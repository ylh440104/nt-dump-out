
===== _tlgWriteEx_EtwWriteEx @ 140001008 =====

void _tlgWriteEx_EtwWriteEx(undefined8 param_1,byte *param_2)

{
  undefined8 *in_stack_00000040;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *in_stack_00000040 = PTR_DAT_14000c088;
  *(uint *)(in_stack_00000040 + 1) = (uint)*(ushort *)PTR_DAT_14000c088;
  in_stack_00000040[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)in_stack_00000040 + 0xc) = 2;
  *(uint *)(in_stack_00000040 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)in_stack_00000040 + 0x1c) = 1;
  EtwWriteEx(DAT_14000c0a0,&local_18,0,1,0,0);
  return;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010c8 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_14000c088;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000c088;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000c0a0,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 140001180 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AdapterClassStatusNotify @ 140001190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
AdapterClassStatusNotify(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
                    /* 0x1190  2  AdapterClassStatusNotify */
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar3 = 0;
  lVar2 = param_1;
  uVar1 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    uVar3 = 0xc00000bb;
    param_1 = lVar2;
  }
  else if (param_1 == PowerAdapter) {
    LOCK();
    *(undefined4 *)(param_1 + 0x120) = 1;
    UNLOCK();
    BattCAdapterQueueWorker(param_1,'\x01',param_3,param_4);
  }
  else {
    uVar3 = 0xc000000d;
    param_1 = lVar2;
  }
  if (5 < DAT_14000c080) {
    local_14 = 0;
    local_20 = local_48;
    local_18 = 4;
    local_48[0] = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140007e70,param_3,param_4,3,local_40);
  }
  return uVar3;
}



===== BattCConfigureIdleResiliencyPollTimer @ 14000124c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BattCConfigureIdleResiliencyPollTimer(longlong param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte *pbVar5;
  uint uVar6;
  undefined1 auStack_168 [48];
  undefined4 local_138;
  undefined1 *local_130;
  undefined1 local_128 [4];
  undefined4 local_124;
  uint local_120;
  uint local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined8 local_100;
  undefined1 local_f8 [32];
  undefined4 *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  uVar2 = 0;
  uVar6 = 0;
  lVar4 = param_1;
  if ((PlatformAoAc == '\0') || (lVar4 = *(longlong *)(param_1 + 0x2f0), lVar4 == 0)) {
LAB_140001330:
    uVar2 = 0xc00000bb;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 0) {
        ExCancelTimer(lVar4,0);
        *(undefined4 *)(param_1 + 0x2f8) = 0;
      }
      else if (param_2 == 2) {
        if (*(int *)(param_1 + 0x2f8) == 1) {
          BattCConfigureIdleResiliencyPollTimer(param_1,0);
        }
        lVar4 = param_1;
        uVar2 = BattCConfigureIdleResiliencyPollTimer(param_1,1);
      }
      else {
        uVar2 = 0xc000000d;
      }
      goto LAB_140001335;
    }
    uVar6 = 0x78;
    if (BatteryIRTimerDurationRegistry != 0) {
      if (BatteryIRTimerDurationRegistry == 0xffffffff) goto LAB_140001330;
      uVar6 = BatteryIRTimerDurationRegistry;
    }
    ExSetTimer(lVar4,(ulonglong)uVar6 * -600000000,0,0);
    *(undefined4 *)(param_1 + 0x2f8) = 1;
  }
LAB_140001335:
  uVar3 = Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledDeviceUsageNoInline
                    ();
  if ((int)uVar3 == 0) {
    if (param_1 == 0) {
      return uVar2;
    }
    if (DAT_14000c080 < 6) {
      return uVar2;
    }
    if (((_DAT_14000c090 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
      bVar1 = false;
    }
    if (!bVar1) {
      return uVar2;
    }
    local_10c = *(undefined4 *)(param_1 + 0x2e4);
    pbVar5 = &DAT_140007ac7;
    local_d8 = &local_10c;
    local_c8 = &local_110;
    local_b8 = &local_114;
    local_118 = *(undefined4 *)(param_1 + 0x2f8);
    local_11c = *(uint *)(param_1 + 0x300);
    local_98 = &local_11c;
    local_120 = *(uint *)(param_1 + 0x304);
    local_88 = &local_120;
    local_124 = *(undefined4 *)(param_1 + 0x310);
    local_78 = &local_124;
    local_128[0] = *(undefined1 *)(param_1 + 0x2ec);
    local_68 = (undefined4 *)local_128;
    local_48 = &local_100;
    local_138 = 0xc;
    local_70 = 4;
    local_60 = 1;
    local_108 = CONCAT44(local_108._4_4_,uVar2);
    local_50 = 4;
    local_100 = 0x1000000;
    local_40 = 8;
    local_114 = uVar6;
    local_110 = param_2;
  }
  else {
    if (param_1 == 0) {
      return uVar2;
    }
    if (param_2 != 1) {
      return uVar2;
    }
    if (DAT_14000c080 < 6) {
      return uVar2;
    }
    if (((_DAT_14000c090 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
      bVar1 = false;
    }
    if (!bVar1) {
      return uVar2;
    }
    local_124 = *(undefined4 *)(param_1 + 0x2e4);
    pbVar5 = &DAT_140008209;
    local_d8 = &local_124;
    local_c8 = &local_120;
    local_11c = *(uint *)(param_1 + 0x2f8);
    local_b8 = &local_11c;
    local_118 = *(undefined4 *)(param_1 + 0x300);
    local_98 = &local_114;
    local_110 = *(uint *)(param_1 + 0x310);
    local_88 = &local_110;
    local_128[0] = *(undefined1 *)(param_1 + 0x2ec);
    local_78 = (undefined4 *)local_128;
    local_68 = &local_10c;
    local_138 = 0xb;
    local_70 = 1;
    local_60 = 4;
    local_108 = 0x1000000;
    local_50 = 8;
    local_120 = uVar6;
    local_114 = *(uint *)(param_1 + 0x304);
    local_10c = uVar2;
  }
  local_58 = &local_108;
  local_a0 = 4;
  local_a8 = &local_118;
  local_b0 = 4;
  local_c0 = 4;
  local_d0 = 4;
  local_130 = local_f8;
  local_90 = 4;
  local_80 = 4;
  _tlgWriteEx_EtwWriteEx(lVar4,pbVar5);
  return uVar2;
}



===== BattCIdleResiliencyPollTimerDispatch @ 140001620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCIdleResiliencyPollTimerDispatch
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStack_88 [48];
  undefined4 local_58;
  undefined1 *local_50;
  undefined4 local_48 [2];
  undefined1 local_40 [32];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  BatteryIRTimerFired = 1;
  uVar1 = param_2;
  BatteryClassStatusNotify(param_2,param_2,param_3,param_4);
  if (5 < DAT_14000c080) {
    local_48[0] = *(undefined4 *)(param_2 + 0x2e4);
    local_14 = 0;
    local_20 = local_48;
    local_50 = local_40;
    local_58 = 3;
    local_18 = 4;
    _tlgWriteEx_EtwWriteEx(uVar1,&DAT_1400078c5);
  }
  return;
}



===== BatteryClassPeakPowerNotify @ 1400016b0 =====

undefined8
BatteryClassPeakPowerNotify
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
                    /* 0x16b0  6  BatteryClassPeakPowerNotify */
  uVar1 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  uVar2 = 0;
  if ((int)uVar1 == 0) {
    uVar2 = 0xc00000bb;
  }
  else if (param_1 == 0) {
    uVar2 = 0xc000000d;
  }
  else {
    LOCK();
    *(undefined4 *)(param_1 + 0x134) = 1;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x138) = 1;
    UNLOCK();
    BattCQueueWorker(param_1,'\x01',param_3,param_4);
  }
  return uVar2;
}



===== BatteryClassStatusNotify @ 140001710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BatteryClassStatusNotify(ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong *puVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  byte *pbVar8;
  ulonglong uVar9;
  bool bVar10;
  undefined1 auStackY_1b8 [32];
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c [13];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 *local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 *local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8 [4];
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
                    /* 0x1710  8  BatteryClassStatusNotify */
  uVar6 = _DAT_fffff78000000008;
  local_28 = __security_cookie ^ (ulonglong)auStackY_1b8;
  LOCK();
  puVar1 = (ulonglong *)(param_1 + 0x1d8);
  uVar7 = *puVar1;
  *puVar1 = *puVar1;
  UNLOCK();
  LOCK();
  *(int *)(param_1 + 0x1d0) = *(int *)(param_1 + 0x1d0) + 1;
  UNLOCK();
  uVar9 = FastestStatusNotifyUpdateInterval + uVar7;
  if ((uVar6 < uVar9) && (*(char *)(param_1 + 0x178) == '\0')) {
    LOCK();
    iVar2 = *(int *)(param_1 + 0x1d4);
    *(int *)(param_1 + 0x1d4) = 1;
    UNLOCK();
    if (iVar2 != 0) goto LAB_140001a3a;
    uVar5 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 != 0) && (5 < DAT_14000c080)) {
      local_174 = *(undefined4 *)(param_1 + 0x2e4);
      local_5c = 0;
      local_68 = &local_174;
      local_60 = 4;
      _tlgWriteEx_EtwWriteEx(uVar7,&DAT_1400074a5);
    }
    uVar7 = param_1 + 0x1e0;
    cVar4 = KeSetCoalescableTimer(uVar7,uVar6 - uVar9,0,0xfa);
    if (cVar4 != '\0') goto LAB_140001a3a;
    uVar6 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      LOCK();
      *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
      UNLOCK();
      goto LAB_140001a3a;
    }
    if (5 < DAT_14000c080) {
      local_170 = *(undefined4 *)(param_1 + 0x2e4);
      local_2c = 0;
      local_38 = &local_170;
      local_30 = 4;
      _tlgWriteEx_EtwWriteEx(uVar7,&DAT_140007949);
    }
    LOCK();
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
    UNLOCK();
    if (DAT_14000c080 < 6) goto LAB_140001a3a;
    local_16c = *(undefined4 *)(param_1 + 0x2e4);
    pbVar8 = &DAT_140007a7a;
    local_10c = 0;
    local_128 = &local_16c;
    local_178 = *(undefined4 *)(param_1 + 0x17c);
    local_118 = &local_178;
    local_110 = 4;
  }
  else {
    LOCK();
    bVar10 = uVar7 == *(ulonglong *)(param_1 + 0x1d8);
    if (bVar10) {
      *(ulonglong *)(param_1 + 0x1d8) = uVar6;
    }
    UNLOCK();
    if (bVar10) {
      LOCK();
      uVar3 = *(undefined4 *)(param_1 + 0x1d0);
      *(undefined4 *)(param_1 + 0x1d0) = 0;
      UNLOCK();
      uVar6 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        if (5 < DAT_14000c080) {
          local_160 = *(undefined4 *)(param_1 + 0x2e4);
          local_9c = 0;
          local_8c = 0;
          local_a8 = &local_160;
          local_98 = local_15c;
          local_a0 = 4;
          local_90 = 4;
          local_15c[0] = uVar3;
          _tlgWriteTransfer_EtwWriteTransfer(uVar7,&DAT_140007900,param_3,param_4,4,local_c8);
        }
      }
      else if (5 < DAT_14000c080) {
        local_168 = *(undefined4 *)(param_1 + 0x2e4);
        local_dc = 0;
        local_cc = 0;
        local_e8 = &local_168;
        local_d8 = &local_164;
        local_e0 = 4;
        local_d0 = 4;
        local_164 = uVar3;
        _tlgWriteEx_EtwWriteEx(uVar7,&DAT_140007989);
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x134) = 1;
      UNLOCK();
      LOCK();
      *(undefined4 *)(param_1 + 0x138) = 1;
      UNLOCK();
      uVar7 = param_1;
      BattCQueueWorker(param_1,'\x01',param_3,param_4);
      uVar6 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar6 == 0) || (DAT_14000c080 < 6)) goto LAB_140001a3a;
      pbVar8 = &DAT_140007c07;
    }
    else {
      uVar6 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar6 == 0) || (DAT_14000c080 < 6)) goto LAB_140001a3a;
      pbVar8 = &DAT_140007111;
    }
    local_178 = *(undefined4 *)(param_1 + 0x2e4);
    local_128 = &local_178;
  }
  local_11c = 0;
  local_120 = 4;
  _tlgWriteEx_EtwWriteEx(uVar7,pbVar8);
LAB_140001a3a:
  uVar7 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    BattCConfigureIdleResiliencyPollTimer(param_1,2);
  }
  return 0;
}



===== Feature_1178837306__private_IsEnabledDeviceUsageNoInline @ 140001a80 =====

ulonglong Feature_1178837306__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1178837306__private_featureState;
  if ((Feature_1178837306__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1178837306__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1178837306__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1178837306__private_IsEnabledFallback @ 140001ab8 =====

void Feature_1178837306__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1178837306__private_descriptor);
  return;
}



===== Feature_1291035962__private_IsEnabledDeviceUsageNoInline @ 140001ad4 =====

ulonglong Feature_1291035962__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1291035962__private_featureState;
  if ((Feature_1291035962__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1291035962__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1291035962__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1291035962__private_IsEnabledFallback @ 140001b0c =====

void Feature_1291035962__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1291035962__private_descriptor);
  return;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline @ 140001b28 =====

ulonglong Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_EE_MPTF_Functionality__private_featureState;
  if ((Feature_EE_MPTF_Functionality__private_featureState & 0x10) == 0) {
    uVar1 = Feature_EE_MPTF_Functionality__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_EE_MPTF_Functionality__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledFallback @ 140001b60 =====

void Feature_EE_MPTF_Functionality__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_EE_MPTF_Functionality__private_descriptor);
  return;
}



===== Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledDeviceUsageNoInline @ 140001b7c =====

ulonglong Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)
               Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_featureState;
  if ((Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_featureState & 0x10) ==
      0) {
    uVar1 = Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledFallback
                      (local_res8,3);
  }
  else {
    uVar1 = (ulonglong)
            (Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledFallback @ 140001bb4 =====

void Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,
             &Feature_Servicing_BatteryIdleResiliencyTimer_GarrulousEvent__private_descriptor);
  return;
}



===== Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline @ 140001bd0 =====

ulonglong Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_BatteryIdleResiliencyTimer__private_featureState;
  if ((Feature_Servicing_BatteryIdleResiliencyTimer__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_BatteryIdleResiliencyTimer__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledFallback @ 140001c08 =====

void Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_BatteryIdleResiliencyTimer__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001c24 =====

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
LAB_140001e2d:
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
LAB_140001cff:
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
      if (param_3 == 4) goto LAB_140001e2d;
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
        goto LAB_140001cff;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001f18 =====

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
      goto LAB_140001fe9;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140001fe9;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140001fe9;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140001fe9;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140001fe9;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140001fe9;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140001fe9;
    }
  }
  uVar3 = 0xff;
LAB_140001fe9:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002040 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002130 =====

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
LAB_1400021e3:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140002211;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400021e3;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140002211:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000239c =====

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



===== wil_details_IsEnabledFallback @ 140002400 =====

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



===== wil_details_RecordCachedUsage @ 140002494 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400025f0 =====

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



===== AcAdapterBackupDpc @ 140002680 =====

void AcAdapterBackupDpc(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  
  AdapterClassStatusNotify(param_2,param_2,param_3,param_4);
  LOCK();
  piVar1 = (int *)(param_2 + 0x1a8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x1b0,0,0);
  }
  return;
}



===== AcAdapterCancelStatus @ 1400026d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AcAdapterCancelStatus
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  undefined4 local_94;
  longlong local_90;
  undefined8 local_88 [4];
  longlong *local_68;
  undefined8 local_60;
  char *local_58;
  uint local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  char *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  BattCAdapterQueueWorker
            (*(longlong *)(*(longlong *)(param_2 + 0xb8) + -0x28),'\x01',param_3,param_4);
  uVar3 = Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    if (((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1) && (5 < DAT_14000c080)) {
      lVar2 = *(longlong *)(param_2 + 0xb8);
      local_68 = &local_90;
      local_60 = 8;
      iVar1 = *(int *)(lVar2 + 0x18);
      if (iVar1 == 0x294070) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
      }
      else if (iVar1 == 0x29406c) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
      }
      else {
        local_58 = "IOCTL_POWER_ADAPTER_SET_STATUS";
        if (iVar1 != 0x294074) {
          local_58 = "<invalid>";
        }
      }
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_58[lVar4] != '\0');
      local_50 = (int)lVar4 + 1;
      local_4c = 0;
      local_94 = *(undefined4 *)(lVar2 + 0x18);
      local_48 = &local_94;
      local_98 = *(undefined4 *)(param_2 + 0x30);
      local_38 = &local_98;
      local_28 = "AcAdapterCancelStatus";
      local_40 = 4;
      local_30 = 4;
      local_20 = 0x16;
      local_90 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_50,&DAT_140009ca4,lVar2,param_4,7,local_88);
    }
  }
  else {
    if (((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1) && (5 < DAT_14000c080)) {
      lVar2 = *(longlong *)(param_2 + 0xb8);
      local_68 = &local_90;
      local_60 = 8;
      iVar1 = *(int *)(lVar2 + 0x18);
      if (iVar1 == 0x294070) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
      }
      else if (iVar1 == 0x29406c) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
      }
      else {
        local_58 = "IOCTL_POWER_ADAPTER_SET_STATUS";
        if (iVar1 != 0x294074) {
          local_58 = "<invalid>";
        }
      }
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_58[lVar4] != '\0');
      local_50 = (int)lVar4 + 1;
      local_4c = 0;
      local_98 = *(undefined4 *)(lVar2 + 0x18);
      local_48 = &local_98;
      local_94 = *(undefined4 *)(param_2 + 0x30);
      local_38 = &local_94;
      local_28 = "AcAdapterCancelStatus";
      local_40 = 4;
      local_30 = 4;
      local_20 = 0x16;
      local_90 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_50,&DAT_1400099b9,lVar2,param_4,7,local_88);
    }
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  }
  return;
}



===== BattCClearCancelRoutine @ 140002940 =====

void BattCClearCancelRoutine(longlong param_1)

{
  IoAcquireCancelSpinLock(param_1 + 0x45);
  LOCK();
  *(undefined8 *)(param_1 + 0x68) = 0;
  UNLOCK();
  IoReleaseCancelSpinLock(*(undefined1 *)(param_1 + 0x45));
  return;
}



===== BattCAcDcUpdateStormCancellationDpc @ 140002990 =====

void BattCAcDcUpdateStormCancellationDpc
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  *(undefined4 *)(param_2 + 0x2e0) = 1;
  UNLOCK();
  LOCK();
  *(int *)(param_2 + 0x1d0) = *(int *)(param_2 + 0x1d0) + -1;
  UNLOCK();
  BatteryClassStatusNotify(param_2,param_2,param_3,param_4);
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return;
}



===== BattCAdapterQueueWorker @ 1400029e8 =====

void BattCAdapterQueueWorker(longlong param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  
  if (param_2 != '\0') {
    LOCK();
    *(undefined4 *)(param_1 + 0x11c) = 1;
    UNLOCK();
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x118);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    if ((*(char *)(param_1 + 0x1ac) != '\0') &&
       (lVar4 = param_1, cVar3 = KeGetCurrentIrql(), cVar3 == '\0')) {
      BattCAdapterCompleteIrpQueue(lVar4,(longlong *)(param_1 + 0xc0),(char *)0xc00002b6,param_4);
      BattCAdapterCompleteIrpQueue(lVar4,(longlong *)(param_1 + 0xd0),(char *)0xc00002b6,param_4);
      LOCK();
      piVar1 = (int *)(param_1 + 0x1a8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(param_1 + 0x1b0,0,0);
        return;
      }
      return;
    }
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0xb8),AcAdapterWorkerThread,1,param_1);
  }
  return;
}



===== BattCBatteryPollingDpc @ 140002ab0 =====

void BattCBatteryPollingDpc
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  *(int *)(param_2 + 0x1d0) = *(int *)(param_2 + 0x1d0) + -1;
  UNLOCK();
  BatteryClassStatusNotify(param_2,param_2,param_3,param_4);
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return;
}



===== BattCCancelStatus @ 140002b00 =====

void BattCCancelStatus(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  BattCQueueWorker(*(longlong *)(*(longlong *)(param_2 + 0xb8) + -0x28),'\x01',param_3,param_4);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  return;
}



===== BattCCancelTag @ 140002b40 =====

void BattCCancelTag(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + -0x28);
  LOCK();
  *(undefined4 *)(lVar1 + 0x130) = 1;
  UNLOCK();
  BattCQueueWorker(lVar1,'\0',param_3,param_4);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  return;
}



===== BattCCompleteIrpQueue @ 140002b84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCCompleteIrpQueue(longlong param_1,longlong *param_2,char *param_3,undefined8 param_4)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0 [2];
  longlong *local_b8 [2];
  undefined8 local_a8 [4];
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong **local_78;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  puVar6 = auStackY_f8;
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  pcVar7 = param_3;
  do {
    plVar3 = (longlong *)*param_2;
    if (plVar3 == param_2) {
LAB_140002db2:
      *(undefined8 *)(puVar6 + -8) = 0x140002dbe;
      return;
    }
    if (((longlong *)plVar3[1] != param_2) || (lVar5 = *plVar3, *(longlong **)(lVar5 + 8) != plVar3)
       ) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStackY_f0;
      goto LAB_140002db2;
    }
    *param_2 = lVar5;
    plVar1 = plVar3 + -0x15;
    *(longlong **)(lVar5 + 8) = param_2;
    BattCClearCancelRoutine((longlong)plVar1);
    *(int *)(plVar3 + -0xf) = (int)param_3;
    if (((int)*(char *)((longlong)plVar3 + -0x65) <= *(char *)((longlong)plVar3 + -0x66) + 1) &&
       (5 < DAT_14000c080)) {
      local_c8 = *(undefined4 *)(param_1 + 0x2e4);
      local_7c = 0;
      local_6c = 0;
      local_88 = &local_c8;
      local_78 = local_b8;
      local_80 = 4;
      local_70 = 8;
      iVar2 = *(int *)(plVar3[2] + 0x18);
      if (iVar2 == 0x294040) {
        local_68 = "IOCTL_BATTERY_QUERY_TAG";
      }
      else if (iVar2 == 0x294044) {
        local_68 = "IOCTL_BATTERY_QUERY_INFORMATION";
      }
      else if (iVar2 == 0x298048) {
        local_68 = "IOCTL_BATTERY_SET_INFORMATION";
      }
      else if (iVar2 == 0x29404c) {
        local_68 = "IOCTL_BATTERY_QUERY_STATUS";
      }
      else if (iVar2 == 0x294050) {
        local_68 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
      }
      else if (iVar2 == 0x294064) {
        local_68 = "IOCTL_BATTERY_QUERY_STATUS_EX";
      }
      else if (iVar2 == 0x45400c) {
        local_68 = "IOCTL_PMI_GET_MEASUREMENT";
      }
      else if (iVar2 == 0x454000) {
        local_68 = "IOCTL_PMI_GET_CAPABILITIES";
      }
      else if (iVar2 == 0x454004) {
        local_68 = "IOCTL_PMI_GET_CONFIGURATION";
      }
      else if (iVar2 == 0x458008) {
        local_68 = "IOCTL_PMI_SET_CONFIGURATION";
      }
      else {
        local_68 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
        pcVar7 = "<invalid>";
        if (iVar2 != 0x45c010) {
          local_68 = "<invalid>";
        }
      }
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_68[lVar5] != '\0');
      local_5c = 0;
      local_60 = (int)lVar5 + 1;
      local_c4 = *(undefined4 *)(plVar3[2] + 0x18);
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_58 = &local_c4;
      local_48 = local_c0;
      local_38 = "BattCCompleteIrpQueue";
      local_50 = 4;
      local_40 = 4;
      local_30 = 0x16;
      local_c0[0] = (int)param_3;
      local_b8[0] = plVar1;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_60,&DAT_14000a1c3,pcVar7,param_4,8,local_a8);
    }
    IofCompleteRequest(plVar1,0);
  } while( true );
}



===== BattCCompleteWmiQueue @ 140002de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCCompleteWmiQueue(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined4 local_98;
  undefined4 local_94;
  longlong local_90;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  uint local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  puVar5 = auStackY_c8;
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  do {
    plVar2 = (longlong *)*param_2;
    if (plVar2 == param_2) {
LAB_140002f76:
      *(undefined8 *)(puVar5 + -8) = 0x140002f82;
      return;
    }
    if (((longlong *)plVar2[1] != param_2) || (lVar4 = *plVar2, *(longlong **)(lVar4 + 8) != plVar2)
       ) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStackY_c0;
      goto LAB_140002f76;
    }
    *param_2 = lVar4;
    *(longlong **)(lVar4 + 8) = param_2;
    *(undefined4 *)plVar2[5] = 0;
    if (5 < DAT_14000c080) {
      local_98 = *(undefined4 *)(param_1 + 0x2e4);
      local_5c = 0;
      local_4c = 0;
      iVar1 = (int)plVar2[4];
      local_68 = &local_98;
      local_90 = plVar2[3];
      local_58 = &local_90;
      local_60 = 4;
      local_50 = 8;
      if (iVar1 == 0) {
        local_48 = "BattWmiStatusId";
      }
      else if (iVar1 == 1) {
        local_48 = "BattWmiRuntimeId";
      }
      else if (iVar1 == 2) {
        local_48 = "BattWmiTemperatureId";
      }
      else if (iVar1 == 3) {
        local_48 = "BattWmiFullChargedCapacityId";
      }
      else if (iVar1 == 4) {
        local_48 = "BattWmiCycleCountId";
      }
      else {
        local_48 = "BattWmiStaticDataId";
        if (iVar1 != 5) {
          local_48 = "<invalid>";
        }
      }
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_48[lVar4] != '\0');
      local_3c = 0;
      local_2c = 0;
      local_40 = (int)lVar4 + 1;
      local_1c = 0;
      local_38 = &local_94;
      local_28 = "BattCCompleteWmiQueue";
      local_94 = 0xc00002b6;
      local_30 = 4;
      local_20 = 0x16;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_40,&DAT_140008638,param_3,param_4,7,local_88);
    }
    param_4 = 0;
    param_3 = 0xc00002b6;
    WmiCompleteRequest(plVar2[2],plVar2[3]);
  } while( true );
}



===== BattCMiniportStatus @ 140002fa4 =====

void BattCMiniportStatus(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  if (param_2 == -0x3ffffff2) {
    Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
    BattCCompleteIrpQueue
              (*(longlong *)(param_1 + 0xb8),(longlong *)(param_1 + 0x58),(char *)0xc000000e,param_4
              );
  }
  return;
}



===== BattCQueueWorker @ 140002fdc =====

void BattCQueueWorker(longlong param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  if (param_2 != '\0') {
    LOCK();
    *(undefined4 *)(param_1 + 300) = 1;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x130) = 1;
    UNLOCK();
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x128);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    if ((*(char *)(param_1 + 0x178) == '\x01') && (cVar4 = KeGetCurrentIrql(), cVar4 == '\0')) {
      BattCCompleteIrpQueue(param_1,(longlong *)(lVar3 + 0x48),(char *)0xc00002b6,param_4);
      BattCCompleteIrpQueue(param_1,(longlong *)(lVar3 + 0x68),(char *)0xc00002b6,param_4);
      uVar5 = 0xc00002b6;
      BattCCompleteIrpQueue(param_1,(longlong *)(lVar3 + 0x58),(char *)0xc00002b6,param_4);
      BattCCompleteWmiQueue(param_1,(longlong *)(lVar3 + 0x78),uVar5,param_4);
      LOCK();
      piVar1 = (int *)(param_1 + 0x17c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(param_1 + 0x180,0,0);
        return;
      }
      return;
    }
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x120),BattCWorkerThread,1,param_1);
  }
  return;
}



===== BattCStatusNotifyStormQuiesceDpc @ 1400030e0 =====

void BattCStatusNotifyStormQuiesceDpc
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  *(undefined4 *)(param_2 + 0x1d4) = 0;
  UNLOCK();
  LOCK();
  *(int *)(param_2 + 0x1d0) = *(int *)(param_2 + 0x1d0) + -1;
  UNLOCK();
  BatteryClassStatusNotify(param_2,param_2,param_3,param_4);
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return;
}



===== BattCTagDpc @ 140003140 =====

void BattCTagDpc(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  *(undefined4 *)(param_2 + 0x130) = 1;
  UNLOCK();
  BattCQueueWorker(param_2,'\0',param_3,param_4);
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return;
}



===== BattCWmi @ 140003194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCWmi(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  undefined1 auStackY_148 [32];
  undefined4 local_104;
  uint local_100;
  uint local_fc;
  uint local_f8 [2];
  undefined8 local_f0;
  uint local_e8;
  undefined1 uStack_e4;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined8 local_b8 [4];
  uint *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar1 = (uint *)(param_2 + 0x44);
  local_c8 = 0;
  local_104 = 0;
  iVar2 = *(int *)(param_3 + 0x20);
  iVar9 = 0;
  _local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  lVar8 = param_3;
  if (iVar2 == 0) {
    iVar9 = 0x18;
    **(uint **)(param_3 + 0x38) = *puVar1;
    *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 4) = *(undefined4 *)(param_2 + 0x9c);
    if (*(int *)(param_2 + 0xa4) < 0) {
      *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 8) = 0;
      *(int *)(*(longlong *)(param_3 + 0x38) + 0xc) = -*(int *)(param_2 + 0xa4);
    }
    else {
      *(int *)(*(longlong *)(param_3 + 0x38) + 8) = *(int *)(param_2 + 0xa4);
      *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0xc) = 0;
    }
    *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0x10) = *(undefined4 *)(param_2 + 0xa0);
    *(byte *)(*(longlong *)(param_3 + 0x38) + 0x14) = *(byte *)(param_2 + 0x98) & 1;
    *(byte *)(*(longlong *)(param_3 + 0x38) + 0x15) = (byte)(*(uint *)(param_2 + 0x98) >> 2) & 1;
    *(byte *)(*(longlong *)(param_3 + 0x38) + 0x16) = (byte)(*(uint *)(param_2 + 0x98) >> 1) & 1;
    *(byte *)(*(longlong *)(param_3 + 0x38) + 0x17) = (byte)(*(uint *)(param_2 + 0x98) >> 3) & 1;
    uVar3 = 0;
  }
  else {
    if (iVar2 == 1) {
      **(uint **)(param_3 + 0x38) = *puVar1;
      lVar7 = *(longlong *)(param_3 + 0x38);
      lVar8 = 3;
    }
    else {
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          param_4 = 0;
          lVar8 = 0;
          **(uint **)(param_3 + 0x38) = *puVar1;
          uVar3 = BattCQueryInformation(param_2,(ulonglong)*puVar1,0,0,&local_e8);
          uVar5 = (undefined4)local_d8;
        }
        else {
          if (iVar2 != 4) {
            if (iVar2 == 5) {
              iVar9 = 0x478;
              **(uint **)(param_3 + 0x38) = *puVar1;
              uVar3 = BattCQueryInformation(param_2,(ulonglong)*puVar1,5,0,&local_104);
              lVar8 = *(longlong *)(param_3 + 0x38);
              if ((int)uVar3 < 0) {
                builtin_wcsncpy((wchar_t *)(lVar8 + 4),L"****",4);
                builtin_wcsncpy((wchar_t *)(lVar8 + 0xc),L"****",4);
                builtin_wcsncpy((wchar_t *)(lVar8 + 0x14),L"****",4);
                builtin_wcsncpy((wchar_t *)(lVar8 + 0x1c),L"**.*",4);
                builtin_wcsncpy((wchar_t *)(lVar8 + 0x24),L"****",4);
                builtin_wcsncpy((wchar_t *)(lVar8 + 0x2c),L"****",4);
                *(undefined2 *)(lVar8 + 0x34) = 0x2a;
              }
              else {
                RtlStringCbPrintfW((wchar_t *)(lVar8 + 4),0x32,L"%d4%d2%d2******.**********",
                                   (ulonglong)local_104._2_2_);
              }
              lVar8 = *(longlong *)(param_3 + 0x38);
              *(undefined8 *)(lVar8 + 0x38) = 0;
              *(undefined8 *)(lVar8 + 0x40) = 0;
              *(undefined8 *)(lVar8 + 0x48) = 0;
              *(undefined8 *)(lVar8 + 0x50) = 0;
              BattCQueryInformation
                        (param_2,(ulonglong)*puVar1,1,0,
                         (uint *)(*(longlong *)(param_3 + 0x38) + 0x38));
              param_4 = 0;
              lVar8 = 0;
              uVar3 = BattCQueryInformation(param_2,(ulonglong)*puVar1,0,0,&local_e8);
              if (-1 < (int)uVar3) {
                *(uint *)(*(longlong *)(param_3 + 0x38) + 0x58) = local_e8;
                *(undefined1 *)(*(longlong *)(param_3 + 0x38) + 0x5c) = uStack_e4;
                *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0x60) = (undefined4)uStack_e0;
                *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 100) = uStack_e0._4_4_;
                *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0x68) = local_d8._4_4_;
                *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0x6c) = (undefined4)uStack_d0;
                *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 0x70) = uStack_d0._4_4_;
                lVar7 = *(longlong *)(param_3 + 0x38);
                BattCQueryInformation(param_2,(ulonglong)*puVar1,4,0,(uint *)(lVar7 + 0x76));
                *(undefined2 *)(lVar7 + 0x74) = 0;
                BattCQueryInformation(param_2,(ulonglong)*puVar1,6,0,(uint *)(lVar7 + 0x78));
                *(undefined2 *)(lVar7 + 0x76) = 0;
                BattCQueryInformation(param_2,(ulonglong)*puVar1,8,0,(uint *)(lVar7 + 0x7a));
                *(undefined2 *)(lVar7 + 0x78) = 0;
                param_4 = 0;
                lVar8 = 7;
                uVar4 = BattCQueryInformation(param_2,(ulonglong)*puVar1,7,0,(uint *)(lVar7 + 0x7c))
                ;
                *(undefined2 *)(lVar7 + 0x7a) = 0;
                iVar9 = ((int)(undefined2 *)(lVar7 + 0x78) + 4) - *(int *)(param_3 + 0x38);
                uVar3 = 0;
                if (-1 < (int)uVar4) {
                  uVar3 = uVar4;
                }
              }
            }
            else {
              uVar3 = 0xc0000295;
            }
            goto LAB_14000364e;
          }
          param_4 = 0;
          lVar8 = 0;
          **(uint **)(param_3 + 0x38) = *puVar1;
          uVar3 = BattCQueryInformation(param_2,(ulonglong)*puVar1,0,0,&local_e8);
          uVar5 = local_c8;
        }
        iVar9 = 8;
        *(undefined4 *)(*(longlong *)(param_3 + 0x38) + 4) = uVar5;
        goto LAB_14000364e;
      }
      **(uint **)(param_3 + 0x38) = *puVar1;
      lVar7 = *(longlong *)(param_3 + 0x38);
      lVar8 = 2;
    }
    iVar9 = 8;
    param_4 = 0;
    uVar3 = BattCQueryInformation(param_2,(ulonglong)*puVar1,(int)lVar8,0,(uint *)(lVar7 + 4));
  }
LAB_14000364e:
  lVar7 = -1;
  if (5 < DAT_14000c080) {
    local_f8[0] = *(uint *)(param_1 + 0x2e4);
    local_88 = &local_f0;
    local_98 = local_f8;
    local_78 = "Battery Absent";
    local_f0 = CONCAT44(local_f0._4_4_,*puVar1);
    lVar6 = -1;
    if (*puVar1 != 0) {
      local_78 = "-";
    }
    local_90 = 4;
    local_80 = 4;
    do {
      lVar6 = lVar6 + 1;
    } while (local_78[lVar6] != '\0');
    local_70 = (int)lVar6 + 1;
    local_100 = *(uint *)(param_3 + 0x20);
    local_68 = &local_100;
    local_58 = &local_fc;
    local_6c = 0;
    local_60 = 4;
    local_50 = 4;
    local_fc = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(local_78,&DAT_140009a63,lVar8,param_4,7,local_b8);
  }
  **(int **)(param_3 + 0x28) = iVar9;
  if (5 < DAT_14000c080) {
    local_fc = *(uint *)(param_1 + 0x2e4);
    uVar4 = *(uint *)(param_3 + 0x20);
    local_98 = &local_fc;
    local_f0 = *(undefined8 *)(param_3 + 0x18);
    local_88 = &local_f0;
    local_90 = 4;
    local_80 = 8;
    if (uVar4 == 0) {
      local_78 = "BattWmiStatusId";
    }
    else if (uVar4 == 1) {
      local_78 = "BattWmiRuntimeId";
    }
    else if (uVar4 == 2) {
      local_78 = "BattWmiTemperatureId";
    }
    else if (uVar4 == 3) {
      local_78 = "BattWmiFullChargedCapacityId";
    }
    else if (uVar4 == 4) {
      local_78 = "BattWmiCycleCountId";
    }
    else {
      local_78 = "BattWmiStaticDataId";
      if (uVar4 != 5) {
        local_78 = "<invalid>";
      }
    }
    do {
      lVar7 = lVar7 + 1;
    } while (local_78[lVar7] != '\0');
    local_68 = &local_100;
    local_6c = 0;
    local_70 = (int)lVar7 + 1;
    local_58 = (uint *)0x140006ea0;
    local_60 = 4;
    local_50 = 9;
    local_100 = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer((ulonglong)uVar4,&DAT_140009d5e,lVar8,param_4,7,local_b8);
  }
  WmiCompleteRequest(*(undefined8 *)(param_3 + 0x10),*(undefined8 *)(param_3 + 0x18),uVar3,iVar9);
  return;
}



===== Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline @ 14000385c =====

ulonglong Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_PowerAdapterUseAfterFreeFix__private_featureState;
  if ((Feature_Servicing_PowerAdapterUseAfterFreeFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_PowerAdapterUseAfterFreeFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledFallback @ 140003894 =====

void Feature_Servicing_PowerAdapterUseAfterFreeFix__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_PowerAdapterUseAfterFreeFix__private_descriptor);
  return;
}



===== RtlStringCbPrintfW @ 1400038b0 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== BattCTraceBatteryBay @ 14000392c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCTraceBatteryBay(longlong param_1)

{
  char cVar1;
  longlong local_res8 [4];
  undefined1 auStack_68 [32];
  longlong **local_48;
  uint local_38 [2];
  longlong *local_30;
  undefined4 local_28;
  undefined4 local_24;
  uint *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  if (BattCEtwRegistered != '\0') {
    local_res8[0] = param_1;
    cVar1 = EtwEventEnabled(BattCEtwHandle,&BATTERY_EVT_BATTERY_BAY_RUNDOWN);
    if (cVar1 != '\0') {
      local_28 = 8;
      local_24 = 0;
      local_14 = 0;
      local_38[0] = (uint)(*(int *)(*(longlong *)(local_res8[0] + 0x18) + 0x44) != 0);
      local_30 = local_res8;
      local_20 = local_38;
      local_48 = &local_30;
      local_18 = 4;
      EtwWrite(BattCEtwHandle,&BATTERY_EVT_BATTERY_BAY_RUNDOWN,0,2);
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgBattCTraceHandleProv @ 1400039f0 =====

void _tlgDefineProvider_annotation__TlgBattCTraceHandleProv(void)

{
  return;
}



===== _guard_check_icall @ 140003a10 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003a28 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140003a4c =====

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



===== __cpu_features_init @ 140003ac0 =====

/* WARNING: Removing unreachable block (ram,0x000140003b2a) */
/* WARNING: Removing unreachable block (ram,0x000140003ad9) */
/* WARNING: Removing unreachable block (ram,0x000140003aca) */

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



===== __security_check_cookie @ 140003b90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003bd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003c00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003c30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003c80 =====

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



===== memset @ 140003f80 =====

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



===== __memset_repmovs @ 1400040c0 =====

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



===== __memset_query @ 140004140 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400041c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004300 =====

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



===== __memset_spec_plain @ 140004380 =====

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



===== AdapterClassInitializeDevice @ 14000f010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AdapterClassInitializeDevice
              (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined1 auStackY_b8 [32];
  undefined4 local_88;
  int local_84 [3];
  undefined8 local_78 [4];
  undefined4 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0xf010  1  AdapterClassInitializeDevice */
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar7 = (undefined4 *)0x0;
  puVar10 = param_1;
  uVar6 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    iVar5 = -0x3fffff45;
    uVar11 = 1;
  }
  else if ((((param_1[2] == 0) || (param_1[3] == 0)) || (param_1[10] == 0)) || (param_1[0xb] == 0))
  {
    iVar5 = -0x3ffffff3;
    uVar11 = 2;
  }
  else {
    KeAcquireGuardedMutex(&PowerAdapterMutex);
    if (PowerAdapter == (undefined4 *)0x0) {
      param_3 = 0x74746142;
      puVar7 = (undefined4 *)ExAllocatePool2(0x40,0x1c8);
      if (puVar7 != (undefined4 *)0x0) {
        PowerAdapter = puVar7;
        KeReleaseGuardedMutex(&PowerAdapterMutex);
        *puVar7 = 1;
        uVar4 = param_1[1];
        *(undefined8 *)(puVar7 + 2) = *param_1;
        *(undefined8 *)(puVar7 + 4) = uVar4;
        uVar4 = param_1[3];
        *(undefined8 *)(puVar7 + 6) = param_1[2];
        *(undefined8 *)(puVar7 + 8) = uVar4;
        uVar4 = param_1[5];
        *(undefined8 *)(puVar7 + 10) = param_1[4];
        *(undefined8 *)(puVar7 + 0xc) = uVar4;
        uVar4 = param_1[7];
        *(undefined8 *)(puVar7 + 0xe) = param_1[6];
        *(undefined8 *)(puVar7 + 0x10) = uVar4;
        uVar4 = param_1[9];
        *(undefined8 *)(puVar7 + 0x12) = param_1[8];
        *(undefined8 *)(puVar7 + 0x14) = uVar4;
        uVar11 = *(undefined4 *)((longlong)param_1 + 0x54);
        uVar2 = *(undefined4 *)(param_1 + 0xb);
        uVar3 = *(undefined4 *)((longlong)param_1 + 0x5c);
        puVar7[0x16] = *(undefined4 *)(param_1 + 10);
        puVar7[0x17] = uVar11;
        puVar7[0x18] = uVar2;
        puVar7[0x19] = uVar3;
        uVar11 = *(undefined4 *)((longlong)param_1 + 100);
        uVar2 = *(undefined4 *)(param_1 + 0xd);
        uVar3 = *(undefined4 *)((longlong)param_1 + 0x6c);
        puVar7[0x1a] = *(undefined4 *)(param_1 + 0xc);
        puVar7[0x1b] = uVar11;
        puVar7[0x1c] = uVar2;
        puVar7[0x1d] = uVar3;
        puVar10 = (undefined8 *)param_1[2];
        lVar8 = IoAllocateWorkItem();
        *(longlong *)(puVar7 + 0x2e) = lVar8;
        if (lVar8 == 0) {
          iVar5 = -0x3fffff66;
          uVar11 = 4;
        }
        else {
          puVar7[0x48] = 1;
          *(undefined1 *)(puVar7 + 0x6b) = 0;
          puVar7[0x6a] = 2;
          KeInitializeEvent(puVar7 + 0x6c,1,0);
          puVar7[0x38] = 1;
          *(undefined8 *)(puVar7 + 0x3a) = 0;
          puVar7[0x3c] = 0;
          KeInitializeEvent(puVar7 + 0x3e,1,0);
          puVar1 = puVar7 + 0x30;
          *(undefined4 **)(puVar7 + 0x32) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          puVar1 = puVar7 + 0x34;
          *(undefined4 **)(puVar7 + 0x36) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          KeInitializeTimer(puVar7 + 0x4a);
          KeInitializeDpc(puVar7 + 0x5a,AcAdapterBackupDpc);
          LOCK();
          UNLOCK();
          iVar5 = NextDeviceNum + 1;
          puVar10 = (undefined8 *)(puVar7 + 0x2a);
          NextDeviceNum = NextDeviceNum + 1;
          puVar7[0x1e] = iVar5;
          RtlInitUnicodeString(puVar10,0);
          puVar9 = (undefined8 *)param_1[2];
          param_3 = 0;
          param_4 = puVar10;
          iVar5 = IoRegisterDeviceInterface(puVar9,&GUID_DEVICE_POWER_ADAPTER);
          if (iVar5 < 0) {
            uVar11 = 5;
            puVar10 = puVar9;
          }
          else {
            iVar5 = IoSetDeviceInterfaceState(puVar10,1);
            *param_2 = puVar7;
            uVar11 = 0;
            puVar7 = (undefined4 *)0x0;
          }
        }
        goto LAB_14000f292;
      }
      iVar5 = -0x3fffff66;
      uVar11 = 3;
    }
    else {
      iVar5 = -0x3fffffff;
      uVar11 = 6;
    }
    puVar10 = (undefined8 *)&PowerAdapterMutex;
    KeReleaseGuardedMutex();
  }
LAB_14000f292:
  if (5 < DAT_14000c080) {
    local_58 = &local_88;
    local_48 = local_84;
    local_50 = 4;
    local_40 = 4;
    local_88 = uVar11;
    local_84[0] = iVar5;
    _tlgWriteTransfer_EtwWriteTransfer(puVar10,&DAT_140007b7d,param_3,param_4,4,local_78);
  }
  if ((iVar5 < 0) && (puVar7 != (undefined4 *)0x0)) {
    uVar6 = Feature_1178837306__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 != 0) {
      KeAcquireGuardedMutex(&PowerAdapterMutex);
      PowerAdapter = (undefined4 *)0x0;
      KeReleaseGuardedMutex(&PowerAdapterMutex);
    }
    if (*(longlong *)(puVar7 + 0x2c) != 0) {
      IoSetDeviceInterfaceState(puVar7 + 0x2a,0);
      ExFreePoolWithTag(*(undefined8 *)(puVar7 + 0x2c),0);
    }
    if (*(longlong *)(puVar7 + 0x2e) != 0) {
      IoFreeWorkItem();
    }
    ExFreePoolWithTag(puVar7,0x74746142);
  }
  return iVar5;
}



===== AdapterClassUnload @ 14000f3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
AdapterClassUnload(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined1 auStackY_98 [32];
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
                    /* 0xf3c0  3  AdapterClassUnload */
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    uVar4 = 0xc00000bb;
    local_68 = 1;
  }
  else {
    KeAcquireGuardedMutex(&PowerAdapterMutex);
    if (param_1 == PowerAdapter) {
      PowerAdapter = 0;
      KeReleaseGuardedMutex(&PowerAdapterMutex);
      uVar4 = IoSetDeviceInterfaceState(param_1 + 0xa8);
      *(undefined1 *)(param_1 + 0x1ac) = 1;
      cVar3 = KeCancelTimer(param_1 + 0x128);
      if (cVar3 != '\0') {
        LOCK();
        *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + -1;
        UNLOCK();
      }
      BattCAdapterQueueWorker(param_1,'\0',param_3,param_4);
      LOCK();
      piVar1 = (int *)(param_1 + 0x1a8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        do {
          param_4 = 0;
          param_3 = 0;
          KeWaitForSingleObject(param_1 + 0x1b0,0);
          LOCK();
          piVar1 = (int *)(param_1 + 0x1a8);
          iVar2 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
        } while (iVar2 != 0);
      }
      if (*(longlong *)(param_1 + 0xb0) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0xb0),0);
      }
      IoFreeWorkItem(*(undefined8 *)(param_1 + 0xb8));
      ExFreePoolWithTag(param_1,0x74746142);
      local_68 = 0;
    }
    else {
      uVar4 = 0xc000000d;
      KeReleaseGuardedMutex();
      local_68 = 2;
    }
  }
  if (5 < DAT_14000c080) {
    local_2c = 0;
    local_1c = 0;
    local_38 = &local_68;
    local_28 = local_64;
    local_30 = 4;
    local_20 = 4;
    local_64[0] = uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000754a,param_3,param_4,4,local_58);
  }
  return uVar4;
}



===== BatteryClassInitializeDevice @ 14000f5a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BatteryClassInitializeDevice
              (undefined *param_1,undefined8 *param_2,undefined8 *param_3,longlong param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined8 *puVar14;
  uint uVar15;
  code *pcVar16;
  code *pcVar17;
  uint uVar18;
  byte *pbVar19;
  undefined1 *puVar20;
  longlong lVar21;
  longlong lVar22;
  int iVar23;
  undefined1 auStack_358 [8];
  undefined1 auStack_350 [24];
  code *local_338;
  undefined8 *local_330;
  longlong local_328;
  undefined4 local_310 [18];
  undefined1 *local_2c8;
  undefined8 local_2c0;
  undefined1 *local_2b8;
  undefined8 local_2b0;
  char *local_2a8;
  int local_2a0;
  undefined4 local_29c;
  char *local_298;
  int local_290;
  undefined4 local_28c;
  char *local_288;
  int local_280;
  undefined4 local_27c;
  char *local_278;
  int local_270;
  undefined4 local_26c;
  char *local_268;
  int local_260;
  undefined4 local_25c;
  char *local_258;
  int local_250;
  undefined4 local_24c;
  char *local_248;
  int local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  char *local_228;
  int local_220;
  undefined4 local_21c;
  undefined1 *local_218;
  undefined8 local_210;
  undefined1 *local_208;
  undefined8 local_200;
  undefined1 *local_1f8;
  undefined8 local_1f0;
  undefined1 *local_1e8;
  undefined8 local_1e0;
  undefined1 *local_1d8;
  undefined8 local_1d0;
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  char *local_1a8;
  int local_1a0;
  undefined4 local_19c;
  char *local_198;
  int local_190;
  undefined4 local_18c;
  uint *local_188;
  undefined8 local_180;
  undefined8 local_178;
  uint local_170 [2];
  uint *local_168;
  undefined8 local_160;
  undefined8 local_158;
  uint local_150 [2];
  uint *local_148;
  undefined8 local_140;
  undefined8 local_138;
  uint local_130 [2];
  char *local_128;
  int local_120;
  undefined4 local_11c;
  char *local_118;
  int local_110;
  undefined4 local_10c;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char *local_a8;
  uint local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 local_88 [32];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0xf5a0  4  BatteryClassInitializeDevice */
  puVar20 = auStack_358;
  local_48 = __security_cookie ^ (ulonglong)auStack_358;
  local_310[0] = 0;
  lVar22 = 0;
  puVar11 = (undefined8 *)0x0;
  LOCK();
  UNLOCK();
  iVar23 = NextDeviceNum + 1;
  if (*(short *)param_1 != 1) {
    iVar10 = -0x3fffffa7;
    pcVar17 = (code *)param_1;
    NextDeviceNum = NextDeviceNum + 1;
    goto LAB_14000f648;
  }
  if (*(short *)(param_1 + 2) == 0) {
    pcVar17 = *(code **)(param_1 + 0x40);
  }
  else {
    pcVar17 = *(code **)(param_1 + 0x50);
  }
  pcVar16 = (code *)0x40;
  param_3 = (undefined8 *)0x74746142;
  NextDeviceNum = NextDeviceNum + 1;
  puVar11 = (undefined8 *)ExAllocatePool2(0x40,0x318);
  if (puVar11 == (undefined8 *)0x0) {
LAB_14000f63f:
    iVar10 = -0x3fffff66;
    pcVar17 = pcVar16;
LAB_14000f645:
    puVar20 = auStack_358;
  }
  else {
    *(undefined4 *)puVar11 = 0;
    pcVar16 = (code *)0x100;
    param_3 = (undefined8 *)0x74746142;
    lVar22 = ExAllocatePool2(0x100,0x1f8);
    if (lVar22 == 0) goto LAB_14000f63f;
    uVar12 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar12 == 0) || (*(ushort *)(param_1 + 2) < 2)) {
      uVar6 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(lVar22 + 200) = *(undefined8 *)param_1;
      *(undefined8 *)(lVar22 + 0xd0) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(lVar22 + 0xd8) = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(lVar22 + 0xe0) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x28);
      *(undefined8 *)(lVar22 + 0xe8) = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(lVar22 + 0xf0) = uVar6;
      uVar7 = *(undefined4 *)(param_1 + 0x34);
      uVar8 = *(undefined4 *)(param_1 + 0x38);
      uVar9 = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(lVar22 + 0xf8) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(lVar22 + 0xfc) = uVar7;
      *(undefined4 *)(lVar22 + 0x100) = uVar8;
      *(undefined4 *)(lVar22 + 0x104) = uVar9;
      uVar7 = *(undefined4 *)(param_1 + 0x44);
      uVar8 = *(undefined4 *)(param_1 + 0x48);
      uVar9 = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(lVar22 + 0x108) = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(lVar22 + 0x10c) = uVar7;
      *(undefined4 *)(lVar22 + 0x110) = uVar8;
      *(undefined4 *)(lVar22 + 0x114) = uVar9;
    }
    else {
      uVar6 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(lVar22 + 200) = *(undefined8 *)param_1;
      *(undefined8 *)(lVar22 + 0xd0) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(lVar22 + 0xd8) = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(lVar22 + 0xe0) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x28);
      *(undefined8 *)(lVar22 + 0xe8) = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(lVar22 + 0xf0) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(lVar22 + 0xf8) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(lVar22 + 0x100) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x48);
      *(undefined8 *)(lVar22 + 0x108) = *(undefined8 *)(param_1 + 0x40);
      *(undefined8 *)(lVar22 + 0x110) = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x58);
      *(undefined8 *)(lVar22 + 0x118) = *(undefined8 *)(param_1 + 0x50);
      *(undefined8 *)(lVar22 + 0x120) = uVar6;
      uVar7 = *(undefined4 *)(param_1 + 100);
      uVar8 = *(undefined4 *)(param_1 + 0x68);
      uVar9 = *(undefined4 *)(param_1 + 0x6c);
      *(undefined4 *)(lVar22 + 0x128) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(lVar22 + 300) = uVar7;
      *(undefined4 *)(lVar22 + 0x130) = uVar8;
      *(undefined4 *)(lVar22 + 0x134) = uVar9;
      *(undefined8 *)(lVar22 + 0x138) = *(undefined8 *)(param_1 + 0x70);
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 3;
    }
    KeInitializeTimer(puVar11 + 4);
    KeInitializeTimer(puVar11 + 0x14);
    KeInitializeTimer(puVar11 + 0x3c);
    KeInitializeTimer(puVar11 + 0x4c);
    uVar12 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar12 != 0) && (PlatformAoAc != '\0')) {
      param_4 = 2;
      local_310[0] = 0x13;
      param_3 = (undefined8 *)local_310;
      pcVar16 = BattCIdleResiliencyPollTimerDispatch;
      lVar13 = Ordinal_4(BattCIdleResiliencyPollTimerDispatch,puVar11);
      puVar11[0x5e] = lVar13;
      if (lVar13 != 0) goto LAB_14000f9aa;
      iVar10 = -0x3fffffff;
      pcVar17 = pcVar16;
      goto LAB_14000f645;
    }
LAB_14000f9aa:
    KeInitializeDpc(puVar11 + 0xc,BattCBatteryPollingDpc,puVar11);
    KeInitializeDpc(puVar11 + 0x1c,BattCTagDpc,puVar11);
    KeInitializeDpc(puVar11 + 0x44,BattCStatusNotifyStormQuiesceDpc,puVar11);
    param_3 = puVar11;
    KeInitializeDpc(puVar11 + 0x54,BattCAcDcUpdateStormCancellationDpc);
    lVar13 = IoAllocateWorkItem();
    puVar20 = auStack_358;
    puVar11[0x24] = lVar13;
    if (lVar13 == 0) {
      iVar10 = -0x3fffff66;
    }
    else {
      puVar11[0x29] = 0;
      *(undefined4 *)(puVar11 + 0x28) = 1;
      *(undefined4 *)(puVar11 + 0x2a) = 0;
      KeInitializeEvent(puVar11 + 0x2b,1);
      *(undefined4 *)(puVar11 + 0x33) = 1;
      puVar11[0x34] = 0;
      *(undefined4 *)(puVar11 + 0x35) = 0;
      KeInitializeEvent(puVar11 + 0x36,1);
      *(undefined4 *)(puVar11 + 0x27) = 1;
      *(undefined4 *)((longlong)puVar11 + 0x134) = 1;
      puVar11[3] = lVar22;
      *(undefined4 *)(lVar22 + 0xa8) = 0xffffffff;
      *(undefined8 **)(lVar22 + 0xb8) = puVar11;
      *(undefined4 *)(lVar22 + 0x44) = 0;
      uVar12 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar12 != 0) {
        *(undefined4 *)(lVar22 + 0x1d8) = 0xffffffff;
        *(undefined4 *)(lVar22 + 0x1dc) = 0xffffffff;
        *(undefined4 *)(lVar22 + 0x1e0) = 0xffffffff;
        *(undefined4 *)(lVar22 + 0x1e4) = 0xffffffff;
      }
      lVar13 = lVar22 + 0x48;
      *(longlong *)(lVar22 + 0x50) = lVar13;
      *(longlong *)lVar13 = lVar13;
      lVar13 = lVar22 + 0x58;
      *(longlong *)(lVar22 + 0x60) = lVar13;
      *(longlong *)lVar13 = lVar13;
      lVar13 = lVar22 + 0x68;
      *(longlong *)(lVar22 + 0x70) = lVar13;
      *(longlong *)lVar13 = lVar13;
      lVar13 = lVar22 + 0x78;
      *(longlong *)(lVar22 + 0x80) = lVar13;
      *(longlong *)lVar13 = lVar13;
      *(undefined1 *)(puVar11 + 0x2f) = 0;
      *(undefined4 *)((longlong)puVar11 + 0x17c) = 2;
      KeInitializeEvent(puVar11 + 0x30,1);
      *(int *)((longlong)puVar11 + 0x2e4) = iVar23;
      RtlInitUnicodeString(lVar22 + 400,0);
      lVar13 = lVar22 + 0x140;
      RtlInitUnicodeString(lVar13,0);
      pcVar17 = *(code **)(param_1 + 0x40);
      param_3 = (undefined8 *)0x0;
      param_4 = lVar13;
      iVar10 = IoRegisterDeviceInterface(pcVar17,&GUID_DEVICE_BATTERY);
      if (iVar10 < 0) goto LAB_14000f645;
      IoSetDeviceInterfaceState(lVar13,1);
      local_328 = lVar22 + 0x1a0;
      param_3 = (undefined8 *)&GUID_INTERFACE_CHARGING_POWERSOURCE;
      param_4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 8);
      local_338 = ChargingPowerSourcePnpNotifyInterfaceChange;
      pcVar17 = (code *)0x2;
      local_330 = puVar11;
      iVar10 = IoRegisterPlugPlayNotification();
      puVar20 = auStack_358;
      if (-1 < iVar10) {
        lVar13 = lVar22 + 0x150;
        RtlInitUnicodeString(lVar13,0);
        pcVar17 = *(code **)(param_1 + 0x40);
        param_3 = (undefined8 *)0x0;
        param_4 = lVar13;
        iVar10 = IoRegisterDeviceInterface(pcVar17,&GUID_DEVICE_POWER_METER);
        if (iVar10 < 0) goto LAB_14000f645;
        IoSetDeviceInterfaceState(lVar13,1);
        uVar12 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline
                           ();
        if ((int)uVar12 != 0) {
          BattCConfigureIdleResiliencyPollTimer((longlong)puVar11,1);
        }
        KeAcquireGuardedMutex(&BatteryListMutex);
        puVar20 = auStack_358;
        param_3 = &BatteryListHead;
        puVar14 = puVar11 + 1;
        if ((undefined8 *)*DAT_14000c308 != &BatteryListHead) {
          pcVar17 = (code *)swi(0x29);
          puVar14 = (undefined8 *)(*pcVar17)(3);
          puVar20 = auStack_350;
        }
        *puVar14 = param_3;
        pcVar17 = (code *)&BatteryListMutex;
        puVar14[1] = DAT_14000c308;
        *DAT_14000c308 = puVar14;
        *(undefined8 *)(puVar20 + -8) = 0x14000fcb8;
        DAT_14000c308 = puVar14;
        KeReleaseGuardedMutex();
        *param_2 = puVar11;
        iVar10 = 0;
      }
    }
  }
LAB_14000f648:
  uVar18 = 0;
  *(undefined8 *)(puVar20 + -8) = 0x14000f64d;
  uVar12 = Feature_1291035962__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar12 == 0) {
    if (iVar10 < 0) {
      if (lVar22 != 0) {
        if (*(longlong *)(lVar22 + 0x1a0) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x14001028a;
          IoUnregisterPlugPlayNotificationEx();
        }
        if (*(longlong *)(lVar22 + 0x148) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x1400102a8;
          IoSetDeviceInterfaceState(lVar22 + 0x140,0);
          uVar6 = *(undefined8 *)(lVar22 + 0x148);
          *(undefined8 *)(puVar20 + -8) = 0x1400102bd;
          ExFreePoolWithTag(uVar6,0);
        }
        if (*(longlong *)(lVar22 + 0x158) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x1400102db;
          IoSetDeviceInterfaceState(lVar22 + 0x150,0);
          uVar6 = *(undefined8 *)(lVar22 + 0x158);
          *(undefined8 *)(puVar20 + -8) = 0x1400102f0;
          ExFreePoolWithTag(uVar6,0);
        }
        *(undefined8 *)(puVar20 + -8) = 0x140010304;
        ExFreePoolWithTag(lVar22,0x74746142);
      }
      if (puVar11 != (undefined8 *)0x0) {
        if (puVar11[0x24] != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x140010321;
          IoFreeWorkItem();
        }
        *(undefined8 *)(puVar20 + -8) = 0x14001032b;
        uVar12 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline
                           ();
        if (((int)uVar12 != 0) && (lVar13 = puVar11[0x5e], lVar13 != 0)) {
          *(undefined8 *)(puVar20 + -8) = 0x14001034b;
          ExDeleteTimer(lVar13,1,1,0);
          puVar11[0x5e] = 0;
        }
        *(undefined8 *)(puVar20 + -8) = 0x140010366;
        ExFreePoolWithTag(puVar11,0x74746142);
      }
    }
    if (DAT_14000c080 < 6) goto LAB_1400109b5;
    local_2b8 = puVar20 + 0x40;
    *(undefined4 *)(puVar20 + 0x44) = *(undefined4 *)((longlong)puVar11 + 0x2e4);
    local_2c8 = puVar20 + 0x44;
    local_2a8 = "Battery Absent";
    iVar23 = *(int *)(lVar22 + 0x44);
    *(int *)(puVar20 + 0x40) = iVar23;
    if (iVar23 != 0) {
      local_2a8 = "-";
    }
    lVar21 = -1;
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_2a8[lVar13] != '\0');
    uVar4 = *(uint *)(lVar22 + 0x98);
    local_2a0 = (int)lVar13;
    local_298 = "AC Power";
    if ((uVar4 & 1) == 0) {
      local_298 = "DC Power";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_298[lVar13] != '\0');
    local_290 = (int)lVar13;
    local_288 = "Battery Discharging";
    lVar13 = -1;
    if ((uVar4 & 2) == 0) {
      local_288 = "-";
    }
    do {
      lVar13 = lVar13 + 1;
    } while (local_288[lVar13] != '\0');
    local_280 = (int)lVar13;
    local_278 = "Battery Charging";
    if ((uVar4 & 4) == 0) {
      local_278 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_278[lVar13] != '\0');
    local_270 = (int)lVar13;
    local_268 = "Battery Critical";
    if ((uVar4 & 8) == 0) {
      local_268 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_268[lVar13] != '\0');
    local_260 = (int)lVar13;
    local_258 = "Battery charge limiting mode";
    if ((uVar4 & 0x10) == 0) {
      local_258 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_258[lVar13] != '\0');
    local_250 = (int)lVar13;
    local_248 = "Battery charging state power supply present";
    if ((uVar4 & 0x20) == 0) {
      local_248 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_248[lVar13] != '\0');
    local_240 = (int)lVar13;
    local_238 = "Battery charging state adequate";
    if ((uVar4 & 0x40) == 0) {
      local_238 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_238[lVar13] != '\0');
    local_230 = (int)lVar13;
    local_228 = "Battery trip point supported";
    if ((uVar4 & 0x80) == 0) {
      local_228 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_228[lVar13] != '\0');
    uVar4 = *(uint *)(lVar22 + 0xb0);
    local_220 = (int)lVar13;
    uVar5 = *(uint *)(lVar22 + 0x9c);
    uVar15 = uVar18;
    if (uVar4 != 0) {
      uVar15 = ((uVar4 >> 1) + uVar5 * 100) / uVar4;
    }
    *(uint *)(puVar20 + 0x68) = uVar15;
    local_218 = puVar20 + 0x68;
    if (uVar4 != 0) {
      uVar18 = (uint)(((ulonglong)uVar5 * 100000) / (ulonglong)uVar4);
    }
    uVar15 = *(uint *)(lVar22 + 0x1cc);
    *(uint *)(puVar20 + 0x60) = uVar5;
    local_1f8 = puVar20 + 0x60;
    local_1e8 = puVar20 + 0x5c;
    *(undefined4 *)(puVar20 + 0x58) = *(undefined4 *)(lVar22 + 0xa0);
    local_1d8 = puVar20 + 0x58;
    *(undefined4 *)(puVar20 + 0x54) = *(undefined4 *)(lVar22 + 0xa4);
    local_1c8 = puVar20 + 0x54;
    *(uint *)(puVar20 + 100) = uVar18;
    local_208 = puVar20 + 100;
    local_1b8 = puVar20 + 0x50;
    local_a8 = "?";
    *(uint *)(puVar20 + 0x5c) = uVar4;
    *(uint *)(puVar20 + 0x50) = uVar15;
    if (uVar15 == 0) {
      local_1a8 = "?";
    }
    else {
      local_1a8 = "Charge Limiting Mode";
      if ((*(uint *)(lVar22 + 0x1d0) & 1) == 0) {
        local_1a8 = "-";
      }
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_1a8[lVar13] != '\0');
    local_1a0 = (int)lVar13;
    if (uVar15 < 2) {
      local_198 = "?";
    }
    else {
      uVar18 = *(uint *)(lVar22 + 0x1d0) & 6;
      if (uVar18 == 0) {
        local_198 = "BatteryNoPowerSupply";
      }
      else if (uVar18 == 2) {
        local_198 = "BatteryInadequatePowerSupply";
      }
      else {
        local_198 = "BatteryAdequatePowerSupply";
        if (uVar18 != 4) {
          local_198 = "<invalid>";
        }
      }
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_198[lVar13] != '\0');
    local_190 = (int)lVar13;
    local_178 = *(undefined8 *)(lVar22 + 0x148);
    uVar1 = *(ushort *)(lVar22 + 0x140);
    local_158 = *(undefined8 *)(lVar22 + 0x198);
    uVar2 = *(ushort *)(lVar22 + 400);
    local_138 = *(undefined8 *)(lVar22 + 0x158);
    uVar3 = *(ushort *)(lVar22 + 0x150);
    uVar18 = *(uint *)(lVar22 + 0xa8);
    if (uVar18 == 0xffffffff) {
      local_128 = "?";
    }
    else {
      local_128 = "System Battery";
      if (-1 < (int)uVar18) {
        local_128 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_128[lVar22] != '\0');
    local_120 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_118 = "?";
    }
    else {
      local_118 = "Battery Capacity Relative";
      if ((uVar18 >> 0x1e & 1) == 0) {
        local_118 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_118[lVar22] != '\0');
    local_110 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_108 = "?";
    }
    else {
      local_108 = "Short Term Battery";
      if ((uVar18 >> 0x1d & 1) == 0) {
        local_108 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_108[lVar22] != '\0');
    local_100 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_f8 = "?";
    }
    else {
      local_f8 = "Battery Sealed";
      if ((uVar18 >> 0x1c & 1) == 0) {
        local_f8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_f8[lVar22] != '\0');
    local_f0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_e8 = "?";
    }
    else {
      local_e8 = "Set Charge Supported";
      if ((uVar18 & 1) == 0) {
        local_e8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_e8[lVar22] != '\0');
    local_e0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_d8 = "?";
    }
    else {
      local_d8 = "Set Discharge Supported";
      if ((uVar18 & 2) == 0) {
        local_d8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_d8[lVar22] != '\0');
    local_d0 = (int)lVar22;
    local_b8 = "Set Charging Source Supported";
    if (uVar18 == 0xffffffff) {
      local_c8 = "?";
    }
    else {
      local_c8 = "Set Charging Source Supported";
      if ((uVar18 & 4) == 0) {
        local_c8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_c8[lVar22] != '\0');
    local_c0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_b8 = "?";
    }
    else if ((uVar18 & 4) == 0) {
      local_b8 = "-";
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_b8[lVar22] != '\0');
    local_b0 = (int)lVar22;
    if ((uVar18 != 0xffffffff) && (local_a8 = "Set Charger ID Supported", (uVar18 & 8) == 0)) {
      local_a8 = "-";
    }
    do {
      lVar21 = lVar21 + 1;
    } while (local_a8[lVar21] != '\0');
    *(int *)(puVar20 + 0x4c) = iVar10;
    local_98 = puVar20 + 0x4c;
    pbVar19 = &DAT_140007ef9;
  }
  else {
    if (iVar10 < 0) {
      if (5 < DAT_14000c080) {
        *(int *)(puVar20 + 0x44) = iVar23;
        local_68 = puVar20 + 0x44;
        local_60 = 4;
        local_58 = puVar20 + 0x40;
        *(int *)(puVar20 + 0x40) = iVar10;
        *(undefined1 **)(puVar20 + 0x28) = local_88;
        *(undefined4 *)(puVar20 + 0x20) = 4;
        local_50 = 4;
        *(undefined8 *)(puVar20 + -8) = 0x14001015f;
        _tlgWriteTransfer_EtwWriteTransfer
                  (pcVar17,&DAT_1400082b2,param_3,param_4,*(undefined4 *)(puVar20 + 0x20),
                   *(undefined8 **)(puVar20 + 0x28));
      }
      if (lVar22 != 0) {
        if (*(longlong *)(lVar22 + 0x1a0) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x14001017b;
          IoUnregisterPlugPlayNotificationEx();
        }
        if (*(longlong *)(lVar22 + 0x148) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x140010199;
          IoSetDeviceInterfaceState(lVar22 + 0x140,0);
          uVar6 = *(undefined8 *)(lVar22 + 0x148);
          *(undefined8 *)(puVar20 + -8) = 0x1400101ae;
          ExFreePoolWithTag(uVar6,0);
        }
        if (*(longlong *)(lVar22 + 0x158) != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x1400101cc;
          IoSetDeviceInterfaceState(lVar22 + 0x150,0);
          uVar6 = *(undefined8 *)(lVar22 + 0x158);
          *(undefined8 *)(puVar20 + -8) = 0x1400101e1;
          ExFreePoolWithTag(uVar6,0);
        }
        *(undefined8 *)(puVar20 + -8) = 0x1400101f5;
        ExFreePoolWithTag(lVar22,0x74746142);
      }
      if (puVar11 != (undefined8 *)0x0) {
        if (puVar11[0x24] != 0) {
          *(undefined8 *)(puVar20 + -8) = 0x140010216;
          IoFreeWorkItem();
        }
        *(undefined8 *)(puVar20 + -8) = 0x140010220;
        uVar12 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline
                           ();
        if (((int)uVar12 != 0) && (lVar22 = puVar11[0x5e], lVar22 != 0)) {
          *(undefined8 *)(puVar20 + -8) = 0x140010240;
          ExDeleteTimer(lVar22,1,1,0);
          puVar11[0x5e] = 0;
        }
        *(undefined8 *)(puVar20 + -8) = 0x14001025b;
        ExFreePoolWithTag(puVar11,0x74746142);
      }
      goto LAB_1400109b5;
    }
    if (DAT_14000c080 < 6) goto LAB_1400109b5;
    local_2b8 = puVar20 + 0x50;
    *(undefined4 *)(puVar20 + 0x4c) = *(undefined4 *)((longlong)puVar11 + 0x2e4);
    local_2c8 = puVar20 + 0x4c;
    local_2a8 = "Battery Absent";
    iVar23 = *(int *)(lVar22 + 0x44);
    *(int *)(puVar20 + 0x50) = iVar23;
    if (iVar23 != 0) {
      local_2a8 = "-";
    }
    lVar21 = -1;
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_2a8[lVar13] != '\0');
    uVar4 = *(uint *)(lVar22 + 0x98);
    local_2a0 = (int)lVar13;
    local_298 = "AC Power";
    if ((uVar4 & 1) == 0) {
      local_298 = "DC Power";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_298[lVar13] != '\0');
    local_290 = (int)lVar13;
    local_288 = "Battery Discharging";
    lVar13 = -1;
    if ((uVar4 & 2) == 0) {
      local_288 = "-";
    }
    do {
      lVar13 = lVar13 + 1;
    } while (local_288[lVar13] != '\0');
    local_280 = (int)lVar13;
    local_278 = "Battery Charging";
    if ((uVar4 & 4) == 0) {
      local_278 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_278[lVar13] != '\0');
    local_270 = (int)lVar13;
    local_268 = "Battery Critical";
    if ((uVar4 & 8) == 0) {
      local_268 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_268[lVar13] != '\0');
    local_260 = (int)lVar13;
    local_258 = "Battery charge limiting mode";
    if ((uVar4 & 0x10) == 0) {
      local_258 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_258[lVar13] != '\0');
    local_250 = (int)lVar13;
    local_248 = "Battery charging state power supply present";
    if ((uVar4 & 0x20) == 0) {
      local_248 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_248[lVar13] != '\0');
    local_240 = (int)lVar13;
    local_238 = "Battery charging state adequate";
    if ((uVar4 & 0x40) == 0) {
      local_238 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_238[lVar13] != '\0');
    local_230 = (int)lVar13;
    local_228 = "Battery trip point supported";
    if ((uVar4 & 0x80) == 0) {
      local_228 = "-";
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_228[lVar13] != '\0');
    uVar4 = *(uint *)(lVar22 + 0xb0);
    local_220 = (int)lVar13;
    uVar5 = *(uint *)(lVar22 + 0x9c);
    uVar15 = uVar18;
    if (uVar4 != 0) {
      uVar15 = ((uVar4 >> 1) + uVar5 * 100) / uVar4;
    }
    *(uint *)(puVar20 + 0x54) = uVar15;
    local_218 = puVar20 + 0x54;
    if (uVar4 != 0) {
      uVar18 = (uint)(((ulonglong)uVar5 * 100000) / (ulonglong)uVar4);
    }
    uVar15 = *(uint *)(lVar22 + 0x1cc);
    *(uint *)(puVar20 + 0x5c) = uVar5;
    local_1f8 = puVar20 + 0x5c;
    local_1e8 = puVar20 + 0x60;
    *(undefined4 *)(puVar20 + 100) = *(undefined4 *)(lVar22 + 0xa0);
    local_1d8 = puVar20 + 100;
    *(undefined4 *)(puVar20 + 0x68) = *(undefined4 *)(lVar22 + 0xa4);
    local_1c8 = puVar20 + 0x68;
    *(uint *)(puVar20 + 0x58) = uVar18;
    local_208 = puVar20 + 0x58;
    local_1b8 = puVar20 + 0x40;
    local_a8 = "?";
    *(uint *)(puVar20 + 0x60) = uVar4;
    *(uint *)(puVar20 + 0x40) = uVar15;
    if (uVar15 == 0) {
      local_1a8 = "?";
    }
    else {
      local_1a8 = "Charge Limiting Mode";
      if ((*(uint *)(lVar22 + 0x1d0) & 1) == 0) {
        local_1a8 = "-";
      }
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_1a8[lVar13] != '\0');
    local_1a0 = (int)lVar13;
    if (uVar15 < 2) {
      local_198 = "?";
    }
    else {
      uVar18 = *(uint *)(lVar22 + 0x1d0) & 6;
      if (uVar18 == 0) {
        local_198 = "BatteryNoPowerSupply";
      }
      else if (uVar18 == 2) {
        local_198 = "BatteryInadequatePowerSupply";
      }
      else {
        local_198 = "BatteryAdequatePowerSupply";
        if (uVar18 != 4) {
          local_198 = "<invalid>";
        }
      }
    }
    lVar13 = -1;
    do {
      lVar13 = lVar13 + 1;
    } while (local_198[lVar13] != '\0');
    local_190 = (int)lVar13;
    local_178 = *(undefined8 *)(lVar22 + 0x148);
    uVar1 = *(ushort *)(lVar22 + 0x140);
    local_158 = *(undefined8 *)(lVar22 + 0x198);
    uVar2 = *(ushort *)(lVar22 + 400);
    local_138 = *(undefined8 *)(lVar22 + 0x158);
    uVar3 = *(ushort *)(lVar22 + 0x150);
    uVar18 = *(uint *)(lVar22 + 0xa8);
    if (uVar18 == 0xffffffff) {
      local_128 = "?";
    }
    else {
      local_128 = "System Battery";
      if (-1 < (int)uVar18) {
        local_128 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_128[lVar22] != '\0');
    local_120 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_118 = "?";
    }
    else {
      local_118 = "Battery Capacity Relative";
      if ((uVar18 >> 0x1e & 1) == 0) {
        local_118 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_118[lVar22] != '\0');
    local_110 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_108 = "?";
    }
    else {
      local_108 = "Short Term Battery";
      if ((uVar18 >> 0x1d & 1) == 0) {
        local_108 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_108[lVar22] != '\0');
    local_100 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_f8 = "?";
    }
    else {
      local_f8 = "Battery Sealed";
      if ((uVar18 >> 0x1c & 1) == 0) {
        local_f8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_f8[lVar22] != '\0');
    local_f0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_e8 = "?";
    }
    else {
      local_e8 = "Set Charge Supported";
      if ((uVar18 & 1) == 0) {
        local_e8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_e8[lVar22] != '\0');
    local_e0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_d8 = "?";
    }
    else {
      local_d8 = "Set Discharge Supported";
      if ((uVar18 & 2) == 0) {
        local_d8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_d8[lVar22] != '\0');
    local_d0 = (int)lVar22;
    local_b8 = "Set Charging Source Supported";
    if (uVar18 == 0xffffffff) {
      local_c8 = "?";
    }
    else {
      local_c8 = "Set Charging Source Supported";
      if ((uVar18 & 4) == 0) {
        local_c8 = "-";
      }
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_c8[lVar22] != '\0');
    local_c0 = (int)lVar22;
    if (uVar18 == 0xffffffff) {
      local_b8 = "?";
    }
    else if ((uVar18 & 4) == 0) {
      local_b8 = "-";
    }
    lVar22 = -1;
    do {
      lVar22 = lVar22 + 1;
    } while (local_b8[lVar22] != '\0');
    local_b0 = (int)lVar22;
    if ((uVar18 != 0xffffffff) && (local_a8 = "Set Charger ID Supported", (uVar18 & 8) == 0)) {
      local_a8 = "-";
    }
    do {
      lVar21 = lVar21 + 1;
    } while (local_a8[lVar21] != '\0');
    *(int *)(puVar20 + 0x44) = iVar10;
    local_98 = puVar20 + 0x44;
    pbVar19 = &DAT_140007149;
  }
  local_b0 = local_b0 + 1;
  local_c0 = local_c0 + 1;
  local_d0 = local_d0 + 1;
  local_e0 = local_e0 + 1;
  local_f0 = local_f0 + 1;
  local_100 = local_100 + 1;
  local_110 = local_110 + 1;
  local_120 = local_120 + 1;
  local_130[0] = (uint)uVar3;
  local_150[0] = (uint)uVar2;
  local_170[0] = (uint)uVar1;
  local_190 = local_190 + 1;
  local_1a0 = local_1a0 + 1;
  local_220 = local_220 + 1;
  local_230 = local_230 + 1;
  local_240 = local_240 + 1;
  local_250 = local_250 + 1;
  local_260 = local_260 + 1;
  local_270 = local_270 + 1;
  local_280 = local_280 + 1;
  local_290 = local_290 + 1;
  local_2a0 = local_2a0 + 1;
  local_ac = 0;
  local_bc = 0;
  local_cc = 0;
  local_dc = 0;
  local_ec = 0;
  local_fc = 0;
  local_10c = 0;
  local_11c = 0;
  local_130[1] = 0;
  local_140 = 2;
  local_148 = local_130;
  local_150[1] = 0;
  local_160 = 2;
  local_168 = local_150;
  local_170[1] = 0;
  local_180 = 2;
  local_188 = local_170;
  local_18c = 0;
  local_19c = 0;
  local_1b0 = 4;
  local_1c0 = 4;
  local_1d0 = 4;
  local_1e0 = 4;
  local_1f0 = 4;
  local_200 = 4;
  local_210 = 4;
  local_21c = 0;
  local_22c = 0;
  local_23c = 0;
  local_24c = 0;
  local_25c = 0;
  local_26c = 0;
  local_27c = 0;
  local_28c = 0;
  local_29c = 0;
  local_2b0 = 4;
  local_2c0 = 4;
  local_a0 = (int)lVar21 + 1;
  *(undefined1 **)(puVar20 + 0x28) = puVar20 + 0x70;
  *(undefined4 *)(puVar20 + 0x20) = 0x26;
  local_9c = 0;
  local_90 = 4;
  *(undefined8 *)(puVar20 + -8) = 0x1400109b5;
  _tlgWriteTransfer_EtwWriteTransfer
            (local_a8,pbVar19,(ulonglong)local_a0,&s__,*(undefined4 *)(puVar20 + 0x20),
             *(undefined8 **)(puVar20 + 0x28));
LAB_1400109b5:
  *(undefined8 *)(puVar20 + -8) = 0x1400109c7;
  return iVar10;
}



===== BatteryClassIoctl @ 1400109f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BatteryClassIoctl(int *param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int iVar6;
  ulonglong uVar7;
  char *pcVar8;
  uint uVar9;
  longlong lVar10;
  longlong *plVar11;
  int *piVar12;
  uint uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  int *piVar17;
  char *pcVar18;
  undefined8 uVar19;
  longlong *plVar20;
  longlong lVar21;
  undefined1 auStackY_248 [8];
  undefined1 auStackY_240 [24];
  char *local_218;
  uint local_210;
  undefined4 local_20c;
  undefined8 local_208;
  undefined4 local_200;
  undefined4 local_1fc;
  int local_1f8;
  int local_1f4;
  undefined4 local_1f0 [2];
  longlong local_1e8;
  longlong local_1e0;
  longlong local_1d8 [2];
  undefined8 local_1c8 [4];
  char **local_1a8;
  undefined8 local_1a0;
  longlong *local_198;
  undefined8 local_190;
  char *local_188;
  int local_180;
  undefined4 local_17c;
  uint *local_178;
  undefined8 local_170;
  uint *local_168;
  undefined8 local_160;
  char *local_158;
  undefined8 local_150;
  char **local_148;
  undefined8 local_140;
  undefined8 local_138 [4];
  int *local_118;
  undefined8 local_110;
  longlong *local_108;
  undefined8 local_100;
  char *local_f8;
  uint local_f0;
  undefined4 local_ec;
  undefined4 *local_e8;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  char *local_c8;
  undefined8 local_c0;
  undefined8 local_b8 [4];
  longlong *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  char *local_88;
  uint local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
                    /* 0x109f0  5  BatteryClassIoctl */
  puVar16 = auStackY_248;
  puVar15 = auStackY_248;
  local_48 = __security_cookie ^ (ulonglong)auStackY_248;
  local_218 = (char *)0x0;
  piVar17 = (int *)0x0;
  if (*param_1 == 0) {
    local_218 = *(char **)(param_1 + 6);
    piVar12 = (int *)0x0;
    piVar17 = param_1;
  }
  else {
    if (*param_1 != 1) {
      uVar13 = 0xc00000bb;
      goto LAB_14001139b;
    }
    piVar12 = param_1;
  }
  lVar10 = *(longlong *)(param_2 + 0xb8);
  lVar21 = -1;
  uVar13 = 0xc00000bb;
  uVar3 = *(uint *)(lVar10 + 0x18);
  uVar19 = 4;
  pcVar18 = local_218;
  if (uVar3 < 0x294075) {
    if (uVar3 == 0x294074) {
LAB_140010abe:
      uVar7 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      puVar15 = auStackY_248;
      if (((int)uVar7 != 0) && (puVar15 = auStackY_248, piVar12 != (int *)0x0)) {
        LOCK();
        piVar12[0x6a] = piVar12[0x6a] + 1;
        UNLOCK();
        if ((char)piVar12[0x6b] != '\0') {
          LOCK();
          piVar2 = piVar12 + 0x6a;
          iVar6 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar6 == 1) {
            piVar12 = piVar12 + 0x6c;
LAB_140010f81:
            pcVar18 = (char *)0x0;
            KeSetEvent(piVar12,0);
          }
LAB_140010f92:
          uVar13 = 0xc00002b6;
          goto LAB_140010f97;
        }
        *(undefined4 *)(param_2 + 0x30) = 0x103;
        uVar13 = 0x103;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        if (((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1) && (5 < DAT_14000c080)
           ) {
          local_8c = 0;
          local_98 = &local_1e0;
          local_90 = 8;
          iVar6 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
          if (iVar6 == 0x294070) {
            local_88 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
          }
          else if (iVar6 == 0x29406c) {
            local_88 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
          }
          else {
            pcVar18 = "<invalid>";
            local_88 = "IOCTL_POWER_ADAPTER_SET_STATUS";
            if (iVar6 != 0x294074) {
              local_88 = "<invalid>";
            }
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (local_88[lVar10] != '\0');
          local_7c = 0;
          uVar19 = 4;
          local_80 = (int)lVar10 + 1;
          local_200 = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
          local_6c = 0;
          local_5c = 0;
          local_4c = 0;
          local_78 = &local_200;
          local_1fc = *(undefined4 *)(param_2 + 0x30);
          local_68 = &local_1fc;
          local_58 = "BatteryClassIoctl";
          local_70 = 4;
          local_60 = 4;
          local_50 = 0x12;
          local_1e0 = param_2;
          _tlgWriteTransfer_EtwWriteTransfer
                    ((ulonglong)local_80,&DAT_140007e1d,pcVar18,4,7,local_b8);
        }
        piVar17 = piVar12 + 0x38;
        ExAcquireFastMutex(piVar17);
        plVar20 = (longlong *)(param_2 + 0xa8);
        plVar11 = *(longlong **)(piVar12 + 0x32);
        if ((int *)*plVar11 != piVar12 + 0x30) {
LAB_14001133c:
          plVar11 = (longlong *)0x3;
          pcVar5 = (code *)swi(0x29);
          pcVar8 = (char *)(*pcVar5)();
          puVar14 = auStackY_240;
          goto LAB_140011343;
        }
        *plVar20 = (longlong)(piVar12 + 0x30);
        *(longlong **)(param_2 + 0xb0) = plVar11;
        *plVar11 = (longlong)plVar20;
        *(longlong **)(piVar12 + 0x32) = plVar20;
        ExReleaseFastMutex(piVar17);
        BattCAdapterQueueWorker((longlong)piVar12,'\0',pcVar18,uVar19);
        puVar14 = auStackY_248;
        LOCK();
        piVar17 = piVar12 + 0x6a;
        iVar6 = *piVar17;
        *piVar17 = *piVar17 + -1;
        UNLOCK();
        puVar15 = auStackY_248;
        if (iVar6 != 1) goto LAB_140011392;
        piVar12 = piVar12 + 0x6c;
LAB_140011381:
        uVar13 = 0x103;
        *(undefined8 *)(puVar14 + -8) = 0x14001138d;
        KeSetEvent(piVar12,0,0);
        puVar15 = puVar14;
      }
    }
    else {
      if ((((uVar3 == 0x294040) || (uVar3 == 0x294044)) || (uVar3 == 0x29404c)) ||
         (uVar3 == 0x294064)) goto LAB_140010f4c;
      if (uVar3 == 0x294068) {
        puVar15 = auStackY_248;
        if (piVar17 != (int *)0x0) {
          uVar7 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          puVar15 = auStackY_248;
          if ((int)uVar7 != 0) {
            if (*(uint *)(lVar10 + 8) < 8) goto LAB_140010b20;
            uVar13 = 0;
            local_208 = 0x100000000;
            **(undefined8 **)(param_2 + 0x18) = 0x100000000;
            goto LAB_140010f97;
          }
        }
      }
      else {
        if ((uVar3 == 0x29406c) || (uVar3 == 0x294070)) goto LAB_140010abe;
LAB_140010d4b:
        puVar15 = auStackY_248;
        if ((piVar17 != (int *)0x0) &&
           ((uVar9 = (int)*(char *)(param_2 + 0x42) + 1, puVar15 = auStackY_248,
            (int)*(char *)(param_2 + 0x43) <= (int)uVar9 &&
            (puVar15 = auStackY_248, 5 < DAT_14000c080)))) {
          local_1f8 = piVar17[0xb9];
          local_1a8 = (char **)&local_1f8;
          local_198 = &local_1e8;
          local_1a0 = 4;
          local_190 = 8;
          if (uVar3 == 0x294040) {
            local_188 = "IOCTL_BATTERY_QUERY_TAG";
          }
          else if (uVar3 == 0x294044) {
            local_188 = "IOCTL_BATTERY_QUERY_INFORMATION";
          }
          else if (uVar3 == 0x298048) {
            local_188 = "IOCTL_BATTERY_SET_INFORMATION";
          }
          else if (uVar3 == 0x29404c) {
            local_188 = "IOCTL_BATTERY_QUERY_STATUS";
          }
          else if (uVar3 == 0x294050) {
            local_188 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
          }
          else if (uVar3 == 0x294064) {
            local_188 = "IOCTL_BATTERY_QUERY_STATUS_EX";
          }
          else if (uVar3 == 0x45400c) {
            local_188 = "IOCTL_PMI_GET_MEASUREMENT";
          }
          else if (uVar3 == 0x454000) {
            local_188 = "IOCTL_PMI_GET_CAPABILITIES";
          }
          else if (uVar3 == 0x454004) {
            local_188 = "IOCTL_PMI_GET_CONFIGURATION";
          }
          else if (uVar3 == 0x458008) {
            local_188 = "IOCTL_PMI_SET_CONFIGURATION";
          }
          else {
            pcVar18 = "<invalid>";
            local_188 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
            if (uVar3 != 0x45c010) {
              local_188 = "<invalid>";
            }
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (local_188[lVar10] != '\0');
          local_180 = (int)lVar10 + 1;
          local_178 = &local_210;
          local_20c = *(undefined4 *)(param_2 + 0x30);
          local_168 = &local_20c;
          local_158 = "BatteryClassIoctl";
          local_148 = &local_218;
          local_17c = 0;
          local_170 = 4;
          local_160 = 4;
          local_150 = 0x12;
          local_218 = (char *)CONCAT44(local_218._4_4_,0xc00000bb);
          local_140 = 4;
          local_210 = uVar3;
          local_1e8 = param_2;
          _tlgWriteTransfer_EtwWriteTransfer((ulonglong)uVar9,&DAT_1400074df,pcVar18,4,9,local_1c8);
          puVar15 = auStackY_248;
        }
      }
    }
  }
  else if (uVar3 == 0x298048) {
LAB_140010f4c:
    puVar15 = auStackY_248;
    if (piVar17 != (int *)0x0) {
      LOCK();
      piVar17[0x5f] = piVar17[0x5f] + 1;
      UNLOCK();
      if ((char)piVar17[0x5e] == '\x01') {
        LOCK();
        piVar12 = piVar17 + 0x5f;
        iVar6 = *piVar12;
        *piVar12 = *piVar12 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          piVar12 = piVar17 + 0x60;
          goto LAB_140010f81;
        }
        goto LAB_140010f92;
      }
      *(undefined4 *)(param_2 + 0x30) = 0x103;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      if (((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1) && (5 < DAT_14000c080))
      {
        local_1f4 = piVar17[0xb9];
        local_118 = &local_1f4;
        local_108 = local_1d8;
        local_110 = 4;
        local_100 = 8;
        iVar6 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
        if (iVar6 == 0x294040) {
          local_f8 = "IOCTL_BATTERY_QUERY_TAG";
        }
        else if (iVar6 == 0x294044) {
          local_f8 = "IOCTL_BATTERY_QUERY_INFORMATION";
        }
        else if (iVar6 == 0x298048) {
          local_f8 = "IOCTL_BATTERY_SET_INFORMATION";
        }
        else if (iVar6 == 0x29404c) {
          local_f8 = "IOCTL_BATTERY_QUERY_STATUS";
        }
        else if (iVar6 == 0x294050) {
          local_f8 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
        }
        else if (iVar6 == 0x294064) {
          local_f8 = "IOCTL_BATTERY_QUERY_STATUS_EX";
        }
        else if (iVar6 == 0x45400c) {
          local_f8 = "IOCTL_PMI_GET_MEASUREMENT";
        }
        else if (iVar6 == 0x454000) {
          local_f8 = "IOCTL_PMI_GET_CAPABILITIES";
        }
        else if (iVar6 == 0x454004) {
          local_f8 = "IOCTL_PMI_GET_CONFIGURATION";
        }
        else if (iVar6 == 0x458008) {
          local_f8 = "IOCTL_PMI_SET_CONFIGURATION";
        }
        else {
          pcVar18 = "<invalid>";
          local_f8 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
          if (iVar6 != 0x45c010) {
            local_f8 = "<invalid>";
          }
        }
        lVar10 = -1;
        do {
          lVar10 = lVar10 + 1;
        } while (local_f8[lVar10] != '\0');
        local_f0 = (int)lVar10 + 1;
        local_ec = 0;
        local_1f0[0] = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
        local_e8 = local_1f0;
        local_208 = CONCAT44(local_208._4_4_,*(undefined4 *)(param_2 + 0x30));
        local_d8 = &local_208;
        local_c8 = "BatteryClassIoctl";
        local_e0 = 4;
        local_d0 = 4;
        local_c0 = 0x12;
        local_1d8[0] = param_2;
        _tlgWriteTransfer_EtwWriteTransfer((ulonglong)local_f0,&DAT_140007a23,pcVar18,4,8,local_138)
        ;
      }
      piVar12 = piVar17 + 0x50;
      ExAcquireFastMutex(piVar12);
      puVar14 = auStackY_248;
      pcVar8 = local_218 + 0x48;
      plVar11 = *(longlong **)(local_218 + 0x50);
      if ((char *)*plVar11 != pcVar8) goto LAB_14001133c;
LAB_140011343:
      uVar13 = 0x103;
      plVar20 = (longlong *)(param_2 + 0xa8);
      *(longlong **)(param_2 + 0xb0) = plVar11;
      *plVar20 = (longlong)pcVar8;
      *plVar11 = (longlong)plVar20;
      *(longlong **)(pcVar8 + 8) = plVar20;
      *(undefined8 *)(puVar14 + -8) = 0x14001135b;
      ExReleaseFastMutex(piVar12);
      *(undefined8 *)(puVar14 + -8) = 0x14001136a;
      BattCQueueWorker((longlong)piVar17,'\0',pcVar18,uVar19);
      LOCK();
      piVar12 = piVar17 + 0x5f;
      iVar6 = *piVar12;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      puVar15 = puVar14;
      if (iVar6 == 1) {
        piVar12 = piVar17 + 0x60;
        goto LAB_140011381;
      }
    }
  }
  else {
    if ((uVar3 != 0x454000) && (uVar3 != 0x454004)) {
      if (uVar3 == 0x45400c) {
        if (piVar17 == (int *)0x0) goto LAB_140011392;
        if (*(uint *)(lVar10 + 8) < 8) {
LAB_140010b20:
          uVar13 = 0xc0000023;
        }
        else {
          puVar4 = *(undefined4 **)(param_2 + 0x18);
          *puVar4 = 1;
          if ((*(uint *)(local_218 + 0x98) & 2) == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = -*(int *)(local_218 + 0xa4);
          }
          puVar4[1] = iVar6;
          uVar13 = 0;
          *(undefined8 *)(param_2 + 0x38) = 8;
        }
        goto LAB_140010f97;
      }
      if ((uVar3 != 0x458008) && (uVar3 != 0x45c010)) goto LAB_140010d4b;
    }
    uVar13 = 0xc0000002;
LAB_140010f97:
    *(uint *)(param_2 + 0x30) = uVar13;
    if (((piVar17 != (int *)0x0) &&
        ((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1)) && (5 < DAT_14000c080)) {
      local_218 = (char *)CONCAT44(local_218._4_4_,piVar17[0xb9]);
      local_1a8 = &local_218;
      local_198 = &local_1e8;
      local_1a0 = 4;
      local_190 = 8;
      uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
      if (uVar3 == 0x294040) {
        local_188 = "IOCTL_BATTERY_QUERY_TAG";
      }
      else if (uVar3 == 0x294044) {
        local_188 = "IOCTL_BATTERY_QUERY_INFORMATION";
      }
      else if (uVar3 == 0x298048) {
        local_188 = "IOCTL_BATTERY_SET_INFORMATION";
      }
      else if (uVar3 == 0x29404c) {
        local_188 = "IOCTL_BATTERY_QUERY_STATUS";
      }
      else if (uVar3 == 0x294050) {
        local_188 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
      }
      else if (uVar3 == 0x294064) {
        local_188 = "IOCTL_BATTERY_QUERY_STATUS_EX";
      }
      else if (uVar3 == 0x45400c) {
        local_188 = "IOCTL_PMI_GET_MEASUREMENT";
      }
      else if (uVar3 == 0x454000) {
        local_188 = "IOCTL_PMI_GET_CAPABILITIES";
      }
      else if (uVar3 == 0x454004) {
        local_188 = "IOCTL_PMI_GET_CONFIGURATION";
      }
      else if (uVar3 == 0x458008) {
        local_188 = "IOCTL_PMI_SET_CONFIGURATION";
      }
      else {
        pcVar18 = "<invalid>";
        local_188 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
        if (uVar3 != 0x45c010) {
          local_188 = "<invalid>";
        }
      }
      do {
        lVar21 = lVar21 + 1;
      } while (local_188[lVar21] != '\0');
      local_17c = 0;
      local_180 = (int)lVar21 + 1;
      local_20c = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
      local_178 = &local_20c;
      local_168 = &local_210;
      local_158 = "BatteryClassIoctl";
      local_170 = 4;
      local_160 = 4;
      local_150 = 0x12;
      local_210 = uVar13;
      local_1e8 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer((ulonglong)uVar3,&DAT_140007ea2,pcVar18,4,8,local_1c8);
    }
    IofCompleteRequest(param_2,0);
    puVar15 = auStackY_248;
  }
LAB_140011392:
  puVar16 = puVar15;
LAB_14001139b:
  *(undefined8 *)(puVar16 + -8) = 0x1400113aa;
  return uVar13;
}



===== BatteryClassQueryWmiDataBlock @ 1400113d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
BatteryClassQueryWmiDataBlock
          (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,uint *param_5,
          uint param_6,longlong param_7)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  byte *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  undefined4 local_d8 [2];
  undefined8 local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8 [4];
  undefined8 *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  char *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x113d0  7  BatteryClassQueryWmiDataBlock */
  puVar8 = auStackY_108;
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar5 = *(longlong *)(param_1 + 0x18);
  local_d0 = param_3;
  iVar7 = (int)param_4 - *(int *)(lVar5 + 0x40);
  local_c0 = param_2;
  if (iVar7 == 0) {
    uVar9 = 0x18;
LAB_140011456:
    if (param_6 < uVar9) {
      *param_5 = uVar9;
      uVar10 = 0xc0000023;
      if (5 < DAT_14000c080) {
        local_d0._4_4_ = (undefined4)((ulonglong)param_3 >> 0x20);
        local_d0 = CONCAT44(local_d0._4_4_,*(undefined4 *)(param_1 + 0x2e4));
        local_98 = &local_d0;
        if (iVar7 == 0) {
          local_78 = "BattWmiStatusId";
        }
        else if (iVar7 == 1) {
          local_78 = "BattWmiRuntimeId";
        }
        else if (iVar7 == 2) {
          local_78 = "BattWmiTemperatureId";
        }
        else if (iVar7 == 3) {
          local_78 = "BattWmiFullChargedCapacityId";
        }
        else if (iVar7 == 4) {
          local_78 = "BattWmiCycleCountId";
        }
        else {
          local_78 = "BattWmiStaticDataId";
          if (iVar7 != 5) {
            local_78 = "<invalid>";
          }
        }
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (local_78[lVar5] != '\0');
        local_68 = (undefined8 *)local_d8;
        pbVar6 = &DAT_14000757f;
        local_d8[0] = 0xc0000023;
        local_c8 = param_3;
LAB_140011528:
        param_3 = local_c8;
        local_60 = 4;
        local_90 = 4;
        local_88 = &local_c8;
        local_80 = 8;
        local_70 = (int)lVar5 + 1;
        local_58 = "BatteryClassQueryWmiDataBlock";
        local_6c = 0;
        local_50 = 0x1e;
        _tlgWriteTransfer_EtwWriteTransfer((ulonglong)local_70,pbVar6,0,param_4,7,local_b8);
      }
    }
    else {
      plVar2 = (longlong *)ExAllocatePool2();
      uVar10 = 0;
      if (plVar2 != (longlong *)0x0) {
        plVar2[2] = local_c0;
        plVar2[3] = local_d0;
        plVar2[7] = param_7;
        *(int *)(plVar2 + 4) = iVar7;
        plVar2[5] = (longlong)param_5;
        *(uint *)(plVar2 + 6) = param_6;
        ExAcquireFastMutex(param_1 + 0x140);
        puVar8 = auStackY_108;
        lVar3 = lVar5 + 0x78;
        plVar4 = *(longlong **)(lVar5 + 0x80);
        if (*plVar4 != lVar3) {
          plVar4 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          lVar3 = (*pcVar1)();
          puVar8 = auStackY_100;
        }
        plVar2[1] = (longlong)plVar4;
        *plVar2 = lVar3;
        *plVar4 = (longlong)plVar2;
        *(longlong **)(lVar3 + 8) = plVar2;
        *(undefined8 *)(puVar8 + -8) = 0x1400116ec;
        ExReleaseFastMutex(param_1 + 0x140);
        *(undefined8 *)(puVar8 + -8) = 0x1400116fb;
        BattCQueueWorker(param_1,'\0',uVar10,param_4);
        param_3 = *(longlong *)(puVar8 + 0x38);
        uVar10 = 0x103;
        goto LAB_140011708;
      }
      uVar10 = 0xc000009a;
      if (5 < DAT_14000c080) {
        local_d8[0] = *(undefined4 *)(param_1 + 0x2e4);
        local_98 = (undefined8 *)local_d8;
        local_c8 = local_d0;
        if (iVar7 == 0) {
          local_78 = "BattWmiStatusId";
        }
        else if (iVar7 == 1) {
          local_78 = "BattWmiRuntimeId";
        }
        else if (iVar7 == 2) {
          local_78 = "BattWmiTemperatureId";
        }
        else if (iVar7 == 3) {
          local_78 = "BattWmiFullChargedCapacityId";
        }
        else if (iVar7 == 4) {
          local_78 = "BattWmiCycleCountId";
        }
        else {
          local_78 = "BattWmiStaticDataId";
          if (iVar7 != 5) {
            local_78 = "<invalid>";
          }
        }
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (local_78[lVar5] != '\0');
        local_68 = &local_d0;
        pbVar6 = &DAT_1400079d2;
        local_d0 = CONCAT44(local_d0._4_4_,0xc000009a);
        goto LAB_140011528;
      }
      param_3 = local_d0;
    }
    puVar8 = auStackY_108;
    uVar10 = WmiCompleteRequest(local_c0,param_3,uVar10,uVar9);
  }
  else {
    if ((((iVar7 == 1) || (iVar7 == 2)) || (iVar7 == 3)) || (iVar7 == 4)) {
      uVar9 = 8;
      goto LAB_140011456;
    }
    if (iVar7 == 5) {
      uVar9 = 0x478;
      goto LAB_140011456;
    }
    uVar10 = 0xc0000295;
LAB_140011708:
    if (5 < DAT_14000c080) {
      *(undefined4 *)(puVar8 + 0x30) = *(undefined4 *)(param_1 + 0x2e4);
      local_98 = (undefined8 *)(puVar8 + 0x30);
      local_88 = (longlong *)(puVar8 + 0x40);
      local_90 = 4;
      *(longlong *)(puVar8 + 0x40) = param_3;
      local_80 = 8;
      if (iVar7 == 0) {
        local_78 = "BattWmiStatusId";
      }
      else if (iVar7 == 1) {
        local_78 = "BattWmiRuntimeId";
      }
      else if (iVar7 == 2) {
        local_78 = "BattWmiTemperatureId";
      }
      else if (iVar7 == 3) {
        local_78 = "BattWmiFullChargedCapacityId";
      }
      else if (iVar7 == 4) {
        local_78 = "BattWmiCycleCountId";
      }
      else {
        local_78 = "BattWmiStaticDataId";
        if (iVar7 != 5) {
          local_78 = "<invalid>";
        }
      }
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_78[lVar5] != '\0');
      local_70 = (int)lVar5 + 1;
      local_68 = (undefined8 *)(puVar8 + 0x38);
      local_60 = 4;
      local_58 = "BatteryClassQueryWmiDataBlock";
      *(undefined8 **)(puVar8 + 0x28) = local_b8;
      *(undefined4 *)(puVar8 + 0x20) = 7;
      local_6c = 0;
      *(int *)(puVar8 + 0x38) = (int)uVar10;
      local_50 = 0x1e;
      *(undefined8 *)(puVar8 + -8) = 0x1400117fc;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_70,&DAT_140007bb6,0,param_4,*(undefined4 *)(puVar8 + 0x20),
                 *(undefined8 **)(puVar8 + 0x28));
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x14001180a;
  return uVar10;
}



===== BatteryClassSystemControl @ 140011830 =====

undefined4
BatteryClassSystemControl
          (longlong param_1,uint *param_2,undefined8 param_3,longlong param_4,int *param_5)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  uint *puVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  uint uVar11;
  void *_Dst;
  ulonglong uVar12;
  undefined4 *puVar13;
  
                    /* 0x11830  9  BatteryClassSystemControl */
  puVar4 = *(uint **)(param_1 + 0x18);
  lVar5 = *(longlong *)(param_4 + 0xb8);
  if (*puVar4 == 0) {
    uVar9 = *(undefined8 *)(param_2 + 2);
    *(undefined8 *)puVar4 = *(undefined8 *)param_2;
    *(undefined8 *)(puVar4 + 2) = uVar9;
    uVar9 = *(undefined8 *)(param_2 + 6);
    *(undefined8 *)(puVar4 + 4) = *(undefined8 *)(param_2 + 4);
    *(undefined8 *)(puVar4 + 6) = uVar9;
    uVar11 = param_2[9];
    uVar7 = param_2[10];
    uVar8 = param_2[0xb];
    puVar4[8] = param_2[8];
    puVar4[9] = uVar11;
    puVar4[10] = uVar7;
    puVar4[0xb] = uVar8;
    uVar11 = param_2[0xd];
    uVar7 = param_2[0xe];
    uVar8 = param_2[0xf];
    puVar4[0xc] = param_2[0xc];
    puVar4[0xd] = uVar11;
    puVar4[0xe] = uVar7;
    puVar4[0xf] = uVar8;
    uVar11 = *param_2;
    *puVar4 = uVar11 + 8;
    puVar4[0x10] = *param_2;
    _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)(uVar11 + 8) << 4,0x74746142);
    *(void **)(puVar4 + 2) = _Dst;
    if (_Dst == (void *)0x0) {
      *puVar4 = 0;
      *(undefined4 *)(param_4 + 0x30) = 0xc000009a;
      *param_5 = 1;
      return 0xc000009a;
    }
    memmove(_Dst,*(void **)(param_2 + 2),(ulonglong)*param_2 << 4);
    uVar9 = uRam000000014000c008;
    uVar12 = (ulonglong)*param_2;
    lVar6 = *(longlong *)(puVar4 + 2);
    puVar2 = (undefined8 *)(lVar6 + uVar12 * 0x10);
    *puVar2 = BattWmiGuidList;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c018;
    puVar2 = (undefined8 *)(lVar6 + 0x10 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_RUNTIME_WMI_GUID_14000c010;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c028;
    puVar2 = (undefined8 *)(lVar6 + 0x20 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_TEMPERATURE_WMI_GUID_14000c020;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c038;
    puVar2 = (undefined8 *)(lVar6 + 0x30 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_FULL_CHARGED_CAPACITY_WMI_GUID_14000c030;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c048;
    puVar2 = (undefined8 *)(lVar6 + 0x40 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_CYCLE_COUNT_WMI_GUID_14000c040;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c058;
    puVar2 = (undefined8 *)(lVar6 + 0x50 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_STATIC_DATA_WMI_GUID_14000c050;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c068;
    puVar2 = (undefined8 *)(lVar6 + 0x60 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_STATUS_CHANGE_WMI_GUID_14000c060;
    puVar2[1] = uVar9;
    uVar9 = uRam000000014000c078;
    puVar2 = (undefined8 *)(lVar6 + 0x70 + uVar12 * 0x10);
    *puVar2 = PTR_BATTERY_TAG_CHANGE_WMI_GUID_14000c070;
    puVar2[1] = uVar9;
  }
  LOCK();
  *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0x178) == '\x01') {
    LOCK();
    piVar1 = (int *)(param_1 + 0x17c);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      KeSetEvent(param_1 + 0x180,0,0);
    }
    return 0xc00002b6;
  }
  uVar10 = WmiSystemControl(puVar4,param_3,param_4,param_5);
  if ((*param_5 == 1) &&
     (((*(char *)(lVar5 + 1) == '\b' || (*(char *)(lVar5 + 1) == '\v')) &&
      (*(longlong *)(lVar5 + 0x10) == 0)))) {
    puVar4 = *(uint **)(lVar5 + 0x20);
    if ((*(longlong *)(param_4 + 0x38) == 4) || (*(int *)(param_4 + 0x30) == -0x3fffffdd)) {
      *puVar4 = *puVar4 + 0xa9 & 0xfffffff8;
    }
    else {
      uVar11 = *puVar4 + 7 & 0xfffffff8;
      puVar4[1] = uVar11;
      uVar11 = uVar11 + 0xa2;
      **(uint **)(lVar5 + 0x20) = uVar11;
      if (uVar11 <= *(uint *)(lVar5 + 0x18)) {
        *(ulonglong *)(param_4 + 0x38) = (ulonglong)uVar11;
        puVar13 = (undefined4 *)((longlong)puVar4 + (ulonglong)puVar4[1]);
        puVar13[1] = 0;
        *puVar13 = 0xa2;
        puVar13[2] = 0x18;
        *(undefined2 *)(puVar13 + 6) = 0x74;
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x1a),L"\\REG",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x22),L"ISTR",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x2a),L"Y\\MA",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x32),L"CHIN",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x3a),L"E\\SY",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x42),L"STEM",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x4a),L"\\Cur",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x52),L"rent",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x5a),L"Cont",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x62),L"rolS",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x6a),L"et\\S",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x72),L"ervi",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x7a),L"ces\\",4);
        builtin_wcsncpy((wchar_t *)((longlong)puVar13 + 0x82),L"Batt",4);
        *(undefined4 *)((longlong)puVar13 + 0x8a) = 0x43;
        puVar13[3] = 0x8e;
        *(undefined2 *)((longlong)puVar13 + 0x8e) = 0x12;
        puVar13[0x24] = 0x410042;
        puVar13[0x25] = 0x540054;
        puVar13[0x26] = 0x570043;
        puVar13[0x27] = 0x49004d;
        *(undefined2 *)(puVar13 + 0x28) = 0;
        puVar13[4] = 0;
        goto LAB_140011ae4;
      }
    }
    uVar10 = 0xc0000023;
    *(undefined4 *)(param_4 + 0x30) = 0xc0000023;
    *(undefined8 *)(param_4 + 0x38) = 4;
  }
LAB_140011ae4:
  LOCK();
  piVar1 = (int *)(param_1 + 0x17c);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    KeSetEvent(param_1 + 0x180,0,0);
  }
  return uVar10;
}



===== BatteryClassUnload @ 140011b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
BatteryClassUnload(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint uVar11;
  char *pcVar12;
  undefined1 auStackY_2e8 [32];
  undefined4 local_2b8;
  int local_2b4;
  uint local_2b0;
  undefined4 local_2ac;
  uint local_2a8;
  uint local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  uint local_298 [4];
  undefined8 local_288 [4];
  undefined4 *local_268;
  undefined8 local_260;
  int *local_258;
  undefined8 local_250;
  char *local_248;
  int local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  char *local_228;
  int local_220;
  undefined4 local_21c;
  char *local_218;
  int local_210;
  undefined4 local_20c;
  char *local_208;
  int local_200;
  undefined4 local_1fc;
  char *local_1f8;
  int local_1f0;
  undefined4 local_1ec;
  char *local_1e8;
  int local_1e0;
  undefined4 local_1dc;
  char *local_1d8;
  int local_1d0;
  undefined4 local_1cc;
  char *local_1c8;
  int local_1c0;
  undefined4 local_1bc;
  uint *local_1b8;
  undefined8 local_1b0;
  undefined4 *local_1a8;
  undefined8 local_1a0;
  uint *local_198;
  undefined8 local_190;
  uint *local_188;
  undefined8 local_180;
  undefined4 *local_178;
  undefined8 local_170;
  undefined4 *local_168;
  undefined8 local_160;
  uint *local_158;
  undefined8 local_150;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  uint *local_128;
  undefined8 local_120;
  undefined8 local_118;
  uint local_110 [2];
  uint *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  uint local_f0 [2];
  uint *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0 [2];
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
                    /* 0x11b30  10  BatteryClassUnload */
  local_38 = __security_cookie ^ (ulonglong)auStackY_2e8;
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  KeAcquireGuardedMutex(&BatteryListMutex);
  puVar1 = (undefined8 *)(param_1 + 8);
  pcVar12 = (char *)*puVar1;
  if ((*(undefined8 **)(pcVar12 + 8) != puVar1) ||
     (puVar5 = *(undefined8 **)(param_1 + 0x10), (undefined8 *)*puVar5 != puVar1)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    uVar10 = (*pcVar6)();
    return uVar10;
  }
  *puVar5 = pcVar12;
  *(undefined8 **)(pcVar12 + 8) = puVar5;
  KeReleaseGuardedMutex(&BatteryListMutex);
  if (5 < DAT_14000c080) {
    local_2b8 = *(undefined4 *)(param_1 + 0x2e4);
    local_258 = &local_2b4;
    local_268 = &local_2b8;
    local_2b4 = puVar4[0x11];
    local_248 = "Battery Absent";
    local_260 = 4;
    lVar8 = -1;
    if (local_2b4 != 0) {
      local_248 = "-";
    }
    local_250 = 4;
    do {
      lVar8 = lVar8 + 1;
    } while (local_248[lVar8] != '\0');
    uVar11 = puVar4[0x26];
    local_240 = (int)lVar8 + 1;
    local_238 = "AC Power";
    local_23c = 0;
    if ((uVar11 & 1) == 0) {
      local_238 = "DC Power";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_238[lVar8] != '\0');
    local_230 = (int)lVar8 + 1;
    local_22c = 0;
    local_228 = "Battery Discharging";
    lVar8 = -1;
    if ((uVar11 & 2) == 0) {
      local_228 = "-";
    }
    do {
      lVar8 = lVar8 + 1;
    } while (local_228[lVar8] != '\0');
    local_220 = (int)lVar8 + 1;
    local_218 = "Battery Charging";
    local_21c = 0;
    if ((uVar11 & 4) == 0) {
      local_218 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_218[lVar8] != '\0');
    local_210 = (int)lVar8 + 1;
    local_208 = "Battery Critical";
    local_20c = 0;
    if ((uVar11 & 8) == 0) {
      local_208 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_208[lVar8] != '\0');
    local_200 = (int)lVar8 + 1;
    local_1f8 = "Battery charge limiting mode";
    local_1fc = 0;
    if ((uVar11 & 0x10) == 0) {
      local_1f8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1f8[lVar8] != '\0');
    local_1f0 = (int)lVar8 + 1;
    local_1e8 = "Battery charging state power supply present";
    local_1ec = 0;
    if ((uVar11 & 0x20) == 0) {
      local_1e8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1e8[lVar8] != '\0');
    local_1e0 = (int)lVar8 + 1;
    local_1d8 = "Battery charging state adequate";
    local_1dc = 0;
    if ((uVar11 & 0x40) == 0) {
      local_1d8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1d8[lVar8] != '\0');
    local_1d0 = (int)lVar8 + 1;
    local_1c8 = "Battery trip point supported";
    local_1cc = 0;
    if ((uVar11 & 0x80) == 0) {
      local_1c8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1c8[lVar8] != '\0');
    local_2a4 = puVar4[0x2c];
    local_1c0 = (int)lVar8 + 1;
    local_2a8 = puVar4[0x27];
    local_1bc = 0;
    if (local_2a4 == 0) {
      local_2b0 = 0;
    }
    else {
      local_2b0 = ((local_2a4 >> 1) + local_2a8 * 100) / local_2a4;
    }
    local_1b8 = &local_2b0;
    local_1b0 = 4;
    if (local_2a4 == 0) {
      local_2ac = 0;
    }
    else {
      local_2ac = (undefined4)(((ulonglong)local_2a8 * 100000) / (ulonglong)local_2a4);
    }
    local_298[0] = puVar4[0x73];
    local_48 = "?";
    local_1a8 = &local_2ac;
    local_198 = &local_2a8;
    local_188 = &local_2a4;
    local_2a0 = puVar4[0x28];
    local_178 = &local_2a0;
    local_29c = puVar4[0x29];
    local_168 = &local_29c;
    local_158 = local_298;
    local_1a0 = 4;
    local_190 = 4;
    local_180 = 4;
    local_170 = 4;
    local_160 = 4;
    local_150 = 4;
    if (local_298[0] == 0) {
      local_148 = "?";
    }
    else {
      local_148 = "Charge Limiting Mode";
      if ((puVar4[0x74] & 1) == 0) {
        local_148 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_148[lVar8] != '\0');
    local_140 = (int)lVar8 + 1;
    local_13c = 0;
    if (local_298[0] < 2) {
      local_138 = "?";
    }
    else {
      uVar11 = puVar4[0x74] & 6;
      if (uVar11 == 0) {
        local_138 = "BatteryNoPowerSupply";
      }
      else if (uVar11 == 2) {
        local_138 = "BatteryInadequatePowerSupply";
      }
      else {
        local_138 = "BatteryAdequatePowerSupply";
        if (uVar11 != 4) {
          local_138 = "<invalid>";
        }
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_138[lVar8] != '\0');
    local_130 = (int)lVar8 + 1;
    local_128 = local_110;
    local_120 = 2;
    local_118 = *(undefined8 *)(puVar4 + 0x52);
    local_110[0] = (uint)*(ushort *)(puVar4 + 0x50);
    local_108 = local_f0;
    local_f8 = *(undefined8 *)(puVar4 + 0x66);
    local_f0[0] = (uint)*(ushort *)(puVar4 + 100);
    local_e8 = local_d0;
    local_d8 = *(undefined8 *)(puVar4 + 0x56);
    local_100 = 2;
    local_e0 = 2;
    local_d0[0] = (uint)*(ushort *)(puVar4 + 0x54);
    uVar11 = puVar4[0x2a];
    local_12c = 0;
    local_110[1] = 0;
    local_f0[1] = 0;
    local_d0[1] = 0;
    if (uVar11 == 0xffffffff) {
      local_c8 = "?";
    }
    else {
      local_c8 = "System Battery";
      if (-1 < (int)uVar11) {
        local_c8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_c8[lVar8] != '\0');
    local_c0 = (int)lVar8 + 1;
    local_bc = 0;
    if (uVar11 == 0xffffffff) {
      local_b8 = "?";
    }
    else {
      local_b8 = "Battery Capacity Relative";
      if ((uVar11 >> 0x1e & 1) == 0) {
        local_b8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_b8[lVar8] != '\0');
    local_b0 = (int)lVar8 + 1;
    local_ac = 0;
    if (uVar11 == 0xffffffff) {
      local_a8 = "?";
    }
    else {
      local_a8 = "Short Term Battery";
      if ((uVar11 >> 0x1d & 1) == 0) {
        local_a8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_a8[lVar8] != '\0');
    local_a0 = (int)lVar8 + 1;
    local_9c = 0;
    if (uVar11 == 0xffffffff) {
      local_98 = "?";
    }
    else {
      local_98 = "Battery Sealed";
      if ((uVar11 >> 0x1c & 1) == 0) {
        local_98 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_98[lVar8] != '\0');
    local_90 = (int)lVar8 + 1;
    local_8c = 0;
    if (uVar11 == 0xffffffff) {
      local_88 = "?";
    }
    else {
      local_88 = "Set Charge Supported";
      if ((uVar11 & 1) == 0) {
        local_88 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_88[lVar8] != '\0');
    local_80 = (int)lVar8 + 1;
    local_7c = 0;
    if (uVar11 == 0xffffffff) {
      local_78 = "?";
    }
    else {
      local_78 = "Set Discharge Supported";
      if ((uVar11 & 2) == 0) {
        local_78 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_78[lVar8] != '\0');
    local_70 = (int)lVar8 + 1;
    pcVar12 = "Set Charging Source Supported";
    local_6c = 0;
    if (uVar11 == 0xffffffff) {
      local_68 = "?";
    }
    else {
      local_68 = "Set Charging Source Supported";
      if ((uVar11 & 4) == 0) {
        local_68 = "-";
      }
    }
    lVar8 = -1;
    param_4 = (ulonglong)(uVar11 & 4);
    do {
      lVar8 = lVar8 + 1;
    } while (local_68[lVar8] != '\0');
    local_60 = (int)lVar8 + 1;
    local_5c = 0;
    if (uVar11 == 0xffffffff) {
      pcVar12 = "?";
    }
    else if ((uVar11 & 4) == 0) {
      pcVar12 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (pcVar12[lVar8] != '\0');
    local_50 = (int)lVar8 + 1;
    local_4c = 0;
    if ((uVar11 != 0xffffffff) && (local_48 = "Set Charger ID Supported", (uVar11 & 8) == 0)) {
      local_48 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_48[lVar8] != '\0');
    local_40 = (int)lVar8 + 1;
    local_3c = 0;
    local_58 = pcVar12;
    _tlgWriteTransfer_EtwWriteTransfer(local_48,&DAT_1400075d0,pcVar12,param_4,0x25,local_288);
  }
  IoSetDeviceInterfaceState(puVar4 + 0x50);
  IoSetDeviceInterfaceState(puVar4 + 0x54);
  *(undefined1 *)(param_1 + 0x178) = 1;
  cVar7 = KeCancelTimer(param_1 + 0x20);
  if (cVar7 != '\0') {
    LOCK();
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + -1;
    UNLOCK();
  }
  cVar7 = KeCancelTimer(param_1 + 0x1e0);
  if (cVar7 != '\0') {
    LOCK();
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + -1;
    UNLOCK();
    Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  }
  cVar7 = KeCancelTimer(param_1 + 0x260);
  if (cVar7 != '\0') {
    LOCK();
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + -1;
    UNLOCK();
    Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  }
  cVar7 = KeCancelTimer(param_1 + 0xa0);
  if (cVar7 != '\0') {
    LOCK();
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + -1;
    UNLOCK();
  }
  uVar9 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar9 != 0) && (*(longlong *)(param_1 + 0x2f0) != 0)) {
    param_4 = 0;
    pcVar12 = (char *)CONCAT71((int7)((ulonglong)pcVar12 >> 8),1);
    ExDeleteTimer();
    *(undefined8 *)(param_1 + 0x2f0) = 0;
  }
  BattCQueueWorker(param_1,'\0',pcVar12,param_4);
  LOCK();
  piVar2 = (int *)(param_1 + 0x17c);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 != 1) {
    do {
      KeWaitForSingleObject(param_1 + 0x180,0,0,0);
      LOCK();
      piVar2 = (int *)(param_1 + 0x17c);
      iVar3 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
    } while (iVar3 != 0);
  }
  if (*(longlong *)(puVar4 + 0x68) != 0) {
    IoUnregisterPlugPlayNotificationEx();
    *(undefined8 *)(puVar4 + 0x68) = 0;
  }
  if (*(longlong *)(puVar4 + 0x6a) != 0) {
    IoUnregisterPlugPlayNotificationEx();
    *(undefined8 *)(puVar4 + 0x6a) = 0;
  }
  if (*(longlong *)(puVar4 + 0x5a) != 0) {
    (**(code **)(puVar4 + 0x5e))();
    *(undefined8 *)(puVar4 + 0x5a) = 0;
  }
  if (*(longlong *)(puVar4 + 0x52) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar4 + 0x52),0);
  }
  if (*(longlong *)(puVar4 + 0x56) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar4 + 0x56),0);
  }
  if (*(longlong *)(puVar4 + 0x66) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar4 + 0x66),0x74746142);
    *(undefined8 *)(puVar4 + 0x66) = 0;
    puVar4[100] = 0;
  }
  if (*(longlong *)(puVar4 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar4 + 2),0x74746142);
    *(undefined8 *)(puVar4 + 2) = 0;
    *puVar4 = 0;
  }
  uVar9 = Feature_1291035962__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    IoFreeWorkItem(*(undefined8 *)(param_1 + 0x120));
    ExFreePoolWithTag(puVar4,0);
    ExFreePoolWithTag(param_1,0);
  }
  uVar9 = Feature_1291035962__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 != 0) {
    IoFreeWorkItem(*(undefined8 *)(param_1 + 0x120));
    ExFreePoolWithTag(puVar4,0);
    ExFreePoolWithTag(param_1,0);
  }
  return 0;
}



===== BatteryClassUpdateData @ 1400124b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
BatteryClassUpdateData(longlong param_1,uint *param_2,ulonglong param_3,ulonglong param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStackY_1f8 [32];
  undefined4 local_1c8;
  int local_1c4;
  uint local_1c0;
  undefined4 local_1bc;
  uint local_1b8;
  uint local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  uint local_1a8 [4];
  undefined8 local_198 [4];
  undefined4 *local_178;
  undefined8 local_170;
  int *local_168;
  undefined8 local_160;
  char *local_158;
  int local_150;
  undefined4 local_14c;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  char *local_128;
  int local_120;
  undefined4 local_11c;
  char *local_118;
  int local_110;
  undefined4 local_10c;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  uint *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
                    /* 0x124b0  11  BatteryClassUpdateData */
  local_38 = __security_cookie ^ (ulonglong)auStackY_1f8;
  lVar5 = *(longlong *)(param_1 + 0x18);
  uVar6 = 0;
  if ((param_2 == (uint *)0x0) || (*param_2 < 3)) {
    if (*(char *)(param_1 + 0x178) == '\x01') {
      uVar6 = 0xc00002b6;
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
      UNLOCK();
      ExAcquireFastMutex(param_1 + 0x198);
      *(undefined8 *)(lVar5 + 0x1cc) = *(undefined8 *)param_2;
      if (5 < DAT_14000c080) {
        local_1c8 = *(undefined4 *)(param_1 + 0x2e4);
        local_168 = &local_1c4;
        local_178 = &local_1c8;
        local_1c4 = *(int *)(lVar5 + 0x44);
        local_158 = "Battery Absent";
        local_170 = 4;
        lVar4 = -1;
        if (local_1c4 != 0) {
          local_158 = "-";
        }
        local_160 = 4;
        do {
          lVar4 = lVar4 + 1;
        } while (local_158[lVar4] != '\0');
        uVar3 = *(uint *)(lVar5 + 0x98);
        local_150 = (int)lVar4 + 1;
        local_148 = "AC Power";
        local_14c = 0;
        if ((uVar3 & 1) == 0) {
          local_148 = "DC Power";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_148[lVar4] != '\0');
        local_140 = (int)lVar4 + 1;
        local_138 = "Battery Discharging";
        local_13c = 0;
        if ((uVar3 & 2) == 0) {
          local_138 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_138[lVar4] != '\0');
        local_130 = (int)lVar4 + 1;
        local_128 = "Battery Charging";
        local_12c = 0;
        if ((uVar3 & 4) == 0) {
          local_128 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_128[lVar4] != '\0');
        local_120 = (int)lVar4 + 1;
        local_118 = "Battery Critical";
        local_11c = 0;
        if ((uVar3 & 8) == 0) {
          local_118 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_118[lVar4] != '\0');
        local_110 = (int)lVar4 + 1;
        local_108 = "Battery charge limiting mode";
        local_10c = 0;
        if ((uVar3 & 0x10) == 0) {
          local_108 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_108[lVar4] != '\0');
        local_100 = (int)lVar4 + 1;
        local_f8 = "Battery charging state power supply present";
        local_fc = 0;
        if ((uVar3 & 0x20) == 0) {
          local_f8 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_f8[lVar4] != '\0');
        local_f0 = (int)lVar4 + 1;
        local_e8 = "Battery charging state adequate";
        local_ec = 0;
        if ((uVar3 & 0x40) == 0) {
          local_e8 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_e8[lVar4] != '\0');
        local_e0 = (int)lVar4 + 1;
        local_d8 = "Battery trip point supported";
        local_dc = 0;
        if ((uVar3 & 0x80) == 0) {
          local_d8 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_d8[lVar4] != '\0');
        local_1b4 = *(uint *)(lVar5 + 0xb0);
        param_4 = (ulonglong)local_1b4;
        local_d0 = (int)lVar4 + 1;
        local_1b8 = *(uint *)(lVar5 + 0x9c);
        local_cc = 0;
        if (local_1b4 == 0) {
          local_1c0 = 0;
        }
        else {
          local_1c0 = ((local_1b4 >> 1) + local_1b8 * 100) / local_1b4;
        }
        local_c8 = &local_1c0;
        local_c0 = 4;
        if (local_1b4 == 0) {
          local_1bc = 0;
        }
        else {
          local_1bc = (undefined4)(((ulonglong)local_1b8 * 100000) / param_4);
        }
        local_1a8[0] = *(uint *)(lVar5 + 0x1cc);
        param_3 = (ulonglong)local_1a8[0];
        local_b8 = &local_1bc;
        local_a8 = &local_1b8;
        local_98 = &local_1b4;
        local_1b0 = *(undefined4 *)(lVar5 + 0xa0);
        local_88 = &local_1b0;
        local_1ac = *(undefined4 *)(lVar5 + 0xa4);
        local_78 = &local_1ac;
        local_68 = local_1a8;
        local_48 = "?";
        local_b0 = 4;
        local_a0 = 4;
        local_90 = 4;
        local_80 = 4;
        local_70 = 4;
        local_60 = 4;
        if (local_1a8[0] == 0) {
          local_58 = "?";
        }
        else {
          local_58 = "Charge Limiting Mode";
          if ((*(uint *)(lVar5 + 0x1d0) & 1) == 0) {
            local_58 = "-";
          }
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_58[lVar4] != '\0');
        local_50 = (int)lVar4 + 1;
        local_4c = 0;
        if (1 < local_1a8[0]) {
          uVar3 = *(uint *)(lVar5 + 0x1d0) & 6;
          if (uVar3 == 0) {
            local_48 = "BatteryNoPowerSupply";
          }
          else if (uVar3 == 2) {
            local_48 = "BatteryInadequatePowerSupply";
          }
          else {
            local_48 = "BatteryAdequatePowerSupply";
            if (uVar3 != 4) {
              local_48 = "<invalid>";
            }
          }
        }
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (local_48[lVar5] != '\0');
        local_40 = (int)lVar5 + 1;
        local_3c = 0;
        _tlgWriteTransfer_EtwWriteTransfer(local_48,&DAT_140007c3c,param_3,param_4,0x16,local_198);
      }
      ExReleaseFastMutex(param_1 + 0x198);
      LOCK();
      *(undefined4 *)(param_1 + 0x2e8) = 1;
      UNLOCK();
      BattCQueueWorker(param_1,'\x01',param_3,param_4);
      LOCK();
      piVar1 = (int *)(param_1 + 0x17c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(param_1 + 0x180,0,0);
      }
    }
  }
  else {
    uVar6 = 0xc000000d;
  }
  return uVar6;
}



===== ChargeNotificationCallback @ 140012910 =====

void ChargeNotificationCallback
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_res8;
  undefined4 local_resc;
  
  LOCK();
  *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0x178) == '\x01') {
    LOCK();
    piVar1 = (int *)(param_1 + 0x17c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  else {
    local_resc = (undefined4)param_3;
    local_res8 = param_2;
    SetChargingSource(*(longlong *)(param_1 + 0x18),(undefined8 *)&local_res8,param_3,param_4);
    LOCK();
    piVar1 = (int *)(param_1 + 0x17c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  if (iVar2 == 1) {
    KeSetEvent(param_1 + 0x180,0,0);
  }
  return;
}



===== ChargingDeviceRemoved @ 140012990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChargingDeviceRemoved
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (*(longlong *)(lVar1 + 0x168) != 0) {
    (**(code **)(lVar1 + 0x178))();
    *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x168) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1a8) != 0) {
    IoUnregisterPlugPlayNotificationEx();
    *(undefined8 *)(lVar1 + 0x1a8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x198) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x198),0x74746142);
    *(undefined8 *)(lVar1 + 0x198) = 0;
    *(undefined4 *)(lVar1 + 400) = 0;
  }
  local_res8[1] = 0;
  uVar2 = 1;
  do {
    local_res8[0] = uVar2;
    SetChargingSource(*(longlong *)(param_1 + 0x18),(undefined8 *)local_res8,param_3,param_4);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return;
}



===== ChargingPowerSourcePnpNotifyInterfaceChange @ 140012a50 =====

int ChargingPowerSourcePnpNotifyInterfaceChange
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  lVar6 = *(longlong *)(param_2 + 0x18);
  iVar2 = 0;
  LOCK();
  *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
  UNLOCK();
  if (*(char *)(param_2 + 0x178) != '\x01') {
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      if (*(longlong *)(lVar6 + 0x198) == 0) {
        uVar8 = 0x74746142;
        uVar7 = **(short **)(param_1 + 0x28) + 2;
        uVar5 = (ulonglong)uVar7;
        lVar4 = ExAllocatePool2(0x100);
        *(longlong *)(lVar6 + 0x198) = lVar4;
        if (lVar4 == 0) {
          ChargingDeviceRemoved(param_2,uVar5,uVar8,param_4);
          iVar2 = -0x3fffff66;
        }
        else {
          *(ushort *)(lVar6 + 0x192) = uVar7;
          *(undefined2 *)(lVar6 + 400) = 0;
          RtlCopyUnicodeString((undefined2 *)(lVar6 + 400),*(undefined8 *)(param_1 + 0x28));
          lVar6 = param_2;
          iVar2 = RegisterDeviceRemovalNotification(param_1,param_2);
          if ((iVar2 < 0) || (iVar2 = RegisterChargerChangeCallback(param_2), iVar2 < 0)) {
            ChargingDeviceRemoved(param_2,lVar6,uVar8,param_4);
          }
        }
      }
    }
    else if (((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4005) &&
             (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) &&
            (*(longlong *)(lVar6 + 0x198) != 0)) {
      uVar8 = *(undefined8 *)(param_1 + 0x28);
      uVar9 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      iVar3 = RtlCompareUnicodeString(lVar6 + 400);
      if (iVar3 == 0) {
        iVar2 = ChargingDeviceRemoved(param_2,uVar8,uVar9,param_4);
      }
    }
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return iVar2;
}



===== ChargingPowerSourcePnpNotifyTargetDeviceChange @ 140012bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ChargingPowerSourcePnpNotifyTargetDeviceChange
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  iVar4 = 0;
  LOCK();
  *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
  UNLOCK();
  if (*(char *)(param_2 + 0x178) != '\x01') {
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4006) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      if (*(longlong *)(lVar3 + 0x168) != 0) {
        (**(code **)(lVar3 + 0x178))();
        *(undefined8 *)(lVar3 + 0x168) = 0;
      }
    }
    else if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4008) &&
            (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      iVar4 = ChargingDeviceRemoved(param_2,param_2,param_3,param_4);
    }
    else if (((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4007) &&
             (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) &&
            (*(longlong *)(lVar3 + 0x168) == 0)) {
      iVar4 = RegisterChargerChangeCallback(param_2);
    }
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0x17c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return iVar4;
}



===== DllUnload @ 140012cf0 =====

undefined8 DllUnload(void)

{
  undefined8 uVar1;
  
                    /* 0x12cf0  13  DllUnload */
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if (BattCEtwRegistered != '\0') {
    EtwUnregister(BattCEtwHandle);
    BattCEtwRegistered = '\0';
  }
  uVar1 = DAT_14000c0a0;
  DAT_14000c0a0 = 0;
  DAT_14000c080 = 0;
  EtwUnregister(uVar1);
  return 0;
}



===== RegisterChargerChangeCallback @ 140012d90 =====

int RegisterChargerChangeCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong local_res8;
  undefined8 local_res10;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_res10 = 0;
  if (*(longlong *)(lVar1 + 0x168) == 0) {
    iVar3 = IoGetDeviceObjectPointer(lVar1 + 400,0x1f0000,&local_res10,&local_res8);
    if (-1 < iVar3) {
      ObfReferenceObject(local_res8);
      ObfDereferenceObject(local_res10);
      lVar4 = IoAllocateIrp(*(undefined1 *)(local_res8 + 0x4c),0);
      if (lVar4 == 0) {
        iVar3 = -0x3fffff66;
        ObfDereferenceObject(local_res8);
      }
      else {
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(undefined **)(lVar2 + -0x40) = &GUID_INTERFACE_CHARGING_POWERSOURCE;
        *(undefined2 *)(lVar2 + -0x48) = 0x81b;
        *(undefined4 *)(lVar2 + -0x38) = 0x10030;
        *(undefined8 *)(lVar1 + 0x160) = 0;
        *(undefined8 *)(lVar1 + 0x168) = 0;
        *(undefined8 *)(lVar1 + 0x170) = 0;
        *(undefined8 *)(lVar1 + 0x178) = 0;
        *(undefined8 *)(lVar1 + 0x180) = 0;
        *(undefined8 *)(lVar1 + 0x188) = 0;
        *(code **)(lVar1 + 0x180) = ChargeNotificationCallback;
        *(longlong *)(lVar1 + 0x188) = param_1;
        *(undefined8 *)(lVar2 + -0x28) = 0;
        *(undefined8 **)(lVar2 + -0x30) = (undefined8 *)(lVar1 + 0x160);
        *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
        iVar3 = IoSynchronousCallDriver(local_res8,lVar4);
        ObfDereferenceObject(local_res8);
        IoFreeIrp(lVar4);
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



===== RegisterDeviceRemovalNotification @ 140012ee8 =====

int RegisterDeviceRemovalNotification(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  local_res8 = 0;
  local_res10 = 0;
  lVar2 = *(longlong *)(param_2 + 0x18);
  plVar1 = (longlong *)(lVar2 + 0x1a8);
  if (*plVar1 != 0) {
    IoUnregisterPlugPlayNotificationEx();
    *plVar1 = 0;
  }
  iVar3 = IoGetDeviceObjectPointer
                    (*(undefined8 *)(param_1 + 0x28),0x1f0000,&local_res8,&local_res10);
  if (-1 < iVar3) {
    iVar3 = IoRegisterPlugPlayNotification
                      (3,0,local_res8,*(undefined8 *)(*(longlong *)(lVar2 + 0x108) + 8),
                       ChargingPowerSourcePnpNotifyTargetDeviceChange,param_2,plVar1);
    ObfDereferenceObject(local_res8);
  }
  return iVar3;
}



===== SetChargingSource @ 140012fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SetChargingSource(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  byte *pbVar4;
  undefined1 auStackY_d8 [32];
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98[0] = *param_2;
  local_a8 = 0;
  if (*(longlong *)(param_1 + 0xe8) == 0) {
    return 0xc0000001;
  }
  uVar1 = (**(code **)(param_1 + 0xd8))(*(undefined8 *)(param_1 + 0xd0),&local_a8);
  uVar2 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (DAT_14000c080 < 6) goto LAB_14001312e;
    local_9c = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
    local_68 = &local_9c;
    local_48 = "Battery Absent";
    if (local_a8 != 0) {
      local_48 = "-";
    }
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_48[lVar3] != '\0');
    local_40 = (int)lVar3;
    pbVar4 = &DAT_1400082f5;
    local_38 = &local_a4;
    local_a4 = uVar1;
  }
  else {
    if (DAT_14000c080 < 6) goto LAB_14001312e;
    local_68 = &local_a4;
    local_48 = "Battery Absent";
    if (local_a8 != 0) {
      local_48 = "-";
    }
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_48[lVar3] != '\0');
    local_40 = (int)lVar3;
    pbVar4 = &DAT_140007459;
    local_38 = &local_9c;
    local_a4 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
    local_9c = uVar1;
  }
  local_40 = local_40 + 1;
  local_50 = 4;
  local_58 = &local_a0;
  local_60 = 4;
  local_a0 = local_a8;
  local_3c = 0;
  local_30 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(local_48,pbVar4,&s__,param_4,6,local_88);
LAB_14001312e:
  if (-1 < (int)uVar1) {
    uVar1 = BattCSetInformation(param_1,(ulonglong)local_a8,3,(uint *)local_98);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies @ 140013174 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400131af;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140013229:
  while( true ) {
    if (&UNK_14000bbe7 < ppuVar3) {
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
      if (&UNK_14000bbe7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400131af:
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
      if (&UNK_14000bbe7 < ppuVar2) goto LAB_140013229;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140013229;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140013264 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400132fc;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400132fc;
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
LAB_1400132fc:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013350 =====

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
              if (&UNK_14000bbe7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400133d0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400134cd;
  }
LAB_1400134d6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400134cd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400134d6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001349e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001349e;
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
    if (&UNK_14000bbe7 < ppuVar3) goto LAB_1400134d6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400134cd;
}



===== AcAdapterWorkerThread @ 140013500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AcAdapterWorkerThread(undefined *param_1,undefined *param_2,char *param_3,uint *param_4)

{
  longlong *plVar1;
  undefined *puVar2;
  longlong *plVar3;
  int *piVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  code *pcVar8;
  int iVar9;
  longlong lVar10;
  undefined *puVar11;
  uint uVar12;
  undefined1 auStackY_1c8 [32];
  uint local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [2];
  longlong *local_178;
  longlong *local_170;
  undefined8 local_168 [4];
  longlong **local_148;
  undefined8 local_140;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined8 local_120;
  undefined4 *local_118;
  undefined8 local_110;
  char *local_108;
  undefined8 local_100;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  longlong **local_88;
  undefined8 local_80;
  char *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1c8;
  plVar1 = (longlong *)(param_2 + 0xc0);
  if (param_2[0x1ac] == '\0') {
    puVar2 = param_2 + 0xe0;
    puVar11 = param_2;
LAB_14001355c:
    do {
      ExAcquireFastMutex(puVar2);
      plVar6 = (longlong *)*plVar1;
      if (plVar6 != plVar1) {
        if (((longlong *)plVar6[1] == plVar1) &&
           (lVar10 = *plVar6, *(longlong **)(lVar10 + 8) == plVar6)) {
          *plVar1 = lVar10;
          *(longlong **)(lVar10 + 8) = plVar1;
          ExReleaseFastMutex(puVar2);
          plVar3 = plVar6 + -0x15;
          lVar10 = plVar6[2];
          iVar5 = *(int *)(lVar10 + 0x18);
          if ((iVar5 != 0x29406c) ||
             ((*(uint *)(lVar10 + 0x10) < 0x10 || (*(uint *)(lVar10 + 8) < 0x28)))) {
            uVar12 = *(uint *)(lVar10 + 8);
            param_3 = (char *)(ulonglong)*(uint *)(lVar10 + 0x10);
            iVar9 = -0x3ffffdfa;
            local_198 = uVar12;
            if (iVar5 != 0x29406c) {
              if (iVar5 == 0x294070) {
                param_4 = &local_198;
                param_3 = (char *)(ulonglong)uVar12;
                iVar9 = BattCAdapterQueryInfo
                                  ((longlong)param_2,(undefined8 *)plVar6[-0x12],uVar12,param_4);
                uVar12 = local_198;
              }
              else if (iVar5 == 0x294074) {
                iVar9 = BattCSetAdapterStatus
                                  ((longlong)param_2,(undefined4 *)plVar6[-0x12],param_3,param_4);
              }
              else {
                iVar9 = -0x3ffffffe;
              }
            }
            *(int *)(plVar6 + -0xf) = iVar9;
            plVar6[-0xe] = (ulonglong)uVar12;
            BattCClearCancelRoutine((longlong)plVar3);
            if (((int)*(char *)((longlong)plVar6 + -0x65) <= *(char *)((longlong)plVar6 + -0x66) + 1
                ) && (5 < DAT_14000c080)) {
              local_88 = &local_170;
              local_80 = 8;
              iVar5 = *(int *)(plVar6[2] + 0x18);
              if (iVar5 == 0x294070) {
                local_78 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
              }
              else if (iVar5 == 0x29406c) {
                local_78 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
              }
              else {
                local_78 = "IOCTL_POWER_ADAPTER_SET_STATUS";
                if (iVar5 != 0x294074) {
                  local_78 = "<invalid>";
                }
              }
              lVar10 = -1;
              do {
                lVar10 = lVar10 + 1;
              } while (local_78[lVar10] != '\0');
              local_70 = (int)lVar10 + 1;
              local_6c = 0;
              local_184 = *(undefined4 *)(plVar6[2] + 0x18);
              local_68 = &local_184;
              local_180[0] = (undefined4)plVar6[-0xf];
              local_58 = local_180;
              local_48 = "BattCAdapterIoctl";
              local_60 = 4;
              local_50 = 4;
              local_40 = 0x12;
              local_170 = plVar3;
              _tlgWriteTransfer_EtwWriteTransfer
                        ((ulonglong)local_70,&DAT_14000a2c4,param_3,param_4,7,local_a8);
            }
            puVar11 = (undefined *)0x0;
            IofCompleteRequest(plVar3);
            goto LAB_14001355c;
          }
          param_4 = (uint *)0x1;
          LOCK();
          *(undefined4 *)(param_2 + 0x11c) = 1;
          UNLOCK();
          lVar10 = plVar6[2];
          *(undefined8 *)(lVar10 + -0x40) = 0;
          *(undefined8 *)(lVar10 + -0x38) = 0;
          *(undefined8 *)(lVar10 + -0x30) = 0;
          *(undefined **)(lVar10 + -0x28) = param_2;
          LOCK();
          plVar6[-8] = (longlong)AcAdapterCancelStatus;
          UNLOCK();
          if (*(char *)((longlong)plVar6 + -100) != '\0') {
            LOCK();
            lVar10 = plVar6[-8];
            plVar6[-8] = 0;
            UNLOCK();
            if (lVar10 != 0) {
              *(undefined4 *)(plVar6 + -0xf) = 0xc0000120;
            }
          }
          plVar7 = *(longlong **)(param_2 + 0xd8);
          if ((undefined *)*plVar7 == param_2 + 0xd0) {
            plVar6[1] = (longlong)plVar7;
            *plVar6 = (longlong)(param_2 + 0xd0);
            *plVar7 = (longlong)plVar6;
            *(longlong **)(param_2 + 0xd8) = plVar6;
            param_3 = (char *)plVar6[-0x12];
            if (((int)*(char *)((longlong)plVar6 + -0x65) <= *(char *)((longlong)plVar6 + -0x66) + 1
                ) && (5 < DAT_14000c080)) {
              local_148 = &local_178;
              local_140 = 8;
              iVar5 = *(int *)(plVar6[2] + 0x18);
              if (iVar5 == 0x294070) {
                local_138 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
              }
              else if (iVar5 == 0x29406c) {
                local_138 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
              }
              else {
                local_138 = "IOCTL_POWER_ADAPTER_SET_STATUS";
                if (iVar5 != 0x294074) {
                  local_138 = "<invalid>";
                }
              }
              lVar10 = -1;
              do {
                lVar10 = lVar10 + 1;
              } while (local_138[lVar10] != '\0');
              local_130 = (int)lVar10 + 1;
              local_12c = 0;
              local_f8 = "Power Adapter Online";
              local_194 = *(undefined4 *)(plVar6[2] + 0x18);
              uVar12 = *(uint *)(param_3 + 8);
              local_128 = &local_194;
              local_190 = (undefined4)plVar6[-0xf];
              local_118 = &local_190;
              local_108 = "AcAdapterWorkerThread";
              if ((uVar12 & 1) == 0) {
                local_f8 = "Power Adapter Offline";
              }
              local_120 = 4;
              lVar10 = -1;
              local_110 = 4;
              local_100 = 0x16;
              do {
                lVar10 = lVar10 + 1;
              } while (local_f8[lVar10] != '\0');
              local_f0 = (int)lVar10 + 1;
              local_e8 = "REC Engaged";
              local_ec = 0;
              lVar10 = -1;
              if ((uVar12 & 2) == 0) {
                local_e8 = "-";
              }
              do {
                lVar10 = lVar10 + 1;
              } while (local_e8[lVar10] != '\0');
              local_e0 = (int)lVar10 + 1;
              local_d8 = "REC Overridden";
              local_dc = 0;
              if ((uVar12 & 4) == 0) {
                local_d8 = "-";
              }
              lVar10 = -1;
              do {
                lVar10 = lVar10 + 1;
              } while (local_d8[lVar10] != '\0');
              local_d0 = (int)lVar10 + 1;
              puVar11 = &DAT_1400098a7;
              local_18c = *(undefined4 *)(param_3 + 4);
              local_c8 = &local_18c;
              local_188 = *(undefined4 *)(param_3 + 0xc);
              local_b8 = &local_188;
              local_cc = 0;
              local_c0 = 4;
              local_b0 = 4;
              local_178 = plVar3;
              _tlgWriteTransfer_EtwWriteTransfer(local_d8,&DAT_1400098a7,param_3,1,0xc,local_168);
            }
            goto LAB_14001355c;
          }
        }
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        pcVar8 = (code *)swi(3);
        (*pcVar8)();
        return;
      }
      param_1 = puVar2;
      ExReleaseFastMutex();
      LOCK();
      piVar4 = (int *)(param_2 + 0x11c);
      iVar5 = *piVar4;
      *piVar4 = *piVar4;
      UNLOCK();
      if (iVar5 != 0) {
        param_1 = param_2;
        BattCAdapterCheckStatusQueue((ulonglong)param_2,puVar11,param_3,param_4);
      }
      LOCK();
      piVar4 = (int *)(param_2 + 0x118);
      iVar5 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar5 == 1) {
        return;
      }
      if (iVar5 != 2) {
        LOCK();
        *(undefined4 *)(param_2 + 0x118) = 1;
        UNLOCK();
      }
    } while (param_2[0x1ac] == '\0');
  }
  BattCAdapterCompleteIrpQueue(param_1,plVar1,(char *)0xc00002b6,param_4);
  BattCAdapterCompleteIrpQueue(param_1,(longlong *)(param_2 + 0xd0),(char *)0xc00002b6,param_4);
  LOCK();
  piVar4 = (int *)(param_2 + 0x1a8);
  iVar5 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    KeSetEvent(param_2 + 0x1b0,0,0);
  }
  return;
}



===== BattCAdapterCheckStatusQueue @ 140013a34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattCAdapterCheckStatusQueue
               (ulonglong param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  uint *puVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  code *pcVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  longlong lVar14;
  undefined8 uVar15;
  byte *pbVar16;
  ulonglong uVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  char cVar20;
  longlong *plVar21;
  ulonglong uVar22;
  longlong *plVar23;
  uint uVar24;
  undefined1 auStackY_258 [8];
  undefined1 auStackY_250 [24];
  uint local_224;
  undefined8 local_220;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  longlong *local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined1 local_1a8 [32];
  undefined1 *local_188;
  undefined8 local_180;
  undefined8 local_178 [4];
  longlong **local_158;
  undefined8 local_150;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  undefined4 *local_138;
  undefined8 local_130;
  undefined4 *local_128;
  undefined8 local_120;
  char *local_118;
  undefined8 local_110;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_258;
  uVar24 = 0;
  local_1b0 = 0;
  uVar13 = 0xffffffff;
  cVar20 = '\x01';
  local_1d8 = 0;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_224 = 0xffffffff;
  local_1c0 = 0;
  uStack_1b8 = 0;
  uVar9 = KeQueryTimeIncrement();
  puVar19 = auStackY_258;
  puVar18 = auStackY_258;
  uVar17 = BatteryBackupPollRateDc;
  if ((*(byte *)(param_1 + 0x84) & 1) != 0) {
    uVar17 = BatteryBackupPollRateAc;
  }
  LOCK();
  uVar10 = *(uint *)(param_1 + 0x11c);
  *(uint *)(param_1 + 0x11c) = 0;
  uVar22 = (ulonglong)uVar10;
  UNLOCK();
  if (uVar10 != 0) {
    do {
      plVar23 = (longlong *)0x0;
      uVar24 = 0;
      plVar21 = (longlong *)(param_1 + 0xd0);
      LOCK();
      puVar1 = (uint *)(param_1 + 0x120);
      uVar10 = *puVar1;
      uVar22 = (ulonglong)uVar10;
      *puVar1 = *puVar1;
      UNLOCK();
      puVar19 = auStackY_258;
      if ((longlong *)*plVar21 == plVar21) break;
      local_1d0 = *(undefined8 *)(param_1 + 0x80);
      uStack_1c8 = *(undefined8 *)(param_1 + 0x88);
      local_1c0 = *(undefined8 *)(param_1 + 0x90);
      uStack_1b8 = *(undefined8 *)(param_1 + 0x98);
      local_1b0 = *(undefined8 *)(param_1 + 0xa0);
      LOCK();
      iVar11 = *(int *)(param_1 + 0x120);
      *(int *)(param_1 + 0x120) = 0;
      UNLOCK();
      if (((iVar11 != 0) || ((char)uVar10 != '\0')) &&
         (uVar22 = param_1, uVar10 = BattCAdapterQueryStatus(param_1), (int)uVar10 < 0)) {
LAB_140014003:
        uVar24 = (uint)plVar23;
        param_3 = (char *)(ulonglong)uVar10;
        *(undefined8 *)(puVar18 + -8) = 0x140014012;
        BattCAdapterCompleteIrpQueue(uVar22,(longlong *)(param_1 + 0xd0),param_3,param_4);
        puVar19 = puVar18;
        break;
      }
      plVar23 = (longlong *)*plVar21;
      uVar17 = BatteryBackupPollRateDc;
      if ((*(byte *)(param_1 + 0x84) & 1) != 0) {
        uVar17 = BatteryBackupPollRateAc;
      }
      if (plVar23 != plVar21) {
        do {
          plVar21 = plVar23 + -0x15;
          lVar14 = plVar23[2];
          lVar3 = plVar23[-0x12];
          plVar4 = (longlong *)*plVar23;
          if (*(char *)((longlong)plVar23 + -100) != '\0') {
            *(undefined4 *)(plVar23 + -0xf) = 0xc0000120;
          }
          if ((int)plVar23[-0xf] == 0x103) {
            param_3 = (char *)0x28;
            lVar12 = RtlCompareMemory(&local_1d0,param_1 + 0x80);
            if (lVar12 == 0x28) {
              lVar12 = _DAT_fffff78000000320 * (ulonglong)uVar9;
              if (((*(uint *)(lVar3 + 4) != 0) && (*(longlong *)(lVar14 + -0x40) == 0)) &&
                 (*(longlong *)(lVar14 + -0x38) == 0)) {
                uVar22 = (ulonglong)*(uint *)(lVar3 + 4) * 10000 + lVar12;
                param_3 = (char *)(uVar22 >> 0x20);
                *(ulonglong *)(lVar14 + -0x40) = uVar22 & 0xffffffff;
                *(longlong *)(lVar14 + -0x38) = (longlong)(int)(uVar22 >> 0x20);
              }
              local_220 = CONCAT44(*(undefined4 *)(lVar14 + -0x38),*(undefined4 *)(lVar14 + -0x40));
              uVar22 = local_220 - lVar12;
              if (0 < (longlong)uVar22) {
                if ((*(int *)(lVar3 + 4) != -1) && ((longlong)uVar22 < (longlong)uVar17)) {
                  uVar17 = uVar22;
                }
                goto LAB_140013c89;
              }
            }
            *(undefined4 *)(plVar23 + -0xf) = 0;
            puVar5 = (undefined8 *)plVar23[-0x12];
            plVar23[-0xe] = 0x28;
            uVar15 = *(undefined8 *)(param_1 + 0x88);
            *puVar5 = *(undefined8 *)(param_1 + 0x80);
            puVar5[1] = uVar15;
            uVar15 = *(undefined8 *)(param_1 + 0x98);
            puVar5[2] = *(undefined8 *)(param_1 + 0x90);
            puVar5[3] = uVar15;
            puVar5[4] = *(undefined8 *)(param_1 + 0xa0);
            uVar13 = *(uint *)(lVar3 + 0xc);
            if ((uVar13 != 0) && (uVar13 <= local_224)) {
              local_224 = uVar13;
            }
          }
          else {
          }
LAB_140013c89:
          uVar13 = local_224;
          if ((int)plVar23[-0xf] != 0x103) {
            lVar14 = *plVar23;
            if ((*(longlong **)(lVar14 + 8) != plVar23) ||
               (plVar6 = (longlong *)plVar23[1], (longlong *)*plVar6 != plVar23)) {
              uVar22 = 3;
              pcVar7 = (code *)swi(0x29);
              uVar10 = (*pcVar7)();
              puVar18 = auStackY_250;
              goto LAB_140014003;
            }
            *plVar6 = lVar14;
            *(longlong **)(lVar14 + 8) = plVar6;
            BattCClearCancelRoutine((longlong)plVar21);
            param_4 = 1;
            if (((int)*(char *)((longlong)plVar23 + -0x65) <=
                 *(char *)((longlong)plVar23 + -0x66) + 1) && (5 < DAT_14000c080)) {
              local_158 = &local_1f0;
              local_150 = 8;
              iVar11 = *(int *)(plVar23[2] + 0x18);
              if (iVar11 == 0x294070) {
                local_148 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
              }
              else if (iVar11 == 0x29406c) {
                local_148 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
              }
              else {
                local_148 = "IOCTL_POWER_ADAPTER_SET_STATUS";
                if (iVar11 != 0x294074) {
                  local_148 = "<invalid>";
                }
              }
              param_3 = (char *)0x0;
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_148[lVar14] != '\0');
              local_140 = (int)lVar14 + 1;
              local_13c = 0;
              local_108 = "Power Adapter Online";
              local_20c = *(undefined4 *)(plVar23[2] + 0x18);
              uVar24 = *(uint *)(param_1 + 0x84);
              local_138 = &local_20c;
              local_208 = (undefined4)plVar23[-0xf];
              local_128 = &local_208;
              local_118 = "BattCAdapterCheckStatusQueue";
              if ((uVar24 & 1) == 0) {
                local_108 = "Power Adapter Offline";
              }
              local_130 = 4;
              lVar14 = -1;
              local_120 = 4;
              local_110 = 0x1d;
              do {
                lVar14 = lVar14 + 1;
              } while (local_108[lVar14] != '\0');
              local_100 = (int)lVar14 + 1;
              local_f8 = "REC Engaged";
              local_fc = 0;
              lVar14 = -1;
              if ((uVar24 & 2) == 0) {
                local_f8 = "-";
              }
              do {
                lVar14 = lVar14 + 1;
              } while (local_f8[lVar14] != '\0');
              local_f0 = (int)lVar14 + 1;
              local_e8 = "REC Overridden";
              local_ec = 0;
              if ((uVar24 & 4) == 0) {
                local_e8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_e8[lVar14] != '\0');
              uVar24 = *(uint *)(lVar3 + 8);
              local_e0 = (int)lVar14 + 1;
              local_204 = *(undefined4 *)(param_1 + 0x88);
              local_d8 = &local_204;
              local_200 = *(undefined4 *)(param_1 + 0x8c);
              local_c8 = &local_200;
              local_1fc = *(undefined4 *)(param_1 + 0x90);
              local_b8 = &local_1fc;
              local_1e8 = *(undefined8 *)(param_1 + 0x98);
              local_a8 = &local_1e8;
              local_1e0 = *(undefined8 *)(param_1 + 0xa0);
              local_98 = &local_1e0;
              local_88 = "Power Adapter Online";
              if ((uVar24 & 1) == 0) {
                local_88 = "Power Adapter Offline";
              }
              local_dc = 0;
              lVar14 = -1;
              local_d0 = 4;
              local_c0 = 4;
              local_b0 = 4;
              local_a0 = 8;
              local_90 = 8;
              do {
                lVar14 = lVar14 + 1;
              } while (local_88[lVar14] != '\0');
              local_80 = (int)lVar14 + 1;
              local_78 = "REC Engaged";
              local_7c = 0;
              if ((uVar24 & 2) == 0) {
                local_78 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_78[lVar14] != '\0');
              local_70 = (int)lVar14 + 1;
              local_68 = "REC Overridden";
              local_6c = 0;
              if ((uVar24 & 4) == 0) {
                local_68 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_68[lVar14] != '\0');
              local_60 = (int)lVar14 + 1;
              local_1f8 = *(undefined4 *)(lVar3 + 4);
              local_58 = &local_1f8;
              local_1f4 = *(undefined4 *)(lVar3 + 0xc);
              local_48 = &local_1f4;
              local_5c = 0;
              local_50 = 4;
              local_40 = 4;
              local_1f0 = plVar21;
              _tlgWriteTransfer_EtwWriteTransfer(local_68,&DAT_1400093c6,0,1,0x14,local_178);
            }
            IofCompleteRequest(plVar21,0);
          }
          uVar22 = param_1 + 0x80;
          plVar23 = plVar4;
        } while (plVar4 != (longlong *)(param_1 + 0xd0));
      }
      uVar24 = 0;
      LOCK();
      iVar11 = *(int *)(param_1 + 0x11c);
      *(int *)(param_1 + 0x11c) = 0;
      UNLOCK();
      puVar19 = auStackY_258;
    } while (iVar11 != 0);
    cVar20 = puVar19[0x30];
  }
  if (*(longlong **)(param_1 + 0xd0) == (longlong *)(param_1 + 0xd0)) {
    pcVar7 = *(code **)(param_1 + 0x70);
    if (pcVar7 != (code *)0x0) {
      uVar15 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(puVar19 + -8) = 0x140014039;
      iVar11 = (*pcVar7)();
      if (iVar11 < 0) {
        if (5 < DAT_14000c080) {
          *(int *)(puVar19 + 0x40) = iVar11;
          local_188 = puVar19 + 0x40;
          local_180 = 4;
          *(undefined1 **)(puVar19 + 0x28) = local_1a8;
          *(undefined4 *)(puVar19 + 0x20) = 3;
          *(undefined8 *)(puVar19 + -8) = 0x140014078;
          _tlgWriteTransfer_EtwWriteTransfer
                    (uVar15,&DAT_1400091bf,param_3,param_4,*(undefined4 *)(puVar19 + 0x20),
                     *(undefined8 **)(puVar19 + 0x28));
        }
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 2;
      }
      else {
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffd;
      }
    }
    goto LAB_14001420a;
  }
  LOCK();
  *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0x1ac) == (char)uVar24) {
    param_4 = 1000;
    lVar14 = param_1 + 0x128;
    *(ulonglong *)(puVar19 + 0x20) = param_1 + 0x168;
    param_3 = (char *)0x0;
    *(undefined8 *)(puVar19 + -8) = 0x14001411b;
    cVar8 = KeSetCoalescableTimer();
    if (cVar8 != '\0') {
      LOCK();
      piVar2 = (int *)(param_1 + 0x1a8);
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar11 == 1) {
        lVar14 = param_1 + 0x1b0;
        param_3 = (char *)0x0;
        *(undefined8 *)(puVar19 + -8) = 0x140014147;
        KeSetEvent(lVar14,0);
      }
    }
    if (5 < DAT_14000c080) {
      local_180 = 8;
      local_188 = puVar19 + 0x40;
      *(ulonglong *)(puVar19 + 0x40) = uVar17 / 10000000;
      *(undefined1 **)(puVar19 + 0x28) = local_1a8;
      *(undefined4 *)(puVar19 + 0x20) = 3;
      *(undefined8 *)(puVar19 + -8) = 0x140014199;
      _tlgWriteTransfer_EtwWriteTransfer
                (lVar14,&DAT_1400085ab,param_3,param_4,*(undefined4 *)(puVar19 + 0x20),
                 *(undefined8 **)(puVar19 + 0x28));
    }
    pcVar7 = *(code **)(param_1 + 0x68);
    if (pcVar7 == (code *)0x0) goto LAB_14001420a;
    uVar15 = *(undefined8 *)(param_1 + 0x10);
    if (cVar20 != '\0') {
      uVar13 = uVar24;
    }
    local_1d8 = CONCAT44(uVar13,(undefined4)local_1d8);
    *(undefined8 *)(puVar19 + -8) = 0x1400141ba;
    iVar11 = (*pcVar7)(uVar15,&local_1d8);
    if (-1 < iVar11) {
      *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffe;
      goto LAB_14001420a;
    }
    uVar13 = *(uint *)(param_1 + 0x7c) | 1;
    uVar22 = (ulonglong)uVar13;
    *(uint *)(param_1 + 0x7c) = uVar13;
    if (DAT_14000c080 < 6) goto LAB_14001420a;
    *(int *)(puVar19 + 0x40) = iVar11;
    pbVar16 = &DAT_14000a24f;
    local_188 = puVar19 + 0x40;
    local_180 = 4;
  }
  else {
    LOCK();
    piVar2 = (int *)(param_1 + 0x1a8);
    iVar11 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar11 == 1) {
      uVar22 = param_1 + 0x1b0;
      param_3 = (char *)0x0;
      *(undefined8 *)(puVar19 + -8) = 0x1400140c3;
      KeSetEvent(uVar22,0);
    }
    if (DAT_14000c080 < 6) goto LAB_14001420a;
    pbVar16 = &DAT_14000a288;
    puVar19[0x31] = *(undefined1 *)(param_1 + 0x1ac);
    local_188 = puVar19 + 0x31;
    local_180 = 1;
  }
  *(undefined1 **)(puVar19 + 0x28) = local_1a8;
  *(undefined4 *)(puVar19 + 0x20) = 3;
  *(undefined8 *)(puVar19 + -8) = 0x140014202;
  _tlgWriteTransfer_EtwWriteTransfer
            (uVar22,pbVar16,param_3,param_4,*(undefined4 *)(puVar19 + 0x20),
             *(undefined8 **)(puVar19 + 0x28));
LAB_14001420a:
  *(undefined8 *)(puVar19 + -8) = 0x140014219;
  return;
}



===== BattCAdapterCompleteIrpQueue @ 140014244 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCAdapterCompleteIrpQueue
               (undefined8 param_1,longlong *param_2,char *param_3,undefined8 param_4)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined4 local_98;
  undefined4 local_94;
  longlong *local_90;
  undefined8 local_88 [4];
  longlong **local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  uint local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  puVar6 = auStackY_c8;
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  pcVar7 = param_3;
  do {
    plVar3 = (longlong *)*param_2;
    if (plVar3 == param_2) {
LAB_1400143c2:
      *(undefined8 *)(puVar6 + -8) = 0x1400143ce;
      return;
    }
    if (((longlong *)plVar3[1] != param_2) || (lVar5 = *plVar3, *(longlong **)(lVar5 + 8) != plVar3)
       ) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStackY_c0;
      goto LAB_1400143c2;
    }
    *param_2 = lVar5;
    plVar1 = plVar3 + -0x15;
    *(longlong **)(lVar5 + 8) = param_2;
    BattCClearCancelRoutine((longlong)plVar1);
    *(int *)(plVar3 + -0xf) = (int)param_3;
    if (((int)*(char *)((longlong)plVar3 + -0x65) <= *(char *)((longlong)plVar3 + -0x66) + 1) &&
       (5 < DAT_14000c080)) {
      local_5c = 0;
      local_68 = &local_90;
      local_60 = 8;
      iVar2 = *(int *)(plVar3[2] + 0x18);
      if (iVar2 == 0x294070) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
      }
      else if (iVar2 == 0x29406c) {
        local_58 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
      }
      else {
        local_58 = "IOCTL_POWER_ADAPTER_SET_STATUS";
        pcVar7 = "<invalid>";
        if (iVar2 != 0x294074) {
          local_58 = "<invalid>";
        }
      }
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_58[lVar5] != '\0');
      local_4c = 0;
      local_50 = (int)lVar5 + 1;
      local_98 = *(undefined4 *)(plVar3[2] + 0x18);
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_48 = &local_98;
      local_38 = &local_94;
      local_28 = "BattCAdapterCompleteIrpQueue";
      local_40 = 4;
      local_30 = 4;
      local_20 = 0x1d;
      local_94 = (int)param_3;
      local_90 = plVar1;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_50,&DAT_1400085e5,pcVar7,param_4,7,local_88);
    }
    IofCompleteRequest(plVar1,0);
  } while( true );
}



===== BattCAdapterQueryInfo @ 1400143f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
BattCAdapterQueryInfo(longlong param_1,undefined8 *param_2,uint param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined1 auStackY_1c8 [32];
  int local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170 [2];
  int local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 local_140;
  uint uStack_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined8 local_120;
  undefined4 uStack_118;
  undefined8 local_108 [4];
  int *local_e8;
  undefined8 local_e0;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_120 = 0;
  uVar4 = 0;
  local_140 = 0;
  uStack_138 = 0;
  uStack_134 = 0;
  local_130 = 0;
  uStack_12c = 0;
  uStack_128 = 0;
  uStack_124 = 0;
  if (param_3 < 0x2c) {
    bVar6 = false;
    uVar5 = 1;
    local_140._4_4_ = 0;
    uVar4 = 0xc0000023;
    local_198 = local_140._4_4_;
    local_178 = 0;
  }
  else {
    local_198 = *(int *)(param_1 + 0x30);
    uStack_164 = *(undefined4 *)(param_1 + 0x34);
    uStack_160 = *(undefined4 *)(param_1 + 0x38);
    uStack_15c = *(undefined4 *)(param_1 + 0x3c);
    uVar5 = *(undefined8 *)(param_1 + 0x38);
    local_158 = *(undefined8 *)(param_1 + 0x40);
    uVar2 = *(undefined8 *)(param_1 + 0x48);
    uVar1 = *(undefined8 *)(param_1 + 0x50);
    bVar6 = (char)uStack_164 != '\0';
    local_140 = CONCAT44(local_198,(uint)*(byte *)(param_1 + 8));
    uStack_138 = (uint)bVar6;
    uStack_150._0_4_ = (undefined4)uVar2;
    uStack_150._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_148._0_4_ = (undefined4)uVar1;
    local_148._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
    uStack_134 = (undefined4)uVar5;
    local_130 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uStack_12c = (undefined4)local_158;
    uStack_128 = (undefined4)((ulonglong)local_158 >> 0x20);
    uVar5 = 0;
    if (local_198 == -1) {
      uVar5 = 2;
    }
    uStack_124 = (undefined4)uStack_150;
    local_120 = CONCAT44((undefined4)local_148,uStack_150._4_4_);
    uStack_118 = local_148._4_4_;
    *param_2 = local_140;
    param_2[1] = CONCAT44(uStack_134,uStack_138);
    param_2[2] = CONCAT44(uStack_12c,local_130);
    param_2[3] = CONCAT44((undefined4)uStack_150,uStack_128);
    param_2[4] = local_120;
    *(undefined4 *)(param_2 + 5) = local_148._4_4_;
    *param_4 = 0x2c;
    local_178 = local_148._4_4_;
    local_168 = local_198;
    uStack_150 = uVar2;
    local_148 = uVar1;
  }
  if (5 < DAT_14000c080) {
    local_e8 = &local_198;
    local_e0 = 4;
    local_d8 = "REC Supported";
    if (!bVar6) {
      local_d8 = "-";
    }
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_d8[lVar3] != '\0');
    local_d0 = (int)lVar3 + 1;
    local_194 = uStack_134;
    local_c8 = &local_194;
    local_190 = local_130;
    local_b8 = &local_190;
    local_18c = uStack_12c;
    local_a8 = &local_18c;
    local_188 = uStack_128;
    local_98 = &local_188;
    local_184 = uStack_124;
    local_88 = &local_184;
    local_180 = (undefined4)local_120;
    local_78 = &local_180;
    local_17c = local_120._4_4_;
    local_68 = &local_17c;
    local_58 = &local_178;
    local_48 = &local_174;
    local_38 = local_170;
    local_cc = 0;
    local_c0 = 4;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 4;
    local_80 = 4;
    local_70 = 4;
    local_60 = 4;
    local_50 = 4;
    local_174 = (undefined4)uVar5;
    local_40 = 4;
    local_30 = 4;
    local_170[0] = uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(local_d8,&DAT_1400091fc,uVar5,param_4,0xe,local_108);
  }
  return uVar4;
}



===== BattCAdapterQueryStatus @ 14001465c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 BattCAdapterQueryStatus(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined1 auStackY_118 [32];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8 [4];
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_dc = (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x10),param_1 + 0x80);
  uVar4 = local_dc;
  if (5 < DAT_14000c080) {
    uVar1 = *(uint *)(param_1 + 0x84);
    local_a8 = "Power Adapter Online";
    if ((uVar1 & 1) == 0) {
      local_a8 = "Power Adapter Offline";
    }
    lVar2 = -1;
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_a8[lVar3] != '\0');
    local_a0 = (int)lVar3 + 1;
    local_9c = 0;
    local_98 = "REC Engaged";
    lVar3 = -1;
    if ((uVar1 & 2) == 0) {
      local_98 = "-";
    }
    do {
      lVar3 = lVar3 + 1;
    } while (local_98[lVar3] != '\0');
    local_90 = (int)lVar3 + 1;
    local_8c = 0;
    local_88 = "REC Overridden";
    if ((uVar1 & 4) == 0) {
      local_88 = "-";
    }
    do {
      lVar2 = lVar2 + 1;
    } while (local_88[lVar2] != '\0');
    local_80 = (int)lVar2 + 1;
    local_70 = 4;
    local_e8 = *(undefined4 *)(param_1 + 0x88);
    local_78 = &local_e8;
    local_e4 = *(undefined4 *)(param_1 + 0x8c);
    local_68 = &local_e4;
    local_e0 = *(undefined4 *)(param_1 + 0x90);
    local_58 = &local_e0;
    local_d8 = *(undefined8 *)(param_1 + 0x98);
    local_48 = &local_d8;
    local_d0 = *(undefined8 *)(param_1 + 0xa0);
    local_38 = &local_d0;
    local_28 = &local_dc;
    local_60 = 4;
    local_50 = 4;
    local_20 = 4;
    local_7c = 0;
    local_40 = 8;
    local_30 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(local_88,&DAT_14000a372,(ulonglong)uVar1,0,0xb,local_c8);
  }
  return uVar4;
}



===== BattCCheckStatusQueue @ 140014818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong *
BattCCheckStatusQueue(longlong param_1,longlong param_2,longlong *param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  longlong *plVar2;
  char cVar3;
  int *piVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined1 auVar8 [16];
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  ulonglong uVar17;
  longlong lVar18;
  longlong *plVar19;
  ulonglong uVar20;
  longlong lVar21;
  char *pcVar22;
  undefined4 uVar23;
  byte *pbVar24;
  ulonglong uVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  char *pcVar28;
  uint *puVar29;
  longlong lVar30;
  undefined1 auStackY_718 [8];
  undefined1 auStackY_710 [24];
  uint local_6e4;
  uint local_6e0;
  uint local_6c0;
  undefined8 local_6b8;
  char local_6b0;
  uint local_6a0;
  undefined4 local_69c;
  undefined4 local_698;
  int local_694;
  int local_690;
  undefined4 local_68c;
  int local_688;
  undefined4 local_684;
  uint local_680;
  uint local_67c;
  uint local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_66c;
  int local_668;
  undefined4 local_664;
  uint local_660;
  uint local_65c;
  uint local_658;
  undefined4 local_654;
  undefined4 local_650;
  undefined4 local_64c;
  undefined4 local_648;
  int local_644;
  undefined4 local_640;
  uint local_63c;
  uint local_638;
  uint local_634;
  undefined4 local_630;
  undefined4 local_62c;
  undefined4 local_628;
  int local_624;
  undefined4 local_620;
  uint local_61c;
  uint local_618;
  uint local_614;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 local_608;
  uint local_604;
  undefined4 local_600 [2];
  longlong *local_5f8;
  longlong *local_5f0;
  longlong *local_5e8;
  ulonglong local_5e0;
  ulonglong local_5d8;
  ulonglong local_5d0;
  ulonglong local_5c8;
  ulonglong local_5c0;
  undefined8 local_5b8;
  uint local_5b0;
  uint uStack_5ac;
  uint uStack_5a8;
  uint uStack_5a4;
  undefined8 local_5a0;
  undefined8 uStack_598;
  uint local_590;
  uint local_58c;
  uint local_588;
  undefined8 local_584;
  undefined8 local_578;
  undefined8 uStack_570;
  undefined4 local_568;
  undefined1 local_558 [32];
  undefined1 *local_538;
  undefined8 local_530;
  undefined1 *local_528;
  undefined8 local_520;
  char *local_518;
  int local_510;
  undefined4 local_50c;
  char *local_508;
  undefined8 local_500;
  undefined1 local_4f8 [32];
  undefined4 *local_4d8;
  undefined8 local_4d0;
  int *local_4c8;
  undefined8 local_4c0;
  char *local_4b8;
  int local_4b0;
  undefined4 local_4ac;
  undefined4 *local_4a8;
  undefined8 local_4a0;
  uint *local_498;
  undefined8 local_490;
  uint *local_488;
  undefined8 local_480;
  uint *local_478;
  undefined8 local_470;
  undefined4 *local_468;
  undefined8 local_460;
  undefined4 *local_458;
  undefined8 local_450;
  ulonglong *local_448;
  undefined8 local_440;
  undefined1 *local_438;
  undefined8 local_430;
  undefined1 *local_428;
  undefined8 local_420;
  undefined4 *local_418;
  undefined8 local_410;
  undefined8 *local_408;
  undefined8 local_400;
  undefined1 local_3f8 [32];
  undefined4 *local_3d8;
  undefined8 local_3d0;
  int *local_3c8;
  undefined8 local_3c0;
  char *local_3b8;
  int local_3b0;
  undefined4 local_3ac;
  undefined4 *local_3a8;
  undefined8 local_3a0;
  uint *local_398;
  undefined8 local_390;
  uint *local_388;
  undefined8 local_380;
  uint *local_378;
  undefined8 local_370;
  undefined4 *local_368;
  undefined8 local_360;
  undefined4 *local_358;
  undefined8 local_350;
  ulonglong *local_348;
  undefined8 local_340;
  undefined1 *local_338;
  undefined8 local_330;
  undefined1 *local_328;
  undefined8 local_320;
  undefined4 *local_318;
  undefined8 local_310;
  undefined1 local_308 [32];
  undefined4 *local_2e8;
  undefined8 local_2e0;
  int *local_2d8;
  undefined8 local_2d0;
  char *local_2c8;
  int local_2c0;
  undefined4 local_2bc;
  undefined4 *local_2b8;
  undefined8 local_2b0;
  uint *local_2a8;
  undefined8 local_2a0;
  uint *local_298;
  undefined8 local_290;
  uint *local_288;
  undefined8 local_280;
  undefined4 *local_278;
  undefined8 local_270;
  undefined4 *local_268;
  undefined8 local_260;
  ulonglong *local_258;
  undefined8 local_250;
  undefined1 *local_248;
  undefined8 local_240;
  undefined1 *local_238;
  undefined8 local_230;
  ulonglong *local_228;
  undefined8 local_220;
  undefined1 local_218 [32];
  undefined4 *local_1f8;
  undefined8 local_1f0;
  int *local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  int local_1d0;
  undefined4 local_1cc;
  undefined4 *local_1c8;
  undefined8 local_1c0;
  uint *local_1b8;
  undefined8 local_1b0;
  uint *local_1a8;
  undefined8 local_1a0;
  uint *local_198;
  undefined8 local_190;
  undefined4 *local_188;
  undefined8 local_180;
  undefined4 *local_178;
  undefined8 local_170;
  ulonglong *local_168;
  undefined8 local_160;
  undefined1 *local_158;
  undefined8 local_150;
  undefined1 *local_148;
  undefined8 local_140;
  undefined8 local_138 [4];
  undefined4 *local_118;
  undefined8 local_110;
  longlong **local_108;
  undefined8 local_100;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  uint *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  char *local_c8;
  undefined8 local_c0;
  undefined1 local_b8 [32];
  undefined4 *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_718;
  local_6e4 = 0xffffffff;
  local_568 = 0;
  local_6e0 = 0xffffffff;
  local_578 = 0;
  uStack_570 = 0;
  local_6c0 = 0xffffffff;
  Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  local_604 = KeQueryTimeIncrement();
  puVar26 = auStackY_718;
  uVar25 = BatteryBackupPollRateDc;
  if ((*(byte *)(param_2 + 0x98) & 1) != 0) {
    uVar25 = BatteryBackupPollRateAc;
  }
  local_588 = 0xffffffff;
  lVar30 = -1;
  local_584 = 0;
  local_5a0 = 0;
  uStack_598 = 0;
  local_58c = 0;
  LOCK();
  iVar16 = *(int *)(param_1 + 300);
  *(int *)(param_1 + 300) = 0;
  UNLOCK();
  cVar13 = '\0';
  while (puVar27 = auStackY_718, iVar16 != 0) {
    local_590 = *(uint *)(param_2 + 0x98);
    local_588 = 0xffffffff;
    local_58c = 0;
    LOCK();
    puVar1 = (undefined4 *)(param_1 + 0x134);
    cVar13 = (char)*puVar1;
    *puVar1 = *puVar1;
    UNLOCK();
    puVar27 = auStackY_718;
    if (*(longlong **)(param_2 + 0x58) == (longlong *)(param_2 + 0x58)) break;
    LOCK();
    iVar16 = *(int *)(param_1 + 0x134);
    *(int *)(param_1 + 0x134) = 0;
    UNLOCK();
    local_6b0 = cVar13;
    if (iVar16 != 0) {
      *(undefined4 *)(param_2 + 0xac) = 0;
      local_6b0 = '\x01';
    }
    lVar18 = _DAT_fffff78000000008;
    lVar21 = *(longlong *)(param_2 + 0x90);
    uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar17 != 0) {
      local_578 = *(undefined8 *)(param_2 + 0x1d4);
      uStack_570 = *(undefined8 *)(param_2 + 0x1dc);
      local_568 = *(undefined4 *)(param_2 + 0x1e4);
      local_5a0 = *(undefined8 *)(param_2 + 0x98);
      uStack_598 = *(undefined8 *)(param_2 + 0xa0);
    }
    if ((local_6b0 != '\0') || (lVar21 + 10000000 <= lVar18)) {
      uVar14 = BattCQueryStatus(param_1,param_2,param_3,0);
      param_4 = 0;
      cVar13 = local_6b0;
      if ((int)uVar14 < 0) {
LAB_140014f12:
        param_3 = (longlong *)(ulonglong)uVar14;
        *(undefined8 *)(puVar26 + -8) = 0x140014f21;
        BattCCompleteIrpQueue(param_1,(longlong *)(param_2 + 0x58),(char *)param_3,param_4);
        puVar27 = puVar26;
        break;
      }
      local_590 = *(uint *)(param_2 + 0x98) & 0xf;
      *(longlong *)(param_2 + 0x90) = lVar18;
    }
    param_4 = 0;
    plVar19 = *(longlong **)(param_2 + 0x58);
    uVar25 = BatteryBackupPollRateDc;
    if ((*(byte *)(param_2 + 0x98) & 1) != 0) {
      uVar25 = BatteryBackupPollRateAc;
    }
    if (plVar19 != (longlong *)(param_2 + 0x58)) {
      do {
        param_4 = 0;
        piVar4 = (int *)plVar19[-0x12];
        plVar2 = plVar19 + -0x15;
        lVar21 = plVar19[2];
        local_5b0 = *(uint *)(param_2 + 0x98);
        uVar14 = *(uint *)(param_2 + 0x9c);
        uVar9 = *(uint *)(param_2 + 0xa0);
        uVar10 = *(uint *)(param_2 + 0xa4);
        local_5e8 = (longlong *)*plVar19;
        plVar5 = plVar19 + -0xf;
        if (*(int *)(param_2 + 0x44) != *piVar4) {
          *(int *)plVar5 = -0x3ffffff2;
        }
        if (*(char *)((longlong)plVar19 + -100) != '\0') {
          *(int *)plVar5 = -0x3ffffee0;
        }
        if (*(int *)(lVar21 + 0x18) == 0x29404c) {
          local_5b0 = local_5b0 & 0xf;
        }
        uVar12 = local_5b0;
        local_5f8 = plVar19;
        uStack_5ac = uVar14;
        uStack_5a8 = uVar9;
        uStack_5a4 = uVar10;
        if ((int)*plVar5 == 0x103) {
          bVar11 = false;
          if (*(int *)(lVar21 + 0x18) == 0x294064) {
            LOCK();
            iVar16 = *(int *)(param_1 + 0x2e8);
            *(int *)(param_1 + 0x2e8) = 0;
            UNLOCK();
            bVar11 = false;
            if (iVar16 != 0) {
              bVar11 = true;
            }
          }
          if (((local_5b0 == piVar4[2]) && ((uint)piVar4[3] <= uVar14)) &&
             (uVar14 <= (uint)piVar4[4])) {
            lVar18 = _DAT_fffff78000000320 * (ulonglong)local_604;
            if (((piVar4[1] != 0) && (*(longlong *)(lVar21 + -0x40) == 0)) &&
               (*(longlong *)(lVar21 + -0x38) == 0)) {
              uVar17 = (ulonglong)(uint)piVar4[1] * 10000 + lVar18;
              *(ulonglong *)(lVar21 + -0x40) = uVar17 & 0xffffffff;
              *(longlong *)(lVar21 + -0x38) = (longlong)(int)(uVar17 >> 0x20);
            }
            local_6b8 = CONCAT44(*(undefined4 *)(lVar21 + -0x38),*(undefined4 *)(lVar21 + -0x40));
            uVar17 = local_6b8 - lVar18;
            if ((longlong)uVar17 < 1) goto LAB_140014b3e;
            if ((piVar4[1] != -1) && ((longlong)uVar17 < (longlong)uVar25)) {
              uVar25 = uVar17;
            }
          }
          else {
LAB_140014b3e:
            bVar11 = true;
          }
          uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar17 == 0) {
            if (bVar11) goto LAB_140014c42;
          }
          else if (((bVar11) || (uStack_598._4_4_ != *(int *)(param_2 + 0xa4))) ||
                  (lVar18 = RtlCompareMemory(&local_578,param_2 + 0x1d4,0x14), lVar18 != 0x14)) {
LAB_140014c42:
            plVar19 = local_5f8;
            puVar29 = (uint *)local_5f8[-0x12];
            *(undefined4 *)(local_5f8 + -0xf) = 0;
            local_5f8[-0xe] = 0x10;
            *puVar29 = uVar12;
            puVar29[1] = uVar14;
            puVar29[2] = uVar9;
            puVar29[3] = uVar10;
            uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
            if (((int)uVar17 != 0) && (*(int *)(lVar21 + 0x18) == 0x294064)) {
              if (0x23 < *(uint *)(lVar21 + 8)) {
                lVar21 = plVar19[-0x12];
                *(undefined1 *)(lVar21 + 0x10) = 1;
                *(undefined4 *)(lVar21 + 0x14) = *(undefined4 *)(param_2 + 0x1d8);
                *(undefined4 *)(lVar21 + 0x18) = *(undefined4 *)(param_2 + 0x1dc);
                *(undefined4 *)(lVar21 + 0x1c) = *(undefined4 *)(param_2 + 0x1e0);
                *(undefined4 *)(lVar21 + 0x20) = *(undefined4 *)(param_2 + 0x1e4);
              }
            }
            goto LAB_140014cbd;
          }
          if (local_58c < (uint)piVar4[3]) {
            local_58c = piVar4[3];
          }
          if ((uint)piVar4[4] < local_588) {
            local_588 = piVar4[4];
          }
          uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          param_4 = 0;
          plVar19 = local_5f8;
          if ((int)uVar17 != 0) {
            lVar21 = local_5f8[-0x12];
            uVar14 = *(uint *)(lVar21 + 0x18);
            if ((uVar14 != 0) && (uVar14 <= local_6e0)) {
              local_6e0 = uVar14;
            }
            uVar14 = *(uint *)(lVar21 + 0x1c);
            if ((uVar14 != 0) && (uVar14 <= local_6c0)) {
              local_6c0 = uVar14;
            }
            uVar14 = *(uint *)(lVar21 + 0x20);
            if (uVar14 != 0) {
              if (uVar14 <= local_6e4) {
                local_6e4 = uVar14;
              }
            }
          }
        }
LAB_140014cbd:
        cVar13 = '\x01';
        param_3 = plVar2;
        if ((int)plVar19[-0xf] != 0x103) {
          lVar21 = *plVar19;
          if ((*(longlong **)(lVar21 + 8) != plVar19) ||
             (plVar5 = (longlong *)plVar19[1], (longlong *)*plVar5 != plVar19)) {
            pcVar6 = (code *)swi(0x29);
            uVar14 = (*pcVar6)(3);
            puVar26 = auStackY_710;
            goto LAB_140014f12;
          }
          *plVar5 = lVar21;
          *(longlong **)(lVar21 + 8) = plVar5;
          BattCClearCancelRoutine((longlong)plVar2);
          if (((int)*(char *)((longlong)plVar19 + -0x65) <= *(char *)((longlong)plVar19 + -0x66) + 1
              ) && (5 < DAT_14000c080)) {
            local_600[0] = *(undefined4 *)(param_1 + 0x2e4);
            local_118 = local_600;
            local_108 = &local_5f0;
            param_4 = 8;
            local_110 = 4;
            local_100 = 8;
            iVar16 = *(int *)(plVar19[2] + 0x18);
            if (iVar16 == 0x294040) {
              local_f8 = "IOCTL_BATTERY_QUERY_TAG";
            }
            else if (iVar16 == 0x294044) {
              local_f8 = "IOCTL_BATTERY_QUERY_INFORMATION";
            }
            else if (iVar16 == 0x298048) {
              local_f8 = "IOCTL_BATTERY_SET_INFORMATION";
            }
            else if (iVar16 == 0x29404c) {
              local_f8 = "IOCTL_BATTERY_QUERY_STATUS";
            }
            else if (iVar16 == 0x294050) {
              local_f8 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
            }
            else if (iVar16 == 0x294064) {
              local_f8 = "IOCTL_BATTERY_QUERY_STATUS_EX";
            }
            else if (iVar16 == 0x45400c) {
              local_f8 = "IOCTL_PMI_GET_MEASUREMENT";
            }
            else if (iVar16 == 0x454000) {
              local_f8 = "IOCTL_PMI_GET_CAPABILITIES";
            }
            else if (iVar16 == 0x454004) {
              local_f8 = "IOCTL_PMI_GET_CONFIGURATION";
            }
            else if (iVar16 == 0x458008) {
              local_f8 = "IOCTL_PMI_SET_CONFIGURATION";
            }
            else {
              local_f8 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
              if (iVar16 != 0x45c010) {
                local_f8 = "<invalid>";
              }
            }
            lVar21 = -1;
            do {
              lVar21 = lVar21 + 1;
            } while (local_f8[lVar21] != '\0');
            local_f0 = (int)lVar21 + 1;
            local_ec = 0;
            local_6a0 = *(uint *)(plVar19[2] + 0x18);
            local_e8 = &local_6a0;
            local_69c = (undefined4)plVar19[-0xf];
            local_d8 = &local_69c;
            local_c8 = "BattCCheckStatusQueue";
            local_e0 = 4;
            local_d0 = 4;
            local_c0 = 0x16;
            local_5f0 = plVar2;
            _tlgWriteTransfer_EtwWriteTransfer
                      ((ulonglong)local_6a0,&DAT_140009a0c,param_3,8,8,local_138);
          }
          IofCompleteRequest(plVar2,0);
        }
        plVar19 = local_5e8;
      } while (local_5e8 != (longlong *)(param_2 + 0x58));
    }
    LOCK();
    iVar16 = *(int *)(param_1 + 300);
    *(int *)(param_1 + 300) = 0;
    UNLOCK();
    cVar13 = local_6b0;
  }
  plVar19 = (longlong *)(param_2 + 0x58);
  if ((longlong *)*plVar19 == plVar19) {
    if (cVar13 != '\0') {
      pcVar6 = *(code **)(param_2 + 0x100);
      uVar7 = *(undefined8 *)(param_2 + 0xd0);
      *(undefined8 *)(puVar27 + -8) = 0x140014f4a;
      uVar15 = (*pcVar6)(uVar7);
      pcVar28 = "Battery Absent";
      if (5 < DAT_14000c080) {
        local_538 = puVar27 + 0x70;
        *(undefined4 *)(puVar27 + 0x70) = *(undefined4 *)(param_1 + 0x2e4);
        local_528 = puVar27 + 0x48;
        iVar16 = *(int *)(param_2 + 0x44);
        local_518 = "Battery Absent";
        *(int *)(puVar27 + 0x48) = iVar16;
        if (iVar16 != 0) {
          local_518 = "-";
        }
        local_530 = 4;
        lVar21 = -1;
        local_520 = 4;
        do {
          lVar21 = lVar21 + 1;
        } while (local_518[lVar21] != '\0');
        local_510 = (int)lVar21 + 1;
        *(undefined4 *)(puVar27 + 0x44) = uVar15;
        local_508 = puVar27 + 0x44;
        *(undefined1 **)(puVar27 + 0x28) = local_558;
        *(undefined4 *)(puVar27 + 0x20) = 6;
        local_50c = 0;
        local_500 = 4;
        *(undefined8 *)(puVar27 + -8) = 0x140015011;
        _tlgWriteTransfer_EtwWriteTransfer
                  (local_518,&DAT_140008554,param_3,param_4,*(undefined4 *)(puVar27 + 0x20),
                   *(undefined8 **)(puVar27 + 0x28));
      }
      *(undefined8 *)(puVar27 + -8) = 0x14001501b;
      plVar19 = (longlong *)Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      if ((int)plVar19 != 0) {
        pcVar6 = *(code **)(param_2 + 0x138);
        plVar19 = (longlong *)0x0;
        if (pcVar6 != (code *)0x0) {
          uVar7 = *(undefined8 *)(param_2 + 0xd0);
          *(undefined8 *)(puVar27 + -8) = 0x14001503f;
          plVar19 = (longlong *)(*pcVar6)(uVar7);
          if ((int)plVar19 < 0) {
            if (5 < DAT_14000c080) {
              local_538 = puVar27 + 0x44;
              iVar16 = *(int *)(param_2 + 0x44);
              *(undefined4 *)(puVar27 + 0x44) = *(undefined4 *)(param_1 + 0x2e4);
              local_528 = puVar27 + 0x48;
              if (iVar16 != 0) {
                pcVar28 = "-";
              }
              local_530 = 4;
              *(int *)(puVar27 + 0x48) = iVar16;
              local_520 = 4;
              do {
                lVar30 = lVar30 + 1;
              } while (pcVar28[lVar30] != '\0');
              local_508 = puVar27 + 0x70;
              *(int *)(puVar27 + 0x70) = (int)plVar19;
              local_510 = (int)lVar30 + 1;
              *(undefined1 **)(puVar27 + 0x28) = local_558;
              *(undefined4 *)(puVar27 + 0x20) = 6;
              local_50c = 0;
              local_500 = 4;
              *(undefined8 *)(puVar27 + -8) = 0x1400150f4;
              local_518 = pcVar28;
              plVar19 = (longlong *)
                        _tlgWriteTransfer_EtwWriteTransfer
                                  (local_528,&DAT_14000887a,param_3,param_4,
                                   *(undefined4 *)(puVar27 + 0x20),*(undefined8 **)(puVar27 + 0x28))
              ;
            }
            *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) | 4;
          }
          else {
            *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) & 0xfffffffb;
          }
        }
      }
      *(undefined8 *)(param_2 + 0x90) = 0;
    }
    goto LAB_140015d45;
  }
  local_590 = *(uint *)(param_2 + 0x98) & 0xf;
  *(undefined8 *)(puVar27 + -8) = 0x140015124;
  uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  cVar13 = '\0';
  pcVar28 = "Battery Absent";
  if ((int)uVar17 != 0) {
    uVar15 = *(undefined4 *)(puVar27 + 0x34);
    local_584 = CONCAT71(local_584._1_7_,2);
    if (puVar27[0x30] != '\0') {
      uVar15 = 0;
    }
    *(undefined4 *)(puVar27 + 0x34) = uVar15;
    local_584 = CONCAT44(uVar15,(undefined4)local_584);
    pcVar6 = *(code **)(param_2 + 0x130);
    if (pcVar6 != (code *)0x0) {
      lVar21 = param_2 + 0x1e8;
      uVar15 = *(undefined4 *)(puVar27 + 0x38);
      uVar23 = *(undefined4 *)(puVar27 + 0x58);
      if (puVar27[0x31] != '\0') {
        uVar15 = 0;
      }
      cVar3 = puVar27[0x32];
      *(undefined4 *)(param_2 + 0x1ec) = uVar15;
      uVar7 = *(undefined8 *)(param_2 + 0xd0);
      if (cVar3 != '\0') {
        uVar23 = 0;
      }
      *(undefined4 *)(param_2 + 0x1f0) = uVar23;
      uVar15 = *(undefined4 *)(param_2 + 0x44);
      *(undefined8 *)(puVar27 + -8) = 0x1400151a7;
      iVar16 = (*pcVar6)(uVar7,uVar15);
      if (iVar16 < 0) {
        if (5 < DAT_14000c080) {
          local_698 = *(undefined4 *)(param_1 + 0x2e4);
          local_98 = &local_698;
          local_88 = &local_694;
          local_694 = *(int *)(param_2 + 0x44);
          local_78 = "Battery Absent";
          if (local_694 != 0) {
            local_78 = "-";
          }
          local_90 = 4;
          lVar18 = -1;
          local_80 = 4;
          do {
            lVar18 = lVar18 + 1;
          } while (local_78[lVar18] != '\0');
          local_70 = (int)lVar18 + 1;
          local_68 = &local_690;
          *(undefined1 **)(puVar27 + 0x28) = local_b8;
          *(undefined4 *)(puVar27 + 0x20) = 6;
          local_6c = 0;
          local_60 = 4;
          *(undefined8 *)(puVar27 + -8) = 0x14001525e;
          local_690 = iVar16;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_78,&DAT_140009319,lVar21,param_4,*(undefined4 *)(puVar27 + 0x20),
                     *(undefined8 **)(puVar27 + 0x28));
        }
        *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) | 2;
      }
      else {
        *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) & 0xfffffffd;
      }
    }
  }
  pcVar6 = *(code **)(param_2 + 0xf8);
  puVar29 = &local_590;
  uVar7 = *(undefined8 *)(param_2 + 0xd0);
  *(undefined8 *)(puVar27 + -8) = 0x14001528b;
  iVar16 = (*pcVar6)(uVar7);
  *(int *)(puVar27 + 0x38) = iVar16;
  if (iVar16 < 0) {
    *(undefined8 *)(puVar27 + -8) = 0x1400152aa;
    BattCMiniportStatus(param_2,iVar16,puVar29,param_4);
    uVar17 = BatteryPollRate;
    if (*(uint *)(param_2 + 0x9c) == 0xffffffff) {
      if (*(uint *)(param_2 + 0xac) < 10) {
        *(uint *)(param_2 + 0xac) = *(uint *)(param_2 + 0xac) + 1;
        uVar17 = 10000000;
      }
    }
    else {
      iVar16 = *(int *)(param_2 + 0xa4);
      if ((iVar16 != 0) && (iVar16 != -0x80000000)) {
        uVar14 = local_588;
        if (iVar16 < 1) {
          uVar14 = local_58c;
        }
        lVar21 = (ulonglong)uVar14 - (ulonglong)*(uint *)(param_2 + 0x9c);
        puVar29 = (uint *)-(longlong)iVar16;
        if ((longlong)puVar29 < 0) {
          puVar29 = (uint *)(longlong)iVar16;
        }
        lVar18 = -lVar21;
        if (lVar18 < 0) {
          lVar18 = lVar21;
        }
        uVar20 = ((lVar18 * 36000000000) / (longlong)puVar29) / 2;
        if (((longlong)uVar20 <= (longlong)BatteryPollRate) &&
           (uVar17 = uVar20, (longlong)uVar20 < 200000000)) {
          uVar17 = 200000000;
        }
      }
    }
    if ((longlong)uVar17 < (longlong)uVar25) {
      uVar25 = uVar17;
    }
  }
  else {
    cVar13 = '\x01';
  }
  if (*(char *)(param_1 + 0x2ec) != cVar13) {
    puVar27[0x33] = 1;
    *(char *)(param_1 + 0x2ec) = cVar13;
  }
  if (cVar13 == '\0') {
    local_590 = local_590 & 0xffffff7f;
  }
  else {
    local_590 = local_590 | 0x80;
  }
  if ((uVar25 == 0) && (uVar25 = BatteryBackupPollRateDc, (*(byte *)(param_2 + 0x98) & 1) != 0)) {
    uVar25 = BatteryBackupPollRateAc;
  }
  *(undefined8 *)(puVar27 + -8) = 0x140015398;
  uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  uVar15 = *(undefined4 *)(puVar27 + 0x34);
  if ((int)uVar17 != 0) {
    uVar15 = local_584._4_4_;
  }
  *(undefined4 *)(puVar27 + 0x34) = uVar15;
  *(undefined8 *)(puVar27 + -8) = 0x1400153ae;
  uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar17 == 0) {
    if (5 < DAT_14000c080) {
      local_68c = *(undefined4 *)(param_1 + 0x2e4);
      local_1e8 = &local_688;
      local_1f8 = &local_68c;
      local_688 = *(int *)(param_2 + 0x44);
      pcVar22 = "Battery Absent";
      if (local_688 != 0) {
        pcVar22 = "-";
      }
      local_1f0 = 4;
      lVar21 = -1;
      local_1e0 = 4;
      do {
        lVar21 = lVar21 + 1;
      } while (pcVar22[lVar21] != '\0');
      local_1cc = 0;
      local_1d0 = (int)lVar21 + 1;
      pbVar24 = &DAT_140008c3e;
      local_684 = *(undefined4 *)(puVar27 + 0x38);
      local_1c8 = &local_684;
      local_680 = local_590;
      local_1b8 = &local_680;
      local_67c = local_58c;
      local_1a8 = &local_67c;
      local_678 = local_588;
      local_198 = &local_678;
      local_674 = *(undefined4 *)(param_2 + 0x9c);
      local_188 = &local_674;
      local_670 = *(undefined4 *)(param_2 + 0xa4);
      local_178 = &local_670;
      local_168 = &local_5e0;
      local_158 = puVar27 + 0x3c;
      puVar27[0x3d] = PlatformAoAc;
      local_148 = puVar27 + 0x3d;
      *(undefined1 **)(puVar27 + 0x28) = local_218;
      *(undefined4 *)(puVar27 + 0x20) = 0xe;
      local_1c0 = 4;
      local_1b0 = 4;
      local_1a0 = 4;
      local_190 = 4;
      local_180 = 4;
      local_170 = 4;
      local_160 = 8;
      puVar27[0x3c] = cVar13;
      local_150 = 1;
      local_140 = 1;
      local_5e0 = uVar25;
      local_1d8 = pcVar22;
      goto LAB_140015710;
    }
  }
  else if (5 < DAT_14000c080) {
    local_66c = *(undefined4 *)(param_1 + 0x2e4);
    local_3c8 = &local_668;
    local_3d8 = &local_66c;
    local_668 = *(int *)(param_2 + 0x44);
    pcVar22 = "Battery Absent";
    if (local_668 != 0) {
      pcVar22 = "-";
    }
    local_3d0 = 4;
    lVar21 = -1;
    local_3c0 = 4;
    do {
      lVar21 = lVar21 + 1;
    } while (pcVar22[lVar21] != '\0');
    local_3ac = 0;
    local_3b0 = (int)lVar21 + 1;
    pbVar24 = &DAT_140008b58;
    local_664 = *(undefined4 *)(puVar27 + 0x38);
    local_3a8 = &local_664;
    local_660 = local_590;
    local_398 = &local_660;
    local_65c = local_58c;
    local_388 = &local_65c;
    local_658 = local_588;
    local_378 = &local_658;
    local_654 = *(undefined4 *)(param_2 + 0x9c);
    local_368 = &local_654;
    local_650 = *(undefined4 *)(param_2 + 0xa4);
    local_358 = &local_650;
    local_348 = &local_5d8;
    local_338 = puVar27 + 0x3e;
    puVar27[0x3f] = PlatformAoAc;
    local_328 = puVar27 + 0x3f;
    local_64c = *(undefined4 *)(puVar27 + 0x34);
    local_318 = &local_64c;
    *(undefined1 **)(puVar27 + 0x28) = local_3f8;
    *(undefined4 *)(puVar27 + 0x20) = 0xf;
    local_3a0 = 4;
    local_390 = 4;
    local_380 = 4;
    local_370 = 4;
    local_360 = 4;
    local_350 = 4;
    local_340 = 8;
    puVar27[0x3e] = cVar13;
    local_330 = 1;
    local_320 = 1;
    local_310 = 4;
    local_5d8 = uVar25;
    local_3b8 = pcVar22;
LAB_140015710:
    param_4 = 1;
    *(undefined8 *)(puVar27 + -8) = 0x140015715;
    _tlgWriteTransfer_EtwWriteTransfer
              (pcVar22,pbVar24,puVar29,1,*(undefined4 *)(puVar27 + 0x20),
               *(undefined8 **)(puVar27 + 0x28));
  }
  if (puVar27[0x33] != '\0') {
    *(undefined8 *)(puVar27 + -8) = 0x140015726;
    uVar17 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    puVar29 = (uint *)0x0;
    if ((int)uVar17 == 0) {
      if (5 < DAT_14000c080) {
        if (((_DAT_14000c090 & 0x400000000000) == 0) ||
           ((DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        param_4 = 1;
        if (bVar11) {
          local_648 = *(undefined4 *)(param_1 + 0x2e4);
          local_2d8 = &local_644;
          local_2e8 = &local_648;
          local_644 = *(int *)(param_2 + 0x44);
          pcVar22 = "Battery Absent";
          if (local_644 != 0) {
            pcVar22 = "-";
          }
          local_2e0 = 4;
          lVar21 = -1;
          local_2d0 = 4;
          do {
            lVar21 = lVar21 + 1;
          } while (pcVar22[lVar21] != '\0');
          local_2c0 = (int)lVar21 + 1;
          pbVar24 = &DAT_14000a495;
          local_640 = *(undefined4 *)(puVar27 + 0x38);
          local_2b8 = &local_640;
          local_63c = local_590;
          local_2a8 = &local_63c;
          local_638 = local_58c;
          local_298 = &local_638;
          local_634 = local_588;
          local_288 = &local_634;
          local_630 = *(undefined4 *)(param_2 + 0x9c);
          local_278 = &local_630;
          local_62c = *(undefined4 *)(param_2 + 0xa4);
          local_268 = &local_62c;
          local_258 = &local_5d0;
          local_248 = puVar27 + 0x40;
          puVar27[0x41] = PlatformAoAc;
          local_238 = puVar27 + 0x41;
          local_228 = &local_5c8;
          *(undefined1 **)(puVar27 + 0x28) = local_308;
          *(undefined4 *)(puVar27 + 0x20) = 0xf;
          local_2bc = 0;
          local_2b0 = 4;
          local_2a0 = 4;
          local_290 = 4;
          local_280 = 4;
          local_270 = 4;
          local_260 = 4;
          local_250 = 8;
          puVar27[0x40] = cVar13;
          local_240 = 1;
          local_230 = 1;
          local_5c8 = 0x1000000;
          local_220 = 8;
          local_5d0 = uVar25;
          local_2c8 = pcVar22;
          goto LAB_140015b4f;
        }
      }
    }
    else if (5 < DAT_14000c080) {
      if (((_DAT_14000c090 & 0x400000000000) == 0) ||
         ((DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      param_4 = 1;
      if (bVar11) {
        local_628 = *(undefined4 *)(param_1 + 0x2e4);
        local_4c8 = &local_624;
        local_4d8 = &local_628;
        local_624 = *(int *)(param_2 + 0x44);
        pcVar22 = "Battery Absent";
        if (local_624 != 0) {
          pcVar22 = "-";
        }
        local_4d0 = 4;
        lVar21 = -1;
        local_4c0 = 4;
        do {
          lVar21 = lVar21 + 1;
        } while (pcVar22[lVar21] != '\0');
        local_4b0 = (int)lVar21 + 1;
        pbVar24 = &DAT_140009039;
        local_620 = *(undefined4 *)(puVar27 + 0x38);
        local_4a8 = &local_620;
        local_61c = local_590;
        local_498 = &local_61c;
        local_618 = local_58c;
        local_614 = local_588;
        local_478 = &local_614;
        local_610 = *(undefined4 *)(param_2 + 0x9c);
        local_468 = &local_610;
        local_60c = *(undefined4 *)(param_2 + 0xa4);
        local_458 = &local_60c;
        local_448 = &local_5c0;
        local_438 = puVar27 + 0x42;
        puVar27[0x43] = PlatformAoAc;
        local_428 = puVar27 + 0x43;
        local_608 = *(undefined4 *)(puVar27 + 0x34);
        local_418 = &local_608;
        local_408 = &local_5b8;
        *(undefined1 **)(puVar27 + 0x28) = local_4f8;
        *(undefined4 *)(puVar27 + 0x20) = 0x10;
        local_4ac = 0;
        local_4a0 = 4;
        local_490 = 4;
        local_480 = 4;
        local_470 = 4;
        local_460 = 4;
        local_450 = 4;
        local_440 = 8;
        puVar27[0x42] = cVar13;
        local_430 = 1;
        local_420 = 1;
        local_410 = 4;
        local_5b8 = 0x1000000;
        local_400 = 8;
        local_5c0 = uVar25;
        local_4b8 = pcVar22;
        local_488 = &local_618;
LAB_140015b4f:
        param_4 = 1;
        *(undefined8 *)(puVar27 + -8) = 0x140015b54;
        _tlgWriteTransfer_EtwWriteTransfer
                  (pcVar22,pbVar24,0,1,*(undefined4 *)(puVar27 + 0x20),
                   *(undefined8 **)(puVar27 + 0x28));
      }
    }
  }
  LOCK();
  *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
  UNLOCK();
  *(undefined8 *)(puVar27 + -8) = 0x140015b6a;
  Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if (*(char *)(param_1 + 0x178) == '\x01') {
    LOCK();
    piVar4 = (int *)(param_1 + 0x17c);
    iVar16 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar16 == 1) {
      puVar29 = (uint *)0x0;
      *(undefined8 *)(puVar27 + -8) = 0x140015b9b;
      KeSetEvent(param_1 + 0x180);
    }
    *(undefined8 *)(puVar27 + -8) = 0x140015ba5;
    plVar19 = (longlong *)Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if (DAT_14000c080 < 6) goto LAB_140015d45;
    *(undefined4 *)(puVar27 + 0x44) = *(undefined4 *)(param_1 + 0x2e4);
    iVar16 = *(int *)(param_2 + 0x44);
    *(int *)(puVar27 + 0x48) = iVar16;
    if (iVar16 != 0) {
      pcVar28 = "-";
    }
    do {
      lVar30 = lVar30 + 1;
    } while (pcVar28[lVar30] != '\0');
    local_508 = "Device is being removed";
    pbVar24 = &DAT_1400083ef;
    local_500 = 0x18;
  }
  else {
    param_4 = 1000;
    *(longlong *)(puVar27 + 0x20) = param_1 + 0x60;
    *(undefined8 *)(puVar27 + -8) = 0x140015c47;
    cVar13 = KeSetCoalescableTimer(param_1 + 0x20,-uVar25);
    if (cVar13 != '\0') {
      LOCK();
      piVar4 = (int *)(param_1 + 0x17c);
      iVar16 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar16 == 1) {
        *(undefined8 *)(puVar27 + -8) = 0x140015c74;
        KeSetEvent(param_1 + 0x180,0);
      }
      *(undefined8 *)(puVar27 + -8) = 0x140015c7e;
      Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    }
    puVar29 = (uint *)0x0;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar25;
    plVar19 = SUB168(ZEXT816(0xd6bf94d5e57a42bd) * auVar8,0);
    if (DAT_14000c080 < 6) goto LAB_140015d45;
    *(undefined4 *)(puVar27 + 0x44) = *(undefined4 *)(param_1 + 0x2e4);
    if (*(int *)(param_2 + 0x44) != 0) {
      pcVar28 = "-";
    }
    *(int *)(puVar27 + 0x48) = *(int *)(param_2 + 0x44);
    do {
      lVar30 = lVar30 + 1;
    } while (pcVar28[lVar30] != '\0');
    *(ulonglong *)(puVar27 + 0x70) = uVar25 / 10000000;
    local_508 = puVar27 + 0x70;
    pbVar24 = &DAT_140008480;
    local_500 = 8;
  }
  local_50c = 0;
  local_520 = 4;
  local_530 = 4;
  local_538 = puVar27 + 0x44;
  local_528 = puVar27 + 0x48;
  local_510 = (int)lVar30 + 1;
  *(undefined1 **)(puVar27 + 0x28) = local_558;
  *(undefined4 *)(puVar27 + 0x20) = 6;
  *(undefined8 *)(puVar27 + -8) = 0x140015d45;
  local_518 = pcVar28;
  plVar19 = (longlong *)
            _tlgWriteTransfer_EtwWriteTransfer
                      (local_528,pbVar24,puVar29,param_4,*(undefined4 *)(puVar27 + 0x20),
                       *(undefined8 **)(puVar27 + 0x28));
LAB_140015d45:
  *(undefined8 *)(puVar27 + -8) = 0x140015d54;
  return plVar19;
}



===== BattCCheckTagQueue @ 140015d7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattCCheckTagQueue(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  longlong lVar14;
  longlong *plVar15;
  undefined1 auStackY_198 [8];
  undefined1 auStackY_190 [24];
  uint local_168 [2];
  undefined8 local_160;
  undefined4 local_158;
  uint local_154;
  int local_150;
  undefined4 local_14c;
  uint local_148;
  undefined4 local_144;
  uint local_140;
  longlong *local_138 [2];
  undefined8 local_128 [4];
  undefined4 *local_108;
  undefined8 local_100;
  longlong **local_f8;
  undefined8 local_f0;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  uint *local_d8;
  undefined8 local_d0;
  undefined4 *local_c8;
  undefined8 local_c0;
  char *local_b8;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  undefined4 *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  local_160 = 0;
  local_168[0] = 0;
  local_140 = KeQueryTimeIncrement();
  puVar12 = auStackY_198;
  LOCK();
  iVar8 = *(int *)(param_1 + 0x130);
  *(int *)(param_1 + 0x130) = 0;
  UNLOCK();
  puVar13 = auStackY_198;
  if (iVar8 != 0) {
    plVar1 = (longlong *)(param_2 + 0x68);
    do {
      uVar10 = (ulonglong)local_140;
      lVar11 = 0;
      puVar13 = auStackY_198;
      if ((longlong *)*plVar1 == plVar1) goto LAB_1400162e1;
      LOCK();
      iVar8 = *(int *)(param_1 + 0x138);
      *(int *)(param_1 + 0x138) = 0;
      UNLOCK();
      lVar14 = _DAT_fffff78000000320 * uVar10;
      if (((iVar8 != 0) || (*(longlong *)(param_2 + 0x88) == 0)) ||
         (10000000 < (ulonglong)(lVar14 - *(longlong *)(param_2 + 0x88)))) {
        local_168[0] = 0;
        iVar8 = (**(code **)(param_2 + 0xd8))(*(undefined8 *)(param_2 + 0xd0),local_168);
        if (5 < DAT_14000c080) {
          local_158 = *(undefined4 *)(param_1 + 0x2e4);
          local_88 = &local_158;
          local_68 = "Battery Absent";
          local_78 = &local_154;
          local_80 = 4;
          if (local_168[0] != 0) {
            local_68 = "-";
          }
          local_154 = local_168[0];
          lVar9 = -1;
          local_70 = 4;
          do {
            lVar9 = lVar9 + 1;
          } while (local_68[lVar9] != '\0');
          local_60 = (int)lVar9 + 1;
          local_58 = &local_150;
          local_5c = 0;
          local_50 = 4;
          local_150 = iVar8;
          _tlgWriteTransfer_EtwWriteTransfer
                    ((ulonglong)local_168[0],&DAT_14000892b,0,param_4,6,local_a8);
        }
        if (((iVar8 + 0x80000000U & 0x80000000) == 0) && (iVar8 != -0x3ffffff2)) {
          BattCMiniportStatus(param_2,iVar8,0x80000000,param_4);
          puVar13 = auStackY_198;
          goto LAB_1400162e1;
        }
        if (iVar8 == -0x3ffffff2) {
          lVar14 = _DAT_fffff78000000320 * uVar10;
          *(longlong *)(param_2 + 0x88) = lVar14;
        }
        else {
          *(undefined8 *)(param_2 + 0x88) = 0;
        }
      }
      plVar4 = (longlong *)*plVar1;
      while( true ) {
        plVar15 = plVar4;
        uVar10 = 0;
        if (plVar15 == plVar1) break;
        plVar3 = plVar15 + -0x15;
        lVar9 = plVar15[2];
        if (*(int *)(lVar9 + 0x10) == 0) {
          param_4 = uVar10;
        }
        else {
          param_4 = (ulonglong)*(uint *)plVar15[-0x12];
        }
        plVar4 = (longlong *)*plVar15;
        if (*(char *)((longlong)plVar15 + -100) != '\0') {
          *(undefined4 *)(plVar15 + -0xf) = 0xc0000120;
        }
        if ((int)plVar15[-0xf] != 0x103) goto LAB_14001604d;
        if (local_168[0] == 0) {
          if ((((int)param_4 != 0) && (*(longlong *)(lVar9 + -0x40) == 0)) &&
             (*(longlong *)(lVar9 + -0x38) == 0)) {
            uVar10 = param_4 * 10000 + lVar14;
            *(ulonglong *)(lVar9 + -0x40) = uVar10 & 0xffffffff;
            *(longlong *)(lVar9 + -0x38) = (longlong)(int)(uVar10 >> 0x20);
          }
          local_160 = CONCAT44(*(undefined4 *)(lVar9 + -0x38),*(undefined4 *)(lVar9 + -0x40));
          local_160 = local_160 - lVar14;
          if (local_160 < 1) {
            uVar10 = 0xc000000e;
            goto LAB_140016006;
          }
          if (((int)param_4 != -1) && ((lVar11 == 0 || (local_160 < lVar11)))) {
            lVar11 = local_160;
          }
        }
        else {
LAB_140016006:
          *(int *)(plVar15 + -0xf) = (int)uVar10;
          *(uint *)plVar15[-0x12] = local_168[0];
          plVar15[-0xe] = 4;
          if (*(uint *)(param_2 + 0x44) != local_168[0]) {
            *(uint *)(param_2 + 0x44) = local_168[0];
          }
        }
        if ((int)plVar15[-0xf] != 0x103) {
LAB_14001604d:
          lVar9 = *plVar15;
          if ((*(longlong **)(lVar9 + 8) != plVar15) ||
             (plVar5 = (longlong *)plVar15[1], (longlong *)*plVar5 != plVar15)) {
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(3);
            puVar12 = auStackY_190;
            goto LAB_14001626b;
          }
          *plVar5 = lVar9;
          *(longlong **)(lVar9 + 8) = plVar5;
          BattCClearCancelRoutine((longlong)plVar3);
          if (((int)*(char *)((longlong)plVar15 + -0x65) <= *(char *)((longlong)plVar15 + -0x66) + 1
              ) && (5 < DAT_14000c080)) {
            local_14c = *(undefined4 *)(param_1 + 0x2e4);
            local_108 = &local_14c;
            local_f8 = local_138;
            local_100 = 4;
            local_f0 = 8;
            iVar8 = *(int *)(plVar15[2] + 0x18);
            if (iVar8 == 0x294040) {
              local_e8 = "IOCTL_BATTERY_QUERY_TAG";
            }
            else if (iVar8 == 0x294044) {
              local_e8 = "IOCTL_BATTERY_QUERY_INFORMATION";
            }
            else if (iVar8 == 0x298048) {
              local_e8 = "IOCTL_BATTERY_SET_INFORMATION";
            }
            else if (iVar8 == 0x29404c) {
              local_e8 = "IOCTL_BATTERY_QUERY_STATUS";
            }
            else if (iVar8 == 0x294050) {
              local_e8 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
            }
            else if (iVar8 == 0x294064) {
              local_e8 = "IOCTL_BATTERY_QUERY_STATUS_EX";
            }
            else if (iVar8 == 0x45400c) {
              local_e8 = "IOCTL_PMI_GET_MEASUREMENT";
            }
            else if (iVar8 == 0x454000) {
              local_e8 = "IOCTL_PMI_GET_CAPABILITIES";
            }
            else if (iVar8 == 0x454004) {
              local_e8 = "IOCTL_PMI_GET_CONFIGURATION";
            }
            else if (iVar8 == 0x458008) {
              local_e8 = "IOCTL_PMI_SET_CONFIGURATION";
            }
            else {
              local_e8 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
              if (iVar8 != 0x45c010) {
                local_e8 = "<invalid>";
              }
            }
            lVar9 = -1;
            do {
              lVar9 = lVar9 + 1;
            } while (local_e8[lVar9] != '\0');
            local_e0 = (int)lVar9 + 1;
            local_dc = 0;
            local_148 = *(uint *)(plVar15[2] + 0x18);
            local_d8 = &local_148;
            local_144 = (undefined4)plVar15[-0xf];
            local_c8 = &local_144;
            local_b8 = "BattCCheckTagQueue";
            local_d0 = 4;
            local_c0 = 4;
            local_b0 = 0x13;
            local_138[0] = plVar3;
            _tlgWriteTransfer_EtwWriteTransfer
                      ((ulonglong)local_148,&DAT_1400088d4,0,param_4,8,local_128);
          }
          IofCompleteRequest(plVar3,0);
        }
      }
      LOCK();
      iVar8 = *(int *)(param_1 + 0x130);
      *(int *)(param_1 + 0x130) = 0;
      UNLOCK();
    } while (iVar8 != 0);
LAB_14001626b:
    puVar13 = puVar12;
    if (lVar11 != 0) {
      LOCK();
      *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
      UNLOCK();
      if (*(char *)(param_1 + 0x178) == '\x01') {
        LOCK();
        piVar2 = (int *)(param_1 + 0x17c);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      else {
        *(undefined8 *)(puVar12 + -8) = 0x1400162b0;
        cVar7 = KeSetTimer(param_1 + 0xa0,-lVar11,param_1 + 0xe0);
        if (cVar7 == '\0') goto LAB_1400162e1;
        LOCK();
        piVar2 = (int *)(param_1 + 0x17c);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar8 == 1) {
        *(undefined8 *)(puVar12 + -8) = 0x1400162dc;
        KeSetEvent(param_1 + 0x180,0,0);
      }
    }
  }
LAB_1400162e1:
  *(undefined8 *)(puVar13 + -8) = 0x1400162ed;
  return;
}



===== BattCIoctl @ 140016310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCIoctl(longlong param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  byte *pbVar6;
  uint *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 auStackY_118 [32];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  uint local_cc;
  longlong local_c8 [2];
  undefined8 local_b8 [4];
  undefined4 *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  char *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_cc = param_3[2];
  uVar9 = (ulonglong)local_cc;
  uVar1 = param_3[6];
  puVar7 = *(uint **)(param_2 + 0x18);
  uVar2 = 0xc0000206;
  if (uVar1 != 0x294040) {
    if (uVar1 == 0x294044) {
      if (param_3[4] == 0xc) {
        param_3 = (uint *)(ulonglong)puVar7[1];
        uVar9 = (ulonglong)puVar7[2];
        uVar2 = BattCQueryInformation(param_1,(ulonglong)*puVar7,puVar7[1],uVar9,puVar7);
      }
    }
    else if ((uVar1 != 0x29404c) && (uVar1 != 0x294064)) {
      if (uVar1 == 0x298048) {
        if (local_cc == 0) {
          uVar2 = BattCIoctlBatterySetInformation(param_1,param_3[4],puVar7,0);
          param_3 = puVar7;
        }
      }
      else {
        uVar2 = 0xc0000002;
      }
    }
  }
  BattCMiniportStatus(param_1,uVar2,param_3,uVar9);
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_cc;
  *(uint *)(param_2 + 0x30) = uVar2;
  BattCClearCancelRoutine(param_2);
  uVar3 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if ((int)*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42) + 1) {
    if ((int)uVar3 == 0) {
      if (DAT_14000c080 < 6) goto LAB_1400166d3;
      lVar8 = *(longlong *)(param_2 + 0xb8);
      local_d0 = *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
      local_98 = &local_d0;
      iVar4 = *(int *)(lVar8 + 0x18);
      if (iVar4 == 0x294040) {
        local_78 = "IOCTL_BATTERY_QUERY_TAG";
      }
      else if (iVar4 == 0x294044) {
        local_78 = "IOCTL_BATTERY_QUERY_INFORMATION";
      }
      else if (iVar4 == 0x298048) {
        local_78 = "IOCTL_BATTERY_SET_INFORMATION";
      }
      else if (iVar4 == 0x29404c) {
        local_78 = "IOCTL_BATTERY_QUERY_STATUS";
      }
      else if (iVar4 == 0x294050) {
        local_78 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
      }
      else if (iVar4 == 0x294064) {
        local_78 = "IOCTL_BATTERY_QUERY_STATUS_EX";
      }
      else if (iVar4 == 0x45400c) {
        local_78 = "IOCTL_PMI_GET_MEASUREMENT";
      }
      else if (iVar4 == 0x454000) {
        local_78 = "IOCTL_PMI_GET_CAPABILITIES";
      }
      else if (iVar4 == 0x454004) {
        local_78 = "IOCTL_PMI_GET_CONFIGURATION";
      }
      else if (iVar4 == 0x458008) {
        local_78 = "IOCTL_PMI_SET_CONFIGURATION";
      }
      else {
        local_78 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
        if (iVar4 != 0x45c010) {
          local_78 = "<invalid>";
        }
      }
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_78[lVar5] != '\0');
      pbVar6 = &DAT_140009168;
      iVar4 = (int)lVar5;
      local_d4 = *(undefined4 *)(lVar8 + 0x18);
      local_d8 = *(undefined4 *)(param_2 + 0x30);
      local_58 = &local_d8;
    }
    else {
      if (DAT_14000c080 < 6) goto LAB_1400166d3;
      lVar8 = *(longlong *)(param_2 + 0xb8);
      local_d8 = *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
      local_98 = &local_d8;
      iVar4 = *(int *)(lVar8 + 0x18);
      if (iVar4 == 0x294040) {
        local_78 = "IOCTL_BATTERY_QUERY_TAG";
      }
      else if (iVar4 == 0x294044) {
        local_78 = "IOCTL_BATTERY_QUERY_INFORMATION";
      }
      else if (iVar4 == 0x298048) {
        local_78 = "IOCTL_BATTERY_SET_INFORMATION";
      }
      else if (iVar4 == 0x29404c) {
        local_78 = "IOCTL_BATTERY_QUERY_STATUS";
      }
      else if (iVar4 == 0x294050) {
        local_78 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
      }
      else if (iVar4 == 0x294064) {
        local_78 = "IOCTL_BATTERY_QUERY_STATUS_EX";
      }
      else if (iVar4 == 0x45400c) {
        local_78 = "IOCTL_PMI_GET_MEASUREMENT";
      }
      else if (iVar4 == 0x454000) {
        local_78 = "IOCTL_PMI_GET_CAPABILITIES";
      }
      else if (iVar4 == 0x454004) {
        local_78 = "IOCTL_PMI_GET_CONFIGURATION";
      }
      else if (iVar4 == 0x458008) {
        local_78 = "IOCTL_PMI_SET_CONFIGURATION";
      }
      else {
        local_78 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
        if (iVar4 != 0x45c010) {
          local_78 = "<invalid>";
        }
      }
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_78[lVar5] != '\0');
      pbVar6 = &DAT_14000936f;
      iVar4 = (int)lVar5;
      local_d4 = *(undefined4 *)(lVar8 + 0x18);
      local_d0 = *(undefined4 *)(param_2 + 0x30);
      local_58 = &local_d0;
    }
    local_70 = iVar4 + 1;
    local_68 = &local_d4;
    local_6c = 0;
    local_80 = 8;
    local_88 = local_c8;
    local_90 = 4;
    local_48 = "BattCIoctl";
    local_60 = 4;
    local_50 = 4;
    local_40 = 0xb;
    local_c8[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer((ulonglong)local_70,pbVar6,lVar8,uVar9,8,local_b8);
  }
LAB_1400166d3:
  IofCompleteRequest(param_2,0);
  return;
}



===== BattCIoctlBatterySetInformation @ 140016710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BattCIoctlBatterySetInformation(longlong param_1,uint param_2,uint *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  undefined1 auStackY_138 [32];
  undefined4 local_f4;
  int local_f0;
  uint local_ec;
  uint local_e8 [12];
  undefined8 local_b8 [4];
  undefined4 *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e8[8] = 0;
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_e8[6] = 0;
  local_e8[7] = 0;
  pcVar7 = (char *)param_3;
  Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  lVar3 = *(longlong *)(param_1 + 0xb8);
  puVar6 = (uint *)0x0;
  if (param_2 < 8) {
LAB_140016771:
    uVar5 = 0xc0000206;
    param_3 = puVar6;
  }
  else {
    uVar2 = param_3[1];
    uVar5 = 0;
    puVar6 = param_3;
    if (uVar2 == 0) {
      iVar1 = 4;
LAB_140016843:
      if (param_2 < iVar1 + 8U) goto LAB_140016771;
LAB_14001684f:
      if ((int)uVar5 < 0) goto LAB_14001687a;
    }
    else if ((uVar2 != 1) && (uVar2 != 2)) {
      if (uVar2 != 3) {
        if (uVar2 == 4) {
          iVar1 = 0x10;
        }
        else {
          if (uVar2 != 5) {
            uVar5 = 0xc000000d;
            goto LAB_14001687a;
          }
          if (param_2 < 0x10) goto LAB_140016771;
          uVar5 = -(uint)(param_3[2] != 2) & 0xc000000d;
          iVar1 = 0x38;
          if (param_3[2] != 2) {
            iVar1 = 0;
          }
        }
        goto LAB_140016843;
      }
      if (*(int *)(param_1 + 0xa8) != -1) {
LAB_140016828:
        iVar1 = (-(uint)((*(uint *)(param_1 + 0xa8) & 4) != 0) & 4) + 4;
        goto LAB_140016843;
      }
      param_4 = 0;
      pcVar7 = (char *)0x0;
      uVar5 = BattCQueryInformation(param_1,(ulonglong)*param_3,0,0,local_e8);
      if (-1 < (int)uVar5) goto LAB_140016828;
      goto LAB_14001684f;
    }
    if (*(longlong *)(param_1 + 0xe8) != 0) {
      uVar2 = BattCSetInformation(param_1,(ulonglong)*param_3,param_3[1],param_3 + 2);
      return uVar2;
    }
    uVar5 = 0xc00000bb;
  }
LAB_14001687a:
  if (5 < DAT_14000c080) {
    local_f4 = *(undefined4 *)(lVar3 + 0x2e4);
    local_88 = &local_f0;
    local_98 = &local_f4;
    local_78 = "Battery Absent";
    local_f0 = *(int *)(param_1 + 0x44);
    if (local_f0 != 0) {
      local_78 = "-";
    }
    local_90 = 4;
    lVar4 = -1;
    local_80 = 4;
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_78[lVar3] != '\0');
    local_70 = (int)lVar3 + 1;
    local_6c = 0;
    if ((param_3 == (uint *)0x0) || (param_3[1] == 0)) {
      local_68 = "BatteryCriticalBias";
    }
    else if (param_3[1] == 1) {
      local_68 = "BatteryCharge";
    }
    else if (param_3[1] == 2) {
      local_68 = "BatteryDischarge";
    }
    else if (param_3[1] == 3) {
      local_68 = "BatteryChargingSource";
    }
    else if (param_3[1] == 4) {
      local_68 = "BatteryChargerId";
    }
    else {
      pcVar7 = "<invalid>";
      local_68 = "BatteryChargerStatus";
      if (param_3[1] != 5) {
        local_68 = "<invalid>";
      }
    }
    do {
      lVar4 = lVar4 + 1;
    } while (local_68[lVar4] != '\0');
    local_60 = (int)lVar4 + 1;
    local_58 = &local_ec;
    local_5c = 0;
    local_50 = 4;
    local_ec = uVar5;
    _tlgWriteTransfer_EtwWriteTransfer(local_68,&DAT_14000a56e,pcVar7,param_4,7,local_b8);
  }
  return uVar5;
}



===== BattCQueryInformation @ 1400169cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BattCQueryInformation
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,uint *param_5)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ulonglong uVar5;
  char *pcVar6;
  byte *pbVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_428 [32];
  undefined1 local_3e8 [4];
  uint local_3e4;
  int local_3e0;
  uint local_3dc;
  uint local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3cc;
  uint local_3c8;
  uint local_3c4;
  uint local_3c0;
  uint local_3bc;
  uint local_3b8;
  uint local_3b4;
  int local_3b0;
  uint local_3ac;
  uint local_3a8;
  undefined8 local_398 [4];
  uint *local_378;
  undefined8 local_370;
  int *local_368;
  undefined8 local_360;
  char *local_358;
  int local_350;
  undefined4 local_34c;
  uint *local_348;
  undefined8 local_340;
  undefined8 local_338;
  uint local_330 [2];
  uint *local_328;
  undefined8 local_320;
  undefined8 local_318;
  uint local_310 [2];
  uint *local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  uint local_2f0 [2];
  char *local_2e8;
  int local_2e0;
  undefined4 local_2dc;
  char *local_2d8;
  int local_2d0;
  undefined4 local_2cc;
  char *local_2c8;
  int local_2c0;
  undefined4 local_2bc;
  char *local_2b8;
  int local_2b0;
  undefined4 local_2ac;
  char *local_2a8;
  int local_2a0;
  undefined4 local_29c;
  char *local_298;
  int local_290;
  undefined4 local_28c;
  char *local_288;
  int local_280;
  undefined4 local_27c;
  char *local_278;
  int local_270;
  undefined4 local_26c;
  char *local_268;
  int local_260;
  undefined4 local_25c;
  undefined1 *local_258;
  undefined8 local_250;
  longlong local_248;
  undefined8 local_240;
  uint *local_238;
  undefined8 local_230;
  uint *local_228;
  undefined8 local_220;
  uint *local_218;
  undefined8 local_210;
  uint *local_208;
  undefined8 local_200;
  uint *local_1f8;
  undefined8 local_1f0;
  uint *local_1e8;
  undefined8 local_1e0;
  uint *local_1d8;
  undefined8 local_1d0;
  char *local_1c8;
  int local_1c0;
  undefined4 local_1bc;
  char *local_1b8;
  int local_1b0;
  undefined4 local_1ac;
  char *local_1a8;
  int local_1a0;
  undefined4 local_19c;
  char *local_198;
  int local_190;
  undefined4 local_18c;
  char *local_188;
  int local_180;
  undefined4 local_17c;
  char *local_178;
  int local_170;
  undefined4 local_16c;
  char *local_168;
  int local_160;
  undefined4 local_15c;
  char *local_158;
  int local_150;
  undefined4 local_14c;
  uint *local_148;
  undefined8 local_140;
  uint *local_138;
  undefined8 local_130;
  uint *local_128;
  undefined8 local_120;
  uint *local_118;
  undefined8 local_110;
  uint *local_108;
  undefined8 local_100;
  int *local_f8;
  undefined8 local_f0;
  uint *local_e8;
  undefined8 local_e0;
  char *local_d8;
  uint local_d0;
  undefined4 local_cc;
  char *local_c8;
  uint local_c0;
  undefined4 local_bc;
  undefined8 local_b8 [4];
  uint *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  char *local_78;
  uint local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_428;
  uVar4 = (**(code **)(param_1 + 0xe0))(*(undefined8 *)(param_1 + 0xd0));
  local_3a8 = uVar4;
  if ((int)uVar4 < 0) {
    uVar5 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      if (DAT_14000c080 < 6) {
        return uVar4;
      }
      local_3dc = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
      local_98 = &local_3dc;
      local_78 = "Battery Absent";
      local_3e0 = *(int *)(param_1 + 0x44);
      if (local_3e0 != 0) {
        local_78 = "-";
      }
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (local_78[lVar8] != '\0');
      local_68 = &local_3e4;
      pbVar7 = &DAT_14000a43a;
      local_3e4 = uVar4;
    }
    else {
      if (DAT_14000c080 < 6) {
        return uVar4;
      }
      local_98 = &local_3e4;
      local_78 = "Battery Absent";
      local_3e0 = *(int *)(param_1 + 0x44);
      if (local_3e0 != 0) {
        local_78 = "-";
      }
      lVar8 = -1;
      do {
        lVar8 = lVar8 + 1;
      } while (local_78[lVar8] != '\0');
      local_68 = &local_3dc;
      pbVar7 = &DAT_14000a317;
      local_3e4 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
      local_3dc = uVar4;
    }
    local_80 = 4;
    local_88 = &local_3e0;
    local_90 = 4;
    local_70 = (int)lVar8 + 1;
    local_60 = 4;
    local_6c = 0;
    _tlgWriteTransfer_EtwWriteTransfer(local_78,pbVar7,(ulonglong)local_70,param_4,6,local_b8);
    return uVar4;
  }
  if (param_3 != 0) {
    return uVar4;
  }
  *(uint *)(param_1 + 0xa8) = *param_5;
  *(uint *)(param_1 + 0xb0) = param_5[4];
  uVar5 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 == 0) {
    if (DAT_14000c080 < 6) {
      return local_3a8;
    }
    local_3ac = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
    local_378 = &local_3ac;
    local_368 = &local_3b0;
    local_3b0 = *(int *)(param_1 + 0x44);
    local_358 = "Battery Absent";
    if (local_3b0 != 0) {
      local_358 = "-";
    }
    lVar9 = -1;
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_358[lVar8] != '\0');
    local_350 = (int)lVar8;
    local_c8 = "?";
    local_338 = *(undefined8 *)(param_1 + 0x148);
    uVar1 = *(ushort *)(param_1 + 0x140);
    local_318 = *(undefined8 *)(param_1 + 0x198);
    uVar2 = *(ushort *)(param_1 + 400);
    local_2f8 = *(undefined8 *)(param_1 + 0x158);
    uVar3 = *(ushort *)(param_1 + 0x150);
    uVar4 = *param_5;
    if (uVar4 == 0xffffffff) {
      local_2e8 = "?";
    }
    else {
      local_2e8 = "System Battery";
      if (-1 < (int)uVar4) {
        local_2e8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2e8[lVar8] != '\0');
    local_2e0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2d8 = "?";
    }
    else {
      local_2d8 = "Battery Capacity Relative";
      if ((uVar4 >> 0x1e & 1) == 0) {
        local_2d8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2d8[lVar8] != '\0');
    local_2d0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2c8 = "?";
    }
    else {
      local_2c8 = "Short Term Battery";
      if ((uVar4 >> 0x1d & 1) == 0) {
        local_2c8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2c8[lVar8] != '\0');
    local_2c0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2b8 = "?";
    }
    else {
      local_2b8 = "Battery Sealed";
      if ((uVar4 >> 0x1c & 1) == 0) {
        local_2b8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2b8[lVar8] != '\0');
    local_2b0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2a8 = "?";
    }
    else {
      local_2a8 = "Set Charge Supported";
      if ((uVar4 & 1) == 0) {
        local_2a8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2a8[lVar8] != '\0');
    local_2a0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_298 = "?";
    }
    else {
      local_298 = "Set Discharge Supported";
      if ((uVar4 & 2) == 0) {
        local_298 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_298[lVar8] != '\0');
    local_290 = (int)lVar8;
    local_278 = "Set Charging Source Supported";
    if (uVar4 == 0xffffffff) {
      local_288 = "?";
    }
    else {
      local_288 = "Set Charging Source Supported";
      if ((uVar4 & 4) == 0) {
        local_288 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_288[lVar8] != '\0');
    local_280 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_278 = "?";
    }
    else if ((uVar4 & 4) == 0) {
      local_278 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_278[lVar8] != '\0');
    local_270 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_268 = "?";
    }
    else {
      local_268 = "Set Charger ID Supported";
      if ((uVar4 & 8) == 0) {
        local_268 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_268[lVar8] != '\0');
    uVar4 = *(uint *)(param_1 + 0x98);
    local_260 = (int)lVar8;
    local_3e8[0] = (undefined1)param_5[1];
    local_3b4 = param_5[3];
    local_228 = &local_3b4;
    local_3b8 = param_5[4];
    local_218 = &local_3b8;
    local_3bc = param_5[5];
    local_208 = &local_3bc;
    local_3c0 = param_5[6];
    local_1f8 = &local_3c0;
    local_3c4 = param_5[7];
    local_1e8 = &local_3c4;
    local_3c8 = param_5[8];
    local_1c8 = "AC Power";
    if ((uVar4 & 1) == 0) {
      local_1c8 = "DC Power";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1c8[lVar8] != '\0');
    local_1c0 = (int)lVar8;
    local_1b8 = "Battery Discharging";
    if ((uVar4 & 2) == 0) {
      local_1b8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1b8[lVar8] != '\0');
    local_1b0 = (int)lVar8;
    local_1a8 = "Battery Charging";
    if ((uVar4 & 4) == 0) {
      local_1a8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1a8[lVar8] != '\0');
    local_1a0 = (int)lVar8;
    local_198 = "Battery Critical";
    if ((uVar4 & 8) == 0) {
      local_198 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_198[lVar8] != '\0');
    local_190 = (int)lVar8;
    local_188 = "Battery charge limiting mode";
    if ((uVar4 & 0x10) == 0) {
      local_188 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_188[lVar8] != '\0');
    local_180 = (int)lVar8;
    local_178 = "Battery charging state power supply present";
    if ((uVar4 & 0x20) == 0) {
      local_178 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_178[lVar8] != '\0');
    local_170 = (int)lVar8;
    local_168 = "Battery charging state adequate";
    if ((uVar4 & 0x40) == 0) {
      local_168 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_168[lVar8] != '\0');
    local_160 = (int)lVar8;
    local_158 = "Battery trip point supported";
    if ((uVar4 & 0x80) == 0) {
      local_158 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_158[lVar8] != '\0');
    local_3d8 = *(uint *)(param_1 + 0xb0);
    local_150 = (int)lVar8;
    local_3d4 = *(uint *)(param_1 + 0x9c);
    if (local_3d8 == 0) {
      local_3cc = 0;
      local_3d0 = 0;
    }
    else {
      local_3cc = ((local_3d8 >> 1) + local_3d4 * 100) / local_3d8;
      local_3d0 = (uint)(((ulonglong)local_3d4 * 100000) / (ulonglong)local_3d8);
    }
    local_148 = &local_3cc;
    local_3e4 = *(uint *)(param_1 + 0x1cc);
    local_128 = &local_3d4;
    local_118 = &local_3d8;
    local_3dc = *(uint *)(param_1 + 0xa0);
    local_108 = &local_3dc;
    local_3e0 = *(int *)(param_1 + 0xa4);
    local_f8 = &local_3e0;
    local_e8 = &local_3e4;
    local_138 = &local_3d0;
    if (local_3e4 == 0) {
      local_d8 = "?";
    }
    else {
      local_d8 = "Charge Limiting Mode";
      if ((*(uint *)(param_1 + 0x1d0) & 1) == 0) {
        local_d8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_d8[lVar8] != '\0');
    local_d0 = (int)lVar8 + 1;
    pcVar6 = (char *)(ulonglong)local_d0;
    if (1 < local_3e4) {
      uVar4 = *(uint *)(param_1 + 0x1d0) & 6;
      if (uVar4 == 0) {
        local_c8 = "BatteryNoPowerSupply";
      }
      else if (uVar4 == 2) {
        local_c8 = "BatteryInadequatePowerSupply";
      }
      else {
        pcVar6 = "<invalid>";
        local_c8 = "BatteryAdequatePowerSupply";
        if (uVar4 != 4) {
          local_c8 = "<invalid>";
        }
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (local_c8[lVar9] != '\0');
    pbVar7 = &DAT_14000952e;
  }
  else {
    if (DAT_14000c080 < 6) {
      return local_3a8;
    }
    local_3dc = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
    local_378 = &local_3dc;
    local_368 = &local_3e0;
    local_3e0 = *(int *)(param_1 + 0x44);
    local_358 = "Battery Absent";
    if (local_3e0 != 0) {
      local_358 = "-";
    }
    lVar9 = -1;
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_358[lVar8] != '\0');
    local_350 = (int)lVar8;
    local_c8 = "?";
    local_338 = *(undefined8 *)(param_1 + 0x148);
    uVar1 = *(ushort *)(param_1 + 0x140);
    local_318 = *(undefined8 *)(param_1 + 0x198);
    uVar2 = *(ushort *)(param_1 + 400);
    local_2f8 = *(undefined8 *)(param_1 + 0x158);
    uVar3 = *(ushort *)(param_1 + 0x150);
    uVar4 = *param_5;
    if (uVar4 == 0xffffffff) {
      local_2e8 = "?";
    }
    else {
      local_2e8 = "System Battery";
      if (-1 < (int)uVar4) {
        local_2e8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2e8[lVar8] != '\0');
    local_2e0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2d8 = "?";
    }
    else {
      local_2d8 = "Battery Capacity Relative";
      if ((uVar4 >> 0x1e & 1) == 0) {
        local_2d8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2d8[lVar8] != '\0');
    local_2d0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2c8 = "?";
    }
    else {
      local_2c8 = "Short Term Battery";
      if ((uVar4 >> 0x1d & 1) == 0) {
        local_2c8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2c8[lVar8] != '\0');
    local_2c0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2b8 = "?";
    }
    else {
      local_2b8 = "Battery Sealed";
      if ((uVar4 >> 0x1c & 1) == 0) {
        local_2b8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2b8[lVar8] != '\0');
    local_2b0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_2a8 = "?";
    }
    else {
      local_2a8 = "Set Charge Supported";
      if ((uVar4 & 1) == 0) {
        local_2a8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_2a8[lVar8] != '\0');
    local_2a0 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_298 = "?";
    }
    else {
      local_298 = "Set Discharge Supported";
      if ((uVar4 & 2) == 0) {
        local_298 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_298[lVar8] != '\0');
    local_290 = (int)lVar8;
    local_278 = "Set Charging Source Supported";
    if (uVar4 == 0xffffffff) {
      local_288 = "?";
    }
    else {
      local_288 = "Set Charging Source Supported";
      if ((uVar4 & 4) == 0) {
        local_288 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_288[lVar8] != '\0');
    local_280 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_278 = "?";
    }
    else if ((uVar4 & 4) == 0) {
      local_278 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_278[lVar8] != '\0');
    local_270 = (int)lVar8;
    if (uVar4 == 0xffffffff) {
      local_268 = "?";
    }
    else {
      local_268 = "Set Charger ID Supported";
      if ((uVar4 & 8) == 0) {
        local_268 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_268[lVar8] != '\0');
    uVar4 = *(uint *)(param_1 + 0x98);
    local_260 = (int)lVar8;
    local_3e8[0] = (undefined1)param_5[1];
    local_3e4 = param_5[3];
    local_228 = &local_3e4;
    local_3d8 = param_5[4];
    local_218 = &local_3d8;
    local_3d4 = param_5[5];
    local_208 = &local_3d4;
    local_3d0 = param_5[6];
    local_1f8 = &local_3d0;
    local_3cc = param_5[7];
    local_1e8 = &local_3cc;
    local_3c8 = param_5[8];
    local_1c8 = "AC Power";
    if ((uVar4 & 1) == 0) {
      local_1c8 = "DC Power";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1c8[lVar8] != '\0');
    local_1c0 = (int)lVar8;
    local_1b8 = "Battery Discharging";
    if ((uVar4 & 2) == 0) {
      local_1b8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1b8[lVar8] != '\0');
    local_1b0 = (int)lVar8;
    local_1a8 = "Battery Charging";
    if ((uVar4 & 4) == 0) {
      local_1a8 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_1a8[lVar8] != '\0');
    local_1a0 = (int)lVar8;
    local_198 = "Battery Critical";
    if ((uVar4 & 8) == 0) {
      local_198 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_198[lVar8] != '\0');
    local_190 = (int)lVar8;
    local_188 = "Battery charge limiting mode";
    if ((uVar4 & 0x10) == 0) {
      local_188 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_188[lVar8] != '\0');
    local_180 = (int)lVar8;
    local_178 = "Battery charging state power supply present";
    if ((uVar4 & 0x20) == 0) {
      local_178 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_178[lVar8] != '\0');
    local_170 = (int)lVar8;
    local_168 = "Battery charging state adequate";
    if ((uVar4 & 0x40) == 0) {
      local_168 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_168[lVar8] != '\0');
    local_160 = (int)lVar8;
    local_158 = "Battery trip point supported";
    if ((uVar4 & 0x80) == 0) {
      local_158 = "-";
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_158[lVar8] != '\0');
    local_3b8 = *(uint *)(param_1 + 0xb0);
    local_150 = (int)lVar8;
    local_3bc = *(uint *)(param_1 + 0x9c);
    if (local_3b8 == 0) {
      local_3c4 = 0;
      local_3c0 = 0;
    }
    else {
      local_3c4 = ((local_3b8 >> 1) + local_3bc * 100) / local_3b8;
      local_3c0 = (uint)(((ulonglong)local_3bc * 100000) / (ulonglong)local_3b8);
    }
    local_148 = &local_3c4;
    local_3ac = *(uint *)(param_1 + 0x1cc);
    local_128 = &local_3bc;
    local_118 = &local_3b8;
    local_3b4 = *(uint *)(param_1 + 0xa0);
    local_108 = &local_3b4;
    local_3b0 = *(int *)(param_1 + 0xa4);
    local_f8 = &local_3b0;
    local_e8 = &local_3ac;
    local_138 = &local_3c0;
    if (local_3ac == 0) {
      local_d8 = "?";
    }
    else {
      local_d8 = "Charge Limiting Mode";
      if ((*(uint *)(param_1 + 0x1d0) & 1) == 0) {
        local_d8 = "-";
      }
    }
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (local_d8[lVar8] != '\0');
    local_d0 = (int)lVar8 + 1;
    pcVar6 = (char *)(ulonglong)local_d0;
    if (1 < local_3ac) {
      uVar4 = *(uint *)(param_1 + 0x1d0) & 6;
      if (uVar4 == 0) {
        local_c8 = "BatteryNoPowerSupply";
      }
      else if (uVar4 == 2) {
        local_c8 = "BatteryInadequatePowerSupply";
      }
      else {
        pcVar6 = "<invalid>";
        local_c8 = "BatteryAdequatePowerSupply";
        if (uVar4 != 4) {
          local_c8 = "<invalid>";
        }
      }
    }
    do {
      lVar9 = lVar9 + 1;
    } while (local_c8[lVar9] != '\0');
    pbVar7 = &DAT_140009e4a;
  }
  local_150 = local_150 + 1;
  local_160 = local_160 + 1;
  local_170 = local_170 + 1;
  local_180 = local_180 + 1;
  local_190 = local_190 + 1;
  local_1a0 = local_1a0 + 1;
  local_1b0 = local_1b0 + 1;
  local_1c0 = local_1c0 + 1;
  local_260 = local_260 + 1;
  local_270 = local_270 + 1;
  local_280 = local_280 + 1;
  local_290 = local_290 + 1;
  local_2a0 = local_2a0 + 1;
  local_2b0 = local_2b0 + 1;
  local_2c0 = local_2c0 + 1;
  local_2d0 = local_2d0 + 1;
  local_2e0 = local_2e0 + 1;
  local_2f0[0] = (uint)uVar3;
  local_310[0] = (uint)uVar2;
  local_330[0] = (uint)uVar1;
  local_350 = local_350 + 1;
  local_cc = 0;
  local_e0 = 4;
  local_f0 = 4;
  local_100 = 4;
  local_110 = 4;
  local_120 = 4;
  local_130 = 4;
  local_140 = 4;
  local_14c = 0;
  local_15c = 0;
  local_16c = 0;
  local_17c = 0;
  local_18c = 0;
  local_19c = 0;
  local_1ac = 0;
  local_1bc = 0;
  local_1d0 = 4;
  local_1d8 = &local_3c8;
  local_1e0 = 4;
  local_1f0 = 4;
  local_200 = 4;
  local_210 = 4;
  local_220 = 4;
  local_230 = 4;
  local_238 = param_5 + 2;
  local_240 = 3;
  local_248 = (longlong)param_5 + 5;
  local_250 = 1;
  local_258 = local_3e8;
  local_25c = 0;
  local_26c = 0;
  local_27c = 0;
  local_28c = 0;
  local_29c = 0;
  local_2ac = 0;
  local_2bc = 0;
  local_2cc = 0;
  local_2dc = 0;
  local_2f0[1] = 0;
  local_300 = 2;
  local_308 = local_2f0;
  local_310[1] = 0;
  local_320 = 2;
  local_328 = local_310;
  local_330[1] = 0;
  local_340 = 2;
  local_348 = local_330;
  local_34c = 0;
  local_360 = 4;
  local_370 = 4;
  local_c0 = (int)lVar9 + 1;
  local_bc = 0;
  _tlgWriteTransfer_EtwWriteTransfer(pcVar6,pbVar7,(ulonglong)local_c0,local_c8,0x2e,local_398);
  return local_3a8;
}



===== BattCQueryStatus @ 140017a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BattCQueryStatus(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  bool bVar5;
  char cVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  char *pcVar10;
  uint uVar11;
  byte *pbVar12;
  longlong lVar13;
  longlong lVar14;
  byte bVar15;
  char *pcVar16;
  undefined1 auStackY_598 [32];
  undefined4 uVar17;
  int local_568;
  int local_564;
  int local_560;
  int local_55c;
  undefined4 local_558 [2];
  longlong local_550;
  uint local_548;
  undefined4 local_544;
  uint local_540;
  uint local_53c;
  undefined4 local_538;
  undefined4 local_534;
  uint local_530;
  undefined4 local_52c;
  int local_528;
  uint local_524;
  undefined4 local_520;
  uint local_51c;
  uint local_518;
  undefined4 local_514;
  undefined4 local_510;
  uint local_50c;
  undefined4 local_508;
  int local_504;
  uint local_500;
  undefined4 local_4fc;
  uint local_4f8;
  uint local_4f4;
  undefined4 local_4f0;
  undefined4 local_4ec;
  uint local_4e8;
  int local_4e4;
  undefined8 local_4e0;
  undefined8 local_4d8 [4];
  int *local_4b8;
  undefined8 local_4b0;
  int *local_4a8;
  undefined8 local_4a0;
  char *local_498;
  int local_490;
  undefined4 local_48c;
  int *local_488;
  undefined8 local_480;
  undefined8 local_478 [4];
  undefined4 *local_458;
  undefined8 local_450;
  int *local_448;
  undefined8 local_440;
  char *local_438;
  int local_430;
  undefined4 local_42c;
  char *local_428;
  int local_420;
  undefined4 local_41c;
  char *local_418;
  int local_410;
  undefined4 local_40c;
  char *local_408;
  int local_400;
  undefined4 local_3fc;
  char *local_3f8;
  int local_3f0;
  undefined4 local_3ec;
  char *local_3e8;
  int local_3e0;
  undefined4 local_3dc;
  char *local_3d8;
  int local_3d0;
  undefined4 local_3cc;
  char *local_3c8;
  int local_3c0;
  undefined4 local_3bc;
  char *local_3b8;
  int local_3b0;
  undefined4 local_3ac;
  uint *local_3a8;
  undefined8 local_3a0;
  undefined4 *local_398;
  undefined8 local_390;
  uint *local_388;
  undefined8 local_380;
  uint *local_378;
  undefined8 local_370;
  undefined4 *local_368;
  undefined8 local_360;
  undefined4 *local_358;
  undefined8 local_350;
  uint *local_348;
  undefined8 local_340;
  char *local_338;
  int local_330;
  undefined4 local_32c;
  char *local_328;
  int local_320;
  undefined4 local_31c;
  undefined8 local_318 [4];
  undefined4 *local_2f8;
  undefined8 local_2f0;
  int *local_2e8;
  undefined8 local_2e0;
  char *local_2d8;
  int local_2d0;
  undefined4 local_2cc;
  char *local_2c8;
  int local_2c0;
  undefined4 local_2bc;
  char *local_2b8;
  int local_2b0;
  undefined4 local_2ac;
  char *local_2a8;
  int local_2a0;
  undefined4 local_29c;
  char *local_298;
  int local_290;
  undefined4 local_28c;
  char *local_288;
  int local_280;
  undefined4 local_27c;
  char *local_278;
  int local_270;
  undefined4 local_26c;
  char *local_268;
  int local_260;
  undefined4 local_25c;
  char *local_258;
  int local_250;
  undefined4 local_24c;
  uint *local_248;
  undefined8 local_240;
  undefined4 *local_238;
  undefined8 local_230;
  uint *local_228;
  undefined8 local_220;
  uint *local_218;
  undefined8 local_210;
  undefined4 *local_208;
  undefined8 local_200;
  undefined4 *local_1f8;
  undefined8 local_1f0;
  uint *local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  int local_1d0;
  undefined4 local_1cc;
  char *local_1c8;
  int local_1c0;
  undefined4 local_1bc;
  undefined8 local_1b8 [4];
  undefined4 *local_198;
  undefined8 local_190;
  int *local_188;
  undefined8 local_180;
  char *local_178;
  int local_170;
  undefined4 local_16c;
  char *local_168;
  int local_160;
  undefined4 local_15c;
  char *local_158;
  int local_150;
  undefined4 local_14c;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  char *local_128;
  int local_120;
  undefined4 local_11c;
  char *local_118;
  int local_110;
  undefined4 local_10c;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  uint *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_598;
  local_558[0] = *(undefined4 *)(param_2 + 0x1b0);
  lVar13 = *(longlong *)(param_2 + 0x1b8);
  local_550 = param_1;
  local_568 = (**(code **)(param_2 + 0xf0))
                        (*(undefined8 *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 0x44));
  if (local_568 < 0) {
    if (DAT_14000c080 < 6) goto LAB_140017b32;
    local_564 = *(int *)(param_1 + 0x2e4);
    local_4b8 = &local_564;
    local_498 = "Battery Absent";
    local_4a8 = &local_560;
    local_560 = *(int *)(param_2 + 0x44);
    if (local_560 != 0) {
      local_498 = "-";
    }
    local_4b0 = 4;
    lVar13 = -1;
    local_4a0 = 4;
    do {
      lVar13 = lVar13 + 1;
    } while (local_498[lVar13] != '\0');
    local_488 = &local_55c;
    local_490 = (int)lVar13 + 1;
    local_48c = 0;
    local_480 = 4;
    local_55c = local_568;
    _tlgWriteTransfer_EtwWriteTransfer(&s__,&DAT_1400084fe,0,param_4,6,local_4d8);
  }
  else {
    *(uint *)(param_2 + 0x1b0) = *(uint *)(param_2 + 0x98);
    uVar7 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    lVar14 = -1;
    pcVar16 = "Battery Absent";
    if (((int)uVar7 != 0) && (*(code **)(param_2 + 0x128) != (code *)0x0)) {
      local_568 = (**(code **)(param_2 + 0x128))
                            (*(undefined8 *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 0x44));
      if (local_568 < 0) {
        if (5 < DAT_14000c080) {
          local_4a8 = &local_560;
          local_498 = "Battery Absent";
          local_4b0 = 4;
          local_4a0 = 4;
          local_55c = *(int *)(local_550 + 0x2e4);
          local_4b8 = &local_55c;
          local_560 = *(int *)(param_2 + 0x44);
          if (local_560 != 0) {
            local_498 = "-";
          }
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (local_498[lVar8] != '\0');
          local_490 = (int)lVar8 + 1;
          local_488 = &local_564;
          local_48c = 0;
          local_480 = 4;
          local_564 = local_568;
          _tlgWriteTransfer_EtwWriteTransfer(local_498,&DAT_1400092c0,0,param_4,6,local_4d8);
        }
        local_568 = 0;
        *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) | 1;
        *(undefined4 *)(param_2 + 0x1d8) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x1dc) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x1e0) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x1e4) = 0xffffffff;
      }
      else {
        *(uint *)(param_2 + 500) = *(uint *)(param_2 + 500) & 0xfffffffe;
      }
    }
    BattCUpdateBatteryPowerState(local_550,param_2);
    uVar7 = _DAT_fffff78000000008;
    uVar2 = *(uint *)(param_2 + 0x98);
    bVar15 = ((byte)uVar2 ^ (byte)local_558[0]) & 1;
    if (_DAT_fffff78000000008 < (ulonglong)(AcDcUpdateStormPingWindow + lVar13)) {
      if (bVar15 != 0) {
        iVar3 = *(int *)(param_2 + 0x1c8);
        iVar1 = iVar3 + 1;
        *(int *)(param_2 + 0x1c8) = iVar1;
        if (iVar1 == -1) {
          *(int *)(param_2 + 0x1c8) = iVar3;
        }
LAB_140017d18:
        *(ulonglong *)(param_2 + 0x1b8) = uVar7;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x1c8) = 1;
      if (bVar15 != 0) {
        *(ulonglong *)(param_2 + 0x1c0) = uVar7;
        goto LAB_140017d18;
      }
    }
    if ((AcDcUpdateStormQualificationCount != 0) &&
       (AcDcUpdateStormQualificationCount <= *(uint *)(param_2 + 0x1c8))) {
      *(uint *)(param_2 + 0x98) = uVar2 | 1;
      uVar7 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        if (5 < DAT_14000c080) {
          local_508 = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x2e4);
          local_2f8 = &local_508;
          local_504 = *(int *)(param_2 + 0x44);
          local_2e8 = &local_504;
          if (local_504 != 0) {
            pcVar16 = "-";
          }
          local_2f0 = 4;
          lVar13 = -1;
          local_2e0 = 4;
          do {
            lVar13 = lVar13 + 1;
          } while (pcVar16[lVar13] != '\0');
          uVar2 = *(uint *)(param_2 + 0x98);
          local_2d0 = (int)lVar13 + 1;
          local_2c8 = "AC Power";
          local_2cc = 0;
          if ((uVar2 & 1) == 0) {
            local_2c8 = "DC Power";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_2c8[lVar13] != '\0');
          local_2c0 = (int)lVar13 + 1;
          local_2b8 = "Battery Discharging";
          local_2bc = 0;
          if ((uVar2 & 2) == 0) {
            local_2b8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_2b8[lVar13] != '\0');
          local_2b0 = (int)lVar13 + 1;
          local_2a8 = "Battery Charging";
          local_2ac = 0;
          if ((uVar2 & 4) == 0) {
            local_2a8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_2a8[lVar13] != '\0');
          local_2a0 = (int)lVar13 + 1;
          local_298 = "Battery Critical";
          local_29c = 0;
          if ((uVar2 & 8) == 0) {
            local_298 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_298[lVar13] != '\0');
          local_290 = (int)lVar13 + 1;
          local_288 = "Battery charge limiting mode";
          local_28c = 0;
          if ((uVar2 & 0x10) == 0) {
            local_288 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_288[lVar13] != '\0');
          local_280 = (int)lVar13 + 1;
          local_278 = "Battery charging state power supply present";
          local_27c = 0;
          if ((uVar2 & 0x20) == 0) {
            local_278 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_278[lVar13] != '\0');
          local_270 = (int)lVar13 + 1;
          local_268 = "Battery charging state adequate";
          local_26c = 0;
          if ((uVar2 & 0x40) == 0) {
            local_268 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_268[lVar13] != '\0');
          local_260 = (int)lVar13 + 1;
          local_258 = "Battery trip point supported";
          local_25c = 0;
          if ((uVar2 & 0x80) == 0) {
            local_258 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_258[lVar13] != '\0');
          local_4f4 = *(uint *)(param_2 + 0xb0);
          uVar7 = (ulonglong)local_4f4;
          local_250 = (int)lVar13 + 1;
          local_4f8 = *(uint *)(param_2 + 0x9c);
          local_24c = 0;
          if (local_4f4 == 0) {
            local_500 = 0;
          }
          else {
            local_500 = (local_4f8 * 100 + (local_4f4 >> 1)) / local_4f4;
          }
          local_248 = &local_500;
          local_240 = 4;
          if (local_4f4 == 0) {
            local_4fc = 0;
          }
          else {
            local_4fc = (undefined4)(((ulonglong)local_4f8 * 100000) / uVar7);
          }
          uVar2 = *(uint *)(param_2 + 0x1cc);
          local_228 = &local_4f8;
          local_218 = &local_4f4;
          local_4f0 = *(undefined4 *)(param_2 + 0xa0);
          local_208 = &local_4f0;
          local_4ec = *(undefined4 *)(param_2 + 0xa4);
          local_1f8 = &local_4ec;
          local_238 = &local_4fc;
          local_1e8 = &local_4e8;
          pcVar10 = "?";
          local_230 = 4;
          local_220 = 4;
          local_210 = 4;
          local_200 = 4;
          local_1f0 = 4;
          local_1e0 = 4;
          if (uVar2 == 0) {
            local_1d8 = "?";
          }
          else {
            local_1d8 = "Charge Limiting Mode";
            if ((*(byte *)(param_2 + 0x1d0) & 1) == 0) {
              local_1d8 = "-";
            }
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_1d8[lVar13] != '\0');
          local_1d0 = (int)lVar13 + 1;
          local_1cc = 0;
          if (1 < uVar2) {
            uVar11 = *(uint *)(param_2 + 0x1d0) & 6;
            if (uVar11 == 0) {
              pcVar10 = "BatteryNoPowerSupply";
            }
            else if (uVar11 == 2) {
              pcVar10 = "BatteryInadequatePowerSupply";
            }
            else {
              pcVar10 = "BatteryAdequatePowerSupply";
              if (uVar11 != 4) {
                pcVar10 = "<invalid>";
              }
            }
          }
          do {
            lVar14 = lVar14 + 1;
          } while (pcVar10[lVar14] != '\0');
          local_1c0 = (int)lVar14 + 1;
          puVar9 = local_318;
          local_1bc = 0;
          pbVar12 = &DAT_140009ac3;
          local_4e8 = uVar2;
          local_2d8 = pcVar16;
          local_1c8 = pcVar10;
LAB_1400188a6:
          uVar17 = 0x16;
LAB_1400188b3:
          _tlgWriteTransfer_EtwWriteTransfer(pcVar10,pbVar12,(ulonglong)uVar2,uVar7,uVar17,puVar9);
        }
      }
      else if (BatteryIRTimerFired == '\0') {
        if (5 < DAT_14000c080) {
          local_52c = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x2e4);
          local_458 = &local_52c;
          local_528 = *(int *)(param_2 + 0x44);
          local_448 = &local_528;
          if (local_528 != 0) {
            pcVar16 = "-";
          }
          local_450 = 4;
          lVar13 = -1;
          local_440 = 4;
          do {
            lVar13 = lVar13 + 1;
          } while (pcVar16[lVar13] != '\0');
          uVar2 = *(uint *)(param_2 + 0x98);
          local_430 = (int)lVar13 + 1;
          local_428 = "AC Power";
          local_42c = 0;
          if ((uVar2 & 1) == 0) {
            local_428 = "DC Power";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_428[lVar13] != '\0');
          local_420 = (int)lVar13 + 1;
          local_418 = "Battery Discharging";
          local_41c = 0;
          if ((uVar2 & 2) == 0) {
            local_418 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_418[lVar13] != '\0');
          local_410 = (int)lVar13 + 1;
          local_408 = "Battery Charging";
          local_40c = 0;
          if ((uVar2 & 4) == 0) {
            local_408 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_408[lVar13] != '\0');
          local_400 = (int)lVar13 + 1;
          local_3f8 = "Battery Critical";
          local_3fc = 0;
          if ((uVar2 & 8) == 0) {
            local_3f8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_3f8[lVar13] != '\0');
          local_3f0 = (int)lVar13 + 1;
          local_3e8 = "Battery charge limiting mode";
          local_3ec = 0;
          if ((uVar2 & 0x10) == 0) {
            local_3e8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_3e8[lVar13] != '\0');
          local_3e0 = (int)lVar13 + 1;
          local_3d8 = "Battery charging state power supply present";
          local_3dc = 0;
          if ((uVar2 & 0x20) == 0) {
            local_3d8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_3d8[lVar13] != '\0');
          local_3d0 = (int)lVar13 + 1;
          local_3c8 = "Battery charging state adequate";
          local_3cc = 0;
          if ((uVar2 & 0x40) == 0) {
            local_3c8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_3c8[lVar13] != '\0');
          local_3c0 = (int)lVar13 + 1;
          local_3b8 = "Battery trip point supported";
          local_3bc = 0;
          if ((uVar2 & 0x80) == 0) {
            local_3b8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_3b8[lVar13] != '\0');
          local_518 = *(uint *)(param_2 + 0xb0);
          uVar7 = (ulonglong)local_518;
          local_3b0 = (int)lVar13 + 1;
          local_51c = *(uint *)(param_2 + 0x9c);
          local_3ac = 0;
          if (local_518 == 0) {
            local_524 = 0;
          }
          else {
            local_524 = (local_51c * 100 + (local_518 >> 1)) / local_518;
          }
          local_3a8 = &local_524;
          local_3a0 = 4;
          if (local_518 == 0) {
            local_520 = 0;
          }
          else {
            local_520 = (undefined4)(((ulonglong)local_51c * 100000) / uVar7);
          }
          uVar2 = *(uint *)(param_2 + 0x1cc);
          local_388 = &local_51c;
          local_378 = &local_518;
          local_514 = *(undefined4 *)(param_2 + 0xa0);
          local_368 = &local_514;
          local_510 = *(undefined4 *)(param_2 + 0xa4);
          local_358 = &local_510;
          local_398 = &local_520;
          local_348 = &local_50c;
          pcVar10 = "?";
          local_390 = 4;
          local_380 = 4;
          local_370 = 4;
          local_360 = 4;
          local_350 = 4;
          local_340 = 4;
          if (uVar2 == 0) {
            local_338 = "?";
          }
          else {
            local_338 = "Charge Limiting Mode";
            if ((*(byte *)(param_2 + 0x1d0) & 1) == 0) {
              local_338 = "-";
            }
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_338[lVar13] != '\0');
          local_330 = (int)lVar13 + 1;
          local_32c = 0;
          if (1 < uVar2) {
            uVar11 = *(uint *)(param_2 + 0x1d0) & 6;
            if (uVar11 == 0) {
              pcVar10 = "BatteryNoPowerSupply";
            }
            else if (uVar11 == 2) {
              pcVar10 = "BatteryInadequatePowerSupply";
            }
            else {
              pcVar10 = "BatteryAdequatePowerSupply";
              if (uVar11 != 4) {
                pcVar10 = "<invalid>";
              }
            }
          }
          do {
            lVar14 = lVar14 + 1;
          } while (pcVar10[lVar14] != '\0');
          local_320 = (int)lVar14 + 1;
          puVar9 = local_478;
          local_31c = 0;
          pbVar12 = &DAT_140008977;
          local_50c = uVar2;
          local_438 = pcVar16;
          local_328 = pcVar10;
          goto LAB_1400188a6;
        }
      }
      else if (5 < DAT_14000c080) {
        if (((_DAT_14000c090 & 0x400000000000) == 0) ||
           (bVar5 = true, (DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
          bVar5 = false;
        }
        if (bVar5) {
          local_558[0] = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x2e4);
          local_198 = local_558;
          local_4e4 = *(int *)(param_2 + 0x44);
          local_188 = &local_4e4;
          if (local_4e4 != 0) {
            pcVar16 = "-";
          }
          local_190 = 4;
          lVar13 = -1;
          local_180 = 4;
          do {
            lVar13 = lVar13 + 1;
          } while (pcVar16[lVar13] != '\0');
          uVar2 = *(uint *)(param_2 + 0x98);
          local_170 = (int)lVar13 + 1;
          local_168 = "AC Power";
          local_16c = 0;
          if ((uVar2 & 1) == 0) {
            local_168 = "DC Power";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_168[lVar13] != '\0');
          local_160 = (int)lVar13 + 1;
          local_158 = "Battery Discharging";
          local_15c = 0;
          if ((uVar2 & 2) == 0) {
            local_158 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_158[lVar13] != '\0');
          local_150 = (int)lVar13 + 1;
          local_148 = "Battery Charging";
          local_14c = 0;
          if ((uVar2 & 4) == 0) {
            local_148 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_148[lVar13] != '\0');
          local_140 = (int)lVar13 + 1;
          local_138 = "Battery Critical";
          local_13c = 0;
          if ((uVar2 & 8) == 0) {
            local_138 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_138[lVar13] != '\0');
          local_130 = (int)lVar13 + 1;
          local_128 = "Battery charge limiting mode";
          local_12c = 0;
          if ((uVar2 & 0x10) == 0) {
            local_128 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_128[lVar13] != '\0');
          local_120 = (int)lVar13 + 1;
          local_118 = "Battery charging state power supply present";
          local_11c = 0;
          if ((uVar2 & 0x20) == 0) {
            local_118 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_118[lVar13] != '\0');
          local_110 = (int)lVar13 + 1;
          local_108 = "Battery charging state adequate";
          local_10c = 0;
          if ((uVar2 & 0x40) == 0) {
            local_108 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_108[lVar13] != '\0');
          local_100 = (int)lVar13 + 1;
          local_f8 = "Battery trip point supported";
          local_fc = 0;
          if ((uVar2 & 0x80) == 0) {
            local_f8 = "-";
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_f8[lVar13] != '\0');
          local_53c = *(uint *)(param_2 + 0xb0);
          uVar7 = (ulonglong)local_53c;
          local_f0 = (int)lVar13 + 1;
          local_540 = *(uint *)(param_2 + 0x9c);
          local_ec = 0;
          if (local_53c == 0) {
            local_548 = 0;
          }
          else {
            local_548 = (local_540 * 100 + (local_53c >> 1)) / local_53c;
          }
          local_e8 = &local_548;
          local_e0 = 4;
          if (local_53c == 0) {
            local_544 = 0;
          }
          else {
            local_544 = (undefined4)(((ulonglong)local_540 * 100000) / uVar7);
          }
          uVar2 = *(uint *)(param_2 + 0x1cc);
          local_d8 = &local_544;
          local_c8 = &local_540;
          local_b8 = &local_53c;
          local_538 = *(undefined4 *)(param_2 + 0xa0);
          local_a8 = &local_538;
          local_534 = *(undefined4 *)(param_2 + 0xa4);
          local_98 = &local_534;
          local_88 = &local_530;
          pcVar10 = "?";
          local_d0 = 4;
          local_c0 = 4;
          local_b0 = 4;
          local_a0 = 4;
          local_90 = 4;
          local_80 = 4;
          if (uVar2 == 0) {
            local_78 = "?";
          }
          else {
            local_78 = "Charge Limiting Mode";
            if ((*(byte *)(param_2 + 0x1d0) & 1) == 0) {
              local_78 = "-";
            }
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (local_78[lVar13] != '\0');
          local_70 = (int)lVar13 + 1;
          local_6c = 0;
          if (1 < uVar2) {
            uVar11 = *(uint *)(param_2 + 0x1d0) & 6;
            if (uVar11 == 0) {
              pcVar10 = "BatteryNoPowerSupply";
            }
            else if (uVar11 == 2) {
              pcVar10 = "BatteryInadequatePowerSupply";
            }
            else {
              pcVar10 = "BatteryAdequatePowerSupply";
              if (uVar11 != 4) {
                pcVar10 = "<invalid>";
              }
            }
          }
          do {
            lVar14 = lVar14 + 1;
          } while (pcVar10[lVar14] != '\0');
          local_58 = &local_4e0;
          pbVar12 = &DAT_140008689;
          puVar9 = local_1b8;
          local_5c = 0;
          local_60 = (int)lVar14 + 1;
          uVar17 = 0x17;
          local_4e0 = 0x1000000;
          local_50 = 8;
          local_530 = uVar2;
          local_178 = pcVar16;
          local_68 = pcVar10;
          goto LAB_1400188b3;
        }
      }
      param_1 = local_550;
      if (bVar15 != 0) {
        if (*(char *)(local_550 + 0x178) != '\x01') {
          cVar6 = KeSetCoalescableTimer(local_550 + 0x260,-AcDcUpdateStormCancellationTime,0,1000);
          if (cVar6 == '\0') {
            Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
            LOCK();
            *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
            UNLOCK();
            Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          }
          uVar7 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline
                            ();
          if (((((int)uVar7 != 0) && (PlatformAoAc != '\0')) && (*(int *)(param_1 + 0x2f8) == 1)) &&
             ((*(uint *)(param_2 + 0x1b0) & 4) != 0)) {
            BattCConfigureIdleResiliencyPollTimer(param_1,0);
          }
        }
        goto LAB_140017b32;
      }
    }
  }
  param_1 = local_550;
LAB_140017b32:
  uVar7 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    uVar4 = *(undefined8 *)(param_2 + 0xa0);
    *(undefined8 *)(param_1 + 0x300) = *(undefined8 *)(param_2 + 0x98);
    *(undefined8 *)(param_1 + 0x308) = uVar4;
    *(undefined4 *)(param_1 + 0x310) = *(undefined4 *)(param_2 + 0xb0);
  }
  return local_568;
}



===== BattCSetAdapterStatus @ 140018964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BattCSetAdapterStatus
              (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_88;
  undefined1 local_87 [3];
  int local_84 [3];
  undefined8 local_78 [4];
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar2 = 0;
  if ((uint)param_3 < 4) {
    local_84[0] = -0x3fffffdd;
  }
  else {
    local_84[0] = (**(code **)(param_1 + 0x60))(*(undefined8 *)(param_1 + 0x10));
    if (-1 < local_84[0]) {
      uVar2 = (undefined2)*param_2;
      if ((char)((uint)*param_2 >> 8) == '\0') {
        uVar1 = *(uint *)(param_1 + 0x84) & 0xfffffffb;
      }
      else {
        uVar1 = *(uint *)(param_1 + 0x84) | 4;
      }
      *(uint *)(param_1 + 0x84) = uVar1;
    }
  }
  iVar3 = local_84[0];
  if (5 < DAT_14000c080) {
    local_4c = 0;
    local_58 = &local_88;
    local_3c = 0;
    local_2c = 0;
    local_87[0] = (undefined1)((ushort)uVar2 >> 8);
    local_48 = local_87;
    local_38 = local_84;
    local_88 = (undefined1)uVar2;
    local_50 = 1;
    local_40 = 1;
    local_30 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(1,&DAT_14000843b,param_3,param_4,5,local_78);
  }
  return iVar3;
}



===== BattCSetInformation @ 140018a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BattCSetInformation(longlong param_1,undefined8 param_2,int param_3,uint *param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  byte *pbVar7;
  longlong lVar8;
  undefined1 auStackY_168 [32];
  undefined4 uVar9;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128 [2];
  undefined8 local_120;
  undefined8 local_118 [4];
  uint *local_f8;
  ulonglong local_f0;
  uint *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  ulonglong local_d0;
  uint *local_c8;
  ulonglong local_c0;
  uint *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  undefined8 *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_168;
  uVar5 = *(ulonglong *)(param_1 + 0xd0);
  uVar2 = (**(code **)(param_1 + 0xe8))();
  Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  lVar8 = -1;
  if (5 < DAT_14000c080) {
    local_134 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x2e4);
    local_e8 = &local_130;
    local_f8 = &local_134;
    local_d8 = (uint *)0x140006400;
    local_130 = *(uint *)(param_1 + 0x44);
    lVar3 = -1;
    if (local_130 != 0) {
      local_d8 = (uint *)&s__;
    }
    local_f0 = 4;
    local_e0 = 4;
    do {
      lVar3 = lVar3 + 1;
    } while (*(char *)((longlong)local_d8 + lVar3) != '\0');
    local_d0 = (ulonglong)((int)lVar3 + 1);
    if (param_3 == 0) {
      local_c8 = (uint *)0x140006b90;
    }
    else if (param_3 == 1) {
      local_c8 = (uint *)0x140006ba8;
    }
    else if (param_3 == 2) {
      local_c8 = (uint *)0x140006bb8;
    }
    else if (param_3 == 3) {
      local_c8 = (uint *)0x140006bd0;
    }
    else if (param_3 == 4) {
      local_c8 = (uint *)0x140006be8;
    }
    else {
      local_c8 = (uint *)0x140006c00;
      if (param_3 != 5) {
        local_c8 = (uint *)0x140006588;
      }
    }
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (*(char *)((longlong)local_c8 + lVar3) != '\0');
    local_b8 = &local_12c;
    uVar4 = (int)lVar3 + 1;
    uVar5 = (ulonglong)uVar4;
    local_c0 = (ulonglong)uVar4;
    local_b0 = 4;
    local_12c = uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(uVar5,&DAT_140009cf7,1,3,7,local_118);
  }
  if (param_3 == 0) {
    if (DAT_14000c080 < 6) {
      return uVar2;
    }
    local_138 = *param_4;
    pbVar7 = &DAT_14000912f;
    local_f8 = &local_138;
    local_f0 = 4;
  }
  else {
    if (param_3 == 3) {
      if (DAT_14000c080 < 6) {
        return uVar2;
      }
      uVar4 = *param_4;
      uVar5 = (ulonglong)uVar4;
      if (uVar4 == 0) {
        local_f8 = (uint *)0x140006c18;
      }
      else if (uVar4 == 0xffffffff) {
        local_f8 = (uint *)0x140006c38;
      }
      else if (uVar4 == 1) {
        local_f8 = (uint *)0x140006c60;
      }
      else if (uVar4 == 2) {
        local_f8 = (uint *)0x140006c80;
      }
      else if (uVar4 == 3) {
        local_f8 = (uint *)0x140006ca0;
      }
      else {
        local_f8 = (uint *)0x140006cc8;
        if (uVar4 != 4) {
          local_f8 = (uint *)0x140006588;
        }
      }
      do {
        lVar8 = lVar8 + 1;
      } while (*(char *)((longlong)local_f8 + lVar8) != '\0');
      pbVar7 = &DAT_140009978;
      local_138 = param_4[1];
      local_e8 = &local_138;
      uVar9 = 4;
      local_f0 = (ulonglong)((int)lVar8 + 1);
      local_e0 = 4;
      goto LAB_140018f18;
    }
    if (param_3 == 4) {
      if (DAT_14000c080 < 6) {
        return uVar2;
      }
      pbVar7 = &DAT_1400084cf;
      local_f0 = 0x10;
      local_f8 = param_4;
    }
    else {
      if (param_3 != 5) {
        return uVar2;
      }
      uVar4 = *param_4;
      uVar5 = (ulonglong)uVar4;
      if (uVar4 == 2) {
        if (DAT_14000c080 < 6) {
          return uVar2;
        }
        lVar3 = -1;
        do {
          lVar6 = lVar3 + 1;
          lVar1 = lVar3 + 1;
          lVar3 = lVar6;
        } while ("BatteryChargingSourceType_USB"[lVar1] != '\0');
        local_f8 = (uint *)0x140006c80;
        local_12c = param_4[1];
        local_e8 = &local_12c;
        local_d8 = &local_130;
        local_134 = param_4[3];
        local_c8 = &local_134;
        local_128[0] = param_4[4];
        local_b8 = local_128;
        local_138 = param_4[2];
        local_a8 = &local_138;
        uVar4 = param_4[5];
        local_f0 = (ulonglong)((int)lVar6 + 1);
        local_e0 = 4;
        local_d0 = 4;
        local_c0 = 4;
        local_b0 = 4;
        local_a0 = 4;
        if (uVar4 == 0) {
          local_98 = "UsbChargerPort_Legacy";
        }
        else if (uVar4 == 1) {
          local_98 = "UsbChargerPort_TypeC";
        }
        else {
          local_98 = "UsbChargerPort_Max";
          if (uVar4 != 2) {
            local_98 = "<invalid>";
          }
        }
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_98[lVar3] != '\0');
        local_90 = (int)lVar3 + 1;
        local_120 = *(undefined8 *)(param_4 + 6);
        local_88 = &local_120;
        uVar4 = param_4[8];
        uVar5 = (ulonglong)uVar4;
        local_8c = 0;
        local_80 = 8;
        if (uVar4 == 0) {
          local_78 = "UsbfnUnknownPort";
        }
        else if (uVar4 == 1) {
          local_78 = "UsbfnStandardDownstreamPort";
        }
        else if (uVar4 == 2) {
          local_78 = "UsbfnChargingDownstreamPort";
        }
        else if (uVar4 == 3) {
          local_78 = "UsbfnDedicatedChargingPort";
        }
        else if (uVar4 == 4) {
          local_78 = "UsbfnInvalidDedicatedChargingPort";
        }
        else {
          local_78 = "UsbfnPortTypeMaximum";
          if (uVar4 != 6) {
            local_78 = "<invalid>";
          }
        }
        do {
          lVar8 = lVar8 + 1;
        } while (local_78[lVar8] != '\0');
        pbVar7 = &DAT_140009daf;
        local_68 = param_4 + 10;
        local_6c = 0;
        local_70 = (int)lVar8 + 1;
        uVar9 = 0xc;
        local_60 = 0x10;
        local_130 = local_138;
        goto LAB_140018f18;
      }
      if (DAT_14000c080 < 6) {
        return uVar2;
      }
      if (uVar4 == 0) {
        local_f8 = (uint *)0x140006c18;
      }
      else if (uVar4 == 0xffffffff) {
        local_f8 = (uint *)0x140006c38;
      }
      else if (uVar4 == 1) {
        local_f8 = (uint *)0x140006c60;
      }
      else if (uVar4 == 3) {
        local_f8 = (uint *)0x140006ca0;
      }
      else {
        local_f8 = (uint *)0x140006cc8;
        if (uVar4 != 4) {
          local_f8 = (uint *)0x140006588;
        }
      }
      do {
        lVar8 = lVar8 + 1;
      } while (*(char *)((longlong)local_f8 + lVar8) != '\0');
      local_f0 = (ulonglong)((int)lVar8 + 1);
      pbVar7 = &DAT_14000a21a;
    }
  }
  uVar9 = 3;
LAB_140018f18:
  _tlgWriteTransfer_EtwWriteTransfer(uVar5,pbVar7,1,3,uVar9,local_118);
  return uVar2;
}



===== BattCUpdateBatteryPowerState @ 140018f48 =====

void BattCUpdateBatteryPowerState(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  
  ExAcquireFastMutex(param_1 + 0x198);
  uVar2 = *(uint *)(param_2 + 0x98) | 0x10;
  if ((*(uint *)(param_2 + 0x1d0) & 1) == 0) {
    uVar2 = *(uint *)(param_2 + 0x98) & 0xffffffef;
  }
  *(uint *)(param_2 + 0x98) = uVar2;
  if (1 < *(uint *)(param_2 + 0x1cc)) {
    uVar1 = *(uint *)(param_2 + 0x1d0) >> 1 & 3;
    if (uVar1 == 0) {
      uVar2 = uVar2 & 0xffffffdf | 0x40;
    }
    else if (uVar1 == 1) {
      uVar2 = uVar2 & 0xffffffbf | 0x20;
    }
    else {
      if (uVar1 != 2) goto LAB_140018fd4;
      uVar2 = uVar2 | 0x60;
    }
    *(uint *)(param_2 + 0x98) = uVar2;
  }
LAB_140018fd4:
  uVar1 = uVar2 | 0x80;
  if (*(char *)(param_1 + 0x2ec) == '\0') {
    uVar1 = uVar2 & 0xffffff7f;
  }
  *(uint *)(param_2 + 0x98) = uVar1;
  ExReleaseFastMutex(param_1 + 0x198);
  return;
}



===== BattCWorkerThread @ 140019020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BattCWorkerThread(undefined8 param_1,longlong param_2,uint *param_3,ulonglong param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint *puVar10;
  code *pcVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  longlong lVar14;
  char *pcVar15;
  undefined4 uVar16;
  byte *pbVar17;
  uint *puVar18;
  undefined8 uVar19;
  bool bVar20;
  undefined1 auStackY_398 [32];
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  uint local_350;
  uint local_34c;
  uint local_348;
  uint local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  uint local_334;
  uint local_330;
  uint local_32c;
  uint local_328 [2];
  longlong *local_320;
  longlong *local_318 [2];
  undefined8 local_308 [4];
  undefined4 *local_2e8;
  undefined8 local_2e0;
  longlong **local_2d8;
  undefined8 local_2d0;
  char *local_2c8;
  int local_2c0;
  undefined4 local_2bc;
  undefined4 *local_2b8;
  undefined8 local_2b0;
  undefined4 *local_2a8;
  undefined8 local_2a0;
  char *local_298;
  undefined8 local_290;
  uint *local_288;
  undefined8 local_280;
  uint *local_278;
  undefined8 local_270;
  uint *local_268;
  undefined8 local_260;
  uint *local_258;
  undefined8 local_250;
  char *local_248;
  int local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  char *local_228;
  int local_220;
  undefined4 local_21c;
  char *local_218;
  int local_210;
  undefined4 local_20c;
  char *local_208;
  int local_200;
  undefined4 local_1fc;
  char *local_1f8;
  int local_1f0;
  undefined4 local_1ec;
  char *local_1e8;
  int local_1e0;
  undefined4 local_1dc;
  char *local_1d8;
  int local_1d0;
  undefined4 local_1cc;
  undefined8 local_1c8 [4];
  undefined4 *local_1a8;
  undefined8 local_1a0;
  longlong **local_198;
  undefined8 local_190;
  char *local_188;
  int local_180;
  undefined4 local_17c;
  undefined4 *local_178;
  undefined8 local_170;
  undefined4 *local_168;
  undefined8 local_160;
  char *local_158;
  undefined8 local_150;
  uint *local_148;
  undefined8 local_140;
  uint *local_138;
  undefined8 local_130;
  uint *local_128;
  undefined8 local_120;
  uint *local_118;
  undefined8 local_110;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_398;
  lVar6 = *(longlong *)(param_2 + 0x18);
  LOCK();
  bVar20 = *(int *)(param_2 + 0x2e0) == 1;
  if (bVar20) {
    *(int *)(param_2 + 0x2e0) = 0;
  }
  UNLOCK();
  if (bVar20) {
    uVar13 = _DAT_fffff78000000008 - AcDcUpdateStormCancellationTime;
    if (*(ulonglong *)(lVar6 + 0x1c0) < uVar13) {
      uVar13 = uVar13 - *(ulonglong *)(lVar6 + 0x1c0);
      uVar16 = (undefined4)(uVar13 / 10000000);
    }
    else {
      uVar16 = 0;
    }
    if (5 < DAT_14000c080) {
      param_3 = (uint *)0x400000000000;
      if (((_DAT_14000c090 & 0x400000000000) == 0) ||
         (bVar20 = true, (DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
        bVar20 = false;
      }
      if (bVar20) {
        local_368 = *(undefined4 *)(param_2 + 0x2e4);
        local_68 = &local_368;
        local_364 = *(undefined4 *)(lVar6 + 0x1c8);
        local_58 = &local_364;
        local_48 = &local_360;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_360 = uVar16;
        _tlgWriteTransfer_EtwWriteTransfer(uVar13,&DAT_14000839d,0x400000000000,param_4,5,local_88);
      }
    }
    *(undefined8 *)(lVar6 + 0x1c0) = 0;
  }
  if (*(char *)(param_2 + 0x178) != '\x01') {
    lVar2 = param_2 + 0x140;
    plVar1 = (longlong *)(lVar6 + 0x48);
LAB_140019187:
    do {
      ExAcquireFastMutex(lVar2);
      plVar7 = (longlong *)*plVar1;
      if (plVar7 != plVar1) {
        if (((longlong *)plVar7[1] != plVar1) ||
           (lVar14 = *plVar7, *(longlong **)(lVar14 + 8) != plVar7)) goto LAB_140019c89;
        *plVar1 = lVar14;
        *(longlong **)(lVar14 + 8) = plVar1;
        ExReleaseFastMutex(lVar2);
        plVar9 = plVar7 + -0x15;
        puVar18 = (uint *)plVar7[2];
        uVar13 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
        uVar4 = puVar18[6];
        if ((int)uVar13 == 0) {
          if ((((uVar4 == 0x29404c) || (uVar4 == 0x294064)) && (puVar18[4] == 0x14)) &&
             (puVar18[2] == 0x10)) {
            LOCK();
            *(undefined4 *)(param_2 + 300) = 1;
            UNLOCK();
            lVar14 = plVar7[2];
            *(undefined8 *)(lVar14 + -0x40) = 0;
            *(undefined8 *)(lVar14 + -0x38) = 0;
            *(undefined8 *)(lVar14 + -0x30) = 0;
            *(longlong *)(lVar14 + -0x28) = param_2;
            LOCK();
            plVar7[-8] = (longlong)BattCCancelStatus;
            UNLOCK();
            if (*(char *)((longlong)plVar7 + -100) != '\0') {
              LOCK();
              lVar14 = plVar7[-8];
              plVar7[-8] = 0;
              UNLOCK();
              if (lVar14 != 0) {
                *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
              }
            }
            plVar8 = *(longlong **)(lVar6 + 0x60);
            if (*plVar8 != lVar6 + 0x58) goto LAB_140019c89;
            plVar7[1] = (longlong)plVar8;
            *plVar7 = lVar6 + 0x58;
            *plVar8 = (longlong)plVar7;
            *(longlong **)(lVar6 + 0x60) = plVar7;
            param_3 = (uint *)plVar7[-0x12];
            if (((int)*(char *)((longlong)plVar7 + -0x65) <= *(char *)((longlong)plVar7 + -0x66) + 1
                ) && (5 < DAT_14000c080)) {
              local_340 = *(undefined4 *)(param_2 + 0x2e4);
              local_1a8 = &local_340;
              local_198 = local_318;
              local_1a0 = 4;
              local_190 = 8;
              iVar5 = *(int *)(plVar7[2] + 0x18);
              if (iVar5 == 0x294040) {
                local_188 = "IOCTL_BATTERY_QUERY_TAG";
              }
              else if (iVar5 == 0x294044) {
                local_188 = "IOCTL_BATTERY_QUERY_INFORMATION";
              }
              else if (iVar5 == 0x298048) {
                local_188 = "IOCTL_BATTERY_SET_INFORMATION";
              }
              else if (iVar5 == 0x29404c) {
                local_188 = "IOCTL_BATTERY_QUERY_STATUS";
              }
              else if (iVar5 == 0x294050) {
                local_188 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
              }
              else if (iVar5 == 0x294064) {
                local_188 = "IOCTL_BATTERY_QUERY_STATUS_EX";
              }
              else if (iVar5 == 0x45400c) {
                local_188 = "IOCTL_PMI_GET_MEASUREMENT";
              }
              else if (iVar5 == 0x454000) {
                local_188 = "IOCTL_PMI_GET_CAPABILITIES";
              }
              else if (iVar5 == 0x454004) {
                local_188 = "IOCTL_PMI_GET_CONFIGURATION";
              }
              else if (iVar5 == 0x458008) {
                local_188 = "IOCTL_PMI_SET_CONFIGURATION";
              }
              else {
                local_188 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
                if (iVar5 != 0x45c010) {
                  local_188 = "<invalid>";
                }
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_188[lVar14] != '\0');
              local_180 = (int)lVar14 + 1;
              local_108 = "AC Power";
              local_17c = 0;
              local_33c = *(undefined4 *)(plVar7[2] + 0x18);
              uVar4 = param_3[2];
              local_178 = &local_33c;
              local_338 = (undefined4)plVar7[-0xf];
              local_168 = &local_338;
              local_170 = 4;
              local_158 = "BattCWorkerThread";
              local_334 = *param_3;
              local_148 = &local_334;
              local_330 = param_3[1];
              local_138 = &local_330;
              local_32c = param_3[3];
              local_128 = &local_32c;
              local_328[0] = param_3[4];
              local_118 = local_328;
              if ((uVar4 & 1) == 0) {
                local_108 = "DC Power";
              }
              local_160 = 4;
              lVar14 = -1;
              local_150 = 0x12;
              local_140 = 4;
              local_130 = 4;
              local_120 = 4;
              local_110 = 4;
              do {
                lVar14 = lVar14 + 1;
              } while (local_108[lVar14] != '\0');
              local_100 = (int)lVar14 + 1;
              local_f8 = "Battery Discharging";
              local_fc = 0;
              lVar14 = -1;
              if ((uVar4 & 2) == 0) {
                local_f8 = "-";
              }
              do {
                lVar14 = lVar14 + 1;
              } while (local_f8[lVar14] != '\0');
              local_f0 = (int)lVar14 + 1;
              local_e8 = "Battery Charging";
              local_ec = 0;
              if ((uVar4 & 4) == 0) {
                local_e8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_e8[lVar14] != '\0');
              local_e0 = (int)lVar14 + 1;
              local_d8 = "Battery Critical";
              local_dc = 0;
              if ((uVar4 & 8) == 0) {
                local_d8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_d8[lVar14] != '\0');
              local_d0 = (int)lVar14 + 1;
              local_c8 = "Battery charge limiting mode";
              local_cc = 0;
              if ((uVar4 & 0x10) == 0) {
                local_c8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_c8[lVar14] != '\0');
              local_c0 = (int)lVar14 + 1;
              local_b8 = "Battery charging state power supply present";
              local_bc = 0;
              if ((uVar4 & 0x20) == 0) {
                local_b8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_b8[lVar14] != '\0');
              local_b0 = (int)lVar14 + 1;
              local_a8 = "Battery charging state adequate";
              local_ac = 0;
              if ((uVar4 & 0x40) == 0) {
                local_a8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_a8[lVar14] != '\0');
              local_a0 = (int)lVar14 + 1;
              pcVar15 = "Battery trip point supported";
              local_9c = 0;
              if ((uVar4 & 0x80) == 0) {
                pcVar15 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (pcVar15[lVar14] != '\0');
              local_90 = (int)lVar14 + 1;
              pbVar17 = &DAT_140008ea0;
              puVar12 = local_1c8;
              local_8c = 0;
              local_318[0] = plVar9;
              local_98 = pcVar15;
LAB_140019a41:
              param_4 = 4;
              param_3 = (uint *)&s__;
              _tlgWriteTransfer_EtwWriteTransfer(pcVar15,pbVar17,&s__,4,0x14,puVar12);
            }
            goto LAB_140019187;
          }
LAB_140019a58:
          if (((uVar4 == 0x294040) && ((puVar18[4] & 0xfffffffb) == 0)) && (puVar18[2] == 4)) {
            LOCK();
            *(undefined4 *)(param_2 + 0x130) = 1;
            UNLOCK();
            lVar14 = plVar7[2];
            *(undefined8 *)(lVar14 + -0x40) = 0;
            *(undefined8 *)(lVar14 + -0x38) = 0;
            *(undefined8 *)(lVar14 + -0x30) = 0;
            *(longlong *)(lVar14 + -0x28) = param_2;
            LOCK();
            plVar7[-8] = (longlong)BattCCancelTag;
            UNLOCK();
            if (*(char *)((longlong)plVar7 + -100) != '\0') {
              LOCK();
              lVar14 = plVar7[-8];
              plVar7[-8] = 0;
              UNLOCK();
              if (lVar14 != 0) {
                *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
              }
            }
            plVar9 = *(longlong **)(lVar6 + 0x70);
            if (*plVar9 != lVar6 + 0x68) {
LAB_140019c89:
              pcVar11 = (code *)swi(0x29);
              (*pcVar11)(3);
              pcVar11 = (code *)swi(3);
              (*pcVar11)();
              return;
            }
            *plVar7 = lVar6 + 0x68;
            plVar7[1] = (longlong)plVar9;
            *plVar9 = (longlong)plVar7;
            *(longlong **)(lVar6 + 0x70) = plVar7;
            goto LAB_140019187;
          }
        }
        else {
          if ((uVar4 != 0x29404c) && (uVar4 != 0x294064)) goto LAB_140019a58;
          if ((puVar18[4] == 0x14) && (puVar18[2] == 0x10)) {
LAB_140019235:
            LOCK();
            *(undefined4 *)(param_2 + 300) = 1;
            UNLOCK();
            lVar14 = plVar7[2];
            *(undefined8 *)(lVar14 + -0x40) = 0;
            *(undefined8 *)(lVar14 + -0x38) = 0;
            *(undefined8 *)(lVar14 + -0x30) = 0;
            *(longlong *)(lVar14 + -0x28) = param_2;
            LOCK();
            plVar7[-8] = (longlong)BattCCancelStatus;
            UNLOCK();
            if (*(char *)((longlong)plVar7 + -100) != '\0') {
              LOCK();
              lVar14 = plVar7[-8];
              plVar7[-8] = 0;
              UNLOCK();
              if (lVar14 != 0) {
                *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
              }
            }
            plVar8 = *(longlong **)(lVar6 + 0x60);
            if (*plVar8 != lVar6 + 0x58) goto LAB_140019c89;
            plVar7[1] = (longlong)plVar8;
            *plVar7 = lVar6 + 0x58;
            *plVar8 = (longlong)plVar7;
            *(longlong **)(lVar6 + 0x60) = plVar7;
            param_3 = (uint *)plVar7[-0x12];
            if (((int)*(char *)((longlong)plVar7 + -0x65) <= *(char *)((longlong)plVar7 + -0x66) + 1
                ) && (5 < DAT_14000c080)) {
              local_35c = *(undefined4 *)(param_2 + 0x2e4);
              local_2e8 = &local_35c;
              local_2d8 = &local_320;
              local_2e0 = 4;
              local_2d0 = 8;
              iVar5 = *(int *)(plVar7[2] + 0x18);
              if (iVar5 == 0x294040) {
                local_2c8 = "IOCTL_BATTERY_QUERY_TAG";
              }
              else if (iVar5 == 0x294044) {
                local_2c8 = "IOCTL_BATTERY_QUERY_INFORMATION";
              }
              else if (iVar5 == 0x298048) {
                local_2c8 = "IOCTL_BATTERY_SET_INFORMATION";
              }
              else if (iVar5 == 0x29404c) {
                local_2c8 = "IOCTL_BATTERY_QUERY_STATUS";
              }
              else if (iVar5 == 0x294050) {
                local_2c8 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
              }
              else if (iVar5 == 0x294064) {
                local_2c8 = "IOCTL_BATTERY_QUERY_STATUS_EX";
              }
              else if (iVar5 == 0x45400c) {
                local_2c8 = "IOCTL_PMI_GET_MEASUREMENT";
              }
              else if (iVar5 == 0x454000) {
                local_2c8 = "IOCTL_PMI_GET_CAPABILITIES";
              }
              else if (iVar5 == 0x454004) {
                local_2c8 = "IOCTL_PMI_GET_CONFIGURATION";
              }
              else if (iVar5 == 0x458008) {
                local_2c8 = "IOCTL_PMI_SET_CONFIGURATION";
              }
              else {
                local_2c8 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
                if (iVar5 != 0x45c010) {
                  local_2c8 = "<invalid>";
                }
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_2c8[lVar14] != '\0');
              local_2c0 = (int)lVar14 + 1;
              local_248 = "AC Power";
              local_2bc = 0;
              local_358 = *(undefined4 *)(plVar7[2] + 0x18);
              uVar4 = param_3[2];
              local_2b8 = &local_358;
              local_354 = (undefined4)plVar7[-0xf];
              local_2a8 = &local_354;
              local_2b0 = 4;
              local_298 = "BattCWorkerThread";
              local_350 = *param_3;
              local_288 = &local_350;
              local_34c = param_3[1];
              local_278 = &local_34c;
              local_348 = param_3[3];
              local_268 = &local_348;
              local_344 = param_3[4];
              local_258 = &local_344;
              if ((uVar4 & 1) == 0) {
                local_248 = "DC Power";
              }
              local_2a0 = 4;
              lVar14 = -1;
              local_290 = 0x12;
              local_280 = 4;
              local_270 = 4;
              local_260 = 4;
              local_250 = 4;
              do {
                lVar14 = lVar14 + 1;
              } while (local_248[lVar14] != '\0');
              local_240 = (int)lVar14 + 1;
              local_238 = "Battery Discharging";
              local_23c = 0;
              lVar14 = -1;
              if ((uVar4 & 2) == 0) {
                local_238 = "-";
              }
              do {
                lVar14 = lVar14 + 1;
              } while (local_238[lVar14] != '\0');
              local_230 = (int)lVar14 + 1;
              local_228 = "Battery Charging";
              local_22c = 0;
              if ((uVar4 & 4) == 0) {
                local_228 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_228[lVar14] != '\0');
              local_220 = (int)lVar14 + 1;
              local_218 = "Battery Critical";
              local_21c = 0;
              if ((uVar4 & 8) == 0) {
                local_218 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_218[lVar14] != '\0');
              local_210 = (int)lVar14 + 1;
              local_208 = "Battery charge limiting mode";
              local_20c = 0;
              if ((uVar4 & 0x10) == 0) {
                local_208 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_208[lVar14] != '\0');
              local_200 = (int)lVar14 + 1;
              local_1f8 = "Battery charging state power supply present";
              local_1fc = 0;
              if ((uVar4 & 0x20) == 0) {
                local_1f8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_1f8[lVar14] != '\0');
              local_1f0 = (int)lVar14 + 1;
              local_1e8 = "Battery charging state adequate";
              local_1ec = 0;
              if ((uVar4 & 0x40) == 0) {
                local_1e8 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (local_1e8[lVar14] != '\0');
              local_1e0 = (int)lVar14 + 1;
              pcVar15 = "Battery trip point supported";
              local_1dc = 0;
              if ((uVar4 & 0x80) == 0) {
                pcVar15 = "-";
              }
              lVar14 = -1;
              do {
                lVar14 = lVar14 + 1;
              } while (pcVar15[lVar14] != '\0');
              local_1d0 = (int)lVar14 + 1;
              pbVar17 = &DAT_140008d07;
              puVar12 = local_308;
              local_1cc = 0;
              local_320 = plVar9;
              local_1d8 = pcVar15;
              goto LAB_140019a41;
            }
            goto LAB_140019187;
          }
          if (uVar4 != 0x294064) goto LAB_140019a58;
          if ((0x23 < puVar18[4]) && (0x23 < puVar18[2])) goto LAB_140019235;
        }
        BattCIoctl(lVar6,(longlong)plVar9,puVar18);
        param_3 = puVar18;
        goto LAB_140019187;
      }
      ExReleaseFastMutex(lVar2);
      LOCK();
      piVar3 = (int *)(param_2 + 300);
      iVar5 = *piVar3;
      *piVar3 = *piVar3;
      UNLOCK();
      if (iVar5 != 0) {
        BattCCheckStatusQueue(param_2,lVar6,(longlong *)param_3,param_4);
      }
      LOCK();
      piVar3 = (int *)(param_2 + 0x130);
      iVar5 = *piVar3;
      *piVar3 = *piVar3;
      UNLOCK();
      if (iVar5 != 0) {
        BattCCheckTagQueue(param_2,lVar6,param_3,param_4);
      }
      ExAcquireFastMutex(lVar2);
      puVar18 = (uint *)(lVar6 + 0x78);
      while (puVar10 = *(uint **)puVar18, puVar10 != puVar18) {
        if ((*(uint **)(puVar10 + 2) != puVar18) ||
           (lVar14 = *(longlong *)puVar10, *(uint **)(lVar14 + 8) != puVar10)) goto LAB_140019c89;
        *(longlong *)puVar18 = lVar14;
        *(uint **)(lVar14 + 8) = puVar18;
        ExReleaseFastMutex(lVar2);
        param_3 = puVar10;
        BattCWmi(param_2,lVar6,(longlong)puVar10,param_4);
        ExFreePoolWithTag(puVar10,0x74746142);
        ExAcquireFastMutex(lVar2);
      }
      ExReleaseFastMutex(lVar2);
      LOCK();
      piVar3 = (int *)(param_2 + 0x128);
      iVar5 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar5 == 1) {
        return;
      }
      if (iVar5 != 2) {
        LOCK();
        *(undefined4 *)(param_2 + 0x128) = 1;
        UNLOCK();
      }
    } while (*(char *)(param_2 + 0x178) != '\x01');
  }
  BattCCompleteIrpQueue(param_2,(longlong *)(lVar6 + 0x48),(char *)0xc00002b6,param_4);
  BattCCompleteIrpQueue(param_2,(longlong *)(lVar6 + 0x68),(char *)0xc00002b6,param_4);
  uVar19 = 0xc00002b6;
  BattCCompleteIrpQueue(param_2,(longlong *)(lVar6 + 0x58),(char *)0xc00002b6,param_4);
  BattCCompleteWmiQueue(param_2,(longlong *)(lVar6 + 0x78),uVar19,param_4);
  LOCK();
  piVar3 = (int *)(param_2 + 0x17c);
  iVar5 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    KeSetEvent(param_2 + 0x180,0,0);
  }
  return;
}



===== BattCAdapterRundownIrpQueue @ 140019c98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCAdapterRundownIrpQueue(undefined8 *param_1,char param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  byte *pbVar6;
  longlong lVar7;
  char *pcVar8;
  undefined1 auStackY_138 [32];
  undefined4 uVar9;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  longlong *local_f0;
  undefined8 local_e8 [4];
  longlong **local_c8;
  undefined8 local_c0;
  char *local_b8;
  uint local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  puVar2 = (undefined8 *)*param_1;
  do {
    if (puVar2 == param_1) {
      return;
    }
    pcVar8 = "BattCAdapterRundownIrpQueue";
    local_f0 = puVar2 + -0x15;
    iVar3 = *(char *)((longlong)puVar2 + -0x66) + 1;
    if (param_2 == '\0') {
      if ((*(char *)((longlong)puVar2 + -0x65) <= iVar3) && (5 < DAT_14000c080)) {
        lVar7 = puVar2[2];
        iVar3 = *(int *)(lVar7 + 0x18);
        if (iVar3 == 0x294070) {
          local_b8 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
        }
        else if (iVar3 == 0x29406c) {
          local_b8 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
        }
        else {
          local_b8 = "IOCTL_POWER_ADAPTER_SET_STATUS";
          if (iVar3 != 0x294074) {
            local_b8 = "<invalid>";
          }
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_b8[lVar4] != '\0');
        local_b0 = (int)lVar4 + 1;
        pcVar5 = (char *)(ulonglong)local_b0;
        local_108 = *(undefined4 *)(lVar7 + 0x18);
        local_a8 = &local_108;
        local_104 = *(undefined4 *)(puVar2 + -0xf);
        pbVar6 = &DAT_14000a770;
        local_98 = &local_104;
        uVar9 = 7;
LAB_140019f73:
        local_80 = 0x1c;
        local_88 = "BattCAdapterRundownIrpQueue";
        local_90 = 4;
        local_a0 = 4;
        local_ac = 0;
        local_c0 = 8;
        local_c8 = &local_f0;
        _tlgWriteTransfer_EtwWriteTransfer(pcVar5,pbVar6,lVar7,pcVar8,uVar9,local_e8);
      }
    }
    else {
      pcVar8 = (char *)puVar2[-0x12];
      if ((*(char *)((longlong)puVar2 + -0x65) <= iVar3) && (5 < DAT_14000c080)) {
        lVar7 = puVar2[2];
        iVar3 = *(int *)(lVar7 + 0x18);
        if (iVar3 == 0x294070) {
          local_b8 = "IOCTL_POWER_ADAPTER_QUERY_INFORMATION";
        }
        else if (iVar3 == 0x29406c) {
          local_b8 = "IOCTL_POWER_ADAPTER_QUERY_STATUS";
        }
        else {
          local_b8 = "IOCTL_POWER_ADAPTER_SET_STATUS";
          if (iVar3 != 0x294074) {
            local_b8 = "<invalid>";
          }
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_b8[lVar4] != '\0');
        local_b0 = (int)lVar4 + 1;
        local_78 = "Power Adapter Online";
        local_100 = *(undefined4 *)(lVar7 + 0x18);
        local_a8 = &local_100;
        local_fc = *(undefined4 *)(puVar2 + -0xf);
        uVar1 = *(uint *)(pcVar8 + 8);
        local_98 = &local_fc;
        if ((uVar1 & 1) == 0) {
          local_78 = "Power Adapter Offline";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_78[lVar4] != '\0');
        local_70 = (int)lVar4 + 1;
        local_68 = "REC Engaged";
        local_6c = 0;
        if ((uVar1 & 2) == 0) {
          local_68 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_68[lVar4] != '\0');
        local_60 = (int)lVar4 + 1;
        pcVar5 = "REC Overridden";
        local_5c = 0;
        if ((uVar1 & 4) == 0) {
          pcVar5 = "-";
        }
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (pcVar5[lVar4] != '\0');
        local_50 = (int)lVar4 + 1;
        pbVar6 = &DAT_14000a8e8;
        local_f8 = *(undefined4 *)(pcVar8 + 4);
        local_48 = &local_f8;
        local_f4 = *(undefined4 *)(pcVar8 + 0xc);
        local_38 = &local_f4;
        uVar9 = 0xc;
        local_4c = 0;
        local_40 = 4;
        local_30 = 4;
        local_58 = pcVar5;
        goto LAB_140019f73;
      }
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== BattCEtwTraceControlCallback @ 140019fd0 =====

void BattCEtwTraceControlCallback(undefined8 param_1,int param_2)

{
  undefined8 *puVar1;
  
  if (param_2 == 2) {
    KeAcquireGuardedMutex(&BatteryListMutex);
    for (puVar1 = BatteryListHead; (undefined8 **)puVar1 != &BatteryListHead;
        puVar1 = (undefined8 *)*puVar1) {
      ExAcquireFastMutex(puVar1 + 0x27);
      BattCTraceBatteryBay((longlong)(puVar1 + -1));
      ExReleaseFastMutex(puVar1 + 0x27);
    }
    KeReleaseGuardedMutex(&BatteryListMutex);
  }
  return;
}



===== BattCRundownIrpQueue @ 14001a078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCRundownIrpQueue(longlong param_1,longlong *param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  byte *pbVar5;
  longlong *plVar6;
  longlong lVar7;
  char *pcVar8;
  undefined1 auStackY_248 [32];
  undefined4 uVar9;
  undefined8 *puVar10;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8 [2];
  longlong *local_1f0;
  undefined8 local_1e8 [4];
  undefined4 *local_1c8;
  undefined8 local_1c0;
  longlong **local_1b8;
  undefined8 local_1b0;
  char *local_1a8;
  int local_1a0;
  undefined4 local_19c;
  undefined4 *local_198;
  undefined8 local_190;
  undefined4 *local_188;
  undefined8 local_180;
  char *local_178;
  undefined8 local_170;
  undefined4 *local_168;
  undefined8 local_160;
  undefined4 *local_158;
  undefined8 local_150;
  undefined4 *local_148;
  undefined8 local_140;
  undefined4 *local_138;
  undefined8 local_130;
  char *local_128;
  int local_120;
  undefined4 local_11c;
  char *local_118;
  int local_110;
  undefined4 local_10c;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  char *local_e8;
  int local_e0;
  undefined4 local_dc;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined8 local_a8 [4];
  undefined4 *local_88;
  undefined8 local_80;
  longlong **local_78;
  undefined8 local_70;
  char *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_248;
  plVar6 = (longlong *)*param_2;
  if (plVar6 != param_2) {
    do {
      pcVar8 = "<invalid>";
      local_1f0 = plVar6 + -0x15;
      iVar2 = *(char *)((longlong)plVar6 + -0x66) + 1;
      if (param_3 == '\0') {
        if ((*(char *)((longlong)plVar6 + -0x65) <= iVar2) && (5 < DAT_14000c080)) {
          local_218 = *(undefined4 *)(param_1 + 0x2e4);
          lVar7 = plVar6[2];
          local_88 = &local_218;
          local_78 = &local_1f0;
          local_80 = 4;
          local_70 = 8;
          iVar2 = *(int *)(lVar7 + 0x18);
          if (iVar2 == 0x294040) {
            local_68 = "IOCTL_BATTERY_QUERY_TAG";
          }
          else if (iVar2 == 0x294044) {
            local_68 = "IOCTL_BATTERY_QUERY_INFORMATION";
          }
          else if (iVar2 == 0x298048) {
            local_68 = "IOCTL_BATTERY_SET_INFORMATION";
          }
          else if (iVar2 == 0x29404c) {
            local_68 = "IOCTL_BATTERY_QUERY_STATUS";
          }
          else if (iVar2 == 0x294050) {
            local_68 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
          }
          else if (iVar2 == 0x294064) {
            local_68 = "IOCTL_BATTERY_QUERY_STATUS_EX";
          }
          else if (iVar2 == 0x45400c) {
            local_68 = "IOCTL_PMI_GET_MEASUREMENT";
          }
          else if (iVar2 == 0x454000) {
            local_68 = "IOCTL_PMI_GET_CAPABILITIES";
          }
          else if (iVar2 == 0x454004) {
            local_68 = "IOCTL_PMI_GET_CONFIGURATION";
          }
          else if (iVar2 == 0x458008) {
            local_68 = "IOCTL_PMI_SET_CONFIGURATION";
          }
          else {
            local_68 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
            if (iVar2 != 0x45c010) {
              local_68 = "<invalid>";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_68[lVar3] != '\0');
          local_60 = (int)lVar3 + 1;
          pcVar4 = (char *)(ulonglong)local_60;
          local_5c = 0;
          local_214 = *(undefined4 *)(lVar7 + 0x18);
          local_58 = &local_214;
          local_210 = (undefined4)plVar6[-0xf];
          pbVar5 = &DAT_14000acb2;
          local_48 = &local_210;
          local_38 = "BattCRundownIrpQueue";
          puVar10 = local_a8;
          uVar9 = 8;
          local_50 = 4;
          local_40 = 4;
          local_30 = 0x15;
          goto LAB_14001a5fe;
        }
      }
      else {
        pcVar8 = (char *)plVar6[-0x12];
        if ((*(char *)((longlong)plVar6 + -0x65) <= iVar2) && (5 < DAT_14000c080)) {
          local_218 = *(undefined4 *)(param_1 + 0x2e4);
          lVar7 = plVar6[2];
          local_1c8 = &local_218;
          local_1b8 = &local_1f0;
          local_1c0 = 4;
          local_1b0 = 8;
          iVar2 = *(int *)(lVar7 + 0x18);
          if (iVar2 == 0x294040) {
            local_1a8 = "IOCTL_BATTERY_QUERY_TAG";
          }
          else if (iVar2 == 0x294044) {
            local_1a8 = "IOCTL_BATTERY_QUERY_INFORMATION";
          }
          else if (iVar2 == 0x298048) {
            local_1a8 = "IOCTL_BATTERY_SET_INFORMATION";
          }
          else if (iVar2 == 0x29404c) {
            local_1a8 = "IOCTL_BATTERY_QUERY_STATUS";
          }
          else if (iVar2 == 0x294050) {
            local_1a8 = "IOCTL_BATTERY_CHARGING_SOURCE_CHANGE";
          }
          else if (iVar2 == 0x294064) {
            local_1a8 = "IOCTL_BATTERY_QUERY_STATUS_EX";
          }
          else if (iVar2 == 0x45400c) {
            local_1a8 = "IOCTL_PMI_GET_MEASUREMENT";
          }
          else if (iVar2 == 0x454000) {
            local_1a8 = "IOCTL_PMI_GET_CAPABILITIES";
          }
          else if (iVar2 == 0x454004) {
            local_1a8 = "IOCTL_PMI_GET_CONFIGURATION";
          }
          else if (iVar2 == 0x458008) {
            local_1a8 = "IOCTL_PMI_SET_CONFIGURATION";
          }
          else {
            local_1a8 = "IOCTL_PMI_REGISTER_EVENT_NOTIFY";
            if (iVar2 != 0x45c010) {
              local_1a8 = "<invalid>";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_1a8[lVar3] != '\0');
          local_1a0 = (int)lVar3 + 1;
          local_128 = "AC Power";
          local_19c = 0;
          local_20c = *(undefined4 *)(lVar7 + 0x18);
          local_198 = &local_20c;
          local_208 = (undefined4)plVar6[-0xf];
          uVar1 = *(uint *)(pcVar8 + 8);
          local_188 = &local_208;
          local_178 = "BattCRundownIrpQueue";
          local_204 = *(undefined4 *)pcVar8;
          local_168 = &local_204;
          local_200 = *(undefined4 *)(pcVar8 + 4);
          local_158 = &local_200;
          local_1fc = *(undefined4 *)(pcVar8 + 0xc);
          local_148 = &local_1fc;
          local_1f8[0] = *(undefined4 *)(pcVar8 + 0x10);
          local_138 = local_1f8;
          if ((uVar1 & 1) == 0) {
            local_128 = "DC Power";
          }
          local_190 = 4;
          lVar3 = -1;
          local_180 = 4;
          local_170 = 0x15;
          local_160 = 4;
          local_150 = 4;
          local_140 = 4;
          local_130 = 4;
          do {
            lVar3 = lVar3 + 1;
          } while (local_128[lVar3] != '\0');
          local_120 = (int)lVar3 + 1;
          local_118 = "Battery Discharging";
          local_11c = 0;
          if ((uVar1 & 2) == 0) {
            local_118 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_118[lVar3] != '\0');
          local_110 = (int)lVar3 + 1;
          local_108 = "Battery Charging";
          local_10c = 0;
          if ((uVar1 & 4) == 0) {
            local_108 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_108[lVar3] != '\0');
          local_100 = (int)lVar3 + 1;
          local_f8 = "Battery Critical";
          local_fc = 0;
          if ((uVar1 & 8) == 0) {
            local_f8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_f8[lVar3] != '\0');
          local_f0 = (int)lVar3 + 1;
          local_e8 = "Battery charge limiting mode";
          local_ec = 0;
          if ((uVar1 & 0x10) == 0) {
            local_e8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_e8[lVar3] != '\0');
          local_e0 = (int)lVar3 + 1;
          local_d8 = "Battery charging state power supply present";
          local_dc = 0;
          if ((uVar1 & 0x20) == 0) {
            local_d8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_d8[lVar3] != '\0');
          local_d0 = (int)lVar3 + 1;
          local_c8 = "Battery charging state adequate";
          local_cc = 0;
          if ((uVar1 & 0x40) == 0) {
            local_c8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_c8[lVar3] != '\0');
          local_c0 = (int)lVar3 + 1;
          pcVar4 = "Battery trip point supported";
          local_bc = 0;
          if ((uVar1 & 0x80) == 0) {
            pcVar4 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (pcVar4[lVar3] != '\0');
          local_b0 = (int)lVar3 + 1;
          pbVar5 = &DAT_14000a5d5;
          puVar10 = local_1e8;
          local_ac = 0;
          uVar9 = 0x14;
          local_b8 = pcVar4;
LAB_14001a5fe:
          _tlgWriteTransfer_EtwWriteTransfer(pcVar4,pbVar5,lVar7,pcVar8,uVar9,puVar10);
        }
      }
      plVar6 = (longlong *)*plVar6;
    } while (plVar6 != param_2);
  }
  return;
}



===== BattCTraceLoggingControlCallback @ 14001a660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BattCTraceLoggingControlCallback
               (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  undefined1 auStackY_2f8 [32];
  uint local_2c8;
  uint local_2c4;
  longlong local_2c0;
  uint local_2b8;
  int local_2b4;
  uint local_2b0;
  undefined4 local_2ac;
  uint local_2a8 [2];
  undefined8 local_2a0;
  longlong *local_298 [2];
  undefined8 local_288 [4];
  uint *local_268;
  ulonglong local_260;
  longlong *local_258;
  ulonglong local_250;
  char *local_248;
  uint local_240;
  undefined4 local_23c;
  uint *local_238;
  ulonglong local_230;
  uint *local_228;
  ulonglong local_220;
  longlong *local_218;
  ulonglong local_210;
  longlong **local_208;
  ulonglong local_200;
  char *local_1f8;
  ulonglong local_1f0;
  uint *local_1e8;
  ulonglong local_1e0;
  char *local_1d8;
  uint local_1d0 [2];
  char *local_1c8;
  int local_1c0;
  undefined4 local_1bc;
  uint *local_1b8;
  undefined8 local_1b0;
  undefined4 *local_1a8;
  undefined8 local_1a0;
  uint *local_198;
  undefined8 local_190;
  undefined8 *local_188;
  undefined8 local_180;
  longlong *local_178;
  undefined8 local_170;
  uint *local_168;
  undefined8 local_160;
  uint *local_158;
  undefined8 local_150;
  char *local_148;
  int local_140;
  undefined4 local_13c;
  char *local_138;
  int local_130;
  undefined4 local_12c;
  uint *local_128;
  undefined8 local_120;
  undefined8 local_118;
  uint local_110 [2];
  uint *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  uint local_f0 [2];
  uint *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0 [2];
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  if (param_2 == 2) {
    local_38 = __security_cookie ^ (ulonglong)auStackY_2f8;
    KeAcquireGuardedMutex(&BatteryListMutex);
    lVar10 = -1;
    puVar12 = BatteryListHead;
    if ((undefined8 **)BatteryListHead != &BatteryListHead) {
      do {
        puVar1 = puVar12 + -1;
        Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
        lVar7 = puVar12[2];
        plVar11 = puVar12 + 0x27;
        local_298[0] = plVar11;
        ExAcquireFastMutex(plVar11);
        ExAcquireFastMutex(puVar12 + 0x32);
        if (5 < DAT_14000c080) {
          local_2b8 = *(uint *)((longlong)puVar12 + 0x2dc);
          local_258 = (longlong *)&local_2b4;
          local_268 = &local_2b8;
          local_248 = "Battery Absent";
          local_2b4 = *(int *)(lVar7 + 0x44);
          local_260 = 4;
          lVar3 = -1;
          if (local_2b4 != 0) {
            local_248 = "-";
          }
          local_250 = 4;
          do {
            lVar3 = lVar3 + 1;
          } while (local_248[lVar3] != '\0');
          uVar6 = *(uint *)(lVar7 + 0x98);
          local_240 = (int)lVar3 + 1;
          local_238 = (uint *)0x140006418;
          local_23c = 0;
          if ((uVar6 & 1) == 0) {
            local_238 = (uint *)0x140006428;
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(char *)((longlong)local_238 + lVar3) != '\0');
          local_228 = (uint *)0x140006438;
          local_230 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 2) == 0) {
            local_228 = (uint *)&s__;
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(char *)((longlong)local_228 + lVar3) != '\0');
          local_218 = (longlong *)0x140006450;
          local_220 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 4) == 0) {
            local_218 = (longlong *)&s__;
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(char *)((longlong)local_218 + lVar3) != '\0');
          local_208 = (longlong **)0x140006468;
          local_210 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 8) == 0) {
            local_208 = (longlong **)&s__;
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(char *)((longlong)local_208 + lVar3) != '\0');
          local_1f8 = "Battery charge limiting mode";
          local_200 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 0x10) == 0) {
            local_1f8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_1f8[lVar3] != '\0');
          local_1e8 = (uint *)0x1400064a0;
          local_1f0 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 0x20) == 0) {
            local_1e8 = (uint *)&s__;
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (*(char *)((longlong)local_1e8 + lVar3) != '\0');
          local_1d8 = "Battery charging state adequate";
          local_1e0 = (ulonglong)((int)lVar3 + 1);
          if ((uVar6 & 0x40) == 0) {
            local_1d8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_1d8[lVar3] != '\0');
          local_1d0[0] = (int)lVar3 + 1;
          local_1c8 = "Battery trip point supported";
          local_1d0[1] = 0;
          if ((uVar6 & 0x80) == 0) {
            local_1c8 = "-";
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_1c8[lVar3] != '\0');
          uVar6 = *(uint *)(lVar7 + 0xb0);
          local_1c0 = (int)lVar3 + 1;
          local_2a8[0] = *(uint *)(lVar7 + 0x9c);
          local_1bc = 0;
          if (uVar6 == 0) {
            local_2b0 = 0;
          }
          else {
            local_2b0 = (local_2a8[0] * 100 + (uVar6 >> 1)) / uVar6;
          }
          local_1b8 = &local_2b0;
          local_1b0 = 4;
          if (uVar6 == 0) {
            local_2ac = 0;
          }
          else {
            local_2ac = (undefined4)(((ulonglong)local_2a8[0] * 100000) / (ulonglong)uVar6);
          }
          local_2c4 = *(uint *)(lVar7 + 0x1cc);
          local_1a8 = &local_2ac;
          local_198 = local_2a8;
          local_188 = &local_2a0;
          local_2c0 = CONCAT44(local_2c0._4_4_,*(undefined4 *)(lVar7 + 0xa0));
          local_178 = &local_2c0;
          local_2c8 = *(uint *)(lVar7 + 0xa4);
          local_168 = &local_2c8;
          local_158 = &local_2c4;
          param_4 = 4;
          local_2a0 = CONCAT44(local_2a0._4_4_,uVar6);
          local_1a0 = 4;
          local_190 = 4;
          local_180 = 4;
          local_170 = 4;
          local_160 = 4;
          local_150 = 4;
          if (local_2c4 == 0) {
            local_148 = "?";
          }
          else {
            local_148 = "Charge Limiting Mode";
            if ((*(byte *)(lVar7 + 0x1d0) & 1) == 0) {
              local_148 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_148[lVar3] != '\0');
          local_140 = (int)lVar3 + 1;
          local_13c = 0;
          if (local_2c4 < 2) {
            local_138 = "?";
          }
          else {
            uVar6 = *(uint *)(lVar7 + 0x1d0) & 6;
            if (uVar6 == 0) {
              local_138 = "BatteryNoPowerSupply";
            }
            else if (uVar6 == 2) {
              local_138 = "BatteryInadequatePowerSupply";
            }
            else {
              local_138 = "BatteryAdequatePowerSupply";
              if (uVar6 != 4) {
                local_138 = "<invalid>";
              }
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_138[lVar3] != '\0');
          local_130 = (int)lVar3 + 1;
          local_128 = local_110;
          local_118 = *(undefined8 *)(lVar7 + 0x148);
          local_110[0] = (uint)*(ushort *)(lVar7 + 0x140);
          local_108 = local_f0;
          local_f8 = *(undefined8 *)(lVar7 + 0x198);
          local_f0[0] = (uint)*(ushort *)(lVar7 + 400);
          local_e8 = local_d0;
          local_d8 = *(undefined8 *)(lVar7 + 0x158);
          local_d0[0] = (uint)*(ushort *)(lVar7 + 0x150);
          uVar6 = *(uint *)(lVar7 + 0xa8);
          local_12c = 0;
          local_120 = 2;
          local_110[1] = 0;
          local_100 = 2;
          local_f0[1] = 0;
          local_e0 = 2;
          local_d0[1] = 0;
          if (uVar6 == 0xffffffff) {
            local_c8 = "?";
          }
          else {
            local_c8 = "System Battery";
            if (-1 < (int)uVar6) {
              local_c8 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_c8[lVar3] != '\0');
          local_c0 = (int)lVar3 + 1;
          local_bc = 0;
          if (uVar6 == 0xffffffff) {
            local_b8 = "?";
          }
          else {
            local_b8 = "Battery Capacity Relative";
            if ((uVar6 >> 0x1e & 1) == 0) {
              local_b8 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_b8[lVar3] != '\0');
          local_b0 = (int)lVar3 + 1;
          local_ac = 0;
          if (uVar6 == 0xffffffff) {
            local_a8 = "?";
          }
          else {
            local_a8 = "Short Term Battery";
            if ((uVar6 >> 0x1d & 1) == 0) {
              local_a8 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_a8[lVar3] != '\0');
          local_a0 = (int)lVar3 + 1;
          local_9c = 0;
          if (uVar6 == 0xffffffff) {
            local_98 = "?";
          }
          else {
            local_98 = "Battery Sealed";
            if ((uVar6 >> 0x1c & 1) == 0) {
              local_98 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_98[lVar3] != '\0');
          local_90 = (int)lVar3 + 1;
          local_8c = 0;
          if (uVar6 == 0xffffffff) {
            local_88 = "?";
          }
          else {
            local_88 = "Set Charge Supported";
            if ((uVar6 & 1) == 0) {
              local_88 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_88[lVar3] != '\0');
          local_80 = (int)lVar3 + 1;
          local_7c = 0;
          if (uVar6 == 0xffffffff) {
            local_78 = "?";
          }
          else {
            local_78 = "Set Discharge Supported";
            if ((uVar6 & 2) == 0) {
              local_78 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_78[lVar3] != '\0');
          local_70 = (int)lVar3 + 1;
          local_6c = 0;
          if (uVar6 == 0xffffffff) {
            local_68 = "?";
          }
          else {
            local_68 = "Set Charging Source Supported";
            if ((uVar6 & 4) == 0) {
              local_68 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_68[lVar3] != '\0');
          local_60 = (int)lVar3 + 1;
          local_5c = 0;
          if (uVar6 == 0xffffffff) {
            local_58 = "?";
          }
          else {
            local_58 = "Set Charging Source Supported";
            if ((uVar6 & 4) == 0) {
              local_58 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_58[lVar3] != '\0');
          local_50 = (int)lVar3 + 1;
          local_4c = 0;
          if (uVar6 == 0xffffffff) {
            local_48 = "?";
          }
          else {
            local_48 = "Set Charger ID Supported";
            if ((uVar6 & 8) == 0) {
              local_48 = "-";
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_48[lVar3] != '\0');
          local_40 = (int)lVar3 + 1;
          local_3c = 0;
          _tlgWriteTransfer_EtwWriteTransfer(local_48,&DAT_14000a9bb,"?",4,0x25,local_288);
        }
        BattCRundownIrpQueue((longlong)puVar1,(longlong *)(lVar7 + 0x48),'\0');
        BattCRundownIrpQueue((longlong)puVar1,(longlong *)(lVar7 + 0x58),'\x01');
        param_3 = 0;
        BattCRundownIrpQueue((longlong)puVar1,(longlong *)(lVar7 + 0x68),'\0');
        plVar9 = (longlong *)(lVar7 + 0x78);
        plVar8 = (longlong *)*plVar9;
        if (plVar8 != plVar9) {
          do {
            if (5 < DAT_14000c080) {
              local_2c4 = *(uint *)((longlong)puVar12 + 0x2dc);
              iVar2 = (int)plVar8[4];
              param_3 = 4;
              local_268 = &local_2c4;
              local_2c0 = plVar8[3];
              local_258 = &local_2c0;
              local_260 = 4;
              local_250 = 8;
              if (iVar2 == 0) {
                local_248 = "BattWmiStatusId";
              }
              else if (iVar2 == 1) {
                local_248 = "BattWmiRuntimeId";
              }
              else if (iVar2 == 2) {
                local_248 = "BattWmiTemperatureId";
              }
              else if (iVar2 == 3) {
                local_248 = "BattWmiFullChargedCapacityId";
              }
              else if (iVar2 == 4) {
                local_248 = "BattWmiCycleCountId";
              }
              else {
                local_248 = "BattWmiStaticDataId";
                if (iVar2 != 5) {
                  local_248 = "<invalid>";
                }
              }
              lVar7 = -1;
              do {
                lVar7 = lVar7 + 1;
              } while (local_248[lVar7] != '\0');
              local_240 = (int)lVar7 + 1;
              local_238 = &local_2c8;
              local_23c = 0;
              local_228 = (uint *)0x140006fe0;
              local_2c8 = 0x103;
              local_230 = 4;
              local_220 = 0x15;
              _tlgWriteTransfer_EtwWriteTransfer
                        ((ulonglong)local_240,&DAT_14000a7c5,4,param_4,7,local_288);
            }
            plVar8 = (longlong *)*plVar8;
          } while (plVar8 != plVar9);
          plVar11 = local_298[0];
        }
        ExReleaseFastMutex(puVar12 + 0x32);
        ExReleaseFastMutex(plVar11);
        puVar12 = (undefined8 *)*puVar12;
      } while ((undefined8 **)puVar12 != &BatteryListHead);
    }
    KeReleaseGuardedMutex(&BatteryListMutex);
    uVar4 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      KeAcquireGuardedMutex(&PowerAdapterMutex);
      lVar7 = PowerAdapter;
      if (PowerAdapter != 0) {
        lVar3 = PowerAdapter + 0xe0;
        ExAcquireFastMutex(lVar3);
        if (5 < DAT_14000c080) {
          uVar6 = *(uint *)(lVar7 + 0x84);
          local_268 = (uint *)0x140006f10;
          if ((uVar6 & 1) == 0) {
            local_268 = (uint *)0x140006f28;
          }
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (*(char *)((longlong)local_268 + lVar5) != '\0');
          local_258 = (longlong *)0x140006f40;
          local_260 = (ulonglong)((int)lVar5 + 1);
          if ((uVar6 & 2) == 0) {
            local_258 = (longlong *)&s__;
          }
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (*(char *)((longlong)local_258 + lVar5) != '\0');
          local_248 = "REC Overridden";
          local_250 = (ulonglong)((int)lVar5 + 1);
          if ((uVar6 & 4) == 0) {
            local_248 = "-";
          }
          do {
            lVar10 = lVar10 + 1;
          } while (local_248[lVar10] != '\0');
          local_2c4 = *(uint *)(lVar7 + 0x88);
          local_240 = (int)lVar10 + 1;
          local_238 = &local_2c4;
          local_2c8 = *(uint *)(lVar7 + 0x8c);
          local_228 = &local_2c8;
          local_2c0 = CONCAT44(local_2c0._4_4_,*(undefined4 *)(lVar7 + 0x90));
          local_218 = &local_2c0;
          local_298[0] = *(longlong **)(lVar7 + 0x98);
          local_208 = local_298;
          local_2a0 = *(undefined8 *)(lVar7 + 0xa0);
          local_1f8 = (char *)&local_2a0;
          local_1e8 = local_1d0;
          local_1d8 = *(char **)(lVar7 + 0xb0);
          local_1d0[0] = (uint)*(ushort *)(lVar7 + 0xa8);
          local_23c = 0;
          local_230 = 4;
          local_220 = 4;
          local_210 = 4;
          local_200 = 8;
          local_1f0 = 8;
          local_1e0 = 2;
          local_1d0[1] = 0;
          _tlgWriteTransfer_EtwWriteTransfer(local_258,&DAT_14000a818,param_3,param_4,0xc,local_288)
          ;
        }
        BattCAdapterRundownIrpQueue((undefined8 *)(lVar7 + 0xc0),'\0');
        BattCAdapterRundownIrpQueue((undefined8 *)(lVar7 + 0xd0),'\x01');
        ExReleaseFastMutex(lVar3);
      }
      KeReleaseGuardedMutex(&PowerAdapterMutex);
    }
  }
  return;
}



===== _tlgEnableCallback @ 14001b0e0 =====

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



===== entry @ 14001d010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 14001d044 =====

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



===== BattCGetRegistryDwordValue @ 14001d078 =====

void BattCGetRegistryDwordValue(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong local_res8;
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong *local_50;
  undefined4 local_48;
  
  local_res8 = param_1 & 0xffffffff00000000;
  memset(local_78,0,0x70);
  local_50 = &local_res8;
  local_70 = 0x20;
  local_58 = 4;
  local_48 = 4;
  local_68 = param_2;
  local_60 = param_3;
  RtlQueryRegistryValuesEx
            (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",local_78,0,0);
  return;
}



===== BattCGetRegistryDwordValueEx @ 14001d10c =====

int BattCGetRegistryDwordValueEx
              (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,uint param_5,
              undefined8 param_6,uint *param_7)

{
  uint uVar1;
  int iVar2;
  uint local_res18 [4];
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  uint *local_60;
  undefined4 local_58;
  uint *local_50;
  undefined4 local_48;
  
  local_res18[0] = param_3;
  memset(local_78,0,0x70);
  local_50 = local_res18;
  local_58 = 4;
  local_48 = 4;
  local_70 = 0x20;
  local_60 = param_7;
  local_68 = param_2;
  iVar2 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",local_78,0,
                     0);
  if (-1 < iVar2) {
    uVar1 = *param_7;
    if (uVar1 == 0) {
      return iVar2;
    }
    if (uVar1 < param_4) {
      *param_7 = param_4;
      return -0x3fffffc2;
    }
    if (uVar1 <= param_5) {
      return iVar2;
    }
    iVar2 = -0x3fffffc4;
    local_res18[0] = param_5;
  }
  *param_7 = local_res18[0];
  return iVar2;
}



===== DllInitialize @ 14001d1e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(void)

{
  undefined2 uVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [56];
  char local_88 [4];
  uint local_84;
  int local_80;
  int local_7c;
  undefined8 local_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 local_68 [32];
  int *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x1d1e0  12  DllInitialize */
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_7c = 0;
  local_88[0] = '\0';
  wil_InitializeFeatureStaging();
  DAT_14000c308 = &BatteryListHead;
  BatteryListHead = &BatteryListHead;
  KeInitializeGuardedMutex(&BatteryListMutex);
  uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    KeInitializeGuardedMutex(&PowerAdapterMutex);
  }
  puVar6 = (undefined8 *)&BATTERY_ETW_PROVIDER;
  iVar4 = EtwRegister(&BATTERY_ETW_PROVIDER,BattCEtwTraceControlCallback,0,&BattCEtwHandle);
  puVar7 = auStack_c8;
  bVar3 = true;
  if (-1 < iVar4) {
    BattCEtwRegistered = 1;
    local_78 = *(undefined8 *)(PTR_DAT_14000c088 + -0x10);
    uStack_70 = *(undefined4 *)(PTR_DAT_14000c088 + -8);
    uStack_6c = *(undefined4 *)(PTR_DAT_14000c088 + -4);
    puVar7 = auStack_c8;
    if (DAT_14000c0a0 != (undefined8 *)0x0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar7 = auStack_c0;
    }
    _DAT_14000c0b0 = 0;
    _DAT_14000c0a8 = BattCTraceLoggingControlCallback;
    puVar6 = &local_78;
    *(undefined8 *)(puVar7 + -8) = 0x14001d2e9;
    iVar4 = EtwRegister(puVar6,_tlgEnableCallback,&DAT_14000c080,&DAT_14000c0a0);
    if (iVar4 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_14000c088;
      *(undefined8 *)(puVar7 + -8) = 0x14001d30e;
      puVar6 = DAT_14000c0a0;
      EtwSetInformation(DAT_14000c0a0,2,PTR_DAT_14000c088,uVar1);
    }
  }
  local_84 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001d326;
  BattCGetRegistryDwordValue((ulonglong)puVar6,L"BatteryMinPollRate",&local_84);
  if (local_84 == 0) {
LAB_14001d35a:
    BatteryPollRate = 1800000000;
  }
  else {
    BatteryPollRate = (ulonglong)local_84 * 10000000;
    if (BatteryPollRate < 200000000) {
      BatteryPollRate = 200000000;
    }
    else if (1800000000 < BatteryPollRate) goto LAB_14001d35a;
  }
  *(undefined4 *)(puVar7 + 0x20) = 1;
  uVar5 = 0x42;
  *(undefined8 *)(puVar7 + -8) = 0x14001d378;
  iVar4 = ZwPowerInformation(0x42,0,0,local_88);
  if ((iVar4 < 0) || (local_88[0] == '\0')) {
    uVar8 = 1800000000;
  }
  else {
    PlatformAoAc = '\x01';
    uVar8 = 36000000000;
  }
  local_84 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001d3af;
  BattCGetRegistryDwordValue(uVar5,L"BatteryMinBackupPollRate",&local_84);
  if (local_84 == 0) {
LAB_14001d3d7:
    BatteryBackupPollRateDc = uVar8;
  }
  else {
    uVar5 = (ulonglong)local_84 * 10000000;
    if (uVar5 < 200000000) {
      BatteryBackupPollRateDc = 200000000;
    }
    else {
      BatteryBackupPollRateDc = uVar5;
      if (uVar8 < uVar5) goto LAB_14001d3d7;
    }
  }
  local_84 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001d3f1;
  BattCGetRegistryDwordValue(uVar5,L"BatteryMinBackupPollRateAc",&local_84);
  if (local_84 == 0xffffffff) {
    BatteryBackupPollRateAc = BatteryBackupPollRateDc;
    goto LAB_14001d435;
  }
  if (local_84 != 0) {
    uVar5 = (ulonglong)local_84 * 10000000;
    if (uVar5 < 200000000) {
      BatteryBackupPollRateAc = 200000000;
      goto LAB_14001d435;
    }
    BatteryBackupPollRateAc = uVar5;
    if (uVar5 < 0x6b49d201) goto LAB_14001d435;
  }
  BatteryBackupPollRateAc = 1800000000;
LAB_14001d435:
  *(int **)(puVar7 + 0x30) = &local_7c;
  *(undefined4 *)(puVar7 + 0x20) = 1000;
  *(undefined8 *)(puVar7 + -8) = 0x14001d45f;
  BattCGetRegistryDwordValueEx
            (uVar5,L"BatteryFastestStatusNotifyUpdateIntervalMilliSec",1000,100,
             *(uint *)(puVar7 + 0x20),*(undefined8 *)(puVar7 + 0x28),*(uint **)(puVar7 + 0x30));
  uVar8 = (ulonglong)(uint)(local_7c * 10000);
  *(undefined8 *)(puVar7 + -8) = 0x14001d472;
  FastestStatusNotifyUpdateInterval = uVar8;
  uVar5 = Feature_Servicing_BatteryIdleResiliencyTimer__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 != 0) && (PlatformAoAc != '\0')) {
    uVar10 = 0;
    *(int **)(puVar7 + 0x30) = &BatteryIRTimerDurationRegistry;
    uVar9 = 0;
    *(undefined4 *)(puVar7 + 0x20) = 0xb4;
    *(undefined8 *)(puVar7 + -8) = 0x14001d4ad;
    BattCGetRegistryDwordValueEx
              (uVar8,L"IdleResiliencyTimerDurationInMinutes",0,0,*(uint *)(puVar7 + 0x20),
               *(undefined8 *)(puVar7 + 0x28),*(uint **)(puVar7 + 0x30));
    if (5 < DAT_14000c080) {
      if (((_DAT_14000c090 & 0x400000000000) == 0) ||
         ((DAT_14000c098 & 0x400000000000) != DAT_14000c098)) {
        bVar3 = false;
      }
      if (bVar3) {
        local_80 = BatteryIRTimerDurationRegistry;
        uVar8 = 4;
        local_48 = &local_80;
        local_40 = 4;
        local_38 = &local_78;
        *(undefined1 **)(puVar7 + 0x28) = local_68;
        *(undefined4 *)(puVar7 + 0x20) = 4;
        local_78 = 0x1000000;
        local_30 = 8;
        *(undefined8 *)(puVar7 + -8) = 0x14001d52e;
        _tlgWriteTransfer_EtwWriteTransfer
                  (4,&DAT_140008341,uVar9,uVar10,*(undefined4 *)(puVar7 + 0x20),
                   *(undefined8 **)(puVar7 + 0x28));
      }
    }
  }
  local_80 = 0;
  *(int **)(puVar7 + 0x30) = &AcDcUpdateStormQualificationCount;
  *(undefined4 *)(puVar7 + 0x20) = 100;
  *(undefined8 *)(puVar7 + -8) = 0x14001d557;
  BattCGetRegistryDwordValueEx
            (uVar8,L"BatteryAcDcUpdateStormQualificationCount",0,5,*(uint *)(puVar7 + 0x20),
             *(undefined8 *)(puVar7 + 0x28),*(uint **)(puVar7 + 0x30));
  *(int **)(puVar7 + 0x30) = &local_80;
  *(undefined4 *)(puVar7 + 0x20) = 60000;
  *(undefined8 *)(puVar7 + -8) = 0x14001d57a;
  BattCGetRegistryDwordValueEx
            (uVar8,L"BatteryAcDcUpdateStormPingWindowMilliSec",0,1000,*(uint *)(puVar7 + 0x20),
             *(undefined8 *)(puVar7 + 0x28),*(uint **)(puVar7 + 0x30));
  AcDcUpdateStormPingWindow = (ulonglong)(uint)(local_80 * 10000);
  AcDcUpdateStormCancellationTime = AcDcUpdateStormPingWindow + 50000000;
  if ((AcDcUpdateStormQualificationCount == 0) || (local_80 == 0)) {
    AcDcUpdateStormQualificationCount = 0;
    AcDcUpdateStormPingWindow = 0;
    AcDcUpdateStormCancellationTime = 0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x14001d5c5;
  return 0;
}



===== DriverEntry @ 14001d5ec =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== wil_InitializeFeatureStaging @ 14001d5f8 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001d67f;
    }
LAB_14001d6b9:
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
LAB_14001d67f:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001d6b9;
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
    goto LAB_14001d6b9;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000bbe7 < ppuVar3) goto LAB_14001d6b9;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001d67f;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001d70c =====

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
            if (&UNK_14000bbe7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001d7f6;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001d7f6;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001d7f6:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000bbe7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


