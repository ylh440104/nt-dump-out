
===== OnDeviceAdd @ 140001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl OnDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  PBC_DEVICE *pPVar5;
  uint *puVar6;
  uint uVar7;
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
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
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
  uVar7 = 0xff;
  local_198 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,0xff);
  }
  EtwActivityIdControl(3,&local_48);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceAdd_Start,&local_48);
  }
  pcVar2 = SpbFunctions;
  _guard_check_icall();
  iVar4 = (*pcVar2)(SpbDriverGlobals);
  if (iVar4 < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
    puVar6 = (uint *)&EvtDeviceSpbDeviceInitConfig_Error;
  }
  else {
    memset(&local_188,0,0x90);
    local_188 = 0x90;
    local_160 = OnPrepareHardware;
    local_158 = OnReleaseHardware;
    local_180 = OnD0Entry;
    local_170 = OnD0Exit;
    local_140 = OnSelfManagedIoInit;
    local_150 = OnSelfManagedIoCleanup;
    local_118 = OnQueryStop;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x1b8);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,local_198,&local_188);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x230);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,local_198,0x80,1);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x220);
    _guard_check_icall();
    iVar4 = (*pcVar2)(WdfDriverGlobals);
    if (-1 < iVar4) {
      memset(local_f0,0,0x38);
      local_c0 = PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078;
      local_f0[0] = 0x38;
      local_d8 = 1;
      local_d4 = 1;
      pcVar2 = *(code **)(WdfFunctions_01015 + 600);
      _guard_check_icall();
      iVar4 = (*pcVar2)(WdfDriverGlobals,&local_198,local_f0,&local_190);
      if (iVar4 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceCreate_Error,0
                        ,iVar4);
        }
        goto LAB_14000133a;
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
      _guard_check_icall();
      pPVar5 = (PBC_DEVICE *)
               (*pcVar2)(WdfDriverGlobals,local_190,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
      *(WDFDEVICE__ **)pPVar5 = local_190;
      iVar4 = CheckSupportedHardware(local_190);
      if (iVar4 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0qqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceHw_Error,
                           &local_48,*(undefined4 *)(pPVar5 + 0x40),
                           (char)*(undefined4 *)(pPVar5 + 0x44),(char)*(undefined4 *)(pPVar5 + 0x48)
                           ,(char)*(undefined4 *)(pPVar5 + 0x4c));
        }
        goto LAB_14000133a;
      }
      uStack_44 = *(ushort *)(pPVar5 + 0x40) | 0x8000;
      uVar7 = *(uint *)(pPVar5 + 0x40);
      *(ulonglong *)(pPVar5 + 8) =
           CONCAT26(uStack_42,CONCAT24(*(ushort *)(pPVar5 + 0x40),local_48)) | 0x800000000000;
      *(undefined8 *)(pPVar5 + 0x10) = uStack_40;
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0qqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceHw_Info,
                         &local_48,uVar7,(char)*(undefined4 *)(pPVar5 + 0x44),
                         (char)*(undefined4 *)(pPVar5 + 0x48),(char)*(undefined4 *)(pPVar5 + 0x4c));
      }
      GetDefaultSettings(pPVar5);
      OverrideDefaultsForHardware(pPVar5);
      GetAcpiSettings(pPVar5);
      GetRegistrySettings(pPVar5);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
               (((uVar1 & 0x8000) != 0 && (uVar7 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))))) {
          WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                        &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,uVar7,
                        (char)*(undefined4 *)(pPVar5 + 0xa0),(char)*(undefined4 *)(pPVar5 + 0xa4),
                        (char)*(undefined4 *)(pPVar5 + 0xa8),(char)*(undefined4 *)(pPVar5 + 0xac),
                        (char)*(undefined4 *)(pPVar5 + 0xb0));
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
          if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
              (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((uVar1 & 0x8000) != 0 && (uVar7 == 4)))) ||
               ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
            WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                          &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,uVar7,
                          (char)*(undefined4 *)(pPVar5 + 0xb4),(char)*(undefined4 *)(pPVar5 + 0xb8),
                          (char)*(undefined4 *)(pPVar5 + 0xbc),(char)*(undefined4 *)(pPVar5 + 0xc0),
                          (char)*(undefined4 *)(pPVar5 + 0xc4));
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
                (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
                  (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
                 (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                   (((uVar1 & 0x8000) != 0 && (uVar7 == 4)))) ||
                  ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))))) {
              WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                            &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,uVar7,
                            (char)*(undefined4 *)(pPVar5 + 200),(char)*(undefined4 *)(pPVar5 + 0xcc)
                            ,(char)*(undefined4 *)(pPVar5 + 0xd0),
                            (char)*(undefined4 *)(pPVar5 + 0xd4),
                            (char)*(undefined4 *)(pPVar5 + 0xd8));
            }
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
                    (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
                   (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
                 ((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
              WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                            &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,uVar7,
                            (char)*(undefined4 *)(pPVar5 + 0xdc),
                            (char)*(undefined4 *)(pPVar5 + 0xe0),
                            (char)*(undefined4 *)(pPVar5 + 0xe4),
                            (char)*(undefined4 *)(pPVar5 + 0xe8),
                            (char)*(undefined4 *)(pPVar5 + 0xec));
            }
          }
        }
      }
      local_70 = 0;
      uStack_6c = 2;
      local_80 = 0x20000001c;
      local_78 = (code *)0x200000002;
      local_68 = 2;
      pcVar2 = *(code **)(WdfFunctions_01015 + 0xe8);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)pPVar5,&local_80);
      memset(&local_188,0,0x48);
      pcVar2 = DAT_1400224e8;
      local_178 = OnTargetConnect;
      local_188 = 0x48;
      uVar3 = *(undefined8 *)pPVar5;
      local_170 = OnTargetDisconnect;
      local_158 = OnRead;
      local_150 = OnWrite;
      local_148 = OnSequence;
      local_168 = OnControllerLock;
      local_160 = OnControllerUnlock;
      local_184 = 1;
      local_180 = (code *)CONCAT44(local_180._4_4_,1);
      _guard_check_icall();
      iVar4 = (*pcVar2)(SpbDriverGlobals,uVar3);
      pcVar2 = DAT_1400224f0;
      if (iVar4 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
        puVar6 = (uint *)&EvtDeviceSpbDeviceInitialize_Error;
      }
      else {
        _guard_check_icall();
        (*pcVar2)(SpbDriverGlobals,*(undefined8 *)pPVar5,OnOther,OnOtherInCallerContext);
        memset(&local_80,0,0x38);
        pcVar2 = DAT_140022500;
        local_50 = PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0;
        local_80._0_4_ = 0x38;
        local_68 = 1;
        local_64 = 1;
        _guard_check_icall();
        (*pcVar2)(SpbDriverGlobals,*(undefined8 *)pPVar5,&local_80);
        memset(&local_80,0,0x38);
        pcVar2 = DAT_1400224f8;
        local_50 = PTR__WDF_PBC_REQUEST_TYPE_INFO_1400220c8;
        local_80._0_4_ = 0x38;
        local_68 = 1;
        local_64 = 1;
        _guard_check_icall();
        (*pcVar2)(SpbDriverGlobals,*(undefined8 *)pPVar5,&local_80);
        memset(&local_80,0,0x38);
        local_60 = *(undefined8 *)pPVar5;
        local_80 = CONCAT44(local_80._4_4_,0x38);
        local_68 = 1;
        local_64 = 1;
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9d8);
        _guard_check_icall();
        iVar4 = (*pcVar2)(WdfDriverGlobals);
        if (iVar4 < 0) {
LAB_1400019ea:
          if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
          puVar6 = (uint *)&EvtDeviceWdfSpinLockCreate_Error;
        }
        else {
          memset(&local_188,0,0x68);
          uVar3 = *(undefined8 *)pPVar5;
          local_170 = OnInterruptIsr;
          local_168 = OnInterruptDpc;
          local_180 = local_f8;
          local_188 = 0x68;
          local_178 = (code *)CONCAT44(local_178._4_4_,2);
          local_12c = 1;
          pcVar2 = *(code **)(WdfFunctions_01015 + 0x468);
          _guard_check_icall();
          iVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,&local_188,0);
          if (iVar4 < 0) {
            if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
            puVar6 = (uint *)&EvtDeviceWdfInterruptCreate_Error;
          }
          else {
            memset(&local_80,0,0x28);
            local_70 = 0;
            local_68 = 0;
            local_78 = OnDelayTimerExpired;
            local_80 = CONCAT44(local_80._4_4_,0x28);
            uStack_6c = CONCAT31(uStack_6c._1_3_,1);
            memset(&local_188,0,0x38);
            local_168 = *(code **)pPVar5;
            local_188 = 0x38;
            local_170 = (code *)0x100000001;
            pcVar2 = *(code **)(WdfFunctions_01015 + 0x9f0);
            _guard_check_icall();
            iVar4 = (*pcVar2)(WdfDriverGlobals,&local_80,&local_188,pPVar5 + 0x80);
            if (-1 < iVar4) {
              memset(&local_80,0,0x28);
              local_70 = 0;
              local_68 = 0;
              local_80 = CONCAT44(local_80._4_4_,0x28);
              local_78 = OnCancelTimerExpired;
              uStack_6c = CONCAT31(uStack_6c._1_3_,1);
              memset(&local_188,0,0x38);
              local_168 = *(code **)pPVar5;
              local_188 = 0x38;
              local_170 = (code *)0x100000001;
              pcVar2 = *(code **)(WdfFunctions_01015 + 0x9f0);
              _guard_check_icall();
              iVar4 = (*pcVar2)(WdfDriverGlobals,&local_80,&local_188,pPVar5 + 0x88);
              if (-1 < iVar4) {
                memset(local_b8,0,0x38);
                local_b8[0] = 0x38;
                local_a0 = 1;
                local_9c = 1;
                local_98 = *(undefined8 *)pPVar5;
                pcVar2 = *(code **)(WdfFunctions_01015 + 0x9d8);
                _guard_check_icall();
                iVar4 = (*pcVar2)(WdfDriverGlobals);
                if (iVar4 < 0) goto LAB_1400019ea;
                memset(&local_80,0,0x24);
                uVar3 = *(undefined8 *)pPVar5;
                local_68 = 2;
                local_60 = CONCAT44(local_60._4_4_,2);
                local_80 = 0x100000024;
                local_78 = (code *)CONCAT44(*(undefined4 *)(pPVar5 + 0xf4),4);
                local_70 = 1;
                uStack_6c = 1;
                local_64 = 2;
                pcVar2 = *(code **)(WdfFunctions_01015 + 0x170);
                _guard_check_icall();
                iVar4 = (*pcVar2)(WdfDriverGlobals,uVar3);
                if ((-1 < iVar4) || ((Intel_iaLPSS2_I2CEnableBits & 1) == 0)) goto LAB_14000133a;
                puVar6 = (uint *)&EvtDeviceWdfDeviceAssignS0IdleSettings_Error;
                goto LAB_1400018b8;
              }
            }
            if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
            puVar6 = (uint *)&EvtDeviceWdfTimerCreate_Error;
          }
        }
      }
LAB_1400018b8:
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar6,0,iVar4);
      goto LAB_14000133a;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_14000133a;
    puVar6 = (uint *)&EvtDeviceWdfDeviceInitAssignSDDLString_Error;
  }
  McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar6,0,iVar4);
LAB_14000133a:
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceAdd_End,&local_48);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) ||
       (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,uVar7);
  }
  return iVar4;
}



===== OnDriverCleanup @ 140001cd0 =====

/* void __cdecl OnDriverCleanup(void * __ptr64) */

void __cdecl OnDriverCleanup(void *param_1)

{
  WppCleanupKm();
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDriverCleanup_Info,0);
  }
  McGenEventUnregister((longlong *)&iaLPSS2_I2C_PROVIDER_Context);
  return;
}



===== DriverEntry @ 140001d0c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 local_res18 [8];
  undefined4 local_78 [2];
  code *local_70;
  undefined4 local_5c;
  undefined4 local_58 [2];
  code *local_50;
  undefined4 local_40;
  undefined4 local_3c;
  
  _DAT_140022228 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140022208 = &WPP_ThisDir_CTLGUID_iaLPSS_I2CTraceGuid;
  DAT_140022210 = 0;
  _DAT_140022220 = 0;
  WppLoadTracingSupport();
  _DAT_140022220 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,0xff);
  }
  McGenEventRegister();
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDriverEntry_Start,0);
  }
  memset(local_78,0,0x20);
  local_78[0] = 0x20;
  local_70 = OnDeviceAdd;
  local_5c = 0x43324949;
  memset(local_58,0,0x38);
  local_58[0] = 0x38;
  local_50 = OnDriverCleanup;
  local_40 = 1;
  local_3c = 1;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x3a0);
  _guard_check_icall();
  iVar2 = (*pcVar1)(WdfDriverGlobals,param_1,param_2,local_58,local_78,local_res18);
  if ((iVar2 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDriverCreate_Error,0,iVar2
                 );
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDriverEntry_End,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_ec0116428a3831e0d1d015b28ca11640_Traceguids,0xff);
  }
  if (iVar2 < 0) {
    McGenEventUnregister((longlong *)&iaLPSS2_I2C_PROVIDER_Context);
    WppCleanupKm();
  }
  return iVar2;
}



===== McGenControlCallbackV2 @ 140001f40 =====

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



===== McGenEventRegister @ 140002048 =====

undefined8 McGenEventRegister(void)

{
  undefined8 uVar1;
  longlong *in_R9;
  
  if (*in_R9 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000140002051. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = EtwRegister();
    return uVar1;
  }
  return 0;
}



===== McGenEventUnregister @ 140002058 =====

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



===== McGenEventWriteKM @ 140002080 =====

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



===== McTemplateK0 @ 140002108 =====

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



===== McTemplateK0q @ 140002144 =====

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



===== McTemplateK0qqqq @ 140002198 =====

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



===== WPP_SF_d @ 140002224 =====

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dDDDDD @ 140002294 =====

void WPP_SF_dDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
            &param_9,4,0);
  return;
}



===== WppClassicProviderCallback @ 140002370 =====

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



===== DumpAllRegisters @ 1400023a0 =====

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
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2,(char)uVar4,
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2,(char)uVar4,
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2,(char)uVar4,
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2,(char)uVar4,
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
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
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2,(char)uVar4,
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar2);
  }
  return;
}



===== OnCancel @ 140002af0 =====

/* void __cdecl OnCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl OnCancel(WDFREQUEST__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  PBC_REQUEST *pPVar8;
  uint *puVar9;
  uint uVar10;
  
  pcVar2 = DAT_140022520;
  _guard_check_icall();
  uVar5 = (*pcVar2)(SpbDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar6 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022520;
  if (lVar6 == 0) {
    uVar10 = 0xf0;
  }
  else {
    _guard_check_icall();
    uVar5 = (*pcVar2)(SpbDriverGlobals,param_1);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar6 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar10 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar2 = DAT_140022520;
  _guard_check_icall();
  uVar5 = (*pcVar2)(SpbDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar6 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022518;
  _guard_check_icall();
  uVar5 = (*pcVar2)(SpbDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar7 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar8 = (PBC_REQUEST *)
           (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_REQUEST_TYPE_INFO_1400220c8);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2))))
       )) || (((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar2 = DAT_140022518;
  if (lVar7 == *(longlong *)(lVar6 + 0x58)) {
    if (pPVar8 == *(PBC_REQUEST **)(lVar7 + 0x18)) {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        _guard_check_icall();
        uVar3 = (*pcVar2)(SpbDriverGlobals,param_1);
        pcVar2 = DAT_140022520;
        _guard_check_icall();
        uVar5 = (*pcVar2)(SpbDriverGlobals,param_1);
        McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtCancelWithOutstandingRequest_Info,lVar6 + 8,uVar5,uVar3,
                        (char)param_1);
      }
      uVar5 = *(undefined8 *)(lVar6 + 0x80);
      pcVar2 = *(code **)(WdfFunctions_01015 + 0xa00);
      _guard_check_icall();
      cVar4 = (*pcVar2)(WdfDriverGlobals,uVar5,0);
      if (((((cVar4 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x60));
      *(uint *)(lVar6 + 0x70) = *(uint *)(lVar6 + 0x70) | 0x80000000;
      uVar5 = *(undefined8 *)(lVar6 + 0x60);
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x470);
      _guard_check_icall();
      cVar4 = (*pcVar2)(WdfDriverGlobals,uVar5);
      if (((((cVar4 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x488);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x60));
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x78));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)) || (5 < uVar10)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
      }
      goto LAB_1400032c6;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar9 = (uint *)&EvtCancelWithoutRequest_Warn;
      goto LAB_140002e4e;
    }
  }
  else if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
    puVar9 = (uint *)&EvtCancelWithoutTarget_Warn;
LAB_140002e4e:
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar9,lVar6 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ))) || (5 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))
         ) || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  PbcRequestComplete(pPVar8,"OnCancel");
LAB_1400032c6:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  return;
}



===== OnCancelTimerExpired @ 140003360 =====

/* void __cdecl OnCancelTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnCancelTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  char cVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
  _guard_check_icall();
  uVar6 = (*pcVar2)(WdfDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar7 = (*pcVar2)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar7 == 0) {
    uVar9 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
    _guard_check_icall();
    uVar6 = (*pcVar2)(WdfDriverGlobals,param_1);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar7 = (*pcVar2)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar9 = *(uint *)(lVar7 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
  _guard_check_icall();
  uVar6 = (*pcVar2)(WdfDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar7 = (*pcVar2)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
       (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = DAT_140022518;
  if (*(longlong *)(lVar7 + 0x58) == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) == 0) goto LAB_1400037e1;
    puVar8 = (uint *)&EvtCancelTimerWithoutTarget_Warn;
  }
  else {
    puVar3 = *(undefined8 **)(*(longlong *)(lVar7 + 0x58) + 0x18);
    if (puVar3 != (undefined8 *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        uVar6 = *puVar3;
        _guard_check_icall();
        uVar4 = (*pcVar2)(SpbDriverGlobals,uVar6);
        pcVar2 = DAT_140022520;
        uVar6 = *puVar3;
        _guard_check_icall();
        uVar6 = (*pcVar2)(SpbDriverGlobals,uVar6);
        McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtCancelTimerWithOutstandingRequest_Info,lVar7 + 8,uVar6,uVar4,
                        (char)*puVar3);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x60));
      *(uint *)(lVar7 + 0x70) = *(uint *)(lVar7 + 0x70) | 0x40000000;
      uVar6 = *(undefined8 *)(lVar7 + 0x60);
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x470);
      _guard_check_icall();
      cVar5 = (*pcVar2)(WdfDriverGlobals,uVar6);
      if (((((cVar5 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x488);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x60));
      goto LAB_1400037e1;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 8) == 0) goto LAB_1400037e1;
    puVar8 = (uint *)&EvtCancelTimerWithoutRequest_Warn;
  }
  McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar8,lVar7 + 8);
LAB_1400037e1:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                 (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
                ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ))) || (5 < uVar9)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
  }
  return;
}



===== OnControllerLock @ 140003990 =====

/* void __cdecl OnControllerLock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerLock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar5 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtSpbDDI_EvtSpbControllerLock_Info,lVar3 + 8,param_1,(char)param_2,
                    (char)param_3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  *(longlong *)(lVar3 + 0x58) = lVar4;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtControllerLock_Info,
                  lVar3 + 8,*(undefined2 *)(lVar4 + 0xc));
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ) || (5 < uVar5)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))
        ) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))
        ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return;
}



===== OnControllerUnlock @ 140003e40 =====

/* void __cdecl OnControllerUnlock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerUnlock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar5 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar4 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtSpbDDI_EvtSpbControllerUnlock_Info,pPVar4 + 8,param_1,(char)param_2,
                    (char)param_3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  ControllerFinishTransfer(pPVar4);
  *(undefined8 *)(pPVar4 + 0x58) = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ) || (5 < uVar5)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))
        ) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtControllerUnlock_Info,
                  pPVar4 + 8,*(undefined2 *)(lVar3 + 0xc));
  }
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))
        ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return;
}



===== OnD0Entry @ 1400042f0 =====

/* long __cdecl OnD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  longlong lVar4;
  PBC_DEVICE *pPVar5;
  uint uVar6;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar4 == 0) {
    uVar6 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar4 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar6);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar5 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtD0Entry_Start,pPVar5 + 8,
                  param_2);
  }
  *(undefined8 *)(pPVar5 + 0x58) = 0;
  lVar3 = ControllerInitialize(pPVar5);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtD0Entry_End,pPVar5 + 8,
                  lVar3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
       || (5 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar6);
  }
  return lVar3;
}



===== OnD0Exit @ 140004510 =====

/* long __cdecl OnD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar4 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtD0Exit_Start,pPVar4 + 8,
                  param_2);
  }
  ControllerUninitialize(pPVar4);
  *(undefined8 *)(pPVar4 + 0x58) = 0;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtD0Exit_End,pPVar4 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return 0;
}



===== OnDelayTimerExpired @ 140004730 =====

/* void __cdecl OnDelayTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnDelayTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  PBC_REQUEST *pPVar3;
  long lVar4;
  undefined8 uVar5;
  longlong lVar6;
  PBC_DEVICE *pPVar7;
  uint *puVar8;
  uint uVar9;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
  _guard_check_icall();
  uVar5 = (*pcVar2)(WdfDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar6 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar6 == 0) {
    uVar9 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
    _guard_check_icall();
    uVar5 = (*pcVar2)(WdfDriverGlobals,param_1);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar6 = (*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar9 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xa08);
  _guard_check_icall();
  uVar5 = (*pcVar2)(WdfDriverGlobals,param_1);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar7 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))
        ))) || (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  lVar6 = *(longlong *)(pPVar7 + 0x58);
  if (lVar6 == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar8 = (uint *)&EvtTimerWithoutTarget_Warn;
LAB_140004a12:
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar8,pPVar7 + 8);
    }
  }
  else {
    pPVar3 = *(PBC_REQUEST **)(lVar6 + 0x18);
    if (pPVar3 == (PBC_REQUEST *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
        puVar8 = (uint *)&EvtTimerWithoutRequest_Warn;
        goto LAB_140004a12;
      }
    }
    else {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtTransferDelayExpired_Info,pPVar7 + 8,
                        *(undefined2 *)(lVar6 + 0xc),(char)*(undefined4 *)(pPVar3 + 0x10),
                        (char)*(undefined4 *)(pPVar3 + 0xc));
      }
      lVar4 = ControllerConfigureForTransfer(pPVar7,pPVar3);
      if (lVar4 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtRequestFailToConfigure_Error,pPVar7 + 8,lVar4);
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        _guard_check_icall();
        (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
             ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))))) || (5 < uVar9)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        PbcRequestComplete(pPVar3,"OnDelayTimerExpired");
        goto LAB_140004b48;
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))
           ) || ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
LAB_140004b48:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  return;
}



===== OnInterruptDpc @ 140004da0 =====

/* void __cdecl OnInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl OnInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  code *pcVar4;
  PBC_REQUEST *pPVar5;
  ulong uVar6;
  longlong lVar7;
  PBC_DEVICE *pPVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar7 = (*pcVar4)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar7 == 0) {
    uVar10 = 0xf0;
  }
  else {
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar7 = (*pcVar4)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar10 = *(uint *)(lVar7 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar10 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar10 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar8 = (PBC_DEVICE *)(*pcVar4)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 & 0x800) != 0 && (uVar10 == 0)) ||
      ((((((uVar1 & 0x1000) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(pPVar8 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 & 0x800) != 0 && (uVar10 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar10 == 1)))) ||
        (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))))) || (5 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  if (*(longlong *)(pPVar8 + 0x58) == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar9 = (uint *)&EvtDpcWithoutTarget_Warn;
LAB_140005018:
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar9,pPVar8 + 8);
    }
  }
  else {
    pPVar5 = *(PBC_REQUEST **)(*(longlong *)(pPVar8 + 0x58) + 0x18);
    if (pPVar5 == (PBC_REQUEST *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
        puVar9 = (uint *)&EvtDpcWithoutRequest_Warn;
        goto LAB_140005018;
      }
    }
    else {
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals,param_1);
      uVar6 = *(ulong *)(pPVar8 + 0x6c);
      uVar2 = *(ulong *)(pPVar8 + 0x70);
      *(undefined4 *)(pPVar8 + 0x6c) = 0;
      *(undefined4 *)(pPVar8 + 0x70) = 0;
      if (pPVar8[0x74] == (PBC_DEVICE)0x0) {
        ControllerDisableInterrupts(pPVar8);
      }
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x488);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals,param_1);
      if ((uVar6 != 0) || (uVar2 != 0)) {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
          McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                         (uint *)&EvtInterruptDPCStatus_Info,pPVar8 + 8,uVar6,(char)uVar2);
        }
        iVar3 = *(int *)(pPVar5 + 0x10);
        ControllerAcknowledgeInterrupts(pPVar8,uVar6);
        ControllerProcessInterrupts(pPVar8,pPVar5,uVar6,uVar2);
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
        _guard_check_icall();
        (*pcVar4)(WdfDriverGlobals,param_1);
        uVar6 = *(ulong *)(pPVar8 + 0x68);
        do {
          LOCK();
          uVar2 = *(ulong *)(pPVar8 + 0x68);
          bVar11 = uVar6 == uVar2;
          if (bVar11) {
            *(ulong *)(pPVar8 + 0x68) = uVar6;
          }
          else {
            uVar6 = uVar2;
          }
          UNLOCK();
        } while (!bVar11);
        if ((uVar6 != 0) && (iVar3 == *(int *)(pPVar5 + 0x10))) {
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                          (uint *)&EvtInterruptDPCReenable_Info,pPVar8 + 8,uVar6);
          }
          ControllerEnableInterrupts(pPVar8,uVar6);
        }
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x488);
        _guard_check_icall();
        (*pcVar4)(WdfDriverGlobals,param_1);
        if (pPVar5[0x24] != (PBC_REQUEST)0x0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
                  (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                     &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
          }
          pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e8);
          _guard_check_icall();
          (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(pPVar8 + 0x78));
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
              (((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                     &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
          }
          PbcRequestComplete(pPVar5,"OnInterruptDpc");
          goto LAB_140005401;
        }
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 & 0x800) != 0 && (uVar10 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))
        ) || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(pPVar8 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar10 == 0)) ||
       ((((uVar1 & 0x1000) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2))))))
      || (((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
           (((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)))) ||
          ((((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
LAB_140005401:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  return;
}



===== OnInterruptIsr @ 1400054a0 =====

/* unsigned char __cdecl OnInterruptIsr(struct WDFINTERRUPT__ * __ptr64,unsigned long) */

uchar __cdecl OnInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  char cVar4;
  ulong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  PBC_DEVICE *pPVar8;
  uint uVar9;
  uchar uVar10;
  bool bVar11;
  
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x4b8);
  _guard_check_icall();
  uVar6 = (*pcVar3)(WdfDriverGlobals,param_1);
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar7 = (*pcVar3)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar7 == 0) {
    uVar9 = 0xf0;
  }
  else {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x4b8);
    _guard_check_icall();
    uVar6 = (*pcVar3)(WdfDriverGlobals,param_1);
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar7 = (*pcVar3)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar9 = *(uint *)(lVar7 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  uVar10 = '\0';
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x4b8);
  _guard_check_icall();
  uVar6 = (*pcVar3)(WdfDriverGlobals,param_1);
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar8 = (PBC_DEVICE *)(*pcVar3)(WdfDriverGlobals,uVar6,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  uVar5 = *(ulong *)(pPVar8 + 0x68);
  do {
    LOCK();
    uVar1 = *(ulong *)(pPVar8 + 0x68);
    bVar11 = uVar5 == uVar1;
    if (bVar11) {
      *(ulong *)(pPVar8 + 0x68) = uVar5;
    }
    else {
      uVar5 = uVar1;
    }
    UNLOCK();
  } while (!bVar11);
  uVar5 = ControllerGetInterruptStatus(pPVar8,uVar5);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtInterruptISRStatus_Info,
                  pPVar8 + 8,uVar5);
  }
  if (uVar5 != 0) {
    *(uint *)(pPVar8 + 0x6c) = *(uint *)(pPVar8 + 0x6c) | uVar5;
    uVar10 = '\x01';
    ControllerDisableInterrupts(pPVar8);
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x470);
    _guard_check_icall();
    cVar4 = (*pcVar3)(WdfDriverGlobals,param_1);
    if (cVar4 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\x01';
      }
      uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar2 & 8) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))
           ) || ((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                 (((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                   (((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
                  ((((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                  &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9,(char)uVar5);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
        (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  return uVar10;
}



===== OnMonitorPowerSettingCallback @ 1400057e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnMonitorPowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl OnMonitorPowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
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
  iVar2 = 0;
  uVar4 = 0xff;
  if (param_4 == (void *)0x0) {
    iVar2 = -0x3ffffff3;
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   (uint *)&EvtPowerCallbackInvalidContext_Error,0);
    }
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar1)(WdfDriverGlobals,param_4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = 0xf0;
    if (lVar3 != 0) {
      uVar4 = *(uint *)(lVar3 + 0x40);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar5 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar4 == 1))))
         || (((uVar5 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
        ((((uVar5 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
         (((((uVar5 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
           (((uVar5 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
    }
    if ((*(longlong *)param_1 == 0x4526451002731015) &&
       (*(longlong *)(param_1 + 8) == -0x15e542815e1a1967)) {
      memset(&local_58,0,0x24);
      local_58 = 0x24;
      local_48 = 2;
      local_44 = 2;
      local_40 = 2;
      local_38 = 2;
      local_54 = 1;
      local_50 = 4;
      local_3c = 2;
      if (*(int *)param_2 != 0) {
        local_4c = *(undefined4 *)(lVar3 + 0xf4);
      }
      else {
        local_4c = *(undefined4 *)(lVar3 + 0xf8);
      }
      uVar5 = (uint)(*(int *)param_2 != 0);
      *(uint *)(lVar3 + 0x98) = uVar5;
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtPowerCallback_Info,
                       lVar3 + 8,uVar5,(char)local_4c);
      }
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x170);
      _guard_check_icall();
      iVar2 = (*pcVar1)(WdfDriverGlobals,param_4,&local_58);
      if ((iVar2 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
        McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                      (uint *)&EvtPowerWdfDeviceAssignS0IdleSettings_Error,lVar3 + 8,iVar2);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || ((((uVar5 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar5 >> 0xe & 1) != 0 && (uVar4 == 3)))
           ))) ||
      (((((uVar5 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return iVar2;
}



===== OnOther @ 140005ad0 =====

/* void __cdecl OnOther(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
OnOther(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4,
       __uint64 param_5,ulong param_6)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppxxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                       (uint *)&EvtSpbDDI_EvtSpbOther_Info,lVar3 + 8,param_1,(char)param_2,
                       (char)param_3,(char)param_4,(char)param_5,(char)param_6);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtRequestCompleteSynchronously_Error,lVar3 + 8,param_1,(char)param_3,
                     8,0xbb);
  }
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return;
}



===== OnOtherInCallerContext @ 140005d50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnOtherInCallerContext(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl OnOtherInCallerContext(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 auStack_78 [32];
  undefined2 local_48 [2];
  int local_44;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   (uint *)&EvtSpbDDI_EvtSpbOtherInCallerContext_Info,lVar3 + 8,param_1,
                   (char)param_2);
  }
  memset(local_48,0,0x28);
  local_48[0] = 0x28;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x850);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,param_2,local_48);
  if (local_44 - 0xeU < 2) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140005f30;
    puVar4 = (uint *)&EvtRequestUnsupportedIoControlCode_Error;
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140005f30;
    puVar4 = (uint *)&EvtRequestUnsupportedType_Error;
  }
  McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar4,lVar3 + 8,0xc00000bb);
LAB_140005f30:
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,param_2,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return;
}



===== OnPrepareHardware @ 140006000 =====

/* long __cdecl OnPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  PBC_DEVICE *pPVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  longlong lVar6;
  PBC_DEVICE *pPVar7;
  char *pcVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar6 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar6 == 0) {
    uVar10 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar6 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar10 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || (((uVar4 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
      ((((uVar4 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
       (((((uVar4 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar4 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar7 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  pPVar1 = pPVar7 + 8;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtPrepareHardware_Start,
                 pPVar1);
  }
  lVar5 = 0;
  iVar13 = 0;
  iVar11 = 0;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x980);
  _guard_check_icall();
  uVar4 = (*pcVar2)(WdfDriverGlobals,param_3);
  uVar12 = 0;
  if (uVar4 != 0) {
    do {
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x988);
      _guard_check_icall();
      pcVar8 = (char *)(*pcVar2)(WdfDriverGlobals,param_3,uVar12);
      cVar3 = *pcVar8;
      if (cVar3 == '\x03') {
        if (iVar13 == 0) {
          lVar6 = MmMapIoSpaceEx(*(undefined8 *)(pcVar8 + 4),*(undefined4 *)(pcVar8 + 0xc),0x204);
          if (lVar6 == 0) {
            lVar5 = -0x3fffff66;
            if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
              McTemplateK0qxqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                               (uint *)&EvtPrepareHardware_MmioMap_Error,pPVar1,0,
                               (char)*(undefined8 *)(pcVar8 + 4),(char)*(undefined4 *)(pcVar8 + 0xc)
                               ,0x9a);
            }
            goto LAB_1400063f4;
          }
          *(longlong *)(pPVar7 + 0x20) = lVar6;
          *(undefined8 *)(pPVar7 + 0x18) = *(undefined8 *)(pcVar8 + 4);
          *(undefined4 *)(pPVar7 + 0x28) = *(undefined4 *)(pcVar8 + 0xc);
          *(longlong *)(pPVar7 + 0x38) = lVar6 + 0x200;
          *(longlong *)(pPVar7 + 0x110) = lVar6 + 0x800;
          *(longlong *)(pPVar7 + 0x30) = lVar6;
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0qxqp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                             (uint *)&EvtPrepareHardware_MmioMapped_Info,pPVar1,0,
                             (char)*(undefined8 *)(pcVar8 + 4),(char)*(undefined4 *)(pcVar8 + 0xc),
                             (char)lVar6);
          }
        }
        else if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
          McTemplateK0qxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                          (uint *)&EvtPrepareHardware_MmioRes_Warn,pPVar1,iVar13,
                          (char)*(undefined8 *)(pcVar8 + 4),(char)*(undefined4 *)(pcVar8 + 0xc));
        }
        cVar3 = *pcVar8;
        iVar13 = iVar13 + 1;
      }
      if (cVar3 == '\x02') {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
          McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtPrepareHardware_IntVector_Info,pPVar1,
                        *(undefined4 *)(pcVar8 + 8));
        }
        iVar11 = iVar11 + 1;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar4);
    if ((iVar13 - 1U < 2) && (iVar11 == 1)) {
      pPVar7[0x118] = (PBC_DEVICE)0x0;
      pPVar7[0x108] = (PBC_DEVICE)0x0;
      if (*(int *)(pPVar7 + 0xfc) == 1) {
        lVar5 = DmaInitSw(pPVar7);
        if (-1 < lVar5) {
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                         (uint *)&EvtPrepareHardware_DmaSwInit_Info,pPVar1);
          }
          pPVar7[0x108] = (PBC_DEVICE)0x1;
          goto LAB_1400063f4;
        }
        lVar5 = -0x3ffffb7d;
        if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_1400063f4;
        puVar9 = (uint *)&EvtPrepareHardware_DmaSwInit_Error;
      }
      else {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) == 0) goto LAB_1400063f4;
        puVar9 = (uint *)&EvtPrepareHardware_DmaSwDisabled_Info;
      }
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar9,pPVar1);
      goto LAB_1400063f4;
    }
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0qqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtPrepareHardware_ResourceCnt_Error,pPVar1,iVar13,(char)iVar11,0x9a);
  }
LAB_1400063f4:
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtPrepareHardware_End,pPVar1)
    ;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar10 == 1))))
       || ((((uVar4 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
           (((uVar4 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
      (((((uVar4 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar10);
  }
  return lVar5;
}



===== OnQueryStop @ 1400064b0 =====

/* long __cdecl OnQueryStop(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnQueryStop(WDFDEVICE__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = *(uint *)(lVar3 + 0x40);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 10 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
    }
  }
  return -0x3fffffff;
}



===== OnRead @ 140006640 =====

/* void __cdecl OnRead(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct SPBREQUEST__
   * __ptr64,unsigned __int64) */

void __cdecl
OnRead(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtSpbDDI_EvtSpbIoRead_Info,lVar3 + 8,param_1,(char)param_2,
                     (char)param_3,(char)param_4);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return;
}



===== OnReleaseHardware @ 140006860 =====

/* long __cdecl OnReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar4 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtReleaseHardware_Start,
                 pPVar4 + 8);
  }
  lVar3 = *(longlong *)(pPVar4 + 0x20);
  if (lVar3 != 0) {
    if (pPVar4[0x108] != (PBC_DEVICE)0x0) {
      DmaReleaseSw(pPVar4);
      lVar3 = *(longlong *)(pPVar4 + 0x20);
      pPVar4[0x108] = (PBC_DEVICE)0x0;
    }
    MmUnmapIoSpace(lVar3,*(undefined4 *)(pPVar4 + 0x28));
    *(undefined8 *)(pPVar4 + 0x20) = 0;
    *(undefined4 *)(pPVar4 + 0x28) = 0;
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtReleaseHardware_End,
                 pPVar4 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return 0;
}



===== OnSelfManagedIoCleanup @ 140006aa0 =====

/* void __cdecl OnSelfManagedIoCleanup(struct WDFDEVICE__ * __ptr64) */

void __cdecl OnSelfManagedIoCleanup(WDFDEVICE__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (*(longlong *)(lVar3 + 0x90) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(lVar3 + 0x90) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return;
}



===== OnSelfManagedIoInit @ 140006c80 =====

/* long __cdecl OnSelfManagedIoInit(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar4 == 0) {
    uVar7 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar4 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar7 = *(uint *)(lVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  puVar5 = (undefined8 *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  uVar6 = *puVar5;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xf8);
  _guard_check_icall();
  uVar6 = (*pcVar2)(WdfDriverGlobals,uVar6);
  iVar3 = PoRegisterPowerSettingCallback
                    (uVar6,&GUID_MONITOR_POWER_ON,OnMonitorPowerSettingCallback,*puVar5,
                     puVar5 + 0x12);
  if ((iVar3 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                  (uint *)&EvtPowerPoRegisterPowerSettingCallback_Error,puVar5 + 1,iVar3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  return iVar3;
}



===== OnSequence @ 140006ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned long) */

void __cdecl
OnSequence(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,ulong param_4)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  longlong lVar5;
  PBC_DEVICE *pPVar6;
  PBC_TARGET *pPVar7;
  PBC_REQUEST *pPVar8;
  uint uVar9;
  undefined1 auStackY_b8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar5 == 0) {
    uVar9 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar5 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar9 = *(uint *)(lVar5 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar6 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar7 = (PBC_TARGET *)(*pcVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0)
  ;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar8 = (PBC_REQUEST *)
           (*pcVar2)(WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_1400220c8);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtSpbDDI_EvtSpbIoSequence_Info,pPVar6 + 8,param_1,(char)param_2,
                     (char)param_3,(char)param_4);
  }
  memset(local_68,0,0x20);
  pcVar2 = DAT_140022528;
  local_68[0] = 0x20;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar8 = param_3;
  *(undefined8 *)(pPVar8 + 0x18) = 0;
  *(undefined4 *)(pPVar8 + 0x10) = 0;
  *(undefined4 *)(pPVar8 + 8) = local_64;
  *(ulong *)(pPVar8 + 0xc) = param_4;
  pPVar8[0x24] = (PBC_REQUEST)0x0;
  lVar4 = PbcRequestValidate(pPVar6,pPVar8,pPVar7);
  if ((-1 < lVar4) && (lVar4 = PbcRequestConfigureForIndex(pPVar8,0), -1 < lVar4)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    uVar3 = *(undefined8 *)pPVar8;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0xc48);
    _guard_check_icall();
    lVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,OnCancel);
    if (-1 < lVar4) {
      *(PBC_TARGET **)(pPVar6 + 0x58) = pPVar7;
      *(PBC_REQUEST **)(pPVar7 + 0x18) = pPVar8;
      PbcRequestDoTransfer(pPVar6,pPVar8);
      if (pPVar8[0x24] == (PBC_REQUEST)0x0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        _guard_check_icall();
        (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
              ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
      }
      else {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        _guard_check_icall();
        (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        PbcRequestComplete(pPVar8,"OnSequence");
      }
      goto LAB_140007427;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtRequestFailMarkCancelable_Error,pPVar6 + 8,lVar4);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ))) || (5 < uVar9)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtRequestCompleteSynchronously_Error,pPVar6 + 8,param_1,(char)param_3
                     ,3,(char)lVar4);
  }
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,lVar4);
LAB_140007427:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  return;
}



===== OnTargetConnect @ 140007750 =====

/* long __cdecl OnTargetConnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

long __cdecl OnTargetConnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  PBC_DEVICE *pPVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  longlong lVar5;
  PBC_DEVICE *pPVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar3)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar5 == 0) {
    uVar8 = 0xf0;
  }
  else {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar5 = (*pcVar3)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar8 = *(uint *)(lVar5 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)))))
       ) || (5 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar8);
  }
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar6 = (PBC_DEVICE *)(*pcVar3)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  puVar7 = (undefined8 *)(*pcVar3)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0)
  ;
  pPVar1 = pPVar6 + 8;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   (uint *)&EvtSpbDDI_EvtSpbTargetConnect_Info,pPVar1,param_1,(char)param_2);
  }
  pcVar3 = DAT_140022508;
  local_30 = 0;
  local_28 = (void *)0x0;
  local_38 = 0x18;
  _guard_check_icall();
  (*pcVar3)(SpbDriverGlobals,param_2,&local_38);
  lVar4 = PbcTargetGetSettings(pPVar6,local_28,(PBC_TARGET_SETTINGS *)(puVar7 + 1));
  if (lVar4 < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtControllerConnect_Error,
                    pPVar1,lVar4);
    }
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtControllerConnect_Info
                      ,pPVar1,*(undefined2 *)((longlong)puVar7 + 0xc),
                      (char)*(undefined4 *)(puVar7 + 1),(char)*(undefined4 *)(puVar7 + 2));
    }
    puVar7[3] = 0;
    *puVar7 = param_2;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
       (((((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2))))
        || (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
      (((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5))))
       || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar8);
  }
  return lVar4;
}



===== OnTargetDisconnect @ 140007a40 =====

/* void __cdecl OnTargetDisconnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

void __cdecl OnTargetDisconnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar5 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   (uint *)&EvtSpbDDI_EvtSpbTargetDisconnect_Info,lVar3 + 8,param_1,(char)param_2);
  }
  if ((lVar4 != 0) && ((Intel_iaLPSS2_I2CEnableBits & 2) != 0)) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtControllerDisconnect_Info,
                  lVar3 + 8,*(undefined2 *)(lVar4 + 0xc));
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar5);
  }
  return;
}



===== OnWrite @ 140007c90 =====

/* void __cdecl OnWrite(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
OnWrite(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar4 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar4 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtSpbDDI_EvtSpbIoWrite_Info,lVar3 + 8,param_1,(char)param_2,
                     (char)param_3,(char)param_4);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return;
}



===== PbcFailDevice @ 140007eac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcFailDevice(struct PBC_DEVICE * __ptr64) */

void __cdecl PbcFailDevice(PBC_DEVICE *param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtDeviceFail_Error,
                 param_1 + 8);
  }
  DumpAllRegisters(param_1);
  uStack_24 = 2;
  uStack_34 = 2;
  uStack_30 = 2;
  uStack_2c = 2;
  uStack_28 = 2;
  local_38 = 0x1c;
  local_20 = 2;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xe0);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)param_1,&local_38);
  uStack_2c = 1;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xe8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)param_1,&local_38);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x2b8);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)param_1,2);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3);
  }
  return;
}



===== PbcRequestComplete @ 1400080d4 =====

/* void __cdecl PbcRequestComplete(struct PBC_REQUEST * __ptr64,char * __ptr64 const) */

void __cdecl PbcRequestComplete(PBC_REQUEST *param_1,char *param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  
  pcVar2 = DAT_140022520;
  uVar4 = *(undefined8 *)param_1;
  _guard_check_icall();
  uVar4 = (*pcVar2)(SpbDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar2)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022520;
  if (lVar5 == 0) {
    uVar7 = 0xf0;
  }
  else {
    uVar4 = *(undefined8 *)param_1;
    _guard_check_icall();
    uVar4 = (*pcVar2)(SpbDriverGlobals,uVar4);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar5 = (*pcVar2)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar7 = *(uint *)(lVar5 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  pcVar2 = DAT_140022520;
  uVar4 = *(undefined8 *)param_1;
  _guard_check_icall();
  uVar4 = (*pcVar2)(SpbDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar2)(WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022520;
  if (*(int *)(param_1 + 0x20) < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140008307;
    uVar4 = *(undefined8 *)param_1;
    _guard_check_icall();
    uVar3 = (*pcVar2)(SpbDriverGlobals,uVar4);
    puVar6 = (uint *)&EvtRequestComplete_Error;
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) == 0) goto LAB_140008307;
    uVar4 = *(undefined8 *)param_1;
    _guard_check_icall();
    uVar3 = (*pcVar2)(SpbDriverGlobals,uVar4);
    puVar6 = (uint *)&EvtRequestComplete_Info;
  }
  McTemplateK0sppxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar6,lVar5 + 8,param_2,uVar3,
                    (char)*(undefined8 *)param_1,(char)*(undefined8 *)(param_1 + 0x18),
                    (char)*(undefined4 *)(param_1 + 0x20));
LAB_140008307:
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x898);
  _guard_check_icall();
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)param_1,*(undefined8 *)(param_1 + 0x18));
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x20));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  return;
}



===== PbcRequestConfigureForIndex @ 1400083e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureForIndex(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex(PBC_REQUEST *param_1,ulong param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  long lVar6;
  uint uVar7;
  undefined1 auStackY_b8 [32];
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  pcVar2 = DAT_140022520;
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar3 = *(undefined8 *)param_1;
  _guard_check_icall();
  uVar3 = (*pcVar2)(SpbDriverGlobals,uVar3);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022520;
  if (lVar4 == 0) {
    uVar7 = 0xf0;
  }
  else {
    uVar3 = *(undefined8 *)param_1;
    _guard_check_icall();
    uVar3 = (*pcVar2)(SpbDriverGlobals,uVar3);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar7 = *(uint *)(lVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  pcVar2 = DAT_140022520;
  lVar6 = 0;
  uVar3 = *(undefined8 *)param_1;
  _guard_check_icall();
  uVar3 = (*pcVar2)(SpbDriverGlobals,uVar3);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  pcVar2 = DAT_140022518;
  uVar3 = *(undefined8 *)param_1;
  _guard_check_icall();
  uVar3 = (*pcVar2)(SpbDriverGlobals,uVar3);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0);
  pcVar2 = DAT_140022530;
  local_50 = 0;
  local_48 = 0;
  local_58 = 0x18;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,*(undefined8 *)param_1,param_2,&local_58);
  if (local_58._4_4_ == 1) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x58) = local_68;
    *(undefined8 *)(param_1 + 0x30) = local_50;
  }
  else {
    if (local_58._4_4_ != 2) {
      if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
        McTemplateK0hqqqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                           (uint *)&EvtRequestConfigured_Error,lVar4 + 8,
                           *(undefined2 *)(lVar5 + 0xc),(char)param_2,
                           (char)*(undefined4 *)(param_1 + 0xc),(char)*(undefined4 *)(param_1 + 100)
                           ,(char)*(undefined4 *)(param_1 + 8),(char)local_50);
      }
      lVar6 = -0x3ffffff3;
      goto LAB_140008769;
    }
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x50) = local_68;
    *(undefined8 *)(param_1 + 0x28) = local_50;
  }
  *(undefined8 *)(param_1 + 0x38) = local_50;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(int *)(param_1 + 100) = local_58._4_4_;
  *(undefined4 *)(param_1 + 0x68) = (undefined4)local_48;
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
    McTemplateK0hqqqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                       (uint *)&EvtRequestConfigured_Info,lVar4 + 8,*(undefined2 *)(lVar5 + 0xc),
                       (char)param_2,(char)*(undefined4 *)(param_1 + 0xc),
                       (char)((ulonglong)local_58 >> 0x20),(char)*(int *)(param_1 + 8),
                       (char)local_50);
  }
LAB_140008769:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar7);
  }
  return lVar6;
}



===== PbcRequestConfigureForNonSequence @ 14000881c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcRequestConfigureForNonSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ *
   __ptr64,struct SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
PbcRequestConfigureForNonSequence
          (WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  longlong lVar5;
  PBC_DEVICE *pPVar6;
  PBC_TARGET *pPVar7;
  PBC_REQUEST *pPVar8;
  uint uVar9;
  undefined1 auStackY_a8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar5 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar5 == 0) {
    uVar9 = 0xf0;
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar5 = (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar6 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar7 = (PBC_TARGET *)(*pcVar2)(WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220a0)
  ;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar8 = (PBC_REQUEST *)
           (*pcVar2)(WdfDriverGlobals,param_3,PTR__WDF_PBC_REQUEST_TYPE_INFO_1400220c8);
  memset(local_68,0,0x20);
  pcVar2 = DAT_140022528;
  local_68[0] = 0x20;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar8 = param_3;
  *(undefined4 *)(pPVar8 + 8) = local_64;
  *(undefined4 *)(pPVar8 + 0x60) = local_60;
  *(undefined8 *)(pPVar8 + 0x18) = 0;
  *(undefined8 *)(pPVar8 + 0xc) = 1;
  pPVar8[0x24] = (PBC_REQUEST)0x0;
  lVar4 = PbcRequestValidate(pPVar6,pPVar8,pPVar7);
  if ((-1 < lVar4) &&
     (lVar4 = PbcRequestConfigureForIndex(pPVar8,*(ulong *)(pPVar8 + 0x10)), -1 < lVar4)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    uVar3 = *(undefined8 *)pPVar8;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0xc48);
    _guard_check_icall();
    lVar4 = (*pcVar2)(WdfDriverGlobals,uVar3,OnCancel);
    if (-1 < lVar4) {
      if (*(int *)(pPVar8 + 0x60) == 1) {
        *(PBC_TARGET **)(pPVar6 + 0x58) = pPVar7;
      }
      *(PBC_REQUEST **)(pPVar7 + 0x18) = pPVar8;
      PbcRequestDoTransfer(pPVar6,pPVar8);
      if (pPVar8[0x24] == (PBC_REQUEST)0x0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        _guard_check_icall();
        (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
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
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
      }
      else {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
        _guard_check_icall();
        (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                   &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
        }
        PbcRequestComplete(pPVar8,"PbcRequestConfigureForNonSequence");
      }
      goto LAB_140008d30;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtRequestFailMarkCancelable_Error,pPVar6 + 8,lVar4);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ) || (5 < uVar9)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
         ((((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
    }
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtRequestCompleteSynchronously_Error,pPVar6 + 8,param_1,(char)param_3
                     ,(char)*(undefined4 *)(pPVar8 + 8),(char)lVar4);
  }
  pcVar2 = DAT_140022538;
  _guard_check_icall();
  (*pcVar2)(SpbDriverGlobals,param_3,lVar4);
LAB_140008d30:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
       || ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar9);
  }
  return;
}



===== PbcRequestDoTransfer @ 140009060 =====

/* void __cdecl PbcRequestDoTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestDoTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  long lVar5;
  uint uVar6;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar6);
  }
  uVar1 = *(uint *)(param_2 + 0x68);
  if (uVar1 == 0) {
    lVar5 = ControllerConfigureForTransfer(param_1,param_2);
    if ((lVar5 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    (uint *)&EvtRequestFailToConfigure_Error,param_1 + 8,lVar5);
    }
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,(uint *)&EvtTransferDelay_Info,
                       param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),
                       (char)uVar1);
      uVar1 = *(uint *)(param_2 + 0x68);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x80);
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x9f8);
    _guard_check_icall();
    cVar4 = (*pcVar3)(WdfDriverGlobals,uVar2,(ulonglong)uVar1 * -10);
    if (cVar4 == '\x01') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))
           ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
                 (((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
                   (((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)))) ||
                  ((((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)) || (5 < uVar6)))))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                 &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar6);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar6);
  }
  return;
}



===== PbcRequestValidate @ 1400092e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestValidate(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,struct
   PBC_TARGET * __ptr64) */

long __cdecl PbcRequestValidate(PBC_DEVICE *param_1,PBC_REQUEST *param_2,PBC_TARGET *param_3)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  uVar1 = *(uint *)(param_2 + 0xc);
  lVar5 = 0;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      pcVar2 = DAT_140022530;
      local_50 = 0;
      local_48 = 0;
      local_58 = 0x18;
      _guard_check_icall();
      (*pcVar2)(SpbDriverGlobals,*(undefined8 *)param_2,uVar3,&local_58);
      if (0xffff < local_50 - 1U) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0hqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                           (uint *)&EvtTransferLength_Error,param_1 + 8,
                           *(undefined2 *)(param_3 + 0xc),(char)uVar3,(char)uVar1,(char)local_50);
        }
        lVar5 = -0x3ffffff3;
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar4);
  }
  return lVar5;
}



===== PbcTargetGetSettings @ 1400094ec =====

/* long __cdecl PbcTargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl PbcTargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  undefined2 uVar1;
  uint *puVar2;
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
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3);
  }
  lVar4 = 0;
  if (*(uint *)((longlong)param_2 + 4) < 0xc) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtTargetInvalidPropertiesLenght_Error,param_1 + 8,
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
                    &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3,(char)param_2 + '\b',
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
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_14000992a;
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
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_14000992a;
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
            ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))) goto LAB_14000992a;
        uVar1 = 0x5c;
      }
      else {
        if ((uVar5 != 1400000) && (uVar5 != 3400000)) {
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            puVar2 = (uint *)&EvtTargetInvalidConnectionSpeed_Error;
            goto LAB_140009613;
          }
          goto LAB_1400095e5;
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
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_14000992a;
        uVar1 = 0x5d;
      }
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
               &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3);
      goto LAB_14000992a;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      uVar5 = (uint)*(byte *)((longlong)param_2 + 0xd);
      puVar2 = (uint *)&EvtTargetInvalidBusType_Error;
LAB_140009613:
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar2,param_1 + 8,uVar5);
    }
  }
LAB_1400095e5:
  lVar4 = -0x3ffffff3;
LAB_14000992a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      ((((((((uVar5 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || (((uVar5 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
         (((uVar5 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
        ((((uVar5 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar3 == 5))))
        )) || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
             &WPP_6edcb477f37237231a4e6d6fe50d85a9_Traceguids,uVar3);
  }
  return lVar4;
}



===== McTemplateK0h @ 1400099c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0h(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4)

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
  McGenEventWriteKM(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0hqq @ 140009a18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0hqqq @ 140009a88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0hqqqqx @ 140009b14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqqqx(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
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
  McGenEventWriteKM(param_1,param_2,param_3,7,local_88);
  return;
}



===== McTemplateK0hqqx @ 140009bc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqx(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0hqx @ 140009c4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqx(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0pp @ 140009cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pp(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0ppp @ 140009d28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppp(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0pppq @ 140009da0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0pppx @ 140009e2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppx(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0pppxxq @ 140009eb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppxxq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
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
  McGenEventWriteKM(param_1,param_2,param_3,7,local_88);
  return;
}



===== McTemplateK0ppqq @ 140009f64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0qq @ 140009ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0qqq @ 14000a058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qxq @ 14000a0c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qxqp @ 14000a134 =====

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



===== McTemplateK0qxqq @ 14000a1c0 =====

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



===== McTemplateK0sppxq @ 14000a24c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sppxq(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,6,local_78);
  return;
}



===== WPP_SF_ddd @ 14000a310 =====

void WPP_SF_ddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dD @ 14000a3a8 =====

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_dqDD @ 14000a428 =====

void WPP_SF_dqDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== ControllerAcknowledgeInterrupts @ 14000a4d4 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
    goto LAB_14000ae03;
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
                 &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
    }
    if ((((((param_2 >> 0xd & 1) == 0) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control))
         || (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 5)) ||
       (((((((uVar1 & 0x800) == 0 || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1))))
          && (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))) &&
         (((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)))) &&
        (((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) && (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))
          ) && (uVar5 < 6)))))) goto LAB_14000ae03;
    uVar4 = 0x75;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
LAB_14000ae03:
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar5);
  }
  return;
}



===== ControllerCompleteTransfer @ 14000af68 =====

/* void __cdecl ControllerCompleteTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned char) */

void __cdecl ControllerCompleteTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2,uchar param_3)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  uchar uVar5;
  long lVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  PBC_REQUEST PVar11;
  PBC_REQUEST PVar10;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
  }
  uVar2 = *(undefined8 *)(param_1 + 0x88);
  pcVar3 = *(code **)(WdfFunctions_01015 + 0xa00);
  _guard_check_icall();
  cVar4 = (*pcVar3)(WdfDriverGlobals,uVar2,0);
  if (((((cVar4 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
  }
  if (param_1[0x119] != (PBC_DEVICE)0x0) {
    uVar5 = DmaCheckBusy(param_1,1);
    if (uVar5 == '\x01') {
      uVar5 = DmaTxComplete(param_1,param_2,3);
      if (uVar5 == '\0') {
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
        }
      }
    }
    uVar5 = DmaCheckBusy(param_1,0);
    if (uVar5 == '\x01') {
      uVar5 = DmaRxComplete(param_1,param_2,3);
      if (uVar5 == '\0') {
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
        }
      }
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),0);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0hqqxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                      (uint *)&EvtControllerProcessingEnd_Info,param_1 + 8,
                      *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
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
      lVar6 = PbcRequestConfigureForIndex(param_2,*(uint *)(param_2 + 0x10));
      *(long *)(param_2 + 0x20) = lVar6;
      if (-1 < lVar6) {
        PbcRequestDoTransfer(param_1,param_2);
        goto LAB_14000b5e1;
      }
    }
  }
  PVar11 = (PBC_REQUEST)0x1;
  PVar10 = (PBC_REQUEST)0x1;
  if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ) || (5 < uVar9)))))) {
      uVar8 = 0x5a;
      iVar7 = -0x3ffffee0;
LAB_14000b54a:
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9,(char)iVar7);
    }
  }
  else {
    uVar2 = *(undefined8 *)param_2;
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x800);
    _guard_check_icall();
    iVar7 = (*pcVar3)(WdfDriverGlobals,uVar2);
    if (iVar7 < 0) {
      if (iVar7 == -0x3ffffee0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
        }
        PVar10 = (PBC_REQUEST)0x0;
      }
      else {
        PVar10 = PVar11;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
             ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9,(char)iVar7);
        }
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
      uVar8 = 0x59;
      goto LAB_14000b54a;
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
    param_2[0x24] = PVar10;
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
LAB_14000b5e1:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar9);
  }
  return;
}



===== ControllerConfigureForTransfer @ 14000b680 =====

/* long __cdecl ControllerConfigureForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ControllerConfigureForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  uchar uVar6;
  byte bVar7;
  PBC_REQUEST PVar8;
  undefined1 uVar9;
  char cVar10;
  ulong uVar11;
  char *pcVar12;
  HWREG<unsigned_long> *this;
  undefined2 uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  long lVar18;
  
  uVar16 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar16 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar15 >> 0xb & 1) != 0 && (uVar16 == 0)) ||
         (((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)))) ||
        (((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)))) ||
       (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))) ||
      (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
        (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16);
  }
  lVar18 = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar15 >> 0xb & 1) != 0 && (uVar16 == 0)) ||
        ((((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)) ||
         (((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)))))) ||
       ((((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)) ||
        ((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
         (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))))))) || (5 < uVar16)))) {
    iVar2 = *(int *)(param_2 + 0x60);
    pcVar12 = "UNKNOWN";
    if (iVar2 == 0) {
      pcVar17 = "Invalid ";
    }
    else if (iVar2 == 1) {
      pcVar17 = "Single";
    }
    else if (iVar2 == 2) {
      pcVar17 = "First";
    }
    else if (iVar2 == 3) {
      pcVar17 = "Continue";
    }
    else if (iVar2 == 4) {
      pcVar17 = "Last";
    }
    else {
      pcVar17 = "UNKNOWN";
      if (iVar2 == 5) {
        pcVar17 = "Max";
      }
    }
    iVar2 = *(int *)(param_2 + 8);
    if (iVar2 == 0) {
      pcVar12 = "Undefined ";
    }
    else if (iVar2 == 1) {
      pcVar12 = "Read";
    }
    else if (iVar2 == 2) {
      pcVar12 = "Write";
    }
    else if (iVar2 == 3) {
      pcVar12 = "Sequence";
    }
    else if (iVar2 == 4) {
      pcVar12 = "LockCtrl";
    }
    else if (iVar2 == 5) {
      pcVar12 = "UnlockCtrl";
    }
    else if (iVar2 == 6) {
      pcVar12 = "LockConn";
    }
    else if (iVar2 == 7) {
      pcVar12 = "UnlockConn";
    }
    else if (iVar2 == 8) {
      pcVar12 = "Other";
    }
    else if (iVar2 == 9) {
      pcVar12 = "Max";
    }
    WPP_SF_dss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16,pcVar12,pcVar17);
  }
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x58) + 0xc);
  if ((*(int *)(param_2 + 0x60) - 1U < 2) || (*(int *)(param_1 + 0x104) == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar15 >> 0xb & 1) != 0 && (uVar16 == 0)) ||
         ((((((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)) ||
            (((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)))) ||
           (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))) ||
          (((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)))))) ||
        ((((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)) || (5 < uVar16)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16);
    }
    uVar6 = IsI2CBusFree(param_1,"I2C Status before first transfer");
    if (uVar6 != '\0') {
      LOCK();
      UNLOCK();
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),0);
      uVar11 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      uVar15 = 0;
      bVar7 = (byte)uVar11 & 1;
      if ((uVar11 & 1) != 0) {
        do {
          if (9 < uVar15) break;
          KeStallExecutionProcessor(0x19);
          uVar11 = HWREG<unsigned_long>::Read
                             ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
          uVar15 = uVar15 + 1;
          bVar7 = (byte)uVar11 & 1;
        } while ((uVar11 & 1) != 0);
        if (bVar7 != 0) {
          *(undefined4 *)(param_2 + 0x20) = 0xc000036b;
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            puVar14 = (uint *)&EvtControllerTimeoutDisabling_Error;
            goto LAB_14000b9f5;
          }
          goto LAB_14000c501;
        }
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x3c),0);
      uVar15 = uVar1 | 0x1000;
      if (*(int *)(*(longlong *)(param_1 + 0x58) + 8) != 1) {
        uVar15 = (uint)uVar1;
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 4),uVar15);
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
        uVar11 = *(ulong *)(param_1 + 0xb0);
LAB_14000bcd8:
        this = (HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xa0);
LAB_14000bce3:
        HWREG<unsigned_long>::Write(this,uVar11);
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
          uVar11 = *(ulong *)(param_1 + 0xc4);
          goto LAB_14000bcd8;
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
          uVar11 = *(ulong *)(param_1 + 0xd8);
          goto LAB_14000bcd8;
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
          uVar11 = *(ulong *)(param_1 + 0xec);
          this = (HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xa4);
          goto LAB_14000bce3;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 4) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar15 >> 0xb & 1) != 0 && (uVar16 == 0)) ||
             (((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)))) ||
            (((((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)) ||
              (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))) ||
             (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
               (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16,(char)iVar2);
        }
      }
      LOCK();
      UNLOCK();
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),1);
      uVar11 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      bVar7 = (byte)uVar11 & 1;
      uVar15 = 0;
      if ((uVar11 & 1) == 0) {
        do {
          if (9 < uVar15) break;
          KeStallExecutionProcessor(0x19);
          uVar11 = HWREG<unsigned_long>::Read
                             ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
          uVar15 = uVar15 + 1;
          bVar7 = (byte)uVar11 & 1;
        } while ((uVar11 & 1) == 0);
        if (bVar7 == 0) {
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                            (uint *)&EvtControllerTimeoutEnabling_Error,param_1 + 8,
                            *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                            (char)*(undefined4 *)(param_2 + 0x10),
                            (char)*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0x20) = 0xc000036b;
          goto LAB_14000c501;
        }
      }
      *(undefined4 *)(param_1 + 0x104) = 1;
      goto LAB_14000bd8e;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      puVar14 = (uint *)&EvtControllerBusBusy_Error;
LAB_14000b9f5:
      McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar14,param_1 + 8,
                      *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                      (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
    }
LAB_14000c501:
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0hqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                       (uint *)&EvtControllerConfiguration_Error,param_1 + 8,
                       *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),1)
      ;
    }
    ControllerCompleteTransfer(param_1,param_2,'\x01');
    lVar18 = -0x3fffffff;
    goto LAB_14000c555;
  }
LAB_14000bd8e:
  uVar11 = HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x54));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar15 & 0x800) != 0 && (uVar16 == 0)) ||
       ((((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)) ||
        (((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)))))) ||
      ((((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)) ||
       (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
         (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))))) {
    WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16,(char)uVar11,
               (char)*(undefined4 *)(param_1 + 0x9c));
  }
  *(undefined4 *)(param_1 + 0x9c) = 0;
  if ((*(int *)(param_2 + 0x60) == 4) || (*(int *)(param_2 + 0x60) == 1)) {
    PVar8 = (PBC_REQUEST)0x1;
  }
  else {
    PVar8 = (PBC_REQUEST)0x0;
  }
  param_2[0x78] = PVar8;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar15 & 0x800) != 0 && (uVar16 == 0)) || (((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1))))
        || ((((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)) ||
            (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))))) ||
       ((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
        (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))))) || (5 < uVar16)))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16,
              param_2[0x78] != (PBC_REQUEST)0x0);
  }
  lVar3 = *(longlong *)(param_1 + 0x38);
  uVar11 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 8));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 8),uVar11 & 0xffffffef);
  HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x24));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar15 & 0x800) != 0 && (uVar16 == 0)) ||
      (((((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)) ||
        ((((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)) ||
         (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))))) ||
       (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
         (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16);
  }
  uVar11 = HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar15 & 0x800) != 0 && (uVar16 == 0)) ||
      ((((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)) ||
       (((((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)) ||
         (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))) ||
        (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
          (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16,(char)uVar11);
  }
  if (*(int *)(param_2 + 100) == 2) {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      uVar9 = (undefined1)*(undefined8 *)(param_2 + 0x28);
      puVar14 = (uint *)&EvtControllerConfiguredWrite_Info;
LAB_14000c049:
      McTemplateK0hqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar14,param_1 + 8,
                       *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),
                       uVar9);
    }
  }
  else {
    if (*(int *)(param_2 + 100) != 1) {
      if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtControllerConfiguredOther_Error,param_1 + 8,
                        *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
      goto LAB_14000c501;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      uVar9 = (undefined1)*(undefined8 *)(param_2 + 0x30);
      puVar14 = (uint *)&EvtControllerConfiguredRead_Info;
      goto LAB_14000c049;
    }
  }
  CheckTransferForDmaOperation(param_1,param_2);
  if (*(int *)(param_2 + 100) == 2) {
    if (param_1[0x119] == (PBC_DEVICE)0x0) {
LAB_14000c388:
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtControllerPioProcessing_Info,param_1 + 8,
                        *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),0);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals);
      ControllerDisableInterrupts(param_1);
      ControllerAcknowledgeInterrupts(param_1,0xffffffff);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      LOCK();
      *(undefined4 *)(param_1 + 0x68) = 0x242;
      UNLOCK();
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 0x100;
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x470);
      _guard_check_icall();
      cVar10 = (*pcVar4)(WdfDriverGlobals,uVar5);
      if (((((cVar10 != '\0') || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
           (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
         (((((uVar15 & 0x800) == 0 || (uVar16 != 0)) &&
           ((((uVar15 >> 0xc & 1) == 0 || (uVar16 != 1)) &&
            (((uVar15 >> 0xd & 1) == 0 || (uVar16 != 2)))))) &&
          ((((uVar15 >> 0xe & 1) == 0 || (uVar16 != 3)) &&
           (((((uVar15 >> 0xf & 1) == 0 || (uVar16 != 4)) &&
             (((uVar15 >> 0x10 & 1) == 0 || (uVar16 != 5)))) && (uVar16 < 6))))))))
      goto LAB_14000c1e3;
      uVar13 = 0x1b;
    }
    else {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        (uint *)&EvtControllerDmaProcessing_Info,param_1 + 8,
                        *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),2);
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x8c),0);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals);
      ControllerDisableInterrupts(param_1);
      ControllerAcknowledgeInterrupts(param_1,0xffffffff);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      LOCK();
      *(undefined4 *)(param_1 + 0x68) = 0x1010242;
      UNLOCK();
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 1;
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x470);
      _guard_check_icall();
      cVar10 = (*pcVar4)(WdfDriverGlobals,uVar5);
      if (((((cVar10 != '\0') || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
           (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
         (((((((uVar15 & 0x800) == 0 || (uVar16 != 0)) &&
             (((uVar15 >> 0xc & 1) == 0 || (uVar16 != 1)))) &&
            (((uVar15 >> 0xd & 1) == 0 || (uVar16 != 2)))) &&
           (((uVar15 >> 0xe & 1) == 0 || (uVar16 != 3)))) &&
          (((((uVar15 >> 0xf & 1) == 0 || (uVar16 != 4)) &&
            (((uVar15 >> 0x10 & 1) == 0 || (uVar16 != 5)))) && (uVar16 < 6)))))) goto LAB_14000c1e3;
      uVar13 = 0x19;
    }
LAB_14000c1d0:
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16);
  }
  else {
    if ((*(int *)(param_2 + 100) != 1) || (param_1[0x119] == (PBC_DEVICE)0x0)) goto LAB_14000c388;
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                      (uint *)&EvtControllerDmaProcessing_Info,param_1 + 8,
                      *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                      (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),3);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x8c),0);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x90),0);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
    _guard_check_icall();
    (*pcVar4)(WdfDriverGlobals);
    ControllerDisableInterrupts(param_1);
    ControllerAcknowledgeInterrupts(param_1,0xffffffff);
    *(undefined4 *)(param_1 + 0x6c) = 0;
    LOCK();
    *(undefined4 *)(param_1 + 0x68) = 0x5000042;
    UNLOCK();
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 0x11;
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x470);
    _guard_check_icall();
    cVar10 = (*pcVar4)(WdfDriverGlobals,uVar5);
    if (((((cVar10 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar15 & 0x800) != 0 && (uVar16 == 0)) || (((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)))
          ) || ((((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)) ||
                (((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)))))) ||
        (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
          (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))) {
      uVar13 = 0x1a;
      goto LAB_14000c1d0;
    }
  }
LAB_14000c1e3:
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x488);
  _guard_check_icall();
  (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
LAB_14000c555:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar15 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar15 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar15 >> 0xb & 1) != 0 && (uVar16 == 0)) ||
        (((uVar15 >> 0xc & 1) != 0 && (uVar16 == 1)))) ||
       (((uVar15 >> 0xd & 1) != 0 && (uVar16 == 2)))) ||
      ((((uVar15 >> 0xe & 1) != 0 && (uVar16 == 3)) ||
       (((((uVar15 >> 0xf & 1) != 0 && (uVar16 == 4)) ||
         (((uVar15 >> 0x10 & 1) != 0 && (uVar16 == 5)))) || (5 < uVar16)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar16);
  }
  return lVar18;
}



===== ControllerDisableInterrupts @ 14000c5f8 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
  }
  return;
}



===== ControllerDoRead @ 14000c76c =====

/* long __cdecl ControllerDoRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  long lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
       (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7);
  }
  lVar8 = 0;
  uVar2 = *(ulonglong *)(param_2 + 0x38);
  uVar9 = *(ulonglong *)(param_2 + 0x48);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x78))
  ;
  uVar10 = (ulonglong)uVar3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    uVar6 = uVar2 - uVar9;
    in_stack_ffffffffffffffb8 = uVar10;
    if (uVar6 < uVar10) {
      in_stack_ffffffffffffffb8 = uVar6;
    }
    WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7,
               (char)in_stack_ffffffffffffffb8,(char)uVar9);
  }
  for (; (uVar9 < uVar2 && ((int)uVar10 != 0)); uVar10 = (ulonglong)((int)uVar10 - 1)) {
    uVar3 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x10));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar1 < '\0' &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      in_stack_ffffffffffffffb8 = uVar9;
      WPP_SF_dqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                  &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7,(char)uVar9,
                  (char)*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),(char)uVar3);
    }
    lVar8 = -0x3ffffffc;
    if (uVar9 < *(ulonglong *)(param_2 + 0x30)) {
      uVar6 = uVar9;
      for (puVar5 = *(undefined8 **)(param_2 + 0x58); puVar5 != (undefined8 *)0x0;
          puVar5 = (undefined8 *)*puVar5) {
        if (uVar6 < *(uint *)(puVar5 + 5)) {
          if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
            in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
            lVar4 = MmMapLockedPagesSpecifyCache(puVar5,0,1,0,in_stack_ffffffffffffffb8,0x40000010);
          }
          else {
            lVar4 = puVar5[3];
          }
          if (lVar4 != 0) {
            *(char *)(lVar4 + uVar6) = (char)uVar3;
            lVar8 = 0;
          }
          break;
        }
        uVar6 = uVar6 - *(uint *)(puVar5 + 5);
      }
    }
    if (lVar8 < 0) break;
    *(longlong *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + 1;
    uVar9 = uVar9 + 1;
  }
  *(ulonglong *)(param_2 + 0x48) = uVar9;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
        (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3))))
      || (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7);
  }
  return lVar8;
}



===== ControllerDoReadPrepare @ 14000cab4 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7);
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
    WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7,(char)uVar9,(char)uVar1);
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
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7,(char)uVar9,
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar7);
  }
  return 0;
}



===== ControllerDoWrite @ 14000ce30 =====

/* long __cdecl ControllerDoWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ulonglong uVar1;
  ulong uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  char *pcVar11;
  long lVar12;
  byte local_res8;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar7 & 0x800) != 0 && (uVar6 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (((((uVar7 >> 0xd & 1) != 0 && (uVar6 == 2)) || (((uVar7 >> 0xe & 1) != 0 && (uVar6 == 3))))
       || (((((uVar7 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
            (((uVar7 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar6);
  }
  lVar12 = 0;
  uVar1 = *(ulonglong *)(param_2 + 0x38);
  uVar10 = *(ulonglong *)(param_2 + 0x40);
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x74))
  ;
  uVar7 = 0x40 - uVar2;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar8 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar8 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar8 & 0x800) != 0 && (uVar6 == 0)) ||
      ((((((uVar8 >> 0xc & 1) != 0 && (uVar6 == 1)) || (((uVar8 >> 0xd & 1) != 0 && (uVar6 == 2))))
        || (((uVar8 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
       (((((uVar8 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar8 >> 0x10 & 1) != 0 && (uVar6 == 5))))
        || (5 < uVar6)))))))) {
    in_stack_ffffffffffffffb8 = (ulonglong)uVar7;
    if (uVar1 - uVar10 < (ulonglong)uVar7) {
      in_stack_ffffffffffffffb8 = uVar1 - uVar10;
    }
    WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar6,
               (char)in_stack_ffffffffffffffb8,(char)uVar10);
  }
  if (uVar10 < uVar1) {
    local_res8 = (byte)uVar1;
    do {
      if (uVar7 == 0) break;
      lVar12 = -0x3ffffffc;
      if (uVar10 < *(ulonglong *)(param_2 + 0x28)) {
        uVar9 = uVar10;
        for (puVar5 = *(undefined8 **)(param_2 + 0x50); puVar5 != (undefined8 *)0x0;
            puVar5 = (undefined8 *)*puVar5) {
          if (uVar9 < *(uint *)(puVar5 + 5)) {
            if ((*(byte *)((longlong)puVar5 + 10) & 5) == 0) {
              in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
              lVar4 = MmMapLockedPagesSpecifyCache
                                (puVar5,0,1,0,in_stack_ffffffffffffffb8,0x40000010);
            }
            else {
              lVar4 = puVar5[3];
            }
            if (lVar4 != 0) {
              local_res8 = *(byte *)(lVar4 + uVar9);
              lVar12 = 0;
            }
            break;
          }
          uVar9 = uVar9 - *(uint *)(puVar5 + 5);
        }
      }
      if (lVar12 < 0) break;
      uVar8 = local_res8 | 0x400;
      if (uVar10 != 0) {
        uVar8 = (uint)local_res8;
      }
      if ((param_2[0x78] != (PBC_REQUEST)0x0) && (uVar1 - uVar10 == 1)) {
        uVar8 = uVar8 | 0x200;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar3 < '\0')) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar3 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar6 == 1)))
           ) || (((((uVar3 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
                  (((uVar3 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
                 (((((uVar3 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
                   (((uVar3 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
        pcVar11 = " ";
        uVar3 = uVar8 & 0x600;
        if (uVar3 == 0x200) {
          pcVar11 = "| STOP";
        }
        if (uVar3 == 0x400) {
          pcVar11 = "| RESTART";
        }
        if (uVar3 == 0x600) {
          pcVar11 = "| RESTART | STOP";
        }
        in_stack_ffffffffffffffb8 = uVar10;
        WPP_SF_dPDDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                     &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar6,(char)uVar10,
                     (char)*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),(char)uVar8,pcVar11)
        ;
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x10),uVar8);
      uVar7 = uVar7 - 1;
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar1);
  }
  *(ulonglong *)(param_2 + 0x40) = uVar10;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar7 & 0x800) != 0 && (uVar6 == 0)) ||
       ((((uVar7 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
        ((((uVar7 >> 0xd & 1) != 0 && (uVar6 == 2)) || (((uVar7 >> 0xe & 1) != 0 && (uVar6 == 3)))))
        ))) || (((((uVar7 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
                 (((uVar7 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar6);
  }
  return lVar12;
}



===== ControllerEnableInterrupts @ 14000d200 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
              &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4,(char)param_2);
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
  }
  return;
}



===== ControllerGetInterruptStatus @ 14000d48c =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4,(char)uVar5,(char)param_2
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
                 &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
                  &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4,(char)uVar5,(char)param_2,
                  (char)uVar2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== ControllerInitialize @ 14000d738 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
              &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4,(char)uVar2);
  }
  uVar1 = *(uint *)(param_1 + 0x50);
  if (((uVar1 & 0xf0) != 0) || (uVar1 == 0xffffffff)) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     (uint *)&EvtControllerCapability_Error,param_1 + 8,uVar1 & 0xf0,(char)uVar1);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar4);
  }
  return lVar3;
}



===== ControllerProcessInterrupts @ 14000da40 =====

/* void __cdecl ControllerProcessInterrupts(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long,unsigned long) */

void __cdecl
ControllerProcessInterrupts(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  char cVar5;
  uchar uVar6;
  ulong uVar7;
  long lVar8;
  __uint64 _Var9;
  undefined2 uVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 uVar13;
  ulonglong uVar14;
  ulong local_res20 [2];
  
  uVar11 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar11 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))
         ) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))
        ) || (5 < uVar11)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   (uint *)&EvtControllerProcesInterrupts_Info,param_1 + 8,param_3,(char)param_4);
  }
  if ((int)param_4 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
         ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
          ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
    }
    *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
    uVar7 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
    if ((uVar7 & 1) != 0) {
      lVar12 = *(longlong *)(param_1 + 0x30);
      uVar7 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar12 + 0x6c));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar12 + 0x6c),uVar7 | 2);
      uVar3 = *(undefined8 *)(param_1 + 0x88);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x9f8);
      _guard_check_icall();
      cVar5 = (*pcVar4)(WdfDriverGlobals,uVar3,0xfffffffffd050f80);
      if (cVar5 == '\x01') {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           (((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
             ((((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
              (((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
        goto LAB_14000f511;
        uVar10 = 0x1f;
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           ((((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
              ((((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
               (((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
             ((((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)))))) &&
            ((((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6)))))) goto LAB_14000f511;
        uVar10 = 0x20;
      }
LAB_14000e6a6:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
      goto LAB_14000f511;
    }
LAB_14000ddaf:
    uVar6 = '\x01';
  }
  else {
    if (((byte)(param_4 >> 0x1e) & 1) != 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
      goto LAB_14000ddaf;
    }
    if ((param_3 >> 6 & 1) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xffffffbf;
      UNLOCK();
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           ((((((uVar1 & 0x1000) != 0 && (uVar11 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
        WPP_SF_dPD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,
                   (char)*(undefined8 *)(param_2 + 0x70),(char)*(undefined4 *)(param_1 + 0x9c));
      }
      uVar1 = *(uint *)(param_1 + 0x9c);
      if ((uVar1 >> 0x10 & 1) == 0) {
        if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
          *(undefined8 *)(param_2 + 0x70) = 0;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                (((uVar1 & 0x1000) != 0 && (uVar11 == 1)))) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
              ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                      &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,
                      (char)*(undefined4 *)(param_1 + 0x9c));
          }
        }
        else if ((uVar1 & 7) == 0) {
          if ((uVar1 & 8) == 0) {
            if ((uVar1 & 0x1000) == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((((uVar2 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                    (((uVar2 & 0x1000) != 0 && (uVar11 == 1)))) ||
                   (((uVar2 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
                  ((((uVar2 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                   (((((uVar2 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                     (((uVar2 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
                uVar10 = 0x28;
                goto LAB_14000e1f8;
              }
            }
            else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                    ((((((uVar2 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                       ((((uVar2 & 0x1000) != 0 && (uVar11 == 1)) ||
                        (((uVar2 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
                      ((((uVar2 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                       ((((uVar2 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                        (((uVar2 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
              uVar10 = 0x27;
LAB_14000e1f8:
              WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                        &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)uVar1);
            }
            *(undefined8 *)(param_2 + 0x70) = 0;
LAB_14000e215:
            *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
          }
          else {
            *(undefined4 *)(param_2 + 0x20) = 0;
            uVar7 = HWREG<unsigned_long>::Read
                              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
            *(ulonglong *)(param_2 + 0x70) = (ulonglong)(uVar7 & 0xffffff);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                 ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                  ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                   (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
              WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                        &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,
                        (char)(uVar7 & 0xffffff));
            }
          }
        }
        else {
          *(undefined8 *)(param_2 + 0x70) = 0;
          *(undefined4 *)(param_2 + 0x20) = 0xc000000e;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
               (((uVar1 & 0x1000) != 0 && (uVar11 == 1)))) ||
              (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
            uVar10 = 0x25;
            goto LAB_14000e045;
          }
        }
      }
      else {
        *(undefined8 *)(param_2 + 0x70) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             ((((uVar1 & 0x1000) != 0 && (uVar11 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
          uVar10 = 0x23;
LAB_14000e045:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
        }
      }
      goto LAB_14000ddaf;
    }
    if ((param_3 >> 1 & 1) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffd;
      UNLOCK();
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                 &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
      }
      *(undefined8 *)(param_2 + 0x70) = 0;
      *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
      goto LAB_14000ddaf;
    }
    if (((param_3 >> 2 & 1) != 0) && (*(int *)(param_2 + 100) == 1)) {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffb;
      UNLOCK();
      lVar8 = ControllerDoRead(param_1,param_2);
      if (-1 < lVar8) {
        if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x48)) {
          if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
              ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
             (((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
               ((((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
                ((((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)) &&
                 (((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)))))))) &&
              (((((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)) &&
                (((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)))) && (uVar11 < 6))))))
          goto LAB_14000f503;
          uVar13 = (undefined1)*(undefined8 *)(param_2 + 0x70);
          uVar10 = 0x2b;
LAB_14000f4f0:
          WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,uVar13);
          goto LAB_14000f503;
        }
        if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
               ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                     &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
          }
          goto LAB_14000e215;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
        }
        goto LAB_14000e581;
      }
      *(long *)(param_2 + 0x20) = lVar8;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
        uVar10 = 0x2a;
        goto LAB_14000e375;
      }
      goto LAB_14000ddaf;
    }
    if (((param_4 & 0x100) != 0) && (*(int *)(param_2 + 100) == 1)) {
LAB_14000e581:
      local_res20[0] = 0;
      lVar8 = ControllerDoReadPrepare(param_1,param_2,local_res20);
      if (-1 < lVar8) {
        if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
          if (param_2[0x78] == (PBC_REQUEST)0x1) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return;
            }
            uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
               ((((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
                  ((((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
                   (((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
                 ((((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                  (((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)))))) &&
                ((((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))
            goto LAB_14000f511;
            uVar10 = 0x2f;
            goto LAB_14000e6a6;
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                 (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
            uVar10 = 0x30;
            goto LAB_14000e723;
          }
        }
        else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                  ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                   (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
                 (((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                   ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                    (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))))) {
          uVar10 = 0x31;
LAB_14000e723:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                   &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
        }
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x38),local_res20[0] - 1
                  );
        LOCK();
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 4;
        UNLOCK();
        goto LAB_14000f511;
      }
      *(long *)(param_2 + 0x20) = lVar8;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
        uVar10 = 0x2e;
LAB_14000e375:
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                  &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)lVar8);
      }
      goto LAB_14000ddaf;
    }
    if (((param_3 & 0x10000) == 0) || (*(int *)(param_2 + 100) != 2)) {
      if ((((param_4 & 0x100) != 0) || ((param_3 >> 0xd & 1) != 0)) &&
         (*(int *)(param_2 + 100) == 2)) {
        LOCK();
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xffffdfff;
        UNLOCK();
        if (*(longlong *)(param_2 + 0x38) != *(longlong *)(param_2 + 0x40)) {
          lVar8 = ControllerDoWrite(param_1,param_2);
          if (lVar8 < 0) {
            *(long *)(param_2 + 0x20) = lVar8;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
               ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
                ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                   (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                  (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                    (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
                   ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                    (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))))) {
              uVar10 = 0x36;
              goto LAB_14000e375;
            }
            goto LAB_14000ddaf;
          }
          if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
            if (param_2[0x78] != (PBC_REQUEST)0x0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return;
              }
              uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
                 ((((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
                    (((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)))) &&
                   (((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)))) &&
                  (((((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                    (((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
                   ((((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
              goto LAB_14000f511;
              uVar10 = 0x37;
              goto LAB_14000e6a6;
            }
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                    (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                   (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
                 ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))) {
              uVar10 = 0x38;
              goto LAB_14000ec36;
            }
          }
          else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                  (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                    ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                     ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                      (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
                   (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                     (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
            uVar10 = 0x39;
LAB_14000ec36:
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                     &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
          }
          LOCK();
          *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 0x2000;
          UNLOCK();
          goto LAB_14000f511;
        }
        uVar7 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
        uVar14 = (ulonglong)(uVar7 & 0xffffff);
        *(ulonglong *)(param_2 + 0x70) = uVar14;
        lVar12 = *(longlong *)(param_2 + 0x38) - uVar14;
        if (lVar12 != 0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
              ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
            uVar10 = 0x34;
            goto LAB_14000e886;
          }
          goto LAB_14000e215;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
          uVar10 = 0x35;
          goto LAB_14000f4eb;
        }
        goto LAB_14000f503;
      }
      if (((param_4 >> 4 & 1) != 0) && (lVar8 = DmaRxStart(param_1,param_2), lVar8 < 0)) {
        *(long *)(param_2 + 0x20) = lVar8;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0 ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)))) ||
           (((((uVar1 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
             (((((uVar1 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
               (((uVar1 >> 0xd & 1) == 0 || (uVar11 != 2)))) &&
              (((uVar1 >> 0xe & 1) == 0 || (uVar11 != 3)))))) &&
            ((((uVar1 >> 0xf & 1) == 0 || (uVar11 != 4)) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
        goto LAB_14000ddaf;
        uVar10 = 0x3a;
        goto LAB_14000e375;
      }
      if (((param_4 & 1) != 0) && (lVar8 = DmaTxStart(param_1,param_2), lVar8 < 0)) {
        *(long *)(param_2 + 0x20) = lVar8;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)) || (5 < uVar11)))))))))) {
          uVar10 = 0x3b;
          goto LAB_14000e375;
        }
        goto LAB_14000ddaf;
      }
      if ((((param_3 & 0x1000000) != 0) || ((param_4 >> 1 & 1) != 0)) &&
         (uVar6 = DmaTxComplete(param_1,param_2,0), uVar6 == '\x01')) {
        _Var9 = DmaDataTransferred(param_1,1);
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
          WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                    &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)_Var9);
        }
        *(__uint64 *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + _Var9;
        uVar6 = DmaCheckBusy(param_1,0);
        if (uVar6 == '\0') {
          LOCK();
          *(undefined4 *)(param_1 + 0x68) = 0;
          UNLOCK();
          ControllerCompleteTransfer(param_1,param_2,'\0');
          goto LAB_14000f511;
        }
      }
      if (((((byte)(param_3 >> 0x1a) & 1) == 0) && ((param_4 >> 5 & 1) == 0)) ||
         (uVar6 = DmaRxComplete(param_1,param_2,0), uVar6 != '\x01')) {
        if ((param_3 >> 9 & 1) == 0) goto LAB_14000f511;
        if (*(int *)(param_2 + 100) == 1) {
          if (param_1[0x119] != (PBC_DEVICE)0x0) goto LAB_14000f511;
          uVar14 = *(ulonglong *)(param_2 + 0x70);
          if (*(longlong *)(param_2 + 0x38) - uVar14 != 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                  (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                 ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
              WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                         &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)uVar14,
                         (char)(*(longlong *)(param_2 + 0x38) - uVar14));
            }
            lVar8 = ControllerDoRead(param_1,param_2);
            if (lVar8 < 0) {
              *(long *)(param_2 + 0x20) = lVar8;
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                   ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                    ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                     (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
                  (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                    (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
                uVar10 = 0x40;
                goto LAB_14000e375;
              }
              goto LAB_14000ddaf;
            }
            uVar14 = *(ulonglong *)(param_2 + 0x70);
            lVar12 = *(longlong *)(param_2 + 0x38) - uVar14;
            if (lVar12 != 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                  ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                   (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                     (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
                    (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                      (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))))) {
                uVar10 = 0x41;
                goto LAB_14000e886;
              }
              goto LAB_14000e215;
            }
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
               ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
            uVar10 = 0x42;
            goto LAB_14000f4eb;
          }
          goto LAB_14000f503;
        }
        if (*(int *)(param_2 + 100) != 2) goto LAB_14000f511;
        if ((param_1[0x119] == (PBC_DEVICE)0x1) &&
           (uVar6 = DmaCheckBusy(param_1,1), uVar6 == '\x01')) {
          uVar6 = DmaTxComplete(param_1,param_2,3);
          if (uVar6 != '\x01') {
            *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
            uVar6 = '\x01';
            goto LAB_14000f50c;
          }
          _Var9 = DmaDataTransferred(param_1,1);
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                  (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))) {
            WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                      &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)_Var9);
          }
        }
        uVar7 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
        uVar14 = (ulonglong)(uVar7 & 0xffffff);
        *(ulonglong *)(param_2 + 0x70) = uVar14;
        lVar12 = *(longlong *)(param_2 + 0x38) - uVar14;
        if (lVar12 != 0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                 (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
            uVar10 = 0x44;
            goto LAB_14000e886;
          }
          goto LAB_14000e215;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
             ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))))) {
          uVar10 = 0x45;
          goto LAB_14000f4eb;
        }
        goto LAB_14000f503;
      }
      _Var9 = DmaDataTransferred(param_1,0);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))))) {
        WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                  &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)_Var9);
      }
      *(__uint64 *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + _Var9;
      uVar6 = DmaCheckBusy(param_1,1);
      if (uVar6 != '\0') {
        uVar6 = DmaTxComplete(param_1,param_2,3);
        if (uVar6 == '\x01') {
          LOCK();
          *(undefined4 *)(param_1 + 0x68) = 0;
          UNLOCK();
          goto LAB_14000f503;
        }
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            ((((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
               ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))))) {
          uVar10 = 0x3e;
          goto LAB_14000e045;
        }
        goto LAB_14000ddaf;
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x68) = 0;
      UNLOCK();
      uVar6 = '\0';
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffeffff;
      UNLOCK();
      uVar7 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
      uVar14 = (ulonglong)(uVar7 & 0xffffff);
      *(ulonglong *)(param_2 + 0x70) = uVar14;
      lVar12 = *(longlong *)(param_2 + 0x38) - uVar14;
      if (lVar12 != 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
          uVar10 = 0x32;
LAB_14000e886:
          WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                     &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11,(char)uVar14,
                     (char)lVar12);
        }
        goto LAB_14000e215;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
          (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
        uVar10 = 0x33;
LAB_14000f4eb:
        uVar13 = (undefined1)uVar14;
        goto LAB_14000f4f0;
      }
LAB_14000f503:
      uVar6 = '\0';
    }
  }
LAB_14000f50c:
  ControllerCompleteTransfer(param_1,param_2,uVar6);
LAB_14000f511:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1))))
      || (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar11);
  }
  return;
}



===== ControllerUninitialize @ 14000f5b0 =====

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
             &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar2);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar2);
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
               &WPP_83e3b9f18e8e37e6b9f9264700394c09_Traceguids,uVar2);
    }
  }
  return;
}



===== McTemplateK0hqqxq @ 14000f75c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqxq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined2 param_4,
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
  McGenEventWriteKM(param_1,param_2,param_3,6,local_78);
  return;
}



===== WPP_SF_dDDD @ 14000f7f8 =====

void WPP_SF_dDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dP @ 14000f8a0 =====

void WPP_SF_dP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_dPD @ 14000f928 =====

void WPP_SF_dPD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_dPDDs @ 14000f9c4 =====

void WPP_SF_dPDDs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_8 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_8[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_8 != (char *)0x0) {
    pcVar2 = param_8;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,&param_7,4,pcVar2,lVar4
            ,0);
  return;
}



===== WPP_SF_dPDs @ 14000fabc =====

void WPP_SF_dPDs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,char *param_7)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_7 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_7[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_7 != (char *)0x0) {
    pcVar2 = param_7;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,pcVar2,lVar4,0);
  return;
}



===== WPP_SF_dxP @ 14000fb9c =====

void WPP_SF_dxP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_dss @ 14000fc38 =====

void WPP_SF_dss(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,char *param_6)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_6 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_6[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  lVar5 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar5;
      lVar5 = lVar3 + 1;
    } while (param_5[lVar5] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar2 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar2 = param_6;
  }
  pcVar4 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar4 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar4,lVar3,pcVar2,lVar6,0);
  return;
}



===== Read @ 14000fd34 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Read(void) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Read(HWREG<unsigned_long> *this)

{
  return *(ulong *)this;
}



===== Write @ 14000fd38 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Write(unsigned long) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Write(HWREG<unsigned_long> *this,ulong param_1)

{
  *(ulong *)this = param_1;
  LOCK();
  UNLOCK();
  return param_1;
}



===== GetDefaultSettings @ 14000fd44 =====

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
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar2);
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
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar2);
  }
  return;
}



===== GetRegistrySettings @ 140010110 =====

/* void __cdecl GetRegistrySettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetRegistrySettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  uint uVar6;
  WDFKEY__ *local_res8;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar6);
  }
  puVar4 = WdfDriverGlobals;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x3b8);
  uVar3 = *WdfDriverGlobals;
  _guard_check_icall();
  iVar5 = (*pcVar2)(puVar4,uVar3,0x1f0000,0,&local_res8);
  if (iVar5 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)) || (5 < uVar6)))))))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar6,(char)iVar5);
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
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x738);
    _guard_check_icall();
    (*pcVar2)(WdfDriverGlobals,local_res8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar6);
  }
  return;
}



===== OverrideDefaultsForHardware @ 1400105e4 =====

/* void __cdecl OverrideDefaultsForHardware(struct PBC_DEVICE * __ptr64) */

void __cdecl OverrideDefaultsForHardware(PBC_DEVICE *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  PBC_DEVICE *pPVar4;
  
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
  }
  if (((*(int *)(param_1 + 0x44) == 2) && (3 < *(uint *)(param_1 + 0x40))) ||
     ((*(int *)(param_1 + 0x44) == 5 && (3 < *(uint *)(param_1 + 0x40))))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || (((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
                 (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))))) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
    }
    SetDefaultParameter(param_1,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xfc),0);
  }
  if ((*(int *)(param_1 + 0x44) == 5) && (3 < *(uint *)(param_1 + 0x40))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
    }
    SetDefaultParameter(param_1,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0),0);
  }
  if ((*(int *)(param_1 + 0x44) == 2) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))
           ))) || ((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
                   (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
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
  if ((*(int *)(param_1 + 0x44) == 5) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
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
  if (((iVar2 == 4) && (*(uint *)(param_1 + 0x48) < 0xf0)) || (iVar2 - 7U < 2)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
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
  pPVar4 = param_1 + 0xa0;
  if ((iVar2 == 5) && (*(uint *)(param_1 + 0x48) < 0xf0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))
           ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)pPVar4,1000);
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
  if ((*(int *)(param_1 + 0x44) == 4) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
        (((((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
          (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
    }
    SetDefaultParameter(param_1,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0),0);
  }
  if (*(int *)(param_1 + 0x44) == 9) {
    if (*(uint *)(param_1 + 0x48) < 0xf0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
      }
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)pPVar4,0x214);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),
                          0x281);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0x84)
      ;
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0xa1);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),
                          0x22);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),
                          0x51);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0x13)
      ;
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x29);
    }
    if ((*(int *)(param_1 + 0x44) == 9) && (0xef < *(uint *)(param_1 + 0x48))) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                 &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
      }
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)pPVar4,0xc4);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),
                          0xc9);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8)
                          ,6);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac)
                          ,6);
      SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0x2e)
      ;
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0x33);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),6);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),6);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),1);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),
                          0x10);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),
                          0x15);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0)
                          ,3);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4)
                          ,3);
      SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),1);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0x10)
      ;
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x15);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),1);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),1);
      SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),1);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
        || (5 < uVar3)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar3);
  }
  return;
}



===== ReadRegistryKeyForController @ 140011824 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ReadRegistryKeyForController(struct PBC_DEVICE * __ptr64,struct WDFKEY__ *
   __ptr64,unsigned short * __ptr64,unsigned long * __ptr64) */

void __cdecl
ReadRegistryKeyForController(PBC_DEVICE *param_1,WDFKEY__ *param_2,ushort *param_3,ulong *param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStackY_2a8 [32];
  ulong local_268 [2];
  undefined4 local_260 [2];
  undefined1 *local_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2a8;
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  local_258 = local_248;
  local_268[0] = 0;
  local_260[0] = 0x2000000;
  iVar3 = RtlUnicodeStringPrintf((_UNICODE_STRING *)local_260,(ushort *)&u__ws__u);
  if (iVar3 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))
           ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))
          ))) || (5 < uVar4)))) {
      WPP_SF_dSd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar4,(undefined *)param_3,
                 (char)iVar3);
    }
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x780);
    _guard_check_icall();
    iVar3 = (*pcVar2)(WdfDriverGlobals,param_2,local_260,local_268);
  }
  if (-1 < iVar3) {
    *param_4 = local_268[0];
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))
          ) || (5 < uVar4)))))) {
      WPP_SF_dSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar4,(undefined *)param_3,
                  (char)local_268[0],(char)local_268[0]);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 140011a08 =====

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



===== SetDefaultParameter @ 140011ab4 =====

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
                &WPP_ac6a82d3960a37669fa98a31d4ef6566_Traceguids,uVar2,(undefined *)param_2,
                (char)param_4,(char)param_4);
  }
  return;
}



===== WPP_SF_dSd @ 140011b68 =====

void WPP_SF_dSd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined *param_5,undefined1 param_6)

{
  code *pcVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (undefined *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar3 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,puVar3,lVar2,&param_6,4,0);
  return;
}



===== WPP_SF_dSdD @ 140011c38 =====

void WPP_SF_dSdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined *param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (undefined *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar3 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,puVar3,lVar2,&param_6,4,&param_7,4,0);
  return;
}



===== ControllerFinishTransfer @ 140011d1c =====

/* void __cdecl ControllerFinishTransfer(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerFinishTransfer(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  uchar uVar4;
  ulong uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar7 & 0x800) != 0 && (uVar8 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
        ((((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))))
        ) || ((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
              (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))))) || (5 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
  }
  uVar4 = IsI2CBusFree(param_1,"I2C Status (ControllerFinishTransfer)");
  if (((((uVar4 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar7 & 0x800) != 0 && (uVar8 == 0)) ||
       (((((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2))))
        || (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
      (((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5))))
       || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
  }
  uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x70))
  ;
  if ((uVar5 & 1) != 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar7 & 0x800) != 0 && (uVar8 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
        ((((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
         ((((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
          (((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
            (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
    }
    lVar2 = *(longlong *)(param_1 + 0x30);
    uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x6c));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x6c),uVar5 | 2);
    uVar5 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c));
    uVar7 = 0;
    uVar9 = uVar5 & 2;
    if (uVar9 != 0) {
      do {
        if (0x7f < uVar7) break;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
          WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8,(char)uVar7,(char)uVar9)
          ;
        }
        KeStallExecutionProcessor(100);
        uVar5 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c));
        uVar7 = uVar7 + 1;
        uVar9 = uVar5 & 2;
      } while (uVar9 != 0);
      if (((((uVar9 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
           ((((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
            (((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)))))) ||
          ((((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
           (((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
             (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
      }
    }
    KeStallExecutionProcessor(100);
    uVar5 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x70));
    if ((((((uVar5 & 1) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
        ((((((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
           ((((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
            (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
          ((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
           (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))))) || (5 < uVar8)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
    }
    uVar4 = IsI2CBusFree(param_1,"I2C Status after USER_ABORT");
    if (((((uVar4 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
         ((((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
          ((((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))
           ))))) ||
        (((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))
          ) || (5 < uVar8)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
    }
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x480);
    _guard_check_icall();
    (*pcVar3)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
    uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar5 & 0xfffffffc);
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar5 | 3);
    ControllerDisableInterrupts(param_1);
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x488);
    _guard_check_icall();
    (*pcVar3)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
    uVar4 = IsI2CBusFree(param_1,"I2C Status after CONTROLLER_RESET");
    if (((((uVar4 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
          ((((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)))
           ))) || (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
        (((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))
          ) || (5 < uVar8)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
    }
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),0);
  uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c))
  ;
  uVar9 = 0;
  uVar7 = uVar5 & 1;
  if (uVar7 == 0) {
LAB_140012368:
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 5)) ||
       ((((((uVar7 >> 0xb & 1) == 0 || (uVar8 != 0)) && (((uVar7 >> 0xc & 1) == 0 || (uVar8 != 1))))
         && (((uVar7 >> 0xd & 1) == 0 || (uVar8 != 2)))) &&
        (((((uVar7 >> 0xe & 1) == 0 || (uVar8 != 3)) &&
          ((((uVar7 >> 0xf & 1) == 0 || (uVar8 != 4)) &&
           (((uVar7 >> 0x10 & 1) == 0 || (uVar8 != 5)))))) && (uVar8 < 6)))))) goto LAB_1400123e4;
    uVar6 = 0x14;
  }
  else {
    do {
      if (9 < uVar9) break;
      KeStallExecutionProcessor(0x19);
      uVar5 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      uVar9 = uVar9 + 1;
      uVar7 = uVar5 & 1;
    } while (uVar7 != 0);
    if (uVar7 == 0) goto LAB_140012368;
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((((uVar7 >> 0xb & 1) == 0 || (uVar8 != 0)) && (((uVar7 >> 0xc & 1) == 0 || (uVar8 != 1))))
         && (((uVar7 >> 0xd & 1) == 0 || (uVar8 != 2)))) &&
        (((((uVar7 >> 0xe & 1) == 0 || (uVar8 != 3)) &&
          ((((uVar7 >> 0xf & 1) == 0 || (uVar8 != 4)) &&
           (((uVar7 >> 0x10 & 1) == 0 || (uVar8 != 5)))))) && (uVar8 < 6)))))) goto LAB_1400123e4;
    uVar6 = 0x13;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
LAB_1400123e4:
  *(undefined4 *)(param_1 + 0x104) = 0;
  uVar4 = IsI2CBusFree(param_1,"I2C Status after DISABLE");
  if (uVar4 == '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar7 & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1))))
         || (((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
        (((((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)) || (((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4))))
         || ((((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)) || (5 < uVar8)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar7 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar8 == 1))))
         || (((uVar7 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
        (((uVar7 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
       ((((uVar7 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar8 == 5)))))
       ) || (5 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar8);
  }
  return;
}



===== DebugI2CLineState @ 14001250c =====

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
                  &WPP_c456b0ffae183a023040d085c3367ab7_Traceguids,uVar6,param_3,bVar2 & 1,
                  bVar2 >> 2 & 1,pcVar7,pcVar5);
  }
  return;
}



===== IsI2CBusFree @ 1400126a4 =====

/* unsigned char __cdecl IsI2CBusFree(struct PBC_DEVICE * __ptr64,char * __ptr64) */

uchar __cdecl IsI2CBusFree(PBC_DEVICE *param_1,char *param_2)

{
  ulong uVar1;
  
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 8));
  DebugI2CLineState(param_1,uVar1,param_2);
  return (uVar1 & 0x5000000) == 0x5000000;
}



===== WPP_SF_dsddss @ 1400126f4 =====

void WPP_SF_dsddss(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  char *param_5,undefined1 param_6,undefined1 param_7,char *param_8,char *param_9)

{
  code *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_9 == (char *)0x0) {
    lVar8 = 5;
  }
  else {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (param_9[lVar7] != '\0');
    lVar8 = lVar8 + 2;
  }
  if (param_8 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar7 = lVar5;
      lVar5 = lVar7 + 1;
    } while (param_8[lVar5] != '\0');
    lVar7 = lVar7 + 2;
  }
  lVar5 = -1;
  if (param_5 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_5[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  pcVar4 = "NULL";
  if (param_9 != (char *)0x0) {
    pcVar4 = param_9;
  }
  pcVar2 = "NULL";
  if (param_8 != (char *)0x0) {
    pcVar2 = param_8;
  }
  pcVar3 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar3 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar3,lVar6,&param_6,4,&param_7,4,pcVar2,
            lVar7,pcVar4,lVar8,0);
  return;
}



===== GetAcpiHardwareInstance @ 140012850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareInstance(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareInstance(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  long lVar6;
  uint uVar7;
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
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
  }
  local_278 = 0x42696541;
  local_250 = &local_278;
  local_274 = 0x4449555f;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  *param_2 = 0xff;
  uVar4 = *(undefined8 *)param_1;
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x150);
  _guard_check_icall();
  uVar4 = (*pcVar2)(WdfDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
  _guard_check_icall();
  iVar3 = (*pcVar2)(WdfDriverGlobals,uVar4,0,0x32c004);
  if ((iVar3 < 0) || (local_240 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,(char)iVar3);
    }
    lVar6 = 0;
    goto LAB_140012cff;
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
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                    &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,(char)local_228);
        }
        goto LAB_140012cff;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) &&
            ((((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1)) &&
             (((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)))))) &&
           ((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))))) &&
          ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6)))))) goto LAB_140012cff;
      uVar5 = 0x15;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) &&
           ((((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1)) &&
            (((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)))))) &&
          (((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))) &&
           ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6)))))))) goto LAB_140012cff;
      uVar5 = 0x14;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1))))
        && ((((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6))))))))))
    goto LAB_140012cff;
    uVar5 = 0x13;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
LAB_140012cff:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
  }
  return lVar6;
}



===== GetAcpiHardwareRevision @ 140012da8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareRevision(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareRevision(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  long lVar6;
  uint uVar7;
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
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
  }
  local_278 = 0x42696541;
  local_250 = &local_278;
  local_274 = 0x5652485f;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  uVar4 = *(undefined8 *)param_1;
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x150);
  _guard_check_icall();
  uVar4 = (*pcVar2)(WdfDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
  _guard_check_icall();
  iVar3 = (*pcVar2)(WdfDriverGlobals,uVar4,0,0x32c004);
  if ((iVar3 < 0) || (local_240 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,(char)iVar3);
    }
    lVar6 = 0;
    *param_2 = 0;
    goto LAB_14001325a;
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
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,(char)local_228);
        }
        goto LAB_14001325a;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) &&
            ((((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1)) &&
             (((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)))))) &&
           ((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))))) &&
          ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6)))))) goto LAB_14001325a;
      uVar5 = 0xe;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) &&
           ((((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1)) &&
            (((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)))))) &&
          (((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))) &&
           ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6)))))))) goto LAB_14001325a;
      uVar5 = 0xd;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar1 >> 0xb & 1) == 0 || (uVar7 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar7 != 1))))
        && ((((uVar1 >> 0xd & 1) == 0 || (uVar7 != 2)) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar7 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar7 != 5)) && (uVar7 < 6))))))))))
    goto LAB_14001325a;
    uVar5 = 0xc;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
LAB_14001325a:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7);
  }
  return lVar6;
}



===== GetAcpiSettings @ 140013300 =====

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
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar2);
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
             &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar2);
  }
  return;
}



===== ReadAcpiClockSettings @ 140013558 =====

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
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined1 uVar8;
  ulong uVar9;
  undefined1 auStackY_318 [32];
  short *local_2d0;
  ulong local_2c0;
  uint local_2bc;
  undefined4 local_2b8;
  char local_2b4;
  char local_2b3;
  char local_2b2;
  char local_2b1;
  ulong local_2b0;
  ulong *local_2a8;
  ulong *local_2a0;
  undefined8 local_298;
  int *local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined4 *local_278;
  undefined8 local_270;
  longlong local_268;
  ulong *local_260;
  ulong *local_258;
  ulong *local_250;
  int local_248 [2];
  uint local_240;
  short local_23c [250];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_318;
  local_2a0 = param_5;
  uVar7 = 0xf0;
  local_2a8 = param_6;
  local_260 = param_7;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  local_2b4 = *param_2;
  local_2b3 = param_2[1];
  local_2b2 = param_2[2];
  local_2b1 = param_2[3];
  local_2b8 = 0x42696541;
  local_270 = 8;
  local_278 = &local_2b8;
  local_280 = 1;
  local_258 = param_3;
  local_250 = param_4;
  memset(local_248,0,0x200);
  uVar4 = *(undefined8 *)param_1;
  local_290 = local_248;
  local_298 = 1;
  local_288 = 0x200;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x150);
  _guard_check_icall();
  uVar4 = (*pcVar2)(WdfDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
  _guard_check_icall();
  iVar3 = (*pcVar2)(WdfDriverGlobals,uVar4,0,0x32c004);
  if ((iVar3 < 0) || (local_268 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
          (((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
           || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2,(char)iVar3);
    }
    iVar3 = 0;
  }
  else if (local_248[0] == 0x426f6541) {
    if (local_240 - 2 < 4) {
      local_2c0 = 0;
      local_2d0 = local_23c;
      local_2bc = 0;
      if (local_240 != 0) {
        do {
          if (*local_2d0 != 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar7 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar7 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
              uVar6 = 0x1b;
              goto LAB_140013ccf;
            }
            break;
          }
          if (local_2bc == 0) {
            local_2c0 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                  ((((uVar1 & 0x2000) != 0 && (uVar7 == 2)) ||
                   (((uVar1 & 0x4000) != 0 && (uVar7 == 3)))))))) ||
                (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                          &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2,
                          (char)local_2c0,(char)local_2c0);
            }
            if (local_2c0 == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                  (((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                    ((((uVar1 & 0x2000) != 0 && (uVar7 == 2)) ||
                     (((uVar1 & 0x4000) != 0 && (uVar7 == 3)))))) ||
                   (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                     (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
                uVar6 = 0x1d;
                goto LAB_14001374f;
              }
              break;
            }
          }
          else if (local_2bc == 1) {
            local_2b0 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar7 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar7 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                          &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2,
                          (char)local_2b0,(char)local_2b0);
            }
            if (local_2b0 == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                      (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
                     (((uVar1 & 0x2000) != 0 && (uVar7 == 2)))) ||
                    (((uVar1 & 0x4000) != 0 && (uVar7 == 3)))) ||
                   ((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                    (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
                uVar6 = 0x1f;
                goto LAB_14001374f;
              }
              break;
            }
            *local_258 = local_2c0;
            *local_250 = local_2b0;
          }
          else if (local_2bc == 2) {
            *local_2a0 = *(ulong *)(local_2d0 + 2);
            *local_2a8 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                    (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
                   (((uVar1 & 0x2000) != 0 && (uVar7 == 2)))) ||
                  (((uVar1 & 0x4000) != 0 && (uVar7 == 3)))) ||
                 ((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
              uVar6 = 0x20;
              uVar8 = (undefined1)*local_2a0;
LAB_140013899:
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                          &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2,uVar8,uVar8
                         );
            }
          }
          else if (local_2bc == 3) {
            uVar9 = *(ulong *)(local_2d0 + 2);
            *local_2a8 = uVar9;
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar7 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar7 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
              uVar6 = 0x21;
LAB_14001388f:
              uVar8 = (undefined1)uVar9;
              goto LAB_140013899;
            }
          }
          else if (local_2bc == 4) {
            uVar9 = *(ulong *)(local_2d0 + 2);
            *local_260 = uVar9;
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
                  ((((uVar1 & 0x2000) != 0 && (uVar7 == 2)) ||
                   (((uVar1 & 0x4000) != 0 && (uVar7 == 3)))))))) ||
                (((((uVar1 & 0x8000) != 0 && (uVar7 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
              uVar6 = 0x22;
              goto LAB_14001388f;
            }
          }
          if ((ushort)local_2d0[1] < 4) {
            uVar5 = 4;
          }
          else {
            uVar5 = (ulonglong)(ushort)local_2d0[1];
          }
          local_2d0 = (short *)((longlong)local_2d0 + uVar5 + 4);
          local_2bc = local_2bc + 1;
        } while (local_2bc < local_240);
      }
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((((uVar1 & 0x800) != 0 && (uVar7 == 0)) ||
             ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) ||
              ((((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
                ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))))))) {
      uVar6 = 0x1a;
      local_2bc = local_240;
LAB_140013ccf:
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                 &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2,(char)local_2bc);
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 & 0x800) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4))))
         || ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      uVar6 = 0x19;
LAB_14001374f:
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar7,param_2);
    }
  }
  return iVar3;
}



===== ReadAcpiParameter @ 140013e40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadAcpiParameter(struct PBC_DEVICE * __ptr64,char * __ptr64,unsigned long *
   __ptr64) */

long __cdecl ReadAcpiParameter(PBC_DEVICE *param_1,char *param_2,ulong *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined1 auStackY_2c8 [32];
  undefined4 local_288;
  char local_284;
  char local_283;
  char local_282;
  char local_281;
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
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  local_284 = *param_2;
  local_283 = param_2[1];
  local_282 = param_2[2];
  local_281 = param_2[3];
  local_260 = &local_288;
  local_288 = 0x42696541;
  local_268 = 1;
  local_258 = 8;
  memset(local_248,0,0x200);
  uVar4 = *(undefined8 *)param_1;
  local_278 = local_248;
  local_280 = 1;
  local_270 = 0x200;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x150);
  _guard_check_icall();
  uVar4 = (*pcVar2)(WdfDriverGlobals,uVar4);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
  _guard_check_icall();
  iVar3 = (*pcVar2)(WdfDriverGlobals,uVar4,0,0x32c004);
  if ((iVar3 < 0) || (local_250 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)) || (5 < uVar6)))))) {
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar6,param_2,(char)iVar3);
    }
    return 0;
  }
  if (local_248[0] == 0x426f6541) {
    if (local_240 == 1) {
      if (local_23c == 0) {
        *param_3 = local_238;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((uVar1 & 0x40) == 0) {
          return iVar3;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
          return iVar3;
        }
        if (((((((uVar1 >> 0xb & 1) == 0) || (uVar6 != 0)) &&
              (((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)))) &&
             ((((uVar1 >> 0xd & 1) == 0 || (uVar6 != 2)) &&
              (((uVar1 >> 0xe & 1) == 0 || (uVar6 != 3)))))) &&
            ((((uVar1 >> 0xf & 1) == 0 || (uVar6 != 4)) &&
             (((uVar1 >> 0x10 & 1) == 0 || (uVar6 != 5)))))) && (uVar6 < 6)) {
          return iVar3;
        }
        WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar6,param_2,(char)local_238,
                    (char)local_238);
        return iVar3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((uVar1 & 0x40) == 0) {
        return iVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar3;
      }
      if (((((uVar1 >> 0xb & 1) == 0) || (uVar6 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)) && (((uVar1 >> 0xd & 1) == 0 || (uVar6 != 2)))
           ))) && ((((uVar1 >> 0xe & 1) == 0 || (uVar6 != 3)) &&
                   (((((uVar1 >> 0xf & 1) == 0 || (uVar6 != 4)) &&
                     (((uVar1 >> 0x10 & 1) == 0 || (uVar6 != 5)))) && (uVar6 < 6)))))) {
        return iVar3;
      }
      uVar5 = 0x26;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((uVar1 & 0x40) == 0) {
        return iVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar3;
      }
      if ((((((uVar1 >> 0xb & 1) == 0) || (uVar6 != 0)) &&
           (((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1)))) &&
          ((((uVar1 >> 0xd & 1) == 0 || (uVar6 != 2)) && (((uVar1 >> 0xe & 1) == 0 || (uVar6 != 3)))
           ))) && (((((uVar1 >> 0xf & 1) == 0 || (uVar6 != 4)) &&
                    (((uVar1 >> 0x10 & 1) == 0 || (uVar6 != 5)))) && (uVar6 < 6)))) {
        return iVar3;
      }
      uVar5 = 0x25;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((uVar1 & 0x40) == 0) {
      return iVar3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return iVar3;
    }
    if (((((uVar1 >> 0xb & 1) == 0) || (uVar6 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar6 != 1))))
       && ((((uVar1 >> 0xd & 1) == 0 || (uVar6 != 2)) &&
           (((((uVar1 >> 0xe & 1) == 0 || (uVar6 != 3)) &&
             ((((uVar1 >> 0xf & 1) == 0 || (uVar6 != 4)) &&
              (((uVar1 >> 0x10 & 1) == 0 || (uVar6 != 5)))))) && (uVar6 < 6)))))) {
      return iVar3;
    }
    uVar5 = 0x24;
  }
  WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
            &WPP_11eb8d2b9d6a3cce946139d034a59ec5_Traceguids,uVar6,param_2);
  return iVar3;
}



===== WPP_SF_ds @ 1400142a8 =====

void WPP_SF_ds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar2,lVar4,0);
  return;
}



===== WPP_SF_dsd @ 140014364 =====

void WPP_SF_dsd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,undefined1 param_6)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar2,lVar4,&param_6,4,0);
  return;
}



===== WPP_SF_dsdD @ 140014430 =====

void WPP_SF_dsdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                char *param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar2,lVar4,&param_6,4,&param_7,4,0);
  return;
}



===== CheckSupportedHardware @ 14001450c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CheckSupportedHardware(struct WDFDEVICE__ * __ptr64) */

long __cdecl CheckSupportedHardware(WDFDEVICE__ *param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  longlong lVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined2 uVar7;
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
             &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar4 = (*pcVar2)(WdfDriverGlobals,param_1);
  local_44 = 0xff;
  local_40 = 0xff;
  local_48 = 0xff;
  local_3c = 0xff;
  lVar3 = GetHardwareVersion(param_1,(HW_PARAMETERS *)&local_48);
  if (lVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140014ae6;
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar7 = 0xf;
  }
  else {
    if (local_40 != 0xff) {
LAB_140014693:
      if (local_48 == 0xff) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
        }
        lVar3 = GetHardwareInstance(param_1,(HW_PARAMETERS *)&local_48);
        if (lVar3 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140014ae6;
          uVar7 = 0x13;
          goto LAB_14001468a;
        }
      }
      *(undefined4 *)(lVar4 + 0x44) = local_44;
      *(int *)(lVar4 + 0x48) = local_40;
      *(int *)(lVar4 + 0x40) = local_48;
      *(int *)(lVar4 + 0x4c) = local_3c;
      iVar1 = *(int *)(lVar4 + 0x44);
      if (iVar1 == 2) {
        if (*(uint *)(lVar4 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x15;
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x14;
        }
      }
      else if (iVar1 == 3) {
        if (0xef < *(uint *)(lVar4 + 0x48)) goto LAB_140014ae0;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar3;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
        pcVar5 = "PCI";
        if (local_3c == 0) {
          pcVar5 = "ACPI";
        }
        uVar7 = 0x16;
      }
      else if (iVar1 == 4) {
        if (*(uint *)(lVar4 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x17;
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x18;
        }
      }
      else if (iVar1 == 5) {
        if (*(uint *)(lVar4 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x19;
        }
        else {
LAB_140014971:
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x1b;
        }
      }
      else if (iVar1 == 6) {
        if (0xef < *(uint *)(lVar4 + 0x48)) {
LAB_140014ae0:
          lVar3 = -0x3ffffda0;
          goto LAB_140014ae6;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar3;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
        pcVar5 = "PCI";
        if (local_3c == 0) {
          pcVar5 = "ACPI";
        }
        uVar7 = 0x1a;
      }
      else {
        if (iVar1 == 5) {
          if (0xef < *(uint *)(lVar4 + 0x48)) goto LAB_140014971;
          goto LAB_140014ae0;
        }
        if (iVar1 == 7) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x1c;
        }
        else if (iVar1 == 8) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar3;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
          pcVar5 = "PCI";
          if (local_3c == 0) {
            pcVar5 = "ACPI";
          }
          uVar7 = 0x1d;
        }
        else {
          if (iVar1 != 9) goto LAB_140014ae0;
          if (*(uint *)(lVar4 + 0x48) < 0xf0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar3;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
            pcVar5 = "PCI";
            if (local_3c == 0) {
              pcVar5 = "ACPI";
            }
            uVar7 = 0x1e;
          }
          else {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar3;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140014ae6;
            pcVar5 = "PCI";
            if (local_3c == 0) {
              pcVar5 = "ACPI";
            }
            uVar7 = 0x1f;
          }
        }
      }
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff,pcVar5);
      goto LAB_140014ae6;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
    }
    lVar3 = GetHardwareRevision(param_1,(HW_PARAMETERS *)&local_48);
    if (-1 < lVar3) goto LAB_140014693;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140014ae6;
    uVar7 = 0x11;
LAB_14001468a:
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_d(uVar6,uVar7,&WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
LAB_140014ae6:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
  }
  return lVar3;
}



===== GetHardwareInstance @ 140014b44 =====

/* long __cdecl GetHardwareInstance(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareInstance(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  code *pcVar1;
  long lVar2;
  PBC_DEVICE *pPVar3;
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar3 = (PBC_DEVICE *)(*pcVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if (*(int *)(param_2 + 0xc) == 0) {
    lVar2 = GetAcpiHardwareInstance(pPVar3,(ulong *)param_2);
  }
  else {
    lVar2 = 0;
    if (*(int *)(param_2 + 0xc) == 1) {
      lVar2 = -0x3fffffff;
    }
  }
  return lVar2;
}



===== GetHardwareRevision @ 140014bd0 =====

/* long __cdecl GetHardwareRevision(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareRevision(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  code *pcVar1;
  long lVar2;
  PBC_DEVICE *pPVar3;
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar3 = (PBC_DEVICE *)(*pcVar1)(WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  if (*(int *)(param_2 + 0xc) == 0) {
    lVar2 = GetAcpiHardwareRevision(pPVar3,(ulong *)(param_2 + 8));
  }
  else {
    if (*(int *)(param_2 + 0xc) != 1) {
      return 0;
    }
    lVar2 = GetPciHardwareRevision(pPVar3,(ulong *)(param_2 + 8));
  }
  return lVar2;
}



===== GetHardwareVersion @ 140014c64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetHardwareVersion(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareVersion(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  wchar_t *pwVar1;
  code *pcVar2;
  wchar_t *_Str2;
  int iVar3;
  int iVar4;
  wchar_t *_Src;
  size_t sVar5;
  ulonglong uVar6;
  uint uVar7;
  size_t _MaxCount;
  undefined **ppuVar8;
  undefined1 auStackY_9c8 [32];
  undefined8 local_998;
  ulonglong local_988;
  undefined4 local_980 [6];
  undefined4 local_968;
  undefined4 local_964;
  WDFDEVICE__ *local_960;
  undefined4 local_948 [2];
  undefined *local_940;
  undefined8 local_938;
  undefined4 local_930 [4];
  undefined1 *local_920;
  undefined4 local_918;
  undefined8 local_914;
  undefined4 local_908;
  undefined1 *local_900;
  undefined4 local_8f8;
  undefined8 local_8f4;
  undefined4 local_8e8;
  undefined1 *local_8e0;
  undefined4 local_8d8;
  undefined8 local_8d4;
  undefined4 local_8c8;
  undefined1 *local_8c0;
  undefined4 local_8b8;
  undefined8 local_8b4;
  undefined4 local_8a8;
  wchar_t *local_8a0;
  undefined4 local_898;
  undefined8 local_894;
  undefined4 local_888;
  undefined1 *local_880;
  undefined8 local_878;
  undefined4 local_870;
  undefined4 local_868;
  undefined1 *local_860;
  undefined4 local_858;
  undefined4 local_854;
  undefined4 local_850;
  undefined4 local_848;
  undefined1 *local_840;
  undefined4 local_838;
  undefined4 local_834;
  undefined4 local_830;
  undefined4 local_828;
  undefined1 *local_820;
  undefined4 local_818;
  undefined4 local_814;
  undefined4 local_810;
  undefined4 local_808;
  undefined1 *local_800;
  undefined4 local_7f8;
  undefined4 local_7f4;
  undefined4 local_7f0;
  undefined4 local_7e8;
  undefined1 *local_7e0;
  undefined4 local_7d8;
  undefined4 local_7d4;
  undefined4 local_7d0;
  undefined4 local_7c8;
  undefined1 *local_7c0;
  undefined8 local_7b8;
  undefined4 local_7b0;
  undefined4 local_7a8;
  undefined1 *local_7a0;
  undefined4 local_798;
  undefined4 local_794;
  undefined4 local_790;
  undefined4 local_788;
  undefined1 *local_780;
  undefined4 local_778;
  undefined4 local_774;
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
  undefined4 local_638;
  undefined4 local_634;
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
  undefined8 local_5b8;
  undefined4 local_5b0;
  undefined4 local_5a8;
  undefined1 *local_5a0;
  undefined4 local_598;
  undefined4 local_594;
  undefined4 local_590;
  undefined4 local_588;
  undefined1 *local_580;
  undefined4 local_578;
  undefined4 local_574;
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
  undefined4 local_4f8;
  undefined4 local_4f4;
  undefined4 local_4f0;
  undefined4 local_4e8;
  undefined1 *local_4e0;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined4 local_4d0;
  undefined4 local_4c8;
  undefined1 *local_4c0;
  undefined8 local_4b8;
  undefined4 local_4b0;
  undefined4 local_4a8;
  undefined1 *local_4a0;
  undefined4 local_498;
  undefined8 local_494;
  undefined4 local_488;
  undefined1 *local_480;
  undefined4 local_478;
  undefined8 local_474;
  undefined4 local_468;
  undefined1 *local_460;
  undefined4 local_458;
  undefined8 local_454;
  undefined4 local_448;
  undefined1 *local_440;
  undefined8 local_438;
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
  undefined8 local_3b8;
  undefined4 local_3b0;
  undefined4 local_3a8;
  undefined1 *local_3a0;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_388;
  undefined1 *local_380;
  undefined4 local_378;
  undefined4 local_374;
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
  undefined8 local_2f8;
  undefined4 local_2f0;
  undefined4 local_2e8;
  undefined1 *local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2c8;
  undefined1 *local_2c0;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2a8;
  undefined1 *local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_288;
  undefined1 *local_280;
  undefined8 local_278;
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
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_9c8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
  }
  local_894 = 5;
  local_948[0] = 1;
  local_940 = &u_ACPI_INT3442;
  uVar7 = 0;
  local_930[0] = 0;
  local_920 = &u_ACPI_INT3443;
  local_938 = 2;
  local_930[2] = 1;
  local_900 = &u_ACPI_INT3444;
  local_918 = 2;
  local_8e0 = &u_ACPI_INT3445;
  local_8c0 = &u_ACPI_INT3446;
  local_8a0 = L"ACPI\\INT3447";
  local_880 = &u_PCI_VEN_8086_DEV_9D60;
  local_860 = &u_PCI_VEN_8086_DEV_9D61;
  local_840 = &u_PCI_VEN_8086_DEV_9D62;
  local_820 = &u_PCI_VEN_8086_DEV_9D63;
  local_800 = &u_PCI_VEN_8086_DEV_9D64;
  local_7e0 = &u_PCI_VEN_8086_DEV_9D65;
  local_7c0 = &u_PCI_VEN_8086_DEV_0AAC;
  local_7a0 = &u_PCI_VEN_8086_DEV_0AAE;
  local_914 = 1;
  local_908 = 1;
  local_8f8 = 2;
  local_8f4 = 2;
  local_8e8 = 1;
  local_8d8 = 2;
  local_8d4 = 3;
  local_8c8 = 1;
  local_8b8 = 2;
  local_8b4 = 4;
  local_8a8 = 1;
  local_898 = 2;
  local_888 = 1;
  local_878 = 2;
  local_870 = 1;
  local_868 = 1;
  local_858 = 2;
  local_854 = 1;
  local_850 = 1;
  local_848 = 1;
  local_838 = 2;
  local_834 = 2;
  local_830 = 1;
  local_828 = 1;
  local_818 = 2;
  local_814 = 3;
  local_810 = 1;
  local_808 = 1;
  local_7f8 = 2;
  local_7f4 = 4;
  local_7f0 = 1;
  local_7e8 = 1;
  local_7d8 = 2;
  local_7d4 = 5;
  local_7d0 = 1;
  local_7c8 = 1;
  local_7b8 = 4;
  local_7b0 = 1;
  local_7a8 = 1;
  local_798 = 4;
  local_794 = 1;
  local_790 = 1;
  local_788 = 1;
  local_780 = &u_PCI_VEN_8086_DEV_0AB0;
  local_778 = 4;
  local_760 = &u_PCI_VEN_8086_DEV_0AB2;
  local_774 = 2;
  local_740 = &u_PCI_VEN_8086_DEV_0AB4;
  local_720 = &u_PCI_VEN_8086_DEV_0AB6;
  local_700 = &u_PCI_VEN_8086_DEV_0AB8;
  local_6e0 = &u_PCI_VEN_8086_DEV_0ABA;
  local_6c0 = &u_PCI_VEN_8086_DEV_1AAC;
  local_6a0 = &u_PCI_VEN_8086_DEV_1AAE;
  local_680 = &u_PCI_VEN_8086_DEV_1AB0;
  local_660 = &u_PCI_VEN_8086_DEV_1AB2;
  local_640 = &u_PCI_VEN_8086_DEV_1AB4;
  local_620 = &u_PCI_VEN_8086_DEV_1AB6;
  local_600 = &u_PCI_VEN_8086_DEV_1AB8;
  local_770 = 1;
  local_768 = 1;
  local_758 = 4;
  local_754 = 3;
  local_750 = 1;
  local_748 = 1;
  local_738 = 4;
  local_734 = 4;
  local_730 = 1;
  local_728 = 1;
  local_718 = 4;
  local_714 = 5;
  local_710 = 1;
  local_708 = 1;
  local_6f8 = 4;
  local_6f4 = 6;
  local_6f0 = 1;
  local_6e8 = 1;
  local_6d8 = 4;
  local_6d4 = 7;
  local_6d0 = 1;
  local_6c8 = 1;
  local_6b8 = 4;
  local_6b0 = 1;
  local_6a8 = 1;
  local_698 = 4;
  local_694 = 1;
  local_690 = 1;
  local_688 = 1;
  local_678 = 4;
  local_674 = 2;
  local_670 = 1;
  local_668 = 1;
  local_658 = 4;
  local_654 = 3;
  local_650 = 1;
  local_648 = 1;
  local_638 = 4;
  local_634 = 4;
  local_630 = 1;
  local_628 = 1;
  local_618 = 4;
  local_614 = 5;
  local_610 = 1;
  local_608 = 1;
  local_5f8 = 4;
  local_5f4 = 6;
  local_5f0 = 1;
  local_5e8 = 1;
  local_5e0 = &u_PCI_VEN_8086_DEV_1ABA;
  local_5c0 = &u_PCI_VEN_8086_DEV_5AAC;
  local_5a0 = &u_PCI_VEN_8086_DEV_5AAE;
  local_580 = &u_PCI_VEN_8086_DEV_5AB0;
  local_560 = &u_PCI_VEN_8086_DEV_5AB2;
  local_540 = &u_PCI_VEN_8086_DEV_5AB4;
  local_520 = &u_PCI_VEN_8086_DEV_5AB6;
  local_500 = &u_PCI_VEN_8086_DEV_5AB8;
  local_4e0 = &u_PCI_VEN_8086_DEV_5ABA;
  local_4c0 = &u_ACPI_INT3456;
  local_4a0 = &u_ACPI_INT3457;
  local_480 = &u_ACPI_INT3458;
  local_460 = &u_ACPI_INT3459;
  local_440 = &u_PCI_VEN_8086_DEV_A160;
  local_420 = &u_PCI_VEN_8086_DEV_A161;
  local_5d8 = 4;
  local_5d4 = 7;
  local_5d0 = 1;
  local_5c8 = 1;
  local_5b8 = 4;
  local_5b0 = 1;
  local_5a8 = 1;
  local_598 = 4;
  local_594 = 1;
  local_590 = 1;
  local_588 = 1;
  local_578 = 4;
  local_574 = 2;
  local_570 = 1;
  local_568 = 1;
  local_558 = 4;
  local_554 = 3;
  local_550 = 1;
  local_548 = 1;
  local_538 = 4;
  local_534 = 4;
  local_530 = 1;
  local_528 = 1;
  local_518 = 4;
  local_514 = 5;
  local_510 = 1;
  local_508 = 1;
  local_4f8 = 4;
  local_4f4 = 6;
  local_4f0 = 1;
  local_4e8 = 1;
  local_4d8 = 4;
  local_4d4 = 7;
  local_4d0 = 1;
  local_4c8 = 1;
  local_4b8 = 3;
  local_4b0 = 0;
  local_4a8 = 1;
  local_498 = 3;
  local_494 = 1;
  local_488 = 1;
  local_478 = 3;
  local_474 = 2;
  local_468 = 1;
  local_458 = 3;
  local_454 = 3;
  local_448 = 1;
  local_438 = 3;
  local_430 = 1;
  local_428 = 1;
  local_418 = 3;
  local_414 = 1;
  local_410 = 1;
  local_400 = &u_PCI_VEN_8086_DEV_A162;
  local_3e0 = &u_PCI_VEN_8086_DEV_A163;
  local_3c0 = &u_PCI_VEN_8086_DEV_9DE8;
  local_3a0 = &u_PCI_VEN_8086_DEV_9DE9;
  local_380 = &u_PCI_VEN_8086_DEV_9DEA;
  local_360 = &u_PCI_VEN_8086_DEV_9DEB;
  local_340 = &u_PCI_VEN_8086_DEV_9DC5;
  local_320 = &u_PCI_VEN_8086_DEV_9DC6;
  local_300 = &u_PCI_VEN_8086_DEV_A368;
  local_2e0 = &u_PCI_VEN_8086_DEV_A369;
  local_2c0 = &u_PCI_VEN_8086_DEV_A36A;
  local_2a0 = &u_PCI_VEN_8086_DEV_A36B;
  local_280 = &u_PCI_VEN_8086_DEV_A2E8;
  local_260 = &u_PCI_VEN_8086_DEV_A2E9;
  local_408 = 1;
  local_3f8 = 3;
  local_3f4 = 2;
  local_3f0 = 1;
  local_3e8 = 1;
  local_3d8 = 3;
  local_3d4 = 3;
  local_3d0 = 1;
  local_3c8 = 1;
  local_3b8 = 5;
  local_3b0 = 1;
  local_3a8 = 1;
  local_398 = 5;
  local_394 = 1;
  local_390 = 1;
  local_388 = 1;
  local_378 = 5;
  local_374 = 2;
  local_370 = 1;
  local_368 = 1;
  local_358 = 5;
  local_354 = 3;
  local_350 = 1;
  local_348 = 1;
  local_338 = 5;
  local_334 = 4;
  local_330 = 1;
  local_328 = 1;
  local_318 = 5;
  local_314 = 5;
  local_310 = 1;
  local_308 = 1;
  local_2f8 = 6;
  local_2f0 = 1;
  local_2e8 = 1;
  local_2d8 = 6;
  local_2d4 = 1;
  local_2d0 = 1;
  local_2c8 = 1;
  local_2b8 = 6;
  local_2b4 = 2;
  local_2b0 = 1;
  local_2a8 = 1;
  local_298 = 6;
  local_294 = 3;
  local_290 = 1;
  local_288 = 1;
  local_278 = 7;
  local_270 = 1;
  local_268 = 1;
  local_258 = 7;
  local_254 = 1;
  local_250 = 1;
  local_1f8 = 8;
  local_240 = &u_PCI_VEN_8086_DEV_A2EA;
  local_220 = &u_PCI_VEN_8086_DEV_A2EB;
  local_200 = &u_PCI_VEN_8086_DEV_31AC;
  local_1e0 = &u_PCI_VEN_8086_DEV_31AE;
  local_1c0 = &u_PCI_VEN_8086_DEV_31B0;
  local_1a0 = &u_PCI_VEN_8086_DEV_31B2;
  local_180 = &u_PCI_VEN_8086_DEV_31B4;
  local_160 = &u_PCI_VEN_8086_DEV_31B6;
  local_140 = &u_PCI_VEN_8086_DEV_31B8;
  local_120 = &u_PCI_VEN_8086_DEV_31BA;
  local_100 = &u_PCI_VEN_8086_DEV_34E8;
  local_e0 = &u_PCI_VEN_8086_DEV_34E9;
  local_1d8 = 8;
  local_1b8 = 8;
  local_198 = 8;
  local_178 = 8;
  local_158 = 8;
  local_138 = 8;
  local_118 = 8;
  local_c0 = &u_PCI_VEN_8086_DEV_34EA;
  local_248 = 1;
  local_238 = 7;
  local_234 = 2;
  local_230 = 1;
  local_228 = 1;
  local_218 = 7;
  local_214 = 3;
  local_210 = 1;
  local_208 = 1;
  local_1f0 = 1;
  local_1e8 = 1;
  local_1d4 = 1;
  local_1d0 = 1;
  local_1c8 = 1;
  local_1b4 = 2;
  local_1b0 = 1;
  local_1a8 = 1;
  local_194 = 3;
  local_190 = 1;
  local_188 = 1;
  local_174 = 4;
  local_170 = 1;
  local_168 = 1;
  local_154 = 5;
  local_150 = 1;
  local_148 = 1;
  local_134 = 6;
  local_130 = 1;
  local_128 = 1;
  local_114 = 7;
  local_110 = 1;
  local_108 = 1;
  local_f8 = 9;
  local_f0 = 1;
  local_e8 = 1;
  local_d8 = 9;
  local_d4 = 1;
  local_d0 = 1;
  local_c8 = 1;
  local_b8 = 9;
  local_b4 = 2;
  local_b0 = 1;
  local_a8 = 1;
  local_a0 = &u_PCI_VEN_8086_DEV_34EB;
  ppuVar8 = &local_940;
  local_98 = 9;
  local_80 = &u_PCI_VEN_8086_DEV_34C5;
  local_60 = &u_PCI_VEN_8086_DEV_34C6;
  local_94 = 3;
  local_90 = 1;
  local_88 = 1;
  local_78 = 9;
  local_74 = 4;
  local_70 = 1;
  local_68 = 1;
  local_58 = 9;
  local_54 = 5;
  local_50 = 1;
  do {
    memset(local_980,0,0x38);
    local_980[0] = 0x38;
    local_968 = 1;
    local_964 = 1;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x290);
    local_960 = param_1;
    _guard_check_icall();
    iVar3 = (*pcVar2)(WdfDriverGlobals,param_1,*(undefined4 *)(ppuVar8 + -1));
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff,(char)uVar7,(char)iVar3);
      }
    }
    else {
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x610);
      _guard_check_icall();
      _Src = (wchar_t *)(*pcVar2)(WdfDriverGlobals,local_998,&local_988);
      pwVar1 = (wchar_t *)((longlong)_Src + (local_988 & 0xfffffffffffffffe));
      for (; _Src < pwVar1; _Src = _Src + sVar5 + 1) {
        _MaxCount = (longlong)pwVar1 - (longlong)_Src >> 1;
        sVar5 = wcsnlen(_Src,_MaxCount);
        if (sVar5 == 0) break;
        _Str2 = (wchar_t *)*ppuVar8;
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
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff,(undefined *)_Src);
          }
          uVar6 = (ulonglong)uVar7;
          *(undefined4 *)(param_2 + 4) = local_930[uVar6 * 8 + -2];
          *(undefined4 *)param_2 = local_930[uVar6 * 8 + -1];
          *(undefined4 *)(param_2 + 0xc) = local_930[uVar6 * 8];
          pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
          _guard_check_icall();
          (*pcVar2)(WdfDriverGlobals,local_998);
          goto LAB_14001597b;
        }
        sVar5 = wcsnlen(_Src,_MaxCount);
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
      _guard_check_icall();
      (*pcVar2)(WdfDriverGlobals);
    }
    uVar7 = uVar7 + 1;
    ppuVar8 = ppuVar8 + 4;
    if (0x47 < uVar7) {
      iVar3 = -0x3ffffda0;
LAB_14001597b:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_ffd917d53804346c06d637783b779140_Traceguids,0xff);
      }
      return iVar3;
    }
  } while( true );
}



===== WPP_SF_dS @ 140015a70 =====

void WPP_SF_dS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined *param_5)

{
  code *pcVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (undefined *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar3 = param_5;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,puVar3,lVar2,0);
  return;
}



===== CheckTransferForDmaOperation @ 140015b30 =====

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
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar3);
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
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar3);
  }
  return (uchar)param_1[0x119];
}



===== DmaCheckBusy @ 140015c98 =====

/* unsigned char __cdecl DmaCheckBusy(struct PBC_DEVICE * __ptr64,enum _WDF_DMA_DIRECTION) */

uchar __cdecl DmaCheckBusy(PBC_DEVICE *param_1,_WDF_DMA_DIRECTION param_2)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  if (param_2 == 1) {
    uVar3 = *(undefined8 *)(param_1 + 0x128);
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x130);
  }
  _guard_check_icall();
  lVar2 = (*pcVar1)(WdfDriverGlobals,uVar3,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  return *(uchar *)(lVar2 + 100);
}



===== DmaDataTransferred @ 140015cfc =====

/* unsigned __int64 __cdecl DmaDataTransferred(struct PBC_DEVICE * __ptr64,enum _WDF_DMA_DIRECTION)
    */

__uint64 __cdecl DmaDataTransferred(PBC_DEVICE *param_1,_WDF_DMA_DIRECTION param_2)

{
  code *pcVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  if (param_2 == 1) {
    uVar4 = *(undefined8 *)(param_1 + 0x128);
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x130);
  }
  _guard_check_icall();
  lVar2 = (*pcVar1)(WdfDriverGlobals,uVar4,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  uVar3 = *(ulonglong *)(lVar2 + 0x40);
  if (*(ulonglong *)(lVar2 + 0x48) <= *(ulonglong *)(lVar2 + 0x40)) {
    uVar3 = *(ulonglong *)(lVar2 + 0x48);
  }
  return uVar3;
}



===== DmaInitSw @ 140015d6c =====

/* long __cdecl DmaInitSw(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaInitSw(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  PBC_DEVICE *pPVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  code *pcVar5;
  WDFCOMMONBUFFER__ *pWVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  uint uVar13;
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
  
  uVar13 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar13 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar13 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar13 == 1))))
       || (((uVar4 >> 0xd & 1) != 0 && (uVar13 == 2)))) ||
      ((((uVar4 >> 0xe & 1) != 0 && (uVar13 == 3)) ||
       (((((uVar4 >> 0xf & 1) != 0 && (uVar13 == 4)) ||
         (((uVar4 >> 0x10 & 1) != 0 && (uVar13 == 5)))) || (5 < uVar13)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar13);
  }
  *(undefined8 *)(param_1 + 0x128) = 0;
  pPVar1 = param_1 + 0x120;
  *(undefined8 *)pPVar1 = 0;
  pPVar2 = param_1 + 0x130;
  *(undefined8 *)pPVar2 = 0;
  pPVar3 = param_1 + 0x140;
  *(WDFCOMMONBUFFER__ **)pPVar3 = (WDFCOMMONBUFFER__ *)0x0;
  param_1[0x119] = (PBC_DEVICE)0x0;
  *(undefined8 *)(param_1 + 0x138) = 0;
  pcVar5 = *(code **)(WdfFunctions_01015 + 0x1a8);
  _guard_check_icall();
  (*pcVar5)(WdfDriverGlobals,*(undefined8 *)param_1,0x3f);
  memset(&local_78,0,0x50);
  local_78 = 0x50;
  local_58 = EvtDmaD0Exit;
  local_74 = 6;
  local_50 = EvtDmaD0Entry;
  local_70 = 0x10000;
  local_34 = 3;
  memset(local_b8,0,0x38);
  local_88 = PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022050;
  local_b8[0] = 0x38;
  uVar11 = *(undefined8 *)param_1;
  local_a0 = 1;
  local_9c = 1;
  pcVar5 = *(code **)(WdfFunctions_01015 + 0x2f0);
  _guard_check_icall();
  iVar7 = (*pcVar5)(WdfDriverGlobals,uVar11,&local_78,local_b8,pPVar1);
  if (iVar7 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar7;
    }
    uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
         ((((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)) &&
          (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))))) &&
        (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
          (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
         ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6)))))))) goto LAB_14001681b;
    uVar11 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar12 = 0xe;
  }
  else {
    uVar11 = *(undefined8 *)pPVar1;
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    puVar8 = (undefined8 *)
             (*pcVar5)(WdfDriverGlobals,uVar11,PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022050);
    *puVar8 = *(undefined8 *)param_1;
    memset(local_b8,0,0x38);
    local_88 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028;
    local_b8[0] = 0x38;
    uVar11 = *(undefined8 *)(param_1 + 0x120);
    local_a0 = 1;
    local_9c = 1;
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x310);
    _guard_check_icall();
    iVar7 = (*pcVar5)(WdfDriverGlobals,uVar11,local_b8,pPVar2);
    if (iVar7 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar7;
      }
      uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
           ((((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)) &&
            (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))))) &&
          (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
            (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
           ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6)))))))) goto LAB_14001681b;
      uVar12 = 0xf;
    }
    else {
      uVar11 = *(undefined8 *)pPVar2;
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x650);
      _guard_check_icall();
      puVar9 = (undefined4 *)
               (*pcVar5)(WdfDriverGlobals,uVar11,
                         PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
      *puVar9 = 0;
      puVar9[0x18] = 0;
      *(undefined1 *)(puVar9 + 0xe) = 0;
      *(undefined1 *)(puVar9 + 0x19) = 0;
      memset(local_b8,0,0x38);
      local_b8[0] = 0x38;
      uVar11 = *(undefined8 *)(param_1 + 0x120);
      local_a0 = 1;
      local_9c = 1;
      local_88 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028;
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x310);
      _guard_check_icall();
      iVar7 = (*pcVar5)(WdfDriverGlobals,uVar11,local_b8);
      if (iVar7 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar7;
        }
        uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
              (((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)))) &&
             (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))) &&
            (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
              (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
             ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6))))))))
        goto LAB_14001681b;
        uVar12 = 0x10;
      }
      else {
        uVar11 = *(undefined8 *)(param_1 + 0x128);
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x650);
        _guard_check_icall();
        puVar9 = (undefined4 *)
                 (*pcVar5)(WdfDriverGlobals,uVar11,
                           PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
        puVar9[0x18] = 0;
        *puVar9 = 1;
        *(undefined1 *)(puVar9 + 0xe) = 0;
        *(undefined1 *)(puVar9 + 0x19) = 0;
        uVar11 = *(undefined8 *)pPVar2;
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x650);
        _guard_check_icall();
        lVar10 = (*pcVar5)(WdfDriverGlobals,uVar11,
                           PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
        *(undefined8 *)(lVar10 + 0x20) = 0xfc0;
        iVar7 = LpssCommonBufferCreate
                          (param_1,*(WDFDMAENABLER__ **)(param_1 + 0x120),0xfc0,
                           (_WDF_OBJECT_ATTRIBUTES *)0x0,(WDFCOMMONBUFFER__ **)pPVar3);
        if (iVar7 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar7;
          }
          uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
          if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
             (((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
               ((((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)) &&
                (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))))) &&
              (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
                (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
               ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6))))))))
          goto LAB_14001681b;
          uVar12 = 0x11;
        }
        else {
          pWVar6 = *(WDFCOMMONBUFFER__ **)pPVar3;
          pcVar5 = *(code **)(WdfFunctions_01015 + 0xb0);
          _guard_check_icall();
          uVar11 = (*pcVar5)(WdfDriverGlobals,pWVar6);
          *(undefined8 *)(lVar10 + 0x28) = uVar11;
          pcVar5 = *(code **)(WdfFunctions_01015 + 0xb8);
          _guard_check_icall();
          uVar11 = (*pcVar5)(WdfDriverGlobals);
          *(undefined8 *)(lVar10 + 0x30) = uVar11;
          memset(*(void **)(lVar10 + 0x28),0,*(size_t *)(lVar10 + 0x20));
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x200) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar4 >> 0xb & 1) != 0 && (uVar13 == 0)) ||
               ((((uVar4 >> 0xc & 1) != 0 && (uVar13 == 1)) ||
                (((uVar4 >> 0xd & 1) != 0 && (uVar13 == 2)))))) ||
              (((((uVar4 >> 0xe & 1) != 0 && (uVar13 == 3)) ||
                ((((uVar4 >> 0xf & 1) != 0 && (uVar13 == 4)) ||
                 (((uVar4 >> 0x10 & 1) != 0 && (uVar13 == 5)))))) || (5 < uVar13)))))) {
            WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar13,
                       (char)*(undefined8 *)(lVar10 + 0x30),(char)*(undefined8 *)(lVar10 + 0x20));
          }
          uVar11 = *(undefined8 *)(param_1 + 0x128);
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x650);
          _guard_check_icall();
          lVar10 = (*pcVar5)(WdfDriverGlobals,uVar11,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
          *(undefined8 *)(lVar10 + 0x20) = 0xfc0;
          iVar7 = LpssCommonBufferCreate
                            (param_1,*(WDFDMAENABLER__ **)(param_1 + 0x120),0xfc0,
                             (_WDF_OBJECT_ATTRIBUTES *)0x0,(WDFCOMMONBUFFER__ **)(param_1 + 0x138));
          if (iVar7 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar7;
            }
            uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
               (((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
                 ((((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)) &&
                  (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))))) &&
                (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
                  (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
                 ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6))))))))
            goto LAB_14001681b;
            uVar12 = 0x13;
          }
          else {
            pWVar6 = *(WDFCOMMONBUFFER__ **)(param_1 + 0x138);
            pcVar5 = *(code **)(WdfFunctions_01015 + 0xb0);
            _guard_check_icall();
            uVar11 = (*pcVar5)(WdfDriverGlobals,pWVar6);
            *(undefined8 *)(lVar10 + 0x28) = uVar11;
            pcVar5 = *(code **)(WdfFunctions_01015 + 0xb8);
            _guard_check_icall();
            uVar11 = (*pcVar5)(WdfDriverGlobals);
            *(undefined8 *)(lVar10 + 0x30) = uVar11;
            memset(*(void **)(lVar10 + 0x28),0,*(size_t *)(lVar10 + 0x20));
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x200) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar4 >> 0xb & 1) != 0 && (uVar13 == 0)) ||
                 ((((uVar4 >> 0xc & 1) != 0 && (uVar13 == 1)) ||
                  ((((uVar4 >> 0xd & 1) != 0 && (uVar13 == 2)) ||
                   (((uVar4 >> 0xe & 1) != 0 && (uVar13 == 3)))))))) ||
                (((((uVar4 >> 0xf & 1) != 0 && (uVar13 == 4)) ||
                  (((uVar4 >> 0x10 & 1) != 0 && (uVar13 == 5)))) || (5 < uVar13)))))) {
              WPP_SF_dxP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar13,
                         (char)*(undefined8 *)(lVar10 + 0x30),(char)*(undefined8 *)(lVar10 + 0x20));
            }
            memset(local_b8,0,0x38);
            local_98 = *(undefined8 *)param_1;
            local_b8[0] = 0x38;
            local_a0 = 1;
            local_9c = 1;
            pcVar5 = *(code **)(WdfFunctions_01015 + 0x9d8);
            _guard_check_icall();
            iVar7 = (*pcVar5)(WdfDriverGlobals,local_b8,param_1 + 0x148);
            if (iVar7 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar7;
              }
              uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
                 (((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
                   (((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)))) &&
                  ((((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)) &&
                   (((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
                     (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))) &&
                    ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6))))))))))
              goto LAB_14001681b;
              uVar12 = 0x15;
            }
            else {
              memset(local_b8,0,0x38);
              local_98 = *(undefined8 *)param_1;
              local_b8[0] = 0x38;
              local_a0 = 1;
              local_9c = 1;
              pcVar5 = *(code **)(WdfFunctions_01015 + 0x9d8);
              _guard_check_icall();
              iVar7 = (*pcVar5)(WdfDriverGlobals,local_b8,param_1 + 0x150);
              if (-1 < iVar7) goto LAB_14001681b;
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar7;
              }
              uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
                 ((((uVar4 >> 0xb & 1) == 0 || (uVar13 != 0)) &&
                  ((((((uVar4 >> 0xc & 1) == 0 || (uVar13 != 1)) &&
                     (((uVar4 >> 0xd & 1) == 0 || (uVar13 != 2)))) &&
                    ((((uVar4 >> 0xe & 1) == 0 || (uVar13 != 3)) &&
                     (((uVar4 >> 0xf & 1) == 0 || (uVar13 != 4)))))) &&
                   ((((uVar4 >> 0x10 & 1) == 0 || (uVar13 != 5)) && (uVar13 < 6))))))))
              goto LAB_14001681b;
              uVar12 = 0x16;
            }
          }
        }
      }
    }
    uVar11 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_dD(uVar11,uVar12,&WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar13,(char)iVar7);
LAB_14001681b:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar13 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar13 == 1))))
      || (((((uVar4 >> 0xd & 1) != 0 && (uVar13 == 2)) ||
           (((uVar4 >> 0xe & 1) != 0 && (uVar13 == 3)))) ||
          (((((uVar4 >> 0xf & 1) != 0 && (uVar13 == 4)) ||
            (((uVar4 >> 0x10 & 1) != 0 && (uVar13 == 5)))) || (5 < uVar13)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar13);
  }
  return iVar7;
}



===== DmaReleaseSw @ 1400168c8 =====

/* long __cdecl DmaReleaseSw(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaReleaseSw(PBC_DEVICE *param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar4);
  }
  lVar3 = *(longlong *)(param_1 + 0x128);
  if (lVar3 != 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,lVar3,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
    *(undefined1 *)(lVar3 + 0x38) = 0;
    *(undefined1 *)(lVar3 + 100) = 0;
    *(undefined8 *)(param_1 + 0x128) = 0;
  }
  lVar3 = *(longlong *)(param_1 + 0x130);
  if (lVar3 != 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar2)(WdfDriverGlobals,lVar3,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
    *(undefined1 *)(lVar3 + 0x38) = 0;
    *(undefined1 *)(lVar3 + 100) = 0;
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar4);
  }
  return 0;
}



===== DmaRxComplete @ 140016a90 =====

/* unsigned char __cdecl DmaRxComplete(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,enum
   DMA_COMPLETION_STATUS) */

uchar __cdecl DmaRxComplete(PBC_DEVICE *param_1,PBC_REQUEST *param_2,DMA_COMPLETION_STATUS param_3)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  uchar uVar4;
  uchar uVar5;
  _DMA_TRANSACTION_CONTEXT *p_Var6;
  longlong lVar7;
  __uint64 _Var8;
  undefined2 uVar9;
  code *pcVar10;
  uint uVar11;
  int local_res18 [2];
  
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
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
  }
  uVar4 = '\0';
  local_res18[0] = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x130);
  pcVar10 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  p_Var6 = (_DMA_TRANSACTION_CONTEXT *)
           (*pcVar10)(WdfDriverGlobals,uVar2,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  *(DMA_COMPLETION_STATUS *)(p_Var6 + 4) = param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
      ((((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))
         ) || (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
    WPP_SF_ddDDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11,(char)param_3,p_Var6[100],
                 p_Var6[0x38],(char)*(undefined8 *)(p_Var6 + 0x10));
  }
  if (p_Var6[100] == (_DMA_TRANSACTION_CONTEXT)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
    }
    uVar4 = '\x01';
    goto LAB_140017344;
  }
  if (param_3 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x130);
    pcVar10 = *(code **)(WdfFunctions_01015 + 0xcf0);
    _guard_check_icall();
    cVar3 = (*pcVar10)(WdfDriverGlobals,uVar2);
    if (cVar3 == '\x01') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                 &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                 &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
      }
      uVar5 = SuspendDmaChannel(param_1,2,'\x01');
      if (uVar5 == '\0') {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                   &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
        }
        PbcFailDevice(param_1);
        goto LAB_140017344;
      }
    }
  }
  if (*(longlong *)(p_Var6 + 0x10) == 0) {
    lVar7 = *(longlong *)(p_Var6 + 0x58);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
        (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11,(char)lVar7);
    }
  }
  else {
    if (p_Var6[0x38] == (_DMA_TRANSACTION_CONTEXT)0x0) goto LAB_140017344;
    uVar2 = *(undefined8 *)(param_1 + 0x130);
    pcVar10 = *(code **)(WdfFunctions_01015 + 0x368);
    _guard_check_icall();
    lVar7 = (*pcVar10)(WdfDriverGlobals,uVar2);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11,(char)lVar7);
    }
  }
  _Var8 = GetCurrentDmaTransferLeft(param_1,p_Var6);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))
        ))) || (5 < uVar11)))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11,(char)_Var8);
  }
  lVar7 = lVar7 - _Var8;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1))))
      || ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
              &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11,(char)lVar7);
  }
  *(longlong *)(p_Var6 + 0x40) = *(longlong *)(p_Var6 + 0x40) + lVar7;
  if (*(longlong *)(p_Var6 + 0x10) == 0) goto LAB_140017344;
  uVar2 = *(undefined8 *)(param_1 + 0x130);
  if (param_3 == 0) {
    pcVar10 = *(code **)(WdfFunctions_01015 + 0x340);
  }
  else {
    pcVar10 = *(code **)(WdfFunctions_01015 + 0x348);
  }
  _guard_check_icall();
  uVar4 = (*pcVar10)(WdfDriverGlobals,uVar2,lVar7,local_res18);
  if (uVar4 == '\0') goto LAB_140017344;
  uVar5 = DisableDmaChannel(param_1,2);
  if (uVar5 == '\0') {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
    }
    PbcFailDevice(param_1);
    uVar4 = '\0';
    goto LAB_140017344;
  }
  if ((local_res18[0] == 0) && (param_3 == 0)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      uVar9 = 0x41;
LAB_140017300:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0 &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
          ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           (((((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)))) ||
            ((((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)) || (5 < uVar11)))))))) {
    uVar9 = 0x40;
    goto LAB_140017300;
  }
  pcVar10 = *(code **)(WdfFunctions_01015 + 0x330);
  _guard_check_icall();
  (*pcVar10)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
  p_Var6[0x38] = (_DMA_TRANSACTION_CONTEXT)0x0;
  p_Var6[100] = (_DMA_TRANSACTION_CONTEXT)0x0;
LAB_140017344:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))
         ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))
        ) || (5 < uVar11)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar11);
  }
  return uVar4;
}



===== DmaRxStart @ 1400173e8 =====

/* long __cdecl DmaRxStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl DmaRxStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_REQUEST PVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  int iVar7;
  longlong lVar8;
  uint uVar9;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar9);
  }
  uVar3 = *(undefined8 *)(param_1 + 0x130);
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar8 = (*pcVar4)(WdfDriverGlobals,uVar3,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  *(int *)(lVar8 + 0x60) = *(int *)(lVar8 + 0x60) + 1;
  *(undefined8 *)(lVar8 + 0x40) = 0;
  *(undefined8 *)(lVar8 + 0x48) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(lVar8 + 0x50) = *(undefined8 *)(param_2 + 0x38);
  PVar1 = param_2[0x78];
  *(undefined4 *)(lVar8 + 4) = 0;
  *(PBC_REQUEST *)(lVar8 + 8) = PVar1;
  *(undefined1 *)(lVar8 + 0x38) = 0;
  *(undefined1 *)(lVar8 + 100) = 0;
  lVar5 = *(longlong *)(param_2 + 0x58);
  *(longlong *)(lVar8 + 0x10) = lVar5;
  uVar3 = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(lVar8 + 0x18) = uVar3;
  if (lVar5 == 0) {
    iVar7 = -0x3fffffff;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar9);
    }
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x130);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0xcb0);
    _guard_check_icall();
    iVar7 = (*pcVar4)(WdfDriverGlobals,uVar6,EvtProgramDmaRx,0,lVar5,0,uVar3);
    if (iVar7 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           ((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                  &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar9,(char)iVar7);
      }
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x330);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
      goto LAB_14001779d;
    }
    *(undefined1 *)(lVar8 + 0x38) = 1;
    *(undefined1 *)(lVar8 + 100) = 1;
    uVar3 = *(undefined8 *)(param_1 + 0x130);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x328);
    _guard_check_icall();
    iVar7 = (*pcVar4)(WdfDriverGlobals,uVar3,lVar8);
    if (-1 < iVar7) goto LAB_14001779d;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
         || ((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
             (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
        (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ) || (5 < uVar9)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar9,(char)iVar7);
    }
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x330);
    _guard_check_icall();
    (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
    *(undefined1 *)(lVar8 + 0x38) = 0;
  }
  *(undefined1 *)(lVar8 + 100) = 0;
LAB_14001779d:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar9);
  }
  return iVar7;
}



===== DmaTxComplete @ 140017838 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl DmaTxComplete(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,enum
   DMA_COMPLETION_STATUS) */

uchar __cdecl DmaTxComplete(PBC_DEVICE *param_1,PBC_REQUEST *param_2,DMA_COMPLETION_STATUS param_3)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  uchar uVar4;
  uchar uVar5;
  _DMA_TRANSACTION_CONTEXT *p_Var6;
  longlong lVar7;
  __uint64 _Var8;
  undefined2 uVar9;
  longlong lVar10;
  code *pcVar11;
  uint uVar12;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  undefined4 local_60 [4];
  int local_50;
  undefined4 local_4c;
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar12 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar12 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))
        ) || (5 < uVar12)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
  }
  uVar4 = '\0';
  local_68[0] = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x128);
  pcVar11 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  p_Var6 = (_DMA_TRANSACTION_CONTEXT *)
           (*pcVar11)(WdfDriverGlobals,uVar2,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  *(DMA_COMPLETION_STATUS *)(p_Var6 + 4) = param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2))))
       )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))) {
    WPP_SF_ddDDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12,(char)param_3,p_Var6[100],
                 p_Var6[0x38],(char)*(undefined8 *)(p_Var6 + 0x10));
  }
  if (p_Var6[100] == (_DMA_TRANSACTION_CONTEXT)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
    }
    uVar4 = '\x01';
    goto LAB_1400181d2;
  }
  if (param_3 != 0) {
    if (p_Var6[0x38] != (_DMA_TRANSACTION_CONTEXT)0x0) {
      uVar2 = *(undefined8 *)(param_1 + 0x128);
      pcVar11 = *(code **)(WdfFunctions_01015 + 0xcf0);
      _guard_check_icall();
      cVar3 = (*pcVar11)(WdfDriverGlobals,uVar2);
      if (cVar3 == '\x01') {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))))) || (5 < uVar12)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                   &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
        }
        goto LAB_140017b33;
      }
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
    }
    uVar5 = DisableDmaChannel(param_1,1);
    if (uVar5 != '\0') goto LAB_140017b33;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
          (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))) {
      uVar9 = 0x26;
LAB_140017cf0:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
    }
LAB_140017d03:
    PbcFailDevice(param_1);
    goto LAB_1400181d2;
  }
LAB_140017b33:
  if (*(longlong *)(p_Var6 + 0x10) == 0) {
    lVar7 = *(longlong *)(p_Var6 + 0x58);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
         (((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))))) {
      uVar9 = 0x28;
LAB_140017d7a:
      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12,(char)lVar7);
    }
  }
  else {
    if (p_Var6[0x38] == (_DMA_TRANSACTION_CONTEXT)0x0) goto LAB_1400181d2;
    uVar2 = *(undefined8 *)(param_1 + 0x128);
    pcVar11 = *(code **)(WdfFunctions_01015 + 0x368);
    _guard_check_icall();
    lVar7 = (*pcVar11)(WdfDriverGlobals,uVar2);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))) {
      uVar9 = 0x27;
      goto LAB_140017d7a;
    }
  }
  _Var8 = GetCurrentDmaTransferLeft(param_1,p_Var6);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1))))
      || (((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12,(char)_Var8);
  }
  lVar7 = lVar7 - _Var8;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))) ||
      (((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))))) || (5 < uVar12)))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12,(char)lVar7);
  }
  lVar10 = *(longlong *)(p_Var6 + 0x40) + lVar7;
  *(longlong *)(p_Var6 + 0x40) = lVar10;
  if (*(longlong *)(p_Var6 + 0x10) == 0) {
    if ((lVar10 != *(longlong *)(p_Var6 + 0x50)) && (param_3 == 0)) {
      local_4c = *(undefined4 *)(param_1 + 0x1c);
      local_48 = (int)*(longlong *)(p_Var6 + 0x50) - (int)lVar10;
      local_50 = *(int *)(param_1 + 0x18) + 0x228;
      local_60[0] = 1;
      uVar5 = EvtProgramDmaTx(*(WDFDMATRANSACTION__ **)(param_1 + 0x128),*(WDFDEVICE__ **)param_1,
                              p_Var6,1,(_SCATTER_GATHER_LIST *)local_60);
      if (uVar5 != '\0') goto LAB_1400181d2;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))) {
        uVar9 = 0x2b;
        goto LAB_140017cf0;
      }
      goto LAB_140017d03;
    }
    uVar4 = '\x01';
    local_68[0] = -(uint)(param_3 != 0) & 0xc0000120;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x128);
    if (param_3 == 0) {
      pcVar11 = *(code **)(WdfFunctions_01015 + 0x340);
    }
    else {
      pcVar11 = *(code **)(WdfFunctions_01015 + 0x348);
    }
    _guard_check_icall();
    uVar4 = (*pcVar11)(WdfDriverGlobals,uVar2,lVar7,local_68);
  }
  if (uVar4 == '\0') goto LAB_1400181d2;
  uVar5 = CheckDmaChannelDisabled(param_1,1);
  if (uVar5 == '\0') {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
          (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))))) || (5 < uVar12)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
    }
    PbcFailDevice(param_1);
    uVar4 = '\0';
    goto LAB_1400181d2;
  }
  if ((local_68[0] == 0) && (param_3 == 0)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)))
         ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)) ||
               ((((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))) || (5 < uVar12)))))))))) {
      uVar9 = 0x2e;
LAB_140018186:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
               &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0 &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
          (((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
            ((((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)))))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)) || (5 < uVar12)))))) {
    uVar9 = 0x2d;
    goto LAB_140018186;
  }
  if (*(longlong *)(p_Var6 + 0x10) != 0) {
    pcVar11 = *(code **)(WdfFunctions_01015 + 0x330);
    _guard_check_icall();
    (*pcVar11)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    p_Var6[0x38] = (_DMA_TRANSACTION_CONTEXT)0x0;
  }
  p_Var6[100] = (_DMA_TRANSACTION_CONTEXT)0x0;
LAB_1400181d2:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar12 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar12 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar12 == 2)))
         ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar12 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar12 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar12 == 5)))
        ) || (5 < uVar12)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar12);
  }
  return uVar4;
}



===== DmaTxStart @ 14001827c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl DmaTxStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl DmaTxStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_REQUEST PVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  uchar uVar5;
  int iVar6;
  void *pvVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  ulong uVar11;
  ulonglong uVar12;
  byte bVar13;
  uint uVar14;
  undefined1 auStackY_b8 [32];
  undefined4 local_70 [4];
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar14 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar14 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar14 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar14 == 1)))
         ) || (((uVar2 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
       ((((uVar2 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
        ((((uVar2 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
         (((uVar2 >> 0x10 & 1) != 0 && (uVar14 == 5)))))))) || (5 < uVar14)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14);
  }
  iVar6 = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x128);
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pvVar7 = (void *)(*pcVar4)(WdfDriverGlobals,uVar3,
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022028);
  *(int *)((longlong)pvVar7 + 0x60) = *(int *)((longlong)pvVar7 + 0x60) + 1;
  *(undefined8 *)((longlong)pvVar7 + 0x40) = 0;
  *(undefined8 *)((longlong)pvVar7 + 0x48) = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)((longlong)pvVar7 + 0x50) = *(undefined8 *)(param_2 + 0x38);
  PVar1 = param_2[0x78];
  *(undefined4 *)((longlong)pvVar7 + 4) = 0;
  *(PBC_REQUEST *)((longlong)pvVar7 + 8) = PVar1;
  *(undefined1 *)((longlong)pvVar7 + 0x38) = 0;
  *(undefined1 *)((longlong)pvVar7 + 100) = 0;
  lVar8 = *(longlong *)(param_2 + 0x50);
  *(longlong *)((longlong)pvVar7 + 0x10) = lVar8;
  *(undefined8 *)((longlong)pvVar7 + 0x18) = *(undefined8 *)(param_2 + 0x28);
  if (lVar8 == 0) {
    uVar11 = 0x500;
    if ((*(longlong *)(param_2 + 0x38) == 1) && (uVar11 = 0x500, param_2[0x78] == (PBC_REQUEST)0x1))
    {
      uVar11 = 0x700;
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x28),uVar11);
    uVar12 = *(ulonglong *)(param_2 + 0x38);
    if (((1 < uVar12) && (param_2[0x78] == (PBC_REQUEST)0x0)) ||
       ((2 < uVar12 && (param_2[0x78] == (PBC_REQUEST)0x1)))) {
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x2c),0x100);
      uVar12 = *(ulonglong *)(param_2 + 0x38);
    }
    if ((1 < uVar12) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),0x300);
    }
    local_5c = *(undefined4 *)(param_1 + 0x1c);
    local_60 = *(int *)(param_1 + 0x18) + 0x230;
    *(undefined1 *)((longlong)pvVar7 + 100) = 1;
    local_58 = *(undefined4 *)((longlong)pvVar7 + 0x50);
    local_70[0] = 1;
    uVar5 = EvtProgramDmaTx(*(WDFDMATRANSACTION__ **)(param_1 + 0x128),*(WDFDEVICE__ **)param_1,
                            pvVar7,1,(_SCATTER_GATHER_LIST *)local_70);
    if (uVar5 == '\0') {
      iVar6 = -0x3fffffff;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar2 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
             (((uVar2 >> 0xc & 1) != 0 && (uVar14 == 1)))) ||
            (((uVar2 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
           (((uVar2 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14);
      }
      *(undefined1 *)((longlong)pvVar7 + 100) = 0;
    }
    goto LAB_1400189c1;
  }
  bVar13 = 0;
  uVar12 = 0;
  iVar6 = -0x3ffffffc;
  if (*(longlong *)(param_2 + 0x28) != 0) {
    for (puVar9 = *(undefined8 **)(param_2 + 0x50); puVar9 != (undefined8 *)0x0;
        puVar9 = (undefined8 *)*puVar9) {
      if (uVar12 < *(uint *)(puVar9 + 5)) {
        if ((*(byte *)((longlong)puVar9 + 10) & 5) == 0) {
          lVar8 = MmMapLockedPagesSpecifyCache(puVar9,0,1,0);
        }
        else {
          lVar8 = puVar9[3];
        }
        if (lVar8 != 0) {
          bVar13 = *(byte *)(lVar8 + uVar12);
          iVar6 = 0;
        }
        break;
      }
      uVar12 = uVar12 - *(uint *)(puVar9 + 5);
    }
  }
  if (iVar6 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar6;
    }
    uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar2 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar2 >> 0xb & 1) == 0 || (uVar14 != 0)) &&
        (((((uVar2 >> 0xc & 1) == 0 || (uVar14 != 1)) &&
          (((uVar2 >> 0xd & 1) == 0 || (uVar14 != 2)))) &&
         (((((uVar2 >> 0xe & 1) == 0 || (uVar14 != 3)) &&
           (((uVar2 >> 0xf & 1) == 0 || (uVar14 != 4)))) &&
          ((((uVar2 >> 0x10 & 1) == 0 || (uVar14 != 5)) && (uVar14 < 6)))))))))) goto LAB_1400189c1;
    uVar10 = 0x1b;
LAB_1400184b4:
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
              &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14,(char)iVar6);
  }
  else {
    uVar11 = bVar13 | 0x400;
    if ((*(longlong *)(param_2 + 0x38) == 1) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      uVar11 = bVar13 | 0x600;
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x28),uVar11);
    if ((1 < *(ulonglong *)(param_2 + 0x38)) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      bVar13 = 0;
      iVar6 = -0x3ffffffc;
      uVar12 = *(ulonglong *)(param_2 + 0x38) - 1;
      if (uVar12 < *(ulonglong *)(param_2 + 0x28)) {
        for (puVar9 = *(undefined8 **)(param_2 + 0x50); puVar9 != (undefined8 *)0x0;
            puVar9 = (undefined8 *)*puVar9) {
          if (uVar12 < *(uint *)(puVar9 + 5)) {
            if ((*(byte *)((longlong)puVar9 + 10) & 5) == 0) {
              lVar8 = MmMapLockedPagesSpecifyCache(puVar9,0,1);
            }
            else {
              lVar8 = puVar9[3];
            }
            if (lVar8 != 0) {
              bVar13 = *(byte *)(lVar8 + uVar12);
              iVar6 = 0;
            }
            break;
          }
          uVar12 = uVar12 - *(uint *)(puVar9 + 5);
        }
      }
      if (iVar6 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar6;
        }
        uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar2 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           (((((((uVar2 >> 0xb & 1) == 0 || (uVar14 != 0)) &&
               (((uVar2 >> 0xc & 1) == 0 || (uVar14 != 1)))) &&
              (((uVar2 >> 0xd & 1) == 0 || (uVar14 != 2)))) &&
             ((((uVar2 >> 0xe & 1) == 0 || (uVar14 != 3)) &&
              (((uVar2 >> 0xf & 1) == 0 || (uVar14 != 4)))))) &&
            ((((uVar2 >> 0x10 & 1) == 0 || (uVar14 != 5)) && (uVar14 < 6)))))) goto LAB_1400189c1;
        uVar10 = 0x1c;
        goto LAB_1400184b4;
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),bVar13 | 0x200);
    }
    if (param_2[0x78] == (PBC_REQUEST)0x0) {
      uVar11 = HWREG<unsigned_long>::Read
                         ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 8));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),uVar11 | 0x10);
    }
    uVar3 = *(undefined8 *)(param_1 + 0x128);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0xcb0);
    _guard_check_icall();
    iVar6 = (*pcVar4)(WdfDriverGlobals,uVar3,EvtProgramDmaTx,1);
    if (iVar6 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
           ((((uVar2 >> 0xc & 1) != 0 && (uVar14 == 1)) ||
            (((uVar2 >> 0xd & 1) != 0 && (uVar14 == 2)))))) ||
          ((((uVar2 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
           (((((uVar2 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
             (((uVar2 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14,(char)iVar6);
      }
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x330);
      _guard_check_icall();
      (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    }
    else {
      *(undefined1 *)((longlong)pvVar7 + 0x38) = 1;
      *(undefined1 *)((longlong)pvVar7 + 100) = 1;
      uVar3 = *(undefined8 *)(param_1 + 0x128);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x328);
      _guard_check_icall();
      iVar6 = (*pcVar4)(WdfDriverGlobals,uVar3,pvVar7);
      if (iVar6 < 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar2 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
              (((uVar2 >> 0xc & 1) != 0 && (uVar14 == 1)))) ||
             (((uVar2 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
            ((((uVar2 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
             (((((uVar2 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
               (((uVar2 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                    &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14,(char)iVar6);
        }
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x330);
        _guard_check_icall();
        (*pcVar4)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
        *(undefined1 *)((longlong)pvVar7 + 0x38) = 0;
        *(undefined1 *)((longlong)pvVar7 + 100) = 0;
      }
    }
  }
LAB_1400189c1:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar2 >> 0xb & 1) != 0 && (uVar14 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar14 == 1))))
       || (((((uVar2 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
           ((((uVar2 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar14 == 5)))))))) || (5 < uVar14)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar14);
  }
  return iVar6;
}



===== LpssCommonBufferCreate @ 140018a6c =====

/* long __cdecl LpssCommonBufferCreate(struct PBC_DEVICE * __ptr64,struct WDFDMAENABLER__ *
   __ptr64,unsigned __int64,struct _WDF_OBJECT_ATTRIBUTES * __ptr64,struct WDFCOMMONBUFFER__ *
   __ptr64 * __ptr64) */

long __cdecl
LpssCommonBufferCreate
          (PBC_DEVICE *param_1,WDFDMAENABLER__ *param_2,__uint64 param_3,
          _WDF_OBJECT_ATTRIBUTES *param_4,WDFCOMMONBUFFER__ **param_5)

{
  uint uVar1;
  WDFCOMMONBUFFER__ *pWVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  iVar7 = 0;
  while( true ) {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0xa8);
    _guard_check_icall();
    iVar4 = (*pcVar3)(WdfDriverGlobals,param_2,param_3,param_4,param_5);
    if (iVar4 != 0) {
      return iVar4;
    }
    pWVar2 = *param_5;
    pcVar3 = *(code **)(WdfFunctions_01015 + 0xb8);
    _guard_check_icall();
    uVar5 = (*pcVar3)(WdfDriverGlobals,pWVar2);
    if (0x1f < iVar7) break;
    if ((int)param_3 - 1U < (uint)((int)param_3 + -1 + (int)uVar5)) {
      return 0;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))
           ) || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
         (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))
          ) || (5 < uVar6)))))) {
      WPP_SF_dDDPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_284edb0c35a1304d74cffcab6cc1d19d_Traceguids,uVar6,
                   (char)((ulonglong)uVar5 >> 0x20),(char)uVar5,(char)param_3,(char)iVar7);
    }
    iVar7 = iVar7 + 1;
  }
  return 0;
}



===== WPP_SF_dDDPd @ 140018bec =====

void WPP_SF_dDDPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,8,&param_8,4,0
           );
  return;
}



===== WPP_SF_ddDDP @ 140018cb0 =====

void WPP_SF_ddDDP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,8,0
           );
  return;
}



===== CheckDmaChannelDisabled @ 140018d74 =====

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



===== DisableDmaChannel @ 140018dac =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar1);
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
        if (99 < iVar4) break;
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar1);
  }
  return uVar3 == 0;
}



===== DisableDmaController @ 140018f64 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar1);
  }
  bVar3 = 0;
  if ((*(uint *)(*(longlong *)(param_1 + 0x110) + 0x398) & 1) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x398) = 0;
    iVar2 = 0;
    uVar4 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x398) & 1;
    bVar3 = (byte)uVar4;
    if (uVar4 != 0) {
      do {
        if (99 < iVar2) break;
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar1);
  }
  return bVar3 ^ 1;
}



===== DmaAcknowledgeInterrupts @ 140019108 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
  }
  return;
}



===== DmaDisableInterrupts @ 1400194a0 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
  }
  return;
}



===== DmaGetInterruptStatus @ 140019610 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
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
                &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,
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
                &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,
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
                  &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
  }
  return uVar4;
}



===== DmaSetInterruptMask @ 140019968 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar2);
  }
  return;
}



===== EvtDmaD0Entry @ 140019b20 =====

/* long __cdecl EvtDmaD0Entry(struct WDFDMAENABLER__ * __ptr64) */

long __cdecl EvtDmaD0Entry(WDFDMAENABLER__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  uint uVar7;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  puVar5 = (undefined8 *)
           (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022050);
  uVar3 = *puVar5;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar6 = (*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  uVar7 = 0xf0;
  if (lVar6 != 0) {
    uVar7 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  if ((*(uint *)(lVar6 + 0x50) & 0x100) == 0) {
    uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(lVar6 + 0x38) + 4));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(lVar6 + 0x38) + 4),uVar4 & 0xfffffffb);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(lVar6 + 0x38) + 4),uVar4 | 4)
    ;
    *(undefined4 *)(*(longlong *)(lVar6 + 0x110) + 0x398) = 1;
    *(undefined1 *)(lVar6 + 0x118) = 1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 9 & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  return 0;
}



===== EvtDmaD0Exit @ 140019d90 =====

/* long __cdecl EvtDmaD0Exit(struct WDFDMAENABLER__ * __ptr64) */

long __cdecl EvtDmaD0Exit(WDFDMAENABLER__ *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  uchar uVar4;
  undefined8 *puVar5;
  PBC_DEVICE *pPVar6;
  uint uVar7;
  long lVar8;
  
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  puVar5 = (undefined8 *)
           (*pcVar2)(WdfDriverGlobals,param_1,PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022050);
  uVar3 = *puVar5;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar6 = (PBC_DEVICE *)(*pcVar2)(WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  uVar7 = 0xf0;
  if (pPVar6 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(pPVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  lVar8 = 0;
  if (pPVar6[0x118] != (PBC_DEVICE)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
    uVar4 = DisableDmaChannel(pPVar6,3);
    if (uVar4 == '\0') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
      lVar8 = -0x3fffffff;
    }
    uVar4 = DisableDmaController(pPVar6);
    if (uVar4 == '\0') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
      lVar8 = -0x3fffffff;
    }
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x310) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x318) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 800) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x328) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x330) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x338) = 3;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x340) = 3;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x348) = 3;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x350) = 3;
    *(undefined4 *)(*(longlong *)(pPVar6 + 0x110) + 0x358) = 3;
    pPVar6[0x118] = (PBC_DEVICE)0x0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  return lVar8;
}



===== EvtProgramDmaRx @ 14001a180 =====

/* unsigned char __cdecl EvtProgramDmaRx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
EvtProgramDmaRx(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
               _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  code *pcVar1;
  uchar uVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  byte bVar9;
  byte bVar8;
  undefined1 local_res18 [16];
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar7 = 0xf0;
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar7 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar4 = (PBC_DEVICE *)(*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  bVar9 = 0;
  bVar8 = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
      ((((((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x148));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
           ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
            ((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
             (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))))))))) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  if (*(int *)((longlong)param_3 + 4) == 0) {
    uVar2 = CheckDmaChannelDisabled(pPVar4,2);
    if (uVar2 == '\x01') {
      *(undefined8 *)((longlong)param_3 + 0x58) = 0;
      if (*(int *)param_5 != 0) {
        lVar3 = 0;
        uVar6 = 0;
        do {
          uVar5 = (int)uVar6 + 1;
          lVar3 = lVar3 + (ulonglong)*(uint *)(param_5 + uVar6 * 0x18 + 0x18);
          *(longlong *)((longlong)param_3 + 0x58) = lVar3;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)param_5);
      }
      FillDmaRxLliBuffer(pPVar4,param_3,param_5);
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x60));
      ProgramDmaAndExecute(pPVar4,param_3);
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x488);
      _guard_check_icall();
      (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x60));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001a67b;
      uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar5 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
             (((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)))))))) ||
          ((((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
           (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
          (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
      if (*(char *)((longlong)param_3 + 0x38) == '\x01') {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x348);
        _guard_check_icall();
        (*pcVar1)(WdfDriverGlobals,param_1,0,local_res18);
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x330);
        _guard_check_icall();
        (*pcVar1)(WdfDriverGlobals,param_1);
        *(undefined1 *)((longlong)param_3 + 0x38) = 0;
      }
      PbcFailDevice(pPVar4);
      bVar9 = 1;
    }
  }
  bVar8 = bVar9;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
LAB_14001a67b:
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x148));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar5 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          ((((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))
           ))) || ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                   (((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)))))) ||
        ((((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
        (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
  }
  return bVar8 ^ 1;
}



===== EvtProgramDmaTx @ 14001a7c0 =====

/* unsigned char __cdecl EvtProgramDmaTx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
EvtProgramDmaTx(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
               _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  code *pcVar1;
  uchar uVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  byte bVar9;
  byte bVar8;
  undefined1 local_res18 [16];
  
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  lVar3 = (*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
  if (lVar3 == 0) {
    uVar7 = 0xf0;
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
    _guard_check_icall();
    lVar3 = (*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078);
    uVar7 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  _guard_check_icall();
  pPVar4 = (PBC_DEVICE *)(*pcVar1)(WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_140022078)
  ;
  bVar9 = 0;
  bVar8 = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
      ((((((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e0);
  _guard_check_icall();
  (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x150));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
           ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
            ((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
             (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))))))))) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
  if (*(int *)((longlong)param_3 + 4) == 0) {
    uVar2 = CheckDmaChannelDisabled(pPVar4,1);
    if (uVar2 == '\x01') {
      *(undefined8 *)((longlong)param_3 + 0x58) = 0;
      if (*(int *)param_5 != 0) {
        lVar3 = 0;
        uVar6 = 0;
        do {
          uVar5 = (int)uVar6 + 1;
          lVar3 = lVar3 + (ulonglong)*(uint *)(param_5 + uVar6 * 0x18 + 0x18);
          *(longlong *)((longlong)param_3 + 0x58) = lVar3;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)param_5);
      }
      FillDmaTxLliBuffer(pPVar4,param_3,param_5);
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x480);
      _guard_check_icall();
      (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x60));
      ProgramDmaAndExecute(pPVar4,param_3);
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x488);
      _guard_check_icall();
      (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x60));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001acbb;
      uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar5 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
             (((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)))))))) ||
          ((((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
           (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
          (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
      }
      if (*(char *)((longlong)param_3 + 0x38) == '\x01') {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x348);
        _guard_check_icall();
        (*pcVar1)(WdfDriverGlobals,param_1,0,local_res18);
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x330);
        _guard_check_icall();
        (*pcVar1)(WdfDriverGlobals,param_1);
        *(undefined1 *)((longlong)param_3 + 0x38) = 0;
      }
      PbcFailDevice(pPVar4);
      bVar9 = 1;
    }
  }
  bVar8 = bVar9;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
      ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
       (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
  }
LAB_14001acbb:
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e8);
  _guard_check_icall();
  (*pcVar1)(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x150));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar5 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          ((((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)))
           ))) || ((((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                   (((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)))))) ||
        ((((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || ((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
        (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
  }
  return bVar8 ^ 1;
}



===== FillDmaRxLliBuffer @ 14001ae00 =====

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
  undefined8 local_68;
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
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
              &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,(char)local_70);
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
              &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,(char)local_78);
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
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
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
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,(char)local_res20,
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
        goto LAB_14001b399;
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
LAB_14001b399:
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
                 &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
      }
    }
    else {
      piVar3[5] = local_68._4_4_;
      piVar3[6] = 0x18202404;
      piVar3[4] = (int)local_68;
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
        goto LAB_14001b399;
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
                          &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5,
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
  }
  return;
}



===== FillDmaTxLliBuffer @ 14001b5ac =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9);
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
              &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,(char)uVar12);
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
              &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,(char)local_74);
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
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9);
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
                     &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,(char)uVar11,
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
LAB_14001ba52:
          pcVar10 = "RDREQ";
          if (*(longlong *)(param_2 + 0x48) != 0) {
            pcVar10 = "WRITE";
          }
          WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                     &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,uVar14,pcVar10);
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
        goto LAB_14001ba52;
      }
      iVar2 = *(int *)(param_1 + 0x18) + 0x228;
LAB_14001bb68:
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
                     &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,uVar14,pcVar10);
        }
        iVar2 = *(int *)(param_1 + 0x18) + 0x230;
        goto LAB_14001bb68;
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
                    &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,uVar14,pcVar10,
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
                     &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,(char)uVar12,
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
          goto LAB_14001c023;
        }
      }
      else {
        if (*(longlong *)(param_2 + 0x48) != 0) goto LAB_14001bf02;
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
          goto LAB_14001c023;
        }
      }
    }
    else {
LAB_14001bf02:
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
LAB_14001c023:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9);
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
          goto LAB_14001c023;
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
                &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,(char)local_res10);
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
                          &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9,
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar9);
  }
  return;
}



===== GetCurrentDmaTransferLeft @ 14001c350 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
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
                          &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7,
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
                         &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7,
                         (char)*(undefined4 *)(uVar4 + 4 + lVar8),
                         (char)*(undefined4 *)(uVar4 + lVar8),
                         (char)*(undefined4 *)(uVar4 + 0xc + lVar8),
                         (char)*(undefined4 *)(uVar4 + 8 + lVar8),(char)iVar1,(char)iVar3,
                         (char)uVar6,(char)*(undefined4 *)(uVar4 + 0x18 + lVar8));
      }
      if ((iVar3 == (int)local_res18) && (iVar1 == local_res18._4_4_)) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001c80a;
        uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar6 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
              ((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
               (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
             ((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
              (((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)))))) ||
            ((((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                   &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
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
                &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7,(char)lVar8);
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
               &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar7);
    }
  }
LAB_14001c80a:
  return *(longlong *)(param_2 + 0x58) - local_res8;
}



===== ProgramDmaAndExecute @ 14001c86c =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar5);
  }
  return;
}



===== SuspendDmaChannel @ 14001cb38 =====

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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar4);
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
      for (iVar7 = 0; (uVar8 = uVar8 >> 9 & 1, uVar8 == 0 && (iVar7 < 100)); iVar7 = iVar7 + 1) {
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
      for (iVar7 = 0; (uVar5 = uVar5 >> 9 & 1, uVar5 == 0 && (iVar7 < 100)); iVar7 = iVar7 + 1) {
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
             &WPP_553ffbf95cc03665fd75defcee910c46_Traceguids,uVar4);
  }
  if ((uVar5 == 0) || (uVar8 == 0)) {
    uVar6 = '\0';
  }
  return uVar6;
}



===== WPP_SF_dDDDDDDDD @ 14001cd74 =====

void WPP_SF_dDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                     undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
            &param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_SF_dDDDDDDDDDDD @ 14001ce94 =====

void WPP_SF_dDDDDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4
                        ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        ,undefined1 param_9,undefined1 param_10,undefined1 param_11,
                        undefined1 param_12,undefined1 param_13,undefined1 param_14,
                        undefined1 param_15)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
            &param_9,4,&param_10,4,&param_11,4,&param_12,4,&param_13,4,&param_14,4,&param_15,4,0);
  return;
}



===== WPP_SF_dPPPPPd @ 14001cfd4 =====

void WPP_SF_dPPPPPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,&param_7,8,&param_8,8,
            &param_9,8,&param_10,4,0);
  return;
}



===== WPP_SF_dds @ 14001d0c4 =====

void WPP_SF_dds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,char *param_6)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_6[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar2 = param_6;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pcVar2,lVar4,0);
  return;
}



===== WPP_SF_ddsd @ 14001d190 =====

void WPP_SF_ddsd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  if (param_6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_6[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar2 = param_6;
  }
  local_res20[0] = param_4;
  _guard_check_icall();
  (*pcVar1)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pcVar2,lVar4,&param_7,4,0);
  return;
}



===== GetPciHardwareRevision @ 14001d26c =====

/* long __cdecl GetPciHardwareRevision(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetPciHardwareRevision(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  byte local_res8 [8];
  undefined4 in_stack_ffffffffffffff78;
  undefined2 uVar8;
  undefined1 local_68 [8];
  undefined8 local_60;
  code *local_30;
  
  uVar8 = (undefined2)((uint)in_stack_ffffffffffffff78 >> 0x10);
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_10663fa1706e3b80625091261d14b191_Traceguids,uVar7);
  }
  uVar2 = *(undefined8 *)param_1;
  local_res8[0] = 0;
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x418);
  _guard_check_icall();
  iVar4 = (*pcVar3)(WdfDriverGlobals,uVar2,&GUID_BUS_INTERFACE_STANDARD,local_68,
                    CONCAT22(uVar8,0x40),1,0);
  if (-1 < iVar4) {
    _guard_check_icall();
    iVar5 = (*local_30)(local_60,0,local_res8,8,1);
    if (iVar5 == 1) {
      lVar6 = 0;
      *param_2 = (uint)local_res8[0];
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
           ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))))) ||
          ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_10663fa1706e3b80625091261d14b191_Traceguids,uVar7,local_res8[0]);
      }
      goto LAB_14001d4d4;
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_10663fa1706e3b80625091261d14b191_Traceguids,uVar7,(char)iVar4);
  }
  lVar6 = -0x3fffffff;
  *param_2 = 0xff;
LAB_14001d4d4:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_10663fa1706e3b80625091261d14b191_Traceguids,uVar7);
  }
  return lVar6;
}



===== __security_check_cookie @ 14001d580 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 14001d5a0 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 14001d5b0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 14001d5c0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001d5e0 =====

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



===== _vsnwprintf @ 14001d640 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnwprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}



===== wcsnlen @ 14001d646 =====

size_t __cdecl wcsnlen(wchar_t *_Src,size_t _MaxCount)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = wcsnlen(_Src,_MaxCount);
  return sVar1;
}



===== wcsncmp @ 14001d64c =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d64c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcsncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 14001d654 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140022140);
  WdfVersionUnbind(&DAT_140022290,&DAT_140022140,WdfDriverGlobals);
  return;
}



===== entry @ 14001d690 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14001d6bc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140022298 = &DAT_1400222d0;
    _DAT_140022290 = 0x2080000;
    _DAT_1400222b8 = param_1;
    RtlCopyUnicodeString(&DAT_140022290);
    iVar1 = WdfVersionBind(param_1,&DAT_140022290,&DAT_140022140,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(code **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140022140);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_1400222a0 = *(longlong *)(param_1 + 0x68);
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



===== FxStubDriverMiniportUnload @ 14001d7f0 =====

void __cdecl FxStubDriverMiniportUnload(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140022140);
  WdfVersionUnbind(&DAT_140022290,&DAT_140022140,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 14001d800 =====

void FxStubDriverUnload(undefined8 param_1)

{
  code *pcVar1;
  
  pcVar1 = DAT_1400222a0;
  if ((DAT_1400222a0 != (code *)0x0) && (DAT_1400222a0 != FxStubDriverUnload)) {
    _guard_check_icall();
    (*pcVar1)(param_1);
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 14001d844 =====

/* WARNING: Removing unreachable block (ram,0x00014001d879) */
/* WARNING: Removing unreachable block (ram,0x00014001d880) */
/* WARNING: Removing unreachable block (ram,0x00014001d8bc) */
/* WARNING: Removing unreachable block (ram,0x00014001d886) */
/* WARNING: Removing unreachable block (ram,0x00014001d88e) */
/* WARNING: Removing unreachable block (ram,0x00014001d89d) */
/* WARNING: Removing unreachable block (ram,0x00014001d866) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 14001d8c4 =====

/* WARNING: Removing unreachable block (ram,0x00014001d8f0) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = &_SPBCx_BIND_INFO;
  while( true ) {
    if ((int *)0x1400221cf < piVar3) {
      return iVar2;
    }
    if (*piVar3 != 0x50) break;
    pcVar1 = *(code **)(piVar3 + 0xe);
    PTR___KMDF_CLASS_BIND_START_1400221d8 = (undefined *)piVar3;
    if (pcVar1 == (code *)0x0) {
      iVar2 = WdfVersionBindClass(param_1,WdfDriverGlobals,piVar3);
    }
    else {
      _guard_check_icall();
      iVar2 = (*pcVar1)(WdfVersionBindClass,param_1,WdfDriverGlobals,piVar3);
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar3 = piVar3 + 0x14;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 14001d970 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  
  puVar2 = &_SPBCx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400221d8 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14002217f < PTR___KMDF_CLASS_BIND_START_1400221d8)) {
    do {
      pcVar1 = *(code **)(puVar2 + 0x10);
      if (pcVar1 == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar2);
      }
      else {
        _guard_check_icall();
        (*pcVar1)(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar2);
      }
      puVar2 = puVar2 + 0x14;
    } while (puVar2 <= PTR___KMDF_CLASS_BIND_START_1400221d8);
  }
  return;
}



===== WdfVersionBind @ 14001d9fa =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001d9fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 14001da00 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001da00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 14001da10 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001da10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 14001da20 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001da20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_dispatch_icall @ 14001da40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001da40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 14001da80 =====

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
        if (uVar12 == 0) goto LAB_14001dc37;
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
LAB_14001dc37:
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
      if (uVar12 == 0) goto LAB_14001da92;
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
LAB_14001da92:
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



===== memset @ 14001ddc0 =====

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

void WppCleanupKm(void)

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
          _guard_check_icall();
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



===== WppInitKm @ 14002408c =====

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
        *(undefined8 *)(puVar2 + 0x38) = 0;
        pcVar1 = pfnEtwRegisterClassicProvider;
        _guard_check_icall();
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



===== WppLoadTracingSupport @ 140024128 =====

void WppLoadTracingSupport(void)

{
  code *pcVar1;
  uint local_res8 [2];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  pcVar1 = pfnWppGetVersion;
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    _guard_check_icall();
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



===== WppTraceCallback @ 140024230 =====

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar5 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          lVar8 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),param_4 + 6,0x10);
          if (lVar8 == 0x10) break;
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
          _guard_check_icall();
          iVar6 = (*pcVar4)(3,local_res8,4,&param_6,param_4);
          if (iVar6 == 0) {
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          pcVar4 = pfnWppQueryTraceInformation;
          _guard_check_icall();
          uVar7 = (*pcVar4)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar7;
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
      lVar8 = param_5;
      do {
        lVar8 = *(longlong *)(lVar8 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar8 != 0);
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
        uVar9 = (ulonglong)uVar10;
        puVar13 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar13 = 0x81000;
          *(undefined8 *)(puVar13 + -4) = uVar2;
          *(undefined8 *)(puVar13 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar9 = uVar9 - 1;
          puVar13 = puVar13 + 8;
        } while (uVar9 != 0);
      }
      *puVar5 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 140025000 =====

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


