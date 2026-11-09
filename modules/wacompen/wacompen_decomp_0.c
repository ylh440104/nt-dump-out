
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



===== OemIsResyncDataValid @ 1c0001020 =====

char OemIsResyncDataValid(longlong param_1)

{
  char cVar1;
  char *_Src;
  char *pcVar2;
  
  if ((((((*(byte *)(param_1 + 0x78) & 0xd8) == 0x80) &&
        ((*(ushort *)(param_1 + 0x79) & 0x8080) == 0)) &&
       ((*(ushort *)(param_1 + 0x7b) & 0x8080) == 0)) &&
      (((*(ushort *)(param_1 + 0x7d) & 0x8080) == 0 && (-1 < *(char *)(param_1 + 0x7f))))) &&
     (-1 < *(char *)(param_1 + 0x80))) {
    cVar1 = '\x01';
    if (*(uint *)(param_1 + 0x8c) < 10) {
      return '\x01';
    }
  }
  else {
    cVar1 = '\0';
  }
  _Src = (char *)(param_1 + 0x77 + (ulonglong)*(uint *)(param_1 + 0x8c));
  pcVar2 = (char *)((ulonglong)(-(uint)(cVar1 != '\0') & 9) + 0x78 + param_1);
  do {
    if (_Src <= pcVar2) {
      if (cVar1 == '\0') {
LAB_1c00010d0:
        if (_Src <= pcVar2) {
          *(undefined4 *)(param_1 + 0x8c) = 0;
        }
      }
      return cVar1;
    }
    if (*_Src < '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_dDDDDDDDDDDDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(byte *)(param_1 + 0x88),
                   (ulonglong)*(ushort *)(param_1 + 0x86),*(uint *)(param_1 + 0x8c),
                   *(byte *)(param_1 + 0x78),(char)*(undefined2 *)(param_1 + 0x79),
                   (char)*(undefined2 *)(param_1 + 0x7b),(char)*(undefined2 *)(param_1 + 0x7d),
                   *(undefined1 *)(param_1 + 0x7f),*(undefined1 *)(param_1 + 0x80),
                   *(undefined1 *)(param_1 + 0x81),(char)*(undefined2 *)(param_1 + 0x82),
                   (char)*(undefined2 *)(param_1 + 0x84),(char)*(ushort *)(param_1 + 0x86),
                   *(byte *)(param_1 + 0x88),*(undefined1 *)(param_1 + 0x89));
      }
      *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + ((int)param_1 - (int)_Src) + 0x78;
      memcpy((undefined1 *)(param_1 + 0x78),_Src,(ulonglong)*(uint *)(param_1 + 0x8c));
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_dDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                       (ulonglong)*(byte *)(param_1 + 0x7f),(ulonglong)*(ushort *)(param_1 + 0x7d),
                       *(undefined4 *)(param_1 + 0x8c),*(undefined1 *)(param_1 + 0x78),
                       (char)*(undefined2 *)(param_1 + 0x79),(char)*(undefined2 *)(param_1 + 0x7b),
                       (char)*(ushort *)(param_1 + 0x7d),*(byte *)(param_1 + 0x7f),
                       *(undefined1 *)(param_1 + 0x80));
      }
      cVar1 = '\0';
      goto LAB_1c00010d0;
    }
    _Src = _Src + -1;
  } while( true );
}



===== OemNormalizeInputData @ 1c0001258 =====

undefined8 OemNormalizeInputData(longlong param_1,byte *param_2)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  ushort uVar5;
  ushort uVar6;
  ulonglong uVar7;
  ushort uVar8;
  byte bVar9;
  ulonglong uVar10;
  byte bVar11;
  ushort *puVar12;
  undefined1 uVar13;
  
  bVar2 = *param_2;
  bVar9 = bVar2 & 0x20;
  if ((bVar2 & 4) == 0) {
    uVar8 = *(ushort *)(param_1 + 0xa2);
  }
  else {
    uVar8 = *(ushort *)(param_1 + 0xa4);
  }
  puVar1 = (ushort *)(param_2 + 5);
  uVar6 = *puVar1;
  uVar10 = (ulonglong)(-(uint)((bVar2 & 4) != 0) & 2);
  *(ushort *)(param_2 + 1) =
       (uVar6 >> 7 & 0xc0 | *(ushort *)(param_2 + 1) & 0x7f00) >> 6 | *(ushort *)(param_2 + 1) << 9;
  *(ushort *)(param_2 + 3) =
       (uVar6 >> 5 & 0xc0 | *(ushort *)(param_2 + 3) & 0x7f00) >> 6 | *(ushort *)(param_2 + 3) << 9;
  if (bVar9 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 >> 1 & 0x80 | uVar6 & 0x7f;
  }
  param_2[7] = param_2[7] & 0x7f;
  param_2[8] = param_2[8] & 0x7f;
  *puVar1 = uVar6;
  if (((*(byte *)(param_1 + 0x9c) & 0x20) == 0) && (bVar9 != 0)) {
    if (uVar6 < 0x10) {
      *(ushort *)(uVar10 + 0x9e + param_1) = uVar6;
    }
  }
  else if (uVar6 < *(ushort *)(uVar10 + 0x9e + param_1)) {
    *(ushort *)(uVar10 + 0x9e + param_1) = uVar6;
  }
  puVar12 = (ushort *)(param_2 + 5);
  uVar5 = *puVar1 - *(short *)(uVar10 + 0x9e + param_1);
  *puVar12 = uVar5;
  bVar11 = *param_2 & 0xfe;
  uVar6 = *(ushort *)(param_1 + 0x96);
  uVar3 = *(ushort *)(uVar10 + 0x9e + param_1);
  *param_2 = bVar11;
  uVar10 = (longlong)(ulonglong)((uint)uVar5 * (uint)uVar6 & 0xffff) /
           (longlong)(int)((uint)uVar6 - (uint)uVar3);
  uVar7 = uVar10 & 0xffffffff;
  *puVar12 = (ushort)uVar7;
  if ((ushort)uVar10 < uVar8) {
    uVar8 = 0;
  }
  else {
    uVar6 = (ushort)uVar7 - uVar8;
    *puVar12 = uVar6;
    bVar11 = bVar11 | 1;
    *param_2 = bVar11;
    lVar4 = (longlong)(int)((uint)*(ushort *)(param_1 + 0x96) - (uint)uVar8);
    uVar10 = (ulonglong)((uint)uVar6 * (uint)*(ushort *)(param_1 + 0x96) & 0xffff);
    uVar8 = (ushort)((longlong)uVar10 / lVar4);
    uVar7 = (longlong)uVar10 % lVar4 & 0xffffffff;
  }
  *puVar12 = uVar8;
  if ((bVar11 & 5) == 5) {
    bVar11 = bVar11 & 0xfe | 8;
  }
  else {
    bVar11 = bVar11 & 0xf7;
  }
  *param_2 = bVar11;
  if (bVar9 == 0) {
    *param_2 = bVar11 & 0xf6;
  }
  if (*(ushort *)(param_1 + 0x92) < *(ushort *)(param_2 + 1)) {
    *(ushort *)(param_2 + 1) = *(ushort *)(param_1 + 0x92);
  }
  if (*(ushort *)(param_1 + 0x94) < *(ushort *)(param_2 + 3)) {
    *(ushort *)(param_2 + 3) = *(ushort *)(param_1 + 0x94);
  }
  *(byte *)(param_1 + 0x9c) = bVar2;
  PoSetSystemState(4,uVar7);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    bVar2 = param_2[7];
    uVar13 = (undefined1)*(ushort *)(param_2 + 5);
    WPP_SF_DDdDdDdDdDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar2,
                       (ulonglong)*(ushort *)(param_2 + 5),(uint)*param_2,
                       (char)*(undefined2 *)(param_2 + 1),(char)*(undefined2 *)(param_2 + 1),
                       (char)*(undefined2 *)(param_2 + 3),(char)*(undefined2 *)(param_2 + 3),uVar13,
                       uVar13,bVar2,bVar2,param_2[8],param_2[8]);
  }
  return 0;
}



===== SetDeviceReportDescriptor @ 1c00014e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SetDeviceReportDescriptor(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = 0xc000000d;
  if (param_1 != 0) {
    _DAT_1c000608d = *(undefined2 *)(param_1 + 0x92);
    _DAT_1c0006097 = *(undefined2 *)(param_1 + 0x94);
    uVar1 = ((uint)*(ushort *)(param_1 + 0x92) * 1000) / 0x9ec;
    if (uVar1 < 0x10000) {
      uVar2 = ((uint)*(ushort *)(param_1 + 0x94) * 1000) / 0x9ec;
      if (uVar2 < 0x10000) {
        _DAT_1c000608a = (undefined2)uVar1;
        _DAT_1c0006094 = (undefined2)uVar2;
      }
    }
    if (*(short *)(param_1 + 0x96) != 0) {
      _DAT_1c00060a1 = *(short *)(param_1 + 0x96);
    }
    if (*(char *)(param_1 + 0x98) != '\0') {
      DAT_1c00060aa = -*(char *)(param_1 + 0x98);
      DAT_1c00060ac = *(undefined1 *)(param_1 + 0x98);
    }
    if (*(char *)(param_1 + 0x99) != '\0') {
      DAT_1c00060b2 = -*(char *)(param_1 + 0x99);
      DAT_1c00060b4 = *(undefined1 *)(param_1 + 0x99);
    }
    *(undefined4 *)(param_1 + 0x9e) = 0x100010;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0xa2) = 0x30003;
  }
  return uVar3;
}



===== WPP_SF_D @ 1c00015f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDdDdDdDdDd @ 1c0001638 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDdDdDdDdDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9,undefined1 param_10,undefined1 param_11,
                       undefined1 param_12,undefined1 param_13,undefined1 param_14)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x23,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
             &param_12,4,&param_13,4,&param_14,4,0);
  return;
}



===== WPP_SF_DdDdDdDdDdDddd @ 1c0001710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DdDdDdDdDdDddd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,undefined1 param_16,
               undefined1 param_17)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x1a,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
             &param_12,4,&param_13,4,&param_14,4,&param_15,4,&param_16,4,&param_17,4,0);
  return;
}



===== WPP_SF_dDDDDDD @ 1c0001818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x20,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_dDDDDDDDDDDDD @ 1c00018b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDDDDDDDDDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,undefined1 param_16)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x1f,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
             &param_12,4,&param_13,4,&param_14,4,&param_15,4,&param_16,4,0);
  return;
}



===== WPP_SF_dd @ 1c00019ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_dddD @ 1c00019fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x1b,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dq @ 1c0001a6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0x1c,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_DD @ 1c0001ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 3;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,0xc,local_res20,4,
             local_18,4,0);
  return;
}



===== WPP_SF_SD @ 1c0001b28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SD(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uStack0000000000000028;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (L"DeviceInfo"[lVar1] != L'\0');
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,0xf,L"DeviceInfo",
             lVar1 * 2 + 2,&uStack0000000000000028,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001bb0 =====

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



===== DevicePowerIrpCompletion @ 1c0001bf0 =====

undefined4 DevicePowerIrpCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  if ((param_3 == 0) || (*(int *)(param_2 + 0x30) != 0)) {
    if (*(int *)(param_2 + 0x30) == -0x3fffffea) {
      return 0xc0000016;
    }
  }
  else {
    iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (((iVar2 < *(int *)(param_3 + 0x48)) && (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x10) == 1)
        ) && (piVar3 = (int *)ExAllocatePool2(0x40,0x18,0x6e657048), piVar3 != (int *)0x0)) {
      lVar4 = IoAllocateWorkItem(param_1);
      *(longlong *)(piVar3 + 4) = lVar4;
      if (lVar4 != 0) {
        *piVar3 = iVar2;
        *(longlong *)(piVar3 + 2) = param_2;
        IoQueueWorkItem(lVar4,WakeDeviceWorkItem,1,piVar3);
        return 0xc0000016;
      }
      ExFreePool(piVar3);
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return 0;
}



===== IrpCompletion @ 1c0001cf0 =====

undefined8 IrpCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  if (param_3 != 0) {
    KeSetEvent(param_3,0,0);
  }
  return 0xc0000016;
}



===== WakeDeviceWorkItem @ 1c0001d30 =====

void WakeDeviceWorkItem(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  longlong lVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = *param_2;
    puVar2 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x10);
    OemWakeupDevice(puVar2);
    *puVar2 = *puVar2 & 0xfffffffd;
    puVar2[0x12] = 1;
    PoSetPowerState(param_1,1,uVar1);
    lVar3 = *(longlong *)(param_2 + 2);
    if (lVar3 != 0) {
      IoReleaseRemoveLockEx(puVar2 + 8,lVar3,0x20);
      *(undefined8 *)(lVar3 + 0x38) = 0;
      *(undefined4 *)(lVar3 + 0x30) = 0;
      IofCompleteRequest(lVar3,0);
    }
    IoFreeWorkItem(*(undefined8 *)(param_2 + 4));
    ExFreePool(param_2);
  }
  return;
}



===== HpenInternalIoctl @ 1c0001e00 =====

int HpenInternalIoctl(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  uint *puVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  char cVar8;
  char local_res8 [8];
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x10);
  *(undefined8 *)(param_2 + 0x38) = 0;
  puVar1 = puVar4 + 8;
  iVar5 = IoAcquireRemoveLockEx(puVar1,param_2,"",1,0x20);
  if (iVar5 < 0) {
    LogError(0xc0050003,iVar5,0x20010);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,iVar5);
    }
    goto LAB_1c00020ce;
  }
  if ((*puVar4 & 1) == 0) {
    IoReleaseRemoveLockEx(puVar1,param_2,0x20);
    iVar5 = -0x3fffff5d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids);
    }
    goto LAB_1c00020ce;
  }
  iVar5 = *(int *)(lVar3 + 0x18);
  cVar8 = '\0';
  local_res8[0] = '\0';
  if (iVar5 == 0xb0003) {
    uVar6 = GetDeviceDescriptor(0,param_2);
    iVar5 = (int)uVar6;
LAB_1c00020b1:
    if (cVar8 != '\0') {
      return iVar5;
    }
  }
  else if (iVar5 == 0xb0007) {
    uVar6 = GetReportDescriptor(0,param_2);
    iVar5 = (int)uVar6;
  }
  else {
    if (iVar5 == 0xb000b) {
      iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
      if (iVar2 == 10) {
        uVar7 = OemReadReport((longlong)puVar4,param_2,local_res8);
        iVar5 = (int)uVar7;
        cVar8 = local_res8[0];
      }
      else {
        iVar5 = -0x3ffffdfa;
        LogError(0xc0050006,0xc0000206,0x20060);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,iVar2,10);
        }
      }
      goto LAB_1c00020b1;
    }
    if (iVar5 == 0xb000f) {
      iVar5 = -0x3fffff45;
      LogError(0xc0050001,0xc00000bb,0x40030);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids);
      }
    }
    else if (iVar5 == 0xb0013) {
      uVar6 = GetString(0,param_2);
      iVar5 = (int)uVar6;
    }
    else if ((iVar5 == 0xb001f) || (iVar5 == 0xb0023)) {
      iVar5 = 0;
    }
    else if (iVar5 == 0xb0027) {
      uVar6 = GetAttributes((longlong)puVar4,param_2);
      iVar5 = (int)uVar6;
    }
    else {
      iVar5 = -0x3fffff45;
      LogError(0xc0050001,0xc00000bb,0x20030);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,*(undefined4 *)(lVar3 + 0x18));
      }
    }
  }
  IoReleaseRemoveLockEx(puVar1,param_2,0x20);
LAB_1c00020ce:
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== WPP_SF_ @ 1c0002104 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_q @ 1c0002130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,0x10,&local_res20,8,0);
  return;
}



===== AsyncReadWriteCompletion @ 1c0002180 =====

undefined8 AsyncReadWriteCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 == -0x3ffffee0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids);
    }
  }
  else if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,iVar1);
  }
  if (param_3 != 0) {
    IoReleaseRemoveLockEx(param_3 + 0x20,param_2,0x20);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== SerialAsyncReadWriteData @ 1c0002248 =====

void SerialAsyncReadWriteData
               (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_3 + 0xb8);
  *(undefined8 *)(param_3 + 0x18) = param_4;
  memset((undefined1 *)(lVar1 + -0x48),0,0x48);
  *(undefined8 *)(lVar1 + -0x30) = 0;
  *(undefined4 *)(lVar1 + -0x40) = param_5;
  *(undefined1 *)(lVar1 + -0x48) = 3;
  lVar1 = *(longlong *)(param_3 + 0xb8);
  *(code **)(lVar1 + -0x10) = ReadReportCompletion;
  *(undefined8 *)(lVar1 + -8) = param_7;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(param_2 + 0x18),param_3);
  return;
}



===== SyncReadWriteCompletion @ 1c00022e0 =====

undefined8 SyncReadWriteCompletion(undefined8 param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    LOCK();
    iVar1 = *param_3;
    *param_3 = 3;
    UNLOCK();
    if (iVar1 == 1) {
      return 0xc0000016;
    }
    *param_3 = 0;
  }
  return 0;
}



===== OemReadReport @ 1c0002308 =====

ulonglong OemReadReport(longlong param_1,longlong param_2,undefined1 *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar1 = *(longlong *)(param_2 + 0x70);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
  uVar4 = ProcessResyncBuffer(param_1,param_2);
  lVar5 = param_1 + 0x40;
  uVar6 = uVar4 & 0xffffffff;
  KeReleaseSpinLock(lVar5,uVar2);
  if ((int)uVar4 < 0) {
    uVar3 = SerialAsyncReadWriteData
                      (lVar5,param_1,param_2,lVar1 + 1,9,in_stack_ffffffffffffffd0,lVar1);
    uVar6 = (ulonglong)uVar3;
    if (param_3 == (undefined1 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids);
      }
    }
    else {
      *param_3 = 1;
    }
  }
  return uVar6;
}



===== ProcessInputData @ 1c00023e8 =====

ulonglong ProcessInputData(longlong param_1,longlong param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
  if (((((*(uint *)(param_1 + 0x8c) == 0) && (*(longlong *)(param_2 + 0x38) == 9)) &&
       ((param_3[1] & 0xd8) == 0x80)) &&
      (((*(ushort *)(param_3 + 2) & 0x8080) == 0 && ((*(ushort *)(param_3 + 4) & 0x8080) == 0)))) &&
     (((*(ushort *)(param_3 + 6) & 0x8080) == 0 &&
      ((-1 < (char)param_3[8] && (-1 < (char)param_3[9])))))) {
    uVar3 = OemNormalizeInputData(param_1,param_3 + 1);
    uVar7 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_3 = 1;
      *(undefined8 *)(param_2 + 0x38) = 10;
      goto LAB_1c0002637;
    }
  }
  else {
    memcpy((void *)((ulonglong)*(uint *)(param_1 + 0x8c) + 0x78 + param_1),param_3 + 1,
           *(size_t *)(param_2 + 0x38));
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + *(int *)(param_2 + 0x38);
    uVar3 = ProcessResyncBuffer(param_1,param_2);
    uVar7 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) goto LAB_1c0002637;
  }
  uVar2 = IoAcquireRemoveLockEx(param_1 + 0x20,param_2,"",1,0x20);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    LogError(0xc0050003,uVar2,0x40040);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,uVar2);
    }
    if (uVar2 == 0xc0000016) goto LAB_1c0002637;
  }
  else {
    plVar4 = (longlong *)ExAllocatePool2(0x40,0x18,0x6e657048);
    if (plVar4 == (longlong *)0x0) {
      uVar7 = 0xc000009a;
      LogError(0xc0050002,0xc000009a,0x40060);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar6 = 0x15;
LAB_1c000260e:
        uVar7 = 0xc000009a;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids);
      }
    }
    else {
      lVar5 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 8));
      *plVar4 = lVar5;
      if (lVar5 != 0) {
        plVar4[1] = param_2;
        plVar4[2] = (longlong)param_3;
        IoQueueWorkItem(lVar5,ReadMoreBytes,1,plVar4);
        uVar7 = 0xc0000016;
        goto LAB_1c0002637;
      }
      uVar7 = 0xc000009a;
      LogError(0xc0050002,0xc000009a,0x40050);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar6 = 0x14;
        goto LAB_1c000260e;
      }
    }
  }
  IoReleaseRemoveLockEx(param_1 + 0x20,param_2,0x20);
LAB_1c0002637:
  KeReleaseSpinLock(param_1 + 0x40,uVar1);
  return uVar7;
}



===== ProcessResyncBuffer @ 1c000266c =====

ulonglong ProcessResyncBuffer(longlong param_1,longlong param_2)

{
  byte *_Dst;
  undefined1 *puVar1;
  char cVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar4 = *(uint *)(param_1 + 0x8c);
  puVar1 = *(undefined1 **)(param_2 + 0x70);
  uVar5 = 0xc000003e;
  do {
    if (uVar4 < 9) {
      return uVar5;
    }
    cVar2 = OemIsResyncDataValid(param_1);
    if (cVar2 != '\0') {
      _Dst = (byte *)(param_1 + 0x78);
      uVar3 = OemNormalizeInputData(param_1,_Dst);
      uVar5 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        *puVar1 = 1;
        *(undefined8 *)(puVar1 + 1) = *(undefined8 *)_Dst;
        puVar1[9] = *(undefined1 *)(param_1 + 0x80);
        *(undefined8 *)(param_2 + 0x38) = 10;
      }
      uVar4 = *(int *)(param_1 + 0x8c) - 9;
      *(uint *)(param_1 + 0x8c) = uVar4;
      if (uVar4 != 0) {
        memcpy(_Dst,(void *)(param_1 + 0x81),(ulonglong)uVar4);
      }
      if (-1 < (int)uVar3) {
        return uVar5;
      }
    }
    uVar4 = *(uint *)(param_1 + 0x8c);
  } while( true );
}



===== ReadMoreBytes @ 1c0002740 =====

void ReadMoreBytes(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 in_stack_ffffffffffffffe0;
  
  if (param_2 != (undefined8 *)0x0) {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x40);
    IoReleaseRemoveLockEx(lVar1 + 0x20,param_2[1],0x20);
    iVar4 = 9 - *(uint *)(lVar1 + 0x8c) % 9;
    KeReleaseSpinLock(lVar1 + 0x40,
                      CONCAT71((int7)(((ulonglong)*(uint *)(lVar1 + 0x8c) / 9) * 9 >> 8),uVar2));
    puVar3 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_D(puVar3,0x16,&WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,iVar4);
    }
    SerialAsyncReadWriteData
              (puVar3,lVar1,param_2[1],param_2[2] + 1,iVar4,in_stack_ffffffffffffffe0,param_2[2]);
    IoFreeWorkItem(*param_2);
    ExFreePool(param_2);
  }
  return;
}



===== ReadReportCompletion @ 1c0002870 =====

ulonglong ReadReportCompletion(longlong param_1,longlong param_2,undefined1 *param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  iVar2 = *(int *)(param_2 + 0x30);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (iVar2 == -0x3ffffee0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids);
    }
  }
  else {
    if (-1 < iVar2) {
      uVar4 = ProcessInputData(lVar3,param_2,param_3);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == -0x3fffffea) {
        return uVar5;
      }
      goto LAB_1c0002911;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,iVar2);
    }
  }
  uVar5 = 0;
LAB_1c0002911:
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  IoReleaseRemoveLockEx(lVar3 + 0x20,param_2,0x20);
  return uVar5;
}



===== LogError @ 1c0002954 =====

void LogError(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined4 in_register_00000014;
  
  if (gDriverObj != 0) {
    lVar1 = IoAllocateErrorLogEntry
                      (gDriverObj,CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),0x30)
                      );
    if (lVar1 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_9d1fa680160a3601379341e1a164d811_Traceguids,0x30);
      }
    }
    else {
      *(undefined4 *)(lVar1 + 4) = 0x280000;
      *(undefined4 *)(lVar1 + 0xc) = param_1;
      *(undefined4 *)(lVar1 + 0x14) = param_2;
      *(undefined4 *)(lVar1 + 0x10) = param_3;
      IoWriteErrorLogEntry(lVar1);
    }
  }
  return;
}



===== _guard_check_icall @ 1c0002a10 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002a28 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0002a4c =====

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



===== __cpu_features_init @ 1c0002ac0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0002b2a) */
/* WARNING: Removing unreachable block (ram,0x0001c0002ad9) */
/* WARNING: Removing unreachable block (ram,0x0001c0002aca) */

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



===== __security_check_cookie @ 1c0002b90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002bd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002c00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002c30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002c80 =====

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



===== memset @ 1c0002f80 =====

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



===== __memset_repmovs @ 1c00030c0 =====

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



===== __memset_query @ 1c0003140 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00031c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003300 =====

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



===== __memset_spec_plain @ 1c0003380 =====

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



===== OemInitDevice @ 1c0009008 =====

ulonglong OemInitDevice(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 local_res8;
  int local_res10 [2];
  longlong local_res18;
  undefined1 uVar7;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  local_res18 = 0;
  local_res10[0] = 0;
  iVar4 = 0x20000;
  uVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,0x20000,&local_res18);
  uVar6 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    LogError(0xc0050009,uVar2,0x50020);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar6;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return uVar6;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,uVar2);
    return uVar6;
  }
  iVar3 = RegQueryValue(local_res18,L"DeviceInfo",iVar4,(void *)(param_1 + 0x4c),0x5c);
  if ((((iVar3 < 0) || (*(short *)(param_1 + 0x92) == 0)) || (*(short *)(param_1 + 0x94) == 0)) ||
     (*(short *)(param_1 + 0x96) == 0)) {
    uVar2 = QueryDeviceInfo(param_1);
    lVar1 = local_res18;
    uVar6 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_1c00092e9;
    if (local_res18 != 0) {
      local_38 = 0;
      uStack_30 = 0;
      RtlInitUnicodeString(&local_38,L"DeviceInfo");
      iVar4 = 0;
      iVar3 = ZwSetValueKey(lVar1,&local_38,0,3,(void *)(param_1 + 0x4c),CONCAT44(uVar8,0x5c));
      if (iVar3 < 0) {
        iVar4 = 0x50;
        LogError(0xc005000b,iVar3,0x50);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          iVar4 = -0x3fffae30;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar3);
        }
      }
    }
  }
  else {
    uVar5 = SetDeviceReportDescriptor(param_1);
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c00092e9;
  }
  local_res8 = 0;
  iVar4 = RegQueryValue(local_res18,L"PressureThresholds",iVar4,&local_res8,4);
  uVar2 = local_res8;
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar4);
    }
  }
  else {
    uVar7 = (undefined1)(local_res8 >> 0x10);
    if ((*(ushort *)(param_1 + 0x96) < (ushort)local_res8) ||
       (*(ushort *)(param_1 + 0x96) < local_res8._2_2_)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,local_res8 & 0xffff,uVar7);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,local_res8 & 0xffff,uVar7);
      }
      *(uint *)(param_1 + 0xa2) = uVar2;
    }
    if (*(ushort *)(param_1 + 0xa2) < 3) {
      *(undefined2 *)(param_1 + 0xa2) = 3;
    }
    if (*(ushort *)(param_1 + 0xa4) < 3) {
      *(undefined2 *)(param_1 + 0xa4) = 3;
    }
  }
  uVar2 = SerialSyncReadWritePort
                    ('\0',param_1,"1",1,local_res10,(undefined8 *)0x0,(undefined4 *)0x0);
  uVar6 = (ulonglong)uVar2;
  if ((((int)uVar2 < 0) &&
      (LogError(0xc0050103,uVar2,0x50010), (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
     && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,uVar2);
  }
LAB_1c00092e9:
  if (local_res18 != 0) {
    ZwClose();
  }
  return uVar6;
}



===== OemInitSerialPort @ 1c0009364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int OemInitSerialPort(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStackY_88 [32];
  undefined1 local_48;
  undefined2 local_47;
  undefined4 local_44;
  undefined4 local_40 [2];
  int local_38 [4];
  ulonglong local_28 [4];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStackY_88;
  local_40[0] = 0x4b00;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  iVar1 = SerialSyncSendIoctl(0x1b0004,*(undefined8 *)(param_1 + 0x18),local_40,4,0,0,0,local_38);
  if (iVar1 < 0) {
    LogError(0xc0050102,iVar1,0x50060);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    uVar2 = 0x12;
  }
  else {
    local_47 = 0x800;
    local_48 = 0;
    iVar1 = SerialSyncSendIoctl(0x1b000c,*(undefined8 *)(param_1 + 0x18),&local_48,3,0,0,0,local_38)
    ;
    if (iVar1 < 0) {
      LogError(0xc0050102,iVar1,0x50070);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar1;
      }
      uVar2 = 0x13;
    }
    else {
      local_28[0] = 0;
      local_28[1] = 0;
      iVar1 = SerialSyncSendIoctl(0x1b0060,*(undefined8 *)(param_1 + 0x18),0,0,local_28,0x10,0,
                                  local_38);
      if (iVar1 < 0) {
        LogError(0xc0050102,iVar1,0x50080);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar1;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return iVar1;
        }
        uVar2 = 0x14;
      }
      else {
        local_28[0] = local_28[0] & 0xffffff7ffffffffd | 0x4000000001;
        iVar1 = SerialSyncSendIoctl(0x1b0064,*(undefined8 *)(param_1 + 0x18),local_28,0x10,0,0,0,
                                    local_38);
        if (iVar1 < 0) {
          LogError(0xc0050102,iVar1,0x50090);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return iVar1;
          }
          uVar2 = 0x15;
        }
        else {
          local_44 = 0x87;
          iVar1 = SerialSyncSendIoctl(0x1b009c,*(undefined8 *)(param_1 + 0x18),&local_44,4,0,0,0,
                                      local_38);
          if (iVar1 < 0) {
            LogError(0xc0050102,iVar1,0x500a0);
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar1;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
              return iVar1;
            }
            uVar2 = 0x16;
          }
          else {
            local_44 = 8;
            iVar1 = SerialSyncSendIoctl(0x1b004c,*(undefined8 *)(param_1 + 0x18),&local_44,4,0,0,0,
                                        local_38);
            if (-1 < iVar1) {
              return iVar1;
            }
            LogError(0xc0050102,iVar1,0x500b0);
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar1;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
              return iVar1;
            }
            uVar2 = 0x17;
          }
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar1);
  return iVar1;
}



===== OemWakeupDevice @ 1c00096b8 =====

int OemWakeupDevice(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  if ((*param_1 & 1) != 0) {
    puVar2 = param_1;
    iVar1 = OemInitSerialPort((longlong)param_1);
    if (-1 < iVar1) {
      iVar1 = SerialAsyncReadWritePort(puVar2,(longlong)param_1,"-1",2);
      if (iVar1 < 0) {
        LogError(0xc0050106,iVar1,0x50030);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar1);
        }
      }
    }
  }
  return iVar1;
}



===== QueryDeviceInfo @ 1c000974c =====

int QueryDeviceInfo(longlong param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined8 uVar6;
  int local_res10 [2];
  int local_res18 [2];
  int local_res20;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  local_res10[0] = 0;
  iVar1 = SerialSyncReadWritePort
                    ('\0',param_1,"0",1,local_res10,(undefined8 *)0x0,(undefined4 *)0x0);
  if (iVar1 < 0) {
    LogError(0xc0050104,iVar1,0x500c0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar1);
    }
  }
  else {
    local_48 = 0xffffffffff676980;
    KeDelayExecutionThread(0,0,&local_48);
    local_res20 = 2;
    do {
      iVar5 = local_res20;
      iVar1 = SerialSyncReadWritePort
                        ('\0',param_1,"*",1,local_res10,(undefined8 *)0x0,(undefined4 *)0x0);
      if (iVar1 < 0) {
        LogError(0xc0050104,iVar1,0x500d0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          uVar4 = 0x19;
LAB_1c0009c1d:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar1);
        }
      }
      else {
        local_res18[0] = 0;
        local_40 = 0;
        local_38._0_3_ = 0;
        iVar1 = 0x3c;
        local_48 = 0xffffffffff676980;
        do {
          iVar2 = SerialSyncReadWritePort
                            ('\x01',param_1,&local_40,1,local_res10,&local_48,local_res18);
          if (iVar2 != 0) break;
          if ((char)local_40 == -0x40) {
            iVar1 = SerialSyncReadWritePort
                              ('\x01',param_1,(longlong)&local_40 + 1,10,local_res10,&local_48,
                               local_res18);
            if (iVar1 == 0) {
              if (local_res18[0] == 10) {
                *(ushort *)(param_1 + 0x92) =
                     (local_40._5_2_ >> 7 & 0xc0 | local_40._1_2_ & 0x7f00) >> 6 |
                     local_40._1_2_ << 9;
                *(ushort *)(param_1 + 0x94) =
                     (local_40._5_2_ >> 5 & 0xc0 | local_40._3_2_ & 0x7f00) >> 6 |
                     local_40._3_2_ << 9;
                *(ushort *)(param_1 + 0x96) = local_40._5_2_ >> 1 & 0x80 | local_40._5_2_ & 0x7f;
                *(byte *)(param_1 + 0x98) = local_40._7_1_ & 0x7f;
                *(byte *)(param_1 + 0x99) = local_38[0] & 0x7f;
                *(ushort *)(param_1 + 0x9a) =
                     (ushort)local_38._1_2_ >> 8 & 0x7f | ((byte)local_38[1] & 0x7f) << 7;
                uVar3 = SetDeviceReportDescriptor(param_1);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                  uVar7 = (undefined1)*(undefined2 *)(param_1 + 0x94);
                  uVar8 = (undefined1)*(undefined2 *)(param_1 + 0x96);
                  uVar9 = (undefined1)*(ushort *)(param_1 + 0x9a);
                  WPP_SF_DdDdDdDdDdDddd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                             (ulonglong)*(ushort *)(param_1 + 0xa2),
                             (ulonglong)*(ushort *)(param_1 + 0x9a),
                             (uint)*(ushort *)(param_1 + 0x92),(char)*(ushort *)(param_1 + 0x92),
                             uVar7,uVar7,uVar8,uVar8,*(undefined1 *)(param_1 + 0x98),
                             *(undefined1 *)(param_1 + 0x98),*(undefined1 *)(param_1 + 0x99),
                             *(undefined1 *)(param_1 + 0x99),uVar9,uVar9,
                             (char)*(ushort *)(param_1 + 0xa2),(char)*(undefined2 *)(param_1 + 0xa4)
                            );
                  iVar5 = local_res20;
                }
                if (((*(short *)(param_1 + 0x92) != 0) && (*(short *)(param_1 + 0x94) != 0)) &&
                   (*(short *)(param_1 + 0x96) != 0)) {
                  return (int)uVar3;
                }
                iVar1 = -0x3fffff64;
                LogError(0xc0050104,0xc000009c,0x500d8);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                  WPP_SF_dddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                              (ulonglong)*(ushort *)(param_1 + 0x96),
                              (ulonglong)*(ushort *)(param_1 + 0x94),
                              (uint)*(ushort *)(param_1 + 0x92),(char)*(ushort *)(param_1 + 0x94),
                              (char)*(ushort *)(param_1 + 0x96),
                              (char)*(undefined2 *)(param_1 + 0x9a));
                }
              }
              else {
                uVar6 = 0x500e0;
                uVar3 = 0xc000009c;
                iVar1 = -0x3fffff64;
                LogError(0xc0050104,0xc000009c,0x500e0);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                  WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,uVar6,local_res18[0],
                            (char)&local_40);
                }
              }
              goto LAB_1c000992a;
            }
            iVar1 = -0x3fffff64;
            LogError(0xc0050104,0xc000009c,0x500f0);
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c000992a;
            uVar4 = 0x1d;
            goto LAB_1c0009c1d;
          }
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        iVar1 = -0x3fffff64;
        LogError(0xc0050104,0xc000009c,0x50110);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                   &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,0xc000009c);
        }
      }
LAB_1c000992a:
      local_res20 = iVar5 + -1;
    } while (local_res20 != 0);
  }
  return iVar1;
}



===== HpenAddDevice @ 1c0009c40 =====

undefined8 HpenAddDevice(undefined8 param_1,longlong param_2)

{
  void *_Dst;
  
  _Dst = *(void **)(*(longlong *)(param_2 + 0x40) + 0x10);
  memset(_Dst,0,0xa8);
  *(longlong *)((longlong)_Dst + 8) = param_2;
  *(undefined8 *)((longlong)_Dst + 0x10) = **(undefined8 **)(param_2 + 0x40);
  *(undefined8 *)((longlong)_Dst + 0x18) = *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8);
  IoInitializeRemoveLockEx((longlong)_Dst + 0x20,0x6e657048,0,10,0x20);
  KeInitializeSpinLock((longlong)_Dst + 0x40);
  *(undefined4 *)((longlong)_Dst + 0x48) = 1;
  *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xffffff7f | 0x2000;
  return 0;
}



===== HpenCreateClose @ 1c0009ce0 =====

undefined8 HpenCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== HpenSystemControl @ 1c0009d10 =====

int HpenSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x20,param_2,"",1,0x20);
  if (iVar2 < 0) {
    LogError(0xc0050003,iVar2,0x20);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,iVar2);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
    IoReleaseRemoveLockEx(lVar1 + 0x20,param_2,0x20);
  }
  return iVar2;
}



===== HpenUnload @ 1c0009e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HpenUnload(void)

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



===== RegQueryValue @ 1c0009e90 =====

int RegQueryValue(undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res18[0] = param_3;
  RtlInitUnicodeString(&local_18);
  local_res18[0] = param_5 + 0xc;
  lVar3 = ExAllocatePool2(0x100,local_res18[0],0x6e657048);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
    LogError(0xc0050002,0xc000009a,0x40);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,param_5);
    }
  }
  else {
    iVar2 = ZwQueryValueKey(param_1,&local_18,2,lVar3,local_res18[0],local_res18);
    if (-1 < iVar2) {
      if (*(int *)(lVar3 + 4) == 3) {
        uVar1 = *(uint *)(lVar3 + 8);
        if (param_5 < uVar1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,param_5,(char)uVar1);
          }
          iVar2 = -0x3fffffdd;
        }
        else {
          memcpy(param_4,(void *)(lVar3 + 0xc),(ulonglong)uVar1);
        }
      }
      else {
        iVar2 = -0x3fffffdc;
        uVar5 = 0x30;
        uVar4 = 0xc0000024;
        LogError(0xc005000c,0xc0000024,0x30);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uVar5,
                    *(undefined4 *)(lVar3 + 4));
        }
      }
    }
    ExFreePool(lVar3);
  }
  return iVar2;
}



===== WppInitKm @ 1c000a040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
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
  }
  return;
}



===== WppLoadTracingSupport @ 1c000a0d0 =====

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



===== WppTraceCallback @ 1c000a220 =====

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



===== HpenPnp @ 1c000a4b0 =====

ulonglong HpenPnp(longlong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  uint *puVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x10);
  puVar1 = puVar4 + 8;
  uVar6 = IoAcquireRemoveLockEx(puVar1,param_2,"",1,0x20);
  if ((int)uVar6 < 0) {
    LogError(0xc0050003,uVar6,0x10010);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,uVar6);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(uint *)(param_2 + 0x30) = uVar6;
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar6;
  }
  cVar2 = *(char *)(lVar3 + 1);
  bVar5 = false;
  if (cVar2 == '\0') {
LAB_1c000a6d9:
    uVar8 = SendSyncIrp(*(undefined8 *)(puVar4 + 6),param_2,'\x01');
    iVar7 = (int)uVar8;
    uVar8 = uVar8 & 0xffffffff;
    if (iVar7 < 0) {
      LogError(0xc0050008,iVar7,0x10020);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,iVar7);
      }
    }
    else {
      uVar9 = OemStartDevice(puVar4,param_2);
      uVar8 = uVar9 & 0xffffffff;
      if (-1 < (int)uVar9) {
        *puVar4 = *puVar4 | 1;
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1c000a74d:
    *(int *)(param_2 + 0x30) = (int)uVar8;
    IofCompleteRequest(param_2,0);
    goto LAB_1c000a761;
  }
  if (cVar2 == '\x01') {
LAB_1c000a69c:
    if ((*puVar4 & 1) == 0) goto LAB_1c000a5ac;
    *puVar4 = *puVar4 & 0xfffffffe;
    uVar6 = OemStopDevice(puVar4,param_2);
    if (-1 < (int)uVar6) goto LAB_1c000a5ac;
    *(uint *)(param_2 + 0x30) = uVar6;
    IofCompleteRequest(param_2,0);
  }
  else {
    if (cVar2 == '\x02') {
      bVar5 = true;
      goto LAB_1c000a69c;
    }
    if (cVar2 == '\x03') goto LAB_1c000a6d9;
    if (cVar2 == '\x04') goto LAB_1c000a69c;
    if (cVar2 == '\t') {
      uVar8 = SendSyncIrp(*(undefined8 *)(puVar4 + 6),param_2,'\x01');
      iVar7 = (int)uVar8;
      uVar8 = uVar8 & 0xffffffff;
      if (iVar7 < 0) {
        LogError(0xc0050008,iVar7,0x10030);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,iVar7);
        }
      }
      else {
        lVar3 = *(longlong *)(lVar3 + 8);
        if (lVar3 != 0) {
          *(undefined4 *)(lVar3 + 0x2c) = 0;
          *(undefined4 *)(lVar3 + 0x30) = 0;
          *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xffffc3ff | 0x200;
          *(undefined4 *)(lVar3 + 0x14) = 1;
          *(undefined4 *)(lVar3 + 0x18) = 4;
          *(undefined4 *)(lVar3 + 0x1c) = 4;
          *(undefined4 *)(lVar3 + 0x20) = 4;
          *(undefined4 *)(lVar3 + 0x24) = 4;
          *(undefined4 *)(lVar3 + 0x28) = 4;
        }
      }
      goto LAB_1c000a74d;
    }
    if (cVar2 == '\x17') goto LAB_1c000a69c;
LAB_1c000a5ac:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar6 = IofCallDriver(*(undefined8 *)(puVar4 + 6),param_2);
  }
  uVar8 = (ulonglong)uVar6;
  if (bVar5) {
    IoReleaseRemoveLockAndWaitEx(puVar1,param_2,0x20);
    return uVar8;
  }
LAB_1c000a761:
  IoReleaseRemoveLockEx(puVar1,param_2,0x20);
  return uVar8;
}



===== HpenPower @ 1c000a7a0 =====

int HpenPower(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  
  puVar4 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x10);
  puVar1 = puVar4 + 8;
  iVar7 = IoAcquireRemoveLockEx(puVar1,param_2,"",1,0x20);
  if (iVar7 < 0) {
    LogError(0xc0050003,iVar7,0x10040);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,iVar7);
    }
    *(int *)(param_2 + 0x30) = iVar7;
    IofCompleteRequest(param_2,0);
    return iVar7;
  }
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar3 = *(uint *)(lVar5 + 0x18);
  uVar8 = (uint)*(byte *)(lVar5 + 1);
  if (*(byte *)(lVar5 + 1) != 0) {
    if (uVar8 == 2) {
      if ((*(int *)(lVar5 + 0x10) == 1) && (uVar3 != puVar4[0x12])) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,puVar4[0x12],(char)uVar3);
        }
        if (uVar3 != 1) {
          uVar9 = (ulonglong)(uVar3 - 2);
          if (uVar3 - 2 != 0) {
            uVar8 = uVar3 - 3;
            uVar9 = (ulonglong)uVar8;
            if ((uVar8 != 0) && (uVar8 != 1)) goto LAB_1c000a8ad;
          }
          if (((*puVar4 & 1) != 0) &&
             (((iVar7 = SerialAsyncReadWritePort(uVar9,(longlong)puVar4,"+",1), iVar7 < 0 &&
               (LogError(0xc0050107,iVar7,0x50040),
               (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)))) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_afbe72eb3232336aa154f1d6e3b8df8a_Traceguids,iVar7);
          }
          *puVar4 = *puVar4 | 2;
          puVar4[0x12] = uVar3;
          PoSetPowerState(param_1,1,uVar3);
          IoReleaseRemoveLockEx(puVar1,param_2,0x20);
        }
        pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar2 = *pbVar2 | 1;
        puVar6 = *(undefined8 **)(param_2 + 0xb8);
        puVar6[-9] = *puVar6;
        puVar6[-8] = puVar6[1];
        puVar6[-7] = puVar6[2];
        puVar6[-6] = puVar6[3];
        *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
        *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
        *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
        puVar6[-3] = puVar6[6];
        *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar5 + -0x10) = DevicePowerIrpCompletion;
        *(uint **)(lVar5 + -8) = puVar4;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        PoCallDriver(*(undefined8 *)(puVar4 + 6),param_2);
        return 0x103;
      }
    }
    else if (((uVar8 != 3) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_bd76d2327412373a3830dd4f4fe28686_Traceguids,uVar8);
    }
  }
LAB_1c000a8ad:
  pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar2 = *pbVar2 | 1;
  puVar6 = *(undefined8 **)(param_2 + 0xb8);
  puVar6[-9] = *puVar6;
  puVar6[-8] = puVar6[1];
  puVar6[-7] = puVar6[2];
  puVar6[-6] = puVar6[3];
  *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
  *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
  *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
  *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
  puVar6[-3] = puVar6[6];
  *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
  lVar5 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar5 + -0x10) = DevicePowerIrpCompletion;
  *(uint **)(lVar5 + -8) = puVar4;
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  PoCallDriver(*(undefined8 *)(puVar4 + 6),param_2);
  IoReleaseRemoveLockEx(puVar1,param_2,0x20);
  return 0x103;
}



===== SendSyncIrp @ 1c000aac0 =====

ulonglong SendSyncIrp(undefined8 param_1,longlong param_2,char param_3)

{
  char *pcVar1;
  undefined8 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,1,0);
  if (param_3 != '\0') {
    puVar2 = *(undefined8 **)(param_2 + 0xb8);
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
    *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
    *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = IrpCompletion;
  *(undefined8 **)(lVar3 + -8) = &local_28;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  if (*pcVar1 == '\x16') {
    uVar4 = PoCallDriver();
  }
  else {
    uVar4 = IofCallDriver(param_1,param_2);
  }
  if ((int)uVar4 == 0x103) {
    uVar4 = KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  if (-1 < (int)uVar4) {
    uVar4 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar4;
}



===== GetAttributes @ 1c000abc8 =====

undefined8 GetAttributes(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar1 + 8) < 0x20) {
    uVar3 = 0xc0000023;
    LogError(0xc0050005,0xc0000023,0x20090);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,*(undefined4 *)(lVar1 + 8));
    }
  }
  else {
    puVar2 = *(undefined4 **)(param_2 + 0x70);
    uVar3 = 0;
    *puVar2 = 0x20;
    *(undefined2 *)(puVar2 + 1) = 0x5c23;
    *(undefined2 *)((longlong)puVar2 + 6) = *(undefined2 *)(param_1 + 0x90);
    *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(param_1 + 0x9a);
    *(undefined8 *)(param_2 + 0x38) = 0x20;
  }
  return uVar3;
}



===== GetDeviceDescriptor @ 1c000ac74 =====

undefined8 GetDeviceDescriptor(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar1 + 8) < 9) {
    uVar3 = 0xc0000023;
    LogError(0xc0050005,0xc0000023,0x20040);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,*(undefined4 *)(lVar1 + 8));
    }
  }
  else {
    uVar3 = 0;
    puVar2 = *(undefined8 **)(param_2 + 0x70);
    *puVar2 = gHidDescriptor;
    *(undefined1 *)(puVar2 + 1) = DAT_1c00060f8;
    *(undefined8 *)(param_2 + 0x38) = 9;
  }
  return uVar3;
}



===== GetReportDescriptor @ 1c000ad10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 GetReportDescriptor(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = uRam00000001c0006058;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar1 + 8) < 0x9b) {
    uVar4 = 0xc0000023;
    LogError(0xc0050005,0xc0000023,0x20050);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,*(undefined4 *)(lVar1 + 8));
    }
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x70);
    *puVar2 = _gReportDescriptor;
    puVar2[1] = uVar3;
    uVar3 = uRam00000001c0006068;
    puVar2[2] = _DAT_1c0006060;
    puVar2[3] = uVar3;
    uVar3 = uRam00000001c0006078;
    puVar2[4] = _DAT_1c0006070;
    puVar2[5] = uVar3;
    uVar3 = uRam00000001c0006088;
    puVar2[6] = _DAT_1c0006080;
    puVar2[7] = uVar3;
    uVar3 = uRam00000001c0006098;
    puVar2[8] = _DAT_1c0006090;
    puVar2[9] = uVar3;
    uVar3 = uRam00000001c00060a8;
    puVar2[10] = _DAT_1c00060a0;
    puVar2[0xb] = uVar3;
    uVar3 = uRam00000001c00060b8;
    puVar2[0xc] = _DAT_1c00060b0;
    puVar2[0xd] = uVar3;
    uVar3 = uRam00000001c00060c8;
    uVar4 = 0;
    puVar2[0xe] = _DAT_1c00060c0;
    puVar2[0xf] = uVar3;
    uVar3 = uRam00000001c00060d8;
    puVar2[0x10] = _DAT_1c00060d0;
    puVar2[0x11] = uVar3;
    puVar2[0x12] = DAT_1c00060e0;
    *(undefined2 *)(puVar2 + 0x13) = DAT_1c00060e8;
    *(undefined1 *)((longlong)puVar2 + 0x9a) = DAT_1c00060ea;
    *(undefined8 *)(param_2 + 0x38) = 0x9b;
  }
  return uVar4;
}



===== GetString @ 1c000ae10 =====

undefined8 GetString(undefined8 param_1,longlong param_2)

{
  ulonglong _Size;
  longlong lVar1;
  short sVar2;
  longlong lVar3;
  wchar_t *_Src;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  sVar2 = (short)*(undefined4 *)(lVar1 + 0x20);
  if (sVar2 == 0xe) {
    _Src = L"Wacom";
  }
  else if (sVar2 == 0xf) {
    _Src = L"ISD V4";
  }
  else {
    if (sVar2 != 0x10) {
      uVar5 = 0x20070;
      uVar4 = 0xc000000d;
      LogError(0xc0050007,0xc000000d,0x20070);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc000000d;
      }
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uVar5,*(undefined8 *)(lVar1 + 0x20))
      ;
      return 0xc000000d;
    }
    _Src = L"0";
  }
  lVar3 = -1;
  uVar4 = 0;
  do {
    lVar3 = lVar3 + 1;
  } while (_Src[lVar3] != L'\0');
  _Size = lVar3 * 2 + 2;
  if (*(uint *)(lVar1 + 8) < _Size) {
    uVar4 = 0xc0000023;
    LogError(0xc0050005,0xc0000023,0x20080);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_18e4de7f9f983a3baced6352c3bf21a8_Traceguids,*(undefined4 *)(lVar1 + 8),
                (char)_Size);
    }
  }
  else {
    memcpy(*(void **)(param_2 + 0x70),_Src,_Size);
    *(ulonglong *)(param_2 + 0x38) = _Size;
  }
  return uVar4;
}



===== SerialAsyncReadWritePort @ 1c000af48 =====

int SerialAsyncReadWritePort
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined8 local_res10;
  
  local_res10 = 0;
  lVar3 = IoBuildAsynchronousFsdRequest
                    (4,*(undefined8 *)(param_2 + 0x18),param_3,param_4,&local_res10,0);
  if (lVar3 == 0) {
    LogError(0xc0050002,0xc000009a,0x30030);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return -0x3fffff66;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids);
    return -0x3fffff66;
  }
  iVar2 = IoAcquireRemoveLockEx(param_2 + 0x20,lVar3,"",1,0x20);
  if (iVar2 < 0) {
    IoFreeIrp(lVar3);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return iVar2;
    }
    uVar4 = 0xd;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = AsyncReadWriteCompletion;
    *(longlong *)(lVar1 + -8) = param_2;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(*(undefined8 *)(param_2 + 0x18),lVar3);
    if (-1 < iVar2) {
      return iVar2;
    }
    LogError(0xc0050100,iVar2,0x30020);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar2;
    }
    uVar4 = 0xc;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,iVar2);
  return iVar2;
}



===== SerialSyncReadWritePort @ 1c000b0d0 =====

int SerialSyncReadWritePort
              (char param_1,longlong param_2,undefined8 param_3,undefined4 param_4,int *param_5,
              undefined8 *param_6,undefined4 *param_7)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 local_res10;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_res10 = 0xffffffffff676980;
  local_58 = 0;
  local_30 = 0;
  puVar4 = &local_res10;
  if (param_6 != (undefined8 *)0x0) {
    puVar4 = param_6;
  }
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  KeInitializeEvent(&local_40,0,0);
  lVar3 = IoBuildSynchronousFsdRequest
                    (4 - (uint)(param_1 != '\0'),*(undefined8 *)(param_2 + 0x18),param_3,param_4,
                     &local_58,&local_40,&local_50);
  if (lVar3 == 0) {
    LogError(0xc0050002,0xc000009a,0x30050);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return -0x3fffff66;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids);
    return -0x3fffff66;
  }
  lVar1 = *(longlong *)(lVar3 + 0xb8);
  *(code **)(lVar1 + -0x10) = SyncReadWriteCompletion;
  *(int **)(lVar1 + -8) = param_5;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  iVar2 = IofCallDriver(*(undefined8 *)(param_2 + 0x18),lVar3);
  if (iVar2 == 0x103) {
    iVar2 = KeWaitForSingleObject(&local_40,0,0,0,puVar4);
    if (iVar2 != 0x102) {
LAB_1c000b30e:
      if ((int)local_50 < 0) {
        return (int)local_50;
      }
      if (param_7 == (undefined4 *)0x0) {
        return (int)local_50;
      }
      *param_7 = (undefined4)uStack_48;
      return (int)local_50;
    }
    LOCK();
    iVar2 = *param_5;
    *param_5 = 1;
    UNLOCK();
    if (iVar2 == 0) {
      IoCancelIrp(lVar3);
      LOCK();
      iVar2 = *param_5;
      *param_5 = 2;
      UNLOCK();
      if (iVar2 == 3) {
        *param_5 = 0;
        IofCompleteRequest(lVar3,0);
      }
    }
    local_50 = CONCAT44(local_50._4_4_,0x102);
    iVar2 = KeWaitForSingleObject(&local_40,0,0,0,0);
    if (((iVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,iVar2);
    }
    LogError(0xc0050100,iVar2,0x30040);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,(int)local_50);
    }
    iVar2 = -0x3fffff4b;
  }
  else if (iVar2 == 0) goto LAB_1c000b30e;
  LogError(0xc0050100,iVar2,0x30040);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,iVar2);
  }
  return iVar2;
}



===== SerialSyncSendIoctl @ 1c000b38c =====

int SerialSyncSendIoctl(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                       undefined8 param_5,undefined4 param_6,undefined1 param_7,int *param_8)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_28 = 0xffffffffff676980;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  KeInitializeEvent(&local_20,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,&local_20,param_8);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
    LogError(0xc0050002,0xc000009a,0x30010);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids);
    }
  }
  else {
    iVar1 = IofCallDriver(param_2,lVar2);
    if ((iVar1 == 0x103) &&
       (iVar1 = KeWaitForSingleObject(&local_20,0,0,0,&local_28), iVar1 == 0x102)) {
      LogError(0xc0050100,0x102,0x30040);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_50570db803d632cae2314b3ac5f4c1a6_Traceguids,0x102);
      }
      return -0x3fffff4b;
    }
    if (iVar1 == 0) {
      iVar1 = *param_8;
    }
  }
  return iVar1;
}



===== OemStartDevice @ 1c000b53c =====

ulonglong OemStartDevice(uint *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  int local_28 [4];
  
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  uVar2 = *(undefined8 *)(param_2 + 0x38);
  memset((void *)(*(longlong *)(param_2 + 0xb8) + -0x48),0,0x48);
  uVar5 = SendSyncIrp(*(undefined8 *)(param_1 + 6),param_2,'\0');
  iVar3 = (int)uVar5;
  uVar5 = uVar5 & 0xffffffff;
  if (iVar3 < 0) {
    LogError(0xc0050101,iVar3,0x40010);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,iVar3);
    }
  }
  else {
    *param_1 = *param_1 | 0x80000000;
    *(undefined4 *)(param_2 + 0x30) = uVar1;
    *(undefined8 *)(param_2 + 0x38) = uVar2;
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    uVar4 = SerialSyncSendIoctl(0x1b000c,*(undefined8 *)(param_1 + 6),0,0,param_1 + 0x13,0x2c,1,
                                local_28);
    uVar5 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      LogError(0xc0050102,uVar4,0x40008);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,uVar4);
      }
    }
    else {
      *param_1 = *param_1 | 0x40000000;
      uVar4 = OemInitSerialPort((longlong)param_1);
      uVar5 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) goto LAB_1c000b688;
      uVar5 = OemInitDevice((longlong)param_1);
      uVar5 = uVar5 & 0xffffffff;
    }
    if (-1 < (int)uVar5) {
      return uVar5;
    }
  }
LAB_1c000b688:
  OemStopDevice(param_1,param_2);
  return uVar5;
}



===== OemStopDevice @ 1c000b6b4 =====

uint OemStopDevice(uint *param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  int local_18 [4];
  
  bVar2 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  if ((*param_1 >> 0x1e & 1) != 0) {
    *param_1 = *param_1 & 0xbfffffff;
    iVar3 = SerialSyncSendIoctl(0x1b0010,*(undefined8 *)(param_1 + 6),param_1 + 0x13,0x2c,0,0,1,
                                local_18);
    if (iVar3 < 0) {
      bVar2 = 1;
      LogError(0xc0050105,iVar3,0x40020);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,iVar3);
      }
    }
  }
  if ((int)*param_1 < 0) {
    *param_1 = *param_1 & 0x7fffffff;
    lVar1 = *(longlong *)(param_2 + 0xb8);
    memset((void *)(lVar1 + -0x48),0,0x48);
    *(undefined1 *)(lVar1 + -0x48) = 0x12;
    uVar4 = SendSyncIrp(*(undefined8 *)(param_1 + 6),param_2,'\0');
    if ((int)uVar4 < 0) {
      bVar2 = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,(int)uVar4);
      }
    }
    lVar1 = *(longlong *)(param_2 + 0xb8);
    memset((void *)(lVar1 + -0x48),0,0x48);
    *(undefined1 *)(lVar1 + -0x48) = 2;
    uVar4 = SendSyncIrp(*(undefined8 *)(param_1 + 6),param_2,'\0');
    if ((int)uVar4 < 0) {
      bVar2 = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_664a6061b414382e03aa6cdac372c9dc_Traceguids,(int)uVar4);
      }
    }
  }
  return -(uint)bVar2 & 0xc0000001;
}



===== entry @ 1c000c010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
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



===== DriverEntry @ 1c000c078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_68 [48];
  ulonglong local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_1c;
  undefined2 local_1b;
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  _DAT_1c00061a8 = 1;
  _WPP_MAIN_CB = 0;
  local_38 = (ulonglong)(uint)local_38;
  DAT_1c0006190 = 0;
  DAT_1c0006188 = &WPP_ThisDir_CTLGUID_ControlGuid;
  _DAT_1c00061a0 = 0;
  WppLoadTracingSupport();
  _DAT_1c00061a0 = 0;
  WppInitKm();
  gDriverObj = param_1;
  *(code **)(param_1 + 0x80) = HpenCreateClose;
  *(code **)(param_1 + 0x70) = HpenCreateClose;
  *(code **)(param_1 + 0x128) = HpenSystemControl;
  *(code **)(param_1 + 0xe8) = HpenInternalIoctl;
  *(code **)(param_1 + 0x148) = HpenPnp;
  *(code **)(param_1 + 0x120) = HpenPower;
  *(code **)(param_1 + 0x68) = HpenUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = HpenAddDevice;
  local_38 = 1;
  local_1b = 0;
  local_19 = 0;
  local_20 = 0xa8;
  local_1c = 0;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = HidRegisterMinidriver(&local_38);
  if (iVar1 < 0) {
    LogError(0xc005000d,iVar1,0x10);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_182eb78e368b3f9b76e3669171cfc15a_Traceguids,iVar1);
    }
  }
  return iVar1;
}


