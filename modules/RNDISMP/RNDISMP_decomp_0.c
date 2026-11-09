
===== __report_gsfailure @ 180001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CompleteMiniportReset @ 180001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CompleteMiniportReset(longlong *param_1,undefined4 param_2,undefined1 param_3)

{
  if (*(char *)((longlong)param_1 + 0x501) != '\0') {
    CompletePendingRequests(param_1);
    LOCK();
    *(int *)(param_1 + 0xaa) = (int)param_1[0xaa] + 1;
    UNLOCK();
    (**(code **)(*param_1 + 0x1c8))(*param_1,param_2,param_3);
    *(undefined1 *)((longlong)param_1 + 0x501) = 0;
  }
  return;
}



===== CompletePendingRequests @ 180001080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CompletePendingRequests(longlong *param_1)

{
  longlong ***ppplVar1;
  longlong lVar2;
  longlong ****pppplVar3;
  undefined1 uVar4;
  code *pcVar5;
  longlong ****pppplVar6;
  longlong ****pppplVar7;
  undefined1 *puVar8;
  longlong ****unaff_RSI;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  pppplVar6 = (longlong ****)(param_1 + 0x85);
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pppplVar6);
  *(undefined1 *)(param_1 + 0x86) = uVar4;
  pppplVar7 = (longlong ****)param_1[0x83];
  while( true ) {
    do {
      pppplVar3 = pppplVar7;
      if (pppplVar3 == (longlong ****)(param_1 + 0x83)) {
        KeReleaseSpinLock(pppplVar6,CONCAT71((int7)((ulonglong)pppplVar3 >> 8),(char)param_1[0x86]))
        ;
        puVar8 = auStack_38;
        pppplVar6 = local_18;
        if ((longlong *****)local_18 != &local_18) goto LAB_180001158;
        return;
      }
      pppplVar7 = (longlong ****)*pppplVar3;
    } while (1 < *(int *)(pppplVar3 + 6) - 4U);
    if (((longlong ****)pppplVar7[1] != pppplVar3) ||
       (ppplVar1 = pppplVar3[1], (longlong ****)*ppplVar1 != pppplVar3)) break;
    *ppplVar1 = (longlong **)pppplVar7;
    pppplVar7[1] = ppplVar1;
    if ((longlong *****)*local_10 != &local_18) break;
    pppplVar3[1] = (longlong ***)local_10;
    *pppplVar3 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar3;
    local_10 = pppplVar3;
    if ((longlong ****)param_1[0xc] == pppplVar3) {
      param_1[0xc] = 0;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar8 = auStack_30;
  do {
    lVar2 = *param_1;
    if (*(int *)(pppplVar6 + 6) == 4) {
      pcVar5 = *(code **)(lVar2 + 0x2c8);
    }
    else {
      pcVar5 = *(code **)(lVar2 + 0x2d0);
    }
    *(undefined8 *)(puVar8 + -8) = 0x1800011a7;
    (*pcVar5)(lVar2,0xc001000c);
    pppplVar7 = pppplVar6;
    pppplVar6 = unaff_RSI;
    while( true ) {
      ppplVar1 = pppplVar7[4];
      *(undefined8 *)(puVar8 + -8) = 0x1800011b9;
      NdisFreeMemory(ppplVar1,1);
      pppplVar7[4] = (longlong ***)0xabababab;
      *(undefined8 *)(puVar8 + -8) = 0x1800011cf;
      DereferenceMsgFrame((longlong)pppplVar7);
      if (pppplVar6 == (longlong ****)(puVar8 + 0x20)) {
        return;
      }
LAB_180001158:
      unaff_RSI = (longlong ****)*pppplVar6;
      if (*pppplVar6[4] == (longlong **)0x0) break;
      lVar2 = *param_1;
      *(undefined8 *)(puVar8 + -8) = 0x180001176;
      NdisMCoRequestComplete(0xc001000c,lVar2);
      pppplVar7 = pppplVar6;
      pppplVar6 = unaff_RSI;
    }
  } while( true );
}



===== CompleteSendHalt @ 180001200 =====

void CompleteSendHalt(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  DereferenceMsgFrame(param_1);
  NdisSetEvent(lVar1 + 0x508);
  return;
}



===== CompleteSendInit @ 180001230 =====

void CompleteSendInit(longlong param_1)

{
  DereferenceMsgFrame(param_1);
  return;
}



===== CompleteSendReset @ 180001250 =====

void CompleteSendReset(longlong param_1,int param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x18);
  DereferenceMsgFrame(param_1);
  if (param_2 != 0) {
    CompleteMiniportReset(plVar1,param_2,0);
  }
  return;
}



===== DllInitialize @ 180001290 =====

undefined8 DllInitialize(void)

{
                    /* 0x1290  1  DllInitialize
                       0x1290  2  DllUnload */
  return 0;
}



===== Feature_2112250168__private_IsEnabledDeviceUsageNoInline @ 18000129c =====

ulonglong Feature_2112250168__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_2112250168__private_featureState;
  if (((uint)Feature_2112250168__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2112250168__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_2112250168__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2112250168__private_IsEnabledFallback @ 1800012d4 =====

void Feature_2112250168__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2112250168__private_descriptor);
  return;
}



===== HaltMessage @ 1800012f0 =====

undefined1 HaltMessage(undefined8 *param_1)

{
  NdisMRemoveMiniport(*param_1);
  return 1;
}



===== InitCompletionMessage @ 180001320 =====

undefined8 InitCompletionMessage(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined8 in_RAX;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  
  if ((0x33 < *(uint *)(param_2 + 4)) && (*(longlong *)(param_1 + 0x528) != 0)) {
    uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
    plVar11 = (longlong *)(param_1 + 0x418);
    *(undefined1 *)(param_1 + 0x430) = uVar8;
    plVar12 = (longlong *)0x0;
    if ((longlong *)*plVar11 != plVar11) {
      plVar9 = (longlong *)*plVar11;
      do {
        plVar1 = (longlong *)*plVar9;
        if (*(int *)((longlong)plVar9 + 0x34) == *(int *)(param_2 + 8)) {
          if (((longlong *)plVar1[1] != plVar9) ||
             (plVar11 = (longlong *)plVar9[1], (longlong *)*plVar11 != plVar9)) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar10 = (*pcVar4)();
            return uVar10;
          }
          *plVar11 = (longlong)plVar1;
          plVar1[1] = (longlong)plVar11;
          plVar12 = plVar9;
          if (*(longlong **)(param_1 + 0x60) == plVar9) {
            *(undefined8 *)(param_1 + 0x60) = 0;
          }
          break;
        }
        plVar9 = plVar1;
      } while (plVar1 != plVar11);
    }
    in_RAX = KeReleaseSpinLock(param_1 + 0x428,
                               CONCAT71((int7)((ulonglong)plVar11 >> 8),
                                        *(undefined1 *)(param_1 + 0x430)));
    if (plVar12 != (longlong *)0x0) {
      uVar10 = *(undefined8 *)(param_2 + 0x10);
      lVar2 = plVar12[4];
      puVar3 = *(undefined8 **)(param_1 + 0x528);
      *puVar3 = *(undefined8 *)(param_2 + 8);
      puVar3[1] = uVar10;
      uVar5 = *(undefined4 *)(param_2 + 0x1c);
      uVar6 = *(undefined4 *)(param_2 + 0x20);
      uVar7 = *(undefined4 *)(param_2 + 0x24);
      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(param_2 + 0x18);
      *(undefined4 *)((longlong)puVar3 + 0x14) = uVar5;
      *(undefined4 *)(puVar3 + 3) = uVar6;
      *(undefined4 *)((longlong)puVar3 + 0x1c) = uVar7;
      puVar3[4] = *(undefined8 *)(param_2 + 0x28);
      *(undefined4 *)(puVar3 + 5) = *(undefined4 *)(param_2 + 0x30);
      in_RAX = NdisSetEvent(*(undefined8 *)(lVar2 + 0x48));
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== KeepAliveCompletionMessage @ 180001440 =====

undefined8
KeepAliveCompletionMessage(longlong param_1,longlong param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_2112250168__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 == 0) || (0xf < param_4)) {
    iVar1 = *(int *)(param_2 + 0xc);
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
    *(undefined1 *)(param_1 + 0x502) = 0;
    *(undefined1 *)(param_1 + 0x430) = uVar2;
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x500) = 1;
    }
    uVar3 = KeReleaseSpinLock(param_1 + 0x428,uVar2);
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== KeepAliveMessage @ 1800014d0 =====

undefined8 KeepAliveMessage(longlong param_1,longlong param_2,undefined8 param_3,uint param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  uVar1 = Feature_2112250168__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar1 == 0) || (0xb < param_4)) {
    plVar2 = BuildRndisMessageCommon(param_1,-0x7ffffff8,0,(undefined4 *)(param_2 + 8),4);
    uVar1 = 0;
    if (plVar2 != (longlong *)0x0) {
      plVar2[7] = 0;
      uVar1 = QueueMessageToMicroport(param_1,plVar2,'\0');
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== ReadAndSetRegistryParameters @ 180001544 =====

int ReadAndSetRegistryParameters(longlong param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  ushort local_80 [8];
  longlong local_70 [2];
  wchar_t *local_60;
  longlong local_58;
  wchar_t *local_50;
  longlong local_48;
  wchar_t *local_40;
  longlong local_38;
  wchar_t *local_30;
  
  local_70[1] = 0x80006;
  local_88 = 0;
  local_res18[0] = 0;
  local_60 = L"Ndi";
  local_res20 = 0;
  NdisOpenConfiguration(local_res18,&local_res20,param_2);
  if (local_res18[0] == 0) {
    NdisOpenConfigurationKeyByName(local_res18,local_res20,local_70 + 1,&local_88);
    if (local_res18[0] == 0) {
      local_50 = L"Params";
      local_58 = 0xe000c;
      local_90 = 0;
      NdisOpenConfigurationKeyByName(local_res18,local_88,local_70 + 3,&local_90);
      if (local_res18[0] == 0) {
        bVar1 = false;
        iVar3 = 0;
        do {
          local_40 = L"type";
          local_80[0] = 0;
          local_80[1] = 0;
          local_80[2] = 0;
          local_80[3] = 0;
          local_98 = 0;
          local_48 = 0xa0008;
          local_70[0] = 0;
          local_80[4] = 0;
          local_80[5] = 0;
          local_80[6] = 0;
          local_80[7] = 0;
          NdisOpenConfigurationKeyByIndex(local_res18,local_90,iVar3,local_80,&local_98);
          if (local_res18[0] != 0) {
            local_res18[0] = 0;
            break;
          }
          NdisReadConfiguration(local_res18,local_70,local_98,local_70 + 5,2);
          if (local_res18[0] == 0) {
            local_res18[0] = SendConfiguredParameter(param_1,local_res20,local_80,local_70[0] + 8);
            if (local_res18[0] == 0) {
              local_38 = 0x1e001c;
              local_30 = L"NetworkAddress";
              cVar2 = RtlEqualUnicodeString(local_80,local_70 + 7,1);
              if (cVar2 != '\0') {
                *(uint *)(param_1 + 0x570) = *(uint *)(param_1 + 0x570) | 0x80;
              }
            }
            else {
              bVar1 = true;
            }
          }
          NdisCloseConfiguration(local_98);
          iVar3 = iVar3 + 1;
        } while (!bVar1);
        NdisCloseConfiguration(local_90);
      }
      NdisCloseConfiguration(local_88);
    }
    NdisCloseConfiguration(local_res20);
  }
  return local_res18[0];
}



===== ResetCompletionMessage @ 180001760 =====

undefined8
ResetCompletionMessage(longlong *param_1,longlong param_2,undefined8 param_3,uint param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
  uVar1 = Feature_2112250168__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar1 == 0) || (0xf < param_4)) {
    uVar4 = *(undefined1 *)(param_2 + 0xc);
    uVar3 = *(undefined4 *)(param_2 + 8);
  }
  else {
    uVar4 = 0;
    uVar3 = 0xc0000001;
  }
  uVar2 = CompleteMiniportReset(param_1,uVar3,uVar4);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== RndisMInitializeWrapper @ 1800017c0 =====

int RndisMInitializeWrapper
              (longlong *param_1,longlong param_2,longlong param_3,undefined8 param_4,
              undefined4 *param_5)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  longlong *local_108;
  longlong local_100;
  undefined1 local_f8;
  undefined1 local_f7;
  code *local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  code *local_d8;
  undefined8 local_d0;
  code *local_c8;
  undefined8 local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  undefined8 local_a0;
  code *local_98;
  undefined8 local_90;
  code *local_88;
  code *local_80;
  code *local_38;
  code *local_30;
  
                    /* 0x17c0  4  RndisMInitializeWrapper */
  local_108 = (longlong *)0x0;
  local_100 = 0;
  iVar2 = MemAlloc(&local_108,0x88);
  if (iVar2 == 0) {
    NdisInitializeWrapper(&local_100,param_3,param_4,0);
    lVar3 = local_100;
    if (local_100 == 0) {
      NdisFreeMemory(local_108,0x88,0);
      iVar2 = -0x3fffffff;
    }
    else {
      *local_108 = local_100;
      local_108[0xf] = 0;
      local_108[3] = param_3;
      *(undefined4 *)((longlong)local_108 + 0x84) = 0x47534c42;
      *(undefined4 *)(local_108 + 5) = *param_5;
      local_108[6] = *(longlong *)(param_5 + 2);
      local_108[7] = *(longlong *)(param_5 + 4);
      local_108[8] = *(longlong *)(param_5 + 6);
      local_108[9] = *(longlong *)(param_5 + 8);
      local_108[10] = *(longlong *)(param_5 + 10);
      local_108[0xb] = *(longlong *)(param_5 + 0xc);
      local_108[0xc] = *(longlong *)(param_5 + 0xe);
      local_108[0xd] = *(longlong *)(param_5 + 0x10);
      local_108[0xe] = param_2;
      *param_1 = local_100;
      memset(&local_f8,0,0xf0);
      local_e8 = 0;
      local_e0 = 0;
      puVar6 = &DAT_18000a011;
      local_d0 = 0;
      local_c0 = 0;
      local_a0 = 0;
      local_90 = 0;
      local_d8 = RndismpHalt;
      uVar5 = 0;
      local_c8 = RndismpInitialize;
      local_b8 = RndismpQueryInformation;
      local_b0 = RndismpReconfigure;
      local_a8 = RndismpReset;
      local_80 = RndismpMultipleSend;
      local_98 = RndismpSetInformation;
      local_88 = RndismpReturnPacket;
      local_f0 = RndismpCheckForHang;
      local_38 = RndismpPnPEventNotify;
      local_30 = _guard_check_icall;
      while( true ) {
        local_f8 = puVar6[-1];
        local_f7 = *puVar6;
        iVar2 = NdisMRegisterMiniport(lVar3,&local_f8,*(undefined4 *)(puVar6 + 3));
        if (iVar2 == 0) break;
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
        puVar6 = puVar6 + 8;
        if (1 < uVar4) {
          NdisTerminateWrapper(local_100,0);
          iVar2 = -0x3fffffff;
          NdisFreeMemory(local_108,0x88,0);
          goto LAB_180001b09;
        }
        lVar3 = local_100;
      }
      *(undefined1 *)(local_108 + 1) = (&RndismpNdisVersionTable)[uVar5 * 8];
      *(undefined1 *)((longlong)local_108 + 9) = (&DAT_18000a011)[uVar5 * 8];
      wil_InitializeFeatureStaging();
      plVar1 = local_108;
      if (RndismpNumMicroports == 0) {
        KeInitializeSpinLock(&RndismpGlobalLock);
      }
      DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
      RndismpNumMicroports = RndismpNumMicroports + 1;
      plVar1[2] = (longlong)DAT_18000a120;
      DAT_18000a120 = plVar1;
      KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
      if ((*(byte *)(local_108 + 1) < 5) ||
         ((*(byte *)(local_108 + 1) == 5 && (*(char *)((longlong)local_108 + 9) == '\0')))) {
        local_108[4] = *(longlong *)(local_108[3] + 0x148);
        *(code **)(local_108[3] + 0x148) = PnPDispatch;
      }
      NdisMRegisterUnloadHandler(local_100,RndismpUnload);
      iVar2 = 0;
    }
  }
LAB_180001b09:
  return iVar2;
}



===== RndisMSendComplete @ 180001b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndisMSendComplete(longlong param_1,longlong param_2,int param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  int iVar7;
  
                    /* 0x1b30  5  RndisMSendComplete */
  if ((param_3 != 0) && (param_3 != -0x3fffff66)) {
    LOCK();
    *(int *)(param_1 + 0x558) = *(int *)(param_1 + 0x558) + 1;
    UNLOCK();
  }
  lVar2 = param_1 + 0x428;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
  *(undefined1 *)(param_1 + 0x430) = uVar6;
  plVar1 = (longlong *)(param_2 + 0x48);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) != plVar1) ||
     (plVar4 = *(longlong **)(param_2 + 0x50), (longlong *)*plVar4 != plVar1)) {
LAB_180001c7b:
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  if (param_3 == -0x3fffff66) {
    LOCK();
    *(int *)(param_1 + 0x53c) = *(int *)(param_1 + 0x53c) + 1;
    UNLOCK();
    if (1 < *(uint *)(param_1 + 0x40)) {
      plVar4 = (longlong *)(param_1 + 0x48);
      lVar3 = *plVar4;
      if (*(longlong **)(lVar3 + 8) != plVar4) goto LAB_180001c7b;
      *plVar1 = lVar3;
      *(longlong **)(param_2 + 0x50) = plVar4;
      *(longlong **)(lVar3 + 8) = plVar1;
      *plVar4 = (longlong)plVar1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x40);
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x40) >> 1;
      KeReleaseSpinLock(lVar2,CONCAT71((int7)((ulonglong)plVar4 >> 8),
                                       *(undefined1 *)(param_1 + 0x430)));
      goto LAB_180001c57;
    }
  }
  if (*(int *)(param_1 + 0x40) == *(int *)(param_1 + 0x3c)) {
    KeReleaseSpinLock();
    QueueMessageToMicroport(param_1,(longlong *)0x0,'\0');
  }
  else {
    KeReleaseSpinLock(lVar2);
  }
  if (*(code **)(param_2 + 0x38) != (code *)0x0) {
    iVar7 = 0;
    if (param_3 != -0x3fffff66) {
      iVar7 = param_3;
    }
    (**(code **)(param_2 + 0x38))(param_2,iVar7);
  }
LAB_180001c57:
  DereferenceMsgFrame(param_2);
  return;
}



===== RndismpCheckForHang @ 180001c90 =====

char RndismpCheckForHang(longlong param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  char cVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
  *(undefined1 *)(param_1 + 0x68) = 1;
  *(undefined1 *)(param_1 + 0x430) = uVar2;
  if ((*(char *)(param_1 + 0x500) == '\0') || (cVar3 = '\x01', *(char *)(param_1 + 0x501) != '\0'))
  {
    cVar3 = '\0';
  }
  if ((*(char *)(param_1 + 0x58) == '\0') && (*(int *)(param_1 + 0x40) == 0)) {
    *(undefined4 *)(param_1 + 0x38) = 0xffff;
    *(undefined4 *)(param_1 + 0x3c) = 0xfff;
  }
  if (((cVar3 == '\0') && (*(char *)(param_1 + 0x501) == '\0')) &&
     (plVar1 = *(longlong **)(param_1 + 0x80), plVar1 != (longlong *)(param_1 + 0x80))) {
    if (*(uint *)(plVar1 + -1) < 5) {
      *(uint *)(plVar1 + -1) = *(uint *)(plVar1 + -1) + 1;
    }
    else {
      cVar3 = '\x01';
    }
  }
  if (RndisForceReset != 0) {
    RndisForceReset = 0;
    cVar3 = '\x01';
    *(undefined2 *)(param_1 + 0x500) = 1;
  }
  KeReleaseSpinLock(param_1 + 0x428,*(undefined1 *)(param_1 + 0x430));
  return cVar3;
}



===== RndismpHalt @ 180001d60 =====

void RndismpHalt(longlong param_1)

{
  RndismpInternalHalt(param_1,'\x01');
  return;
}



===== RndismpInitialize @ 180001d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RndismpInitialize(undefined8 param_1,uint *param_2,longlong param_3,uint param_4,
                     undefined8 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  code *pcVar14;
  longlong *plVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined1 *puVar19;
  char cVar20;
  undefined8 *in_R10;
  char cVar21;
  int iVar22;
  uint uVar23;
  undefined8 *puVar24;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined8 *local_80;
  char local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  puVar24 = (undefined8 *)0x0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  cVar20 = '\0';
  local_80 = (undefined8 *)0x0;
  uVar23 = 0;
  bVar3 = false;
  iVar10 = MemAlloc(&local_80,0x5c0);
  if (iVar10 == 0) {
    iVar10 = MemAlloc(local_80 + 0x7d,0x5c);
    uVar18 = uRam000000018000a028;
    if (iVar10 != 0) goto LAB_18000265c;
    puVar13 = (undefined8 *)local_80[0x7d];
    *puVar13 = _RndismpSupportedOids;
    puVar13[1] = uVar18;
    uVar18 = uRam000000018000a038;
    puVar13[2] = _DAT_18000a030;
    puVar13[3] = uVar18;
    uVar18 = uRam000000018000a048;
    puVar13[4] = _DAT_18000a040;
    puVar13[5] = uVar18;
    uVar18 = uRam000000018000a058;
    puVar13[6] = _DAT_18000a050;
    puVar13[7] = uVar18;
    uVar6 = uRam000000018000a06c;
    uVar5 = uRam000000018000a068;
    uVar4 = uRam000000018000a064;
    *(undefined4 *)(puVar13 + 8) = _DAT_18000a060;
    *(undefined4 *)((longlong)puVar13 + 0x44) = uVar4;
    *(undefined4 *)(puVar13 + 9) = uVar5;
    *(undefined4 *)((longlong)puVar13 + 0x4c) = uVar6;
    puVar13[10] = DAT_18000a070;
    *(undefined4 *)(puVar13 + 0xb) = DAT_18000a078;
    *(undefined4 *)(local_80 + 0x7e) = 0x17;
    *local_80 = param_5;
    puVar13 = local_80 + 0x83;
    local_80[0x84] = puVar13;
    *puVar13 = puVar13;
    *(undefined1 *)((longlong)local_80 + 0x503) = 1;
    *(undefined4 *)(local_80 + 0xae) = 0xd;
    *(undefined4 *)((longlong)local_80 + 0x204) = 1;
    *(undefined4 *)(local_80 + 7) = 0xffff;
    *(undefined4 *)((longlong)local_80 + 0x3c) = 0xfff;
    *(undefined4 *)(local_80 + 8) = 0;
    *(undefined1 *)(local_80 + 0xb) = 0;
    puVar13 = local_80 + 9;
    local_80[10] = puVar13;
    *puVar13 = puVar13;
    puVar13 = local_80 + 0x10;
    local_80[0x11] = puVar13;
    *puVar13 = puVar13;
    puVar13 = local_80 + 0xe;
    local_80[0xf] = puVar13;
    *puVar13 = puVar13;
    *(undefined1 *)((longlong)local_80 + 0x2c1) = 0;
    puVar13 = local_80 + 0x59;
    local_80[0x5a] = puVar13;
    *puVar13 = puVar13;
    NdisMInitializeTimer(local_80 + 0x5b,param_5,IndicateTimeout);
    *(undefined1 *)(local_80 + 0x12) = 0;
    puVar13 = local_80 + 0x13;
    local_80[0x14] = puVar13;
    *puVar13 = puVar13;
    NdisMInitializeTimer(local_80 + 0x15,param_5,SendProcessTimeout);
    NdisInitializeEvent(local_80 + 0x9c);
    KeInitializeSpinLock(local_80 + 0x85);
    NdisMGetDeviceProperty(param_5,&local_70,&local_68,&local_60);
    local_80[0xac] = local_68;
    local_80[0xad] = local_70;
    uVar18 = local_70;
    GetDeviceFriendlyName(local_70,local_80 + 3,local_80 + 5);
    lVar11 = DeviceObjectToDriverBlock(uVar18,local_68);
    puVar19 = auStackY_c8;
    if (lVar11 == 0) {
      iVar10 = -0x3ffefffa;
      cVar21 = '\0';
      cVar20 = '\0';
      bVar3 = false;
    }
    else {
      local_80[2] = lVar11;
      *(undefined4 *)((longlong)local_80 + 0x584) = 0x47534441;
      *(undefined4 *)(local_80 + 0x6f) = *(undefined4 *)(lVar11 + 0x28);
      local_80[0x70] = *(undefined8 *)(lVar11 + 0x30);
      local_80[0x71] = *(undefined8 *)(lVar11 + 0x38);
      local_80[0x72] = *(undefined8 *)(lVar11 + 0x40);
      local_80[0x73] = *(undefined8 *)(lVar11 + 0x48);
      local_80[0x74] = *(undefined8 *)(lVar11 + 0x58);
      local_80[0x75] = *(undefined8 *)(lVar11 + 0x60);
      local_80[0x76] = *(undefined8 *)(lVar11 + 0x68);
      iVar10 = (*(code *)local_80[0x70])(local_80 + 0x78,local_80 + 0x81);
      if (iVar10 != 0) goto LAB_18000265c;
      bVar3 = true;
      iVar10 = AllocateTransportResources((longlong)local_80);
      if (((iVar10 == 0) && (iVar10 = MemAlloc(local_80 + 0xa5,0x2c), iVar10 == 0)) &&
         (plVar12 = BuildRndisMessageCommon((longlong)local_80,2,0,(undefined4 *)0x0,0),
         plVar12 != (longlong *)0x0)) {
        iVar22 = *(int *)((longlong)plVar12 + 0x34);
        puVar13 = (undefined8 *)AllocateRequestContext();
        if (puVar13 != (undefined8 *)0x0) {
          *puVar13 = 0;
          NdisInitializeEvent(&local_58);
          puVar13[9] = &local_58;
          plVar12[4] = (longlong)puVar13;
          LOCK();
          *(int *)(plVar12 + 2) = (int)plVar12[2] + 1;
          UNLOCK();
          plVar12[7] = (longlong)CompleteSendInit;
          QueueMessageToMicroport((longlong)local_80,plVar12,'\x01');
          local_78 = NdisWaitEvent(&local_58,5000);
          uVar8 = KeAcquireSpinLockRaiseToDpc(local_80 + 0x85);
          *(undefined1 *)(local_80 + 0x86) = uVar8;
          puVar1 = (undefined8 *)local_80[0x83];
          do {
            puVar2 = puVar1;
            if (puVar2 == local_80 + 0x83) goto LAB_180002230;
            puVar1 = (undefined8 *)*puVar2;
          } while (*(int *)((longlong)puVar2 + 0x34) != iVar22);
          if (((undefined8 *)puVar1[1] == puVar2) &&
             (puVar24 = (undefined8 *)puVar2[1], (undefined8 *)*puVar24 == puVar2)) {
            *puVar24 = puVar1;
            puVar1[1] = puVar24;
            puVar24 = puVar2;
            if ((undefined8 *)local_80[0xc] == puVar2) {
              local_80[0xc] = 0;
            }
LAB_180002230:
            KeReleaseSpinLock(local_80 + 0x85,*(undefined1 *)(local_80 + 0x86));
            DereferenceMsgFrame((longlong)plVar12);
            puVar19 = auStackY_c8;
            in_R10 = local_80;
            if (local_78 == '\0') {
              iVar10 = -0x3ffefff8;
            }
            else {
              lVar11 = local_80[0xa5];
              iVar10 = *(int *)(lVar11 + 4);
              if (iVar10 == 0) {
                if (((*(uint *)(lVar11 + 0x10) & 5) == 0) || (*(int *)(lVar11 + 0x14) != 0)) {
                  iVar10 = -0x3fffff45;
                }
                else {
                  if (((*(uint *)(lVar11 + 0x10) & 4) != 0) ||
                     (pcVar14 = DoMultipleSend, gRawEncap != 0)) {
                    pcVar14 = DoMultipleSendRaw;
                  }
                  local_80[0x77] = pcVar14;
                  iVar22 = 1;
                  cVar21 = '\x01';
                  *(undefined4 *)(local_80 + 0x7f) = *(undefined4 *)(lVar11 + 0x14);
                  *(undefined4 *)(local_80 + 0x80) = *(undefined4 *)(lVar11 + 0x18);
                  if (*(int *)(local_80 + 0x80) == 0) {
                    *(undefined4 *)(local_80 + 0x80) = 1;
                  }
                  *(bool *)((longlong)local_80 + 0x404) = 1 < *(uint *)(local_80 + 0x80);
                  *(undefined4 *)((longlong)local_80 + 0x40c) = *(undefined4 *)(lVar11 + 0x1c);
                  uVar17 = *(uint *)(lVar11 + 0x20);
                  if (7 < uVar17) {
                    uVar17 = 7;
                  }
                  iVar10 = 1 << ((byte)uVar17 & 0x1f);
                  uVar16 = 0;
                  *(int *)(local_80 + 0x82) = iVar10;
                  *(int *)((longlong)local_80 + 0x414) = -iVar10;
                  if (param_4 != 0) {
                    do {
                      if (*(int *)(param_3 + uVar16 * 4) == *(int *)(local_80 + 0x7f)) break;
                      uVar17 = (int)uVar16 + 1;
                      uVar16 = (ulonglong)uVar17;
                    } while (uVar17 < param_4);
                  }
                  if ((uint)uVar16 != param_4) {
                    *param_2 = (uint)uVar16;
                    *(undefined4 *)((longlong)local_80 + 0x3fc) = *(undefined4 *)(lVar11 + 0x10);
                    NdisMSetAttributesEx(*local_80,local_80,4);
                    if (((code *)local_80[0x71] == (code *)0x0) ||
                       (iVar10 = (*(code *)local_80[0x71])
                                           (local_80[0x78],
                                            *(undefined4 *)((longlong)local_80 + 0x3fc),
                                            (longlong)local_80 + 0x40c), iVar10 == 0)) {
                      plVar15 = BuildRndisMessageCommon
                                          ((longlong)local_80,4,0x10101,(undefined4 *)0x0,0);
                      puVar1 = local_80;
                      if (plVar15 != (longlong *)0x0) {
                        LOCK();
                        *(int *)(plVar15 + 2) = (int)plVar15[2] + 1;
                        UNLOCK();
                        lVar11 = local_80[2];
                        DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
                        puVar1[1] = *(undefined8 *)(lVar11 + 0x78);
                        *(int *)(lVar11 + 0x80) = *(int *)(lVar11 + 0x80) + 1;
                        *(undefined8 **)(lVar11 + 0x78) = puVar1;
                        KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
                        *puVar13 = 0;
                        *(undefined4 *)((longlong)puVar13 + 0x3c) = 0;
                        *(undefined4 *)(puVar13 + 1) = 0x10101;
                        *(undefined1 *)(puVar13 + 7) = 1;
                        NdisInitializeEvent(&local_58);
                        puVar13[9] = &local_58;
                        iVar10 = *(int *)((longlong)plVar15 + 0x34);
                        plVar15[4] = (longlong)puVar13;
                        puVar13 = (undefined8 *)0x0;
                        do {
                          puVar19 = auStackY_c8;
                          plVar15[7] = 0;
                          QueueMessageToMicroport((longlong)local_80,plVar15,'\x01');
                          bVar9 = NdisWaitEvent(&local_58,5000);
                          plVar12 = (longlong *)(ulonglong)bVar9;
                          uVar8 = KeAcquireSpinLockRaiseToDpc(local_80 + 0x85);
                          *(undefined1 *)(local_80 + 0x86) = uVar8;
                          puVar24 = (undefined8 *)local_80[0x83];
                          do {
                            puVar1 = puVar24;
                            puVar24 = (undefined8 *)0x0;
                            if (puVar1 == local_80 + 0x83) goto LAB_180002525;
                            puVar24 = (undefined8 *)*puVar1;
                          } while (*(int *)((longlong)puVar1 + 0x34) != iVar10);
                          if (((undefined8 *)puVar24[1] != puVar1) ||
                             (puVar2 = (undefined8 *)puVar1[1], (undefined8 *)*puVar2 != puVar1))
                          goto LAB_180002575;
                          *puVar2 = puVar24;
                          puVar24[1] = puVar2;
                          puVar24 = puVar1;
                          if ((undefined8 *)local_80[0xc] == puVar1) {
                            local_80[0xc] = 0;
                          }
LAB_180002525:
                          KeReleaseSpinLock(local_80 + 0x85,*(undefined1 *)(local_80 + 0x86));
                        } while ((bVar9 == 0) && (uVar23 = uVar23 + 1, uVar23 < 2));
                        DereferenceMsgFrame((longlong)plVar15);
                        in_R10 = local_80;
                        cVar20 = '\x01';
                        if (puVar24 == (undefined8 *)0x0) goto LAB_18000257c;
                        puVar19 = auStackY_c8;
                        cVar7 = '\x01';
                        if (bVar9 != 0) goto LAB_180002583;
                        cVar20 = '\x01';
                        puVar19 = auStackY_c8;
                        goto LAB_180002567;
                      }
                      goto LAB_180002154;
                    }
                    goto LAB_180002159;
                  }
                  iVar10 = -0x3ffeffe7;
                }
              }
            }
            cVar21 = '\0';
            goto LAB_180002667;
          }
LAB_180002575:
          bVar9 = (byte)plVar12;
          puVar24 = (undefined8 *)0x0;
          pcVar14 = (code *)swi(0x29);
          (*pcVar14)(3);
          puVar19 = auStackY_c0;
          cVar20 = (char)iVar22;
LAB_18000257c:
          cVar21 = cVar20;
          cVar20 = (char)puVar13;
          cVar7 = cVar21;
          if (bVar9 != 0) {
LAB_180002583:
            cVar21 = cVar7;
            cVar20 = (char)puVar13;
            if ((undefined8 *)in_R10[0x7d] != puVar13) {
              uVar16 = (ulonglong)puVar13 & 0xffffffff;
              if (*(uint *)((longlong)in_R10 + 0x3f4) != 0) {
                do {
                  if (*(int *)(in_R10[0x79] + uVar16 * 4) == 0x1021b) {
                    if (*(int *)(in_R10[0x7b] + uVar16 * 4) == 2) {
                      *(undefined8 *)(puVar19 + -8) = 0x1800025d0;
                      iVar10 = ReadAndSetRegistryParameters((longlong)in_R10,param_6);
                      if (iVar10 != 0) goto LAB_180002663;
                      in_R10 = local_80;
                    }
                    break;
                  }
                  uVar23 = (int)uVar16 + 1;
                  uVar16 = (ulonglong)uVar23;
                } while (uVar23 < *(uint *)((longlong)in_R10 + 0x3f4));
              }
              uVar18 = *in_R10;
              *(undefined8 *)(puVar19 + -8) = 0x1800025f2;
              NdisMRegisterAdapterShutdownHandler(uVar18,in_R10,_guard_check_icall);
              *(char *)(local_80 + 0x9b) = cVar20;
              *(char *)((longlong)local_80 + 0x503) = cVar20;
              *(undefined8 *)(puVar19 + -8) = 0x18000262a;
              NdisMInitializeTimer(local_80 + 0x87,param_5,KeepAliveTimerHandler);
              *(undefined8 *)(puVar19 + -8) = 0x180002646;
              NdisSetTimer(local_80 + 0x87,0x9c4);
              iVar10 = (int)puVar13;
              goto LAB_180002663;
            }
          }
LAB_180002567:
          iVar10 = -0x3ffefff8;
          goto LAB_180002667;
        }
LAB_180002154:
        iVar10 = -0x3fffff66;
LAB_180002159:
        puVar19 = auStackY_c8;
        cVar21 = '\0';
        cVar20 = '\0';
      }
      else {
        puVar19 = auStackY_c8;
        iVar10 = -0x3fffff66;
        cVar21 = '\0';
        cVar20 = '\0';
        bVar3 = true;
      }
    }
  }
  else {
LAB_18000265c:
    puVar19 = auStackY_c8;
    cVar21 = '\0';
    cVar20 = '\0';
  }
LAB_180002663:
  in_R10 = local_80;
LAB_180002667:
  if (in_R10 != (undefined8 *)0x0) {
    lVar11 = in_R10[0xa5];
    if (lVar11 != 0) {
      *(undefined8 *)(puVar19 + -8) = 0x180002686;
      NdisFreeMemory(lVar11,0x2c);
      in_R10 = local_80;
    }
  }
  if (iVar10 != 0) {
    if (bVar3) {
      pcVar14 = (code *)in_R10[0x72];
      uVar18 = in_R10[0x78];
      *(undefined8 *)(puVar19 + -8) = 0x1800026ab;
      (*pcVar14)(uVar18);
      in_R10 = local_80;
    }
    if (cVar20 != '\0') {
      iVar22 = *(int *)(in_R10 + 8);
      while (iVar22 != 0) {
        *(undefined8 *)(puVar19 + -8) = 0x1800026c7;
        NdisMSleep(200);
        iVar22 = *(int *)(local_80 + 8);
      }
      *(undefined8 *)(puVar19 + -8) = 0x1800026de;
      DereferenceMsgFrame((longlong)puVar24);
      in_R10 = local_80;
    }
    if (in_R10 != (undefined8 *)0x0) {
      if (cVar21 != '\0') {
        *(undefined8 *)(puVar19 + -8) = 0x1800026f4;
        RemoveAdapter((longlong)in_R10);
        in_R10 = local_80;
      }
      *(undefined8 *)(puVar19 + -8) = 0x180002700;
      FreeAdapter((longlong)in_R10);
    }
  }
  return iVar10;
}



===== RndismpInternalHalt @ 180002724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndismpInternalHalt(longlong param_1,char param_2)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  longlong *plVar4;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  FlushPendingMessages(param_1);
  if (*(char *)(param_1 + 0x504) == '\0') {
    plVar4 = BuildRndisMessageCommon(param_1,3,0,(undefined4 *)0x0,0);
    if (plVar4 != (longlong *)0x0) {
      uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
      *(undefined1 *)(param_1 + 0x504) = 1;
      *(undefined1 *)(param_1 + 0x430) = uVar2;
      NdisInitializeEvent(param_1 + 0x508);
      KeReleaseSpinLock(param_1 + 0x428,*(undefined1 *)(param_1 + 0x430));
      plVar4[7] = (longlong)CompleteSendHalt;
      QueueMessageToMicroport(param_1,plVar4,'\0');
      NdisWaitEvent(param_1 + 0x508,2000);
    }
    iVar3 = NdisPacketPoolUsage(*(undefined8 *)(param_1 + 0x208));
    while (iVar3 != 0) {
      NdisMSleep(200);
      iVar3 = NdisPacketPoolUsage(*(undefined8 *)(param_1 + 0x208));
    }
    iVar3 = *(int *)(param_1 + 0x40);
    uVar1 = 0;
    while (iVar3 != 0) {
      NdisMSleep(200);
      if (0x1e < uVar1) break;
      uVar1 = uVar1 + 1;
      iVar3 = *(int *)(param_1 + 0x40);
    }
    *(undefined1 *)(param_1 + 0x4d8) = 1;
    NdisMCancelTimer(param_1 + 0x438,local_res10);
    if (local_res10[0] == '\0') {
      NdisWaitEvent(param_1 + 0x4e0,0);
    }
    (**(code **)(param_1 + 0x390))(*(undefined8 *)(param_1 + 0x3c0));
  }
  if (param_2 != '\0') {
    FreeOIDLists(param_1);
    RemoveAdapter(param_1);
    FreeAdapter(param_1);
  }
  return;
}



===== RndismpPnPEventNotify @ 1800028e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndismpPnPEventNotify(longlong *param_1,int param_2)

{
  if (param_2 == 2) {
    *(undefined1 *)((longlong)param_1 + 0x505) = 1;
    (*(code *)param_1[0x76])(param_1[0x78],1);
    CompletePendingRequests(param_1);
  }
  return;
}



===== RndismpReconfigure @ 180002930 =====

undefined8 RndismpReconfigure(undefined4 *param_1,longlong param_2)

{
  RndismpInternalHalt(param_2,'\0');
  *param_1 = 0;
  return 0;
}



===== RndismpReset @ 180002960 =====

undefined8 RndismpReset(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong *plVar3;
  
  *(undefined1 *)((longlong)param_2 + 0x501) = 1;
  FlushPendingMessages((longlong)param_2);
  plVar3 = BuildRndisMessageCommon((longlong)param_2,6,0,(undefined4 *)0x0,0);
  if (plVar3 == (longlong *)0x0) {
    CompleteMiniportReset(param_2,0xc000009a,0);
  }
  else {
    plVar1 = param_2 + 0x85;
    uVar2 = KeAcquireSpinLockRaiseToDpc(plVar1);
    *(undefined1 *)(param_2 + 0xa0) = 0;
    *(undefined1 *)(param_2 + 0x86) = uVar2;
    *(undefined4 *)(param_2 + 7) = 0x10000;
    KeReleaseSpinLock(plVar1,uVar2);
    plVar3[7] = (longlong)CompleteSendReset;
    QueueMessageToMicroport((longlong)param_2,plVar3,'\0');
    uVar2 = KeAcquireSpinLockRaiseToDpc(plVar1);
    *(int *)(param_2 + 7) = (int)param_2[7] + -1;
    *(undefined1 *)(param_2 + 0x86) = uVar2;
    KeReleaseSpinLock(plVar1,uVar2);
  }
  return 0x103;
}



===== _guard_check_icall @ 180002a50 =====

void _guard_check_icall(void)

{
  return;
}



===== RndismpUnload @ 180002a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndismpUnload(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined *puVar3;
  
  DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
  lVar2 = DAT_18000a120;
  do {
    if (*(longlong *)(lVar2 + 0x18) == param_1) break;
    lVar2 = *(longlong *)(lVar2 + 0x10);
  } while (lVar2 != 0);
  KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
  if (lVar2 != 0) {
    if (*(code **)(lVar2 + 0x50) != (code *)0x0) {
      (**(code **)(lVar2 + 0x50))(*(undefined8 *)(lVar2 + 0x70));
    }
    puVar3 = &RndismpMiniportBlockListHead;
    DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
    lVar1 = DAT_18000a120;
    while (lVar1 != lVar2) {
      puVar3 = *(undefined **)(puVar3 + 0x10);
      if (puVar3 == (undefined *)0x0) goto LAB_180002b16;
      lVar1 = *(longlong *)(puVar3 + 0x10);
    }
    *(undefined8 *)(puVar3 + 0x10) = *(undefined8 *)(*(longlong *)(puVar3 + 0x10) + 0x10);
LAB_180002b16:
    RndismpNumMicroports = RndismpNumMicroports + -1;
    KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
    NdisFreeMemory(lVar2,0x88,0);
  }
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



===== SendConfiguredParameter @ 180002ba8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SendConfiguredParameter(longlong param_1,undefined8 param_2,ushort *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined1 uVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  int *_Src;
  uint uVar12;
  undefined1 auStackY_168 [8];
  undefined1 auStackY_160 [24];
  int local_138 [2];
  uint *local_130;
  uint local_128;
  undefined4 local_120 [2];
  int *local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined4 local_e8 [2];
  wchar_t *local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  wchar_t *local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  wchar_t *local_98;
  undefined4 local_90;
  undefined4 local_88;
  wchar_t *local_80;
  undefined4 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_168;
  local_118 = (int *)0x0;
  local_f0 = 0;
  local_120[0] = 0;
  local_e0 = L"int";
  local_130 = (uint *)0x0;
  local_c8 = L"long";
  local_138[0] = 0;
  local_b0 = L"word";
  plVar7 = (longlong *)0x0;
  local_e8[0] = 0x80006;
  local_98 = L"dword";
  puVar8 = (undefined8 *)0x0;
  local_d8 = 0;
  local_80 = L"edit";
  uVar12 = 0;
  local_d0 = 0xa0008;
  local_128 = 2;
  uVar11 = 0;
  local_78 = 2;
  local_60 = 2;
  local_100 = 0;
  uStack_f8 = 0;
  local_c0 = 0;
  local_b8 = 0xa0008;
  local_a8 = 0;
  local_a0 = 0xc000a;
  local_90 = 0;
  local_88 = 0xa0008;
  local_70 = 0xa0008;
  local_68 = L"enum";
  local_110 = param_4;
  local_108 = param_2;
  do {
    cVar5 = RtlEqualUnicodeString(local_e8 + (ulonglong)uVar11 * 6,local_110,1);
    if (cVar5 != '\0') break;
    uVar11 = uVar11 + 1;
  } while (uVar11 < 6);
  if (uVar11 == 6) {
    local_138[0] = -0x3ffeffeb;
    puVar10 = auStackY_168;
    goto LAB_180002f09;
  }
  NdisReadConfiguration(local_138,&local_118,local_108,param_3);
  puVar10 = auStackY_168;
  if ((local_138[0] == 0) && (puVar10 = auStackY_168, local_118 != (int *)0x0)) {
    if (*local_118 == 0) {
      local_128 = 0;
      uVar11 = 4;
      _Src = local_118 + 2;
    }
    else {
      puVar10 = auStackY_168;
      if (*local_118 != 2) goto LAB_180002f05;
      uVar11 = (uint)*(ushort *)(local_118 + 2);
      _Src = *(int **)(local_118 + 4);
    }
    uVar12 = *param_3 + 0x14 + uVar11;
    local_138[0] = MemAlloc(&local_130,(ulonglong)uVar12);
    puVar10 = auStackY_168;
    if (local_138[0] != 0) goto LAB_180002f09;
    *local_130 = 0x14;
    local_130[1] = (uint)*param_3;
    local_130[2] = local_128;
    local_130[3] = local_130[1] + *local_130;
    local_130[4] = uVar11;
    memmove((void *)((ulonglong)*local_130 + (longlong)local_130),*(void **)(param_3 + 4),
            (ulonglong)*param_3);
    memmove((void *)((ulonglong)local_130[3] + (longlong)local_130),_Src,(ulonglong)uVar11);
    plVar7 = BuildRndisMessageCommon(param_1,5,0x1021b,local_130,uVar12);
    if ((plVar7 == (longlong *)0x0) ||
       (puVar8 = (undefined8 *)AllocateRequestContext(), puVar8 == (undefined8 *)0x0)) {
      local_138[0] = -0x3fffff66;
      puVar10 = auStackY_168;
      goto LAB_180002f09;
    }
    *puVar8 = 0;
    *(undefined4 *)(puVar8 + 1) = 0x1021b;
    NdisInitializeEvent(&local_100);
    *(undefined1 *)(puVar8 + 7) = 1;
    puVar8[9] = &local_100;
    *(uint *)(puVar8 + 3) = uVar12;
    puVar8[4] = local_120;
    iVar1 = *(int *)((longlong)plVar7 + 0x34);
    plVar7[7] = 0;
    plVar7[4] = (longlong)puVar8;
    QueueMessageToMicroport(param_1,plVar7,'\x01');
    cVar5 = NdisWaitEvent(&local_100,5000);
    uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
    puVar9 = (undefined8 *)(param_1 + 0x418);
    *(undefined1 *)(param_1 + 0x430) = uVar6;
    puVar2 = (undefined8 *)*puVar9;
    do {
      puVar4 = puVar2;
      if (puVar4 == puVar9) goto LAB_180002eb3;
      puVar2 = (undefined8 *)*puVar4;
    } while (*(int *)((longlong)puVar4 + 0x34) != iVar1);
    if (((undefined8 *)puVar2[1] == puVar4) &&
       (puVar9 = (undefined8 *)puVar4[1], (undefined8 *)*puVar9 == puVar4)) {
      *puVar9 = puVar2;
      puVar2[1] = puVar9;
      if (*(undefined8 **)(param_1 + 0x60) == puVar4) {
        *(undefined8 *)(param_1 + 0x60) = 0;
      }
LAB_180002eb3:
      KeReleaseSpinLock(param_1 + 0x428,
                        CONCAT71((int7)((ulonglong)puVar9 >> 8),*(undefined1 *)(param_1 + 0x430)));
      local_138[0] = -0x3ffefff8;
      if (cVar5 != '\0') {
        local_138[0] = *(int *)((longlong)puVar8 + 0x3c);
      }
      puVar10 = auStackY_168;
      goto LAB_180002f09;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar10 = auStackY_160;
  }
LAB_180002f05:
  *(uint *)(puVar10 + 0x30) = *(uint *)(puVar10 + 0x30) & (uint)puVar8;
LAB_180002f09:
  if (*(longlong *)(puVar10 + 0x38) != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x180002f20;
    NdisFreeMemory(*(longlong *)(puVar10 + 0x38),uVar12,0);
  }
  if (plVar7 != (longlong *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x180002f32;
    DereferenceMsgFrame((longlong)plVar7);
  }
  if (puVar8 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x180002f48;
    NdisFreeMemory(puVar8,1);
  }
  *(undefined8 *)(puVar10 + -8) = 0x180002f5d;
  return *(undefined4 *)(puVar10 + 0x30);
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 180002f78 =====

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
LAB_180003181:
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
LAB_180003053:
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
      if (param_3 == 4) goto LAB_180003181;
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
        goto LAB_180003053;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 18000326c =====

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
      goto LAB_18000333d;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_18000333d;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_18000333d;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_18000333d;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_18000333d;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_18000333d;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_18000333d;
    }
  }
  uVar3 = 0xff;
LAB_18000333d:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 180003394 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 180003484 =====

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
LAB_180003537:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_180003565;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_180003537;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_180003565:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1800036f0 =====

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



===== wil_details_IsEnabledFallback @ 180003754 =====

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



===== wil_details_RecordCachedUsage @ 1800037e8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 180003940 =====

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



===== AllocateTransportResources @ 1800039c4 =====

int AllocateTransportResources(longlong param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = NdisGetVersion();
  ExInitializeNPagedLookasideList
            (param_1 + 0x180,0,0,~-(uint)(uVar1 < 0x6001e) & 0x200,0x60,0x734d4e52,0);
  *(undefined1 *)(param_1 + 0x200) = 1;
  iVar2 = SetupReceiveQueues(param_1);
  if ((iVar2 != 0) && (*(char *)(param_1 + 0x200) != '\0')) {
    ExDeleteNPagedLookasideList(param_1 + 0x180);
    *(undefined1 *)(param_1 + 0x200) = 0;
  }
  return iVar2;
}



===== FreeReceiveResources @ 180003a80 =====

void FreeReceiveResources(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x210) != 0) {
    NdisFreeBufferPool();
    *(undefined8 *)(param_1 + 0x210) = 0;
  }
  if (*(longlong *)(param_1 + 0x208) != 0) {
    NdisFreePacketPool();
    *(undefined8 *)(param_1 + 0x208) = 0;
  }
  if (*(char *)(param_1 + 0x2c0) != '\0') {
    ExDeleteNPagedLookasideList(param_1 + 0x240);
    *(undefined1 *)(param_1 + 0x2c0) = 0;
  }
  return;
}



===== SetupReceiveQueues @ 180003afc =====

int SetupReceiveQueues(longlong param_1)

{
  uint uVar1;
  int local_res8 [2];
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x218) = 0x14;
  local_res8[0] = 0;
  *(undefined4 *)(param_1 + 0x21c) = 400;
  uVar1 = NdisGetVersion();
  uVar2 = 0;
  ExInitializeNPagedLookasideList
            (param_1 + 0x240,0,0,~-(uint)(uVar1 < 0x6001e) & 0x200,0x18,0x724d4e52,0);
  *(undefined1 *)(param_1 + 0x2c0) = 1;
  NdisAllocatePacketPoolEx
            (local_res8,param_1 + 0x208,*(undefined4 *)(param_1 + 0x218),
             *(undefined4 *)(param_1 + 0x21c),CONCAT44(uVar2,0x20));
  if ((local_res8[0] == 0) &&
     (NdisAllocateBufferPool(local_res8,param_1 + 0x210,*(undefined4 *)(param_1 + 0x21c)),
     local_res8[0] == 0)) {
    return 0;
  }
  FreeReceiveResources(param_1);
  return local_res8[0];
}



===== DereferenceRcvFrame @ 180003bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DereferenceRcvFrame(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 2);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(char *)((longlong)param_1 + 0x14) == '\0') {
      (**(code **)(param_2 + 0x3a8))(*(undefined8 *)(param_2 + 0x3c0),param_1[1],*param_1);
    }
    else {
      NdisFreeMemory(param_1[1],1,0);
    }
    ExFreeToNPagedLookasideList(param_2 + 0x240,param_1);
  }
  return;
}



===== IndicateStatusMessage @ 180003c70 =====

ulonglong IndicateStatusMessage(undefined8 *param_1,int *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar1 = param_2[1];
  uVar4 = (ulonglong)uVar1;
  if (((uVar1 <= param_4) && (*param_2 == 7)) && (0x13 < uVar1)) {
    uVar2 = param_2[3];
    uVar1 = uVar2 + 8;
    uVar4 = (ulonglong)uVar1;
    if ((uVar2 <= uVar1) && (uVar1 <= param_4)) {
      uVar3 = param_2[4];
      if ((uVar3 <= uVar3 + uVar1) && (uVar3 + uVar1 <= param_4)) {
        if (*(char *)((longlong)param_1 + 0x503) == '\0') {
          NdisMIndicateStatus(*param_1,param_2[2],(longlong)(param_2 + 2) + (ulonglong)uVar3,uVar2);
          uVar4 = NdisMIndicateStatusComplete(*param_1);
        }
        return CONCAT71((int7)(uVar4 >> 8),1);
      }
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== IndicateTimeout @ 180003d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IndicateTimeout(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  int *piVar7;
  uint uVar8;
  undefined1 uVar9;
  char cVar10;
  code *pcVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined4 local_30;
  char local_28;
  
  _RcvTimerCount = _RcvTimerCount + 1;
  lVar1 = param_2 + 0x428;
  uVar13 = 0;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar12 = auStack_58;
  plVar2 = (longlong *)(param_2 + 0x2c8);
  do {
    *(undefined1 *)(param_2 + 0x430) = uVar9;
    plVar5 = (longlong *)*plVar2;
    if (plVar5 == plVar2) {
LAB_180003eb2:
      uVar8 = RcvMaxPackets;
      *(undefined1 *)(param_2 + 0x2c1) = 0;
      if (uVar8 <= uVar13) {
        RcvMaxPackets = uVar13;
      }
      *(undefined8 *)(puVar12 + -8) = 0x180003ed3;
      KeReleaseSpinLock(lVar1,uVar9);
      return;
    }
    if (((longlong *)plVar5[1] != plVar2) ||
       (lVar6 = *plVar5, (longlong *)*(longlong *)(lVar6 + 8) != plVar5)) {
      pcVar11 = (code *)swi(0x29);
      uVar9 = (*pcVar11)(3);
      puVar12 = auStack_50;
      goto LAB_180003eb2;
    }
    *plVar2 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar2;
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_2 + 0x430));
    piVar7 = (int *)plVar5[5];
    uVar13 = uVar13 + 1;
    iVar4 = *piVar7;
    if (iVar4 == 1) {
      pcVar11 = ReceivePacketMessage;
    }
    else if (iVar4 == 3) {
      pcVar11 = HaltMessage;
    }
    else if (iVar4 == 7) {
      pcVar11 = IndicateStatusMessage;
    }
    else if (iVar4 == 8) {
      pcVar11 = KeepAliveMessage;
    }
    else if (iVar4 == -0x7ffffffe) {
      pcVar11 = InitCompletionMessage;
    }
    else if (iVar4 + 0x7ffffffcU < 2) {
      pcVar11 = QuerySetCompletionMessage;
    }
    else if (iVar4 == -0x7ffffffa) {
      pcVar11 = ResetCompletionMessage;
    }
    else {
      pcVar11 = KeepAliveCompletionMessage;
      if (iVar4 != -0x7ffffff8) {
        pcVar11 = UnknownMessage;
      }
    }
    local_30 = *(undefined4 *)(plVar5 + 6);
    cVar3 = *(char *)((longlong)plVar5 + 0x34);
    local_38 = plVar5[2];
    local_28 = cVar3;
    cVar10 = (*pcVar11)(param_2,piVar7,plVar5[3],*(undefined4 *)(plVar5 + 4));
    if (cVar10 != '\0') {
      if (cVar3 == '\0') {
        (**(code **)(param_2 + 0x3a8))(*(undefined8 *)(param_2 + 0x3c0),plVar5[3],plVar5[2]);
      }
      else {
        NdisFreeMemory(piVar7,1);
      }
    }
    NdisFreeMemory(plVar5,0x40);
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  } while( true );
}



===== NdisQueryPacket @ 180003f00 =====

void NdisQueryPacket(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                    int *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = *(undefined8 *)(param_1 + 2);
  }
  if (param_5 != (int *)0x0) {
    if ((char)param_1[10] == '\0') {
      iVar5 = 0;
      iVar6 = 0;
      iVar3 = 0;
      for (puVar4 = *(undefined8 **)(param_1 + 2); puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        uVar1 = *(uint *)(puVar4 + 5);
        iVar5 = iVar5 + uVar1;
        if (uVar1 == 0) {
          iVar2 = 1;
        }
        else {
          iVar2 = (int)((ulonglong)uVar1 + 0xfff +
                        (ulonglong)
                        (*(int *)((longlong)puVar4 + 0x2c) + *(int *)(puVar4 + 4) & 0xfff) >> 0xc);
        }
        iVar6 = iVar6 + iVar2;
        iVar3 = iVar3 + 1;
      }
      param_1[8] = iVar3;
      param_1[1] = iVar5;
      *param_1 = iVar6;
      *(undefined1 *)(param_1 + 10) = 1;
    }
    *param_5 = param_1[1];
  }
  return;
}



===== ReceivePacketMessage @ 180003fa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
ReceivePacketMessage
          (longlong *param_1,int *param_2,int *param_3,uint param_4,undefined8 param_5,int param_6,
          char param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  int *piVar6;
  longlong *plVar7;
  uint uVar8;
  undefined1 uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined1 auStack_1d8 [32];
  int local_1b8;
  longlong local_1a8;
  int local_1a0;
  int local_19c;
  int local_198;
  undefined8 *local_190;
  longlong local_188 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1d8;
  memset(local_188,0,0x140);
  uVar9 = 0;
  local_1a8 = 0;
  local_190 = (undefined8 *)0x0;
  local_19c = 0;
  local_198 = 0;
  if (param_7 == '\0') {
    local_198 = param_6;
  }
  local_1a0 = 0;
  puVar5 = (undefined8 *)ExAllocateFromNPagedLookasideList(param_1 + 0x48);
  if (puVar5 == (undefined8 *)0x0) {
    uVar9 = 1;
  }
  else {
    *puVar5 = param_5;
    piVar6 = param_2;
    if (param_7 == '\0') {
      piVar6 = param_3;
    }
    uVar13 = 0;
    puVar5[1] = piVar6;
    *(bool *)((longlong)puVar5 + 0x14) = param_7 != '\0';
    *(undefined4 *)(puVar5 + 2) = 1;
    do {
      do {
        puVar10 = (uint *)(param_2 + 2);
        if (((((param_4 < (uint)param_2[1]) || (*param_2 != 1)) ||
             (uVar12 = param_2[1], uVar12 < 0x2c)) ||
            ((uVar12 < (uint)param_2[3] || (uVar4 = *puVar10 + 8, uVar4 < 8)))) ||
           ((uVar12 <= uVar4 || ((uVar8 = param_2[3] + uVar4, uVar8 < uVar4 || (uVar12 < uVar8))))))
        {
          plVar7 = (longlong *)((longlong)param_1 + 0x544);
LAB_180004282:
          LOCK();
          *(int *)plVar7 = (int)*plVar7 + 1;
          UNLOCK();
          if ((int)uVar13 != 0) {
            plVar7 = local_188;
            do {
              RndismpReturnPacket((longlong)param_1,*plVar7);
              plVar7 = plVar7 + 1;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          goto LAB_1800042a5;
        }
        NdisAllocatePacket(&local_1a0,&local_1a8,param_1[0x41]);
        if (local_1a0 != 0) {
          local_1a8 = 0;
LAB_1800042ef:
          plVar7 = param_1 + 0xa9;
          goto LAB_180004282;
        }
        *(int *)((ulonglong)*(ushort *)(local_1a8 + 0x2a) + 0x20 + local_1a8) = local_198;
        if ((int)param_1[0x7f] == 0) {
          *(undefined4 *)((ulonglong)*(ushort *)(local_1a8 + 0x2a) + 0x10 + local_1a8) = 0xe;
        }
        local_1b8 = param_2[3];
        NdisAllocateBuffer(&local_19c,&local_190,param_1[0x42],
                           (ulonglong)*puVar10 + (longlong)puVar10);
        if (local_19c != 0) {
          NdisFreePacket(local_1a8);
          goto LAB_1800042ef;
        }
        puVar3 = (undefined8 *)*local_190;
        puVar2 = local_190;
        while (puVar1 = puVar3, puVar1 != (undefined8 *)0x0) {
          puVar2 = puVar1;
          puVar3 = (undefined8 *)*puVar1;
        }
        if (*(longlong *)(local_1a8 + 8) == 0) {
          *(undefined8 **)(local_1a8 + 0x10) = puVar2;
        }
        *puVar2 = *(undefined8 *)(local_1a8 + 8);
        *(undefined8 **)(local_1a8 + 8) = local_190;
        *(undefined1 *)(local_1a8 + 0x28) = 0;
        iVar11 = param_2[8];
        if (iVar11 != 0) {
          puVar10 = (uint *)((ulonglong)(uint)param_2[7] + (longlong)puVar10);
          do {
            if (puVar10[1] == 0) {
              *(ulonglong *)((ulonglong)*(ushort *)(local_1a8 + 0x2a) + 0x28 + local_1a8) =
                   (ulonglong)*(uint *)((ulonglong)puVar10[2] + (longlong)puVar10);
            }
            else if (puVar10[1] == 6) {
              *(ulonglong *)((ulonglong)*(ushort *)(local_1a8 + 0x2a) + 0x58 + local_1a8) =
                   (ulonglong)*(uint *)((ulonglong)puVar10[2] + (longlong)puVar10);
            }
            uVar12 = *puVar10;
            puVar10 = (uint *)((longlong)puVar10 + (ulonglong)uVar12);
            iVar11 = iVar11 - uVar12;
          } while (iVar11 != 0);
        }
        local_188[uVar13] = local_1a8;
        uVar12 = (int)uVar13 + 1;
        uVar13 = (ulonglong)uVar12;
        LOCK();
        *(int *)(param_1 + 0xa8) = (int)param_1[0xa8] + 1;
        UNLOCK();
        *(undefined8 **)(local_1a8 + 0x30) = puVar5;
        param_4 = param_4 - param_2[1];
        param_2 = (int *)((longlong)param_2 + (ulonglong)(uint)param_2[1]);
        LOCK();
        *(int *)(puVar5 + 2) = *(int *)(puVar5 + 2) + 1;
        UNLOCK();
      } while ((uVar12 != 0x28) && (0x2b < param_4));
      _RcvIndicateCount = _RcvIndicateCount + uVar12;
      (**(code **)(*param_1 + 0x1b0))(*param_1,local_188,uVar13);
      if ((local_198 == -0x3fffff66) && (uVar12 != 0)) {
        plVar7 = local_188;
        do {
          LOCK();
          *(int *)((longlong)param_1 + 0x54c) = *(int *)((longlong)param_1 + 0x54c) + 1;
          UNLOCK();
          RndismpReturnPacket((longlong)param_1,*plVar7);
          plVar7 = plVar7 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      uVar13 = 0;
    } while (0x2b < param_4);
LAB_1800042a5:
    DereferenceRcvFrame(puVar5,(longlong)param_1);
  }
  return uVar9;
}



===== ReceivePacketMessageRaw @ 180004310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
ReceivePacketMessageRaw
          (longlong *param_1,longlong param_2,longlong param_3,uint param_4,undefined8 param_5,
          int param_6,char param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  undefined1 auStack_1e8 [32];
  uint local_1c8;
  longlong local_1b8;
  int local_1b0;
  int local_1ac;
  undefined8 *local_1a8;
  longlong local_1a0;
  longlong *local_198;
  longlong local_188;
  undefined1 local_180 [312];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_1a0 = param_3;
  memset(local_180,0,0x138);
  local_198 = param_1 + 0x48;
  local_1b8 = 0;
  iVar6 = 0;
  if (param_7 == '\0') {
    iVar6 = param_6;
  }
  local_1a8 = (undefined8 *)0x0;
  local_1ac = 0;
  local_1b0 = 0;
  puVar4 = (undefined8 *)ExAllocateFromNPagedLookasideList(local_198);
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = param_5;
    lVar5 = param_2;
    if (param_7 == '\0') {
      lVar5 = local_1a0;
    }
    puVar4[1] = lVar5;
    *(bool *)((longlong)puVar4 + 0x14) = param_7 != '\0';
    *(undefined4 *)(puVar4 + 2) = 1;
    NdisAllocatePacket(&local_1b0,&local_1b8,param_1[0x41]);
    if (local_1b0 == 0) {
      *(int *)((ulonglong)*(ushort *)(local_1b8 + 0x2a) + 0x20 + local_1b8) = iVar6;
      if ((int)param_1[0x7f] == 0) {
        *(undefined4 *)((ulonglong)*(ushort *)(local_1b8 + 0x2a) + 0x10 + local_1b8) = 0xe;
      }
      local_1c8 = param_4;
      NdisAllocateBuffer(&local_1ac,&local_1a8,param_1[0x42],param_2);
      if (local_1ac == 0) {
        puVar3 = (undefined8 *)*local_1a8;
        puVar2 = local_1a8;
        while (puVar1 = puVar3, puVar1 != (undefined8 *)0x0) {
          puVar2 = puVar1;
          puVar3 = (undefined8 *)*puVar1;
        }
        if (*(longlong *)(local_1b8 + 8) == 0) {
          *(undefined8 **)(local_1b8 + 0x10) = puVar2;
        }
        *puVar2 = *(undefined8 *)(local_1b8 + 8);
        *(undefined8 **)(local_1b8 + 8) = local_1a8;
        *(undefined1 *)(local_1b8 + 0x28) = 0;
        local_188 = local_1b8;
        *(undefined8 **)(local_1b8 + 0x30) = puVar4;
        if (*(uint *)(param_2 + 4) <= param_4) {
          LOCK();
          *(int *)(param_1 + 0xa8) = (int)param_1[0xa8] + 1;
          UNLOCK();
          LOCK();
          *(int *)(puVar4 + 2) = *(int *)(puVar4 + 2) + 1;
          UNLOCK();
          (**(code **)(*param_1 + 0x1b0))(*param_1,&local_188,1);
          if (iVar6 == -0x3fffff66) {
            LOCK();
            *(int *)((longlong)param_1 + 0x54c) = *(int *)((longlong)param_1 + 0x54c) + 1;
            UNLOCK();
            RndismpReturnPacket((longlong)param_1,local_188);
          }
          DereferenceRcvFrame(puVar4,(longlong)param_1);
          return 0;
        }
        NdisFreePacket(local_1b8);
        IoFreeMdl(local_1a8);
      }
      else {
        NdisFreePacket(local_1b8);
      }
    }
    else {
      local_1b8 = 0;
    }
    LOCK();
    *(int *)(param_1 + 0xa9) = (int)param_1[0xa9] + 1;
    UNLOCK();
    ExFreeToNPagedLookasideList(local_198,puVar4);
  }
  return 1;
}



===== RndisMIndicateReceive @ 180004590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndisMIndicateReceive
               (longlong param_1,longlong *param_2,undefined8 param_3,int param_4,undefined4 param_5
               )

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  int *piVar4;
  void *_Src;
  uint uVar5;
  code *pcVar6;
  char cVar7;
  uint local_res8;
  int *local_res10;
  undefined8 local_res18;
  ulonglong in_stack_ffffffffffffffa8;
  
                    /* 0x4590  3  RndisMIndicateReceive */
  local_res8 = 0;
  cVar7 = '\0';
  cVar1 = '\x01';
  uVar5 = 0;
  plVar3 = param_2;
  if (param_2 != (longlong *)0x0) {
    do {
      uVar5 = uVar5 + (int)plVar3[5];
      plVar3 = (longlong *)*plVar3;
    } while (plVar3 != (longlong *)0x0);
    local_res8 = uVar5;
  }
  local_res18 = param_3;
  if (*param_2 == 0) {
    if ((*(byte *)((longlong)param_2 + 10) & 5) == 0) {
      piVar4 = (int *)MmMapLockedPagesSpecifyCache
                                (param_2,0,1,0,in_stack_ffffffffffffffa8 & 0xffffffff00000000,
                                 0x40000010);
    }
    else {
      piVar4 = (int *)param_2[3];
    }
    if (piVar4 == (int *)0x0) goto LAB_1800047b9;
  }
  else {
    local_res10 = (int *)0x0;
    iVar2 = MemAlloc(&local_res10,(ulonglong)local_res8);
    if (iVar2 == 0) {
      piVar4 = local_res10;
      plVar3 = param_2;
      do {
        uVar5 = *(uint *)(plVar3 + 5);
        if ((*(byte *)((longlong)plVar3 + 10) & 5) == 0) {
          in_stack_ffffffffffffffa8 = in_stack_ffffffffffffffa8 & 0xffffffff00000000;
          _Src = (void *)MmMapLockedPagesSpecifyCache
                                   (plVar3,0,1,0,in_stack_ffffffffffffffa8,0x40000010);
        }
        else {
          _Src = (void *)plVar3[3];
        }
        memmove(piVar4,_Src,(ulonglong)uVar5);
        plVar3 = (longlong *)*plVar3;
        piVar4 = (int *)((longlong)piVar4 + (ulonglong)uVar5);
      } while (plVar3 != (longlong *)0x0);
      param_3 = local_res18;
    }
    else {
      local_res10 = (int *)0x0;
    }
    piVar4 = local_res10;
    if (local_res10 == (int *)0x0) goto LAB_1800047b9;
    cVar7 = '\x01';
  }
  RndisGetSystemUpTime((longlong *)(param_1 + 0x4f8));
  if ((((*(uint *)(param_1 + 0x3fc) & 4) == 0) && (gRawEncap == 0)) || (param_4 == 1)) {
    iVar2 = *piVar4;
    if (iVar2 == 1) {
      pcVar6 = ReceivePacketMessage;
    }
    else if (iVar2 == 3) {
      pcVar6 = HaltMessage;
    }
    else if (iVar2 == 7) {
      pcVar6 = IndicateStatusMessage;
    }
    else if (iVar2 == 8) {
      pcVar6 = KeepAliveMessage;
    }
    else if (iVar2 == -0x7ffffffe) {
      pcVar6 = InitCompletionMessage;
    }
    else if (iVar2 + 0x7ffffffcU < 2) {
      pcVar6 = QuerySetCompletionMessage;
    }
    else if (iVar2 == -0x7ffffffa) {
      pcVar6 = ResetCompletionMessage;
    }
    else {
      pcVar6 = KeepAliveCompletionMessage;
      if (iVar2 != -0x7ffffff8) {
        pcVar6 = UnknownMessage;
      }
    }
  }
  else {
    pcVar6 = ReceivePacketMessageRaw;
  }
  cVar1 = (*pcVar6)(param_1,piVar4,param_2,local_res8,param_3,param_5,cVar7);
  if ((cVar1 == '\0') && (cVar7 == '\0')) {
    return;
  }
LAB_1800047b9:
  (**(code **)(param_1 + 0x3a8))(*(undefined8 *)(param_1 + 0x3c0),param_2,param_3);
  if ((cVar7 != '\0') && (cVar1 != '\0')) {
    NdisFreeMemory(piVar4,1);
  }
  return;
}



===== RndismpReturnPacket @ 180004820 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RndismpReturnPacket(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x30);
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  DereferenceRcvFrame(puVar1,param_1);
  NdisFreePacket(param_2);
  _RcvReturnCount = _RcvReturnCount + 1;
  return;
}



===== UnknownMessage @ 180004880 =====

undefined1 UnknownMessage(void)

{
  return 1;
}



===== AllocatePacketMsgWrapper @ 18000488c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * AllocatePacketMsgWrapper(undefined8 param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  void *local_res8;
  
  local_res8 = (void *)0x0;
  pvVar2 = (void *)0x0;
  if ((ulonglong)param_2 + 0x28 < 0x100000000) {
    iVar1 = MemAlloc(&local_res8,(ulonglong)(param_2 + 0x28));
    if (iVar1 == 0) {
      memset(local_res8,0,(ulonglong)(param_2 + 0x28));
      LOCK();
      _PktWrapperAllocated = _PktWrapperAllocated + 1;
      UNLOCK();
      pvVar2 = local_res8;
    }
  }
  return pvVar2;
}



===== CompleteSendData @ 180004900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CompleteSendData(longlong param_1,int param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  plVar2 = *(longlong **)(param_1 + 0x18);
  puVar3 = *(undefined8 **)(param_1 + 0x28);
  while (puVar3 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*puVar3;
    IoFreeMdl();
    LOCK();
    _MdlsAllocated = _MdlsAllocated + -1;
    UNLOCK();
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    lVar6 = *(longlong *)(param_1 + 0x20);
    do {
      lVar4 = *(longlong *)(lVar6 + 0x30);
      NdisFreeMemory(*(undefined8 *)(lVar6 + 0x38),0x28);
      LOCK();
      _PktWrapperAllocated = _PktWrapperAllocated + -1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)((ulonglong)(-(uint)(param_2 != 0) & 4) + 0x534 + (longlong)plVar2);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      lVar5 = *plVar2;
      (**(code **)(lVar5 + 0x1b8))(lVar5,lVar6);
      lVar6 = lVar4;
    } while (lVar4 != 0);
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  DereferenceMsgFrame(param_1);
  return;
}



===== DoMultipleSend @ 1800049e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DoMultipleSend(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  uint local_res20;
  int local_68;
  uint local_64 [3];
  undefined8 *local_58;
  longlong *local_50;
  longlong *local_48;
  
  uVar13 = (uint)param_3;
  uVar12 = 0;
  local_50 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  local_48 = (longlong *)0x0;
  uVar9 = 0;
  local_68 = 0;
  local_64[1] = 0;
  local_64[0] = 0;
  local_res20 = 0;
  local_58 = (undefined8 *)0x0;
  if (*(char *)((longlong)param_1 + 0x504) == '\0') {
    plVar5 = param_2;
    plVar14 = param_2;
    if (uVar13 != 0) {
      do {
        piVar1 = (int *)*plVar14;
        NdisQueryPacket(piVar1,plVar5,param_3,(undefined8 *)0x0,(int *)(local_64 + 1));
        if ((*(char *)((longlong)param_1 + 0x404) == '\0') || (bVar3 = true, uVar13 - 1 <= uVar9)) {
          bVar3 = false;
        }
        plVar5 = plVar8;
        if (plVar8 == (longlong *)0x0) {
          plVar5 = AllocateMsgFrame((longlong)param_1);
          if (plVar5 != (longlong *)0x0) {
            *(undefined4 *)(plVar5 + 6) = 1;
            uVar12 = 0;
            local_50 = plVar5 + 4;
            local_68 = 0;
            local_48 = (longlong *)0x0;
            local_58 = (undefined8 *)0x0;
            *local_50 = 0;
            local_res20 = 0;
            goto LAB_180004adc;
          }
LAB_180004bca:
          uVar11 = 0xc000009a;
          plVar8 = plVar5;
          if (uVar13 <= uVar9) {
            return;
          }
          goto LAB_180004bdb;
        }
LAB_180004adc:
        puVar6 = PrepareDataMessage(piVar1,(longlong)param_1,&local_68,local_64);
        puVar4 = local_58;
        if (puVar6 == (undefined8 *)0x0) {
LAB_180004b84:
          local_58 = puVar4;
          if (uVar12 == 0) goto LAB_180004bca;
          uVar10 = (ulonglong)uVar12;
          do {
            LOCK();
            *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + 1;
            UNLOCK();
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          param_3 = (undefined8 *)0x0;
          plVar5[7] = (longlong)CompleteSendData;
          QueueMessageToMicroport((longlong)param_1,plVar5,'\0');
          uVar12 = 0;
          plVar8 = (longlong *)0x0;
          plVar7 = plVar5;
          if (puVar6 != (undefined8 *)0x0) goto LAB_180004bba;
        }
        else {
          lVar2 = puVar6[2];
          plVar7 = (longlong *)(piVar1 + 0xc);
          *puVar6 = plVar5;
          *(undefined8 **)(piVar1 + 0xe) = puVar6;
          *plVar7 = 0;
          if (plVar5[5] == 0) {
            plVar5[5] = lVar2;
          }
          uVar12 = uVar12 + 1;
          *local_50 = (longlong)piVar1;
          if (local_48 != (longlong *)0x0) {
            **(longlong **)(local_48[1] + 0x18) = lVar2;
          }
          if ((local_58 != (undefined8 *)0x0) && (local_64[0] != 0)) {
            piVar1 = (int *)((ulonglong)local_res20 + 0x24 + (longlong)local_58);
            *piVar1 = *piVar1 + local_64[0];
          }
          local_res20 = local_64[0];
          puVar4 = puVar6;
          if ((!bVar3) || (uVar12 == *(uint *)(param_1 + 0x80))) goto LAB_180004b84;
          plVar8 = plVar5;
          param_3 = local_58;
          local_58 = puVar6;
          local_50 = plVar7;
          local_48 = plVar7;
LAB_180004bba:
          uVar9 = uVar9 + 1;
          plVar14 = plVar14 + 1;
          plVar5 = plVar7;
        }
      } while (uVar9 < uVar13);
    }
  }
  else {
    uVar11 = 0x10003;
    if (uVar13 != 0) {
LAB_180004bdb:
      uVar10 = (ulonglong)(uVar13 - uVar9);
      plVar5 = param_2 + uVar9;
      do {
        LOCK();
        *(int *)(param_1 + 0xa7) = (int)param_1[0xa7] + 1;
        UNLOCK();
        (**(code **)(*param_1 + 0x1b8))(*param_1,*plVar5,uVar11);
        plVar5 = plVar5 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (plVar8 != (longlong *)0x0) {
      plVar8[5] = 0;
      DereferenceMsgFrame((longlong)plVar8);
    }
  }
  return;
}



===== DoMultipleSendRaw @ 180004c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DoMultipleSendRaw(longlong *param_1,undefined8 *param_2,undefined8 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined8 *puVar3;
  uint uVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  undefined4 uVar10;
  uint uVar11;
  ulonglong uVar12;
  int local_res8 [2];
  undefined8 *local_res10;
  int *piVar13;
  
  local_res8[0] = 0;
  uVar12 = 0;
  uVar4 = (uint)param_3;
  local_res10 = param_2;
  if (*(char *)((longlong)param_1 + 0x504) == '\0') {
    if (uVar4 != 0) {
      do {
        piVar2 = (int *)*local_res10;
        piVar13 = local_res8;
        NdisQueryPacket(piVar2,local_res10,param_3,(undefined8 *)0x0,piVar13);
        plVar9 = param_1;
        plVar5 = AllocateMsgFrame((longlong)param_1);
        if (plVar5 == (longlong *)0x0) {
          uVar10 = 0xc000009a;
          goto LAB_180004e2c;
        }
        *(undefined4 *)(plVar5 + 6) = 1;
        plVar5[4] = (longlong)piVar2;
        if (plVar5 + 5 != (longlong *)0x0) {
          plVar9 = *(longlong **)(piVar2 + 2);
          plVar5[5] = (longlong)plVar9;
        }
        puVar6 = AllocatePacketMsgWrapper(plVar9,0);
        if (puVar6 != (undefined8 *)0x0) {
          puVar6[2] = 0;
          puVar6[1] = piVar2;
          puVar3 = *(undefined8 **)(piVar2 + 2);
          do {
            while( true ) {
              if (puVar3 == (undefined8 *)0x0) {
                lVar7 = puVar6[2];
                *puVar6 = plVar5;
                piVar2[0xc] = 0;
                piVar2[0xd] = 0;
                *(undefined8 **)(piVar2 + 0xe) = puVar6;
                plVar5[5] = lVar7;
                LOCK();
                *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + 1;
                UNLOCK();
                param_3 = 0;
                plVar5[7] = (longlong)CompleteSendData;
                QueueMessageToMicroport((longlong)param_1,plVar5,'\0');
                goto LAB_180004e11;
              }
              puVar8 = (undefined8 *)*puVar3;
              if ((*(byte *)((longlong)puVar3 + 10) & 5) == 0) {
                piVar13 = (int *)((ulonglong)piVar13 & 0xffffffff00000000);
                lVar7 = MmMapLockedPagesSpecifyCache(puVar3,0,1,0,piVar13,0x40000010);
              }
              else {
                lVar7 = puVar3[3];
              }
              piVar1 = (int *)(puVar3 + 5);
              puVar3 = puVar8;
              if (lVar7 == 0) break;
              if (*piVar1 != 0) {
                piVar13 = (int *)0x0;
                puVar8 = (undefined8 *)IoAllocateMdl(lVar7);
                if (puVar8 == (undefined8 *)0x0) goto LAB_180004d34;
                *puVar8 = 0;
                if (puVar6[2] == 0) {
                  puVar6[2] = puVar8;
                }
                else {
                  *(undefined8 **)puVar6[3] = puVar8;
                }
                puVar6[3] = puVar8;
                LOCK();
                _MdlsAllocated = _MdlsAllocated + 1;
                UNLOCK();
                MmBuildMdlForNonPagedPool();
              }
            }
          } while (*piVar1 == 0);
LAB_180004d34:
          puVar3 = (undefined8 *)puVar6[2];
          while (puVar3 != (undefined8 *)0x0) {
            puVar3 = (undefined8 *)*puVar3;
            IoFreeMdl();
            LOCK();
            _MdlsAllocated = _MdlsAllocated + -1;
            UNLOCK();
          }
          param_3 = 0;
          NdisFreeMemory(puVar6,0x28);
          LOCK();
          _PktWrapperAllocated = _PktWrapperAllocated + -1;
          UNLOCK();
        }
LAB_180004e11:
        uVar11 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar11;
      } while (uVar11 < uVar4);
    }
  }
  else {
    uVar10 = 0x10003;
LAB_180004e2c:
    if ((uint)uVar12 < uVar4) {
      puVar6 = local_res10 + uVar12;
      uVar12 = (ulonglong)(uVar4 - (uint)uVar12);
      do {
        LOCK();
        *(int *)(param_1 + 0xa7) = (int)param_1[0xa7] + 1;
        UNLOCK();
        (**(code **)(*param_1 + 0x1b8))(*param_1,*puVar6,uVar10);
        puVar6 = puVar6 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
  }
  return;
}



===== FlushPendingMessages @ 180004e80 =====

void FlushPendingMessages(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  byte bVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = param_1 + 0x428;
  bVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar7 = auStack_28;
  *(undefined1 *)(param_1 + 0x58) = 1;
  do {
    *(byte *)(param_1 + 0x430) = bVar5;
    plVar6 = (longlong *)(ulonglong)bVar5;
    plVar2 = *(longlong **)(param_1 + 0x48);
    if (plVar2 == (longlong *)(param_1 + 0x48)) {
LAB_180004f4c:
      *(undefined1 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(puVar7 + -8) = 0x180004f5a;
      KeReleaseSpinLock(lVar1);
      return;
    }
    lVar3 = *plVar2;
    if ((*(longlong **)(lVar3 + 8) != plVar2) ||
       (plVar6 = (longlong *)plVar2[1], (longlong *)*plVar6 != plVar2)) {
LAB_180004f45:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3,plVar6);
      puVar7 = auStack_20;
      goto LAB_180004f4c;
    }
    *plVar6 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar6;
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    plVar6 = *(longlong **)(param_1 + 0x88);
    if (*plVar6 != param_1 + 0x80) goto LAB_180004f45;
    *plVar2 = param_1 + 0x80;
    plVar2[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar2;
    *(longlong **)(param_1 + 0x88) = plVar2;
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)plVar6 >> 8),*(undefined1 *)(param_1 + 0x430)
                                    ));
    LOCK();
    *(int *)(plVar2 + -7) = (int)plVar2[-7] + 1;
    UNLOCK();
    RndisMSendComplete(param_1,(longlong)(plVar2 + -9),0x10003);
    bVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  } while( true );
}



===== PrepareDataMessage @ 180004f7c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * PrepareDataMessage(int *param_1,longlong param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  void *pvVar10;
  undefined8 *puVar11;
  longlong lVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  uint local_res8 [2];
  ulonglong uVar18;
  
  local_res8[0] = 0;
  iVar1 = *param_3;
  if (iVar1 == 0) {
    uVar15 = 0;
  }
  else {
    uVar15 = *(int *)(param_2 + 0x410) + iVar1 & *(uint *)(param_2 + 0x414);
  }
  uVar18 = (ulonglong)*(ushort *)((longlong)param_1 + 0x2a);
  uVar15 = uVar15 - iVar1;
  uVar16 = (ulonglong)uVar15;
  iVar1 = *(int *)(uVar18 + 0x28 + (longlong)param_1);
  uVar2 = *(uint *)(uVar18 + 0x38 + (longlong)param_1);
  uVar13 = -(uint)(iVar1 != 0) & 0x10;
  uVar9 = uVar13 + 0x10;
  if (uVar2 == 0) {
    uVar9 = uVar13;
  }
  iVar3 = *(int *)(uVar18 + 0x58 + (longlong)param_1);
  uVar13 = uVar9 + 0x10;
  if (iVar3 == 0) {
    uVar13 = uVar9;
  }
  uVar9 = uVar13 + 0x24;
  if (uVar9 <= uVar15 + uVar9) {
    uVar17 = uVar15 + uVar9 + 8;
    piVar14 = param_1;
    NdisQueryPacket(param_1,(ulonglong)uVar13,(ulonglong)uVar2,(undefined8 *)0x0,(int *)local_res8);
    if ((*param_3 + local_res8[0] + uVar17 <= *(uint *)(param_2 + 0x40c)) &&
       (pvVar10 = AllocatePacketMsgWrapper(piVar14,uVar17), pvVar10 != (void *)0x0)) {
      *(int **)((longlong)pvVar10 + 8) = param_1;
      *(undefined4 *)((longlong)pvVar10 + uVar16 + 0x20) = 1;
      uVar18 = 0;
      puVar11 = (undefined8 *)IoAllocateMdl((longlong)pvVar10 + 0x20,uVar17,0,0,0);
      if (puVar11 != (undefined8 *)0x0) {
        LOCK();
        _MdlsAllocated = _MdlsAllocated + 1;
        UNLOCK();
        MmBuildMdlForNonPagedPool(puVar11);
        *puVar11 = 0;
        *(undefined8 **)((longlong)pvVar10 + 0x10) = puVar11;
        local_res8[0] = 0;
        puVar6 = *(undefined8 **)(param_1 + 2);
        puVar7 = puVar11;
        uVar8 = 0;
        while (puVar6 != (undefined8 *)0x0) {
          puVar5 = (undefined8 *)*puVar6;
          if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
            uVar18 = uVar18 & 0xffffffff00000000;
            lVar12 = MmMapLockedPagesSpecifyCache(puVar6,0,1,0,uVar18,0x40000010);
          }
          else {
            lVar12 = puVar6[3];
          }
          iVar4 = *(int *)(puVar6 + 5);
          if ((lVar12 == 0) && (iVar4 != 0)) goto LAB_18000525f;
          puVar6 = puVar5;
          if (iVar4 != 0) {
            local_res8[0] = uVar8 + iVar4;
            uVar18 = 0;
            puVar11 = (undefined8 *)IoAllocateMdl(lVar12,iVar4,0,0,0);
            if (puVar11 == (undefined8 *)0x0) goto LAB_18000525f;
            LOCK();
            _MdlsAllocated = _MdlsAllocated + 1;
            UNLOCK();
            MmBuildMdlForNonPagedPool(puVar11);
            *puVar7 = puVar11;
            *puVar11 = 0;
            puVar7 = puVar11;
            uVar8 = local_res8[0];
          }
        }
        *puVar11 = 0;
        *(undefined8 **)((longlong)pvVar10 + 0x18) = puVar11;
        if (uVar17 <= uVar8 + uVar17) {
          *(uint *)((longlong)pvVar10 + uVar16 + 0x24) = (uVar8 - uVar15) + uVar17;
          *(uint *)((longlong)pvVar10 + uVar16 + 0x2c) = uVar8;
          *param_3 = *param_3 + uVar8 + uVar17;
          *param_4 = uVar15;
          *(uint *)((longlong)pvVar10 + uVar16 + 0x28) = uVar9;
          if (uVar13 == 0) {
            return pvVar10;
          }
          *(uint *)((longlong)pvVar10 + uVar16 + 0x40) = uVar13;
          puVar11 = (undefined8 *)(uVar16 + 0x4c + (longlong)pvVar10);
          *(undefined4 *)((longlong)pvVar10 + uVar16 + 0x3c) = 0x24;
          if (iVar1 != 0) {
            *puVar11 = 0x10;
            *(undefined4 *)(puVar11 + 1) = 0xc;
            *(int *)((longlong)puVar11 + 0xc) = iVar1;
            puVar11 = puVar11 + 2;
          }
          if (uVar2 != 0) {
            *(undefined4 *)puVar11 = 0x10;
            *(undefined4 *)((longlong)puVar11 + 4) = 2;
            *(undefined4 *)(puVar11 + 1) = 0xc;
            *(uint *)((longlong)puVar11 + 0xc) = uVar2;
            puVar11 = puVar11 + 2;
            *(ulonglong *)
             ((ulonglong)*(ushort *)((longlong)param_1 + 0x2a) + 0x38 + (longlong)param_1) =
                 (ulonglong)uVar8;
          }
          if (iVar3 == 0) {
            return pvVar10;
          }
          *(undefined4 *)puVar11 = 0x10;
          *(undefined4 *)((longlong)puVar11 + 4) = 6;
          *(undefined4 *)(puVar11 + 1) = 0xc;
          *(int *)((longlong)puVar11 + 0xc) = iVar3;
          return pvVar10;
        }
      }
LAB_18000525f:
      puVar11 = *(undefined8 **)((longlong)pvVar10 + 0x10);
      while (puVar11 != (undefined8 *)0x0) {
        puVar11 = (undefined8 *)*puVar11;
        IoFreeMdl();
        LOCK();
        _MdlsAllocated = _MdlsAllocated + -1;
        UNLOCK();
      }
      NdisFreeMemory(pvVar10,0x28);
      LOCK();
      _PktWrapperAllocated = _PktWrapperAllocated + -1;
      UNLOCK();
    }
  }
  return (void *)0x0;
}



===== QueueMessageToMicroport @ 1800052c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QueueMessageToMicroport(longlong param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 uVar7;
  
  lVar1 = param_1 + 0x428;
  puVar2 = (undefined1 *)(param_1 + 0x430);
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *puVar2 = uVar7;
  if (param_2 != (longlong *)0x0) {
    plVar3 = *(longlong **)(param_1 + 0x50);
    plVar4 = param_2 + 9;
    if (*plVar3 != param_1 + 0x48) {
LAB_180005483:
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar4 = param_1 + 0x48;
    param_2[10] = (longlong)plVar3;
    *plVar3 = (longlong)plVar4;
    *(longlong **)(param_1 + 0x50) = plVar4;
    if (param_3 != '\0') {
      plVar4 = *(longlong **)(param_1 + 0x420);
      if (*plVar4 != param_1 + 0x418) goto LAB_180005483;
      *param_2 = param_1 + 0x418;
      param_2[1] = (longlong)plVar4;
      *plVar4 = (longlong)param_2;
      *(longlong **)(param_1 + 0x420) = param_2;
    }
  }
  if (*(char *)(param_1 + 0x58) == '\0') {
    *(undefined1 *)(param_1 + 0x58) = 1;
    if (*(uint *)(param_1 + 0x40) < *(uint *)(param_1 + 0x38)) {
      do {
        plVar4 = *(longlong **)(param_1 + 0x48);
        if (plVar4 == (longlong *)(param_1 + 0x48)) break;
        lVar5 = *plVar4;
        if ((*(longlong **)(lVar5 + 8) != plVar4) ||
           (plVar3 = (longlong *)plVar4[1], (longlong *)*plVar3 != plVar4)) goto LAB_180005483;
        *plVar3 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar3;
        *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
        plVar3 = *(longlong **)(param_1 + 0x88);
        if (*plVar3 != param_1 + 0x80) goto LAB_180005483;
        *plVar4 = param_1 + 0x80;
        plVar4[1] = (longlong)plVar3;
        *plVar3 = (longlong)plVar4;
        *(longlong **)(param_1 + 0x88) = plVar4;
        KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)plVar3 >> 8),*puVar2));
        LOCK();
        *(int *)(plVar4 + -7) = (int)plVar4[-7] + 1;
        UNLOCK();
        if ((*(char *)(param_1 + 0x504) == '\0') || ((int)plVar4[-3] == 3)) {
          (**(code **)(param_1 + 0x3a0))
                    (*(undefined8 *)(param_1 + 0x3c0),plVar4[-4],plVar4 + -9,(int)plVar4[-3] != 1);
        }
        else {
          RndisMSendComplete(param_1,(longlong)(plVar4 + -9),0x10003);
        }
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
        *puVar2 = uVar7;
      } while (*(uint *)(param_1 + 0x40) < *(uint *)(param_1 + 0x38));
    }
    *(undefined1 *)(param_1 + 0x58) = 0;
  }
  KeReleaseSpinLock(param_1 + 0x428,*(undefined1 *)(param_1 + 0x430));
  return;
}



===== RndismpMultipleSend @ 180005490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RndismpMultipleSend(longlong param_1)

{
  (**(code **)(param_1 + 0x3b8))();
  return;
}



===== SendProcessTimeout @ 1800054b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SendProcessTimeout(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [24];
  longlong local_d8 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_d8,0,0xa0);
  _SndTimerCount = _SndTimerCount + 1;
  lVar1 = param_2 + 0x428;
  iVar10 = 0;
  iVar9 = 0;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar8 = auStack_f8;
  lVar11 = 0;
  plVar2 = (longlong *)(param_2 + 0x98);
  do {
    *(undefined1 *)(param_2 + 0x430) = uVar7;
    plVar3 = (longlong *)*plVar2;
    if (plVar3 == plVar2) {
LAB_1800055a5:
      iVar6 = SndMaxPackets;
      *(undefined1 *)(param_2 + 0x90) = 0;
      if (iVar6 <= iVar9) {
        SndMaxPackets = iVar9;
      }
      *(undefined8 *)(puVar8 + -8) = 0x1800055c6;
      KeReleaseSpinLock(lVar1,uVar7);
      if (iVar10 != 0) {
        pcVar5 = *(code **)(param_2 + 0x3b8);
        *(undefined8 *)(puVar8 + -8) = 0x1800055e6;
        (*pcVar5)(param_2,puVar8 + 0x20,iVar10);
      }
      *(undefined8 *)(puVar8 + -8) = 0x1800055f6;
      return;
    }
    if (((longlong *)plVar3[1] != plVar2) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) {
      pcVar5 = (code *)swi(0x29);
      uVar7 = (*pcVar5)(3);
      puVar8 = auStack_f0;
      goto LAB_1800055a5;
    }
    *plVar2 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar2;
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_2 + 0x430));
    _SndPacketCount = _SndPacketCount + 1;
    local_d8[lVar11] = (longlong)(plVar3 + -6);
    iVar9 = iVar9 + 1;
    lVar11 = lVar11 + 1;
    iVar10 = iVar10 + 1;
    if (iVar10 == 0x14) {
      (**(code **)(param_2 + 0x3b8))(param_2,local_d8,0x14);
      iVar10 = 0;
      lVar11 = 0;
    }
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  } while( true );
}



===== AllocateRequestContext @ 18000561c =====

undefined8 AllocateRequestContext(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = MemAlloc(local_res8,0x50);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_res8[0];
  }
  return uVar2;
}



===== BuildOIDLists @ 180005654 =====

undefined4 BuildOIDLists(longlong param_1,int *param_2,uint param_3,int *param_4,uint param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  uVar9 = 0;
  uVar8 = param_5;
  if (param_3 != 0) {
    uVar10 = (ulonglong)param_3;
    piVar6 = param_2;
    do {
      uVar5 = 0;
      if (param_5 != 0) {
        do {
          if (*piVar6 == param_4[uVar5]) {
            param_4[uVar5] = 0;
            break;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_5);
      }
      uVar3 = uVar8 + 1;
      if (uVar5 != param_5) {
        uVar3 = uVar8;
      }
      uVar8 = uVar3;
      piVar6 = piVar6 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  puVar1 = (undefined8 *)(param_1 + 0x3c8);
  puVar2 = (undefined8 *)(param_1 + 0x3d8);
  iVar4 = MemAlloc(puVar1,(ulonglong)(uVar8 * 4));
  if (iVar4 == 0) {
    *(uint *)(param_1 + 0x3d0) = uVar8 * 4;
    iVar4 = MemAlloc(puVar2,(ulonglong)(uVar8 * 4));
    piVar6 = (int *)*puVar1;
    if (iVar4 == 0) {
      puVar7 = (undefined4 *)*puVar2;
      *(uint *)(param_1 + 0x3e0) = uVar8 * 4;
      *(uint *)(param_1 + 0x3f4) = uVar8;
      if (param_5 != 0) {
        uVar10 = (ulonglong)param_5;
        do {
          if (*param_4 != 0) {
            *piVar6 = *param_4;
            piVar6 = piVar6 + 1;
            *puVar7 = 1;
            puVar7 = puVar7 + 1;
          }
          param_4 = param_4 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      if (param_3 != 0) {
        uVar10 = (ulonglong)param_3;
        do {
          if (*param_2 != 0) {
            *piVar6 = *param_2;
            piVar6 = piVar6 + 1;
            *puVar7 = 2;
            puVar7 = puVar7 + 1;
          }
          param_2 = param_2 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      if (*(int *)(param_1 + 0x3f4) == 0) {
        return 0;
      }
      do {
        if (*(int *)(*(longlong *)(param_1 + 0x3c8) + uVar9 * 4) == 0x10101) {
          *(undefined4 *)(*(longlong *)(param_1 + 0x3d8) + uVar9 * 4) = 1;
        }
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < *(uint *)(param_1 + 0x3f4));
      return 0;
    }
    NdisFreeMemory(piVar6,*(undefined4 *)(param_1 + 0x3d0),0);
  }
  *(undefined4 *)(param_1 + 0x3d0) = 0;
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0x3e0) = 0;
  *puVar2 = 0;
  return 0xc0000001;
}



===== CompleteDeviceRequest @ 180005800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CompleteDeviceRequest(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x30) == 4) {
    pcVar2 = *(code **)(**(longlong **)(param_1 + 0x18) + 0x2c8);
  }
  else {
    if (*(int *)(param_1 + 0x30) != 5) goto LAB_18000583d;
    pcVar2 = *(code **)(**(longlong **)(param_1 + 0x18) + 0x2d0);
  }
  (*pcVar2)();
LAB_18000583d:
  NdisFreeMemory(uVar1,1);
  *(undefined8 *)(param_1 + 0x20) = 0xbcbcbcbc;
  DereferenceMsgFrame(param_1);
  return;
}



===== CompleteSendDeviceRequest @ 180005880 =====

void CompleteSendDeviceRequest(longlong *param_1,int param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  lVar1 = param_1[3];
  if (param_2 != 0) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x428);
    plVar6 = (longlong *)(lVar1 + 0x418);
    *(undefined1 *)(lVar1 + 0x430) = uVar4;
    plVar7 = (longlong *)0x0;
    if ((longlong *)*plVar6 != plVar6) {
      plVar5 = (longlong *)*plVar6;
      do {
        plVar2 = (longlong *)*plVar5;
        if (*(int *)((longlong)plVar5 + 0x34) == *(int *)((longlong)param_1 + 0x34)) {
          if (((longlong *)plVar2[1] != plVar5) ||
             (plVar6 = (longlong *)plVar5[1], (longlong *)*plVar6 != plVar5)) {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          *plVar6 = (longlong)plVar2;
          plVar2[1] = (longlong)plVar6;
          plVar7 = plVar5;
          if (*(longlong **)(lVar1 + 0x60) == plVar5) {
            *(undefined8 *)(lVar1 + 0x60) = 0;
          }
          break;
        }
        plVar5 = plVar2;
      } while (plVar2 != plVar6);
    }
    KeReleaseSpinLock(lVar1 + 0x428,
                      CONCAT71((int7)((ulonglong)plVar6 >> 8),*(undefined1 *)(lVar1 + 0x430)));
    if (plVar7 == param_1) {
      CompleteDeviceRequest((longlong)param_1);
    }
  }
  DereferenceMsgFrame((longlong)param_1);
  return;
}



===== DeviceQueryInformation @ 180005964 =====

undefined8
DeviceQueryInformation
          (longlong param_1,undefined8 param_2,int param_3,undefined4 *param_4,uint param_5,
          undefined8 param_6,undefined8 param_7)

{
  undefined1 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  
  if ((*(char *)(param_1 + 0x504) == '\0') && (*(char *)(param_1 + 0x505) == '\0')) {
    puVar3 = (undefined8 *)AllocateRequestContext();
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar2 = 0x30;
      if (param_5 < 0x31) {
        uVar2 = param_5;
      }
      plVar4 = BuildRndisMessageCommon(param_1,4,param_3,param_4,uVar2);
      if (plVar4 == (longlong *)0x0) {
        uVar5 = 0xc000009a;
        NdisFreeMemory(puVar3,1,0);
      }
      else {
        uVar5 = 0x103;
        puVar3[4] = 0;
        *(undefined4 *)(puVar3 + 8) = 0;
        *puVar3 = 0;
        puVar3[5] = param_6;
        puVar3[6] = param_7;
        puVar3[2] = param_4;
        *(uint *)(puVar3 + 3) = param_5;
        *(int *)(puVar3 + 1) = param_3;
        *(undefined1 *)(puVar3 + 7) = 0;
        plVar4[4] = (longlong)puVar3;
        LOCK();
        *(int *)(plVar4 + 2) = (int)plVar4[2] + 1;
        UNLOCK();
        uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
        *(undefined1 *)(param_1 + 0x430) = uVar1;
        if (*(char *)(param_1 + 0x68) == '\0') {
          *(longlong **)(param_1 + 0x60) = plVar4;
        }
        KeReleaseSpinLock(param_1 + 0x428,uVar1);
        plVar4[7] = (longlong)CompleteSendDeviceRequest;
        QueueMessageToMicroport(param_1,plVar4,'\x01');
      }
    }
  }
  else {
    uVar5 = 0x10003;
  }
  return uVar5;
}



===== DeviceSetInformation @ 180005ac8 =====

undefined8
DeviceSetInformation
          (longlong param_1,undefined8 param_2,int param_3,undefined4 *param_4,uint param_5,
          undefined8 param_6,undefined8 param_7)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  if ((*(char *)(param_1 + 0x504) == '\0') && (*(char *)(param_1 + 0x505) == '\0')) {
    puVar2 = (undefined8 *)AllocateRequestContext();
    if (puVar2 == (undefined8 *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      plVar3 = BuildRndisMessageCommon(param_1,5,param_3,param_4,param_5);
      if (plVar3 == (longlong *)0x0) {
        uVar4 = 0xc000009a;
        NdisFreeMemory(puVar2,1,0);
      }
      else {
        uVar4 = 0x103;
        puVar2[5] = 0;
        *(undefined4 *)(puVar2 + 8) = 0;
        *puVar2 = 0;
        puVar2[2] = param_4;
        puVar2[4] = param_6;
        puVar2[6] = param_7;
        *(uint *)(puVar2 + 3) = param_5;
        *(int *)(puVar2 + 1) = param_3;
        *(undefined1 *)(puVar2 + 7) = 0;
        uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
        *(undefined1 *)(param_1 + 0x430) = uVar1;
        if (*(char *)(param_1 + 0x68) == '\0') {
          *(longlong **)(param_1 + 0x60) = plVar3;
        }
        KeReleaseSpinLock(param_1 + 0x428,uVar1);
        plVar3[4] = (longlong)puVar2;
        LOCK();
        *(int *)(plVar3 + 2) = (int)plVar3[2] + 1;
        UNLOCK();
        plVar3[7] = (longlong)CompleteSendDeviceRequest;
        QueueMessageToMicroport(param_1,plVar3,'\x01');
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



===== DriverQueryInformation @ 180005c20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
DriverQueryInformation
          (longlong param_1,undefined8 param_2,uint param_3,undefined4 *param_4,uint param_5,
          uint *param_6,uint *param_7)

{
  uint uVar1;
  int *_Src;
  undefined8 uVar2;
  int iVar3;
  undefined1 auStackY_78 [32];
  int local_38;
  undefined2 local_34 [2];
  int local_30 [2];
  char acStack_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = 0;
  builtin_strncpy(acStack_28,"DIS Network Card",0x11);
  local_38 = 0;
  local_34[0] = 0;
  local_30 = (int  [2])0x4e2065746f6d6552;
  if (0x10111 < param_3) {
    if (param_3 < 0x20104) {
      if (param_3 == 0x20103) {
        local_38 = *(int *)(param_1 + 0x538);
      }
      else if (param_3 == 0x10113) {
        local_38 = *(int *)(param_1 + 0x570);
      }
      else if (param_3 == 0x10115) {
        local_38 = *(int *)(param_1 + 0x400);
      }
      else if (param_3 == 0x10116) {
        local_38 = 0xa000b;
      }
      else {
        if (param_3 == 0x10117) {
          _Src = (int *)&CustomGuidList;
          uVar1 = 0x1c;
          goto LAB_180005e97;
        }
        if (param_3 == 0x20101) {
          local_38 = *(int *)(param_1 + 0x534);
        }
        else {
          if (param_3 != 0x20102) {
            return 0xc0010017;
          }
          local_38 = *(int *)(param_1 + 0x540);
        }
      }
    }
    else if (param_3 == 0x20104) {
      local_38 = *(int *)(param_1 + 0x544);
    }
    else {
      if (param_3 != 0x20105) {
        if ((param_3 + 0x2feff00 & 0xfffffffd) == 0) {
          return 0xc00000bb;
        }
        if (param_3 != 0xffa0c90a) {
          return 0xc0010017;
        }
        _Src = (int *)(param_1 + 0x530);
        uVar1 = 0x2c;
        goto LAB_180005e97;
      }
      local_38 = *(int *)(param_1 + 0x548);
    }
    goto LAB_180005e8d;
  }
  if (param_3 == 0x10111) {
LAB_180005d1d:
    local_38 = 0x5ea;
  }
  else if (param_3 < 0x1010b) {
    if (param_3 == 0x1010a) goto LAB_180005d1d;
    if (param_3 == 0x10101) {
      _Src = *(int **)(param_1 + 0x3c8);
      uVar1 = *(uint *)(param_1 + 0x3d0);
      goto LAB_180005e97;
    }
    if (param_3 == 0x10104) {
      iVar3 = 0x10103;
      goto LAB_180005cef;
    }
    if ((param_3 == 0x10105) || (param_3 == 0x10106)) goto LAB_180005d7c;
    if (param_3 == 0x10108) {
      local_38 = *(int *)(param_1 + 0x40c);
    }
    else {
      if (param_3 != 0x10109) {
        return 0xc0010017;
      }
      local_38 = *(int *)(param_1 + 0x408) << 3;
    }
  }
  else {
    if (param_3 == 0x1010b) goto LAB_180005d1d;
    if (param_3 != 0x1010c) {
      if (param_3 == 0x1010d) {
        if (*(ushort *)(param_1 + 0x18) == 0) {
          _Src = local_30;
          uVar1 = 0x19;
        }
        else {
          _Src = *(int **)(param_1 + 0x20);
          uVar1 = (uint)*(ushort *)(param_1 + 0x18);
        }
        goto LAB_180005e97;
      }
      uVar1 = 2;
      if (param_3 != 0x1010f) {
        if (param_3 != 0x10110) {
          return 0xc0010017;
        }
        local_34[0] = CONCAT11(*(undefined1 *)(*(longlong *)(param_1 + 0x10) + 8),
                               *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 9));
        _Src = (int *)local_34;
        goto LAB_180005e97;
      }
LAB_180005d7c:
      iVar3 = 0x10106;
LAB_180005cef:
      uVar2 = DeviceQueryInformation(param_1,param_2,iVar3,param_4,param_5,param_6,param_7);
      return uVar2;
    }
    local_38 = 0xffffff;
  }
LAB_180005e8d:
  uVar1 = 4;
  _Src = &local_38;
LAB_180005e97:
  if (param_5 < uVar1) {
    *param_7 = uVar1;
    uVar2 = 0xc0010016;
  }
  else {
    *param_6 = uVar1;
    if (uVar1 != 0) {
      memmove(param_4,_Src,(ulonglong)uVar1);
    }
  }
  return uVar2;
}



===== Feature_1158651193__private_IsEnabledDeviceUsageNoInline @ 180005ee4 =====

ulonglong Feature_1158651193__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1158651193__private_featureState;
  if ((Feature_1158651193__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1158651193__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1158651193__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1158651193__private_IsEnabledFallback @ 180005f1c =====

void Feature_1158651193__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1158651193__private_descriptor);
  return;
}



===== FreeOIDLists @ 180005f38 =====

void FreeOIDLists(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x428);
  lVar3 = *(longlong *)(param_1 + 0x3c8);
  uVar1 = *(undefined4 *)(param_1 + 0x3d0);
  lVar4 = *(longlong *)(param_1 + 0x3d8);
  uVar2 = *(undefined4 *)(param_1 + 0x3e0);
  *(undefined8 *)(param_1 + 0x3c8) = 0;
  *(undefined4 *)(param_1 + 0x3d0) = 0;
  *(undefined8 *)(param_1 + 0x3d8) = 0;
  *(undefined4 *)(param_1 + 0x3e0) = 0;
  *(undefined4 *)(param_1 + 0x3f4) = 0;
  *(undefined1 *)(param_1 + 0x430) = uVar5;
  KeReleaseSpinLock(param_1 + 0x428,uVar5);
  if (lVar3 != 0) {
    NdisFreeMemory(lVar3,uVar1,0);
  }
  if (lVar4 != 0) {
    NdisFreeMemory(lVar4,uVar2,0);
  }
  return;
}



===== ProcessSetInformation @ 180006018 =====

ulonglong ProcessSetInformation
                    (longlong param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    uint param_5,undefined4 *param_6,undefined8 param_7)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x3f4) != 0) {
    do {
      if (*(int *)(*(longlong *)(param_1 + 0x3c8) + uVar3 * 4) == param_3) {
        iVar1 = *(int *)(*(longlong *)(param_1 + 0x3d8) + uVar3 * 4);
        if (iVar1 == 0) {
          return 0xc0010017;
        }
        if (iVar1 != 1) {
          if (iVar1 == 2) {
            uVar3 = DeviceSetInformation(param_1,param_1,param_3,param_4,param_5,param_6,param_7);
            return uVar3;
          }
          return 0xc0010017;
        }
        if (param_3 == 0x1010f) {
          *param_6 = 4;
          return (ulonglong)(-(uint)(param_5 != 4) & 0xc0010014);
        }
        if (5 < param_3 + 0x2fefeffU) {
          return 0xc0010017;
        }
        if ((0x2dU >> (param_3 + 0x2fefeffU & 0x1f) & 1) == 0) {
          return 0xc0010017;
        }
        return 0xc00000bb;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x3f4));
  }
  return 0xc0010017;
}



===== QuerySetCompletionMessage @ 1800060e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
QuerySetCompletionMessage(longlong *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  longlong *plVar1;
  int *piVar2;
  void *_Dst;
  undefined1 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined4 *puVar9;
  code *pcVar10;
  uint uVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  longlong *plVar17;
  char unaff_R13B;
  uint unaff_R15D;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  
  uVar5 = 0;
  uVar7 = Feature_1158651193__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    uVar6 = param_2[1];
  }
  else {
    uVar6 = param_4;
  }
  uVar7 = Feature_1158651193__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    uVar11 = *param_2;
    puVar9 = (undefined4 *)(ulonglong)uVar11;
    if (uVar11 == 0x80000004) {
      uVar11 = 0x18;
    }
    else {
      if (uVar11 != 0x80000005) goto LAB_180006431;
      uVar11 = 0x10;
    }
    if (param_4 < uVar11) goto LAB_180006431;
  }
  plVar15 = param_1 + 0x85;
  plVar17 = (longlong *)0x0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar15);
  plVar13 = param_1 + 0x83;
  *(undefined1 *)(param_1 + 0x86) = uVar4;
  if ((longlong *)*plVar13 != plVar13) {
    plVar8 = (longlong *)*plVar13;
    do {
      plVar1 = (longlong *)*plVar8;
      if (*(uint *)((longlong)plVar8 + 0x34) == param_2[2]) {
        if (((longlong *)plVar1[1] != plVar8) ||
           (plVar13 = (longlong *)plVar8[1], (longlong *)*plVar13 != plVar8)) {
          pcVar10 = (code *)swi(0x29);
          puVar9 = (undefined4 *)(*pcVar10)(3);
          puVar3 = auStack_50;
          goto LAB_1800061fc;
        }
        *plVar13 = (longlong)plVar1;
        plVar1[1] = (longlong)plVar13;
        plVar17 = plVar8;
        if ((longlong *)param_1[0xc] == plVar8) {
          param_1[0xc] = 0;
        }
        break;
      }
      plVar8 = plVar1;
    } while (plVar1 != plVar13);
  }
  puVar9 = (undefined4 *)
           KeReleaseSpinLock(plVar15,CONCAT71((int7)((ulonglong)plVar13 >> 8),(char)param_1[0x86]));
  puVar16 = auStack_58;
  if (plVar17 == (longlong *)0x0) goto LAB_180006431;
  plVar15 = (longlong *)plVar17[4];
  unaff_R15D = *param_2;
  puVar9 = (undefined4 *)(ulonglong)(*(uint *)(plVar17 + 6) | 0x80000000);
  unaff_R13B = (char)plVar15[7];
  puVar3 = auStack_58;
  if (unaff_R15D == (*(uint *)(plVar17 + 6) | 0x80000000)) {
LAB_1800061fc:
    puVar16 = puVar3;
    if (unaff_R15D == 0x80000004) {
      uVar11 = param_2[3];
      *(uint *)((longlong)plVar15 + 0x3c) = uVar11;
      if ((int)plVar15[1] == 0x10101) {
        if (uVar11 == 0) {
          uVar14 = (ulonglong)param_2[5];
          uVar7 = (ulonglong)uVar6;
          if (((uVar7 < 0x18) || (uVar14 < 0x10)) ||
             ((uVar7 - 8 < uVar14 || ((uVar7 - uVar14) - 8 < (ulonglong)param_2[4])))) {
            uVar5 = 0xc0010015;
            *(undefined4 *)((longlong)plVar15 + 0x3c) = 0xc0010015;
            *(undefined8 *)(puVar16 + -8) = 0x1800062d3;
            Feature_1158651193__private_IsEnabledDeviceUsageNoInline();
          }
          else {
            uVar5 = param_2[4];
            piVar2 = (int *)param_1[0x7d];
            *(int *)(puVar16 + 0x20) = (int)param_1[0x7e];
            *(undefined8 *)(puVar16 + -8) = 0x1800062c0;
            uVar5 = BuildOIDLists((longlong)param_1,(int *)(uVar14 + 8 + (longlong)param_2),
                                  uVar5 >> 2,piVar2,*(uint *)(puVar16 + 0x20));
          }
        }
        lVar12 = plVar15[9];
        *(undefined8 *)(puVar16 + -8) = 0x1800062de;
        puVar9 = (undefined4 *)NdisSetEvent(lVar12);
      }
      else {
        puVar9 = (undefined4 *)(ulonglong)param_2[4];
        *(uint *)plVar15[6] = param_2[4];
        uVar11 = param_2[4];
        if (*(uint *)(plVar15 + 3) < uVar11) {
          uVar5 = 0xc0010016;
        }
        else {
          if (param_2[3] == 0) {
            uVar14 = (ulonglong)param_2[5];
            uVar7 = (ulonglong)uVar6;
            if ((((uVar7 < 0x18) || (uVar14 < 0x10)) || (uVar7 - 8 < uVar14)) ||
               ((uVar7 - uVar14) - 8 < (ulonglong)uVar11)) {
              *(undefined4 *)((longlong)plVar15 + 0x3c) = 0xc0010015;
              uVar5 = 0xc0010015;
              *(undefined4 *)plVar15[5] = 0;
              *(undefined8 *)(puVar16 + -8) = 0x1800063a0;
              puVar9 = (undefined4 *)Feature_1158651193__private_IsEnabledDeviceUsageNoInline();
            }
            else {
              _Dst = (void *)plVar15[2];
              *(undefined8 *)(puVar16 + -8) = 0x18000637f;
              memmove(_Dst,(void *)(uVar14 + 8 + (longlong)param_2),(ulonglong)uVar11);
              puVar9 = (undefined4 *)(ulonglong)param_2[4];
              *(uint *)plVar15[5] = param_2[4];
            }
            if ((int)plVar15[1] == 0x10113) {
              uVar6 = *(uint *)plVar15[2] & 0x40 | *(uint *)(param_1 + 0xae);
              puVar9 = (undefined4 *)(ulonglong)uVar6;
              *(uint *)plVar15[2] = uVar6;
            }
            if (unaff_R13B == '\0') goto LAB_18000631d;
            if (plVar15[9] != 0) {
              *(undefined8 *)(puVar16 + -8) = 0x1800063d8;
              puVar9 = (undefined4 *)NdisSetEvent();
              goto LAB_180006431;
            }
            goto LAB_18000624c;
          }
          *(uint *)plVar15[6] = uVar11;
          puVar9 = (undefined4 *)plVar15[5];
          *puVar9 = 0;
          uVar5 = param_2[3];
        }
      }
      goto LAB_180006314;
    }
    if (unaff_R15D != 0x80000005) goto LAB_180006314;
    if (param_2[3] == 0) {
      puVar9 = (undefined4 *)(ulonglong)*(uint *)(plVar15 + 3);
      *(uint *)plVar15[4] = *(uint *)(plVar15 + 3);
    }
    else {
      *(uint *)plVar15[4] = 0;
      uVar5 = param_2[3];
    }
    *(uint *)((longlong)plVar15 + 0x3c) = uVar5;
    if (unaff_R13B == '\0') goto LAB_18000631d;
    if (plVar15[9] != 0) {
      *(undefined8 *)(puVar16 + -8) = 0x180006243;
      puVar9 = (undefined4 *)NdisSetEvent();
      plVar17 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
    }
LAB_18000624c:
    if (plVar15 != (longlong *)0x0) {
LAB_18000640e:
      *(undefined8 *)(puVar16 + -8) = 0x18000641f;
      puVar9 = (undefined4 *)NdisFreeMemory(plVar15,1);
    }
  }
  else {
    plVar17 = (longlong *)0x0;
    uVar5 = 0xc0000001;
LAB_180006314:
    if (unaff_R13B != '\0') goto LAB_18000624c;
LAB_18000631d:
    if (plVar15 != (longlong *)0x0) {
      if (*plVar15 == 0) {
        if (unaff_R15D == 0x80000004) {
          lVar12 = *param_1;
          pcVar10 = *(code **)(lVar12 + 0x2c8);
        }
        else {
          if (unaff_R15D != 0x80000005) goto LAB_18000640e;
          lVar12 = *param_1;
          pcVar10 = *(code **)(lVar12 + 0x2d0);
        }
        *(undefined8 *)(puVar16 + -8) = 0x18000640e;
        (*pcVar10)(lVar12,uVar5);
      }
      else {
        lVar12 = *param_1;
        *(undefined8 *)(puVar16 + -8) = 0x18000633e;
        NdisMCoRequestComplete(uVar5,lVar12);
      }
      goto LAB_18000640e;
    }
  }
  if (plVar17 != (longlong *)0x0) {
    *(undefined8 *)(puVar16 + -8) = 0x180006431;
    puVar9 = (undefined4 *)DereferenceMsgFrame((longlong)plVar17);
  }
LAB_180006431:
  return CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
}



===== RndismpQueryInformation @ 180006460 =====

undefined8
RndismpQueryInformation
          (longlong param_1,uint param_2,undefined4 *param_3,uint param_4,uint *param_5,
          uint *param_6)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (*(char *)(param_1 + 0x501) == '\x01') {
    uVar3 = 0xc001000c;
  }
  else {
    uVar4 = 0;
    if (*(uint *)(param_1 + 0x3f4) != 0) {
      do {
        if (*(uint *)(*(longlong *)(param_1 + 0x3c8) + uVar4 * 4) == param_2) {
          iVar1 = *(int *)(*(longlong *)(param_1 + 0x3d8) + uVar4 * 4);
          if (iVar1 != 0) {
            if (iVar1 == 1) {
              uVar3 = DriverQueryInformation(param_1,uVar4,param_2,param_3,param_4,param_5,param_6);
              return uVar3;
            }
            if (iVar1 == 2) {
              uVar3 = DeviceQueryInformation(param_1,uVar4,param_2,param_3,param_4,param_5,param_6);
              return uVar3;
            }
          }
          break;
        }
        uVar2 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 0x3f4));
    }
    uVar3 = 0xc0010017;
  }
  return uVar3;
}



===== RndismpSetInformation @ 180006520 =====

ulonglong RndismpSetInformation
                    (longlong param_1,undefined8 param_2,undefined4 *param_3,uint param_4,
                    undefined4 *param_5,undefined8 param_6)

{
  ulonglong uVar1;
  
  if (*(char *)(param_1 + 0x501) == '\x01') {
    uVar1 = 0xc001000c;
  }
  else {
    uVar1 = ProcessSetInformation(param_1,param_2,(int)param_2,param_3,param_4,param_5,param_6);
  }
  return uVar1;
}



===== AllocateMessageAndFrame @ 180006564 =====

void * AllocateMessageAndFrame(longlong param_1,ulonglong param_2)

{
  int iVar1;
  longlong lVar2;
  void *pvVar3;
  longlong local_res18;
  
  local_res18 = 0;
  iVar1 = MemAlloc(&local_res18,param_2);
  if ((iVar1 == 0) && (lVar2 = IoAllocateMdl(local_res18,param_2 & 0xffffffff,0,0,0), lVar2 != 0)) {
    MmBuildMdlForNonPagedPool(lVar2);
    pvVar3 = AllocateMsgFrame(param_1);
    if (pvVar3 != (void *)0x0) {
      *(longlong *)((longlong)pvVar3 + 0x28) = lVar2;
      *(int *)(local_res18 + 4) = (int)param_2;
      return pvVar3;
    }
    IoFreeMdl(lVar2);
  }
  if (local_res18 != 0) {
    NdisFreeMemory(local_res18,param_2 & 0xffffffff,0);
  }
  return (void *)0x0;
}



===== AllocateMsgFrame @ 180006630 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * AllocateMsgFrame(longlong param_1)

{
  int *piVar1;
  int iVar2;
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromNPagedLookasideList(param_1 + 0x180);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x60);
    *(longlong *)((longlong)_Dst + 0x18) = param_1;
    LOCK();
    piVar1 = (int *)(param_1 + 0x204);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *(undefined4 *)((longlong)_Dst + 0x58) = 0x47535246;
    *(int *)((longlong)_Dst + 0x34) = iVar2 + 1;
    *(undefined4 *)((longlong)_Dst + 0x10) = 1;
    LOCK();
    _MsgFrameAllocs = _MsgFrameAllocs + 1;
    UNLOCK();
  }
  return _Dst;
}



===== BuildRndisMessageCommon @ 1800066a4 =====

void * BuildRndisMessageCommon
                 (longlong param_1,int param_2,int param_3,undefined4 *param_4,uint param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if (param_2 == 2) {
    pvVar3 = AllocateMessageAndFrame(param_1,0x18);
    if (pvVar3 == (void *)0x0) {
      return (void *)0x0;
    }
    lVar2 = *(longlong *)((longlong)pvVar3 + 0x28);
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      puVar4 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      puVar4 = *(undefined4 **)(lVar2 + 0x18);
    }
    if (puVar4 == (undefined4 *)0x0) {
      return pvVar3;
    }
    *puVar4 = 2;
    uVar1 = *(undefined4 *)((longlong)pvVar3 + 0x34);
    *(undefined4 *)((longlong)pvVar3 + 0x30) = 2;
    puVar4[4] = 0;
    puVar4[2] = uVar1;
    puVar4[3] = 1;
    puVar4[5] = *(undefined4 *)(param_1 + 0x408);
    return pvVar3;
  }
  if (param_2 != 3) {
    if ((param_2 == 4) || (param_2 == 5)) {
      pvVar3 = AllocateMessageAndFrame(param_1,(ulonglong)(param_5 + 0x1c));
      if (pvVar3 == (void *)0x0) {
        return (void *)0x0;
      }
      lVar2 = *(longlong *)((longlong)pvVar3 + 0x28);
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        piVar5 = (int *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
      }
      else {
        piVar5 = *(int **)(lVar2 + 0x18);
      }
      if (piVar5 == (int *)0x0) {
        return pvVar3;
      }
      *piVar5 = param_2;
      *(int *)((longlong)pvVar3 + 0x30) = param_2;
      piVar5[2] = *(int *)((longlong)pvVar3 + 0x34);
      piVar5[3] = param_3;
      piVar5[4] = param_5;
      piVar5[5] = 0x14;
      memmove(piVar5 + 7,param_4,(ulonglong)param_5);
      return pvVar3;
    }
    if (param_2 == 6) {
      pvVar3 = AllocateMessageAndFrame(param_1,0xc);
      if (pvVar3 == (void *)0x0) {
        return (void *)0x0;
      }
      lVar2 = *(longlong *)((longlong)pvVar3 + 0x28);
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        puVar4 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
      }
      else {
        puVar4 = *(undefined4 **)(lVar2 + 0x18);
      }
      if (puVar4 == (undefined4 *)0x0) {
        return pvVar3;
      }
      *puVar4 = 6;
      *(undefined4 *)((longlong)pvVar3 + 0x30) = 6;
      puVar4[2] = 0;
      return pvVar3;
    }
    if (param_2 != 8) {
      if (param_2 != -0x7ffffff8) {
        return (void *)0x0;
      }
      pvVar3 = AllocateMessageAndFrame(param_1,0x10);
      if (pvVar3 == (void *)0x0) {
        return (void *)0x0;
      }
      lVar2 = *(longlong *)((longlong)pvVar3 + 0x28);
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        puVar4 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
      }
      else {
        puVar4 = *(undefined4 **)(lVar2 + 0x18);
      }
      if (puVar4 == (undefined4 *)0x0) {
        return pvVar3;
      }
      *puVar4 = 0x80000008;
      *(undefined4 *)((longlong)pvVar3 + 0x30) = 0x80000008;
      uVar1 = *param_4;
      puVar4[3] = 0;
      puVar4[2] = uVar1;
      return pvVar3;
    }
  }
  pvVar3 = AllocateMessageAndFrame(param_1,0xc);
  if (pvVar3 != (void *)0x0) {
    lVar2 = *(longlong *)((longlong)pvVar3 + 0x28);
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      piVar5 = (int *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      piVar5 = *(int **)(lVar2 + 0x18);
    }
    if (piVar5 != (int *)0x0) {
      *piVar5 = param_2;
      *(int *)((longlong)pvVar3 + 0x30) = param_2;
      piVar5[2] = *(int *)((longlong)pvVar3 + 0x34);
    }
  }
  return pvVar3;
}



===== CompleteSendKeepAlive @ 180006940 =====

void CompleteSendKeepAlive(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  DereferenceMsgFrame(param_1);
  if (param_2 != 0) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x428);
    *(undefined1 *)(lVar1 + 0x502) = 0;
    *(undefined1 *)(lVar1 + 0x430) = uVar2;
    *(undefined1 *)(lVar1 + 0x500) = 0;
    KeReleaseSpinLock(lVar1 + 0x428,uVar2);
  }
  return;
}



===== DereferenceMsgFrame @ 1800069a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DereferenceMsgFrame(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  longlong lVar6;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    lVar3 = *(longlong *)(param_1 + 0x18);
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x428);
    *(undefined1 *)(lVar3 + 0x430) = uVar5;
    KeReleaseSpinLock(lVar3 + 0x428,uVar5);
    lVar4 = *(longlong *)(param_1 + 0x28);
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
    if (lVar4 != 0) {
      if ((*(byte *)(lVar4 + 10) & 5) == 0) {
        lVar6 = MmMapLockedPagesSpecifyCache(lVar4,0,1,0,0,0x40000010);
      }
      else {
        lVar6 = *(longlong *)(lVar4 + 0x18);
      }
      if (lVar6 != 0) {
        NdisFreeMemory(lVar6,1);
        IoFreeMdl(lVar4);
      }
    }
    ExFreeToNPagedLookasideList(lVar3 + 0x180,param_1);
    LOCK();
    _MsgFrameAllocs = _MsgFrameAllocs + -1;
    UNLOCK();
  }
  return;
}



===== DeviceObjectToDriverBlock @ 180006a9c =====

longlong DeviceObjectToDriverBlock(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
  lVar1 = DAT_18000a120;
  do {
    if (*(longlong *)(lVar1 + 0x18) == *(longlong *)(param_2 + 8)) break;
    lVar1 = *(longlong *)(lVar1 + 0x10);
  } while (lVar1 != 0);
  KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
  return lVar1;
}



===== FreeAdapter @ 180006b04 =====

void FreeAdapter(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(param_1 + 1000) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 1000),0x5c);
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x1a),0);
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 0x30),*(undefined2 *)(param_1 + 0x2a),0);
  }
  puVar5 = auStack_28;
  plVar1 = (longlong *)(param_1 + 0x70);
  do {
    if ((longlong *)*plVar1 == plVar1) {
LAB_180006ba8:
      if (*(char *)(param_1 + 0x200) != '\0') {
        *(undefined8 *)(puVar5 + -8) = 0x180006bbf;
        ExDeleteNPagedLookasideList(param_1 + 0x180);
        *(undefined1 *)(param_1 + 0x200) = 0;
      }
      *(undefined8 *)(puVar5 + -8) = 0x180006bd3;
      FreeReceiveResources(param_1);
      *(undefined8 *)(puVar5 + -8) = 0x180006be5;
      NdisFreeMemory(param_1,0x5c0,0);
      return;
    }
    puVar2 = *(undefined8 **)(param_1 + 0x78);
    if (((longlong *)*puVar2 != plVar1) ||
       (plVar3 = (longlong *)puVar2[1], (undefined8 *)*plVar3 != puVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_20;
      goto LAB_180006ba8;
    }
    *(longlong **)(param_1 + 0x78) = plVar3;
    *plVar3 = (longlong)plVar1;
    DereferenceMsgFrame((longlong)puVar2);
    DereferenceMsgFrame((longlong)puVar2);
  } while( true );
}



===== KeepAliveTimerHandler @ 180006c10 =====

void KeepAliveTimerHandler(undefined8 param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong *puVar4;
  code *pcVar5;
  byte bVar6;
  undefined1 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  ulonglong uVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong local_res10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  local_res10 = 0;
  RndisGetSystemUpTime(&local_res10);
  lVar2 = param_2 + 0x428;
  bVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
  puVar13 = auStack_38;
  uVar14 = (ulonglong)bVar6;
  *(byte *)(param_2 + 0x430) = bVar6;
  if (local_res10 - *(longlong *)(param_2 + 0x4f8) < 0x1389) {
LAB_180006e55:
    KeReleaseSpinLock(lVar2,bVar6);
    puVar13 = auStack_38;
  }
  else {
    plVar10 = *(longlong **)(param_2 + 0x60);
    if (plVar10 != (longlong *)0x0) {
      plVar17 = (longlong *)0x0;
      for (puVar11 = *(undefined8 **)(param_2 + 0x48); puVar11 != (undefined8 *)(param_2 + 0x48);
          puVar11 = (undefined8 *)*puVar11) {
        if (puVar11 + -9 == plVar10) {
          plVar17 = plVar10;
          break;
        }
      }
      plVar16 = (longlong *)0x0;
      for (puVar11 = *(undefined8 **)(param_2 + 0x80); puVar11 != (undefined8 *)(param_2 + 0x80);
          puVar11 = (undefined8 *)*puVar11) {
        if (puVar11 + -9 == plVar10) {
          plVar16 = plVar10;
          break;
        }
      }
      plVar12 = (longlong *)0x0;
      for (plVar8 = *(longlong **)(param_2 + 0x418); plVar8 != (longlong *)(param_2 + 0x418);
          plVar8 = (longlong *)*plVar8) {
        if (plVar8 == plVar10) {
          plVar12 = plVar10;
          break;
        }
      }
      plVar8 = (longlong *)(param_2 + 0x70);
      plVar15 = (longlong *)0x0;
      for (plVar9 = (longlong *)*plVar8; plVar9 != plVar8; plVar9 = (longlong *)*plVar9) {
        if (plVar9 == plVar10) {
          plVar15 = plVar10;
          break;
        }
      }
      if (((((plVar17 == (longlong *)0x0) && (plVar16 == (longlong *)0x0)) &&
           (plVar12 == (longlong *)0x0)) && (plVar15 == (longlong *)0x0)) ||
         (*(undefined8 *)(param_2 + 0x60) = 0, plVar12 == (longlong *)0x0)) goto LAB_180006e55;
      lVar3 = *plVar10;
      if ((*(longlong **)(lVar3 + 8) == plVar10) &&
         (plVar16 = (longlong *)plVar10[1], (longlong *)*plVar16 == plVar10)) {
        *plVar16 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar16;
        puVar1 = (ulonglong *)(plVar10 + 9);
        uVar14 = *puVar1;
        if ((*(ulonglong **)(uVar14 + 8) == puVar1) &&
           (puVar4 = (ulonglong *)plVar10[10], (ulonglong *)*puVar4 == puVar1)) {
          *puVar4 = uVar14;
          *(ulonglong **)(uVar14 + 8) = puVar4;
          if (plVar17 == (longlong *)0x0) {
            plVar17 = *(longlong **)(param_2 + 0x78);
            if ((longlong *)*plVar17 != plVar8) goto LAB_180006da4;
            *plVar10 = (longlong)plVar8;
            plVar10[1] = (longlong)plVar17;
            *plVar17 = (longlong)plVar10;
            *(longlong **)(param_2 + 0x78) = plVar10;
          }
          else {
            DereferenceMsgFrame((longlong)plVar10);
          }
          KeReleaseSpinLock(lVar2,*(undefined1 *)(param_2 + 0x430));
          CompleteDeviceRequest((longlong)plVar10);
          puVar13 = auStack_38;
          goto LAB_180006e67;
        }
      }
LAB_180006da4:
      bVar6 = (byte)uVar14;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar13 = auStack_30;
    }
    if (*(char *)(param_2 + 0x502) == '\0') {
      *(undefined8 *)(puVar13 + -8) = 0x180006de0;
      KeReleaseSpinLock(lVar2,bVar6);
      *(undefined4 *)(puVar13 + 0x20) = 0;
      *(undefined8 *)(puVar13 + -8) = 0x180006dfc;
      plVar10 = BuildRndisMessageCommon(param_2,8,0,(undefined4 *)0x0,*(uint *)(puVar13 + 0x20));
      if (plVar10 != (longlong *)0x0) {
        *(undefined8 *)(puVar13 + -8) = 0x180006e0e;
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar2);
        *(undefined1 *)(param_2 + 0x430) = uVar7;
        *(undefined1 *)(param_2 + 0x502) = 1;
        *(undefined4 *)(param_2 + 0x520) = *(undefined4 *)((longlong)plVar10 + 0x34);
        *(undefined8 *)(puVar13 + -8) = 0x180006e35;
        KeReleaseSpinLock(lVar2,uVar7);
        plVar10[7] = (longlong)CompleteSendKeepAlive;
        *(undefined8 *)(puVar13 + -8) = 0x180006e53;
        QueueMessageToMicroport(param_2,plVar10,'\0');
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x500) = 1;
      *(undefined8 *)(puVar13 + -8) = 0x180006dc8;
      KeReleaseSpinLock();
      LOCK();
      *(int *)(param_2 + 0x554) = *(int *)(param_2 + 0x554) + 1;
      UNLOCK();
    }
  }
LAB_180006e67:
  if (*(char *)(param_2 + 0x4d8) == '\0') {
    *(undefined8 *)(puVar13 + -8) = 0x180006e83;
    NdisSetTimer(param_2 + 0x438,0x9c4);
  }
  else {
    *(undefined8 *)(puVar13 + -8) = 0x180006e98;
    NdisSetEvent(param_2 + 0x4e0);
  }
  return;
}



===== MemAlloc @ 180006eb4 =====

int MemAlloc(undefined8 *param_1,ulonglong param_2)

{
  int iVar1;
  
  iVar1 = NdisAllocateMemoryWithTag(param_1,param_2,0x204d4e52);
  if (iVar1 == 0) {
    memset((void *)*param_1,0,param_2 & 0xffffffff);
  }
  return iVar1;
}



===== RemoveAdapter @ 180006f08 =====

void RemoveAdapter(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
  lVar3 = *(longlong *)(lVar2 + 0x78);
  if (lVar3 == param_1) {
    *(undefined8 *)(lVar2 + 0x78) = *(undefined8 *)(param_1 + 8);
  }
  else {
    do {
      plVar1 = (longlong *)(lVar3 + 8);
      lVar3 = *plVar1;
    } while (lVar3 != param_1);
    *plVar1 = *(longlong *)(param_1 + 8);
  }
  *(int *)(lVar2 + 0x80) = *(int *)(lVar2 + 0x80) + -1;
  KeReleaseSpinLock(&RndismpGlobalLock,DAT_18000a218);
  return;
}



===== RndisGetSystemUpTime @ 180006f8c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RndisGetSystemUpTime(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = _DAT_fffff78000000320;
  uVar2 = KeQueryTimeIncrement();
  *param_1 = (longlong)((ulonglong)uVar2 * lVar1) / 10000;
  return;
}



===== GetDeviceFriendlyName @ 180006fe8 =====

int GetDeviceFriendlyName(undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  int iVar1;
  ushort uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_res20 [2];
  longlong local_58;
  undefined8 local_50;
  void *pvStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_58 = 0;
  uVar3 = 9;
  uVar4 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  pvStack_48 = (void *)0x0;
  do {
    local_res20[0] = 0;
    iVar1 = IoGetDeviceProperty(param_1,uVar3,0,0,local_res20);
    if (iVar1 == -0x3fffffdd) {
      iVar1 = MemAlloc(&local_58,(ulonglong)local_res20[0]);
      if (iVar1 == 0) {
        iVar1 = IoGetDeviceProperty(param_1,uVar3,local_res20[0],local_58,local_res20);
        if (iVar1 != 0) {
          NdisFreeMemory(local_58,local_res20[0],0);
          local_58 = 0;
          break;
        }
        RtlInitUnicodeString(&local_40,local_58);
        uVar2 = local_40._2_2_ >> 1;
        iVar1 = MemAlloc(&pvStack_48,(ulonglong)uVar2);
        if (iVar1 == 0) {
          local_50 = (ulonglong)CONCAT42(local_50._4_4_,uVar2) << 0x10;
          memset(pvStack_48,0,(ulonglong)uVar2);
          iVar1 = RtlUnicodeStringToAnsiString(&local_50,&local_40,0);
          if (-1 < iVar1) {
            *param_2 = local_50;
            param_2[1] = (longlong)pvStack_48;
            *param_3 = local_40;
            param_3[1] = uStack_38;
            return iVar1;
          }
          goto LAB_180007081;
        }
      }
      iVar1 = -0x3fffff66;
      goto LAB_180007081;
    }
    uVar4 = uVar4 + 1;
    local_res20[0] = 0;
    uVar3 = 0;
  } while (uVar4 < 2);
  if (iVar1 < 0) {
LAB_180007081:
    if (local_58 != 0) {
      NdisFreeMemory(local_58,1);
    }
    if (pvStack_48 != (void *)0x0) {
      NdisFreeMemory(pvStack_48,local_50._2_2_,0);
    }
  }
  return iVar1;
}



===== PnPDispatch @ 1800071b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PnPDispatch(longlong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar4 = 0;
  lVar6 = 0;
  lVar5 = DeviceObjectToDriverBlock(param_1,param_1);
  if (lVar5 != 0) {
    DAT_18000a218 = KeAcquireSpinLockRaiseToDpc(&RndismpGlobalLock);
    for (lVar6 = *(longlong *)(lVar5 + 0x78);
        (lVar6 != 0 && (*(longlong *)(lVar6 + 0x560) != param_1)); lVar6 = *(longlong *)(lVar6 + 8))
    {
    }
    KeReleaseSpinLock(&RndismpGlobalLock);
  }
  cVar2 = *(char *)(lVar3 + 1);
  if (cVar2 == '\t') {
    puVar1 = (uint *)(*(longlong *)(lVar3 + 8) + 4);
    *puVar1 = *puVar1 | 0x200;
  }
  else if ((cVar2 == '\x17') && (lVar6 != 0)) {
    RndismpInternalHalt(lVar6,'\0');
  }
  if (lVar5 == 0) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar4 = (**(code **)(lVar5 + 0x20))(param_1,param_2);
  }
  return uVar4;
}



===== __GSHandlerCheck @ 1800072b8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1800072dc =====

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



===== __cpu_features_init @ 180007350 =====

/* WARNING: Removing unreachable block (ram,0x0001800073ba) */
/* WARNING: Removing unreachable block (ram,0x000180007369) */
/* WARNING: Removing unreachable block (ram,0x00018000735a) */

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



===== __security_check_cookie @ 180007420 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180007460 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180007490 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180007490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1800074c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 180007540 =====

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



===== memset @ 180007840 =====

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



===== __memset_repmovs @ 180007980 =====

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



===== __memset_query @ 180007a00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180007a80 =====

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



===== __memset_spec_ermsb_repmovsb @ 180007bc0 =====

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



===== __memset_spec_plain @ 180007c40 =====

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



===== wil_details_EvaluateFeatureDependencies @ 18000d008 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_2112250168__private_descriptor;
  ppuVar2 = &Feature_2112250168__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00018000d043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_18000d0bd:
  while( true ) {
    if (&UNK_180009b7f < ppuVar3) {
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
      if (&UNK_180009b7f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00018000d043:
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
      if (&UNK_180009b7f < ppuVar2) goto LAB_18000d0bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_18000d0bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 18000d0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_18000d190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_18000d190;
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
LAB_18000d190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 18000d1e0 =====

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
      for (ppuVar2 = &Feature_2112250168__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_180009b7f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 18000d260 =====

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
  for (ppuVar3 = &Feature_2112250168__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_18000d35d;
  }
LAB_18000d366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_18000d35d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_18000d366;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_18000d32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_18000d32e;
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
    if (&UNK_180009b7f < ppuVar3) goto LAB_18000d366;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_18000d35d;
}



===== entry @ 18000f010 =====

void entry(void)

{
  __security_init_cookie();
  DllInitialize();
  return;
}



===== __security_init_cookie @ 18000f044 =====

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



===== wil_InitializeFeatureStaging @ 18000f078 =====

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
    for (ppuVar3 = &Feature_2112250168__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_18000f0ff;
    }
LAB_18000f139:
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
LAB_18000f0ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_18000f139;
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
    goto LAB_18000f139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_180009b7f < ppuVar3) goto LAB_18000f139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_18000f0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 18000f18c =====

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
  ppuVar4 = &Feature_2112250168__private_descriptor;
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
            if (&UNK_180009b7f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_18000f276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_18000f276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_18000f276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_180009b7f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


