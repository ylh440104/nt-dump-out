
===== _tlgKeywordOn @ 140001010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_14000b010 & 0x200000000000) == 0) ||
     (in_RAX = DAT_14000b018 & 0x200000000000, in_RAX != DAT_14000b018)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== HumSelectConfiguration @ 140001050 =====

int HumSelectConfiguration(ulonglong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  ushort *_Src;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar4;
  longlong local_38 [2];
  undefined8 local_28;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  _Src = (ushort *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x46,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  local_38[0] = USBD_ParseConfigurationDescriptorEx
                          (param_2,param_2,0xffffffff,0xffffffff,3,CONCAT44(uVar4,0xffffffff),
                           0xffffffff);
  local_28 = 0;
  if (local_38[0] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x4a,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
    }
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar3 = USBD_CreateConfigurationRequestEx(param_2,local_38);
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x49,
                         &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
      }
      iVar2 = -0x3fffffe9;
    }
    else {
      iVar2 = HumCallUSB(param_1,lVar3);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x48,
                            &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar2);
        }
        *(undefined8 *)(lVar1 + 0x18) = 0;
      }
      else {
        _Src = (ushort *)(lVar3 + 0x28);
        *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar3 + 0x20);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x47,
                            &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)_Src);
        }
      }
      if (-1 < iVar2) {
        _Dst = (void *)ExAllocatePool2(0x40,*_Src,0x55646948);
        *(void **)(lVar1 + 0x10) = _Dst;
        if (_Dst == (void *)0x0) {
          iVar2 = -0x3fffffe9;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5a,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x17);
          }
        }
        else {
          memmove(_Dst,_Src,(ulonglong)*_Src);
        }
      }
      ExFreePool(lVar3);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5b,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return iVar2;
}



===== HumGetConfigDescriptor @ 140001330 =====

int HumGetConfigDescriptor(ulonglong param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  undefined2 uVar6;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffb0;
  byte *local_38 [2];
  
  uVar3 = 0;
  local_res20[0] = 9;
  local_38[0] = (byte *)0x0;
  iVar2 = HumGetDescriptorRequest
                    (param_1,0xb,2,(longlong *)local_38,local_res20,in_stack_ffffffffffffffb0,0,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x29,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar2);
    }
LAB_1400017ad:
    pbVar5 = local_38[0];
LAB_140001434:
    *param_2 = pbVar5;
    *param_3 = uVar3;
  }
  else {
    if (local_res20[0] < 9) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x1b;
        uVar4 = local_res20[0];
LAB_140001703:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                          &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)uVar4);
      }
    }
    else {
      uVar1 = *(ushort *)(local_38[0] + 2);
      ExFreePool();
      if (uVar1 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1c,
                           &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
        }
      }
      else {
        local_38[0] = (byte *)0x0;
        uVar4 = (uint)uVar1;
        local_res20[0] = uVar4;
        iVar2 = HumGetDescriptorRequest
                          (param_1,0xb,2,(longlong *)local_38,local_res20,in_stack_ffffffffffffffb0,
                           0,0);
        pbVar5 = local_38[0];
        uVar3 = local_res20[0];
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x28,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar2);
          }
          uVar3 = local_res20[0];
          goto LAB_1400017ad;
        }
        if (8 < local_res20[0]) {
          if (uVar4 < *(ushort *)(local_38[0] + 2)) {
            *(ushort *)(local_38[0] + 2) = uVar1;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1e,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)local_38[0]);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1f,
                                &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,*pbVar5);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x20,
                                  &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,pbVar5[1]);
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x21,
                                    &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                                    (char)*(undefined2 *)(pbVar5 + 2));
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x22,
                                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,pbVar5[4]);
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x23,
                                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,pbVar5[5]);
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x24,
                                          &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,pbVar5[6]
                                         );
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x25,
                                            &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                                            pbVar5[7]);
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x26,
                                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                                              pbVar5[8]);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ((*pbVar5 < 9) &&
             (*pbVar5 = 9, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x27,
                             &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
          }
          goto LAB_140001434;
        }
        if (local_38[0] != (byte *)0x0) {
          ExFreePool();
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1d;
          goto LAB_140001703;
        }
      }
    }
    iVar2 = -0x3fffff64;
  }
  return iVar2;
}



===== HumInitDevice @ 1400017c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HumInitDevice(ulonglong param_1,undefined8 param_2,uint *param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStackY_b8 [32];
  uint local_88 [2];
  undefined8 local_80;
  undefined8 local_78 [4];
  uint *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = 0;
  local_88[0] = 0;
  puVar1 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar7 = param_1;
  uVar3 = HumGetDeviceDescriptor(param_1,(longlong)puVar1);
  if ((int)uVar3 < 0) {
    if (DAT_14000b000 < 6) {
      return uVar3;
    }
    uVar6 = _tlgKeywordOn();
    if ((char)uVar6 == '\0') {
      return uVar3;
    }
    local_88[0] = *puVar1;
    local_38 = "PNP_DeviceDesc";
LAB_1400018d8:
    local_48 = local_88;
    local_58 = (uint *)&local_80;
    local_80 = CONCAT44(local_80._4_4_,uVar3);
    local_50 = 4;
    local_40 = 4;
    local_30 = 0xf;
    _tlgWriteTransfer_EtwWriteTransfer(uVar7,&DAT_140009647,param_3,param_4,5,local_78);
    return uVar3;
  }
  param_3 = local_88;
  uVar7 = param_1;
  uVar3 = HumGetConfigDescriptor(param_1,&local_80,param_3);
  uVar2 = local_80;
  if ((int)uVar3 < 0) {
    if (DAT_14000b000 < 6) {
      return uVar3;
    }
    uVar6 = _tlgKeywordOn();
    if ((char)uVar6 == '\0') {
      return uVar3;
    }
    local_88[0] = *puVar1;
    local_38 = "PNP_ConfigDesc";
    goto LAB_1400018d8;
  }
  uVar6 = (ulonglong)local_88[0];
  uVar7 = param_1;
  uVar4 = HumGetHidInfo(param_1,local_80,local_88[0]);
  uVar3 = (uint)uVar4;
  if ((int)uVar3 < 0) {
    if ((DAT_14000b000 < 6) || (uVar5 = _tlgKeywordOn(), (char)uVar5 == '\0')) goto LAB_14000186c;
    local_58 = (uint *)&local_80;
    local_80 = CONCAT44(local_80._4_4_,uVar3);
    local_88[0] = *puVar1;
    local_48 = local_88;
    local_38 = "PNP_HIDInfo";
    local_30 = 0xc;
  }
  else {
    uVar7 = param_1;
    uVar3 = HumSelectConfiguration(param_1,uVar2);
    if (-1 < (int)uVar3) {
      HumSetIdle(param_1);
      goto LAB_14000186c;
    }
    if ((DAT_14000b000 < 6) || (uVar5 = _tlgKeywordOn(), (char)uVar5 == '\0')) goto LAB_14000186c;
    local_58 = local_88;
    local_80 = CONCAT44(local_80._4_4_,*puVar1);
    local_48 = (uint *)&local_80;
    local_38 = "PNP_Configuration";
    local_30 = 0x12;
    local_88[0] = uVar3;
  }
  local_50 = 4;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(uVar7,&DAT_140009647,uVar6,param_4,5,local_78);
LAB_14000186c:
  ExFreePool(uVar2);
  return uVar3;
}



===== HumGetDeviceDescriptor @ 140001a20 =====

int HumGetDeviceDescriptor(ulonglong param_1,longlong param_2)

{
  int iVar1;
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res10[0] = 0x12;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xf,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  iVar1 = HumGetDescriptorRequest
                    (param_1,0xb,1,(longlong *)(param_2 + 8),local_res10,in_stack_ffffffffffffffd0,0
                     ,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x19,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar1);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x10,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x11,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      **(undefined1 **)(param_2 + 8));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x12,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      *(undefined1 *)(*(longlong *)(param_2 + 8) + 1));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x13,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      *(undefined1 *)(*(longlong *)(param_2 + 8) + 4));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x14,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      *(undefined1 *)(*(longlong *)(param_2 + 8) + 5));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x15,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      *(undefined1 *)(*(longlong *)(param_2 + 8) + 6));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x16,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      (char)*(undefined2 *)(*(longlong *)(param_2 + 8) + 8));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x17,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      (char)*(undefined2 *)(*(longlong *)(param_2 + 8) + 10));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x18,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                      (char)*(undefined2 *)(*(longlong *)(param_2 + 8) + 0xc));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1a,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return iVar1;
}



===== HumPowerCompletion @ 140001d50 =====

undefined8 HumPowerCompletion(ulonglong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  longlong lVar5;
  
  iVar2 = *(int *)(param_2 + 0x30);
  piVar3 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if ((((-1 < iVar2) && (lVar5 = *(longlong *)(param_2 + 0xb8), *(char *)(lVar5 + 1) == '\x02')) &&
      (*(int *)(lVar5 + 0x10) == 1)) && ((*(int *)(lVar5 + 0x18) == 1 && (*piVar3 == 2)))) {
    bVar4 = KeGetCurrentIrql();
    if (bVar4 < 2) {
      HumSetIdle(param_1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x11,
                         &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids);
      }
      lVar5 = IoAllocateWorkItem(param_1);
      if (lVar5 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x12,
                           &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids);
        }
      }
      else {
        IoQueueWorkItem(lVar5,HumSetIdleWorker,0,lVar5);
      }
    }
  }
  IoReleaseRemoveLockEx(piVar3 + 0x1a,param_2,0x20);
  return 0;
}



===== HumSetIdle @ 140001eb0 =====

int HumSetIdle(ulonglong param_1)

{
  uint uVar1;
  longlong lVar2;
  ushort uVar3;
  int iVar4;
  undefined2 *puVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5c,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (lVar2 == 0) {
    iVar4 = -0x3ffffddb;
  }
  else {
    puVar5 = (undefined2 *)ExAllocatePool2(0x40,0x88,0x55646948);
    if (puVar5 == (undefined2 *)0x0) {
      iVar4 = -0x3fffffe9;
    }
    else {
      uVar1 = *(uint *)(lVar2 + 0x40);
      *puVar5 = 0x88;
      if ((uVar1 & 1) == 0) {
        puVar5[1] = 0x1b;
        uVar3 = (ushort)*(byte *)(*(longlong *)(lVar2 + 0x10) + 2);
      }
      else {
        puVar5[1] = 0x1c;
        uVar3 = 0;
      }
      puVar5[0x42] = uVar3;
      *(undefined4 *)(puVar5 + 0x40) = 0xa22;
      *(undefined8 *)(puVar5 + 0x10) = 0;
      *(undefined8 *)(puVar5 + 0x14) = 0;
      iVar4 = HumCallUSB(param_1,puVar5);
      ExFreePool(puVar5);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5d,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return iVar4;
}



===== HumGetDescriptorRequest @ 140002020 =====

int HumGetDescriptorRequest
              (ulonglong param_1,undefined2 param_2,undefined1 param_3,longlong *param_4,
              uint *param_5,undefined8 param_6,undefined1 param_7,undefined2 param_8)

{
  bool bVar1;
  int iVar2;
  undefined2 *puVar3;
  void *_Dst;
  uint uVar4;
  
  bVar1 = false;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5e,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5f,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)param_1);
    }
  }
  puVar3 = (undefined2 *)ExAllocatePool2(0x40,0x88,0x55646948);
  if (puVar3 == (undefined2 *)0x0) {
    iVar2 = -0x3fffffe9;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffe9;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,100,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x17);
    goto LAB_140002153;
  }
  _Dst = (void *)*param_4;
  if (_Dst == (void *)0x0) {
    _Dst = (void *)ExAllocatePool2(0x40,*param_5,0x55646948);
    *param_4 = (longlong)_Dst;
    bVar1 = true;
    if (_Dst != (void *)0x0) goto LAB_1400020bb;
    iVar2 = -0x3fffffe9;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,99,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x17);
    }
  }
  else {
LAB_1400020bb:
    if (!bVar1) {
      memset(_Dst,0,(ulonglong)*param_5);
    }
    *(uint *)(puVar3 + 0x12) = *param_5;
    puVar3[1] = param_2;
    uVar4 = 0;
    *(undefined8 *)(puVar3 + 0x18) = 0;
    *puVar3 = 0x88;
    *(longlong *)(puVar3 + 0x14) = *param_4;
    *(undefined1 *)(puVar3 + 0x41) = param_7;
    puVar3[0x42] = param_8;
    *(undefined1 *)((longlong)puVar3 + 0x83) = param_3;
    *(undefined8 *)(puVar3 + 0x1c) = 0;
    iVar2 = HumCallUSB(param_1,puVar3);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x62,
                          &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar2);
      }
LAB_140002132:
      if (bVar1) {
        ExFreePool(*param_4);
        *param_4 = 0;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if (*(int *)(puVar3 + 2) < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        iVar2 = -0x3fffffff;
        goto LAB_140002132;
      }
      iVar2 = 0;
      uVar4 = *(uint *)(puVar3 + 0x12);
    }
    *param_5 = uVar4;
  }
  ExFreePool(puVar3);
LAB_140002153:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x65,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return iVar2;
}



===== HumCallUSB @ 140002370 =====

int HumCallUSB(ulonglong param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  ulonglong in_stack_ffffffffffffff90;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff90 = param_1;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x66,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)param_1,
                       (char)*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10));
  }
  KeInitializeEvent(&local_38,0,0);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x220003,*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),0,0,0,
                     in_stack_ffffffffffffff90 & 0xffffffff00000000,1,&local_38,&local_48);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x67,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
    }
    return -0x3fffff66;
  }
  iVar1 = IoSetCompletionRoutineEx(param_1,lVar3,HumCallUsbComplete,&local_38,1,1,1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x68,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar1);
    }
    IofCompleteRequest(lVar3,0);
    return iVar1;
  }
  *(undefined8 *)(*(longlong *)(lVar3 + 0xb8) + -0x40) = param_2;
  iVar1 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),lVar3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x69,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar1);
  }
  if (iVar1 == 0x103) {
    iVar2 = KeWaitForSingleObject(&local_38,5,0,0,&DAT_14000b090);
    if (iVar2 == 0x102) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x6a,
                         &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
      }
      IoCancelIrp(lVar3);
      iVar2 = KeWaitForSingleObject(&local_38,5,0,0,0);
      local_48 = CONCAT44(local_48._4_4_,0xc00000b5);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_1400024ed;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6b,
                      &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar2);
    IofCompleteRequest(lVar3,0);
  }
  else {
LAB_1400024ed:
    IofCompleteRequest(lVar3,0);
    if (iVar1 != 0x103) goto LAB_14000250a;
  }
  iVar1 = (int)local_48;
LAB_14000250a:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6c,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)iVar1);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6d,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
    }
  }
  return iVar1;
}



===== WPP_RECORDER_SF_qDd @ 140002760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x60,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x60,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140002880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== HumGetHidInfo @ 140002980 =====

undefined8 HumGetHidInfo(longlong param_1,undefined8 param_2,int param_3)

{
  longlong lVar1;
  byte *pbVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined8 *local_res8;
  
  uVar3 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  *(undefined8 *)(lVar1 + 0x50) = 0;
  *(undefined1 *)(lVar1 + 0x58) = 0;
  pbVar2 = (byte *)USBD_ParseConfigurationDescriptorEx
                             (param_2,param_2,0xffffffff,0xffffffff,3,0xffffffff,0xffffffff);
  if (pbVar2 == (byte *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0xd;
      goto LAB_140002b07;
    }
  }
  else {
    local_res8 = (undefined8 *)0x0;
    if (pbVar2[5] == 3) {
      HumParseHidInterface
                (lVar1,pbVar2,((int)param_2 - (int)pbVar2) + param_3,(longlong *)&local_res8);
      if (local_res8 != (undefined8 *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xb,
                           &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
        }
        *(undefined8 *)(lVar1 + 0x50) = *local_res8;
        *(undefined1 *)(lVar1 + 0x58) = *(undefined1 *)(local_res8 + 1);
        goto LAB_140002a7d;
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0xc;
LAB_140002b07:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar4,
                       &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
    }
  }
  uVar3 = 0xc0000001;
LAB_140002a7d:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xe,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return uVar3;
}



===== HumParseHidInterface @ 140002b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 HumParseHidInterface(longlong param_1,byte *param_2,uint param_3,longlong *param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined8 uVar10;
  undefined1 auStackY_e8 [32];
  undefined1 uVar11;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  byte *local_90;
  undefined *local_88;
  uint local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar10 = 0;
  uVar7 = 0;
  local_90 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2a,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  *param_4 = 0;
  if (param_3 < 9) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x2b,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)param_3);
    }
    if (5 < DAT_14000b000) {
      if (((_DAT_14000b010 & 0x200000000000) == 0) ||
         ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_68 = &local_a8;
        local_a8 = 0xc0000001;
        local_58 = "USB_DescriptorOverflow";
        local_50 = 0x17;
        uVar1 = *(ushort *)PTR_DAT_14000b008;
        local_a4 = 0xea;
LAB_140002ced:
        local_80 = (uint)uVar1;
        local_60 = 4;
        local_6c = 1;
        local_70 = 0x2a;
        local_78 = &DAT_14000961c;
        local_7c = 2;
        local_98 = 0x200000000000;
        local_9c = 5;
        local_a0 = 0xb000000;
        local_88 = PTR_DAT_14000b008;
        EtwWriteTransfer(DAT_14000b020,&local_a0,0,0);
      }
    }
LAB_140002d22:
    if (*param_4 != 0) {
      if (uVar7 != local_90[4]) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x44,
                           &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
        }
        uVar10 = 0xc0000001;
      }
      goto LAB_1400035e9;
    }
  }
  else {
    if (*param_2 < 9) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002da4;
      uVar8 = (uint)*param_2;
      uVar9 = 0x2c;
LAB_140002d8c:
      uVar11 = (undefined1)uVar8;
      bVar5 = 2;
LAB_140002d8e:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,5,uVar9,
                        &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,uVar11);
LAB_140002da4:
      if (5 < DAT_14000b000) {
        if (((_DAT_14000b010 & 0x200000000000) == 0) ||
           ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_50 = 0x15;
          local_58 = "USB_DescriptorLength";
LAB_140002dfc:
          local_68 = &local_a4;
          local_a4 = 0xc0000001;
          uVar1 = *(ushort *)PTR_DAT_14000b008;
          local_a8 = 0xea;
          goto LAB_140002ced;
        }
      }
      goto LAB_140002d22;
    }
    uVar4 = Feature_HOFFEB__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 != 0) && (param_3 < *param_2)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if (5 < DAT_14000b000) {
        if (((_DAT_14000b010 & 0x200000000000) == 0) ||
           ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_50 = 0x20;
          local_58 = "USB_InterfaceDescriptorOverflow";
          goto LAB_140002dfc;
        }
      }
      goto LAB_140002d22;
    }
    uVar8 = param_3 - *param_2;
    if (uVar8 < 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140002da4;
      uVar9 = 0x2e;
LAB_140002f24:
      uVar11 = (undefined1)uVar8;
      bVar5 = 3;
      goto LAB_140002d8e;
    }
    uVar3 = *(uint *)(param_1 + 0x40) & 0xfffffffe;
    *(uint *)(param_1 + 0x40) = uVar3;
    pbVar6 = param_2 + *param_2;
    bVar5 = *pbVar6;
    if (bVar5 < 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x2f;
LAB_140002f6f:
        uVar8 = (uint)bVar5;
        goto LAB_140002d8c;
      }
      goto LAB_140002da4;
    }
    if (pbVar6[1] == 0x21) {
      if (bVar5 != 9) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x31,
                            &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,bVar5);
        }
        if (5 < DAT_14000b000) {
          if (((_DAT_14000b010 & 0x200000000000) == 0) ||
             ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (bVar2) {
            local_98 = 0x200000000000;
            local_68 = &local_a4;
            local_a4 = 0xc0000001;
            local_58 = "USB_DescriptorLength";
            local_88 = PTR_DAT_14000b008;
            local_9c = 5;
            local_60 = 4;
            local_50 = 0x15;
            local_a0 = 0xb000000;
            local_80 = (uint)*(ushort *)PTR_DAT_14000b008;
            local_78 = &DAT_14000961c;
            local_7c = 2;
            local_70 = 0x2a;
            local_6c = 1;
            local_a8 = 0xea;
            EtwWriteTransfer(DAT_14000b020,&local_a0,0,0);
          }
        }
        goto LAB_140002d22;
      }
      *param_4 = (longlong)pbVar6;
      uVar8 = uVar8 - *pbVar6;
      if ((int)uVar8 < 0) {
        *param_4 = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x30;
          goto LAB_140002f24;
        }
        goto LAB_140002da4;
      }
      pbVar6 = pbVar6 + *pbVar6;
    }
    else {
      *(uint *)(param_1 + 0x40) = uVar3 | 1;
    }
    if (param_2[4] != 0) {
      do {
        if (uVar8 < 2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140002da4;
          uVar9 = 0x32;
          goto LAB_140002d8c;
        }
        if (pbVar6[1] == 5) {
          if (*pbVar6 != 7) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x33,
                                &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,*pbVar6);
            }
LAB_14000309d:
            if (DAT_14000b000 < 6) goto LAB_140002d22;
            if (((_DAT_14000b010 & 0x200000000000) == 0) ||
               ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
            if (!bVar2) goto LAB_140002d22;
            local_50 = 0x17;
            local_58 = "USB_DescriptorEndpoint";
            goto LAB_140002dfc;
          }
          bVar5 = *pbVar6;
          uVar7 = uVar7 + 1;
        }
        else {
          if (pbVar6[1] == 4) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x34,
                               &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
            }
            goto LAB_14000309d;
          }
          bVar5 = *pbVar6;
          if (bVar5 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140002da4;
            uVar9 = 0x35;
            bVar5 = 0;
            goto LAB_140002f6f;
          }
        }
        uVar8 = uVar8 - bVar5;
        if ((int)uVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140002da4;
          uVar9 = 0x36;
          goto LAB_140002d8c;
        }
        pbVar6 = pbVar6 + bVar5;
      } while (uVar7 != param_2[4]);
    }
    if ((*(uint *)(param_1 + 0x40) & 1) != 0) {
      if (uVar8 < 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x37;
          goto LAB_140002d8c;
        }
        goto LAB_140002da4;
      }
      if (pbVar6[1] == 0x21) {
LAB_140003236:
        *param_4 = (longlong)pbVar6;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x38,
                           &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
        }
        if (*pbVar6 == 9) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x39,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,9);
          }
          goto LAB_140003236;
        }
      }
      if ((int)uVar8 < (int)(uint)*pbVar6) {
        if (uVar8 < 9) {
          *param_4 = 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x3a;
          goto LAB_140002d8c;
        }
        goto LAB_140002da4;
      }
    }
    if (*param_4 != 0) {
      if ((((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
            (WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3b,
                               &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,(char)*param_4),
            (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
           (WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3c,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                              *(undefined1 *)*param_4),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
          ((WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3d,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                              *(undefined1 *)(*param_4 + 1)),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED &&
           (WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3e,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                              (char)*(undefined2 *)(*param_4 + 2)),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)))) &&
         ((WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3f,
                             &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                             *(undefined1 *)(*param_4 + 4)),
          (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED &&
          ((WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x40,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                              *(undefined1 *)(*param_4 + 5)),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED &&
           (WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x41,
                              &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                              *(undefined1 *)(*param_4 + 6)),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)))))) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x42,
                          &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,
                          (char)*(undefined2 *)(*param_4 + 7));
      }
      goto LAB_140002d22;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x43,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  uVar10 = 0xc0000001;
LAB_1400035e9:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x45,
                     &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids);
  }
  return uVar10;
}



===== WPP_RECORDER_SF_d @ 140003650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_ @ 140003750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 140003830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== HumResetInterruptPipe @ 140003940 =====

int HumResetInterruptPipe(ulonglong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x55646948);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x1e0028;
    lVar3 = GetInterruptInputPipeForDevice(lVar3);
    if (lVar3 == 0) {
      iVar1 = -0x3ffffff0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xc,
                         &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids);
      }
    }
    else {
      *(undefined8 *)(puVar2 + 6) = *(undefined8 *)(lVar3 + 8);
      iVar1 = HumCallUSB(param_1,puVar2);
    }
    ExFreePool(puVar2);
  }
  return iVar1;
}



===== HumReadCompletion @ 140003a20 =====

ulonglong HumReadCompletion(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  uVar4 = 0;
  iVar2 = *(int *)(param_2 + 0x30);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (-1 < iVar2) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(param_3 + 0x24);
    goto LAB_140003a54;
  }
  if (iVar2 == -0x3ffffee0) {
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_140003a54;
    uVar6 = 0x17;
    bVar5 = 5;
    uVar7 = 0x20;
  }
  else {
    if (iVar2 != -0x3fffff63) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x18,
                           &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)param_2,
                           (char)iVar2);
      }
      uVar4 = HumQueueResetWorkItem(param_1,param_2);
      uVar4 = uVar4 & 0xffffffff;
      goto LAB_140003a54;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003a54;
    uVar6 = 0x19;
    uVar7 = 0x9d;
    bVar5 = 3;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,2,uVar6,
                     &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)param_2,uVar7);
LAB_140003a54:
  ExFreePool(param_3);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 < 0) {
    KeSetEvent(lVar3 + 0x28,0,0);
  }
  IoReleaseRemoveLockEx(lVar3 + 0x68,param_2,0x20);
  return uVar4;
}



===== HumInternalIoctl @ 140003bb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

IMAGE_DOS_HEADER * HumInternalIoctl(IMAGE_DOS_HEADER *param_1,longlong param_2)

{
  IMAGE_DOS_HEADER *pIVar1;
  byte *pbVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  int *piVar7;
  longlong *plVar8;
  bool bVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  IMAGE_DOS_HEADER *pIVar16;
  IMAGE_DOS_HEADER *pIVar17;
  short sVar18;
  IMAGE_DOS_HEADER *pIVar19;
  char *pcVar20;
  IMAGE_DOS_HEADER *pIVar21;
  IMAGE_DOS_HEADER *pIVar22;
  undefined2 uVar23;
  char *pcVar24;
  word wVar25;
  undefined1 auStackY_f8 [32];
  char local_b8;
  char local_b7 [3];
  uint local_b4;
  word *local_b0;
  uint local_a8;
  IMAGE_DOS_HEADER *local_a0;
  longlong *local_98;
  undefined1 *local_90;
  undefined8 local_88 [4];
  word **local_68;
  byte local_60 [8];
  uint *local_58;
  byte local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b7[0] = '\x01';
  bVar9 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
                     &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids);
  }
  pcVar20 = "";
  wVar25 = 1;
  pcVar24 = (char *)0x1;
  lVar6 = *(longlong *)(*(longlong *)param_1->e_program + 0x10);
  pIVar1 = (IMAGE_DOS_HEADER *)(lVar6 + 0x68);
  pIVar17 = pIVar1;
  uVar11 = IoAcquireRemoveLockEx();
  pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
  if ((int)uVar11 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xb,
                         &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids,(char)pIVar1,(char)uVar11)
      ;
      *(uint *)(param_2 + 0x30) = uVar11;
      IofCompleteRequest(param_2,0);
      goto LAB_140003e6c;
    }
    goto LAB_140003eba;
  }
  bVar9 = true;
  uVar11 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  pIVar21 = (IMAGE_DOS_HEADER *)pcVar20;
  local_a8 = uVar11;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pIVar17 = *(IMAGE_DOS_HEADER **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_Lqq(pIVar17);
    pIVar21 = (IMAGE_DOS_HEADER *)pcVar20;
  }
  if (uVar11 == 0xb000b) {
    local_98 = *(longlong **)(param_2 + 0xb8);
    piVar7 = *(int **)(*(longlong *)param_1->e_program + 0x10);
    local_90 = *(undefined1 **)(param_2 + 0x70);
    local_b0 = (word *)CONCAT44(local_b0._4_4_,(int)local_98[1]);
    if (((int)local_98[1] == 0) || (local_90 == (undefined1 *)0x0)) {
      pIVar19 = (IMAGE_DOS_HEADER *)0xc000000d;
LAB_140003dc2:
      if ((DAT_14000b000 < 6) || (pIVar17 = pIVar19, uVar14 = _tlgKeywordOn(), (char)uVar14 == '\0')
         ) goto LAB_140003e5f;
      local_b0 = (word *)CONCAT44(local_b0._4_4_,(int)pIVar17);
      goto LAB_140003ddf;
    }
    pIVar21 = *(IMAGE_DOS_HEADER **)(piVar7 + 4);
    uVar11._0_2_ = pIVar21->e_sp;
    uVar11._2_2_ = pIVar21->e_csum;
    pcVar24 = (char *)(ulonglong)uVar11;
    for (uVar14 = 0; (uint)uVar14 < uVar11; uVar14 = (ulonglong)((uint)uVar14 + 1)) {
      pcVar20 = pIVar21->e_magic + uVar14 * 0x18;
      if (((char)pIVar21->e_res_4_[uVar14 * 0xc + -1] < '\0') && (*(int *)(pcVar20 + 0x1c) == 3)) {
        if (pcVar20 != (char *)0xffffffffffffffe8) {
          pIVar21 = (IMAGE_DOS_HEADER *)0x55646948;
          puVar13 = (undefined4 *)ExAllocatePool2(0x40);
          if (puVar13 == (undefined4 *)0x0) {
            pIVar19 = (IMAGE_DOS_HEADER *)0xc000009a;
          }
          else {
            *puVar13 = 0x90080;
            *(undefined8 *)(puVar13 + 6) = *(undefined8 *)(pcVar20 + 0x20);
            puVar13[9] = local_b0._0_4_;
            *(undefined8 *)(puVar13 + 0xc) = 0;
            *(undefined8 *)(puVar13 + 0xe) = 0;
            *(undefined1 **)(puVar13 + 10) = local_90;
            puVar13[8] = 3;
            lVar6 = *(longlong *)(param_2 + 0xb8);
            *(code **)(lVar6 + -0x10) = HumReadCompletion;
            *(undefined4 **)(lVar6 + -8) = puVar13;
            *(undefined1 *)(lVar6 + -0x45) = 0xe0;
            pIVar21 = *(IMAGE_DOS_HEADER **)(param_2 + 0xb8);
            *(undefined4 **)pIVar21[-1].e_program = puVar13;
            *(char *)(pIVar21[-1].e_res2_10_ + 8) = (char)*local_98;
            pIVar21[-1].e_program[0x10] = 3;
            pIVar21[-1].e_program[0x11] = 0;
            pIVar21[-1].e_program[0x12] = 0x22;
            pIVar21[-1].e_program[0x13] = 0;
            *(undefined8 *)(pIVar21[-1].e_program + 0x20) =
                 *(undefined8 *)(*(longlong *)param_1->e_program + 8);
            LOCK();
            piVar7[8] = piVar7[8] + 1;
            UNLOCK();
            if (*piVar7 - 1U < 2) {
              uVar11 = IofCallDriver(*(undefined8 *)(*(longlong *)param_1->e_program + 8),param_2);
              pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
              local_b7[0] = '\0';
            }
            else {
              HumDecrementPendingRequestCount((longlong)piVar7);
              ExFreePool(puVar13);
              pIVar19 = (IMAGE_DOS_HEADER *)0xc000000e;
            }
          }
          goto LAB_140003db8;
        }
        break;
      }
    }
    pIVar19 = (IMAGE_DOS_HEADER *)0xc0000182;
LAB_140003db8:
    if ((int)pIVar19 < 0) goto LAB_140003dc2;
    goto LAB_140003e5f;
  }
  if (uVar11 == 0xb0263) {
LAB_140003e30:
    pIVar21 = (IMAGE_DOS_HEADER *)CONCAT71((int7)((ulonglong)pIVar21 >> 8),uVar11 == 0xb0263);
    pcVar24 = local_b7;
    uVar15 = HumWriteReport((longlong)param_1,param_2,uVar11 == 0xb0263,pcVar24);
    uVar11 = (uint)uVar15;
    pIVar17 = param_1;
    goto LAB_140003e43;
  }
  if (0xb0191 < uVar11) {
    if (uVar11 - 0xb0192 < 0xa2) {
      pIVar21 = &IMAGE_DOS_HEADER_140000000;
      pIVar17 = (IMAGE_DOS_HEADER *)
                (IMAGE_DOS_HEADER_140000000.e_magic +
                (&switchD_140003f68::switchdataD_140009488)
                [(&switchD_140003f68::switchdataD_1400094a0)[uVar11 - 0xb0192]]);
      switch(uVar11) {
      case 0xb0192:
      case 0xb0195:
      case 0xb01a2:
        goto switchD_140003f68_caseD_b0192;
      default:
        break;
      case 0xb019a:
        uVar11 = HumGetPhysicalDescriptor((ulonglong)param_1,param_2);
        goto LAB_1400042b9;
      case 0xb01e2:
        goto switchD_140003f68_caseD_b01e2;
      case 0xb01e6:
        uVar11 = HumGetMsGenreDescriptor((ulonglong)param_1,param_2);
        goto LAB_140004311;
      case 0xb0233:
        goto switchD_140003f68_caseD_b0233;
      }
    }
switchD_140003f68_caseD_b0193:
    pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)*(uint *)(param_2 + 0x30);
LAB_140004301:
    *(int *)(param_2 + 0x30) = (int)pIVar19;
    goto LAB_1400042be;
  }
  if (uVar11 == 0xb0191) {
switchD_140003f68_caseD_b0192:
    local_90 = *(undefined1 **)(param_2 + 0xb8);
    iVar5 = *(int *)(local_90 + 0x18);
    if (iVar5 == 0xb0191) {
      uVar12 = 0x300;
LAB_140003f8c:
      local_b8 = '\t';
      local_b4 = 0;
LAB_140003f97:
      plVar8 = *(longlong **)(param_2 + 0x70);
      local_b0 = (word *)CONCAT44(local_b0._4_4_,uVar12);
      pIVar17 = *(IMAGE_DOS_HEADER **)(*(longlong *)param_1->e_program + 0x10);
      local_a0 = pIVar17;
      if (((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) ||
         (local_98 = plVar8 + 1, (int)plVar8[1] == 0)) {
        pIVar19 = (IMAGE_DOS_HEADER *)0xc000003e;
        goto LAB_140003e49;
      }
      pIVar21 = (IMAGE_DOS_HEADER *)0x55646948;
      pIVar17 = (IMAGE_DOS_HEADER *)0x40;
      pIVar16 = (IMAGE_DOS_HEADER *)ExAllocatePool2();
      pIVar22 = local_a0;
      if (pIVar16 == (IMAGE_DOS_HEADER *)0x0) {
        pIVar19 = (IMAGE_DOS_HEADER *)0xc000009a;
      }
      else {
        bVar4 = *(byte *)((longlong)plVar8 + 0xc);
        sVar18 = (short)local_b0;
        uVar11 = *(uint *)local_a0->e_program;
        pIVar16->e_magic[0] = -0x78;
        pIVar16->e_magic[1] = '\0';
        if ((uVar11 & 1) == 0) {
          pIVar16->e_cblp = 0x1b;
          wVar25 = (word)*(byte *)(*(longlong *)&local_a0->e_sp + 2);
          local_a0 = pIVar16 + 1;
        }
        else {
          pIVar16->e_cblp = 0x1c;
        }
        local_b0 = &pIVar16[1].e_cp;
        *local_b0 = wVar25;
        pIVar16[1].e_magic[0] = '\"';
        pIVar16[1].e_magic[1] = local_b8;
        pIVar16[1].e_cblp = sVar18 + (ushort)bVar4;
        *(uint *)(pIVar16->e_res_4_ + 2) = local_b4;
        *(longlong *)pIVar16->e_res2_10_ = *plVar8;
        lVar6 = *local_98;
        pIVar16->e_oemid = (short)lVar6;
        pIVar16->e_oeminfo = (short)((ulonglong)lVar6 >> 0x10);
        lVar6 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar6 + -0x10) = HumWriteCompletion;
        *(IMAGE_DOS_HEADER **)(lVar6 + -8) = pIVar16;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        *(IMAGE_DOS_HEADER **)(local_90 + -0x40) = pIVar16;
        local_90[-0x48] = *local_90;
        *(undefined4 *)(local_90 + -0x30) = 0x220003;
        *(undefined8 *)(local_90 + -0x20) = *(undefined8 *)(*(longlong *)param_1->e_program + 8);
        LOCK();
        *(int *)(pIVar22->e_res_4_ + 2) = *(int *)(pIVar22->e_res_4_ + 2) + 1;
        UNLOCK();
        if (*(int *)pIVar22 - 1U < 2) {
          pIVar17 = *(IMAGE_DOS_HEADER **)(*(longlong *)param_1->e_program + 8);
          uVar11 = IofCallDriver(pIVar17,param_2);
          pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
          local_b7[0] = '\0';
          pIVar21 = pIVar22;
        }
        else {
          HumDecrementPendingRequestCount((longlong)pIVar22);
          ExFreePool();
          pIVar19 = (IMAGE_DOS_HEADER *)0xc000000e;
          pIVar17 = pIVar16;
          pIVar21 = pIVar22;
        }
      }
      uVar11 = (uint)pIVar19;
      goto LAB_140003e47;
    }
    if (iVar5 == 0xb0192) {
      local_b4 = 1;
      uVar12 = 0x300;
      local_b8 = '\x01';
      goto LAB_140003f97;
    }
    if (iVar5 == 0xb0195) {
      uVar12 = 0x200;
      goto LAB_140003f8c;
    }
    if (iVar5 == 0xb01a2) {
      local_b4 = 1;
      uVar12 = 0x100;
      local_b8 = '\x01';
      goto LAB_140003f97;
    }
    pIVar19 = (IMAGE_DOS_HEADER *)0xc00000bb;
    goto LAB_140003e49;
  }
  pIVar21 = &IMAGE_DOS_HEADER_140000000;
  switch(uVar11) {
  case 0xb0003:
    uVar15 = HumGetHidDescriptor((longlong)param_1,param_2);
    uVar11 = (uint)uVar15;
    break;
  default:
    goto switchD_140003f68_caseD_b0193;
  case 0xb0007:
    pIVar21 = (IMAGE_DOS_HEADER *)local_b7;
    uVar11 = HumGetReportDescriptor((ulonglong)param_1,param_2,(undefined1 *)pIVar21);
    pIVar17 = param_1;
    goto LAB_140003e43;
  case 0xb000f:
    goto LAB_140003e30;
  case 0xb0013:
switchD_140003f68_caseD_b01e2:
    pIVar21 = &IMAGE_DOS_HEADER_140000000;
    uVar11 = HumGetStringDescriptor((ulonglong)param_1,param_2);
LAB_140004311:
    pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
    if (((-1 < (int)uVar11) || (DAT_14000b000 < 6)) ||
       (uVar14 = _tlgKeywordOn(), (char)uVar14 == '\0')) goto LAB_140003eba;
    local_68 = &local_b0;
    local_b0 = (word *)CONCAT44(local_b0._4_4_,uVar11);
    local_b4 = local_a8;
    local_58 = &local_b4;
    local_60[0] = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 0;
    local_60[4] = 0;
    local_60[5] = 0;
    local_60[6] = 0;
    local_60[7] = 0;
    local_50[0] = 4;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    local_50[7] = 0;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000967e,pIVar21,pcVar24,4,local_88);
    goto LAB_140004301;
  case 0xb001f:
  case 0xb0023:
    pIVar19 = (IMAGE_DOS_HEADER *)0x0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    goto LAB_1400042be;
  case 0xb0027:
    uVar15 = HumGetDeviceAttributes((longlong)param_1,param_2);
    uVar11 = (uint)uVar15;
    break;
  case 0xb002b:
    pIVar21 = (IMAGE_DOS_HEADER *)local_b7;
    uVar15 = HumSendIdleNotificationRequest((longlong)param_1,param_2,(undefined1 *)pIVar21);
    uVar11 = (uint)uVar15;
    pIVar17 = param_1;
LAB_140003e43:
    pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
LAB_140003e47:
    if ((int)uVar11 < 0) {
LAB_140003e49:
      if ((5 < DAT_14000b000) && (uVar14 = _tlgKeywordOn(), (char)uVar14 != '\0')) {
        local_b0 = (word *)CONCAT44(local_b0._4_4_,(int)pIVar19);
LAB_140003ddf:
        local_68 = &local_b0;
        local_60[0] = 4;
        local_60[1] = 0;
        local_60[2] = 0;
        local_60[3] = 0;
        local_60[4] = 0;
        local_60[5] = 0;
        local_60[6] = 0;
        local_60[7] = 0;
        local_b4 = local_a8;
        local_58 = &local_b4;
        local_50[0] = 4;
        local_50[1] = 0;
        local_50[2] = 0;
        local_50[3] = 0;
        local_50[4] = 0;
        local_50[5] = 0;
        local_50[6] = 0;
        local_50[7] = 0;
        _tlgWriteTransfer_EtwWriteTransfer(pIVar17,&DAT_14000967e,pIVar21,pcVar24,4,local_88);
      }
    }
LAB_140003e5f:
    if (local_b7[0] == '\0') goto LAB_140003e6c;
LAB_140003eba:
    *(int *)(param_2 + 0x30) = (int)pIVar19;
    IofCompleteRequest(param_2,0);
    if (!bVar9) goto LAB_140003e6c;
    goto LAB_140003eda;
  }
LAB_1400042b9:
  pIVar19 = (IMAGE_DOS_HEADER *)(ulonglong)uVar11;
  *(uint *)(param_2 + 0x30) = uVar11;
LAB_1400042be:
  IofCompleteRequest(param_2,0);
LAB_140003eda:
  IoReleaseRemoveLockEx(pIVar1,param_2,0x20);
LAB_140003e6c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x10,
                     &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids);
  }
  return pIVar19;
switchD_140003f68_caseD_b0233:
  uVar10 = KeAcquireSpinLockRaiseToDpc();
  if (*(longlong *)(lVar6 + 0x90) == 0) {
    *(longlong *)(lVar6 + 0x90) = param_2;
    LOCK();
    *(code **)(param_2 + 0x68) = HumDeviceResetNotificationIrpCancelled;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) != '\0') {
      LOCK();
      lVar3 = *(longlong *)(param_2 + 0x68);
      *(longlong *)(param_2 + 0x68) = 0;
      UNLOCK();
      if (lVar3 != 0) {
        *(undefined8 *)(lVar6 + 0x90) = 0;
        KeReleaseSpinLock(lVar6 + 0x88,uVar10);
        pIVar19 = (IMAGE_DOS_HEADER *)0xc0000120;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar23 = 0xe;
          goto LAB_14000449a;
        }
        goto LAB_140003eba;
      }
    }
    pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    KeReleaseSpinLock(lVar6 + 0x88,uVar10);
    pIVar19 = (IMAGE_DOS_HEADER *)0x103;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return (IMAGE_DOS_HEADER *)0x103;
    }
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
                       &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids,(char)param_2,(char)param_1)
    ;
    goto LAB_140003e6c;
  }
  KeReleaseSpinLock(lVar6 + 0x88,uVar10);
  pIVar19 = (IMAGE_DOS_HEADER *)0xc0000010;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003eba;
  uVar23 = 0xf;
LAB_14000449a:
  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar23,
                     &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids,(char)param_2,(char)param_1);
  *(int *)(param_2 + 0x30) = (int)pIVar19;
  IofCompleteRequest(param_2,0);
  goto LAB_140003eda;
}



===== HumWriteReport @ 140004530 =====

undefined8 HumWriteReport(longlong param_1,longlong param_2,char param_3,undefined1 *param_4)

{
  longlong lVar1;
  byte bVar2;
  longlong *plVar3;
  undefined1 *puVar4;
  int *piVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  longlong lVar11;
  
  plVar3 = *(longlong **)(param_2 + 0x70);
  puVar4 = *(undefined1 **)(param_2 + 0xb8);
  piVar5 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (((plVar3 == (longlong *)0x0) || (*plVar3 == 0)) || ((int)plVar3[1] == 0)) {
    return 0xc000003e;
  }
  puVar9 = (undefined4 *)ExAllocatePool2(0x40,0x98,0x55646948);
  if (puVar9 == (undefined4 *)0x0) {
    return 0xc000009a;
  }
  if ((piVar5[0x10] & 1U) == 0) {
    lVar6 = *(longlong *)(piVar5 + 4);
    lVar11 = 0;
    for (uVar7 = 0; uVar7 < *(uint *)(lVar6 + 0x10); uVar7 = uVar7 + 1) {
      lVar1 = lVar6 + (ulonglong)uVar7 * 0x18;
      if ((-1 < *(char *)(lVar6 + 0x1a + (ulonglong)uVar7 * 0x18)) && (*(int *)(lVar1 + 0x1c) == 3))
      {
        lVar11 = lVar1 + 0x18;
        break;
      }
    }
    if (lVar11 != 0) {
      *puVar9 = 0x90080;
      *(undefined8 *)(puVar9 + 6) = *(undefined8 *)(lVar11 + 8);
      puVar9[9] = (int)plVar3[1];
      *(undefined8 *)(puVar9 + 0xc) = 0;
      *(longlong *)(puVar9 + 10) = *plVar3;
      puVar9[8] = 2;
      *(undefined8 *)(puVar9 + 0xe) = 0;
      goto LAB_14000464c;
    }
    *(undefined2 *)puVar9 = 0x88;
    if (param_3 != '\0') {
      *(undefined2 *)((longlong)puVar9 + 2) = 0x32;
      puVar9[8] = 8;
      *(longlong *)(puVar9 + 10) = *plVar3;
      puVar9[9] = (int)plVar3[1];
      iVar8 = *(int *)((longlong)plVar3 + 0x14);
      *(undefined2 *)(puVar9 + 0x20) = 0x921;
      if (iVar8 == 0) {
        iVar8 = 5000;
      }
      puVar9[0xe] = iVar8;
      *(ushort *)((longlong)puVar9 + 0x82) = *(byte *)((longlong)plVar3 + 0xc) + 0x200;
      *(ushort *)(puVar9 + 0x21) = (ushort)*(byte *)(*(longlong *)(piVar5 + 4) + 2);
      *(short *)((longlong)puVar9 + 0x86) = (short)plVar3[1];
      goto LAB_14000464c;
    }
    *(undefined2 *)((longlong)puVar9 + 2) = 0x1b;
    *(ushort *)(puVar9 + 0x21) = (ushort)*(byte *)(*(longlong *)(piVar5 + 4) + 2);
    *(undefined2 *)(puVar9 + 0x20) = 0x922;
    bVar2 = *(byte *)((longlong)plVar3 + 0xc);
  }
  else {
    lVar11 = GetInterruptInputPipeForDevice((longlong)piVar5);
    if (lVar11 == 0) {
      ExFreePool(puVar9);
      return 0xc000003e;
    }
    bVar2 = *(byte *)(lVar11 + 2);
    *puVar9 = 0x1c0088;
    *(ushort *)(puVar9 + 0x21) = (ushort)(bVar2 & 0x7f);
    *(undefined2 *)(puVar9 + 0x20) = 0x922;
    bVar2 = *(byte *)((longlong)plVar3 + 0xc);
  }
  *(ushort *)((longlong)puVar9 + 0x82) = bVar2 + 0x200;
  puVar9[8] = 0;
  *(longlong *)(puVar9 + 10) = *plVar3;
  puVar9[9] = (int)plVar3[1];
LAB_14000464c:
  lVar11 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar11 + -0x10) = HumWriteCompletion;
  *(undefined4 **)(lVar11 + -8) = puVar9;
  *(undefined1 *)(lVar11 + -0x45) = 0xe0;
  *(undefined4 **)(puVar4 + -0x40) = puVar9;
  puVar4[-0x48] = *puVar4;
  *(undefined4 *)(puVar4 + -0x30) = 0x220003;
  *(undefined8 *)(puVar4 + -0x20) = *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8);
  LOCK();
  piVar5[8] = piVar5[8] + 1;
  UNLOCK();
  if (*piVar5 - 1U < 2) {
    uVar10 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
    *param_4 = 0;
  }
  else {
    HumDecrementPendingRequestCount((longlong)piVar5);
    ExFreePool(puVar9);
    uVar10 = 0xc000000e;
  }
  return uVar10;
}



===== WPP_RECORDER_SF_Lqq @ 140004800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids,0xc,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_2854d9da723b379c5be992cbaea3dfcc_Traceguids,0xc,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== GetInterruptInputPipeForDevice @ 140004920 =====

longlong GetInterruptInputPipeForDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar3 = 0;
  while( true ) {
    if (*(uint *)(lVar2 + 0x10) <= (uint)uVar3) {
      return 0;
    }
    lVar1 = lVar2 + uVar3 * 0x18;
    if ((*(char *)(lVar2 + 0x1a + uVar3 * 0x18) < '\0') && (*(int *)(lVar1 + 0x1c) == 3)) break;
    uVar3 = (ulonglong)((uint)uVar3 + 1);
  }
  return lVar1 + 0x18;
}



===== HumSendIdleNotificationRequest @ 140004960 =====

undefined8 HumSendIdleNotificationRequest(longlong param_1,longlong param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 0xb8);
  if (*(uint *)(puVar1 + 0x10) < 0x10) {
    uVar3 = 0xc0000023;
  }
  else {
    IoReleaseRemoveLockEx(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x68,param_2,0x20);
    puVar1[-0x48] = *puVar1;
    *(undefined4 *)(puVar1 + -0x38) = *(undefined4 *)(puVar1 + 0x10);
    *(undefined8 *)(puVar1 + -0x28) = *(undefined8 *)(puVar1 + 0x20);
    *(undefined4 *)(puVar1 + -0x30) = 0x220027;
    lVar2 = *(longlong *)(param_1 + 0x40);
    *param_3 = 0;
    *(undefined8 *)(puVar1 + -0x20) = *(undefined8 *)(lVar2 + 8);
    uVar3 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  }
  return uVar3;
}



===== HumResetWorkItem @ 140004a10 =====

void HumResetWorkItem(longlong param_1,longlong param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined2 uVar7;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  bVar2 = false;
  piVar1 = *(int **)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x40) + 0x10);
  uVar4 = HumIncrementPendingRequestCount(piVar1);
  if ((int)uVar4 < 0) goto LAB_140004ccd;
  uVar5 = HumGetPortStatus(*(longlong *)(param_2 + 0x10),local_res10);
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x15,
                        &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)uVar5);
    }
  }
  else if ((local_res10[0] & 2) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x14,
                        &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)local_res10[0]);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xd,
                        &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)local_res10[0]);
    }
    iVar3 = HumAbortPendingRequests(*(ulonglong *)(param_2 + 0x10));
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x12;
        bVar6 = 3;
LAB_140004c30:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar6,2,uVar7,
                          &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)iVar3);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xe,
                         &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids);
      }
      uVar5 = HumResetParentPort(*(longlong *)(param_2 + 0x10));
      iVar3 = (int)uVar5;
      if (iVar3 == -0x3fffff64) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xf,
                             &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,0x9c,
                             (char)*(undefined8 *)(param_2 + 0x10));
        }
        *piVar1 = 6;
        IoInvalidateDeviceState(**(undefined8 **)(*(longlong *)(param_2 + 0x10) + 0x40));
      }
      else {
        if (iVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x10;
            bVar6 = 2;
LAB_140004bb8:
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar6,2,uVar7,
                              &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)uVar5);
          }
        }
        else {
          bVar2 = true;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x11;
            bVar6 = 4;
            goto LAB_140004bb8;
          }
        }
        if ((-1 < iVar3) &&
           (iVar3 = HumResetInterruptPipe(*(ulonglong *)(param_2 + 0x10)),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = 0x13;
          bVar6 = 4;
          goto LAB_140004c30;
        }
      }
    }
  }
  HumDecrementPendingRequestCount((longlong)piVar1);
LAB_140004ccd:
  LOCK();
  piVar1[0x12] = 0;
  piVar1[0x13] = 0;
  UNLOCK();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qcc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (bVar2) {
    HumCompleteDeviceResetNotificationIrp(param_1,0);
  }
  IofCompleteRequest(*(undefined8 *)(param_2 + 0x18),0);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 8));
  ExFreePool(param_2);
  HumDecrementPendingRequestCount((longlong)piVar1);
  IoReleaseRemoveLockEx(piVar1 + 0x1a,0x57525548,0x20);
  return;
}



===== HumQueueResetWorkItem @ 140004d90 =====

undefined8 HumQueueResetWorkItem(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  byte *pbVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  bool bVar7;
  
  piVar3 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar4 = HumIncrementPendingRequestCount(piVar3);
  if ((int)uVar4 < 0) {
    return 0;
  }
  puVar5 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x55646948);
  if (puVar5 == (undefined4 *)0x0) {
    HumDecrementPendingRequestCount((longlong)piVar3);
  }
  else {
    lVar6 = IoAllocateWorkItem(*(undefined8 *)(piVar3 + 0x18));
    *(longlong *)(puVar5 + 2) = lVar6;
    puVar1 = (undefined8 *)(puVar5 + 2);
    if (lVar6 != 0) {
      LOCK();
      bVar7 = *(longlong *)(piVar3 + 0x12) == 0;
      if (bVar7) {
        *(undefined8 **)(piVar3 + 0x12) = puVar1;
      }
      UNLOCK();
      if (bVar7) {
        *puVar5 = 0x74657352;
        *(longlong *)(puVar5 + 6) = param_2;
        *(longlong *)(puVar5 + 4) = param_1;
        pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar2 = *pbVar2 | 1;
        IoAcquireRemoveLockEx(piVar3 + 0x1a,0x57525548,"",1,0x20);
        IoQueueWorkItem(*puVar1,HumResetWorkItem,1,puVar5);
        return 0xc0000016;
      }
      IoFreeWorkItem(*puVar1);
    }
    ExFreePool(puVar5);
    HumDecrementPendingRequestCount((longlong)piVar3);
  }
  return 0;
}



===== HumIncrementPendingRequestCount @ 140004ee0 =====

undefined8 HumIncrementPendingRequestCount(int *param_1)

{
  LOCK();
  param_1[8] = param_1[8] + 1;
  UNLOCK();
  if (*param_1 - 1U < 2) {
    return 0;
  }
  HumDecrementPendingRequestCount((longlong)param_1);
  return 0xc000000e;
}



===== HumDecrementPendingRequestCount @ 140004f10 =====

void HumDecrementPendingRequestCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 < 0) {
    KeSetEvent(param_1 + 0x28,0,0);
  }
  return;
}



===== HumGetPortStatus @ 140004f50 =====

ulonglong HumGetPortStatus(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  *param_2 = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x220013,*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),0,0,0,0,1,
                     local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined4 **)(*(longlong *)(lVar1 + 0xb8) + -0x40) = param_2;
    uVar2 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,5,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== WPP_RECORDER_SF_qq @ 140005050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 140005190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== HumResetParentPort @ 1400052d0 =====

ulonglong HumResetParentPort(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x220007,*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),0,0,0,0,1,
                     local_38 + 2,local_38);
  if (lVar1 == 0) {
    return 0xc000009a;
  }
  uVar2 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),lVar1);
  if ((int)uVar2 == 0x103) {
    KeWaitForSingleObject(local_38 + 2,5,0,0,0);
    uVar2 = local_38[0] & 0xffffffff;
  }
  return uVar2;
}



===== WPP_RECORDER_SF_qcc @ 1400053d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qcc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,1,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,1,&uStack0000000000000040,1,0);
  return;
}



===== HumWriteCompletion @ 1400054d0 =====

undefined8 HumWriteCompletion(longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (-1 < *(int *)(param_2 + 0x30)) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(param_3 + 0x24);
  }
  ExFreePool(param_3);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  LOCK();
  piVar2 = (int *)(lVar4 + 0x20);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 + -1 < 0) {
    KeSetEvent(lVar4 + 0x28,0,0);
  }
  IoReleaseRemoveLockEx(lVar4 + 0x68,param_2,0x20);
  return 0;
}



===== HumPower @ 140005570 =====

ulonglong HumPower(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = IoAcquireRemoveLockEx
                    (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x68,param_2,"",1,0x20);
  if ((int)uVar3 < 0) {
    PoStartNextPowerIrp();
    *(uint *)(param_2 + 0x30) = uVar3;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = (ulonglong)uVar3;
  }
  else {
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
    *(code **)(lVar2 + -0x10) = HumPowerCompletion;
    *(undefined8 *)(lVar2 + -8) = 0;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar4 = PoCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  }
  return uVar4;
}



===== HumCallUsbComplete @ 140005660 =====

undefined8 HumCallUsbComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== HumPnpCompletion @ 140005690 =====

undefined8 HumPnpCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,1);
  return 0xc0000016;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400056c0 =====

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
  *param_6 = PTR_DAT_14000b008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000b008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000b020,&local_18,0,0,param_5,param_6);
  return;
}



===== HumAddDevice @ 140005770 =====

undefined8 HumAddDevice(undefined8 param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar2;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_1af868856896395a050634e1874b08f4_Traceguids);
  }
  puVar1 = *(undefined4 **)(*(longlong *)(param_2 + 0x40) + 0x10);
  puVar1[0x10] = 0;
  puVar1[8] = 0;
  KeInitializeEvent(puVar1 + 10,0,0);
  *(undefined8 *)(puVar1 + 0x12) = 0;
  *puVar1 = 0;
  *(longlong *)(puVar1 + 0x18) = param_2;
  KeInitializeSpinLock(puVar1 + 0x22);
  *(undefined8 *)(puVar1 + 0x24) = 0;
  IoInitializeRemoveLockEx(puVar1 + 0x1a,0x55646948,2,0,CONCAT44(uVar2,0x20));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_1af868856896395a050634e1874b08f4_Traceguids);
  }
  return 0;
}



===== WPP_RECORDER_SF_dq @ 140005890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== HumCompleteDeviceResetNotificationIrp @ 1400059d0 =====

void HumCompleteDeviceResetNotificationIrp(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x88);
  lVar2 = *(longlong *)(lVar1 + 0x90);
  if (lVar2 == 0) {
    KeReleaseSpinLock(lVar1 + 0x88,uVar3);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x15,
                         &WPP_1af868856896395a050634e1874b08f4_Traceguids,(char)param_2,
                         (char)param_1);
    }
  }
  else {
    *(undefined8 *)(lVar1 + 0x90) = 0;
    KeReleaseSpinLock();
    LOCK();
    *(undefined8 *)(lVar2 + 0x68) = 0;
    UNLOCK();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    *(undefined4 *)(lVar2 + 0x30) = param_2;
    IofCompleteRequest(lVar2,0);
    IoReleaseRemoveLockEx(lVar1 + 0x68,lVar2,0x20);
  }
  return;
}



===== DriverEntry @ 140005b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  bool bVar4;
  longlong lVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [40];
  int local_b8 [4];
  longlong local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined1 local_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  undefined *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  local_b8[3] = 0;
  wil_InitializeFeatureStaging();
  puVar7 = auStack_e8;
  local_90 = *(undefined4 *)(PTR_DAT_14000b008 + -0x10);
  uStack_8c = *(undefined4 *)(PTR_DAT_14000b008 + -0xc);
  uStack_88 = *(undefined8 *)(PTR_DAT_14000b008 + -8);
  if (DAT_14000b020 != 0) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
    puVar7 = auStack_e0;
  }
  _DAT_14000b028 = 0;
  uRam000000014000b030 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140005b90;
  iVar6 = EtwRegister(&local_90,_tlgEnableCallback,&DAT_14000b000,&DAT_14000b020);
  if (iVar6 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000b008;
    *(undefined8 *)(puVar7 + -8) = 0x140005bb5;
    EtwSetInformation(DAT_14000b020,2,PTR_DAT_14000b008,uVar1);
  }
  _WPP_MAIN_CB = 0;
  DAT_14000b1e8 = &WPP_ThisDir_CTLGUID_HidUsbTraceGuid;
  DAT_14000b1f0 = 0;
  _DAT_14000b200 = 0;
  _DAT_14000b208 = 1;
  _DAT_14000b220 = 0;
  _DAT_14000b228 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140005bfa;
  WppLoadTracingSupport();
  _DAT_14000b200 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140005c0c;
  WppInitKm(param_1,param_2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined **)(puVar7 + 0x20) = &WPP_1af868856896395a050634e1874b08f4_Traceguids;
      *(undefined8 *)(puVar7 + -8) = 0x140005c4a;
      WPP_RECORDER_SF_(uVar2,5,1,10,*(undefined8 *)(puVar7 + 0x20));
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      *(longlong *)(puVar7 + 0x28) = param_1;
      *(undefined **)(puVar7 + 0x20) = &WPP_1af868856896395a050634e1874b08f4_Traceguids;
      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined8 *)(puVar7 + -8) = 0x140005c79;
      WPP_RECORDER_SF_q(uVar2,4,1,0xb,*(undefined8 *)(puVar7 + 0x20),puVar7[0x28]);
    }
  }
  *(code **)(param_1 + 0x80) = HumCreateClose;
  *(code **)(param_1 + 0x70) = HumCreateClose;
  *(code **)(param_1 + 0xe8) = HumInternalIoctl;
  *(code **)(param_1 + 0x148) = HumPnP;
  *(code **)(param_1 + 0x120) = HumPower;
  *(code **)(param_1 + 0x128) = HumSystemControl;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = HumAddDevice;
  *(code **)(param_1 + 0x68) = HumUnload;
  local_b8[2] = 1;
  local_98 = 0x98;
  local_94 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140005d02;
  local_a8 = param_1;
  local_a0 = param_2;
  iVar6 = HidRegisterMinidriver(local_b8 + 2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    *(int *)(puVar7 + 0x28) = iVar6;
    *(undefined **)(puVar7 + 0x20) = &WPP_1af868856896395a050634e1874b08f4_Traceguids;
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar7 + -8) = 0x140005d37;
    WPP_RECORDER_SF_d(uVar2,4,1,0xc,*(undefined8 *)(puVar7 + 0x20),puVar7[0x28]);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140005d45;
  KeInitializeSpinLock(&resetWorkItemsListSpinLock);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar7 + 0x20) = &WPP_1af868856896395a050634e1874b08f4_Traceguids;
    *(undefined8 *)(puVar7 + -8) = 0x140005d7a;
    WPP_RECORDER_SF_(uVar2,5,1,0xd,*(undefined8 *)(puVar7 + 0x20));
  }
  if (iVar6 < 0) {
    if (5 < DAT_14000b000) {
      if (((_DAT_14000b010 & 0x200000000000) == 0) ||
         ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        uStack_88 = 0x200000000000;
        local_58 = local_b8;
        local_48 = "HIDUSB_MiniportReg";
        local_78 = PTR_DAT_14000b008;
        uStack_8c = 5;
        local_50 = 4;
        local_40 = 0x13;
        local_90 = 0xb000000;
        local_70 = (uint)*(ushort *)PTR_DAT_14000b008;
        local_68 = &DAT_14000961c;
        local_6c = 2;
        local_60 = 0x2a;
        local_5c = 1;
        local_b8[1] = 0xea;
        local_b8[0] = iVar6;
        *(undefined ***)(puVar7 + 0x28) = &local_78;
        *(undefined4 *)(puVar7 + 0x20) = 4;
        *(undefined8 *)(puVar7 + -8) = 0x140005e71;
        EtwWriteTransfer(DAT_14000b020,&local_90,0,0);
      }
    }
    lVar5 = DAT_14000b020;
    DAT_14000b020 = 0;
    DAT_14000b000 = 0;
    *(undefined8 *)(puVar7 + -8) = 0x140005e91;
    EtwUnregister(lVar5);
    *(undefined8 *)(puVar7 + -8) = 0x140005e9e;
    WppCleanupKm(param_1);
    if (g_wil_details_featureChangeNotification != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x140005eb1;
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x140005ed0;
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140005ef0;
  return iVar6;
}



===== HumUnload @ 140005f10 =====

void HumUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                      &WPP_1af868856896395a050634e1874b08f4_Traceguids,(char)param_1);
  }
  uVar1 = DAT_14000b020;
  DAT_14000b000 = 0;
  DAT_14000b020 = 0;
  EtwUnregister(uVar1);
  WppCleanupKm(param_1);
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



===== __report_gsfailure @ 140005ff0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== HumCreateClose @ 140006000 =====

undefined4 HumCreateClose(undefined1 param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  uVar1 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_1af868856896395a050634e1874b08f4_Traceguids);
  }
  if (**(char **)(param_2 + 0xb8) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = 0xf;
LAB_1400060d1:
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar2,
                         &WPP_1af868856896395a050634e1874b08f4_Traceguids,(char)param_2,param_1);
    }
  }
  else {
    if (**(char **)(param_2 + 0xb8) != '\x02') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x11,
                           &WPP_1af868856896395a050634e1874b08f4_Traceguids,(char)param_2,param_1);
      }
      uVar1 = 0xc000000d;
      goto LAB_1400060f9;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = 0x10;
      goto LAB_1400060d1;
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1400060f9:
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_1af868856896395a050634e1874b08f4_Traceguids);
  }
  return uVar1;
}



===== HumDeviceResetNotificationIrpCancelled @ 140006170 =====

void HumDeviceResetNotificationIrpCancelled(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  bool bVar4;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x88);
  bVar4 = *(longlong *)(lVar1 + 0x90) != param_2;
  if (!bVar4) {
    *(undefined8 *)(lVar1 + 0x90) = 0;
  }
  KeReleaseSpinLock(lVar1 + 0x88,uVar2);
  if (bVar4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0x18;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar1 + 0x68,param_2,0x20);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0x17;
  }
  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar3,
                     &WPP_1af868856896395a050634e1874b08f4_Traceguids,(char)param_2,(char)param_1);
  return;
}



===== WPP_RECORDER_SF_qdq @ 1400062a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1af868856896395a050634e1874b08f4_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1af868856896395a050634e1874b08f4_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WppClassicProviderCallback @ 1400063a0 =====

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



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 1400063fc =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140006408 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000a7a7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140006430 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140006590 =====

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



===== HumSetIdleWorker @ 140006620 =====

void HumSetIdleWorker(ulonglong param_1,undefined8 param_2)

{
  HumSetIdle(param_1);
  IoFreeWorkItem(param_2);
  return;
}



===== WPP_RECORDER_SF_L @ 14000664c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,0x13,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,3,4,&WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,0x13,
                  &uStack0000000000000030,4,0);
  return;
}



===== Feature_HOFFEB__private_IsEnabledDeviceUsageNoInline @ 1400066f8 =====

ulonglong Feature_HOFFEB__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_HOFFEB__private_featureState;
  if ((Feature_HOFFEB__private_featureState & 0x10) == 0) {
    uVar1 = Feature_HOFFEB__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_HOFFEB__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_HOFFEB__private_IsEnabledFallback @ 140006730 =====

void Feature_HOFFEB__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_Dl @ 140006748 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dl(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x2d,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x2d,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_dD @ 140006818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x61,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_ffc04ad7a4bc34c6f404a660c0f6d017_Traceguids,0x61,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400068e8 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400069c0 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140006aa4 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140006bfc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140006bef:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140006bfc;
      if (uVar5 == 5) goto LAB_140006bef;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140006c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3758d4b,&Feature_ValLabTest_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

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
                     (local_50,(uint *)&Feature_HOFFEB__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3758d4b,param_3 & 0xffffffff,1,&Feature_HOFFEB__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3758d4b);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006d8c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140006e9c =====

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
  if ((Feature_HOFFEB__private_featureState & 2) != 0) {
    uVar1 = Feature_HOFFEB__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_HOFFEB__private_featureState;
      if (bVar3) {
        Feature_HOFFEB__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_HOFFEB__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140006ef0 =====

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



===== wil_details_IsEnabledFallback @ 140007050 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_HOFFEB__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_HOFFEB__private_featureState,(ulonglong)param_1,0x14000a6c8);
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



===== wil_details_MapReportingKind @ 1400070e0 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== _guard_check_icall @ 140007190 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400071a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400071cc =====

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



===== __cpu_features_init @ 140007240 =====

/* WARNING: Removing unreachable block (ram,0x0001400072aa) */
/* WARNING: Removing unreachable block (ram,0x000140007259) */
/* WARNING: Removing unreachable block (ram,0x00014000724a) */

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



===== __security_check_cookie @ 140007310 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007350 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007380 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400073b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140007400 =====

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



===== memset @ 140007700 =====

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



===== __memset_repmovs @ 140007840 =====

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



===== __memset_query @ 1400078c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007940 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007a80 =====

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



===== __memset_spec_plain @ 140007b00 =====

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



===== WppTraceCallback @ 14000e010 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000e298 =====

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
      goto LAB_14000e2f5;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000e2f5;
    }
  }
  uVar1 = 0x206;
LAB_14000e2f5:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000e300 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
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
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000e3b8 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000e3f0 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000e472;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000e472;
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
LAB_14000e472:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000e4c0 =====

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
      ppuVar3 = &wil_details_featureDescriptors_a;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000e520 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000e53c =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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



===== HumGetMsGenreDescriptor @ 14000e5f0 =====

int HumGetMsGenreDescriptor(ulonglong param_1,longlong param_2)

{
  undefined1 uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  void *_Dst;
  undefined4 *puVar6;
  undefined *in_stack_ffffffffffffffd8;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1a,
                     &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids);
  }
  uVar2 = *(uint *)(lVar3 + 8);
  if (uVar2 != 0) {
    lVar3 = *(longlong *)(param_2 + 8);
    if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache
                               (lVar3,0,1,0,
                                (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffff00000000,0x40000010
                               );
    }
    else {
      _Dst = *(void **)(lVar3 + 0x18);
    }
    if (_Dst != (void *)0x0) {
      puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x55646948);
      if (puVar6 == (undefined4 *)0x0) {
        return -0x3fffff66;
      }
      memset(_Dst,0,(ulonglong)uVar2);
      *(undefined8 *)(puVar6 + 0xc) = 0;
      *puVar6 = 0x2a0088;
      *(byte *)(puVar6 + 0x20) = *(byte *)(puVar6 + 0x20) & 0xe1 | 1;
      puVar6[9] = uVar2;
      *(void **)(puVar6 + 10) = _Dst;
      uVar1 = *(undefined1 *)(*(longlong *)(lVar4 + 0x10) + 2);
      *(undefined8 *)(puVar6 + 0xe) = 0;
      *(undefined1 *)((longlong)puVar6 + 0x82) = uVar1;
      *(undefined2 *)(puVar6 + 0x21) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1b,
                         &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids);
      }
      iVar5 = HumCallUSB(param_1,puVar6);
      if (iVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1e,
                            &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)iVar5);
        }
      }
      else if ((int)puVar6[1] < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1d,
                            &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)puVar6[1]);
        }
        iVar5 = -0x3fffffff;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1c,
                           &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids);
        }
        iVar5 = 0;
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uint)puVar6[9];
      }
      ExFreePool(puVar6);
      return iVar5;
    }
  }
  return -0x3fffff18;
}



===== HumGetPhysicalDescriptor @ 14000e844 =====

int HumGetPhysicalDescriptor(ulonglong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  uint local_res10 [2];
  longlong local_res18 [2];
  ulonglong in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffe0;
  undefined4 in_stack_ffffffffffffffe4;
  
  local_res10[0] = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (local_res10[0] != 0) {
    lVar1 = *(longlong *)(param_2 + 8);
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      in_stack_ffffffffffffffe0 = 0x40000010;
      local_res18[0] =
           MmMapLockedPagesSpecifyCache(lVar1,0,1,0,in_stack_ffffffffffffffd8 & 0xffffffff00000000);
    }
    else {
      local_res18[0] = *(longlong *)(lVar1 + 0x18);
    }
    if (local_res18[0] != 0) {
      iVar2 = HumGetDescriptorRequest
                        (param_1,0xb,0x23,local_res18,local_res10,
                         CONCAT44(in_stack_ffffffffffffffe4,in_stack_ffffffffffffffe0),0,0);
      return iVar2;
    }
  }
  return -0x3fffff18;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14000e8dc =====

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



===== HumGetStringDescriptor @ 14000e9b0 =====

int HumGetStringDescriptor(ulonglong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  char *pcVar7;
  int iVar8;
  void *_Dst;
  uint uVar9;
  uint uVar10;
  ulonglong _Size;
  uint local_res8 [2];
  char *local_res10;
  ulonglong in_stack_ffffffffffffffa8;
  undefined4 in_stack_ffffffffffffffb0;
  undefined4 in_stack_ffffffffffffffb4;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(int *)(lVar3 + 0x18) == 0xb0013) {
    _Dst = *(void **)(param_2 + 0x70);
    bVar6 = false;
  }
  else {
    if (*(int *)(lVar3 + 0x18) != 0xb01e2) {
      return -0x3fffff18;
    }
    lVar5 = *(longlong *)(param_2 + 8);
    if (lVar5 == 0) {
      return -0x3fffff18;
    }
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      in_stack_ffffffffffffffb0 = 0x40000010;
      _Dst = (void *)MmMapLockedPagesSpecifyCache
                               (lVar5,0,1,0,in_stack_ffffffffffffffa8 & 0xffffffff00000000);
    }
    else {
      _Dst = *(void **)(lVar5 + 0x18);
    }
    bVar6 = true;
  }
  if (_Dst == (void *)0x0) {
    return -0x3fffff18;
  }
  uVar2 = *(uint *)(lVar3 + 8);
  if (uVar2 < 2) {
    return -0x3fffff18;
  }
  uVar9 = *(uint *)(lVar3 + 0x20);
  uVar10 = uVar9 & 0xffff;
  if (bVar6) {
LAB_14000ea60:
    local_res8[0] = uVar2 + 2;
    local_res10 = (char *)ExAllocatePool2(0x40,local_res8[0],0x55646948);
    if (local_res10 == (char *)0x0) {
      iVar8 = -0x3fffff66;
    }
    else {
      iVar8 = HumGetDescriptorRequest
                        (param_1,0xb,3,(longlong *)&local_res10,local_res8,
                         CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),(char)uVar10,
                         (short)(uVar9 >> 0x10));
      pcVar7 = local_res10;
      if (-1 < iVar8) {
        uVar9 = (int)*local_res10 - 2U;
        if (local_res8[0] < (int)*local_res10 - 2U) {
          uVar9 = local_res8[0];
        }
        _Size = (ulonglong)uVar9 & 0xfffffffe;
        if ((ulonglong)uVar2 - 2 < _Size) {
          iVar8 = -0x3ffffdfa;
        }
        else {
          memmove(_Dst,local_res10 + 2,_Size);
          *(undefined2 *)(_Size + (longlong)_Dst) = 0;
          *(ulonglong *)(param_2 + 0x38) = _Size + 2;
        }
      }
      ExFreePool(pcVar7);
    }
  }
  else {
    if (uVar10 == 0xf) {
      bVar1 = *(byte *)(*(longlong *)(lVar4 + 8) + 0xf);
joined_r0x00014000ebad:
      uVar10 = (uint)bVar1;
      if (uVar10 != 0) goto LAB_14000ea60;
    }
    else {
      if (uVar10 == 0xe) {
        bVar1 = *(byte *)(*(longlong *)(lVar4 + 8) + 0xe);
        goto joined_r0x00014000ebad;
      }
      if (uVar10 == 0x10) {
        uVar10 = (uint)*(byte *)(*(longlong *)(lVar4 + 8) + 0x10);
        if (uVar10 == 0) {
          return -0x3ffffff3;
        }
        goto LAB_14000ea60;
      }
    }
    iVar8 = -0x3ffffff3;
  }
  return iVar8;
}



===== HumAbortPendingRequests @ 14000ebf0 =====

int HumAbortPendingRequests(ulonglong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined2 uVar5;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x55646948);
  if (puVar3 == (undefined4 *)0x0) {
    return -0x3fffff66;
  }
  lVar1 = *(longlong *)(lVar1 + 0x10);
  if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) == 0)) {
    iVar2 = -0x3ffffff2;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000ec5d;
    uVar5 = 0x17;
    bVar4 = 2;
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0x20);
    if (lVar1 == 0) {
      iVar2 = -0x3ffffff2;
      goto LAB_14000ec5d;
    }
    *puVar3 = 0x20028;
    *(longlong *)(puVar3 + 6) = lVar1;
    iVar2 = HumCallUSB(param_1,puVar3);
    if ((-1 < iVar2) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14000ec5d;
    uVar5 = 0x16;
    bVar4 = 3;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar4,4,uVar5,
                    &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,(char)iVar2);
LAB_14000ec5d:
  ExFreePool(puVar3);
  return iVar2;
}



===== WppInitKm @ 14000ed10 =====

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



===== HumGetReportDescriptor @ 14000edf0 =====

int HumGetReportDescriptor(ulonglong param_1,longlong param_2,undefined1 *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  short sVar9;
  undefined4 uVar10;
  uint local_res8 [2];
  void *local_res10;
  undefined8 in_stack_ffffffffffffffc0;
  
  uVar10 = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res10 = (void *)0x0;
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  local_res8[0] = *(ushort *)(lVar3 + 0x57) + 0x40;
  if ((*(uint *)(lVar3 + 0x40) & 1) == 0) {
    sVar9 = 0x28;
    bVar4 = *(byte *)(*(longlong *)(lVar3 + 0x10) + 2);
  }
  else {
    uVar10 = 0;
    lVar6 = GetInterruptInputPipeForDevice(lVar3);
    if (lVar6 == 0) {
      iVar5 = -0x3ffffe7e;
      goto LAB_14000eedb;
    }
    sVar9 = (short)uVar10 + 0x24;
    bVar4 = *(byte *)(lVar6 + 2) & 0x7f;
  }
  iVar5 = HumGetDescriptorRequest
                    (param_1,sVar9,*(undefined1 *)(lVar3 + 0x56),(longlong *)&local_res10,local_res8
                     ,in_stack_ffffffffffffffc0,(char)uVar10,(ushort)bVar4);
  if (-1 < iVar5) {
    uVar1 = *(uint *)(lVar2 + 8);
    uVar8 = (uint)*(ushort *)(lVar3 + 0x57);
    if (uVar1 <= *(ushort *)(lVar3 + 0x57)) {
      uVar8 = uVar1;
    }
    if (local_res8[0] < uVar8) {
      uVar8 = local_res8[0];
    }
    memmove(*(void **)(param_2 + 0x70),local_res10,(ulonglong)uVar8);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
    ExFreePool(local_res10);
    return iVar5;
  }
  if (iVar5 == -0x3fffff63) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff63;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xb,
                       &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)param_2,0x9d);
    return -0x3fffff63;
  }
LAB_14000eedb:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,10,
                       &WPP_b40a5588456f3c2c427887b931342e5d_Traceguids,(char)param_2,(char)iVar5);
  }
  *(int *)(param_2 + 0x30) = iVar5;
  uVar7 = HumQueueResetWorkItem(param_1,param_2);
  if ((int)uVar7 == -0x3fffffea) {
    *param_3 = 0;
    IoReleaseRemoveLockEx(lVar3 + 0x68,param_2,0x20);
    return 0x103;
  }
  return iVar5;
}



===== HumSystemControl @ 14000efc0 =====

void HumSystemControl(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
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
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8));
  return;
}



===== HumGetHidDescriptor @ 14000f010 =====

undefined8 HumGetHidDescriptor(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  bVar1 = *(byte *)(lVar3 + 0x50);
  if (bVar1 == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    return 0xc0000001;
  }
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (bVar1 < uVar2) {
    uVar2 = (uint)bVar1;
  }
  memmove(*(void **)(param_2 + 0x70),(void *)(lVar3 + 0x50),(ulonglong)uVar2);
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
  return 0;
}



===== WppLoadTracingSupport @ 14000f080 =====

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



===== WppCleanupKm @ 14000f1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== _tlgEnableCallback @ 14000f290 =====

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



===== HumGetDeviceAttributes @ 14000f320 =====

undefined8 HumGetDeviceAttributes(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  puVar1 = *(undefined4 **)(param_2 + 0x70);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x20) {
    return 0xc0000206;
  }
  *(undefined8 *)(param_2 + 0x38) = 0x20;
  *puVar1 = 0x20;
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(*(longlong *)(lVar2 + 8) + 8);
  *(undefined2 *)((longlong)puVar1 + 6) = *(undefined2 *)(*(longlong *)(lVar2 + 8) + 10);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(*(longlong *)(lVar2 + 8) + 0xc);
  return 0;
}



===== HumPnP @ 14000f380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint HumPnP(ulonglong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  undefined8 *puVar5;
  int *piVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  longlong lVar11;
  code *pcVar12;
  undefined8 *puVar13;
  longlong lVar14;
  undefined1 auStackY_118 [32];
  undefined1 uVar15;
  uint local_d8 [2];
  longlong local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined *local_98;
  uint local_90;
  undefined4 local_8c;
  undefined *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,10,
                     &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids);
  }
  lVar14 = *(longlong *)(param_2 + 0xb8);
  piVar4 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
  local_d0 = lVar14;
  uVar8 = IoAcquireRemoveLockEx(piVar4 + 0x1a,param_2,"",1);
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xb,
                        &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,(char)uVar8);
    }
    *(uint *)(param_2 + 0x30) = uVar8;
    IofCompleteRequest(param_2,0);
    return uVar8;
  }
  cVar2 = *(char *)(lVar14 + 1);
  uVar15 = (undefined1)param_1;
  if (cVar2 == '\0') {
    piVar6 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
    iVar9 = *piVar6;
    *piVar6 = 1;
    KeResetEvent(piVar6 + 10);
    if ((iVar9 - 3U < 3) &&
       (HumIncrementPendingRequestCount(piVar6),
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    piVar6[4] = 0;
    piVar6[5] = 0;
    lVar14 = local_d0;
  }
  else {
    if (cVar2 == '\x02') {
      piVar4 = *(int **)(*(longlong *)(param_1 + 0x40) + 0x10);
      iVar9 = *piVar4;
      *piVar4 = 5;
      if (1 < iVar9 - 3U) {
        HumDecrementPendingRequestCount((longlong)piVar4);
      }
      HumCompleteDeviceResetNotificationIrp(param_1,0xc000000e);
      if (iVar9 == 2) {
        HumAbortPendingRequests(param_1);
      }
      KeWaitForSingleObject(piVar4 + 10,0,0,0);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      *(undefined4 *)(param_2 + 0x30) = 0;
      uVar8 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
      IoReleaseRemoveLockAndWaitEx(piVar4 + 0x1a,param_2,0x20);
      if (*(longlong *)(piVar4 + 4) != 0) {
        ExFreePool();
        piVar4[4] = 0;
        piVar4[5] = 0;
      }
      if (*(longlong *)(piVar4 + 2) != 0) {
        ExFreePool();
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
      return uVar8;
    }
    if (cVar2 == '\x04') {
      if (*piVar4 == 2) {
        puVar10 = *(undefined4 **)(*(longlong *)(param_1 + 0x40) + 0x10);
        *puVar10 = 3;
        HumAbortPendingRequests(param_1);
        HumDecrementPendingRequestCount((longlong)puVar10);
        KeWaitForSingleObject(puVar10 + 10,0,0,0);
        puVar10 = (undefined4 *)ExAllocatePool2(0x40,0x58,0x55646948);
        if (puVar10 == (undefined4 *)0x0) {
          iVar9 = -0x3fffffff;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x15,
                               &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,uVar15,1);
            goto LAB_14000f5ed;
          }
        }
        else {
          *puVar10 = 0x58;
          *(undefined8 *)(puVar10 + 6) = 0;
          iVar9 = HumCallUSB(param_1,puVar10);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x14,
                               &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,uVar15,(char)iVar9);
          }
          ExFreePool(puVar10);
          if (iVar9 < 0) {
LAB_14000f5ed:
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0xc,
                                 &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,uVar15,(char)iVar9
                                );
            }
          }
        }
      }
    }
    else if ((cVar2 == '\x14') && (*piVar4 == 6)) {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 4;
    }
  }
  KeInitializeEvent(&local_b8,0,0);
  puVar5 = *(undefined8 **)(param_2 + 0xb8);
  puVar13 = &local_b8;
  pcVar12 = HumPnpCompletion;
  puVar5[-9] = *puVar5;
  puVar5[-8] = puVar5[1];
  puVar5[-7] = puVar5[2];
  puVar5[-6] = puVar5[3];
  *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
  *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
  *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
  *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
  puVar5[-3] = puVar5[6];
  *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
  uVar8 = IoSetCompletionRoutineEx(param_1,param_2);
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xd,
                        &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,(char)uVar8);
    }
  }
  else {
    lVar11 = param_2;
    iVar9 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8));
    if (iVar9 == 0x103) {
      puVar13 = (undefined8 *)0x0;
      pcVar12 = (code *)0x0;
      lVar11 = 0;
      KeWaitForSingleObject(&local_b8);
    }
    cVar2 = *(char *)(lVar14 + 1);
    uVar8 = *(uint *)(param_2 + 0x30);
    if (cVar2 == '\0') {
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0xf,
                             &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,uVar15,(char)uVar8);
        }
        *piVar4 = 6;
        if (DAT_14000b000 < 6) goto LAB_14000fb66;
        if (((_DAT_14000b010 & 0x200000000000) == 0) ||
           ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if (!bVar7) goto LAB_14000fb66;
        local_78 = (uint *)&local_d0;
        local_d0 = CONCAT44(local_d0._4_4_,uVar8);
        local_58 = "PNP_DeviceStart";
        local_50 = 0x10;
        uVar3 = *(ushort *)PTR_DAT_14000b008;
        local_d8[0] = 0xea;
      }
      else {
        *piVar4 = 2;
        uVar8 = HumInitDevice(param_1,lVar11,(uint *)pcVar12,puVar13);
        if (-1 < (int)uVar8) goto LAB_14000fb66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0xe,
                            &WPP_3c55f616c7bd3da2f3db13575d3d7204_Traceguids,uVar15);
        }
        *piVar4 = 6;
        if (DAT_14000b000 < 6) goto LAB_14000fb66;
        if (((_DAT_14000b010 & 0x200000000000) == 0) ||
           ((DAT_14000b018 & 0x200000000000) != DAT_14000b018)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if (!bVar7) goto LAB_14000fb66;
        local_78 = local_d8;
        local_58 = "PNP_HumInitDevice";
        local_50 = 0x12;
        uVar3 = *(ushort *)PTR_DAT_14000b008;
        local_d0 = CONCAT44(local_d0._4_4_,0xea);
        local_d8[0] = uVar8;
      }
      local_90 = (uint)uVar3;
      local_60 = 4;
      local_68 = local_d8 + 1;
      local_70 = 4;
      local_7c = 1;
      local_80 = 0x2b;
      local_88 = &DAT_140009652;
      local_8c = 2;
      local_c0 = 0x200000000000;
      local_c4 = 5;
      local_c8 = 0xb000000;
      local_d8[1] = 6;
      local_98 = PTR_DAT_14000b008;
      EtwWriteTransfer(DAT_14000b020,&local_c8,0,0);
    }
    else if (cVar2 == '\x04') {
      *piVar4 = 4;
      if (*(longlong *)(piVar4 + 4) != 0) {
        ExFreePool();
        piVar4[4] = 0;
        piVar4[5] = 0;
      }
      if (*(longlong *)(piVar4 + 2) != 0) {
        ExFreePool();
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
    }
    else if ((cVar2 == '\t') && (-1 < (int)uVar8)) {
      puVar1 = (uint *)(*(longlong *)(lVar14 + 8) + 4);
      *puVar1 = *puVar1 | 0x200;
    }
  }
LAB_14000fb66:
  *(uint *)(param_2 + 0x30) = uVar8;
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(piVar4 + 0x1a,param_2,0x20);
  return uVar8;
}



===== entry @ 140010010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
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



===== wil_InitializeFeatureStaging @ 140010078 =====

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
    ppuVar4 = &wil_details_featureDescriptors_a;
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
          g_wil_details_featureChangeNotification = 0;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140010168 =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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


