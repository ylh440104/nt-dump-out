
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __cpu_features_init @ 140001030 =====

/* WARNING: Removing unreachable block (ram,0x00014000109a) */
/* WARNING: Removing unreachable block (ram,0x000140001049) */
/* WARNING: Removing unreachable block (ram,0x00014000103a) */

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



===== BmAllocateCommonBuffer @ 140001100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmAllocateCommonBuffer(longlong param_1)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x10))();
  return;
}



===== BmBuildMdlFromScatterGatherList @ 140001130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmBuildMdlFromScatterGatherList(longlong param_1,longlong param_2)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x78))
            (*(longlong *)(param_1 + 0xe8),*(undefined8 *)(param_2 + 0x3e0),
             *(undefined8 *)(param_2 + 0x88),param_2 + 0x90);
  return;
}



===== BmFlush @ 140001170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmFlush(longlong param_1,longlong param_2,char param_3)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x60))
            (*(longlong *)(param_1 + 0xe8),*(undefined8 *)(param_2 + 0x3e0),param_3 == '\0');
  *(undefined8 *)(param_2 + 0x3e0) = 0;
  *(undefined8 *)(param_2 + 0x90) = 0;
  return;
}



===== BmFreeCommonBuffer @ 1400011c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmFreeCommonBuffer(longlong param_1)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x18))();
  return;
}



===== BmGetDmaAdapterObject @ 1400011f0 =====

undefined8 BmGetDmaAdapterObject(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0xe8);
}



===== BmReceiveScatterGatherList @ 140001200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmReceiveScatterGatherList
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(param_4 + 0x3e0) = param_3;
  (**(code **)(lVar1 + 0xf8))(param_4);
  return;
}



===== BmSetup @ 140001230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BmSetup(longlong param_1,longlong param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x70))
                    (*(longlong *)(param_1 + 0xe8),*(undefined8 *)(param_1 + 0x18),
                     *(undefined8 *)(param_2 + 0x88),*(undefined8 *)(param_2 + 0x70),
                     *(undefined4 *)(param_2 + 0x400),BmReceiveScatterGatherList,param_2,param_3,
                     param_2 + 0xa0,0x340);
  if (iVar1 < 0) {
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 0x58))
              (*(longlong *)(param_1 + 0xe8),*(undefined8 *)(param_1 + 0x18),
               *(undefined8 *)(param_2 + 0x88),*(undefined8 *)(param_2 + 0x70),
               *(undefined4 *)(param_2 + 0x400),BmReceiveScatterGatherList,param_2,param_3);
  }
  return;
}



===== BusMasterUninitialize @ 140001300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BusMasterUninitialize(longlong param_1)

{
  undefined1 uVar1;
  
  if (*(longlong *)(param_1 + 0xe8) != 0) {
    uVar1 = KfRaiseIrql(2);
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 8) + 8))();
    KeLowerIrql(uVar1);
    *(undefined8 *)(param_1 + 0xe8) = 0;
    *(undefined4 *)(param_1 + 0xf0) = 1;
  }
  return 0;
}



===== AtaPortAllocateQueueTag @ 140001370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortAllocateQueueTag(longlong param_1,undefined1 param_2,undefined1 param_3)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong lStack_40;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1370  1  AtaPortAllocateQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 9;
  local_38 = (ulonglong)CONCAT11(param_2,param_3);
  lStack_40 = param_1;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortBuildRequestSenseIrb @ 1400013d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortBuildRequestSenseIrb(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x13d0  2  AtaPortBuildRequestSenseIrb */
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 7;
  uStack_30 = 1;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortCompleteAllActiveRequests @ 140001430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortCompleteAllActiveRequests
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1430  3  AtaPortCompleteAllActiveRequests */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 1;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortCompleteRequest @ 140001490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortCompleteRequest(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1490  4  AtaPortCompleteRequest */
  local_48 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortConvertPhysicalAddressToUlong @ 1400014e0 =====

undefined4 AtaPortConvertPhysicalAddressToUlong(undefined4 param_1)

{
                    /* 0x14e0  5  AtaPortConvertPhysicalAddressToUlong */
  return param_1;
}



===== AtaPortConvertUlongToPhysicalAddress @ 1400014f0 =====

undefined8 AtaPortConvertUlongToPhysicalAddress(undefined8 param_1)

{
                    /* 0x14f0  6  AtaPortConvertUlongToPhysicalAddress */
  return param_1;
}



===== AtaPortCopyMemory @ 140001500 =====

void AtaPortCopyMemory(void *param_1,void *param_2,uint param_3)

{
                    /* 0x1500  7  AtaPortCopyMemory
                       0x1500  20  AtaPortMoveMemory */
  memcpy(param_1,param_2,(ulonglong)param_3);
  return;
}



===== AtaPortDebugBreak @ 140001520 =====

void AtaPortDebugBreak(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AtaPortDebugPrint @ 140001530 =====

void AtaPortDebugPrint(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
                    /* 0x1530  9  AtaPortDebugPrint
                       0x1530  60  PciIdeXDebugPrint */
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if ((param_1 == 1) || (param_1 == 2)) {
    param_1 = 2;
  }
  else if (param_1 == 3) {
  }
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintExWithPrefix("AtaMini: ",0x39,param_1,param_2,&local_res18);
  return;
}



===== AtaPortDeviceStateChange @ 1400015a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortDeviceStateChange
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  uint local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x15a0  10  AtaPortDeviceStateChange */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 3;
  _local_38 = CONCAT44(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortEtwTraceLog @ 140001600 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AtaPortEtwTraceLog(int param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  char cVar3;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  longlong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
                    /* 0x1600  11  AtaPortEtwTraceLog */
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  uStack_20 = 0;
  if (AtaEtwEnabled == '\0') {
    return;
  }
  if (param_1 == 1) {
    puVar2 = &ATAPORT_EVENT_LPM_POWERSTATE_PARTIAL;
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 3) {
        puVar2 = &ATAPORT_EVENT_CHANNEL_START_INIT;
      }
      else {
        if (param_1 != 4) {
          if (param_1 == 5) {
            puVar2 = &ATAPORT_EVENT_CHANNEL_RESET_INIT;
          }
          else {
            if (param_1 != 6) {
              puVar2 = (undefined *)0x0;
              uVar1 = 0;
              goto LAB_140001695;
            }
            puVar2 = &ATAPORT_EVENT_CHANNEL_RESET_COMPLETE;
          }
          uVar1 = 8;
          goto LAB_140001695;
        }
        puVar2 = &ATAPORT_EVENT_CHANNEL_START_COMPLETE;
      }
      uVar1 = 2;
      goto LAB_140001695;
    }
    puVar2 = &ATAPORT_EVENT_LPM_POWERSTATE_SLUMBER;
  }
  uVar1 = 0x20;
LAB_140001695:
  if ((_AtaMatchAnyKeyword & uVar1) != 0) {
    if ((param_2 == 0) || (param_3 == 0)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
      uStack_20 = (ulonglong)param_3;
      local_28 = param_2;
    }
    if (puVar2 != (undefined *)0x0) {
      local_38 = -(ulonglong)(cVar3 != '\0') & (ulonglong)&local_28;
      EtwWrite(AtaEtwHandle,puVar2,0,cVar3);
    }
  }
  return;
}



===== AtaPortGetDeviceBase @ 140001710 =====

undefined8 AtaPortGetDeviceBase(undefined8 param_1,undefined8 param_2)

{
                    /* 0x1710  13  AtaPortGetDeviceBase */
  return param_2;
}



===== AtaPortGetPhysicalAddress @ 140001720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AtaPortGetPhysicalAddress(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  
                    /* 0x1720  14  AtaPortGetPhysicalAddress */
  local_48 = 0xc;
  local_20 = 0;
  local_18 = 0;
  local_40 = param_1;
  local_38 = param_2;
  local_30 = param_3;
  local_28 = param_4;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortGetScatterGatherList @ 140001770 =====

undefined8 AtaPortGetScatterGatherList(undefined8 param_1,longlong param_2)

{
                    /* 0x1770  15  AtaPortGetScatterGatherList */
  return *(undefined8 *)(param_2 + -8);
}



===== AtaPortGetUnCachedExtension @ 140001780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortGetUnCachedExtension(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1780  16  AtaPortGetUnCachedExtension */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 5;
  local_38 = CONCAT44(param_3,param_2);
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortInitializeQueueTag @ 1400017e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortInitializeQueueTag
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x17e0  18  AtaPortInitializeQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 8;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortLogError @ 140001840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortLogError(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1840  19  AtaPortLogError */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 6;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortNotification @ 140001890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortNotification(uint param_1,longlong param_2,undefined1 param_3,undefined1 param_4,
                        uint param_5)

{
  undefined8 local_40;
  longlong lStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined4 local_10;
  
                    /* 0x1890  21  AtaPortNotification */
  local_10 = 0;
  local_40 = 4;
  uStack_28 = 0;
  local_30 = (ulonglong)param_1;
  local_20 = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_1 == 1)) {
    local_30._0_5_ = CONCAT14(param_4,param_1);
    local_30 = (ulonglong)CONCAT15(param_3,(undefined5)local_30);
  }
  else if (param_1 == 2) {
    local_30._0_5_ = CONCAT14(param_4,2);
    local_30 = (ulonglong)CONCAT15(param_3,(undefined5)local_30);
    uStack_28 = (ulonglong)param_5;
  }
  lStack_38 = param_2;
  (**(code **)(param_2 + -8))((undefined8 *)(param_2 + -8),&local_40);
  return;
}



===== AtaPortQuerySystemTime @ 140001930 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AtaPortQuerySystemTime(undefined8 *param_1)

{
                    /* 0x1930  22  AtaPortQuerySystemTime */
  *param_1 = _DAT_fffff78000000014;
  return;
}



===== AtaPortReadPortBufferUchar @ 140001950 =====

void AtaPortReadPortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
                    /* 0x1950  23  AtaPortReadPortBufferUchar */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortBufferUlong @ 140001970 =====

void AtaPortReadPortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
                    /* 0x1970  24  AtaPortReadPortBufferUlong */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortBufferUshort @ 140001990 =====

void AtaPortReadPortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
                    /* 0x1990  25  AtaPortReadPortBufferUshort */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortUchar @ 1400019b0 =====

undefined1 AtaPortReadPortUchar(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadPortUlong @ 1400019c0 =====

undefined4 AtaPortReadPortUlong(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadPortUshort @ 1400019d0 =====

undefined2 AtaPortReadPortUshort(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadRegisterBufferUchar @ 1400019f0 =====

void AtaPortReadRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x19f0  29  AtaPortReadRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterBufferUlong @ 140001a20 =====

void AtaPortReadRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1a20  30  AtaPortReadRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterBufferUshort @ 140001a50 =====

void AtaPortReadRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1a50  31  AtaPortReadRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterUchar @ 140001a80 =====

undefined1 AtaPortReadRegisterUchar(undefined1 *param_1)

{
  return *param_1;
}



===== AtaPortReadRegisterUlong @ 140001a90 =====

undefined4 AtaPortReadRegisterUlong(undefined4 *param_1)

{
  return *param_1;
}



===== AtaPortReadRegisterUshort @ 140001aa0 =====

undefined2 AtaPortReadRegisterUshort(undefined2 *param_1)

{
  return *param_1;
}



===== AtaPortRegistryAllocateBuffer @ 140001ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortRegistryAllocateBuffer(longlong param_1,uint param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined4 local_18;
  
                    /* 0x1ab0  35  AtaPortRegistryAllocateBuffer */
  uStack_30 = 0;
  local_38 = 0;
  local_28 = 0;
  local_18 = 0;
  uStack_20 = (ulonglong)param_2;
  local_48 = 0xb;
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortRegistryFreeBuffer @ 140001b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortRegistryFreeBuffer(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1b10  36  AtaPortRegistryFreeBuffer */
  uStack_20 = 0;
  local_18 = 0;
  uStack_30 = 0;
  local_48 = 0xb;
  local_38 = 1;
  lStack_40 = param_1;
  local_28 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortRegistryRead @ 140001b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryRead(longlong param_1,undefined1 param_2,undefined1 param_3,
                             undefined8 param_4,undefined1 param_5,undefined8 param_6,
                             undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x1b70  37  AtaPortRegistryRead */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 2;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortRegistryWrite @ 140001be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryWrite
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                    undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x1be0  38  AtaPortRegistryWrite */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 3;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortRegistryWriteDeferred @ 140001c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryWriteDeferred
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                    undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x1c50  39  AtaPortRegistryWriteDeferred */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 4;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortReleaseQueueTag @ 140001cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortReleaseQueueTag
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1cc0  40  AtaPortReleaseQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 10;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortReleaseRequestSenseIrb @ 140001d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortReleaseRequestSenseIrb(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x1d20  41  AtaPortReleaseRequestSenseIrb */
  local_18 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 7;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortRequestCallback @ 140001d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
AtaPortRequestCallback(undefined4 param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_48;
  longlong local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  
                    /* 0x1d70  42  AtaPortRequestCallback */
  local_34 = 0;
  local_48 = 2;
  local_24 = 0;
  uStack_1c = 0;
  local_40 = param_2;
  local_38 = param_1;
  local_30 = param_3;
  local_28 = param_4;
  (**(code **)(param_2 + -8))((undefined8 *)(param_2 + -8),&local_48);
  return (undefined1)local_38;
}



===== AtaPortStallExecution @ 140001dc0 =====

void AtaPortStallExecution(void)

{
                    /* 0x1dc0  44  AtaPortStallExecution */
  KeStallExecutionProcessor();
  return;
}



===== AtaPortTraceNotification @ 140001de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortTraceNotification
                    (undefined8 param_1,undefined8 param_2,uint param_3,longlong *param_4)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  
                    /* 0x1de0  45  AtaPortTraceNotification */
  lVar6 = 0;
  if (param_3 < 0x7d4) {
    if (param_3 == 0x7d3) {
      uVar5 = WmiQueryTraceInformation
                        ((int)*param_4,param_4[1],(int)param_4[2],param_4[3],param_4[4]);
    }
    else {
      if (param_3 == 1000) {
        uVar5 = PortTraceInitTracing(param_4);
        return uVar5;
      }
      if (param_3 == 0x3e9) {
        lVar6 = *param_4;
        PortTraceErrorFreeDriver(lVar6);
        if (*(code **)(lVar6 + 0x10) != (code *)0x0) {
          (**(code **)(lVar6 + 0x10))(*(undefined8 *)(lVar6 + 8));
        }
        uVar5 = ExFreePoolWithTag(lVar6,0);
        return uVar5;
      }
      if (param_3 != 2000) {
        uVar4 = param_3 - 0x7d1;
        if (uVar4 == 0) {
          uVar5 = PortTraceInitGlobalLogger(param_4);
          return uVar5;
        }
        if (uVar4 == 1) {
          uVar5 = IoWMIRegistrationControl(*param_4,(int)param_4[1]);
          *(int *)((longlong)param_4 + 0xc) = (int)uVar5;
          return uVar5;
        }
        return (ulonglong)uVar4;
      }
      uVar5 = WmiTraceMessageVa(*param_4,(int)param_4[1],param_4[2],(short)param_4[3],param_4[4]);
    }
    *(int *)(param_4 + 5) = (int)uVar5;
    return uVar5;
  }
  if (param_3 == 0x7d4) {
    uVar5 = RtlInitUnicodeString(*param_4,param_4[1]);
    return uVar5;
  }
  if (param_3 == 4000) {
    lVar6 = *param_4;
    ExpInterlockedPushEntrySList(lVar6 + 0x40,param_4[1] + -0x20);
    bVar3 = KeGetCurrentIrql();
    if (bVar3 < 3) {
      uVar5 = PortTraceErrorDrainList(*(undefined8 *)(lVar6 + 8),lVar6 + 0x40);
      return uVar5;
    }
    LOCK();
    *(int *)(lVar6 + 0x54) = *(int *)(lVar6 + 0x54) + 1;
    UNLOCK();
    uVar5 = KeInsertQueueDpc(lVar6 + 0x58,0,0);
    return uVar5;
  }
  uVar4 = param_3 - 0xfa1;
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      uVar5 = param_4[1];
      LOCK();
      *(undefined4 *)(uVar5 - 0x10) = 0;
      UNLOCK();
      return uVar5;
    }
    return (ulonglong)uVar4;
  }
  uVar4 = *(uint *)(param_4 + 1);
  lVar1 = *param_4;
  uVar5 = 0;
  if ((uVar4 < 0xf1) && (uVar8 = 0, *(int *)(lVar1 + 0x50) != 0)) {
    do {
      uVar5 = *(ulonglong *)(lVar1 + 0x38);
      lVar2 = *(longlong *)(uVar5 + uVar8 * 8);
      if (*(int *)(lVar2 + 0x10) == 0) {
        uVar5 = 0;
        LOCK();
        uVar7 = *(uint *)(lVar2 + 0x10);
        if (uVar7 == 0) {
          *(uint *)(lVar2 + 0x10) = 1;
        }
        else {
          uVar5 = (ulonglong)uVar7;
        }
        UNLOCK();
        if (uVar7 == 0) {
          *(uint *)(lVar2 + 0x14) = uVar4;
          lVar6 = lVar2 + 0x20;
          break;
        }
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(lVar1 + 0x50));
  }
  param_4[2] = lVar6;
  return uVar5;
}



===== AtaPortWritePortBufferUchar @ 140002000 =====

void AtaPortWritePortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x2000  46  AtaPortWritePortBufferUchar */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortBufferUlong @ 140002020 =====

void AtaPortWritePortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x2020  47  AtaPortWritePortBufferUlong */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortBufferUshort @ 140002040 =====

void AtaPortWritePortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x2040  48  AtaPortWritePortBufferUshort */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortUchar @ 140002060 =====

undefined1 AtaPortWritePortUchar(undefined2 param_1,undefined1 param_2)

{
                    /* 0x2060  49  AtaPortWritePortUchar */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWritePortUlong @ 140002070 =====

undefined4 AtaPortWritePortUlong(undefined2 param_1,undefined4 param_2)

{
                    /* 0x2070  50  AtaPortWritePortUlong */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWritePortUshort @ 140002080 =====

undefined2 AtaPortWritePortUshort(undefined2 param_1,undefined2 param_2)

{
                    /* 0x2080  51  AtaPortWritePortUshort */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWriteRegisterBufferUchar @ 1400020a0 =====

void AtaPortWriteRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x20a0  52  AtaPortWriteRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterBufferUlong @ 1400020d0 =====

void AtaPortWriteRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x20d0  53  AtaPortWriteRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterBufferUshort @ 140002100 =====

void AtaPortWriteRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x2100  54  AtaPortWriteRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUchar @ 140002130 =====

void AtaPortWriteRegisterUchar(undefined1 *param_1,undefined1 param_2)

{
                    /* 0x2130  55  AtaPortWriteRegisterUchar */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUlong @ 140002140 =====

void AtaPortWriteRegisterUlong(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x2140  56  AtaPortWriteRegisterUlong */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUshort @ 140002150 =====

void AtaPortWriteRegisterUshort(undefined2 *param_1,undefined2 param_2)

{
                    /* 0x2150  57  AtaPortWriteRegisterUshort */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== FdoChildRequestPowerUpCompletionRoutine @ 140002160 =====

void FdoChildRequestPowerUpCompletionRoutine(void)

{
  longlong lVar1;
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  lVar1 = *(longlong *)(*(longlong *)(in_R9 + 0xb8) + 0x28);
  *(undefined4 *)(in_R9 + 0x30) = *in_stack_00000028;
  PdoCompleteDevicePowerIrp(lVar1,in_R9);
  return;
}



===== FdoDevicePowerCompletion @ 140002190 =====

undefined4
FdoDevicePowerCompletion(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 in_stack_ffffffffffffffe8;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    PoStartNextPowerIrp(param_2);
    uVar4 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x40);
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (*(int *)(lVar3 + 0x50) != 1) {
      PoSetPowerState(param_1,1,iVar1);
    }
    iVar2 = *(int *)(lVar3 + 0x50);
    *(int *)(lVar3 + 0x50) = iVar1;
    FdoProcessDevicePowerChange(param_1,iVar1,iVar2,param_4,in_stack_ffffffffffffffe8,param_2);
    uVar4 = 0xc0000016;
  }
  return uVar4;
}



===== FdoIssueSetPowerCompletion @ 140002230 =====

void FdoIssueSetPowerCompletion(void)

{
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  *(undefined4 *)(in_R9 + 0x18) = *in_stack_00000028;
  KeSetEvent();
  return;
}



===== FdoPowerUpDevice @ 140002264 =====

int FdoPowerUpDevice(undefined8 param_1)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  KeInitializeEvent(&local_28,0,0);
  iVar1 = GenPowerRequestSetPowerIrp(param_1,1,FdoIssueSetPowerCompletion,&local_28);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar1 = (int)uStack_10;
  }
  return iVar1;
}



===== FdoQueryPowerState @ 1400022e0 =====

void FdoQueryPowerState(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(undefined4 *)(param_2 + 0x30) = 0;
  PoStartNextPowerIrp(param_2);
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
  PoCallDriver(*puVar1,param_2);
  return;
}



===== FdoSetDevicePowerState @ 140002354 =====

undefined8 FdoSetDevicePowerState(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  pbVar1 = (byte *)(lVar2 + 3);
  *pbVar1 = *pbVar1 | 1;
  if (((byte)*(ushort *)(puVar4 + 0x1b) & 0x11) == 0x11) {
    puVar4 = *(undefined8 **)(param_1 + 0x40);
  }
  else if (((*(ushort *)(puVar4 + 0x1b) & 1) != 0) &&
          (*(int *)(puVar4 + 10) != *(int *)(lVar2 + 0x18))) {
    if (*(int *)(puVar4 + 10) == 1) {
      PoSetPowerState(param_1,1);
    }
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
    *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
    *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
    *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar2 + -8) = 0;
    *(code **)(lVar2 + -0x10) = FdoDevicePowerCompletion;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    goto LAB_1400023a1;
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_1400023a1:
  PoCallDriver(*puVar4,param_2);
  return 0x103;
}



===== FdoSetPowerState @ 140002440 =====

undefined4 FdoSetPowerState(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (iVar1 == 0) {
    uVar3 = FdoSetSystemPowerState(param_1,param_2);
    uVar2 = (undefined4)uVar3;
  }
  else {
    if (iVar1 != 1) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
      return 0xc0000002;
    }
    uVar3 = FdoSetDevicePowerState(param_1,param_2);
    uVar2 = (undefined4)uVar3;
  }
  return uVar2;
}



===== FdoSetSystemPowerState @ 1400024b8 =====

undefined8 FdoSetSystemPowerState(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  if ((*(ushort *)(puVar3 + 0x1b) & 1) != 0) {
    iVar1 = *(int *)(lVar5 + 0x18);
    if (*(int *)((longlong)puVar3 + 0x4c) != iVar1) {
      if (*(int *)((longlong)puVar3 + 0x4c) == 1) {
        iVar2 = *(int *)(lVar5 + 0x20);
        if (iVar2 == 5) {
          *(ushort *)(puVar3 + 0x1b) = *(ushort *)(puVar3 + 0x1b) | 0x10;
          lVar5 = *(longlong *)(param_2 + 0xb8);
        }
        if (iVar1 == 1) {
          uVar7 = 1;
        }
        else if ((iVar1 != 6) || (uVar7 = 1, iVar2 != 5)) {
          uVar7 = 4;
        }
        *(byte *)(lVar5 + 3) = *(byte *)(lVar5 + 3) | 1;
        GenPowerRequestSetPowerIrp(param_1,uVar7,FdoSystemPowerDownCompletion,param_2);
      }
      else {
        *(byte *)(lVar5 + 3) = *(byte *)(lVar5 + 3) | 1;
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(undefined8 *)(lVar5 + -8) = 0;
        *(code **)(lVar5 + -0x10) = FdoSystemPowerCompletion;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        PoCallDriver(*puVar3,param_2);
      }
      return 0x103;
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar6 = PoCallDriver(*puVar3,param_2);
  return uVar6;
}



===== FdoSystemPowerCompletion @ 1400025f0 =====

undefined4 FdoSystemPowerCompletion(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < *(int *)(param_2 + 0x30)) {
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    *(int *)(*(longlong *)(param_1 + 0x40) + 0x4c) = iVar1;
    if (iVar1 == 1) {
      GenPowerRequestSetPowerIrp(param_1,1,(undefined *)0x0,0);
    }
    PoSetPowerState(param_1,0,iVar1);
  }
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  PoStartNextPowerIrp(param_2);
  return uVar2;
}



===== FdoSystemPowerDownCompletion @ 140002670 =====

void FdoSystemPowerDownCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,int *param_5
               )

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (*param_5 < 0) {
    *(undefined8 *)(param_4 + 0x38) = 0;
    *(int *)(param_4 + 0x30) = *param_5;
    PoStartNextPowerIrp(param_4);
    IofCompleteRequest(param_4,0);
  }
  else {
    puVar2 = *(undefined8 **)(param_4 + 0xb8);
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
    lVar3 = *(longlong *)(param_4 + 0xb8);
    *(code **)(lVar3 + -0x10) = FdoSystemPowerCompletion;
    *(longlong *)(lVar3 + -8) = param_4;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    PoCallDriver(*puVar1,param_4);
  }
  return;
}



===== GenPnpAddDeviceToGlobalList @ 140002718 =====

void GenPnpAddDeviceToGlobalList(longlong param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&GlobalDeviceList);
  puVar6 = auStack_28;
  puVar4 = &DAT_140007108;
  puVar5 = (undefined8 *)(param_1 + 0xa0);
  puVar3 = DAT_140007110;
  if ((undefined *)*DAT_140007110 != &DAT_140007108) {
    puVar3 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar6 = auStack_20;
  }
  *puVar5 = puVar4;
  *(undefined8 **)(param_1 + 0xa8) = puVar3;
  *puVar3 = puVar5;
  *(undefined8 *)(puVar6 + -8) = 0x140002776;
  DAT_140007110 = puVar5;
  KeReleaseSpinLock(&GlobalDeviceList,uVar2);
  return;
}



===== GenPnpRefNextPdoExtensionWithTag @ 140002788 =====

longlong GenPnpRefNextPdoExtensionWithTag(longlong param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  ulonglong uVar8;
  uint uVar9;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x98);
  do {
    uVar1 = *param_2;
    lVar6 = 0;
    uVar9 = 0xffffffff;
    uVar8 = 0;
    do {
      for (lVar5 = *(longlong *)(param_1 + 0x58 + uVar8 * 8); lVar5 != 0;
          lVar5 = *(longlong *)(lVar5 + 0x98)) {
        uVar2 = *(uint *)(lVar5 + 0x54);
        if (((uVar1 <= uVar2) && (uVar2 < uVar9)) && (lVar6 = lVar5, uVar9 = uVar2, uVar2 == uVar1))
        goto LAB_140002809;
      }
      lVar5 = lVar6;
    } while ((uVar9 != uVar1) && (bVar7 = (char)uVar8 + 1, uVar8 = (ulonglong)bVar7, bVar7 < 8));
LAB_140002809:
    if (lVar5 == 0) break;
    *param_2 = *(int *)(lVar5 + 0x54) + 1;
    iVar4 = IoAcquireRemoveLockEx(lVar5 + 0xb0,param_3,"",1,0x20);
  } while (iVar4 < 0);
  KeReleaseSpinLock(param_1 + 0x98,uVar3);
  return lVar5;
}



===== GenPnpRefPdoExtensionWithTag @ 140002884 =====

longlong GenPnpRefPdoExtensionWithTag(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x98);
  lVar3 = *(longlong *)
           (param_1 + 0x58 + (ulonglong)((byte)((char)(param_2 >> 6) + (char)param_2) & 7) * 8);
  do {
    if (lVar3 == 0) {
LAB_14000291e:
      KeReleaseSpinLock(param_1 + 0x98,uVar1);
      return lVar3;
    }
    if (*(int *)(lVar3 + 0x54) == (int)param_2) {
      iVar2 = IoAcquireRemoveLockEx(lVar3 + 0xb0,ControllerQueryBusRelations,"",1,0x20);
      if (iVar2 < 0) {
        lVar3 = 0;
      }
      goto LAB_14000291e;
    }
    lVar3 = *(longlong *)(lVar3 + 0x98);
  } while( true );
}



===== GenPnpRemoveDeviceFromGlobalList @ 140002958 =====

void GenPnpRemoveDeviceFromGlobalList(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&GlobalDeviceList);
  plVar5 = (longlong *)(param_1 + 0xa0);
  lVar1 = *plVar5;
  if ((*(longlong **)(lVar1 + 8) == plVar5) &&
     (plVar2 = *(longlong **)(param_1 + 0xa8), (longlong *)*plVar2 == plVar5)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseSpinLock(&GlobalDeviceList,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4));
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== GenPnpUnRefPdoExtensionWithTag @ 1400029c0 =====

void GenPnpUnRefPdoExtensionWithTag(longlong param_1,undefined8 param_2)

{
  IoReleaseRemoveLockEx(param_1 + 0xb0,param_2,0x20);
  return;
}



===== GenPowerRequestSetPowerIrp @ 1400029ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GenPowerRequestSetPowerIrp
              (undefined8 param_1,undefined4 param_2,undefined *param_3,undefined8 param_4)

{
  int iVar1;
  int local_18 [4];
  
  iVar1 = PoRequestPowerIrp(param_1,2,param_2,param_3,param_4,0);
  if ((iVar1 < 0) && (param_3 != (undefined *)0x0)) {
    local_18[1] = 0;
    local_18[2] = 0;
    local_18[3] = 0;
    local_18[0] = iVar1;
    (*(code *)param_3)(param_1,2,param_2,param_4,local_18);
  }
  return iVar1;
}



===== InsertPdoExtension @ 140002a88 =====

void InsertPdoExtension(longlong param_1,longlong param_2,ulonglong param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x98);
  IoAcquireRemoveLockEx(param_2 + 0xb0,param_2,"",1,0x20);
  uVar2 = (ulonglong)((byte)((char)(param_3 >> 6) + (char)param_3) & 7);
  *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_1 + 0x58 + uVar2 * 8);
  *(longlong *)(param_1 + 0x58 + uVar2 * 8) = param_2;
  *(longlong *)(param_2 + 0x58) = param_1;
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  KeReleaseSpinLock(param_1 + 0x98,uVar1);
  return;
}



===== PdoCompleteDevicePowerIrp @ 140002b48 =====

void PdoCompleteDevicePowerIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(longlong *)(param_2 + 0x38) = (longlong)iVar1;
  if (*(int *)(lVar2 + 0x50) == iVar1) {
    PoStartNextPowerIrp();
    IofCompleteRequest(param_2,0);
  }
  else {
    PdoCompleteDevicePowerIrpCallback(param_2,*(int *)(param_2 + 0x30));
  }
  return;
}



===== PdoCompleteDevicePowerIrpCallback @ 140002ba4 =====

void PdoCompleteDevicePowerIrpCallback(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x28) + 0x40);
  *(int *)(param_1 + 0x30) = param_2;
  if (-1 < param_2) {
    iVar3 = *(int *)(param_1 + 0x38);
    if (*(int *)(lVar4 + 0x50) != 1) {
      PoSetPowerState();
    }
    if (iVar3 == 4) {
      lVar5 = *(longlong *)(lVar4 + 0x58);
      LOCK();
      piVar1 = (int *)(lVar5 + 0xd4);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        GenPowerRequestSetPowerIrp(*(undefined8 *)(lVar5 + 0x18),4,(undefined *)0x0,0);
      }
    }
    *(int *)(lVar4 + 0x50) = iVar3;
  }
  PoStartNextPowerIrp(param_1);
  IofCompleteRequest(param_1,0);
  return;
}



===== PdoCompleteSystemPowerIrp @ 140002c50 =====

void PdoCompleteSystemPowerIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(longlong *)(param_2 + 0x38) = (longlong)iVar1;
  if (*(int *)(lVar2 + 0x4c) != iVar1) {
    *(int *)(lVar2 + 0x4c) = iVar1;
    PoSetPowerState(param_1,0);
  }
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  return;
}



===== PdoQueryPowerState @ 140002cc0 =====

undefined8 PdoQueryPowerState(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PdoSetDevicePowerState @ 140002cfc =====

undefined8 PdoSetDevicePowerState(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (((*(byte *)(lVar1 + 0xd8) & 1) == 0) ||
     (*(int *)(lVar1 + 0x50) == *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18))) {
    return 0;
  }
  if (*(int *)(lVar1 + 0x50) == 1) {
    PoSetPowerState(param_1,1);
  }
  if (*(int *)(lVar1 + 0x50) == 4) {
    lVar1 = *(longlong *)(lVar1 + 0x58);
    LOCK();
    *(int *)(lVar1 + 0xd4) = *(int *)(lVar1 + 0xd4) + 1;
    UNLOCK();
    if (*(int *)(lVar1 + 0x50) != 1) {
      GenPowerRequestSetPowerIrp
                (*(undefined8 *)(lVar1 + 0x18),1,FdoChildRequestPowerUpCompletionRoutine,param_2);
      return 0x103;
    }
    param_1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x28);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  PdoCompleteDevicePowerIrp(param_1,param_2);
  return 0x103;
}



===== PdoSetPowerState @ 140002dc0 =====

undefined8 PdoSetPowerState(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pbVar1 = (byte *)(lVar2 + 3);
  *pbVar1 = *pbVar1 | 1;
  iVar3 = *(int *)(lVar2 + 0x10);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else if (iVar3 == 1) {
    uVar4 = PdoSetDevicePowerState(param_1,param_2);
    iVar3 = (int)uVar4;
    if (iVar3 == 0x103) {
      return 0x103;
    }
  }
  else {
    iVar3 = -0x3ffffffe;
  }
  *(int *)(param_2 + 0x30) = iVar3;
  iVar3 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (iVar3 == 0) {
    PdoCompleteSystemPowerIrp(param_1,param_2);
  }
  else if (iVar3 == 1) {
    PdoCompleteDevicePowerIrp(param_1,param_2);
  }
  else {
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  return 0x103;
}



===== RemovePdoExtension @ 140002e68 =====

void RemovePdoExtension(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  uVar3 = *(uint *)(param_2 + 0x54);
  lVar1 = param_1 + 0x98;
  cVar2 = *(char *)(param_2 + 0x54);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar8 = (ulonglong)((char)(uVar3 >> 6) + cVar2 & 7);
  lVar6 = *(longlong *)(param_1 + 0x58 + uVar8 * 8);
  lVar7 = 0;
  if (lVar6 != 0) {
    do {
      lVar5 = lVar6;
      lVar6 = lVar5;
      if (*(int *)(lVar5 + 0x54) == *(int *)(param_2 + 0x54)) break;
      lVar6 = *(longlong *)(lVar5 + 0x98);
      lVar7 = lVar5;
    } while (lVar6 != 0);
  }
  KeReleaseSpinLock(lVar1,uVar4);
  if (lVar6 != 0) {
    IoReleaseRemoveLockAndWaitEx(lVar6 + 0xb0,lVar6,0x20);
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (lVar7 == 0) {
      *(undefined8 *)(param_1 + 0x58 + uVar8 * 8) = *(undefined8 *)(lVar6 + 0x98);
    }
    else {
      *(undefined8 *)(lVar7 + 0x98) = *(undefined8 *)(lVar6 + 0x98);
    }
    *(undefined8 *)(lVar6 + 0x98) = 0;
    *(undefined8 *)(lVar6 + 0x58) = 0;
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    KeReleaseSpinLock(lVar1,uVar4);
  }
  return;
}



===== ControllerInterrupt @ 140002f70 =====

undefined8 ControllerInterrupt(undefined8 param_1,longlong param_2)

{
  short sVar1;
  byte bVar2;
  undefined8 in_RAX;
  undefined7 uVar3;
  undefined1 uVar4;
  short sVar5;
  
  uVar4 = 0;
  in((short)*(undefined8 *)(param_2 + 8) + 7);
  uVar3 = (undefined7)((ulonglong)in_RAX >> 8);
  sVar1 = (short)*(undefined8 *)(param_2 + 0x10);
  sVar5 = sVar1 + 2;
  bVar2 = in(sVar5);
  if ((bVar2 != 0xff) && ((bVar2 & 4) != 0)) {
    uVar4 = 1;
    out(sVar1,0);
    uVar3 = 0;
    out(sVar5,4);
  }
  return CONCAT71(uVar3,uVar4);
}



===== ControllerInterruptControl @ 140002fc0 =====

int ControllerInterruptControl(longlong param_1,ulonglong param_2,char param_3)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong *local_48;
  code *local_40;
  longlong *local_38;
  undefined8 local_30;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_20;
  
  iVar3 = 0;
  plVar1 = (longlong *)(param_1 + ((param_2 & 0xff) * 3 + 0x47) * 8);
  if (param_3 == '\0') {
    local_60 = *plVar1;
    if (local_60 != 0) {
      local_64 = 0;
      local_68 = 1;
      IoDisconnectInterruptEx(&local_68);
      *plVar1 = 0;
    }
  }
  else {
    uVar2 = (uint)param_2 & 0xff;
    local_54 = 0;
    plVar1[1] = *(longlong *)(*(longlong *)(param_1 + 0x100) + (ulonglong)(uVar2 * 2) * 0x18);
    plVar1[2] = (ulonglong)(uVar2 * 8) + *(longlong *)(*(longlong *)(param_1 + 0x100) + 0x60);
    memset(&local_58,0,0x50);
    local_58 = 1;
    uVar4 = GenPopulateInterruptParameters(*(uint **)(param_1 + 0xf0),(longlong)&local_58);
    if ((char)uVar4 == '\0') {
      iVar3 = -0x3fffff66;
    }
    else {
      local_50 = *(undefined8 *)(param_1 + 8);
      local_30 = 0;
      local_40 = ControllerInterrupt;
      local_28 = local_20;
      local_27 = 0;
      local_48 = plVar1;
      local_38 = plVar1;
      iVar3 = IoConnectInterruptEx(&local_58);
      if (iVar3 < 0) {
        *plVar1 = 0;
      }
    }
  }
  return iVar3;
}



===== ChannelAcquireControllerSpinLock @ 1400030f0 =====

void ChannelAcquireControllerSpinLock(longlong param_1)

{
  KeAcquireSpinLockAtDpcLevel(*(longlong *)(param_1 + 0x58) + 0x2a8);
  return;
}



===== ChannelReleaseControllerSpinLock @ 140003120 =====

void ChannelReleaseControllerSpinLock(longlong param_1)

{
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 0x58) + 0x2a8);
  return;
}



===== PciIdeAllocateAccessToken @ 140003150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PciIdeAllocateAccessToken(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  _DAT_1400070f0 = _DAT_1400070f0 + 1;
  IoAllocateController
            (*(undefined8 *)(*(longlong *)(param_1 + 0x58) + 0x2a0),*(undefined8 *)(param_1 + 0x18),
             param_2,param_3);
  return 0;
}



===== PciIdeFreeAccessToken @ 140003190 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PciIdeFreeAccessToken(longlong param_1)

{
  _DAT_1400070f0 = _DAT_1400070f0 + -1;
  IoFreeController(*(undefined8 *)(*(longlong *)(param_1 + 0x58) + 0x2a0));
  return 0;
}



===== PciIdeDispatchPower @ 1400031c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PciIdeDispatchPower(longlong param_1,longlong param_2)

{
  byte bVar1;
  code *pcVar2;
  
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (bVar1 < 4) {
    pcVar2 = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x30) + (ulonglong)bVar1 * 8);
  }
  else {
    pcVar2 = *(code **)(*(longlong *)(param_1 + 0x40) + 0x20);
  }
  (*pcVar2)();
  return;
}



===== RtlStringCbPrintfA @ 1400031fc =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

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



===== RtlStringCbPrintfW @ 140003270 =====

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



===== AtaPortGetBusData @ 1400032f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AtaPortGetBusData(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
                    /* 0x32f0  12  AtaPortGetBusData */
  uVar1 = 0;
  if (*(code **)(param_1 + -0x150) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + -0x150))
                      (*(undefined8 *)(param_1 + -0x180),0,param_2,param_3,param_4);
  }
  return uVar1;
}



===== AtaPortSetBusData @ 140003330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AtaPortSetBusData(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
                    /* 0x3330  43  AtaPortSetBusData */
  uVar1 = 0;
  if (*(code **)(param_1 + -0x158) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + -0x158))
                      (*(undefined8 *)(param_1 + -0x180),0,param_2,param_3,param_4);
  }
  return uVar1;
}



===== PciIdeXGetBusData @ 140003370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PciIdeXGetBusData(longlong param_1,undefined8 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
                    /* 0x3370  61  PciIdeXGetBusData */
  iVar1 = 0;
  if (*(code **)(param_1 + -0x150) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + -0x150))
                      (*(undefined8 *)(param_1 + -0x180),0,param_2,param_3,param_4);
  }
  return -(uint)(iVar1 != param_4) & 0xc0000001;
}



===== PciIdeXSetBusData @ 1400033c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PciIdeXSetBusData(longlong param_1,longlong param_2,longlong param_3,undefined4 param_4,
                      uint param_5)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  
                    /* 0x33c0  63  PciIdeXSetBusData */
  uVar7 = (ulonglong)param_5;
  pbVar4 = (byte *)ExAllocatePoolWithTag(0x200,param_5,0x58656449);
  uVar5 = 0;
  if (pbVar4 == (byte *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + -0x148);
    uVar3 = 0;
    if (*(code **)(param_1 + -0x150) != (code *)0x0) {
      uVar3 = (**(code **)(param_1 + -0x150))
                        (*(undefined8 *)(param_1 + -0x180),0,pbVar4,param_4,param_5);
    }
    if (uVar3 == param_5) {
      if (param_5 != 0) {
        pbVar6 = pbVar4;
        do {
          bVar1 = (pbVar6 + (param_2 - (longlong)pbVar4))[param_3 - param_2];
          *pbVar6 = ~bVar1 & *pbVar6 | pbVar6[param_2 - (longlong)pbVar4] & bVar1;
          pbVar6 = pbVar6 + 1;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      if (*(code **)(param_1 + -0x158) != (code *)0x0) {
        uVar5 = (**(code **)(param_1 + -0x158))
                          (*(undefined8 *)(param_1 + -0x180),0,pbVar4,param_4,param_5);
      }
      uVar5 = -(uint)(uVar5 != param_5) & 0xc0000001;
    }
    else {
      uVar5 = 0xc0000001;
    }
    KeReleaseSpinLock(param_1 + -0x148,uVar2);
    ExFreePoolWithTag(pbVar4,0);
  }
  return uVar5;
}



===== PciIdexGetBusLocation @ 140003530 =====

void PciIdexGetBusLocation(longlong param_1,undefined8 param_2)

{
  undefined4 local_res8 [8];
  
                    /* 0x3530  64  PciIdexGetBusLocation */
  local_res8[0] = 0;
  IoGetDeviceProperty(*(undefined8 *)(param_1 + -0x370),0x10,4,param_2,local_res8);
  return;
}



===== FdoProcessDevicePowerChange @ 140003570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FdoProcessDevicePowerChange
               (longlong param_1,int param_2,int param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  char local_e8 [192];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_118;
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(local_e8,0,0xc0);
  uVar5 = 2;
  if (*(byte *)(lVar1 + 0x1b1) < 2) {
    if (param_2 == 1) {
      if ((param_3 == 4) && (*(char *)(lVar1 + 0x2b0) != '\0')) {
        if (*(code **)(lVar1 + 0x228) != (code *)0x0) {
          local_f8 = 0xc0;
          (**(code **)(lVar1 + 0x228))(*(undefined8 *)(lVar1 + 0x1f8),0,local_e8,0x40);
        }
        lVar4 = 0;
        do {
          if (local_e8[lVar4] != '\0') {
            *(undefined1 *)(lVar1 + 0x2b0) = 0;
            break;
          }
          lVar4 = lVar4 + 1;
        } while (lVar4 < 0x40);
        if (*(char *)(lVar1 + 0x2b0) != '\0') {
          if (*(code **)(lVar1 + 0x220) != (code *)0x0) {
            local_f8 = 0xc0;
            (**(code **)(lVar1 + 0x220))(*(undefined8 *)(lVar1 + 0x1f8),0,lVar1 + 0x2b1,0x40);
          }
          *(undefined1 *)(lVar1 + 0x2b0) = 0;
        }
      }
    }
    else if ((param_2 == 4) && (param_3 == 1)) {
      if (*(code **)(lVar1 + 0x228) != (code *)0x0) {
        local_f8 = 0xc0;
        iVar2 = (**(code **)(lVar1 + 0x228))(*(undefined8 *)(lVar1 + 0x1f8),0,lVar1 + 0x2b1,0x40);
        if (iVar2 == 0xc0) {
          *(undefined1 *)(lVar1 + 0x2b0) = 1;
        }
      }
    }
  }
  else {
    if (param_2 == 1) {
      pcVar3 = *(code **)(lVar1 + 0x1e0);
      if (pcVar3 == (code *)0x0) goto LAB_1400036ef;
    }
    else {
      if ((param_3 != 1) || (pcVar3 = *(code **)(lVar1 + 0x1e0), pcVar3 == (code *)0x0))
      goto LAB_1400036ef;
      uVar5 = 3;
    }
    (*pcVar3)(*(undefined8 *)(lVar1 + 0xe8),uVar5,0);
  }
LAB_1400036ef:
  PoStartNextPowerIrp(param_6);
  IofCompleteRequest(param_6,0);
  return;
}



===== PciIdeReadConfigSpace @ 140003740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
PciIdeReadConfigSpace(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(code **)(param_1 + 0x228) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x228))
                      (*(undefined8 *)(param_1 + 0x1f8),0,param_2,param_3,param_4);
  }
  return uVar1;
}



===== PciIdeEtwEnableCallback @ 140003780 =====

void PciIdeEtwEnableCallback(undefined8 param_1,int param_2)

{
  AtaEtwEnabled = param_2 != 0;
  return;
}



===== PciIdeRegisterEtw @ 140003794 =====

void PciIdeRegisterEtw(void)

{
  int iVar1;
  
  if (AtaEtwHandle == 0) {
    iVar1 = EtwRegister(&STORAGE_ATAPORT_PROVIDER,PciIdeEtwEnableCallback,0,&AtaEtwHandle);
    if (iVar1 < 0) {
      AtaEtwHandle = 0;
    }
  }
  return;
}



===== PciIdeUnregisterEtw @ 1400037e0 =====

void PciIdeUnregisterEtw(void)

{
  if (AtaEtwHandle != 0) {
    EtwUnregister();
    AtaEtwHandle = 0;
  }
  return;
}



===== PortWdmSetEventCompletionRoutine @ 140003810 =====

undefined8 PortWdmSetEventCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if (*(char *)(param_2 + 0x41) == '\x01') {
    KeSetEvent(param_3,0,0);
  }
  return 0xc0000016;
}



===== PortTraceInitGlobalLogger @ 140003844 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PortTraceInitGlobalLogger(undefined8 *param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined1 *puVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined4 local_168;
  int local_164;
  uint local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined4 local_140;
  wchar_t *local_138;
  uint *local_130;
  undefined4 local_128;
  undefined4 *local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  wchar_t local_98 [56];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_198;
  puVar1 = (uint *)*param_1;
  puVar2 = (undefined8 *)param_1[1];
  puVar3 = (uint *)param_1[2];
  puVar4 = (undefined1 *)param_1[3];
  builtin_wcsncpy(local_98 + 8,L"alLogger\\",10);
  local_138 = L"Start";
  local_130 = (uint *)&local_164;
  local_120 = &local_168;
  local_160 = 0;
  local_15c = 0;
  local_164 = 0;
  local_168 = 0;
  local_98[0x12] = 0;
  builtin_wcsncpy(local_98,L"WMI\\Glob",8);
  local_148 = 0;
  local_140 = 0x120;
  local_128 = 0x4000004;
  local_118 = 4;
  local_110 = 0;
  local_108 = 0;
  local_158 = 0;
  uStack_150 = 0;
  RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
  pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
  local_178 = 0;
  if (pcVar6 == (code *)0x0) {
    pcVar6 = RtlQueryRegistryValues_exref;
  }
  iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
  if ((-1 < iVar5) && (local_164 != 0)) {
    local_148 = 0;
    local_138 = L"Flags";
    local_130 = &local_160;
    local_140 = 0x120;
    local_120 = &local_168;
    local_100 = L"Level";
    local_f8 = &local_15c;
    local_e8 = &local_168;
    lVar7 = -1;
    local_128 = 0x4000004;
    local_118 = 4;
    local_110 = 0;
    local_108 = 0x120;
    local_f0 = 0x4000004;
    local_e0 = 1;
    local_d8 = 0;
    local_d0 = 0;
    do {
      lVar7 = lVar7 + 1;
    } while (local_98[lVar7] != L'\0');
    WppGuidToStr((longlong)(local_98 + lVar7),puVar1);
    local_158 = 0;
    uStack_150 = 0;
    RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
    pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
    local_178 = 0;
    if (pcVar6 == (code *)0x0) {
      pcVar6 = RtlQueryRegistryValues_exref;
    }
    iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
    if ((-1 < iVar5) && (local_164 == 1)) {
      *puVar2 = 1;
      *puVar3 = local_160 & 0x7fffffff;
      *puVar4 = (undefined1)local_15c;
    }
  }
  return;
}



===== PortTraceInitTracing @ 140003ab0 =====

void PortTraceInitTracing(undefined8 *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)*param_1;
  if (*piVar1 == 0x38) {
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    if (*(longlong *)(piVar1 + 10) == 0) {
      *(undefined4 *)(param_1 + 1) = 0;
    }
    else {
      puVar3 = (undefined4 *)ExAllocatePool2(0x40,0xa0,0x63546c50);
      if (puVar3 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 1) = 0xc000009a;
      }
      else {
        *puVar3 = 0xa0;
        lVar2 = *(longlong *)(piVar1 + 10);
        *(longlong *)(puVar3 + 2) = lVar2;
        *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(lVar2 + 0x68);
        *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(piVar1 + 8);
        PortTraceErrorRegisterDriver((longlong)puVar3,(longlong)piVar1);
        *(undefined4 **)(piVar1 + 0xc) = puVar3;
        *(undefined4 *)(param_1 + 1) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 1) = 0xc000000d;
  }
  return;
}



===== WppGuidToStr @ 140003b58 =====

void WppGuidToStr(longlong param_1,uint *param_2)

{
  longlong lVar1;
  
  lVar1 = param_1;
  WppIntToHex(param_1,*param_2,8);
  *(undefined2 *)(param_1 + 0x10) = 0x2d;
  WppIntToHex(param_1 + 0x12,(uint)(ushort)param_2[1],4);
  *(undefined2 *)(lVar1 + 0x1a) = 0x2d;
  WppIntToHex(lVar1 + 0x1c,(uint)*(ushort *)((longlong)param_2 + 6),4);
  *(undefined2 *)(lVar1 + 0x24) = 0x2d;
  WppIntToHex(lVar1 + 0x26,(uint)(byte)param_2[2],2);
  WppIntToHex(lVar1 + 0x2a,(uint)*(byte *)((longlong)param_2 + 9),2);
  *(undefined2 *)(lVar1 + 0x2e) = 0x2d;
  WppIntToHex(lVar1 + 0x30,(uint)*(byte *)((longlong)param_2 + 10),2);
  WppIntToHex(lVar1 + 0x34,(uint)*(byte *)((longlong)param_2 + 0xb),2);
  WppIntToHex(lVar1 + 0x38,(uint)(byte)param_2[3],2);
  WppIntToHex(lVar1 + 0x3c,(uint)*(byte *)((longlong)param_2 + 0xd),2);
  WppIntToHex(lVar1 + 0x40,(uint)*(byte *)((longlong)param_2 + 0xe),2);
  WppIntToHex(lVar1 + 0x44,(uint)*(byte *)((longlong)param_2 + 0xf),2);
  *(undefined2 *)(lVar1 + 0x48) = 0;
  return;
}



===== WppIntToHex @ 140003c58 =====

void WppIntToHex(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = (longlong)(param_3 + -1);
  if (-1 < param_3 + -1) {
    do {
      uVar1 = param_2 & 0xf;
      param_2 = param_2 >> 4;
      *(wchar_t *)(param_1 + lVar2 * 2) = L"0123456789abcdef"[uVar1];
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  return;
}



===== PortTraceErrorDrainList @ 140003c8c =====

void PortTraceErrorDrainList(undefined8 param_1,undefined8 param_2)

{
  void *_Dst;
  longlong lVar1;
  
  while( true ) {
    lVar1 = ExpInterlockedPopEntrySList(param_2);
    if (lVar1 == 0) break;
    _Dst = (void *)IoAllocateErrorLogEntry(param_1,*(undefined1 *)(lVar1 + 0x14));
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)(lVar1 + 0x20),(ulonglong)*(uint *)(lVar1 + 0x14));
      IoWriteErrorLogEntry(_Dst);
    }
    LOCK();
    *(undefined4 *)(lVar1 + 0x10) = 0;
    UNLOCK();
  }
  return;
}



===== PortpErrorDrainListDpc @ 140003d20 =====

void PortpErrorDrainListDpc(undefined8 param_1,longlong param_2)

{
  PortTraceErrorDrainList(*(undefined8 *)(param_2 + 8),param_2 + 0x40);
  LOCK();
  *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + -1;
  UNLOCK();
  return;
}



===== PortpErrorInitDpc @ 140003d48 =====

void PortpErrorInitDpc(longlong param_1)

{
  KeInitializeDpc(param_1 + 0x58,PortpErrorDrainListDpc,param_1);
  return;
}



===== _guard_check_icall @ 140003d80 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003d98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140003dbc =====

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



===== __security_check_cookie @ 140003e30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003e70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003ea0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003ed0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140003f40 =====

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
  
                    /* 0x3f40  65  memcpy
                       0x3f40  66  memmove */
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



===== memset @ 140004240 =====

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



===== __memset_repmovs @ 140004380 =====

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



===== __memset_query @ 140004400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140004480 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400045c0 =====

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



===== __memset_spec_plain @ 140004640 =====

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



===== memset @ 140005020 =====

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



===== BmSetCallBack @ 14000a010 =====

void BmSetCallBack(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0xf8) = param_2;
  return;
}



===== GenPnpAllocateFdo @ 14000a020 =====

longlong GenPnpAllocateFdo(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                          uint param_5)

{
  longlong *_Dst;
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  RtlInitUnicodeString(local_28 + 1,param_3);
  iVar1 = IoCreateDevice(param_1,param_5,local_28 + 1,0x2a,0x100,0,local_28);
  if (-1 < iVar1) {
    _Dst = *(longlong **)(local_28[0] + 0x40);
    memset(_Dst,0,(ulonglong)param_5);
    _Dst[1] = param_2;
    _Dst[2] = param_1;
    _Dst[3] = local_28[0];
    KeInitializeSpinLock(_Dst + 0x13);
    *(undefined4 *)((longlong)_Dst + 0x4c) = 1;
    *(undefined1 *)((longlong)_Dst + 0xda) = 1;
    lVar2 = IoAttachDeviceToDeviceStack(local_28[0],param_2);
    *_Dst = lVar2;
    if (lVar2 == 0) {
      IoDeleteDevice(local_28[0]);
      return 0;
    }
    *(undefined4 *)(local_28[0] + 0x98) = *(undefined4 *)(lVar2 + 0x98);
    if (*(int *)(local_28[0] + 0x98) == 0) {
      *(undefined4 *)(local_28[0] + 0x98) = 1;
    }
    *(uint *)(local_28[0] + 0x30) = *(uint *)(local_28[0] + 0x30) | *(uint *)(*_Dst + 0x30) & 0x6014
    ;
    GenPnpAddDeviceToGlobalList((longlong)_Dst);
    if (*(char *)((longlong)_Dst + 0xda) == '\0') {
      uVar3 = ChannelCreatePdoCallBack(_Dst[3],(undefined1 *)0x0);
      iVar1 = (int)uVar3;
    }
    else {
      iVar1 = 0;
    }
    *(undefined4 *)(_Dst + 0x1c) = 1;
    if (iVar1 < 0) {
      GenPnpFreeFdo(local_28[0]);
      return 0;
    }
  }
  return local_28[0];
}



===== GenPnpAllocatePdo @ 14000a19c =====

longlong GenPnpAllocatePdo(longlong param_1)

{
  void *_Dst;
  int iVar1;
  undefined8 uVar2;
  longlong local_res8;
  uint in_stack_00000028;
  undefined1 *in_stack_00000030;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  iVar1 = IoCreateDevice(*(undefined8 *)(param_1 + 0x10),0x100,&local_28,4,0x100,0,&local_res8);
  if (-1 < iVar1) {
    *(undefined4 *)(local_res8 + 0x98) = *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x98);
    if (*(int *)(local_res8 + 0x98) == 0) {
      *(undefined4 *)(local_res8 + 0x98) = 1;
    }
    *(uint *)(local_res8 + 0x30) =
         *(uint *)(local_res8 + 0x30) | *(uint *)(*(longlong *)(param_1 + 0x18) + 0x30) & 0x6014;
    _Dst = *(void **)(local_res8 + 0x40);
    memset(_Dst,0,0x100);
    *(undefined8 *)((longlong)_Dst + 0x10) = *(undefined8 *)(param_1 + 0x10);
    *(longlong *)((longlong)_Dst + 0x18) = local_res8;
    *(longlong *)((longlong)_Dst + 8) = local_res8;
    *(undefined4 *)((longlong)_Dst + 0x4c) = 1;
    *(undefined4 *)((longlong)_Dst + 0x50) = 1;
    *(uint *)((longlong)_Dst + 0x54) = in_stack_00000028;
    IoInitializeRemoveLockEx((longlong)_Dst + 0xb0,0x50656449,10,0xfffffff,0x20);
    if (*(char *)((longlong)_Dst + 0xda) == '\0') {
      uVar2 = ChannelCreatePdoCallBack(*(longlong *)((longlong)_Dst + 0x18),in_stack_00000030);
      iVar1 = (int)uVar2;
    }
    else {
      iVar1 = 0;
    }
    *(undefined4 *)((longlong)_Dst + 0xe0) = 1;
    if (iVar1 < 0) {
      GenPnpFreePdo(local_res8,'\x01');
      return 0;
    }
    InsertPdoExtension(param_1,(longlong)_Dst,(ulonglong)in_stack_00000028);
  }
  return local_res8;
}



===== GenPnpBuildDeviceRelations @ 14000a320 =====

uint * GenPnpBuildDeviceRelations(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint local_res8 [2];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar7 = 0;
  iVar1 = *(int *)(lVar2 + 0x54);
  puVar5 = (uint *)0x0;
  if (param_2 != 0) {
    puVar3 = *(uint **)(param_2 + 0x38);
    puVar5 = puVar3;
    if ((puVar3 != (uint *)0x0) && (uVar7 = *puVar3, iVar1 == 0)) goto LAB_14000a458;
  }
  uVar6 = iVar1 + uVar7;
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  puVar3 = (uint *)ExAllocatePoolWithTag(1,uVar6 * 8 + 8,0x58656449);
  if (puVar3 != (uint *)0x0) {
    *puVar3 = 0;
    if (uVar7 != 0) {
      *puVar3 = uVar7;
      memcpy(puVar3 + 2,puVar5 + 2,(ulonglong)uVar7 << 3);
    }
    local_res8[0] = 0;
    while (lVar4 = GenPnpRefNextPdoExtensionWithTag(lVar2,local_res8,GenPnpBuildDeviceRelations),
          lVar4 != 0) {
      if (*(char *)(lVar4 + 0xdb) == '\0') {
        *(ushort *)(lVar4 + 0xd8) = *(ushort *)(lVar4 + 0xd8) | 0x20;
        ObReferenceObjectByPointer(*(undefined8 *)(lVar4 + 0x18),0,0,0);
        if (*puVar3 < uVar6) {
          *(undefined8 *)(puVar3 + (ulonglong)*puVar3 * 2 + 2) = *(undefined8 *)(lVar4 + 0x18);
          *puVar3 = *puVar3 + 1;
        }
      }
      else {
        *(ushort *)(lVar4 + 0xd8) = *(ushort *)(lVar4 + 0xd8) & 0xffdf;
      }
      GenPnpUnRefPdoExtensionWithTag(lVar4,GenPnpBuildDeviceRelations);
    }
  }
  if (puVar5 != (uint *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
LAB_14000a458:
  return puVar3;
}



===== GenPnpFdoQueryPnPDeviceState @ 14000a480 =====

void GenPnpFdoQueryPnPDeviceState(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (*(int *)(puVar1 + 8) != 0) {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1);
  return;
}



===== GenPnpFdoRemoveDevice @ 14000a4c0 =====

undefined4 GenPnpFdoRemoveDevice(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  uint *puVar4;
  bool bVar5;
  uint local_res8 [2];
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  local_res8[0] = 0;
  while( true ) {
    puVar4 = local_res8;
    lVar3 = GenPnpRefNextPdoExtensionWithTag((longlong)puVar1,puVar4,GenPnpFdoRemoveDevice);
    if (lVar3 == 0) break;
    bVar5 = (*(ushort *)(lVar3 + 0xd8) & 4) == 0;
    if (!bVar5) {
      *(ushort *)(lVar3 + 0xd8) = *(ushort *)(lVar3 + 0xd8) & 0xffdf;
    }
    GenPnpUnRefPdoExtensionWithTag(lVar3,GenPnpFdoRemoveDevice);
    GenPnpFreePdo(*(longlong *)(lVar3 + 0x18),bVar5);
  }
  if (*(int *)(puVar1 + 0x1c) - 2U < 2) {
    if (*(char *)((longlong)puVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(puVar1[3]);
    }
    else {
      ControllerRemoveDevice(puVar1[3],(ulonglong)puVar4);
    }
    *(undefined4 *)(puVar1 + 0x1c) = 4;
  }
  *(ushort *)(puVar1 + 0x1b) = *(ushort *)(puVar1 + 0x1b) & 0xfffc | 8;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar2 = IofCallDriver(*puVar1,param_2);
  GenPnpFreeFdo(param_1);
  return uVar2;
}



===== GenPnpFdoStartDevice @ 14000a5d0 =====

int GenPnpFdoStartDevice(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 local_18;
  ulonglong uStack_10;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  local_18 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uStack_10 = (ulonglong)(*(byte *)(puVar1 + 0x1b) >> 1 & 1);
  uVar3 = PortWdmForwardIrpSynchronous(*puVar1,param_2);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    if ((*(byte *)(puVar1 + 0x1b) & 1) == 0) {
      *(undefined4 *)((longlong)puVar1 + 0x4c) = 1;
      if (*(char *)((longlong)puVar1 + 0xda) == '\0') {
        uVar3 = ChannelStartDevice(puVar1[3]);
        iVar2 = (int)uVar3;
      }
      else {
        uVar3 = ControllerStartDevice(puVar1[3],(uint *)&local_18);
        iVar2 = (int)uVar3;
      }
      *(undefined4 *)(puVar1 + 0x1c) = 2;
      if (iVar2 < 0) goto LAB_14000a682;
    }
    *(ushort *)(puVar1 + 0x1b) = *(ushort *)(puVar1 + 0x1b) & 0xfff1 | 1;
    iVar2 = FdoPowerUpDevice(puVar1[3]);
  }
LAB_14000a682:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== GenPnpFdoStopDevice @ 14000a6c0 =====

void GenPnpFdoStopDevice(longlong param_1,ulonglong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if ((*(byte *)(puVar1 + 0x1b) & 1) != 0) {
    if (*(char *)((longlong)puVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(puVar1[3]);
    }
    else {
      ControllerStopDevice(puVar1[3],param_2);
    }
    *(undefined4 *)(puVar1 + 0x1c) = 3;
    *(ushort *)(puVar1 + 0x1b) = *(ushort *)(puVar1 + 0x1b) & 0xfffe | 2;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1,param_2);
  return;
}



===== GenPnpFdoSurpriseRemoveDevice @ 14000a750 =====

void GenPnpFdoSurpriseRemoveDevice(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint *puVar3;
  uint local_res8 [2];
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  local_res8[0] = 0;
  while( true ) {
    puVar3 = local_res8;
    lVar2 = GenPnpRefNextPdoExtensionWithTag((longlong)puVar1,puVar3,GenPnpFdoSurpriseRemoveDevice);
    if (lVar2 == 0) break;
    *(ushort *)(lVar2 + 0xd8) = *(ushort *)(lVar2 + 0xd8) & 0xffdf;
    GenPnpUnRefPdoExtensionWithTag(lVar2,GenPnpFdoSurpriseRemoveDevice);
  }
  if (*(int *)(puVar1 + 0x1c) - 2U < 2) {
    if (*(char *)((longlong)puVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(puVar1[3]);
    }
    else {
      ControllerRemoveDevice(puVar1[3],(ulonglong)puVar3);
    }
  }
  *(undefined4 *)(puVar1 + 0x1c) = 5;
  *(ushort *)(puVar1 + 0x1b) = *(ushort *)(puVar1 + 0x1b) & 0xfffe | 4;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1,param_2);
  return;
}



===== GenPnpFdoUsageNotification @ 14000a820 =====

ulonglong GenPnpFdoUsageNotification(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  plVar3 = *(longlong **)(param_1 + 0x40);
  if ((((*(int *)(lVar2 + 0x10) == 1) && (*(char *)(lVar2 + 8) == '\0')) && ((int)plVar3[8] == 1))
     && ((*(uint *)(param_1 + 0x30) >> 0xe & 1) == 0)) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  uVar4 = PortWdmForwardIrpSynchronous(*plVar3,param_2);
  if (-1 < (int)uVar4) {
    iVar1 = *(int *)(lVar2 + 0x10);
    if (iVar1 == 1) {
      if (*(char *)(lVar2 + 8) == '\0') {
        LOCK();
        *(int *)(plVar3 + 8) = (int)plVar3[8] + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(plVar3 + 8) = (int)plVar3[8] + 1;
        UNLOCK();
      }
    }
    else if (iVar1 == 2) {
      if (*(char *)(lVar2 + 8) == '\0') {
        LOCK();
        *(int *)((longlong)plVar3 + 0x44) = *(int *)((longlong)plVar3 + 0x44) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)((longlong)plVar3 + 0x44) = *(int *)((longlong)plVar3 + 0x44) + 1;
        UNLOCK();
      }
    }
    else if (iVar1 == 3) {
      if (*(char *)(lVar2 + 8) == '\0') {
        LOCK();
        *(int *)(plVar3 + 9) = (int)plVar3[9] + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(plVar3 + 9) = (int)plVar3[9] + 1;
        UNLOCK();
      }
    }
  }
  if ((*(int *)(lVar2 + 0x10) == 1) && ((*(uint *)(*plVar3 + 0x30) & 0x2000) == 0)) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
  }
  IofCompleteRequest(param_2,0);
  return uVar4 & 0xffffffff;
}



===== GenPnpFreeFdo @ 14000a914 =====

void GenPnpFreeFdo(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(undefined4 *)(puVar1 + 0x1c) = 5;
  GenPnpRemoveDeviceFromGlobalList((longlong)puVar1);
  IoDetachDevice(*puVar1);
  *puVar1 = 0;
  IoDeleteDevice(param_1);
  return;
}



===== GenPnpFreePdo @ 14000a96c =====

void GenPnpFreePdo(longlong param_1,char param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(lVar1 + 0xe0) = 5;
  if (*(longlong *)(lVar1 + 0x58) != 0) {
    RemovePdoExtension(*(longlong *)(lVar1 + 0x58),lVar1);
  }
  if (param_2 != '\0') {
    IoDeleteDevice(param_1);
  }
  return;
}



===== GenPnpPassDownToNextDriver @ 14000a9c0 =====

void GenPnpPassDownToNextDriver(longlong param_1,longlong param_2)

{
  PortWdmPassDownToNextDriver(**(undefined8 **)(param_1 + 0x40),param_2);
  return;
}



===== GenPnpPdoQueryCapabilities @ 14000a9e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GenPnpPdoQueryCapabilities(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  memset(&local_58,0,0x40);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58), lVar1 == 0)) {
    iVar3 = -0x3fffff40;
  }
  else {
    iVar3 = PortWdmGetDeviceCapabilities(*(undefined8 *)(lVar1 + 8),(undefined4 *)&local_58);
    if (-1 < iVar3) {
      puVar2 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 8);
      *puVar2 = local_58;
      puVar2[1] = uStack_50;
      puVar2[2] = local_48;
      puVar2[3] = uStack_40;
      puVar2[4] = local_38;
      puVar2[5] = uStack_30;
      puVar2[6] = local_28;
      puVar2[7] = uStack_20;
      lVar1 = *(longlong *)(param_1 + 0x40);
      *(uint *)((longlong)puVar2 + 4) = *(uint *)((longlong)puVar2 + 4) & 0xffffffbf;
      *(uint *)(puVar2 + 1) = (uint)*(byte *)(lVar1 + 0xe4);
    }
  }
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== GenPnpPdoQueryDeviceRelations @ 14000aac0 =====

undefined4 GenPnpPdoQueryDeviceRelations(undefined8 param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 4) {
    puVar1 = (undefined4 *)ExAllocatePoolWithTag(1,0x10,0x58656449);
    uVar2 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xc0000017;
    }
    else {
      *puVar1 = 1;
      *(undefined8 *)(puVar1 + 2) = param_1;
      ObReferenceObjectByPointer(param_1,0,0,*(undefined1 *)(param_2 + 0x40));
    }
    *(undefined4 *)(param_2 + 0x30) = uVar2;
    *(undefined4 **)(param_2 + 0x38) = puVar1;
  }
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== GenPnpPdoQueryPnPDeviceState @ 14000ab70 =====

undefined8 GenPnpPdoQueryPnPDeviceState(longlong param_1,longlong param_2)

{
  if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x40) != 0) {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== GenPnpPdoQueryRemoveDevice @ 14000abb0 =====

undefined4 GenPnpPdoQueryRemoveDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = 0;
  if (((*(char *)(lVar1 + 0xdd) != '\0') || (*(int *)(lVar1 + 0x40) != 0)) ||
     (*(int *)(lVar1 + 0x48) != 0)) {
    uVar2 = 0xc0000001;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== GenPnpPdoQueryStopDevice @ 14000ac00 =====

undefined4 GenPnpPdoQueryStopDevice(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*(longlong *)(param_1 + 0x40) + 0x40) != 0) ||
     (*(int *)(*(longlong *)(param_1 + 0x40) + 0x48) != 0)) {
    uVar1 = 0xc0000001;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== GenPnpPdoRemoveDevice @ 14000ac50 =====

undefined8 GenPnpPdoRemoveDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  ushort uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0xe0) - 2U < 2) {
    if (*(char *)(lVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(*(longlong *)(lVar1 + 0x18));
    }
    else {
      ControllerRemoveDevice(*(longlong *)(lVar1 + 0x18),param_2);
    }
    *(undefined4 *)(lVar1 + 0xe0) = 4;
  }
  uVar2 = *(ushort *)(lVar1 + 0xd8) & 0x20;
  *(ushort *)(lVar1 + 0xd8) = (-(ushort)(uVar2 != 0) & 8) + 8 | *(ushort *)(lVar1 + 0xd8) & 0xfffc;
  if (uVar2 == 0) {
    GenPnpFreePdo(*(longlong *)(lVar1 + 0x18),'\x01');
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== GenPnpPdoStartDevice @ 14000ad10 =====

undefined4 GenPnpPdoStartDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  uint local_18 [2];
  ulonglong uStack_10;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  uStack_10 = 0;
  if ((*(ushort *)(lVar1 + 0xd8) & 1) == 0) {
    *(undefined4 *)(lVar1 + 0x4c) = 1;
    uStack_10 = (ulonglong)((*(ushort *)(lVar1 + 0xd8) & 2) != 0);
    *(undefined4 *)(lVar1 + 0x50) = 1;
    if (*(char *)(lVar1 + 0xda) == '\0') {
      uVar3 = ChannelStartDevice(*(longlong *)(lVar1 + 0x18));
      uVar2 = (undefined4)uVar3;
    }
    else {
      uVar3 = ControllerStartDevice(*(longlong *)(lVar1 + 0x18),local_18);
      uVar2 = (undefined4)uVar3;
    }
    *(undefined4 *)(lVar1 + 0xe0) = 2;
  }
  *(ushort *)(lVar1 + 0xd8) = *(ushort *)(lVar1 + 0xd8) & 0xffe1 | 1;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== GenPnpPdoStopDevice @ 14000add0 =====

undefined8 GenPnpPdoStopDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(byte *)(lVar1 + 0xd8) & 1) != 0) {
    if (*(char *)(lVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(*(longlong *)(lVar1 + 0x18));
    }
    else {
      ControllerStopDevice(*(longlong *)(lVar1 + 0x18),param_2);
    }
    *(undefined4 *)(lVar1 + 0xe0) = 3;
    *(ushort *)(lVar1 + 0xd8) = *(ushort *)(lVar1 + 0xd8) & 0xfffe | 2;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== GenPnpPdoSurpriseRemoveDevice @ 14000ae50 =====

undefined8 GenPnpPdoSurpriseRemoveDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0xe0) - 2U < 2) {
    if (*(char *)(lVar1 + 0xda) == '\0') {
      ChannelStopRemoveDevice(*(longlong *)(lVar1 + 0x18));
    }
    else {
      ControllerRemoveDevice(*(longlong *)(lVar1 + 0x18),param_2);
    }
    *(undefined4 *)(lVar1 + 0xe0) = 4;
  }
  if ((*(byte *)(lVar1 + 0xd8) & 0x20) == 0) {
    GenPnpFreePdo(param_1,'\0');
  }
  *(ushort *)(lVar1 + 0xd8) = *(ushort *)(lVar1 + 0xd8) & 0xfffc | 4;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== GenPnpPdoUsageNotification @ 14000af00 =====

int GenPnpPdoUsageNotification(longlong param_1,longlong param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  puVar3 = *(undefined1 **)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0x40);
  pcVar1 = puVar3 + 8;
  lVar5 = *(longlong *)(lVar4 + 0x58);
  if (*(int *)(puVar3 + 0x10) == 1) {
    if (((*pcVar1 == '\0') && (*(int *)(lVar4 + 0x40) == 1)) &&
       ((*(uint *)(param_1 + 0x30) >> 0xe & 1) == 0)) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
    }
    IoInvalidateDeviceState();
  }
  lVar11 = IoGetAttachedDeviceReference(*(undefined8 *)(lVar5 + 0x18));
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lVar12 = IoAllocateIrp(*(undefined1 *)(lVar11 + 0x4c));
  if (lVar12 == 0) {
    iVar10 = -0x3fffffe9;
  }
  else {
    lVar6 = *(longlong *)(lVar12 + 0xb8);
    *(undefined1 *)(lVar6 + -0x48) = *puVar3;
    *(undefined1 *)(lVar6 + -0x47) = puVar3[1];
    *(undefined1 *)(lVar6 + -0x46) = puVar3[2];
    *(undefined8 *)(lVar6 + -0x20) = *(undefined8 *)(puVar3 + 0x28);
    *(undefined8 *)(lVar6 + -0x18) = *(undefined8 *)(puVar3 + 0x30);
    uVar7 = *(undefined4 *)(puVar3 + 0xc);
    uVar8 = *(undefined4 *)(puVar3 + 0x10);
    uVar9 = *(undefined4 *)(puVar3 + 0x14);
    *(undefined4 *)(lVar6 + -0x40) = *(undefined4 *)pcVar1;
    *(undefined4 *)(lVar6 + -0x3c) = uVar7;
    *(undefined4 *)(lVar6 + -0x38) = uVar8;
    *(undefined4 *)(lVar6 + -0x34) = uVar9;
    uVar7 = *(undefined4 *)(puVar3 + 0x1c);
    uVar8 = *(undefined4 *)(puVar3 + 0x20);
    uVar9 = *(undefined4 *)(puVar3 + 0x24);
    *(undefined4 *)(lVar6 + -0x30) = *(undefined4 *)(puVar3 + 0x18);
    *(undefined4 *)(lVar6 + -0x2c) = uVar7;
    *(undefined4 *)(lVar6 + -0x28) = uVar8;
    *(undefined4 *)(lVar6 + -0x24) = uVar9;
    *(undefined4 *)(lVar12 + 0x30) = 0xc00000bb;
    KeInitializeEvent(&local_48,0,0);
    lVar6 = *(longlong *)(lVar12 + 0xb8);
    *(code **)(lVar6 + -0x10) = PortWdmSetEventCompletionRoutine;
    *(undefined8 **)(lVar6 + -8) = &local_48;
    *(undefined1 *)(lVar6 + -0x45) = 0xe0;
    iVar10 = IofCallDriver(lVar11);
    if (iVar10 == 0x103) {
      KeWaitForSingleObject(&local_48,0,0,0,0);
    }
    iVar10 = *(int *)(lVar12 + 0x30);
    IoFreeIrp(lVar12);
  }
  ObfDereferenceObject(lVar11);
  if (-1 < iVar10) {
    iVar2 = *(int *)(puVar3 + 0x10);
    if (iVar2 == 1) {
      if (*pcVar1 == '\0') {
        LOCK();
        *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
        UNLOCK();
      }
    }
    else if (iVar2 == 2) {
      if (*pcVar1 == '\0') {
        LOCK();
        *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x44) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x44) + 1;
        UNLOCK();
      }
    }
    else if (iVar2 == 3) {
      if (*pcVar1 == '\0') {
        LOCK();
        *(int *)(lVar4 + 0x48) = *(int *)(lVar4 + 0x48) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x48) = *(int *)(lVar4 + 0x48) + 1;
        UNLOCK();
      }
    }
  }
  if ((*(int *)(puVar3 + 0x10) == 1) &&
     ((*(uint *)(*(longlong *)(lVar5 + 0x18) + 0x30) & 0x2000) == 0)) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
  }
  *(int *)(param_2 + 0x30) = iVar10;
  IofCompleteRequest(param_2);
  return iVar10;
}



===== GenPnpSuccessAndPassDown @ 14000b130 =====

void GenPnpSuccessAndPassDown(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  PortWdmPassDownToNextDriver(**(undefined8 **)(param_1 + 0x40),param_2);
  return;
}



===== GenPopulateAccessRange @ 14000b150 =====

ulonglong GenPopulateAccessRange(uint *param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar3 = 0;
  if ((param_1 == (uint *)0x0) || (param_2 == 0)) {
    uVar3 = 0;
  }
  else {
    puVar4 = param_1 + 1;
    if (*param_1 != 0) {
      uVar6 = (ulonglong)*param_1;
      do {
        uVar1 = puVar4[3];
        uVar8 = 0;
        if (uVar1 != 0) {
          puVar5 = puVar4 + 7;
          do {
            if ((char)puVar5[-3] == '\x01') {
              *(undefined8 *)(param_2 + uVar3 * 0x18) = *(undefined8 *)(puVar5 + -2);
              *(uint *)(param_2 + 0x10 + uVar3 * 0x18) = *puVar5;
              *(undefined1 *)(param_2 + 0x14 + uVar3 * 0x18) = 0;
LAB_14000b226:
              uVar3 = (ulonglong)((int)uVar3 + 1);
            }
            else if ((char)puVar5[-3] == '\x03') {
              uVar2 = MmMapIoSpaceEx(*(undefined8 *)(puVar4 + uVar8 * 5 + 5),*puVar5,0x204);
              *(undefined8 *)(param_2 + uVar3 * 0x18) = uVar2;
              uVar2 = MmGetPhysicalAddress(uVar2);
              *(undefined8 *)(param_2 + 8 + uVar3 * 0x18) = uVar2;
              *(uint *)(param_2 + 0x10 + uVar3 * 0x18) = *puVar5;
              *(undefined1 *)(param_2 + 0x14 + uVar3 * 0x18) = 1;
              goto LAB_14000b226;
            }
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
            puVar5 = puVar5 + 5;
          } while (uVar7 < uVar1);
        }
        puVar4 = puVar4 + (ulonglong)uVar1 * 5 + 4;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  return uVar3;
}



===== GenPopulateInterruptParameters @ 14000b274 =====

ulonglong GenPopulateInterruptParameters(uint *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong in_RAX;
  uint *puVar2;
  uint *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  uVar6 = 0;
  if (param_1 == (uint *)0x0) {
    uVar4 = in_RAX & 0xffffffffffffff00;
  }
  else {
    puVar2 = param_1 + 1;
    if (*param_1 != 0) {
      uVar4 = (ulonglong)*param_1;
      do {
        uVar1 = puVar2[3];
        if (uVar1 != 0) {
          puVar3 = puVar2 + 6;
          uVar5 = (ulonglong)uVar1;
          do {
            if ((char)puVar3[-2] == '\x02') {
              uVar6 = 1;
              *(bool *)(param_2 + 0x32) = *(char *)((longlong)puVar3 + -7) == '\x03';
              *(uint *)(param_2 + 0x34) = *puVar3;
              *(char *)(param_2 + 0x38) = (char)puVar3[-1];
              *(uint *)(param_2 + 0x3c) = *(ushort *)((longlong)puVar3 + -6) & 1;
              *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(puVar3 + 1);
            }
            puVar3 = puVar3 + 5;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        puVar2 = puVar2 + (ulonglong)uVar1 * 5 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar4 = CONCAT71((int7)((ulonglong)puVar2 >> 8),uVar6);
  }
  return uVar4;
}



===== ChannelGetAllocatedResources @ 14000b310 =====

longlong ChannelGetAllocatedResources(longlong param_1)

{
  return *(longlong *)(param_1 + 0x58) + 0xf0;
}



===== ChannelGetChannelProperties @ 14000b330 =====

undefined8 ChannelGetChannelProperties(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  uVar2 = ((uint)*(byte *)(lVar1 + 0x1af) << 2 ^ *param_2) & 4 ^ *param_2;
  *param_2 = uVar2;
  uVar2 = (*(byte *)(lVar1 + 0x1ae) ^ uVar2) & 1 ^ uVar2;
  *param_2 = uVar2;
  *param_2 = -(uint)(*(longlong *)(param_1 + 0xe8) != 0) & 2 | uVar2 & 0xfffffffd;
  PopulateTimingTable(lVar1,param_2 + 4,param_2 + 3);
  uVar2 = 0x1000;
  if (0x1000 < *(uint *)(lVar1 + 0x1a8)) {
    uVar2 = *(uint *)(lVar1 + 0x1a8);
  }
  param_2[1] = uVar2;
  param_2[2] = *(uint *)(param_1 + 0xf0);
  param_2[0x23] = *(uint *)(lVar1 + 0x1e8);
  return 0;
}



===== ChannelGetInterface @ 14000b3e0 =====

undefined8 ChannelGetInterface(longlong param_1,int param_2,longlong *param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_2 == 0) {
    if (param_4 != 0x40) {
      return 0xc0000059;
    }
    lVar1 = *(longlong *)(param_1 + 0x58);
    if (*(byte *)(lVar1 + 0x1b1) < 2) {
      return 0xc00000bb;
    }
    *(undefined4 *)param_3 = *(undefined4 *)(lVar1 + 0x1a0);
    lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(lVar1 + 0x10),DriverEntry);
    lVar2 = *(longlong *)(lVar3 + 0x48);
    param_3[1] = *(longlong *)(lVar3 + 0x40);
    param_3[2] = lVar2;
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40);
    param_3[3] = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x38);
    param_3[4] = lVar2;
    param_3[5] = *(longlong *)(lVar1 + 0xe8);
    param_3[7] = *(longlong *)(lVar1 + 0x1b8);
    param_3[6] = *(longlong *)(lVar1 + 0x1c8);
  }
  else if (param_2 == 1) {
    if (param_4 != 0x10) {
      return 0xc0000059;
    }
    lVar1 = *(longlong *)(param_1 + 0x58);
    if (1 < *(byte *)(lVar1 + 0x1b1)) {
      return 0xc00000bb;
    }
    if (*(char *)(lVar1 + 0x1ae) == '\0') {
      return 0xc00000bb;
    }
    *param_3 = lVar1;
    param_3[1] = (longlong)ControllerInterruptControl;
  }
  else if (param_2 == 2) {
    if (param_4 != 0x40) {
      return 0xc0000059;
    }
    if (*(longlong *)(param_1 + 0xe8) == 0) {
      return 0xc00000bb;
    }
    *param_3 = param_1;
    param_3[1] = (longlong)BmSetup;
    param_3[3] = (longlong)BmFlush;
    param_3[2] = (longlong)BmSetCallBack;
    param_3[4] = (longlong)BmAllocateCommonBuffer;
    param_3[5] = (longlong)BmFreeCommonBuffer;
    param_3[7] = (longlong)BmGetDmaAdapterObject;
    param_3[6] = (longlong)BmBuildMdlFromScatterGatherList;
  }
  else if (param_2 == 3) {
    if (param_4 != 0x28) {
      return 0xc0000059;
    }
    lVar1 = *(longlong *)(param_1 + 0x58);
    if (1 < *(byte *)(lVar1 + 0x1b1)) {
      return 0xc00000bb;
    }
    param_3[1] = *(longlong *)(lVar1 + 0xe8);
    *(undefined4 *)param_3 = *(undefined4 *)(lVar1 + 0x1a4);
    param_3[2] = *(longlong *)(lVar1 + 0x1c8);
    param_3[4] = *(longlong *)(lVar1 + 0x1e0);
    param_3[3] = *(longlong *)(lVar1 + 0x1d8);
  }
  else {
    if (param_2 != 4) {
      return 0xc0000059;
    }
    if (param_4 != 0x18) {
      return 0xc0000059;
    }
    if (*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x2a0) == 0) {
      return 0xc00000bb;
    }
    *param_3 = param_1;
    param_3[1] = (longlong)PciIdeAllocateAccessToken;
    param_3[2] = (longlong)PciIdeFreeAccessToken;
  }
  return 0;
}



===== ChannelQueryInterface @ 14000b5f0 =====

undefined4 ChannelQueryInterface(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_2 + 0x30);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (((**(longlong **)(lVar1 + 8) == 0x4157f83714a001c6) &&
      ((*(longlong **)(lVar1 + 8))[1] == -0x67763ead90b63641)) && (0x37 < *(ushort *)(lVar1 + 0x10))
     ) {
    lVar2 = *(longlong *)(param_1 + 0x40);
    uVar4 = 0;
    puVar3 = *(undefined1 **)(lVar1 + 0x18);
    *puVar3 = *(undefined1 *)(lVar2 + 0xe4);
    *(code **)(puVar3 + 0x10) = ChannelGetInterface;
    *(code **)(puVar3 + 0x20) = ChannelGetChannelProperties;
    *(code **)(puVar3 + 0x18) = ChannelGetAllocatedResources;
    *(code **)(puVar3 + 0x28) = ChannelAcquireControllerSpinLock;
    *(code **)(puVar3 + 0x30) = ChannelReleaseControllerSpinLock;
    *(longlong *)(puVar3 + 8) = lVar2;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== PciIdeGetBusStandardInterface @ 14000b698 =====

ulonglong PciIdeGetBusStandardInterface(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar2 = IoBuildSynchronousFsdRequest(0x1b,*param_1,0,0,0,local_38 + 2,local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_BUS_INTERFACE_STANDARD;
    *(undefined8 **)(lVar1 + -0x30) = param_1 + 0x3e;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0x10040;
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    uVar3 = IofCallDriver(*param_1);
    if (-1 < (int)uVar3) {
      if ((int)uVar3 == 0x103) {
        KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      }
      uVar3 = local_38[0] & 0xffffffff;
    }
  }
  return uVar3;
}



===== PciIdeGetNativeModeInterface @ 14000b78c =====

ulonglong PciIdeGetNativeModeInterface(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar2 = IoBuildSynchronousFsdRequest(0x1b,*param_1,0,0,0,local_38 + 2,local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_PCI_NATIVE_IDE_INTERFACE;
    *(undefined8 **)(lVar1 + -0x30) = param_1 + 0x4d;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0x10028;
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    uVar3 = IofCallDriver(*param_1);
    if (-1 < (int)uVar3) {
      if ((int)uVar3 == 0x103) {
        KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      }
      uVar3 = local_38[0] & 0xffffffff;
    }
  }
  return uVar3;
}



===== PopulateTimingTable @ 14000b880 =====

void PopulateTimingTable(longlong param_1,undefined4 *param_2,uint *param_3)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  bool bVar7;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  short *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  *param_2 = 600;
  param_2[1] = 0x17f;
  bVar7 = PciIdeDebugBypassRegistry == 0;
  param_2[3] = 0xb4;
  local_res10[0] = 0;
  param_2[2] = 0xf0;
  param_2[5] = 0x3c0;
  local_48 = 0;
  uStack_40 = 0;
  param_2[6] = 0x1e0;
  param_2[4] = 0x78;
  uVar5 = 0x12;
  param_2[10] = 0x78;
  param_2[0xb] = 0x78;
  param_2[7] = 0xf0;
  param_2[8] = 0x1e0;
  param_2[9] = 0x96;
  param_2[0xc] = 0x50;
  param_2[0xd] = 0x3c;
  param_2[0xe] = 0x2d;
  param_2[0xf] = 0x1e;
  param_2[0x10] = 0x14;
  param_2[0x11] = 0xf;
  if (bVar7) {
    RtlInitUnicodeString(&local_48);
    local_58 = (short *)0x0;
    local_res20[0] = 0;
    iVar3 = PortRegistryReadDeviceKey
                      (*(undefined8 *)(param_1 + 8),0,(longlong)&local_48,7,&local_58,local_res20);
    psVar2 = local_58;
    if ((-1 < iVar3) && (local_58 != (short *)0x0)) {
      local_58 = (short *)0x0;
      uStack_50 = 0;
      uVar4 = 0;
      sVar1 = *psVar2;
      psVar6 = psVar2;
      while (sVar1 != 0) {
        RtlInitUnicodeString(&local_58,psVar6);
        RtlUnicodeStringToInteger(&local_58,10,local_res10);
        if (uVar4 == 0) {
          uVar5 = local_res10[0];
          if (0x1f < local_res10[0]) {
            uVar5 = 0x1f;
          }
        }
        else {
          if (uVar5 < uVar4) break;
          if (local_res10[0] != 0) {
            param_2[uVar4 - 1] = local_res10[0];
          }
        }
        uVar4 = uVar4 + 1;
        psVar6 = psVar6 + ((ulonglong)local_58 >> 1 & 0x7fff) + 1;
        sVar1 = *psVar6;
      }
      uVar5 = uVar4 - 1;
      ExFreePoolWithTag(psVar2,0);
    }
  }
  *param_3 = uVar5;
  return;
}



===== PciIdeXInitialize @ 14000ba40 =====

void PciIdeXInitialize(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 *local_18 [2];
  
                    /* 0xba40  62  PciIdeXInitialize */
  local_18[0] = (undefined8 *)0x0;
  iVar1 = IoAllocateDriverObjectExtension(param_1,DriverEntry,0x50,local_18);
  if (-1 < iVar1) {
    *(undefined1 *)(local_18[0] + 7) = 0;
    *local_18[0] = param_3;
    *(undefined4 *)((longlong)local_18[0] + 0x3c) = param_4;
    PciIdeDriverEntry(param_1);
  }
  return;
}



===== DllInitialize @ 14000bac0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(void)

{
  int iVar1;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0xbac0  58  DllInitialize */
  __security_init_cookie();
  PciIdePopulateDispatchTables();
  local_1c = 0;
  local_res18[0] = 0;
  local_res10 = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,L"\\Device\\Ide");
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x250;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwCreateDirectoryObject(&local_res10,0xf000f,&local_38);
  if (-1 < iVar1) {
    ObReferenceObjectByHandle(local_res10,0x80,0,0,local_res18,0);
    ZwClose(local_res10);
  }
  KeInitializeSpinLock(&GlobalDeviceList);
  DAT_140007110 = &DAT_140007108;
  _DAT_140007108 = &DAT_140007108;
  return 0;
}



===== DllUnload @ 14000bbc0 =====

undefined8 DllUnload(void)

{
                    /* 0xbbc0  59  DllUnload */
  return 0;
}



===== PciIdeDispatchPnp @ 14000bbd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PciIdeDispatchPnp(longlong param_1,longlong param_2)

{
  byte bVar1;
  code *pcVar2;
  
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (bVar1 < 0x19) {
    pcVar2 = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) + (ulonglong)bVar1 * 8);
  }
  else {
    pcVar2 = *(code **)(*(longlong *)(param_1 + 0x40) + 0x20);
  }
  (*pcVar2)();
  return;
}



===== PciIdeDispatchWmi @ 14000bc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PciIdeDispatchWmi(longlong param_1,longlong param_2)

{
  byte bVar1;
  code *pcVar2;
  
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (bVar1 < 0xc) {
    pcVar2 = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38) + (ulonglong)bVar1 * 8);
  }
  else {
    pcVar2 = *(code **)(*(longlong *)(param_1 + 0x40) + 0x20);
  }
  (*pcVar2)();
  return;
}



===== PciIdeDriverEntry @ 14000bc4c =====

undefined8 PciIdeDriverEntry(longlong param_1)

{
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = ControllerAddDevice;
  *(code **)(param_1 + 0x68) = PciIdeUnload;
  *(code **)(param_1 + 0x120) = PciIdeDispatchPower;
  *(code **)(param_1 + 0x148) = PciIdeDispatchPnp;
  *(code **)(param_1 + 0x128) = PciIdeDispatchWmi;
  PciIdeRegisterEtw();
  return 0;
}



===== PciIdePopulateDispatchTables @ 14000bca8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PciIdePopulateDispatchTables(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  puVar2 = &FdoPnpDispatchTable;
  for (lVar1 = 0x19; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = GenPnpPassDownToNextDriver;
    puVar2 = puVar2 + 1;
  }
  FdoPnpDispatchTable = GenPnpFdoStartDevice;
  _DAT_140007140 = GenPnpFdoStopDevice;
  _DAT_1400071d8 = GenPnpFdoSurpriseRemoveDevice;
  _DAT_140007130 = GenPnpFdoRemoveDevice;
  _DAT_140007158 = ControllerQueryDeviceRelations;
  _DAT_140007160 = ControllerQueryInterface;
  _DAT_1400071d0 = GenPnpFdoUsageNotification;
  _DAT_1400071c0 = GenPnpFdoQueryPnPDeviceState;
  DAT_140007128 = GenPnpSuccessAndPassDown;
  _DAT_140007138 = GenPnpSuccessAndPassDown;
  _DAT_140007148 = GenPnpSuccessAndPassDown;
  _DAT_140007150 = GenPnpSuccessAndPassDown;
  puVar2 = &PdoPnpDispatchTable;
  for (lVar1 = 0x19; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = PortWdmNoSupportIrp;
    puVar2 = puVar2 + 1;
  }
  PdoPnpDispatchTable = GenPnpPdoStartDevice;
  _DAT_140007220 = GenPnpPdoStopDevice;
  _DAT_1400072b8 = GenPnpPdoSurpriseRemoveDevice;
  _DAT_140007210 = GenPnpPdoRemoveDevice;
  _DAT_140007238 = GenPnpPdoQueryDeviceRelations;
  DAT_140007208 = GenPnpPdoQueryRemoveDevice;
  _DAT_140007228 = GenPnpPdoQueryStopDevice;
  _DAT_140007218 = PortWdmAlwaysStatusSuccessIrp;
  _DAT_140007230 = PortWdmAlwaysStatusSuccessIrp;
  _DAT_140007248 = GenPnpPdoQueryCapabilities;
  _DAT_140007250 = ChannelQueryResources;
  _DAT_140007258 = ChannelQueryResourceRequirements;
  _DAT_140007260 = ChannelQueryText;
  _DAT_140007298 = ChannelQueryId;
  _DAT_140007240 = ChannelQueryInterface;
  _DAT_1400072b0 = GenPnpPdoUsageNotification;
  _DAT_1400072a0 = GenPnpPdoQueryPnPDeviceState;
  _DAT_140007268 = ChannelFilterResourceRequirements;
  _FdoPowerDispatchTable = GenPnpPassDownToNextDriver;
  pcRam00000001400073a8 = GenPnpPassDownToNextDriver;
  _DAT_1400073b0 = FdoSetPowerState;
  _DAT_1400073b8 = FdoQueryPowerState;
  _DAT_1400073d0 = PdoSetPowerState;
  _PdoPowerDispatchTable = PortWdmNoSupportIrp;
  pcRam00000001400073c8 = PortWdmNoSupportIrp;
  _DAT_1400073d8 = PdoQueryPowerState;
  puVar2 = &PdoWmiDispatchTable;
  for (lVar1 = 0xc; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = PortWdmNoSupportIrp;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &FdoWmiDispatchTable;
  for (lVar1 = 0xc; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = GenPnpPassDownToNextDriver;
    puVar2 = puVar2 + 1;
  }
  return;
}



===== PciIdeUnload @ 14000bf00 =====

void PciIdeUnload(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = IoGetDriverObjectExtension(param_1,DriverEntry);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x48) != 0)) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x48),0);
    *(undefined8 *)(lVar1 + 0x48) = 0;
    *(undefined4 *)(lVar1 + 0x40) = 0;
  }
  PciIdeUnregisterEtw();
  return;
}



===== ChannelBuildDeviceId @ 14000bf5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

short * ChannelBuildDeviceId(void)

{
  short sVar1;
  uint uVar2;
  longlong lVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  ulonglong uVar7;
  undefined1 auStack_58 [32];
  wchar_t local_38 [20];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  builtin_wcsncpy(local_38,L"PCIIDE\\IDEChannel",0x12);
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (local_38[lVar3] != L'\0');
  uVar2 = (int)lVar3 * 2 + 2;
  psVar4 = (short *)ExAllocatePoolWithTag(1,uVar2,0x58656449);
  if ((psVar4 != (short *)0x0) && (uVar7 = (ulonglong)(uVar2 >> 1), uVar7 != 0)) {
    lVar3 = 0x7ffffffe - uVar7;
    psVar6 = psVar4;
    do {
      if ((lVar3 + uVar7 == 0) ||
         (sVar1 = *(short *)(((longlong)local_38 - (longlong)psVar4) + (longlong)psVar6), sVar1 == 0
         )) break;
      *psVar6 = sVar1;
      psVar6 = psVar6 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    psVar5 = psVar6 + -1;
    if (uVar7 != 0) {
      psVar5 = psVar6;
    }
    *psVar5 = 0;
  }
  return psVar4;
}



===== ChannelBuildHardwareId @ 14000c040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t * ChannelBuildHardwareId(longlong param_1)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  undefined1 auStack_78 [32];
  wchar_t *local_58;
  undefined4 local_48;
  wchar_t local_40 [12];
  wchar_t local_28 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  uVar1 = PciIdeReadConfigSpace(*(longlong *)(param_1 + 0x58),&local_48,0,4);
  if ((int)uVar1 == 4) {
  }
  else {
    local_48._0_2_ = 0;
    local_48._2_2_ = 0;
    local_48 = 0;
  }
  uVar3 = local_48._2_2_;
  if ((ushort)local_48 == 0xe11) {
    pwVar7 = L"Compaq";
  }
  else if ((ushort)local_48 == 0x1039) {
    pwVar7 = L"SiS";
  }
  else if ((ushort)local_48 == 0x1095) {
    pwVar7 = L"CMD";
  }
  else if ((ushort)local_48 == 0x10ad) {
    pwVar7 = L"WinBond";
  }
  else if ((ushort)local_48 == 0x10b9) {
    pwVar7 = L"ALi";
  }
  else if ((ushort)local_48 == 0x8086) {
    pwVar7 = L"Intel";
    if (local_48._2_2_ == 0x1230) {
      pwVar8 = L"PIIX";
      goto LAB_14000c18a;
    }
    if (local_48._2_2_ == 0x7010) {
      pwVar8 = L"PIIX3";
      goto LAB_14000c18a;
    }
    if (local_48._2_2_ == 0x7111) {
      pwVar8 = L"PIIX4";
      goto LAB_14000c18a;
    }
  }
  else {
    uVar1 = RtlStringCbPrintfW(local_40,0x14,L"%04x",(ulonglong)(ushort)local_48);
    if ((int)uVar1 < 0) {
      return (wchar_t *)0x0;
    }
    pwVar7 = local_40;
    uVar3 = local_48._2_2_;
  }
  uVar1 = RtlStringCbPrintfW(local_28,0x14,L"%04x",(ulonglong)uVar3);
  if ((int)uVar1 < 0) {
    return (wchar_t *)0x0;
  }
  pwVar8 = local_28;
LAB_14000c18a:
  pwVar2 = (wchar_t *)ExAllocatePoolWithTag(1,0x212,0x58656449);
  if (pwVar2 != (wchar_t *)0x0) {
    local_58 = pwVar8;
    uVar1 = RtlStringCbPrintfW(pwVar2,0x212,L"%ws-%ws",pwVar7);
    if (-1 < (int)uVar1) {
      uVar5 = 0xffffffffffffffff;
      do {
        uVar5 = uVar5 + 1;
      } while (pwVar2[uVar5] != L'\0');
      iVar4 = (int)uVar5;
      uVar6 = (ulonglong)(iVar4 + 1);
      pwVar2[uVar5 & 0xffffffff] = L'\0';
      uVar1 = ChannelInternalCompatibleId._8_8_;
      *(undefined8 *)(pwVar2 + uVar6) = ChannelInternalCompatibleId._0_8_;
      *(undefined8 *)(pwVar2 + uVar6 + 4) = uVar1;
      uVar1 = ChannelInternalCompatibleId._24_8_;
      *(undefined8 *)(pwVar2 + uVar6 + 8) = ChannelInternalCompatibleId._16_8_;
      *(undefined8 *)(pwVar2 + uVar6 + 8 + 4) = uVar1;
      *(undefined8 *)(pwVar2 + uVar6 + 0x10) = ChannelInternalCompatibleId._32_8_;
      pwVar2[uVar6 + 0x14] = ChannelInternalCompatibleId[0x14];
      pwVar2[iVar4 + 0x16] = L'\0';
      uVar1 = uRam00000001400070b8;
      *(undefined8 *)(pwVar2 + (iVar4 + 0x17)) = _ChannelCompatibleId;
      *(undefined8 *)(pwVar2 + (iVar4 + 0x17) + 4) = uVar1;
      pwVar2[(ulonglong)(iVar4 + 0x17) + 8] = DAT_1400070c0;
      pwVar2[iVar4 + 0x20] = L'\0';
      pwVar2[iVar4 + 0x21] = L'\0';
      return pwVar2;
    }
    ExFreePoolWithTag(pwVar2,0);
  }
  return (wchar_t *)0x0;
}



===== ChannelCreatePdoCallBack @ 14000c288 =====

undefined8 ChannelCreatePdoCallBack(longlong param_1,undefined1 *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined1 *)(lVar1 + 0xe4) = *param_2;
  *(code **)(lVar1 + 0x20) = PortWdmNoSupportIrp;
  *(undefined8 **)(lVar1 + 0x28) = &PdoPnpDispatchTable;
  *(undefined **)(lVar1 + 0x30) = &PdoPowerDispatchTable;
  *(undefined8 **)(lVar1 + 0x38) = &PdoWmiDispatchTable;
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffff7f;
  return 0;
}



===== ChannelQueryId @ 14000c2d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ChannelQueryId(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStack_48 [32];
  wchar_t local_28 [4];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0xc0000001;
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (iVar1 == 0) {
    pwVar4 = ChannelBuildDeviceId();
  }
  else if (iVar1 == 1) {
    pwVar4 = ChannelBuildHardwareId(lVar2);
  }
  else if (iVar1 == 2) {
    pwVar4 = (wchar_t *)ExAllocatePoolWithTag(1,0x16,0x58656449);
    uVar3 = uRam00000001400070b8;
    if (pwVar4 != (wchar_t *)0x0) {
      *(undefined8 *)pwVar4 = _ChannelCompatibleId;
      *(undefined8 *)(pwVar4 + 4) = uVar3;
      pwVar4[8] = DAT_1400070c0;
      pwVar4[9] = L'\0';
      pwVar4[10] = L'\0';
    }
  }
  else {
    if (iVar1 != 3) {
      uVar5 = 0xc00000bb;
      goto LAB_14000c3de;
    }
    local_28[0] = L'%';
    local_28[1] = L'd';
    local_28[2] = 0;
    pwVar4 = (wchar_t *)ExAllocatePoolWithTag(1,0x14,0x58656449);
    if (pwVar4 != (wchar_t *)0x0) {
      RtlStringCbPrintfW(pwVar4,0x14,local_28,(ulonglong)*(byte *)(lVar2 + 0xe4));
    }
  }
  if (pwVar4 != (wchar_t *)0x0) {
    *(wchar_t **)(param_2 + 0x38) = pwVar4;
    uVar5 = 0;
  }
LAB_14000c3de:
  *(undefined4 *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== ChannelQueryText @ 14000c420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChannelQueryText(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_128 = 0;
  uStack_120 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (iVar2 == 0) {
    pcVar4 = "ATA Channel %d";
  }
  else {
    if (iVar2 != 1) {
      iVar2 = -0x3fffff45;
      goto LAB_14000c4eb;
    }
    pcVar4 = "Channel %d";
  }
  uVar3 = RtlStringCbPrintfA(local_118,0x100,pcVar4,(ulonglong)*(byte *)(lVar1 + 0xe4));
  if ((int)uVar3 < 0) {
    return -0x3fffff66;
  }
  local_138 = 0;
  uStack_130 = 0;
  RtlInitAnsiString(&local_138,local_118);
  iVar2 = RtlAnsiStringToUnicodeString(&local_128,&local_138,1);
  if (-1 < iVar2) {
    *(undefined8 *)(param_2 + 0x38) = uStack_120;
  }
LAB_14000c4eb:
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== ChannelStartDevice @ 14000c52c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ChannelStartDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStack_88 [32];
  uint local_68 [4];
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined2 local_50;
  undefined1 local_4d;
  undefined4 local_44;
  undefined4 local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x58);
  *(undefined4 *)(lVar1 + 0xf0) = 1;
  if (*(char *)(lVar2 + 0x1b0) == '\0') {
    uVar5 = BusMasterUninitialize(lVar1);
    uVar5 = uVar5 & 0xffffffff;
  }
  else {
    local_68[0] = 0;
    memset(local_58,0,0x40);
    local_4d = *(undefined1 *)(lVar2 + 0x1af);
    local_38 = *(undefined4 *)(lVar2 + 0x1a8);
    local_54 = 0x101;
    local_50 = 1;
    local_44 = 5;
    lVar3 = IoGetDmaAdapter(*(undefined8 *)(lVar2 + 8),local_58,local_68);
    *(longlong *)(lVar1 + 0xe8) = lVar3;
    if (lVar3 == 0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar4 = (uint)(byte)(*(char *)(lVar2 + 0x1ac) + 1);
      if (uVar4 < local_68[0]) {
        local_68[0] = uVar4;
      }
      *(uint *)(lVar1 + 0xf0) = local_68[0];
    }
  }
  return uVar5;
}



===== ChannelStopRemoveDevice @ 14000c628 =====

undefined8 ChannelStopRemoveDevice(longlong param_1)

{
  BusMasterUninitialize(*(longlong *)(param_1 + 0x40));
  return 0;
}



===== ControllerAddDevice @ 14000c650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ControllerAddDevice(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStackY_c8 [32];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  uVar3 = DAT_1400070f4;
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  LOCK();
  UNLOCK();
  uVar8 = (ulonglong)DAT_1400070f4;
  DAT_1400070f4 = DAT_1400070f4 + 1;
  uVar4 = RtlStringCbPrintfW(local_98,0x80,L"\\Device\\Ide\\PciIde%d",uVar8);
  if ((((((int)uVar4 < 0) || (lVar5 = IoGetDriverObjectExtension(param_1,DriverEntry), lVar5 == 0))
       || (uVar7 = *(int *)(lVar5 + 0xc) + 0x378, uVar7 < 0x378)) ||
      ((*(byte *)(lVar5 + 0x38) < 2 && (uVar7 = *(int *)(lVar5 + 0x3c) + 0x378, uVar7 < 0x378)))) ||
     (lVar5 = GenPnpAllocateFdo(param_1,param_2,local_98,uVar8,uVar7), lVar5 == 0)) {
    return 0xc0000001;
  }
  lVar6 = *(longlong *)(lVar5 + 0x40);
  *(code **)(lVar6 + 0x20) = GenPnpPassDownToNextDriver;
  *(undefined8 **)(lVar6 + 0x28) = &FdoPnpDispatchTable;
  *(undefined **)(lVar6 + 0x30) = &FdoPowerDispatchTable;
  *(undefined8 **)(lVar6 + 0x38) = &FdoWmiDispatchTable;
  *(longlong *)(lVar6 + 0xe8) = lVar6 + 0x378;
  *(uint *)(lVar6 + 0xe4) = uVar3;
  puVar1 = *(undefined8 **)(lVar5 + 0x40);
  PciIdeGetBusStandardInterface(puVar1);
  KeInitializeSpinLock(puVar1 + 0x46);
  KeInitializeSpinLock(puVar1 + 0x55);
  uVar3 = ControllerInitControllerInfo((longlong)puVar1);
  if (-1 < (int)uVar3) {
    if (*(byte *)((longlong)puVar1 + 0x1b1) < 2) {
      if (*(char *)((longlong)puVar1 + 0x1ae) != '\0') {
        PciIdeGetNativeModeInterface(puVar1);
        if ((code *)puVar1[0x51] != (code *)0x0) {
          (*(code *)puVar1[0x51])(puVar1[0x4e],0);
        }
      }
      uVar3 = 0;
      if (((code *)puVar1[0x3a] != (code *)0x0) &&
         (cVar2 = (*(code *)puVar1[0x3a])(puVar1[0x1d]), cVar2 != '\0')) {
        lVar6 = IoCreateController(0);
        puVar1[0x54] = lVar6;
        uVar3 = ~-(uint)(lVar6 != 0) & 0xc000009a;
      }
    }
    *(uint *)(lVar5 + 0x30) = *(uint *)(lVar5 + 0x30) & 0xffffff7f;
  }
  return uVar3;
}



===== ControllerInitControllerInfo @ 14000c844 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ControllerInitControllerInfo(longlong param_1)

{
  byte bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_c8 [32];
  undefined4 local_a8 [6];
  undefined8 local_90;
  undefined8 local_80;
  undefined2 local_78;
  char local_76;
  byte local_75;
  undefined8 local_70;
  uint local_68;
  int local_64;
  undefined8 local_60;
  undefined1 local_58 [9];
  byte local_4f;
  char local_4e;
  char local_4d;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(local_a8,0,0x50);
  plVar3 = (longlong *)IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 0x10));
  iVar2 = 0;
  bVar1 = *(byte *)(plVar3 + 7);
  *(byte *)(param_1 + 0x1b1) = bVar1;
  if (bVar1 < 2) {
    iVar2 = 0;
    if (*plVar3 != 0) {
      local_64 = 0;
      local_75 = local_75 & 0xfc;
      local_a8[0] = 0x50;
      local_78 = 0;
      local_76 = '\0';
      iVar2 = (*(code *)*plVar3)(*(undefined8 *)(param_1 + 0xe8));
    }
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  *(undefined1 *)(param_1 + 0x1ad) = 2;
  if (*(byte *)(param_1 + 0x1b1) < 2) {
    memset(local_58,0,0x40);
    *(undefined8 *)(param_1 + 0x1c0) = local_90;
    *(undefined8 *)(param_1 + 0x1c8) = local_80;
    *(undefined8 *)(param_1 + 0x1d8) = local_70;
    *(undefined8 *)(param_1 + 0x1e0) = local_60;
    *(undefined1 *)(param_1 + 0x1ae) = 0;
    *(undefined1 *)(param_1 + 0x1b0) = 0;
    uVar4 = PciIdeReadConfigSpace(param_1,local_58,0,0x40);
    if ((int)uVar4 == 0x40) {
      if ((local_4d == '\x01') &&
         (((local_4e - 4U & 0xfd) == 0 ||
          (((local_4e == '\x01' && ((local_4f & 1) != 0)) && ((local_4f & 4) != 0)))))) {
        *(undefined1 *)(param_1 + 0x1ae) = 1;
      }
      if ((char)local_4f < '\0') {
        *(undefined1 *)(param_1 + 0x1b0) = 1;
      }
    }
    *(undefined1 *)(param_1 + 0x1ac) = 0x22;
    *(undefined4 *)(param_1 + 0x1a8) = 0x20000;
    uVar5 = (uint)(local_64 != 0);
    if (local_78._1_1_ != '\0') {
      uVar5 = uVar5 | 2;
    }
    if ((char)local_78 != '\0') {
      uVar5 = uVar5 | 4;
    }
    if (local_76 != '\0') {
      uVar5 = uVar5 | 8;
    }
    uVar6 = uVar5 | 0x10;
    if ((local_75 & 1) == 0) {
      uVar6 = uVar5;
    }
    uVar5 = uVar6 | 0x20;
    if ((local_75 & 2) == 0) {
      uVar5 = uVar6;
    }
    *(uint *)(param_1 + 0x1a4) = uVar5;
    uVar5 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x98);
    if (local_68 < uVar5) {
      local_68 = uVar5;
    }
    *(uint *)(*(longlong *)(param_1 + 0x18) + 0x98) = local_68;
  }
  else {
    *(undefined1 *)(param_1 + 0x1ac) = 0x22;
    *(undefined2 *)(param_1 + 0x1ae) = 1;
    *(undefined1 *)(param_1 + 0x1b0) = 1;
    *(undefined4 *)(param_1 + 0x1a8) = 0x20000;
    *(int *)(param_1 + 0x1a0) = (int)plVar3[2];
    *(longlong *)(param_1 + 0x1b8) = plVar3[3];
    *(longlong *)(param_1 + 0x1c0) = plVar3[4];
    *(longlong *)(param_1 + 0x1c8) = plVar3[5];
    *(longlong *)(param_1 + 0x1e0) = plVar3[6];
    uVar5 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x98);
    if (uVar5 <= *(uint *)((longlong)plVar3 + 0x14)) {
      uVar5 = *(uint *)((longlong)plVar3 + 0x14);
    }
    *(uint *)(*(longlong *)(param_1 + 0x18) + 0x98) = uVar5;
  }
  return iVar2;
}



===== ControllerQueryBusRelations @ 14000caa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ControllerQueryBusRelations(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint *puVar7;
  byte bVar8;
  undefined1 auStack_278 [32];
  uint local_258;
  byte *local_250;
  byte local_248 [16];
  wchar_t local_238 [256];
  ulonglong local_38;
  
  if (param_2 != 0) {
    local_38 = __security_cookie ^ (ulonglong)auStack_278;
    puVar2 = *(undefined8 **)(param_1 + 0x40);
    bVar8 = 0;
    lVar3 = *(longlong *)(param_2 + 8);
    bVar1 = *(byte *)((longlong)puVar2 + 0x1ad);
    if (bVar1 != 0) {
      do {
        uVar4 = PciIdeChannelEnabled((longlong)puVar2,bVar8);
        lVar5 = GenPnpRefPdoExtensionWithTag((longlong)puVar2,(ulonglong)bVar8);
        if (lVar5 == 0) {
          if (((int)uVar4 == 1) &&
             (local_258 = (uint)bVar8, local_248[0] = bVar8,
             uVar6 = RtlStringCbPrintfW(local_238,0x200,L"\\Device\\Ide\\PciIde%dChannel%d",
                                        (ulonglong)*(uint *)((longlong)puVar2 + 0xe4)),
             -1 < (int)uVar6)) {
            local_250 = local_248;
            local_258 = (uint)bVar8;
            GenPnpAllocatePdo((longlong)puVar2);
          }
        }
        else {
          if ((int)uVar4 == 0) {
            *(undefined1 *)(lVar5 + 0xdb) = 1;
          }
          GenPnpUnRefPdoExtensionWithTag(lVar5,ControllerQueryBusRelations);
        }
        bVar8 = bVar8 + 1;
      } while (bVar8 < bVar1);
    }
    puVar7 = GenPnpBuildDeviceRelations(puVar2[3],lVar3);
    if (puVar7 == (uint *)0x0) {
      *(undefined4 *)(lVar3 + 0x30) = 0xc000009a;
      IofCompleteRequest(lVar3,0);
    }
    else {
      *(undefined4 *)(lVar3 + 0x30) = 0;
      *(char *)(lVar3 + 0x43) = *(char *)(lVar3 + 0x43) + '\x01';
      *(longlong *)(lVar3 + 0xb8) = *(longlong *)(lVar3 + 0xb8) + 0x48;
      *(uint **)(lVar3 + 0x38) = puVar7;
      IofCallDriver(*puVar2,lVar3);
    }
  }
  return;
}



===== ControllerQueryDeviceRelations @ 14000cc00 =====

undefined4 ControllerQueryDeviceRelations(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    puVar2[0x53] = param_2;
    uVar3 = 0x103;
    *(undefined4 *)(param_2 + 0x30) = 0x103;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    IoQueueWorkItem(puVar2[0x52],ControllerQueryBusRelations,1,puVar2 + 0x52);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*puVar2);
  }
  return uVar3;
}



===== ControllerQueryInterface @ 14000cc90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ControllerQueryInterface(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  if ((((**(longlong **)(lVar1 + 8) == 0x11d0aacf6c154a92) &&
       ((*(longlong **)(lVar1 + 8))[1] == 0x44b206c9a0002a8d)) && (0x2f < *(ushort *)(lVar1 + 0x10))
      ) && ((*(int *)(lVar1 + 0x20) == 2 && (*(char *)((longlong)puVar2 + 0x1ae) == '\0')))) {
    uVar3 = (**(code **)(HalDispatchTable_exref + 0x78))
                      (5,0,0xffffffff,*(ushort *)(lVar1 + 0x10),*(undefined2 *)(lVar1 + 0x12),
                       *(undefined8 *)(lVar1 + 0x18),local_res8);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCallDriver(*puVar2,param_2);
  return;
}



===== ControllerRemoveDevice @ 14000cd58 =====

undefined8 ControllerRemoveDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  ControllerStopDevice(param_1,param_2);
  if (*(longlong *)(lVar1 + 0x290) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x290) = 0;
  }
  if (*(longlong *)(lVar1 + 0x2a0) != 0) {
    IoDeleteController();
    *(undefined8 *)(lVar1 + 0x2a0) = 0;
  }
  return 0;
}



===== ControllerStartDevice @ 14000cdb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ControllerStartDevice(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  byte bVar7;
  byte bVar8;
  uint *puVar9;
  undefined1 auStack_58 [32];
  uint local_38 [6];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  puVar9 = *(uint **)param_2;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = param_2[2];
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (puVar9 != (uint *)0x0) {
    uVar3 = PortWdmSizeOfCmResourceList(puVar9);
    _Dst = (uint *)ExAllocatePool2(0x100,uVar3,0x6c576c50);
    if (_Dst == (uint *)0x0) {
      *(undefined8 *)(lVar1 + 0xf0) = 0;
      return 0xc000009a;
    }
    memcpy(_Dst,puVar9,(ulonglong)uVar3);
    *(uint **)(lVar1 + 0xf0) = _Dst;
    uVar4 = GenPopulateAccessRange(_Dst,lVar1 + 0x108);
    *(int *)(lVar1 + 0x198) = (int)uVar4;
    puVar9 = local_38;
    uVar3 = 0;
    do {
      param_2 = puVar9;
      PciIdeReadConfigSpace(lVar1,puVar9,uVar3 * 4 + 0x10,4);
      *puVar9 = *puVar9 & 0xfffffffd;
      bVar7 = (char)uVar3 + 1;
      uVar3 = (uint)bVar7;
      puVar9 = puVar9 + 1;
    } while (bVar7 < 6);
    uVar4 = 0;
    uVar3 = 0;
    if (*(int *)(lVar1 + 0x198) != 0) {
      do {
        if (*(char *)(lVar1 + 0x11c + uVar4 * 0x18) == '\x01') {
          param_2 = (uint *)((ulonglong)param_2 & 0xffffffffffffff00);
          do {
            if (*(ulonglong *)(lVar1 + 0x110 + uVar4 * 0x18) ==
                (ulonglong)local_38[(ulonglong)param_2 & 0xff]) {
              *(char *)(lVar1 + 0x11d + uVar4 * 0x18) = (char)param_2;
              break;
            }
            bVar7 = (char)param_2 + 1;
            param_2 = (uint *)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar7);
          } while (bVar7 < 6);
          if ((char)param_2 == '\x06') {
            *(undefined1 *)(lVar1 + 0x11d + uVar4 * 0x18) = 0xfe;
          }
        }
        else {
          *(undefined1 *)(lVar1 + 0x11d + uVar4 * 0x18) = 0xff;
        }
        uVar3 = *(uint *)(lVar1 + 0x198);
        bVar7 = (char)uVar4 + 1;
        uVar4 = (ulonglong)bVar7;
      } while (bVar7 < uVar3);
    }
    *(longlong *)(lVar1 + 0x100) = lVar1 + 0x108;
    *(uint *)(lVar1 + 0xf8) = uVar3;
  }
  if (*(byte *)(lVar1 + 0x1b1) < 2) {
    uVar4 = 0;
    if (*(char *)(lVar1 + 0x1ae) != '\0') {
      bVar7 = *(byte *)(lVar1 + 0x1ad);
      bVar8 = 0;
      if (bVar7 != 0) {
        do {
          param_2 = (uint *)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar8);
          uVar5 = PciIdeChannelEnabled(lVar1,bVar8);
          if ((int)uVar5 != 0) {
            param_2 = (uint *)CONCAT71((int7)((ulonglong)param_2 >> 8),bVar8);
            uVar3 = ControllerInterruptControl(lVar1,(ulonglong)param_2,'\x01');
            uVar4 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) goto LAB_14000cf94;
          }
          bVar8 = bVar8 + 1;
        } while (bVar8 < bVar7);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
      }
      if (*(code **)(lVar1 + 0x288) != (code *)0x0) {
        (**(code **)(lVar1 + 0x288))(*(undefined8 *)(lVar1 + 0x270),1);
      }
    }
  }
  else {
    uVar4 = ControllerStartMiniport(lVar1);
    uVar4 = uVar4 & 0xffffffff;
  }
LAB_14000cf94:
  uVar3 = (uint)uVar4;
  if (((-1 < (int)uVar3) && ((char)uVar2 == '\0')) && (*(longlong *)(lVar1 + 0x290) == 0)) {
    lVar6 = IoAllocateWorkItem(*(undefined8 *)(lVar1 + 0x18));
    *(longlong *)(lVar1 + 0x290) = lVar6;
    if (lVar6 == 0) {
      uVar3 = 0xc000009a;
    }
    uVar4 = (ulonglong)uVar3;
  }
  return uVar4;
}



===== ControllerStartMiniport @ 14000cff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerStartMiniport(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_28;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  longlong lStack_10;
  
  uVar2 = 0;
  if (*(code **)(param_1 + 0x1e0) != (code *)0x0) {
    local_28 = (ulonglong)CONCAT12(*(undefined1 *)(param_1 + 0x1ad),0x20);
    _uStack_20 = CONCAT44(*(undefined4 *)(param_1 + 0x1a8),(uint)*(byte *)(param_1 + 0x1ac));
    local_18 = (ulonglong)*(uint3 *)(param_1 + 0x1ae) << 8;
    lStack_10 = param_1 + 0xf8;
    cVar1 = (**(code **)(param_1 + 0x1e0))(*(undefined8 *)(param_1 + 0xe8),0,&local_28);
    if (cVar1 == '\0') {
      uVar2 = 0xc0000059;
    }
    else {
      *(undefined1 *)(param_1 + 0x1ad) = local_28._2_1_;
      *(undefined1 *)(param_1 + 0x1ac) = (undefined1)uStack_20;
      *(undefined4 *)(param_1 + 0x1a8) = uStack_1c;
      *(undefined1 *)(param_1 + 0x1ae) = local_18._1_1_;
      *(undefined1 *)(param_1 + 0x1b0) = local_18._3_1_;
      *(undefined1 *)(param_1 + 0x1af) = local_18._2_1_;
      *(undefined4 *)(param_1 + 0x1e8) = local_18._4_4_;
    }
  }
  return uVar2;
}



===== ControllerStopDevice @ 14000d0ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerStopDevice(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  byte bVar4;
  undefined4 *puVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(byte *)(lVar2 + 0x1b1) < 2) {
    if (*(char *)(lVar2 + 0x1ae) != '\0') {
      bVar1 = *(byte *)(lVar2 + 0x1ad);
      if (*(code **)(lVar2 + 0x288) != (code *)0x0) {
        param_2 = 0;
        (**(code **)(lVar2 + 0x288))(*(undefined8 *)(lVar2 + 0x270),0);
      }
      bVar4 = 0;
      if (bVar1 != 0) {
        do {
          param_2 = CONCAT71((int7)(param_2 >> 8),bVar4);
          ControllerInterruptControl(lVar2,param_2,'\0');
          bVar4 = bVar4 + 1;
        } while (bVar4 < bVar1);
      }
    }
  }
  else if (*(code **)(lVar2 + 0x1e0) != (code *)0x0) {
    (**(code **)(lVar2 + 0x1e0))(*(undefined8 *)(lVar2 + 0xe8),1);
  }
  if (*(uint *)(lVar2 + 0x198) != 0) {
    puVar5 = (undefined4 *)(lVar2 + 0x118);
    uVar3 = (ulonglong)*(uint *)(lVar2 + 0x198);
    do {
      if (*(char *)(puVar5 + 1) != '\0') {
        MmUnmapIoSpace(*(undefined8 *)(puVar5 + -4),*puVar5);
      }
      *(undefined8 *)(puVar5 + -4) = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 6;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *(undefined4 *)(lVar2 + 0xf8) = 0;
  *(undefined8 *)(lVar2 + 0x100) = 0;
  *(undefined4 *)(lVar2 + 0x198) = 0;
  if (*(longlong *)(lVar2 + 0xf0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar2 + 0xf0),0);
    *(undefined8 *)(lVar2 + 0xf0) = 0;
  }
  return 0;
}



===== AtaPortInitializeEx @ 14000d210 =====

int AtaPortInitializeEx(longlong param_1,ushort *param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  void *pvVar5;
  int iVar6;
  longlong lVar7;
  void *local_res8;
  
                    /* 0xd210  17  AtaPortInitializeEx */
  local_res8 = (void *)0x0;
  iVar6 = IoAllocateDriverObjectExtension(param_1,DriverEntry,0x50,&local_res8);
  if (-1 < iVar6) {
    memset(local_res8,0,0x50);
    pvVar5 = local_res8;
    *(undefined1 *)((longlong)local_res8 + 0x38) = 2;
    uVar4 = param_3[1];
    *(undefined8 *)((longlong)local_res8 + 8) = *param_3;
    *(undefined8 *)((longlong)local_res8 + 0x10) = uVar4;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0x14);
    uVar2 = *(undefined4 *)(param_3 + 3);
    uVar3 = *(undefined4 *)((longlong)param_3 + 0x1c);
    *(undefined4 *)((longlong)local_res8 + 0x18) = *(undefined4 *)(param_3 + 2);
    *(undefined4 *)((longlong)local_res8 + 0x1c) = uVar1;
    *(undefined4 *)((longlong)local_res8 + 0x20) = uVar2;
    *(undefined4 *)((longlong)local_res8 + 0x24) = uVar3;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0x24);
    uVar2 = *(undefined4 *)(param_3 + 5);
    uVar3 = *(undefined4 *)((longlong)param_3 + 0x2c);
    *(undefined4 *)((longlong)local_res8 + 0x28) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)((longlong)local_res8 + 0x2c) = uVar1;
    *(undefined4 *)((longlong)local_res8 + 0x30) = uVar2;
    *(undefined4 *)((longlong)local_res8 + 0x34) = uVar3;
    lVar7 = ExAllocatePoolWithTag(0x200,(ulonglong)*param_2 * 2,0x58656449);
    *(longlong *)((longlong)pvVar5 + 0x48) = lVar7;
    if (lVar7 != 0) {
      *(undefined2 *)((longlong)pvVar5 + 0x40) = 0;
      *(ushort *)((longlong)pvVar5 + 0x42) = *param_2;
      RtlCopyUnicodeString((undefined2 *)((longlong)pvVar5 + 0x40),param_2);
    }
    PciIdeDriverEntry(param_1);
  }
  return iVar6;
}



===== ChannelFilterResourceRequirements @ 14000d300 =====

undefined4 ChannelFilterResourceRequirements(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== ChannelQueryResourceRequirements @ 14000d330 =====

undefined4 ChannelQueryResourceRequirements(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined4 *_Dst;
  undefined4 uVar3;
  undefined4 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (*(char *)(*(longlong *)(lVar2 + 0x58) + 0x1ae) == '\0') {
    _Dst = (undefined4 *)ExAllocatePoolWithTag(1,0x88,0x58656449);
    if (_Dst == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
      uVar4 = 0xc0000017;
      goto LAB_14000d5d9;
    }
    memset(_Dst,0,0x88);
    *_Dst = 0x88;
    _Dst[1] = 1;
    _Dst[7] = 1;
    *(undefined8 *)(_Dst + 8) = 0x10001;
    cVar1 = *(char *)(lVar2 + 0xe4);
    if (cVar1 == '\0') {
      *(undefined2 *)(_Dst + 10) = 0x101;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x2a + (longlong)_Dst) = 1;
      *(undefined2 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xb) = 0x11;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xc] = 8;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xd] = 1;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xe) = 0x1f0;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0x10) = 0x1f7;
      _Dst[9] = _Dst[9] + 1;
      *(undefined1 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 10) = 1;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x29 + (longlong)_Dst) = 1;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x2a + (longlong)_Dst) = 1;
      *(undefined2 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xb) = 0x11;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xc] = 1;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xd] = 1;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xe) = 0x3f6;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0x10) = 0x3f6;
      uVar3 = 0xe;
LAB_14000d56f:
      _Dst[9] = _Dst[9] + 1;
      *(undefined1 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 10) = 1;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x29 + (longlong)_Dst) = 2;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x2a + (longlong)_Dst) = 1;
      *(undefined2 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xb) = 1;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xc] = uVar3;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xd] = uVar3;
      _Dst[9] = _Dst[9] + 1;
      if (_Dst[9] != 0) goto LAB_14000d5d9;
    }
    else if (cVar1 == '\x01') {
      *(undefined2 *)(_Dst + 10) = 0x101;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x2a + (longlong)_Dst) = 1;
      *(undefined2 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xb) = 0x11;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xc] = 8;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xd] = 1;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xe) = 0x170;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0x10) = 0x177;
      _Dst[9] = _Dst[9] + 1;
      *(undefined1 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 10) = 1;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x29 + (longlong)_Dst) = 1;
      *(undefined1 *)((ulonglong)(uint)_Dst[9] * 0x20 + 0x2a + (longlong)_Dst) = 1;
      *(undefined2 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xb) = 0x11;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xc] = 1;
      _Dst[(ulonglong)(uint)_Dst[9] * 8 + 0xd] = 1;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0xe) = 0x376;
      *(undefined8 *)(_Dst + (ulonglong)(uint)_Dst[9] * 8 + 0x10) = 0x376;
      uVar3 = 0xf;
      goto LAB_14000d56f;
    }
    ExFreePoolWithTag(_Dst,0);
  }
  _Dst = (undefined4 *)0x0;
LAB_14000d5d9:
  *(undefined4 **)(param_2 + 0x38) = _Dst;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== ChannelQueryResources @ 14000d620 =====

undefined4 ChannelQueryResources(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 *_Dst;
  undefined4 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (*(char *)(*(longlong *)(lVar2 + 0x58) + 0x1ae) == '\0') {
    _Dst = (undefined4 *)ExAllocatePoolWithTag(1,0x50,0x58656449);
    if (_Dst == (undefined4 *)0x0) {
      uVar4 = 0xc0000017;
      goto LAB_14000d72c;
    }
    memset(_Dst,0,0x50);
    *_Dst = 1;
    *(undefined8 *)(_Dst + 1) = 1;
    _Dst[4] = 0;
    cVar1 = *(char *)(lVar2 + 0xe4);
    if (cVar1 == '\0') {
      _Dst[5] = 0x110101;
      uVar3 = 0xe;
      *(undefined8 *)(_Dst + 6) = 0x1f0;
      _Dst[8] = 8;
      *(undefined8 *)(_Dst + 0xb) = 0x3f6;
    }
    else {
      if (cVar1 != '\x01') {
        _Dst[4] = 0;
        ExFreePoolWithTag(_Dst,0);
        goto LAB_14000d729;
      }
      _Dst[5] = 0x110101;
      uVar3 = 0xf;
      *(undefined8 *)(_Dst + 6) = 0x170;
      _Dst[8] = 8;
      *(undefined8 *)(_Dst + 0xb) = 0x376;
    }
    _Dst[10] = 0x110101;
    _Dst[0xd] = 1;
    _Dst[0xf] = 0x10102;
    _Dst[0x10] = uVar3;
    _Dst[0x11] = uVar3;
    *(undefined8 *)(_Dst + 0x12) = 1;
    _Dst[4] = 3;
  }
  else {
LAB_14000d729:
    _Dst = (undefined4 *)0x0;
  }
LAB_14000d72c:
  *(undefined4 **)(param_2 + 0x38) = _Dst;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== PciIdeChannelEnabled @ 14000d768 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PciIdeChannelEnabled(longlong param_1,byte param_2)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint local_res8 [2];
  undefined4 local_res18 [2];
  
  pcVar1 = *(code **)(param_1 + 0x1c0);
  if (*(byte *)(param_1 + 0x1b1) < 2) {
    if (pcVar1 != (code *)0x0) {
      uVar4 = (*pcVar1)(*(undefined8 *)(param_1 + 0xe8),param_2);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      if ((int)uVar4 == 1) {
        return 1;
      }
    }
  }
  else {
    uVar4 = 2;
    if (pcVar1 != (code *)0x0) {
      uVar4 = (*pcVar1)(*(undefined8 *)(param_1 + 0xe8),param_2);
    }
    if ((int)uVar4 != 2) {
      return uVar4;
    }
  }
  if (*(byte *)(param_1 + 0x1ad) < 3) {
    local_res8[0] = 0;
    iVar3 = PciIdeRegReadDwordDeviceKey(param_1,param_2,L"ChannelStateMask",local_res8);
    if (-1 < iVar3) {
      local_res18[0] = 0;
      bVar2 = (byte)local_res8[0];
      iVar3 = PciIdeRegReadDwordDeviceKey(param_1,param_2,L"ChannelStateOffset",local_res18);
      if (-1 < iVar3) {
        local_res8[0] = local_res8[0] & 0xffffff00;
        uVar5 = PciIdeReadConfigSpace(param_1,local_res8,local_res18[0],1);
        if ((int)uVar5 == 1) {
          return (ulonglong)(((byte)local_res8[0] & bVar2) != 0);
        }
      }
    }
  }
  return 1;
}



===== PciIdeRegReadDwordDeviceKey @ 14000d870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PciIdeRegReadDwordDeviceKey
              (longlong param_1,byte param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_b8 [32];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  wchar_t local_58 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (PciIdeDebugBypassRegistry == 0) {
    local_84 = 4;
    local_80 = &local_88;
    if (param_2 == 0xff) {
      puVar3 = (undefined8 *)0x0;
    }
    else {
      uVar2 = RtlStringCbPrintfW(local_58,0x20,L"Channel%d\\",(ulonglong)param_2);
      if ((int)uVar2 < 0) {
        return -0x3fffff66;
      }
      RtlInitUnicodeString(&local_78,local_58);
      puVar3 = &local_78;
    }
    RtlInitUnicodeString(&local_68,param_3);
    iVar1 = PortRegistryReadDeviceKey
                      (*(undefined8 *)(param_1 + 8),(longlong)puVar3,(longlong)&local_68,4,&local_80
                       ,&local_84);
    if (-1 < iVar1) {
      *param_4 = local_88;
    }
  }
  else {
    iVar1 = -0x3fffffff;
  }
  return iVar1;
}



===== PortWdmAlwaysStatusSuccessIrp @ 14000d980 =====

undefined8 PortWdmAlwaysStatusSuccessIrp(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PortWdmForwardIrpSynchronous @ 14000d9a8 =====

ulonglong PortWdmForwardIrpSynchronous(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = PortWdmSetEventCompletionRoutine;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar3 = IofCallDriver(param_1,param_2);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar3;
}



===== PortWdmGetDeviceCapabilities @ 14000da78 =====

int PortWdmGetDeviceCapabilities(undefined8 param_1,undefined4 *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined2 *_Dst;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  memset(param_2,0,0x40);
  *param_2 = 0x10040;
  param_2[3] = 0xffffffff;
  param_2[2] = 0xffffffff;
  KeInitializeEvent(&local_28,1,0);
  uVar3 = IoGetAttachedDeviceReference(param_1);
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_28,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar4 + 0x38) = 0;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    _Dst = (undefined2 *)(lVar1 + -0x48);
    if (_Dst == (undefined2 *)0x0) {
      iVar2 = -0x3ffffff3;
    }
    else {
      memset(_Dst,0,0x48);
      *_Dst = 0x91b;
      *(undefined4 **)(lVar1 + -0x40) = param_2;
      iVar2 = IofCallDriver(uVar3,lVar4);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(&local_28,0,0,0,0);
        iVar2 = (int)local_38;
      }
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== PortWdmNoSupportIrp @ 14000dbe0 =====

undefined4 PortWdmNoSupportIrp(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if (**(char **)(param_2 + 0xb8) == '\x16') {
    PoStartNextPowerIrp(param_2);
  }
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== PortWdmPassDownToNextDriver @ 14000dc30 =====

void PortWdmPassDownToNextDriver(undefined8 param_1,longlong param_2)

{
  if (**(char **)(param_2 + 0xb8) == '\x16') {
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    PoCallDriver(param_1,param_2);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(char **)(param_2 + 0xb8) = *(char **)(param_2 + 0xb8) + 0x48;
    IofCallDriver(param_1,param_2);
  }
  return;
}



===== PortWdmSizeOfCmResourceList @ 14000dcac =====

int PortWdmSizeOfCmResourceList(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar4 = 0x28;
  if (*param_1 != 0) {
    puVar3 = param_1 + 4;
    do {
      iVar1 = iVar4 + 0x24;
      if (uVar5 == 0) {
        iVar1 = iVar4;
      }
      iVar4 = iVar1;
      uVar2 = 0;
      if (*puVar3 != 0) {
        iVar1 = iVar4;
        do {
          iVar4 = iVar1 + 0x14;
          if (uVar2 == 0) {
            iVar4 = iVar1;
          }
          uVar2 = uVar2 + 1;
          iVar1 = iVar4;
        } while (uVar2 < *puVar3);
      }
      uVar5 = uVar5 + 1;
      puVar3 = puVar3 + 9;
    } while (uVar5 < *param_1);
  }
  return iVar4;
}



===== PortTraceErrorFreeDriver @ 14000dd04 =====

void PortTraceErrorFreeDriver(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
  UNLOCK();
  puVar1 = (uint *)(param_1 + 0x50);
  if (*(longlong *)(param_1 + 0x38) != 0) {
    uVar3 = 0;
    if (*puVar1 != 0) {
      do {
        ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x38) + uVar3 * 8),0);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *puVar1);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x38),0);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  *puVar1 = 0;
  return;
}



===== PortTraceErrorRegisterDriver @ 14000dd78 =====

void PortTraceErrorRegisterDriver(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_2 + 0xc);
  uVar4 = 10;
  if ((10 < uVar3) || (uVar4 = uVar3, uVar3 != 0)) {
    lVar1 = ExAllocatePool2(0x40,uVar4 * 8,0x6c456c50);
    *(longlong *)(param_1 + 0x38) = lVar1;
    if (lVar1 != 0) {
      uVar3 = 0;
      if (uVar4 != 0) {
        lVar1 = 0;
        do {
          lVar2 = ExAllocatePool2(0x40,0x110,0x6c456c50);
          if (lVar2 == 0) break;
          uVar3 = uVar3 + 1;
          *(longlong *)(lVar1 + *(longlong *)(param_1 + 0x38)) = lVar2;
          lVar1 = lVar1 + 8;
        } while (uVar3 < uVar4);
      }
      *(uint *)(param_1 + 0x50) = uVar3;
    }
  }
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x40));
  *(undefined4 *)(param_1 + 0x54) = 0;
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  UNLOCK();
  PortpErrorInitDpc(param_1);
  return;
}



===== PortRegistryReadDeviceKey @ 14000de48 =====

int PortRegistryReadDeviceKey
              (undefined8 param_1,longlong param_2,longlong param_3,undefined4 param_4,
              undefined8 *param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 local_18 [2];
  
  puVar1 = param_6;
  local_18[0] = 0;
  param_6._0_4_ = *param_6;
  iVar2 = IoOpenDeviceRegistryKey(param_1,1,0x20019,local_18);
  if (-1 < iVar2) {
    iVar2 = PortRegistryReadWithHandle
                      (local_18[0],param_2,param_3,param_4,param_5,(undefined4 *)&param_6);
    ZwClose(local_18[0]);
    if (-1 < iVar2) {
      *puVar1 = param_6._0_4_;
    }
  }
  return iVar2;
}



===== PortRegistryReadWithHandle @ 14000df04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PortRegistryReadWithHandle
              (undefined8 param_1,longlong param_2,longlong param_3,undefined4 param_4,
              undefined8 *param_5,undefined4 *param_6)

{
  undefined8 uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_res10;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  code *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 *local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  
  local_res10 = 0;
  local_dc = 0;
  if (param_2 == 0) {
    local_res10 = param_1;
  }
  else {
    local_ac = 0;
    local_c8 = 0x30;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b0 = 0x240;
    local_c0 = param_1;
    local_b8 = param_2;
    iVar2 = ZwCreateKey(&local_res10,0x2001f,&local_c8,0,0,0,0);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  uVar1 = local_res10;
  local_e8 = *param_5;
  local_e0 = *param_6;
  memset(&local_98,0,0x70);
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_98 = PortpRegQueryRoutine;
  local_88 = *(undefined8 *)(param_3 + 8);
  local_80 = &local_e8;
  local_90 = 0x14;
  local_d8 = 0;
  uStack_d0 = 0;
  RtlInitUnicodeString(&local_d8,L"RtlQueryRegistryValuesEx");
  pcVar3 = (code *)MmGetSystemRoutineAddress(&local_d8);
  if (pcVar3 == (code *)0x0) {
    pcVar3 = RtlQueryRegistryValues_exref;
  }
  iVar2 = (*pcVar3)(0x40000000,uVar1,&local_98,param_4,0);
  *param_5 = local_e8;
  *param_6 = local_e0;
  if (param_2 != 0) {
    ZwClose(local_res10);
  }
  return iVar2;
}



===== PortpRegQueryRoutine @ 14000e0a0 =====

undefined8
PortpRegQueryRoutine
          (undefined8 param_1,int param_2,void *param_3,uint param_4,int param_5,longlong *param_6)

{
  uint uVar1;
  void *_Dst;
  undefined8 uVar2;
  
  if (param_2 != param_5) {
    return 0xc0000001;
  }
  uVar2 = 0;
  _Dst = (void *)*param_6;
  uVar1 = *(uint *)(param_6 + 1);
  if (((_Dst == (void *)0x0) &&
      (_Dst = (void *)ExAllocatePool2(0x100,(ulonglong)param_4,0x67526c50), uVar1 = param_4,
      _Dst == (void *)0x0)) || (uVar1 < param_4)) {
    uVar2 = 0xc000009a;
  }
  else {
    memcpy(_Dst,param_3,(ulonglong)param_4);
  }
  *param_6 = (longlong)_Dst;
  *(uint *)(param_6 + 1) = param_4;
  return uVar2;
}



===== entry @ 140010010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140010044 =====

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



===== DriverEntry @ 140010080 =====

undefined8 DriverEntry(void)

{
  return 0;
}


