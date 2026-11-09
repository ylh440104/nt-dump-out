
===== USBD_ParseConfigurationDescriptorEx @ 180001010 =====

byte * USBD_ParseConfigurationDescriptorEx
                 (longlong param_1,byte *param_2,uint param_3,uint param_4,uint param_5,uint param_6
                 ,uint param_7)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined2 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
                    /* 0x1010  14  USBD_ParseConfigurationDescriptorEx */
  pbVar2 = (byte *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
  }
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,(char)param_2);
    }
    pbVar2 = (byte *)0x0;
  }
  else {
    pbVar5 = (byte *)((ulonglong)*(ushort *)(param_1 + 2) + param_1);
    do {
      pbVar6 = (byte *)0x0;
      if (param_2 == (byte *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,0);
        }
        break;
      }
      pbVar3 = (byte *)((ulonglong)*(ushort *)(param_1 + 2) + param_1);
      while( true ) {
        if ((pbVar3 <= param_2) || ((ulonglong)((longlong)pbVar3 - (longlong)param_2) < 2))
        goto LAB_1800010f2;
        if (param_2[1] == 4) {
          pbVar6 = param_2;
          goto LAB_1800010f2;
        }
        if (*param_2 == 0) break;
        if (param_2 + *param_2 < param_2) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180001117;
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
            uVar4 = 0xe;
            goto LAB_1800012e4;
          }
          goto LAB_1800010f2;
        }
        param_2 = param_2 + *param_2;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180001117;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar4 = 0xd;
LAB_1800012e4:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                 &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_2);
      }
LAB_1800010f2:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,pbVar6);
      }
LAB_180001117:
      if (pbVar6 == (byte *)0x0) break;
      pbVar2 = pbVar6;
      if ((param_3 != 0xffffffff) &&
         ((((pbVar5 < pbVar6 || (0xffff < (longlong)pbVar5 - (longlong)pbVar6)) ||
           ((ulonglong)((longlong)pbVar5 - (longlong)pbVar6) < 3)) || (pbVar6[2] != param_3)))) {
        pbVar2 = (byte *)0x0;
      }
      if ((param_4 != 0xffffffff) &&
         (((pbVar5 < pbVar6 || (0xffff < (longlong)pbVar5 - (longlong)pbVar6)) ||
          (((ulonglong)((longlong)pbVar5 - (longlong)pbVar6) < 4 || (pbVar6[3] != param_4)))))) {
        pbVar2 = (byte *)0x0;
      }
      if ((param_5 != 0xffffffff) &&
         (((pbVar5 < pbVar6 || (0xffff < (longlong)pbVar5 - (longlong)pbVar6)) ||
          (((ulonglong)((longlong)pbVar5 - (longlong)pbVar6) < 6 || (pbVar6[5] != param_5)))))) {
        pbVar2 = (byte *)0x0;
      }
      if ((param_6 != 0xffffffff) &&
         ((((pbVar5 < pbVar6 || (0xffff < (longlong)pbVar5 - (longlong)pbVar6)) ||
           ((ulonglong)((longlong)pbVar5 - (longlong)pbVar6) < 7)) || (pbVar6[6] != param_6)))) {
        pbVar2 = (byte *)0x0;
      }
      if ((param_7 == 0xffffffff) ||
         (((pbVar6 <= pbVar5 && ((longlong)pbVar5 - (longlong)pbVar6 < 0x10000)) &&
          ((7 < (ulonglong)((longlong)pbVar5 - (longlong)pbVar6) && (pbVar6[7] == param_7)))))) {
        bVar1 = *pbVar6;
        if (pbVar2 != (byte *)0x0) break;
      }
      else {
        bVar1 = *pbVar6;
        pbVar2 = (byte *)0x0;
      }
      param_2 = pbVar6 + bVar1;
    } while (bVar1 != 0);
  }
  return pbVar2;
}



===== USBD_ParseDescriptors @ 180001390 =====

byte * USBD_ParseDescriptors(longlong param_1,uint param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte *pbVar3;
  
                    /* 0x1390  16  USBD_ParseDescriptors */
  pbVar1 = (byte *)0x0;
  if ((param_1 == 0) || (param_3 == (byte *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,(char)param_3);
    }
    pbVar1 = (byte *)0x0;
  }
  else {
    while( true ) {
      pbVar3 = pbVar1;
      if ((((byte *)((ulonglong)param_2 + param_1) <= param_3) ||
          ((ulonglong)((longlong)((ulonglong)param_2 + param_1) - (longlong)param_3) < 2)) ||
         (pbVar3 = param_3, param_3[1] == param_4)) goto LAB_18000140f;
      if (*param_3 == 0) break;
      if (param_3 + *param_3 < param_3) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180001426;
        pbVar3 = pbVar1;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar2 = 0xe;
          goto LAB_180001468;
        }
        goto LAB_18000140f;
      }
      param_3 = param_3 + *param_3;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_180001426;
    pbVar3 = pbVar1;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar2 = 0xd;
LAB_180001468:
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_3);
      pbVar3 = pbVar1;
    }
LAB_18000140f:
    pbVar1 = pbVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,pbVar3);
    }
  }
LAB_180001426:
  return pbVar1;
}



===== USBD_AddDeviceToGlobalList @ 1800014d0 =====

undefined8
USBD_AddDeviceToGlobalList
          (undefined8 param_1,longlong param_2,short param_3,longlong param_4,short param_5,
          short param_6,longlong param_7)

{
  code *pcVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  void *_Dst;
  undefined8 uVar5;
  
                    /* 0x14d0  3  USBD_AddDeviceToGlobalList */
  uVar2 = KeAcquireSpinLockRaiseToDpc(&GlobalChildListLock);
  puVar4 = GlobalChildListHead;
  if ((undefined8 **)GlobalChildListHead != &GlobalChildListHead) {
    for (; (undefined8 **)puVar4 != &GlobalChildListHead; puVar4 = (undefined8 *)*puVar4) {
      if ((((*(short *)(puVar4 + 6) == param_5) && (*(short *)((longlong)puVar4 + 0x32) == param_6))
          && (*(int *)((longlong)puVar4 + 0x3c) == *(int *)(param_7 + 4))) &&
         (uVar3 = RtlCompareMemory(puVar4[8],*(undefined8 *)(param_7 + 8),*(int *)(param_7 + 4)),
         uVar3 == *(uint *)(param_7 + 4))) {
        if (*(int *)((longlong)puVar4 + 0x34) == 2) {
          if ((((param_3 == *(short *)(puVar4 + 4)) && (param_2 != 0)) && (param_2 == puVar4[3])) ||
             ((param_4 != 0 && (param_4 == puVar4[5])))) break;
        }
        else if ((param_4 == 0) || (param_4 != puVar4[5])) {
          uVar5 = 3;
          goto LAB_18000167a;
        }
        uVar5 = 2;
        goto LAB_18000167a;
      }
    }
  }
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x44425355);
  if (puVar4 != (undefined8 *)0x0) {
    _Dst = (void *)ExAllocatePool2(0x40,*(undefined4 *)(param_7 + 4),0x44425355);
    puVar4[8] = _Dst;
    if (_Dst != (void *)0x0) {
      memmove(_Dst,*(void **)(param_7 + 8),(ulonglong)*(uint *)(param_7 + 4));
      *(undefined4 *)((longlong)puVar4 + 0x3c) = *(undefined4 *)(param_7 + 4);
      puVar4[2] = param_1;
      puVar4[3] = param_2;
      *(short *)(puVar4 + 4) = param_3;
      puVar4[5] = param_4;
      *(short *)(puVar4 + 6) = param_5;
      *(short *)((longlong)puVar4 + 0x32) = param_6;
      *(undefined4 *)((longlong)puVar4 + 0x34) = 1;
      if ((undefined8 **)*DAT_180007268 != &GlobalChildListHead) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        pcVar1 = (code *)swi(3);
        uVar5 = (*pcVar1)();
        return uVar5;
      }
      *puVar4 = &GlobalChildListHead;
      puVar4[1] = DAT_180007268;
      *DAT_180007268 = puVar4;
      uVar5 = 1;
      DAT_180007268 = puVar4;
      goto LAB_18000167a;
    }
    ExFreePoolWithTag(puVar4,0x44425355);
  }
  uVar5 = 4;
LAB_18000167a:
  KeReleaseSpinLock(&GlobalChildListLock,uVar2);
  return uVar5;
}



===== USBD_CreateConfigurationRequestEx @ 1800016f0 =====

ushort * USBD_CreateConfigurationRequestEx(ulonglong param_1,ulonglong *param_2)

{
  byte bVar1;
  ulonglong uVar2;
  ushort *puVar3;
  ulonglong uVar4;
  ushort *puVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort *puVar10;
  
                    /* 0x16f0  7  USBD_CreateConfigurationRequestEx */
  if ((param_1 == 0) || (param_2 == (ulonglong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,(char)param_2);
    }
LAB_1800018e6:
    puVar3 = (ushort *)0x0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_2);
    }
    uVar7 = *(ushort *)(param_1 + 2) + param_1;
    uVar8 = 0x28;
    for (puVar6 = param_2; *puVar6 != 0; puVar6 = puVar6 + 2) {
      uVar9 = (*(byte *)(*puVar6 + 4) + 1) * 0x18;
      if ((int)(0xffff - (uint)uVar9) < (int)(uint)uVar8) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                  &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
        }
        goto LAB_1800018e6;
      }
      uVar8 = uVar8 + uVar9;
    }
    puVar3 = (ushort *)ExAllocatePool2(0x40,(ulonglong)uVar8,0x44425355);
    if (puVar3 != (ushort *)0x0) {
      puVar10 = puVar3 + 0x14;
      while (uVar2 = *param_2, uVar2 != 0) {
        if (((param_1 < uVar2) && (uVar2 <= uVar7)) &&
           ((uVar4 = uVar7 - uVar2, 0xffff < (longlong)uVar4 || (uVar4 < 5)))) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                    &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
          }
LAB_180001915:
          ExFreePoolWithTag(puVar3,0x44425355);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                    &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
          }
          puVar3 = (ushort *)0x0;
          goto LAB_180001784;
        }
        bVar1 = *(byte *)(uVar2 + 4);
        uVar4 = (ulonglong)(uint)bVar1;
        if ((ushort *)((longlong)puVar3 + (ulonglong)uVar8) < puVar10 + ((ulonglong)bVar1 + 1) * 0xc
           ) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                     &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,uVar2);
          }
          goto LAB_180001915;
        }
        *(undefined1 *)(puVar10 + 1) = *(undefined1 *)(uVar2 + 2);
        *(undefined1 *)((longlong)puVar10 + 3) = *(undefined1 *)(uVar2 + 3);
        *(uint *)(puVar10 + 8) = (uint)bVar1;
        if (bVar1 != 0) {
          puVar5 = puVar10 + 0x16;
          do {
            puVar5[-2] = 0xffff;
            puVar5[-1] = 0xffff;
            puVar5[0] = 0;
            puVar5[1] = 0;
            puVar5 = puVar5 + 0xc;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        *puVar10 = (bVar1 + 1) * 0x18;
        param_2[1] = (ulonglong)puVar10;
        param_2 = param_2 + 2;
        puVar10 = (ushort *)((longlong)puVar10 + (ulonglong)*puVar10);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                   &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,puVar10);
        }
      }
      *puVar3 = uVar8;
      puVar3[1] = 0;
      *(ulonglong *)(puVar3 + 0xc) = param_1;
    }
  }
LAB_180001784:
  return puVar3;
}



===== USBD_RemoveDeviceFromGlobalList @ 180001a20 =====

void USBD_RemoveDeviceFromGlobalList(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  
                    /* 0x1a20  21  USBD_RemoveDeviceFromGlobalList */
  uVar4 = KeAcquireSpinLockRaiseToDpc(&GlobalChildListLock);
  puVar5 = GlobalChildListHead;
  do {
    if ((undefined8 **)puVar5 == &GlobalChildListHead) {
LAB_180001aa8:
      KeReleaseSpinLock(&GlobalChildListLock,uVar4);
      return;
    }
    puVar1 = (undefined8 *)*puVar5;
    if (puVar5[2] == param_1) {
      if (((undefined8 *)puVar1[1] != puVar5) ||
         (puVar2 = (undefined8 *)puVar5[1], (undefined8 *)*puVar2 != puVar5)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      ExFreePoolWithTag(puVar5[8],0x44425355);
      ExFreePoolWithTag(puVar5,0x44425355);
      goto LAB_180001aa8;
    }
    puVar5 = puVar1;
  } while( true );
}



===== USBD_MarkDeviceAsDisconnected @ 180001ae0 =====

void USBD_MarkDeviceAsDisconnected(longlong param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  
                    /* 0x1ae0  12  USBD_MarkDeviceAsDisconnected */
  uVar1 = KeAcquireSpinLockRaiseToDpc(&GlobalChildListLock);
  puVar2 = GlobalChildListHead;
  do {
    if ((undefined8 **)puVar2 == &GlobalChildListHead) {
LAB_180001b21:
      KeReleaseSpinLock(&GlobalChildListLock,uVar1);
      return;
    }
    if (puVar2[2] == param_1) {
      *(undefined4 *)((longlong)puVar2 + 0x34) = 2;
      goto LAB_180001b21;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== USBD_ReleaseHubNumber @ 180001b50 =====

void USBD_ReleaseHubNumber(undefined4 param_1)

{
                    /* 0x1b50  20  USBD_ReleaseHubNumber */
  if (GlobalHubNumbersBitmap != 0) {
    KeWaitForSingleObject(&GlobalHubNumbersLock,0,0,0,0);
    RtlClearBits(GlobalHubNumbersBitmap,param_1,1);
    KeSetEvent(&GlobalHubNumbersLock,0,0);
  }
  return;
}



===== USBD_AllocateHubNumber @ 180001bd0 =====

int USBD_AllocateHubNumber(void)

{
  int iVar1;
  
                    /* 0x1bd0  4  USBD_AllocateHubNumber */
  if (GlobalHubNumbersBitmap == 0) {
    return 0;
  }
  KeWaitForSingleObject(&GlobalHubNumbersLock,0,0,0,0);
  iVar1 = RtlFindClearBitsAndSet(GlobalHubNumbersBitmap,1,0);
  KeSetEvent(&GlobalHubNumbersLock,0,0);
  if (iVar1 == -1) {
    iVar1 = 0;
  }
  return iVar1;
}



===== DllInitializeWorker @ 180001c60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitializeWorker(void)

{
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  _DAT_1800072c8 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1800072a8 = &WPP_ThisDir_CTLGUID_UsbdTraceGuid;
  DAT_1800072b0 = 0;
  _DAT_1800072c0 = 0;
  WppLoadTracingSupport();
  _DAT_1800072c0 = 0;
  WppInitKm();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
  }
  memset(local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  DAT_180007268 = &GlobalChildListHead;
  GlobalChildListHead = &GlobalChildListHead;
  KeInitializeSpinLock(&GlobalChildListLock);
  KeInitializeEvent(&GlobalHubNumbersLock,1,1);
  GlobalHubNumbersBitmap = ExAllocatePool2(0x100,0x30,0x44425355);
  if (GlobalHubNumbersBitmap != 0) {
    RtlInitializeBitMap(GlobalHubNumbersBitmap,GlobalHubNumbersBitmap + 0x10,0x100);
    RtlSetBits(GlobalHubNumbersBitmap,0,1);
  }
  ShimLoad();
  return 0;
}



===== DllInitialize @ 180001de0 =====

void DllInitialize(void)

{
                    /* 0x1de0  1  DllInitialize */
  __security_init_cookie();
  DllInitializeWorker();
  return;
}



===== __report_gsfailure @ 180001e10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DllUnload @ 180001e20 =====

undefined8 DllUnload(void)

{
                    /* 0x1e20  2  DllUnload */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
  }
  ShimUnload();
  if (GlobalHubNumbersBitmap != 0) {
    ExFreePoolWithTag(GlobalHubNumbersBitmap,0x44425355);
  }
  WppCleanupKm();
  return 0;
}



===== DriverEntry @ 180001e88 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== USBD_CalculateUsbBandwidth @ 180001ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint USBD_CalculateUsbBandwidth(int param_1,byte param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  int local_28 [10];
  
                    /* 0x1ea0  5  USBD_CalculateUsbBandwidth */
  local_28[0] = 0;
  local_28[2] = 0;
  local_28[1] = 9;
  local_28[3] = 0xd;
  if (param_2 < 4) {
    uVar2 = -(uint)(local_28[param_2] != 0) & (uint)((local_28[param_2] + param_1) * 0x38) / 6;
    uVar1 = uVar2 * 8;
    if (param_3 == '\0') {
      uVar1 = uVar2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== USBD_CreateConfigurationRequest @ 180001f20 =====

ushort * USBD_CreateConfigurationRequest(ulonglong param_1,ushort *param_2)

{
  byte bVar1;
  ulonglong *puVar2;
  byte *pbVar3;
  ushort *puVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong *puVar7;
  
                    /* 0x1f20  6  USBD_CreateConfigurationRequest */
  uVar5 = 0;
  puVar4 = (ushort *)0x0;
  if (param_1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1);
    }
    bVar1 = *(byte *)(param_1 + 4);
    puVar2 = (ulonglong *)ExAllocatePool2(0x100,(ulonglong)(bVar1 + 1) << 4,0x44425355);
    if (puVar2 != (ulonglong *)0x0) {
      puVar7 = puVar2;
      for (uVar6 = 0; (int)uVar6 < (int)(uint)bVar1; uVar6 = uVar6 + 1) {
        pbVar3 = USBD_ParseConfigurationDescriptorEx
                           (param_1,(byte *)param_1,uVar6,0,0xffffffff,0xffffffff,0xffffffff);
        if (pbVar3 == (byte *)0x0) goto LAB_18000202b;
        *puVar7 = (ulonglong)pbVar3;
        puVar7 = puVar7 + 2;
      }
      *puVar7 = 0;
      puVar4 = USBD_CreateConfigurationRequestEx(param_1,puVar2);
LAB_18000202b:
      ExFreePool(puVar2);
      if (puVar4 != (ushort *)0x0) {
        uVar5 = *puVar4;
      }
      *param_2 = uVar5;
      return puVar4;
    }
  }
  return (ushort *)0x0;
}



===== USBD_GetInterfaceLength @ 180002070 =====

void USBD_GetInterfaceLength(byte *param_1,byte *param_2)

{
                    /* 0x2070  8  USBD_GetInterfaceLength */
  USBD_InternalGetInterfaceLength(param_1,param_2);
  return;
}



===== USBD_GetPdoRegistryParameter @ 180002090 =====

int USBD_GetPdoRegistryParameter
              (undefined8 param_1,void *param_2,uint param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  undefined8 local_18 [2];
  
                    /* 0x2090  9  USBD_GetPdoRegistryParameter */
  local_18[0] = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_1,2,0x1f0000,local_18);
  if (-1 < iVar1) {
    iVar1 = USBD_GetRegistryKeyValue(local_18[0],param_4,param_5,param_2,param_3);
    ZwClose(local_18[0]);
  }
  return iVar1;
}



===== USBD_GetRegistryKeyValue @ 180002120 =====

int USBD_GetRegistryKeyValue
              (undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint local_res18 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  
                    /* 0x2120  10  USBD_GetRegistryKeyValue */
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  uVar3 = param_3 + 0x18;
  if ((uVar3 < 0x18) || (local_res18[0] = uVar3 + param_5, local_res18[0] < uVar3)) {
    return -0x3fffff6b;
  }
  lVar2 = ExAllocatePool2(0x100,local_res18[0],0x44425355);
  iVar1 = 0;
  if (lVar2 != 0) {
    iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res18[0],local_res18);
    if (-1 < iVar1) {
      memmove(param_4,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),(ulonglong)param_5);
    }
    ExFreePool(lVar2);
  }
  return iVar1;
}



===== USBD_GetUSBDIVersion @ 180002210 =====

void USBD_GetUSBDIVersion(undefined4 *param_1)

{
                    /* 0x2210  11  USBD_GetUSBDIVersion */
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0x600;
    param_1[1] = 0x100;
  }
  return;
}



===== USBD_InternalGetInterfaceLength @ 18000222c =====

ulonglong USBD_InternalGetInterfaceLength(byte *param_1,byte *param_2)

{
  byte bVar1;
  ulonglong uVar2;
  byte *pbVar3;
  undefined2 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (param_1 == (byte *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = (ulonglong)*param_1;
    pbVar3 = param_1 + uVar2;
    for (uVar5 = (uint)param_1[4]; uVar5 != 0; uVar5 = uVar5 - 1) {
      if ((param_2 < pbVar3) ||
         (pbVar6 = pbVar3, (ulonglong)((longlong)param_2 - (longlong)pbVar3) < 2)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_18000238f;
        uVar4 = 0x2c;
        goto LAB_18000237f;
      }
      while( true ) {
        uVar2 = (ulonglong)((int)uVar2 + (uint)*pbVar6);
        pbVar3 = pbVar6 + *pbVar6;
        if (pbVar6[1] == 5) break;
        if (((param_2 <= pbVar3) || ((ulonglong)((longlong)param_2 - (longlong)pbVar3) < 2)) ||
           (pbVar6 = pbVar3, *pbVar3 == 0)) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_18000238f;
          uVar4 = 0x2d;
          goto LAB_18000237f;
        }
      }
    }
    while( true ) {
      if (param_2 <= pbVar3) goto LAB_180002391;
      if ((ulonglong)((longlong)param_2 - (longlong)pbVar3) < 2) break;
      if (pbVar3[1] == 4) goto LAB_180002391;
      bVar1 = *pbVar3;
      if (bVar1 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                   &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,pbVar3);
        }
        goto LAB_18000238f;
      }
      uVar2 = (ulonglong)((int)uVar2 + (uint)bVar1);
      pbVar3 = pbVar3 + bVar1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar4 = 0x2e;
LAB_18000237f:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
              &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
    }
LAB_18000238f:
    uVar2 = 0;
LAB_180002391:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,(int)uVar2);
    }
  }
  return uVar2;
}



===== USBD_ParseConfigurationDescriptor @ 1800023e0 =====

void USBD_ParseConfigurationDescriptor(longlong param_1,byte param_2,byte param_3)

{
                    /* 0x23e0  13  USBD_ParseConfigurationDescriptor */
  USBD_ParseConfigurationDescriptorEx
            (param_1,(byte *)param_1,(uint)param_2,(uint)param_3,0xffffffff,0xffffffff,0xffffffff);
  return;
}



===== USBD_ParseConfigurationDescriptorEx2 @ 180002410 =====

byte * USBD_ParseConfigurationDescriptorEx2
                 (byte *param_1,byte *param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 uint param_7)

{
  byte *pbVar1;
  undefined8 uVar2;
  byte *pbVar3;
  byte *local_res8;
  
                    /* 0x2410  15  USBD_ParseConfigurationDescriptorEx2 */
  local_res8 = (byte *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
  }
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,(char)param_2);
    }
  }
  else {
    pbVar1 = param_1 + *(ushort *)(param_1 + 2);
    if (pbVar1 < param_1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_1,
                  (char)*(ushort *)(param_1 + 2));
      }
    }
    else {
      while( true ) {
        uVar2 = USBD_ParseDescriptors2
                          (param_1,(ulonglong)*(ushort *)(param_1 + 2),param_2,4,&local_res8,
                           (longlong *)0x0);
        if ((int)uVar2 != 0) break;
        pbVar3 = local_res8;
        if ((param_3 != 0xffffffff) &&
           ((((pbVar1 < local_res8 || (0xffff < (longlong)pbVar1 - (longlong)local_res8)) ||
             ((ulonglong)((longlong)pbVar1 - (longlong)local_res8) < 3)) ||
            (local_res8[2] != param_3)))) {
          pbVar3 = (byte *)0x0;
        }
        if ((param_4 != 0xffffffff) &&
           (((pbVar1 < local_res8 || (0xffff < (longlong)pbVar1 - (longlong)local_res8)) ||
            (((ulonglong)((longlong)pbVar1 - (longlong)local_res8) < 4 || (local_res8[3] != param_4)
             ))))) {
          pbVar3 = (byte *)0x0;
        }
        if ((param_5 != 0xffffffff) &&
           (((pbVar1 < local_res8 || (0xffff < (longlong)pbVar1 - (longlong)local_res8)) ||
            (((ulonglong)((longlong)pbVar1 - (longlong)local_res8) < 6 || (local_res8[5] != param_5)
             ))))) {
          pbVar3 = (byte *)0x0;
        }
        if ((param_6 != 0xffffffff) &&
           ((((pbVar1 < local_res8 || (0xffff < (longlong)pbVar1 - (longlong)local_res8)) ||
             ((ulonglong)((longlong)pbVar1 - (longlong)local_res8) < 7)) ||
            (local_res8[6] != param_6)))) {
          pbVar3 = (byte *)0x0;
        }
        if ((param_7 != 0xffffffff) &&
           (((pbVar1 < local_res8 || (0xffff < (longlong)pbVar1 - (longlong)local_res8)) ||
            (((ulonglong)((longlong)pbVar1 - (longlong)local_res8) < 8 || (local_res8[7] != param_7)
             ))))) {
          pbVar3 = (byte *)0x0;
        }
        param_2 = local_res8 + *local_res8;
        if (pbVar3 != (byte *)0x0) {
          return pbVar3;
        }
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,param_2,(int)uVar2);
      }
    }
  }
  return (byte *)0x0;
}



===== USBD_ParseDescriptors2 @ 180002660 =====

undefined8
USBD_ParseDescriptors2
          (byte *param_1,longlong param_2,byte *param_3,byte param_4,undefined8 *param_5,
          longlong *param_6)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
                    /* 0x2660  17  USBD_ParseDescriptors2 */
  pbVar4 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qDqDqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2,
                  (char)param_3,param_4,(char)param_5,(char)param_6);
  }
  pbVar1 = param_1 + param_2;
  if (pbVar1 < param_1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    uVar2 = 0x13;
  }
  else {
    if ((((param_1 != (byte *)0x0) && (param_3 != (byte *)0x0)) && (param_1 <= param_3)) &&
       ((param_3 < pbVar1 && (pbVar5 = (byte *)0x0, param_5 != (undefined8 *)0x0)))) {
      while( true ) {
        pbVar3 = param_3;
        if ((ulonglong)((longlong)pbVar1 - (longlong)pbVar3) < 2) {
          *param_5 = pbVar5;
          if (param_6 != (longlong *)0x0) {
            *param_6 = (longlong)(pbVar3 + (2 - (longlong)param_1));
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                      &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,pbVar3,0x23);
          }
          return 0xc0000023;
        }
        if (*pbVar3 == 0) {
          *param_5 = pbVar3;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                      &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,pbVar3,4);
          }
          return 0xc0000004;
        }
        param_3 = pbVar3 + *pbVar3;
        if (param_3 < pbVar3) break;
        if (pbVar1 <= param_3) {
          *param_5 = pbVar3;
          if (param_6 != (longlong *)0x0) {
            *param_6 = (longlong)param_3 - (longlong)param_1;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc0000023;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return 0xc0000023;
          }
          WPP_SF_qDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,pbVar4,pbVar3,
                      *pbVar3,(char)((longlong)param_3 - (longlong)param_1));
          return 0xc0000023;
        }
        if (pbVar3[1] == param_4) {
          if (param_6 != (longlong *)0x0) {
            *param_6 = param_2;
          }
          *param_5 = pbVar3;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_Dqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pbVar1,pbVar4,(uint)param_4,
                       (char)pbVar3);
          }
          return 0;
        }
        pbVar5 = pbVar3;
      }
      *param_5 = pbVar3;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000004;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc0000004;
      }
      WPP_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pbVar1,pbVar4,pbVar3,*pbVar3);
      return 0xc0000004;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    uVar2 = 0x14;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,pbVar4,0xc000000d);
  return 0xc000000d;
}



===== USBD_QueryBusTime @ 1800028f0 =====

undefined8 USBD_QueryBusTime(void)

{
                    /* 0x28f0  18  USBD_QueryBusTime */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_17e88a309dff3c712c023f8b20db5674_Traceguids);
  }
  return 0xc00000bb;
}



===== _guard_check_icall @ 180002940 =====

void _guard_check_icall(void)

{
                    /* 0x2940  19  USBD_RegisterHcFilter */
  return;
}



===== USBD_ValidateConfigurationDescriptor @ 180002950 =====

int USBD_ValidateConfigurationDescriptor
              (ushort *param_1,uint param_2,ushort param_3,longlong *param_4,int param_5)

{
  int iVar1;
  
                    /* 0x2950  22  USBD_ValidateConfigurationDescriptor */
  if ((param_1 == (ushort *)0x0) || (param_4 == (longlong *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = USBD_ValidateConfigurationDescriptorInternal(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



===== USBD_ValidateConfigurationDescriptorInternal @ 180002980 =====

int USBD_ValidateConfigurationDescriptorInternal
              (ushort *param_1,uint param_2,ushort param_3,longlong *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte *pbVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  ulonglong uVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort local_48;
  
  local_48 = 0;
  iVar9 = 0x4e627355;
  if (param_5 != 0) {
    iVar9 = param_5;
  }
  bVar3 = true;
  iVar7 = 0;
  if (((param_1 == (ushort *)0x0) || (param_2 < 9)) || (param_4 == (longlong *)0x0)) {
    iVar7 = -0x3fffd000;
  }
  else {
    if ((byte)*param_1 < 9) {
      iVar7 = -0x3fefffff;
      puVar10 = param_1;
    }
    else if (*(char *)((longlong)param_1 + 1) == '\x02') {
      puVar10 = param_1 + 1;
      if ((param_2 < *puVar10) || (*puVar10 < (ushort)(((byte)param_1[2] + 1) * 9))) {
        iVar7 = -0x3feffffa;
      }
      else if ((param_3 < 2) || ((byte)param_1[2] == 0)) {
        puVar10 = (ushort *)0x0;
      }
      else {
        pbVar4 = (byte *)ExAllocatePool2(0x40,0x204,iVar9);
        if (pbVar4 == (byte *)0x0) {
          iVar7 = -0x3ffff000;
          puVar10 = param_1;
        }
        else {
          lVar5 = ExAllocatePool2(0x40,0x100,iVar9);
          if (lVar5 == 0) {
            iVar7 = -0x3ffff000;
            puVar10 = param_1;
          }
          else {
            puVar11 = (ushort *)((ulonglong)*puVar10 + (longlong)param_1);
            for (puVar10 = (ushort *)((longlong)param_1 + 9); puVar10 < puVar11;
                puVar10 = (ushort *)((longlong)puVar10 + (ulonglong)(byte)*puVar10)) {
              if ((ulonglong)((longlong)puVar11 - (longlong)puVar10) < 2) {
                iVar7 = -0x3ff00000;
                goto LAB_180002ceb;
              }
              bVar2 = (byte)*puVar10;
              if (puVar11 < (ushort *)((longlong)puVar10 + (ulonglong)bVar2)) {
LAB_180002c8e:
                iVar7 = -0x3fefffff;
                goto LAB_180002ceb;
              }
              bVar1 = *(byte *)((longlong)puVar10 + 1);
              if (bVar1 == 4) {
                if ((bVar2 < 9) || ((bVar2 != 9 && (2 < param_3)))) goto LAB_180002c8e;
                bVar2 = (byte)puVar10[1];
                uVar6 = (ulonglong)bVar2;
                bVar1 = *(byte *)((longlong)puVar10 + 3);
                uVar8 = (ulonglong)bVar1;
                if (bVar3) {
                  if (bVar1 == 0) {
                    *pbVar4 = bVar2;
                    local_48 = local_48 + 1;
                    pbVar4[1] = 0;
                    pbVar4[2] = 1;
                    pbVar4[0x202] = (byte)puVar10[2];
                    pbVar4[0x203] = 0;
                    *(undefined1 *)(uVar6 + lVar5) = 1;
                    bVar3 = false;
                    goto LAB_180002c7f;
                  }
                }
                else if (bVar2 == *pbVar4) {
                  if ((pbVar4[uVar8 + 2] != 1) && ((pbVar4[1] < bVar1 || (param_3 < 3)))) {
LAB_180002c36:
                    if ((pbVar4[0x203] == pbVar4[0x202]) || (param_3 < 3)) {
                      memset(pbVar4 + 0x102,0,0x100);
                      pbVar4[0x203] = 0;
                      pbVar4[0x202] = (byte)puVar10[2];
                      pbVar4[uVar8 + 2] = 1;
                      pbVar4[1] = bVar1;
                      goto LAB_180002c7f;
                    }
                    iVar7 = -0x3feffff8;
                    goto LAB_180002ceb;
                  }
                }
                else {
                  if ((*(char *)(uVar6 + lVar5) == '\x01') || ((bVar2 < *pbVar4 && (2 < param_3))))
                  {
                    iVar7 = -0x3feffffd;
                    puVar10 = puVar10 + 1;
                    goto LAB_180002ceb;
                  }
                  if (bVar1 == 0) {
                    local_48 = local_48 + 1;
                    *(undefined1 *)(uVar6 + lVar5) = 1;
                    *pbVar4 = bVar2;
                    memset(pbVar4 + 2,0,0x100);
                    uVar8 = 0;
                    goto LAB_180002c36;
                  }
                }
                iVar7 = -0x3feffffd;
                puVar10 = (ushort *)((longlong)puVar10 + 3);
                goto LAB_180002ceb;
              }
              if (bVar1 == 5) {
                if ((bVar2 < 7) || ((bVar2 != 7 && (2 < param_3)))) goto LAB_180002c8e;
                if (bVar3) {
                  iVar7 = -0x3feffffc;
                  goto LAB_180002ceb;
                }
                if (pbVar4[(ulonglong)(byte)puVar10[1] + 0x102] != 0) {
                  iVar7 = -0x3feffff7;
                  puVar10 = puVar10 + 1;
                  goto LAB_180002ceb;
                }
                pbVar4[(ulonglong)(byte)puVar10[1] + 0x102] = 1;
                pbVar4[0x203] = pbVar4[0x203] + 1;
              }
              else if ((bVar1 == 0xb) &&
                      ((((bVar2 != 8 ||
                         (bVar2 = *(byte *)((longlong)puVar10 + 3),
                         0x100 < (uint)(byte)puVar10[1] + (uint)bVar2)) ||
                        ((byte)param_1[2] < bVar2)) || (bVar2 == 0)))) {
                iVar7 = -0x3feffffb;
                goto LAB_180002ceb;
              }
LAB_180002c7f:
              if ((byte)*puVar10 == 0) break;
            }
            if (local_48 == (byte)param_1[2]) {
              iVar7 = 0;
              puVar10 = (ushort *)0x0;
            }
            else {
              iVar7 = -0x3feffff9;
              puVar10 = param_1;
            }
          }
LAB_180002ceb:
          ExFreePool(pbVar4);
          if (lVar5 != 0) {
            ExFreePool(lVar5);
          }
        }
      }
    }
    else {
      iVar7 = -0x3feffffe;
      puVar10 = (ushort *)((longlong)param_1 + 1);
    }
    if (-1 < iVar7) {
      puVar10 = (ushort *)0x0;
    }
    *param_4 = (longlong)puVar10;
  }
  return iVar7;
}



===== WPP_SF_ @ 180002d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 180002d7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_Dqd @ 180002dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 0;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0x19,local_res20,4,
             &param_5,8,local_18,4,0);
  return;
}



===== WPP_SF_d @ 180002e2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 180002e74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qd @ 180002eb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qDDd @ 180002f0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0xc0000023;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0x18,&local_res20,8,
             &param_5,4,&param_6,4,local_18,4,0);
  return;
}



===== WPP_SF_qDd @ 180002f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0xc0000004;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0x17,&local_res20,8,
             &param_5,4,local_18,4,0);
  return;
}



===== WPP_SF_qDqDqq @ 180002ffc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDqDqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_17e88a309dff3c712c023f8b20db5674_Traceguids,0x12,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_SF_qq @ 180003090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WppClassicProviderCallback @ 1800030e0 =====

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



===== ShimHookIofCallDriver @ 180003120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ShimHookIofCallDriver(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined2 uVar6;
  char *pcVar7;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2,
              *(undefined1 *)(param_2 + 0x42));
  }
  if (*(char *)(param_1 + 0x4c) <= *(char *)(param_2 + 0x42)) {
    uVar4 = (*DAT_180007018)(param_1,param_2);
    return uVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
  pcVar7 = (char *)(lVar2 + -0x48);
  *(char **)(param_2 + 0xb8) = pcVar7;
  lVar5 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01',0);
  if (lVar5 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2);
    }
    *(undefined8 *)(param_2 + 0x78) = 0;
    *(undefined8 *)(param_2 + 0x80) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return 0xc000009a;
  }
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(longlong *)(param_2 + 0x80) = lVar5;
  *(undefined8 *)(lVar5 + 0x18) = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined1 *)(lVar5 + 0x40) = *(undefined1 *)(param_2 + 0x40);
  *(undefined8 *)(lVar5 + 0x70) = *(undefined8 *)(param_2 + 0x70);
  *(undefined4 *)(lVar5 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  if (*pcVar7 == '\0') {
    *(undefined8 *)(lVar5 + 0x58) = *(undefined8 *)(param_2 + 0x58);
  }
  *(undefined8 *)(lVar5 + 0xc0) = *(undefined8 *)(param_2 + 0xc0);
  lVar3 = *(longlong *)(lVar5 + 0xb8);
  uVar4 = *(undefined8 *)(lVar2 + -0x40);
  *(undefined8 *)(lVar3 + -0x48) = *(undefined8 *)pcVar7;
  *(undefined8 *)(lVar3 + -0x40) = uVar4;
  uVar4 = *(undefined8 *)(lVar2 + -0x30);
  *(undefined8 *)(lVar3 + -0x38) = *(undefined8 *)(lVar2 + -0x38);
  *(undefined8 *)(lVar3 + -0x30) = uVar4;
  uVar4 = *(undefined8 *)(lVar2 + -0x20);
  *(undefined8 *)(lVar3 + -0x28) = *(undefined8 *)(lVar2 + -0x28);
  *(undefined8 *)(lVar3 + -0x20) = uVar4;
  uVar4 = *(undefined8 *)(lVar2 + -0x10);
  *(undefined8 *)(lVar3 + -0x18) = *(undefined8 *)(lVar2 + -0x18);
  *(undefined8 *)(lVar3 + -0x10) = uVar4;
  *(undefined8 *)(lVar3 + -8) = *(undefined8 *)(lVar2 + -8);
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  LOCK();
  *(code **)(param_2 + 0x68) = ShimIrpCancel;
  UNLOCK();
  if (*(char *)(param_2 + 0x44) == '\0') {
    lVar2 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar2 + -0x10) = ShimIoCompletionRoutine;
    *(longlong *)(lVar2 + -8) = param_2;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,lVar5,(char)param_2);
    }
    IofCallDriver(param_1,lVar5);
    return 0x103;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2);
  }
  LOCK();
  lVar2 = *(longlong *)(param_2 + 0x68);
  *(longlong *)(param_2 + 0x68) = 0;
  UNLOCK();
  if (lVar2 == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x78);
    *(longlong *)(param_2 + 0x78) = 0xffffffff;
    UNLOCK();
    if (lVar2 != 0xffffffff) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0x103;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0x103;
      }
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2);
      return 0x103;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_18000334d;
    uVar6 = 0x14;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_18000334d;
    uVar6 = 0x13;
  }
  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2);
LAB_18000334d:
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  IoFreeIrp(lVar5);
  return 0x103;
}



===== ShimIoCompletionRoutine @ 180003430 =====

undefined8 ShimIoCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2,(char)param_3);
  }
  LOCK();
  lVar1 = *(longlong *)(param_3 + 0x68);
  *(longlong *)(param_3 + 0x68) = 0;
  UNLOCK();
  if (lVar1 == 0) {
    iVar4 = 0;
    if (*(int *)(param_2 + 0x30) < 0) {
      iVar4 = *(int *)(param_2 + 0x30);
    }
    *(int *)(param_3 + 0x30) = iVar4;
    *(undefined8 *)(param_3 + 0x38) = *(undefined8 *)(param_2 + 0x38);
    LOCK();
    lVar1 = *(longlong *)(param_3 + 0x78);
    *(longlong *)(param_3 + 0x78) = 0xffffffff;
    UNLOCK();
    if (lVar1 != 0xffffffff) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000016;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc0000016;
      }
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_3);
      return 0xc0000016;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_3);
    }
    *(undefined8 *)(param_3 + 0x78) = 0;
    *(undefined8 *)(param_3 + 0x80) = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_3);
    }
    iVar4 = *(int *)(param_2 + 0x30);
    uVar2 = *(undefined8 *)(param_2 + 0x38);
    *(undefined8 *)(param_3 + 0x78) = 0;
    *(undefined8 *)(param_3 + 0x80) = 0;
    iVar3 = 0;
    if (iVar4 < 0) {
      iVar3 = iVar4;
    }
    *(int *)(param_3 + 0x30) = iVar3;
    *(undefined8 *)(param_3 + 0x38) = uVar2;
  }
  IofCompleteRequest(param_3,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== ShimIrpCancel @ 1800035a0 =====

void ShimIrpCancel(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar2 = *(undefined8 *)(param_2 + 0x80);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,uVar2,(char)param_2);
  }
  IoCancelIrp(uVar2);
  LOCK();
  lVar1 = *(longlong *)(param_2 + 0x78);
  *(longlong *)(param_2 + 0x78) = 0xffffffff;
  UNLOCK();
  if (lVar1 == 0xffffffff) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_47d3fd7d7a123e4705f327c9c58115b7_Traceguids,param_2);
    }
    *(undefined8 *)(param_2 + 0x78) = 0;
    *(undefined8 *)(param_2 + 0x80) = 0;
    IofCompleteRequest(param_2,0);
    IoFreeIrp(uVar2);
  }
  return;
}



===== HookIrpMjInternalDeviceControlNokiaUsbserFilterShim @ 180003690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HookIrpMjInternalDeviceControlNokiaUsbserFilterShim
               (longlong param_1,longlong param_2,undefined8 param_3)

{
  byte bVar1;
  byte *pbVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  
  pbVar2 = *(byte **)(param_2 + 0xb8);
  lVar5 = *(longlong *)(pbVar2 + 8);
  bVar1 = *pbVar2;
  if ((((lVar5 == 0) || (*(int *)(pbVar2 + 0x18) != 0x220003)) || (*(short *)(lVar5 + 2) != 0xb)) ||
     ((*(char *)(lVar5 + 0x83) != '\x02' || (*(int *)(lVar5 + 0x24) != 9)))) {
    lVar5 = param_2;
    cVar4 = USBD_IsClassInterfaceCommandWithUsbSerCompatIssue(param_2);
    if (cVar4 != '\0') {
      lVar3 = *(longlong *)(pbVar2 + 8);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_ZqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,param_3,
                   (wchar_t *)(*(longlong *)(param_1 + 8) + 0x38),(char)lVar3,
                   *(undefined1 *)(lVar3 + 0x81));
      }
      *(undefined2 *)(lVar3 + 2) = 0x1b;
    }
    lVar5 = (*(code *)*DAT_180007108)(*(undefined8 *)(param_1 + 8));
    (**(code **)(lVar5 + 0x20 + (ulonglong)bVar1 * 8))(param_1,param_2);
  }
  else {
    USBD_CallLowerDriver(param_1,param_2,param_3);
  }
  return;
}



===== USBD_CallLowerDriver @ 180003774 =====

undefined4 USBD_CallLowerDriver(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = IoGetLowerDeviceObject();
  if (lVar2 == 0) {
    uVar1 = 0xc0000001;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_ZqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,param_3,
                  (wchar_t *)(*(longlong *)(param_1 + 8) + 0x38),(char)param_2,(char)param_1);
    }
    IofCompleteRequest(param_2,0);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_Zqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                 (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),param_3,
                 (wchar_t *)(*(longlong *)(param_1 + 8) + 0x38),(char)param_2,(char)lVar2);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar1 = IofCallDriver(lVar2,param_2);
    ObfDereferenceObject(lVar2);
  }
  return uVar1;
}



===== USBD_IsClassInterfaceCommandWithUsbSerCompatIssue @ 180003874 =====

undefined1 USBD_IsClassInterfaceCommandWithUsbSerCompatIssue(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  undefined2 uVar3;
  char cVar4;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (lVar2 == 0) {
    return 0;
  }
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x18) != 0x220003) {
    return 0;
  }
  if ((*(short *)(lVar2 + 2) != 8) && (*(short *)(lVar2 + 2) != 0x32)) {
    return 0;
  }
  bVar1 = *(byte *)(lVar2 + 0x80);
  if ((bVar1 & 0x1f) != 1) {
    return 0;
  }
  if ((bVar1 & 0x60) != 0x20) {
    return 0;
  }
  cVar4 = *(char *)(lVar2 + 0x81);
  if (cVar4 != ' ') {
    if (cVar4 == '!') {
      if ((char)bVar1 < '\0') {
        return 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 1;
      }
      uVar3 = 0xc;
      cVar4 = '!';
      goto LAB_18000390d;
    }
    if ((cVar4 != '\"') && (cVar4 != '#')) {
      return 0;
    }
  }
  if (-1 < (char)bVar1) {
    return 1;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 1;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
    return 1;
  }
  uVar3 = 0xb;
LAB_18000390d:
  WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
            &WPP_2f71040678c63def7b32d802f682d560_Traceguids,lVar2,cVar4);
  return 1;
}



===== WPP_SF_ZqD @ 18000395c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_180003984;
    }
  }
  pwVar2 = L"NULL";
LAB_180003984:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2f71040678c63def7b32d802f682d560_Traceguids,10,param_4,2,pwVar2,wVar1
             ,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_Zqq @ 180003a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_180003a35;
    }
  }
  pwVar2 = L"NULL";
LAB_180003a35:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2f71040678c63def7b32d802f682d560_Traceguids,0xd,param_4,2,pwVar2,
             wVar1,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_ZqqD @ 180003ab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                undefined1 param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000001;
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_180003af0;
    }
  }
  pwVar1 = L"NULL";
LAB_180003af0:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2f71040678c63def7b32d802f682d560_Traceguids,0xe,param_4,2,pwVar1,
             wVar2,&param_5,8,&param_6,8,local_18,4,0);
  return;
}



===== __GSHandlerCheck @ 180003b98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 180003bbc =====

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



===== __cpu_features_init @ 180003c30 =====

/* WARNING: Removing unreachable block (ram,0x000180003c9a) */
/* WARNING: Removing unreachable block (ram,0x000180003c49) */
/* WARNING: Removing unreachable block (ram,0x000180003c3a) */

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



===== __security_check_cookie @ 180003d00 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180003d40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180003d70 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180003d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180003da0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 180003e00 =====

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



===== memset @ 180004100 =====

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



===== __memset_repmovs @ 180004240 =====

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



===== __memset_query @ 1800042c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180004340 =====

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



===== __memset_spec_ermsb_repmovsb @ 180004480 =====

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



===== __memset_spec_plain @ 180004500 =====

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



===== WppLoadTracingSupport @ 18000a010 =====

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



===== WppInitKm @ 18000a160 =====

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



===== WppCleanupKm @ 18000a1f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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



===== WppTraceCallback @ 18000a280 =====

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



===== ShimUnload @ 18000a508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ShimUnload(void)

{
  int iVar1;
  
  if (g_KseUnregisterShim != (code *)0x0) {
    if (g_UsbShimRegistered != '\0') {
      iVar1 = (*g_KseUnregisterShim)(&Shim,0,0);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids,iVar1);
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids);
        }
        g_UsbShimRegistered = '\0';
      }
    }
    if (g_NokiaUsbserFilterShimRegistered != '\0') {
      iVar1 = (*g_KseUnregisterShim)(&NokiaUsbserFilterShim,0,0);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids,iVar1);
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids);
        }
        g_NokiaUsbserFilterShimRegistered = '\0';
      }
    }
  }
  return;
}



===== ShimLoad @ 18000c010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ShimLoad(void)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"KseRegisterShimEx");
  g_KseRegisterShimEx = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"KseUnregisterShim");
  g_KseUnregisterShim = MmGetSystemRoutineAddress(&local_18);
  if ((g_KseRegisterShimEx == (code *)0x0) || (g_KseUnregisterShim == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids);
    }
  }
  else {
    iVar1 = (*g_KseRegisterShimEx)(&Shim,0,0,0);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids,iVar1);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids);
      }
      g_UsbShimRegistered = 1;
    }
    iVar1 = (*g_KseRegisterShimEx)(&NokiaUsbserFilterShim,0,0,0);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids,iVar1);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_07d0787fb7a13f49702d3e8c9615b63d_Traceguids);
      }
      g_NokiaUsbserFilterShimRegistered = 1;
    }
  }
  return;
}



===== entry @ 18000c1e0 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 18000c214 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  byte in_DL;
  char cVar5;
  undefined7 in_register_00000011;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar2 = (code *)swi(0x29);
    pbVar4 = (byte *)(*pcVar2)(6);
    bVar3 = (byte)pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + in_DL + CARRY1(bVar1,bVar3);
    *pbVar4 = *pbVar4 + bVar3;
    cVar5 = in_DL + pbVar4[0x2000013];
    *(byte *)((longlong)pbVar4 * 2) =
         *(byte *)((longlong)pbVar4 * 2) << 1 | CARRY1(in_DL,pbVar4[0x2000013]);
    *(byte *)CONCAT71(in_register_00000011,cVar5) =
         *(char *)CONCAT71(in_register_00000011,cVar5) + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


