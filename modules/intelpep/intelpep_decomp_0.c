
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== PepAcceptDeviceNotification @ 140001040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte PepAcceptDeviceNotification
               (uint param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort *puVar1;
  longlong lVar2;
  undefined2 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  byte extraout_var_00;
  ulonglong uVar6;
  undefined7 extraout_var;
  longlong lVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  longlong lVar11;
  bool bVar12;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  bVar4 = 1;
  if (param_1 == 0x15) {
    return 1;
  }
  switch(param_1) {
  case 2:
    uVar5 = PepAbandonDevice(*param_2);
    *(undefined1 *)(param_2 + 1) = uVar5;
    break;
  case 3:
    bVar4 = PepRegisterDevice((ushort *)*param_2,param_2[1],(ulonglong *)param_2[2],param_2 + 3);
    *(int *)(param_2 + 4) = (int)CONCAT71(extraout_var,bVar4);
    return 1;
  case 4:
    PepUnregisterDevice((undefined4 *)*param_2);
    break;
  case 5:
    uVar10 = 1;
    puVar3 = (undefined2 *)*param_2;
    if ((PepDbgDeviceStateCallback != (code *)0x0) && (*(longlong *)(puVar3 + 0x10) != 0)) {
      if ((int)param_2[1] == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = (int)param_2[1] + -1;
      }
      (*PepDbgDeviceStateCallback)
                (*puVar3,*(undefined8 *)(puVar3 + 4),1,0xff,iVar9,
                 *(undefined1 *)((longlong)param_2 + 0xc));
    }
    lVar2 = *param_2;
    if (((PepPcieLtrOverrideEnabled != '\0') && (lVar2 != 0)) &&
       ((*(longlong **)(lVar2 + 0x30) != (longlong *)0x0 &&
        (lVar7 = **(longlong **)(lVar2 + 0x30), lVar7 != 0)))) {
      if (*(char *)((longlong)param_2 + 0xc) != '\0') {
        uVar10 = (undefined4)param_2[1];
      }
      *(undefined4 *)(lVar7 + 0x50) = uVar10;
      PepDiagRootPortDStateChange(lVar2,(longlong)param_2);
      return 0;
    }
  default:
    goto switchD_1400010aa_caseD_6;
  case 0x12:
    PepDeviceStarted((undefined4 *)*param_2);
    break;
  case 0x13:
    if ((PepDbgDeviceStateCallback != (code *)0x0) &&
       (puVar3 = (undefined2 *)*param_2, *(longlong *)(puVar3 + 0x10) != 0)) {
      (*PepDbgDeviceStateCallback)
                (*puVar3,*(undefined8 *)(puVar3 + 4),0,(int)param_2[1],
                 *(undefined4 *)((longlong)param_2 + 0xc),(char)param_2[2]);
    }
    puVar1 = (ushort *)*param_2;
    if ((((PepPcieLtrOverrideEnabled != '\0') && (puVar1 != (ushort *)0x0)) &&
        (*(longlong **)(puVar1 + 0x18) != (longlong *)0x0)) &&
       (lVar2 = **(longlong **)(puVar1 + 0x18), lVar2 != 0)) {
      if ((char)param_2[2] == '\0') {
        uVar10 = 0;
      }
      else {
        uVar10 = *(undefined4 *)((longlong)param_2 + 0xc);
      }
      *(undefined4 *)(lVar2 + 0x54) = uVar10;
      PepDiagRootPortComponentStateChange((longlong)puVar1,(longlong)param_2);
      if (PepSubsystemLtrStatusReportingSupported != '\0') {
        PepPcieCheckRootPortParentLtrStatus
                  (puVar1,lVar2,*(int *)((longlong)param_2 + 0xc),(ulonglong)*(byte *)(param_2 + 2))
        ;
      }
    }
    goto switchD_1400010aa_caseD_6;
  case 0x19:
    puVar8 = (undefined4 *)param_2[1];
    local_18 = *puVar8;
    uStack_14 = puVar8[1];
    uStack_10 = puVar8[2];
    uStack_c = puVar8[3];
    DbgPrintEx(0x92,3,"INTELPEP: crashdump device registered (%wZ)\n",&local_18);
    *param_2 = (longlong)PepPowerUpCrashdumpDevice;
    return 1;
  case 0x1a:
    lVar2 = *param_2;
    if ((*(longlong *)(lVar2 + 0x20) != 0) && (*(uint *)(param_2 + 2) != 0)) {
      uVar6 = (ulonglong)*(uint *)(param_2 + 2);
      puVar8 = (undefined4 *)param_2[1];
      lVar7 = 0;
      do {
        *puVar8 = *(undefined4 *)(lVar7 + *(longlong *)(lVar2 + 0x20));
        uVar6 = uVar6 - 1;
        puVar8 = puVar8 + 1;
        lVar7 = lVar7 + 8;
      } while (uVar6 != 0);
    }
    break;
  case 0x1b:
    lVar2 = *param_2;
    puVar8 = (undefined4 *)param_2[2];
    lVar7 = *(longlong *)(lVar2 + 0x20);
    if ((lVar7 != 0) && (*(uint *)(param_2 + 3) != 0)) {
      lVar11 = 0;
      uVar6 = (ulonglong)*(uint *)(param_2 + 3);
      do {
        if ((*(int *)(lVar7 + lVar11) == 0) || (*(int *)(lVar7 + lVar11) == 1)) {
          *puVar8 = *(undefined4 *)(lVar7 + 4 + lVar11);
          lVar7 = *(longlong *)(lVar2 + 0x20);
        }
        lVar11 = lVar11 + 8;
        puVar8 = puVar8 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    break;
  case 0x23:
    uVar6 = PepGetDebuggerTransitionRequirements(*(uint *)(param_2 + 1),(void *)param_2[2]);
    bVar4 = (byte)(uVar6 >> 0x1f) & 1 ^ 1;
    break;
  case 0x24:
    if (PepSubsystemAccountingSource != 0) goto switchD_1400010aa_caseD_25;
    LOCK();
    bVar12 = PepDbgInterfaceInUse == 0;
    if (bVar12) {
      PepDbgInterfaceInUse = 0;
    }
    UNLOCK();
    if (((bVar12) || (PepDbgSubsystemQueryCallback == (code *)0x0)) ||
       (PepDebugInterfaceV2Supported == '\0')) {
      uVar6 = PepSubsystemAccountingInit();
      if ((int)uVar6 < 0) {
        uVar6 = Pepv2SubsystemAccountingInit();
        if ((int)uVar6 < 0) {
          PepSubsystemAccountingSource = 4;
          goto LAB_140001172;
        }
        PepSubsystemAccountingSource = 3;
      }
      else {
        PepSubsystemAccountingSource = 2;
      }
      param_3 = 0;
      KeSetEvent(&PepSubsystemCounterAccountingInitFinished,0);
    }
    else {
      PepSubsystemAccountingSource = 1;
    }
    goto LAB_140001172;
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
switchD_1400010aa_caseD_25:
LAB_140001172:
    if (PepSubsystemAccountingSource - 2U < 2) {
      uVar6 = PepSubsystemQuery((undefined8 *)(ulonglong)param_1,(int *)param_2,param_3,param_4);
      if (-1 < (int)uVar6) {
        return 1;
      }
    }
    else if (PepSubsystemAccountingSource == 1) {
      LOCK();
      bVar12 = PepDbgInterfaceInUse == 0;
      if (bVar12) {
        PepDbgInterfaceInUse = 0;
      }
      UNLOCK();
      if (((bVar12) || (PepDbgSubsystemQueryCallback == (code *)0x0)) ||
         (PepDebugInterfaceV2Supported == '\0')) {
        bVar4 = 0xc0;
      }
      else {
        (*PepDbgSubsystemQueryCallback)(param_1,param_2);
        bVar4 = extraout_var_00;
      }
      return bVar4 >> 7 ^ 1;
    }
switchD_1400010aa_caseD_6:
    bVar4 = 0;
    break;
  case 0x90:
    bVar4 = PepPrepareDevice(param_2);
    *(byte *)(param_2 + 1) = bVar4;
    return 1;
  }
  return bVar4;
}



===== PepSubsystemQuery @ 1400014a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PepSubsystemQuery(undefined8 *param_1,int *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  int local_res8 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  puVar6 = PepPcieLtrOverrideSkipTelemetry;
  uVar7 = 0xc00000bb;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = (int)param_1;
  if (iVar1 == 0x27) {
    if (*param_2 != PepDripsIndex) {
      return 0xc00000bb;
    }
    if (PepCurrentStandbySessionStartTime != PepLastStandbySessionStartTime) {
      PepCurrentStandbySessionStartTime = PepLastStandbySessionStartTime;
      PepSubsystemLogTelemetry(param_1,param_2,0xc00000bb);
    }
    iVar1 = **(int **)(param_2 + 2);
    if ((iVar1 - 4U & 0xfffffffb) == 0) {
      uVar7 = PepSubsystemUpdateBlockingTimePwrGatingDomains((longlong)param_2);
    }
    else if (iVar1 == 2) {
      uVar7 = PepSubsystemQueryLtrBlockingTime((longlong)param_2);
    }
    else if (iVar1 == 0xb) {
      uVar7 = PepSubsystemQueryPciLinkBlockingTime((longlong)param_2);
    }
    else if (iVar1 == 3) {
      uVar7 = PepSubsystemQueryPkgcDbgBlockingTime((longlong)param_2);
    }
    else {
      lVar4 = *(longlong *)(*(int **)(param_2 + 2) + 2);
      if ((((PepSubsystemIsKabyLake != '\0') && (PepWoVEnabled != '\0')) &&
          (6 < PepSubsystemHwDripsIndex)) &&
         ((*(int *)(lVar4 + 0x14) == 7 && (*(longlong *)(PepSubsystemHwDripsInfo + 0x80) == 0)))) {
        *(undefined8 *)(lVar4 + 0x80) = *(undefined8 *)(PepSubsystemDeepestPkgStateInfo + 0x80);
      }
      uVar7 = *(ulonglong *)(lVar4 + 0x80);
      if (((*(uint *)(lVar4 + 0x10) & 1) != 0) && (PepSubsystemSlpS0Info != 0)) {
        if (*(ulonglong *)(PepSubsystemSlpS0Info + 0x80) < uVar7) {
          uVar7 = uVar7 - *(ulonglong *)(PepSubsystemSlpS0Info + 0x80);
        }
        else {
          uVar7 = 0;
        }
      }
    }
    *(ulonglong *)(param_2 + 6) = uVar7;
    return 0;
  }
  if (iVar1 == 0x24) {
    iVar1 = 0;
    local_res8[0] = 0;
    if (*param_2 != PepDripsIndex) {
      return 0xc00000bb;
    }
    uVar5 = 0;
    if (PepSubsystemAccountingCount != 0) {
      do {
        lVar4 = (ulonglong)uVar5 * 0xd8 + PepSubsystemAccountingInfo;
        iVar9 = *(int *)(lVar4 + 0x14);
        if ((iVar9 - 4U & 0xfffffffb) == 0) {
          if (6 < PepSubsystemHwDripsIndex) {
            PepSubsystemQueryPowerGatingDomains(lVar4,local_res8);
            iVar1 = local_res8[0];
          }
        }
        else if (iVar9 == 2) {
          local_res8[0] = PepSubsystemQueryLtrCount(lVar4);
          local_res8[0] = iVar1 + local_res8[0];
          iVar1 = local_res8[0];
        }
        else {
          uVar2 = *(uint *)(lVar4 + 0x10) & 2;
          if (iVar9 == 0xb) {
            if (uVar2 != 0) {
              local_res8[0] = PepSubsystemQueryPciLinkCount(lVar4);
              local_res8[0] = iVar1 + local_res8[0];
              iVar1 = local_res8[0];
            }
          }
          else if (uVar2 != 0) {
            local_res8[0] = iVar1 + 1;
            iVar1 = local_res8[0];
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < PepSubsystemAccountingCount);
    }
    param_2[1] = iVar1;
    return 0;
  }
  if (iVar1 != 0x25) {
    if (iVar1 != 0x26) {
      return 0xc00000bb;
    }
    if (*param_2 != PepDripsIndex) {
      return 0xc00000bb;
    }
    PepLastStandbySessionStartTime = _DAT_fffff78000000014;
    PepSubsystemTotalSwDripsResidency = 0;
    PepSubsystemInvalidSessionBitMask = 0;
    PepDripsTransitionCount = 0;
    if ((PepPcieLtrOverrideEnabled != '\0') &&
       (PepPcieLtrOverrideSkipTelemetry != (undefined8 *)0x0)) {
      *PepPcieLtrOverrideSkipTelemetry = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      puVar6[5] = 0;
      puVar6[6] = 0;
    }
    uVar5 = PepSubsystemAccountingCount;
    if ((PepPciePchLtrOvrMboxEnabled != '\0') && (PepPciePchLtrOvrMboxDisabledBootSession == '\0'))
    {
      _DAT_140087f60 = 0;
      _PepPcieLtrOvrMbExitResponseBuckets = 0;
      uRam0000000140087ea8 = 0;
      _DAT_140087ec0 = 0;
      _DAT_140087eb0 = 0;
      uRam0000000140087eb8 = 0;
      _PepPcieLtrOvrMbEnterResponseBuckets = 0;
      uRam0000000140087f48 = 0;
      _DAT_140087f50 = 0;
      uRam0000000140087f58 = 0;
    }
    uVar7 = 0;
    if (PepSubsystemAccountingCount != 0) {
      piVar8 = (int *)(PepSubsystemAccountingInfo + 0x14);
      do {
        iVar9 = (int)uVar7;
        iVar1 = *piVar8;
        piVar8[0x1b] = 0;
        piVar8[0x1c] = 0;
        if ((iVar1 - 4U & 0xfffffffb) == 0) {
          PepSubsystemResetPowerGatingDomains(uVar7 * 0xd8 + PepSubsystemAccountingInfo);
        }
        else if (iVar1 == 2) {
          PepSubsystemResetLtrCounters(uVar7 * 0xd8 + PepSubsystemAccountingInfo);
        }
        else if (iVar1 == 3) {
          PepSubsystemResetDebugPkgCounters(uVar7 * 0xd8 + PepSubsystemAccountingInfo);
        }
        else if (iVar1 == 0xb) {
          PepSubsystemResetPciLinkAccounting(uVar7 * 0xd8 + PepSubsystemAccountingInfo);
        }
        uVar7 = (ulonglong)(iVar9 + 1U);
        piVar8 = piVar8 + 0x36;
      } while (iVar9 + 1U < uVar5);
    }
    if (PepSubsystemEnableDebugPkgCounters != '\0') {
      _PepSubsystemStartCmdTimeAccounting = 0;
      uRam0000000140087928 = 0;
      _PepSubsystemStopCmdTimeAccounting = 0;
      uRam0000000140087950 = 0;
    }
    if (PepSubsystemEnableDebugPchCounters == '\0') {
      return 0;
    }
    uVar3 = PepSubsystemEnableEnergyReporting(PepSubsystemEnergyReportingContext);
    if ((int)uVar3 < 0) {
      PepSubsystemEnableDebugPchCounters = '\0';
    }
    PepDiagLogEnergyReportingCapabilities(PepSubsystemEnergyReportingContext,param_2,0,param_4);
    return 0;
  }
  if (*param_2 != PepDripsIndex) {
    return 0xc00000bb;
  }
  local_res8[0] = 0;
  uVar5 = 0;
  do {
    if (PepSubsystemAccountingCount <= uVar5) {
      return uVar7;
    }
    puVar6 = (undefined8 *)((ulonglong)uVar5 * 0xd8 + PepSubsystemAccountingInfo);
    puVar10 = (undefined4 *)((ulonglong)uVar5 * 0x10 + PepSubsystemAccountingHandle);
    iVar1 = *(int *)((longlong)puVar6 + 0x14);
    if ((iVar1 - 4U & 0xfffffffb) == 0) {
      if (PepSubsystemHwDripsIndex < 7) goto LAB_140001940;
      uVar7 = PepSubsystemUpdatePowerGatingDomainsBlockers
                        (puVar10,(longlong)puVar6,(longlong)param_2,local_res8);
      iVar1 = (int)uVar7;
joined_r0x00014000193a:
      uVar7 = uVar7 & 0xffffffff;
      if (iVar1 == 0) {
        return uVar7;
      }
    }
    else {
      if (iVar1 == 2) {
        uVar7 = PepSubsystemQueryLtrBlockerInfo(puVar10,puVar6,(longlong)param_2,local_res8);
        iVar1 = (int)uVar7;
        goto joined_r0x00014000193a;
      }
      if (iVar1 == 0xb) {
        if ((*(uint *)(puVar6 + 2) & 2) != 0) {
          uVar7 = PepSubsystemQueryPciLinkBlockerInfo
                            (puVar10,(longlong)puVar6,(longlong)param_2,local_res8);
          iVar1 = (int)uVar7;
          goto joined_r0x00014000193a;
        }
      }
      else if (((*(uint *)(puVar6 + 2) & 2) != 0) &&
              (local_res8[0] = local_res8[0] + 1, local_res8[0] == param_2[1] + 1)) {
        RtlInitUnicodeString(&local_28,puVar6[1]);
        RtlCopyUnicodeString(param_2 + 4,&local_28);
        RtlInitUnicodeString(&local_28,*puVar6);
        RtlCopyUnicodeString(param_2 + 8,&local_28);
        *puVar10 = *(undefined4 *)((longlong)puVar6 + 0x14);
        *(undefined8 **)(puVar10 + 2) = puVar6;
        *(undefined4 **)(param_2 + 2) = puVar10;
        return 0;
      }
    }
LAB_140001940:
    uVar5 = uVar5 + 1;
  } while( true );
}



===== PepDiagRootPortDStateChange @ 140001a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagRootPortDStateChange(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined **local_90;
  int local_88;
  uint local_84 [3];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  int *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (5 < DAT_1400340a0) {
    local_48 = *(wchar_t **)(param_1 + 8);
    if (local_48 == (wchar_t *)0x0) {
      local_48 = L"";
      local_40 = 2;
    }
    else {
      lVar2 = -1;
      do {
        lVar1 = lVar2 + 1;
        lVar2 = lVar2 + 1;
      } while (local_48[lVar1] != L'\0');
      local_40 = (int)lVar2 * 2 + 2;
    }
    local_88 = *(int *)(param_2 + 8) + -1;
    local_3c = 0;
    local_38 = &local_88;
    local_84[0] = (uint)*(byte *)(param_2 + 0xc);
    local_28 = local_84;
    local_74 = 5;
    local_68 = PTR_DAT_1400340a8;
    local_70 = 0;
    local_30 = 4;
    local_20 = 4;
    local_78 = 0xb000000;
    local_60 = (uint)*(ushort *)PTR_DAT_1400340a8;
    local_58 = &DAT_14002eaad;
    local_5c = 2;
    local_50 = 0x3a;
    local_4c = 1;
    local_84[1] = 0x349b;
    local_90 = &local_68;
    local_98 = 5;
    EtwWriteTransfer(DAT_1400340c0,&local_78,0,0);
  }
  return;
}



===== PepSubsystemEnableEnergyReporting @ 140001b60 =====

undefined8 PepSubsystemEnableEnergyReporting(undefined8 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined8 uVar3;
  uint local_res8 [2];
  undefined8 local_res10;
  ulonglong local_res18;
  
  local_res18 = 0;
  local_res10 = 0;
  local_res8[0] = 0;
  local_res8[1] = 0;
  if (param_1 == (undefined8 *)0x0) {
    return 0xc0000001;
  }
  piVar1 = (int *)param_1[1];
  PepReadRegisterWithBus((int *)*param_1,0,(uint *)&local_res18);
  if ((local_res18 & 4) == 0) {
    uVar3 = 0xc0000001;
  }
  else {
    piVar2 = (int *)param_1[3];
    if (*(int *)((longlong)param_1 + 0x14) == 1) {
      if ((local_res18 & 0x400000) != 0) {
        return 0xc0000001;
      }
    }
    else if (*(int *)((longlong)param_1 + 0x14) == 2) {
      PepReadRegisterWithBus(piVar2,0,local_res8);
      local_res8[0] = local_res8[0] | *(uint *)(param_1 + 4);
      PepWriteRegisterWithBus(piVar2,0,(undefined8 *)local_res8);
    }
    PepReadRegisterWithBus(piVar1,0,(uint *)&local_res10);
    local_res10 = CONCAT44(local_res10._4_4_,(uint)local_res10 | *(uint *)(param_1 + 2));
    PepWriteRegisterWithBus(piVar1,0,&local_res10);
    uVar3 = 0;
  }
  return uVar3;
}



===== PepNotifyPpmQueryPlatformStateResidencies @ 140001c50 =====

void PepNotifyPpmQueryPlatformStateResidencies(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar1 = 0;
  lVar3 = DAT_140087710;
  if (PepNumPlatformStates == 0) {
    lVar3 = 0;
  }
  if (*param_2 != 0) {
    do {
      uVar2 = (ulonglong)uVar1;
      uVar1 = uVar1 + 1;
      *(ulonglong *)(*(longlong *)(param_2 + 2) + 8 + uVar2 * 0x10) =
           (ulonglong)*(uint *)(lVar3 + 4 + uVar2 * 0x10);
      *(undefined8 *)(*(longlong *)(param_2 + 2) + uVar2 * 0x10) =
           *(undefined8 *)(lVar3 + 8 + uVar2 * 0x10);
    } while (uVar1 < *param_2);
  }
  DbgPrintEx(0x92,2,"INTELPEP: PPM_NOTIFY_PPM_QUERY_PLATFORM_STATE_RESIDENCIES\n");
  return;
}



===== PepPowerSettingChangeCallback @ 140001cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PepPowerSettingChangeCallback(longlong *param_1,int *param_2,int param_3)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepPlatformNotificationMutex,0);
  lVar3 = *param_1;
  lVar2 = 0x4b00e9d55d3e9a59 - lVar3;
  if (lVar2 == 0) {
    lVar2 = 0x486551ff34ffbda6 - param_1[1];
  }
  if (((lVar2 == 0) && (param_3 == 4)) && (param_2 != (int *)0x0)) {
    if (PepAcDcPowerState != *param_2) {
      PepAcDcPowerState = *param_2;
    }
  }
  else {
    lVar2 = 0x43cee09b307bcc77 - lVar3;
    if (lVar2 == 0) {
      lVar2 = -0x58fb04908ab96873 - param_1[1];
    }
    if (((lVar2 == 0) && (param_3 == 4)) && (param_2 != (int *)0x0)) {
      PepSystemStandbyEntered = *param_2 != 0;
    }
    else {
      lVar2 = 0x47a0704a6fe69556 - lVar3;
      if (lVar2 == 0) {
        lVar2 = 0x47da6f938dc2248f - param_1[1];
      }
      if (((lVar2 == 0) && (param_3 == 4)) && (param_2 != (int *)0x0)) {
        if (PepConsoleDisplayState != *param_2) {
          PepConsoleDisplayState = *param_2;
        }
      }
      else {
        lVar3 = 0x4344b427786e8a1d - lVar3;
        if (lVar3 == 0) {
          lVar3 = -0x564123f418f6f86e - param_1[1];
        }
        if (((lVar3 == 0) && (param_3 == 4)) && (param_2 != (int *)0x0)) {
          PepGlobalUserPresence = *param_2;
        }
      }
      if ((PepConsoleDisplayState == 0) && (PepGlobalUserPresence == 2)) {
        PepSystemUserIdle = '\x01';
      }
      else {
        PepSystemUserIdle = '\0';
      }
    }
  }
  if ((PepPlatformNotifyWorkItemQueued == '\0') &&
     ((PepSystemUserIdle != PepFirmwareUserIdle ||
      (PepSystemStandbyEntered != PepFirmwareStandbyEntered)))) {
    PepPlatformIdleVetoEvent(3,'\x01');
    PepPlatformNotifyWorkItemQueued = '\x01';
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepPlatformNotificationMutex);
    pcVar1 = *(code **)(WdfFunctions_01015 + 0xbe0);
    uVar4 = PepPlatformNotificationWorkItem;
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x9d0);
    uVar4 = PepPlatformNotificationMutex;
  }
  (*pcVar1)(WdfDriverGlobals,uVar4);
  return 0;
}



===== PepPlatformNotificationWorker @ 140001ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPlatformNotificationWorker(void)

{
  int iVar1;
  char cVar2;
  
  do {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepPlatformNotificationMutex,0);
    iVar1 = -1;
    if (PepPlatformAoAc == '\0') {
      iVar1 = (uint)(PepSystemUserIdle != PepFirmwareUserIdle) * 2 + -1;
      if (iVar1 == 1) {
LAB_140002013:
        PepFirmwareUserIdle = PepSystemUserIdle;
        cVar2 = PepSystemUserIdle;
      }
      else {
LAB_140001f73:
        cVar2 = '\0';
        if (iVar1 == -1) {
          PepPlatformNotifyWorkItemQueued = 0;
          PepPlatformIdleVetoEvent(3,'\0');
          (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepPlatformNotificationMutex);
          return;
        }
      }
    }
    else {
      if (PepSystemStandbyEntered == PepFirmwareStandbyEntered) {
        if (PepSystemUserIdle == PepFirmwareUserIdle) goto LAB_140001f73;
        if (((PepSystemUserIdle != '\0') || (PepSystemStandbyEntered == '\0')) ||
           (PepPlatformStandbyNotifySupported == '\0')) goto LAB_14000200e;
        PepSystemStandbyEntered = '\0';
      }
      else if (((PepSystemStandbyEntered != '\0') && (PepSystemUserIdle == '\0')) &&
              (PepPlatformUserIdleNotifySupported != '\0')) {
        PepSystemUserIdle = '\x01';
LAB_14000200e:
        iVar1 = 1;
        goto LAB_140002013;
      }
      iVar1 = 0;
      PepFirmwareStandbyEntered = PepSystemStandbyEntered;
      cVar2 = PepSystemStandbyEntered;
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepPlatformNotificationMutex);
    PepAcpiPlatformEntryExitNotify(iVar1,cVar2);
  } while( true );
}



===== PepAcpiPlatformEntryExitNotify @ 140002030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepAcpiPlatformEntryExitNotify(int param_1,char param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  longlong local_res18;
  
  lVar3 = 0;
  local_res18 = 0;
  uVar2 = PepWdfDevice;
  puVar1 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  iVar4 = -0x3fffffff;
  if (param_1 == 0) {
    iVar4 = 6 - (uint)(param_2 != '\0');
  }
  else {
    if (param_1 != 1) goto LAB_14000209f;
    iVar4 = 4 - (uint)(param_2 != '\0');
  }
  iVar4 = PepAcpiEval_DSM(puVar1,uVar2,iVar4,&local_res18);
  lVar3 = local_res18;
LAB_14000209f:
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x49504550);
  }
  return iVar4;
}



===== PepAcpiEval_DSM @ 1400020f0 =====

int PepAcpiEval_DSM(undefined8 *param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 local_res10 [2];
  longlong local_28 [2];
  
  local_res10[0] = 0;
  piVar2 = (int *)ExAllocatePool2(0x40,0x48,0x49504550);
  if (piVar2 == (int *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    uVar4 = 0x10;
    *piVar2 = 0x43696541;
    piVar2[3] = 4;
    piVar2[1] = 0x4d53445f;
    piVar2[2] = 0x48;
    piVar2[4] = 0x100002;
    memcpy_s(piVar2 + 5,0x10,&GUID_INTELPEP_DSM,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)piVar2 + 0x12);
    if (*(ushort *)((longlong)piVar2 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined8 *)((longlong)piVar2 + uVar3 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)piVar2 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)piVar2 + uVar3 + 0x20) = param_3;
    *(undefined8 *)((longlong)piVar2 + uVar3 + 0x24) = 0x40003;
    local_28[0] = 0;
    iVar1 = PepAcpiEvaluateMethod(param_1,uVar4,piVar2,local_28,local_res10);
    if (-1 < iVar1) {
      *param_4 = local_28[0];
    }
    ExFreePoolWithTag(piVar2,0x49504550);
  }
  return iVar1;
}



===== PepAcpiEvaluateMethod @ 140002220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepAcpiEvaluateMethod
              (undefined8 *param_1,undefined8 param_2,int *param_3,longlong *param_4,
              undefined4 *param_5)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  longlong local_res18 [2];
  ulonglong local_58;
  longlong local_50;
  ulonglong local_48;
  ulonglong local_40;
  int *local_38;
  int local_30;
  undefined4 local_2c;
  
  local_res18[0] = 0;
  local_40 = (ulonglong)(uint)local_40;
  local_58 = (ulonglong)(uint)local_58;
  if (param_3 == (int *)0x0) {
    iVar3 = -0x3fffff11;
  }
  else {
    iVar3 = *param_3;
    if (iVar3 == 0x43696541) {
      iVar3 = param_3[2];
    }
    else if (iVar3 == 0x42696541) {
      iVar3 = 8;
    }
    else if (iVar3 == 0x49696541) {
      iVar3 = 0xc;
    }
    else {
      if (iVar3 != 0x53696541) {
        iVar3 = -0x3fffff10;
        goto LAB_14000225e;
      }
      iVar3 = param_3[2] + 0xf;
    }
    lVar2 = ExAllocatePool2(0x40,0x1000,0x49504550);
    if (lVar2 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      local_40 = 1;
      local_2c = 0;
      local_58 = 1;
      local_48 = 0x1000;
      local_50 = lVar2;
      local_38 = param_3;
      local_30 = iVar3;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                        (WdfDriverGlobals,*param_1,0,0x32c004,&local_40,&local_58,0,local_res18);
      if (iVar3 == -0x7ffffffb) {
        uVar1 = *(uint *)(lVar2 + 4);
        ExFreePoolWithTag(lVar2,0x49504550);
        lVar2 = ExAllocatePool2(0x40,uVar1,0x49504550);
        if (lVar2 == 0) {
          iVar3 = -0x3fffff66;
          goto LAB_14000225e;
        }
        local_58 = 1;
        local_48 = (ulonglong)uVar1;
        local_50 = lVar2;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                          (WdfDriverGlobals,*param_1,0,0x32c004,&local_40,&local_58,0,local_res18);
      }
      if (-1 < iVar3) {
        if (local_res18[0] != 0) {
          *param_4 = lVar2;
          goto LAB_14000225e;
        }
        iVar3 = -0x3ffffffe;
      }
      ExFreePoolWithTag(lVar2,0x49504550);
    }
  }
LAB_14000225e:
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = (undefined4)local_res18[0];
  }
  return iVar3;
}



===== PepPlatformIdleVetoEvent @ 140002490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPlatformIdleVetoEvent(int param_1,char param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepVetoMutex,0);
  pcVar1 = DAT_1400877c0;
  if (PepBootVetoesEnumerated == '\0') {
    if (param_2 == '\0') {
      iVar2 = *(int *)(&Microsoft_Windows_Kernel_PepEnableBits + (longlong)param_1 * 4) + -1;
    }
    else {
      iVar2 = *(int *)(&Microsoft_Windows_Kernel_PepEnableBits + (longlong)param_1 * 4) + 1;
    }
    *(int *)(&Microsoft_Windows_Kernel_PepEnableBits + (longlong)param_1 * 4) = iVar2;
  }
  else {
    uVar3 = 0;
    if (PepNumPlatformStates != 0) {
      do {
        (*pcVar1)(*(undefined8 *)(PepProcessorContext + 0x50),uVar3,param_1,param_2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < PepNumPlatformStates);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepVetoMutex);
  return;
}



===== PepNotifyPpmQueryPlatformState @ 140002570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepNotifyPpmQueryPlatformState(longlong param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  puVar1 = param_2 + 2;
  puVar3 = (uint *)PepGetPlatformStateInfo(*param_2);
  uVar7 = 0;
  puVar1[0] = 0;
  puVar1[1] = 0;
  bVar6 = 10;
  param_2[5] = *puVar3;
  param_2[6] = puVar3[1];
  lVar8 = *(longlong *)(param_1 + 0x28);
  if (lVar8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x58),0);
    for (bVar4 = 0; bVar6 = 10, bVar4 < 10; bVar4 = bVar4 + 1) {
      if (*(uint *)(lVar8 + 0x60 + (ulonglong)bVar4 * 8) == puVar3[2]) {
        bVar6 = bVar4;
        break;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x58));
  }
  param_2[7] = param_2[8];
  uVar2 = 0;
  *(byte *)(param_2 + 4) = bVar6;
  if (PepKnownDeviceCount != 0) {
    do {
      lVar8 = (ulonglong)uVar2 * 0x38 + PepKnownDeviceList;
      if ((*(char *)(lVar8 + 0x18) != '\0') && (**(char **)(lVar8 + 0x28) == '\0')) {
        lVar5 = uVar7 + 2;
        uVar7 = (ulonglong)((int)uVar7 + 1);
        *(undefined8 *)(puVar1 + lVar5 * 4) = *(undefined8 *)(lVar8 + 0x10);
        *(char *)(param_2 + lVar5 * 4 + 4) = (char)param_2[4];
        *(undefined2 *)((longlong)param_2 + lVar5 * 0x10 + 0x11) = 0x101;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < PepKnownDeviceCount);
  }
  return;
}



===== PepGetPlatformStateInfo @ 1400026a0 =====

longlong PepGetPlatformStateInfo(uint param_1)

{
  if (param_1 < PepNumPlatformStates) {
    return (ulonglong)param_1 * 0x60 + DAT_140087708;
  }
  return 0;
}



===== PepFindDeviceMatch @ 1400026d0 =====

longlong PepFindDeviceMatch(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t *pwVar3;
  uint uVar4;
  longlong lVar5;
  longlong local_res10;
  
  uVar4 = 0;
  local_res10 = 0;
  do {
    if (PepKnownDeviceCount <= uVar4) {
LAB_140002750:
      PepFindBccdListMatch(param_1,&local_res10);
      if ((local_res10 == 0) && (PepPlatformAoAc != '\0')) {
        PepDebuggerDeviceMatch(param_1,&local_res10);
      }
      return local_res10;
    }
    lVar5 = PepKnownDeviceList + (ulonglong)uVar4 * 0x38;
    pwVar3 = wcsrchr(*(wchar_t **)(lVar5 + 8),L'*');
    if (pwVar3 == (wchar_t *)0x0) {
      iVar1 = RtlCompareUnicodeString(lVar5,param_1,1);
LAB_140002737:
      if (iVar1 == 0) {
        local_res10 = PepKnownDeviceList + (ulonglong)uVar4 * 0x38;
        if (local_res10 != 0) {
          return local_res10;
        }
        goto LAB_140002750;
      }
    }
    else {
      uVar2 = (int)pwVar3 - *(int *)(lVar5 + 8);
      if (uVar2 <= *param_1) {
        uVar2 = uVar2 >> 1;
        iVar1 = RtlCompareUnicodeStrings
                          (*(undefined8 *)(lVar5 + 8),uVar2,*(undefined8 *)(param_1 + 4),uVar2,1);
        goto LAB_140002737;
      }
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



===== PepFindBccdListMatch @ 1400027d0 =====

void PepFindBccdListMatch(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (PepBccdList != (uint *)0x0) {
    for (uVar4 = 0; (uint)uVar4 < *PepBccdList; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
      lVar1 = *(longlong *)(PepBccdList + uVar4 * 2 + 2);
      iVar2 = RtlCompareUnicodeString(lVar1,param_1,1);
      if (iVar2 == 0) {
        lVar3 = *(longlong *)(lVar1 + 0x18);
        if (lVar3 == 0) {
          lVar3 = ExAllocatePool2(0x40,0x38,0x49504550);
          if (lVar3 == 0) {
            return;
          }
          *(undefined2 *)(lVar3 + 0x18) = 0;
          *(undefined8 *)(lVar3 + 0x20) = 0;
          RtlInitUnicodeString(lVar3,*(undefined8 *)(lVar1 + 8));
          *(longlong *)(lVar3 + 0x28) = lVar1;
          *(longlong *)(lVar1 + 0x18) = lVar3;
        }
        *param_2 = lVar3;
        return;
      }
    }
  }
  return;
}



===== PepDebuggerDeviceMatch @ 1400028b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepDebuggerDeviceMatch(ushort *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PCI_DEBUG_");
  if (((*param_1 < (ushort)local_18) ||
      (iVar1 = RtlCompareUnicodeStrings
                         (uStack_10,(ushort)local_18 >> 1,*(undefined8 *)(param_1 + 4),
                          (ushort)local_18 >> 1,1), iVar1 != 0)) ||
     (lVar2 = ExAllocatePool2(0x40,0x38,0x49504550), lVar2 == 0)) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
    if (*param_1 < *(ushort *)(lVar2 + 0x38)) {
      return;
    }
    iVar1 = RtlCompareUnicodeStrings
                      (*(undefined8 *)(lVar2 + 0x40),*(ushort *)(lVar2 + 0x38) >> 1,
                       *(undefined8 *)(param_1 + 4),*param_1 >> 1,1);
    if (iVar1 != 0) {
      return;
    }
    lVar2 = ExAllocatePool2(0x40,0x38,0x49504550);
    if (lVar2 == 0) {
      return;
    }
  }
  *param_2 = lVar2;
  return;
}



===== PepAcceptProcessorNotification @ 1400029e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PepAcceptProcessorNotification(undefined8 param_1,uint param_2,undefined8 param_3)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  ulonglong uVar2;
  
  if ((param_2 < 0x31) &&
     (in_RAX = 0, *(code **)(&PpmDispatchTable + (ulonglong)param_2 * 8) != (code *)0x0)) {
    uVar1 = (**(code **)(&PpmDispatchTable + (ulonglong)param_2 * 8))(param_1,param_3);
    uVar2 = CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
  }
  else {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  return uVar2;
}



===== PepDiagLogSlpS0DbgCounter @ 140002a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogSlpS0DbgCounter
               (wchar_t *param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,
               char param_5,undefined8 param_6)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_d8 [32];
  undefined4 uVar4;
  undefined1 local_a8;
  undefined1 local_a7 [7];
  undefined8 local_a0;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  longlong local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_5 == '\0') {
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_68,param_1);
    local_58 = local_a7;
    pbVar1 = &DAT_140030647;
    local_48 = &local_a8;
    local_38 = &local_a0;
    uVar4 = 6;
    local_a8 = uVar2;
    local_a7[0] = param_2;
    local_a0 = param_4;
  }
  else {
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_68,param_1);
    local_58 = &local_a8;
    pbVar1 = &DAT_14002e2cd;
    local_48 = local_a7;
    local_38 = local_98;
    local_a0 = param_6;
    local_28 = &local_a0;
    uVar4 = 7;
    local_20 = 8;
    local_a8 = param_2;
    local_a7[0] = uVar2;
    local_98[0] = param_4;
  }
  local_50 = 1;
  local_40 = 1;
  local_30 = 8;
  _tlgWriteTransfer_EtwWriteTransfer
            (0x1400340a0,pbVar1,CONCAT71(uVar3,uVar2),param_4,uVar4,local_88);
  return;
}



===== PepDiagLogCtaCounterTelemetry @ 140002b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogCtaCounterTelemetry(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined1 auStackY_a8 [32];
  undefined4 uVar3;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  longlong local_48 [2];
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  if (iVar1 == 0xe) {
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
    pbVar2 = &DAT_14002f8bc;
LAB_140002cb6:
    local_78 = param_1[0x10];
    local_38 = &local_78;
  }
  else {
    if (iVar1 == 1) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
      pbVar2 = &DAT_14003090e;
      goto LAB_140002cb6;
    }
    if (iVar1 == 0xc) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
      pbVar2 = &DAT_14002e22e;
      goto LAB_140002cb6;
    }
    if (iVar1 == 0xd) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
      pbVar2 = &DAT_14002ec3f;
      goto LAB_140002cb6;
    }
    if (iVar1 == 0x10) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
      local_70 = param_1[0x10];
      local_38 = &local_70;
      pbVar2 = &DAT_14002eae8;
      local_28 = &local_78;
      uVar3 = 5;
      local_20 = 8;
      local_78 = param_2;
      goto LAB_140002cda;
    }
    if (iVar1 != 0x12) {
      return;
    }
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
    local_70 = param_1[0x10];
    local_38 = &local_70;
    pbVar2 = &DAT_14002e738;
  }
  uVar3 = 4;
LAB_140002cda:
  local_30 = 8;
  _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,pbVar2,param_1,param_2,uVar3,local_68);
  return;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140002d10 =====

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
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,0,0,param_5,param_6);
  return;
}



===== PepDiagLogPkgCCounterTelemetry @ 140002dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPkgCCounterTelemetry(undefined8 *param_1,undefined8 param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStackY_108 [32];
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  uint local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined *local_a8;
  uint local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  longlong local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if (PepSubsystemEnableDebugPkgCounters != '\0') {
    puVar1 = (uint *)param_1[0x19];
    uVar2 = (ulonglong)*puVar1;
    uVar4 = (ulonglong)puVar1[1];
    uVar5 = puVar1[2];
    uVar6 = puVar1[3];
    if (5 < DAT_1400340a0) {
      _tlgCreate1Sz_wchar_t(local_88,(wchar_t *)*param_1);
      local_c8 = param_1[0x10];
      local_78 = &local_c8;
      local_68 = (undefined8 *)&local_d4;
      local_58 = &local_d0;
      local_70 = 8;
      local_48 = &local_cc;
      local_38 = &local_d8;
      local_28 = &local_c0;
      local_d4 = (undefined4)uVar2;
      local_60 = 4;
      local_d0 = (undefined4)uVar4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 8;
      local_d8 = uVar6;
      local_cc = uVar5;
      local_c0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002fc90,uVar2,uVar4,9,&local_a8);
    }
    lVar3 = param_1[3];
    if ((lVar3 != 0) && (5 < DAT_1400340a0)) {
      _tlgCreate1Sz_wchar_t(local_88,(wchar_t *)*param_1);
      local_c0 = *(undefined8 *)(lVar3 + 0x18);
      local_78 = &local_c0;
      local_68 = &local_c8;
      local_b4 = 5;
      local_a8 = PTR_DAT_1400340a8;
      local_70 = 8;
      local_60 = 8;
      local_b8 = 0xb000000;
      local_b0 = 0;
      local_a0 = (uint)*(ushort *)PTR_DAT_1400340a8;
      local_98 = &DAT_1400309b4;
      local_9c = 2;
      local_90 = 0x75;
      local_8c = 1;
      local_d8 = 0x349b;
      local_c8 = param_2;
      EtwWriteTransfer(DAT_1400340c0,&local_b8,0,0);
    }
  }
  return;
}



===== _tlgCreate1Sz_wchar_t @ 140002fe0 =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,wchar_t *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
    iVar2 = 2;
  }
  else {
    lVar3 = -1;
    do {
      lVar1 = lVar3 + 1;
      lVar3 = lVar3 + 1;
    } while (param_2[lVar1] != L'\0');
    iVar2 = (int)lVar3 * 2 + 2;
  }
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar2;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== McGenControlCallbackV2 @ 140003030 =====

void McGenControlCallbackV2
               (void *param_1,uint param_2,ulonglong param_3,int *param_4,undefined8 param_5,
               undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  byte bVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      param_3 = 0;
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        param_1 = *(void **)(param_7 + 0x30);
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        param_3 = (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2;
        memset(param_1,0,param_3);
      }
    }
    else if (param_2 == 1) {
      *(char *)(param_7 + 0x28) = (char)param_3;
      param_3 = 0;
      *(int **)(param_7 + 0x10) = param_4;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          bVar2 = *(byte *)(param_7 + 0x28);
          param_4 = (int *)(ulonglong)bVar2;
          uVar3 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + param_3 * 8);
          if (((bVar2 < *(byte *)(param_3 + *(longlong *)(param_7 + 0x40))) && (bVar2 != 0)) ||
             ((uVar3 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar3) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar3) != *(ulonglong *)(param_7 + 0x18))))))) {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (param_3 >> 5) * 4);
            *puVar1 = *puVar1 & ~(1 << ((byte)param_3 & 0x1f));
          }
          else {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (param_3 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)param_3 & 0x1f);
          }
          param_1 = (void *)(ulonglong)((uint)param_3 & 0x1f);
          uVar5 = (uint)param_3 + 1;
          param_3 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
    PepTraceControlCallback(param_1,(ulonglong)param_2,param_3,param_4);
  }
  return;
}



===== PepTraceControlCallback @ 140003160 =====

void PepTraceControlCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  undefined8 uVar1;
  
  if ((int)param_2 == 2) {
    PepTraceRundownDeviceConstraints('\0',param_2,param_3,(longlong)param_4);
    uVar1 = 0;
    PepTraceRundownComponentConstraints('\0',param_2,param_3,(undefined8 *)param_4);
    PepTraceRundownLtrSpxMap();
    PepPcieTreeConstraintsFromBios(uVar1,param_2,param_3,param_4);
  }
  return;
}



===== PepTraceRundownDeviceConstraints @ 140003190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepTraceRundownDeviceConstraints
               (char param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int *piVar8;
  ulonglong uVar9;
  undefined1 auStackY_c8 [32];
  int local_88;
  int local_84 [3];
  undefined8 local_78 [4];
  longlong local_58 [2];
  int *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (PepNumPlatformStates != 0) {
    uVar1 = PepNumPlatformStates * 8;
    uVar7 = 0x49504550;
    _Dst = (void *)ExAllocatePool2(0x40);
    if (_Dst != (void *)0x0) {
      if ((PepPcieGeneratedConstraintEnabled == '\0') &&
         (PepPcieGeneratedConstraintRCiEPEnabled == '\0')) {
        uVar9 = 0;
        if (PepKnownDeviceCount != 0) {
          do {
            lVar4 = uVar9 * 0x38 + PepKnownDeviceList;
            memset(_Dst,0,(ulonglong)uVar1);
            uVar6 = 0;
            if (PepNumPlatformStates != 0) {
              do {
                piVar8 = (int *)(uVar6 * 8 + (longlong)_Dst);
                *piVar8 = (int)uVar6;
                iVar2 = *(int *)(uVar6 * 8 + *(longlong *)(lVar4 + 0x20));
                iVar3 = 0;
                if (iVar2 != 0) {
                  iVar3 = iVar2 + -1;
                }
                piVar8[1] = iVar3;
                if (((param_1 != '\0') && (5 < DAT_1400340a0)) &&
                   (uVar7 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar7 != '\0')) {
                  _tlgCreate1Sz_wchar_t(local_58,*(wchar_t **)(lVar4 + 8));
                  local_88 = *piVar8;
                  local_48 = &local_88;
                  local_84[0] = piVar8[1];
                  local_38 = local_84;
                  local_40 = 4;
                  local_30 = 4;
                  _tlgWriteTransfer_EtwWriteTransfer
                            (0x1400340a0,&DAT_14002f2ed,piVar8,param_4,5,local_78);
                }
                uVar5 = (int)uVar6 + 1;
                uVar6 = (ulonglong)uVar5;
              } while (uVar5 < PepNumPlatformStates);
            }
            if ((param_1 == '\0') && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
              param_4 = *(longlong *)(lVar4 + 0x10);
              McTemplateK0pzqNR2_EtwWriteTransfer();
            }
            uVar5 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar5;
          } while (uVar5 < PepKnownDeviceCount);
        }
      }
      else {
        PepTraceRundownGeneratedDeviceConstraints(_Dst,param_1,uVar7,param_4);
      }
      ExFreePoolWithTag(_Dst,0x49504550);
    }
  }
  return;
}



===== PepTraceRundownGeneratedDeviceConstraints @ 1400033f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepTraceRundownGeneratedDeviceConstraints
               (void *param_1,char param_2,undefined8 param_3,longlong param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  uint uVar13;
  int *piVar14;
  ulonglong _Size;
  undefined1 auStackY_e8 [32];
  int local_a8;
  int local_a4;
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined8 local_70;
  longlong local_68 [2];
  int *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar11 = 0;
  _Size = (ulonglong)(PepNumPlatformStates * 8);
  if (PepKnownDeviceCount != 0) {
    do {
      lVar12 = uVar11 * 0x38 + PepKnownDeviceList;
      memset(param_1,0,_Size);
      uVar10 = 0;
      if (PepNumPlatformStates != 0) {
        do {
          piVar14 = (int *)(uVar10 * 8 + (longlong)param_1);
          *piVar14 = (int)uVar10;
          iVar1 = *(int *)(uVar10 * 8 + *(longlong *)(lVar12 + 0x20));
          iVar6 = 0;
          if (iVar1 != 0) {
            iVar6 = iVar1 + -1;
          }
          piVar14[1] = iVar6;
          if (((param_2 != '\0') && (5 < DAT_1400340a0)) &&
             (uVar5 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar5 != '\0')) {
            local_78 = &local_a0;
            local_a0 = 0x1000000;
            local_70 = 8;
            _tlgCreate1Sz_wchar_t(local_68,*(wchar_t **)(lVar12 + 8));
            local_a8 = *piVar14;
            local_58 = &local_a8;
            local_a4 = piVar14[1];
            local_48 = &local_a4;
            local_50 = 4;
            local_40 = 4;
            _tlgWriteTransfer_EtwWriteTransfer
                      (0x1400340a0,&DAT_14002db20,piVar14,param_4,6,local_98);
          }
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
        } while (uVar9 < PepNumPlatformStates);
      }
      if (((param_2 == '\0') && (param_4 = *(longlong *)(lVar12 + 0x10), param_4 != 0)) &&
         ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
        McTemplateK0pzqNR2_EtwWriteTransfer();
      }
      uVar9 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar9;
    } while (uVar9 < PepKnownDeviceCount);
  }
  if (param_2 == '\0') {
    if (PepPcieGeneratedConstraintEnabled != '\0') {
      ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock);
      for (puVar2 = PepPcieRootPortList; (undefined8 **)puVar2 != &PepPcieRootPortList;
          puVar2 = (undefined8 *)*puVar2) {
        lVar12 = puVar2[9];
        if (lVar12 == 0) {
          DbgPrintEx(0x92,0,
                     "INTELPEP: PepTraceRundownGeneratedDeviceConstraints: PcieRootPort 0x%p has empty registration info. Skipping this root port and children.\n"
                     ,puVar2);
        }
        else {
          memset(param_1,0,_Size);
          uVar9 = PepNumPlatformStates;
          uVar13 = 0;
          uVar7 = 0;
          if (PepNumPlatformStates != 0) {
            lVar8 = 0;
            do {
              *(uint *)(lVar8 + (longlong)param_1) = uVar7;
              lVar3 = *(longlong *)(lVar12 + 0x20);
              iVar1 = *(int *)(lVar3 + lVar8);
              if ((iVar1 == 1) && (*(int *)(lVar3 + 4 + lVar8) == 0)) {
                uVar13 = uVar13 + 1;
              }
              else if (iVar1 == 0) {
                *(undefined4 *)(lVar8 + 4 + (longlong)param_1) = 0;
              }
              else {
                *(int *)(lVar8 + 4 + (longlong)param_1) = iVar1 + -1;
              }
              uVar7 = uVar7 + 1;
              lVar8 = lVar8 + 8;
            } while (uVar7 < uVar9);
          }
          if ((uVar13 != uVar9) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
            McTemplateK0pzqNR2_EtwWriteTransfer();
          }
          for (puVar4 = (undefined8 *)puVar2[2]; puVar4 != puVar2 + 2;
              puVar4 = (undefined8 *)*puVar4) {
            lVar12 = puVar4[6];
            if (lVar12 == 0) {
              DbgPrintEx(0x92,0,
                         "INTELPEP: PepTraceRundownGeneratedDeviceConstraints: NULL Child End Point:0x%p hasempty registration info. Skipping.\n"
                         ,puVar4);
            }
            else if ((*(longlong *)(lVar12 + 0x20) != 0) &&
                    ((puVar4[3] == 0 || (*(int *)(puVar4[3] + 0x50) != 4)))) {
              memset(param_1,0,_Size);
              uVar9 = PepNumPlatformStates;
              uVar13 = 0;
              uVar7 = 0;
              if (PepNumPlatformStates != 0) {
                lVar8 = 0;
                do {
                  *(uint *)(lVar8 + (longlong)param_1) = uVar7;
                  iVar1 = *(int *)(lVar8 + *(longlong *)(lVar12 + 0x20));
                  if ((iVar1 == 1) && (*(int *)(lVar8 + 4 + *(longlong *)(lVar12 + 0x20)) == 0)) {
                    uVar13 = uVar13 + 1;
                  }
                  else if (iVar1 == 0) {
                    *(undefined4 *)(lVar8 + 4 + (longlong)param_1) = 0;
                  }
                  else {
                    *(int *)(lVar8 + 4 + (longlong)param_1) = iVar1 + -1;
                  }
                  uVar7 = uVar7 + 1;
                  lVar8 = lVar8 + 8;
                } while (uVar7 < uVar9);
              }
              if ((uVar13 != uVar9) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
                McTemplateK0pzqNR2_EtwWriteTransfer();
              }
            }
          }
        }
      }
      ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    }
    if (PepPcieGeneratedConstraintRCiEPEnabled != '\0') {
      PepTraceRunDownRCiEPGeneratedDeviceConstraints(param_1);
    }
  }
  return;
}



===== PepTraceRundownComponentConstraints @ 140003820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepTraceRundownComponentConstraints
               (char param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  longlong lVar2;
  void *_Dst;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStackY_f8 [32];
  undefined4 local_88;
  undefined4 local_84 [3];
  undefined8 local_78 [4];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  if (PepNumPlatformStates != 0) {
    uVar1 = PepNumPlatformStates * 8;
    uVar5 = 0x49504550;
    _Dst = (void *)ExAllocatePool2(0x40);
    if (_Dst != (void *)0x0) {
      if ((PepPcieGeneratedConstraintEnabled == '\0') &&
         (PepPcieGeneratedConstraintRCiEPEnabled == '\0')) {
        uVar4 = 0;
        if (PepKnownDeviceCount != 0) {
          do {
            puVar3 = (undefined *)0x0;
            puVar7 = (ushort *)((ulonglong)uVar4 * 0x38 + PepKnownDeviceList);
            puVar6 = (undefined4 *)(ulonglong)uVar1;
            memset(_Dst,0,(size_t)(ulonglong)uVar1);
            uVar9 = 0;
            if (PepNumPlatformStates != 0) {
              do {
                lVar2 = uVar9 * 8;
                *(int *)(lVar2 + (longlong)_Dst) = (int)uVar9;
                puVar6 = (undefined4 *)(lVar2 + (longlong)_Dst);
                puVar3 = *(undefined **)(puVar7 + 0x10);
                puVar6[1] = *(undefined4 *)(puVar3 + lVar2 + 4);
                if (*(int *)(puVar3 + lVar2) - 2U < 3) {
                  puVar6[1] = 0;
                }
                if ((param_1 != '\0') && (5 < DAT_1400340a0)) {
                  puVar3 = (undefined *)0x400000000000;
                  uVar5 = _tlgKeywordOn(0x1400340a0,0x400000000000);
                  if ((char)uVar5 != '\0') {
                    _tlgCreate1Sz_wchar_t(local_58,*(wchar_t **)(puVar7 + 4));
                    local_88 = *puVar6;
                    local_48 = &local_88;
                    puVar3 = &DAT_14002f392;
                    local_84[0] = puVar6[1];
                    local_38 = local_84;
                    local_40 = 4;
                    local_30 = 4;
                    _tlgWriteTransfer_EtwWriteTransfer
                              (0x1400340a0,&DAT_14002f392,puVar6,param_4,5,local_78);
                  }
                }
                uVar8 = (int)uVar9 + 1;
                uVar9 = (ulonglong)uVar8;
              } while (uVar8 < PepNumPlatformStates);
            }
            if ((param_1 == '\0') && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
              McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
                        ((ulonglong)(*puVar7 >> 1),puVar3,puVar6,param_4,
                         (char)*(undefined8 *)(puVar7 + 8));
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < PepKnownDeviceCount);
        }
      }
      else {
        PepTraceRundownGeneratedComponentConstraints(_Dst,param_1,uVar5,param_4);
      }
      ExFreePoolWithTag(_Dst,0x49504550);
    }
  }
  return;
}



===== PepTraceRundownGeneratedComponentConstraints @ 140003a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepTraceRundownGeneratedComponentConstraints
               (void *param_1,char param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  int *piVar5;
  longlong lVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  ulonglong uVar12;
  char *pcVar13;
  char *_Size;
  undefined1 auStackY_118 [32];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined8 local_70;
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar8 = 0;
  _Size = (char *)(ulonglong)(PepNumPlatformStates * 8);
  if (PepKnownDeviceCount != 0) {
    do {
      puVar10 = (ushort *)((ulonglong)uVar8 * 0x38 + PepKnownDeviceList);
      pcVar13 = _Size;
      memset(param_1,0,(size_t)_Size);
      uVar9 = 0;
      if (PepNumPlatformStates != 0) {
        do {
          lVar6 = (ulonglong)uVar9 * 8;
          *(uint *)(lVar6 + (longlong)param_1) = uVar9;
          pcVar13 = (char *)(lVar6 + (longlong)param_1);
          lVar1 = *(longlong *)(puVar10 + 0x10);
          *(undefined4 *)(pcVar13 + 4) = *(undefined4 *)(lVar1 + 4 + lVar6);
          if (*(int *)(lVar1 + lVar6) - 2U < 3) {
            pcVar13[4] = '\0';
            pcVar13[5] = '\0';
            pcVar13[6] = '\0';
            pcVar13[7] = '\0';
          }
          if (((param_2 != '\0') && (5 < DAT_1400340a0)) &&
             (uVar4 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar4 != '\0')) {
            local_78 = &local_a0;
            local_a0 = 0x1000000;
            local_70 = 8;
            _tlgCreate1Sz_wchar_t(local_68,*(wchar_t **)(puVar10 + 4));
            local_a8 = *(undefined4 *)pcVar13;
            local_58 = &local_a8;
            local_a4 = *(undefined4 *)(pcVar13 + 4);
            local_48 = &local_a4;
            local_50 = 4;
            local_40 = 4;
            _tlgWriteTransfer_EtwWriteTransfer
                      (0x1400340a0,&DAT_140030ac8,pcVar13,param_4,6,local_98);
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < PepNumPlatformStates);
      }
      if (((param_2 == '\0') && (lVar6 = *(longlong *)(puVar10 + 8), lVar6 != 0)) &&
         ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
        McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
                  ((ulonglong)(*puVar10 >> 1),lVar6,pcVar13,param_4,(char)lVar6);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < PepKnownDeviceCount);
  }
  if (param_2 == '\0') {
    if (PepPcieGeneratedConstraintEnabled != '\0') {
      ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock);
      for (puVar3 = PepPcieRootPortList; (undefined8 **)puVar3 != &PepPcieRootPortList;
          puVar3 = (undefined8 *)*puVar3) {
        puVar10 = (ushort *)puVar3[9];
        if (puVar10 == (ushort *)0x0) {
          param_4 = puVar3;
          DbgPrintEx(0x92,0,
                     "INTELPEP: PepTraceRundownGeneratedComponentConstraints: Root Port: 0x%p has emptyregistration info. Skipping.\n"
                    );
        }
        else {
          lVar6 = 0;
          pcVar13 = _Size;
          memset(param_1,0,(size_t)_Size);
          uVar8 = 0;
          uVar9 = 0;
          if (PepNumPlatformStates != 0) {
            do {
              lVar1 = (ulonglong)uVar9 * 8;
              *(uint *)(lVar1 + (longlong)param_1) = uVar9;
              lVar6 = *(longlong *)(puVar10 + 0x10);
              if (lVar6 == 0) {
                pcVar13 = 
                "INTELPEP: PepTraceRundownGeneratedComponentConstraints: Root Port: 0x%p Constraint Info is NULL. Skipping.\n"
                ;
                lVar6 = 0;
                param_4 = puVar3;
                DbgPrintEx(0x92);
              }
              else if ((*(int *)(lVar6 + lVar1) == 1) && (*(int *)(lVar6 + lVar1 + 4) == 0)) {
                uVar8 = uVar8 + 1;
              }
              else {
                *(undefined4 *)(lVar1 + 4 + (longlong)param_1) = *(undefined4 *)(lVar6 + lVar1 + 4);
                if (*(int *)(lVar6 + lVar1) - 2U < 3) {
                  *(undefined4 *)(lVar1 + 4 + (longlong)param_1) = 0;
                }
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < PepNumPlatformStates);
          }
          if ((uVar8 != PepNumPlatformStates) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)
             ) {
            McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
                      ((ulonglong)(*puVar10 >> 1),lVar6,pcVar13,param_4,
                       (char)*(undefined8 *)(puVar10 + 8));
          }
          for (puVar2 = (undefined8 *)puVar3[2]; puVar2 != puVar3 + 2;
              puVar2 = (undefined8 *)*puVar2) {
            puVar10 = (ushort *)puVar2[6];
            if (((puVar10 != (ushort *)0x0) && (*(longlong *)(puVar10 + 0x10) != 0)) &&
               ((puVar2[3] == 0 || (*(int *)(puVar2[3] + 0x50) != 4)))) {
              piVar7 = (int *)0x0;
              memset(param_1,0,(size_t)_Size);
              uVar8 = PepNumPlatformStates;
              param_4 = (undefined8 *)(ulonglong)PepNumPlatformStates;
              uVar9 = 0;
              uVar12 = 0;
              if (PepNumPlatformStates != 0) {
                piVar5 = (int *)((longlong)param_1 + 4);
                do {
                  piVar5[-1] = (int)uVar12;
                  piVar7 = (int *)((longlong)piVar5 +
                                  *(longlong *)(puVar10 + 0x10) + (-4 - (longlong)param_1));
                  if ((*piVar7 == 1) && (piVar7[1] == 0)) {
                    uVar9 = uVar9 + 1;
                  }
                  else {
                    *piVar5 = piVar7[1];
                    if (*piVar7 - 2U < 3) {
                      *piVar5 = 0;
                    }
                  }
                  uVar11 = (int)uVar12 + 1;
                  uVar12 = (ulonglong)uVar11;
                  piVar5 = piVar5 + 2;
                } while (uVar11 < uVar8);
              }
              if ((uVar9 != uVar8) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
                McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
                          ((ulonglong)(*puVar10 >> 1),piVar7,uVar12,param_4,
                           (char)*(undefined8 *)(puVar10 + 8));
              }
            }
          }
        }
      }
      ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    }
    if (PepPcieGeneratedConstraintRCiEPEnabled != '\0') {
      PepTraceRunDownRCiEPGeneratedComponentConstraints(param_1);
    }
  }
  return;
}



===== McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer @ 140003f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined4 uStack0000000000000060;
  undefined1 auStackY_118 [32];
  undefined4 local_e8 [2];
  undefined4 local_e0 [2];
  undefined4 local_d8 [2];
  undefined4 local_d0 [2];
  uint local_c8 [4];
  undefined8 local_b8 [2];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_a8 = local_e8;
  local_98 = &param_5;
  local_d0[0] = 0;
  local_88 = local_e0;
  local_78 = local_d8;
  local_68 = local_d0;
  local_d8[0] = 0;
  local_58 = local_c8;
  local_40 = PepNumPlatformStates * 8;
  local_38 = &uStack0000000000000060;
  local_20 = uStack0000000000000060 * 2;
  local_e0[0] = 0;
  local_e8[0] = 0;
  local_3c = 0;
  local_1c = 0;
  local_c8[0] = PepNumPlatformStates;
  local_a0 = 4;
  local_90 = 8;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_30 = 4;
  McGenEventWrite_EtwWriteTransfer
            ((ulonglong)PepNumPlatformStates,&POP_PEP_ETW_COMPONENT_RUNDOWN,param_3,10,local_b8);
  return;
}



===== McTemplateK0pzqNR2_EtwWriteTransfer @ 140004050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pzqNR2_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  wchar_t *in_stack_00000028;
  undefined1 auStackY_a8 [32];
  int local_78 [4];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  int *local_38;
  undefined8 local_30;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = local_res20;
  local_78[0] = PepNumPlatformStates;
  local_50 = 8;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_38 = local_78;
  local_3c = 0;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_20 = PepNumPlatformStates * 8;
  local_1c = 0;
  local_30 = 4;
  local_48 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&POP_PEP_ETW_DEVICE_RUNDOWN,L"NULL",5,local_68)
  ;
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004160 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140034038;
  if (DAT_140034038 == (ushort *)0x0) {
    uVar2 = 0;
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140034038;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(POP_PEP_ETW_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== PepTraceRundownLtrSpxMap @ 1400041d0 =====

void PepTraceRundownLtrSpxMap(void)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong *plVar10;
  ulonglong uVar11;
  int local_res8 [2];
  int local_res10 [2];
  int local_res18 [2];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  if (((PepSleepStudyEtwHandleRegistered != '\0') &&
      (uVar8 = (ulonglong)PepSubsystemLtrSpxCount, PepSubsystemLtrSpxCount != 0)) &&
     (PepSubsystemLtrSpxInfo != 0)) {
    iVar5 = 0;
    local_res18[0] = 0;
    if (PepSubsystemLtrSpxCount != 0) {
      piVar6 = (int *)(PepSubsystemLtrSpxInfo + 8);
      do {
        iVar5 = iVar5 + *piVar6;
        piVar6 = piVar6 + 6;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      local_res18[0] = iVar5;
    }
    iVar5 = local_res18[0] * 4 + 1;
    plVar3 = (longlong *)ExAllocatePool2(0x100,iVar5 * 0x10,0x49504550);
    uVar2 = PepSubsystemLtrSpxCount;
    if (plVar3 != (longlong *)0x0) {
      *plVar3 = (longlong)local_res18;
      plVar9 = plVar3 + 2;
      plVar3[1] = 4;
      if (uVar2 != 0) {
        puVar7 = (undefined8 *)(PepSubsystemLtrSpxInfo + 0x10);
        uVar8 = (ulonglong)uVar2;
        do {
          plVar1 = (longlong *)puVar7[-2];
          lVar4 = -1;
          uVar11 = (ulonglong)*(uint *)(puVar7 + -1);
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)(*plVar1 + lVar4 * 2) != 0);
          local_res8[0] = (int)lVar4;
          plVar10 = (longlong *)*puVar7;
          if (*(uint *)(puVar7 + -1) != 0) {
            do {
              plVar9[1] = 4;
              *plVar9 = (longlong)local_res8;
              plVar9[2] = *plVar1;
              lVar4 = -1;
              *(int *)(plVar9 + 3) = local_res8[0] * 2;
              *(undefined4 *)((longlong)plVar9 + 0x1c) = 0;
              do {
                lVar4 = lVar4 + 1;
              } while (*(short *)(*plVar10 + lVar4 * 2) != 0);
              local_res10[0] = (int)lVar4;
              plVar9[4] = (longlong)local_res10;
              plVar9[5] = 4;
              plVar9[6] = *plVar10;
              plVar10 = plVar10 + 1;
              *(int *)(plVar9 + 7) = local_res10[0] * 2;
              *(undefined4 *)((longlong)plVar9 + 0x3c) = 0;
              plVar9 = plVar9 + 8;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          puVar7 = puVar7 + 3;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      EtwWrite(PepSleepStudyEtwHandle,&SLEEPSTUDY_SUBSYSTEM_CONTEXT_INFO,0,iVar5,plVar3);
      ExFreePoolWithTag(plVar3,0x49504550);
    }
  }
  return;
}



===== PepNotifyPpmCstStates @ 1400043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepNotifyPpmCstStates(longlong param_1,uint *param_2)

{
  longlong lVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x28);
  if (lVar3 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x58));
    *(undefined4 *)(lVar3 + 0x60) = 0xffffffff;
    uVar7 = 0;
    *(undefined4 *)(lVar3 + 0x68) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x70) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x78) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x80) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x88) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x90) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0x98) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0xa0) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0xa8) = 0xffffffff;
    *(undefined4 *)(lVar3 + 0xb0) = 0xffffffff;
    while( true ) {
      uVar6 = (uint)uVar7;
      if (*param_2 <= uVar6) break;
      lVar4 = *(longlong *)(param_2 + 2);
      bVar2 = *(byte *)(lVar4 + uVar7 * 0x18);
      do {
        iVar5 = (int)uVar7;
        lVar1 = uVar7 * 0x18;
        if (*param_2 - 1 <= uVar6) break;
        uVar6 = iVar5 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (*(byte *)(lVar4 + uVar7 * 0x18) == bVar2);
      if (10 < bVar2) break;
      *(undefined8 *)(lVar3 + 0x60 + (ulonglong)(bVar2 - 1) * 8) =
           *(undefined8 *)(lVar4 + lVar1 + 0x10);
      uVar7 = (ulonglong)(iVar5 + 1);
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x58));
  }
  return;
}



===== PepGetHwResidenciesTotal @ 140004500 =====

undefined8 PepGetHwResidenciesTotal(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_140087710;
  if (PepNumPlatformStates == 0) {
    uVar1 = 0;
  }
  return uVar1;
}



===== PepDiagRootPortComponentStateChange @ 140004520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagRootPortComponentStateChange(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined **local_90;
  undefined4 local_88;
  uint local_84 [3];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (5 < DAT_1400340a0) {
    local_48 = *(wchar_t **)(param_1 + 8);
    if (local_48 == (wchar_t *)0x0) {
      local_48 = L"";
      local_40 = 2;
    }
    else {
      lVar2 = -1;
      do {
        lVar1 = lVar2 + 1;
        lVar2 = lVar2 + 1;
      } while (local_48[lVar1] != L'\0');
      local_40 = (int)lVar2 * 2 + 2;
    }
    local_88 = *(undefined4 *)(param_2 + 0xc);
    local_38 = &local_88;
    local_84[0] = (uint)*(byte *)(param_2 + 0x10);
    local_28 = local_84;
    local_74 = 5;
    local_68 = PTR_DAT_1400340a8;
    local_3c = 0;
    local_70 = 0;
    local_30 = 4;
    local_20 = 4;
    local_78 = 0xb000000;
    local_60 = (uint)*(ushort *)PTR_DAT_1400340a8;
    local_58 = &DAT_1400302e6;
    local_5c = 2;
    local_50 = 0x42;
    local_4c = 1;
    local_84[1] = 0x349b;
    local_90 = &local_68;
    local_98 = 5;
    EtwWriteTransfer(DAT_1400340c0,&local_78,0,0);
  }
  return;
}



===== PepPlatformIdleVetoReference @ 140004670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPlatformIdleVetoReference(undefined4 param_1,undefined1 param_2)

{
  code *pcVar1;
  uint uVar2;
  
  pcVar1 = DAT_1400877c0;
  uVar2 = 0;
  if (PepNumPlatformStates != 0) {
    do {
      (*pcVar1)(*(undefined8 *)(PepProcessorContext + 0x50),uVar2,param_1,param_2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < PepNumPlatformStates);
  }
  return;
}



===== PepReadMmioReg @ 1400046e0 =====

void PepReadMmioReg(longlong param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 3) {
    uVar2 = **(uint **)(param_1 + 0x30);
  }
  else if (iVar1 == 1) {
    uVar2 = (uint)**(byte **)(param_1 + 0x30);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 4) {
        *(undefined8 *)param_2 = **(undefined8 **)(param_1 + 0x30);
        return;
      }
      return;
    }
    uVar2 = (uint)**(ushort **)(param_1 + 0x30);
  }
  *param_2 = uVar2;
  return;
}



===== _tlgKeywordOn @ 140004730 =====

ulonglong _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      (in_RAX = *(ulonglong *)(param_1 + 0x18) & param_2, in_RAX == *(ulonglong *)(param_1 + 0x18)))
     )) {
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== PepReadPciReg @ 140004760 =====

void PepReadPciReg(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14);
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  *param_3 = 0;
  if (iVar2 == 3) {
    uVar4 = 4;
  }
  else {
    if (iVar2 != 4) {
      return;
    }
    uVar4 = 8;
  }
  HalGetBusDataByOffset(4,param_2,uVar1,param_3,uVar3,uVar4);
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400047d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_MapReportingKind @ 1400048c0 =====

int wil_details_MapReportingKind(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  if (param_1 == 3) {
    iVar1 = 2;
    iVar3 = 6;
  }
  else {
    switch(param_1) {
    case 0:
      return 0xff;
    case 1:
      iVar1 = 0;
      iVar3 = 4;
      break;
    case 2:
      iVar1 = 1;
      iVar3 = 5;
      break;
    default:
      bVar2 = (char)param_1 + 0x9c;
      if (0x31 < bVar2) {
        return 0xff;
      }
      iVar1 = 100;
      if (param_2 == 0) {
        iVar1 = 0x96;
      }
      return iVar1 + (uint)bVar2;
    case 4:
      iVar1 = 3;
      iVar3 = 7;
      break;
    case 5:
      iVar1 = 8;
      iVar3 = 10;
      break;
    case 6:
      iVar1 = 9;
      iVar3 = 0xb;
    }
  }
  if (param_2 == 0) {
    iVar1 = iVar3;
  }
  return iVar1;
}



===== PepDiagLogPowerGatingCounter @ 140004960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPowerGatingCounter
               (wchar_t *param_1,undefined1 param_2,undefined8 param_3,longlong param_4,char param_5
               ,longlong param_6)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_c8 [32];
  undefined4 uVar4;
  undefined1 local_98;
  undefined1 local_97 [7];
  longlong local_90;
  longlong local_88 [2];
  undefined8 local_78 [4];
  longlong local_58 [2];
  longlong *local_48;
  undefined8 local_40;
  longlong *local_38;
  undefined8 local_30;
  longlong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (param_5 == '\0') {
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_58,param_1);
    local_48 = (longlong *)&local_98;
    pbVar1 = &DAT_14003002b;
    local_38 = (longlong *)local_97;
    local_40 = 1;
    local_28 = &local_90;
    uVar4 = 6;
    local_30 = 1;
    local_20 = 8;
    local_98 = param_2;
    local_97[0] = uVar2;
    local_90 = param_4;
  }
  else {
    if (param_4 == 0) {
      return;
    }
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_58,param_1);
    local_48 = local_88;
    pbVar1 = &DAT_14002df2c;
    local_90 = param_6;
    local_38 = &local_90;
    uVar4 = 5;
    local_40 = 8;
    local_30 = 8;
    local_88[0] = param_4;
  }
  _tlgWriteTransfer_EtwWriteTransfer
            (0x1400340a0,pbVar1,CONCAT71(uVar3,uVar2),param_4,uVar4,local_78);
  return;
}



===== PepDiagLogSubsystemCounter @ 140004a80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogSubsystemCounter
               (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  undefined7 uVar4;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  longlong local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  cVar3 = (char)param_3;
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (cVar3 == '\0') {
    switch(*(undefined4 *)((longlong)param_1 + 0x14)) {
    case 0:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a0 = param_1[0xf];
        local_58 = &local_a0;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002f902,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    case 1:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x12:
      PepDiagLogCtaCounter(param_1,param_2);
      break;
    case 2:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a0 = param_1[0xe];
        local_58 = &local_a0;
        local_98[0] = *param_2;
        local_48 = local_98;
        local_a8 = param_1[0xf];
        local_38 = &local_a8;
        local_50 = 8;
        local_40 = 8;
        local_30 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002dd64,CONCAT71(uVar4,cVar3),param_4,6,local_88);
      }
      puVar1 = (undefined8 *)param_1[3];
      if (puVar1 != (undefined8 *)0x0) {
        lVar2 = 7;
        do {
          if (5 < DAT_1400340a0) {
            _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*puVar1);
            local_a8 = puVar1[2];
            local_58 = &local_a8;
            local_50 = 8;
            _tlgWriteTransfer_EtwWriteTransfer
                      (0x1400340a0,&DAT_14002f93b,CONCAT71(uVar4,cVar3),param_4,4,local_88);
          }
          puVar1 = puVar1 + 5;
          lVar2 = lVar2 + -1;
        } while (lVar2 != 0);
      }
      break;
    case 3:
      if ((PepSubsystemEnableDebugPkgCounters != '\0') && (5 < DAT_1400340a0)) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a8 = param_1[0xe];
        local_58 = &local_a8;
        local_98[0] = *param_2;
        local_48 = local_98;
        local_50 = 8;
        local_40 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002ffe7,CONCAT71(uVar4,cVar3),param_4,5,local_88);
      }
      break;
    case 4:
    case 7:
    case 8:
    case 9:
    case 0x11:
      break;
    case 5:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a8 = param_1[0xe];
        local_58 = &local_a8;
        local_98[0] = *param_2;
        local_48 = local_98;
        local_50 = 8;
        local_40 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002e3ee,CONCAT71(uVar4,cVar3),param_4,5,local_88);
      }
      break;
    case 6:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a8 = param_1[0xf];
        local_58 = &local_a8;
        local_48 = local_98;
        local_50 = 8;
        local_40 = 8;
        local_98[0] = param_4;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002fa69,CONCAT71(uVar4,cVar3),param_4,5,local_88);
      }
      break;
    case 10:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a0 = param_1[0xf];
        local_58 = &local_a0;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002ed98,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    case 0xb:
      PepDiagLogPciLinkCounter(param_1,param_2,param_3,param_4);
      break;
    case 0xc:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a0 = param_1[0xf];
        local_58 = &local_a0;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002dae4,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    case 0xd:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a0 = param_1[0xf];
        local_58 = &local_a0;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_140030888,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    case 0x13:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a8 = param_1[0xf];
        local_58 = &local_a8;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002e170,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    case 0x14:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
        local_a8 = param_1[0xf];
        local_58 = &local_a8;
        local_50 = 8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_1400308c2,CONCAT71(uVar4,cVar3),param_4,4,local_88);
      }
      break;
    default:
      goto switchD_140004adb_default;
    }
  }
  else {
    PepDiagLogSubsystemCounterTelemetry(param_1,param_4);
  }
switchD_140004adb_default:
  return;
}



===== PepDiagLogSubsystemCounterTelemetry @ 140004f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogSubsystemCounterTelemetry(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if ((param_1[0x10] != 0) && ((*(uint *)(param_1 + 2) & 0x10) == 0)) {
    switch(*(undefined4 *)((longlong)param_1 + 0x14)) {
    case 0:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_98 = param_1[0x10];
        local_48 = &local_98;
        local_38 = local_88;
        local_40 = 8;
        local_30 = 8;
        local_88[0] = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002da91,param_1,param_2,5,local_78);
      }
      break;
    case 1:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x10:
    case 0x12:
      PepDiagLogCtaCounterTelemetry(param_1,param_2);
      break;
    case 2:
      if ((5 < DAT_1400340a0) &&
         (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')) {
        local_58 = &local_98;
        local_98 = 0x1000000;
        local_50 = 8;
        _tlgCreate1Sz_wchar_t((longlong *)&local_48,(wchar_t *)*param_1);
        local_88[0] = param_1[0x10];
        local_38 = local_88;
        local_28 = &local_90;
        local_30 = 8;
        local_20 = 8;
        local_90 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002fb5b,param_1,param_2,6,local_78);
      }
      break;
    case 3:
      PepDiagLogPkgCCounterTelemetry(param_1,param_2);
      break;
    case 5:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_90 = param_1[0x10];
        local_48 = &local_90;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030835,param_1,param_2,5,local_78);
      }
      break;
    case 6:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_90 = param_1[0x10];
        local_48 = &local_90;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f332,param_1,param_2,5,local_78);
      }
      break;
    case 10:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_88[0] = param_1[0x10];
        local_48 = local_88;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ea49,param_1,param_2,5,local_78);
      }
      break;
    case 0xb:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_90 = param_1[0x10];
        local_48 = &local_90;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e277,param_1,param_2,5,local_78);
      }
      break;
    case 0x13:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_90 = param_1[0x10];
        local_48 = &local_90;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e346,param_1,param_2,5,local_78);
      }
      break;
    case 0x14:
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t((longlong *)&local_58,(wchar_t *)*param_1);
        local_90 = param_1[0x10];
        local_48 = &local_90;
        local_38 = &local_98;
        local_40 = 8;
        local_30 = 8;
        local_98 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ebe4,param_1,param_2,5,local_78);
      }
    }
  }
  return;
}



===== PepReadRegister @ 1400053e0 =====

void PepReadRegister(int *param_1,uint *param_2)

{
  PepReadRegisterWithBus(param_1,0,param_2);
  return;
}



===== PepReadRegisterWithBus @ 1400053fc =====

void PepReadRegisterWithBus(int *param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  undefined8 uVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  
  param_3[0] = 0;
  param_3[1] = 0;
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = param_1[3];
      if (iVar1 == 1) {
        bVar3 = in((short)param_1[10]);
        uVar5 = (uint)bVar3;
      }
      else if (iVar1 == 2) {
        uVar4 = in((short)param_1[10]);
        uVar5 = (uint)uVar4;
      }
      else {
        if (iVar1 != 3) {
          return;
        }
        uVar5 = in((short)param_1[10]);
      }
      *param_3 = uVar5;
      return;
    }
    if (iVar1 == 2) {
      PepReadPciReg((longlong)param_1,param_2,(undefined8 *)param_3);
      return;
    }
    if (iVar1 == 0x7f) {
      if ((int)*(undefined8 *)(param_1 + 10) == 0) {
        return;
      }
      uVar2 = rdmsr((int)*(undefined8 *)(param_1 + 10));
      *(undefined8 *)param_3 = uVar2;
      return;
    }
    if (iVar1 != 0x80) {
      return;
    }
  }
  PepReadMmioReg((longlong)param_1,param_3);
  return;
}



===== PepWriteRegisterWithBus @ 140005490 =====

void PepWriteRegisterWithBus(int *param_1,uint param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = param_1[3];
      if (iVar1 == 1) {
        out((short)param_1[10],*(undefined1 *)param_3);
        return;
      }
      if (iVar1 == 2) {
        out((short)param_1[10],*(undefined2 *)param_3);
        return;
      }
      if (iVar1 == 3) {
        out((short)param_1[10],*(undefined4 *)param_3);
        return;
      }
      return;
    }
    if (iVar1 == 2) {
      PepWritePciReg((longlong)param_1,param_2,param_3);
      return;
    }
    if (iVar1 == 0x7f) {
      if ((int)*(undefined8 *)(param_1 + 10) == 0) {
        return;
      }
      wrmsr((int)*(undefined8 *)(param_1 + 10),*param_3);
      return;
    }
    if (iVar1 != 0x80) {
      return;
    }
  }
  PepWriteMmioReg((longlong)param_1,param_3);
  return;
}



===== PepWriteMmioReg @ 140005520 =====

void PepWriteMmioReg(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 1) {
    **(undefined1 **)(param_1 + 0x30) = *(undefined1 *)param_2;
  }
  else if (iVar1 == 2) {
    **(undefined2 **)(param_1 + 0x30) = *(undefined2 *)param_2;
  }
  else if (iVar1 == 3) {
    **(undefined4 **)(param_1 + 0x30) = *(undefined4 *)param_2;
  }
  else {
    if (iVar1 != 4) {
      return;
    }
    **(undefined8 **)(param_1 + 0x30) = *param_2;
  }
  LOCK();
  UNLOCK();
  return;
}



===== __report_gsfailure @ 140005580 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 140005590 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1400055ad:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1400055ef:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_1400055ad;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1400055ef;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== __cpu_features_init @ 140005630 =====

/* WARNING: Removing unreachable block (ram,0x00014000569a) */
/* WARNING: Removing unreachable block (ram,0x000140005649) */
/* WARNING: Removing unreachable block (ram,0x00014000563a) */

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



===== Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline @ 1400056f8 =====

ulonglong Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_IntelPepArlAndBugFixes__private_featureState;
  if ((Feature_Servicing_IntelPepArlAndBugFixes__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_IntelPepArlAndBugFixes__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledFallback @ 140005730 =====

void Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_IntelPepArlAndBugFixes__private_descriptor);
  return;
}



===== Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline @ 14000574c =====

ulonglong Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_IntelPepPtlHWDrips__private_featureState;
  if ((Feature_Servicing_IntelPepPtlHWDrips__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_IntelPepPtlHWDrips__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledFallback @ 140005784 =====

void Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_IntelPepPtlHWDrips__private_descriptor);
  return;
}



===== McGenEventRegister_EtwRegister @ 1400057a0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (POP_PEP_ETW_PROVIDER_Context == 0) {
    EtwRegister(&POP_PEP_ETW_PROVIDER,McGenControlCallbackV2,&POP_PEP_ETW_PROVIDER_Context,
                &POP_PEP_ETW_PROVIDER_Context);
  }
  return;
}



===== PepDeviceStarted @ 1400057e0 =====

void PepDeviceStarted(undefined4 *param_1)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  DbgPrintEx(0x92,3,"INTELPEP: PepDeviceStarted device (%wZ)\n",&local_18);
  if (*(longlong *)(param_1 + 0xc) != 0) {
    PepPcieDeviceStarted((longlong)param_1);
  }
  return;
}



===== PepEnumerateBootVetoes @ 140005830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepEnumerateBootVetoes(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepVetoMutex,0);
  uVar1 = 0;
  PepBootVetoesEnumerated = 1;
  puVar3 = &PepBootVetoCounts;
  do {
    uVar2 = 0;
    uVar1 = uVar1 + 1;
    if (*puVar3 != 0) {
      do {
        PepPlatformIdleVetoReference(uVar1,1);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *puVar3);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (uVar1 < 4);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepVetoMutex);
  return;
}



===== PepGetDebuggerTransitionRequirements @ 1400058d0 =====

undefined8 PepGetDebuggerTransitionRequirements(uint param_1,void *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (PepDebuggerRegistered == '\0') {
    uVar1 = 0;
    DbgPrintEx(0x92,3,"INTELPEP: Debugger device using automatic transitions.\n");
    if (param_1 != 0) {
      memset(param_2,(int)CONCAT71((int7)((ulonglong)uVar1 >> 8),1),(ulonglong)param_1);
    }
  }
  else {
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== PepGetProcessorCount @ 14000593c =====

void PepGetProcessorCount(void)

{
  KeQueryActiveProcessorCountEx(0xffff);
  return;
}



===== PepInitializePlatformNotificationSupport @ 140005960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepInitializePlatformNotificationSupport(void)

{
  int iVar1;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  ulonglong local_40 [5];
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_58 = (ulonglong)(uint)local_58;
  local_10 = 0;
  local_40[2] = 0;
  uStack_18 = 0;
  local_40[4] = PepWdfDevice;
  local_40[1] = 0;
  local_40[0] = 0x38;
  local_40[3] = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                    (WdfDriverGlobals,local_40,&PepPlatformNotificationMutex);
  if (-1 < iVar1) {
    local_48 = 1;
    local_58 = 0x18;
    pcStack_50 = PepPlatformNotificationWorker;
    local_10 = 0;
    local_40[2] = 0;
    uStack_18 = 0;
    local_40[4] = PepWdfDevice;
    local_40[1] = 0;
    local_40[0] = 0x38;
    local_40[3] = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_58,local_40,&PepPlatformNotificationWorkItem);
    if (-1 < iVar1) {
      PepPlatformStandbyNotifySupported = PepAcpiQueryPlatformNotificationSupport(0);
      if ((PepPlatformAoAc != '\0') && (PepPlatformStandbyNotifySupported != '\0')) {
        PoRegisterPowerSettingCallback
                  (0,&GUID_PDC_IDLE_RESILIENCY_ENGAGED,PepPowerSettingChangeCallback,0,0);
      }
      PepPlatformUserIdleNotifySupported = PepAcpiQueryPlatformNotificationSupport(1);
      if (PepPlatformUserIdleNotifySupported != '\0') {
        PoRegisterPowerSettingCallback
                  (0,&GUID_CONSOLE_DISPLAY_STATE,PepPowerSettingChangeCallback,0,0);
        PoRegisterPowerSettingCallback
                  (0,&GUID_GLOBAL_USER_PRESENCE,PepPowerSettingChangeCallback,0,0);
        PoRegisterPowerSettingCallback(0,&GUID_ACDC_POWER_SOURCE,PepPowerSettingChangeCallback,0,0);
      }
    }
  }
  return;
}



===== PepIoCtaInterfaceWorker @ 140005b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepIoCtaInterfaceWorker(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined1 auStack_158 [32];
  undefined8 *local_138;
  ulonglong *local_130;
  undefined8 local_128;
  ulonglong *local_120;
  longlong local_108;
  ulonglong local_100 [2];
  undefined8 *puStack_f0;
  ulonglong local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_88;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffff000000000000;
  local_48 = 0;
  uStack_40 = 0;
  local_e8 = local_e8 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_100[1] = 0;
  puStack_f0 = (undefined8 *)0x0;
  memset(&local_d8,0,0x88);
  local_100[0] = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  local_108 = 0;
  puVar4 = (undefined8 *)0x0;
  if (*(int *)(lVar2 + 0x30) != 1) {
    return;
  }
  if (PepPlatformAoAc == '\0') {
    return;
  }
  puVar5 = &PepSubsystemCounterAccountingInitFinished;
  local_e0 = 0xffffffff4d2fa200;
  local_138 = &local_e0;
  iVar1 = KeWaitForSingleObject(&PepSubsystemCounterAccountingInitFinished,0,0,0);
  if (iVar1 == 0x102) {
    uVar3 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (puVar5,0x40087e60,0x102,"PepIoCtaInterfaceWorker failed due to timeout");
    }
    else if (PepSubsystemAccountingSource != 4) {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (puVar5,0x40087e60,0x102,"PepIoCtaInterfaceWorker failed due to timeout");
    }
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,PepWdfDevice,0,&local_108);
    if (iVar1 < 0) {
      DbgPrintEx(0x92,3,"WdfIoTargetCreate failed 0x%x\n",iVar1);
    }
    else {
      if (*(longlong *)(lVar2 + 0x28) == 0) {
        pcVar7 = "Symlink not available to open target\n";
      }
      else {
        local_d8 = 0x88;
        local_d4 = 2;
        local_a8 = *(undefined4 *)(lVar2 + 0x20);
        uStack_a4 = *(undefined4 *)(lVar2 + 0x24);
        uStack_a0 = *(undefined4 *)(lVar2 + 0x28);
        uStack_9c = *(undefined4 *)(lVar2 + 0x2c);
        local_98 = 0x1f0000;
        local_88 = 0x40;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_108,&local_d8);
        if (iVar1 < 0) {
          pcVar7 = "INTELPEP: WdfIoTargetOpen failed\n";
        }
        else {
          puStack_f0 = &local_48;
          local_120 = local_100;
          local_130 = local_100 + 1;
          local_128 = 0;
          uVar6 = (-(uint)(PepIntcExclusivePmtMmioInterfaceAvailable != '\0') & 0xfffffff4) +
                  0x99996664;
          local_48 = 0;
          uStack_40 = 0;
          local_100[1] = 1;
          local_38 = 0;
          uStack_30 = 0;
          local_e8 = 8;
          local_28 = 0;
          uStack_20 = 0;
          local_138 = (undefined8 *)0x0;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,local_108,0,uVar6);
          if (iVar1 == -0x3fffffdd) {
            if ((local_100[0] != 8) ||
               ((PepIntcExclusivePmtMmioInterfaceAvailable == '\0' && ((short)local_48 != 0))))
            goto LAB_140005ea9;
            puVar4 = (undefined8 *)ExAllocatePool2(0x40,local_48._4_4_);
            if (puVar4 == (undefined8 *)0x0) goto LAB_140005ea9;
            local_e8 = local_48 >> 0x20;
            uVar3 = (ulonglong)uVar6;
            uVar8 = 0;
            local_100[1] = 1;
            local_120 = local_100;
            local_130 = local_100 + 1;
            local_128 = 0;
            local_138 = (undefined8 *)0x0;
            lVar2 = local_108;
            puStack_f0 = puVar4;
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals);
            if (-1 < iVar1) {
              if ((0x2f < local_100[0]) &&
                 (uVar6 = PepSubsystemCtaArrivalUpdateInfo((longlong)puVar4,lVar2,uVar8,uVar3),
                 (int)uVar6 < 0)) {
                DbgPrintEx(0x92,0,"INTELPEP:Update CTA Subsystem failed\n");
              }
              goto LAB_140005ea9;
            }
            pcVar7 = 
            "INTELPEP:WdfIoTargetSendInternalIoctlSynchronously                   failed \n";
          }
          else {
            pcVar7 = 
            "INTELPEP: WdfIoTargetSendInternalIoctlSynchronously                    failed \n";
          }
        }
      }
      DbgPrintEx(0x92,3,pcVar7);
    }
  }
LAB_140005ea9:
  if (local_108 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (puVar4 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar4,0x49504550);
  }
  return;
}



===== PepIoCtaInterfaceWorkerV1 @ 140005f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepIoCtaInterfaceWorkerV1(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  uint uVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong lVar12;
  ulonglong *puVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined *puVar16;
  int iVar17;
  undefined8 *puVar18;
  char *pcVar19;
  undefined8 uVar20;
  uint uVar21;
  int *piVar22;
  longlong lVar23;
  undefined1 auStack_198 [32];
  undefined8 *local_178;
  ulonglong *local_170;
  undefined8 local_168;
  ulonglong *local_160;
  ulonglong *local_148;
  undefined4 local_140;
  uint local_13c;
  longlong local_138;
  ulonglong local_130 [2];
  ulonglong *puStack_120;
  ulonglong local_118;
  undefined4 local_110 [2];
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_a8;
  ulonglong local_68 [8];
  
  local_68[6] = __security_cookie ^ (ulonglong)auStack_198;
  local_68[0]._0_4_ = (uint)(ushort)local_68[0];
  local_118 = local_118 & 0xffffffff00000000;
  local_130[1] = 0;
  puStack_120 = (ulonglong *)0x0;
  local_100 = param_1;
  memset(&local_f8,0,0x88);
  puVar13 = (ulonglong *)0x0;
  local_140 = 0;
  local_130[0] = 0;
  local_108 = 0;
  local_110[0] = 0;
  puVar8 = (ulonglong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  local_138 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_148 = (ulonglong *)0x0;
  puVar18 = (undefined8 *)0x0;
  local_68[4] = 0;
  local_68[5] = 0;
  bVar6 = false;
  lVar12 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar8[9],0);
  puVar9 = (ulonglong *)0x0;
  if ((int)puVar8[6] != 1) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    goto LAB_14000609b;
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar8[9]);
  if (PepPlatformAoAc == '\0') goto LAB_14000609b;
  puVar16 = &PepSubsystemCounterAccountingInitFinished;
  local_108 = 0xffffffff4d2fa200;
  local_178 = &local_108;
  uVar7 = KeWaitForSingleObject(&PepSubsystemCounterAccountingInitFinished,0,0,0);
  if (uVar7 == 0x102) {
    if (PepSubsystemAccountingSource != 4) {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (puVar16,0x40087e60,0x102,"PepIoCtaInterfaceWorker failed due to timeout");
    }
    puVar9 = (ulonglong *)0x0;
    goto LAB_14000609b;
  }
  if (PepIntcExclusivePmtMmioInterfaceAvailable == '\0') {
LAB_14000640f:
    if (PepIntcExclusivePmtDdiInterfaceAvailable == '\0') {
LAB_1400068e0:
      uVar7 = 0;
      if (!bVar6) {
        puVar9 = local_148;
        goto LAB_14000609b;
      }
    }
    else {
      plVar10 = (longlong *)
                (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,
                           PTR__WDF_PPEP_PMT_DDI_INTERFACE_TYPE_INFO_140034090);
      puVar18 = (undefined8 *)*plVar10;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*puVar18,0);
      uVar21 = *(uint *)(puVar18 + 0x15);
      bVar6 = true;
      if (uVar21 == 1) {
        *(undefined4 *)(puVar18 + 0x15) = 2;
        puVar1 = puVar18 + 0x16;
        uVar7 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,PepWdfDevice,0,puVar1);
        if ((int)uVar7 < 0) {
          pcVar19 = "WdfIoTargetCreate failed, Status 0x%x\n";
LAB_1400064dc:
          uVar21 = uVar7;
LAB_1400064df:
          DbgPrintEx(0x92,3,pcVar19,uVar21);
        }
        else if (puVar18[3] == 0) {
          local_178 = puVar18;
          local_170 = puVar8;
          DbgPrintEx(0x92,0,
                     "IntelPEP:%s:DDI Symlink buffer not available to open target for PmtContext: 0x%p. DevExt: 0x%p\n"
                     ,"PepIoCtaInterfaceWorkerV1");
        }
        else {
          if (*(char *)(puVar18 + 1) == '\0') {
            memset((void *)((longlong)puVar18 + 0x24),0,0x84);
            *(undefined4 *)(puVar18 + 4) = 0x88;
            *(undefined4 *)((longlong)puVar18 + 0x24) = 2;
            *(undefined4 *)(puVar18 + 0xc) = 0x1f0000;
            *(undefined4 *)(puVar18 + 0xe) = 0x40;
            *(undefined4 *)(puVar18 + 10) = *(undefined4 *)(puVar18 + 2);
            *(undefined4 *)((longlong)puVar18 + 0x54) = *(undefined4 *)((longlong)puVar18 + 0x14);
            *(undefined4 *)(puVar18 + 0xb) = *(undefined4 *)(puVar18 + 3);
            *(undefined4 *)((longlong)puVar18 + 0x5c) = *(undefined4 *)((longlong)puVar18 + 0x1c);
            uVar21 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,*puVar1,puVar18 + 4)
            ;
            uVar7 = uVar21;
            if ((int)uVar21 < 0) {
              pcVar19 = "INTELPEP: WdfIoTargetOpen failed with Status:%x\n";
              goto LAB_14000647d;
            }
            *(undefined1 *)(puVar18 + 1) = 1;
            puVar11 = (undefined8 *)ExAllocatePool2(0x40,0x40,0x49504550);
            if (puVar11 != (undefined8 *)0x0) {
              local_168 = 0;
              local_170 = (ulonglong *)CONCAT62(local_170._2_6_,1);
              local_178 = (undefined8 *)CONCAT62(local_178._2_6_,0x40);
              uVar7 = (**(code **)(WdfFunctions_01015 + 0x588))
                                (WdfDriverGlobals,*puVar1,&GUID_DEVINTERFACE_PMT_TELEMTRY_DDI,
                                 puVar11);
              if ((int)uVar7 < 0) {
                pcVar19 = 
                "IntelPEP: WdfIoTargetQueryForInterface function failed with status - 0x%x";
                goto LAB_1400064dc;
              }
              *(undefined1 *)((longlong)puVar18 + 0xac) = 1;
              puVar18[0x17] = puVar11;
              uVar7 = (*(code *)puVar11[4])(puVar11,&local_140);
              if ((int)uVar7 < 0) {
                pcVar19 = "IntelPEP: Get discovery size failed for PMT instance\n";
              }
              else {
                lVar12 = ExAllocatePool2(0x40,local_140,0x49504550);
                if (lVar12 == 0) {
                  uVar7 = 0xc000009a;
                  DbgPrintEx(0x92,0,
                             "IntelPEP: %s: Failed to allocate memory for PMT Telemetry Discovery Info\n"
                             ,"PepIoCtaInterfaceWorkerV1");
                  goto LAB_1400068e7;
                }
                uVar7 = (*(code *)puVar11[5])(puVar11,lVar12,local_140,local_110);
                uVar15 = (ulonglong)uVar7;
                if ((int)uVar7 < 0) {
                  pcVar19 = "IntelPEP: Get Telemtery Discovery failed for PMT instance\n";
                }
                else {
                  puVar13 = (ulonglong *)ExAllocatePool2(0x40,0x10,0x49504550);
                  if (puVar13 != (ulonglong *)0x0) {
                    uVar21 = 0;
                    if (*(int *)(lVar12 + 4) == 0) goto LAB_1400068e0;
                    do {
                      uVar7 = (uint)uVar15;
                      local_170 = (ulonglong *)(lVar12 + 8);
                      piVar22 = &Pepv2SubsystemGuidIdentifierArray;
                      local_168 = CONCAT44(local_168._4_4_,uVar21);
                      local_178 = (undefined8 *)((ulonglong)uVar21 * 0x10 + 8 + lVar12);
                      uVar2 = *(undefined4 *)((longlong)local_178 + 4);
                      uVar3 = *(undefined4 *)(local_178 + 1);
                      uVar4 = *(undefined4 *)((longlong)local_178 + 0xc);
                      *(undefined4 *)puVar13 = *(undefined4 *)local_178;
                      *(undefined4 *)((longlong)puVar13 + 4) = uVar2;
                      *(undefined4 *)(puVar13 + 1) = uVar3;
                      *(undefined4 *)((longlong)puVar13 + 0xc) = uVar4;
                      local_160 = puVar13;
                      DbgPrintEx(0x92,3,
                                 "IntelPEP: %s: Copied Discovery Entry: 0x%p from DiscoveryArray: %p at Index 0x%x to temp local entry: 0x%p\n"
                                 ,"PepIoCtaInterfaceWorkerV1");
                      local_13c = 0;
                      iVar17 = (int)puVar13[1];
                      do {
                        local_170 = (ulonglong *)CONCAT44(local_170._4_4_,iVar17);
                        local_178 = (undefined8 *)CONCAT44(local_178._4_4_,*piVar22);
                        DbgPrintEx(0x92,3,"IntelPEP: %s: Comparing TelemGUIDs 0x%x vs 0x%x\n",
                                   "PepIoCtaInterfaceWorkerV1");
                        iVar17 = (int)puVar13[1];
                        if (*piVar22 == iVar17) {
                          uVar15 = (ulonglong)local_13c;
                          lVar23 = uVar15 * 0x78;
                          *(int *)(&DAT_140087644 + lVar23) = (int)*puVar13;
                          *(undefined4 *)(&DAT_140087648 + lVar23) =
                               *(undefined4 *)((longlong)puVar13 + 4);
                          *(undefined4 *)(&DAT_14008764c + lVar23) =
                               *(undefined4 *)((longlong)puVar13 + 0xc);
                          uVar20 = puVar11[1];
                          *(undefined8 *)(&DAT_140087668 + lVar23) = *puVar11;
                          *(undefined8 *)(lVar23 + 0x140087670) = uVar20;
                          uVar20 = puVar11[3];
                          *(undefined8 *)(&DAT_140087678 + lVar23) = puVar11[2];
                          *(undefined8 *)(lVar23 + 0x140087680) = uVar20;
                          uVar2 = *(undefined4 *)((longlong)puVar11 + 0x24);
                          uVar3 = *(undefined4 *)(puVar11 + 5);
                          uVar4 = *(undefined4 *)((longlong)puVar11 + 0x2c);
                          *(undefined4 *)(&DAT_140087688 + lVar23) = *(undefined4 *)(puVar11 + 4);
                          *(undefined4 *)(lVar23 + 0x14008768c) = uVar2;
                          *(undefined4 *)(lVar23 + 0x140087690) = uVar3;
                          *(undefined4 *)(lVar23 + 0x140087694) = uVar4;
                          uVar2 = *(undefined4 *)(puVar11 + 6);
                          uVar3 = *(undefined4 *)((longlong)puVar11 + 0x34);
                          uVar4 = *(undefined4 *)(puVar11 + 7);
                          uVar5 = *(undefined4 *)((longlong)puVar11 + 0x3c);
                          (&DAT_1400876a8)[uVar15 * 0xf] = puVar18;
                          *(undefined4 *)(&DAT_140087698 + lVar23) = uVar2;
                          *(undefined4 *)(lVar23 + 0x14008769c) = uVar3;
                          *(undefined4 *)(lVar23 + 0x1400876a0) = uVar4;
                          *(undefined4 *)(lVar23 + 0x1400876a4) = uVar5;
                          iVar17 = *(int *)((longlong)puVar13 + 0xc) << 2;
                          (&DAT_140087660)[uVar15 * 0x1e] = iVar17;
                          lVar14 = ExAllocatePool2(0x40,iVar17,0x49504550);
                          (&DAT_140087658)[uVar15 * 0xf] = lVar14;
                          if (lVar14 == 0) {
                            pcVar19 = 
                            "IoCtaInterfaceWorker: Failed to allocate memory for Telemetry Buffer\n"
                            ;
                            goto LAB_14000653c;
                          }
                          (&DAT_140087650)[lVar23] = 1;
                          uVar15 = PepSubsystemEnablePmtTelemetry((int)puVar13[1]);
                          uVar7 = (uint)uVar15;
                          uVar15 = uVar15 & 0xffffffff;
                          if ((int)uVar7 < 0) {
                            uVar21 = (uint)puVar13[1];
                            pcVar19 = 
                            "IntelPEP: Enable PMT Telemetry for Identifier GUID %x failed\n";
                            goto LAB_1400064df;
                          }
                          break;
                        }
                        local_13c = local_13c + 1;
                        piVar22 = piVar22 + 0x1e;
                      } while (local_13c == 0);
                      uVar21 = uVar21 + 1;
                    } while (uVar21 < *(uint *)(lVar12 + 4));
                    uVar7 = 0;
                    goto LAB_1400068e7;
                  }
                  uVar7 = 0xc000009a;
                  pcVar19 = "IntelPEP: Insufficient Resources for Telemetry Header\n";
                }
              }
              DbgPrintEx(0x92,3,pcVar19);
              goto LAB_1400068e7;
            }
            pcVar19 = "IntelPEP: Failed to allocate memory\n";
          }
          else {
            pcVar19 = "IntelPEP: DDI Symlink interface is already open\n";
          }
LAB_14000653c:
          DbgPrintEx(0x92,0,pcVar19);
        }
      }
      else {
        pcVar19 = "IntelPEP: PMT Interface state is %d - bailing out of DDI initialization.";
LAB_14000647d:
        DbgPrintEx(0x92,0,pcVar19,uVar21);
      }
    }
LAB_1400068e7:
    if (puVar18 != (undefined8 *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar18);
    }
LAB_140006909:
    puVar9 = local_148;
    if (-1 < (int)uVar7) goto LAB_14000609b;
  }
  else {
    iVar17 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,PepWdfDevice,0,&local_138);
    puVar9 = (ulonglong *)0x0;
    if (iVar17 < 0) {
      DbgPrintEx(0x92,3,"WdfIoTargetCreate failed 0x%x\n",iVar17);
      goto LAB_140006311;
    }
    if (puVar8[5] == 0) {
      DbgPrintEx(0x92,3,"Symlink not available to open target\n");
      goto LAB_14000609b;
    }
    local_f8 = 0x88;
    local_f4 = 2;
    local_c8 = (undefined4)puVar8[4];
    uStack_c4 = *(undefined4 *)((longlong)puVar8 + 0x24);
    uStack_c0 = (undefined4)puVar8[5];
    uStack_bc = *(undefined4 *)((longlong)puVar8 + 0x2c);
    local_a8 = 0x40;
    local_b8 = 0x1f0000;
    iVar17 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_138,&local_f8);
    if (iVar17 < 0) {
      pcVar19 = "INTELPEP: WdfIoTargetOpen failed\n";
LAB_1400063b0:
      DbgPrintEx(0x92,3,pcVar19);
    }
    else {
      puStack_120 = local_68;
      local_160 = local_130;
      local_170 = local_130 + 1;
      local_168 = 0;
      uVar21 = (-(uint)(PepIntcExclusivePmtMmioInterfaceAvailable != '\0') & 0xfffffff4) +
               0x99996664;
      local_130[1] = 1;
      local_118 = 8;
      local_178 = (undefined8 *)0x0;
      uVar7 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,local_138,0,uVar21);
      if (uVar7 != 0xc0000023) {
        DbgPrintEx(0x92,3,
                   "INTELPEP: WdfIoTargetSendInternalIoctlSynchronously                            failed \n"
                  );
        goto LAB_140006909;
      }
      if (local_130[0] == 8) {
        if ((PepIntcExclusivePmtMmioInterfaceAvailable != '\0') || ((ushort)local_68[0] == 0)) {
          puVar9 = (ulonglong *)ExAllocatePool2(0x40);
          local_148 = puVar9;
          if (puVar9 != (ulonglong *)0x0) {
            local_118 = local_68[0] >> 0x20;
            uVar15 = (ulonglong)uVar21;
            uVar20 = 0;
            local_130[1] = 1;
            local_160 = local_130;
            local_170 = local_130 + 1;
            local_168 = 0;
            local_178 = (undefined8 *)0x0;
            lVar14 = local_138;
            puStack_120 = puVar9;
            iVar17 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals);
            if (iVar17 < 0) {
              pcVar19 = 
              "INTELPEP:WdfIoTargetSendInternalIoctlSynchronously                           failed \n"
              ;
              goto LAB_1400063b0;
            }
            if (0x2f < local_130[0]) {
              uVar7 = PepSubsystemCtaArrivalUpdateInfo((longlong)puVar9,lVar14,uVar20,uVar15);
              if (-1 < (int)uVar7) {
                param_1 = local_100;
                goto LAB_14000640f;
              }
              DbgPrintEx(0x92,0,"INTELPEP:Update CTA Subsystem failed\n");
              puVar9 = local_148;
            }
          }
          goto LAB_140006311;
        }
        DbgPrintEx(0x92,3,"INTELPEP: Unsupported version detected: %d\n",local_68[0] & 0xffff);
      }
      puVar9 = (ulonglong *)0x0;
    }
  }
LAB_140006311:
  MicrosoftTelemetryAssertTriggeredMsgKM("PepIoCtaInterfaceWorker exited early with failure.");
LAB_14000609b:
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (puVar9 != (ulonglong *)0x0) {
    ExFreePoolWithTag(puVar9,0x49504550);
  }
  if (puVar13 != (ulonglong *)0x0) {
    ExFreePoolWithTag(puVar13,0x49504550);
  }
  if (lVar12 != 0) {
    ExFreePoolWithTag(lVar12,0x49504550);
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_100);
  return;
}



===== PepMarkAsBccd @ 14000692c =====

void PepMarkAsBccd(ushort *param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = PepFindDeviceMatch(param_1);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x28) = param_2;
  }
  return;
}



===== PepPowerUpCrashdumpDevice @ 140006950 =====

undefined8 PepPowerUpCrashdumpDevice(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = *param_1;
  lVar2 = *(longlong *)(uVar4 + 0x28);
  if ((lVar2 != 0) && (uVar3 = 0, *(int *)(lVar2 + 0x10) != 0)) {
    do {
      uVar4 = uVar3;
      iVar6 = (int)uVar4;
      piVar5 = (int *)(uVar4 * 0x60 + 0x20 + lVar2);
      iVar1 = *piVar5;
      if ((iVar1 == 1) || ((iVar1 == 3 || (iVar1 == 4)))) {
        uVar4 = PepBccdTriggerPowerUp((longlong)piVar5);
      }
      uVar7 = iVar6 + 1;
      uVar3 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(lVar2 + 0x10));
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== PepQueryPlatformAoAc @ 1400069b0 =====

bool PepQueryPlatformAoAc(void)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  char local_res8 [32];
  
  bVar2 = false;
  local_res8[0] = '\0';
  iVar1 = ZwPowerInformation(0x42,0,0,local_res8,1);
  if (iVar1 < 0) {
    DbgPrintEx(0x92,0,"INTELPEP: BIOS INFO: Unable to determine if the platform is AoAc capable.\n")
    ;
  }
  else {
    if (local_res8[0] == '\0') {
      pcVar3 = "INTELPEP: BIOS INFO: Platform does not support AoAc.\n";
    }
    else {
      pcVar3 = "INTELPEP: BIOS INFO: Platform is AoAc enabled.\n";
    }
    bVar2 = local_res8[0] != '\0';
    DbgPrintEx(0x92,1,pcVar3);
  }
  return bVar2;
}



===== PepUpdateNumUnregisteredDevices @ 140006a38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepUpdateNumUnregisteredDevices(char param_1)

{
  bool bVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepNumUnregisteredDevicesMutex,0);
  if (PepPcieGeneratedConstraintEnabled == '\0') {
    if (param_1 == '\0') {
      PepNumUnregisteredDevices = PepNumUnregisteredDevices + -1;
      bVar1 = PepNumUnregisteredDevices == 0;
    }
    else {
      PepNumUnregisteredDevices = PepNumUnregisteredDevices + 1;
      bVar1 = PepNumUnregisteredDevices == 1;
    }
    if (bVar1) {
      PepPlatformIdleVetoEvent(1,param_1);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,PepNumUnregisteredDevicesMutex);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140006ad0 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  switch(param_3) {
  case 0:
  case 4:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar5 = uVar2 >> 5 & 0x1ff;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 4;
          if (param_3 != 0) {
            uVar5 = 0;
          }
          uVar4 = uVar2 & 0xffffc01f | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 4) {
          uVar5 = 0x4000;
        }
        uVar4 = uVar5 | uVar4 & 0xffffbfff;
      }
      uVar3 = uVar4 >> 5 & 0x1ff;
      uVar5 = uVar3 + 1;
      if ((0x1ff < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 5 ^ uVar4) & 0x3fe0 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 1:
  case 5:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar5 = uVar2 >> 0xf & 0x7f;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 5;
          if (param_3 != 1) {
            uVar5 = 1;
          }
          uVar4 = uVar2 & 0xffc07fff | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 5) {
          uVar5 = 0x400000;
        }
        uVar4 = uVar5 | uVar4 & 0xffbfffff;
      }
      uVar3 = uVar4 >> 0xf & 0x7f;
      uVar5 = uVar3 + 1;
      if ((0x7f < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 0xf ^ uVar4) & 0x3f8000 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 2:
  case 3:
  case 6:
  case 7:
    uVar4 = 0;
    if (param_3 == 2) {
      uVar4 = 2;
    }
    else if (param_3 == 3) {
      uVar4 = 8;
    }
    else if (param_3 == 6) {
      uVar4 = 4;
    }
    else if (param_3 == 7) {
      uVar4 = 0x10;
    }
    uVar2 = *param_2;
    do {
      uVar3 = uVar2;
      uVar2 = uVar4 | uVar3;
      param_1[4] = (uint)(uVar2 == uVar3);
      uVar5 = uVar2 | 1;
      if (uVar2 == uVar3) {
        uVar5 = uVar2;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar5;
        uVar2 = uVar3;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar5 & 1) == 0) || (uVar4 = 1, (uVar3 & 1) != 0)) {
      uVar4 = 0;
    }
    *param_1 = uVar4;
    break;
  default:
    uVar4 = param_3 - 0x140;
    if ((int)uVar4 < 0x40) {
      uVar2 = param_2[1];
      do {
        if (((uVar2 & 0x10) == 0) || (uVar5 = 1, (uVar2 >> 5 & 0x3f) != uVar4)) {
          uVar5 = 0;
        }
        param_1[4] = uVar5;
        LOCK();
        uVar5 = param_2[1];
        bVar6 = uVar2 == uVar5;
        if (bVar6) {
          param_2[1] = (uVar4 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
        }
        else {
          uVar2 = uVar5;
        }
        UNLOCK();
      } while (!bVar6);
      if (param_1[4] != 0) {
        return param_1;
      }
    }
    param_1[2] = param_3;
    param_1[1] = 1;
    param_1[3] = param_4;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140006da4 =====

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
      goto LAB_140006e75;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140006e75;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140006e75;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140006e75;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140006e75;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140006e75;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140006e75;
    }
  }
  uVar3 = 0xff;
LAB_140006e75:
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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140006fdc =====

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
    do {
      if ((uVar3 & 2) == 0) {
        return;
      }
      if (((uVar3 ^ param_1) & 1) != 0) {
        return;
      }
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
    } while (!bVar5);
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 140007038 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 140007198 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 14000722c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14003323f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140007258 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400073b0 =====

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



===== McTemplateK0qNR0_EtwWriteTransfer @ 140007434 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qNR0_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined1 auStackY_78 [32];
  int local_48 [2];
  undefined8 local_40 [2];
  int *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  uint local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_30 = local_48;
  local_24 = 0;
  local_28 = 4;
  local_20 = param_6;
  local_14 = 0;
  local_48[0] = PepNumPlatformStates;
  local_18 = PepNumPlatformStates << 4;
  McGenEventWrite_EtwWriteTransfer
            ((ulonglong)local_18,&POP_PEP_ETW_PLATFORM_IDLE_RESIDENCY,param_3,3,local_40);
  return;
}



===== PepCollectProcessorTemperature @ 1400074c0 =====

uint PepCollectProcessorTemperature(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar2 = rdmsr(0x19c);
  uVar3 = (uint)uVar2;
  if ((int)uVar3 < 0) {
    uVar3 = -(uVar3 >> 0x10 & 0x7f);
  }
  else {
    uVar3 = uVar3 >> 0x10 & 0x7f;
  }
  LOCK();
  uVar1 = *(uint *)(param_2 + 8);
  *(uint *)(param_2 + 8) = uVar3;
  UNLOCK();
  return uVar1;
}



===== PepGetHwResidenciesLastTransition @ 1400074f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PepGetHwResidenciesLastTransition(void)

{
  return -(ulonglong)(PepNumPlatformStates != 0) & _DAT_140087718;
}



===== PepInitializeProcessorContext @ 140007510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400075bd) */

int PepInitializeProcessorContext(void)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar2 = PepNumProcessors;
  iVar4 = 0;
  lVar5 = ExAllocatePool2(0x40,PepNumProcessors * 0xb8,0x49504550);
  if (lVar5 == 0) {
    iVar4 = -0x3fffff66;
  }
  else {
    for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1) {
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                        (WdfDriverGlobals,0,(ulonglong)uVar6 * 0xb8 + 0x58 + lVar5);
      if (iVar4 < 0) {
        ExFreePoolWithTag(lVar5,0x49504550);
        return iVar4;
      }
    }
    PepIsParkingSupported = 0;
    puVar1 = (uint *)cpuid_Thermal_Power_Management_info(6);
    PepProcessorContext = lVar5;
    if (((*puVar1 & 1) != 0) && (cVar3 = CheckDtsAvailableRegistryEntry(), cVar3 != '\0')) {
      PepIsParkingSupported = 1;
    }
  }
  return iVar4;
}



===== PepNotifyPpmEnumerateBootVetoes @ 140007600 =====

void PepNotifyPpmEnumerateBootVetoes(void)

{
  PepEnumerateBootVetoes();
  PepSetUpThermalCollectionForParking();
  return;
}



===== PepNotifyPpmIdleComplete @ 140007620 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepNotifyPpmIdleComplete
               (undefined8 param_1,longlong param_2,ulonglong *param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 in_stack_ffffffffffffffe8;
  
  if (*(int *)(param_2 + 4) != -1) {
    if (PepPcieLtrOverrideEnabled != '\0') {
      PepPcieLtrApplyOverride(*(int *)(param_2 + 4),'\0',(uint *)param_3,param_4);
    }
    uVar3 = 1;
    PepDbgPlatformStateTransition();
    if (PepSubsystemAccountingSource - 2U < 2) {
      PepSubsystemUpdateActiveTimes(*(int *)(param_2 + 4),uVar3,param_3,param_4);
    }
    plVar2 = (longlong *)(ulonglong)*(uint *)(param_2 + 4);
    uVar5 = -(ulonglong)(PepNumPlatformStates != 0) & _DAT_140087718;
    lVar4 = DAT_140087720;
    PepGetPlatformStateHwResidency(*(uint *)(param_2 + 4),DAT_140087720,uVar5);
    lVar1 = PepGetHwResidenciesTotal();
    uVar6 = (ulonglong)PepNumPlatformStates;
    if (PepNumPlatformStates != 0) {
      plVar2 = (longlong *)(lVar1 + 8);
      lVar4 = uVar5 - lVar1;
      uVar7 = uVar6;
      do {
        *plVar2 = *plVar2 + *(longlong *)(lVar4 + (longlong)plVar2);
        *(int *)((longlong)plVar2 + -4) =
             *(int *)((longlong)plVar2 + -4) + *(int *)(lVar4 + -4 + (longlong)plVar2);
        plVar2 = plVar2 + 2;
        uVar7 = uVar7 - 1;
        uVar6 = 0;
      } while (uVar7 != 0);
    }
    if ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0) {
      McTemplateK0qNR0_EtwWriteTransfer(plVar2,lVar4,uVar6,param_4,in_stack_ffffffffffffffe8,uVar5);
    }
  }
  return;
}



===== PepNotifyPpmIdlePreExecute @ 1400076e0 =====

void PepNotifyPpmIdlePreExecute
               (undefined8 param_1,undefined4 *param_2,uint *param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong local_res10;
  
  *param_2 = 0;
  lVar1 = DAT_140087720;
  iVar3 = param_2[2];
  if (iVar3 != -1) {
    uVar5 = 0;
    if (PepNumPlatformStates != 0) {
      do {
        local_res10 = 0;
        lVar2 = PepGetPlatformStateInfo((uint)uVar5);
        PepReadResidencyCounter(lVar2,&local_res10);
        *(ulonglong *)(lVar1 + uVar5 * 8) = local_res10;
        uVar4 = (uint)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < PepNumPlatformStates);
      iVar3 = param_2[2];
    }
    PepDripsTransitionCount = PepDripsTransitionCount + 1;
    if ((PepSubsystemAccountingSource == 2) || (PepSubsystemAccountingSource == 3)) {
      PepSubsystemSnapActiveCounters(iVar3);
      iVar3 = param_2[2];
    }
    if (PepPcieLtrOverrideEnabled != '\0') {
      PepPcieLtrApplyOverride(iVar3,'\x01',param_3,param_4);
    }
    PepDbgPlatformStateTransition();
  }
  return;
}



===== PepNotifyPpmParkSelection @ 140007790 =====

void PepNotifyPpmParkSelection(undefined8 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = param_2[1];
  iVar6 = *param_2;
  if (PepIsParkingSupported != '\0') {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      uVar7 = 0xffffffff;
      uVar5 = 0;
      iVar4 = 0x7fffffff;
      if (uVar1 != 0) {
        plVar3 = *(longlong **)(param_2 + 2);
        do {
          if ((((char)plVar3[1] == '\0') && (*(char *)((longlong)plVar3 + 9) != '\x02')) &&
             (iVar2 = *(int *)(*(longlong *)(*plVar3 + 0x28) + 8), iVar2 < iVar4)) {
            iVar4 = iVar2;
            uVar7 = uVar5;
          }
          uVar5 = uVar5 + 1;
          plVar3 = plVar3 + 2;
        } while (uVar5 < uVar1);
      }
      *(undefined1 *)(*(longlong *)(param_2 + 2) + 9 + (longlong)(int)uVar7 * 0x10) = 2;
    }
  }
  return;
}



===== PepNotifyPpmQueryCapabilities @ 140007820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepNotifyPpmQueryCapabilities(longlong param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  if (*(char *)(param_2 + 3) == '\0') {
    LOCK();
    UNLOCK();
    puVar4 = (undefined1 *)
             ((ulonglong)(PepProcessorContextLastIndex + 1) * 0xb8 + PepProcessorContext);
    PepProcessorContextLastIndex = PepProcessorContextLastIndex + 1;
    uVar2 = KeGetCurrentProcessorNumberEx(0);
    *(undefined4 *)(puVar4 + 4) = uVar2;
  }
  else {
    puVar4 = (undefined1 *)ExAllocatePool2(0x40,0xb8,0x49504550);
    if (puVar4 == (undefined1 *)0x0) goto LAB_140007899;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0,puVar4 + 0x58);
    if (iVar3 < 0) {
      ExFreePoolWithTag(puVar4,0x49504550);
      goto LAB_140007899;
    }
  }
  uVar1 = PepIsParkingSupported;
  *(undefined1 *)(param_1 + 0x18) = 1;
  *param_2 = 0;
  *(undefined1 *)((longlong)param_2 + 9) = uVar1;
  param_2[1] = 0xb;
  *(undefined1 *)(param_2 + 2) = 0;
  *(undefined8 *)(puVar4 + 0x50) = *(undefined8 *)(param_1 + 0x10);
  *puVar4 = *(undefined1 *)(param_2 + 3);
  *(undefined1 **)(param_1 + 0x28) = puVar4;
LAB_140007899:
  DbgPrintEx(0x92,2,"INTELPEP: PPM_NOTIFY_PPM_QUERY_CAPABILTIES (RegInfo: %p)\n",param_1);
  return;
}



===== PepNotifyPpmQueryIdleStates @ 140007940 =====

void PepNotifyPpmQueryIdleStates(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  if (*param_2 != 0) {
    uVar4 = 8;
    uVar3 = 0;
    do {
      uVar2 = (int)uVar3 + 1;
      param_2[uVar3 * 3 + 2] = 0xffffffff;
      uVar1 = uVar4 ^ (param_2[uVar3 * 3 + 1] | 0x87);
      uVar4 = uVar4 + 8;
      param_2[uVar3 * 3 + 1] = uVar1 & 0x78 ^ (param_2[uVar3 * 3 + 1] | 0x87) | 0x200;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *param_2);
  }
  DbgPrintEx(0x92,2,"INTELPEP: PPM_NOTIFY_PPM_QUERY_IDLE_STATES (RegInfo: %p)\n",param_1);
  return;
}



===== PepNotifyPpmQueryMeasurementCapabilities @ 1400079c0 =====

void PepNotifyPpmQueryMeasurementCapabilities(undefined8 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = PepSubsystemGetResidencyRegisterCount();
  uVar2 = *param_2 | 1;
  if (iVar1 == 0) {
    uVar2 = *param_2 & 0xfffffffe;
  }
  *param_2 = uVar2;
  return;
}



===== PepNotifyPpmQueryPkgIdleStateRegisters @ 140007a00 =====

void PepNotifyPpmQueryPkgIdleStateRegisters(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar2 = PepSubsystemGetResidencyRegisterCount();
  lVar1 = PepSubsystemAccountingInfo;
  if (uVar2 != 0) {
    if (*(int *)(param_2 + 1) == 0) {
      *(uint *)(param_2 + 1) = uVar2;
    }
    else {
      uVar4 = 0;
      *param_2 = *(undefined8 *)(PepSubsystemAccountingInfo + 0x28);
      if (uVar2 != 0) {
        puVar5 = (undefined4 *)(lVar1 + 0x34);
        do {
          param_2[2] = *(undefined8 *)(puVar5 + -0xd);
          param_2[3] = *(undefined8 *)(puVar5 + 9);
          *(undefined4 *)(param_2 + 4) = *puVar5;
          *(undefined4 *)((longlong)param_2 + 0x24) = puVar5[1];
          if (uVar4 == 0) {
            uVar3 = 0x200200;
          }
          else if (uVar4 == 1) {
            uVar3 = 0x200300;
          }
          else if (uVar4 == 2) {
            uVar3 = 0x200600;
          }
          else if (uVar4 == 3) {
            uVar3 = 0x200700;
          }
          else if (uVar4 == 4) {
            uVar3 = 0x200800;
          }
          else if (uVar4 == 5) {
            uVar3 = 0x200900;
          }
          else if (uVar4 == 6) {
            uVar3 = 0x200a00;
          }
          else {
            uVar3 = 0;
          }
          *(undefined4 *)(param_2 + 5) = uVar3;
          uVar4 = uVar4 + 1;
          puVar5 = puVar5 + 0x36;
          param_2 = param_2 + 4;
        } while (uVar4 < uVar2);
      }
    }
  }
  return;
}



===== PepNotifyPpmQueryPlatformStates @ 140007af0 =====

void PepNotifyPpmQueryPlatformStates(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = PepNumPlatformStates;
  DbgPrintEx(0x92,2,"INTELPEP: PPM_NOTIFY_PPM_QUERY_PLATFORM_STATES\n");
  return;
}



===== PepNotifyPpmQueryVetoReason @ 140007b30 =====

void PepNotifyPpmQueryVetoReason(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  
  if (*(void **)(param_2 + 2) == (void *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)((&PepVetoNames)[*param_2 - 1] + lVar1 * 2) != 0);
    *(short *)(param_2 + 1) = (short)lVar1;
  }
  else {
    memmove(*(void **)(param_2 + 2),(&PepVetoNames)[*param_2 - 1],
            (ulonglong)*(ushort *)(param_2 + 1) * 2);
  }
  return;
}



===== PepNotifyPpmQueryVetoReasons @ 140007b80 =====

void PepNotifyPpmQueryVetoReasons(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 4;
  return;
}



===== PepNotifyPpmTestIdleState @ 140007b90 =====

void PepNotifyPpmTestIdleState(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}



===== PepScheduleTemperatureCollection @ 140007ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepScheduleTemperatureCollection(void)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_148 [32];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  memset(local_128,0,0x108);
  if (PepIsParkingSupported != '\0') {
    KeInitializeAffinityEx2(local_128,0x20);
    KeQueryActiveProcessorAffinity2(local_128);
    uVar3 = 0;
    if (PepNumProcessors != 0) {
      do {
        iVar1 = KeCheckProcessorAffinityEx
                          (local_128,*(undefined4 *)(uVar3 * 0xb8 + 4 + PepProcessorContext));
        if (iVar1 != 0) {
          KeInsertQueueDpc(PepProcessorContext + 0x10 + uVar3 * 0xb8,0,0);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < PepNumProcessors);
    }
  }
  return;
}



===== PepSetUpThermalCollectionForParking @ 140007c8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepSetUpThermalCollectionForParking(void)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_48 [32];
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (PepIsParkingSupported != '\0') {
    uVar3 = 0;
    if (PepNumProcessors != 0) {
      do {
        local_28[0] = 0;
        KeGetProcessorNumberFromIndex
                  (*(undefined4 *)(uVar3 * 0xb8 + 4 + PepProcessorContext),local_28);
        lVar1 = PepProcessorContext + uVar3 * 0xb8 + 0x10;
        KeInitializeDpc(lVar1,PepCollectProcessorTemperature);
        KeSetImportanceDpc(lVar1,3);
        KeSetTargetProcessorDpcEx(lVar1,local_28);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < PepNumProcessors);
    }
    _PepPeriodicThermalTimer = ExAllocateTimer(PepScheduleTemperatureCollection,0,8);
    if (_PepPeriodicThermalTimer != 0) {
      local_20 = 0;
      local_18 = 0xffffffffffffffff;
      ExSetTimer(_PepPeriodicThermalTimer,0xfffffffffd050f80,10000000,&local_20);
    }
  }
  return;
}



===== PepAcpiDeviceDependencyTableBuilder @ 140007db4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PepAcpiDeviceDependencyTableBuilder(undefined8 *param_1,undefined8 *param_2)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  short *psVar10;
  byte *pbVar11;
  int iVar12;
  uint *_Dst;
  longlong lVar13;
  short *psVar14;
  char cVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  undefined1 auStackY_138 [32];
  longlong local_f0;
  uint *local_e8;
  short *local_e0;
  undefined8 *local_d8;
  byte local_d0 [2];
  undefined4 local_ce;
  char *local_c8;
  code *local_c0;
  undefined1 local_b8;
  undefined4 local_b6;
  char *local_b0;
  code *local_a8;
  byte local_98 [2];
  undefined4 local_96;
  char *local_90;
  code *local_88;
  undefined1 local_80;
  undefined4 local_7e;
  char *local_78;
  code *local_70;
  undefined1 local_68;
  undefined4 local_66;
  char *local_60;
  code *local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_98[0] = 0;
  local_96 = 0;
  local_88 = PepAcpiParseULong;
  local_90 = "LPI-UID";
  local_80 = 1;
  local_b8 = 1;
  local_7e = 0x40000;
  local_78 = "MinDState";
  local_70 = PepAcpiParseULong;
  local_68 = 2;
  local_66 = 0x80000;
  local_60 = "MinFState";
  local_58 = PepAcpiParseULong;
  local_d0[0] = 0;
  local_ce = 0;
  local_c8 = "LPI-UID";
  local_c0 = PepAcpiParseULong;
  local_b6 = 0x40000;
  local_b0 = "MinDState";
  local_a8 = PepAcpiParseULong;
  local_f0 = 0;
  local_d8 = param_2;
  if ((*(uint *)(param_1 + 1) >> 1 & 1) == 0) {
    iVar5 = -0x3ffffffe;
    goto LAB_1400081d8;
  }
  iVar5 = PepAcpiEval_DSM(param_1,"LPI-UID",1,&local_f0);
  lVar13 = local_f0;
  if (iVar5 < 0) {
    pcVar16 = "INTELPEP: _DSM evaluation failed.\n";
  }
  else {
    uVar3 = *(uint *)(local_f0 + 8);
    if (uVar3 == 0) {
      DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: 0 Device dependencies specified.\n");
      iVar5 = -0x3ffffddb;
      goto LAB_1400081d8;
    }
    if (*(uint *)(local_f0 + 4) < 0x14) {
      iVar5 = -0x7ffffffb;
      goto LAB_1400081d8;
    }
    psVar14 = (short *)(local_f0 + 0xc);
    if (*psVar14 == 3) {
      puVar6 = (uint *)ExAllocatePool2(0x40,uVar3 * 0x90 + 8,0x49504550);
      if (puVar6 == (uint *)0x0) {
        iVar5 = -0x3fffff66;
      }
      else {
        *puVar6 = uVar3;
        uVar9 = 0;
        uVar3 = *(uint *)(param_1 + 2);
        while (uVar18 = 0, psVar14 < (short *)((ulonglong)*(uint *)(lVar13 + 4) + lVar13)) {
          if (*psVar14 != 3) goto LAB_140007ee9;
          _Dst = puVar6 + (ulonglong)uVar9 * 0x24 + 2;
          _Dst[0x21] = uVar3;
          local_e8 = _Dst;
          uVar7 = ExAllocatePool2(0x40,uVar3 * 0xc,0x49504550);
          *(undefined8 *)(_Dst + 0x22) = uVar7;
          if (psVar14[2] != 1) {
            pcVar16 = "INTELPEP: BIOS ERROR: String argument expected.\n";
            goto LAB_140007ef0;
          }
          strncpy_s((char *)_Dst,0x80,(char *)(psVar14 + 4),0xffffffffffffffff);
          uVar8 = (ulonglong)(ushort)psVar14[3];
          if ((ushort)psVar14[3] < 4) {
            uVar8 = 4;
          }
          psVar10 = (short *)(uVar8 + 4 + (longlong)(psVar14 + 2));
          if (*psVar10 != 0) {
            pcVar16 = "INTELPEP: BIOS ERROR: Integer argument expected.\n";
            goto LAB_140007ef0;
          }
          _Dst[0x20] = *(uint *)(psVar10 + 2);
          uVar8 = (ulonglong)(ushort)psVar10[1];
          if ((ushort)psVar10[1] < 4) {
            uVar8 = 4;
          }
          psVar10 = (short *)(uVar8 + 4 + (longlong)psVar10);
          if (*psVar10 != 3) goto LAB_140007ee9;
          local_e0 = (short *)((ulonglong)(ushort)psVar10[1] + 4 + (longlong)psVar10);
          psVar14 = psVar10 + 2;
          if (*psVar14 == 0) {
            if (*(int *)(psVar10 + 4) != 0) {
              iVar5 = -0x3ffffff3;
              goto LAB_1400081d8;
            }
            uVar8 = (ulonglong)(ushort)psVar10[3];
            if ((ushort)psVar10[3] < 4) {
              uVar8 = 4;
            }
            psVar14 = (short *)((longlong)psVar14 + uVar8 + 4);
          }
          for (; psVar14 < local_e0; psVar14 = (short *)((longlong)psVar14 + uVar8 + 4)) {
            if (uVar18 == uVar3) {
              iVar5 = -0x3febfff5;
              pcVar16 = 
              "INTELPEP: BIOS ERROR: Firmware device list has too many dependency packages.\n";
              goto LAB_140007ef5;
            }
            if (*psVar14 != 3) goto LAB_140007ee9;
            uVar2 = psVar14[1];
            if (uVar2 == 0) {
LAB_1400080dd:
              cVar15 = '\0';
              uVar17 = 3;
            }
            else {
              psVar10 = psVar14 + 2;
              psVar1 = (short *)((longlong)psVar10 + (ulonglong)uVar2);
              iVar5 = 0;
              if (psVar1 <= psVar10) goto LAB_1400080dd;
              do {
                iVar12 = iVar5;
                uVar8 = (ulonglong)(ushort)psVar10[1];
                if ((ushort)psVar10[1] < 4) {
                  uVar8 = 4;
                }
                iVar5 = iVar12 + 1;
                psVar10 = (short *)((longlong)psVar10 + uVar8 + 4);
              } while (psVar10 < psVar1);
              _Dst = local_e8;
              lVar13 = local_f0;
              if (iVar5 != 2) goto LAB_1400080dd;
              cVar15 = (char)iVar12;
              uVar17 = 2;
            }
            pbVar11 = local_98;
            if (cVar15 != '\0') {
              pbVar11 = local_d0;
            }
            iVar5 = PepAcpiParseCore(pbVar11,uVar17,psVar14 + 2,(ulonglong)uVar2,
                                     *(longlong *)(_Dst + 0x22) + (ulonglong)uVar18 * 0xc,0xc,"DEVX"
                                    );
            if (iVar5 < 0) goto LAB_1400081d8;
            uVar8 = (ulonglong)(ushort)psVar14[1];
            uVar18 = uVar18 + 1;
            if ((ushort)psVar14[1] < 4) {
              uVar8 = 4;
            }
            _Dst = local_e8;
          }
          if ((uVar18 != 1) && (uVar18 != uVar3)) {
            iVar5 = -0x3febfff5;
            pcVar16 = 
            "INTELPEP: BIOS ERROR: Firmware device list has incorrect number of dependency packages.\n"
            ;
            goto LAB_140007ef5;
          }
          uVar9 = uVar9 + 1;
        }
        uVar8 = PepValidateDevxList(puVar6,(longlong)param_1);
        iVar5 = (int)uVar8;
        if (-1 < iVar5) {
          *local_d8 = puVar6;
          if (lVar13 != 0) {
            ExFreePoolWithTag(lVar13,0x49504550);
          }
          return uVar8 & 0xffffffff;
        }
      }
      goto LAB_1400081d8;
    }
LAB_140007ee9:
    pcVar16 = "INTELPEP: BIOS ERROR: Package argument expected.\n";
LAB_140007ef0:
    iVar5 = -0x3febfff8;
  }
LAB_140007ef5:
  DbgPrintEx(0x92,0,pcVar16);
LAB_1400081d8:
  PepAcpiFatalBiosError(iVar5);
  pcVar4 = (code *)swi(3);
  uVar8 = (*pcVar4)();
  return uVar8;
}



===== PepAcpiFatalBiosError @ 140008230 =====

void PepAcpiFatalBiosError(int param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xa0,0x680,(longlong)param_1,0,0);
}



===== PepAcpiGetDeviceDependencyInfo @ 140008260 =====

uint PepAcpiGetDeviceDependencyInfo(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  int *piVar11;
  longlong lVar12;
  uint uVar13;
  uint *puVar14;
  undefined8 *puVar15;
  int iVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  uint uVar19;
  uint *local_res18;
  
  lVar12 = 0;
  local_res18 = (uint *)0x0;
  lVar9 = 0;
  uVar8 = PepAcpiDeviceDependencyTableBuilder(param_1,&local_res18);
  puVar4 = local_res18;
  uVar7 = (uint)uVar8;
  uVar8 = uVar8 & 0xffffffff;
  if (-1 < (int)uVar7) {
    iVar16 = 0;
    if (*local_res18 != 0) {
      puVar14 = local_res18 + 0x22;
      uVar17 = (ulonglong)*local_res18;
      do {
        uVar7 = *puVar14;
        puVar14 = puVar14 + 0x24;
        iVar5 = iVar16 + 1;
        if (uVar7 == 0) {
          iVar5 = iVar16;
        }
        iVar16 = iVar5;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
    }
    PepAcpiQueryEmDeviceConstraints();
    iVar16 = iVar16 + PepAcpiEmDeviceCount;
    if (iVar16 == 0) {
      PepKnownDeviceList = 0;
      PepKnownDeviceCount = 0;
      uVar7 = 0;
    }
    else {
      lVar9 = ExAllocatePool2(0x40,iVar16 * 0x38,0x49504550);
      uVar7 = PepAcpiEmDeviceCount;
      if (lVar9 == 0) {
LAB_14000830f:
        uVar7 = 0xc000009a;
      }
      else {
        uVar17 = 0;
        if (PepAcpiEmDeviceCount != 0) {
          puVar15 = PepAcpiEmDeviceList;
          do {
            uVar3 = puVar15[1];
            lVar12 = uVar17 * 0x38;
            uVar19 = (int)uVar17 + 1;
            uVar17 = (ulonglong)uVar19;
            *(undefined8 *)(lVar12 + lVar9) = *puVar15;
            ((undefined8 *)(lVar12 + lVar9))[1] = uVar3;
            uVar3 = puVar15[3];
            puVar1 = (undefined8 *)(lVar12 + 0x10 + lVar9);
            *puVar1 = puVar15[2];
            puVar1[1] = uVar3;
            uVar3 = puVar15[5];
            puVar1 = (undefined8 *)(lVar12 + 0x20 + lVar9);
            *puVar1 = puVar15[4];
            puVar1[1] = uVar3;
            *(undefined8 *)(lVar12 + 0x30 + lVar9) = puVar15[6];
            puVar15 = puVar15 + 7;
          } while (uVar19 < uVar7);
        }
        uVar18 = 0;
        while( true ) {
          uVar7 = (uint)uVar8;
          if (*puVar4 <= (uint)uVar18) break;
          if (puVar4[uVar18 * 0x24 + 0x22] == 0) {
            ExFreePoolWithTag(*(undefined8 *)(puVar4 + uVar18 * 0x24 + 0x24),0x49504550);
          }
          else {
            uVar7 = *(uint *)(param_1 + 2);
            lVar12 = uVar17 * 0x38 + lVar9;
            lVar10 = ExAllocatePool2(0x40,uVar7 * 8,0x49504550);
            *(longlong *)(lVar12 + 0x20) = lVar10;
            if (lVar10 == 0) goto LAB_14000830f;
            uVar8 = 0;
            while (uVar19 = (uint)uVar8, uVar19 < uVar7) {
              lVar10 = *(longlong *)(puVar4 + uVar18 * 0x24 + 0x24);
              lVar2 = *(longlong *)(lVar12 + 0x20);
              iVar5 = *(int *)(lVar10 + 4 + uVar8 * 0xc) + 1;
              *(int *)(lVar2 + uVar8 * 8) = iVar5;
              uVar6 = *(int *)(lVar10 + 8 + uVar8 * 0xc) - 0x80;
              uVar13 = 0;
              if (uVar6 < 0x7f) {
                uVar13 = uVar6;
              }
              local_res18 = (uint *)CONCAT44(local_res18._4_4_,uVar13);
              *(uint *)(lVar2 + 4 + uVar8 * 8) = uVar13;
              uVar6 = (uVar7 - uVar19) - 1;
              if ((uVar6 != 0) && (*(int *)(lVar10 + uVar8 * 0xc) == 0xff)) {
                piVar11 = (int *)(lVar2 + (uVar8 + 1) * 8);
                if (uVar6 != 0) {
                  uVar8 = (ulonglong)uVar6;
                  do {
                    *piVar11 = iVar5;
                    piVar11[1] = uVar13;
                    piVar11 = piVar11 + 2;
                    uVar8 = uVar8 - 1;
                  } while (uVar8 != 0);
                }
                break;
              }
              uVar8 = (ulonglong)(uVar19 + 1);
            }
            ExFreePoolWithTag(*(undefined8 *)(puVar4 + uVar18 * 0x24 + 0x24),0x49504550);
            uVar7 = PepAcpiInitUnicodeString(lVar12);
            uVar8 = (ulonglong)uVar7;
            if ((int)uVar7 < 0) goto LAB_1400084b1;
            *(undefined8 *)(lVar12 + 0x10) = 0;
            *(undefined8 *)(lVar12 + 0x28) = 0;
            uVar17 = (ulonglong)((int)uVar17 + 1);
            *(undefined2 *)(lVar12 + 0x18) = 0x100;
          }
          uVar18 = (ulonglong)((uint)uVar18 + 1);
        }
        lVar12 = 0;
        PepKnownDeviceCount = iVar16;
        PepKnownDeviceList = lVar9;
      }
    }
  }
LAB_1400084b1:
  if (puVar4 != (uint *)0x0) {
    ExFreePoolWithTag(puVar4,0x49504550);
  }
  if ((int)uVar7 < 0) {
    if ((lVar12 != 0) && (*(longlong *)(lVar12 + 0x20) != 0)) {
      ExFreePoolWithTag(*(longlong *)(lVar12 + 0x20),0x49504550);
    }
    if (lVar9 != 0) {
      ExFreePoolWithTag(lVar9,0x49504550);
    }
    DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: Failed to get device dependencies.\n");
  }
  return uVar7;
}



===== PepAcpiGetPlatformStateInfo @ 140008540 =====

ulonglong PepAcpiGetPlatformStateInfo(longlong param_1,undefined4 *param_2)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int *piVar5;
  uint uVar6;
  longlong lVar7;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = PepAcpiLpitBuilder(param_1,local_res18);
  if (-1 < (int)uVar2) {
    lVar3 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x10) << 4,0x49504550);
    *(longlong *)(param_2 + 4) = lVar3;
    if (lVar3 != 0) {
      lVar3 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x10) << 4,0x49504550);
      *(longlong *)(param_2 + 6) = lVar3;
      if (lVar3 != 0) {
        lVar3 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x10) << 3,0x49504550);
        *(longlong *)(param_2 + 8) = lVar3;
        if (lVar3 != 0) {
          lVar3 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x10) * 0x60,0x49504550);
          if (lVar3 != 0) {
            uVar4 = 0;
            if (*(int *)(param_1 + 0x10) != 0) {
              do {
                lVar7 = uVar4 * 0x38;
                piVar5 = (int *)(uVar4 * 0x60 + lVar3);
                *piVar5 = *(int *)(lVar7 + 0x44 + local_res18[0]) * 10;
                piVar5[1] = *(int *)(lVar7 + 0x40 + local_res18[0]) * 10;
                *(undefined8 *)(piVar5 + 2) = *(undefined8 *)(lVar7 + 0x38 + local_res18[0]);
                if ((*(byte *)(lVar7 + 0x30 + local_res18[0]) & 2) == 0) {
                  piVar5[8] = (uint)*(byte *)(lVar7 + 0x48 + local_res18[0]);
                  piVar5[0xb] = (uint)*(byte *)(lVar7 + 0x4b + local_res18[0]);
                  *(undefined8 *)(piVar5 + 0x12) = *(undefined8 *)(lVar7 + 0x4c + local_res18[0]);
                  piVar5[9] = (uint)*(byte *)(lVar7 + 0x49 + local_res18[0]);
                  piVar5[10] = (uint)*(byte *)(lVar7 + 0x4a + local_res18[0]);
                  *(undefined8 *)(piVar5 + 6) = *(undefined8 *)(lVar7 + 0x54 + local_res18[0]);
                }
                else {
                  *(undefined1 *)(piVar5 + 4) = 1;
                }
                uVar6 = (int)uVar4 + 1;
                uVar4 = (ulonglong)uVar6;
              } while (uVar6 < *(uint *)(param_1 + 0x10));
            }
            *(longlong *)(param_2 + 2) = lVar3;
            *param_2 = *(undefined4 *)(param_1 + 0x10);
            if (local_res18[0] != 0) {
              ExFreePoolWithTag(local_res18[0],0x49504550);
            }
            return (ulonglong)uVar2;
          }
        }
      }
    }
    uVar2 = 0xc000009a;
  }
  DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: Missing or malformed LPIT from firmware\n");
  PepAcpiFatalBiosError(uVar2);
  pcVar1 = (code *)swi(3);
  uVar4 = (*pcVar1)();
  return uVar4;
}



===== PepAcpiGetTable @ 1400086fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PepAcpiGetTable(undefined4 param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *_Dst;
  undefined1 auStack_78 [32];
  int local_58 [2];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  local_44 = 0;
  local_58[0] = 0;
  local_4c = 1;
  local_50 = 0x41435049;
  local_48 = param_1;
  iVar2 = ZwQuerySystemInformation(0x4c,&local_50,0x14,local_58);
  if (iVar2 == -0x3fffffdd) {
    puVar3 = (undefined4 *)ExAllocatePool2(0x40,local_58[0],0x49504550);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *puVar3 = 0x41435049;
      puVar3[1] = 1;
      puVar3[2] = param_1;
      puVar3[3] = local_58[0] + -0x10;
      iVar2 = ZwQuerySystemInformation(0x4c,puVar3,local_58[0],local_58);
      if (-1 < iVar2) {
        uVar1 = puVar3[3];
        _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar1,0x49504550);
        if (_Dst == (void *)0x0) {
          iVar2 = -0x3fffff66;
        }
        else {
          memmove(_Dst,puVar3 + 4,(ulonglong)uVar1);
          *param_2 = _Dst;
        }
      }
      ExFreePoolWithTag(puVar3,0x49504550);
    }
  }
  else {
    iVar2 = -0x3fffffff;
  }
  return iVar2;
}



===== PepAcpiInitUnicodeString @ 140008854 =====

undefined4 PepAcpiInitUnicodeString(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitString(&local_18);
  uVar1 = RtlxAnsiStringToUnicodeSize(&local_18);
  lVar2 = ExAllocatePool2(0x40,uVar1,0x49504550);
  if (lVar2 == 0) {
    uVar1 = 0xc000009a;
    DbgPrintEx(0x92,1,"INTELPEP: BIOS WARNING: Could not allocate memory for device names.\n");
  }
  else {
    *(longlong *)(param_1 + 8) = lVar2;
    *(short *)(param_1 + 2) = (short)uVar1;
    uVar1 = RtlAnsiStringToUnicodeString(param_1,&local_18,0);
  }
  return uVar1;
}



===== PepAcpiLpitBuilder @ 140008904 =====

int PepAcpiLpitBuilder(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong local_res10;
  
  local_res10 = 0;
  iVar1 = PepAcpiGetTable(0x5449504c,&local_res10);
  lVar3 = local_res10;
  if (iVar1 < 0) {
    DbgPrintEx(0x92,2,"INTELPEP: Failed to get LPIT!\n");
  }
  else {
    uVar2 = PepValidateAcpiLpit(local_res10,param_1);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) goto LAB_140008987;
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x49504550);
    lVar3 = 0;
  }
LAB_140008987:
  *param_2 = lVar3;
  return iVar1;
}



===== PepAcpiParseCore @ 1400089a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepAcpiParseCore(byte *param_1,uint param_2,short *param_3,ulonglong param_4,longlong param_5,
                    int param_6,undefined8 param_7)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  ulonglong uVar4;
  byte *pbVar5;
  char *pcVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar9 = (ulonglong)param_2;
  uVar7 = 0;
  uVar8 = 0;
  uVar10 = param_1[(ulonglong)(param_2 - 1) * 0x18] + 1;
  psVar3 = (short *)((param_4 & 0xffffffff) + (longlong)param_3);
  do {
    if (psVar3 <= param_3) {
      if (uVar8 == uVar10) {
        return 0;
      }
      pcVar6 = "INTELPEP: BIOS ERROR: %s has too few elements, expected %d.\n";
LAB_140008bb0:
      DbgPrintEx(0x92,0,pcVar6,param_7,uVar10);
      return -0x3febfff5;
    }
    if (uVar10 <= uVar8) {
      pcVar6 = "INTELPEP: BIOS ERROR: %s has too many elements (%d expected)\n";
      goto LAB_140008bb0;
    }
    sVar1 = *param_3;
    while( true ) {
      if (param_2 <= (uint)uVar7) goto LAB_140008aa9;
      pbVar5 = param_1 + uVar7 * 0x18;
      if ((*pbVar5 == uVar8) && (*(short *)(pbVar5 + 2) == sVar1)) break;
      uVar7 = (ulonglong)((uint)uVar7 + 1);
    }
    if (pbVar5 == (byte *)0x0) {
LAB_140008aa9:
      uVar7 = 0;
      if (param_2 == 0) {
        return -0x3febfff8;
      }
      pbVar5 = param_1;
      break;
    }
    iVar2 = (**(code **)(pbVar5 + 0x10))
                      (param_3,(ulonglong)*(ushort *)(pbVar5 + 4) + param_5,
                       param_6 - (uint)*(ushort *)(pbVar5 + 4));
    if (iVar2 < 0) {
      DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: %s.%s is malformed.\n",param_7,
                 *(undefined8 *)(pbVar5 + 8));
      return iVar2;
    }
    uVar4 = (ulonglong)(ushort)param_3[1];
    uVar8 = uVar8 + 1;
    if ((ushort)param_3[1] < 4) {
      uVar4 = 4;
    }
    param_3 = (short *)((longlong)param_3 + uVar4 + 4);
  } while( true );
  while( true ) {
    uVar10 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar10;
    pbVar5 = pbVar5 + 0x18;
    if (param_2 <= uVar10) break;
    if (*pbVar5 == uVar8) break;
  }
  if ((uint)uVar7 < param_2) {
    if (sVar1 == 0) {
      pcVar6 = "INTEGER";
    }
    else if (sVar1 == 1) {
      pcVar6 = "STRING";
    }
    else if (sVar1 == 2) {
      pcVar6 = "BUFFER";
    }
    else if ((sVar1 == 3) || (sVar1 == 4)) {
      pcVar6 = "PACKAGE";
    }
    else {
      pcVar6 = "UNKNOWN";
    }
    DbgPrintEx(0x92,3,"INTELPEP: BIOS ERROR: %s.%s has an unexpected type %s.  Acceptable types:\n",
               param_7,*(undefined8 *)(param_1 + uVar7 * 0x18 + 8),pcVar6);
    do {
      if (*param_1 == uVar8) {
        sVar1 = *(short *)(param_1 + 2);
        if (sVar1 == 0) {
          pcVar6 = "    INTEGER\n";
        }
        else if (sVar1 == 1) {
          pcVar6 = "    STRING\n";
        }
        else {
          if (sVar1 != 2) goto LAB_140008b98;
          pcVar6 = "    BUFFER\n";
        }
        DbgPrintEx(0x92,0,pcVar6);
      }
LAB_140008b98:
      param_1 = param_1 + 0x18;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  return -0x3febfff8;
}



===== PepAcpiParseULong @ 140008c10 =====

undefined8 PepAcpiParseULong(longlong param_1,undefined4 *param_2,uint param_3)

{
  if (param_3 < 4) {
    return 0xc000000d;
  }
  *param_2 = *(undefined4 *)(param_1 + 4);
  return 0;
}



===== PepAcpiParseULong64 @ 140008c30 =====

undefined8 PepAcpiParseULong64(longlong param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (param_3 < 8) {
    uVar1 = 0xc000000d;
  }
  else if (*(ushort *)(param_1 + 2) < 9) {
    *param_2 = 0;
    memmove(param_2,(void *)(param_1 + 4),(ulonglong)*(ushort *)(param_1 + 2));
    uVar1 = 0;
  }
  else {
    DbgPrintEx(0x92,0,"INTELPEP: PepAcpiParseULong: Element must be <=64 bit buffer.\n");
    uVar1 = 0xc0140008;
  }
  return uVar1;
}



===== PepAcpiQueryPlatformNotificationSupport @ 140008c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 PepAcpiQueryPlatformNotificationSupport(int param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  if (param_1 == 0) {
    if (((*(uint *)(lVar1 + 8) >> 5 & 1) != 0) && (uVar2 = 0, (*(uint *)(lVar1 + 8) >> 6 & 1) != 0))
    {
      uVar2 = 1;
    }
  }
  else if (((param_1 == 1) && ((*(uint *)(lVar1 + 8) >> 3 & 1) != 0)) &&
          ((*(uint *)(lVar1 + 8) >> 4 & 1) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== RtlULongLongMult @ 140008d10 =====

undefined8 RtlULongLongMult(ulonglong param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uVar3;
  
  uVar3 = 0;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_2;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    *param_3 = SUB168(auVar1 * auVar2,0);
  }
  else {
    *param_3 = 0xffffffffffffffff;
    uVar3 = 0xc0000095;
  }
  return uVar3;
}



===== RtlUnicodeStringCopy @ 140008d38 =====

ulonglong RtlUnicodeStringCopy(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  puVar2 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  puVar4 = (undefined2 *)0x0;
  if (((int)uVar1 < 0) || (puVar2 == (ushort *)0x0)) {
    lVar8 = 0;
    uVar5 = 0;
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
  }
  else {
    lVar8 = *(longlong *)(puVar2 + 4);
    uVar5 = (ulonglong)(puVar2[1] >> 1);
  }
  uVar1 = RtlUnicodeStringValidateWorker(param_2);
  uVar7 = uVar1 & 0xffffffff;
  if (((int)uVar1 < 0) || (param_2 == (ushort *)0x0)) {
    puVar3 = puVar4;
    puVar6 = puVar4;
    if ((int)uVar1 < 0) goto LAB_140008de3;
  }
  else {
    puVar3 = (undefined2 *)(ulonglong)(*param_2 >> 1);
    puVar6 = *(undefined2 **)(param_2 + 4);
  }
  uVar7 = (ulonglong)puVar4 & 0xffffffff;
  if (uVar5 != 0) {
    lVar8 = lVar8 - (longlong)puVar6;
    do {
      if (puVar3 == (undefined2 *)0x0) goto LAB_140008de3;
      puVar3 = (undefined2 *)((longlong)puVar3 + -1);
      *(undefined2 *)(lVar8 + (longlong)puVar6) = *puVar6;
      puVar4 = (undefined2 *)((longlong)puVar4 + 1);
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (puVar3 != (undefined2 *)0x0) {
    uVar7 = 0x80000005;
  }
LAB_140008de3:
  *param_1 = (short)puVar4 * 2;
  return uVar7;
}



===== RtlUnicodeStringValidateWorker @ 140008e0c =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== PepBccdInitialize @ 140008e54 =====

void PepBccdInitialize(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  
  if (*(uint *)(param_1 + 0x10) != 0) {
    piVar5 = (int *)(param_1 + 0x2c);
    uVar6 = (ulonglong)*(uint *)(param_1 + 0x10);
    do {
      uVar4 = PepValidateAndInitAddress(piVar5 + -1);
      if ((int)uVar4 < 0) {
LAB_140008f29:
        piVar5[-3] = 0;
      }
      else {
        iVar1 = piVar5[-1];
        if (iVar1 == 0) {
          piVar5[-3] = 3;
        }
        else if ((iVar1 == 0x7f) && (*piVar5 != 1)) {
          piVar5[-3] = 1;
        }
        else {
          if (iVar1 != 1) goto LAB_140008f29;
          piVar5[-3] = 4;
        }
        iVar1 = *piVar5;
        uVar2 = *(ulonglong *)(piVar5 + 0xd);
        uVar3 = *(ulonglong *)(piVar5 + 0xf);
        if (iVar1 == 8) {
          if ((0xff < uVar2) || (0xff < uVar3)) {
LAB_140008f0a:
            DbgPrintEx(0x92,1,
                       "INTELPEP: BIOS WARNING: BCCD mask information inconsistent with address definition.\n"
                      );
          }
        }
        else if (((iVar1 == 0x10) && ((0xffff < uVar2 || (0xffff < uVar3)))) ||
                ((iVar1 == 0x20 && ((0xffffffff < uVar2 || (0xffffffff < uVar3))))))
        goto LAB_140008f0a;
      }
      piVar5 = piVar5 + 0x18;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}



===== PepBccdTriggerPowerUp @ 140008f58 =====

void PepBccdTriggerPowerUp(longlong param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong local_res8;
  
  local_res8 = 0;
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      local_res8 = *(ulonglong *)(param_1 + 0x48);
LAB_140009019:
      PepWriteRegisterWithBus(piVar1,0,&local_res8);
      goto LAB_140008fd3;
    }
    if (iVar2 == 2) {
      local_res8 = *(ulonglong *)(param_1 + 0x48);
    }
    else {
      if (iVar2 == 3) {
        PepReadRegisterWithBus(piVar1,0,(uint *)&local_res8);
        local_res8 = *(ulonglong *)(param_1 + 0x40) & local_res8 | *(ulonglong *)(param_1 + 0x48);
        goto LAB_140009019;
      }
      if (iVar2 != 4) goto LAB_140008fd3;
      PepReadRegisterWithBus(piVar1,0,(uint *)&local_res8);
      local_res8 = *(ulonglong *)(param_1 + 0x40) & local_res8 | *(ulonglong *)(param_1 + 0x48);
    }
    PepWriteRegisterWithBus(piVar1,0,&local_res8);
  }
  PepReadRegisterWithBus(piVar1,0,(uint *)&local_res8);
LAB_140008fd3:
  KeStallExecutionProcessor(*(undefined4 *)(param_1 + 0x58));
  return;
}



===== PepValidateAcpiLpit @ 140009034 =====

undefined8 PepValidateAcpiLpit(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar6 = *(int *)(param_1 + 4) - 0x24;
  uVar4 = (ulonglong)uVar6 / 7;
  uVar5 = 0;
  lVar9 = 0;
  uVar4 = (uVar6 - uVar4 >> 1) + uVar4 >> 5;
  if ((ulonglong)uVar6 == uVar4 * 0x38) {
    *(undefined8 *)(param_2 + 0xc) = 0;
    for (uVar6 = 0; uVar6 < (uint)uVar4; uVar6 = uVar6 + 1) {
      lVar8 = (ulonglong)uVar6 * 0x38 + param_1;
      if ((*(byte *)(lVar8 + 0x30) & 1) == 0) {
        if (*(int *)(lVar8 + 0x24) != 0) {
          uVar5 = 0xc0000001;
          pcVar7 = "INTELPEP: BIOS ERROR: LPIT contains unsupported StateType!\n";
          goto LAB_14000907b;
        }
        pbVar1 = (byte *)(param_2 + 0xc + ((longlong)(int)(uint)*(ushort *)(lVar8 + 0x2c) >> 3));
        uVar2 = *(ushort *)(lVar8 + 0x2c) & 7;
        bVar3 = *pbVar1;
        *pbVar1 = *pbVar1 | '\x01' << uVar2;
        if ((bVar3 >> uVar2 & 1) != 0) {
          uVar5 = 0xc0000001;
          pcVar7 = "INTELPEP: BIOS ERROR: LPIT contains duplicate Unique IDs!\n";
          goto LAB_14000907b;
        }
        if ((lVar9 != 0) && (*(ushort *)(lVar8 + 0x2c) < *(ushort *)(lVar9 + 8))) {
          DbgPrintEx(0x92,0,
                     "INTELPEP: BIOS ERROR: Descriptor entries %lu and %lu are non-monotonically increasing.\n"
                     ,uVar6 - 1,uVar6);
          goto LAB_140009147;
        }
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
        lVar9 = lVar8 + 0x24;
      }
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: LpiCount is zero!\n");
LAB_140009147:
      uVar5 = 0xc0000001;
    }
  }
  else {
    pcVar7 = "INTELPEP: BIOS ERROR: LPIT descriptors unexpected length!\n";
LAB_14000907b:
    DbgPrintEx(0x92,0,pcVar7);
  }
  return uVar5;
}



===== PepValidateDeviceDependencyList @ 140009160 =====

undefined8
PepValidateDeviceDependencyList(longlong param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar3 = 0;
  if (param_2 == 0) {
    DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: Dependency List is NULL\n");
LAB_1400091a5:
    uVar3 = 0xc0000001;
  }
  else {
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
      uVar2 = (ulonglong)uVar4;
      if (0xff < *(uint *)(param_2 + 8 + uVar2 * 0xc)) {
        pcVar5 = "INTELPEP: BIOS ERROR: Invalid f-state constraint for device: %s.\n";
LAB_14000925c:
        DbgPrintEx(0x92,0,pcVar5,param_4);
        return 0xc0000001;
      }
      uVar1 = *(uint *)(param_2 + uVar2 * 0xc);
      if (0xff < uVar1) {
        pcVar5 = "INTELPEP: BIOS ERROR: LPI Id dependency greater than MAX_LPIT_ID for device: %s\n"
        ;
        goto LAB_14000925c;
      }
      if (3 < *(uint *)(param_2 + 4 + uVar2 * 0xc)) {
        uVar3 = 0xc0000001;
        DbgPrintEx(0x92,0,
                   "INTELPEP: BIOS ERROR: Device %s has invalid Dstate constraint for LPI ID %lu\n",
                   param_4,uVar1);
      }
      uVar1 = *(uint *)(param_2 + uVar2 * 0xc);
      if ((uVar1 != 0xff) &&
         ((*(byte *)(param_1 + 0xc + ((longlong)(int)uVar1 >> 3)) >> (uVar1 & 7) & 1) == 0)) {
        DbgPrintEx(0x92,0,
                   "INTELPEP: BIOS ERROR: %s has a dependency (%lu) with an invalid LpiId of %lu.\n"
                   ,param_4,uVar4,uVar1);
        goto LAB_1400091a5;
      }
    }
  }
  return uVar3;
}



===== PepValidateDevxEntry @ 14000929c =====

undefined8 PepValidateDevxEntry(char *param_1,longlong param_2)

{
  size_t sVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    pcVar3 = "INTELPEP: BIOS ERROR: NULL Devx Entry.\n";
  }
  else {
    sVar1 = strnlen(param_1,0x80);
    if ((int)sVar1 != 0) {
      if (*(uint *)(param_2 + 0x10) < *(uint *)(param_1 + 0x84)) {
        DbgPrintEx(0x92,0,"INTELPEP: BIOS ERROR: %s has more dependencies than LPIT entries.\n");
        return 0xc0000001;
      }
      uVar2 = PepValidateDeviceDependencyList
                        (param_2,*(longlong *)(param_1 + 0x88),*(uint *)(param_1 + 0x84),param_1);
      return uVar2;
    }
    pcVar3 = "INTELPEP: BIOS ERROR: Devx Entry Unique ID empty.\n";
  }
  DbgPrintEx(0x92,0,pcVar3);
  return 0xc0000001;
}



===== PepValidateDevxList @ 140009340 =====

undefined8 PepValidateDevxList(uint *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  uint *_Str1;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  do {
    if (*param_1 <= uVar4) {
      return uVar2;
    }
    _Str1 = param_1 + (ulonglong)uVar4 * 0x24 + 2;
    uVar4 = uVar4 + 1;
    for (uVar3 = uVar4; uVar3 < *param_1; uVar3 = uVar3 + 1) {
      iVar1 = strncmp((char *)_Str1,(char *)(param_1 + (ulonglong)uVar3 * 0x24 + 2),0x80);
      if (iVar1 == 0) {
        DbgPrintEx(0x92,0,"INTLEPEP: BIOS ERROR: Devx Entries with ID: %s is not unique\n",_Str1);
        return 0xc0000001;
      }
    }
    uVar2 = PepValidateDevxEntry((char *)_Str1,param_2);
  } while (-1 < (int)uVar2);
  return uVar2;
}



===== PepCheckPciDeviceSecure @ 140009408 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 PepCheckPciDeviceSecure(longlong param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  uint local_44;
  undefined1 local_40;
  byte local_3f;
  byte local_3e;
  undefined1 local_3d;
  undefined8 local_38;
  undefined8 uStack_30;
  uint local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar3 = 0;
  local_3d = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_1 != 0) {
    local_28 = *(uint *)(param_1 + 0x10);
    uStack_24 = *(undefined4 *)(param_1 + 0x14);
    uStack_20 = *(undefined4 *)(param_1 + 0x18);
    uStack_1c = *(undefined4 *)(param_1 + 0x1c);
    local_18 = *(undefined4 *)(param_1 + 0x20);
    local_44 = param_2 >> 8 & 0xffff;
    local_48 = 2;
    local_3f = (byte)local_28 & 0x1f;
    local_40 = (undefined1)param_2;
    local_3e = (byte)(local_28 >> 5) & 7;
    if (PepPcieSecurePcieEnabled != '\0') {
      puVar2 = &local_48;
      iVar1 = VslQuerySecureDevice(puVar2,&local_38);
      if ((iVar1 < 0) || ((char)local_38 != '\0')) {
        uVar3 = 1;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  (puVar2,(int)&local_28,iVar1,"Attempted to write to a secure device");
      }
    }
  }
  return uVar3;
}



===== PepValidateAndInitAddress @ 1400094cc =====

uint PepValidateAndInitAddress(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  undefined4 uVar11;
  longlong lVar12;
  uint uVar13;
  char *pcVar14;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if (param_1 == (int *)0x0) {
    return 0xc000000d;
  }
  iVar5 = param_1[4];
  iVar6 = param_1[5];
  uVar7 = param_1[6];
  uVar8 = param_1[7];
  uVar1 = param_1[8];
  iVar2 = param_1[2];
  local_res20 = 0;
  uVar3 = param_1[1];
  iVar4 = param_1[3];
  local_res18 = 0;
  lVar12 = *(longlong *)(param_1 + 10);
  iVar10 = *param_1;
  if (iVar10 == 0) {
LAB_140009660:
    if (((((uVar3 == 8) && (iVar4 == 1)) || ((uVar3 == 0x40 && (iVar4 == 4)))) ||
        (((uVar3 == 0x10 && (iVar4 == 2)) || ((uVar3 == 0x20 && (iVar4 == 3)))))) &&
       ((iVar2 == 0 && (lVar12 != 0)))) {
      bVar9 = true;
      lVar12 = MmMapIoSpaceEx(lVar12,uVar3 >> 3,0x204);
      if (lVar12 == 0) {
        uVar13 = 0xc000009a;
        pcVar14 = 
        "INTELPEP: WARNING:  Cannot allocate memory for residency counter register for platform idle state\n"
        ;
        goto LAB_140009764;
      }
    }
    else {
      bVar9 = false;
      lVar12 = 0;
    }
    *(longlong *)(param_1 + 0xc) = lVar12;
    if (bVar9) {
      return 0;
    }
LAB_14000975a:
    pcVar14 = "INTELPEP: BIOS WARNING: Unsupported ACPI generic register.\n";
  }
  else {
    if (iVar10 == 1) {
      if (((((uVar3 == 8) && (iVar4 == 1)) || ((uVar3 == 0x10 && (iVar4 == 2)))) ||
          ((uVar3 == 0x20 && (iVar4 == 3)))) && ((iVar2 == 0 && (lVar12 - 1U < 0xffff)))) {
        return 0;
      }
      goto LAB_14000975a;
    }
    if (iVar10 == 2) {
      return 0;
    }
    if (iVar10 == 0x7f) {
      if ((((uVar3 - 1 < 0x40) &&
           ((0x8000000080000001U >> ((ulonglong)(uVar3 - 1) & 0x3f) & 1) != 0)) && (iVar2 == 0)) &&
         (iVar4 == 0)) {
        return 0;
      }
      param_1[10] = 0;
      param_1[0xb] = 0;
      goto LAB_14000975a;
    }
    if (iVar10 != 0x80) goto LAB_14000975a;
    if ((int)((ulonglong)*(undefined8 *)(param_1 + 4) >> 0x20) != 3) {
      if (iVar6 == 4) {
        iVar10 = HalGetBusDataByOffset(4,0,iVar5,&local_res18,uVar7,8);
        iVar10 = iVar10 + -8;
        goto LAB_1400095c0;
      }
      uVar13 = 0xc0000001;
LAB_1400096e5:
      pcVar14 = "INTELPEP: WARNING:  Failed to read Base Addressfor a system register\n";
      goto LAB_140009764;
    }
    iVar10 = HalGetBusDataByOffset(4,0,iVar5,&local_res18,uVar7,4);
    iVar10 = iVar10 + -4;
LAB_1400095c0:
    uVar13 = -(uint)(iVar10 != 0) & 0xc0000001;
    if (uVar13 != 0) goto LAB_1400096e5;
    if (local_res18 != 0) {
      if (uVar7 < 0x10) {
LAB_14000961a:
        if (0x24 < uVar7) goto LAB_14000961f;
      }
      else {
        if (uVar7 < 0x25) {
          if ((local_res18 & 1) != 0) goto LAB_1400095f5;
          goto LAB_14000961a;
        }
LAB_14000961f:
        if ((uVar8 & local_res18) != (ulonglong)uVar1) {
LAB_1400095f5:
          DbgPrintEx(0x92,1,
                     "INTELPEP: WARNING:  PCI BAR masked value does notequal expected value\n");
          return 0xc0000001;
        }
      }
      if ((iVar6 == 3) && (((byte)local_res18 & 6) == 4)) {
        return 0xc0000001;
      }
      local_res20 = CONCAT44(local_res20._4_4_,(int)local_res18) & 0xfffffffffffffff0;
      if (iVar6 == 4) {
        uVar11 = local_res20._4_4_;
        if (((byte)local_res18 & 6) == 4) {
          uVar11 = local_res18._4_4_;
        }
        local_res20 = CONCAT44(uVar11,(undefined4)local_res20);
      }
      lVar12 = lVar12 + local_res20;
      goto LAB_140009660;
    }
    pcVar14 = "INTELPEP: WARNING: PCI bar address read is 0\n";
  }
  uVar13 = 0xc0000001;
LAB_140009764:
  DbgPrintEx(0x92,1,pcVar14);
  return uVar13;
}



===== PepWritePciReg @ 140009794 =====

void PepWritePciReg(longlong param_1,uint param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  char cVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  int iStack_24;
  undefined4 uStack_20;
  
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  uVar4 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && (cVar3 = PepCheckPciDeviceSecure(param_1,param_2), cVar3 != '\0')) {
    return;
  }
  iStack_24 = (int)(uVar1 >> 0x20);
  if (iStack_24 == 3) {
    uVar5 = 4;
  }
  else {
    if (iStack_24 != 4) {
      return;
    }
    uVar5 = 8;
  }
  uStack_20 = (undefined4)uVar2;
  HalSetBusDataByOffset(4,param_2,uVar1 & 0xffffffff,param_3,uStack_20,uVar5);
  return;
}



===== PepGetHwResidency @ 140009820 =====

void PepGetHwResidency(uint param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong local_res10;
  longlong local_res18;
  
  local_res10 = 0;
  lVar2 = PepGetPlatformStateInfo(param_1);
  PepReadResidencyCounter(lVar2,&local_res10);
  lVar1 = *(longlong *)(param_2 + (ulonglong)param_1 * 8);
  uVar6 = (ulonglong)param_1;
  if ((longlong)local_res10 < lVar1) {
    if (*(int *)(lVar2 + 0x24) == 0x40) {
      lVar3 = -1;
    }
    else {
      lVar3 = 0;
      if (*(int *)(lVar2 + 0x24) == 0x20) {
        lVar3 = 0xffffffff;
      }
    }
    lVar3 = lVar3 - lVar1;
  }
  else {
    lVar3 = -lVar1;
  }
  local_res10 = local_res10 + lVar3;
  uVar7 = *(ulonglong *)(lVar2 + 0x18);
  local_res18 = 0;
  uVar5 = local_res10 % uVar7;
  uVar4 = RtlULongLongMult(local_res10 / uVar7,10000000,&local_res18);
  if ((int)uVar4 < 0) {
    local_res18 = 0;
  }
  else {
    local_res18 = (uVar5 * 10000000) / uVar7 + local_res18;
  }
  *(uint *)(param_3 + 4 + uVar6 * 0x10) = (uint)(local_res18 != 0);
  *(longlong *)(param_3 + 8 + uVar6 * 0x10) = local_res18;
  return;
}



===== PepGetPlatformStateHwResidency @ 140009904 =====

void PepGetPlatformStateHwResidency(uint param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  byte *pbVar2;
  longlong lVar3;
  bool bVar4;
  uint local_res20 [2];
  uint local_18 [4];
  
  local_res20[0] = (1 << ((byte)PepNumPlatformStates & 0x1f)) - 1;
  PepGetHwResidency(param_1,param_2,param_3);
  pbVar2 = (byte *)((longlong)local_res20 + ((longlong)(int)param_1 >> 3));
  *pbVar2 = *pbVar2 & ~('\x01' << (param_1 & 7));
  lVar3 = PepGetPlatformStateInfo(param_1);
  local_18[0] = *(uint *)(lVar3 + 0x58);
  uVar1 = 0;
  bVar4 = local_18[0] != 0;
  if (bVar4) {
    for (; (local_18[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
    }
  }
  while (bVar4) {
    *(undefined8 *)(param_3 + 8 + (ulonglong)uVar1 * 0x10) = 0;
    *(undefined4 *)(param_3 + 4 + (ulonglong)uVar1 * 0x10) = 0;
    pbVar2 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar1 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    pbVar2 = (byte *)((longlong)local_18 + ((longlong)(int)uVar1 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    uVar1 = 0;
    bVar4 = local_18[0] != 0;
    if (bVar4) {
      for (; (local_18[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
  }
  while( true ) {
    uVar1 = 0x1f;
    if (local_res20[0] != 0) {
      for (; local_res20[0] >> uVar1 == 0; uVar1 = uVar1 - 1) {
      }
    }
    if (local_res20[0] == 0) break;
    PepGetHwResidency(uVar1,param_2,param_3);
    pbVar2 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar1 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    lVar3 = PepGetPlatformStateInfo(uVar1);
    local_18[0] = *(uint *)(lVar3 + 0x58);
    uVar1 = 0;
    bVar4 = local_18[0] != 0;
    if (bVar4) {
      for (; (local_18[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
    while (bVar4) {
      *(undefined8 *)(param_3 + 8 + (ulonglong)uVar1 * 0x10) = 0;
      *(undefined4 *)(param_3 + 4 + (ulonglong)uVar1 * 0x10) = 0;
      pbVar2 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar1 >> 3));
      *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
      pbVar2 = (byte *)((longlong)local_18 + ((longlong)(int)uVar1 >> 3));
      *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
      uVar1 = 0;
      bVar4 = local_18[0] != 0;
      if (bVar4) {
        for (; (local_18[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
        }
      }
    }
  }
  return;
}



===== PepGetTscFrequencyInHz @ 1400099ec =====

int PepGetTscFrequencyInHz(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = TscFrequencyInHz;
  iVar2 = 0;
  *param_1 = 0;
  if (lVar1 == 0) {
    iVar2 = PepNumProcessors * 0x18;
    lVar1 = ExAllocatePool2(0x40,iVar2,0x49504550);
    if (lVar1 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = ZwPowerInformation(0xb,0,0,lVar1,iVar2);
      if (-1 < iVar2) {
        TscFrequencyInHz = (ulonglong)*(uint *)(lVar1 + 4) * 1000000;
        *param_1 = TscFrequencyInHz;
      }
      ExFreePoolWithTag(lVar1,0);
    }
  }
  else {
    *param_1 = lVar1;
  }
  return iVar2;
}



===== PepReadResidencyCounter @ 140009aa8 =====

void PepReadResidencyCounter(longlong param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  
  *param_2 = 0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(int *)(param_1 + 0x24) == 0x40) {
      uVar1 = 0xffffffffffffffff;
    }
    else {
      if (*(int *)(param_1 + 0x24) != 0x20) {
        return;
      }
      uVar1 = 0xffffffff;
    }
    PepReadRegisterWithBus((int *)(param_1 + 0x20),0,(uint *)param_2);
    *param_2 = *param_2 & uVar1;
  }
  return;
}



===== PepResidencyCounterDuplicate @ 140009afc =====

undefined8 PepResidencyCounterDuplicate(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_2 + 0x10);
  uVar2 = 0;
  if ((((*(uint *)(param_1 + 0x10) == *(uint *)(param_2 + 0x10)) &&
       (uVar1 = (ulonglong)*(uint *)(param_2 + 0x14),
       *(uint *)(param_1 + 0x14) == *(uint *)(param_2 + 0x14))) &&
      (uVar1 = (ulonglong)*(uint *)(param_2 + 0x18),
      *(uint *)(param_1 + 0x18) == *(uint *)(param_2 + 0x18))) &&
     (*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c))) {
    uVar1 = 0;
    uVar2 = 0;
    if (*(longlong *)(param_1 + 0x38) == *(longlong *)(param_2 + 0x38)) {
      uVar2 = 1;
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== PepDbgDereferenceCallbacks @ 140009b50 =====

void PepDbgDereferenceCallbacks(void)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xa0,0,0,0,0);
}



===== PepDbgDeviceProcessQueryInterfaceRequest @ 140009b80 =====

undefined8
PepDbgDeviceProcessQueryInterfaceRequest(undefined8 param_1,undefined8 param_2,short *param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  if ((param_3 == (short *)0x0) || (*param_3 != 0x28)) {
    uVar2 = 0xc000000d;
  }
  else {
    if (param_3[1] == 2) {
      uVar1 = 1;
    }
    else {
      if (param_3[1] != 1) {
        return 0xc00000bb;
      }
      uVar1 = 0;
    }
    LOCK();
    bVar3 = PepDbgInterfaceInUse == 0;
    if (bVar3) {
      PepDbgInterfaceInUse = 1;
    }
    UNLOCK();
    if (bVar3) {
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
      *(code **)(param_3 + 0xc) = PepDbgDereferenceCallbacks;
      *(code **)(param_3 + 0x10) = PepDbgRegisterDebugCallbacks;
      *(code **)(param_3 + 8) = _guard_check_icall;
      PepDebugInterfaceV2Supported = uVar1;
    }
    else {
      uVar2 = 0xc0000708;
    }
  }
  return uVar2;
}



===== PepDbgInitializeInterface @ 140009c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepDbgInitializeInterface(void)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong local_38 [2];
  undefined *local_28;
  undefined8 uStack_20;
  code *local_18;
  undefined8 uStack_10;
  
  uVar1 = PepWdfDevice;
  local_38[0] = (ulonglong)(uint)local_38[0];
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                    (WdfDriverGlobals,PepWdfDevice,&GUID_DEVINTERFACE_INTELPEP,0);
  if (-1 < iVar2) {
    uStack_10 = 1;
    local_38[1] = 0;
    uStack_20 = 0;
    local_28 = &GUID_PEP_DEBUG_INTERFACE;
    local_18 = PepDbgDeviceProcessQueryInterfaceRequest;
    local_38[0] = 0x30;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,uVar1,local_38);
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x270))
                (WdfDriverGlobals,uVar1,&GUID_DEVINTERFACE_INTELPEP,0,1);
    }
  }
  return iVar2;
}



===== PepDbgPlatformStateTransition @ 140009cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepDbgPlatformStateTransition(void)

{
  if (PepDbgPlatformStateCallback != (code *)0x0) {
    (*PepDbgPlatformStateCallback)();
  }
  return;
}



===== PepDbgPreprocessCallback @ 140009d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepDbgPreprocessCallback(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined2 *puVar2;
  int iVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar4 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&GUID_PEP_DEBUG_INTERFACE,0x10);
  if (lVar4 == 0x10) {
    puVar2 = *(undefined2 **)(lVar1 + 0x18);
    *puVar2 = *(undefined2 *)(lVar1 + 0x10);
    puVar2[1] = *(undefined2 *)(lVar1 + 0x12);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  if (iVar3 < 0) {
    DbgPrintEx(0x92,3,"INTELPEP: Interface PreProcess Failed (0x%x)\n",iVar3);
  }
  return iVar3;
}



===== PepDbgRegisterDebugCallbacks @ 140009de0 =====

void PepDbgRegisterDebugCallbacks(undefined8 *param_1)

{
  if (PepDebugInterfaceV2Supported != '\0') {
    PepDbgSubsystemQueryCallback = param_1[2];
  }
  PepDbgPlatformStateCallback = param_1[1];
  PepDbgDeviceStateCallback = *param_1;
  return;
}



===== PepDiagLogCtaCounter @ 140009e14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogCtaCounter(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined1 auStackY_c8 [32];
  undefined4 uVar3;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  longlong local_58 [2];
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  if (iVar1 == 1) {
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
    pbVar2 = &DAT_14002f98b;
LAB_140009fb9:
    local_98 = param_1[0xf];
    local_48 = &local_98;
  }
  else {
    if (iVar1 == 0xe) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
      pbVar2 = &DAT_1400303db;
      goto LAB_140009fb9;
    }
    if (iVar1 == 0xf) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
      local_98 = param_1[0xe];
      local_48 = &local_98;
      local_2c = 0;
      pbVar2 = &DAT_14002e6da;
      local_1c = 0;
      local_88[0] = *param_2;
      local_38 = local_88;
      local_90 = param_1[0xf];
      local_28 = &local_90;
      uVar3 = 6;
      local_30 = 8;
      local_20 = 8;
      goto LAB_140009fdf;
    }
    if (iVar1 == 0x10) {
      if (DAT_1400340a0 < 6) {
        return;
      }
      _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
      local_90 = param_1[0xe];
      local_48 = &local_90;
      local_2c = 0;
      pbVar2 = &DAT_14002df81;
      local_1c = 0;
      local_88[0] = *param_2;
      local_38 = local_88;
      local_98 = param_1[0xf];
      local_28 = &local_98;
      uVar3 = 6;
      local_30 = 8;
      local_20 = 8;
      goto LAB_140009fdf;
    }
    if (iVar1 != 0x12) {
      return;
    }
    if (DAT_1400340a0 < 6) {
      return;
    }
    _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
    local_90 = *param_2;
    local_48 = &local_90;
    pbVar2 = &DAT_140030a8e;
  }
  uVar3 = 4;
LAB_140009fdf:
  local_3c = 0;
  local_40 = 8;
  _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,pbVar2,param_1,param_2,uVar3,local_78);
  return;
}



===== PepDiagLogDbgPkgcFlowCntrWriteCmdFails @ 14000a010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogDbgPkgcFlowCntrWriteCmdFails(wchar_t *param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_68 [4];
  longlong local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_48,param_1);
      local_2c = 0;
      local_38 = local_78;
      local_1c = 0;
      local_28 = &local_70;
      local_78[0] = (undefined4)uVar2;
      local_30 = 4;
      local_20 = 8;
      local_70 = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ef9f,param_3,uVar2,5,local_68);
    }
  }
  return;
}



===== PepDiagLogGlobalLtrOverrideRegister @ 14000a0d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogGlobalLtrOverrideRegister
               (uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 auStackY_108 [32];
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  undefined8 local_b8 [4];
  uint *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if ((param_1 != (uint *)0x0) &&
     (local_18 = __security_cookie ^ (ulonglong)auStackY_108, 5 < DAT_1400340a0)) {
    uVar1 = *param_1;
    local_90 = 4;
    local_d8 = uVar1 >> 0x1f;
    local_98 = &local_d8;
    local_d4 = uVar1 >> 0x1e & 1;
    local_80 = 4;
    local_88 = &local_d4;
    local_d0 = uVar1 >> 0x1a & 7;
    local_70 = 4;
    local_78 = &local_d0;
    local_cc = uVar1 >> 0x10 & 0x3ff;
    local_60 = 4;
    local_68 = &local_cc;
    local_c8 = uVar1 >> 0xf & 1;
    local_50 = 4;
    local_58 = &local_c8;
    local_c4 = uVar1 >> 0xe & 1;
    local_40 = 4;
    local_48 = &local_c4;
    local_bc = uVar1 & 0x3ff;
    local_c0 = uVar1 >> 10 & 7;
    local_38 = &local_c0;
    local_30 = 4;
    local_28 = &local_bc;
    local_20 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f4bd,param_3,param_4,10,local_b8);
  }
  return;
}



===== PepDiagLogInconsistentPciLinkStates @ 14000a218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogInconsistentPciLinkStates
               (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,ulonglong param_4,
               uint param_5,uint param_6,uint param_7)

{
  undefined8 uVar1;
  undefined1 auStackY_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  ulonglong local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  ulonglong local_c8 [2];
  undefined8 local_b8 [4];
  undefined8 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  longlong local_88 [2];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  if ((((param_1 != (undefined8 *)0x0) &&
       (local_18 = __security_cookie ^ (ulonglong)auStackY_128, param_2 != (undefined8 *)0x0)) &&
      (param_3 != (undefined8 *)0x0)) &&
     ((5 < DAT_1400340a0 && (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')
      ))) {
    local_98 = &local_f8;
    local_8c = 0;
    local_90 = 8;
    local_f8 = 0x1000000;
    _tlgCreate1Sz_wchar_t(local_88,(wchar_t *)*param_1);
    local_f0 = *param_2;
    local_78 = &local_f0;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_e8 = *param_3;
    local_68 = &local_e8;
    local_e0 = param_4 & 0xffffffff;
    local_58 = &local_e0;
    local_d8 = (ulonglong)param_5;
    local_48 = &local_d8;
    local_d0 = (ulonglong)param_6;
    local_38 = &local_d0;
    local_c8[0] = (ulonglong)param_7;
    local_28 = local_c8;
    local_70 = 8;
    local_60 = 8;
    local_50 = 8;
    local_40 = 8;
    local_30 = 8;
    local_20 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002fe2c,param_3,param_4,10,local_b8);
  }
  return;
}



===== PepDiagLogIncorrectErPolicyRegister @ 14000a388 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogIncorrectErPolicyRegister(wchar_t *param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_3c = 0;
      local_48 = &local_78;
      uVar2 = 8;
      local_40 = 8;
      local_78 = 0x1000000;
      _tlgCreate1Sz_wchar_t(local_38,param_1);
      local_70 = *(undefined8 *)(param_2 + 0x28);
      local_28 = &local_70;
      local_1c = 0;
      local_20 = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e7f6,local_70,param_1,5,local_68);
    }
  }
  return;
}



===== PepDiagLogIncorrectPmtLtrThreshold @ 14000a454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogIncorrectPmtLtrThreshold
               (wchar_t *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 local_58 [32];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_2c = 0;
      local_38 = local_68;
      local_68[0] = 0x1000000;
      local_30 = 8;
      _tlgCreate1Sz_wchar_t(local_28,param_1);
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002dbb8,local_58,param_4,4,(undefined8 *)local_58);
    }
  }
  return;
}



===== PepDiagLogLpitFrequencyOverride @ 14000a504 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLpitFrequencyOverride(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_58 = &local_98;
      local_98 = 0x1000000;
      local_90 = *param_1;
      local_48 = &local_90;
      local_88 = *param_2;
      local_38 = &local_88;
      local_80 = *param_3;
      local_28 = &local_80;
      local_50 = 8;
      local_40 = 8;
      local_30 = 8;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002dec0,param_3,param_2,6,local_78);
    }
  }
  return;
}



===== PepDiagLogLtrOverrideRegisters @ 14000a5f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLtrOverrideRegisters(ushort *param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 auStackY_118 [32];
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0 [2];
  undefined8 local_c8 [4];
  uint *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint local_90 [2];
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if ((((param_1 != (ushort *)0x0) &&
       (local_18 = __security_cookie ^ (ulonglong)auStackY_118, param_2 != (uint *)0x0)) &&
      (param_3 != (uint *)0x0)) && (5 < DAT_1400340a0)) {
    local_a8 = local_90;
    local_a0 = 2;
    local_98 = *(undefined8 *)(param_1 + 4);
    uVar1 = *param_3;
    local_90[0] = (uint)*param_1;
    local_e8 = *param_2 >> 0x1f;
    local_88 = &local_e8;
    local_e4 = uVar1 >> 1 & 1;
    local_e0 = *param_2 >> 0xf & 1;
    local_78 = &local_e4;
    local_68 = &local_e0;
    local_90[1] = 0;
    local_dc = uVar1 & 1;
    local_80 = 4;
    local_58 = &local_dc;
    local_d8 = uVar1 >> 3 & 1;
    local_d4 = uVar1 >> 2 & 1;
    local_48 = &local_d8;
    local_38 = &local_d4;
    local_70 = 4;
    local_d0[0] = (uint)param_4 & 0xff;
    local_28 = local_d0;
    local_60 = 4;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    local_20 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f626,param_3,param_4,0xb,local_c8);
  }
  return;
}



===== PepDiagLogLtrOvrMbResponseHistrogram @ 14000a75c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLtrOvrMbResponseHistrogram
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_68 = &local_98;
      local_60 = 8;
      local_58 = &PepPcieLtrOvrMbResponseHistogramUs;
      local_50 = 0x50;
      local_48 = &PepPcieLtrOvrMbEnterResponseBuckets;
      local_38 = &PepPcieLtrOvrMbExitResponseBuckets;
      local_28 = &local_90;
      local_40 = 0x24;
      local_30 = 0x24;
      local_90 = 0x1000000;
      local_20 = 8;
      local_98 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e542,param_1,param_4,7,local_88);
    }
  }
  return;
}



===== PepDiagLogLtrValue @ 14000a84c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLtrValue(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  longlong local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (5 < DAT_1400340a0) {
    _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
    local_2c = 0;
    local_38 = &local_78;
    local_1c = 0;
    local_28 = &local_70;
    local_30 = 8;
    local_20 = 8;
    local_78 = param_2;
    local_70 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f9c7,param_3,param_2,5,local_68);
  }
  return;
}



===== PepDiagLogPchDeviceId @ 14000a8ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchDeviceId
               (undefined4 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined2 param_5)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined6 uVar3;
  undefined2 uVar4;
  undefined6 uVar5;
  undefined1 auStackY_e8 [32];
  undefined2 local_b8 [2];
  undefined2 local_b4 [2];
  undefined2 local_b0 [2];
  undefined2 local_ac [2];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar4 = (undefined2)param_4;
  uVar5 = (undefined6)((ulonglong)param_4 >> 0x10);
  uVar2 = (undefined2)param_3;
  uVar3 = (undefined6)((ulonglong)param_3 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_6c = 0;
      local_78 = &local_a0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_68 = local_a8;
      local_58 = local_b8;
      local_48 = local_b4;
      local_38 = local_b0;
      local_ac[0] = param_5;
      local_28 = local_ac;
      local_50 = 2;
      local_40 = 2;
      local_30 = 2;
      local_20 = 2;
      local_a0 = 0x1000000;
      local_70 = 8;
      local_60 = 4;
      local_b8[0] = param_2;
      local_b4[0] = uVar2;
      local_b0[0] = uVar4;
      local_a8[0] = param_1;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002fa0c,CONCAT62(uVar3,uVar2),CONCAT62(uVar5,uVar4),8,local_98);
    }
  }
  return;
}



===== PepDiagLogPchLtrMailboxFailure @ 14000aa04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchLtrMailboxFailure
               (ushort *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68 [4];
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (((param_1 != (ushort *)0x0) &&
      (local_18 = __security_cookie ^ (ulonglong)auStackY_a8, param_2 != (undefined8 *)0x0)) &&
     (5 < DAT_1400340a0)) {
    local_48 = local_30;
    local_40 = 2;
    local_38 = *(undefined8 *)(param_1 + 4);
    local_30[0] = (uint)*param_1;
    local_78[0] = *param_2;
    local_28 = local_78;
    local_30[1] = 0;
    local_20 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030b20,0,param_4,5,local_68);
  }
  return;
}



===== PepDiagLogPchLtrMbTimeout @ 14000aab4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchLtrMbTimeout
               (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  char *local_70 [7];
  longlong local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = (longlong)(int)param_1;
  local_70[0] = "PCH RP LTR Mail Box Initialization";
  local_70[1] = "PCH RP LTR Mail Box LTR applied";
  local_70[2] = "PCH RP LTR Mail Box LTR Restored";
  if ((param_1 < 3) && (5 < DAT_1400340a0)) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_char(local_38,local_70[lVar2]);
      local_1c = 0;
      local_28 = &local_78;
      local_78 = 0x1000000;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e39f,lVar2,param_4,4,local_70 + 3);
    }
  }
  return;
}



===== PepDiagLogPchLtrRegReadOnly @ 14000aba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchLtrRegReadOnly
               (ushort *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68 [4];
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if ((param_1 != (ushort *)0x0) &&
     (local_18 = __security_cookie ^ (ulonglong)auStackY_a8, 5 < DAT_1400340a0)) {
    local_48 = local_30;
    local_40 = 2;
    local_38 = *(undefined8 *)(param_1 + 4);
    local_30[0] = (uint)*param_1;
    local_78[0] = *param_2;
    local_28 = local_78;
    local_30[1] = 0;
    local_20 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e1eb,0,param_4,5,local_68);
  }
  return;
}



===== PepDiagLogPciLinkCounter @ 14000ac4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPciLinkCounter
               (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStackY_118 [32];
  longlong local_e8;
  undefined8 local_e0;
  longlong local_d8;
  undefined8 local_d0;
  longlong local_c8 [2];
  undefined8 local_b8 [4];
  longlong local_98 [2];
  undefined8 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar4 = param_1[3];
  if (lVar4 != 0) {
    uVar2 = CONCAT71((int7)((ulonglong)param_3 >> 8),*(undefined1 *)(lVar4 + 4));
    uVar1 = PepSubsystemGetPciLinkState(param_1,param_1[0xe],uVar2);
    uVar2 = PepSubsystemGetPciLinkState
                      (param_1,*param_2,
                       CONCAT71((int7)((ulonglong)uVar2 >> 8),*(undefined1 *)(lVar4 + 4)));
    lVar5 = (longlong)(int)uVar2;
    if (5 < DAT_1400340a0) {
      _tlgCreate1Sz_wchar_t(local_98,(wchar_t *)*param_1);
      local_e0 = param_1[0xe];
      local_88 = &local_e0;
      local_7c = 0;
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_78 = &local_d8;
      local_d0 = *param_2;
      local_68 = &local_d0;
      local_58 = local_c8;
      local_e8 = param_1[0xf];
      local_48 = &local_e8;
      local_80 = 8;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_d8 = (longlong)(int)uVar1;
      local_c8[0] = lVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002fda5,lVar5,param_4,8,local_b8);
    }
    puVar3 = (undefined8 *)(lVar4 + 0x10);
    lVar4 = 4;
    do {
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_98,(wchar_t *)*param_1);
        _tlgCreate1Sz_wchar_t((longlong *)&local_88,(wchar_t *)*puVar3);
        local_e8 = puVar3[3];
        local_78 = &local_e8;
        local_6c = 0;
        local_70 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f3da,lVar5,param_4,5,local_b8);
      }
      puVar3 = puVar3 + 6;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return;
}



===== PepDiagLogPkgcNormalizationCategorySum @ 14000adf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPkgcNormalizationCategorySum
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_e8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (5 < DAT_1400340a0) {
    local_b8 = PepSubsystemPkgcPc2Pc3LimitOrWake1CategorySum;
    local_68 = &local_b8;
    local_60 = 8;
    local_b0 = PepSubsystemPkgcPc2Pc3LimitOrWake2CategorySum;
    local_58 = &local_b0;
    local_a8 = PepSubsystemPkgcPc6Pc10WakeCategorySum;
    local_48 = &local_a8;
    local_a0 = PepSubsystemPkgcPc6Pc10LimitCategorySum;
    local_38 = &local_a0;
    local_98[0] = PepSubsystemPkgcPc2Pc3LimitOrWake3CategorySum;
    local_28 = local_98;
    local_50 = 8;
    local_40 = 8;
    local_30 = 8;
    local_20 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14003077c,param_3,param_4,7,local_88);
  }
  return;
}



===== PepDiagLogPkgcNormalizationOverflow @ 14000aee8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPkgcNormalizationOverflow
               (wchar_t *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  longlong local_58 [2];
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_58,param_1);
      local_3c = 0;
      local_48 = &local_98;
      local_2c = 0;
      local_1c = 0;
      local_38 = &local_90;
      local_28 = local_88;
      local_40 = 8;
      local_30 = 8;
      local_20 = 8;
      local_98 = param_2;
      local_90 = param_3;
      local_88[0] = param_4;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_1400306f4,param_3,param_4,6,local_78);
    }
  }
  return;
}



===== PepDiagLogPmcMailboxFails @ 14000afbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPmcMailboxFails(wchar_t *param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_b8 [32];
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78 [4];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_58,param_1);
      local_84 = (undefined4)param_3;
      local_48 = &local_88;
      local_88 = (undefined4)uVar2;
      local_38 = &local_84;
      local_40 = 4;
      local_80 = PepSleepStudySessionInstanceId;
      local_28 = &local_80;
      local_30 = 4;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_1400300cb,param_3,uVar2,6,local_78);
    }
  }
  return;
}



===== PepDiagLogPmtReadDuration @ 14000b094 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPmtReadDuration
               (undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_94 = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    local_58 = &local_90;
    local_48 = local_88;
    local_38 = &local_98;
    local_90 = 0x1000000;
    local_28 = &local_94;
    local_50 = 8;
    local_40 = 8;
    local_30 = 4;
    local_20 = 4;
    local_98 = param_1;
    local_88[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ec86,param_3,param_4,6,local_78);
  }
  return;
}



===== PepDiagLogRootPortParentLtrStatus @ 14000b14c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogRootPortParentLtrStatus
               (ushort *param_1,ushort *param_2,int param_3,undefined8 param_4,undefined2 param_5,
               undefined2 param_6,int param_7,int param_8,int param_9,ushort *param_10,
               ushort *param_11)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_218 [32];
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined1 local_1e5;
  undefined1 local_1e4 [4];
  undefined2 local_1e0 [2];
  undefined2 local_1dc [2];
  int local_1d8;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  int local_1c8 [2];
  undefined8 local_1c0;
  undefined8 local_1b8 [2];
  undefined8 local_1a8 [4];
  undefined8 *local_188;
  undefined8 local_180;
  uint *local_178;
  undefined8 local_170;
  undefined8 local_168;
  uint local_160;
  undefined4 local_15c;
  uint *local_158;
  undefined8 local_150;
  undefined8 local_148;
  uint local_140;
  undefined4 local_13c;
  int *local_138;
  undefined8 local_130;
  undefined1 *local_128;
  undefined8 local_120;
  undefined2 *local_118;
  undefined8 local_110;
  undefined2 *local_108;
  undefined8 local_100;
  int *local_f8;
  undefined8 local_f0;
  int *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0;
  undefined4 local_ac;
  uint *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint local_90;
  undefined4 local_8c;
  undefined8 *local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_1e5 = (undefined1)param_4;
  uVar3 = (undefined7)((ulonglong)param_4 >> 8);
  if ((((param_1 != (ushort *)0x0) &&
       (local_38 = __security_cookie ^ (ulonglong)auStackY_218, param_2 != (ushort *)0x0)) &&
      (param_10 != (ushort *)0x0)) && (param_11 != (ushort *)0x0)) {
    if (5 < DAT_1400340a0) {
      local_188 = &local_1c0;
      local_1c0 = 0x1000000;
      local_178 = &local_160;
      local_168 = *(undefined8 *)(param_1 + 4);
      local_160 = (uint)*param_1;
      local_158 = &local_140;
      local_148 = *(undefined8 *)(param_2 + 4);
      local_140 = (uint)*param_2;
      local_138 = &local_1d8;
      local_128 = local_1e4;
      local_1e0[0] = param_5;
      local_118 = local_1e0;
      local_1dc[0] = param_6;
      local_108 = local_1dc;
      local_f8 = &local_1d4;
      local_e8 = &local_1d0;
      local_1cc = param_9;
      local_d8 = &local_1cc;
      local_c8 = &local_b0;
      local_b8 = *(undefined8 *)(param_10 + 4);
      local_b0 = (uint)*param_10;
      local_a8 = &local_90;
      local_98 = *(undefined8 *)(param_11 + 4);
      local_90 = (uint)*param_11;
      local_1b8[0] = PepSleepStudySessionInstanceId;
      local_88 = local_1b8;
      local_1c8[0] = PepConsoleDisplayState;
      local_78 = local_1c8;
      local_1e8 = PepPcieLtrOverrideEnabled;
      local_68 = &local_1e8;
      local_180 = 8;
      local_170 = 2;
      local_15c = 0;
      local_150 = 2;
      local_13c = 0;
      local_130 = 4;
      local_120 = 1;
      local_110 = 2;
      local_100 = 2;
      local_1d4 = param_7;
      local_f0 = 4;
      local_1d0 = param_8;
      local_e0 = 4;
      local_d0 = 4;
      local_c0 = 2;
      local_ac = 0;
      local_a0 = 2;
      local_8c = 0;
      local_80 = 8;
      local_70 = 4;
      local_1e7 = PepPcieSecurePcieEnabled;
      local_58 = &local_1e7;
      local_60 = 1;
      local_1e6 = PepPcieGeneratePcieHierarchyEnabled;
      local_48 = &local_1e6;
      local_50 = 1;
      local_40 = 1;
      local_1e4[0] = local_1e5;
      local_1d8 = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002dfdb,0,param_4,0x17,local_1a8);
    }
    uVar2 = 0;
    if (((param_3 != 0) && ((param_7 != 0 || (param_8 != 0)))) &&
       ((5 < DAT_1400340a0 &&
        (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')))) {
      local_188 = local_1b8;
      local_1b8[0] = 0x1000000;
      local_178 = &local_160;
      local_168 = *(undefined8 *)(param_1 + 4);
      local_160 = (uint)*param_1;
      local_158 = &local_140;
      local_148 = *(undefined8 *)(param_2 + 4);
      local_140 = (uint)*param_2;
      local_138 = local_1c8;
      local_128 = &local_1e5;
      local_1dc[0] = param_5;
      local_118 = local_1dc;
      local_1e0[0] = param_6;
      local_108 = local_1e0;
      local_f8 = &local_1cc;
      local_e8 = &local_1d0;
      local_1d4 = param_9;
      local_d8 = &local_1d4;
      local_c8 = &local_b0;
      local_b8 = *(undefined8 *)(param_10 + 4);
      local_b0 = (uint)*param_10;
      local_a8 = &local_90;
      local_98 = *(undefined8 *)(param_11 + 4);
      local_90 = (uint)*param_11;
      local_1c0 = PepSleepStudySessionInstanceId;
      local_88 = &local_1c0;
      local_1d8 = PepConsoleDisplayState;
      local_78 = &local_1d8;
      local_1e6 = PepPcieLtrOverrideEnabled;
      local_68 = &local_1e6;
      local_180 = 8;
      local_170 = 2;
      local_15c = (undefined4)uVar2;
      local_150 = 2;
      local_130 = 4;
      local_120 = 1;
      local_110 = 2;
      local_100 = 2;
      local_1cc = param_7;
      local_f0 = 4;
      local_1d0 = param_8;
      local_e0 = 4;
      local_d0 = 4;
      local_c0 = 2;
      local_a0 = 2;
      local_80 = 8;
      local_70 = 4;
      local_1e7 = PepPcieSecurePcieEnabled;
      local_58 = &local_1e7;
      local_60 = 1;
      local_1e8 = PepPcieGeneratePcieHierarchyEnabled;
      local_48 = &local_1e8;
      local_50 = 1;
      local_40 = 1;
      local_1c8[0] = param_3;
      local_13c = local_15c;
      local_ac = local_15c;
      local_8c = local_15c;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002edd7,uVar2,CONCAT71(uVar3,local_1e5),0x17,local_1a8);
    }
  }
  return;
}



===== PepDiagLogSlpS0WakeCounter @ 14000b6b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogSlpS0WakeCounter
               (longlong param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined7 uVar5;
  undefined1 uVar6;
  undefined1 auStackY_98 [32];
  undefined1 local_68 [16];
  undefined8 local_58 [4];
  longlong local_38 [2];
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  puVar1 = *(uint **)(param_1 + 0x18);
  if (((puVar1 != (uint *)0x0) && (*(longlong *)(puVar1 + 2) != 0)) && (uVar3 = 0, *puVar1 != 0)) {
    do {
      lVar4 = *(longlong *)(puVar1 + 2);
      uVar6 = (*param_2 & 1 << (*(byte *)(lVar4 + 0x10 + uVar3 * 0x28) & 0x1f)) != 0;
      if (5 < DAT_1400340a0) {
        _tlgCreate1Sz_wchar_t(local_38,*(wchar_t **)(lVar4 + uVar3 * 0x28));
        local_1c = 0;
        local_28 = local_68;
        local_20 = 1;
        local_68[0] = uVar6;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002f5e9,lVar4,CONCAT71(uVar5,uVar6),4,local_58);
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *puVar1);
  }
  return;
}



===== PepDiagLogUnexpectedPciLinkValue @ 14000b7a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogUnexpectedPciLinkValue
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4,
               uint param_5)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_f8 [32];
  undefined1 local_c8 [8];
  undefined8 local_c0;
  undefined8 local_b8;
  ulonglong local_b0;
  ulonglong local_a8 [2];
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  if (((param_1 != (undefined8 *)0x0) &&
      (local_18 = __security_cookie ^ (ulonglong)auStackY_f8, 5 < DAT_1400340a0)) &&
     (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')) {
    local_78 = &local_c0;
    local_6c = 0;
    local_70 = 8;
    local_c0 = 0x1000000;
    _tlgCreate1Sz_wchar_t(local_68,(wchar_t *)*param_1);
    local_4c = 0;
    local_58 = &local_b8;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_48 = local_c8;
    local_b0 = param_4 & 0xffffffff;
    local_38 = &local_b0;
    local_a8[0] = (ulonglong)param_5;
    local_28 = local_a8;
    local_50 = 8;
    local_40 = 1;
    local_30 = 8;
    local_20 = 8;
    local_c8[0] = uVar2;
    local_b8 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x1400340a0,&DAT_14002fece,CONCAT71(uVar3,uVar2),param_4,8,local_98);
  }
  return;
}



===== PepDiagLogWrongLtrValue @ 14000b8bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogWrongLtrValue(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  longlong local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_wchar_t(local_48,(wchar_t *)*param_1);
      local_2c = 0;
      local_38 = &local_78;
      local_1c = 0;
      local_28 = &local_70;
      local_30 = 8;
      local_20 = 8;
      local_78 = param_2;
      local_70 = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030391,param_3,param_2,5,local_68);
    }
  }
  return;
}



===== PepDiagPostPchLtrMailboxFailure @ 14000b978 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagPostPchLtrMailboxFailure(uint *param_1,uint param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  char *local_58 [4];
  char *local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = 4;
  local_58[0] = "Mb Context empty";
  uVar1 = (ulonglong)param_2;
  local_58[1] = "Mb maximum retry limit reached";
  local_58[2] = "Mb timeout in response happened";
  local_58[3] = "Mb error status returned";
  if ((*param_1 < 4) && (5 < DAT_1400340a0)) {
    _tlgCreate1Sz_char((longlong *)(local_58 + 4),local_58[*param_1]);
    local_1c = 0;
    local_28 = local_68;
    local_68[0] = (undefined4)uVar1;
    local_20 = (undefined4)uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030083,uVar1,uVar2,local_20,local_58);
  }
  return;
}



===== PepDiagSubsystemPkgcNormalizationAndBlockingTime @ 14000ba38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagSubsystemPkgcNormalizationAndBlockingTime(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  longlong local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar1 = param_1[3];
  if ((lVar1 != 0) && (5 < DAT_1400340a0)) {
    _tlgCreate1Sz_wchar_t(local_58,(wchar_t *)*param_1);
    local_98 = param_1[0xf];
    local_48 = &local_98;
    local_90 = *(undefined8 *)(lVar1 + 0x10);
    local_38 = &local_90;
    local_88[0] = *(undefined8 *)(lVar1 + 0x18);
    local_28 = local_88;
    local_40 = 8;
    local_30 = 8;
    local_20 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002fac0,param_1,lVar1,6,local_78);
  }
  return;
}



===== PepTraceRunDownRCiEPGeneratedComponentConstraints @ 14000bb04 =====

void PepTraceRunDownRCiEPGeneratedComponentConstraints(void *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  int *piVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  uVar1 = PepNumPlatformStates * 8;
  ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock);
  for (puVar8 = PepPcieRCiEPList; (undefined8 **)puVar8 != &PepPcieRCiEPList;
      puVar8 = (undefined8 *)*puVar8) {
    lVar3 = puVar8[4];
    if (lVar3 != 0) {
      memset(param_1,0,(ulonglong)uVar1);
      uVar4 = PepNumPlatformStates;
      uVar9 = 0;
      uVar7 = 0;
      if (PepNumPlatformStates != 0) {
        piVar6 = (int *)((longlong)param_1 + 4);
        do {
          piVar6[-1] = uVar7;
          lVar5 = *(longlong *)(lVar3 + 0x20) + (-4 - (longlong)param_1);
          iVar2 = *(int *)(lVar5 + (longlong)piVar6);
          if ((iVar2 == 1) && (*(int *)(lVar5 + 4 + (longlong)piVar6) == 0)) {
            uVar9 = uVar9 + 1;
          }
          else if (iVar2 == 0) {
            *piVar6 = 0;
          }
          else {
            *piVar6 = iVar2 + -1;
          }
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 2;
        } while (uVar7 < uVar4);
      }
      if ((uVar9 != uVar4) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
        McTemplateK0pzqNR2_EtwWriteTransfer();
      }
    }
  }
  ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
  return;
}



===== PepTraceRunDownRCiEPGeneratedDeviceConstraints @ 14000bc30 =====

void PepTraceRunDownRCiEPGeneratedDeviceConstraints(void *param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar1 = PepNumPlatformStates * 8;
  ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock);
  for (puVar6 = PepPcieRCiEPList; (undefined8 **)puVar6 != &PepPcieRCiEPList;
      puVar6 = (undefined8 *)*puVar6) {
    puVar2 = (ushort *)puVar6[4];
    if (puVar2 != (ushort *)0x0) {
      piVar5 = (int *)0x0;
      memset(param_1,0,(ulonglong)uVar1);
      uVar3 = PepNumPlatformStates;
      uVar9 = 0;
      uVar8 = 0;
      if (PepNumPlatformStates != 0) {
        piVar4 = (int *)((longlong)param_1 + 4);
        do {
          piVar4[-1] = (int)uVar8;
          piVar5 = (int *)(*(longlong *)(puVar2 + 0x10) + (-4 - (longlong)param_1) +
                          (longlong)piVar4);
          if ((*piVar5 == 1) && (piVar5[1] == 0)) {
            uVar9 = (ulonglong)((int)uVar9 + 1);
          }
          else {
            *piVar4 = piVar5[1];
            if (*piVar5 - 2U < 3) {
              *piVar4 = 0;
            }
          }
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
          piVar4 = piVar4 + 2;
        } while (uVar7 < uVar3);
      }
      if (((uint)uVar9 != uVar3) && ((Microsoft_Windows_Kernel_PepEnableBits & 1) != 0)) {
        McTemplateK0qpqqqqNR5qzr7_EtwWriteTransfer
                  ((ulonglong)(*puVar2 >> 1),piVar5,uVar8,uVar9,(char)*(undefined8 *)(puVar2 + 8));
      }
    }
  }
  ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
  return;
}



===== _guard_check_icall @ 14000bd70 =====

void _guard_check_icall(void)

{
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 14000bd7c =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== PepSubsystemAccountingInit @ 14000bd88 =====

ulonglong PepSubsystemAccountingInit(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  uint local_res8 [2];
  longlong local_res10;
  undefined8 local_res18;
  
  local_res18 = 0;
  lVar10 = 0;
  local_res8[0] = 0;
  uVar9 = 0xc00000bb;
  if (PepNumPlatformStates != 0) {
    lVar10 = (ulonglong)PepDripsIndex * 0x60 + DAT_140087708;
    PepDiagLogHwDripsCounterInfo();
  }
  local_res10 = 0;
  PepSubsystemGetCounterInfo(&local_res10,(int *)local_res8,&local_res18);
  uVar3 = local_res8[0];
  if (local_res8[0] != 0) {
    PepSubsystemAccountingInfo = ExAllocatePool2(0x40,local_res8[0] * 0xd8,0x49504550);
    if (PepSubsystemAccountingInfo != 0) {
      PepSubsystemAccountingCount = uVar3;
      PepSubsystemAccountingHandle = ExAllocatePool2(0x40,uVar3 << 4,0x49504550);
      lVar4 = local_res10;
      if (PepSubsystemAccountingHandle != 0) {
        local_res8[0] = 0;
        uVar7 = 0;
        uVar5 = 0;
        while ((uint)uVar5 < uVar3) {
          puVar6 = (undefined8 *)(uVar5 * 0xd8 + PepSubsystemAccountingInfo);
          lVar8 = uVar7 * 0xa0;
          *puVar6 = *(undefined8 *)(lVar8 + lVar4);
          puVar6[1] = *(undefined8 *)(lVar8 + 8 + lVar4);
          *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(lVar8 + 0x18 + lVar4);
          *(undefined4 *)((longlong)puVar6 + 0x14) = *(undefined4 *)(lVar8 + 0x1c + lVar4);
          puVar6[3] = *(undefined8 *)(lVar8 + 0x20 + lVar4);
          puVar6[5] = *(undefined8 *)(lVar8 + 0x10 + lVar4);
          puVar1 = (undefined8 *)(lVar8 + 0x28 + lVar4);
          uVar2 = puVar1[1];
          puVar6[6] = *puVar1;
          puVar6[7] = uVar2;
          puVar1 = (undefined8 *)(lVar8 + 0x38 + lVar4);
          uVar2 = puVar1[1];
          puVar6[8] = *puVar1;
          puVar6[9] = uVar2;
          puVar1 = (undefined8 *)(lVar8 + 0x48 + lVar4);
          uVar2 = puVar1[1];
          puVar6[10] = *puVar1;
          puVar6[0xb] = uVar2;
          puVar6[0xc] = *(undefined8 *)(lVar8 + 0x58 + lVar4);
          puVar1 = (undefined8 *)(lVar8 + 0x60 + lVar4);
          uVar2 = puVar1[1];
          puVar6[0x11] = *puVar1;
          puVar6[0x12] = uVar2;
          puVar1 = (undefined8 *)(lVar8 + 0x70 + lVar4);
          uVar2 = puVar1[1];
          puVar6[0x13] = *puVar1;
          puVar6[0x14] = uVar2;
          puVar1 = (undefined8 *)(lVar8 + 0x80 + lVar4);
          uVar2 = puVar1[1];
          puVar6[0x15] = *puVar1;
          puVar6[0x16] = uVar2;
          puVar6[0x17] = *(undefined8 *)(lVar8 + 0x90 + lVar4);
          puVar6[0x18] = *(undefined8 *)(lVar8 + 0x98 + lVar4);
          uVar5 = PepSubsystemInitializeCounter((longlong)puVar6,local_res8,lVar10);
          uVar9 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) goto LAB_14000bf61;
          local_res8[0] = local_res8[0] + 1;
          uVar7 = (ulonglong)local_res8[0];
          uVar5 = (ulonglong)local_res8[0];
        }
        PepSubsystemInitializeActiveCounters();
        PepSubsystemLtrBlockingThreshold = local_res18;
        if (-1 < (int)uVar9) {
          return uVar9;
        }
        goto LAB_14000bf61;
      }
    }
    uVar9 = 0xc000009a;
  }
LAB_14000bf61:
  if (PepSubsystemAccountingInfo != 0) {
    if (PepSubsystemAccountingHandle != 0) {
      if (uVar3 != 0) {
        uVar5 = 0;
        uVar11 = 0;
        do {
          lVar10 = uVar5 * 0xd8 + PepSubsystemAccountingInfo;
          if ((*(int *)(lVar10 + 0x14) == 3) && (*(longlong *)(lVar10 + 200) != 0)) {
            ExFreePoolWithTag(*(longlong *)(lVar10 + 200),0x49504550);
            *(undefined8 *)(lVar10 + 200) = 0;
          }
          uVar11 = uVar11 + 1;
          uVar5 = (ulonglong)uVar11;
        } while (uVar11 < uVar3);
      }
      ExFreePoolWithTag(PepSubsystemAccountingHandle,0x49504550);
      PepSubsystemAccountingHandle = 0;
    }
    ExFreePoolWithTag(PepSubsystemAccountingInfo,0x49504550);
    PepSubsystemAccountingInfo = 0;
    PepSubsystemAccountingCount = 0;
  }
  return uVar9;
}



===== PepSubsystemApplyLpitFrequencyOverrides @ 14000c030 =====

void PepSubsystemApplyLpitFrequencyOverrides
               (longlong *param_1,longlong *param_2,int param_3,longlong *param_4)

{
  longlong local_res20;
  
  if (param_4 == (longlong *)0x0) {
    DbgPrintEx(0x92,0,"INTELPEP: Cannot override NULL LPIT Frequency!\n");
  }
  else if (((int)param_1[1] == param_3) && (*param_1 == *param_2)) {
    if (param_1[2] != *param_4) {
      DbgPrintEx(0x92,3,"INTELPEP: LPIT override selected: changing frequency from %llu, to %llu\n",
                 *param_4,param_1[2]);
      local_res20 = *param_4;
      *param_4 = param_1[2];
      PepDiagLogLpitFrequencyOverride(param_2,&local_res20,param_4);
    }
  }
  return;
}



===== PepSubsystemComputePkgcNormalizationAndBlockingTime @ 14000c0dc =====

void PepSubsystemComputePkgcNormalizationAndBlockingTime(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  uVar4 = 0;
  lVar9 = 0;
  do {
    if (PepSubsystemAccountingCount <= uVar4) {
      return;
    }
    puVar5 = (undefined8 *)(PepSubsystemAccountingInfo + lVar9);
    if (*(int *)((longlong)puVar5 + 0x14) == 3) {
      puVar1 = (undefined8 *)puVar5[3];
      if (puVar1 != (undefined8 *)0x0) {
        uVar7 = *(ulonglong *)*puVar1;
        puVar1[2] = 0;
        if (uVar7 != 0) {
          uVar8 = 0;
          if (puVar5[3] != 0) {
            uVar6 = 0;
            for (bVar3 = *(byte *)(puVar5[3] + 8); bVar3 != 0; bVar3 = bVar3 >> 1) {
              if ((bVar3 & 1) != 0) {
                uVar8 = uVar8 + *(longlong *)(uVar6 * 0xd8 + 0x78 + PepSubsystemAccountingInfo);
              }
              uVar6 = (ulonglong)(byte)((char)uVar6 + 1);
            }
          }
          uVar6 = puVar5[0xf];
          if (uVar6 == uVar7) {
            puVar1[2] = uVar8;
          }
          else if (uVar6 != 0) {
            uVar8 = uVar8 / 10000;
            uVar2 = RtlULongLongMult(uVar6,uVar8,puVar1 + 2);
            if ((int)uVar2 < 0) {
              puVar1[2] = 0;
              PepDiagLogPkgcNormalizationOverflow((wchar_t *)*puVar5,puVar5[0xf],uVar7,uVar8);
            }
            else {
              puVar1[2] = ((ulonglong)puVar1[2] / uVar7) * 10000;
            }
          }
        }
        if (puVar1[2] != 0) {
          puVar1[3] = puVar1[3] + puVar1[2];
          uVar7 = 0;
          for (bVar3 = *(byte *)(puVar1 + 1); bVar3 != 0; bVar3 = bVar3 >> 1) {
            if ((bVar3 & 1) != 0) {
              *(uint *)((&PepSubsystemUnattributedPkgCInfo)[uVar7] + 0x10) =
                   *(uint *)((&PepSubsystemUnattributedPkgCInfo)[uVar7] + 0x10) | 0x20;
            }
            uVar7 = (ulonglong)(byte)((char)uVar7 + 1);
          }
          PepDiagSubsystemPkgcNormalizationAndBlockingTime(puVar5);
        }
      }
      if ((char)*(undefined4 *)(puVar5 + 2) < '\0') {
        PepSubsystemPkgcPc6Pc10LimitCategorySum = 0;
        PepSubsystemPkgcPc2Pc3LimitOrWake1CategorySum = 0;
        PepSubsystemPkgcPc2Pc3LimitOrWake3CategorySum = 0;
        PepSubsystemPkgcPc6Pc10WakeCategorySum = 0;
        PepSubsystemPkgcPc2Pc3LimitOrWake2CategorySum = 0;
        return;
      }
    }
    uVar4 = uVar4 + 1;
    lVar9 = lVar9 + 0xd8;
  } while( true );
}



===== PepSubsystemCyclesTo100ns @ 14000c274 =====

longlong PepSubsystemCyclesTo100ns(longlong param_1,ulonglong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong local_res8 [4];
  
  uVar4 = *(ulonglong *)(param_1 + 8);
  lVar3 = 0;
  local_res8[0] = 0;
  uVar2 = param_2 % uVar4;
  uVar1 = RtlULongLongMult(param_2 / uVar4,10000000,local_res8);
  if (-1 < (int)uVar1) {
    lVar3 = (uVar2 * 10000000) / uVar4 + local_res8[0];
  }
  return lVar3;
}



===== PepSubsystemDisablePmtCountersPerTelemetryGuid @ 14000c2cc =====

void PepSubsystemDisablePmtCountersPerTelemetryGuid(uint param_1)

{
  uint *puVar1;
  ulonglong uVar2;
  
  if ((PepSubsystemAccountingInfo != 0) && (PepSubsystemAccountingCount != 0)) {
    puVar1 = (uint *)(PepSubsystemAccountingInfo + 0x10);
    uVar2 = (ulonglong)PepSubsystemAccountingCount;
    do {
      if ((puVar1[0x30] == param_1) && ((*puVar1 & 2) != 0)) {
        *puVar1 = *puVar1 & 0xfffffffd | 0x4000;
      }
      puVar1 = puVar1 + 0x36;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== PepSubsystemEnableEnergyReportingPolicyHandling @ 14000c31c =====

void PepSubsystemEnableEnergyReportingPolicyHandling(char param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  ulonglong *puVar4;
  ulonglong local_res10;
  ulonglong local_res18;
  ulonglong local_res20;
  
  if (PepSubsystemEnergyReportingContext == 0) {
    return;
  }
  local_res10 = 0;
  local_res18 = 0;
  local_res20 = 0;
  piVar1 = *(int **)(PepSubsystemEnergyReportingContext + 0x28);
  piVar2 = *(int **)(PepSubsystemEnergyReportingContext + 0x30);
  piVar3 = *(int **)(PepSubsystemEnergyReportingContext + 0x38);
  if (param_1 == '\0') {
    if (PepSubsystemErC10AccountingPolicyOriginal == 0) goto LAB_14000c3d8;
    puVar4 = &PepSubsystemErC10AccountingPolicyOriginal;
  }
  else {
    PepSubsystemErC10AccountingPolicyOriginal = 0;
    if (piVar2 == (int *)0x0) {
      PepSubsystemErC10AccountingPolicyOriginal = 0;
      return;
    }
    PepReadRegisterWithBus(piVar2,0,(uint *)&local_res18);
    if ((local_res18 & 0x10) != 0) {
      local_res18 = local_res18 & 0xffffffffffffffef;
      PepWriteRegisterWithBus(piVar2,0,&local_res18);
    }
    if (piVar1 == (int *)0x0) {
      return;
    }
    PepReadRegisterWithBus(piVar1,0,(uint *)&local_res10);
    PepSubsystemErC10AccountingPolicyOriginal = local_res10;
    if ((local_res10 & 1) != 0) goto LAB_14000c3d8;
    local_res10 = local_res10 | 1;
    puVar4 = &local_res10;
  }
  PepWriteRegisterWithBus(piVar1,0,puVar4);
LAB_14000c3d8:
  if ((piVar3 != (int *)0x0) &&
     (PepReadRegisterWithBus(piVar3,0,(uint *)&local_res20), (local_res20 & 1) == 0)) {
    local_res20 = local_res20 | 1;
    PepWriteRegisterWithBus(piVar3,0,&local_res20);
  }
  return;
}



===== PepSubsystemEnablePmtTelemetry @ 14000c418 =====

undefined8 PepSubsystemEnablePmtTelemetry(int param_1)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar2 = 0xc0000001;
  if (Pepv2SubsystemSocInfo == 0) {
    uVar2 = 0xc00000e5;
  }
  else if (PepSubsystemAccountingCount != 0) {
    uVar3 = (ulonglong)PepSubsystemAccountingCount;
    puVar1 = (undefined1 *)(PepSubsystemAccountingInfo + 0x20);
    do {
      if (((*(int *)(puVar1 + 0xb0) == param_1) && (puVar1 != (undefined1 *)0x0)) &&
         ((*(uint *)(puVar1 + -0x10) >> 0xf & 1) == 0)) {
        *puVar1 = 0;
        *(uint *)(puVar1 + -0x10) = *(uint *)(puVar1 + -0x10) & 0xffffbfff | 0x2000;
        uVar2 = 0;
      }
      puVar1 = puVar1 + 0xd8;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return uVar2;
}



===== PepSubsystemEstimateLtrResidency @ 14000c488 =====

undefined8 PepSubsystemEstimateLtrResidency(undefined8 *param_1,int *param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined4 local_res20;
  undefined4 local_18;
  
  uVar6 = 0;
  uVar10 = 7;
  if (PepSubsystemDeepestPkgStateInfo != 0) {
    local_res20 = *param_2;
    local_18 = *param_3;
    if ((*(uint *)(param_1 + 2) & 0x400) == 0) {
      uVar10 = 7;
      uVar9 = PepSubsystemGetLtrValue((ushort *)&local_res20);
      uVar2 = PepSubsystemGetLtrValue((ushort *)&local_18);
      uVar3 = PepSubsystemGetLtrValue((ushort *)((longlong)&local_res20 + 2));
      uVar4 = PepSubsystemGetLtrValue((ushort *)((longlong)&local_18 + 2));
      if (uVar9 < uVar3) {
        uVar3 = uVar9;
      }
      if (uVar2 < uVar4) {
        uVar4 = uVar2;
      }
    }
    else {
      uVar3 = (ulonglong)(uint)(local_res20 * 1000);
      uVar4 = (ulonglong)(uint)(local_18 * 1000);
    }
    if (PepSubsystemPkgCStateThreshold != 0) {
      if ((uVar3 < *(uint *)(PepSubsystemPkgCStateThreshold + 8)) ||
         (uVar4 < *(uint *)(PepSubsystemPkgCStateThreshold + 8))) {
        PepDiagLogWrongLtrValue(param_1,uVar3,uVar4);
      }
      else {
        for (uVar5 = 1; uVar5 < uVar10; uVar5 = uVar5 + 1) {
          if (uVar3 < *(uint *)(PepSubsystemPkgCStateThreshold + 8 + (ulonglong)uVar5 * 0x10)) {
            if (uVar5 - 1 != uVar10) {
              uVar10 = uVar5 - 1;
            }
            break;
          }
        }
        for (uVar5 = 1; uVar5 < 7; uVar5 = uVar5 + 1) {
          if (uVar4 < *(uint *)(PepSubsystemPkgCStateThreshold + 8 + (ulonglong)uVar5 * 0x10)) {
            uVar5 = uVar5 - 1;
            if ((uVar5 != 7) && (uVar10 < uVar5)) {
              uVar10 = uVar5;
            }
            break;
          }
        }
        if ((param_1[3] != 0) && (uVar10 != 7)) {
          plVar8 = &PepSubsystemUnattributedPkgCInfo;
          plVar7 = (longlong *)(param_1[3] + 0x18);
          uVar9 = (ulonglong)(uVar10 + 1);
          do {
            lVar1 = *(longlong *)
                     ((ulonglong)*(byte *)((longlong)plVar7 + 0xc) * 0xd8 + 0x78 +
                     PepSubsystemAccountingInfo);
            *plVar7 = *plVar7 + lVar1;
            plVar7[-1] = lVar1;
            if (lVar1 != 0) {
              *(uint *)(*plVar8 + 0x10) = *(uint *)(*plVar8 + 0x10) | 0x20;
            }
            plVar7 = plVar7 + 5;
            plVar8 = plVar8 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        if ((uVar3 != 0xffffffffffffffff) || (uVar4 != 0xffffffffffffffff)) {
          PepDiagLogLtrValue(param_1,uVar3,uVar4);
        }
        if ((uVar3 < PepSubsystemLtrBlockingThreshold) && (uVar4 < PepSubsystemLtrBlockingThreshold)
           ) {
          uVar6 = PepSubsystemLastDripsResidency;
        }
      }
    }
  }
  return uVar6;
}



===== PepSubsystemEstimatePciLinkStateResidency @ 14000c644 =====

ulonglong PepSubsystemEstimatePciLinkStateResidency
                    (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  char *pcVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  
  uVar9 = 0;
  if (param_1 == (undefined8 *)0x0) {
    pcVar10 = "INTELPEP: Received NULL SubsystemInfo for Link State reporting accounting type.\n";
  }
  else if (param_2 == (undefined8 *)0x0) {
    pcVar10 = "INTELPEP: Received NULL SnappedCycles Counter.\n";
  }
  else if (param_3 == (undefined8 *)0x0) {
    pcVar10 = "INTELPEP: Received NULL Counter Cycles.\n";
  }
  else if (*(int *)((longlong)param_1 + 0x14) == 0xb) {
    plVar2 = (longlong *)param_1[3];
    if (plVar2 != (longlong *)0x0) {
      uVar1 = *(undefined1 *)((longlong)plVar2 + 4);
      uVar5 = CONCAT71((int7)((ulonglong)param_3 >> 8),uVar1);
      uVar4 = PepSubsystemGetPciLinkState(param_1,*param_2,uVar5);
      uVar5 = PepSubsystemGetPciLinkState
                        (param_1,*param_3,CONCAT71((int7)((ulonglong)uVar5 >> 8),uVar1));
      uVar13 = (uint)uVar4;
      plVar6 = plVar2;
      uVar3 = PepSubsystemGetBlockingStateIndexForLinkState(uVar13,(longlong)plVar2);
      uVar8 = (uint)uVar5;
      uVar12 = (ulonglong)uVar3;
      uVar3 = PepSubsystemGetBlockingStateIndexForLinkState(uVar8,(longlong)plVar6);
      uVar11 = (uint)uVar12;
      if (uVar13 != uVar8) {
        PepDiagLogInconsistentPciLinkStates
                  (param_1,param_2,param_3,uVar4 & 0xffffffff,uVar8,uVar11,uVar3);
        return 0;
      }
      lVar7 = 4;
      if ((uVar11 != 0xffffffff) &&
         (uVar9 = *(ulonglong *)(uVar12 * 0xd8 + 0x78 + PepSubsystemAccountingInfo),
         (*(uint *)(uVar12 * 0xd8 + 0x10 + PepSubsystemAccountingInfo) & 4) != 0)) {
        uVar9 = -(ulonglong)(*(ulonglong *)(PepSubsystemSlpS0Info + 0x78) < uVar9) &
                uVar9 - *(ulonglong *)(PepSubsystemSlpS0Info + 0x78);
      }
      if (PepSubsystemUnattributedPkgCCount < uVar11) {
        return uVar9;
      }
      do {
        plVar6 = plVar2 + 6;
        if (*(uint *)(plVar2 + 4) == uVar13) {
          *plVar6 = *plVar6 + uVar9;
          plVar2[5] = uVar9;
          if (uVar11 < 7) {
            *(uint *)((&PepSubsystemUnattributedPkgCInfo)[uVar12] + 0x10) =
                 *(uint *)((&PepSubsystemUnattributedPkgCInfo)[uVar12] + 0x10) | 0x20;
          }
        }
        lVar7 = lVar7 + -1;
        plVar2 = plVar6;
      } while (lVar7 != 0);
      return uVar9;
    }
    pcVar10 = "INTELPEP: Null Context when estimating link state blocking activity.\n";
  }
  else {
    pcVar10 = "INTELPEP: Expected Link State Counter but receiveddifferent type.\n";
  }
  DbgPrintEx(0x92,0,pcVar10);
  return 0;
}



===== PepSubsystemEstimateSlpS0DbgTime @ 14000c7cc =====

ulonglong PepSubsystemEstimateSlpS0DbgTime(longlong param_1,uint *param_2,undefined8 param_3)

{
  longlong *plVar1;
  byte bVar2;
  uint *puVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 uVar10;
  undefined7 uVar11;
  ulonglong uVar12;
  
  uVar11 = (undefined7)((ulonglong)param_3 >> 8);
  bVar5 = false;
  uVar7 = 0;
  if ((((PepSubsystemSlpS0Info != 0) && (PepSubsystemDeepestPkgStateInfo != 0)) &&
      (uVar9 = *(ulonglong *)(PepSubsystemDeepestPkgStateInfo + 0x78), uVar9 != 0)) &&
     (puVar3 = *(uint **)(param_1 + 0x18), *(longlong *)(puVar3 + 2) != 0)) {
    if (*(ulonglong *)(PepSubsystemSlpS0Info + 0x78) <= uVar9) {
      uVar7 = uVar9 - *(ulonglong *)(PepSubsystemSlpS0Info + 0x78);
    }
    uVar9 = 0;
    if (*puVar3 != 0) {
      do {
        lVar4 = *(longlong *)(puVar3 + 2);
        bVar2 = *(byte *)(lVar4 + 0x10 + uVar9 * 0x28);
        uVar6 = 1 << (bVar2 & 0x1f) & *param_2;
        uVar8 = *(uint *)(lVar4 + 0x20 + uVar9 * 0x28);
        if ((((uVar8 >> 9 & 1) == 0) || (uVar6 != 0)) && (((uVar8 >> 8 & 1) == 0 || (uVar6 == 0))))
        {
          uVar12 = 0;
          uVar10 = 0;
        }
        else {
          plVar1 = (longlong *)(lVar4 + 0x18 + uVar9 * 0x28);
          *plVar1 = *plVar1 + uVar7;
          uVar10 = 1;
          bVar5 = true;
          uVar12 = uVar7;
        }
        PepDiagLogSlpS0DbgCounter
                  (*(wchar_t **)(lVar4 + uVar9 * 0x28),bVar2,CONCAT71(uVar11,uVar10),uVar12,'\0',
                   PepSleepStudySessionInstanceId);
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < *puVar3);
      if (bVar5) {
        *(uint *)(DAT_140087988 + 0x10) = *(uint *)(DAT_140087988 + 0x10) | 0x20;
      }
    }
  }
  return -(ulonglong)bVar5 & uVar7;
}



===== PepSubsystemEstimateUngatedTime @ 14000c8ec =====

ulonglong PepSubsystemEstimateUngatedTime(longlong param_1,uint *param_2)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  bool bVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  puVar4 = *(uint **)(param_1 + 0x18);
  bVar6 = false;
  if (((puVar4 != (uint *)0x0) && (PepSubsystemSlpS0Info != 0)) &&
     (PepSubsystemDeepestPkgStateInfo != 0)) {
    uVar2 = *(uint *)(param_1 + 0x70);
    uVar3 = *param_2;
    lVar5 = *(longlong *)(puVar4 + 2);
    uVar10 = 0;
    uVar8 = -(ulonglong)
             (*(ulonglong *)(PepSubsystemSlpS0Info + 0x78) <
             *(ulonglong *)(PepSubsystemDeepestPkgStateInfo + 0x78)) &
            *(ulonglong *)(PepSubsystemDeepestPkgStateInfo + 0x78) -
            *(ulonglong *)(PepSubsystemSlpS0Info + 0x78);
    if (*puVar4 != 0) {
      do {
        uVar7 = 1 << (*(byte *)(lVar5 + 0x10 + uVar10 * 0x28) & 0x1f);
        param_1 = CONCAT71((int7)((ulonglong)param_1 >> 8),(uVar3 & uVar7) == 0);
        if (((uVar7 & uVar2) == 0) && ((uVar3 & uVar7) == 0)) {
          plVar1 = (longlong *)(lVar5 + 0x18 + uVar10 * 0x28);
          *plVar1 = *plVar1 + uVar8;
          bVar6 = true;
          uVar9 = uVar8;
        }
        else {
          uVar9 = 0;
        }
        PepDiagLogPowerGatingCounter
                  (*(wchar_t **)(lVar5 + uVar10 * 0x28),(uVar7 & uVar2) == 0,param_1,uVar9,'\0',0);
        uVar7 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar7;
      } while (uVar7 < *puVar4);
      if (bVar6) {
        *(uint *)(DAT_140087988 + 0x10) = *(uint *)(DAT_140087988 + 0x10) | 0x20;
        return uVar8;
      }
    }
  }
  return 0;
}



===== PepSubsystemEvaluateEnergyReporting @ 14000ca00 =====

void PepSubsystemEvaluateEnergyReporting
               (undefined8 param_1,undefined8 param_2,char *param_3,ulonglong param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  puVar1 = PepSubsystemEnergyReportingContext;
  uVar2 = PepSubsystemInitializeEnergyReporting(PepSubsystemEnergyReportingContext);
  if (-1 < (int)uVar2) {
    uVar3 = PepSubsystemEnableEnergyReporting(puVar1);
    if ((int)uVar3 < 0) {
      param_4 = uVar3 & 0xffffffff;
      param_3 = "INTELPEP: Could not enable energy reportingcounters with status 0x%x.\n";
      param_2 = 1;
      DbgPrintEx(0x92,1,"INTELPEP: Could not enable energy reportingcounters with status 0x%x.\n");
    }
    else {
      PepSubsystemEnableDebugPchCounters = 1;
    }
  }
  PepDiagLogEnergyReportingCapabilities
            (puVar1,param_2,CONCAT71((int7)((ulonglong)param_3 >> 8),1),param_4);
  return;
}



===== PepSubsystemEvaluateLpitOverride @ 14000ca68 =====

void PepSubsystemEvaluateLpitOverride(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  if ((param_1 != (longlong *)0x0) && (uVar2 = 0, PepNumPlatformStates != 0)) {
    do {
      lVar1 = PepGetPlatformStateInfo(uVar2);
      if ((lVar1 != 0) &&
         (((char *)(lVar1 + 0x10) != (char *)0x0 && (*(char *)(lVar1 + 0x10) == '\0')))) {
        if ((int *)(lVar1 + 0x20) == (int *)0x0) {
          DbgPrintEx(0x92,0,"INTELPEP: Cannot override NULL LPIT Address!\n");
        }
        else {
          PepSubsystemApplyLpitFrequencyOverrides
                    (param_1,(longlong *)(lVar1 + 0x48),*(int *)(lVar1 + 0x20),
                     (longlong *)(lVar1 + 0x18));
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < PepNumPlatformStates);
  }
  return;
}



===== PepSubsystemGetBlockingStateIndexForLinkState @ 14000caf4 =====

undefined4 PepSubsystemGetBlockingStateIndexForLinkState(int param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    for (; uVar1 < 4; uVar1 = uVar1 + 1) {
      if (*(int *)(param_2 + 0x20 + (ulonglong)uVar1 * 0x30) == param_1) {
        return *(undefined4 *)(param_2 + 0x24 + (ulonglong)uVar1 * 0x30);
      }
    }
  }
  return 0xffffffff;
}



===== PepSubsystemGetBootTelemetryInfo @ 14000cb30 =====

uint PepSubsystemGetBootTelemetryInfo(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 local_res8;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8 = 0;
  uVar4 = 0xc0000001;
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x18) == 1)) &&
      (*(longlong **)(param_1 + 0x20) != (longlong *)0x0)) &&
     (puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x20), puVar1 != (undefined8 *)0x0)) {
    local_58 = *puVar1;
    uStack_50 = puVar1[1];
    local_48 = puVar1[2];
    uStack_40 = puVar1[3];
    local_38 = puVar1[4];
    uStack_30 = puVar1[5];
    local_28 = puVar1[6];
    if (*(int *)(param_1 + 4) == 0x11) {
      if (*(int *)(param_1 + 0x54) != 1) {
        return 0xc0000001;
      }
      lVar2 = *(longlong *)(param_1 + 0x58);
      if (lVar2 == 0) {
        return 0xc0000001;
      }
      for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 0x60); uVar4 = uVar4 + 1) {
        lVar5 = (ulonglong)uVar4 * 0x20;
        puVar1 = *(undefined8 **)(lVar5 + 8 + lVar2);
        local_48 = *puVar1;
        uStack_40 = puVar1[1];
        local_38 = CONCAT44(local_38._4_4_,*(undefined4 *)(puVar1 + 2));
        uStack_30 = *(undefined8 *)(lVar5 + 0x10 + lVar2);
        uVar3 = PepValidateAndInitAddress((int *)&local_58);
        if ((int)uVar3 < 0) {
          PepDiagLogBootTelemetry(*(wchar_t **)(lVar5 + lVar2),local_res8,3);
          return uVar3;
        }
        uStack_50 = CONCAT44(3,(undefined4)uStack_50);
        local_58 = CONCAT44(0x20,(int)local_58);
        PepReadRegisterWithBus((int *)&local_58,0,(uint *)&local_res8);
        PepDiagLogBootTelemetry(*(wchar_t **)(lVar5 + lVar2),local_res8,0);
      }
    }
    else {
      PepDiagLogBootTelemetry(L"CounterNameNotFound",0,4);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== PepSubsystemGetCounterInfo @ 14000cc78 =====

void PepSubsystemGetCounterInfo(longlong *param_1,int *param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined8 uVar5;
  char cVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  char *pcVar10;
  undefined4 *puVar11;
  
  *param_2 = 0;
  *param_1 = 0;
  *param_3 = 0;
  if (PepSubsystemSoCInfo == (int *)0x0) {
    return;
  }
  iVar1 = *PepSubsystemSoCInfo;
  iVar2 = PepSubsystemSoCInfo[1];
  piVar3 = *(int **)(PepSubsystemSoCInfo + 10);
  if (((iVar1 == 6) && (iVar2 == 0x8e)) && (*piVar3 == PepSunrisePointLp)) {
    PepSubsystemIsKabyLake = 1;
  }
  if (PepSubsystemEnableCoffeeLakeAccounting == '\0') {
    if (*piVar3 == PepCannonLakePchLp) {
      return;
    }
    if (*piVar3 == PepCannonLakePchH) {
      return;
    }
  }
  if (iVar1 != 6) goto LAB_14000cd8d;
  if (iVar2 == 0x7e) {
    if (*piVar3 != PepIceLakePchLp) goto LAB_14000cd8d;
    cVar6 = PepSubsystemEnableIceLakeAccounting;
  }
  else {
    if (iVar2 == 0x8a) {
      if (*piVar3 != PepLakeFieldPchLp) goto LAB_14000cd8d;
      if (PepSubsystemEnableLakeFieldAccounting == '\0') {
        return;
      }
      uVar7 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemLPMEnableRegister,param_2,
                         (int *)&PepSubsystemLPMPriorityRegister);
      if ((int)uVar7 < 0) {
        return;
      }
    }
    if (iVar2 != 0xa6) goto LAB_14000cd8d;
    if ((*piVar3 == PepCometLakePchLp) && (PepSubsystemEnableCometLakeLPAccounting == '\0')) {
      return;
    }
    if (*piVar3 != PepCometLakePchSH) goto LAB_14000cd8d;
    cVar6 = PepSubsystemEnableCometLakeSHAccounting;
  }
  if (cVar6 == '\0') {
    return;
  }
LAB_14000cd8d:
  pcVar10 = (char *)0x0;
  puVar11 = &PepSubsystemSocList;
  while( true ) {
    if (8 < (uint)pcVar10) {
      return;
    }
    lVar9 = (longlong)pcVar10 * 0x58;
    if (((iVar1 == (&PepSubsystemSocList)[(longlong)pcVar10 * 0x16]) &&
        (iVar2 == (&DAT_140061b64)[(longlong)pcVar10 * 0x16])) &&
       (*piVar3 == *(int *)(&PTR_PepSunrisePointLp_140061b88)[(longlong)pcVar10 * 0xb])) break;
    pcVar10 = (char *)(ulonglong)((uint)pcVar10 + 1);
  }
  PepSubsystemEnergyReportingContext =
       (&PTR_SunrisePointEnergyReportingContext_140061b80)[(longlong)pcVar10 * 0xb];
  puVar4 = (&PTR_SkylakeSubsystemCounterInfo_140061b68)[(longlong)pcVar10 * 0xb];
  iVar1 = *(int *)(&DAT_140061b70 + lVar9);
  uVar5 = *(undefined8 *)(&DAT_140061b78 + lVar9);
  plVar8 = (longlong *)
           (&PTR_PepSubsystemSunriseLpLpitFreqOverride_140061ba8)[(longlong)pcVar10 * 0xb];
  PepSubsystemOrignalPkgCStateThreshold =
       (&PTR_SkylakePlatformIdleStateThreshold_140061b90)[(longlong)pcVar10 * 0xb];
  PepSubsystemCtaSignature = *(undefined8 *)(&DAT_140061bb0 + lVar9);
  PepSubsystemLtrSpxInfo = (&PTR_PepSubsystemSklLtrSpxInfo_140061b98)[(longlong)pcVar10 * 0xb];
  PepSubsystemLtrSpxCount = *(undefined4 *)(&DAT_140061ba0 + lVar9);
  if (puVar4 == (undefined *)0x0) {
    PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
    return;
  }
  if (iVar1 == 0) {
    PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
    return;
  }
  PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
  PepSubsystemEvaluateLpitOverride(plVar8);
  PepSubsystemEvaluateEnergyReporting(plVar8,lVar9,pcVar10,(ulonglong)puVar11);
  *param_2 = iVar1;
  *param_1 = (longlong)puVar4;
  *param_3 = uVar5;
  return;
}



===== PepSubsystemGetDiscretePchDeviceId @ 14000ce5c =====

undefined8
PepSubsystemGetDiscretePchDeviceId(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined4 local_res8 [2];
  
  uVar2 = PepSubsystemPchBusNumber;
  local_res8[0] = 0;
  uVar4 = 0xc00000ef;
  if (PepSubsystemPchBusNumber < 0x100) {
    uVar4 = 0xc00000f0;
    if (param_2 != (undefined4 *)0x0) {
      iVar3 = HalGetBusDataByOffset(4,PepSubsystemPchBusNumber,*param_2,local_res8,0,4);
      if (iVar3 == 4) {
        DbgPrintEx(0x92,3,"INTELPEP: Discrete PCH Device ID: %x\n",local_res8[0]);
        *param_3 = local_res8[0];
        uVar1 = *(ushort *)((longlong)param_3 + 2);
        PepDiagLogPchDeviceId
                  (uVar2,*(undefined2 *)param_3,(ulonglong)(uVar1 & 0x7f),
                   (ulonglong)(uVar1 >> 7 & 7),uVar1 >> 10);
        return 0;
      }
      DbgPrintEx(0x92,1,"INTELPEP: Could not read config space of Discrete PCH.\n");
      return 0xc00000f0;
    }
    pcVar5 = "INTELPEP: Invalid Discrete PCH Location.\n";
  }
  else {
    pcVar5 = "INTELPEP: Invalid Discrete PCH Bus Number.\n";
  }
  DbgPrintEx(0x92,0,pcVar5);
  return uVar4;
}



===== PepSubsystemGetLPMConfig @ 14000cf74 =====

uint PepSubsystemGetLPMConfig(int *param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  uint local_res10 [2];
  uint local_res20 [2];
  
  local_res20[0] = 0;
  local_res20[1] = 0;
  local_res10[0] = 0;
  local_res10[1] = 0;
  if ((param_1 == (int *)0x0) || (param_3 == (int *)0x0)) {
    uVar1 = 0xc0000001;
  }
  else {
    uVar1 = PepValidateAndInitAddress(param_1);
    if (-1 < (int)uVar1) {
      PepReadRegisterWithBus(param_1,0,local_res20);
      PepDiagLogLPMEnable(local_res20);
      uVar1 = PepValidateAndInitAddress(param_3);
      if (-1 < (int)uVar1) {
        PepReadRegisterWithBus(param_3,0,local_res10);
        PepDiagLogLPMPriority(local_res10);
      }
    }
  }
  return uVar1;
}



===== PepSubsystemGetLtrValue @ 14000d014 =====

longlong PepSubsystemGetLtrValue(ushort *param_1)

{
  ushort uVar1;
  longlong lVar2;
  
  uVar1 = *param_1;
  lVar2 = -1;
  if (((short)uVar1 < 0) && ((uVar1 & 0x1c00) < 0x1401)) {
    lVar2 = (longlong)(int)((uVar1 & 0x3ff) << (((byte)(uVar1 >> 10) & 7) * '\x05' & 0x1f));
  }
  return lVar2;
}



===== PepSubsystemGetPchDeviceId @ 14000d058 =====

undefined8 PepSubsystemGetPchDeviceId(uint param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  puVar7 = (undefined4 *)0x0;
  uVar6 = 0xc0000001;
  uVar3 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    puVar4 = &DAT_140061ea4;
    lVar5 = 0x14;
    do {
      if ((param_1 == puVar4[-1]) && (param_2 == *puVar4)) {
        puVar7 = *(undefined4 **)(puVar4 + 1);
      }
      puVar4 = puVar4 + 4;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xc0000001;
    }
    goto LAB_14000d170;
  }
  if (param_1 != 6) {
    return 0xc0000001;
  }
  if (param_2 < 0xa6) {
    if (param_2 != 0xa5) {
      if (param_2 < 0x8e) {
        if ((((param_2 != 0x8d) && (param_2 != 0x4e)) && (param_2 != 0x5e)) && (param_2 != 0x7e)) {
          iVar2 = param_2 - 0x8a;
          bVar8 = iVar2 == 0;
LAB_14000d130:
          if ((!bVar8) && (iVar2 != 2)) {
            return 0xc0000001;
          }
        }
      }
      else if (((param_2 != 0x8e) && (param_2 != 0x97)) && (param_2 != 0x9a)) {
        iVar2 = param_2 - 0x9c;
        bVar8 = iVar2 == 0;
        goto LAB_14000d130;
      }
    }
  }
  else if (param_2 < 0xbb) {
    if (((param_2 != 0xba) && (param_2 != 0xa6)) && ((param_2 != 0xa7 && (param_2 != 0xaa)))) {
      iVar2 = param_2 - 0xb5;
      bVar8 = iVar2 == 0;
      goto LAB_14000d130;
    }
  }
  else if ((((param_2 != 0xbd) && (param_2 != 0xbe)) && (param_2 != 0xc5)) && (param_2 != 0xc6)) {
    if (param_2 != 0xcc) {
      return 0xc0000001;
    }
    uVar3 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      return 0xc0000001;
    }
  }
  puVar7 = &PepSubsystemLpcLocation;
LAB_14000d170:
  local_res20[0] = 0;
  iVar2 = HalGetBusDataByOffset(4,0,*puVar7,local_res20,0,4);
  if (iVar2 == 4) {
    DbgPrintEx(0x92,3,"INTELPEP: PCH Device ID: %x\n",local_res20[0]);
    *param_3 = local_res20[0];
    uVar1 = *(ushort *)((longlong)param_3 + 2);
    PepDiagLogPchDeviceId
              (0,*(undefined2 *)param_3,(ulonglong)(uVar1 & 0x7f),(ulonglong)(uVar1 >> 7 & 7),
               uVar1 >> 10);
    uVar6 = 0;
  }
  else {
    DbgPrintEx(0x92,1,"INTELPEP: Could not read config space of PCH.\n");
  }
  return uVar6;
}



===== PepSubsystemGetPciLinkState @ 14000d234 =====

undefined8 PepSubsystemGetPciLinkState(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  char cVar4;
  char *pcVar5;
  
  cVar4 = (char)param_3;
  uVar3 = 5;
  uVar1 = 0xff;
  if (param_1 == (undefined8 *)0x0) {
    return 5;
  }
  uVar2 = (uint)param_2;
  if (uVar2 == 0xffffffff) {
    return 5;
  }
  if (cVar4 == '\0') {
    uVar2 = uVar2 >> 0x10;
  }
  else {
    uVar1 = (uint)((ulonglong)param_2 >> 0x18) & 0xff;
    uVar2 = uVar2 >> 0x13;
  }
  uVar2 = uVar2 & 0xf;
  if ((uVar2 == 0) || (uVar2 == 1)) {
LAB_14000d2ac:
    uVar3 = 0;
  }
  else {
    if (uVar2 == 3) {
      if ((cVar4 == '\0') || (uVar1 < 0x3d)) {
        return 1;
      }
      if (uVar1 < 0x3f) {
        return 2;
      }
      if (uVar1 - 0x3f < 2) {
        return 3;
      }
      pcVar5 = "INTELPEP: inconsistent link state for value read: %I64x \n";
      DbgPrintEx(0x92,1,"INTELPEP: inconsistent link state for value read: %I64x \n",param_2);
      param_3 = CONCAT71((int7)((ulonglong)pcVar5 >> 8),cVar4);
    }
    else {
      if ((uVar2 == 4) || (uVar2 == 5)) {
        return 4;
      }
      if ((((uVar2 == 7) || (uVar2 == 8)) || (uVar2 == 9)) || (uVar2 == 10)) goto LAB_14000d2ac;
    }
    PepDiagLogUnexpectedPciLinkValue(param_1,param_2,param_3,(ulonglong)uVar2,uVar1);
  }
  return uVar3;
}



===== PepSubsystemGetRegistryOverrides @ 14000d340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepSubsystemGetRegistryOverrides(void)

{
  int iVar1;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res10 = 0;
  if (*WdfDriverGlobals != 0) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                      (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,&local_res10);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_18,L"EnableCoffeeLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableCoffeeLakeAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableIceLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableIceLakeAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableLakeFieldAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableLakeFieldAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableCometLakeLPAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableCometLakeLPAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableCometLakeSHAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableCometLakeSHAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableTigerLakeLPAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableTigerLakeLPAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableTigerLakeHAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableTigerLakeHAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableRocketLakeSAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableRocketLakeSAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableJasperLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableJasperLakeAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableMeteorLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableMetorLakeAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableLunarLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableLunarLakeAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnableArrowLakeAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepSubsystemEnableArrowLakeSAccounting = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"EnablePepv2SubsystemAccounting");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        Pepv2SubsystemAccountingEnabled = local_res8[0] != 0;
      }
      RtlInitUnicodeString(&local_18,L"CollectPcieHierarchyDiagnostic");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,local_res8);
      if (-1 < iVar1) {
        PepPcieCollectPcieHierarchyDiagnostic = local_res8[0] != 0;
      }
    }
    if (local_res10 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    }
  }
  return;
}



===== PepSubsystemGetResidencyRegisterCount @ 14000d7ec =====

int PepSubsystemGetResidencyRegisterCount(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if ((PepSubsystemAccountingCount == 0) || (PepSubsystemAccountingInfo == 0)) {
    Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  }
  else {
    uVar3 = 0;
    if (PepSubsystemAccountingCount != 0) {
      puVar1 = (uint *)(PepSubsystemAccountingInfo + 0x10);
      do {
        if (puVar1[1] != 0) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        if ((*puVar1 & 4) != 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1;
        puVar1 = puVar1 + 0x36;
      } while (uVar3 < PepSubsystemAccountingCount);
    }
  }
  return iVar2;
}



===== PepSubsystemGetVelocityOverrides @ 14000d848 =====

void PepSubsystemGetVelocityOverrides(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong local_res8;
  
  iVar3 = 0;
  if ((PepSubsystemSoCInfo == (undefined4 *)0x0) && (Pepv2SubsystemSocInfo == (undefined4 *)0x0)) {
    return;
  }
  uVar6 = 0;
  uVar5 = 0;
  if (PepSubsystemSoCInfo == (undefined4 *)0x0) {
    if (Pepv2SubsystemSocInfo == (undefined4 *)0x0) goto LAB_14000d898;
    piVar4 = *(int **)(Pepv2SubsystemSocInfo + 2);
    puVar1 = Pepv2SubsystemSocInfo;
  }
  else {
    piVar4 = *(int **)(PepSubsystemSoCInfo + 10);
    puVar1 = PepSubsystemSoCInfo;
  }
  iVar3 = *piVar4;
  uVar5 = puVar1[1];
  uVar6 = *puVar1;
LAB_14000d898:
  if ((((iVar3 == PepAlderLakePchS) || (iVar3 == PepAlderLakePchP)) || (iVar3 == PepRaptorLakePchS))
     && (puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x10,0x49504550),
        PepSubsystemVelocityErrataCounter = puVar1, puVar1 != (undefined4 *)0x0)) {
    *puVar1 = uVar6;
    puVar1[1] = uVar5;
    puVar1[2] = iVar3;
    if ((Feature_IntelADLRPLBugFix__private_featureState & 0x10) == 0) {
      uVar2 = Feature_IntelADLRPLBugFix__private_featureState | 1;
      local_res8 = (ulonglong)uVar2;
      wil_details_FeatureReporting_ReportUsageToService(0x1400330f0,local_res8,3);
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                (uVar2,3,&Feature_IntelADLRPLBugFix__private_descriptor);
    }
    PepSubsystemVelocityErrataCounter[3] = 1;
  }
  return;
}



===== PepSubsystemIdentifySoC @ 14000d95c =====

/* WARNING: Removing unreachable block (ram,0x00014000d975) */

void PepSubsystemIdentifySoC(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [2];
  
  uVar5 = 0;
  local_res8[0] = 0;
  puVar6 = (uint *)cpuid_Version_info(1);
  uVar1 = *puVar6;
  local_res18[0] = uVar1 >> 8 & 0xf;
  local_res10[0] = uVar1 >> 4 & 0xf;
  if (local_res18[0] == 0xf) {
    local_res18[0] = (uVar1 >> 0x14 & 0xff) + 0xf;
  }
  else if (local_res18[0] != 6) goto LAB_14000d9ba;
  local_res10[0] = local_res10[0] | uVar1 >> 0xc & 0xf0;
LAB_14000d9ba:
  uVar2 = local_res18[0];
  uVar1 = local_res10[0];
  uVar3 = PepSubsystemGetPchDeviceId(local_res18[0],local_res10[0],local_res8);
  if (-1 < (int)uVar3) {
    puVar6 = &DAT_140061b64;
    local_res8[0] = local_res8[0] & 0xff80ffff;
    do {
      if (((uVar2 == puVar6[-1]) && (uVar1 == *puVar6)) &&
         (local_res8[0] == **(uint **)(puVar6 + 9))) {
        PepSubsystemSoCInfo = &PepSubsystemSocList + uVar5 * 0x16;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      puVar6 = puVar6 + 0x16;
    } while (uVar4 < 9);
    Pepv2SubsystemIdentifySoC((int *)local_res18,(int *)local_res10,(int *)local_res8);
  }
  return;
}



===== PepSubsystemInitializeActiveCounters @ 14000da38 =====

void PepSubsystemInitializeActiveCounters(void)

{
  byte bVar1;
  int iVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  
  uVar5 = 0;
  if (PepSubsystemAccountingCount != 0) {
    do {
      lVar6 = uVar5 * 0xd8 + PepSubsystemAccountingInfo;
      uVar4 = *(uint *)(lVar6 + 0x14);
      if (((uVar4 < 0x13) && ((0x5f002U >> (uVar4 & 0x1f) & 1) != 0)) &&
         ((*(uint *)(lVar6 + 0x10) & 0x4000) != 0)) goto LAB_14000dba5;
      if ((uVar4 - 6 < 2) || (uVar4 == 0x14)) {
        *(undefined1 *)(lVar6 + 0x20) = 1;
      }
      if (*(char *)(lVar6 + 0x20) == '\0') {
        plVar3 = (longlong *)(lVar6 + 0x28);
        if ((*plVar3 != 0) || (iVar2 = PepGetTscFrequencyInHz(plVar3), -1 < iVar2)) {
          if (*(int *)(lVar6 + 0x14) == 0xb) {
            if (*(int *)(lVar6 + 0x30) == 2) {
              uVar4 = *(uint *)(lVar6 + 0x40) & 0x1f;
              uVar9 = *(uint *)(lVar6 + 0x40) >> 5 & 7;
              bVar1 = PepSubsystemIsPciRootPortReadable(plVar3,uVar4,uVar9,lVar6);
              uVar7 = (uint)bVar1;
              DbgPrintEx(0x92,3,"INTELPEP: B/D/F: 0x%x/0x%x/0x%x : Present? : %x\n",0,uVar4,uVar9,
                         uVar7);
              if (bVar1 == 0) goto LAB_14000daf7;
              if (*(longlong *)(lVar6 + 0x18) != 0) {
                DbgPrintEx(0x92,3,
                           "INTELPEP: Successfully received diagnostic info for root port (0x%x/0x%x/0x%x). \n"
                           ,0,uVar4,uVar9,uVar7);
                goto LAB_14000db85;
              }
            }
            else {
              DbgPrintEx(0x92,0,
                         "INTELPEP: Expected PCI based address for PCI Link State reporting.\n");
LAB_14000daf7:
              *(undefined1 *)(lVar6 + 0x20) = 1;
            }
            *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffffd;
            goto LAB_14000dba9;
          }
LAB_14000db85:
          uVar4 = PepValidateAndInitAddress((int *)(lVar6 + 0x30));
          if ((-1 < (int)uVar4) &&
             ((*(int *)(lVar6 + 0x88) == -1 ||
              (uVar4 = PepValidateAndInitAddress((int *)(lVar6 + 0x88)), -1 < (int)uVar4))))
          goto LAB_14000dba9;
        }
LAB_14000dba5:
        *(undefined1 *)(lVar6 + 0x20) = 1;
      }
LAB_14000dba9:
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < PepSubsystemAccountingCount);
  }
  uVar4 = PepSubsystemAccountingCount;
  uVar7 = PepSubsystemHwDripsIndex + 1;
  if (uVar7 < PepSubsystemAccountingCount) {
    puVar8 = (uint *)(PepSubsystemAccountingInfo + 0x10 + (ulonglong)uVar7 * 0xd8);
    do {
      if (puVar8[1] != 0) break;
      if ((*puVar8 >> 0xb & 1) != 0) {
        *puVar8 = *puVar8 & 0xfffffffd;
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 0x36;
    } while (uVar7 < uVar4);
  }
  uVar4 = PepValidateAndInitAddress((int *)&PepBiosMailboxCommandAddress);
  if (((int)uVar4 < 0) ||
     (uVar4 = PepValidateAndInitAddress((int *)&PepBiosMailboxDataAddress), (int)uVar4 < 0)) {
    PepSubsystemEnableDebugPkgCounters = 0;
    return;
  }
  return;
}



===== PepSubsystemInitializeCounter @ 14000dc54 =====

undefined8 PepSubsystemInitializeCounter(longlong param_1,uint *param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (((uVar1 & 4) != 0) && (PepSubsystemDeepestPkgStateInfo == 0)) {
    PepSubsystemDeepestPkgStateInfo = param_1;
  }
  if (((uVar1 & 8) != 0) && (PepSubsystemSlpS0Info == 0)) {
    PepSubsystemSlpS0Info = param_1;
  }
  if (((param_3 != 0) && (*(int *)(param_1 + 0x14) == 0)) &&
     ((short)*(undefined4 *)(param_1 + 0x58) == (short)*(undefined4 *)(param_3 + 0x48))) {
    PepSubsystemHwDripsIndex = *param_2;
    *(uint *)(param_1 + 0x10) = uVar1 & 0xfffffffd;
    PepSubsystemHwDripsInfo = param_1;
  }
  if ((PepSubsystemHwDripsInfo == 0) && (*(int *)(param_1 + 0x14) != 0)) {
    PepDiagLogHwDripsCounterNotFound();
    return 0xc0000225;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  if (((iVar2 == 10) || (iVar2 == 0x13)) && (PepSubsystemHwDripsIndex < 7)) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  }
  if (iVar2 == 5) {
    if (PepSubsystemEnableDebugPchCounters == '\0') goto LAB_14000dd2e;
    if (PepSubsystemDebugPchMailboxRequired != '\0') {
      *(undefined8 *)(param_1 + 0x18) = PepSubsystemPmcStatusRegister;
    }
  }
  else if (iVar2 != 7) {
    if (iVar2 == 0x14) {
      if (((*(uint *)(param_1 + 0x10) & 0x40) != 0) && (PepSubsystemHwDripsIndex < 7)) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
      }
      (&PepSubsystemUnattributedPkgCInfo)[PepSubsystemUnattributedPkgCCount] = param_1;
      PepSubsystemUnattributedPkgCCount = PepSubsystemUnattributedPkgCCount + 1;
      return 0;
    }
    if (iVar2 != 3) {
      return 0;
    }
    lVar3 = ExAllocatePool2(0x40,0x10,0x49504550);
    if (lVar3 == 0) {
      return 0xc000009a;
    }
    *(longlong *)(param_1 + 200) = lVar3;
    return 0;
  }
  if (6 < PepSubsystemHwDripsIndex) {
    return 0;
  }
LAB_14000dd2e:
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  return 0;
}



===== PepSubsystemInitializeEnergyReporting @ 14000ddb0 =====

uint PepSubsystemInitializeEnergyReporting(undefined8 *param_1)

{
  int *piVar1;
  uint uVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  ulonglong local_res8;
  
  local_res8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    return 0xc0000001;
  }
  if ((int *)*param_1 == (int *)0x0) {
    return 0xc0000001;
  }
  uVar2 = PepValidateAndInitAddress((int *)*param_1);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  PepReadRegisterWithBus((int *)*param_1,0,(uint *)&local_res8);
  if ((local_res8 & 4) == 0) {
    return 0xc0000429;
  }
  if ((int *)param_1[1] == (int *)0x0) {
    return uVar2;
  }
  uVar2 = PepValidateAndInitAddress((int *)param_1[1]);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  piVar1 = (int *)param_1[3];
  if (piVar1 == (int *)0x0) {
    return 0xc0000001;
  }
  uVar2 = PepValidateAndInitAddress(piVar1);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (*(int *)((longlong)param_1 + 0x14) == 1) {
    if ((local_res8 & 0x400000) != 0) {
      return 0xc0000429;
    }
    PepSubsystemDebugPchMailboxRequired = 1;
    PepSubsystemPmcStatusRegister = piVar1;
  }
  if (((int *)param_1[5] != (int *)0x0) && (param_1[6] != 0)) {
    uVar2 = PepValidateAndInitAddress((int *)param_1[5]);
    if ((int)uVar2 < 0) {
      lVar4 = param_1[5];
      pwVar3 = L"ErC10AccountingRegister";
      goto LAB_14000de97;
    }
    uVar2 = PepValidateAndInitAddress((int *)param_1[6]);
    if ((int)uVar2 < 0) {
      lVar4 = param_1[6];
      pwVar3 = L"ErSlpS0HaltRegister";
      goto LAB_14000de97;
    }
    PepSubsystemEnableErPolicyBits = 1;
  }
  if (((int *)param_1[7] == (int *)0x0) ||
     (uVar2 = PepValidateAndInitAddress((int *)param_1[7]), -1 < (int)uVar2)) {
    return 0;
  }
  lVar4 = param_1[7];
  pwVar3 = L"S0ixBlockerEnablePolicyRegister";
LAB_14000de97:
  PepDiagLogIncorrectErPolicyRegister(pwVar3,lVar4);
  return uVar2;
}



===== PepSubsystemIsPciRootPortReadable @ 14000df00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
PepSubsystemIsPciRootPortReadable(undefined8 param_1,uint param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  undefined2 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_48 [2];
  wchar_t local_40 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  if (PepPcieGeneratePcieHierarchyEnabled != '\0') {
    if (param_2 < 0x20) {
      if (param_3 < 8) {
        local_50 = 4;
        local_58 = 0;
        iVar3 = HalGetBusDataByOffset(4,0,(param_3 & 7) << 5 | param_2 & 0x1f,local_48);
        if (iVar3 != 4) {
          DbgPrintEx(0x92,3,"INTELPEP: VendorId & Device Id config space read failed.\n");
          return 0;
        }
        if ((short)local_48[0] == -1) {
          return 0;
        }
        lVar1 = *(longlong *)(param_4 + 0x18);
        lVar4 = ExAllocatePool2(0x40,0x10,0x49504550);
        *(longlong *)(lVar1 + 8) = lVar4;
        if (lVar4 == 0) {
          return 1;
        }
        uVar5 = ExAllocatePool2(0x40,0x40,0x49504550);
        *(undefined8 *)(*(longlong *)(lVar1 + 8) + 8) = uVar5;
        puVar2 = *(undefined2 **)(lVar1 + 8);
        if (*(longlong *)(puVar2 + 4) == 0) {
          ExFreePoolWithTag(puVar2,0x49504550);
          *(undefined8 *)(lVar1 + 8) = 0;
          return 1;
        }
        *puVar2 = 0;
        *(undefined2 *)(*(longlong *)(lVar1 + 8) + 2) = 0x40;
        swprintf_s(local_40,6,L"%X");
        RtlAppendUnicodeToString(*(undefined8 *)(lVar1 + 8),L"VEN_8086&DEV_");
        RtlAppendUnicodeToString(*(undefined8 *)(lVar1 + 8),local_40);
        return 1;
      }
      pcVar6 = "INTELPEP: Tried to check an Invalid PCI Function number\n";
    }
    else {
      pcVar6 = "INTELPEP: Tried to check an Invalid PCI Device number\n";
    }
    DbgPrintEx(0x92,0,pcVar6);
  }
  return 0;
}



===== PepSubsystemPostPchMailbox @ 14000e0c0 =====

void PepSubsystemPostPchMailbox(undefined8 *param_1,ulonglong *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint local_res18;
  
  if (((*(char *)(param_1 + 4) == '\0') && (PepSubsystemEnableDebugPchCounters != '\0')) &&
     (param_1[3] != 0)) {
    puVar2 = (uint *)param_1[0xc];
    uVar1 = *(uint *)(param_1 + 0x18);
    puVar3 = *(uint **)(param_1[3] + 0x30);
    puVar4 = (uint *)param_1[0x17];
    *puVar4 = uVar1;
    LOCK();
    UNLOCK();
    iVar5 = 0;
    local_res18 = *puVar4;
    while (local_res18 != uVar1) {
      if (iVar5 == 500) {
        PepDiagLogPmcMailboxFails((wchar_t *)*param_1,local_res18,0);
        PepSubsystemInvalidSessionBitMask = PepSubsystemInvalidSessionBitMask | 2;
        PepSubsystemEnableDebugPchCounters = 0;
        PepSubsystemDebugPchMailboxRequired = 0;
        return;
      }
      KeStallExecutionProcessor(10);
      iVar5 = iVar5 + 1;
      local_res18 = *puVar4;
    }
    iVar5 = 0;
    while ((*puVar3 >> 0x18 & 1) != 0) {
      if (iVar5 == 500) {
        PepDiagLogPmcMailboxFails((wchar_t *)*param_1,local_res18,(ulonglong)*puVar3);
        PepSubsystemInvalidSessionBitMask = PepSubsystemInvalidSessionBitMask | 4;
        PepSubsystemEnableDebugPchCounters = 0;
        PepSubsystemDebugPchMailboxRequired = 0;
        return;
      }
      KeStallExecutionProcessor(10);
      iVar5 = iVar5 + 1;
    }
    uVar1 = *puVar2;
    *param_2 = (ulonglong)
               (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18);
  }
  return;
}



===== PepSubsystemReadResidencyCounter @ 14000e218 =====

void PepSubsystemReadResidencyCounter(undefined8 *param_1,ulonglong *param_2)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  
  bVar5 = PepSubsystemEnableDebugPkgCounters != '\0';
  *param_2 = 0;
  piVar1 = (int *)((longlong)param_1 + 0x14);
  if ((bVar5) || (*piVar1 != 3)) {
    if (PepSubsystemEnableDebugPchCounters == '\0') {
      if (*piVar1 == 5) {
        return;
      }
    }
    else if ((*piVar1 == 5) && (PepSubsystemDebugPchMailboxRequired != '\0')) {
      PepSubsystemPostPchMailbox(param_1,param_2);
      return;
    }
    if (*(char *)(param_1 + 4) == '\0') {
      iVar2 = *(int *)((longlong)param_1 + 0x34);
      if (iVar2 == 0x40) {
        uVar4 = 0xffffffffffffffff;
      }
      else if (iVar2 == 0x20) {
        uVar4 = 0xffffffff;
      }
      else if (iVar2 == 0x10) {
        uVar4 = 0xffff;
      }
      else {
        if (iVar2 != 8) {
          return;
        }
        uVar4 = 0xff;
      }
      if (*(int *)(param_1 + 0x11) != -1) {
        PepSubsystemWriteCommand
                  ((wchar_t *)*param_1,(int *)(param_1 + 0x11),param_1 + 0x18,(uint *)param_1[0x19])
        ;
      }
      if ((*(uint *)(param_1 + 2) & 0x200000) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (ulonglong)PepSubsystemPchBusNumber;
      }
      PepReadRegisterWithBus((int *)(param_1 + 6),uVar3,(uint *)param_2);
      *param_2 = *param_2 & uVar4;
    }
  }
  return;
}



===== PepSubsystemReadResidencyCounterFromIntcPmt @ 14000e308 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepSubsystemReadResidencyCounterFromIntcPmt(longlong param_1,ulonglong *param_2)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  char *pcVar6;
  
  *param_2 = 0;
  uVar3 = *(longlong *)(param_1 + 0x58) >> 0x3f & 3;
  uVar2 = *(longlong *)(param_1 + 0x58) + uVar3;
  uVar5 = (longlong)uVar2 >> 2;
  if (((uVar2 & 3) == uVar3) && (*(char *)(param_1 + 0x20) == '\0')) {
    iVar1 = *(int *)(param_1 + 0x34);
    if (iVar1 == 0x40) {
      uVar2 = 0xffffffffffffffff;
    }
    else if (iVar1 == 0x20) {
      uVar2 = 0xffffffff;
    }
    else if (iVar1 == 0x10) {
      uVar2 = 0xffff;
    }
    else {
      if (iVar1 != 8) goto LAB_14000e434;
      uVar2 = 0xff;
    }
    if ((Pepv2SubsystemGuidIdentifierArray == *(int *)(param_1 + 0xd0)) && (DAT_140087650 != '\0'))
    {
      if (DAT_140087658 == 0) {
        pcVar6 = "INTELPEP: Unexpected NULL data buffer\n";
      }
      else {
        uVar4 = (uint)uVar5;
        if (_DAT_14008764c <= uVar4) {
          DbgPrintEx(0x92,3,"IntelPEP: Invalid Buffer Index 0x%x\n",uVar5 & 0xffffffff);
          return;
        }
        if (uVar2 != 0xffffffffffffffff) {
          *param_2 = *(uint *)(DAT_140087658 + (uVar5 & 0xffffffff) * 4) & uVar2;
          return;
        }
        if (uVar4 < _DAT_14008764c - 1) {
          *param_2 = CONCAT44(*(undefined4 *)(DAT_140087658 + (ulonglong)(uVar4 + 1) * 4),
                              *(undefined4 *)(DAT_140087658 + (uVar5 & 0xffffffff) * 4));
          return;
        }
        pcVar6 = "INTELPEP: Invalid Buffer Index Accessed\n";
      }
      DbgPrintEx(0x92,3,pcVar6);
    }
  }
  else {
LAB_14000e434:
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  }
  return;
}



===== PepSubsystemRestorePkgCStateThreshold @ 14000e444 =====

void PepSubsystemRestorePkgCStateThreshold(void)

{
  PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
  PepSubsystemLtrBlockingThreshold = 0xcb5e8;
  return;
}



===== PepSubsystemSnapActiveCounters @ 14000e468 =====

void PepSubsystemSnapActiveCounters(int param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong local_res10 [3];
  
  local_res10[1] = 0;
  if (param_1 == PepDripsIndex) {
    PepSubsystemLastDripsResidency = KeQueryInterruptTimePrecise(local_res10 + 1);
    if ((PepSubsystemEnableDebugPchCounters != '\0') && (PepSubsystemEnableErPolicyBits != '\0')) {
      PepSubsystemEnableEnergyReportingPolicyHandling('\x01');
    }
    if (PepSubsystemEnableDebugPkgCounters != '\0') {
      local_res10[2] = 0x80000114;
      PepSubsystemWriteCommand
                (L"StartPkgcFlowCounterCommand",(int *)&PepBiosMailboxCommandAddress,local_res10 + 2
                 ,(uint *)&PepSubsystemStartCmdTimeAccounting);
    }
    uVar1 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 != 0) {
      PepSubsystemSnapActiveCountersFromIntcPmt();
    }
    uVar1 = 0;
    if (PepSubsystemAccountingCount != 0) {
      do {
        local_res10[0] = 0;
        puVar3 = (undefined8 *)(uVar1 * 0xd8 + PepSubsystemAccountingInfo);
        uVar2 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar2 == 0) || ((*(uint *)(puVar3 + 2) >> 0x17 & 1) == 0)) {
          PepSubsystemReadResidencyCounter(puVar3,local_res10);
LAB_14000e549:
          puVar3[0xe] = local_res10[0];
        }
        else if ((*(uint *)(puVar3 + 2) >> 0xe & 1) == 0) {
          PepSubsystemReadResidencyCounterFromIntcPmt((longlong)puVar3,local_res10);
          goto LAB_14000e549;
        }
        uVar4 = (int)uVar1 + 1;
        uVar1 = (ulonglong)uVar4;
      } while (uVar4 < PepSubsystemAccountingCount);
    }
  }
  return;
}



===== PepSubsystemSnapActiveCountersFromIntcPmt @ 14000e570 =====

void PepSubsystemSnapActiveCountersFromIntcPmt(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Pepv2SubsystemGuidIdentifierArray;
  if (((PepIntcExclusivePmtDdiInterfaceAvailable != '\0') && (DAT_140087650 != '\0')) &&
     (DAT_140087658 != (void *)0x0)) {
    memset(DAT_140087658,0,(ulonglong)DAT_140087660);
    uVar2 = Pepv2SubsystemSnapIntcPmtCounters(&Pepv2SubsystemGuidIdentifierArray);
    if ((int)uVar2 < 0) {
      DbgPrintEx(0x92,3,
                 "INTELPEP: Couldn\'t read IntcPMT Telemetry for TelemGuid 0x%x. Status 0x%x\n",
                 Pepv2SubsystemGuidIdentifierArray,uVar2);
      PepSubsystemDisablePmtCountersPerTelemetryGuid(uVar1);
    }
  }
  return;
}



===== PepSubsystemUpdateActiveTimes @ 14000e5f8 =====

void PepSubsystemUpdateActiveTimes
               (int param_1,undefined8 param_2,ulonglong *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong local_res10 [3];
  
  local_res10[0] = 0;
  local_res10[1] = 0;
  if (param_1 == PepDripsIndex) {
    if ((PepSubsystemEnableDebugPchCounters != '\0') && (PepSubsystemEnableErPolicyBits != '\0')) {
      PepSubsystemEnableEnergyReportingPolicyHandling('\0');
    }
    lVar3 = KeQueryInterruptTimePrecise(local_res10 + 1);
    PepSubsystemLastDripsResidency = lVar3 - PepSubsystemLastDripsResidency;
    PepSubsystemTotalSwDripsResidency =
         PepSubsystemTotalSwDripsResidency + PepSubsystemLastDripsResidency;
    uVar4 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      PepSubsystemSnapActiveCountersFromIntcPmt();
    }
    uVar4 = 0;
    if (PepSubsystemAccountingCount != 0) {
      do {
        local_res10[0] = 0;
        puVar9 = (undefined8 *)(uVar4 * 0xd8 + PepSubsystemAccountingInfo);
        uVar10 = *(uint *)((longlong)puVar9 + 0x14);
        if (((uVar10 != 7) && ((*(uint *)(puVar9 + 2) >> 0xf & 1) == 0)) &&
           ((0x12 < uVar10 ||
            (((0x5f002U >> (uVar10 & 0x1f) & 1) == 0 || ((*(uint *)(puVar9 + 2) & 0x5000) != 0x5000)
             ))))) {
          uVar5 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar5 == 0) || ((*(uint *)(puVar9 + 2) >> 0x17 & 1) == 0)) {
            PepSubsystemReadResidencyCounter(puVar9,local_res10);
          }
          else {
            if ((*(uint *)(puVar9 + 2) >> 0xe & 1) != 0) goto LAB_14000e999;
            PepSubsystemReadResidencyCounterFromIntcPmt((longlong)puVar9,local_res10);
          }
          iVar1 = *(int *)((longlong)puVar9 + 0x14);
          if (iVar1 < 0xb) {
            if (((iVar1 == 10) || (iVar1 == 0)) || (iVar1 == 1)) {
LAB_14000e8f3:
              lVar3 = puVar9[0xe];
              if ((longlong)local_res10[0] < lVar3) {
                if (*(int *)((longlong)puVar9 + 0x34) == 0x40) {
                  lVar6 = -1;
                }
                else {
                  lVar6 = 0;
                  if (*(int *)((longlong)puVar9 + 0x34) == 0x20) {
                    lVar6 = 0xffffffff;
                  }
                }
                lVar6 = lVar6 - lVar3;
              }
              else {
                lVar6 = -lVar3;
              }
              local_res10[0] = local_res10[0] + lVar6;
              lVar3 = PepSubsystemCyclesTo100ns((longlong)(puVar9 + 4),local_res10[0]);
              puVar9[0xf] = lVar3;
              if ((((*(int *)((longlong)puVar9 + 0x14) == 10) && (lVar3 != 0)) &&
                  (5 < PepSubsystemUnattributedPkgCCount)) &&
                 (*(longlong *)(PepSubsystemDeepestPkgStateInfo + 0x78) != 0)) {
                *(uint *)(DAT_140087988 + 0x10) = *(uint *)(DAT_140087988 + 0x10) | 0x20;
              }
              goto LAB_14000e97c;
            }
            if (iVar1 == 2) {
LAB_14000e8b7:
              uVar5 = PepSubsystemEstimateLtrResidency
                                (puVar9,(int *)(puVar9 + 0xe),(int *)local_res10);
              goto LAB_14000e978;
            }
            if (iVar1 == 3) {
              param_4 = 0;
              puVar8 = local_res10;
              param_3 = (ulonglong *)0x0;
              PepDiagLogSubsystemCounter(puVar9,puVar8,0,0);
              lVar3 = puVar9[0xe];
              if ((longlong)local_res10[0] < lVar3) {
                local_res10[0] = (ulonglong)(ushort)(((short)local_res10[0] - (short)lVar3) - 1);
              }
              else {
                local_res10[0] = local_res10[0] - lVar3;
              }
              puVar9[0xf] = local_res10[0];
              plVar7 = (longlong *)0x0;
              if ((undefined8 *)puVar9[3] != (undefined8 *)0x0) {
                plVar7 = *(longlong **)puVar9[3];
                *plVar7 = *plVar7 + local_res10[0];
              }
              if (((char)*(undefined4 *)(puVar9 + 2) < '\0') &&
                 (PepSubsystemEnableDebugPkgCounters != '\0')) {
                PepDiagLogPkgcNormalizationCategorySum(plVar7,puVar8,param_3,param_4);
                PepSubsystemComputePkgcNormalizationAndBlockingTime();
              }
            }
            else if (iVar1 == 4) {
              uVar5 = PepSubsystemEstimateUngatedTime((longlong)puVar9,(uint *)local_res10);
LAB_14000e7fd:
              puVar9[0xf] = uVar5;
            }
            else if (iVar1 == 5) {
              if ((PepSubsystemEnableDebugPchCounters != '\0') && (6 < PepSubsystemHwDripsIndex)) {
                param_4 = 0;
                param_3 = (ulonglong *)0x0;
                PepDiagLogSubsystemCounter(puVar9,local_res10,0,0);
                lVar3 = puVar9[0xe];
                uVar2 = *(ulonglong *)(PepSubsystemDeepestPkgStateInfo + 0x78);
                if ((longlong)local_res10[0] < lVar3) {
                  lVar3 = (local_res10[0] - lVar3) + 0xffffffff;
                }
                else {
                  lVar3 = local_res10[0] - lVar3;
                }
                uVar5 = lVar3 * 10;
                local_res10[0] = uVar5;
                if (uVar2 < uVar5) {
                  uVar5 = uVar2;
                  local_res10[0] = uVar2;
                }
                goto LAB_14000e7fd;
              }
            }
            else {
              if (iVar1 == 6) {
                uVar5 = PepSubsystemUpdateGroupResidencyBlockingTime((longlong)puVar9);
                goto LAB_14000e978;
              }
              if (iVar1 == 8) {
                uVar5 = PepSubsystemEstimateSlpS0DbgTime
                                  ((longlong)puVar9,(uint *)local_res10,param_3);
                goto LAB_14000e7fd;
              }
              if (iVar1 == 9) {
                PepDiagLogSlpS0WakeCounter((longlong)puVar9,(uint *)local_res10,param_3,param_4);
                puVar9[0xf] = 0;
              }
            }
          }
          else {
            if (iVar1 != 0xb) {
              if (((iVar1 != 0xc) && (iVar1 != 0xd)) && (iVar1 != 0xe)) {
                if (iVar1 == 0xf) {
                  if ((*(uint *)(puVar9 + 2) & 0x2000) != 0) {
                    puVar9[0xf] = 0;
                    param_3 = local_res10;
                    PepSubsystemUpdateCtaLtrThreshold(puVar9,(int *)(puVar9 + 0xe),(int *)param_3);
                  }
                }
                else {
                  if (iVar1 == 0x10) goto LAB_14000e8b7;
                  if ((iVar1 == 0x12) || (iVar1 == 0x13)) goto LAB_14000e8f3;
                  if (iVar1 == 0x14) {
                    uVar5 = PepSubsystemUpdateUnattributedPkgCCounter((longlong)puVar9);
                    goto LAB_14000e978;
                  }
                }
                goto LAB_14000e98e;
              }
              goto LAB_14000e8f3;
            }
            uVar5 = PepSubsystemEstimatePciLinkStateResidency(puVar9,puVar9 + 0xe,local_res10);
LAB_14000e978:
            puVar9[0xf] = uVar5;
LAB_14000e97c:
            param_4 = 0;
            param_3 = (ulonglong *)0x0;
            PepDiagLogSubsystemCounter(puVar9,local_res10,0,0);
          }
LAB_14000e98e:
          puVar9[0x10] = puVar9[0x10] + puVar9[0xf];
        }
LAB_14000e999:
        uVar10 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar10;
      } while (uVar10 < PepSubsystemAccountingCount);
    }
    if (PepSubsystemEnableDebugPkgCounters != '\0') {
      local_res10[2] = 0x80000214;
      PepSubsystemWriteCommand
                (L"StopPkgcFlowCounterCommand",(int *)&PepBiosMailboxCommandAddress,local_res10 + 2,
                 (uint *)&PepSubsystemStopCmdTimeAccounting);
    }
  }
  return;
}



===== PepSubsystemUpdateCtaLtrThreshold @ 14000e9ec =====

void PepSubsystemUpdateCtaLtrThreshold(undefined8 *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  lVar3 = PepSubsystemPkgCStateThreshold;
  uVar5 = *param_2 * 1000;
  puVar2 = (uint *)param_1[3];
  uVar4 = (ulonglong)uVar5;
  if ((uint)(*param_3 * 1000) <= uVar5) {
    uVar4 = (ulonglong)(uint)(*param_3 * 1000);
  }
  uVar1 = *puVar2;
  if (uVar1 < 7) {
    *(int *)(PepSubsystemPkgCStateThreshold + 8 + (longlong)(int)uVar1 * 0x10) = (int)uVar4;
    uVar1 = *puVar2;
    if (uVar1 != 0) {
      if (((*(uint *)(param_1 + 2) & 0x8000) == 0) && (uVar4 == 0)) {
        PepDiagLogIncorrectPmtLtrThreshold((wchar_t *)*param_1,(ulonglong)uVar1,0,(ulonglong)uVar5);
        PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
        PepSubsystemLtrBlockingThreshold = 0xcb5e8;
      }
      else if (uVar1 == 6) {
        PepSubsystemLtrBlockingThreshold = (ulonglong)*(uint *)(lVar3 + 0x68);
      }
    }
  }
  return;
}



===== PepSubsystemUpdateGroupResidencyBlockingTime @ 14000ea7c =====

ulonglong PepSubsystemUpdateGroupResidencyBlockingTime(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  byte *pbVar4;
  ulonglong uVar5;
  
  uVar3 = 0;
  uVar2 = **(uint **)(param_1 + 0x18);
  pbVar4 = *(byte **)(*(uint **)(param_1 + 0x18) + 2);
  if (uVar2 != 0) {
    uVar5 = (ulonglong)uVar2;
    do {
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 4;
      uVar3 = uVar3 + *(longlong *)((ulonglong)bVar1 * 0xd8 + 0x78 + PepSubsystemAccountingInfo);
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (((*(uint *)(param_1 + 0x10) & 1) != 0) && (PepSubsystemSlpS0Info != 0)) {
    if (*(ulonglong *)(PepSubsystemSlpS0Info + 0x80) < uVar3) {
      uVar3 = uVar3 - *(ulonglong *)(PepSubsystemSlpS0Info + 0x80);
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== PepSubsystemUpdateUnattributedPkgCCounter @ 14000eae8 =====

ulonglong PepSubsystemUpdateUnattributedPkgCCounter(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x14) == 0x14) {
    if ((*(uint *)(param_1 + 0x10) & 0x20) == 0) {
      uVar1 = **(uint **)(param_1 + 0x18);
      if (uVar1 < 7) {
        uVar2 = *(ulonglong *)((longlong)(int)uVar1 * 0xd8 + 0x78 + PepSubsystemAccountingInfo);
        if (((uVar1 == 6) && ((*(uint *)(PepSubsystemAccountingInfo + 0x520) & 1) != 0)) &&
           (PepSubsystemSlpS0Info != 0)) {
          if (*(ulonglong *)(PepSubsystemSlpS0Info + 0x80) < uVar2) {
            uVar2 = uVar2 - *(ulonglong *)(PepSubsystemSlpS0Info + 0x80);
          }
          else {
            uVar2 = 0;
          }
        }
      }
    }
    else {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
    }
  }
  return uVar2;
}



===== PepSubsystemWriteCommand @ 14000eb64 =====

void PepSubsystemWriteCommand(wchar_t *param_1,int *param_2,ulonglong *param_3,uint *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong local_res10;
  
  if (param_2[1] == 0x40) {
    uVar2 = 0xffffffffffffffff;
  }
  else {
    if (param_2[1] != 0x20) {
      return;
    }
    uVar2 = 0xffffffff;
  }
  *param_3 = *param_3 & uVar2;
  local_res10 = *param_3;
  PepWriteRegisterWithBus(param_2,0,&local_res10);
  iVar3 = 0;
  PepReadRegisterWithBus(param_2,0,(uint *)&local_res10);
  while ((int)(uint)local_res10 < 0) {
    if (iVar3 == 300) {
      PepDiagLogDbgPkgcFlowCntrWriteCmdFails(param_1,(uint)local_res10,*param_3);
      PepSubsystemInvalidSessionBitMask = PepSubsystemInvalidSessionBitMask | 1;
      PepSubsystemEnableDebugPkgCounters = 0;
      return;
    }
    KeStallExecutionProcessor(10);
    PepReadRegisterWithBus(param_2,0,(uint *)&local_res10);
    iVar3 = iVar3 + 1;
  }
  if (param_4 == (uint *)0x0) {
    return;
  }
  uVar1 = iVar3 * 10;
  if (param_4[3] == 0) {
    *param_4 = uVar1;
  }
  else {
    if (uVar1 <= *param_4) {
      *param_4 = uVar1;
      goto LAB_14000ec3e;
    }
    if (uVar1 <= param_4[1]) goto LAB_14000ec3e;
  }
  param_4[1] = uVar1;
LAB_14000ec3e:
  param_4[2] = param_4[2] + uVar1;
  param_4[3] = param_4[3] + 1;
  return;
}



===== Pepv2SubsystemSnapIntcPmtCounters @ 14000ec64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint Pepv2SubsystemSnapIntcPmtCounters(undefined4 *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined1 auStack_78 [32];
  int *local_58;
  uint local_50;
  int local_48 [2];
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  local_48[0] = 0;
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0xc000000d;
    pcVar5 = "IntelPEP: %s: NULL Input GUID!\n";
  }
  else {
    lVar4 = *(longlong *)(param_1 + 6);
    if (lVar4 == 0) {
      uVar2 = 0xc000009a;
      pcVar5 = "IntelPEP: %s: NULL PMT Telemetry DataBuffer\n";
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x1a);
      if (lVar1 == 0) {
        uVar2 = 0xc000009a;
        pcVar5 = "IntelPEP: %s: NULL PmtContext!\n";
      }
      else {
        if (*(longlong *)(lVar1 + 0xb8) != 0) {
          local_38 = param_1[1];
          uVar2 = param_1[8];
          local_30 = 0;
          local_34 = param_1[2];
          local_2c = param_1[3];
          lVar1 = *(longlong *)(lVar1 + 0xb8);
          lVar3 = KeQueryInterruptTimePrecise(&local_40);
          local_58 = local_48;
          uVar6 = (ulonglong)uVar2;
          uVar2 = (**(code **)(lVar1 + 0x38))(lVar1,&local_38,lVar4);
          lVar4 = KeQueryInterruptTimePrecise(&local_40);
          PepDiagLogPmtReadDuration(*param_1,lVar4 - lVar3,(ulonglong)uVar2,uVar6);
          if ((int)uVar2 < 0) {
            local_58 = (int *)CONCAT44(local_58._4_4_,(uint)*(byte *)(param_1 + 4));
            local_50 = uVar2;
            DbgPrintEx(0x92,0,
                       "INTELPEP: Reading PMT Telemetry failed for GUID: 0x%lx\nIsEnabled: 0x%lx with Status: 0x%x\n"
                       ,*param_1);
            return uVar2;
          }
          if (local_48[0] == 0) {
            DbgPrintEx(0x92,3,"INTELPEP: Data Buffer is empty; data not copied;  Status: 0x%x \n",
                       0xc0000001);
            return 0xc0000001;
          }
          return uVar2;
        }
        uVar2 = 0xc000009a;
        pcVar5 = "IntelPEP: %s: NULL PmtDdiContext!\n";
      }
    }
  }
  DbgPrintEx(0x92,0,pcVar5,"Pepv2SubsystemSnapIntcPmtCounters");
  return uVar2;
}



===== RtlUnicodeStringPrintf @ 14000ee10 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PepPcieCheckEndPointD3Requirement @ 14000eeb0 =====

void PepPcieCheckEndPointD3Requirement(longlong param_1)

{
  undefined8 *puVar1;
  
  if (PepPcieGeneratedConstraintEnabled != '\0') {
    for (puVar1 = *(undefined8 **)(param_1 + 0x10); puVar1 != (undefined8 *)(param_1 + 0x10);
        puVar1 = (undefined8 *)*puVar1) {
      if (((puVar1[8] & 0x200) == 0) && (*(char *)(puVar1 + 4) != '\0')) {
        puVar1[8] = puVar1[8] | 0x200;
        LOCK();
        *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
        UNLOCK();
        PepPcieQueueConstraintWork(param_1,1);
        return;
      }
    }
  }
  return;
}



===== PepPcieCheckRootPortParentLtrStatus @ 14000ef04 =====

void PepPcieCheckRootPortParentLtrStatus
               (ushort *param_1,longlong param_2,int param_3,undefined8 param_4)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  ushort *puVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  ushort *puVar8;
  undefined7 uVar9;
  uint local_res8 [2];
  ushort local_38 [8];
  
  uVar9 = (undefined7)((ulonglong)param_4 >> 8);
  if (param_1 != (ushort *)0x0) {
    uVar7 = 0;
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_38[4] = 0;
    local_38[5] = 0;
    local_38[6] = 0;
    local_38[7] = 0;
    if ((((param_2 != 0) && (*(longlong *)(param_2 + 0xb0) != 0)) &&
        (*(longlong *)(param_2 + 0xb8) != 0)) &&
       (piVar1 = (int *)(*(longlong *)(param_2 + 0xb8) + 0x10), piVar1 != (int *)0x0)) {
      local_res8[0] = 0;
      local_res8[1] = 0;
      PepReadRegisterWithBus(piVar1,0,local_res8);
      uVar4 = local_res8[0];
      plVar2 = *(longlong **)(param_2 + 0x10);
      if (((plVar2 == (longlong *)(param_2 + 0x10)) || (plVar2 == (longlong *)0x0)) ||
         (lVar3 = plVar2[3], lVar3 == 0)) {
        uVar6 = 0;
        RtlInitUnicodeString(local_38,L"NoChildDeviceInfo");
        puVar5 = local_38;
        puVar8 = local_38;
      }
      else {
        uVar7 = *(undefined2 *)(lVar3 + 0x56);
        puVar5 = (ushort *)(lVar3 + 0x20);
        uVar6 = *(undefined2 *)(lVar3 + 0x54);
        puVar8 = (ushort *)(lVar3 + 0x40);
      }
      PepDiagLogRootPortParentLtrStatus
                (param_1,*(ushort **)(param_2 + 0xb0),param_3,CONCAT71(uVar9,(char)param_4),uVar7,
                 uVar6,uVar4 >> 0xf & 1,uVar4 >> 0x1f,uVar4,puVar5,puVar8);
    }
  }
  return;
}



===== PepPcieDeviceStarted @ 14000f038 =====

void PepPcieDeviceStarted(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (PepPcieGeneratedConstraintEnabled != '\0') {
    lVar2 = (*(longlong **)(param_1 + 0x30))[1];
    lVar1 = **(longlong **)(param_1 + 0x30);
    if (lVar2 == 0) {
      if (lVar1 == 0) {
        return;
      }
      lVar2 = *(longlong *)(lVar1 + 0x28);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar2 != 0) {
      *(undefined4 *)(lVar2 + 0x50) = 3;
    }
    if (((lVar1 != 0) && (lVar2 != 0)) && (*(int *)(lVar2 + 0x30) == 8)) {
      KeSetEvent(lVar1 + 0x60,0,0);
      local_18 = *(undefined4 *)(lVar2 + 0x20);
      uStack_14 = *(undefined4 *)(lVar2 + 0x24);
      uStack_10 = *(undefined4 *)(lVar2 + 0x28);
      uStack_c = *(undefined4 *)(lVar2 + 0x2c);
      DbgPrintEx(0x92,3,
                 "INTELPEP: PepPcieDeviceStarted Set root port started event for device name:(%wZ) \n"
                 ,&local_18);
    }
  }
  return;
}



===== PepPcieGetLightestEndPointConstraint @ 14000f0d0 =====

undefined8 PepPcieGetLightestEndPointConstraint(longlong param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  
  uVar7 = 0xc0000001;
  if (((param_1 != 0) && (param_2 != (int *)0x0)) && (param_3 != (uint *)0x0)) {
    iVar6 = 5;
    uVar5 = 0xffffffff;
    for (puVar4 = *(undefined8 **)(param_1 + 0x10); puVar4 != (undefined8 *)(param_1 + 0x10);
        puVar4 = (undefined8 *)*puVar4) {
      if (PepPcieGeneratedConstraintEnabled == '\0') {
        lVar3 = puVar4[5];
      }
      else {
        lVar3 = puVar4[7];
      }
      if (lVar3 == 0) {
        return 0xc0000001;
      }
      iVar1 = *(int *)(lVar3 + (ulonglong)PepDripsIndex * 8);
      if ((iVar1 < iVar6) &&
         (uVar2 = *(uint *)(lVar3 + 4 + (ulonglong)PepDripsIndex * 8), iVar6 = iVar1, uVar2 < uVar5)
         ) {
        uVar5 = uVar2;
      }
    }
    *param_2 = iVar6;
    uVar7 = 0;
    *param_3 = uVar5;
  }
  return uVar7;
}



===== PepPcieGetRootPortLocation @ 14000f16c =====

undefined4 PepPcieGetRootPortLocation(longlong param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  longlong lVar4;
  char cVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  
  lVar4 = PepPcieSoCCpuConnectedRootPortInfo;
  puVar3 = PepPciePchConnectedRootPortBdfRange;
  uVar7 = 3;
  if (((*(int *)(param_1 + 0x30) == 8) && (PepPcieSoCCpuConnectedRootPortInfo != 0)) &&
     (PepPciePchConnectedRootPortBdfRange != (uint *)0x0)) {
    uVar1 = *(uint *)(param_1 + 0x34);
    uVar2 = *(uint *)(param_1 + 0x38);
    cVar5 = PepPcieRootPortInTable
                      (*(uint **)(PepPcieSoCCpuConnectedRootPortInfo + 0x10),uVar1,uVar2);
    if (cVar5 == '\0') {
      cVar5 = PepPcieRootPortInTable(puVar3,uVar1,uVar2);
      if (cVar5 == '\0') {
        cVar5 = PepPcieRootPortInTable(PepPcieDiscretePchConnectedRootPortBdfRange,uVar1,uVar2);
        uVar7 = 3;
        if (cVar5 != '\0') {
          uVar7 = 2;
        }
      }
      else {
        uVar7 = 1;
      }
    }
    else {
      uVar7 = 0;
      uVar6 = PepPcieRootPortInTable(*(uint **)(lVar4 + 0x20),uVar1,uVar2);
      *param_2 = uVar6;
    }
  }
  return uVar7;
}



===== PepPcieGetVendorDeviceId @ 14000f22c =====

void PepPcieGetVendorDeviceId(longlong param_1)

{
  int iVar1;
  undefined4 local_res8 [8];
  
  if (param_1 != 0) {
    local_res8[0] = 0;
    iVar1 = HalGetBusDataByOffset
                      (4,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),local_res8,
                       0,4);
    if ((iVar1 == 4) && ((short)local_res8[0] != -1)) {
      *(short *)(param_1 + 0x56) = (short)local_res8[0];
      *(short *)(param_1 + 0x54) = (short)((uint)local_res8[0] >> 0x10);
    }
  }
  return;
}



===== PepPcieQueueConstraintWork @ 14000f294 =====

void PepPcieQueueConstraintWork(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x98);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x98);
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *(uint *)(param_1 + 0x98) = uVar2 | param_2;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  if (uVar2 == 0) {
    ExQueueWorkItem(param_1 + 0x78,1);
  }
  return;
}



===== PepPcieRootPortInTable @ 14000f2dc =====

undefined1 PepPcieRootPortInTable(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if (param_1 != (uint *)0x0) {
    uVar1 = param_3 >> 5 & 7;
    if (((((*param_1 & 0xff) <= param_2) && (param_2 <= *(byte *)((longlong)param_1 + 1))) &&
        ((param_1[1] & 0xff) <= (param_3 & 0x1f))) &&
       (((param_3 & 0x1f) <= (uint)*(byte *)((longlong)param_1 + 5) &&
        ((param_1[2] & 0xff) <= uVar1)))) {
      uVar2 = 0;
      if (uVar1 <= *(byte *)((longlong)param_1 + 9)) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



===== PepPcieUpdateDiscreteBdfRange @ 14000f34c =====

undefined8 PepPcieUpdateDiscreteBdfRange(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  bool bVar6;
  
  uVar2 = PepSubsystemPchBusNumber;
  bVar6 = false;
  ppuVar5 = (undefined **)0x0;
  lVar3 = 0;
  while ((int)lVar3 == 0) {
    ppuVar5 = &PepPcieDiscretePchRootPortRangeList + lVar3 * 3;
    if ((int *)*ppuVar5 == (int *)0x0) {
      return 0xc0000001;
    }
    iVar1 = *(int *)*ppuVar5;
    bVar6 = param_1 == iVar1;
    DbgPrintEx(0x92,3,"INTELPEP: %s : %lx ID == %lx ID?\n","PepPcieUpdateDiscreteBdfRange",param_1,
               iVar1);
    if (param_1 == iVar1) break;
    lVar3 = 1;
  }
  if (bVar6) {
    if (ppuVar5[1] == (undefined *)0x0) {
      uVar4 = 0xc00000e5;
    }
    else {
      lVar3 = 0;
      do {
        ppuVar5[1][lVar3] = (char)uVar2;
        lVar3 = lVar3 + 1;
      } while (lVar3 < 2);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xc0000225;
  }
  return uVar4;
}



===== PepSubsystemFindRootPortInSpx @ 14000f438 =====

undefined8 PepSubsystemFindRootPortInSpx(longlong param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (uint *)0x0)) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8);
    local_28 = 0;
    uStack_20 = 0;
    for (uVar4 = 0; uVar4 < uVar1; uVar4 = uVar4 + 1) {
      RtlInitUnicodeString
                (&local_28,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + (ulonglong)uVar4 * 8));
      iVar2 = RtlCompareUnicodeString(param_2,&local_28,0);
      if (iVar2 == 0) {
        *param_3 = uVar4;
        return 0;
      }
    }
    uVar3 = 0xc0000225;
  }
  return uVar3;
}



===== Pepv2SubsystemGetRootPortParentInfo @ 14000f4ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint Pepv2SubsystemGetRootPortParentInfo(longlong param_1,longlong *param_2,longlong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 auStack_a8 [32];
  uint local_88;
  int local_80;
  uint local_78 [2];
  undefined8 local_70;
  undefined8 uStack_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_1 != 0) {
    if (PepSubsystemLtrStatusReportingSupported == '\0') {
      return 0xc00000bb;
    }
    if (PepSubsystemPchLtrStatusList == 0) {
      return 0xc00000bb;
    }
    if ((param_2 != (longlong *)0x0) && (param_3 != (longlong *)0x0)) {
      lVar4 = param_1;
      uVar2 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 == 0) {
        if (PepSubsystemLtrSpxCount == PepSubsystemPchLtrStatusCount) {
LAB_14000f56e:
          local_88 = (uint)*(ushort *)(param_1 + 0x54);
          local_60[0x10] = L'\0';
          local_60[0x11] = L'\0';
          local_60[0] = L'\0';
          local_60[1] = L'\0';
          local_60[2] = L'\0';
          local_60[3] = L'\0';
          local_60[4] = L'\0';
          local_60[5] = L'\0';
          local_60[6] = L'\0';
          local_60[7] = L'\0';
          local_60[8] = L'\0';
          local_60[9] = L'\0';
          local_60[10] = L'\0';
          local_60[0xb] = L'\0';
          local_60[0xc] = L'\0';
          local_60[0xd] = L'\0';
          local_60[0xe] = L'\0';
          local_60[0xf] = L'\0';
          iVar1 = swprintf_s(local_60,0x12,L"VEN_%X&DEV_%X");
          if (iVar1 < 0) {
            return 0xc0000001;
          }
          local_70 = 0;
          uStack_68 = 0;
          RtlInitUnicodeString(&local_70,local_60);
          local_78[0] = 0;
          uVar2 = 0;
          if (PepSubsystemLtrSpxCount != 0) {
            do {
              lVar4 = PepSubsystemLtrSpxInfo + uVar2 * 0x18;
              DbgPrintEx(0x92,3,"InstancePath ptr: %p\n",*(undefined8 *)(lVar4 + 0x10));
              uVar3 = PepSubsystemFindRootPortInSpx(lVar4,(longlong)&local_70,local_78);
              if ((int)uVar3 == 0) {
                local_88 = local_78[0];
                local_80 = (int)uVar2;
                DbgPrintEx(0x92,3,
                           "%s: Found Root Port match at RP Index: %x for Controller Index: %x\n",
                           "Pepv2SubsystemGetRootPortParentInfo");
                lVar4 = ExAllocatePool2(0x40,0x10,0x49504550);
                if (lVar4 == 0) {
                  return 0xc000009a;
                }
                RtlInitUnicodeString
                          (lVar4,*(undefined8 *)(PepSubsystemPchLtrStatusList + uVar2 * 0x28));
                *param_2 = lVar4;
                lVar5 = ExAllocatePool2(0x40,0x50,0x49504550);
                if (lVar5 == 0) {
                  uVar6 = 0xc000009a;
                }
                else {
                  *(undefined4 *)(lVar5 + 0x14) = 0x20;
                  *(int *)(lVar5 + 0x10) = 0;
                  *(undefined4 *)(lVar5 + 0x1c) = 3;
                  *(undefined8 *)(lVar5 + 0x38) =
                       *(undefined8 *)(PepSubsystemPchLtrStatusList + 0x18 + uVar2 * 0x28);
                  uVar6 = PepValidateAndInitAddress((int *)(lVar5 + 0x10));
                  if (-1 < (int)uVar6) {
                    *param_3 = lVar5;
                    return 0;
                  }
                }
                ExFreePoolWithTag(lVar4,0x49504550);
                if (lVar5 == 0) {
                  return uVar6;
                }
                ExFreePoolWithTag(lVar5,0x49504550);
                return uVar6;
              }
              uVar6 = (int)uVar2 + 1;
              uVar2 = (ulonglong)uVar6;
            } while (uVar6 < PepSubsystemLtrSpxCount);
          }
          return 0xc0000225;
        }
      }
      else {
        if (PepSubsystemLtrSpxCount <= PepSubsystemPchLtrStatusCount) goto LAB_14000f56e;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  (lVar4,PepSubsystemLtrSpxCount,PepSubsystemPchLtrStatusCount,
                   "Pepv2SubsystemGetRootPortParentInfo failed: More LTR Spx mappings than LTR status registers."
                  );
      }
      return 0xc00000bb;
    }
  }
  return 0xc000000d;
}



===== RtlUnicodeStringInitEx @ 14000f7a0 =====

uint RtlUnicodeStringInitEx(short *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  
  uVar2 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 != (short *)0x0) {
    lVar4 = 0x7fff;
    psVar3 = param_2;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      if (param_1 == (short *)0x0) {
        return 0xc000000d;
      }
      sVar1 = (0x7fff - (short)lVar4) * 2;
      *(short **)(param_1 + 4) = param_2;
      *param_1 = sVar1;
      param_1[1] = sVar1 + 2;
    }
    if (((int)uVar2 < 0) && (param_1 != (short *)0x0)) {
      param_1[0] = 0;
      param_1[1] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
    }
  }
  return uVar2;
}



===== PepPcieLtrApplyGlobalRootPortOverride @ 14000f82c =====

void PepPcieLtrApplyGlobalRootPortOverride
               (int *param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  uint local_res8 [2];
  ulonglong local_res18 [2];
  
  local_res18[0] = 0;
  if ((char)param_1[0xf] != '\0') {
    puVar1 = (uint *)(param_1 + 0xe);
    puVar3 = local_res18;
    if (param_2 == '\0') {
      uVar2 = 0;
      local_res18[0] = (ulonglong)*puVar1;
      PepWriteRegisterWithBus(param_1,0,puVar3);
      PepDiagLogGlobalLtrOverrideRegister(puVar1,uVar2,puVar3,param_4);
      DAT_140086f10 = 0;
    }
    else {
      PepReadRegisterWithBus(param_1,0,(uint *)puVar3);
      puVar3 = local_res18;
      uVar2 = 0;
      *puVar1 = (uint)local_res18[0];
      local_res18[0] = CONCAT44(local_res18[0]._4_4_,0xd7ffd7ff);
      PepWriteRegisterWithBus(param_1,0,puVar3);
      local_res8[0] = (uint)local_res18[0];
      PepDiagLogGlobalLtrOverrideRegister(local_res8,uVar2,puVar3,param_4);
      DAT_140086f10 = 1;
    }
  }
  return;
}



===== PepPcieLtrApplyOverride @ 14000f8c8 =====

void PepPcieLtrApplyOverride(int param_1,char param_2,uint *param_3,undefined8 param_4)

{
  ushort *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  bool bVar11;
  int local_res20 [2];
  uint local_58 [2];
  longlong local_50;
  undefined8 local_48 [2];
  
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  bVar5 = false;
  bVar11 = false;
  local_48[0] = 0;
  if (PepPcieLtrOverrideEnabled == '\0') {
    return;
  }
  if (param_1 != PepDripsIndex) {
    return;
  }
  lVar7 = KeQueryInterruptTimePrecise(local_48);
  lVar10 = 0;
  local_50 = lVar7;
  if (param_2 == '\0') {
    if (PepPcieLtrOverrideSkipTelemetry != (longlong *)0x0) {
      lVar10 = lVar7 - *PepPcieLtrOverrideSkipTelemetry;
    }
    for (puVar9 = PepPcieRootPortList; (undefined8 **)puVar9 != &PepPcieRootPortList;
        puVar9 = (undefined8 *)*puVar9) {
      if ((puVar9[9] != 0) &&
         (lVar7 = *(longlong *)(*(longlong *)(puVar9[9] + 0x30) + 0x10), lVar7 != 0)) {
        if (PepPcieLtrOverrideSkipTelemetry == (longlong *)0x0) {
LAB_14000fa96:
          if (*(char *)(lVar7 + 0x78) == '\0') goto LAB_14000fa9c;
        }
        else {
          if (*(char *)(lVar7 + 0x78) == '\0') {
            if (*(int *)(lVar7 + 0x98) != 0) goto LAB_14000fa27;
            bVar11 = true;
          }
          else {
            bVar11 = DAT_140086f10 == 0;
LAB_14000fa27:
            if (!bVar11) goto LAB_14000fa96;
          }
          local_res20[0] = 0;
          param_3 = local_58;
          local_58[0] = 0;
          uVar8 = PepPcieGetLightestEndPointConstraint((longlong)puVar9,local_res20,param_3);
          if ((-1 < (int)uVar8) && (local_res20[0] == 1)) {
            if (local_58[0] == 0) {
              bVar5 = true;
            }
            else {
              bVar3 = bVar4;
              if (local_58[0] == 1) {
                bVar3 = true;
                bVar4 = true;
              }
            }
          }
          if (*(char *)(lVar7 + 0x78) == '\0') {
            if ((*(uint *)(lVar7 + 0x74) & 4) != 0) {
              bVar2 = true;
            }
LAB_14000fa9c:
            if (*(int *)(lVar7 + 0x98) != 0) {
              PepPcieLtrApplyRootPortOverride((ushort *)puVar9[9],'\0');
            }
          }
        }
      }
    }
    if (DAT_140086f10 != 0) {
      PepPcieLtrApplyGlobalRootPortOverride
                ((int *)&PepPcieLtrGlobalOverrideContext,'\0',param_3,param_4);
    }
    plVar6 = PepPcieLtrOverrideSkipTelemetry;
    if (PepPcieLtrOverrideSkipTelemetry == (longlong *)0x0) {
      return;
    }
    if (bVar2) {
      *(int *)(PepPcieLtrOverrideSkipTelemetry + 6) = (int)PepPcieLtrOverrideSkipTelemetry[6] + 1;
      plVar6[3] = plVar6[3] + lVar10;
    }
    if (bVar3) {
      *(int *)(plVar6 + 5) = (int)plVar6[5] + 1;
      plVar6[1] = plVar6[1] + lVar10;
    }
    if (bVar5) {
      *(int *)((longlong)plVar6 + 0x2c) = *(int *)((longlong)plVar6 + 0x2c) + 1;
      plVar6[2] = plVar6[2] + lVar10;
    }
    if (((bVar2) || (bVar3)) || (bVar5)) {
      *(int *)((longlong)plVar6 + 0x34) = *(int *)((longlong)plVar6 + 0x34) + 1;
      plVar6[4] = plVar6[4] + lVar10;
    }
    lVar7 = local_50;
  }
  else {
    bVar11 = true;
    puVar9 = PepPcieRootPortList;
    if ((undefined8 **)PepPcieRootPortList != &PepPcieRootPortList) {
      do {
        puVar1 = (ushort *)puVar9[9];
        if ((puVar1 != (ushort *)0x0) && (*(longlong *)(*(longlong *)(puVar1 + 0x18) + 0x10) != 0))
        {
          if (*(char *)(*(longlong *)(*(longlong *)(puVar1 + 0x18) + 0x10) + 0x78) == '\0') {
            if ((*(int *)(puVar9 + 10) - 2U < 3) ||
               (*(int *)((longlong)puVar9 + 0x54) - 1U < 0xfffffffe)) {
              PepPcieLtrApplyRootPortOverride(puVar1,param_2);
            }
          }
          else if ((2 < *(int *)(puVar9 + 10) - 2U) &&
                  ((*(int *)((longlong)puVar9 + 0x54) + 1U & 0xfffffffe) == 0)) {
            bVar11 = false;
          }
        }
        puVar9 = (undefined8 *)*puVar9;
      } while ((undefined8 **)puVar9 != &PepPcieRootPortList);
      if (!bVar11) goto LAB_14000fb25;
    }
    PepPcieLtrApplyGlobalRootPortOverride
              ((int *)&PepPcieLtrGlobalOverrideContext,param_2,param_3,param_4);
  }
LAB_14000fb25:
  if (PepPcieLtrOverrideSkipTelemetry != (longlong *)0x0) {
    *PepPcieLtrOverrideSkipTelemetry = lVar7;
  }
  return;
}



===== PepPcieLtrApplyRootPortOverride @ 14000fb54 =====

void PepPcieLtrApplyRootPortOverride(ushort *param_1,char param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint local_res8 [4];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x18) + 0x10);
  if (puVar1 == (undefined8 *)0x0) {
    return;
  }
  if ((*(char *)((longlong)puVar1 + 0x79) != '\0') &&
     (PepPciePchLtrOvrMboxDisabledBootSession != '\0')) {
    return;
  }
  if (param_2 == '\0') {
    local_res20 = (ulonglong)*(uint *)(puVar1 + 0xe);
    puVar5 = param_1;
    uVar4 = PepPcieReadWriteLtrOverride(param_1,param_1,puVar1,1,1,(uint *)&local_res20,2);
    if ((int)uVar4 < 0) {
      return;
    }
    local_res18[0] = *(uint *)(puVar1 + 0xe);
    uVar7 = 0;
    local_res20 = CONCAT44(local_res20._4_4_,*(undefined4 *)((longlong)puVar1 + 0x74));
    uVar4 = PepPcieReadWriteLtrOverride(puVar5,param_1,puVar1,1,2,(uint *)&local_res20,2);
    if ((int)uVar4 < 0) {
      return;
    }
    local_res8[0] = *(uint *)((longlong)puVar1 + 0x74);
    *(undefined4 *)(puVar1 + 0x13) = 0;
  }
  else {
    uVar7 = 0;
    puVar5 = param_1;
    puVar6 = puVar1;
    uVar4 = PepPcieReadWriteLtrOverride(param_1,param_1,puVar1,0,2,(uint *)&local_res20,1);
    if ((int)uVar4 < 0) {
      return;
    }
    if ((local_res20 & 4) != 0) {
      *(undefined4 *)(puVar1 + 0x13) = 0;
      PepDiagLogPchLtrRegReadOnly(param_1,&local_res20,puVar6,uVar7);
      return;
    }
    uVar2 = (uint)local_res20;
    *(uint *)((longlong)puVar1 + 0x74) = (uint)local_res20;
    uVar4 = PepPcieReadWriteLtrOverride(puVar5,param_1,puVar1,0,1,(uint *)&local_res20,1);
    if ((int)uVar4 < 0) {
      return;
    }
    uVar3 = (uint)local_res20;
    local_res8[0] = uVar2 | 0xb;
    *(uint *)(puVar1 + 0xe) = (uint)local_res20;
    local_res20 = CONCAT44(local_res20._4_4_,uVar2) | 0xb;
    uVar4 = PepPcieReadWriteLtrOverride(puVar5,param_1,puVar1,1,2,(uint *)&local_res20,1);
    if ((int)uVar4 < 0) {
      return;
    }
    local_res18[0] = uVar3 & 0x7fff7fff;
    uVar7 = 0;
    local_res20 = CONCAT44(local_res20._4_4_,uVar3) & 0xffffffff7fff7fff;
    uVar4 = PepPcieReadWriteLtrOverride(puVar5,param_1,puVar1,1,1,(uint *)&local_res20,1);
    if ((int)uVar4 < 0) {
      return;
    }
    *(undefined4 *)(puVar1 + 0x13) = 1;
  }
  PepDiagLogLtrOverrideRegisters
            (param_1,local_res18,local_res8,CONCAT71((int7)((ulonglong)uVar7 >> 8),param_2));
  return;
}



===== PepPciePostPchLtrOvrMailbox @ 14000fd28 =====

undefined8
PepPciePostPchLtrOvrMailbox(longlong param_1,int param_2,int param_3,uint *param_4,uint param_5)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulonglong *puVar10;
  uint *puVar11;
  uint local_res8 [2];
  ulonglong local_48 [2];
  
  local_48[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x90);
  if (lVar1 == 0) {
    local_res8[0] = 0;
    goto LAB_14000fecc;
  }
  puVar11 = param_4;
  PepReadRegisterWithBus((int *)(lVar1 + 0x48),0,(uint *)local_48);
  iVar7 = 0;
  while (uVar9 = (uint)local_48[0], (int)(uint)local_48[0] < 0) {
    if (iVar7 == 3) {
      local_res8[0] = 1;
      goto LAB_14000fecc;
    }
    KeStallExecutionProcessor(10);
    PepReadRegisterWithBus((int *)(lVar1 + 0x48),0,(uint *)local_48);
    iVar7 = iVar7 + 1;
  }
  uVar2 = 0xaa000000;
  if (param_2 == 0) {
    if (param_3 == 1) {
      uVar3 = *(undefined4 *)(param_1 + 0x80);
LAB_14000fde4:
      local_48[0] = CONCAT44(local_48[0]._4_4_,uVar3);
    }
    else if (param_3 == 2) {
      uVar3 = *(undefined4 *)(param_1 + 0x84);
      goto LAB_14000fde4;
    }
    PepWriteRegisterWithBus((int *)(lVar1 + 0xb8),0,local_48);
LAB_14000fdf9:
    uVar8 = uVar2;
  }
  else {
    if (param_2 != 1) goto LAB_14000fdf9;
    uVar8 = 0xaa010000;
    if (param_3 == 1) {
      uVar3 = *(undefined4 *)(param_1 + 0x80);
    }
    else {
      uVar2 = 0xaa010000;
      if (param_3 != 2) goto LAB_14000fdf9;
      uVar3 = *(undefined4 *)(param_1 + 0x84);
    }
    local_48[0] = CONCAT44(local_48[0]._4_4_,uVar3);
    PepWriteRegisterWithBus((int *)(lVar1 + 0xb8),0,local_48);
    PepWriteRegisterWithBus((int *)(lVar1 + 0xf0),0,(undefined8 *)param_4);
  }
  puVar10 = local_48;
  local_48[0] = (ulonglong)uVar8;
  uVar6 = 0;
  PepWriteRegisterWithBus((int *)(lVar1 + 0x10),0,puVar10);
  iVar7 = 0;
  while ((int)uVar9 < 0) {
    if (iVar7 == 1000) {
      PepDiagLogPchLtrMbTimeout(param_5,uVar6,puVar10,puVar11);
      PepSubsystemInvalidSessionBitMask = PepSubsystemInvalidSessionBitMask | 8;
      PepPciePchLtrOvrMboxDisabledBootSession = 1;
      local_res8[0] = 2;
      goto LAB_14000fecc;
    }
    KeStallExecutionProcessor(100);
    puVar10 = local_48;
    uVar6 = 0;
    PepReadRegisterWithBus((int *)(lVar1 + 0x48),0,(uint *)puVar10);
    iVar7 = iVar7 + 1;
    uVar9 = (uint)local_48[0];
  }
  if ((uVar9 >> 0x1e & 1) == 0) {
    if (param_2 == 0) {
      PepReadRegisterWithBus((int *)(lVar1 + 0x80),0,param_4);
    }
    uVar5 = 0;
    do {
      uVar4 = uVar5;
      if (8 < (uint)uVar4) {
        return 0;
      }
      uVar5 = (ulonglong)((uint)uVar4 + 1);
    } while (((ulonglong)(uint)(iVar7 * 100) <
              (ulonglong)(&PepPcieLtrOvrMbResponseHistogramUs)[uVar4]) ||
            ((ulonglong)(&PepPcieLtrOvrMbResponseHistogramUs)[uVar5] <=
             (ulonglong)(uint)(iVar7 * 100)));
    if (param_5 == 1) {
      (&PepPcieLtrOvrMbEnterResponseBuckets)[uVar4] =
           (&PepPcieLtrOvrMbEnterResponseBuckets)[uVar4] + 1;
    }
    else if (param_5 == 2) {
      (&PepPcieLtrOvrMbExitResponseBuckets)[uVar4] =
           (&PepPcieLtrOvrMbExitResponseBuckets)[uVar4] + 1;
    }
    return 0;
  }
  local_res8[0] = 3;
LAB_14000fecc:
  PepDiagPostPchLtrMailboxFailure(local_res8,0xc0000001);
  return 0xc0000001;
}



===== PepPcieReadWriteLtrOverride @ 14000ff60 =====

ulonglong PepPcieReadWriteLtrOverride
                    (undefined8 param_1,ushort *param_2,undefined8 *param_3,int param_4,uint param_5
                    ,uint *param_6,uint param_7)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((((param_2 == (ushort *)0x0) || (*(longlong **)(param_2 + 0x18) == (longlong *)0x0)) ||
      (lVar2 = **(longlong **)(param_2 + 0x18), lVar2 == 0)) ||
     (lVar2 = *(longlong *)(lVar2 + 0x28), lVar2 == 0)) {
    DbgPrintEx(0x92,0,"INTELPEP: %s: invalid registration info!\n","PepPcieReadWriteLtrOverride");
    return 0xc000000d;
  }
  uVar1 = *(uint *)(lVar2 + 0x34);
  if ((*(char *)((longlong)param_3 + 0x79) != '\0') && (PepPciePchLtrOvrMboxEnabled != '\0')) {
    uVar4 = (ulonglong)param_5;
    puVar5 = param_6;
    uVar3 = PepPciePostPchLtrOvrMailbox((longlong)param_3,param_4,param_5,param_6,param_7);
    if ((int)uVar3 < 0) {
      *(undefined4 *)(param_3 + 0x13) = 0;
      PepDiagLogPchLtrMailboxFailure(param_2,(undefined8 *)param_6,uVar4,puVar5);
      return 0xc0000001;
    }
    return uVar3 & 0xffffffff;
  }
  if (param_5 == 1) {
    local_48 = *param_3;
    uStack_40 = param_3[1];
    local_38 = param_3[2];
    uStack_30 = param_3[3];
    uVar6 = *(undefined4 *)(param_3 + 4);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0x24);
    uVar8 = *(undefined4 *)(param_3 + 5);
    uVar9 = *(undefined4 *)((longlong)param_3 + 0x2c);
    uVar10 = (undefined4)param_3[6];
    uVar11 = (undefined4)((ulonglong)param_3[6] >> 0x20);
  }
  else {
    if (param_5 != 2) goto LAB_14001006c;
    local_48 = param_3[7];
    uStack_40 = param_3[8];
    local_38 = param_3[9];
    uStack_30 = param_3[10];
    uVar6 = *(undefined4 *)(param_3 + 0xb);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0x5c);
    uVar8 = *(undefined4 *)(param_3 + 0xc);
    uVar9 = *(undefined4 *)((longlong)param_3 + 100);
    uVar10 = (undefined4)param_3[0xd];
    uVar11 = (undefined4)((ulonglong)param_3[0xd] >> 0x20);
  }
  local_18 = CONCAT44(uVar11,uVar10);
  local_28 = CONCAT44(uVar7,uVar6);
  uStack_20 = CONCAT44(uVar9,uVar8);
LAB_14001006c:
  if (param_4 == 0) {
    PepReadRegisterWithBus((int *)&local_48,(ulonglong)uVar1,param_6);
  }
  else if (param_4 == 1) {
    PepWriteRegisterWithBus((int *)&local_48,uVar1,(undefined8 *)param_6);
  }
  return 0;
}



===== Feature_IntelAdlNSupport__private_IsEnabledPreCheck @ 1400100dc =====

undefined8 Feature_IntelAdlNSupport__private_IsEnabledPreCheck(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  if ((Feature_IntelAdlNSupport__private_featureState & 0x10) == 0) {
    uVar1 = Feature_IntelAdlNSupport__private_featureState | 1;
    local_res8 = (ulonglong)uVar1;
    wil_details_FeatureReporting_ReportUsageToService(0x140033198,local_res8,3);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar1,3,&Feature_IntelAdlNSupport__private_descriptor);
  }
  return 1;
}



===== PepSubsystemDetectLtrStatusReportingRequired @ 140010144 =====

void PepSubsystemDetectLtrStatusReportingRequired(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong local_res8;
  
  local_res8 = 0;
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = 0;
  if (PepSubsystemSoCInfo == (int *)0x0) {
    if (Pepv2SubsystemSocInfo == (int *)0x0) goto LAB_1400101ca;
    iVar4 = *Pepv2SubsystemSocInfo;
    iVar5 = Pepv2SubsystemSocInfo[1];
    uVar1 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar1 != 0) && (*(int **)(Pepv2SubsystemSocInfo + 2) != (int *)0x0)) {
      iVar3 = **(int **)(Pepv2SubsystemSocInfo + 2);
    }
  }
  else {
    iVar4 = *PepSubsystemSoCInfo;
    iVar5 = PepSubsystemSoCInfo[1];
  }
  if ((iVar4 == 6) && (iVar5 == 0xbd)) {
    PepSubsystemLtrStatusReportingSupported = 1;
    PepSubsystemLtrSpxInfo = &PepSubsystemLnlLtrSpxInfo;
    PepSubsystemLtrSpxCount = 2;
  }
LAB_1400101ca:
  uVar1 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar1 != 0) && (iVar4 == 6)) && (iVar5 == 0xcc)) {
    PepSubsystemLtrStatusReportingSupported = 1;
    if (iVar3 == PepPantherLakePchP) {
      PepSubsystemLtrSpxInfo = &PepSubsystemPtlPLtrSpxInfo;
      PepSubsystemLtrSpxCount = 3;
    }
    else if (iVar3 == PepPantherLakePchH) {
      PepSubsystemLtrSpxInfo = &PepSubsystemPtlHLtrSpxInfo;
      PepSubsystemLtrSpxCount = 5;
    }
  }
  if (((Pepv2SubsystemSocInfo != (int *)0x0) &&
      (uVar2 = PepV2SubsystemGetLegacyLtrInfo(*(int **)(Pepv2SubsystemSocInfo + 2),&local_res8),
      -1 < (int)uVar2)) && (local_res8 != 0)) {
    PepSubsystemPchLtrStatusList = *(undefined8 *)(local_res8 + 0x58);
    PepSubsystemPchLtrStatusCount = *(undefined4 *)(local_res8 + 0x60);
  }
  return;
}



===== PepSubsystemIntcPmtAccessRequired @ 140010278 =====

void PepSubsystemIntcPmtAccessRequired(void)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  piVar1 = PepSubsystemSoCInfo;
  if ((PepSubsystemSoCInfo != (int *)0x0) ||
     (piVar1 = Pepv2SubsystemSocInfo, Pepv2SubsystemSocInfo != (int *)0x0)) {
    iVar4 = *piVar1;
    iVar3 = piVar1[1];
    if ((iVar4 == 6) && (iVar3 == 0xbd)) {
      PepIntcExclusivePmtMmioInterfaceAvailable = 1;
    }
  }
  uVar2 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar2 != 0) && (iVar4 == 6)) && (iVar3 == 0xcc)) {
    PepIntcExclusivePmtDdiInterfaceAvailable = 1;
  }
  return;
}



===== PepV2SubsystemGetLegacyLtrInfo @ 1400102e8 =====

undefined8 PepV2SubsystemGetLegacyLtrInfo(int *param_1,longlong *param_2)

{
  ulonglong uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  uint uVar4;
  
  if ((param_1 != (int *)0x0) && (param_2 != (longlong *)0x0)) {
    uVar1 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
    uVar4 = 0;
    if ((int)uVar1 == 0) {
      ppuVar2 = &PTR_TGLUY_CPU_HWID_140081090;
      do {
        ppuVar3 = ppuVar2 + -2;
        if (((*(int *)ppuVar3 == 1) && (*(int *)(ppuVar2 + -1) == 1)) &&
           ((*(int *)*ppuVar2 == 2 &&
            ((**(int **)((longlong)*ppuVar2 + 0x10) == *param_1 &&
             (*(int *)((longlong)ppuVar2 + -0xc) == 2)))))) {
LAB_1400103a2:
          *param_2 = (longlong)ppuVar3;
          return 0;
        }
        uVar4 = uVar4 + 1;
        ppuVar2 = ppuVar2 + 0x10;
      } while (uVar4 < 0xac);
    }
    else {
      ppuVar2 = &PTR_TGLUY_CPU_HWID_14007a360;
      do {
        ppuVar3 = ppuVar2 + -2;
        if ((((*(int *)ppuVar3 == 1) && (*(int *)(ppuVar2 + -1) == 1)) && (*(int *)*ppuVar2 == 2))
           && ((**(int **)((longlong)*ppuVar2 + 0x10) == *param_1 &&
               (*(int *)((longlong)ppuVar2 + -0xc) == 2)))) goto LAB_1400103a2;
        uVar4 = uVar4 + 1;
        ppuVar2 = ppuVar2 + 0x10;
      } while (uVar4 < 0xcd);
    }
  }
  return 0xc0000001;
}



===== Pepv2PrepareDynamicCounterList @ 1400103c0 =====

ulonglong Pepv2PrepareDynamicCounterList(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  bool bVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  
  puVar5 = (undefined4 *)0x0;
  uVar4 = 0xc0000001;
  local_res10[0] = 0;
  uVar2 = 0;
  local_res8[0] = 0;
  do {
    uVar3 = 1;
    do {
      if (uVar3 == 1) {
        puVar5 = &Pepv2CpuCounterIndexMap;
      }
      else if (uVar3 == 2) {
        puVar5 = &Pepv2PchCounterIndexMap;
      }
      else if (puVar5 == (undefined4 *)0x0) {
        return uVar4;
      }
      uVar1 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar1 == 0) {
        bVar6 = (uint)puVar5[uVar2] < 0xac;
      }
      else {
        bVar6 = (uint)puVar5[uVar2] < 0xcd;
      }
      if (bVar6) {
        uVar2 = Pepv2SubsystemReadStaticTable((longlong)puVar5,local_res8,local_res10);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          return uVar4;
        }
        uVar2 = (ulonglong)local_res8[0];
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 3);
    local_res8[0] = (int)uVar2 + 1;
    uVar2 = (ulonglong)local_res8[0];
  } while (local_res8[0] < 0x16);
  return 0;
}



===== Pepv2SubsystemAccountingInit @ 140010468 =====

ulonglong Pepv2SubsystemAccountingInit(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  uint local_res8 [2];
  uint local_res10 [2];
  
  local_res8[0] = 0;
  lVar4 = 0;
  uVar2 = 0xc00000bb;
  memset(&Pepv2CpuCounterIndexMap,0x7fffffff,0x58);
  memset(&Pepv2PchCounterIndexMap,0x7fffffff,0x58);
  if (PepNumPlatformStates != 0) {
    lVar4 = (ulonglong)PepDripsIndex * 0x60 + DAT_140087708;
    PepDiagLogHwDripsCounterInfo();
  }
  Pepv2SubsystemGetCounterInfo((int *)local_res8);
  if (local_res8[0] != 0) {
    PepSubsystemAccountingInfo = ExAllocatePool2(0x40,local_res8[0] * 0xd8,0x49504550);
    if (PepSubsystemAccountingInfo != 0) {
      PepSubsystemAccountingCount = local_res8[0];
      PepSubsystemAccountingHandle = ExAllocatePool2(0x40,local_res8[0] << 4,0x49504550);
      if (PepSubsystemAccountingHandle != 0) {
        uVar1 = Pepv2PrepareDynamicCounterList();
        uVar2 = uVar1 & 0xffffffff;
        if (-1 < (int)uVar1) {
          local_res10[0] = 0;
          uVar1 = 0;
          while (local_res10[0] < local_res8[0]) {
            uVar1 = PepSubsystemInitializeCounter
                              (uVar1 * 0xd8 + PepSubsystemAccountingInfo,local_res10,lVar4);
            uVar2 = uVar1 & 0xffffffff;
            if ((int)uVar1 < 0) goto LAB_1400105a3;
            local_res10[0] = local_res10[0] + 1;
            uVar1 = (ulonglong)local_res10[0];
          }
          PepSubsystemInitializeActiveCounters();
          Pepv2SubsystemReadBootTelemetry();
          if (-1 < (int)uVar2) {
            return uVar2;
          }
        }
        goto LAB_1400105a3;
      }
    }
    uVar2 = 0xc000009a;
  }
LAB_1400105a3:
  if (PepSubsystemAccountingInfo != 0) {
    if (PepSubsystemAccountingHandle != 0) {
      if (local_res8[0] != 0) {
        uVar1 = 0;
        uVar3 = 0;
        do {
          lVar4 = uVar1 * 0xd8 + PepSubsystemAccountingInfo;
          if ((*(int *)(lVar4 + 0x14) == 3) && (*(longlong *)(lVar4 + 200) != 0)) {
            ExFreePoolWithTag(*(longlong *)(lVar4 + 200),0x49504550);
            *(undefined8 *)(lVar4 + 200) = 0;
          }
          uVar3 = uVar3 + 1;
          uVar1 = (ulonglong)uVar3;
        } while (uVar3 < local_res8[0]);
      }
      ExFreePoolWithTag(PepSubsystemAccountingHandle,0x49504550);
      PepSubsystemAccountingHandle = 0;
    }
    ExFreePoolWithTag(PepSubsystemAccountingInfo,0x49504550);
    PepSubsystemAccountingInfo = 0;
    PepSubsystemAccountingCount = 0;
  }
  return uVar2;
}



===== Pepv2SubsystemCntrDependencyNotResolved @ 140010670 =====

undefined8 Pepv2SubsystemCntrDependencyNotResolved(longlong param_1)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  uint *puVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 *puVar10;
  
  puVar10 = (undefined4 *)0x0;
  uVar9 = 0;
  uVar7 = 1;
  do {
    uVar8 = 1;
    do {
      uVar3 = uVar8 - 1;
      ppuVar5 = (undefined **)(ulonglong)uVar3;
      if (uVar3 == 0) {
        puVar10 = &Pepv2CpuCounterIndexMap;
      }
      else if (uVar3 == 1) {
        puVar10 = &Pepv2PchCounterIndexMap;
      }
      else if (puVar10 == (undefined4 *)0x0) goto LAB_140010744;
      uVar3 = puVar10[uVar9];
      if (uVar3 < 0x16) {
        uVar4 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
        ppuVar5 = &PTR_CntrDependencyNone_14007a398;
        if ((int)uVar4 == 0) {
          ppuVar5 = &PTR_CntrDependencyNone_1400810c8;
        }
        puVar6 = (uint *)ppuVar5[(ulonglong)uVar3 * 0x10];
        if (puVar6 == (uint *)0x0) goto LAB_140010744;
        ppuVar5 = (undefined **)&DAT_14007a3a0;
        if ((int)uVar4 == 0) {
          ppuVar5 = (undefined **)&DAT_1400810d0;
        }
        ppuVar1 = ppuVar5 + (ulonglong)uVar3 * 0x10;
        uVar3 = 0;
        if (*(uint *)ppuVar1 != 0) {
          do {
            uVar2 = *puVar6;
            ppuVar5 = (undefined **)(longlong)(int)uVar2;
            if (((uVar2 < 0x16) && (uVar2 != 0x15)) &&
               (*(char *)((longlong)ppuVar5 + param_1) == '\0')) goto LAB_140010744;
            uVar3 = uVar3 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar3 < *(uint *)ppuVar1);
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 3);
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar8;
  } while (uVar8 < 0x16);
  uVar7 = 0;
LAB_140010744:
  return CONCAT71((int7)((ulonglong)ppuVar5 >> 8),uVar7);
}



===== Pepv2SubsystemDiscoverExtraSocComponents @ 140010768 =====

uint Pepv2SubsystemDiscoverExtraSocComponents(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  if (Pepv2SubsystemSocInfo == (int *)0x0) {
    uVar1 = 0xc000000d;
  }
  else if ((*Pepv2SubsystemSocInfo == 6) && (Pepv2SubsystemSocInfo[1] == 0xc6)) {
    puVar3 = &PepSubsystemMeteorLakeBusRegister;
    _local_res8 = CONCAT44((int)((ulonglong)param_1 >> 0x20),0x1f);
    PepSubsystemPchBusNumberRegister = &PepSubsystemMeteorLakeBusRegister;
    uVar1 = PepValidateAndInitAddress((int *)&PepSubsystemMeteorLakeBusRegister);
    if ((int)uVar1 < 0) {
      pcVar4 = "INTELPEP: ERROR: Initializing PCH Bus Number address failed with Status: 0x%x\n";
    }
    else {
      uVar2 = Pepv2SubsystemReadPchSBusNumberHw();
      uVar1 = (uint)uVar2;
      if ((int)uVar1 < 0) {
        pcVar4 = "INTELPEP: ERROR: Reading PCH Bus Number address failed with Status: 0x%x\n";
      }
      else {
        uVar2 = PepSubsystemGetDiscretePchDeviceId(puVar3,&local_res8,&PepSubsystemDiscretePchId);
        uVar1 = (uint)uVar2;
        if ((int)uVar1 < 0) {
          pcVar4 = "INTELPEP: ERROR: Geting discrete PCH Device ID failed with Status: 0x%x\n";
        }
        else {
          PepSubsystemDiscretePchId = PepSubsystemDiscretePchId & 0xff80ffff;
          uVar2 = PepPcieUpdateDiscreteBdfRange(PepSubsystemDiscretePchId);
          uVar1 = (uint)uVar2;
          if (-1 < (int)uVar1) {
            return 0;
          }
          pcVar4 = 
          "INTELPEP: ERROR: Updating discrete PCH Bdf range table failed with Status: 0x%x\n";
        }
      }
    }
    DbgPrintEx(0x92,0,pcVar4,uVar1);
  }
  else {
    uVar1 = 0xc00000c0;
  }
  return uVar1;
}



===== Pepv2SubsystemGetCounterInfo @ 140010850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400108ac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pepv2SubsystemGetCounterInfo(int *param_1)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined7 uVar11;
  ulonglong uVar10;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined1 auStack_a8 [48];
  byte local_78;
  char local_77;
  uint local_74;
  int local_70;
  uint local_6c;
  int *local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined2 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar13 = 0;
  local_74 = 0;
  bVar2 = false;
  local_70 = 0;
  local_78 = 0;
  local_77 = '\0';
  local_60 = param_1;
  if (Pepv2SubsystemAccountingEnabled == '\0') goto LAB_140010d77;
  puVar12 = (uint *)cpuid_Version_info(1);
  uVar14 = *puVar12;
  local_6c = uVar14 >> 8 & 0xf;
  uVar15 = uVar14 >> 4 & 0xf;
  if (local_6c == 0xf) {
    local_6c = (uVar14 >> 0x14 & 0xff) + 0xf;
LAB_1400108df:
    uVar15 = uVar15 | uVar14 >> 0xc & 0xf0;
  }
  else if (local_6c == 6) goto LAB_1400108df;
  uVar14 = local_6c;
  uVar10 = (ulonglong)uVar15;
  local_38 = 0;
  puVar9 = (undefined *)(ulonglong)local_6c;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar7 = PepSubsystemGetPchDeviceId(local_6c,uVar15,&local_74);
  if ((int)uVar7 < 0) goto LAB_140010d77;
  local_74 = local_74 & 0xff80ffff;
  Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  uVar3 = local_74;
  if (uVar14 == 6) {
    if (uVar15 == 0x8c) {
      if (((PepSubsystemEnableTigerLakeHAccounting == '\0') && (local_74 == PepTigerLakePchH)) ||
         ((PepSubsystemEnableTigerLakeLPAccounting == '\0' && (local_74 == PepTigerLakePchLp))))
      goto LAB_140010d77;
      puVar9 = &PepSubsystemLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0xa7) {
      if (uVar3 != PepTigerLakePchH) goto LAB_140010b4b;
      if (PepSubsystemEnableRocketLakeSAccounting == '\0') goto LAB_140010d77;
    }
    if (uVar15 == 0x9c) {
      if (uVar3 != PepJasperLakePch) goto LAB_140010b4b;
      if (PepSubsystemEnableJasperLakeAccounting == '\0') goto LAB_140010d77;
    }
    if (uVar15 == 0x97) {
      puVar9 = &PepSubsystemAdlLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemAdlLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemAdlLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0x9a) {
      puVar9 = &PepSubsystemLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0xba) {
      puVar9 = &PepSubsystemLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0xb7) {
      puVar9 = &PepSubsystemLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0xbe) {
      Feature_IntelAdlNSupport__private_IsEnabledPreCheck();
      puVar9 = &PepSubsystemAdlLPMEnableRegister;
      uVar6 = PepSubsystemGetLPMConfig
                        ((int *)&PepSubsystemAdlLPMEnableRegister,uVar10,
                         (int *)&PepSubsystemAdlLPMPriorityRegister);
      if ((int)uVar6 < 0) goto LAB_140010d77;
    }
    if (uVar15 == 0xaa) {
      if (PepSubsystemEnableMetorLakeAccounting != '\0') goto LAB_140010b4b;
      if (uVar3 == PepMeteorLakePch) goto LAB_140010d77;
    }
    if (uVar15 == 0xbd) {
      if ((PepSubsystemEnableLunarLakeAccounting == '\0') && (uVar3 == PepLunarLakePch))
      goto LAB_140010d77;
      _CpuPkgCHwDripsBlockersIndex = 0;
      PTR_CpuPkgCHwDripsBlockersIndex_140059960 = &CpuPkgCHwDripsBlockersIndex;
      PTR_PlatformHwDripsBlockersIndex_140061568 = &PlatformHwDripsBlockersIndex;
      _DAT_140086b3c = 2;
      _DAT_140086b40 = 0xe;
      _CpuPkgCHwDripsBlockers = 3;
      _PlatformHwDripsBlockersIndex = 0xf;
      _DAT_140086a04 = 0x10;
      _PlatformHwDripsBlockers = 2;
    }
    else if (uVar15 == 0xc6) {
      if ((PepSubsystemEnableArrowLakeSAccounting == '\0') && (uVar3 == PepMeteorLakeSocS))
      goto LAB_140010d77;
      PepSubsystemPchBusNumberRegister = &PepSubsystemMeteorLakeBusRegister;
    }
  }
LAB_140010b4b:
  uVar8 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar8 != 0) && (uVar14 == 6)) && (uVar15 == 0xcc)) {
    _CpuPkgCHwDripsBlockersIndex = 0;
    _DAT_140086b3c = 2;
    _DAT_140086b40 = 0xe;
    _CpuPkgCHwDripsBlockers = 3;
    PTR_CpuPkgCHwDripsBlockersIndex_140059960 = &CpuPkgCHwDripsBlockersIndex;
    _PlatformHwDripsBlockersIndex = 0xf;
    _DAT_140086a04 = 0x10;
    _PlatformHwDripsBlockers = 2;
    PTR_PlatformHwDripsBlockersIndex_140061568 = &PlatformHwDripsBlockersIndex;
  }
  uVar8 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  uVar14 = 0;
  if ((int)uVar8 != 0) {
    puVar12 = &DAT_14007a354;
LAB_140010cc2:
    cVar5 = Pepv2SubsystemIsHardwareErrataRequired
                      (puVar9,uVar10,(int *)&local_74,(int *)(puVar12 + -1));
    if (cVar5 != '\0') goto LAB_140010d41;
    if (puVar12[1] == 1) {
      puVar9 = *(undefined **)(puVar12 + 3);
      puVar1 = *(uint **)(puVar9 + 8);
      if (puVar1 != (uint *)0x0) {
        puVar9 = (undefined *)(ulonglong)local_6c;
        if ((local_6c == *puVar1) && (uVar15 == puVar1[1])) {
          puVar9 = (undefined *)(longlong)(int)*puVar12;
          if (0x15 < *puVar12) {
            local_78 = 1;
            bVar2 = true;
            goto LAB_140010d22;
          }
          if ((&Pepv2CpuCounterIndexMap)[(longlong)puVar9] == -1) {
            local_78 = 1;
            bVar2 = true;
            (&Pepv2CpuCounterIndexMap)[(longlong)puVar9] = uVar14;
            goto LAB_140010d1d;
          }
          goto LAB_140010d77;
        }
        goto LAB_140010d1d;
      }
      if ((*(uint **)(puVar9 + 0x10) == (uint *)0x0) || (uVar3 != **(uint **)(puVar9 + 0x10)))
      goto LAB_140010d1d;
      uVar6 = *puVar12;
      if ((&Pepv2PchCounterIndexMap)[(int)uVar6] != -1) goto LAB_140010d77;
      local_77 = '\x01';
      bVar2 = true;
      if (uVar6 < 0x16) {
        (&Pepv2PchCounterIndexMap)[(int)uVar6] = uVar14;
      }
    }
    else {
LAB_140010d1d:
      if (!bVar2) goto LAB_140010d41;
    }
LAB_140010d22:
    if (*puVar12 < 0x16) {
      *(undefined1 *)((longlong)&local_48 + (longlong)(int)*puVar12) = 1;
      if (*(longlong *)(puVar12 + 0x15) != 0) {
        local_70 = local_70 + puVar12[0x17];
      }
      bVar2 = false;
    }
LAB_140010d41:
    uVar14 = uVar14 + 1;
    puVar12 = puVar12 + 0x20;
    if (0xcc < uVar14) goto code_r0x000140010d55;
    goto LAB_140010cc2;
  }
  puVar12 = &DAT_140081084;
  do {
    cVar5 = Pepv2SubsystemIsHardwareErrataRequired
                      (puVar9,uVar10,(int *)&local_74,(int *)(puVar12 + -1));
    uVar11 = (undefined7)(uVar10 >> 8);
    if (cVar5 == '\0') {
      if (puVar12[1] == 1) {
        puVar9 = *(undefined **)(puVar12 + 3);
        puVar1 = *(uint **)(puVar9 + 8);
        if (puVar1 != (uint *)0x0) {
          puVar9 = (undefined *)(ulonglong)local_6c;
          if ((local_6c != *puVar1) || (uVar15 != puVar1[1])) goto LAB_140010c76;
          puVar9 = (undefined *)(longlong)(int)*puVar12;
          if (0x15 < *puVar12) {
            bVar2 = true;
            local_78 = 1;
            uVar10 = CONCAT71(uVar11,1);
            goto LAB_140010c7e;
          }
          if ((&Pepv2CpuCounterIndexMap)[(longlong)puVar9] == -1) {
            uVar10 = CONCAT71(uVar11,1);
            (&Pepv2CpuCounterIndexMap)[(longlong)puVar9] = uVar14;
            local_78 = 1;
            bVar2 = true;
            goto LAB_140010c79;
          }
          goto LAB_140010d77;
        }
        if ((*(uint **)(puVar9 + 0x10) == (uint *)0x0) || (uVar3 != **(uint **)(puVar9 + 0x10)))
        goto LAB_140010c76;
        uVar6 = *puVar12;
        if ((&Pepv2PchCounterIndexMap)[(int)uVar6] != -1) goto LAB_140010d77;
        uVar10 = CONCAT71(uVar11,local_78);
        bVar2 = true;
        local_77 = '\x01';
        if (uVar6 < 0x16) {
          (&Pepv2PchCounterIndexMap)[(int)uVar6] = uVar14;
        }
      }
      else {
LAB_140010c76:
        uVar10 = CONCAT71(uVar11,local_78);
LAB_140010c79:
        if (!bVar2) goto LAB_140010ca2;
      }
LAB_140010c7e:
      if (*puVar12 < 0x16) {
        *(undefined1 *)((longlong)&local_48 + (longlong)(int)*puVar12) = 1;
        if (*(longlong *)(puVar12 + 0x15) != 0) {
          local_70 = local_70 + puVar12[0x17];
        }
        bVar2 = false;
      }
    }
    else {
      uVar10 = CONCAT71(uVar11,local_78);
    }
LAB_140010ca2:
    uVar14 = uVar14 + 1;
    puVar12 = puVar12 + 0x20;
  } while (uVar14 < 0xac);
  goto LAB_140010d58;
code_r0x000140010d55:
  uVar10 = (ulonglong)local_78;
LAB_140010d58:
  iVar4 = local_70;
  if (((local_70 != 0) && ((char)uVar10 != '\0')) && (local_77 != '\0')) {
    uVar7 = Pepv2SubsystemCntrDependencyNotResolved((longlong)&local_48);
    iVar13 = 0;
    if ((char)uVar7 == '\0') {
      iVar13 = iVar4;
    }
  }
LAB_140010d77:
  *local_60 = iVar13;
  return;
}



===== Pepv2SubsystemIdentifySoC @ 140010e00 =====

void Pepv2SubsystemIdentifySoC(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  
  if (((param_1 != (int *)0x0) && (uVar2 = 0, param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) {
    piVar3 = &DAT_140080f54;
    do {
      if (((*param_1 == piVar3[-1]) && (*param_2 == *piVar3)) &&
         (*param_3 == **(int **)(piVar3 + 1))) {
        Pepv2SubsystemSocInfo = &Pepv2SubsystemSocList + uVar2 * 4;
        Pepv2SubsystemDiscoverExtraSocComponents(&Pepv2SubsystemSocList);
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      piVar3 = piVar3 + 4;
    } while (uVar1 < 0x13);
  }
  return;
}



===== Pepv2SubsystemIsHardwareErrataRequired @ 140010ea0 =====

undefined1
Pepv2SubsystemIsHardwareErrataRequired
          (undefined8 param_1,undefined8 param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((PepSubsystemVelocityErrataCounter != 0) &&
     (iVar1 = *param_3, iVar1 == *(int *)(PepSubsystemVelocityErrataCounter + 8))) {
    if ((iVar1 == PepRaptorLakePchS) && ((param_4[1] - 2U & 0xfffffff7) == 0)) {
      uVar2 = 0;
      if (*(int *)(PepSubsystemVelocityErrataCounter + 0xc) == *param_4) {
        uVar2 = 1;
      }
    }
    if ((((iVar1 == PepAlderLakePchP) && ((uint)param_4[1] < 0xb)) &&
        ((0x424U >> (param_4[1] & 0x1fU) & 1) != 0)) &&
       (*(int *)(PepSubsystemVelocityErrataCounter + 0xc) == *param_4)) {
      uVar2 = 1;
    }
    if (((iVar1 == PepAlderLakePchS) && (param_4[1] == 10)) &&
       (*(int *)(PepSubsystemVelocityErrataCounter + 0xc) == *param_4)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== Pepv2SubsystemReadPchSBusNumberHw @ 140010f34 =====

undefined8 Pepv2SubsystemReadPchSBusNumberHw(void)

{
  int *piVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 local_res10 [3];
  
  piVar1 = PepSubsystemPchBusNumberRegister;
  uVar2 = 0xc00000ef;
  local_res10[0] = 0;
  if (PepSubsystemPchBusNumberRegister != (int *)0x0) {
    PepReadRegisterWithBus(PepSubsystemPchBusNumberRegister,0,(uint *)local_res10);
    DbgPrintEx(0x92,3,"INTELPEP: INFO: PCH Bus Number read returned :0x%llx\n",local_res10[0]);
    if (piVar1[3] == 1) {
      if ((uint)local_res10[0] < 0x100) {
        PepSubsystemPchBusNumber = (uint)local_res10[0];
        return 0;
      }
      uVar2 = 0xc0000001;
      pcVar3 = "INTELPEP: Error: Unexpected PCH Bus Number number.\n";
    }
    else {
      uVar2 = 0xc00000e5;
      pcVar3 = "INTELPEP: Error: Unexpected PCH Bus Number access size.\n";
    }
    DbgPrintEx(0x92,0,pcVar3);
  }
  return uVar2;
}



===== Pepv2SubsystemReadStaticTable @ 140010fe8 =====

undefined8 Pepv2SubsystemReadStaticTable(longlong param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined *puVar10;
  undefined **ppuVar11;
  undefined8 *puVar12;
  uint uVar13;
  undefined *puVar14;
  int *piVar15;
  int *piVar16;
  undefined4 *puVar17;
  undefined **ppuVar18;
  undefined **ppuVar19;
  uint *puVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  uint local_res10;
  longlong *local_res20;
  uint *local_b8;
  int *local_a8;
  undefined **local_a0;
  int *local_98;
  undefined **local_90;
  uint *local_88;
  int *local_80;
  longlong *local_78;
  uint *local_70;
  undefined *local_60;
  undefined *local_58;
  undefined8 uStack_50;
  longlong local_48 [2];
  
  local_60 = (undefined *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  puVar21 = (undefined8 *)0x0;
  puVar22 = (undefined8 *)0x0;
  local_58 = (undefined *)0x0;
  uStack_50 = 0;
  if (0x15 < *param_2) {
    return 0xc0000001;
  }
  uVar13 = *(uint *)(param_1 + (ulonglong)*param_2 * 4);
  uVar9 = (ulonglong)uVar13;
  uVar7 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    if (0xab < uVar13) {
      return 0xc0000001;
    }
    lVar8 = uVar9 * 0x80;
    local_b8 = (uint *)(&DAT_1400810f0 + lVar8);
    local_88 = (uint *)(&DAT_1400810c0 + lVar8);
    local_80 = (int *)(&DAT_1400810e4 + lVar8);
    local_98 = (int *)(&DAT_1400810b0 + lVar8);
    local_res20 = (longlong *)(&DAT_1400810a8 + lVar8);
    local_90 = &PTR_PkgCResidencySharedData_1400810b8 + uVar9 * 0x10;
    local_a0 = &PTR_Pepv2AddressDescriptor_1400810a0 + uVar9 * 0x10;
    local_70 = &DAT_1400810e0 + uVar9 * 0x20;
    local_78 = (longlong *)(&DAT_1400810e8 + lVar8);
    local_a8 = (int *)(&DAT_140081098 + lVar8);
    puVar17 = &DAT_140081084;
    puVar14 = &DAT_1400810d4;
    ppuVar11 = &PTR_Pepv2PkgCResidencyCtrList_1400810d8;
  }
  else {
    if (0xcc < uVar13) {
      return 0xc0000001;
    }
    lVar8 = uVar9 * 0x80;
    local_b8 = (uint *)(&DAT_14007a3c0 + lVar8);
    puVar17 = &DAT_14007a354;
    local_70 = &DAT_14007a3b0 + uVar9 * 0x20;
    local_78 = (longlong *)(&DAT_14007a3b8 + lVar8);
    puVar14 = &DAT_14007a3a4;
    local_80 = (int *)(&DAT_14007a3b4 + lVar8);
    local_88 = (uint *)(&DAT_14007a390 + lVar8);
    local_90 = &PTR_PkgCResidencySharedData_14007a388 + uVar9 * 0x10;
    local_98 = (int *)(&DAT_14007a380 + lVar8);
    local_res20 = (longlong *)(&DAT_14007a378 + lVar8);
    local_a0 = &PTR_Pepv2AddressDescriptor_14007a370 + uVar9 * 0x10;
    local_a8 = (int *)(&DAT_14007a368 + lVar8);
    ppuVar11 = &PTR_Pepv2PkgCResidencyCtrList_14007a3a8;
  }
  piVar15 = (int *)(puVar14 + uVar9 * 0x80);
  ppuVar18 = (undefined **)(puVar17 + uVar9 * 0x20);
  ppuVar11 = ppuVar11 + uVar9 * 0x10;
  if (*piVar15 == 1) {
    puVar14 = *ppuVar11;
    puVar10 = puVar14;
  }
  else {
    if (*piVar15 != 0x10) {
      return 0;
    }
    local_60 = *ppuVar11;
    puVar14 = (undefined *)0x0;
    puVar10 = local_60;
  }
  if (puVar10 == (undefined *)0x0) {
    return 0xc0000001;
  }
  uVar7 = 0;
  local_res10 = 0;
  if (*local_70 != 0) {
    puVar20 = local_70;
    do {
      puVar12 = (undefined8 *)((ulonglong)*param_3 * 0xd8 + PepSubsystemAccountingInfo);
      if (PepSubsystemAccountingCount < *param_3) {
        return 0xc0000001;
      }
      *(int *)((longlong)puVar12 + 0x14) = *(int *)ppuVar18;
      ppuVar19 = ppuVar18;
      if (*piVar15 == 1) {
        puVar21 = (undefined8 *)(puVar14 + uVar7 * 0x28);
        if (puVar21 == (undefined8 *)0x0) {
          return 0xc0000001;
        }
        *puVar12 = *puVar21;
        puVar12[1] = puVar21[1];
        *(undefined4 *)(puVar12 + 2) = *(undefined4 *)(puVar21 + 2);
        puVar12[3] = puVar21[4];
        uVar9 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar9 != 0) {
          *(undefined4 *)(puVar12 + 0x1a) = 0;
        }
      }
      if (*piVar15 == 0x10) {
        puVar22 = (undefined8 *)(local_60 + uVar7 * 0x30);
        if (puVar22 == (undefined8 *)0x0) {
          return 0xc0000001;
        }
        *puVar12 = *puVar22;
        puVar12[1] = puVar22[1];
        *(undefined4 *)(puVar12 + 2) = *(undefined4 *)(puVar22 + 2);
        puVar12[3] = puVar22[5];
        uVar9 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar9 != 0) {
          *(undefined4 *)(puVar12 + 0x1a) = 0;
        }
      }
      if (*local_a8 == 1) {
        ppuVar11 = (undefined **)*local_a0;
        *(undefined4 *)(puVar12 + 6) = 0xffffffff;
        *(undefined4 *)((longlong)puVar12 + 0x3c) = 0xffffffff;
        *(undefined4 *)(puVar12 + 0x11) = 0xffffffff;
        *(undefined4 *)((longlong)puVar12 + 0x94) = 0xffffffff;
        if (ppuVar11 != (undefined **)0x0) {
          puVar10 = *ppuVar11;
          ppuVar19 = ppuVar11 + 1;
          if (puVar10 != (undefined *)0x0) {
            if (*ppuVar19 == (undefined *)0x0) {
              if (*piVar15 == 1) {
                *(undefined8 *)(puVar10 + 0x28) = puVar21[3];
                puVar10 = *ppuVar11;
              }
              else if (*piVar15 != 0x10) {
                return 0xc0000001;
              }
              if (*piVar15 == 0x10) {
                *(undefined4 *)(puVar10 + 0x10) = *(undefined4 *)((longlong)puVar22 + 0x14);
                *(undefined4 *)(*ppuVar11 + 0x14) = *(undefined4 *)(puVar22 + 3);
                *(undefined4 *)(*ppuVar11 + 0x18) = *(undefined4 *)((longlong)puVar22 + 0x1c);
                *(undefined4 *)(*ppuVar11 + 0x1c) = *(undefined4 *)(puVar22 + 4);
                *(undefined4 *)(*ppuVar11 + 0x20) = *(undefined4 *)((longlong)puVar22 + 0x24);
              }
            }
            puVar2 = (undefined8 *)*ppuVar11;
            uVar4 = puVar2[1];
            puVar12[6] = *puVar2;
            puVar12[7] = uVar4;
            uVar4 = puVar2[3];
            puVar12[8] = puVar2[2];
            puVar12[9] = uVar4;
            uVar4 = puVar2[5];
            puVar12[10] = puVar2[4];
            puVar12[0xb] = uVar4;
            puVar12[0xc] = puVar2[6];
          }
          if (*ppuVar19 != (undefined *)0x0) {
            puVar12[0x18] = puVar21[3];
            puVar2 = (undefined8 *)*ppuVar19;
            uVar4 = puVar2[1];
            puVar12[0x11] = *puVar2;
            puVar12[0x12] = uVar4;
            uVar4 = puVar2[3];
            puVar12[0x13] = puVar2[2];
            puVar12[0x14] = uVar4;
            uVar4 = puVar2[5];
            puVar12[0x15] = puVar2[4];
            puVar12[0x16] = uVar4;
            puVar12[0x17] = puVar2[6];
          }
        }
      }
      if (*local_res20 != 0) {
        if (*(int *)ppuVar18 == 5) {
          PepSubsystemEnergyReportingContext = *local_res20;
          PepSubsystemEvaluateEnergyReporting
                    (local_res20,ppuVar11,(char *)ppuVar19,(ulonglong)puVar20);
        }
        if ((*(int *)ppuVar18 == 2) &&
           (puVar2 = (undefined8 *)*local_res20, puVar2 != (undefined8 *)0x0)) {
          PepSubsystemLtrSpxInfo = *puVar2;
          PepSubsystemLtrSpxCount = *(undefined4 *)(puVar2 + 1);
        }
      }
      if (*local_98 == 1) {
        puVar10 = *local_90;
        if ((puVar10 != (undefined *)0x0) && (uVar7 = 0, *local_88 != 0)) {
          do {
            piVar16 = (int *)(puVar10 + uVar7 * 0x10);
            if (piVar16 == (int *)0x0) {
              return 0xc0000001;
            }
            iVar1 = *piVar16;
            if (iVar1 == 0) {
              if (*(undefined8 **)(piVar16 + 2) != (undefined8 *)0x0) {
                puVar12[5] = **(undefined8 **)(piVar16 + 2);
              }
            }
            else if (iVar1 == 1) {
              if (*(longlong **)(piVar16 + 2) != (longlong *)0x0) {
                PepSubsystemEvaluateLpitOverride(*(longlong **)(piVar16 + 2));
              }
            }
            else if (iVar1 == 2) {
              if ((*(int *)((longlong)puVar12 + 0x14) == 2) ||
                 (*(int *)((longlong)puVar12 + 0x14) == 0x10)) {
                PepSubsystemOrignalPkgCStateThreshold = *(undefined8 *)(piVar16 + 2);
                PepSubsystemPkgCStateThreshold = PepSubsystemOrignalPkgCStateThreshold;
              }
            }
            else if (iVar1 == 3) {
              if (((*(int *)((longlong)puVar12 + 0x14) == 2) ||
                  (*(int *)((longlong)puVar12 + 0x14) == 0x10)) &&
                 (*(undefined8 **)(piVar16 + 2) != (undefined8 *)0x0)) {
                PepSubsystemLtrBlockingThreshold = **(undefined8 **)(piVar16 + 2);
              }
            }
            else if (iVar1 == 4) {
              PepSubsystemCtaSignature = *(undefined8 *)(piVar16 + 2);
            }
            else if (iVar1 == 5) {
              puVar2 = *(undefined8 **)(piVar16 + 2);
              if (puVar2 != (undefined8 *)0x0) {
                uVar4 = puVar2[1];
                puVar12[8] = *puVar2;
                puVar12[9] = uVar4;
                *(undefined4 *)(puVar12 + 10) = *(undefined4 *)(puVar2 + 2);
              }
            }
            else if (((iVar1 == 6) &&
                     (uVar9 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline
                                        (), (int)uVar9 != 0)) &&
                    (*(undefined4 **)(piVar16 + 2) != (undefined4 *)0x0)) {
              *(undefined4 *)(puVar12 + 0x1a) = **(undefined4 **)(piVar16 + 2);
            }
            uVar13 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar13;
          } while (uVar13 < *local_88);
        }
        uVar7 = (ulonglong)local_res10;
      }
      uVar13 = (uint)uVar7;
      if (((*local_80 == 1) && (puVar2 = (undefined8 *)*local_78, puVar2 != (undefined8 *)0x0)) &&
         (uVar7 = 0, *local_b8 != 0)) {
        do {
          puVar3 = puVar2 + uVar7 * 3;
          if (puVar3 != (undefined8 *)0x0) {
            RtlInitUnicodeString(local_48,*puVar12);
            RtlInitUnicodeString(&local_58,*puVar2);
            ppuVar11 = &local_58;
            cVar6 = RtlEqualUnicodeString(local_48,ppuVar11,1);
            if (cVar6 != '\0') {
              iVar1 = *(int *)(puVar3 + 1);
              if (iVar1 == 0) {
                if ((undefined8 *)puVar3[2] != (undefined8 *)0x0) {
                  puVar12[5] = *(undefined8 *)puVar3[2];
                }
              }
              else if (iVar1 == 1) {
                if ((undefined4 *)puVar3[2] != (undefined4 *)0x0) {
                  *(undefined4 *)(puVar12 + 2) = *(undefined4 *)puVar3[2];
                }
              }
              else if (iVar1 == 2) {
                if (((undefined8 *)puVar3[2] != (undefined8 *)0x0) &&
                   (puVar12 != (undefined8 *)0xffffffffffffffd0)) {
                  puVar12[0xb] = *(undefined8 *)puVar3[2];
                }
              }
              else if ((iVar1 == 3) &&
                      (ppuVar11 = (undefined **)puVar3[2], ppuVar11 != (undefined **)0x0)) {
                puVar3 = (undefined8 *)*ppuVar11;
                if (puVar3 != (undefined8 *)0x0) {
                  uVar5 = puVar3[1];
                  uVar4 = puVar12[0xb];
                  puVar12[6] = *puVar3;
                  puVar12[7] = uVar5;
                  uVar5 = puVar3[3];
                  puVar12[8] = puVar3[2];
                  puVar12[9] = uVar5;
                  uVar5 = puVar3[5];
                  puVar12[10] = puVar3[4];
                  puVar12[0xb] = uVar5;
                  puVar12[0xc] = puVar3[6];
                  puVar12[0xb] = uVar4;
                }
                puVar3 = (undefined8 *)ppuVar11[1];
                if (puVar3 != (undefined8 *)0x0) {
                  uVar4 = puVar3[1];
                  puVar12[0x11] = *puVar3;
                  puVar12[0x12] = uVar4;
                  uVar4 = puVar3[3];
                  puVar12[0x13] = puVar3[2];
                  puVar12[0x14] = uVar4;
                  uVar4 = puVar3[5];
                  puVar12[0x15] = puVar3[4];
                  puVar12[0x16] = uVar4;
                  puVar12[0x17] = puVar3[6];
                }
              }
            }
          }
          uVar13 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar13;
        } while (uVar13 < *local_b8);
        uVar13 = local_res10;
      }
      local_res10 = uVar13 + 1;
      uVar7 = (ulonglong)local_res10;
      *param_3 = *param_3 + 1;
    } while (local_res10 < *local_70);
  }
  return 0;
}



===== FxStubDriverUnloadCommon @ 14001174c =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_140087cc0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140011790 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400117c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140087cc0 = 0x2080000;
    _DAT_140087cc8 = &DAT_140087aa0;
    RtlCopyUnicodeString(&DAT_140087cc0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140087cc0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140087ca8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140087cc0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400876d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 140011950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140087ca8 != (code *)0x0) && (DAT_140087ca8 != FxStubDriverUnload)) {
    (*DAT_140087ca8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140011984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400119a9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x1400876cf < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1400876d8 = (undefined *)puVar2;
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
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 140011ae4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400876d8 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1400876d8 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 140011ba0 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 140011be8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140011c05) */
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
    if ((void **)0x1400876ef < ppvVar2) break;
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



===== InitializeTelemetryAssertsKMByDriverObject @ 140011cb0 =====

ulonglong InitializeTelemetryAssertsKMByDriverObject(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_48,0);
    uVar3 = IoQueryFullDriverPath(param_1,&local_48);
    if (-1 < (int)uVar3) {
      uVar2 = RtlUnicodeStringToAnsiString(&local_38,&local_48,1);
      uVar3 = (ulonglong)uVar2;
      ExFreePoolWithTag(uStack_40,0);
      if (-1 < (int)uVar2) {
        uVar2 = (uint)(ushort)local_38;
        do {
          uVar1 = uVar2;
          uVar2 = uVar1 - 1;
          if (uVar2 == 0) goto LAB_140011d8e;
        } while (*(char *)((ulonglong)uVar2 + lStack_30) != '\\');
        if (uVar2 != (ushort)local_38) {
          local_28 = 0;
          uStack_20 = 0;
          RtlInitAnsiString(&local_28,(ulonglong)uVar1 + lStack_30);
          local_18 = local_28;
          uStack_10 = uStack_20;
          uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
          uVar3 = uVar3 & 0xffffffff;
        }
LAB_140011d8e:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140011db4 =====

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
    _DAT_140087ce8 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14008d040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14008d008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14008d078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140011e68 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,"intelpep.sys",param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredMsgKM @ 140011e9c =====

void MicrosoftTelemetryAssertTriggeredMsgKM(char *param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,param_1)
  ;
  return;
}



===== MicrosoftTelemetryAssertTriggeredNoArgsKM @ 140011ecc =====

void MicrosoftTelemetryAssertTriggeredNoArgsKM(void)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,(char *)0x0);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140011efc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400120b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  char *pcVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  char *pcVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined1 *puVar18;
  uint uVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  undefined4 uVar22;
  undefined1 auStack_1c8 [8];
  undefined1 auStack_1c0 [112];
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148 [2];
  char *local_140;
  char *local_138;
  undefined1 local_128 [32];
  undefined4 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  longlong local_c8 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  longlong local_88 [2];
  undefined1 *local_78;
  ulonglong local_70;
  undefined1 *local_68;
  ulonglong local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
  puVar18 = auStack_1c8;
  local_48 = __security_cookie ^ (ulonglong)auStack_1c8;
  uVar19 = 0;
  local_138 = param_6;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400126c8;
  local_150 = param_2;
  local_14c = param_4;
  local_140 = param_3;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar18 = auStack_1c8;
  puVar13 = &g_MicrosoftTelemetryAssertsTriggeredList;
  do {
    puVar13 = (undefined8 *)*puVar13;
    if ((longlong **)puVar13 == &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
      lVar3 = _DAT_fffff78000000320;
      puVar18 = auStack_1c8;
      if (plVar9 == (longlong *)0x0) goto LAB_1400126b2;
      *plVar9 = (longlong)param_1;
      uVar7 = KeQueryTimeIncrement();
      puVar18 = auStack_1c8;
      plVar9[2] = 0;
      *(undefined4 *)(plVar9 + 3) = 0;
      plVar9[1] = (longlong)((ulonglong)uVar7 * lVar3) / 10000 + -0xea61;
      plVar10 = plVar9 + 4;
      plVar14 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        plVar14 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        plVar10 = (longlong *)(*pcVar2)();
        puVar18 = auStack_1c0;
      }
      *plVar10 = (longlong)plVar14;
      plVar10[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
      plVar14[1] = (longlong)plVar10;
      g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
      break;
    }
    plVar9 = puVar13 + -4;
  } while ((IMAGE_DOS_HEADER *)*plVar9 != param_1);
  *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
  *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
  lVar3 = _DAT_fffff78000000320;
  *(undefined8 *)(puVar18 + -8) = 0x14001204c;
  uVar7 = KeQueryTimeIncrement();
  lVar3 = (longlong)((ulonglong)uVar7 * lVar3) / 10000;
  if (60000 < (ulonglong)(lVar3 - plVar9[1])) {
    if (((IMAGE_DOS_HEADER *)0x13fffffff < param_1) && (param_1 < (IMAGE_DOS_HEADER *)0x1400a4001))
    {
      uVar19 = (int)param_1 + 0xc0000000;
    }
    uVar1 = (undefined4)plVar9[2];
    *(undefined4 *)(puVar18 + 0x70) = *(undefined4 *)((longlong)plVar9 + 0x14);
    plVar9[1] = lVar3;
    *(int *)(puVar18 + 0x6c) = (int)plVar9[3];
    *(undefined8 *)(puVar18 + -8) = 0x1400120fa;
    KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar4));
    uVar21 = 0;
    pcVar12 = local_140;
    if (local_140 == (char *)0x0) {
      pcVar12 = g_ModuleName;
    }
    uVar22 = 10;
    local_140 = pcVar12;
    if (*(int *)(puVar18 + 0x78) == 0) {
      if (5 < DAT_14008d040) {
        *(undefined8 *)(puVar18 + -8) = 0x1400122b0;
        pcVar12 = g_ModuleName;
        uVar11 = _tlgKeywordOn(0x14008d040,0x400000000000);
        if ((char)uVar11 != '\0') {
          local_108 = (undefined4 *)(puVar18 + 100);
          *(undefined4 *)(puVar18 + 100) = uVar22;
          local_f8 = puVar18 + 0x60;
          local_100 = 4;
          local_e8 = puVar18 + 0x5c;
          *(uint *)(puVar18 + 0x60) = uVar19;
          local_d8 = puVar18 + 0x58;
          local_f0 = 4;
          pcVar17 = "<unknown>";
          if (pcVar12 != (char *)0x0) {
            pcVar17 = pcVar12;
          }
          *(dword *)(puVar18 + 0x5c) = 0xa284c1cb;
          local_e0 = 4;
          *(dword *)(puVar18 + 0x58) = 0xa4000;
          local_d0 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x140012321;
          _tlgCreate1Sz_char(local_c8,pcVar17);
          local_b8 = puVar18 + 0x54;
          *(undefined4 *)(puVar18 + 0x54) = uVar1;
          *(undefined4 *)(puVar18 + 0x50) = *(undefined4 *)(puVar18 + 0x70);
          local_a8 = puVar18 + 0x50;
          local_b0 = 4;
          local_a0 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x140012357;
          bVar5 = KeGetCurrentIrql();
          uVar20 = 4;
          *(uint *)(puVar18 + 0x68) = (uint)bVar5;
          local_98 = puVar18 + 0x68;
          local_90 = 4;
          pcVar12 = local_138;
          if (local_138 == (char *)0x0) {
            pcVar12 = "<unknown>";
          }
          *(undefined8 *)(puVar18 + -8) = 0x140012391;
          _tlgCreate1Sz_char(local_88,pcVar12);
          *(undefined1 **)(puVar18 + 0x28) = local_128;
          pbVar16 = &DAT_140030ccc;
          *(undefined4 *)(puVar18 + 0x20) = 0xb;
          goto LAB_1400123a9;
        }
      }
    }
    else if (5 < DAT_14008d040) {
      *(undefined8 *)(puVar18 + -8) = 0x140012151;
      pcVar17 = g_ModuleName;
      uVar11 = _tlgKeywordOn(0x14008d040,0x400000000000);
      if ((char)uVar11 != '\0') {
        local_108 = local_148;
        local_f8 = puVar18 + 0x74;
        local_100 = 4;
        local_e8 = puVar18 + 0x68;
        local_148[0] = uVar22;
        *(uint *)(puVar18 + 0x74) = uVar19;
        local_d8 = puVar18 + 0x50;
        local_f0 = 4;
        pcVar15 = "<unknown>";
        if (pcVar17 != (char *)0x0) {
          pcVar15 = pcVar17;
        }
        *(dword *)(puVar18 + 0x68) = 0xa284c1cb;
        local_e0 = 4;
        *(dword *)(puVar18 + 0x50) = 0xa4000;
        local_d0 = 4;
        *(undefined8 *)(puVar18 + -8) = 0x1400121c0;
        _tlgCreate1Sz_char(local_c8,pcVar15);
        local_b8 = puVar18 + 0x54;
        *(undefined4 *)(puVar18 + 0x54) = uVar1;
        *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x70);
        local_a8 = puVar18 + 0x58;
        local_b0 = 4;
        local_a0 = 4;
        *(undefined8 *)(puVar18 + -8) = 0x1400121f6;
        bVar5 = KeGetCurrentIrql();
        uVar20 = 4;
        *(uint *)(puVar18 + 0x5c) = (uint)bVar5;
        local_98 = puVar18 + 0x5c;
        local_90 = 4;
        *(undefined8 *)(puVar18 + -8) = 0x140012225;
        _tlgCreate1Sz_char(local_88,pcVar12);
        local_78 = puVar18 + 0x60;
        *(undefined4 *)(puVar18 + 100) = param_5;
        local_68 = puVar18 + 100;
        *(undefined4 *)(puVar18 + 0x60) = *(undefined4 *)(puVar18 + 0x7c);
        local_70 = uVar20 & 0xffffffff;
        pcVar12 = local_138;
        if (local_138 == (char *)0x0) {
          pcVar12 = "<unknown>";
        }
        local_60 = uVar20 & 0xffffffff;
        *(undefined8 *)(puVar18 + -8) = 0x140012270;
        _tlgCreate1Sz_char(local_58,pcVar12);
        *(undefined1 **)(puVar18 + 0x28) = local_128;
        pbVar16 = &DAT_140030c22;
        *(undefined4 *)(puVar18 + 0x20) = 0xe;
LAB_1400123a9:
        *(undefined8 *)(puVar18 + -8) = 0x1400123b5;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x14008d040,pbVar16,uVar20,uVar21,*(undefined4 *)(puVar18 + 0x20),
                   *(undefined8 **)(puVar18 + 0x28));
      }
    }
    if ((DAT_14008d078 == 0) || (*(int *)(puVar18 + 0x6c) != 0)) goto LAB_1400126c8;
    *(undefined8 *)(puVar18 + -8) = 0x1400123d4;
    cVar6 = KeGetCurrentIrql();
    if (cVar6 != '\0') goto LAB_1400126c8;
    *(undefined4 *)(puVar18 + 0x40) = 0;
    *(undefined8 *)(puVar18 + 0x38) = 0;
    *(undefined8 *)(puVar18 + 0x30) = 0;
    *(undefined8 *)(puVar18 + 0x28) = 0xa4000;
    *(undefined8 *)(puVar18 + 0x20) = 0xa284c1cb;
    uVar20 = (ulonglong)uVar19;
    *(undefined8 *)(puVar18 + -8) = 0x14001241e;
    iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
    uVar21 = 0;
    if (*(int *)(puVar18 + 0x78) == 0) {
      if (5 < DAT_14008d040) {
        *(undefined8 *)(puVar18 + -8) = 0x140012598;
        uVar11 = _tlgKeywordOn(0x14008d040,0x400000000000);
        if ((char)uVar11 != '\0') {
          local_108 = (undefined4 *)(puVar18 + 0x6c);
          *(undefined4 *)(puVar18 + 0x6c) = 10;
          local_f8 = puVar18 + 100;
          local_100 = 4;
          local_e8 = puVar18 + 0x60;
          local_d8 = puVar18 + 0x5c;
          *(uint *)(puVar18 + 100) = uVar19;
          local_f0 = 4;
          pcVar12 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar12 = g_ModuleName;
          }
          *(dword *)(puVar18 + 0x60) = 0xa284c1cb;
          local_e0 = 4;
          *(dword *)(puVar18 + 0x5c) = 0xa4000;
          local_d0 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x140012613;
          _tlgCreate1Sz_char(local_c8,pcVar12);
          local_b8 = puVar18 + 0x58;
          *(undefined4 *)(puVar18 + 0x58) = uVar1;
          pbVar16 = &DAT_140030ddf;
          *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x70);
          local_a8 = puVar18 + 0x54;
          local_98 = puVar18 + 0x50;
          *(undefined1 **)(puVar18 + 0x28) = local_128;
          *(undefined4 *)(puVar18 + 0x20) = 10;
          local_b0 = 4;
          local_a0 = 4;
          *(int *)(puVar18 + 0x50) = iVar8;
          local_90 = 4;
          goto LAB_140012670;
        }
      }
    }
    else if (5 < DAT_14008d040) {
      *(undefined8 *)(puVar18 + -8) = 0x140012457;
      uVar11 = _tlgKeywordOn(0x14008d040,0x400000000000);
      if ((char)uVar11 != '\0') {
        local_108 = (undefined4 *)(puVar18 + 0x6c);
        *(undefined4 *)(puVar18 + 0x6c) = 10;
        local_f8 = puVar18 + 100;
        local_100 = 4;
        local_e8 = puVar18 + 0x60;
        local_d8 = puVar18 + 0x5c;
        *(uint *)(puVar18 + 100) = uVar19;
        local_f0 = 4;
        pcVar12 = "<unknown>";
        if (g_ModuleName != (char *)0x0) {
          pcVar12 = g_ModuleName;
        }
        *(dword *)(puVar18 + 0x60) = 0xa284c1cb;
        local_e0 = 4;
        *(dword *)(puVar18 + 0x5c) = 0xa4000;
        local_d0 = 4;
        *(undefined8 *)(puVar18 + -8) = 0x1400124d2;
        _tlgCreate1Sz_char(local_c8,pcVar12);
        local_b8 = puVar18 + 0x58;
        *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x70);
        local_a8 = puVar18 + 0x54;
        local_98 = puVar18 + 0x50;
        *(undefined4 *)(puVar18 + 0x58) = uVar1;
        local_b0 = 4;
        local_a0 = 4;
        *(int *)(puVar18 + 0x50) = iVar8;
        local_90 = 4;
        *(undefined8 *)(puVar18 + -8) = 0x140012524;
        _tlgCreate1Sz_char(local_88,local_140);
        pbVar16 = &DAT_140030d39;
        *(undefined4 *)(puVar18 + 0x68) = *(undefined4 *)(puVar18 + 0x7c);
        local_78 = puVar18 + 0x68;
        *(undefined4 *)(puVar18 + 0x74) = param_5;
        local_68 = puVar18 + 0x74;
        *(undefined1 **)(puVar18 + 0x28) = local_128;
        *(undefined4 *)(puVar18 + 0x20) = 0xd;
        local_70 = 4;
        local_60 = 4;
LAB_140012670:
        *(undefined8 *)(puVar18 + -8) = 0x14001267c;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x14008d040,pbVar16,uVar20,uVar21,*(undefined4 *)(puVar18 + 0x20),
                   *(undefined8 **)(puVar18 + 0x28));
      }
    }
    if (iVar8 != 0) goto LAB_1400126c8;
    *(undefined8 *)(puVar18 + -8) = 0x14001268f;
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar13 = &g_MicrosoftTelemetryAssertsTriggeredList;
    do {
      puVar13 = (undefined8 *)*puVar13;
      if ((longlong **)puVar13 == &g_MicrosoftTelemetryAssertsTriggeredList) goto LAB_1400126b2;
    } while ((IMAGE_DOS_HEADER *)puVar13[-4] != param_1);
    *(int *)(puVar13 + -1) = *(int *)(puVar13 + -1) + 1;
  }
LAB_1400126b2:
  *(undefined8 *)(puVar18 + -8) = 0x1400126c3;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_1400126c8:
  *(undefined8 *)(puVar18 + -8) = 0x1400126d7;
  return;
}



===== HviIsAnyHypervisorPresent @ 1400126fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140012730) */
/* WARNING: Removing unreachable block (ram,0x00014001271f) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 140012758 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140012785) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== __GSHandlerCheck @ 1400127b8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400127dc =====

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



===== __security_check_cookie @ 140012850 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140012890 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400128c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400128c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400128f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140012940 =====

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



===== memset @ 140012c40 =====

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



===== __memset_repmovs @ 140012d80 =====

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



===== __memset_query @ 140012e00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140012e80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140012fc0 =====

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



===== __memset_spec_plain @ 140013040 =====

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



===== PepAbandonDevice @ 14008e008 =====

undefined1 PepAbandonDevice(undefined8 param_1)

{
  DbgPrintEx(0x92,3,"INTELPEP: abandon device (%wZ)\n",param_1);
  PepPcieAbandonDevice(param_1);
  if (PepPcieCollectPcieHierarchyDiagnostic != '\0') {
    PepPcieAbandonDiagDevice(param_1);
  }
  return 1;
}



===== PepPnpNotifyIntelCtaInterfaceChangeCallback @ 14008e060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepPnpNotifyIntelCtaInterfaceChangeCallback(longlong param_1)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 local_res18 [2];
  ulonglong local_68;
  code *pcStack_60;
  undefined8 local_58;
  ulonglong local_50 [5];
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_50[0] = (ulonglong)(uint)local_50[0];
  iVar3 = 0;
  local_res18[0] = 0;
  local_68 = (ulonglong)(uint)local_68;
  bVar2 = PepQueryPlatformAoAc();
  if (bVar2) {
    plVar6 = &GUID_DEVINTERFACE_LEGACY_PEP_EXCLUSIVE;
    if (PepIntcExclusivePmtMmioInterfaceAvailable == '\0') {
      plVar6 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
    }
    lVar4 = *(longlong *)(param_1 + 0x14) - *plVar6;
    if (lVar4 == 0) {
      lVar4 = *(longlong *)(param_1 + 0x1c) - plVar6[1];
    }
    if (lVar4 == 0) {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
      lVar5 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
      if (lVar5 == 0) {
        lVar5 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
      }
      if (lVar5 == 0) {
        uVar1 = **(undefined2 **)(param_1 + 0x28);
        lVar5 = ExAllocatePool2(0x100,uVar1,0x49504550);
        *(longlong *)(lVar4 + 0x28) = lVar5;
        if (lVar5 == 0) {
          iVar3 = -0x3fffff66;
        }
        else {
          *(undefined2 *)(lVar4 + 0x22) = uVar1;
          *(undefined2 *)(lVar4 + 0x20) = 0;
          RtlCopyUnicodeString((undefined2 *)(lVar4 + 0x20),*(undefined8 *)(param_1 + 0x28));
          DbgPrintEx(0x92,3,"INTELPEP: ARRIVAL of CTA reported\n");
          local_20 = 0;
          local_68 = 0x18;
          local_50[2] = 0;
          uStack_28 = 0;
          local_50[4] = PepWdfDevice;
          pcStack_60 = PepIoCtaInterfaceWorker;
          local_50[1] = 0;
          local_50[0] = 0x38;
          local_50[3] = 0x100000001;
          local_58 = 1;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                            (WdfDriverGlobals,&local_68,local_50,local_res18);
          if (-1 < iVar3) {
            *(undefined4 *)(lVar4 + 0x30) = 1;
            (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res18[0]);
          }
        }
      }
      else {
        lVar5 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4005;
        if (lVar5 == 0) {
          lVar5 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
        }
        if (lVar5 == 0) {
          DbgPrintEx(0x92,3,"INTELPEP: REMOVAL of Telemetry Aggregator reported\n");
          PepSubsystemRestorePkgCStateThreshold();
          PepSubSystemDisableCtaCounters();
          if (*(longlong *)(lVar4 + 0x28) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar4 + 0x28),0x49504550);
            *(undefined8 *)(lVar4 + 0x28) = 0;
          }
          *(undefined4 *)(lVar4 + 0x30) = 2;
        }
        else {
          iVar3 = -0x3fffff1b;
          DbgPrintEx(0x92,0,
                     "INTELPEP: Interface Change Notification-->                        Arrival unknown action\n"
                    );
        }
      }
    }
  }
  return iVar3;
}



===== PepPnpNotifyIntelCtaInterfaceChangeCallbackV1 @ 14008e2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepPnpNotifyIntelCtaInterfaceChangeCallbackV1(longlong param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  code *pcVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  ushort uVar14;
  int iVar15;
  int iVar16;
  char local_res18;
  undefined8 local_res20;
  undefined8 local_88;
  code *pcStack_80;
  ulonglong local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined *local_40;
  
  lVar7 = 0;
  local_40 = (undefined *)((ulonglong)local_40 & 0xffffffff00000000);
  local_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  local_res20 = 0;
  iVar15 = 0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  local_78 = local_78 & 0xffffffff00000000;
  local_50 = 0;
  uStack_48 = 0;
  local_res18 = '\0';
  local_88 = 0;
  pcStack_80 = (code *)0x0;
  bVar2 = PepQueryPlatformAoAc();
  if (!bVar2) {
    return 0;
  }
  plVar10 = &GUID_DEVINTERFACE_LEGACY_PEP_EXCLUSIVE;
  if (PepIntcExclusivePmtMmioInterfaceAvailable == '\0') {
    plVar10 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
  }
  if ((*(longlong *)(param_1 + 0x14) == *plVar10) && (*(longlong *)(param_1 + 0x1c) == plVar10[1]))
  {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      uVar14 = **(short **)(param_1 + 0x28) + 2;
      lVar6 = ExAllocatePool2(0x100,uVar14,0x49504550);
      *(longlong *)(lVar5 + 0x28) = lVar6;
      if (lVar6 == 0) {
        return -0x3fffff66;
      }
      *(ushort *)(lVar5 + 0x22) = uVar14;
      *(undefined2 *)(lVar5 + 0x20) = 0;
      RtlCopyUnicodeString((undefined2 *)(lVar5 + 0x20),*(undefined8 *)(param_1 + 0x28));
      *(undefined2 *)(*(longlong *)(lVar5 + 0x28) + -2 + (ulonglong)(uVar14 >> 1) * 2) = 0;
      DbgPrintEx(0x92,3,"INTELPEP: ARRIVAL of CTA reported\n");
      local_40 = (undefined *)0x0;
      local_88 = 0x18;
      local_60 = 0;
      uStack_5c = 0;
      uStack_48 = 0;
      local_50 = PepWdfDevice;
      pcStack_80 = PepIoCtaInterfaceWorkerV1;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      local_70 = 0x38;
      uStack_58 = 0x100000001;
      local_78 = 1;
      iVar15 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                         (WdfDriverGlobals,&local_88,&local_70,&local_res20);
      if (iVar15 < 0) {
        return iVar15;
      }
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48),0);
      *(undefined4 *)(lVar5 + 0x30) = 1;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48));
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res20);
      goto LAB_14008e5d1;
    }
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4005) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      DbgPrintEx(0x92,3,"INTELPEP: REMOVAL of Telemetry Aggregator reported\n");
      PepSubsystemRestorePkgCStateThreshold();
      PepSubSystemDisableCtaCounters();
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48),0);
      *(undefined4 *)(lVar5 + 0x30) = 2;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48));
      if (*(longlong *)(lVar5 + 0x28) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar5 + 0x28),0x49504550);
        *(undefined8 *)(lVar5 + 0x28) = 0;
      }
      goto LAB_14008e5d1;
    }
LAB_14008eaf1:
    iVar15 = -0x3fffff1b;
    DbgPrintEx(0x92,0,
               "INTELPEP: Interface Change Notification-->                        Arrival unknown action\n"
              );
  }
  else {
LAB_14008e5d1:
    if (*(longlong *)(param_1 + 0x14) != 0x4c595c443dfb2563) {
      return iVar15;
    }
    if (*(longlong *)(param_1 + 0x1c) != -0x4719f98215457f73) {
      return iVar15;
    }
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      iVar15 = 0;
      lVar6 = 0;
      do {
        puVar13 = (undefined8 *)(*(longlong *)(lVar5 + 0x58) + lVar6);
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*puVar13,0);
        if ((*(int *)(puVar13 + 0x15) == 0) || (*(int *)(puVar13 + 0x15) == 3)) {
          *(undefined4 *)(puVar13 + 0x15) = 1;
          lVar7 = 1;
          break;
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar13);
        iVar15 = iVar15 + 1;
        lVar6 = lVar6 + 0xc0;
      } while (iVar15 == 0);
      local_res18 = (char)lVar7;
      if (iVar15 == 1) {
        iVar15 = -0x3fffff1b;
        DbgPrintEx(0x92,0,"INTELPEP: %s: No available PMT Context!\n",
                   "PepPnpNotifyIntelCtaInterfaceChangeCallbackV1");
      }
      else {
        uVar14 = **(short **)(param_1 + 0x28) + 2;
        lVar7 = ExAllocatePool2(0x100,uVar14,0x49504550);
        puVar13[3] = lVar7;
        if (lVar7 == 0) {
          DbgPrintEx(0x92,0,"INTELPEP: Memory allocation failure for DDI symlink\n");
          iVar15 = -0x3fffff66;
        }
        else {
          *(ushort *)((longlong)puVar13 + 0x12) = uVar14;
          *(undefined2 *)(puVar13 + 2) = 0;
          RtlCopyUnicodeString(puVar13 + 2,*(undefined8 *)(param_1 + 0x28));
          *(undefined2 *)(puVar13[3] + -2 + (ulonglong)(uVar14 >> 1) * 2) = 0;
          DbgPrintEx(0x92,3,"INTELPEP: ARRIVAL of PMT using DDI reported\n");
          local_40 = PTR__WDF_PPEP_PMT_DDI_INTERFACE_TYPE_INFO_140034090;
          local_50 = PepWdfDevice;
          uStack_5c = 0;
          pcStack_80 = PepIoCtaInterfaceWorkerV1;
          uStack_6c = 0;
          uStack_68 = 0;
          uStack_64 = 0;
          local_60 = 0;
          uStack_48 = 0;
          local_70 = 0x38;
          uStack_58 = 0x100000001;
          local_88 = 0x18;
          local_78 = 1;
          iVar15 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                             (WdfDriverGlobals,&local_88,&local_70,&local_res20);
          if (-1 < iVar15) {
            puVar11 = (undefined8 *)
                      (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,local_res20,
                                 PTR__WDF_PPEP_PMT_DDI_INTERFACE_TYPE_INFO_140034090);
            *puVar11 = puVar13;
            (**(code **)(WdfFunctions_01015 + 0x9c8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48),0);
            *(int *)(lVar5 + 0x54) = *(int *)(lVar5 + 0x54) + 1;
            *(undefined4 *)(lVar5 + 0x30) = 1;
            (**(code **)(WdfFunctions_01015 + 0x9d0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48));
            *(undefined1 *)(puVar13 + 1) = 0;
            *(undefined1 *)((longlong)puVar13 + 0xac) = 0;
            pcVar9 = *(code **)(WdfFunctions_01015 + 0xbe0);
            uVar12 = local_res20;
            goto LAB_14008eabc;
          }
          DbgPrintEx(0x92,0,"INTELPEP: Failed to create work item for PMT arrival\n");
        }
      }
    }
    else {
      if ((*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4005) ||
         (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0)) goto LAB_14008eaf1;
      DbgPrintEx(0x92,0,"INTELPEP: REMOVAL of Telemetry Aggregator reported\n");
      iVar16 = 0;
      do {
        puVar13 = (undefined8 *)(*(longlong *)(lVar5 + 0x58) + lVar7);
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*puVar13,0);
        iVar3 = RtlCompareUnicodeString(puVar13 + 2,*(undefined8 *)(param_1 + 0x28));
        if (iVar3 == 0) {
          local_res18 = '\x01';
          break;
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar13);
        iVar16 = iVar16 + 1;
        lVar7 = lVar7 + 0xc0;
      } while (iVar16 == 0);
      if (iVar16 == 1) {
        iVar15 = -0x3fffff1b;
        DbgPrintEx(0x92,0,
                   "INTELPEP: Unable to find matching PMT interface                            for removal %wZ\n"
                   ,*(undefined8 *)(param_1 + 0x28));
        MicrosoftTelemetryAssertTriggeredMsgKM("Unable to find matching PMT interface for removal");
      }
      else {
        uVar8 = 0;
        puVar11 = &DAT_1400876a8;
        do {
          if (puVar13 == (undefined8 *)*puVar11) {
            (&DAT_140087650)[uVar8 * 0x78] = 0;
            if ((&DAT_140087658)[uVar8 * 0xf] != 0) {
              ExFreePoolWithTag((&DAT_140087658)[uVar8 * 0xf],0x49504550);
              (&DAT_140087658)[uVar8 * 0xf] = 0;
            }
            (&DAT_1400876a8)[uVar8 * 0xf] = 0;
            (&DAT_140087660)[uVar8 * 0x1e] = 0;
            break;
          }
          uVar4 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar4;
          puVar11 = puVar11 + 0xf;
        } while (uVar4 == 0);
        if (puVar13[3] != 0) {
          ExFreePoolWithTag(puVar13[3],0x49504550);
          puVar13[3] = 0;
        }
        if (puVar13[0x17] != 0) {
          ExFreePoolWithTag(puVar13[0x17],0x49504550);
          puVar13[0x17] = 0;
        }
        if (puVar13[0x16] != 0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
          puVar13[0x16] = 0;
        }
        *(undefined1 *)(puVar13 + 1) = 0;
        *(undefined1 *)((longlong)puVar13 + 0xac) = 0;
        *(undefined4 *)(puVar13 + 0x15) = 3;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x48),0);
        piVar1 = (int *)(lVar5 + 0x54);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined4 *)(lVar5 + 0x30) = 2;
        }
        uVar12 = *(undefined8 *)(lVar5 + 0x48);
        pcVar9 = *(code **)(WdfFunctions_01015 + 0x9d0);
LAB_14008eabc:
        (*pcVar9)(WdfDriverGlobals,uVar12);
      }
    }
    if ((local_res18 != '\0') && (puVar13 != (undefined8 *)0x0)) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar13);
    }
  }
  return iVar15;
}



===== PepRegisterIntelCtaInterfaceChange @ 14008eb34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepRegisterIntelCtaInterfaceChange(ulonglong param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulonglong local_res8;
  longlong local_res10 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar1 = PepWdfDevice;
  local_res10[1] = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (PepPlatformAoAc != '\0') {
    if (*WdfDriverGlobals != 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                        (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,local_res10);
      if (-1 < iVar2) {
        RtlInitUnicodeString(&local_18,L"EnableCtaInterface");
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))
                          (WdfDriverGlobals,local_res10[0],&local_18,&local_res8);
        if (-1 < iVar2) {
          PepEnableCtaInterface = (int)local_res8 != 0;
        }
        if (PepEnableCtaInterface != '\0') {
          puVar3 = &GUID_DEVINTERFACE_LEGACY_PEP_EXCLUSIVE;
          if (PepIntcExclusivePmtMmioInterfaceAvailable == '\0') {
            puVar3 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
          }
          IoRegisterPlugPlayNotification
                    (2,1,puVar3,PepDriverObject,PepPnpNotifyIntelCtaInterfaceChangeCallback,uVar1,
                     local_res10 + 1);
        }
      }
      if (local_res10[0] != 0) {
        (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
      }
    }
  }
  return;
}



===== PepRegisterIntelCtaInterfaceChangeV1 @ 14008ec88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepRegisterIntelCtaInterfaceChangeV1(ulonglong param_1)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong local_res8;
  longlong local_res10 [2];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  uVar1 = PepWdfDevice;
  local_res8 = param_1 & 0xffffffff00000000;
  local_res10[1] = 0;
  local_res10[0] = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_38 = local_38 & 0xffffffff00000000;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (PepPlatformAoAc == '\0') {
    return;
  }
  if (*WdfDriverGlobals == 0) {
    return;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,local_res10);
  if (iVar2 < 0) goto LAB_14008ef00;
  RtlInitUnicodeString(&local_78,L"EnableCtaInterface");
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))
                    (WdfDriverGlobals,local_res10[0],&local_78,&local_res8);
  if (iVar2 < 0) {
LAB_14008ed73:
    if (PepEnableCtaInterface == '\0') goto LAB_14008ef00;
  }
  else {
    if ((int)local_res8 == 0) {
      PepEnableCtaInterface = '\0';
      goto LAB_14008ed73;
    }
    PepEnableCtaInterface = '\x01';
  }
  if (PepIntcExclusivePmtDdiInterfaceAvailable == 0) {
    puVar7 = &GUID_DEVINTERFACE_LEGACY_PEP_EXCLUSIVE;
    if (PepIntcExclusivePmtMmioInterfaceAvailable == 0) {
      puVar7 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
    *(undefined4 *)(lVar3 + 0x54) = 0;
    _Dst = (void *)ExAllocatePool2(0x40,0xc0,0x49504550);
    *(void **)(lVar3 + 0x58) = _Dst;
    memset(_Dst,0,0xc0);
    uVar5 = 0;
    lVar6 = 0;
    do {
      local_38 = 0;
      local_58 = 0;
      uStack_60 = 0;
      local_68 = 0x38;
      uStack_40 = 0;
      uStack_50 = 0x100000001;
      local_48 = uVar1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                        (WdfDriverGlobals,&local_68,uVar5 * 0xc0 + *(longlong *)(lVar3 + 0x58));
      if (iVar2 < 0) {
        DbgPrintEx(0x92,3,"INTELPEP: WdfWaitLockCreate failed with status code 0x%x\n",iVar2);
        goto LAB_14008ef00;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      *(undefined4 *)(lVar6 + 0xa8 + *(longlong *)(lVar3 + 0x58)) = 0;
      lVar6 = lVar6 + 0xc0;
    } while (uVar4 == 0);
    *(undefined1 *)(lVar3 + 0x50) = 1;
    puVar7 = &GUID_DEVINTERFACE_PMT_TELEMETRY;
  }
  iVar2 = IoRegisterPlugPlayNotification
                    (2,1,puVar7,PepDriverObject,PepPnpNotifyIntelCtaInterfaceChangeCallbackV1,uVar1,
                     local_res10 + 1);
  if (iVar2 != 0) {
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              ((ulonglong)(uint)PepIntcExclusivePmtMmioInterfaceAvailable,
               (uint)PepIntcExclusivePmtDdiInterfaceAvailable * 2 |
               (uint)PepIntcExclusivePmtMmioInterfaceAvailable,iVar2,
               "INTELPEP: IORegisterPlugPlayNotification failed");
  }
LAB_14008ef00:
  if (local_res10[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== PepUnregisterDevice @ 14008ef44 =====

void PepUnregisterDevice(undefined4 *param_1)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  DbgPrintEx(0x92,3,"INTELPEP: unregister device (%wZ)\n",&local_18);
  if (*(char *)((longlong)param_1 + 0x19) != '\0') {
    PepUpdateNumUnregisteredDevices('\x01');
  }
  *(undefined8 *)(param_1 + 4) = 0;
  if (*(longlong *)(param_1 + 0xc) != 0) {
    PepPcieUnregisterDevice((longlong)param_1);
  }
  return;
}



===== PepWnfSleepStudySessionInfoCallback @ 14008efb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PepWnfSleepStudySessionInfoCallback(void)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38 [2];
  undefined1 local_30 [8];
  longlong local_28;
  longlong lStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_38[0] = 0x18;
  local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  iVar1 = ExQueryWnfStateData(0,local_30,&local_28,local_38);
  if (-1 < iVar1) {
    local_28 = local_28 + -0x44fd8b8ecc99192b;
    if (local_28 == 0) {
      local_28 = lStack_20 + -0x294d1b1462efa9b0;
    }
    if (local_28 == 0) {
      PepSleepStudySessionInstanceId = local_18;
      PepSleepStudySessionInProgress = 1;
    }
    else {
      PepSleepStudySessionInProgress = 0;
    }
  }
  return iVar1;
}



===== PepWnfWakeOnVoiceCallback @ 14008f060 =====

int PepWnfWakeOnVoiceCallback(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int *piVar4;
  undefined1 local_res20 [8];
  char local_18 [4];
  int local_14 [3];
  
  piVar4 = local_14;
  local_18[0] = '\0';
  pcVar3 = local_18;
  local_14[0] = 1;
  puVar2 = local_res20;
  iVar1 = ExQueryWnfStateData();
  if (-1 < iVar1) {
    if (local_14[0] == 0) {
      iVar1 = 0;
    }
    else {
      if ((PepSleepStudySessionInProgress == '\0') || (local_18[0] != '\0')) {
        PepWoVEnabled = local_18[0];
      }
      else {
        iVar1 = 0;
      }
      PepTraceWakeOnVoiceUpdate(local_18[0],puVar2,pcVar3,piVar4);
    }
  }
  return iVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14008f0d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== PepEvtDeviceAdd @ 14008f1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PepEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined8 local_res20;
  undefined8 in_stack_fffffffffffffed0;
  undefined4 uVar4;
  ulonglong local_118 [6];
  undefined *local_e8;
  ulonglong local_e0 [5];
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined4 local_a8 [10];
  code *local_80;
  
  uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);
  local_res20 = 0;
  local_118[0] = (ulonglong)(uint)local_118[0];
  local_e0[0] = (ulonglong)(uint)local_e0[0];
  local_res10 = param_2;
  memset(local_a8,0,0x90);
  local_80 = PepEvtDevicePrepareHardware;
  local_a8[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,local_a8);
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_res10,0);
  (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,local_res10);
  local_e8 = PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018;
  local_118[2] = 0;
  local_118[1] = 0;
  local_118[0] = 0x38;
  local_118[4] = 0;
  local_118[5] = 0;
  local_118[3] = 0x100000001;
  local_res18[0] = 8;
  (**(code **)(WdfFunctions_01015 + 0x248))
            (WdfDriverGlobals,local_res10,PepDbgPreprocessCallback,0x1b,local_res18,
             CONCAT44(uVar4,1));
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,local_118,&PepWdfDevice);
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,PepWdfDevice,0);
    PepDbgInitializeInterface();
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))
                      (WdfDriverGlobals,PepWdfDevice,1,0xf003f,0,&local_res20);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res20);
      uVar2 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 != 0) {
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
        local_b0 = 0;
        local_e0[2] = 0;
        local_e0[1] = 0;
        local_e0[0] = 0x38;
        uStack_b8 = 0;
        local_e0[4] = PepWdfDevice;
        local_e0[3] = 0x100000001;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,local_e0,lVar3 + 0x48);
        if (iVar1 < 0) {
          DbgPrintEx(0x92,3,"INTELPEP: WdfWaitLockCreate failed with status code 0x%x\n",iVar1);
        }
      }
    }
  }
  return iVar1;
}



===== PepEvtDevicePrepareHardware @ 14008f430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepEvtDevicePrepareHardware(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined7 extraout_var;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals);
  *puVar2 = uVar3;
  uVar1 = PepAcpiQueryDsmFunctionsSupported(puVar2,param_1);
  *(int *)(puVar2 + 1) = (int)CONCAT71(extraout_var,uVar1);
  PepRegisterPlugin(puVar2);
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14008f4ac =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_14008f509;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14008f509;
    }
  }
  uVar1 = 0x206;
LAB_14008f509:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14008f514 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_GatePerf__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &Feature_GatePerf__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14008f5cc =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14008f604 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14008f686;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14008f686;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14008f686:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14008f6d0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &Feature_GatePerf__private_descriptor;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14008f730 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14008f74c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_GatePerf__private_descriptor;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== CheckDtsAvailableRegistryEntry @ 14008f800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 CheckDtsAvailableRegistryEntry(void)

{
  int iVar1;
  undefined1 uVar2;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar2 = 0;
  local_res8[0] = 0;
  local_res10 = 0;
  local_res18[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,&local_res10);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_28,L"Parking");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                      (WdfDriverGlobals,local_res10,&local_28,0x20019,0,local_res18);
    if (iVar1 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
    }
    else {
      RtlInitUnicodeString(&local_28,L"EnableDTS");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res18[0],&local_28,local_res8);
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res18[0]);
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res10);
      if ((-1 < iVar1) && (uVar2 = 0, local_res8[0] == 1)) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



===== PepNotifyPpmQueryProvSocIdentifier @ 14008f970 =====

void PepNotifyPpmQueryProvSocIdentifier
               (undefined8 param_1,ushort *param_2,char *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (DAT_140087e58 == (void *)0x0) {
    uVar1 = PepSubsystemQueryProvSocIdentifier();
    uVar3 = (undefined4)uVar1;
    if (DAT_140087e58 == (void *)0x0) {
      param_3 = "Allocate Soc Identifier Query Failed\n";
      pvVar2 = (void *)0x2;
      DbgPrintEx(0x92);
      goto LAB_14008f9bb;
    }
  }
  if (*(void **)(param_2 + 4) == (void *)0x0) {
    *param_2 = PepSubsystemProvSocIdentifier >> 1;
    return;
  }
  if (PepSubsystemProvSocIdentifier >> 1 <= *param_2) {
    memmove(*(void **)(param_2 + 4),DAT_140087e58,(ulonglong)DAT_140087e52);
    return;
  }
  uVar3 = 0xc000000d;
  pvVar2 = DAT_140087e58;
LAB_14008f9bb:
  PepDiagLogAllocSocIdFailure(uVar3,pvVar2,param_3,param_4);
  return;
}



===== PepAcpiEmDeviceConstraintCallback @ 14008fa10 =====

undefined8
PepAcpiEmDeviceConstraintCallback
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,int param_4,int *param_5,
          int param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong local_res18;
  ulonglong local_38 [4];
  
  local_res18 = 0;
  uVar6 = 1;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if ((((param_3 != (undefined8 *)0x0) && (param_4 == 1)) && (param_5 != (int *)0x0)) &&
     ((param_6 == 2 && (PepAcpiEmDeviceList == (undefined8 *)0x0)))) {
    RtlInitAnsiString(local_38 + 2,*param_3);
    iVar1 = RtlAnsiStringToUnicodeString(local_38,local_38 + 2,1);
    if (-1 < iVar1) {
      uVar2 = RtlULongLongMult((ulonglong)PepNumPlatformStates,8,&local_res18);
      if ((-1 < (int)uVar2) && (0x37 < local_res18 + 0x38U)) {
        uVar7 = local_res18 + 0x39U & 0xfffffffffffffffe;
        uVar5 = (local_38[0] & 0xffff) + 2 + uVar7;
        if (uVar7 <= uVar5) {
          puVar3 = (undefined8 *)ExAllocatePool2(0x40,uVar5,0x49504550);
          if (puVar3 != (undefined8 *)0x0) {
            if (PepNumPlatformStates != 0) {
              uVar5 = (ulonglong)PepNumPlatformStates;
              piVar4 = (int *)(puVar3 + 7);
              do {
                piVar4[1] = *param_5;
                *piVar4 = param_5[1] + 1;
                piVar4 = piVar4 + 2;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            *(undefined2 *)(puVar3 + 3) = 0;
            puVar3[4] = puVar3 + 7;
            *puVar3 = 0;
            puVar3[1] = 0;
            *(short *)((longlong)puVar3 + 2) = (short)local_38[0] + 2;
            puVar3[1] = (longlong)puVar3 + uVar7;
            RtlCopyUnicodeString(puVar3,local_38);
            PepAcpiEmDeviceCount = 1;
            uVar6 = 2;
            PepAcpiEmDeviceList = puVar3;
          }
        }
      }
      RtlFreeUnicodeString(local_38);
    }
  }
  return uVar6;
}



===== PepAcpiQueryDsmFunctionsSupported @ 14008fbb4 =====

undefined1 PepAcpiQueryDsmFunctionsSupported(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 uVar3;
  longlong local_res10 [3];
  
  uVar3 = 0;
  local_res10[0] = 0;
  iVar2 = PepAcpiEval_DSM(param_1,param_2,0,local_res10);
  lVar1 = local_res10[0];
  if (-1 < iVar2) {
    if (*(int *)(local_res10[0] + 8) == 0) {
      DbgPrintEx(0x92,0,
                 "INTELPEP: BIOS ERROR: _DSM evaluation for with Function Index set to 0 did not return a value.\n"
                );
    }
    else if (((0x13 < *(uint *)(local_res10[0] + 4)) && (*(short *)(local_res10[0] + 0xc) == 2)) &&
            (*(short *)(local_res10[0] + 0xe) == 1)) {
      uVar3 = *(undefined1 *)(local_res10[0] + 0x10);
    }
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x49504550);
  }
  return uVar3;
}



===== PepAcpiQueryEmDeviceConstraints @ 14008fc44 =====

void PepAcpiQueryEmDeviceConstraints(void)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = EmProviderRegister(PepDriverObject,0,0,&PepAcpiEmCallbackReg,1,local_res10);
  if (-1 < iVar1) {
    local_res8[0] = 0;
    EmClientQueryRuleState(&GUID_EM_RULE_INTELPEP_ADD_DEVICE_CONSTRAINT,local_res8);
    EmProviderDeregister(local_res10[0]);
  }
  return;
}



===== PepInitializeResidencyCounters @ 14008fcc0 =====

void PepInitializeResidencyCounters(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar4 = PepGetHwResidenciesLastTransition();
  lVar5 = PepGetHwResidenciesTotal();
  uVar9 = 0;
  if (PepNumPlatformStates != 0) {
    do {
      uVar8 = (uint)uVar9;
      *(undefined4 *)(uVar4 + 4 + uVar9 * 0x10) = 0;
      *(undefined8 *)(uVar4 + 8 + uVar9 * 0x10) = 0;
      *(uint *)(uVar4 + uVar9 * 0x10) = uVar8;
      *(undefined4 *)(lVar5 + 4 + uVar9 * 0x10) = 0;
      *(undefined8 *)(lVar5 + 8 + uVar9 * 0x10) = 0;
      *(uint *)(lVar5 + uVar9 * 0x10) = uVar8;
      lVar6 = PepGetPlatformStateInfo(uVar8);
      if (*(char *)(lVar6 + 0x10) == '\0') {
        if (*(longlong *)(lVar6 + 0x18) == 0) {
          iVar2 = PepGetTscFrequencyInHz((longlong *)(lVar6 + 0x18));
          if (-1 < iVar2) goto LAB_14008fd37;
        }
        else {
LAB_14008fd37:
          uVar3 = PepValidateAndInitAddress((int *)(lVar6 + 0x20));
          if (-1 < (int)uVar3) goto LAB_14008fd48;
        }
        *(undefined1 *)(lVar6 + 0x10) = 1;
      }
LAB_14008fd48:
      uVar9 = (ulonglong)(uVar8 + 1);
    } while (uVar8 + 1 < PepNumPlatformStates);
  }
  uVar4 = (ulonglong)PepNumPlatformStates;
  uVar9 = 0;
  if (PepNumPlatformStates != 0) {
    do {
      lVar5 = PepGetPlatformStateInfo((uint)uVar9);
      iVar2 = (int)uVar9;
      *(undefined4 *)(lVar5 + 0x58) = 0;
      if (*(char *)(lVar5 + 0x10) == '\0') {
        uVar8 = 0;
        do {
          if ((uint)uVar9 != uVar8) {
            lVar6 = PepGetPlatformStateInfo(uVar8);
            uVar7 = PepResidencyCounterDuplicate(lVar5 + 0x10,lVar6 + 0x10);
            if ((char)uVar7 != '\0') {
              pbVar1 = (byte *)(lVar5 + 0x58 + ((longlong)(int)uVar8 >> 3));
              *pbVar1 = *pbVar1 | '\x01' << (uVar8 & 7);
            }
          }
          iVar2 = (int)uVar9;
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)uVar4);
      }
      uVar9 = (ulonglong)(iVar2 + 1U);
    } while (iVar2 + 1U < (uint)uVar4);
  }
  return;
}



===== PepDiagCtaInterfaceArrivalFail @ 14008fdc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagCtaInterfaceArrivalFail
               (undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 auStackY_128 [32];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8 [2];
  undefined8 local_c8 [4];
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  if ((param_1 != (undefined8 *)0x0) && (5 < DAT_1400340a0)) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_a8 = local_d8;
      local_d8[0] = 0x1000000;
      local_a0 = 8;
      _tlgCreate1Sz_wchar_t((longlong *)&local_98,(wchar_t *)*param_1);
      local_e8 = param_1[5];
      local_88 = &local_e8;
      local_ec = *(undefined4 *)(param_1 + 6);
      local_78 = &local_ec;
      local_f8 = *(undefined4 *)((longlong)param_1 + 0x34);
      local_68 = (undefined8 *)&local_f8;
      local_f4 = *(undefined4 *)(param_1 + 7);
      local_58 = &local_f4;
      local_f0 = *(undefined4 *)((longlong)param_1 + 0x3c);
      local_48 = &local_f0;
      local_e0 = param_1[0xb];
      local_38 = &local_e0;
      local_80 = 8;
      local_70 = 4;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e861,param_1,param_4,10,local_c8);
    }
  }
  if ((param_2 != 0) && (5 < DAT_1400340a0)) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_a8 = &local_e0;
      local_e0 = 0x1000000;
      local_f0 = *(undefined4 *)(param_2 + 0x14);
      local_98 = &local_f0;
      local_f4 = *(undefined4 *)(param_2 + 0x18);
      local_88 = (undefined8 *)&local_f4;
      local_f8 = *(undefined4 *)(param_2 + 4);
      local_78 = &local_f8;
      local_e8 = *(undefined8 *)(param_2 + 8);
      local_68 = &local_e8;
      local_a0 = 8;
      local_90 = 4;
      local_80 = 4;
      local_70 = 4;
      local_60 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f137,param_1,param_4,7,local_c8);
    }
  }
  return;
}



===== PepDiagInitializeProvider @ 14009000c =====

void PepDiagInitializeProvider(void)

{
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x1400340a0);
  return;
}



===== PepDiagLogAllocSocIdFailure @ 140090028 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogAllocSocIdFailure
               (undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_1400340a0) {
    local_20 = local_48;
    local_14 = 0;
    local_18 = 4;
    local_48[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002de89,param_3,param_4,3,local_40);
  }
  return;
}



===== PepDiagLogBootTelemetry @ 14009009c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogBootTelemetry(wchar_t *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_4c = 0;
      local_58 = &local_90;
      uVar2 = 8;
      local_50 = 8;
      local_90 = 0x1000000;
      _tlgCreate1Sz_wchar_t(local_48,param_1);
      local_98[0] = (undefined4)param_3;
      local_2c = 0;
      local_38 = local_88;
      local_1c = 0;
      local_28 = local_98;
      local_20 = 4;
      local_88[0] = param_2;
      local_30 = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f589,param_3,param_2,6,local_78);
    }
  }
  return;
}



===== PepDiagLogDbgPkgcCmdAccessTimeAccounting @ 14009017c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogDbgPkgcCmdAccessTimeAccounting
               (wchar_t *param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStackY_e8 [32];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8 [2];
  undefined8 local_98 [4];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar4 = *param_2;
  uVar5 = param_2[1];
  uVar1 = param_2[2];
  uVar2 = param_2[3];
  if (5 < DAT_1400340a0) {
    uVar3 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar3 != '\0') {
      _tlgCreate1Sz_wchar_t(local_78,param_1);
      local_5c = 0;
      local_68 = &local_b8;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_58 = &local_b4;
      local_48 = &local_b0;
      local_38 = &local_ac;
      local_28 = local_a8;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 8;
      local_b8 = uVar4;
      local_b4 = uVar5;
      local_b0 = uVar1;
      local_ac = uVar2;
      local_a8[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e8ff,param_3,param_1,8,local_98);
    }
  }
  return;
}



===== PepDiagLogGc2Enabled @ 140090298 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogGc2Enabled
               (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 uVar4;
  undefined7 uVar5;
  undefined1 auStackY_c8 [32];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95 [5];
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
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
  
  uVar4 = (undefined1)param_4;
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_68 = &local_90;
      local_90 = 0x1000000;
      local_98 = PepPcieGeneratedConstraintRCiEPEnabled;
      local_58 = &local_98;
      local_48 = &local_97;
      local_38 = &local_96;
      local_28 = local_95;
      local_60 = 8;
      local_50 = 1;
      local_40 = 1;
      local_30 = 1;
      local_20 = 1;
      local_97 = param_2;
      local_96 = uVar2;
      local_95[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002dc37,CONCAT71(uVar3,uVar2),CONCAT71(uVar5,uVar4),7,local_88);
    }
  }
  return;
}



===== PepDiagLogGeneratedConstraintDisabled @ 140090390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogGeneratedConstraintDisabled(longlong param_1)

{
  undefined8 uVar1;
  byte *pbVar2;
  undefined8 uVar3;
  undefined1 auStackY_188 [32];
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined1 local_158 [4];
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148 [2];
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128 [2];
  undefined8 local_118 [4];
  undefined8 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_188;
  uVar3 = 0;
  if (param_1 == 0) {
    if (DAT_1400340a0 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_48 = &local_140;
    local_140 = 0x1000000;
    pbVar2 = &DAT_14002e432;
    local_38 = local_158;
    local_40 = 8;
    local_28 = &local_154;
    puVar5 = local_68;
    uVar4 = 5;
    local_158[0] = (undefined1)uVar3;
    local_30 = 1;
    local_20 = 4;
  }
  else {
    if (DAT_1400340a0 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_f8 = &local_138;
    local_138 = 0x1000000;
    pbVar2 = &DAT_14002f1d0;
    local_e8 = local_158;
    local_f0 = 8;
    local_d8 = &local_154;
    local_130 = *(undefined8 *)(param_1 + 8);
    local_c8 = &local_130;
    local_150 = *(undefined4 *)(param_1 + 0x10);
    local_b8 = &local_150;
    local_14c = *(undefined4 *)(param_1 + 0x14);
    local_a8 = &local_14c;
    local_148[0] = *(undefined4 *)(param_1 + 0x18);
    local_98 = local_148;
    local_140 = CONCAT44(local_140._4_4_,*(undefined4 *)(param_1 + 0x1c));
    local_88 = &local_140;
    local_128[0] = *(undefined8 *)(param_1 + 0x38);
    local_78 = local_128;
    puVar5 = local_118;
    uVar4 = 0xb;
    local_158[0] = (undefined1)uVar3;
    local_e0 = 1;
    local_d0 = 4;
    local_c0 = 8;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 4;
    local_80 = 4;
    local_70 = 8;
  }
  local_154 = PepNumPlatformStates;
  _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,pbVar2,param_1,uVar3,uVar4,puVar5);
  return;
}



===== PepDiagLogGeneratedConstraintEnabled @ 1400905a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogGeneratedConstraintEnabled
               (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined7 uVar2;
  undefined1 auStackY_a8 [32];
  undefined1 local_78;
  undefined1 local_77 [7];
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_48 = &local_70;
      local_70 = 0x1000000;
      local_78 = PepPcieGeneratedConstraintEnabled;
      local_38 = &local_78;
      local_28 = local_77;
      local_40 = 8;
      local_30 = 1;
      local_20 = 1;
      local_77[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_140030a2a,CONCAT71(uVar2,param_2),param_4,5,local_68);
    }
  }
  return;
}



===== PepDiagLogHardwareFailedToRespond @ 14009066c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogHardwareFailedToRespond(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStackY_e8 [32];
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  undefined1 local_b5 [5];
  undefined8 local_b0;
  undefined8 local_a8 [2];
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar3 = (ulonglong)(PepSubsystemInvalidSessionBitMask & 1);
  uVar4 = PepSubsystemInvalidSessionBitMask & 2;
  uVar5 = PepSubsystemInvalidSessionBitMask & 4;
  uVar2 = (ulonglong)(PepSubsystemInvalidSessionBitMask & 8);
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_b7 = uVar4 != 0;
      local_b0 = 0x1000000;
      local_78 = &local_b0;
      local_70 = 8;
      local_a8[0] = PepSleepStudySessionInstanceId;
      local_b6 = uVar5 != 0;
      local_60 = 8;
      local_68 = local_a8;
      local_b8 = (undefined1)uVar3;
      local_58 = &local_b8;
      local_50 = 1;
      local_b5[0] = (int)uVar2 != 0;
      local_48 = &local_b7;
      local_40 = 1;
      local_38 = &local_b6;
      local_30 = 1;
      local_28 = local_b5;
      local_20 = 1;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030b66,uVar2,uVar3,8,local_98);
    }
  }
  return;
}



===== PepDiagLogHwDripsCounterInfo @ 1400907a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogHwDripsCounterInfo(void)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined1 auStackY_e8 [32];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined8 *local_78;
  ulonglong local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  iVar4 = 0;
  if (PepNumPlatformStates != 0) {
    lVar2 = (ulonglong)PepDripsIndex * 0x60;
    if (5 < DAT_1400340a0) {
      lVar3 = DAT_140087708;
      uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
      if ((char)uVar1 != '\0') {
        local_a8 = *(undefined8 *)(lVar2 + 0x18 + lVar3);
        local_70 = (ulonglong)(iVar4 + 8U);
        local_78 = &local_a8;
        local_b8 = *(undefined4 *)(lVar2 + 0x20 + lVar3);
        local_68 = &local_b8;
        local_b4 = *(undefined4 *)(lVar2 + 0x24 + lVar3);
        local_58 = &local_b4;
        local_b0 = *(undefined4 *)(lVar2 + 0x28 + lVar3);
        local_48 = &local_b0;
        local_ac = *(undefined4 *)(lVar2 + 0x2c + lVar3);
        local_38 = &local_ac;
        local_a0 = *(undefined8 *)(lVar2 + 0x48 + lVar3);
        local_28 = &local_a0;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_30 = 4;
        local_20 = local_70;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_14002ddbb,lVar2,lVar3,iVar4 + 8U,local_98);
      }
    }
  }
  return;
}



===== PepDiagLogHwDripsCounterNotFound @ 1400908d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogHwDripsCounterNotFound(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined1 auStackY_148 [32];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100 [2];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8 [2];
  undefined8 local_d8 [4];
  undefined8 *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  if (PepSubsystemSoCInfo == (undefined4 *)0x0) {
    if (Pepv2SubsystemSocInfo == (undefined4 *)0x0) {
      return;
    }
    puVar6 = *(undefined4 **)(Pepv2SubsystemSocInfo + 2);
    puVar2 = Pepv2SubsystemSocInfo;
  }
  else {
    puVar6 = *(undefined4 **)(PepSubsystemSoCInfo + 10);
    puVar2 = PepSubsystemSoCInfo;
  }
  uVar5 = (ulonglong)(uint)puVar2[1];
  uVar1 = *puVar2;
  if (((PepNumPlatformStates != 0) && (lVar4 = (ulonglong)PepDripsIndex * 0x60, 5 < DAT_1400340a0))
     && (lVar7 = DAT_140087708, uVar3 = _tlgKeywordOn(0x1400340a0,0x400000000000),
        (char)uVar3 != '\0')) {
    local_ac = 0;
    local_b8 = &local_f8;
    local_9c = 0;
    local_8c = 0;
    local_7c = 0;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_a8 = &local_118;
    local_98 = &local_114;
    local_110 = *puVar6;
    local_88 = &local_110;
    local_f0 = *(undefined8 *)(lVar4 + 0x18 + lVar7);
    local_78 = &local_f0;
    local_10c = *(undefined4 *)(lVar4 + 0x20 + lVar7);
    local_68 = &local_10c;
    local_108 = *(undefined4 *)(lVar4 + 0x24 + lVar7);
    local_58 = &local_108;
    local_104 = *(undefined4 *)(lVar4 + 0x28 + lVar7);
    local_48 = &local_104;
    local_100[0] = *(undefined4 *)(lVar4 + 0x2c + lVar7);
    local_38 = local_100;
    local_e8[0] = *(undefined8 *)(lVar4 + 0x48 + lVar7);
    local_28 = local_e8;
    local_a0 = 4;
    local_90 = 4;
    local_80 = 4;
    local_60 = 4;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    local_f8 = 0x1000000;
    local_b0 = 8;
    local_114 = (undefined4)uVar5;
    local_70 = 8;
    local_20 = 8;
    local_118 = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002dcc0,lVar4,uVar5,0xc,local_d8);
  }
  return;
}



===== PepDiagLogLPMEnable @ 140090abc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLPMEnable(uint *param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStackY_a8 [32];
  undefined1 local_78 [8];
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  puVar1 = PTR_LowPowerModeEnableDomainAccounting_140061e90;
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0;
  if (PepSubsystemLPMDomainInfo != 0) {
    do {
      lVar6 = uVar4 * 5;
      uVar5 = (ulonglong)(1 << (puVar1[uVar4 * 0x28 + 0x10] & 0x1f) & *param_1);
      if (5 < DAT_1400340a0) {
        uVar2 = _tlgKeywordOn(0x1400340a0,0x400000000000);
        if ((char)uVar2 != '\0') {
          local_48 = &local_70;
          local_3c = 0;
          local_70 = 0x1000000;
          local_40 = 8;
          _tlgCreate1Sz_wchar_t(local_38,*(wchar_t **)(puVar1 + lVar6 * 8));
          local_28 = local_78;
          local_20 = 1;
          local_78[0] = (int)uVar5 != 0;
          local_1c = 0;
          _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002db75,uVar5,lVar6,5,local_68);
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < PepSubsystemLPMDomainInfo);
  }
  return;
}



===== PepDiagLogLPMPriority @ 140090bdc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLPMPriority(uint *param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStackY_a8 [32];
  undefined1 local_78 [8];
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  puVar1 = PTR_LowPowerModePriorityDomainAccounting_140061e80;
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0;
  if (PepSubsystemLPMPriorityDomainInfo != 0) {
    do {
      lVar6 = uVar4 * 5;
      uVar5 = (ulonglong)(*param_1 >> (puVar1[uVar4 * 0x28 + 0x10] & 0x1f)) & 0xffffffffffffff0f;
      if (5 < DAT_1400340a0) {
        uVar2 = _tlgKeywordOn(0x1400340a0,0x400000000000);
        if ((char)uVar2 != '\0') {
          local_48 = &local_70;
          local_3c = 0;
          local_70 = 0x1000000;
          local_40 = 8;
          _tlgCreate1Sz_wchar_t(local_38,*(wchar_t **)(puVar1 + lVar6 * 8));
          local_1c = 0;
          local_28 = local_78;
          local_78[0] = (undefined1)uVar5;
          local_20 = 1;
          _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002eb43,uVar5,lVar6,5,local_68);
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < PepSubsystemLPMPriorityDomainInfo);
  }
  return;
}



===== PepDiagLogLtrOverrideEnabled @ 140090cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLtrOverrideEnabled
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_c8 [32];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95 [5];
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
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
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_68 = &local_90;
      local_90 = 0x1000000;
      local_98 = PepPcieGeneratePcieHierarchyEnabled;
      local_58 = &local_98;
      local_97 = PepPcieLtrOverrideEnabled;
      local_48 = &local_97;
      local_38 = &local_96;
      local_60 = 8;
      local_50 = 1;
      local_40 = 1;
      local_30 = 1;
      local_96 = uVar2;
      uVar1 = PepSubsystemIsSocHardwareSupportPresent();
      local_95[0] = (undefined1)uVar1;
      local_28 = local_95;
      local_20 = 1;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002e9a1,CONCAT71(uVar3,uVar2),param_4,7,local_88);
    }
  }
  return;
}



===== PepDiagLogLtrOverrideSkippedTelemetry @ 140090df0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogLtrOverrideSkippedTelemetry
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 auStackY_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined8 local_b8 [4];
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
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
  ulonglong local_28;
  
  lVar2 = PepPcieLtrOverrideSkipTelemetry;
  uVar1 = PepDripsTransitionCount;
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  if ((PepPcieLtrOverrideSkipTelemetry != 0) &&
     (uVar4 = (ulonglong)DAT_1400340a0, 5 < DAT_1400340a0)) {
    uVar3 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar3 != '\0') {
      local_98 = &local_d8;
      local_d8 = 0x1000000;
      local_88 = &local_e0;
      local_90 = 8;
      local_e8 = *(undefined8 *)(lVar2 + 0x20);
      local_78 = &local_e8;
      local_f0 = *(undefined8 *)(lVar2 + 0x10);
      local_68 = &local_f0;
      local_f8 = *(undefined8 *)(lVar2 + 8);
      local_58 = &local_f8;
      local_d0 = *(undefined8 *)(lVar2 + 0x18);
      local_48 = &local_d0;
      local_80 = 8;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_e0 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ece2,uVar4,param_4,8,local_b8);
      uVar4 = (ulonglong)DAT_1400340a0;
    }
    if (5 < (uint)uVar4) {
      uVar3 = _tlgKeywordOn(0x1400340a0,0x400000000000);
      if ((char)uVar3 != '\0') {
        local_98 = &local_d0;
        local_d0 = 0x1000000;
        local_88 = local_c8;
        local_90 = 8;
        local_78 = &local_f8;
        local_f0 = CONCAT44(local_f0._4_4_,*(undefined4 *)(lVar2 + 0x34));
        local_68 = &local_f0;
        local_e8 = CONCAT44(local_e8._4_4_,*(undefined4 *)(lVar2 + 0x2c));
        local_58 = &local_e8;
        local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar2 + 0x28));
        local_48 = &local_e0;
        local_d8 = CONCAT44(local_d8._4_4_,*(undefined4 *)(lVar2 + 0x30));
        local_38 = &local_d8;
        local_80 = 8;
        local_f8 = CONCAT44(local_f8._4_4_,uVar1);
        local_70 = 4;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_30 = 4;
        local_c8[0] = param_1;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002ff3e,uVar4,param_4,9,local_b8);
      }
    }
  }
  return;
}



===== PepDiagLogNonPoFxStorportRpConstraint @ 140091030 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogNonPoFxStorportRpConstraint
               (longlong param_1,longlong param_2,undefined1 param_3,undefined8 param_4)

{
  undefined2 *puVar1;
  bool bVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 auStackY_d8 [32];
  undefined1 local_a8 [8];
  longlong local_a0;
  longlong lStack_98;
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  longlong local_48;
  uint local_40 [2];
  undefined1 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a0 = 0;
  lStack_98 = 0;
  RtlInitUnicodeString(&local_a0,0);
  bVar2 = false;
  if (param_2 == 0) {
    RtlInitUnicodeString(&local_a0,L"RpNonPoFxPdoStorportNotFound");
  }
  else {
    ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    for (puVar3 = *(undefined8 **)(param_2 + 0x10); puVar3 != (undefined8 *)(param_2 + 0x10);
        puVar3 = (undefined8 *)*puVar3) {
      if (*(longlong *)(puVar3[3] + 0x10) == param_1) {
        puVar1 = (undefined2 *)(puVar3[3] + 0x40);
        lStack_98 = ExAllocatePool2(0x100,*puVar1,0x49504550);
        if (lStack_98 != 0) {
          local_a0 = (ulonglong)CONCAT42((int)((ulonglong)local_a0 >> 0x20),*puVar1) << 0x10;
          RtlCopyUnicodeString(&local_a0,puVar1);
          bVar2 = true;
        }
        break;
      }
    }
    ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  }
  if (lStack_98 != 0) {
    lVar5 = lStack_98;
    if (5 < DAT_1400340a0) {
      uVar4 = _tlgKeywordOn(0x1400340a0,0x400000000000);
      if ((char)uVar4 != '\0') {
        local_68 = &local_90;
        local_90 = 0x1000000;
        local_58 = local_40;
        local_60 = 8;
        local_40[0] = (uint)(ushort)local_a0;
        local_38 = local_a8;
        local_50 = 2;
        local_40[1] = 0;
        local_30 = 1;
        local_a8[0] = param_3;
        local_48 = lVar5;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e77c,lVar5,param_4,6,local_88);
        lVar5 = lStack_98;
      }
    }
    if (bVar2) {
      ExFreePoolWithTag(lVar5,0x49504550);
    }
  }
  return;
}



===== PepDiagLogPchMbInitIndexesFailure @ 140091224 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchMbInitIndexesFailure(uint *param_1,uint param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [2];
  undefined8 local_70;
  char *local_68 [4];
  char *local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  char *local_28;
  char *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar2 = (ulonglong)*param_1;
  local_68[0] = "Mb Disabled";
  local_68[1] = "Mb Entry not found in PCH table";
  local_68[2] = "Mb command register Init failed";
  local_68[3] = "Mb status register Init failed";
  local_48 = "Mb readbuf0 register Init failed";
  local_40 = "Mb writebuf0 register Init failed";
  local_38 = "Mb writebuf1 register Init failed";
  local_30 = "Mb incorrect mailbox version";
  local_28 = "Mb LTR context is NULL";
  local_20 = "Mb RP index not found in the table";
  uVar3 = (ulonglong)param_2;
  if ((*param_1 < 10) && (5 < DAT_1400340a0)) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_char((longlong *)(local_68 + 4),local_68[uVar2]);
      local_38 = (char *)local_78;
      local_28 = (char *)&local_70;
      local_78[0] = (undefined4)uVar3;
      local_30 = (char *)0x4;
      local_70 = 0x1000000;
      local_20 = (char *)0x8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002eb88,uVar2,uVar3,5,local_68);
    }
  }
  return;
}



===== PepDiagLogPchMbInitLtrOvrFail @ 140091364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchMbInitLtrOvrFail(ushort *param_1,char *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined8 local_88 [4];
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (param_1 != (ushort *)0x0) {
    local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
    uVar2 = 0;
    if ((5 < DAT_1400340a0) &&
       (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')) {
      local_68 = &local_50;
      local_60 = 2;
      local_58 = *(undefined8 *)(param_1 + 4);
      local_50 = (uint)*param_1;
      local_4c = uVar2;
      _tlgCreate1Sz_char(local_48,param_2);
      local_98[0] = (undefined4)param_3;
      local_38 = local_98;
      local_28 = &local_90;
      local_30 = 4;
      local_90 = 0x1000000;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e65f,param_3,param_1,7,local_88);
    }
  }
  return;
}



===== PepDiagLogPchMbInitLtrOvrRegFail @ 140091454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchMbInitLtrOvrRegFail(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (param_1 != 0) {
    local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
    uVar2 = (ulonglong)param_2;
    if ((5 < DAT_1400340a0) &&
       (uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000), (char)uVar1 != '\0')) {
      local_90 = *(undefined8 *)(param_1 + 0x28);
      local_58 = &local_90;
      local_50 = 8;
      local_98 = *(undefined4 *)(param_1 + 0x10);
      local_48 = &local_98;
      local_38 = &local_94;
      local_28 = local_88;
      local_40 = 4;
      local_94 = (undefined4)uVar2;
      local_30 = 4;
      local_88[0] = 0x1000000;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f27f,param_1,uVar2,6,local_78);
    }
  }
  return;
}



===== PepDiagLogPchOverrideRegFail @ 140091540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPchOverrideRegFail(ushort *param_1,longlong param_2,undefined8 param_3)

{
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88 [4];
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_94 = (undefined4)param_3;
  if (((param_1 != (ushort *)0x0) &&
      (local_18 = __security_cookie ^ (ulonglong)auStackY_c8, param_2 != 0)) && (5 < DAT_1400340a0))
  {
    local_68 = local_50;
    local_60 = 2;
    local_58 = *(undefined8 *)(param_1 + 4);
    local_50[0] = (uint)*param_1;
    local_90 = *(undefined8 *)(param_2 + 0x28);
    local_48 = &local_90;
    local_98 = *(undefined4 *)(param_2 + 0x10);
    local_38 = &local_98;
    local_28 = &local_94;
    local_50[1] = 0;
    local_40 = 8;
    local_30 = 4;
    local_20 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_140030329,param_3,0,7,local_88);
  }
  return;
}



===== PepDiagLogPcieHierarchyState @ 140091624 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPcieHierarchyState
               (undefined1 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined7 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_f8 [32];
  undefined1 local_c8;
  undefined1 local_c7;
  undefined1 local_c6;
  undefined1 local_c5;
  undefined1 local_c4 [4];
  undefined4 local_c0 [2];
  undefined8 local_b8 [2];
  undefined8 local_a8 [4];
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar3 = (undefined7)((ulonglong)param_4 >> 8);
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_c8 = PepPcieGeneratePcieHierarchyEnabled;
      local_88 = &local_c8;
      local_80 = 1;
      local_c7 = PepPlatformAoAc;
      local_78 = &local_c7;
      local_c0[0] = PepDripsIndex;
      local_68 = local_c0;
      local_c6 = PepPcieSecurePcieEnabled;
      local_58 = &local_c6;
      local_48 = &local_c5;
      local_38 = local_c4;
      local_28 = local_b8;
      local_70 = 1;
      local_60 = 4;
      local_50 = 1;
      local_40 = 1;
      local_30 = 1;
      local_b8[0] = 0x1000000;
      local_20 = 8;
      local_c5 = param_1;
      local_c4[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002fbc0,CONCAT71(uVar2,param_2),CONCAT71(uVar3,param_1),9,
                 local_a8);
    }
  }
  return;
}



===== PepDiagLogPcieLtrOverrideState @ 140091758 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogPcieLtrOverrideState
               (undefined1 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined7 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_c8 [32];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95 [5];
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar3 = (undefined7)((ulonglong)param_4 >> 8);
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_98 = PepPcieLtrOverrideEnabled;
      local_68 = &local_98;
      local_60 = 1;
      local_58 = &local_97;
      local_96 = PepPcieSecurePcieEnabled;
      local_48 = &local_96;
      local_38 = local_95;
      local_28 = &local_90;
      local_50 = 1;
      local_40 = 1;
      local_30 = 1;
      local_90 = 0x1000000;
      local_20 = 8;
      local_97 = param_1;
      local_95[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002e4a0,CONCAT71(uVar2,param_2),CONCAT71(uVar3,param_1),7,
                 local_88);
    }
  }
  return;
}



===== PepDiagLogRootPortLtrOverrideInitFailure @ 140091858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogRootPortLtrOverrideInitFailure(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_f8 [32];
  undefined4 local_c8;
  uint local_c4;
  uint local_c0;
  undefined4 local_bc;
  undefined8 local_b8 [2];
  undefined8 local_a8 [4];
  undefined8 *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  undefined8 local_68;
  uint local_60 [2];
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1400340a0) {
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_88 = local_b8;
      local_78 = local_60;
      local_b8[0] = 0x1000000;
      local_68 = *(undefined8 *)(param_1 + 0x28);
      local_60[0] = (uint)*(ushort *)(param_1 + 0x20);
      local_c8 = *(undefined4 *)(param_1 + 0x34);
      local_58 = &local_c8;
      local_c4 = *(uint *)(param_1 + 0x38) & 0x1f;
      local_c0 = *(uint *)(param_1 + 0x38) >> 5 & 7;
      local_48 = &local_c4;
      local_38 = &local_c0;
      local_80 = 8;
      local_28 = &local_bc;
      local_70 = 2;
      local_60[1] = 0;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_bc = (undefined4)uVar2;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002e5ef,param_1,uVar2,9,local_a8);
    }
  }
  return;
}



===== PepTraceWakeOnVoiceUpdate @ 140091984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepTraceWakeOnVoiceUpdate
               (undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  undefined7 uVar4;
  undefined1 auStackY_c8 [32];
  undefined1 local_98;
  char local_97 [7];
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar4 = (undefined7)((ulonglong)param_4 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar2 = PepSleepStudySessionInstanceId;
  if (PepSleepStudySessionInProgress == '\0') {
    uVar2 = 0xffffffff;
  }
  if (5 < DAT_1400340a0) {
    cVar3 = PepSleepStudySessionInProgress;
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 != '\0') {
      local_4c = 0;
      local_58 = &local_90;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_48 = &local_98;
      local_38 = local_97;
      local_28 = local_88;
      local_40 = 1;
      local_30 = 1;
      local_90 = 0x1000000;
      local_50 = 8;
      local_20 = 8;
      local_98 = param_1;
      local_97[0] = cVar3;
      local_88[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1400340a0,&DAT_14002de2c,uVar2,CONCAT71(uVar4,cVar3),6,local_78);
    }
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140091a84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

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
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140091ae7;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140091b07;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140091b1b;
  return iVar6;
}



===== PepSubSystemDisableCtaCounters @ 140091b34 =====

void PepSubSystemDisableCtaCounters(void)

{
  char *pcVar1;
  ulonglong uVar2;
  
  if ((PepSubsystemAccountingInfo != 0) && (PepSubsystemAccountingCount != 0)) {
    pcVar1 = (char *)(PepSubsystemAccountingInfo + 0x20);
    uVar2 = (ulonglong)PepSubsystemAccountingCount;
    do {
      if ((*(uint *)(pcVar1 + -0x10) >> 0xc & 1) != 0) {
        if ((PepSubsystemCtaBaseAddr != 0) && (*pcVar1 == '\0')) {
          *(longlong *)(pcVar1 + 0x38) = *(longlong *)(pcVar1 + 0x38) - PepSubsystemCtaBaseAddr;
        }
        *(uint *)(pcVar1 + -0x10) = *(uint *)(pcVar1 + -0x10) & 0xffffdfff | 0x4000;
        *pcVar1 = '\x01';
      }
      pcVar1 = pcVar1 + 0xd8;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  LOCK();
  PepSubsystemCtaBaseAddr = 0;
  UNLOCK();
  return;
}



===== PepSubsystemCtaArrivalUpdateInfo @ 140091ba0 =====

uint PepSubsystemCtaArrivalUpdateInfo
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  int *piVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined8 uVar15;
  uint local_res10;
  undefined8 *local_res18;
  
  uVar9 = 0;
  if ((param_1 == 0) || (Pepv2SubsystemSocInfo == (int *)0x0)) {
    return 0xc00000e5;
  }
  bVar7 = false;
  bVar6 = false;
  uVar10 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 == 0) {
    if ((*Pepv2SubsystemSocInfo == 6) && (Pepv2SubsystemSocInfo[1] == 0xaa)) {
      bVar7 = true;
    }
  }
  else if ((*Pepv2SubsystemSocInfo == 6) && (Pepv2SubsystemSocInfo[1] == 0x8c)) {
    bVar6 = true;
  }
  uVar14 = *(uint *)(param_1 + 8);
  if (0xff < uVar14 - 1) {
    return 0x105;
  }
  if (PepSubsystemCtaSignature == (int *)0x0) {
    return 0xc00000e5;
  }
  uVar15 = 0x49504550;
  puVar11 = (undefined8 *)ExAllocatePool2();
  if (puVar11 == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  local_res10 = 0;
  if (uVar14 != 0) {
    local_res18 = (undefined8 *)(param_1 + 0x10);
    do {
      piVar8 = PepSubsystemCtaSignature;
      uVar12 = local_res18[1];
      *puVar11 = *local_res18;
      puVar11[1] = uVar12;
      uVar12 = local_res18[3];
      puVar11[2] = local_res18[2];
      puVar11[3] = uVar12;
      iVar1 = *piVar8;
      iVar2 = *(int *)((longlong)puVar11 + 0x14);
      iVar3 = piVar8[1];
      iVar4 = *(int *)((longlong)puVar11 + 4);
      uVar10 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar10 != 0) {
        if (!bVar6) goto LAB_140091ca4;
LAB_140091cf8:
        if (iVar1 != iVar2) goto LAB_140091ca9;
LAB_140091cfd:
        if (PepIntcExclusivePmtMmioInterfaceAvailable == '\0') {
          uVar12 = PepSubsystemCtaValidateCounterInfo(*(uint *)(puVar11 + 3));
          uVar9 = (uint)uVar12;
          if ((int)uVar9 < 0) goto LAB_140091dba;
        }
        lVar5 = puVar11[1];
        if (lVar5 != 0) {
          uVar10 = 0;
          LOCK();
          UNLOCK();
          PepSubsystemCtaBaseAddr = lVar5;
          if (PepSubsystemAccountingCount == 0) goto LAB_140091d8b;
          goto LAB_140091d3d;
        }
        break;
      }
      if (!bVar7) goto LAB_140091cf8;
LAB_140091ca4:
      if (iVar1 == iVar2) {
LAB_140091ca9:
        if (iVar3 == iVar4) goto LAB_140091cfd;
      }
      local_res10 = local_res10 + 1;
      local_res18 = local_res18 + 4;
    } while (local_res10 < uVar14);
  }
  uVar9 = 0xc00000e5;
  goto LAB_140091cd0;
LAB_140091d3d:
  do {
    puVar13 = (undefined8 *)(uVar10 * 0xd8 + PepSubsystemAccountingInfo);
    if ((*(uint *)(puVar13 + 2) & 0x9000) == 0x1000) {
      puVar13[0xb] = puVar13[0xb] + lVar5;
      uVar9 = PepValidateAndInitAddress((int *)(puVar13 + 6));
      if ((int)uVar9 < 0) {
        PepDiagCtaInterfaceArrivalFail(puVar13,0,uVar15,param_4);
        PepSubSystemDisableCtaCounters();
        uVar9 = 0xc0000001;
        goto LAB_140091cda;
      }
      *(undefined1 *)(puVar13 + 4) = 0;
      *(uint *)(puVar13 + 2) = *(uint *)(puVar13 + 2) & 0xffffbfff | 0x2000;
    }
    uVar14 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar14;
  } while (uVar14 < PepSubsystemAccountingCount);
LAB_140091d8b:
  if ((PepIntcExclusivePmtMmioInterfaceAvailable == '\0') &&
     (Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline(),
     PepSubsystemPkgCStateThreshold != (undefined **)0x0)) {
    PepSubsystemOrignalPkgCStateThreshold = PepSubsystemPkgCStateThreshold;
    PepSubsystemPkgCStateThreshold = &PepSubSystemCtaPlatformIdleStateThreshold;
  }
LAB_140091dba:
  if (uVar9 != 0xc00000e5) goto LAB_140091cda;
LAB_140091cd0:
  PepDiagCtaInterfaceArrivalFail((undefined8 *)0x0,(longlong)puVar11,uVar15,param_4);
LAB_140091cda:
  ExFreePoolWithTag(puVar11,0x49504550);
  return uVar9;
}



===== PepSubsystemCtaValidateCounterInfo @ 140091e0c =====

undefined8 PepSubsystemCtaValidateCounterInfo(uint param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int *piVar4;
  undefined8 uVar5;
  byte bVar6;
  byte bVar7;
  ulonglong uVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  uint uVar16;
  byte bVar17;
  bool bVar18;
  
  uVar5 = 0;
  bVar18 = false;
  uVar16 = 0;
  uVar11 = 0;
  bVar2 = 0;
  bVar3 = 0;
  bVar14 = 0;
  bVar13 = 0;
  piVar4 = PepSubsystemSoCInfo;
  if (((PepSubsystemSoCInfo != (int *)0x0) ||
      (piVar4 = Pepv2SubsystemSocInfo, Pepv2SubsystemSocInfo != (int *)0x0)) &&
     (iVar1 = piVar4[1], *piVar4 == 6)) {
    bVar15 = (byte)param_1;
    if (iVar1 == 0x8c) {
      bVar6 = (byte)(param_1 >> 0x10);
      bVar7 = (byte)(param_1 >> 0x18);
      uVar10 = param_1 >> 8;
    }
    else {
      if (0x27 < iVar1 - 0x97U) {
        return 0;
      }
      if ((0x8900080009U >> ((ulonglong)(iVar1 - 0x97U) & 0x3f) & 1) == 0) {
        return 0;
      }
      bVar6 = (byte)(param_1 >> 9) & 0x3f;
      bVar7 = (byte)(param_1 >> 0x13) & 0xf;
      bVar13 = (byte)(param_1 >> 0x17) & 0x1f;
      bVar15 = bVar15 & 0x1f;
      uVar10 = param_1 >> 5 & 0xf;
      bVar18 = iVar1 == 0xaa;
      bVar2 = 1;
      bVar14 = 0xb;
      uVar11 = (uint)!bVar18;
    }
    if (PepSubsystemAccountingCount != 0) {
      uVar8 = (ulonglong)PepSubsystemAccountingCount;
      piVar4 = (int *)(PepSubsystemAccountingInfo + 0x14);
      bVar9 = bVar2;
      uVar12 = uVar11;
      bVar17 = 0;
      do {
        iVar1 = *piVar4;
        piVar4 = piVar4 + 0x36;
        uVar11 = uVar12 + 1;
        if (iVar1 != 0xc) {
          uVar11 = uVar12;
        }
        uVar12 = uVar16 + 1;
        if (iVar1 != 0xd) {
          uVar12 = uVar16;
        }
        uVar16 = uVar12;
        bVar2 = bVar9 + 1;
        if (iVar1 != 0xe) {
          bVar2 = bVar9;
        }
        bVar3 = bVar17 + 1;
        if (iVar1 != 0x10) {
          bVar3 = bVar17;
        }
        bVar9 = bVar14 + 1;
        if (iVar1 != 1) {
          bVar9 = bVar14;
        }
        bVar14 = bVar9;
        uVar8 = uVar8 - 1;
        bVar9 = bVar2;
        uVar12 = uVar11;
        bVar17 = bVar3;
      } while (uVar8 != 0);
    }
    uVar5 = 0;
    if ((((uVar11 != bVar15) || (uVar16 != (uVar10 & 0xff))) || ((bVar2 != bVar6 && (!bVar18)))) ||
       ((bVar3 != bVar7 || (bVar14 != bVar13)))) {
      uVar5 = 0xc00000e5;
      DbgPrintEx(0x92,0,"INTELPEP: Incorrect Count\n");
    }
  }
  return uVar5;
}



===== PepSubsystemIsSocHardwareSupportPresent @ 140091fe0 =====

undefined8 PepSubsystemIsSocHardwareSupportPresent(void)

{
  int *piVar1;
  undefined1 uVar2;
  
  piVar1 = PepSubsystemSoCInfo;
  uVar2 = 1;
  if (((PepSubsystemSoCInfo != (int *)0x0) ||
      (piVar1 = Pepv2SubsystemSocInfo, Pepv2SubsystemSocInfo != (int *)0x0)) && (*piVar1 == 6)) {
    uVar2 = 1;
    if (piVar1[1] == 0x97) {
      uVar2 = 0;
    }
  }
  return CONCAT71((int7)((ulonglong)piVar1 >> 8),uVar2);
}



===== PepSubsystemQueryLtrBlockerInfo @ 14009201c =====

undefined8
PepSubsystemQueryLtrBlockerInfo
          (undefined4 *param_1,undefined8 *param_2,longlong param_3,int *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  iVar4 = *param_4;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = 0xc0000225;
  if ((*(uint *)(param_2 + 2) & 2) != 0) {
    lVar1 = param_2[3];
    if (lVar1 == 0) {
      iVar4 = iVar4 + 1;
      if (iVar4 == *(int *)(param_3 + 4) + 1) {
        RtlInitUnicodeString(&local_38,param_2[1]);
        RtlCopyUnicodeString(param_3 + 0x10,&local_38);
        RtlInitUnicodeString(&local_28,*param_2);
LAB_140092127:
        RtlCopyUnicodeString(param_3 + 0x20);
        uVar3 = 0;
        *param_1 = *(undefined4 *)((longlong)param_2 + 0x14);
        *(undefined8 **)(param_1 + 2) = param_2;
        *(undefined4 **)(param_3 + 8) = param_1;
      }
    }
    else {
      for (uVar2 = 0; (uint)uVar2 < 7; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
        if ((*(uint *)(lVar1 + 0x20 + uVar2 * 0x28) & 2) != 0) {
          iVar4 = iVar4 + 1;
          if (iVar4 == *(int *)(param_3 + 4) + 1) {
            RtlInitUnicodeString(&local_28,*(undefined8 *)(lVar1 + uVar2 * 0x28));
            RtlInitUnicodeString(&local_38,*(undefined8 *)(lVar1 + 8 + uVar2 * 0x28));
            RtlCopyUnicodeString(param_3 + 0x10,&local_38);
            goto LAB_140092127;
          }
        }
      }
    }
  }
  *param_4 = iVar4;
  return uVar3;
}



===== PepSubsystemQueryLtrCount @ 140092178 =====

int PepSubsystemQueryLtrCount(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  
  iVar3 = 0;
  if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
    if (*(longlong *)(param_1 + 0x18) == 0) {
      iVar3 = 1;
    }
    else {
      puVar2 = (uint *)(*(longlong *)(param_1 + 0x18) + 0x20);
      lVar4 = 7;
      do {
        iVar1 = iVar3 + 1;
        if ((*puVar2 & 2) == 0) {
          iVar1 = iVar3;
        }
        iVar3 = iVar1;
        puVar2 = puVar2 + 10;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
  }
  return iVar3;
}



===== PepSubsystemQueryPciLinkBlockerInfo @ 1400921bc =====

undefined8
PepSubsystemQueryPciLinkBlockerInfo
          (undefined4 *param_1,longlong param_2,longlong param_3,int *param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar5 = 0xc000000d;
  local_38 = 0;
  uStack_30 = 0;
  if ((((param_1 != (undefined4 *)0x0) && (param_2 != 0)) && (param_3 != 0)) &&
     (param_4 != (int *)0x0)) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    if (lVar2 == 0) {
      DbgPrintEx(0x92,0,"INTELPEP: Null context in PCI Link State telemetry.\n");
      uVar5 = 0xc00000e5;
    }
    else {
      iVar4 = *param_4;
      uVar5 = 0xc0000225;
      for (uVar3 = 0; (uint)uVar3 < 4; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
        if ((*(uint *)(lVar2 + 0x38 + uVar3 * 0x30) & 2) != 0) {
          iVar4 = iVar4 + 1;
          if (iVar4 == *(int *)(param_3 + 4) + 1) {
            RtlInitUnicodeString(&local_38,*(undefined8 *)(lVar2 + 0x18 + uVar3 * 0x30));
            RtlCopyUnicodeString(param_3 + 0x10,&local_38);
            lVar1 = param_3 + 0x20;
            RtlCopyUnicodeString(lVar1,&local_38);
            if (*(longlong *)(lVar2 + 8) != 0) {
              RtlAppendUnicodeToString(lVar1,L".");
              RtlAppendUnicodeStringToString(lVar1,*(undefined8 *)(lVar2 + 8));
            }
            RtlAppendUnicodeToString(lVar1,L".");
            RtlAppendUnicodeToString(lVar1,*(undefined8 *)(lVar2 + 0x10 + uVar3 * 0x30));
            uVar5 = 0;
            *param_1 = *(undefined4 *)(param_2 + 0x14);
            *(longlong *)(param_1 + 2) = param_2;
            *(undefined4 **)(param_3 + 8) = param_1;
            break;
          }
        }
      }
      *param_4 = iVar4;
    }
  }
  return uVar5;
}



===== PepSubsystemQueryPciLinkCount @ 140092350 =====

int PepSubsystemQueryPciLinkCount(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  longlong lVar3;
  
  iVar1 = 0;
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x10) & 2) != 0)) {
    if (*(longlong *)(param_1 + 0x18) == 0) {
      DbgPrintEx(0x92,0,"INTELPEP: Link State Accounting has NULL list.\n");
      iVar1 = 1;
    }
    else {
      puVar2 = (uint *)(*(longlong *)(param_1 + 0x18) + 0x38);
      lVar3 = 4;
      do {
        if (PepSubsystemHwDripsIndex <= puVar2[-5]) {
          *puVar2 = *puVar2 & 0xfffffffd;
        }
        if ((*puVar2 & 2) != 0) {
          iVar1 = iVar1 + 1;
        }
        puVar2 = puVar2 + 0xc;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
    }
  }
  return iVar1;
}



===== PepSubsystemQueryPowerGatingDomains @ 1400923c8 =====

void PepSubsystemQueryPowerGatingDomains(longlong param_1,int *param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  
  if (((((*(int *)(param_1 + 0x14) - 4U & 0xfffffffb) == 0) &&
       (puVar1 = *(uint **)(param_1 + 0x18), puVar1 != (uint *)0x0)) && (PepSubsystemSlpS0Info != 0)
      ) && (PepSubsystemDeepestPkgStateInfo != 0)) {
    uVar2 = (ulonglong)*puVar1;
    if (*puVar1 != 0) {
      puVar1 = (uint *)(*(longlong *)(puVar1 + 2) + 0x20);
      do {
        if ((*puVar1 & 2) != 0) {
          *param_2 = *param_2 + 1;
        }
        puVar1 = puVar1 + 10;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  }
  return;
}



===== PepSubsystemQueryProvSocIdentifier @ 140092420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PepSubsystemQueryProvSocIdentifier(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  puVar6 = local_res8;
  iVar1 = HalGetBusDataByOffset(4,0,0,puVar6,0,4);
  if (iVar1 == 4) {
    if ((short)local_res8[0] == -0x7f7a) {
      uVar4 = local_res8[0] >> 0x10;
      lVar2 = ExAllocatePool2(0x40,0x1a,0x49504550);
      if (lVar2 == 0) {
        uVar5 = 0xc000009a;
      }
      else {
        _PepSubsystemProvSocIdentifier = 0x1a0000;
        DAT_140087e58 = lVar2;
        uVar3 = RtlUnicodeStringPrintf
                          (&PepSubsystemProvSocIdentifier,L"SOC\\DEV_%.4X",(ulonglong)uVar4,puVar6);
        uVar5 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          ExFreePoolWithTag(lVar2,0x49504550);
          DAT_140087e58 = 0;
        }
      }
    }
    else {
      uVar5 = 0xc0000452;
    }
  }
  else {
    DbgPrintEx(0x92,3,"INTELPEP: VendorId & Device Id config space read failed.\n");
    uVar5 = 0xc00000e5;
  }
  return uVar5;
}



===== PepSubsystemUpdatePowerGatingDomainsBlockers @ 140092538 =====

undefined8
PepSubsystemUpdatePowerGatingDomainsBlockers
          (undefined4 *param_1,longlong param_2,longlong param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  if (((*(int *)(param_2 + 0x14) - 4U & 0xfffffffb) == 0) &&
     (puVar3 = *(uint **)(param_2 + 0x18), puVar3 != (uint *)0x0)) {
    lVar4 = *(longlong *)(puVar3 + 2);
    uVar1 = *puVar3;
    for (uVar5 = 0; (uint)uVar5 < uVar1; uVar5 = (ulonglong)((uint)uVar5 + 1)) {
      if (((*(uint *)(lVar4 + 0x20 + uVar5 * 0x28) & 2) != 0) &&
         (iVar2 = *(int *)(param_3 + 4), *param_4 = *param_4 + 1, *param_4 == iVar2 + 1)) {
        RtlInitUnicodeString(&local_28,*(undefined8 *)(lVar4 + 8 + uVar5 * 0x28));
        RtlCopyUnicodeString(param_3 + 0x10,&local_28);
        RtlInitUnicodeString(&local_28,*(undefined8 *)(lVar4 + uVar5 * 0x28));
        RtlCopyUnicodeString(param_3 + 0x20,&local_28);
        *param_1 = *(undefined4 *)(param_2 + 0x14);
        *(uint **)(param_1 + 2) = puVar3;
        *(undefined4 **)(param_3 + 8) = param_1;
        return 0;
      }
    }
  }
  return 0xc00000bb;
}



===== IsPepPcieRCiEPInExceptionList @ 140092640 =====

undefined1 IsPepPcieRCiEPInExceptionList(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  wchar_t *_Str1;
  uint local_res8 [2];
  uint local_res10 [2];
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_res8[0] = 0;
  local_res10[0] = 0;
  iVar3 = IoGetDeviceProperty(*(undefined8 *)(lVar2 + 0x10),2,0,0,local_res8);
  if (((iVar3 == -0x3fffffdd) && (local_res8[0] < 0x10000)) &&
     (pwVar4 = (wchar_t *)ExAllocatePool2(0x40,local_res8[0],0x49504550), pwVar4 != (wchar_t *)0x0))
  {
    iVar3 = IoGetDeviceProperty(*(undefined8 *)(lVar2 + 0x10),2,local_res8[0],pwVar4,local_res10);
    if (-1 < iVar3) {
      RtlInitUnicodeString(param_1 + 0x38,L"");
      for (_Str1 = pwVar4; *_Str1 != L'\0'; _Str1 = _Str1 + 1) {
        iVar3 = _wcsicmp(_Str1,L"PCI\\CC_0780");
        if (((iVar3 == 0) || (iVar3 = _wcsicmp(_Str1,L"PCI\\CC_0403"), iVar3 == 0)) ||
           (iVar3 = _wcsicmp(_Str1,L"PCI\\CC_0401"), iVar3 == 0)) {
          *(short *)(param_1 + 0x38) = (short)local_res10[0];
          *(wchar_t **)(param_1 + 0x40) = pwVar4;
          *(undefined2 *)(param_1 + 0x3a) = (undefined2)local_res8[0];
          uVar5 = 0;
          if (local_res10[0] >> 1 < 3) {
            return 1;
          }
          do {
            if (pwVar4[uVar5] == L'\0') {
              pwVar4[uVar5] = L',';
              pwVar4 = *(wchar_t **)(param_1 + 0x40);
            }
            uVar1 = uVar5 + 3;
            uVar5 = uVar5 + 1;
          } while (uVar1 < local_res10[0] >> 1);
          return 1;
        }
        for (; *_Str1 != L'\0'; _Str1 = _Str1 + 1) {
        }
      }
    }
    ExFreePoolWithTag(pwVar4,0x49504550);
  }
  return 0;
}



===== PepPcieAbandonDiagDevice @ 1400927f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepPcieAbandonDiagDevice(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if (PepPcieCollectPcieHierarchyDiagnostic != '\0') {
    ExAcquirePushLockExclusiveEx(&PepPcieDiagDeviceMapListLock,0);
    for (puVar3 = PepPcieDiagDeviceMapList; (undefined8 **)puVar3 != &PepPcieDiagDeviceMapList;
        puVar3 = (undefined8 *)*puVar3) {
      iVar2 = RtlCompareUnicodeString(puVar3 + 4,param_1,1);
      uVar1 = _DAT_fffff78000000014;
      if (iVar2 == 0) {
        *(uint *)(puVar3 + 9) = *(uint *)(puVar3 + 9) | 0x10;
        puVar3[8] = uVar1;
        break;
      }
    }
    ExReleasePushLockExclusiveEx(&PepPcieDiagDeviceMapListLock,0);
  }
  return;
}



===== PepPcieAddDiagList @ 140092888 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * PepPcieAddDiagList(undefined8 *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (PepPcieCollectPcieHierarchyDiagnostic == '\0') {
    return (undefined8 *)0x0;
  }
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x50,0x49504550);
  if (puVar4 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  puVar4[7] = _DAT_fffff78000000014;
  puVar4[2] = param_1[2];
  puVar4[3] = param_1[3];
  uVar1 = *(ushort *)*param_1 + 2;
  if (*(ushort *)*param_1 <= uVar1) {
    lVar5 = ExAllocatePool2(0x40,uVar1,0x49504550);
    puVar4[5] = lVar5;
    if (lVar5 != 0) {
      puVar2 = (ushort *)(puVar4 + 4);
      *(ushort *)((longlong)puVar4 + 0x22) = uVar1;
      *puVar2 = 0;
      uVar6 = RtlUnicodeStringCopy(puVar2,(ushort *)*param_1);
      if (-1 < (int)uVar6) goto LAB_140092969;
      ExFreePoolWithTag(puVar4[5],0x49504550);
      puVar2[0] = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar4[5] = 0;
    }
  }
  *(uint *)(puVar4 + 9) = *(uint *)(puVar4 + 9) | 1;
LAB_140092969:
  ExAcquirePushLockExclusiveEx(&PepPcieDiagDeviceMapListLock,0);
  puVar8 = auStack_28;
  puVar7 = &PepPcieDiagDeviceMapList;
  if ((undefined8 *)*DAT_140087e18 != &PepPcieDiagDeviceMapList) {
    puVar7 = (undefined8 *)0x3;
    pcVar3 = (code *)swi(0x29);
    DAT_140087e18 = (undefined8 *)(*pcVar3)();
    puVar8 = auStack_20;
  }
  *puVar4 = puVar7;
  puVar4[1] = DAT_140087e18;
  *DAT_140087e18 = puVar4;
  *(undefined8 *)(puVar8 + -8) = 0x1400929b9;
  DAT_140087e18 = puVar4;
  ExReleasePushLockExclusiveEx(&PepPcieDiagDeviceMapListLock,0);
  return puVar4;
}



===== PepPcieClearRpConstraint @ 1400929e4 =====

int PepPcieClearRpConstraint(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = 0;
  iVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x48);
  if (lVar1 == 0) {
    *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x20000;
  }
  else if (*(longlong *)(param_1 + 0x28) != 0) {
    if (*(int *)(*(longlong *)(param_1 + 0x28) + 0x50) == 3) {
      if (PepDripsIndex == 0xffffffff) {
        *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x10000;
      }
      else {
        if ((*(int *)(*(longlong *)(lVar1 + 0x20) + (ulonglong)PepDripsIndex * 8) != 1) ||
           (*(int *)(*(longlong *)(lVar1 + 0x20) + 4 + (ulonglong)PepDripsIndex * 8) != 1)) {
          MicrosoftTelemetryAssertTriggeredMsgKM
                    ("PepPcieClearRpConstraint called when drips constraint is other than D0:F1");
        }
        local_18 = 0x41;
        local_10 = *(undefined8 *)(lVar1 + 0x10);
        iVar2 = ZwPowerInformation(0x57,&local_18,0x10,0,0);
        if (iVar2 < 0) {
          *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x80;
        }
        else {
          if (PepNumPlatformStates != 0) {
            uVar4 = (ulonglong)PepNumPlatformStates;
            lVar3 = 0;
            do {
              *(undefined4 *)(lVar3 + *(longlong *)(lVar1 + 0x20)) = 1;
              *(undefined4 *)(*(longlong *)(lVar1 + 0x20) + 4 + lVar3) = 0;
              *(undefined4 *)(lVar3 + *(longlong *)(param_1 + 0x38)) = 1;
              *(undefined4 *)(lVar3 + 4 + *(longlong *)(param_1 + 0x38)) = 0;
              uVar4 = uVar4 - 1;
              lVar3 = lVar3 + 8;
            } while (uVar4 != 0);
          }
          *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 1;
        }
      }
    }
    else {
      *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x40000;
    }
  }
  return iVar2;
}



===== PepPcieCreateAndInsertEndPointDevice @ 140092b0c =====

undefined8
PepPcieCreateAndInsertEndPointDevice(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  uint local_res20 [2];
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined4 local_58;
  uint *local_50;
  undefined4 *local_48;
  undefined4 *local_40;
  undefined4 local_38;
  undefined4 local_34 [3];
  
  uVar8 = 0;
  ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  puVar11 = PepPcieRootPortList;
  do {
    if ((undefined8 **)puVar11 == &PepPcieRootPortList) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
      puVar9 = auStack_78;
LAB_140092cba:
      *(undefined8 *)(puVar9 + -8) = 0x140092cca;
      ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
      return uVar8;
    }
    if (*(longlong *)(puVar11[5] + 0x10) == param_2) {
      puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x50,0x49504550);
      puVar9 = auStack_78;
      if (puVar4 == (undefined8 *)0x0) {
        uVar8 = 0xc000009a;
      }
      else {
        puVar4[3] = param_3;
        puVar4[5] = 0;
        puVar4[7] = 0;
        lVar5 = PepFindDeviceMatch((ushort *)(param_3 + 0x20));
        if (lVar5 != 0) {
          puVar4[5] = *(undefined8 *)(lVar5 + 0x20);
        }
        uVar10 = 0;
        if (PepPcieGeneratedConstraintEnabled != '\0') {
          local_40 = &local_38;
          local_38 = 0;
          local_48 = local_34;
          local_34[0] = 0;
          local_50 = local_res20;
          local_res20[0] = 0xffffffff;
          local_58 = 4;
          iVar3 = IoGetDevicePropertyData(param_2,&DEVPKEY_PciDevice_SupportedLinkSubState,0,0);
          if (iVar3 != 0) {
            MicrosoftTelemetryAssertTriggeredMsgKM
                      ("PepPcieQueryPcieL1PMSubstate device property query failed");
          }
          if ((local_res20[0] != 0xffffffff) &&
             ((local_res20[0] == 0 || ((local_res20[0] & 0xb) == 0)))) {
            *(undefined1 *)(puVar4 + 4) = 1;
            puVar11[0x14] = puVar11[0x14] | 4;
          }
          *(uint *)(puVar4 + 2) = local_res20[0];
          *(undefined4 *)(puVar4 + 9) = 0;
          LOCK();
          *(int *)(puVar11 + 0x15) = *(int *)(puVar11 + 0x15) + 1;
          UNLOCK();
          uVar10 = local_res20[0];
        }
        puVar9 = auStack_78;
        puVar6 = puVar11 + 2;
        puVar7 = (undefined8 *)puVar11[3];
        if ((undefined8 *)*puVar7 != puVar6) {
          puVar7 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          puVar6 = (undefined8 *)(*pcVar2)();
          puVar9 = auStack_70;
        }
        puVar4[1] = puVar7;
        *puVar4 = puVar6;
        *puVar7 = puVar4;
        puVar6[1] = puVar4;
        *(undefined8 *)(puVar9 + -8) = 0x140092c86;
        PepPcieCheckEndPointD3Requirement((longlong)puVar11);
        uVar1 = *param_1;
        *(uint *)(puVar9 + 0x28) = (uint)*(byte *)(puVar4 + 4);
        *(uint *)(puVar9 + 0x20) = uVar10;
        *(undefined8 *)(puVar9 + -8) = 0x140092cae;
        DbgPrintEx(0x92,3,
                   "INTELPEP: PepPcieCreateAndInsertEndPointDevice EP (%wZ) L1PM sub state register bit-mask: 0x%x,IsRpD3ConstraintRequired: %d \n"
                   ,uVar1);
      }
      goto LAB_140092cba;
    }
    puVar11 = (undefined8 *)*puVar11;
  } while( true );
}



===== PepPcieEvaluateGeneratePcieHierarchyEnabled @ 140092cf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPcieEvaluateGeneratePcieHierarchyEnabled
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  bool bVar2;
  int local_res8 [2];
  ulonglong local_res10;
  longlong local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  bVar2 = false;
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  if ((PepPlatformAoAc == '\0') || (PepDripsIndex == -1)) {
    PepPcieGeneratePcieHierarchyEnabled = 0;
  }
  else {
    if (PepPcieSecurePcieEnabled != '\0') {
      local_res10 = (ulonglong)Feature_IntelGcWithSecurePcie__private_featureState;
      if ((Feature_IntelGcWithSecurePcie__private_featureState & 0x10) == 0) {
        local_res10 = (ulonglong)(Feature_IntelGcWithSecurePcie__private_featureState | 1);
        wil_details_FeatureReporting_ReportUsageToService(0x1400330b8,local_res10,3);
        wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                  ((uint)local_res10,3,&Feature_IntelGcWithSecurePcie__private_descriptor);
      }
    }
    param_4 = (int *)0x0;
    param_3 = (undefined8 *)0x20019;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                      (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,local_res18);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_18,L"PcieHierarchyOverride");
      param_4 = local_res8;
      param_3 = &local_18;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_res18[0]);
      if (-1 < iVar1) {
        PepPcieGeneratePcieHierarchyEnabled = local_res8[0] != 0;
        bVar2 = local_res8[0] == 0;
      }
    }
    if (local_res18[0] != 0) {
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    }
  }
  PepDiagLogPcieHierarchyState(bVar2,0,param_3,param_4);
  return;
}



===== PepPcieEvaluateLtrOverrideEnabled @ 140092e4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPcieEvaluateLtrOverrideEnabled
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,int *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  bool bVar4;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  bVar4 = false;
  local_res10 = 0;
  uVar3 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (PepPcieSecurePcieEnabled == '\0') {
    uVar2 = PepSubsystemIsSocHardwareSupportPresent();
    if ((char)uVar2 == '\0') {
      uVar3 = 1;
      PepPcieLtrOverrideEnabled = 0;
    }
    else {
      param_4 = (int *)0x0;
      param_3 = (undefined8 *)0x20019;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                        (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,&local_res10);
      if (-1 < iVar1) {
        RtlInitUnicodeString(&local_18,L"LtrOverride");
        param_4 = local_res8;
        param_3 = &local_18;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_res10);
        if (-1 < iVar1) {
          PepPcieLtrOverrideEnabled = local_res8[0] != 0;
          bVar4 = local_res8[0] == 0;
        }
      }
      if (local_res10 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
      }
    }
  }
  else {
    PepPcieLtrOverrideEnabled = 0;
  }
  PepDiagLogPcieLtrOverrideState(bVar4,uVar3,param_3,param_4);
  return;
}



===== PepPcieEvaluateSecurePciEnabled @ 140092f64 =====

void PepPcieEvaluateSecurePciEnabled(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar2 != '\0') {
    cVar1 = VslGetSecurePciEnabled();
    if (cVar1 != '\0') {
      PepPcieSecurePcieEnabled = 1;
    }
  }
  return;
}



===== PepPcieEvalulateGeneratedConstraintsEnabled @ 140092f94 =====

void PepPcieEvalulateGeneratedConstraintsEnabled(void)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int *piVar5;
  int local_res8 [2];
  undefined8 local_res10 [3];
  
  local_res8[0] = 0;
  if (PepNumPlatformStates == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = (ulonglong)PepDripsIndex * 0x60 + DAT_140087708 + 0x10;
    if (*(int *)(lVar2 + 0x10) != 0x7f) {
      piVar5 = local_res8;
      uVar4 = 8;
      local_res10[0] = 0x43;
      uVar3 = 0x57;
      iVar1 = ZwPowerInformation(0x57,local_res10,8,piVar5,4);
      if (iVar1 < 0) {
        DbgPrintEx(0x92,0,
                   "INTELPEP: EvalulateGeneratedConstraintsEnabled power information failed.\n");
        PepPcieGeneratedConstraintEnabled = 0;
        return;
      }
      if (local_res8[0] != -1) {
        PepPcieGeneratedConstraintEnabled = local_res8[0] == 0;
      }
      PepDiagLogGeneratedConstraintEnabled
                (uVar3,local_res8[0] == -1 || local_res8[0] == 0,uVar4,piVar5);
      return;
    }
  }
  PepPcieGeneratedConstraintEnabled = 0;
  PepDiagLogGeneratedConstraintDisabled(lVar2);
  return;
}



===== PepPcieEvalulateRCiEPGeneratedConstraintsEnabled @ 140093060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPcieEvalulateRCiEPGeneratedConstraintsEnabled
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_res10 = 0;
  uVar2 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar3 = 0;
  if ((PepNumPlatformStates != 0) &&
     (param_1 = (undefined8 *)((ulonglong)PepDripsIndex * 0x60),
     *(int *)((longlong)param_1 + DAT_140087708 + 0x20) != 0x7f)) {
    param_4 = (int *)0x0;
    uVar2 = 1;
    param_1 = WdfDriverGlobals;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                      (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,&local_res10);
    uVar3 = 0;
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_18,L"Gc2Enabled");
      param_4 = local_res8;
      param_1 = WdfDriverGlobals;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_res10,&local_18,param_4);
      if (-1 < iVar1) {
        PepPcieGeneratedConstraintRCiEPEnabled = local_res8[0] != 0;
        uVar3 = 1;
      }
    }
    if (local_res10 != 0) {
      param_1 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x738))();
    }
  }
  PepDiagLogGc2Enabled(param_1,uVar2,0,CONCAT71((int7)((ulonglong)param_4 >> 8),uVar3));
  return;
}



===== PepPcieFindDeviceMatch @ 14009317c =====

short * PepPcieFindDeviceMatch(ushort *param_1,undefined8 param_2,ulonglong *param_3)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  short *psVar11;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  psVar3 = (short *)0x0;
  uVar2 = 0;
  ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  if ((PepPcieLtrOverrideEnabled != '\0') || (PepPcieGeneratedConstraintEnabled != '\0')) {
    lVar10 = 2;
    for (puVar9 = PepPcieRootPortList; (undefined8 **)puVar9 != &PepPcieRootPortList;
        puVar9 = (undefined8 *)*puVar9) {
      lVar5 = puVar9[5];
      iVar1 = RtlCompareUnicodeString(lVar5 + 0x20,param_1,1);
      if (iVar1 == 0) {
        *(undefined4 *)(lVar5 + 0x50) = 2;
        if (puVar9[9] == 0) {
          psVar3 = (short *)ExAllocatePool2(0x40,0x38,0x49504550);
          if (psVar3 == (short *)0x0) {
            uVar2 = 0xc000009a;
          }
          else {
            puVar6 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x49504550);
            if (puVar6 != (undefined8 *)0x0) {
              PepPcieGetVendorDeviceId(lVar5);
              uVar2 = Pepv2SubsystemGetRootPortParentInfo(lVar5,puVar9 + 0x16,puVar9 + 0x17);
              if ((int)uVar2 < 0) {
                local_48 = *(undefined4 *)(lVar5 + 0x20);
                uStack_44 = *(undefined4 *)(lVar5 + 0x24);
                uStack_40 = *(undefined4 *)(lVar5 + 0x28);
                uStack_3c = *(undefined4 *)(lVar5 + 0x2c);
                DbgPrintEx(0x92,1,
                           "INTELPEP: %s: Failed to get root port: (%wZ) parent info with status: 0x%x\n"
                           ,"PepPcieFindDeviceMatch",&local_48,uVar2);
              }
              if ((PepPcieLtrOverrideEnabled != '\0') &&
                 (uVar2 = PepPcieInitRootPortLtrOverrideContext
                                    ((longlong)puVar9,(longlong)puVar6,*(int *)(lVar5 + 0x38)),
                 (int)uVar2 < 0)) {
                local_48 = *(undefined4 *)(lVar5 + 0x20);
                uStack_44 = *(undefined4 *)(lVar5 + 0x24);
                uStack_40 = *(undefined4 *)(lVar5 + 0x28);
                uStack_3c = *(undefined4 *)(lVar5 + 0x2c);
                DbgPrintEx(0x92,1,
                           "INTELPEP: %s: Failed to initialize LTR Override Context for Rp Name:(%wZ) with status: 0x%x\n"
                           ,"PepPcieFindDeviceMatch",&local_48,uVar2);
                PepDiagLogRootPortLtrOverrideInitFailure(lVar5,uVar2);
              }
              psVar3[0x14] = 0;
              psVar3[0x15] = 0;
              psVar3[0x16] = 0;
              psVar3[0x17] = 0;
              psVar11 = psVar3 + 0xc;
              *(undefined1 *)psVar11 = 0;
              *(undefined1 *)((longlong)psVar3 + 0x19) = 0;
              *(undefined8 *)(psVar3 + 8) = param_2;
              uVar2 = RtlUnicodeStringInitEx(psVar3,*(short **)(lVar5 + 0x28));
              if (PepPcieGeneratedConstraintEnabled == '\0') {
                lVar5 = PepFindDeviceMatch(param_1);
                if ((lVar5 != 0) && (*(char *)(lVar5 + 0x19) != '\0')) {
                  puVar9[0xb] = *(undefined8 *)(lVar5 + 0x20);
                  if (*(longlong *)(psVar3 + 0x10) == 0) {
                    *(undefined8 *)(psVar3 + 0x10) = *(undefined8 *)(lVar5 + 0x20);
                  }
                  do {
                    *(undefined1 *)psVar11 =
                         *(undefined1 *)((lVar5 - (longlong)psVar3) + (longlong)psVar11);
                    psVar11 = (short *)((longlong)psVar11 + 1);
                    *(undefined8 *)(psVar3 + 0x14) = *(undefined8 *)(lVar5 + 0x28);
                    lVar10 = lVar10 + -1;
                  } while (lVar10 != 0);
                  *(undefined8 *)(lVar5 + 0x10) = param_2;
                  PepUpdateNumUnregisteredDevices('\0');
                }
                goto LAB_14009361f;
              }
              lVar10 = ExAllocatePool2(0x40,(ulonglong)PepNumPlatformStates << 3,0x49504550);
              *(longlong *)(psVar3 + 0x10) = lVar10;
              if (lVar10 != 0) {
                uVar8 = 0;
                if (PepNumPlatformStates != 0) {
                  do {
                    *(undefined4 *)(*(longlong *)(psVar3 + 0x10) + 4 + uVar8 * 8) = 1;
                    *(undefined4 *)(*(longlong *)(psVar3 + 0x10) + uVar8 * 8) = 1;
                    uVar7 = (int)uVar8 + 1;
                    uVar8 = (ulonglong)uVar7;
                  } while (uVar7 < PepNumPlatformStates);
                }
                puVar9[7] = *(undefined8 *)(psVar3 + 0x10);
LAB_14009361f:
                *puVar6 = puVar9;
                *(undefined8 **)(psVar3 + 0x18) = puVar6;
                puVar9[9] = psVar3;
                break;
              }
            }
LAB_140093400:
            uVar2 = 0xc000009a;
          }
        }
        else {
          PepPlatformIdleVetoEvent(4,'\x01');
        }
        break;
      }
      if (PepPcieGeneratedConstraintEnabled != '\0') {
        puVar6 = (undefined8 *)puVar9[2];
LAB_140093223:
        if (puVar6 != puVar9 + 2) {
          lVar5 = puVar6[3];
          iVar1 = RtlCompareUnicodeString(lVar5 + 0x20,param_1,1);
          if (iVar1 != 0) goto code_r0x00014009324f;
          *(undefined4 *)(lVar5 + 0x50) = 2;
          if (puVar6[6] == 0) {
            psVar3 = (short *)ExAllocatePool2(0x40,0x38,0x49504550);
            if ((psVar3 != (short *)0x0) &&
               (lVar4 = ExAllocatePool2(0x40,0x20,0x49504550), lVar4 != 0)) {
              PepPcieGetVendorDeviceId(lVar5);
              psVar3[0xc] = 0;
              psVar3[0x14] = 0;
              psVar3[0x15] = 0;
              psVar3[0x16] = 0;
              psVar3[0x17] = 0;
              *(undefined8 *)(psVar3 + 8) = param_2;
              uVar2 = RtlUnicodeStringInitEx(psVar3,*(short **)(lVar5 + 0x28));
              lVar5 = ExAllocatePool2(0x40,(ulonglong)PepNumPlatformStates << 3,0x49504550);
              puVar6[7] = lVar5;
              if (lVar5 != 0) {
                uVar8 = 0;
                if (PepNumPlatformStates != 0) {
                  do {
                    *(undefined4 *)(puVar6[7] + 4 + uVar8 * 8) = 0;
                    *(undefined4 *)(puVar6[7] + uVar8 * 8) = 1;
                    uVar7 = (int)uVar8 + 1;
                    uVar8 = (ulonglong)uVar7;
                  } while (uVar7 < PepNumPlatformStates);
                }
                *(undefined8 **)(lVar4 + 8) = puVar6;
                *(longlong *)(psVar3 + 0x18) = lVar4;
                puVar6[6] = psVar3;
                if (((*param_3 & 0xffee000000000000) == 0) || (*(char *)(puVar6 + 4) != '\0')) {
                  if ((puVar9[0x14] & 0xffee000000000000) == 0xffee000000000000) {
                    MicrosoftTelemetryAssertTriggeredMsgKM
                              (
                              "PepPcieFindDeviceMatch: Another endpoint register and trying to update constraint on same root port along with storport."
                              );
                  }
                  if ((*(char *)(puVar6 + 4) != '\0') && (((ulonglong)puVar6[8] >> 9 & 1) == 0)) {
                    puVar6[8] = puVar6[8] | 0x200;
                    LOCK();
                    *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + 1;
                    UNLOCK();
                    PepPcieQueueConstraintWork((longlong)puVar9,1);
                  }
                }
                else {
                  puVar9[0x14] = puVar9[0x14] | 0xffee000000000000;
                  PepPcieQueueConstraintWork((longlong)puVar9,2);
                  uVar8 = 0;
                  if (PepNumPlatformStates != 0) {
                    do {
                      *(undefined4 *)(puVar6[7] + 4 + uVar8 * 8) = 1;
                      *(undefined4 *)(puVar6[7] + uVar8 * 8) = 1;
                      uVar7 = (int)uVar8 + 1;
                      uVar8 = (ulonglong)uVar7;
                    } while (uVar7 < PepNumPlatformStates);
                  }
                  *(undefined8 *)(puVar6[6] + 0x20) = puVar6[7];
                }
                goto LAB_1400933f8;
              }
            }
            goto LAB_140093400;
          }
          PepPlatformIdleVetoEvent(4,'\x01');
        }
      }
LAB_1400933f8:
    }
  }
  ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  if ((psVar3 == (short *)0x0) && (PepPcieGeneratedConstraintRCiEPEnabled != '\0')) {
    psVar3 = PepPcieFindRCiEPMatch(param_1,param_2,param_3);
  }
  if (((uVar2 != 0) && (MicrosoftTelemetryAssertTriggeredNoArgsKM(), (int)uVar2 < 0)) &&
     (psVar3 != (short *)0x0)) {
    if (*(longlong *)(psVar3 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(psVar3 + 0x10),0x49504550);
      psVar3[0x10] = 0;
      psVar3[0x11] = 0;
      psVar3[0x12] = 0;
      psVar3[0x13] = 0;
    }
    if (*(longlong *)(psVar3 + 0x18) != 0) {
      ExFreePoolWithTag(*(longlong *)(psVar3 + 0x18),0x49504550);
      psVar3[0x18] = 0;
      psVar3[0x19] = 0;
      psVar3[0x1a] = 0;
      psVar3[0x1b] = 0;
    }
    ExFreePoolWithTag(psVar3,0x49504550);
    psVar3 = (short *)0x0;
  }
  return psVar3;
code_r0x00014009324f:
  puVar6 = (undefined8 *)*puVar6;
  goto LAB_140093223;
}



===== PepPcieFindRCiEPMatch @ 1400936f8 =====

short * PepPcieFindRCiEPMatch(undefined8 param_1,undefined8 param_2,ulonglong *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  psVar4 = (short *)0x0;
  uVar3 = 0;
  lVar5 = 0;
  uVar10 = 0;
  uVar9 = 4;
  ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
  for (puVar7 = PepPcieRCiEPList; (undefined8 **)puVar7 != &PepPcieRCiEPList;
      puVar7 = (undefined8 *)*puVar7) {
    lVar6 = puVar7[2];
    iVar2 = RtlCompareUnicodeString(lVar6 + 0x20,param_1,1);
    if (iVar2 == 0) {
      *(undefined4 *)(lVar6 + 0x50) = 2;
      if (puVar7[4] == 0) {
        psVar4 = (short *)ExAllocatePool2(0x40,0x38,0x49504550);
        if (psVar4 != (short *)0x0) {
          lVar5 = ExAllocatePool2(0x40,0x20,0x49504550);
          if (lVar5 != 0) {
            *(undefined8 *)(psVar4 + 8) = param_2;
            psVar4[0xc] = 0;
            psVar4[0x14] = 0;
            psVar4[0x15] = 0;
            psVar4[0x16] = 0;
            psVar4[0x17] = 0;
            uVar3 = RtlUnicodeStringInitEx(psVar4,*(short **)(lVar6 + 0x28));
            lVar6 = ExAllocatePool2(0x40,(ulonglong)PepNumPlatformStates << 3,0x49504550);
            *(longlong *)(psVar4 + 0x10) = lVar6;
            if (lVar6 != 0) {
              cVar1 = IsPepPcieRCiEPInExceptionList((longlong)puVar7);
              if (cVar1 == '\0') goto LAB_140093866;
              puVar7[6] = puVar7[6] | 1;
              uVar8 = 0;
              uVar9 = 1;
              uVar10 = 1;
              goto LAB_14009384a;
            }
          }
        }
        uVar3 = 0xc000009a;
      }
      else {
        PepPlatformIdleVetoEvent(4,'\x01');
      }
      break;
    }
  }
LAB_1400938c2:
  ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
  if (uVar3 != 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    if (((int)uVar3 < 0) && (psVar4 != (short *)0x0)) {
      if (*(longlong *)(psVar4 + 0x10) != 0) {
        ExFreePoolWithTag(*(longlong *)(psVar4 + 0x10),0x49504550);
        psVar4[0x10] = 0;
        psVar4[0x11] = 0;
        psVar4[0x12] = 0;
        psVar4[0x13] = 0;
      }
      if (lVar5 != 0) {
        ExFreePoolWithTag(lVar5,0x49504550);
      }
      ExFreePoolWithTag(psVar4,0x49504550);
      psVar4 = (short *)0x0;
    }
  }
  return psVar4;
LAB_14009384a:
  if ((uint)param_3[1] <= (uint)uVar8) goto LAB_140093866;
  if (*(int *)(param_3[uVar8 + 2] + 0x1c) == 1) {
    uVar10 = 0;
    puVar7[6] = puVar7[6] | 2;
    goto LAB_140093866;
  }
  uVar8 = (ulonglong)((uint)uVar8 + 1);
  goto LAB_14009384a;
LAB_140093866:
  if ((*param_3 & 0xffee000000000000) != 0) {
    puVar7[6] = puVar7[6] | 4;
    uVar9 = 1;
    uVar10 = 1;
  }
  if (PepNumPlatformStates != 0) {
    lVar6 = 0;
    uVar8 = (ulonglong)PepNumPlatformStates;
    do {
      *(undefined4 *)(lVar6 + 4 + *(longlong *)(psVar4 + 0x10)) = uVar10;
      *(undefined4 *)(lVar6 + *(longlong *)(psVar4 + 0x10)) = uVar9;
      lVar6 = lVar6 + 8;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  puVar7[3] = *(undefined8 *)(psVar4 + 0x10);
  *(undefined8 **)(lVar5 + 0x18) = puVar7;
  *(longlong *)(psVar4 + 0x18) = lVar5;
  puVar7[4] = psVar4;
  goto LAB_1400938c2;
}



===== PepPcieFindRootPortFromEndpointPdo @ 140093958 =====

undefined8 * PepPcieFindRootPortFromEndpointPdo(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)0x0;
  ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  puVar2 = PepPcieRootPortList;
  do {
    if ((undefined8 **)puVar2 == &PepPcieRootPortList) {
      ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
      return puVar3;
    }
    for (puVar1 = (undefined8 *)puVar2[2]; puVar1 != puVar2 + 2; puVar1 = (undefined8 *)*puVar1) {
      if (*(longlong *)(puVar1[3] + 0x10) == param_1) {
        puVar3 = puVar2;
        break;
      }
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== PepPcieGetDeviceFriendlyName @ 1400939dc =====

void PepPcieGetDeviceFriendlyName(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  int local_res18 [2];
  
  local_res18[0] = 0;
  RtlInitUnicodeString(param_2,L"FriendlyNameNotFound");
  lVar4 = 2;
  uVar5 = 9;
  do {
    lVar3 = lVar4;
    iVar1 = IoGetDeviceProperty(param_1,uVar5,0,0,local_res18);
    uVar2 = 0;
    if (iVar1 == -0x3fffffdd) {
      uVar2 = uVar5;
    }
    lVar4 = lVar3 + -1;
    uVar5 = uVar2;
  } while (lVar4 != 0);
  if (local_res18[0] != 0) {
    lVar4 = ExAllocatePool2((int)lVar3 + 0x3f,local_res18[0],0x49504550);
    if (lVar4 != 0) {
      iVar1 = IoGetDeviceProperty(param_1,uVar2,local_res18[0],lVar4,local_res18);
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar4,0);
      }
      else {
        RtlInitUnicodeString(param_2,lVar4);
      }
    }
  }
  return;
}



===== PepPcieInitRootPortRangeTable @ 140093adc =====

undefined8 PepPcieInitRootPortRangeTable(void)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  uint uVar7;
  undefined **ppuVar8;
  
  if ((PepSubsystemSoCInfo == (int *)0x0) && (Pepv2SubsystemSocInfo == (int *)0x0)) {
    PepPciePchLtrOvrMboxEnabled = 0;
    PepPcieDiscretePchConnectedRootPortBdfRange = (undefined *)0x0;
    PepPciePchConnectedRootPortBdfRange = (undefined *)0x0;
    PepPcieLtrOvrPchMbContext = (undefined **)0x0;
    PepPcieSoCCpuConnectedRootPortInfo = (int *)0x0;
    return 0xc0000001;
  }
  iVar3 = 0;
  iVar4 = 0;
  piVar6 = (int *)0x0;
  if (PepSubsystemSoCInfo == (int *)0x0) {
    if (Pepv2SubsystemSocInfo != (int *)0x0) {
      piVar6 = *(int **)(Pepv2SubsystemSocInfo + 2);
      piVar1 = Pepv2SubsystemSocInfo;
      goto LAB_140093b2e;
    }
  }
  else {
    piVar6 = *(int **)(PepSubsystemSoCInfo + 10);
    piVar1 = PepSubsystemSoCInfo;
LAB_140093b2e:
    iVar4 = piVar1[1];
    iVar3 = *piVar1;
  }
  uVar7 = 0;
  PepPcieSoCCpuConnectedRootPortInfo = &PepPcieCpuConnectedRootPortInfo;
  while ((iVar3 != *PepPcieSoCCpuConnectedRootPortInfo ||
         (iVar4 != PepPcieSoCCpuConnectedRootPortInfo[1]))) {
    uVar7 = uVar7 + 1;
    PepPcieSoCCpuConnectedRootPortInfo = PepPcieSoCCpuConnectedRootPortInfo + 10;
    if (0x15 < uVar7) {
      PepPciePchLtrOvrMboxEnabled = 0;
      PepPcieDiscretePchConnectedRootPortBdfRange = (undefined *)0x0;
      PepPciePchConnectedRootPortBdfRange = (undefined *)0x0;
      PepPcieLtrOvrPchMbContext = (undefined **)0x0;
      PepPcieSoCCpuConnectedRootPortInfo = (int *)0x0;
      return 0xc0000001;
    }
  }
  uVar2 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
  iVar4 = *piVar6;
  uVar7 = 0;
  if ((int)uVar2 == 0) {
    ppuVar5 = &PepPciePchConnectedRootPortRangeList;
    while (iVar4 != *(int *)*ppuVar5) {
      uVar7 = uVar7 + 1;
      ppuVar5 = ppuVar5 + 3;
      if (0x10 < uVar7) {
        PepPciePchLtrOvrMboxEnabled = 0;
        PepPcieDiscretePchConnectedRootPortBdfRange = (undefined *)0x0;
        PepPciePchConnectedRootPortBdfRange = (undefined *)0x0;
        PepPcieLtrOvrPchMbContext = (undefined **)0x0;
        PepPcieSoCCpuConnectedRootPortInfo = (int *)0x0;
        return 0xc0000001;
      }
    }
    PepPcieSoCPchConnectedRootPortInfo = ppuVar5;
    if (*(char *)(ppuVar5 + 2) != '\0') {
      ppuVar8 = &PepPcieLtrOvrRplSMtlPcMboxMap;
      uVar7 = 0;
      ppuVar5 = &PepPcieLtrOvrRplSMtlPcMboxMap;
      do {
        if (*(int *)*ppuVar5 == iVar4) goto LAB_140093c43;
        uVar7 = uVar7 + 1;
        ppuVar5 = ppuVar5 + 3;
      } while (uVar7 < 4);
    }
  }
  else {
    ppuVar5 = &PepPciePchConnectedRootPortRangeListV1;
    while (iVar4 != *(int *)*ppuVar5) {
      uVar7 = uVar7 + 1;
      ppuVar5 = ppuVar5 + 3;
      if (0x13 < uVar7) {
        PepPciePchLtrOvrMboxEnabled = 0;
        PepPcieDiscretePchConnectedRootPortBdfRange = (undefined *)0x0;
        PepPciePchConnectedRootPortBdfRange = (undefined *)0x0;
        PepPcieLtrOvrPchMbContext = (undefined **)0x0;
        PepPcieSoCCpuConnectedRootPortInfo = (int *)0x0;
        return 0xc0000001;
      }
    }
    PepPcieSoCPchConnectedRootPortInfo = ppuVar5;
    if (*(char *)(ppuVar5 + 2) != '\0') {
      ppuVar8 = &PepPcieLtrOvrRplSMtlPcMboxMapV1;
      uVar7 = 0;
      ppuVar5 = &PepPcieLtrOvrRplSMtlPcMboxMapV1;
      do {
        if (*(int *)*ppuVar5 == iVar4) goto LAB_140093c43;
        uVar7 = uVar7 + 1;
        ppuVar5 = ppuVar5 + 3;
      } while (uVar7 < 5);
    }
  }
LAB_140093c5b:
  if (PepSubsystemDiscretePchId != 0) {
    if (PepSubsystemDiscretePchId != *(int *)PepPcieDiscretePchRootPortRangeList) {
      PepPcieSoCCpuConnectedRootPortInfo = (int *)0x0;
      PepPcieLtrOvrPchMbContext = (undefined **)0x0;
      PepPciePchConnectedRootPortBdfRange = (undefined *)0x0;
      PepPcieDiscretePchConnectedRootPortBdfRange = (undefined *)0x0;
      PepPciePchLtrOvrMboxEnabled = 0;
      return 0xc0000001;
    }
    PepPcieDiscretePchConnectedRootPortBdfRange =
         PTR_PepPciDefaultDiscretePchRootPortBdfRange_140062758;
  }
  PepPciePchConnectedRootPortBdfRange = PepPcieSoCPchConnectedRootPortInfo[1];
  return 0;
LAB_140093c43:
  PepPciePchLtrOvrMboxEnabled = 1;
  PepPcieLtrOvrPchMbContext = ppuVar8 + (ulonglong)uVar7 * 3;
  goto LAB_140093c5b;
}



===== PepPcieInitializeHelper @ 140093ca4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepPcieInitializeHelper(void)

{
  DAT_140087e08 = &PepPcieDeviceMapList;
  PepPcieDeviceMapList = &PepPcieDeviceMapList;
  DAT_140087e28 = &PepPcieRootPortList;
  PepPcieRootPortList = &PepPcieRootPortList;
  DAT_140087e18 = &PepPcieDiagDeviceMapList;
  PepPcieDiagDeviceMapList = &PepPcieDiagDeviceMapList;
  DAT_140087e48 = &PepPcieRCiEPList;
  PepPcieRCiEPList = &PepPcieRCiEPList;
  _PepPcieDeviceMapListLock = 0;
  _PepPcieRootPortListLock = 0;
  _PepPcieDiagDeviceMapListLock = 0;
  _PepPcieRCiEPListLock = 0;
  return;
}



===== PepPcieNonPoFxStorPortPnpNotifyInterfaceChangeCb @ 140093d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PepPcieNonPoFxStorPortPnpNotifyInterfaceChangeCb(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 local_res18;
  longlong local_res20;
  
  local_res18 = 0;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  local_res20 = 0;
  uVar4 = 0;
  if (PepPcieGeneratedConstraintEnabled != '\0') {
    lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
    }
    if (lVar2 == 0) {
      puVar5 = &local_res18;
      iVar1 = IoGetDeviceObjectPointer(*(undefined8 *)(param_1 + 0x28),0x1f0000,&local_res20);
      if (-1 < iVar1) {
        lVar2 = IoGetDeviceAttachmentBaseRef(local_res18);
        puVar3 = PepPcieFindRootPortFromEndpointPdo(lVar2);
        if (puVar3 == (undefined8 *)0x0) {
          MicrosoftTelemetryAssertTriggeredMsgKM
                    (
                    "NonPoFxStorPortPnpNotifyInterfaceChangeCb: No parent root port found for NonPoFx stor port miniport device."
                    );
        }
        else if ((*(byte *)(puVar3 + 0x14) & 1) == 0) {
          PepPcieQueueConstraintWork((longlong)puVar3,2);
          uVar4 = 1;
        }
        PepDiagLogNonPoFxStorportRpConstraint(lVar2,(longlong)puVar3,uVar4,puVar5);
      }
      if (local_res20 != 0) {
        ObfDereferenceObject();
      }
    }
  }
  return 0;
}



===== PepPciePreparePcieDevice @ 140093e44 =====

int PepPciePreparePcieDevice(undefined8 *param_1,longlong param_2,char *param_3)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 **ppuVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  ushort *puVar15;
  char cVar16;
  bool bVar17;
  uint local_res20 [2];
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  uint local_68;
  uint *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44 [3];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar15 = (ushort *)0x0;
  cVar16 = '\0';
  iVar4 = 0;
  for (ppuVar11 = (undefined8 **)PepPcieDeviceMapList; ppuVar11 != &PepPcieDeviceMapList;
      ppuVar11 = (undefined8 **)*ppuVar11) {
    if (ppuVar11[2] == (undefined8 *)param_1[2]) goto LAB_140094374;
  }
  local_50 = &local_48;
  local_res20[0] = 0xffffffff;
  local_58 = local_44;
  local_48 = 0;
  local_60 = local_res20;
  local_44[0] = 0;
  local_68 = 4;
  iVar3 = IoGetDevicePropertyData(param_1[2],&DEVPKEY_PciDevice_DeviceType,0,0);
  if ((iVar3 != 0) && (iVar3 != -0x3fffffcc)) {
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("PepPcieQueryPcieDeviceType device property query failed");
  }
  uVar6 = local_res20[0];
  if ((PepPcieCollectPcieHierarchyDiagnostic != '\0') && (param_2 != 0)) {
    *(uint *)(param_2 + 0x30) = local_res20[0];
  }
  if ((0xe < local_res20[0]) || ((0x7fddU >> (local_res20[0] & 0x1f) & 1) == 0)) goto LAB_140094374;
  cVar16 = '\x01';
  puVar7 = (undefined8 *)ExAllocatePool2(0x40,0x58,0x49504550);
  puVar14 = auStack_88;
  if (puVar7 != (undefined8 *)0x0) {
    uVar1 = *(ushort *)*param_1 + 2;
    if (uVar1 < *(ushort *)*param_1) {
LAB_14009434c:
      iVar4 = -0x3fffff6b;
      goto LAB_140094351;
    }
    lVar8 = ExAllocatePool2(0x40,uVar1,0x49504550);
    puVar7[5] = lVar8;
    if (lVar8 != 0) {
      puVar15 = (ushort *)(puVar7 + 4);
      *(ushort *)((longlong)puVar7 + 0x22) = uVar1;
      *puVar15 = 0;
      uVar9 = RtlUnicodeStringCopy(puVar15,(ushort *)*param_1);
      iVar4 = (int)uVar9;
      if (iVar4 < 0) {
        ExFreePoolWithTag(puVar7[5],0x49504550);
        puVar14 = auStack_88;
        puVar15 = (ushort *)0x0;
        goto LAB_140094351;
      }
      PepPcieGetDeviceFriendlyName(param_1[2],puVar7 + 8);
      if (uVar6 != 0xffffffff) {
        PepPcieQueryPcieDeviceLocation
                  (param_1[2],(undefined4 *)((longlong)puVar7 + 0x34),(uint *)(puVar7 + 7));
      }
      local_38 = *(undefined4 *)puVar15;
      uStack_34 = *(undefined4 *)((longlong)puVar7 + 0x24);
      uStack_30 = *(undefined4 *)(puVar7 + 5);
      uStack_2c = *(undefined4 *)((longlong)puVar7 + 0x2c);
      puVar7[2] = param_1[2];
      puVar7[3] = param_1[3];
      *(uint *)(puVar7 + 6) = uVar6;
      local_50 = (undefined4 *)
                 (CONCAT44(local_50._4_4_,*(uint *)(puVar7 + 7) >> 5) & 0xffffffff00000007);
      local_58 = (undefined4 *)(CONCAT44(local_58._4_4_,*(uint *)(puVar7 + 7)) & 0xffffffff0000001f)
      ;
      local_60 = (uint *)CONCAT44(local_60._4_4_,*(undefined4 *)((longlong)puVar7 + 0x34));
      local_68 = uVar6;
      *(undefined4 *)(puVar7 + 10) = 1;
      DbgPrintEx(0x92,3,
                 "INTELPEP: PepPciePreparePcieDevice Name:(%wZ), Device Type: %d, Location Bus: %d, Device: %d, Function:%d \n"
                 ,&local_38);
      ExAcquirePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
      if ((undefined8 **)*DAT_140087e08 != &PepPcieDeviceMapList) {
LAB_140094345:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar14 = auStack_80;
        goto LAB_14009434c;
      }
      *puVar7 = &PepPcieDeviceMapList;
      puVar7[1] = DAT_140087e08;
      *DAT_140087e08 = puVar7;
      DAT_140087e08 = puVar7;
      ExReleasePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
      if (uVar6 == 8) {
        puVar10 = (undefined8 *)ExAllocatePool2(0x40,0xc0,0x49504550);
        puVar15 = (ushort *)0x0;
        if (puVar10 != (undefined8 *)0x0) {
          puVar13 = puVar10 + 2;
          puVar10[3] = puVar13;
          *puVar13 = puVar13;
          *(undefined4 *)(puVar10 + 8) = 0;
          *(undefined4 *)(puVar10 + 0x15) = 0;
          puVar10[4] = 0;
          puVar10[7] = 0;
          puVar10[9] = 0;
          puVar10[5] = puVar7;
          puVar10[10] = 1;
          uVar5 = PepPcieGetRootPortLocation
                            ((longlong)puVar7,(undefined1 *)((longlong)puVar10 + 0x34));
          *(undefined4 *)(puVar10 + 6) = uVar5;
          puVar10[0xb] = 0;
          lVar8 = PepFindDeviceMatch((ushort *)(puVar7 + 4));
          if ((lVar8 != 0) && (*(char *)(lVar8 + 0x19) != '\0')) {
            puVar10[0xb] = *(undefined8 *)(lVar8 + 0x20);
          }
          ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
          if ((undefined8 *)*DAT_140087e28 == &PepPcieRootPortList) {
            *puVar10 = &PepPcieRootPortList;
            puVar10[1] = DAT_140087e28;
            *DAT_140087e28 = puVar10;
            DAT_140087e28 = puVar10;
            ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
            if (PepPcieGeneratedConstraintEnabled != '\0') {
              KeInitializeEvent(puVar10 + 0xc,0,0);
              puVar10[0x12] = puVar10;
              puVar10[0x11] = PepPcieUpdateConstraintWorker;
              puVar10[0xf] = 0;
            }
LAB_1400941c8:
            DbgPrintEx(0x92,3,"INTELPEP: PepPciePreparePcieDevice RP (%wZ) \n",*param_1);
LAB_140094374:
            bVar17 = PepPcieCollectPcieHierarchyDiagnostic != '\0';
            *param_3 = cVar16;
            if ((bVar17) && (param_2 != 0)) {
              if (cVar16 == '\0') {
                uVar6 = *(uint *)(param_2 + 0x48) | 8;
              }
              else {
                uVar6 = *(uint *)(param_2 + 0x48) | 4;
              }
              *(uint *)(param_2 + 0x48) = uVar6;
            }
            return iVar4;
          }
          goto LAB_140094345;
        }
      }
      else {
        if ((uVar6 - 2 < 2) || (uVar6 - 9 < 2)) {
          puVar10 = (undefined8 *)param_1[3];
          puVar15 = (ushort *)0x0;
          ExAcquirePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
          while( true ) {
            ppuVar11 = (undefined8 **)PepPcieDeviceMapList;
            while( true ) {
              puVar13 = (undefined8 *)0x0;
              if (ppuVar11 == &PepPcieDeviceMapList) goto LAB_14009430c;
              puVar13 = ppuVar11[2];
              if (puVar13 == puVar10) break;
              ppuVar11 = (undefined8 **)*ppuVar11;
            }
            if (*(int *)(ppuVar11 + 6) == 8) break;
            puVar10 = ppuVar11[3];
          }
LAB_14009430c:
          ExReleasePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
          puVar14 = auStack_88;
          if (puVar13 == (undefined8 *)0x0) {
            iVar4 = -0x3fffffcc;
          }
          else {
            uVar12 = PepPcieCreateAndInsertEndPointDevice
                               (param_1,(longlong)puVar13,(longlong)puVar7);
            puVar14 = auStack_88;
            iVar4 = (int)uVar12;
            if ((iVar4 == 0) || (-1 < iVar4)) goto LAB_140094374;
          }
          goto LAB_140094351;
        }
        if ((uVar6 & 0xfffffffb) != 0) goto LAB_140094374;
        puVar10 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x49504550);
        puVar15 = (ushort *)0x0;
        if (puVar10 != (undefined8 *)0x0) {
          puVar10[3] = 0;
          puVar10[4] = 0;
          puVar10[2] = puVar7;
          puVar10[5] = 0;
          lVar8 = PepFindDeviceMatch((ushort *)(puVar7 + 4));
          if ((lVar8 != 0) && (*(char *)(lVar8 + 0x19) != '\0')) {
            puVar10[5] = *(undefined8 *)(lVar8 + 0x20);
          }
          ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
          if ((undefined8 *)*DAT_140087e48 == &PepPcieRCiEPList) {
            *puVar10 = &PepPcieRCiEPList;
            puVar10[1] = DAT_140087e48;
            *DAT_140087e48 = puVar10;
            DAT_140087e48 = puVar10;
            ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
            goto LAB_1400941c8;
          }
          goto LAB_140094345;
        }
      }
    }
  }
  puVar14 = auStack_88;
  puVar15 = (ushort *)0x0;
  iVar4 = -0x3fffff66;
LAB_140094351:
  *(ushort **)(puVar14 + 0x20) = puVar15;
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar14 + -8) = 0x14009436b;
  KeBugCheckEx(0xa0,0x100,param_1,(longlong)iVar4);
}



===== PepPcieQueryPcieDeviceLocation @ 1400943c0 =====

void PepPcieQueryPcieDeviceLocation(undefined8 param_1,undefined4 *param_2,uint *param_3)

{
  int iVar1;
  undefined4 local_res20 [2];
  uint local_28;
  undefined4 local_24 [3];
  
  local_28 = 0;
  local_res20[0] = 0;
  local_24[0] = 0xffffffff;
  iVar1 = IoGetDeviceProperty(param_1,0xe,4,local_24,local_res20);
  if (iVar1 != 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    if (iVar1 < 0) goto LAB_14009447c;
  }
  iVar1 = IoGetDeviceProperty(param_1,0x10,4,&local_28,local_res20);
  if (iVar1 != 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    if (iVar1 < 0) goto LAB_14009447c;
  }
  *param_3 = (local_28 >> 0x10 & 0x1f ^ *param_3 & 0xffffffe0) & 0xffffff1f | (local_28 & 7) << 5;
  if (-1 < iVar1) {
    *param_2 = local_24[0];
    return;
  }
LAB_14009447c:
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xa0,0x101,param_1,(longlong)iVar1,0);
}



===== PepPcieReEvalRpConstraints @ 1400944c0 =====

void PepPcieReEvalRpConstraints(void)

{
  uint uVar1;
  undefined8 *puVar2;
  
  if (PepPcieGeneratedConstraintEnabled != '\0') {
    ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock);
    for (puVar2 = PepPcieRootPortList; (undefined8 **)puVar2 != &PepPcieRootPortList;
        puVar2 = (undefined8 *)*puVar2) {
      if ((*(uint *)(puVar2 + 0x14) & 0x1800) != 0) {
        LOCK();
        uVar1 = *(uint *)(puVar2 + 0x13);
        *(uint *)(puVar2 + 0x13) = 0;
        UNLOCK();
        if ((uVar1 & 3) != 0) {
          puVar2[0x14] = puVar2[0x14] & 0xffffffffffffe7ff | 0x80000;
          PepPcieQueueConstraintWork((longlong)puVar2,uVar1);
        }
      }
    }
    ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  }
  return;
}



===== PepPcieRegisterCallbacks @ 140094564 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PepPcieRegisterCallbacks(void)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_res10 [3];
  
  local_res8 = 0;
  local_res10[0] = 0;
  KeInitializeEvent(&InitialPlatformStateRegistered,0,0);
  iVar1 = ExSubscribeWnfStateChange
                    (&local_res8,&WNF_PO_DRIPS_DEVICE_CONSTRAINTS_REGISTERED,1,0,
                     PepPcieWnfDripsDeviceConstraintRegistredCb,0);
  if (-1 < iVar1) {
    _DAT_140087ef8 = 0;
    _PepPcieD3ColdUpdateWorkItem = 0;
    _PepPcieD3ColdUpdateWorkerLock = 0;
    _DAT_140087ef0 = PepPcieD3ColdUpdateWorker;
    iVar1 = ExSubscribeWnfStateChange
                      (local_res10,&WNF_PO_D3COLD_STATE_CHANGED,1,0,PepPcieWnfPcieD3ColdUpdateCb,0);
    if (-1 < iVar1) {
      PepPcieRegisterNonPoFxStorportPnpNotifyInterfaceChange();
    }
  }
  return iVar1;
}



===== PepPcieRegisterNonPoFxStorportPnpNotifyInterfaceChange @ 140094638 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PepPcieRegisterNonPoFxStorportPnpNotifyInterfaceChange(void)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar1 = PepWdfDevice;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,PepWdfDevice,PTR__WDF_PEP_FDO_DATA_TYPE_INFO_140034018);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,uVar1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar3);
  IoRegisterPlugPlayNotification
            (2,1,&GUID_STORPORT_NON_POFX_MINIPORT,uVar3,
             PepPcieNonPoFxStorPortPnpNotifyInterfaceChangeCb,uVar1,lVar2 + 0x18);
  return;
}



===== PepPcieUnregisterDevice @ 1400946f8 =====

void PepPcieUnregisterDevice(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  plVar1 = *(longlong **)(param_1 + 0x30);
  lVar2 = plVar1[1];
  lVar3 = *plVar1;
  lVar4 = plVar1[3];
  if (lVar2 == 0) {
    if (lVar3 == 0) {
      if (lVar4 == 0) goto LAB_14009475e;
      lVar5 = *(longlong *)(lVar4 + 0x10);
    }
    else {
      lVar5 = *(longlong *)(lVar3 + 0x28);
    }
  }
  else {
    lVar5 = *(longlong *)(lVar2 + 0x18);
  }
  if (lVar5 != 0) {
    *(undefined4 *)(lVar5 + 0x50) = 4;
  }
LAB_14009475e:
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x10), lVar5 != 0)) {
    ExFreePoolWithTag(lVar5,0x49504550);
    *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x10) = 0;
  }
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0x49504550);
  *(undefined8 *)(param_1 + 0x30) = 0;
  ExFreePoolWithTag(param_1,0x49504550);
  if (lVar3 != 0) {
    *(undefined8 *)(lVar3 + 0x48) = 0;
  }
  if (lVar2 != 0) {
    *(undefined8 *)(lVar2 + 0x30) = 0;
  }
  if (lVar4 != 0) {
    *(undefined8 *)(lVar4 + 0x20) = 0;
  }
  ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
  return;
}



===== PepPcieUpdateConstraintWorker @ 140094810 =====

void PepPcieUpdateConstraintWorker(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 local_res10;
  longlong local_38;
  undefined *local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (((PepPcieGeneratedConstraintEnabled != '\0') && (param_1 != 0)) &&
     (lVar2 = *(longlong *)(param_1 + 0x28), lVar2 != 0)) {
    local_28 = *(undefined4 *)(lVar2 + 0x20);
    uStack_24 = *(undefined4 *)(lVar2 + 0x24);
    uStack_20 = *(undefined4 *)(lVar2 + 0x28);
    uStack_1c = *(undefined4 *)(lVar2 + 0x2c);
    DbgPrintEx(0x92,3,
               "INTELPEP: PepPcieUpdateConstraintWorker WAIT Started for device name:(%wZ) \n",
               &local_28);
    local_38 = param_1 + 0x60;
    local_res10 = 0xffffffffee1e5d00;
    local_30 = &InitialPlatformStateRegistered;
    uVar5 = 2;
    iVar3 = KeWaitForMultipleObjects(2,&local_38,0,0,0,0,&local_res10,0);
    if (iVar3 == 0x102) {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (uVar5,(int)param_1,0x102,"PepPcieUpdateConstraintWorker fail due to timeout");
      *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x800;
    }
    else {
      local_18 = *(undefined4 *)(lVar2 + 0x20);
      uStack_14 = *(undefined4 *)(lVar2 + 0x24);
      uStack_10 = *(undefined4 *)(lVar2 + 0x28);
      uStack_c = *(undefined4 *)(lVar2 + 0x2c);
      DbgPrintEx(0x92,3,
                 "INTELPEP: PepPcieUpdateConstraintWorker WAIT ended for device name:(%wZ) \n",
                 &local_18);
      if (*(int *)(lVar2 + 0x50) == 3) {
        do {
          LOCK();
          uVar1 = *(uint *)(param_1 + 0x98);
          *(uint *)(param_1 + 0x98) = 0x80000000;
          UNLOCK();
          if ((uVar1 & 2) != 0) {
            PepPcieClearRpConstraint(param_1);
          }
          if ((uVar1 & 1) != 0) {
            PepPcieUpdateRpConstraint(param_1);
          }
          iVar4 = -0x80000000;
          LOCK();
          iVar3 = *(int *)(param_1 + 0x98);
          if (iVar3 == -0x80000000) {
            *(int *)(param_1 + 0x98) = 0;
          }
          else {
            iVar4 = iVar3;
          }
          UNLOCK();
        } while (iVar4 != -0x80000000);
      }
      else {
        *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x1000;
      }
    }
  }
  return;
}



===== PepPcieUpdateRpConstraint @ 14009497c =====

int PepPcieUpdateRpConstraint(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (param_1 != 0) {
    lVar2 = *(longlong *)(param_1 + 0x48);
    if (lVar2 == 0) {
      *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x2000;
    }
    else {
      lVar3 = *(longlong *)(lVar2 + 0x10);
      if (lVar3 == 0) {
        *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x4000;
      }
      else {
        lVar4 = *(longlong *)(param_1 + 0x28);
        if (lVar4 != 0) {
          if (*(int *)(lVar4 + 0x50) == 3) {
            if (PepDripsIndex == 0xffffffff) {
              *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x10000;
            }
            else {
              LOCK();
              piVar1 = (int *)(param_1 + 0x40);
              iVar5 = *piVar1;
              *piVar1 = *piVar1;
              UNLOCK();
              if (iVar5 < 1) {
                LOCK();
                piVar1 = (int *)(param_1 + 0x40);
                iVar5 = *piVar1;
                *piVar1 = *piVar1;
                UNLOCK();
                if (iVar5 != 0) {
                  return 0;
                }
                iVar5 = PoFxSetTargetDripsDevicePowerState(lVar3,0);
                if (iVar5 != 0) {
                  MicrosoftTelemetryAssertTriggeredMsgKM
                            (
                            "PoFxSetTargetDripsDevicePowerState API failed to apply default pep constraints."
                            );
                }
                uVar6 = (ulonglong)PepDripsIndex;
                if (iVar5 != 0) {
                  *(undefined4 *)(*(longlong *)(lVar2 + 0x20) + uVar6 * 8) = 4;
                  *(undefined4 *)(*(longlong *)(lVar2 + 0x20) + 4 + uVar6 * 8) = 1;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + uVar6 * 8) = 4;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 4 + uVar6 * 8) = 1;
                  *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x40;
                  return iVar5;
                }
                pcVar7 = 
                "INTELPEP: PepPcieUpdateRpConstraint D0:F1 constraint updated for device name:(%wZ) \n"
                ;
                *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 4 + uVar6 * 8) = 1;
                *(undefined4 *)(*(longlong *)(param_1 + 0x38) + uVar6 * 8) = 1;
                *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x10;
              }
              else {
                iVar5 = PoFxSetTargetDripsDevicePowerState(lVar3,4);
                if (iVar5 != 0) {
                  MicrosoftTelemetryAssertTriggeredMsgKM
                            ("PoFxSetTargetDripsDevicePowerState API failed to deepens constraints."
                            );
                }
                uVar6 = (ulonglong)PepDripsIndex;
                if (iVar5 != 0) {
                  *(undefined4 *)(*(longlong *)(lVar2 + 0x20) + uVar6 * 8) = 1;
                  *(undefined4 *)(*(longlong *)(lVar2 + 0x20) + 4 + uVar6 * 8) = 1;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + uVar6 * 8) = 1;
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 4 + uVar6 * 8) = 1;
                  *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x20;
                  return iVar5;
                }
                pcVar7 = 
                "INTELPEP: PepPcieUpdateRpConstraint D3 constraint updated for device name:(%wZ) \n"
                ;
                *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 4 + uVar6 * 8) = 1;
                *(undefined4 *)(*(longlong *)(param_1 + 0x38) + uVar6 * 8) = 4;
                *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 8;
              }
              local_18 = *(undefined4 *)(lVar4 + 0x20);
              uStack_14 = *(undefined4 *)(lVar4 + 0x24);
              uStack_10 = *(undefined4 *)(lVar4 + 0x28);
              uStack_c = *(undefined4 *)(lVar4 + 0x2c);
              DbgPrintEx(0x92,3,pcVar7,&local_18);
            }
          }
          else {
            *(ulonglong *)(param_1 + 0xa0) = *(ulonglong *)(param_1 + 0xa0) | 0x8000;
          }
        }
      }
    }
  }
  return 0;
}



===== PepPcieWnfDripsDeviceConstraintRegistredCb @ 140094b70 =====

int PepPcieWnfDripsDeviceConstraintRegistredCb
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_res20 [2];
  char local_28 [4];
  int local_24;
  int local_20 [6];
  
  local_28[0] = '\0';
  local_20[1] = 1;
  local_res20[0] = param_4;
  iVar1 = ExQueryWnfStateData(param_1,local_res20,local_28,local_20 + 1);
  if ((-1 < iVar1) && (local_28[0] == '\x01')) {
    KeSetEvent(&InitialPlatformStateRegistered,0,0);
    LOCK();
    PepInitialPlatformStateRegistered = PepInitialPlatformStateRegistered + 1;
    UNLOCK();
    PepPcieReEvalRpConstraints();
    local_24 = 0;
    local_20[2] = 0;
    local_20[0] = 4;
    iVar2 = ZwQueryWnfStateData(&WNF_PO_D3COLD_STATE_CHANGED,0,0,&local_24,local_20 + 2,local_20);
    if ((-1 < iVar2) && ((local_24 != 0 && (local_20[0] == 4)))) {
      PepPcieQueueD3UpdateWork();
    }
  }
  return iVar1;
}



===== PepPcieInitPchRPLtrMboxIndexes @ 140094c3c =====

uint PepPcieInitPchRPLtrMboxIndexes(longlong param_1,int param_2)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  int *piVar6;
  uint uVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  int iVar9;
  
  uVar8 = 0;
  local_res8[0] = 0;
  uVar3 = 0;
  if (((PepPciePchLtrOvrMboxEnabled != '\0') && (param_1 != 0)) &&
     (PepPcieSoCPchConnectedRootPortInfo != (undefined8 *)0x0)) {
    piVar1 = (int *)*PepPcieSoCPchConnectedRootPortInfo;
    uVar4 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
    uVar7 = 0;
    if ((int)uVar4 == 0) {
      ppuVar5 = &PepPcieLtrOvrRplSMtlPcMboxMap;
      do {
        if (*(int *)*ppuVar5 == *piVar1) goto LAB_140094cde;
        uVar7 = uVar7 + 1;
        ppuVar5 = ppuVar5 + 3;
      } while (uVar7 < 4);
    }
    else {
      ppuVar5 = &PepPcieLtrOvrRplSMtlPcMboxMapV1;
      do {
        if (*(int *)*ppuVar5 == *piVar1) goto LAB_140094cde;
        uVar7 = uVar7 + 1;
        ppuVar5 = ppuVar5 + 3;
      } while (uVar7 < 5);
    }
    local_res8[0] = 1;
  }
LAB_140094e8d:
  uVar3 = 0xc0000001;
LAB_140094e92:
  PepDiagLogPchMbInitIndexesFailure(local_res8,uVar3);
  return uVar3;
LAB_140094cde:
  *(undefined4 **)(param_1 + 0x90) = &PepPcieLtrOvrRplsMtlMboxContext;
  DbgPrintEx(0x92,3,
             "INTELPEP: PepPcieInitPchRPLtrMboxIndexes  found PchId match, setting MboxContext in LTROVRCTX!!! \n"
            );
  piVar1 = *(int **)(param_1 + 0x90);
  iVar9 = piVar1[2];
  DbgPrintEx(0x92,3,
             "INTELPEP: PepPcieInitPchRPLtrMboxIndexes MboxContext->MboxVersion: (%x), MboxContext->MailboxType: (%x)\n."
             ,*piVar1,iVar9);
  if ((char)piVar1[1] == '\0') {
    if ((*piVar1 == 1) && (piVar1[2] == 1)) {
      uVar3 = PepValidateAndInitAddress(piVar1 + 4);
      if ((int)uVar3 < 0) {
        local_res8[0] = 2;
        piVar6 = piVar1 + 4;
      }
      else {
        uVar3 = PepValidateAndInitAddress(piVar1 + 0x12);
        if ((int)uVar3 < 0) {
          local_res8[0] = 3;
          piVar6 = piVar1 + 0x12;
        }
        else {
          piVar6 = piVar1 + 0x20;
          uVar3 = PepValidateAndInitAddress(piVar6);
          if ((int)uVar3 < 0) {
            local_res8[0] = 4;
          }
          else {
            piVar6 = piVar1 + 0x2e;
            uVar3 = PepValidateAndInitAddress(piVar6);
            if ((int)uVar3 < 0) {
              local_res8[0] = 5;
            }
            else {
              piVar6 = piVar1 + 0x3c;
              uVar3 = PepValidateAndInitAddress(piVar6);
              if (-1 < (int)uVar3) {
                *(undefined1 *)(piVar1 + 1) = 1;
                DbgPrintEx(0x92,3,
                           "INTELPEP: PepPcieInitPchRPLtrMboxIndexes  mailbox command, status and buffers initialized.\n"
                          );
                goto LAB_140094e16;
              }
              local_res8[0] = 6;
            }
          }
        }
      }
      PepDiagLogPchMbInitLtrOvrRegFail((longlong)piVar6,uVar3);
      goto LAB_140094e92;
    }
    DbgPrintEx(0x92,3,
               "INTELPEP: PepPcieInitPchRPLtrMboxIndexes could not match mbox version or type, command, status, buffers are not initialized.\n"
              );
    local_res8[0] = 7;
  }
  else {
LAB_140094e16:
    lVar2 = PepPcieLtrOvrPchMbContext;
    if (PepPcieLtrOvrPchMbContext == 0) {
      DbgPrintEx(0x92,3,
                 "INTELPEP: PepPcieInitPchRPLtrMboxIndexes PepPciePchMailboxContext is null.\n");
      local_res8[0] = 8;
    }
    else {
      if (*(uint *)(PepPcieLtrOvrPchMbContext + 0x10) != 0) {
        do {
          if (*(int *)(*(longlong *)(PepPcieLtrOvrPchMbContext + 8) + 0xc + uVar8 * 0x10) == param_2
             ) {
            *(undefined4 *)(param_1 + 0x80) =
                 *(undefined4 *)(*(longlong *)(PepPcieLtrOvrPchMbContext + 8) + 4 + uVar8 * 0x10);
            *(undefined4 *)(param_1 + 0x84) =
                 *(undefined4 *)(*(longlong *)(lVar2 + 8) + 8 + uVar8 * 0x10);
            *(int *)(param_1 + 0x88) = param_2;
            DbgPrintEx(0x92,3,
                       "INTELPEP: PepPcieInitPchRPLtrMboxIndexes setting indexes for rootport slot: (%x) \n. !!! FOUND !!!"
                       ,param_2,iVar9);
            *(undefined1 *)(param_1 + 0x79) = 1;
            return uVar3;
          }
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < *(uint *)(PepPcieLtrOvrPchMbContext + 0x10));
      }
      local_res8[0] = 9;
    }
  }
  goto LAB_140094e8d;
}



===== PepPcieInitRootPortLtrOverrideContext @ 140094f0c =====

uint PepPcieInitRootPortLtrOverrideContext(longlong param_1,longlong param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined8 uVar9;
  uint *puVar10;
  uint local_res20 [2];
  uint local_58 [4];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  lVar3 = *(longlong *)(param_1 + 0x28);
  local_58[0] = 0;
  local_58[1] = 0;
  local_res20[0] = 0;
  local_res20[1] = 0;
  piVar6 = (int *)0x0;
  uVar4 = 0;
  if (PepPcieLtrOverrideEnabled == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x34) != '\0') {
LAB_140094f54:
    uVar4 = 0xc00000bb;
    goto LAB_140095196;
  }
  piVar6 = (int *)ExAllocatePool2(0x40,0xa0,0x49504550);
  if (piVar6 == (int *)0x0) {
    uVar4 = 0xc000009a;
    goto LAB_140095196;
  }
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 == 0) {
    if (*(char *)(PepPcieSoCCpuConnectedRootPortInfo + 0x18) == '\0') goto LAB_140094fd5;
    if (DAT_140086f0c == '\0') goto LAB_14009518e;
    *(undefined1 *)(piVar6 + 0x1e) = 1;
    pcVar8 = "INTELPEP: PCIe Global LTR Override: %wZ initialized \n";
LAB_14009516f:
    local_48 = *(undefined4 *)(lVar3 + 0x20);
    uStack_44 = *(undefined4 *)(lVar3 + 0x24);
    uStack_40 = *(undefined4 *)(lVar3 + 0x28);
    uStack_3c = *(undefined4 *)(lVar3 + 0x2c);
    DbgPrintEx(0x92,3,pcVar8,&local_48);
  }
  else {
    if ((iVar2 == 1) || (iVar2 == 2)) {
LAB_140094fd5:
      uVar7 = Feature_Servicing_IntelPepArlAndBugFixes__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar7 != 0) && (*(int *)(param_1 + 0x30) == 2)) goto LAB_140094f54;
      if (PepPciePchLtrOvrMboxEnabled != '\0') {
        uVar4 = PepPcieInitPchRPLtrMboxIndexes((longlong)piVar6,param_3);
        if ((int)uVar4 < 0) {
          uVar7 = (ulonglong)uVar4;
          pcVar8 = "InitRootPortLtrMboxIndexes";
        }
        else {
          local_res20[0] = 0;
          local_res20[1] = 0;
          puVar10 = local_res20;
          uVar9 = 1;
          uVar7 = PepPciePostPchLtrOvrMailbox((longlong)piVar6,0,1,puVar10,0);
          uVar4 = (uint)uVar7;
          if ((int)uVar4 < 0) {
            PepDiagLogPchLtrMailboxFailure
                      ((ushort *)(lVar3 + 0x20),(undefined8 *)local_res20,uVar9,puVar10);
            uVar7 = uVar7 & 0xffffffff;
            pcVar8 = "PostPchLtrMailboxLtrOvr1";
          }
          else {
            puVar10 = local_res20;
            piVar6[0x1c] = local_res20[0];
            local_res20[0] = 0;
            local_res20[1] = 0;
            uVar9 = 2;
            uVar7 = PepPciePostPchLtrOvrMailbox((longlong)piVar6,0,2,puVar10,0);
            uVar4 = (uint)uVar7;
            if (-1 < (int)uVar4) {
              uVar5 = local_res20[0];
              goto LAB_140095162;
            }
            PepDiagLogPchLtrMailboxFailure
                      ((ushort *)(lVar3 + 0x20),(undefined8 *)local_res20,uVar9,puVar10);
            uVar7 = uVar7 & 0xffffffff;
            pcVar8 = "PostPchLtrMailboxLtrOvr2";
          }
        }
        PepDiagLogPchMbInitLtrOvrFail((ushort *)(lVar3 + 0x20),pcVar8,uVar7);
        goto LAB_140095196;
      }
      *piVar6 = 2;
      piVar6[1] = 0x20;
      piVar6[3] = 3;
      piVar6[4] = param_3;
      piVar6[5] = 3;
      piVar6[6] = 0x400;
      uVar4 = PepValidateAndInitAddress(piVar6);
      if ((int)uVar4 < 0) {
        PepDiagLogPchOverrideRegFail((ushort *)(lVar3 + 0x20),(longlong)piVar6,(ulonglong)uVar4);
        goto LAB_140095196;
      }
      PepReadRegisterWithBus(piVar6,(ulonglong)*(uint *)(lVar3 + 0x34),local_58);
      piVar1 = piVar6 + 0xe;
      piVar6[0x1c] = local_58[0];
      piVar6[0x12] = param_3;
      piVar6[0x13] = 3;
      piVar6[0x14] = 0x404;
      *piVar1 = 2;
      piVar6[0xf] = 0x20;
      piVar6[0x11] = 3;
      uVar4 = PepValidateAndInitAddress(piVar1);
      if ((int)uVar4 < 0) {
        PepDiagLogPchOverrideRegFail((ushort *)(lVar3 + 0x20),(longlong)piVar1,(ulonglong)uVar4);
        goto LAB_140095196;
      }
      PepReadRegisterWithBus(piVar1,(ulonglong)*(uint *)(lVar3 + 0x34),local_58);
      uVar5 = local_58[0];
LAB_140095162:
      piVar6[0x1d] = uVar5;
      pcVar8 = "INTELPEP: PCI Root Port LTR Override: %wZ initialized.\n";
      goto LAB_14009516f;
    }
    uVar4 = 0xc00000e5;
  }
LAB_14009518e:
  *(int **)(param_2 + 0x10) = piVar6;
  if (-1 < (int)uVar4) {
    return uVar4;
  }
LAB_140095196:
  if ((piVar6 != (int *)0x0) && (ExFreePoolWithTag(piVar6,0x49504550), param_2 != 0)) {
    *(undefined8 *)(param_2 + 0x10) = 0;
  }
  return uVar4;
}



===== PepPcieLtrOverrideInit @ 1400951dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepPcieLtrOverrideInit(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 in_R9;
  undefined1 auStackY_88 [32];
  uint local_58 [2];
  uint local_50 [2];
  undefined8 local_48 [4];
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (PepPcieLtrOverrideEnabled != '\0') {
    local_50[0] = 0;
    local_50[1] = 0;
    if ((PepSubsystemSoCInfo == (int *)0x0) && (Pepv2SubsystemSocInfo == (int *)0x0)) {
      PepPcieLtrOverrideEnabled = '\0';
    }
    else {
      uVar5 = 0x49504550;
      PepPcieLtrOverrideSkipTelemetry = ExAllocatePool2();
      iVar4 = 0;
      iVar3 = 0;
      piVar2 = PepSubsystemSoCInfo;
      if ((PepSubsystemSoCInfo != (int *)0x0) ||
         (piVar2 = Pepv2SubsystemSocInfo, Pepv2SubsystemSocInfo != (int *)0x0)) {
        iVar3 = piVar2[1];
        iVar4 = *piVar2;
      }
      if (((iVar4 == *PepPcieSoCCpuConnectedRootPortInfo) &&
          (iVar3 == PepPcieSoCCpuConnectedRootPortInfo[1])) &&
         ((char)PepPcieSoCCpuConnectedRootPortInfo[6] != '\0')) {
        uVar1 = PepValidateAndInitAddress((int *)&PepPcieLtrGlobalOverrideContext);
        if ((int)uVar1 < 0) {
          if (5 < DAT_1400340a0) {
            local_1c = 0;
            local_28 = local_58;
            local_20 = 4;
            local_58[0] = uVar1;
            _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_1400306ab,uVar5,in_R9,3,local_48);
          }
        }
        else {
          PepReadRegister((int *)&PepPcieLtrGlobalOverrideContext,local_50);
          _DAT_140086f08 = local_50[0];
          DAT_140086f0c = 1;
          if (uVar1 == 0) {
            DAT_140086f0c = 1;
            return;
          }
        }
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
    }
  }
  return;
}



===== Pepv2SubsystemReadBootTelemetry @ 140095330 =====

void Pepv2SubsystemReadBootTelemetry(void)

{
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  wchar_t *pwVar4;
  int *piVar5;
  ulonglong uVar6;
  ulonglong local_res8;
  
  local_res8 = local_res8 & 0xffffffff00000000;
  puVar1 = PepSubsystemSoCInfo;
  if ((PepSubsystemSoCInfo != (uint *)0x0) ||
     (puVar1 = Pepv2SubsystemSocInfo, Pepv2SubsystemSocInfo != (uint *)0x0)) {
    if ((*puVar1 != 0) && (puVar1[1] != 0)) {
      uVar2 = PepSubsystemGetPchDeviceId(*puVar1,puVar1[1],(undefined4 *)&local_res8);
      piVar5 = (int *)0x0;
      if (-1 < (int)uVar2) {
        local_res8._0_4_ = (uint)local_res8 & 0xff80ffff;
        uVar3 = 0;
        while( true ) {
          if (10 < uVar3) {
            return;
          }
          uVar6 = (ulonglong)uVar3;
          if ((&DAT_1400809d8)[uVar6 * 0x20] == 1) {
            piVar5 = (int *)(&PTR_TGLUY_PCH_HWID_1400809e0)[uVar6 * 0x10];
          }
          if (piVar5 == (int *)0x0) {
            return;
          }
          if (*piVar5 != 2) {
            return;
          }
          if (*(uint **)(piVar5 + 4) == (uint *)0x0) break;
          if (**(uint **)(piVar5 + 4) == (uint)local_res8) {
            local_res8 = (ulonglong)Feature_IntelAdlNSupport__private_featureState;
            if ((Feature_IntelAdlNSupport__private_featureState & 0x10) == 0) {
              local_res8 = (ulonglong)(Feature_IntelAdlNSupport__private_featureState | 1);
              wil_details_FeatureReporting_ReportUsageToService(0x140033198,local_res8,3);
              wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                        ((uint)local_res8,3,&Feature_IntelAdlNSupport__private_descriptor);
            }
            PepSubsystemGetBootTelemetryInfo
                      ((longlong)(&Pepv2SubsystemBootTelemetryInfoArray + uVar6 * 0x80));
            return;
          }
          uVar3 = uVar3 + 1;
        }
        return;
      }
      uVar2 = 2;
      pwVar4 = L"PchDeviceIdReadFailed";
      goto LAB_140095451;
    }
  }
  pwVar4 = L"FamilyModelNotInitialized";
  uVar2 = 1;
LAB_140095451:
  PepDiagLogBootTelemetry(pwVar4,0,uVar2);
  return;
}



===== PepSubsystemQueryLtrBlockingTime @ 140095470 =====

undefined8 PepSubsystemQueryLtrBlockingTime(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,0);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 8);
  if (lVar1 == 0) {
    return 0;
  }
  lVar2 = *(longlong *)(lVar1 + 0x18);
  if (lVar2 == 0) {
    return *(undefined8 *)(lVar1 + 0x80);
  }
  uVar4 = 0;
  while( true ) {
    if (6 < (uint)uVar4) {
      return 0;
    }
    RtlInitUnicodeString(&local_18,*(undefined8 *)(lVar2 + uVar4 * 0x28));
    cVar3 = RtlEqualUnicodeString(&local_18,*(undefined8 *)(param_1 + 0x10),1);
    if (cVar3 != '\0') break;
    uVar4 = (ulonglong)((uint)uVar4 + 1);
  }
  return *(undefined8 *)(lVar2 + uVar4 * 0x28 + 0x18);
}



===== PepPcieTreeConstraintsFromBios @ 140095540 =====

void PepPcieTreeConstraintsFromBios
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  PepDiagTracePcieFeatures(param_1,param_2,param_3,param_4);
  if ((PepPcieGeneratePcieHierarchyEnabled != '\0') && (PepNumPlatformStates != 0)) {
    puVar2 = (undefined8 *)0x0;
    ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock);
    puVar3 = PepPcieRootPortList;
    if ((undefined8 **)PepPcieRootPortList != &PepPcieRootPortList) {
      do {
        PepDiagTraceBiosRootPortConstraints((longlong)puVar3,puVar2,param_3,param_4);
        for (puVar1 = (undefined8 *)puVar3[2]; puVar1 != puVar3 + 2; puVar1 = (undefined8 *)*puVar1)
        {
          puVar2 = puVar1;
          PepDiagTraceBiosEndPointConstraints((longlong)puVar3,(longlong)puVar1);
        }
        puVar3 = (undefined8 *)*puVar3;
      } while ((undefined8 **)puVar3 != &PepPcieRootPortList);
    }
    ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
    for (puVar3 = PepPcieRCiEPList; (undefined8 **)puVar3 != &PepPcieRCiEPList;
        puVar3 = (undefined8 *)*puVar3) {
      PepDiagTraceRCiEPConstraints((longlong)puVar3);
    }
    ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
  }
  return;
}



===== PepDiagTracePcieFeatures @ 140095660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepDiagTracePcieFeatures
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined1 auStackY_128 [32];
  undefined1 local_f8;
  undefined1 local_f7;
  undefined1 local_f6;
  undefined1 local_f5;
  undefined1 local_f4;
  undefined1 local_f3;
  undefined1 local_f2;
  undefined1 local_f1;
  undefined8 local_f0;
  undefined8 local_e8 [2];
  undefined8 local_d8 [4];
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  if (5 < DAT_1400340a0) {
    if (((_DAT_1400340b0 & 0x400000000000) == 0) ||
       ((DAT_1400340b8 & 0x400000000000) != DAT_1400340b8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_b8 = &local_f0;
      local_f0 = 0x1000000;
      local_e8[0] = PepSleepStudySessionInstanceId;
      local_a8 = local_e8;
      local_f8 = PepPcieGeneratePcieHierarchyEnabled;
      local_98 = &local_f8;
      local_f7 = PepPcieLtrOverrideEnabled;
      local_88 = &local_f7;
      local_f6 = PepPcieGeneratedConstraintEnabled;
      local_78 = &local_f6;
      local_f5 = PepPcieGeneratedConstraintRCiEPEnabled;
      local_68 = &local_f5;
      local_f4 = PepErrataIgnoreMissingDependencies;
      local_58 = &local_f4;
      local_f3 = PepPciePchLtrOvrMboxEnabled;
      local_48 = &local_f3;
      local_f2 = PepPciePchLtrOvrMboxDisabledBootSession;
      local_38 = &local_f2;
      local_f1 = PepPcieSecurePcieEnabled;
      local_28 = &local_f1;
      local_b0 = 8;
      local_a0 = 8;
      local_90 = 1;
      local_80 = 1;
      local_70 = 1;
      local_60 = 1;
      local_50 = 1;
      local_40 = 1;
      local_30 = 1;
      local_20 = 1;
      _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f003,param_3,param_4,0xc,local_d8);
    }
  }
  return;
}



===== PepDiagTraceBiosEndPointConstraints @ 140095820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepDiagTraceBiosEndPointConstraints(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined1 auStackY_208 [32];
  undefined1 local_1d8;
  undefined1 local_1d7;
  undefined1 local_1d6 [2];
  undefined2 local_1d4 [2];
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  uint local_1c4;
  uint local_1c0 [2];
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8 [2];
  undefined8 local_198 [4];
  undefined8 *local_178;
  undefined8 local_170;
  undefined8 *local_168;
  undefined8 local_160;
  uint *local_158;
  undefined8 local_150;
  undefined8 local_148;
  uint local_140 [2];
  uint *local_138;
  undefined8 local_130;
  undefined8 local_128;
  uint local_120 [2];
  uint *local_118;
  undefined8 local_110;
  undefined8 local_108;
  uint local_100 [2];
  uint *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  uint local_e0 [2];
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_208;
  if ((PepNumPlatformStates != 0) &&
     (lVar8 = ExAllocatePool2(0x40,PepNumPlatformStates * 0x14), uVar6 = PepNumPlatformStates,
     lVar8 != 0)) {
    uVar10 = 0;
    piVar1 = *(int **)(param_2 + 0x38);
    lVar2 = *(longlong *)(param_2 + 0x28);
    local_1d4[0] = (undefined2)PepNumPlatformStates;
    if (PepNumPlatformStates != 0) {
      if (lVar2 == 0) {
        uVar10 = 0;
        piVar12 = (int *)(lVar8 + 0x10);
        piVar13 = piVar1;
        do {
          piVar12[-4] = uVar10;
          if (piVar1 != (int *)0x0) {
            iVar7 = uVar10 + 1;
            if (*piVar13 != 0) {
              iVar7 = *piVar13 + -1;
            }
            piVar12[-1] = iVar7;
            *piVar12 = piVar13[1];
          }
          uVar10 = uVar10 + 1;
          piVar13 = piVar13 + 2;
          piVar12 = piVar12 + 5;
        } while (uVar10 < uVar6);
      }
      else {
        piVar12 = piVar1 + 1;
        puVar11 = (undefined4 *)(lVar8 + 8);
        do {
          puVar11[-2] = uVar10;
          iVar7 = *(int *)((lVar2 - (longlong)piVar1) + -4 + (longlong)piVar12);
          iVar9 = 0;
          if (iVar7 != 0) {
            iVar9 = iVar7 + -1;
          }
          puVar11[-1] = iVar9;
          *puVar11 = *(undefined4 *)((lVar2 - (longlong)piVar1) + (longlong)piVar12);
          if (piVar1 != (int *)0x0) {
            if (piVar12[-1] == 0) {
              iVar7 = uVar10 + 1;
            }
            else {
              iVar7 = piVar12[-1] + -1;
            }
            puVar11[1] = iVar7;
            puVar11[2] = *piVar12;
          }
          uVar10 = uVar10 + 1;
          piVar12 = piVar12 + 2;
          puVar11 = puVar11 + 5;
        } while (uVar10 < uVar6);
      }
    }
    uVar10 = *(uint *)(param_2 + 0x48);
    lVar3 = *(longlong *)(param_1 + 0x28);
    lVar4 = *(longlong *)(param_2 + 0x18);
    if (5 < DAT_1400340a0) {
      if (((_DAT_1400340b0 & 0x400000000000) == 0) ||
         ((DAT_1400340b8 & 0x400000000000) != DAT_1400340b8)) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if (bVar5) {
        local_178 = &local_1b8;
        local_1b8 = 0x1000000;
        local_1d8 = lVar2 != 0;
        local_1b0 = PepSleepStudySessionInstanceId;
        local_168 = &local_1b0;
        local_170 = 8;
        local_1d7 = piVar1 != (int *)0x0;
        local_158 = local_140;
        local_160 = 8;
        local_148 = *(undefined8 *)(lVar4 + 0x28);
        local_140[0] = (uint)*(ushort *)(lVar4 + 0x20);
        local_138 = local_120;
        local_128 = *(undefined8 *)(lVar4 + 0x48);
        local_120[0] = (uint)*(ushort *)(lVar4 + 0x40);
        local_118 = local_100;
        local_108 = *(undefined8 *)(lVar3 + 0x28);
        local_100[0] = (uint)*(ushort *)(lVar3 + 0x20);
        local_f8 = local_e0;
        local_e8 = *(undefined8 *)(lVar3 + 0x48);
        local_e0[0] = (uint)*(ushort *)(lVar3 + 0x40);
        local_d8 = &local_1d8;
        local_c8 = &local_1d7;
        local_1d0 = *(undefined4 *)(param_2 + 0x10);
        local_b8 = &local_1d0;
        local_1d6[0] = *(undefined1 *)(param_2 + 0x20);
        local_a8 = local_1d6;
        local_1cc = *(undefined4 *)(lVar3 + 0x50);
        local_98 = &local_1cc;
        local_1c8 = *(undefined4 *)(lVar4 + 0x50);
        local_88 = &local_1c8;
        local_78 = &local_1c4;
        local_68 = local_1c0;
        local_1a8[0] = *(undefined8 *)(param_2 + 0x40);
        local_150 = 2;
        local_140[1] = 0;
        local_130 = 2;
        local_120[1] = 0;
        local_110 = 2;
        local_100[1] = 0;
        local_f0 = 2;
        local_e0[1] = 0;
        local_d0 = 1;
        local_c0 = 1;
        local_b0 = 4;
        local_a0 = 1;
        local_90 = 4;
        local_80 = 4;
        local_70 = 4;
        local_1c0[0] = (uint)(((byte)uVar10 & 0xc) == 0xc);
        local_60 = 4;
        local_58 = local_1a8;
        local_50 = 8;
        local_48 = local_1d4;
        local_40 = 2;
        local_2c = 0;
        local_30 = (uVar6 & 0xffff) * 0x14;
        local_1c4 = uVar10;
        local_38 = lVar8;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1400340a0,&DAT_140030477,lVar4,(ulonglong)uVar10,0x17,local_198);
      }
    }
    ExFreePoolWithTag(lVar8,0x49504550);
  }
  return;
}



===== PepDiagTraceBiosRootPortConstraints @ 140095c70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepDiagTraceBiosRootPortConstraints
               (longlong param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  uint uVar13;
  undefined1 auStackY_1a8 [32];
  undefined1 local_178;
  undefined1 local_177 [3];
  ushort local_174 [2];
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148 [4];
  undefined8 *local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined8 local_110;
  uint *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  uint local_f0 [2];
  uint *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0 [2];
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 local_50;
  longlong local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1a8;
  if (PepNumPlatformStates != 0) {
    piVar12 = (int *)0x49504550;
    lVar8 = ExAllocatePool2();
    uVar5 = PepNumPlatformStates;
    if (lVar8 != 0) {
      uVar13 = 0;
      piVar1 = *(int **)(param_1 + 0x38);
      lVar2 = *(longlong *)(param_1 + 0x58);
      local_174[0] = (ushort)PepNumPlatformStates;
      if (PepNumPlatformStates != 0) {
        if (lVar2 == 0) {
          uVar13 = 0;
          piVar10 = (int *)(lVar8 + 0x10);
          piVar12 = piVar1;
          do {
            piVar10[-4] = uVar13;
            if (piVar1 != (int *)0x0) {
              if (*piVar12 == 0) {
                iVar7 = uVar13 + 1;
              }
              else {
                iVar7 = *piVar12 + -1;
              }
              piVar10[-1] = iVar7;
              *piVar10 = piVar12[1];
            }
            uVar13 = uVar13 + 1;
            piVar12 = piVar12 + 2;
            piVar10 = piVar10 + 5;
          } while (uVar13 < uVar5);
        }
        else {
          param_4 = piVar1 + 1;
          piVar12 = (int *)(lVar8 + 8);
          do {
            piVar12[-2] = uVar13;
            iVar7 = *(int *)((lVar2 - (longlong)piVar1) + -4 + (longlong)param_4);
            iVar9 = 0;
            if (iVar7 != 0) {
              iVar9 = iVar7 + -1;
            }
            uVar13 = uVar13 + 1;
            piVar12[-1] = iVar9;
            *piVar12 = *(int *)((lVar2 - (longlong)piVar1) + (longlong)param_4);
            if (piVar1 != (int *)0x0) {
              if (param_4[-1] == 0) {
                uVar6 = uVar13;
              }
              else {
                uVar6 = param_4[-1] - 1;
              }
              piVar12[1] = uVar6;
              piVar12[2] = *param_4;
            }
            param_4 = param_4 + 2;
            piVar12 = piVar12 + 5;
          } while (uVar13 < uVar5);
        }
      }
      uVar11 = 0;
      lVar3 = *(longlong *)(param_1 + 0x28);
      if ((PepDripsIndex != 0xffffffff) && (piVar1 != (int *)0x0)) {
        if ((piVar1[(ulonglong)PepDripsIndex * 2] != 1) &&
           (piVar1[(ulonglong)PepDripsIndex * 2] != 4)) {
          MicrosoftTelemetryAssertTriggeredMsgKM
                    ("PepDiagTraceBiosRootPortConstraints Incorrect GC D-constraints");
        }
        if (1 < (uint)piVar1[(ulonglong)PepDripsIndex * 2 + 1]) {
          MicrosoftTelemetryAssertTriggeredMsgKM
                    ("PepDiagTraceBiosRootPortConstraints Incorrect GC F-constraints");
        }
        if (piVar1[(ulonglong)PepDripsIndex * 2] == 1) {
          if (piVar1[(ulonglong)PepDripsIndex * 2 + 1] == 0) {
            if ((*(ulonglong *)(param_1 + 0xa0) & 0xffee000000000000) == 0xffee000000000000) {
              uVar11 = 2;
            }
            else if ((*(ulonglong *)(param_1 + 0xa0) & 1) != 0) {
              uVar11 = 1;
            }
          }
        }
        else if ((piVar1[(ulonglong)PepDripsIndex * 2] == 4) &&
                (uVar11 = 0, (*(byte *)(param_1 + 0xa0) & 4) != 0)) {
          uVar11 = 4;
        }
      }
      if (5 < DAT_1400340a0) {
        if (((_DAT_1400340b0 & 0x400000000000) == 0) ||
           ((DAT_1400340b8 & 0x400000000000) != DAT_1400340b8)) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
        if (bVar4) {
          local_128 = &local_160;
          local_160 = 0x1000000;
          local_178 = lVar2 != 0;
          local_158 = PepSleepStudySessionInstanceId;
          local_118 = &local_158;
          local_108 = local_f0;
          local_120 = 8;
          local_177[0] = piVar1 != (int *)0x0;
          local_f8 = *(undefined8 *)(lVar3 + 0x28);
          local_f0[0] = (uint)*(ushort *)(lVar3 + 0x20);
          local_e8 = local_d0;
          local_d8 = *(undefined8 *)(lVar3 + 0x48);
          local_d0[0] = (uint)*(ushort *)(lVar3 + 0x40);
          local_c8 = &local_178;
          local_b8 = local_177;
          local_170 = *(undefined4 *)(lVar3 + 0x50);
          local_a8 = &local_170;
          local_98 = &local_16c;
          local_150 = *(undefined8 *)(param_1 + 0xa0);
          local_88 = &local_150;
          local_168 = *(undefined4 *)(param_1 + 0x40);
          local_78 = &local_168;
          local_164 = *(undefined4 *)(param_1 + 0xa8);
          local_68 = &local_164;
          local_58 = local_174;
          local_110 = 8;
          local_100 = 2;
          local_f0[1] = 0;
          local_e0 = 2;
          local_40 = (uint)local_174[0] * 0x14;
          local_d0[1] = 0;
          local_c0 = 1;
          local_b0 = 1;
          local_a0 = 4;
          local_90 = 4;
          local_80 = 8;
          local_70 = 4;
          local_60 = 4;
          local_50 = 2;
          local_3c = 0;
          local_16c = uVar11;
          local_48 = lVar8;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x1400340a0,&DAT_140030138,piVar12,param_4,0x11,local_148);
        }
      }
      ExFreePoolWithTag(lVar8,0x49504550);
    }
  }
  return;
}



===== PepDiagTraceRCiEPConstraints @ 1400960a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PepDiagTraceRCiEPConstraints(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 uVar4;
  longlong lVar5;
  bool bVar6;
  uint uVar7;
  longlong lVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  undefined1 auStackY_198 [32];
  undefined1 local_168;
  undefined1 local_167;
  byte local_166 [2];
  undefined2 local_164 [2];
  undefined4 local_160 [2];
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148 [2];
  undefined8 local_138 [4];
  undefined8 *local_118;
  undefined8 local_110;
  undefined8 *local_108;
  undefined8 local_100;
  uint *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  uint local_e0 [2];
  uint *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  uint local_c0 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  byte *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  undefined2 *local_48;
  undefined8 local_40;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_198;
  if ((PepNumPlatformStates != 0) &&
     (lVar8 = ExAllocatePool2(0x40,PepNumPlatformStates * 0x14,0x49504550),
     uVar7 = PepNumPlatformStates, lVar8 != 0)) {
    uVar13 = 0;
    lVar2 = *(longlong *)(param_1 + 0x28);
    piVar3 = *(int **)(param_1 + 0x18);
    local_164[0] = (undefined2)PepNumPlatformStates;
    if (PepNumPlatformStates != 0) {
      if (lVar2 == 0) {
        piVar12 = (int *)(lVar8 + 0x10);
        piVar14 = piVar3;
        do {
          piVar12[-4] = uVar13;
          uVar13 = uVar13 + 1;
          if (piVar3 != (int *)0x0) {
            uVar10 = uVar13;
            if (*piVar14 != 0) {
              uVar10 = *piVar14 - 1;
            }
            piVar12[-1] = uVar10;
            *piVar12 = piVar14[1];
          }
          piVar14 = piVar14 + 2;
          piVar12 = piVar12 + 5;
        } while (uVar13 < uVar7);
      }
      else {
        piVar12 = piVar3 + 1;
        puVar11 = (undefined4 *)(lVar8 + 8);
        do {
          puVar11[-2] = uVar13;
          iVar1 = *(int *)((lVar2 - (longlong)piVar3) + -4 + (longlong)piVar12);
          iVar9 = 0;
          if (iVar1 != 0) {
            iVar9 = iVar1 + -1;
          }
          uVar13 = uVar13 + 1;
          puVar11[-1] = iVar9;
          *puVar11 = *(undefined4 *)((lVar2 - (longlong)piVar3) + (longlong)piVar12);
          if (piVar3 != (int *)0x0) {
            uVar10 = uVar13;
            if (piVar12[-1] != 0) {
              uVar10 = piVar12[-1] - 1;
            }
            puVar11[1] = uVar10;
            puVar11[2] = *piVar12;
          }
          piVar12 = piVar12 + 2;
          puVar11 = puVar11 + 5;
        } while (uVar13 < uVar7);
      }
    }
    uVar4 = *(undefined8 *)(param_1 + 0x30);
    lVar5 = *(longlong *)(param_1 + 0x10);
    if (5 < DAT_1400340a0) {
      if (((_DAT_1400340b0 & 0x400000000000) == 0) ||
         ((DAT_1400340b8 & 0x400000000000) != DAT_1400340b8)) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (bVar6) {
        local_118 = &local_158;
        local_168 = lVar2 != 0;
        local_150 = PepSleepStudySessionInstanceId;
        local_108 = &local_150;
        local_f8 = local_e0;
        local_158 = 0x1000000;
        local_167 = piVar3 != (int *)0x0;
        local_e8 = *(undefined8 *)(lVar5 + 0x28);
        local_e0[0] = (uint)*(ushort *)(lVar5 + 0x20);
        local_d8 = local_c0;
        local_c8 = *(undefined8 *)(lVar5 + 0x48);
        local_c0[0] = (uint)*(ushort *)(lVar5 + 0x40);
        local_b8 = &local_168;
        local_a8 = &local_167;
        local_160[0] = *(undefined4 *)(lVar5 + 0x50);
        local_98 = local_160;
        local_88 = local_148;
        local_78 = local_166;
        local_68 = local_50;
        local_58 = *(undefined8 *)(param_1 + 0x40);
        local_50[0] = (uint)*(ushort *)(param_1 + 0x38);
        local_48 = local_164;
        local_110 = 8;
        local_100 = 8;
        local_f0 = 2;
        local_e0[1] = 0;
        local_30 = (uVar7 & 0xffff) * 0x14;
        local_d0 = 2;
        local_c0[1] = 0;
        local_b0 = 1;
        local_a0 = 1;
        local_90 = 4;
        local_80 = 8;
        local_70 = 1;
        local_60 = 2;
        local_50[1] = 0;
        local_40 = 2;
        local_2c = 0;
        local_166[0] = (byte)uVar4 & 1;
        local_148[0] = uVar4;
        local_38 = lVar8;
        _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,&DAT_14002f6e0,uVar4,lVar5,0x11,local_138);
      }
    }
    ExFreePoolWithTag(lVar8,0x49504550);
  }
  return;
}



===== PepPcieD3ColdUpdateWorker @ 140096400 =====

int PepPcieD3ColdUpdateWorker(void)

{
  int *piVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  
  do {
    LOCK();
    PepPcieD3ColdUpdateWorkerStatus = -0x80000000;
    UNLOCK();
    LOCK();
    UNLOCK();
    if (0 < PepInitialPlatformStateRegistered) {
      ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
      for (puVar4 = PepPcieRootPortList; (undefined8 **)puVar4 != &PepPcieRootPortList;
          puVar4 = (undefined8 *)*puVar4) {
        for (puVar2 = (undefined8 *)puVar4[2]; puVar2 != puVar4 + 2; puVar2 = (undefined8 *)*puVar2)
        {
          local_res18[0] = 0;
          local_res10[0] = 0;
          local_res20[0] = 0;
          iVar5 = IoGetDevicePropertyData
                            (*(undefined8 *)(puVar2[3] + 0x10),&DEVPKEY_PciDevice_D3ColdSupport,0,0,
                             4,local_res10,local_res20,local_res18);
          if (iVar5 != 0) {
            MicrosoftTelemetryAssertTriggeredMsgKM
                      ("PepPcieQueryD3ColdSupported device property query failed");
          }
          *(undefined4 *)(puVar2 + 9) = local_res10[0];
          uVar3 = puVar2[8];
          if (((byte)local_res10[0] & 0xc) == 0xc) {
            if ((uVar3 >> 10 & 1) == 0) {
              puVar2[8] = uVar3 | 0x400;
              LOCK();
              piVar1 = (int *)(puVar4 + 0x15);
              iVar5 = *piVar1;
              *piVar1 = *piVar1;
              UNLOCK();
              if (0 < iVar5) {
                LOCK();
                piVar1 = (int *)(puVar4 + 0x15);
                iVar5 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if (iVar5 == 1) {
                  LOCK();
                  *(int *)(puVar4 + 8) = *(int *)(puVar4 + 8) + 1;
                  UNLOCK();
                  goto LAB_140096519;
                }
              }
            }
          }
          else if ((uVar3 >> 10 & 1) != 0) {
            puVar2[8] = uVar3 & 0xfffffffffffffbff;
            LOCK();
            piVar1 = (int *)(puVar4 + 0x15);
            iVar5 = *piVar1;
            *piVar1 = *piVar1 + 1;
            UNLOCK();
            if (iVar5 == 0) {
              LOCK();
              *(int *)(puVar4 + 8) = *(int *)(puVar4 + 8) + -1;
              UNLOCK();
LAB_140096519:
              PepPcieQueueConstraintWork((longlong)puVar4,1);
            }
          }
        }
      }
      ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock);
    }
    iVar5 = -0x80000000;
    LOCK();
    bVar6 = PepPcieD3ColdUpdateWorkerStatus == -0x80000000;
    if (bVar6) {
      PepPcieD3ColdUpdateWorkerStatus = 0;
    }
    else {
      iVar5 = PepPcieD3ColdUpdateWorkerStatus;
    }
    UNLOCK();
    if (bVar6) {
      return iVar5;
    }
  } while( true );
}



===== PepPrepareDevice @ 1400965c0 =====

byte PepPrepareDevice(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  byte bVar5;
  byte local_res10 [8];
  
  puVar4 = (undefined8 *)0x0;
  local_res10[0] = 0;
  bVar5 = 0;
  if (PepPcieGeneratePcieHierarchyEnabled != '\0') {
    if (PepPcieCollectPcieHierarchyDiagnostic != '\0') {
      puVar4 = PepPcieAddDiagList(param_1);
    }
    uVar3 = PepPcieIsPcieDevice(param_1[2],(longlong)puVar4);
    if ((((char)uVar3 != '\0') &&
        (iVar1 = PepPciePreparePcieDevice(param_1,(longlong)puVar4,(char *)local_res10),
        bVar5 = local_res10[0], local_res10[0] != 0)) && (iVar1 == 0)) {
      DbgPrintEx(0x92,3,"INTELPEP: prepare PCIe device (%wZ)\n",*param_1);
      return bVar5;
    }
  }
  lVar2 = PepFindDeviceMatch((ushort *)*param_1);
  if (lVar2 == 0) {
    return bVar5;
  }
  DbgPrintEx(0x92,3,"INTELPEP: prepare device (%wZ)\n",*param_1);
  return 1;
}



===== PepPcieIsPcieDevice @ 1400966a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PepPcieIsPcieDevice(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined4 local_28 [2];
  longlong local_20;
  longlong lStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = 0;
  local_38 = local_28;
  uVar3 = 0;
  local_20 = 0;
  lStack_18 = 0;
  iVar1 = IoGetDeviceProperty(0,0xc,0x10,&local_20);
  if (-1 < iVar1) {
    lVar2 = local_20 + -0x11d0b510c8ebdfb0;
    if (lVar2 == 0) {
      lVar2 = lStack_18 + 0x1cbdda365fff1a80;
    }
    if (((lVar2 == 0) && (uVar3 = 1, PepPcieCollectPcieHierarchyDiagnostic != '\0')) &&
       (param_2 != 0)) {
      *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) | 2;
    }
    if (iVar1 == 0) {
      return uVar3;
    }
  }
  if (iVar1 != -0x3fffffcc) {
    MicrosoftTelemetryAssertTriggeredMsgKM("PepPcieIsPcieDevice device property query failed");
  }
  return uVar3;
}



===== PepSubsystemQueryPkgcDbgBlockingTime @ 140096770 =====

undefined8 PepSubsystemQueryPkgcDbgBlockingTime(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 8) + 0x18);
  if ((lVar1 == 0) || (PepSubsystemEnableDebugPkgCounters == '\0')) {
    return 0;
  }
  return *(undefined8 *)(lVar1 + 0x18);
}



===== PepSubsystemQueryPciLinkBlockingTime @ 1400967a0 =====

undefined8 PepSubsystemQueryPciLinkBlockingTime(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 local_28;
  longlong lStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  cVar3 = '\0';
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  lStack_20 = 0;
  if ((param_1 == 0) || (*(longlong *)(param_1 + 8) == 0)) {
    return 0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 8);
  if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 == 0)) {
    return 0;
  }
  puVar6 = (undefined8 *)(lVar2 + 0x10);
  uVar7 = 0;
  do {
    RtlInitUnicodeString(&local_18,*puVar6);
    uVar1 = **(ushort **)(param_1 + 0x10);
    uVar4 = (uint)uVar1 - (uint)(ushort)local_18;
    if (uVar4 <= uVar1) {
      local_28._0_4_ = CONCAT22((ushort)local_18,(ushort)local_18);
      lStack_20 = *(longlong *)(*(ushort **)(param_1 + 0x10) + 4) + (ulonglong)(uVar4 >> 1) * 2;
      cVar3 = RtlEqualUnicodeString
                        (&local_18,&local_28,CONCAT71((uint7)(byte)((ulonglong)local_18 >> 8),1));
      if (cVar3 != '\0') goto LAB_14009686d;
    }
    uVar4 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar4;
    puVar6 = puVar6 + 6;
  } while (uVar4 < 4);
  if (cVar3 == '\0') {
    uVar5 = 0;
  }
  else {
LAB_14009686d:
    uVar5 = *(undefined8 *)(lVar2 + (uVar7 + 1) * 0x30);
  }
  return uVar5;
}



===== PepSubsystemLogTelemetry @ 1400968e0 =====

void PepSubsystemLogTelemetry(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  wchar_t *pwVar1;
  undefined *puVar2;
  uint uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  
  pwVar1 = PepSleepStudySessionInstanceId;
  if (PepSubsystemInvalidSessionBitMask != 0) {
    PepDiagLogHardwareFailedToRespond();
  }
  if (599999999 < PepSubsystemTotalSwDripsResidency) {
    uVar4 = 0;
    if (PepSubsystemAccountingCount != 0) {
      do {
        param_1 = (undefined8 *)(uVar4 * 0xd8 + PepSubsystemAccountingInfo);
        if ((*(int *)((longlong)param_1 + 0x14) - 4U & 0xfffffffb) == 0) {
          PepSubsystemLogPowerGatingDomainTelemetry((longlong)param_1,(longlong)pwVar1,param_3);
        }
        else {
          param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
          PepDiagLogSubsystemCounter(param_1,(undefined8 *)0x0,param_3,pwVar1);
        }
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < PepSubsystemAccountingCount);
    }
    if (PepSubsystemHwDripsInfo == (undefined8 *)0x0) {
      pwVar5 = L"Undefined";
      puVar2 = (undefined *)0x0;
    }
    else {
      pwVar5 = (wchar_t *)*PepSubsystemHwDripsInfo;
      puVar2 = (undefined *)PepSubsystemHwDripsInfo[0x10];
    }
    pwVar6 = pwVar1;
    PepDiagLogStandbySummaryTelemetry(param_1,puVar2,pwVar5,pwVar1);
    if (PepSubsystemEnableDebugPkgCounters != '\0') {
      PepDiagLogDbgPkgcCmdAccessTimeAccounting
                (L"StartPkgcFlowCounterCommand",(undefined4 *)&PepSubsystemStartCmdTimeAccounting,
                 pwVar1);
      puVar2 = &PepSubsystemStopCmdTimeAccounting;
      pwVar5 = pwVar1;
      PepDiagLogDbgPkgcCmdAccessTimeAccounting
                (L"StopPkgcFlowCounterCommand",(undefined4 *)&PepSubsystemStopCmdTimeAccounting,
                 pwVar1);
    }
    if ((PepPcieLtrOverrideEnabled != '\0') && (PepPcieLtrOverrideSkipTelemetry != 0)) {
      PepDiagLogLtrOverrideSkippedTelemetry(pwVar1,puVar2,pwVar5,pwVar6);
    }
    if ((PepPciePchLtrOvrMboxEnabled != '\0') && (PepPciePchLtrOvrMboxDisabledBootSession == '\0'))
    {
      PepDiagLogLtrOvrMbResponseHistrogram(pwVar1,puVar2,pwVar5,pwVar6);
    }
  }
  return;
}



===== PepSubsystemLogPowerGatingDomainTelemetry @ 140096a20 =====

void PepSubsystemLogPowerGatingDomainTelemetry(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (((*(int *)(param_1 + 0x14) - 4U & 0xfffffffb) == 0) &&
     (puVar1 = *(uint **)(param_1 + 0x18), puVar1 != (uint *)0x0)) {
    uVar5 = 0;
    lVar2 = *(longlong *)(puVar1 + 2);
    if (*puVar1 != 0) {
      do {
        if (*(int *)(param_1 + 0x14) == 4) {
          param_3 = 0;
          PepDiagLogPowerGatingCounter
                    (*(wchar_t **)(lVar2 + uVar5 * 0x28),0,0,
                     *(longlong *)(lVar2 + 0x18 + uVar5 * 0x28),'\x01',param_2);
        }
        else if (*(int *)(param_1 + 0x14) == 8) {
          lVar3 = *(longlong *)(lVar2 + 0x18 + uVar5 * 0x28);
          param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),lVar3 != 0);
          PepDiagLogSlpS0DbgCounter
                    (*(wchar_t **)(lVar2 + uVar5 * 0x28),
                     *(undefined1 *)(lVar2 + 0x10 + uVar5 * 0x28),param_3,lVar3,'\x01',param_2);
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *puVar1);
    }
  }
  return;
}



===== PepDiagLogStandbySummaryTelemetry @ 140096af0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogStandbySummaryTelemetry
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  byte *pbVar2;
  undefined8 uVar3;
  undefined1 auStackY_d8 [32];
  undefined4 uVar4;
  undefined1 local_a8 [8];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  undefined8 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar3 = PepSubsystemTotalSwDripsResidency;
  if (PepSubsystemIsKabyLake == '\0') {
    if (DAT_1400340a0 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_68 = &local_90;
    local_58 = &local_98;
    local_60 = 8;
    local_50 = 8;
    local_98 = param_2;
    local_90 = uVar3;
    _tlgCreate1Sz_wchar_t(local_48,param_3);
    local_38 = &local_a0;
    pbVar2 = &DAT_14002f853;
    uVar4 = 6;
    local_a0 = param_4;
  }
  else {
    if (DAT_1400340a0 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_68 = &local_a0;
    local_58 = &local_98;
    local_60 = 8;
    local_50 = 8;
    local_a0 = uVar3;
    local_98 = param_2;
    _tlgCreate1Sz_wchar_t(local_48,param_3);
    local_38 = &local_90;
    pbVar2 = &DAT_14002ef27;
    local_a8[0] = PepWoVEnabled;
    local_28 = local_a8;
    uVar4 = 7;
    local_20 = 1;
    local_90 = param_4;
  }
  local_30 = 8;
  _tlgWriteTransfer_EtwWriteTransfer(0x1400340a0,pbVar2,uVar3,param_4,uVar4,local_88);
  return;
}



===== PepSubsystemUpdateBlockingTimePwrGatingDomains @ 140096c80 =====

undefined8 PepSubsystemUpdateBlockingTimePwrGatingDomains(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  uVar5 = 0;
  puVar1 = *(uint **)(*(longlong *)(param_1 + 8) + 8);
  lVar2 = *(longlong *)(puVar1 + 2);
  if (*puVar1 != 0) {
    do {
      RtlInitUnicodeString(&local_18,*(undefined8 *)(lVar2 + uVar5 * 0x28));
      cVar3 = RtlEqualUnicodeString(&local_18,*(undefined8 *)(param_1 + 0x10),1);
      if (cVar3 != '\0') break;
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *puVar1);
  }
  return *(undefined8 *)(lVar2 + 0x18 + uVar5 * 0x28);
}



===== PepPcieWnfPcieD3ColdUpdateCb @ 140096d20 =====

undefined8 PepPcieWnfPcieD3ColdUpdateCb(undefined8 param_1,longlong *param_2)

{
  if ((PepDripsIndex != -1) && (PepPcieGeneratedConstraintEnabled != '\0')) {
    if (*param_2 != 0x41c6013da3bd9875) {
      return 0xc00000bb;
    }
    PepPcieQueueD3UpdateWork();
  }
  return 0;
}



===== PepPcieQueueD3UpdateWork @ 140096d60 =====

void PepPcieQueueD3UpdateWork(void)

{
  uint uVar1;
  bool bVar2;
  
  if (PepPcieGeneratedConstraintEnabled != '\0') {
    ExAcquirePushLockExclusiveEx(&PepPcieD3ColdUpdateWorkerLock,0);
    uVar1 = PepPcieD3ColdUpdateWorkerStatus;
    do {
      LOCK();
      bVar2 = uVar1 == PepPcieD3ColdUpdateWorkerStatus;
      if (bVar2) {
        PepPcieD3ColdUpdateWorkerStatus = uVar1 | 0x80000001;
      }
      else {
        uVar1 = PepPcieD3ColdUpdateWorkerStatus;
      }
      UNLOCK();
    } while (!bVar2);
    if (uVar1 == 0) {
      ExQueueWorkItem(&PepPcieD3ColdUpdateWorkItem,1);
    }
    ExReleasePushLockExclusiveEx(&PepPcieD3ColdUpdateWorkerLock,0);
  }
  return;
}



===== PepSubsystemResetDebugPkgCounters @ 140096de0 =====

void PepSubsystemResetDebugPkgCounters(longlong param_1)

{
  undefined8 *puVar1;
  
  if (PepSubsystemEnableDebugPkgCounters != '\0') {
    puVar1 = *(undefined8 **)(param_1 + 200);
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    if (*(longlong *)(param_1 + 0x18) != 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x18) = 0;
    }
  }
  return;
}



===== _tlgEnableCallback @ 140096e20 =====

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



===== PepSubsystemResetLtrCounters @ 140096ea0 =====

void PepSubsystemResetLtrCounters(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x18) = 0;
    *(undefined8 *)(lVar1 + 0x40) = 0;
    *(undefined8 *)(lVar1 + 0x68) = 0;
    *(undefined8 *)(lVar1 + 0x90) = 0;
    *(undefined8 *)(lVar1 + 0xb8) = 0;
    *(undefined8 *)(lVar1 + 0xe0) = 0;
    *(undefined8 *)(lVar1 + 0x108) = 0;
  }
  return;
}



===== PepPcieAbandonDevice @ 140096ee0 =====

void PepPcieAbandonDevice(undefined8 param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (PepPcieGeneratePcieHierarchyEnabled != '\0') {
    plVar7 = (longlong *)0x0;
    ExAcquirePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    for (plVar8 = PepPcieRootPortList; (longlong **)plVar8 != &PepPcieRootPortList;
        plVar8 = (longlong *)*plVar8) {
      iVar6 = RtlCompareUnicodeString(plVar8[5] + 0x20,param_1,1);
      if (iVar6 == 0) {
        plVar7 = (longlong *)plVar8[5];
        local_28 = (undefined4)plVar7[4];
        uStack_24 = *(undefined4 *)((longlong)plVar7 + 0x24);
        uStack_20 = (undefined4)plVar7[5];
        uStack_1c = *(undefined4 *)((longlong)plVar7 + 0x2c);
        DbgPrintEx(0x92,3,
                   "INTELPEP: PepPcieAbandonDevice Rp Name:(%wZ), Device Type: %d, Location Bus: %d, Device: %d, Function:%d \n"
                   ,&local_28,(int)plVar7[6],*(undefined4 *)((longlong)plVar7 + 0x34),
                   *(uint *)(plVar7 + 7) & 0x1f,*(uint *)(plVar7 + 7) >> 5 & 7);
        lVar1 = *plVar8;
        if ((*(longlong **)(lVar1 + 8) != plVar8) ||
           (plVar3 = (longlong *)plVar8[1], (longlong *)*plVar3 != plVar8)) goto LAB_140097416;
        *plVar3 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar3;
        if ((longlong *)plVar8[2] != plVar8 + 2) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        plVar8[5] = 0;
        ExFreePoolWithTag(plVar8,0x49504550);
        break;
      }
      plVar3 = plVar8 + 2;
      for (plVar9 = (longlong *)plVar8[2]; plVar9 != plVar3; plVar9 = (longlong *)*plVar9) {
        iVar6 = RtlCompareUnicodeString(plVar9[3] + 0x20,param_1,1);
        if (iVar6 == 0) {
          plVar7 = (longlong *)plVar9[3];
          if (((PepPcieGeneratedConstraintEnabled != '\0') && ((char)plVar9[4] != '\0')) &&
             ((plVar8[0x14] & 0xffee000000000000U) != 0xffee000000000000)) {
            LOCK();
            *(int *)(plVar8 + 8) = (int)plVar8[8] + -1;
            UNLOCK();
            PepPcieQueueConstraintWork((longlong)plVar8,1);
          }
          local_38 = (undefined4)plVar7[4];
          uStack_34 = *(undefined4 *)((longlong)plVar7 + 0x24);
          uStack_30 = (undefined4)plVar7[5];
          uStack_2c = *(undefined4 *)((longlong)plVar7 + 0x2c);
          DbgPrintEx(0x92,3,
                     "INTELPEP: PepPcieAbandonDevice EP Name:(%wZ), Device Type: %d, Location Bus: %d, Device: %d, Function:%d \n"
                     ,&local_38,(int)plVar7[6],*(undefined4 *)((longlong)plVar7 + 0x34),
                     *(uint *)(plVar7 + 7) & 0x1f,*(uint *)(plVar7 + 7) >> 5 & 7);
          lVar1 = *plVar9;
          if ((*(longlong **)(lVar1 + 8) != plVar9) ||
             (plVar2 = (longlong *)plVar9[1], (longlong *)*plVar2 != plVar9)) goto LAB_140097416;
          *plVar2 = lVar1;
          *(longlong **)(lVar1 + 8) = plVar2;
          if ((*(uint *)(plVar9 + 8) >> 10 & 1) == 0) {
            LOCK();
            plVar2 = plVar8 + 0x15;
            lVar1 = *plVar2;
            *(int *)plVar2 = (int)*plVar2;
            UNLOCK();
            if (0 < (int)lVar1) {
              LOCK();
              plVar2 = plVar8 + 0x15;
              lVar1 = *plVar2;
              *(int *)plVar2 = (int)*plVar2 + -1;
              UNLOCK();
              if (((longlong *)*plVar3 != plVar3) && ((int)lVar1 == 1)) {
                LOCK();
                *(int *)(plVar8 + 8) = (int)plVar8[8] + 1;
                UNLOCK();
                PepPcieQueueConstraintWork((longlong)plVar8,1);
              }
            }
          }
          if (plVar9[7] != 0) {
            ExFreePoolWithTag(plVar9[7],0x49504550);
            plVar9[7] = 0;
          }
          plVar9[3] = 0;
          ExFreePoolWithTag(plVar9);
          break;
        }
      }
    }
    ExReleasePushLockExclusiveEx(&PepPcieRootPortListLock,0);
    if (plVar7 == (longlong *)0x0) {
      ExAcquirePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
      for (plVar8 = PepPcieRCiEPList; (longlong **)plVar8 != &PepPcieRCiEPList;
          plVar8 = (longlong *)*plVar8) {
        iVar6 = RtlCompareUnicodeString(plVar8[2] + 0x20,param_1,1);
        if (iVar6 == 0) {
          plVar7 = (longlong *)plVar8[2];
          local_28 = (undefined4)plVar7[4];
          uStack_24 = *(undefined4 *)((longlong)plVar7 + 0x24);
          uStack_20 = (undefined4)plVar7[5];
          uStack_1c = *(undefined4 *)((longlong)plVar7 + 0x2c);
          DbgPrintEx(0x92,3,
                     "INTELPEP: PepPcieAbandonDevice RCiEP Name:(%wZ), Device Type: %d, Location Bus: %d, Device: %d, Function:%d \n"
                     ,&local_28,(int)plVar7[6],*(undefined4 *)((longlong)plVar7 + 0x34),
                     *(uint *)(plVar7 + 7) & 0x1f,*(uint *)(plVar7 + 7) >> 5 & 7);
          lVar1 = *plVar8;
          if ((*(longlong **)(lVar1 + 8) != plVar8) ||
             (plVar3 = (longlong *)plVar8[1], (longlong *)*plVar3 != plVar8)) goto LAB_140097416;
          *plVar3 = lVar1;
          *(longlong **)(lVar1 + 8) = plVar3;
          plVar8[2] = 0;
          RtlInitUnicodeString(&local_58,L"");
          cVar5 = RtlEqualUnicodeString(plVar8 + 7,&local_58,0);
          if ((cVar5 == '\0') && (plVar8[8] != 0)) {
            ExFreePoolWithTag(plVar8[8],0x49504550);
          }
          ExFreePoolWithTag(plVar8,0x49504550);
          break;
        }
      }
      ExReleasePushLockExclusiveEx(&PepPcieRCiEPListLock,0);
      if (plVar7 == (longlong *)0x0) {
        return;
      }
    }
    ExAcquirePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
    local_28 = (undefined4)plVar7[4];
    uStack_24 = *(undefined4 *)((longlong)plVar7 + 0x24);
    uStack_20 = (undefined4)plVar7[5];
    uStack_1c = *(undefined4 *)((longlong)plVar7 + 0x2c);
    DbgPrintEx(0x92,3,
               "INTELPEP: PepPcieAbandonDevice PCIe Name:(%wZ)removed from PepPcieDeviceMapList, Device Type: %d \n"
               ,&local_28,(int)plVar7[6]);
    lVar1 = *plVar7;
    if ((*(longlong **)(lVar1 + 8) != plVar7) ||
       (plVar8 = (longlong *)plVar7[1], (longlong *)*plVar8 != plVar7)) {
LAB_140097416:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar8 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar8;
    RtlInitUnicodeString(&local_48,L"FriendlyNameNotFound");
    cVar5 = RtlEqualUnicodeString(plVar7 + 8,&local_48,0);
    if ((cVar5 == '\0') && (plVar7[9] != 0)) {
      ExFreePoolWithTag(plVar7[9],0x49504550);
    }
    ExFreePoolWithTag(plVar7[5],0x49504550);
    ExFreePoolWithTag(plVar7,0x49504550);
    ExReleasePushLockExclusiveEx(&PepPcieDeviceMapListLock,0);
  }
  return;
}



===== PepSubsystemResetPciLinkAccounting @ 140097430 =====

void PepSubsystemResetPciLinkAccounting(longlong param_1)

{
  longlong lVar1;
  
  if ((param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x30) = 0;
    *(undefined8 *)(lVar1 + 0x28) = 0;
    *(undefined8 *)(lVar1 + 0x60) = 0;
    *(undefined8 *)(lVar1 + 0x58) = 0;
    *(undefined8 *)(lVar1 + 0x90) = 0;
    *(undefined8 *)(lVar1 + 0x88) = 0;
    *(undefined8 *)(lVar1 + 0xc0) = 0;
    *(undefined8 *)(lVar1 + 0xb8) = 0;
  }
  return;
}



===== PepSubsystemResetPowerGatingDomains @ 140097480 =====

void PepSubsystemResetPowerGatingDomains(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (((*(int *)(param_1 + 0x14) - 4U & 0xfffffffb) == 0) &&
     (puVar1 = *(uint **)(param_1 + 0x18), puVar1 != (uint *)0x0)) {
    lVar2 = *(longlong *)(puVar1 + 2);
    uVar4 = 0;
    if (*puVar1 != 0) {
      do {
        uVar3 = (int)uVar4 + 1;
        *(undefined8 *)(lVar2 + 0x18 + uVar4 * 0x28) = 0;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < *puVar1);
    }
  }
  return;
}



===== PepRegisterDevice @ 1400974c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte PepRegisterDevice(ushort *param_1,undefined8 param_2,ulonglong *param_3,undefined8 *param_4)

{
  uint uVar1;
  longlong lVar2;
  short *psVar3;
  ulonglong uVar4;
  byte bVar5;
  longlong lVar6;
  ulonglong uVar7;
  bool bVar8;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  bVar5 = 0;
  bVar8 = PepPcieGeneratePcieHierarchyEnabled != '\0';
  *param_4 = 0;
  if (bVar8) {
    psVar3 = PepPcieFindDeviceMatch(param_1,param_2,param_3);
    if (psVar3 != (short *)0x0) {
      *param_4 = psVar3;
      DbgPrintEx(0x92,3,"INTELPEP: Successfully registered PCIe device (%wZ, RegInfo: %p)\n",param_1
                 ,psVar3);
      bVar5 = -(*(longlong *)(psVar3 + 0x18) != 0) & 2;
      goto LAB_140097652;
    }
  }
  psVar3 = (short *)PepFindDeviceMatch(param_1);
  if (psVar3 != (short *)0x0) {
    if (PepPlatformAoAc == '\0') {
      *(undefined8 *)(psVar3 + 8) = param_2;
      DbgPrintEx(0x92,3,"INTELPEP: Successfully registered device (%wZ, RegInfo: %p)\n",param_1,
                 psVar3);
      *param_4 = psVar3;
      bVar5 = 2;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,PepDeviceKernelHandleMutex,0);
      lVar6 = *(longlong *)(psVar3 + 8);
      if (lVar6 == 0) {
        *(undefined8 *)(psVar3 + 8) = param_2;
        DbgPrintEx(0x92,3,"INTELPEP: Successfully registered device (%wZ, RegInfo: %p)\n",param_1,
                   psVar3);
        *param_4 = psVar3;
        bVar5 = 2;
      }
      else {
        local_28 = *(undefined4 *)psVar3;
        uStack_24 = *(undefined4 *)(psVar3 + 2);
        uStack_20 = *(undefined4 *)(psVar3 + 4);
        uStack_1c = *(undefined4 *)(psVar3 + 6);
        DbgPrintEx(0x92,1,
                   "INTELPEP: Cannot register device (%wZ) as another device already matched descriptor %wZ \n"
                   ,param_1,&local_28);
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))();
      if (*(char *)((longlong)psVar3 + 0x19) != '\0') {
        PepUpdateNumUnregisteredDevices('\0');
        if (lVar6 != 0) {
          PepPlatformIdleVetoEvent(2,'\x01');
        }
      }
    }
  }
LAB_140097652:
  if ((((PepPlatformAoAc != '\0') && (psVar3 != (short *)0x0)) &&
      (*(longlong *)(psVar3 + 0x10) != 0)) && (PepNumPlatformStates != 0)) {
    lVar6 = 0;
    uVar7 = (ulonglong)PepNumPlatformStates;
    do {
      lVar2 = *(longlong *)(psVar3 + 0x10);
      if ((*(int *)(lVar2 + lVar6) < 2) && (uVar1 = *(uint *)(lVar2 + 4 + lVar6), uVar1 != 0)) {
        for (uVar4 = 0; (uint)uVar4 < (uint)param_3[1]; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
          if (*(uint *)(param_3[uVar4 + 2] + 0x1c) <= uVar1) {
            *(undefined4 *)(lVar2 + lVar6) = 2;
            break;
          }
        }
      }
      lVar6 = lVar6 + 8;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return bVar5;
}



===== PepDiagLogEnergyReportingCapabilities @ 1400976e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PepDiagLogEnergyReportingCapabilities
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  byte *pbVar3;
  char cVar4;
  char cVar5;
  undefined7 uVar6;
  undefined1 auStackY_c8 [32];
  undefined4 uVar7;
  char local_98;
  char local_97 [7];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  char *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  cVar1 = PepSubsystemEnableDebugPchCounters;
  cVar4 = (char)param_3;
  uVar6 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_90 = 0;
  if (param_1 == (undefined8 *)0x0) {
    if (cVar4 == '\0') {
      return;
    }
    if (DAT_1400340a0 < 6) {
      return;
    }
    uVar2 = _tlgKeywordOn(0x1400340a0,0x400000000000);
    if ((char)uVar2 == '\0') {
      return;
    }
    local_58 = &local_88;
    local_88 = 0x1000000;
    pbVar3 = &DAT_14002e12b;
    uVar7 = 3;
  }
  else {
    if ((int *)*param_1 == (int *)0x0) {
      if (cVar4 == '\0') {
        if (DAT_1400340a0 < 6) {
          return;
        }
        pbVar3 = &DAT_14002e1b6;
        uVar7 = 2;
      }
      else {
        if (DAT_1400340a0 < 6) {
          return;
        }
        uVar2 = _tlgKeywordOn(0x1400340a0,0x400000000000);
        if ((char)uVar2 == '\0') {
          return;
        }
        pbVar3 = &DAT_14002dc02;
        uVar7 = 2;
      }
      goto LAB_1400978fc;
    }
    cVar5 = cVar4;
    PepReadRegister((int *)*param_1,(uint *)&local_90);
    if (cVar4 == '\0') {
      if (DAT_1400340a0 < 6) {
        return;
      }
      pbVar3 = &DAT_14002fd33;
      local_58 = &local_80;
      local_48 = local_97;
      uVar7 = 5;
      local_97[0] = cVar1;
      local_40 = 1;
      local_98 = '\0';
    }
    else {
      if (DAT_1400340a0 < 6) {
        return;
      }
      uVar2 = _tlgKeywordOn(0x1400340a0,0x400000000000);
      if ((char)uVar2 == '\0') {
        return;
      }
      local_58 = &local_88;
      local_88 = 0x1000000;
      pbVar3 = &DAT_14002f43b;
      local_48 = (char *)&local_80;
      local_28 = local_97;
      uVar7 = 6;
      local_40 = 8;
      local_98 = cVar1;
      local_20 = 1;
      local_97[0] = cVar4;
    }
    local_38 = &local_98;
    local_30 = 1;
    cVar4 = cVar5;
    local_80 = local_90;
  }
  local_50 = 8;
LAB_1400978fc:
  _tlgWriteTransfer_EtwWriteTransfer
            (0x1400340a0,pbVar3,CONCAT71(uVar6,cVar4),param_4,uVar7,local_78);
  return;
}



===== PepRegisterPlugin @ 140098008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PepRegisterPlugin(undefined8 *param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined8 *puVar10;
  int *piVar11;
  int local_res10 [2];
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_88;
  code *local_80;
  code *local_78;
  undefined8 local_70;
  ulonglong local_68 [5];
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res10[0] = 0;
  local_88 = (ulonglong)(uint)local_88;
  uVar2 = 0xc0000001;
  local_78 = (code *)0x0;
  local_70 = 0;
  local_res20 = 0;
  local_res18 = 0;
  local_68[0] = (ulonglong)(uint)local_68[0];
  PepNumProcessors = PepGetProcessorCount();
  if ((PepNumProcessors != 0) && (uVar2 = PepInitializeProcessorContext(), -1 < (int)uVar2)) {
    PepPlatformAoAc = PepQueryPlatformAoAc();
    PepInitializePlatformNotificationSupport();
    local_38 = 0;
    local_68[2] = 0;
    uStack_40 = 0;
    local_68[4] = PepWdfDevice;
    local_68[1] = 0;
    local_68[0] = 0x38;
    local_68[3] = 0x100000001;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,local_68,&PepVetoMutex);
    if (-1 < (int)uVar2) {
      if (PepPlatformAoAc != '\0') {
        uVar4 = PepAcpiGetPlatformStateInfo((longlong)param_1,&PepPlatformIdleStates);
        if ((int)(uint)uVar4 < 0) {
          return (uint)uVar4;
        }
        PepNumPlatformStates = PepPlatformIdleStates;
        if (PepPlatformIdleStates != 0) {
          PepDripsIndex = PepPlatformIdleStates + -1;
        }
        local_38 = 0;
        local_68[2] = 0;
        uStack_40 = 0;
        local_68[4] = PepWdfDevice;
        local_68[1] = 0;
        local_68[0] = 0x38;
        local_68[3] = 0x100000001;
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                          (WdfDriverGlobals,local_68,&PepDeviceKernelHandleMutex);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        local_38 = 0;
        local_68[2] = 0;
        uStack_40 = 0;
        local_68[4] = PepWdfDevice;
        local_68[1] = 0;
        local_68[0] = 0x38;
        local_68[3] = 0x100000001;
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                          (WdfDriverGlobals,local_68,&PepNumUnregisteredDevicesMutex);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        PepInitializeResidencyCounters();
        uVar2 = PepAcpiGetDeviceDependencyInfo(param_1);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        PepSubsystemIdentifySoC();
        PepSubsystemDetectLtrStatusReportingRequired();
        PepSubsystemIntcPmtAccessRequired();
        PepSubsystemGetRegistryOverrides();
        PepSubsystemGetVelocityOverrides();
        local_res10[0] = 1;
        EmClientQueryRuleState(&GUID_EM_RULE_IGNORE_MISSING_DEPENDENCIES,local_res10);
        if (local_res10[0] == 2) {
          uVar2 = 0;
          PepErrataIgnoreMissingDependencies = 1;
          if (PepKnownDeviceCount != 0) {
            do {
              uVar4 = (ulonglong)uVar2;
              uVar2 = uVar2 + 1;
              *(undefined1 *)(uVar4 * 0x38 + 0x19 + PepKnownDeviceList) = 0;
            } while (uVar2 < PepKnownDeviceCount);
          }
        }
        if (PepKnownDeviceCount != 0) {
          uVar4 = (ulonglong)PepKnownDeviceCount;
          pcVar5 = (char *)(PepKnownDeviceList + 0x19);
          do {
            if (*pcVar5 != '\0') {
              PepNumUnregisteredDevices = PepNumUnregisteredDevices + 1;
            }
            pcVar5 = pcVar5 + 0x38;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        if (0 < PepNumUnregisteredDevices) {
          PepPlatformIdleVetoEvent(1,'\x01');
        }
        PepAcpiGetSerialDebugDeviceName((longlong)param_1);
      }
      iVar3 = PepAcpiGetBugCheckCriticalDeviceInfo(param_1);
      if ((-1 < iVar3) && (uVar4 = 0, *PepBccdList != 0)) {
        do {
          puVar1 = *(ushort **)(PepBccdList + uVar4 * 2 + 2);
          PepBccdInitialize((longlong)puVar1);
          PepMarkAsBccd(puVar1,puVar1);
          uVar2 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar2;
        } while (uVar2 < *PepBccdList);
      }
      memset(&DAT_140087784,0,0x54);
      local_80 = PepAcceptDeviceNotification;
      local_78 = (code *)0x0;
      _PepKernelInformation = 0x580002;
      if (PepPlatformAoAc != '\0') {
        local_78 = PepAcceptProcessorNotification;
      }
      local_88 = 0x200002;
      local_70 = 0;
      uVar2 = PoFxRegisterPluginEx(&local_88);
      if (-1 < (int)uVar2) {
        if ((DAT_140087782 == 0x58) && (PepKernelInformation == 2)) {
          if (PepPlatformAoAc != '\0') {
            uVar2 = ExSubscribeWnfStateChange
                              (&local_res18,&WNF_PO_WAKE_ON_VOICE_STATE,1,0,
                               PepWnfWakeOnVoiceCallback,0);
            if ((int)uVar2 < 0) {
              return uVar2;
            }
            uVar2 = ExSubscribeWnfStateChange
                              (&local_res20,&WNF_PO_SCENARIO_CHANGE,1,0,
                               PepWnfSleepStudySessionInfoCallback,0);
            if ((int)uVar2 < 0) {
              return uVar2;
            }
            KeInitializeEvent(&PepSubsystemCounterAccountingInitFinished);
          }
          McGenEventRegister_EtwRegister();
          piVar11 = (int *)&PepSleepStudyEtwHandle;
          puVar10 = (undefined8 *)0x0;
          uVar8 = 0;
          puVar7 = (undefined8 *)&SLEEPSTUDY_ETW_PROVIDER;
          uVar2 = EtwRegister();
          if (-1 < (int)uVar2) {
            PepSleepStudyEtwHandleRegistered = 1;
            PepDiagInitializeProvider();
            PepPcieEvaluateSecurePciEnabled();
            PepPcieEvaluateGeneratePcieHierarchyEnabled(puVar7,uVar8,puVar10,piVar11);
            if (PepPcieGeneratePcieHierarchyEnabled == '\0') {
              PepPcieLtrOverrideEnabled = '\0';
              PepPcieGeneratedConstraintEnabled = '\0';
              PepPcieGeneratedConstraintRCiEPEnabled = '\0';
            }
            else {
              PepPcieInitializeHelper();
              uVar9 = 0;
              PepPcieEvaluateLtrOverrideEnabled(puVar7,uVar8,puVar10,piVar11);
              if (PepPcieLtrOverrideEnabled != '\0') {
                uVar6 = PepPcieInitRootPortRangeTable();
                if ((int)uVar6 < 0) {
                  PepPcieLtrOverrideEnabled = '\0';
                }
                else {
                  PepPcieLtrOverrideInit();
                  uVar9 = 1;
                }
              }
              puVar10 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar10 >> 8),uVar9);
              PepDiagLogLtrOverrideEnabled(puVar7,uVar8,puVar10,piVar11);
              PepPcieEvalulateGeneratedConstraintsEnabled();
              if (PepPcieGeneratedConstraintEnabled != '\0') {
                puVar10 = (undefined8 *)0x0;
                (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
                if (0 < PepNumUnregisteredDevices) {
                  PepNumUnregisteredDevices = 0;
                  PepPlatformIdleVetoEvent(1,'\0');
                }
                puVar7 = WdfDriverGlobals;
                uVar8 = PepNumUnregisteredDevicesMutex;
                (**(code **)(WdfFunctions_01015 + 0x9d0))();
                uVar2 = PepPcieRegisterCallbacks();
                if ((int)uVar2 < 0) {
                  return uVar2;
                }
              }
              PepPcieEvalulateRCiEPGeneratedConstraintsEnabled(puVar7,uVar8,puVar10,piVar11);
            }
            if (((PepPcieLtrOverrideEnabled == '\0') && (PepPcieGeneratedConstraintEnabled == '\0'))
               && (PepPcieGeneratedConstraintRCiEPEnabled == '\0')) {
              PepPcieGeneratePcieHierarchyEnabled = '\0';
            }
            uVar4 = Feature_Servicing_IntelPepPtlHWDrips__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar4 == 0) {
              PepRegisterIntelCtaInterfaceChange((ulonglong)puVar7);
            }
            else {
              PepRegisterIntelCtaInterfaceChangeV1((ulonglong)puVar7);
            }
            PepTraceRundownDeviceConstraints('\x01',uVar8,puVar10,(longlong)piVar11);
            PepTraceRundownComponentConstraints('\x01',uVar8,puVar10,(undefined8 *)piVar11);
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0xc0000001;
        }
      }
    }
  }
  return uVar2;
}



===== PepAcpiGetBugCheckCriticalDeviceInfo @ 140098598 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PepAcpiGetBugCheckCriticalDeviceInfo(undefined8 *param_1)

{
  uint *puVar1;
  short *psVar2;
  ushort uVar3;
  int iVar4;
  uint *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  short *psVar9;
  ulonglong uVar10;
  ushort uVar11;
  char *pcVar12;
  short *psVar13;
  short *psVar14;
  uint uVar15;
  longlong lVar16;
  uint uVar17;
  longlong lVar18;
  undefined1 auStackY_1f8 [32];
  longlong local_1a0;
  uint local_198;
  short *local_190;
  byte local_188 [2];
  undefined4 local_186;
  char *local_180;
  code *local_178;
  undefined1 local_170;
  undefined4 local_16e;
  char *local_168;
  code *local_160;
  undefined1 local_158;
  undefined4 local_156;
  char *local_150;
  code *local_148;
  byte local_138 [2];
  undefined4 local_136;
  char *local_130;
  code *local_128;
  undefined1 local_120;
  undefined4 local_11e;
  char *local_118;
  code *local_110;
  undefined1 local_108;
  undefined4 local_106;
  char *local_100;
  code *local_f8;
  undefined1 local_f0;
  undefined4 local_ee;
  char *local_e8;
  code *local_e0;
  undefined1 local_d8;
  undefined4 local_d6;
  char *local_d0;
  code *local_c8;
  char local_b8 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_11e = 0x40000;
  local_138[0] = 0;
  local_136 = 0;
  local_128 = PepAcpiParseULong;
  local_110 = PepAcpiParseULong;
  local_130 = "AddressId";
  local_120 = 1;
  local_118 = "BitWidth";
  local_108 = 2;
  local_100 = "BitOffset";
  uVar15 = 0;
  local_106 = 0x80000;
  local_f0 = 3;
  uVar7 = 0;
  local_f8 = PepAcpiParseULong;
  local_e8 = "AccessSize";
  puVar5 = (uint *)0x0;
  local_ee = 0xc0000;
  local_d0 = "PwrCtrlAddress";
  local_180 = "AndMask";
  local_168 = "OrMask";
  local_150 = "TriggerType";
  local_e0 = PepAcpiParseULong;
  local_d8 = 4;
  local_d6 = 0x280000;
  local_c8 = PepAcpiParseULong64;
  local_188[0] = 0;
  local_186 = 0;
  local_178 = PepAcpiParseULong64;
  local_170 = 1;
  local_16e = 0x80000;
  local_160 = PepAcpiParseULong64;
  local_158 = 2;
  local_156 = 0x100000;
  local_148 = PepAcpiParseULong;
  local_1a0 = 0;
  if ((*(uint *)(param_1 + 1) >> 2 & 1) == 0) {
    return -0x3ffffffe;
  }
  iVar4 = PepAcpiEval_DSM(param_1,PepAcpiParseULong64,2,&local_1a0);
  lVar16 = local_1a0;
  if (iVar4 < 0) {
    DbgPrintEx(0x92,1,"INTELPEP: BIOS WARNING: Unable to obtain BCCD list.\n");
    lVar16 = local_1a0;
    goto LAB_140098db5;
  }
  uVar15 = *(uint *)(local_1a0 + 8);
  if (uVar15 == 0) {
    iVar4 = -0x3fffffff;
    pcVar12 = "INTELPEP: BIOS WARNING: BCCD returned 0 devices!\n";
LAB_140098731:
    DbgPrintEx(0x92,1,pcVar12);
  }
  else {
    puVar1 = (uint *)(local_1a0 + 4);
    if (0x13 < *puVar1) {
      puVar5 = (uint *)ExAllocatePool2(0x40,uVar15 * 8 + 8,0x49504550);
      if (puVar5 == (uint *)0x0) {
        iVar4 = -0x3fffff66;
        pcVar12 = "INTELPEP: BIOS WARNING: Could not allocate memory for BCCD list.\n";
        goto LAB_140098731;
      }
      *puVar5 = uVar15;
      psVar2 = (short *)(lVar16 + 0xc);
      if ((psVar2 < (short *)(lVar16 + 0x14U)) &&
         (psVar13 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
         (short *)(lVar16 + 0x14U) <= psVar13)) {
        uVar11 = *(ushort *)(lVar16 + 0xe);
        uVar8 = (ulonglong)uVar11;
        uVar6 = 4;
        if (3 < uVar11) {
          uVar6 = uVar8;
        }
        if (psVar2 < (short *)(uVar6 + 4 + (longlong)psVar2)) {
          if (uVar11 < 4) {
            uVar8 = 4;
          }
          if ((short *)(lVar16 + 0x10 + uVar8) <= psVar13) {
            uVar11 = 0;
            psVar13 = psVar2;
            while( true ) {
              uVar6 = 4;
              uVar7 = 0;
              if (uVar15 <= uVar11) break;
              if (((psVar13 < psVar2) || (psVar13 + 4 <= psVar13)) ||
                 (psVar9 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                 psVar9 < psVar13 + 4)) goto LAB_140098daa;
              uVar3 = psVar13[1];
              uVar8 = uVar6;
              if (3 < uVar3) {
                uVar8 = (ulonglong)uVar3;
              }
              if ((short *)(uVar8 + 4 + (longlong)psVar13) <= psVar13) goto LAB_140098daa;
              uVar8 = (ulonglong)uVar3;
              if (uVar3 < 4) {
                uVar8 = uVar6;
              }
              if (psVar9 < (short *)(uVar8 + 4 + (longlong)psVar13)) goto LAB_140098daa;
              if (*psVar13 != 3) {
                pcVar12 = "INTELPEP: BIOS WARNING: BCCD parse error: Package argument expected.\n";
LAB_140098f87:
                iVar4 = -0x3febfff8;
                DbgPrintEx(0x92,1,pcVar12);
                goto LAB_140098db5;
              }
              if (((uVar3 < 8) || (psVar14 = psVar13 + 2, psVar14 < psVar2)) ||
                 ((psVar13 + 6 <= psVar14 || (psVar9 < psVar13 + 6)))) goto LAB_140098daa;
              uVar3 = psVar13[3];
              uVar8 = uVar6;
              if (3 < uVar3) {
                uVar8 = (ulonglong)uVar3;
              }
              if ((short *)(uVar8 + 4 + (longlong)psVar14) <= psVar14) goto LAB_140098daa;
              uVar8 = (ulonglong)uVar3;
              if (uVar3 < 4) {
                uVar8 = uVar6;
              }
              if (psVar9 < (short *)(uVar8 + 4 + (longlong)psVar14)) goto LAB_140098daa;
              if (*psVar14 != 1) {
                pcVar12 = "INTELPEP: BIOS WARNING: BCCD parse error - String  argument expected.\n";
                goto LAB_140098f87;
              }
              strncpy_s(local_b8,0x80,(char *)(psVar13 + 4),0xffffffffffffffff);
              if ((ushort)psVar13[3] < 4) {
                uVar6 = 4;
              }
              else {
                uVar6 = (ulonglong)(ushort)psVar13[3];
                lVar16 = local_1a0;
              }
              psVar13 = (short *)((longlong)psVar13 + uVar6 + 8);
              if (((psVar13 < psVar2) || (psVar13 + 4 <= psVar13)) ||
                 (psVar9 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                 psVar9 < psVar13 + 4)) goto LAB_140098daa;
              uVar3 = psVar13[1];
              uVar8 = (ulonglong)uVar3;
              uVar6 = 4;
              if (3 < uVar3) {
                uVar6 = uVar8;
              }
              if ((short *)(uVar6 + 4 + (longlong)psVar13) <= psVar13) goto LAB_140098daa;
              uVar6 = uVar8;
              if (uVar3 < 4) {
                uVar6 = 4;
              }
              if (psVar9 < (short *)(uVar6 + 4 + (longlong)psVar13)) goto LAB_140098daa;
              if (*psVar13 != 3) {
                pcVar12 = "INTELPEP: BIOS WARNING: BCCD parse error - Package  argument expected.\n"
                ;
                goto LAB_140098f87;
              }
              if (uVar3 != 0) {
                psVar9 = psVar13 + 2;
                psVar14 = (short *)(uVar8 + (longlong)psVar9);
                if (psVar9 < psVar14) {
                  do {
                    uVar6 = (ulonglong)(ushort)psVar9[1];
                    if ((ushort)psVar9[1] < 4) {
                      uVar6 = 4;
                    }
                    uVar17 = (int)uVar7 + 1;
                    uVar7 = (ulonglong)uVar17;
                    psVar9 = (short *)((longlong)psVar9 + uVar6 + 4);
                  } while (psVar9 < psVar14);
                  if (uVar17 != 0) {
                    uVar7 = ExAllocatePool2(0x40,uVar17 * 0x60 + 0x20,0x49504550);
                    if (uVar7 == 0) {
                      pcVar12 = 
                      "INTELPEP: BIOS WARNING: Could not allocate memory for BCCD powerup actions.\n"
                      ;
                    }
                    else {
                      *(uint *)(uVar7 + 0x10) = uVar17;
                      iVar4 = PepAcpiInitUnicodeString(uVar7);
                      if (-1 < iVar4) {
                        local_198 = 0;
                        local_190 = (short *)((ulonglong)(ushort)psVar13[1] + 4 + (longlong)psVar13)
                        ;
                        uVar6 = 0;
                        psVar9 = psVar13 + 2;
                        if (((psVar2 <= psVar9) && (psVar9 < psVar13 + 6)) &&
                           (psVar14 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                           psVar13 + 6 <= psVar14)) {
                          uVar3 = psVar13[3];
                          uVar10 = (ulonglong)uVar3;
                          uVar8 = 4;
                          if (3 < uVar3) {
                            uVar8 = uVar10;
                          }
                          if (psVar9 < (short *)(uVar8 + 4 + (longlong)psVar9)) {
                            if (uVar3 < 4) {
                              uVar10 = 4;
                            }
                            if ((short *)(uVar10 + 4 + (longlong)psVar9) <= psVar14) {
                              while (psVar9 < local_190) {
                                if (*psVar9 != 3) {
                                  iVar4 = -0x3febfff8;
                                  pcVar12 = 
                                  "INTELPEP: BIOS WARNING: BCCD parse error: PowerUp Package argument expected.\n"
                                  ;
                                  goto LAB_140098f4e;
                                }
                                psVar13 = psVar9 + 2;
                                if (((psVar13 < psVar2) || (psVar9 + 6 <= psVar13)) ||
                                   (psVar14 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                                   psVar14 < psVar9 + 6)) goto LAB_140098daa;
                                uVar3 = psVar9[3];
                                uVar10 = (ulonglong)uVar3;
                                uVar8 = 4;
                                if (3 < uVar3) {
                                  uVar8 = (ulonglong)(uint)uVar3;
                                }
                                if ((short *)(uVar8 + 4 + (longlong)psVar13) <= psVar13)
                                goto LAB_140098daa;
                                if (uVar3 < 4) {
                                  uVar10 = 4;
                                }
                                if (psVar14 < (short *)(uVar10 + 4 + (longlong)psVar13))
                                goto LAB_140098daa;
                                if (*psVar13 != 3) {
                                  iVar4 = -0x3febfff8;
                                  pcVar12 = 
                                  "INTELPEP: BIOS WARNING: BCCD parse error: GAS Package argument expected.\n"
                                  ;
                                  goto LAB_140098f4e;
                                }
                                lVar18 = uVar6 * 0x60;
                                iVar4 = PepAcpiParseCore(local_138,5,psVar9 + 4,
                                                         (ulonglong)(uint)uVar3,
                                                         lVar18 + 0x28 + uVar7,0x38,"BCCD-GAS");
                                if (iVar4 < 0) {
                                  pcVar12 = "INTELPEP: BIOS WARNING: BCCD-GAS parse error for %s.\n"
                                  ;
LAB_140098efd:
                                  DbgPrintEx(0x92,1,pcVar12,local_b8);
                                  goto LAB_140098f68;
                                }
                                if ((ushort)psVar9[3] < 4) {
                                  uVar6 = 4;
                                }
                                else {
                                  uVar6 = (ulonglong)(ushort)psVar9[3];
                                  lVar16 = local_1a0;
                                }
                                psVar9 = (short *)((longlong)psVar9 + uVar6 + 8);
                                if (((psVar9 < psVar2) || (psVar9 + 4 <= psVar9)) ||
                                   (psVar13 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                                   psVar13 < psVar9 + 4)) goto LAB_140098daa;
                                uVar3 = psVar9[1];
                                uVar8 = (ulonglong)uVar3;
                                uVar6 = 4;
                                if (3 < uVar3) {
                                  uVar6 = (ulonglong)(uint)uVar3;
                                }
                                if ((short *)(uVar6 + 4 + (longlong)psVar9) <= psVar9)
                                goto LAB_140098daa;
                                if (uVar3 < 4) {
                                  uVar8 = 4;
                                }
                                if (psVar13 < (short *)(uVar8 + 4 + (longlong)psVar9))
                                goto LAB_140098daa;
                                if (*psVar9 != 3) {
                                  iVar4 = -0x3febfff8;
                                  pcVar12 = 
                                  "INTELPEP: BIOS WARNING: BCCD parse error: Mask Package argument expected.\n"
                                  ;
                                  goto LAB_140098f4e;
                                }
                                iVar4 = PepAcpiParseCore(local_188,3,psVar9 + 2,
                                                         (ulonglong)(uint)uVar3,
                                                         uVar7 + 0x60 + lVar18,0x18,"BCCD-MASK");
                                if (iVar4 < 0) {
                                  pcVar12 = 
                                  "INTELPEP: BIOS WARNING: BCCD-MASK parse error for %s.\n";
                                  goto LAB_140098efd;
                                }
                                if ((ushort)psVar9[1] < 4) {
                                  uVar6 = 4;
                                }
                                else {
                                  uVar6 = (ulonglong)(ushort)psVar9[1];
                                  lVar16 = local_1a0;
                                }
                                psVar9 = (short *)(uVar6 + 4 + (longlong)psVar9);
                                if (((psVar9 < psVar2) || (psVar9 + 4 <= psVar9)) ||
                                   (psVar13 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                                   psVar13 < psVar9 + 4)) goto LAB_140098daa;
                                uVar3 = psVar9[1];
                                uVar8 = (ulonglong)uVar3;
                                uVar6 = 4;
                                if (3 < uVar3) {
                                  uVar6 = uVar8;
                                }
                                if ((short *)(uVar6 + 4 + (longlong)psVar9) <= psVar9)
                                goto LAB_140098daa;
                                if (uVar3 < 4) {
                                  uVar8 = 4;
                                }
                                if (psVar13 < (short *)(uVar8 + 4 + (longlong)psVar9))
                                goto LAB_140098daa;
                                if (*psVar9 != 0) {
                                  iVar4 = -0x3febfff8;
                                  pcVar12 = 
                                  "INTELPEP: BIOS WARNING: BCCD parse error: Latency integer argument expected.\n"
                                  ;
                                  goto LAB_140098f4e;
                                }
                                *(undefined4 *)(lVar18 + 0x78 + uVar7) = *(undefined4 *)(psVar9 + 2)
                                ;
                                if ((ushort)psVar9[1] < 4) {
                                  uVar6 = 4;
                                }
                                else {
                                  uVar6 = (ulonglong)(ushort)psVar9[1];
                                  lVar16 = local_1a0;
                                }
                                psVar9 = (short *)(uVar6 + 4 + (longlong)psVar9);
                                if (((psVar9 < psVar2) || (psVar9 + 4 <= psVar9)) ||
                                   (psVar13 = (short *)((ulonglong)(*puVar1 - 0xc) + 0xc + lVar16),
                                   psVar13 < psVar9 + 4)) {
LAB_140098d92:
                                  if (psVar9 < local_190) goto LAB_140098daa;
                                }
                                else {
                                  uVar3 = psVar9[1];
                                  uVar8 = (ulonglong)uVar3;
                                  uVar6 = 4;
                                  if (3 < uVar3) {
                                    uVar6 = uVar8;
                                  }
                                  if ((short *)(uVar6 + 4 + (longlong)psVar9) <= psVar9)
                                  goto LAB_140098d92;
                                  if (uVar3 < 4) {
                                    uVar8 = 4;
                                  }
                                  if (psVar13 < (short *)(uVar8 + 4 + (longlong)psVar9))
                                  goto LAB_140098d92;
                                }
                                local_198 = local_198 + 1;
                                uVar6 = (ulonglong)local_198;
                              }
                              *(ulonglong *)(puVar5 + (ulonglong)uVar11 * 2 + 2) = uVar7;
                              psVar13 = psVar9;
                              goto LAB_140098ec4;
                            }
                          }
                        }
                        goto LAB_140098daa;
                      }
                      pcVar12 = 
                      "INTELPEP: BIOS WARNING: Could not allocate memory for BCCD device name.\n";
                    }
                    iVar4 = -0x3fffff66;
LAB_140098f4e:
                    DbgPrintEx(0x92,1,pcVar12);
LAB_140098f68:
                    goto LAB_140098db5;
                  }
                }
              }
LAB_140098ec4:
              uVar11 = uVar11 + 1;
            }
            PepBccdList = puVar5;
            goto LAB_140098db5;
          }
        }
      }
    }
LAB_140098daa:
    iVar4 = -0x7ffffffb;
  }
LAB_140098db5:
  if (lVar16 != 0) {
    ExFreePoolWithTag(lVar16,0x49504550);
  }
  if (iVar4 < 0) {
    if (uVar7 != 0) {
      RtlFreeUnicodeString(uVar7);
      ExFreePoolWithTag(uVar7,0x49504550);
    }
    if (puVar5 != (uint *)0x0) {
      uVar11 = 0;
      if (uVar15 != 0) {
        do {
          lVar16 = *(longlong *)(puVar5 + (ulonglong)uVar11 * 2 + 2);
          if (lVar16 != 0) {
            RtlFreeUnicodeString(lVar16);
            ExFreePoolWithTag(lVar16,0x49504550);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar15);
      }
      ExFreePoolWithTag(puVar5,0x49504550);
    }
  }
  return iVar4;
}



===== PepAcpiGetSerialDebugDeviceName @ 140098fcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PepAcpiGetSerialDebugDeviceName(longlong param_1)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_288 [32];
  longlong local_268;
  undefined8 local_260;
  undefined1 *puStack_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 local_240;
  undefined8 uStack_238;
  undefined1 local_228 [512];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_288;
  local_260 = 0;
  puStack_258 = (undefined1 *)0x0;
  local_268 = 0;
  bVar1 = false;
  local_240 = 0;
  uStack_238 = 0;
  local_250 = 0;
  uStack_248 = 0;
  iVar2 = PepAcpiGetTable(0x32474244,&local_268);
  if (iVar2 < 0) {
    DbgPrintEx(0x92,2,"INTELPEP: Failed to get DebugPortTable!\n");
  }
  else {
    lVar4 = local_268;
    for (uVar5 = 0; uVar5 < *(uint *)(local_268 + 0x28); uVar5 = uVar5 + 1) {
      lVar4 = lVar4 + (ulonglong)*(uint *)(local_268 + 0x24);
      if (*(short *)(lVar4 + 0xc) == -0x8000) {
        RtlInitAnsiString(&local_240,(ulonglong)*(ushort *)(lVar4 + 6) + lVar4);
        iVar2 = RtlAnsiStringToUnicodeString(&local_250,&local_240,1);
        if (iVar2 < 0) goto LAB_14009916a;
        puStack_258 = local_228;
        bVar1 = true;
        local_260._0_4_ = CONCAT22(0x1fe,(ushort)local_260);
        iVar2 = RtlAppendUnicodeToString(&local_260,L"ACPI\\DEBUG");
        if (iVar2 < 0) goto LAB_140099159;
        iVar2 = RtlAppendUnicodeStringToString(&local_260,&local_250);
        if (iVar2 < 0) goto LAB_140099159;
        lVar4 = ExAllocatePool2(0x100,local_260 & 0xffff,0x49504550);
        *(longlong *)(param_1 + 0x40) = lVar4;
        if (lVar4 != 0) {
          *(ushort *)(param_1 + 0x38) = 0;
          *(ushort *)(param_1 + 0x3a) = (ushort)local_260;
          uVar3 = RtlUnicodeStringCopy((ushort *)(param_1 + 0x38),(ushort *)&local_260);
          iVar2 = (int)uVar3;
          if (iVar2 < 0) goto LAB_140099159;
        }
        break;
      }
    }
    iVar2 = 0;
    if (bVar1) {
LAB_140099159:
      RtlFreeUnicodeString(&local_250);
    }
  }
LAB_14009916a:
  if (local_268 != 0) {
    ExFreePoolWithTag(local_268,0x49504550);
  }
  return iVar2;
}



===== __security_init_cookie @ 14009a008 =====

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



===== DriverEntry @ 14009a03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_24 = 0;
  wil_InitializeFeatureStaging();
  local_24 = 0;
  local_20 = PepEvtDeviceAdd;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0x20;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  PepDriverObject = param_1;
  InitializeTelemetryAssertsKMByDriverObject(param_1);
  return uVar1;
}



===== wil_InitializeFeatureStaging @ 14009a0d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &Feature_GatePerf__private_descriptor;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          _g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14009a1c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_GatePerf__private_descriptor;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


