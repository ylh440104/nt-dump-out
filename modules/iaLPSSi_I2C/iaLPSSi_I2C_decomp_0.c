
===== CheckSupportedOs @ 140001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CheckSupportedOs(void) */

long __cdecl CheckSupportedOs(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(&local_138,0,0x11c);
  local_138 = 0x11c;
  local_134 = 6;
  local_130 = 3;
  uVar2 = VerSetConditionMask(0,3,3);
  lVar1 = RtlVerifyVersionInfo(&local_138,3,uVar2);
  return lVar1;
}



===== OnDeviceAdd @ 140001080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl OnDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  uint uVar1;
  int iVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_1f8 [32];
  WDFDEVICE__ *local_1c8;
  WDFDEVICE_INIT *local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  code *local_1a8;
  undefined4 local_1a0;
  undefined4 local_19c;
  WDFDEVICE__ *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  code *local_168;
  undefined4 local_158 [2];
  code *local_150;
  undefined4 local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_110;
  undefined4 local_fc;
  code *local_e8;
  undefined4 local_c8 [6];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined *local_98;
  undefined4 local_90 [6];
  undefined4 local_78;
  undefined4 local_74;
  WDFDEVICE__ *local_70;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_1f8;
  uVar4 = 0xff;
  local_1c0 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  iVar2 = (*SpbFunctions)(SpbDriverGlobals);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff,(char)iVar2);
    }
    if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
    pwVar5 = L"Error configuring WDFDEVICE_INIT";
  }
  else {
    memset(local_158,0,0x90);
    local_158[0] = 0x90;
    local_130 = OnPrepareHardware;
    local_128 = OnReleaseHardware;
    local_150 = OnD0Entry;
    local_140 = OnD0Exit;
    local_110 = OnSelfManagedIoInit;
    local_120 = OnSelfManagedIoCleanup;
    local_e8 = OnQueryStop;
    (*DAT_140019498)(WdfDriverGlobals,local_1c0,local_158);
    (*DAT_140019510)(WdfDriverGlobals,local_1c0,0x80,1);
    iVar2 = (*DAT_140019500)(WdfDriverGlobals);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff,(char)iVar2);
      }
      if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
      pwVar5 = L"Error setting the device security descriptor";
    }
    else {
      memset(local_c8,0,0x38);
      local_98 = PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040;
      local_c8[0] = 0x38;
      local_b0 = 1;
      local_ac = 1;
      iVar2 = (*DAT_140019538)(WdfDriverGlobals,&local_1c0,local_c8,&local_1c8);
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                    &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff,(char)iVar2);
        }
        if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
        pwVar5 = L"Error creating WDFDEVICE";
      }
      else {
        pPVar3 = (PBC_DEVICE *)(*DAT_140019930)(WdfDriverGlobals,local_1c8);
        *(WDFDEVICE__ **)pPVar3 = local_1c8;
        iVar2 = CheckSupportedHardware(local_1c8);
        if (-1 < iVar2) {
          uVar4 = *(uint *)(pPVar3 + 0x24);
          GetDefaultSettings(pPVar3);
          OverrideDefaultsForHardware(pPVar3);
          GetAcpiSettings(pPVar3);
          GetRegistrySettings(pPVar3);
          local_48 = 0;
          uStack_44 = 2;
          local_50 = (code *)0x200000002;
          local_40 = 2;
          local_58 = 0x20000001c;
          (*DAT_1400193c8)(WdfDriverGlobals,local_1c8,&local_58);
          memset(&local_1b8,0,0x48);
          local_1b8 = 0x48;
          local_1a8 = OnTargetConnect;
          local_1b4 = 1;
          local_188 = OnRead;
          local_1b0 = 1;
          local_180 = OnWrite;
          local_178 = OnSequence;
          local_198 = (WDFDEVICE__ *)OnControllerLock;
          local_190 = OnControllerUnlock;
          iVar2 = (*DAT_14001a2c8)(SpbDriverGlobals,local_1c8);
          if (iVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
               ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
                (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                  (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) || (1 < uVar4)))))) {
              WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                        &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
            }
            if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
            pwVar5 = L"Error initializing SPB controller";
          }
          else {
            (*DAT_14001a2d0)(SpbDriverGlobals,*(undefined8 *)pPVar3,OnOther,OnOtherInCallerContext);
            memset(&local_1b8,0,0x38);
            local_188 = (code *)PTR__WDF_PBC_TARGET_TYPE_INFO_140019068;
            local_1b8 = 0x38;
            local_1a0 = 1;
            local_19c = 1;
            (*DAT_14001a2e0)(SpbDriverGlobals,local_1c8,&local_1b8);
            memset(&local_1b8,0,0x38);
            local_188 = (code *)PTR__WDF_PBC_REQUEST_TYPE_INFO_140019090;
            local_1b8 = 0x38;
            local_1a0 = 1;
            local_19c = 1;
            (*DAT_14001a2d8)(SpbDriverGlobals,local_1c8,&local_1b8);
            memset(&local_1b8,0,0x38);
            local_198 = local_1c8;
            local_1b8 = 0x38;
            local_1a0 = 1;
            local_19c = 1;
            iVar2 = (*DAT_140019cb8)(WdfDriverGlobals);
            if (iVar2 < 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                  ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
                WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                          &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
              }
              if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
              pwVar5 = L"Failed to create interrupt spinlock";
            }
            else {
              memset(local_158,0,0x60);
              local_140 = OnInterruptIsr;
              local_158[0] = 0x60;
              local_138 = OnInterruptDpc;
              local_148 = 2;
              local_150 = local_168;
              local_fc = 1;
              iVar2 = (*DAT_140019748)(WdfDriverGlobals,*(undefined8 *)pPVar3,local_158,0);
              if (iVar2 < 0) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                     (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) || (1 < uVar4)))) {
                  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                            &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
                }
                if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                pwVar5 = L"Error creating interrupt object";
              }
              else {
                memset(&local_58,0,0x20);
                local_48 = 0;
                local_40 = 0;
                local_58 = CONCAT44(local_58._4_4_,0x20);
                uStack_44 = CONCAT31(uStack_44._1_3_,1);
                local_50 = OnDelayTimerExpired;
                memset(&local_1b8,0,0x38);
                local_198 = local_1c8;
                local_1b8 = 0x38;
                local_1a0 = 1;
                local_19c = 1;
                iVar2 = (*DAT_140019cd0)(WdfDriverGlobals,&local_58,&local_1b8,pPVar3 + 0x58);
                if (iVar2 < 0) {
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                      ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
                    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                              &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
                  }
                  if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                  pwVar5 = L"Failed to create delay timer";
                }
                else {
                  memset(&local_58,0,0x20);
                  local_48 = 0;
                  local_40 = 0;
                  local_58 = CONCAT44(local_58._4_4_,0x20);
                  uStack_44 = CONCAT31(uStack_44._1_3_,1);
                  local_50 = ControlerOnCancelTimerExpired;
                  memset(&local_1b8,0,0x38);
                  local_198 = local_1c8;
                  local_1b8 = 0x38;
                  local_1a0 = 1;
                  local_19c = 1;
                  iVar2 = (*DAT_140019cd0)(WdfDriverGlobals,&local_58,&local_1b8,pPVar3 + 0x70c8);
                  if (iVar2 < 0) {
                    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
                      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                                &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
                    }
                    if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                    pwVar5 = L"Failed to create cancel timer";
                  }
                  else {
                    memset(local_90,0,0x38);
                    local_70 = local_1c8;
                    local_90[0] = 0x38;
                    local_78 = 1;
                    local_74 = 1;
                    iVar2 = (*DAT_140019cb8)(WdfDriverGlobals);
                    if (iVar2 < 0) {
                      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                          ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
                        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                                  &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2
                                 );
                      }
                      if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                      pwVar5 = L"Failed to create device spinlock";
                    }
                    else {
                      memset(&local_58,0,0x24);
                      local_40 = 2;
                      local_38 = 2;
                      local_58 = 0x100000024;
                      local_50 = (code *)CONCAT44(*(undefined4 *)(pPVar3 + 0xb8),4);
                      local_48 = 1;
                      uStack_44 = 1;
                      local_3c = 2;
                      iVar2 = (*DAT_140019450)(WdfDriverGlobals);
                      if (iVar2 < 0) {
                        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                           (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                             (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) || (1 < uVar4)))) {
                          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                                    &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,
                                    (char)iVar2);
                        }
                        if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                        pwVar5 = L"Failed to initalize S0 idle settings";
                      }
                      else {
                        memset(&local_1b8,0,0x38);
                        local_188 = (code *)PTR__WDF_WORKER_CONTEXT_TYPE_INFO_1400190b8;
                        local_198 = local_1c8;
                        uStack_44 = 0;
                        local_1b8 = 0x38;
                        local_1a0 = 1;
                        local_19c = 1;
                        local_58 = 0x18;
                        local_50 = ControllerConfigureForTransfer_PassiveLevel;
                        local_48 = 1;
                        iVar2 = (*DAT_140019eb8)(WdfDriverGlobals,&local_58,&local_1b8,
                                                 pPVar3 + 0x70d8);
                        if (-1 < iVar2) {
                          pPVar3[0x70e0] = (PBC_DEVICE)0x0;
                          KeInitializeEvent(pPVar3 + 0x70e8,0,0);
                          KeInitializeEvent(pPVar3 + 0x7100,0,0);
                          KeInitializeEvent(pPVar3 + 0x7118,0,0);
                          KeInitializeEvent(pPVar3 + 0x7130,0,0);
                          KeInitializeEvent(pPVar3 + 29000,0,0);
                          if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
                            Template_p();
                          }
                          goto LAB_140001d31;
                        }
                        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                           ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
                            ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
                          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                                    &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,
                                    (char)iVar2);
                        }
                        if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
                        pwVar5 = L"Error creating Work Item";
                      }
                    }
                  }
                }
              }
            }
          }
          Template_zqp(Intel_IALPSS_I2CHandle,&EVENT_I2C_ENUMERATION_FAILURE,0,(undefined1 *)pwVar5,
                       (char)iVar2,(char)*(undefined8 *)pPVar3);
          goto LAB_140001d31;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
        }
        if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140001d31;
        pwVar5 = L"No supported hardware found";
      }
    }
  }
  Template_zqp(Intel_IALPSS_I2CHandle,&EVENT_I2C_ENUMERATION_FAILURE,0,(undefined1 *)pwVar5,
               (char)iVar2,0);
LAB_140001d31:
  if (((((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4,(char)iVar2);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || (1 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,uVar4);
  }
  return iVar2;
}



===== OnDriverCleanup @ 140001e20 =====

/* void __cdecl OnDriverCleanup(void * __ptr64) */

void __cdecl OnDriverCleanup(void *param_1)

{
  WppCleanupKm();
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  McGenEventUnregister(&Intel_IALPSS_I2CHandle);
  return;
}



===== DriverEntry @ 140001e5c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long DriverEntry(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined1 local_res18 [16];
  undefined4 local_88 [2];
  code *local_80;
  undefined4 local_6c;
  undefined4 local_68 [2];
  code *local_60;
  undefined4 local_50;
  undefined4 local_4c;
  
  _DAT_1400192b8 = 1;
  DAT_140019298 = &WPP_ThisDir_CTLGUID_iaLPSS_I2CTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1400192a0 = 0;
  _DAT_1400192b0 = 0;
  WppLoadTracingSupport();
  _DAT_1400192b0 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
  }
  McGenEventRegister();
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  lVar1 = CheckSupportedOs();
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
    }
  }
  else {
    memset(local_88,0,0x20);
    local_88[0] = 0x20;
    local_80 = OnDeviceAdd;
    local_6c = 0x43324949;
    memset(local_68,0,0x38);
    local_60 = OnDriverCleanup;
    local_68[0] = 0x38;
    local_50 = 1;
    local_4c = 1;
    lVar1 = (*DAT_140019680)(WdfDriverGlobals,param_1,param_2,local_68,local_88,local_res18);
    if (-1 < lVar1) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
      }
      goto LAB_1400020a2;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff,(char)lVar1);
    }
  }
  WppCleanupKm();
  McGenEventUnregister(&Intel_IALPSS_I2CHandle);
LAB_1400020a2:
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_66a28193649afc584a7c7a0fe655798b_Traceguids,0xff);
  }
  return lVar1;
}



===== McGenControlCallbackV2 @ 140002114 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar3 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 & ~(1 << ((byte)uVar5 & 0x1f));
          }
          else {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)uVar5 & 0x1f);
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister @ 14000222c =====

undefined8 McGenEventRegister(void)

{
  undefined8 uVar1;
  longlong *in_R9;
  
  if (*in_R9 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000140002235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = EtwRegister();
    return uVar1;
  }
  return 0;
}



===== McGenEventUnregister @ 14000223c =====

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



===== TemplateEventDescriptor @ 140002264 =====

void TemplateEventDescriptor(void)

{
  EtwWrite();
  return;
}



===== Template_p @ 14000227c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_p(void)

{
  undefined1 local_res20 [8];
  undefined1 auStack_58 [32];
  undefined1 **local_38;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = local_res20;
  local_1c = 0;
  local_38 = &local_28;
  local_20 = 8;
  EtwWrite();
  return;
}



===== Template_zqp @ 1400022d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_zqp(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4,
                 undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStack_78 [32];
  undefined1 **local_58;
  undefined1 *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  if (param_4 == (undefined1 *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_48 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    local_48 = param_4;
  }
  local_38 = &param_5;
  local_3c = 0;
  local_28 = &param_6;
  local_30 = 4;
  local_58 = &local_48;
  local_20 = 8;
  EtwWrite(param_1,param_2,param_3,3);
  return;
}



===== WPP_SF_d @ 140002378 =====

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== ControllerConfigureForTransfer_Enqueue @ 1400023dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl ControllerConfigureForTransfer_Enqueue(struct PBC_DEVICE * __ptr64,struct
   PBC_REQUEST * __ptr64) */

void __cdecl ControllerConfigureForTransfer_Enqueue(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x70d8),
                            PTR__WDF_WORKER_CONTEXT_TYPE_INFO_1400190b8);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  param_1[0x70e0] = (PBC_DEVICE)0x1;
                    /* WARNING: Could not recover jumptable at 0x00014000242d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_140019ec0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x70d8));
  return;
}



===== ControllerConfigureForTransfer_PassiveLevel @ 140002434 =====

/* void __cdecl ControllerConfigureForTransfer_PassiveLevel(struct WDFWORKITEM__ * __ptr64) */

void __cdecl ControllerConfigureForTransfer_PassiveLevel(WDFWORKITEM__ *param_1)

{
  PBC_DEVICE *pPVar1;
  PBC_REQUEST *pPVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_WORKER_CONTEXT_TYPE_INFO_1400190b8);
  pPVar1 = (PBC_DEVICE *)*puVar3;
  pPVar2 = (PBC_REQUEST *)puVar3[1];
  pPVar1[0x70e0] = (PBC_DEVICE)0x0;
  ControllerConfigureForTransfer(pPVar1,pPVar2);
  return;
}



===== OnCancel @ 140002468 =====

/* void __cdecl OnCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl OnCancel(WDFREQUEST__ *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  PBC_DEVICE *pPVar6;
  PBC_TARGET *pPVar7;
  PBC_REQUEST *pPVar8;
  undefined2 uVar9;
  uint uVar10;
  
  uVar4 = (*DAT_14001a300)(SpbDriverGlobals,param_1);
  lVar5 = (*DAT_140019930)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar5 == 0) {
    uVar10 = 0xf0;
  }
  else {
    uVar4 = (*DAT_14001a300)(SpbDriverGlobals,param_1);
    lVar5 = (*DAT_140019930)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar10 = *(uint *)(lVar5 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar10);
  }
  uVar4 = (*DAT_14001a300)(SpbDriverGlobals,param_1);
  pPVar6 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  uVar4 = (*DAT_14001a2f8)(SpbDriverGlobals,param_1);
  pPVar7 = (PBC_TARGET *)
           (*DAT_140019930)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_TARGET_TYPE_INFO_140019068);
  pPVar8 = (PBC_REQUEST *)(*DAT_140019930)(WdfDriverGlobals,param_1);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(*(undefined8 *)(pPVar6 + 8));
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_CANCEL,0,param_1,
                    (char)*(undefined8 *)pPVar6,(char)*(undefined8 *)pPVar7,&u_Cancel,
                    (char)*(undefined2 *)(pPVar7 + 0xc),uVar2);
  }
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x50));
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  if (pPVar7 == *(PBC_TARGET **)(pPVar6 + 0x30)) {
    if (pPVar8 == *(PBC_REQUEST **)(pPVar7 + 0x18)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
         ((2 < (byte)WPP_GLOBAL_Control[0x29] &&
          (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar10);
      }
      cVar3 = (*DAT_140019ce0)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x58),0);
      if (((((cVar3 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar10);
      }
      LOCK();
      *(uint *)(pPVar6 + 0x70d0) = *(uint *)(pPVar6 + 0x70d0) | 1;
      UNLOCK();
      KeSetEvent(pPVar6 + 29000,0,0);
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x50));
      if (cVar3 != '\0') {
        *(undefined4 *)(pPVar8 + 0x20) = 0xc0000120;
        ControllerGenerateStop(pPVar6,pPVar7);
        ControllerCompleteTransfer(pPVar6,pPVar8);
      }
      KeWaitForSingleObject(pPVar6 + 0x70e8,0,0,0,0);
      *(undefined8 *)(*(longlong *)(pPVar6 + 0x30) + 0x18) = 0;
      if ((*(int *)(pPVar8 + 8) == 3) || (*(int *)(pPVar8 + 0x38) == 1)) {
        *(undefined8 *)(pPVar6 + 0x30) = 0;
      }
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        TemplateEventDescriptor();
      }
      PbcRequestComplete(pPVar8);
      goto LAB_140002850;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      uVar9 = 0x4c;
      goto LAB_1400026bd;
    }
  }
  else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
          (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
    uVar9 = 0x4b;
LAB_1400026bd:
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar10);
  }
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x50));
LAB_140002850:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar10);
  }
  return;
}



===== OnControllerLock @ 1400028c0 =====

/* void __cdecl OnControllerLock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerLock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar5 = (undefined8 *)(*DAT_140019930)(WdfDriverGlobals,param_2);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(puVar4[1]);
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,(char)*puVar4,
                    (char)*puVar5,&u_Lock,(char)*(undefined2 *)((longlong)puVar5 + 0xc),uVar2);
  }
  (*DAT_140019cc0)(WdfDriverGlobals,puVar4[10]);
  puVar4[6] = puVar5;
  (*DAT_140019cc8)(WdfDriverGlobals,puVar4[10]);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,
              (char)*(undefined2 *)((longlong)puVar5 + 0xc));
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    Template_pq();
  }
  (*DAT_14001a318)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== OnControllerUnlock @ 140002b1c =====

/* void __cdecl OnControllerUnlock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerUnlock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  PBC_TARGET *pPVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  pPVar4 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  pPVar5 = (PBC_TARGET *)(*DAT_140019930)(WdfDriverGlobals,param_2);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(*(undefined8 *)(pPVar4 + 8));
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,
                    (char)*(undefined8 *)pPVar4,(char)*(undefined8 *)pPVar5,&u_UnLock,
                    (char)*(undefined2 *)(pPVar5 + 0xc),uVar2);
  }
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x50));
  ControllerGenerateStop(pPVar4,pPVar5);
  ControlerDisableOnFinish(pPVar4);
  *(undefined8 *)(pPVar4 + 0x30) = 0;
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x50));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
              &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,
              (char)*(undefined2 *)(pPVar5 + 0xc));
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    Template_pq();
  }
  (*DAT_14001a318)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== OnD0Entry @ 140002d8c =====

/* long __cdecl OnD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  longlong lVar2;
  PBC_DEVICE *pPVar3;
  char *pcVar4;
  uint uVar5;
  
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar2 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar5 = *(uint *)(lVar2 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  pPVar3 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    pcVar4 = "UNKNOWN";
    if (param_2 == 6) {
      pcVar4 = "WdfPowerDevicePrepareForHibernation";
    }
    if (param_2 == 5) {
      pcVar4 = "WdfPowerDeviceD3Final";
    }
    if (param_2 == 4) {
      pcVar4 = "WdfPowerDeviceD3";
    }
    if (param_2 == 3) {
      pcVar4 = "WdfPowerDeviceD2";
    }
    if (param_2 == 2) {
      pcVar4 = "WdfPowerDeviceD1";
    }
    if (param_2 == 1) {
      pcVar4 = "WdfPowerDeviceD0";
    }
    if (param_2 == 0) {
      pcVar4 = "WdfPowerDeviceInvalid";
    }
    WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5,(char)param_2,pcVar4);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar3 + 8));
    Template_ppx();
  }
  *(undefined8 *)(pPVar3 + 0x30) = 0;
  ControllerInitialize(pPVar3);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar3 + 8));
    Template_ppx();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  return 0;
}



===== OnD0Exit @ 140003008 =====

/* long __cdecl OnD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  longlong lVar2;
  PBC_DEVICE *pPVar3;
  char *pcVar4;
  uint uVar5;
  
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar2 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar5 = *(uint *)(lVar2 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  pPVar3 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    pcVar4 = "UNKNOWN";
    if (param_2 == 6) {
      pcVar4 = "WdfPowerDevicePrepareForHibernation";
    }
    if (param_2 == 5) {
      pcVar4 = "WdfPowerDeviceD3Final";
    }
    if (param_2 == 4) {
      pcVar4 = "WdfPowerDeviceD3";
    }
    if (param_2 == 3) {
      pcVar4 = "WdfPowerDeviceD2";
    }
    if (param_2 == 2) {
      pcVar4 = "WdfPowerDeviceD1";
    }
    if (param_2 == 1) {
      pcVar4 = "WdfPowerDeviceD0";
    }
    if (param_2 == 0) {
      pcVar4 = "WdfPowerDeviceInvalid";
    }
    WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5,(char)param_2,pcVar4);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar3 + 8));
    Template_ppx();
  }
  ControllerUninitialize(pPVar3);
  *(undefined8 *)(pPVar3 + 0x30) = 0;
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar3 + 8));
    Template_ppx();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  return 0;
}



===== OnDelayTimerExpired @ 140003284 =====

/* void __cdecl OnDelayTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnDelayTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  PBC_REQUEST *pPVar2;
  undefined8 uVar3;
  longlong lVar4;
  PBC_DEVICE *pPVar5;
  undefined2 uVar6;
  uint uVar7;
  
  uVar3 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar7 = 0xf0;
  }
  else {
    uVar3 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar7 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
      (1 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar7);
  }
  uVar3 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
  pPVar5 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
  if (*(longlong *)(pPVar5 + 0x30) == 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (1 < uVar7)))))) {
      uVar6 = 0x71;
LAB_14000341d:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar7);
    }
  }
  else {
    pPVar2 = *(PBC_REQUEST **)(*(longlong *)(pPVar5 + 0x30) + 0x18);
    if (pPVar2 != (PBC_REQUEST *)0x0) {
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
          (1 < uVar7)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar7);
      }
      ControllerConfigureForTransfer_Enqueue(pPVar5,pPVar2);
      goto LAB_1400034a0;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (1 < uVar7)))))) {
      uVar6 = 0x72;
      goto LAB_14000341d;
    }
  }
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
LAB_1400034a0:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
      (1 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar7);
  }
  return;
}



===== OnInterruptDpc @ 140003508 =====

/* void __cdecl OnInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl OnInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  uint uVar1;
  ulong uVar2;
  PBC_REQUEST *pPVar3;
  bool bVar4;
  bool bVar5;
  longlong lVar6;
  PBC_DEVICE *pPVar7;
  undefined2 uVar8;
  uint uVar9;
  
  lVar6 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar6 == 0) {
    uVar9 = 0xf0;
  }
  else {
    lVar6 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar9 = *(uint *)(lVar6 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar9);
  }
  bVar4 = false;
  bVar5 = false;
  pPVar7 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar7 + 8));
    Template_px();
  }
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x50));
  if (*(longlong *)(pPVar7 + 0x30) == 0) {
    bVar4 = bVar5;
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
       ((((uVar1 & 0x800) == 0 || (uVar9 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) && (uVar9 < 2)))))) goto LAB_14000376f;
    uVar8 = 0x55;
  }
  else {
    pPVar3 = *(PBC_REQUEST **)(*(longlong *)(pPVar7 + 0x30) + 0x18);
    if (pPVar3 != (PBC_REQUEST *)0x0) {
      (*DAT_140019760)(WdfDriverGlobals,param_1);
      uVar2 = *(ulong *)(pPVar7 + 0x44);
      *(undefined4 *)(pPVar7 + 0x44) = 0;
      (*DAT_140019768)(WdfDriverGlobals,param_1);
      if (uVar2 != 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) || (1 < uVar9)))) {
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                    &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar9,(char)uVar2);
        }
        ControllerAcknowledgeInterrupts(pPVar7,uVar2);
        ControllerProcessInterrupts(pPVar7,pPVar3,uVar2);
        bVar4 = true;
      }
      goto LAB_14000376f;
    }
    bVar4 = bVar5;
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
       ((((uVar1 & 0x800) == 0 || (uVar9 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) && (uVar9 < 2)))))) goto LAB_14000376f;
    uVar8 = 0x56;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
           &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar9);
  bVar4 = bVar5;
LAB_14000376f:
  LOCK();
  *(undefined4 *)(pPVar7 + 0x7160) = 0;
  UNLOCK();
  if (bVar4) {
    KeSetEvent(pPVar7 + 0x7100,0,0);
  }
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x50));
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar7 + 8));
    Template_px();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar9);
  }
  return;
}



===== OnInterruptIsr @ 14000383c =====

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
  
  uVar5 = (*DAT_140019798)(WdfDriverGlobals,param_1);
  lVar6 = (*DAT_140019930)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar6 == 0) {
    uVar8 = 0xf0;
  }
  else {
    uVar5 = (*DAT_140019798)(WdfDriverGlobals,param_1);
    lVar6 = (*DAT_140019930)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar8 = *(uint *)(lVar6 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8);
  }
  uVar9 = '\0';
  uVar5 = (*DAT_140019798)(WdfDriverGlobals,param_1);
  pPVar7 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar7 + 8));
    Template_px();
  }
  uVar4 = *(ulong *)(pPVar7 + 0x40);
  do {
    LOCK();
    uVar1 = *(ulong *)(pPVar7 + 0x40);
    bVar10 = uVar4 == uVar1;
    if (bVar10) {
      *(ulong *)(pPVar7 + 0x40) = uVar4;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
  } while (!bVar10);
  uVar4 = ControllerGetInterruptStatus(pPVar7,uVar4);
  if (uVar4 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
       ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
         (1 < uVar8)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8,(char)uVar4);
    }
    *(uint *)(pPVar7 + 0x44) = *(uint *)(pPVar7 + 0x44) | uVar4;
    uVar9 = '\x01';
    ControllerDisableInterrupts(pPVar7);
    cVar3 = (*DAT_140019750)(WdfDriverGlobals,param_1);
    if (cVar3 == '\0') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar2 & 0x800) != 0 && (uVar8 == 0)) ||
          ((((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)) || (1 < uVar8)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                  &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8,(char)uVar4);
      }
    }
    else {
      LOCK();
      *(uint *)(pPVar7 + 0x7160) = *(uint *)(pPVar7 + 0x7160) | 1;
      UNLOCK();
    }
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(pPVar7 + 8));
    Template_ppx();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8);
  }
  return uVar9;
}



===== OnMonitorPowerSettingCallback @ 140003b0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnMonitorPowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl OnMonitorPowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 auStackY_a8 [32];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar3 = 0;
  uVar6 = 0xff;
  if (param_4 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140003df3;
    uVar5 = 0x2a;
    iVar3 = -0x3ffffff3;
  }
  else {
    puVar4 = (undefined8 *)
             (*DAT_140019930)(WdfDriverGlobals,param_4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = 0xf0;
    if (puVar4 != (undefined8 *)0x0) {
      uVar6 = *(uint *)((longlong)puVar4 + 0x24);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || (1 < uVar6)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
    }
    if ((*(longlong *)param_1 != 0x4526451002731015) ||
       (*(longlong *)(param_1 + 8) != -0x15e542815e1a1967)) goto LAB_140003df3;
    iVar3 = *(int *)param_2;
    memset(&local_60,0,0x24);
    local_60 = 0x24;
    local_50 = 2;
    local_4c = 2;
    local_48 = 2;
    local_40 = 2;
    local_5c = 1;
    local_58 = 4;
    local_44 = 2;
    if (iVar3 != 0) {
      local_54 = *(undefined4 *)(puVar4 + 0x17);
      *(undefined4 *)(puVar4 + 0xd) = 1;
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        uVar2 = MmGetPhysicalAddress(puVar4[1]);
        puVar8 = &u_ON;
        goto LAB_140003ce5;
      }
    }
    else {
      local_54 = *(undefined4 *)((longlong)puVar4 + 0xbc);
      *(undefined4 *)(puVar4 + 0xd) = 0;
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        uVar2 = MmGetPhysicalAddress(puVar4[1]);
        puVar8 = &u_OFF;
LAB_140003ce5:
        Template_zxpx(Intel_IALPSS_I2CHandle,&EVENT_I2C_MONITOR_CALLBACK,0,puVar8,(char)local_54,
                      (char)*puVar4,uVar2);
      }
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || (1 < uVar6)))) {
      pcVar7 = "on";
      if (iVar3 == 0) {
        pcVar7 = "off";
      }
      WPP_SF_dsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,pcVar7,(char)local_54);
    }
    iVar3 = (*DAT_140019450)(WdfDriverGlobals,param_4,&local_60);
    if (-1 < iVar3) goto LAB_140003df3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 >> 0xb & 1) == 0 || (uVar6 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)) && (uVar6 < 2)))))) goto LAB_140003df3;
    uVar5 = 0x2d;
  }
  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
            &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)iVar3);
LAB_140003df3:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return iVar3;
}



===== OnOther @ 140003e68 =====

/* void __cdecl OnOther(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
OnOther(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4,
       __uint64 param_5,ulong param_6)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar5 = (undefined8 *)(*DAT_140019930)(WdfDriverGlobals,param_2);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(puVar4[1]);
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,(char)*puVar4,
                    (char)*puVar5,(undefined1 *)L"Other",
                    (char)*(undefined2 *)((longlong)puVar5 + 0xc),uVar2);
    if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
      Template_pq();
    }
  }
  (*DAT_14001a318)(SpbDriverGlobals,param_3,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== OnOtherInCallerContext @ 140004068 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnOtherInCallerContext(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl OnOtherInCallerContext(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined1 auStack_88 [32];
  undefined2 local_58 [2];
  int local_54;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar4 = *(uint *)(lVar2 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  memset(local_58,0,0x28);
  local_58[0] = 0x28;
  (*DAT_140019b30)(WdfDriverGlobals,param_2,local_58);
  if (local_54 - 0xeU < 2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) == 0)) ||
       (((byte)WPP_GLOBAL_Control[0x29] < 2 ||
        (((((uVar1 & 0x800) == 0 || (uVar4 != 0)) && (((uVar1 & 0x1000) == 0 || (uVar4 != 1)))) &&
         (uVar4 < 2)))))) goto LAB_1400041ed;
    uVar3 = 0x43;
  }
  else {
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 & 0x800) == 0 || (uVar4 != 0)) &&
        ((((uVar1 & 0x1000) == 0 || (uVar4 != 1)) && (uVar4 < 2)))))) goto LAB_1400041ed;
    uVar3 = 0x42;
  }
  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
            &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,0xbb);
LAB_1400041ed:
  (*DAT_140019b18)(WdfDriverGlobals,param_2,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  return;
}



===== OnPrepareHardware @ 140004270 =====

/* long __cdecl OnPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  long lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  char *pcVar9;
  longlong lVar10;
  undefined2 uVar11;
  uint uVar12;
  wchar_t *pwVar13;
  undefined8 uVar14;
  int iVar15;
  int iVar16;
  int local_res20;
  undefined1 uVar17;
  uint local_48;
  
  lVar7 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar7 == 0) {
    uVar12 = 0xf0;
  }
  else {
    lVar7 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar12 = *(uint *)(lVar7 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1))))
      || (1 < uVar12)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  puVar8 = (undefined8 *)(*DAT_140019930)(WdfDriverGlobals,param_1);
  lVar6 = 0;
  iVar16 = 0;
  *(undefined4 *)(puVar8 + 0xe31) = 0;
  iVar15 = 0;
  local_res20 = 0;
  uVar5 = (*DAT_140019c60)(WdfDriverGlobals,param_3);
  local_48 = 0;
  if (uVar5 == 0) {
LAB_140004ca9:
    lVar6 = -0x3fffff66;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)))
         ) || (1 < uVar12)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
    }
    if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140004d3f;
    pwVar13 = L"Incorrect memory resources count";
  }
  else {
    do {
      pcVar9 = (char *)(*DAT_140019c68)(WdfDriverGlobals,param_3);
      if (*pcVar9 == '\x03') {
        lVar7 = (*DAT_140019c68)(WdfDriverGlobals,param_2);
        uVar4 = (undefined1)iVar15;
        if ((*(int *)(lVar7 + 8) != 0) ||
           ((uint)(*(int *)(lVar7 + 0xc) + *(int *)(lVar7 + 4)) < *(uint *)(lVar7 + 4))) {
          lVar6 = -0x3fffff66;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0 &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
             ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
              ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
            WPP_SF_ddxd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                        &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,uVar4,
                        (char)*(undefined8 *)(lVar7 + 4),0x9a);
          }
          if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140004d3f;
          pwVar13 = L"MBAR address is not below 4GB";
          goto LAB_140004d12;
        }
        lVar10 = MmMapIoSpace(*(undefined8 *)(pcVar9 + 4),*(undefined4 *)(pcVar9 + 0xc));
        if (lVar10 == 0) {
          lVar6 = -0x3fffff66;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
              ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
            WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                       &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,uVar4,0x9a);
          }
          if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140004d3f;
          pwVar13 = L"Error Mapping controller MBAR";
          goto LAB_140004d12;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
          WPP_SF_ddxq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,uVar4,
                      (char)*(undefined8 *)(lVar7 + 4),(char)lVar10);
        }
        if (iVar15 == 0) {
          puVar8[1] = lVar10;
          *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(pcVar9 + 0xc);
          puVar8[0xe3b] = *(undefined8 *)(pcVar9 + 4);
        }
        else if (iVar15 == 1) {
          if (*(int *)(puVar8 + 0x18) == 1) {
            puVar8[3] = lVar10;
            *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(pcVar9 + 0xc);
          }
          else {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                 (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                       &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
            }
            MmUnmapIoSpace(lVar10,*(undefined4 *)(pcVar9 + 0xc));
            puVar8[3] = 0;
            *(undefined4 *)(puVar8 + 4) = 0;
          }
        }
        else {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
            WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                      &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,uVar4);
          }
          MmUnmapIoSpace(lVar10,*(undefined4 *)(pcVar9 + 0xc));
        }
        iVar15 = iVar15 + 1;
        iVar16 = local_res20;
      }
      if (*pcVar9 == '\x02') {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,
                    (char)*(undefined4 *)(pcVar9 + 8));
        }
        iVar16 = iVar16 + 1;
        local_res20 = iVar16;
      }
      if (*pcVar9 == '\x04') {
        iVar2 = *(int *)(puVar8 + 0xe31);
        if (iVar2 == 0) {
          puVar8[0xe32] = pcVar9;
        }
        else if (iVar2 == 1) {
          puVar8[0xe33] = pcVar9;
        }
        *(int *)(puVar8 + 0xe31) = iVar2 + 1;
      }
      local_48 = local_48 + 1;
    } while (local_48 < uVar5);
    if (1 < iVar15 - 1U) goto LAB_140004ca9;
    if (iVar16 == 1) {
      if (*(int *)(puVar8 + 0xe31) == 2) {
        if (*(int *)((longlong)puVar8 + 0xb4) == 1) {
          lVar6 = I2CInitDma(param_1);
          if (lVar6 < 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
              uVar11 = 0x14;
LAB_1400048b7:
              WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                        &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12,(char)lVar6);
            }
          }
          else {
            lVar6 = I2CConfigureSystemProfile
                              (param_1,(_CM_PARTIAL_RESOURCE_DESCRIPTOR *)puVar8[0xe32],1);
            if (lVar6 < 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                  ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
                uVar11 = 0x15;
                goto LAB_1400048b7;
              }
            }
            else {
              lVar6 = I2CConfigureSystemProfile
                                (param_1,(_CM_PARTIAL_RESOURCE_DESCRIPTOR *)puVar8[0xe33],0);
              if (lVar6 < 0) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                     (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
                  uVar11 = 0x16;
                  goto LAB_1400048b7;
                }
              }
              else {
                lVar6 = I2CCreateDmaTxnObjects(param_1);
                if (lVar6 < 0) {
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                      ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
                    uVar11 = 0x17;
                    goto LAB_1400048b7;
                  }
                }
                else {
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                       (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
                    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
                  }
                  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
                    uVar3 = MmGetPhysicalAddress(puVar8[1]);
                    uVar14 = puVar8[0xe2f];
                    pwVar13 = L"Enabled";
                    uVar4 = (undefined1)*puVar8;
                    uVar17 = (undefined1)puVar8[0xe30];
                    goto LAB_140004b37;
                  }
                }
              }
            }
          }
        }
        else {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
              ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
          }
          *(undefined4 *)(puVar8 + 0xe31) = 0;
          if ((Intel_IALPSS_I2CEnableBits & 1) == 0) goto LAB_140004c51;
          uVar3 = MmGetPhysicalAddress(puVar8[1]);
          pwVar13 = L"Disabled";
          uVar4 = (undefined1)*puVar8;
          uVar17 = 0;
          uVar14 = 0;
LAB_140004b37:
          Template_pppxz(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_CONFIGURATION,0,uVar14,uVar17,uVar4,
                         uVar3,(undefined1 *)pwVar13);
        }
        if (lVar6 < 0) {
          if (*(int *)(puVar8 + 0x16) == 1) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                       &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
            }
            goto LAB_140004d3f;
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
               (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                     &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
          }
          if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
            uVar4 = MmGetPhysicalAddress(puVar8[1]);
            Template_pppxz(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_CONFIGURATION,0,0,0,(char)*puVar8,
                           uVar4,(undefined1 *)L"Fall Back to PIO");
          }
          *(undefined4 *)(puVar8 + 0xe31) = 0;
          goto LAB_140004c51;
        }
      }
      else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
              (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
                (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)))) || (1 < uVar12)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
LAB_140004c51:
        lVar6 = 0;
      }
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        MmGetPhysicalAddress(puVar8[1]);
        Template_ppx();
      }
      goto LAB_140004d3f;
    }
    lVar6 = -0x3fffff66;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
        ((((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1)) || (1 < uVar12)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
    }
    if ((Intel_IALPSS_I2CEnableBits & 2) == 0) goto LAB_140004d3f;
    pwVar13 = L"Incorrect interrupt resources count";
  }
LAB_140004d12:
  lVar6 = -0x3fffff66;
  Template_zqp(Intel_IALPSS_I2CHandle,&EVENT_I2C_ENUMERATION_FAILURE,0,(undefined1 *)pwVar13,0x9a,
               (char)*puVar8);
LAB_140004d3f:
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    TemplateEventDescriptor();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar5 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar12 == 1))))
      || (1 < uVar12)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar12);
  }
  return lVar6;
}



===== OnQueryStop @ 140004dc8 =====

/* long __cdecl OnQueryStop(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnQueryStop(WDFDEVICE__ *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar3 = *(uint *)(lVar2 + 0x24);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 10 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
    }
  }
  return -0x3fffffff;
}



===== OnRead @ 140004ec8 =====

/* void __cdecl OnRead(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct SPBREQUEST__
   * __ptr64,unsigned __int64) */

void __cdecl
OnRead(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar5 = (undefined8 *)(*DAT_140019930)(WdfDriverGlobals,param_2);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(puVar4[1]);
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,(char)*puVar4,
                    (char)*puVar5,(undefined1 *)L"Read",
                    (char)*(undefined2 *)((longlong)puVar5 + 0xc),uVar2);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== OnReleaseHardware @ 140005094 =====

/* long __cdecl OnReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  longlong lVar4;
  uint uVar5;
  
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar5 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(lVar4 + 8));
    Template_ppx();
  }
  I2CReleaseDma(param_1);
  lVar2 = *(longlong *)(lVar4 + 0x18);
  if (lVar2 != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x84),uVar3 & 0xfffffffc);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 0x18) + 0x84));
  }
  if (*(longlong *)(lVar4 + 8) != 0) {
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 8) + 0x800),0);
    lVar2 = *(longlong *)(lVar4 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x804));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x804),uVar3 & 0xfffffffc);
    *(undefined4 *)(lVar4 + 0x70d4) = 0;
    MmUnmapIoSpace(*(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar4 + 0x10));
    *(undefined8 *)(lVar4 + 8) = 0;
    *(undefined4 *)(lVar4 + 0x10) = 0;
  }
  lVar2 = *(longlong *)(lVar4 + 0x18);
  if (lVar2 != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x84),uVar3 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 0x18) + 0x84));
    MmUnmapIoSpace(*(undefined8 *)(lVar4 + 0x18),*(undefined4 *)(lVar4 + 0x20));
    *(undefined8 *)(lVar4 + 0x18) = 0;
    *(undefined4 *)(lVar4 + 0x20) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  return 0;
}



===== OnSelfManagedIoCleanup @ 1400052d8 =====

/* void __cdecl OnSelfManagedIoCleanup(struct WDFDEVICE__ * __ptr64) */

void __cdecl OnSelfManagedIoCleanup(WDFDEVICE__ *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar3 = *(uint *)(lVar2 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
  }
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (*(longlong *)(lVar2 + 0x60) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(lVar2 + 0x60) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
  }
  return;
}



===== OnSelfManagedIoInit @ 140005408 =====

/* long __cdecl OnSelfManagedIoInit(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  uVar5 = (*DAT_1400193d8)(WdfDriverGlobals,*puVar4);
  iVar2 = PoRegisterPowerSettingCallback
                    (uVar5,&GUID_MONITOR_POWER_ON,OnMonitorPowerSettingCallback,*puVar4,puVar4 + 0xc
                    );
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)iVar2);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return iVar2;
}



===== OnSequence @ 1400055b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned long) */

void __cdecl
OnSequence(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,ulong param_4)

{
  uint uVar1;
  undefined1 uVar2;
  long lVar3;
  longlong lVar4;
  PBC_DEVICE *pPVar5;
  undefined8 *puVar6;
  PBC_REQUEST *pPVar7;
  uint uVar8;
  undefined1 auStackY_b8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar8 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar8 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8);
  }
  pPVar5 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar6 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140019068);
  pPVar7 = (PBC_REQUEST *)(*DAT_140019930)(WdfDriverGlobals);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(*(undefined8 *)(pPVar5 + 8));
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,
                    (char)*(undefined8 *)pPVar5,(char)*puVar6,(undefined1 *)L"Sequence",
                    (char)*(undefined2 *)((longlong)puVar6 + 0xc),uVar2);
  }
  memset(local_68,0,0x20);
  local_68[0] = 0x20;
  (*DAT_14001a308)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar7 = param_3;
  *(undefined8 *)(pPVar7 + 0x18) = 0;
  *(ulong *)(pPVar7 + 0xc) = param_4;
  *(undefined4 *)(pPVar7 + 8) = local_64;
  *(undefined4 *)(pPVar7 + 0x10) = 0;
  pPVar7[0x24] = (PBC_REQUEST)0x0;
  *(undefined8 *)(pPVar5 + 0x70d0) = 0;
  KeClearEvent(pPVar5 + 29000);
  KeClearEvent(pPVar5 + 0x70e8);
  lVar3 = PbcRequestConfigureForIndex(pPVar7,0);
  if (lVar3 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) || (1 < uVar8)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8,(char)lVar3);
    }
  }
  else {
    (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
    lVar3 = (*DAT_140019f28)(WdfDriverGlobals,*(undefined8 *)pPVar7,OnCancel);
    if (lVar3 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))
           ) || (1 < uVar8)))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                  &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8,(char)lVar3);
      }
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
    }
    else {
      *(undefined8 **)(pPVar5 + 0x30) = puVar6;
      puVar6[3] = pPVar7;
      PbcRequestDoTransfer(pPVar5,pPVar7);
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar5 + 0x50));
    }
  }
  if (lVar3 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) || (1 < uVar8)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8,(char)lVar3);
    }
    (*DAT_14001a318)(SpbDriverGlobals,param_3,lVar3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar8);
  }
  return;
}



===== OnTargetConnect @ 140005998 =====

/* long __cdecl OnTargetConnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

long __cdecl OnTargetConnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 local_28;
  undefined8 local_20;
  void *local_18;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  pPVar4 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar5 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140019068);
  local_20 = 0;
  local_18 = (void *)0x0;
  local_28 = 0x18;
  (*DAT_14001a2e8)(SpbDriverGlobals,param_2,&local_28);
  lVar2 = PbcTargetGetSettings(pPVar4,local_18,(PBC_TARGET_SETTINGS *)(puVar5 + 1));
  if (-1 < lVar2) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || (1 < uVar6)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,
                (char)*(undefined2 *)((longlong)puVar5 + 0xc));
    }
    puVar5[3] = 0;
    *(undefined4 *)(puVar5 + 4) = 0;
    *puVar5 = param_2;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return lVar2;
}



===== OnWrite @ 140005b90 =====

/* void __cdecl OnWrite(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
OnWrite(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  puVar5 = (undefined8 *)(*DAT_140019930)(WdfDriverGlobals,param_2);
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar2 = MmGetPhysicalAddress(puVar4[1]);
    Template_pppzxx(Intel_IALPSS_I2CHandle,&EVENT_I2C_IO_REQUEST_START,0,param_3,(char)*puVar4,
                    (char)*puVar5,&u_Write,(char)*(undefined2 *)((longlong)puVar5 + 0xc),uVar2);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== PbcRequestComplete @ 140005d5c =====

/* void __cdecl PbcRequestComplete(struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestComplete(PBC_REQUEST *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar4 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    pcVar5 = "error";
    if (-1 < *(int *)(param_1 + 0x20)) {
      pcVar5 = "complete";
    }
    WPP_SF_dsPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,pcVar5,
                (char)*(undefined8 *)(param_1 + 0x18),(char)*(int *)(param_1 + 0x20));
  }
  (*DAT_140019b78)(WdfDriverGlobals,*(undefined8 *)param_1,*(undefined8 *)(param_1 + 0x18));
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    Template_pq();
  }
  (*DAT_14001a318)(SpbDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x20));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  return;
}



===== PbcRequestConfigureForIndex @ 140005f6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureForIndex(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex(PBC_REQUEST *param_1,ulong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  PBC_TARGET *pPVar5;
  uint uVar6;
  long lVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  lVar7 = 0;
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  pPVar4 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  uVar2 = (*DAT_14001a2f8)(SpbDriverGlobals,*(undefined8 *)param_1);
  pPVar5 = (PBC_TARGET *)
           (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_TARGET_TYPE_INFO_140019068);
  local_48 = 0;
  local_40 = 0;
  local_50 = 0x18;
  (*DAT_14001a310)(SpbDriverGlobals,*(undefined8 *)param_1,param_2,&local_50);
  if (local_48 - 1U < 0xffff) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x30) = local_58;
    *(longlong *)(param_1 + 0x28) = local_48;
    *(undefined4 *)(param_1 + 0x44) = local_50._4_4_;
    *(undefined4 *)(param_1 + 0x48) = (undefined4)local_40;
    if (*(int *)(param_1 + 8) == 3) {
      if (*(int *)(param_1 + 0xc) == 1) {
        *(undefined4 *)(param_1 + 0x38) = 1;
      }
      else if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0x38) = 2;
      }
      else {
        *(uint *)(param_1 + 0x38) = 4 - (uint)(param_2 != *(int *)(param_1 + 0xc) - 1U);
      }
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
      WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)param_2,
                 (char)*(undefined2 *)(pPVar5 + 0xc));
    }
  }
  else {
    lVar7 = -0x3ffffff3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
       ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
         || (1 < uVar6)))))) {
      WPP_SF_dPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)local_48,0xd);
    }
    if (*(int *)(param_1 + 8) == 3) {
      ControllerGenerateStop(pPVar4,pPVar5);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return lVar7;
}



===== PbcRequestConfigureForNonSequence @ 140006298 =====

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
  PBC_REQUEST *pPVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 auStackY_88 [32];
  undefined2 local_58 [2];
  undefined4 local_54;
  int local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  pPVar4 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_140019068);
  pPVar5 = (PBC_REQUEST *)
           (*DAT_140019930)(WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_140019090);
  memset(local_58,0,0x20);
  local_58[0] = 0x20;
  (*DAT_14001a308)(SpbDriverGlobals,param_3,local_58);
  *(SPBREQUEST__ **)pPVar5 = param_3;
  *(undefined4 *)(pPVar5 + 8) = local_54;
  *(undefined8 *)(pPVar5 + 0x18) = 0;
  *(undefined4 *)(pPVar5 + 0x10) = 0;
  *(int *)(pPVar5 + 0x38) = local_50;
  *(undefined4 *)(pPVar5 + 0xc) = 1;
  pPVar5[0x24] = (PBC_REQUEST)0x0;
  *(undefined4 *)(pPVar4 + 0x70d0) = 0;
  KeClearEvent(pPVar4 + 29000);
  KeClearEvent(pPVar4 + 0x70e8);
  if (local_50 - 1U < 2) {
    *(undefined4 *)(pPVar4 + 0x70d4) = 0;
  }
  lVar2 = PbcRequestConfigureForIndex(pPVar5,*(ulong *)(pPVar5 + 0x10));
  if (lVar2 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)lVar2);
    }
  }
  else {
    (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x50));
    lVar2 = (*DAT_140019f28)(WdfDriverGlobals,*(undefined8 *)pPVar5,OnCancel);
    if (lVar2 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                  &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)lVar2);
      }
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x50));
    }
    else {
      if (*(int *)(pPVar5 + 0x38) == 1) {
        *(longlong *)(pPVar4 + 0x30) = lVar3;
      }
      *(PBC_REQUEST **)(lVar3 + 0x18) = pPVar5;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))
           ) || (1 < uVar6)))) {
        pcVar7 = "write";
        if (*(int *)(pPVar5 + 8) == 1) {
          pcVar7 = "read";
        }
        WPP_SF_dsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                   &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,pcVar7,
                   (char)*(undefined2 *)(lVar3 + 0xc));
      }
      PbcRequestDoTransfer(pPVar4,pPVar5);
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x50));
    }
  }
  if (lVar2 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 2) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || (1 < uVar6)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6,(char)lVar2);
    }
    (*DAT_14001a318)(SpbDriverGlobals,param_3,lVar2);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar6);
  }
  return;
}



===== PbcRequestDoTransfer @ 1400066b8 =====

/* void __cdecl PbcRequestDoTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestDoTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
  }
  if (*(int *)(param_2 + 0x48) == 0) {
    ControllerConfigureForTransfer_Enqueue(param_1,param_2);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
         (1 < uVar3)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3,
                (char)*(int *)(param_2 + 0x48));
    }
    cVar2 = (*DAT_140019cd8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58),
                             (ulonglong)*(uint *)(param_2 + 0x48) * -10);
    if (cVar2 == '\x01') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 & 0x800) != 0 && (uVar3 == 0)) ||
          ((((uVar1 & 0x1000) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000240;
      if (*(PBC_TARGET **)(param_1 + 0x30) != (PBC_TARGET *)0x0) {
        ControllerGenerateStop(param_1,*(PBC_TARGET **)(param_1 + 0x30));
      }
      ControllerCompleteTransfer(param_1,param_2);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar3);
  }
  return;
}



===== PbcRequestGetTransferDirection @ 140006898 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestGetTransferDirection(struct PBC_REQUEST * __ptr64,unsigned long,enum
   SPB_TRANSFER_DIRECTION * __ptr64) */

long __cdecl
PbcRequestGetTransferDirection(PBC_REQUEST *param_1,ulong param_2,SPB_TRANSFER_DIRECTION *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar5 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
  }
  uVar2 = (*DAT_14001a300)(SpbDriverGlobals,*(undefined8 *)param_1);
  (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  local_40 = 0;
  local_38 = 0;
  local_48 = 0x18;
  (*DAT_14001a310)(SpbDriverGlobals,*(undefined8 *)param_1,param_2,&local_48);
  *param_3 = local_48._4_4_;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      pcVar4 = "To Device";
      if (local_48._4_4_ == 1) {
        pcVar4 = "From Device";
      }
      WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5,(char)param_2,pcVar4);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar5);
    }
  }
  return 0;
}



===== PbcTargetGetSettings @ 140006aa8 =====

/* long __cdecl PbcTargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl PbcTargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  PBC_TARGET_SETTINGS PVar7;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  lVar6 = 0;
  PVar7 = (PBC_TARGET_SETTINGS)0x0;
  uVar5 = 1;
  if (*(uint *)((longlong)param_2 + 4) < 8) {
    lVar6 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
                  &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,
                  (char)*(uint *)((longlong)param_2 + 4),8,0xd);
    }
    goto LAB_140006e36;
  }
  if (*(char *)((longlong)param_2 + 0xd) != '\x01') {
    lVar6 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      WPP_SF_dcd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                 &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,
                 *(char *)((longlong)param_2 + 0xd),0xd);
    }
    goto LAB_140006e36;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_dPdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,(char)param_2 + '\b',
                (char)*(undefined4 *)((longlong)param_2 + 0x14),
                (char)*(undefined2 *)((longlong)param_2 + 0x18));
  }
  *(undefined2 *)(param_3 + 4) = *(undefined2 *)((longlong)param_2 + 0x18);
  *(uint *)param_3 = *(ushort *)((longlong)param_2 + 0xf) & 1;
  iVar2 = *(int *)((longlong)param_2 + 0x14);
  if (iVar2 == 100000) {
    uVar5 = 1;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      uVar3 = 0x5d;
      PVar7 = (PBC_TARGET_SETTINGS)0x0;
LAB_140006dc3:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
    }
  }
  else if (iVar2 == 400000) {
    uVar5 = 2;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (1 < uVar4)))) {
      uVar3 = 0x5e;
      PVar7 = (PBC_TARGET_SETTINGS)0x0;
      goto LAB_140006dc3;
    }
  }
  else if (iVar2 == 1000000) {
    uVar5 = 2;
    PVar7 = (PBC_TARGET_SETTINGS)0x1;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      uVar3 = 0x5f;
      PVar7 = (PBC_TARGET_SETTINGS)0x1;
      goto LAB_140006dc3;
    }
  }
  else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
          ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
              &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4,(char)iVar2);
  }
  *(undefined4 *)(param_3 + 8) = uVar5;
  param_3[0xc] = PVar7;
LAB_140006e36:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_8eb16be60c45a32c329eccc273f43ea8_Traceguids,uVar4);
  }
  return lVar6;
}



===== Template_pppxz @ 140006ea8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_pppxz(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 *param_8)

{
  longlong lVar1;
  undefined8 local_res20;
  undefined1 auStack_98 [32];
  undefined8 **local_78;
  undefined8 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_68 = &local_res20;
  local_58 = &param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_60 = 8;
  local_50 = 8;
  local_40 = 8;
  local_30 = 8;
  if (param_8 == (undefined1 *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_8 + lVar1 * 2) != 0);
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  local_28 = &u_NULL;
  if (param_8 != (undefined1 *)0x0) {
    local_28 = param_8;
  }
  local_78 = &local_68;
  local_res20 = param_4;
  EtwWrite(param_1,param_2,param_3,5);
  return;
}



===== Template_pppzxx @ 140006f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_pppzxx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 *param_7,undefined1 param_8,
                    undefined1 param_9)

{
  longlong lVar1;
  undefined8 local_res20;
  undefined1 auStack_b8 [32];
  undefined8 **local_98;
  undefined8 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = &local_res20;
  local_78 = &param_5;
  local_68 = &param_6;
  local_80 = 8;
  local_70 = 8;
  local_60 = 8;
  if (param_7 == (undefined1 *)0x0) {
    local_50 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_7 + lVar1 * 2) != 0);
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_4c = 0;
  local_58 = &u_NULL;
  if (param_7 != (undefined1 *)0x0) {
    local_58 = param_7;
  }
  local_40 = 8;
  local_48 = &param_8;
  local_30 = 8;
  local_38 = &param_9;
  local_98 = &local_88;
  local_res20 = param_4;
  EtwWrite(param_1,param_2,param_3,6);
  return;
}



===== Template_pq @ 14000706c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_pq(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 auStack_68 [32];
  undefined1 **local_48;
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &uStack0000000000000028;
  local_30 = 8;
  local_1c = 0;
  local_48 = &local_38;
  local_20 = 4;
  EtwWrite();
  return;
}



===== Template_px @ 1400070d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_px(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 auStack_68 [32];
  undefined1 **local_48;
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = local_res20;
  local_30 = 8;
  local_2c = 0;
  local_28 = &uStack0000000000000028;
  local_20 = 8;
  local_1c = 0;
  local_48 = &local_38;
  EtwWrite();
  return;
}



===== Template_ppx @ 140007140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_ppx(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 auStack_78 [32];
  undefined1 **local_58;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = local_res20;
  local_40 = 8;
  local_38 = &uStack0000000000000028;
  local_30 = 8;
  local_28 = &uStack0000000000000030;
  local_20 = 8;
  local_58 = &local_48;
  EtwWrite();
  return;
}



===== Template_zxpx @ 1400071b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_zxpx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined1 auStack_88 [32];
  undefined1 **local_68;
  undefined1 *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  if (param_4 == (undefined1 *)0x0) {
    local_50 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_58 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    local_58 = param_4;
  }
  local_48 = &param_5;
  local_4c = 0;
  local_38 = &param_6;
  local_40 = 8;
  local_28 = &param_7;
  local_30 = 8;
  local_68 = &local_58;
  local_20 = 8;
  EtwWrite(param_1,param_2,param_3,4);
  return;
}



===== WPP_SF_dL @ 14000726c =====

void WPP_SF_dL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_dLL @ 1400072b0 =====

void WPP_SF_dLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dcd @ 140007300 =====

void WPP_SF_dcd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,1,&param_6,4,0);
  return;
}



===== WPP_SF_dddd @ 140007354 =====

void WPP_SF_dddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dds @ 1400073b0 =====

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



===== WPP_SF_ddxd @ 14000743c =====

void WPP_SF_ddxd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_ddxq @ 14000749c =====

void WPP_SF_ddxq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_dsPd @ 1400074fc =====

void WPP_SF_dsPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
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
            (param_1,0x2b,param_3,param_2,local_res20,4,pcVar1,lVar3,&param_6,8,&param_7,4,0);
  return;
}



===== ControlerDisableOnFinish @ 14000759c =====

/* void __cdecl ControlerDisableOnFinish(struct PBC_DEVICE * __ptr64) */

void __cdecl ControlerDisableOnFinish(PBC_DEVICE *param_1)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),0);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
  iVar5 = 0;
  bVar2 = (byte)uVar3 & 1;
  if ((uVar3 & 1) != 0) {
    do {
      if (9 < iVar5) break;
      KeStallExecutionProcessor(0x19);
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      iVar5 = iVar5 + 1;
      bVar2 = (byte)uVar3 & 1;
    } while ((uVar3 & 1) != 0);
    if ((((bVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (1 < uVar4)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
    }
  }
  *(undefined4 *)(param_1 + 0x70d4) = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  return;
}



===== ControlerOnCancelTimerExpired @ 14000771c =====

/* void __cdecl ControlerOnCancelTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl ControlerOnCancelTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar2 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    uVar2 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar4 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  uVar2 = (*DAT_140019ce8)(WdfDriverGlobals,param_1);
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    MmGetPhysicalAddress(*(undefined8 *)(lVar3 + 8));
    Template_px();
  }
  KeSetEvent(lVar3 + 29000,0,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  return;
}



===== ControllerAcknowledgeInterrupts @ 1400078f8 =====

/* void __cdecl ControllerAcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerAcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 & 0x800) != 0 && (uVar5 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  uVar4 = 0;
  if (((*(int *)(param_1 + 0x28) == 0) &&
      ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee)))) ||
     (*(int *)(param_1 + 0x28) == 1)) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820))
    ;
    uVar4 = (uVar3 & 1) << 0x14;
  }
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
  uVar4 = (uVar3 | uVar4) & param_2;
  if ((((((uVar4 & 1) != 0) &&
        (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x44)),
        (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if (((((uVar4 & 2) != 0) &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x48)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((((((uVar4 & 4) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if (((((uVar4 & 8) != 0) &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x4c)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((((((uVar4 & 0x10) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if (((((uVar4 & 0x20) != 0) &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x50)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((uVar4 & 0x40) != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x80));
    *(ulong *)(param_1 + 0x6c) = uVar3;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
        (1 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
    }
  }
  if (((((char)uVar4 < '\0') &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x58)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((((((uVar4 >> 8 & 1) != 0) &&
        (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x5c)),
        (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if (((((uVar4 >> 9 & 1) != 0) &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x60)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((((((uVar4 >> 10 & 1) != 0) &&
        (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 100)),
        (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if (((((uVar4 & 0x800) != 0) &&
       (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x68)),
       (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  if ((uVar4 >> 0x14 & 1) != 0) {
    lVar2 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x808));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x808),uVar3 & 0xffffffef);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x824));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar4 & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar4 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar4 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 & 0x800) != 0 && (uVar5 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  return;
}



===== ControllerCompleteTransfer @ 140007fc8 =====

/* void __cdecl ControllerCompleteTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64)
    */

void __cdecl ControllerCompleteTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  undefined2 uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8);
  }
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x50));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    iVar5 = *(int *)(param_2 + 0x20);
    if (iVar5 == 0x10b) {
      pcVar6 = "aborted";
    }
    else if (iVar5 == -0x3ffffee0) {
      pcVar6 = "cancelled";
    }
    else {
      pcVar6 = "error";
      if (-1 < iVar5) {
        pcVar6 = "complete";
      }
    }
    WPP_SF_dLsPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8,
                 (char)*(undefined4 *)(param_2 + 0x10),pcVar6,(char)*(undefined8 *)(param_2 + 0x50),
                 (char)iVar5);
  }
  lVar3 = *(longlong *)(param_2 + 0x50);
  *(undefined8 *)(param_2 + 0x50) = 0;
  *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + lVar3;
  if ((-1 < *(int *)(param_2 + 0x20)) && (*(int *)(param_2 + 0x20) != 0x10b)) {
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    if (*(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0xc)) {
      lVar4 = PbcRequestConfigureForIndex(param_2,*(uint *)(param_2 + 0x10));
      *(long *)(param_2 + 0x20) = lVar4;
      if (-1 < lVar4) {
        (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x50));
        PbcRequestDoTransfer(param_1,param_2);
        goto LAB_1400082f5;
      }
    }
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x40) = 0;
  UNLOCK();
  iVar5 = (*DAT_140019ae0)(WdfDriverGlobals,*(undefined8 *)param_2);
  if (iVar5 < 0) {
    if (iVar5 == -0x3ffffee0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))
           ) || (1 < uVar8)))) {
        uVar7 = 0x61;
        iVar5 = -0x3ffffee0;
LAB_140008216:
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8,(char)iVar5);
      }
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
            (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
              (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) || (1 < uVar8)))) {
      uVar7 = 0x62;
      goto LAB_140008216;
    }
    *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
  }
  if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x38) == 1)) {
    ControlerDisableOnFinish(param_1);
  }
  if (*(int *)(param_2 + 0x20) != -0x3ffffee0) {
    iVar5 = *(int *)(param_1 + 0x70d0);
    do {
      LOCK();
      iVar1 = *(int *)(param_1 + 0x70d0);
      bVar9 = iVar5 == iVar1;
      if (bVar9) {
        *(int *)(param_1 + 0x70d0) = iVar5;
      }
      else {
        iVar5 = iVar1;
      }
      UNLOCK();
    } while (!bVar9);
    if (iVar5 == 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x18) = 0;
      if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x38) == 1)) {
        *(undefined8 *)(param_1 + 0x30) = 0;
      }
      if (((*(int *)(param_2 + 0x20) == 0x10b) &&
          (*(undefined4 *)(param_2 + 0x20) = 0, *(int *)(param_1 + 0x28) == 0)) &&
         ((*(int *)(param_1 + 0x2c) == 0 || (*(int *)(param_1 + 0x2c) == 1)))) {
        *(undefined8 *)(param_2 + 0x18) = 0;
      }
      param_2[0x24] = (PBC_REQUEST)0x1;
      (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x50));
      PbcRequestComplete(param_2);
      goto LAB_1400082f5;
    }
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  param_2[0x24] = (PBC_REQUEST)0x1;
  *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x50));
  KeSetEvent(param_1 + 0x70e8,0,0);
LAB_1400082f5:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
      ((((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)) || (1 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8);
  }
  return;
}



===== ControllerConfigureForTransfer @ 140008360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ControllerConfigureForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

void __cdecl ControllerConfigureForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  int iVar1;
  uint uVar2;
  PBC_TARGET *pPVar3;
  undefined8 uVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  uchar uVar11;
  char cVar12;
  ulong uVar13;
  long lVar14;
  int iVar15;
  ulong uVar16;
  char *pcVar17;
  undefined2 uVar18;
  uint uVar19;
  uint uVar20;
  ulonglong uVar21;
  uint uVar22;
  char *pcVar23;
  PBC_REQUEST PVar24;
  bool bVar25;
  bool bVar26;
  undefined1 local_188 [32];
  undefined1 uVar27;
  char local_148;
  SPB_TRANSFER_DIRECTION local_134;
  PBC_DEVICE *local_130;
  PBC_DEVICE *local_128;
  PBC_DEVICE *local_120;
  PBC_DEVICE *local_118;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_188;
  bVar26 = false;
  uVar22 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar22 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) || (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))
       ) || (1 < uVar22)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
  }
  local_148 = '\0';
  if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
    return;
  }
  if (*(int *)(param_2 + 0x20) == 0x10b) {
    return;
  }
  pPVar3 = *(PBC_TARGET **)(param_1 + 0x30);
  iVar15 = *(int *)(param_2 + 0x38);
  uVar4 = *(undefined8 *)(&DAT_1400174a8 + (longlong)iVar15 * 8);
  *(undefined4 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x3c) = uVar4;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) || (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))
       ) || (1 < uVar22)))) {
    pcVar17 = "UNKNOWN";
    if (iVar15 == 0) {
      pcVar23 = "Invalid";
    }
    else if (iVar15 == 1) {
      pcVar23 = "Single";
    }
    else if (iVar15 == 2) {
      pcVar23 = "First";
    }
    else if (iVar15 == 3) {
      pcVar23 = "Continue";
    }
    else if (iVar15 == 4) {
      pcVar23 = "Last";
    }
    else {
      pcVar23 = "UNKNOWN";
      if (iVar15 == 5) {
        pcVar23 = "Max";
      }
    }
    iVar15 = *(int *)(param_2 + 8);
    if (iVar15 == 0) {
      pcVar17 = "Undefined";
    }
    else if (iVar15 == 1) {
      pcVar17 = "Read";
    }
    else if (iVar15 == 2) {
      pcVar17 = "Write";
    }
    else if (iVar15 == 3) {
      pcVar17 = "Sequence";
    }
    else if (iVar15 == 4) {
      pcVar17 = "LockCtrl";
    }
    else if (iVar15 == 5) {
      pcVar17 = "UnlockCtrl";
    }
    else if (iVar15 == 6) {
      pcVar17 = "LockConn";
    }
    else if (iVar15 == 7) {
      pcVar17 = "UnlockConn";
    }
    else if (iVar15 == 8) {
      pcVar17 = "Other";
    }
    else if (iVar15 == 9) {
      pcVar17 = "Max";
    }
    WPP_SF_dss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,pcVar17,pcVar23);
  }
  uVar21 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x30) + 0xc);
  uVar20 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x30) + 0xc);
  IsDmaOp(param_1,param_2);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x3c),0);
  if (((param_2[0x40] == (PBC_REQUEST)0x1) &&
      ((param_2[0x41] == (PBC_REQUEST)0x1 || (param_2[0x41] == (PBC_REQUEST)0x0)))) ||
     (*(int *)(param_1 + 0x70d4) == 0)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
        ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
    }
    LOCK();
    UNLOCK();
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),0);
    uVar13 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c))
    ;
    uVar19 = 0;
    bVar10 = (byte)uVar13 & 1;
    if ((uVar13 & 1) == 0) {
LAB_1400086d8:
      uVar13 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x54));
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
          ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
        WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,(char)uVar13,
                   (char)*(undefined4 *)(param_1 + 0x6c));
      }
      *(undefined4 *)(param_1 + 0x6c) = 0;
      uVar19 = uVar20;
      if (*(int *)(*(longlong *)(param_1 + 0x30) + 8) == 1) {
        uVar19 = uVar20 | 0x1000;
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 4),uVar19);
      HWREG<unsigned_long>::Write
                (*(HWREG<unsigned_long> **)(param_1 + 8),
                 (*(uint *)(*(longlong *)(param_1 + 0x30) + 0x10) & 3) * 2 | 0x61);
      *(undefined4 *)(pPVar3 + 0x24) = *(undefined4 *)(param_1 + uVar21 * 4 + 0x60c8);
      iVar15 = *(int *)(*(longlong *)(param_1 + 0x30) + 0x10);
      if (iVar15 == 1) {
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x14),
                   *(ulong *)(param_1 + 0x70));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x18),
                   *(ulong *)(param_1 + 0x74));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0xa0),
                   *(ulong *)(param_1 + 0x7c));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                   *(ulong *)(param_1 + 0x78));
        if (*(int *)(pPVar3 + 0x24) == 0) {
          *(undefined4 *)(pPVar3 + 0x24) = 100;
        }
      }
      else if (iVar15 == 2) {
        if (*(char *)(*(longlong *)(param_1 + 0x30) + 0x14) == '\0') {
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),
                     *(ulong *)(param_1 + 0x80));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                     *(ulong *)(param_1 + 0x84));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0xa0),
                     *(ulong *)(param_1 + 0x8c));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                     *(ulong *)(param_1 + 0x88));
          if (*(int *)(pPVar3 + 0x24) == 0) {
            *(undefined4 *)(pPVar3 + 0x24) = 0x19;
          }
        }
        else {
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),
                     *(ulong *)(param_1 + 0x90));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                     *(ulong *)(param_1 + 0x94));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0xa0),
                     *(ulong *)(param_1 + 0x9c));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                     *(ulong *)(param_1 + 0x98));
          if (*(int *)(pPVar3 + 0x24) == 0) {
            *(undefined4 *)(pPVar3 + 0x24) = 10;
          }
        }
      }
      else if (iVar15 == 3) {
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x1c),
                   *(ulong *)(param_1 + 0x80));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x20),
                   *(ulong *)(param_1 + 0x84));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0xa0),
                   *(ulong *)(param_1 + 0x8c));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x24),
                   *(ulong *)(param_1 + 0xa0));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x28),
                   *(ulong *)(param_1 + 0xa4));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0xa4),
                   *(ulong *)(param_1 + 0xac));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x7c),
                   *(ulong *)(param_1 + 0xa8));
        if (*(int *)(pPVar3 + 0x24) == 0) {
          *(undefined4 *)(pPVar3 + 0x24) = 2;
        }
      }
      LOCK();
      UNLOCK();
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x6c),1);
      uVar13 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      uVar19 = 0;
      bVar10 = (byte)uVar13 & 1;
      if ((uVar13 & 1) == 0) {
        do {
          if (9 < uVar19) break;
          KeStallExecutionProcessor(0x19);
          uVar13 = HWREG<unsigned_long>::Read
                             ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
          uVar19 = uVar19 + 1;
          bVar10 = (byte)uVar13 & 1;
        } while ((uVar13 & 1) == 0);
        if (bVar10 == 0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
              ((((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
            uVar18 = 0x1b;
            goto LAB_140008a06;
          }
          goto LAB_140008a19;
        }
      }
      *(undefined4 *)(param_1 + 0x70d4) = 1;
      goto LAB_140008a32;
    }
    do {
      if (9 < uVar19) break;
      KeStallExecutionProcessor(0x19);
      uVar13 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x9c));
      uVar19 = uVar19 + 1;
      bVar10 = (byte)uVar13 & 1;
    } while ((uVar13 & 1) != 0);
    if (bVar10 == 0) goto LAB_1400086d8;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
         (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
      uVar18 = 0x19;
LAB_140008a06:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
    }
LAB_140008a19:
    *(undefined4 *)(param_2 + 0x20) = 0xc000036b;
  }
  else {
LAB_140008a32:
    if (*(int *)(param_2 + 8) != 3) {
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    param_2[0x62] = (PBC_REQUEST)0x1;
    if ((*(int *)(param_2 + 8) == 3) && (*(uint *)(param_2 + 0x10) < *(int *)(param_2 + 0xc) - 1U))
    {
      PbcRequestGetTransferDirection(param_2,*(uint *)(param_2 + 0x10) + 1,&local_134);
      if (*(int *)(param_2 + 0x44) == 2) {
        if (local_134 == 1) {
          PVar24 = (PBC_REQUEST)(*(int *)(param_1 + uVar21 * 4 + 200) == 0);
        }
        else {
          if (local_134 != 2) goto LAB_140008a95;
          PVar24 = (PBC_REQUEST)(*(int *)(param_1 + uVar21 * 4 + 0x10c8) == 0);
        }
      }
      else {
LAB_140008a95:
        if (*(int *)(param_2 + 0x44) != 1) goto LAB_140008ada;
        if (local_134 == 2) {
          PVar24 = (PBC_REQUEST)(*(int *)(param_1 + uVar21 * 4 + 0x20c8) == 0);
        }
        else {
          if (local_134 != 1) goto LAB_140008ada;
          PVar24 = (PBC_REQUEST)(*(int *)(param_1 + uVar21 * 4 + 0x30c8) == 0);
        }
      }
      param_2[0x62] = PVar24;
    }
    else if ((*(int *)(param_2 + 8) - 1U < 2) && (*(int *)(param_2 + 0x38) - 2U < 2)) {
      param_2[0x62] = (PBC_REQUEST)0x0;
    }
LAB_140008ada:
    if (((*(int *)(param_1 + 0x28) == 0) &&
        ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee)))) ||
       (*(int *)(param_1 + 0x28) == 1)) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
           (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
      }
      lVar5 = *(longlong *)(param_1 + 8);
      uVar13 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar5 + 0x808));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar5 + 0x808),uVar13 & 0xffffffef);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
           (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
      }
      lVar5 = *(longlong *)(param_1 + 8);
      uVar13 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar5 + 0x818));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar5 + 0x818),uVar13 | 0x80000);
      lVar5 = *(longlong *)(param_1 + 8);
      uVar13 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar5 + 0x818));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar5 + 0x818),uVar13 & 0xfff7ffff);
    }
    (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    ControllerDisableInterrupts(param_1);
    LOCK();
    *(undefined4 *)(param_1 + 0x40) = 0x242;
    UNLOCK();
    ControllerAcknowledgeInterrupts(param_1,0x1002ff);
    *(undefined4 *)(param_1 + 0x44) = 0;
    (*DAT_140019768)(WdfDriverGlobals);
    if (*(int *)(param_2 + 0x44) == 2) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
           (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
        uVar18 = 0x1e;
LAB_140008cd9:
        WPP_SF_ddxd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
                    &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,
                    (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined8 *)(param_2 + 0x28),
                    (char)*(undefined2 *)(*(longlong *)(param_1 + 0x30) + 0xc));
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x58) = 0;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
          ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
        uVar18 = 0x1f;
        goto LAB_140008cd9;
      }
    }
    KeClearEvent(param_1 + 0x7100);
    KeClearEvent(param_1 + 0x7118);
    KeClearEvent(param_1 + 0x7130);
    LOCK();
    *(undefined4 *)(param_1 + 0x7160) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x7174) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x7164) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x7168) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x716c) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x7170) = 0;
    UNLOCK();
    local_130 = param_1 + 29000;
    bVar9 = false;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    local_128 = param_1 + 0x7118;
    local_120 = param_1 + 0x7130;
    local_118 = param_1 + 0x7100;
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
    if (*(int *)(param_1 + 0x6c) == 0) {
      if (param_1[0x71d0] == (PBC_DEVICE)0x0) {
        ControllerProcessInterrupts(param_1,param_2,0x10);
      }
      else {
        lVar14 = ControllerExecuteDmaTransaction(param_1,param_2);
        if (lVar14 < 0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 >> 8 & 1) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
               (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
            WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                      &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,(char)lVar14);
          }
          goto LAB_140009adb;
        }
      }
      do {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
             (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
          WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                      &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,
                      (char)*(undefined4 *)(param_1 + 0x7160),
                      (char)*(undefined4 *)(param_1 + 0x7170),local_148);
        }
        (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
        if ((*(int *)(param_1 + 0x7160) == 0) && (*(int *)(param_1 + 0x7170) == 0)) {
          uVar13 = *(ulong *)(param_1 + 0x40);
          do {
            LOCK();
            uVar16 = *(ulong *)(param_1 + 0x40);
            bVar25 = uVar13 == uVar16;
            if (bVar25) {
              *(ulong *)(param_1 + 0x40) = uVar13;
            }
            else {
              uVar13 = uVar16;
            }
            UNLOCK();
          } while (!bVar25);
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
              ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
            WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,(char)uVar13,
                       param_1[0x48]);
          }
          if ((uVar13 != 0) && (param_1[0x48] != (PBC_DEVICE)0x0)) {
            ControllerEnableInterrupts(param_1,uVar13);
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0 &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
                ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                 ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
        }
        (*DAT_140019768)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
             (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
        }
        iVar15 = KeWaitForMultipleObjects(4,&local_130,1,0);
        if (iVar15 == 3) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
               (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                     &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
          }
          KeClearEvent(param_1 + 0x7100);
          iVar15 = *(int *)(param_1 + 0x7170);
          do {
            LOCK();
            iVar1 = *(int *)(param_1 + 0x7170);
            bVar25 = iVar15 == iVar1;
            if (bVar25) {
              *(int *)(param_1 + 0x7170) = iVar15;
            }
            else {
              iVar15 = iVar1;
            }
            UNLOCK();
          } while (!bVar25);
          if (iVar15 == 0) {
            iVar15 = *(int *)(param_1 + 0x7174);
            do {
              LOCK();
              iVar1 = *(int *)(param_1 + 0x7174);
              bVar25 = iVar15 == iVar1;
              if (bVar25) {
                *(int *)(param_1 + 0x7174) = iVar15;
              }
              else {
                iVar15 = iVar1;
              }
              UNLOCK();
            } while (!bVar25);
            if (iVar15 == 0) {
              iVar15 = *(int *)(param_1 + 0x7164);
              do {
                LOCK();
                iVar1 = *(int *)(param_1 + 0x7164);
                bVar25 = iVar15 == iVar1;
                if (bVar25) {
                  *(int *)(param_1 + 0x7164) = iVar15;
                }
                else {
                  iVar15 = iVar1;
                }
                UNLOCK();
              } while (!bVar25);
              if (iVar15 == 0) {
                iVar15 = *(int *)(param_1 + 0x7168);
                do {
                  LOCK();
                  iVar1 = *(int *)(param_1 + 0x7168);
                  bVar25 = iVar15 == iVar1;
                  if (bVar25) {
                    *(int *)(param_1 + 0x7168) = iVar15;
                  }
                  else {
                    iVar15 = iVar1;
                  }
                  UNLOCK();
                } while (!bVar25);
                if (iVar15 == 0) {
                  iVar15 = *(int *)(param_1 + 0x716c);
                  do {
                    LOCK();
                    iVar1 = *(int *)(param_1 + 0x716c);
                    bVar25 = iVar15 == iVar1;
                    if (bVar25) {
                      *(int *)(param_1 + 0x716c) = iVar15;
                    }
                    else {
                      iVar15 = iVar1;
                    }
                    UNLOCK();
                  } while (!bVar25);
                  if (iVar15 == 0) goto LAB_140009a02;
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                     ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
                      (((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
                        (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))))) {
                    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
                  }
                  bVar7 = true;
                  bVar6 = true;
                  if (*(int *)(param_2 + 0x44) == 2) {
                    if ((*(int *)(param_1 + 0x28) == 0) && (*(uint *)(param_1 + 0x2c) < 2)) {
                      KeStallExecutionProcessor(*(undefined4 *)(pPVar3 + 0x24));
                      uVar13 = HWREG<unsigned_long>::Read
                                         ((HWREG<unsigned_long> *)
                                          (*(longlong *)(param_1 + 8) + 0x34));
                      if ((uVar13 & 0x40) != 0) {
                        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
                           (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                             (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                          WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                                    &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,
                                    (char)*(undefined8 *)(param_2 + 0x50));
                        }
                        LOCK();
                        *(uint *)(param_1 + 0x7164) = *(uint *)(param_1 + 0x7164) | 1;
                        UNLOCK();
                        uVar13 = HWREG<unsigned_long>::Read
                                           ((HWREG<unsigned_long> *)
                                            (*(longlong *)(param_1 + 8) + 0x80));
                        *(ulong *)(param_1 + 0x6c) = uVar13;
                        KeSetEvent(param_1 + 0x7100,0,0);
                        bVar7 = false;
                        bVar6 = false;
                        goto LAB_140009a3f;
                      }
                      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                           (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,
                                  (char)*(undefined8 *)(param_2 + 0x50));
                      }
                    }
                    else {
                      uVar13 = HWREG<unsigned_long>::Read
                                         ((HWREG<unsigned_long> *)
                                          (*(longlong *)(param_1 + 8) + 0x818));
                      uVar16 = HWREG<unsigned_long>::Read
                                         ((HWREG<unsigned_long> *)
                                          (*(longlong *)(param_1 + 8) + 0x818));
                      uVar19 = (uVar16 >> 0x10 & 1) + (uVar13 & 0xffff);
                      uVar27 = (undefined1)uVar19;
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0 &&
                           (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
                         ((((uVar2 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                          ((((uVar2 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
                        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,uVar27);
                      }
                      if (((((ulonglong)uVar19 != *(ulonglong *)(param_2 + 0x28)) &&
                           ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                          ((uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0 &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
                         (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                           (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                        WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,uVar27,
                                   (char)*(ulonglong *)(param_2 + 0x28));
                        goto LAB_140009a02;
                      }
                    }
                  }
                  goto LAB_140009a13;
                }
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
                    ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
                  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                           &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
                }
              }
              else {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
                    ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
                  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                           &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
                }
                if ((*(uint *)(param_1 + 0x6c) & 7) == 0) {
                  *(undefined4 *)(param_2 + 0x20) = 0x10b;
                  if (((*(int *)(param_1 + 0x28) != 0) ||
                      ((*(int *)(param_1 + 0x2c) != 0xf2 && (0xed < *(int *)(param_1 + 0x2c) - 2U)))
                      ) && (*(int *)(param_1 + 0x28) != 1)) goto LAB_14000936a;
                  uVar13 = HWREG<unsigned_long>::Read
                                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
                  uVar16 = HWREG<unsigned_long>::Read
                                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
                  uVar19 = (uVar13 & 0xffff) + (uVar16 >> 0x10 & 1);
                  *(ulonglong *)(param_2 + 0x50) = (ulonglong)uVar19;
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     (((((uVar2 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                       (((uVar2 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                              &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,(char)uVar19);
                  }
                }
                else {
                  *(undefined4 *)(param_2 + 0x20) = 0xc000000e;
LAB_14000936a:
                  *(undefined8 *)(param_2 + 0x50) = 0;
                }
                if (param_1[0x71d0] != (PBC_DEVICE)0x0) {
                  uVar13 = 3;
                  goto LAB_14000916a;
                }
              }
            }
            else {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                  (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
                  ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
                WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                         &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
              }
              if (param_1[0x71d0] != (PBC_DEVICE)0x0) {
                ControllerCompleteDmaTransaction(param_1,param_2,3);
              }
            }
          }
          else {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar19 & 0x800) != 0 && (uVar22 == 0)) ||
                ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
            }
            KeStallExecutionProcessor(*(undefined4 *)(pPVar3 + 0x24));
            if (*(int *)(param_2 + 0x44) == 1) {
              if (param_1[0x71d0] == (PBC_DEVICE)0x0) {
                lVar14 = ControllerDoRead(param_1,param_2);
                if (((((lVar14 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                     (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                     (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                            &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,(char)lVar14);
                }
              }
              else {
                uVar13 = 2;
LAB_14000916a:
                ControllerCompleteDmaTransaction(param_1,param_2,uVar13);
              }
            }
          }
          bVar7 = true;
          bVar6 = true;
LAB_140009a13:
          if ((param_1[0x71d0] == (PBC_DEVICE)0x0) ||
             ((bVar8 && ((*(int *)(param_2 + 0x44) == 2 ||
                         ((bVar26 && (*(int *)(param_2 + 0x44) == 1)))))))) {
            bVar9 = true;
          }
        }
        else {
          if (iVar15 == 1) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                 (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
            }
            KeClearEvent(param_1 + 0x7118);
            uVar11 = ControllerDmaEventProcessing(param_1,param_2);
            bVar8 = true;
            bVar6 = bVar7;
            if (uVar11 != '\0') {
              bVar6 = true;
              bVar7 = bVar6;
            }
          }
          else if (iVar15 == 2) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                 (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
            }
            KeClearEvent(param_1 + 0x7130);
            uVar11 = ControllerDmaEventProcessing(param_1,param_2);
            bVar26 = true;
            bVar6 = bVar7;
            if (uVar11 != '\0') {
              bVar6 = true;
              bVar7 = true;
            }
          }
          else if (iVar15 == 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
            }
            KeClearEvent(param_1 + 29000);
            if (local_148 == '\0') {
              local_148 = '\x01';
              if (param_1[0x71d0] != (PBC_DEVICE)0x0) {
                ControllerCompleteDmaTransaction(param_1,param_2,3);
              }
              cVar12 = (*DAT_140019cd8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x70c8),
                                        (ulonglong)
                                        *(uint *)(param_1 + (ulonglong)uVar20 * 4 + 0x50c8) * -10);
              if (cVar12 == '\x01') {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                    ((((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
                  uVar18 = 0x35;
LAB_1400099a4:
                  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
                           &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
                }
              }
              else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        (uVar19 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar19 & 8) != 0)) &&
                       (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                      (((((uVar19 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
                        (((uVar19 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
                uVar18 = 0x36;
                goto LAB_1400099a4;
              }
            }
            else {
              bVar6 = true;
              bVar7 = true;
            }
          }
LAB_140009a02:
          if (bVar6) goto LAB_140009a13;
        }
LAB_140009a3f:
      } while (!bVar9);
      cVar12 = (*DAT_140019ce0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x70c8),0);
      if (((((cVar12 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
           (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 >> 8 & 1) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
          ((((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)) || (1 < uVar22)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22,
                  (char)*(int *)(param_1 + 0x6c));
      }
      *(undefined4 *)(param_2 + 0x20) = 0x10b;
    }
  }
LAB_140009adb:
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),0);
  (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
  ControllerDisableInterrupts(param_1);
  LOCK();
  *(undefined4 *)(param_1 + 0x40) = 0;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x44) = 0;
  (*DAT_140019768)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
  iVar15 = *(int *)(param_1 + 0x7174);
  do {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x7174);
    bVar26 = iVar15 == iVar1;
    if (bVar26) {
      *(int *)(param_1 + 0x7174) = iVar15;
    }
    else {
      iVar15 = iVar1;
    }
    UNLOCK();
  } while (!bVar26);
  if (iVar15 == 0) {
    iVar15 = *(int *)(param_1 + 0x70d0);
    do {
      LOCK();
      iVar1 = *(int *)(param_1 + 0x70d0);
      bVar26 = iVar15 == iVar1;
      if (bVar26) {
        *(int *)(param_1 + 0x70d0) = iVar15;
      }
      else {
        iVar15 = iVar1;
      }
      UNLOCK();
    } while (!bVar26);
    if (iVar15 == 0) goto LAB_140009b82;
    *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
  }
  else {
    *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  ControllerGenerateStop(param_1,pPVar3);
LAB_140009b82:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 & 8) != 0)) &&
     ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) ||
        (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))) || (1 < uVar22)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
  }
  ControllerCompleteTransfer(param_1,param_2);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar20 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar20 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar20 >> 0xb & 1) != 0 && (uVar22 == 0)) || (((uVar20 >> 0xc & 1) != 0 && (uVar22 == 1)))
       ) || (1 < uVar22)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar22);
  }
  return;
}



===== ControllerDisableInterrupts @ 140009c50 =====

/* void __cdecl ControllerDisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableInterrupts(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x30),0);
  if (((*(int *)(param_1 + 0x28) == 0) &&
      ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee)))) ||
     (*(int *)(param_1 + 0x28) == 1)) {
    lVar2 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x820));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x820),uVar3 | 2);
  }
  param_1[0x48] = (PBC_DEVICE)0x1;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  return;
}



===== ControllerDoRead @ 140009d88 =====

/* long __cdecl ControllerDoRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulong uVar4;
  ulong uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  long lVar11;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8);
  }
  uVar3 = *(ulonglong *)(param_2 + 0x28);
  uVar9 = *(ulonglong *)(param_2 + 0x50);
  lVar11 = 0;
  uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    in_stack_ffffffffffffffb8 = *(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50);
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8,
               (char)in_stack_ffffffffffffffb8,(char)uVar4);
  }
  for (; (uVar9 < uVar3 && (uVar4 != 0)); uVar4 = uVar4 - 1) {
    uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10));
    puVar7 = *(undefined8 **)(param_2 + 0x30);
    lVar11 = -0x3ffffffc;
    uVar10 = uVar9;
    if (uVar9 < *(ulonglong *)(param_2 + 0x28)) {
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
        puVar1 = (uint *)(puVar7 + 5);
        if (uVar10 < *puVar1) {
          if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
            in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
            lVar6 = MmMapLockedPagesSpecifyCache(puVar7,0,1,0,in_stack_ffffffffffffffb8,0x10);
          }
          else {
            lVar6 = puVar7[3];
          }
          if (lVar6 != 0) {
            *(char *)(lVar6 + uVar10) = (char)uVar5;
            lVar11 = 0;
          }
          break;
        }
        uVar10 = uVar10 - *puVar1;
      }
    }
    if (lVar11 < 0) break;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar2 < '\0')) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
        || (1 < uVar8)))) {
      in_stack_ffffffffffffffb8 = uVar9;
      WPP_SF_dPdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8,(char)uVar9,
                  (char)*(undefined2 *)(*(longlong *)(param_1 + 0x30) + 0xc),(char)uVar5);
    }
    *(longlong *)(param_2 + 0x50) = *(longlong *)(param_2 + 0x50) + 1;
    uVar9 = uVar9 + 1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
       || (1 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar8);
  }
  return lVar11;
}



===== ControllerDoWrite @ 14000a018 =====

/* long __cdecl ControllerDoWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  ulong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  long lVar12;
  ulonglong uVar13;
  byte bVar14;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar9);
  }
  uVar2 = *(ulonglong *)(param_2 + 0x28);
  uVar13 = *(ulonglong *)(param_2 + 0x50);
  lVar12 = 0;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  iVar11 = 0x20 - uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
     ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar9 == 1)))) ||
       (1 < uVar9)))))) {
    in_stack_ffffffffffffffb8 = *(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50);
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar9,
               (char)in_stack_ffffffffffffffb8,(char)iVar11);
  }
  lVar4 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar4 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar4 + 0x800),uVar3 & 0xfffffffe);
  for (; (uVar13 < uVar2 && (iVar11 != 0)); iVar11 = iVar11 + -1) {
    puVar5 = *(undefined8 **)(param_2 + 0x30);
    bVar14 = 0;
    lVar12 = -0x3ffffffc;
    uVar8 = uVar13;
    if (uVar13 < *(ulonglong *)(param_2 + 0x28)) {
      for (; puVar5 != (undefined8 *)0x0; puVar5 = (undefined8 *)*puVar5) {
        puVar1 = (uint *)(puVar5 + 5);
        if (uVar8 < *puVar1) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
            lVar4 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,in_stack_ffffffffffffffb8,0x10);
          }
          else {
            lVar4 = puVar5[3];
          }
          if (lVar4 != 0) {
            bVar14 = *(byte *)(lVar4 + uVar8);
            lVar12 = 0;
          }
          break;
        }
        uVar8 = uVar8 - *puVar1;
      }
    }
    if (lVar12 < 0) goto LAB_14000a2f2;
    uVar6 = (uint)bVar14;
    if (uVar13 == 0) {
      uVar6 = bVar14 | 0x400;
    }
    uVar7 = uVar6;
    if (((param_2[0x62] != (PBC_REQUEST)0x0) && (uVar2 - uVar13 == 1)) &&
       (uVar7 = uVar6 | 0x200, uVar2 == 1)) {
      uVar7 = uVar6 | 0x600;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar6 < '\0')) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
        ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
      uVar6 = uVar7 & 0x600;
      pcVar10 = " ";
      if (uVar6 == 0x200) {
        pcVar10 = "STOP";
      }
      if (uVar6 == 0x400) {
        pcVar10 = "RESTART";
      }
      if (uVar6 == 0x600) {
        pcVar10 = "RESTART/STOP";
      }
      in_stack_ffffffffffffffb8 = uVar13;
      WPP_SF_dPDDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar9,(char)uVar13,
                   (char)*(undefined2 *)(*(longlong *)(param_1 + 0x30) + 0xc),bVar14,pcVar10);
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar7);
    *(longlong *)(param_2 + 0x50) = *(longlong *)(param_2 + 0x50) + 1;
    uVar13 = uVar13 + 1;
  }
  lVar4 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar4 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar4 + 0x800),uVar3 | 1);
LAB_14000a2f2:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
      ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar9);
  }
  return lVar12;
}



===== ControllerEnableInterrupts @ 14000a368 =====

/* void __cdecl ControllerEnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerEnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  param_1[0x48] = (PBC_DEVICE)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || (1 < uVar4)))))) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
              &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4,(char)param_2);
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x30),param_2 & 0x2ff);
  if ((((*(int *)(param_1 + 0x28) == 0) &&
       ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee)))) ||
      (*(int *)(param_1 + 0x28) == 1)) && ((param_2 & 0x1002ff) >> 0x14 != 0)) {
    lVar2 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x820));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x820),uVar3 & 0xfffffffd);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  return;
}



===== ControllerGetInterruptStatus @ 14000a50c =====

/* unsigned long __cdecl ControllerGetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ControllerGetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar3);
  }
  uVar4 = 0;
  if (((*(int *)(param_1 + 0x28) == 0) &&
      ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee)))) ||
     (*(int *)(param_1 + 0x28) == 1)) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x820))
    ;
    uVar4 = (uVar2 & 1) << 0x14;
  }
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x34));
  if (param_1[0x48] == (PBC_DEVICE)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || (1 < uVar3)))) {
      WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar3,(char)uVar2,(char)param_2);
    }
    uVar2 = (uVar2 | uVar4) & param_2;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar4 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || (1 < uVar3)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar3);
    }
  }
  else {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar4 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        ((((uVar4 >> 0xc & 1) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
      WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                 &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar3,(char)uVar2,(char)param_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== ControllerInitialize @ 14000a700 =====

/* void __cdecl ControllerInitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerInitialize(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulong uVar4;
  uint uVar5;
  longlong local_res8;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
  }
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (lVar2 != 0) {
    uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x84),uVar4 & 0xfffffffc);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x18) + 0x84));
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    if (*(int *)(param_1 + 0x68) == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
          ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5,
                  (char)*(int *)(param_1 + 0xc4));
      }
      local_res8 = (ulonglong)*(uint *)(param_1 + 0xc4) * -10000;
      uVar3 = KeDelayExecutionThread(0,0,&local_res8);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
          ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5,uVar3);
      }
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
            (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar5 == 1))))
             || (1 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
    }
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x800),1);
  *(undefined4 *)(param_1 + 0x70d4) = 0;
  ControllerDisableInterrupts(param_1);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar5);
    }
  }
  return;
}



===== ControllerPrepareForRead @ 14000a9ec =====

/* long __cdecl ControllerPrepareForRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long * __ptr64) */

long __cdecl ControllerPrepareForRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  ulong local_res8;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
      (1 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar7);
  }
  uVar10 = *(ulonglong *)(param_2 + 0x58);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  local_res8 = 0;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
  iVar9 = 0x1f - uVar3;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x74));
  lVar2 = *(longlong *)(param_1 + 8);
  iVar6 = 0x20 - uVar3;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 & 0xfffffffe);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
      (1 < uVar7)))) {
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar7,(char)uVar1 - (char)uVar10,
               (char)iVar6);
  }
  *(undefined2 *)(param_2 + 0x60) = 0;
  if (uVar10 < uVar1) {
    do {
      if ((iVar6 == 0) || (iVar9 == 0)) break;
      uVar4 = 0x100;
      if (uVar10 == 0) {
        uVar4 = 0x500;
      }
      uVar5 = uVar4;
      if ((param_2[0x62] != (PBC_REQUEST)0x0) && (uVar1 - uVar10 == 1)) {
        uVar5 = uVar4 | 0x200;
        *(undefined2 *)(param_2 + 0x60) = 1;
        if (uVar1 == 1) {
          uVar5 = uVar4 | 0x600;
        }
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar4 < '\0')) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar4 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar7 == 1)))
           ) || (1 < uVar7)))) {
        uVar4 = uVar5 & 0x600;
        pcVar8 = " ";
        if (uVar4 == 0x200) {
          pcVar8 = "STOP";
        }
        if (uVar4 == 0x400) {
          pcVar8 = "RESTART";
        }
        if (uVar4 == 0x600) {
          pcVar8 = "RESTART/STOP";
        }
        WPP_SF_dPDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                    &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar7,(char)uVar10,
                    (char)*(undefined2 *)(*(longlong *)(param_1 + 0x30) + 0xc),pcVar8);
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x10),uVar5)
      ;
      local_res8 = local_res8 + 1;
      *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + -1;
      iVar6 = iVar6 + -1;
    } while (uVar10 < uVar1);
  }
  *param_3 = local_res8;
  lVar2 = *(longlong *)(param_1 + 8);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x800));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x800),uVar3 | 1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar4 & 0x800) != 0 && (uVar7 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
       (1 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar7);
  }
  return 0;
}



===== ControllerProcessInterrupts @ 14000ad20 =====

/* void __cdecl ControllerProcessInterrupts(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long) */

void __cdecl ControllerProcessInterrupts(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  ulong local_res18 [2];
  
  uVar10 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar10 = *(uint *)(param_1 + 0x24);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar11 >> 10 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,(char)param_3);
    }
  }
  if ((param_3 >> 6 & 1) == 0) {
    if ((param_3 >> 1 & 1) == 0) {
      if (((param_3 >> 2 & 1) == 0) || (*(int *)(param_2 + 0x44) != 1)) {
        if (((param_3 >> 4 & 1) == 0) || (*(int *)(param_2 + 0x44) != 1)) {
LAB_14000b218:
          if (((param_3 >> 0x14 & 1) != 0) && (*(int *)(param_2 + 0x44) == 2)) {
            lVar3 = *(longlong *)(param_1 + 8);
            uVar6 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x808));
            HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x808),uVar6 & 0xffffffef);
            iVar5 = *(int *)(param_1 + 0x70d0);
            do {
              LOCK();
              iVar1 = *(int *)(param_1 + 0x70d0);
              bVar12 = iVar5 == iVar1;
              if (bVar12) {
                *(int *)(param_1 + 0x70d0) = iVar5;
              }
              else {
                iVar5 = iVar1;
              }
              UNLOCK();
            } while (!bVar12);
            if (iVar5 != 0) goto LAB_14000b153;
            if (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x50)) goto LAB_14000b04f;
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                 (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                       &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
            }
            LOCK();
            *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffefffff;
            UNLOCK();
            LOCK();
            *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10;
            UNLOCK();
          }
          if (((param_3 >> 4 & 1) != 0) && (*(int *)(param_2 + 0x44) == 2)) {
            iVar5 = *(int *)(param_1 + 0x70d0);
            do {
              LOCK();
              iVar1 = *(int *)(param_1 + 0x70d0);
              bVar12 = iVar5 == iVar1;
              if (bVar12) {
                *(int *)(param_1 + 0x70d0) = iVar5;
              }
              else {
                iVar5 = iVar1;
              }
              UNLOCK();
            } while (!bVar12);
            if (iVar5 != 0) goto LAB_14000b153;
            if (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x50)) goto LAB_14000b04f;
            lVar4 = ControllerDoWrite(param_1,param_2);
            if (lVar4 < 0) {
              *(long *)(param_2 + 0x20) = lVar4;
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                   (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                uVar9 = 0x45;
                goto LAB_14000af5e;
              }
              goto LAB_14000aee7;
            }
            *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x20) = *(undefined4 *)(param_2 + 0x44);
            if (*(longlong *)(param_2 + 0x28) == *(longlong *)(param_2 + 0x50)) {
              if (param_2[0x62] == (PBC_REQUEST)0x0) {
                if (((*(int *)(param_1 + 0x28) == 0) &&
                    ((*(int *)(param_1 + 0x2c) == 0xf2 || (*(int *)(param_1 + 0x2c) - 2U < 0xee))))
                   || (*(int *)(param_1 + 0x28) == 1)) {
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                       (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
                  }
                  lVar3 = *(longlong *)(param_1 + 8);
                  uVar6 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x808));
                  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x808),uVar6 | 0x10);
                  LOCK();
                  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
                  UNLOCK();
                  LOCK();
                  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100000;
                  UNLOCK();
                }
                else {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                     ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
                      (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                        (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))))) {
                    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
                  }
                  LOCK();
                  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10;
                  UNLOCK();
                }
                goto LAB_14000b908;
              }
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                  (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                  ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
                WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                         &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
              }
              LOCK();
              *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
              UNLOCK();
            }
            else {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                  (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                   (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                         &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
              }
              LOCK();
              *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10;
              UNLOCK();
            }
          }
          if ((param_3 >> 9 & 1) == 0) goto LAB_14000b908;
          if (*(int *)(param_2 + 0x44) == 1) {
            if (param_1[0x71d0] == (PBC_DEVICE)0x0) {
              if (*(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50) != 0) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                     (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                  WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                            &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,
                            (char)(*(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50)));
                }
                lVar4 = ControllerDoRead(param_1,param_2);
                if (lVar4 < 0) {
                  *(long *)(param_2 + 0x20) = lVar4;
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                       (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                    uVar9 = 0x4b;
                    goto LAB_14000af5e;
                  }
                  goto LAB_14000aee7;
                }
              }
            }
            else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                    ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                     ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
              uVar9 = 0x4c;
LAB_14000b6b2:
              uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
LAB_14000b8e4:
              WPP_SF_d(uVar8,uVar9,&WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
            }
          }
          else if (*(int *)(param_2 + 0x44) == 2) {
            if (param_1[0x71d0] == (PBC_DEVICE)0x0) {
              if (*(int *)(param_2 + 0x20) == 0x10b) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                    ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
                  WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                            &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,
                            (char)*(undefined8 *)(param_2 + 0x28) -
                            (char)*(undefined8 *)(param_2 + 0x50));
                }
              }
              else if (*(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50) == 0) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                    ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
                  uVar9 = 0x4f;
                  goto LAB_14000b6b2;
                }
              }
              else {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                     (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                  WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                            &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,
                            (char)(*(longlong *)(param_2 + 0x28) - *(longlong *)(param_2 + 0x50)));
                }
                *(undefined4 *)(param_2 + 0x20) = 0xc000000e;
                *(undefined8 *)(param_2 + 0x50) = 0;
              }
            }
            else {
              uVar6 = HWREG<unsigned_long>::Read
                                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
              uVar7 = HWREG<unsigned_long>::Read
                                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x818));
              uVar11 = (uVar6 & 0xffff) + (uVar7 >> 0x10 & 1);
              if ((ulonglong)uVar11 != *(ulonglong *)(param_2 + 0x28)) {
                if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                    ((((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
                  WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,(char)uVar11,
                             (char)*(ulonglong *)(param_2 + 0x28));
                }
                *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
                goto LAB_14000aee7;
              }
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                  (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                   (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                uVar9 = 0x51;
                goto LAB_14000b8e4;
              }
            }
          }
          LOCK();
          *(uint *)(param_1 + 0x7168) = *(uint *)(param_1 + 0x7168) | 1;
          UNLOCK();
        }
        else {
LAB_14000b0d0:
          iVar5 = *(int *)(param_1 + 0x70d0);
          do {
            LOCK();
            iVar1 = *(int *)(param_1 + 0x70d0);
            bVar12 = iVar5 == iVar1;
            if (bVar12) {
              *(int *)(param_1 + 0x70d0) = iVar5;
            }
            else {
              iVar5 = iVar1;
            }
            UNLOCK();
          } while (!bVar12);
          if (iVar5 == 0) {
            local_res18[0] = 0;
            lVar4 = ControllerPrepareForRead(param_1,param_2,local_res18);
            if (lVar4 < 0) {
              *(long *)(param_2 + 0x20) = lVar4;
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                   (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                uVar9 = 0x43;
                goto LAB_14000af5e;
              }
              goto LAB_14000aee7;
            }
            *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x20) = *(undefined4 *)(param_2 + 0x44);
            LOCK();
            *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
            UNLOCK();
            if (*(short *)(param_2 + 0x60) == 0) {
              uVar6 = 0;
              if (1 < local_res18[0]) {
                uVar6 = local_res18[0] - 1;
              }
              HWREG<unsigned_long>::Write
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x38),uVar6);
              LOCK();
              *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 4;
              UNLOCK();
            }
            goto LAB_14000b218;
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
               (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
            uVar6 = HWREG<unsigned_long>::Read
                              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x78));
            WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                      &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,(char)uVar6);
          }
LAB_14000b153:
          LOCK();
          *(uint *)(param_1 + 0x7170) = *(uint *)(param_1 + 0x7170) | 1;
          UNLOCK();
        }
        goto LAB_14000b8fb;
      }
      lVar4 = ControllerDoRead(param_1,param_2);
      if (-1 < lVar4) {
        LOCK();
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffb;
        UNLOCK();
        if (*(longlong *)(param_2 + 0x28) != *(longlong *)(param_2 + 0x50)) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
               (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                     &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
          }
          goto LAB_14000b0d0;
        }
        if (*(short *)(param_2 + 0x60) == 1) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
               (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                     &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
          }
          goto LAB_14000b218;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
             (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                   &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
        }
LAB_14000b04f:
        LOCK();
        *(uint *)(param_1 + 0x716c) = *(uint *)(param_1 + 0x716c) | 1;
        UNLOCK();
        goto LAB_14000b8fb;
      }
      *(long *)(param_2 + 0x20) = lVar4;
      if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar11 >> 0xb & 1) == 0 || (uVar10 != 0)) &&
           (((uVar11 >> 0xc & 1) == 0 || (uVar10 != 1)))) && (uVar10 < 2)))) goto LAB_14000aee7;
      uVar9 = 0x3e;
LAB_14000af5e:
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,(char)lVar4);
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
             ((((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
    }
LAB_14000aee7:
    LOCK();
    *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
    UNLOCK();
  }
  else {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
         (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
      WPP_SF_dPdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                  &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10,
                  (char)*(undefined8 *)(param_2 + 0x50),(char)*(undefined4 *)(param_2 + 0x20),
                  (char)*(undefined4 *)(param_1 + 0x6c));
    }
    LOCK();
    *(uint *)(param_1 + 0x7164) = *(uint *)(param_1 + 0x7164) | 1;
    UNLOCK();
  }
LAB_14000b8fb:
  LOCK();
  *(undefined4 *)(param_1 + 0x40) = 0;
  UNLOCK();
LAB_14000b908:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar11 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar11 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar11 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar11 >> 0xc & 1) != 0 && (uVar10 == 1)))
       ) || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar10);
  }
  return;
}



===== ControllerUninitialize @ 14000b978 =====

/* void __cdecl ControllerUninitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerUninitialize(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
  }
  ControllerDisableInterrupts(param_1);
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (lVar2 != 0) {
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x84));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x84),uVar3 | 3);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x18) + 0x84));
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_072b5f4b5da3f262d743f4e593e9106d_Traceguids,uVar4);
    }
  }
  return;
}



===== WPP_SF_dLsPd @ 14000bae0 =====

void WPP_SF_dLsPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

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
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pcVar1,lVar3,&param_7,8,&param_8,
             4,0);
  return;
}



===== WPP_SF_dP @ 14000bb98 =====

void WPP_SF_dP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_dPdD @ 14000bbdc =====

void WPP_SF_dPdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dPDDs @ 14000bc3c =====

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



===== WPP_SF_dPDs @ 14000bcf8 =====

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



===== WPP_SF_dPP @ 14000bd9c =====

void WPP_SF_dPP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_dss @ 14000bdf0 =====

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



===== Read @ 14000beb4 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Read(void) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Read(HWREG<unsigned_long> *this)

{
  return *(ulong *)this;
}



===== Write @ 14000beb8 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Write(unsigned long) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Write(HWREG<unsigned_long> *this,ulong param_1)

{
  *(ulong *)this = param_1;
  LOCK();
  UNLOCK();
  return param_1;
}



===== GetDefaultSettings @ 14000bec4 =====

/* void __cdecl GetDefaultSettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetDefaultSettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  PBC_DEVICE *pPVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar4);
  }
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x70),0x1b0
                     );
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x74),0x1fb)
  ;
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x78),9);
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0x7c),1);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x80),0x48);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x84),0xa0);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x88),9);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0x8c),5);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 0x90),0x1a)
  ;
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0x94),0x32);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_HoldCnt",(ulong *)(param_1 + 0x98),5);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0x9c),5);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),0xc);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),0x16);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0xa8),1);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xac),1);
  SetDefaultParameter(param_1,(ushort *)L"DmaError",(ulong *)(param_1 + 0xb0),0);
  SetDefaultParameter(param_1,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xb4),1);
  SetDefaultParameter(param_1,(ushort *)L"MonitorOnIdleTimeout",(ulong *)(param_1 + 0xb8),2000);
  SetDefaultParameter(param_1,(ushort *)L"MonitorOffIdleTimeout",(ulong *)(param_1 + 0xbc),200);
  SetDefaultParameter(param_1,(ushort *)L"EnableMbar1Control",(ulong *)(param_1 + 0xc0),0);
  SetDefaultParameter(param_1,(ushort *)L"MonitorOffD0EntryDelay",(ulong *)(param_1 + 0xc4),0);
  SetDefaultParameter(param_1,(ushort *)L"CombinedWriteRead[0]",(ulong *)(param_1 + 200),1);
  SetDefaultParameter(param_1,(ushort *)L"CombinedWriteWrite[0]",(ulong *)(param_1 + 0x10c8),1);
  SetDefaultParameter(param_1,(ushort *)L"CombinedReadWrite[0]",(ulong *)(param_1 + 0x20c8),1);
  SetDefaultParameter(param_1,(ushort *)&u_CombinedReadRead_0_,(ulong *)(param_1 + 0x30c8),1);
  SetDefaultParameter(param_1,(ushort *)L"ForceDma[0]",(ulong *)(param_1 + 0x40c8),0x10);
  SetDefaultParameter(param_1,(ushort *)L"CancelTimeoutUs[0]",(ulong *)(param_1 + 0x50c8),10000);
  SetDefaultParameter(param_1,(ushort *)L"ByteTimeUs[0]",(ulong *)(param_1 + 0x60c8),0);
  lVar3 = 0x3ff;
  pPVar2 = param_1 + 0x10cc;
  do {
    *(ulong *)(pPVar2 + -0x1000) = *(ulong *)(param_1 + 200);
    *(ulong *)pPVar2 = *(ulong *)(param_1 + 0x10c8);
    *(ulong *)(pPVar2 + 0x1000) = *(ulong *)(param_1 + 0x20c8);
    *(ulong *)(pPVar2 + 0x2000) = *(ulong *)(param_1 + 0x30c8);
    *(ulong *)(pPVar2 + 0x3000) = *(ulong *)(param_1 + 0x40c8);
    *(ulong *)(pPVar2 + 0x4000) = *(ulong *)(param_1 + 0x50c8);
    *(ulong *)(pPVar2 + 0x5000) = *(ulong *)(param_1 + 0x60c8);
    lVar3 = lVar3 + -1;
    pPVar2 = pPVar2 + 4;
  } while (lVar3 != 0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar4);
  }
  return;
}



===== GetRegistrySettings @ 14000c318 =====

/* void __cdecl GetRegistrySettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetRegistrySettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  WDFKEY__ *local_res8;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
  }
  iVar2 = (*DAT_140019698)(WdfDriverGlobals,*WdfDriverGlobals,0x1f0000,0,&local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3,(char)iVar2);
    }
  }
  else {
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x70));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x74));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x78));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0x7c));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x80));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x84));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x88));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0x8c));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 0x90));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0x94));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SDA_HoldCnt",(ulong *)(param_1 + 0x98));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0x9c));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0xa8));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xac));
    ReadRegistryKeyForController(param_1,local_res8,(ushort *)L"DmaError",(ulong *)(param_1 + 0xb0))
    ;
    ReadRegistryKeyForController(param_1,local_res8,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xb4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"MonitorOnIdleTimeout",(ulong *)(param_1 + 0xb8));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"MonitorOffIdleTimeout",(ulong *)(param_1 + 0xbc));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"MonitorOffD0EntryDelay",(ulong *)(param_1 + 0xc4));
    (*DAT_140019a18)(WdfDriverGlobals,local_res8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
  }
  return;
}



===== OverrideDefaultsForHardware @ 14000c6a8 =====

/* void __cdecl OverrideDefaultsForHardware(struct PBC_DEVICE * __ptr64) */

void __cdecl OverrideDefaultsForHardware(PBC_DEVICE *param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  uint uVar3;
  PBC_DEVICE *pPVar4;
  ulong uVar5;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 & 0x800) != 0 && (uVar3 == 0)) ||
          ((((uVar1 & 0x1000) != 0 && (uVar3 == 1)) || (1 < uVar3)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
      }
      pPVar4 = param_1 + 0xb4;
      uVar5 = 0;
      pwVar2 = L"DmaInit";
    }
    else {
      if (*(int *)(param_1 + 0x2c) != 0xf2) goto LAB_14000c9b0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
         ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
          (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
           (1 < uVar3)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
      }
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x70),
                          0xdb);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x74),
                          0xfe);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x78),9
                         );
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0x7c),1);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0x80),0x20)
      ;
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0x84),0x42);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0x88),9);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0x8c),3);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 0x90),
                          0xc);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0x94),
                          0x16);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_HoldCnt",(ulong *)(param_1 + 0x98),5
                         );
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0x9c),3);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),0xc);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),0x16);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_HoldCnt",(ulong *)(param_1 + 0xa8),1);
      pPVar4 = param_1 + 0xac;
      uVar5 = 1;
      pwVar2 = L"HighSpeed_SPK_Cnt";
    }
    SetDefaultParameter(param_1,(ushort *)pwVar2,(ulong *)pPVar4,uVar5);
  }
LAB_14000c9b0:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar3 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar3 == 1)))) ||
      (1 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3);
  }
  return;
}



===== ReadRegistryKeyForController @ 14000ca10 =====

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
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  local_258 = local_248;
  local_268[0] = 0;
  local_260[0] = 0x2000000;
  iVar2 = RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)local_260,(ushort *)&u__ws__u,param_3,
                     (ulonglong)*(uint *)(param_1 + 0x24));
  if (iVar2 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || (1 < uVar3)))) {
      WPP_SF_dSd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3,(short *)param_3,(char)iVar2
                );
    }
  }
  else {
    iVar2 = (*DAT_140019a60)(WdfDriverGlobals,param_2,local_260,local_268);
  }
  if (-1 < iVar2) {
    *param_4 = local_268[0];
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || (1 < uVar3)))) {
      WPP_SF_dSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar3,(short *)param_3,
                  (char)local_268[0],(char)local_268[0]);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 14000cb80 =====

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
  _Dest = (wchar_t *)0x0;
  _Count = 0;
  lVar5 = 0;
  if ((((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 2), (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((*(wchar_t **)(param_1 + 8) != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (size_t)(uVar2 >> 1);
    _Dest = *(wchar_t **)(param_1 + 8);
  }
  else {
    lVar5 = -0x3ffffff3;
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
  return lVar5;
}



===== SetDefaultParameter @ 14000cc24 =====

/* void __cdecl SetDefaultParameter(struct PBC_DEVICE * __ptr64,unsigned short * __ptr64,unsigned
   long * __ptr64,unsigned long) */

void __cdecl SetDefaultParameter(PBC_DEVICE *param_1,ushort *param_2,ulong *param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x24);
  }
  *param_3 = param_4;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_dSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_64ec75d3c22f2ff658abe815f45391b3_Traceguids,uVar2,(short *)param_2,
                (char)param_4,(char)param_4);
  }
  return;
}



===== WPP_SF_dSd @ 14000cca8 =====

void WPP_SF_dSd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               short *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
  if (param_5 == (short *)0x0) {
    lVar1 = 10;
  }
  else if (*param_5 == 0) {
    lVar1 = 0xe;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (short *)0x0) {
    param_5 = (short *)&u_NULL;
  }
  else if (*param_5 == 0) {
    param_5 = (short *)&u_<NULL>;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,lVar1,&param_6,4,0);
  return;
}



===== WPP_SF_dSdD @ 14000cd58 =====

void WPP_SF_dSdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                short *param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
  if (param_5 == (short *)0x0) {
    lVar1 = 10;
  }
  else if (*param_5 == 0) {
    lVar1 = 0xe;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (short *)0x0) {
    param_5 = (short *)&u_NULL;
  }
  else if (*param_5 == 0) {
    param_5 = (short *)&u_<NULL>;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,param_5,lVar1,&param_6,4,&param_7,4,0);
  return;
}



===== ControllerCompleteDmaTransaction @ 14000ce1c =====

/* long __cdecl ControllerCompleteDmaTransaction(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long) */

long __cdecl
ControllerCompleteDmaTransaction(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  bool bVar10;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
  }
  if (param_1[0x71d0] == (PBC_DEVICE)0x0) goto LAB_14000d2f2;
  if ((param_3 & 1) != 0) {
    (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x7220));
    lVar3 = *(longlong *)(param_1 + 8);
    uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x88));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x88),uVar5 & 0xfffffffd);
    uVar6 = *(uint *)(param_1 + 0x722c);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x722c);
      bVar10 = uVar6 == uVar1;
      if (bVar10) {
        *(uint *)(param_1 + 0x722c) = uVar6 | 1;
      }
      else {
        uVar6 = uVar1;
      }
      UNLOCK();
    } while (!bVar10);
    if (uVar6 == 0) {
      iVar7 = *(int *)(param_2 + 100);
      do {
        LOCK();
        iVar2 = *(int *)(param_2 + 100);
        bVar10 = iVar7 == iVar2;
        if (bVar10) {
          *(int *)(param_2 + 100) = iVar7;
        }
        else {
          iVar7 = iVar2;
        }
        UNLOCK();
      } while (!bVar10);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 8 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
          ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9,(char)iVar7);
      }
      if ((iVar7 == 0) ||
         (cVar4 = (*DAT_140019fd0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0)),
         cVar4 != '\x01')) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)))) || (1 < uVar9)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                   &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
        }
        (*DAT_14001a030)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0));
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 8 & 1) != 0 &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
              ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        uVar8 = 0x1e;
        goto LAB_14000d0a9;
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 8 & 1) != 0)) &&
            ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
             (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)))) || (1 < uVar9)))))) {
      uVar8 = 0x20;
LAB_14000d0a9:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
    }
    (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x7220));
  }
  if (((param_3 & 2) == 0) || (*(int *)(param_2 + 0x44) != 1)) goto LAB_14000d2f2;
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x7218));
  lVar3 = *(longlong *)(param_1 + 8);
  uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 0x88));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 0x88),uVar5 & 0xfffffffe);
  uVar6 = *(uint *)(param_1 + 0x7228);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x7228);
    bVar10 = uVar6 == uVar1;
    if (bVar10) {
      *(uint *)(param_1 + 0x7228) = uVar6 | 1;
    }
    else {
      uVar6 = uVar1;
    }
    UNLOCK();
  } while (!bVar10);
  if (uVar6 == 0) {
    iVar7 = *(int *)(param_2 + 0x68);
    do {
      LOCK();
      iVar2 = *(int *)(param_2 + 0x68);
      bVar10 = iVar7 == iVar2;
      if (bVar10) {
        *(int *)(param_2 + 0x68) = iVar7;
      }
      else {
        iVar7 = iVar2;
      }
      UNLOCK();
    } while (!bVar10);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 0x100) != 0)) &&
       ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || (1 < uVar9)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9,(char)iVar7);
    }
    if ((iVar7 == 0) ||
       (cVar4 = (*DAT_140019fd0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8)),
       cVar4 != '\x01')) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 0x100) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
          ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
      }
      (*DAT_14001a030)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8));
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 0x100) != 0 &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
            ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
      uVar8 = 0x22;
      goto LAB_14000d2c4;
    }
  }
  else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 8 & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
          (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)))) || (1 < uVar9)))) {
    uVar8 = 0x24;
LAB_14000d2c4:
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
  }
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x7218));
LAB_14000d2f2:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
      ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
  }
  return 0;
}



===== ControllerDestroyMdlForDma @ 14000d35c =====

/* void __cdecl ControllerDestroyMdlForDma(struct _MDL * __ptr64 * __ptr64) */

void __cdecl ControllerDestroyMdlForDma(_MDL **param_1)

{
  _MDL *p_Var1;
  
  if (param_1 != (_MDL **)0x0) {
    p_Var1 = *param_1;
    while (p_Var1 != (_MDL *)0x0) {
      *param_1 = *(_MDL **)p_Var1;
      IoFreeMdl();
      p_Var1 = *param_1;
    }
  }
  return;
}



===== ControllerDmaEventProcessing @ 14000d388 =====

/* unsigned char __cdecl ControllerDmaEventProcessing(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST
   * __ptr64) */

uchar __cdecl ControllerDmaEventProcessing(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined1 uVar7;
  ulong uVar8;
  undefined2 uVar9;
  uint uVar10;
  longlong lVar11;
  uchar uVar12;
  
  uVar10 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar10 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
  }
  uVar1 = *(uint *)(param_1 + 0x71f8);
  uVar12 = '\0';
  bVar6 = false;
  bVar4 = false;
  if (((uVar1 & 0x10000) == 0) || (*(int *)(param_2 + 0x44) != 2)) goto LAB_14000d583;
  bVar5 = true;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0 &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
     ((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
    WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
               &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,
               (char)*(undefined4 *)(param_1 + 0x7208),(char)*(undefined8 *)(param_1 + 0x7210));
  }
  if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
    uVar7 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
    Template_zpxqx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_END,0,
                   (undefined1 *)L"SpbTransferDirectionToDevice",(char)*(undefined8 *)param_1,uVar7,
                   (char)*(undefined4 *)(param_1 + 0x7208),(char)*(undefined8 *)(param_1 + 0x7210));
  }
  iVar3 = *(int *)(param_1 + 0x7208);
  if (iVar3 == 1) {
    if (*(int *)(param_1 + 0x6c) == 0) {
      lVar11 = *(longlong *)(param_1 + 0x7210);
      *(longlong *)(param_2 + 0x50) = lVar11;
      lVar11 = *(longlong *)(param_2 + 0x28) - lVar11;
      if (lVar11 == 0) {
        if (param_2[0x62] == (PBC_REQUEST)0x0) {
          (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
          ControllerDisableInterrupts(param_1);
          if (((*(int *)(param_1 + 0x28) != 0) ||
              ((*(int *)(param_1 + 0x2c) != 0xf2 && (0xed < *(int *)(param_1 + 0x2c) - 2U)))) &&
             (*(int *)(param_1 + 0x28) != 1)) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                 (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                       &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
            }
            goto LAB_14000d8e2;
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                     &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
          }
          lVar11 = *(longlong *)(param_1 + 8);
          uVar8 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar11 + 0x808));
          HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar11 + 0x808),uVar8 | 0x10);
          LOCK();
          *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffef;
          UNLOCK();
          LOCK();
          *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100000;
          UNLOCK();
          goto LAB_14000d8e7;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
          uVar9 = 0x3b;
          goto LAB_14000d866;
        }
      }
      else {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
          WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                    &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)lVar11);
        }
        LOCK();
        *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
        UNLOCK();
        LOCK();
        *(undefined4 *)(param_1 + 0x40) = 0;
        UNLOCK();
      }
    }
    goto LAB_14000dcc6;
  }
  if ((iVar3 != 2) && (iVar3 != 4)) {
    if (iVar3 != 8) {
      bVar4 = true;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), bVar4 = bVar5, (uVar2 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
      }
      goto LAB_14000d583;
    }
    if (*(int *)(param_1 + 0x6c) == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
      }
      (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
      ControllerDisableInterrupts(param_1);
LAB_14000d8e2:
      LOCK();
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10;
      UNLOCK();
LAB_14000d8e7:
      (*DAT_140019768)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
         ((((uVar1 >> 0xb & 1) == 0 || (uVar10 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar10 != 1)) && (uVar10 < 2)))))) goto LAB_14000dcc6;
      uVar9 = 0x3f;
LAB_14000d866:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
               &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
    }
    goto LAB_14000dcc6;
  }
  LOCK();
  *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
  *(undefined4 *)(param_1 + 0x7188) = 0;
  bVar4 = bVar5;
LAB_14000d583:
  if (((uVar1 >> 0x11 & 1) == 0) || (*(int *)(param_2 + 0x44) != 1)) {
LAB_14000d6d4:
    if (((uVar1 & 0x10000) == 0) || (*(int *)(param_2 + 0x44) != 1)) goto LAB_14000dbc6;
    bVar4 = true;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,
                 (char)*(undefined4 *)(param_1 + 0x7208),(char)*(undefined8 *)(param_1 + 0x7210));
    }
    if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
      uVar7 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
      Template_zpxqx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_END,0,(undefined1 *)L"TX for RX DMA",
                     (char)*(undefined8 *)param_1,uVar7,(char)*(undefined4 *)(param_1 + 0x7208),
                     (char)*(undefined8 *)(param_1 + 0x7210));
    }
    iVar3 = *(int *)(param_1 + 0x7208);
    if (iVar3 != 1) {
      if ((iVar3 == 2) || (iVar3 == 4)) {
        LOCK();
        *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
        UNLOCK();
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        *(undefined4 *)(param_1 + 0x7188) = 0;
        goto LAB_14000dbc6;
      }
      if ((((iVar3 != 8) &&
           (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
            (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)))) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        uVar9 = 0x48;
        goto LAB_14000d866;
      }
    }
  }
  else {
    bVar6 = true;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,
                 (char)*(undefined4 *)(param_1 + 0x71fc),(char)*(undefined8 *)(param_1 + 0x7200));
    }
    if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
      uVar7 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
      Template_zpxqx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_END,0,
                     (undefined1 *)L"SpbTransferDirectionFromDevice",(char)*(undefined8 *)param_1,
                     uVar7,(char)*(undefined4 *)(param_1 + 0x71fc),
                     (char)*(undefined8 *)(param_1 + 0x7200));
    }
    iVar3 = *(int *)(param_1 + 0x71fc);
    if (iVar3 != 1) {
      if ((iVar3 == 2) || (iVar3 == 4)) {
        LOCK();
        *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
        UNLOCK();
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        *(undefined4 *)(param_1 + 0x7188) = 0;
      }
      else if ((((iVar3 != 8) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
               ((uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0 &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
              (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
      }
      goto LAB_14000d6d4;
    }
    lVar11 = *(longlong *)(param_1 + 0x7200);
    *(longlong *)(param_2 + 0x50) = lVar11;
    lVar11 = *(longlong *)(param_2 + 0x28) - lVar11;
    if (lVar11 == 0) {
      if (param_2[0x62] == (PBC_REQUEST)0x0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                   &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
        }
        uVar12 = '\x01';
      }
      else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
              ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                  &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)lVar11);
      }
      LOCK();
      *(uint *)(param_1 + 0x7174) = *(uint *)(param_1 + 0x7174) | 1;
      UNLOCK();
      LOCK();
      *(undefined4 *)(param_1 + 0x40) = 0;
      UNLOCK();
    }
LAB_14000dbc6:
    if (!bVar4) goto LAB_14000dcd8;
  }
LAB_14000dcc6:
  LOCK();
  *(uint *)(param_1 + 0x71f8) = *(uint *)(param_1 + 0x71f8) & 0xfffeffff;
  UNLOCK();
LAB_14000dcd8:
  if (bVar6) {
    LOCK();
    *(uint *)(param_1 + 0x71f8) = *(uint *)(param_1 + 0x71f8) & 0xfffdffff;
    UNLOCK();
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
  }
  return uVar12;
}



===== ControllerExecuteDmaTransaction @ 14000dd58 =====

/* long __cdecl ControllerExecuteDmaTransaction(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ControllerExecuteDmaTransaction(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  __uint64 _Var4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined2 uVar9;
  uint uVar10;
  ulong local_res8 [2];
  __uint64 local_res10;
  _MDL *local_res18;
  undefined8 *local_res20;
  undefined1 uVar11;
  undefined1 uVar12;
  
  uVar10 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar10 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
  }
  *(undefined8 *)(param_1 + 0x71e0) = 0;
  *(undefined8 *)(param_1 + 0x71b0) = 0;
  iVar6 = 0;
  *(undefined8 *)(param_1 + 0x71b8) = 0;
  local_res18 = (_MDL *)0x0;
  local_res8[0] = 0;
  local_res10 = 0;
  local_res20 = (undefined8 *)
                (*DAT_140019930)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                                 PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
  puVar8 = (undefined8 *)
           (*DAT_140019930)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),
                            PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
  LOCK();
  *(undefined4 *)(param_1 + 0x722c) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x7228) = 0;
  UNLOCK();
  if (*(int *)(param_2 + 0x44) == 2) {
    iVar6 = ControllerPrepareMdlForDmaTx(param_1,param_2,&local_res18,local_res8,&local_res10);
    _Var4 = local_res10;
    uVar3 = local_res8[0];
    if (iVar6 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        uVar9 = 0xd;
LAB_14000e205:
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
      }
    }
    else {
      uVar12 = (undefined1)local_res10;
      uVar11 = (undefined1)local_res8[0];
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,uVar11,uVar12);
      }
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        uVar5 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
        Template_zxxpx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_START,0,
                       (undefined1 *)L"SpbTransferDirectionToDevice",uVar11,uVar12,
                       (char)*(undefined8 *)param_1,uVar5);
      }
      param_1[0x71c0] = (PBC_DEVICE)0x0;
      *(_MDL **)(param_1 + 0x71b0) = local_res18;
      iVar6 = (*DAT_1400195f8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),ProgramDmaCallback
                               ,1,local_res18,
                               (ulonglong)*(uint *)(local_res18 + 0x2c) +
                               *(longlong *)(local_res18 + 0x20),_Var4);
      puVar8 = local_res20;
      if (iVar6 < 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
          uVar9 = 0xf;
LAB_14000e023:
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                    &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)iVar6);
        }
      }
      else {
        uVar2 = *(undefined8 *)(param_1 + 0x71b0);
        param_1[0x71c0] = (PBC_DEVICE)0x1;
        *(ulong *)(local_res20 + 4) = uVar3;
        local_res20[5] = _Var4;
        local_res20[3] = uVar2;
        *local_res20 = param_1;
        local_res20[1] = param_2;
        local_res20[6] = 0;
        (*DAT_140019fc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),0x10);
        (*DAT_140019fa0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),I2CEvtConfigureChannel,0
                        );
        (*DAT_140019fa8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                         I2CEvtDmaTransferCompleteTx,0);
        HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x8c),0);
        HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x90),0);
        HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),2);
        *(undefined8 *)(param_1 + 0x7210) = 0;
        *(undefined4 *)(param_1 + 0x7208) = 0;
        *(undefined4 *)(param_1 + 0x71f8) = 0;
        LOCK();
        *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) | 1;
        UNLOCK();
        iVar6 = (*DAT_140019608)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),puVar8);
        if (-1 < iVar6) goto LAB_14000e8bb;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
          uVar9 = 0x10;
          goto LAB_14000e023;
        }
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x44) != 1) goto LAB_14000e8bb;
    iVar6 = ControllerPrepareMdlForDmaRx(param_1,param_2,&local_res18,local_res8,&local_res10);
    _Var4 = local_res10;
    uVar3 = local_res8[0];
    if (iVar6 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
        uVar9 = 0x11;
        goto LAB_14000e205;
      }
    }
    else {
      uVar12 = (undefined1)local_res10;
      uVar11 = (undefined1)local_res8[0];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
         ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
          (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))))) {
        WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,uVar11,uVar12);
      }
      if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
        uVar5 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
        Template_zxxpx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_START,0,
                       (undefined1 *)L"SpbTransferDirectionFromDevice",uVar11,uVar12,
                       (char)*(undefined8 *)param_1,uVar5);
      }
      param_1[0x71c1] = (PBC_DEVICE)0x0;
      *(_MDL **)(param_1 + 0x71b8) = local_res18;
      iVar6 = (*DAT_1400195f8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),ProgramDmaCallback
                               ,0,local_res18,
                               (ulonglong)*(uint *)(local_res18 + 0x2c) +
                               *(longlong *)(local_res18 + 0x20),_Var4);
      if (iVar6 < 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
          uVar9 = 0x13;
          goto LAB_14000e023;
        }
      }
      else {
        uVar2 = *(undefined8 *)(param_1 + 0x71b8);
        param_1[0x71c1] = (PBC_DEVICE)0x1;
        puVar8[6] = 0;
        puVar8[3] = uVar2;
        *(ulong *)(puVar8 + 4) = uVar3;
        puVar8[5] = _Var4;
        *puVar8 = param_1;
        puVar8[1] = param_2;
        (*DAT_140019fc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),0x10);
        (*DAT_140019fa0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),I2CEvtConfigureChannel,0
                        );
        (*DAT_140019fa8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),
                         I2CEvtDmaTransferCompleteRx,0);
        iVar6 = ControllerPrepareMdlForDmaTxForRx
                          (param_1,param_2,&local_res18,local_res8,&local_res10);
        _Var4 = local_res10;
        uVar3 = local_res8[0];
        if (iVar6 < 0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                     &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
          }
        }
        else {
          uVar12 = (undefined1)local_res10;
          uVar11 = (undefined1)local_res8[0];
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
            WPP_SF_ddP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                       &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,uVar11,uVar12);
          }
          if ((Intel_IALPSS_I2CEnableBits & 1) != 0) {
            uVar5 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 8));
            Template_zxxpx(Intel_IALPSS_I2CHandle,&EVENT_I2C_DMA_TXN_START,0,
                           (undefined1 *)L"TX for RX DMA",uVar11,uVar12,(char)*(undefined8 *)param_1
                           ,uVar5);
          }
          param_1[0x71c0] = (PBC_DEVICE)0x0;
          *(_MDL **)(param_1 + 0x71b0) = local_res18;
          iVar6 = (*DAT_1400195f8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                                   ProgramDmaCallback,1,local_res18,
                                   (ulonglong)*(uint *)(local_res18 + 0x2c) +
                                   *(longlong *)(local_res18 + 0x20),_Var4);
          if (iVar6 < 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
              uVar9 = 0x16;
              goto LAB_14000e023;
            }
          }
          else {
            uVar2 = *(undefined8 *)(param_1 + 0x71b0);
            param_1[0x71c0] = (PBC_DEVICE)0x1;
            *(ulong *)(local_res20 + 4) = uVar3;
            local_res20[3] = uVar2;
            local_res20[5] = _Var4;
            *local_res20 = param_1;
            local_res20[1] = param_2;
            local_res20[6] = 0;
            (*DAT_140019fc0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),0x10);
            (*DAT_140019fa0)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                             I2CEvtConfigureChannel,0);
            (*DAT_140019fa8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                             I2CEvtDmaTransferCompleteTx,0);
            HWREG<unsigned_long>::Write
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x8c),0);
            HWREG<unsigned_long>::Write
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x90),0);
            HWREG<unsigned_long>::Write
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x88),3);
            *(undefined8 *)(param_1 + 0x7200) = 0;
            *(undefined8 *)(param_1 + 0x71f8) = 0;
            *(undefined8 *)(param_1 + 0x7210) = 0;
            *(undefined4 *)(param_1 + 0x7208) = 0;
            LOCK();
            *(uint *)(param_2 + 0x68) = *(uint *)(param_2 + 0x68) | 1;
            UNLOCK();
            iVar6 = (*DAT_140019608)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8),puVar8);
            if (iVar6 < 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                  ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
                uVar9 = 0x17;
                goto LAB_14000e023;
              }
            }
            else {
              LOCK();
              *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) | 1;
              UNLOCK();
              iVar6 = (*DAT_140019608)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0),
                                       local_res20);
              if (-1 < iVar6) goto LAB_14000e8bb;
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                   (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
                WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                          &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)iVar6);
              }
              ControllerCompleteDmaTransaction(param_1,param_2,2);
            }
          }
        }
      }
    }
  }
  if (param_1[0x71c0] != (PBC_DEVICE)0x0) {
    iVar7 = (*DAT_140019610)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a0));
    if ((((iVar7 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0 &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)iVar7);
    }
    param_1[0x71c0] = (PBC_DEVICE)0x0;
  }
  if (param_1[0x71c1] != (PBC_DEVICE)0x0) {
    iVar7 = (*DAT_140019610)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x71a8));
    if (((((iVar7 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10,(char)iVar7);
    }
    param_1[0x71c1] = (PBC_DEVICE)0x0;
  }
  ControllerDestroyMdlForDma((_MDL **)(param_1 + 0x71b0));
  ControllerDestroyMdlForDma((_MDL **)(param_1 + 0x71b8));
LAB_14000e8bb:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || (1 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar10);
  }
  return iVar6;
}



===== ControllerPrepareMdlForDmaRx @ 14000e924 =====

/* long __cdecl ControllerPrepareMdlForDmaRx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaRx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  _MDL *p_Var4;
  uint uVar5;
  _MDL *p_Var6;
  undefined8 *puVar7;
  _MDL *p_Var8;
  long lVar9;
  _MDL *local_res8;
  _MDL *in_stack_ffffffffffffffb8;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar5);
  }
  puVar7 = *(undefined8 **)(param_2 + 0x30);
  p_Var6 = (_MDL *)0x0;
  lVar9 = 0;
  local_res8 = (_MDL *)0x0;
  p_Var8 = (_MDL *)0x0;
  do {
    if (puVar7 == (undefined8 *)0x0) {
      *param_5 = 0;
      *param_4 = 0;
      p_Var8 = p_Var6;
      if (p_Var6 == (_MDL *)0x0) {
        lVar9 = -0x3fffffff;
      }
      else {
        do {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
             ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
              (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
                (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) || (1 < uVar5)))))) {
            if (((byte)p_Var8[10] & 5) == 0) {
              uVar2 = MmMapLockedPagesSpecifyCache
                                (p_Var8,0,1,0,
                                 (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x10);
            }
            else {
              uVar2 = (undefined1)*(longlong *)(p_Var8 + 0x18);
            }
            in_stack_ffffffffffffffb8 = p_Var8;
            WPP_SF_dPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                        &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar5,(char)p_Var8,uVar2,
                        (char)*(undefined4 *)(p_Var8 + 0x28));
          }
          *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var8 + 0x28);
          *param_4 = *param_4 + 1;
          p_Var8 = *(_MDL **)p_Var8;
        } while (p_Var8 != (_MDL *)0x0);
      }
LAB_14000eb82:
      *param_3 = p_Var6;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))
           ) || (1 < uVar5)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar5);
      }
      return lVar9;
    }
    if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
      uVar3 = MmMapLockedPagesSpecifyCache
                        (puVar7,0,1,0,(ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x10
                        );
    }
    else {
      uVar3 = puVar7[3];
    }
    in_stack_ffffffffffffffb8 = (_MDL *)0x0;
    p_Var4 = (_MDL *)IoAllocateMdl(uVar3,*(undefined4 *)(puVar7 + 5),0,0,0);
    if (p_Var4 == (_MDL *)0x0) {
      lVar9 = -0x3fffffff;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar5);
      }
      ControllerDestroyMdlForDma(&local_res8);
      p_Var6 = local_res8;
      goto LAB_14000eb82;
    }
    MmBuildMdlForNonPagedPool(p_Var4);
    if (p_Var6 == (_MDL *)0x0) {
      p_Var6 = p_Var4;
      local_res8 = p_Var4;
    }
    else {
      *(_MDL **)p_Var8 = p_Var4;
    }
    puVar7 = (undefined8 *)*puVar7;
    p_Var8 = p_Var4;
  } while( true );
}



===== ControllerPrepareMdlForDmaTx @ 14000ebf4 =====

/* long __cdecl ControllerPrepareMdlForDmaTx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaTx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  _MDL *p_Var4;
  longlong lVar5;
  _MDL *p_Var6;
  undefined8 *puVar7;
  undefined2 uVar8;
  uint uVar9;
  long lVar10;
  ulonglong uVar11;
  longlong *plVar12;
  _MDL *p_Var13;
  _MDL *local_res8;
  _MDL *in_stack_ffffffffffffffb8;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
  }
  puVar7 = *(undefined8 **)(param_2 + 0x30);
  p_Var4 = (_MDL *)0x0;
  uVar11 = 0;
  local_res8 = (_MDL *)0x0;
  lVar10 = -0x3ffffffc;
  if (*(longlong *)(param_2 + 0x28) != 0) {
    for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
      if (uVar11 < *(uint *)(puVar7 + 5)) {
        if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
          in_stack_ffffffffffffffb8 =
               (_MDL *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000);
          lVar5 = MmMapLockedPagesSpecifyCache(puVar7,0,1,0,in_stack_ffffffffffffffb8,0x10);
        }
        else {
          lVar5 = puVar7[3];
        }
        if (lVar5 != 0) {
          lVar10 = 0;
          param_1[0x71e0] = *(PBC_DEVICE *)(lVar5 + uVar11);
        }
        break;
      }
      uVar11 = uVar11 - *(uint *)(puVar7 + 5);
    }
  }
  if (lVar10 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
       ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || (1 < uVar9)))))) {
      uVar8 = 0x2b;
LAB_14000ee14:
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9,(char)lVar10);
    }
LAB_14000f0e6:
    if (-1 < lVar10) {
      if (p_Var4 == (_MDL *)0x0) {
        lVar10 = -0x3fffffff;
      }
      goto LAB_14000f10a;
    }
  }
  else {
    *(uint *)(param_1 + 0x71e0) = *(uint *)(param_1 + 0x71e0) | 0x400;
    puVar7 = *(undefined8 **)(param_2 + 0x30);
    uVar11 = *(ulonglong *)(param_2 + 0x28) - 1;
    lVar10 = -0x3ffffffc;
    if (uVar11 < *(ulonglong *)(param_2 + 0x28)) {
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
        if (uVar11 < *(uint *)(puVar7 + 5)) {
          if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
            in_stack_ffffffffffffffb8 =
                 (_MDL *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000);
            lVar5 = MmMapLockedPagesSpecifyCache(puVar7,0,1,0,in_stack_ffffffffffffffb8,0x10);
          }
          else {
            lVar5 = puVar7[3];
          }
          if (lVar5 != 0) {
            lVar10 = 0;
            param_1[0x71e4] = *(PBC_DEVICE *)(lVar5 + uVar11);
          }
          break;
        }
        uVar11 = uVar11 - *(uint *)(puVar7 + 5);
      }
    }
    if (lVar10 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
          ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        uVar8 = 0x2c;
        goto LAB_14000ee14;
      }
      goto LAB_14000f0e6;
    }
    if (param_2[0x62] != (PBC_REQUEST)0x0) {
      *(uint *)(param_1 + 0x71e4) = *(uint *)(param_1 + 0x71e4) | 0x200;
    }
    plVar12 = *(longlong **)(param_2 + 0x30);
    uVar2 = *(uint *)(plVar12 + 5);
    if (uVar2 < 2) {
LAB_14000ef1f:
      p_Var13 = p_Var4;
LAB_14000efa9:
      plVar12 = (longlong *)*plVar12;
      if (plVar12 != (longlong *)0x0) {
        if (*plVar12 == 0) goto code_r0x00014000ef2d;
        iVar1 = (int)plVar12[5];
        goto LAB_14000ef3d;
      }
      *param_5 = 0;
      *param_4 = 0;
      for (p_Var13 = p_Var4; p_Var13 != (_MDL *)0x0; p_Var13 = *(_MDL **)p_Var13) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar2 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
            (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) &&
           ((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
          if (((byte)p_Var13[10] & 5) == 0) {
            uVar3 = MmMapLockedPagesSpecifyCache
                              (p_Var13,0,1,0,
                               (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x10);
          }
          else {
            uVar3 = (undefined1)*(undefined8 *)(p_Var13 + 0x18);
          }
          in_stack_ffffffffffffffb8 = p_Var13;
          WPP_SF_dPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                      &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9,(char)p_Var13,uVar3,
                      (char)*(undefined4 *)(p_Var13 + 0x28));
        }
        *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var13 + 0x28);
        *param_4 = *param_4 + 1;
      }
      goto LAB_14000f0e6;
    }
    iVar1 = uVar2 - 1;
    if (*plVar12 == 0) {
      iVar1 = uVar2 - 2;
    }
    if ((*(byte *)((longlong)plVar12 + 10) & 5) == 0) {
      lVar5 = MmMapLockedPagesSpecifyCache
                        (plVar12,0,1,0,(ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,
                         0x10);
    }
    else {
      lVar5 = plVar12[3];
    }
    in_stack_ffffffffffffffb8 = (_MDL *)0x0;
    p_Var4 = (_MDL *)IoAllocateMdl(lVar5 + 1,iVar1,0,0,0);
    if (p_Var4 != (_MDL *)0x0) {
      MmBuildMdlForNonPagedPool(p_Var4);
      local_res8 = p_Var4;
      goto LAB_14000ef1f;
    }
    lVar10 = -0x3fffffff;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
        ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
      uVar8 = 0x2d;
LAB_14000eef9:
      lVar10 = -0x3fffffff;
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
    }
  }
LAB_14000f0ea:
  ControllerDestroyMdlForDma(&local_res8);
  p_Var4 = local_res8;
LAB_14000f10a:
  *param_3 = p_Var4;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar9);
  }
  return lVar10;
code_r0x00014000ef2d:
  if (1 < *(uint *)(plVar12 + 5)) {
    iVar1 = *(uint *)(plVar12 + 5) - 1;
LAB_14000ef3d:
    if ((*(byte *)((longlong)plVar12 + 10) & 5) == 0) {
      lVar5 = MmMapLockedPagesSpecifyCache
                        (plVar12,0,1,0,(ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,
                         0x10);
    }
    else {
      lVar5 = plVar12[3];
    }
    in_stack_ffffffffffffffb8 = (_MDL *)0x0;
    p_Var6 = (_MDL *)IoAllocateMdl(lVar5,iVar1,0,0,0);
    if (p_Var6 == (_MDL *)0x0) {
      lVar10 = -0x3fffffff;
      if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar2 >> 0xb & 1) == 0 || (uVar9 != 0)) && (((uVar2 >> 0xc & 1) == 0 || (uVar9 != 1)))
           ) && (uVar9 < 2)))) goto LAB_14000f0ea;
      uVar8 = 0x2e;
      goto LAB_14000eef9;
    }
    MmBuildMdlForNonPagedPool(p_Var6);
    if (p_Var13 == (_MDL *)0x0) {
      p_Var4 = p_Var6;
      local_res8 = p_Var6;
    }
    else {
      *(_MDL **)p_Var13 = p_Var6;
    }
    p_Var13 = p_Var6;
  }
  goto LAB_14000efa9;
}



===== ControllerPrepareMdlForDmaTxForRx @ 14000f17c =====

/* long __cdecl ControllerPrepareMdlForDmaTxForRx(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,struct _MDL * __ptr64 * __ptr64,unsigned long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
ControllerPrepareMdlForDmaTxForRx
          (PBC_DEVICE *param_1,PBC_REQUEST *param_2,_MDL **param_3,ulong *param_4,__uint64 *param_5)

{
  uint uVar1;
  longlong lVar2;
  _MDL *p_Var3;
  _MDL *p_Var4;
  undefined1 uVar5;
  _MDL *p_Var6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  _MDL *p_Var10;
  _MDL *p_Var11;
  long lVar12;
  _MDL *local_res8;
  _MDL *in_stack_ffffffffffffffa8;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar8);
  }
  lVar2 = *(longlong *)(param_2 + 0x28);
  lVar12 = 0;
  *(undefined4 *)(param_1 + 0x71e0) = 0x500;
  local_res8 = (_MDL *)0x0;
  *(uint *)(param_1 + 0x71e4) = (-(uint)(param_2[0x62] != (PBC_REQUEST)0x0) & 0x200) + 0x100;
  uVar9 = lVar2 - 2;
  p_Var11 = (_MDL *)0x0;
  p_Var6 = (_MDL *)0x0;
  p_Var4 = local_res8;
  do {
    local_res8 = p_Var4;
    p_Var3 = p_Var6;
    p_Var10 = p_Var11;
    if (uVar9 == 0) {
      *param_5 = 0;
      *param_4 = 0;
      p_Var11 = p_Var10;
      if (p_Var10 == (_MDL *)0x0) {
        lVar12 = -0x3fffffff;
      }
      else {
        do {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
             ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
              (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
                (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) || (1 < uVar8)))))) {
            if (((byte)p_Var11[10] & 5) == 0) {
              uVar5 = MmMapLockedPagesSpecifyCache
                                (p_Var11,0,1,0,
                                 (ulonglong)in_stack_ffffffffffffffa8 & 0xffffffff00000000,0x10);
            }
            else {
              uVar5 = (undefined1)*(longlong *)(p_Var11 + 0x18);
            }
            in_stack_ffffffffffffffa8 = p_Var11;
            WPP_SF_dPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                        &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar8,(char)p_Var11,uVar5,
                        (char)*(undefined4 *)(p_Var11 + 0x28));
          }
          *param_5 = *param_5 + (ulonglong)*(uint *)(p_Var11 + 0x28);
          *param_4 = *param_4 + 1;
          p_Var11 = *(_MDL **)p_Var11;
        } while (p_Var11 != (_MDL *)0x0);
      }
LAB_14000f3fc:
      *param_3 = p_Var10;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))
           ) || (1 < uVar8)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar8);
      }
      return lVar12;
    }
    uVar7 = (ulonglong)(uint)((int)uVar9 * 2);
    if (0x7fd < uVar9) {
      uVar7 = 0xffa;
    }
    in_stack_ffffffffffffffa8 = (_MDL *)0x0;
    uVar9 = uVar9 - (uVar7 >> 1);
    p_Var6 = (_MDL *)IoAllocateMdl(*(undefined8 *)(param_1 + 0x71c8),uVar7,0,0,0);
    if (p_Var6 == (_MDL *)0x0) {
      lVar12 = -0x3fffffff;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) || (1 < uVar8)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar8);
      }
      ControllerDestroyMdlForDma(&local_res8);
      p_Var10 = local_res8;
      goto LAB_14000f3fc;
    }
    MmBuildMdlForNonPagedPool(p_Var6);
    p_Var11 = p_Var6;
    p_Var4 = p_Var6;
    if (p_Var3 != (_MDL *)0x0) {
      *(_MDL **)p_Var3 = p_Var6;
      p_Var11 = p_Var10;
      p_Var4 = local_res8;
    }
  } while( true );
}



===== IsDmaOp @ 14000f470 =====

/* void __cdecl IsDmaOp(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl IsDmaOp(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar2);
  }
  if (((*(int *)(param_1 + 0x7188) == 2) &&
      (3 < *(uint *)(param_1 +
                    (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x30) + 0xc) * 4 + 0x40c8))) &&
     ((ulonglong)
      *(uint *)(param_1 + (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x30) + 0xc) * 4 + 0x40c8)
      <= *(ulonglong *)(param_2 + 0x28))) {
    param_1[0x71d0] = (PBC_DEVICE)0x1;
  }
  else {
    param_1[0x71d0] = (PBC_DEVICE)0x0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar2);
  }
  return;
}



===== ProgramDmaCallback @ 14000f580 =====

/* unsigned char __cdecl ProgramDmaCallback(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__
   * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
ProgramDmaCallback(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
                  _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  lVar1 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar1 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar1 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar4 = *(uint *)(lVar1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar4 == 0)) || (((uVar2 & 0x1000) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar4);
  }
  *(undefined8 *)((longlong)param_3 + 0x38) = 0;
  if (*(int *)param_5 != 0) {
    lVar1 = 0;
    uVar3 = 0;
    do {
      uVar2 = (int)uVar3 + 1;
      lVar1 = lVar1 + (ulonglong)*(uint *)(param_5 + uVar3 * 0x18 + 0x18);
      *(longlong *)((longlong)param_3 + 0x38) = lVar1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)param_5);
  }
  if (*(int *)((longlong)param_3 + 0x10) == 1) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar2 & 0x800) != 0 && (uVar4 == 0)) ||
        ((((uVar2 & 0x1000) != 0 && (uVar4 == 1)) || (1 < uVar4)))))) {
      WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar4,
                 (char)*(undefined8 *)((longlong)param_3 + 0x38),
                 (char)*(undefined4 *)((longlong)param_3 + 0x40));
    }
    LOCK();
    *(undefined4 *)(*(longlong *)((longlong)param_3 + 8) + 100) = 0;
    UNLOCK();
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
       ((3 < (byte)WPP_GLOBAL_Control[0x29] &&
        (((((uVar2 & 0x800) != 0 && (uVar4 == 0)) || (((uVar2 & 0x1000) != 0 && (uVar4 == 1)))) ||
         (1 < uVar4)))))) {
      WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                 &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar4,
                 (char)*(undefined8 *)((longlong)param_3 + 0x38),
                 (char)*(undefined4 *)((longlong)param_3 + 0x40));
    }
    LOCK();
    *(undefined4 *)(*(longlong *)((longlong)param_3 + 8) + 0x68) = 0;
    UNLOCK();
  }
  *(ulonglong *)((longlong)param_3 + 0x38) =
       *(ulonglong *)((longlong)param_3 + 0x38) / (ulonglong)*(uint *)((longlong)param_3 + 0x40);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar4 == 0)) || (((uVar2 & 0x1000) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_bef2bb132ef3a2acbc92d55b7d3574d9_Traceguids,uVar4);
  }
  return '\x01';
}



===== Template_zpxqx @ 14000f7a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_zpxqx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined1 auStack_98 [32];
  undefined1 **local_78;
  undefined1 *local_68;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if (param_4 == (undefined1 *)0x0) {
    local_60 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
    local_60 = (int)lVar1 * 2 + 2;
  }
  local_68 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    local_68 = param_4;
  }
  local_58 = &param_5;
  local_5c = 0;
  local_48 = &param_6;
  local_50 = 8;
  local_38 = &param_7;
  local_40 = 8;
  local_28 = &param_8;
  local_30 = 4;
  local_78 = &local_68;
  local_20 = 8;
  EtwWrite(param_1,param_2,param_3,5);
  return;
}



===== Template_zxxpx @ 14000f874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Template_zxxpx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined1 auStack_98 [32];
  undefined1 **local_78;
  undefined1 *local_68;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if (param_4 == (undefined1 *)0x0) {
    local_60 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
    local_60 = (int)lVar1 * 2 + 2;
  }
  local_68 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    local_68 = param_4;
  }
  local_58 = &param_5;
  local_5c = 0;
  local_48 = &param_6;
  local_50 = 8;
  local_38 = &param_7;
  local_40 = 8;
  local_28 = &param_8;
  local_30 = 8;
  local_78 = &local_68;
  local_20 = 8;
  EtwWrite(param_1,param_2,param_3,5);
  return;
}



===== WPP_SF_ddP @ 14000f940 =====

void WPP_SF_ddP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_dPPd @ 14000f994 =====

void WPP_SF_dPPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== I2CConfigureSystemProfile @ 14000f9f4 =====

/* long __cdecl I2CConfigureSystemProfile(struct WDFDEVICE__ * __ptr64,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR * __ptr64,enum _WDF_DMA_DIRECTION) */

long __cdecl
I2CConfigureSystemProfile
          (WDFDEVICE__ *param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,_WDF_DMA_DIRECTION param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined8 local_18;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *local_10;
  
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6);
  }
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  uVar2 = *(undefined8 *)(lVar4 + 0x71d8);
  memset(&local_28,0,0x20);
  local_28 = 0x20;
  local_20 = 2;
  local_24 = 1;
  if (param_3 == 1) {
    uVar5 = *(undefined8 *)(lVar4 + 0x7178);
  }
  else {
    uVar5 = *(undefined8 *)(lVar4 + 0x7180);
  }
  local_18 = uVar2;
  local_10 = param_2;
  iVar3 = (*DAT_140019f88)(WdfDriverGlobals,uVar5,&local_28,param_3);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 8 & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6,(char)iVar3);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (1 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6);
  }
  return iVar3;
}



===== I2CCreateDmaTxnObjects @ 14000fbfc =====

/* long __cdecl I2CCreateDmaTxnObjects(struct WDFDEVICE__ * __ptr64) */

long __cdecl I2CCreateDmaTxnObjects(WDFDEVICE__ *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined4 local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_28;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar6 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6);
  }
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  memset(local_58,0,0x38);
  local_58[0] = 0x38;
  local_28 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018;
  local_40 = 1;
  local_3c = 1;
  iVar2 = (*DAT_1400195f0)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x7178),local_58,
                           (undefined8 *)(lVar3 + 0x71a0));
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 8 & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 >> 0xb & 1) == 0 || (uVar6 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)) && (uVar6 < 2)))))) goto LAB_14000fe5c;
    uVar5 = 0x1b;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x71a0),
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
    *(undefined4 *)(lVar4 + 0x10) = 1;
    memset(local_58,0,0x38);
    local_28 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018;
    local_58[0] = 0x38;
    local_40 = 1;
    local_3c = 1;
    iVar2 = (*DAT_1400195f0)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x7180),local_58,
                             lVar3 + 0x71a8);
    if (-1 < iVar2) {
      lVar3 = (*DAT_140019930)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x71a8),
                               PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
      *(undefined4 *)(lVar3 + 0x10) = 0;
      goto LAB_14000fe5c;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 8 & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 >> 0xb & 1) == 0 || (uVar6 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)) && (uVar6 < 2)))))) goto LAB_14000fe5c;
    uVar5 = 0x1c;
  }
  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
            &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6,(char)iVar2);
LAB_14000fe5c:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (1 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar6);
  }
  return iVar2;
}



===== I2CEvtConfigureChannel @ 14000fec4 =====

/* unsigned char __cdecl I2CEvtConfigureChannel(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,struct _MDL * __ptr64,unsigned __int64,unsigned __int64) */

uchar __cdecl
I2CEvtConfigureChannel
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,_MDL *param_4,
          __uint64 param_5,__uint64 param_6)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  int iVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined **ppuVar11;
  int local_res20 [2];
  char *in_stack_ffffffffffffffb8;
  undefined4 local_28 [4];
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar10 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar10 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
  }
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  plVar4 = (longlong *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,
                            PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
  ppuVar11 = (undefined **)WPP_GLOBAL_Control;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    in_stack_ffffffffffffffb8 = "RX";
    if ((int)plVar4[2] == 1) {
      in_stack_ffffffffffffffb8 = "TX";
    }
    WPP_SF_dsqPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,in_stack_ffffffffffffffb8,
                 (char)param_4,(char)param_5,(char)param_6);
    ppuVar11 = (undefined **)WPP_GLOBAL_Control;
  }
  for (; param_4 != (_MDL *)0x0; param_4 = *(_MDL **)param_4) {
    if ((((ppuVar11 != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)((longlong)ppuVar11 + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
        (3 < *(byte *)((longlong)ppuVar11 + 0x29))) &&
       ((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      if (((byte)param_4[10] & 5) == 0) {
        in_stack_ffffffffffffffb8 =
             (char *)MmMapLockedPagesSpecifyCache
                               (param_4,0,1,0,
                                (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x10);
        ppuVar11 = (undefined **)WPP_GLOBAL_Control;
      }
      else {
        in_stack_ffffffffffffffb8 = *(char **)(param_4 + 0x18);
      }
      WPP_SF_dPd(ppuVar11[3],0x20,&WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,
                 (char)in_stack_ffffffffffffffb8,(char)*(undefined4 *)(param_4 + 0x28));
      ppuVar11 = (undefined **)WPP_GLOBAL_Control;
    }
  }
  *(undefined4 *)(plVar4 + 8) = 0;
  if ((int)plVar4[2] == 1) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
    }
    lVar5 = (*DAT_140019ee8)(WdfDriverGlobals,*(undefined8 *)(*plVar4 + 0x7178),1);
    iVar7 = 0;
    uVar9 = param_5 & 0xffffffff;
    plVar6 = (longlong *)plVar4[3];
    if (plVar6 == (longlong *)0x0) {
LAB_1400101a8:
      if (param_5 == 0) {
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(lVar3 + 8) + 0x10),
                   *(ulong *)(lVar3 + 0x71e0));
        *(longlong *)(lVar3 + 0x7210) = *(longlong *)(lVar3 + 0x7210) + 1;
      }
    }
    else {
      do {
        puVar1 = (uint *)(plVar6 + 5);
        if (uVar9 < *puVar1) break;
        plVar6 = (longlong *)*plVar6;
        iVar7 = iVar7 + 1;
        uVar9 = uVar9 - *puVar1;
      } while (plVar6 != (longlong *)0x0);
      if (iVar7 == 0) goto LAB_1400101a8;
    }
    local_res20[0] = (*(int *)(plVar4[1] + 0x44) != 2) + 1;
    *(undefined4 *)(*(longlong *)(*plVar4 + 0x30) + 0x20) = *(undefined4 *)(plVar4[1] + 0x44);
  }
  else {
    if ((int)plVar4[2] != 0) goto LAB_14001037a;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
    }
    lVar5 = (*DAT_140019ee8)(WdfDriverGlobals,*(undefined8 *)(*plVar4 + 0x7180),0);
    local_res20[0] = 1;
  }
  if (lVar5 == 0) goto LAB_14001037a;
  local_28[0] = 0;
  iVar7 = (**(code **)(*(longlong *)(lVar5 + 8) + 0xa8))(lVar5,3,local_28);
  if (iVar7 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\x01';
    }
    uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar2 >> 8 & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar2 >> 0xb & 1) == 0 || (uVar10 != 0)) &&
        ((((uVar2 >> 0xc & 1) == 0 || (uVar10 != 1)) && (uVar10 < 2)))))) goto LAB_14001037a;
    uVar8 = 0x23;
  }
  else {
    iVar7 = (**(code **)(*(longlong *)(lVar5 + 8) + 0xa8))(lVar5,1,local_res20);
    if (-1 < iVar7) {
      *(int *)(plVar4 + 8) = local_res20[0];
      goto LAB_14001037a;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\x01';
    }
    uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar2 >> 8 & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar2 >> 0xb & 1) == 0 || (uVar10 != 0)) &&
        ((((uVar2 >> 0xc & 1) == 0 || (uVar10 != 1)) && (uVar10 < 2)))))) goto LAB_14001037a;
    uVar8 = 0x24;
  }
  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
            &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,(char)iVar7);
LAB_14001037a:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
  }
  return '\x01';
}



===== I2CEvtDmaTransferCompleteRx @ 1400103e0 =====

/* void __cdecl I2CEvtDmaTransferCompleteRx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__
   * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
I2CEvtDmaTransferCompleteRx
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int local_28 [4];
  
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar10 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar10 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
  }
  lVar5 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  local_28[0] = 0;
  plVar6 = (longlong *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,
                            PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7218));
  lVar7 = (*DAT_140019ee8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7180),param_4);
  lVar4 = plVar6[7];
  uVar3 = (**(code **)(*(longlong *)(lVar7 + 8) + 0x50))(lVar7);
  plVar6[6] = plVar6[6] + (lVar4 - (ulonglong)uVar3);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || (1 < uVar10)))) {
    WPP_SF_dPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,(char)lVar4,(char)uVar3,
                (char)param_5);
  }
  if (param_5 == 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
    }
    (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7218));
    cVar2 = (*DAT_140019618)(WdfDriverGlobals,param_1,local_28);
    (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7218));
    if (cVar2 == '\0') goto LAB_140010714;
    LOCK();
    *(uint *)(*plVar6 + 0x7228) = *(uint *)(*plVar6 + 0x7228) | 1;
    UNLOCK();
    if (-1 < local_28[0]) {
      uVar8 = (*DAT_140019630)(WdfDriverGlobals,param_1);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                  &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,(char)uVar8);
      }
      local_28[0] = (*DAT_140019610)(WdfDriverGlobals,param_1);
      if (((((local_28[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)))) || (1 < uVar10)))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                  &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,(char)local_28[0]);
      }
      *(undefined1 *)(lVar5 + 0x71c1) = 0;
      (**(code **)(*(longlong *)(lVar7 + 8) + 0x30))(lVar7);
      ControllerDestroyMdlForDma((_MDL **)(lVar5 + 0x71b8));
      uVar9 = 4;
      if (-1 < local_28[0]) {
        uVar9 = 1;
      }
      *(undefined8 *)(lVar5 + 0x7200) = uVar8;
      *(undefined4 *)(lVar5 + 0x71fc) = uVar9;
      LOCK();
      *(uint *)(lVar5 + 0x71f8) = *(uint *)(lVar5 + 0x71f8) | 0x20000;
      UNLOCK();
      KeSetEvent(*plVar6 + 0x7130,0,0);
      goto LAB_140010714;
    }
LAB_1400105cb:
    LOCK();
    *(uint *)(*plVar6 + 0x7228) = *(uint *)(*plVar6 + 0x7228) | 1;
    UNLOCK();
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
    }
    if (param_5 != 0) {
      (*DAT_140019628)(WdfDriverGlobals,param_1,0,local_28);
    }
    local_28[0] = (*DAT_140019610)(WdfDriverGlobals,param_1);
    if (((((local_28[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10,(char)local_28[0]);
    }
    *(undefined1 *)(lVar5 + 0x71c1) = 0;
    (**(code **)(*(longlong *)(lVar7 + 8) + 0x30))(lVar7);
    ControllerDestroyMdlForDma((_MDL **)(lVar5 + 0x71b8));
    uVar9 = 4;
    if (-1 < local_28[0]) {
      uVar9 = 8;
    }
LAB_1400106e1:
    *(undefined4 *)(lVar5 + 0x71fc) = uVar9;
  }
  else {
    if (param_5 != 1) {
      if (param_5 != 2) {
        if (param_5 != 3) goto LAB_140010714;
        goto LAB_1400105cb;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
      }
      uVar9 = 4;
      goto LAB_1400106e1;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (1 < uVar10)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
    }
    *(undefined4 *)(lVar5 + 0x71fc) = 2;
  }
  *(undefined8 *)(lVar5 + 0x7200) = 0;
  LOCK();
  *(uint *)(lVar5 + 0x71f8) = *(uint *)(lVar5 + 0x71f8) | 0x20000;
  UNLOCK();
  KeSetEvent(*plVar6 + 0x7130,0,0);
LAB_140010714:
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7218));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar3 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((uVar3 >> 0xc & 1) != 0 && (uVar10 == 1)) || (1 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar10);
  }
  return;
}



===== I2CEvtDmaTransferCompleteTx @ 140010a28 =====

/* void __cdecl I2CEvtDmaTransferCompleteTx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__
   * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
I2CEvtDmaTransferCompleteTx
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined4 uVar8;
  uint uVar9;
  int local_28 [4];
  
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar9 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar9 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
  }
  lVar5 = (*DAT_140019930)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  local_28[0] = 0;
  plVar6 = (longlong *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,
                            PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140019018);
  (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7220));
  lVar7 = (*DAT_140019ee8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7178),param_4);
  lVar4 = plVar6[7];
  uVar3 = (**(code **)(*(longlong *)(lVar7 + 8) + 0x50))(lVar7);
  plVar6[6] = plVar6[6] + (lVar4 - (ulonglong)uVar3);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (1 < uVar9)))) {
    WPP_SF_dPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9,(char)lVar4,(char)uVar3,
                (char)param_5);
  }
  if (param_5 == 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
        ((((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
    }
    (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7220));
    cVar2 = (*DAT_140019618)(WdfDriverGlobals,param_1,local_28);
    (*DAT_140019cc0)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7220));
    if (cVar2 == '\0') goto LAB_140010d5c;
    LOCK();
    *(uint *)(*plVar6 + 0x722c) = *(uint *)(*plVar6 + 0x722c) | 1;
    UNLOCK();
    if (-1 < local_28[0]) {
      lVar4 = (*DAT_140019630)(WdfDriverGlobals,param_1);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                  &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9,(char)lVar4);
      }
      local_28[0] = (*DAT_140019610)(WdfDriverGlobals,param_1);
      if (((((local_28[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)))
           ) || (1 < uVar9)))) {
        WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                  &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9,(char)local_28[0]);
      }
      *(undefined1 *)(lVar5 + 0x71c0) = 0;
      (**(code **)(*(longlong *)(lVar7 + 8) + 0x30))(lVar7);
      ControllerDestroyMdlForDma((_MDL **)(lVar5 + 0x71b0));
      *(longlong *)(lVar5 + 0x7210) = *(longlong *)(lVar5 + 0x7210) + lVar4;
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(lVar5 + 8) + 0x10),
                 *(ulong *)(lVar5 + 0x71e4));
      *(longlong *)(lVar5 + 0x7210) = *(longlong *)(lVar5 + 0x7210) + 1;
      uVar8 = 4;
      if (-1 < local_28[0]) {
        uVar8 = 1;
      }
      *(undefined4 *)(lVar5 + 0x7208) = uVar8;
      LOCK();
      *(uint *)(lVar5 + 0x71f8) = *(uint *)(lVar5 + 0x71f8) | 0x10000;
      UNLOCK();
      KeSetEvent(*plVar6 + 0x7118,0,0);
      goto LAB_140010d5c;
    }
LAB_140010c13:
    LOCK();
    *(uint *)(*plVar6 + 0x722c) = *(uint *)(*plVar6 + 0x722c) | 1;
    UNLOCK();
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
        ((((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
    }
    if (param_5 != 0) {
      (*DAT_140019628)(WdfDriverGlobals,param_1,0,local_28);
    }
    local_28[0] = (*DAT_140019610)(WdfDriverGlobals,param_1);
    if (((((local_28[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || (1 < uVar9)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9,(char)local_28[0]);
    }
    *(undefined1 *)(lVar5 + 0x71c0) = 0;
    (**(code **)(*(longlong *)(lVar7 + 8) + 0x30))(lVar7);
    ControllerDestroyMdlForDma((_MDL **)(lVar5 + 0x71b0));
    uVar8 = 4;
    if (-1 < local_28[0]) {
      uVar8 = 8;
    }
LAB_140010d29:
    *(undefined4 *)(lVar5 + 0x7208) = uVar8;
  }
  else {
    if (param_5 != 1) {
      if (param_5 != 2) {
        if (param_5 != 3) goto LAB_140010d5c;
        goto LAB_140010c13;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                 &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
      }
      uVar8 = 4;
      goto LAB_140010d29;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || (1 < uVar9)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
    }
    *(undefined4 *)(lVar5 + 0x7208) = 2;
  }
  *(undefined8 *)(lVar5 + 0x7210) = 0;
  LOCK();
  *(uint *)(lVar5 + 0x71f8) = *(uint *)(lVar5 + 0x71f8) | 0x10000;
  UNLOCK();
  KeSetEvent(*plVar6 + 0x7118,0,0);
LAB_140010d5c:
  (*DAT_140019cc8)(WdfDriverGlobals,*(undefined8 *)(*plVar6 + 0x7220));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
      ((((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1)) || (1 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar9);
  }
  return;
}



===== I2CInitDma @ 14001108c =====

/* long __cdecl I2CInitDma(struct WDFDEVICE__ * __ptr64) */

long __cdecl I2CInitDma(WDFDEVICE__ *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  void *_Dst;
  longlong lVar5;
  undefined2 uVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined4 uVar10;
  undefined4 local_a8 [6];
  undefined4 local_90;
  undefined4 local_8c;
  WDFDEVICE__ *local_88;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_24;
  
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar4 == 0) {
    uVar8 = 0xf0;
  }
  else {
    lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar8 = *(uint *)(lVar4 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 & 0x1000) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8);
  }
  lVar4 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  memset(&local_68,0,0x50);
  local_68 = 0x50;
  local_64 = 7;
  local_60 = 0xffa;
  local_24 = 3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 & 0x1000) != 0 && (uVar8 == 1)))) ||
      (1 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8);
  }
  *(undefined2 *)(lVar4 + 0x71c0) = 0;
  iVar3 = (*DAT_1400195d0)(WdfDriverGlobals,param_1,&local_68,0,(undefined8 *)(lVar4 + 0x7178));
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((uVar2 >> 8 & 1) == 0) {
      return iVar3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar3;
    }
    if ((((uVar2 >> 0xb & 1) == 0) || (uVar8 != 0)) &&
       ((((uVar2 >> 0xc & 1) == 0 || (uVar8 != 1)) && (uVar8 < 2)))) {
      return iVar3;
    }
    uVar6 = 0xc;
  }
  else {
    memset(&local_68,0,0x50);
    local_68 = 0x50;
    local_64 = 7;
    local_60 = 0xffa;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
        || (1 < uVar8)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8);
    }
    puVar1 = (undefined8 *)(lVar4 + 0x7180);
    puVar9 = puVar1;
    iVar3 = (*DAT_1400195d0)(WdfDriverGlobals,param_1,&local_68,0,puVar1);
    uVar10 = (undefined4)((ulonglong)puVar9 >> 0x20);
    if (iVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((uVar2 >> 8 & 1) == 0) {
        return iVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar3;
      }
      if ((((uVar2 >> 0xb & 1) == 0) || (uVar8 != 0)) &&
         ((((uVar2 >> 0xc & 1) == 0 || (uVar8 != 1)) && (uVar8 < 2)))) {
        return iVar3;
      }
      uVar6 = 0xe;
    }
    else {
      memset(local_a8,0,0x38);
      local_a8[0] = 0x38;
      local_90 = 1;
      local_8c = 1;
      local_88 = param_1;
      iVar3 = (*DAT_140019cb8)(WdfDriverGlobals,local_a8,lVar4 + 0x7218);
      if (iVar3 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((uVar2 >> 8 & 1) == 0) {
          return iVar3;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar3;
        }
        if ((((uVar2 >> 0xb & 1) == 0) || (uVar8 != 0)) &&
           ((((uVar2 >> 0xc & 1) == 0 || (uVar8 != 1)) && (uVar8 < 2)))) {
          return iVar3;
        }
        uVar6 = 0xf;
      }
      else {
        memset(local_a8,0,0x38);
        local_a8[0] = 0x38;
        local_90 = 1;
        local_8c = 1;
        local_88 = param_1;
        iVar3 = (*DAT_140019cb8)(WdfDriverGlobals,local_a8,lVar4 + 0x7220);
        if (-1 < iVar3) {
          (*DAT_1400195e8)(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x7178),1);
          (*DAT_1400195e8)(WdfDriverGlobals,*puVar1,1);
          _Dst = (void *)MmAllocateContiguousMemorySpecifyCache
                                   (0xffa,0,0xffffffff,0,CONCAT44(uVar10,1));
          *(void **)(lVar4 + 0x71c8) = _Dst;
          if (_Dst == (void *)0x0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 8 & 1) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
                 (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) || (1 < uVar8)))) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                       &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8);
            }
            iVar3 = -0x3fffffff;
          }
          else {
            memset(_Dst,0,0xffa);
            lVar5 = 1;
            lVar7 = 0x7fd;
            do {
              *(undefined1 *)(lVar5 + *(longlong *)(lVar4 + 0x71c8)) = 1;
              lVar5 = lVar5 + 2;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar3;
          }
          uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
          if ((uVar2 >> 10 & 1) == 0) {
            return iVar3;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
            return iVar3;
          }
          if (((((uVar2 >> 0xb & 1) == 0) || (uVar8 != 0)) &&
              (((uVar2 >> 0xc & 1) == 0 || (uVar8 != 1)))) && (uVar8 < 2)) {
            return iVar3;
          }
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8);
          return iVar3;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((uVar2 >> 8 & 1) == 0) {
          return iVar3;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar3;
        }
        if (((((uVar2 >> 0xb & 1) == 0) || (uVar8 != 0)) &&
            (((uVar2 >> 0xc & 1) == 0 || (uVar8 != 1)))) && (uVar8 < 2)) {
          return iVar3;
        }
        uVar6 = 0x10;
      }
    }
  }
  WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar8,(char)iVar3);
  return iVar3;
}



===== I2CReleaseDma @ 1400115f8 =====

/* long __cdecl I2CReleaseDma(struct WDFDEVICE__ * __ptr64) */

long __cdecl I2CReleaseDma(WDFDEVICE__ *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  byte in_CR8;
  
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
    uVar5 = *(uint *)(lVar3 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar5);
  }
  lVar3 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  if (in_CR8 < 2) {
    in_CR8 = KfRaiseIrql(2);
  }
  if ((*(longlong *)(lVar3 + 0x71a0) != 0) && (*(char *)(lVar3 + 0x71c0) != '\0')) {
    iVar2 = (*DAT_140019610)(WdfDriverGlobals);
    if (((iVar2 < 0) &&
        ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || (1 < uVar5)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar5,(char)iVar2);
    }
    *(undefined1 *)(lVar3 + 0x71c0) = 0;
  }
  if ((*(longlong *)(lVar3 + 0x7178) != 0) &&
     (lVar4 = (*DAT_140019ee8)(WdfDriverGlobals,*(longlong *)(lVar3 + 0x7178),1), lVar4 != 0)) {
    (**(code **)(*(longlong *)(lVar4 + 8) + 0x30))(lVar4);
    (**(code **)(*(longlong *)(lVar4 + 8) + 8))(lVar4);
  }
  if ((*(longlong *)(lVar3 + 0x71a8) != 0) && (*(char *)(lVar3 + 0x71c1) != '\0')) {
    iVar2 = (*DAT_140019610)(WdfDriverGlobals);
    if (((iVar2 < 0) &&
        ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || (1 < uVar5)))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar5,(char)iVar2);
    }
    *(undefined1 *)(lVar3 + 0x71c1) = 0;
  }
  if ((*(longlong *)(lVar3 + 0x7180) != 0) &&
     (lVar4 = (*DAT_140019ee8)(WdfDriverGlobals,*(longlong *)(lVar3 + 0x7180),0), lVar4 != 0)) {
    (**(code **)(*(longlong *)(lVar4 + 8) + 0x30))(lVar4);
    (**(code **)(*(longlong *)(lVar4 + 8) + 8))(lVar4);
  }
  if (in_CR8 < 2) {
    KeLowerIrql(in_CR8);
  }
  if (*(longlong *)(lVar3 + 0x71c8) != 0) {
    MmFreeContiguousMemory();
    *(undefined8 *)(lVar3 + 0x71c8) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_82713d08f7718154044c65261359cc7a_Traceguids,uVar5);
  }
  return 0;
}



===== WPP_SF_dPd @ 1400118dc =====

void WPP_SF_dPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_dsqPP @ 140011930 =====

void WPP_SF_dsqPP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 char *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

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
            (param_1,0x2b,param_3,param_2,local_res20,4,pcVar1,lVar3,&param_6,8,&param_7,8,&param_8,
             8,0);
  return;
}



===== ControllerGenerateStop @ 1400119e8 =====

/* void __cdecl ControllerGenerateStop(struct PBC_DEVICE * __ptr64,struct PBC_TARGET * __ptr64) */

void __cdecl ControllerGenerateStop(PBC_DEVICE *param_1,PBC_TARGET *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar2 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar2);
  }
  if ((*(int *)(param_1 + 0x28) == 0) &&
     ((*(int *)(param_1 + 0x2c) == 0 || (*(int *)(param_1 + 0x2c) == 1)))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 & 0x800) != 0 && (uVar2 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar2 == 1)) || (1 < uVar2)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar2);
    }
    ControllerSwIoGenerateStop(param_1,param_2);
  }
  if (((*(int *)(param_1 + 0x28) == 0) &&
      ((*(int *)(param_1 + 0x2c) - 2U < 0xee || (*(int *)(param_1 + 0x2c) == 0xf2)))) ||
     (*(int *)(param_1 + 0x28) == 1)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar2 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar2 == 1)))) ||
        (1 < uVar2)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar2);
    }
    ControllerHwIoGenerateStop(param_1,param_2);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 & 0x800) != 0 && (uVar2 == 0)) ||
      ((((uVar1 & 0x1000) != 0 && (uVar2 == 1)) || (1 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar2);
  }
  return;
}



===== ControllerHwIoGenerateStop @ 140011bbc =====

/* void __cdecl ControllerHwIoGenerateStop(struct PBC_DEVICE * __ptr64,struct PBC_TARGET * __ptr64)
    */

void __cdecl ControllerHwIoGenerateStop(PBC_DEVICE *param_1,PBC_TARGET *param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
  }
  DEBUG_I2C_DCN(param_1,"After transaction: ");
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
  if ((uVar3 & 0x20) == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
    }
  }
  else {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
    }
    lVar2 = *(longlong *)(param_1 + 8);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x6c));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x6c),uVar3 | 2);
    iVar4 = 100;
    do {
      KeStallExecutionProcessor(*(undefined4 *)(param_2 + 0x24));
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x70));
      if ((uVar3 & 0x20) == 0) break;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (iVar4 == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar5 == 1)))) ||
          (1 < uVar5)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
      }
      DEBUG_I2C_LINE(param_1);
    }
    KeStallExecutionProcessor(*(undefined4 *)(param_2 + 0x24));
    DEBUG_I2C_DCN(param_1,"After stop: ");
    (*DAT_140019760)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
    ControllerDisableInterrupts(param_1);
    *(undefined4 *)(param_1 + 0x70d4) = 0;
    (*DAT_140019768)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x38));
    KeStallExecutionProcessor(*(undefined4 *)(param_2 + 0x24));
    DEBUG_I2C_DCN(param_1,"After reset: ");
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
      ((((uVar1 & 0x1000) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
  }
  return;
}



===== ControllerSwIoGenerateStop @ 140011e8c =====

/* void __cdecl ControllerSwIoGenerateStop(struct PBC_DEVICE * __ptr64,struct PBC_TARGET * __ptr64)
    */

void __cdecl ControllerSwIoGenerateStop(PBC_DEVICE *param_1,PBC_TARGET *param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
  }
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  bVar6 = (byte)(uVar3 >> 0x18);
  if (*(int *)(param_2 + 0x20) == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
    }
  }
  else {
    DEBUG_I2C_DCN(param_1,"After transaction: ");
    if ((uVar3 & 0x1000000) == 0) {
      DRIVE_I2C_SW(param_1,bVar6 >> 1 & 1,bVar6 >> 3 & 1);
      KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 10);
      lVar2 = *(longlong *)(param_1 + 8);
      uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x808));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x808),uVar3 | 0xa0000000);
      KeStallExecutionProcessor(*(uint *)(param_2 + 0x24) >> 1);
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
      if (((uVar3 & 0x1000000) != 0) || ((bVar6 >> 2 & 1) != ((byte)(uVar3 >> 0x1a) & 1))) {
        DEBUG_I2C_DCN(param_1,"After switch to SW: ");
      }
      DEBUG_I2C_LINE(param_1);
      if (*(int *)(param_2 + 0x20) == 1) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) || (1 < uVar5)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
        }
        DRIVE_I2C_SW(param_1,'\x01','\0');
        KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
        DRIVE_I2C_SW(param_1,'\0','\0');
        KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
        DRIVE_I2C_SW(param_1,'\x01','\0');
        KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
      }
      DRIVE_I2C_SW(param_1,'\x01','\x01');
      KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
      DRIVE_I2C_SW(param_1,'\0','\x01');
      KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
      DRIVE_I2C_SW(param_1,'\0','\0');
      KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),0xfffffffc);
      KeStallExecutionProcessor(*(undefined4 *)(param_2 + 0x24));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x804),3);
      KeStallExecutionProcessor(*(undefined4 *)(param_2 + 0x24));
      *(undefined4 *)(param_1 + 0x70d4) = 0;
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
      bVar6 = (byte)(uVar3 >> 0x18);
      bVar4 = bVar6 >> 3 & 1;
      bVar6 = bVar6 >> 1 & 1;
      if ((bVar6 != 0) || (bVar4 != 0)) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
          WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5,bVar6,bVar4);
        }
        DEBUG_I2C_DCN(param_1,"After reset: ");
      }
      lVar2 = *(longlong *)(param_1 + 8);
      uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x808));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x808),uVar3 & 0x5fffffff);
      KeStallExecutionProcessor((ulonglong)*(uint *)(param_2 + 0x24) / 5);
      DEBUG_I2C_LINE(param_1);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5);
  }
  return;
}



===== DEBUG_I2C_DCN @ 140012348 =====

/* void __cdecl DEBUG_I2C_DCN(struct PBC_DEVICE * __ptr64,char * __ptr64) */

void __cdecl DEBUG_I2C_DCN(PBC_DEVICE *param_1,char *param_2)

{
  uint uVar1;
  ulong uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  byte bVar6;
  char *pcVar7;
  char *pcVar8;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  bVar6 = (byte)(uVar2 >> 0x18);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    pcVar4 = "SW-";
    pcVar3 = "SW-";
    if ((bVar6 >> 6 & 1) != 0) {
      pcVar3 = "SW0";
    }
    pcVar8 = "HW-";
    pcVar7 = "HW-";
    if ((bVar6 >> 3 & 1) != 0) {
      pcVar7 = "HW0";
    }
    if ((int)uVar2 < 0) {
      pcVar7 = pcVar3;
    }
    if ((bVar6 >> 4 & 1) != 0) {
      pcVar4 = "SW0";
    }
    if ((bVar6 >> 1 & 1) != 0) {
      pcVar8 = "HW0";
    }
    if ((bVar6 >> 5 & 1) != 0) {
      pcVar8 = pcVar4;
    }
    WPP_SF_dsddss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar5,param_2,bVar6 & 1,
                  bVar6 >> 2 & 1,pcVar8,pcVar7);
  }
  return;
}



===== DEBUG_I2C_LINE @ 1400124c8 =====

/* void __cdecl DEBUG_I2C_LINE(struct PBC_DEVICE * __ptr64) */

void __cdecl DEBUG_I2C_LINE(PBC_DEVICE *param_1)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x24);
  }
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (1 < uVar4)))) {
    bVar2 = (byte)(uVar3 >> 0x18);
    WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar4,bVar2 & 1,bVar2 >> 2 & 1);
  }
  return;
}



===== DRIVE_I2C_SW @ 140012564 =====

/* void __cdecl DRIVE_I2C_SW(struct PBC_DEVICE * __ptr64,unsigned char,unsigned char) */

void __cdecl DRIVE_I2C_SW(PBC_DEVICE *param_1,uchar param_2,uchar param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x24);
  }
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808),
             ((uint)param_3 << 2 | (uint)param_2) << 0x1c | uVar2 & 0xafffffff);
  iVar4 = 100;
  if (param_2 == '\0') {
    iVar5 = 100;
    do {
      KeStallExecutionProcessor((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x30) + 0x24) / 10);
      uVar2 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
      if ((uVar2 >> 0x18 & 1) != 0) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (iVar5 == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || (1 < uVar3)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar3);
      }
      DEBUG_I2C_LINE(param_1);
    }
  }
  if (param_3 == '\0') {
    do {
      KeStallExecutionProcessor((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x30) + 0x24) / 10);
      uVar2 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 8) + 0x808));
      if ((uVar2 >> 0x1a & 1) != 0) break;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (iVar4 == 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || (1 < uVar3)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_705319b36cb9ce41a26c867da651ea82_Traceguids,uVar3);
      }
      DEBUG_I2C_LINE(param_1);
    }
  }
  return;
}



===== WPP_SF_dsddss @ 140012710 =====

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



===== GetAcpiHardwareInstance @ 140012850 =====

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
  undefined1 auStack_2a8 [32];
  undefined4 local_268;
  undefined4 local_264;
  undefined8 local_260;
  int *local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined4 *local_240;
  undefined8 local_238;
  longlong local_230;
  int local_228 [2];
  int local_220;
  short local_21c;
  ulong local_218;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
  }
  local_240 = &local_268;
  local_268 = 0x42696541;
  local_264 = 0x4449555f;
  local_248 = 1;
  local_238 = 8;
  memset(local_228,0,0x200);
  *param_2 = 0xff;
  local_258 = local_228;
  local_260 = 1;
  local_250 = 0x200;
  uVar3 = (*DAT_140019430)(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (*DAT_1400198b0)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_230 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,(char)iVar2);
    }
    lVar6 = 0;
    goto LAB_140012bc5;
  }
  lVar6 = -0x3febfff1;
  if (local_228[0] == 0x426f6541) {
    if (local_220 == 1) {
      if (local_21c == 0) {
        lVar6 = 0;
        *param_2 = local_218;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                    &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,(char)local_218);
        }
        goto LAB_140012bc5;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012bc5;
      uVar4 = 0x15;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012bc5;
      uVar4 = 0x14;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012bc5;
    uVar4 = 0x13;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
LAB_140012bc5:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
  }
  return lVar6;
}



===== GetAcpiHardwareRevision @ 140012c34 =====

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
  undefined1 auStack_2b8 [32];
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
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
  }
  local_250 = &local_278;
  local_278 = 0x42696541;
  local_274 = 0x5652485f;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  uVar3 = (*DAT_140019430)(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (*DAT_1400198b0)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_240 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,(char)iVar2);
    }
    lVar6 = 0;
    *param_2 = 0;
    goto LAB_140012fa6;
  }
  *param_2 = 0xff;
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
           ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
          WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,(char)local_228);
        }
        goto LAB_140012fa6;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012fa6;
      uVar4 = 0xe;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012fa6;
      uVar4 = 0xd;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
        ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))))) goto LAB_140012fa6;
    uVar4 = 0xc;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
LAB_140012fa6:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (1 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5);
  }
  return lVar6;
}



===== GetAcpiSettings @ 140013014 =====

/* void __cdecl GetAcpiSettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetAcpiSettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x24);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar2);
  }
  ReadAcpiClockSettings
            (param_1,"SSCN",(ulong *)(param_1 + 0x70),(ulong *)(param_1 + 0x74),
             (ulong *)(param_1 + 0x78));
  ReadAcpiClockSettings
            (param_1,"FMCN",(ulong *)(param_1 + 0x80),(ulong *)(param_1 + 0x84),
             (ulong *)(param_1 + 0x88));
  ReadAcpiClockSettings
            (param_1,"FPCN",(ulong *)(param_1 + 0x90),(ulong *)(param_1 + 0x94),
             (ulong *)(param_1 + 0x98));
  ReadAcpiClockSettings
            (param_1,"HSCN",(ulong *)(param_1 + 0xa0),(ulong *)(param_1 + 0xa4),
             (ulong *)(param_1 + 0xa8));
  ReadAcpiParameter(param_1,"M0D3",(ulong *)(param_1 + 0xbc));
  ReadAcpiParameter(param_1,"M1D3",(ulong *)(param_1 + 0xb8));
  ReadAcpiParameter(param_1,"M0D0",(ulong *)(param_1 + 0xc4));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      (1 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar2);
  }
  return;
}



===== ReadAcpiClockSettings @ 1400131c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadAcpiClockSettings(struct PBC_DEVICE * __ptr64,char * __ptr64,unsigned long *
   __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) */

long __cdecl
ReadAcpiClockSettings
          (PBC_DEVICE *param_1,char *param_2,ulong *param_3,ulong *param_4,ulong *param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  undefined2 uVar6;
  uint uVar7;
  ulong uVar8;
  short *psVar9;
  undefined1 auStackY_2e8 [32];
  uint local_2a4;
  undefined4 local_2a0;
  char local_29c;
  char local_29b;
  char local_29a;
  char local_299;
  undefined8 local_298;
  undefined4 *local_290;
  undefined8 local_288;
  undefined8 local_280;
  int *local_278;
  undefined8 local_270;
  ulong *local_268;
  longlong local_260;
  ulong *local_258;
  ulong *local_250;
  int local_248 [2];
  uint local_240;
  short local_23c [250];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2e8;
  uVar7 = 0xf0;
  local_268 = param_5;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x24);
  }
  local_29c = *param_2;
  local_29b = param_2[1];
  local_29a = param_2[2];
  local_2a0 = 0x42696541;
  local_299 = param_2[3];
  local_290 = &local_2a0;
  local_288 = 8;
  local_298 = 1;
  local_258 = param_4;
  local_250 = param_3;
  memset(local_248,0,0x200);
  local_278 = local_248;
  local_280 = 1;
  local_270 = 0x200;
  uVar3 = (*DAT_140019430)(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (*DAT_1400198b0)(WdfDriverGlobals,uVar3,0);
  if ((iVar2 < 0) || (local_260 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (1 < uVar7)))))) {
      WPP_SF_dsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar7,param_2,(char)iVar2);
    }
    return 0;
  }
  ppuVar5 = (undefined **)WPP_GLOBAL_Control;
  if (local_248[0] == 0x426f6541) {
    if (local_240 - 2 < 2) {
      psVar9 = local_23c;
      local_2a4 = 0;
      if (local_240 == 0) {
        return iVar2;
      }
      while (*psVar9 == 0) {
        if (local_2a4 == 0) {
          uVar8 = *(ulong *)(psVar9 + 2);
          *local_250 = uVar8;
          ppuVar5 = (undefined **)WPP_GLOBAL_Control;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
              ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (1 < uVar7)))))) {
            uVar6 = 0x1c;
LAB_1400134fa:
            WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                        &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar7,param_2,(char)uVar8,
                        (char)uVar8);
            ppuVar5 = (undefined **)WPP_GLOBAL_Control;
          }
        }
        else if (local_2a4 == 1) {
          uVar8 = *(ulong *)(psVar9 + 2);
          *local_258 = uVar8;
          ppuVar5 = (undefined **)WPP_GLOBAL_Control;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
              ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (1 < uVar7)))))) {
            uVar6 = 0x1d;
            goto LAB_1400134fa;
          }
        }
        else if (local_2a4 == 2) {
          uVar8 = *(ulong *)(psVar9 + 2);
          *local_268 = uVar8;
          ppuVar5 = (undefined **)WPP_GLOBAL_Control;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) || (1 < uVar7)))) {
            uVar6 = 0x1e;
            goto LAB_1400134fa;
          }
        }
        if ((ushort)psVar9[1] < 4) {
          uVar4 = 4;
        }
        else {
          uVar4 = (ulonglong)(ushort)psVar9[1];
        }
        local_2a4 = local_2a4 + 1;
        psVar9 = (short *)((longlong)psVar9 + uVar4 + 4);
        if (local_240 <= local_2a4) {
          return iVar2;
        }
      }
      if (ppuVar5 == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      uVar1 = *(uint *)((longlong)ppuVar5 + 0x2c);
      if ((uVar1 & 0x40) == 0) {
        return iVar2;
      }
      if (*(byte *)((longlong)ppuVar5 + 0x29) < 2) {
        return iVar2;
      }
      if ((((uVar1 >> 0xb & 1) == 0) || (uVar7 != 0)) &&
         ((((uVar1 & 0x1000) == 0 || (uVar7 != 1)) && (uVar7 < 2)))) {
        return iVar2;
      }
      uVar6 = 0x1b;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        return iVar2;
      }
      if (((((uVar1 >> 0xb & 1) == 0) || (uVar7 != 0)) && (((uVar1 & 0x1000) == 0 || (uVar7 != 1))))
         && (uVar7 < 2)) {
        return iVar2;
      }
      uVar6 = 0x1a;
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
    if (((((uVar1 >> 0xb & 1) == 0) || (uVar7 != 0)) && (((uVar1 & 0x1000) == 0 || (uVar7 != 1))))
       && (uVar7 < 2)) {
      return iVar2;
    }
    uVar6 = 0x19;
  }
  WPP_SF_ds(ppuVar5[3],uVar6,&WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar7,param_2);
  return iVar2;
}



===== ReadAcpiParameter @ 140013638 =====

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
  undefined1 auStackY_2b8 [32];
  undefined4 local_278;
  char local_274;
  char local_273;
  char local_272;
  char local_271;
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
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2b8;
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x24);
  }
  local_274 = *param_2;
  local_273 = param_2[1];
  local_278 = 0x42696541;
  local_272 = param_2[2];
  local_271 = param_2[3];
  local_250 = &local_278;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  uVar3 = (*DAT_140019430)(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (*DAT_1400198b0)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_240 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (1 < uVar5)))))) {
      WPP_SF_dsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,param_2,(char)iVar2);
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
        if (((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
            (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)))) && (uVar5 < 2)) {
          return iVar2;
        }
        WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                    &WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,param_2,(char)local_228,
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
      if ((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
         ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))) {
        return iVar2;
      }
      uVar4 = 0x22;
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
      if (((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
          (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)))) && (uVar5 < 2)) {
        return iVar2;
      }
      uVar4 = 0x21;
    }
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
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
    if ((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
       ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (uVar5 < 2)))) {
      return iVar2;
    }
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 0x20;
  }
  WPP_SF_ds(uVar3,uVar4,&WPP_2b2d7765c59bcc2190ff8fb6e01538ed_Traceguids,uVar5,param_2);
  return iVar2;
}



===== WPP_SF_ds @ 140013998 =====

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



===== WPP_SF_dsL @ 140013a0c =====

void WPP_SF_dsL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
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



===== WPP_SF_dsdD @ 140013a98 =====

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



===== CheckSupportedHardware @ 140013b34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CheckSupportedHardware(struct WDFDEVICE__ * __ptr64) */

long __cdecl CheckSupportedHardware(WDFDEVICE__ *param_1)

{
  long lVar1;
  longlong lVar2;
  undefined2 uVar3;
  undefined1 auStack_58 [32];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
  }
  lVar2 = (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  lVar1 = GetHardwareVersion(param_1,(HW_PARAMETERS *)&local_38);
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140013df5;
    uVar3 = 0xf;
  }
  else {
    lVar1 = GetHardwareRevision(param_1,(HW_PARAMETERS *)&local_38);
    if (lVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140013df5;
      uVar3 = 0x10;
    }
    else {
      if (local_38 == 0xff) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
        }
        lVar1 = GetHardwareInstance(param_1,(HW_PARAMETERS *)&local_38);
        if (lVar1 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140013df5;
          uVar3 = 0x12;
          goto LAB_140013bfb;
        }
      }
      *(undefined4 *)(lVar2 + 0x28) = local_34;
      *(undefined4 *)(lVar2 + 0x2c) = local_30;
      *(int *)(lVar2 + 0x24) = local_38;
      if (*(int *)(lVar2 + 0x28) == 0) {
        if (*(int *)(lVar2 + 0x2c) == 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140013df5;
          uVar3 = 0x13;
        }
        else if (*(int *)(lVar2 + 0x2c) == 1) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140013df5;
          uVar3 = 0x14;
        }
        else if (*(int *)(lVar2 + 0x2c) == 0xf2) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140013df5;
          uVar3 = 0x15;
        }
        else {
          if (0xed < *(int *)(lVar2 + 0x2c) - 2U) goto LAB_140013dc1;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140013df5;
          uVar3 = 0x16;
        }
      }
      else {
LAB_140013dc1:
        if (*(int *)(lVar2 + 0x28) != 1) {
          lVar1 = -0x3ffffda0;
          goto LAB_140013df5;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar1;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140013df5;
        uVar3 = 0x17;
      }
    }
  }
LAB_140013bfb:
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
LAB_140013df5:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
  }
  return lVar1;
}



===== GetHardwareInstance @ 140013e48 =====

/* long __cdecl GetHardwareInstance(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareInstance(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  PBC_DEVICE *pPVar1;
  long lVar2;
  
  pPVar1 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  lVar2 = GetAcpiHardwareInstance(pPVar1,(ulong *)param_2);
  return lVar2;
}



===== GetHardwareRevision @ 140013e78 =====

/* long __cdecl GetHardwareRevision(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareRevision(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  PBC_DEVICE *pPVar1;
  long lVar2;
  
  pPVar1 = (PBC_DEVICE *)
           (*DAT_140019930)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140019040);
  lVar2 = GetAcpiHardwareRevision(pPVar1,(ulong *)(param_2 + 8));
  return lVar2;
}



===== GetHardwareVersion @ 140013eac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetHardwareVersion(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareVersion(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  wchar_t *_Src;
  size_t sVar4;
  ulonglong uVar5;
  wchar_t *_Str2;
  uint uVar6;
  ulonglong uVar7;
  size_t _MaxCount;
  ulonglong _MaxCount_00;
  undefined4 *puVar8;
  undefined1 auStackY_2f8 [32];
  undefined8 local_2c8;
  ulonglong local_2b8;
  undefined4 local_2b0 [6];
  undefined4 local_298;
  undefined4 local_294;
  WDFDEVICE__ *local_290;
  undefined4 local_278;
  undefined8 local_274;
  undefined8 uStack_26c;
  undefined8 local_264;
  undefined2 local_25c;
  undefined1 local_25a [102];
  undefined8 local_1f4;
  undefined4 local_1ec;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined2 local_1d0;
  undefined1 local_1ce [102];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined8 local_15c;
  undefined8 uStack_154;
  undefined8 local_14c;
  undefined2 local_144;
  undefined1 local_142 [102];
  undefined8 local_dc;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined2 local_b8;
  undefined1 local_b6 [102];
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2f8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
  }
  local_278 = 1;
  local_25c = 0;
  local_274 = 0x49005000430041;
  uStack_26c = 0x54004e0049005c;
  local_264 = 0x32004300330033;
  memset(local_25a,0,0x66);
  uVar7 = 0;
  local_1e8 = 0x49005000430041;
  uStack_1e0 = 0x54004e0049005c;
  local_1d8 = 0x33004300330033;
  local_1ec = 1;
  local_1d0 = 0;
  local_1f4 = 0;
  memset(local_1ce,0,0x66);
  local_168 = 0;
  local_14c = 0x32003300340033;
  local_15c = 0x49005000430041;
  uStack_154 = 0x54004e0049005c;
  local_164 = 1;
  local_160 = 1;
  local_144 = 0;
  memset(local_142,0,0x66);
  local_dc = 1;
  local_c0 = 0x33003300340033;
  local_d0 = 0x49005000430041;
  uStack_c8 = 0x54004e0049005c;
  local_d4 = 1;
  local_b8 = 0;
  memset(local_b6,0,0x66);
  local_50 = 1;
  local_4c = 1;
  puVar8 = &local_278;
  do {
    memset(local_2b0,0,0x38);
    local_2b0[0] = 0x38;
    local_298 = 1;
    local_294 = 1;
    local_290 = param_1;
    iVar2 = (*DAT_140019570)(WdfDriverGlobals,param_1,*puVar8,0x200);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_dLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff,(char)uVar7,(char)iVar2);
      }
    }
    else {
      _Src = (wchar_t *)(*DAT_1400198f0)(WdfDriverGlobals,local_2c8);
      pwVar1 = (wchar_t *)((longlong)_Src + (local_2b8 & 0xfffffffffffffffe));
      for (; (_Src < pwVar1 && (_Src != (wchar_t *)0x0)); _Src = _Src + sVar4 + 1) {
        _MaxCount = (longlong)pwVar1 - (longlong)_Src >> 1;
        sVar4 = wcsnlen(_Src,_MaxCount);
        if (sVar4 == 0) break;
        _Str2 = (wchar_t *)((longlong)&local_274 + uVar7 * 0x8c);
        uVar5 = 0xffffffffffffffff;
        do {
          uVar5 = uVar5 + 1;
        } while (_Str2[uVar5] != L'\0');
        _MaxCount_00 = _MaxCount & 0xffffffff;
        if (uVar5 < (_MaxCount & 0xffffffff)) {
          _MaxCount_00 = uVar5;
        }
        iVar3 = wcsncmp(_Src,_Str2,_MaxCount_00);
        if (iVar3 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff,_Src);
          }
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(local_25a + uVar7 * 0x8c + 0x66);
          *(undefined4 *)param_2 = *(undefined4 *)(local_25a + uVar7 * 0x8c + 0x6a);
          (*DAT_140019960)(WdfDriverGlobals,local_2c8);
          goto LAB_1400141e2;
        }
        sVar4 = wcsnlen(_Src,_MaxCount);
      }
      (*DAT_140019960)(WdfDriverGlobals);
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar8 = puVar8 + 0x23;
    if (3 < uVar6) {
      iVar2 = -0x3ffffda0;
LAB_1400141e2:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_b36f7472517633055c1b40c62490cf22_Traceguids,0xff);
      }
      return iVar2;
    }
  } while( true );
}



===== WPP_SF_dS @ 1400142bc =====

void WPP_SF_dS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              short *param_5)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
  if (param_5 == (short *)0x0) {
    lVar1 = 10;
  }
  else if (*param_5 == 0) {
    lVar1 = 0xe;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (short *)0x0) {
    param_5 = (short *)&u_NULL;
  }
  else if (*param_5 == 0) {
    param_5 = (short *)&u_<NULL>;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,lVar1,0);
  return;
}



===== __GSHandlerCheck @ 140014358 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140014378 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== _vsnwprintf @ 1400143e0 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 1400143f8 =====

int __cdecl
_vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  if ((_Format == (wchar_t *)0x0) || ((_MaxCount != 0 && (_DstBuf == (wchar_t *)0x0)))) {
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    if (_MaxCount < 0x40000000) {
      local_38._cnt = (int)_MaxCount * 2;
    }
    else {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = (char *)_DstBuf;
    local_38._base = (char *)_DstBuf;
    iVar1 = _woutput_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
        local_38._ptr = (char *)((longlong)local_38._ptr + 1);
      }
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
      }
    }
  }
  return iVar1;
}



===== wcsnlen @ 1400144d0 =====

size_t __cdecl wcsnlen(wchar_t *_Src,size_t _MaxCount)

{
  size_t sVar1;
  
  sVar1 = 0;
  if (_MaxCount != 0) {
    do {
      if (*_Src == L'\0') {
        return sVar1;
      }
      sVar1 = sVar1 + 1;
      _Src = _Src + 1;
    } while (sVar1 < _MaxCount);
  }
  return sVar1;
}



===== wcsncmp @ 1400144f0 =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  if (_MaxCount == 0) {
    return 0;
  }
  for (; ((_MaxCount = _MaxCount - 1, _MaxCount != 0 && (*_Str1 != L'\0')) && (*_Str1 == *_Str2));
      _Str1 = _Str1 + 1) {
    _Str2 = _Str2 + 1;
  }
  return (uint)(ushort)*_Str1 - (uint)(ushort)*_Str2;
}



===== _flsbuf @ 14001451c =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 140014524 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _woutput_l(FILE *_File,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  ushort uVar1;
  wchar_t wVar2;
  ushort *puVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  wchar_t *pwVar8;
  char *pcVar9;
  ulonglong uVar10;
  FILE *pFVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  wchar_t wVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  wchar_t *pwVar19;
  undefined1 auStack_4c8 [32];
  undefined8 local_4a8;
  int local_498;
  uint local_494;
  uint local_490;
  uint local_48c;
  wchar_t *local_488;
  int local_480;
  int local_47c;
  wchar_t local_478;
  short local_476;
  wchar_t local_474 [2];
  char local_470 [4];
  int local_46c;
  FILE *local_468;
  undefined4 local_460;
  wchar_t *local_458;
  wchar_t local_448 [255];
  undefined2 local_249;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_4c8;
  uVar12 = 0;
  local_460 = 0;
  local_48c = 0;
  uVar6 = 0;
  local_490 = 0;
  local_494 = 0;
  local_46c = 0;
  local_480 = 0;
  local_488 = (wchar_t *)_ArgList;
  local_468 = _File;
  if ((_File == (FILE *)0x0) || (_Format == (wchar_t *)0x0)) {
    local_4a8 = 0;
    _guard_check_icall();
    iVar17 = -1;
  }
  else {
    wVar15 = *_Format;
    iVar17 = 0;
    local_498 = 0;
    uVar14 = 0;
    local_47c = 0;
    if (wVar15 != L'\0') {
      pcVar9 = (char *)local_458;
      uVar16 = 0;
      do {
        uVar10 = 0;
        pwVar19 = _Format + 1;
        if (iVar17 < 0) break;
        uVar18 = 0;
        if ((ushort)(wVar15 + L'￠') < 0x59) {
          uVar13 = (int)"(null)"[(ushort)wVar15] & 0xf;
        }
        else {
          uVar13 = uVar18;
        }
        local_47c = (int)(char)(&__lookuptable)[(longlong)local_47c + (longlong)(int)uVar13 * 8] >>
                    4;
        uVar13 = uVar12;
        local_458 = pwVar19;
        if (local_47c == 0) {
LAB_140014c9e:
          local_480 = 1;
          write_char(wVar15,local_468,&local_498);
LAB_140014ba1:
          _ArgList = (va_list)local_488;
          uVar12 = uVar13;
          iVar17 = local_498;
          uVar6 = local_490;
          uVar18 = uVar16;
        }
        else if (local_47c == 1) {
          local_46c = 0;
          local_48c = 0;
          local_494 = 0;
          local_490 = 0xffffffff;
          local_480 = 0;
          uVar12 = uVar18;
          uVar6 = 0xffffffff;
        }
        else if (local_47c == 2) {
          if (wVar15 == L' ') {
            uVar12 = uVar12 | 2;
            uVar18 = uVar16;
          }
          else if (wVar15 == L'#') {
            uVar12 = uVar12 | 0x80;
            uVar18 = uVar16;
          }
          else if (wVar15 == L'+') {
            uVar12 = uVar12 | 1;
            uVar18 = uVar16;
          }
          else if (wVar15 == L'-') {
            uVar12 = uVar12 | 4;
            uVar18 = uVar16;
          }
          else {
            uVar18 = uVar16;
            if (wVar15 == L'0') {
              uVar12 = uVar12 | 8;
            }
          }
        }
        else if (local_47c == 3) {
          if (wVar15 == L'*') {
            local_48c = *(uint *)_ArgList;
            local_488 = (wchar_t *)((longlong)_ArgList + 8);
            _ArgList = (va_list)local_488;
            uVar18 = local_48c;
            if ((int)local_48c < 0) {
              uVar12 = uVar12 | 4;
              uVar18 = -local_48c;
              local_48c = -local_48c;
            }
          }
          else {
            uVar18 = (uint)(ushort)wVar15 + uVar16 * 10 + -0x30;
            local_48c = uVar18;
          }
        }
        else if (local_47c == 4) {
          local_490 = 0;
          uVar6 = uVar18;
          uVar18 = uVar16;
        }
        else if (local_47c == 5) {
          if (wVar15 == L'*') {
            local_490 = *(uint *)_ArgList;
            local_488 = (wchar_t *)((longlong)_ArgList + 8);
            _ArgList = (va_list)local_488;
            uVar6 = local_490;
            uVar18 = uVar16;
            if ((int)local_490 < 0) {
              local_490 = 0xffffffff;
              uVar6 = 0xffffffff;
            }
          }
          else {
            local_490 = (uint)(ushort)wVar15 + uVar6 * 10 + -0x30;
            uVar6 = local_490;
            uVar18 = uVar16;
          }
        }
        else if (local_47c == 6) {
          if (wVar15 == L'I') {
            wVar2 = *pwVar19;
            uVar13 = uVar12 | 0x8000;
            if ((wVar2 == L'6') && (_Format[2] == L'4')) {
              pwVar19 = _Format + 3;
              uVar12 = uVar12 | 0x8000;
              uVar18 = uVar16;
            }
            else {
              if ((wVar2 != L'3') || (_Format[2] != L'2')) {
                if ((ushort)(wVar2 + L'ﾨ') < 0x21) {
                  uVar12 = uVar13;
                  uVar18 = uVar16;
                  if ((0x120821001U >> ((ulonglong)(ushort)(wVar2 + L'ﾨ') & 0x3f) & 1) != 0)
                  goto LAB_140014bbc;
                }
                local_47c = 0;
                goto LAB_140014c9e;
              }
              pwVar19 = _Format + 3;
              uVar12 = uVar12 & 0xffff7fff;
              uVar18 = uVar16;
            }
          }
          else if (wVar15 == L'h') {
            uVar12 = uVar12 | 0x20;
            uVar18 = uVar16;
          }
          else if (wVar15 == L'l') {
            if (*pwVar19 == L'l') {
              pwVar19 = _Format + 2;
              uVar12 = uVar12 | 0x1000;
              uVar18 = uVar16;
            }
            else {
              uVar12 = uVar12 | 0x10;
              uVar18 = uVar16;
            }
          }
          else {
            uVar18 = uVar16;
            if (wVar15 == L'w') {
              uVar12 = uVar12 | 0x800;
            }
          }
        }
        else {
          uVar18 = uVar16;
          if (local_47c == 7) {
            if ((ushort)wVar15 < 0x6a) {
              if (wVar15 == L'i') {
LAB_1400146b1:
                uVar12 = uVar12 | 0x40;
LAB_1400146b4:
                iVar7 = 10;
                goto LAB_1400146c3;
              }
              if (wVar15 == L'C') {
                if ((uVar12 & 0x830) == 0) {
                  uVar12 = uVar12 | 0x20;
                }
LAB_1400147c2:
                local_474[0] = *(wchar_t *)_ArgList;
                local_488 = (wchar_t *)((longlong)_ArgList + 8);
                local_480 = 1;
                if ((uVar12 & 0x20) == 0) {
                  local_448[0] = local_474[0];
                }
                else {
                  local_470[1] = 0;
                  local_470[0] = (char)local_474[0];
                  iVar7 = mbtowc(local_448,local_470,(longlong)(int)__mb_cur_max);
                  if (iVar7 < 0) {
                    local_46c = 1;
                  }
                }
                pcVar9 = (char *)local_448;
                uVar10 = 1;
              }
              else if (wVar15 == L'S') {
                if ((uVar12 & 0x830) == 0) {
                  uVar12 = uVar12 | 0x20;
                }
LAB_14001475a:
                if (uVar6 == 0xffffffff) {
                  uVar6 = 0x7fffffff;
                }
                pwVar8 = *(wchar_t **)_ArgList;
                local_488 = (wchar_t *)((longlong)_ArgList + 8);
                if ((uVar12 & 0x20) == 0) {
                  local_480 = 1;
                  pcVar9 = (char *)L"(null)";
                  if (pwVar8 != (wchar_t *)0x0) {
                    pcVar9 = (char *)pwVar8;
                  }
                  for (pwVar8 = (wchar_t *)pcVar9;
                      (uVar6 != 0 && (uVar6 = uVar6 - 1, *pwVar8 != L'\0')); pwVar8 = pwVar8 + 1) {
                  }
                  uVar10 = (longlong)pwVar8 - (longlong)pcVar9 >> 1;
                }
                else {
                  pcVar9 = "(null)";
                  if (pwVar8 != (wchar_t *)0x0) {
                    pcVar9 = (char *)pwVar8;
                  }
                  pwVar8 = (wchar_t *)pcVar9;
                  if (0 < (int)uVar6) {
                    do {
                      if ((char)*pwVar8 == '\0') break;
                      uVar18 = (int)uVar10 + 1;
                      uVar10 = (ulonglong)uVar18;
                      pwVar8 = (wchar_t *)((longlong)pwVar8 + 1);
                    } while ((int)uVar18 < (int)uVar6);
                  }
                }
              }
              else {
                if (wVar15 == L'X') goto LAB_14001489b;
                if (wVar15 == L'Z') {
                  puVar3 = *(ushort **)_ArgList;
                  local_488 = (wchar_t *)((longlong)_ArgList + 8);
                  if ((puVar3 == (ushort *)0x0) ||
                     (pcVar9 = *(char **)(puVar3 + 4), (wchar_t *)pcVar9 == (wchar_t *)0x0)) {
                    pcVar9 = "(null)";
                    uVar10 = 6;
                  }
                  else {
                    uVar1 = *puVar3;
                    if (puVar3[1] < uVar1) {
LAB_140014e25:
                      local_4a8 = 0;
                      _guard_check_icall();
                      return -1;
                    }
                    if ((uVar12 >> 0xb & 1) == 0) {
                      local_480 = 0;
                      uVar10 = (ulonglong)uVar1;
                    }
                    else {
                      if (((~uVar1 & 1) == 0) || ((~(uint)pcVar9 & 1) == 0)) goto LAB_140014e25;
                      local_480 = 1;
                      uVar10 = (ulonglong)(uVar1 >> 1);
                    }
                  }
                }
                else {
                  if (wVar15 == L'c') goto LAB_1400147c2;
                  uVar10 = uVar14;
                  if (wVar15 == L'd') goto LAB_1400146b1;
                }
              }
            }
            else if (wVar15 == L'n') {
              piVar4 = *(int **)_ArgList;
              local_488 = (wchar_t *)((longlong)_ArgList + 8);
              iVar7 = _get_printf_count_output();
              if (iVar7 == 0) goto LAB_140014e25;
              if ((uVar12 & 0x20) == 0) {
                *piVar4 = iVar17;
              }
              else {
                *(short *)piVar4 = (short)iVar17;
              }
              local_46c = 1;
              pwVar19 = local_458;
              uVar10 = uVar14;
            }
            else {
              if (wVar15 == L'o') {
                iVar7 = 8;
                if ((char)uVar12 < '\0') {
                  uVar12 = uVar12 | 0x200;
                }
              }
              else {
                if (wVar15 == L'p') {
                  uVar6 = 0x10;
                  uVar12 = uVar12 | 0x8000;
LAB_14001489b:
                  local_460 = 7;
                }
                else {
                  if (wVar15 == L's') goto LAB_14001475a;
                  if (wVar15 == L'u') goto LAB_1400146b4;
                  uVar10 = uVar14;
                  if (wVar15 != L'x') goto LAB_140014a36;
                  local_460 = 0x27;
                }
                iVar7 = 0x10;
                if ((char)uVar12 < '\0') {
                  local_494 = 2;
                  local_478 = L'0';
                  local_476 = (short)local_460 + 0x51;
                }
              }
LAB_1400146c3:
              if ((uVar12 >> 0xf == 0) && ((uVar12 >> 0xc & 1) == 0)) {
                if ((uVar12 & 0x20) == 0) {
                  if ((uVar12 & 0x40) == 0) {
                    uVar14 = (ulonglong)*(uint *)_ArgList;
                  }
                  else {
                    uVar14 = (ulonglong)(int)*(uint *)_ArgList;
                  }
                }
                else if ((uVar12 & 0x40) == 0) {
                  uVar14 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar14 = (ulonglong)*(wchar_t *)_ArgList;
                }
              }
              else {
                uVar14 = *(ulonglong *)_ArgList;
              }
              local_488 = (wchar_t *)((longlong)_ArgList + 8);
              if (((uVar12 & 0x40) != 0) && ((longlong)uVar14 < 0)) {
                uVar14 = -uVar14;
                uVar12 = uVar12 | 0x100;
              }
              if ((uVar12 >> 0xf == 0) && ((uVar12 >> 0xc & 1) == 0)) {
                uVar14 = uVar14 & 0xffffffff;
              }
              if ((int)uVar6 < 0) {
                uVar6 = 1;
              }
              else {
                uVar12 = uVar12 & 0xfffffff7;
                if (0x200 < (int)uVar6) {
                  uVar6 = 0x200;
                }
              }
              pwVar8 = &local_249;
              local_494 = -(uint)(uVar14 != 0) & local_494;
              for (; (local_490 = uVar6 - 1, 0 < (int)uVar6 || (uVar14 != 0));
                  uVar14 = uVar14 / (ulonglong)(longlong)iVar7) {
                uVar6 = (int)(uVar14 % (ulonglong)(longlong)iVar7) + 0x30;
                cVar5 = (char)uVar6;
                if (0x39 < uVar6) {
                  cVar5 = cVar5 + (char)local_460;
                }
                *(char *)pwVar8 = cVar5;
                pwVar8 = (wchar_t *)((longlong)pwVar8 + -1);
                uVar6 = local_490;
              }
              uVar6 = (int)&local_249 - (int)pwVar8;
              pcVar9 = (char *)((longlong)pwVar8 + 1);
              uVar10 = (ulonglong)uVar6;
              uVar16 = local_48c;
              if (((uVar12 & 0x200) != 0) && ((uVar6 == 0 || (*pcVar9 != '0')))) {
                *(char *)pwVar8 = '0';
                pcVar9 = (char *)pwVar8;
                uVar10 = (ulonglong)(uVar6 + 1);
              }
            }
LAB_140014a36:
            pFVar11 = local_468;
            uVar14 = uVar10;
            if (local_46c == 0) {
              if ((uVar12 & 0x40) != 0) {
                if ((uVar12 >> 8 & 1) == 0) {
                  if ((uVar12 & 1) == 0) {
                    if ((uVar12 & 2) == 0) goto LAB_140014a80;
                    local_478 = L' ';
                  }
                  else {
                    local_478 = L'+';
                  }
                }
                else {
                  local_478 = L'-';
                }
                local_494 = 1;
              }
LAB_140014a80:
              uVar6 = local_494;
              iVar7 = (int)uVar10;
              iVar17 = (uVar16 - iVar7) - local_494;
              if ((uVar12 & 0xc) == 0) {
                write_multi_char(L' ',iVar17,local_468,&local_498);
              }
              write_string(&local_478,uVar6,pFVar11,&local_498);
              pFVar11 = local_468;
              if (((uVar12 & 8) != 0) && ((uVar12 & 4) == 0)) {
                write_multi_char(L'0',iVar17,local_468,&local_498);
              }
              if ((local_480 == 0) && (0 < iVar7)) {
                uVar10 = uVar10 & 0xffffffff;
                pwVar19 = (wchar_t *)pcVar9;
                do {
                  uVar6 = (int)uVar10 - 1;
                  iVar7 = mbtowc(local_474,(char *)pwVar19,(longlong)(int)__mb_cur_max);
                  if (iVar7 == 2) {
                    uVar6 = (int)uVar10 - 2;
                  }
                  uVar10 = (ulonglong)uVar6;
                  if (iVar7 < 1) {
                    local_498 = -1;
                    pFVar11 = local_468;
                    goto LAB_140014b6f;
                  }
                  write_char(local_474[0],local_468,&local_498);
                  pwVar19 = (wchar_t *)((longlong)pwVar19 + (longlong)iVar7);
                } while (0 < (int)uVar6);
                pFVar11 = local_468;
              }
              else {
                write_string((wchar_t *)pcVar9,iVar7,pFVar11,&local_498);
              }
LAB_140014b6f:
              if ((-1 < local_498) && ((uVar12 & 4) != 0)) {
                write_multi_char(L' ',iVar17,pFVar11,&local_498);
                pwVar19 = local_458;
                uVar13 = uVar12;
                uVar16 = local_48c;
                goto LAB_140014ba1;
              }
              pwVar19 = local_458;
              _ArgList = (va_list)local_488;
              iVar17 = local_498;
              uVar6 = local_490;
              uVar18 = local_48c;
            }
            else {
              _ArgList = (va_list)local_488;
              uVar6 = local_490;
              uVar18 = uVar16;
            }
          }
        }
LAB_140014bbc:
        wVar15 = *pwVar19;
        _Format = pwVar19;
        uVar16 = uVar18;
      } while (wVar15 != L'\0');
    }
  }
  return iVar17;
}



===== write_char @ 140014e40 =====

/* Library Function - Single Match
    write_char
   
   Library: Visual Studio 2019 Release */

void write_char(wchar_t param_1,FILE *param_2,int *param_3)

{
  wint_t wVar1;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    wVar1 = _fputwc_nolock(param_1,param_2);
    if ((wVar1 == 0xffff) && ((param_2->_flag & 0x20U) != 0)) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 140014e8c =====

/* Library Function - Single Match
    write_multi_char
   
   Library: Visual Studio 2019 Release */

void write_multi_char(wchar_t param_1,int param_2,FILE *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 140014ee0 =====

/* Library Function - Single Match
    write_string
   
   Library: Visual Studio 2019 Release */

void write_string(wchar_t *param_1,int param_2,FILE *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    while (0 < param_2) {
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
      if (*param_4 == -1) {
        if (gbl_errno != 0x2a) {
          return;
        }
        write_char(L'?',param_3,param_4);
      }
    }
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _guard_check_icall @ 140014f68 =====

void _guard_check_icall(void)

{
  return;
}



===== _get_printf_count_output @ 140014f6c =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_1400192d0 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 140014f84 =====

wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    _guard_check_icall();
    return 0xffff;
  }
  iVar1 = _File->_cnt + -2;
  _File->_cnt = iVar1;
  if (iVar1 < 0) {
    iVar1 = _flswbuf((uint)(ushort)_Ch,_File);
    return (wint_t)iVar1;
  }
  *(wchar_t *)_File->_ptr = _Ch;
  _File->_ptr = _File->_ptr + 2;
  return _Ch;
}



===== mbtowc @ 140014fd8 =====

int __cdecl mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  wchar_t wVar1;
  int iVar2;
  char *local_res10 [3];
  
  iVar2 = 0;
  if ((_SrcCh != (char *)0x0) && (_SrcSizeInBytes != 0)) {
    if (*_SrcCh == '\0') {
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = L'\0';
      }
    }
    else {
      local_res10[0] = _SrcCh;
      wVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *_DstCh = wVar1;
      iVar2 = (int)local_res10[0] - (int)_SrcCh;
    }
  }
  return iVar2;
}



===== _flswbuf @ 140015028 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __security_check_cookie @ 140015050 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlAnsiCharToUnicodeChar @ 140015078 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140015078. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== FxStubDriverUnloadCommon @ 140015080 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140019150);
  WdfVersionUnbind(&DAT_14001a298,&DAT_140019150,WdfDriverGlobals);
  return;
}



===== entry @ 1400150b0 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400150dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  long lVar1;
  
  if (param_1 == 0) {
    lVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14001a2a0 = &DAT_14001a090;
    _DAT_14001a298 = 0x2080000;
    _DAT_14001a078 = param_1;
    RtlCopyUnicodeString(&DAT_14001a298);
    lVar1 = WdfVersionBind(param_1,&DAT_14001a298,&DAT_140019150,&WdfDriverGlobals);
    if (-1 < lVar1) {
      lVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140019150);
      if (((-1 < lVar1) && (lVar1 = FxStubInitTypes(), -1 < lVar1)) &&
         (lVar1 = DriverEntry(param_1,param_2), -1 < lVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _DAT_14001a080 = DAT_140019928;
            DAT_140019928 = &FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_14001a068 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
    }
  }
  return lVar1;
}



===== FxStubDriverUnload @ 140015204 =====

void FxStubDriverUnload(void)

{
  if ((DAT_14001a068 != (code *)0x0) && (DAT_14001a068 != FxStubDriverUnload)) {
    (*DAT_14001a068)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 14001522c =====

/* WARNING: Removing unreachable block (ram,0x00014001525c) */
/* WARNING: Removing unreachable block (ram,0x000140015263) */
/* WARNING: Removing unreachable block (ram,0x000140015291) */
/* WARNING: Removing unreachable block (ram,0x000140015269) */
/* WARNING: Removing unreachable block (ram,0x000140015271) */
/* WARNING: Removing unreachable block (ram,0x000140015277) */
/* WARNING: Removing unreachable block (ram,0x000140015249) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140015298 =====

/* WARNING: Removing unreachable block (ram,0x0001400152bf) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &_SPBCx_BIND_INFO;
  while( true ) {
    if ((int *)0x1400191df < piVar2) {
      return iVar1;
    }
    if (*piVar2 != 0x50) break;
    PTR___KMDF_CLASS_BIND_START_1400191e8 = (undefined *)piVar2;
    if (*(code **)(piVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(param_1,WdfDriverGlobals,piVar2);
    }
    else {
      iVar1 = (**(code **)(piVar2 + 0xe))(WdfVersionBindClass,param_1,WdfDriverGlobals,piVar2);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 0x14;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 140015330 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &_SPBCx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400191e8 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14001918f < PTR___KMDF_CLASS_BIND_START_1400191e8)) {
    do {
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar1);
      }
      puVar1 = puVar1 + 0x14;
    } while (puVar1 <= PTR___KMDF_CLASS_BIND_START_1400191e8);
  }
  return;
}



===== WdfVersionBind @ 1400153a8 =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400153a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 1400153ae =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400153ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 1400153b4 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400153b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 1400153ba =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400153ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== memcpy @ 1400153c0 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
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
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
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
        if (uVar12 == 0) goto LAB_140015577;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
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
LAB_140015577:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
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
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
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
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
      if (uVar12 == 0) goto LAB_1400153d2;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_1400153d2:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 140015700 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_1400157c0;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1400157bd_caseD_2;
      case 3:
        goto switchD_1400157bd_caseD_3;
      case 4:
        goto switchD_1400157bd_caseD_4;
      case 5:
        goto switchD_1400157bd_caseD_5;
      case 6:
        goto switchD_1400157bd_caseD_6;
      case 7:
        goto switchD_1400157bd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1400157c0:
        *puVar3 = uVar4;
switchD_1400157bd_caseD_7:
        puVar3[1] = uVar4;
switchD_1400157bd_caseD_6:
        puVar3[2] = uVar4;
switchD_1400157bd_caseD_5:
        puVar3[3] = uVar4;
switchD_1400157bd_caseD_4:
        puVar3[4] = uVar4;
switchD_1400157bd_caseD_3:
        puVar3[5] = uVar4;
switchD_1400157bd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== WppCleanupKm @ 14001c000 =====

void WppCleanupKm(void)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
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



===== WppInitKm @ 14001c068 =====

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
                  (*(undefined8 *)(puVar1 + 8),0,&WppClassicProviderCallback,puVar1,puVar1 + 0x38);
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



===== WppLoadTracingSupport @ 14001c0ec =====

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
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



===== WppTraceCallback @ 14001c1e4 =====

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar4 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          lVar7 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),param_4 + 6,0x10);
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
          if (WPPTraceSuite != 2) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
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
      if (puVar1 == (ushort *)0x0) {
        uVar12 = 0;
        uVar9 = uVar10 * 0x20 + 0x18;
      }
      else {
        uVar12 = uVar10 * 0x20 + 0x18;
        uVar9 = *puVar1 + 2 + uVar12;
      }
      if (param_3 < uVar9) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar9;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar9;
      param_4[2] = uVar12;
      param_4[4] = uVar10;
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar1;
        memcpy((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
               (ulonglong)*puVar1);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar11 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar11 = 0x81000;
          *(undefined8 *)(puVar11 + -4) = uVar2;
          *(undefined8 *)(puVar11 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar11 = puVar11 + 8;
        } while (uVar8 != 0);
      }
      *puVar4 = uVar9;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 14001d000 =====

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


