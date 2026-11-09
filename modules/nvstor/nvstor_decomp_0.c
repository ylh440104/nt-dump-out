
===== NvStorGetDmaPoolSize @ 00011000 =====

int NvStorGetDmaPoolSize(longlong param_1,uint param_2)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x25f0) & 0x1000) == 0) {
    return (uint)*(byte *)(param_1 + 0x2500) * 0x106 +
           (uint)*(byte *)(param_1 + 0x2500) * 0xb0 + 0x2067;
  }
  if (0x20 < param_2) {
    param_2 = 0x20;
  }
  return (uint)*(byte *)(param_1 + 0x2500) * (param_2 * 800 + 0xb87) + 0x5c;
}



===== NvStorControllerInitialize @ 0001105c =====

undefined8
NvStorControllerInitialize
          (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
          undefined8 param_5,short param_6,undefined2 param_7,undefined2 param_8,char param_9,
          undefined1 param_10,undefined1 param_11,undefined8 param_12)

{
  longlong lVar1;
  short *psVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined2 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  if (DeviceModelList != 0) {
    psVar2 = &DeviceModelList;
    do {
      psVar2 = psVar2 + 6;
      iVar6 = iVar6 + 1;
    } while (*psVar2 != 0);
    if (iVar6 < 0) goto LAB_000110e8;
  }
  pcVar3 = &DAT_0002f002 + (longlong)iVar6 * 0xc;
  do {
    if ((param_6 == *(short *)(pcVar3 + -2)) && ((*pcVar3 == -1 || (param_9 == *pcVar3)))) {
      puVar5 = &DeviceModelList + (longlong)iVar6 * 6;
      goto LAB_000110eb;
    }
    pcVar3 = pcVar3 + -0xc;
    iVar6 = iVar6 + -1;
  } while (-1 < iVar6);
LAB_000110e8:
  puVar5 = (undefined2 *)0x0;
LAB_000110eb:
  if (puVar5 == (undefined2 *)0x0) {
    uVar4 = 0x80000003;
  }
  else {
    *(undefined4 *)(param_1 + 0x25f0) = *(undefined4 *)(puVar5 + 2);
    *(undefined1 *)(param_1 + 0x2500) = *(undefined1 *)(puVar5 + 4);
    *(undefined1 *)(param_1 + 0x2501) = *(undefined1 *)((longlong)puVar5 + 9);
    uVar4 = (**(code **)(NvStorOsCBT + 0x198))(param_1);
    *(undefined8 *)(param_1 + 0x28c8) = uVar4;
    *(undefined2 *)(param_1 + 0x25fa) = param_7;
    *(undefined2 *)(param_1 + 0x25fc) = param_8;
    *(undefined1 *)(param_1 + 0x25f4) = param_2;
    lVar1 = NvStorOsCBT;
    *(undefined1 *)(param_1 + 0x25f5) = param_3;
    *(ushort *)(param_1 + 0x2600) = CONCAT11(param_10,param_11);
    *(undefined1 *)(param_1 + 0x25f6) = param_4;
    *(short *)(param_1 + 0x25f8) = param_6;
    *(char *)(param_1 + 0x25fe) = param_9;
    (**(code **)(lVar1 + 0x118))(param_1 + 0x2510,param_12,0xe0);
    *(code **)(param_1 + 0x2720) = NvStorControllerConfigNotify;
    *(code **)(param_1 + 0x2750) = NvStorPortConfigNotify;
    *(code **)(param_1 + 0x27a8) = NvStorDeviceConfigNotify;
    if ((*(uint *)(param_1 + 0x25f0) & 0x1000) == 0) {
      *(undefined8 *)(param_1 + 0x26b8) = 0;
      *(undefined8 *)(param_1 + 0x26d0) = 0;
      *(undefined1 **)(param_1 + 0x26c0) = &NvStorAhciControllerGetMaxQueueDepth;
      *(undefined8 *)(param_1 + 0x26d8) = 0;
      *(undefined1 **)(param_1 + 0x26c8) = &NvStorAhciControllerSetQueueDepth;
      *(undefined8 *)(param_1 + 10000) = 0;
      *(code **)(param_1 + 0x26e0) = NvStorSataInitializeController;
      *(undefined8 *)(param_1 + 0x2718) = 0;
      *(undefined1 **)(param_1 + 0x26e8) = &NvStorSpinLockCreate;
      *(undefined8 *)(param_1 + 0x2728) = 0;
      *(code **)(param_1 + 0x26f0) = NvStorSataControllerStop;
      *(undefined8 *)(param_1 + 0x27f0) = 0;
      *(code **)(param_1 + 0x26f8) = NvStorSataControllerRestart;
      *(undefined8 *)(param_1 + 0x2800) = 0;
      *(code **)(param_1 + 0x2700) = NvStorSataControllerIsReady;
      *(code **)(param_1 + 0x2708) = NvStorSataDeviceIsReady;
      *(code **)(param_1 + 0x2730) = NvStorSataInitializePort;
      *(undefined1 **)(param_1 + 0x2738) = &NvStorSpinLockCreate;
      *(code **)(param_1 + 0x2740) = NvStorSataPortStop;
      *(code **)(param_1 + 0x2748) = NvStorSataPortRestart;
      *(undefined1 **)(param_1 + 0x2758) = &NvStorSpinLockCreate;
      *(undefined1 **)(param_1 + 0x2760) = &NvStorSpinLockCreate;
      *(undefined1 **)(param_1 + 0x2768) = &NvStorSpinLockCreate;
      *(undefined1 **)(param_1 + 0x2770) = &NvStorSpinLockCreate;
      *(code **)(param_1 + 0x2778) = NvStorSataInitializeDevice;
      *(code **)(param_1 + 0x2788) = NvStorSataDeviceStart;
      *(undefined1 **)(param_1 + 0x2790) = &NvStorSpinLockCreate;
      *(code **)(param_1 + 0x2798) = NvStorSataDeviceCfgStart;
      *(undefined1 **)(param_1 + 0x27a0) = &NvStorSataDeviceStop;
      *(code **)(param_1 + 0x2780) = NvStorSataDeviceRemove;
      *(code **)(param_1 + 0x27b0) = NvStorSataScsi;
      *(code **)(param_1 + 0x27c0) = NvStorTimerTickController;
      *(code **)(param_1 + 0x27d8) = NvStorSataDeliverTaskFile;
      *(undefined1 **)(param_1 + 0x27e0) = &NvStorSataSetupTaskFile;
      *(undefined1 **)(param_1 + 0x27e8) = &NvStorSataDeliverIdentifyData;
      *(code **)(param_1 + 0x27c8) = NvStorSataPortDetectDevicePresense;
      *(undefined1 **)(param_1 + 0x27d0) = &NvStorSataPortHaltForRemoval;
      *(code **)(param_1 + 0x27f8) = NvStorSataDeviceBuildInquiryPage;
      *(code **)(param_1 + 0x2808) = NvStorSataResetSATAPhy;
      *(code **)(param_1 + 0x2810) = NvStorSataAtapiResetTimer;
    }
    else {
      *(undefined8 *)(param_1 + 0x2810) = 0;
      *(code **)(param_1 + 0x26b8) = NvStorAhciControllerInitialize;
      *(undefined1 **)(param_1 + 0x26c0) = &NvStorAhciControllerGetMaxQueueDepth;
      *(undefined1 **)(param_1 + 0x26c8) = &NvStorAhciControllerSetQueueDepth;
      *(code **)(param_1 + 0x26d0) = NvStorAhciControllerAllocateResources;
      *(code **)(param_1 + 0x26d8) = NvStorAhciControllerReleaseResources;
      *(code **)(param_1 + 0x26e0) = NvStorAhciControllerStart;
      *(code **)(param_1 + 0x26e8) = NvStorAhciControllerCfgSetup;
      *(code **)(param_1 + 0x26f0) = NvStorAhciControllerStop;
      *(code **)(param_1 + 0x26f8) = NvStorAhciControllerRestart;
      *(code **)(param_1 + 0x2700) = NvStorAhciControllerIsReady;
      *(code **)(param_1 + 0x2708) = NvStorAhciDeviceIsReady;
      *(code **)(param_1 + 10000) = NvStorAhciEnableInterruptsGlobal;
      *(code **)(param_1 + 0x2718) = NvStorAhciDisableInterruptsGlobal;
      *(code **)(param_1 + 0x2758) = NvStorAhciPortToPartialState;
      *(code **)(param_1 + 0x2760) = NvStorAhciPortToSlumberState;
      *(code **)(param_1 + 0x2768) = NvStorAhciPortToActiveState;
      *(code **)(param_1 + 0x2770) = NvStorAhciPortSATALinkRebuild;
      *(code **)(param_1 + 0x2728) = NvStorAhciPortInitialize;
      *(code **)(param_1 + 0x2730) = NvStorAhciPortStart;
      *(undefined1 **)(param_1 + 0x2738) = &NvStorSpinLockCreate;
      *(code **)(param_1 + 0x2740) = NvStorAhciPortStop;
      *(code **)(param_1 + 0x2748) = NvStorSataPortRestart;
      *(code **)(param_1 + 0x2778) = NvStorAhciDeviceInitialize;
      *(code **)(param_1 + 0x2788) = NvStorAhciDeviceStart;
      *(undefined1 **)(param_1 + 0x2790) = &NvStorSpinLockCreate;
      *(code **)(param_1 + 0x2798) = NvStorAhciDeviceCfgStart;
      *(code **)(param_1 + 0x27a0) = NvStorAhciDeviceStop;
      *(code **)(param_1 + 0x2780) = NvStorAhciDeviceRemove;
      *(code **)(param_1 + 0x27b0) = NvStorAhciScsi;
      *(code **)(param_1 + 0x27c0) = NvStorTimerTickController;
      *(undefined1 **)(param_1 + 0x27d8) = &NvStorAhciDeliverTaskFile;
      *(code **)(param_1 + 0x27e0) = NvStorAhciSetupTaskFile;
      *(undefined1 **)(param_1 + 0x27e8) = &NvStorAhciDeliverIdentifyData;
      *(undefined1 **)(param_1 + 0x27f0) = &NvStorAhciSetupSmartReq;
      *(code **)(param_1 + 0x27c8) = NvStorAhciPortDetectDevicePresense;
      *(undefined1 **)(param_1 + 0x27d0) = &NvStorAhciPortHaltForRemoval;
      *(code **)(param_1 + 0x27f8) = NvStorAhciDeviceBuildInquiryPage;
      *(code **)(param_1 + 0x2800) = NvStorAhciPreIssueNonIntCommand;
      *(code **)(param_1 + 0x2808) = NvStorAhciResetSATAPhy;
    }
    if (*(code **)(param_1 + 0x26b8) != (code *)0x0) {
      (**(code **)(param_1 + 0x26b8))(param_1);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== NvStorControllerStart @ 00011648 =====

uint NvStorControllerStart(ulonglong param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar2 = 0;
  uVar6 = param_1;
  if (*(code **)(param_1 + 0x26d0) != (code *)0x0) {
    uVar2 = (**(code **)(param_1 + 0x26d0))();
  }
  if ((uVar2 & 0x80000000) == 0) {
    *(undefined1 *)(param_1 + 0x2918) = 0;
    if ((*(uint *)(param_1 + 0x2818) & 0x10) == 0) {
      if (*(longlong *)(param_1 + 0x28c0) != 0) {
        (**(code **)(NvStorOsCBT + 0x108))(param_1,*(longlong *)(param_1 + 0x28c0),0);
        *(undefined8 *)(param_1 + 0x28c0) = 0;
      }
      uVar6 = param_1;
      lVar3 = (**(code **)(NvStorOsCBT + 0x100))(param_1,0x5c,0);
      *(longlong *)(param_1 + 0x28c0) = lVar3;
      if (lVar3 == 0) goto LAB_00011979;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x28c0);
    uVar6 = 0x80000008;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 2;
      *(undefined4 **)(param_1 + 0x2820) = puVar1;
      lVar3 = *(longlong *)(param_1 + 0x2820);
      plVar4 = (longlong *)(*(longlong *)(param_1 + 0x28c0) + 4);
      if ((lVar3 != 0) && (plVar4 != (longlong *)0x0)) {
        *(undefined8 *)(*(longlong *)(param_1 + 0x28c0) + 0xc) = 0;
        *plVar4 = lVar3;
        *(longlong **)(param_1 + 0x2828) = plVar4;
        uVar6 = 0;
      }
      if ((uVar6 & 0x80000000) == 0) {
        plVar4 = (longlong *)(param_1 + 0x2830);
        uVar6 = *(ulonglong *)(param_1 + 0x2820);
        uVar5 = NvCfgEntityCreate(uVar6,*(longlong **)(param_1 + 0x2828),0x4e764374,
                                  &ControllerConfigElements,param_1 + 0x2840,
                                  (undefined8 *)(*(longlong *)(param_1 + 0x28c0) + 0x14),plVar4);
        if (((uVar5 & 0x80000000) == 0) &&
           (uVar5 = NvCfgEntityObserverCreate
                              (uVar6,*plVar4,*(longlong *)(param_1 + 0x2720),
                               (longlong *)(*(longlong *)(param_1 + 0x28c0) + 0x3c),param_1,
                               (undefined8 *)(param_1 + 0x2838)), (uVar5 & 0x80000000) == 0)) {
          uVar6 = *(ulonglong *)(param_1 + 0x2820);
          uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\0',(ulonglong *)(param_1 + 0x25f4),1);
          if ((uVar2 & 0x80000000) == 0) {
            uVar6 = *(ulonglong *)(param_1 + 0x2820);
            uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x01',(ulonglong *)(param_1 + 0x25f5)
                                    ,1);
            if ((uVar2 & 0x80000000) == 0) {
              uVar6 = *(ulonglong *)(param_1 + 0x2820);
              uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x02',
                                      (ulonglong *)(param_1 + 0x25f6),1);
              if ((uVar2 & 0x80000000) == 0) {
                uVar6 = *(ulonglong *)(param_1 + 0x2820);
                uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x03',
                                        (ulonglong *)(param_1 + 0x2500),1);
                if ((uVar2 & 0x80000000) == 0) {
                  uVar6 = *(ulonglong *)(param_1 + 0x2820);
                  uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x04',
                                          (ulonglong *)(param_1 + 0x25f8),2);
                  if ((uVar2 & 0x80000000) == 0) {
                    uVar6 = *(ulonglong *)(param_1 + 0x2820);
                    uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x05',
                                            (ulonglong *)(param_1 + 0x25fa),2);
                    if ((uVar2 & 0x80000000) == 0) {
                      uVar6 = *(ulonglong *)(param_1 + 0x2820);
                      uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x06',
                                              (ulonglong *)(param_1 + 0x25fc),2);
                      if ((uVar2 & 0x80000000) == 0) {
                        uVar6 = *(ulonglong *)(param_1 + 0x2820);
                        uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\a',
                                                (ulonglong *)(param_1 + 0x25fe),1);
                        if ((uVar2 & 0x80000000) == 0) {
                          uVar6 = *(ulonglong *)(param_1 + 0x2820);
                          uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\b',
                                                  (ulonglong *)(param_1 + 0x2600),2);
                          if ((uVar2 & 0x80000000) == 0) {
                            uVar6 = *(ulonglong *)(param_1 + 0x2820);
                            uVar2 = NvCfgElementSet(uVar6,(longlong *)*plVar4,'\x10',
                                                    (ulonglong *)(param_1 + 0x2602),0x61);
                            if ((uVar2 & 0x80000000) == 0) {
                              *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 0x10;
                              if (*(code **)(param_1 + 0x26e8) != (code *)0x0) {
                                uVar2 = (**(code **)(param_1 + 0x26e8))(param_1);
                              }
                              if (*(code **)(param_1 + 0x26e0) == (code *)0x0) {
                                return uVar2;
                              }
                              uVar6 = param_1;
                              uVar2 = (**(code **)(param_1 + 0x26e0))();
                              if ((uVar2 & 0x80000000) == 0) {
                                *(undefined4 *)(param_1 + 0x2664) = 1;
                                return uVar2;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00011979:
  NvCfgEntityObserverDestroy(uVar6,*(longlong **)(param_1 + 0x2838));
  NvCfgEntityDestroy(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830));
  if (*(longlong *)(param_1 + 0x28c0) != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(param_1,*(longlong *)(param_1 + 0x28c0),0);
    *(undefined8 *)(param_1 + 0x28c0) = 0;
  }
  return 0;
}



===== NvStorControllerStop @ 000119dc =====

ulonglong NvStorControllerStop(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x2664) = 2;
  if (*(code **)(param_1 + 0x26f0) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x26f0))();
    uVar3 = (ulonglong)uVar1;
  }
  if ((*(uint *)(param_1 + 0x2818) & 0x10) != 0) {
    NvCfgEntityObserverDestroy
              ((ulonglong)*(uint *)(param_1 + 0x2818),*(longlong **)(param_1 + 0x2838));
    NvCfgEntityDestroy(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830));
    uVar3 = 0;
  }
  if (*(longlong *)(param_1 + 0x28c0) != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(param_1,*(longlong *)(param_1 + 0x28c0),0);
    *(undefined8 *)(param_1 + 0x28c0) = 0;
  }
  *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) & 0xffffffef;
  if (*(code **)(param_1 + 0x26d8) != (code *)0x0) {
    uVar2 = (**(code **)(param_1 + 0x26d8))(param_1);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  return uVar3;
}



===== NvStorPortStart @ 00011a84 =====

void NvStorPortStart(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar2 = (**(code **)(NvStorOsCBT + 0x1a0))();
  lVar1 = *param_1;
  param_1[0x1e] = lVar2;
  if ((*(uint *)(param_1 + 0x24) & 8) == 0) {
    lVar2 = lVar1;
    lVar3 = (**(code **)(NvStorOsCBT + 0x100))(lVar1,0x48,0);
    param_1[0x23] = lVar3;
    if (lVar3 == 0) goto LAB_00011b83;
  }
  lVar2 = *(longlong *)(lVar1 + 0x2820);
  uVar4 = NvCfgEntityCreate(lVar2,*(longlong **)(lVar1 + 0x2828),0x4e765074,&PortConfigElements,
                            (longlong)(param_1 + 0x22),(undefined8 *)param_1[0x23],param_1 + 0x20);
  if ((-1 < (int)uVar4) &&
     (uVar4 = NvCfgEntityObserverCreate
                        (lVar2,param_1[0x20],*(longlong *)(lVar1 + 0x2750),
                         (longlong *)(param_1[0x23] + 0x28),(longlong)param_1,param_1 + 0x21),
     -1 < (int)uVar4)) {
    if (*(code **)(lVar1 + 0x2738) != (code *)0x0) {
      (**(code **)(lVar1 + 0x2738))(param_1);
    }
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 8;
    if (*(code **)(lVar1 + 0x2730) == (code *)0x0) {
      return;
    }
    (**(code **)(lVar1 + 0x2730))(param_1);
    return;
  }
LAB_00011b83:
  NvCfgEntityObserverDestroy(lVar2,(longlong *)param_1[0x21]);
  NvCfgEntityDestroy(*(longlong *)(lVar1 + 0x2820),(longlong *)param_1[0x20]);
  return;
}



===== NvStorPortStop @ 00011bb4 =====

ulonglong NvStorPortStop(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  
  lVar1 = *param_1;
  uVar3 = 0;
  plVar4 = param_1;
  if (*(code **)(lVar1 + 0x2740) != (code *)0x0) {
    uVar2 = (**(code **)(lVar1 + 0x2740))();
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if ((*(uint *)(param_1 + 0x24) & 8) != 0) {
    NvCfgEntityObserverDestroy(plVar4,(longlong *)param_1[0x21]);
    uVar3 = NvCfgEntityDestroy(*(longlong *)(lVar1 + 0x2820),(longlong *)param_1[0x20]);
    uVar3 = uVar3 & 0xffffffff;
  }
  if (param_1[0x23] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(lVar1,param_1[0x23],0);
    param_1[0x23] = 0;
  }
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffff7;
  return uVar3;
}



===== NvStorDeviceInitialize @ 00011c4c =====

ulonglong NvStorDeviceInitialize(longlong *param_1,undefined8 *param_2,byte param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  uVar1 = 0;
  (**(code **)(NvStorOsCBT + 0x110))(param_2,0x2570);
  lVar5 = NvStorOsCBT;
  param_1[(ulonglong)param_3 + 1] = (longlong)param_2;
  *param_2 = param_1;
  uVar2 = (**(code **)(lVar5 + 0x1a8))(param_2);
  param_2[0x110] = uVar2;
  *(byte *)((longlong)param_2 + 0x222) = param_3;
  param_2[0x111] = param_2 + 0x4f1;
  *(undefined2 *)((longlong)param_2 + 0x256d) = 1;
  *(undefined4 *)((longlong)param_2 + 0x24) = 0;
  *(undefined4 *)((longlong)param_2 + 0x2c) = 3;
  *(undefined4 *)((longlong)param_2 + 0x1c) = 4;
  *(undefined4 *)(param_2 + 5) = 100;
  *(undefined4 *)(param_2 + 3) = 100;
  *(undefined4 *)(param_2 + 4) = 2;
  lVar5 = *param_1;
  *(undefined1 *)(param_2 + 0x114) = 0;
  *(undefined4 *)((longlong)param_2 + 0x89c) = 0;
  *(undefined4 *)((longlong)param_2 + 0x8a4) = 0;
  if (*(code **)(lVar5 + 0x2778) != (code *)0x0) {
    uVar3 = (**(code **)(lVar5 + 0x2778))(param_1,param_2,param_3);
    uVar1 = (uint)uVar3;
    if ((int)uVar1 < 0) {
      param_1[(ulonglong)param_3 + 1] = 0;
      return uVar3;
    }
  }
  param_2[0x41f] = 0;
  param_2[0x420] = 0;
  puVar4 = param_2 + 0x416;
  lVar5 = 5;
  do {
    puVar4[-1] = 0;
    *puVar4 = 0;
    puVar4 = puVar4 + 2;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar2 = (**(code **)(NvStorOsCBT + 0x140))();
  param_2[0x425] = uVar2;
  return (ulonglong)uVar1;
}



===== NvStorDeviceRemove @ 00011d84 =====

ulonglong NvStorDeviceRemove(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 local_28 [32];
  
  uVar3 = 0;
  lVar1 = *(longlong *)*param_1;
  if (*(code **)(lVar1 + 0x2780) != (code *)0x0) {
    uVar2 = (**(code **)(lVar1 + 0x2780))();
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  (**(code **)(NvStorOsCBT + 0x150))(lVar1,2,0,local_28);
  *(uint *)(*param_1 + 0x120) = *(uint *)(*param_1 + 0x120) & 0xfffffffd;
  *(undefined8 *)(*param_1 + 8 + (ulonglong)*(byte *)((longlong)param_1 + 0x222) * 8) = 0;
  (**(code **)(NvStorOsCBT + 0x110))(param_1,0x2570);
  (**(code **)(NvStorOsCBT + 0x158))(lVar1,2,0,local_28);
  return uVar3;
}



===== NvStorDeviceReset @ 00011e2c =====

int NvStorDeviceReset(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined1 local_28 [32];
  
  if (param_1[0x71] == 0) {
    iVar2 = -0x7ffffff8;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_28);
    iVar2 = (*(code *)param_1[0x71])(param_1);
    (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*param_1,2,0,local_28);
    if (((*(uint *)(*(longlong *)*param_1 + 0x25f0) & 1) != 0) &&
       ((*(byte *)(param_1 + 0x112) & 0x20) != 0)) {
      *(byte *)(param_1 + 0x113) = *(byte *)(param_1 + 0x113) | 1;
      if (*(code **)(NvStorOsCBT + 0x210) != (code *)0x0) {
        (**(code **)(NvStorOsCBT + 0x210))(param_1,0xf);
      }
    }
    lVar1 = NvStorOsCBT;
    if (iVar2 == 0) {
      if ((param_1[0x112] & 0x4000000000000U) == 0) {
        return 0;
      }
    }
    else {
      param_1[0x112] = param_1[0x112] | 0x1000000;
      if (*param_1 == 0) {
        return iVar2;
      }
      *(undefined8 *)(*param_1 + 8 + (ulonglong)*(byte *)((longlong)param_1 + 0x222) * 8) = 0;
    }
    (**(code **)(lVar1 + 0x188))
              (*(undefined8 *)*param_1,*(undefined1 *)((undefined8 *)*param_1 + 0x1b));
  }
  return iVar2;
}



===== NvStorDeviceStart @ 00011f34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

ulonglong NvStorDeviceStart(longlong *param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  char *pcVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  undefined1 auStackY_c8 [22];
  undefined1 auStackY_b2 [10];
  byte local_88 [4];
  undefined1 local_84 [28];
  ulonglong local_68 [6];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  if ((param_1[0x112] & 0x100000000U) == 0) {
    plVar7 = *(longlong **)*param_1;
    lVar5 = (**(code **)(NvStorOsCBT + 0x100))(plVar7,0x68,0,1);
    param_1[0xd3] = lVar5;
    if (lVar5 == 0) goto LAB_00012863;
  }
  plVar1 = param_1 + 0xb6;
  plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
  uVar6 = NvCfgEntityCreate((longlong)plVar7,*(longlong **)(*(longlong *)*param_1 + 0x2828),
                            0x4e764374,&DeviceConfigElements,(longlong)(param_1 + 0xb9),
                            (undefined8 *)param_1[0xd3],plVar1);
  if ((uVar6 & 0x80000000) == 0) {
    plVar7 = param_1 + 0xb7;
    uVar6 = NvCfgEntityObserverCreate
                      (plVar7,*plVar1,*(longlong *)(*(longlong *)*param_1 + 0x27a8),
                       (longlong *)(param_1[0xd3] + 0x28),(longlong)param_1,plVar7);
    if (((uVar6 & 0x80000000) == 0) &&
       (uVar6 = NvCfgEntityObserverCreate
                          (plVar7,*(longlong *)(*(longlong *)*param_1 + 0x2830),
                           *(longlong *)(*(longlong *)*param_1 + 0x27a8),
                           (longlong *)(param_1[0xd3] + 0x48),(longlong)param_1,param_1 + 0xb8),
       (uVar6 & 0x80000000) == 0)) {
      plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
      uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1e',
                              (ulonglong *)(*(longlong *)*param_1 + 0x25f4),1);
      if ((uVar4 & 0x80000000) == 0) {
        plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
        uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1f',
                                (ulonglong *)(*(longlong *)*param_1 + 0x25f5),1);
        if ((uVar4 & 0x80000000) == 0) {
          plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
          uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,' ',
                                  (ulonglong *)(*(longlong *)*param_1 + 0x25f6),1);
          if ((uVar4 & 0x80000000) == 0) {
            plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
            uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x18',
                                    (ulonglong *)(param_1 + 7),8);
            if ((uVar4 & 0x80000000) == 0) {
              plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
              uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x19',
                                      (ulonglong *)(param_1 + 8),0x10);
              if ((uVar4 & 0x80000000) == 0) {
                if ((*(uint *)(*(longlong *)*param_1 + 0x25f0) & 0x1000) == 0) {
                  lVar5 = param_1[0x110];
                }
                else {
                  lVar5 = *(longlong *)param_1[0x110];
                }
                (**(code **)(NvStorOsCBT + 0x110))(local_68,0x29);
                (**(code **)(NvStorOsCBT + 0x118))(local_68,lVar5 + 0x36,0x28);
                bVar3 = (**(code **)(NvStorOsCBT + 0x120))(local_68);
                if (bVar3 < 0x28) {
                  pcVar9 = (char *)((longlong)local_68 + (ulonglong)bVar3);
                  uVar6 = (ulonglong)(byte)(0x28 - bVar3);
                  do {
                    if (*pcVar9 == '\0') {
                      *pcVar9 = ' ';
                    }
                    pcVar9 = pcVar9 + 1;
                    uVar6 = uVar6 - 1;
                  } while (uVar6 != 0);
                }
                plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1b',local_68,0x28);
                if ((uVar4 & 0x80000000) == 0) {
                  (**(code **)(NvStorOsCBT + 0x110))((ulonglong *)((longlong)local_84 + 4),0x15);
                  (**(code **)(NvStorOsCBT + 0x118))
                            ((ulonglong *)((longlong)local_84 + 4),lVar5 + 0x14,0x14);
                  bVar3 = (**(code **)(NvStorOsCBT + 0x120))((ulonglong *)((longlong)local_84 + 4));
                  if (bVar3 < 0x14) {
                    pcVar9 = (char *)((longlong)local_84 + (ulonglong)bVar3 + 4);
                    uVar6 = (ulonglong)(byte)(0x14 - bVar3);
                    do {
                      if (*pcVar9 == '\0') {
                        *pcVar9 = ' ';
                      }
                      pcVar9 = pcVar9 + 1;
                      uVar6 = uVar6 - 1;
                    } while (uVar6 != 0);
                  }
                  plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                  uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1c',
                                          (ulonglong *)((longlong)local_84 + 4),0x14);
                  if ((uVar4 & 0x80000000) == 0) {
                    (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x4a6,local_68,0x28);
                    (**(code **)(NvStorOsCBT + 0x118))
                              (param_1 + 0x4ab,(ulonglong *)((longlong)local_84 + 4),0x14);
                    puVar8 = (undefined1 *)(lVar5 + 0x2e);
                    lVar11 = 2;
                    do {
                      lVar10 = lVar11;
                      puVar8[(longlong)(auStackY_b2 + -lVar5)] = puVar8[1];
                      uVar2 = *puVar8;
                      puVar8 = puVar8 + 2;
                      puVar8[(longlong)(auStackY_c8 + (0x15 - lVar5))] = uVar2;
                      lVar11 = lVar10 + -1;
                    } while (lVar11 != 0);
                    uVar12 = (int)lVar10 + 3;
                    plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                    uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1a',
                                            (ulonglong *)(local_88 + 4),uVar12);
                    if ((uVar4 & 0x80000000) == 0) {
                      plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                      uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\x1d',
                                              (ulonglong *)((longlong *)*param_1 + 0x1b),1);
                      if ((uVar4 & 0x80000000) == 0) {
                        local_88[0] = *(byte *)(param_1 + 0x112) & 1;
                        plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                        uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'!',
                                                (ulonglong *)local_88,1);
                        if ((uVar4 & 0x80000000) == 0) {
                          local_88[0] = (byte)(*(uint *)(param_1 + 0x112) >> 0xf) & 1;
                          plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                          uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\"',
                                                  (ulonglong *)local_88,1);
                          if ((uVar4 & 0x80000000) == 0) {
                            NvCfgElementGet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                                            *(longlong **)(*(longlong *)*param_1 + 0x2830),'\n',
                                            (undefined8 *)local_88,1);
                            if (local_88[0] != 0) {
                              local_88[0] = (byte)(*(uint *)(param_1 + 0x112) >> 0xe) & 1;
                            }
                            plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                            uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'#',
                                                    (ulonglong *)local_88,1);
                            if ((uVar4 & 0x80000000) == 0) {
                              NvCfgElementGet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                                              *(longlong **)(*(longlong *)*param_1 + 0x2830),'\v',
                                              (undefined8 *)local_88,1);
                              if (local_88[0] != 0) {
                                local_88[0] = (byte)((ulonglong)param_1[0x112] >> 0x18) >> 1 & 1;
                              }
                              plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                              uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'%',
                                                      (ulonglong *)local_88,1);
                              if ((uVar4 & 0x80000000) == 0) {
                                local_88[0] = *(byte *)(param_1 + 0x112) >> 7;
                                plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'&',
                                                        (ulonglong *)local_88,1);
                                if ((uVar4 & 0x80000000) == 0) {
                                  local_88[0] = (byte)(*(uint *)(param_1 + 0x112) >> 0xb) & 1;
                                  plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                  uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'\'',
                                                          (ulonglong *)local_88,1);
                                  if ((uVar4 & 0x80000000) == 0) {
                                    local_88[0] = (byte)(*(uint *)(param_1 + 0x112) >> 0xc) & 1;
                                    plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                    uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,'('
                                                            ,(ulonglong *)local_88,1);
                                    if ((uVar4 & 0x80000000) == 0) {
                                      local_88[0] = (byte)((ulonglong)param_1[0x112] >> 0x24) & 1;
                                      plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                      uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1,
                                                              'B',(ulonglong *)local_88,1);
                                      if ((uVar4 & 0x80000000) == 0) {
                                        local_88[0] = (byte)((ulonglong)param_1[0x112] >> 0x26) & 1;
                                        plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                        uVar4 = NvCfgElementSet((longlong)plVar7,(longlong *)*plVar1
                                                                ,'E',(ulonglong *)local_88,1);
                                        if ((uVar4 & 0x80000000) == 0) {
                                          local_88[0] = (byte)((ulonglong)param_1[0x112] >> 0x28) &
                                                        1;
                                          plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                          uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                  (longlong *)*plVar1,'G',
                                                                  (ulonglong *)local_88,1);
                                          if ((uVar4 & 0x80000000) == 0) {
                                            local_88[0] = (byte)((ulonglong)param_1[0x112] >> 0x2a)
                                                          & 1;
                                            plVar7 = *(longlong **)(*(longlong *)*param_1 + 0x2820);
                                            uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                    (longlong *)*plVar1,'I',
                                                                    (ulonglong *)local_88,1);
                                            if ((uVar4 & 0x80000000) == 0) {
                                              local_88[0] = (byte)(*(uint *)(param_1 + 0x112) >> 0xd
                                                                  ) & 1;
                                              plVar7 = *(longlong **)
                                                        (*(longlong *)*param_1 + 0x2820);
                                              uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                      (longlong *)*plVar1,')',
                                                                      (ulonglong *)local_88,1);
                                              if ((uVar4 & 0x80000000) == 0) {
                                                plVar7 = *(longlong **)
                                                          (*(longlong *)*param_1 + 0x2820);
                                                local_88[0] = *(byte *)(*(longlong *)*param_1 +
                                                                       0x2818) >> 3 & 1;
                                                uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                        (longlong *)*plVar1,'*',
                                                                        (ulonglong *)local_88,1);
                                                if ((uVar4 & 0x80000000) == 0) {
                                                  plVar7 = *(longlong **)
                                                            (*(longlong *)*param_1 + 0x2820);
                                                  uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                          (longlong *)*plVar1,'+',
                                                                          (ulonglong *)
                                                                          (param_1[1] + 0x1c),1);
                                                  if ((uVar4 & 0x80000000) == 0) {
                                                    plVar7 = *(longlong **)
                                                              (*(longlong *)*param_1 + 0x2820);
                                                    uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                            (longlong *)*plVar1,',',
                                                                            (ulonglong *)
                                                                            (param_1[1] + 0x1d),1);
                                                    if ((uVar4 & 0x80000000) == 0) {
                                                      plVar7 = *(longlong **)
                                                                (*(longlong *)*param_1 + 0x2820);
                                                      uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                              (longlong *)*plVar1,
                                                                              '-',(ulonglong *)
                                                                                  (param_1 + 5),
                                                                              uVar12);
                                                      if ((uVar4 & 0x80000000) == 0) {
                                                        plVar7 = *(longlong **)
                                                                  (*(longlong *)*param_1 + 0x2820);
                                                        uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                                (longlong *)*plVar1,
                                                                                '.',(ulonglong *)
                                                                                    ((longlong)
                                                                                     param_1 + 0x2c)
                                                                                ,uVar12);
                                                        if ((uVar4 & 0x80000000) == 0) {
                                                          plVar7 = *(longlong **)
                                                                    (*(longlong *)*param_1 + 0x2820)
                                                          ;
                                                          uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                                  (longlong *)
                                                                                  *plVar1,'/',
                                                                                  (ulonglong *)
                                                                                  (param_1 + 3),
                                                                                  uVar12);
                                                          if ((uVar4 & 0x80000000) == 0) {
                                                            plVar7 = *(longlong **)
                                                                      (*(longlong *)*param_1 +
                                                                      0x2820);
                                                            uVar4 = NvCfgElementSet((longlong)plVar7
                                                                                    ,(longlong *)
                                                                                     *plVar1,'0',
                                                                                    (ulonglong *)
                                                                                    ((longlong)
                                                                                     param_1 + 0x1c)
                                                                                    ,uVar12);
                                                            if ((uVar4 & 0x80000000) == 0) {
                                                              plVar7 = *(longlong **)
                                                                        (*(longlong *)*param_1 +
                                                                        0x2820);
                                                              uVar4 = NvCfgElementSet((longlong)
                                                                                      plVar7,(
                                                  longlong *)*plVar1,'1',(ulonglong *)(param_1 + 4),
                                                  uVar12);
                                                  if ((uVar4 & 0x80000000) == 0) {
                                                    plVar7 = *(longlong **)
                                                              (*(longlong *)*param_1 + 0x2820);
                                                    uVar4 = NvCfgElementSet((longlong)plVar7,
                                                                            (longlong *)*plVar1,'5',
                                                                            (ulonglong *)
                                                                            ((longlong)param_1 +
                                                                            0x8a4),uVar12);
                                                    if (((uVar4 & 0x80000000) == 0) &&
                                                       ((*(code **)(*(longlong *)*param_1 + 0x2788)
                                                         == (code *)0x0 ||
                                                        (plVar7 = param_1,
                                                        uVar4 = (**(code **)(*(longlong *)*param_1 +
                                                                            0x2788))(),
                                                        (uVar4 & 0x80000000) == 0)))) {
                                                      param_1[0x112] = param_1[0x112] | 0x100000000;
                                                      if (*(code **)(*(longlong *)*param_1 + 0x2790)
                                                          != (code *)0x0) {
                                                        uVar4 = (**(code **)(*(longlong *)*param_1 +
                                                                            0x2790))(param_1);
                                                      }
                                                      param_1[0x112] =
                                                           param_1[0x112] & 0xfffffffdffffffff;
                                                      return (ulonglong)uVar4;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00012863:
  NvCfgEntityObserverDestroy(plVar7,(longlong *)param_1[0xb7]);
  NvCfgEntityObserverDestroy(plVar7,(longlong *)param_1[0xb8]);
  uVar6 = NvCfgEntityDestroy(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6]
                            );
  if (param_1[0xd3] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0xd3],1);
    param_1[0xd3] = 0;
  }
  return uVar6 & 0xffffffff;
}



===== NvStorDeviceStop @ 000128ec =====

ulonglong NvStorDeviceStop(undefined8 *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  puVar3 = param_1;
  if (*(code **)(*(longlong *)*param_1 + 0x27a0) != (code *)0x0) {
    uVar1 = (**(code **)(*(longlong *)*param_1 + 0x27a0))();
    uVar2 = (ulonglong)uVar1;
  }
  if ((param_1[0x112] & 0x100000000) != 0) {
    NvCfgEntityObserverDestroy(puVar3,(longlong *)param_1[0xb7]);
    NvCfgEntityObserverDestroy(puVar3,(longlong *)param_1[0xb8]);
    uVar2 = NvCfgEntityDestroy(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                               (longlong *)param_1[0xb6]);
    uVar2 = uVar2 & 0xffffffff;
    param_1[0x112] = param_1[0x112] & 0xfffffffeffffffff;
  }
  if (param_1[0xd3] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0xd3],1);
    param_1[0xd3] = 0;
  }
  return uVar2;
}



===== NvStorInitializeScsi @ 000129a0 =====

undefined8 NvStorInitializeScsi(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0x80000003;
  }
  else {
    bVar1 = *(byte *)(param_2 + 0x40);
    if (((bVar1 == 8) || (bVar1 == 0x28)) ||
       (((byte)(bVar1 + 0x78) < 0x37 &&
        ((0x42000100000001U >> ((ulonglong)(bVar1 + 0x78) & 0x3f) & 1) != 0)))) {
      *(undefined4 *)(param_2 + 0xd8) = 0;
    }
    else if ((((bVar1 < 0x2f) && ((0x440000000400U >> ((ulonglong)bVar1 & 0x3f) & 1) != 0)) ||
             (bVar1 == 0xaa)) || (bVar1 == 0x8a)) {
      *(undefined4 *)(param_2 + 0xd8) = 1;
    }
    uVar2 = NvStorScsiGetBlockCount((byte *)(param_2 + 0x40));
    *(uint *)(param_2 + 0xdc) = uVar2;
    uVar3 = (**(code **)(NvStorOsCBT + 0x138))();
    *(longlong *)(param_2 + 0x10) = param_1;
    *(undefined8 *)(param_2 + 0xe0) = uVar3;
    uVar3 = (**(code **)(param_1 + 0x368))(param_2);
  }
  return uVar3;
}



===== NvStorPortReset @ 00012a50 =====

void NvStorPortReset(longlong *param_1)

{
  undefined1 uVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  byte bVar6;
  undefined1 local_28 [32];
  
  bVar6 = 0;
  if ((short)param_1[2] != 0) {
    do {
      if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_00012aa5:
        plVar2 = (longlong *)param_1[(ulonglong)bVar6 + 1];
        if ((plVar2 != (longlong *)0x0) &&
           (((*(uint *)(*param_1 + 0x2818) & 2) == 0 || ((plVar2[0x112] & 0x400000000U) == 0)))) {
          (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*plVar2,2,0,local_28);
          iVar4 = (*(code *)plVar2[0x71])(plVar2);
          (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*plVar2,2,0,local_28);
          if (((*(uint *)(*(longlong *)*plVar2 + 0x25f0) & 1) != 0) &&
             ((*(byte *)(plVar2 + 0x112) & 0x20) != 0)) {
            *(byte *)(plVar2 + 0x113) = *(byte *)(plVar2 + 0x113) | 1;
            if (*(code **)(NvStorOsCBT + 0x210) != (code *)0x0) {
              (**(code **)(NvStorOsCBT + 0x210))(plVar2,0xf);
            }
          }
          if (iVar4 == 0) {
            if ((plVar2[0x112] & 0x4000000000000U) == 0) goto LAB_00012bb7;
            uVar1 = (undefined1)param_1[0x1b];
            lVar5 = *param_1;
          }
          else {
            plVar2[0x112] = plVar2[0x112] | 0x1000000;
            param_1[(ulonglong)*(byte *)((longlong)plVar2 + 0x222) + 1] = 0;
            uVar1 = (undefined1)((longlong *)*plVar2)[0x1b];
            lVar5 = *(longlong *)*plVar2;
          }
          (**(code **)(NvStorOsCBT + 0x188))(lVar5,uVar1);
        }
      }
      else {
        cVar3 = (**(code **)(NvStorOsCBT + 0x208))(param_1,bVar6,1);
        if (cVar3 != '\0') goto LAB_00012aa5;
      }
LAB_00012bb7:
      bVar6 = bVar6 + 1;
    } while ((ushort)bVar6 < *(ushort *)(param_1 + 2));
  }
  return;
}



===== NvStorPrepareLinkedRequest @ 00012be4 =====

void NvStorPrepareLinkedRequest(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = (**(code **)(NvStorOsCBT + 0x100))
                    (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),0x104,2);
  if (lVar3 != 0) {
    (**(code **)(NvStorOsCBT + 0x110))(lVar3,0x104);
    *(undefined8 *)(lVar3 + 0xd0) = 0;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(lVar3 + 0x30) = 0;
    *(undefined4 *)(lVar3 + 0x2c) = 0;
    lVar2 = NvStorOsCBT;
    *(undefined8 *)(lVar3 + 0x10) = uVar4;
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
    *(longlong *)(lVar3 + 0x68) = param_1;
    *(undefined4 *)(lVar3 + 0x1c) = uVar1;
    uVar4 = (**(code **)(lVar2 + 0x1b0))(lVar3);
    *(undefined4 *)(lVar3 + 0x84) = 0xffffffff;
    *(uint *)(lVar3 + 0xc0) = *(uint *)(lVar3 + 0xc0) | 0x50000;
    *(undefined8 *)(lVar3 + 200) = uVar4;
    *(longlong *)(param_1 + 0x70) = lVar3;
  }
  return;
}



===== NvStorDisableInterruptsGlobal @ 00012c8c =====

undefined8 NvStorDisableInterruptsGlobal(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong *plVar4;
  byte bVar5;
  
  if (param_1 == 0) {
    uVar2 = 0x80000003;
  }
  else {
    if ((*(uint *)(param_1 + 0x25f0) & 0x1000) == 0) {
      bVar5 = 0;
      if (*(char *)(param_1 + 0x2500) != '\0') {
        do {
          plVar4 = (longlong *)((ulonglong)bVar5 * 0x128 + param_1);
          if ((plVar4 != (longlong *)0x0) && (bVar3 = 0, (short)plVar4[2] != 0)) {
            do {
              uVar1 = NvStorSataInterruptGetAppropriateMask(plVar4,bVar3);
              NvStorSataInterruptEnableDisableByMask(plVar4,bVar3,'\0',uVar1);
              bVar3 = bVar3 + 1;
            } while ((ushort)bVar3 < *(ushort *)(plVar4 + 2));
          }
          bVar5 = bVar5 + 1;
        } while (bVar5 < *(byte *)(param_1 + 0x2500));
      }
    }
    else {
      NvStorAhciDisableInterruptsGlobal(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== NvStorWaitForRequestCompletion @ 00012d44 =====

ulonglong NvStorWaitForRequestCompletion(longlong *param_1,undefined8 param_2,uint param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)*param_1;
  if (lVar1 == 0) {
    uVar3 = 0x80000003;
  }
  else if ((*(uint *)(lVar1 + 0x25f0) >> 0xc & 1) == 0) {
    uVar3 = NvStorNonIntWaitOnPortStatus((longlong *)*param_1,0x80,0);
    puVar2 = (undefined8 *)*param_1;
    (**(code **)(NvStorOsCBT + 0x60))
              (*puVar2,(ushort)*(byte *)(puVar2 + 0x1b) * 8 + *(short *)(puVar2 + 0xb),0);
    uVar3 = (ulonglong)(-(uint)((uVar3 & 0x80) != 0) & 0x80000006);
  }
  else {
    uVar3 = NvStorAhciWaitForRequestCompletion(param_1,param_2,param_3);
  }
  return uVar3;
}



===== NvStorRaidMetaDataIo @ 00012dc0 =====

ulonglong NvStorRaidMetaDataIo
                    (undefined8 *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    undefined8 param_5,int param_6,char param_7)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 local_38 [32];
  
  (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_38);
  param_1[0x112] = param_1[0x112] | 0x40000000;
  (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*param_1,2,0,local_38);
  plVar1 = param_1 + 0xd4;
  uVar3 = param_1[0xed];
  (**(code **)(NvStorOsCBT + 0x110))(plVar1,0xf0);
  param_1[0xed] = uVar3;
  lVar6 = NvStorOsCBT;
  if (param_6 == 0) {
    *(undefined1 *)(param_1 + 0xdc) = 0x88;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 1;
  }
  else {
    *(undefined1 *)(param_1 + 0xdc) = 0x8a;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xfffffffe;
    if (param_7 == '\0') {
      (**(code **)(lVar6 + 0x110))(param_2,6);
    }
    else {
      (**(code **)(lVar6 + 0x118))(param_2,&s_NVIDIA,6);
    }
  }
  *(undefined4 *)((longlong)param_1 + 0x6ea) = 0x2000000;
  lVar6 = param_1[0x45] + -1;
  *(char *)((longlong)param_1 + 0x6e9) = (char)lVar6;
  *(char *)((longlong)param_1 + 0x6e2) = (char)((ulonglong)lVar6 >> 0x38);
  *(char *)((longlong)param_1 + 0x6e3) = (char)((ulonglong)lVar6 >> 0x30);
  *(char *)((longlong)param_1 + 0x6e4) = (char)((ulonglong)lVar6 >> 0x28);
  *(char *)((longlong)param_1 + 0x6e5) = (char)((ulonglong)lVar6 >> 0x20);
  *(char *)((longlong)param_1 + 0x6e6) = (char)((ulonglong)lVar6 >> 0x18);
  *(char *)((longlong)param_1 + 0x6e7) = (char)((ulonglong)lVar6 >> 0x10);
  *(char *)(param_1 + 0xdd) = (char)((ulonglong)lVar6 >> 8);
  param_1[0xd8] = param_3;
  param_1[0xd6] = param_1;
  param_1[0xda] = 0;
  uVar2 = *(undefined4 *)(param_3 + 0x18);
  *(undefined4 *)((longlong)param_1 + 0x724) = 0xffffffff;
  *(undefined4 *)((longlong)param_1 + 0x6cc) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x6bc) = 10;
  *(undefined4 *)(param_1 + 0xe6) = 1;
  param_1[0xea] = param_4;
  param_1[0xe1] = param_5;
  uVar4 = (**(code **)(*(longlong *)*param_1 + 0x27b0))(plVar1);
  uVar7 = (ulonglong)uVar4;
  if (uVar4 == 1) {
    uVar5 = NvStorInitializeScsi((longlong)param_1,(longlong)plVar1);
    uVar7 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 1) {
      uVar4 = NvStorReqQueueInsert(param_1[0xd6] + 0x1a8,plVar1);
      if (-1 < (int)uVar4) {
        return uVar7;
      }
      uVar7 = (ulonglong)uVar4;
      if (uVar4 == 1) {
        return 1;
      }
    }
  }
  param_1[0x112] = param_1[0x112] & 0xffffffffbfffffff;
  return uVar7;
}



===== NvStorCompleteSSFRequest @ 00012fb0 =====

void NvStorCompleteSSFRequest(longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  
  if (*(longlong *)(param_1 + 200) != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(param_2);
    *(undefined8 *)(param_1 + 200) = 0;
  }
  puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
  *puVar1 = *puVar1 & 0xffefffffffffffff;
  return;
}



===== NvStorDeviceBuildIdentifyString @ 00012ffc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorDeviceBuildIdentifyString(longlong param_1,longlong param_2)

{
  byte bVar1;
  ulonglong uVar2;
  char *pcVar3;
  undefined1 auStack_78 [32];
  char local_58 [24];
  char local_40 [48];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  (**(code **)(NvStorOsCBT + 0x110))(local_40,0x29);
  (**(code **)(NvStorOsCBT + 0x118))(local_40,param_2 + 0x36,0x28);
  bVar1 = (**(code **)(NvStorOsCBT + 0x120))(local_40);
  if (bVar1 < 0x28) {
    pcVar3 = local_40 + bVar1;
    uVar2 = (ulonglong)(byte)(0x28 - bVar1);
    do {
      if (*pcVar3 == '\0') {
        *pcVar3 = ' ';
      }
      pcVar3 = pcVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  (**(code **)(NvStorOsCBT + 0x110))(local_58,0x15);
  (**(code **)(NvStorOsCBT + 0x118))(local_58,param_2 + 0x14,0x14);
  bVar1 = (**(code **)(NvStorOsCBT + 0x120))(local_58);
  if (bVar1 < 0x14) {
    pcVar3 = local_58 + bVar1;
    uVar2 = (ulonglong)(byte)(0x14 - bVar1);
    do {
      if (*pcVar3 == '\0') {
        *pcVar3 = ' ';
      }
      pcVar3 = pcVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x2530,local_40,0x28);
  (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x2558,local_58,0x14);
  return 0;
}



===== NvStorGetDeviceQuirks @ 00013150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * NvStorGetDeviceQuirks(byte *param_1,byte *param_2,byte *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  byte *pbVar3;
  int iVar4;
  ulonglong uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar6 = 0;
  if ((_DAT_0002f2f4 & 0x80000000) == 0) {
    puVar7 = (uint *)&DAT_0002f2f4;
    do {
      puVar7 = puVar7 + 9;
      iVar6 = iVar6 + 1;
    } while ((*puVar7 & 0x80000000) == 0);
    if (iVar6 < 0) {
      return (byte *)0x0;
    }
  }
  do {
    lVar2 = (longlong)iVar6 * 0x24;
    pbVar3 = &DeviceQuirksList + lVar2;
    iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar3);
    if (iVar4 == 0) {
LAB_000131e2:
      pbVar1 = (byte *)(lVar2 + 0x2f2b8);
      iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar1);
      if (iVar4 != 0) {
        iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar1);
        uVar5 = NvStorUtilStrNCmp(pbVar1,param_2,iVar4);
        if ((char)uVar5 != '\0') goto LAB_00013256;
      }
      pbVar1 = (byte *)(lVar2 + 0x2f2c8);
      iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar1);
      if (iVar4 == 0) {
        return pbVar3;
      }
      iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar1);
      uVar5 = NvStorUtilStrNCmp(pbVar1,param_3,iVar4);
      if ((char)uVar5 == '\0') {
        return pbVar3;
      }
    }
    else {
      iVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar3);
      uVar5 = NvStorUtilStrNCmp(pbVar3,param_1,iVar4);
      if ((char)uVar5 == '\0') goto LAB_000131e2;
    }
LAB_00013256:
    iVar6 = iVar6 + -1;
    if (iVar6 < 0) {
      return (byte *)0x0;
    }
  } while( true );
}



===== NvStorScsiGetLBA @ 00013280 =====

ulonglong NvStorScsiGetLBA(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  
  bVar1 = *param_1;
  if (((byte)(bVar1 + 0x78) < 8) && ((0x85U >> (bVar1 + 0x78 & 0x1f) & 1) != 0)) {
    bVar1 = param_1[9];
    uVar3 = (ulonglong)
            CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(param_1[2],param_1[3]),param_1[4])
                                                ,param_1[5]),param_1[6]),param_1[7]),param_1[8]) <<
            8;
  }
  else {
    if ((bVar1 + 0x58 & 0xfd) == 0) {
      return (ulonglong)CONCAT31(CONCAT21(CONCAT11(param_1[2],param_1[3]),param_1[4]),param_1[5]);
    }
    if ((bVar1 < 0x30) && ((0x850000000000U >> ((ulonglong)bVar1 & 0x3f) & 1) != 0)) {
      uVar2 = (uint)CONCAT21(CONCAT11(param_1[2],param_1[3]),param_1[4]);
      bVar1 = param_1[5];
    }
    else {
      uVar2 = (uint)param_1[2];
      bVar1 = param_1[3];
    }
    uVar3 = (ulonglong)(uVar2 << 8);
  }
  return uVar3 | bVar1;
}



===== NvStorScsiGetBlockCount @ 00013364 =====

uint NvStorScsiGetBlockCount(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_1;
  if (((byte)(bVar1 + 0x78) < 8) && ((0x85U >> (bVar1 + 0x78 & 0x1f) & 1) != 0)) {
    uVar2 = (uint)CONCAT21(CONCAT11(param_1[10],param_1[0xb]),param_1[0xc]);
    bVar1 = param_1[0xd];
  }
  else {
    if ((bVar1 + 0x58 & 0xfd) == 0) {
      return CONCAT31(CONCAT21(CONCAT11(param_1[6],param_1[7]),param_1[8]),param_1[9]);
    }
    if ((0x2f < bVar1) || ((0x850000000000U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0)) {
      return (uint)param_1[4];
    }
    uVar2 = (uint)param_1[7];
    bVar1 = param_1[8];
  }
  return uVar2 << 8 | (uint)bVar1;
}



===== NvStorScsiBuildInquiryPage @ 000133f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorScsiBuildInquiryPage(char *param_1,byte *param_2,longlong param_3,byte param_4)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  longlong lVar5;
  longlong lVar6;
  char acStack_6e [14];
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  undefined1 local_38 [8];
  undefined1 local_30 [16];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  if (*param_1 < '\0') {
    param_2[1] = param_2[1] | 0x80;
  }
  param_2[7] = param_2[7] | 2;
  param_2[2] = 6;
  param_2[4] = 0x1f;
  pcVar3 = param_1 + 0x36;
  param_2[3] = param_2[3] & 0xf2 | 0x12;
  lVar6 = 10;
  do {
    lVar5 = lVar6;
    pcVar3[(longlong)(acStack_6e + -(longlong)param_1)] = pcVar3[1];
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 2;
    pcVar3[(longlong)(acStack_6e + (-1 - (longlong)param_1))] = cVar1;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  uStack_60 = 0x1348b;
  (**(code **)(NvStorOsCBT + 0x118))(param_3,local_38,(int)lVar5 + 7);
  uStack_60 = 0x134a7;
  (**(code **)(NvStorOsCBT + 0x118))(param_3 + 8,local_30,0xc);
  puVar4 = (undefined1 *)(param_3 + 0x19);
  *(undefined4 *)(param_3 + 0x14) = 0x20202020;
  lVar6 = 2;
  do {
    puVar4[-1] = puVar4[(longlong)(param_1 + (0x16 - param_3))];
    *puVar4 = puVar4[(longlong)(param_1 + (0x15 - param_3))];
    lVar5 = NvStorOsCBT;
    puVar4 = puVar4 + 2;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  if ((param_4 & 1) == 0) {
    *param_2 = *param_2 & 0xe0;
    uStack_60 = 0x13561;
    (**(code **)(lVar5 + 0x118))(param_2 + 8,param_3,8);
    uStack_60 = 0x1357c;
    (**(code **)(NvStorOsCBT + 0x118))(param_2 + 0x10,param_3 + 8,0x10);
    uStack_60 = 0x13597;
    (**(code **)(NvStorOsCBT + 0x118))(param_2 + 0x20,param_3 + 0x18,4);
  }
  else {
    pcVar3 = "Raid Disk";
    *param_2 = *param_2 & 0xec | 0xc;
    if ((param_4 & 2) == 0) {
      pcVar3 = "Raid Disk 20";
    }
    uStack_60 = 0x1350e;
    uVar2 = (**(code **)(lVar5 + 0x120))(&s_NVIDIA);
    uStack_60 = 0x13522;
    (**(code **)(lVar5 + 0x118))(param_2 + 8,&s_NVIDIA,uVar2);
    lVar6 = NvStorOsCBT;
    uStack_60 = 0x13532;
    uVar2 = (**(code **)(NvStorOsCBT + 0x120))(pcVar3);
    uStack_60 = 0x13542;
    (**(code **)(lVar6 + 0x118))(param_2 + 0x10,pcVar3,uVar2);
  }
  return;
}



===== NvStorScsiPrintDeviceSummary @ 000135b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorScsiPrintDeviceSummary(longlong param_1)

{
  undefined1 auStack_48 [32];
  undefined1 local_28 [8];
  undefined1 local_20;
  undefined1 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  (**(code **)(NvStorOsCBT + 0x118))(local_28,param_1 + 0x38,8);
  local_20 = 0;
  (**(code **)(NvStorOsCBT + 0x118))(local_28,param_1 + 0x40,0x10);
  local_18 = 0;
  (**(code **)(NvStorOsCBT + 0x118))(local_28,param_1 + 0x50,4);
  return;
}



===== NvStorScsiBuildSenseData @ 00013644 =====

void NvStorScsiBuildSenseData(longlong param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  undefined1 *puVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  
  *(undefined4 *)(param_1 + 0x88) = param_2;
  *(undefined2 *)(param_1 + 0x8c) = 0x102;
  puVar2 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
  iVar5 = 0;
  (**(code **)(NvStorOsCBT + 0x110))(puVar2,0xff);
  puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
  *puVar1 = *puVar1 | 0x100000;
  *puVar2 = 0xf0;
  puVar2[7] = 0xb;
  if ((*(uint *)(param_1 + 0xc0) >> 0x13 & 1) == 0) {
    puVar2[2] = puVar2[2] & 0xf0;
  }
  else {
    iVar5 = 6;
    puVar2[2] = puVar2[2] & 0xfb | 0xb;
  }
  *(undefined2 *)(puVar2 + 0xc) = 0;
  bVar4 = *(byte *)(param_1 + 0x18);
  if ((bVar4 & 8) != 0) {
    *(undefined2 *)(puVar2 + 0xc) = 0x15a;
    puVar2[2] = puVar2[2] & 0xf6 | 6;
    goto LAB_00013783;
  }
  if ((bVar4 & 4) == 0) {
    if ((bVar4 & 2) == 0) {
      if ((bVar4 & 1) == 0) {
        if ((char)bVar4 < '\0') {
          bVar4 = puVar2[2] & 0xf4 | 4;
        }
        else {
          if ((bVar4 & 0x10) != 0) {
            puVar2[0xc] = 0x21;
            bVar4 = puVar2[2] & 0xf5 | 5;
            goto LAB_00013742;
          }
          if ((bVar4 & 0x20) != 0) {
            puVar2[0xc] = 0x28;
            puVar2[2] = puVar2[2] & 0xf6 | 6;
            goto LAB_00013783;
          }
          if ((bVar4 & 0x40) == 0) {
            *(undefined2 *)(param_1 + 0x8c) = 0;
            iVar5 = 7;
            goto LAB_00013783;
          }
          bVar4 = puVar2[2] & 0xf3 | 3;
        }
        goto LAB_0001376b;
      }
      *(undefined4 *)(param_1 + 0x88) = 0x80000007;
    }
    else {
      puVar2[0xc] = 0x3a;
      bVar4 = puVar2[2] & 0xf2 | 2;
LAB_00013742:
      puVar2[2] = bVar4;
    }
    iVar5 = 3;
  }
  else {
    if (-1 < (char)bVar4) {
      iVar5 = 2;
      puVar2[2] = puVar2[2] & 0xfb | 0xb;
      goto LAB_00013783;
    }
    *(undefined2 *)(puVar2 + 0xc) = 0x308;
    bVar4 = puVar2[2] & 0xf4 | 4;
LAB_0001376b:
    puVar2[2] = bVar4;
    iVar5 = 1;
  }
LAB_00013783:
  lVar3 = NvStorOsCBT;
  *(undefined1 *)(param_1 + 0x78) = 0x12;
  if ((*(code **)(lVar3 + 0x1e8) != (code *)0x0) && (iVar5 != 0)) {
    (**(code **)(lVar3 + 0x1e8))(*(undefined8 *)(param_1 + 0x10),param_1,iVar5);
  }
  return;
}



===== NvStorScsiInquiry @ 000137bc =====

undefined8 NvStorScsiInquiry(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined1 *puVar5;
  longlong lVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  
  puVar3 = *(undefined8 **)(param_1 + 0x10);
  uVar12 = *(uint *)(param_1 + 0x2c);
  puVar5 = (undefined1 *)puVar3[0x33];
  if (uVar12 == 0) {
    return 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x30);
  if (lVar4 == 0) {
    return 0x80000008;
  }
  cVar1 = *(char *)(param_1 + 0x42);
  if (cVar1 == '\0') {
    if ((*(byte *)(param_1 + 0x41) & 1) != 0) goto LAB_00013872;
    (**(code **)(NvStorOsCBT + 0x110))(lVar4);
    uVar9 = 0x24;
    if (*(uint *)(param_1 + 0x2c) < 0x24) {
      uVar9 = *(undefined4 *)(param_1 + 0x2c);
    }
    (**(code **)(NvStorOsCBT + 0x118))(lVar4,*(longlong *)(param_1 + 0x10) + 0x30,uVar9);
    uVar9 = 0x24;
    if (*(uint *)(param_1 + 0x2c) < 0x24) {
      uVar9 = *(undefined4 *)(param_1 + 0x2c);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x41) & 1) == 0) goto LAB_00013811;
LAB_00013872:
    if (cVar1 == '\0') {
      if ((*(char *)(*(longlong *)*puVar3 + 0x28d9) == '\0') &&
         ((*(uint *)(*(longlong *)*puVar3 + 0x25f0) & 0x1000000) != 0)) {
        iVar8 = 2;
      }
      else {
        iVar8 = 3;
      }
      if (uVar12 < iVar8 + 5U) {
        return 0x80000008;
      }
      (**(code **)(NvStorOsCBT + 0x110))(lVar4,iVar8 + 5);
      *(char *)(lVar4 + 3) = (char)iVar8 + '\x01';
      *(undefined2 *)(lVar4 + 4) = 0x8000;
      *(undefined1 *)(lVar4 + 6) = 0x83;
      if ((*(char *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x28d9) != '\0') ||
         ((*(uint *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x25f0) >> 0x18 & 1) == 0)) {
        *(undefined1 *)(lVar4 + 7) = 0x89;
      }
      *(int *)(param_1 + 0x28) = iVar8 + 5;
      goto LAB_00013b45;
    }
    if (cVar1 == -0x80) {
      if ((*(char *)(*(longlong *)*puVar3 + 0x28d9) == '\0') &&
         ((*(uint *)(*(longlong *)*puVar3 + 0x25f0) & 0x1000000) != 0)) {
LAB_00013811:
        *(undefined4 *)(param_1 + 0x88) = 0x80000008;
        *(undefined1 *)(param_1 + 0x8c) = 2;
        if (puVar5 != (undefined1 *)0x0) {
          (**(code **)(NvStorOsCBT + 0x110))(puVar5,0x12);
          *puVar5 = 0xf0;
          puVar5[7] = 0xb;
          *(undefined2 *)(puVar5 + 0xc) = 0x24;
          puVar5[2] = puVar5[2] & 0xf5 | 5;
          *(undefined1 *)(param_1 + 0x78) = 0x12;
          *(undefined1 *)(param_1 + 0x8d) = 1;
        }
        return 0x80000008;
      }
      if (uVar12 < 0x18) {
        return 0x80000008;
      }
      (**(code **)(NvStorOsCBT + 0x110))(lVar4,0x18);
      lVar6 = 10;
      *(undefined1 *)(lVar4 + 1) = 0x80;
      *(undefined1 *)(lVar4 + 3) = 0x14;
      puVar5 = (undefined1 *)(lVar4 + 4);
      do {
        *puVar5 = puVar5[(param_2 - lVar4) + 0x11];
        puVar5[1] = puVar5[(param_2 - lVar4) + 0x10];
        puVar5 = puVar5 + 2;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      *(undefined4 *)(param_1 + 0x28) = 0x18;
      goto LAB_00013b45;
    }
    if (cVar1 == -0x7d) {
      if (*(char *)(param_2 + 0xae) < '\0') {
        if (uVar12 < 0x10) {
          return 0x80000008;
        }
        (**(code **)(NvStorOsCBT + 0x110))(lVar4);
        *(undefined1 *)(lVar4 + 3) = 0xc;
        *(undefined1 *)(lVar4 + 7) = 8;
        puVar5 = (undefined1 *)(lVar4 + 9);
        lVar6 = 2;
        *(byte *)(lVar4 + 4) = *(byte *)(lVar4 + 4) & 0xf1 | 1;
        puVar7 = (undefined1 *)(param_2 + 0xd8);
        *(byte *)(lVar4 + 5) = *(byte *)(lVar4 + 5) & 0xf3 | 3;
        do {
          puVar5[-1] = puVar7[1];
          uVar2 = *puVar7;
          puVar7 = puVar7 + 4;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 2;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
      }
      else {
        if (uVar12 < 0x4c) {
          return 0x80000008;
        }
        (**(code **)(NvStorOsCBT + 0x110))(lVar4);
        *(undefined1 *)(lVar4 + 3) = 0x48;
        *(undefined4 *)(lVar4 + 7) = 0x41544144;
        puVar5 = (undefined1 *)(param_2 + 0x36);
        *(byte *)(lVar4 + 4) = *(byte *)(lVar4 + 4) & 0xf2 | 2;
        *(byte *)(lVar4 + 5) = *(byte *)(lVar4 + 5) & 0xf1 | 1;
        *(undefined4 *)(lVar4 + 0xb) = 0x20202020;
        *(undefined1 *)(lVar4 + 0xf) = 0x20;
        uVar12 = 0;
        do {
          bVar10 = (char)uVar12 + 2;
          *(undefined1 *)((ulonglong)(uVar12 + 8) + 8 + lVar4) = puVar5[1];
          uVar2 = *puVar5;
          puVar5 = puVar5 + 2;
          *(undefined1 *)((ulonglong)(uVar12 + 9) + 8 + lVar4) = uVar2;
          uVar12 = (uint)bVar10;
        } while (bVar10 < 0x28);
        puVar5 = (undefined1 *)(param_2 + 0x14);
        bVar10 = 0;
        do {
          bVar11 = bVar10 + 2;
          *(undefined1 *)((ulonglong)(bVar10 + 0x30) + 8 + lVar4) = puVar5[1];
          uVar2 = *puVar5;
          puVar5 = puVar5 + 2;
          *(undefined1 *)((ulonglong)(bVar10 + 0x31) + 8 + lVar4) = uVar2;
          bVar10 = bVar11;
        } while (bVar11 < 0x14);
      }
      *(undefined1 *)(lVar4 + 1) = 0x83;
      *(uint *)(param_1 + 0x28) = *(byte *)(lVar4 + 3) + 4;
      goto LAB_00013b45;
    }
    if (cVar1 != -0x77) goto LAB_00013811;
    if (uVar12 < 0x23c) {
      return 0x80000008;
    }
    (**(code **)(NvStorOsCBT + 0x110))(lVar4);
    *(undefined2 *)(lVar4 + 2) = 0x3802;
    lVar6 = NvStorOsCBT;
    *(undefined1 *)(lVar4 + 1) = 0x89;
    *(undefined1 *)(lVar4 + 0x38) = 0xec;
    *(undefined1 *)(lVar4 + 0x24) = 0x34;
    (**(code **)(lVar6 + 0x118))(lVar4 + 0x3c,param_2,0x200);
    uVar9 = 0x23c;
  }
  *(undefined4 *)(param_1 + 0x28) = uVar9;
LAB_00013b45:
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  return 0;
}



===== NvStorProtocolAtaNonQueuedCheckQueueDpc @ 00013b70 =====

undefined8 NvStorProtocolAtaNonQueuedCheckQueueDpc(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
  }
  *(char *)(param_1 + 0x6c) = (char)uVar2;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== NvStorProtocolAtaNonQueuedHandleInterrupt @ 00013bb8 =====

void NvStorProtocolAtaNonQueuedHandleInterrupt(longlong *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x15] == 0) {
    iVar3 = (**(code **)(NvStorOsCBT + 0x10))
                      (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 0x40 + 4 + (short)puVar1[0xf]);
  }
  else {
    iVar3 = (**(code **)(NvStorOsCBT + 0x40))
                      (*puVar1,(longlong)(int)((uint)*(byte *)(puVar1 + 0x1b) * 0x40 + 4) +
                               puVar1[0x15]);
  }
  if (iVar3 != 0) {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x15] == 0) {
      (**(code **)(NvStorOsCBT + 0x70))
                (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 0x40 + (short)puVar1[0xf] + 4,iVar3);
    }
    else {
      (**(code **)(NvStorOsCBT + 0xa0))
                (*puVar1,(longlong)(int)((uint)*(byte *)(puVar1 + 0x1b) * 0x40 + 4) + puVar1[0x15]);
    }
  }
  if ((param_1[0x48] != 0) && (pcVar2 = *(code **)(param_1[0x48] + 0xb8), pcVar2 != (code *)0x0)) {
    (*pcVar2)(param_1);
  }
  return;
}



===== NvStorProtocolAtaNonDataIssueCommand @ 00013ca0 =====

undefined8 NvStorProtocolAtaNonDataIssueCommand(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x18);
  }
  uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if (-1 < (char)uVar3) {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 4);
    }
    NvStorNonIntSendCommandAddressCount(param_1,param_2);
    uVar3 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar3) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      *(code **)(param_2 + 0xb8) = NvStorProtocolAtaNonDataInterrupt;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 7,puVar1[10]);
      }
      else {
        (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x1c);
      }
      return 0;
    }
  }
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000150c4(param_2,-0x7ffffffa);
  return 0x80000006;
}



===== NvStorProtocolAtaNonDataInterrupt @ 00013de8 =====

undefined8 NvStorProtocolAtaNonDataInterrupt(undefined8 *param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if ((*(byte *)(param_1 + 0x6c) & 1) == 0) {
    if ((char)*(byte *)(param_1 + 0x6c) < '\0') {
      uVar2 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      if ((char)uVar2 < '\0') {
        puVar3 = (undefined8 *)*param_1;
        goto LAB_00013e05;
      }
    }
    FUN_000150c4(param_2,0);
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined8 *)*param_1;
LAB_00013e05:
    if (puVar3[0x19] == 0) {
      uVar1 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 1);
    }
    else {
      uVar1 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar1;
    FUN_000150c4(param_2,-0x7ffffffd);
    uVar2 = 0x80000003;
  }
  return uVar2;
}



===== NvStorProtocolAtaPioInIssueCommand @ 00013e78 =====

undefined8 NvStorProtocolAtaPioInIssueCommand(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x18);
  }
  uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if (-1 < (char)uVar3) {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 4);
    }
    NvStorNonIntSendCommandAddressCount(param_1,param_2);
    uVar3 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar3) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      *(code **)(param_2 + 0xb8) = NvStorProtocolAtaPioInInterrupt;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 7,puVar1[10]);
      }
      else {
        (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x1c);
      }
      return 0;
    }
  }
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000150c4(param_2,-0x7ffffffa);
  return 0x80000006;
}



===== NvStorProtocolAtaPioInInterrupt @ 00013fc0 =====

undefined8 NvStorProtocolAtaPioInInterrupt(longlong *param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  uint uVar8;
  
  bVar1 = *(byte *)(param_1 + 0x6c);
  lVar3 = param_1[0x110];
  if ((bVar1 & 1) == 0) {
    if (((char)bVar1 < '\0') || ((bVar1 & 8) == 0)) {
      uVar5 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,8);
      if (((char)uVar5 < '\0') || ((uVar5 & 8) == 0)) {
        puVar7 = (undefined8 *)*param_1;
        goto LAB_000140ae;
      }
    }
    uVar2 = *(uint *)(param_2 + 0x2c);
    uVar8 = (uint)*(byte *)(lVar3 + 0x5e) * (int)param_1[0x46];
    if (uVar2 <= uVar8) {
      uVar8 = uVar2;
    }
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + uVar8;
    *(uint *)(param_2 + 0x2c) = uVar2 - uVar8;
    puVar7 = (undefined8 *)*param_1;
    if (puVar7[0x19] == 0) {
      if ((uVar8 & 1) == 0) {
        (*(code *)NvStorOsCBT[4])();
      }
      else {
        (*(code *)NvStorOsCBT[3])
                  (*puVar7,*(undefined2 *)(puVar7 + 3),
                   (*(longlong *)(param_2 + 0x30) - (ulonglong)uVar8) +
                   (ulonglong)*(uint *)(param_2 + 0x28));
      }
    }
    else {
      (*(code *)NvStorOsCBT[10])(*puVar7);
    }
    if (*(int *)(param_2 + 0x2c) == 0) {
      FUN_000150c4(param_2,0);
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
  }
  else {
    puVar7 = (undefined8 *)*param_1;
LAB_000140ae:
    if (puVar7[0x19] == 0) {
      uVar4 = (*(code *)*NvStorOsCBT)(*puVar7,*(short *)(puVar7 + 3) + 1);
    }
    else {
      uVar4 = (*(code *)NvStorOsCBT[6])(*puVar7,puVar7[0x19] + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar4;
    FUN_000150c4(param_2,-0x7ffffffd);
    uVar6 = 0x80000003;
  }
  return uVar6;
}



===== NvStorProtocolAtaPioOutIssueCommand @ 00014104 =====

int NvStorProtocolAtaPioOutIssueCommand(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int iVar5;
  
  puVar1 = *(undefined1 **)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x18);
  }
  uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if (-1 < (char)uVar3) {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 4);
    }
    NvStorNonIntSendCommandAddressCount(param_1,param_2);
    uVar3 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar3) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 7,puVar1[10]);
      }
      else {
        (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x1c);
      }
      uVar4 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,8);
      if (-1 < (char)uVar4) {
        if ((uVar4 & 8) != 0) {
          *(code **)(param_2 + 0xb8) = NvStorProtocolAtaPioOutInterrupt;
          NvStorProtocolAtaPioOutWriteHelper(param_1,param_2);
          return 0;
        }
        iVar5 = -0x7ffffff7;
        goto LAB_00014172;
      }
    }
  }
  iVar5 = -0x7ffffffa;
LAB_00014172:
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000150c4(param_2,iVar5);
  return iVar5;
}



===== NvStorProtocolAtaPioOutWriteHelper @ 00014278 =====

void NvStorProtocolAtaPioOutWriteHelper(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_1[0x110] + 0x5e) * (int)param_1[0x46];
  puVar1 = (undefined8 *)*param_1;
  if (*(uint *)(param_2 + 0x2c) <= uVar2) {
    uVar2 = *(uint *)(param_2 + 0x2c);
  }
  if (puVar1[0x19] == 0) {
    if ((uVar2 & 1) == 0) {
      (**(code **)(NvStorOsCBT + 0x80))();
    }
    else {
      (**(code **)(NvStorOsCBT + 0x78))
                (*puVar1,*(undefined2 *)(puVar1 + 3),
                 (ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(param_2 + 0x30));
    }
  }
  else {
    (**(code **)(NvStorOsCBT + 0xb0))(*puVar1);
  }
  *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + uVar2;
  *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) - uVar2;
  return;
}



===== NvStorProtocolAtaPioOutInterrupt @ 000142f8 =====

int NvStorProtocolAtaPioOutInterrupt(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  
  lVar1 = param_1[0x110];
  if ((*(byte *)(param_1 + 0x6c) & 1) == 0) {
    if (*(int *)(param_2 + 0x2c) != 0) {
      uVar4 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      if ((char)uVar4 < '\0') {
        iVar5 = -0x7ffffffa;
        goto LAB_0001435d;
      }
      if ((uVar4 & 8) != 0) {
        puVar2 = (undefined8 *)*param_1;
        uVar6 = (uint)*(byte *)(lVar1 + 0x5e) * (int)param_1[0x46];
        if (*(uint *)(param_2 + 0x2c) <= uVar6) {
          uVar6 = *(uint *)(param_2 + 0x2c);
        }
        if (puVar2[0x19] == 0) {
          if ((uVar6 & 1) == 0) {
            (*(code *)NvStorOsCBT[0x10])();
          }
          else {
            (*(code *)NvStorOsCBT[0xf])
                      (*puVar2,*(undefined2 *)(puVar2 + 3),
                       (ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(param_2 + 0x30));
          }
        }
        else {
          (*(code *)NvStorOsCBT[0x16])(*puVar2);
        }
        *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + uVar6;
        *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) - uVar6;
        return 1;
      }
    }
    FUN_000150c4(param_2,0);
    iVar5 = 0;
  }
  else {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      uVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 1);
    }
    else {
      uVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar3;
    iVar5 = -0x7ffffffd;
LAB_0001435d:
    FUN_000150c4(param_2,iVar5);
  }
  return iVar5;
}



===== NvStorProtocolAtaDmaIssueCommand @ 00014428 =====

undefined8 NvStorProtocolAtaDmaIssueCommand(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6,*(undefined1 *)(lVar1 + 9));
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
  }
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    cVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
  }
  else {
    cVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
  }
  if (-1 < cVar3) {
    NvStorNonIntSendCommandAddressCount(param_1,param_2);
    uVar4 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar4) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      *(code **)(param_2 + 0xb8) = NvStorProtocolAtaDmaInterrupt;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 7,*(undefined1 *)(lVar1 + 10));
      }
      else {
        (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x1c);
      }
      NvStorNonIntBuildAndStartPrd(param_1,param_2);
      return 0;
    }
  }
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000150c4(param_2,-0x7ffffffa);
  return 0x80000006;
}



===== NvStorProtocolAtaDmaInterrupt @ 00014564 =====

undefined8 NvStorProtocolAtaDmaInterrupt(longlong *param_1,longlong param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  (*(code *)NvStorOsCBT[0xc])(*(undefined8 *)*param_1);
  bVar1 = *(byte *)(param_1 + 0x6c);
  uVar4 = (ulonglong)bVar1;
  if (((char)bVar1 < '\0') || ((bVar1 & 8) != 0)) {
    uVar4 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x88,0);
  }
  if ((uVar4 & 1) == 0) {
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0x2c);
    FUN_000150c4(param_2,0);
    uVar5 = 0;
  }
  else {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      uVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 1);
    }
    else {
      uVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar3;
    FUN_000150c4(param_2,-0x7ffffffd);
    uVar5 = 0x80000003;
  }
  return uVar5;
}



===== NvStorProtocolAtaBusyWaitCheckQueueDpc @ 00014618 =====

ulonglong NvStorProtocolAtaBusyWaitCheckQueueDpc(longlong *param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
  }
  *(char *)(param_1 + 0x6c) = (char)uVar2;
  return uVar2 & 0xffffffffffffff00;
}



===== NvStorProtocolAtaIdentifyDevice @ 00014660 =====

undefined8 NvStorProtocolAtaIdentifyDevice(longlong *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 local_38 [32];
  
  pbVar1 = (byte *)param_1[0x110];
  uVar8 = 0;
  (*(code *)NvStorOsCBT[0x2a])(*(undefined8 *)*param_1,2,0,local_38);
  lVar2 = param_1[0x73];
  param_1[0x73] = (longlong)NvStorProtocolAtaBusyWaitCheckQueueDpc;
  (*(code *)NvStorOsCBT[0x2b])(*(undefined8 *)*param_1,2,0,local_38);
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 6,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x18);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    bVar4 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 7);
  }
  else {
    bVar4 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 1,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 4);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 2,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 8);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 3,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0xc);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 4,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x10);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 5,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x14);
  }
  if (bVar4 != 0xff) {
    if ((bVar4 & 0x40) == 0) {
LAB_00014a09:
      (*(code *)NvStorOsCBT[0x30])(0xf);
      NvStorNonIntExecuteDeviceResetProtocol(param_1);
      (*(code *)NvStorOsCBT[0x30])(100);
      uVar9 = 0;
      do {
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          cVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 7) + 2);
        }
        else {
          cVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
        }
        if (-1 < cVar5) break;
        (*(code *)NvStorOsCBT[0x30])(1);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 10000000);
      if (-1 < cVar5) {
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          cVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 4);
        }
        else {
          cVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x10);
        }
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          cVar6 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 5);
        }
        else {
          cVar6 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x14);
        }
        if ((cVar5 == '\x14') && (cVar6 == -0x15)) {
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 6,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x18);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 1,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 4);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 2,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 8);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 3,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0xc);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 4,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x10);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 5,0);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x14);
          }
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 7,0xa1);
          }
          else {
            (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x1c);
          }
          uVar7 = NvStorNonIntExecutePioDataInPhase(param_1);
          if ((int)uVar7 == 2) {
            puVar3 = (undefined8 *)*param_1;
            if (puVar3[0x19] == 0) {
              (*(code *)NvStorOsCBT[4])(*puVar3,*(undefined2 *)(puVar3 + 3),pbVar1,0x100);
            }
            else {
              (*(code *)NvStorOsCBT[10])(*puVar3,puVar3[0x19],pbVar1,0x200);
            }
            if ((*pbVar1 & 4) == 0) {
              if ((*(uint *)(*(longlong *)*param_1 + 0x2818) & 0x40) != 0) {
                lVar10 = 900;
                do {
                  (*(code *)NvStorOsCBT[0x30])(1000);
                  lVar10 = lVar10 + -1;
                } while (lVar10 != 0);
              }
              param_1[0x112] = param_1[0x112] | 0x20;
              goto LAB_00014969;
            }
          }
        }
      }
    }
    else {
      puVar3 = (undefined8 *)*param_1;
      if (puVar3[0x19] == 0) {
        (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 7,0xec);
      }
      else {
        (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x1c);
      }
      puVar3 = (undefined8 *)*param_1;
      if (puVar3[0x19] == 0) {
        cVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 7);
      }
      else {
        cVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
      }
      if (cVar5 != -1) {
        uVar7 = NvStorNonIntExecutePioDataInPhase(param_1);
        puVar3 = (undefined8 *)*param_1;
        lVar10 = puVar3[0x19];
        if ((int)uVar7 == 2) {
          if (lVar10 == 0) {
            (*(code *)NvStorOsCBT[4])(*puVar3,*(undefined2 *)(puVar3 + 3),pbVar1,0x100);
          }
          else {
            (*(code *)NvStorOsCBT[10])(*puVar3,lVar10,pbVar1,0x200);
          }
          uVar8 = 0;
          if ((*pbVar1 & 4) != 0) {
            uVar8 = 0x80000003;
          }
          goto LAB_00014969;
        }
        if (lVar10 == 0) {
          cVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 4);
        }
        else {
          cVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,lVar10 + 0x10);
        }
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          cVar6 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 5);
        }
        else {
          cVar6 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x14);
        }
        if ((cVar5 == '\x14') && (cVar6 == -0x15)) goto LAB_00014a09;
      }
    }
  }
  uVar8 = 0x80000003;
LAB_00014969:
  (*(code *)NvStorOsCBT[0x2a])(*(undefined8 *)*param_1,2,0,local_38);
  puVar3 = NvStorOsCBT;
  param_1[0x73] = lVar2;
  (*(code *)puVar3[0x2b])(*(undefined8 *)*param_1,2,0,local_38);
  return uVar8;
}



===== NvStorProtocolAtaSendCommandAndWait @ 00014d28 =====

uint NvStorProtocolAtaSendCommandAndWait(longlong *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 6,param_2[9]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x18);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 1,*param_2);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 4);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 2,param_2[1]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 8);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 2,param_2[1]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 8);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 3,param_2[6]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0xc);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 3,param_2[2]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0xc);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 4,param_2[7]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x10);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 4,param_2[3]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x10);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 5,param_2[8]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x14);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 5,param_2[4]);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x14);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x1c);
  }
  uVar2 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = (char)uVar2;
  }
  return -(uint)((uVar2 & 1) != 0) & 0x80000003;
}



===== NvStorProtocolAtaSendCommandAndBusyWaitInterrupt @ 00014fcc =====

uint NvStorProtocolAtaSendCommandAndBusyWaitInterrupt
               (longlong *param_1,undefined1 *param_2,undefined1 *param_3,char param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 local_28 [32];
  
  lVar3 = 0;
  if (param_4 != '\0') {
    (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_28);
    lVar3 = param_1[0x73];
    param_1[0x73] = (longlong)NvStorProtocolAtaBusyWaitCheckQueueDpc;
    (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*param_1,2,0,local_28);
  }
  uVar2 = NvStorProtocolAtaSendCommandAndWait(param_1,param_2,param_3);
  if (param_4 != '\0') {
    (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_28);
    lVar1 = NvStorOsCBT;
    param_1[0x73] = lVar3;
    (**(code **)(lVar1 + 0x158))(*(undefined8 *)*param_1,2,0,local_28);
  }
  return uVar2;
}



===== FUN_000150c4 @ 000150c4 =====

void FUN_000150c4(longlong param_1,int param_2)

{
  undefined1 local_28 [32];
  
  if (*(int *)(param_1 + 0x84) != -1) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8)
         = 0;
    if ((*(uint *)(param_1 + 0xc0) & 0x1000) == 0) {
      (**(code **)(NvStorOsCBT + 0x150))
                (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),1,0,local_28);
    }
    NvStorReleaseTag(*(undefined8 **)(param_1 + 0x10),(ulonglong)*(uint *)(param_1 + 0x84));
    if ((*(uint *)(param_1 + 0xc0) & 0x1000) == 0) {
      (**(code **)(NvStorOsCBT + 0x158))
                (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),1,0,local_28);
    }
  }
  if (param_2 == 0) {
    (**(code **)(param_1 + 0x98))();
  }
  else {
    (**(code **)(param_1 + 0xa0))(param_1,param_2);
  }
  return;
}



===== NvStorProtocolSetupSmart @ 00015180 =====

int NvStorProtocolSetupSmart(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  
  puVar1 = *(undefined1 **)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x18);
  }
  uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if ((char)uVar3 < '\0') {
    iVar4 = -0x7ffffffa;
  }
  else {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 4);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 2,puVar1[1]);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 8);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 3,puVar1[2]);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0xc);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 4,puVar1[3]);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x10);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 3) + 5,puVar1[4]);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x14);
    }
    uVar3 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar3) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      return 0;
    }
    iVar4 = -0x7ffffffe;
  }
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000150c4(param_2,iVar4);
  return iVar4;
}



===== NvStorProtocolSmartNonDataIssueCommand @ 00015350 =====

int NvStorProtocolSmartNonDataIssueCommand(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  iVar2 = NvStorProtocolSetupSmart(param_1,param_2);
  if (iVar2 == 0) {
    *(code **)(param_2 + 0xb8) = NvStorProtocolAtaNonDataInterrupt;
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar1,*(short *)(puVar1 + 3) + 7,
                 *(undefined1 *)(*(longlong *)(param_2 + 200) + 10));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x1c);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== NvStorProtocolSmartDataOutIssueCommand @ 000153c4 =====

int NvStorProtocolSmartDataOutIssueCommand(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  iVar2 = NvStorProtocolSetupSmart(param_1,param_2);
  if (iVar2 == 0) {
    *(code **)(param_2 + 0xb8) = NvStorProtocolAtaPioOutInterrupt;
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar1,*(short *)(puVar1 + 3) + 7,
                 *(undefined1 *)(*(longlong *)(param_2 + 200) + 10));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x1c);
    }
    NvStorProtocolAtaPioOutWriteHelper(param_1,param_2);
    iVar2 = 0;
  }
  return iVar2;
}



===== NvStorProtocolSmartDataInIssueCommand @ 00015444 =====

int NvStorProtocolSmartDataInIssueCommand(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  iVar2 = NvStorProtocolSetupSmart(param_1,param_2);
  if (iVar2 == 0) {
    *(code **)(param_2 + 0xb8) = NvStorProtocolAtaPioInInterrupt;
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar1,*(short *)(puVar1 + 3) + 7,
                 *(undefined1 *)(*(longlong *)(param_2 + 200) + 10));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar1,puVar1[0x19] + 0x1c);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== FUN_000154b8 @ 000154b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_000154b8(longlong *param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  int aiStack_b0 [2];
  short local_a8 [72];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_b8 = 0x4000000000;
  aiStack_b0[0] = 0;
  aiStack_b0[1] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 1;
  local_a8[3] = 0;
  local_a8[4] = 0x40;
  local_a8[5] = 0;
  local_a8[6] = 4;
  local_a8[7] = 0;
  local_a8[8] = 4;
  local_a8[9] = 0;
  local_a8[10] = 4;
  local_a8[0xb] = 0;
  local_a8[0xc] = 2;
  local_a8[0xd] = 0;
  local_a8[0xe] = 0x40;
  local_a8[0xf] = 0;
  local_a8[0x10] = 8;
  local_a8[0x11] = 0;
  local_a8[0x12] = 8;
  local_a8[0x13] = 0;
  local_a8[0x14] = 8;
  local_a8[0x15] = 0;
  local_a8[0x16] = 3;
  local_a8[0x17] = 0;
  local_a8[0x18] = 0x40;
  local_a8[0x19] = 0;
  local_a8[0x1a] = 0xc;
  local_a8[0x1b] = 0;
  local_a8[0x1c] = 0xc;
  local_a8[0x1d] = 0;
  local_a8[0x1e] = -1;
  local_a8[0x1f] = -1;
  local_a8[0x20] = 4;
  local_a8[0x21] = 0;
  local_a8[0x22] = 0;
  local_a8[0x23] = 0;
  local_a8[0x24] = 0x400;
  local_a8[0x25] = 0;
  local_a8[0x26] = 0x400;
  local_a8[0x27] = 0;
  local_a8[0x28] = -1;
  local_a8[0x29] = -1;
  local_a8[0x2a] = 5;
  local_a8[0x2b] = 0;
  local_a8[0x2c] = 0;
  local_a8[0x2d] = 0;
  local_a8[0x2e] = 0x440;
  local_a8[0x2f] = 0;
  local_a8[0x30] = 0x440;
  local_a8[0x31] = 0;
  local_a8[0x32] = 0x10;
  local_a8[0x33] = 0;
  local_a8[0x34] = 6;
  local_a8[0x35] = 0;
  local_a8[0x36] = 0;
  local_a8[0x37] = 0;
  local_a8[0x38] = -1;
  local_a8[0x39] = -1;
  local_a8[0x3a] = 0x444;
  local_a8[0x3b] = 0;
  local_a8[0x3c] = -1;
  local_a8[0x3d] = -1;
  local_a8[0x3e] = 7;
  local_a8[0x3f] = 0;
  local_a8[0x40] = 0;
  local_a8[0x41] = 0;
  local_a8[0x42] = -1;
  local_a8[0x43] = -1;
  local_a8[0x44] = 0x448;
  local_a8[0x45] = 0;
  local_a8[0x46] = -1;
  local_a8[0x47] = -1;
  if (param_1[0x15] == 0) {
    (**(code **)(NvStorOsCBT + 0x70))
              (*param_1,(short)aiStack_b0[(longlong)param_2 * 5 + -1] *
                        (ushort)*(byte *)(param_1 + 0x1b) + local_a8[(longlong)param_2 * 10] +
                        (short)param_1[0xf],param_3);
  }
  else {
    lVar1 = (longlong)param_2;
    if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) {
      iVar2 = aiStack_b0[lVar1 * 5];
    }
    else {
      iVar2 = aiStack_b0[lVar1 * 5 + 1];
    }
    (**(code **)(NvStorOsCBT + 0xa0))
              (*param_1,(longlong)
                        (int)(aiStack_b0[lVar1 * 5 + -1] * (uint)*(byte *)(param_1 + 0x1b) + iVar2)
                        + param_1[0x15],param_3);
  }
  return;
}



===== FUN_00015608 @ 00015608 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00015608(longlong *param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  int aiStack_b0 [38];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_b8 = 0x4000000000;
  aiStack_b0[0] = 0;
  aiStack_b0[1] = 0;
  aiStack_b0[2] = 0;
  aiStack_b0[3] = 1;
  aiStack_b0[4] = 0x40;
  aiStack_b0[5] = 4;
  aiStack_b0[6] = 4;
  aiStack_b0[7] = 4;
  aiStack_b0[8] = 2;
  aiStack_b0[9] = 0x40;
  aiStack_b0[10] = 8;
  aiStack_b0[0xb] = 8;
  aiStack_b0[0xc] = 8;
  aiStack_b0[0xd] = 3;
  aiStack_b0[0xe] = 0x40;
  aiStack_b0[0xf] = 0xc;
  aiStack_b0[0x10] = 0xc;
  aiStack_b0[0x11] = -1;
  aiStack_b0[0x12] = 4;
  aiStack_b0[0x13] = 0;
  aiStack_b0[0x14] = 0x400;
  aiStack_b0[0x15] = 0x400;
  aiStack_b0[0x16] = -1;
  aiStack_b0[0x17] = 5;
  aiStack_b0[0x18] = 0;
  aiStack_b0[0x19] = 0x440;
  aiStack_b0[0x1a] = 0x440;
  aiStack_b0[0x1b] = 0x10;
  aiStack_b0[0x1c] = 6;
  aiStack_b0[0x1d] = 0;
  aiStack_b0[0x1e] = -1;
  aiStack_b0[0x1f] = 0x444;
  aiStack_b0[0x20] = -1;
  aiStack_b0[0x21] = 7;
  aiStack_b0[0x22] = 0;
  aiStack_b0[0x23] = -1;
  aiStack_b0[0x24] = 0x448;
  aiStack_b0[0x25] = -1;
  if (param_1[0x15] == 0) {
    iVar2 = aiStack_b0[(longlong)param_2 * 5 + -1] * (uint)*(byte *)(param_1 + 0x1b) +
            aiStack_b0[(longlong)param_2 * 5 + 2];
    (**(code **)(NvStorOsCBT + 0x10))
              (*param_1,CONCAT22((short)((uint)iVar2 >> 0x10),(short)iVar2 + (short)param_1[0xf]));
  }
  else {
    lVar1 = (longlong)param_2;
    if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) {
      iVar2 = aiStack_b0[lVar1 * 5];
    }
    else {
      iVar2 = aiStack_b0[lVar1 * 5 + 1];
    }
    (**(code **)(NvStorOsCBT + 0x40))
              (*param_1,(longlong)
                        (int)(iVar2 + aiStack_b0[lVar1 * 5 + -1] * (uint)*(byte *)(param_1 + 0x1b))
                        + param_1[0x15]);
  }
  return;
}



===== NvStorProtocolNcqInitialize @ 00015748 =====

undefined8 NvStorProtocolNcqInitialize(undefined8 *param_1)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  
  lVar2 = param_1[0x110];
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  *(undefined4 *)((longlong)param_1 + 0x344) = 0xffffffff;
  *(undefined4 *)(lVar2 + 0x208) = 0;
  *(undefined1 *)(lVar2 + 0x214) = 0;
  uVar4 = FUN_00015608((longlong *)*param_1,4);
  FUN_000154b8((longlong *)*param_1,4,
               (-(uint)((char)((longlong *)*param_1)[0x1b] != '\0') & 2) + 2 | uVar4);
  cVar1 = *(char *)((longlong)param_1 + 0x222);
  plVar3 = (longlong *)*param_1;
  uVar4 = NvStorSataInterruptGetAppropriateMask(plVar3,cVar1);
  NvStorSataInterruptEnableDisableByMask(plVar3,cVar1,'\x01',uVar4);
  return 0;
}



===== NvStorProtocolNcqCheckQueueDpc @ 000157d8 =====

undefined1 NvStorProtocolNcqCheckQueueDpc(longlong *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  lVar1 = param_1[0x110];
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    uVar4 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
  }
  else {
    uVar4 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
  }
  plVar3 = (longlong *)*param_1;
  *(undefined1 *)(param_1 + 0x6c) = uVar4;
  uVar5 = 0;
  if ((*(uint *)(*plVar3 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*plVar3 + 0x25f0) & 8) != 0) {
      uVar5 = FUN_00015608(plVar3,5);
    }
  }
  else {
    uVar5 = FUN_00015608(plVar3,5);
    uVar5 = (uVar5 & 0xf0) << 0xc | uVar5 & 0xf;
  }
  plVar3 = (longlong *)*param_1;
  uVar6 = 0;
  if ((*(uint *)(*plVar3 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*plVar3 + 0x25f0) & 8) != 0) {
      uVar6 = FUN_00015608(plVar3,6);
    }
  }
  else {
    uVar6 = FUN_00015608(plVar3,5);
    uVar6 = (uVar6 & 0xf000) << 4 | uVar6 >> 8 & 0xf;
  }
  plVar3 = (longlong *)*param_1;
  uVar7 = 0xf0 << ((*(byte *)(plVar3 + 0x1b) & 1) << 4);
  uVar5 = uVar7 & uVar6 & uVar5;
  if ((uVar5 & uVar7) == 0) {
    return 0;
  }
  if ((*(uint *)(*plVar3 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*plVar3 + 0x25f0) & 8) == 0) goto LAB_0001592a;
    uVar6 = uVar5;
  }
  else {
    uVar6 = FUN_00015608(plVar3,5);
    uVar6 = uVar6 & 0xff00 | uVar5 >> 0xc & 0xf0 | uVar5 & 0xf;
  }
  FUN_000154b8(plVar3,5,uVar6);
LAB_0001592a:
  *(uint *)(lVar1 + 0x208) = *(uint *)(lVar1 + 0x208) | uVar5;
  return 1;
}



===== NvStorProtocolNcqIssueCommand @ 00015954 =====

undefined8 NvStorProtocolNcqIssueCommand(longlong *param_1,longlong *param_2)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar1,*(short *)(puVar1 + 3) + 6);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar1,puVar1[0x19] + 0x18);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    cVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    cVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
  }
  if (cVar2 < '\0') {
    uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
    if (-1 < (char)uVar3) goto LAB_00015a04;
LAB_000159e6:
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x1000;
    FUN_000150c4((longlong)param_2,-0x7ffffffa);
    uVar3 = 0x80000006;
  }
  else {
LAB_00015a04:
    NvStorNonIntSendCommandAddressCount(param_1,(longlong)param_2);
    if ((*(uint *)(param_2 + 0x18) & 0x100) == 0) {
      uVar3 = NvStorGetNextTag(param_1,(uint *)((longlong)param_2 + 0x84));
      if ((int)uVar3 < 0) goto LAB_000159e6;
    }
    param_1[(longlong)*(int *)((longlong)param_2 + 0x84) + 0x48] = (longlong)param_2;
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])
                (*puVar1,*(short *)(puVar1 + 3) + 2,*(char *)((longlong)param_2 + 0x84) << 3);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar1,puVar1[0x19] + 8);
    }
    (*(code *)NvStorOsCBT[0x2c])(*(undefined8 *)*param_1,FUN_00016010,param_2);
    if ((*(uint *)(param_2 + 0x18) >> 8 & 1) != 0) {
      *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x1000;
      FUN_00015f3c(param_2);
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== FUN_00015ac4 @ 00015ac4 =====

ulonglong FUN_00015ac4(longlong *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *local_48;
  undefined1 local_40;
  uint local_3c;
  byte local_38;
  undefined1 local_30 [40];
  
  local_40 = 1;
  uVar6 = 0;
  local_48 = param_1;
  (**(code **)(NvStorOsCBT + 0x160))(*(undefined8 *)*param_1,FUN_00016140);
  iVar2 = FUN_00015608((longlong *)*param_1,1);
  if (iVar2 != 0) {
    FUN_000154b8((longlong *)*param_1,1,iVar2);
  }
  if ((local_38 & 1) == 0) {
    plVar7 = (longlong *)*param_1;
    bVar5 = (char)plVar7[0x1b] << 4;
    if ((((local_3c & 0x10 << (bVar5 & 0x1f)) != 0) && ((local_3c & 0x40 << (bVar5 & 0x1f)) == 0))
       && ((int)param_1[0x68] != -1)) {
      FUN_00015608(plVar7,3);
      FUN_00015f3c((longlong *)param_1[(longlong)(int)param_1[0x68] + 0x48]);
    }
    puVar1 = (undefined8 *)*param_1;
    if (((local_3c & 0x40 << ((*(byte *)(puVar1 + 0x1b) & 1) << 4)) != 0) &&
       (*(undefined4 *)(param_1 + 0x68) = 0xffffffff,
       (local_3c & 0xa0 << ((*(byte *)(puVar1 + 0x1b) & 1) << 4)) == 0)) {
      (**(code **)(NvStorOsCBT + 0x150))(*puVar1,1,0,local_30);
      NvStorReqQueueDispatch((longlong)(param_1 + 0x35));
      plVar7 = (longlong *)0x0;
      (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*param_1,1,0,local_30);
    }
    uVar6 = 0;
    if ((local_3c & 0x20 << ((*(byte *)(*param_1 + 0xd8) & 1) << 4)) != 0) {
      uVar4 = FUN_00015d1c(param_1,local_3c,CONCAT71((int7)((ulonglong)plVar7 >> 8),local_38));
      uVar6 = uVar4 & 0xffffffff;
      if ((int)uVar4 != 0) goto LAB_00015c5c;
    }
    if ((local_3c & 0x80 << ((*(byte *)(*param_1 + 0xd8) & 1) << 4)) == 0) {
      return uVar6;
    }
    uVar4 = FUN_00015e60(param_1);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      return uVar6;
    }
  }
LAB_00015c5c:
  uVar8 = 0;
  (**(code **)(NvStorOsCBT + 0x60))(*(undefined8 *)*param_1);
  if ((param_1[0x112] & 0x800000000U) != 0) {
    uVar3 = NvStorSataCrashDumpReadLogExt(param_1,'\0');
    uVar6 = (ulonglong)uVar3;
    if (((param_1[0x112] & 0x800000000U) != 0) && (uVar3 == 0)) goto LAB_00015cbf;
  }
  NvStorSataIssueSRST((undefined8 *)*param_1);
  uVar8 = 0;
  NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
LAB_00015cbf:
  NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000002,uVar8,1);
  local_40 = 1;
  local_48 = param_1;
  (**(code **)(NvStorOsCBT + 0x160))(*(undefined8 *)*param_1,FUN_00016140,&local_48);
  return uVar6;
}



===== FUN_00015d1c @ 00015d1c =====

undefined8 FUN_00015d1c(longlong *param_1,uint param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  bVar3 = false;
  uVar4 = FUN_00015608((longlong *)*param_1,3);
  puVar1 = (undefined8 *)*param_1;
  (**(code **)(NvStorOsCBT + 0x60))
            (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 8 + *(short *)(puVar1 + 0xb),0);
  *(undefined4 *)((longlong)param_1 + 0x344) = 0xffffffff;
  *(undefined1 *)(param_1[0x110] + 0x214) = 0;
  uVar6 = 0;
  if ((short)param_1[0x44] != 0) {
    do {
      uVar5 = (uint)uVar6;
      lVar2 = param_1[uVar6 + 0x48];
      if ((((*(uint *)(param_1 + 0x68) != uVar5) && ((~uVar4 >> (uVar5 & 0x1f) & 1) != 0)) &&
          (lVar2 != 0)) && ((*(uint *)(lVar2 + 0xc0) & 0x100) == 0)) {
        if ((param_3 & 1) != 0) {
          return 0x80000003;
        }
        *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(lVar2 + 0x2c);
        *(undefined4 *)((longlong)param_1 + 0x344) = 0xffffffff;
        if ((((param_2 & 0x80 << ((*(byte *)(*param_1 + 0xd8) & 1) << 4)) != 0) ||
            ((int)param_1[0x68] != -1)) || (bVar3)) {
          *(uint *)(lVar2 + 0xc0) = *(uint *)(lVar2 + 0xc0) | 0x400;
        }
        FUN_000150c4(lVar2,0);
        if ((char)param_1[0x3f] == '\0') {
          bVar3 = true;
        }
      }
      uVar6 = (ulonglong)(uVar5 + 1);
    } while (uVar5 + 1 < (uint)*(ushort *)(param_1 + 0x44));
  }
  return 0;
}



===== FUN_00015e60 @ 00015e60 =====

undefined8 FUN_00015e60(longlong *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  byte bVar5;
  
  uVar4 = FUN_00015608((longlong *)*param_1,7);
  bVar5 = *(char *)(*param_1 + 0xd8) * '\x10';
  uVar4 = (0x7c << (bVar5 & 0x1f) & uVar4) >> (bVar5 + 2 & 0x1f);
  if (*(uint *)(param_1 + 0x68) == uVar4) {
    *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  }
  if ((int)param_1[0x68] != -1) {
    FUN_00015f3c((longlong *)param_1[(longlong)(int)param_1[0x68] + 0x48]);
  }
  lVar2 = param_1[0x110];
  if (*(int *)((longlong)param_1 + 0x344) == -1) {
    *(undefined1 *)(lVar2 + 0x214) = 0;
  }
  else {
    *(undefined1 *)(lVar2 + 0x214) = 1;
    uVar1 = *(undefined4 *)((longlong)param_1 + 0x344);
    *(uint *)(lVar2 + 0x210) = uVar4;
    *(undefined4 *)(lVar2 + 0x20c) = uVar1;
    puVar3 = (undefined8 *)*param_1;
    (**(code **)(NvStorOsCBT + 0x60))
              (*puVar3,(ushort)*(byte *)(puVar3 + 0x1b) * 8 + *(short *)(puVar3 + 0xb),0);
  }
  *(uint *)((longlong)param_1 + 0x344) = uVar4;
  if (param_1[(longlong)(int)uVar4 + 0x48] != 0) {
    NvStorNonIntBuildAndStartPrd(param_1,param_1[(longlong)(int)uVar4 + 0x48]);
  }
  return 0;
}



===== FUN_00015f3c @ 00015f3c =====

void FUN_00015f3c(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 local_28 [32];
  
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x100;
  param_1[0x17] = (longlong)NvStorProtocolNcqIssueCommand;
  *(undefined4 *)(param_1[2] + 0x340) = 0xffffffff;
  *(undefined8 *)(param_1[2] + 0x240 + (longlong)*(int *)((longlong)param_1 + 0x84) * 8) = 0;
  lVar2 = param_1[2];
  if ((*(uint *)(param_1 + 0x18) & 0x1000) == 0) {
    (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)(lVar2 + 0x1a8),1,0,local_28);
  }
  plVar1 = (longlong *)(lVar2 + 0x1b0);
  lVar3 = *plVar1;
  param_1[1] = (longlong)plVar1;
  *param_1 = lVar3;
  *(longlong **)(lVar3 + 8) = param_1;
  *plVar1 = (longlong)param_1;
  *(int *)(lVar2 + 0x1c8) = *(int *)(lVar2 + 0x1c8) + 1;
  if ((*(uint *)(param_1 + 0x18) >> 0xc & 1) == 0) {
    (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)(lVar2 + 0x1a8),1,0,local_28);
  }
  else {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffefff;
  }
  return;
}



===== FUN_00016010 @ 00016010 =====

undefined8 FUN_00016010(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  
  plVar1 = *(longlong **)(param_2 + 0x10);
  lVar2 = *(longlong *)(param_2 + 200);
  lVar3 = plVar1[0x110];
  FUN_00015608((longlong *)*plVar1,3);
  FUN_000154b8((longlong *)*plVar1,3,1 << ((byte)*(undefined4 *)(param_2 + 0x84) & 0x1f));
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) & 0xfffffeff;
  plVar4 = (longlong *)*plVar1;
  lVar7 = *plVar4;
  uVar6 = 0;
  if ((*(uint *)(lVar7 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(lVar7 + 0x25f0) & 8) != 0) {
      lVar7 = FUN_00015608(plVar4,5);
      uVar6 = (uint)lVar7;
    }
  }
  else {
    uVar6 = FUN_00015608(plVar4,5);
    lVar7 = 0;
    uVar6 = (uVar6 & 0xf0) << 0xc | uVar6 & 0xf;
  }
  uVar8 = 0x80 << ((*(byte *)(*plVar1 + 0xd8) & 1) << 4);
  if (((*(uint *)(lVar3 + 0x208) | uVar6) & uVar8) == 0) {
    *(undefined4 *)(plVar1 + 0x68) = *(undefined4 *)(param_2 + 0x84);
    *(undefined8 *)(param_2 + 0xb8) = 0;
    puVar5 = (undefined8 *)*plVar1;
    if (puVar5[0x19] == 0) {
      lVar7 = (**(code **)(NvStorOsCBT + 0x60))
                        (*puVar5,*(short *)(puVar5 + 3) + 7,
                         CONCAT31((int3)(uVar8 >> 8),*(undefined1 *)(lVar2 + 10)));
    }
    else {
      lVar7 = (**(code **)(NvStorOsCBT + 0x90))(*puVar5,puVar5[0x19] + 0x1c);
    }
  }
  else {
    *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x100;
  }
  return CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
}



===== FUN_00016140 @ 00016140 =====

undefined8 FUN_00016140(undefined8 param_1,longlong *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*param_2 + 0x880);
  uVar1 = *(undefined4 *)(lVar2 + 0x208);
  *(undefined4 *)((longlong)param_2 + 0xc) = uVar1;
  if ((char)param_2[1] != '\0') {
    *(undefined4 *)(lVar2 + 0x208) = 0;
  }
  *(undefined1 *)(param_2 + 2) = *(undefined1 *)(*param_2 + 0x360);
  if ((char)param_2[1] != '\0') {
    *(undefined1 *)(*param_2 + 0x360) = 0;
  }
  return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);
}



===== NvStorProtocolNcqAckIntAfterReset @ 00016180 =====

undefined8 NvStorProtocolNcqAckIntAfterReset(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  longlong *local_28;
  undefined1 local_20;
  
  if (((ulonglong)param_1[0x112] >> 0xf & 1) == 0) {
    return 0;
  }
  if (((ulonglong)param_1[0x112] >> 0xe & 1) == 0) {
    return 0;
  }
  plVar1 = (longlong *)*param_1;
  uVar4 = 0;
  if ((*(uint *)(*plVar1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*plVar1 + 0x25f0) & 8) != 0) {
      uVar4 = FUN_00015608(plVar1,5);
    }
  }
  else {
    uVar4 = FUN_00015608(plVar1,5);
    uVar4 = (uVar4 & 0xf0) << 0xc | uVar4 & 0xf;
  }
  plVar1 = (longlong *)*param_1;
  uVar5 = 0;
  if ((*(uint *)(*plVar1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*plVar1 + 0x25f0) & 8) != 0) {
      uVar5 = FUN_00015608(plVar1,6);
    }
  }
  else {
    uVar5 = FUN_00015608(plVar1,5);
    uVar5 = (uVar5 & 0xf000) << 4 | uVar5 >> 8 & 0xf;
  }
  puVar2 = (undefined8 *)*param_1;
  uVar4 = 0xf0 << ((*(byte *)(puVar2 + 0x1b) & 1) << 4) & uVar5 & uVar4;
  if (uVar4 != 0) {
    if (puVar2[0x19] == 0) {
      uVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
    }
    else {
      uVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
    }
    plVar1 = (longlong *)*param_1;
    *(undefined1 *)(param_1 + 0x6c) = uVar3;
    if ((*(uint *)(*plVar1 + 0x25f0) & 4) == 0) {
      if ((*(uint *)(*plVar1 + 0x25f0) & 8) == 0) goto LAB_000162d6;
    }
    else {
      uVar5 = FUN_00015608(plVar1,5);
      uVar4 = uVar5 & 0xff00 | uVar4 >> 0xc & 0xf0 | uVar4 & 0xf;
    }
    FUN_000154b8(plVar1,5,uVar4);
  }
LAB_000162d6:
  local_20 = 1;
  local_28 = param_1;
  FUN_00016140(*(undefined8 *)*param_1,(longlong *)&local_28);
  return 0;
}



===== NvStorProtocolAtapiSendPacketCdb @ 00016308 =====

undefined8 NvStorProtocolAtapiSendPacketCdb(longlong *param_1,longlong *param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,8);
  if ((char)uVar2 < '\0') {
    uVar3 = 0x80000006;
  }
  else if ((uVar2 & 8) == 0) {
    uVar3 = 0x80000009;
  }
  else if (((uVar2 & 1) == 0) || (param_2 == param_1 + 0x15)) {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x80))(*puVar1,*(undefined2 *)(puVar1 + 3),param_2 + 8,6);
    }
    else {
      (**(code **)(NvStorOsCBT + 0xb0))(*puVar1,puVar1[0x19],param_2 + 8,0xc);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80000012;
  }
  return uVar3;
}



===== NvStorProtocolAtapiSendPacketCdbDma @ 000163a0 =====

undefined8 NvStorProtocolAtapiSendPacketCdbDma(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,8);
  if ((char)uVar2 < '\0') {
    return 0x80000006;
  }
  if ((uVar2 & 8) != 0) {
    if ((uVar2 & 1) != 0) {
      return 0x80000012;
    }
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x80))(*puVar1,*(undefined2 *)(puVar1 + 3),param_2 + 0x40,6);
    }
    else {
      (**(code **)(NvStorOsCBT + 0xb0))(*puVar1,puVar1[0x19],param_2 + 0x40,0xc);
    }
    uVar2 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,8,0);
    if ((uVar2 & 8) == 0) {
      uVar3 = NvStorNonIntBuildAndStartPrd(param_1,param_2);
      return uVar3;
    }
  }
  return 0x80000009;
}



===== NvStorProtocolAtapiPioIssueCommand @ 00016444 =====

ulonglong NvStorProtocolAtapiPioIssueCommand(longlong *param_1,longlong *param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  puVar1 = (undefined1 *)param_2[0x19];
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
  }
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    cVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
  }
  else {
    cVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
  }
  if ((-1 < cVar3) ||
     (uVar5 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0), -1 < (char)uVar5)) {
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 4,puVar1[3]);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x10);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 5,puVar1[4]);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x14);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 4);
    }
    uVar5 = NvStorGetNextTag(param_1,(uint *)((longlong)param_2 + 0x84));
    if (-1 < (int)uVar5) {
      param_1[(longlong)(int)*(uint *)((longlong)param_2 + 0x84) + 0x48] = (longlong)param_2;
      if ((*(byte *)(param_1 + 0x112) & 0x40) != 0) {
        param_2[0x17] = (longlong)NvStorProtocolAtapiPioInterruptSendPacket;
        puVar2 = (undefined8 *)*param_1;
        if (puVar2[0x19] == 0) {
          (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 7);
        }
        else {
          (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x1c);
        }
        return 1;
      }
      param_2[0x17] = (longlong)NvStorProtocolAtapiPioInterrupt;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 7,0xa0);
      }
      else {
        (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x1c);
      }
      uVar6 = NvStorProtocolAtapiSendPacketCdb(param_1,param_2);
      iVar4 = (int)uVar6;
      uVar6 = uVar6 & 0xffffffff;
      if (-1 < iVar4) {
        return 0;
      }
      goto LAB_000164e7;
    }
  }
  uVar6 = 0x80000006;
  iVar4 = -0x7ffffffa;
LAB_000164e7:
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x1000;
  FUN_000172b0((longlong)param_2,iVar4);
  return uVar6;
}



===== NvStorProtocolAtapiPioInterruptSendPacket @ 00016694 =====

ulonglong NvStorProtocolAtapiPioInterruptSendPacket(longlong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  param_2[0x17] = (longlong)NvStorProtocolAtapiPioInterrupt;
  uVar1 = NvStorProtocolAtapiSendPacketCdb(param_1,param_2);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    FUN_000172b0((longlong)param_2,(int)uVar1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== NvStorProtocolAtapiPioInterrupt @ 000166d8 =====

undefined8 NvStorProtocolAtapiPioInterrupt(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  
  puVar1 = (undefined8 *)*param_1;
  bVar3 = false;
  if (puVar1[0x19] == 0) {
    bVar4 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    bVar4 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
  }
  if ((bVar4 & 0x80) != 0) {
    uVar7 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
    bVar4 = (byte)uVar7;
  }
  puVar1 = (undefined8 *)*param_1;
  lVar2 = puVar1[0x19];
  if ((bVar4 & 1) == 0) {
    if (lVar2 == 0) {
      uVar5 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 4);
    }
    else {
      uVar5 = (*(code *)NvStorOsCBT[6])(*puVar1,lVar2 + 0x10);
    }
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      uVar6 = (*(code *)*NvStorOsCBT)(*puVar1);
    }
    else {
      uVar6 = (*(code *)NvStorOsCBT[6])(*puVar1);
    }
    uVar10 = (uint)CONCAT11(uVar6,uVar5);
    if (((bVar4 & 8) == 0) && (uVar10 != 0)) {
      bVar4 = bVar4 | 8;
      bVar3 = true;
    }
    uVar9 = *(uint *)(param_2 + 0x2c);
    if ((((uVar9 != 0) || (bVar3)) || ((bVar4 & 8) != 0)) && (((bVar4 & 8) != 0 && (uVar10 != 0))))
    {
      if (uVar9 <= uVar10) {
        uVar10 = uVar9;
      }
      if (((*(uint *)(param_2 + 0xc0) & 1) == 0) && (*(longlong *)(param_2 + 0x30) != param_1[0x33])
         ) {
        puVar1 = (undefined8 *)*param_1;
        if (puVar1[0x19] == 0) {
          if ((uVar10 & 1) == 0) {
            (*(code *)NvStorOsCBT[0x10])();
          }
          else {
            (*(code *)NvStorOsCBT[0xf])
                      (*puVar1,*(undefined2 *)(puVar1 + 3),
                       (ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(param_2 + 0x30));
          }
        }
        else {
          (*(code *)NvStorOsCBT[0x16])(*puVar1);
        }
      }
      else {
        puVar1 = (undefined8 *)*param_1;
        if (puVar1[0x19] == 0) {
          if ((uVar10 & 1) == 0) {
            (*(code *)NvStorOsCBT[4])();
          }
          else {
            (*(code *)NvStorOsCBT[3])
                      (*puVar1,*(undefined2 *)(puVar1 + 3),
                       (ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(param_2 + 0x30));
          }
        }
        else {
          (*(code *)NvStorOsCBT[10])(*puVar1);
        }
        if (*(uint *)(param_2 + 0x2c) == uVar10) {
          puVar1 = (undefined8 *)*param_1;
          if (puVar1[0x19] == 0) {
            uVar8 = (*(code *)*NvStorOsCBT)(*puVar1);
          }
          else {
            uVar8 = (*(code *)NvStorOsCBT[6])(*puVar1);
          }
          if ((uVar8 & 8) != 0) {
            uVar9 = 0;
            do {
              puVar1 = (undefined8 *)*param_1;
              if (puVar1[0x19] == 0) {
                (*(code *)NvStorOsCBT[1])(*puVar1,*(undefined2 *)(puVar1 + 3));
              }
              else {
                (*(code *)NvStorOsCBT[7])(*puVar1);
              }
              puVar1 = (undefined8 *)*param_1;
              if (puVar1[0x19] == 0) {
                uVar8 = (*(code *)*NvStorOsCBT)(*puVar1);
              }
              else {
                uVar8 = (*(code *)NvStorOsCBT[6])(*puVar1);
              }
            } while (((uVar8 & 8) != 0) && (uVar9 = uVar9 + 1, uVar9 < 0x10000));
          }
        }
      }
      *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) - uVar10;
      *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + uVar10;
      if (!bVar3) {
        return 1;
      }
    }
    FUN_000172b0(param_2,0);
    uVar7 = 0;
  }
  else {
    if (lVar2 == 0) {
      uVar5 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 1);
    }
    else {
      uVar5 = (*(code *)NvStorOsCBT[6])(*puVar1,lVar2 + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar5;
    FUN_000172b0(param_2,-0x7ffffffd);
    uVar7 = 0x80000003;
  }
  return uVar7;
}



===== NvStorProtocolAtapiDmaIssueCommand @ 000169ac =====

int NvStorProtocolAtapiDmaIssueCommand(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 uVar4;
  int iVar5;
  
  puVar1 = *(undefined1 **)(param_2 + 200);
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
  }
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    cVar3 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
  }
  else {
    cVar3 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
  }
  if (cVar3 < '\0') {
    uVar4 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
    if (-1 < (char)uVar4) goto LAB_00016a66;
  }
  else {
LAB_00016a66:
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 4,puVar1[3]);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x10);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 5,puVar1[4]);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x14);
    }
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 1,*puVar1);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 4);
    }
    uVar4 = NvStorGetNextTag(param_1,(uint *)(param_2 + 0x84));
    if (-1 < (int)uVar4) {
      param_1[(longlong)(int)*(uint *)(param_2 + 0x84) + 0x48] = param_2;
      if ((*(byte *)(param_1 + 0x112) & 0x40) != 0) {
        *(code **)(param_2 + 0xb8) = NvStorProtocolAtapiDmaInterruptSendPacket;
        puVar2 = (undefined8 *)*param_1;
        if (puVar2[0x19] == 0) {
          (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 7);
        }
        else {
          (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x1c);
        }
        return 1;
      }
      *(code **)(param_2 + 0xb8) = NvStorProtocolAtapiDmaInterrupt;
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 7,0xa0);
      }
      else {
        (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x1c);
      }
      uVar4 = NvStorProtocolAtapiSendPacketCdbDma(param_1,param_2);
      if (-1 < (int)uVar4) {
        return 0;
      }
      iVar5 = -0x7ffffffd;
      goto LAB_00016a4d;
    }
  }
  iVar5 = -0x7ffffffa;
LAB_00016a4d:
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x1000;
  FUN_000172b0(param_2,iVar5);
  return iVar5;
}



===== NvStorProtocolAtapiDmaInterruptSendPacket @ 00016c00 =====

ulonglong NvStorProtocolAtapiDmaInterruptSendPacket(longlong *param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  *(code **)(param_2 + 0xb8) = NvStorProtocolAtapiDmaInterrupt;
  uVar1 = NvStorProtocolAtapiSendPacketCdbDma(param_1,param_2);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    FUN_000172b0(param_2,(int)uVar1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== NvStorProtocolAtapiDmaInterrupt @ 00016c44 =====

undefined8 NvStorProtocolAtapiDmaInterrupt(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  puVar1 = (undefined8 *)*param_1;
  (*(code *)NvStorOsCBT[0xc])
            (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 8 + *(short *)(puVar1 + 0xb));
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    uVar3 = (*(code *)*NvStorOsCBT)(*puVar1);
  }
  else {
    uVar3 = (*(code *)NvStorOsCBT[6])(*puVar1);
  }
  *(char *)(param_1 + 0x6c) = (char)uVar3;
  if (((char)uVar3 < '\0') || ((uVar3 & 8) != 0)) {
    uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x88,0);
  }
  if ((uVar3 & 1) == 0) {
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0x2c);
    FUN_000172b0(param_2,0);
    uVar4 = 0;
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 1);
    }
    else {
      uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 4);
    }
    *(undefined1 *)(param_2 + 0x18) = uVar2;
    FUN_000172b0(param_2,-0x7ffffffd);
    uVar4 = 0x80000003;
  }
  return uVar4;
}



===== NvStorProtocolAtapiSendCommandAndWait @ 00016d28 =====

ulonglong NvStorProtocolAtapiSendCommandAndWait(longlong *param_1,longlong *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar2 = (undefined1 *)param_2[0x19];
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 6,puVar2[9]);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x18);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 1,*puVar2);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 4);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 2,puVar2[1]);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 8);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 3,puVar2[2]);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0xc);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 4,puVar2[3]);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x10);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 5,puVar2[4]);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x14);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 7);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x1c);
  }
  uVar6 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
  if ((uVar6 & 1) == 0) {
    uVar6 = NvStorProtocolAtapiSendPacketCdb(param_1,param_2);
    if (-1 < (int)uVar6) {
      (*(code *)NvStorOsCBT[0x30])(100);
      iVar1 = *(int *)((longlong)param_2 + 0x2c);
      while ((iVar1 != 0 &&
             (uVar6 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,8), (uVar6 & 8) != 0)
             )) {
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          uVar4 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 4);
        }
        else {
          uVar4 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x10);
        }
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          uVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 5);
        }
        else {
          uVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x14);
        }
        uVar8 = (uint)CONCAT11(uVar5,uVar4);
        if (uVar8 == 0) {
          return 0;
        }
        if (*(uint *)((longlong)param_2 + 0x2c) <= uVar8) {
          uVar8 = *(uint *)((longlong)param_2 + 0x2c);
        }
        if (((*(uint *)(param_2 + 0x18) & 1) == 0) && (param_2[6] != param_1[0x33])) {
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            if ((uVar8 & 1) == 0) {
              (*(code *)NvStorOsCBT[0x10])();
            }
            else {
              (*(code *)NvStorOsCBT[0xf])(*puVar3,*(undefined2 *)(puVar3 + 3));
            }
          }
          else {
            (*(code *)NvStorOsCBT[0x16])(*puVar3);
          }
        }
        else {
          puVar3 = (undefined8 *)*param_1;
          if (puVar3[0x19] == 0) {
            if ((uVar8 & 1) == 0) {
              (*(code *)NvStorOsCBT[4])();
            }
            else {
              (*(code *)NvStorOsCBT[3])(*puVar3,*(undefined2 *)(puVar3 + 3));
            }
          }
          else {
            (*(code *)NvStorOsCBT[10])(*puVar3);
          }
          if (*(uint *)((longlong)param_2 + 0x2c) == uVar8) {
            puVar3 = (undefined8 *)*param_1;
            if (puVar3[0x19] == 0) {
              uVar6 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 7) + 2);
            }
            else {
              uVar6 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
            }
            if ((uVar6 & 8) != 0) {
              uVar7 = 0;
              do {
                puVar3 = (undefined8 *)*param_1;
                if (puVar3[0x19] == 0) {
                  (*(code *)NvStorOsCBT[1])(*puVar3,*(undefined2 *)(puVar3 + 3));
                }
                else {
                  (*(code *)NvStorOsCBT[7])(*puVar3);
                }
                puVar3 = (undefined8 *)*param_1;
                if (puVar3[0x19] == 0) {
                  uVar6 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 7) + 2);
                }
                else {
                  uVar6 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
                }
              } while (((uVar6 & 8) != 0) && (uVar7 = uVar7 + 1, uVar7 < 0x10000));
            }
          }
        }
        *(int *)((longlong)param_2 + 0x2c) = *(int *)((longlong)param_2 + 0x2c) - uVar8;
        iVar1 = *(int *)((longlong)param_2 + 0x2c);
        *(uint *)(param_2 + 5) = (int)param_2[5] + uVar8;
      }
      uVar6 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      uVar6 = (ulonglong)(-(uint)((uVar6 & 0x80) != 0) & 0x80000006);
    }
  }
  else {
    uVar6 = 0x80000003;
  }
  return uVar6;
}



===== NvStorProtocolAtapiGetInquiryData @ 00017140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvStorProtocolAtapiGetInquiryData(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_168 [32];
  undefined1 local_148 [32];
  longlong local_128 [5];
  undefined4 local_fc;
  undefined8 local_f8;
  undefined1 local_e8 [4];
  undefined1 local_e4;
  uint local_68;
  undefined1 *local_60;
  undefined1 local_38 [3];
  undefined1 local_35;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  (**(code **)(NvStorOsCBT + 0x110))(local_128,0xf0);
  (**(code **)(NvStorOsCBT + 0x110))(param_2,0x60);
  (**(code **)(NvStorOsCBT + 0x110))(local_38,0xb);
  local_60 = local_38;
  (**(code **)(NvStorOsCBT + 0x110))(local_e8,0x10);
  local_68 = local_68 | 1;
  local_e8[0] = 0x12;
  local_e4 = 0x24;
  local_35 = 0x24;
  local_fc = 0x24;
  local_f8 = param_2;
  (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_148);
  lVar1 = param_1[0x73];
  param_1[0x73] = (longlong)NvStorProtocolAtaBusyWaitCheckQueueDpc;
  (**(code **)(NvStorOsCBT + 0x158))(*(undefined8 *)*param_1,2,0,local_148);
  uVar3 = NvStorProtocolAtapiSendCommandAndWait(param_1,local_128);
  (**(code **)(NvStorOsCBT + 0x150))(*(undefined8 *)*param_1,2,0,local_148);
  lVar2 = NvStorOsCBT;
  param_1[0x73] = lVar1;
  (**(code **)(lVar2 + 0x158))(*(undefined8 *)*param_1,2,0,local_148);
  return uVar3 & 0xffffffff;
}



===== FUN_000172b0 @ 000172b0 =====

void FUN_000172b0(longlong param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined1 local_28 [32];
  
  if (*(int *)(param_1 + 0x84) != -1) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8)
         = 0;
    if ((*(uint *)(param_1 + 0xc0) & 0x1000) == 0) {
      (**(code **)(NvStorOsCBT + 0x150))
                (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),1,0,local_28);
    }
    NvStorReleaseTag(*(undefined8 **)(param_1 + 0x10),(ulonglong)*(uint *)(param_1 + 0x84));
    if ((*(uint *)(param_1 + 0xc0) & 0x1000) == 0) {
      (**(code **)(NvStorOsCBT + 0x158))
                (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),1,0,local_28);
    }
  }
  if (param_2 == 0) {
    if ((*(char *)(param_1 + 0x40) == '%') && (lVar2 = *(longlong *)(param_1 + 0x30), lVar2 != 0)) {
      uVar1 = *(uint *)(lVar2 + 4);
      *(uint *)(*(longlong *)(param_1 + 0x10) + 0x230) =
           (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | (uint)*(byte *)(lVar2 + 7);
    }
    (**(code **)(param_1 + 0x98))(param_1);
  }
  else {
    (**(code **)(param_1 + 0xa0))(param_1,param_2);
  }
  return;
}



===== NvStorProtocolAtapiPioCheckQueueDpc @ 000173b0 =====

ulonglong NvStorProtocolAtapiPioCheckQueueDpc(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
  }
  *(byte *)(param_1 + 0x6c) = (byte)uVar2;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),~((byte)uVar2 >> 7)) & 0xffffffffffffff01;
}



===== NvStorNonIntWaitOnPortStatus @ 000173fc =====

undefined8 NvStorNonIntWaitOnPortStatus(undefined8 *param_1,byte param_2,byte param_3)

{
  undefined8 uVar1;
  undefined7 uVar2;
  undefined7 extraout_var;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (param_1[0x19] == 0) {
      uVar1 = (*(code *)*NvStorOsCBT)(*param_1,*(short *)(param_1 + 3) + 7);
    }
    else {
      uVar1 = (*(code *)NvStorOsCBT[6])(*param_1,param_1[0x19] + 0x1c);
    }
    uVar2 = (undefined7)((ulonglong)uVar1 >> 8);
    if ((byte)((byte)uVar1 & (param_2 | param_3)) == param_3) break;
    (*(code *)NvStorOsCBT[0x30])(1);
    uVar3 = uVar3 + 1;
    uVar2 = extraout_var;
  } while (uVar3 < 10000000);
  return CONCAT71(uVar2,(byte)uVar1);
}



===== NvStorNonIntExecutePioDataInPhase @ 00017490 =====

undefined8 NvStorNonIntExecutePioDataInPhase(longlong *param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  
  (*(code *)NvStorOsCBT[0x30])(1);
  bVar2 = false;
  uVar4 = 0;
  do {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      bVar3 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
    }
    else {
      bVar3 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
    }
    if ((char)bVar3 < '\0') {
      bVar2 = true;
    }
    else {
      if (bVar2) {
        uVar4 = 0x989580;
        bVar2 = false;
      }
      if ((bVar3 & 1) != 0) {
        return 4;
      }
      if ((bVar3 & 8) != 0) {
        return 2;
      }
    }
    (*(code *)NvStorOsCBT[0x30])(1);
    uVar4 = uVar4 + 1;
    if (9999999 < uVar4) {
      return 3;
    }
  } while( true );
}



===== NvStorNonIntExecuteDeviceResetProtocol @ 00017544 =====

undefined8 NvStorNonIntExecuteDeviceResetProtocol(longlong *param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  uint uVar3;
  
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar1,*(short *)(puVar1 + 3) + 6,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar1,puVar1[0x19] + 0x18);
  }
  puVar1 = (undefined8 *)*param_1;
  if (puVar1[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar1,*(short *)(puVar1 + 3) + 7,8);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar1,puVar1[0x19] + 0x1c);
  }
  (*(code *)NvStorOsCBT[0x30])(1);
  uVar3 = 0;
  while( true ) {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      bVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
    }
    else {
      bVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
    }
    if (-1 < (char)bVar2) break;
    (*(code *)NvStorOsCBT[0x30])(1);
    uVar3 = uVar3 + 1;
    if (9999999 < uVar3) {
      return 3;
    }
  }
  if ((bVar2 & 1) == 0) {
    (*(code *)NvStorOsCBT[0x30])(1);
    return 0;
  }
  return 4;
}



===== NvStorNonIntBuildAndStartPrd @ 00017654 =====

undefined8 NvStorNonIntBuildAndStartPrd(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  int iVar11;
  ulonglong uVar12;
  
  puVar8 = *(uint **)(param_2 + 0x20);
  plVar1 = *(longlong **)(*param_1 + 0xf0);
  if (*puVar8 == 0) {
    uVar5 = 0x80000008;
  }
  else {
    uVar9 = 0;
    uVar10 = 0;
    if (*puVar8 != 0) {
      do {
        uVar6 = 0;
        iVar11 = 0;
        uVar7 = puVar8[uVar10 * 6 + 6];
        do {
          uVar12 = uVar9;
          lVar2 = *plVar1;
          *(int *)(lVar2 + uVar12 * 8) =
               *(int *)(*(longlong *)(param_2 + 0x20) + 0x10 + uVar10 * 0x18) + iVar11;
          uVar5 = *(undefined8 *)(*(longlong *)(param_2 + 0x20) + 0x10 + uVar10 * 0x18);
          *(undefined1 *)(lVar2 + 7 + uVar12 * 8) = 0;
          uVar4 = 0x10000;
          if (uVar7 < 0x10000) {
            uVar4 = uVar7;
          }
          *(char *)(lVar2 + 6 + uVar12 * 8) = (char)((ulonglong)uVar5 >> 0x20);
          uVar6 = uVar6 + 1;
          *(short *)(lVar2 + 4 + uVar12 * 8) = (short)uVar4;
          puVar8 = *(uint **)(param_2 + 0x20);
          uVar7 = uVar7 - uVar4;
          uVar9 = (ulonglong)((int)uVar12 + 1);
          iVar11 = iVar11 + 0x10000;
        } while (uVar6 <= puVar8[uVar10 * 6 + 6] / 0x10001);
        uVar7 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar7;
      } while (uVar7 < *puVar8);
      *(undefined1 *)(lVar2 + 7 + uVar12 * 8) = 0x80;
    }
    puVar3 = (undefined8 *)*param_1;
    uVar9 = CONCAT71((int7)((ulonglong)puVar8 >> 8),*(undefined1 *)(param_2 + 0xc0)) &
            0xffffffffffffff01;
    (**(code **)(NvStorOsCBT + 0x60))
              (*puVar3,(ushort)*(byte *)(puVar3 + 0x1b) * 8 + *(short *)(puVar3 + 0xb),
               CONCAT71((int7)(uVar9 >> 8),(char)uVar9 << 3) | 1);
    uVar5 = 0;
  }
  return uVar5;
}



===== NvStorNonIntSendCommandAddressCount @ 00017778 =====

void NvStorNonIntSendCommandAddressCount(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  short sVar4;
  longlong lVar5;
  
  uVar2 = *(uint *)(param_2 + 0xc0);
  lVar1 = *(longlong *)(param_2 + 200);
  puVar3 = (undefined8 *)*param_1;
  lVar5 = puVar3[0x19];
  if ((uVar2 & 0x10) != 0) {
    if ((uVar2 & 0x20) == 0) {
      if (lVar5 == 0) {
        sVar4 = *(short *)(puVar3 + 3) + 2;
        goto LAB_000177eb;
      }
      lVar5 = lVar5 + 8;
LAB_000177d8:
      (**(code **)(NvStorOsCBT + 0x90))(*puVar3,lVar5);
    }
    else {
      if (lVar5 != 0) {
        lVar5 = lVar5 + 4;
        goto LAB_000177d8;
      }
      sVar4 = *(short *)(puVar3 + 3) + 1;
LAB_000177eb:
      (**(code **)(NvStorOsCBT + 0x60))(*puVar3,sVar4,*(undefined1 *)(lVar1 + 5));
    }
    puVar3 = (undefined8 *)*param_1;
    if (puVar3[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar3,*(short *)(puVar3 + 3) + 3,*(undefined1 *)(lVar1 + 6));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0xc);
    }
    puVar3 = (undefined8 *)*param_1;
    if (puVar3[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar3,*(short *)(puVar3 + 3) + 4,*(undefined1 *)(lVar1 + 7));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x10);
    }
    puVar3 = (undefined8 *)*param_1;
    if (puVar3[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar3,*(short *)(puVar3 + 3) + 5,*(undefined1 *)(lVar1 + 8));
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x14);
    }
    puVar3 = (undefined8 *)*param_1;
    uVar2 = *(uint *)(param_2 + 0xc0);
    lVar5 = puVar3[0x19];
  }
  if ((uVar2 & 0x20) == 0) {
    if (lVar5 == 0) {
      sVar4 = *(short *)(puVar3 + 3) + 2;
      goto LAB_000178e5;
    }
    lVar5 = lVar5 + 8;
  }
  else {
    if (lVar5 == 0) {
      sVar4 = *(short *)(puVar3 + 3) + 1;
LAB_000178e5:
      (**(code **)(NvStorOsCBT + 0x60))(*puVar3,sVar4,*(undefined1 *)(lVar1 + 1));
      goto LAB_000178eb;
    }
    lVar5 = lVar5 + 4;
  }
  (**(code **)(NvStorOsCBT + 0x90))(*puVar3,lVar5);
LAB_000178eb:
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 3,*(undefined1 *)(lVar1 + 2))
    ;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0xc);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 4,*(undefined1 *)(lVar1 + 3))
    ;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x10);
  }
  puVar3 = (undefined8 *)*param_1;
  if (puVar3[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 5,*(undefined1 *)(lVar1 + 4))
    ;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x14);
  }
  return;
}



===== NvStorControllerConfigNotify @ 000179a0 =====

undefined8 NvStorControllerConfigNotify(int param_1,longlong *param_2,int param_3)

{
  char local_res8 [32];
  
  if ((((*(uint *)(param_2 + 0x4be) & 0x1000) != 0) && (local_res8[0] = '\0', param_1 == 0)) &&
     (0x10 < param_3)) {
    if (param_3 < 0x14) {
      FUN_00020398(param_2);
    }
    else if (param_3 == 0x15) {
      NvCfgElementGet(param_2[0x504],(longlong *)param_2[0x506],'\x15',(undefined8 *)local_res8,1);
      if (local_res8[0] == '\0') {
        *(uint *)(param_2 + 0x503) = *(uint *)(param_2 + 0x503) | 0x200;
      }
      else {
        *(uint *)(param_2 + 0x503) = *(uint *)(param_2 + 0x503) & 0xfffffdff;
      }
      *(int *)(param_2 + 0x503) = (int)param_2[0x503];
    }
  }
  return 0;
}



===== NvStorPortConfigNotify @ 00017a28 =====

uint NvStorPortConfigNotify(int param_1,longlong *param_2,int param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  char local_res10 [24];
  
  lVar1 = *param_2;
  if ((*(uint *)(lVar1 + 0x25f0) & 0x1000) == 0) {
    return 0;
  }
  uVar3 = 0;
  if ((param_1 == 0) && (param_3 == 0x17)) {
    plVar2 = *(longlong **)(lVar1 + 0x28c8);
    uVar3 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0x20],'\x17',
                            (undefined8 *)local_res10,1);
    if (('\x01' << (*(byte *)(param_2 + 0x1b) & 0x1f) & *(byte *)(*plVar2 + 0x18)) == 0) {
      if (local_res10[0] == '\0') {
        return uVar3;
      }
    }
    else if (local_res10[0] != '\0') {
      return uVar3;
    }
    uVar3 = FUN_00020398((longlong *)*param_2);
  }
  return uVar3;
}



===== NvStorDeviceConfigNotify @ 00017ac4 =====

uint NvStorDeviceConfigNotify(int param_1,longlong *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  char cVar5;
  ulonglong *puVar6;
  char local_res10 [8];
  
  lVar1 = *(longlong *)*param_2;
  if ((*(uint *)(lVar1 + 0x25f0) & 0x1000) == 0) {
    uVar2 = NvStorSataDeviceConfigNotify(param_1,param_2,param_3);
  }
  else {
    uVar2 = NvStorAhciDeviceConfigNotify(param_1,param_2,param_3);
  }
  if (uVar2 != 0) {
    return uVar2;
  }
  if (param_1 != 0) {
    return 0;
  }
  if (param_3 < 0x2f) {
    if (param_3 == 0x2e) {
      puVar6 = (ulonglong *)((longlong)param_2 + 0x2c);
      uVar2 = 4;
      cVar5 = '.';
    }
    else {
      if (param_3 < 0x28) {
        if (param_3 == 0x27) {
          uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'\'',
                                  (undefined8 *)local_res10,1);
          if (local_res10[0] == '\0') {
            param_2[0x112] = param_2[0x112] & 0xfffffffffffff7ff;
            return uVar2;
          }
          param_2[0x112] = param_2[0x112] | 0x800;
          return uVar2;
        }
        if (param_3 == 10) {
          uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),*(longlong **)(lVar1 + 0x2830),'\n',
                                  (undefined8 *)local_res10,1);
          if (local_res10[0] == '\0') {
            param_2[0x112] = param_2[0x112] & 0xffffffffffffbfff;
            uVar2 = NvCfgElementSet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'#',
                                    (ulonglong *)local_res10,1);
            return uVar2;
          }
LAB_00017ba7:
          param_2[0x112] = param_2[0x112] | 0x4000;
          return uVar2;
        }
        if (param_3 == 0xb) {
          plVar4 = *(longlong **)(lVar1 + 0x2830);
          uVar2 = 1;
          puVar6 = (ulonglong *)local_res10;
          cVar5 = '\v';
          goto LAB_00017b6a;
        }
        if (param_3 == 0x22) {
          param_2[0x112] = param_2[0x112] & 0xffffffffffff7fff;
          return 0;
        }
        if (param_3 == 0x23) {
          uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'#',
                                  (undefined8 *)local_res10,1);
          if (local_res10[0] == '\0') {
            param_2[0x112] = param_2[0x112] & 0xffffffffffffbfff;
            return uVar2;
          }
          goto LAB_00017ba7;
        }
        if (param_3 != 0x25) {
          return 0;
        }
        puVar6 = (ulonglong *)local_res10;
        cVar5 = '%';
      }
      else {
        if (param_3 == 0x29) {
          uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],')',
                                  (undefined8 *)local_res10,1);
          if (local_res10[0] == '\0') {
            param_2[0x112] = param_2[0x112] & 0xffffffffffffdfff;
            return uVar2;
          }
          param_2[0x112] = param_2[0x112] | 0x2000;
          return uVar2;
        }
        if (param_3 == 0x2a) {
          uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'*',
                                  (undefined8 *)local_res10,1);
          if (local_res10[0] == '\0') {
            *(uint *)(lVar1 + 0x2818) = *(uint *)(lVar1 + 0x2818) & 0xfffffff7;
            return uVar2;
          }
          *(uint *)(lVar1 + 0x2818) = *(uint *)(lVar1 + 0x2818) | 8;
          return uVar2;
        }
        if (param_3 == 0x2b) {
          cVar5 = '+';
          puVar6 = (ulonglong *)(param_2[1] + 0x1c);
        }
        else {
          if (param_3 != 0x2c) {
            if (param_3 != 0x2d) {
              return 0;
            }
            puVar6 = (ulonglong *)(param_2 + 5);
            uVar2 = 4;
            cVar5 = '-';
            goto LAB_00017b63;
          }
          cVar5 = ',';
          puVar6 = (ulonglong *)(param_2[1] + 0x1d);
        }
      }
      uVar2 = 1;
    }
  }
  else {
    if (0x44 < param_3) {
      if (param_3 == 0x46) {
        uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'F',
                                (undefined8 *)local_res10,1);
        if (local_res10[0] == '\0') {
          uVar3 = 0xffffff7fffffffff;
          goto LAB_00017f97;
        }
        uVar3 = 0x8000000000;
      }
      else if (param_3 == 0x48) {
        uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'H',
                                (undefined8 *)local_res10,1);
        if (local_res10[0] == '\0') {
          uVar3 = 0xfffffdffffffffff;
          goto LAB_00017f97;
        }
        uVar3 = 0x20000000000;
      }
      else {
        if (param_3 != 0x4a) {
          if (param_3 == 0x4b) {
            uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'K',
                                    (undefined8 *)local_res10,1);
            *(char *)((longlong)param_2 + 0x89b) = local_res10[0];
            return uVar2;
          }
          return 0;
        }
        uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'J',
                                (undefined8 *)local_res10,1);
        if (local_res10[0] == '\0') {
          uVar3 = 0xfffff7ffffffffff;
LAB_00017f97:
          param_2[0x112] = param_2[0x112] & uVar3;
          return uVar2;
        }
        uVar3 = 0x80000000000;
      }
LAB_00017f84:
      param_2[0x112] = param_2[0x112] | uVar3;
      return uVar2;
    }
    if (param_3 == 0x44) {
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'D',
                              (undefined8 *)local_res10,1);
      *(char *)((longlong)param_2 + 0x89a) = local_res10[0];
      return uVar2;
    }
    if (param_3 == 0x2f) {
      puVar6 = (ulonglong *)(param_2 + 3);
      uVar2 = 4;
      cVar5 = '/';
    }
    else if (param_3 == 0x30) {
      puVar6 = (ulonglong *)((longlong)param_2 + 0x1c);
      uVar2 = 4;
      cVar5 = '0';
    }
    else if (param_3 == 0x31) {
      puVar6 = (ulonglong *)(param_2 + 4);
      uVar2 = 4;
      cVar5 = '1';
    }
    else {
      if (param_3 != 0x35) {
        if (param_3 != 0x43) {
          return 0;
        }
        uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'C',
                                (undefined8 *)local_res10,1);
        if (local_res10[0] == '\0') {
          uVar3 = 0xffffffdfffffffff;
          goto LAB_00017f97;
        }
        uVar3 = 0x2000000000;
        goto LAB_00017f84;
      }
      puVar6 = (ulonglong *)((longlong)param_2 + 0x8a4);
      uVar2 = 4;
      cVar5 = '5';
    }
  }
LAB_00017b63:
  plVar4 = (longlong *)param_2[0xb6];
LAB_00017b6a:
  uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),plVar4,cVar5,puVar6,uVar2);
  return uVar2;
}



===== NvStorUtilStrStr @ 00017fb4 =====

char * NvStorUtilStrStr(char *param_1,char *param_2)

{
  ulonglong uVar1;
  char cVar2;
  
  cVar2 = *param_1;
  if (cVar2 != '\0') {
    do {
      uVar1 = 0;
      if (cVar2 == *param_2) {
        do {
          if (cVar2 == '\0') break;
          uVar1 = (ulonglong)((int)uVar1 + 1);
          cVar2 = param_1[uVar1];
        } while (cVar2 == param_2[uVar1]);
      }
      if (param_2[uVar1] == '\0') {
        return param_1;
      }
      if (param_1[uVar1] == '\0') {
        return (char *)0x0;
      }
      param_1 = param_1 + 1;
      cVar2 = *param_1;
    } while (cVar2 != '\0');
  }
  return (char *)0x0;
}



===== NvStorUtilStrICmp @ 00017ffc =====

undefined4 NvStorUtilStrICmp(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  for (; cVar3 = *param_1, cVar3 != '\0'; param_1 = param_1 + 1) {
    iVar2 = (int)cVar3;
    if ((byte)(cVar3 + 0xbfU) < 0x1a) {
      iVar2 = iVar2 + 0x20;
    }
    iVar1 = (int)*param_2;
    if ((byte)(*param_2 + 0xbfU) < 0x1a) {
      iVar1 = iVar1 + 0x20;
    }
    if (iVar2 != iVar1) break;
    param_2 = param_2 + 1;
  }
  cVar3 = *param_1;
  if ((byte)(cVar3 + 0xbfU) < 0x1a) {
    cVar3 = cVar3 + ' ';
  }
  iVar2 = (int)*param_2;
  if ((byte)(*param_2 + 0xbfU) < 0x1a) {
    iVar2 = iVar2 + 0x20;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),cVar3 - (char)iVar2);
}



===== NvStorUtilStrNCmp @ 0001806c =====

ulonglong NvStorUtilStrNCmp(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  ulonglong in_RAX;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = param_3 + -1;
  if (-1 < iVar3) {
    do {
      pbVar2 = param_2;
      in_RAX = CONCAT71((int7)(in_RAX >> 8),*pbVar2);
      bVar1 = *param_1;
      if (bVar1 != *pbVar2) break;
      param_1 = param_1 + 1;
      if (bVar1 == 0) goto LAB_0001809c;
      iVar3 = iVar3 + -1;
      param_2 = pbVar2 + 1;
    } while (-1 < iVar3);
    if (-1 < iVar3) {
      return (ulonglong)((uint)*param_1 - (uint)*pbVar2);
    }
  }
LAB_0001809c:
  return in_RAX & 0xffffffffffffff00;
}



===== NvStorCompleteRequestEx @ 000180a0 =====

void NvStorCompleteRequestEx(longlong param_1,undefined1 param_2)

{
  NvStorCompleteRequestHistory(param_1);
  if (*(code **)(param_1 + 0xb0) == (code *)0x0) {
    (**(code **)(NvStorOsCBT + 0x1c0))
              (param_1,*(undefined8 *)**(undefined8 **)(param_1 + 0x10),param_2);
  }
  else {
    (**(code **)(param_1 + 0xb0))();
  }
  return;
}



===== NvStorCompleteRequestHistory @ 000180f0 =====

void NvStorCompleteRequestHistory(longlong param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  ulonglong local_58 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (param_1 != 0) {
    uVar7 = 0;
    uVar6 = 0;
    local_res8[0] = 0;
    if (*(longlong *)(param_1 + 0x10) != 0) {
      uVar3 = (**(code **)(NvStorOsCBT + 0x138))();
      *(undefined8 *)(param_1 + 0xe8) = uVar3;
      bVar1 = *(byte *)(param_1 + 0x40);
      if (((bVar1 < 0x2f) && ((0x450000000500U >> ((ulonglong)bVar1 & 0x3f) & 1) != 0)) ||
         (((byte)(bVar1 + 0x78) < 0x37 &&
          ((0x42000500000005U >> ((ulonglong)(byte)(bVar1 + 0x78) & 0x3f) & 1) != 0)))) {
        local_48 = *(undefined8 *)(param_1 + 0xd8);
        uStack_40 = *(undefined8 *)(param_1 + 0xe0);
        local_38 = *(undefined8 *)(param_1 + 0xe8);
        lVar4 = *(longlong *)(param_1 + 0x10) + 0x8a8;
        if (lVar4 != 0) {
          NvIoHistoryQueueAdd(lVar4,&local_48);
        }
      }
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      lVar5 = 5;
      local_58[0] = puVar2[0x420];
      local_res10[0] = *(undefined4 *)((longlong)puVar2 + 0x20fc);
      lVar4 = 0;
      do {
        uVar7 = uVar7 + *(int *)(lVar4 + 0x20b0 + (longlong)puVar2);
        uVar6 = uVar6 + *(int *)(lVar4 + 0x20b4 + (longlong)puVar2);
        lVar4 = lVar4 + 0x10;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      local_res18[0] = uVar7 / 5;
      local_res20[0] = uVar6 / 5;
      uVar6 = *(int *)((longlong)puVar2 + 0x210c) * 2;
      if (uVar6 != 0) {
        local_res8[0] = (uint)(*(int *)(puVar2 + 0x421) * 100) / uVar6;
      }
      NvCfgElementSet(*(longlong *)(*(longlong *)*puVar2 + 0x2820),(longlong *)puVar2[0xb6],':',
                      local_58,8);
      NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                      (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],'<',
                      (ulonglong *)local_res10,4);
      NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                      (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],'>',
                      (ulonglong *)local_res8,4);
      NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                      (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],'?',
                      (ulonglong *)local_res18,4);
      NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                      (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],'@',
                      (ulonglong *)local_res20,4);
    }
  }
  return;
}



===== NvStorSataCheckHotPlugInterrupt @ 000182d0 =====

char NvStorSataCheckHotPlugInterrupt(longlong *param_1)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  longlong *plVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar7 = 0;
  cVar5 = '\0';
  uVar3 = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      uVar3 = FUN_00015608(param_1,5);
    }
  }
  else {
    uVar3 = FUN_00015608(param_1,5);
    uVar3 = (uVar3 & 0xf0) << 0xc | uVar3 & 0xf;
  }
  uVar8 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      uVar4 = 0;
      plVar6 = param_1 + uVar8 * 0x25;
      if ((*(uint *)(*plVar6 + 0x25f0) & 4) == 0) {
        if ((*(uint *)(*plVar6 + 0x25f0) & 8) != 0) {
          uVar4 = FUN_00015608(plVar6,6);
        }
      }
      else {
        uVar4 = FUN_00015608(plVar6,5);
        uVar4 = (uVar4 & 0xf000) << 4 | uVar4 >> 8 & 0xf;
      }
      if ((uVar3 & 0xc << ((*(byte *)(plVar6 + 0x1b) & 1) << 4) & uVar4) != 0) {
        bVar2 = false;
        uVar4 = 0;
        if ((short)plVar6[2] != 0) {
          do {
            lVar1 = plVar6[(ulonglong)uVar4 + 1];
            if ((lVar1 == 0) || ((*(ulonglong *)(lVar1 + 0x890) >> 0x18 & 1) != 0)) {
              if ((uVar3 & 4 << ((*(byte *)(plVar6 + 0x1b) & 1) << 4)) != 0) {
                NvStorSataResetSATAPhy(plVar6);
                bVar2 = true;
              }
            }
            else if ((uVar3 & 8 << ((*(byte *)(plVar6 + 0x1b) & 1) << 4)) != 0) {
              *(ulonglong *)(lVar1 + 0x890) = *(ulonglong *)(lVar1 + 0x890) | 0x80000000;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(ushort *)(plVar6 + 2));
          if (bVar2) {
            (**(code **)(NvStorOsCBT + 0x188))(param_1,(char)plVar6[0x1b]);
          }
        }
        cVar5 = '\x01';
        uVar7 = uVar7 | 0xe << ((*(byte *)(plVar6 + 0x1b) & 1) << 4);
      }
      uVar4 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar4;
    } while (uVar4 < *(byte *)(param_1 + 0x4a0));
    if (cVar5 != '\0') {
      if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
        if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) {
          return cVar5;
        }
      }
      else {
        uVar3 = FUN_00015608(param_1,5);
        uVar7 = uVar3 & 0xff00 | uVar7 >> 0xc & 0xf0 | uVar7 & 0xf;
      }
      FUN_000154b8(param_1,5,uVar7);
    }
  }
  return cVar5;
}



===== NvStorSataResetSATAPhy @ 000184f4 =====

uint NvStorSataResetSATAPhy(longlong *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = 0;
  (**(code **)(NvStorOsCBT + 0x60))
            (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + (short)param_1[0xb],0);
  uVar7 = 0;
  do {
    if (param_1[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*param_1,(short)param_1[3] + 6,0);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))();
    }
    bVar1 = FUN_00015608(param_1,0);
    uVar3 = FUN_00015608(param_1,2);
    FUN_000154b8(param_1,2,uVar3 | 1);
    (**(code **)(NvStorOsCBT + 0x180))(1000);
    FUN_000154b8(param_1,2,uVar3 & 0xfffffffe);
    uVar4 = FUN_00015608(param_1,1);
    FUN_000154b8(param_1,1,uVar4);
    iVar8 = 4;
    if ((bVar1 & 0xf) == 3) {
      iVar8 = 14000;
    }
    do {
      iVar8 = iVar8 + -1;
      (**(code **)(NvStorOsCBT + 0x180))(500);
      bVar1 = FUN_00015608(param_1,0);
      if ((bVar1 & 0xf) == 3) break;
    } while (iVar8 != 0);
    if ((bVar1 & 0xf) == 3) {
      uVar5 = NvStorNonIntWaitOnPortStatus(param_1,0x88,0);
      bVar2 = (byte)uVar5;
      uVar6 = uVar5 & 0xff;
      if ((-1 < (char)bVar2) && ((uVar5 & 8) == 0)) break;
    }
    bVar2 = (byte)uVar6;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 4);
  if ((((char)bVar2 < '\0') || ((bVar2 & 8) != 0)) || ((bVar1 & 0xf) != 3)) {
    bVar1 = 0;
  }
  if ((bVar1 & 3) == 3) {
    uVar7 = NvStorSataIssueSRST(param_1);
  }
  else {
    uVar7 = 0x80000010;
  }
  return uVar7;
}



===== NvStorSataIssueSRST @ 00018690 =====

uint NvStorSataIssueSRST(undefined8 *param_1)

{
  ulonglong uVar1;
  
  if (param_1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*param_1,*(short *)(param_1 + 7) + 2);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*param_1,param_1[0x19] + 0x1c);
  }
  (**(code **)(NvStorOsCBT + 0x180))(5000);
  if (param_1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*param_1,*(short *)(param_1 + 7) + 2);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*param_1,param_1[0x19] + 0x1c);
  }
  (**(code **)(NvStorOsCBT + 0x180))(2000);
  if (param_1[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(*param_1,*(short *)(param_1 + 3) + 6);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(*param_1,param_1[0x19] + 0x18);
  }
  uVar1 = NvStorNonIntWaitOnPortStatus(param_1,0x80,0);
  return -(uint)((uVar1 & 0x80) != 0) & 0x80000006;
}



===== NvStorSataInitializeController @ 00018770 =====

ulonglong NvStorSataInitializeController(longlong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong *plVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  uint local_res10 [2];
  byte local_res18 [16];
  
  uVar5 = 0;
  param_1[0x4f7] = (longlong)NvStorIntParallelEmuCheckInterrupt;
  bVar3 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      uVar1 = (ulonglong)bVar3;
      bVar3 = bVar3 + 1;
      param_1[uVar1 * 0x25 + 0x1d] = (longlong)NvStorIntPortCheckInterruptSingleDevice;
      param_1[uVar1 * 0x25 + 0x1c] = (longlong)NvStorIntPortDpcSingleDevice;
    } while (bVar3 < *(byte *)(param_1 + 0x4a0));
  }
  uVar1 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      plVar4 = param_1 + uVar1 * 0x25;
      *(char *)(plVar4 + 0x1b) = (char)uVar1;
      *plVar4 = (longlong)param_1;
      *(ushort *)(plVar4 + 2) = (ushort)*(byte *)((longlong)param_1 + 0x2501);
      uVar6 = (int)uVar1 + 1;
      plVar4[3] = param_1[uVar1 * 4 + 0x4a2];
      plVar4[4] = param_1[uVar1 * 4 + 0x4a3];
      plVar4[5] = param_1[uVar1 * 4 + 0x4a4];
      plVar4[6] = param_1[uVar1 * 4 + 0x4a5];
      plVar4[7] = param_1[uVar1 * 4 + 0x4aa];
      plVar4[8] = param_1[uVar1 * 4 + 0x4ab];
      plVar4[9] = param_1[uVar1 * 4 + 0x4ac];
      plVar4[10] = param_1[uVar1 * 4 + 0x4ad];
      plVar4[0xb] = param_1[0x4b2];
      plVar4[0xc] = param_1[0x4b3];
      plVar4[0xd] = param_1[0x4b4];
      plVar4[0xe] = param_1[0x4b5];
      plVar4[0xf] = param_1[0x4b6];
      plVar4[0x10] = param_1[0x4b7];
      plVar4[0x11] = param_1[0x4b8];
      plVar4[0x12] = param_1[0x4b9];
      plVar4[0x13] = param_1[0x4ba];
      plVar4[0x14] = param_1[0x4bb];
      plVar4[0x15] = param_1[0x4bc];
      plVar4[0x16] = param_1[0x4bd];
      uVar1 = (ulonglong)uVar6;
    } while (uVar6 < *(byte *)(param_1 + 0x4a0));
  }
  if (((*(uint *)(param_1 + 0x4be) & 2) != 0) &&
     (uVar6 = (**(code **)(NvStorOsCBT + 0xd0))(param_1,0x50,local_res8), (uVar6 & 0x80000000) == 0)
     ) {
    local_res8[0] = local_res8[0] | 4;
    (**(code **)(NvStorOsCBT + 0xd8))(param_1,0x50);
  }
  if (((*(uint *)(param_1 + 0x4be) & 0x20000) != 0) &&
     (uVar6 = (**(code **)(NvStorOsCBT + 0xd0))(param_1,0x7c,local_res10), (uVar6 & 0x80000000) == 0
     )) {
    local_res10[0] = local_res10[0] & 0x7fffffff;
    (**(code **)(NvStorOsCBT + 0xd8))(param_1,0x7c);
  }
  uVar1 = (**(code **)(NvStorOsCBT + 0xd0))(param_1,0xa4,local_res18);
  if ((uVar1 & 0x80000000) != 0) {
    return uVar1;
  }
  if ((local_res18[0] & 0x40) != 0) {
    *(uint *)(param_1 + 0x503) = *(uint *)(param_1 + 0x503) | 8;
  }
  if ((*(uint *)(param_1 + 0x4be) & 0x40) == 0) {
LAB_00018a3c:
    uVar1 = 0;
  }
  else {
    uVar6 = (**(code **)(NvStorOsCBT + 0xd0))(param_1,0x50,local_res8);
    uVar1 = (ulonglong)uVar6;
    if ((uVar6 & 0x80000000) == 0) {
      local_res8[0] = local_res8[0] | 0x20;
      (**(code **)(NvStorOsCBT + 0xd8))(param_1,0x50);
      *(uint *)(param_1 + 0x503) = *(uint *)(param_1 + 0x503) | 1;
      goto LAB_00018a3c;
    }
  }
  if ((uVar1 & 0x80000000) != 0) {
    return uVar1;
  }
  uVar6 = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      uVar6 = FUN_00015608(param_1,5);
    }
  }
  else {
    uVar6 = FUN_00015608(param_1,5);
    uVar6 = uVar6 & 0xf;
  }
  uVar6 = uVar6 & 0xff;
  uVar8 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      uVar6 = uVar6 | 0x3fd << ((*(byte *)(param_1 + uVar8 * 0x25 + 0x1b) & 1) << 4);
      uVar2 = NvStorPortStart(param_1 + uVar8 * 0x25);
      uVar1 = uVar2 & 0xffffffff;
      if ((uVar2 & 0x80000000) != 0) {
        return uVar2;
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *(byte *)(param_1 + 0x4a0));
  }
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) goto LAB_00018b29;
  }
  else {
    uVar7 = FUN_00015608(param_1,5);
    uVar6 = uVar7 & 0xff00 | uVar6 >> 0xc & 0xf0 | uVar6 & 0xf;
  }
  FUN_000154b8(param_1,5,uVar6);
LAB_00018b29:
  if ((char)param_1[0x4a0] != '\0') {
    do {
      uVar6 = NvStorSataInterruptGetAppropriateMask(param_1 + uVar5 * 0x25,'\0');
      NvStorSataInterruptEnableDisableByMask(param_1 + uVar5 * 0x25,'\0','\x01',uVar6);
      uVar6 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar6;
    } while (uVar6 < *(byte *)(param_1 + 0x4a0));
  }
  *(undefined4 *)((longlong)param_1 + 0x2664) = 1;
  return uVar1;
}



===== NvStorSataInitializePort @ 00018b80 =====

undefined8 NvStorSataInitializePort(longlong *param_1,undefined8 param_2,longlong param_3)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  byte bVar4;
  undefined8 uVar5;
  ushort local_res8 [4];
  uint local_res10 [2];
  
  plVar1 = (longlong *)param_1[0x1e];
  uVar5 = 0;
  if (*plVar1 == 0) {
    lVar3 = (*(code *)NvStorOsCBT[0x20])(*param_1,0x1000,0,0);
    *plVar1 = lVar3;
    if (lVar3 != 0) {
      local_res10[0] = 0x1000;
      param_3 = *plVar1;
      lVar3 = (*(code *)NvStorOsCBT[0x37])(*param_1,0,param_3,local_res10);
      plVar1[1] = lVar3;
      if ((lVar3 != 0) && (0xfff < local_res10[0])) goto LAB_00018c02;
    }
    uVar5 = 0x80000011;
  }
  else {
LAB_00018c02:
    uVar2 = (*(code *)*NvStorOsCBT)
                      (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + 2 + (short)param_1[0xb]);
    (*(code *)NvStorOsCBT[0xc])
              (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + 2 + (short)param_1[0xb],
               CONCAT71((int7)((ulonglong)param_3 >> 8),uVar2) | 6);
    (*(code *)NvStorOsCBT[0xe])
              (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + 4 + (short)param_1[0xb],
               (int)plVar1[1]);
    if ((*(uint *)(*param_1 + 0x2818) & 1) != 0) {
      (*(code *)NvStorOsCBT[0x1c])(*param_1,0x60,local_res8);
      bVar4 = (char)param_1[0x1b] << 3;
      local_res8[0] =
           (ushort)(byte)((ulonglong)plVar1[1] >> 0x20) << (bVar4 & 0x1f) |
           ~(0xff << (bVar4 & 0x1f)) & local_res8[0];
      (*(code *)NvStorOsCBT[0x1d])(*param_1,0x60);
    }
  }
  return uVar5;
}



===== NvStorSataInitializeDevice @ 00018cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvStorSataInitializeDevice(longlong *param_1,longlong *param_2,byte param_3)

{
  longlong *plVar1;
  ushort uVar2;
  byte *pbVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  byte *pbVar9;
  longlong lVar10;
  code *pcVar11;
  undefined8 uVar12;
  byte *pbVar13;
  byte *pbVar14;
  ulonglong uVar15;
  undefined1 auStack_b8 [64];
  byte local_78 [8];
  undefined1 local_70;
  byte local_6f;
  undefined1 local_66;
  byte local_60 [8];
  byte local_58 [16];
  byte local_48 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar8 = FUN_00015608(param_1,0);
  if ((uVar8 & 3) == 0) {
    uVar15 = 0x80000003;
    goto LAB_0001958c;
  }
  param_2[0x112] = param_2[0x112] | 0x200000;
  pbVar3 = (byte *)param_2[0x110];
  param_2[0x73] = (longlong)NvStorProtocolAtaBusyWaitCheckQueueDpc;
  if ((*(uint *)(*param_1 + 0x2818) & 2) != 0) {
    uVar8 = NvStorDeviceResetCrashdump(param_2);
    uVar15 = uVar8 & 0xffffffff;
    if ((int)uVar8 < 0) goto LAB_0001958c;
  }
  uVar8 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_2,0x88,0);
  if (((char)uVar8 < '\0') || ((uVar8 & 8) != 0)) {
    uVar7 = NvStorSataResetSATAPhy(param_1);
    uVar15 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) goto LAB_0001958c;
    uVar8 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_2,0x88,0);
    if (((char)uVar8 < '\0') || ((uVar8 & 8) != 0)) {
      uVar15 = 0x80000006;
      goto LAB_0001958c;
    }
  }
  uVar7 = NvStorSataInterruptGetAppropriateMask(param_1,param_3);
  NvStorSataInterruptEnableDisableByMask(param_1,param_3,'\0',uVar7);
  uVar8 = NvStorProtocolAtaIdentifyDevice(param_2);
  uVar15 = uVar8 & 0xffffffff;
  if ((int)uVar8 < 0) goto LAB_0001958c;
  param_2[0x112] = param_2[0x112] | 0x200;
  uVar8 = param_2[0x112];
  if ((uVar8 & 0x20) != 0) {
    if ((*pbVar3 & 0x20) == 0) {
      uVar8 = uVar8 & 0xffffffffffffffbf;
    }
    else {
      uVar8 = uVar8 | 0x40;
    }
    param_2[0x112] = uVar8;
    if ((pbVar3[1] & 0x1f) == 1) {
      param_2[0x112] = param_2[0x112] & 0xfffffffffffffdff;
    }
  }
  if ((*(byte *)(param_2 + 0x112) & 0x20) == 0) {
    cVar4 = (**(code **)(NvStorOsCBT + 0x1c8))(param_1);
    uVar7 = *(uint *)(*param_1 + 0x25f0);
    if (cVar4 != '\0') {
      param_2[0x112] = param_2[0x112] | 0x800000000000;
    }
    NvStorScsiBuildInquiryPage
              ((char *)pbVar3,(byte *)(param_2 + 6),(longlong)local_60,
               cVar4 != '\0' | ~(byte)(uVar7 >> 0xb) & 2);
    pbVar9 = local_48;
    pbVar14 = local_58;
    pbVar13 = local_60;
  }
  else {
    NvStorProtocolAtapiGetInquiryData(param_2,param_2 + 6);
    pbVar9 = (byte *)(param_2 + 10);
    pbVar14 = (byte *)(param_2 + 8);
    pbVar13 = (byte *)(param_2 + 7);
  }
  pbVar9 = NvStorGetDeviceQuirks(pbVar13,pbVar14,pbVar9);
  param_2[0x112] = param_2[0x112] & 0xfffffffffdffffff;
  param_2[1] = (longlong)pbVar9;
  if ((*(uint *)(pbVar9 + 0x20) & 0x20) != 0) {
    param_2[0x112] = param_2[0x112] | 0x400000000;
  }
  if ((char)*pbVar3 < '\0') {
    param_2[0x112] = param_2[0x112] | 1;
  }
  if ((*(ushort *)(pbVar3 + 0xa6) & 0x400) != 0) {
    param_2[0x112] = param_2[0x112] | 0x10;
  }
  if ((*(ushort *)(pbVar3 + 0xd4) & 0x1000) == 0) {
    iVar6 = 0x200;
  }
  else {
    iVar6 = *(int *)(pbVar3 + 0xea) * 2;
  }
  *(int *)(param_2 + 0x46) = iVar6;
  if ((*(ushort *)(pbVar3 + 0xd4) & 0x2000) != 0) {
    param_2[0x112] = param_2[0x112] | 0x40000000000000;
    *(byte *)((longlong)param_2 + 0x234) = pbVar3[0xd4] & 0xf;
    *(ushort *)((longlong)param_2 + 0x236) = *(ushort *)(pbVar3 + 0x1a2) & 0x3fff;
  }
  *(uint *)(param_2 + 0x47) = (uint)pbVar3[0x5e] * (int)param_2[0x46];
  if ((*(byte *)(param_2 + 0x112) & 0x10) == 0) {
    uVar2 = *(ushort *)(pbVar3 + 0x78);
    uVar8 = (ulonglong)*(ushort *)(pbVar3 + 0x7a);
  }
  else {
    uVar8 = (ulonglong)*(uint6 *)(pbVar3 + 0xca);
    uVar2 = *(ushort *)(pbVar3 + 200);
  }
  param_2[0x45] = (uVar8 << 0x10 | (ulonglong)uVar2) - 1;
  if (pbVar3[0xb1] == 0) {
LAB_00018fe4:
    if (pbVar3[0x7f] != 0) goto LAB_00018ff5;
    param_2[0x112] = param_2[0x112] & 0xffffffffffffff7f;
  }
  else {
    if (pbVar3[0x7f] != 0) {
      pbVar3[0x7e] = 0;
      pbVar3[0x7f] = 0;
    }
    if (pbVar3[0xb1] == 0) goto LAB_00018fe4;
LAB_00018ff5:
    uVar8 = param_2[0x112];
    if (((uVar8 & 0x20) == 0) || ((pbVar3[1] & 0x1f) != 1)) {
      param_2[0x112] = uVar8 | 0x80;
    }
    else {
      param_2[0x112] = uVar8 & 0xffffffffffffff7f;
      pbVar3[0xb0] = 0;
      pbVar3[0xb1] = 0;
      pbVar3[0x7e] = 0;
      pbVar3[0x7f] = 0;
    }
  }
  if ((param_2[0x112] & 0x20U) == 0) {
    uVar8 = param_2[0x112] & 0xfffffffffffffeff;
    param_2[0x112] = uVar8;
    if (1 < pbVar3[0x5e]) {
      if ((ushort)(*(ushort *)(pbVar3 + 0x76) & 0x1ff) == (ushort)(pbVar3[0x5e] | 0x100)) {
        param_2[0x112] = uVar8 | 0x100;
      }
      else {
        (**(code **)(NvStorOsCBT + 0x110))(&local_70,0xb);
        local_6f = pbVar3[0x5e];
        local_66 = 0xc6;
        NvStorProtocolAtaSendCommandAndBusyWaitInterrupt(param_2,&local_70,local_78,'\x01');
        if ((local_78[0] & 1) == 0) {
          param_2[0x112] = param_2[0x112] | 0x100;
        }
      }
    }
  }
  FUN_0001a25c(param_2);
  if (((((*(byte *)(param_2 + 0x112) & 0x20) == 0) && ((*(ushort *)(pbVar3 + 0x100) & 1) != 0)) &&
      ((*(ushort *)(pbVar3 + 0x100) & 8) == 0)) && ((*(uint *)(*param_1 + 0x2818) & 0x800) != 0)) {
    (**(code **)(NvStorOsCBT + 0x1a8))(param_2);
    (**(code **)(NvStorOsCBT + 0x110))(&local_70,0xb);
    local_66 = 0xf5;
    NvStorProtocolAtaSendCommandAndBusyWaitInterrupt(param_2,&local_70,local_78,'\x01');
  }
  if (((pbVar3[0xa4] & 0x20) != 0) && (uVar8 = param_2[0x112], (uVar8 & 0x20) == 0)) {
    param_2[0x112] = uVar8 | 0x800;
    if ((pbVar3[0xaa] & 0x20) == 0) {
      uVar8 = uVar8 & 0xffffffffffffefff | 0x800;
    }
    else {
      uVar8 = uVar8 | 0x1800;
    }
    param_2[0x112] = uVar8;
    param_2[0x112] = param_2[0x112] | 0x1000;
  }
  if ((pbVar3[0xa6] & 8) != 0) {
    param_2[0x112] = param_2[0x112] | 0x1000000000;
  }
  if ((*(ushort *)(pbVar3 + 0xa6) & 0x200) != 0) {
    param_2[0x112] = param_2[0x112] | 0x40000000000;
  }
  if ((pbVar3[0xee] & 2) != 0) {
    param_2[0x112] = param_2[0x112] | 0x4000000000;
  }
  if ((pbVar3[0xee] & 0x20) != 0) {
    param_2[0x112] = param_2[0x112] | 0x10000000000;
  }
  *(undefined2 *)(param_2 + 0x44) = 1;
  if ((pbVar3[0xa8] & 0x20) != 0) {
    param_2[0x112] = param_2[0x112] | 0x800000000;
  }
  if ((param_2[0x112] & 0x20U) == 0) {
    bVar5 = *pbVar3;
  }
  else {
    bVar5 = *(byte *)((longlong)param_2 + 0x31);
  }
  if ((char)bVar5 < '\0') {
    param_2[0x112] = param_2[0x112] | 1;
  }
  uVar7 = FUN_00015608((longlong *)*param_2,0);
  pbVar3[0x204] = 0;
  pbVar3[0x205] = 0;
  pbVar3[0x206] = 0;
  pbVar3[0x207] = 0;
  *(uint *)(pbVar3 + 0x200) = uVar7 & 0xf0;
  if ((pbVar3[0x98] & 2) != 0) {
    pbVar3[0x204] = 0x10;
    pbVar3[0x205] = 0;
    pbVar3[0x206] = 0;
    pbVar3[0x207] = 0;
  }
  if ((pbVar3[0x98] & 4) != 0) {
    *(uint *)(pbVar3 + 0x204) = *(uint *)(pbVar3 + 0x204) | 0x20;
  }
  if (*(int *)(pbVar3 + 0x204) == 0) {
    *(uint *)(pbVar3 + 0x204) = uVar7 & 0xf0;
  }
  if ((*(ushort *)(pbVar3 + 0x98) & 0x200) != 0) {
    param_2[0x112] = param_2[0x112] | 0x80000;
  }
  if ((*(byte *)(param_2 + 0x112) & 0x20) == 0) {
    uVar8 = NvStorProtocolAtaIdentifyDevice(param_2);
    uVar15 = uVar8 & 0xffffffff;
    if ((int)uVar8 < 0) goto LAB_0001958c;
  }
  NvStorDeviceBuildIdentifyString((longlong)param_2,(longlong)pbVar3);
  NvStorSataSetProtocol(param_2,0);
  param_2[0x6d] = (longlong)NvStorSataSetupCommand;
  param_2[0x72] = 0;
  param_2[0x75] = (longlong)NvStorSataSetProtocol;
  if ((*(uint *)(param_2 + 0x112) & 0x8000) != 0) {
    NvStorSataSetProtocol(param_2,4);
    param_2[0x72] = (longlong)NvStorProtocolNcqInitialize;
  }
  if ((code *)param_2[0x72] != (code *)0x0) {
    uVar7 = (*(code *)param_2[0x72])(param_2);
    uVar15 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) goto LAB_0001958c;
  }
  param_2[0x112] = param_2[0x112] | 0x800000;
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffd;
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffb;
  uVar7 = NvStorSataInterruptGetAppropriateMask(param_1,param_3);
  NvStorSataInterruptEnableDisableByMask(param_1,param_3,'\x01',uVar7);
  NvStorInitializeTags(param_2,0x20);
  lVar10 = *(longlong *)*param_2;
  plVar1 = param_2 + 0x36;
  param_2[0x37] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  *(undefined4 *)((longlong)param_2 + 0x1dc) = 0xffffffff;
  param_2[0x35] = lVar10;
  *(undefined4 *)(param_2 + 0x39) = 0;
  *(uint *)((longlong)param_2 + 0x1cc) = (uint)*(ushort *)(param_2 + 0x44);
  param_2[0x38] = (longlong)(param_2 + 0x48);
  param_2[0x3a] = 0;
  param_2[0x3c] = 0;
  param_2[0x3d] = 0;
  param_2[0x3e] = 0;
  *(undefined4 *)(param_2 + 0x3b) = 0x100;
  if ((*(byte *)(param_2 + 0x112) & 0x20) == 0) {
    *(undefined4 *)((longlong)param_2 + 0x1d4) = 2;
  }
  if (((*(uint *)(param_2 + 0x112) & 0x8000) != 0) &&
     ((*(uint *)(*(longlong *)*param_2 + 0x25f0) & 0x200) != 0)) {
    *(uint *)((longlong)param_2 + 0x1d4) = *(uint *)((longlong)param_2 + 0x1d4) | 1;
  }
  if (param_2[0x2e] == 0) {
    lVar10 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0xb,0,1);
    param_2[0x2e] = lVar10;
    if (lVar10 != 0) goto LAB_0001944a;
  }
  else {
LAB_0001944a:
    if (param_2[0x33] == 0) {
      lVar10 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0xff,0,1);
      param_2[0x33] = lVar10;
      if (lVar10 == 0) goto LAB_00019440;
    }
    if (param_2[0xed] != 0) {
LAB_000194a9:
      (**(code **)(NvStorOsCBT + 0x110))(param_2[0xed],0xb);
      pcVar11 = NvStorSataAtapiHandleError;
      if ((*(byte *)(param_2 + 0x112) & 0x20) == 0) {
        pcVar11 = NvStorSataAtaHandleError;
      }
      param_2[0x6f] = (longlong)pcVar11;
      param_2[0x6e] = (longlong)NvStorSataAtaSuccess;
      param_2[0x70] = (longlong)NvStorSataAtaCancel;
      param_2[0x71] = (longlong)NvStorAtaDeviceReset;
      NvStorScsiPrintDeviceSummary((longlong)param_2);
      if ((((((*(uint *)(*(longlong *)*param_2 + 0x2818) & 2) == 0) &&
            ((param_2[0x112] & 0x20U) == 0)) && ((*(ushort *)(pbVar3 + 0x100) & 1) != 0)) &&
          (((*(ushort *)(pbVar3 + 0x100) & 8) == 0 && ((param_2[0x112] & 0x10000000000000U) == 0))))
         && (((*(uint *)(*param_1 + 0x2818) & 0x800) == 0 &&
             (uVar12 = NvStorSataSetupFeatureRequest(param_2,(longlong)(param_2 + 0xf2)),
             -1 < (int)uVar12)))) {
        param_2[0x112] = param_2[0x112] | 0x18000000000000;
      }
      return 0;
    }
    lVar10 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0xb,0,1);
    param_2[0xed] = lVar10;
    if (lVar10 != 0) goto LAB_000194a9;
  }
LAB_00019440:
  uVar15 = 0x80000011;
LAB_0001958c:
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffd;
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffb;
  uVar7 = NvStorSataInterruptGetAppropriateMask(param_1,param_3);
  NvStorSataInterruptEnableDisableByMask(param_1,param_3,'\x01',uVar7);
  if (param_2[0x2e] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x2e],1);
    param_2[0x2e] = 0;
  }
  if (param_2[0x33] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x33],1);
    param_2[0x33] = 0;
  }
  if (param_2[0xed] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0xed],1);
    param_2[0xed] = 0;
  }
  if (param_2[0x10b] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x10b],1);
    param_2[0x10b] = 0;
  }
  param_1[(ulonglong)param_3 + 1] = 0;
  return uVar15;
}



===== NvStorSataInterruptGetAppropriateMask @ 00019688 =====

uint NvStorSataInterruptGetAppropriateMask(longlong *param_1,char param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar6 = 0;
  if (*(ushort *)(param_1 + 2) == 0) {
LAB_000196e4:
    iVar3 = 0xd;
  }
  else {
    plVar5 = param_1;
    do {
      plVar5 = plVar5 + 1;
      lVar1 = *plVar5;
      if ((lVar1 != 0) && (*(char *)(lVar1 + 0x222) == param_2)) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)(param_1 + 2));
    if ((lVar1 == 0) || (uVar2 = *(ulonglong *)(lVar1 + 0x890), (uVar2 >> 0xe & 1) == 0))
    goto LAB_000196e4;
    if (((uVar2 >> 0xf & 1) == 0) && ((uVar2 >> 0x10 & 1) == 0)) goto LAB_000196f6;
    iVar3 = 0xfd;
  }
  uVar4 = iVar3 << ((*(byte *)(param_1 + 0x1b) & 1) << 4);
LAB_000196f6:
  if ((*(uint *)(*param_1 + 0x25f0) & 0x20) != 0) {
    uVar4 = uVar4 | 0xc0000000;
  }
  return uVar4;
}



===== NvStorSataInterruptEnableDisableByMask @ 0001970c =====

void NvStorSataInterruptEnableDisableByMask
               (longlong *param_1,char param_2,char param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (param_3 == '\0') {
    uVar2 = 0;
    uVar6 = 2;
    plVar4 = param_1;
    if (*(ushort *)(param_1 + 2) != 0) {
      do {
        plVar4 = plVar4 + 1;
        lVar1 = *plVar4;
        if ((lVar1 != 0) && (*(char *)(lVar1 + 0x222) == param_2)) {
          uVar6 = 2;
          if ((*(byte *)(lVar1 + 0x890) & 0x20) != 0) {
            uVar6 = 0;
          }
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(param_1 + 2));
    }
  }
  else {
    uVar6 = 0;
    if (param_1[0x19] == 0) {
      (*(code *)*NvStorOsCBT)(*param_1,(short)param_1[3] + 7);
    }
    else {
      (*(code *)NvStorOsCBT[6])(*param_1,param_1[0x19] + 0x1c);
    }
  }
  if (param_1[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*param_1,(short)param_1[3] + 6,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*param_1,param_1[0x19] + 0x18);
  }
  if (param_1[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*param_1,(short)param_1[7] + 2,uVar6);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*param_1,param_1[0x19] + 0x1c);
  }
  uVar2 = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      uVar2 = FUN_00015608(param_1,6);
    }
  }
  else {
    uVar2 = FUN_00015608(param_1,5);
    uVar2 = (uVar2 & 0xf000) << 4 | uVar2 >> 8 & 0xf;
  }
  if (param_3 == '\0') {
    uVar2 = uVar2 & ~param_4;
  }
  else {
    uVar7 = 0x3ff << ((*(byte *)(param_1 + 0x1b) & 1) << 4);
    uVar2 = uVar2 | param_4;
  }
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) goto LAB_000198c4;
  }
  else {
    uVar3 = FUN_00015608(param_1,5);
    uVar7 = uVar3 & 0xff00 | uVar7 >> 0xc & 0xf0 | uVar7 & 0xf;
  }
  FUN_000154b8(param_1,5,uVar7);
LAB_000198c4:
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) == 0) {
      return;
    }
    iVar5 = 6;
  }
  else {
    iVar5 = 5;
    uVar2 = uVar2 >> 4 & 0xf000 | (uVar2 & 0xf) << 8;
  }
  FUN_000154b8(param_1,iVar5,uVar2);
  return;
}



===== NvStorSataSetupCommand @ 00019920 =====

undefined4 NvStorSataSetupCommand(longlong param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 0x80000003;
  uVar4 = 0;
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x1c);
  piVar1 = &DAT_00035460;
  do {
    piVar2 = piVar1;
    if (*piVar2 == *(int *)(param_1 + 0xc4)) break;
    uVar4 = uVar4 + 1;
    piVar1 = piVar2 + 8;
  } while (uVar4 < 10);
  if (uVar4 == 10) {
    piVar2 = (int *)0x0;
  }
  if (piVar2 != (int *)0x0) {
    uVar3 = 1;
    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(piVar2 + 2);
  }
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 0x20) != 0) {
    uVar3 = 1;
  }
  return uVar3;
}



===== NvStorSataControllerRestart @ 00019990 =====

uint NvStorSataControllerRestart(ulonglong param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  
  uVar1 = NvStorControllerStart(param_1);
  if ((-1 < (int)uVar1) && (uVar3 = 0, *(char *)(param_1 + 0x2500) != '\0')) {
    do {
      uVar1 = 0;
      plVar4 = (longlong *)(uVar3 * 0x128 + param_1);
      if (*(code **)(*plVar4 + 0x2748) != (code *)0x0) {
        uVar1 = (**(code **)(*plVar4 + 0x2748))(plVar4);
      }
      if ((int)uVar1 < 0) break;
      (**(code **)(NvStorOsCBT + 0x188))(param_1,(char)plVar4[0x1b]);
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(byte *)(param_1 + 0x2500));
  }
  return uVar1;
}



===== NvStorSataControllerIsReady @ 00019a28 =====

undefined8 NvStorSataControllerIsReady(longlong param_1)

{
  ulonglong uVar1;
  ulonglong in_RAX;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  longlong *plVar5;
  
  uVar2 = 1;
  uVar1 = 0;
  if (*(char *)(param_1 + 0x2500) != '\0') {
    do {
      in_RAX = uVar1;
      cVar3 = (char)in_RAX;
      plVar5 = (longlong *)(in_RAX * 0x128 + param_1);
      if (plVar5 != (longlong *)0x0) {
        in_RAX = FUN_00015608(plVar5,0);
        if ((in_RAX & 0xf) != 0) {
          if (((((uint)in_RAX & 0xf) != 1) && ((in_RAX & 0xf0) != 0)) && ((in_RAX & 0xf00) != 0)) {
            if (plVar5[0x19] == 0) {
              in_RAX = (*(code *)*NvStorOsCBT)(*plVar5);
            }
            else {
              in_RAX = (*(code *)NvStorOsCBT[6])();
            }
            if ((in_RAX & 0x88) == 0) goto LAB_00019aad;
          }
          uVar2 = 0;
          break;
        }
      }
LAB_00019aad:
      bVar4 = cVar3 + 1;
      uVar1 = (ulonglong)bVar4;
    } while (bVar4 < *(byte *)(param_1 + 0x2500));
  }
  return CONCAT71((int7)(in_RAX >> 8),uVar2);
}



===== NvStorSataDeviceIsReady @ 00019ad4 =====

bool NvStorSataDeviceIsReady(longlong *param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar2 = FUN_00015608((longlong *)*param_1,0);
  if ((uVar2 & 0xf) == 0) {
    bVar3 = true;
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    if (puVar1[0x19] == 0) {
      uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 7);
    }
    else {
      uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x1c);
    }
    bVar3 = (uVar2 & 0x88) == 0;
  }
  return bVar3;
}



===== NvStorSataPortRestart @ 00019b48 =====

undefined8 NvStorSataPortRestart(longlong param_1)

{
  uint *puVar1;
  longlong *plVar2;
  char cVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (*(short *)(param_1 + 0x10) != 0) {
    do {
      if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_00019b88:
        plVar2 = *(longlong **)(param_1 + 8 + (ulonglong)bVar4 * 8);
        if (plVar2 != (longlong *)0x0) {
          puVar1 = (uint *)(*plVar2 + 0x120);
          *puVar1 = *puVar1 | 2;
        }
      }
      else {
        cVar3 = (**(code **)(NvStorOsCBT + 0x208))(param_1,bVar4,1);
        if (cVar3 != '\0') goto LAB_00019b88;
      }
      bVar4 = bVar4 + 1;
    } while ((ushort)bVar4 < *(ushort *)(param_1 + 0x10));
  }
  return 0;
}



===== NvStorSataControllerStop @ 00019bbc =====

void NvStorSataControllerStop(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x2500) != '\0') {
    do {
      uVar1 = NvStorPortStop((longlong *)(uVar3 * 0x128 + param_1));
      if ((int)uVar1 < 0) break;
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(byte *)(param_1 + 0x2500));
  }
  *(undefined4 *)(param_1 + 0x2664) = 2;
  return;
}



===== NvStorSataPortStop @ 00019c0c =====

undefined8 NvStorSataPortStop(longlong *param_1)

{
  longlong *plVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  if ((short)param_1[2] != 0) {
    do {
      cVar4 = (char)uVar5;
      if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_00019c51:
        plVar1 = (longlong *)param_1[uVar5 + 1];
        if (plVar1 != (longlong *)0x0) {
          plVar1[0x112] = plVar1[0x112] | 0x200000000;
          uVar5 = plVar1[0x112];
          if (((((*(char *)(*param_1 + 0x2668) - 2U & 0xf9) == 0) &&
               (*(char *)(*param_1 + 0x2668) != '\b')) && ((uVar5 >> 0x17 & 1) != 0)) &&
             ((((uVar5 & 0x20) == 0 && ((uVar5 & 0x81000000) == 0)) &&
              ((*(uint *)(param_1 + 0x24) & 6) == 0)))) {
            NvStorSataSendStandBy(plVar1);
          }
        }
        uVar3 = NvStorSataInterruptGetAppropriateMask(param_1,cVar4);
        NvStorSataInterruptEnableDisableByMask(param_1,cVar4,'\0',uVar3);
      }
      else {
        cVar2 = (**(code **)(NvStorOsCBT + 0x208))(param_1,uVar5);
        if (cVar2 != '\0') goto LAB_00019c51;
      }
      uVar5 = (ulonglong)(byte)(cVar4 + 1U);
    } while ((ushort)(byte)(cVar4 + 1U) < *(ushort *)(param_1 + 2));
  }
  return 0;
}



===== NvStorSataDeviceStart @ 00019cf4 =====

void NvStorSataDeviceStart(undefined8 *param_1)

{
  uint uVar1;
  undefined1 local_res8 [32];
  
  local_res8[0] = ((ulonglong)param_1[0x112] >> 0xe & 1) == 0 && (param_1[0x112] & 0x20) == 0;
  uVar1 = NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],
                          '$',(ulonglong *)local_res8,1);
  if (((-1 < (int)uVar1) &&
      (uVar1 = NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                               (longlong *)param_1[0xb6],'2',(ulonglong *)(param_1[0x110] + 0x204),4
                              ), -1 < (int)uVar1)) &&
     (uVar1 = NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                              (longlong *)param_1[0xb6],'3',(ulonglong *)(param_1[0x110] + 0x200),4)
     , -1 < (int)uVar1)) {
    NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'4',
                    (ulonglong *)(param_1[0x110] + 0x200),4);
  }
  return;
}



===== NvStorSataDeviceRemove @ 00019e10 =====

undefined8 NvStorSataDeviceRemove(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  if ((*(uint *)(param_1 + 0x112) >> 0x17 & 1) != 0) {
    NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000002,param_3,1);
  }
  if (param_1[0x2e] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x2e],1);
    param_1[0x2e] = 0;
  }
  if (param_1[0x33] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x33],1);
    param_1[0x33] = 0;
  }
  if (param_1[0xed] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0xed],1);
    param_1[0xed] = 0;
  }
  if (param_1[0x10b] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x10b],1);
    param_1[0x10b] = 0;
  }
  return 0;
}



===== NvStorSataDeviceCfgStart @ 00019eec =====

uint NvStorSataDeviceCfgStart(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (((param_1[0x112] & 0x1000000000U) != 0) && ((param_1[0x112] & 0x2000000000U) != 0)) {
    uVar1 = FUN_0001a378(param_1,5,*(undefined1 *)((longlong)param_1 + 0x89a));
  }
  if (((param_1[0x112] & 0x40000000000U) != 0) && ((param_1[0x112] & 0x80000000000U) != 0)) {
    uVar2 = FUN_0001a378(param_1,0x42,*(undefined1 *)((longlong)param_1 + 0x89b));
    uVar1 = uVar1 | uVar2;
  }
  if (((param_1[0x112] & 0x10000000000U) != 0) && ((param_1[0x112] & 0x20000000000U) != 0)) {
    uVar2 = FUN_0001a378(param_1,0x41,0);
    uVar1 = uVar1 | uVar2;
  }
  if (((param_1[0x112] & 0x4000000000U) != 0) && ((param_1[0x112] & 0x8000000000U) != 0)) {
    uVar2 = FUN_0001a378(param_1,0xb,0);
    uVar1 = uVar1 | uVar2;
  }
  return uVar1;
}



===== NvStorSataSetProtocol @ 00019fe0 =====

undefined4 NvStorSataSetProtocol(undefined8 *param_1,int param_2)

{
  longlong *plVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  
  uVar3 = 0;
  uVar6 = 0x80000003;
  uVar4 = 0;
  piVar2 = &DAT_00035460;
  do {
    piVar7 = piVar2;
    if (*piVar7 == param_2) break;
    uVar4 = uVar4 + 1;
    piVar2 = piVar7 + 8;
  } while (uVar4 < 10);
  if (uVar4 == 10) {
    piVar7 = (int *)0x0;
  }
  if (piVar7 != (int *)0x0) {
    uVar6 = 0;
    param_1[0x73] = *(undefined8 *)(piVar7 + 4);
    param_1[0x74] = *(undefined8 *)(piVar7 + 6);
  }
  if ((((ulonglong)param_1[0x112] >> 0x17 & 1) != 0) &&
     (((ulonglong)param_1[0x112] >> 0xd & 1) != 0)) {
    plVar1 = (longlong *)*param_1;
    if ((*(uint *)(*plVar1 + 0x25f0) & 4) == 0) {
      if ((*(uint *)(*plVar1 + 0x25f0) & 8) != 0) {
        uVar3 = FUN_00015608(plVar1,6);
      }
    }
    else {
      uVar3 = FUN_00015608(plVar1,5);
      uVar3 = (uVar3 & 0xf000) << 4 | uVar3 >> 8 & 0xf;
    }
    plVar1 = (longlong *)*param_1;
    uVar4 = 0xf0 << ((*(byte *)(plVar1 + 0x1b) & 1) << 4);
    if (param_2 == 4) {
      uVar4 = uVar4 | uVar3;
    }
    else {
      uVar4 = ~uVar4 & uVar3;
    }
    if ((*(uint *)(*plVar1 + 0x25f0) & 4) == 0) {
      if ((*(uint *)(*plVar1 + 0x25f0) & 8) == 0) {
        return uVar6;
      }
      iVar5 = 6;
    }
    else {
      uVar4 = uVar4 >> 4 & 0xf000 | (uVar4 & 0xf) << 8;
      iVar5 = 5;
    }
    FUN_000154b8(plVar1,iVar5,uVar4);
  }
  return uVar6;
}



===== NvStorSataDeviceConfigNotify @ 0001a118 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NvStorSataDeviceConfigNotify(int param_1,undefined8 *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined1 auStackY_58 [32];
  char local_28 [8];
  undefined1 local_20 [16];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  uVar2 = 0;
  lVar1 = *(longlong *)*param_2;
  if (param_1 == 0) {
    if (param_3 == 0x26) {
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'&',
                              (undefined8 *)local_28,1);
      if (local_28[0] == '\0') {
        param_2[0x112] = param_2[0x112] & 0xffffffffffffff7f;
      }
      else {
        param_2[0x112] = param_2[0x112] | 0x80;
      }
    }
    else if (param_3 == 0x28) {
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'(',
                              (undefined8 *)local_28,1);
      (**(code **)(NvStorOsCBT + 0x110))(local_20,0xb);
      if (local_28[0] == '\0') {
        param_2[0x112] = param_2[0x112] & 0xffffffffffffefff;
      }
      else {
        param_2[0x112] = param_2[0x112] | 0x1000;
      }
    }
    else {
      if (param_3 == 0x32) {
        cVar3 = '2';
        puVar4 = (undefined8 *)(param_2[0x110] + 0x204);
      }
      else {
        if (param_3 != 0x33) {
          return 0;
        }
        cVar3 = '3';
        puVar4 = (undefined8 *)(param_2[0x110] + 0x200);
      }
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],cVar3,puVar4,4
                             );
    }
  }
  return uVar2;
}



===== FUN_0001a25c @ 0001a25c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0001a25c(longlong *param_1)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  char cVar4;
  undefined1 auStack_48 [32];
  byte local_28 [8];
  undefined1 local_20;
  char local_1f;
  undefined1 local_16;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  lVar2 = (**(code **)(NvStorOsCBT + 0x1a8))();
  bVar1 = *(byte *)(lVar2 + 0x80);
  (**(code **)(NvStorOsCBT + 0x110))(&local_20,0xb);
  local_20 = 3;
  local_16 = 0xef;
  local_1f = ((bVar1 & 2) != 0) + '\v';
  NvStorProtocolAtaSendCommandAndBusyWaitInterrupt(param_1,&local_20,local_28,'\x01');
  if ((*(byte *)(lVar2 + 0xb0) & 0x7f) == 0) {
    if ((*(byte *)(lVar2 + 0x7e) & 7) == 0) {
      return;
    }
    cVar4 = ' ';
    bVar1 = 4;
    bVar3 = *(byte *)(lVar2 + 0x7e) & 7;
  }
  else {
    cVar4 = '@';
    bVar3 = *(byte *)(lVar2 + 0xb0) & 0x7f;
    bVar1 = 0x40;
  }
  for (; (bVar1 & bVar3) == 0; bVar1 = bVar1 >> 1) {
  }
  if (bVar1 != 0) {
    for (; (bVar1 & 1) == 0; bVar1 = bVar1 >> 1) {
      cVar4 = cVar4 + '\x01';
    }
    (**(code **)(NvStorOsCBT + 0x110))(&local_20,0xb);
    local_20 = 3;
    local_16 = 0xef;
    local_1f = cVar4;
    NvStorProtocolAtaSendCommandAndBusyWaitInterrupt(param_1,&local_20,local_28,'\x01');
    if ((local_28[0] & 1) == 0) {
      param_1[0x112] = param_1[0x112] | 0x80;
    }
  }
  return;
}



===== FUN_0001a378 @ 0001a378 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0001a378(longlong *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 auStack_58 [32];
  byte local_38 [8];
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_26;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  (**(code **)(NvStorOsCBT + 0x110))(&local_30,0xb);
  local_26 = 0xef;
  local_30 = param_2;
  local_2f = param_3;
  NvStorProtocolAtaSendCommandAndBusyWaitInterrupt(param_1,&local_30,local_38,'\x01');
  return -(uint)((local_38[0] & 1) != 0) & 0x80000003;
}



===== NvStorSataSendStandBy @ 0001a3f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NvStorSataSendStandBy(longlong *param_1)

{
  undefined1 auStack_48 [32];
  byte local_28 [8];
  undefined1 local_20 [10];
  undefined1 local_16;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  (**(code **)(NvStorOsCBT + 0x1a8))();
  (**(code **)(NvStorOsCBT + 0x110))(local_20,0xb);
  local_16 = 0xe0;
  NvStorProtocolAtaSendCommandAndWait(param_1,local_20,local_28);
  return -(uint)((local_28[0] & 1) != 0) & 0x80000003;
}



===== NvStorSataPortDetectDevicePresense @ 0001a470 =====

bool NvStorSataPortDetectDevicePresense(longlong *param_1)

{
  byte bVar1;
  
  bVar1 = FUN_00015608(param_1,0);
  return (bVar1 & 0xf) == 3;
}



===== NvStorDeviceResetCrashdump @ 0001a4b0 =====

undefined8 NvStorDeviceResetCrashdump(longlong *param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  puVar1 = (undefined8 *)*param_1;
  uVar2 = (*(code *)*NvStorOsCBT)
                    (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 8 + 2 + *(short *)(puVar1 + 0xb));
  if ((uVar2 & 1) != 0) {
    uVar4 = 0;
    do {
      puVar1 = (undefined8 *)*param_1;
      uVar2 = (*(code *)*NvStorOsCBT)
                        (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 8 + 2 + *(short *)(puVar1 + 0xb)
                        );
      if ((uVar2 & 1) == 0) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10000);
  }
  puVar1 = (undefined8 *)*param_1;
  (*(code *)NvStorOsCBT[0xc])
            (*puVar1,(ushort)*(byte *)(puVar1 + 0x1b) * 8 + *(short *)(puVar1 + 0xb));
  NvStorSataIssueSRST((undefined8 *)*param_1);
  if (((param_1[0x112] & 0x800000000U) != 0) && (((ulonglong)param_1[0x112] >> 0xe & 1) != 0)) {
    uVar4 = NvStorSataCrashDumpReadLogExt(param_1,'\x01');
    if (uVar4 != 0) {
      NvStorSataIssueSRST((undefined8 *)*param_1);
      uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      if ((char)uVar3 < '\0') {
        return 0x80000006;
      }
    }
    uVar4 = NvStorSataCrashDumpReadLogExt(param_1,'\x01');
    if (uVar4 != 0) {
      NvStorSataIssueSRST((undefined8 *)*param_1);
      uVar3 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      if ((char)uVar3 < '\0') {
        return 0x80000006;
      }
    }
  }
  return 0;
}



===== NvStorSataDeviceBuildInquiryPage @ 0001a5c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorSataDeviceBuildInquiryPage(longlong param_1)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined1 auStack_58 [32];
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pcVar1 = *(char **)(param_1 + 0x880);
  bVar3 = 0;
  (**(code **)(NvStorOsCBT + 0x110))(param_1 + 0x30,0x60);
  bVar2 = 0;
  do {
    if (*(char *)((ulonglong)bVar2 + 0x2130 + param_1) != (&s_NVIDIA)[bVar2]) {
      *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) & 0xffff7fffffffffff;
      goto LAB_0001a64d;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 6);
  bVar3 = 1;
  *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) | 0x800000000000;
LAB_0001a64d:
  NvStorScsiBuildInquiryPage(pcVar1,(byte *)(param_1 + 0x30),(longlong)local_38,bVar3 | 2);
  return;
}



===== NvStorSataAtapiResetTimer @ 0001a688 =====

void NvStorSataAtapiResetTimer(longlong *param_1)

{
  char *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  byte bVar5;
  int iVar6;
  
  pcVar1 = (char *)((longlong)param_1 + 0x899);
  *pcVar1 = *pcVar1 + -1;
  puVar2 = (undefined8 *)*param_1;
  if (*pcVar1 == '\0') {
    param_1[0x112] = param_1[0x112] | 0x1000000;
    goto LAB_0001a868;
  }
  if ((*(byte *)(param_1 + 0x113) & 2) == 0) {
    if ((*(byte *)(param_1 + 0x113) & 4) == 0) goto LAB_0001a868;
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6,0);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
    }
    puVar3 = (undefined8 *)*param_1;
    if (puVar3[0x19] == 0) {
      bVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 7);
    }
    else {
      bVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
    }
    if ((bVar5 & 1) == 0) {
      if ((char)bVar5 < '\0') goto LAB_0001a868;
      pcVar4 = *(code **)(*(longlong *)*param_1 + 0x2778);
      if (pcVar4 == (code *)0x0) goto LAB_0001a868;
      iVar6 = (*pcVar4)((longlong *)*param_1,param_1,*(undefined1 *)((longlong)param_1 + 0x222));
      if (-1 < iVar6) {
        *(byte *)(param_1 + 0x113) = *(byte *)(param_1 + 0x113) & 0xfa;
        goto LAB_0001a868;
      }
    }
  }
  else {
    if (puVar2[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6,0);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
    }
    puVar3 = (undefined8 *)*param_1;
    if (puVar3[0x19] == 0) {
      bVar5 = (*(code *)*NvStorOsCBT)(*puVar3,*(short *)(puVar3 + 3) + 7);
    }
    else {
      bVar5 = (*(code *)NvStorOsCBT[6])(*puVar3,puVar3[0x19] + 0x1c);
    }
    if ((bVar5 & 1) == 0) {
      if (-1 < (char)bVar5) {
        puVar3 = (undefined8 *)*param_1;
        *(byte *)(param_1 + 0x113) = *(byte *)(param_1 + 0x113) & 0xfd | 4;
        if (puVar3[0x19] == 0) {
          (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 6,0);
        }
        else {
          (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x18);
        }
        puVar3 = (undefined8 *)*param_1;
        if (puVar3[0x19] == 0) {
          (*(code *)NvStorOsCBT[0xc])(*puVar3,*(short *)(puVar3 + 3) + 7,8);
        }
        else {
          (*(code *)NvStorOsCBT[0x12])(*puVar3,puVar3[0x19] + 0x1c);
        }
        (*(code *)NvStorOsCBT[0x30])(1);
      }
      goto LAB_0001a868;
    }
  }
  param_1[0x112] = param_1[0x112] | 0x1000000;
LAB_0001a868:
  if ((*(uint *)(param_1 + 0x112) & 0x1000000) != 0) {
    *(undefined1 *)(param_1 + 0x113) = 0;
    puVar2[(ulonglong)*(byte *)((longlong)param_1 + 0x222) + 1] = 0;
    (*(code *)NvStorOsCBT[0x31])(*puVar2,*(undefined1 *)(puVar2 + 0x1b));
    if ((code *)NvStorOsCBT[0x3d] != (code *)0x0) {
      (*(code *)NvStorOsCBT[0x3d])(param_1,0,5);
    }
  }
  return;
}



===== NvStorSataScsi @ 0001a8d0 =====

int NvStorSataScsi(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  bool bVar9;
  
  puVar3 = *(undefined8 **)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0xc0);
  if ((uVar2 >> 0xe & 1) == 0) {
    *(undefined8 *)(param_1 + 0xa0) = puVar3[0x6f];
    *(undefined8 *)(param_1 + 0x98) = puVar3[0x6e];
    *(undefined8 *)(param_1 + 0xa8) = puVar3[0x70];
  }
  *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
  iVar6 = -0x7ffffff9;
  if (((uVar2 >> 0x12 & 1) != 0) && ((uVar2 >> 0x15 & 1) != 0)) {
    *(byte *)(*(longlong *)(param_1 + 200) + 10) = ~(byte)(uVar2 >> 0x11) & 1 | 0xe0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    (**(code **)(*(longlong *)(param_1 + 0x10) + 0x368))(param_1);
    *(undefined4 *)(param_1 + 0x88) = 1;
    return 1;
  }
  if ((puVar3[0x112] & 0x200000000) != 0) {
    puVar3[0x112] = puVar3[0x112] & 0xfffffffdffffffff;
  }
  if (((*(byte *)(puVar3 + 0x112) & 0x20) != 0) && (*(char *)(param_1 + 0x40) != -0x60)) {
    uVar7 = FUN_0001bfc0(param_1);
    iVar6 = (int)uVar7;
    goto LAB_0001ac0a;
  }
  bVar1 = *(byte *)(param_1 + 0x40);
  if (0x2a < bVar1) {
    if (bVar1 < 0x8b) {
      if (bVar1 == 0x8a) goto LAB_0001aa73;
      if (bVar1 != 0x2f) {
        if (bVar1 != 0x35) {
          if (bVar1 == 0x55) {
LAB_0001ab29:
            uVar8 = FUN_0001b1e4(param_1);
            iVar6 = (int)uVar8;
            goto LAB_0001ac0a;
          }
          if (bVar1 != 0x5a) {
            bVar9 = bVar1 == 0x88;
            goto LAB_0001aa6d;
          }
          goto LAB_0001ab1c;
        }
        goto LAB_0001abce;
      }
    }
    else if (bVar1 != 0x8f) {
      if (bVar1 != 0x91) {
        if (bVar1 == 0x9e) {
          uVar8 = FUN_0001bcd8(param_1);
          iVar6 = (int)uVar8;
          goto LAB_0001ac0a;
        }
        if (bVar1 == 0xa0) {
          uVar8 = FUN_0001bb68(param_1);
          iVar6 = (int)uVar8;
          goto LAB_0001ac0a;
        }
LAB_0001ab55:
        puVar4 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
        *(undefined4 *)(param_1 + 0x88) = 0x80000007;
        *(undefined1 *)(param_1 + 0x8c) = 2;
        if (puVar4 != (undefined1 *)0x0) {
          (**(code **)(NvStorOsCBT + 0x110))(puVar4,0x12);
          *puVar4 = 0xf0;
          puVar4[7] = 0xb;
          *(undefined2 *)(puVar4 + 0xc) = 0x20;
          puVar4[2] = puVar4[2] & 0xf5 | 5;
          *(undefined1 *)(param_1 + 0x78) = 0x12;
          *(undefined1 *)(param_1 + 0x8d) = 1;
        }
        goto LAB_0001ac0a;
      }
LAB_0001abce:
      uVar8 = FUN_0001b748(param_1);
      iVar6 = (int)uVar8;
      goto LAB_0001ac0a;
    }
    lVar5 = *(longlong *)(param_1 + 200);
    uVar8 = FUN_0001b7c8(param_1);
    iVar6 = (int)uVar8;
    if (iVar6 < 0) goto LAB_0001ac0a;
    *(byte *)(lVar5 + 10) = *(byte *)(param_1 + 0xc0) >> 3 & 2 | 0x40;
LAB_0001ac02:
    *(undefined4 *)(param_1 + 0xc4) = 0;
    iVar6 = 1;
    goto LAB_0001ac0a;
  }
  if (bVar1 == 0x2a) {
LAB_0001aa73:
    if (((*(uint *)(*(longlong *)*puVar3 + 0x2818) & 8) != 0) &&
       ((*(byte *)(param_1 + 0x41) & 8) != 0)) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x8000;
    }
    uVar8 = FUN_0001b8b0(param_1);
    iVar6 = (int)uVar8;
    goto LAB_0001ac0a;
  }
  if (0x1a < bVar1) {
    if (bVar1 == 0x1b) {
      uVar8 = FUN_0001b61c(param_1);
      iVar6 = (int)uVar8;
      goto LAB_0001ac0a;
    }
    if (bVar1 != 0x1e) {
      if (bVar1 == 0x25) {
        uVar8 = FUN_0001bc24(param_1);
        iVar6 = (int)uVar8;
        goto LAB_0001ac0a;
      }
      bVar9 = bVar1 == 0x28;
LAB_0001aa6d:
      if (!bVar9) goto LAB_0001ab55;
      goto LAB_0001aa73;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) == 0) {
      *(undefined4 *)(param_1 + 0x88) = 0x80000007;
      goto LAB_0001aa28;
    }
    *(byte *)(*(longlong *)(param_1 + 200) + 10) = ~*(byte *)(param_1 + 0x44) & 1 | 0xde;
    goto LAB_0001ac02;
  }
  if (bVar1 == 0x1a) {
LAB_0001ab1c:
    uVar8 = FUN_0001b370(param_1);
    iVar6 = (int)uVar8;
    goto LAB_0001ac0a;
  }
  if (bVar1 == 0) {
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 200) + 10) = 0xda;
      goto LAB_0001ac02;
    }
    *(undefined4 *)(param_1 + 0x88) = 0;
LAB_0001aa28:
    *(undefined1 *)(param_1 + 0x8c) = 0;
  }
  else {
    if (bVar1 == 3) {
      *(undefined1 *)(param_1 + 0x78) = 0x12;
      *(undefined8 *)(param_1 + 0x28) = 0;
      goto LAB_0001aa28;
    }
    if (bVar1 == 0x12) {
      uVar8 = NvStorScsiInquiry(param_1,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x880));
      iVar6 = (int)uVar8;
      goto LAB_0001ac0a;
    }
    if (bVar1 == 0x15) goto LAB_0001ab29;
    if (1 < bVar1 - 0x16) goto LAB_0001ab55;
  }
  iVar6 = 0;
LAB_0001ac0a:
  *(int *)(param_1 + 0x88) = iVar6;
  if (iVar6 != 1) {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x800;
  }
  return iVar6;
}



===== NvStorAtaDeviceReset @ 0001ac3c =====

uint NvStorAtaDeviceReset(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  lVar1 = param_1[0x110];
  if ((*(uint *)(param_1 + 0x112) >> 0xe & 1) != 0) {
    bVar4 = FUN_00015608((longlong *)*param_1,0);
    if (((bVar4 & 0xf) == 3) && (*(char *)(lVar1 + 0x214) != '\0')) {
      puVar2 = (undefined8 *)*param_1;
      param_3 = 0;
      (**(code **)(NvStorOsCBT + 0x60))
                (*puVar2,(ushort)*(byte *)(puVar2 + 0x1b) * 8 + *(short *)(puVar2 + 0xb));
      uVar5 = NvStorSataIssueSRST((undefined8 *)*param_1);
      if ((uVar5 == 0) && ((param_1[0x112] & 0x800000000U) != 0)) {
        uVar5 = NvStorSataCrashDumpReadLogExt(param_1,'\x01');
      }
      *(undefined1 *)(lVar1 + 0x214) = 0;
      uVar6 = 0;
      if (uVar5 == 0) goto LAB_0001ada4;
    }
  }
  plVar3 = (longlong *)*param_1;
  if ((*(byte *)(param_1 + 0x112) & 0x20) == 0) {
    uVar6 = NvStorSataResetSATAPhy(plVar3);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x60))
              (*plVar3,(ushort)*(byte *)(plVar3 + 0x1b) * 8 + (short)plVar3[0xb],0);
    puVar2 = (undefined8 *)*param_1;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 7) + 2);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x1c);
    }
    (**(code **)(NvStorOsCBT + 0x180))(5000);
    param_3 = 0;
    if (puVar2[0x19] == 0) {
      (**(code **)(NvStorOsCBT + 0x60))(*puVar2,*(short *)(puVar2 + 7) + 2);
    }
    else {
      (**(code **)(NvStorOsCBT + 0x90))(*puVar2,puVar2[0x19] + 0x1c);
    }
    (**(code **)(NvStorOsCBT + 0x180))(2000);
    uVar6 = 0;
    *(undefined2 *)(param_1 + 0x113) = 0xa03;
  }
LAB_0001ada4:
  if ((-1 < (char)*(uint *)(*(longlong *)*param_1 + 0x2818)) &&
     ((*(uint *)(*(longlong *)*param_1 + 0x2818) & 2) == 0)) {
    NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000015,param_3,0);
  }
  if ((((ulonglong)param_1[0x112] >> 0xf & 1) != 0) && (((ulonglong)param_1[0x112] >> 0xe & 1) != 0)
     ) {
    NvStorProtocolNcqAckIntAfterReset(param_1);
  }
  return uVar6;
}



===== NvStorSataAtaSuccess @ 0001adfc =====

void NvStorSataAtaSuccess(longlong param_1)

{
  longlong lVar1;
  
  FUN_0001c240(param_1);
  lVar1 = *(longlong *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x88) = 0;
  if ((lVar1 != 0) &&
     (*(longlong *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
    *(undefined8 *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
  }
  NvStorCompleteRequestEx(param_1,1);
  return;
}



===== NvStorSataAtaHandleError @ 0001ae5c =====

void NvStorSataAtaHandleError(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int local_res8 [8];
  
  NvStorScsiBuildSenseData(param_1,param_2);
  lVar1 = *(longlong *)(param_1 + 0x10);
  if ((lVar1 != 0) &&
     (*(longlong *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
    *(undefined8 *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  if (puVar2 != (undefined8 *)0x0) {
    NvCfgElementGet(*(longlong *)(*(longlong *)*puVar2 + 0x2820),(longlong *)puVar2[0xb6],';',
                    (undefined8 *)local_res8,4);
    local_res8[0] = local_res8[0] + 1;
    NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                    (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],';',(ulonglong *)local_res8
                    ,4);
  }
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x100000;
  if (*(longlong *)(param_1 + 0x10) != 0) {
    NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
  }
  NvStorCompleteRequestEx(param_1,1);
  return;
}



===== NvStorSataAtaCancel @ 0001af20 =====

void NvStorSataAtaCancel(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  longlong lVar1;
  
  if ((*(uint *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2818) & 2) == 0) {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x80000;
    NvStorScsiBuildSenseData(param_1,param_2);
    lVar1 = *(longlong *)(param_1 + 0x10);
    if ((lVar1 != 0) &&
       (*(longlong *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
      *(undefined8 *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
    }
    NvStorCompleteRequestEx(param_1,param_3);
  }
  return;
}



===== NvStorSataAtapiHandleError @ 0001af90 =====

void NvStorSataAtapiHandleError(longlong param_1,undefined4 param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  bVar6 = false;
  bVar5 = false;
  *(undefined4 *)(param_1 + 0x88) = param_2;
  FUN_0001c240(param_1);
  lVar3 = *(longlong *)(param_1 + 0x10);
  if ((*(uint *)(lVar3 + 0x890) >> 0x14 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x8d) = 1;
    if (0xff < *(uint *)(lVar2 + 0xd0)) {
      *(undefined4 *)(lVar2 + 0xd0) = 0xff;
    }
    *(undefined1 *)(param_1 + 0x78) = *(undefined1 *)(lVar2 + 0xd0);
    lVar2 = *(longlong *)(param_1 + 0x10);
    if ((lVar2 != 0) &&
       (*(longlong *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
      *(undefined8 *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
    }
    NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
    NvStorCompleteRequestEx(param_1,1);
    if (lVar3 == 0) {
      return;
    }
    *(ulonglong *)(lVar3 + 0x890) = *(ulonglong *)(lVar3 + 0x890) & 0xffffffffffefffff;
    return;
  }
  *(undefined4 *)(lVar3 + 0x1a0) = 0x80000003;
  bVar1 = *(byte *)(param_1 + 0x18) >> 4;
  if (bVar1 < 6) {
    if (bVar1 == 5) {
      *(undefined1 *)(param_1 + 0x8c) = 2;
      *(undefined4 *)(param_1 + 0x88) = 0x80000003;
      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0x80000012;
      goto LAB_0001b096;
    }
    if (bVar1 == 0) {
      bVar6 = true;
    }
    else {
      if (bVar1 == 1) {
        *(undefined4 *)(param_1 + 0x88) = 0;
        *(undefined1 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0;
        goto LAB_0001b096;
      }
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 0x8c) = 2;
        *(undefined4 *)(param_1 + 0x88) = 0x80000003;
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0x80000009;
        goto LAB_0001b096;
      }
      if ((bVar1 != 3) && (bVar1 != 4)) goto LAB_0001b1d8;
    }
LAB_0001b089:
    *(undefined1 *)(param_1 + 0x8c) = 2;
    bVar5 = bVar6;
  }
  else {
    if ((((bVar1 == 6) || (bVar1 == 7)) || (bVar1 == 8)) || (bVar1 == 0xb)) goto LAB_0001b089;
LAB_0001b1d8:
    *(undefined1 *)(param_1 + 0x8c) = 0;
    bVar5 = bVar6;
  }
  *(undefined4 *)(param_1 + 0x88) = 0x80000003;
LAB_0001b096:
  if ((*(uint *)(param_1 + 0xc0) & 2) == 0) {
    FUN_0001beb0(*(longlong *)(param_1 + 0x10),param_1);
    iVar7 = (**(code **)(lVar2 + 0x160))(*(undefined8 *)(param_1 + 0x10),lVar2 + 0xa8);
    if (-1 < iVar7) {
      return;
    }
  }
  if ((*(char *)(param_1 + 0x8c) == '\x02') && (!bVar5)) {
    puVar4 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
    *puVar4 = 0xf0;
    puVar4[7] = 0xb;
    bVar1 = *(byte *)(param_1 + 0x18);
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4[1] = bVar1 >> 4;
    *(undefined1 *)(param_1 + 0x78) = 8;
    *(undefined1 *)(param_1 + 0x8d) = 1;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  if ((lVar2 != 0) &&
     (*(longlong *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
    *(undefined8 *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
  }
  NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
  NvStorCompleteRequestEx(param_1,1);
  return;
}



===== FUN_0001b1e4 @ 0001b1e4 =====

undefined8 FUN_0001b1e4(longlong param_1)

{
  ulonglong *puVar1;
  undefined1 *puVar2;
  ulonglong uVar3;
  byte bVar4;
  byte bVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 local_res8 [8];
  
  bVar13 = *(char *)(param_1 + 0x40) == '\x15';
  puVar2 = *(undefined1 **)(param_1 + 200);
  uVar3 = *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
  uVar7 = (-(uint)bVar13 & 0xfffffffc) + 8;
  if ((uVar3 & 1) != 0) {
    return 0x80000007;
  }
  lVar9 = *(longlong *)(param_1 + 0x30);
  if (lVar9 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x78) = 0;
    *(undefined1 *)(param_1 + 0x8c) = 0;
LAB_0001b23e:
    uVar6 = 0;
  }
  else {
    if (bVar13) {
      if (uVar7 <= *(uint *)(param_1 + 0x2c)) {
        uVar12 = (ulonglong)*(byte *)(lVar9 + 3);
        lVar11 = lVar9 + 4;
LAB_0001b272:
        uVar7 = (int)uVar12 + uVar7;
        if (bVar13) {
          uVar8 = (ulonglong)*(byte *)(param_1 + 0x44);
        }
        else {
          uVar8 = (ulonglong)*(ushort *)(param_1 + 0x47);
        }
        if ((ulonglong)uVar7 + 1 <= uVar8) {
          if ((*(byte *)(lVar11 + uVar12) & 0x3f) != 8) {
            return 0x80000007;
          }
          bVar4 = *(byte *)((ulonglong)uVar7 + 2 + lVar9) >> 2;
          bVar5 = bVar4 & 1;
          bVar4 = bVar4 & 1;
          if ((bVar5 == 0) || ((uVar3 & 0x1000) == 0)) {
            if (bVar5 == 0) {
              if ((uVar3 & 0x1000) == 0) goto LAB_0001b2bb;
              if (bVar4 != 0) goto LAB_0001b2d1;
            }
            else {
LAB_0001b2d1:
              if (((uVar3 >> 0xb & 1) != 0) && ((uVar3 & 0x1000) == 0)) {
                *puVar2 = 2;
                puVar2[10] = 0xef;
                *(undefined4 *)(param_1 + 0x2c) = 0;
                local_res8[0] = 1;
                puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
                *puVar1 = *puVar1 | 0x1000;
                puVar10 = *(undefined8 **)(param_1 + 0x10);
                lVar9 = *(longlong *)*puVar10;
                goto LAB_0001b302;
              }
              if (bVar4 != 0) {
                return 0x80000007;
              }
            }
            if ((uVar3 & 0x1000) == 0) {
              return 0x80000007;
            }
            *puVar2 = 0x82;
            puVar2[10] = 0xef;
            *(undefined4 *)(param_1 + 0x2c) = 0;
            local_res8[0] = 0;
            puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
            *puVar1 = *puVar1 & 0xffffffffffffefff;
            puVar10 = *(undefined8 **)(param_1 + 0x10);
            lVar9 = *(longlong *)*puVar10;
LAB_0001b302:
            NvCfgElementSet(*(longlong *)(lVar9 + 0x2820),(longlong *)puVar10[0xb6],'(',
                            (ulonglong *)local_res8,1);
            return 1;
          }
LAB_0001b2bb:
          *(undefined4 *)(param_1 + 0x88) = 0;
          goto LAB_0001b23e;
        }
      }
    }
    else if (uVar7 <= *(uint *)(param_1 + 0x2c)) {
      uVar12 = (ulonglong)*(ushort *)(lVar9 + 6);
      lVar11 = lVar9 + 8;
      goto LAB_0001b272;
    }
    uVar6 = 0x80000008;
  }
  return uVar6;
}



===== FUN_0001b370 @ 0001b370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_0001b370(longlong param_1)

{
  byte *pbVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined1 auStack_68 [32];
  char local_48;
  char local_44 [4];
  byte local_40 [16];
  ushort local_30 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 200) + 10) = 0xda;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    return 1;
  }
  if (*(uint *)(param_1 + 0x2c) == 0) {
LAB_0001b3bb:
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  else {
    bVar5 = *(byte *)(param_1 + 0x42) & 0x3f;
    if ((bVar5 < 0x40) && ((0x8000000010000100U >> bVar5 & 1) != 0)) {
      if (bVar5 != 0x1c) {
        bVar11 = *(char *)(param_1 + 0x40) == '\x1a';
        puVar2 = *(ushort **)(param_1 + 0x30);
        uVar8 = -(uint)bVar11 & 0xfffffffc;
        uVar9 = uVar8 + 8;
        if (puVar2 == (ushort *)0x0) {
          return 0x80000008;
        }
        local_48 = bVar11;
        (**(code **)(NvStorOsCBT + 0x110))(puVar2);
        uVar10 = uVar8 + 0x1c;
        if (bVar11) {
          if (*(uint *)(param_1 + 0x2c) < uVar10) {
LAB_0001b494:
            if (bVar11) {
              *(char *)puVar2 = (char)uVar8 + '\a';
            }
            else {
              uVar4 = (ushort)(uVar8 + 6);
              *puVar2 = uVar4 << 8 | uVar4 >> 8;
            }
            *(undefined4 *)(param_1 + 0x88) = 0x80000004;
            *(undefined1 *)(param_1 + 0x8c) = 0;
            *(uint *)(param_1 + 0x2c) = uVar9;
            *(uint *)(param_1 + 0x28) = uVar9;
            *(undefined1 *)(param_1 + 0x78) = 0;
            return 0;
          }
          (**(code **)(NvStorOsCBT + 0x110))(local_44,uVar9);
          local_44[0] = (char)uVar8 + '\x1b';
        }
        else {
          if (*(uint *)(param_1 + 0x2c) < uVar10) goto LAB_0001b494;
          (**(code **)(NvStorOsCBT + 0x110))(local_30,uVar9);
          uVar4 = (short)uVar8 + 0x1a;
          local_30[0] = uVar4 * 0x100 | uVar4 >> 8;
        }
        (**(code **)(NvStorOsCBT + 0x110))(local_40,0xc);
        local_40[1] = 0x12;
        puVar7 = (ushort *)local_44;
        local_40[0] = local_40[0] & 200 | 8;
        local_40[2] = local_40[2] ^
                      ((char)(*(uint *)(*(longlong *)(param_1 + 0x10) + 0x890) >> 0xc) << 2 ^
                      local_40[2]) & 4;
        if (*(uint *)(param_1 + 0x2c) < uVar9) {
          uVar9 = *(uint *)(param_1 + 0x2c);
        }
        if (local_48 == '\0') {
          puVar7 = local_30;
        }
        (**(code **)(NvStorOsCBT + 0x118))(puVar2,puVar7,uVar9);
        if (uVar9 < *(uint *)(param_1 + 0x2c)) {
          uVar6 = *(uint *)(param_1 + 0x2c) - uVar9;
          uVar8 = 0xc;
          if (uVar6 < 0x14) {
            uVar8 = uVar6;
          }
          (**(code **)(NvStorOsCBT + 0x118))
                    ((char *)((longlong)puVar2 + (ulonglong)uVar9),local_40,uVar8);
        }
        if (*(uint *)(param_1 + 0x2c) < uVar10) {
          uVar10 = *(uint *)(param_1 + 0x2c);
        }
        *(uint *)(param_1 + 0x28) = uVar10;
        goto LAB_0001b3bb;
      }
      pbVar1 = *(byte **)(param_1 + 0x30);
      (**(code **)(NvStorOsCBT + 0x110))(pbVar1,0xc);
      pbVar1[1] = 0xb;
      *pbVar1 = *pbVar1 & 0xdc | 0x1c;
      uVar9 = 0xc;
      if (*(uint *)(param_1 + 0x2c) < 0xc) {
        uVar9 = *(uint *)(param_1 + 0x2c);
      }
      *(uint *)(param_1 + 0x28) = uVar9;
    }
    else {
      puVar3 = *(undefined1 **)(param_1 + 0x30);
      if (*(uint *)(param_1 + 0x2c) < 4) {
        *(undefined4 *)(param_1 + 0x88) = 0x80000002;
        return 0x80000008;
      }
      (**(code **)(NvStorOsCBT + 0x110))(puVar3,4);
      *puVar3 = 3;
      *(undefined4 *)(param_1 + 0x2c) = 4;
      *(undefined4 *)(param_1 + 0x28) = 4;
    }
    *(undefined1 *)(param_1 + 0x8c) = 0;
  }
  return 0;
}



===== FUN_0001b61c @ 0001b61c =====

undefined8 FUN_0001b61c(longlong param_1)

{
  uint *puVar1;
  ulonglong *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte bVar5;
  
  bVar5 = *(byte *)(param_1 + 0x44) & 2;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    if (bVar5 == 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x8a4) = 0;
      if ((*(uint *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2818) & 0x100) == 0) {
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10000;
        NvStorPrepareLinkedRequest(param_1);
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x70) + 0xc0);
        *puVar1 = *puVar1 | 0x220000;
      }
      uVar4 = FUN_0001b748(param_1);
      return uVar4;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) == 0) {
LAB_0001b729:
      *(undefined1 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0x80000007;
      return 0x80000007;
    }
    *(undefined1 *)(*(longlong *)(param_1 + 200) + 10) = 0xed;
  }
  else {
    if (bVar5 != 0) goto LAB_0001b729;
    if (*(int *)(*(longlong *)**(longlong **)(param_1 + 0x10) + 0x2664) == 2) {
      puVar1 = (uint *)((longlong *)**(longlong **)(param_1 + 0x10) + 0x24);
      *puVar1 = *puVar1 | 2;
    }
    puVar2 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
    *puVar2 = *puVar2 & 0xfffffffdffffffff;
    (**(code **)(NvStorOsCBT + 0x110))(param_1 + 0x40,0x10);
    lVar3 = *(longlong *)(param_1 + 200);
    *(undefined1 *)(param_1 + 0x40) = 0x2f;
    *(undefined1 *)(param_1 + 0x45) = 1;
    *(undefined1 *)(param_1 + 0x48) = 1;
    uVar4 = FUN_0001b7c8(param_1);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(byte *)(lVar3 + 10) = *(byte *)(param_1 + 0xc0) >> 3 & 2 | 0x40;
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
  return 1;
}



===== FUN_0001b748 @ 0001b748 =====

undefined8 FUN_0001b748(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if ((*(int *)(lVar1 + 0x8a4) == 1) && (*(longlong *)(param_1 + 0xd0) != 0)) {
    if ((*(uint *)(lVar1 + 0x890) >> 0xc & 1) != 0) {
      *(undefined1 *)(lVar1 + 0x8a0) = 1;
    }
  }
  else {
    if ((*(ulonglong *)(lVar1 + 0x890) >> 0xc & 1) != 0) {
      if ((*(ulonglong *)(lVar1 + 0x890) & 0x10) == 0) {
        *(undefined1 *)(*(longlong *)(param_1 + 200) + 10) = 0xe7;
      }
      else {
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10;
        *(undefined1 *)(*(longlong *)(param_1 + 200) + 10) = 0xea;
      }
      *(undefined4 *)(param_1 + 0xc4) = 0;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x88) = 0x80000007;
    *(undefined1 *)(param_1 + 0x8c) = 2;
  }
  return 0;
}



===== FUN_0001b7c8 @ 0001b7c8 =====

undefined8 FUN_0001b7c8(longlong param_1)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  lVar8 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_1 + 200);
  uVar6 = NvStorScsiGetLBA((byte *)(param_1 + 0x40));
  *(ulonglong *)(param_1 + 0x38) = uVar6;
  if (((*(byte *)(lVar8 + 0x890) & 1) == 0) && (*(ulonglong *)(lVar8 + 0x228) < uVar6)) {
    uVar7 = 0x80000003;
  }
  else {
    uVar5 = NvStorScsiGetBlockCount((byte *)(param_1 + 0x40));
    pbVar1 = (byte *)(lVar3 + 9);
    *pbVar1 = *pbVar1 | 0x40;
    if ((*(byte *)(lVar8 + 0x890) & 0x10) != 0) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10;
    }
    uVar2 = *(uint *)(param_1 + 0xc0);
    uVar7 = *(undefined8 *)(param_1 + 0x38);
    lVar8 = *(longlong *)(param_1 + 200);
    *(char *)(lVar8 + 2) = (char)uVar7;
    bVar4 = (byte)((ulonglong)uVar7 >> 0x18);
    if ((uVar2 & 0x10) == 0) {
      *(byte *)(lVar8 + 9) = bVar4 & 0xf | 0x40;
    }
    else {
      *(char *)(lVar8 + 8) = (char)((ulonglong)uVar7 >> 0x28);
      *(char *)(lVar8 + 7) = (char)((ulonglong)uVar7 >> 0x20);
      *(byte *)(lVar8 + 6) = bVar4;
    }
    *(char *)(lVar8 + 4) = (char)((ulonglong)uVar7 >> 0x10);
    *(char *)(lVar8 + 3) = (char)((ulonglong)uVar7 >> 8);
    uVar2 = *(uint *)(param_1 + 0xc0);
    lVar8 = *(longlong *)(param_1 + 200);
    *(char *)(lVar8 + 1) = (char)uVar5;
    if ((uVar2 & 0x10) != 0) {
      *(char *)(lVar8 + 5) = (char)(uVar5 >> 8);
    }
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x2000;
    uVar7 = 0;
  }
  return uVar7;
}



===== FUN_0001b8b0 @ 0001b8b0 =====

undefined8 FUN_0001b8b0(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_1 + 200);
  lVar4 = *(longlong *)(lVar2 + 0x880);
  uVar6 = FUN_0001b7c8(param_1);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if (*(char *)(lVar2 + 0x890) < '\0') {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x200;
    *(undefined4 *)(param_1 + 0xc4) = 1;
    if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
      *(undefined1 *)(lVar3 + 10) = 0xca;
    }
    else {
      *(undefined1 *)(lVar3 + 10) = 200;
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 1;
    }
    if ((*(uint *)(param_1 + 0xc0) & 0x10) != 0) {
      if (*(char *)(lVar3 + 10) == -0x38) {
        *(undefined1 *)(lVar3 + 10) = 0x25;
      }
      else {
        if (*(char *)(lVar3 + 10) != -0x36) {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 10) = 0x35;
      }
    }
    if ((((*(ulonglong *)(lVar2 + 0x890) & 0x4000) != 0) &&
        ((*(ulonglong *)(lVar2 + 0x890) >> 0x10 & 1) != 0)) && (1 < *(ushort *)(lVar2 + 0x220))) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x20;
      cVar1 = *(char *)(lVar3 + 10);
      if (cVar1 == '%') {
        *(undefined1 *)(lVar3 + 10) = 0x26;
      }
      else if (cVar1 == '5') {
        *(undefined1 *)(lVar3 + 10) = 0x36;
      }
      else if (cVar1 == -0x38) {
        *(undefined1 *)(lVar3 + 10) = 199;
      }
      else {
        if (cVar1 != -0x36) {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 10) = 0xcc;
      }
    }
    uVar5 = *(ulonglong *)(lVar2 + 0x890);
    if ((((uVar5 & 0x4000) != 0) && ((uVar5 & 0x8000) != 0)) &&
       ((1 < *(ushort *)(lVar2 + 0x220) &&
        (((uVar5 >> 0x19 & 1) == 0 || ((uVar5 >> 0x1a & 1) != 0)))))) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x20;
      *(undefined4 *)(param_1 + 0xc4) = 4;
      if (*(char *)(lVar3 + 10) == '%') {
        *(undefined1 *)(lVar3 + 10) = 0x60;
      }
      else {
        if (*(char *)(lVar3 + 10) != '5') {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 10) = 0x61;
      }
    }
  }
  else {
    if ((*(int *)(param_1 + 0x2c) != 0) && (*(longlong *)(param_1 + 0x30) == 0)) {
      if (*(code **)(NvStorOsCBT + 0x1d0) == (code *)0x0) {
        return 0x80000008;
      }
      uVar6 = (**(code **)(NvStorOsCBT + 0x1d0))(param_1);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
    }
    if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
      *(undefined4 *)(param_1 + 0xc4) = 3;
      if ((*(uint *)(lVar2 + 0x890) >> 8 & 1) == 0) {
        *(undefined1 *)(lVar3 + 10) = 0x30;
      }
      else {
        *(undefined1 *)(lVar3 + 10) = 0xc5;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc4) = 2;
      if ((*(uint *)(lVar2 + 0x890) >> 8 & 1) == 0) {
        *(undefined1 *)(lVar3 + 10) = 0x20;
      }
      else {
        *(undefined1 *)(lVar3 + 10) = 0xc4;
      }
    }
    if ((*(uint *)(param_1 + 0xc0) & 0x10) != 0) {
      cVar1 = *(char *)(lVar3 + 10);
      if (cVar1 == ' ') {
        *(undefined1 *)(lVar3 + 10) = 0x24;
      }
      else if (cVar1 == '0') {
        *(undefined1 *)(lVar3 + 10) = 0x34;
      }
      else if (cVar1 == -0x3c) {
        *(undefined1 *)(lVar3 + 10) = 0x29;
      }
      else {
        if (cVar1 != -0x3b) {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 10) = 0x39;
      }
    }
  }
  if ((*(uint *)(param_1 + 0xc0) & 0x8000) != 0) {
    if (((*(ulonglong *)(lVar2 + 0x890) & 0x4000) == 0) ||
       ((*(ulonglong *)(lVar2 + 0x890) & 0x8000) == 0)) {
      if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
        cVar1 = *(char *)(lVar3 + 10);
        if (cVar1 == '5') {
          if (*(char *)(lVar4 + 0xa6) < '\0') {
            *(undefined1 *)(lVar3 + 10) = 0x3d;
          }
        }
        else if (cVar1 == '6') {
          if ((*(byte *)(lVar4 + 0xa6) & 0x40) != 0) {
            *(undefined1 *)(lVar3 + 10) = 0x3e;
          }
        }
        else if ((cVar1 == '9') && (*(char *)(lVar4 + 0xa6) < '\0')) {
          *(undefined1 *)(lVar3 + 10) = 0xce;
        }
      }
    }
    else {
      *(byte *)(lVar3 + 9) = *(byte *)(lVar3 + 9) | 0x80;
    }
  }
  return 1;
}



===== FUN_0001bb68 @ 0001bb68 =====

undefined8 FUN_0001bb68(longlong param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  if (*(uint *)(param_1 + 0x2c) < 0x10) {
    puVar1 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
    *(undefined1 *)(param_1 + 0x8c) = 2;
    if (puVar1 != (undefined1 *)0x0) {
      (**(code **)(NvStorOsCBT + 0x110))(puVar1,0x12);
      *puVar1 = 0xf0;
      puVar1[7] = 0xb;
      *(undefined2 *)(puVar1 + 0xc) = 0x24;
      puVar1[2] = puVar1[2] & 0xf5 | 5;
      *(undefined1 *)(param_1 + 0x78) = 0x12;
      *(undefined1 *)(param_1 + 0x8d) = 1;
    }
    uVar3 = 0x80000007;
  }
  else {
    if (*(byte *)(param_1 + 0x42) < 3) {
      puVar2 = *(undefined4 **)(param_1 + 0x30);
      (**(code **)(NvStorOsCBT + 0x110))(puVar2,0x10);
      *puVar2 = 0x8000000;
      *(undefined2 *)(puVar2 + 2) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0x10;
      *(undefined4 *)(param_1 + 0x28) = 0x10;
      *(undefined1 *)(param_1 + 0x78) = 0;
    }
    *(undefined1 *)(param_1 + 0x8c) = 0;
    uVar3 = 0;
  }
  return uVar3;
}



===== FUN_0001bc24 @ 0001bc24 =====

undefined8 FUN_0001bc24(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  
  puVar2 = *(uint **)(param_1 + 0x30);
  if (puVar2 == (uint *)0x0) {
    return 0x80000008;
  }
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x230);
  puVar2[1] = (uVar1 << 0x10 | uVar1 & 0xff00) << 8 |
              (uint)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x233) | uVar1 >> 8 & 0xff00;
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (((*(ulonglong *)(lVar3 + 0x890) & 0x40000000000000) == 0) &&
     (*(ulonglong *)(lVar3 + 0x228) < 0x100000000)) {
    uVar1 = *(uint *)(lVar3 + 0x228);
    *puVar2 = (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 |
              (uint)*(byte *)(lVar3 + 0x22b);
  }
  else {
    *puVar2 = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
  return 0;
}



===== FUN_0001bcd8 @ 0001bcd8 =====

undefined8 FUN_0001bcd8(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  ushort uVar6;
  
  uVar6 = 1;
  if (*(uint *)(param_1 + 0x2c) < 0xc) {
    *(undefined4 *)(param_1 + 0x88) = 0x80000002;
  }
  else {
    puVar4 = *(ulonglong **)(param_1 + 0x30);
    if (puVar4 != (ulonglong *)0x0) {
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x230);
      *(uint *)(puVar4 + 1) =
           (uVar3 << 0x10 | uVar3 & 0xff00) << 8 |
           (uint)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x233) | uVar3 >> 8 & 0xff00;
      uVar5 = *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x228);
      *puVar4 = (((uVar5 << 0x10 | uVar5 & 0xff00) << 0x10 | (ulonglong)((uint)uVar5 & 0xff0000)) <<
                 0x10 | uVar5 & 0xff000000) << 8 |
                ((uVar5 >> 0x10 & 0xff00000000 | uVar5 & 0xff0000000000) >> 0x10 |
                uVar5 & 0xff00000000) >> 8 |
                (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x10) + 0x22f);
      if (0x1f < *(uint *)(param_1 + 0x2c)) {
        *(byte *)((longlong)puVar4 + 0xd) =
             *(byte *)((longlong)puVar4 + 0xd) ^
             (*(byte *)(*(longlong *)(param_1 + 0x10) + 0x234) ^ *(byte *)((longlong)puVar4 + 0xd))
             & 0xf;
        bVar1 = *(byte *)(*(longlong *)(param_1 + 0x10) + 0x234);
        uVar5 = (ulonglong)bVar1;
        if (bVar1 != 0) {
          do {
            uVar6 = uVar6 * 2;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x10) + 0x236);
        if (uVar2 == 0) {
          *(undefined2 *)((longlong)puVar4 + 0xe) = 0;
        }
        else {
          *(ushort *)((longlong)puVar4 + 0xe) =
               (ushort)((uint)uVar6 - (uint)uVar2 >> 8) & 0xff ^ (uVar6 - uVar2) * 0x100;
        }
      }
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
      return 0;
    }
  }
  return 0x80000008;
}



===== FUN_0001beb0 @ 0001beb0 =====

void FUN_0001beb0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = param_1 + 0xa8;
  uVar2 = *(undefined8 *)(param_1 + 0x170);
  (**(code **)(NvStorOsCBT + 0x110))(lVar1,0xf0);
  *(undefined8 *)(param_1 + 0x170) = uVar2;
  *(longlong *)(param_1 + 0xb8) = param_1;
  *(undefined4 *)(param_1 + 0xc4) = 10;
  *(undefined4 *)(param_1 + 0xd4) = 0xff;
  *(uint *)(param_1 + 0x168) = *(uint *)(param_1 + 0x168) | 3;
  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0x198);
  *(longlong *)(param_1 + 0x178) = param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_2 + 0x84);
  (**(code **)(NvStorOsCBT + 0x110))(uVar2,0xb);
  *(undefined1 *)(param_1 + 0xe8) = 3;
  *(undefined2 *)(param_1 + 0xec) = 0xff;
  *(undefined2 *)(*(longlong *)(param_1 + 0x170) + 3) = 0xff;
  *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) | 0x100000;
  *(longlong *)(param_1 + 0x178) = param_2;
  *(longlong *)(param_1 + 0x240 + (longlong)*(int *)(param_2 + 0x84) * 8) = lVar1;
  *(undefined4 *)(param_1 + 0x16c) = 6;
  *(undefined1 **)(param_1 + 0x148) = &LAB_0001be70;
  *(undefined1 **)(param_1 + 0x140) = &LAB_0001be70;
                    /* WARNING: Could not recover jumptable at 0x0001bfba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x368))(lVar1);
  return;
}



===== FUN_0001bfc0 @ 0001bfc0 =====

ulonglong FUN_0001bfc0(longlong param_1)

{
  char *pcVar1;
  byte bVar2;
  undefined1 *puVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  ushort uVar9;
  bool bVar10;
  
  puVar3 = *(undefined1 **)(param_1 + 200);
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x890) >> 9 & 1) == 0) {
LAB_0001c12c:
    bVar10 = false;
  }
  else {
    pcVar1 = (char *)(param_1 + 0x40);
    if (*pcVar1 == '\x15') {
      uVar8 = *(undefined1 *)(param_1 + 0x44);
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 4;
      (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x50,pcVar1,0xc);
      (**(code **)(NvStorOsCBT + 0x110))(pcVar1,0xc);
      *pcVar1 = 'U';
      *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 0x10;
      *(undefined1 *)(param_1 + 0x47) = 0;
      *(undefined1 *)(param_1 + 0x48) = uVar8;
      *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 1;
      *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(param_1 + 0x55);
      goto LAB_0001c12c;
    }
    if (*pcVar1 != '\x1a') goto LAB_0001c12c;
    bVar2 = *(byte *)(param_1 + 0x42);
    if (*(longlong *)(param_1 + 0x30) == 0) {
      bVar10 = true;
    }
    else {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 4;
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 4;
      uVar9 = *(byte *)(param_1 + 0x44) + 4;
      (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x50,pcVar1,0xc);
      *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0x30);
      uVar5 = *(uint *)(param_1 + 0x2c);
      if (*(uint *)(param_1 + 0x2c) < (uint)uVar9) {
        uVar5 = (uint)uVar9;
      }
      lVar6 = (**(code **)(NvStorOsCBT + 0x128))
                        (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),uVar5);
      *(longlong *)(param_1 + 0x30) = lVar6;
      lVar4 = NvStorOsCBT;
      if (lVar6 != 0) {
        *(undefined8 *)(param_1 + 0x20) = 0;
        (**(code **)(lVar4 + 0x110))(pcVar1,0xc);
        *pcVar1 = 'Z';
        *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) | bVar2 & 0x3f;
        *(char *)(param_1 + 0x48) = (char)uVar9;
        *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 8;
        *(char *)(param_1 + 0x47) = (char)(uVar9 >> 8);
        *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(param_1 + 0x55);
        goto LAB_0001c12c;
      }
      bVar10 = true;
    }
  }
  if (bVar10) {
    return 0x80000011;
  }
  uVar5 = *(uint *)(param_1 + 0x2c);
  lVar4 = *(longlong *)(param_1 + 200);
  uVar8 = (undefined1)(uVar5 >> 8);
  if (0xffff < uVar5) {
    uVar8 = 0xff;
    uVar5 = 0xff;
  }
  *(char *)(lVar4 + 3) = (char)uVar5;
  *(undefined1 *)(lVar4 + 4) = uVar8;
  puVar3[10] = 0xa0;
  if ((*(char *)(*(longlong *)(param_1 + 0x10) + 0x890) < '\0') &&
     (*(longlong *)(param_1 + 0x20) != 0)) {
    bVar10 = true;
    if (*(int *)(param_1 + 0x2c) == 0) goto LAB_0001c1e3;
    if ((*(uint *)(param_1 + 0xc0) & 4) == 0) {
      bVar2 = *(byte *)(param_1 + 0x40);
      if (((bVar2 < 0x2f) && ((0x450000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
         (((byte)(bVar2 + 0x78) < 0x37 &&
          ((0x42000500000005U >> ((ulonglong)(byte)(bVar2 + 0x78) & 0x3f) & 1) != 0)))) {
        *puVar3 = 1;
        if ((*(uint *)(param_1 + 0xc0) & 1) != 0) {
          *puVar3 = 5;
        }
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x200;
        *(undefined4 *)(param_1 + 0xc4) = 5;
        return 1;
      }
    }
  }
  bVar10 = *(int *)(param_1 + 0x2c) == 0;
LAB_0001c1e3:
  if ((!bVar10) && (*(longlong *)(param_1 + 0x30) == 0)) {
    if (*(code **)(NvStorOsCBT + 0x1d0) == (code *)0x0) {
      return 0x80000008;
    }
    uVar7 = (**(code **)(NvStorOsCBT + 0x1d0))(param_1);
    if ((uVar7 & 0x80000000) != 0) {
      return uVar7;
    }
  }
  *puVar3 = 0;
  *(undefined4 *)(param_1 + 0xc4) = 6;
  return 1;
}



===== FUN_0001c240 @ 0001c240 =====

void FUN_0001c240(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  uint uVar5;
  
  if (((*(uint *)(param_1 + 0xc0) & 4) != 0) && (*(char *)(param_1 + 0x40) == 'Z')) {
    lVar2 = *(longlong *)(param_1 + 0x30);
    puVar3 = *(undefined1 **)(param_1 + 0x60);
    *puVar3 = *(undefined1 *)(lVar2 + 1);
    puVar3[1] = *(undefined1 *)(lVar2 + 2);
    puVar3[2] = *(undefined1 *)(lVar2 + 3);
    puVar3[3] = *(undefined1 *)(lVar2 + 7);
    uVar5 = *(uint *)(param_1 + 0x28);
    if (7 < uVar5) {
      uVar5 = 8;
    }
    piVar1 = (int *)(param_1 + 0x28);
    *piVar1 = *piVar1 - uVar5;
    if (*piVar1 != 0) {
      (**(code **)(NvStorOsCBT + 0x118))
                (*(longlong *)(param_1 + 0x60) + 4,*(longlong *)(param_1 + 0x30) + 8,
                 *(undefined4 *)(param_1 + 0x28));
    }
    lVar2 = NvStorOsCBT;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 4;
    (**(code **)(lVar2 + 0x118))(param_1 + 0x40,param_1 + 0x50,0xc);
    uVar4 = *(undefined8 *)(param_1 + 0x30);
    *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x60);
    (**(code **)(NvStorOsCBT + 0x130))(*(undefined8 *)**(undefined8 **)(param_1 + 0x10),uVar4);
  }
  return;
}



===== NvStorSataDeliverTaskFile @ 0001c308 =====

undefined8 NvStorSataDeliverTaskFile(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 2);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 8);
  }
  *(undefined1 *)(param_2 + 1) = uVar2;
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 3);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0xc);
  }
  *(undefined1 *)(param_2 + 2) = uVar2;
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 4);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x10);
  }
  *(undefined1 *)(param_2 + 3) = uVar2;
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 5);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x14);
  }
  *(undefined1 *)(param_2 + 4) = uVar2;
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 6);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 0x18);
  }
  *(undefined1 *)(param_2 + 9) = uVar2;
  puVar1 = (undefined8 *)**(longlong **)(param_1 + 0x10);
  if (puVar1[0x19] == 0) {
    uVar2 = (*(code *)*NvStorOsCBT)(*puVar1,*(short *)(puVar1 + 3) + 1);
  }
  else {
    uVar2 = (*(code *)NvStorOsCBT[6])(*puVar1,puVar1[0x19] + 4);
  }
  *(undefined1 *)(param_2 + 0xb) = uVar2;
  return 0;
}



===== NvStorSataCrashDumpReadLogExt @ 0001c49c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NvStorSataCrashDumpReadLogExt(longlong *param_1,char param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 auStack_78 [32];
  undefined1 local_58 [8];
  undefined1 local_50 [32];
  undefined1 local_30;
  undefined2 local_2f;
  undefined2 local_27;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  lVar6 = 0;
  if (param_2 == '\0') {
    (*(code *)NvStorOsCBT[0x2a])(*(undefined8 *)*param_1,2,0,local_50);
    lVar6 = param_1[0x73];
    param_1[0x73] = (longlong)NvStorProtocolAtaBusyWaitCheckQueueDpc;
    (*(code *)NvStorOsCBT[0x2b])(*(undefined8 *)*param_1,2,0,local_50);
  }
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar2,*(short *)(puVar2 + 3) + 6,0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar2,puVar2[0x19] + 0x18);
  }
  puVar2 = (undefined8 *)*param_1;
  if (puVar2[0x19] == 0) {
    uVar4 = (*(code *)*NvStorOsCBT)(*puVar2,*(short *)(puVar2 + 3) + 7);
  }
  else {
    uVar4 = (*(code *)NvStorOsCBT[6])(*puVar2,puVar2[0x19] + 0x1c);
  }
  if (((uVar4 & 0x40) != 0) && ((uVar4 & 0x88) == 0)) {
    (*(code *)NvStorOsCBT[0x22])(&local_30,0xb);
    local_27 = 0x2f00;
    local_2f = 0x1001;
    uVar3 = NvStorProtocolAtaSendCommandAndWait(param_1,&local_30,local_58);
    if (uVar3 != 0) goto LAB_0001c654;
    uVar5 = NvStorNonIntExecutePioDataInPhase(param_1);
    if ((int)uVar5 == 2) {
      plVar1 = param_1 + 0x76;
      (*(code *)NvStorOsCBT[0x22])(plVar1,0x200);
      puVar2 = (undefined8 *)*param_1;
      if (puVar2[0x19] == 0) {
        (*(code *)NvStorOsCBT[4])(*puVar2,*(undefined2 *)(puVar2 + 3),plVar1,0x100);
      }
      else {
        (*(code *)NvStorOsCBT[10])(*puVar2,puVar2[0x19],plVar1,0x200);
      }
      uVar5 = NvStorNonIntWaitOnPortStatus((undefined8 *)*param_1,0x80,0);
      if ((char)uVar5 < '\0') {
        uVar3 = 0x80000006;
      }
      goto LAB_0001c654;
    }
  }
  uVar3 = 0x80000003;
LAB_0001c654:
  if (param_2 == '\0') {
    (*(code *)NvStorOsCBT[0x2a])(*(undefined8 *)*param_1,2,0,local_50);
    puVar2 = NvStorOsCBT;
    param_1[0x73] = lVar6;
    (*(code *)puVar2[0x2b])(*(undefined8 *)*param_1,2,0,local_50);
  }
  return uVar3;
}



===== NvStorSataSetupFeatureRequest @ 0001c6c4 =====

undefined8 NvStorSataSetupFeatureRequest(undefined8 *param_1,longlong param_2)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  
  (**(code **)(NvStorOsCBT + 0x110))(param_2,0xf0);
  *(undefined4 *)(param_2 + 0xc4) = 0;
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x40000;
  *(undefined8 *)(param_2 + 0xd0) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x30) = 0;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *(undefined8 **)(param_2 + 0x10) = param_1;
  *(undefined4 *)(param_2 + 0x1c) = 10;
  *(code **)(param_2 + 0xb8) = NvStorProtocolAtaNonDataIssueCommand;
  puVar1 = (undefined2 *)(**(code **)(NvStorOsCBT + 0x100))(*(undefined8 *)*param_1,0xb,0,1);
  *(undefined2 **)(param_2 + 200) = puVar1;
  if (puVar1 == (undefined2 *)0x0) {
    uVar2 = 0x80000011;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x110))(puVar1,0xb);
    *(undefined2 *)((longlong)puVar1 + 9) = 0xf500;
    *puVar1 = 0;
    *(undefined8 *)(param_2 + 0xa0) = param_1[0x6f];
    *(undefined8 *)(param_2 + 0x98) = param_1[0x6e];
    uVar2 = param_1[0x70];
    *(undefined1 *)(param_2 + 0x8d) = 0;
    *(undefined8 *)(param_2 + 0xa8) = uVar2;
    *(code **)(param_2 + 0xb0) = NvStorCompleteSSFRequest;
    uVar2 = 0;
  }
  return uVar2;
}



===== NvStorAhciControllerInitialize @ 0001c7d8 =====

ulonglong NvStorAhciControllerInitialize(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint uVar9;
  byte local_res8 [8];
  
  plVar8 = *(longlong **)(param_1 + 0x28c8);
  (**(code **)(NvStorOsCBT + 0x110))(plVar8,0x18);
  *(code **)(param_1 + 0x27b8) = NvStorAhciCheckInterrupt;
  *plVar8 = *(longlong *)(param_1 + 0x25e0);
  uVar5 = NvStorAhciEnableAhciMode(param_1);
  if (-1 < (int)uVar5) {
    if ((*(uint *)(param_1 + 0x25f0) & 0x200000) == 0) {
      uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar8 + 4);
      (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar8 + 4,uVar2 | 1);
      uVar6 = FUN_0001fc4c(param_1,*plVar8 + 4,1,0,10000000);
      if ((uVar6 & 1) != 0) {
        return 0x80000003;
      }
    }
    if (((*(uint *)(param_1 + 0x25f0) >> 0xe & 1) != 0) ||
       ((*(uint *)(param_1 + 0x25f0) >> 0xf & 1) != 0)) {
      uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar8);
      *(uint *)(plVar8 + 1) = uVar2 | 0x4000000;
      (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar8 + 0xa0,uVar2 | 0x4000000);
    }
    uVar3 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar8);
    *(undefined4 *)(plVar8 + 1) = uVar3;
    *(ushort *)(plVar8 + 2) = ((ushort)((uint)uVar3 >> 8) & 0x1f) + 1;
    lVar1 = NvStorOsCBT;
    *(ushort *)((longlong)plVar8 + 0xe) = ((ushort)uVar3 & 0x1f) + 1;
    uVar2 = (**(code **)(lVar1 + 0x40))(param_1,*plVar8 + 0x14);
    *(byte *)((longlong)plVar8 + 0xc) = (byte)(uVar2 >> 3) & 0x1f;
    iVar4 = (**(code **)(NvStorOsCBT + 0xd0))(param_1,0xa4,local_res8);
    if ((-1 < iVar4) && ((local_res8[0] & 0x40) != 0)) {
      *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 8;
    }
    if ((int)plVar8[1] < 0) {
      *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 1;
    }
    lVar1 = NvStorOsCBT;
    uVar9 = 0;
    *(undefined1 *)(param_1 + 0x2500) = 0;
    uVar2 = (**(code **)(lVar1 + 0x40))(param_1,*plVar8 + 0xc);
    uVar7 = 0;
    do {
      if ((uVar2 >> (uVar7 & 0x1f) & 1) != 0) {
        *(char *)(param_1 + 0x2500) = *(char *)(param_1 + 0x2500) + '\x01';
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x20);
    uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar8 + 0xc);
    uVar5 = uVar5 & 0xffffffff;
    do {
      if ((uVar2 >> (uVar9 & 0x1f) & 1) != 0) {
        plVar8 = (longlong *)((ulonglong)uVar9 * 0x128 + param_1);
        *plVar8 = param_1;
        *(char *)(plVar8 + 0x1b) = (char)uVar9;
        *(ushort *)(plVar8 + 2) = (ushort)*(byte *)(param_1 + 0x2501);
        plVar8[0x13] = *(longlong *)(param_1 + 0x25d0);
        plVar8[0x14] = *(longlong *)(param_1 + 0x25d8);
        plVar8[0x15] = *(longlong *)(param_1 + 0x25e0);
        plVar8[0x16] = *(longlong *)(param_1 + 0x25e8);
        uVar6 = NvStorAhciPortInitialize(plVar8);
        uVar5 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x20);
    *(undefined4 *)(param_1 + 0x28dc) = 0xffffffff;
  }
  return uVar5;
}



===== NvStorAhciControllerAllocateResources @ 0001ca48 =====

int NvStorAhciControllerAllocateResources(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)param_1[0x519] + 0xc);
  uVar5 = 0;
  do {
    if ((uVar2 >> (uVar5 & 0x1f) & 1) != 0) {
      lVar1 = param_1[0x1e];
      if (*(longlong *)(lVar1 + 0x18) == 0) {
        lVar3 = (**(code **)(NvStorOsCBT + 0x100))
                          (*param_1,*(int *)(*param_1 + 0x2504) << 5,0x400,0);
        *(longlong *)(lVar1 + 0x18) = lVar3;
        if (lVar3 != 0) goto LAB_0001cac3;
LAB_0001cb5a:
        if (*(longlong *)(lVar1 + 0x18) != 0) {
          (**(code **)(NvStorOsCBT + 0x108))(*param_1,*(longlong *)(lVar1 + 0x18),0);
          *(undefined8 *)(lVar1 + 0x18) = 0;
        }
        if (*(longlong *)(lVar1 + 0x10) != 0) {
          (**(code **)(NvStorOsCBT + 0x108))(*param_1,*(longlong *)(lVar1 + 0x10),0);
          *(undefined8 *)(lVar1 + 0x10) = 0;
        }
        if (*(longlong *)(lVar1 + 0x20) != 0) {
          (**(code **)(NvStorOsCBT + 0x108))(*param_1,*(longlong *)(lVar1 + 0x20),0);
          *(undefined8 *)(lVar1 + 0x20) = 0;
        }
        iVar4 = -0x7fffffef;
      }
      else {
LAB_0001cac3:
        (**(code **)(NvStorOsCBT + 0x110))
                  (*(undefined8 *)(lVar1 + 0x18),*(int *)(*param_1 + 0x2504) << 5);
        if (*(longlong *)(lVar1 + 0x10) == 0) {
          lVar3 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0x100,0x100);
          *(longlong *)(lVar1 + 0x10) = lVar3;
          if (lVar3 == 0) goto LAB_0001cb5a;
        }
        (**(code **)(NvStorOsCBT + 0x110))(*(undefined8 *)(lVar1 + 0x10),0x100);
        if (*(longlong *)(lVar1 + 0x20) == 0) {
          lVar3 = (**(code **)(NvStorOsCBT + 0x100))
                            (*param_1,*(int *)(*param_1 + 0x2504) * 0x300,0x80);
          *(longlong *)(lVar1 + 0x20) = lVar3;
          if (lVar3 == 0) goto LAB_0001cb5a;
        }
        (**(code **)(NvStorOsCBT + 0x110))
                  (*(undefined8 *)(lVar1 + 0x20),*(int *)(*param_1 + 0x2504) * 0x300);
        iVar4 = 0;
      }
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    uVar5 = uVar5 + 1;
    param_1 = param_1 + 0x25;
    if (0x1f < uVar5) {
      return iVar4;
    }
  } while( true );
}



===== NvStorAhciControllerReleaseResources @ 0001cc14 =====

undefined8 NvStorAhciControllerReleaseResources(undefined8 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)param_1[0x519] + 0xc);
  uVar3 = 0;
  do {
    if ((uVar2 >> (uVar3 & 0x1f) & 1) != 0) {
      lVar1 = param_1[0x1e];
      if (*(longlong *)(lVar1 + 0x18) != 0) {
        (**(code **)(NvStorOsCBT + 0x108))(*param_1,*(longlong *)(lVar1 + 0x18),0);
        *(undefined8 *)(lVar1 + 0x18) = 0;
      }
      if (*(longlong *)(lVar1 + 0x10) != 0) {
        (**(code **)(NvStorOsCBT + 0x108))(*param_1);
        *(undefined8 *)(lVar1 + 0x10) = 0;
      }
      if (*(longlong *)(lVar1 + 0x20) != 0) {
        (**(code **)(NvStorOsCBT + 0x108))(*param_1);
        *(undefined8 *)(lVar1 + 0x20) = 0;
      }
    }
    uVar3 = uVar3 + 1;
    param_1 = param_1 + 0x25;
  } while (uVar3 < 0x20);
  return 0;
}



===== NvStorAhciControllerStart @ 0001ccdc =====

ulonglong NvStorAhciControllerStart(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar3 = NvStorAhciEnableAhciMode(param_1);
  if (-1 < (int)uVar3) {
    if (((*(uint *)(param_1 + 0x25f0) >> 0xe & 1) != 0) ||
       ((*(uint *)(param_1 + 0x25f0) >> 0xf & 1) != 0)) {
      uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1);
      *(uint *)(plVar1 + 1) = uVar2 | 0x4000000;
      (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 0xa0,uVar2 | 0x4000000);
    }
    uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 0xc);
    uVar5 = 0;
    uVar3 = uVar3 & 0xffffffff;
    do {
      if ((uVar2 >> (uVar5 & 0x1f) & 1) != 0) {
        uVar4 = NvStorPortStart((longlong *)((ulonglong)uVar5 * 0x128 + param_1));
        uVar3 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) {
          return uVar4;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x20);
    *(undefined4 *)(param_1 + 0x2664) = 1;
    *(undefined1 *)(param_1 + 0x28d8) = 0;
  }
  return uVar3;
}



===== NvStorAhciControllerStop @ 0001cdb4 =====

ulonglong NvStorAhciControllerStop(longlong param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar4 = 0;
  uVar3 = 0;
  do {
    if ((*(uint *)(*plVar1 + 0xc) >> (uVar3 & 0x1f) & 1) != 0) {
      uVar2 = NvStorPortStop((longlong *)((ulonglong)uVar3 * 0x128 + param_1));
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x20);
  NvStorAhciDisableInterruptsGlobal(param_1);
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
  (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 4,uVar3 & 0x7fffffff);
  (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
  (**(code **)(NvStorOsCBT + 0x180))(0x14);
  *(undefined4 *)(param_1 + 0x2664) = 2;
  return uVar4;
}



===== NvStorAhciControllerRestart @ 0001ce8c =====

uint NvStorAhciControllerRestart(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  
  plVar1 = (longlong *)param_1[0x519];
  uVar2 = NvStorControllerStart((ulonglong)param_1);
  if (-1 < (int)uVar2) {
    uVar3 = 0;
    plVar4 = param_1;
    do {
      if ((*(uint *)(*plVar1 + 0xc) >> (uVar3 & 0x1f) & 1) != 0) {
        uVar2 = 0;
        if (*(code **)(*plVar4 + 0x2748) != (code *)0x0) {
          uVar2 = (**(code **)(*plVar4 + 0x2748))(plVar4);
        }
        if ((int)uVar2 < 0) break;
        (**(code **)(NvStorOsCBT + 0x188))(param_1,(char)plVar4[0x1b]);
      }
      uVar3 = uVar3 + 1;
      plVar4 = plVar4 + 0x25;
    } while (uVar3 < 0x20);
  }
  return uVar2;
}



===== NvStorAhciControllerIsReady @ 0001cf2c =====

undefined8 NvStorAhciControllerIsReady(longlong param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  char cVar5;
  byte bVar6;
  
  uVar3 = 1;
  puVar2 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x2500) != '\0') {
    do {
      register0x00000020 = (BADSPACEBASE *)puVar2;
      cVar5 = (char)register0x00000020;
      puVar4 = (undefined8 *)((longlong)register0x00000020 * 0x128 + param_1);
      if (puVar4 != (undefined8 *)0x0) {
        lVar1 = puVar4[0x1e];
        register0x00000020 =
             (BADSPACEBASE *)
             (**(code **)(NvStorOsCBT + 0x40))(*puVar4,*(longlong *)(lVar1 + 0x28) + 0x28);
        if ((((ulonglong)register0x00000020 & 0xf) != 0) &&
           ((((((uint)register0x00000020 & 0xf) == 1 ||
              (((ulonglong)register0x00000020 & 0xf0) == 0)) ||
             (((ulonglong)register0x00000020 & 0xf00) == 0)) ||
            (register0x00000020 =
                  (BADSPACEBASE *)
                  (**(code **)(NvStorOsCBT + 0x30))(*puVar4,*(longlong *)(lVar1 + 0x28) + 0x20),
            ((ulonglong)register0x00000020 & 0x88) != 0)))) {
          uVar3 = 0;
          break;
        }
      }
      bVar6 = cVar5 + 1;
      puVar2 = (undefined1 *)(ulonglong)bVar6;
    } while (bVar6 < *(byte *)(param_1 + 0x2500));
  }
  return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),uVar3);
}



===== NvStorAhciDeviceIsReady @ 0001cfe4 =====

bool NvStorAhciDeviceIsReady(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  bool bVar3;
  
  lVar1 = ((undefined8 *)*param_1)[0x1e];
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))
                    (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x28);
  if ((uVar2 & 0xf) == 0) {
    bVar3 = true;
  }
  else {
    uVar2 = (**(code **)(NvStorOsCBT + 0x30))
                      (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x20);
    bVar3 = (uVar2 & 0x88) == 0;
  }
  return bVar3;
}



===== NvStorAhciDeviceConfigNotify @ 0001d040 =====

uint NvStorAhciDeviceConfigNotify(int param_1,longlong *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  char local_res8 [8];
  
  uVar2 = 0;
  lVar1 = *(longlong *)*param_2;
  if (param_1 == 0) {
    if (param_3 == 0x26) {
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'&',
                              (undefined8 *)local_res8,1);
      if (local_res8[0] == '\0') {
        param_2[0x112] = param_2[0x112] & 0xffffffffffffff7f;
      }
      else {
        param_2[0x112] = param_2[0x112] | 0x80;
      }
    }
    else if (param_3 == 0x28) {
      uVar2 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'(',
                              (undefined8 *)local_res8,1);
      if (local_res8[0] == '\0') {
        param_2[0x112] = param_2[0x112] & 0xffffffffffffefff;
      }
      else {
        param_2[0x112] = param_2[0x112] | 0x1000;
      }
    }
    else if (param_3 == 0x41) {
      NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_2[0xb6],'A',
                      (undefined8 *)local_res8,1);
      uVar2 = NvCfgElementSet(*(longlong *)(lVar1 + 0x2820),*(longlong **)(*param_2 + 0x100),'\x17',
                              (ulonglong *)local_res8,1);
    }
  }
  return uVar2;
}



===== NvStorAhciPortInitialize @ 0001d154 =====

undefined8 NvStorAhciPortInitialize(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(*param_1 + 0x28c8);
  lVar3 = (**(code **)(NvStorOsCBT + 0x1a0))();
  lVar4 = NvStorOsCBT;
  param_1[0x1e] = lVar3;
  (**(code **)(lVar4 + 0x110))(lVar3,0x30);
  param_1[0x1d] = (longlong)&NvStorAhciPortCheckInterruptSingleDevice;
  param_1[0x1c] = (longlong)NvStorAhciPortDpcSingleDevice;
  lVar4 = (longlong)(int)((uint)*(byte *)(param_1 + 0x1b) << 7) +
          *(longlong *)(*param_1 + 0x25e0) + 0x100;
  *(longlong *)(lVar3 + 0x28) = lVar4;
  if ((*(uint *)(lVar1 + 8) & 0x20) != 0) {
    uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,lVar4 + 0x18);
    if ((uVar2 >> 0x15 & 1) != 0) {
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x80;
    }
  }
  return 0;
}



===== NvStorAhciPortStart @ 0001d218 =====

undefined8 NvStorAhciPortStart(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint local_res8 [2];
  
  lVar1 = param_1[0x1e];
  uVar6 = 0;
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar2 | 0x300);
  if ((*(byte *)((longlong)param_1 + 0x124) & 0xcf) != 0) {
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x10,0xffffffff);
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,0xffffffff);
  }
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  if ((uVar2 & 0x8001) != 0) {
    (**(code **)(NvStorOsCBT + 0xa0))
              (*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar2 & 0xfffffffe);
    FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,0x8000,0,500000);
  }
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  if ((uVar2 & 0x4010) != 0) {
    (**(code **)(NvStorOsCBT + 0xa0))
              (*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar2 & 0xffffffef);
    FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,0x4000,0,500000);
  }
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  if ((uVar3 & 0xc011) == 0) {
    local_res8[0] = *(int *)(*param_1 + 0x2504) << 5;
    uVar3 = (**(code **)(NvStorOsCBT + 0x1b8))(*param_1,0,*(undefined8 *)(lVar1 + 0x18),local_res8);
    if ((uVar3 != 0) && ((ulonglong)*(uint *)(*param_1 + 0x2504) << 5 <= (ulonglong)local_res8[0]))
    {
      (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(undefined8 *)(lVar1 + 0x28),uVar3 & 0xffffffff);
      (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 4,uVar3 >> 0x20);
      local_res8[0] = 0x100;
      uVar3 = (**(code **)(NvStorOsCBT + 0x1b8))
                        (*param_1,0,*(undefined8 *)(lVar1 + 0x10),local_res8);
      if ((uVar3 != 0) && (0xff < local_res8[0])) {
        (**(code **)(NvStorOsCBT + 0xa0))
                  (*param_1,*(longlong *)(lVar1 + 0x28) + 8,uVar3 & 0xffffffff);
        (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0xc,uVar3 >> 0x20);
        lVar4 = *param_1;
        uVar3 = 0;
        if (*(int *)(lVar4 + 0x2504) != 0) {
          do {
            lVar5 = uVar3 * 0x20 + *(longlong *)(lVar1 + 0x18);
            local_res8[0] = 0x300;
            lVar4 = (**(code **)(NvStorOsCBT + 0x1b8))
                              (lVar4,0,uVar3 * 0x300 + *(longlong *)(lVar1 + 0x20),local_res8);
            if ((lVar4 == 0) || (local_res8[0] < 0x300)) goto LAB_0001d56c;
            *(int *)(lVar5 + 8) = (int)lVar4;
            uVar2 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar2;
            *(int *)(lVar5 + 0xc) = (int)((ulonglong)lVar4 >> 0x20);
            lVar4 = *param_1;
          } while (uVar2 < *(uint *)(lVar4 + 0x2504));
        }
        lVar4 = param_1[0x1e];
        uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x18);
        (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x18,uVar2 | 0x10);
        (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,0xfff0f03);
        (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x10,0x7840007f);
        NvStorAhciEnableInterrupts(param_1);
        return 0;
      }
    }
LAB_0001d56c:
    uVar6 = 0x80000011;
  }
  return uVar6;
}



===== NvStorAhciPortStop @ 0001d588 =====

undefined8 NvStorAhciPortStop(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  lVar1 = param_1[0x1e];
  bVar8 = 0;
  if ((short)param_1[2] != 0) {
    do {
      if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_0001d5e4:
        plVar2 = (longlong *)param_1[(ulonglong)bVar8 + 1];
        if (plVar2 != (longlong *)0x0) {
          uVar6 = NvStorAhciDeviceStop(plVar2);
          if ((int)uVar6 < 0) break;
          uVar7 = plVar2[0x112];
          if (((((uVar7 & 0x20) == 0) && ((uVar7 >> 0x18 & 1) == 0)) &&
              ((*(uint *)((longlong *)*plVar2 + 0x24) & 2) == 0)) &&
             (((uVar7 & 0x200000000000) == 0 && ((uVar7 >> 0x17 & 1) != 0)))) {
            lVar3 = *(longlong *)*plVar2;
            uVar7 = (**(code **)(NvStorOsCBT + 0x40))(lVar3,**(longlong **)(lVar3 + 0x28c8) + 4);
            if ((uVar7 & 2) != 0) {
              NvStorAhciFlushCache(plVar2);
              if (((*(char *)(*param_1 + 0x2668) - 2U & 0xf9) == 0) &&
                 (*(char *)(*param_1 + 0x2668) != '\b')) {
                NvStorAhciSendAtaRequestNoData(plVar2);
              }
            }
          }
        }
      }
      else {
        cVar4 = (**(code **)(NvStorOsCBT + 0x208))(param_1,bVar8,1);
        if (cVar4 != '\0') goto LAB_0001d5e4;
      }
      bVar8 = bVar8 + 1;
    } while ((ushort)bVar8 < *(ushort *)(param_1 + 2));
  }
  uVar5 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  if ((((uVar5 >> 9 & 1) != 0) || ((uVar5 >> 8 & 1) != 0)) || (uVar5 == 0)) {
    NvStorAhciPortToActiveState(param_1);
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar5 | 0x300);
  }
  lVar1 = param_1[0x1e];
  uVar5 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar5 & 0xffffffef);
  NvStorAhciStopCommandListProcessing(param_1);
  NvStorAhciDisableInterrupts(param_1);
  return 0;
}



===== NvStorAhciPortToPartialState @ 0001d748 =====

undefined8 NvStorAhciPortToPartialState(undefined8 *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  lVar1 = param_1[0x1e];
  iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
  if ((iVar2 == 0) &&
     (iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x34),
     iVar2 == 0)) {
    uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
    if ((uVar3 & 0xf0000000) == 0) {
      uVar3 = uVar3 & 0xfffffff | 0x20000000;
    }
    else {
      if ((uVar3 & 0xf0000000) != 0x60000000) {
        return 0;
      }
      uVar3 = uVar3 & 0xfffffff | 0x10000000;
    }
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar3);
  }
  return 0;
}



===== NvStorAhciPortToSlumberState @ 0001d7f4 =====

undefined8 NvStorAhciPortToSlumberState(undefined8 *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  lVar1 = param_1[0x1e];
  iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
  if ((iVar2 == 0) &&
     (iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x34),
     iVar2 == 0)) {
    uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
    if ((uVar3 & 0xf0000000) == 0) {
      uVar3 = uVar3 & 0xfffffff | 0x60000000;
    }
    else {
      if (((uVar3 & 0xf0000000) != 0x20000000) && ((uVar3 & 0xf0000000) != 0x60000000)) {
        return 0;
      }
      uVar3 = uVar3 & 0xfffffff | 0x10000000;
    }
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar3);
  }
  return 0;
}



===== NvStorAhciPortToActiveState @ 0001d8a8 =====

undefined8 NvStorAhciPortToActiveState(undefined8 *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  lVar1 = param_1[0x1e];
  iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x34);
    if (iVar2 == 0) {
      uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
      if ((uVar3 & 0xf0000000) == 0) {
        uVar4 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x28);
        if ((uVar4 & 0xf00) != 0x100) {
          (**(code **)(NvStorOsCBT + 0xa0))
                    (*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar3 & 0xfffffff | 0x10000000);
        }
      }
    }
  }
  return 0;
}



===== NvStorAhciDeviceInitialize @ 0001d96c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NvStorAhciDeviceInitialize(longlong *param_1,longlong *param_2,byte param_3,undefined8 param_4)

{
  longlong *plVar1;
  ushort uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  byte *pbVar6;
  bool bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  byte *pbVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  byte bVar16;
  uint uVar17;
  undefined7 uVar18;
  undefined1 auStack_c8 [32];
  undefined2 local_78;
  undefined1 local_76;
  byte local_60 [8];
  byte local_58 [16];
  byte local_48 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  plVar3 = (longlong *)param_2[0x110];
  lVar4 = param_1[0x1e];
  puVar5 = *(undefined8 **)(*param_1 + 0x28c8);
  (**(code **)(NvStorOsCBT + 0x110))(plVar3,0x18);
  if (param_3 == 0) {
    uVar10 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*puVar5);
    if ((uVar10 & 0x2000) == 0) {
      *(byte *)((longlong)param_1 + 0x124) = *(byte *)((longlong)param_1 + 0x124) & 0xba;
    }
    if ((uVar10 >> 0xe & 1) == 0) {
      *(byte *)((longlong)param_1 + 0x124) = *(byte *)((longlong)param_1 + 0x124) & 0x75;
    }
    uVar10 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x28);
    if ((uVar10 & 0xf00) == 0) {
      uVar17 = 0;
      do {
        (**(code **)(NvStorOsCBT + 0x180))(10);
        uVar10 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x28);
        if ((uVar10 & 0xf00) != 0) break;
        uVar17 = uVar17 + 1;
      } while (uVar17 < 0x5dc);
      if (uVar17 == 0x5dc) {
        uVar17 = 0x80000010;
        goto LAB_0001db30;
      }
    }
    param_2[0x112] = param_2[0x112] | 0x200000;
    if (*plVar3 == 0) {
      param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),1);
      lVar12 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0x200,2,param_4);
      *plVar3 = lVar12;
      if (lVar12 == 0) {
        uVar17 = 0x80000011;
        goto LAB_0001db30;
      }
    }
    (**(code **)(NvStorOsCBT + 0x110))(*plVar3,0x200);
    pbVar6 = (byte *)*plVar3;
    uVar17 = 0;
    do {
      bVar16 = FUN_0001fbe4(*param_1,*(longlong *)(lVar4 + 0x28) + 0x20);
      if (((bVar16 & 0x88) != 0) &&
         (uVar9 = NvStorAhciResetSATAPhy((longlong *)*param_2), (int)uVar9 < 0)) break;
      uVar17 = uVar17 + 1;
    } while (uVar17 < 2);
    if ((bVar16 & 0x88) == 0) {
      uVar17 = NvStorAhciStartCommandListProcessing(param_1);
      if (-1 < (int)uVar17) {
        if (((*(uint *)(*param_1 + 0x2818) & 0x200) != 0) &&
           ((*(byte *)(param_2 + 0x112) & 0x20) == 0)) {
          NvStorAhciExecuteTaskFile(param_2);
        }
        uVar17 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c);
        (**(code **)(NvStorOsCBT + 0xa0))
                  (*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c,uVar17 | 0x300);
        if ((*(byte *)((longlong)param_1 + 0x124) & 0xcf) != 0) {
          (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x10,0xffffffff);
          (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x30,0xffffffff);
        }
        uVar17 = FUN_0001fcc4(param_2);
        if (-1 < (int)uVar17) {
          *(uint *)((longlong)plVar3 + 0xc) = uVar10 & 0xf0;
          *(undefined4 *)(plVar3 + 2) = 0;
          if ((pbVar6[0x98] & 2) != 0) {
            *(undefined4 *)(plVar3 + 2) = 0x10;
          }
          if ((pbVar6[0x98] & 4) != 0) {
            *(uint *)(plVar3 + 2) = *(uint *)(plVar3 + 2) | 0x20;
          }
          if ((int)plVar3[2] == 0) {
            *(uint *)(plVar3 + 2) = uVar10 & 0xf0;
          }
          uVar15 = param_2[0x112];
          if ((uVar15 & 0x20) != 0) {
            param_2[0x112] = uVar15 | 0x200;
            if ((*pbVar6 & 0x20) == 0) {
              uVar15 = uVar15 & 0xffffffffffffffbf | 0x200;
            }
            else {
              uVar15 = uVar15 | 0x240;
            }
            param_2[0x112] = uVar15;
            if ((pbVar6[1] & 0x1f) == 1) {
              param_2[0x112] = param_2[0x112] & 0xfffffffffffffdff;
            }
          }
          cVar8 = (**(code **)(NvStorOsCBT + 0x1c8))(param_1);
          bVar7 = (param_2[0x112] & 0x20U) == 0 && cVar8 != '\0';
          if (bVar7) {
            param_2[0x112] = param_2[0x112] | 0x800000000000;
          }
          uVar18 = (undefined7)((ulonglong)param_4 >> 8);
          NvStorScsiBuildInquiryPage((char *)pbVar6,(byte *)(param_2 + 6),(longlong)local_60,bVar7);
          pbVar13 = NvStorGetDeviceQuirks(local_60,local_58,local_48);
          param_2[0x112] = param_2[0x112] & 0xfffffffffdffffff;
          param_2[1] = (longlong)pbVar13;
          if ((char)*pbVar6 < '\0') {
            param_2[0x112] = param_2[0x112] | 1;
          }
          if ((*(ushort *)(pbVar6 + 0xa6) & 0x400) != 0) {
            param_2[0x112] = param_2[0x112] | 0x10;
          }
          if (((pbVar6[0xa4] & 0x20) != 0) && (uVar15 = param_2[0x112], (uVar15 & 0x20) == 0)) {
            param_2[0x112] = uVar15 | 0x800;
            if ((pbVar6[0xaa] & 0x20) == 0) {
              uVar15 = uVar15 & 0xffffffffffffefff | 0x800;
            }
            else {
              uVar15 = uVar15 | 0x1800;
            }
            param_2[0x112] = uVar15;
          }
          *(undefined2 *)(param_2 + 0x44) = 1;
          if ((pbVar6[0xb1] != 0) || (pbVar6[0x7f] != 0)) {
            param_2[0x112] = param_2[0x112] | 0x80;
          }
          if ((pbVar6[0xa6] & 8) != 0) {
            param_2[0x112] = param_2[0x112] | 0x1000000000;
          }
          if ((*(ushort *)(pbVar6 + 0xa6) & 0x200) != 0) {
            param_2[0x112] = param_2[0x112] | 0x40000000000;
          }
          if ((pbVar6[0xee] & 2) != 0) {
            param_2[0x112] = param_2[0x112] | 0x4000000000;
          }
          if ((pbVar6[0xee] & 0x20) != 0) {
            param_2[0x112] = param_2[0x112] | 0x10000000000;
          }
          NvStorDeviceBuildIdentifyString((longlong)param_2,(longlong)pbVar6);
          uVar17 = FUN_0002000c(param_2);
          if (-1 < (int)uVar17) {
            if (((((*(byte *)(param_2 + 0x112) & 0x20) == 0) &&
                 ((*(ushort *)(pbVar6 + 0x100) & 1) != 0)) &&
                ((*(ushort *)(pbVar6 + 0x100) & 8) == 0)) &&
               ((*(uint *)(*param_1 + 0x2818) & 0x800) != 0)) {
              (**(code **)(NvStorOsCBT + 0x110))(&local_78,0x14);
              local_78 = 0x8027;
              local_76 = 0xf5;
              FUN_000201b0(param_2,&local_78);
            }
            if ((param_2[0x112] & 0x20U) == 0) {
              param_2[0x112] = param_2[0x112] & 0xfffffffffffffeff;
              if (1 < pbVar6[0x5e]) {
                uVar17 = FUN_000200b8(param_2,0xc6,0,pbVar6[0x5e],'\0');
                if ((int)uVar17 < 0) goto LAB_0001db30;
                param_2[0x112] = param_2[0x112] | 0x100;
              }
            }
            if ((((*(byte *)((longlong)param_1 + 0x124) & 0xc0) == 0) ||
                ((*(uint *)(param_2 + 0x112) >> 0x1d & 1) == 0)) ||
               (uVar17 = FUN_000200b8(param_2,0xef,0x10,3,'\0'), -1 < (int)uVar17)) {
              if ((*(ushort *)(pbVar6 + 0xd4) & 0x1000) == 0) {
                iVar11 = 0x200;
              }
              else {
                iVar11 = *(int *)(pbVar6 + 0xea) * 2;
              }
              *(int *)(param_2 + 0x46) = iVar11;
              if ((*(ushort *)(pbVar6 + 0xd4) & 0x2000) != 0) {
                param_2[0x112] = param_2[0x112] | 0x40000000000000;
                *(byte *)((longlong)param_2 + 0x234) = pbVar6[0xd4] & 0xf;
                *(ushort *)((longlong)param_2 + 0x236) = *(ushort *)(pbVar6 + 0x1a2) & 0x3fff;
              }
              *(uint *)(param_2 + 0x47) = (uint)pbVar6[0x5e] * (int)param_2[0x46];
              if ((*(byte *)(param_2 + 0x112) & 0x10) == 0) {
                uVar2 = *(ushort *)(pbVar6 + 0x78);
                uVar15 = (ulonglong)*(ushort *)(pbVar6 + 0x7a);
              }
              else {
                uVar15 = (ulonglong)*(uint6 *)(pbVar6 + 0xca);
                uVar2 = *(ushort *)(pbVar6 + 200);
              }
              param_2[0x45] = (uVar15 << 0x10 | (ulonglong)uVar2) - 1;
              FUN_0001fcc4(param_2);
              NvStorInitializeTags(param_2,*(uint *)(*param_1 + 0x2504));
              lVar12 = *(longlong *)*param_2;
              plVar1 = param_2 + 0x36;
              param_2[0x37] = (longlong)plVar1;
              *plVar1 = (longlong)plVar1;
              *(undefined4 *)((longlong)param_2 + 0x1dc) = 0xffffffff;
              param_2[0x35] = lVar12;
              *(undefined4 *)(param_2 + 0x39) = 0;
              *(uint *)((longlong)param_2 + 0x1cc) = (uint)*(ushort *)(param_2 + 0x44);
              param_2[0x38] = (longlong)(param_2 + 0x48);
              param_2[0x3a] = 0;
              param_2[0x3c] = 0;
              param_2[0x3d] = 0;
              param_2[0x3e] = 0;
              *(undefined4 *)(param_2 + 0x3b) = 0x100;
              if ((*(byte *)(param_2 + 0x112) & 0x20) == 0) {
                *(undefined4 *)((longlong)param_2 + 0x1d4) = 2;
              }
              *(uint *)((longlong)param_2 + 0x1d4) = *(uint *)((longlong)param_2 + 0x1d4) | 4;
              lVar12 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0x14,0,CONCAT71(uVar18,1));
              param_2[0x2e] = lVar12;
              if (lVar12 != 0) {
                lVar12 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0xff,2,1);
                param_2[0x33] = lVar12;
                if (lVar12 != 0) {
                  lVar12 = (**(code **)(NvStorOsCBT + 0x100))(*param_1,0x14,0,1);
                  param_2[0xed] = lVar12;
                  if (lVar12 != 0) {
                    (**(code **)(NvStorOsCBT + 0x110))(lVar12,0x14);
                    param_2[0x6d] = (longlong)&NvStorAhciSetupRequest;
                    param_2[0x6e] = (longlong)NvStorAhciAtaSuccess;
                    param_2[0x6f] = (longlong)NvStorAhciAtaHandleError;
                    param_2[0x70] = (longlong)NvStorAhciAtaCancel;
                    param_2[0x71] = (longlong)NvStorAhciDeviceReset;
                    param_2[0x75] = (longlong)&NvStorSpinLockCreate;
                    if ((param_2[0x112] & 0x20U) != 0) {
                      param_2[0x6f] = (longlong)NvStorAhciAtapiHandleError;
                    }
                    param_2[0x112] = param_2[0x112] & 0xfffffffdffffffffU | 0x800000;
                    *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffd;
                    *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffb;
                    NvStorScsiPrintDeviceSummary((longlong)param_2);
                    if ((*(byte *)((longlong)param_1 + 0x124) & 3) != 0) {
                      uVar10 = (**(code **)(NvStorOsCBT + 0x40))
                                         (*param_1,*(longlong *)(lVar4 + 0x28) + 0x18);
                      uVar10 = uVar10 & 0xfbffffff;
                      if ((*(uint *)(param_2 + 0x112) >> 0x1c & 1) != 0) {
                        uVar10 = uVar10 | 0x4000000;
                      }
                      lVar12 = *param_1;
                      if (((lVar12 != 0) && ((*(uint *)(lVar12 + 0x25f0) & 0x400000) != 0)) &&
                         ((*(uint *)(param_2[1] + 0x20) & 8) != 0)) {
                        uVar10 = uVar10 & 0xfbffffff;
                      }
                      if ((*(byte *)((longlong)param_1 + 0x124) & 2) == 0) {
                        uVar17 = uVar10 & 0xf7ffffff;
                      }
                      else {
                        uVar17 = uVar10 | 0x8000000;
                        if ((*(uint *)(param_2[1] + 0x20) & 0x40) != 0) {
                          uVar17 = uVar10 & 0xfbffffff | 0x8000000;
                        }
                      }
                      (**(code **)(NvStorOsCBT + 0xa0))
                                (lVar12,*(longlong *)(lVar4 + 0x28) + 0x18,uVar17);
                    }
                    uVar10 = (**(code **)(NvStorOsCBT + 0x40))
                                       (*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c);
                    bVar16 = *(byte *)((longlong)param_1 + 0x124);
                    uVar10 = uVar10 & 0xfffff0ff;
                    if (((bVar16 & 0x40) == 0) || (-1 < (char)bVar16)) {
                      if ((bVar16 & 0x40) != 0) {
                        uVar10 = uVar10 | 0x200;
                      }
                      if (((char)bVar16 < '\0') && ((*(uint *)(param_2[1] + 0x20) & 0x40) != 0)) {
                        uVar10 = uVar10 | 0x300;
                      }
                    }
                    (**(code **)(NvStorOsCBT + 0xa0))
                              (*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c,uVar10);
                    if (((((*(uint *)(*(longlong *)*param_2 + 0x2818) & 2) == 0) &&
                         ((param_2[0x112] & 0x20U) == 0)) &&
                        ((*(ushort *)(pbVar6 + 0x100) & 1) != 0)) &&
                       ((((*(ushort *)(pbVar6 + 0x100) & 8) == 0 &&
                         ((param_2[0x112] & 0x10000000000000U) == 0)) &&
                        (((*(uint *)(*param_1 + 0x2818) & 0x800) == 0 &&
                         (uVar14 = NvStorAhciSetupFeatureRequest(param_2,(longlong)(param_2 + 0xf2))
                         , -1 < (int)uVar14)))))) {
                      param_2[0x112] = param_2[0x112] | 0x18000000000000;
                    }
                    return 0;
                  }
                }
              }
              uVar17 = 0x80000011;
            }
          }
        }
      }
    }
    else {
      uVar17 = 0x80000003;
    }
  }
  else {
    uVar17 = 0x80000010;
  }
LAB_0001db30:
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffd;
  *(uint *)(*param_2 + 0x120) = *(uint *)(*param_2 + 0x120) & 0xfffffffb;
  if (param_2[0x2e] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x2e],1);
    param_2[0x2e] = 0;
  }
  if (param_2[0x33] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x33],1);
    param_2[0x33] = 0;
  }
  if (*plVar3 != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,*plVar3,1);
    *plVar3 = 0;
  }
  if (param_2[0xed] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0xed],1);
    param_2[0xed] = 0;
  }
  if (param_2[0x10b] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*param_1,param_2[0x10b],1);
    param_2[0x10b] = 0;
  }
  param_1[(ulonglong)param_3 + 1] = 0;
  uVar10 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c);
  uVar10 = uVar10 & 0xfffff0ff;
  bVar16 = *(byte *)((longlong)param_1 + 0x124) & 0x40;
  if (((bVar16 == 0) || (-1 < (char)*(byte *)((longlong)param_1 + 0x124))) && (bVar16 != 0)) {
    uVar10 = uVar10 | 0x200;
  }
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x2c,uVar10);
  return uVar17;
}



===== NvStorAhciDeviceStart @ 0001e47c =====

void NvStorAhciDeviceStart(undefined8 *param_1)

{
  uint uVar1;
  undefined1 local_res8 [32];
  
  local_res8[0] = 1;
  NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'$',
                  (ulonglong *)local_res8,1);
  uVar1 = NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],
                          '2',(ulonglong *)(param_1[0x110] + 0x10),4);
  if (-1 < (int)uVar1) {
    uVar1 = NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],
                            '3',(ulonglong *)(param_1[0x110] + 0xc),4);
    if (-1 < (int)uVar1) {
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'4',
                      (ulonglong *)(param_1[0x110] + 0xc),4);
    }
  }
  return;
}



===== NvStorAhciDeviceStop @ 0001e550 =====

undefined8 NvStorAhciDeviceStop(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = param_1[0x112];
  if (((((uVar2 & 0x20) == 0) && ((uVar2 >> 0x18 & 1) == 0)) &&
      ((*(uint *)((longlong *)*param_1 + 0x24) & 2) == 0)) && ((uVar2 & 0x200000000) == 0)) {
    lVar1 = *(longlong *)*param_1;
    uVar2 = (**(code **)(NvStorOsCBT + 0x40))(lVar1,**(longlong **)(lVar1 + 0x28c8) + 4);
    if ((uVar2 & 2) != 0) {
      NvStorAhciFlushCache(param_1);
    }
  }
  param_1[0x112] = param_1[0x112] | 0x200000000;
  return 0;
}



===== NvStorAhciDeviceRemove @ 0001e5c8 =====

undefined8 NvStorAhciDeviceRemove(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)param_1[0x110];
  if ((*(uint *)(param_1 + 0x112) >> 0x17 & 1) != 0) {
    NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000002,param_3,1);
  }
  if (param_1[0x2e] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x2e],1);
    param_1[0x2e] = 0;
  }
  if (param_1[0x33] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x33],1);
    param_1[0x33] = 0;
  }
  lVar2 = *plVar1;
  if (lVar2 != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,lVar2,1);
    *plVar1 = 0;
  }
  if (param_1[0xed] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0xed],1);
    param_1[0xed] = 0;
  }
  if (param_1[0x10b] != 0) {
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)*param_1,param_1[0x10b],1);
    param_1[0x10b] = 0;
  }
  return 0;
}



===== NvStorAhciControllerCfgSetup @ 0001e6d4 =====

uint NvStorAhciControllerCfgSetup(longlong param_1)

{
  uint uVar1;
  undefined1 local_res8 [32];
  
  uVar1 = 0;
  if ((char)*(undefined4 *)(*(longlong *)(param_1 + 0x28c8) + 8) < '\0') {
    local_res8[0] = 1;
    uVar1 = NvCfgElementSet(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830),'\x11',
                            (ulonglong *)local_res8,1);
  }
  return uVar1;
}



===== NvStorAhciDeviceCfgStart @ 0001e71c =====

uint NvStorAhciDeviceCfgStart(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (((param_1[0x112] & 0x1000000000U) != 0) && ((param_1[0x112] & 0x2000000000U) != 0)) {
    uVar1 = FUN_000200b8(param_1,0xef,5,*(undefined1 *)((longlong)param_1 + 0x89a),'\0');
  }
  if (((param_1[0x112] & 0x40000000000U) != 0) && ((param_1[0x112] & 0x80000000000U) != 0)) {
    uVar2 = FUN_000200b8(param_1,0xef,0x42,*(undefined1 *)((longlong)param_1 + 0x89b),'\0');
    uVar1 = uVar1 | uVar2;
  }
  if (((param_1[0x112] & 0x10000000000U) != 0) && ((param_1[0x112] & 0x20000000000U) != 0)) {
    uVar2 = FUN_000200b8(param_1,0xef,0x41,0,'\0');
    uVar1 = uVar1 | uVar2;
  }
  if (((param_1[0x112] & 0x4000000000U) != 0) && ((param_1[0x112] & 0x8000000000U) != 0)) {
    uVar2 = FUN_000200b8(param_1,0xef,0xb,0,'\0');
    uVar1 = uVar1 | uVar2;
  }
  return uVar1;
}



===== NvStorAhciCheckInterrupt @ 0001e830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char NvStorAhciCheckInterrupt(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  byte bVar10;
  longlong *plVar11;
  uint uVar12;
  char *pcVar13;
  longlong *plVar14;
  undefined1 auStackY_b8 [32];
  byte local_88 [4];
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  char *local_70;
  longlong *local_68;
  longlong local_60;
  char local_58 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  plVar14 = (longlong *)param_1[0x519];
  local_84 = 0;
  local_68 = plVar14;
  uVar5 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar14 + 8);
  bVar10 = 0;
  local_80 = (uint)(uVar5 != 0);
  do {
    uVar9 = (ulonglong)bVar10;
    if (0x1f < uVar9) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(8);
      pcVar2 = (code *)swi(3);
      cVar4 = (*pcVar2)();
      return cVar4;
    }
    bVar10 = bVar10 + 1;
    local_58[uVar9] = '\0';
  } while (bVar10 < 0x20);
  bVar10 = 0;
  pcVar13 = local_58;
  plVar11 = param_1 + 0x1e;
  do {
    uVar12 = 1 << (bVar10 & 0x1f);
    if ((((*(uint *)(*plVar14 + 0xc) & uVar12) != 0) && ((uVar5 & uVar12) != 0)) &&
       (iVar6 = (*(code *)plVar11[-1])(plVar11 + -0x1e,0), iVar6 == 2)) {
      lVar1 = *plVar11;
      uVar7 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar1 + 0x28) + 0x10);
      *(uint *)(lVar1 + 8) = *(uint *)(lVar1 + 8) | uVar7;
      (**(code **)(NvStorOsCBT + 0xa0))
                (param_1,*(longlong *)(lVar1 + 0x28) + 0x10,*(undefined4 *)(lVar1 + 8));
      uVar7 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
      *(uint *)(lVar1 + 0xc) = *(uint *)(lVar1 + 0xc) | uVar7;
      (**(code **)(NvStorOsCBT + 0xa0))
                (param_1,*(longlong *)(lVar1 + 0x28) + 0x30,*(undefined4 *)(lVar1 + 0xc));
      local_84 = local_84 | uVar12;
      (**(code **)(NvStorOsCBT + 400))(plVar11 + -0x1e);
      *pcVar13 = '\x01';
    }
    bVar10 = bVar10 + 1;
    plVar11 = plVar11 + 0x25;
    pcVar13 = pcVar13 + 1;
  } while (bVar10 < 0x20);
  if ((*(uint *)(param_1 + 0x4be) >> 0xd & 1) != 0) {
    local_70 = local_58;
    uVar12 = 0;
    local_88[0] = 0;
    plVar11 = param_1;
    do {
      pcVar13 = local_70;
      bVar10 = (byte)uVar12;
      local_78 = uVar12;
      if ((*(uint *)(*plVar14 + 0xc) >> (uVar12 & 0x1f) & 1) != 0) {
        lVar1 = plVar11[1];
        local_60 = plVar11[0x1e];
        if ((((lVar1 != 0) && (uVar9 = *(ulonglong *)(lVar1 + 0x890), (uVar9 >> 0x17 & 1) != 0)) &&
            ((*local_70 == '\0' && (((uVar9 >> 0x1b & 1) == 0 && ((uVar9 >> 0x18 & 1) == 0)))))) &&
           (*(char *)(*(longlong *)(lVar1 + 0x880) + 8) != '\0')) {
          local_7c = (**(code **)(NvStorOsCBT + 0x40))
                               (param_1,*(longlong *)(local_60 + 0x28) + 0x34);
          lVar3 = local_60;
          uVar12 = local_78;
          uVar9 = 0;
          if (*(int *)(*plVar11 + 0x2504) != 0) {
            do {
              if ((*(longlong *)(lVar1 + 0x240 + uVar9 * 8) != 0) &&
                 ((local_7c >> ((uint)uVar9 & 0x1f) & 1) == 0)) {
                *(ulonglong *)(lVar1 + 0x890) = *(ulonglong *)(lVar1 + 0x890) | 0x8000000;
                uVar7 = 1 << ((byte)uVar12 & 0x1f);
                if ((local_84 & uVar7) == 0) {
                  uVar8 = (**(code **)(NvStorOsCBT + 0x40))
                                    (param_1,*(longlong *)(lVar3 + 0x28) + 0x10);
                  *(uint *)(lVar3 + 8) = *(uint *)(lVar3 + 8) | uVar8;
                  (**(code **)(NvStorOsCBT + 0xa0))
                            (param_1,*(longlong *)(lVar3 + 0x28) + 0x10,*(undefined4 *)(lVar3 + 8));
                  uVar8 = (**(code **)(NvStorOsCBT + 0x40))
                                    (param_1,*(longlong *)(lVar3 + 0x28) + 0x30);
                  *(uint *)(lVar3 + 0xc) = *(uint *)(lVar3 + 0xc) | uVar8;
                  (**(code **)(NvStorOsCBT + 0xa0))
                            (param_1,*(longlong *)(lVar3 + 0x28) + 0x30,*(undefined4 *)(lVar3 + 0xc)
                            );
                  local_84 = local_84 | uVar7;
                }
                (**(code **)(NvStorOsCBT + 400))(plVar11,plVar11[0x1c]);
                uVar5 = uVar5 | uVar7;
              }
              uVar7 = (uint)uVar9 + 1;
              uVar9 = (ulonglong)uVar7;
            } while (uVar7 < *(uint *)(*plVar11 + 0x2504));
            pcVar13 = local_70;
            plVar14 = local_68;
            bVar10 = local_88[0];
          }
        }
      }
      local_88[0] = bVar10 + 1;
      uVar12 = (uint)local_88[0];
      local_70 = pcVar13 + 1;
      plVar11 = plVar11 + 0x25;
    } while (local_88[0] < 0x20);
  }
  NvCfgElementGet(param_1[0x504],(longlong *)param_1[0x506],'\x11',(undefined8 *)local_88,1);
  if ((local_88[0] != 0) && ((uVar5 >> (*(byte *)((longlong)plVar14 + 0xc) & 0x1f) & 1) != 0)) {
    bVar10 = 0;
    plVar11 = param_1 + 1;
    do {
      uVar12 = 1 << (bVar10 & 0x1f);
      if (((uVar12 & *(uint *)(*plVar14 + 0xc)) != 0) &&
         ((uVar12 & *(uint *)(*plVar14 + 0x18)) != 0)) {
        lVar1 = plVar11[0x1d];
        uVar12 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
        uVar7 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar1 + 0x28) + 0x34);
        uVar9 = 0;
        if (*(int *)((longlong)param_1 + 0x2504) != 0) {
          do {
            if ((*(longlong *)(*plVar11 + 0x240 + uVar9 * 8) != 0) &&
               ((uVar8 = 1 << ((byte)uVar9 & 0x1f), (uVar12 & uVar8) == 0 || ((uVar7 & uVar8) == 0))
               )) {
              (**(code **)(NvStorOsCBT + 400))(plVar11 + -1,FUN_000205cc);
            }
            uVar8 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar8;
          } while (uVar8 < *(uint *)((longlong)param_1 + 0x2504));
        }
      }
      bVar10 = bVar10 + 1;
      plVar11 = plVar11 + 0x25;
    } while (bVar10 < 0x20);
  }
  cVar4 = (char)local_80;
  if (cVar4 != '\0') {
    (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar14 + 8,uVar5);
  }
  return cVar4;
}



===== NvStorAhciPortDpcSingleDevice @ 0001ece4 =====

void NvStorAhciPortDpcSingleDevice(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  char cVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 local_res10;
  undefined1 local_98 [32];
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  
  local_res10 = 0;
  (**(code **)(NvStorOsCBT + 0x150))(*param_1,0,(char)param_1[0x1b],local_58);
  lVar2 = param_1[0x1e];
  lVar3 = param_1[1];
  if (param_2 == '\0') {
    (**(code **)(NvStorOsCBT + 0x150))(*param_1,2,0,local_78);
  }
  uVar11 = *(uint *)(lVar2 + 8);
  *(undefined8 *)(lVar2 + 8) = 0;
  if (param_2 == '\0') {
    (**(code **)(NvStorOsCBT + 0x158))(*param_1,2,0,local_78);
  }
  if ((*(byte *)((longlong)param_1 + 0x124) & 0xcf) != 0) {
    uVar11 = uVar11 & 0xffbfffbf;
  }
  if ((uVar11 & 0x400040) != 0) {
    if ((lVar3 == 0) || ((*(ulonglong *)(lVar3 + 0x890) & 0x1000000) != 0)) {
      if ((uVar11 & 0x40) != 0) {
        *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x10;
        FUN_00020978(param_1);
      }
    }
    else if ((uVar11 >> 0x16 & 1) != 0) {
      *(ulonglong *)(lVar3 + 0x890) = *(ulonglong *)(lVar3 + 0x890) | 0x80000000;
    }
  }
  if (((lVar3 == 0) || ((*(ulonglong *)(lVar3 + 0x890) >> 0x17 & 1) == 0)) ||
     ((*(ulonglong *)(lVar3 + 0x890) & 0x1000000) != 0)) goto LAB_0001f090;
  lVar4 = *(longlong *)(lVar3 + 0x880);
  uVar13 = uVar11 & 0x78000000;
  if (uVar13 != 0) {
    NvStorAhciStopCommandListProcessing(param_1);
    FUN_00020804(param_1);
  }
  if ((uVar11 >> 0x1e & 1) != 0) {
    local_res10 = *(undefined1 *)(*(longlong *)(lVar2 + 0x10) + 0x43);
  }
  if (*(char *)(lVar4 + 8) == '\0') {
    if (((uVar11 & 1) != 0) || ((uVar11 & 0x20) != 0)) {
      (**(code **)(NvStorOsCBT + 0x150))(*param_1,1,0,local_98);
      uVar9 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x38);
      uVar10 = 0;
      if (*(int *)(*param_1 + 0x2504) != 0) {
        do {
          lVar1 = lVar3 + uVar10 * 8;
          lVar5 = *(longlong *)(lVar1 + 0x240);
          if ((lVar5 != 0) && ((uVar9 >> ((uint)uVar10 & 0x1f) & 1) == 0)) {
            lVar6 = *(longlong *)(lVar2 + 0x18);
            *(uint *)(lVar5 + 0xc0) = *(uint *)(lVar5 + 0xc0) | 0x1400;
            if (uVar13 == 0) {
              uVar7 = *(ulonglong *)(*(longlong *)(lVar5 + 0x10) + 0x890);
              if (((uVar7 & 0x20) != 0) && ((uVar7 >> 0x14 & 1) != 0)) {
                *(undefined4 *)(lVar5 + 0x28) = *(undefined4 *)(uVar10 * 0x20 + lVar6 + 4);
              }
              (**(code **)(*(longlong *)(lVar1 + 0x240) + 0x98))();
            }
            else {
              *(undefined1 *)(lVar5 + 0x18) = local_res10;
              (**(code **)(*(longlong *)(lVar1 + 0x240) + 0xa0))(lVar5,0x80000003);
            }
          }
          uVar12 = (uint)uVar10 + 1;
          uVar10 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(*param_1 + 0x2504));
      }
      NvStorReqQueueDispatch(lVar3 + 0x1a8);
      (**(code **)(NvStorOsCBT + 0x158))(*param_1,1,0,local_98);
    }
    if (*(char *)(lVar4 + 8) != '\0') goto LAB_0001ef6b;
  }
  else {
LAB_0001ef6b:
    if (((uVar11 & 8) != 0) || ((*(uint *)(lVar3 + 0x890) >> 0x1b & 1) != 0)) {
      (**(code **)(NvStorOsCBT + 0x150))(*param_1,1,0,local_98);
      uVar11 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x34);
      uVar9 = 0;
      if (*(int *)(*param_1 + 0x2504) != 0) {
        do {
          lVar4 = *(longlong *)(lVar3 + 0x240 + (ulonglong)uVar9 * 8);
          if ((lVar4 != 0) && ((uVar11 >> (uVar9 & 0x1f) & 1) == 0)) {
            *(uint *)(lVar4 + 0xc0) = *(uint *)(lVar4 + 0xc0) | 0x1400;
            lVar1 = *(longlong *)(lVar3 + 0x240 + (ulonglong)uVar9 * 8);
            if (uVar13 == 0) {
              (**(code **)(lVar1 + 0x98))();
            }
            else {
              (**(code **)(lVar1 + 0xa0))(lVar4,0x80000003);
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint *)(*param_1 + 0x2504));
      }
      *(ulonglong *)(lVar3 + 0x890) = *(ulonglong *)(lVar3 + 0x890) & 0xfffffffff7ffffff;
      NvStorReqQueueDispatch(lVar3 + 0x1a8);
      (**(code **)(NvStorOsCBT + 0x158))(*param_1,1,0,local_98);
    }
  }
  if (uVar13 != 0) {
    uVar10 = (**(code **)(NvStorOsCBT + 0x30))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x20);
    if (((uVar10 & 0x88) != 0) && (cVar8 = (**(code **)(*param_1 + 0x27c8))(param_1), cVar8 != '\0')
       ) {
      FUN_0001fbe4(*param_1,*(longlong *)(lVar2 + 0x28) + 0x20);
    }
    FUN_00020754(param_1);
    NvStorAhciStartCommandListProcessing(param_1);
  }
LAB_0001f090:
  (**(code **)(NvStorOsCBT + 0x158))(*param_1,0,(char)param_1[0x1b],local_58);
  return;
}



===== NvStorAhciResetSATAPhy @ 0001f0cc =====

uint NvStorAhciResetSATAPhy(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  lVar1 = param_1[0x1e];
  uVar8 = 0;
  bVar3 = false;
  NvStorAhciDisableInterrupts(param_1);
  uVar5 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  lVar2 = param_1[0x1e];
  uVar6 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18,uVar6 & 0xfffffffe);
  uVar6 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18);
  if (((uVar6 & 0x10) != 0) || ((uVar6 >> 0xe & 1) != 0)) {
    (**(code **)(NvStorOsCBT + 0xa0))
              (*param_1,*(longlong *)(lVar2 + 0x28) + 0x18,uVar6 & 0xffffffef);
  }
  while( true ) {
    uVar6 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar6 | 1);
    (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    (**(code **)(NvStorOsCBT + 0x180))(1000);
    (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    uVar9 = FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x28,0,3,1000);
    if (((byte)uVar9 & 3) == 3) {
      lVar2 = param_1[0x1e];
      uVar6 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18);
      (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18,uVar6 | 0x10);
      (**(code **)(NvStorOsCBT + 0x180))(500);
      FUN_0001fc4c(*param_1,*(longlong *)(lVar2 + 0x28) + 0x18,0x8000,0,1000000);
      bVar4 = FUN_0001fbe4(*param_1,*(longlong *)(lVar1 + 0x28) + 0x20);
      if ((bVar4 & 0x88) == 0) goto LAB_0001f33f;
    }
    lVar2 = NvStorOsCBT;
    if (*(char *)((longlong)param_1 + 0x124) == '\0') break;
    *(undefined1 *)((longlong)param_1 + 0x124) = 0;
    uVar6 = (**(code **)(lVar2 + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
    (**(code **)(NvStorOsCBT + 0xa0))
              (*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar6 & 0xfffff3ff | 0x300);
    if (bVar3) break;
    bVar3 = true;
  }
  uVar8 = 0x80000003;
LAB_0001f33f:
  uVar7 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,uVar7);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  if ((uVar5 & 1) != 0) {
    uVar8 = NvStorAhciStartCommandListProcessing(param_1);
  }
  NvStorAhciEnableInterrupts(param_1);
  return uVar8;
}



===== NvStorAhciPortSATALinkRebuild @ 0001f3b8 =====

undefined8 NvStorAhciPortSATALinkRebuild(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  lVar1 = param_1[0x1e];
  NvStorAhciDisableInterrupts(param_1);
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar2 & 0xfffffffe);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar3 | 1);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0x180))(0x3de);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar3 & 0xfffffffe);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0x180))(900);
  uVar4 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,uVar4);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar3 | uVar2 & 1);
  NvStorAhciEnableInterrupts(param_1);
  return 0;
}



===== NvStorAhciExecuteTaskFile @ 0001f558 =====

void NvStorAhciExecuteTaskFile(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  if ((((param_1 != (longlong *)0x0) && ((longlong *)*param_1 != (longlong *)0x0)) &&
      (lVar2 = *(longlong *)*param_1, lVar2 != 0)) && (0 < *(int *)(lVar2 + 0x28dc))) {
    iVar3 = 0;
    lVar4 = 0;
    do {
      iVar1 = FUN_000200b8(param_1,*(undefined1 *)(lVar4 + 0x28e6 + lVar2),
                           *(undefined1 *)(lVar4 + 0x28e0 + lVar2),
                           *(undefined1 *)(lVar4 + 0x28e1 + lVar2),*(char *)(lVar4 + 0x28e5 + lVar2)
                          );
      if (iVar1 < 0) {
        return;
      }
      iVar3 = iVar3 + 1;
      lVar4 = lVar4 + 7;
      lVar2 = *(longlong *)*param_1;
    } while (iVar3 < *(int *)(lVar2 + 0x28dc));
  }
  return;
}



===== NvStorAhciEnableAhciMode @ 0001f5e4 =====

undefined8 NvStorAhciEnableAhciMode(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
  if ((uVar2 & 0x80000000) == 0) {
    uVar3 = uVar2 | 0x80000000;
    if ((*(uint *)(param_1 + 0x25f0) & 0x200000) == 0) {
      uVar3 = uVar2 | 0x80000001;
    }
    uVar2 = uVar3;
    (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 4,uVar2);
    lVar4 = 0x6e;
    do {
      (**(code **)(NvStorOsCBT + 0x180))(100);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar3 = 0;
    if ((*(uint *)(param_1 + 0x25f0) & 0x200000) == 0) {
      do {
        uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
        if ((uVar2 & 1) == 0) break;
        (**(code **)(NvStorOsCBT + 0x180))(0x14);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 500);
      if ((uVar2 & 1) != 0) {
        return 0x80000003;
      }
    }
  }
  if ((uVar2 & 0x80000000) == 0) {
    (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 4,uVar2 | 0x80000000);
    (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
    (**(code **)(NvStorOsCBT + 0x180))(0x14);
  }
  return 0;
}



===== NvStorAhciEnableInterruptsGlobal @ 0001f720 =====

void NvStorAhciEnableInterruptsGlobal(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
  (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 4,uVar2 | 2);
  (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
                    /* WARNING: Could not recover jumptable at 0x0001f78c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(NvStorOsCBT + 0x180))(0x14);
  return;
}



===== NvStorAhciDisableInterruptsGlobal @ 0001f794 =====

void NvStorAhciDisableInterruptsGlobal(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x28c8);
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
  (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 4,uVar2 & 0xfffffffd);
  (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 4);
                    /* WARNING: Could not recover jumptable at 0x0001f800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(NvStorOsCBT + 0x180))(0x14);
  return;
}



===== NvStorAhciEnableInterrupts @ 0001f808 =====

void NvStorAhciEnableInterrupts(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  char local_res8 [8];
  
  lVar1 = param_1[0x1e];
  NvCfgElementGet(*(longlong *)(*param_1 + 0x2820),(longlong *)param_1[0x20],'\x17',
                  (undefined8 *)local_res8,1);
  uVar2 = ~-(uint)(local_res8[0] != '\0') & 9;
  uVar3 = uVar2 | 0x78400076;
  if ((*(byte *)((longlong)param_1 + 0x124) & 0xcf) == 0) {
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffffbf;
  }
  else {
    uVar3 = uVar2 | 0x78000036;
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x40;
  }
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x14,uVar3);
                    /* WARNING: Could not recover jumptable at 0x0001f8ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x14);
  return;
}



===== NvStorAhciDisableInterrupts @ 0001f8b4 =====

void NvStorAhciDisableInterrupts(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = param_1[0x1e];
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x14,0);
                    /* WARNING: Could not recover jumptable at 0x0001f8ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x14);
  return;
}



===== NvStorAhciStartCommandListProcessing @ 0001f904 =====

uint NvStorAhciStartCommandListProcessing(undefined8 *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = param_1[0x1e];
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  uVar2 = FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,0,0x8000,1000000);
  return ~-(uint)((uVar2 & 0x8000) != 0) & 0x80000003;
}



===== NvStorAhciStopCommandListProcessing @ 0001f988 =====

uint NvStorAhciStopCommandListProcessing(undefined8 *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = param_1[0x1e];
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar2 & 0xfffffffe);
  uVar3 = FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,0x8000,0,1000000);
  return -(uint)((uVar3 & 0x8000) != 0) & 0x80000003;
}



===== NvStorAhciWaitForRequestCompletion @ 0001fa08 =====

undefined8 NvStorAhciWaitForRequestCompletion(longlong *param_1,undefined8 param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar5 = 0;
  lVar1 = *(longlong *)(*param_1 + 0xf0);
  uVar6 = 0;
  do {
    uVar2 = (**(code **)(NvStorOsCBT + 0x40))
                      (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x10);
    uVar3 = (**(code **)(NvStorOsCBT + 0x40))
                      (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
    if (((uVar2 & 0xb) != 0) || ((uVar3 & 1) == 0)) break;
    (**(code **)(NvStorOsCBT + 0x180))(1);
    uVar5 = uVar5 + 1;
  } while (uVar5 < param_3);
  if (((uVar3 & 1) != 0) && (((uVar2 & 0xb) == 0 || ((uVar2 & 0x78000000) != 0)))) {
    uVar6 = 0x80000003;
  }
  uVar4 = (**(code **)(NvStorOsCBT + 0x40))
                    (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,uVar4);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x10,uVar2);
  (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x10);
  return uVar6;
}



===== NvStorAhciSendAtaRequestNoData @ 0001fb54 =====

void NvStorAhciSendAtaRequestNoData(longlong *param_1)

{
  undefined2 *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*param_1 + 0xf0);
  puVar1 = *(undefined2 **)(lVar2 + 0x20);
  **(undefined8 **)(lVar2 + 0x18) = 5;
  (**(code **)(NvStorOsCBT + 0x110))(puVar1,0x14);
  *puVar1 = 0x8027;
  *(undefined1 *)(puVar1 + 1) = 0xe0;
  NvStorAhciPreIssueNonIntCommand((undefined8 *)*param_1);
  lVar2 = *(longlong *)(lVar2 + 0x28) + 0x38;
  (**(code **)(NvStorOsCBT + 0xa0))(*(undefined8 *)*param_1,lVar2,1);
  NvStorAhciWaitForRequestCompletion(param_1,lVar2,10000000);
  return;
}



===== FUN_0001fbe4 @ 0001fbe4 =====

byte FUN_0001fbe4(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    bVar1 = (**(code **)(NvStorOsCBT + 0x30))(param_1,param_2);
    if ((bVar1 & 0x88) == 0) {
      return bVar1;
    }
    (**(code **)(NvStorOsCBT + 0x180))(1);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10000000);
  return bVar1;
}



===== FUN_0001fc4c @ 0001fc4c =====

ulonglong FUN_0001fc4c(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,uint param_5)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = (**(code **)(NvStorOsCBT + 0x40))(param_1,param_2);
    if (((uint)uVar1 & (param_3 | param_4)) == param_4) {
      return uVar1;
    }
    (**(code **)(NvStorOsCBT + 0x180))(1);
    uVar2 = uVar2 + 1;
  } while (uVar2 < param_5);
  return uVar1 & 0xffffffff;
}



===== FUN_0001fcc4 @ 0001fcc4 =====

uint FUN_0001fcc4(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  char local_res8 [8];
  uint local_res10 [2];
  
  plVar1 = (longlong *)*param_1;
  lVar2 = plVar1[0x1e];
  puVar3 = (undefined8 *)param_1[0x110];
  plVar4 = *(longlong **)(*plVar1 + 0x28c8);
  puVar5 = *(undefined2 **)(lVar2 + 0x20);
  puVar6 = *(undefined4 **)(lVar2 + 0x18);
  NvStorAhciDisableInterrupts(plVar1);
  lVar10 = NvStorOsCBT;
  puVar6[1] = 0;
  *puVar6 = 0x10005;
  (**(code **)(lVar10 + 0x110))(puVar5,0x14);
  lVar10 = NvStorOsCBT;
  *puVar5 = 0x8027;
  iVar7 = (**(code **)(lVar10 + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x24);
  if (iVar7 == 0x101) {
LAB_0001fdcb:
    *(undefined1 *)(puVar5 + 1) = 0xec;
  }
  else {
    if (iVar7 != -0x14ebfeff) {
      iVar7 = CONCAT31(*(undefined3 *)(*(longlong *)(lVar2 + 0x10) + 0x44),
                       *(undefined1 *)(*(longlong *)(lVar2 + 0x10) + 0x4c));
      if (iVar7 == 0x101) goto LAB_0001fdcb;
      if (iVar7 != -0x14ebfeff) {
        uVar8 = NvStorAhciResetSATAPhy((longlong *)*param_1);
        if ((int)uVar8 < 0) goto LAB_0001ff51;
        iVar7 = CONCAT31(*(undefined3 *)(*(longlong *)(lVar2 + 0x10) + 0x44),
                         *(undefined1 *)(*(longlong *)(lVar2 + 0x10) + 0x4c));
        if ((iVar7 == 0x101) || (iVar7 != -0x14ebfeff)) goto LAB_0001fdcb;
      }
    }
    *(undefined1 *)(puVar5 + 1) = 0xa1;
  }
  local_res10[0] = 0x200;
  lVar10 = (**(code **)(NvStorOsCBT + 0x1b8))(*(undefined8 *)*param_1,0,*puVar3,local_res10);
  if ((lVar10 == 0) || (local_res10[0] < 0x200)) {
    uVar8 = 0x80000011;
  }
  else {
    *(int *)(puVar5 + 0x40) = (int)lVar10;
    *(undefined4 *)(puVar5 + 0x46) = 0x1ff;
    *(int *)(puVar5 + 0x42) = (int)((ulonglong)lVar10 >> 0x20);
    NvStorAhciPreIssueNonIntCommand((undefined8 *)*param_1);
    lVar10 = *(longlong *)(lVar2 + 0x28) + 0x38;
    (**(code **)(NvStorOsCBT + 0xa0))(*(undefined8 *)*param_1,lVar10,1);
    uVar11 = NvStorAhciWaitForRequestCompletion(param_1,lVar10,10000000);
    uVar8 = (uint)uVar11;
    if (((uVar11 & 0x80000000) != 0) && (*(char *)(puVar5 + 1) == -0x14)) {
      NvStorAhciStopCommandListProcessing((undefined8 *)*param_1);
      NvStorAhciStartCommandListProcessing((undefined8 *)*param_1);
      *(undefined1 *)(puVar5 + 1) = 0xa1;
      NvStorAhciPreIssueNonIntCommand((undefined8 *)*param_1);
      lVar10 = *(longlong *)(lVar2 + 0x28) + 0x38;
      (**(code **)(NvStorOsCBT + 0xa0))(*(undefined8 *)*param_1,lVar10,1);
      uVar11 = NvStorAhciWaitForRequestCompletion(param_1,lVar10,10000000);
      uVar8 = (uint)uVar11;
      if ((uVar11 & 0x80000000) != 0) {
        NvStorAhciStopCommandListProcessing((undefined8 *)*param_1);
        NvStorAhciStartCommandListProcessing((undefined8 *)*param_1);
        goto LAB_0001ff51;
      }
    }
    uVar9 = (**(code **)(NvStorOsCBT + 0x40))
                      (*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x18);
    if (*(char *)(puVar5 + 1) == -0x5f) {
      param_1[0x112] = param_1[0x112] | 0x20;
      uVar9 = uVar9 | 0x1000000;
      if ((*(uint *)(*(longlong *)*param_1 + 0x2818) & 0x40) != 0) {
        lVar10 = 900;
        do {
          (**(code **)(NvStorOsCBT + 0x180))(1000);
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
    }
    else {
      uVar9 = uVar9 & 0xfeffffff;
    }
    (**(code **)(NvStorOsCBT + 0xa0))
              (*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x18,uVar9);
  }
LAB_0001ff51:
  NvCfgElementGet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                  (longlong *)((longlong *)*param_1)[0x20],'\x17',(undefined8 *)local_res8,1);
  (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x10);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x10,
             ~-(uint)(local_res8[0] != '\0') & 9 | 0x78400076);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*plVar4 + 8,
             1 << (*(byte *)((undefined8 *)*param_1 + 0x1b) & 0x1f));
  NvStorAhciEnableInterrupts((longlong *)*param_1);
  return uVar8;
}



===== FUN_0002000c @ 0002000c =====

void FUN_0002000c(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  char cVar6;
  
  plVar1 = (longlong *)param_1[0x110];
  iVar4 = FUN_000200b8(param_1,0xef,3,((*(byte *)(*plVar1 + 0x80) & 2) != 0) + '\v','\0');
  if (iVar4 < 0) {
    return;
  }
  lVar2 = *plVar1;
  bVar5 = *(byte *)(lVar2 + 0xb0);
  if ((bVar5 & 0x7f) == 0) {
    bVar5 = *(byte *)(lVar2 + 0x7e);
    if ((bVar5 & 7) == 0) {
      cVar6 = '\0';
      goto LAB_0002008e;
    }
    cVar6 = ' ';
    bVar3 = 4;
    bVar5 = bVar5 & 7;
  }
  else {
    cVar6 = '@';
    bVar5 = bVar5 & 0x7f;
    bVar3 = 0x40;
  }
  for (; (bVar3 & bVar5) == 0; bVar3 = bVar3 >> 1) {
  }
  if (bVar3 != 0) {
    for (; (bVar3 & 1) == 0; bVar3 = bVar3 >> 1) {
      cVar6 = cVar6 + '\x01';
    }
  }
LAB_0002008e:
  iVar4 = FUN_000200b8(param_1,0xef,3,cVar6,'\0');
  if (-1 < iVar4) {
    param_1[0x112] = param_1[0x112] | 0x80;
  }
  return;
}



===== FUN_000200b8 @ 000200b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_000200b8(longlong *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 char param_5)

{
  undefined1 auStack_68 [32];
  undefined2 local_48;
  undefined1 local_46;
  undefined1 local_45;
  char local_41;
  undefined1 local_3c;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  (**(code **)(NvStorOsCBT + 0x110))(&local_48,0x14);
  if (param_5 != '\0') {
    local_41 = param_5;
  }
  local_48 = 0x8027;
  local_46 = param_2;
  local_45 = param_3;
  local_3c = param_4;
  FUN_000201b0(param_1,&local_48);
  return;
}



===== NvStorAhciFlushCache @ 00020144 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorAhciFlushCache(longlong *param_1)

{
  undefined1 auStack_48 [32];
  undefined2 local_28;
  char local_26;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  (**(code **)(NvStorOsCBT + 0x110))(&local_28);
  local_28 = 0x8027;
  local_26 = (-((*(byte *)(param_1 + 0x112) & 0x10) != 0) & 3U) - 0x19;
  FUN_000201b0(param_1,&local_28);
  return;
}



===== FUN_000201b0 @ 000201b0 =====

ulonglong FUN_000201b0(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  char local_res8 [8];
  
  plVar1 = (longlong *)*param_1;
  lVar2 = plVar1[0x1e];
  plVar3 = *(longlong **)(*plVar1 + 0x28c8);
  uVar4 = *(undefined8 *)(lVar2 + 0x20);
  puVar5 = *(undefined8 **)(lVar2 + 0x18);
  NvStorAhciDisableInterrupts(plVar1);
  lVar7 = NvStorOsCBT;
  *puVar5 = 5;
  (**(code **)(lVar7 + 0x118))(uVar4,param_2,0x14);
  NvStorAhciPreIssueNonIntCommand((undefined8 *)*param_1);
  lVar7 = *(longlong *)(lVar2 + 0x28) + 0x38;
  (**(code **)(NvStorOsCBT + 0xa0))(*(undefined8 *)*param_1,lVar7,1);
  uVar6 = NvStorAhciWaitForRequestCompletion(param_1,lVar7,10000000);
  if ((int)uVar6 < 0) {
    NvStorAhciStopCommandListProcessing((undefined8 *)*param_1);
    NvStorAhciStartCommandListProcessing((undefined8 *)*param_1);
  }
  NvCfgElementGet(*(longlong *)(*(longlong *)*param_1 + 0x2820),
                  (longlong *)((longlong *)*param_1)[0x20],'\x17',(undefined8 *)local_res8,1);
  (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x10);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*(longlong *)(lVar2 + 0x28) + 0x10,
             ~-(uint)(local_res8[0] != '\0') & 9 | 0x78400076);
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*plVar3 + 8,
             1 << (*(byte *)((undefined8 *)*param_1 + 0x1b) & 0x1f));
  NvStorAhciEnableInterrupts((longlong *)*param_1);
  return uVar6 & 0xffffffff;
}



===== NvStorAhciPortDetectDevicePresense @ 00020318 =====

bool NvStorAhciPortDetectDevicePresense(undefined8 *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = param_1[0x1e];
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x28);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  if ((uVar3 & 0xf0000000) == 0) {
    uVar2 = uVar2 & 0xf00;
  }
  else {
    uVar2 = uVar2 & 0xf0;
  }
  return uVar2 != 0;
}



===== FUN_00020398 @ 00020398 =====

uint FUN_00020398(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  uint3 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  longlong *plVar9;
  byte bVar10;
  char local_res8 [8];
  undefined2 local_res10 [4];
  
  plVar1 = (longlong *)param_1[0x519];
  uVar4 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 0x14);
  (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 0x14,uVar4 & 0xfffffffe);
  uVar4 = NvCfgElementGet(param_1[0x504],(longlong *)param_1[0x506],'\x12',(undefined8 *)local_res10
                          ,2);
  if (((uVar4 & 0x80000000) == 0) &&
     (uVar4 = NvCfgElementGet(param_1[0x504],(longlong *)param_1[0x506],'\x13',
                              (undefined8 *)local_res8,1), (uVar4 & 0x80000000) == 0)) {
    uVar3 = CONCAT21(local_res10[0],local_res8[0]);
    uVar5 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*plVar1 + 0xc);
    uVar6 = 0;
    plVar9 = param_1;
    do {
      if ((uVar5 >> (uVar6 & 0x1f) & 1) != 0) {
        local_res8[0] = '\0';
        NvCfgElementGet(param_1[0x504],(longlong *)plVar9[0x20],'\x17',(undefined8 *)local_res8,1);
        if (local_res8[0] == '\0') {
          FUN_00020804(plVar9);
        }
        else {
          FUN_00020754(plVar9);
        }
      }
      bVar10 = (char)uVar6 + 1;
      uVar6 = (uint)bVar10;
      plVar9 = plVar9 + 0x25;
    } while (bVar10 < 0x20);
    (**(code **)(NvStorOsCBT + 0xa0))(param_1,*plVar1 + 0x14,(uint)uVar3 << 8 | 1);
    bVar10 = 0;
    plVar9 = param_1 + 1;
    do {
      uVar5 = 1 << (bVar10 & 0x1f);
      if (((*(uint *)(*plVar1 + 0xc) & uVar5) != 0) && ((*(uint *)(*plVar1 + 0x18) & uVar5) != 0)) {
        lVar2 = plVar9[0x1d];
        uVar5 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar2 + 0x28) + 0x38);
        uVar6 = (**(code **)(NvStorOsCBT + 0x40))(param_1,*(longlong *)(lVar2 + 0x28) + 0x34);
        bVar8 = 0;
        if (*(int *)((longlong)param_1 + 0x2504) != 0) {
          do {
            if ((*(longlong *)(*plVar9 + 0x240 + (ulonglong)bVar8 * 8) != 0) &&
               ((uVar7 = 1 << (bVar8 & 0x1f), (uVar5 & uVar7) == 0 || ((uVar6 & uVar7) == 0)))) {
              (**(code **)(NvStorOsCBT + 400))(plVar9 + -1,FUN_000205cc);
            }
            bVar8 = bVar8 + 1;
          } while ((uint)bVar8 < *(uint *)((longlong)param_1 + 0x2504));
        }
      }
      bVar10 = bVar10 + 1;
      plVar9 = plVar9 + 0x25;
    } while (bVar10 < 0x20);
  }
  return uVar4;
}



===== FUN_000205cc @ 000205cc =====

void FUN_000205cc(longlong *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 local_28 [32];
  
  lVar3 = param_1[1];
  lVar4 = param_1[0x1e];
  if (*(char *)(*(longlong *)(lVar3 + 0x880) + 8) == '\0') {
    (**(code **)(NvStorOsCBT + 0x150))();
    uVar8 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x38);
    uVar10 = 0;
    if (*(int *)(*param_1 + 0x2504) != 0) {
      do {
        lVar2 = lVar3 + uVar10 * 8;
        lVar5 = *(longlong *)(lVar2 + 0x240);
        if ((lVar5 != 0) && ((uVar8 >> ((uint)uVar10 & 0x1f) & 1) == 0)) {
          lVar6 = *(longlong *)(lVar4 + 0x18);
          *(uint *)(lVar5 + 0xc0) = *(uint *)(lVar5 + 0xc0) | 0x1400;
          uVar7 = *(ulonglong *)(*(longlong *)(lVar5 + 0x10) + 0x890);
          if (((uVar7 & 0x20) != 0) && ((uVar7 >> 0x14 & 1) != 0)) {
            *(undefined4 *)(lVar5 + 0x28) = *(undefined4 *)(uVar10 * 0x20 + lVar6 + 4);
          }
          (**(code **)(*(longlong *)(lVar2 + 0x240) + 0x98))();
        }
        uVar9 = (uint)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(*param_1 + 0x2504));
    }
  }
  else {
    (**(code **)(NvStorOsCBT + 0x150))(*param_1,1,0,local_28);
    uVar8 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar4 + 0x28) + 0x34);
    uVar10 = 0;
    if (*(int *)(*param_1 + 0x2504) != 0) {
      do {
        lVar4 = *(longlong *)(lVar3 + 0x240 + uVar10 * 8);
        if ((lVar4 != 0) && ((uVar8 >> ((uint)uVar10 & 0x1f) & 1) == 0)) {
          puVar1 = (uint *)(lVar4 + 0xc0);
          *puVar1 = *puVar1 | 0x1400;
          (**(code **)(*(longlong *)(lVar3 + 0x240 + uVar10 * 8) + 0x98))();
        }
        uVar9 = (uint)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(*param_1 + 0x2504));
    }
  }
  NvStorReqQueueDispatch(lVar3 + 0x1a8);
  (**(code **)(NvStorOsCBT + 0x158))(*param_1,1,0,local_28);
  return;
}



===== FUN_00020754 @ 00020754 =====

void FUN_00020754(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  char local_res8 [8];
  
  lVar1 = *param_1;
  plVar2 = *(longlong **)(lVar1 + 0x28c8);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(lVar1,*plVar2 + 0x18);
  if ((uVar3 >> (*(byte *)(param_1 + 0x1b) & 0x1f) & 1) == 0) {
    uVar4 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_1[0x20],'\x17',
                            (undefined8 *)local_res8,1);
    if ((-1 < (int)uVar4) && (local_res8[0] != '\0')) {
      (**(code **)(NvStorOsCBT + 0xa0))
                (lVar1,*plVar2 + 0x18,1 << (*(byte *)(param_1 + 0x1b) & 0x1f) | uVar3);
      NvStorAhciEnableInterrupts(param_1);
    }
  }
  return;
}



===== FUN_00020804 @ 00020804 =====

void FUN_00020804(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_res8;
  
  lVar1 = *param_1;
  plVar2 = *(longlong **)(lVar1 + 0x28c8);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(lVar1,*plVar2 + 0x18);
  if ((uVar3 >> (*(byte *)(param_1 + 0x1b) & 0x1f) & 1) != 0) {
    uVar4 = NvCfgElementGet(*(longlong *)(lVar1 + 0x2820),(longlong *)param_1[0x20],'\x17',
                            &local_res8,1);
    if (-1 < (int)uVar4) {
      (**(code **)(NvStorOsCBT + 0xa0))
                (lVar1,*plVar2 + 0x18,~(1 << (*(byte *)(param_1 + 0x1b) & 0x1f)) & uVar3);
      NvStorAhciEnableInterrupts(param_1);
    }
  }
  return;
}



===== NvStorAhciDeviceBuildInquiryPage @ 000208b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorAhciDeviceBuildInquiryPage(longlong param_1)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined1 auStack_58 [32];
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pcVar1 = (char *)**(undefined8 **)(param_1 + 0x880);
  bVar3 = 0;
  (**(code **)(NvStorOsCBT + 0x110))(param_1 + 0x30,0x60);
  bVar2 = 0;
  do {
    if (*(char *)((ulonglong)bVar2 + 0x2130 + param_1) != (&s_NVIDIA)[bVar2]) {
      *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) & 0xffff7fffffffffff;
      goto LAB_00020940;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 6);
  bVar3 = 1;
  *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) | 0x800000000000;
LAB_00020940:
  NvStorScsiBuildInquiryPage(pcVar1,(byte *)(param_1 + 0x30),(longlong)local_38,bVar3);
  return;
}



===== FUN_00020978 @ 00020978 =====

undefined4 FUN_00020978(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  
  lVar1 = param_1[0x1e];
  NvStorAhciDisableInterrupts(param_1);
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar2 & 0xfffffffe);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c,uVar3 | 1);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0x180))(1000);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x2c);
  uVar5 = FUN_0001fc4c(*param_1,*(longlong *)(lVar1 + 0x28) + 0x28,0,3,1000);
  uVar6 = 0;
  if (((byte)uVar5 & 3) != 3) {
    uVar6 = 0x80000003;
  }
  uVar4 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30,uVar4);
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x30);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18);
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x18,uVar3 | uVar2 & 1);
  NvStorAhciEnableInterrupts(param_1);
  return uVar6;
}



===== NvStorAhciPreIssueNonIntCommand @ 00020b3c =====

void NvStorAhciPreIssueNonIntCommand(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = param_1[0x1e];
  (**(code **)(NvStorOsCBT + 0xa0))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x10,0xb);
                    /* WARNING: Could not recover jumptable at 0x00020b8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(NvStorOsCBT + 0x40))(*param_1,*(longlong *)(lVar1 + 0x28) + 0x10);
  return;
}



===== NvStorAhciScsi @ 00020b98 =====

int NvStorAhciScsi(longlong param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar7;
  uint uVar6;
  int iVar8;
  bool bVar9;
  
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x1c);
  iVar4 = -0x7ffffff9;
  *(undefined8 *)(param_1 + 0xa0) = puVar2[0x6f];
  *(undefined8 *)(param_1 + 0x98) = puVar2[0x6e];
  uVar5 = puVar2[0x70];
  *(undefined1 *)(param_1 + 0x8d) = 0;
  *(undefined8 *)(param_1 + 0xa8) = uVar5;
  uVar6 = *(uint *)(param_1 + 0xc0);
  if (((uVar6 >> 0x12 & 1) != 0) && ((uVar6 >> 0x15 & 1) != 0)) {
    *(byte *)(*(longlong *)(param_1 + 200) + 2) = ~(byte)(uVar6 >> 0x11) & 1 | 0xe0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(code **)(param_1 + 0xb8) = FUN_000223c8;
    *(undefined4 *)(param_1 + 0x88) = 1;
    return 1;
  }
  if ((puVar2[0x112] & 0x200000000) != 0) {
    puVar2[0x112] = puVar2[0x112] & 0xfffffffdffffffff;
  }
  if (((*(byte *)(puVar2 + 0x112) & 0x20) != 0) && (*(char *)(param_1 + 0x40) != -0x60)) {
    uVar5 = FUN_00021e48(param_1);
    iVar4 = (int)uVar5;
    goto LAB_00020ea6;
  }
  bVar1 = *(byte *)(param_1 + 0x40);
  uVar6 = (uint)bVar1;
  uVar7 = (uint)bVar1;
  if (0x2f < bVar1) {
    if (uVar7 < 0x90) {
      if (uVar7 == 0x8f) goto LAB_00020de3;
      if (uVar6 == 0x35) {
        uVar5 = FUN_000219e0(param_1);
        iVar4 = (int)uVar5;
        goto LAB_00020ea6;
      }
      if (uVar6 == 0x55) {
LAB_00020dc9:
        uVar5 = FUN_00021430(param_1);
        iVar4 = (int)uVar5;
        goto LAB_00020ea6;
      }
      if (uVar6 == 0x5a) goto LAB_00020dbc;
      iVar8 = uVar6 - 0x88;
    }
    else {
      if (uVar7 == 0x9e) {
        uVar5 = FUN_0001bcd8(param_1);
        iVar4 = (int)uVar5;
        goto LAB_00020ea6;
      }
      if (uVar7 == 0xa0) {
        uVar5 = FUN_0001bb68(param_1);
        iVar4 = (int)uVar5;
        goto LAB_00020ea6;
      }
      iVar8 = uVar7 - 0xa8;
    }
    if (iVar8 != 0) {
      bVar9 = iVar8 == 2;
LAB_00020e0d:
      if (!bVar9) {
LAB_00020e0f:
        puVar3 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
        *(undefined4 *)(param_1 + 0x88) = 0x80000007;
        *(undefined1 *)(param_1 + 0x8c) = 2;
        if (puVar3 != (undefined1 *)0x0) {
          (**(code **)(NvStorOsCBT + 0x110))(puVar3,0x12);
          *puVar3 = 0xf0;
          puVar3[7] = 0xb;
          *(undefined2 *)(puVar3 + 0xc) = 0x20;
          puVar3[2] = puVar3[2] & 0xf5 | 5;
          *(undefined1 *)(param_1 + 0x78) = 0x12;
          *(undefined1 *)(param_1 + 0x8d) = 1;
        }
        goto LAB_00020ea6;
      }
    }
    if (((*(uint *)(*(longlong *)*puVar2 + 0x2818) & 8) != 0) &&
       ((*(byte *)(param_1 + 0x41) & 8) != 0)) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x8000;
    }
    uVar5 = FUN_00021a6c(param_1);
    iVar4 = (int)uVar5;
    goto LAB_00020ea6;
  }
  if (bVar1 == 0x2f) {
LAB_00020de3:
    uVar5 = FUN_00021cac(param_1);
    iVar4 = (int)uVar5;
    goto LAB_00020ea6;
  }
  if (uVar6 != 0x1a && 0x19 < bVar1) {
    if (uVar7 == 0x1b) {
      uVar5 = FUN_0002189c(param_1);
      iVar4 = (int)uVar5;
      goto LAB_00020ea6;
    }
    if (uVar7 == 0x1e) {
      if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
        *(byte *)(*(longlong *)(param_1 + 200) + 2) = ~*(byte *)(param_1 + 0x44) & 1 | 0xde;
        goto LAB_00020d71;
      }
      *(undefined4 *)(param_1 + 0x88) = 0x80000007;
      goto LAB_00020cef;
    }
    if (uVar6 == 0x25) {
      uVar5 = FUN_0001bc24(param_1);
      iVar4 = (int)uVar5;
      goto LAB_00020ea6;
    }
    bVar9 = (bVar1 - 0x28 & 0xfffffffd) == 0;
    goto LAB_00020e0d;
  }
  if (uVar6 == 0x1a) {
LAB_00020dbc:
    uVar5 = FUN_000215e4(param_1);
    iVar4 = (int)uVar5;
    goto LAB_00020ea6;
  }
  if (uVar6 == 0) {
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 200) + 2) = 0xda;
LAB_00020d71:
      *(undefined4 *)(param_1 + 0xc4) = 0;
      iVar4 = 1;
      *(code **)(param_1 + 0xb8) = FUN_000223c8;
      goto LAB_00020ea6;
    }
    *(undefined4 *)(param_1 + 0x88) = 0;
LAB_00020cef:
    *(undefined1 *)(param_1 + 0x8c) = 0;
  }
  else {
    if (uVar7 == 3) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined1 *)(param_1 + 0x78) = 0x12;
      goto LAB_00020cef;
    }
    if (uVar7 == 0x12) {
      uVar5 = NvStorScsiInquiry(param_1,**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x880));
      iVar4 = (int)uVar5;
      goto LAB_00020ea6;
    }
    if (uVar7 == 0x15) goto LAB_00020dc9;
    if (1 < bVar1 - 0x16) goto LAB_00020e0f;
  }
  iVar4 = 0;
LAB_00020ea6:
  *(int *)(param_1 + 0x88) = iVar4;
  if (iVar4 != 1) {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x800;
  }
  return iVar4;
}



===== NvStorAhciDeviceReset @ 00020ecc =====

uint NvStorAhciDeviceReset(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = NvStorAhciResetSATAPhy((longlong *)*param_1);
  lVar2 = *(longlong *)*param_1;
  if (((*(uint *)(lVar2 + 0x2818) & 0x200) != 0) && ((*(byte *)(param_1 + 0x112) & 0x20) == 0)) {
    uVar1 = NvStorAhciExecuteTaskFile(param_1);
  }
  if (-1 < (char)*(undefined4 *)(*(longlong *)*param_1 + 0x2818)) {
    NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000015,lVar2,0);
    *(undefined4 *)((longlong *)*param_1)[0x1e] = *(undefined4 *)(*(longlong *)*param_1 + 0x2504);
  }
  return uVar1;
}



===== NvStorAhciAtaSuccess @ 00020f50 =====

void NvStorAhciAtaSuccess(longlong *param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)((longlong)param_1 + 0x84) != 0xffffffff) {
    NvStorReleaseTag((undefined8 *)param_1[2],(ulonglong)*(uint *)((longlong)param_1 + 0x84));
    *(undefined8 *)(param_1[2] + 0x240 + (longlong)*(int *)((longlong)param_1 + 0x84) * 8) = 0;
    *(undefined4 *)((longlong)param_1 + 0x84) = 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x18) & 0x10) == 0) {
    uVar3 = *(int *)(param_1[2] + 0x230) << 8;
  }
  else {
    uVar3 = *(int *)(param_1[2] + 0x230) << 0x10;
  }
  uVar4 = *(uint *)((longlong)param_1 + 0x2c);
  if (uVar3 < *(uint *)((longlong)param_1 + 0x2c)) {
    uVar4 = uVar3;
  }
  *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) - uVar4;
  *(uint *)(param_1 + 5) = (int)param_1[5] + uVar4;
  if (*(int *)((longlong)param_1 + 0x2c) != 0) {
    iVar1 = NvStorAhciScsi((longlong)param_1);
    if (iVar1 < 0) {
      NvStorAhciAtaHandleError((longlong)param_1,iVar1);
    }
    if (iVar1 == 1) {
      iVar1 = NvStorReqQueueInsert(param_1[2] + 0x1a8,param_1);
      if (iVar1 < 0) {
        NvStorAhciAtaHandleError((longlong)param_1,iVar1);
      }
      uVar2 = NvStorReqQueueComplete((undefined8 *)(param_1[2] + 0x1a8),(longlong)param_1);
      if ((int)uVar2 < 0) {
        NvStorAhciAtaHandleError((longlong)param_1,(int)uVar2);
        return;
      }
      return;
    }
  }
  FUN_000220c4((longlong)param_1);
  *(undefined4 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((longlong)param_1 + 0x8c) = 0;
  NvStorReqQueueComplete((undefined8 *)(param_1[2] + 0x1a8),(longlong)param_1);
  NvStorCompleteRequestEx((longlong)param_1,1);
  return;
}



===== NvStorAhciAtaHandleError @ 0002105c =====

void NvStorAhciAtaHandleError(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int local_res8 [8];
  
  if (param_1 != 0) {
    NvStorScsiBuildSenseData(param_1,param_2);
    lVar1 = *(longlong *)(param_1 + 0x10);
    if ((lVar1 != 0) &&
       (*(longlong *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
      *(undefined8 *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
    }
    if (*(uint *)(param_1 + 0x84) != 0xffffffff) {
      NvStorReleaseTag(*(undefined8 **)(param_1 + 0x10),(ulonglong)*(uint *)(param_1 + 0x84));
      *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
    }
    puVar2 = *(undefined8 **)(param_1 + 0x10);
    if (puVar2 != (undefined8 *)0x0) {
      NvCfgElementGet(*(longlong *)(*(longlong *)*puVar2 + 0x2820),(longlong *)puVar2[0xb6],';',
                      (undefined8 *)local_res8,4);
      local_res8[0] = local_res8[0] + 1;
      NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2820),
                      (longlong *)(*(undefined8 **)(param_1 + 0x10))[0xb6],';',
                      (ulonglong *)local_res8,4);
    }
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x100000;
    if (*(longlong *)(param_1 + 0x10) != 0) {
      NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
    }
    NvStorCompleteRequestEx(param_1,1);
  }
  return;
}



===== NvStorAhciAtaCancel @ 00021144 =====

void NvStorAhciAtaCancel(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  longlong lVar1;
  
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x80000;
  NvStorScsiBuildSenseData(param_1,param_2);
  lVar1 = *(longlong *)(param_1 + 0x10);
  if ((lVar1 != 0) &&
     (*(longlong *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
    *(undefined8 *)(lVar1 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
  }
  NvStorCompleteRequestEx(param_1,param_3);
  return;
}



===== NvStorAhciAtapiHandleError @ 0002119c =====

void NvStorAhciAtapiHandleError(longlong param_1,undefined4 param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  bVar6 = false;
  bVar5 = false;
  *(undefined4 *)(param_1 + 0x88) = param_2;
  FUN_000220c4(param_1);
  lVar3 = *(longlong *)(param_1 + 0x10);
  if ((*(uint *)(lVar3 + 0x890) >> 0x14 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x8d) = 1;
    if (0xff < *(uint *)(lVar2 + 0xd0)) {
      *(undefined4 *)(lVar2 + 0xd0) = 0xff;
    }
    *(undefined1 *)(param_1 + 0x78) = *(undefined1 *)(lVar2 + 0xd0);
    lVar2 = *(longlong *)(param_1 + 0x10);
    if ((lVar2 != 0) &&
       (*(longlong *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
      *(undefined8 *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
    }
    if (*(uint *)(param_1 + 0x84) != 0xffffffff) {
      NvStorReleaseTag(*(undefined8 **)(param_1 + 0x10),(ulonglong)*(uint *)(param_1 + 0x84));
      *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
    }
    NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
    NvStorCompleteRequestEx(param_1,1);
    if (lVar3 == 0) {
      return;
    }
    *(ulonglong *)(lVar3 + 0x890) = *(ulonglong *)(lVar3 + 0x890) & 0xffffffffffefffff;
    return;
  }
  *(undefined4 *)(lVar3 + 0x1a0) = 0x80000003;
  bVar1 = *(byte *)(param_1 + 0x18) >> 4;
  if (bVar1 < 6) {
    if (bVar1 == 5) {
      *(undefined1 *)(param_1 + 0x8c) = 2;
      *(undefined4 *)(param_1 + 0x88) = 0x80000003;
      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0x80000012;
      goto LAB_000212c1;
    }
    if (bVar1 == 0) {
      bVar6 = true;
    }
    else {
      if (bVar1 == 1) {
        *(undefined4 *)(param_1 + 0x88) = 0;
        *(undefined1 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0;
        goto LAB_000212c1;
      }
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 0x8c) = 2;
        *(undefined4 *)(param_1 + 0x88) = 0x80000003;
        *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x1a0) = 0x80000009;
        goto LAB_000212c1;
      }
      if ((bVar1 != 3) && (bVar1 != 4)) goto LAB_00021422;
    }
LAB_000212b4:
    *(undefined1 *)(param_1 + 0x8c) = 2;
    bVar5 = bVar6;
  }
  else {
    if ((((bVar1 == 6) || (bVar1 == 7)) || (bVar1 == 8)) || (bVar1 == 0xb)) goto LAB_000212b4;
LAB_00021422:
    *(undefined1 *)(param_1 + 0x8c) = 0;
    bVar5 = bVar6;
  }
  *(undefined4 *)(param_1 + 0x88) = 0x80000003;
LAB_000212c1:
  if ((*(uint *)(param_1 + 0xc0) & 2) == 0) {
    FUN_00021d28(*(longlong *)(param_1 + 0x10),param_1);
    iVar7 = (**(code **)(lVar2 + 0x160))(*(undefined8 *)(param_1 + 0x10),lVar2 + 0xa8);
    if (-1 < iVar7) {
      return;
    }
  }
  if ((*(char *)(param_1 + 0x8c) == '\x02') && (!bVar5)) {
    puVar4 = *(undefined1 **)(*(longlong *)(param_1 + 0x10) + 0x198);
    *puVar4 = 0xf0;
    puVar4[7] = 0xb;
    bVar1 = *(byte *)(param_1 + 0x18);
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4[1] = bVar1 >> 4;
    *(undefined1 *)(param_1 + 0x78) = 8;
    *(undefined1 *)(param_1 + 0x8d) = 1;
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  if ((lVar2 != 0) &&
     (*(longlong *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) == param_1)) {
    *(undefined8 *)(lVar2 + 0x240 + (longlong)*(int *)(param_1 + 0x84) * 8) = 0;
  }
  if (*(uint *)(param_1 + 0x84) != 0xffffffff) {
    NvStorReleaseTag(*(undefined8 **)(param_1 + 0x10),(ulonglong)*(uint *)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
  }
  NvStorReqQueueComplete((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1a8),param_1);
  NvStorCompleteRequestEx(param_1,1);
  return;
}



===== FUN_00021430 @ 00021430 =====

undefined8 FUN_00021430(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  byte bVar3;
  byte bVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  bool bVar12;
  undefined1 local_res8 [8];
  
  uVar2 = *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
  if ((uVar2 & 1) != 0) {
    return 0x80000007;
  }
  bVar12 = *(char *)(param_1 + 0x40) == '\x15';
  lVar8 = *(longlong *)(param_1 + 0x30);
  uVar6 = (-(uint)bVar12 & 0xfffffffc) + 8;
  if (lVar8 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x78) = 0;
    *(undefined1 *)(param_1 + 0x8c) = 0;
LAB_0002148a:
    uVar5 = 0;
  }
  else {
    if (bVar12) {
      if (uVar6 <= *(uint *)(param_1 + 0x2c)) {
        uVar11 = (ulonglong)*(byte *)(lVar8 + 3);
        lVar10 = lVar8 + 4;
LAB_000214be:
        uVar6 = (int)uVar11 + uVar6;
        if (bVar12) {
          uVar7 = (ulonglong)*(byte *)(param_1 + 0x44);
        }
        else {
          uVar7 = (ulonglong)*(ushort *)(param_1 + 0x47);
        }
        if ((ulonglong)uVar6 + 1 <= uVar7) {
          if ((*(byte *)(lVar10 + uVar11) & 0x3f) != 8) {
            return 0x80000007;
          }
          bVar3 = *(byte *)((ulonglong)uVar6 + 2 + lVar8) >> 2;
          bVar4 = bVar3 & 1;
          bVar3 = bVar3 & 1;
          if ((bVar4 == 0) || ((uVar2 & 0x1000) == 0)) {
            if (bVar4 == 0) {
              if ((uVar2 & 0x1000) == 0) goto LAB_00021507;
              if (bVar3 != 0) goto LAB_0002151d;
            }
            else {
LAB_0002151d:
              if (((uVar2 >> 0xb & 1) != 0) && ((uVar2 & 0x1000) == 0)) {
                *(undefined2 *)(*(longlong *)(param_1 + 200) + 2) = 0x2ef;
                *(undefined4 *)(param_1 + 0xc4) = 0;
                *(undefined4 *)(param_1 + 0x2c) = 0;
                local_res8[0] = 1;
                *(code **)(param_1 + 0xb8) = FUN_000223c8;
                puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
                *puVar1 = *puVar1 | 0x1000;
                puVar9 = *(undefined8 **)(param_1 + 0x10);
                lVar8 = *(longlong *)*puVar9;
                goto LAB_00021562;
              }
              if (bVar3 != 0) {
                return 0x80000007;
              }
            }
            if ((uVar2 & 0x1000) == 0) {
              return 0x80000007;
            }
            *(undefined2 *)(*(longlong *)(param_1 + 200) + 2) = 0x82ef;
            *(undefined4 *)(param_1 + 0xc4) = 0;
            *(undefined4 *)(param_1 + 0x2c) = 0;
            local_res8[0] = 0;
            *(code **)(param_1 + 0xb8) = FUN_000223c8;
            puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
            *puVar1 = *puVar1 & 0xffffffffffffefff;
            puVar9 = *(undefined8 **)(param_1 + 0x10);
            lVar8 = *(longlong *)*puVar9;
LAB_00021562:
            NvCfgElementSet(*(longlong *)(lVar8 + 0x2820),(longlong *)puVar9[0xb6],'(',
                            (ulonglong *)local_res8,1);
            return 1;
          }
LAB_00021507:
          *(undefined4 *)(param_1 + 0x88) = 0;
          goto LAB_0002148a;
        }
      }
    }
    else if (uVar6 <= *(uint *)(param_1 + 0x2c)) {
      uVar11 = (ulonglong)*(ushort *)(lVar8 + 6);
      lVar10 = lVar8 + 8;
      goto LAB_000214be;
    }
    uVar5 = 0x80000008;
  }
  return uVar5;
}



===== FUN_000215e4 @ 000215e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_000215e4(longlong param_1)

{
  byte *pbVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined1 auStack_68 [32];
  char local_48;
  char local_44 [4];
  byte local_40 [16];
  ushort local_30 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 200) + 2) = 0xda;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(code **)(param_1 + 0xb8) = FUN_000223c8;
    return 1;
  }
  if (*(uint *)(param_1 + 0x2c) == 0) {
LAB_0002162f:
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  else {
    bVar5 = *(byte *)(param_1 + 0x42) & 0x3f;
    if ((bVar5 < 0x40) && ((0x8000000010000100U >> bVar5 & 1) != 0)) {
      if (bVar5 != 0x1c) {
        bVar11 = *(char *)(param_1 + 0x40) == '\x1a';
        puVar2 = *(ushort **)(param_1 + 0x30);
        uVar8 = -(uint)bVar11 & 0xfffffffc;
        uVar9 = uVar8 + 8;
        if (puVar2 == (ushort *)0x0) {
          return 0x80000008;
        }
        local_48 = bVar11;
        (**(code **)(NvStorOsCBT + 0x110))(puVar2);
        uVar10 = uVar8 + 0x1c;
        if (bVar11) {
          if (*(uint *)(param_1 + 0x2c) < uVar10) {
LAB_00021708:
            if (bVar11) {
              *(char *)puVar2 = (char)uVar8 + '\a';
            }
            else {
              uVar4 = (ushort)(uVar8 + 6);
              *puVar2 = uVar4 << 8 | uVar4 >> 8;
            }
            *(undefined4 *)(param_1 + 0x88) = 0x80000004;
            *(undefined1 *)(param_1 + 0x8c) = 0;
            *(uint *)(param_1 + 0x2c) = uVar9;
            *(uint *)(param_1 + 0x28) = uVar9;
            *(undefined1 *)(param_1 + 0x78) = 0;
            return 0;
          }
          (**(code **)(NvStorOsCBT + 0x110))(local_44,uVar9);
          local_44[0] = (char)uVar8 + '\x1b';
        }
        else {
          if (*(uint *)(param_1 + 0x2c) < uVar10) goto LAB_00021708;
          (**(code **)(NvStorOsCBT + 0x110))(local_30,uVar9);
          uVar4 = (short)uVar8 + 0x1a;
          local_30[0] = uVar4 * 0x100 | uVar4 >> 8;
        }
        (**(code **)(NvStorOsCBT + 0x110))(local_40,0xc);
        local_40[1] = 0x12;
        puVar7 = (ushort *)local_44;
        local_40[0] = local_40[0] & 200 | 8;
        local_40[2] = local_40[2] ^
                      ((char)(*(uint *)(*(longlong *)(param_1 + 0x10) + 0x890) >> 0xc) << 2 ^
                      local_40[2]) & 4;
        if (*(uint *)(param_1 + 0x2c) < uVar9) {
          uVar9 = *(uint *)(param_1 + 0x2c);
        }
        if (local_48 == '\0') {
          puVar7 = local_30;
        }
        (**(code **)(NvStorOsCBT + 0x118))(puVar2,puVar7,uVar9);
        if (uVar9 < *(uint *)(param_1 + 0x2c)) {
          uVar6 = *(uint *)(param_1 + 0x2c) - uVar9;
          uVar8 = 0xc;
          if (uVar6 < 0x14) {
            uVar8 = uVar6;
          }
          (**(code **)(NvStorOsCBT + 0x118))
                    ((char *)((longlong)puVar2 + (ulonglong)uVar9),local_40,uVar8);
        }
        if (*(uint *)(param_1 + 0x2c) < uVar10) {
          uVar10 = *(uint *)(param_1 + 0x2c);
        }
        *(uint *)(param_1 + 0x28) = uVar10;
        goto LAB_0002162f;
      }
      pbVar1 = *(byte **)(param_1 + 0x30);
      (**(code **)(NvStorOsCBT + 0x110))(pbVar1,0xc);
      pbVar1[1] = 0xb;
      *pbVar1 = *pbVar1 & 0xdc | 0x1c;
      uVar9 = 0xc;
      if (*(uint *)(param_1 + 0x2c) < 0xc) {
        uVar9 = *(uint *)(param_1 + 0x2c);
      }
      *(uint *)(param_1 + 0x28) = uVar9;
    }
    else {
      puVar3 = *(undefined1 **)(param_1 + 0x30);
      if (*(uint *)(param_1 + 0x2c) < 4) {
        *(undefined4 *)(param_1 + 0x88) = 0x80000002;
        return 0x80000008;
      }
      (**(code **)(NvStorOsCBT + 0x110))(puVar3,4);
      *puVar3 = 3;
      *(undefined4 *)(param_1 + 0x2c) = 4;
      *(undefined4 *)(param_1 + 0x28) = 4;
    }
    *(undefined1 *)(param_1 + 0x8c) = 0;
  }
  return 0;
}



===== FUN_0002189c @ 0002189c =====

undefined8 FUN_0002189c(longlong param_1)

{
  ulonglong *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  byte bVar4;
  
  bVar4 = *(byte *)(param_1 + 0x44) & 2;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    if (bVar4 == 0) {
      puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
      *puVar1 = *puVar1 | 0x200000000;
      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x8a4) = 0;
      if ((*(uint *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x2818) & 0x100) == 0) {
        puVar1 = *(undefined8 **)(param_1 + 0x10) + 0x112;
        *puVar1 = *puVar1 | 0x200000000000;
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10000;
        NvStorPrepareLinkedRequest(param_1);
        puVar2 = (uint *)(*(longlong *)(param_1 + 0x70) + 0xc0);
        *puVar2 = *puVar2 | 0x220000;
      }
      uVar3 = FUN_000219e0(param_1);
      return uVar3;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x10) + 0x890) & 1) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 200) + 2) = 0xed;
      *(code **)(param_1 + 0xb8) = FUN_000223c8;
      *(undefined4 *)(param_1 + 0xc4) = 0;
      return 1;
    }
  }
  else if (bVar4 == 0) {
    if (*(int *)(*(longlong *)**(longlong **)(param_1 + 0x10) + 0x2664) == 2) {
      puVar2 = (uint *)((longlong *)**(longlong **)(param_1 + 0x10) + 0x24);
      *puVar2 = *puVar2 | 2;
    }
    puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
    *puVar1 = *puVar1 & 0xfffffffdffffffff;
    (**(code **)(NvStorOsCBT + 0x110))(param_1 + 0x40,0x10);
    *(undefined1 *)(param_1 + 0x40) = 0x2f;
    *(undefined1 *)(param_1 + 0x45) = 1;
    *(undefined1 *)(param_1 + 0x48) = 1;
    uVar3 = FUN_00021cac(param_1);
    return uVar3;
  }
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0x80000007;
  return 0x80000007;
}



===== FUN_000219e0 @ 000219e0 =====

undefined8 FUN_000219e0(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if ((*(int *)(lVar1 + 0x8a4) == 1) && (*(longlong *)(param_1 + 0xd0) != 0)) {
    if ((*(uint *)(lVar1 + 0x890) >> 0xc & 1) != 0) {
      *(undefined1 *)(lVar1 + 0x8a0) = 1;
    }
  }
  else {
    if ((*(ulonglong *)(lVar1 + 0x890) >> 0xc & 1) != 0) {
      if ((*(ulonglong *)(lVar1 + 0x890) & 0x10) == 0) {
        *(undefined1 *)(*(longlong *)(param_1 + 200) + 2) = 0xe7;
      }
      else {
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10;
        *(undefined1 *)(*(longlong *)(param_1 + 200) + 2) = 0xea;
      }
      *(undefined4 *)(param_1 + 0xc4) = 0;
      *(code **)(param_1 + 0xb8) = FUN_000223c8;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x88) = 0x80000007;
    *(undefined1 *)(param_1 + 0x8c) = 2;
  }
  return 0;
}



===== FUN_00021a6c @ 00021a6c =====

undefined8 FUN_00021a6c(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_1 + 200);
  plVar4 = *(longlong **)(lVar2 + 0x880);
  uVar6 = FUN_00022190(param_1);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if ((*(byte *)(lVar2 + 0x890) & 0x80) == 0) {
    if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
      *(undefined4 *)(param_1 + 0xc4) = 3;
      if ((*(uint *)(lVar2 + 0x890) >> 8 & 1) == 0) {
        *(undefined1 *)(lVar3 + 2) = 0x30;
      }
      else {
        *(undefined1 *)(lVar3 + 2) = 0xc5;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc4) = 2;
      if ((*(uint *)(lVar2 + 0x890) >> 8 & 1) == 0) {
        *(undefined1 *)(lVar3 + 2) = 0x20;
      }
      else {
        *(undefined1 *)(lVar3 + 2) = 0xc4;
      }
    }
    if ((*(uint *)(param_1 + 0xc0) & 0x10) != 0) {
      cVar1 = *(char *)(lVar3 + 2);
      if (cVar1 == ' ') {
        *(undefined1 *)(lVar3 + 2) = 0x24;
      }
      else if (cVar1 == '0') {
        *(undefined1 *)(lVar3 + 2) = 0x34;
      }
      else if (cVar1 == -0x3c) {
        *(undefined1 *)(lVar3 + 2) = 0x29;
      }
      else {
        if (cVar1 != -0x3b) {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 2) = 0x39;
      }
    }
  }
  else {
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x200;
    *(undefined4 *)(param_1 + 0xc4) = 1;
    if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
      *(undefined1 *)(lVar3 + 2) = 0xca;
    }
    else {
      *(undefined1 *)(lVar3 + 2) = 200;
    }
    if ((*(uint *)(param_1 + 0xc0) & 0x10) != 0) {
      if (*(char *)(lVar3 + 2) == -0x38) {
        *(undefined1 *)(lVar3 + 2) = 0x25;
      }
      else {
        if (*(char *)(lVar3 + 2) != -0x36) {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 2) = 0x35;
      }
    }
    uVar5 = *(ulonglong *)(lVar2 + 0x890);
    if (((((uVar5 & 0x4000) != 0) && ((uVar5 & 0x8000) != 0)) && (1 < *(ushort *)(lVar2 + 0x220)))
       && (((uVar5 >> 0x19 & 1) == 0 || ((uVar5 >> 0x1a & 1) != 0)))) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x20;
      *(undefined4 *)(param_1 + 0xc4) = 4;
      if (*(char *)(lVar3 + 2) == '%') {
        *(undefined1 *)(lVar3 + 2) = 0x60;
      }
      else {
        if (*(char *)(lVar3 + 2) != '5') {
          return 0x80000003;
        }
        *(undefined1 *)(lVar3 + 2) = 0x61;
      }
    }
  }
  if ((*(uint *)(param_1 + 0xc0) & 0x8000) != 0) {
    if (((*(ulonglong *)(lVar2 + 0x890) & 0x4000) == 0) ||
       ((*(ulonglong *)(lVar2 + 0x890) & 0x8000) == 0)) {
      if ((*(uint *)(param_1 + 0xc0) & 1) == 0) {
        cVar1 = *(char *)(lVar3 + 2);
        if (cVar1 == '5') {
          if ((*(byte *)(*plVar4 + 0xa6) & 0x80) != 0) {
            *(undefined1 *)(lVar3 + 2) = 0x3d;
          }
        }
        else if (cVar1 == '6') {
          if ((*(byte *)(*plVar4 + 0xa6) & 0x40) != 0) {
            *(undefined1 *)(lVar3 + 2) = 0x3e;
          }
        }
        else if ((cVar1 == '9') && ((*(byte *)(*plVar4 + 0xa6) & 0x80) != 0)) {
          *(undefined1 *)(lVar3 + 2) = 0xce;
        }
      }
    }
    else {
      *(byte *)(lVar3 + 7) = *(byte *)(lVar3 + 7) | 0x80;
    }
  }
  uVar6 = FUN_000221e8(param_1);
  if (-1 < (int)uVar6) {
    *(code **)(param_1 + 0xb8) = FUN_00022624;
    uVar6 = 1;
  }
  return uVar6;
}



===== FUN_00021cac @ 00021cac =====

undefined8 FUN_00021cac(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 200);
  uVar2 = NvStorScsiGetBlockCount((byte *)(param_1 + 0x40));
  *(uint *)(param_1 + 0x2c) =
       uVar2 * *(int *)(*(longlong *)(param_1 + 0x10) + 0x230) - *(int *)(param_1 + 0x28);
  uVar3 = FUN_00022190(param_1);
  if (-1 < (int)uVar3) {
    *(byte *)(lVar1 + 2) = *(byte *)(param_1 + 0xc0) >> 3 & 2 | 0x40;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    uVar3 = FUN_000221e8(param_1);
    if (-1 < (int)uVar3) {
      *(code **)(param_1 + 0xb8) = FUN_000223c8;
      uVar3 = 1;
    }
  }
  return uVar3;
}



===== FUN_00021d28 @ 00021d28 =====

void FUN_00021d28(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = param_1 + 0xa8;
  lVar2 = *(longlong *)(param_1 + 0x170);
  (**(code **)(NvStorOsCBT + 0x110))(lVar1,0xf0);
  *(longlong *)(param_1 + 0x170) = lVar2;
  *(longlong *)(param_1 + 0xb8) = param_1;
  *(undefined4 *)(param_1 + 0xc4) = 10;
  *(undefined4 *)(param_1 + 0xd4) = 0xff;
  *(uint *)(param_1 + 0x168) = *(uint *)(param_1 + 0x168) | 3;
  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0x198);
  *(longlong *)(param_1 + 0x178) = param_2;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_2 + 0x84);
  lVar3 = NvStorOsCBT;
  *(undefined1 *)(param_1 + 0xe8) = 3;
  *(undefined2 *)(param_1 + 0xec) = 0xff;
  (**(code **)(lVar3 + 0x110))(lVar2,0x14);
  *(undefined2 *)(*(longlong *)(param_1 + 0x170) + 5) = 0xff;
  *(undefined1 *)(lVar2 + 2) = 0xa0;
  *(ulonglong *)(param_1 + 0x890) = *(ulonglong *)(param_1 + 0x890) | 0x100000;
  *(longlong *)(param_1 + 0x178) = param_2;
  *(longlong *)(param_1 + 0x240 + (longlong)*(int *)(param_2 + 0x84) * 8) = lVar1;
  *(undefined4 *)(param_1 + 0x16c) = 6;
  *(undefined1 **)(param_1 + 0x148) = &LAB_0001be70;
  *(undefined1 **)(param_1 + 0x140) = &LAB_0001be70;
  *(code **)(param_1 + 0x160) = FUN_000223c8;
                    /* WARNING: Could not recover jumptable at 0x00021e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x368))(lVar1);
  return;
}



===== FUN_00021e48 @ 00021e48 =====

undefined8 FUN_00021e48(longlong param_1)

{
  char *pcVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 uVar8;
  code *pcVar9;
  short sVar10;
  
  lVar3 = *(longlong *)(param_1 + 200);
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x890) >> 9 & 1) == 0) {
LAB_00021faa:
    iVar5 = 0;
  }
  else {
    pcVar1 = (char *)(param_1 + 0x40);
    if (*pcVar1 == '\x15') {
      uVar8 = *(undefined1 *)(param_1 + 0x44);
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 4;
      (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x50,pcVar1,0xc);
      (**(code **)(NvStorOsCBT + 0x110))(pcVar1,0xc);
      *pcVar1 = 'U';
      *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 0x10;
      *(undefined1 *)(param_1 + 0x47) = 0;
      *(undefined1 *)(param_1 + 0x48) = uVar8;
      *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 1;
LAB_00021fa4:
      *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(param_1 + 0x55);
      goto LAB_00021faa;
    }
    if (*pcVar1 != '\x1a') goto LAB_00021faa;
    bVar2 = *(byte *)(param_1 + 0x42);
    if (*(longlong *)(param_1 + 0x30) == 0) {
      iVar5 = -0x7ffffff9;
    }
    else {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 4;
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 4;
      sVar10 = *(byte *)(param_1 + 0x44) + 4;
      (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x50,pcVar1,0xc);
      *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0x30);
      lVar7 = (**(code **)(NvStorOsCBT + 0x100))
                        (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),sVar10,2,1);
      *(longlong *)(param_1 + 0x30) = lVar7;
      lVar4 = NvStorOsCBT;
      if (lVar7 != 0) {
        *(undefined8 *)(param_1 + 0x20) = 0;
        (**(code **)(lVar4 + 0x110))(pcVar1,0xc);
        *pcVar1 = 'Z';
        *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) | bVar2 & 0x3f;
        *(char *)(param_1 + 0x48) = (char)sVar10;
        *(byte *)(param_1 + 0x41) = *(byte *)(param_1 + 0x41) | *(byte *)(param_1 + 0x51) & 8;
        *(char *)(param_1 + 0x47) = (char)((ushort)sVar10 >> 8);
        goto LAB_00021fa4;
      }
      iVar5 = -0x7fffffef;
    }
  }
  if (iVar5 < 0) {
    return 0x80000011;
  }
  uVar6 = *(uint *)(param_1 + 0x2c);
  lVar4 = *(longlong *)(param_1 + 200);
  uVar8 = (undefined1)(uVar6 >> 8);
  if (0xffff < uVar6) {
    uVar8 = 0xff;
    uVar6 = 0xff;
  }
  *(char *)(lVar4 + 5) = (char)uVar6;
  *(undefined1 *)(lVar4 + 6) = uVar8;
  *(undefined1 *)(lVar3 + 2) = 0xa0;
  if (((*(char *)(*(undefined8 **)(param_1 + 0x10) + 0x112) < '\0') &&
      (*(longlong *)(param_1 + 0x20) != 0)) && (*(int *)(param_1 + 0x2c) != 0)) {
    if ((*(uint *)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x25f0) & 0x800000) != 0) {
      bVar2 = *(byte *)(param_1 + 0x40);
      if (((0x2e < bVar2) || ((0x450000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) == 0)) &&
         ((0x36 < (byte)(bVar2 + 0x78) ||
          ((0x42000500000005U >> ((ulonglong)(byte)(bVar2 + 0x78) & 0x3f) & 1) == 0))))
      goto LAB_00022076;
    }
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x200;
    *(undefined1 *)(lVar3 + 3) = 1;
    if ((*(uint *)(param_1 + 0xc0) & 1) != 0) {
      *(undefined1 *)(lVar3 + 3) = 5;
    }
    *(undefined4 *)(param_1 + 0xc4) = 5;
    *(code **)(param_1 + 0xb8) = FUN_00022624;
  }
  else {
LAB_00022076:
    *(undefined1 *)(lVar3 + 3) = 0;
    pcVar9 = FUN_000223c8;
    *(undefined4 *)(param_1 + 0xc4) = 6;
    if (*(longlong *)(param_1 + 0x20) != 0) {
      pcVar9 = FUN_00022624;
    }
    *(code **)(param_1 + 0xb8) = pcVar9;
  }
  return 1;
}



===== FUN_000220c4 @ 000220c4 =====

void FUN_000220c4(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  uint uVar5;
  
  if (((*(uint *)(param_1 + 0xc0) & 4) != 0) && (*(char *)(param_1 + 0x40) == 'Z')) {
    lVar2 = *(longlong *)(param_1 + 0x30);
    puVar3 = *(undefined1 **)(param_1 + 0x60);
    *puVar3 = *(undefined1 *)(lVar2 + 1);
    puVar3[1] = *(undefined1 *)(lVar2 + 2);
    puVar3[2] = *(undefined1 *)(lVar2 + 3);
    puVar3[3] = *(undefined1 *)(lVar2 + 7);
    uVar5 = *(uint *)(param_1 + 0x28);
    if (7 < uVar5) {
      uVar5 = 8;
    }
    piVar1 = (int *)(param_1 + 0x28);
    *piVar1 = *piVar1 - uVar5;
    if (*piVar1 != 0) {
      (**(code **)(NvStorOsCBT + 0x118))
                (*(longlong *)(param_1 + 0x60) + 4,*(longlong *)(param_1 + 0x30) + 8,
                 *(undefined4 *)(param_1 + 0x28));
    }
    lVar2 = NvStorOsCBT;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 4;
    (**(code **)(lVar2 + 0x118))(param_1 + 0x40,param_1 + 0x50,0xc);
    uVar4 = *(undefined8 *)(param_1 + 0x30);
    *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x60);
    (**(code **)(NvStorOsCBT + 0x108))(*(undefined8 *)**(undefined8 **)(param_1 + 0x10),uVar4,1);
  }
  return;
}



===== FUN_00022190 @ 00022190 =====

undefined8 FUN_00022190(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar4 = *(longlong *)(param_1 + 200);
  uVar1 = NvStorScsiGetLBA((byte *)(param_1 + 0x40));
  *(ulonglong *)(param_1 + 0x38) = uVar1;
  if (((*(byte *)(lVar3 + 0x890) & 1) == 0) && (*(ulonglong *)(lVar3 + 0x228) < uVar1)) {
    uVar2 = 0x80000003;
  }
  else {
    *(byte *)(lVar4 + 7) = *(byte *)(lVar4 + 7) | 0x40;
    if ((*(byte *)(lVar3 + 0x890) & 0x10) != 0) {
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_000221e8 @ 000221e8 =====

undefined8 FUN_000221e8(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  
  lVar9 = *(longlong *)(param_1 + 200);
  uVar5 = NvStorScsiGetBlockCount((byte *)(param_1 + 0x40));
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x230);
  *(byte *)(lVar9 + 7) = *(byte *)(lVar9 + 7) | 0x40;
  lVar9 = *(longlong *)(param_1 + 200);
  uVar7 = *(uint *)(param_1 + 0xc0);
  lVar6 = (ulonglong)(uVar5 * iVar1 - *(int *)(param_1 + 0x2c) >> 9) + *(longlong *)(param_1 + 0x38)
  ;
  *(char *)(lVar9 + 4) = (char)lVar6;
  bVar4 = (byte)((ulonglong)lVar6 >> 0x18);
  if ((uVar7 & 0x10) == 0) {
    *(byte *)(lVar9 + 7) = bVar4 & 0xf | 0x40;
  }
  else {
    *(char *)(lVar9 + 10) = (char)((ulonglong)lVar6 >> 0x28);
    *(char *)(lVar9 + 9) = (char)((ulonglong)lVar6 >> 0x20);
    *(byte *)(lVar9 + 8) = bVar4;
  }
  *(char *)(lVar9 + 6) = (char)((ulonglong)lVar6 >> 0x10);
  *(char *)(lVar9 + 5) = (char)((ulonglong)lVar6 >> 8);
  uVar7 = *(uint *)(param_1 + 0x2c);
  uVar5 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x230);
  uVar8 = *(uint *)(param_1 + 0xc0) & 0x10;
  if (uVar8 == 0) {
    if (uVar5 << 8 < uVar7) {
      uVar7 = uVar5 << 8;
    }
  }
  else if (uVar5 << 0x10 < uVar7) {
    uVar7 = uVar5 << 0x10;
  }
  uVar3 = (undefined1)((ulonglong)uVar7 / (ulonglong)uVar5);
  lVar9 = *(longlong *)(param_1 + 200);
  if (uVar8 == 0) {
    *(undefined1 *)(lVar9 + 0xc) = uVar3;
  }
  else {
    uVar2 = (undefined1)((ulonglong)uVar7 / (ulonglong)uVar5 >> 8);
    if ((*(uint *)(param_1 + 0xc0) & 0x20) == 0) {
      *(undefined1 *)(lVar9 + 0xc) = uVar3;
      *(undefined1 *)(lVar9 + 0xd) = uVar2;
    }
    else {
      *(undefined1 *)(lVar9 + 3) = uVar3;
      *(undefined1 *)(lVar9 + 0xb) = uVar2;
    }
  }
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x2000;
  return 0;
}



===== NvStorAhciSetupTaskFile @ 0002236c =====

undefined8 NvStorAhciSetupTaskFile(longlong param_1,undefined1 *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  (**(code **)(NvStorOsCBT + 0x110))(lVar1,0x14);
  *(undefined1 *)(lVar1 + 3) = *param_2;
  *(undefined1 *)(lVar1 + 0xc) = param_2[1];
  *(undefined1 *)(lVar1 + 4) = param_2[2];
  *(undefined1 *)(lVar1 + 5) = param_2[3];
  *(undefined1 *)(lVar1 + 6) = param_2[4];
  *(undefined1 *)(lVar1 + 2) = param_2[10];
  return 0;
}



===== FUN_000223c8 @ 000223c8 =====

ulonglong FUN_000223c8(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  uint local_res8 [2];
  
  uVar7 = 0;
  if (param_2 != param_1 + 0x15) {
    uVar4 = NvStorGetNextTag(param_1,(uint *)((longlong)param_2 + 0x84));
    uVar7 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  lVar1 = *(longlong *)(*param_1 + 0xf0);
  lVar2 = param_1[0x110];
  puVar8 = (ushort *)
           ((longlong)*(int *)((longlong)param_2 + 0x84) * 0x20 + *(longlong *)(lVar1 + 0x18));
  puVar9 = (undefined2 *)
           ((longlong)*(int *)((longlong)param_2 + 0x84) * 0x300 + *(longlong *)(lVar1 + 0x20));
  (**(code **)(NvStorOsCBT + 0x118))(puVar9,param_2[0x19],0x14);
  *puVar8 = 5;
  puVar8[2] = 0;
  puVar8[3] = 0;
  *puVar9 = 0x8027;
  if ((param_2[6] == 0) || (*(int *)((longlong)param_2 + 0x2c) == 0)) {
    puVar8[1] = 0;
  }
  else {
    puVar8[1] = 1;
    local_res8[0] = *(uint *)((longlong)param_2 + 0x2c);
    if (((*(uint *)(param_2 + 0x18) & 4) == 0) || ((char)param_2[8] != 'Z')) {
      plVar6 = param_2;
      if ((char)param_2[8] == '\x03') {
        plVar6 = (longlong *)0x0;
      }
    }
    else {
      plVar6 = (longlong *)0x0;
    }
    lVar5 = (**(code **)(NvStorOsCBT + 0x1b8))(*(undefined8 *)*param_1,plVar6,param_2[6],local_res8)
    ;
    if ((lVar5 == 0) || (local_res8[0] < *(uint *)((longlong)param_2 + 0x2c))) {
      return 0x80000011;
    }
    *(int *)(puVar9 + 0x40) = (int)lVar5;
    *(int *)(puVar9 + 0x42) = (int)((ulonglong)lVar5 >> 0x20);
    uVar3 = *(int *)((longlong)param_2 + 0x2c) - 1;
    *(uint *)(puVar9 + 0x46) = uVar3;
    if (*(int *)((longlong)param_2 + 0xc4) == 2) {
      *(uint *)(puVar9 + 0x46) = uVar3 | 0x80000000;
    }
  }
  if (((*(uint *)(param_2 + 0x18) & 1) == 0) && (*(int *)((longlong)param_2 + 0x2c) != 0)) {
    *puVar8 = *puVar8 | 0x40;
  }
  lVar5 = NvStorOsCBT;
  if ((*(byte *)(param_1 + 0x112) & 0x20) != 0) {
    *puVar8 = *puVar8 | 0x20;
    (**(code **)(lVar5 + 0x118))(puVar9 + 0x20,param_2 + 8,0x10);
  }
  if ((*(uint *)(param_2 + 0x18) & 0x20) == 0) {
    *(undefined1 *)(lVar2 + 8) = 0;
    *puVar8 = *puVar8 | 0x80;
  }
  else {
    *(undefined1 *)(lVar2 + 8) = 1;
    *(byte *)(puVar9 + 6) = *(byte *)(puVar9 + 6) | *(char *)((longlong)param_2 + 0x84) << 3;
    (**(code **)(NvStorOsCBT + 0xa0))
              (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x34,
               1 << ((byte)*(undefined4 *)((longlong)param_2 + 0x84) & 0x1f));
  }
  param_1[(longlong)*(int *)((longlong)param_2 + 0x84) + 0x48] = (longlong)param_2;
  (**(code **)(NvStorOsCBT + 0xa0))
            (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x38,
             1 << ((byte)*(undefined4 *)((longlong)param_2 + 0x84) & 0x1f));
  (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
  return uVar7;
}



===== FUN_00022624 @ 00022624 =====

ulonglong FUN_00022624(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  ushort *puVar7;
  ushort uVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  
  uVar5 = 0;
  if (param_2 != param_1 + 0x15) {
    uVar4 = NvStorGetNextTag(param_1,(uint *)((longlong)param_2 + 0x84));
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  if (*(int *)param_2[4] == 0) {
    uVar5 = 0x80000008;
  }
  else {
    param_1[(longlong)*(int *)((longlong)param_2 + 0x84) + 0x48] = (longlong)param_2;
    lVar1 = *(longlong *)(*param_1 + 0xf0);
    lVar2 = param_1[0x110];
    puVar7 = (ushort *)
             ((longlong)*(int *)((longlong)param_2 + 0x84) * 0x20 + *(longlong *)(lVar1 + 0x18));
    puVar10 = (undefined2 *)
              ((longlong)*(int *)((longlong)param_2 + 0x84) * 0x300 + *(longlong *)(lVar1 + 0x20));
    (**(code **)(NvStorOsCBT + 0x118))(puVar10,param_2[0x19],0x14);
    *puVar10 = 0x8027;
    uVar8 = 0;
    if (*(int *)param_2[4] != 0) {
      do {
        uVar4 = (ulonglong)uVar8;
        puVar9 = (undefined4 *)(puVar10 + (uVar4 + 8) * 8);
        *puVar9 = *(undefined4 *)(param_2[4] + 0x10 + uVar4 * 0x18);
        puVar9[1] = (int)((ulonglong)*(undefined8 *)(param_2[4] + 0x10 + uVar4 * 0x18) >> 0x20);
        uVar6 = *(int *)(param_2[4] + 0x18 + uVar4 * 0x18) - 1;
        puVar9[3] = uVar6;
        if (*(int *)((longlong)param_2 + 0xc4) == 2) {
          puVar9[3] = uVar6 | 0x80000000;
        }
        uVar8 = uVar8 + 1;
      } while ((uint)uVar8 < *(uint *)param_2[4]);
    }
    puVar7[1] = uVar8;
    puVar7[2] = 0;
    puVar7[3] = 0;
    *puVar7 = 5;
    if (((*(uint *)(param_2 + 0x18) & 1) == 0) && (*(int *)((longlong)param_2 + 0x2c) != 0)) {
      *puVar7 = 0x45;
    }
    lVar3 = NvStorOsCBT;
    if ((*(byte *)(param_1 + 0x112) & 0x20) != 0) {
      *puVar7 = *puVar7 | 0x20;
      (**(code **)(lVar3 + 0x118))(puVar10 + 0x20,param_2 + 8,0x10);
    }
    if ((*(uint *)(param_2 + 0x18) & 0x20) == 0) {
      *(undefined1 *)(lVar2 + 8) = 0;
      *puVar7 = *puVar7 | 0x80;
    }
    else {
      *(undefined1 *)(lVar2 + 8) = 1;
      *(byte *)(puVar10 + 6) = *(byte *)(puVar10 + 6) | *(char *)((longlong)param_2 + 0x84) << 3;
      (**(code **)(NvStorOsCBT + 0xa0))
                (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x34,
                 1 << ((byte)*(undefined4 *)((longlong)param_2 + 0x84) & 0x1f));
    }
    param_1[(longlong)*(int *)((longlong)param_2 + 0x84) + 0x48] = (longlong)param_2;
    (**(code **)(NvStorOsCBT + 0xa0))
              (*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x38,
               1 << ((byte)*(undefined4 *)((longlong)param_2 + 0x84) & 0x1f));
    (**(code **)(NvStorOsCBT + 0x40))(*(undefined8 *)*param_1,*(longlong *)(lVar1 + 0x28) + 0x38);
  }
  return uVar5;
}



===== NvStorAhciSetupFeatureRequest @ 0002286c =====

undefined8 NvStorAhciSetupFeatureRequest(undefined8 *param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  (**(code **)(NvStorOsCBT + 0x110))(param_2,0xf0);
  *(undefined4 *)(param_2 + 0xc4) = 0;
  *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) | 0x40000;
  *(undefined8 *)(param_2 + 0xd0) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x30) = 0;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *(undefined8 **)(param_2 + 0x10) = param_1;
  *(undefined4 *)(param_2 + 0x1c) = 10;
  *(code **)(param_2 + 0xb8) = FUN_000223c8;
  puVar1 = (undefined4 *)(**(code **)(NvStorOsCBT + 0x100))(*(undefined8 *)*param_1,0x14,0,1);
  *(undefined4 **)(param_2 + 200) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x80000011;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x110))(puVar1,0x14);
    *puVar1 = 0xf58027;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((longlong)puVar1 + 7) = 0;
    *(undefined8 *)(param_2 + 0xa0) = param_1[0x6f];
    *(undefined8 *)(param_2 + 0x98) = param_1[0x6e];
    uVar2 = param_1[0x70];
    *(undefined1 *)(param_2 + 0x8d) = 0;
    *(undefined8 *)(param_2 + 0xa8) = uVar2;
    *(code **)(param_2 + 0xb0) = NvStorCompleteSSFRequest;
    uVar2 = 0;
  }
  return uVar2;
}



===== NvStorIntParallelEmuCheckInterrupt @ 00022980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char NvStorIntParallelEmuCheckInterrupt(longlong *param_1)

{
  code *pcVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte bVar8;
  char cVar9;
  ulonglong uVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  uint local_48 [2];
  undefined1 auStack_40 [32];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  cVar9 = '\0';
  if ((*(uint *)(param_1 + 0x503) & 2) == 0) {
    cVar3 = NvStorSataCheckHotPlugInterrupt(param_1);
    cVar9 = '\0';
    if (cVar3 != '\0') {
      cVar9 = '\x01';
    }
  }
  uVar4 = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      uVar4 = FUN_00015608(param_1,5);
    }
  }
  else {
    uVar4 = FUN_00015608(param_1,5);
    uVar4 = (uVar4 & 0xf0) << 0xc | uVar4 & 0xf;
  }
  if (((uVar4 >> 0x1e & 1) != 0) || ((int)uVar4 < 0)) {
    if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
      if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
        uVar4 = 0xc0000000;
        goto LAB_00022a48;
      }
    }
    else {
      uVar4 = FUN_00015608(param_1,5);
      uVar4 = uVar4 & 0xff00;
LAB_00022a48:
      FUN_000154b8(param_1,5,uVar4);
    }
    cVar9 = '\x01';
  }
  local_48[0] = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      local_48[0] = FUN_00015608(param_1,5);
    }
  }
  else {
    uVar4 = FUN_00015608(param_1,5);
    local_48[0] = (uVar4 & 0xf0) << 0xc | uVar4 & 0xf;
  }
  puVar6 = auStack_68;
  bVar8 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      uVar10 = (ulonglong)bVar8;
      if (0x1f < uVar10) {
        pcVar1 = (code *)swi(0x29);
        uVar4 = (*pcVar1)(8);
        puVar7 = auStack_60;
        goto LAB_00022b2f;
      }
      auStack_40[uVar10] = 0;
      iVar5 = (*(code *)(param_1 + uVar10 * 0x25)[0x1d])(param_1 + uVar10 * 0x25,local_48);
      if (iVar5 == 1) {
LAB_00022ad6:
        cVar9 = '\x01';
      }
      else if (iVar5 == 2) {
        auStack_40[uVar10] = 1;
        goto LAB_00022ad6;
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < *(byte *)(param_1 + 0x4a0));
  }
  puVar7 = auStack_68;
  if (cVar9 != '\0') {
    uVar4 = *(uint *)(*param_1 + 0x25f0);
    puVar7 = auStack_68;
    if ((uVar4 & 4) == 0) {
LAB_00022b2f:
      puVar6 = puVar7;
      puVar7 = puVar6;
      if ((uVar4 & 8) == 0) goto LAB_00022b69;
    }
    else {
      FUN_00015608(param_1,5);
    }
    puVar7 = puVar6;
    if (param_1[0x15] == 0) {
      pcVar1 = *(code **)(NvStorOsCBT + 0x70);
      *(undefined8 *)(puVar6 + -8) = 0x22b69;
      (*pcVar1)();
    }
    else {
      pcVar1 = *(code **)(NvStorOsCBT + 0xa0);
      *(undefined8 *)(puVar6 + -8) = 0x22b5a;
      (*pcVar1)();
    }
  }
LAB_00022b69:
  uVar10 = 0;
  if ((char)param_1[0x4a0] != '\0') {
    do {
      if (puVar7[uVar10 + 0x28] != '\0') {
        lVar2 = (param_1 + uVar10 * 0x25)[0x1c];
        pcVar1 = *(code **)(NvStorOsCBT + 400);
        *(undefined8 *)(puVar7 + -8) = 0x22b9f;
        (*pcVar1)(param_1 + uVar10 * 0x25,lVar2);
      }
      bVar8 = (char)uVar10 + 1;
      uVar10 = (ulonglong)bVar8;
    } while (bVar8 < *(byte *)(param_1 + 0x4a0));
  }
  *(undefined8 *)(puVar7 + -8) = 0x22bbb;
  return cVar9;
}



===== NvStorIntPortCheckInterruptSingleDevice @ 00022bd8 =====

undefined8 NvStorIntPortCheckInterruptSingleDevice(longlong *param_1,uint *param_2)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined8 uVar6;
  
  bVar2 = false;
  uVar5 = 0;
  if ((*(uint *)(*param_1 + 0x25f0) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0x25f0) & 8) != 0) {
      uVar5 = FUN_00015608(param_1,6);
    }
  }
  else {
    uVar5 = FUN_00015608(param_1,5);
    uVar5 = (uVar5 & 0xf000) << 4 | uVar5 >> 8 & 0xf;
  }
  if ((uVar5 & 0xf1 << ((*(byte *)(param_1 + 0x1b) & 1) << 4) & *param_2) != 0) {
    bVar2 = true;
    if (param_1[0x19] == 0) {
      (*(code *)*NvStorOsCBT)(*param_1,(short)param_1[3] + 7);
    }
    else {
      (*(code *)NvStorOsCBT[6])(*param_1,param_1[0x19] + 0x1c);
    }
  }
  bVar3 = (*(code *)*NvStorOsCBT)
                    (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + (short)param_1[0xb] + 2);
  if ((bVar3 & 4) != 0) {
    bVar2 = true;
    if (param_1[0x19] == 0) {
      (*(code *)*NvStorOsCBT)(*param_1,(short)param_1[3] + 7);
    }
    else {
      (*(code *)NvStorOsCBT[6])(*param_1,param_1[0x19] + 0x1c);
    }
    (*(code *)NvStorOsCBT[0xc])
              (*param_1,(ushort)*(byte *)(param_1 + 0x1b) * 8 + (short)param_1[0xb] + 2,bVar3);
  }
  if (bVar2) {
    lVar1 = param_1[1];
    if ((((lVar1 != 0) && ((*(ulonglong *)(lVar1 + 0x890) >> 0x17 & 1) != 0)) &&
        ((*(ulonglong *)(lVar1 + 0x890) >> 0x18 & 1) == 0)) &&
       ((*(code **)(lVar1 + 0x398) != (code *)0x0 &&
        (cVar4 = (**(code **)(lVar1 + 0x398))(lVar1,0), cVar4 != '\0')))) {
      return 2;
    }
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



===== NvStorIntPortDpcSingleDevice @ 00022d5c =====

void NvStorIntPortDpcSingleDevice(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 local_28 [32];
  
  if (param_1[1] != 0) {
    (**(code **)(NvStorOsCBT + 0x150))(*param_1,0,*(undefined1 *)(param_1 + 0x1b),local_28);
    lVar1 = param_1[1];
    if ((((*(ulonglong *)(lVar1 + 0x890) >> 0x17 & 1) != 0) &&
        ((*(ulonglong *)(lVar1 + 0x890) >> 0x18 & 1) == 0)) && ((*(byte *)(lVar1 + 0x898) & 1) == 0)
       ) {
      (**(code **)(lVar1 + 0x3a0))(lVar1);
    }
    (**(code **)(NvStorOsCBT + 0x158))(*param_1,0,*(undefined1 *)(param_1 + 0x1b),local_28);
  }
  return;
}



===== NvStorReqQueueInsert @ 00022ddc =====

void NvStorReqQueueInsert(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(uint *)(param_1 + 0x2c) & 2) == 0) {
    if ((int)param_2[0x12] == 0) {
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(longlong **)(param_1 + 0x48) = param_2;
    }
    puVar1 = *(undefined8 **)(param_1 + 0x10);
    param_2[1] = (longlong)puVar1;
    *param_2 = param_1 + 8;
    *puVar1 = param_2;
    *(longlong **)(param_1 + 0x10) = param_2;
    iVar2 = 0;
  }
  else {
    uVar3 = FUN_00023238(param_1,param_2);
    iVar2 = (int)uVar3;
  }
  if ((-1 < iVar2) &&
     (((*(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1, *(int *)(param_1 + 0x28) == 0 ||
       ((*(uint *)(param_1 + 0x2c) & 8) != 0)) || ((*(uint *)(param_1 + 0x2c) & 4) != 0)))) {
    NvStorReqQueueDispatch(param_1);
  }
  return;
}



===== NvStorReqQueueDispatch @ 00022e48 =====

undefined8 NvStorReqQueueDispatch(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  byte bVar4;
  longlong *plVar5;
  uint uVar6;
  char local_res8 [8];
  
  do {
    if (*(uint *)(param_1 + 0x24) <= *(uint *)(param_1 + 0x28)) {
      return 0;
    }
    plVar1 = (longlong *)(param_1 + 8);
    if ((longlong *)*plVar1 == plVar1) {
      return 0;
    }
    plVar5 = (longlong *)*plVar1;
    if (plVar5 == plVar1) {
      plVar5 = (longlong *)0x0;
    }
    FUN_00023460(param_1,(longlong)plVar5);
    local_res8[0] = *(char *)(param_1 + 0x20) + *(char *)(param_1 + 0x28);
    NvCfgElementSet(*(longlong *)(**(longlong **)plVar5[2] + 0x2820),
                    (longlong *)((undefined8 *)plVar5[2])[0xb6],'9',(ulonglong *)local_res8,1);
    *(undefined1 *)(param_1 + 0x50) = 0;
    if (*(int *)(param_1 + 0x28) != 0) {
      if (((*(uint *)(plVar5 + 0x18) & 0x20) == 0) ||
         (*(int *)((longlong)plVar5 + 0xc4) != *(int *)(param_1 + 0x34))) {
LAB_0002301f:
        *(undefined1 *)(param_1 + 0x50) = 1;
        return 0;
      }
      if ((*(uint *)(param_1 + 0x2c) & 1) != 0) {
        plVar3 = *(longlong **)(param_1 + 0x18);
        bVar4 = 0;
        uVar6 = 0;
        do {
          if (*plVar3 != 0) {
            if ((*(uint *)(*plVar3 + 0xc0) & 1) == 0) {
              bVar4 = bVar4 | 2;
            }
            else {
              bVar4 = bVar4 | 1;
            }
            if (bVar4 == 3) break;
          }
          uVar6 = uVar6 + 1;
          plVar3 = plVar3 + 1;
        } while (uVar6 < 0x20);
        uVar6 = *(uint *)(plVar5 + 0x18) & 1;
        if (((uVar6 != 0) && (bVar4 == 2)) || ((uVar6 == 0 && (bVar4 == 1)))) goto LAB_0002301f;
      }
    }
    plVar5 = (longlong *)*plVar1;
    lVar2 = *plVar5;
    *plVar1 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar1;
    if (plVar5 == *(longlong **)(param_1 + 0x40)) {
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    if (plVar5 == *(longlong **)(param_1 + 0x48)) {
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    else if ((*(uint *)(plVar5 + 0x18) & 0x2000) != 0) {
      *(longlong *)(param_1 + 0x38) = plVar5[7];
    }
    if ((longlong *)*plVar1 == plVar1) {
      plVar3 = (longlong *)0x0;
    }
    else {
      plVar3 = (longlong *)*plVar1;
      if (plVar3 == plVar1) {
        plVar3 = (longlong *)0x0;
      }
    }
    if (plVar3 == *(longlong **)(param_1 + 0x40)) {
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    if ((*(uint *)(plVar5 + 0x18) & 0x100) == 0) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
    }
    if (*(int *)((longlong)plVar5 + 0xc4) != *(int *)(param_1 + 0x34)) {
      *(int *)(param_1 + 0x34) = *(int *)((longlong)plVar5 + 0xc4);
      (**(code **)(plVar5[2] + 0x3a8))(plVar5[2],*(undefined4 *)((longlong)plVar5 + 0xc4));
    }
    (*(code *)plVar5[0x17])(plVar5[2],plVar5);
    if ((longlong *)*plVar1 == plVar1) {
      plVar3 = (longlong *)0x0;
    }
    else {
      plVar3 = (longlong *)*plVar1;
      if (plVar3 == plVar1) {
        plVar3 = (longlong *)0x0;
      }
    }
    if ((*(uint *)(param_1 + 0x2c) & 8) == 0) {
      if ((*(uint *)(param_1 + 0x2c) & 4) == 0) {
        return 0;
      }
      if ((*(uint *)(plVar5 + 0x18) & 0x20) == 0) {
        return 0;
      }
      if (plVar3 == (longlong *)0x0) {
        return 0;
      }
      if ((*(uint *)(plVar3 + 0x18) & 0x20) == 0) {
        return 0;
      }
    }
  } while( true );
}



===== NvStorReqQueueComplete @ 0002303c =====

ulonglong NvStorReqQueueComplete(undefined8 *param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined1 local_28 [32];
  
  uVar2 = 0;
  if ((*(uint *)(param_2 + 0xc0) & 0x1000) == 0) {
    (**(code **)(NvStorOsCBT + 0x150))(*param_1,1,0,local_28);
  }
  *(int *)(param_1 + 5) = *(int *)(param_1 + 5) + -1;
  if ((*(uint *)(param_2 + 0xc0) >> 10 & 1) == 0) {
    if ((*(uint *)(param_2 + 0xc0) >> 0x14 & 1) == 0) {
      uVar2 = NvStorReqQueueDispatch((longlong)param_1);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      puVar1 = (ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x890);
      *puVar1 = *puVar1 | 0x100000000000;
      (**(code **)(NvStorOsCBT + 0x1e0))
                (*(undefined8 *)**(undefined8 **)(param_2 + 0x10),NvStorReqQueueDispatchTimer,1);
    }
  }
  if ((*(uint *)(param_2 + 0xc0) >> 0xc & 1) == 0) {
    (**(code **)(NvStorOsCBT + 0x158))(*param_1,1,0,local_28);
  }
  else {
    *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) & 0xffffefff;
  }
  return uVar2;
}



===== NvStorReqQueueFlushEx @ 0002311c =====

undefined8
NvStorReqQueueFlushEx(longlong param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  plVar1 = (longlong *)(param_1 + 8);
  while ((longlong *)*plVar1 != plVar1) {
    plVar4 = (longlong *)*plVar1;
    lVar2 = *plVar4;
    *plVar1 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar1;
    if (*(uint *)((longlong)plVar4 + 0x84) != 0xffffffff) {
      NvStorReleaseTag((undefined8 *)plVar4[2],(ulonglong)*(uint *)((longlong)plVar4 + 0x84));
      if (plVar4[2] != 0) {
        *(undefined8 *)(plVar4[2] + 0x240 + (longlong)*(int *)((longlong)plVar4 + 0x84) * 8) = 0;
      }
      *(undefined4 *)((longlong)plVar4 + 0x84) = 0xffffffff;
    }
    if ((code *)plVar4[0x15] != (code *)0x0) {
      (*(code *)plVar4[0x15])(plVar4,param_2,param_4);
    }
  }
  lVar3 = 0;
  lVar2 = 0x20;
  do {
    lVar5 = *(longlong *)(lVar3 + *(longlong *)(param_1 + 0x18));
    if (lVar5 != 0) {
      if (*(uint *)(lVar5 + 0x84) != 0xffffffff) {
        NvStorReleaseTag(*(undefined8 **)(lVar5 + 0x10),(ulonglong)*(uint *)(lVar5 + 0x84));
        if (*(longlong *)(lVar5 + 0x10) != 0) {
          *(undefined8 *)
           (*(longlong *)(lVar5 + 0x10) + 0x240 + (longlong)*(int *)(lVar5 + 0x84) * 8) = 0;
        }
        *(undefined4 *)(lVar5 + 0x84) = 0xffffffff;
      }
      if (*(code **)(lVar5 + 0xa8) != (code *)0x0) {
        (**(code **)(lVar5 + 0xa8))(lVar5,param_2,param_4);
      }
    }
    lVar3 = lVar3 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  return 0;
}



===== FUN_00023238 @ 00023238 =====

undefined8 FUN_00023238(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  bool bVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong *plVar10;
  
  plVar1 = (longlong *)(param_1 + 8);
  *(undefined4 *)((longlong)param_2 + 0x94) = *(undefined4 *)(param_1 + 0x30);
  bVar5 = false;
  if ((longlong *)*plVar1 == plVar1) {
LAB_0002342a:
    if ((int)param_2[0x12] != 0) goto LAB_0002343a;
  }
  else {
    plVar8 = (longlong *)*plVar1;
    plVar10 = *(longlong **)(param_1 + 0x10);
    if (plVar8 == plVar1) {
      plVar8 = (longlong *)0x0;
    }
    if (plVar8 == (longlong *)0x0) goto LAB_0002342a;
    if ((int)param_2[0x12] != 0) {
      if (*(longlong **)(param_1 + 0x48) == (longlong *)0x0) {
        uVar2 = param_2[7];
        uVar3 = *(ulonglong *)(param_1 + 0x38);
        plVar7 = *(longlong **)(param_1 + 0x40);
        if (uVar2 < uVar3) {
          if (plVar7 == (longlong *)0x0) {
            uVar9 = plVar8[7];
            if (uVar3 <= uVar9) {
              *(longlong **)(param_1 + 0x40) = param_2;
              if ((int)param_2[0x12] == 0) {
                *(longlong **)(param_1 + 0x48) = param_2;
                *(undefined8 *)(param_1 + 0x40) = 0;
              }
              puVar6 = *(undefined8 **)(param_1 + 0x10);
              *param_2 = (longlong)plVar1;
              param_2[1] = (longlong)puVar6;
              *puVar6 = param_2;
              *(longlong **)(param_1 + 0x10) = param_2;
              goto LAB_000233e6;
            }
LAB_000232bb:
            if (uVar9 <= uVar2) goto LAB_0002337b;
            puVar6 = (undefined8 *)plVar8[1];
            *param_2 = (longlong)plVar8;
            param_2[1] = (longlong)puVar6;
            plVar8[1] = (longlong)param_2;
          }
          else {
            plVar8 = plVar7;
            if ((ulonglong)plVar7[7] <= uVar2) goto LAB_0002337b;
            *(longlong **)(param_1 + 0x40) = param_2;
            puVar6 = (undefined8 *)plVar7[1];
            *param_2 = (longlong)plVar7;
            param_2[1] = (longlong)puVar6;
            plVar7[1] = (longlong)param_2;
          }
          *puVar6 = param_2;
          goto LAB_000233e6;
        }
        if (plVar7 == (longlong *)0x0) {
          uVar9 = plVar8[7];
          if (uVar9 < uVar3) {
            *(longlong **)(param_1 + 0x40) = plVar8;
            puVar6 = (undefined8 *)plVar8[1];
            *param_2 = (longlong)plVar8;
            param_2[1] = (longlong)puVar6;
            plVar8[1] = (longlong)param_2;
            *puVar6 = param_2;
            bVar5 = true;
            goto LAB_000233e6;
          }
          goto LAB_000232bb;
        }
        plVar10 = (longlong *)plVar7[1];
        if ((plVar10 == plVar1) || (plVar10 == (longlong *)0x0)) {
          plVar10 = (longlong *)0x0;
        }
        if ((uVar2 < (ulonglong)plVar8[7]) &&
           ((plVar8 = (longlong *)plVar7[1], plVar8 == plVar1 || (plVar8 == (longlong *)0x0)))) {
          plVar8 = (longlong *)0x0;
        }
        bVar5 = true;
      }
      else {
        plVar8 = *(longlong **)(param_1 + 0x48);
      }
LAB_0002337b:
      if ((ulonglong)param_2[7] < (ulonglong)plVar10[7]) {
        while ((plVar10 = (longlong *)*plVar8, plVar10 != plVar1 && (plVar10 != (longlong *)0x0))) {
          if (plVar10 == *(longlong **)(param_1 + 0x40)) {
            if ((longlong *)*plVar1 == plVar1) {
              plVar7 = (longlong *)0x0;
            }
            else {
              plVar7 = (longlong *)*plVar1;
              if (plVar7 == plVar1) {
                plVar7 = (longlong *)0x0;
              }
            }
            if ((ulonglong)plVar7[7] <= (ulonglong)param_2[7]) break;
          }
          if ((ulonglong)param_2[7] < (ulonglong)plVar10[7]) break;
          plVar8 = plVar10;
        }
        *param_2 = (longlong)plVar10;
        param_2[1] = (longlong)plVar8;
        plVar10[1] = (longlong)param_2;
        *plVar8 = (longlong)param_2;
      }
      else {
        lVar4 = *plVar10;
        param_2[1] = (longlong)plVar10;
        *param_2 = lVar4;
        *(longlong **)(lVar4 + 8) = param_2;
        *plVar10 = (longlong)param_2;
      }
LAB_000233e6:
      while( true ) {
        param_2 = (longlong *)*param_2;
        if (param_2 == plVar1) {
          return 0;
        }
        if (param_2 == (longlong *)0x0) break;
        *(int *)((longlong)param_2 + 0x94) = *(int *)((longlong)param_2 + 0x94) + -1;
        if ((bVar5) && (param_2 == *(longlong **)(param_1 + 0x40))) {
          bVar5 = false;
        }
        if (*(int *)((longlong)param_2 + 0x94) == 0) {
          if (bVar5) {
            param_2 = *(longlong **)(param_1 + 0x40);
            bVar5 = false;
          }
          *(longlong **)(param_1 + 0x48) = param_2;
          *(undefined8 *)(param_1 + 0x40) = 0;
        }
      }
      return 0;
    }
  }
  *(longlong **)(param_1 + 0x48) = param_2;
  *(undefined8 *)(param_1 + 0x40) = 0;
LAB_0002343a:
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *param_2 = (longlong)plVar1;
  param_2[1] = (longlong)puVar6;
  *puVar6 = param_2;
  *(longlong **)(param_1 + 0x10) = param_2;
  return 0;
}



===== FUN_00023460 @ 00023460 =====

void FUN_00023460(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  bool bVar5;
  longlong lVar6;
  uint uVar7;
  uint local_res10 [2];
  byte local_res18 [8];
  int local_res20 [2];
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'%',(undefined8 *)local_res10
                  ,1);
  puVar3 = *(undefined8 **)(param_2 + 0x10);
  if (((*(uint *)(puVar3 + 0x112) >> 0x19 & 1) == 0) && ((char)local_res10[0] == '\0')) {
    return;
  }
  bVar2 = *(byte *)(param_2 + 0x40);
  if ((0x2e < bVar2) || ((0x450000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) == 0)) {
    if (0x36 < (byte)(bVar2 + 0x78)) {
      return;
    }
    if ((0x42000500000005U >> ((ulonglong)(byte)(bVar2 + 0x78) & 0x3f) & 1) == 0) {
      return;
    }
  }
  lVar6 = *(longlong *)(param_2 + 0x38);
  uVar7 = (uint)CONCAT11(*(undefined1 *)(param_2 + 0x47),*(undefined1 *)(param_2 + 0x48));
  NvCfgElementGet(*(longlong *)(*(longlong *)*puVar3 + 0x2820),(longlong *)puVar3[0xb6],'+',
                  (undefined8 *)local_res10,1);
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],',',(undefined8 *)local_res18
                  ,1);
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'-',(undefined8 *)&local_44,4
                 );
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'.',(undefined8 *)&local_3c,4
                 );
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'/',(undefined8 *)local_res20
                  ,4);
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'0',(undefined8 *)&local_40,4
                 );
  NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                  (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'1',(undefined8 *)&local_48,4
                 );
  if ((*(uint *)(param_2 + 0xc0) & 1) == 0) {
    if ((ulonglong)*(uint *)(param_1 + 0x70) + *(longlong *)(param_1 + 0x68) == lVar6) {
      piVar1 = (int *)(*(longlong *)(param_2 + 0x10) + 0x14);
      *piVar1 = *piVar1 + 1;
      if (local_res20[0] < *(int *)(*(longlong *)(param_2 + 0x10) + 0x14)) {
        *(int *)(*(longlong *)(param_2 + 0x10) + 0x14) = local_res20[0];
      }
    }
    else {
      piVar1 = (int *)(*(longlong *)(param_2 + 0x10) + 0x14);
      *piVar1 = *piVar1 - local_48;
      if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x14) < 0) {
        *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x14) = 0;
      }
    }
    *(longlong *)(param_1 + 0x68) = lVar6;
    *(uint *)(param_1 + 0x70) = uVar7;
  }
  else {
    if ((ulonglong)*(uint *)(param_1 + 0x60) + *(longlong *)(param_1 + 0x58) == lVar6) {
      piVar1 = (int *)(*(longlong *)(param_2 + 0x10) + 0x10);
      *piVar1 = *piVar1 + 1;
      if (local_res20[0] < *(int *)(*(longlong *)(param_2 + 0x10) + 0x10)) {
        *(int *)(*(longlong *)(param_2 + 0x10) + 0x10) = local_res20[0];
      }
    }
    else {
      piVar1 = (int *)(*(longlong *)(param_2 + 0x10) + 0x10);
      *piVar1 = *piVar1 - local_48;
      if (*(int *)(*(longlong *)(param_2 + 0x10) + 0x10) < 0) {
        *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x10) = 0;
      }
    }
    *(longlong *)(param_1 + 0x58) = lVar6;
    *(uint *)(param_1 + 0x60) = uVar7;
  }
  uVar7 = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x24) == 1) {
    lVar6 = *(longlong *)(param_2 + 0x10);
    if (uVar7 <= (local_res10[0] & 0xff)) goto LAB_000236de;
LAB_0002371e:
    *(int *)(lVar6 + 0x24) = *(int *)(lVar6 + 0x24) + 1;
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x10);
    if (uVar7 <= local_res18[0]) goto LAB_0002371e;
LAB_000236de:
    *(undefined4 *)(lVar6 + 0x24) = 0;
  }
  bVar5 = false;
  if ((*(uint *)(param_1 + 0x24) == 1) &&
     (lVar6 = *(longlong *)(param_2 + 0x10), local_44 <= *(uint *)(lVar6 + 0x24))) {
    if ((*(int *)(lVar6 + 0x10) < local_40) && (*(int *)(lVar6 + 0x14) < local_40)) {
      *(uint *)(param_1 + 0x24) = (uint)*(ushort *)(lVar6 + 0x220);
      goto LAB_00023739;
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x24) < 2) ||
       (*(uint *)(*(longlong *)(param_2 + 0x10) + 0x24) < local_3c)) goto LAB_0002379e;
    *(undefined4 *)(param_1 + 0x24) = 1;
LAB_00023739:
    bVar5 = true;
  }
  *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x24) = 0;
  if (bVar5) {
    NvCfgElementGet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                    (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'=',
                    (undefined8 *)local_res10,4);
    local_res10[0] = local_res10[0] + 1;
    NvCfgElementSet(*(longlong *)(*(longlong *)**(undefined8 **)(param_2 + 0x10) + 0x2820),
                    (longlong *)(*(undefined8 **)(param_2 + 0x10))[0xb6],'=',
                    (ulonglong *)local_res10,4);
  }
LAB_0002379e:
  if (*(uint *)(param_1 + 0x24) == 1) {
    uVar4 = *(ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x890);
    if ((uVar4 & 0x4000000) != 0) {
      *(ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x890) = uVar4 & 0xfffffffffbffffff;
      return;
    }
  }
  if (1 < *(uint *)(param_1 + 0x24)) {
    uVar4 = *(ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x890);
    if ((uVar4 & 0x4000000) == 0) {
      *(ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x890) = uVar4 | 0x4000000;
    }
  }
  return;
}



===== NvStorReqQueueDispatchTimer @ 000237f8 =====

void NvStorReqQueueDispatchTimer(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x2500) != '\0') {
    do {
      lVar3 = (ulonglong)uVar5 * 0x128 + param_1;
      if ((lVar3 != 0) && (uVar4 = 0, *(short *)(lVar3 + 0x10) != 0)) {
        do {
          lVar1 = *(longlong *)(lVar3 + 8 + (ulonglong)uVar4 * 8);
          if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_00023867:
            if ((lVar1 != 0) && ((*(ulonglong *)(lVar1 + 0x890) & 0x100000000000) != 0)) {
              *(ulonglong *)(lVar1 + 0x890) = *(ulonglong *)(lVar1 + 0x890) & 0xffffefffffffffff;
              NvStorReqQueueDispatch(lVar1 + 0x1a8);
            }
          }
          else {
            cVar2 = (**(code **)(NvStorOsCBT + 0x208))(lVar3,uVar4,1);
            if (cVar2 != '\0') goto LAB_00023867;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(ushort *)(lVar3 + 0x10));
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(byte *)(param_1 + 0x2500));
  }
  return;
}



===== NvStorGetNextTag @ 000238d8 =====

undefined8 NvStorGetNextTag(longlong *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if ((*(uint *)(*(longlong *)*param_1 + 0x25f0) & 1) == 0) {
    uVar3 = FUN_00023a3c(param_1,param_2);
  }
  else {
    uVar3 = 0;
    uVar2 = 0;
    if (*(uint *)(param_1 + 0x6a) != 0) {
      do {
        if ((*(uint *)(param_1[0x69] + (ulonglong)(uVar2 >> 5) * 4) >> ((byte)uVar2 & 0x1f) & 1) ==
            0) goto LAB_0002393f;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x6a));
    }
    uVar2 = 0xffffffff;
LAB_0002393f:
    if (uVar2 == 0xffffffff) {
      uVar3 = 0x80000003;
    }
    else {
      puVar1 = (uint *)(param_1[0x69] + (ulonglong)(uVar2 >> 5) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar2 & 0x1f);
      *param_2 = uVar2;
    }
  }
  return uVar3;
}



===== NvStorReleaseTag @ 00023984 =====

undefined8 NvStorReleaseTag(undefined8 *param_1,ulonglong param_2)

{
  uint *puVar1;
  
  if ((*(uint *)(*(longlong *)*param_1 + 0x25f0) & 1) != 0) {
    puVar1 = (uint *)(param_1[0x69] + ((param_2 & 0xffffffff) >> 5) * 4);
    *puVar1 = *puVar1 & ~(1 << ((byte)param_2 & 0x1f));
  }
  return 0;
}



===== NvStorInitializeTags @ 000239c0 =====

void NvStorInitializeTags(longlong *param_1,uint param_2)

{
  uint *puVar1;
  
  if ((*(uint *)(*(longlong *)*param_1 + 0x25f0) & 1) == 0) {
    puVar1 = (uint *)((longlong *)*param_1)[0x1e];
    *puVar1 = param_2;
    puVar1[1] = param_2;
  }
  else {
    (**(code **)(NvStorOsCBT + 0x110))(param_1 + 0x6b,(uint)((param_2 & 7) != 0) + (param_2 >> 3));
    param_1[0x69] = (longlong)(param_1 + 0x6b);
    *(uint *)(param_1 + 0x6a) = param_2;
  }
  return;
}



===== FUN_00023a3c @ 00023a3c =====

undefined8 FUN_00023a3c(longlong *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(*param_1 + 0xf0);
  *param_2 = 0xffffffff;
  uVar2 = (**(code **)(NvStorOsCBT + 0x40))
                    (*(undefined8 *)*param_1,*(longlong *)(puVar1 + 10) + 0x38);
  uVar3 = (**(code **)(NvStorOsCBT + 0x40))
                    (*(undefined8 *)*param_1,*(longlong *)(puVar1 + 10) + 0x34);
  for (uVar4 = *puVar1; uVar4 < puVar1[1]; uVar4 = uVar4 + 1) {
    uVar6 = 1 << ((byte)uVar4 & 0x1f);
    if ((((uVar2 & uVar6) == 0) && ((uVar3 & uVar6) == 0)) &&
       (param_1[(ulonglong)uVar4 + 0x48] == 0)) {
      *param_2 = uVar4;
      break;
    }
  }
  if (puVar1[1] <= uVar4) {
    uVar5 = 0;
    if (*puVar1 != 0) {
      do {
        uVar4 = 1 << ((byte)uVar5 & 0x1f);
        if ((((uVar2 & uVar4) == 0) && ((uVar3 & uVar4) == 0)) && (param_1[uVar5 + 0x48] == 0)) {
          *param_2 = (uint)uVar5;
          break;
        }
        uVar4 = (uint)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *puVar1);
    }
  }
  *puVar1 = *param_2;
  return 0;
}



===== NvStorTimerTickController @ 00023b18 =====

void NvStorTimerTickController(longlong param_1,undefined *param_2,undefined8 param_3)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  *(char *)(param_1 + 0x2918) = *(char *)(param_1 + 0x2918) + '\x01';
  if (9 < *(byte *)(param_1 + 0x2918)) {
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0x2918) = 0;
    if (*(char *)(param_1 + 0x2500) != '\0') {
      do {
        plVar1 = (longlong *)(uVar3 * 0x128 + param_1);
        if (plVar1 != (longlong *)0x0) {
          FUN_00023b74(plVar1,param_2,param_3);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(byte *)(param_1 + 0x2500));
    }
  }
  return;
}



===== FUN_00023b74 @ 00023b74 =====

void FUN_00023b74(longlong *param_1,undefined *param_2,undefined8 param_3)

{
  byte bVar1;
  longlong *plVar2;
  bool bVar3;
  longlong lVar4;
  char cVar5;
  ulonglong uVar6;
  byte *pbVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  
  uVar9 = (undefined1)param_3;
  uVar10 = (undefined7)((ulonglong)param_3 >> 8);
  bVar3 = true;
  if ((*(uint *)(param_1 + 0x24) & 0x40) != 0) {
    FUN_00023f08(param_1,param_2,param_3);
    if ((((*(byte *)((longlong)param_1 + 0x124) & 0x20) != 0) &&
        ((*(byte *)((longlong)param_1 + 0x124) & 0xc) != 0)) &&
       (bVar1 = *(byte *)(param_1 + 0x1b), (&DAT_00035650)[bVar1] = (&DAT_00035650)[bVar1] + '\x10',
       ((&DAT_00035650)[bVar1] & 0x30) == 0)) {
      (**(code **)(*param_1 + 0x2768))(param_1);
    }
  }
  if (((*(uint *)(param_1 + 0x24) & 0x10) != 0) && ((*(uint *)(*param_1 + 0x25f0) & 0x1000) != 0)) {
    param_2 = (undefined *)(*(longlong *)(param_1[0x1e] + 0x28) + 0x20);
    uVar6 = (**(code **)(NvStorOsCBT + 0x30))();
    lVar4 = NvStorOsCBT;
    if ((uVar6 & 0x88) == 0) {
      param_2 = (undefined *)(ulonglong)*(byte *)(param_1 + 0x1b);
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffffef;
      (**(code **)(lVar4 + 0x188))(*param_1);
    }
  }
  uVar8 = 0;
  if ((short)param_1[2] != 0) {
    do {
      plVar2 = (longlong *)param_1[(ulonglong)uVar8 + 1];
      if (*(code **)(NvStorOsCBT + 0x208) == (code *)0x0) {
LAB_00023c68:
        if (((plVar2 != (longlong *)0x0) && (uVar6 = plVar2[0x112], (uVar6 >> 0x17 & 1) != 0)) &&
           (((uVar6 & 0x200000000) == 0 && ((uVar6 >> 0x18 & 1) == 0)))) {
          if ((uVar6 & 0x80000000) != 0) {
            FUN_00023df0(plVar2,param_2,CONCAT71(uVar10,uVar9));
          }
          if ((*(byte *)(plVar2 + 0x113) & 1) != 0) {
            if ((((plVar2[0x112] & 0x20U) == 0) || (((ulonglong)plVar2[0x112] >> 0x18 & 1) != 0)) ||
               (*(code **)(*(longlong *)*plVar2 + 0x2810) == (code *)0x0)) {
              *(undefined1 *)(plVar2 + 0x113) = 0;
            }
            else {
              (**(code **)(*(longlong *)*plVar2 + 0x2810))(plVar2);
            }
            if (((*(byte *)(plVar2 + 0x113) & 1) == 0) &&
               (param_2 = *(undefined **)(NvStorOsCBT + 0x218), (code *)param_2 != (code *)0x0)) {
              (*(code *)param_2)(plVar2);
            }
          }
          bVar3 = (bool)(bVar3 & (*(uint *)(plVar2 + 0x112) & 0x10000000) != 0);
          if (((*param_1 != 0) && ((*(uint *)(*param_1 + 0x25f0) >> 0x16 & 1) != 0)) &&
             (plVar2[1] != 0)) {
            if ((*(byte *)(plVar2[1] + 0x20) & 0x10) != 0) {
              bVar3 = false;
            }
          }
          if ((plVar2[1] != 0) && ((*(byte *)((longlong)param_1 + 0x124) & 8) != 0)) {
            if ((*(byte *)(plVar2[1] + 0x20) & 0x40) != 0) {
              bVar3 = false;
            }
          }
        }
      }
      else {
        uVar9 = 1;
        param_2 = (undefined *)(ulonglong)uVar8;
        cVar5 = (**(code **)(NvStorOsCBT + 0x208))(param_1);
        if (cVar5 != '\0') goto LAB_00023c68;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ushort *)(param_1 + 2));
  }
  bVar1 = *(byte *)((longlong)param_1 + 0x124);
  if ((((bVar1 & 0xc) != 0) && ((bVar1 & 0xc0) == 0)) && (bVar3)) {
    pbVar7 = &DAT_00035650 + *(byte *)(param_1 + 0x1b);
    if ((bVar1 & 0x20) == 0) {
      *pbVar7 = 1;
    }
    else {
      *pbVar7 = *pbVar7 ^ 1;
    }
    if ((*pbVar7 & 1) != 0) {
      if ((bVar1 & 4) == 0) {
        if (((bVar1 & 8) != 0) && (*param_1 != 0)) {
          (**(code **)(*param_1 + 0x2760))(param_1);
        }
      }
      else if (*param_1 != 0) {
        (**(code **)(*param_1 + 0x2758))(param_1);
      }
    }
  }
  return;
}



===== FUN_00023df0 @ 00023df0 =====

void FUN_00023df0(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  char cVar2;
  
  plVar1 = (longlong *)*param_1;
  cVar2 = (**(code **)(*plVar1 + 0x27c8))(plVar1);
  if (cVar2 == '\0') {
    if (*(char *)((longlong)param_1 + 0x256d) != '\0') {
      *(undefined1 *)((longlong)param_1 + 0x256d) = 0;
      return;
    }
    if (*(char *)((longlong)param_1 + 0x256e) != '\x01') {
      if ((*(byte *)((longlong)plVar1 + 0x124) & 8) != 0) {
        NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000015,param_3,1);
        (**(code **)(*plVar1 + 0x2770))(plVar1);
      }
      *(undefined1 *)((longlong)param_1 + 0x256e) = 1;
      return;
    }
    param_1[0x112] = param_1[0x112] | 0x1000000;
    plVar1[(ulonglong)*(byte *)((longlong)param_1 + 0x222) + 1] = 0;
    (**(code **)(*plVar1 + 0x2770))(plVar1);
    (**(code **)(*plVar1 + 0x27d0))(plVar1);
    NvStorReqQueueFlushEx((longlong)(param_1 + 0x35),0x80000010,param_3,1);
    (**(code **)(NvStorOsCBT + 0x188))(*plVar1,(char)plVar1[0x1b]);
    if (*(code **)(NvStorOsCBT + 0x1e8) != (code *)0x0) {
      (**(code **)(NvStorOsCBT + 0x1e8))(param_1,0,5);
    }
  }
  *(undefined2 *)((longlong)param_1 + 0x256d) = 1;
  param_1[0x112] = param_1[0x112] & 0xffffffff7fffffff;
  return;
}



===== FUN_00023f08 @ 00023f08 =====

void FUN_00023f08(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  bool bVar4;
  char cVar5;
  byte bVar6;
  ulonglong uVar7;
  
  uVar7 = 0;
  do {
    lVar1 = param_1[uVar7 + 1];
    bVar4 = false;
    if (lVar1 != 0) {
      uVar2 = *(ulonglong *)(lVar1 + 0x890);
      if ((uVar2 & 0x80000000) != 0) {
        return;
      }
      if ((uVar2 >> 0x17 & 1) == 0) {
        return;
      }
      bVar4 = false;
      if ((uVar2 >> 0x18 & 1) == 0) {
        bVar4 = true;
      }
    }
    pcVar3 = *(code **)(*param_1 + 0x27c8);
    if (pcVar3 == (code *)0x0) {
      return;
    }
    if (bVar4) {
      cVar5 = (*pcVar3)();
      if (cVar5 != '\0') {
        return;
      }
      NvStorReqQueueFlushEx(lVar1 + 0x1a8,0x80000015,param_3,1);
      (**(code **)(*param_1 + 0x2770))();
      *(ulonglong *)(lVar1 + 0x890) = *(ulonglong *)(lVar1 + 0x890) | 0x80000000;
    }
    else {
      cVar5 = (*pcVar3)(param_1);
      lVar1 = NvStorOsCBT;
      if (cVar5 == '\0') {
        return;
      }
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x10;
      (**(code **)(lVar1 + 0x188))(*param_1,(char)param_1[0x1b]);
    }
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
  } while (bVar6 == 0);
  return;
}



===== NvIoHistoryQueueAdd @ 00023ff8 =====

undefined8 NvIoHistoryQueueAdd(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ushort uVar4;
  longlong lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  if ((param_2[1] != 0) && (param_2[2] != 0)) {
    if (*(short *)(param_1 + 0x1852) == 0x100) {
      uVar1 = (ulonglong)*(ushort *)(param_1 + 0x1850);
      if (*(int *)(param_1 + uVar1 * 0x18) == 0) {
        *(int *)(param_1 + 0x1860) = *(int *)(param_1 + 0x1860) + -1;
        *(int *)(param_1 + 0x1868) =
             *(int *)(param_1 + 0x1868) - *(int *)(param_1 + 4 + uVar1 * 0x18);
        *(longlong *)(param_1 + 0x1870) =
             *(longlong *)(param_1 + 0x1870) +
             (*(longlong *)(param_1 + 8 + uVar1 * 0x18) -
             *(longlong *)(param_1 + 0x10 + uVar1 * 0x18));
      }
      else {
        *(int *)(param_1 + 0x1864) = *(int *)(param_1 + 0x1864) + -1;
        *(int *)(param_1 + 0x186c) =
             *(int *)(param_1 + 0x186c) - *(int *)(param_1 + 4 + uVar1 * 0x18);
        *(longlong *)(param_1 + 0x1878) =
             *(longlong *)(param_1 + 0x1878) +
             (*(longlong *)(param_1 + 8 + uVar1 * 0x18) -
             *(longlong *)(param_1 + 0x10 + uVar1 * 0x18));
      }
    }
    lVar5 = 3;
    puVar3 = (undefined8 *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x1850) * 0x18);
    lVar2 = (longlong)param_2 - (longlong)puVar3;
    do {
      *puVar3 = *(undefined8 *)(lVar2 + (longlong)puVar3);
      puVar3 = puVar3 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    if (*(ushort *)(param_1 + 0x1852) < 0x100) {
      *(ushort *)(param_1 + 0x1852) = *(ushort *)(param_1 + 0x1852) + 1;
    }
    local_38 = *param_2;
    uStack_30 = param_2[1];
    local_28 = param_2[2];
    NvIoHistoryQueueFindBucket(param_1,(int *)&local_38);
    uVar1 = (ulonglong)*(ushort *)(param_1 + 0x1850);
    if (*(int *)(param_1 + uVar1 * 0x18) == 0) {
      *(int *)(param_1 + 0x1860) = *(int *)(param_1 + 0x1860) + 1;
      *(int *)(param_1 + 0x1868) = *(int *)(param_1 + 0x1868) + *(int *)(param_1 + 4 + uVar1 * 0x18)
      ;
      *(longlong *)(param_1 + 0x1870) =
           *(longlong *)(param_1 + 0x1870) +
           (*(longlong *)(param_1 + 0x10 + uVar1 * 0x18) - *(longlong *)(param_1 + 8 + uVar1 * 0x18)
           );
    }
    else {
      *(int *)(param_1 + 0x1864) = *(int *)(param_1 + 0x1864) + 1;
      *(int *)(param_1 + 0x186c) = *(int *)(param_1 + 0x186c) + *(int *)(param_1 + 4 + uVar1 * 0x18)
      ;
      *(longlong *)(param_1 + 0x1878) =
           *(longlong *)(param_1 + 0x1878) +
           (*(longlong *)(param_1 + 0x10 + uVar1 * 0x18) - *(longlong *)(param_1 + 8 + uVar1 * 0x18)
           );
    }
    uVar4 = *(ushort *)(param_1 + 0x1850) + 1;
    *(ushort *)(param_1 + 0x1850) = uVar4;
    *(uint *)(param_1 + 0x1854) =
         (uint)(*(int *)(param_1 + 0x186c) + *(int *)(param_1 + 0x1868)) /
         (uint)*(ushort *)(param_1 + 0x1852);
    *(ulonglong *)(param_1 + 0x1858) =
         (ulonglong)(*(longlong *)(param_1 + 0x1878) + *(longlong *)(param_1 + 0x1870)) /
         (ulonglong)*(ushort *)(param_1 + 0x1852);
    if (0xff < uVar4) {
      *(undefined2 *)(param_1 + 0x1850) = 0;
    }
  }
  return 0;
}



===== NvIoHistoryQueueFindBucket @ 000241a8 =====

undefined8 NvIoHistoryQueueFindBucket(longlong param_1,int *param_2)

{
  int *piVar1;
  byte bVar2;
  ulonglong uVar3;
  
  if (((*(longlong *)(param_1 + 0x1800) == 0) && (*(int *)(param_1 + 0x1808) == 0)) &&
     (*(int *)(param_1 + 0x180c) == 0)) {
    *(undefined8 *)(param_1 + 0x1840) = *(undefined8 *)(param_2 + 2);
    NvIoHistoryQueueBucketShift(param_1,4);
  }
  uVar3 = (ulonglong)(*(longlong *)(param_2 + 4) - *(longlong *)(param_1 + 0x1800)) /
          *(ulonglong *)(param_1 + 0x1880);
  bVar2 = (byte)uVar3;
  if (4 < bVar2) {
    if (4 < (int)(((uint)uVar3 & 0xff) - 4)) {
      *(undefined8 *)(param_1 + 0x1800) = *(undefined8 *)(param_2 + 2);
    }
    NvIoHistoryQueueBucketShift(param_1,bVar2 - 4);
    uVar3 = (ulonglong)(byte)(bVar2 - 6);
  }
  if (4 < (byte)uVar3) {
    uVar3 = (ulonglong)(byte)((byte)uVar3 + (char)(((uint)uVar3 & 0xff) / 5) * -5);
  }
  if (*param_2 == 0) {
    piVar1 = (int *)(param_1 + 0x1808 + (uVar3 & 0xff) * 0x10);
    *piVar1 = *piVar1 + param_2[1];
  }
  else {
    piVar1 = (int *)(param_1 + 0x180c + (uVar3 & 0xff) * 0x10);
    *piVar1 = *piVar1 + param_2[1];
  }
  return 0;
}



===== NvIoHistoryQueueBucketShift @ 00024280 =====

void NvIoHistoryQueueBucketShift(longlong param_1,byte param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  byte bVar6;
  
  bVar6 = 0;
  if (0 < (int)(5 - (uint)param_2)) {
    do {
      uVar4 = (ulonglong)bVar6;
      bVar6 = bVar6 + 1;
      lVar1 = param_2 + uVar4;
      *(undefined8 *)(param_1 + (uVar4 + 0x180) * 0x10) =
           *(undefined8 *)(param_1 + (lVar1 + 0x180) * 0x10);
      *(undefined4 *)(param_1 + 0x1808 + uVar4 * 0x10) =
           *(undefined4 *)(param_1 + 0x1808 + lVar1 * 0x10);
      *(undefined4 *)(param_1 + 0x180c + uVar4 * 0x10) =
           *(undefined4 *)(param_1 + 0x180c + lVar1 * 0x10);
    } while ((int)(uint)bVar6 < (int)(5 - (uint)param_2));
    if (4 < bVar6) {
      return;
    }
  }
  puVar3 = (undefined4 *)(param_1 + 0x1808 + (ulonglong)bVar6 * 0x10);
  uVar5 = (ulonglong)(byte)(5 - bVar6);
  uVar4 = (ulonglong)bVar6;
  do {
    lVar1 = *(longlong *)(param_1 + 0x1880);
    lVar2 = *(longlong *)(param_1 + 0x1800);
    *puVar3 = 0;
    puVar3[1] = 0;
    *(ulonglong *)(puVar3 + -2) = uVar4 * lVar1 + lVar2;
    puVar3 = puVar3 + 4;
    uVar5 = uVar5 - 1;
    uVar4 = uVar4 + 1;
  } while (uVar5 != 0);
  return;
}



===== NvCfgEntityCreate @ 00024350 =====

undefined8
NvCfgEntityCreate(longlong param_1,longlong *param_2,undefined4 param_3,char *param_4,
                 longlong param_5,undefined8 *param_6,undefined8 *param_7)

{
  char *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  char *pcVar5;
  
  if (((param_1 == 0) || (param_2 == (longlong *)0x0)) || (param_6 == (undefined8 *)0x0)) {
    uVar3 = 0x80000008;
  }
  else if (*param_2 == param_1) {
    param_6[4] = 0;
    param_6[3] = param_5;
    *param_6 = param_2;
    *(undefined4 *)(param_6 + 1) = param_3;
    param_6[2] = param_4;
    *param_7 = param_6;
    if (*param_4 != -1) {
      pcVar5 = param_4 + 0x28;
      do {
        FUN_000247fc((undefined8 *)((ulonglong)*(uint *)(pcVar5 + -0x1c) + param_5),(longlong)pcVar5
                     ,*(uint *)(pcVar5 + -0x20));
        pcVar1 = pcVar5 + 0x100;
        pcVar5 = pcVar5 + 0x128;
      } while (*pcVar1 != -1);
    }
    for (puVar4 = (undefined8 *)param_2[1]; puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)*puVar4) {
      iVar2 = (*(code *)puVar4[-1])(0,puVar4[-2],param_6);
      if (iVar2 < 0) break;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80000014;
  }
  return uVar3;
}



===== NvCfgEntityDestroy @ 00024404 =====

undefined8 NvCfgEntityDestroy(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_2 == (longlong *)0x0) {
    uVar3 = 0x80000008;
  }
  else {
    plVar1 = (longlong *)*param_2;
    if (plVar1 == (longlong *)0x0) {
      uVar3 = 0x80000013;
    }
    else if (*plVar1 == param_1) {
      for (puVar4 = (undefined8 *)plVar1[1]; puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        iVar2 = (*(code *)puVar4[-1])(1,puVar4[-2],param_2);
        if (iVar2 < 0) break;
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0x80000014;
    }
  }
  return uVar3;
}



===== NvCfgEntityObserverCreate @ 00024468 =====

undefined8
NvCfgEntityObserverCreate
          (undefined8 param_1,longlong param_2,longlong param_3,longlong *param_4,longlong param_5,
          undefined8 *param_6)

{
  longlong *plVar1;
  
  if ((param_2 == 0) || (param_4 == (longlong *)0x0)) {
    return 0x80000008;
  }
  param_4[2] = param_3;
  *param_4 = param_2;
  param_4[1] = param_5;
  plVar1 = param_4 + 3;
  *plVar1 = 0;
  if (plVar1 != (longlong *)0x0) {
    if (*(longlong *)(param_2 + 0x20) == 0) {
      *(longlong **)(param_2 + 0x20) = plVar1;
      *plVar1 = 0;
    }
    else {
      *plVar1 = *(longlong *)(param_2 + 0x20);
      *(longlong **)(param_2 + 0x20) = plVar1;
    }
  }
  *param_6 = param_4;
  return 0;
}



===== NvCfgEntityObserverDestroy @ 000244bc =====

undefined8 NvCfgEntityObserverDestroy(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  bool bVar4;
  
  if (param_2 == (longlong *)0x0) {
    return 0x80000008;
  }
  lVar1 = *param_2;
  if (lVar1 == 0) {
    return 0x80000013;
  }
  if (param_2 != (longlong *)0xffffffffffffffe8) {
    plVar3 = *(longlong **)(lVar1 + 0x20);
    plVar2 = (longlong *)*plVar3;
    if (plVar3 == param_2 + 3) {
      *(longlong **)(lVar1 + 0x20) = plVar2;
    }
    else {
      while (plVar2 != (longlong *)0x0) {
        bVar4 = plVar2 == param_2 + 3;
        plVar2 = (longlong *)*plVar2;
        if (bVar4) {
          *plVar3 = (longlong)plVar2;
          return 0;
        }
        plVar3 = (longlong *)*plVar3;
      }
    }
  }
  return 0;
}



===== NvCfgElementGet @ 0002450c =====

uint NvCfgElementGet(longlong param_1,longlong *param_2,char param_3,undefined8 *param_4,
                    uint param_5)

{
  char *pcVar1;
  
  if ((param_1 != 0) && (param_2 != (longlong *)0x0)) {
    if ((longlong *)*param_2 == (longlong *)0x0) {
      return 0x80000013;
    }
    pcVar1 = (char *)param_2[2];
    if (pcVar1 == (char *)0x0) {
LAB_00024541:
      if (pcVar1 != (char *)0x0) {
        if ((*(longlong *)*param_2 != param_1) && ((*(uint *)(pcVar1 + 0x10) & 1) == 0)) {
          return 0x80000014;
        }
        if (param_5 < *(uint *)(pcVar1 + 8)) {
          return 0x80000004;
        }
        FUN_000247fc(param_4,(ulonglong)*(uint *)(pcVar1 + 0xc) + param_2[3],param_5);
        return -(uint)(*(uint *)(pcVar1 + 8) < param_5) & 0x80000005;
      }
    }
    else {
      for (; *pcVar1 != -1; pcVar1 = pcVar1 + 0x128) {
        if (*pcVar1 == param_3) goto LAB_00024541;
      }
    }
  }
  return 0x80000008;
}



===== NvCfgElementSetStringType @ 000245a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NvCfgElementSetStringType(longlong param_1,undefined1 *param_2,longlong param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined1 auStack_148 [32];
  undefined8 local_128 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  puVar4 = (undefined8 *)((ulonglong)*(uint *)(param_2 + 0xc) + *(longlong *)(param_1 + 0x18));
  FUN_000247fc(local_128,(longlong)puVar4,*(uint *)(param_2 + 8));
  FUN_000247fc(puVar4,param_3,*(uint *)(param_2 + 8));
  uVar1 = *param_2;
  iVar2 = 0;
  for (puVar4 = *(undefined8 **)(param_1 + 0x20); puVar4 != (undefined8 *)0x0;
      puVar4 = (undefined8 *)*puVar4) {
    iVar2 = (*(code *)puVar4[-1])(0,puVar4[-2],uVar1);
    if (iVar2 < 0) goto LAB_0002462a;
  }
  if (iVar2 < 0) {
LAB_0002462a:
    FUN_000247fc((undefined8 *)((ulonglong)*(uint *)(param_2 + 0xc) + *(longlong *)(param_1 + 0x18))
                 ,(longlong)local_128,*(uint *)(param_2 + 8));
    uVar3 = 0x80000013;
  }
  else {
    uVar3 = -(uint)(*(uint *)(param_2 + 8) < param_4) & 0x80000004;
  }
  return uVar3;
}



===== NvCfgElementSet @ 0002467c =====

uint NvCfgElementSet(longlong param_1,longlong *param_2,char param_3,ulonglong *param_4,uint param_5
                    )

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  ulonglong local_res8;
  
  if ((param_1 == 0) || (param_2 == (longlong *)0x0)) goto LAB_0002469c;
  if ((longlong *)*param_2 == (longlong *)0x0) {
LAB_000246b3:
    uVar3 = 0x80000013;
  }
  else {
    pcVar4 = (char *)param_2[2];
    if (pcVar4 == (char *)0x0) {
LAB_000246c6:
      if (pcVar4 != (char *)0x0) {
        if ((*(longlong *)*param_2 != param_1) && ((*(uint *)(pcVar4 + 0x10) & 2) == 0)) {
          return 0x80000014;
        }
        uVar3 = *(uint *)(pcVar4 + 8);
        if (param_5 < uVar3) {
          return 0x80000005;
        }
        if (*(int *)(pcVar4 + 4) != 0) {
          uVar3 = NvCfgElementSetStringType((longlong)param_2,pcVar4,(longlong)param_4,param_5);
          return uVar3;
        }
        local_res8 = 0;
        if (uVar3 == 1) {
          local_res8 = (ulonglong)(byte)*param_4;
LAB_00024748:
          if ((local_res8 < *(ulonglong *)(pcVar4 + 0x18)) ||
             (*(ulonglong *)(pcVar4 + 0x20) < local_res8)) {
            return 0x80000007;
          }
        }
        else {
          if (uVar3 == 2) {
            local_res8 = (ulonglong)(ushort)*param_4;
            goto LAB_00024748;
          }
          if (uVar3 == 4) {
            local_res8 = (ulonglong)(uint)*param_4;
            goto LAB_00024748;
          }
          if (uVar3 == 8) {
            local_res8 = *param_4;
            goto LAB_00024748;
          }
        }
        puVar5 = (undefined8 *)((ulonglong)*(uint *)(pcVar4 + 0xc) + param_2[3]);
        FUN_000247fc(&local_res8,(longlong)puVar5,uVar3);
        FUN_000247fc(puVar5,(longlong)param_4,uVar3);
        cVar1 = *pcVar4;
        iVar2 = 0;
        for (puVar5 = (undefined8 *)param_2[4]; puVar5 != (undefined8 *)0x0;
            puVar5 = (undefined8 *)*puVar5) {
          iVar2 = (*(code *)puVar5[-1])(0,puVar5[-2],cVar1);
          if (iVar2 < 0) goto LAB_000247b1;
        }
        if (-1 < iVar2) {
          return -(uint)(*(uint *)(pcVar4 + 8) < param_5) & 0x80000004;
        }
LAB_000247b1:
        FUN_000247fc((undefined8 *)((ulonglong)*(uint *)(pcVar4 + 0xc) + param_2[3]),
                     (longlong)&local_res8,*(uint *)(pcVar4 + 8));
        goto LAB_000246b3;
      }
    }
    else {
      for (; *pcVar4 != -1; pcVar4 = pcVar4 + 0x128) {
        if (*pcVar4 == param_3) goto LAB_000246c6;
      }
    }
LAB_0002469c:
    uVar3 = 0x80000008;
  }
  return uVar3;
}



===== FUN_000247fc @ 000247fc =====

void FUN_000247fc(undefined8 *param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if ((param_3 & 7) == 0) {
    if (param_3 >> 3 != 0) {
      lVar1 = param_2 - (longlong)param_1;
      uVar2 = (ulonglong)(param_3 >> 3);
      do {
        *param_1 = *(undefined8 *)(lVar1 + (longlong)param_1);
        param_1 = param_1 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      return;
    }
  }
  else if ((param_3 & 3) == 0) {
    if (param_3 >> 2 != 0) {
      lVar1 = param_2 - (longlong)param_1;
      uVar2 = (ulonglong)(param_3 >> 2);
      do {
        *(undefined4 *)param_1 = *(undefined4 *)((longlong)param_1 + lVar1);
        param_1 = (undefined8 *)((longlong)param_1 + 4);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      return;
    }
  }
  else if ((param_3 & 1) == 0) {
    if (param_3 >> 1 != 0) {
      lVar1 = param_2 - (longlong)param_1;
      uVar2 = (ulonglong)(param_3 >> 1);
      do {
        *(undefined2 *)param_1 = *(undefined2 *)((longlong)param_1 + lVar1);
        param_1 = (undefined8 *)((longlong)param_1 + 2);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      return;
    }
  }
  else if (param_3 != 0) {
    lVar1 = param_2 - (longlong)param_1;
    uVar2 = (ulonglong)param_3;
    do {
      *(undefined1 *)param_1 = *(undefined1 *)((longlong)param_1 + lVar1);
      param_1 = (undefined8 *)((longlong)param_1 + 1);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== NvStorCBTInitialize @ 00024884 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NvStorCBTInitialize(void)

{
  _CBT = &NvStorPortReadU8;
  _DAT_000356a8 = &NvStorPortReadU16;
  _DAT_000356b0 = &NvStorPortReadU32;
  _DAT_000356b8 = NvStorPortReadBufferU8;
  _DAT_000356c0 = NvStorPortReadBufferU16;
  _DAT_000356c8 = NvStorPortReadBufferU32;
  _DAT_000356d0 = &NvStorRegisterReadU8;
  _DAT_000356d8 = &NvStorRegisterReadU16;
  _DAT_000356e0 = &NvStorRegisterReadU32;
  _DAT_000356e8 = NvStorRegisterReadBufferU8;
  _DAT_000356f0 = NvStorRegisterReadBufferU16;
  _DAT_000356f8 = NvStorRegisterReadBufferU32;
  _DAT_00035700 = &NvStorPortWriteU8;
  _DAT_00035708 = &NvStorPortWriteU16;
  _DAT_00035710 = &NvStorPortWriteU32;
  _DAT_00035718 = NvStorPortWriteBufferU8;
  _DAT_00035720 = NvStorPortWriteBufferU16;
  _DAT_00035728 = NvStorPortWriteBufferU32;
  _DAT_00035730 = &NvStorRegisterWriteU8;
  _DAT_00035738 = &NvStorRegisterWriteU16;
  _DAT_00035740 = &NvStorRegisterWriteU32;
  _DAT_00035748 = NvStorRegisterWriteBufferU8;
  _DAT_00035750 = NvStorRegisterWriteBufferU16;
  _DAT_00035758 = NvStorRegisterWriteBufferU32;
  _DAT_00035760 = NvStorPciConfigRead;
  _DAT_00035768 = NvStorPciConfigWrite;
  _DAT_00035770 = NvStorPciConfigReadU32;
  _DAT_00035778 = NvStorPciConfigWriteU32;
  _DAT_00035780 = NvStorPciConfigReadU16;
  _DAT_00035788 = NvStorPciConfigWriteU16;
  _DAT_00035790 = NvStorPciConfigReadU8;
  _DAT_00035798 = NvStorPciConfigWriteU8;
  _DAT_000357a0 = NvStorMemAlloc;
  _DAT_000357a8 = NvStorMemFree;
  _DAT_000357b0 = NvStorMemZero;
  _DAT_000357b8 = &NvStorMemCopy;
  _DAT_000357c0 = &NvStorStrLen;
  _DAT_000357c8 = NvStorHeapMemAlloc;
  _DAT_000357d0 = &NvStorHeapMemFree;
  _DAT_000357d8 = &NvStorSystemTimeGet;
  _DAT_000357e0 = &NvStorSystemTimeGetGranularity;
  _DAT_000357e8 = &NvStorSpinLockCreate;
  _DAT_000357f0 = NvStorSpinLockAcquire;
  _DAT_000357f8 = NvStorSpinLockRelease;
  _DAT_00035800 = &NvStorSynchronizeWithIsr;
  _DAT_00035808 = &NvStorDbgSet;
  _DAT_00035810 = NvStorDbgPrint;
  _DAT_00035818 = &NvStorAssert;
  _DAT_00035820 = &NvStorStallExecution;
  _DAT_00035828 = NvStorNotifyDeviceChange;
  _DAT_00035830 = NvStorIssueDpc;
  _DAT_00035838 = &NvStorGetSataControllerExtension;
  _DAT_00035840 = &NvStorGetSataPortExtension;
  _DAT_00035848 = &NvStorGetSataDeviceExtension;
  _DAT_00035850 = &NvStorGetSataRequestExtension;
  _DAT_00035858 = &NvStorGetPhysicalAddress;
  _DAT_00035860 = NvStorReqCompleteRequest;
  _DAT_00035868 = &NvStorIsPortRaidEnabled;
  _DAT_000358a0 = &NvStorQuerySystemTime;
  _DAT_00035870 = NvStorGetPioTransferAddress;
  _DAT_000358a8 = NvStorValidateDevice;
  _DAT_00035878 = NvStorGetTaskFile;
  _DAT_00035880 = &NvStorRequestTimerCall;
  _DAT_00035888 = 0;
  _DAT_00035890 = 0;
  _DAT_00035898 = 0;
  _DAT_000358b8 = &NvStorDeviceResume;
  _DAT_000358b0 = NvStorDevicePause;
  return;
}



===== NvStorAdapterControl @ 00024c2c =====

undefined8 NvStorAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 5) = 0x101;
    *(undefined1 *)(param_3 + 4) = 1;
    *(undefined1 *)(param_3 + 8) = 1;
  }
  else if (param_2 == 1) {
    NvStorControllerConfigStop(param_1);
    NvStorControllerStop(param_1);
  }
  else if (param_2 == 2) {
    if (*(code **)(param_1 + 0x2700) == (code *)0x0) {
      cVar2 = '\x01';
    }
    else {
      cVar2 = (**(code **)(param_1 + 0x2700))();
    }
    if (cVar2 == '\0') {
      StorPortPause(param_1,0x1f);
      *(undefined4 *)(lVar1 + 0x918) = 0x12d;
      *(undefined1 *)(lVar1 + 0x91c) = 0;
    }
    if (*(code **)(param_1 + 10000) != (code *)0x0) {
      (**(code **)(param_1 + 10000))(param_1);
    }
    StorPortNotification(6,param_1,FUN_00026448);
  }
  else if (param_2 == 4) {
    if ((*(uint *)(param_1 + 0x2818) & 2) != 0) {
      *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) & 0xfffffffd;
    }
    if (*(code **)(param_1 + 0x26f8) != (code *)0x0) {
      (**(code **)(param_1 + 0x26f8))();
    }
    NvStorInitializeControllerConfig(param_1);
  }
  return 0;
}



===== NvStorBuildIo @ 00024d1c =====

ulonglong NvStorBuildIo(longlong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 *in_RAX;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  byte bVar6;
  void *_Dst;
  uint local_res10 [2];
  
  _Dst = (void *)0x0;
  cVar1 = *(char *)(param_2 + 2);
  local_res10[0] = 0;
  if (cVar1 == '\x17') goto LAB_00024d42;
  if (cVar1 == '%') {
    uVar3 = NvStorPnpSrb(param_1,param_2);
    return uVar3;
  }
  if (cVar1 == '$') {
    if (*(char *)(param_2 + 4) == '\x01') {
      *(undefined1 *)(param_1 + 0x2668) = *(undefined1 *)(param_2 + 0x40);
      *(undefined1 *)(param_1 + 0x2669) = *(undefined1 *)(param_2 + 8);
    }
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else if ((*(char *)(param_2 + 7) == '\0') && (*(char *)(param_2 + 5) == *(char *)(param_2 + 6))) {
    if (cVar1 == '\x02') {
LAB_00024dbe:
      if (*(uint *)(param_2 + 0x10) < 0x1c) {
        in_RAX = (undefined8 *)0x80000008;
      }
      else {
        uVar3 = NvStorGetPortNumberForIoctls(param_2,local_res10);
        bVar6 = (byte)uVar3;
        in_RAX = (undefined8 *)(ulonglong)local_res10[0];
        if (local_res10[0] == 1) goto LAB_00024df6;
      }
      *(undefined1 *)(param_2 + 3) = 6;
LAB_00024edc:
      if ((int)in_RAX == 1) {
LAB_00024d42:
        return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
      }
    }
    else {
      bVar6 = *(byte *)(param_2 + 6);
LAB_00024df6:
      puVar4 = (undefined8 *)StorPortGetLogicalUnit(param_1,bVar6,bVar6,0);
      _Dst = *(void **)(param_2 + 0x38);
      memset(_Dst,0,0xf0);
      *(void **)((longlong)_Dst + 0xd0) = (void *)((longlong)_Dst + 0x104);
      memset((void *)((longlong)_Dst + 0x104),0,0x330);
      if ((*(char *)(param_2 + 2) != '\x02') ||
         (uVar5 = NvStorCompleteControllerIoctls(param_1,param_2,(longlong)_Dst), (int)uVar5 == 1))
      {
        if (puVar4 == (undefined8 *)0x0) {
          *(undefined1 *)(param_2 + 3) = 6;
        }
        else {
          uVar2 = *(uint *)((ulonglong)bVar6 * 0x128 + 0x120 + param_1);
          if (((uVar2 & 4) == 0) || (*(char *)(param_2 + 0x48) == '\x12')) {
            if (((ulonglong)puVar4[0x112] >> 0x18 & 1) != 0) {
              in_RAX = *(undefined8 **)((longlong)_Dst + 0xd0);
              *in_RAX = 0;
              goto LAB_00024d42;
            }
            uVar2 = uVar2 & 2;
            in_RAX = (undefined8 *)0x0;
            if ((uVar2 == 0) || (*(char *)(param_2 + 2) != '\x02')) {
              if (((ulonglong)puVar4[0x112] >> 0x17 & 1) != 0) {
                if ((uVar2 != 0) && (*(char *)(param_2 + 0x48) == '\x12')) goto LAB_00024d42;
                in_RAX = (undefined8 *)NvStorReqSetupRequest((longlong)_Dst,puVar4,param_2);
                goto LAB_00024edc;
              }
              if (*(char *)(param_2 + 2) == '\0') goto LAB_00024d42;
            }
          }
          *(undefined1 *)(param_2 + 3) = 5;
        }
      }
    }
    if ((_Dst != (void *)0x0) && (**(longlong **)((longlong)_Dst + 0xd0) != 0)) {
      uVar3 = NvStorReqCompleteRequest((longlong)_Dst,param_1);
      goto LAB_00024d84;
    }
  }
  else {
    if (cVar1 == '\x02') goto LAB_00024dbe;
    *(undefined1 *)(param_2 + 3) = 8;
  }
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_00024d84:
  return uVar3 & 0xffffffffffffff00;
}



===== NvStorFindAdapter @ 00024f14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
NvStorFindAdapter(ulonglong param_1,undefined8 param_2,undefined8 param_3,byte *param_4,
                 longlong param_5)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 uVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  code *pcVar14;
  undefined1 auStackY_3b8 [32];
  undefined8 in_stack_fffffffffffffc68;
  char local_358 [4];
  undefined4 local_354 [3];
  undefined8 local_348;
  undefined4 local_340;
  longlong local_338;
  undefined8 local_328;
  undefined4 local_320;
  longlong local_318;
  undefined8 local_308;
  undefined4 local_300;
  longlong local_2f8;
  undefined8 local_2e8;
  undefined4 local_2e0;
  longlong local_2d8;
  undefined8 local_2c8;
  undefined4 local_2c0;
  longlong local_2b8;
  undefined8 local_288;
  undefined4 local_280;
  longlong local_278;
  undefined1 local_268 [2];
  short local_266;
  char local_260;
  undefined1 local_25e;
  undefined1 local_25d;
  undefined2 local_23c;
  undefined2 local_23a;
  undefined1 local_1c4;
  undefined4 local_168;
  uint local_164;
  int local_160;
  ulonglong local_48;
  
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffc68 >> 0x20);
  local_48 = __security_cookie ^ (ulonglong)auStackY_3b8;
  puVar2 = *(undefined8 **)(param_5 + 0x38);
  local_358[0] = '\0';
  (**(code **)(NvStorOsCBT + 0x110))(param_1,0x2920);
  FUN_000264dc(param_1,param_4,CONCAT71((int7)((ulonglong)param_3 >> 8),1));
  if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
    local_354[0] = 0x2000;
    param_4 = (byte *)StorPortAllocateRegistryBuffer(param_1,local_354);
    if (param_4 != (byte *)0x0) {
      pbVar13 = param_4;
      StorPortRegistryRead(param_1,"DriverParameter",1,1);
      uVar7 = (undefined4)((ulonglong)pbVar13 >> 0x20);
    }
  }
  *(undefined4 **)(param_1 + 0x28d0) = (undefined4 *)(param_1 + 0x2920);
  *(undefined4 *)(param_1 + 0x2920) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_1 + 0x2924) = *(undefined4 *)(param_5 + 100);
  uVar4 = NvStorPciConfigRead(param_1,local_268,0x100);
  if (uVar4 < 0x100) goto LAB_00025681;
  local_348 = *puVar2;
  local_340 = *(undefined4 *)(puVar2 + 1);
  local_338 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),*puVar2);
  if (local_338 == 0) goto LAB_00025681;
  local_308 = puVar2[2];
  local_300 = *(undefined4 *)(puVar2 + 3);
  local_2f8 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),puVar2[2]);
  if (local_2f8 == 0) goto LAB_00025681;
  local_328 = puVar2[4];
  local_320 = *(undefined4 *)(puVar2 + 5);
  local_318 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),puVar2[4]);
  if (local_318 == 0) goto LAB_00025681;
  local_2e8 = puVar2[6];
  local_2e0 = *(undefined4 *)(puVar2 + 7);
  local_2d8 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),puVar2[6]);
  if (local_2d8 == 0) goto LAB_00025681;
  local_2c8 = puVar2[8];
  local_2c0 = *(undefined4 *)(puVar2 + 9);
  local_2b8 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),puVar2[8]);
  if (local_2b8 == 0) goto LAB_00025681;
  local_288 = puVar2[10];
  local_280 = *(undefined4 *)(puVar2 + 0xb);
  uVar10 = CONCAT44(uVar7,local_280);
  local_278 = StorPortGetDeviceBase(param_1,5,*(undefined4 *)(param_5 + 4),puVar2[10]);
  if ((local_278 == 0) ||
     (uVar8 = NvStorControllerInitialize
                        (param_1,*(undefined1 *)(param_5 + 4),*(byte *)(param_5 + 100) & 0x1f,
                         (char)(*(uint *)(param_5 + 100) >> 5),uVar10,local_266,local_23c,local_23a,
                         local_260,local_25d,local_25e,&local_348), (uVar8 & 0x80000000) != 0))
  goto LAB_00025681;
  *(undefined1 *)(param_5 + 0x48) = *(undefined1 *)(param_1 + 0x2500);
  *(undefined1 *)(param_5 + 0x61) = *(undefined1 *)(param_1 + 0x2500);
  uVar11 = *(undefined1 *)(param_1 + 0x2501);
  *(undefined4 *)(param_5 + 0x18) = 0x20000;
  *(undefined2 *)(param_5 + 0x51) = 0x101;
  *(undefined1 *)(param_5 + 0x91) = 1;
  *(undefined4 *)(param_5 + 0x30) = 1;
  *(undefined1 *)(param_5 + 0x92) = uVar11;
  *(undefined1 *)(param_5 + 0x57) = 1;
  *(undefined1 *)(param_5 + 0x93) = 1;
  *(undefined1 *)(param_5 + 0x53) = 1;
  *(undefined4 *)(param_5 + 0x1c) = 0x20;
  *(undefined4 *)(param_5 + 0x94) = 1;
  if ((*(char *)(param_5 + 0x90) == -0x80) && ((*(uint *)(param_1 + 0x2818) & 1) != 0)) {
    *(undefined1 *)(param_5 + 0x90) = 1;
    *(undefined1 *)(param_5 + 0x57) = 0;
  }
  uVar11 = 0;
  if (*(short *)(param_1 + 0x2600) == 0x104) {
    uVar11 = local_1c4;
  }
  *(undefined1 *)(param_1 + 0x32c0) = uVar11;
  if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
    if (*(code **)(param_1 + 0x26c0) == (code *)0x0) {
      uVar4 = 1;
    }
    else {
      uVar4 = (**(code **)(param_1 + 0x26c0))(param_1);
    }
    if (param_4 == (byte *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (**(code **)(NvStorOsCBT + 0x120))(param_4);
    }
    iVar5 = NvStorGetDmaPoolSize(param_1,uVar4);
    lVar9 = StorPortGetUncachedExtension
                      (param_1,param_5,
                       iVar6 + iVar5 + (uint)*(byte *)(param_1 + 0x2500) * 0x640 + 0x10d06);
  }
  else {
    if (param_4 == (byte *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (**(code **)(NvStorOsCBT + 0x120))(param_4);
    }
    iVar5 = NvStorGetDmaPoolSize(param_1,1);
    lVar9 = StorPortGetUncachedExtension
                      (param_1,param_5,
                       iVar6 + iVar5 + (uint)*(byte *)(param_1 + 0x2500) * 0x440 + 0x3ea6);
  }
  *(longlong *)(param_1 + 0x2928) = lVar9;
  if (lVar9 == 0) goto LAB_00025681;
  if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
    if (*(code **)(param_1 + 0x26c0) == (code *)0x0) {
      uVar4 = 1;
    }
    else {
      uVar4 = (**(code **)(param_1 + 0x26c0))(param_1);
    }
    if (param_4 == (byte *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = (**(code **)(NvStorOsCBT + 0x120))(param_4);
    }
    iVar5 = NvStorGetDmaPoolSize(param_1,uVar4);
    uVar10 = NvStorMemPoolInit(param_1,*(longlong *)(param_1 + 0x2928),
                               iVar6 + iVar5 + (uint)*(byte *)(param_1 + 0x2500) * 0x440 + 0x10d01);
    uVar4 = (uint)uVar10;
    if (*(code **)(param_1 + 0x26c0) == (code *)0x0) {
      uVar7 = 1;
    }
    else {
      uVar7 = (**(code **)(param_1 + 0x26c0))(param_1);
    }
    pcVar14 = *(code **)(param_1 + 0x26c8);
    *(undefined4 *)(param_1 + 0x2504) = uVar7;
    if (pcVar14 != (code *)0x0) goto LAB_00025421;
  }
  else {
    iVar6 = NvStorGetDmaPoolSize(param_1,1);
    uVar10 = NvStorMemPoolInit(param_1,lVar9,
                               iVar6 + (uint)*(byte *)(param_1 + 0x2500) * 0x440 + 0x3ea0);
    pcVar14 = *(code **)(param_1 + 0x26c8);
    *(undefined4 *)(param_1 + 0x2504) = 1;
    uVar4 = (uint)uVar10;
    if (pcVar14 != (code *)0x0) {
      uVar7 = 1;
LAB_00025421:
      (*pcVar14)(param_1,uVar7);
    }
  }
  if ((uVar4 & 0x80000000) == 0) {
    uVar4 = NvStorControllerStart(param_1);
    FUN_00026448(param_1);
    *(undefined1 *)(param_1 + 0x323c) = 1;
    if ((uVar4 & 0x80000000) == 0) {
      lVar9 = *(longlong *)(param_1 + 0x28d0);
      (**(code **)(NvStorOsCBT + 0x110))(lVar9 + 0x9f8,0x2000);
      lVar3 = NvStorOsCBT;
      if (param_4 != (byte *)0x0) {
        (**(code **)(NvStorOsCBT + 0x120))(param_4);
        (**(code **)(lVar3 + 0x118))(lVar9 + 0x9f8,param_4);
      }
      NvStorInitializeControllerConfig(param_1);
      FUN_000264dc(param_1,param_4,0);
      iVar6 = 0;
      if (*(char *)(param_1 + 0x2500) != '\0') {
        puVar12 = (undefined1 *)(param_1 + 0x124);
        do {
          *puVar12 = 0;
          iVar6 = iVar6 + 1;
          puVar12 = puVar12 + 0x128;
        } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x2500));
      }
      if (((*(uint *)(param_1 + 0x2818) & 2) == 0) &&
         (iVar6 = 0, *(char *)(param_1 + 0x2500) != '\0')) {
        pbVar13 = (byte *)(param_1 + 0x124);
        do {
          bVar1 = *(byte *)(param_1 + 0x2852);
          *pbVar13 = bVar1;
          if ((*(uint *)(param_1 + 0x25f0) & 0x4000) == 0) {
            *pbVar13 = bVar1 & 0xf0;
          }
          if ((*(uint *)(param_1 + 0x25f0) & 0x8000) == 0) {
            *pbVar13 = *pbVar13 & 0x3f;
          }
          if (((*(uint *)(param_1 + 0x25f0) & 0x10000) != 0) &&
             ((*(byte *)(param_1 + 0x2852) & 0xcf) == 0)) {
            *pbVar13 = *pbVar13 | 8;
          }
          if (((*pbVar13 & 0x10) != 0) || ((char)*(undefined4 *)(pbVar13 + -4) < '\0')) {
            *pbVar13 = 0x10;
          }
          if ((*pbVar13 & 0xcf) != 0) {
            *(uint *)(pbVar13 + -4) = *(uint *)(pbVar13 + -4) | 0x40;
          }
          iVar6 = iVar6 + 1;
          pbVar13 = pbVar13 + 0x128;
        } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x2500));
      }
      if (*(char *)(param_1 + 0x2854) != '\0') {
        *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 0x40;
      }
      uVar4 = NvCfgElementGet(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830),
                              '\x16',(undefined8 *)local_358,1);
      if ((-1 < (int)uVar4) && (local_358[0] != '\0')) {
        *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 0x800;
      }
      lVar9 = *(longlong *)(param_1 + 0x28d0);
      *(undefined ***)(lVar9 + 0x9b0) = &NvStorGuidList;
      *(undefined4 *)(lVar9 + 0x9a8) = 2;
      *(undefined1 **)(lVar9 + 0x9b8) = &LAB_00029780;
      *(undefined8 *)(lVar9 + 0x9d0) = 0;
      *(code **)(lVar9 + 0x9c0) = FUN_000293a4;
      *(undefined8 *)(lVar9 + 0x9d8) = 0;
      *(code **)(lVar9 + 0x9c8) = FUN_00029640;
      *(code **)(lVar9 + 0x9e0) = FUN_00029764;
      *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 0x100;
      if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
        memset(&local_168,0,0x114);
        local_168 = 0x114;
        RtlGetVersion(&local_168);
        if ((local_164 < 7) && ((local_164 != 6 || (local_160 == 0)))) {
          *(undefined1 *)(param_1 + 0x28d9) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x28d9) = 1;
        }
      }
      if (((*(uint *)(param_1 + 0x2818) & 2) == 0) && (param_4 != (byte *)0x0)) {
        StorPortFreeRegistryBuffer(param_1,param_4);
      }
      return 1;
    }
  }
LAB_00025681:
  if (*(longlong *)(param_1 + 0x2520) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 0x2560) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 0x2540) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 0x2580) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 0x25a0) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 0x25e0) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (((*(uint *)(param_1 + 0x2818) & 2) == 0) && (param_4 != (byte *)0x0)) {
    StorPortFreeRegistryBuffer(param_1,param_4);
  }
  return 2;
}



===== NvStorInitialize @ 0002574c =====

undefined1 NvStorInitialize(longlong param_1)

{
  byte bVar1;
  code *pcVar2;
  bool bVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  byte *pbVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint *puVar14;
  int local_res8 [2];
  int local_res10;
  longlong local_res18;
  
  lVar10 = *(longlong *)(param_1 + 0x28d0);
  iVar9 = (-(uint)((*(byte *)(param_1 + 0x2818) & 2) != 0) & 0xfffffc20) + 0x400;
  lVar5 = (**(code **)(NvStorOsCBT + 0x100))(param_1,iVar9 * 0x35,0);
  *(longlong *)(param_1 + 0x26b0) = lVar5;
  lVar6 = NvStorOsCBT;
  if (lVar5 != 0) {
    *(longlong *)(param_1 + 0x2670) = param_1;
    uVar7 = (**(code **)(lVar6 + 0x140))();
    pcVar2 = *(code **)(NvStorOsCBT + 0x138);
    *(int *)(param_1 + 0x2680) = iVar9;
    *(longlong *)(param_1 + 0x2678) = *(longlong *)(param_1 + 0x26b0);
    *(undefined8 *)(param_1 + 0x2688) = 0;
    *(undefined4 *)(param_1 + 0x2684) = 0;
    if (*(longlong *)(param_1 + 0x26b0) != 0) {
      *(undefined4 *)(param_1 + 0x2690) = 0x6e566556;
      *(code **)(param_1 + 0x26a4) = pcVar2;
      *(undefined8 *)(param_1 + 0x269c) = uVar7;
      uVar7 = (*pcVar2)();
      *(undefined8 *)(param_1 + 0x2694) = uVar7;
      iVar9 = 0;
      goto LAB_00025820;
    }
  }
  iVar9 = -0x7fffffef;
LAB_00025820:
  if (-1 < iVar9) {
    lVar6 = NvStorMemAlloc(param_1,(uint)*(byte *)(param_1 + 0x2500) << 10,2,'\0');
    *(longlong *)(param_1 + 0x2908) = lVar6;
    if (lVar6 != 0) {
      lVar6 = NvStorMemAlloc(param_1,(uint)*(byte *)(param_1 + 0x2500) << 6,0,'\0');
      *(longlong *)(param_1 + 0x2910) = lVar6;
      if (lVar6 != 0) {
        local_res8[0] = 0;
        if (*(char *)(param_1 + 0x2500) != '\0') {
          local_res18 = 0;
          local_res10 = 0;
          do {
            lVar5 = (longlong)local_res10;
            lVar6 = *(longlong *)(param_1 + 0x2908);
            puVar14 = (uint *)(*(longlong *)(param_1 + 0x2910) + local_res18);
            uVar11 = 0;
            uVar4 = 0;
            do {
              uVar13 = uVar4;
              puVar14[uVar13 * 6 + 6] = 0x400 - uVar11;
              uVar7 = (**(code **)(NvStorOsCBT + 0x1b8))
                                (param_1,0,lVar5 + lVar6,puVar14 + uVar13 * 6 + 6);
              uVar11 = uVar11 + puVar14[uVar13 * 6 + 6];
              uVar12 = (int)uVar13 + 1;
              *(undefined8 *)(puVar14 + uVar13 * 6 + 4) = uVar7;
              uVar4 = (ulonglong)uVar12;
            } while (uVar11 < 0x400);
            *puVar14 = uVar12;
            local_res10 = local_res10 + 0x400;
            puVar14[(uVar13 + 1) * 6] = puVar14[(uVar13 + 1) * 6] + (0x400 - uVar11);
            local_res8[0] = local_res8[0] + 1;
            local_res18 = local_res18 + 0x40;
          } while (local_res8[0] < (int)(uint)*(byte *)(param_1 + 0x2500));
        }
        *(undefined1 *)(lVar10 + 0x11) = 0;
        local_res8[0] = 0;
        StorPortNotification(0x1000,param_1,NvStorPassiveInitializeRoutine,local_res8);
        *(undefined1 *)(lVar10 + 0x10) = (undefined1)local_res8[0];
        if (*(code **)(param_1 + 10000) != (code *)0x0) {
          (**(code **)(param_1 + 10000))(param_1);
        }
        if (((*(uint *)(param_1 + 0x25f0) & 0x1000) != 0) &&
           ((*(uint *)(param_1 + 0x2818) & 2) == 0)) {
          bVar3 = false;
          pbVar8 = (byte *)(param_1 + 0x124);
          lVar10 = 0x20;
          do {
            bVar1 = *pbVar8;
            pbVar8 = pbVar8 + 0x128;
            if ((bVar1 & 0xc) != 0) {
              bVar3 = true;
            }
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          if (bVar3) {
            StorPortNotification(6,param_1,FUN_00026448,30000000);
          }
        }
        return 1;
      }
      NvStorMemFree(param_1,*(longlong *)(param_1 + 0x2908),'\0');
    }
    (**(code **)(NvStorOsCBT + 0x108))(param_1,*(undefined8 *)(param_1 + 0x26b0),1);
    if (((*(int *)(param_1 + 0x2690) == 0x6e566556) && (*(int *)(param_1 + 0x2680) != 0)) &&
       (*(longlong *)(param_1 + 0x2678) != 0)) {
      *(undefined4 *)(param_1 + 0x2680) = 0;
      *(undefined8 *)(param_1 + 0x2678) = 0;
      *(undefined8 *)(param_1 + 0x2688) = 0;
    }
  }
  return 0;
}



===== NvStorInterrupt @ 00025a88 =====

undefined8 NvStorInterrupt(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((*(code **)(param_1 + 0x27b8) != (code *)0x0) && (*(int *)(param_1 + 0x2664) == 1)) {
    uVar1 = (**(code **)(param_1 + 0x27b8))();
  }
  return uVar1;
}



===== NvStorDpcForIsr @ 00025aac =====

void NvStorDpcForIsr(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined *param_4)

{
  if (param_4 != (undefined *)0x0) {
    (*(code *)param_4)(param_3,0);
  }
  return;
}



===== NvStorPassiveInitializeRoutine @ 00025ac4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorPassiveInitializeRoutine(longlong param_1)

{
  byte *pbVar1;
  ulonglong *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ushort uVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  undefined1 auStackY_118 [32];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  int local_c8 [3];
  short local_bc;
  byte local_b8;
  int local_a8 [3];
  short local_9c;
  ushort local_9a;
  undefined1 local_98 [112];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar3 = *(longlong *)(param_1 + 0x28d0);
  lVar7 = lVar3 + 0x18;
  lVar10 = 0x20;
  do {
    lVar9 = lVar10;
    StorPortNotification(0x1001,param_1,lVar7,NvStorDpcForIsr);
    lVar7 = lVar7 + 0x48;
    lVar10 = lVar9 + -1;
  } while (lVar10 != 0);
  *(undefined1 *)(lVar3 + 0x11) = 1;
  iVar11 = (int)lVar9 + 1;
  if ((((*(uint *)(param_1 + 0x25f0) & 0x40000) != 0) || (-1 < *(char *)(lVar3 + 0x9a0))) &&
     (*(short *)(param_1 + 0x2600) == 0x104)) {
    local_e4 = 0x504d5244;
    local_e8 = 0x42696541;
    StorPortExtendedFunction(8,param_1,local_d0,local_d8);
    uVar4 = FUN_00026cdc(local_e0,0x32c004,&local_e8,8,local_c8,0x14);
    if ((-1 < (int)uVar4) && (local_bc == 0)) {
      lVar7 = *(longlong *)(param_1 + 0x28d0);
      iVar5 = 0;
      *(undefined1 *)(lVar7 + 0x9a0) = 0x80;
      if (*(char *)(param_1 + 0x2500) != '\0') {
        uVar6 = 0;
        do {
          if ((local_b8 >> (uVar6 & 0x1f) & 1) != 0) {
            pbVar1 = (byte *)(lVar7 + 0x9a0);
            *pbVar1 = *pbVar1 | '\x01' << ((byte)iVar5 & 0x1f);
          }
          iVar5 = iVar5 + 1;
          uVar6 = uVar6 + iVar11;
        } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x2500));
      }
    }
  }
  puVar2 = (ulonglong *)(param_1 + 0x2602);
  *(undefined1 *)puVar2 = 0;
  local_e4 = 0x4d4e5450;
  local_e8 = 0x42696541;
  StorPortExtendedFunction(8,param_1,local_d8,local_d0);
  uVar4 = FUN_00026cdc(local_e0,0x32c004,&local_e8,8,local_a8,0x78);
  if ((-1 < (int)uVar4) && (local_9c == (short)iVar11)) {
    uVar8 = 0x61;
    if (local_9a < 0x62) {
      uVar8 = local_9a;
    }
    (**(code **)(NvStorOsCBT + 0x118))(puVar2,local_98,uVar8);
    uVar6 = NvCfgElementSet(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830),'\x10',
                            puVar2,0x61);
    uVar4 = CONCAT44(extraout_var,uVar6);
  }
  if (*(int *)(param_1 + 0x28dc) == -1) {
    if (*(code **)(NvStorOsCBT + 0x1d8) != (code *)0x0) {
      uVar4 = (**(code **)(NvStorOsCBT + 0x1d8))(param_1);
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== NvStorResetBus @ 00025d0c =====

undefined8 NvStorResetBus(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x2818);
  if ((*(uint *)(param_1 + 0x2818) >> 10 & 1) == 0) {
    if (*(byte *)(param_1 + 0x2500) <= param_2) {
      return 0;
    }
    uVar1 = (ulonglong)param_2;
    plVar2 = (longlong *)(uVar1 * 0x128 + param_1);
    if (plVar2 != (longlong *)0x0) {
      uVar1 = NvStorPortReset(plVar2);
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== NvStorStartIo @ 00025d48 =====

undefined8 NvStorStartIo(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint *puVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined7 uVar12;
  undefined1 uVar13;
  longlong lVar14;
  ulonglong local_res10;
  
  cVar5 = *(char *)(param_2 + 2);
  if (cVar5 == '\x17') {
    uVar7 = NvStorWmiSrb(param_1,param_2);
    return uVar7;
  }
  bVar4 = *(byte *)(param_2 + 6);
  if ((*(byte *)(param_2 + 5) == bVar4) || (cVar5 == '\x02')) {
    if (cVar5 == '\x02') {
      if (*(uint *)(param_2 + 0x10) < 0x1c) {
        bVar4 = 0;
      }
      else {
        uVar9 = NvStorGetPortNumberForIoctls(param_2,(undefined4 *)&local_res10);
        bVar4 = (byte)uVar9;
      }
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined1 *)(param_2 + 7);
    }
    lVar11 = CONCAT71((int7)((ulonglong)param_3 >> 8),bVar4);
    plVar8 = (longlong *)StorPortGetLogicalUnit(param_1,bVar4,lVar11,uVar13);
    plVar2 = *(longlong **)(param_2 + 0x38);
    plVar10 = plVar8;
    if ((*(uint *)(plVar2 + 0x18) & 0x800) != 0) goto LAB_00026427;
    *(undefined1 *)(param_2 + 3) = 0;
    if (plVar8 == (longlong *)0x0) {
      plVar10 = (longlong *)(*(code *)plVar2[0x15])(plVar2,0x80000010,1);
      goto LAB_00026427;
    }
    uVar9 = plVar8[0x112];
    if ((uVar9 >> 0x18 & 1) != 0) {
      if (*(longlong *)plVar2[0x1a] == 0) {
        *(undefined1 *)(param_2 + 3) = 8;
        StorPortNotification(0,param_1,param_2);
      }
      else {
        (*(code *)plVar2[0x15])(plVar2,0x80000010,1);
      }
      NvStorDeviceConfigStop(plVar8);
      NvStorDeviceStop(plVar8);
      plVar10 = (longlong *)NvStorDeviceRemove(plVar8);
      if ((uVar9 & 0x1000000000000) != 0) {
        StorPortNotification(7,param_1,*(undefined1 *)(param_2 + 5));
        plVar10 = (longlong *)0x1000000000000;
        plVar8[0x112] = plVar8[0x112] | 0x1000000000000;
      }
      goto LAB_00026427;
    }
    if ((*(byte *)(plVar8 + 0x113) & 1) != 0) {
LAB_00025ead:
      *(undefined4 *)(plVar2 + 0x11) = 0x80000006;
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_000263db;
    }
    if ((uVar9 >> 0x17 & 1) == 0) {
LAB_0002618e:
      cVar5 = *(char *)(param_2 + 2);
      if (cVar5 == '\0') {
        uVar9 = plVar8[0x112];
        if ((uVar9 >> 0x17 & 1) == 0) {
          plVar8[0x112] = uVar9 | 0x4000000000000;
          if ((uVar9 & 0x1000000000000) != 0) {
            *(undefined1 *)(param_2 + 3) = 8;
            StorPortNotification(7,param_1,*(undefined1 *)(param_2 + 5));
            goto LAB_000263db;
          }
          uVar12 = (undefined7)((ulonglong)lVar11 >> 8);
          plVar10 = (longlong *)
                    NvStorDeviceInitialize
                              ((longlong *)((ulonglong)*(byte *)(param_2 + 6) * 0x128 + param_1),
                               plVar8,*(byte *)(param_2 + 7));
          if (-1 < (int)plVar10) {
            StorPortSetDeviceQueueDepth
                      (param_1,*(undefined1 *)(param_2 + 5),
                       CONCAT71(uVar12,*(undefined1 *)(param_2 + 6)),*(undefined1 *)(param_2 + 7),
                       0x80);
            plVar8[0x111] = (longlong)(plVar8 + 0x4f1);
            uVar9 = NvStorDeviceStart(plVar8);
            if ((int)uVar9 < 0) {
              plVar10 = (longlong *)NvStorDeviceRemove(plVar8);
            }
            else {
              FUN_00026768(plVar8);
              NvStorInitializeDeviceConfig(plVar8);
              puVar3 = (undefined4 *)plVar8[0x111];
              *(undefined ***)(puVar3 + 2) = &NvStorDeviceGuidList;
              *puVar3 = 2;
              *(undefined8 *)(puVar3 + 10) = 0;
              *(undefined8 *)(puVar3 + 0xe) = 0;
              *(undefined1 **)(puVar3 + 4) = &LAB_00029780;
              *(code **)(puVar3 + 6) = FUN_00029880;
              *(code **)(puVar3 + 8) = FUN_0002a044;
              *(code **)(puVar3 + 0xc) = FUN_0002a578;
              if (*(code **)(*(longlong *)*plVar8 + 0x2798) != (code *)0x0) {
                (**(code **)(*(longlong *)*plVar8 + 0x2798))(plVar8);
              }
              if ((plVar8[0x112] & 0x8000000000000U) != 0) {
                plVar8[0x112] = plVar8[0x112] & 0xfff7ffffffffffff;
                NvStorReqQueueInsert((longlong)(plVar8 + 0x35),plVar8 + 0xf2);
              }
              if (((*(byte *)(plVar8 + 0x112) & 0x20) != 0) || (gNvStorPassThroughEnabled == '\0'))
              goto LAB_000263a2;
              plVar10 = (longlong *)
                        NvStorRaidMetaDataIo
                                  (plVar8,(longlong)(int)((uint)bVar4 << 10) +
                                          *(longlong *)(param_1 + 0x2908),
                                   (ulonglong)bVar4 * 0x40 + *(longlong *)(param_1 + 0x2910),
                                   FUN_00027518,param_2,0,'\0');
              if ((int)plVar10 == 1) goto LAB_00026427;
              *(undefined4 *)(plVar2 + 0x11) = 0x80000010;
            }
          }
          iVar6 = (int)plVar10;
          *(undefined1 *)(param_2 + 3) = 8;
        }
        else {
          if ((((*(uint *)(param_1 + 0x25f0) & 1) != 0) && ((uVar9 & 0x80000000) != 0)) &&
             ((uVar9 & 0x20) != 0)) {
            *(undefined1 *)(param_2 + 3) = 2;
            goto LAB_000263ee;
          }
          if (plVar2[2] != 0) goto LAB_000263b5;
LAB_000263a2:
          uVar9 = NvStorReqSetupRequest((longlong)plVar2,plVar8,param_2);
          iVar6 = (int)uVar9;
        }
LAB_000263b0:
        if (iVar6 == 1) {
LAB_000263b5:
          if ((*(char *)(param_2 + 0x48) == '\x12') && ((*(byte *)(plVar8 + 0x112) & 0x20) == 0)) {
            uVar9 = NvStorReqSetupRequest((longlong)plVar2,plVar8,param_2);
            iVar6 = (int)uVar9;
            goto LAB_000263d5;
          }
          goto LAB_000263f8;
        }
      }
      else {
        if (cVar5 != '\x12') {
          if ((cVar5 == '\x13') || (cVar5 == ' ')) {
            iVar6 = NvStorDeviceReset(plVar8);
            goto LAB_000263b0;
          }
          goto LAB_000263b5;
        }
        NvStorResetBus(*(longlong *)*plVar8,(uint)*(byte *)(param_2 + 5));
      }
LAB_000263db:
      if (*(longlong *)plVar2[0x1a] == 0) goto LAB_000263ee;
    }
    else {
      lVar14 = (ulonglong)bVar4 * 0x128;
      if ((*(uint *)(lVar14 + 0x120 + param_1) & 2) == 0) goto LAB_0002618e;
      if (((uVar9 & 0x20) == 0) && (*(char *)(*(longlong *)(param_1 + 0x28d0) + 0x91c) == '\0')) {
        if (*(code **)(*(longlong *)*plVar8 + 0x2708) == (code *)0x0) {
          cVar5 = '\x01';
        }
        else {
          cVar5 = (**(code **)(*(longlong *)*plVar8 + 0x2708))(plVar8);
        }
        if (cVar5 == '\0') goto LAB_00025ead;
      }
      plVar8[0x112] = plVar8[0x112] | 0x4000000000000;
      uVar9 = plVar8[0x112];
      puVar1 = (uint *)(lVar14 + 0x120 + param_1);
      *puVar1 = *puVar1 | 4;
      local_res10 = CONCAT71((uint7)(uVar9 >> 0x39),(char)(uVar9 >> 0x31)) & 0xffffffffffffff01;
      NvStorDeviceConfigStop(plVar8);
      NvStorDeviceStop(plVar8);
      NvStorDeviceRemove(plVar8);
      uVar9 = NvStorDeviceInitialize
                        ((longlong *)((ulonglong)*(byte *)(param_2 + 6) * 0x128 + param_1),plVar8,
                         *(byte *)(param_2 + 7));
      iVar6 = (int)uVar9;
      if ((uVar9 & 0x80000000) == 0) {
        plVar8[0x111] = (longlong)(plVar8 + 0x4f1);
        uVar9 = NvStorDeviceStart(plVar8);
        if ((uVar9 & 0x80000000) == 0) {
          FUN_00026768(plVar8);
          NvStorInitializeDeviceConfig(plVar8);
          puVar3 = (undefined4 *)plVar8[0x111];
          *puVar3 = 2;
          *(undefined8 *)(puVar3 + 10) = 0;
          *(undefined8 *)(puVar3 + 0xe) = 0;
          *(undefined ***)(puVar3 + 2) = &NvStorDeviceGuidList;
          *(undefined1 **)(puVar3 + 4) = &LAB_00029780;
          *(code **)(puVar3 + 6) = FUN_00029880;
          *(code **)(puVar3 + 8) = FUN_0002a044;
          *(code **)(puVar3 + 0xc) = FUN_0002a578;
          if (*(code **)(*(longlong *)*plVar8 + 0x2798) != (code *)0x0) {
            (**(code **)(*(longlong *)*plVar8 + 0x2798))(plVar8);
          }
          if ((plVar8[0x112] & 0x8000000000000U) != 0) {
            plVar8[0x112] = plVar8[0x112] & 0xfff7ffffffffffff;
            NvStorReqQueueInsert((longlong)(plVar8 + 0x35),plVar8 + 0xf2);
          }
          if (((plVar8[0x112] & 0x20U) == 0) && (gNvStorPassThroughEnabled != '\0')) {
            if ((char)local_res10 == '\0') {
              plVar10 = (longlong *)
                        NvStorRaidMetaDataIo
                                  (plVar8,(longlong)(int)((uint)bVar4 << 10) +
                                          *(longlong *)(param_1 + 0x2908),
                                   (ulonglong)bVar4 * 0x40 + *(longlong *)(param_1 + 0x2910),
                                   FUN_00027518,param_2,0,'\0');
              iVar6 = (int)plVar10;
              if (iVar6 == 1) goto LAB_00026427;
              *(undefined4 *)(plVar2 + 0x11) = 0x80000010;
              *(undefined1 *)(param_2 + 3) = 8;
              goto LAB_000263d5;
            }
            plVar8[0x112] = plVar8[0x112] | 0x2000000000000;
            if (*(code **)(*(longlong *)*plVar8 + 0x27f8) != (code *)0x0) {
              (**(code **)(*(longlong *)*plVar8 + 0x27f8))(plVar8);
            }
          }
          lVar11 = param_2;
          uVar9 = NvStorReqSetupRequest((longlong)plVar2,plVar8,param_2);
          if ((int)uVar9 != 1) goto LAB_000263db;
          goto LAB_0002618e;
        }
        uVar9 = NvStorDeviceRemove(plVar8);
        iVar6 = (int)uVar9;
        *(undefined4 *)(plVar2 + 0x11) = 0x80000010;
        *(undefined1 *)(param_2 + 3) = 8;
      }
      else {
        *(undefined4 *)(plVar2 + 0x11) = 0x80000010;
        *(undefined1 *)(param_2 + 3) = 8;
        plVar8[0x112] = plVar8[0x112] | 0x1000000;
        StorPortNotification(7,param_1);
      }
LAB_000263d5:
      if (iVar6 != 1) goto LAB_000263db;
LAB_000263f8:
      plVar10 = (longlong *)NvStorReqQueueInsert(plVar2[2] + 0x1a8,plVar2);
      if (-1 < (int)plVar10) goto LAB_00026427;
      *(undefined4 *)(plVar2 + 0x11) = 0x80000006;
    }
    plVar10 = (longlong *)NvStorReqCompleteRequest((longlong)plVar2,param_1);
  }
  else {
    *(undefined1 *)(param_2 + 3) = 8;
LAB_000263ee:
    plVar10 = (longlong *)StorPortNotification(0,param_1,param_2);
  }
LAB_00026427:
  return CONCAT71((int7)((ulonglong)plVar10 >> 8),1);
}



===== FUN_00026448 @ 00026448 =====

void FUN_00026448(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  if (*(char *)(lVar1 + 0x91c) == '\0') {
    *(int *)(lVar1 + 0x918) = *(int *)(lVar1 + 0x918) + -1;
    if (*(code **)(param_1 + 0x2700) == (code *)0x0) {
      cVar2 = '\x01';
    }
    else {
      cVar2 = (**(code **)(param_1 + 0x2700))();
    }
    if ((cVar2 != '\0') || (*(int *)(lVar1 + 0x918) == 0)) {
      StorPortResume(param_1);
      *(undefined4 *)(lVar1 + 0x918) = 0;
      *(undefined1 *)(lVar1 + 0x91c) = 1;
    }
  }
  if (*(int *)(param_1 + 0x2664) != 2) {
    (**(code **)(param_1 + 0x27c0))(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000264d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,FUN_00026448,100000);
  return;
}



===== FUN_000264dc @ 000264dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_000264dc(longlong param_1,byte *param_2,ulonglong param_3)

{
  longlong *plVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char **ppcVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 auStackY_128 [32];
  uint local_f8 [4];
  char *local_e8;
  char local_e0 [8];
  char *local_d8;
  undefined1 local_d0;
  char *local_c8;
  undefined1 local_c0;
  undefined1 *local_b8;
  undefined1 local_b0;
  char *local_a8;
  undefined1 local_a0;
  char *local_98;
  undefined1 local_90;
  char *local_88;
  undefined1 local_80;
  undefined1 *local_78;
  undefined1 local_70;
  char *local_68;
  undefined1 local_60;
  byte local_58 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e8 = "queuingEnable";
  local_e0[0] = '\n';
  local_d8 = "aqEnable";
  local_d0 = 0xb;
  local_c8 = "aqQueuedThreshold";
  local_c0 = 0xc;
  local_b8 = &s_IPM;
  local_b0 = 0xd;
  local_a8 = "UseBiosDefault";
  local_a0 = 0xe;
  local_98 = "DellAtapiWar";
  local_90 = 0xf;
  local_88 = "DisableRemovable";
  local_80 = 0x14;
  local_78 = &s_DisableGTF;
  local_70 = 0x15;
  local_60 = 0x16;
  local_68 = "BSYWaitSSF";
  if (param_2 != (byte *)0x0) {
    if ((param_3 & 1) == 0) {
      pcVar6 = NvStorUtilStrStr((char *)param_2,"ID_");
      if (pcVar6 != (char *)0x0) {
        *pcVar6 = '\0';
      }
      if (*param_2 != 0) {
        uVar11 = local_f8[0];
LAB_00026651:
        iVar10 = 0;
        local_f8[0] = 0;
        uVar7 = 0;
        while( true ) {
          bVar3 = *param_2;
          if ((bVar3 == 0) || ((bVar3 - 0x3b & 0xfd) == 0)) break;
          param_2 = param_2 + 1;
          local_58[uVar7] = bVar3;
          uVar7 = (ulonglong)(byte)((char)uVar7 + 1);
        }
        if (0x1f < uVar7) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(8);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        local_58[uVar7] = 0;
        bVar3 = *param_2;
        if (bVar3 != 0) {
          param_2 = param_2 + 1;
          if (bVar3 != 0x3b) {
            bVar3 = *param_2;
            if (bVar3 != 0) {
              do {
                local_f8[0] = iVar10;
                if (bVar3 == 0x3b) break;
                param_2 = param_2 + 1;
                iVar10 = (uint)bVar3 + (iVar10 * 5 + -0x18) * 2;
                bVar3 = *param_2;
                local_f8[0] = iVar10;
              } while (bVar3 != 0);
              if (*param_2 != 0) {
                param_2 = param_2 + 1;
              }
            }
            uVar7 = 0;
            ppcVar8 = &local_e8;
            do {
              uVar5 = NvStorUtilStrICmp(*ppcVar8,(char *)local_58);
              if ((char)uVar5 == '\0') {
                plVar1 = *(longlong **)(param_1 + 0x2830);
                if (((*(longlong *)(param_1 + 0x2820) == 0) || (plVar1 == (longlong *)0x0)) ||
                   (*plVar1 == 0)) goto LAB_0002672a;
                pcVar6 = (char *)plVar1[2];
                if (pcVar6 != (char *)0x0) goto LAB_00026755;
                goto LAB_00026721;
              }
              uVar9 = (int)uVar7 + 1;
              uVar7 = (ulonglong)uVar9;
              ppcVar8 = ppcVar8 + 2;
            } while (uVar9 < 9);
          }
          goto LAB_0002673c;
        }
      }
    }
    else {
      bVar3 = *param_2;
      while (bVar3 != 0) {
        uVar7 = 0;
        while( true ) {
          bVar3 = param_2[uVar7];
          iVar10 = (int)(char)bVar3;
          if ((byte)(bVar3 + 0xbf) < 0x1a) {
            iVar10 = iVar10 + 0x20;
          }
          iVar4 = (int)(char)(&s_dump)[uVar7];
          if ((byte)((&s_dump)[uVar7] + 0xbf) < 0x1a) {
            iVar4 = iVar4 + 0x20;
          }
          if ((iVar10 != iVar4) || (bVar3 == 0)) break;
          uVar7 = (ulonglong)((int)uVar7 + 1);
        }
        if ((&s_dump)[uVar7] == '\0') goto LAB_000265fa;
        if (param_2[uVar7] == 0) break;
        param_2 = param_2 + 1;
        bVar3 = *param_2;
      }
      param_2 = (byte *)0x0;
LAB_000265fa:
      if ((param_2 != (byte *)0x0) && (param_2[5] == 0x31)) {
        *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 2;
      }
    }
  }
  return;
LAB_00026755:
  if (*pcVar6 == -1) goto LAB_0002672a;
  if (*pcVar6 == local_e0[uVar7 * 0x10]) goto LAB_00026721;
  pcVar6 = pcVar6 + 0x128;
  goto LAB_00026755;
LAB_00026721:
  if (pcVar6 != (char *)0x0) {
    uVar11 = *(uint *)(pcVar6 + 8);
  }
LAB_0002672a:
  NvCfgElementSet(*(longlong *)(param_1 + 0x2820),plVar1,local_e0[uVar7 * 0x10],
                  (ulonglong *)local_f8,uVar11);
LAB_0002673c:
  if (*param_2 == 0) {
    return;
  }
  goto LAB_00026651;
}



===== FUN_00026768 @ 00026768 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00026768(undefined8 *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  undefined8 *puVar13;
  byte *pbVar14;
  uint uVar15;
  char **ppcVar16;
  undefined1 auStackY_2e8 [32];
  undefined1 local_2b8;
  undefined1 local_2b7;
  undefined1 local_2b6 [2];
  uint local_2b4 [3];
  char *local_2a8;
  char local_2a0 [8];
  char *local_298;
  undefined1 local_290;
  char *local_288;
  undefined1 local_280;
  char *local_278;
  undefined1 local_270;
  char *local_268;
  undefined1 local_260;
  char *local_258;
  undefined1 local_250;
  char *local_248;
  undefined1 local_240;
  char *local_238;
  undefined1 local_230;
  char *local_228;
  undefined1 local_220;
  char *local_218;
  undefined1 local_210;
  char *local_208;
  undefined1 local_200;
  char *local_1f8;
  undefined1 local_1f0;
  char *local_1e8;
  undefined1 local_1e0;
  char *local_1d8;
  undefined1 local_1d0;
  undefined1 *local_1c8;
  undefined1 local_1c0;
  char *local_1b8;
  undefined1 local_1b0;
  undefined1 *local_1a8;
  undefined1 local_1a0;
  char *local_198;
  undefined1 local_190;
  char *local_188;
  undefined1 local_180;
  char *local_178;
  undefined1 local_170;
  char *local_168;
  undefined1 local_160;
  char *local_158;
  undefined1 local_150;
  char *local_148;
  undefined1 local_140;
  undefined *local_138;
  undefined1 local_130;
  char *local_128;
  undefined1 local_120;
  char *local_118;
  undefined1 local_110;
  char *local_108;
  undefined1 local_100;
  char *local_f8;
  undefined1 local_f0;
  byte local_e8 [16];
  byte local_d8 [24];
  byte local_c0 [32];
  byte local_a0 [48];
  undefined1 local_70 [64];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_2e8;
  local_2a8 = "QueuingEnable";
  local_2a0[0] = '#';
  local_298 = "ElevatorEnable";
  local_290 = 0x24;
  local_288 = "AQEnable";
  local_280 = 0x25;
  local_278 = "DmaEnable";
  local_270 = 0x26;
  local_268 = "WriteCacheEnable";
  local_260 = 0x28;
  local_258 = "ServerFUAFeature";
  local_250 = 0x2a;
  local_248 = "QueuedThreshold";
  local_240 = 0x2b;
  local_238 = "NonQueuedThreshold";
  local_230 = 0x2c;
  local_228 = "QueuedChange";
  local_220 = 0x2d;
  local_218 = "NonQueuedChange";
  local_210 = 0x2e;
  local_208 = "SequentialMaxCount";
  local_200 = 0x2f;
  local_1f8 = "SequentialThreshold";
  local_1f0 = 0x30;
  local_1e8 = "SequentialDecrement";
  local_1e0 = 0x31;
  local_1d8 = "SataSpeedActive";
  local_1d0 = 0x33;
  local_1c8 = &s_FlushPolicy;
  local_1c0 = 0x35;
  local_1b8 = "UseBiosDefault";
  local_1b0 = 0x38;
  local_1a8 = &s_IPM;
  local_1a0 = 0x37;
  local_198 = "CCCEnable";
  local_190 = 0x41;
  local_188 = "APMEnable";
  local_180 = 0x43;
  local_178 = "ApmValue";
  local_170 = 0x44;
  local_168 = "AAMEnable";
  local_160 = 0x4a;
  local_158 = "AamValue";
  local_150 = 0x4b;
  local_148 = "WRVEnable";
  local_140 = 0x46;
  local_138 = &s_FFCEnable;
  local_130 = 0x48;
  local_128 = "ErrorInjectFailIOCount";
  local_120 = 0x4c;
  local_118 = "ErrorInjectErrorRate";
  local_110 = 0x4d;
  plVar2 = (longlong *)param_1[0xb6];
  local_108 = "ErrorInjectEnable";
  local_f8 = "ErrorInjectHang";
  local_100 = 0x4e;
  local_f0 = 0x4f;
  lVar3 = *(longlong *)(*(longlong *)*param_1 + 0x28d0);
  if ((char *)(lVar3 + 0x9f8) != (char *)0x0) {
    (**(code **)(NvStorOsCBT + 0x110))(local_e8,0xf);
    (**(code **)(NvStorOsCBT + 0x110))(local_70,0x3d);
    (**(code **)(NvStorOsCBT + 0x110))(local_a0,0x29);
    (**(code **)(NvStorOsCBT + 0x110))(local_d8,0x15);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'\x1b',(undefined8 *)local_a0,0x28);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'\x1c',(undefined8 *)local_d8,0x14);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'\x1d',(undefined8 *)&local_2b7,1);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'\x1e',(undefined8 *)(local_2b6 + 1),1);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'\x1f',(undefined8 *)local_2b6,1);
    puVar13 = (undefined8 *)&local_2b8;
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,' ',puVar13,1);
    nv_sprintf(local_e8,(byte *)"ID_%x",(ulonglong)CONCAT31(CONCAT21(local_2b6,local_2b8),local_2b7)
               ,puVar13);
    pcVar6 = NvStorUtilStrStr((char *)(lVar3 + 0x9f8),(char *)local_e8);
    if (pcVar6 != (char *)0x0) {
      cVar1 = *pcVar6;
      while (cVar1 != '=') {
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar6;
      }
      pbVar14 = (byte *)(pcVar6 + 0x29);
      uVar7 = NvStorUtilStrNCmp((byte *)(pcVar6 + 1),local_a0,0x28);
      if (((char)uVar7 == '\0') &&
         (uVar7 = NvStorUtilStrNCmp(pbVar14,local_d8,0x14), (char)uVar7 == '\0')) {
        pbVar11 = (byte *)(pcVar6 + 0x3e);
        pcVar6 = NvStorUtilStrStr((char *)pbVar14,"ID_");
        if (pcVar6 != (char *)0x0) {
          *pcVar6 = '\0';
        }
        bVar9 = *pbVar11;
        if (bVar9 != 0) {
          uVar15 = local_2b4[0];
LAB_00026b8a:
          iVar10 = 0;
          local_2b4[0] = 0;
          uVar7 = 0;
          while ((bVar9 != 0 && ((bVar9 - 0x3b & 0xfd) != 0))) {
            pbVar11 = pbVar11 + 1;
            local_c0[uVar7] = bVar9;
            uVar7 = (ulonglong)(byte)((char)uVar7 + 1);
            bVar9 = *pbVar11;
          }
          if (0x1f < uVar7) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(8);
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          local_c0[uVar7] = 0;
          bVar9 = *pbVar11;
          if (bVar9 != 0) {
            pbVar11 = pbVar11 + 1;
            if (bVar9 != 0x3b) {
              bVar9 = *pbVar11;
              if (bVar9 != 0) {
                do {
                  if (bVar9 == 0x3b) break;
                  pbVar11 = pbVar11 + 1;
                  iVar10 = (uint)bVar9 + (iVar10 * 5 + -0x18) * 2;
                  bVar9 = *pbVar11;
                } while (bVar9 != 0);
                local_2b4[0] = iVar10;
                if (*pbVar11 != 0) {
                  pbVar11 = pbVar11 + 1;
                }
              }
              uVar7 = 0;
              ppcVar16 = &local_2a8;
              do {
                uVar5 = NvStorUtilStrICmp(*ppcVar16,(char *)local_c0);
                if ((char)uVar5 == '\0') {
                  plVar2 = (longlong *)param_1[0xb6];
                  if (((*(longlong *)(*(longlong *)*param_1 + 0x2820) == 0) ||
                      (plVar2 == (longlong *)0x0)) || (*plVar2 == 0)) goto LAB_00026c6f;
                  pcVar8 = (char *)plVar2[2];
                  if (pcVar8 == (char *)0x0) goto LAB_00026c66;
                  goto LAB_00026cc9;
                }
                uVar12 = (int)uVar7 + 1;
                uVar7 = (ulonglong)uVar12;
                ppcVar16 = ppcVar16 + 2;
              } while (uVar12 < 0x1c);
            }
            goto LAB_00026c81;
          }
        }
LAB_00026c8b:
        if (pcVar6 != (char *)0x0) {
          *pcVar6 = 'I';
        }
      }
    }
  }
  return;
LAB_00026cc9:
  if (*pcVar8 == -1) goto LAB_00026c6f;
  if (*pcVar8 == local_2a0[uVar7 * 0x10]) goto LAB_00026c66;
  pcVar8 = pcVar8 + 0x128;
  goto LAB_00026cc9;
LAB_00026c66:
  if (pcVar8 != (char *)0x0) {
    uVar15 = *(uint *)(pcVar8 + 8);
  }
LAB_00026c6f:
  NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),plVar2,local_2a0[uVar7 * 0x10],
                  (ulonglong *)local_2b4,uVar15);
LAB_00026c81:
  bVar9 = *pbVar11;
  if (bVar9 == 0) goto LAB_00026c8b;
  goto LAB_00026b8a;
}



===== FUN_00026cdc @ 00026cdc =====

ulonglong FUN_00026cdc(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                      int *param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  uint local_38 [4];
  undefined1 local_28 [32];
  
  KeInitializeEvent(local_28,1);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,local_28,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_28,0,0,0,0);
      uVar2 = (ulonglong)local_38[0];
    }
    if ((param_5 != (int *)0x0) && ((*param_5 != 0x426f6541 || (param_5[2] == 0)))) {
      uVar2 = 0xc014000f;
    }
  }
  return uVar2;
}



===== NvStorGetTaskFile @ 00026dcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvStorGetTaskFile(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte bVar3;
  undefined1 auStackY_1b8 [32];
  undefined8 local_188;
  undefined1 local_180 [8];
  undefined1 local_178 [8];
  int local_170 [2];
  uint local_168;
  short local_164;
  short sStack_162;
  undefined1 local_160 [40];
  undefined4 local_138;
  undefined1 local_134 [268];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1b8;
  (**(code **)(NvStorOsCBT + 0x118))(local_134,"PRI0.MAST._GTF",0xf);
  local_138 = 0x41696541;
  StorPortExtendedFunction(8,param_1,local_180,local_178);
  uVar1 = FUN_00026cdc(local_188,0x32c018,&local_138,0x104,local_170,0x38);
  uVar2 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    if ((local_164 == 2) && (local_168 < 6)) {
      uVar1 = 0;
      *(uint *)(param_1 + 0x28dc) = local_168;
      if ((int)local_168 < 1) {
        return uVar2;
      }
      while (*(short *)(local_160 + uVar1 * 8 + -2) == 7) {
        (**(code **)(NvStorOsCBT + 0x118))(param_1 + 0x28e0 + uVar1 * 7,local_160 + uVar1 * 8,7);
        bVar3 = (char)uVar1 + 1;
        uVar1 = (ulonglong)bVar3;
        if (*(int *)(param_1 + 0x28dc) <= (int)(uint)bVar3) {
          return uVar2;
        }
      }
    }
    uVar2 = 0xc0000010;
  }
  *(undefined4 *)(param_1 + 0x28dc) = 0;
  return uVar2;
}



===== NvStorWriteDeviceSettings @ 00026f14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorWriteDeviceSettings(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  ulonglong *puVar11;
  undefined1 auStackY_2d8 [32];
  undefined1 local_2a8;
  undefined1 local_2a7;
  undefined1 local_2a6;
  undefined1 local_2a5;
  uint local_2a4;
  ulonglong local_2a0;
  char *local_298;
  char local_290 [8];
  char *local_288;
  undefined1 local_280;
  char *local_278;
  undefined1 local_270;
  char *local_268;
  undefined1 local_260;
  char *local_258;
  undefined1 local_250;
  char *local_248;
  undefined1 local_240;
  char *local_238;
  undefined1 local_230;
  char *local_228;
  undefined1 local_220;
  char *local_218;
  undefined1 local_210;
  char *local_208;
  undefined1 local_200;
  char *local_1f8;
  undefined1 local_1f0;
  char *local_1e8;
  undefined1 local_1e0;
  char *local_1d8;
  undefined1 local_1d0;
  char *local_1c8;
  undefined1 local_1c0;
  undefined1 *local_1b8;
  undefined1 local_1b0;
  char *local_1a8;
  undefined1 local_1a0;
  undefined1 *local_198;
  undefined1 local_190;
  char *local_188;
  undefined1 local_180;
  char *local_178;
  undefined1 local_170;
  char *local_168;
  undefined1 local_160;
  char *local_158;
  undefined1 local_150;
  char *local_148;
  undefined1 local_140;
  char *local_138;
  undefined1 local_130;
  undefined *local_128;
  undefined1 local_120;
  char *local_118;
  undefined1 local_110;
  char *local_108;
  undefined1 local_100;
  char *local_f8;
  undefined1 local_f0;
  char *local_e8;
  undefined1 local_e0;
  byte local_d8 [16];
  undefined8 local_c8 [3];
  byte local_b0 [24];
  undefined8 local_98 [6];
  byte local_68 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_290[0] = '#';
  local_298 = "QueuingEnable";
  local_280 = 0x24;
  local_288 = "ElevatorEnable";
  local_270 = 0x25;
  local_278 = "AQEnable";
  local_260 = 0x26;
  local_268 = "DmaEnable";
  local_250 = 0x28;
  local_258 = "WriteCacheEnable";
  local_240 = 0x2a;
  local_248 = "ServerFUAFeature";
  local_230 = 0x2b;
  local_238 = "QueuedThreshold";
  local_220 = 0x2c;
  local_228 = "NonQueuedThreshold";
  local_210 = 0x2d;
  local_218 = "QueuedChange";
  local_200 = 0x2e;
  local_208 = "NonQueuedChange";
  local_1f0 = 0x2f;
  local_1f8 = "SequentialMaxCount";
  local_1e0 = 0x30;
  local_1e8 = "SequentialThreshold";
  local_1d0 = 0x31;
  local_1d8 = "SequentialDecrement";
  local_1c0 = 0x33;
  local_1c8 = "SataSpeedActive";
  local_1b0 = 0x35;
  local_1b8 = &s_FlushPolicy;
  local_1a0 = 0x38;
  local_1a8 = "UseBiosDefault";
  local_190 = 0x37;
  local_198 = &s_IPM;
  local_180 = 0x41;
  local_188 = "CCCEnable";
  local_170 = 0x43;
  local_178 = "APMEnable";
  local_160 = 0x44;
  local_168 = "ApmValue";
  local_150 = 0x4a;
  local_158 = "AAMEnable";
  local_140 = 0x4b;
  local_148 = "AamValue";
  local_130 = 0x46;
  local_138 = "WRVEnable";
  local_120 = 0x48;
  local_128 = &s_FFCEnable;
  local_110 = 0x4c;
  local_118 = "ErrorInjectFailIOCount";
  local_100 = 0x4d;
  local_108 = "ErrorInjectErrorRate";
  local_f8 = "ErrorInjectEnable";
  plVar1 = (longlong *)param_1[0xb6];
  local_e8 = "ErrorInjectHang";
  local_f0 = 0x4e;
  local_e0 = 0x4f;
  lVar2 = *(longlong *)(*(longlong *)*param_1 + 0x28d0);
  pbVar7 = (byte *)(lVar2 + 0x9f8);
  (**(code **)(NvStorOsCBT + 0x110))(local_68,0x3d);
  (**(code **)(NvStorOsCBT + 0x110))(local_d8,0xf);
  (**(code **)(NvStorOsCBT + 0x110))(local_98,0x29);
  (**(code **)(NvStorOsCBT + 0x110))(local_c8,0x15);
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x1b',local_98,0x28);
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x1c',local_c8,0x14);
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x1d',(undefined8 *)&local_2a5,1);
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x1e',(undefined8 *)&local_2a6,1);
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x1f',(undefined8 *)&local_2a8,1);
  puVar10 = (undefined8 *)&local_2a7;
  NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,' ',puVar10,1);
  nv_sprintf(local_d8,(byte *)"ID_%x",
             (ulonglong)CONCAT31(CONCAT21(CONCAT11(local_2a6,local_2a8),local_2a7),local_2a5),
             puVar10);
  nv_sprintf(local_68,&s__s_s,(ulonglong)local_98,local_c8);
  pbVar5 = (byte *)NvStorUtilStrStr((char *)pbVar7,(char *)local_d8);
  if (pbVar5 == (byte *)0x0) {
    uVar4 = (**(code **)(NvStorOsCBT + 0x120))(pbVar7);
    pbVar5 = pbVar7 + uVar4;
    if (pbVar5 == pbVar7) goto LAB_0002734d;
    pbVar5 = pbVar5 + -1;
  }
  else {
    pcVar6 = NvStorUtilStrStr((char *)(pbVar5 + 1),"ID_");
    if (pcVar6 == (char *)0x0) goto LAB_0002734d;
    iVar3 = (**(code **)(NvStorOsCBT + 0x120))(pcVar6);
    (**(code **)(NvStorOsCBT + 0x118))(pbVar5,pcVar6,iVar3 + 1);
    pbVar5 = pbVar5 + (iVar3 - 1);
  }
  if (*pbVar5 != 0x3b) {
    pbVar5 = pbVar5 + 1;
    *pbVar5 = 0x3b;
  }
  pbVar5 = pbVar5 + 1;
LAB_0002734d:
  lVar2 = NvStorOsCBT;
  *pbVar5 = 0;
  iVar3 = (**(code **)(lVar2 + 0x120))(pbVar7);
  local_2a4 = 0x2000 - iVar3;
  pbVar7 = (byte *)FUN_00027474(pbVar5,(ulonglong)local_d8,local_68,(int *)&local_2a4);
  uVar9 = 0;
  uVar4 = local_2a4;
  do {
    local_2a0._0_4_ = 0;
    plVar1 = (longlong *)param_1[0xb6];
    if (((*(longlong *)(*(longlong *)*param_1 + 0x2820) != 0) && (plVar1 != (longlong *)0x0)) &&
       (*plVar1 != 0)) {
      pcVar6 = (char *)plVar1[2];
      if (pcVar6 == (char *)0x0) {
LAB_000273d2:
        if (pcVar6 != (char *)0x0) {
          uVar4 = *(uint *)(pcVar6 + 8);
        }
      }
      else {
        for (; *pcVar6 != -1; pcVar6 = pcVar6 + 0x128) {
          if (*pcVar6 == local_290[uVar9 * 0x10]) goto LAB_000273d2;
        }
      }
    }
    puVar11 = &local_2a0;
    NvCfgElementGet(*(longlong *)(*(longlong *)*param_1 + 0x2820),plVar1,local_290[uVar9 * 0x10],
                    puVar11,uVar4);
    nv_sprintf(local_b0,&s__u,(ulonglong)(uint)local_2a0,puVar11);
    pbVar7 = (byte *)FUN_00027474(pbVar7,(&local_2a0)[uVar9 * 2 + 1],local_b0,(int *)&local_2a4);
    bVar8 = (char)uVar9 + 1;
    uVar9 = (ulonglong)bVar8;
    if (0x1b < bVar8) {
      return;
    }
  } while( true );
}



===== FUN_00027474 @ 00027474 =====

void FUN_00027474(byte *param_1,ulonglong param_2,undefined8 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(NvStorOsCBT + 0x120))(param_2);
  iVar2 = (**(code **)(NvStorOsCBT + 0x120))(param_3);
  nv_sprintf(param_1,&s__s__s_s,param_2,param_3);
  uVar3 = (**(code **)(NvStorOsCBT + 0x120))(param_1);
  *param_4 = *param_4 - (iVar1 + 1 + iVar2);
  param_1[uVar3] = 0;
  return;
}



===== FUN_00027518 @ 00027518 =====

void FUN_00027518(void *param_1,longlong param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  
  plVar2 = *(longlong **)((longlong)param_1 + 0x10);
  lVar3 = *(longlong *)((longlong)param_1 + 0x68);
  bVar1 = *(byte *)(*plVar2 + 0xd8);
  lVar4 = *(longlong *)(param_2 + 0x2908);
  if (*(int *)((longlong)param_1 + 0x88) < 0) {
    NvStorSetSrbStatus(lVar3,(longlong)param_1);
    *(uint *)(*plVar2 + 0x120) = *(uint *)(*plVar2 + 0x120) | 2;
    StorPortNotification(0,param_2,lVar3);
    memset(param_1,0,0xf0);
    plVar2[0x112] = plVar2[0x112] & 0xffffffffbfffffff;
    return;
  }
  uVar5 = *(undefined8 *)((longlong)param_1 + 200);
  memset(param_1,0,0xf0);
  lVar7 = NvStorOsCBT;
  *(undefined8 *)((longlong)param_1 + 200) = uVar5;
  plVar2[0x112] = plVar2[0x112] & 0xffffffffbfffffff;
  (**(code **)(lVar7 + 0x118))(plVar2 + 0x426,(int)((uint)bVar1 << 10) + lVar4,0x400);
  if (*(code **)(*(longlong *)*plVar2 + 0x27f8) != (code *)0x0) {
    (**(code **)(*(longlong *)*plVar2 + 0x27f8))(plVar2);
  }
  plVar6 = *(longlong **)(lVar3 + 0x38);
  uVar5 = *(undefined8 *)*plVar2;
  uVar9 = NvStorReqSetupRequest((longlong)plVar6,plVar2,lVar3);
  if ((int)uVar9 == 1) {
    iVar8 = NvStorReqQueueInsert(plVar6[2] + 0x1a8,plVar6);
    if (-1 < iVar8) goto LAB_00027663;
    *(undefined4 *)(plVar6 + 0x11) = 0x80000006;
  }
  else if (*(longlong *)plVar6[0x1a] == 0) {
    StorPortNotification(0,uVar5,lVar3);
    goto LAB_00027663;
  }
  NvStorReqCompleteRequest((longlong)plVar6,uVar5);
LAB_00027663:
  if (gNvStorPassThroughEnabled != '\0') {
    NvStorWmiFireEvent(param_2,0x20);
  }
  return;
}



===== NvStorValidateDevice @ 00027690 =====

bool NvStorValidateDevice(longlong *param_1,uint param_2)

{
  longlong lVar1;
  bool bVar2;
  
  if ((((param_1[(ulonglong)param_2 + 1] == 0) || ((*(uint *)(param_1 + 0x24) & 2) != 0)) ||
      ((*(uint *)(param_1 + 0x24) & 4) != 0)) || ((*(uint *)(*param_1 + 0x2818) & 2) != 0)) {
    bVar2 = true;
  }
  else {
    lVar1 = StorPortGetLogicalUnit(*param_1,(char)param_1[0x1b],(char)param_1[0x1b],(char)param_2);
    bVar2 = param_1[(ulonglong)param_2 + 1] == lVar1;
  }
  return bVar2;
}



===== NvStorPortReadBufferU8 @ 000276fc =====

void NvStorPortReadBufferU8(undefined8 param_1,undefined2 param_2,undefined1 *param_3,uint param_4)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorPortReadBufferU16 @ 00027710 =====

void NvStorPortReadBufferU16(undefined8 param_1,undefined2 param_2,undefined2 *param_3,uint param_4)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorPortReadBufferU32 @ 00027724 =====

void NvStorPortReadBufferU32(undefined8 param_1,undefined2 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_4;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_2);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorRegisterReadBufferU8 @ 00027744 =====

void NvStorRegisterReadBufferU8
               (undefined8 param_1,undefined1 *param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorRegisterReadBufferU16 @ 00027764 =====

void NvStorRegisterReadBufferU16
               (undefined8 param_1,undefined2 *param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorRegisterReadBufferU32 @ 00027784 =====

void NvStorRegisterReadBufferU32
               (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_3 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorPortWriteBufferU8 @ 000277bc =====

void NvStorPortWriteBufferU8(undefined8 param_1,undefined2 param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorPortWriteBufferU16 @ 000277d0 =====

void NvStorPortWriteBufferU16
               (undefined8 param_1,undefined2 param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorPortWriteBufferU32 @ 000277e4 =====

void NvStorPortWriteBufferU32
               (undefined8 param_1,undefined2 param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_4;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_3,param_2);
    param_3 = param_3 + 1;
  }
  return;
}



===== NvStorRegisterWriteBufferU8 @ 0002781c =====

void NvStorRegisterWriteBufferU8
               (undefined8 param_1,undefined1 *param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== NvStorRegisterWriteBufferU16 @ 00027840 =====

void NvStorRegisterWriteBufferU16
               (undefined8 param_1,undefined2 *param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== NvStorRegisterWriteBufferU32 @ 00027864 =====

void NvStorRegisterWriteBufferU32
               (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== NvStorPciConfigRead @ 00027888 =====

void NvStorPciConfigRead(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  StorPortGetBusData(param_1,4,**(undefined4 **)(param_1 + 0x28d0),
                     (*(undefined4 **)(param_1 + 0x28d0))[1],param_2,param_3);
  return;
}



===== NvStorPciConfigWrite @ 000278b4 =====

void NvStorPciConfigWrite(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  StorPortSetBusDataByOffset
            (param_1,4,**(undefined4 **)(param_1 + 0x28d0),(*(undefined4 **)(param_1 + 0x28d0))[1],
             param_2,param_3,param_4);
  return;
}



===== NvStorPciConfigReadU32 @ 000278e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorPciConfigReadU32(longlong param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_148 [32];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_118;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_118._0_2_ = 0;
  memset((void *)((longlong)&local_118 + 2),0,0xfe);
  local_128 = &local_118;
  local_120 = 0x100;
  uVar1 = StorPortGetBusData(param_1,4,**(undefined4 **)(param_1 + 0x28d0),
                             (*(undefined4 **)(param_1 + 0x28d0))[1]);
  if (uVar1 < 0x100) {
    uVar2 = 0x80000003;
  }
  else {
    uVar2 = 0;
    *param_3 = *(undefined4 *)((longlong)&local_118 + (ulonglong)param_2);
  }
  return uVar2;
}



===== NvStorPciConfigWriteU32 @ 00027998 =====

void NvStorPciConfigWriteU32(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  StorPortSetBusDataByOffset
            (param_1,4,**(undefined4 **)(param_1 + 0x28d0),(*(undefined4 **)(param_1 + 0x28d0))[1],
             local_res18,param_2,4);
  return;
}



===== NvStorPciConfigReadU16 @ 000279d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorPciConfigReadU16(longlong param_1,uint param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_148 [32];
  undefined2 *local_128;
  undefined4 local_120;
  undefined2 local_118;
  undefined1 local_116 [254];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_118 = 0;
  memset(local_116,0,0xfe);
  local_128 = &local_118;
  local_120 = 0x100;
  uVar1 = StorPortGetBusData(param_1,4,**(undefined4 **)(param_1 + 0x28d0),
                             (*(undefined4 **)(param_1 + 0x28d0))[1]);
  if (uVar1 < 0x100) {
    uVar2 = 0x80000003;
  }
  else {
    uVar2 = 0;
    *param_3 = *(undefined2 *)(local_116 + ((ulonglong)param_2 - 2));
  }
  return uVar2;
}



===== NvStorPciConfigWriteU16 @ 00027a88 =====

void NvStorPciConfigWriteU16(longlong param_1,undefined4 param_2,undefined2 param_3)

{
  undefined2 local_res18 [8];
  
  local_res18[0] = param_3;
  StorPortSetBusDataByOffset
            (param_1,4,**(undefined4 **)(param_1 + 0x28d0),(*(undefined4 **)(param_1 + 0x28d0))[1],
             local_res18,param_2,2);
  return;
}



===== NvStorPciConfigReadU8 @ 00027ac8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorPciConfigReadU8(longlong param_1,uint param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_148 [32];
  undefined2 *local_128;
  undefined4 local_120;
  undefined2 local_118;
  undefined1 local_116 [254];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_118 = 0;
  memset(local_116,0,0xfe);
  local_128 = &local_118;
  local_120 = 0x100;
  uVar1 = StorPortGetBusData(param_1,4,**(undefined4 **)(param_1 + 0x28d0),
                             (*(undefined4 **)(param_1 + 0x28d0))[1]);
  if (uVar1 < 0x100) {
    uVar2 = 0x80000003;
  }
  else {
    uVar2 = 0;
    *param_3 = local_116[(ulonglong)param_2 - 2];
  }
  return uVar2;
}



===== NvStorPciConfigWriteU8 @ 00027b78 =====

void NvStorPciConfigWriteU8(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 local_res18 [16];
  
  local_res18[0] = param_3;
  StorPortSetBusDataByOffset
            (param_1,4,**(undefined4 **)(param_1 + 0x28d0),(*(undefined4 **)(param_1 + 0x28d0))[1],
             local_res18,param_2,1);
  return;
}



===== NvStorReqInitializeRequest @ 00027bb8 =====

undefined4 NvStorReqInitializeRequest(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 *_Dst;
  uint *puVar1;
  char cVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 uVar6;
  
  plVar4 = *(longlong **)(param_3 + 0xd0);
  _Dst = (undefined8 *)(param_3 + 0x40);
  memcpy(_Dst,(void *)(param_2 + 0x48),0x10);
  *(undefined8 **)(param_3 + 0x10) = param_1;
  *(undefined8 *)(param_3 + 0x30) = *(undefined8 *)(param_2 + 0x18);
  *(undefined4 *)(param_3 + 0x2c) = *(undefined4 *)(param_2 + 0x10);
  uVar6 = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_3 + 0x84) = 0xffffffff;
  *(undefined4 *)(param_3 + 0x1c) = uVar6;
  *(longlong *)(param_3 + 200) = param_3 + 0xf0;
  lVar5 = NvStorOsCBT;
  *plVar4 = param_2;
  (**(code **)(lVar5 + 0x110))(*(undefined8 *)(param_3 + 200),0x14);
  if ((*(uint *)(param_2 + 0xc) & 0x40) != 0) {
    *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 1;
  }
  if ((*(uint *)(param_2 + 0xc) & 0x20) != 0) {
    *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 2;
  }
  if (((*(uint *)(param_2 + 0xc) & 2) == 0) || (cVar2 = *(char *)(param_2 + 9), cVar2 == ' ')) {
    *(undefined4 *)(param_3 + 0x90) = 1;
  }
  else if (cVar2 == '!') {
    *(undefined4 *)(param_3 + 0x90) = 2;
  }
  else if (cVar2 == '\"') {
    *(undefined4 *)(param_3 + 0x90) = 0;
  }
  *(undefined1 *)(param_2 + 3) = 6;
  if ((*(uint *)(param_2 + 0xc) & 0x40) != 0) {
    *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 1;
  }
  cVar2 = *(char *)(param_2 + 2);
  if (cVar2 != '\0') {
    if (cVar2 == '\x02') {
      uVar6 = FUN_0002800c(param_1,param_2,param_3);
      return uVar6;
    }
    if (cVar2 != '\a') {
      if (cVar2 == '\b') {
        return 0;
      }
      if (((cVar2 == '\x12') || (cVar2 == '\x13')) || (cVar2 == ' ')) {
        return 1;
      }
      return 0x80000007;
    }
    *(undefined4 *)((longlong)param_1 + 0x8a4) = 0;
    uVar3 = *(uint *)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x2818);
    if ((uVar3 & 2) != 0) {
      *(uint *)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x2818) = uVar3 | 0x400;
    }
    if ((*(uint *)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x2818) & 2) != 0) {
      *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 0x10000;
      NvStorPrepareLinkedRequest(param_3);
      puVar1 = (uint *)(*(longlong *)(param_3 + 0x70) + 0xc0);
      *puVar1 = *puVar1 | 0x200000;
      puVar1 = (uint *)(*(longlong *)(param_3 + 0x70) + 0xc0);
      *puVar1 = *puVar1 | 0x20000;
    }
    *_Dst = 0;
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined1 *)_Dst = 0x35;
  }
  uVar6 = (**(code **)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x27b0))(param_3);
  return uVar6;
}



===== NvStorReqCompleteRequest @ 00027da0 =====

void NvStorReqCompleteRequest(longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined8 uVar6;
  
  plVar2 = *(longlong **)(param_1 + 0xd0);
  if (((*(uint *)(param_1 + 0xc0) & 0x50000) != 0) &&
     (uVar6 = NvStorReqCompleteSpecialRequest(param_1,*(int *)(param_1 + 0x88)), (char)uVar6 != '\0'
     )) {
    return;
  }
  lVar3 = *plVar2;
  if (*(longlong *)(param_1 + 0x10) != 0) {
    puVar1 = (ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
    *puVar1 = *puVar1 & 0xffffffffffefffff;
    uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890);
    if ((uVar4 & 0x4000000000000) != 0) {
      *(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x890) = uVar4 & 0xfffbffffffffffff;
    }
  }
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 0x800;
  if (lVar3 != 0) {
    if ((*(int *)(param_1 + 0x88) != -0x7ffffffa) && (*(int *)(param_1 + 0x28) == 0)) {
      *(undefined4 *)(lVar3 + 0x10) = 0;
    }
    NvStorSetSrbStatus(lVar3,param_1);
    *(undefined1 *)(lVar3 + 4) = *(undefined1 *)(param_1 + 0x8c);
    bVar5 = *(byte *)(param_1 + 0x78);
    if (*(byte *)(lVar3 + 0xb) <= *(byte *)(param_1 + 0x78)) {
      bVar5 = *(byte *)(lVar3 + 0xb);
    }
    *(byte *)(lVar3 + 0xb) = bVar5;
    if (((*(char *)(param_1 + 0x78) != '\0') && (*(longlong *)(lVar3 + 0x20) != 0)) &&
       (*(longlong *)(param_1 + 0x10) != 0)) {
      (**(code **)(NvStorOsCBT + 0x118))
                (*(longlong *)(lVar3 + 0x20),*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x198),
                 bVar5);
    }
    if (((-1 < *(int *)(param_1 + 0x88)) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) &&
       (*(byte *)(lVar3 + 0xb) != 0)) {
      memset(*(void **)(lVar3 + 0x20),0,(ulonglong)*(byte *)(lVar3 + 0xb));
    }
    StorPortNotification(0,param_2,lVar3);
  }
  return;
}



===== NvStorSetSrbStatus @ 00027ee4 =====

void NvStorSetSrbStatus(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x88);
  if (0 < iVar1) {
    if (iVar1 == 1) {
      *(undefined1 *)(param_1 + 3) = 0;
    }
    goto LAB_00027fa2;
  }
  if (iVar1 == 0) {
LAB_00027f93:
    *(undefined1 *)(param_1 + 3) = 1;
    goto LAB_00027fa2;
  }
  if (iVar1 < -0x7ffffff7) {
    if (iVar1 != -0x7ffffff8) {
      if (iVar1 == -0x7ffffffe) {
        *(undefined1 *)(param_1 + 3) = 2;
        goto LAB_00027fa2;
      }
      if (iVar1 == -0x7ffffffd) goto LAB_00027f4e;
      if (iVar1 == -0x7ffffffc) {
        *(undefined1 *)(param_1 + 3) = 0x12;
        goto LAB_00027fa2;
      }
      if (iVar1 == -0x7ffffffb) goto LAB_00027f93;
      if (iVar1 == -0x7ffffffa) {
        *(undefined1 *)(param_1 + 3) = 5;
        goto LAB_00027fa2;
      }
      if (iVar1 != -0x7ffffff9) goto LAB_00027fa2;
    }
    *(undefined1 *)(param_1 + 3) = 6;
  }
  else {
    if ((iVar1 == -0x7ffffff7) || (iVar1 == -0x7ffffff0)) {
      *(undefined1 *)(param_1 + 3) = 8;
      goto LAB_00027fa2;
    }
    if ((iVar1 != -0x7fffffef) && (iVar1 != -0x7fffffee)) {
      if (iVar1 == -0x7fffffeb) {
        *(undefined1 *)(param_1 + 3) = 0xe;
      }
      goto LAB_00027fa2;
    }
LAB_00027f4e:
    *(undefined1 *)(param_1 + 3) = 4;
  }
LAB_00027fa2:
  if (*(char *)(param_2 + 0x8d) != '\0') {
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x80;
  }
  return;
}



===== NvStorSataHandleSmartSuccess @ 00027fb0 =====

void NvStorSataHandleSmartSuccess(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x88) = 0;
  NvStorSataHandleSmartCompletion(param_1);
                    /* WARNING: Could not recover jumptable at 0x00027fd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x10) + 0x370))(param_1);
  return;
}



===== NvStorSataHandleSmartError @ 00027fd8 =====

void NvStorSataHandleSmartError(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x88) = param_2;
  NvStorSataHandleSmartCompletion(param_1);
                    /* WARNING: Could not recover jumptable at 0x00028005. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x10) + 0x378))(param_1,param_2);
  return;
}



===== FUN_0002800c @ 0002800c =====

undefined4 FUN_0002800c(undefined8 *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (*(uint *)(param_2 + 0x10) < 0x1c) {
    return 0x80000008;
  }
  lVar2 = *(longlong *)(param_2 + 0x18);
  if (lVar2 == 0) {
    return 0x80000003;
  }
  uVar1 = *(uint *)(lVar2 + 0x10);
  if (uVar1 == 0x1b0013) {
    return 0;
  }
  if (uVar1 == 0x1b0500) {
    uVar4 = FUN_00028260(param_1,lVar2,param_3);
    uVar3 = (undefined4)uVar4;
  }
  else if (uVar1 == 0x1b0501) {
    uVar4 = FUN_0002831c(param_1,lVar2,param_3);
    uVar3 = (undefined4)uVar4;
  }
  else {
    if (uVar1 < 0x1b0502) {
      return 0;
    }
    if (0x1b050c < uVar1) {
      if (uVar1 == 0x1b0800) {
        if (0x37 < *(uint *)(param_2 + 0x10)) {
          memcpy((void *)(lVar2 + 0x1c),(void *)(*(longlong *)(param_3 + 0x10) + 0x38),0x1c);
          goto LAB_00028101;
        }
      }
      else {
        if (uVar1 != 0x1b0801) {
          return 0;
        }
        *(undefined1 *)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x28d8) = 0;
        if (*(int *)(lVar2 + 0x14) == 1) {
          *(undefined1 *)(*(longlong *)**(undefined8 **)(param_3 + 0x10) + 0x28d8) = 1;
        }
        if (0x4f < *(uint *)(param_2 + 0x10)) {
          lVar2 = *(longlong *)(param_2 + 0x18);
          *(undefined8 *)(lVar2 + 0x2c) = *(undefined8 *)(param_3 + 0x10);
          *(undefined1 **)(lVar2 + 0x44) = &NvStorCrashDumpInitialize;
LAB_00028101:
          if ((*(void **)(param_2 + 0x20) != (void *)0x0) && (*(byte *)(param_2 + 0xb) != 0)) {
            memset(*(void **)(param_2 + 0x20),0,(ulonglong)*(byte *)(param_2 + 0xb));
          }
          *(undefined4 *)(param_3 + 0x88) = 0;
          *(undefined2 *)(param_2 + 3) = 1;
          return 0;
        }
      }
      return 0x80000008;
    }
    uVar4 = FUN_000283f8(param_1,lVar2,param_3);
    uVar3 = (undefined4)uVar4;
  }
  return uVar3;
}



===== NvStorSataHandleSmartCompletion @ 00028164 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorSataHandleSmartCompletion(longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 auStack_48 [32];
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_1f;
  undefined1 local_1d;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (param_1 == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = **(longlong **)(param_1 + 0xd0);
  }
  lVar2 = *(longlong *)(lVar2 + 0x18);
  *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x28);
  (**(code **)(NvStorOsCBT + 0x110))(&local_28,0xd);
  pcVar1 = *(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x27d8);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,&local_28);
  }
  if (*(int *)(lVar2 + 0x10) == 0x1b0506) {
    *(undefined1 *)(lVar2 + 0x2c) = 0xda;
    *(undefined1 *)(lVar2 + 0x32) = 0xb0;
    *(undefined4 *)(lVar2 + 0x1c) = 8;
    *(undefined1 *)(lVar2 + 0x2d) = local_27;
    *(undefined1 *)(lVar2 + 0x2e) = local_26;
    *(undefined1 *)(lVar2 + 0x2f) = local_25;
    *(undefined1 *)(lVar2 + 0x30) = local_24;
    *(undefined1 *)(lVar2 + 0x31) = local_1f;
  }
  if (*(int *)(param_1 + 0x88) == 0) {
    *(undefined2 *)(lVar2 + 0x20) = 0;
  }
  else {
    *(undefined1 *)(lVar2 + 0x20) = 1;
    *(undefined1 *)(lVar2 + 0x21) = local_1d;
  }
  *(int *)(param_1 + 0x28) = *(int *)(lVar2 + 0x1c) + 0x2c;
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(**(longlong **)(param_1 + 0xd0) + 0x18);
  return;
}



===== FUN_00028260 @ 00028260 =====

undefined8 FUN_00028260(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (*(uint *)(param_2 + 0x18) < 0x18) {
    uVar1 = 0x80000005;
  }
  else if ((*(byte *)(param_1 + 0x112) & 0x20) == 0) {
    *(undefined2 *)(param_2 + 0x1c) = 0x101;
    *(undefined1 *)(param_2 + 0x1e) = 0;
    if ((*(byte *)(param_1 + 0x112) & 0x20) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 1;
    }
    else {
      *(undefined4 *)(param_2 + 0x20) = 2;
    }
    if ((*(code **)(*(longlong *)*param_1 + 0x27e8) != (code *)0x0) &&
       (lVar2 = (**(code **)(*(longlong *)*param_1 + 0x27e8))(), lVar2 != 0)) {
      if ((*(byte *)(lVar2 + 0xa4) & 1) != 0) {
        *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 4;
      }
      *(byte *)(param_2 + 0x1f) = (-((*(byte *)(param_1 + 0x112) & 0x20) != 0) & 0xeU) + 2;
      *(undefined4 *)(param_3 + 0x28) = 0x34;
      return 0;
    }
    uVar1 = 0x80000003;
  }
  else {
    uVar1 = 0x80000002;
  }
  return uVar1;
}



===== FUN_0002831c @ 0002831c =====

undefined8 FUN_0002831c(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (0x1f < *(uint *)(param_2 + 0x18)) {
    uVar3 = *(undefined8 *)(param_2 + 0x1c);
    cVar2 = (char)((ulonglong)*(undefined8 *)(param_2 + 0x24) >> 0x10);
    if (((cVar2 != -0x14) || ((*(byte *)(param_1 + 0x112) & 0x20) != 0)) &&
       ((cVar2 != -0x5f || ((*(byte *)(param_1 + 0x112) & 0x20) == 0)))) {
      *(undefined1 *)(param_2 + 0x20) = 3;
      return 0x80000008;
    }
    if (0x20f < *(uint *)(param_2 + 0x18)) {
      if (*(code **)(*(longlong *)*param_1 + 0x27e8) != (code *)0x0) {
        uVar1 = (**(code **)(*(longlong *)*param_1 + 0x27e8))(param_1);
      }
      (**(code **)(NvStorOsCBT + 0x118))(param_2 + 0x2c,uVar1,0x200,uVar1,uVar3);
      *(undefined4 *)(param_2 + 0x1c) = 0x200;
      *(undefined2 *)(param_2 + 0x20) = 0;
      *(undefined4 *)(param_3 + 0x28) = 0x22d;
      return 0;
    }
    *(undefined2 *)(param_2 + 0x20) = 4;
  }
  return 0x80000005;
}



===== FUN_000283f8 @ 000283f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_000283f8(undefined8 *param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_26;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  if (0x1f < *(uint *)(param_2 + 0x18)) {
    local_58 = *(ulonglong *)(param_2 + 0x1c);
    local_50 = *(undefined8 *)(param_2 + 0x24);
    local_48 = *(undefined8 *)(param_2 + 0x2c);
    local_40 = *(undefined8 *)(param_2 + 0x34);
    local_38 = *(undefined1 *)(param_2 + 0x3c);
    *(undefined8 **)(param_3 + 0x10) = param_1;
    iVar1 = *(int *)(param_2 + 0x10);
    if (iVar1 == 0x1b050c) {
      if ((local_58 & 0xffffffff) + 0x20 <= (ulonglong)*(uint *)(param_2 + 0x18)) {
        if ((uint)local_58 == 0) {
          return 0x80000008;
        }
        *(uint *)(param_3 + 0x2c) = (uint)local_58;
        *(undefined4 *)(param_3 + 0xc4) = 7;
        *(longlong *)(param_3 + 0x30) = param_2 + 0x3c;
        goto LAB_00028543;
      }
    }
    else if (((iVar1 - 0x1b0502U & 0xfffffff6) == 0) && (iVar1 != 0x1b050a)) {
      uVar3 = 0x200;
      if ((iVar1 != 0x1b0502) && ((iVar1 != 0x1b0503 && (uVar3 = 0, iVar1 == 0x1b050b)))) {
        uVar3 = 0x200;
      }
      if (((local_58 & 0xffffffff) + 0x10 <= (ulonglong)*(uint *)(param_2 + 0x18)) &&
         ((uVar3 <= (uint)local_58 || (uVar3 <= *(uint *)(param_2 + 0x18) - 0x10)))) {
        *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 1;
        *(uint *)(param_3 + 0x2c) = uVar3;
        *(longlong *)(param_3 + 0x30) = param_2 + 0x2c;
        *(undefined4 *)(param_3 + 0xc4) = 8;
        goto LAB_00028543;
      }
    }
    else if ((iVar1 != 0x1b0506) ||
            ((local_58 & 0xffffffff) + 0x10 <= (ulonglong)*(uint *)(param_2 + 0x18))) {
      *(undefined4 *)(param_3 + 0x2c) = 0;
      *(undefined4 *)(param_3 + 0xc4) = 9;
      *(longlong *)(param_3 + 0x30) = param_2;
LAB_00028543:
      (**(code **)(NvStorOsCBT + 0x110))(&local_30,0xd);
      local_30 = local_58._4_1_;
      local_2f = local_58._5_1_;
      local_2e = local_58._6_1_;
      local_2d = local_58._7_1_;
      local_2c = (undefined1)local_50;
      local_26 = local_50._2_1_;
      if (*(code **)(*(longlong *)*param_1 + 0x27e0) != (code *)0x0) {
        (**(code **)(*(longlong *)*param_1 + 0x27e0))(param_3,&local_30);
      }
      if (*(code **)(*(longlong *)*param_1 + 0x27f0) != (code *)0x0) {
        (**(code **)(*(longlong *)*param_1 + 0x27f0))(param_3);
      }
      *(code **)(param_3 + 0x98) = NvStorSataHandleSmartSuccess;
      *(code **)(param_3 + 0xa0) = NvStorSataHandleSmartError;
      uVar2 = param_1[0x70];
      *(uint *)(param_3 + 0xc0) = *(uint *)(param_3 + 0xc0) | 0x4000;
      *(undefined8 *)(param_3 + 0xa8) = uVar2;
      return 1;
    }
  }
  return 0x80000005;
}



===== NvStorGetPortNumberForIoctls @ 00028604 =====

ulonglong NvStorGetPortNumberForIoctls(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong in_RAX;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (lVar2 == 0) {
    *param_2 = 0x80000003;
  }
  else {
    iVar1 = *(int *)(lVar2 + 0x10);
    *param_2 = 1;
    uVar3 = iVar1 - 0x1b0501;
    in_RAX = (ulonglong)uVar3;
    if (0xb < uVar3) {
      return (ulonglong)CONCAT31((int3)(uVar3 >> 8),*(undefined1 *)(param_1 + 6));
    }
    if (0x1f < *(uint *)(lVar2 + 0x18)) {
      return *(ulonglong *)(lVar2 + 0x24) >> 0x20;
    }
    *param_2 = 0x80000005;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== NvStorReqCompleteSpecialRequest @ 00028674 =====

undefined8 NvStorReqCompleteSpecialRequest(longlong param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong *plVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  uVar2 = *(uint *)(param_1 + 0xc0);
  uVar5 = (ulonglong)uVar2;
  if ((uVar2 >> 0x12 & 1) == 0) {
    if (param_2 < 0) {
      if (*(longlong *)(param_1 + 0x70) != 0) {
        uVar5 = (**(code **)(NvStorOsCBT + 0x108))
                          (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),
                           *(longlong *)(param_1 + 0x70),0);
      }
      return uVar5 & 0xffffffffffffff00;
    }
    plVar3 = *(longlong **)(param_1 + 0x70);
    *(int *)(param_1 + 0x88) = param_2;
    if (plVar3 != (longlong *)0x0) {
      iVar4 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x10) + 0x27b0))(plVar3);
      if (iVar4 == 1) {
        if (plVar3[2] == 0) {
          iVar4 = -0x7ffffffd;
        }
        else {
          uVar6 = NvStorInitializeScsi(plVar3[2],(longlong)plVar3);
          iVar4 = (int)uVar6;
        }
        if ((iVar4 == 1) &&
           (uVar5 = NvStorReqQueueInsert(plVar3[2] + 0x1a8,plVar3), (int)uVar5 == 0))
        goto LAB_000286e1;
      }
      uVar5 = (**(code **)(NvStorOsCBT + 0x108))(**(undefined8 **)plVar3[2],plVar3,0);
    }
  }
  else {
    if (((uVar2 >> 0x10 & 1) != 0) && (*(longlong *)(param_1 + 0x68) != 0)) {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x68) + 0xc0);
      *puVar1 = *puVar1 & 0xfffeffff;
      (**(code **)(NvStorOsCBT + 0x1c0))
                (*(longlong *)(param_1 + 0x68),
                 *(undefined8 *)**(undefined8 **)(*(longlong *)(param_1 + 0x68) + 0x10),1);
    }
    uVar5 = (**(code **)(NvStorOsCBT + 0x108))
                      (*(undefined8 *)**(undefined8 **)(param_1 + 0x10),param_1,0);
  }
LAB_000286e1:
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== NvStorCompleteControllerIoctls @ 0002879c =====

undefined8 NvStorCompleteControllerIoctls(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  if (*(uint *)(param_2 + 0x10) < 0x1c) {
    return 0x80000005;
  }
  lVar1 = *(longlong *)(param_2 + 0x18);
  if (lVar1 == 0) {
    return 0x80000003;
  }
  **(longlong **)(param_3 + 0xd0) = param_2;
  if (*(int *)(lVar1 + 0x10) == 0x1b0802) {
    if (*(uint *)(lVar1 + 0x18) < 0xd) {
      return 0x80000005;
    }
    *(undefined1 *)(lVar1 + 0x1c) = *(undefined1 *)(param_1 + 0x25f4);
    *(undefined1 *)(lVar1 + 0x1d) = *(undefined1 *)(param_1 + 0x25f5);
    *(undefined1 *)(lVar1 + 0x1e) = *(undefined1 *)(param_1 + 0x25f6);
    *(undefined1 *)(lVar1 + 0x1f) = *(undefined1 *)(param_1 + 0x25fe);
    *(undefined2 *)(lVar1 + 0x28) = *(undefined2 *)(param_1 + 0x2600);
    *(undefined2 *)(lVar1 + 0x22) = *(undefined2 *)(param_1 + 0x25f8);
    *(undefined2 *)(lVar1 + 0x24) = *(undefined2 *)(param_1 + 0x25fa);
    *(undefined2 *)(lVar1 + 0x26) = *(undefined2 *)(param_1 + 0x25fc);
    *(undefined1 *)(lVar1 + 0x20) = *(undefined1 *)(param_1 + 0x2500);
    *(undefined4 *)(param_3 + 0x28) = 0x2a;
  }
  else {
    if (*(int *)(lVar1 + 0x10) != 0x1b0803) {
      return 1;
    }
    *(undefined4 *)(param_3 + 0x88) = 0;
    gNvStorPassThroughEnabled = 1;
  }
  return 0;
}



===== _guard_check_icall @ 00028860 =====

void _guard_check_icall(void)

{
  return;
}



===== NvStorReqSetupRequest @ 00028864 =====

ulonglong NvStorReqSetupRequest(longlong param_1,undefined8 *param_2,longlong param_3)

{
  uint *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 extraout_var;
  ulonglong uVar4;
  uint uVar5;
  
  if (*(char *)(param_3 + 2) != '\x02') {
    uVar3 = StorPortGetScatterGatherList(*(undefined8 *)*param_2);
    *(undefined8 *)(param_1 + 0x20) = uVar3;
  }
  puVar1 = *(uint **)(param_1 + 0x20);
  uVar4 = 0;
  if (puVar1 != (uint *)0x0) {
    if (0x21 < *puVar1) {
LAB_000288a7:
      *(undefined1 *)(param_3 + 3) = 6;
      return 0x80000007;
    }
    if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
      do {
        if ((puVar1[uVar4 * 6 + 4] & 1) != 0) goto LAB_000288a7;
        uVar5 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar5;
      } while (uVar5 < *puVar1);
    }
  }
  iVar2 = NvStorReqInitializeRequest(param_2,param_3,param_1);
  uVar4 = CONCAT44(extraout_var,iVar2);
  if (iVar2 == 1) {
    uVar4 = NvStorInitializeScsi((longlong)param_2,param_1);
  }
  return uVar4;
}



===== NvStorNotifyDeviceChange @ 0002890c =====

void NvStorNotifyDeviceChange(longlong param_1,undefined4 param_2)

{
  StorPortNotification(7,param_1,param_2);
  if (gNvStorPassThroughEnabled != '\0') {
    NvStorWmiFireEvent(param_1,0x21);
  }
  return;
}



===== NvStorIssueDpc @ 00028940 =====

void NvStorIssueDpc(longlong *param_1,undefined *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res8 [8];
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x28d0);
  if ((*(char *)(lVar2 + 0x10) != '\0') && (*(char *)(lVar2 + 0x11) != '\0')) {
    local_res8[0] = 0;
    StorPortNotification
              (0x1002,lVar1,lVar2 + ((ulonglong)*(byte *)(param_1 + 0x1b) * 9 + 3) * 8,param_1,
               param_2,local_res8);
    return;
  }
  if (param_2 != (undefined *)0x0) {
    (*(code *)param_2)(param_1,CONCAT71((int7)((ulonglong)lVar1 >> 8),1));
  }
  return;
}



===== NvStorGetPioTransferAddress @ 00028a2c =====

uint NvStorGetPioTransferAddress(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = **(undefined8 **)(param_1 + 0xd0);
  }
  iVar1 = StorPortExtendedFunction
                    (5,*(undefined8 *)**(undefined8 **)(param_1 + 0x10),uVar2,param_1 + 0x30);
  return -(uint)(iVar1 != 0) & 0x80000008;
}



===== NvStorDevicePause @ 00028ab4 =====

void NvStorDevicePause(longlong *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)((undefined8 *)*param_1 + 0x1b);
  StorPortPauseDevice(*(undefined8 *)*param_1,uVar1,uVar1,*(undefined1 *)((longlong)param_1 + 0x222)
                      ,param_2);
  return;
}



===== NvStorSpinLockAcquire @ 00028ae0 =====

void NvStorSpinLockAcquire(longlong param_1,int param_2,byte param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = 0;
  uVar1 = 2;
  if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
    if (param_2 == 0) {
      uVar1 = 1;
      lVar2 = *(longlong *)(param_1 + 0x28d0) + ((ulonglong)param_3 * 9 + 3) * 8;
    }
    else if (param_2 != 1) {
      if (param_2 != 2) {
        return;
      }
      uVar1 = 3;
    }
    StorPortNotification(0x1003,param_1,uVar1,lVar2,param_4);
  }
  return;
}



===== NvStorSpinLockRelease @ 00028b48 =====

void NvStorSpinLockRelease
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if ((*(uint *)(param_1 + 0x2818) & 2) == 0) {
    StorPortNotification(0x1004,param_1,param_4);
  }
  return;
}



===== NvStorDbgPrint @ 00028c18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NvStorDbgPrint(uint param_1,byte *param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong local_res18;
  undefined8 local_res20;
  undefined1 auStackY_168 [32];
  undefined1 *local_138;
  ulonglong local_130;
  undefined1 local_128 [255];
  undefined1 local_29;
  ulonglong local_28;
  
  if ((param_1 & 0xf) == 0) {
    local_28 = __security_cookie ^ (ulonglong)auStackY_168;
    uVar2 = (ulonglong)DAT_00035670;
    uVar1 = 0;
    local_res18 = param_3;
    local_res20 = param_4;
    if (DAT_00035670 != 0xffffffff) {
      uVar1 = nv_snprintf(local_128,0x100,(byte *)"{%d:%d:%d}:",uVar2);
    }
    local_130 = (ulonglong)(0x100 - uVar1);
    local_138 = local_128 + uVar1;
    nv_kvprintf(param_2,&LAB_0002c040,(byte *)&local_138,uVar2,&local_res18);
    if (local_130 != 0) {
      *local_138 = 0;
    }
    local_29 = 0;
    StorPortDebugPrint(param_1,local_128);
  }
  return;
}



===== NvStorMemPoolInit @ 00028d04 =====

undefined8 NvStorMemPoolInit(longlong param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x28d0);
  if (param_3 < 0x2881) {
    uVar4 = 0x80000008;
  }
  else {
    *(longlong *)(lVar3 + 0x990) = param_2;
    *(longlong *)(lVar3 + 0x920) = param_1;
    *(uint *)(lVar3 + 0x930) = param_3 - 0x2800;
    *(uint *)(lVar3 + 0x92c) = param_3 - 0x2800;
    *(longlong *)(lVar3 + 0x938) = param_2 + 0x2800;
    *(undefined4 *)(lVar3 + 0x928) = 0xc0debabe;
    *(undefined4 *)(lVar3 + 0x99c) = 0x100;
    *(undefined4 *)(lVar3 + 0x998) = 0x100;
    lVar1 = lVar3 + 0x968;
    plVar2 = (longlong *)(lVar3 + 0x940);
    *(longlong **)(lVar3 + 0x948) = plVar2;
    *plVar2 = (longlong)plVar2;
    *(longlong *)(lVar3 + 0x970) = lVar1;
    *(longlong *)lVar1 = lVar1;
    memset(*(void **)(lVar3 + 0x990),0,0x2800);
    plVar5 = (longlong *)FUN_00029064(lVar3 + 0x920);
    if (plVar5 == (longlong *)0x0) {
      uVar4 = 0x80000011;
    }
    else {
      *(undefined4 *)(plVar5 + 2) = *(undefined4 *)(lVar3 + 0x92c);
      plVar5[3] = *(longlong *)(lVar3 + 0x938);
      lVar3 = *plVar2;
      plVar5[1] = (longlong)plVar2;
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      *plVar2 = (longlong)plVar5;
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== NvStorMemAlloc @ 00028dcc =====

longlong NvStorMemAlloc(longlong param_1,uint param_2,uint param_3,char param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 local_38 [32];
  
  lVar4 = *(longlong *)(param_1 + 0x28d0);
  uVar8 = (ulonglong)param_3;
  uVar1 = uVar8 - 1;
  plVar6 = (longlong *)(lVar4 + 0x920);
  if ((uVar8 & uVar1) == 0) {
    if (param_4 != '\0') {
      NvStorSpinLockAcquire(*plVar6,2,0,local_38);
    }
    if ((param_2 <= *(uint *)(lVar4 + 0x930)) &&
       (plVar2 = (longlong *)(lVar4 + 0x940), (longlong *)*plVar2 != plVar2)) {
      plVar5 = (longlong *)*plVar2;
      while( true ) {
        if ((plVar5 == plVar2) || (plVar5 == (longlong *)0x0)) goto LAB_00028e7e;
        if ((param_3 == 0) || (plVar5[3] == (~uVar1 & plVar5[3]))) {
          uVar7 = plVar5[3];
        }
        else {
          uVar7 = (~uVar1 & plVar5[3]) + uVar8;
        }
        uVar3 = ((int)plVar5[2] - (int)uVar7) + (int)plVar5[3];
        if (uVar3 == param_2) break;
        plVar5 = (longlong *)*plVar5;
      }
      if (plVar5 != (longlong *)0x0) goto LAB_00028ec7;
LAB_00028e7e:
      plVar5 = (longlong *)*plVar2;
      while( true ) {
        if ((plVar5 == plVar2) || (plVar5 == (longlong *)0x0)) goto LAB_00028f01;
        if ((param_3 == 0) || (plVar5[3] == (~uVar1 & plVar5[3]))) {
          uVar7 = plVar5[3];
        }
        else {
          uVar7 = (~uVar1 & plVar5[3]) + uVar8;
        }
        uVar3 = ((int)plVar5[2] - (int)uVar7) + (int)plVar5[3];
        if (param_2 <= uVar3) break;
        plVar5 = (longlong *)*plVar5;
      }
      if (plVar5 != (longlong *)0x0) {
LAB_00028ec7:
        lVar4 = FUN_00028f40((longlong)plVar6,plVar5,param_2,uVar7,uVar3);
        if ((param_4 != '\0') && ((*(uint *)(*plVar6 + 0x2818) & 2) == 0)) {
          StorPortNotification(0x1004,*plVar6,local_38);
        }
        return lVar4;
      }
    }
LAB_00028f01:
    if ((param_4 != '\0') && ((*(uint *)(*plVar6 + 0x2818) & 2) == 0)) {
      StorPortNotification(0x1004,*plVar6,local_38);
    }
  }
  return 0;
}



===== FUN_00028f40 @ 00028f40 =====

longlong FUN_00028f40(longlong param_1,longlong *param_2,uint param_3,ulonglong param_4,uint param_5
                     )

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if ((((param_2 == (longlong *)0x0) || (*(uint *)(param_2 + 2) < param_5)) ||
      ((char)param_2[4] == '\0')) || (param_4 < (ulonglong)param_2[3])) {
LAB_00029044:
    lVar3 = 0;
  }
  else {
    if (param_2[3] != param_4) {
      plVar2 = (longlong *)FUN_00029064(param_1);
      if (plVar2 == (longlong *)0x0) goto LAB_00029044;
      plVar1 = (longlong *)(param_1 + 0x20);
      *(int *)(plVar2 + 2) = (int)param_4 - (int)param_2[3];
      plVar2[3] = param_2[3];
      lVar3 = param_2[3];
      param_2[3] = param_4;
      *(int *)(param_2 + 2) = (int)param_2[2] + ((int)lVar3 - (int)param_4);
      lVar3 = *plVar1;
      plVar2[1] = (longlong)plVar1;
      *plVar2 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar2;
      *plVar1 = (longlong)plVar2;
    }
    if (param_3 < param_5) {
      plVar2 = (longlong *)FUN_00029064(param_1);
      if (plVar2 == (longlong *)0x0) goto LAB_00029044;
      plVar1 = (longlong *)(param_1 + 0x20);
      *(uint *)(plVar2 + 2) = (int)param_2[2] - param_3;
      plVar2[3] = (ulonglong)param_3 + param_2[3];
      lVar3 = *plVar1;
      plVar2[1] = (longlong)plVar1;
      *plVar2 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar2;
      *plVar1 = (longlong)plVar2;
      *(uint *)(param_2 + 2) = param_3;
    }
    plVar2 = (longlong *)param_2[1];
    lVar3 = *param_2;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    plVar2 = (longlong *)(param_1 + 0x48);
    lVar3 = *plVar2;
    param_2[1] = (longlong)plVar2;
    *param_2 = lVar3;
    *(longlong **)(lVar3 + 8) = param_2;
    *plVar2 = (longlong)param_2;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - param_3;
    lVar3 = param_2[3];
  }
  return lVar3;
}



===== FUN_00029064 @ 00029064 =====

longlong FUN_00029064(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x7c) == 0)) {
    return 0;
  }
  lVar1 = 0;
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x78) != 0) {
    do {
      lVar1 = *(longlong *)(param_1 + 0x70) + (ulonglong)uVar2 * 0x28;
      if (*(char *)(lVar1 + 0x20) == '\0') goto LAB_000290a7;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x78));
    if (*(char *)(lVar1 + 0x20) != '\0') {
      return 0;
    }
LAB_000290a7:
    *(undefined1 *)(lVar1 + 0x20) = 1;
  }
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;
  return lVar1;
}



===== NvStorMemFree @ 000290b4 =====

void NvStorMemFree(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 local_28 [32];
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  if (param_3 != '\0') {
    NvStorSpinLockAcquire(*(longlong *)(lVar1 + 0x920),2,0,local_28);
  }
  plVar4 = *(longlong **)(lVar1 + 0x968);
  while( true ) {
    if ((plVar4 == (longlong *)(lVar1 + 0x968)) || (plVar4 == (longlong *)0x0)) goto LAB_0002913a;
    if (plVar4[3] == param_2) break;
    plVar4 = (longlong *)*plVar4;
  }
  if (plVar4 != (longlong *)0x0) {
    plVar2 = (longlong *)plVar4[1];
    lVar3 = *plVar4;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    plVar2 = (longlong *)(lVar1 + 0x940);
    lVar3 = *plVar2;
    plVar4[1] = (longlong)plVar2;
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *plVar2 = (longlong)plVar4;
    *(int *)(lVar1 + 0x930) = *(int *)(lVar1 + 0x930) + (int)plVar4[2];
  }
LAB_0002913a:
  if ((param_3 != '\0') &&
     (lVar1 = *(longlong *)(lVar1 + 0x920), (*(uint *)(lVar1 + 0x2818) & 2) == 0)) {
    StorPortNotification(0x1004,lVar1,local_28);
  }
  return;
}



===== NvStorMemZero @ 0002916c =====

void NvStorMemZero(void *param_1,uint param_2)

{
  if (param_2 != 0) {
    memset(param_1,0,(ulonglong)param_2);
  }
  return;
}



===== NvStorHeapMemAlloc @ 0002919c =====

undefined8 NvStorHeapMemAlloc(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  
  iVar1 = StorPortExtendedFunction(0,param_1,param_2,0x5453564e,local_res18);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x2508) = *(int *)(param_1 + 0x2508) + 1;
  }
  else {
    local_res18[0] = 0;
  }
  return local_res18[0];
}



===== NvStorWmiSrb @ 000291f4 =====

undefined8 NvStorWmiSrb(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  uint *puVar6;
  byte bVar7;
  uint uVar8;
  uint *puVar9;
  
  plVar2 = *(longlong **)(param_2 + 0x38);
  *plVar2 = 0;
  plVar2[1] = 0;
  plVar2[2] = 0;
  plVar2[3] = 0;
  *plVar2 = param_2;
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    lVar3 = StorPortGetLogicalUnit
                      (param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                       *(undefined1 *)(param_2 + 7));
    if (lVar3 == 0) {
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(undefined1 *)(param_2 + 3) = 4;
    }
    else {
      if ((*(uint *)(lVar3 + 0x890) >> 0x17 & 1) != 0) {
        puVar9 = *(uint **)(param_2 + 0x18);
        bVar7 = *(byte *)(param_2 + 4);
        puVar6 = *(uint **)(lVar3 + 0x888);
        uVar8 = *(uint *)(param_2 + 0x10);
        plVar4 = *(longlong **)(param_2 + 0x20);
        goto LAB_000292ad;
      }
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(undefined1 *)(param_2 + 3) = 6;
    }
  }
  else {
    puVar9 = *(uint **)(param_2 + 0x18);
    uVar8 = *(uint *)(param_2 + 0x10);
    puVar6 = (uint *)(*(longlong *)(param_1 + 0x28d0) + 0x9a8);
    plVar4 = *(longlong **)(param_2 + 0x20);
    bVar7 = *(byte *)(param_2 + 4);
    lVar3 = param_1;
LAB_000292ad:
    uVar5 = ScsiPortWmiDispatchFunction(puVar6,bVar7,lVar3,(longlong)plVar2,plVar4,uVar8,puVar9);
    if ((char)uVar5 != '\0') goto LAB_000292d8;
    uVar1 = *(undefined1 *)((longlong)plVar2 + 0x19);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)((longlong)plVar2 + 0x1c);
    *(undefined1 *)(param_2 + 3) = uVar1;
  }
  StorPortNotification(0,param_1,param_2);
LAB_000292d8:
  uVar5 = StorPortNotification(1,param_1);
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== NvStorWmiFireEvent @ 000292fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 NvStorWmiFireEvent(longlong param_1,undefined1 param_2)

{
  void *pvVar1;
  undefined1 auStack_88 [32];
  undefined4 local_68 [3];
  undefined4 local_5c;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  pvVar1 = memset(local_68,0,0x48);
  if (param_1 != 0) {
    local_5c = 0;
    local_34 = 0;
    local_50 = _NvErrorEvent;
    uStack_4c = uRam00000000000355a4;
    uStack_48 = uRam00000000000355a8;
    uStack_44 = uRam00000000000355ac;
    local_3c = 0x8a;
    local_30 = 0x40;
    local_2c = 8;
    local_68[0] = 0x48;
    local_28 = param_2;
    pvVar1 = (void *)ScsiPortNotification(8,param_1,local_68,0xff);
  }
  return CONCAT71((int7)((ulonglong)pvVar1 >> 8),1);
}



===== FUN_000293a4 @ 000293a4 =====

char FUN_000293a4(longlong param_1,longlong param_2,int param_3,undefined8 param_4,
                 undefined8 param_5,undefined4 *param_6,uint param_7,undefined2 *param_8)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  
  plVar1 = *(longlong **)(param_1 + 0x2830);
  lVar2 = *(longlong *)(param_1 + 0x28d0);
  if (param_3 == 1) {
    if (param_7 < 0x8d) {
      cVar4 = '\x12';
    }
    else {
      *param_6 = 0x8d;
      lVar3 = NvStorOsCBT;
      *param_8 = 1;
      (**(code **)(lVar3 + 0x118))((longlong)param_8 + 0x79,&s_10_6_0_23);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\0',(undefined8 *)(param_8 + 1),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x01',
                      (undefined8 *)((longlong)param_8 + 3),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x02',(undefined8 *)(param_8 + 2),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x03',
                      (undefined8 *)((longlong)param_8 + 5),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x04',(undefined8 *)(param_8 + 3),2);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x05',(undefined8 *)(param_8 + 4),2);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x06',(undefined8 *)(param_8 + 5),2);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\a',(undefined8 *)(param_8 + 6),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\b',(undefined8 *)(param_8 + 7),2);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\n',(undefined8 *)(param_8 + 8),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\v',
                      (undefined8 *)((longlong)param_8 + 0x11),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\f',(undefined8 *)(param_8 + 9),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x0e',
                      (undefined8 *)((longlong)param_8 + 0x13),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x10',(undefined8 *)(param_8 + 10),0x61);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x11',
                      (undefined8 *)((longlong)param_8 + 0x89),1);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x12',(undefined8 *)(param_8 + 0x45),2);
      NvCfgElementGet(*(longlong *)(lVar2 + 0x9e8),plVar1,'\x13',(undefined8 *)(param_8 + 0x46),1);
      cVar4 = '\x01';
    }
  }
  else {
    cVar4 = '\x04';
  }
  ScsiPortWmiPostProcess(param_2,cVar4,0x8d);
  return cVar4;
}



===== FUN_00029640 @ 00029640 =====

char FUN_00029640(longlong param_1,longlong param_2,int param_3,undefined8 param_4,uint param_5,
                 longlong param_6)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  plVar2 = *(longlong **)(param_1 + 0x2830);
  if ((param_3 == 1) && (0x8c < param_5)) {
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\n',(ulonglong *)(param_6 + 0x10),1);
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\v',(ulonglong *)(param_6 + 0x11),1);
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\f',(ulonglong *)(param_6 + 0x12),1);
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\x0e',(ulonglong *)(param_6 + 0x13),1);
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\x12',(ulonglong *)(param_6 + 0x8a),2);
    NvCfgElementSet(*(longlong *)(lVar1 + 0x9e8),plVar2,'\x13',(ulonglong *)(param_6 + 0x8c),1);
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\x04';
  }
  ScsiPortWmiPostProcess(param_2,cVar3,0x8d);
  return cVar3;
}



===== FUN_00029764 @ 00029764 =====

undefined1 FUN_00029764(undefined8 param_1,longlong param_2)

{
  ScsiPortWmiPostProcess(param_2,'\x01',0x8d);
  return 1;
}



===== NvStorInitializeControllerConfig @ 00029790 =====

int NvStorInitializeControllerConfig(longlong param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  if ((*(uint *)(param_1 + 0x2818) & 0x20) == 0) {
    lVar3 = NvStorMemAlloc(param_1,4,0,'\0');
    *(longlong *)(lVar1 + 0x9f0) = lVar3;
    if (lVar3 == 0) {
      iVar4 = -0x7fffffef;
      goto LAB_000297fb;
    }
  }
  puVar2 = *(undefined4 **)(lVar1 + 0x9f0);
  if (puVar2 == (undefined4 *)0x0) {
    iVar4 = -0x7ffffff8;
  }
  else {
    *puVar2 = 1;
    iVar4 = 0;
    *(undefined4 **)(lVar1 + 0x9e8) = puVar2;
  }
  if (-1 < iVar4) {
    *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) | 0x20;
    return iVar4;
  }
LAB_000297fb:
  if (*(longlong *)(lVar1 + 0x9f0) != 0) {
    NvStorMemFree(param_1,*(longlong *)(lVar1 + 0x9f0),'\0');
    *(undefined8 *)(lVar1 + 0x9f0) = 0;
  }
  return iVar4;
}



===== NvStorControllerConfigStop @ 00029838 =====

void NvStorControllerConfigStop(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x28d0);
  if ((*(uint *)(param_1 + 0x2818) & 0x20) != 0) {
    NvStorMemFree(param_1,*(longlong *)(lVar1 + 0x9f0),'\0');
    *(undefined8 *)(lVar1 + 0x9f0) = 0;
    *(uint *)(param_1 + 0x2818) = *(uint *)(param_1 + 0x2818) & 0xffffffdf;
  }
  return;
}



===== FUN_00029880 @ 00029880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char FUN_00029880(longlong *param_1,longlong param_2,int param_3,undefined8 param_4,
                 undefined8 param_5,uint *param_6,uint param_7,longlong *param_8)

{
  longlong *plVar1;
  ushort *puVar2;
  byte *pbVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  undefined1 auStackY_b8 [32];
  ushort local_78 [12];
  ushort local_60;
  undefined1 local_5e [38];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  plVar1 = (longlong *)param_1[0xb6];
  if (param_3 == 0) {
    lVar4 = *(longlong *)(*(longlong *)*param_1 + 0x28d0);
    *param_6 = 0xa6;
    if (param_7 < 0xa6) {
LAB_00029b1a:
      cVar6 = '\x12';
      goto LAB_0002a00a;
    }
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x18',param_8,8);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x19',param_8 + 1,0x10);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1a',param_8 + 3,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1b',
                    (undefined8 *)((longlong)param_8 + 0x1c),0x28);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1c',
                    (undefined8 *)((longlong)param_8 + 0x44),0x14);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1d',param_8 + 0xb,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1e',
                    (undefined8 *)((longlong)param_8 + 0x59),1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\x1f',
                    (undefined8 *)((longlong)param_8 + 0x5a),1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,' ',(undefined8 *)((longlong)param_8 + 0x5b)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'!',(undefined8 *)((longlong)param_8 + 0x5c)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'#',(undefined8 *)((longlong)param_8 + 0x5e)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'$',(undefined8 *)((longlong)param_8 + 0x5f)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'%',param_8 + 0xc,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'&',(undefined8 *)((longlong)param_8 + 0x61)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'\'',
                    (undefined8 *)((longlong)param_8 + 0x62),1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'(',(undefined8 *)((longlong)param_8 + 99),1
                   );
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,')',(undefined8 *)((longlong)param_8 + 100),
                    1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'*',(undefined8 *)((longlong)param_8 + 0x65)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'+',(undefined8 *)((longlong)param_8 + 0x66)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,',',(undefined8 *)((longlong)param_8 + 0x67)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'-',param_8 + 0xd,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'.',(undefined8 *)((longlong)param_8 + 0x6c)
                    ,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'/',param_8 + 0xe,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'0',(undefined8 *)((longlong)param_8 + 0x74)
                    ,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'1',param_8 + 0xf,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'2',(undefined8 *)((longlong)param_8 + 0x7c)
                    ,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'3',param_8 + 0x10,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'4',(undefined8 *)((longlong)param_8 + 0x84)
                    ,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'5',param_8 + 0x11,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'8',param_8 + 0x12,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'A',(undefined8 *)((longlong)param_8 + 0x91)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'B',(undefined8 *)((longlong)param_8 + 0x92)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'C',(undefined8 *)((longlong)param_8 + 0x93)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'D',(undefined8 *)((longlong)param_8 + 0x94)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'E',(undefined8 *)((longlong)param_8 + 0x95)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'F',(undefined8 *)((longlong)param_8 + 0x96)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'G',(undefined8 *)((longlong)param_8 + 0x97)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'H',param_8 + 0x13,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'I',(undefined8 *)((longlong)param_8 + 0x99)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'J',(undefined8 *)((longlong)param_8 + 0x9a)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'K',(undefined8 *)((longlong)param_8 + 0x9b)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'L',(undefined8 *)((longlong)param_8 + 0x9c)
                    ,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'M',param_8 + 0x14,4);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'N',(undefined8 *)((longlong)param_8 + 0xa4)
                    ,1);
    NvCfgElementGet(*(longlong *)(lVar4 + 0x9e8),plVar1,'O',(undefined8 *)((longlong)param_8 + 0xa5)
                    ,1);
  }
  else {
    if (param_3 != 1) {
      cVar6 = '\x04';
      goto LAB_0002a00a;
    }
    local_60 = 0;
    memset(local_5e,0,0x26);
    local_78[1] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[0] = 0;
    *param_6 = 0x55;
    if (param_7 < 0x55) goto LAB_00029b1a;
    *(byte *)((longlong)param_8 + 0x12) = (byte)((ulonglong)param_1[0x112] >> 0x2f) & 1;
    *param_8 = param_1[0x45];
    *(int *)(param_8 + 1) = (int)param_1[0x46];
    *(byte *)((longlong)param_8 + 0xc) = *(byte *)(param_1 + 0x112) >> 5 & 1;
    *(byte *)((longlong)param_8 + 0x54) = (byte)((ulonglong)param_1[0x112] >> 0x31) & 1;
    *(byte *)((longlong)param_8 + 0xe) = (byte)((ulonglong)param_1[0x112] >> 0x2f) & 1;
    *(ushort *)(param_8 + 2) = (ushort)((ulonglong)param_1[0x112] >> 0x2f) & 1;
    plVar1 = (longlong *)*param_1;
    if ((plVar1 != (longlong *)0x0) && (*plVar1 != 0)) {
      *(char *)((longlong)param_8 + 0xd) = (char)plVar1[0x1b];
      *(undefined1 *)((longlong)param_8 + 0xf) = *(undefined1 *)(*(longlong *)*param_1 + 0x2500);
      *(undefined1 *)((longlong)param_8 + 0x13) = *(undefined1 *)(*(longlong *)*param_1 + 0x25f4);
      *(undefined1 *)((longlong)param_8 + 0x14) = *(undefined1 *)(*(longlong *)*param_1 + 0x25f5);
      *(undefined1 *)((longlong)param_8 + 0x15) = *(undefined1 *)(*(longlong *)*param_1 + 0x25f6);
      *(undefined2 *)((longlong)param_8 + 0x16) = *(undefined2 *)(*(longlong *)*param_1 + 0x25f8);
    }
    plVar1 = (longlong *)param_1[0x110];
    if (((longlong *)*param_1 != (longlong *)0x0) && (lVar4 = *(longlong *)*param_1, lVar4 != 0)) {
      if ((*(uint *)(lVar4 + 0x25f0) & 0x1000) == 0) {
        (**(code **)(NvStorOsCBT + 0x118))(&local_60,(longlong)plVar1 + 0x36);
      }
      else {
        (**(code **)(NvStorOsCBT + 0x118))(&local_60,*plVar1 + 0x36,0x28);
        plVar1 = (longlong *)*plVar1;
      }
      (**(code **)(NvStorOsCBT + 0x118))(local_78,(longlong)plVar1 + 0x14,0x14);
    }
    puVar2 = &local_60;
    lVar4 = 0x14;
    do {
      *puVar2 = *puVar2 << 8 | *puVar2 >> 8;
      puVar2 = puVar2 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    puVar2 = local_78;
    lVar4 = 10;
    do {
      lVar5 = lVar4;
      *puVar2 = *puVar2 << 8 | *puVar2 >> 8;
      puVar2 = puVar2 + 1;
      lVar4 = lVar5 + -1;
    } while (lVar4 != 0);
    (**(code **)(NvStorOsCBT + 0x118))(param_8 + 3,&local_60,(int)lVar5 + 0x27);
    pbVar3 = (byte *)((longlong)param_8 + 0x3f);
    do {
      if ((*pbVar3 & 0xdf) != 0) break;
      *pbVar3 = 0;
      pbVar3 = pbVar3 + -1;
    } while (-1 < (longlong)pbVar3 - (longlong)(param_8 + 3));
    (**(code **)(NvStorOsCBT + 0x118))(param_8 + 8,local_78,0x14);
    pbVar3 = (byte *)((longlong)param_8 + 0x53);
    do {
      if ((*pbVar3 & 0xdf) != 0) break;
      *pbVar3 = 0;
      pbVar3 = pbVar3 + -1;
    } while (-1 < (longlong)pbVar3 - (longlong)(param_8 + 8));
  }
  cVar6 = '\x01';
LAB_0002a00a:
  ScsiPortWmiPostProcess(param_2,cVar6,*param_6);
  return cVar6;
}



===== FUN_0002a044 @ 0002a044 =====

char FUN_0002a044(undefined8 *param_1,longlong param_2,int param_3,undefined8 param_4,uint param_5,
                 longlong param_6)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    if (0xa5 < param_5) {
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'#',
                      (ulonglong *)(param_6 + 0x5e),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'%',
                      (ulonglong *)(param_6 + 0x60),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'&',
                      (ulonglong *)(param_6 + 0x61),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'(',
                      (ulonglong *)(param_6 + 99),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'*',
                      (ulonglong *)(param_6 + 0x65),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'+',
                      (ulonglong *)(param_6 + 0x66),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],',',
                      (ulonglong *)(param_6 + 0x67),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'-',
                      (ulonglong *)(param_6 + 0x68),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'.',
                      (ulonglong *)(param_6 + 0x6c),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'/',
                      (ulonglong *)(param_6 + 0x70),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'0',
                      (ulonglong *)(param_6 + 0x74),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'1',
                      (ulonglong *)(param_6 + 0x78),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'5',
                      (ulonglong *)(param_6 + 0x88),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'$',
                      (ulonglong *)(param_6 + 0x5f),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'3',
                      (ulonglong *)(param_6 + 0x80),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'8',
                      (ulonglong *)(param_6 + 0x90),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'A',
                      (ulonglong *)(param_6 + 0x91),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'C',
                      (ulonglong *)(param_6 + 0x93),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'D',
                      (ulonglong *)(param_6 + 0x94),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'F',
                      (ulonglong *)(param_6 + 0x96),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'H',
                      (ulonglong *)(param_6 + 0x98),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'J',
                      (ulonglong *)(param_6 + 0x9a),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'K',
                      (ulonglong *)(param_6 + 0x9b),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'L',
                      (ulonglong *)(param_6 + 0x9c),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'M',
                      (ulonglong *)(param_6 + 0xa0),4);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'N',
                      (ulonglong *)(param_6 + 0xa4),1);
      NvCfgElementSet(*(longlong *)(*(longlong *)*param_1 + 0x2820),(longlong *)param_1[0xb6],'O',
                      (ulonglong *)(param_6 + 0xa5),1);
      uVar2 = 0xa6;
      cVar1 = '\x01';
      goto LAB_0002a49e;
    }
  }
  else if (param_3 == 1) {
    cVar1 = '\x01';
    goto LAB_0002a49e;
  }
  cVar1 = '\x04';
LAB_0002a49e:
  ScsiPortWmiPostProcess(param_2,cVar1,uVar2);
  return cVar1;
}



===== NvStorInitializeDeviceConfig @ 0002a4c8 =====

undefined8 NvStorInitializeDeviceConfig(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = param_1[0x111];
  if ((*(uint *)(param_1 + 0x112) >> 0x16 & 1) == 0) {
    lVar2 = NvStorMemAlloc(*(longlong *)*param_1,4,0,'\0');
    *(longlong *)(lVar1 + 0x40) = lVar2;
    if (lVar2 == 0) {
      return 0x80000011;
    }
  }
  param_1[0x112] = param_1[0x112] | 0x400000;
  return 0;
}



===== NvStorDeviceConfigStop @ 0002a524 =====

void NvStorDeviceConfigStop(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = param_1[0x111];
  if ((*(uint *)(param_1 + 0x112) >> 0x16 & 1) != 0) {
    NvStorWriteDeviceSettings(param_1);
    NvStorMemFree(*(longlong *)*param_1,*(longlong *)(lVar1 + 0x40),'\0');
    *(undefined8 *)(lVar1 + 0x40) = 0;
    param_1[0x112] = param_1[0x112] & 0xffffffffffbfffff;
  }
  return;
}



===== FUN_0002a578 @ 0002a578 =====

undefined8
FUN_0002a578(longlong *param_1,longlong param_2,int param_3,undefined8 param_4,int param_5,
            uint param_6,uint param_7,char *param_8)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  char cVar10;
  
  lVar3 = NvStorOsCBT;
  plVar2 = (longlong *)param_1[0xb6];
  uVar4 = 0;
  if (param_3 == 0) {
    if (param_5 != 2) goto LAB_0002a6ad;
    lVar3 = *(longlong *)(*(longlong *)*param_1 + 0x28d0);
    uVar4 = 0x21;
    if (param_7 < 0x21) goto LAB_0002a6ad;
    (**(code **)(NvStorOsCBT + 0x110))(param_8,0x21);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,':',(undefined8 *)param_8,8);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,';',(undefined8 *)(param_8 + 8),4);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'<',(undefined8 *)(param_8 + 0xc),4);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'=',(undefined8 *)(param_8 + 0x10),4);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'>',(undefined8 *)(param_8 + 0x14),4);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'?',(undefined8 *)(param_8 + 0x1c),4);
    NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'@',(undefined8 *)(param_8 + 0x18),4);
    uVar4 = NvCfgElementGet(*(longlong *)(lVar3 + 0x9e8),plVar2,'9',(undefined8 *)(param_8 + 0x20),1
                           );
    uVar5 = CONCAT44(extraout_var,uVar4);
    uVar4 = 0x21;
  }
  else {
    if (param_3 != 1) goto LAB_0002a875;
    if (param_5 == 1) {
      uVar8 = 1;
      uVar4 = 1;
      if (param_6 == 0) goto LAB_0002a875;
      cVar10 = *param_8;
      if (cVar10 == '\0') {
        if ((param_1[0x112] & 0x800000000000U) == 0) goto LAB_0002a6ad;
      }
      else if ((param_1[0x112] & 0x800000000000U) != 0) goto LAB_0002a6ad;
      lVar3 = *(longlong *)*param_1;
      bVar1 = *(byte *)((longlong *)*param_1 + 0x1b);
      lVar9 = (ulonglong)bVar1 * 0x40 + *(longlong *)(lVar3 + 0x2910);
      lVar7 = (longlong)(int)((uint)bVar1 << 10) + *(longlong *)(lVar3 + 0x2908);
      (**(code **)(NvStorOsCBT + 0x110))(lVar7,0x400);
    }
    else {
      if (param_5 != 2) goto LAB_0002a6ad;
      uVar8 = 0x401;
      uVar4 = 0x401;
      if (param_6 < 0x401) goto LAB_0002a875;
      if ((*param_8 == '\0') || ((param_1[0x112] & 0x800000000000U) != 0)) goto LAB_0002a6ad;
      lVar7 = *(longlong *)*param_1;
      bVar1 = *(byte *)((longlong *)*param_1 + 0x1b);
      lVar9 = (ulonglong)bVar1 * 0x40 + *(longlong *)(lVar7 + 0x2910);
      lVar7 = (longlong)(int)((uint)bVar1 << 10) + *(longlong *)(lVar7 + 0x2908);
      param_1[0x112] = param_1[0x112] | 0x2000000000000;
      (**(code **)(lVar3 + 0x118))(lVar7,param_8 + 1,0x400);
      cVar10 = *param_8;
    }
    uVar5 = NvStorRaidMetaDataIo(param_1,lVar7,lVar9,FUN_0002a894,param_2,1,cVar10);
    uVar4 = uVar8;
  }
  if ((int)uVar5 != 0) {
    if ((int)uVar5 == 1) {
      return uVar5 & 0xffffffffffffff00;
    }
LAB_0002a875:
    uVar6 = ScsiPortWmiPostProcess(param_2,'\x04',0);
    return CONCAT71((int7)((ulonglong)uVar6 >> 8),4);
  }
LAB_0002a6ad:
  uVar6 = ScsiPortWmiPostProcess(param_2,'\x01',uVar4);
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
}



===== FUN_0002a894 @ 0002a894 =====

void FUN_0002a894(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  plVar1 = *(longlong **)(param_1 + 0x68);
  plVar2 = *(longlong **)(param_1 + 0x10);
  lVar3 = *plVar1;
  uVar4 = *(undefined8 *)(param_1 + 200);
  (**(code **)(NvStorOsCBT + 0x110))(param_1,0xf0);
  *(undefined8 *)(param_1 + 200) = uVar4;
  plVar2[0x112] = plVar2[0x112] & 0xffffffffbfffffff;
  ScsiPortWmiPostProcess((longlong)plVar1,'\x01',0);
  *(undefined1 *)(lVar3 + 3) = *(undefined1 *)((longlong)plVar1 + 0x19);
  *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)((longlong)plVar1 + 0x1c);
  StorPortNotification(0,param_2,lVar3);
  if ((plVar2[0x112] & 0x2000000000000U) == 0) {
    plVar2[0x112] = plVar2[0x112] | 0x1000001000000;
    NvStorNotifyDeviceChange(param_2,(uint)*(byte *)(*plVar2 + 0xd8));
  }
  return;
}



===== NvStorPnpSrb @ 0002a964 =====

ulonglong NvStorPnpSrb(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  ulonglong uVar4;
  char local_res10 [8];
  
  iVar2 = *(int *)(param_2 + 8);
  if (iVar2 == 0) {
    if ((*(byte *)(param_2 + 5) == *(byte *)(param_2 + 6)) &&
       (lVar3 = *(longlong *)
                 (param_1 + 8 +
                 ((ulonglong)*(byte *)(param_2 + 5) * 0x25 + (ulonglong)*(byte *)(param_2 + 7)) * 8)
       , lVar3 != 0)) {
      puVar1 = (ulonglong *)(lVar3 + 0x890);
      *puVar1 = *puVar1 & 0xfffffffdffffffff;
    }
  }
  else if (iVar2 == 2) {
    if ((*(byte *)(param_2 + 5) == *(byte *)(param_2 + 6)) &&
       (lVar3 = *(longlong *)
                 (param_1 + 8 +
                 ((ulonglong)*(byte *)(param_2 + 5) * 0x25 + (ulonglong)*(byte *)(param_2 + 7)) * 8)
       , lVar3 != 0)) {
      puVar1 = (ulonglong *)(lVar3 + 0x890);
      *puVar1 = *puVar1 | 0x1000000;
      *(undefined8 *)
       (param_1 + 8 +
       ((ulonglong)*(byte *)(param_2 + 5) * 0x25 + (ulonglong)*(byte *)(param_2 + 7)) * 8) = 0;
    }
  }
  else if (iVar2 == 4) {
    if ((*(byte *)(param_2 + 5) == *(byte *)(param_2 + 6)) &&
       (lVar3 = *(longlong *)
                 (param_1 + 8 +
                 ((ulonglong)*(byte *)(param_2 + 5) * 0x25 + (ulonglong)*(byte *)(param_2 + 7)) * 8)
       , lVar3 != 0)) {
      puVar1 = (ulonglong *)(lVar3 + 0x890);
      *puVar1 = *puVar1 | 0x200000000;
    }
  }
  else {
    if (iVar2 == 9) {
      _Dst = *(void **)(param_2 + 0x18);
      if (*(uint *)(param_2 + 0x10) != 0) {
        memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
      }
      NvCfgElementGet(*(longlong *)(param_1 + 0x2820),*(longlong **)(param_1 + 0x2830),'\x14',
                      (undefined8 *)local_res10,1);
      if ((local_res10[0] == '\x01') &&
         (-1 < (char)*(undefined4 *)((ulonglong)*(byte *)(param_2 + 6) * 0x128 + 0x120 + param_1)))
      {
        *(uint *)((longlong)_Dst + 4) = *(uint *)((longlong)_Dst + 4) & 0xfffffeef;
      }
      else {
        *(uint *)((longlong)_Dst + 4) = *(uint *)((longlong)_Dst + 4) | 0x110;
      }
      *(undefined1 *)(param_2 + 3) = 1;
      goto LAB_0002aaca;
    }
    if (iVar2 != 0xd) goto LAB_0002aaca;
  }
  *(undefined1 *)(param_2 + 3) = 1;
LAB_0002aaca:
  uVar4 = StorPortNotification(0,param_1,param_2);
  return uVar4 & 0xffffffffffffff00;
}



===== NvStorCrashDumpOpen @ 0002ab6c =====

ulonglong NvStorCrashDumpOpen(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  byte bVar2;
  longlong *plVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined4 extraout_var;
  ulonglong uVar9;
  
  plVar3 = *(longlong **)(param_1 + 0x10);
  puVar4 = (ulonglong *)*plVar3;
  bVar2 = *(byte *)((longlong)plVar3 + 0x222);
  uVar5 = *puVar4;
  uVar8 = 0;
  lVar6 = *(longlong *)(uVar5 + 0x28d0);
  *(uint *)(uVar5 + 0x2818) = *(uint *)(uVar5 + 0x2818) | 2;
  *(undefined8 *)(param_1 + 8) = param_2;
  uVar7 = plVar3[0x112];
  NvStorDeviceConfigStop(plVar3);
  NvStorDeviceStop(plVar3);
  NvStorDeviceRemove(plVar3);
  if (*(int *)(lVar6 + 0x29f8) == 0) {
    uVar8 = NvStorControllerStart(uVar5);
    uVar9 = CONCAT44(extraout_var,uVar8);
    if ((uVar8 & 0x80000000) != 0) goto LAB_0002ac00;
    *(undefined4 *)(uVar5 + 0x2664) = 2;
    uVar9 = NvStorDisableInterruptsGlobal(uVar5);
    uVar8 = (uint)uVar9;
    if ((uVar9 & 0x80000000) != 0) goto LAB_0002ac00;
  }
  if ((uVar7 & 0x400000000) == 0) {
    uVar9 = (ulonglong)*(uint *)(uVar5 + 0x25f0);
    if ((*(uint *)(uVar5 + 0x25f0) >> 0x15 & 1) != 0) {
      uVar9 = 0;
      if (*(code **)(uVar5 + 0x2808) != (code *)0x0) {
        uVar9 = (**(code **)(uVar5 + 0x2808))(puVar4);
        uVar8 = (uint)uVar9;
      }
    }
    if ((uVar8 & 0x80000000) != 0) goto LAB_0002ac00;
  }
  uVar9 = NvStorDeviceInitialize((longlong *)puVar4,plVar3,bVar2);
  if ((uVar9 & 0x80000000) == 0) {
    piVar1 = (int *)(lVar6 + 0x29f8);
    *piVar1 = *piVar1 + 1;
    return CONCAT71((int7)(uVar9 >> 8),1);
  }
LAB_0002ac00:
  return uVar9 & 0xffffffffffffff00;
}



===== NvStorCrashDumpWrite @ 0002ac80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvStorCrashDumpWrite(longlong param_1,char param_2,longlong *param_3,undefined8 *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 auStack_4a8 [32];
  uint local_488;
  longlong local_480;
  undefined1 local_478 [16];
  longlong *local_468;
  int local_45c;
  undefined8 local_458;
  uint local_44c;
  undefined1 local_438;
  undefined1 local_436;
  undefined1 local_435;
  undefined1 local_434;
  undefined1 local_433;
  undefined1 local_432;
  undefined1 local_431;
  undefined1 local_430;
  undefined1 local_42f;
  undefined1 local_42e;
  undefined1 local_42d;
  undefined1 local_42c;
  undefined1 local_42b;
  uint local_3f4;
  code *local_3c8;
  code *local_3c0;
  uint local_3b8;
  undefined8 *local_3b0;
  undefined1 *local_3a8;
  undefined1 local_388 [816];
  undefined8 local_58;
  ulonglong local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_4a8;
  plVar1 = *(longlong **)(param_1 + 0x10);
  lVar2 = *(longlong *)*plVar1;
  plVar1[0x112] = plVar1[0x112] & 0xfffffffff9ff3fff;
  *(undefined2 *)(plVar1 + 0x44) = 1;
  uVar4 = (ulonglong)(*(longlong *)(param_1 + 8) + *param_3) / (ulonglong)*(uint *)(plVar1 + 0x46);
  local_488 = *(uint *)(param_4 + 3);
  uVar5 = (ulonglong)local_488 / (ulonglong)*(uint *)(plVar1 + 0x46);
  local_480 = param_1;
  memset(local_478,0,0xf0);
  local_3b0 = &local_58;
  local_58 = 0;
  if ((*(uint *)(*(longlong *)*plVar1 + 0x25f0) & 0x1000) == 0) {
    local_50 = local_50 & 0xffffffffff000000;
  }
  else {
    local_50 = 0;
    local_48 = 0;
  }
  memset(local_388,0,0x330);
  local_3f4 = 0xffffffff;
  local_3a8 = local_388;
  if (param_2 == '\0') {
    local_438 = 0x8a;
  }
  else {
    local_3b8 = local_3b8 | 1;
    local_438 = 0x88;
  }
  local_42f = (undefined1)uVar4;
  local_45c = 10;
  local_436 = (undefined1)(uVar4 >> 0x38);
  local_435 = (undefined1)(uVar4 >> 0x30);
  local_434 = (undefined1)(uVar4 >> 0x28);
  local_433 = (undefined1)(uVar4 >> 0x20);
  local_432 = (undefined1)(uVar4 >> 0x18);
  local_431 = (undefined1)(uVar4 >> 0x10);
  local_430 = (undefined1)(uVar4 >> 8);
  local_42e = (undefined1)(uVar5 >> 0x18);
  local_42d = (undefined1)(uVar5 >> 0x10);
  local_42c = (undefined1)(uVar5 >> 8);
  local_44c = local_488;
  local_458 = *param_4;
  local_3c8 = _guard_check_icall;
  local_468 = plVar1;
  local_42b = (char)uVar5;
  uVar3 = (**(code **)(*(longlong *)*plVar1 + 0x27b0))(local_478);
  uVar5 = (ulonglong)uVar3;
  if ((uVar3 & 0x80000000) == 0) {
    if (local_468 == (longlong *)0x0) {
      uVar5 = 0x80000003;
    }
    else {
      uVar5 = NvStorInitializeScsi((longlong)local_468,(longlong)local_478);
      uVar5 = uVar5 & 0xffffffff;
    }
    if ((int)uVar5 == 1) {
      if (*(code **)(lVar2 + 0x2800) != (code *)0x0) {
        (**(code **)(lVar2 + 0x2800))(*plVar1);
      }
      puVar6 = local_478;
      uVar3 = (*local_3c0)(plVar1);
      uVar5 = (ulonglong)uVar3;
      if ((uVar3 & 0x80000000) == 0) {
        uVar4 = NvStorWaitForRequestCompletion(plVar1,puVar6,local_45c * 1000000);
        uVar5 = uVar4 & 0xffffffff;
        if ((uVar4 & 0x80000000) == 0) {
          if (local_3f4 != 0xffffffff) {
            uVar4 = NvStorReleaseTag(local_468,(ulonglong)local_3f4);
            uVar5 = uVar4 & 0xffffffff;
            if ((uVar4 & 0x80000000) != 0) goto LAB_0002aebc;
            local_468[(longlong)(int)local_3f4 + 0x48] = 0;
            local_3f4 = 0xffffffff;
          }
          (**(code **)(local_480 + 0x20))(param_4[1],param_2,0);
          return uVar5;
        }
        *(uint *)(lVar2 + 0x2818) = *(uint *)(lVar2 + 0x2818) | 0x80;
        NvStorPortReset((longlong *)*plVar1);
        *(uint *)(lVar2 + 0x2818) = *(uint *)(lVar2 + 0x2818) & 0xffffff7f;
      }
    }
  }
LAB_0002aebc:
  if (local_3f4 != 0xffffffff) {
    NvStorReleaseTag(local_468,(ulonglong)local_3f4);
  }
  return uVar5;
}



===== NvStorCrashDumpFinish @ 0002af3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NvStorCrashDumpFinish(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 auStack_488 [32];
  undefined1 local_468 [16];
  longlong *local_458;
  int local_44c;
  undefined1 local_428;
  uint local_3e4;
  code *local_3b0;
  undefined8 *local_3a0;
  undefined1 *local_398;
  undefined1 local_378 [816];
  undefined8 local_48;
  ulonglong local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_488;
  plVar2 = *(longlong **)(param_1 + 0x10);
  lVar3 = *(longlong *)*plVar2;
  lVar4 = *(longlong *)(lVar3 + 0x28d0);
  *(undefined4 *)((longlong)plVar2 + 0x8a4) = 0;
  memset(local_468,0,0xf0);
  local_3e4 = 0xffffffff;
  if ((((ulonglong)plVar2[0x112] >> 0xb & 1) != 0) && (((ulonglong)plVar2[0x112] >> 0xc & 1) != 0))
  {
    local_3a0 = &local_48;
    local_48 = 0;
    if ((*(uint *)(*(longlong *)*plVar2 + 0x25f0) & 0x1000) == 0) {
      local_40 = local_40 & 0xffffffffff000000;
    }
    else {
      local_40 = 0;
      local_38 = 0;
    }
    memset(local_378,0,0x330);
    local_428 = 0x35;
    local_44c = 10;
    local_398 = local_378;
    local_458 = plVar2;
    uVar5 = (**(code **)(*(longlong *)*plVar2 + 0x27b0))(local_468);
    uVar6 = (ulonglong)uVar5;
    if ((uVar5 & 0x80000000) != 0) goto LAB_0002b15d;
    if (local_458 == (longlong *)0x0) {
      uVar6 = 0x80000003;
    }
    else {
      uVar6 = NvStorInitializeScsi((longlong)local_458,(longlong)local_468);
      uVar6 = uVar6 & 0xffffffff;
    }
    if ((int)uVar6 != 1) goto LAB_0002b15d;
    if (*(code **)(lVar3 + 0x2800) != (code *)0x0) {
      (**(code **)(lVar3 + 0x2800))(*plVar2);
    }
    puVar8 = local_468;
    uVar5 = (*local_3b0)(plVar2);
    uVar6 = (ulonglong)uVar5;
    if ((uVar5 & 0x80000000) != 0) goto LAB_0002b15d;
    uVar7 = NvStorWaitForRequestCompletion(plVar2,puVar8,local_44c * 1000000);
    uVar6 = uVar7 & 0xffffffff;
    if ((uVar7 & 0x80000000) != 0) goto LAB_0002b15d;
    if (local_3e4 != 0xffffffff) {
      uVar7 = NvStorReleaseTag(local_458,(ulonglong)local_3e4);
      uVar6 = uVar7 & 0xffffffff;
      if ((uVar7 & 0x80000000) != 0) goto LAB_0002b15d;
      local_458[(longlong)(int)local_3e4 + 0x48] = 0;
      local_3e4 = 0xffffffff;
    }
  }
  if (*(longlong *)*plVar2 == 0) {
    uVar6 = 0x80000003;
  }
  else {
    if ((*(uint *)(*(longlong *)*plVar2 + 0x25f0) & 0x1000) == 0) {
      uVar5 = NvStorSataSendStandBy(plVar2);
    }
    else {
      uVar5 = NvStorAhciSendAtaRequestNoData(plVar2);
    }
    uVar6 = (ulonglong)uVar5;
  }
  if ((uVar6 & 0x80000000) == 0) {
    piVar1 = (int *)(lVar4 + 0x29f8);
    *piVar1 = *piVar1 + -1;
    uVar7 = NvStorDeviceRemove(plVar2);
    uVar6 = uVar7 & 0xffffffff;
    if ((uVar7 & 0x80000000) == 0) {
      if (*(int *)(lVar4 + 0x29f8) != 0) {
        return uVar6;
      }
      if (*(code **)(lVar3 + 0x26d8) != (code *)0x0) {
        (**(code **)(lVar3 + 0x26d8))(lVar3);
      }
      NvStorControllerConfigStop(lVar3);
      NvStorControllerStop(lVar3);
      return uVar6;
    }
  }
LAB_0002b15d:
  if (local_3e4 != 0xffffffff) {
    NvStorReleaseTag(local_458,(ulonglong)local_3e4);
  }
  return uVar6;
}



===== NvStorSataCrashDumpOpen @ 0002b19c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvStorSataCrashDumpOpen(longlong param_1,undefined8 param_2,char param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  char cVar9;
  longlong lVar10;
  undefined7 uVar11;
  undefined1 auStack_248 [32];
  undefined1 local_228 [94];
  char local_1ca;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_248;
  plVar1 = *(longlong **)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 8) = param_2;
  if ((param_3 != '\0') && ((plVar1[0x112] & 0x400000000U) == 0)) {
    *(uint *)(*(longlong *)*plVar1 + 0x2818) = *(uint *)(*(longlong *)*plVar1 + 0x2818) | 2;
    uVar5 = NvStorDeviceResetCrashdump(plVar1);
    if ((int)uVar5 < 0) {
      return uVar5 & 0xffffffffffffff00;
    }
    NvStorDeviceReset(plVar1);
  }
  cVar9 = *(char *)((longlong)plVar1 + 0x222);
  plVar2 = (longlong *)*plVar1;
  uVar4 = NvStorSataInterruptGetAppropriateMask(plVar2,cVar9);
  NvStorSataInterruptEnableDisableByMask(plVar2,cVar9,'\0',uVar4);
  if (((*(uint *)(*(longlong *)*plVar1 + 0x25f0) & 0x1000) != 0) &&
     (uVar5 = 0, *(char *)(*(longlong *)*plVar1 + 0x2500) != '\0')) {
    do {
      lVar8 = *(longlong *)*plVar1;
      lVar7 = uVar5 * 0x128 + lVar8;
      lVar10 = (uVar5 & 1) * 0x20;
      *(undefined8 *)(lVar7 + 0x18) = *(undefined8 *)(lVar10 + 0x2510 + lVar8);
      *(undefined8 *)(lVar7 + 0x20) = *(undefined8 *)(lVar10 + 0x2518 + lVar8);
      *(undefined8 *)(lVar7 + 0x28) = *(undefined8 *)(lVar10 + 0x2520 + lVar8);
      *(undefined8 *)(lVar7 + 0x30) = *(undefined8 *)(lVar10 + 0x2528 + lVar8);
      lVar8 = *(longlong *)*plVar1;
      *(undefined8 *)(lVar7 + 0x38) = *(undefined8 *)(lVar8 + 0x2550 + lVar10);
      *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar8 + 0x2558 + lVar10);
      *(undefined8 *)(lVar7 + 0x48) = *(undefined8 *)(lVar8 + 0x2560 + lVar10);
      *(undefined8 *)(lVar7 + 0x50) = *(undefined8 *)(lVar8 + 0x2568 + lVar10);
      plVar2 = *(longlong **)(lVar7 + 8);
      if ((plVar2 != (longlong *)0x0) && ((*(byte *)(plVar2 + 0x112) & 0x20) == 0)) {
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 7) + 2,6);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
        }
        (**(code **)(param_1 + 0x18))(0x32);
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 7) + 2);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
        }
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(byte *)(*(longlong *)*plVar1 + 0x2500));
  }
  lVar8 = *(longlong *)*plVar1;
  if (((*(uint *)(lVar8 + 0x25f0) & 0x1000) != 0) && (uVar5 = 0, *(char *)(lVar8 + 0x2500) != '\0'))
  {
    do {
      plVar2 = *(longlong **)(uVar5 * 0x128 + 8 + lVar8);
      if ((plVar2 != (longlong *)0x0) && ((*(byte *)(plVar2 + 0x112) & 0x20) == 0)) {
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))
                    (*puVar3,*(short *)(puVar3 + 3) + 6,((byte)uVar5 & 2) << 3);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x18);
        }
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      lVar8 = *(longlong *)*plVar1;
    } while (uVar4 < *(byte *)(lVar8 + 0x2500));
  }
  lVar8 = *(longlong *)*plVar1;
  if (((*(uint *)(lVar8 + 0x25f0) & 0x1000) != 0) && (uVar5 = 0, *(char *)(lVar8 + 0x2500) != '\0'))
  {
    do {
      plVar2 = *(longlong **)(uVar5 * 0x128 + 8 + lVar8);
      if ((plVar2 != (longlong *)0x0) && ((*(byte *)(plVar2 + 0x112) & 0x20) == 0)) {
        uVar6 = 0;
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
        puVar3 = (undefined8 *)*plVar2;
        cVar9 = ((byte)uVar5 & 2) << 3;
        uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),cVar9);
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 6,uVar6);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x18);
        }
        uVar11 = (undefined7)((ulonglong)uVar6 >> 8);
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))
                    (*puVar3,*(short *)(puVar3 + 3) + 7,CONCAT71(uVar11,0xec));
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
        }
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,200,0x48);
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x20))(*puVar3,*(undefined2 *)(puVar3 + 3),local_228,0x100);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x50))(*puVar3,puVar3[0x19],local_228,0x200);
        }
        if (local_1ca != '\0') {
          NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
          puVar3 = (undefined8 *)*plVar2;
          if (puVar3[0x19] == 0) {
            (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 6,cVar9);
          }
          else {
            (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x18);
          }
          puVar3 = (undefined8 *)*plVar2;
          uVar6 = 0;
          if (puVar3[0x19] == 0) {
            (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 2,0);
          }
          else {
            (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 8);
          }
          puVar3 = (undefined8 *)*plVar2;
          uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),local_1ca);
          if (puVar3[0x19] == 0) {
            (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 2,uVar6);
          }
          else {
            (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 8);
          }
          uVar11 = (undefined7)((ulonglong)uVar6 >> 8);
          NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
          puVar3 = (undefined8 *)*plVar2;
          if (puVar3[0x19] == 0) {
            (**(code **)(NvStorOsCBT + 0x60))
                      (*puVar3,*(short *)(puVar3 + 3) + 7,CONCAT71(uVar11,0xc6));
          }
          else {
            (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
          }
          NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
        }
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 6,cVar9);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x18);
        }
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 2,0);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 8);
        }
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 2,0xc);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 8);
        }
        puVar3 = (undefined8 *)*plVar2;
        uVar6 = 0;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 1,0);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 4);
        }
        puVar3 = (undefined8 *)*plVar2;
        uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),3);
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 3) + 1,uVar6);
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 4);
        }
        uVar11 = (undefined7)((ulonglong)uVar6 >> 8);
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
        puVar3 = (undefined8 *)*plVar2;
        if (puVar3[0x19] == 0) {
          (**(code **)(NvStorOsCBT + 0x60))
                    (*puVar3,*(short *)(puVar3 + 3) + 7,CONCAT71(uVar11,0xef));
        }
        else {
          (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
        }
        NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      lVar8 = *(longlong *)*plVar1;
    } while (uVar4 < *(byte *)(lVar8 + 0x2500));
  }
  plVar2 = (longlong *)*plVar1;
  lVar8 = *plVar2;
  if ((*(uint *)(lVar8 + 0x25f0) & 0x1000) == 0) {
    cVar9 = '\0';
  }
  else {
    cVar9 = (*(byte *)(plVar2 + 0x1b) & 2) << 3;
  }
  if (plVar2[0x19] == 0) {
    (**(code **)(NvStorOsCBT + 0x60))(lVar8,(short)plVar2[3] + 6,cVar9);
  }
  else {
    (**(code **)(NvStorOsCBT + 0x90))(lVar8,plVar2[0x19] + 0x18);
  }
  puVar3 = (undefined8 *)*plVar1;
  if (puVar3[0x19] == 0) {
    uVar6 = (**(code **)(NvStorOsCBT + 0x60))(*puVar3,*(short *)(puVar3 + 7) + 2,2);
  }
  else {
    uVar6 = (**(code **)(NvStorOsCBT + 0x90))(*puVar3,puVar3[0x19] + 0x1c);
  }
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
}



===== NvStorSataCrashDumpWrite @ 0002b894 =====

undefined8
NvStorSataCrashDumpWrite(longlong param_1,char param_2,longlong *param_3,longlong param_4)

{
  uint uVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  short sVar8;
  longlong lVar9;
  undefined7 uVar10;
  uint uVar11;
  ulonglong uVar12;
  byte bVar13;
  undefined8 uVar14;
  uint uVar15;
  
  plVar2 = *(longlong **)(param_1 + 0x10);
  NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
  puVar7 = (undefined8 *)*plVar2;
  if (puVar7[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 6);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0x18);
  }
  uVar15 = *(uint *)(param_4 + 0x18);
  uVar6 = *(undefined8 *)(param_4 + 8);
  uVar12 = *(longlong *)(param_1 + 8) + *param_3;
  uVar1 = *(uint *)(plVar2 + 0x47);
  uVar14 = 0;
  uVar4 = NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
  if ((char)uVar4 < '\0') {
    return 0x80000006;
  }
  uVar10 = (undefined7)((ulonglong)uVar14 >> 8);
  if ((*(byte *)(plVar2 + 0x112) & 0x10) == 0) {
    plVar3 = (longlong *)*plVar2;
    if ((*(uint *)(*plVar3 + 0x25f0) & 0x1000) == 0) {
      bVar13 = 0;
    }
    else {
      uVar5 = CONCAT71(uVar10,(char)plVar3[0x1b]) & 0xffffffffffffff02;
      uVar10 = (undefined7)(uVar5 >> 8);
      bVar13 = (char)uVar5 << 3;
    }
    if (plVar3[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])
                (*plVar3,(short)plVar3[3] + 6,
                 CONCAT71(uVar10,bVar13 | (byte)(uVar12 >> 0x21) & 0xf | 0x40));
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*plVar3,plVar3[0x19] + 0x18);
    }
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 3,uVar12 >> 9 & 0xff);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0xc);
    }
    puVar7 = (undefined8 *)*plVar2;
    uVar5 = uVar12 >> 0x11;
    if (puVar7[0x19] != 0) {
      lVar9 = puVar7[0x19] + 0x10;
      goto LAB_0002bb5e;
    }
    sVar8 = *(short *)(puVar7 + 3) + 4;
  }
  else {
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])
                (*puVar7,*(short *)(puVar7 + 3) + 3,CONCAT71(uVar10,(char)(uVar12 >> 0x21)));
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0xc);
    }
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 3,uVar12 >> 9 & 0xff);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0xc);
    }
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 4,uVar12 >> 0x29 & 0xff);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0x10);
    }
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 4,uVar12 >> 0x11 & 0xff);
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0x10);
    }
    puVar7 = (undefined8 *)*plVar2;
    uVar5 = uVar12 >> 0x31;
    if (puVar7[0x19] != 0) {
      lVar9 = puVar7[0x19] + 0x14;
LAB_0002bb5e:
      (*(code *)NvStorOsCBT[0x12])(*puVar7,lVar9);
      goto LAB_0002bb77;
    }
    sVar8 = *(short *)(puVar7 + 3) + 5;
  }
  (*(code *)NvStorOsCBT[0xc])(*puVar7,sVar8,uVar5 & 0xff);
LAB_0002bb77:
  puVar7 = (undefined8 *)*plVar2;
  if (puVar7[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 5,uVar12 >> 0x19 & 0xff);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar7,puVar7[0x19] + 0x14);
  }
  puVar7 = (undefined8 *)*plVar2;
  lVar9 = puVar7[0x19];
  if ((*(byte *)(plVar2 + 0x112) & 0x10) != 0) {
    if (lVar9 == 0) {
      (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 2,(char)((uVar15 >> 9) >> 8));
    }
    else {
      (*(code *)NvStorOsCBT[0x12])(*puVar7,lVar9 + 8);
    }
    puVar7 = (undefined8 *)*plVar2;
    lVar9 = puVar7[0x19];
  }
  if (lVar9 == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar7,*(short *)(puVar7 + 3) + 2,(char)(uVar15 >> 9));
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar7,lVar9 + 8);
  }
  NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0xc0,0x40);
  puVar7 = (undefined8 *)*plVar2;
  if (puVar7[0x19] == 0) {
    uVar12 = (ulonglong)(ushort)(*(short *)(puVar7 + 3) + 7);
    (*(code *)NvStorOsCBT[0xc])(*puVar7,uVar12);
  }
  else {
    uVar12 = puVar7[0x19] + 0x1c;
    (*(code *)NvStorOsCBT[0x12])(*puVar7,uVar12);
  }
  for (; 0 < (int)uVar15; uVar15 = uVar15 - uVar11) {
    uVar12 = CONCAT71((int7)(uVar12 >> 8),0x80);
    uVar5 = NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
    if ((char)uVar5 < '\0') {
      return 0x80000006;
    }
    uVar11 = uVar1;
    if ((int)uVar15 < (int)uVar1) {
      uVar11 = uVar15;
    }
    if ((uVar5 & 8) == 0) break;
    NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,200,0x48);
    puVar7 = (undefined8 *)*plVar2;
    uVar12 = puVar7[0x19];
    if (param_2 == '\0') {
      if (uVar12 == 0) {
        uVar12 = (ulonglong)*(ushort *)(puVar7 + 3);
        if ((uVar11 & 1) == 0) {
          (*(code *)NvStorOsCBT[0x10])();
        }
        else {
          (*(code *)NvStorOsCBT[0xf])(*puVar7,uVar12);
        }
      }
      else {
        (*(code *)NvStorOsCBT[0x16])(*puVar7);
      }
    }
    else if (uVar12 == 0) {
      uVar12 = (ulonglong)*(ushort *)(puVar7 + 3);
      if ((uVar11 & 1) == 0) {
        (*(code *)NvStorOsCBT[4])();
      }
      else {
        (*(code *)NvStorOsCBT[3])(*puVar7,uVar12);
      }
    }
    else {
      (*(code *)NvStorOsCBT[10])(*puVar7);
    }
  }
  uVar10 = (undefined7)(uVar12 >> 8);
  uVar12 = NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar2,0x80,0);
  (**(code **)(param_1 + 0x20))(uVar6,CONCAT71(uVar10,param_2),0);
  if ((uVar12 & 1) == 0) {
    uVar6 = 0;
  }
  else {
    puVar7 = (undefined8 *)*plVar2;
    if (puVar7[0x19] == 0) {
      (*(code *)*NvStorOsCBT)(*puVar7,*(short *)(puVar7 + 3) + 1);
    }
    else {
      (*(code *)NvStorOsCBT[6])(*puVar7,puVar7[0x19] + 4);
    }
    uVar6 = 0x80000003;
  }
  return uVar6;
}



===== NvStorSataCrashDumpFinish @ 0002bdc0 =====

undefined8 NvStorSataCrashDumpFinish(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  byte bVar5;
  uint uVar6;
  uint7 uVar10;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  plVar1 = *(longlong **)(param_1 + 0x10);
  uVar9 = 0;
  NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar1,0x80,0);
  plVar2 = (longlong *)*plVar1;
  lVar3 = *plVar2;
  uVar10 = (uint7)((ulonglong)uVar9 >> 8);
  if ((*(uint *)(lVar3 + 0x25f0) & 0x1000) == 0) {
    lVar8 = (ulonglong)uVar10 << 8;
  }
  else {
    uVar7 = CONCAT71(uVar10,(char)plVar2[0x1b]) & 0xffffffffffffff02;
    lVar8 = CONCAT71((int7)(uVar7 >> 8),(char)uVar7 << 3);
  }
  if (plVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(lVar3,(short)plVar2[3] + 6,lVar8);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(lVar3,plVar2[0x19] + 0x18);
  }
  puVar4 = (undefined8 *)*plVar1;
  uVar7 = CONCAT71((int7)((ulonglong)lVar8 >> 8),-((*(byte *)(plVar1 + 0x112) & 0x10) != 0)) &
          0xffffffffffffff03;
  uVar9 = CONCAT71((int7)(uVar7 >> 8),(char)uVar7 + -0x19);
  if (puVar4[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar4,*(short *)(puVar4 + 3) + 7,uVar9);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar4,puVar4[0x19] + 0x1c);
  }
  uVar6 = 0;
  (**(code **)(param_1 + 0x18))(1000);
  do {
    puVar4 = (undefined8 *)*plVar1;
    if (puVar4[0x19] == 0) {
      bVar5 = (*(code *)*NvStorOsCBT)(*puVar4,*(short *)(puVar4 + 3) + 7);
    }
    else {
      bVar5 = (*(code *)NvStorOsCBT[6])(*puVar4,puVar4[0x19] + 0x1c);
    }
    if (((bVar5 & 8) == 0) && (-1 < (char)bVar5)) break;
    (**(code **)(param_1 + 0x18))(1000);
    uVar6 = uVar6 + 1000;
  } while (uVar6 < 30000000);
  plVar2 = (longlong *)*plVar1;
  lVar3 = *plVar2;
  uVar10 = (uint7)((ulonglong)uVar9 >> 8);
  if ((*(uint *)(lVar3 + 0x25f0) & 0x1000) == 0) {
    lVar8 = (ulonglong)uVar10 << 8;
  }
  else {
    uVar7 = CONCAT71(uVar10,(char)plVar2[0x1b]) & 0xffffffffffffff02;
    lVar8 = CONCAT71((int7)(uVar7 >> 8),(char)uVar7 << 3);
  }
  if (plVar2[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(lVar3,(short)plVar2[3] + 6,lVar8);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(lVar3,plVar2[0x19] + 0x18);
  }
  puVar4 = (undefined8 *)*plVar1;
  if (puVar4[0x19] == 0) {
    (*(code *)NvStorOsCBT[0xc])(*puVar4,*(short *)(puVar4 + 3) + 7,0xe0);
  }
  else {
    (*(code *)NvStorOsCBT[0x12])(*puVar4,puVar4[0x19] + 0x1c);
  }
  NvStorNonIntWaitOnPortStatus((undefined8 *)*plVar1,0xc0,0x40);
  puVar4 = (undefined8 *)*plVar1;
  if (puVar4[0x19] == 0) {
    (*(code *)*NvStorOsCBT)(*puVar4,*(short *)(puVar4 + 3) + 7);
  }
  else {
    (*(code *)NvStorOsCBT[6])(*puVar4,puVar4[0x19] + 0x1c);
  }
  return 0;
}



===== nv_sprintf @ 0002bfb8 =====

void nv_sprintf(byte *param_1,byte *param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  iVar1 = nv_kvprintf(param_2,(undefined *)0x0,param_1,param_4,&local_res18);
  param_1[iVar1] = 0;
  return;
}



===== nv_snprintf @ 0002bff4 =====

void nv_snprintf(undefined1 *param_1,longlong param_2,byte *param_3,ulonglong param_4)

{
  ulonglong local_res20;
  undefined1 *local_18;
  longlong local_10;
  
  local_res20 = param_4;
  local_18 = param_1;
  local_10 = param_2;
  nv_kvprintf(param_3,&LAB_0002c040,(byte *)&local_18,param_4,&local_res20);
  if (local_10 != 0) {
    *local_18 = 0;
  }
  return;
}



===== nv_kvprintf @ 0002c054 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int nv_kvprintf(byte *param_1,undefined *param_2,byte *param_3,undefined8 param_4,ulonglong *param_5
               )

{
  char *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  byte *pbVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong *puVar15;
  ulonglong *puVar16;
  uint uVar17;
  int iVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  ulonglong uVar22;
  code *pcVar23;
  uint uVar24;
  byte *pbVar25;
  int iVar26;
  undefined1 auStack_108 [32];
  byte local_e8;
  int local_e4;
  int local_e0;
  byte *local_d8;
  byte *local_d0;
  uint local_c8;
  int local_c4;
  code *local_c0;
  int local_b8;
  int local_b4;
  uint local_b0;
  byte *local_a8;
  int local_a0;
  byte local_98;
  byte local_97 [79];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  iVar26 = 0;
  local_d0 = (byte *)0x2dbe0;
  pbVar20 = (byte *)0x0;
  if (param_2 == (undefined *)0x0) {
    pbVar20 = param_3;
  }
  if (param_1 != (byte *)0x0) {
    local_d0 = param_1;
  }
  local_e4 = 0;
  local_d8 = param_3;
  local_c0 = (code *)param_2;
LAB_0002c0be:
  do {
    puVar15 = param_5;
    iVar12 = local_e4;
    local_e8 = 0x20;
    uVar17 = 0;
    pbVar21 = local_d0;
    while( true ) {
      bVar8 = *pbVar21;
      pbVar25 = pbVar21 + 1;
      local_d0 = pbVar25;
      if ((bVar8 == 0x25) && (iVar12 == 0)) break;
      if (bVar8 == 0) {
        return iVar26;
      }
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = bVar8;
        pbVar20 = pbVar20 + 1;
      }
      else {
        (*(code *)param_2)((int)(char)bVar8);
        param_2 = local_c0;
      }
      iVar26 = iVar26 + 1;
      pbVar21 = pbVar25;
    }
    local_b0 = 0;
    local_e0 = 0;
    iVar12 = 0;
    local_b4 = 0;
    bVar5 = false;
    bVar2 = false;
    bVar4 = false;
    uVar24 = 0;
    bVar3 = false;
    local_a0 = 0;
    local_c8 = 0;
    bVar6 = false;
    local_a8 = (byte *)((ulonglong)local_a8 & 0xffffffff00000000);
    local_c4 = 0;
    local_b8 = 0;
LAB_0002c141:
    bVar7 = local_e8;
    pbVar25 = local_d0 + 1;
    bVar8 = *local_d0;
    local_d0 = pbVar25;
    if (0x69 < bVar8) {
      if (bVar8 < 0x73) {
        if (bVar8 == 0x72) {
          iVar11 = 10;
          if ((int)local_a8 == 0) goto LAB_0002c71f;
          goto LAB_0002c6b3;
        }
        if (bVar8 == 0x6a) {
          bVar3 = true;
        }
        else {
          if (bVar8 != 0x6c) {
            if (bVar8 != 0x6e) {
              if (bVar8 == 0x6f) {
                iVar11 = 8;
                goto LAB_0002c71f;
              }
              if (bVar8 != 0x70) {
                if (bVar8 != 0x71) goto LAB_0002c658;
                goto LAB_0002c2e6;
              }
              uVar22 = *puVar15;
              iVar11 = 0x10;
              local_c8 = (uint)(uVar17 == 0);
              goto LAB_0002c736;
            }
            if ((bVar3) || (bVar5)) {
LAB_0002c5fd:
              *(longlong *)*puVar15 = (longlong)iVar26;
            }
            else if (bVar2) {
LAB_0002c631:
              *(int *)*puVar15 = iVar26;
            }
            else {
              if (bVar6) goto LAB_0002c5fd;
              if (iVar12 == 0) {
                if (local_c4 == 0) goto LAB_0002c631;
                *(char *)*puVar15 = (char)iVar26;
              }
              else {
                *(short *)*puVar15 = (short)iVar26;
              }
            }
            param_5 = puVar15 + 1;
            goto LAB_0002c0b9;
          }
          if (bVar2) {
            bVar2 = false;
LAB_0002c2e6:
            bVar5 = true;
          }
          else {
            bVar2 = true;
          }
        }
LAB_0002c1b4:
        goto LAB_0002c141;
      }
      if (bVar8 == 0x73) break;
      if (bVar8 != 0x74) {
        if (bVar8 != 0x75) {
          if (bVar8 == 0x78) goto LAB_0002c70d;
          if (bVar8 != 0x79) {
            if (bVar8 != 0x7a) {
LAB_0002c658:
              if (pbVar21 < pbVar25) {
                iVar26 = iVar26 + ((int)pbVar25 - (int)pbVar21);
                do {
                  bVar8 = *pbVar21;
                  pbVar21 = pbVar21 + 1;
                  if ((code *)param_2 == (code *)0x0) {
                    *pbVar20 = bVar8;
                    pbVar20 = pbVar20 + 1;
                  }
                  else {
                    (*(code *)param_2)((int)(char)bVar8);
                    param_2 = local_c0;
                  }
                } while (pbVar21 < pbVar25);
              }
              local_e4 = 1;
              local_d0 = pbVar25;
              goto LAB_0002c69e;
            }
            bVar6 = true;
            local_a0 = 1;
            goto LAB_0002c1b4;
          }
          iVar11 = 0x10;
          goto LAB_0002c6ae;
        }
        iVar11 = 10;
LAB_0002c71f:
        local_a8._0_4_ = 0;
        if (((bVar3) || (bVar5)) || (local_e0 != 0)) {
LAB_0002c72a:
          uVar22 = *puVar15;
        }
        else if (bVar2) {
          uVar22 = (ulonglong)(uint)*puVar15;
        }
        else {
          if (local_a0 != 0) goto LAB_0002c72a;
          if (iVar12 == 0) {
            if (local_c4 == 0) {
              uVar22 = (ulonglong)(uint)*puVar15;
              goto LAB_0002c7fb;
            }
            uVar22 = (ulonglong)(byte)*puVar15;
          }
          else {
            uVar22 = (ulonglong)(ushort)*puVar15;
          }
        }
        goto LAB_0002c736;
      }
      local_e0 = 1;
      goto LAB_0002c141;
    }
    if (bVar8 != 0x69) {
      if (bVar8 < 0x3a) {
        iVar12 = local_b8;
        if (bVar8 < 0x31) {
          if (bVar8 == 0x23) {
            local_c8 = 1;
          }
          else {
            if (bVar8 == 0x25) {
              if ((code *)param_2 == (code *)0x0) {
                *pbVar20 = 0x25;
                goto LAB_0002c37b;
              }
              iVar12 = 0x25;
              goto LAB_0002c366;
            }
            if (bVar8 == 0x2a) {
              puVar16 = puVar15 + 1;
              if (!bVar4) {
                uVar17 = (uint)*puVar15;
                puVar15 = puVar16;
                if ((int)uVar17 < 0) {
                  local_b0 = (uint)(local_b0 == 0);
                  uVar17 = -uVar17;
                  goto LAB_0002c1b4;
                }
                goto LAB_0002c141;
              }
              uVar24 = (uint)*puVar15;
              puVar15 = puVar16;
            }
            else if (bVar8 == 0x2b) {
              local_a8 = (byte *)CONCAT44(local_a8._4_4_,1);
            }
            else if (bVar8 == 0x2d) {
              local_b0 = 1;
            }
            else if (bVar8 == 0x2e) {
              bVar4 = true;
            }
            else {
              if (bVar8 != 0x30) goto LAB_0002c658;
              if (bVar4) goto LAB_0002c20c;
              local_e8 = 0x30;
            }
          }
        }
        else {
LAB_0002c20c:
          uVar14 = bVar8 - 0x30;
          iVar11 = (int)(char)*pbVar25;
          if (0x2f < iVar11) {
            do {
              if (0x39 < iVar11) break;
              pbVar25 = pbVar25 + 1;
              uVar14 = iVar11 + (uVar14 * 5 + -0x18) * 2;
              iVar11 = (int)(char)*pbVar25;
            } while (0x2f < iVar11);
            param_2 = local_c0;
            local_d0 = pbVar25;
          }
          if (bVar4) {
            uVar24 = uVar14;
          }
          else {
            uVar17 = uVar14;
          }
        }
        goto LAB_0002c1b4;
      }
      if (bVar8 == 0x44) {
        pbVar21 = (byte *)*puVar15;
        local_a8 = (byte *)puVar15[1];
        param_5 = puVar15 + 2;
        pbVar25 = local_a8;
        if (uVar17 == 0) {
          uVar17 = 0x10;
        }
        while( true ) {
          uVar17 = uVar17 - 1;
          if ((code *)param_2 == (code *)0x0) {
            *pbVar20 = "0123456789abcdefghijklmnopqrstuvwxyz"[*pbVar21 >> 4];
            pbVar20 = pbVar20 + 1;
          }
          else {
            (*(code *)param_2)((int)"0123456789abcdefghijklmnopqrstuvwxyz"[*pbVar21 >> 4]);
            param_2 = local_c0;
          }
          if ((code *)param_2 == (code *)0x0) {
            *pbVar20 = "0123456789abcdefghijklmnopqrstuvwxyz"[*pbVar21 & 0xf];
            pbVar20 = pbVar20 + 1;
          }
          else {
            (*(code *)param_2)((int)"0123456789abcdefghijklmnopqrstuvwxyz"[*pbVar21 & 0xf]);
            param_2 = local_c0;
          }
          pcVar23 = local_c0;
          iVar26 = iVar26 + 2;
          pbVar21 = pbVar21 + 1;
          if (uVar17 == 0) break;
          if (*pbVar25 != 0) {
            do {
              if (pcVar23 == (code *)0x0) {
                *pbVar20 = *pbVar25;
                pbVar20 = pbVar20 + 1;
              }
              else {
                (*pcVar23)((int)(char)*pbVar25);
              }
              pbVar25 = pbVar25 + 1;
              iVar26 = iVar26 + 1;
            } while (*pbVar25 != 0);
            param_2 = local_c0;
            pbVar25 = local_a8;
          }
        }
        goto LAB_0002c0b9;
      }
      if (bVar8 == 0x58) {
LAB_0002c70d:
        iVar11 = 0x10;
        goto LAB_0002c71f;
      }
      if (bVar8 != 0x62) {
        if (bVar8 != 99) {
          if (bVar8 != 100) {
            if (bVar8 != 0x68) goto LAB_0002c658;
            if (iVar12 == 0) {
              iVar12 = 1;
              local_b8 = 1;
            }
            else {
              iVar12 = 0;
              local_c4 = 1;
              local_b8 = 0;
            }
            goto LAB_0002c1b4;
          }
          goto LAB_0002c5b3;
        }
        uVar22 = *puVar15;
        puVar15 = puVar15 + 1;
        if ((code *)param_2 != (code *)0x0) {
          iVar12 = (int)(char)(byte)uVar22;
          goto LAB_0002c366;
        }
        *pbVar20 = (byte)uVar22;
        goto LAB_0002c37b;
      }
      pbVar19 = (byte *)(ulonglong)(uint)*puVar15;
      pcVar1 = (char *)puVar15[1];
      puVar15 = puVar15 + 2;
      uVar22 = (ulonglong)*pcVar1;
      local_98 = 0;
      pbVar21 = &local_98;
      pbVar25 = pbVar19;
      do {
        pbVar21 = pbVar21 + 1;
        pbVar9 = (byte *)((ulonglong)pbVar25 / uVar22);
        bVar8 = "0123456789abcdefghijklmnopqrstuvwxyz"[(ulonglong)pbVar25 % uVar22];
        *pbVar21 = bVar8;
        pbVar25 = pbVar9;
      } while (pbVar9 != (byte *)0x0);
      pbVar25 = (byte *)(pcVar1 + 1);
      local_a8 = pbVar19;
      while (bVar8 != 0) {
        bVar8 = *pbVar21;
        pbVar21 = pbVar21 + -1;
        if ((code *)param_2 == (code *)0x0) {
          *pbVar20 = bVar8;
          pbVar20 = pbVar20 + 1;
          param_2 = (code *)0x0;
        }
        else {
          (*(code *)param_2)((int)(char)bVar8);
          param_2 = local_c0;
        }
        iVar26 = iVar26 + 1;
        bVar8 = *pbVar21;
      }
      if (pbVar19 != (byte *)0x0) {
        bVar8 = *pbVar25;
        bVar2 = false;
        if (bVar8 != 0) {
          do {
            pbVar21 = local_d8;
            pbVar25 = pbVar25 + 1;
            if (((ulonglong)pbVar19 >> ((ulonglong)(byte)(bVar8 - 1) & 0x3f) & 1) == 0) {
              for (; ' ' < (char)*pbVar25; pbVar25 = pbVar25 + 1) {
              }
            }
            else {
              bVar8 = (-bVar2 & 0xf0U) + 0x3c;
              if ((code *)param_2 == (code *)0x0) {
                *pbVar20 = bVar8;
                pbVar20 = pbVar20 + 1;
              }
              else {
                (*(code *)param_2)((int)(char)bVar8,local_d8);
              }
              pcVar23 = local_c0;
              bVar8 = *pbVar25;
              iVar26 = iVar26 + 1;
              if (' ' < (char)bVar8) {
                do {
                  if (pcVar23 == (code *)0x0) {
                    *pbVar20 = bVar8;
                    pbVar20 = pbVar20 + 1;
                  }
                  else {
                    (*pcVar23)((int)(char)bVar8,pbVar21);
                  }
                  pbVar25 = pbVar25 + 1;
                  iVar26 = iVar26 + 1;
                  bVar8 = *pbVar25;
                } while (' ' < (char)bVar8);
                pbVar19 = local_a8;
              }
              bVar2 = true;
            }
            bVar8 = *pbVar25;
            param_2 = local_c0;
          } while (bVar8 != 0);
          param_5 = puVar15;
          if (bVar2) {
            if (local_c0 == (code *)0x0) {
              *pbVar20 = 0x3e;
LAB_0002c37b:
              pbVar20 = pbVar20 + 1;
              param_5 = puVar15;
            }
            else {
              iVar12 = 0x3e;
LAB_0002c366:
              (*(code *)param_2)(iVar12);
              param_5 = puVar15;
              param_2 = local_c0;
            }
            iVar26 = iVar26 + 1;
            goto LAB_0002c0b9;
          }
          goto LAB_0002c0be;
        }
      }
LAB_0002c69e:
      param_5 = puVar15;
      goto LAB_0002c0be;
    }
LAB_0002c5b3:
    iVar11 = 10;
LAB_0002c6ae:
    local_a8._0_4_ = 1;
LAB_0002c6b3:
    if (((bVar3) || (bVar5)) || (local_e0 != 0)) {
LAB_0002c6dd:
      uVar22 = *puVar15;
    }
    else if (bVar2) {
LAB_0002c6cd:
      uVar22 = (ulonglong)(int)(uint)*puVar15;
    }
    else {
      if (local_a0 != 0) goto LAB_0002c6dd;
      if (iVar12 == 0) {
        if (local_c4 == 0) goto LAB_0002c6cd;
        uVar22 = (ulonglong)(char)(byte)*puVar15;
      }
      else {
        uVar22 = (ulonglong)(short)(ushort)*puVar15;
      }
    }
LAB_0002c7fb:
    if (((int)local_a8 == 0) || (-1 < (longlong)uVar22)) {
LAB_0002c736:
      iVar12 = 0;
    }
    else {
      iVar12 = 1;
      uVar22 = -uVar22;
      local_b4 = 1;
    }
    param_5 = puVar15 + 1;
    local_a8 = &local_98;
    local_98 = 0;
    uVar13 = uVar22;
    do {
      local_a8 = local_a8 + 1;
      uVar10 = uVar13 / (ulonglong)(longlong)iVar11;
      *local_a8 = "0123456789abcdefghijklmnopqrstuvwxyz"[uVar13 % (ulonglong)(longlong)iVar11];
      uVar13 = uVar10;
    } while (uVar10 != 0);
    local_c4 = (int)local_a8 - (int)&local_98;
    if ((local_c8 != 0) && (uVar22 != 0)) {
      if (iVar11 == 8) {
        local_c4 = local_c4 + 1;
      }
      else if (iVar11 == 0x10) {
        local_c4 = local_c4 + 2;
      }
    }
    if (iVar12 != 0) {
      local_c4 = local_c4 + 1;
    }
    param_2 = local_c0;
    if (local_b0 == 0) {
      if (local_e8 != 0x30) {
        if (uVar17 != 0) {
          uVar17 = uVar17 - local_c4;
          if (0 < (int)uVar17) {
            iVar26 = iVar26 + uVar17;
            do {
              uVar17 = uVar17 - 1;
              if ((code *)param_2 == (code *)0x0) {
                *pbVar20 = bVar7;
                pbVar20 = pbVar20 + 1;
              }
              else {
                (*(code *)param_2)((int)(char)bVar7);
                param_2 = local_c0;
              }
            } while (uVar17 != 0);
            uVar17 = 0xffffffff;
            iVar12 = local_b4;
          }
        }
      }
    }
    pbVar21 = local_a8;
    iVar18 = local_c4;
    if (iVar12 != 0) {
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = 0x2d;
        pbVar20 = pbVar20 + 1;
      }
      else {
        (*(code *)param_2)(0x2d);
        param_2 = local_c0;
      }
      iVar26 = iVar26 + 1;
    }
    if ((local_c8 != 0) && (uVar22 != 0)) {
      if (iVar11 == 8) {
        if ((code *)param_2 == (code *)0x0) {
          *pbVar20 = 0x30;
          pbVar20 = pbVar20 + 1;
        }
        else {
          (*(code *)param_2)(0x30);
          param_2 = local_c0;
        }
        iVar26 = iVar26 + 1;
      }
      else if (iVar11 == 0x10) {
        if ((code *)param_2 == (code *)0x0) {
          *pbVar20 = 0x30;
          pbVar20 = pbVar20 + 1;
          pcVar23 = (code *)0x0;
        }
        else {
          (*(code *)param_2)(0x30);
          pcVar23 = local_c0;
        }
        if (pcVar23 == (code *)0x0) {
          *pbVar20 = 0x78;
          pbVar20 = pbVar20 + 1;
          param_2 = (code *)0x0;
        }
        else {
          (*pcVar23)(0x78);
          param_2 = local_c0;
        }
        iVar26 = iVar26 + 2;
      }
    }
    bVar8 = local_e8;
    if ((local_b0 == 0) && (uVar17 != 0)) {
      uVar17 = uVar17 - iVar18;
      if (0 < (int)uVar17) {
        iVar26 = iVar26 + uVar17;
        do {
          uVar17 = uVar17 - 1;
          if ((code *)param_2 == (code *)0x0) {
            *pbVar20 = bVar8;
            pbVar20 = pbVar20 + 1;
          }
          else {
            (*(code *)param_2)((int)(char)bVar8);
            param_2 = local_c0;
          }
        } while (uVar17 != 0);
        uVar17 = 0xffffffff;
        pbVar21 = local_a8;
      }
    }
    bVar8 = *pbVar21;
    bVar7 = local_e8;
    while (local_e8 = bVar7, bVar8 != 0) {
      bVar8 = *pbVar21;
      pbVar21 = pbVar21 + -1;
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = bVar8;
        pbVar20 = pbVar20 + 1;
        param_2 = (code *)0x0;
      }
      else {
        (*(code *)param_2)((int)(char)bVar8);
        param_2 = local_c0;
      }
      iVar26 = iVar26 + 1;
      bVar7 = local_e8;
      bVar8 = *pbVar21;
    }
    if ((local_b0 == 0) || (uVar17 == 0)) goto LAB_0002c0b9;
    iVar18 = uVar17 - iVar18;
    if (0 < iVar18) {
      local_c4 = iVar26 + iVar18;
      do {
        iVar18 = iVar18 + -1;
        if ((code *)param_2 == (code *)0x0) {
          *pbVar20 = bVar7;
          pbVar20 = pbVar20 + 1;
        }
        else {
          (*(code *)param_2)((int)(char)bVar7);
          param_2 = local_c0;
        }
      } while (iVar18 != 0);
      goto LAB_0002ca2d;
    }
  } while( true );
  local_a8 = &s__null_;
  if ((byte *)*puVar15 != (byte *)0x0) {
    local_a8 = (byte *)*puVar15;
  }
  if (bVar4) {
    uVar22 = 0;
    if (0 < (int)uVar24) {
      do {
        if (local_a8[(int)uVar22] == 0) break;
        uVar14 = (int)uVar22 + 1;
        uVar22 = (ulonglong)uVar14;
      } while ((int)uVar14 < (int)uVar24);
    }
  }
  else {
    uVar22 = 0xffffffffffffffff;
    do {
      uVar22 = uVar22 + 1;
    } while (local_a8[uVar22] != 0);
  }
  iVar11 = (int)uVar22;
  iVar12 = uVar17 - iVar11;
  if ((local_b0 == 0) && (0 < iVar12)) {
    iVar26 = iVar26 + iVar12;
    do {
      iVar12 = iVar12 + -1;
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = bVar7;
        pbVar20 = pbVar20 + 1;
      }
      else {
        (*(code *)param_2)((int)(char)bVar7);
        param_2 = local_c0;
      }
    } while (iVar12 != 0);
    iVar12 = -1;
  }
  if (iVar11 != 0) {
    iVar26 = iVar26 + iVar11;
    pbVar21 = local_a8;
    do {
      bVar8 = *pbVar21;
      uVar17 = (int)uVar22 - 1;
      uVar22 = (ulonglong)uVar17;
      pbVar21 = pbVar21 + 1;
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = bVar8;
        pbVar20 = pbVar20 + 1;
      }
      else {
        (*(code *)param_2)((int)(char)bVar8);
        param_2 = local_c0;
      }
    } while (uVar17 != 0);
  }
  bVar8 = local_e8;
  param_5 = puVar15 + 1;
  if ((local_b0 != 0) && (0 < iVar12)) {
    local_c4 = iVar26 + iVar12;
    do {
      iVar12 = iVar12 + -1;
      if ((code *)param_2 == (code *)0x0) {
        *pbVar20 = bVar8;
        pbVar20 = pbVar20 + 1;
      }
      else {
        (*(code *)param_2)((int)(char)bVar8);
        param_2 = local_c0;
      }
    } while (iVar12 != 0);
LAB_0002ca2d:
    param_5 = puVar15 + 1;
    iVar26 = local_c4;
LAB_0002c0b9:
  }
  goto LAB_0002c0be;
}



===== entry @ 0002cb88 =====

void entry(undefined8 param_1,undefined8 param_2)

{
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
  undefined4 local_80;
  undefined2 local_7c;
  code *local_60;
  code *local_58;
  
  __security_init_cookie();
  NvStorCBTInitialize();
  NvStorOsCBT = &CBT;
  memset(&local_d8,0,0xd0);
  local_d0 = NvStorInitialize;
  local_c8 = NvStorStartIo;
  local_c0 = NvStorInterrupt;
  local_b8 = NvStorFindAdapter;
  local_d8 = 0xd0;
  local_b0 = NvStorResetBus;
  local_98 = 0x5938;
  local_60 = NvStorAdapterControl;
  local_94 = 0x27d0;
  local_90 = 0x434;
  local_8c = 6;
  local_d4 = 5;
  local_58 = NvStorBuildIo;
  local_80 = 0x1010102;
  local_7c = 1;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== __report_gsfailure @ 0002cc7c =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 0002cc84 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  
  cVar1 = *(char *)(param_1 + 0x18);
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  uVar9 = 0;
  if (cVar1 == '\0') {
    uVar7 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar10 = (ulonglong)uVar3;
    uVar5 = uVar7 + param_3;
    if (param_2 == '\x01') {
      if (uVar5 <= uVar2) {
        if (((0x2f < uVar2) && (*puVar4 = uVar5, uVar9 = uVar5, (char)puVar4[0xb] < '\0')) &&
           (puVar8 = puVar4 + 0xf, uVar6 = uVar10, uVar3 != 0)) {
          do {
            uVar5 = (int)uVar6 - 1;
            uVar6 = (ulonglong)uVar5;
            if (uVar6 * 8 + 0x48 <= (ulonglong)uVar2) {
              puVar4[uVar6 * 2 + 0x10] = puVar8[uVar6];
            }
          } while (uVar5 != 0);
          if (uVar3 != 0) {
            uVar6 = 0x48;
            do {
              if (uVar6 <= uVar2) {
                *puVar8 = uVar7;
                uVar7 = uVar7 + 7 + puVar8[1] & 0xfffffff8;
              }
              uVar6 = uVar6 + 8;
              puVar8 = puVar8 + 2;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
        }
        goto LAB_0002cd46;
      }
      param_2 = '\x12';
    }
LAB_0002cd23:
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_0002cd46;
    puVar4[0xc] = uVar5;
  }
  else {
    if (cVar1 == '\x01') {
      uVar5 = puVar4[0xe] + param_3;
      if (param_2 == '\x01') {
        if (0x2f < uVar2) {
          *puVar4 = uVar5;
          uVar9 = uVar5;
        }
        goto LAB_0002cd46;
      }
      goto LAB_0002cd23;
    }
    if (cVar1 != '\t') goto LAB_0002cd46;
    uVar7 = puVar4[0xf] + param_3;
    if (param_2 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar7;
        puVar4[0x10] = param_3;
        uVar9 = uVar7;
      }
      goto LAB_0002cd46;
    }
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_0002cd46;
    puVar4[0xc] = uVar7;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  param_2 = '\x01';
  uVar9 = 0x38;
LAB_0002cd46:
  *(uint *)(param_1 + 0x1c) = uVar9;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 0002cdd4 =====

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,longlong *param_5,
               uint param_6,uint *param_7,uint *param_8,short *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  short *psVar4;
  char cVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  longlong *plVar9;
  ulonglong *puVar10;
  undefined2 *puVar11;
  int iVar12;
  longlong lVar13;
  uint *puVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined4 uVar20;
  
  puVar14 = (uint *)0x0;
  psVar4 = param_9;
  psVar4[0] = 0;
  psVar4[1] = 0;
  uVar6 = 0;
  uVar19 = 0;
  uVar16 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar9 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar9) && (param_5[1] == ((longlong *)*plVar9)[1])) {
          uVar16 = *(uint *)(*(longlong **)(param_1 + 2) + uVar19 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar6 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar6 < uVar16))))
          goto LAB_0002cea4;
          break;
        }
        uVar16 = (int)uVar19 + 1;
        uVar19 = (ulonglong)uVar16;
        plVar9 = plVar9 + 2;
      } while (uVar16 < *param_1);
    }
    *param_8 = 0;
    cVar5 = '\x04';
    goto LAB_0002d1d6;
  }
LAB_0002cea4:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (0x47 < param_6) {
          param_7[0xb] = param_7[0xb] & 0xffffffef;
          param_7[0xd] = uVar16;
          uVar6 = uVar16 * 8 + 0x40;
          param_7[0xc] = uVar6;
          if (param_6 < uVar6) {
            lVar13 = 0;
            iVar12 = 0;
          }
          else {
            puVar14 = param_7 + 0xf;
            lVar13 = (ulonglong)uVar6 + (longlong)param_7;
            iVar12 = param_6 - uVar6;
          }
          uVar6 = 0;
          goto LAB_0002cff1;
        }
      }
      else {
        if (param_2 == 1) {
          if (param_6 < 0x40) {
            if (param_6 < 4) {
              *(undefined1 *)param_7 = 8;
              return '\x12';
            }
            *param_7 = 0x40;
            return '\x12';
          }
          lVar13 = (longlong)param_7 + (ulonglong)param_7[0xe];
          iVar12 = param_6 - param_7[0xe];
          puVar14 = param_7 + 0xf;
          uVar16 = 1;
LAB_0002cff1:
          cVar5 = (**(code **)(param_1 + 6))
                            (param_3,param_4,uVar19,uVar6,uVar16,puVar14,iVar12,lVar13);
          return cVar5;
        }
        if (param_2 == 2) {
          if (*(code **)(param_1 + 8) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 8))
                              (param_3,param_4,uVar19,uVar6,param_7[0xf],
                               (ulonglong)param_7[0xe] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 3) {
          if (*(code **)(param_1 + 10) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 10))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               (ulonglong)param_7[0xf] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 4) {
          pcVar7 = *(code **)(param_1 + 0xe);
          if (pcVar7 != (code *)0x0) {
            uVar18 = 0;
            goto LAB_0002d1f9;
          }
          goto LAB_0002d20a;
        }
      }
LAB_0002cf19:
      cVar5 = '\x04';
      goto LAB_0002d20d;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 0;
      goto LAB_0002d1fe;
    }
  }
  else if (param_2 == 6) {
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar18 = 1;
LAB_0002d1f9:
      uVar20 = 1;
LAB_0002d1fe:
      cVar5 = (*pcVar7)(param_3,param_4,uVar19,uVar18,uVar20);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (*(code **)(param_1 + 0xc) != (code *)0x0)) && (0x47 < param_6)) {
          uVar16 = param_7[0xf];
          if (uVar16 <= param_6) {
            cVar5 = (**(code **)(param_1 + 0xc))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               param_6 - uVar16,(longlong)param_7 + (ulonglong)uVar16);
            return cVar5;
          }
        }
        goto LAB_0002cf19;
      }
      cVar5 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar5 == '\x01') {
        uVar6 = *param_1;
        uVar19 = (ulonglong)uVar6;
        lVar13 = *(longlong *)(param_1 + 2);
        uVar17 = uVar6 * 0x20 + 0x18;
        uVar16 = uVar6 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          sVar2 = *param_9;
          while (sVar2 != 0) {
            uVar15 = uVar15 + 1;
            sVar2 = param_9[uVar15];
          }
          uVar15 = uVar15 * 2;
        }
        uVar8 = uVar15 + uVar16;
        if ((uVar8 < uVar16) || (uVar1 = uVar8 + 2, uVar1 < uVar8)) {
          cVar5 = '\x04';
          goto LAB_0002d1c7;
        }
        if (param_6 < uVar1) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
          }
          else {
            *param_7 = uVar1;
            param_6 = 4;
          }
        }
        else {
          *param_7 = uVar1;
          param_7[1] = 0;
          param_7[2] = 0;
          param_7[3] = uVar16;
          param_7[4] = uVar6;
          if (uVar6 != 0) {
            puVar14 = (uint *)(lVar13 + 0xc);
            puVar10 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(puVar14 + -3))[1];
              puVar10[-3] = **(ulonglong **)(puVar14 + -3);
              puVar10[-2] = uVar3;
              if (puVar14[-1] == 0xffffffff) {
                *(uint *)(puVar10 + -1) = *puVar14;
                *puVar10 = 0;
                *(undefined4 *)((longlong)puVar10 + -4) = 0;
              }
              else {
                *(uint *)(puVar10 + -1) = *puVar14 | 8;
                *puVar10 = (ulonglong)uVar17;
                *(uint *)((longlong)puVar10 + -4) = puVar14[-1];
              }
              puVar10 = puVar10 + 4;
              puVar14 = puVar14 + 4;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          puVar11 = (undefined2 *)((ulonglong)uVar17 + (longlong)param_7);
          *puVar11 = 0x1a;
          memcpy(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar16 + (longlong)param_7) = uVar15;
          memcpy((ushort *)((ulonglong)uVar16 + (longlong)param_7) + 1,param_9,(ulonglong)uVar15);
          param_6 = uVar1;
        }
      }
      else {
LAB_0002d1c7:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_0002d1d6:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 1;
      goto LAB_0002d1fe;
    }
  }
LAB_0002d20a:
  cVar5 = '\x01';
LAB_0002d20d:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== ScsiPortWmiDispatchFunction @ 0002d230 =====

undefined8
ScsiPortWmiDispatchFunction
          (uint *param_1,byte param_2,undefined8 param_3,longlong param_4,longlong *param_5,
          uint param_6,uint *param_7)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined7 extraout_var;
  uint local_res10 [6];
  int local_18 [4];
  
  local_res10[0] = 0;
  *(undefined4 *)(param_4 + 0x1c) = 0;
  if (param_2 < 10) {
    *(byte *)(param_4 + 0x18) = param_2;
    *(uint **)(param_4 + 0x10) = param_7;
    *(uint *)(param_4 + 8) = param_6;
    cVar1 = ScsiWmipProcessRequest
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_res10,
                       (short *)local_18);
    uVar2 = extraout_var;
    if (local_18[0] == 1) {
      *(char *)(param_4 + 0x19) = cVar1;
      if (cVar1 != '\x01') {
        local_res10[0] = 0;
      }
      *(uint *)(param_4 + 0x1c) = local_res10[0];
    }
  }
  else {
    uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
    cVar1 = '\x04';
    *(undefined1 *)(param_4 + 0x19) = 4;
  }
  return CONCAT71(uVar2,cVar1 == '\0');
}



===== __security_check_cookie @ 0002d2e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __GSHandlerCheck @ 0002d300 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 0002d320 =====

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



===== memcpy @ 0002d3c0 =====

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
        if (uVar12 == 0) goto LAB_0002d577;
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
LAB_0002d577:
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
      if (uVar12 == 0) goto LAB_0002d3d2;
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
LAB_0002d3d2:
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



===== memset @ 0002d700 =====

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
      if (uVar5 == 0) goto LAB_0002d7c0;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_0002d7bd_caseD_2;
      case 3:
        goto switchD_0002d7bd_caseD_3;
      case 4:
        goto switchD_0002d7bd_caseD_4;
      case 5:
        goto switchD_0002d7bd_caseD_5;
      case 6:
        goto switchD_0002d7bd_caseD_6;
      case 7:
        goto switchD_0002d7bd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_0002d7c0:
        *puVar3 = uVar4;
switchD_0002d7bd_caseD_7:
        puVar3[1] = uVar4;
switchD_0002d7bd_caseD_6:
        puVar3[2] = uVar4;
switchD_0002d7bd_caseD_5:
        puVar3[3] = uVar4;
switchD_0002d7bd_caseD_4:
        puVar3[4] = uVar4;
switchD_0002d7bd_caseD_3:
        puVar3[5] = uVar4;
switchD_0002d7bd_caseD_2:
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



===== __security_init_cookie @ 00037000 =====

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


