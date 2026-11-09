
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



===== McGenControlCallbackV2 @ 1c0001020 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c0001130 =====

void McGenEventRegister_EtwRegister(void)

{
  if (VMSTORFL_PROVIDER_Context == 0) {
    EtwRegister(&VMSTORFL_PROVIDER,McGenControlCallbackV2,&VMSTORFL_PROVIDER_Context,
                &VMSTORFL_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c0001170 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (VMSTORFL_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    VMSTORFL_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c00011a4 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c0008038;
  uVar2 = 0;
  if (DAT_1c0008038 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c0008038;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(VMSTORFL_PROVIDER_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1c0001208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,&SFLT_FILTER_INACTIVE_FOR_ALL_DRIVES,0,1,local_28);
  return;
}



===== McTemplateK0d_EtwWriteTransfer @ 1c0001254 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0d_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,2,local_38);
  return;
}



===== McTemplateK0pduuuuup_EtwWriteTransfer @ 1c00012b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pduuuuup_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined8 *local_98;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = &local_res20;
  local_90 = 8;
  local_88 = &param_5;
  local_80 = 4;
  local_78 = &param_6;
  local_70 = 1;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_60 = 1;
  local_50 = 1;
  local_40 = 1;
  local_30 = 1;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventIORequestComplete,param_3,9,local_a8);
  return;
}



===== McTemplateK0puxip_EtwWriteTransfer @ 1c000138c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0puxip_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = &local_res20;
  local_60 = 8;
  local_58 = &param_5;
  local_50 = 1;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,6,local_78);
  return;
}



===== McTemplateK0zd_EtwWriteTransfer @ 1c000142c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_20 = 4;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,0,3,local_48);
  return;
}



===== RtlStringCchPrintfW @ 1c00014c4 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== StorFilterAllocateRequestAndLock @ 1c0001540 =====

bool StorFilterAllocateRequestAndLock(longlong param_1,undefined1 *param_2,longlong *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  longlong lVar4;
  bool bVar5;
  
  uVar2 = *(uint *)(param_1 + 0xa4);
  lVar1 = param_1 + 0x48;
  bVar5 = false;
  *param_3 = 0;
  if (0xff < uVar2) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar2 = *(uint *)(param_1 + 0xa4);
    *param_2 = uVar3;
    if (0xff < uVar2) {
      return false;
    }
    KeReleaseSpinLock(lVar1,uVar3);
  }
  lVar4 = ExAllocateFromNPagedLookasideList(param_1 + 0xc0);
  *param_3 = lVar4;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *param_2 = uVar3;
  if (*param_3 == 0) {
    if (*(uint *)(param_1 + 0xa4) == 0) {
      bVar5 = true;
      *param_3 = *(longlong *)(param_1 + 0x140);
    }
  }
  else {
    bVar5 = *(uint *)(param_1 + 0xa4) < 0x100;
  }
  return bVar5;
}



===== StorFilterBlockLimitsVpdCompletion @ 1c0001620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 StorFilterBlockLimitsVpdCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  byte bVar10;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined2 local_18;
  
  bVar10 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,param_1);
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar6,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  StorFilterDetectAndReportDeviceRemoval(puVar7,param_3);
  if ((*(byte *)(param_3 + 3) & 0x3f) == 1) {
    uVar9 = *(uint *)(param_3 + 400);
    if (*(uint *)(param_3 + 0x10) <= *(uint *)(param_3 + 400)) {
      uVar9 = *(uint *)(param_3 + 0x10);
    }
    uVar8 = RtlCompareMemory(*(undefined8 *)(param_3 + 0x18),param_3 + 0x194,uVar9);
    if (uVar9 != uVar8) {
      local_18 = 0;
      local_28 = 0xa00000000060070;
      uStack_20 = 0x3f00000000;
      if (0x12 < bVar10) {
        bVar10 = 0x12;
      }
      memcpy(*(void **)(lVar2 + 0x20),&local_28,(ulonglong)bVar10);
      *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 0x80;
      *(byte *)(lVar2 + 0xb) = bVar10;
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_3 + 0x178);
  uVar3 = *(undefined4 *)(param_3 + 0x184);
  uVar4 = *(undefined4 *)(param_3 + 0x188);
  uVar5 = *(undefined4 *)(param_3 + 0x18c);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_3 + 0x180);
  *(undefined4 *)(param_2 + 0x34) = uVar3;
  *(undefined4 *)(param_2 + 0x38) = uVar4;
  *(undefined4 *)(param_2 + 0x3c) = uVar5;
  IoFreeMdl(*(undefined8 *)(param_3 + 0x170));
  ExFreePoolWithTag(param_3,0);
  IofCompleteRequest(param_2,0);
  return 0xc0000016;
}



===== StorFilterCompleteAndProcessNextIrp @ 1c00017ac =====

void StorFilterCompleteAndProcessNextIrp(longlong param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  byte *pbVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  ulonglong uVar10;
  byte bVar11;
  byte bVar12;
  
  do {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 4) != 0) {
      bVar12 = 0;
      bVar11 = 0;
      uVar10 = 0;
      lVar3 = *(longlong *)((char *)param_3[0x17] + 8);
      if ((*(char *)param_3[0x17] == '\x0f') &&
         (((((cVar1 = *(char *)(lVar3 + 0x48), cVar1 == '\b' || (cVar1 == '\n')) || (cVar1 == '('))
           || ((cVar1 == '*' || (cVar1 == -0x78)))) ||
          ((cVar1 == -0x76 || ((cVar1 == -0x58 || (cVar1 == -0x56)))))))) {
        pbVar4 = *(byte **)(lVar3 + 0x20);
        bVar2 = *(byte *)(lVar3 + 0xb);
        if ((*(char *)(lVar3 + 3) == '\x01') || ((pbVar4 == (byte *)0x0 || (bVar2 == 0)))) {
LAB_1c00018d4:
          bVar12 = 0;
          bVar11 = 0;
          uVar10 = 0;
        }
        else {
          bVar5 = false;
          if ((byte)((*pbVar4 & 0x7f) + 0x8e) < 2) {
            if (pbVar4 + 8 <= pbVar4 + bVar2) {
              bVar11 = pbVar4[2];
              bVar12 = pbVar4[1] & 0xf;
              uVar10 = (ulonglong)pbVar4[3];
              goto LAB_1c00018c2;
            }
          }
          else if (pbVar4 + 8 <= pbVar4 + bVar2) {
            bVar12 = pbVar4[2] & 0xf;
            uVar7 = (uint)bVar2;
            if (pbVar4[7] + 8 <= (uint)bVar2) {
              uVar7 = pbVar4[7] + 8;
            }
            if (pbVar4 + 0xd <= pbVar4 + uVar7) {
              bVar11 = pbVar4[0xc];
            }
            if (pbVar4 + uVar7 < pbVar4 + 0xe) {
              uVar10 = 0;
            }
            else {
              uVar10 = (ulonglong)pbVar4[0xd];
            }
LAB_1c00018c2:
            bVar5 = true;
          }
          if (!bVar5) goto LAB_1c00018d4;
        }
        McTemplateK0pduuuuup_EtwWriteTransfer
                  (uVar10,pbVar4,param_2 + 5,param_3,(char)param_3[6],*(char *)(lVar3 + 3),
                   *(undefined1 *)(lVar3 + 4),bVar12,bVar11,(char)uVar10,(char)param_3);
      }
    }
    uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
    plVar9 = StorFilterPopQueue(param_1);
    if (plVar9 == (longlong *)0x0) {
      *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + -1;
    }
    else {
      *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -1;
    }
    KeReleaseSpinLock(param_1 + 0x48,uVar6);
    if ((plVar9 == (longlong *)0x0) && (param_2 != *(longlong **)(param_1 + 0x140))) {
      ExFreeToNPagedLookasideList(param_1 + 0xc0,param_2);
    }
    IofCompleteRequest(param_3,1);
    if (plVar9 == (longlong *)0x0) {
      return;
    }
    iVar8 = StorFilterForwardIrp(param_1,(longlong)plVar9,param_2);
    if (-1 < iVar8) {
      return;
    }
    param_3 = plVar9;
  } while( true );
}



===== StorFilterCompletion @ 1c00019d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterCompletion(undefined8 param_1,int param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  
  lVar4 = VmbChannelGetPointer();
  lVar1 = *(longlong *)(param_4 + 0x18);
  plVar2 = *(longlong **)(param_4 + -8);
  puVar3 = *(undefined8 **)(lVar4 + 0x40);
  if (param_2 == 1) {
    lVar4 = lVar1;
    StorChannelCopyPacketDataToSrb(param_1,param_3,lVar1);
    if ((((*(char *)(lVar1 + 3) != '\x01') &&
         ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(byte *)(lVar1 + 0x48),lVar4
                 ,lVar1,*(byte *)(lVar1 + 0x48),*(char *)(lVar1 + 3));
    }
    bVar5 = *(byte *)(lVar1 + 3) & 0x3f;
    if (bVar5 == 1) {
      uVar6 = 0;
    }
    else if ((bVar5 == 2) || (bVar5 == 4)) {
      uVar6 = 0xc0000185;
    }
    else if (bVar5 == 6) {
      uVar6 = 0xc0000010;
    }
    else if (bVar5 == 8) {
      uVar6 = 0xc000000e;
    }
    else if (bVar5 == 0x12) {
      uVar6 = 0x80000005;
    }
    else {
      uVar6 = 0xc0000001;
    }
    plVar2[7] = (ulonglong)*(uint *)(lVar1 + 0x10);
    *(undefined4 *)(plVar2 + 6) = uVar6;
    if ((((*(byte *)(lVar1 + 3) & 0x3f) == 1) && (*(char *)(lVar1 + 2) == '\0')) &&
       ((*(char *)(lVar1 + 0x48) == '\x12' &&
        (((*(byte *)(lVar1 + 0x49) & 1) != 0 && (*(char *)(lVar1 + 0x4a) == -0x50)))))) {
      (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,*puVar3);
      uVar7 = *(uint *)(lVar1 + 0x10);
      if (0x40 < uVar7) {
        uVar7 = 0x40;
      }
      memcpy((void *)((longlong)puVar3 + 0x174),*(void **)(lVar1 + 0x18),(ulonglong)uVar7);
      if (uVar7 <= *(uint *)(puVar3 + 0x2e)) {
        uVar7 = *(uint *)(puVar3 + 0x2e);
      }
      *(uint *)(puVar3 + 0x2e) = uVar7;
      (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,*puVar3);
    }
    StorFilterDetectAndReportDeviceRemoval(puVar3,lVar1);
  }
  else if (param_2 == 2) {
    *(undefined1 *)(lVar1 + 3) = 2;
    plVar2[7] = 0;
    *(undefined4 *)(plVar2 + 6) = 0xc000020f;
  }
  StorFilterCompleteAndProcessNextIrp((longlong)puVar3,(longlong *)(param_4 + -8),plVar2);
  return;
}



===== StorFilterDetectAndReportDeviceRemoval @ 1c0001bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void StorFilterDetectAndReportDeviceRemoval(undefined8 *param_1,longlong param_2)

{
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if ((*(byte *)(param_2 + 3) & 0x3f) == 8) {
    local_38 = 0x1c;
    local_34 = 0x200000002;
    uStack_2c = 0x200000002;
    local_24 = 0x200000001;
    (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,*param_1,&local_38);
  }
  return;
}



===== StorFilterEvtProcessDeviceIoCtrlIrp @ 1c0001c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 StorFilterEvtProcessDeviceIoCtrlIrp(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  if ((*(int *)(puVar2 + 3) == 0x2d1400) && (0xb < *(uint *)(puVar2 + 2))) {
    iVar1 = **(int **)(param_2 + 0x18);
    if ((iVar1 == 8) || (iVar1 == 0xb)) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
      IofCompleteRequest(param_2,CONCAT71((int7)((ulonglong)puVar2 >> 8),1));
      return 0xc00000bb;
    }
    if (iVar1 == 1) {
      puVar2[-9] = *puVar2;
      puVar2[-8] = puVar2[1];
      puVar2[-7] = puVar2[2];
      puVar2[-6] = puVar2[3];
      puVar2[-5] = puVar2[4];
      puVar2[-4] = puVar2[5];
      puVar2[-3] = puVar2[6];
      *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = StorFilterQueryAdapterPropertyCompletion;
      *(undefined8 *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0x40;
      goto LAB_1c0001cdf;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(undefined8 **)(param_2 + 0xb8) = puVar2 + 9;
LAB_1c0001cdf:
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1);
  return uVar4;
}



===== StorFilterEvtProcessPnPIrp @ 1c0001d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong StorFilterEvtProcessPnPIrp(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  if ((*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 2) && (*(longlong *)(lVar5 + 0x18) != 0)) {
    KeInitializeEvent(lVar5 + 0x20,1);
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
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = StorFilterPnPIrpCompletion;
    *(longlong *)(lVar3 + -8) = lVar5;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
    if ((((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar4);
    }
    KeWaitForSingleObject(lVar5 + 0x20,0,0,0,0);
    uVar1 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    uVar6 = (ulonglong)uVar1;
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  return uVar6;
}



===== StorFilterEvtProcessPowerIrp @ 1c0001eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 StorFilterEvtProcessPowerIrp(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  if ((*(int *)(puVar2 + 2) == 1) && (*(char *)(lVar4 + 0x38) != '\0')) {
    if (*(int *)(puVar2 + 3) == 4) {
      *(longlong *)(lVar4 + 0x150) = param_2;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      IoQueueWorkItem(*(undefined8 *)(lVar4 + 0x148),StorFilterPowerDownWorkItemRoutine,1,lVar4);
      return 0x103;
    }
    if (*(int *)(puVar2 + 3) == 1) {
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
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = StorFilterPowerIrpCompletion;
      *(longlong *)(lVar3 + -8) = lVar4;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      goto LAB_1c0001f9a;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(undefined8 **)(param_2 + 0xb8) = puVar2 + 9;
LAB_1c0001f9a:
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return uVar5;
}



===== StorFilterEvtProcessScsiIrp @ 1c0001fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong StorFilterEvtProcessScsiIrp(undefined8 param_1,longlong *param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined1 local_res10 [8];
  longlong *local_res18;
  
  local_res18 = (longlong *)0x0;
  local_res10[0] = 0;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  lVar2 = param_2[0x17];
  lVar3 = *(longlong *)(lVar2 + 8);
  if ((*(char *)(lVar9 + 0x168) == '\0') || (*(char *)(lVar3 + 2) != '\0')) goto LAB_1c000207c;
  bVar1 = *(byte *)(lVar3 + 0x48);
  if (bVar1 < 0x43) {
    if ((0x3a < bVar1 - 8) || ((0x400000000000005U >> ((ulonglong)(bVar1 - 8) & 0x3f) & 1) == 0)) {
      if (bVar1 == 0x12) {
        if ((*(byte *)(lVar3 + 0x49) & 1) == 0) goto LAB_1c000207c;
      }
      else if ((0x35 < bVar1) || ((0x20050000000000U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0))
      goto LAB_1c000207c;
    }
  }
  else if (((bVar1 != 0x88) && (bVar1 != 0x8a)) && (bVar1 != 0x91)) {
    if (bVar1 == 0x9e) {
      if (((*(byte *)(lVar3 + 0x49) & 0x1f) - 0x10 & 0xfd) != 0) goto LAB_1c000207c;
    }
    else if ((bVar1 != 0xa8) && (bVar1 != 0xaa)) goto LAB_1c000207c;
  }
  if (*(uint *)(lVar3 + 0x10) <= *(uint *)(lVar9 + 0x16c)) {
    *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
    bVar6 = StorFilterAllocateRequestAndLock(lVar9,local_res10,(longlong *)&local_res18);
    if (bVar6) {
      if (*(int *)(lVar9 + 0xa0) != 0) {
        StorFilterPushQueue(lVar9,(longlong)param_2);
        param_2 = StorFilterPopQueue(lVar9);
      }
      *(int *)(lVar9 + 0xa4) = *(int *)(lVar9 + 0xa4) + 1;
      KeReleaseSpinLock(lVar9 + 0x48,local_res10[0]);
      iVar8 = StorFilterForwardIrp(lVar9,(longlong)param_2,local_res18);
      if (iVar8 < 0) {
        StorFilterCompleteAndProcessNextIrp(lVar9,local_res18,param_2);
      }
    }
    else {
      StorFilterPushQueue(lVar9,(longlong)param_2);
      KeReleaseSpinLock(lVar9 + 0x48,local_res10[0]);
      if (local_res18 != (longlong *)0x0) {
        ExFreeToNPagedLookasideList(lVar9 + 0xc0);
      }
    }
    return 0x103;
  }
LAB_1c000207c:
  if ((*(int *)(lVar9 + 0x170) == 0) || (*(char *)(lVar9 + 0x168) == '\0')) {
    puVar4 = (undefined8 *)param_2[0x17];
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
    lVar2 = param_2[0x17];
    *(code **)(lVar2 + -0x10) = StorFilterIrpCompletion;
    *(longlong *)(lVar2 + -8) = lVar9;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar10 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  else {
    puVar4 = (undefined8 *)param_2[0x17];
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
    lVar5 = param_2[0x17];
    *(code **)(lVar5 + -0x10) = StorFilterNotFilterableSrbCompletion;
    *(longlong *)(lVar5 + -8) = lVar9;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    *(ulonglong *)(lVar2 + 0x10) = (ulonglong)*(byte *)(lVar3 + 0xb);
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
    uVar10 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
      uVar10 = 0x103;
    }
  }
  return uVar10;
}



===== StorFilterForwardIrp @ 1c00022ac =====

void StorFilterForwardIrp(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  *param_3 = param_2;
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 3) != 0) {
    StorFilterStartIOTrace(lVar1,param_2,param_3 + 5);
  }
  *(undefined1 *)(lVar1 + 5) = *(undefined1 *)(param_1 + 0x41);
  *(undefined1 *)(lVar1 + 6) = *(undefined1 *)(param_1 + 0x42);
  *(undefined1 *)(lVar1 + 7) = *(undefined1 *)(param_1 + 0x43);
  iVar2 = StorChannelSendSrbRequest
                    (*(undefined8 *)(param_1 + 8),SystemReserved1[0x12]._4_4_,lVar1,
                     *(longlong *)(param_2 + 8),in_stack_ffffffffffffffd8,param_3 + 1,param_3 + 8,
                     (longlong)(param_3 + 5));
  if (iVar2 < 0) {
    *(undefined1 *)(lVar1 + 3) = 2;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar2;
  }
  return;
}



===== StorFilterIrpCompletion @ 1c0002370 =====

undefined8 StorFilterIrpCompletion(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  byte *pbVar1;
  
  StorFilterDetectAndReportDeviceRemoval(param_3,*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8));
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return 0;
}



===== StorFilterLogActiveEvent @ 1c00023ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void StorFilterLogActiveEvent(char param_1,undefined1 param_2,longlong param_3)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  undefined *puVar3;
  wchar_t *pwVar4;
  undefined1 auStack_c8 [32];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  pwVar2 = local_98;
  pwVar4 = L"%d,%d,%d";
  uVar1 = RtlStringCchPrintfW(pwVar2,0x40,L"%d,%d,%d",(ulonglong)*(byte *)(param_3 + 4));
  if (-1 < (int)uVar1) {
    if (param_1 == '\0') {
      if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 8) == 0) {
        return;
      }
      puVar3 = &SFLT_FILTER_INACTIVE;
    }
    else {
      if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 0x10) == 0) {
        return;
      }
      puVar3 = &SFLT_FILTER_ACTIVE;
    }
    McTemplateK0zd_EtwWriteTransfer(pwVar2,puVar3,pwVar4,local_98,param_2);
  }
  return;
}



===== StorFilterNotFilterableSrbCompletion @ 1c0002460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
StorFilterNotFilterableSrbCompletion(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  lVar8 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  StorFilterDetectAndReportDeviceRemoval(param_3,lVar8);
  if ((*(byte *)(lVar8 + 3) & 0x3f) == 1) {
    if (*(char *)(param_2 + 0x41) != '\0') {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
    }
    return 0;
  }
  puVar7 = (undefined2 *)ExAllocatePool2(0x40,0x1d8,0x746c6656);
  if (puVar7 != (undefined2 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,*param_3);
    *(undefined4 *)(puVar7 + 200) = *(undefined4 *)(param_3 + 0x2e);
    memcpy(puVar7 + 0xca,(void *)((longlong)param_3 + 0x174),(ulonglong)*(uint *)(param_3 + 0x2e));
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,*param_3);
    *(undefined8 *)(puVar7 + 0xbc) = *(undefined8 *)(param_2 + 8);
    lVar8 = IoAllocateMdl(puVar7 + 0x2c,0xff,0,0,param_2);
    *(longlong *)(puVar7 + 0xb8) = lVar8;
    if (lVar8 != 0) {
      MmBuildMdlForNonPagedPool(lVar8);
      *puVar7 = 0x58;
      *(undefined1 *)(puVar7 + 1) = 0;
      *(undefined1 *)((longlong)puVar7 + 5) = *(undefined1 *)((longlong)param_3 + 0x41);
      *(undefined1 *)(puVar7 + 3) = *(undefined1 *)((longlong)param_3 + 0x42);
      uVar2 = *(undefined1 *)((longlong)param_3 + 0x43);
      *(byte *)((longlong)puVar7 + 0x49) = *(byte *)((longlong)puVar7 + 0x49) | 1;
      *(undefined1 *)((longlong)puVar7 + 7) = uVar2;
      *(longlong *)(puVar7 + 0x10) = (longlong)puVar7 + 0x157;
      *(undefined4 *)(puVar7 + 4) = 0x140620ff;
      *(undefined4 *)(puVar7 + 6) = 0x148;
      *(undefined4 *)(puVar7 + 8) = 0xff;
      *(undefined4 *)(puVar7 + 10) = 0x3c;
      *(undefined2 **)(puVar7 + 0xc) = puVar7 + 0x2c;
      *(undefined1 *)(puVar7 + 0x24) = 0x12;
      *(undefined1 *)(puVar7 + 0x25) = 0xb0;
      *(undefined1 *)(puVar7 + 0x26) = 0xff;
      puVar3 = *(undefined8 **)(param_2 + 0xb8);
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      puVar3[-5] = puVar3[4];
      puVar3[-4] = puVar3[5];
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      lVar8 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar8 + -0x10) = StorFilterBlockLimitsVpdCompletion;
      *(undefined2 **)(lVar8 + -8) = puVar7;
      *(undefined1 *)(lVar8 + -0x45) = 0xe0;
      *(undefined2 **)(*(longlong *)(param_2 + 0xb8) + -0x40) = puVar7;
      uVar4 = *(undefined4 *)(param_2 + 0x34);
      uVar5 = *(undefined4 *)(param_2 + 0x38);
      uVar6 = *(undefined4 *)(param_2 + 0x3c);
      *(undefined4 *)(puVar7 + 0xc0) = *(undefined4 *)(param_2 + 0x30);
      *(undefined4 *)(puVar7 + 0xc2) = uVar4;
      *(undefined4 *)(puVar7 + 0xc4) = uVar5;
      *(undefined4 *)(puVar7 + 0xc6) = uVar6;
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      uVar9 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*param_3);
      IofCallDriver(uVar9,param_2);
      return 0xc0000016;
    }
    ExFreePoolWithTag(puVar7,0);
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  IofCompleteRequest(param_2,0);
  return 0xc0000016;
}



===== StorFilterPnPIrpCompletion @ 1c00026e0 =====

int StorFilterPnPIrpCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  ulonglong uVar5;
  uint uVar6;
  
  puVar4 = (uint *)0x0;
  uVar6 = 0;
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  iVar2 = *(int *)(param_2 + 0x30);
  if (iVar2 < 0) {
    if ((iVar2 != -0x3fffff45) && (iVar2 != -0x3ffffff0)) {
      return iVar2;
    }
  }
  else {
    puVar4 = *(uint **)(param_2 + 0x38);
    if (puVar4 != (uint *)0x0) {
      uVar6 = *puVar4;
    }
  }
  uVar5 = (ulonglong)uVar6;
  piVar3 = (int *)ExAllocatePool2(0x40,uVar5 * 8 + 0x10,0x746c6656);
  if (piVar3 == (int *)0x0) {
    *(undefined1 *)(param_3 + 0x38) = 0;
    return iVar2;
  }
  if (uVar6 != 0) {
    memcpy(piVar3 + 2,puVar4 + 2,uVar5 * 8);
  }
  *(undefined8 *)(piVar3 + uVar5 * 2 + 2) = *(undefined8 *)(param_3 + 0x18);
  *piVar3 = uVar6 + 1;
  ObfReferenceObject(*(undefined8 *)(param_3 + 0x18));
  if (puVar4 != (uint *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(int **)(param_2 + 0x38) = piVar3;
  KeSetEvent(param_3 + 0x20,0,0);
  return -0x3fffffea;
}



===== StorFilterPopQueue @ 1c0002810 =====

longlong * StorFilterPopQueue(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  int iVar5;
  
  iVar5 = 5;
  do {
    plVar4 = (longlong *)(((ulonglong)(iVar5 - 1) + 5) * 0x10 + param_1);
    if ((longlong *)*plVar4 != plVar4) break;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (iVar5 != 0) {
    plVar4 = *(longlong **)(param_1 + ((ulonglong)(iVar5 - 1) + 5) * 0x10);
    lVar1 = *plVar4;
    if ((*(longlong **)(lVar1 + 8) == plVar4) &&
       (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 == plVar4)) {
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      return plVar4 + -0x15;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
  }
  return (longlong *)0x0;
}



===== StorFilterPowerDownWorkItemRoutine @ 1c0002880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterPowerDownWorkItemRoutine(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  lVar1 = param_2[0x2a];
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_2 + 0x2c);
  param_2[0x2a] = 0;
  *(undefined1 *)(param_2 + 0x2d) = 0;
  puVar3 = (undefined8 *)VmbChannelGetPointer(param_2[1]);
  VmbChannelDisable(*puVar3);
  plVar4 = puVar3 + 0x12;
  uVar6 = 0x3f;
  do {
    uVar5 = uVar6;
    if (*plVar4 != 0) {
      VmbChannelCleanup();
    }
    plVar4 = plVar4 + 2;
    uVar6 = uVar5 - 1;
  } while (uVar6 != 0);
  memset(puVar3 + 0x12,0,0x3f0);
  StorChannelReevaluateSubChannels(puVar3);
  PoSetPowerState(param_1,uVar5 & 0xffffffff,*(undefined4 *)(lVar2 + 0x18));
  ExReleasePushLockExclusiveEx(param_2 + 0x2c,0);
  KeLeaveCriticalRegion();
  puVar3 = *(undefined8 **)(lVar1 + 0xb8);
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
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,*param_2,lVar1);
  return;
}



===== StorFilterPowerIrpCompletion @ 1c0002a00 =====

int StorFilterPowerIrpCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(lVar3 + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  iVar2 = *(int *)(param_2 + 0x30);
  if (-1 < iVar2) {
    IoQueueWorkItem(*(undefined8 *)(param_3 + 0x158),StorFilterPowerUpWorkItemRoutine,1,param_3);
    PoSetPowerState(param_1,1,*(undefined4 *)(lVar3 + 0x18));
  }
  return iVar2;
}



===== StorFilterPowerUpWorkItemRoutine @ 1c0002a90 =====

void StorFilterPowerUpWorkItemRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  KeEnterCriticalRegion();
  uVar4 = 0;
  ExAcquirePushLockExclusiveEx(param_2 + 0x160);
  puVar2 = (undefined8 *)VmbChannelGetPointer(*(undefined8 *)(param_2 + 8));
  iVar1 = VmbChannelEnable(*puVar2);
  if (-1 < iVar1) {
    uVar3 = StorChannelEstablishCommunications(*puVar2,uVar4,param_3);
    iVar1 = (int)uVar3;
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  *(undefined2 *)((longlong)puVar2 + 0x82) = 0;
  *(undefined1 *)((longlong)puVar2 + 0x84) = 0;
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar1);
    }
    StorFilterLogActiveEvent('\0',(char)iVar1,param_2 + 0x3c);
  }
  ExReleasePushLockExclusiveEx(param_2 + 0x160,0);
  KeLeaveCriticalRegion();
  return;
}



===== StorFilterPushQueue @ 1c0002ba4 =====

void StorFilterPushQueue(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  code *pcVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  
  uVar3 = IoGetIoPriorityHint(param_2);
  plVar6 = (longlong *)(param_2 + 0xa8);
  if (4 < uVar3) {
    uVar3 = 4;
  }
  lVar5 = ((ulonglong)uVar3 + 5) * 0x10 + param_1;
  plVar4 = *(longlong **)(lVar5 + 8);
  if (*plVar4 != lVar5) {
    pcVar2 = (code *)swi(0x29);
    plVar4 = (longlong *)(*pcVar2)(3);
  }
  *plVar6 = lVar5;
  plVar6[1] = (longlong)plVar4;
  *plVar4 = (longlong)plVar6;
  *(longlong **)(lVar5 + 8) = plVar6;
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  return;
}



===== StorFilterQueryAdapterPropertyCompletion @ 1c0002c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
StorFilterQueryAdapterPropertyCompletion(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  if ((*(char *)(lVar3 + 0x168) != '\0') && (0xb < *(ulonglong *)(param_2 + 0x38))) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    uVar4 = *(uint *)(lVar2 + 8);
    if (*(uint *)(lVar2 + 8) <= *(uint *)(lVar3 + 0x16c)) {
      uVar4 = *(uint *)(lVar3 + 0x16c);
    }
    *(uint *)(lVar2 + 8) = uVar4;
    uVar5 = (uint)((*(uint *)(lVar3 + 0x16c) & 0xfff) != 0) + (*(uint *)(lVar3 + 0x16c) >> 0xc);
    uVar4 = *(uint *)(lVar2 + 0xc);
    if (*(uint *)(lVar2 + 0xc) <= uVar5) {
      uVar4 = uVar5;
    }
    *(uint *)(lVar2 + 0xc) = uVar4;
  }
  return 0;
}



===== StorFilterStartIOTrace @ 1c0002cd4 =====

void StorFilterStartIOTrace(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  char cVar2;
  uint3 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined *puVar6;
  uint local_res8;
  
  iVar5 = IoGetActivityIdIrp(param_2,param_3);
  if (iVar5 < 0) {
    EtwActivityIdControl(3,param_3);
  }
  if (*(char *)(param_1 + 2) != '\0') {
    return;
  }
  if (*(char *)(param_1 + 10) == '\x10') {
    uVar1 = *(undefined1 *)(param_1 + 0x51);
    uVar3 = CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x52),*(undefined1 *)(param_1 + 0x53)),
                     *(undefined1 *)(param_1 + 0x54));
    uVar4 = *(undefined1 *)(param_1 + 0x55);
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x4d);
    uVar3 = (uint3)*(byte *)(param_1 + 0x4f);
    uVar4 = *(undefined1 *)(param_1 + 0x50);
  }
  cVar2 = *(char *)(param_1 + 0x48);
  local_res8 = CONCAT31(uVar3,uVar4);
  if (cVar2 == '\b') {
LAB_1c0002e06:
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 1) == 0) {
      return;
    }
    puVar6 = &EventReadRequest;
  }
  else {
    if (cVar2 != '\n') {
      if (cVar2 == '(') goto LAB_1c0002e06;
      if (cVar2 != '*') {
        if (cVar2 == -0x78) goto LAB_1c0002e06;
        if (cVar2 != -0x76) {
          if (cVar2 == -0x58) goto LAB_1c0002e06;
          if (cVar2 != -0x56) {
            return;
          }
        }
      }
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 2) == 0) {
      return;
    }
    puVar6 = &EventWriteRequest;
  }
  McTemplateK0puxip_EtwWriteTransfer
            ((ulonglong)local_res8,puVar6,param_3,param_2,cVar2,uVar4,uVar1,(char)param_2);
  return;
}



===== StorFilterStorageChannelPostStarted @ 1c0002e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterStorageChannelPostStarted(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 local_res10 [3];
  
  lVar2 = VmbChannelGetPointer();
  puVar1 = *(undefined8 **)(lVar2 + 0x40);
  local_res10[0] = 0;
  uVar3 = StorChannelEstablishCommunications(param_1,param_2,param_3);
  if (-1 < (int)uVar3) {
    lVar2 = VmbChannelGetPointer(param_1);
    *(undefined4 *)((longlong)puVar1 + 0x16c) = *(undefined4 *)(lVar2 + 0x54);
    LOCK();
    UNLOCK();
    *(undefined1 *)(puVar1 + 0x2d) = 1;
    VmbChannelGetTargetDeviceObject(param_1,local_res10);
    uVar4 = IoGetDeviceAttachmentBaseRef(local_res10[0]);
    puVar1[3] = uVar4;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,*puVar1);
    IoInvalidateDeviceRelations(uVar4,2);
  }
  return;
}



===== WPP_SF_ @ 1c0002f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1c0002f4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_qDD @ 1c0002f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0003000 =====

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



===== FxStubDriverUnloadCommon @ 1c0003034 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0008158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0008158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c000308d:
      if (ppvVar1 == (void **)0x0) goto LAB_1c00030e3;
      if (ppvVar2 <= ppvVar1) goto LAB_1c00030fb;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c000308d;
LAB_1c00030e3:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c00030fb:
  WdfVersionUnbind(&DAT_1c00083e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0003130 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0003164 =====

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
    _DAT_1c00083e0 = 0x2080000;
    _DAT_1c00083e8 = &DAT_1c00081d0;
    RtlCopyUnicodeString(&DAT_1c00083e0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00083e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00083d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00083e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0008158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c00032f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00083d8 != (code *)0x0) && (DAT_1c00083d8 != FxStubDriverUnload)) {
    (*DAT_1c00083d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0003324 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0003349) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000814f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0008158 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c00034ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00034c9) */
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
    if ((void **)0x1c000816f < ppvVar2) break;
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



===== StorChannelCompareChannelByProcessorIndex @ 1c0003580 =====

ulonglong StorChannelCompareChannelByProcessorIndex(longlong param_1,longlong param_2)

{
  if (*(uint *)(param_1 + 8) < *(uint *)(param_2 + 8)) {
    return 0xffffffff;
  }
  return (ulonglong)(*(uint *)(param_1 + 8) != *(uint *)(param_2 + 8));
}



===== StorChannelCompareProcessorByDistanceDescending @ 1c00035b0 =====

ulonglong StorChannelCompareProcessorByDistanceDescending(ushort *param_1,ushort *param_2)

{
  if (param_1[2] <= param_2[2]) {
    if (param_1[2] < param_2[2]) {
      return 1;
    }
    if (*param_2 <= *param_1) {
      return (ulonglong)(*param_2 < *param_1);
    }
  }
  return 0xffffffff;
}



===== StorChannelCopyPacketDataToSrb @ 1c00035e4 =====

void StorChannelCopyPacketDataToSrb(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  code *pcVar7;
  bool bVar8;
  byte bVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  byte bVar16;
  byte bVar17;
  byte *_Dst;
  byte bVar18;
  
  cVar3 = *(char *)(param_3 + 2);
  puVar1 = (uint *)(param_3 + 0x10);
  if (cVar3 == '(') {
    uVar15 = *(uint *)(param_3 + 0x3c);
  }
  else {
    uVar15 = *puVar1;
  }
  uVar11 = *(uint *)(param_2 + 0x18);
  if (uVar15 < uVar11) {
LAB_1c0003a9a:
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(0x3a);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  if (cVar3 != '(') {
    *puVar1 = uVar11;
  }
  else {
    *(uint *)(param_3 + 0x3c) = uVar11;
  }
  bVar9 = *(byte *)(param_2 + 0xe);
  if (cVar3 != '(') {
    if (*(char *)(param_3 + 3) < '\0') {
      bVar9 = bVar9 | 0x80;
    }
  }
  else {
    bVar5 = bVar9 | 0x80;
    if (-1 < *(char *)(param_3 + 3)) {
      bVar5 = bVar9;
    }
    bVar9 = bVar5;
  }
  *(byte *)(param_3 + 3) = bVar9;
  uVar4 = *(undefined1 *)(param_2 + 0xf);
  if (cVar3 == '(') {
    bVar8 = false;
    if ((*(int *)(param_3 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_3 + 0x38) != 0)) {
      do {
        uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
        if ((0x7f < uVar15) && (uVar11 = *puVar1, uVar15 < uVar11)) {
          uVar12 = (ulonglong)uVar15;
          iVar6 = *(int *)((ulonglong)uVar15 + param_3);
          if (iVar6 == 0x40) {
LAB_1c00036ab:
            if (uVar12 + 0x28 <= (ulonglong)uVar11) {
              *(undefined1 *)(uVar12 + 8 + param_3) = uVar4;
              break;
            }
          }
          else if (iVar6 == 0x41) {
            if (uVar12 + 0x38 <= (ulonglong)uVar11) {
              bVar8 = true;
              *(undefined1 *)(uVar12 + 8 + param_3) = uVar4;
            }
          }
          else if (iVar6 == 0x42) goto LAB_1c00036ab;
          if (bVar8) break;
        }
        uVar15 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar15;
      } while (uVar15 < *(uint *)(param_3 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_3 + 4) = uVar4;
  }
  if (*(char *)(param_2 + 0xf) != '\x02') {
    return;
  }
  lVar10 = VmbChannelGetPointer(param_1);
  if (0x14 < *(byte *)(param_2 + 0x15)) goto LAB_1c0003a9a;
  _Dst = (byte *)0x0;
  if (*(char *)(param_3 + 2) == '(') {
    bVar8 = false;
    if (*(int *)(param_3 + 0x14) == 0) {
      uVar14 = 0;
      if (*(uint *)(param_3 + 0x38) != 0) {
        do {
          uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
          if ((0x7f < uVar15) && (uVar12 = (ulonglong)*puVar1, uVar15 < *puVar1)) {
            uVar13 = (ulonglong)uVar15;
            iVar6 = *(int *)((ulonglong)uVar15 + param_3);
            if (iVar6 == 0x40) {
              if (uVar13 + 0x28 <= uVar12) {
                _Dst = *(byte **)(uVar13 + 0x10 + param_3);
                break;
              }
            }
            else if (iVar6 == 0x41) {
              if (uVar13 + 0x38 <= uVar12) {
                _Dst = *(byte **)(uVar13 + 0x10 + param_3);
                bVar8 = true;
              }
            }
            else if ((iVar6 == 0x42) && (uVar13 + 0x28 <= uVar12)) {
              _Dst = *(byte **)(uVar13 + 0x18 + param_3);
              break;
            }
            if (bVar8) break;
          }
          uVar15 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar15;
        } while (uVar15 < *(uint *)(param_3 + 0x38));
      }
    }
    bVar8 = false;
    bVar9 = 0;
    if (*(int *)(param_3 + 0x14) == 0) {
      uVar14 = 0;
      bVar5 = 0;
      if (*(uint *)(param_3 + 0x38) != 0) {
        do {
          bVar9 = bVar5;
          uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
          if ((0x7f < uVar15) && (uVar11 = *puVar1, uVar15 < uVar11)) {
            uVar12 = (ulonglong)uVar15;
            iVar6 = *(int *)((ulonglong)uVar15 + param_3);
            if (iVar6 == 0x40) {
LAB_1c00037da:
              if (uVar12 + 0x28 <= (ulonglong)uVar11) {
                bVar9 = *(byte *)(uVar12 + 9 + param_3);
                break;
              }
            }
            else if (iVar6 == 0x41) {
              if (uVar12 + 0x38 <= (ulonglong)uVar11) {
                bVar9 = *(byte *)(uVar12 + 9 + param_3);
                bVar8 = true;
              }
            }
            else if (iVar6 == 0x42) goto LAB_1c00037da;
            if (bVar8) break;
          }
          uVar15 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar15;
          bVar5 = bVar9;
        } while (uVar15 < *(uint *)(param_3 + 0x38));
      }
    }
  }
  else {
    _Dst = *(byte **)(param_3 + 0x20);
    bVar9 = *(byte *)(param_3 + 0xb);
  }
  if (_Dst == (byte *)0x0) {
    return;
  }
  if (bVar9 == 0) {
    return;
  }
  if (((byte)((*(byte *)(param_2 + 0x1c) & 0x7f) + 0x8e) < 2) &&
     ((*(char *)(lVar10 + 0x75) == '\0' || ((bVar9 < *(byte *)(param_2 + 0x15) && (0x11 < bVar9)))))
     ) {
    bVar8 = true;
  }
  else {
    bVar8 = false;
  }
  bVar5 = *(byte *)(param_2 + 0x15);
  uVar14 = (ulonglong)bVar5;
  if (!bVar8) {
    if (bVar9 < bVar5) {
      return;
    }
    memcpy(_Dst,(void *)(param_2 + 0x1c),uVar14);
    uVar4 = *(undefined1 *)(param_2 + 0x15);
    if (*(char *)(param_3 + 2) != '(') {
      *(undefined1 *)(param_3 + 0xb) = uVar4;
      return;
    }
    bVar8 = false;
    if (*(int *)(param_3 + 0x14) != 0) {
      return;
    }
    uVar14 = 0;
    if (*(int *)(param_3 + 0x38) == 0) {
      return;
    }
    do {
      uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
      if ((0x7f < uVar15) && (uVar11 = *(uint *)(param_3 + 0x10), uVar15 < uVar11)) {
        uVar12 = (ulonglong)uVar15;
        iVar6 = *(int *)((ulonglong)uVar15 + param_3);
        if (iVar6 == 0x40) {
LAB_1c0003a54:
          if (uVar12 + 0x28 <= (ulonglong)uVar11) {
            *(undefined1 *)(uVar12 + 9 + param_3) = uVar4;
            return;
          }
        }
        else if (iVar6 == 0x41) {
          if (uVar12 + 0x38 <= (ulonglong)uVar11) {
            bVar8 = true;
            *(undefined1 *)(uVar12 + 9 + param_3) = uVar4;
          }
        }
        else if (iVar6 == 0x42) goto LAB_1c0003a54;
        if (bVar8) {
          return;
        }
      }
      uVar15 = (int)uVar14 + 1;
      uVar14 = (ulonglong)uVar15;
      if (*(uint *)(param_3 + 0x38) <= uVar15) {
        return;
      }
    } while( true );
  }
  pbVar2 = (byte *)(param_2 + 0x1c);
  bVar17 = 0;
  bVar18 = 0;
  bVar16 = 0;
  if ((((pbVar2 == (byte *)0x0) || (bVar5 == 0)) || (bVar9 < 0x12)) ||
     (1 < (byte)((*pbVar2 & 0x7f) + 0x8e))) goto LAB_1c000395e;
  memset(_Dst,0,(ulonglong)bVar9);
  if ((byte)((*pbVar2 & 0x7f) + 0x8e) < 2) {
    bVar8 = false;
    if ((byte *)(param_2 + 0x24U) <= pbVar2 + uVar14) {
      bVar18 = *(byte *)(param_2 + 0x1d);
      bVar17 = *(byte *)(param_2 + 0x1e);
      bVar16 = *(byte *)(param_2 + 0x1f);
LAB_1c000391d:
      bVar8 = true;
    }
  }
  else {
    if (1 < (byte)((*pbVar2 & 0x7f) + 0x90)) goto LAB_1c000395e;
    bVar8 = false;
    if ((byte *)(param_2 + 0x24U) <= pbVar2 + uVar14) {
      bVar18 = *(byte *)(param_2 + 0x1e);
      uVar11 = *(byte *)(param_2 + 0x23) + 8;
      uVar15 = (uint)bVar5;
      if (uVar11 <= bVar5) {
        uVar15 = uVar11;
      }
      if ((byte *)(param_2 + 0x29U) <= pbVar2 + uVar15) {
        bVar17 = *(byte *)(param_2 + 0x28);
      }
      if (pbVar2 + uVar15 < (byte *)(param_2 + 0x2aU)) {
        bVar16 = 0;
      }
      else {
        bVar16 = *(byte *)(param_2 + 0x29U);
      }
      goto LAB_1c000391d;
    }
  }
  if (bVar8) {
    if (((*pbVar2 & 0x7f) + 0x90 & 0xfd) == 0) {
      bVar9 = *_Dst & 0xf0 | 0x70;
    }
    else {
      bVar9 = *_Dst & 0xf1 | 0x71;
    }
    *_Dst = bVar9;
    _Dst[7] = 10;
    _Dst[0xc] = bVar17;
    _Dst[0xd] = bVar16;
    _Dst[2] = (bVar18 ^ _Dst[2]) & 0xf ^ _Dst[2];
  }
LAB_1c000395e:
  if (*(char *)(param_3 + 2) == '(') {
    bVar8 = false;
    if ((*(int *)(param_3 + 0x14) == 0) && (uVar14 = 0, *(int *)(param_3 + 0x38) != 0)) {
      do {
        uVar15 = *(uint *)(param_3 + 0x78 + uVar14 * 4);
        if ((0x7f < uVar15) && (uVar11 = *(uint *)(param_3 + 0x10), uVar15 < uVar11)) {
          uVar12 = (ulonglong)uVar15;
          iVar6 = *(int *)((ulonglong)uVar15 + param_3);
          if (iVar6 == 0x40) {
LAB_1c00039a4:
            if (uVar12 + 0x28 <= (ulonglong)uVar11) {
              *(undefined1 *)(uVar12 + 9 + param_3) = 0x12;
              return;
            }
          }
          else if (iVar6 == 0x41) {
            if (uVar12 + 0x38 <= (ulonglong)uVar11) {
              bVar8 = true;
              *(undefined1 *)(uVar12 + 9 + param_3) = 0x12;
            }
          }
          else if (iVar6 == 0x42) goto LAB_1c00039a4;
          if (bVar8) {
            return;
          }
        }
        uVar15 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar15;
      } while (uVar15 < *(uint *)(param_3 + 0x38));
    }
  }
  else {
    *(undefined1 *)(param_3 + 0xb) = 0x12;
  }
  return;
}



===== StorChannelCopySrbToPacket @ 1c0003aa8 =====

void StorChannelCopySrbToPacket(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  short *psVar7;
  byte bVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  size_t _Size;
  longlong lVar11;
  void *_Src;
  uint uVar12;
  ulonglong uVar13;
  int *piVar14;
  byte bVar15;
  
  uVar9 = 0;
  piVar14 = (int *)(param_1 + 0x14);
  if (*(char *)(param_1 + 2) == '(') {
    _Src = (void *)0x0;
    bVar3 = false;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) &&
             (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar12 < *(uint *)(param_1 + 0x10))) {
            uVar5 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
              if (uVar5 + 0x28 <= uVar6) {
                if (*(char *)(uVar5 + 10 + param_1) != '\0') {
                  lVar11 = param_1 + 0x18;
LAB_1c0003b7e:
                  _Src = (void *)(lVar11 + uVar5);
                }
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar5 + 0x38 <= uVar6) {
                bVar3 = true;
                if (*(char *)(uVar5 + 10 + param_1) == '\0') break;
                _Src = (void *)(param_1 + 0x18 + uVar5);
              }
            }
            else if ((iVar1 == 0x42) && (uVar5 + 0x28 <= uVar6)) {
              if (*(int *)(uVar5 + 0xc + param_1) != 0) {
                lVar11 = param_1 + 0x20;
                goto LAB_1c0003b7e;
              }
              break;
            }
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
    bVar3 = false;
    bVar8 = 0;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) &&
             (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar12 < *(uint *)(param_1 + 0x10))) {
            uVar5 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
              if (uVar5 + 0x28 <= uVar6) {
                bVar8 = *(byte *)(uVar5 + 10 + param_1);
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar5 + 0x38 <= uVar6) {
                bVar8 = *(byte *)(uVar5 + 10 + param_1);
                bVar3 = true;
              }
            }
            else if ((iVar1 == 0x42) && (uVar5 + 0x28 <= uVar6)) break;
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
    bVar3 = false;
    bVar15 = 0;
    if (*piVar14 == 0) {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_1 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) && (uVar2 = *(uint *)(param_1 + 0x10), uVar12 < uVar2)) {
            uVar6 = (ulonglong)uVar12;
            iVar1 = *(int *)((ulonglong)uVar12 + param_1);
            if (iVar1 == 0x40) {
LAB_1c0003c41:
              if (uVar6 + 0x28 <= (ulonglong)uVar2) {
                bVar15 = *(byte *)(uVar6 + 9 + param_1);
                break;
              }
            }
            else if (iVar1 == 0x41) {
              if (uVar6 + 0x38 <= (ulonglong)uVar2) {
                bVar15 = *(byte *)(uVar6 + 9 + param_1);
                bVar3 = true;
              }
            }
            else if (iVar1 == 0x42) goto LAB_1c0003c41;
            if (bVar3) break;
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_1 + 0x38));
      }
    }
  }
  else {
    bVar8 = *(byte *)(param_1 + 10);
    _Src = (void *)(param_1 + 0x48);
    bVar15 = *(byte *)(param_1 + 0xb);
  }
  if (_Src != (void *)0x0) {
    _Size = 0x10;
    if (bVar8 < 0x10) {
      _Size = (size_t)bVar8;
    }
    memcpy(param_2 + 7,_Src,_Size);
  }
  *param_2 = 3;
  uVar10 = 0;
  *(undefined2 *)(param_2 + 3) = 0x34;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = (undefined1)psVar7[4];
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 5);
  }
  *(undefined1 *)((longlong)param_2 + 0x11) = uVar10;
  uVar10 = 0;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = *(undefined1 *)((longlong)psVar7 + 9);
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 6);
  }
  *(undefined1 *)((longlong)param_2 + 0x12) = uVar10;
  uVar10 = 0;
  if (*(char *)(param_1 + 2) == '(') {
    if (((*(uint *)(param_1 + 0x34) != 0) &&
        (psVar7 = (short *)((ulonglong)*(uint *)(param_1 + 0x34) + param_1), psVar7 != (short *)0x0)
        ) && (*psVar7 == 1)) {
      uVar10 = (undefined1)psVar7[5];
    }
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 7);
  }
  *(undefined1 *)((longlong)param_2 + 0x13) = uVar10;
  *(byte *)(param_2 + 5) = bVar8;
  bVar8 = 0x14;
  if (bVar15 < 0x14) {
    bVar8 = bVar15;
  }
  *(byte *)((longlong)param_2 + 0x15) = bVar8;
  if (*(char *)(param_1 + 2) == '(') {
    uVar4 = *(undefined4 *)(param_1 + 0x3c);
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x10);
  }
  param_2[1] = param_2[1] | 1;
  param_2[6] = uVar4;
  if (*(char *)(param_1 + 2) == '(') {
    uVar12 = *(uint *)(param_1 + 0x18);
  }
  else {
    uVar12 = *(uint *)(param_1 + 0xc);
  }
  if ((uVar12 & 0x40) == 0) {
    *(byte *)((longlong)param_2 + 0x16) = ~((byte)uVar12 >> 6) & 2;
  }
  else {
    *(undefined1 *)((longlong)param_2 + 0x16) = 1;
  }
  if (*(char *)(param_1 + 2) == '(') {
    uVar10 = (undefined1)*(undefined4 *)(param_1 + 0x20);
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 8);
  }
  *(undefined1 *)((longlong)param_2 + 0x32) = uVar10;
  if (*(char *)(param_1 + 2) == '(') {
    uVar10 = *(undefined1 *)(param_1 + 0x26);
  }
  else {
    uVar10 = *(undefined1 *)(param_1 + 9);
  }
  *(undefined1 *)((longlong)param_2 + 0x33) = uVar10;
  param_2[0xd] = uVar12;
  if (*(char *)(param_1 + 2) == '(') {
    piVar14 = (int *)(param_1 + 0x28);
  }
  param_2[0xe] = *piVar14;
  if (*(char *)(param_1 + 2) == '\0') {
    uVar9 = *(undefined4 *)(param_1 + 0x40);
  }
  param_2[0xf] = uVar9;
  return;
}



===== StorChannelEnableSubChannels @ 1c0003de8 =====

ulonglong StorChannelEnableSubChannels(undefined8 *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  ushort uVar7;
  ulonglong local_res8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 uStack_70;
  int local_68 [3];
  undefined2 local_5c;
  
  local_res8 = local_res8 & 0xffffffff00000000;
  memset(local_68,0,0x40);
  local_68[1] = 1;
  local_5c = *(undefined2 *)(param_1 + 0x10);
  local_68[0] = 0xd;
  uVar2 = StorChannelSendSyntheticVstorPacket(*param_1,local_68);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar3 = 0;
    uVar2 = param_1[0x11];
    if (*(short *)(param_1 + 0x10) != 0) {
      do {
        if (uVar2 == 0) {
          iVar6 = -1;
        }
        else {
          uVar4 = 0;
          if (uVar2 != 0) {
            for (; (uVar2 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
            }
          }
          iVar6 = (int)uVar4;
          uVar2 = uVar2 & ~(1L << (uVar4 & 0x3f));
        }
        lVar5 = uVar3 + 9;
        local_98 = 0;
        uStack_90 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_res8 = param_1[lVar5 * 2];
        local_78 = (code *)0x0;
        uStack_70 = 0;
        if (local_res8 == 0) {
          uVar1 = VmbChannelAllocate(param_1[0xf],0,&local_res8);
          uVar4 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = VmbChannelAllocateForStorage(local_res8);
            uVar4 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              VmbChannelInitSetMaximumPacketSize(local_res8,0x40);
              VmbClientChannelInitSetRingBufferPageCount(local_res8,10,10);
              local_78 = StorChannelKmclEvtSubChannelStarted;
              uStack_80 = 0;
              uStack_70 = 0;
              uStack_90 = 0;
              local_88 = 0;
              local_98 = 0x3000000001;
              VmbChannelInitSetStateChangeCallbacks(local_res8,&local_98);
              VmbChannelInitSetPrimaryChannel(local_res8,*param_1,(int)uVar3 + 1);
              VmbChannelSetPointer(local_res8,param_1);
              VmbChannelSetAllowableDpcCpuUsage(local_res8);
              if (iVar6 != -1) {
                VmbClientChannelInitSetTargetProcessorIndex(local_res8);
              }
              param_1[lVar5 * 2] = local_res8;
              goto LAB_1c0003fb1;
            }
          }
        }
        else {
LAB_1c0003fb1:
          uVar1 = VmbChannelEnable();
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            param_1[lVar5 * 2] = 0;
          }
          else {
            uVar4 = 0;
            local_res8 = 0;
          }
        }
        if (local_res8 != 0) {
          VmbChannelCleanup();
        }
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        uVar7 = (short)uVar3 + 1;
        uVar3 = (ulonglong)uVar7;
      } while (uVar7 < *(ushort *)(param_1 + 0x10));
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== StorChannelEstablishCommunications @ 1c000402c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000433c) */

ulonglong StorChannelEstablishCommunications
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  short sVar1;
  ulonglong *puVar2;
  code *pcVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  uint uVar12;
  short *psVar13;
  undefined1 auStack_b8 [32];
  ulonglong local_98;
  int local_88 [3];
  uint local_7c;
  ushort local_78;
  byte local_74;
  int local_70;
  ulonglong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1);
  }
  puVar7 = (undefined8 *)VmbChannelGetPointer(param_1);
  memset(local_88,0,0x40);
  local_88[1] = 1;
  local_88[0] = 7;
  uVar8 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
  iVar5 = (int)uVar8;
  uVar8 = uVar8 & 0xffffffff;
  if (iVar5 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar11 = 0xc;
LAB_1c0004106:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
               &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,iVar5);
    }
  }
  else {
    uVar10 = 0;
    psVar13 = &g_StorChannelSupportedVersions;
    do {
      sVar1 = *psVar13;
      memset(local_88,0,0x40);
      local_88[1] = 1;
      local_88[0] = 9;
      local_7c = CONCAT22(local_7c._2_2_,sVar1);
      uVar9 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
      uVar8 = uVar9 & 0xffffffff;
      if (-1 < (int)uVar9) {
        if ((short)local_7c != sVar1) {
LAB_1c00044dc:
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(0x3a);
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        *(short *)(puVar7 + 0xc) = (short)local_7c;
        *(undefined2 *)(puVar7 + 0xe) = (&DAT_1c0007682)[uVar10 * 4];
        *(undefined2 *)((longlong)puVar7 + 0x72) = (&DAT_1c0007684)[uVar10 * 4];
        *(undefined1 *)((longlong)puVar7 + 0x74) = (&DAT_1c0007686)[uVar10 * 8];
        memset(local_88,0,0x40);
        local_88[1] = 1;
        local_88[0] = 10;
        if (0x5ff < *(ushort *)(puVar7 + 0xc)) {
          local_7c = local_7c | 1;
        }
        uVar10 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
        uVar8 = uVar10 & 0xffffffff;
        if ((int)uVar10 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0xf;
            goto LAB_1c00041eb;
          }
          goto LAB_1c000447a;
        }
        if (0x7fffff < local_70 - 1U) goto LAB_1c00044dc;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,local_70);
        }
        *(int *)((longlong)puVar7 + 0x54) = local_70;
        if ((*(ushort *)(puVar7 + 0xc) < 0x501) || ((local_74 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          *(uint *)(puVar7 + 10) = *(uint *)(puVar7 + 10) | 1;
          uVar4 = 0x3f;
          if (local_78 < 0x3f) {
            uVar4 = local_78;
          }
        }
        *(ushort *)((longlong)puVar7 + 0x4c) = uVar4;
        local_48 = 0;
        uStack_40 = 0;
        uVar6 = HviIsHypervisorMicrosoftCompatible();
        if ((char)uVar6 != '\0') {
          puVar2 = (ulonglong *)cpuid(0x40000003);
          local_48 = *puVar2;
        }
        if ((local_48 & 0x40000000000000) == 0) {
LAB_1c00043b6:
          uVar4 = *(ushort *)(puVar7 + 0x10);
          if (*(ushort *)((longlong)puVar7 + 0x4c) <= *(ushort *)(puVar7 + 0x10)) {
            uVar4 = *(ushort *)((longlong)puVar7 + 0x4c);
          }
          *(ushort *)(puVar7 + 0x10) = uVar4;
          if ((*(char *)((longlong)puVar7 + 0x84) != '\0') &&
             (local_98 = (ulonglong)*(ushort *)((longlong)puVar7 + 0x82),
             uVar4 != *(ushort *)((longlong)puVar7 + 0x82))) {
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0xbd,param_1,puVar7,uVar4);
          }
          if (uVar4 != 0) {
            uVar10 = StorChannelEnableSubChannels(puVar7);
            uVar8 = uVar10 & 0xffffffff;
            if ((int)uVar10 < 0) goto LAB_1c000447a;
          }
          memset(local_88,0,0x40);
          local_88[1] = 1;
          local_88[0] = 8;
          uVar10 = StorChannelSendSyntheticVstorPacket(param_1,local_88);
          uVar8 = uVar10 & 0xffffffff;
          if (-1 < (int)uVar10) {
            uVar8 = 0;
            goto LAB_1c000447a;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000447a;
          uVar11 = 0x12;
        }
        else {
          uVar12 = VmbChannelAllocateBounceBuffer(param_1);
          uVar8 = (ulonglong)uVar12;
          if (-1 < (int)uVar12) goto LAB_1c00043b6;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000447a;
          uVar11 = 0x11;
        }
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                 &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,(int)uVar8);
        goto LAB_1c000447a;
      }
      if ((int)uVar9 != -0x3fffffa7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar8;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000447a;
        uVar11 = 0xd;
LAB_1c00041eb:
        iVar5 = (int)uVar8;
        goto LAB_1c0004106;
      }
      uVar12 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar12;
      psVar13 = psVar13 + 4;
    } while (uVar12 < 6);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids);
    }
  }
LAB_1c000447a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,(int)uVar8);
  }
  return uVar8;
}



===== StorChannelKmclEvtProcessPacket @ 1c00044f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorChannelKmclEvtProcessPacket
               (undefined8 param_1,undefined8 param_2,int *param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  int local_48 [16];
  
  memset(local_48,0,0x40);
  if (param_4 < 0x40) {
    memcpy(local_48,param_3,(ulonglong)param_4);
    param_3 = local_48;
  }
  iVar1 = *param_3;
  if (iVar1 != 0xb) {
    if (iVar1 == 0xc) {
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\x02') {
        VmbChannelPacketDeferToPassive(param_2);
        return;
      }
    }
    else if (iVar1 != 0xe) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,iVar1);
      }
      goto LAB_1c00045d3;
    }
  }
  lVar3 = VmbChannelGetPointer(param_1);
  if (*(code **)(lVar3 + 0x68) != (code *)0x0) {
    (**(code **)(lVar3 + 0x68))(param_1,param_3);
  }
LAB_1c00045d3:
  VmbChannelPacketComplete(param_2,0,0);
  return;
}



===== StorChannelKmclEvtSubChannelStarted @ 1c0004610 =====

void StorChannelKmclEvtSubChannelStarted(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong *plVar3;
  
  puVar1 = (undefined8 *)VmbChannelGetPointer();
  ExAcquireFastMutex(puVar1 + 1);
  uVar2 = 0;
  plVar3 = puVar1 + 0x12;
  do {
    if (*plVar3 == param_1) {
      *(undefined1 *)(puVar1 + (ulonglong)uVar2 * 2 + 0x13) = 1;
      StorChannelReevaluateSubChannels(puVar1);
      break;
    }
    uVar2 = uVar2 + 1;
    plVar3 = plVar3 + 2;
  } while (uVar2 < 0x3f);
  ExReleaseFastMutex(puVar1 + 1);
  return;
}



===== StorChannelKmclPacketCompletionRoutine @ 1c00046a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorChannelKmclPacketCompletionRoutine
               (undefined8 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  puVar6 = auStack_38;
  if ((-1 < param_2) && ((param_3 == (undefined4 *)0x0 || (puVar6 = auStack_38, param_4 < 0x30)))) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x3a);
    puVar6 = auStack_30;
  }
  *(undefined8 *)(puVar6 + -8) = 0x1c00046d9;
  lVar2 = VmbPacketGetPointer();
  *(undefined8 *)(puVar6 + -8) = 0x1c00046eb;
  uVar3 = VmbPacketGetChannel(param_1);
  *(undefined8 *)(puVar6 + -8) = 0x1c00046fa;
  puVar4 = (undefined8 *)VmbChannelGetPointer(uVar3);
  pcVar1 = *(code **)(lVar2 + 8);
  if (pcVar1 != (code *)0x0) {
    uVar3 = *puVar4;
    if (param_2 < 0) {
      param_3 = (undefined4 *)0x0;
      uVar5 = 2;
    }
    else {
      uVar5 = *param_3;
    }
    *(undefined8 *)(puVar6 + -8) = 0x1c0004728;
    (*pcVar1)(uVar3,uVar5,param_3,lVar2);
  }
  return;
}



===== StorChannelReevaluateSubChannels @ 1c0004744 =====

void StorChannelReevaluateSubChannels(undefined8 *param_1)

{
  undefined8 *_Base;
  undefined8 *_Dst;
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  size_t _Size;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  ushort *_Base_00;
  
  _Base = param_1 + 0xa2;
  _Dst = param_1 + 0x92;
  *_Base = *param_1;
  uVar4 = VmbChannelGetTargetProcessorIndex();
  uVar9 = 0;
  *(undefined4 *)(param_1 + 0xa3) = uVar4;
  uVar13 = 0;
  uVar8 = 1;
  if (*(short *)(param_1 + 0x10) != 0) {
    do {
      if (*(char *)(param_1 + uVar13 * 2 + 0x13) != '\0') {
        _Base[(ulonglong)uVar8 * 2] = param_1[(uVar13 + 9) * 2];
        uVar4 = VmbChannelGetTargetProcessorIndex();
        *(undefined4 *)(param_1 + (ulonglong)uVar8 * 2 + 0xa3) = uVar4;
        uVar8 = uVar8 + 1;
      }
      uVar14 = (int)uVar13 + 1;
      uVar13 = (ulonglong)uVar14;
    } while (uVar14 < *(ushort *)(param_1 + 0x10));
  }
  qsort(_Base,(ulonglong)uVar8,0x10,StorChannelCompareChannelByProcessorIndex);
  uVar14 = KeQueryMaximumProcessorCountEx(0xffff);
  uVar13 = (ulonglong)uVar14;
  if (param_1[0x11] == 0) {
    if (uVar14 != 0) {
      lVar15 = 0;
      do {
        uVar6 = (uVar9 * uVar8) / uVar13;
        *(undefined8 *)(lVar15 + param_1[0x90]) = _Base[uVar6 * 2];
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,&WPP_GLOBAL_Control,
                    *(undefined4 *)(param_1 + uVar6 * 2 + 0xa3),(char)uVar9);
        }
        uVar9 = uVar9 + 1;
        lVar15 = lVar15 + 8;
      } while (uVar9 < uVar14);
    }
  }
  else {
    _Base_00 = (ushort *)param_1[0x91];
    uVar9 = 0;
    uVar12 = 0;
    if (uVar14 != 0) {
      do {
        uVar11 = uVar9;
        while (uVar11 = uVar11 + 1, uVar11 < uVar8) {
          uVar7 = uVar12 - *(int *)(param_1 + (ulonglong)uVar11 * 2 + 0xa3);
          uVar5 = uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3);
          uVar10 = *(int *)(param_1 + (ulonglong)uVar11 * 2 + 0xa3) - uVar12;
          if (-1 < (int)uVar7) {
            uVar10 = uVar7;
          }
          uVar7 = *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3) - uVar12;
          if (-1 < (int)uVar5) {
            uVar7 = uVar5;
          }
          if (uVar7 <= uVar10) break;
          uVar9 = uVar9 + 1;
        }
        uVar6 = (ulonglong)uVar12;
        _Base_00[uVar6 * 3] = (ushort)uVar12;
        _Base_00[uVar6 * 3 + 1] = (ushort)uVar9;
        uVar2 = (ushort)(uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3));
        uVar3 = -uVar2;
        if (-1 < (int)(uVar12 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3))) {
          uVar3 = uVar2;
        }
        uVar12 = uVar12 + 1;
        _Base_00[uVar6 * 3 + 2] = uVar3;
      } while (uVar12 < uVar14);
    }
    qsort(_Base_00,uVar13,6,StorChannelCompareProcessorByDistanceDescending);
    _Size = (ulonglong)uVar8 * 2;
    memset(_Dst,0,_Size);
    if (uVar14 != 0) {
      do {
        uVar6 = (ulonglong)_Base_00[1];
        uVar3 = *_Base_00;
        uVar9 = (uint)_Base_00[1];
        while (uVar9 = uVar9 + 1, uVar9 < uVar8) {
          uVar12 = (uint)uVar3 - *(int *)(param_1 + uVar6 * 2 + 0xa3);
          _Size = (size_t)uVar12;
          uVar14 = -((uint)uVar3 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3));
          if ((int)uVar14 < 0) {
            uVar14 = (uint)uVar3 - *(int *)(param_1 + (ulonglong)uVar9 * 2 + 0xa3);
          }
          uVar11 = -uVar12;
          if ((int)-uVar12 < 0) {
            uVar11 = uVar12;
          }
          if ((uVar11 < uVar14) ||
             (*(ushort *)((longlong)_Dst + uVar6 * 2) <=
              *(ushort *)((longlong)_Dst + (ulonglong)uVar9 * 2))) break;
          uVar6 = (ulonglong)((int)uVar6 + 1);
        }
        psVar1 = (short *)((longlong)_Dst + uVar6 * 2);
        *psVar1 = *psVar1 + 1;
        *(undefined8 *)(param_1[0x90] + (ulonglong)uVar3 * 8) = _Base[uVar6 * 2];
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,_Size,
                    *(undefined4 *)(param_1 + uVar6 * 2 + 0xa3),(char)uVar3);
        }
        _Base_00 = _Base_00 + 3;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
  }
  return;
}



===== StorChannelSendSrbRequest @ 1c0004a5c =====

void StorChannelSendSrbRequest
               (undefined8 param_1,uint param_2,longlong param_3,longlong param_4,undefined8 param_5
               ,longlong *param_6,undefined8 param_7,longlong param_8)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_68 [3];
  ushort local_5c;
  byte local_53;
  char local_4c;
  
  memset(local_68,0,0x40);
  if (*(char *)(param_3 + 2) == '(') {
    lVar6 = *(longlong *)(param_3 + 0x40);
    uVar8 = *(undefined4 *)(param_3 + 0x3c);
    uVar7 = *(uint *)(param_3 + 0x18);
  }
  else {
    lVar6 = *(longlong *)(param_3 + 0x18);
    uVar8 = *(undefined4 *)(param_3 + 0x10);
    uVar7 = *(uint *)(param_3 + 0xc);
  }
  lVar4 = VmbChannelGetPointer(param_1);
  uVar2 = *(undefined8 *)(*(longlong *)(lVar4 + 0x480) + (ulonglong)param_2 * 8);
  StorChannelCopySrbToPacket(param_3,local_68);
  param_6[1] = (longlong)StorFilterCompletion;
  param_6[2] = param_8;
  param_6[3] = param_3;
  *param_6 = param_4;
  uVar1 = *(undefined2 *)(lVar4 + 0x70);
  if (*(ushort *)(lVar4 + 0x72) < local_5c) {
    local_5c = *(ushort *)(lVar4 + 0x72);
  }
  if (*(byte *)(lVar4 + 0x74) < local_53) {
    local_53 = *(byte *)(lVar4 + 0x74);
  }
  uVar3 = VmbChannelSizeofPacket(uVar2);
  VmbPacketInitialize(uVar2,param_7,uVar3);
  VmbPacketSetCompletionRoutine(param_7,StorChannelKmclPacketCompletionRoutine);
  VmbPacketSetPointer(param_7);
  iVar5 = 0;
  if (param_4 == 0) {
    VmbPacketSend(param_7,local_68,uVar1,0,1);
  }
  else {
    if ((((((local_4c == '\b') || (local_4c == '\n')) || (local_4c == '(')) ||
         ((local_4c == '*' || (local_4c == -0x78)))) ||
        ((local_4c == -0x76 || ((local_4c == -0x58 || (local_4c == -0x56)))))) &&
       (((ulonglong)*(uint *)(param_4 + 0x2c) + *(longlong *)(param_4 + 0x20) != lVar6 &&
        (((*(byte *)(param_4 + 10) & 1) == 0 || (*(longlong *)(param_4 + 0x18) != lVar6)))))) {
      iVar5 = ((int)lVar6 - *(int *)(param_4 + 0x20)) - *(uint *)(param_4 + 0x2c);
    }
    if ((uVar7 & 0x40) == 0) {
      uVar3 = 3;
      if ((uVar7 & 0x80) != 0) {
        uVar3 = 0x13;
      }
    }
    else {
      uVar3 = 0xb;
    }
    VmbPacketSendWithExternalMdl(param_7,local_68,uVar1,param_4,iVar5,uVar8,uVar3);
  }
  return;
}



===== StorChannelSendSyntheticVstorPacket @ 1c0004c78 =====

ulonglong StorChannelSendSyntheticVstorPacket(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint local_res18 [4];
  
  lVar1 = VmbChannelGetPointer();
  local_res18[0] = (uint)*(ushort *)(lVar1 + 0x70);
  uVar2 = VmbChannelSendSynchronousRequest
                    (param_1,param_2,*(ushort *)(lVar1 + 0x70),0,1,param_2,local_res18,0);
  if (-1 < (int)uVar2) {
    if (local_res18[0] == *(ushort *)(lVar1 + 0x70)) {
      uVar2 = 0xc000009d;
      if (*param_2 == 1) {
        uVar2 = (ulonglong)(uint)param_2[2];
      }
    }
    else {
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== WPP_SF_dd @ 1c0004d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_q @ 1c0004d6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,0xb,&local_res20,8,0);
  return;
}



===== HviIsAnyHypervisorPresent @ 1c0004db8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004dec) */
/* WARNING: Removing unreachable block (ram,0x0001c0004ddb) */

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



===== HviIsHypervisorMicrosoftCompatible @ 1c0004e14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004e41) */

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



===== _guard_check_icall @ 1c0004e80 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004e98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0004ebc =====

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



===== wcscmp @ 1c0004f26 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004f26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 1c0004f40 =====

/* WARNING: Removing unreachable block (ram,0x0001c0004faa) */
/* WARNING: Removing unreachable block (ram,0x0001c0004f59) */
/* WARNING: Removing unreachable block (ram,0x0001c0004f4a) */

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



===== __security_check_cookie @ 1c0005010 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0005050 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0005080 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0005080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00050b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0005100 =====

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



===== memset @ 1c0005400 =====

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



===== __memset_repmovs @ 1c0005540 =====

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



===== __memset_query @ 1c00055c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005640 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005780 =====

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



===== __memset_spec_plain @ 1c0005800 =====

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



===== StorFilterConnectToIdeChannel @ 1c000b008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000b240) */

ulonglong StorFilterConnectToIdeChannel(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined1 auStackY_1c8 [32];
  undefined4 local_170;
  undefined8 local_16c;
  uint local_160;
  ushort local_15c;
  undefined2 local_15a;
  undefined8 local_158;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined1 local_138 [4];
  char acStack_134 [16];
  uint local_124;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_150 = 0x32412632;
  uStack_14c = 0x44a286cb;
  uStack_148 = 0xd1505c9b;
  uStack_144 = 0xf5547341;
  local_16c = 0;
  local_158 = 0;
  local_170 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,*param_1);
  uVar8 = 0xc;
  uVar4 = StorInvokeIoctl(uVar3,0x2d1400,&local_170,0xc,local_138,0x10c);
  uVar7 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,(int)uVar4);
    }
  }
  else if ((byte)(acStack_134[local_124] - 0x30U) < 2) {
    bVar6 = acStack_134[local_124] - 0x30;
    *(byte *)((longlong)param_1 + 0x39) = bVar6;
    if ((bVar6 < 2) && (*(byte *)((longlong)param_1 + 0x42) < 2)) {
      local_160 = (uint)bVar6;
      local_15a = 0x8899;
      local_15c = (ushort)*(byte *)((longlong)param_1 + 0x42);
      lVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*param_1);
      uVar1 = StorChannelOpen(lVar5,&local_150,(longlong)param_1,uVar8,(longlong)&local_160);
      uVar7 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,uVar1);
        }
      }
      else {
        iVar2 = VmbChannelSizeofPacket(0);
        lVar5 = ExAllocatePool2(0x40,iVar2 + 0x40,0x52746c46);
        param_1[0x28] = lVar5;
        if (lVar5 == 0) {
          uVar7 = 0xc000009a;
        }
        else {
          ExInitializeNPagedLookasideList(param_1 + 0x18,0,0,ExDefaultNonPagedPoolType | 0x200);
          param_1[1] = 0;
          uVar7 = 0;
        }
      }
    }
    else {
      uVar7 = 0xc0000225;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids);
    }
    uVar7 = 0xc0000001;
  }
  return uVar7;
}



===== StorFilterEvtAddDevice @ 1c000b2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 StorFilterEvtAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined4 *_Dst;
  undefined *puVar9;
  undefined2 uVar10;
  code *pcVar11;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  ulonglong uVar12;
  undefined8 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  code *local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined *local_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_90;
  code *local_80;
  
  _Dst = &local_c8;
  local_d8 = (undefined *)((ulonglong)local_d8 & 0xffffffff00000000);
  local_c4 = 0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  local_f8 = (code *)0x0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_res10 = param_2;
  memset(_Dst,0,0x8c);
  iVar2 = g_DriverDisabledEventLogged;
  local_118 = 0;
  local_res18[0] = 2;
  local_res20[0] = 7;
  local_110 = 0;
  if (g_DriverState != 3) {
    if (g_DriverState != 1) {
      return 0;
    }
    LOCK();
    g_DriverDisabledEventLogged = 1;
    UNLOCK();
    if (iVar2 != 0) {
      g_DriverDisabledEventLogged = 1;
      return 0;
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 8) == 0) {
      g_DriverDisabledEventLogged = 1;
      return 0;
    }
    McTemplateK0_EtwWriteTransfer(_Dst);
    return 0;
  }
  pcVar11 = (code *)0xf;
  puVar9 = WdfDriverGlobals;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,param_2,0xf,1,0,&local_118);
  if (-1 < iVar2) {
    pwVar3 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_118,0);
    iVar2 = wcscmp(pwVar3,L"IDE");
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_118);
    if (iVar2 != 0) {
      return 0;
    }
    puVar7 = &local_118;
    pcVar11 = (code *)0x1;
    puVar9 = WdfDriverGlobals;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x3f8))(WdfDriverGlobals,local_res10,1,1,0,puVar7);
    if (-1 < iVar2) {
      pwVar3 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_118,0);
      pwVar3 = wcsstr(pwVar3,L"Virtual_HD");
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_118);
      if (pwVar3 == (wchar_t *)0x0) {
        return 0;
      }
      (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals,local_res10);
      (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_res10,0x22);
      pcVar11 = StorFilterEvtProcessScsiIrp;
      uVar12 = (ulonglong)puVar7 & 0xffffffff00000000;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                        (WdfDriverGlobals,local_res10,StorFilterEvtProcessScsiIrp,0xf,0,uVar12);
      if (iVar2 < 0) {
        puVar9 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000b567;
        uVar10 = 0x14;
      }
      else {
        pcVar11 = StorFilterEvtProcessDeviceIoCtrlIrp;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                          (WdfDriverGlobals,local_res10,StorFilterEvtProcessDeviceIoCtrlIrp,0xe,0,
                           uVar12 & 0xffffffff00000000);
        if (iVar2 < 0) {
          puVar9 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000b567;
          uVar10 = 0x15;
        }
        else {
          pcVar11 = StorFilterEvtProcessPowerIrp;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                            (WdfDriverGlobals,local_res10,StorFilterEvtProcessPowerIrp,0x16,
                             local_res18,1);
          if (iVar2 < 0) {
            puVar9 = WPP_GLOBAL_Control;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000b567;
            uVar10 = 0x16;
          }
          else {
            pcVar11 = StorFilterEvtProcessPnPIrp;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x248))
                              (WdfDriverGlobals,local_res10,StorFilterEvtProcessPnPIrp,0x1b,
                               local_res20,1);
            if (iVar2 < 0) {
              puVar9 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000b567;
              uVar10 = 0x17;
            }
            else {
              memset(&local_c8,0,0x90);
              local_80 = StorFilterEvtSelfManagedIoInit;
              local_90 = StorFilterEvtSelfManagedIoCleanup;
              local_c8 = 0x90;
              (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,&local_c8);
              pcVar11 = (code *)&local_108;
              local_d8 = PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018;
              uStack_104 = 0;
              uStack_100 = 0;
              local_f8 = StorFilterEvtDestroyDevice;
              uStack_fc = 0;
              local_e8 = 0;
              uStack_e0 = 0;
              local_108 = 0x38;
              uStack_f0 = 0x100000001;
              iVar2 = (**(code **)(WdfFunctions_01015 + 600))
                                (WdfDriverGlobals,&local_res10,pcVar11,&local_110);
              if (-1 < iVar2) {
                uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,local_110);
                lVar5 = IoAllocateWorkItem(uVar4);
                if ((((lVar5 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                           &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar2);
                }
                uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,local_110);
                lVar6 = IoAllocateWorkItem(uVar4);
                if (((lVar6 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                   (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                           &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar2);
                }
                puVar7 = (undefined8 *)
                         (**(code **)(WdfFunctions_01015 + 0x650))
                                   (WdfDriverGlobals,local_110,
                                    PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
                *puVar7 = local_110;
                puVar7[0x29] = lVar5;
                puVar7[0x2b] = lVar6;
                if ((lVar5 == 0) || (uVar1 = 1, lVar6 == 0)) {
                  uVar1 = 0;
                }
                *(undefined1 *)(puVar7 + 7) = uVar1;
                ExInitializePushLock(puVar7 + 0x2c);
                puVar8 = puVar7 + 10;
                puVar7[9] = 0;
                lVar5 = 5;
                do {
                  puVar8[1] = puVar8;
                  *puVar8 = puVar8;
                  puVar8 = puVar8 + 2;
                  lVar5 = lVar5 + -1;
                } while (lVar5 != 0);
                puVar7[3] = 0;
                return 0;
              }
              puVar9 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000b567;
              uVar10 = 0x18;
            }
          }
        }
      }
      puVar9 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      pcVar11 = (code *)&WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids;
      WPP_SF_D(puVar9,uVar10,&WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar2);
    }
  }
LAB_1c000b567:
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 8) != 0) {
    McTemplateK0d_EtwWriteTransfer(puVar9,&SFLT_FILTER_INIT_DEVICE_FAILURE,pcVar11,iVar2);
  }
  return 0;
}



===== StorFilterEvtDestroyDevice @ 1c000b930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterEvtDestroyDevice(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  if (*(longlong *)(lVar1 + 0x148) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x148) = 0;
  }
  if (*(longlong *)(lVar1 + 0x158) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x158) = 0;
  }
  return;
}



===== StorFilterEvtDriverUnload @ 1c000b9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterEvtDriverUnload(undefined8 param_1)

{
  undefined *puVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
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
  McGenEventUnregister_EtwUnregister();
  return;
}



===== StorFilterEvtSelfManagedIoCleanup @ 1c000ba90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StorFilterEvtSelfManagedIoCleanup(undefined8 param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  *(undefined1 *)(lVar1 + 0x168) = 0;
  if (*(longlong *)(lVar1 + 8) != 0) {
    plVar2 = (longlong *)VmbChannelGetPointer();
    StorChannelCloseInternal(plVar2);
    *(undefined8 *)(lVar1 + 8) = 0;
    ExDeleteNPagedLookasideList(lVar1 + 0xc0);
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x140),0);
    *(undefined8 *)(lVar1 + 0x140) = 0;
  }
  return;
}



===== StorFilterEvtSelfManagedIoInit @ 1c000bb30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 StorFilterEvtSelfManagedIoInit(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_STOR_FILTER_EXTENSION_TYPE_INFO_1c0008018);
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_38 = 0;
  local_20 = 0;
  uStack_18 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  local_40 = 1;
  uVar4 = StorInvokeIoctl(uVar3,0x2d1400,&local_40,0xc,&local_30,0x20);
  iVar1 = (int)uVar4;
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar1);
    }
LAB_1c000bc8e:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000bd15;
    uVar5 = 0xf;
  }
  else {
    uVar4 = StorInvokeIoctl(uVar3,0x41018,0,0,&local_48,8);
    iVar1 = (int)uVar4;
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar1);
      }
      goto LAB_1c000bc8e;
    }
    *(uint *)(puVar2 + 2) = (uint)(byte)uStack_18;
    *(undefined8 *)((longlong)puVar2 + 0x3c) = local_48;
    if ((byte)uStack_18 != 3) {
      iVar1 = -0x3fffff1b;
      goto LAB_1c000bd15;
    }
    uVar4 = StorFilterConnectToIdeChannel(puVar2);
    iVar1 = (int)uVar4;
    if (((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    goto LAB_1c000bd15;
    uVar5 = 0x10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar1);
LAB_1c000bd15:
  StorFilterLogActiveEvent((byte)((uint)iVar1 >> 0x1f) ^ 1,(char)iVar1,(longlong)puVar2 + 0x3c);
  return 0;
}



===== StorFilterIsDriverActive @ 1c000bd54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int StorFilterIsDriverActive(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  int local_res18 [2];
  longlong local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,param_1,0x20019,0,&local_res20);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,L"Enabled");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res20,&local_18,local_res18);
    if (iVar1 < 0) {
      *param_2 = 0;
    }
    else {
      *param_2 = local_res18[0] != 0;
    }
    iVar1 = 0;
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== WppInitKm @ 1c000be3c =====

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



===== WppLoadTracingSupport @ 1c000becc =====

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



===== WppTraceCallback @ 1c000c010 =====

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



===== StorChannelCloseInternal @ 1c000c298 =====

void StorChannelCloseInternal(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  if (*param_1 != 0) {
    VmbChannelDisable();
    plVar2 = param_1 + 0x12;
    lVar1 = 0x3f;
    do {
      if (*plVar2 != 0) {
        VmbChannelCleanup();
      }
      plVar2 = plVar2 + 2;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    VmbChannelCleanup(*param_1);
  }
  ExFreePoolWithTag(param_1,0x63736d56);
  return;
}



===== StorChannelOpen @ 1c000c324 =====

int StorChannelOpen(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                   longlong param_5)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  longlong local_res20;
  longlong *in_stack_00000048;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  code *pcStack_30;
  
  local_res20 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  pcStack_30 = (code *)0x0;
  uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
  plVar3 = (longlong *)ExAllocatePool2(0x40,uVar1 * 0xe + 0x910,0x63736d56);
  if (plVar3 == (longlong *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined4 *)(plVar3 + 1) = 1;
    plVar3[0x90] = (longlong)(plVar3 + 0x122);
    plVar3[2] = 0;
    plVar3[0x91] = (longlong)(plVar3 + 0x122 + uVar1);
    *(undefined4 *)(plVar3 + 3) = 0;
    KeInitializeEvent(plVar3 + 4,1);
    iVar2 = VmbChannelAllocate(param_1,0,&local_res20);
    if ((-1 < iVar2) && (iVar2 = VmbChannelAllocateForStorage(local_res20), -1 < iVar2)) {
      VmbChannelInitSetBounceBufferSizes(local_res20,0,0x200000,0);
      VmbChannelInitSetMaximumPacketSize(local_res20,0x40);
      VmbClientChannelInitSetRingBufferPageCount(local_res20,10,10);
      if (param_5 != 0) {
        VmbClientChannelInitSetTargetPnp(local_res20,param_2,param_5,0);
      }
      VmbChannelInitSetProcessPacketCallbacks(local_res20,StorChannelKmclEvtProcessPacket,0);
      pcStack_30 = StorFilterStorageChannelPostStarted;
      uStack_50 = 0;
      local_48 = 0;
      local_58 = 0x3000000001;
      uStack_40 = 0;
      local_38 = 0;
      VmbChannelInitSetStateChangeCallbacks(local_res20,&local_58);
      VmbChannelInitSetFlags(local_res20,2);
      *plVar3 = local_res20;
      plVar3[8] = param_3;
      plVar3[0xd] = 0;
      *(undefined4 *)(plVar3 + 0xe) = 0x240030;
      *(undefined1 *)((longlong)plVar3 + 0x74) = 0x12;
      plVar3[0xf] = param_1;
      *(undefined2 *)(plVar3 + 0x10) = 0;
      plVar3[0x11] = 0;
      StorChannelReevaluateSubChannels(plVar3);
      VmbChannelSetPointer(local_res20,plVar3);
      VmbChannelSetAllowableDpcCpuUsage(local_res20,100);
      *(undefined1 *)((longlong)plVar3 + 0x75) = 1;
      iVar2 = VmbChannelEnable(local_res20);
      if (-1 < iVar2) {
        *in_stack_00000048 = local_res20;
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_fae18269a3c73a60ae52ad52de4ed304_Traceguids,iVar2);
      }
    }
    StorChannelCloseInternal(plVar3);
  }
  return iVar2;
}



===== StorInvokeIoctl @ 1c000c5d8 =====

ulonglong StorInvokeIoctl(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                         undefined4 param_4,undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,1,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== __security_init_cookie @ 1c000d008 =====

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



===== DriverEntry @ 1c000d040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198;
  undefined8 *local_190;
  char local_178 [8];
  undefined8 local_170;
  undefined8 local_168;
  code *local_160;
  code *local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  uint local_144;
  uint local_140;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_168 = 0x20;
  iVar3 = 0;
  local_14c = 0x576c6656;
  local_170 = 0;
  local_160 = StorFilterEvtAddDevice;
  local_190 = &local_170;
  local_158 = StorFilterEvtDriverUnload;
  local_198 = &local_168;
  local_150 = 0;
  local_178[0] = '\0';
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar1 < 0) {
    DbgPrint("storflt!WdfDriverCreate failed with 0x%x\n",iVar1);
  }
  else {
    _WPP_MAIN_CB = 0;
    DAT_1c0008408 = &WPP_ThisDir_CTLGUID_StorvscTraceGuid;
    DAT_1c0008410 = 0;
    _DAT_1c0008420 = 0;
    _DAT_1c0008428 = 1;
    WppLoadTracingSupport();
    _DAT_1c0008420 = 0;
    WppInitKm();
    puVar4 = (undefined *)0x110;
    memset(&local_144,0,0x110);
    local_148 = 0x114;
    iVar1 = RtlGetVersion(&local_148);
    if ((-1 < iVar1) && ((6 < local_144 || ((local_144 == 6 && (1 < local_140)))))) {
      ExDefaultNonPagedPoolType = 0x200;
    }
    if (*(int *)InitSafeBootMode_exref == 0) {
      iVar1 = StorFilterIsDriverActive(param_2,local_178);
      if (iVar1 < 0) {
        puVar2 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          puVar4 = &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids;
          WPP_SF_D(puVar2,0x1c,&WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar1);
        }
        iVar3 = iVar1;
        if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Storage_FilterEnableBits & 8) != 0) {
          McTemplateK0d_EtwWriteTransfer(puVar2,&SFLT_FILTER_INIT_FAILURE,puVar4,iVar1);
        }
      }
      else if (local_178[0] == '\0') {
        MmPageEntireDriver(DriverEntry);
        g_DriverState = 1;
      }
      else {
        McGenEventRegister_EtwRegister();
        g_DriverState = 3;
      }
    }
    else {
      g_DriverState = 2;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_330d2e2773c93e7366a6cfdabc3e7f83_Traceguids,iVar3);
    }
    iVar1 = 0;
  }
  return iVar1;
}


