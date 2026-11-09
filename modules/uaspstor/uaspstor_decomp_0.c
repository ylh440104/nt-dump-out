
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



===== IssueBulkRequest @ 140001020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int IssueBulkRequest(longlong param_1,longlong param_2,uint param_3,ushort param_4,
                    undefined8 param_5,undefined8 param_6,undefined4 param_7,uint param_8,
                    undefined8 param_9)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong *puVar3;
  undefined8 *local_48;
  longlong local_40;
  ulonglong local_38;
  ulonglong local_30;
  undefined4 *local_28 [2];
  
  local_40 = 0;
  local_30 = 0;
  local_38 = 0;
  local_28[0] = (undefined4 *)0x0;
  local_48 = (undefined8 *)0x0;
  if (param_3 - 1 < 4) {
    puVar3 = &local_38;
    PrepareBulkRequest(param_1,param_3,param_4,param_8,(longlong *)&local_48,&local_40,local_28,
                       &local_30,puVar3);
    puVar1 = local_48;
    *local_48 = param_5;
    local_48[1] = param_2;
    local_48[3] = param_9;
    local_48[4] = local_38;
    local_48[2] = _DAT_fffff78000000014;
    if (*(char *)(param_2 + 0xb8) != '\0') {
      IoSetActivityIdIrp(local_40,param_2 + 0xa8);
    }
    iVar2 = UaspIssueBulkOrInterruptRequest
                      (param_1,local_40,local_28[0],local_30,param_8,param_7,param_5,param_6,puVar3,
                       puVar1);
  }
  else {
    iVar2 = -0x3ffffff3;
  }
  return iVar2;
}



===== OpenStreamArray @ 140001160 =====

int OpenStreamArray(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *_Dst;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)0x0;
  lVar4 = *(longlong *)(param_1 + 0x4f8);
  _Dst = (void *)0x0;
  iVar3 = USBD_UrbAllocate(lVar4,&local_res8);
  if (-1 < iVar3) {
    _Dst = (void *)UaspAllocatePool(lVar4,(ulonglong)*(ushort *)(param_1 + 0x500) * 0x18);
    puVar2 = local_res8;
    if (_Dst == (void *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x500);
      memset(local_res8,0,0x98);
      memset(_Dst,0,(ulonglong)uVar1 * 0x18);
      *puVar2 = 0x350030;
      *(undefined8 *)(puVar2 + 6) = param_3;
      puVar2[8] = (uint)uVar1;
      puVar2[9] = 0x180100;
      *(void **)(puVar2 + 10) = _Dst;
      iVar3 = UaspSyncSendUsbRequestNew(param_1,*(longlong *)(param_1 + 0x10),local_res8,'\x01');
      if (-1 < iVar3) {
        if ((uint)local_res8[8] <= (uint)*(ushort *)(param_1 + 0x500)) {
          bVar6 = 0;
          if (local_res8[8] != 0) {
            do {
              uVar5 = (ulonglong)bVar6;
              bVar6 = bVar6 + 1;
              *(undefined8 *)(uVar5 * 0xe0 + 0x30 + param_2) =
                   *(undefined8 *)(*(longlong *)(local_res8 + 10) + uVar5 * 0x18);
            } while ((uint)bVar6 < (uint)local_res8[8]);
          }
          *(undefined8 *)(local_res8 + 6) = param_4;
          iVar3 = UaspSyncSendUsbRequestNew(param_1,*(longlong *)(param_1 + 0x10),local_res8,'\x01')
          ;
          if (iVar3 < 0) goto LAB_1400011c6;
          if ((uint)local_res8[8] <= (uint)*(ushort *)(param_1 + 0x500)) {
            bVar6 = 0;
            if (local_res8[8] != 0) {
              do {
                uVar5 = (ulonglong)bVar6;
                bVar6 = bVar6 + 1;
                *(undefined8 *)(uVar5 * 0xe0 + 0x38 + param_2) =
                     *(undefined8 *)(*(longlong *)(local_res8 + 10) + uVar5 * 0x18);
              } while ((uint)bVar6 < (uint)local_res8[8]);
            }
            *(undefined8 *)(local_res8 + 6) = param_5;
            iVar3 = UaspSyncSendUsbRequestNew
                              (param_1,*(longlong *)(param_1 + 0x10),local_res8,'\x01');
            if (iVar3 < 0) goto LAB_1400011c6;
            if ((uint)local_res8[8] <= (uint)*(ushort *)(param_1 + 0x500)) {
              bVar6 = 0;
              if (local_res8[8] != 0) {
                do {
                  uVar5 = (ulonglong)bVar6;
                  bVar6 = bVar6 + 1;
                  *(undefined8 *)(uVar5 * 0xe0 + 0x40 + param_2) =
                       *(undefined8 *)(*(longlong *)(local_res8 + 10) + uVar5 * 0x18);
                } while ((uint)bVar6 < (uint)local_res8[8]);
              }
              goto LAB_1400011c6;
            }
          }
        }
        iVar3 = -0x3fffff64;
      }
    }
  }
LAB_1400011c6:
  if (local_res8 != (undefined4 *)0x0) {
    USBD_UrbFree(*(longlong *)(param_1 + 0x4f8),(longlong)local_res8);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar3;
}



===== PipeCompletionRoutine @ 1400013b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PipeCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  param_3[2] = _DAT_fffff78000000014 - param_3[2];
  if ((code *)param_3[3] == (code *)0x0) {
    StatusPipeCompletion
              ((longlong)param_3,(char *)*param_3,(ulonglong)*(uint *)(param_2 + 0x30),param_2,
               param_3[4]);
  }
  else {
    (*(code *)param_3[3])(param_3[1]);
  }
  return 0xc0000016;
}



===== PrepareBulkRequest @ 140001418 =====

ulonglong PrepareBulkRequest(longlong param_1,uint param_2,ushort param_3,uint param_4,
                            longlong *param_5,undefined8 *param_6,undefined8 *param_7,
                            ulonglong *param_8,ulonglong *param_9)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  uVar3 = (ulonglong)param_2;
  *param_9 = 0;
  *param_8 = 0;
  if (param_2 == 1) {
    lVar7 = (ulonglong)param_3 * 0xe0;
    lVar2 = *(longlong *)(param_1 + 0x498);
    *param_5 = *(longlong *)(param_1 + 0x480) + (ulonglong)param_3 * 0x28;
    *param_6 = *(undefined8 *)(lVar7 + 0x70 + lVar2);
    *param_7 = *(undefined8 *)(lVar7 + 0x50 + lVar2);
    uVar3 = *(ulonglong *)(param_1 + 0x450);
    uVar6 = *(ulonglong *)(uVar3 + 8);
    *param_9 = uVar6;
    goto LAB_1400015b2;
  }
  if (param_2 == 3) {
    lVar2 = *(longlong *)(param_1 + 0x498);
    lVar7 = (ulonglong)param_3 * 0xe0;
    *param_5 = *(longlong *)(lVar7 + 0xd0 + lVar2);
    *param_6 = *(undefined8 *)(lVar7 + 0x80 + lVar2);
    uVar4 = *(undefined8 *)(lVar7 + 0x60 + lVar2);
LAB_1400014cb:
    *param_7 = uVar4;
    uVar5 = 0;
    if (*(char *)(param_1 + 0x3da) != '\0') {
      uVar5 = *(ulonglong *)(lVar7 + 0x40 + lVar2);
      *param_8 = uVar5;
    }
    lVar2 = *(longlong *)(param_1 + 0x448);
  }
  else {
    if (param_2 == 4) {
      lVar2 = *(longlong *)(param_1 + 0x498);
      lVar7 = (ulonglong)param_3 * 0xe0;
      *param_5 = *(longlong *)(lVar7 + 0xd8 + lVar2);
      *param_6 = *(undefined8 *)(lVar7 + 0x88 + lVar2);
      uVar4 = *(undefined8 *)(lVar7 + 0x68 + lVar2);
      goto LAB_1400014cb;
    }
    uVar6 = 0;
    if (param_2 != 2) goto LAB_1400015b2;
    *param_5 = *(longlong *)(param_1 + 0x478) + (ulonglong)param_3 * 0x28;
    lVar7 = (ulonglong)param_3 * 0xe0;
    cVar1 = *(char *)(param_1 + 0x3da);
    lVar2 = *(longlong *)(param_1 + 0x498);
    *param_6 = *(undefined8 *)(lVar7 + 0x78 + lVar2);
    *param_7 = *(undefined8 *)(lVar7 + 0x58 + lVar2);
    if (cVar1 == '\0') {
      uVar5 = 0;
      if ((param_4 & 1) != 0) goto LAB_1400015c3;
LAB_14000159f:
      lVar2 = *(longlong *)(param_1 + 0x58);
    }
    else {
      if ((param_4 & 1) == 0) {
        uVar5 = *(ulonglong *)(lVar7 + 0x38 + lVar2);
        *param_8 = uVar5;
        goto LAB_14000159f;
      }
      uVar5 = *(ulonglong *)(lVar7 + 0x30 + lVar2);
      *param_8 = uVar5;
LAB_1400015c3:
      lVar2 = *(longlong *)(param_1 + 0x50);
    }
  }
  uVar3 = *(ulonglong *)(lVar2 + 8);
  *param_9 = uVar3;
  uVar6 = uVar3;
  if (uVar5 != 0) {
    return uVar3;
  }
LAB_1400015b2:
  *param_8 = uVar6;
  return uVar3;
}



===== Feature_1589099833__private_IsEnabledDeviceUsageNoInline @ 1400015d0 =====

ulonglong Feature_1589099833__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_1589099833__private_featureState;
  if ((Feature_1589099833__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1589099833__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1589099833__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1589099833__private_IsEnabledFallback @ 140001608 =====

void Feature_1589099833__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== UasInitializeDevice @ 140001620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UasInitializeDevice(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined2 uVar8;
  bool bVar9;
  ushort local_res8 [4];
  undefined1 local_78 [8];
  undefined8 local_70;
  code *local_60;
  code *local_38;
  
  uVar5 = 0;
  memset(local_78,0,0x48);
  local_res8[0] = 0;
  lVar4 = IoAllocateWorkItem(param_2);
  *(longlong *)(param_1 + 200) = lVar4;
  if (lVar4 == 0) {
    return -0x3fffff66;
  }
  iVar3 = UaspGetDescriptors(param_1,uVar5,param_3);
  if (iVar3 < 0) {
    return iVar3;
  }
  lVar4 = param_3;
  iVar3 = UaspSelectConfiguration(param_1,uVar5,param_3);
  if (iVar3 < 0) {
    return iVar3;
  }
  uVar5 = UaspGetPipes(param_1);
  if ((int)uVar5 < 0) {
    return (int)uVar5;
  }
  lVar7 = param_3;
  iVar3 = USBD_CreateHandle(param_2,param_3,lVar4,param_4,(ulonglong *)(param_1 + 0x4f8));
  if (iVar3 < 0) {
    if (gTracingEnabled == '\0') {
      return iVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    uVar8 = 0x14;
    uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
LAB_140001721:
    WPP_RECORDER_SF_D(uVar5,2,1,uVar8,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,(char)iVar3);
  }
  else {
    uVar6 = *(ulonglong *)(param_1 + 0x4f8);
    iVar3 = USBD_QueryUsbCapability(uVar6,lVar7,lVar4,(longlong)local_res8);
    if (iVar3 < 0) {
LAB_1400017bb:
      bVar9 = gTracingEnabled != '\0';
      *(undefined1 *)(param_1 + 0x3da) = 0;
      if ((bVar9) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar6,4,4,0x15,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,
                          (char)iVar3);
      }
      iVar3 = UaspGetBusInterface(uVar6,param_2,param_3,local_78);
      if (iVar3 < 0) {
LAB_1400019dc:
        if (gTracingEnabled == '\0') {
          return -0x3ffffe7e;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffe7e;
        }
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar5,2,1,0x16,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids);
        return -0x3ffffe7e;
      }
      uVar1 = (*local_38)(local_70);
      *(undefined1 *)(param_1 + 0x3d9) = uVar1;
      (*local_60)(local_70);
      if (*(char *)(param_1 + 0x3d9) == '\0') goto LAB_1400019dc;
      *(undefined2 *)(param_1 + 0x500) = 0x20;
    }
    else {
      uVar2 = *(ushort *)(param_1 + 0x500);
      uVar6 = (ulonglong)local_res8[0];
      if ((uVar2 == 0) && (local_res8[0] == 0)) goto LAB_1400017bb;
      *(undefined1 *)(param_1 + 0x3da) = 1;
      if (local_res8[0] <= uVar2) {
        uVar2 = local_res8[0];
      }
      *(ushort *)(param_1 + 0x500) = uVar2;
      StorPortExtendedFunction(0x54,param_1,uVar2 - 1,uVar2 - 1);
    }
    uVar5 = AllocateRequestContextPool(param_1);
    if ((int)uVar5 < 0) {
      return (int)uVar5;
    }
    lVar4 = param_1;
    uVar5 = AllocateIUPool(param_1);
    if ((int)uVar5 < 0) {
      return (int)uVar5;
    }
    iVar3 = 0;
    lVar7 = UaspAllocatePool(lVar4,(ulonglong)*(ushort *)(param_1 + 0x500) * 0xe0);
    *(longlong *)(param_1 + 0x498) = lVar7;
    if (((lVar7 == 0) && (iVar3 = -0x3fffff66, gTracingEnabled != '\0')) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 0xd;
    }
    else {
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = 0;
      lVar4 = UaspAllocatePool(lVar4,(ulonglong)*(ushort *)(param_1 + 0x500) << 2);
      *(longlong *)(param_1 + 0x4c8) = lVar4;
      if (((lVar4 != 0) || (iVar3 = -0x3fffff66, gTracingEnabled == '\0')) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) {
        if (iVar3 < 0) {
          return iVar3;
        }
        if ((*(char *)(param_1 + 0x3da) == '\0') ||
           (iVar3 = OpenStreamArray(param_1,*(longlong *)(param_1 + 0x498),
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 8),
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x58) + 8),
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x448) + 8)), -1 < iVar3
           )) {
          iVar3 = InitializeQueue(param_2,param_1);
          if (iVar3 < 0) {
            return iVar3;
          }
          *(undefined4 *)(param_1 + 0x3e0) = 0x80000;
          *(undefined4 *)(param_1 + 0x3e4) = 0x80;
          return iVar3;
        }
        if (gTracingEnabled == '\0') {
          return iVar3;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar3;
        }
        uVar8 = 0x17;
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        goto LAB_140001721;
      }
      uVar8 = 0xe;
    }
    uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_(uVar5,2,1,uVar8,&WPP_36185c522d943f8d0ee1935152861c3e_Traceguids);
    iVar3 = -0x3fffff66;
  }
  return iVar3;
}



===== UaspDumpIssueBulkOrInterruptRequest @ 140001a4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UaspDumpIssueBulkOrInterruptRequest(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  undefined1 auStack_128 [32];
  longlong local_108;
  undefined4 local_100;
  uint local_f8 [4];
  longlong local_e8 [20];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar4 = *(longlong *)(param_2 + 0x28);
  local_f8[0] = 0;
  memset(local_e8,0,0xa0);
  if (lVar4 == *(longlong *)(*(longlong *)(param_3[1] + 0x20) + 0x18)) {
    iVar7 = *(int *)(param_2 + 0x24);
    uVar6 = 0;
    do {
      local_f8[0] = 0x1000;
      lVar2 = StorPortGetPhysicalAddress(param_1,*(undefined8 *)(param_3[1] + 0x20),lVar4,local_f8);
      iVar7 = iVar7 - local_f8[0];
      local_e8[uVar6] = lVar2;
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      lVar4 = lVar4 + (ulonglong)local_f8[0];
      if (iVar7 < 1) break;
    } while (uVar5 < 0x14);
  }
  else {
    local_e8[0] = (ulonglong)(uint)((int)lVar4 - *(int *)(lVar1 + 0x430)) +
                  *(longlong *)(lVar1 + 0x438);
  }
  local_100 = *(undefined4 *)(param_2 + 0x24);
  local_108 = local_e8[0];
  DbgPrintEx(5,2,"UASPSTOR: Issuing URB. Urb: %p, PA: 0x%I64X, Length: %u\n",param_2);
  pcVar3 = *(code **)(lVar1 + 0x410);
  if (pcVar3 == (code *)0x0) {
    pcVar3 = *(code **)(lVar1 + 0x408);
  }
  iVar7 = (*pcVar3)(*(undefined8 *)(lVar1 + 0x3f8),param_2,local_e8);
  local_108 = CONCAT44(local_108._4_4_,iVar7);
  DbgPrintEx(5,2,"UASPSTOR: URB completion. Urb: %p, Status: 0x%lX\n",param_2);
  if (iVar7 != 0x103) {
    (*(code *)param_3[3])(param_3[1],*param_3,iVar7,param_3[4]);
  }
  return iVar7;
}



===== UaspGetMaximumTransferLength @ 140001bd4 =====

undefined4 UaspGetMaximumTransferLength(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res20 = 0;
  lVar2 = 0;
  local_res10[0] = 0;
  uVar4 = 0x80000;
  local_28 = 0;
  uStack_20 = 0;
  local_res18[0] = 0x80000;
  RtlInitUnicodeString(&local_28,L"MaximumTransferLength");
  iVar1 = IoOpenDeviceRegistryKey(param_1,1,0x20019,&local_res20);
  if (-1 < iVar1) {
    lVar3 = local_res20;
    iVar1 = ZwQueryValueKey(local_res20,&local_28,2,0,0,local_res10);
    if ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd)) {
      lVar2 = UaspAllocatePool(lVar3,(ulonglong)local_res10[0]);
      if (lVar2 != 0) {
        iVar1 = ZwQueryValueKey(local_res20,&local_28,2,lVar2,local_res10[0],local_res10);
        if ((-1 < iVar1) && (*(int *)(lVar2 + 8) == 4)) {
          memmove(local_res18,(void *)(lVar2 + 0xc),4);
          uVar4 = local_res18[0];
        }
      }
    }
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return uVar4;
}



===== UaspGetPipes @ 140001d0c =====

undefined8 UaspGetPipes(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x48);
  uVar4 = 0;
  uVar2 = *(uint *)(lVar3 + 0x10);
  if ((((*(byte *)(param_1 + 0x440) < uVar2) && (*(byte *)(param_1 + 0x443) < uVar2)) &&
      (*(byte *)(param_1 + 0x441) < uVar2)) && (*(byte *)(param_1 + 0x442) < uVar2)) {
    lVar1 = lVar3 + ((ulonglong)*(byte *)(param_1 + 0x440) + 1) * 0x18;
    if ((*(int *)(lVar1 + 4) == 2) && (-1 < *(char *)(lVar1 + 2))) {
      *(longlong *)(param_1 + 0x450) = lVar1;
    }
    lVar1 = lVar3 + ((ulonglong)*(byte *)(param_1 + 0x443) + 1) * 0x18;
    if ((*(int *)(lVar1 + 4) == 2) && (*(char *)(lVar1 + 2) < '\0')) {
      *(longlong *)(param_1 + 0x448) = lVar1;
    }
    lVar1 = lVar3 + ((ulonglong)*(byte *)(param_1 + 0x441) + 1) * 0x18;
    if ((*(int *)(lVar1 + 4) == 2) && (*(char *)(lVar1 + 2) < '\0')) {
      *(longlong *)(param_1 + 0x50) = lVar1;
    }
    lVar3 = lVar3 + ((ulonglong)*(byte *)(param_1 + 0x442) + 1) * 0x18;
    if ((*(int *)(lVar3 + 4) == 2) && (-1 < *(char *)(lVar3 + 2))) {
      *(longlong *)(param_1 + 0x58) = lVar3;
    }
    if ((*(longlong *)(param_1 + 0x450) == 0) || (*(longlong *)(param_1 + 0x448) == 0)) {
      uVar4 = 0xc0000182;
    }
  }
  else {
    uVar4 = 0xc0000182;
  }
  return uVar4;
}



===== UaspIssueBulkOrInterruptRequest @ 140001e04 =====

int UaspIssueBulkOrInterruptRequest
              (longlong param_1,longlong param_2,undefined4 *param_3,undefined8 param_4,
              undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
              undefined8 param_9,undefined8 *param_10)

{
  longlong lVar1;
  int iVar2;
  
  memset(param_3,0,0x80);
  param_3[8] = param_5;
  param_3[9] = param_6;
  *(undefined8 *)(param_3 + 10) = param_7;
  *(undefined8 *)(param_3 + 0xc) = param_8;
  *param_3 = 0x90080;
  *(undefined8 *)(param_3 + 6) = param_4;
  if (param_2 == 0) {
    lVar1 = param_10[1];
    if ((*(longlong *)(*(longlong *)(param_1 + 0x68) + 0x410) == 0) &&
       (param_3 != *(undefined4 **)(lVar1 + 0x58))) {
      if (param_3 != *(undefined4 **)(lVar1 + 0x50)) {
        return 0x103;
      }
      UaspDumpIssueBulkOrInterruptRequest
                (param_1,(longlong)*(undefined4 **)(lVar1 + 0x50),*(undefined8 **)(param_1 + 0x480))
      ;
      if (*(int *)(lVar1 + 0x14) == 2) {
        UaspDumpIssueBulkOrInterruptRequest
                  (param_1,*(longlong *)(lVar1 + 0x68),*(undefined8 **)(param_1 + 0x490));
      }
      param_10 = *(undefined8 **)(param_1 + 0x488);
      param_3 = *(undefined4 **)(lVar1 + 0x60);
    }
    iVar2 = UaspDumpIssueBulkOrInterruptRequest(param_1,(longlong)param_3,param_10);
  }
  else {
    IoReuseIrp(param_2,0);
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220003;
    if (*(int *)(*(longlong *)(param_1 + 0x4f8) + 0xd8) - 0x602U < 0xfffff9fd) {
      *(undefined4 **)(lVar1 + -0x18) = param_3;
    }
    *(undefined4 **)(lVar1 + -0x40) = param_3;
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar1 + -0x10) = PipeCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = param_10;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),param_2);
  }
  return iVar2;
}



===== UaspParseConfigurationDescriptor @ 140001f74 =====

void UaspParseConfigurationDescriptor
               (undefined8 param_1,ushort *param_2,ulonglong *param_3,char *param_4,char *param_5,
               char *param_6,char *param_7,int *param_8)

{
  ushort *puVar1;
  byte bVar2;
  byte bVar3;
  ushort *puVar4;
  char cVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  puVar6 = (ushort *)0x0;
  cVar5 = '\0';
  puVar7 = (ushort *)((ulonglong)param_2[1] + (longlong)param_2);
  if (param_2 + 1 < puVar7) {
    while( true ) {
      bVar3 = (byte)*param_2;
      if (puVar7 < (ushort *)((ulonglong)bVar3 + (longlong)param_2)) break;
      puVar4 = param_2;
      if (*(byte *)((longlong)param_2 + 1) == 4) {
        if (bVar3 == 9) {
          if (puVar6 != (ushort *)0x0) break;
          if (*(byte *)((longlong)param_2 + 3) == 1) {
            puVar6 = param_2;
          }
        }
      }
      else if (((*(byte *)((longlong)param_2 + 1) == 5) && (bVar3 == 7)) &&
              (puVar1 = (ushort *)((ulonglong)bVar3 + (longlong)param_2), puVar6 != (ushort *)0x0))
      {
        while (puVar4 = puVar1, puVar4 + 1 < puVar7) {
          bVar3 = (byte)*puVar4;
          puVar1 = (ushort *)((ulonglong)bVar3 + (longlong)puVar4);
          if (puVar7 < puVar1) break;
          bVar2 = *(byte *)((longlong)puVar4 + 1);
          if (bVar2 == 0x24) {
            if (bVar3 == 4) {
              bVar3 = (byte)puVar4[1];
              if (bVar3 == 1) {
                if (((*(byte *)((longlong)param_2 + 3) & 3) != 2) || ((char)(byte)param_2[1] < '\0')
                   ) goto LAB_14000212b;
                *param_4 = cVar5;
              }
              else if (bVar3 == 2) {
                if (((*(byte *)((longlong)param_2 + 3) & 3) != 2) || (-1 < (char)(byte)param_2[1]))
                goto LAB_14000212b;
                *param_7 = cVar5;
              }
              else if (bVar3 == 3) {
                if (((*(byte *)((longlong)param_2 + 3) & 3) != 2) || (-1 < (char)(byte)param_2[1]))
                goto LAB_14000212b;
                *param_5 = cVar5;
              }
              else {
                if (((bVar3 != 4) || ((*(byte *)((longlong)param_2 + 3) & 3) != 2)) ||
                   ((char)(byte)param_2[1] < '\0')) goto LAB_14000212b;
                *param_6 = cVar5;
              }
              break;
            }
LAB_1400020b4:
            if (bVar3 == 0) goto LAB_14000212b;
          }
          else {
            if (bVar2 != 0x30) {
              if (1 < (byte)(bVar2 - 4)) goto LAB_1400020b4;
              break;
            }
            if (bVar3 != 6) goto LAB_1400020b4;
            if (((*(byte *)((longlong)param_2 + 3) & 3) == 2) &&
               (bVar3 = *(byte *)((longlong)puVar4 + 3) & 0x1f, bVar3 != 0)) {
              *param_8 = (1 << bVar3) + -1;
            }
          }
        }
        cVar5 = cVar5 + '\x01';
      }
      if (((puVar7 <= puVar4 + 1) || ((byte)*puVar4 == 0)) ||
         (param_2 = (ushort *)((longlong)puVar4 + (ulonglong)(byte)*puVar4), puVar7 <= param_2 + 1))
      break;
    }
  }
LAB_14000212b:
  *param_3 = (ulonglong)puVar6;
  return;
}



===== UaspPostProcessSrb @ 140002150 =====

void UaspPostProcessSrb(longlong param_1,longlong param_2)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  
  cVar1 = *(char *)(param_2 + 0x48);
  if (cVar1 == '\x12') {
    return;
  }
  if (cVar1 == -0x62) {
    return;
  }
  if (cVar1 != -0x60) {
    return;
  }
  uVar8 = 8;
  uVar2 = Feature_1589099833__private_IsEnabledDeviceUsageNoInline();
  uVar6 = 0;
  if (((int)uVar2 == 0) || (7 < *(uint *)(param_2 + 0x10))) {
    puVar5 = *(uint **)(param_2 + 0x18);
    uVar7 = *puVar5;
    uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    if (uVar7 == 0) {
      return;
    }
    uVar2 = Feature_1589099833__private_IsEnabledDeviceUsageNoInline();
    uVar7 = uVar7 >> 3;
    if ((int)uVar2 == 0) {
      *(uint *)(param_1 + 1000) = uVar7;
      if (*(longlong *)(param_1 + 0x468) == 0) {
        lVar3 = UaspAllocatePool(0,(ulonglong)uVar7 << 5);
        *(longlong *)(param_1 + 0x468) = lVar3;
        if (lVar3 == 0) {
          return;
        }
      }
      if (*(int *)(param_1 + 1000) == 0) {
        return;
      }
      do {
        uVar8 = uVar8 + 8;
        if (uVar8 <= *(uint *)(param_2 + 0x10)) {
          *(undefined8 *)(uVar6 * 0x20 + *(longlong *)(param_1 + 0x468)) =
               *(undefined8 *)(puVar5 + uVar6 * 2 + 2);
        }
        uVar7 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar7;
      } while (uVar7 < *(uint *)(param_1 + 1000));
      return;
    }
    if (*(longlong *)(param_1 + 0x468) == 0) {
      if (SUB168(ZEXT416(0x20) * ZEXT416(uVar7),8) == 0) {
        lVar3 = UaspAllocatePool(0,SUB168(ZEXT416(0x20) * ZEXT416(uVar7),0));
        *(longlong *)(param_1 + 0x468) = lVar3;
        if (lVar3 != 0) {
          *(uint *)(param_1 + 1000) = uVar7;
          goto LAB_140002257;
        }
      }
    }
    else {
      if (uVar7 <= *(uint *)(param_1 + 1000)) {
LAB_140002257:
        uVar2 = (ulonglong)uVar7;
        if (uVar7 == 0) {
          return;
        }
        do {
          puVar5 = puVar5 + 2;
          uVar8 = uVar8 + 8;
          if (uVar8 <= *(uint *)(param_2 + 0x10)) {
            *(undefined8 *)(uVar6 + *(longlong *)(param_1 + 0x468)) = *(undefined8 *)puVar5;
          }
          uVar6 = uVar6 + 0x20;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
        return;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_LL(uVar4);
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 4;
  return;
}



===== UaspSelectConfiguration @ 140002308 =====

int UaspSelectConfiguration(longlong param_1,undefined8 param_2,longlong param_3)

{
  ushort *_Src;
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong *puVar4;
  longlong lVar5;
  void *_Dst;
  undefined8 uVar6;
  char local_res8 [8];
  char local_res10;
  undefined7 uStackX_11;
  char local_res20 [8];
  char local_38 [4];
  uint local_34;
  ulonglong local_30;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lVar5 = 0;
  local_30 = 0;
  local_34 = 0;
  uVar6 = 0x100;
  _local_res10 = CONCAT71((int7)((ulonglong)param_2 >> 8),0xff);
  local_res8[0] = -1;
  local_res20[0] = -1;
  local_38[0] = -1;
  puVar4 = (ulonglong *)ExAllocatePool2(0x100,0x20,0x75617370);
  if (puVar4 == (ulonglong *)0x0) {
    return -0x3fffff66;
  }
  UaspParseConfigurationDescriptor
            (uVar6,*(ushort **)(param_1 + 0x28),&local_30,&local_res10,local_res8,local_res20,
             local_38,(int *)&local_34);
  if ((((local_30 == 0) || (local_res10 == -1)) || (local_res8[0] == -1)) ||
     ((local_res20[0] == -1 || (local_38[0] == -1)))) {
    iVar3 = -0x3ffffe7b;
    goto LAB_1400024a2;
  }
  *(char *)(param_1 + 0x440) = local_res10;
  *(char *)(param_1 + 0x441) = local_res8[0];
  uVar2 = 0xffff;
  if (local_34 < 0xffff) {
    uVar2 = local_34;
  }
  *(char *)(param_1 + 0x442) = local_res20[0];
  *(short *)(param_1 + 0x500) = (short)uVar2;
  *(char *)(param_1 + 0x443) = local_38[0];
  *(ulonglong *)(param_1 + 0x30) = local_30;
  puVar4[2] = 0;
  *puVar4 = local_30;
  *(undefined1 *)(lVar1 + 4) = 1;
  lVar5 = USBD_CreateConfigurationRequestEx(lVar1,puVar4);
  if (lVar5 == 0) {
LAB_140002438:
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = UaspSyncSendUsbRequestNew(0,param_3,lVar5,'\0');
    if (iVar3 < 0) goto LAB_1400024a2;
    _Dst = *(void **)(param_1 + 0x48);
    _Src = (ushort *)(lVar5 + 0x28);
    *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(lVar5 + 0x20);
    if (_Dst == (void *)0x0) {
      _Dst = (void *)ExAllocatePool2(0x40,*_Src,0x75617370);
      *(void **)(param_1 + 0x48) = _Dst;
      if (_Dst == (void *)0x0) goto LAB_140002438;
    }
    memmove(_Dst,_Src,(ulonglong)*_Src);
  }
LAB_1400024a2:
  ExFreePoolWithTag(puVar4,0);
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  return iVar3;
}



===== UaspStartIo @ 1400024f0 =====

undefined8 UaspStartIo(undefined *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 extraout_var;
  undefined8 uVar7;
  undefined4 extraout_var_00;
  longlong lVar8;
  code *pcVar9;
  uint uVar10;
  undefined2 uVar11;
  longlong lVar12;
  undefined *in_stack_ffffffffffffff48;
  undefined8 in_stack_ffffffffffffff50;
  
  bVar1 = *(byte *)(param_2 + 2);
  uVar10 = (uint)bVar1;
  uVar3 = (undefined1)param_2;
  if (bVar1 == 0) {
    *(longlong *)(param_1 + 0x158) = param_2;
    *(longlong *)(param_1 + 0x98) = param_2;
    if ((*(uint *)(param_1 + 0x78) & 1) == 0) {
      bVar2 = true;
      if ((*(char *)(param_2 + 0x48) == '\x12') && (*(char *)(param_2 + 0x4a) == -0x71)) {
        *(undefined1 *)(param_2 + 3) = 4;
        bVar2 = false;
      }
      if (((uint)*(byte *)(param_2 + 7) < *(uint *)(param_1 + 1000)) ||
         (*(char *)(param_2 + 0x48) == -0x60)) {
        if (bVar2) {
          if ((gTracingEnabled != '\0') &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            WPP_RECORDER_SF_PDDDDDDDDDDD(uVar5);
          }
          *(undefined1 *)(param_2 + 3) = 0;
          if (param_1[0x3da] == '\0') {
            uVar6 = QueueCommandHS((longlong)param_1,(longlong)param_1,param_2);
            pcVar9 = (code *)param_1;
          }
          else {
            uVar6 = QueueCommandSS((longlong)param_1,(longlong)param_1,param_2);
            pcVar9 = (code *)param_1;
          }
          iVar4 = (int)uVar6;
          if (((-1 < iVar4) || (gTracingEnabled == '\0')) ||
             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_1400025de;
          uVar11 = 0xc;
LAB_140002b13:
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          goto LAB_140002b2a;
        }
      }
      else {
        *(undefined1 *)(param_2 + 3) = 0x20;
      }
    }
    else {
LAB_14000299d:
      *(undefined1 *)(param_2 + 3) = 8;
    }
  }
  else {
    if (uVar10 == 2) {
      if (0x1b < *(uint *)(param_2 + 0x10)) {
        lVar12 = *(longlong *)(param_2 + 0x18);
        lVar8 = RtlCompareMemory(lVar12 + 4,"UASPSTOR",8);
        if ((lVar8 == 8) && (*(int *)(lVar12 + 0x10) == 0x1b0800)) {
          if (*(uint *)(param_2 + 0x10) < 0x1e) {
            uVar3 = 6;
          }
          else {
            *(undefined2 *)(*(longlong *)(param_2 + 0x18) + 0x1c) = *(undefined2 *)(param_1 + 0x500)
            ;
            uVar3 = 1;
          }
          *(undefined1 *)(param_2 + 3) = uVar3;
          goto LAB_1400025ca;
        }
      }
      goto LAB_1400025c5;
    }
    if (uVar10 != 0x10) {
      if ((uVar10 == 0x13) || (uVar10 == 0x20)) {
        uVar5 = 0;
        if ((*(uint *)(param_1 + 0x78) & 1) != 0) goto LAB_14000299d;
        if (bVar1 == 0x13) {
          if ((gTracingEnabled != '\0') &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            uVar11 = 0xd;
LAB_140002872:
            in_stack_ffffffffffffff48 = &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids;
            WPP_RECORDER_SF_P(uVar7,uVar5,5,uVar11,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,
                              uVar3);
          }
        }
        else if ((gTracingEnabled != '\0') &&
                ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          uVar11 = 0xe;
          goto LAB_140002872;
        }
        pcVar9 = QueueTaskWorkItem;
        lVar12 = 0x10;
        if (bVar1 != 0x13) {
          lVar12 = 8;
        }
        iVar4 = UaspQueueWorkItem((longlong)param_1,0x140008bc0,param_2,lVar12);
        uVar6 = CONCAT44(extraout_var_00,iVar4);
        if (-1 < iVar4) goto LAB_1400025de;
        if (bVar1 == 0x13) {
          if ((gTracingEnabled == '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_1400025de;
          uVar11 = 0xf;
          goto LAB_140002b13;
        }
        if ((gTracingEnabled == '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
        goto LAB_1400025de;
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        uVar11 = 0x10;
LAB_140002b2a:
        uVar6 = WPP_RECORDER_SF_DP(uVar5,pcVar9,param_2,uVar11,in_stack_ffffffffffffff48,(char)iVar4
                                   ,uVar3);
        goto LAB_1400025de;
      }
      if (uVar10 == 0x24) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_PDD(uVar5);
        }
      }
      else {
        uVar6 = (ulonglong)(uVar10 - 0x25);
        if (uVar10 - 0x25 == 0) {
          uVar10 = *(uint *)(param_2 + 8);
          if ((*(uint *)(param_2 + 0x40) & 1) == 0) {
            if (uVar10 == 9) {
              *(uint *)(*(longlong *)(param_2 + 0x18) + 4) =
                   *(uint *)(*(longlong *)(param_2 + 0x18) + 4) & 0xffffffef | 0xa00;
              goto LAB_140002633;
            }
          }
          else if ((uVar10 < 0x18) && ((0x800014U >> (uVar10 & 0x1f) & 1) != 0)) {
            if ((*param_1 & 2) != 0) {
              if (param_1[0x3da] == '\0') {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  WPP_RECORDER_SF_SP(uVar5,uVar6,param_3,0x2b,
                                     &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                     in_stack_ffffffffffffff50,uVar3);
                }
                pcVar9 = QueueCancelHSWorkItem;
              }
              else {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  WPP_RECORDER_SF_SP(uVar5,uVar6,param_3,0xd,
                                     &WPP_b606bc35c7ef35d872dd65732ef04e06_Traceguids,
                                     in_stack_ffffffffffffff50,uVar3);
                }
                pcVar9 = QueueCancelSSWorkItem;
              }
              iVar4 = UaspQueueWorkItem((longlong)param_1,(longlong)pcVar9,param_2,0);
              uVar6 = CONCAT44(extraout_var,iVar4);
              if (((iVar4 < 0) && (gTracingEnabled != '\0')) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar3 = *(undefined1 *)(param_2 + 7);
                uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                uVar6 = WPP_RECORDER_SF_D(uVar5,2,1,0x11,
                                          &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,uVar3);
              }
              goto LAB_1400025de;
            }
            goto LAB_14000299d;
          }
LAB_1400025c5:
          *(undefined1 *)(param_2 + 3) = 6;
        }
        else if (uVar10 == 0x26) {
          UaspGetDumpPointers((longlong)param_1,param_2,param_3,param_4);
        }
        else {
          if (uVar10 != 0x27) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_D(uVar5,3,2,0x13,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,
                                bVar1);
            }
            goto LAB_1400025c5;
          }
          lVar12 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0x40);
          UaspInternalDeviceIoControl
                    (*(longlong *)(param_1 + 0x10),0x491408,lVar12 + 0x3f0,0x58,0,0);
          ExFreePoolWithTag(lVar12,0);
LAB_140002633:
          *(undefined1 *)(param_2 + 3) = 1;
        }
      }
    }
  }
LAB_1400025ca:
  uVar6 = StorPortNotification(0,param_1,param_2);
LAB_1400025de:
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== WPP_RECORDER_SF_ @ 140002b48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 140002c20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_DP @ 140002d1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,param_4,&param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,param_4,&param_6,4,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_LL @ 140002df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_P @ 140002ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_P(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (3 < *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_PDD @ 140002fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,0x12,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,0x12,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_PDDDDDDDDDDD @ 1400030a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PDDDDDDDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_c764e4e39a1f3e6bd12a0e4f6e391f43_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400032e0 =====

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
LAB_1400034e9:
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
LAB_1400033bb:
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
      if (param_3 == 4) goto LAB_1400034e9;
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
        goto LAB_1400033bb;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400035d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140003697;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140003697;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140003697;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140003697;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140003697;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140003697;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140003697;
    }
  }
  uVar2 = 0xff;
LAB_140003697:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b3f309,&Feature_1589099833_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400036f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,&Feature_1589099833__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3b3f309,param_3,1,&Feature_1589099833__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3b3f309);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400037dc =====

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
LAB_14000388f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400038bd;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000388f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400038bd:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003a48 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_1589099833__private_featureState & 2) != 0) {
    uVar1 = Feature_1589099833__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_1589099833__private_featureState;
      if (bVar3) {
        Feature_1589099833__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_1589099833__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_IsEnabledFallback @ 140003a9c =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_1589099833__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_1589099833__private_featureState,(ulonglong)param_1,
                             0x140011c30);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== DriverEntry @ 140003b2c =====

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_80;
  undefined4 local_7f;
  code *local_60;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  undefined4 local_20;
  code *local_10;
  
  if (gDumpPreInitializeInvoked == '\0') {
    wil_InitializeFeatureStaging();
  }
  memset(&local_d8,0,0xd0);
  local_d8 = 0xd0;
  if (param_1 == 0) {
    local_d0 = UaspDumpInitialize;
    local_c0 = UaspDumpHwInterrupt;
  }
  else {
    local_c0 = (code *)0x0;
    local_d0 = UaspInitialize;
  }
  local_c8 = UaspStartIo;
  local_d4 = 0;
  local_8c = 0;
  local_b8 = UaspFindAdapter;
  local_80 = param_1 != 0;
  local_98 = 0x5b8;
  local_b0 = UaspResetBus;
  local_90 = 0x10;
  local_60 = UaspAdapterControl;
  gTracingEnabled = param_1 != 0;
  local_94 = 0x20;
  local_10 = UaspUnitControl;
  local_7f = 0x1010101;
  local_50 = UaspFreeAdapterResources;
  local_20 = 5;
  local_48 = UaspProcessServiceRequest;
  local_40 = _guard_check_icall;
  local_38 = UaspInitializeTracing;
  local_30 = UaspCleanupTracing;
  iVar1 = StorPortInitialize(param_1,param_2,&local_d8,0);
  if (gDumpPreInitializeInvoked == '\0') {
    if (iVar1 == 0) {
      gStorPortDriverUnload = *(longlong *)(param_1 + 0x68);
      if (gStorPortDriverUnload != 0) {
        *(code **)(param_1 + 0x68) = UaspDriverUnload;
      }
    }
    else {
      if (g_wil_details_featureChangeNotification != 0) {
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      g_wil_details_isFeatureStagingInitialized = 0;
    }
  }
  return iVar1;
}



===== DumpPreInitialize @ 140003d00 =====

void DumpPreInitialize(void)

{
                    /* 0x3d00  1  DumpPreInitialize */
  gDumpPreInitializeInvoked = 1;
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 140003d20 =====

void DumpUninitialize(void)

{
                    /* 0x3d20  2  DumpUninitialize */
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== UaspAdapterControl @ 140003d80 =====

undefined8 UaspAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 5) = 0x101;
    *(undefined1 *)(param_3 + 0xc) = 1;
    *(undefined1 *)(param_3 + 4) = 1;
    return 0;
  }
  if (param_2 == 1) {
    if (gTracingEnabled != '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar2,4,3,0xf,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
      return 0;
    }
    uVar3 = 0x13;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 8) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_D(uVar2,4,3,0x12,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,
                            (char)param_2);
        }
        return 1;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar1 = *(undefined1 *)(param_3 + 0x14);
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar2,4,3,0x11,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,uVar1);
      }
      if (*(longlong *)(param_1 + 0x458) == 0) {
        return 0;
      }
      *(bool *)(param_1 + 0x460) = *(char *)(param_3 + 0x14) != '\0';
      return 0;
    }
    if (gTracingEnabled != '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar2,4,3,0x10,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
      return 0;
    }
    uVar3 = 0x14;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,3,uVar3,
                   &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
  return 0;
}



===== UaspCleanupTracing @ 140003fd0 =====

void UaspCleanupTracing(undefined8 param_1)

{
  WppCleanupKm(param_1);
  return;
}



===== _guard_check_icall @ 140003ff0 =====

void _guard_check_icall(void)

{
  return;
}



===== UaspDriverUnload @ 140004000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UaspDriverUnload(void)

{
  (*gStorPortDriverUnload)();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== UaspFindAdapter @ 140004070 =====

undefined8
UaspFindAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,longlong param_6,undefined1 *param_7)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  ExInitializeRundownProtection(param_1 + 0x508);
  uVar3 = PsGetCurrentProcess();
  *(undefined8 *)(param_1 + 8) = param_3;
  *(undefined8 *)(param_1 + 0x3f0) = uVar3;
  *(undefined4 *)(param_1 + 4) = 0x1e;
  *(undefined8 *)(param_1 + 0x10) = param_4;
  *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(param_6 + 0x40);
  *(undefined8 *)(param_1 + 0x558) = 0;
  *(undefined8 *)(param_1 + 0x560) = 0;
  *(undefined8 *)(param_1 + 0x568) = 0;
  *(undefined8 *)(param_1 + 0x570) = 0;
  *(undefined1 *)(param_6 + 0x48) = 1;
  *(undefined1 *)(param_6 + 0x61) = 1;
  *(undefined1 *)(param_6 + 0x92) = 0x10;
  if (*(longlong *)(param_1 + 0x68) == 0) {
    uVar2 = UaspGetMaximumTransferLength(param_4);
  }
  else {
    uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 4);
  }
  *(undefined4 *)(param_6 + 0x18) = uVar2;
  *(undefined4 *)(param_6 + 0x1c) = 0xffffffff;
  *(undefined2 *)(param_6 + 0x53) = 0;
  lVar1 = *(longlong *)(param_1 + 0x68);
  *(undefined4 *)(param_6 + 0x30) = 3;
  *(undefined1 *)(param_6 + 0x91) = 1;
  *(bool *)(param_6 + 0x59) = lVar1 == 0;
  *(undefined4 *)(param_6 + 0x88) = 0x20;
  *(undefined4 *)(param_6 + 0xcc) = 0x20;
  *(undefined2 *)(param_6 + 0x51) = 0x101;
  *(undefined2 *)(param_6 + 0x5a) = 0x101;
  *(undefined4 *)(param_6 + 0x94) = 1;
  *(undefined1 *)(param_6 + 0xc4) = 1;
  *(undefined4 *)(param_6 + 0x84) = 0x5b8;
  *(undefined4 *)(param_6 + 0x8c) = 0x10;
  *(undefined1 *)(param_6 + 0x93) = 0;
  *param_7 = 0;
  if (*(longlong *)(param_1 + 0x68) != 0) {
    StorPortExtendedFunction(0x2d,param_1,*(longlong *)(param_1 + 0x68),0x450,0);
    StorPortExtendedFunction
              (0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x430),
               *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x440),0);
    StorPortExtendedFunction
              (0x2d,param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x408),0,0);
  }
  return 1;
}



===== UaspFreeAdapterResources @ 140004220 =====

void UaspFreeAdapterResources(byte *param_1)

{
  UaspFreeResources(param_1,'\x01');
  return;
}



===== UaspFreeResources @ 140004238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UaspFreeResources(byte *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ushort uVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_qDD(uVar4);
  }
  ExWaitForRundownProtectionRelease(param_1 + 0x508);
  if ((*param_1 & 2) != 0) {
    KeWaitForSingleObject(param_1 + 0x580,0,0,0,0);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,3,0x15,
                       &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
    }
    *param_1 = *param_1 | 4;
    KeAcquireInStackQueuedSpinLock(param_1 + 0x4d8,&local_38);
    param_1[0x4e0] = 1;
    param_1[0x4e1] = 0;
    param_1[0x4e2] = 0;
    param_1[0x4e3] = 0;
    if ((param_2 != '\0') && (*(longlong *)(param_1 + 0x468) != 0)) {
      uVar5 = 0;
      if (*(int *)(param_1 + 1000) != 0) {
        do {
          lVar7 = *(longlong *)((ulonglong)uVar5 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x468));
          if (lVar7 != 0) {
            ExFreePoolWithTag(lVar7,0);
            *(undefined8 *)(*(longlong *)(param_1 + 0x468) + 0x10 + (ulonglong)uVar5 * 0x20) = 0;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 1000));
      }
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x468),0);
      param_1[0x468] = 0;
      param_1[0x469] = 0;
      param_1[0x46a] = 0;
      param_1[0x46b] = 0;
      param_1[0x46c] = 0;
      param_1[0x46d] = 0;
      param_1[0x46e] = 0;
      param_1[0x46f] = 0;
    }
    if (*(longlong *)(param_1 + 0x458) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x458),0);
      param_1[0x458] = 0;
      param_1[0x459] = 0;
      param_1[0x45a] = 0;
      param_1[0x45b] = 0;
      param_1[0x45c] = 0;
      param_1[0x45d] = 0;
      param_1[0x45e] = 0;
      param_1[0x45f] = 0;
    }
    if (*(longlong *)(param_1 + 0x90) != 0) {
      IoFreeIrp();
      param_1[0x90] = 0;
      param_1[0x91] = 0;
      param_1[0x92] = 0;
      param_1[0x93] = 0;
      param_1[0x94] = 0;
      param_1[0x95] = 0;
      param_1[0x96] = 0;
      param_1[0x97] = 0;
    }
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      IoFreeIrp();
    }
    if ((*(longlong *)(param_1 + 0x498) != 0) && (uVar8 = 0, *(short *)(param_1 + 0x500) != 0)) {
      do {
        uVar6 = (ulonglong)uVar8;
        lVar7 = uVar6 * 0xe0;
        if (*(longlong *)(lVar7 + 0x70 + *(longlong *)(param_1 + 0x498)) != 0) {
          IoFreeIrp();
          *(undefined8 *)(lVar7 + 0x70 + *(longlong *)(param_1 + 0x498)) = 0;
        }
        lVar3 = *(longlong *)(lVar7 + 0x50 + *(longlong *)(param_1 + 0x498));
        if (lVar3 != 0) {
          USBD_UrbFree(*(longlong *)(param_1 + 0x4f8),lVar3);
        }
        if (*(longlong *)(lVar7 + 0x78 + *(longlong *)(param_1 + 0x498)) != 0) {
          IoFreeIrp();
          *(undefined8 *)(lVar7 + 0x78 + *(longlong *)(param_1 + 0x498)) = 0;
        }
        lVar7 = *(longlong *)(lVar7 + 0x58 + *(longlong *)(param_1 + 0x498));
        if (lVar7 != 0) {
          USBD_UrbFree(*(longlong *)(param_1 + 0x4f8),lVar7);
        }
        if (*(longlong *)(uVar6 * 0xe0 + 0x80 + *(longlong *)(param_1 + 0x498)) != 0) {
          IoFreeIrp();
          *(undefined8 *)(uVar6 * 0xe0 + 0x80 + *(longlong *)(param_1 + 0x498)) = 0;
        }
        lVar7 = *(longlong *)(uVar6 * 0xe0 + 0x60 + *(longlong *)(param_1 + 0x498));
        if (lVar7 != 0) {
          USBD_UrbFree(*(longlong *)(param_1 + 0x4f8),lVar7);
        }
        if (*(longlong *)(uVar6 * 0xe0 + 0x88 + *(longlong *)(param_1 + 0x498)) != 0) {
          IoFreeIrp();
          *(undefined8 *)(uVar6 * 0xe0 + 0x88 + *(longlong *)(param_1 + 0x498)) = 0;
        }
        lVar7 = *(longlong *)(uVar6 * 0xe0 + 0x68 + *(longlong *)(param_1 + 0x498));
        if (lVar7 != 0) {
          USBD_UrbFree(*(longlong *)(param_1 + 0x4f8),lVar7);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ushort *)(param_1 + 0x500));
    }
    KeReleaseInStackQueuedSpinLock(&local_38);
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
      param_1[0x20] = 0;
      param_1[0x21] = 0;
      param_1[0x22] = 0;
      param_1[0x23] = 0;
      param_1[0x24] = 0;
      param_1[0x25] = 0;
      param_1[0x26] = 0;
      param_1[0x27] = 0;
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x28),0);
      param_1[0x28] = 0;
      param_1[0x29] = 0;
      param_1[0x2a] = 0;
      param_1[0x2b] = 0;
      param_1[0x2c] = 0;
      param_1[0x2d] = 0;
      param_1[0x2e] = 0;
      param_1[0x2f] = 0;
    }
    if (*(longlong *)(param_1 + 0x38) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0);
      param_1[0x38] = 0;
      param_1[0x39] = 0;
      param_1[0x3a] = 0;
      param_1[0x3b] = 0;
      param_1[0x3c] = 0;
      param_1[0x3d] = 0;
      param_1[0x3e] = 0;
      param_1[0x3f] = 0;
    }
    if (*(longlong *)(param_1 + 0x48) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x48),0);
      param_1[0x48] = 0;
      param_1[0x49] = 0;
      param_1[0x4a] = 0;
      param_1[0x4b] = 0;
      param_1[0x4c] = 0;
      param_1[0x4d] = 0;
      param_1[0x4e] = 0;
      param_1[0x4f] = 0;
    }
    lVar7 = *(longlong *)(param_1 + 0x4f8);
    if (lVar7 != 0) {
      *(undefined1 *)(lVar7 + 0xe1) = 1;
      LOCK();
      piVar1 = (int *)(lVar7 + 0xdc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 < 2) {
        if (*(char *)(lVar7 + 0xe1) == '\0') {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,
                       "UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                       lVar7);
          }
        }
        else {
          if (*(code **)(lVar7 + 0x70) != (code *)0x0) {
            (**(code **)(lVar7 + 0x70))(*(undefined8 *)(lVar7 + 0x30));
          }
          ExFreePoolWithTag(lVar7,*(undefined4 *)(lVar7 + 0x40));
        }
      }
      param_1[0x4f8] = 0;
      param_1[0x4f9] = 0;
      param_1[0x4fa] = 0;
      param_1[0x4fb] = 0;
      param_1[0x4fc] = 0;
      param_1[0x4fd] = 0;
      param_1[0x4fe] = 0;
      param_1[0x4ff] = 0;
    }
    if (*(longlong *)(param_1 + 0x480) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x480),0);
      param_1[0x480] = 0;
      param_1[0x481] = 0;
      param_1[0x482] = 0;
      param_1[0x483] = 0;
      param_1[0x484] = 0;
      param_1[0x485] = 0;
      param_1[0x486] = 0;
      param_1[0x487] = 0;
    }
    if (*(longlong *)(param_1 + 0x4a0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x4a0),0);
      param_1[0x4a0] = 0;
      param_1[0x4a1] = 0;
      param_1[0x4a2] = 0;
      param_1[0x4a3] = 0;
      param_1[0x4a4] = 0;
      param_1[0x4a5] = 0;
      param_1[0x4a6] = 0;
      param_1[0x4a7] = 0;
    }
    if (*(longlong *)(param_1 + 0x498) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x498),0);
      param_1[0x498] = 0;
      param_1[0x499] = 0;
      param_1[0x49a] = 0;
      param_1[0x49b] = 0;
      param_1[0x49c] = 0;
      param_1[0x49d] = 0;
      param_1[0x49e] = 0;
      param_1[0x49f] = 0;
    }
    if (*(longlong *)(param_1 + 0x4c8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x4c8),0);
      param_1[0x4c8] = 0;
      param_1[0x4c9] = 0;
      param_1[0x4ca] = 0;
      param_1[0x4cb] = 0;
      param_1[0x4cc] = 0;
      param_1[0x4cd] = 0;
      param_1[0x4ce] = 0;
      param_1[0x4cf] = 0;
    }
    if (*(longlong *)(param_1 + 0x578) != 0) {
      ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x578) + 0x18),0);
      ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x578) + 0x20),0);
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x578),0);
      param_1[0x578] = 0;
      param_1[0x579] = 0;
      param_1[0x57a] = 0;
      param_1[0x57b] = 0;
      param_1[0x57c] = 0;
      param_1[0x57d] = 0;
      param_1[0x57e] = 0;
      param_1[0x57f] = 0;
    }
    if (*(longlong *)(param_1 + 0x598) != 0) {
      IoFreeMdl();
      param_1[0x598] = 0;
      param_1[0x599] = 0;
      param_1[0x59a] = 0;
      param_1[0x59b] = 0;
      param_1[0x59c] = 0;
      param_1[0x59d] = 0;
      param_1[0x59e] = 0;
      param_1[0x59f] = 0;
    }
    FreeReservedMDLs((longlong)param_1);
    if (*(longlong *)(param_1 + 200) != 0) {
      IoFreeWorkItem();
      param_1[200] = 0;
      param_1[0xc9] = 0;
      param_1[0xca] = 0;
      param_1[0xcb] = 0;
      param_1[0xcc] = 0;
      param_1[0xcd] = 0;
      param_1[0xce] = 0;
      param_1[0xcf] = 0;
    }
    *param_1 = *param_1 & 0xfd;
  }
  return;
}



===== UaspHwPassiveInit @ 140004800 =====

undefined1 UaspHwPassiveInit(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  undefined1 uVar6;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  uVar6 = 1;
  UaspFreeResources(param_1,'\0');
  ExReInitializeRundownProtection(param_1 + 0x508);
  pbVar5 = param_1 + 0x548;
  *(byte **)(param_1 + 0x550) = pbVar5;
  *(byte **)pbVar5 = pbVar5;
  KeInitializeEvent(param_1 + 0x580,0,1);
  KeInitializeSpinLock(param_1 + 0x80);
  param_1[0x158] = 0;
  param_1[0x159] = 0;
  param_1[0x15a] = 0;
  param_1[0x15b] = 0;
  param_1[0x15c] = 0;
  param_1[0x15d] = 0;
  param_1[0x15e] = 0;
  param_1[0x15f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  pbVar5 = param_1;
  iVar2 = UasInitializeDevice((longlong)param_1,*(longlong *)(param_1 + 8),
                              *(longlong *)(param_1 + 0x10),param_4);
  *param_1 = *param_1 | 2;
  if (iVar2 == 0) {
    puVar4 = (undefined4 *)UaspAllocatePool(pbVar5,0x58);
    *(undefined4 **)(param_1 + 0x458) = puVar4;
    if (puVar4 == (undefined4 *)0x0) goto LAB_140004a5a;
    *puVar4 = 2;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 4) = 0x18;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 8) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0xc) = 0x10;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x10) = 0;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x18) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x1c) = 0x20;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x20) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x24) = 0;
    lVar1 = *(longlong *)(param_1 + 0x458);
    *(undefined4 *)(lVar1 + 0x28) = 0xdcaf9c10;
    *(undefined4 *)(lVar1 + 0x2c) = 0x481f895f;
    *(undefined4 *)(lVar1 + 0x30) = 0xced492a4;
    *(undefined4 *)(lVar1 + 0x34) = 0x3356f5d2;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x38) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x3c) = 0x20;
    *(undefined8 *)(*(longlong *)(param_1 + 0x458) + 0x40) = 0;
    *(undefined8 *)(*(longlong *)(param_1 + 0x458) + 0x48) = 0;
    *(undefined4 *)(*(longlong *)(param_1 + 0x458) + 0x50) = 0xffffffff;
    iVar2 = StorPortExtendedFunction(0x30,param_1,0,*(undefined8 *)(param_1 + 0x458),local_res8);
    if (iVar2 == 0) goto LAB_140004a5a;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_D(uVar3,2,1,0xc,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,(char)iVar2);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x458),0);
    param_1[0x458] = 0;
    param_1[0x459] = 0;
    param_1[0x45a] = 0;
    param_1[0x45b] = 0;
    param_1[0x45c] = 0;
    param_1[0x45d] = 0;
    param_1[0x45e] = 0;
    param_1[0x45f] = 0;
  }
  else {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_D(uVar3,2,1,0xb,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,(char)iVar2);
    }
    UaspFreeResources(param_1,'\x01');
  }
  uVar6 = 0;
LAB_140004a5a:
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PD(uVar3,4,3,0xd,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,(char)param_1,
                       uVar6);
  }
  return uVar6;
}



===== UaspInitialize @ 140004ad0 =====

undefined1 UaspInitialize(undefined8 param_1)

{
  undefined1 uVar1;
  undefined4 local_res10 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = 1;
  local_38 = 8;
  local_34 = 0x28;
  local_30 = 1;
  local_2c = 1;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  StorPortExtendedFunction(0xe,param_1,0,&local_38);
  local_res10[0] = 0;
  StorPortNotification(0x1000,param_1,UaspHwPassiveInit,local_res10);
  if ((char)local_res10[0] == '\0') {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,1,10,
                       &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== UaspInitializeTracing @ 140004bb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UaspInitializeTracing(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  _DAT_140012168 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140012150 = 0;
  local_28 = 0;
  uStack_20 = 0;
  DAT_140012148 = &WPP_ThisDir_CTLGUID_Uasp;
  _DAT_140012160 = 0;
  _DAT_140012180 = 0;
  _DAT_140012188 = 0;
  WppLoadTracingSupport();
  _DAT_140012160 = 0;
  WppInitKm(param_1,param_2);
  uStack_20 = 0x200000002;
  local_28 = CONCAT35(local_28._5_3_,0x100000010);
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_28);
  return;
}



===== UaspProcessServiceRequest @ 140004c90 =====

void UaspProcessServiceRequest(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  StorPortExtendedFunction(7,param_1,param_2);
  return;
}



===== UaspResetBus @ 140004cc0 =====

bool UaspResetBus(longlong param_1)

{
  bool bVar1;
  undefined8 uVar2;
  
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_(uVar2,4,3,0xe,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
  }
  if (*(longlong *)(param_1 + 0x68) == 0) {
    *(undefined8 *)(param_1 + 0xa0) = 0;
    UaspQueueWorkItem(param_1,0x140006ee0,0,0);
    *(int *)(param_1 + 0x558) = *(int *)(param_1 + 0x558) + 1;
    bVar1 = true;
  }
  else {
    bVar1 = UaspDumpReset(param_1);
  }
  return bVar1;
}



===== UaspUnitControl @ 140004d70 =====

undefined4 UaspUnitControl(longlong param_1,int param_2,longlong param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined **ppuVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 uVar12;
  undefined1 local_res10 [8];
  undefined8 in_stack_ffffffffffffffa8;
  
  ppuVar9 = &WPP_RECORDER_INITIALIZED;
  uVar12 = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_3 + 5) = 0x1010101;
    *(undefined1 *)(param_3 + 4) = 1;
    *(undefined2 *)(param_3 + 10) = 0x101;
    goto LAB_1400052ea;
  }
  if (param_2 == 1) {
    if (*(int *)(param_1 + 0x568) == 0) {
      *(undefined4 *)(param_1 + 0x568) = *(undefined4 *)(param_3 + 8);
    }
    if (*(int *)(param_3 + 8) != 1) {
      if (*(int *)(param_3 + 8) == 4) {
        *(undefined1 *)(param_1 + 0x3db) = 1;
        UaspDetectPortableWorkspace(param_1);
      }
      goto LAB_1400052ea;
    }
    if (*(char *)(param_1 + 0x3dc) != '\0') goto LAB_1400052ea;
    uVar5 = AllocateReservedMDLs(param_1);
    if (-1 < (int)uVar5) {
      iVar4 = UaspNotifyForwardProgress(param_1);
      if (-1 < iVar4) {
        *(undefined1 *)(param_1 + 0x3dc) = 1;
        goto LAB_1400052ea;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar5,2,1,0x16,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,
                          (char)iVar4);
      }
      FreeReservedMDLs(param_1);
    }
LAB_14000513b:
    uVar12 = 1;
  }
  else {
    if (param_2 == 3) {
      if (gTracingEnabled == '\0') {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_DDD(uVar5);
      }
      goto LAB_1400052ea;
    }
    if (param_2 == 4) {
      lVar2 = *(longlong *)(param_3 + 8);
      bVar3 = *(byte *)(lVar2 + 10);
      uVar6 = (ulonglong)bVar3;
      lVar11 = (ulonglong)bVar3 * 0x20 + *(longlong *)(param_1 + 0x468);
      if (*(longlong *)(param_1 + 0x468) != 0) {
        if (*(char *)(param_3 + 0x10) == '\0') {
          if ((gTracingEnabled != '\0') &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            WPP_RECORDER_SF_D(uVar5,4,3,0x1b,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,bVar3)
            ;
          }
          uVar12 = 0;
          if (*(longlong *)(lVar11 + 0x10) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar11 + 0x10),0);
            *(undefined8 *)(lVar11 + 0x10) = 0;
          }
          goto LAB_1400052ea;
        }
        local_res10[0] = 0;
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_D(uVar6,4,3,0x19,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,bVar3);
        }
        if (*(longlong *)(lVar11 + 0x10) != 0) goto LAB_1400052ea;
        puVar7 = (undefined4 *)UaspAllocatePool(uVar6,0x58);
        *(undefined4 **)(lVar11 + 0x10) = puVar7;
        if (puVar7 == (undefined4 *)0x0) goto LAB_1400052ea;
        *puVar7 = 2;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 4) = 0x18;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x10) = 15000;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0xc) = 0x10;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 8) = 1;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x18) = 1;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x1c) = 0x20;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x20) = 1;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x24) = 0;
        lVar8 = *(longlong *)(lVar11 + 0x10);
        *(undefined4 *)(lVar8 + 0x28) = 0x585d326b;
        *(undefined4 *)(lVar8 + 0x2c) = 0x40880b3a;
        *(undefined4 *)(lVar8 + 0x30) = 0xb0883989;
        *(undefined4 *)(lVar8 + 0x34) = 0xbe58690f;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x38) = 1;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x3c) = 0x20;
        *(undefined8 *)(*(longlong *)(lVar11 + 0x10) + 0x40) = 0;
        *(undefined8 *)(*(longlong *)(lVar11 + 0x10) + 0x48) = 0;
        *(undefined4 *)(*(longlong *)(lVar11 + 0x10) + 0x50) = 0xffffffff;
        lVar8 = param_1;
        lVar10 = lVar2;
        iVar4 = StorPortExtendedFunction
                          (0x30,param_1,lVar2,*(undefined8 *)(lVar11 + 0x10),local_res10);
        if (iVar4 == 0) goto LAB_1400052ea;
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar1 = *(undefined1 *)(lVar2 + 10);
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_dD(uVar5,lVar8,lVar10,0x1a,
                             &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,uVar1,(char)iVar4);
        }
        StorPortExtendedFunction(1,param_1,*(undefined8 *)(lVar11 + 0x10));
        *(undefined8 *)(lVar11 + 0x10) = 0;
        goto LAB_14000513b;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar5,2,3,0x18,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids);
      }
    }
    else if (param_2 == 6) {
      lVar2 = *(longlong *)(param_3 + 8);
      lVar11 = *(longlong *)(param_1 + 0x468);
      bVar3 = *(byte *)(lVar2 + 10);
      if (*(longlong *)((ulonglong)bVar3 * 0x20 + 0x10 + lVar11) != 0) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar1 = *(undefined1 *)(param_3 + 0x14);
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_dd(uVar5,lVar11,ppuVar9,0x1c,in_stack_ffffffffffffffa8,uVar1,bVar3);
          bVar3 = *(byte *)(lVar2 + 10);
          lVar11 = *(longlong *)(param_1 + 0x468);
        }
        *(bool *)((ulonglong)bVar3 * 0x20 + 0x18 + lVar11) = *(char *)(param_3 + 0x14) != '\0';
        goto LAB_1400052ea;
      }
    }
    else if (param_2 == 7) {
      bVar3 = *(byte *)(*(longlong *)(param_3 + 8) + 10);
      uVar6 = (ulonglong)bVar3;
      if (*(longlong *)(uVar6 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x468)) != 0) {
        if (gTracingEnabled == '\0') {
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_dd(uVar5,uVar6,ppuVar9,0x1d,in_stack_ffffffffffffffa8,
                             (char)*(undefined4 *)(param_3 + 0x14),bVar3);
        }
        goto LAB_1400052ea;
      }
    }
    else if ((gTracingEnabled != '\0') &&
            ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_D(uVar5,4,3,0x1e,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,
                        (char)param_2);
    }
    uVar12 = 1;
  }
LAB_1400052ea:
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_DqD(uVar5);
  }
  return uVar12;
}



===== WPP_RECORDER_SF_DDD @ 140005350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x17,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x17,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DqD @ 14000543c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DqD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x1f,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x1f,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_dD @ 140005530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 140005604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_PD @ 1400056d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 140005800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x20,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_7740b34c14c638f69bf7694cfa8deaf7_Traceguids,0x20,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WppClassicProviderCallback @ 140005900 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== wil_details_RecordCachedUsage @ 14000595c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005ab0 =====

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



===== AllocateIUPool @ 140005b34 =====

undefined8 AllocateIUPool(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar2 = UaspAllocatePool(param_1,((-(ulonglong)(*(char *)(param_1 + 0x3da) != '\0') &
                                    0xfffffffffffffc00) + 0xc30) *
                                   (ulonglong)*(ushort *)(param_1 + 0x500));
  if (lVar2 == 0) {
    uVar4 = 0xc000009a;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar3,2,1,0xc,&WPP_36185c522d943f8d0ee1935152861c3e_Traceguids);
    }
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x500);
    *(longlong *)(param_1 + 0x4a0) = lVar2;
    lVar2 = lVar2 + (ulonglong)uVar1 * 0x20;
    *(longlong *)(param_1 + 0x4b0) = lVar2;
    lVar2 = lVar2 + (ulonglong)uVar1 * 0x400;
    *(longlong *)(param_1 + 0x4b8) = lVar2;
    lVar2 = lVar2 + (ulonglong)uVar1 * 0x10;
    *(longlong *)(param_1 + 0x4c0) = lVar2;
    if (*(char *)(param_1 + 0x3da) == '\0') {
      *(ulonglong *)(param_1 + 0x4a8) = (ulonglong)uVar1 * 0x400 + lVar2;
    }
  }
  return uVar4;
}



===== AllocateRequestContextPool @ 140005c34 =====

undefined8 AllocateRequestContextPool(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  lVar1 = UaspAllocatePool(param_1,(ulonglong)*(ushort *)(param_1 + 0x500) * 0xa0);
  if (lVar1 == 0) {
    uVar4 = 0xc000009a;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar2,2,1,0xb,&WPP_36185c522d943f8d0ee1935152861c3e_Traceguids);
    }
  }
  else {
    *(longlong *)(param_1 + 0x480) = lVar1;
    lVar3 = (ulonglong)*(ushort *)(param_1 + 0x500) * 0x28;
    *(longlong *)(param_1 + 0x478) = lVar1 + lVar3;
    lVar1 = lVar1 + lVar3 + lVar3;
    *(longlong *)(param_1 + 0x488) = lVar1;
    *(longlong *)(param_1 + 0x490) = lVar3 + lVar1;
  }
  return uVar4;
}



===== AllocateReservedMDLs @ 140005cfc =====

undefined8 AllocateReservedMDLs(longlong param_1)

{
  longlong lVar1;
  
  *(undefined8 *)(param_1 + 0x5a0) = 0;
  *(undefined8 *)(param_1 + 0x5a8) = 0;
  *(undefined8 *)(param_1 + 0x5b0) = 0;
  lVar1 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x4a0),0x20,0,0,0);
  if (lVar1 != 0) {
    MmBuildMdlForNonPagedPool(lVar1);
    *(longlong *)(param_1 + 0x5a0) = lVar1;
    lVar1 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x4b0),0x400,0,0,0);
    if (lVar1 != 0) {
      MmBuildMdlForNonPagedPool(lVar1);
      *(longlong *)(param_1 + 0x5a8) = lVar1;
      if (*(longlong *)(param_1 + 0x4a8) == 0) {
        return 0;
      }
      lVar1 = IoAllocateMdl(*(longlong *)(param_1 + 0x4a8),0x400,0,0,0);
      if (lVar1 != 0) {
        MmBuildMdlForNonPagedPool(lVar1);
        *(longlong *)(param_1 + 0x5b0) = lVar1;
        return 0;
      }
    }
  }
  FreeReservedMDLs(param_1);
  return 0xc000009a;
}



===== FreeReservedMDLs @ 140005e18 =====

void FreeReservedMDLs(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x5a0) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x5a0) = 0;
  }
  if (*(longlong *)(param_1 + 0x5b0) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x5b0) = 0;
  }
  if (*(longlong *)(param_1 + 0x5a8) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x5a8) = 0;
  }
  return;
}



===== UaspAllocatePool @ 140005e90 =====

longlong UaspAllocatePool(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0x75617370;
  uVar3 = param_2;
  lVar1 = ExAllocatePool2(0x40);
  if (((lVar1 == 0) && (gTracingEnabled != '\0')) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_dD(uVar2,uVar3,uVar4,10,&WPP_36185c522d943f8d0ee1935152861c3e_Traceguids,
                       (char)param_2,0x70);
  }
  return lVar1;
}



===== UaspCompleteWorkItem @ 140005f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UaspCompleteWorkItem(longlong *param_1,int param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar5 = param_1[1];
  lVar1 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (lVar5 != 0) {
    if (param_2 < 0) {
      *(char *)(lVar5 + 3) = (param_2 == -0x7fffffef) + '\x04';
    }
    else {
      *(undefined1 *)(lVar5 + 3) = 1;
    }
    StorPortNotification(0,lVar1);
  }
  KeAcquireInStackQueuedSpinLock(lVar1 + 0x80,&local_28);
  plVar3 = param_1 + 4;
  lVar5 = *plVar3;
  if ((*(longlong **)(lVar5 + 8) != plVar3) ||
     (plVar2 = (longlong *)param_1[5], (longlong *)*plVar2 != plVar3)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar2 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar2;
  plVar3 = *(longlong **)(lVar1 + 0x548);
  lVar5 = (longlong)(plVar3 + -4);
  if (plVar3 == (longlong *)(lVar1 + 0x548)) {
    lVar5 = 0;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (param_1 == (longlong *)(lVar1 + 0x518)) {
    *(undefined1 *)(lVar1 + 0x510) = 0;
  }
  else {
    ExFreePoolWithTag(param_1,0);
  }
  if (lVar5 != 0) {
    (**(code **)(lVar5 + 0x18))(*(undefined8 *)(lVar1 + 8),lVar5);
  }
  ExReleaseRundownProtection(lVar1 + 0x508);
  return;
}



===== UaspDetectPortableWorkspace @ 140006064 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined ** UaspDetectPortableWorkspace(longlong param_1)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined1 auStackY_268 [32];
  char local_238 [4];
  int local_234;
  int local_230 [2];
  undefined8 local_228;
  undefined4 local_220;
  undefined4 uStack_21c;
  wchar_t *pwStack_218;
  undefined1 local_208 [8];
  undefined4 local_200;
  wchar_t *local_1f8;
  int *local_1f0;
  undefined4 local_1e8;
  undefined4 local_1c8;
  wchar_t *local_1c0;
  int *local_1b8;
  undefined4 local_1b0;
  wchar_t local_158 [80];
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  local_234 = 0;
  local_230[0] = 0;
  local_238[0] = '\0';
  memset(local_158,0,0x9a);
  local_230[1] = 0;
  local_228 = 0;
  _local_220 = 0;
  pwStack_218 = (wchar_t *)0x0;
  ppuVar3 = (undefined **)RtlCheckPortableOperatingSystem(local_238);
  if ((int)ppuVar3 == -0x3ffffddb) {
    memset(local_208,0,0xa8);
    pwStack_218 = local_158;
    local_220 = CONCAT22(0x9a,(undefined2)local_220);
    local_1f8 = L"ContainerID";
    local_1f0 = &local_220;
    local_200 = 0x124;
    local_1e8 = 0x1000000;
    ppuVar3 = (undefined **)
              RtlQueryRegistryValuesEx
                        (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Enum\\HTREE\\ROOT\\0",
                         local_208,0);
    iVar1 = (int)ppuVar3;
    if (iVar1 < 0) goto LAB_14000628c;
    ppuVar3 = (undefined **)IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x10),0x16,0x9a,local_b8);
    iVar1 = (int)ppuVar3;
    if (iVar1 < 0) goto LAB_14000628c;
    iVar1 = _wcsnicmp(local_b8,local_158,0x4d);
    local_238[0] = iVar1 != 0;
    ppuVar3 = (undefined **)RtlSetPortableOperatingSystem();
  }
  iVar1 = (int)ppuVar3;
  if (local_238[0] != '\0') {
    local_234 = 1;
    memset(local_208,0,0xa8);
    local_1f8 = L"Hibernate";
    local_1f0 = local_230;
    local_200 = 0x120;
    local_1c0 = L"Sleep";
    local_1b8 = &local_234;
    local_1e8 = 0x4000000;
    local_1c8 = 0x120;
    local_1b0 = 0x4000000;
    iVar2 = RtlQueryRegistryValuesEx
                      (0,
                       L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Microsoft\\PortableOperatingSystem"
                       ,local_208,0);
    if (-1 < iVar1) {
      iVar1 = iVar2;
    }
    ppuVar3 = (undefined **)(ulonglong)(uint)-local_234;
    bVar5 = ~-(local_234 != 0) & 7U | ~-(local_230[0] != 0) & 8U;
    if (bVar5 != 0) {
      ppuVar3 = (undefined **)PoDisableSleepStates(3,bVar5,&local_228);
      if (iVar1 < 0) goto LAB_14000628c;
      iVar1 = (int)ppuVar3;
    }
  }
  if (-1 < iVar1) {
    return ppuVar3;
  }
LAB_14000628c:
  if ((gTracingEnabled != '\0') &&
     (ppuVar3 = &WPP_RECORDER_INITIALIZED,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    ppuVar3 = (undefined **)
              WPP_RECORDER_SF_D(uVar4,2,1,0x13,&WPP_36185c522d943f8d0ee1935152861c3e_Traceguids,
                                (char)iVar1);
  }
  return ppuVar3;
}



===== UaspQueueWorkItem @ 140006310 =====

int UaspQueueWorkItem(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  char cVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [56];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  iVar10 = 0;
  lVar7 = param_1 + 0x508;
  cVar3 = ExAcquireRundownProtection();
  puVar11 = auStack_88;
  if (cVar3 == '\0') {
    iVar10 = -0x3fffffaa;
    goto LAB_140006490;
  }
  plVar4 = (longlong *)UaspAllocatePool(lVar7,0x30);
  KeAcquireInStackQueuedSpinLock(param_1 + 0x80,&local_48);
  puVar11 = auStack_88;
  puVar1 = (undefined8 *)(param_1 + 0x548);
  for (puVar8 = (undefined8 *)*puVar1; plVar12 = plVar4, puVar8 != puVar1;
      puVar8 = (undefined8 *)*puVar8) {
    if ((puVar8[-1] == param_2) && (puVar8[-2] == param_4)) {
      iVar10 = -0x7fffffef;
      goto LAB_1400063c7;
    }
  }
  if (*(char *)(param_1 + 0x510) == '\0') {
    plVar4 = (longlong *)(param_1 + 0x518);
    *(undefined1 *)(param_1 + 0x510) = 1;
LAB_140006408:
    puVar8 = (undefined8 *)*puVar1;
    plVar4[2] = param_4;
    plVar5 = plVar4 + 4;
    *plVar4 = param_1;
    plVar4[3] = param_2;
    plVar4[1] = param_3;
    puVar9 = *(undefined8 **)(param_1 + 0x550);
    if ((undefined8 *)*puVar9 != puVar1) {
      puVar9 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar5 = (longlong *)(*pcVar2)();
      puVar11 = auStack_80;
    }
    plVar5[1] = (longlong)puVar9;
    *plVar5 = (longlong)puVar1;
    *puVar9 = plVar5;
    *(longlong **)(param_1 + 0x550) = plVar5;
    *(undefined8 *)(puVar11 + -8) = 0x140006450;
    KeReleaseInStackQueuedSpinLock(puVar11 + 0x40);
    if (puVar8 == puVar1) {
      uVar6 = *(undefined8 *)(param_1 + 200);
      *(undefined8 *)(puVar11 + -8) = 0x140006471;
      IoQueueWorkItem(uVar6,param_2,0,plVar4);
    }
  }
  else {
    if (plVar4 != (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      goto LAB_140006408;
    }
    iVar10 = -0x3fffff66;
LAB_1400063c7:
    KeReleaseInStackQueuedSpinLock(&local_48);
    ExReleaseRundownProtection(param_1 + 0x508);
    puVar11 = auStack_88;
  }
  if (plVar12 != (longlong *)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x140006487;
    ExFreePoolWithTag(plVar12,0);
  }
  if (-1 < iVar10) {
    return iVar10;
  }
LAB_140006490:
  if (param_3 != 0) {
    *(undefined1 *)(param_3 + 3) = 4;
    *(undefined8 *)(puVar11 + -8) = 0x1400064a9;
    StorPortNotification(0,param_1,param_3);
  }
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    *(undefined8 *)(puVar11 + -8) = 0x1400064da;
    uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    *(int *)(puVar11 + 0x30) = iVar10;
    *(longlong *)(puVar11 + 0x28) = param_3;
    *(undefined **)(puVar11 + 0x20) = &WPP_36185c522d943f8d0ee1935152861c3e_Traceguids;
    *(undefined8 *)(puVar11 + -8) = 0x140006506;
    WPP_RECORDER_SF_PD(uVar6,2,1,0x14,*(undefined8 *)(puVar11 + 0x20),puVar11[0x28],puVar11[0x30]);
  }
  return iVar10;
}



===== UaspGetDescriptor @ 140006530 =====

int UaspGetDescriptor(longlong param_1,undefined8 param_2,char param_3,undefined1 param_4,
                     undefined2 param_5,undefined8 param_6,int param_7,longlong *param_8)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = 2;
  *param_8 = 0;
  lVar2 = ExAllocatePool2(0x40,param_7,0x75617370);
  *param_8 = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x75617370);
    if (puVar3 == (undefined4 *)0x0) {
      ExFreePoolWithTag(*param_8,0);
      *param_8 = 0;
      iVar1 = -0x3fffff66;
    }
    else {
      do {
        lVar2 = *param_8;
        *(undefined8 *)(puVar3 + 0xc) = 0;
        *(undefined8 *)(puVar3 + 0xe) = 0;
        *(longlong *)(puVar3 + 10) = lVar2;
        *puVar3 = 0xb0088;
        puVar3[9] = param_7;
        *(char *)((longlong)puVar3 + 0x83) = param_3;
        *(undefined1 *)((longlong)puVar3 + 0x82) = param_4;
        *(undefined2 *)(puVar3 + 0x21) = param_5;
        iVar1 = UaspSyncSendUsbRequestNew(0,param_1,puVar3,'\0');
        if (-1 < iVar1) {
          if ((param_7 == puVar3[9]) && (param_3 == *(char *)(*param_8 + 1))) break;
          iVar1 = -0x3fffff64;
        }
        bVar5 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar5);
      ExFreePoolWithTag(puVar3,0);
    }
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if (*param_8 != 0) {
    ExFreePoolWithTag(*param_8,0);
    *param_8 = 0;
  }
  return iVar1;
}



===== UaspGetDescriptors @ 140006690 =====

int UaspGetDescriptors(longlong param_1,undefined8 param_2,longlong param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res10 = 0;
  iVar2 = UaspGetDescriptor(param_3,param_2,'\x01',0,0,in_stack_ffffffffffffffd0,0x12,&local_res10);
  if (-1 < iVar2) {
    *(longlong *)(param_1 + 0x20) = local_res10;
    iVar2 = UaspGetDescriptor(param_3,param_2,'\x02',0,0,in_stack_ffffffffffffffd0,9,&local_res10);
    if (-1 < iVar2) {
      uVar3 = 0;
      uVar1 = *(ushort *)(local_res10 + 2);
      ExFreePoolWithTag();
      if (uVar1 < 9) {
        iVar2 = -0x3fffff64;
      }
      else {
        iVar2 = UaspGetDescriptor(param_3,uVar3,'\x02',0,0,in_stack_ffffffffffffffd0,(uint)uVar1,
                                  &local_res10);
        if (-1 < iVar2) {
          if (uVar1 < *(ushort *)(local_res10 + 2)) {
            iVar2 = -0x3fffff64;
            ExFreePoolWithTag(local_res10,0);
          }
          else {
            *(longlong *)(param_1 + 0x28) = local_res10;
            if (*(char *)(*(longlong *)(param_1 + 0x20) + 0x10) != '\0') {
              UaspGetStringDescriptors(param_1,uVar3,param_3);
            }
          }
        }
      }
    }
  }
  return iVar2;
}



===== UaspGetStringDescriptors @ 1400067bc =====

int UaspGetStringDescriptors(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  byte *local_res10;
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res10 = (byte *)0x0;
  iVar2 = UaspGetDescriptor(param_3,param_2,'\x03',0,0,in_stack_ffffffffffffffd0,2,
                            (longlong *)&local_res10);
  if (iVar2 < 0) {
    return iVar2;
  }
  uVar5 = 0;
  bVar1 = *local_res10;
  ExFreePoolWithTag();
  if ((3 < bVar1) && ((bVar1 & 1) == 0)) {
    iVar2 = UaspGetDescriptor(param_3,uVar5,'\x03',0,0,in_stack_ffffffffffffffd0,(uint)bVar1,
                              (longlong *)&local_res10);
    if (iVar2 < 0) {
      return iVar2;
    }
    uVar6 = 2;
    uVar7 = *(undefined2 *)(local_res10 + 2);
    uVar3 = (uint)((ulonglong)bVar1 - 2 >> 1);
    if (1 < uVar3) {
      do {
        if (*(short *)(local_res10 + uVar6 * 2) == 0x409) {
          uVar7 = 0x409;
          break;
        }
        uVar4 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar4;
      } while (uVar4 <= uVar3);
    }
    uVar5 = 0;
    ExFreePoolWithTag(local_res10);
    iVar2 = UaspGetDescriptor(param_3,uVar5,'\x03',
                              *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x10),uVar7,
                              in_stack_ffffffffffffffd0,2,(longlong *)&local_res10);
    if (iVar2 < 0) {
      return iVar2;
    }
    uVar5 = 0;
    bVar1 = *local_res10;
    ExFreePoolWithTag();
    if ((3 < bVar1) && ((bVar1 & 1) == 0)) {
      iVar2 = UaspGetDescriptor(param_3,uVar5,'\x03',
                                *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x10),uVar7,
                                in_stack_ffffffffffffffd0,(uint)bVar1,(longlong *)&local_res10);
      if (iVar2 < 0) {
        return iVar2;
      }
      *(byte **)(param_1 + 0x38) = local_res10;
      return iVar2;
    }
  }
  return -0x3fffff64;
}



===== UaspInternalDeviceIoControl @ 140006950 =====

int UaspInternalDeviceIoControl
              (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 *)(lVar1 + -0x40) = param_6;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = param_2;
    *(undefined4 *)(lVar1 + -0x38) = param_4;
    *(undefined8 *)(lVar3 + 0x70) = param_5;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 0x18) = param_3;
    *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(param_1,lVar3);
    if (iVar2 == 0x103) {
      iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if (iVar2 == 0x102) {
        IoCancelIrp(lVar3);
        KeWaitForSingleObject(&local_28,0,0,0,0);
        iVar2 = -0x3fffff4b;
      }
      else {
        iVar2 = *(int *)(lVar3 + 0x30);
      }
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== UaspNotifyForwardProgress @ 140006ab4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UaspNotifyForwardProgress(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  undefined4 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_88 = 0;
  local_98 = 0;
  uStack_90 = 0;
  KeInitializeEvent(&local_98,0,0);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x10) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c)));
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    memset(&local_78,0,0x58);
    local_68 = 0;
    local_58 = 0x1000;
    local_78 = 1;
    local_74 = 0x58;
    local_64 = 4;
    local_60 = *(undefined8 *)(*(longlong *)(param_1 + 0x450) + 8);
    local_48 = 0x1000;
    local_50 = *(undefined8 *)(*(longlong *)(param_1 + 0x448) + 8);
    local_38 = 0x1000;
    local_40 = *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 8);
    local_28 = 0x1000;
    local_30 = *(undefined8 *)(*(longlong *)(param_1 + 0x58) + 8);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 **)(lVar1 + -0x40) = &local_78;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x49140f;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_98;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar3);
    if (iVar2 == 0x103) {
      local_a8 = 0;
      iVar2 = KeWaitForSingleObject(&local_98,0,0,0);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== USBD_SyncCompletionRoutine @ 140006c50 =====

undefined8 USBD_SyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== UaspSyncSendUsbRequestNew @ 140006c7c =====

int UaspSyncSendUsbRequestNew(longlong param_1,longlong param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeInitializeEvent(&local_38,1,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220003;
    if ((param_4 != '\0') && (*(int *)(*(longlong *)(param_1 + 0x4f8) + 0xd8) - 0x602U < 0xfffff9fd)
       ) {
      *(undefined8 *)(lVar1 + -0x18) = param_3;
    }
    *(undefined8 *)(lVar1 + -0x40) = param_3;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_38;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(param_2,lVar3);
    if (iVar2 == 0x103) {
      local_res10 = 0xfffffffffd050f80;
      iVar2 = KeWaitForSingleObject(&local_38,0,0,0,&local_res10);
      if (iVar2 == 0x102) {
        iVar2 = -0x3fffff4b;
        IoCancelIrp(lVar3);
        KeWaitForSingleObject(&local_38,0,0,0,0);
      }
      else {
        iVar2 = *(int *)(lVar3 + 0x30);
      }
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== AbortPipe @ 140006df0 =====

int AbortPipe(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x75617370);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x20028;
    *(undefined8 *)(puVar2 + 6) = param_2;
    iVar1 = UaspSyncSendUsbRequestNew(0,param_1,puVar2,'\0');
    ExFreePoolWithTag(puVar2,0);
  }
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PD(uVar3,3,4,10,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,(char)param_2,
                       (char)iVar1);
  }
  return iVar1;
}



===== BulkResetDeviceWorkItem @ 140006ee0 =====

void BulkResetDeviceWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  uint local_res10 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar1 = *param_2;
  uVar5 = QueueCancel(lVar1);
  if ((((int)uVar5 < 0) && (gTracingEnabled != '\0')) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_(uVar5,2,1,0xc,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids);
  }
  uVar7 = 0;
  do {
    if ((*(char *)(lVar1 + 0x3db) == '\0') && (*(char *)(lVar1 + 0x3dc) == '\0')) {
      local_res10[0] = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x10) >> 8),
                                     *(undefined1 *)(*(longlong *)(lVar1 + 0x10) + 0x4c)),0);
      if (lVar6 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        KeInitializeEvent(&local_48,1,0);
        lVar2 = *(longlong *)(lVar6 + 0xb8);
        *(undefined1 *)(lVar2 + -0x48) = 0xf;
        *(undefined4 *)(lVar2 + -0x30) = 0x220013;
        *(uint **)(lVar2 + -0x40) = local_res10;
        lVar2 = *(longlong *)(lVar6 + 0xb8);
        *(code **)(lVar2 + -0x10) = USBD_SyncCompletionRoutine;
        *(undefined8 **)(lVar2 + -8) = &local_48;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10));
        if (iVar3 == 0x103) {
          KeWaitForSingleObject(&local_48,0,0,0,0);
          iVar3 = *(int *)(lVar6 + 0x30);
        }
        IoFreeIrp(lVar6);
        if (-1 < iVar3) {
          if ((local_res10[0] & 2) == 0) {
            iVar3 = -0x3fffff40;
          }
          else if (-1 < iVar3) goto LAB_14000706a;
        }
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar5,2,1,0xd,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,(char)iVar3
                         );
      }
      break;
    }
LAB_14000706a:
    local_res10[0] = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x10) >> 8),
                                   *(undefined1 *)(*(longlong *)(lVar1 + 0x10) + 0x4c)));
    if (lVar6 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      KeInitializeEvent(&local_48,1);
      lVar2 = *(longlong *)(lVar6 + 0xb8);
      *(undefined1 *)(lVar2 + -0x48) = 0xf;
      if ((*(char *)(lVar1 + 0x3db) == '\0') && (*(char *)(lVar1 + 0x3dc) == '\0')) {
        uVar4 = 0x220007;
      }
      else {
        *(uint **)(lVar2 + -0x40) = local_res10;
        uVar4 = 0x220fb3;
      }
      *(undefined4 *)(lVar2 + -0x30) = uVar4;
      lVar2 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar2 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar2 + -8) = &local_48;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10));
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(&local_48);
        iVar3 = *(int *)(lVar6 + 0x30);
      }
      IoFreeIrp(lVar6);
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar5,3,4,0xf,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,(char)iVar3
                         );
      }
      if (-1 < iVar3) goto LAB_14000725f;
    }
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_Dd(uVar5);
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 3);
  *(uint *)(lVar1 + 0x78) = *(uint *)(lVar1 + 0x78) | 1;
LAB_14000725f:
  *(undefined8 *)(lVar1 + 0xa0) = 0;
  UaspCompleteWorkItem(param_2,iVar3);
  return;
}



===== ResetPipeWorkItem @ 140007290 =====

void ResetPipeWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  lVar2 = param_2[2];
  plVar1 = (longlong *)(*param_2 + 0x10);
  if (lVar2 != *(longlong *)(*param_2 + 0x450)) {
    AbortPipe(*plVar1,lVar2);
  }
  lVar3 = *plVar1;
  puVar5 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x75617370);
  if (puVar5 == (undefined4 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    *puVar5 = 0x1e0028;
    *(longlong *)(puVar5 + 6) = lVar2;
    iVar4 = UaspSyncSendUsbRequestNew(0,lVar3,puVar5,'\0');
    ExFreePoolWithTag(puVar5,0);
  }
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PD(uVar6,3,4,0xb,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,(char)lVar2,
                       (char)iVar4);
  }
  UaspCompleteWorkItem(param_2,iVar4);
  return;
}



===== UaspGetBusInterface @ 1400073a8 =====

int UaspGetBusInterface(undefined8 param_1,longlong param_2,undefined8 param_3,void *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  memset(param_4,0,0x48);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(&local_38,1);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &USB_BUS_INTERFACE_USBDI_GUID;
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(void **)(lVar1 + -0x30) = param_4;
    *(undefined4 *)(lVar1 + -0x38) = 0x10048;
    iVar2 = IoSetCompletionRoutineEx(param_2,lVar3,USBD_SyncCompletionRoutine,&local_38,1,1,1);
    if (iVar2 < 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      iVar2 = IofCallDriver(param_3,lVar3);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
        iVar2 = *(int *)(lVar3 + 0x30);
      }
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== WPP_RECORDER_SF_Dd @ 140007500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,0xe,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_d6e86d99c60838f182e9af92ee52ce91_Traceguids,0xe,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== RtlStringCbPrintfW @ 1400075d0 =====

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



===== UaspDumpHwInterrupt @ 140007650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UaspDumpHwInterrupt(longlong param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x68) + 0x418);
  uVar2 = 0;
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(*(undefined8 *)(*(longlong *)(param_1 + 0x68) + 0x3f8),local_res8);
    if ((int)uVar2 != 0x103) {
      if (local_res8[0] == *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x50)) {
        puVar3 = *(undefined8 **)(param_1 + 0x480);
      }
      else if (local_res8[0] == *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x58)) {
        puVar3 = *(undefined8 **)(param_1 + 0x478);
      }
      else {
        puVar3 = *(undefined8 **)(param_1 + 0x488);
      }
      uVar2 = (*(code *)puVar3[3])(puVar3[1],*puVar3,uVar2 & 0xffffffff,puVar3[4]);
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== UaspDumpInitialize @ 1400076e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 UaspDumpInitialize(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined1 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x68);
  uVar4 = 1;
  iVar3 = (**(code **)(lVar1 + 0x400))(*(undefined8 *)(lVar1 + 0x3f8));
  if (iVar3 < 0) {
LAB_140007719:
    uVar4 = 0;
  }
  else {
    if (*(code **)(lVar1 + 0x420) != (code *)0x0) {
      iVar3 = (**(code **)(lVar1 + 0x420))(*(undefined8 *)(lVar1 + 0x3f8));
      if (iVar3 < 0) goto LAB_140007719;
    }
    *(undefined2 *)(param_1 + 0x500) = 1;
    *(undefined2 *)(param_1 + 0x4d0) = 0;
    *(undefined1 *)(param_1 + 0x3d9) = *(undefined1 *)(lVar1 + 0x449);
    *(undefined1 *)(param_1 + 0x3da) = *(undefined1 *)(lVar1 + 0x44a);
    *(longlong *)(param_1 + 0x450) = lVar1 + 0x50;
    *(longlong *)(param_1 + 0x478) = lVar1 + 0x268;
    *(longlong *)(param_1 + 0x480) = lVar1 + 0x290;
    *(longlong *)(param_1 + 0x488) = lVar1 + 0x2b8;
    *(longlong *)(param_1 + 0x490) = lVar1 + 0x2e0;
    *(longlong **)(param_1 + 0x498) = (longlong *)(lVar1 + 0x308);
    *(longlong *)(param_1 + 0x50) = lVar1 + 8;
    *(longlong *)(param_1 + 0x58) = lVar1 + 0x20;
    *(longlong *)(param_1 + 0x448) = lVar1 + 0x38;
    *(longlong *)(lVar1 + 0x308) = param_1;
    *(undefined2 *)(*(longlong *)(param_1 + 0x498) + 0x28) = 0;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x30) = lVar1 + 8;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x38) = lVar1 + 0x20;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x40) = lVar1 + 0x38;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x50) = lVar1 + 0x68;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x58) = lVar1 + 0x168;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x60) = lVar1 + 0xe8;
    *(longlong *)(*(longlong *)(param_1 + 0x498) + 0x68) = lVar1 + 0x1e8;
    *(undefined8 *)(*(longlong *)(param_1 + 0x498) + 0xd0) = *(undefined8 *)(param_1 + 0x488);
    *(undefined8 *)(*(longlong *)(param_1 + 0x498) + 0xd8) = *(undefined8 *)(param_1 + 0x490);
    lVar2 = *(longlong *)(lVar1 + 0x430);
    *(longlong *)(param_1 + 0x4a0) = lVar2;
    *(longlong *)(param_1 + 0x4b0) = lVar2 + 0x20;
    *(longlong *)(param_1 + 0x4b8) = lVar2 + 0x420;
    *(longlong *)(param_1 + 0x4c0) = lVar2 + 0x430;
    *(longlong *)(param_1 + 0x4a8) = lVar2 + 0x820;
    **(longlong **)(param_1 + 0x488) = lVar2 + 0x20;
    **(undefined8 **)(param_1 + 0x490) = *(undefined8 *)(param_1 + 0x4a8);
    *(undefined4 **)(param_1 + 0x4c8) = (undefined4 *)(lVar1 + 1000);
    *(undefined4 *)(lVar1 + 1000) = 1;
    *(undefined4 *)(param_1 + 0x3e0) = *(undefined4 *)(lVar1 + 4);
    *(uint *)(param_1 + 0x3e4) = *(uint *)(lVar1 + 4) >> 0xc;
    *(undefined4 *)(param_1 + 0x4e0) = 3;
  }
  return uVar4;
}



===== UaspDumpReset @ 140007918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool UaspDumpReset(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar2 = *(longlong *)(param_1 + 0x498);
  if (*(char *)(lVar1 + 0x448) == '\0') {
    *(undefined1 *)(lVar1 + 0x448) = 1;
  }
  else {
    if (*(int *)(lVar2 + 8) == 2) {
      puVar3 = *(undefined8 **)(param_1 + 0x480);
      (*(code *)puVar3[3])(lVar2,*puVar3,0xc0000120,puVar3[4]);
    }
    if (*(int *)(lVar2 + 0xc) == 2) {
      puVar3 = *(undefined8 **)(param_1 + 0x478);
      (*(code *)puVar3[3])(lVar2,*puVar3,0xc0000120,puVar3[4]);
    }
    if (*(int *)(lVar2 + 0x10) == 2) {
      puVar3 = *(undefined8 **)(param_1 + 0x488);
      (*(code *)puVar3[3])(lVar2,*puVar3,0xc0000120,puVar3[4]);
    }
    if (*(code **)(lVar1 + 0x420) != (code *)0x0) {
      iVar4 = (**(code **)(lVar1 + 0x420))(*(undefined8 *)(lVar1 + 0x3f8));
      return -1 < iVar4;
    }
  }
  return true;
}



===== UaspGetDumpPointers @ 1400079f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UaspGetDumpPointers(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *_Dst;
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 *puVar4;
  wchar_t *pwVar5;
  undefined1 uVar6;
  undefined1 auStackY_c8 [32];
  ulonglong local_88;
  uint *puStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  uint local_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  uint local_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  _Dst = *(undefined4 **)(param_2 + 0x18);
  local_88 = (ulonglong)(uint)local_88;
  memset(_Dst,0,0x70);
  _Dst[0x15] = 0xffffffff;
  pwVar5 = (wchar_t *)(_Dst + 1);
  *_Dst = 0x700100;
  _Dst[0x14] = 0x14000;
  _Dst[0xe] = 0x10000;
  _Dst[0x16] = 3;
  uVar6 = 1;
  _Dst[0x1a] = 0x1010101;
  RtlStringCbPrintfW(pwVar5,0x1e,L"uaspstor.sys",param_4);
  puVar4 = (undefined4 *)UaspAllocatePool(pwVar5,0x450);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x4500450;
    puVar4[1] = *(undefined4 *)(param_1 + 0x3e0);
    puVar1 = *(undefined8 **)(param_1 + 0x450);
    uVar2 = puVar1[1];
    *(undefined8 *)(puVar4 + 0x14) = *puVar1;
    *(undefined8 *)(puVar4 + 0x16) = uVar2;
    *(undefined8 *)(puVar4 + 0x18) = puVar1[2];
    puVar1 = *(undefined8 **)(param_1 + 0x448);
    uVar2 = puVar1[1];
    *(undefined8 *)(puVar4 + 0xe) = *puVar1;
    *(undefined8 *)(puVar4 + 0x10) = uVar2;
    *(undefined8 *)(puVar4 + 0x12) = puVar1[2];
    puVar1 = *(undefined8 **)(param_1 + 0x50);
    uVar2 = puVar1[1];
    *(undefined8 *)(puVar4 + 2) = *puVar1;
    *(undefined8 *)(puVar4 + 4) = uVar2;
    *(undefined8 *)(puVar4 + 6) = puVar1[2];
    puVar1 = *(undefined8 **)(param_1 + 0x58);
    uVar2 = puVar1[1];
    *(undefined8 *)(puVar4 + 8) = *puVar1;
    *(undefined8 *)(puVar4 + 10) = uVar2;
    *(undefined8 *)(puVar4 + 0xc) = puVar1[2];
    *(undefined4 **)(puVar4 + 0x16) = puVar4 + 0x14;
    *(undefined4 **)(puVar4 + 0x10) = puVar4 + 0xe;
    *(undefined4 **)(puVar4 + 4) = puVar4 + 2;
    *(undefined4 **)(puVar4 + 10) = puVar4 + 8;
    *(undefined1 *)((longlong)puVar4 + 0x449) = *(undefined1 *)(param_1 + 0x3d9);
    *(undefined1 *)((longlong)puVar4 + 0x44a) = *(undefined1 *)(param_1 + 0x3da);
    _local_68 = CONCAT44(0x14000,(uint)*(byte *)(*(longlong *)(param_1 + 0x450) + 2));
    _uStack_60 = CONCAT44(0x14000,(uint)*(byte *)(*(longlong *)(param_1 + 0x448) + 2));
    _local_58 = CONCAT44(0x14000,(uint)*(byte *)(*(longlong *)(param_1 + 0x50) + 2));
    puStack_80 = &local_68;
    uStack_70 = 0;
    _uStack_50 = CONCAT44(0x14000,(uint)*(byte *)(*(longlong *)(param_1 + 0x58) + 2));
    local_88 = 4;
    local_78 = 0x10001;
    puVar4[0x110] = 0xc30;
    iVar3 = UaspInternalDeviceIoControl
                      (*(longlong *)(param_1 + 0x10),0x491404,&local_88,0x20,puVar4 + 0xfc,0x58);
    if (-1 < iVar3) {
      *(undefined4 **)(_Dst + 0x10) = puVar4;
      goto LAB_140007bf8;
    }
    ExFreePoolWithTag(puVar4,0);
  }
  uVar6 = 4;
LAB_140007bf8:
  *(undefined1 *)(param_2 + 3) = uVar6;
  return;
}



===== CommandIUCompletion @ 140007c30 =====

void CommandIUCompletion(longlong *param_1,undefined8 param_2,int param_3,longlong param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 in_stack_ffffffffffffffb8;
  
  iVar1 = *(int *)(param_1[10] + 4);
  *(undefined4 *)(param_1 + 1) = 3;
  if ((param_3 == -0x3ffffee0) || (iVar1 == -0x3fff0000)) {
    uVar6 = 2;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar3 = param_1[5];
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_Di(uVar2,3,2,0xf,in_stack_ffffffffffffffb8,(char)lVar3 + -1,(char)param_1[4]);
    }
  }
  else {
    if ((iVar1 == 0) && (-1 < param_3)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        lVar3 = param_1[5];
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_Di(uVar2,3,3,0x13,in_stack_ffffffffffffffb8,(char)lVar3 + -1,
                           (char)param_1[4]);
      }
      goto LAB_140007eb2;
    }
    uVar6 = 4;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar3 = param_1[5];
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_DiD(uVar2,3,1,0x10,in_stack_ffffffffffffffb8,(char)lVar3 + -1,(char)param_1[4]
                          ,(char)iVar1);
    }
    if ((iVar1 + 0x3fffffefU < 2) || (iVar1 == -0x3ffffffc)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_i(uVar2,3,2,0x11,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                          (char)param_1[4]);
      }
      lVar3 = *param_1;
      pcVar4 = ResetPipeWorkItem;
      lVar5 = 0;
    }
    else {
      if (((iVar1 != -0x3fff9000) && (param_3 != -0x3fffff63)) && (param_3 != -0x3ffffff2))
      goto LAB_140007ea4;
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar2,3,2,0x12,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      lVar3 = *param_1;
      pcVar4 = BulkResetDeviceWorkItem;
      param_4 = 0;
      lVar5 = *(longlong *)(lVar3 + 0xa0);
    }
    UaspQueueWorkItem(lVar3,(longlong)pcVar4,lVar5,param_4);
  }
LAB_140007ea4:
  if (*(byte *)(param_1[4] + 3) < 2) {
    *(undefined1 *)(param_1[4] + 3) = uVar6;
  }
LAB_140007eb2:
  QueueUpdateCompletion(param_1);
  return;
}



===== DataCompletion @ 140007ee0 =====

void DataCompletion(longlong *param_1,undefined8 param_2,int param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 in_stack_ffffffffffffffb8;
  
  iVar1 = *(int *)(param_1[0xb] + 4);
  *(undefined4 *)((longlong)param_1 + 0xc) = 3;
  if ((param_3 == -0x3ffffee0) || (iVar1 == -0x3fff0000)) {
    uVar4 = 2;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar2 = param_1[5];
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_Di(uVar3,3,2,0x21,in_stack_ffffffffffffffb8,(char)lVar2 + -1,(char)param_1[4])
      ;
    }
  }
  else {
    if ((iVar1 == 0) && (-1 < param_3)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        lVar2 = param_1[5];
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_Di(uVar3,4,3,0x27,in_stack_ffffffffffffffb8,(char)lVar2 + -1,
                           (char)param_1[4]);
      }
      goto LAB_140008219;
    }
    uVar4 = 4;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar2 = param_1[5];
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_DiD(uVar3,3,2,0x22,in_stack_ffffffffffffffb8,(char)lVar2 + -1,(char)param_1[4]
                          ,(char)iVar1);
    }
    if ((iVar1 + 0x3fffffefU < 2) || (iVar1 == -0x3ffffffc)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_i(uVar3,3,2,0x23,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                          (char)param_1[4]);
      }
      UaspQueueWorkItem(*param_1,0x140007290,0,param_4);
      if ((int)param_1[1] == 2) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_(uVar3,4,3,0x24,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
        }
        IoCancelIrp(param_1[0xe]);
      }
      if ((int)param_1[2] == 2) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_(uVar3,4,3,0x25,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
        }
        CancelStatusIrp(param_1);
      }
    }
    else if (((iVar1 == -0x3fff9000) || (param_3 == -0x3fffff63)) || (param_3 == -0x3ffffff2)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar3,3,2,0x26,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      UaspQueueWorkItem(*param_1,0x140006ee0,*(longlong *)(*param_1 + 0xa0),0);
    }
  }
  if (*(byte *)(param_1[4] + 3) < 2) {
    *(undefined1 *)(param_1[4] + 3) = uVar4;
  }
LAB_140008219:
  QueueUpdateCompletion(param_1);
  return;
}



===== InitializeQueue @ 140008240 =====

int InitializeQueue(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ushort uVar7;
  longlong local_res10;
  
  uVar2 = *(ushort *)(param_2 + 0x500);
  iVar3 = 0;
  local_res10 = 0;
  KeInitializeSpinLock(param_2 + 0x4d8);
  KeInitializeSpinLock(param_2 + 0x470);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      uVar6 = (ulonglong)uVar7;
      plVar5 = (longlong *)(uVar6 * 0xe0 + *(longlong *)(param_2 + 0x498));
      *plVar5 = param_2;
      *(ushort *)(plVar5 + 5) = uVar7;
      *(undefined4 *)(*(longlong *)(param_2 + 0x4c8) + uVar6 * 4) = 1;
      lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar4 == 0) {
        return -0x3fffff66;
      }
      plVar5[0xe] = lVar4;
      iVar3 = USBD_UrbAllocate(*(longlong *)(param_2 + 0x4f8),&local_res10);
      if (iVar3 < 0) {
        return iVar3;
      }
      plVar5[10] = local_res10;
      lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar4 == 0) {
        return -0x3fffff66;
      }
      plVar5[0xf] = lVar4;
      iVar3 = USBD_UrbAllocate(*(longlong *)(param_2 + 0x4f8),&local_res10);
      if (iVar3 < 0) {
        return iVar3;
      }
      plVar5[0xb] = local_res10;
      lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar4 == 0) {
        return -0x3fffff66;
      }
      plVar5[0x10] = lVar4;
      iVar3 = USBD_UrbAllocate(*(longlong *)(param_2 + 0x4f8),&local_res10);
      if (iVar3 < 0) {
        return iVar3;
      }
      plVar5[0xc] = local_res10;
      lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar4 == 0) {
        return -0x3fffff66;
      }
      plVar5[0x11] = lVar4;
      iVar3 = USBD_UrbAllocate(*(longlong *)(param_2 + 0x4f8),&local_res10);
      if (iVar3 < 0) {
        return iVar3;
      }
      plVar5[0xd] = local_res10;
      plVar1 = (longlong *)(*(longlong *)(param_2 + 0x488) + uVar6 * 0x28);
      plVar5[0x1a] = (longlong)plVar1;
      plVar5[0x1b] = *(longlong *)(param_2 + 0x490) + uVar6 * 0x28;
      *plVar1 = *(longlong *)(param_2 + 0x4b0) + uVar6 * 0x400;
      *(ulonglong *)plVar5[0x1b] = *(longlong *)(param_2 + 0x4a8) + uVar6 * 0x400;
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar2);
  }
  *(undefined2 *)(param_2 + 0x4d0) = 1;
  *(undefined4 *)(param_2 + 0x4e0) = 3;
  return iVar3;
}



===== QueueCancel @ 14000847c =====

undefined8 QueueCancel(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort uVar4;
  longlong lVar5;
  bool bVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x4d8,&local_48);
  bVar6 = *(int *)(param_1 + 0x4e0) != 1;
  if (bVar6) {
    *(undefined4 *)(param_1 + 0x4e0) = 1;
  }
  KeReleaseInStackQueuedSpinLock(&local_48);
  if (bVar6) {
    uVar4 = 0;
    if (*(short *)(param_1 + 0x500) != 0) {
      do {
        lVar5 = (ulonglong)uVar4 * 0xe0 + *(longlong *)(param_1 + 0x498);
        if (*(int *)(*(longlong *)(param_1 + 0x4c8) + (ulonglong)uVar4 * 4) == 2) {
          if ((gTracingEnabled != '\0') &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            WPP_RECORDER_SF_PDDd(uVar3);
          }
          lVar2 = *(longlong *)(lVar5 + 0x70);
          iVar1 = *(int *)(lVar5 + 8);
          if ((lVar2 == 0) || (iVar1 != 2)) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_D(uVar3,4,5,0x38,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                                (char)iVar1);
            }
          }
          else {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_(uVar3,4,5,0x37,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
            }
            IoCancelIrp(lVar2);
          }
          lVar2 = *(longlong *)(lVar5 + 0x78);
          iVar1 = *(int *)(lVar5 + 0xc);
          if ((lVar2 == 0) || (iVar1 != 2)) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_D(uVar3,4,5,0x3a,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                                (char)iVar1);
            }
          }
          else {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_(uVar3,4,5,0x39,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
            }
            IoCancelIrp(lVar2);
          }
          lVar2 = *(longlong *)(lVar5 + 0x80);
          iVar1 = *(int *)(lVar5 + 0x10);
          if ((lVar2 == 0) || (iVar1 != 2)) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_D(uVar3,4,5,0x3c,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                                (char)iVar1);
            }
          }
          else {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_(uVar3,4,5,0x3b,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
            }
            IoCancelIrp(lVar2);
          }
          lVar2 = *(longlong *)(lVar5 + 0x88);
          iVar1 = *(int *)(lVar5 + 0x14);
          if ((lVar2 == 0) || (iVar1 != 2)) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_D(uVar3,4,5,0x3e,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                                (char)iVar1);
            }
          }
          else {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_(uVar3,4,5,0x3d,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
            }
            IoCancelIrp(lVar2);
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(ushort *)(param_1 + 0x500));
    }
    *(undefined4 *)(param_1 + 0x4e0) = 3;
  }
  else if ((gTracingEnabled != '\0') &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_(uVar3,2,3,0x35,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
  }
  return 0;
}



===== QueueFindNextFree @ 1400088e8 =====

undefined8 QueueFindNextFree(longlong param_1,ushort *param_2,longlong param_3,char param_4)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar3 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x4d8,&local_28);
  if (*(int *)(param_1 + 0x4e0) == 3) {
    if (param_4 == '\0') {
      uVar1 = *(ushort *)(param_1 + 0x4d0);
      if (uVar1 < *(ushort *)(param_1 + 0x500)) {
        lVar2 = *(longlong *)(param_1 + 0x4c8);
        *param_2 = uVar1;
        *(undefined4 *)(lVar2 + (ulonglong)uVar1 * 4) = 2;
        uVar4 = 1;
        uVar1 = *(ushort *)(param_1 + 0x500);
        *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + 1;
        *(ushort *)(param_1 + 0x4d0) = uVar1;
        if (1 < uVar1) {
          do {
            if (*(int *)(*(longlong *)(param_1 + 0x4c8) + (ulonglong)uVar4 * 4) == 1) {
              *(ushort *)(param_1 + 0x4d0) = uVar4;
              break;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar1);
        }
        goto LAB_140008adf;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_D(uVar3,3,2,0xc,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,(char)uVar1
                         );
      }
    }
    else {
      if (**(int **)(param_1 + 0x4c8) == 1) {
        **(int **)(param_1 + 0x4c8) = 2;
        *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + 1;
        *param_2 = 0;
        goto LAB_140008adf;
      }
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar3,3,2,0xb,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
    }
    *(undefined2 *)(param_3 + 3) = 0x2804;
  }
  else {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar3,3,2,10,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
    }
    *(undefined1 *)(param_3 + 3) = 5;
  }
  uVar3 = 0x80000011;
LAB_140008adf:
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (*(uint *)(param_1 + 0x570) < *(uint *)(param_1 + 0x56c)) {
    *(uint *)(param_1 + 0x570) = *(uint *)(param_1 + 0x56c);
  }
  return uVar3;
}



===== QueueReleaseEntry @ 140008b28 =====

void QueueReleaseEntry(longlong *param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar2 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x4d8,&local_28);
  *(undefined4 *)(*(longlong *)(lVar2 + 0x4c8) + (ulonglong)*(ushort *)(param_1 + 5) * 4) = 1;
  *(int *)(lVar2 + 0x56c) = *(int *)(lVar2 + 0x56c) + -1;
  uVar1 = *(ushort *)(param_1 + 5);
  if ((uVar1 < *(ushort *)(lVar2 + 0x4d0)) && ((*(longlong *)(lVar2 + 0x68) != 0 || (uVar1 != 0))))
  {
    *(ushort *)(lVar2 + 0x4d0) = uVar1;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== QueueTaskWorkItem @ 140008bc0 =====

void QueueTaskWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 uVar7;
  longlong *plVar8;
  ushort uVar9;
  undefined1 *puVar10;
  ushort local_res10 [4];
  undefined4 local_res18;
  longlong local_res20;
  
  lVar1 = *param_2;
  lVar2 = param_2[1];
  local_res10[0] = 0;
  local_res18 = (undefined4)param_2[2];
  QueueCancel(lVar1);
  uVar5 = QueueFindNextFree(lVar1,local_res10,lVar2,'\0');
  iVar4 = (int)uVar5;
  if (iVar4 < 0) {
    if (iVar4 != -0x7fffffef) goto LAB_140008dd5;
    uVar5 = QueueFindNextFree(lVar1,local_res10,lVar2,'\x01');
    iVar4 = (int)uVar5;
    if (iVar4 < 0) goto LAB_140008dd5;
  }
  uVar7 = 4;
  local_res20 = (ulonglong)local_res10[0] * 0xe0;
  plVar8 = (longlong *)(*(longlong *)(lVar1 + 0x498) + local_res20);
  uVar9 = (ushort)(local_res10[0] + 1) >> 8 | (local_res10[0] + 1) * 0x100;
  *(undefined4 *)(plVar8 + 3) = 2;
  plVar8[4] = lVar2;
  puVar10 = (undefined1 *)((ulonglong)local_res10[0] * 0x10 + *(longlong *)(lVar1 + 0x4b8));
  puVar3 = *(undefined1 **)plVar8[0x1a];
  *puVar3 = 4;
  *(ushort *)(puVar3 + 2) = uVar9;
  *(undefined4 *)(plVar8 + 2) = 2;
  param_2[1] = 0;
  iVar4 = IssueBulkRequest(lVar1,(longlong)plVar8,3,local_res10[0],puVar3,0,0x400,1,
                           -(ulonglong)(*(char *)(lVar1 + 0x3da) != '\0') & 0x140009040);
  if (iVar4 < 0) {
    *(undefined1 *)(plVar8[4] + 3) = 4;
    StorPortNotification(0,lVar1,plVar8[4]);
    QueueReleaseEntry(plVar8);
  }
  else {
    *puVar10 = 5;
    if (*(longlong *)(lVar1 + 0x468) == 0) {
      lVar6 = (ulonglong)*(byte *)(lVar2 + 7) << 0x38;
    }
    else {
      lVar6 = *(longlong *)((ulonglong)*(byte *)(lVar2 + 7) * 0x20 + *(longlong *)(lVar1 + 0x468));
    }
    *(longlong *)(puVar10 + 8) = lVar6;
    puVar10[4] = (char)local_res18;
    *(undefined2 *)(puVar10 + 6) = 0;
    *(ushort *)(puVar10 + 2) = uVar9;
    *(undefined4 *)(plVar8 + 1) = 2;
    iVar4 = IssueBulkRequest(lVar1,(longlong)plVar8,1,local_res10[0],puVar10,0,0x10,0,
                             TaskIUCompletion);
    if (iVar4 < 0) {
      if (iVar4 == -0x3ffffff2) {
        uVar7 = 0xe;
      }
      else if (iVar4 == -0x3fffffc4) {
        uVar7 = 0x12;
      }
      *(undefined1 *)(lVar2 + 3) = uVar7;
      CancelStatusIrp((longlong *)(local_res20 + *(longlong *)(lVar1 + 0x498)));
    }
  }
LAB_140008dd5:
  UaspCompleteWorkItem(param_2,iVar4);
  return;
}



===== QueueUpdateCompletion @ 140008e00 =====

void QueueUpdateCompletion(longlong *param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar3 = param_1[4];
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PDddd(uVar5);
  }
  LOCK();
  plVar1 = param_1 + 3;
  lVar4 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar4 == 1) {
    *(undefined4 *)(param_1 + 2) = 0;
    *(undefined4 *)(param_1 + 1) = 0;
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
    *(undefined4 *)((longlong)param_1 + 0x14) = 0;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar2 = *(undefined1 *)(lVar3 + 3);
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_PD(uVar5,4,5,0xe,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,(char)lVar3,
                         uVar2);
    }
    if (*(char *)(lVar3 + 3) == '\x01') {
      UaspPostProcessSrb(*param_1,param_1[4]);
    }
    if ((char)param_1[0x19] == '\0') {
      QueueReleaseEntry(param_1);
      StorPortNotification(0,*param_1,lVar3);
    }
    else {
      KeSetEvent(param_1[0x18],0,0);
      QueueReleaseEntry(param_1);
    }
  }
  return;
}



===== QueueUpdateTaskCompletion @ 140008f5c =====

void QueueUpdateTaskCompletion(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  
  lVar2 = param_1[4];
  LOCK();
  plVar1 = param_1 + 3;
  lVar3 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar3 != 1) {
    return;
  }
  *(undefined8 *)((longlong)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  if (*(char *)(lVar2 + 2) == '\x13') {
    if ((gTracingEnabled == '\0') ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140009004;
    uVar5 = 0x28;
  }
  else {
    if ((gTracingEnabled == '\0') ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140009004;
    uVar5 = 0x29;
  }
  uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  WPP_RECORDER_SF_P(uVar4,param_2,5,uVar5,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                    (char)lVar2);
LAB_140009004:
  QueueReleaseEntry(param_1);
  StorPortNotification(0,*param_1,lVar2);
  return;
}



===== ResponseIUCompletion @ 140009040 =====

void ResponseIUCompletion(longlong *param_1,undefined *param_2,int param_3,longlong param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  undefined2 uVar6;
  longlong lVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffffc8;
  
  iVar2 = *(int *)(param_1[0xc] + 4);
  *(undefined4 *)(param_1 + 2) = 3;
  *(undefined1 *)((longlong)param_1 + 0xca) = 0;
  if ((param_3 == -0x3ffffee0) || (iVar2 == -0x3fff0000)) {
    bVar8 = gTracingEnabled == '\0';
    *(undefined1 *)(param_1[4] + 3) = 2;
    if ((bVar8) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14000931a;
    uVar6 = 0x2f;
  }
  else {
    if ((iVar2 != 0) || (param_3 < 0)) {
      bVar8 = gTracingEnabled != '\0';
      *(undefined1 *)(param_1[4] + 3) = 4;
      if ((bVar8) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        lVar4 = param_1[5];
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        param_2 = (undefined *)CONCAT71((int7)((ulonglong)param_2 >> 8),2);
        WPP_RECORDER_SF_DiD(uVar3,2,1,0x30,in_stack_ffffffffffffffc8,(char)lVar4 + -1,
                            (char)param_1[4],(char)iVar2);
      }
      if ((iVar2 + 0x3fffffefU < 2) || (iVar2 == -0x3ffffffc)) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_i(uVar3,3,2,0x31,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                            (char)param_1[4]);
        }
        lVar4 = *param_1;
        pcVar5 = ResetPipeWorkItem;
        lVar7 = 0;
      }
      else {
        if (((iVar2 != -0x3fff9000) && (param_3 != -0x3fffff63)) && (param_3 != -0x3ffffff2))
        goto LAB_14000931a;
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_(uVar3,3,2,0x32,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
        }
        lVar4 = *param_1;
        pcVar5 = BulkResetDeviceWorkItem;
        param_4 = 0;
        lVar7 = *(longlong *)(lVar4 + 0xa0);
      }
      UaspQueueWorkItem(lVar4,(longlong)pcVar5,lVar7,param_4);
      param_2 = pcVar5;
      goto LAB_14000931a;
    }
    if ((param_2[7] & 0xf7) != 0) {
      bVar8 = gTracingEnabled != '\0';
      *(undefined1 *)(param_1[4] + 3) = 4;
      if ((bVar8) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        lVar4 = param_1[5];
        uVar1 = param_2[7];
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        param_2 = (undefined *)CONCAT71((int7)((ulonglong)param_2 >> 8),4);
        WPP_RECORDER_SF_DiD(uVar3,4,3,0x34,in_stack_ffffffffffffffc8,(char)lVar4 + -1,
                            (char)param_1[4],uVar1);
      }
      goto LAB_14000931a;
    }
    bVar8 = gTracingEnabled == '\0';
    *(undefined1 *)(param_1[4] + 3) = 1;
    if ((bVar8) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14000931a;
    uVar6 = 0x33;
  }
  lVar4 = param_1[5];
  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  param_2 = (undefined *)CONCAT71((int7)((ulonglong)param_2 >> 8),4);
  WPP_RECORDER_SF_Di(uVar3,4,3,uVar6,in_stack_ffffffffffffffc8,(char)lVar4 + -1,(char)param_1[4]);
LAB_14000931a:
  QueueUpdateTaskCompletion(param_1,param_2);
  return;
}



===== SenseIUCompletion @ 140009350 =====

void SenseIUCompletion(longlong *param_1,char *param_2,int param_3,longlong param_4)

{
  uint uVar1;
  longlong *plVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  code *pcVar9;
  char cVar10;
  longlong lVar11;
  uint uVar12;
  undefined1 uVar13;
  undefined *in_stack_ffffffffffffffa8;
  
  iVar4 = *(int *)(param_1[0xc] + 4);
  *(undefined4 *)(param_1 + 2) = 3;
  *(undefined1 *)((longlong)param_1 + 0xca) = 0;
  if ((param_3 == -0x3ffffee0) || (iVar4 == -0x3fff0000)) {
    uVar13 = 2;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar8 = param_1[5];
      uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_Di(uVar7,3,2,0x14,in_stack_ffffffffffffffa8,(char)lVar8 + -1,(char)param_1[4])
      ;
      uVar13 = 2;
    }
  }
  else if ((iVar4 == 0) && (-1 < param_3)) {
    if (*param_2 == '\x04') {
      bVar3 = param_2[7];
      if ((bVar3 & 0xf7) == 0) {
        uVar13 = 1;
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          in_stack_ffffffffffffffa8 = &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids;
          WPP_RECORDER_SF_PD(uVar7,3,2,0x18,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                             (char)param_1[4],bVar3);
          uVar13 = 1;
        }
      }
      else {
        if (((bVar3 == 2) || (bVar3 == 4)) || (bVar3 == 5)) {
          uVar13 = 6;
        }
        else if (bVar3 == 9) {
          uVar13 = 0x20;
        }
        else {
          uVar13 = 4;
        }
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_iDD(uVar7);
        }
      }
    }
    else {
      cVar10 = param_2[4];
      if ((cVar10 == '\0') && (param_2[6] == '\0')) {
        uVar13 = 1;
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          lVar8 = param_1[5];
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_Di(uVar7,4,3,0x1a,in_stack_ffffffffffffffa8,(char)lVar8 + -1,
                             (char)param_1[4]);
        }
      }
      else {
        bVar5 = (byte)((ushort)*(undefined2 *)(param_2 + 6) >> 8);
        bVar3 = (byte)((ushort)*(undefined2 *)(param_2 + 0xe) >> 8);
        iVar4 = *(int *)(param_1[0xc] + 0x24);
        uVar1 = iVar4 - 8;
        uVar12 = (uint)bVar5;
        if (uVar12 == uVar1) {
          lVar8 = 8;
        }
        else {
          if ((uint)bVar3 != iVar4 - 0x10U) {
            uVar13 = 4;
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              in_stack_ffffffffffffffa8 = &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids;
              WPP_RECORDER_SF_i(uVar7,2,1,0x1c,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                                (char)param_1[4]);
              uVar13 = 4;
            }
            goto LAB_140009884;
          }
          lVar8 = 0x10;
          cVar10 = param_2[6];
          bVar5 = bVar3;
        }
        if (*(int *)(*param_1 + 0x564) == 0) {
          uVar6 = 2;
          if (uVar12 != uVar1) {
            uVar6 = 4;
          }
          *(undefined4 *)(*param_1 + 0x564) = uVar6;
        }
        plVar2 = param_1 + 4;
        *(char *)(*plVar2 + 4) = cVar10;
        if (cVar10 == '\x02') {
          uVar13 = 4;
          if ((2 < bVar5) && (param_2 + lVar8 != (char *)0x0)) {
            uVar13 = 0x84;
            bVar3 = *(byte *)(*plVar2 + 0xb);
            if (bVar3 < bVar5) {
              bVar5 = bVar3;
            }
            memmove(*(void **)(*plVar2 + 0x20),param_2 + lVar8,(ulonglong)bVar5);
            *(byte *)(*plVar2 + 0xb) = bVar5;
          }
        }
        else if ((cVar10 - 8U & 0xdf) == 0) {
          uVar13 = 5;
        }
        else {
          uVar13 = 4;
        }
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_diDDD(uVar7);
        }
      }
    }
  }
  else {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar8 = param_1[5];
      uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_DiD(uVar7,3,2,0x15,in_stack_ffffffffffffffa8,(char)lVar8 + -1,(char)param_1[4]
                          ,(char)iVar4);
    }
    uVar13 = 4;
    if ((iVar4 + 0x3fffffefU < 2) || (iVar4 == -0x3ffffffc)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        in_stack_ffffffffffffffa8 = &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids;
        WPP_RECORDER_SF_i(uVar7,3,2,0x16,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                          (char)param_1[4]);
      }
      lVar8 = *param_1;
      pcVar9 = ResetPipeWorkItem;
      lVar11 = 0;
    }
    else {
      if (((iVar4 != -0x3fff9000) && (param_3 != -0x3fffff63)) && (param_3 != -0x3ffffff2))
      goto LAB_140009884;
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        in_stack_ffffffffffffffa8 = &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids;
        WPP_RECORDER_SF_(uVar7,3,2,0x17,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      lVar8 = *param_1;
      pcVar9 = BulkResetDeviceWorkItem;
      param_4 = 0;
      lVar11 = *(longlong *)(lVar8 + 0xa0);
    }
    UaspQueueWorkItem(lVar8,(longlong)pcVar9,lVar11,param_4);
  }
LAB_140009884:
  if (*(char *)(param_1[4] + 3) != '\x04') {
    *(undefined1 *)(param_1[4] + 3) = uVar13;
  }
  lVar8 = param_1[4];
  if (*(char *)(lVar8 + 3) != '\x01') {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar11 = param_1[5];
      uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_Di(uVar7,4,3,0x1d,in_stack_ffffffffffffffa8,(char)lVar11 + -1,(char)lVar8);
    }
    if (*(int *)((longlong)param_1 + 0xc) == 2) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar7,4,3,0x1e,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      IoCancelIrp(param_1[0xf]);
    }
    if ((int)param_1[1] == 2) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar7,4,3,0x1f,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      IoCancelIrp(param_1[0xe]);
    }
    if (*(int *)((longlong)param_1 + 0x14) == 2) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar7,4,3,0x20,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      CancelReadyIrp(param_1);
    }
  }
  QueueUpdateCompletion(param_1);
  return;
}



===== TaskIUCompletion @ 140009a60 =====

void TaskIUCompletion(longlong *param_1,undefined *param_2,int param_3,longlong param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 in_stack_ffffffffffffffa8;
  
  iVar1 = *(int *)(param_1[10] + 4);
  *(undefined4 *)(param_1 + 1) = 3;
  if ((param_3 == -0x3ffffee0) || (iVar1 == -0x3fff0000)) {
    uVar6 = 2;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar3 = param_1[5];
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      param_2 = (undefined *)CONCAT71((int7)((ulonglong)param_2 >> 8),4);
      WPP_RECORDER_SF_Di(uVar2,4,3,0x2a,in_stack_ffffffffffffffa8,(char)lVar3 + -1,(char)param_1[4])
      ;
    }
  }
  else {
    if ((iVar1 == 0) && (-1 < param_3)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_Did(uVar2);
      }
      goto LAB_140009cd8;
    }
    uVar6 = 4;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_DidD(uVar2);
    }
    if ((iVar1 + 0x3fffffefU < 2) || (iVar1 == -0x3ffffffc)) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_i(uVar2,3,2,0x2c,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,
                          (char)param_1[4]);
      }
      lVar3 = *param_1;
      pcVar4 = ResetPipeWorkItem;
      lVar5 = 0;
    }
    else {
      if (((iVar1 != -0x3fff9000) && (param_3 != -0x3fffff63)) && (param_3 != -0x3ffffff2))
      goto LAB_140009cca;
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_(uVar2,3,2,0x2d,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids);
      }
      lVar3 = *param_1;
      pcVar4 = BulkResetDeviceWorkItem;
      param_4 = 0;
      lVar5 = *(longlong *)(lVar3 + 0xa0);
    }
    UaspQueueWorkItem(lVar3,(longlong)pcVar4,lVar5,param_4);
    param_2 = pcVar4;
  }
LAB_140009cca:
  if (*(byte *)(param_1[4] + 3) < 2) {
    *(undefined1 *)(param_1[4] + 3) = uVar6;
  }
LAB_140009cd8:
  QueueUpdateTaskCompletion(param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_Di @ 140009d04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Di(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,param_4,&param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,param_4,
                  &param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_DiD @ 140009e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DiD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,param_4,
                  &param_6,4,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_Did @ 140009f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Did(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x2e,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x2e,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DidD @ 14000a074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DidD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x2b,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x2b,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_PDDd @ 14000a188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x36,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x36,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_PDddd @ 14000a29c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PDddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0xd,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0xd,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_diDDD @ 14000a3d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_diDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x1b,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x1b,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_i @ 14000a50c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_i(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_iDD @ 14000a608 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x19,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_d6e12b5d5d0c3ab99520f795e25f2e40_Traceguids,0x19,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== CancelReadyIrp @ 14000a6fc =====

void CancelReadyIrp(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar3 = 0;
  KeAcquireInStackQueuedSpinLock(*param_1 + 0x470,&local_28);
  if (*(int *)((longlong)param_1 + 0x14) == 2) {
    lVar3 = param_1[0x11];
    *(undefined1 *)((longlong)param_1 + 0xcb) = 1;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (lVar3 == param_1[0x11]) {
    IoCancelIrp(lVar3);
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      lVar1 = param_1[5];
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_PD(uVar2,4,3,0x28,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,(char)lVar3
                         ,(char)lVar1 + -1);
    }
  }
  return;
}



===== CancelStatusIrp @ 14000a7ec =====

void CancelStatusIrp(longlong *param_1)

{
  longlong lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(char *)(*param_1 + 0x3d9) == '\0') {
    lVar1 = param_1[0x10];
  }
  else {
    KeAcquireInStackQueuedSpinLock(*param_1 + 0x470,&local_28);
    if ((int)param_1[2] == 2) {
      lVar1 = param_1[0x10];
      *(undefined1 *)((longlong)param_1 + 0xca) = 1;
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  if (lVar1 != 0) {
    IoCancelIrp(lVar1);
  }
  return;
}



===== IssueCommandHS @ 14000a884 =====

ulonglong IssueCommandHS(longlong param_1,longlong param_2,undefined4 *param_3,longlong param_4,
                        undefined8 param_5,char param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 uVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  ushort local_res8 [4];
  
  local_res8[0] = 0;
  lVar9 = *(longlong *)(param_1 + 0x68);
  uVar7 = QueueFindNextFree(param_1,local_res8,param_2,'\0');
  if ((int)uVar7 < 0) {
    return uVar7 & 0xffffffff;
  }
  uVar5 = local_res8[0] + 1;
  plVar12 = (longlong *)((ulonglong)local_res8[0] * 0xe0 + *(longlong *)(param_1 + 0x498));
  *(undefined4 *)(plVar12 + 1) = 1;
  *(undefined4 *)((longlong)plVar12 + 0xc) = 1;
  *(undefined4 *)((longlong)plVar12 + 0x14) = 1;
  *(undefined4 *)(plVar12 + 2) = 1;
  plVar12[4] = param_2;
  plVar12[0x14] = param_4;
  *(char *)((longlong)plVar12 + 0xc9) = param_6;
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *(undefined4 *)(plVar12 + 0x15) = *param_3;
    *(undefined4 *)((longlong)plVar12 + 0xac) = uVar1;
    *(undefined4 *)(plVar12 + 0x16) = uVar2;
    *(undefined4 *)((longlong)plVar12 + 0xb4) = uVar3;
  }
  *(bool *)(plVar12 + 0x17) = param_3 != (undefined4 *)0x0;
  plVar12[0x18] = 0;
  uVar11 = 4;
  *(undefined1 *)(plVar12 + 0x19) = 0;
  puVar13 = (undefined1 *)((ulonglong)local_res8[0] * 0x20 + *(longlong *)(param_1 + 0x4a0));
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    lVar4 = plVar12[5];
    uVar8 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PD(uVar8,4,3,0x2a,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,(char)param_2
                       ,(char)lVar4 + -1);
  }
  if ((*(uint *)(param_2 + 0xc) & 0xc0) == 0) {
    *(undefined4 *)(plVar12 + 3) = 2;
  }
  else {
    uVar8 = *(undefined8 *)plVar12[0x1b];
    *(undefined4 *)(plVar12 + 3) = 3;
    *(undefined4 *)((longlong)plVar12 + 0x14) = 2;
    if (param_6 == '\0') {
      uVar10 = 0;
    }
    else {
      uVar10 = *(undefined8 *)(param_1 + 0x5b0);
    }
    uVar6 = IssueBulkRequest(param_1,(longlong)plVar12,4,local_res8[0],uVar8,uVar10,0x400,
                             (-(uint)(param_6 != '\0') & 0x10) + 1,
                             -(ulonglong)(lVar9 != 0) & 0x14000b0e0);
    if ((int)uVar6 < 0) {
      if (uVar6 == 0xc000000e) {
        uVar11 = 0xe;
      }
      else if (uVar6 == 0xc000003c) {
        uVar11 = 0x12;
      }
      *(undefined1 *)(param_2 + 3) = uVar11;
      goto LAB_14000aa83;
    }
  }
  uVar8 = *(undefined8 *)plVar12[0x1a];
  *(undefined4 *)(plVar12 + 2) = 2;
  if (param_6 == '\0') {
    uVar10 = 0;
  }
  else {
    uVar10 = *(undefined8 *)(param_1 + 0x5a8);
  }
  uVar6 = IssueBulkRequest(param_1,(longlong)plVar12,3,local_res8[0],uVar8,uVar10,0x400,
                           (-(uint)(param_6 != '\0') & 0x10) + 1,
                           -(ulonglong)(lVar9 != 0) & 0x140009350);
  if (-1 < (int)uVar6) {
    *puVar13 = 1;
    uVar8 = *(undefined8 *)(param_2 + 0x50);
    *(undefined8 *)(puVar13 + 0x10) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(puVar13 + 0x18) = uVar8;
    if (*(longlong *)(param_1 + 0x468) == 0) {
      lVar9 = (ulonglong)*(byte *)(param_2 + 7) << 0x38;
    }
    else {
      lVar9 = *(longlong *)
               ((ulonglong)*(byte *)(param_2 + 7) * 0x20 + *(longlong *)(param_1 + 0x468));
    }
    puVar13[6] = puVar13[6] & 3;
    puVar13[4] = puVar13[4] & 0x80;
    *(longlong *)(puVar13 + 8) = lVar9;
    *(ushort *)(puVar13 + 2) = uVar5 >> 8 | uVar5 * 0x100;
    *(undefined4 *)(plVar12 + 1) = 2;
    if (param_6 == '\0') {
      uVar8 = 0;
    }
    else {
      uVar8 = *(undefined8 *)(param_1 + 0x5a0);
    }
    uVar6 = IssueBulkRequest(param_1,(longlong)plVar12,1,local_res8[0],puVar13,uVar8,0x20,
                             -(uint)(param_6 != '\0') & 0x10,CommandIUCompletion);
    if (-1 < (int)uVar6) {
      return (ulonglong)uVar6;
    }
    if (uVar6 == 0xc000000e) {
      uVar11 = 0xe;
    }
    else if (uVar6 == 0xc000003c) {
      uVar11 = 0x12;
    }
    *(undefined1 *)(param_2 + 3) = uVar11;
    *(undefined4 *)(plVar12 + 1) = 3;
    *(undefined4 *)((longlong)plVar12 + 0xc) = 3;
    if ((*(uint *)(param_2 + 0xc) & 0xc0) != 0) {
      CancelReadyIrp(plVar12);
    }
    CancelStatusIrp(plVar12);
    return 0;
  }
  if (uVar6 == 0xc000000e) {
    uVar11 = 0xe;
  }
  else if (uVar6 == 0xc000003c) {
    uVar11 = 0x12;
  }
  *(undefined1 *)(plVar12[4] + 3) = uVar11;
  *(undefined4 *)(plVar12 + 2) = 3;
  if ((*(uint *)(param_2 + 0xc) & 0xc0) != 0) {
    *(undefined4 *)(plVar12 + 1) = 3;
    *(undefined4 *)((longlong)plVar12 + 0xc) = 3;
    CancelReadyIrp(plVar12);
    return 0;
  }
LAB_14000aa83:
  QueueReleaseEntry(plVar12);
  return (ulonglong)uVar6;
}



===== IssueDataTransferRequest @ 14000ac68 =====

undefined4 IssueDataTransferRequest(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined8 local_res8;
  
  lVar2 = param_1[4];
  lVar3 = *param_1;
  local_res8 = 0;
  uVar4 = *(uint *)(lVar2 + 0xc) & 0xc0;
  if (uVar4 == 0) {
LAB_14000ae36:
    uVar8 = 0xc000000d;
LAB_14000ae3b:
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_PD(uVar6,2,1,0xc,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                         (char)param_1[4],(char)uVar8);
    }
  }
  else {
    if (uVar4 == 0x40) {
      uVar4 = 3;
    }
    else {
      if (uVar4 != 0x80) goto LAB_14000ae36;
      uVar4 = 0;
    }
    cVar1 = *(char *)((longlong)param_1 + 0xc9);
    *(undefined4 *)((longlong)param_1 + 0xc) = 2;
    if (*(longlong *)(lVar3 + 8) == 0) {
      local_res8 = *(undefined8 *)(lVar2 + 0x18);
    }
    else if (param_1[0x14] == 0) {
      lVar7 = lVar3;
      lVar9 = lVar2;
      iVar5 = StorPortExtendedFunction(5,lVar3,lVar2,&local_res8);
      if (iVar5 != 0) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_iiD(uVar6,lVar7,lVar9,10,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                              (char)lVar2,(char)*(undefined8 *)(lVar2 + 0x18),(char)iVar5);
        }
        *(undefined1 *)(lVar2 + 3) = 4;
        uVar8 = 0xc000009a;
        goto LAB_14000ae3b;
      }
    }
    *(undefined4 *)((longlong)param_1 + 0xc) = 2;
    iVar5 = IssueBulkRequest(lVar3,(longlong)param_1,2,*(ushort *)(param_1 + 5),local_res8,
                             param_1[0x14],*(undefined4 *)(lVar2 + 0x10),
                             uVar4 | -(uint)(cVar1 != '\0') & 0x10,DataCompletion);
    if (((iVar5 < 0) && (gTracingEnabled != '\0')) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_PD(uVar6,2,1,0xb,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                         (char)param_1[4],(char)iVar5);
    }
    uVar8 = 0;
  }
  return uVar8;
}



===== QueueCancelHSWorkItem @ 14000aeb0 =====

void QueueCancelHSWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  lVar1 = param_2[1];
  plVar4 = param_2;
  uVar2 = QueueCancel(*param_2);
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_P(uVar3,plVar4,3,0x2c,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                      (char)lVar1);
  }
  UaspCompleteWorkItem(param_2,(int)uVar2);
  return;
}



===== QueueCommandHS @ 14000af50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong QueueCommandHS(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auStackY_88 [32];
  undefined *in_stack_ffffffffffffff98;
  longlong local_48 [4];
  
  local_48[3] = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  lVar6 = param_3;
  iVar1 = StorPortExtendedFunction(0x28,param_1,param_3,local_48 + 1);
  plVar5 = local_48 + 1;
  if (iVar1 != 0) {
    plVar5 = (longlong *)0x0;
  }
  if (((*(uint *)(param_3 + 0xc) & 0xc0) != 0) &&
     ((iVar1 = -0x3effffff, *(longlong *)(param_3 + 0x30) == 0 ||
      (param_1 = param_2, lVar6 = param_3,
      iVar1 = StorPortExtendedFunction(6,param_2,param_3,local_48), iVar1 != 0)))) {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      in_stack_ffffffffffffff98 = &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids;
      WPP_RECORDER_SF_iiD(uVar2,param_1,lVar6,0x29,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                          (char)param_3,(char)*(undefined8 *)(param_3 + 0x18),(char)iVar1);
    }
    local_48[0] = 0;
  }
  uVar3 = IssueCommandHS(param_2,param_3,(undefined4 *)plVar5,local_48[0],in_stack_ffffffffffffff98,
                         '\0');
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == -0x3fffff66) {
    if ((0x1000 < *(uint *)(param_3 + 0x10)) || (*(char *)(param_2 + 0x3dc) == '\0'))
    goto LAB_14000b096;
    uVar4 = IssueCommandHS(param_2,param_3,(undefined4 *)plVar5,local_48[0],
                           in_stack_ffffffffffffff98,'\x01');
    uVar4 = uVar4 & 0xffffffff;
  }
  if (-1 < (int)uVar4) {
    return uVar4;
  }
LAB_14000b096:
  StorPortNotification(0,param_2,param_3);
  return uVar4;
}



===== ReadyIUCompletion @ 14000b0e0 =====

void ReadyIUCompletion(longlong *param_1,char *param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  code *pcVar7;
  undefined1 uVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  undefined8 in_stack_ffffffffffffffa8;
  
  iVar3 = (int)param_3;
  iVar2 = *(int *)(param_1[0xd] + 4);
  *(undefined4 *)((longlong)param_1 + 0x14) = 3;
  *(undefined1 *)((longlong)param_1 + 0xcb) = 0;
  cVar1 = *param_2;
  if (cVar1 == '\x06') {
    pwVar10 = L"ReadReadyIU";
LAB_14000b14a:
    if ((iVar3 == -0x3ffffee0) || (iVar2 == -0x3fff0000)) {
      if (*(int *)(param_1[0xd] + 0x24) != 0) goto LAB_14000b2c6;
      uVar8 = 2;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_SDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,param_3,0xe,
                            in_stack_ffffffffffffffa8,pwVar10,(char)param_1[5] + -1,(char)param_1[4]
                           );
      }
      goto LAB_14000b1c7;
    }
    if ((iVar2 == 0) && (-1 < iVar3)) {
LAB_14000b2c6:
      uVar8 = 4;
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        lVar6 = param_1[5];
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_SDi(uVar5,4,param_3,0x10,in_stack_ffffffffffffffa8,pwVar10,(char)lVar6 + -1,
                            (char)param_1[4]);
      }
      iVar4 = IssueDataTransferRequest(param_1);
      if (-1 < iVar4) {
        return;
      }
      goto LAB_14000b1c7;
    }
    uVar8 = 4;
    if (gTracingEnabled != '\0') {
      uVar8 = 4;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_SDiD(uVar5);
      }
      goto LAB_14000b1c7;
    }
  }
  else {
    if (cVar1 == '\a') {
      pwVar10 = L"WriteReadyIU";
      goto LAB_14000b14a;
    }
    uVar8 = 4;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,param_3,0xd,
                         in_stack_ffffffffffffffa8,(char)param_1[5],cVar1);
    }
LAB_14000b1c7:
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_i(uVar5,3,2,0x11,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                        (char)param_1[4]);
    }
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 3;
  if ((iVar2 + 0x3fffffefU < 2) || (iVar2 == -0x3ffffffc)) {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_i(uVar5,3,2,0x12,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                        (char)param_1[4]);
    }
    lVar6 = *param_1;
    pcVar7 = ResetPipeWorkItem;
    lVar9 = 0;
  }
  else {
    if (((iVar2 != -0x3fff9000) && (iVar3 != -0x3fffff63)) && (iVar3 != -0x3ffffff2))
    goto LAB_14000b42d;
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_SF_(uVar5,3,2,0x13,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids);
    }
    lVar6 = *param_1;
    pcVar7 = BulkResetDeviceWorkItem;
    param_4 = 0;
    lVar9 = *(longlong *)(lVar6 + 0xa0);
  }
  UaspQueueWorkItem(lVar6,(longlong)pcVar7,lVar9,param_4);
LAB_14000b42d:
  if (*(byte *)(param_1[4] + 3) < 2) {
    *(undefined1 *)(param_1[4] + 3) = uVar8;
  }
  QueueUpdateCompletion(param_1);
  return;
}



===== StatusPipeCompletion @ 14000b468 =====

void StatusPipeCompletion
               (longlong param_1,char *param_2,ulonglong param_3,longlong param_4,longlong param_5)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined2 uVar8;
  longlong *plVar9;
  ushort uVar10;
  ulonglong uVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined *in_stack_ffffffffffffff68;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  char cVar18;
  undefined1 uVar19;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  puVar5 = &local_40;
  uVar13 = param_3 & 0xffffffff;
  lVar14 = 0;
  lVar1 = **(longlong **)(param_1 + 8);
  uVar11 = param_3;
  KeAcquireInStackQueuedSpinLock(lVar1 + 0x470);
  plVar2 = *(longlong **)(param_1 + 8);
  iVar12 = (int)param_3;
  uVar15 = (undefined1)param_4;
  if (iVar12 < 0) {
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      uVar11 = 2;
      puVar5 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar5 >> 8),2);
      in_stack_ffffffffffffff68 = &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids;
      WPP_RECORDER_SF_PD(uVar3,2,2,0x14,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,uVar15,
                         (char)param_3);
    }
    if (param_4 == plVar2[0x10]) {
      lVar4 = plVar2[0xc];
LAB_14000b55d:
      if ((*(int *)(lVar4 + 4) == -0x3fff0000) && (*(int *)(lVar4 + 0x24) != 0)) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_id(uVar3);
        }
        goto LAB_14000b5ae;
      }
      goto LAB_14000b6c4;
    }
    if (param_4 == plVar2[0x11]) {
      lVar4 = plVar2[0xd];
      goto LAB_14000b55d;
    }
LAB_14000c0f4:
    *(undefined4 *)(plVar2 + 2) = 3;
  }
  else {
LAB_14000b5ae:
    uVar10 = (*(ushort *)(param_2 + 2) >> 8 | *(ushort *)(param_2 + 2) << 8) - 1;
    uVar16 = (undefined1)uVar10;
    if (uVar10 < *(ushort *)(lVar1 + 0x500)) {
      cVar18 = *param_2;
      plVar9 = (longlong *)((ulonglong)uVar10 * 0xe0 + *(longlong *)(lVar1 + 0x498));
      if ((cVar18 == '\x03') || (cVar18 == '\x04')) {
        if (((param_2[6] == '(') && (gTracingEnabled != '\0')) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          uVar11 = 2;
          puVar5 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar5 >> 8),2);
          in_stack_ffffffffffffff68 = &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids;
          WPP_RECORDER_SF_(uVar3,2,2,0x16,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids);
        }
        iVar7 = (int)plVar9[2];
        if (iVar7 == 2) {
          if (param_4 != plVar9[0x10]) {
            if (param_4 == plVar9[0x11]) {
              if ((gTracingEnabled != '\0') &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                WPP_RECORDER_SF_iDDDiDi(uVar3);
              }
              lVar1 = plVar9[0xc];
              lVar4 = plVar9[0x10];
              plVar9[0xc] = plVar9[0xd];
              plVar9[0x10] = plVar9[0x11];
              plVar9[0xd] = lVar1;
              lVar1 = plVar9[0x1a];
              plVar9[0x1a] = plVar9[0x1b];
              plVar9[0x11] = lVar4;
              plVar9[0x1b] = lVar1;
              if (*(char *)((longlong)plVar9 + 0xcb) != '\0') {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  lVar1 = plVar9[5];
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  WPP_RECORDER_SF_PD(uVar3,2,2,0x19,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids
                                     ,(char)lVar4,(char)lVar1 + -1);
                }
                lVar14 = plVar9[0x11];
              }
            }
            else {
              lVar1 = plVar2[0x10];
              uVar19 = (undefined1)plVar9[0x10];
              if (param_4 == lVar1) {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  cVar18 = (char)plVar2[5] + -1;
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  uVar17 = (undefined1)lVar1;
                  WPP_RECORDER_SF_iDiDDiDi
                            (uVar3,puVar5,uVar11,0x1a,in_stack_ffffffffffffff68,uVar15,uVar16,uVar17
                             ,cVar18,uVar16,uVar17,cVar18,uVar19);
                }
                lVar1 = plVar2[0xc];
                plVar2[0xc] = plVar9[0xc];
                plVar9[0xc] = lVar1;
                lVar1 = plVar2[0x10];
                plVar2[0x10] = plVar9[0x10];
                plVar9[0x10] = lVar1;
                lVar1 = plVar2[0x1a];
                plVar2[0x1a] = plVar9[0x1a];
                plVar9[0x1a] = lVar1;
                uVar3 = *(undefined8 *)(plVar2[0x1a] + 8);
                *(undefined8 *)(plVar2[0x1a] + 8) = *(undefined8 *)(lVar1 + 8);
                *(undefined8 *)(lVar1 + 8) = uVar3;
                if (*(char *)((longlong)plVar2 + 0xca) != '\0') {
                  if ((gTracingEnabled != '\0') &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    lVar1 = plVar2[5];
                    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                    WPP_RECORDER_SF_PD(uVar3,2,2,0x1b,
                                       &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                       (char)plVar2[0x10],(char)lVar1 + -1);
                  }
                  lVar14 = plVar2[0x10];
                }
              }
              else {
                lVar1 = plVar2[0x11];
                if (param_4 != lVar1) goto LAB_14000b671;
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  cVar18 = (char)plVar2[5] + -1;
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  uVar17 = (undefined1)lVar1;
                  WPP_RECORDER_SF_iDiDDiDi
                            (uVar3,puVar5,uVar11,0x1c,in_stack_ffffffffffffff68,uVar15,uVar16,uVar17
                             ,cVar18,uVar16,uVar17,cVar18,uVar19);
                }
                lVar1 = plVar2[0xd];
                plVar2[0xd] = plVar9[0xc];
                plVar9[0xc] = lVar1;
                lVar1 = plVar2[0x11];
                plVar2[0x11] = plVar9[0x10];
                plVar9[0x10] = lVar1;
                lVar1 = plVar2[0x1b];
                plVar2[0x1b] = plVar9[0x1a];
                plVar9[0x1a] = lVar1;
                uVar3 = *(undefined8 *)(plVar2[0x1b] + 8);
                *(undefined8 *)(plVar2[0x1b] + 8) = *(undefined8 *)(lVar1 + 8);
                *(undefined8 *)(lVar1 + 8) = uVar3;
                if (*(char *)((longlong)plVar2 + 0xcb) != '\0') {
                  if ((gTracingEnabled != '\0') &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    lVar1 = plVar2[5];
                    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                    WPP_RECORDER_SF_PD(uVar3,2,2,0x1d,
                                       &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                       (char)plVar2[0x11],(char)lVar1 + -1);
                  }
                  lVar14 = plVar2[0x11];
                }
              }
            }
          }
          *(undefined4 *)(plVar9 + 2) = 3;
          KeReleaseInStackQueuedSpinLock(&local_40);
          if (lVar14 != 0) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              lVar1 = plVar2[5];
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_PD(uVar3,2,2,0x1e,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                 (char)lVar14,(char)lVar1 + -1);
            }
            IoCancelIrp(lVar14);
          }
          if (*param_2 == '\x04') {
            ResponseIUCompletion(plVar9,param_2,iVar12,param_5);
            return;
          }
          goto LAB_14000c12a;
        }
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar8 = 0x17;
LAB_14000b632:
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          uVar11 = 2;
          in_stack_ffffffffffffff68 = &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids;
          WPP_RECORDER_SF_D(uVar3,2,2,uVar8,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                            (char)iVar7);
        }
      }
      else if ((cVar18 == '\x06') || (cVar18 == '\a')) {
        iVar7 = *(int *)((longlong)plVar9 + 0x14);
        if (iVar7 == 2) {
          if (param_4 != plVar9[0x11]) {
            lVar1 = plVar9[0x10];
            uVar19 = (undefined1)plVar9[0x11];
            if (param_4 == lVar1) {
              if ((gTracingEnabled != '\0') &&
                 (ppuVar6 = &WPP_RECORDER_INITIALIZED,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                uVar17 = (undefined1)lVar1;
                WPP_RECORDER_SF_iDiDDiDi
                          (uVar3,ppuVar6,uVar11,0x20,in_stack_ffffffffffffff68,uVar15,uVar16,uVar17,
                           uVar16,uVar16,uVar17,uVar16,uVar19);
              }
              lVar1 = plVar9[0xd];
              lVar4 = plVar9[0x11];
              plVar9[0xd] = plVar9[0xc];
              plVar9[0x11] = plVar9[0x10];
              plVar9[0xc] = lVar1;
              lVar1 = plVar9[0x1b];
              plVar9[0x1b] = plVar9[0x1a];
              plVar9[0x10] = lVar4;
              plVar9[0x1a] = lVar1;
              if (*(char *)((longlong)plVar9 + 0xca) != '\0') {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  lVar1 = plVar9[5];
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  WPP_RECORDER_SF_PD(uVar3,2,2,0x21,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids
                                     ,(char)lVar4,(char)lVar1 + -1);
                }
                lVar14 = plVar9[0x10];
              }
            }
            else {
              lVar1 = plVar2[0x11];
              if (param_4 == lVar1) {
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  cVar18 = (char)plVar2[5] + -1;
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  uVar17 = (undefined1)lVar1;
                  WPP_RECORDER_SF_iDiDDiDi
                            (uVar3,puVar5,uVar11,0x22,in_stack_ffffffffffffff68,uVar15,uVar16,uVar17
                             ,cVar18,uVar16,uVar17,cVar18,uVar19);
                }
                lVar1 = plVar2[0xd];
                plVar2[0xd] = plVar9[0xd];
                plVar9[0xd] = lVar1;
                lVar1 = plVar2[0x11];
                plVar2[0x11] = plVar9[0x11];
                plVar9[0x11] = lVar1;
                lVar1 = plVar2[0x1b];
                plVar2[0x1b] = plVar9[0x1b];
                plVar9[0x1b] = lVar1;
                uVar3 = *(undefined8 *)(plVar2[0x1b] + 8);
                *(undefined8 *)(plVar2[0x1b] + 8) = *(undefined8 *)(lVar1 + 8);
                *(undefined8 *)(lVar1 + 8) = uVar3;
                if (*(char *)((longlong)plVar2 + 0xcb) != '\0') {
                  if ((gTracingEnabled != '\0') &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    lVar1 = plVar2[5];
                    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                    WPP_RECORDER_SF_PD(uVar3,2,2,0x23,
                                       &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                       (char)plVar2[0x11],(char)lVar1 + -1);
                  }
                  lVar14 = plVar2[0x11];
                }
              }
              else {
                lVar1 = plVar2[0x10];
                if (param_4 != lVar1) goto LAB_14000b671;
                if ((gTracingEnabled != '\0') &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  cVar18 = (char)plVar2[5] + -1;
                  uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                  uVar17 = (undefined1)lVar1;
                  WPP_RECORDER_SF_iDiDDiDi
                            (uVar3,puVar5,uVar11,0x24,in_stack_ffffffffffffff68,uVar15,uVar16,uVar17
                             ,cVar18,uVar16,uVar17,cVar18,uVar19);
                }
                lVar1 = plVar2[0xc];
                plVar2[0xc] = plVar9[0xd];
                plVar9[0xd] = lVar1;
                lVar1 = plVar2[0x10];
                plVar2[0x10] = plVar9[0x11];
                plVar9[0x11] = lVar1;
                lVar1 = plVar2[0x1a];
                plVar2[0x1a] = plVar9[0x1b];
                plVar9[0x1b] = lVar1;
                uVar3 = *(undefined8 *)(plVar2[0x1a] + 8);
                *(undefined8 *)(plVar2[0x1a] + 8) = *(undefined8 *)(lVar1 + 8);
                *(undefined8 *)(lVar1 + 8) = uVar3;
                if (*(char *)((longlong)plVar2 + 0xca) != '\0') {
                  if ((gTracingEnabled != '\0') &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    lVar1 = plVar2[5];
                    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                    WPP_RECORDER_SF_PD(uVar3,2,2,0x25,
                                       &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                       (char)plVar2[0x10],(char)lVar1 + -1);
                  }
                  lVar14 = plVar2[0x10];
                }
              }
            }
          }
          *(undefined4 *)((longlong)plVar9 + 0x14) = 3;
          KeReleaseInStackQueuedSpinLock(&local_40);
          if (lVar14 != 0) {
            if ((gTracingEnabled != '\0') &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              lVar1 = plVar2[5];
              uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_SF_PD(uVar3,2,2,0x26,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,
                                 (char)lVar14,(char)lVar1 + -1);
            }
            IoCancelIrp(lVar14);
          }
          uVar13 = param_3 & 0xffffffff;
          goto LAB_14000bbb5;
        }
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar8 = 0x1f;
          goto LAB_14000b632;
        }
      }
    }
LAB_14000b671:
    if (-1 < iVar12) {
      if ((gTracingEnabled != '\0') &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        cVar18 = *param_2;
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_SF_DD(uVar3,2,uVar11,0x27,in_stack_ffffffffffffff68,cVar18,uVar16);
      }
      uVar13 = 0xc0000001;
    }
LAB_14000b6c4:
    if (param_4 != plVar2[0x11]) goto LAB_14000c0f4;
    *(undefined4 *)((longlong)plVar2 + 0x14) = 3;
  }
  KeReleaseInStackQueuedSpinLock(&local_40);
  iVar12 = (int)uVar13;
  plVar9 = plVar2;
  if (param_4 == plVar2[0x11]) {
LAB_14000bbb5:
    ReadyIUCompletion(plVar9,param_2,uVar13,param_5);
    return;
  }
LAB_14000c12a:
  SenseIUCompletion(plVar9,param_2,iVar12,param_5);
  return;
}



===== WPP_RECORDER_SF_DD @ 14000c158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,
                  &param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_SDi @ 14000c234 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDi(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,pwVar2,lVar1,&param_7,4,
               &param_8,8,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,3,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,param_6
                  ,lVar3,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_SDiD @ 14000c3c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SDiD(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (2 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0xf,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,3,1,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0xf,in_stack_00000030
                  ,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048
                  ,4,0);
  return;
}



===== WPP_RECORDER_SF_SP @ 14000c574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,L"PnPRemove",0x14,
               &param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,3,param_5,param_4,L"PnPRemove",0x14,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_iDDDiDi @ 14000c650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iDDDiDi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,&uStack0000000000000058,4,&uStack0000000000000060,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,0);
  return;
}



===== WPP_RECORDER_SF_iDiDDiDi @ 14000c7c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iDiDDiDi
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,4,&param_10,4,&param_11,8,&param_12,4,&param_13,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,&param_9,4,&param_10,4,&param_11,8,&param_12,4,&param_13,8,0
                 );
  return;
}



===== WPP_RECORDER_SF_id @ 14000c968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_id(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d051a084a3683fa63da562e0abde3dd2_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_iiD @ 14000ca40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iiD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== IssueCommandSS @ 14000cb38 =====

ulonglong IssueCommandSS(longlong param_1,longlong param_2,undefined4 *param_3,longlong param_4,
                        ushort param_5,char param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined8 local_30;
  
  cVar4 = param_6;
  param_5 = 0;
  local_30 = 0;
  uVar10 = QueueFindNextFree(param_1,&param_5,param_2,param_6);
  if ((int)uVar10 < 0) {
    return uVar10 & 0xffffffff;
  }
  uVar9 = (uint)param_5;
  plVar13 = (longlong *)((ulonglong)param_5 * 0xe0 + *(longlong *)(param_1 + 0x498));
  uVar6 = (ushort)(param_5 + 1) >> 8 | (param_5 + 1) * 0x100;
  plVar13[4] = param_2;
  plVar13[0x14] = param_4;
  *(char *)((longlong)plVar13 + 0xc9) = cVar4;
  puVar15 = (undefined1 *)((ulonglong)uVar9 * 0x20 + *(longlong *)(param_1 + 0x4a0));
  *(undefined4 *)(plVar13 + 1) = 1;
  *(undefined4 *)((longlong)plVar13 + 0xc) = 1;
  *(undefined4 *)(plVar13 + 2) = 1;
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *(undefined4 *)(plVar13 + 0x15) = *param_3;
    *(undefined4 *)((longlong)plVar13 + 0xac) = uVar1;
    *(undefined4 *)(plVar13 + 0x16) = uVar2;
    *(undefined4 *)((longlong)plVar13 + 0xb4) = uVar3;
  }
  *(bool *)(plVar13 + 0x17) = param_3 != (undefined4 *)0x0;
  plVar13[0x18] = 0;
  *(undefined1 *)(plVar13 + 0x19) = 0;
  if ((*(uint *)(param_2 + 0xc) & 0xc0) == 0) {
    *(undefined4 *)(plVar13 + 3) = 2;
  }
  else {
    *(undefined4 *)(plVar13 + 3) = 3;
    uVar7 = *(uint *)(param_2 + 0xc) & 0xc0;
    if (uVar7 == 0x40) {
      uVar7 = 3;
    }
    else {
      if (uVar7 != 0x80) {
        uVar10 = 0xc000000d;
        goto LAB_14000ce83;
      }
      uVar7 = 0;
    }
    *(undefined4 *)((longlong)plVar13 + 0xc) = 2;
    if (*(longlong *)(param_1 + 8) == 0) {
      local_30 = *(undefined8 *)(param_2 + 0x18);
    }
    else if (param_4 == 0) {
      lVar11 = param_1;
      lVar14 = param_2;
      iVar8 = StorPortExtendedFunction(5);
      if (iVar8 != 0) {
        if ((gTracingEnabled != '\0') &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar12 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_SF_iiD(uVar12,lVar11,lVar14,0xc,
                              &WPP_b606bc35c7ef35d872dd65732ef04e06_Traceguids,(char)param_2,
                              (char)*(undefined8 *)(param_2 + 0x18),(char)iVar8);
        }
        *(undefined1 *)(param_2 + 3) = 4;
        uVar10 = 0xc000009a;
        goto LAB_14000ce83;
      }
    }
    uVar7 = IssueBulkRequest(param_1,(longlong)plVar13,2,param_5,local_30,param_4,
                             *(undefined4 *)(param_2 + 0x10),uVar7 | -(uint)(cVar4 != '\0') & 0x10,
                             DataCompletion);
    uVar10 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
      uVar5 = 4;
      if (uVar7 == 0xc000000e) {
        uVar5 = 0xe;
      }
      else if (uVar7 == 0xc000003c) {
        uVar5 = 0x12;
      }
      *(undefined1 *)(param_2 + 3) = uVar5;
      goto LAB_14000ce83;
    }
  }
  puVar16 = (undefined1 *)((ulonglong)uVar9 * 0x400 + *(longlong *)(param_1 + 0x4b0));
  *puVar16 = 3;
  *(undefined2 *)(puVar16 + 6) = 0;
  *(undefined2 *)(puVar16 + 0xe) = 0;
  *(ushort *)(puVar16 + 2) = uVar6;
  *(undefined4 *)(plVar13 + 2) = 2;
  if (cVar4 == '\0') {
    uVar12 = 0;
  }
  else {
    uVar12 = *(undefined8 *)(param_1 + 0x5a8);
  }
  uVar9 = IssueBulkRequest(param_1,(longlong)plVar13,3,param_5,puVar16,uVar12,0x400,
                           (-(uint)(cVar4 != '\0') & 0x10) + 1,SenseIUCompletion);
  uVar10 = (ulonglong)uVar9;
  if (-1 < (int)uVar9) {
    *puVar15 = 1;
    uVar12 = *(undefined8 *)(param_2 + 0x50);
    *(undefined8 *)(puVar15 + 0x10) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(puVar15 + 0x18) = uVar12;
    if (*(longlong *)(param_1 + 0x468) == 0) {
      lVar11 = (ulonglong)*(byte *)(param_2 + 7) << 0x38;
    }
    else {
      lVar11 = *(longlong *)
                ((ulonglong)*(byte *)(param_2 + 7) * 0x20 + *(longlong *)(param_1 + 0x468));
    }
    puVar15[6] = puVar15[6] & 3;
    puVar15[4] = puVar15[4] & 0x80;
    *(longlong *)(puVar15 + 8) = lVar11;
    *(ushort *)(puVar15 + 2) = uVar6;
    *(undefined4 *)(plVar13 + 1) = 2;
    if (cVar4 == '\0') {
      uVar12 = 0;
    }
    else {
      uVar12 = *(undefined8 *)(param_1 + 0x5a0);
    }
    uVar9 = IssueBulkRequest(param_1,(longlong)plVar13,1,param_5,puVar15,uVar12,0x20,
                             -(uint)(cVar4 != '\0') & 0x10,CommandIUCompletion);
    if (-1 < (int)uVar9) {
      return (ulonglong)uVar9;
    }
    uVar5 = 4;
    if (uVar9 == 0xc000000e) {
      uVar5 = 0xe;
    }
    else if (uVar9 == 0xc000003c) {
      uVar5 = 0x12;
    }
    *(undefined1 *)(param_2 + 3) = uVar5;
    *(undefined4 *)(plVar13 + 1) = 3;
    if ((*(uint *)(param_2 + 0xc) & 0xc0) != 0) {
      IoCancelIrp(plVar13[0xf]);
    }
    IoCancelIrp(plVar13[0x10]);
    return 0;
  }
  uVar5 = 4;
  if (uVar9 == 0xc000000e) {
    uVar5 = 0xe;
  }
  else if (uVar9 == 0xc000003c) {
    uVar5 = 0x12;
  }
  *(undefined1 *)(param_2 + 3) = uVar5;
  if ((*(uint *)(param_2 + 0xc) & 0xc0) != 0) {
    *(undefined4 *)(plVar13 + 1) = 3;
    *(undefined4 *)(plVar13 + 2) = 3;
    IoCancelIrp(plVar13[0xf]);
    uVar10 = 0;
  }
  if (-1 < (int)uVar10) {
    return uVar10;
  }
LAB_14000ce83:
  QueueReleaseEntry(plVar13);
  return uVar10;
}



===== QueueCancelSSWorkItem @ 14000cfb0 =====

void QueueCancelSSWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  lVar1 = param_2[1];
  plVar4 = param_2;
  uVar2 = QueueCancel(*param_2);
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_P(uVar3,plVar4,3,0xe,&WPP_b606bc35c7ef35d872dd65732ef04e06_Traceguids,
                      (char)lVar1);
  }
  UaspCompleteWorkItem(param_2,(int)uVar2);
  return;
}



===== QueueCommandSS @ 14000d050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong QueueCommandSS(longlong param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 auStackY_98 [32];
  ushort in_stack_ffffffffffffff88;
  longlong local_58 [4];
  
  local_58[3] = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  lVar6 = param_3;
  iVar2 = StorPortExtendedFunction(0x28,param_1,param_3,local_58 + 1);
  plVar7 = local_58 + 1;
  if (iVar2 != 0) {
    plVar7 = (longlong *)0x0;
  }
  if ((*(uint *)(param_3 + 0xc) & 0xc0) != 0) {
    iVar2 = -0x3effffff;
    if (*(longlong *)(param_3 + 0x30) != 0) {
      param_1 = param_2;
      lVar6 = param_3;
      iVar2 = StorPortExtendedFunction(6,param_2,param_3,local_58);
      if (iVar2 == 0) goto LAB_14000d14d;
    }
    if ((gTracingEnabled != '\0') &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      in_stack_ffffffffffffff88 = 0x578;
      WPP_RECORDER_SF_iiD(uVar3,param_1,lVar6,10,&WPP_b606bc35c7ef35d872dd65732ef04e06_Traceguids,
                          (char)param_3,(char)*(undefined8 *)(param_3 + 0x18),(char)iVar2);
    }
    local_58[0] = 0;
  }
LAB_14000d14d:
  uVar4 = IssueCommandSS(param_2,param_3,(undefined4 *)plVar7,local_58[0],in_stack_ffffffffffffff88,
                         '\0');
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 == -0x3fffff66) {
    if ((0x1000 < *(uint *)(param_3 + 0x10)) || (*(char *)(param_2 + 0x3dc) == '\0'))
    goto LAB_14000d1a1;
    QueueCancel(param_2);
    uVar5 = IssueCommandSS(param_2,param_3,(undefined4 *)plVar7,local_58[0],
                           in_stack_ffffffffffffff88,'\x01');
    uVar5 = uVar5 & 0xffffffff;
  }
  if (-1 < (int)uVar5) {
    return uVar5;
  }
LAB_14000d1a1:
  if ((gTracingEnabled != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar1 = *(undefined1 *)(param_3 + 3);
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_PD(uVar3,4,5,0xb,&WPP_b606bc35c7ef35d872dd65732ef04e06_Traceguids,(char)param_3,
                       uVar1);
  }
  StorPortNotification(0,param_2,param_3);
  return uVar5;
}



===== USBDInternal_BuildAndSendQueryInterfaceSynchronously @ 14000d234 =====

int USBDInternal_BuildAndSendQueryInterfaceSynchronously
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined2 *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Failed to allocate Query Interface Irp for Target Device Ojbect 0x%p\n",
                 param_2);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined2 **)(lVar1 + -0x30) = param_4;
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(undefined8 *)(lVar1 + -0x40) = param_3;
    *(undefined2 *)(lVar1 + -0x38) = *param_4;
    *(undefined2 *)(lVar1 + -0x36) = param_4[1];
    iVar2 = IoSetCompletionRoutineEx(param_1,lVar3,USBD_SyncCompletionRoutine,&local_28,1,1,1);
    if (iVar2 < 0) {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar1 + -8) = &local_28;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    }
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(param_2,lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== USBDInternal_BuildServicePath @ 14000d3b0 =====

uint USBDInternal_BuildServicePath(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  longlong lVar4;
  short *_Dst;
  short *psVar5;
  longlong lVar6;
  short *psVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  
  lVar6 = *(longlong *)(param_1 + 8);
  _Dst = (short *)0x0;
  if ((*(ushort *)(lVar6 + 0x38) < 0x11) ||
     (lVar4 = RtlCompareMemory(*(undefined8 *)(lVar6 + 0x40),L"\\Driver\\",0x10), lVar4 != 0x10)) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Unexpected Driver name, Drvobj 0x%p\n",lVar6);
    }
    uVar9 = 0xc00000e5;
  }
  else {
    lVar4 = *(longlong *)(lVar6 + 0x40);
    uVar2 = *(ushort *)(lVar6 + 0x38);
    uVar1 = uVar2 + 8;
    _Dst = (short *)ExAllocatePoolWithTag(DAT_140012130,uVar1,0x75617370);
    if (_Dst == (short *)0x0) {
      uVar9 = 0xc000009a;
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"Couldnt allocate servicePath of size %d\n",uVar1);
      }
    }
    else {
      memset(_Dst,0,(ulonglong)uVar1);
      memmove(_Dst,(void *)(lVar4 + 0x10),(ulonglong)(uVar2 - 0x10));
      uVar10 = (ulonglong)(uVar1 >> 1);
      if (uVar10 == 0) {
        uVar9 = 0xc000000d;
      }
      else {
        psVar5 = _Dst;
        uVar8 = uVar10;
        do {
          if (*psVar5 == 0) break;
          psVar5 = psVar5 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
        if (uVar8 == 0) {
          uVar9 = 0xc000000d;
        }
        else {
          lVar6 = uVar10 - uVar8;
          psVar5 = _Dst + lVar6;
          lVar4 = uVar10 - lVar6;
          if (lVar4 != 0) {
            lVar6 = lVar4 + 0x7ffffffe + (lVar6 - uVar10);
            lVar11 = (longlong)L"\\Parameters" - (longlong)psVar5;
            do {
              if ((lVar6 == 0) || (sVar3 = *(short *)(lVar11 + (longlong)psVar5), sVar3 == 0))
              break;
              *psVar5 = sVar3;
              lVar6 = lVar6 + -1;
              psVar5 = psVar5 + 1;
              lVar4 = lVar4 + -1;
            } while (lVar4 != 0);
          }
          psVar7 = psVar5 + -1;
          if (lVar4 != 0) {
            psVar7 = psVar5;
          }
          uVar9 = ~-(uint)(lVar4 != 0) & 0x80000005;
          *psVar7 = 0;
        }
      }
      if ((int)uVar9 < 0) {
        if (g_EnableDbgPrints != '\0') {
          DbgPrintEx(0x4d,0,"RtlStringCchCatW failed with status 0x%x",uVar9);
        }
        ExFreePoolWithTag(_Dst,0x75617370);
        _Dst = (short *)0x0;
      }
      else {
        uVar9 = 0;
      }
    }
  }
  *param_2 = _Dst;
  return uVar9;
}



===== USBDInternal_BuildandSendIoctlSynchronously @ 14000d5d4 =====

int USBDInternal_BuildandSendIoctlSynchronously
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Failed to allocate Irp for Target Device Object 0x%p\n",param_2);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar3 + 0x18) = param_3;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x40) = param_4;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x49104b;
    iVar2 = IoSetCompletionRoutineEx(param_1,lVar3,USBD_SyncCompletionRoutine,&local_28,1,1,1);
    if (iVar2 < 0) {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar1 + -8) = &local_28;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    }
    iVar2 = IofCallDriver(param_2,lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== USBDInternal_QueryUsbVerifierSettings @ 14000d738 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBDInternal_QueryUsbVerifierSettings(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 *_Dst;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  puVar1 = (undefined4 *)(param_2 + 0x48);
  local_res10 = 0;
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = MmIsDriverVerifying(*(undefined8 *)(param_1 + 8));
  *puVar1 = uVar2;
  RtlInitUnicodeString(&local_48,L"IoOpenDriverRegistryKey");
  pcVar5 = (code *)MmGetSystemRoutineAddress(&local_48);
  if (pcVar5 == (code *)0x0) {
    uVar4 = USBDInternal_BuildServicePath(param_1,&local_res8);
    lVar8 = local_res8;
    if (-1 < (int)uVar4) goto LAB_14000d817;
  }
  else {
    iVar3 = (*pcVar5)(*(undefined8 *)(param_1 + 8),0,1,0,&local_res10);
    lVar8 = 0;
    if (iVar3 < 0) {
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"IoOpenDriverRegistryKey failed with 0x%x\n",iVar3);
      }
      goto LAB_14000da77;
    }
LAB_14000d817:
    _Dst = (undefined8 *)ExAllocatePoolWithTag(DAT_140012130,0x1c0,0x75617370);
    if (_Dst == (undefined8 *)0x0) {
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"ExAllocatePoolWithTag for USBDInternal_QueryUsbVerifierSettings failed\n"
                  );
      }
    }
    else {
      memset(_Dst,0,0x1c0);
      _Dst[3] = puVar1;
      *_Dst = USBD_VerifierSettingsCallback;
      _Dst[2] = L"UsbVerifierEnabled";
      *(undefined4 *)(_Dst + 4) = 4;
      *(undefined4 *)(_Dst + 6) = 4;
      _Dst[5] = puVar1;
      _Dst[9] = L"UsbVerifierFailRegistration";
      _Dst[10] = param_2 + 0x4c;
      _Dst[0xc] = param_2 + 0x4c;
      _Dst[7] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0xb) = 4;
      *(undefined4 *)(_Dst + 0xd) = 4;
      _Dst[0x10] = L"UsbVerifierFailChainedMdlSupport";
      _Dst[0x11] = param_2 + 0x50;
      _Dst[0x13] = param_2 + 0x50;
      _Dst[0xe] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x12) = 4;
      *(undefined4 *)(_Dst + 0x14) = 4;
      _Dst[0x17] = L"UsbVerifierFailStaticStreamSupport";
      _Dst[0x18] = param_2 + 0x54;
      _Dst[0x1a] = param_2 + 0x54;
      _Dst[0x15] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x19) = 4;
      *(undefined4 *)(_Dst + 0x1b) = 4;
      _Dst[0x1e] = L"UsbVerifierStaticStreamCountOverride";
      _Dst[0x1f] = param_2 + 0x58;
      _Dst[0x21] = param_2 + 0x58;
      _Dst[0x1c] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x20) = 4;
      *(undefined4 *)(_Dst + 0x22) = 4;
      _Dst[0x25] = L"UsbVerifierFailEnableStaticStreams";
      _Dst[0x26] = param_2 + 0x5c;
      _Dst[0x28] = param_2 + 0x5c;
      _Dst[0x23] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x27) = 4;
      *(undefined4 *)(_Dst + 0x29) = 4;
      _Dst[0x2c] = L"UsbVerifierFailSecureTransferSupport";
      _Dst[0x2a] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x2e) = 4;
      *(undefined4 *)(_Dst + 0x30) = 4;
      _Dst[0x2d] = param_2 + 0xa0;
      _Dst[0x2f] = param_2 + 0xa0;
      lVar7 = lVar8;
      if (pcVar5 != (code *)0x0) {
        lVar7 = local_res10;
      }
      local_38 = 0;
      uStack_30 = 0;
      RtlInitUnicodeString(&local_38,L"RtlQueryRegistryValuesEx");
      pcVar6 = (code *)MmGetSystemRoutineAddress(&local_38);
      if (pcVar6 == (code *)0x0) {
        pcVar6 = RtlQueryRegistryValues_exref;
      }
      iVar3 = (*pcVar6)((-(uint)(pcVar5 != (code *)0x0) & 0x3fffffff) + 1,lVar7,_Dst,0,0);
      if ((iVar3 < 0) && (g_EnableDbgPrints != '\0')) {
        DbgPrintEx(0x4d,0,"RtlQueryRegistrySettings failed, ignoring this error0x%x\n",iVar3);
      }
      ExFreePoolWithTag(_Dst,0x75617370);
    }
  }
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8,0x75617370);
  }
LAB_14000da77:
  if (local_res10 != 0) {
    ZwClose();
  }
  return;
}



===== USBD_CreateHandle @ 14000daac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBD_CreateHandle(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 *param_5)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *_Dst;
  char *pcVar6;
  bool bVar7;
  undefined1 auStack_1e8 [32];
  int local_1c8;
  undefined4 local_1b8 [2];
  undefined8 local_1b0;
  code *local_1a0;
  code *local_178;
  undefined4 local_168;
  uint local_164;
  uint local_160;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  uVar4 = 0;
  bVar2 = false;
  cVar3 = KeGetCurrentIrql();
  if (cVar3 == '\0') {
    if (DAT_140012134 == '\0') {
      DAT_140012130 = 0;
      memset(&local_164,0,0x118);
      local_168 = 0x11c;
      iVar5 = RtlGetVersion(&local_168);
      if ((-1 < iVar5) && ((6 < local_164 || ((local_164 == 6 && (1 < local_160)))))) {
        DAT_140012130 = 0x200;
      }
    }
    DAT_140012134 = '\x01';
    if (param_1 == 0) {
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "DeviceObject cannot be NULL\n";
LAB_14000dbb8:
        DbgPrintEx(0x4d,0,pcVar6);
      }
    }
    else {
      if (param_2 != 0) {
        if (param_5 == (undefined8 *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"USBDHandle cannot be NULL\n");
          }
          return -0x3ffffff3;
        }
        _Dst = (undefined4 *)ExAllocatePoolWithTag(DAT_140012130,0xe8,0x75617370);
        if (_Dst == (undefined4 *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"Allocation Failed\n");
          }
          iVar5 = -0x3fffff66;
          goto LAB_14000deab;
        }
        memset(_Dst,0,0xe8);
        puVar1 = _Dst + 2;
        USBDInternal_QueryUsbVerifierSettings(param_1,(longlong)puVar1);
        *_Dst = 0x44425355;
        *(undefined2 *)((longlong)_Dst + 10) = 0x603;
        _Dst[0x36] = 0x603;
        *(undefined2 *)puVar1 = 200;
        _Dst[10] = 0x602;
        *(longlong *)(_Dst + 0xe) = param_1;
        _Dst[0x10] = 0x75617370;
        *(undefined4 **)(_Dst + 0x12) = _Dst;
        *(longlong *)(_Dst + 0x34) = param_2;
        _Dst[0x37] = 1;
        iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                          (param_1,param_2,&GUID_USBD_INTERFACE,(undefined2 *)puVar1);
        if (iVar5 < 0) {
          if (g_EnableDbgPrints != '\0') {
            local_1c8 = iVar5;
            DbgPrintEx(0x4d,3,
                       "Core stack (TargetDevieObject 0x%p) failed USBD_INTERFACE_VERSION_603, 0x%x\n"
                       ,param_2);
          }
          *(undefined2 *)(_Dst + 2) = 0x98;
          *(undefined2 *)((longlong)_Dst + 10) = 0x602;
          _Dst[0x36] = 0x602;
          iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                            (param_1,param_2,&GUID_USBD_INTERFACE,(undefined2 *)(_Dst + 2));
          if (-1 < iVar5) goto LAB_14000dcdc;
          bVar7 = g_EnableDbgPrints != '\0';
          _Dst[0x36] = 0x600;
          if (bVar7) {
            local_1c8 = iVar5;
            DbgPrintEx(0x4d,3,
                       "Core stack (TargetDevieObject 0x%p) failed USBD_INTERFACE_VERSION_602, 0x%x\n"
                       ,param_2);
          }
          iVar5 = 0;
        }
        else {
          _Dst[0x36] = (uint)*(ushort *)((longlong)_Dst + 10);
LAB_14000dcdc:
          bVar2 = true;
        }
        if (g_EnableDbgPrints != '\0') {
          DbgPrintEx(0x4d,3,"USBD_CreateHandle Successful: usbdHandleInfo 0x%p\n",_Dst);
        }
        if (_Dst[0x36] == 0x600) {
          memset(local_1b8,0,0x48);
          local_1b8[0] = 0x10048;
          iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                            (param_1,param_2,&USB_BUS_INTERFACE_USBDI_GUID,(undefined2 *)local_1b8);
          if (iVar5 < 0) {
            if (g_EnableDbgPrints != '\0') {
              local_1c8 = iVar5;
              DbgPrintEx(0x4d,0,
                         "Core stack (TargetDevieObject 0x%p) failed query to USB_BUS_INTERFACE_USBDI_GUID : USB_BUSIF_USBDI_VERSION_1, 0x%x\n"
                         ,param_2);
            }
            _Dst[0x36] = 0xffffffff;
            iVar5 = 0;
          }
          else {
            if (local_178 != (code *)0x0) {
              uVar4 = (*local_178)(local_1b0);
            }
            *(undefined1 *)(_Dst + 0x38) = uVar4;
            (*local_1a0)(local_1b0);
          }
LAB_14000dd7e:
          *param_5 = _Dst;
          return iVar5;
        }
        if (-1 < iVar5) goto LAB_14000dd7e;
        if ((bVar2) && (*(code **)(_Dst + 0x1c) != (code *)0x0)) {
          (**(code **)(_Dst + 0x1c))(*(undefined8 *)(_Dst + 0xc));
        }
        ExFreePoolWithTag(_Dst,0x75617370);
        goto LAB_14000deab;
      }
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "TargetDeviceObject cannot be NULL\n";
        goto LAB_14000dbb8;
      }
    }
    iVar5 = -0x3ffffff3;
  }
  else {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Irql Too High\n");
    }
    iVar5 = -0x3ffffeb8;
  }
  if (param_5 == (undefined8 *)0x0) {
    return iVar5;
  }
LAB_14000deab:
  *param_5 = 0;
  return iVar5;
}



===== USBD_QueryUsbCapability @ 14000debc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBD_QueryUsbCapability(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 auStack_68 [48];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if (param_1 == 0) {
      if (g_EnableDbgPrints == '\0') {
        return -0x3ffffff3;
      }
      pcVar4 = "USBDHandle cant be NULL\n";
    }
    else {
      if (param_4 != 0) {
        if (*(int *)(param_1 + 0xd8) == -1) {
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffffe;
          }
          pcVar4 = 
          "Could not exchange an interface with the Underlying USB core stack, querrying for capability is not possible\n"
          ;
LAB_14000df5e:
          DbgPrintEx(0x4d,0,pcVar4);
          return -0x3ffffffe;
        }
        if (*(int *)(param_1 + 0xd8) != 0x600) {
          local_30 = *(undefined8 *)(param_1 + 0x30);
          local_34 = 0;
          local_14 = 0;
          local_28 = 0x4e6b0dc909051e1f;
          uStack_20 = 0x8faa81bd0c96128b;
          local_38 = 0x280001;
          local_18 = 2;
          iVar2 = USBDInternal_BuildandSendIoctlSynchronously
                            (*(undefined8 *)(param_1 + 0x38),*(longlong *)(param_1 + 0xd0),param_4,
                             &local_38);
          return iVar2;
        }
        lVar3 = RtlCompareMemory(&GUID_USB_CAPABILITY_STATIC_STREAMS,
                                 &GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE,0x10);
        if (lVar3 == 0x10) {
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffff3;
          }
          pcVar4 = 
          "OutputBuffer must be NULL for GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE\n"
          ;
        }
        else {
          lVar3 = RtlCompareMemory(&GUID_USB_CAPABILITY_STATIC_STREAMS,
                                   &GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,0x10);
          if (lVar3 != 0x10) {
            if (g_EnableDbgPrints == '\0') {
              return -0x3ffffffe;
            }
            pcVar4 = "QueryUsbCapability not supported/implemented by core stack\n";
            goto LAB_14000df5e;
          }
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffff3;
          }
          pcVar4 = "OutputBuffer must be NULL for GUID_USB_CAPABILITY_SELECTIVE_SUSPEND\n";
        }
        DbgPrintEx(0x4d,0,pcVar4);
        return -0x3ffffff3;
      }
      if (g_EnableDbgPrints == '\0') {
        return -0x3ffffff3;
      }
      pcVar4 = "OutputBuffer cant be NULL if OutputBufferLength is not zero\n";
    }
  }
  else {
    if (g_EnableDbgPrints == '\0') {
      return -0x3ffffff3;
    }
    pcVar4 = "PASSIVE_LEVEL required\n";
  }
  DbgPrintEx(0x4d,0,pcVar4);
  return -0x3ffffff3;
}



===== USBD_UrbAllocate @ 14000e098 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBD_UrbAllocate(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *_Dst;
  char *pcVar4;
  
  if (param_1 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"USBDHandle cant be NULL\n");
    }
    iVar3 = -0x3ffffff3;
    if (param_2 == (undefined8 *)0x0) {
      return -0x3ffffff3;
    }
    goto LAB_14000e273;
  }
  if (param_2 == (undefined8 *)0x0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Urb cant be NULL\n");
    }
    return -0x3ffffff3;
  }
  if (*(char *)(param_1 + 0xe1) == '\0') {
    if (0 < *(int *)(param_1 + 0xdc)) {
      LOCK();
      *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
      UNLOCK();
      if (*(code **)(param_1 + 0x78) == (code *)0x0) {
        _Dst = (void *)ExAllocatePoolWithTag(DAT_140012130,0x98,*(undefined4 *)(param_1 + 0x40));
        *param_2 = _Dst;
        if (_Dst == (void *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"Insufficient Memory to allocate URB\n");
          }
          iVar3 = -0x3fffff66;
        }
        else {
          memset(_Dst,0,0x98);
          iVar3 = 0;
        }
      }
      else {
        iVar3 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x30));
      }
      if (-1 < iVar3) {
        return iVar3;
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xdc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 < 2) {
        if (*(char *)(param_1 + 0xe1) == '\0') {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,
                       "UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                       param_1);
          }
        }
        else {
          if (*(code **)(param_1 + 0x70) != (code *)0x0) {
            (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x30));
          }
          ExFreePoolWithTag(param_1,*(undefined4 *)(param_1 + 0x40));
        }
      }
      goto LAB_14000e273;
    }
    if (g_EnableDbgPrints != '\0') {
      pcVar4 = "UsbdHandleInfo->ReferenceCount must be 1 or higher 0x%p\n";
      goto LAB_14000e14e;
    }
  }
  else if (g_EnableDbgPrints != '\0') {
    pcVar4 = "UsbdHandleInfo->PendingDelete is set, UsbdHandleInfo 0x%p\n";
LAB_14000e14e:
    DbgPrintEx(0x4d,0,pcVar4,param_1);
  }
  iVar3 = -0x3ffffe7c;
  if (g_EnableDbgPrints != '\0') {
    DbgPrintEx(0x4d,0,"USBDInternal_ReferenceHandle failed %x\n",0xc0000184);
  }
LAB_14000e273:
  *param_2 = 0;
  return iVar3;
}



===== USBD_UrbFree @ 14000e298 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBD_UrbFree(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    if (g_EnableDbgPrints == '\0') {
      return;
    }
    pcVar3 = "Urb cant be NULL\n";
  }
  else {
    if (param_1 != 0) {
      if (*(code **)(param_1 + 0x98) == (code *)0x0) {
        ExFreePoolWithTag(param_2,*(undefined4 *)(param_1 + 0x40));
      }
      else {
        (**(code **)(param_1 + 0x98))(param_2);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xdc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (1 < iVar2) {
        return;
      }
      if (*(char *)(param_1 + 0xe1) != '\0') {
        if (*(code **)(param_1 + 0x70) != (code *)0x0) {
          (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x30));
        }
        ExFreePoolWithTag(param_1,*(undefined4 *)(param_1 + 0x40));
        return;
      }
      if (g_EnableDbgPrints == '\0') {
        return;
      }
      DbgPrintEx(0x4d,0,"UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                 param_1);
      return;
    }
    if (g_EnableDbgPrints == '\0') {
      return;
    }
    pcVar3 = "USBDHandle cant be NULL\n";
  }
  DbgPrintEx(0x4d,0,pcVar3);
  return;
}



===== USBD_VerifierSettingsCallback @ 14000e390 =====

undefined8
USBD_VerifierSettingsCallback
          (undefined8 param_1,int param_2,undefined4 *param_3,int param_4,undefined8 param_5,
          undefined4 *param_6)

{
  if (param_2 != 4) {
    return 0xc000000d;
  }
  if (param_4 != 4) {
    return 0xc00000e5;
  }
  if (param_6 != param_3) {
    *param_6 = *param_3;
  }
  return 0;
}



===== __GSHandlerCheck @ 14000e3c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000e3ec =====

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



===== __cpu_features_init @ 14000e460 =====

/* WARNING: Removing unreachable block (ram,0x00014000e4ca) */
/* WARNING: Removing unreachable block (ram,0x00014000e479) */
/* WARNING: Removing unreachable block (ram,0x00014000e46a) */

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



===== __security_check_cookie @ 14000e530 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000e570 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000e5a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000e5a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000e5d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000e640 =====

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



===== memset @ 14000e940 =====

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



===== __memset_repmovs @ 14000ea80 =====

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



===== __memset_query @ 14000eb00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000eb80 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000ecc0 =====

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



===== __memset_spec_plain @ 14000ed40 =====

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



===== WppCleanupKm @ 140015008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

{
  undefined8 *puVar1;
  
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[2]) {
        if (puVar1[7] != 0) {
          (*pfnEtwUnregister)();
          puVar1[7] = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1400150b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 140015194 =====

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



===== WppTraceCallback @ 1400152e0 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_details_EvaluateFeatureDependencies @ 140015568 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400155a3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001561d:
  while( true ) {
    if (&UNK_140011c67 < ppuVar3) {
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
      if (&UNK_140011c67 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400155a3:
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
      if (&UNK_140011c67 < ppuVar2) goto LAB_14001561d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001561d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140015658 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400156f0;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400156f0;
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
LAB_1400156f0:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140015740 =====

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
              if (&UNK_140011c67 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400157c0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400158bd;
  }
LAB_1400158c6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400158bd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400158c6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001588e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001588e;
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
    if (&UNK_140011c67 < ppuVar3) goto LAB_1400158c6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400158bd;
}



===== entry @ 140017010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140017044 =====

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



===== wil_InitializeFeatureStaging @ 140017078 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400170ff;
    }
LAB_140017139:
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
LAB_1400170ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140017139;
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
    goto LAB_140017139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140011c67 < ppuVar3) goto LAB_140017139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400170ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001718c =====

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
            if (&UNK_140011c67 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140017276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140017276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140017276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140011c67 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


