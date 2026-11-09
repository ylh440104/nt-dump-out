
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



===== DriverEntry @ 1c0001020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_1b8 [80];
  undefined8 local_168;
  wchar_t *local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  longlong local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_e0;
  code *local_80;
  code *local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  uVar2 = 0;
  memset(&local_158,0,0x140);
  local_168 = 0x240022;
  local_160 = L"\\Device\\RamParser";
  wil_InitializeFeatureStaging();
  _RamParserDataLock = 0;
  _DAT_1c00072f8 = &RamParserDataList;
  RamParserDataList = &RamParserDataList;
  *(code **)(param_1 + 0x68) = RamDriverUnload;
  *(code **)(param_1 + 0x70) = RamParserCreate;
  *(code **)(param_1 + 0x80) = RamParserClose;
  *(code **)(param_1 + 0xe0) = RamParserDeviceControl;
  iVar1 = WdmlibIoCreateDeviceSecure(param_1,uVar2,&local_168);
  if ((-1 < iVar1) && (iVar1 = IoCreateSymbolicLink(&RamParserSymbolicLink,&local_168), -1 < iVar1))
  {
    RamParserCreatedLink = 1;
    local_138 = RamParserOpenDisk;
    local_158 = 0x140;
    local_120 = RamParserMountDisk;
    local_118 = _guard_check_icall;
    local_110 = RamParserQueryMountStatusDisk;
    local_130 = RamParserCloseDisk;
    local_128 = RamParserFastCloseDisk;
    local_108 = RamParserExecuteScsiRequestDisk;
    local_100 = RamParserQueryInformationDisk;
    local_e0 = RamParserSetBehavior;
    local_80 = RamParserCheckForParserOverride;
    local_38 = RamParserSupportsDataTransferDirectionValidation;
    local_154 = 6;
    local_150 = 0xe40f8a2b;
    uStack_14c = 0x4fa32e86;
    uStack_148 = 0x6c508af;
    uStack_144 = 0x997716f5;
    local_140 = param_1;
    iVar1 = VstorRegisterParser(&local_158);
    if (-1 < iVar1) {
      *(uint *)(RamParserDeviceObject + 0x30) = *(uint *)(RamParserDeviceObject + 0x30) & 0xffffff7f
      ;
      return 0;
    }
  }
  RamDriverUnload();
  return iVar1;
}



===== RamDriverUnload @ 1c0001210 =====

void RamDriverUnload(void)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  ExAcquirePushLockExclusiveEx(&RamParserDataLock,0);
  puVar5 = auStack_28;
  do {
    puVar4 = RamParserDataList;
    if ((undefined8 **)RamParserDataList == &RamParserDataList) {
LAB_1c000126a:
      *(undefined8 *)(puVar5 + -8) = 0x1c000127a;
      ExReleasePushLockExclusiveEx(&RamParserDataLock,0);
      if (RamParserCreatedLink != '\0') {
        *(undefined8 *)(puVar5 + -8) = 0x1c0001297;
        IoDeleteSymbolicLink(&RamParserSymbolicLink);
        RamParserCreatedLink = '\0';
      }
      if (RamParserDeviceObject != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x1c00012b5;
        IoDeleteDevice();
        RamParserDeviceObject = 0;
      }
      if (g_wil_details_featureChangeNotification != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x1c00012d4;
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x1c00012f3;
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      g_wil_details_isFeatureStagingInitialized = 0;
      return;
    }
    if (((undefined8 **)RamParserDataList[1] != &RamParserDataList) ||
       (puVar2 = (undefined8 *)*RamParserDataList, (undefined8 *)puVar2[1] != RamParserDataList)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStack_20;
      goto LAB_1c000126a;
    }
    RamParserDataList = puVar2;
    puVar2[1] = &RamParserDataList;
    plVar1 = puVar4 + 6;
    *plVar1 = *plVar1 + -1;
    RamParserFreeData((longlong)puVar4);
  } while( true );
}



===== RamParserCheckForParserOverride @ 1c0001320 =====

undefined8 RamParserCheckForParserOverride(ushort *param_1,longlong *param_2,undefined1 *param_3)

{
  short *psVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar3 = 0;
  uVar4 = 1;
  if (((*param_2 == 0x4cd9f0f5f916c826) && (param_2[1] == 0x539acf38d64f68be)) &&
     (9 < *param_1 >> 1)) {
    psVar1 = *(short **)(param_1 + 4) + ((ulonglong)(uint)(*param_1 >> 1) - 1);
    do {
      if (psVar1 == *(short **)(param_1 + 4)) goto LAB_1c00013ef;
      if (*psVar1 == 0x2e) {
        uVar3 = uVar3 + 1;
        if (uVar3 == 2) goto LAB_1c0001396;
      }
      psVar1 = psVar1 + -1;
      uVar4 = uVar4 + 1;
    } while (uVar3 < 2);
    if (uVar3 == 2) {
LAB_1c0001396:
      if (((((6 < uVar4) && ((psVar1[1] - 0x41U & 0xffdf) == 0)) &&
           (((psVar1[2] - 0x5aU & 0xffdf) == 0 &&
            (((psVar1[3] - 0x55U & 0xffdf) == 0 && ((psVar1[4] - 0x52U & 0xffdf) == 0)))))) &&
          ((psVar1[5] - 0x45U & 0xffdf) == 0)) && (uVar2 = 0, psVar1[6] == 0x2e)) {
        uVar2 = 1;
      }
    }
  }
LAB_1c00013ef:
  *param_3 = uVar2;
  return 0;
}



===== RamParserClose @ 1c0001410 =====

undefined8 RamParserClose(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  plVar2 = *(longlong **)(lVar1 + 0x18);
  if (*(longlong *)(lVar1 + 0x20) != 0) {
    RamParserUnblock((longlong)plVar2);
  }
  RamParserReleaseData(plVar2,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== RamParserCloseDisk @ 1c0001470 =====

void RamParserCloseDisk(undefined8 *param_1)

{
  char cVar1;
  
  if (param_1[0x18] != 0) {
    cVar1 = KeCancelTimer(param_1 + 8);
    if (cVar1 != '\0') {
      ExReleaseRundownProtection(param_1 + 0x19);
    }
    ExWaitForRundownProtectionRelease(param_1 + 0x19);
    IoFreeWorkItem(param_1[0x18]);
    param_1[0x18] = 0;
  }
  if (*(char *)((longlong)param_1 + 0xd3) != '\0') {
    RamParserTeardownRandomDelay((longlong)param_1);
  }
  if ((longlong *)*param_1 != (longlong *)0x0) {
    RamParserReleaseData((longlong *)*param_1,(longlong)param_1);
    *param_1 = 0;
  }
  if (param_1[0x2d] != 0) {
    IoFreeWorkItem();
    param_1[0x2d] = 0;
  }
  ExFreePoolWithTag(param_1,0x706d6172);
  return;
}



===== RamParserCompleteFlushOperation @ 1c0001548 =====

void RamParserCompleteFlushOperation(longlong *param_1,undefined1 param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  
  ExAcquirePushLockExclusiveEx(*param_1 + 0x50);
  lVar1 = *(longlong *)(*param_1 + 0x80);
  *(undefined8 *)(*param_1 + 0x80) = 0;
  *(undefined1 *)(*param_1 + 0x78) = 0;
  ExReleasePushLockExclusiveEx(*param_1 + 0x50);
  if (lVar1 != 0) {
    cVar3 = KeCancelTimer(param_1 + 8);
    if (cVar3 != '\0') {
      ExReleaseRundownProtection(param_1 + 0x19);
    }
    lVar2 = *(longlong *)(lVar1 + 8);
    *(undefined1 *)(lVar2 + 3) = 0;
    *(undefined1 *)(lVar2 + 2) = param_2;
    VstorCompleteScsiRequest(lVar1);
    RamParserProcessPendingIO(param_1,'\0');
  }
  return;
}



===== RamParserCreate @ 1c0001610 =====

int RamParserCreate(undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  byte bVar2;
  longlong lVar3;
  undefined8 uVar4;
  ushort uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 local_res10;
  undefined8 local_18;
  short *psStack_10;
  
  local_res10 = 0;
  local_18 = 0;
  psStack_10 = (short *)0x0;
  bVar2 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 0x13);
  if (bVar2 - 1 < 3) {
    lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
    puVar1 = (ushort *)(lVar3 + 0x58);
    uVar5 = *puVar1;
    uVar4 = *(undefined8 *)puVar1;
    psStack_10 = *(short **)(lVar3 + 0x60);
    local_18 = uVar4;
    if ((1 < uVar5) && (*psStack_10 == 0x5c)) {
      psStack_10 = psStack_10 + 1;
      uVar5 = uVar5 - 2;
      local_18._2_2_ = (short)((uint6)*(undefined6 *)puVar1 >> 0x10);
      local_18._4_4_ = (undefined4)((ulonglong)uVar4 >> 0x20);
      local_18 = CONCAT62(CONCAT42(local_18._4_4_,local_18._2_2_ + -2),uVar5);
    }
    if (uVar5 != 0) {
      uVar7 = RamParserGetData(&local_18,0,0,(uint)bVar2,'\0',&local_res10);
      iVar6 = (int)uVar7;
      if (-1 < iVar6) {
        iVar6 = 0;
        *(undefined8 *)(lVar3 + 0x18) = local_res10;
        *(undefined8 *)(lVar3 + 0x20) = 0;
      }
      goto LAB_1c00016c5;
    }
  }
  iVar6 = -0x3ffffff3;
LAB_1c00016c5:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== RamParserDeviceControl @ 1c0001700 =====

undefined4 RamParserDeviceControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(lVar3 + 0x30);
  iVar1 = *(int *)(lVar3 + 0x18);
  lVar5 = *(longlong *)(lVar4 + 0x18);
  if (iVar1 == 0x228004) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar5 + 0x50,0);
    *(undefined1 *)(lVar5 + 0x48) = 1;
    ExReleasePushLockExclusiveEx(lVar5 + 0x50,0);
    KeLeaveCriticalRegion();
    *(undefined8 *)(lVar4 + 0x20) = 1;
  }
  else {
    if (iVar1 == 0x228008) {
      uVar6 = 0;
      *(undefined8 *)(lVar4 + 0x20) = 0;
      RamParserUnblock(lVar5);
      goto LAB_1c000182f;
    }
    if (iVar1 != 0x22800c) {
      uVar6 = 0xc0000010;
      goto LAB_1c000182f;
    }
    if (*(uint *)(lVar3 + 0x10) < 4) {
      uVar6 = 0xc0000206;
      goto LAB_1c000182f;
    }
    uVar2 = **(uint **)(param_2 + 0x18);
    if (1000 < uVar2) {
      uVar6 = 0xc000000d;
      goto LAB_1c000182f;
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar5 + 0x50,0);
    *(uint *)(lVar5 + 0x4c) = uVar2;
    *(undefined1 *)(lVar5 + 0x49) = 1;
    for (puVar7 = *(undefined8 **)(lVar5 + 0x38); puVar7 != (undefined8 *)(lVar5 + 0x38);
        puVar7 = (undefined8 *)*puVar7) {
      RamParserStartTimerLocked(puVar7 + -1);
    }
    ExReleasePushLockExclusiveEx(lVar5 + 0x50,0);
    KeLeaveCriticalRegion();
  }
  uVar6 = 0;
LAB_1c000182f:
  *(undefined4 *)(param_2 + 0x30) = uVar6;
  IofCompleteRequest(param_2,0);
  return uVar6;
}



===== RamParserExecuteFlush @ 1c0001864 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 RamParserExecuteFlush(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined1 uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  int local_48 [2];
  undefined4 local_40;
  int local_3c;
  int local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  lVar3 = *param_1;
  local_48[0] = 0;
  if (*(int *)(lVar3 + 0x60) == 0) {
    uVar10 = 1;
    puVar12 = auStack_68;
    goto LAB_1c0001a71;
  }
  lVar1 = lVar3 + 0x50;
  ExAcquirePushLockExclusiveEx(lVar1,0);
  puVar11 = auStack_68;
  if (*(char *)(lVar3 + 0x78) == '\0') {
    lVar2 = lVar3 + 0x68;
    RtlClearAllBits(lVar2);
    puVar11 = auStack_68;
    puVar12 = auStack_68;
    uVar14 = 0;
    uVar10 = 1;
    if (*(int *)(lVar3 + 0x60) != 0) {
      do {
        if (*(int *)(*(longlong *)(lVar3 + 0x58) + uVar14 * 4) == 4) {
          RtlSetBit(lVar2,uVar14);
        }
        uVar13 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar13;
      } while (uVar13 < *(uint *)(lVar3 + 0x60));
    }
    cVar5 = RtlAreBitsClear(lVar2,0);
    if (cVar5 != '\0') {
      ExReleasePushLockExclusiveEx(lVar1,0);
      goto LAB_1c0001a71;
    }
    *(undefined1 *)(lVar3 + 0x78) = 1;
    *(undefined8 **)(lVar3 + 0x80) = param_2;
    ExReleasePushLockExclusiveEx();
    uVar13 = *(int *)(lVar3 + 0x60) - 1;
    if ((*(byte *)(*(longlong *)(lVar3 + 0x70) + ((longlong)(ulonglong)uVar13 >> 3)) >>
         ((ulonglong)uVar13 & 7) & 1) == 0) {
      RtlFindLastBackwardRunClear(lVar2,uVar13,local_48);
    }
    else {
      local_48[0] = *(int *)(lVar3 + 0x60);
    }
    local_40 = 1;
    local_3c = RtlFindSetBits(lVar2,1,0);
    local_38 = local_48[0] - local_3c;
    cVar5 = ExAcquireRundownProtection(param_1 + 0x19);
    if (cVar5 != '\0') {
      KeSetTimer(param_1 + 8,0xffffffffee1e5d00,param_1 + 0x10);
      iVar6 = VstorSendKsdNotification(param_1[5],&local_40);
      if (-1 < iVar6) goto LAB_1c0001902;
      cVar5 = KeCancelTimer(param_1 + 8);
      if (cVar5 != '\0') {
        ExReleaseRundownProtection(param_1 + 0x19);
      }
    }
    *(undefined8 *)(lVar3 + 0x80) = 0;
    uVar10 = 4;
    *(undefined1 *)(lVar3 + 0x78) = 0;
    puVar12 = auStack_68;
  }
  else {
    plVar8 = (longlong *)*param_2;
    plVar7 = param_1 + 6;
    plVar9 = (longlong *)param_1[7];
    if ((longlong *)*plVar9 != plVar7) {
      plVar8 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      plVar7 = (longlong *)(*pcVar4)();
      puVar11 = auStack_60;
    }
    plVar8[1] = (longlong)plVar9;
    *plVar8 = (longlong)plVar7;
    *plVar9 = (longlong)plVar8;
    plVar7[1] = (longlong)plVar8;
    *(undefined1 *)(param_2[1] + 2) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x1c00018fd;
    ExReleasePushLockExclusiveEx(lVar1,0);
LAB_1c0001902:
    uVar10 = 0;
    puVar12 = puVar11;
  }
LAB_1c0001a71:
  *(undefined8 *)(puVar12 + -8) = 0x1c0001a80;
  return uVar10;
}



===== RamParserExecuteInquiry @ 1c0001aa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RamParserExecuteInquiry(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  void *pvVar5;
  void *_Dst;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 local_c0;
  undefined1 local_a8;
  byte local_a7;
  undefined1 local_a6;
  byte local_a5;
  undefined1 local_a4;
  byte local_a1;
  undefined1 local_a0 [8];
  undefined1 local_98 [16];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  lVar2 = *(longlong *)(param_1 + 8);
  lVar3 = *(longlong *)(param_1 + 0x10);
  pvVar5 = (void *)0x0;
  if ((*(byte *)(lVar3 + 10) & 5) == 0) {
    local_c0 = 0x40000010;
    local_c8 = 0;
    pvVar5 = (void *)MmMapLockedPagesSpecifyCache(lVar3,0,1);
    _Dst = pvVar5;
  }
  else {
    _Dst = *(void **)(lVar3 + 0x18);
  }
  if (_Dst != (void *)0x0) {
    bVar1 = *(byte *)(lVar2 + 0x14);
    pvVar5 = (void *)0x0;
    uVar4 = (uint)bVar1;
    if (uVar4 <= *(uint *)(lVar2 + 0xc)) {
      if ((((*(byte *)(lVar2 + 0x11) & 2) != 0) || ((*(byte *)(lVar2 + 0x11) & 1) != 0)) ||
         (*(char *)(lVar2 + 0x12) != '\0')) {
        return 6;
      }
      if (4 < bVar1) {
        if (0x24 < bVar1) {
          uVar4 = 0x24;
        }
        memset(&local_a8,0,0x68);
        local_a7 = local_a7 & 0x7f;
        local_a1 = local_a1 | 2;
        local_a5 = local_a5 & 0xf2 | 2;
        local_a6 = 4;
        local_a4 = 0x1f;
        memcpy(local_a0,"msft    ",8);
        memcpy(local_98,"vmem disk       ",0x10);
        memcpy(local_88,"1.0 ",4);
        pvVar5 = memcpy(_Dst,&local_a8,(ulonglong)uVar4);
        *(uint *)(lVar2 + 0xc) = uVar4;
        return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
      }
    }
  }
  return CONCAT71((int7)((ulonglong)pvVar5 >> 8),4);
}



===== RamParserExecuteRequest @ 1c0001c14 =====

bool RamParserExecuteRequest(longlong *param_1,undefined8 *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  char cVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  ulonglong uVar9;
  bool bVar10;
  
  lVar2 = param_2[1];
  *(undefined1 *)(lVar2 + 3) = 0;
  if (*(int *)(lVar2 + 0xc) == 0) {
LAB_1c0001c58:
    cVar4 = *(char *)(lVar2 + 0x10);
    cVar5 = '\x12';
    if (cVar4 == '\x12') {
      uVar6 = RamParserExecuteInquiry((longlong)param_2);
      cVar5 = (char)uVar6;
    }
    else {
      if (cVar4 == '%') {
        if (7 < *(uint *)(param_2[1] + 0xc)) {
          lVar3 = param_2[2];
          if ((*(byte *)(lVar3 + 10) & 5) == 0) {
            puVar7 = (uint *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000010);
          }
          else {
            puVar7 = *(uint **)(lVar3 + 0x18);
          }
          if (puVar7 == (uint *)0x0) {
            cVar5 = '\x04';
          }
          else {
            puVar7[1] = 0x20000;
            uVar8 = (*(uint *)(*param_1 + 0x28) >> 9) - 1;
            *puVar7 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 |
                      uVar8 * 0x1000000;
            cVar5 = '\x01';
          }
        }
        goto LAB_1c0001db0;
      }
      if (cVar4 == '(') {
LAB_1c0001cf9:
        lVar3 = param_2[1];
        uVar8 = 0;
        uVar9 = 0;
        if (cVar4 == '(') {
          if ((*(byte *)(lVar3 + 0x11) & 1) != 0) goto LAB_1c0001c51;
          uVar1 = *(uint *)(lVar3 + 0x12);
          uVar8 = (uint)(ushort)(*(ushort *)(lVar3 + 0x17) >> 8 | *(ushort *)(lVar3 + 0x17) << 8);
          uVar9 = (ulonglong)
                  (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18);
        }
        else if (cVar4 == -0x78) {
          uVar8 = *(uint *)(lVar3 + 0x1a);
          uVar9 = *(ulonglong *)(lVar3 + 0x12);
          uVar8 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
          uVar9 = uVar9 >> 0x38 | (uVar9 & 0xff000000000000) >> 0x28 |
                  (uVar9 & 0xff0000000000) >> 0x18 | (uVar9 & 0xff00000000) >> 8 |
                  (uVar9 & 0xff000000) << 8 | (uVar9 & 0xff0000) << 0x18 | (uVar9 & 0xff00) << 0x28
                  | uVar9 << 0x38;
        }
        cVar4 = '\0';
      }
      else {
        if (cVar4 != '*') {
          if (cVar4 != '5') {
            if (cVar4 == -0x78) goto LAB_1c0001cf9;
            if (cVar4 == -0x76) goto LAB_1c0001ca4;
            if (cVar4 != -0x6f) goto LAB_1c0001c51;
          }
          cVar5 = RamParserExecuteFlush(param_1,param_2);
          goto LAB_1c0001daa;
        }
LAB_1c0001ca4:
        lVar3 = param_2[1];
        uVar8 = 0;
        uVar9 = 0;
        if (cVar4 == '*') {
          if ((*(byte *)(lVar3 + 0x11) & 1) != 0) goto LAB_1c0001c51;
          uVar1 = *(uint *)(lVar3 + 0x12);
          uVar8 = (uint)(ushort)(*(ushort *)(lVar3 + 0x17) >> 8 | *(ushort *)(lVar3 + 0x17) << 8);
          uVar9 = (ulonglong)
                  (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18);
        }
        else if (cVar4 == -0x76) {
          uVar8 = *(uint *)(lVar3 + 0x1a);
          uVar9 = *(ulonglong *)(lVar3 + 0x12);
          uVar8 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
          uVar9 = uVar9 >> 0x38 | (uVar9 & 0xff000000000000) >> 0x28 |
                  (uVar9 & 0xff0000000000) >> 0x18 | (uVar9 & 0xff00000000) >> 8 |
                  (uVar9 & 0xff000000) << 8 | (uVar9 & 0xff0000) << 0x18 | (uVar9 & 0xff00) << 0x28
                  | uVar9 << 0x38;
        }
        cVar4 = '\x01';
      }
      uVar6 = RamParserReadWrite(param_1,param_2,cVar4,uVar9,uVar8);
      cVar5 = (char)uVar6;
    }
LAB_1c0001daa:
    bVar10 = true;
    if (cVar5 == '\0') goto LAB_1c0001db5;
  }
  else {
    cVar4 = DvScsiValidateDataTransferDirection
                      (*(byte *)(lVar2 + 0x10),
                       (-(uint)(*(char *)(param_2[1] + 10) != '\0') & 0xffffffc0) + 0x80);
    if (cVar4 != '\0') goto LAB_1c0001c58;
LAB_1c0001c51:
    cVar5 = '\x06';
  }
LAB_1c0001db0:
  *(char *)(lVar2 + 2) = cVar5;
  bVar10 = cVar5 == '\0';
LAB_1c0001db5:
  return !bVar10;
}



===== RamParserExecuteScsiRequestDisk @ 1c0001dd0 =====

void RamParserExecuteScsiRequestDisk(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar7 = (longlong *)*param_2;
  plVar7[4] = (longlong)param_1;
  plVar7[5] = (longlong)param_2;
  ExAcquirePushLockExclusiveEx(*param_1 + 0x50,0);
  puVar9 = auStack_28;
  puVar8 = auStack_28;
  if (*(char *)((longlong)param_1 + 0xd3) == '\0') {
    if ((*(char *)(*param_1 + 0x48) == '\0') && (*(int *)(*param_1 + 0x4c) == 0))
    goto LAB_1c0001ea5;
    plVar4 = param_1 + 0x1b;
    plVar6 = (longlong *)param_1[0x1c];
    if ((longlong *)*plVar6 != plVar4) {
      plVar6 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar4 = (longlong *)(*pcVar2)();
      puVar8 = auStack_20;
    }
    plVar7[1] = (longlong)plVar6;
    *plVar7 = (longlong)plVar4;
    *plVar6 = (longlong)plVar7;
    plVar4[1] = (longlong)plVar7;
    *(undefined8 *)(puVar8 + -8) = 0x1c0001ea3;
    RamParserStartTimerLocked(param_1);
  }
  else {
    uVar3 = RtlRandomEx(param_1 + 0xc9);
    puVar9 = auStack_28;
    if ((uVar3 & 0xf) == 0) goto LAB_1c0001ea5;
    uVar3 = uVar3 >> 4 & 0xfffffff;
    uVar5 = (ulonglong)((uint)uVar3 & 3);
    LOCK();
    *(int *)(param_1 + uVar5 * 6 + 0x31) = (int)param_1[uVar5 * 6 + 0x31] + 1;
    UNLOCK();
    ExpInterlockedPushEntrySList
              (param_1 + (uVar5 * 0x10 + (ulonglong)((uint)(uVar3 >> 2) & 0xf) + 0x24) * 2,
               plVar7 + 2);
    puVar8 = auStack_28;
  }
  plVar7 = (longlong *)0x0;
  puVar9 = puVar8;
LAB_1c0001ea5:
  lVar1 = *param_1;
  *(undefined8 *)(puVar9 + -8) = 0x1c0001eb5;
  ExReleasePushLockExclusiveEx(lVar1 + 0x50,0);
  if (plVar7 != (longlong *)0x0) {
    *(undefined8 *)(puVar9 + -8) = 0x1c0001ec7;
    RamParserRunRequest((longlong)plVar7);
  }
  return;
}



===== RamParserFastCloseDisk @ 1c0001ee0 =====

void RamParserFastCloseDisk(longlong *param_1)

{
  char cVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*param_1 + 0x50,0);
  *(undefined1 *)((longlong)param_1 + 0xd2) = 1;
  if ((char)param_1[0x2e] != '\0') {
    cVar1 = KeCancelTimer(param_1 + 0x25);
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x2e) = 0;
    }
  }
  RamParserStartTimerLocked(param_1);
  ExReleasePushLockExclusiveEx(*param_1 + 0x50,0);
  KeLeaveCriticalRegion();
  if (*(char *)((longlong)param_1 + 0xd3) != '\0') {
    RamParserStopThreadsRandomDelay((longlong)param_1);
  }
  return;
}



===== RamParserFlushTimerDpc @ 1c0001f80 =====

void RamParserFlushTimerDpc(undefined8 param_1,longlong param_2)

{
  IoQueueWorkItem(*(undefined8 *)(param_2 + 0xc0),RamParserFlushTimerWorkerRoutine,1,param_2);
  return;
}



===== RamParserFlushTimerWorkerRoutine @ 1c0001fc0 =====

void RamParserFlushTimerWorkerRoutine(undefined8 param_1,longlong *param_2)

{
  RamParserCompleteFlushOperation(param_2,4);
  ExReleaseRundownProtection(param_2 + 0x19);
  return;
}



===== RamParserFreeData @ 1c0001ff4 =====

void RamParserFreeData(longlong param_1)

{
  RtlFreeUnicodeString(param_1 + 0x10);
  if (*(longlong *)(param_1 + 0x20) != 0) {
    if (*(longlong *)(param_1 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0x706d6172);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x706d6172);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  ExFreePoolWithTag(param_1,0x706d6172);
  return;
}



===== RamParserGetData @ 1c000206c =====

ulonglong RamParserGetData(undefined8 param_1,uint param_2,longlong param_3,int param_4,char param_5
                          ,undefined8 *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong *plVar4;
  void *_Dst;
  ulonglong uVar5;
  longlong *local_28 [2];
  
  local_28[0] = (longlong *)0x0;
  uVar2 = RamParserGetOrInsertData(param_1,param_3,param_4,(longlong *)local_28);
  uVar5 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if (((int)uVar2 == -0x3ffffddb) && (param_4 != 1)) {
      plVar3 = (longlong *)ExAllocatePool2(0x40,0x88,0x706d6172);
      local_28[0] = plVar3;
      if (plVar3 == (longlong *)0x0) goto LAB_1c00020e9;
      plVar3[1] = (longlong)plVar3;
      *plVar3 = (longlong)plVar3;
      plVar4 = plVar3 + 7;
      plVar3[8] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      plVar3[10] = 0;
      plVar3[6] = 1;
      uVar1 = RtlDuplicateUnicodeString(0,param_1,plVar3 + 2);
      uVar5 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) goto LAB_1c00021de;
      uVar2 = RamParserGetOrInsertData(param_1,param_3,param_4,(longlong *)local_28);
      uVar5 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) goto LAB_1c0002154;
    }
    plVar3 = local_28[0];
LAB_1c00021de:
    if (plVar3 != (longlong *)0x0) {
      RamParserReleaseData(plVar3,param_3);
    }
  }
  else {
LAB_1c0002154:
    plVar3 = local_28[0];
    if ((param_3 != 0) && (*(uint *)(local_28[0] + 5) != param_2)) {
      _Dst = (void *)ExAllocatePool2(0x100,param_2,0x706d6172);
      if (_Dst == (void *)0x0) {
LAB_1c00020e9:
        uVar5 = 0xc000009a;
        goto LAB_1c00021de;
      }
      uVar1 = *(uint *)(plVar3 + 5);
      if (param_2 < *(uint *)(plVar3 + 5)) {
        uVar1 = param_2;
      }
      memcpy(_Dst,(void *)plVar3[4],(ulonglong)uVar1);
      if (plVar3[4] != 0) {
        ExFreePoolWithTag(plVar3[4],0x706d6172);
      }
      plVar3[4] = (longlong)_Dst;
      *(uint *)(plVar3 + 5) = param_2;
      if (param_5 != '\0') {
        uVar2 = RamParserInitializeDataBlockState((longlong)plVar3);
        uVar5 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) goto LAB_1c00021de;
      }
    }
    uVar5 = 0;
    *param_6 = plVar3;
  }
  return uVar5;
}



===== RamParserGetOrInsertData @ 1c000221c =====

undefined8
RamParserGetOrInsertData(undefined8 param_1,longlong param_2,int param_3,longlong *param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  char cVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  lVar9 = *param_4;
  *param_4 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&RamParserDataLock,0);
  puVar7 = RamParserDataList;
  do {
    if ((undefined8 **)puVar7 == &RamParserDataList) {
LAB_1c000229f:
      if (lVar9 == 0) {
        uVar8 = 0xc0000225;
      }
      else {
        if (param_2 != 0) {
          plVar4 = *(longlong **)(lVar9 + 0x40);
          plVar2 = (longlong *)(param_2 + 8);
          if (*plVar4 != lVar9 + 0x38) {
LAB_1c0002368:
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            pcVar5 = (code *)swi(3);
            uVar8 = (*pcVar5)();
            return uVar8;
          }
          *plVar2 = lVar9 + 0x38;
          *(longlong **)(param_2 + 0x10) = plVar4;
          *plVar4 = (longlong)plVar2;
          *(longlong **)(lVar9 + 0x40) = plVar2;
        }
        *param_4 = lVar9;
        lVar9 = 0;
LAB_1c0002316:
        uVar8 = 0;
      }
LAB_1c0002318:
      ExReleasePushLockExclusiveEx(&RamParserDataLock,0);
      KeLeaveCriticalRegion();
      if (lVar9 != 0) {
        RamParserFreeData(lVar9);
      }
      return uVar8;
    }
    cVar6 = RtlEqualUnicodeString(puVar7 + 2,param_1,1);
    if (cVar6 != '\0') {
      if (puVar7 != (undefined8 *)0x0) {
        if (param_3 == 2) {
          uVar8 = 0xc0000708;
          goto LAB_1c0002318;
        }
        if (param_2 != 0) {
          puVar3 = (undefined8 *)puVar7[8];
          puVar1 = (undefined8 *)(param_2 + 8);
          if ((undefined8 *)*puVar3 != puVar7 + 7) goto LAB_1c0002368;
          *puVar1 = puVar7 + 7;
          *(undefined8 **)(param_2 + 0x10) = puVar3;
          *puVar3 = puVar1;
          puVar7[8] = puVar1;
        }
        puVar7[6] = puVar7[6] + 1;
        *param_4 = (longlong)puVar7;
        goto LAB_1c0002316;
      }
      goto LAB_1c000229f;
    }
    puVar7 = (undefined8 *)*puVar7;
  } while( true );
}



===== RamParserInitializeDataBlockState @ 1c0002378 =====

undefined8 RamParserInitializeDataBlockState(longlong param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  uVar3 = *(uint *)(param_1 + 0x28) + 0xfffff;
  if (uVar3 < *(uint *)(param_1 + 0x28)) {
    uVar5 = 0xc0000095;
  }
  else {
    uVar3 = uVar3 >> 0x14;
    uVar4 = (ulonglong)uVar3;
    puVar1 = (undefined4 *)
             ExAllocatePool2(0x100,((ulonglong)((uVar3 + 7 >> 3) + 3) & 0xfffffffc) + uVar4 * 4,
                             0x706d6172);
    uVar5 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      if (uVar3 != 0) {
        puVar6 = puVar1;
        for (uVar2 = uVar4; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar6 = 1;
          puVar6 = puVar6 + 1;
        }
      }
      RtlInitializeBitMap(param_1 + 0x68,puVar1 + uVar4,uVar3);
      *(undefined4 **)(param_1 + 0x58) = puVar1;
      *(uint *)(param_1 + 0x60) = uVar3;
    }
  }
  return uVar5;
}



===== RamParserInitializeRandomDelay @ 1c0002444 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RamParserInitializeRandomDelay(longlong param_1)

{
  int iVar1;
  PSLIST_HEADER ListHead;
  int *piVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  ListHead = (PSLIST_HEADER)(param_1 + 0x240);
  lVar3 = 4;
  do {
    lVar5 = 0x10;
    do {
      InitializeSListHead(ListHead);
      ListHead = ListHead + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  KeInitializeEvent(param_1 + 0x688,0,0);
  KeInitializeEvent(param_1 + 0x658,0,0);
  KeInitializeEvent(param_1 + 0x670,0,0);
  *(int *)(param_1 + 0x648) = (int)_DAT_fffff78000000008;
  lVar3 = ExAllocateTimer(RamParserRandomDelayTickCallback,param_1 + 0x658,0x80000000);
  *(longlong *)(param_1 + 0x640) = lVar3;
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
LAB_1c0002513:
    RamParserTeardownRandomDelay(param_1);
  }
  else {
    uVar6 = 0;
    piVar2 = (int *)(param_1 + 0x18c);
    do {
      *(longlong *)(piVar2 + -5) = param_1;
      lVar3 = uVar6 * 0x30;
      *piVar2 = (int)uVar6;
      piVar2[2] = -0x3fcaffe5;
      *(undefined4 *)(lVar3 + 0x188 + param_1) = 0;
      iVar1 = PsCreateSystemThread
                        (lVar3 + 0x180 + param_1,0x100000,0,0,0,RamParserRandomDelayThread,
                         param_1 + 0x178 + lVar3);
      if (iVar1 < 0) goto LAB_1c0002513;
      *(undefined1 *)(piVar2 + 1) = 1;
      uVar4 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar4;
      *(int *)(param_1 + 0x64c) = *(int *)(param_1 + 0x64c) + 1;
      piVar2 = piVar2 + 0xc;
    } while (uVar4 < 4);
    RamParserRandomDelaySetTimer(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



===== RamParserLoadDataBlocks @ 1c00025d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RamParserLoadDataBlocks(longlong *param_1,undefined8 *param_2,uint param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [40];
  ulonglong local_48;
  
  puVar16 = auStack_78;
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  bVar6 = false;
  lVar1 = *param_1;
  bVar4 = false;
  bVar5 = false;
  lVar2 = *(longlong *)(lVar1 + 0x58);
  if (*(int *)(lVar1 + 0x60) == 0) {
    iVar7 = 0;
    goto LAB_1c000279f;
  }
  uVar17 = param_4 * 0x200 + param_3 * 0x200 >> 0x14;
  ExAcquirePushLockExclusiveEx(lVar1 + 0x50,0);
  puVar15 = auStack_78;
  puVar16 = auStack_78;
  uVar14 = (param_3 & 0x7fffff) >> 0xb;
  if (uVar17 < uVar14) {
LAB_1c00026e3:
    iVar7 = 0;
  }
  else {
    do {
      iVar7 = *(int *)(lVar2 + (ulonglong)uVar14 * 4);
      if (iVar7 == 1) {
        uVar9 = 0;
        if (*(int *)(*param_1 + 0x60) != 0) {
          do {
            if (*(int *)(lVar2 + uVar9 * 4) == 1) {
              *(undefined4 *)(lVar2 + uVar9 * 4) = 2;
            }
            uVar10 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar10;
          } while (uVar10 < *(uint *)(*param_1 + 0x60));
        }
        bVar4 = true;
        bVar5 = true;
      }
      else if (iVar7 - 2U < 2) {
        bVar5 = true;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 <= uVar17);
    if ((bVar4) && (*(char *)(*param_1 + 100) == '\0')) {
      *(undefined1 *)(*param_1 + 100) = 1;
      bVar6 = true;
    }
    if (!bVar5) goto LAB_1c00026e3;
    plVar12 = (longlong *)*param_2;
    plVar8 = param_1 + 6;
    plVar13 = (longlong *)param_1[7];
    if ((longlong *)*plVar13 != plVar8) {
      plVar12 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      plVar8 = (longlong *)(*pcVar3)();
      puVar15 = auStack_70;
    }
    *plVar12 = (longlong)plVar8;
    iVar7 = 0x103;
    plVar12[1] = (longlong)plVar13;
    *plVar13 = (longlong)plVar12;
    plVar8[1] = (longlong)plVar12;
    *(undefined1 *)(param_2[1] + 2) = 0;
    puVar16 = puVar15;
  }
  lVar1 = *param_1;
  *(undefined8 *)(puVar16 + -8) = 0x1c00026f5;
  ExReleasePushLockExclusiveEx(lVar1 + 0x50,0);
  if (bVar6) {
    lVar1 = *param_1;
    uVar14 = *(uint *)(lVar1 + 0x60);
    *(undefined8 *)(puVar16 + -8) = 0x1c0002718;
    ExAcquirePushLockExclusiveEx(lVar1 + 0x50,0);
    uVar17 = *(uint *)(lVar1 + 0x60);
    uVar9 = 0;
    uVar10 = uVar14;
    if (uVar17 != 0) {
      do {
        uVar11 = (uint)uVar9;
        if (*(int *)(*(longlong *)(lVar1 + 0x58) + uVar9 * 4) == 2) {
          *(undefined4 *)(*(longlong *)(lVar1 + 0x58) + uVar9 * 4) = 3;
          uVar17 = *(uint *)(lVar1 + 0x60);
          if (uVar14 != uVar17) {
            uVar9 = (ulonglong)uVar14;
          }
          uVar14 = (uint)uVar9;
          uVar10 = uVar11;
        }
        uVar11 = uVar11 + 1;
        uVar9 = (ulonglong)uVar11;
      } while (uVar11 < uVar17);
    }
    *(undefined8 *)(puVar16 + -8) = 0x1c000275a;
    ExReleasePushLockExclusiveEx(lVar1 + 0x50,0);
    lVar1 = param_1[5];
    *(undefined4 *)(puVar16 + 0x20) = 2;
    *(uint *)(puVar16 + 0x24) = uVar14;
    *(uint *)(puVar16 + 0x28) = (uVar10 - uVar14) + 1;
    *(undefined8 *)(puVar16 + -8) = 0x1c0002783;
    iVar7 = VstorSendKsdNotification(lVar1,puVar16 + 0x20);
    if (iVar7 < 0) {
      *(undefined8 *)(puVar16 + -8) = 0x1c0002798;
      RamParserProcessPendingIO(param_1,'\x01');
    }
    else {
      iVar7 = 0x103;
    }
  }
LAB_1c000279f:
  *(undefined8 *)(puVar16 + -8) = 0x1c00027ae;
  return iVar7;
}



===== RamParserMarkDataBlocks @ 1c00027d0 =====

void RamParserMarkDataBlocks(longlong *param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  
  ExAcquirePushLockExclusiveEx(*param_1 + 0x50,0);
  for (uVar1 = (param_2 & 0x7fffff) >> 0xb; uVar1 <= param_3 * 0x200 + param_2 * 0x200 >> 0x14;
      uVar1 = uVar1 + 1) {
    *(undefined4 *)(*(longlong *)(*param_1 + 0x58) + (ulonglong)uVar1 * 4) = param_4;
  }
  ExReleasePushLockExclusiveEx(*param_1 + 0x50,0);
  return;
}



===== RamParserMarkDataCommitState @ 1c0002858 =====

undefined8 RamParserMarkDataCommitState(longlong *param_1,ulonglong *param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  lVar1 = *param_1 + 0x68;
  if (0xf < param_3) {
    uVar2 = *param_2;
    uVar5 = (ulonglong)*(uint *)(*param_1 + 0x28);
    if ((uVar2 <= uVar5) || ((ulonglong)(uint)param_2[1] <= uVar5 - uVar2)) {
      if (*(char *)((longlong)param_2 + 0xc) == '\0') {
        uVar6 = 4;
      }
      else {
        uVar5 = param_2[1];
        uVar3 = *param_2;
        RamParserMarkDataBlocks(param_1,(uint)(uVar2 >> 9),(uint)uVar5 >> 9,5);
        RtlClearBits(lVar1,(uint)uVar3 >> 0x14,(uint)uVar5 + 0xfffff >> 0x14);
        cVar4 = RtlAreBitsClear(lVar1,0,*(undefined4 *)(*param_1 + 0x60));
        if (cVar4 == '\0') {
          return 0;
        }
        uVar6 = 1;
      }
      RamParserCompleteFlushOperation(param_1,uVar6);
      return 0;
    }
  }
  return 0xc000000d;
}



===== RamParserMountDisk @ 1c0002940 =====

void RamParserMountDisk(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  *param_4 = 0;
  *(undefined4 *)param_4 = 0x30;
  if ((*(char *)(param_1 + 0xd0) != '\0') &&
     (*(undefined1 *)((longlong)param_4 + 5) = 1, *(char *)(param_1 + 0xd1) != '\0')) {
    *(undefined1 *)((longlong)param_4 + 6) = 1;
  }
  return;
}



===== RamParserOpenDisk @ 1c0002970 =====

ulonglong RamParserOpenDisk(ushort *param_1,uint param_2,undefined4 *param_3,longlong param_4,
                           undefined8 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int local_res10 [2];
  undefined4 local_48 [2];
  longlong local_40;
  short local_38 [8];
  
  local_40 = 0;
  local_48[0] = 0;
  local_res10[0] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if ((param_2 & 0xfffffdff) != 0) {
    return 0xc000000d;
  }
  plVar5 = (longlong *)ExAllocatePool2(0x40,0x6b0,0x706d6172);
  if (plVar5 == (longlong *)0x0) {
    return 0xc000009a;
  }
  plVar6 = plVar5 + 6;
  plVar5[7] = (longlong)plVar6;
  *plVar6 = (longlong)plVar6;
  plVar6 = plVar5 + 0x1b;
  plVar5[0x1c] = (longlong)plVar6;
  *plVar6 = (longlong)plVar6;
  KeInitializeTimer(plVar5 + 0x25);
  KeInitializeDpc(plVar5 + 0x1d,RamParserTimerDpc,plVar5);
  KeInitializeTimer(plVar5 + 8);
  KeInitializeDpc(plVar5 + 0x10,RamParserFlushTimerDpc,plVar5);
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *(undefined4 *)(plVar5 + 3) = *param_3;
    *(undefined4 *)((longlong)plVar5 + 0x1c) = uVar1;
    *(undefined4 *)(plVar5 + 4) = uVar2;
    *(undefined4 *)((longlong)plVar5 + 0x24) = uVar3;
  }
  lVar7 = IoAllocateWorkItem(RamParserDeviceObject);
  plVar5[0x2d] = lVar7;
  if (lVar7 != 0) {
    lVar7 = IoAllocateWorkItem(RamParserDeviceObject);
    plVar5[0x18] = lVar7;
    if (lVar7 != 0) {
      ExInitializeRundownProtection(plVar5 + 0x19);
      uVar8 = RamParserParseFileName
                        (param_1,local_38,local_res10,local_48,(undefined1 *)(plVar5 + 0x1a),
                         (undefined1 *)((longlong)plVar5 + 0xd1),(char *)((longlong)plVar5 + 0xd3));
      uVar9 = uVar8 & 0xffffffff;
      if (-1 < (int)uVar8) {
        if (*(char *)((longlong)plVar5 + 0xd3) != '\0') {
          uVar4 = RamParserInitializeRandomDelay((longlong)plVar5);
          uVar9 = (ulonglong)uVar4;
          if ((int)uVar4 < 0) goto LAB_1c0002a96;
        }
        uVar8 = RamParserGetData(local_38,local_res10[0] << 0x14,(longlong)plVar5,3,
                                 (byte)(param_2 >> 9) & 1,&local_40);
        uVar9 = uVar8 & 0xffffffff;
        if (-1 < (int)uVar8) {
          if (*(char *)(local_40 + 0x49) == '\0') {
            *(undefined4 *)(local_40 + 0x4c) = local_48[0];
          }
          *plVar5 = local_40;
          plVar5[5] = param_4;
          *param_5 = plVar5;
          return 0;
        }
      }
      goto LAB_1c0002a96;
    }
  }
  uVar9 = 0xc000009a;
LAB_1c0002a96:
  RamParserCloseDisk(plVar5);
  return uVar9;
}



===== RamParserParseFileName @ 1c0002ba4 =====

undefined8
RamParserParseFileName
          (ushort *param_1,short *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined1 *param_5,undefined1 *param_6,undefined1 *param_7)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  bool local_res8;
  ulonglong local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  longlong lStack_c0;
  undefined8 local_b8;
  longlong lStack_b0;
  ulonglong local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  
  local_98 = L"size";
  uVar14 = (uint)(*param_1 >> 1);
  local_88 = L"delay";
  local_d8 = 0;
  local_78 = L"fastpause";
  uVar9 = 0x2a;
  local_a0 = 0xa0008;
  local_68 = L"fastclose";
  local_90 = 0xc000a;
  local_80 = 0x140012;
  uVar6 = 0;
  local_58 = L"randomdelay";
  local_70 = 0x140012;
  local_c8 = 0;
  local_60 = 0x180016;
  bVar15 = false;
  local_b8 = 0;
  local_d0 = 0x2a;
  bVar16 = false;
  local_a8 = 0;
  uVar7 = 0;
  local_res8 = false;
  if (uVar14 != 0) {
    do {
      if (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar7 * 2) == 0x2c) break;
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar14);
  }
  if (uVar7 == 0) {
    return 0xc000000d;
  }
  uVar12 = uVar7 + 1;
  if (uVar14 <= uVar7) {
    uVar12 = uVar7;
  }
  uVar8 = (ulonglong)uVar12;
  bVar5 = false;
  if (uVar12 < uVar14) {
    do {
      uVar12 = (uint)(*param_1 >> 1);
      uVar11 = uVar8;
      if ((uint)uVar8 < uVar12) {
        uVar10 = uVar8;
LAB_1c0002cae:
        sVar1 = *(short *)(*(longlong *)(param_1 + 4) + uVar10 * 2);
        uVar11 = uVar10;
        if (sVar1 != 0x2c) {
          uVar3 = (int)uVar10 + 1;
          if (sVar1 != 0x3d) goto code_r0x0001c0002cc9;
          uVar13 = (ulonglong)uVar3;
          while ((uVar11 = (ulonglong)uVar3, uVar3 < uVar12 &&
                 (sVar1 = *(short *)(*(longlong *)(param_1 + 4) + uVar11 * 2), sVar1 != 0x2c))) {
            if (sVar1 == 0x3d) {
              return 0xc000000d;
            }
            uVar3 = uVar3 + 1;
          }
          goto LAB_1c0002cd7;
        }
      }
LAB_1c0002cd1:
      uVar10 = uVar11;
      uVar13 = uVar11;
LAB_1c0002cd7:
      if ((uint)uVar10 == (uint)uVar8) {
        return 0xc000000d;
      }
      sVar1 = ((short)uVar10 - (short)uVar8) * 2;
      local_c8._0_4_ = CONCAT22(sVar1,sVar1);
      lStack_c0 = *(longlong *)(param_1 + 4) + uVar8 * 2;
      sVar1 = ((short)uVar11 - (short)uVar13) * 2;
      lStack_b0 = *(longlong *)(param_1 + 4) + uVar13 * 2;
      local_b8._0_4_ = CONCAT22(sVar1,sVar1);
      uVar8 = (ulonglong)((uint)uVar11 + 1);
      if (uVar12 <= (uint)uVar11) {
        uVar8 = uVar11;
      }
      cVar2 = RtlEqualUnicodeString(&local_c8,&local_a0,CONCAT71((int7)(uVar11 >> 8),1));
      if (cVar2 == '\0') {
        cVar2 = RtlEqualUnicodeString(&local_c8,&local_90,1);
        if (cVar2 != '\0') {
          if (sVar1 == 0) {
            return 0xc000000d;
          }
          uVar4 = RamParserParseInteger((ushort *)&local_b8,&local_d8);
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          local_a8 = local_d8;
          if (1000 < local_d8) {
            return 0xc000000d;
          }
          goto LAB_1c0002f1d;
        }
        cVar2 = RtlEqualUnicodeString(&local_c8,&local_80,1);
        if (cVar2 != '\0') {
          if (sVar1 == 0) {
            bVar15 = true;
          }
          else {
            uVar4 = RamParserParseInteger((ushort *)&local_b8,&local_d8);
            if ((int)uVar4 < 0) {
              return uVar4;
            }
            bVar15 = local_d8 == 1;
joined_r0x0001c0002f09:
            if (1 < local_d8) {
              return 0xc000000d;
            }
          }
          goto LAB_1c0002f1d;
        }
        cVar2 = RtlEqualUnicodeString(&local_c8,&local_70,1);
        if (cVar2 == '\0') {
          cVar2 = RtlEqualUnicodeString(&local_c8,&local_60,1);
          if (cVar2 == '\0') {
            return 0xc000000d;
          }
          if (sVar1 != 0) {
            uVar4 = RamParserParseInteger((ushort *)&local_b8,&local_d8);
            if ((int)uVar4 < 0) {
              return uVar4;
            }
            bVar16 = local_d8 == 1;
            goto joined_r0x0001c0002f09;
          }
          bVar16 = true;
          goto LAB_1c0002f1d;
        }
        if (sVar1 == 0) {
          local_res8 = true;
        }
        else {
          uVar4 = RamParserParseInteger((ushort *)&local_b8,&local_d8);
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          local_res8 = local_d8 == 1;
          if (1 < local_d8) {
            return 0xc000000d;
          }
        }
        uVar9 = (undefined4)local_d0;
      }
      else {
        if (sVar1 == 0) {
          return 0xc000000d;
        }
        uVar4 = RamParserParseInteger((ushort *)&local_b8,&local_d8);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        local_d0 = local_d8;
        if (0x7ff < local_d8 - 1) {
          return 0xc000000d;
        }
LAB_1c0002f1d:
        uVar9 = (undefined4)local_d0;
      }
    } while ((uint)uVar8 < uVar14);
    uVar6 = (undefined4)local_a8;
    bVar5 = local_res8;
  }
  sVar1 = (short)uVar7 * 2;
  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + 4);
  *param_2 = sVar1;
  param_2[1] = sVar1;
  *param_3 = uVar9;
  *param_4 = uVar6;
  *param_5 = bVar15;
  *param_6 = bVar5;
  *param_7 = bVar16;
  return 0;
code_r0x0001c0002cc9:
  uVar11 = (ulonglong)uVar3;
  uVar10 = uVar11;
  if (uVar12 <= uVar3) goto LAB_1c0002cd1;
  goto LAB_1c0002cae;
}



===== RamParserParseInteger @ 1c0002f74 =====

undefined8 RamParserParseInteger(ushort *param_1,ulonglong *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  if (*param_1 >> 1 != 0) {
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 4) + uVar4 * 2);
      if ((9 < (ushort)(uVar1 - 0x30)) || (0x19999999999999c9 - (ulonglong)uVar1 < uVar2)) {
        return 0xc000000d;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      uVar2 = (ulonglong)uVar1 + (uVar2 * 5 + -0x18) * 2;
    } while (uVar3 < *param_1 >> 1);
  }
  *param_2 = uVar2;
  return 0;
}



===== RamParserProcessPendingIO @ 1c0002fd8 =====

void RamParserProcessPendingIO(longlong *param_1,char param_2)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  longlong *****ppppplVar4;
  longlong *****ppppplVar5;
  code *pcVar6;
  longlong *****local_18;
  longlong *****local_10;
  
  local_10 = (longlong *****)&local_18;
  local_18 = (longlong *****)&local_18;
  ExAcquirePushLockExclusiveEx(*param_1 + 0x50,0);
  pppplVar1 = (longlong ****)(param_1 + 6);
  pppplVar2 = (longlong ****)*pppplVar1;
  if (pppplVar2 == pppplVar1) {
LAB_1c0003099:
    ExReleasePushLockExclusiveEx(*param_1 + 0x50,0);
    while (ppppplVar4 = local_18, (longlong ******)local_18 != &local_18) {
      if (((longlong ******)local_18[1] != &local_18) ||
         (ppppplVar5 = (longlong *****)*local_18, (longlong *****)ppppplVar5[1] != local_18))
      goto LAB_1c0003107;
      ppppplVar5[1] = (longlong ****)&local_18;
      if (param_2 == '\0') {
        local_18 = ppppplVar5;
        RamParserRunRequest((longlong)ppppplVar4);
      }
      else {
        *(undefined1 *)((longlong)local_18[5][1] + 2) = 4;
        ppppplVar4 = local_18 + 5;
        local_18 = ppppplVar5;
        VstorCompleteScsiRequest(*ppppplVar4);
      }
    }
  }
  else {
    ppplVar3 = (longlong ***)param_1[7];
    if (((longlong ****)pppplVar2[1] == pppplVar1) && ((longlong ****)*ppplVar3 == pppplVar1)) {
      *ppplVar3 = (longlong **)pppplVar2;
      pppplVar2[1] = ppplVar3;
      if (((longlong ******)local_18[1] == &local_18) &&
         ((((longlong ******)*local_10 == &local_18 && ((longlong ****)(*pppplVar2)[1] == pppplVar2)
           ) && ((longlong ****)*ppplVar3 == pppplVar2)))) {
        *local_10 = pppplVar2;
        ppppplVar4 = (longlong *****)pppplVar2[1];
        *pppplVar2[1] = (longlong **)&local_18;
        pppplVar2[1] = (longlong ***)local_10;
        param_1[7] = (longlong)pppplVar1;
        *pppplVar1 = (longlong ***)pppplVar1;
        local_10 = ppppplVar4;
        goto LAB_1c0003099;
      }
    }
LAB_1c0003107:
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
  }
  return;
}



===== RamParserQueryInformationDisk @ 1c0003130 =====

undefined8
RamParserQueryInformationDisk
          (longlong *param_1,int param_2,longlong param_3,uint param_4,ulonglong *param_5,
          uint *param_6)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (param_2 == 1) {
    if (0xf < *param_6) {
      *param_5 = 0;
      *(undefined4 *)(param_5 + 1) = 0x200;
      *(undefined4 *)((longlong)param_5 + 0xc) = 0x200;
      *param_5 = (ulonglong)*(uint *)(*param_1 + 0x28);
      *param_6 = 0x10;
      return 0;
    }
LAB_1c0003266:
    uVar3 = 0xc0000023;
  }
  else {
    if (param_2 == 0x101) {
      if (*param_6 < 0x38) goto LAB_1c0003266;
      *param_5 = 0;
      param_5[1] = 0;
      param_5[2] = 0;
      param_5[3] = 0;
      param_5[4] = 0;
      param_5[5] = 0;
      param_5[6] = 0;
      *(undefined4 *)(param_5 + 1) = 0x1000;
      param_5[4] = (ulonglong)*(uint *)(*param_1 + 0x28);
      *(undefined1 *)((longlong)param_5 + 0x1e) = 1;
      *(undefined4 *)((longlong)param_5 + 4) = 2;
      *(undefined4 *)param_5 = 99;
      *param_6 = 0x38;
    }
    else if (param_2 == 0x102) {
      if (*param_6 < 4) goto LAB_1c0003266;
      *(undefined4 *)param_5 = 1;
      *param_6 = 4;
    }
    else if (param_2 == 0x104) {
      if (*param_6 == 0) goto LAB_1c0003266;
      *(undefined1 *)param_5 = 1;
      *param_6 = 1;
    }
    else {
      if (param_2 != 0x284) {
        return 0xc0000010;
      }
      if ((param_4 < 0x20) || (uVar1 = *(uint *)(param_3 + 0x10), *param_6 < uVar1)) {
        return 0xc000000d;
      }
      uVar2 = *(ulonglong *)(param_3 + 8) >> 9;
      uVar4 = (ulonglong)(*(uint *)(*param_1 + 0x28) >> 9);
      if (uVar4 < uVar2) {
        return 0xc000000d;
      }
      if (uVar4 - uVar2 < (ulonglong)(uVar1 >> 9)) {
        return 0xc000000d;
      }
      memcpy(param_5,(void *)(*(longlong *)(*param_1 + 0x20) + *(ulonglong *)(param_3 + 8)),
             (ulonglong)uVar1);
      *param_6 = (uVar1 >> 9) << 9;
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== RamParserQueryMountStatusDisk @ 1c00032b0 =====

undefined8 RamParserQueryMountStatusDisk(void)

{
  return 0;
}



===== RamParserRandomDelaySetTimer @ 1c00032bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RamParserRandomDelaySetTimer(longlong param_1)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  *(undefined8 *)(param_1 + 0x6a0) = _DAT_fffff78000000008;
  local_28 = 0;
  uStack_20 = 0;
  ExSetTimer(*(undefined8 *)(param_1 + 0x640),0xfffffffffff85ee0,0,&local_28);
  return;
}



===== RamParserRandomDelayThread @ 1c0003330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RamParserRandomDelayThread(longlong *param_1)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  undefined1 local_70;
  undefined8 local_68;
  undefined8 local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48 [4];
  
  local_48[2] = __security_cookie ^ (ulonglong)auStack_98;
  lVar4 = *param_1;
  uVar3 = *(uint *)((longlong)param_1 + 0x14);
  uVar5 = KeQueryMaximumProcessorCountEx(0);
  local_48[1] = 0;
  local_48[0] = 1L << ((byte)((uVar3 + 1) % uVar5) & 0x3f);
  KeSetSystemGroupAffinityThread(local_48,0);
  do {
    while( true ) {
      local_60 = 0;
      local_68 = 0;
      local_70 = 0;
      local_78 = 0;
      local_58 = lVar4 + 0x688;
      local_50 = lVar4 + 0x658;
      iVar6 = KeWaitForMultipleObjects(2,&local_58,1);
      *(int *)((longlong)param_1 + 0x1c) = iVar6;
      if (iVar6 != 1) goto LAB_1c0003505;
      lVar1 = lVar4 + 0x670;
      KeClearEvent(lVar1);
      uVar5 = *(uint *)(lVar4 + 0x654);
      while (lVar7 = ExpInterlockedPopEntrySList
                               (((ulonglong)uVar3 * 0x10 + 0x24 + (ulonglong)uVar5) * 0x10 + lVar4),
            lVar7 != 0) {
        RamParserRunRequest(lVar7 + -0x10);
        LOCK();
        *(int *)(param_1 + 2) = (int)param_1[2] + -1;
        UNLOCK();
      }
      LOCK();
      piVar2 = (int *)(lVar4 + 0x650);
      iVar6 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      if (iVar6 != 2) break;
      KeClearEvent(lVar4 + 0x658);
      *(uint *)(lVar4 + 0x654) = uVar5 + 1 & 0xf;
      *(undefined4 *)(lVar4 + 0x650) = 0;
      *(int *)(param_1 + 5) = (int)param_1[5] + 1;
      param_1[4] = _DAT_fffff78000000008;
      RamParserRandomDelaySetTimer(lVar4);
      KeSetEvent(lVar1,0,0);
    }
    local_60 = 0;
    local_68 = 0;
    local_70 = 0;
    local_78 = 0;
    local_58 = lVar4 + 0x688;
    local_50 = lVar1;
    iVar6 = KeWaitForMultipleObjects(2,&local_58,1);
    *(int *)((longlong)param_1 + 0x1c) = iVar6;
  } while (iVar6 == 1);
LAB_1c0003505:
  PsTerminateSystemThread(0);
  return;
}



===== RamParserRandomDelayTickCallback @ 1c0003550 =====

void RamParserRandomDelayTickCallback(undefined8 param_1,undefined8 param_2)

{
  KeSetEvent(param_2,0,0);
  return;
}



===== RamParserReadWrite @ 1c0003574 =====

undefined8
RamParserReadWrite(longlong *param_1,undefined8 *param_2,char param_3,ulonglong param_4,uint param_5
                  )

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  void *pvVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar3 = *param_1;
  uVar6 = (ulonglong)(*(uint *)(uVar3 + 0x28) >> 9);
  if ((param_4 <= uVar6) && (uVar3 = (ulonglong)param_5, uVar3 <= uVar6 - param_4)) {
    uVar3 = param_2[1];
    uVar5 = param_5 * 0x200;
    if (uVar5 <= *(uint *)(uVar3 + 0xc)) {
      iVar2 = RamParserLoadDataBlocks(param_1,param_2,(uint)param_4,param_5);
      if (iVar2 != 0) {
        return CONCAT44(extraout_var,iVar2) & 0xffffffffffffff00;
      }
      lVar1 = param_2[2];
      if ((*(byte *)(lVar1 + 10) & 5) == 0) {
        pvVar4 = (void *)MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
      }
      else {
        pvVar4 = *(void **)(lVar1 + 0x18);
      }
      uVar3 = 0;
      if (pvVar4 != (void *)0x0) {
        if (param_3 == '\0') {
          pvVar4 = memcpy(pvVar4,(void *)(param_4 * 0x200 + *(longlong *)(*param_1 + 0x20)),
                          (ulonglong)uVar5);
        }
        else {
          memcpy((void *)(param_4 * 0x200 + *(longlong *)(*param_1 + 0x20)),pvVar4,(ulonglong)uVar5)
          ;
          pvVar4 = (void *)RamParserMarkDataBlocks(param_1,(uint)param_4,param_5,4);
        }
        return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
      }
    }
  }
  return CONCAT71((int7)(uVar3 >> 8),4);
}



===== RamParserReleaseData @ 1c0003690 =====

void RamParserReleaseData(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&RamParserDataLock,0);
  puVar5 = auStack_28;
  if (param_2 == 0) {
LAB_1c00036e3:
    plVar1 = param_1 + 6;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      lVar2 = *param_1;
      if ((*(longlong **)(lVar2 + 8) == param_1) &&
         (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 == param_1)) {
        *plVar1 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar1;
        puVar5 = auStack_28;
        goto LAB_1c000370e;
      }
      goto LAB_1c0003705;
    }
  }
  else {
    plVar1 = (longlong *)(param_2 + 8);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_2 + 0x10), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      goto LAB_1c00036e3;
    }
LAB_1c0003705:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar5 = auStack_20;
  }
  param_1 = (longlong *)0x0;
LAB_1c000370e:
  *(undefined8 *)(puVar5 + -8) = 0x1c000371e;
  ExReleasePushLockExclusiveEx(&RamParserDataLock,0);
  *(undefined8 *)(puVar5 + -8) = 0x1c000372a;
  KeLeaveCriticalRegion();
  if (param_1 != (longlong *)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x1c000373c;
    RamParserFreeData((longlong)param_1);
  }
  return;
}



===== RamParserRunRequest @ 1c0003750 =====

void RamParserRunRequest(longlong param_1)

{
  bool bVar1;
  
  if (*(char *)((longlong)*(longlong **)(param_1 + 0x20) + 0xd2) == '\0') {
    bVar1 = RamParserExecuteRequest(*(longlong **)(param_1 + 0x20),*(undefined8 **)(param_1 + 0x28))
    ;
    if (!bVar1) {
      return;
    }
  }
  else {
    *(undefined1 *)((*(undefined8 **)(param_1 + 0x28))[1] + 2) = 2;
    *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 8) + 3) = 0;
  }
  VstorCompleteScsiRequest(*(undefined8 *)(param_1 + 0x28));
  return;
}



===== RamParserSetBehavior @ 1c00037b0 =====

undefined8 RamParserSetBehavior(longlong *param_1,int param_2,ulonglong *param_3,uint param_4)

{
  undefined8 uVar1;
  
  if (param_2 == 0x40000001) {
    uVar1 = RamParserSetBlockData(param_1,(uint *)param_3,param_4);
  }
  else if (param_2 == 0x40000002) {
    uVar1 = RamParserMarkDataCommitState(param_1,param_3,param_4);
  }
  else {
    uVar1 = 0xc0000010;
  }
  return uVar1;
}



===== RamParserSetBlockData @ 1c00037f0 =====

undefined8 RamParserSetBlockData(longlong *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (7 < param_3) {
    uVar1 = param_2[1];
    if (((ulonglong)uVar1 <= (ulonglong)param_3 - 8) &&
       (uVar2 = *param_2, ((uVar1 | uVar2) & 0x1ff) == 0)) {
      uVar3 = uVar2 >> 9;
      uVar4 = (ulonglong)(*(uint *)(*param_1 + 0x28) >> 9);
      if ((uVar3 <= uVar4) && ((ulonglong)(uVar1 >> 9) <= uVar4 - uVar3)) {
        memcpy((void *)(*(longlong *)(*param_1 + 0x20) + (ulonglong)uVar2),param_2 + 2,
               (ulonglong)uVar1);
        RamParserMarkDataBlocks(param_1,uVar3,uVar1 >> 9,5);
        *(undefined1 *)(*param_1 + 100) = 0;
        RamParserProcessPendingIO(param_1,'\0');
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== RamParserStartTimerLocked @ 1c00038a8 =====

void RamParserStartTimerLocked(longlong *param_1)

{
  if (((char)param_1[0x2e] == '\0') &&
     (((*(char *)((longlong)param_1 + 0xd2) != '\0' || (*(char *)(*param_1 + 0x48) == '\0')) &&
      ((longlong *)param_1[0x1b] != param_1 + 0x1b)))) {
    *(undefined1 *)(param_1 + 0x2e) = 1;
    if ((*(char *)((longlong)param_1 + 0xd2) == '\0') && (*(uint *)(*param_1 + 0x4c) != 0)) {
      KeSetTimer(param_1 + 0x25,(ulonglong)*(uint *)(*param_1 + 0x4c) * -10000,param_1 + 0x1d);
    }
    else {
      KeInsertQueueDpc(param_1 + 0x1d,0,0);
    }
  }
  return;
}



===== RamParserStopThreadsRandomDelay @ 1c0003930 =====

void RamParserStopThreadsRandomDelay(longlong param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  longlong lVar6;
  undefined8 local_res8;
  
  local_res8 = 0;
  KeSetEvent(param_1 + 0x688,0,0);
  lVar3 = 4;
  pcVar2 = (char *)(param_1 + 400);
  lVar4 = 4;
  do {
    if (*pcVar2 != '\0') {
      local_res8 = 0xffffffffff676980;
      ZwWaitForSingleObject(*(undefined8 *)(pcVar2 + -0x10),0,&local_res8);
      ZwClose(*(undefined8 *)(pcVar2 + -0x10));
      *pcVar2 = '\0';
    }
    pcVar2 = pcVar2 + 0x30;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  piVar5 = (int *)(param_1 + 0x188);
  lVar4 = param_1 + 0x240;
  do {
    lVar6 = 0x10;
    do {
      while( true ) {
        lVar1 = ExpInterlockedPopEntrySList(lVar4);
        if (lVar1 == 0) break;
        RamParserRunRequest(lVar1 + -0x10);
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
      }
      lVar4 = lVar4 + 0x10;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    piVar5 = piVar5 + 0xc;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== RamParserSupportsDataTransferDirectionValidation @ 1c0003a20 =====

undefined1 RamParserSupportsDataTransferDirectionValidation(void)

{
  return 1;
}



===== RamParserTeardownRandomDelay @ 1c0003a2c =====

void RamParserTeardownRandomDelay(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  RamParserStopThreadsRandomDelay(param_1);
  if (*(longlong *)(param_1 + 0x640) != 0) {
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    ExDeleteTimer(*(longlong *)(param_1 + 0x640),1,1,&local_28);
    *(undefined8 *)(param_1 + 0x640) = 0;
  }
  return;
}



===== RamParserTimerDpc @ 1c0003a90 =====

void RamParserTimerDpc(undefined8 param_1,longlong param_2)

{
  IoQueueWorkItem(*(undefined8 *)(param_2 + 0x168),RamParserTimerWorkerRoutine,1,param_2);
  return;
}



===== RamParserTimerWorkerRoutine @ 1c0003ad0 =====

void RamParserTimerWorkerRoutine(undefined8 param_1,longlong *param_2)

{
  longlong ***ppplVar1;
  longlong *****ppppplVar2;
  longlong ****pppplVar3;
  longlong ****pppplVar4;
  longlong ***ppplVar5;
  longlong *****ppppplVar6;
  code *pcVar7;
  longlong *****local_18;
  longlong *****local_10;
  
  local_10 = (longlong *****)&local_18;
  local_18 = (longlong *****)&local_18;
  ExAcquirePushLockExclusiveEx(*param_2 + 0x50,0);
  *(undefined1 *)(param_2 + 0x2e) = 0;
  if (*(char *)((longlong)param_2 + 0xd2) == '\0') {
    if (*(char *)(*param_2 + 0x48) == '\0') {
      if (*(int *)(*param_2 + 0x4c) == 0) goto LAB_1c0003b7b;
      pppplVar4 = (longlong ****)(param_2 + 0x1b);
      ppppplVar2 = (longlong *****)*pppplVar4;
      if ((ppppplVar2[1] != pppplVar4) ||
         (pppplVar3 = *ppppplVar2, (longlong *****)pppplVar3[1] != ppppplVar2)) goto LAB_1c0003c39;
      *pppplVar4 = (longlong ***)pppplVar3;
      pppplVar3[1] = (longlong ***)pppplVar4;
      if ((longlong ******)*local_10 != &local_18) goto LAB_1c0003c39;
      ppppplVar2[1] = (longlong ****)local_10;
      *ppppplVar2 = (longlong ****)&local_18;
      *local_10 = (longlong ****)ppppplVar2;
      local_10 = ppppplVar2;
      RamParserStartTimerLocked(param_2);
    }
  }
  else {
LAB_1c0003b7b:
    ppplVar1 = (longlong ***)(param_2 + 0x1b);
    pppplVar4 = (longlong ****)*ppplVar1;
    ppplVar5 = (longlong ***)param_2[0x1c];
    if ((pppplVar4[1] != ppplVar1) || ((longlong ***)*ppplVar5 != ppplVar1)) goto LAB_1c0003c39;
    *ppplVar5 = (longlong **)pppplVar4;
    pppplVar4[1] = ppplVar5;
    if (((longlong ******)local_18[1] != &local_18) ||
       ((((longlong ******)*local_10 != &local_18 || ((longlong ****)(*pppplVar4)[1] != pppplVar4))
        || ((longlong ****)*ppplVar5 != pppplVar4)))) goto LAB_1c0003c39;
    *local_10 = pppplVar4;
    ppppplVar2 = (longlong *****)pppplVar4[1];
    *pppplVar4[1] = (longlong **)&local_18;
    pppplVar4[1] = (longlong ***)local_10;
    param_2[0x1c] = (longlong)ppplVar1;
    *ppplVar1 = (longlong **)ppplVar1;
    local_10 = ppppplVar2;
  }
  ExReleasePushLockExclusiveEx(*param_2 + 0x50,0);
  while( true ) {
    ppppplVar2 = local_18;
    if ((longlong ******)local_18 == &local_18) {
      return;
    }
    if (((longlong ******)local_18[1] != &local_18) ||
       (ppppplVar6 = (longlong *****)*local_18, (longlong *****)ppppplVar6[1] != local_18)) break;
    ppppplVar6[1] = (longlong ****)&local_18;
    local_18 = ppppplVar6;
    RamParserRunRequest((longlong)ppppplVar2);
  }
LAB_1c0003c39:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  return;
}



===== RamParserUnblock @ 1c0003c54 =====

void RamParserUnblock(longlong param_1)

{
  undefined8 *puVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x50,0);
  *(undefined1 *)(param_1 + 0x48) = 0;
  for (puVar1 = *(undefined8 **)(param_1 + 0x38); puVar1 != (undefined8 *)(param_1 + 0x38);
      puVar1 = (undefined8 *)*puVar1) {
    RamParserStartTimerLocked(puVar1 + -1);
  }
  ExReleasePushLockExclusiveEx(param_1 + 0x50,0);
  KeLeaveCriticalRegion();
  return;
}



===== _guard_check_icall @ 1c0003ce0 =====

void _guard_check_icall(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1c0003cec =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c0003e40 =====

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



===== WdmlibRtlInitUnicodeStringEx @ 1c0003ec4 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== DvScsiValidateDataTransferDirection @ 1c0003f10 =====

undefined1 DvScsiValidateDataTransferDirection(byte param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  
  if (param_1 < 0x4b) {
    if (param_1 != 0x4a) {
      if (0x1d < param_1) {
        if (param_1 < 0x30) {
          if (param_1 == 0x2f) {
            return 1;
          }
          if (param_1 == 0x1e) {
            return 1;
          }
          if ((param_1 == 0x25) || (param_1 == 0x28)) goto LAB_1c00040b7;
          if (param_1 != 0x2a) {
            bVar2 = param_1 == 0x2e;
            goto LAB_1c0003fd4;
          }
        }
        else {
          if (param_1 == 0x35) {
            return 1;
          }
          if ((param_1 != 0x41) && (param_1 != 0x42)) {
            if (param_1 != 0x43) {
              bVar2 = param_1 == 0x46;
              goto LAB_1c00040b1;
            }
            goto LAB_1c00040b7;
          }
        }
        goto LAB_1c0004064;
      }
      if (param_1 == 0x1d) {
        return 1;
      }
      if (param_1 < 0x13) {
        if (param_1 != 0x12) {
          if (param_1 == 0) {
            return 1;
          }
          if (param_1 != 3) {
            if (param_1 == 4) {
              return 1;
            }
            if (param_1 != 8) {
              bVar2 = param_1 == 10;
              goto LAB_1c0004062;
            }
          }
        }
      }
      else {
        if (param_1 == 0x15) goto LAB_1c0004064;
        if (param_1 == 0x16) {
          return 1;
        }
        if (param_1 == 0x17) {
          return 1;
        }
        if (param_1 != 0x1a) {
          bVar2 = param_1 == 0x1b;
LAB_1c0003fd4:
          if (bVar2) {
            return 1;
          }
          return 0;
        }
      }
    }
    goto LAB_1c00040b7;
  }
  if (param_1 < 0x8b) {
    if (param_1 != 0x8a) {
      if (param_1 < 0x5f) {
        if (((param_1 != 0x5e) && (param_1 != 0x51)) && (param_1 != 0x52)) {
          if (param_1 == 0x55) goto LAB_1c0004064;
          if (param_1 != 0x5a) {
            bVar2 = param_1 == 0x5c;
            goto LAB_1c00040b1;
          }
        }
        goto LAB_1c00040b7;
      }
      if (param_1 != 0x5f) {
        if (param_1 == 0x83) {
          return 1;
        }
        if ((param_1 == 0x84) || (param_1 == 0x88)) goto LAB_1c00040b7;
        bVar2 = param_1 == 0x89;
LAB_1c0004062:
        if (!bVar2) {
          return 0;
        }
      }
    }
  }
  else {
    if (0xaa < param_1) {
      if ((param_1 != 0xac) && (param_1 != 0xad)) {
        if (param_1 == 0xb6) goto LAB_1c0004064;
        bVar2 = param_1 == 0xbd;
LAB_1c00040b1:
        if (!bVar2) {
          return 0;
        }
      }
LAB_1c00040b7:
      uVar1 = 0x40;
      goto LAB_1c00040bc;
    }
    if (param_1 != 0xaa) {
      if (param_1 == 0x8f) {
        return 1;
      }
      if (param_1 == 0x91) {
        return 1;
      }
      if (param_1 != 0x93) {
        if (param_1 != 0x9e) {
          bVar2 = param_1 == 0xa8;
          goto LAB_1c00040b1;
        }
        goto LAB_1c00040b7;
      }
    }
  }
LAB_1c0004064:
  uVar1 = 0x80;
LAB_1c00040bc:
  if (uVar1 == (param_2 & 0xc0)) {
    return 1;
  }
  return 0;
}



===== __GSHandlerCheck @ 1c00040d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00040fc =====

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



===== __cpu_features_init @ 1c0004170 =====

/* WARNING: Removing unreachable block (ram,0x0001c00041da) */
/* WARNING: Removing unreachable block (ram,0x0001c0004189) */
/* WARNING: Removing unreachable block (ram,0x0001c000417a) */

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



===== __security_check_cookie @ 1c0004240 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004280 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00042b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00042b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00042e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004340 =====

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



===== memset @ 1c0004640 =====

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



===== __memset_repmovs @ 1c0004780 =====

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



===== __memset_query @ 1c0004800 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004880 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00049c0 =====

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



===== __memset_spec_plain @ 1c0004a40 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1c000a008 =====

/* WARNING: Removing unreachable block (ram,0x0001c000a030) */
/* WARNING: Removing unreachable block (ram,0x0001c000a040) */
/* WARNING: Removing unreachable block (ram,0x0001c000a045) */
/* WARNING: Removing unreachable block (ram,0x0001c000a04a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a055) */
/* WARNING: Removing unreachable block (ram,0x0001c000a06a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a060) */
/* WARNING: Removing unreachable block (ram,0x0001c000a07a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a097) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0a6) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0ab) */
/* WARNING: Removing unreachable block (ram,0x0001c000a09d) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0ad) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0b2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0a2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a035) */
/* WARNING: Removing unreachable block (ram,0x0001c000a03e) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0bd) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0c2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0b4) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0e5) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0c4) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0de) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0e3) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0d5) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0da) */
/* WARNING: Removing unreachable block (ram,0x0001c000a0b9) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000a0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1c000a190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1c000a190;
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
LAB_1c000a190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000a1e0 =====

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
              if (&UNK_1c0006d8f < plVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000a260 =====

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
    if (*plVar3 != 0) goto LAB_1c000a35d;
  }
LAB_1c000a366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1c000a35d:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000a366;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1c000a32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1c000a32e;
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
    if (&UNK_1c0006d8f < plVar3) goto LAB_1c000a366;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000a35d;
}



===== WdmlibIoCreateDeviceSecure @ 1c000a38c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,0,&RamParserDeviceObject);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c000a480 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c000a5e0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c000a5e0;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_1c000a5e0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c000a614 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 1c000a704 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memcpy(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 1c000a7e4 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 1c000a8e4 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 1c000a9d0 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_1c000ad6b:
              iVar5 = -0x3ffffff3;
LAB_1c000ad6d:
              lVar7 = *param_2;
              goto LAB_1c000ad53;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c000ad6b;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_1c0007010;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_1c000701c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_1c0007018)[uVar11 * 4];
                    goto LAB_1c000ac5d;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c000ad6b;
                uVar15 = (uint)local_res8;
LAB_1c000ac5d:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c000ad6d;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_1c000ad6d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c000acdb:
              iVar5 = -0x3fffff89;
              goto LAB_1c000ad6d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c000acdb;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c000ad6d;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_1c000ad53:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c000ad98 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_1c00070e4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c00070dc + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c00070d8 + uVar7 * 0x18);
      uVar6 = (&DAT_1c00070e4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c000ae2f;
      }
      else {
LAB_1c000ae2f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c00070d0 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c000ae44;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c000ae44:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c000ae6c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1c000aeef:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c000aecd;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c000aeef;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c000aecd:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 1c000af78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_1c000b0bd;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c000b0bd:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c000b11c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c00064a0,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1c000b2b8 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c0006420);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_1c000b437;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0006438,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c000b437;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0006450,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c000b437;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0006480,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c000b437:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 1c000b47c =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c00063c0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c00063d8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c00063e8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c0006408,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c000b5e0 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1c00063c0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c0006420);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c000b748 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateWstrKey @ 1c000b844 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 1c000b914 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 1c000b9a8 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_1c000bae0;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c000bae0:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c000bb24 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memcpy(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 1c000bc70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 1c000bd14 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== entry @ 1c000c010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000c044 =====

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



===== wil_InitializeFeatureStaging @ 1c000c078 =====

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
      if (*plVar3 != 0) goto LAB_1c000c0ff;
    }
LAB_1c000c139:
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
LAB_1c000c0ff:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000c139;
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
    goto LAB_1c000c139;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0006d8f < plVar3) goto LAB_1c000c139;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000c0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000c18c =====

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
            if (&UNK_1c0006d8f < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1c000c276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1c000c276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1c000c276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1c0006d8f < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


