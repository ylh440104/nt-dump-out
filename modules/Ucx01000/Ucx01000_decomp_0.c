
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



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

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
  *param_6 = PTR_DAT_140033048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140033048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140033060,&local_18,0,0,param_5,param_6);
  return;
}



===== UsbDevice_EvtFailMgmtIoInternalDeviceControl @ 140001120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_EvtFailMgmtIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined1 auStackY_68 [32];
  undefined1 uVar4;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  uVar4 = (undefined1)param_2;
  if (param_5 == 0x220003) {
    local_18 = 0;
    lStack_30 = 0;
    local_38 = 0x28;
    local_28 = 0;
    uStack_20 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
    lVar1 = lStack_30;
    if (*(short *)(lStack_30 + 2) == 0x36) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x4e,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar4);
      }
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),
                         PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      if ((*(uint *)(lVar1 + 0x198) & 1) == 0) goto LAB_14000129a;
      *(uint *)(lVar1 + 0x198) = *(uint *)(lVar1 + 0x198) & 0xfffffffe;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x4f,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,
                        (char)*(short *)(lStack_30 + 2));
    }
    uVar2 = 0xc000000e;
    goto LAB_1400013a3;
  }
  if (param_5 == 0x49101b) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x4b;
LAB_140001271:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar3,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar4);
    }
  }
  else {
    if (param_5 != 0x49102b) {
      if (param_5 == 0x491037) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x4d,
                            &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar4);
        }
        local_18 = 0;
        lStack_30 = 0;
        local_38 = 0x28;
        local_28 = 0;
        uStack_20 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
        uVar2 = -(uint)(*(int *)(lStack_30 + 0x18) != 0) & 0xc000000e;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x50,
                            &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_5);
        }
        uVar2 = 0xc0000010;
      }
      goto LAB_1400013a3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x4c;
      goto LAB_140001271;
    }
  }
LAB_14000129a:
  uVar2 = 0;
LAB_1400013a3:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  return;
}



===== RootHub_Pdo_EvtDeviceEnableWakeAtBus @ 1400013f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RootHub_Pdo_EvtDeviceEnableWakeAtBus(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  uVar2 = 0;
  uVar3 = (undefined1)*(longlong *)(lVar1 + 0x10);
  if (*(char *)(*(longlong *)(lVar1 + 0x10) + 0x3f0) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x4a,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar3);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x49,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar3);
    }
    uVar2 = 0xc000000e;
  }
  return uVar2;
}



===== WPP_RECORDER_SF_q @ 1400014b8 =====

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



===== DefaultEndpoint_Create @ 1400015c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DefaultEndpoint_Create
                    (undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined4 local_b8;
  longlong local_a0;
  undefined1 local_38;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar4 = *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28);
  memset(&local_c8,0,0xa8);
  local_c8 = 0x74697045;
  local_b8 = 1;
  local_c4 = 2;
  local_38 = 1;
  local_c0 = param_2;
  uVar2 = (**(code **)(lVar3 + 200))(uVar4,param_2,param_3,&local_c8);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,10,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar2);
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_a0,
                       PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      *param_4 = local_a0;
      uVar4 = WdfDriverGlobals;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_a0,
                         PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
      Etw_UcxEndpointCreate(uVar4,lVar3);
      return uVar5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xb,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar3);
    }
    uVar5 = 0xc00000e5;
    if (*(char *)(*(longlong *)(lVar3 + 0x40) + 0x3f9) != '\0') {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
  }
  *param_4 = 0;
  if (local_a0 != 0) {
    Endpoint_Delete(param_1,param_2,local_a0);
  }
  return uVar5;
}



===== Endpoint_Create @ 1400017a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Endpoint_Create(undefined8 param_1,undefined8 param_2,undefined4 *param_3,
                         undefined4 param_4,byte *param_5,longlong *param_6)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined2 local_c0;
  undefined1 local_be;
  undefined4 local_bd;
  undefined2 local_b9;
  longlong local_b0;
  undefined1 local_48;
  undefined8 local_47;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar4 = *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28);
  memset(&local_d8,0,0xa8);
  local_c8 = 3;
  bVar5 = *(byte *)((longlong)param_3 + 3) & 3;
  local_d8 = 0x74697045;
  if (bVar5 != 1) {
    if (bVar5 == 2) {
      local_c8 = 2;
    }
    else {
      local_c8 = 1;
      if (bVar5 == 3) {
        local_c8 = 4;
      }
    }
  }
  if (*(short *)(param_3 + 1) == 0) {
    local_d4 = 1;
  }
  local_c4 = *param_3;
  local_c0 = *(undefined2 *)(param_3 + 1);
  local_be = *(undefined1 *)((longlong)param_3 + 6);
  local_48 = 1;
  if (param_5 != (byte *)0x0) {
    local_bd = *(undefined4 *)param_5;
    local_b9 = *(undefined2 *)(param_5 + 4);
    if ((bVar5 == 1) && ((char)param_5[3] < '\0')) {
      local_47 = *(undefined8 *)(param_5 + *param_5);
    }
  }
  local_d0 = param_2;
  uVar2 = (**(code **)(lVar3 + 0xd0))(uVar4,param_2,param_3,param_4,param_5,&local_d8);
  uVar6 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xc,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar2);
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_b0,
                       PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      KeInitializeSpinLock(lVar3 + 0x300);
      *param_6 = local_b0;
      uVar4 = WdfDriverGlobals;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_b0,
                         PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
      Etw_UcxEndpointCreate(uVar4,lVar3);
      return uVar6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar3);
    }
    uVar6 = 0xc00000e5;
    if (*(char *)(*(longlong *)(lVar3 + 0x40) + 0x3f9) != '\0') {
      pcVar1 = (code *)swi(3);
      uVar6 = (*pcVar1)();
      return uVar6;
    }
  }
  *param_6 = 0;
  if (local_b0 != 0) {
    Endpoint_Delete(param_1,param_2,local_b0);
  }
  return uVar6;
}



===== Etw_UcxEndpointCreate @ 140001a20 =====

void Etw_UcxEndpointCreate(undefined8 param_1,longlong param_2)

{
  undefined8 in_stack_ffffffffffffffe8;
  
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    McTemplateK0pppn_EtwWriteTransfer
              (param_2 + 0x10,&UCX_ETW_EVENT_UCX_ENDPOINT_CREATE,0,
               *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x10),
               (char)*(undefined8 *)(param_2 + 8),(char)(param_2 + 0x10),in_stack_ffffffffffffffe8,
               param_2 + 0x2f4);
  }
  return;
}



===== McTemplateK0ppqp_EtwWriteTransfer @ 140001a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppqp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== UcxEndpointStateEntryFunc_DeletingStale @ 140001b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_DeletingStale(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)(param_1 + 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xb,
                      &WPP_e67e476125823041822f663b4e7cb804_Traceguids,(char)*puVar1);
  }
  uVar3 = WdfDriverGlobals;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  Etw_UcxEndpointDelete(uVar3,lVar2);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*puVar1);
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,*puVar1,_UcxEndpointCreate,0x3fc,
             "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\statemachineucxendpointstateentryfuncs.c")
  ;
  return 0xebe300c2;
}



===== Etw_TransferXrbDispatch @ 140001be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_TransferXrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  undefined7 in_register_00000009;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined1 auStackY_a8 [32];
  undefined1 uVar7;
  undefined1 uVar8;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar3 = -0x3ffffddb;
  }
  else {
    iVar3 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar2 = *(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x28);
  uVar7 = (undefined1)uVar1;
  uVar8 = (undefined1)param_2;
  switch(*(undefined2 *)(param_2 + 2)) {
  case 9:
  case 0x37:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar6 = &local_38;
      if (iVar3 < 0) {
        puVar6 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (0,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER,puVar6,uVar2,
                 uVar7,(char)*(undefined8 *)(param_2 + 0x18),param_1,uVar8,0x80,param_2);
    }
    break;
  case 10:
  case 0x38:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar5 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_ISOCH_TRANSFER;
    goto LAB_140001d36;
  case 0x39:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar6 = &local_38;
      if (iVar3 < 0) {
        puVar6 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (0,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_BULK_OR_INTERRUPT_TRANSFER,puVar6,
                 uVar2,uVar7,(char)*(undefined8 *)(param_2 + 0x18),param_1,uVar8,0x80,param_2);
    }
    break;
  case 0x3a:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar5 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_ISOCH_TRANSFER;
LAB_140001d36:
    puVar6 = &local_38;
    if (iVar3 < 0) {
      puVar6 = (undefined8 *)0x0;
    }
    McTemplateK0ppppphnNR5_EtwWriteTransfer
              (0,puVar5,puVar6,uVar2,uVar7,(char)*(undefined8 *)(param_2 + 0x18),param_1,uVar8,
               *(ushort *)(param_2 + 0x84),in_stack_ffffffffffffffa0,param_2,
               in_stack_ffffffffffffffb0,param_2 + 0x8c);
  }
  return;
}



===== UcxEndpointStateEntryFunc_Deleting @ 140001df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_Deleting(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  
  if (*(char *)(*(longlong *)(param_1 + 0x48) + 0x1a1) != '\0') {
    lVar7 = *(longlong *)(param_1 + 0x48) + 0x80;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7);
    plVar1 = (longlong *)(param_1 + 0x110);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(param_1 + 0x118), (longlong *)*plVar4 != plVar1))
    goto LAB_140001f95;
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(undefined8 *)(param_1 + 0x118) = 0;
    *plVar1 = 0;
    KeReleaseSpinLock(lVar7,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar6));
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + 0x1e8);
  piVar2 = (int *)(*(longlong *)(param_1 + 0x40) + 500);
  *piVar2 = *piVar2 + -1;
  plVar1 = (longlong *)(param_1 + 0xc0);
  lVar7 = *plVar1;
  if ((*(longlong **)(lVar7 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_1 + 200), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar4;
    KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + 0x1e8,
                      CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar6));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,10,
                        &WPP_e67e476125823041822f663b4e7cb804_Traceguids,
                        (char)*(undefined8 *)(param_1 + 8));
    }
    uVar8 = WdfDriverGlobals;
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),
                       PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
    Etw_UcxEndpointDelete(uVar8,lVar7);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),_UcxEndpointCreate,0x3d3,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\statemachineucxendpointstateentryfuncs.c"
              );
    return 0xebe300c2;
  }
LAB_140001f95:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  uVar8 = (*pcVar5)();
  return uVar8;
}



===== Etw_UcxEndpointDelete @ 140001fa4 =====

void Etw_UcxEndpointDelete(undefined8 param_1,longlong param_2)

{
  undefined8 in_stack_ffffffffffffffe8;
  
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    McTemplateK0pppn_EtwWriteTransfer
              (param_2 + 0x10,&UCX_ETW_EVENT_UCX_ENDPOINT_DELETE,0,
               *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x10),
               (char)*(undefined8 *)(param_2 + 8),(char)(param_2 + 0x10),in_stack_ffffffffffffffe8,
               param_2 + 0x2f4);
  }
  return;
}



===== Etw_UcxControllerStateMachineTransition @ 140002000 =====

void Etw_UcxControllerStateMachineTransition
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5)

{
  if (Microsoft_Windows_USB_UCXEnableBits < '\0') {
    McTemplateK0ppqq_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_CONTROLLER_STATE_MACHINE_TRANSITION,param_1,param_2,
               param_3,param_4,param_5);
  }
  return;
}



===== Etw_UcxControllerStateMachineEvent @ 140002040 =====

void Etw_UcxControllerStateMachineEvent
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  if (Microsoft_Windows_USB_UCXEnableBits < '\0') {
    McTemplateK0ppq_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_CONTROLLER_STATE_MACHINE_EVENT,param_1,param_2,param_3,
               param_4);
  }
  return;
}



===== McTemplateK0pppn_EtwWriteTransfer @ 140002078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppn_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = param_8;
  local_30 = 8;
  local_20 = 7;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== Etw_UcxEndpointRundown @ 140002108 =====

void Etw_UcxEndpointRundown(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar1 = param_1;
  if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
    McTemplateK0pppn_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_RUNDOWN_UCX_ENDPOINT_INFORMATION,param_1,param_2,
               (char)*(undefined8 *)(param_3 + 8),(char)param_3 + '\x10',in_stack_ffffffffffffffd8,
               param_3 + 0x2f4);
  }
  uVar4 = (ulonglong)*(byte *)(param_3 + 0x2a0);
  lVar2 = 0x10;
  lVar5 = 0x10;
  do {
    uVar4 = (ulonglong)((int)uVar4 - 1U & 0xf);
    if ((DAT_14002f391 & 1) != 0) {
      McTemplateK0ppqq_EtwWriteTransfer
                (uVar1,&UCX_ETW_EVENT_RUNDOWN_UCX_ENDPOINT_STATE_MACHINE_TRANSITION,param_1,
                 *(undefined8 *)(param_3 + 8),(char)param_3 + '\x10',
                 (char)*(undefined4 *)(param_3 + 0x1e0 + uVar4 * 8),
                 (char)*(undefined4 *)(param_3 + 0x1e4 + uVar4 * 8));
    }
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar4 = (ulonglong)*(byte *)(param_3 + 0x2a1);
  do {
    uVar4 = (ulonglong)((int)uVar4 - 1U & 0xf);
    if ((DAT_14002f391 & 1) != 0) {
      McTemplateK0ppq_EtwWriteTransfer
                (param_3 + 0x10,&UCX_ETW_EVENT_RUNDOWN_UCX_ENDPOINT_STATE_MACHINE_EVENT,param_1,
                 *(undefined8 *)(param_3 + 8),(char)(param_3 + 0x10),
                 (char)*(undefined4 *)(param_3 + 0x260 + uVar4 * 4));
    }
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar4 = 0;
  if ((param_4 != 0) && (*(int *)(param_4 + 4) != 0)) {
    do {
      if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
        McTemplateK0ppqp_EtwWriteTransfer
                  (param_3 + 0x10,&UCX_ETW_EVENT_RUNDOWN_UCX_STATIC_STREAM_INFORMATION,param_1,
                   param_2,(char)(param_3 + 0x10),
                   (char)*(undefined4 *)(*(longlong *)(param_4 + 0x20) + 0x40 + uVar4 * 0x48),
                   (char)*(longlong *)(param_4 + 0x20) + '\x10' + (char)uVar4 * 'H');
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(param_4 + 4));
  }
  return;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_VendorClassCommand @ 140002280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_VendorClassCommand
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 uVar5;
  byte bVar6;
  
  *(undefined2 *)(param_3 + 0x86) = *(undefined2 *)(param_3 + 0x24);
  bVar6 = *(byte *)(param_3 + 0x80) & 0x7f | (char)*(uint *)(param_3 + 0x20) << 7;
  *(byte *)(param_3 + 0x80) = bVar6;
  lVar2 = (ulonglong)*(ushort *)(param_3 + 2) * 0x18;
  bVar6 = ((&DAT_14002c10d)[lVar2] << 5 ^ bVar6) & 0x60 ^ bVar6;
  *(byte *)(param_3 + 0x80) = bVar6;
  *(byte *)(param_3 + 0x80) = (bVar6 ^ (&DAT_14002c10e)[lVar2]) & 3 ^ bVar6;
  *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 2;
  Etw_ClassVendorUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  switch(*(undefined2 *)(param_3 + 2)) {
  default:
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
    bVar6 = KeGetCurrentIrql();
    if ((((bVar6 < 2) && (*(longlong *)(param_3 + 0x30) == 0)) &&
        (*(longlong *)(param_3 + 0x28) != 0)) && (*(int *)(param_3 + 0x24) != 0)) {
      UCX_LockBufferPagesInUrbForDMA(param_3);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar4 = IoSetCompletionRoutineEx(uVar5,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar4 < 0) {
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar2 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar2 + -8) = param_3;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== Etw_ClassVendorUrbDispatch @ 14000249c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_ClassVendorUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined7 in_register_00000009;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar4 = (uint)*(ushort *)(param_2 + 2);
  uVar5 = (ulonglong)(uVar4 - 0x17);
  if (uVar4 - 0x17 != 0) {
    if (uVar4 == 0x18) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_VENDOR_INTERFACE;
      uVar5 = 0;
      goto LAB_140002572;
    }
    if (uVar4 == 0x19) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_VENDOR_ENDPOINT;
      uVar5 = 0;
      goto LAB_140002572;
    }
    if (uVar4 == 0x1a) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLASS_DEVICE;
      uVar5 = 0;
      goto LAB_140002572;
    }
    if (uVar4 == 0x1b) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLASS_INTERFACE;
      uVar5 = 0;
      goto LAB_140002572;
    }
    if (uVar4 == 0x1c) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLASS_ENDPOINT;
      uVar5 = 0;
      goto LAB_140002572;
    }
    uVar4 = uVar4 - 0x1f;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLASS_OTHER;
      goto LAB_140002572;
    }
    if (uVar4 == 1) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_VENDOR_OTHER;
      goto LAB_140002572;
    }
  }
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_VENDOR_DEVICE;
LAB_140002572:
  puVar7 = &local_38;
  if (iVar2 < 0) {
    puVar7 = (undefined8 *)0x0;
  }
  McTemplateK0pppppn_EtwWriteTransfer
            (uVar5,puVar6,puVar7,*(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
             (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
  return;
}



===== UrbHandler_Legacy_ControlTransferEx @ 140002680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_Legacy_ControlTransferEx
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  undefined8 uVar7;
  
  Etw_ControlTransferExUrbDispatch((char)param_2,param_3);
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 == 8) || (sVar2 == 9)) || (sVar2 == 10)) ||
     (((sVar2 == 0x32 || (sVar2 == 0x37)) ||
      ((sVar2 == 0x38 || ((sVar2 != 0x39 && (sVar2 != 0x3a)))))))) {
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
    bVar5 = KeGetCurrentIrql();
    if ((bVar5 < 2) &&
       (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
        (*(int *)(param_3 + 0x24) != 0)))) {
      UCX_LockBufferPagesInUrbForDMA(param_3);
    }
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar6 = IoSetCompletionRoutineEx(uVar7,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar6 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== Etw_ControlTransferExUrbDispatch @ 140002818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_ControlTransferExUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined7 in_register_00000009;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar2 = -0x3ffffddb;
    }
    else {
      iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
    }
    uVar1 = *(undefined8 *)(param_2 + 8);
    uVar4 = WdfDriverGlobals;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar5 = &local_38;
      if (iVar2 < 0) {
        puVar5 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar4,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CONTROL_TRANSFER_EX,puVar5,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
                 (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
    }
  }
  return;
}



===== Etw_UcxEndpointStateMachineEvent @ 140002920 =====

void Etw_UcxEndpointStateMachineEvent
               (undefined8 param_1,undefined8 param_2,char param_3,undefined1 param_4)

{
  if (Microsoft_Windows_USB_UCXEnableBits < '\0') {
    McTemplateK0ppq_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_ENDPOINT_STATE_MACHINE_EVENT,param_1,param_2,
               param_3 + -0x10,param_4);
  }
  return;
}



===== Etw_UcxEndpointStateMachineTransition @ 140002960 =====

void Etw_UcxEndpointStateMachineTransition
               (undefined8 param_1,undefined8 param_2,char param_3,undefined1 param_4,
               undefined1 param_5)

{
  if (Microsoft_Windows_USB_UCXEnableBits < '\0') {
    McTemplateK0ppqq_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_ENDPOINT_STATE_MACHINE_TRANSITION,param_1,param_2,
               param_3 + -0x10,param_4,param_5);
  }
  return;
}



===== McTemplateK0ppq_EtwWriteTransfer @ 1400029a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0ppqq_EtwWriteTransfer @ 140002a24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0ppppphnNR5q_EtwWriteTransfer @ 140002ac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppppphnNR5q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               ushort param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13,undefined1 param_14)

{
  undefined8 local_res20;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
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
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a0 = 8;
  local_a8 = &local_res20;
  local_2c = 0;
  local_98 = &param_5;
  local_90 = 8;
  local_88 = &param_6;
  local_78 = &param_7;
  local_68 = &param_8;
  local_58 = &param_9;
  local_48 = param_11;
  local_38 = param_13;
  local_80 = 8;
  local_70 = 8;
  local_60 = 8;
  local_50 = 2;
  local_28 = &param_14;
  local_30 = (uint)param_9 * 0xc;
  local_40 = 0x8c;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer((ulonglong)local_30,param_2,param_3,10,local_b8);
  return;
}



===== UrbHandler_Legacy_ControlTransfer @ 140002bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
UrbHandler_Legacy_ControlTransfer
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = 0;
  uStack_50 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar3 = -0x3ffffddb;
    }
    else {
      iVar3 = (*g_IoGetActivityIdIrp)(param_2,&local_58);
    }
    uVar5 = *(undefined8 *)(param_3 + 8);
    uVar6 = WdfDriverGlobals;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar5,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar7 = &local_58;
      if (iVar3 < 0) {
        puVar7 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar6,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CONTROL_TRANSFER,puVar7,
                 *(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x28),(char)uVar5,
                 (char)*(undefined8 *)(param_3 + 0x18),(char)param_2,(char)param_3,0x88,param_3);
    }
  }
  switch(*(undefined2 *)(param_3 + 2)) {
  default:
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
    bVar2 = KeGetCurrentIrql();
    if ((((bVar2 < 2) && (*(longlong *)(param_3 + 0x30) == 0)) &&
        (*(longlong *)(param_3 + 0x28) != 0)) && (*(int *)(param_3 + 0x24) != 0)) {
      UCX_LockBufferPagesInUrbForDMA(param_3);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar7 = *(undefined8 **)(param_2 + 0xb8);
  puVar7[-9] = *puVar7;
  puVar7[-8] = puVar7[1];
  puVar7[-7] = puVar7[2];
  puVar7[-6] = puVar7[3];
  *(undefined4 *)(puVar7 + -5) = *(undefined4 *)(puVar7 + 4);
  *(undefined4 *)((longlong)puVar7 + -0x24) = *(undefined4 *)((longlong)puVar7 + 0x24);
  *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(puVar7 + 5);
  *(undefined4 *)((longlong)puVar7 + -0x1c) = *(undefined4 *)((longlong)puVar7 + 0x2c);
  puVar7[-3] = puVar7[6];
  *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar3 = IoSetCompletionRoutineEx(uVar5,param_2,Urb_LegacyTransferUrbCompletion,param_3);
  if (iVar3 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4);
  return 0x103;
}



===== UrbHandler_USBPORTStyle_Legacy_IsochTransfer @ 140002e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
UrbHandler_USBPORTStyle_Legacy_IsochTransfer
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined1 auStackY_c8 [32];
  undefined8 in_stack_ffffffffffffff80;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar7 = *(longlong *)(param_3 + 0x18);
  if (((*(int *)(param_3 + 0x24) == 0) && (*(longlong *)(param_3 + 0x30) == 0)) &&
     (*(longlong *)(param_3 + 0x28) == 0)) {
    if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
      *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
    }
    *(undefined4 *)(param_3 + 4) = 0x80000300;
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  else {
    uVar3 = *(uint *)(lVar7 + 0x1c);
    if (uVar3 < 9) {
      uVar4 = *(uint *)(param_3 + 0x84);
      if ((uVar4 == 0) || ((uVar4 * uVar3 & 7) != 0)) {
        if ((uVar4 * uVar3 & 7) != 0) {
          *(undefined4 *)(param_3 + 0x80) = 0;
        }
      }
      else if (uVar4 <= *(uint *)(lVar7 + 0x18)) {
        if (*(char *)(lVar7 + 9) == '\0') {
          *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfffffffe;
        }
        else {
          *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 1;
        }
        local_58 = 0;
        uStack_50 = 0;
        if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
          if (g_IoGetActivityIdIrp == (code *)0x0) {
            iVar6 = -0x3ffffddb;
          }
          else {
            iVar6 = (*g_IoGetActivityIdIrp)(param_2,&local_58);
          }
          uVar8 = *(undefined8 *)(param_3 + 8);
          uVar2 = *(ushort *)(param_3 + 0x84);
          lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,uVar8,
                             PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
          if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
            puVar9 = &local_58;
            if (iVar6 < 0) {
              puVar9 = (undefined8 *)0x0;
            }
            McTemplateK0ppppphnNR5_EtwWriteTransfer
                      (param_3 + 0x8c,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_ISOCH_TRANSFER,puVar9,
                       *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x28),(char)uVar8,
                       (char)*(undefined8 *)(param_3 + 0x18),(char)param_2,(char)param_3,uVar2,
                       in_stack_ffffffffffffff80,param_3,in_stack_ffffffffffffff90,param_3 + 0x8c);
          }
        }
        switch(*(undefined2 *)(param_3 + 2)) {
        default:
          *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
          bVar5 = KeGetCurrentIrql();
          if (((bVar5 < 2) && (*(longlong *)(param_3 + 0x30) == 0)) &&
             ((*(longlong *)(param_3 + 0x28) != 0 && (*(int *)(param_3 + 0x24) != 0)))) {
            UCX_LockBufferPagesInUrbForDMA(param_3);
          }
          break;
        case 0x39:
        case 0x3a:
          break;
        }
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        puVar9 = *(undefined8 **)(param_2 + 0xb8);
        puVar9[-9] = *puVar9;
        puVar9[-8] = puVar9[1];
        puVar9[-7] = puVar9[2];
        puVar9[-6] = puVar9[3];
        *(undefined4 *)(puVar9 + -5) = *(undefined4 *)(puVar9 + 4);
        *(undefined4 *)((longlong)puVar9 + -0x24) = *(undefined4 *)((longlong)puVar9 + 0x24);
        *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(puVar9 + 5);
        *(undefined4 *)((longlong)puVar9 + -0x1c) = *(undefined4 *)((longlong)puVar9 + 0x2c);
        puVar9[-3] = puVar9[6];
        *(undefined1 *)((longlong)puVar9 + -0x45) = 0;
        uVar8 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
        iVar6 = IoSetCompletionRoutineEx(uVar8,param_2,Urb_LegacyTransferUrbCompletion,param_3);
        if (iVar6 < 0) {
          lVar7 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar7 + -0x10) = Urb_LegacyTransferUrbCompletion;
          *(longlong *)(lVar7 + -8) = param_3;
          *(undefined1 *)(lVar7 + -0x45) = 0xe0;
        }
        (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4);
        return 0x103;
      }
      if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
      }
      *(undefined4 *)(param_3 + 4) = 0x80000300;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      *(undefined4 *)(param_3 + 0x80) = 0;
      if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
      }
      *(undefined4 *)(param_3 + 4) = 0x80000300;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  IofCompleteRequest(param_2,0);
  return 0xc000000d;
}



===== McTemplateK0ppppphnNR5_EtwWriteTransfer @ 1400031c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppppphnNR5_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               ushort param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
               undefined8 param_13)

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
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = 8;
  local_98 = &local_res20;
  local_1c = 0;
  local_88 = &param_5;
  local_80 = 8;
  local_78 = &param_6;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = param_11;
  local_28 = param_13;
  local_70 = 8;
  local_60 = 8;
  local_50 = 8;
  local_40 = 2;
  local_20 = (uint)param_9 * 0xc;
  local_30 = 0x8c;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer((ulonglong)local_20,param_2,param_3,9,local_a8);
  return;
}



===== Xrb_BulkInterruptIsochCompletion @ 1400032a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Xrb_BulkInterruptIsochCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong lVar8;
  
  iVar3 = *(int *)(param_3 + 4);
  switch(*(undefined2 *)(param_3 + 2)) {
  default:
    lVar8 = 0x24;
    break;
  case 0x39:
  case 0x3a:
    lVar8 = 0x34;
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                     PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  if (iVar3 == 0x40000000) {
    *(int *)(lVar5 + 0x1a4) = *(int *)(lVar5 + 0x1a4) + 1;
    *(undefined4 *)(lVar8 + param_3) = 0;
    if (*(char *)(lVar5 + 0x19c) == '\0') {
      *(undefined4 *)(param_3 + 4) = 0xc0010000;
      if (*(short *)(param_3 + 2) == 10) {
        uVar7 = 0;
        if (*(int *)(param_3 + 0x84) != 0) {
          do {
            uVar6 = (ulonglong)uVar7;
            uVar7 = uVar7 + 1;
            *(undefined4 *)(param_3 + 0x94 + uVar6 * 0xc) = 0xffffffff;
          } while (uVar7 < *(uint *)(param_3 + 0x84));
        }
        *(undefined4 *)(param_3 + 0x88) = 0;
      }
    }
    else {
      *(undefined4 *)(param_3 + 4) = 0xc0007000;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    }
    goto LAB_14000333d;
  }
  *(undefined8 *)(lVar5 + 0x1a8) = _DAT_fffff78000000014;
  if (iVar3 < 0) {
    *(int *)(lVar5 + 0x1a4) = *(int *)(lVar5 + 0x1a4) + 1;
    LOCK();
    iVar2 = *(int *)(lVar5 + 0x18c);
    *(int *)(lVar5 + 0x18c) = 0;
    UNLOCK();
    if (iVar2 == 1) {
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x20),
                         PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      (**(code **)(lVar8 + 0x1c0))(*(undefined8 *)(lVar8 + 0x1b0),*(undefined8 *)(lVar5 + 0x28));
    }
LAB_1400034ac:
    if (iVar3 < -0x3ffff1ff) {
      if (iVar3 == -0x3ffff200) {
        uVar4 = 0xc00000bb;
      }
      else if ((((iVar3 == -0x7ffffe00) || (iVar3 == -0x7ffffd00)) || (iVar3 == -0x7ffffa00)) ||
              (iVar3 == -0x3ffff600)) {
        uVar4 = 0xc000000d;
      }
      else {
LAB_14000351d:
        uVar4 = 0xc0000001;
      }
    }
    else if (iVar3 == -0x3ffff000) {
      uVar4 = 0xc000009a;
    }
    else if (iVar3 == -0x3fff9000) {
      uVar4 = 0xc000000e;
    }
    else {
      if (iVar3 != -0x3fff0000) {
        if (iVar3 != 0) goto LAB_14000351d;
        goto LAB_140003338;
      }
      uVar4 = 0xc0000120;
    }
  }
  else {
    if (iVar3 != 1) goto LAB_1400034ac;
LAB_140003338:
    uVar4 = 0;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
LAB_14000333d:
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  switch(*(undefined2 *)(param_3 + 2)) {
  default:
    if ((*(uint *)(param_3 + 0x10) & 0x20000000) != 0) {
      MmUnlockPages(*(undefined8 *)(param_3 + 0x30));
      IoFreeMdl(*(undefined8 *)(param_3 + 0x30));
      *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
      *(undefined8 *)(param_3 + 0x30) = 0;
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
  Etw_UrbComplete(param_2,param_3);
  return 0;
}



===== Urb_LegacyTransferUrbCompletion @ 140003550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Urb_LegacyTransferUrbCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  
  iVar2 = *(int *)(param_2 + 0x30);
  iVar3 = *(int *)(param_3 + 4);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (iVar3 == 0x40000000) {
    *(undefined4 *)(param_3 + 4) = 0xc0010000;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    *(undefined4 *)(param_3 + 0x24) = 0;
    if (*(short *)(param_3 + 2) == 10) {
      uVar8 = 0;
      if (*(int *)(param_3 + 0x84) != 0) {
        do {
          uVar6 = (ulonglong)uVar8;
          uVar8 = uVar8 + 1;
          *(undefined4 *)(param_3 + 0x94 + uVar6 * 0xc) = 0xffffffff;
        } while (uVar8 < *(uint *)(param_3 + 0x84));
      }
      *(undefined4 *)(param_3 + 0x88) = 0;
    }
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    *(int *)(lVar5 + 0x1a4) = *(int *)(lVar5 + 0x1a4) + 1;
    goto LAB_140003644;
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                     PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  if (-1 < iVar3) {
    *(undefined8 *)(lVar5 + 0x1a8) = _DAT_fffff78000000014;
    if (iVar2 < 0) {
      if (iVar2 == -0x3ffffff2) {
        uVar4 = 0xc0007000;
      }
      else if (iVar2 == -0x3fffff66) {
        uVar4 = 0xc0001000;
      }
      else if (iVar2 == -0x3fffff45) {
        uVar4 = 0xc0000e00;
      }
      else {
        uVar4 = 0xc0010000;
        if (iVar2 != -0x3ffffee0) {
          uVar4 = 0x80000300;
        }
      }
      *(undefined4 *)(param_3 + 4) = uVar4;
    }
    goto LAB_140003644;
  }
  *(int *)(lVar5 + 0x1a4) = *(int *)(lVar5 + 0x1a4) + 1;
  LOCK();
  iVar2 = *(int *)(lVar5 + 0x18c);
  *(int *)(lVar5 + 0x18c) = 0;
  UNLOCK();
  if (iVar2 == 1) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x20),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    (**(code **)(lVar7 + 0x1c0))(*(undefined8 *)(lVar7 + 0x1b0),*(undefined8 *)(lVar5 + 0x28));
  }
  if (iVar3 < -0x3ffff1ff) {
    if (iVar3 == -0x3ffff200) {
      uVar4 = 0xc00000bb;
    }
    else if ((((iVar3 == -0x7ffffe00) || (iVar3 == -0x7ffffd00)) || (iVar3 == -0x7ffffa00)) ||
            (iVar3 == -0x3ffff600)) {
      uVar4 = 0xc000000d;
    }
    else {
LAB_140003807:
      uVar4 = 0xc0000001;
    }
  }
  else if (iVar3 == -0x3ffff000) {
    uVar4 = 0xc000009a;
  }
  else if (iVar3 == -0x3fff9000) {
    uVar4 = 0xc000000e;
  }
  else {
    if (iVar3 != -0x3fff0000) goto LAB_140003807;
    uVar4 = 0xc0000120;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
LAB_140003644:
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  switch(*(undefined2 *)(param_3 + 2)) {
  case 8:
  case 9:
  case 10:
  case 0x32:
  case 0x37:
  case 0x38:
  default:
    if ((*(uint *)(param_3 + 0x10) & 0x20000000) != 0) {
      MmUnlockPages(*(undefined8 *)(param_3 + 0x30));
      IoFreeMdl(*(undefined8 *)(param_3 + 0x30));
      *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
      *(undefined8 *)(param_3 + 0x30) = 0;
    }
  case 0x39:
  case 0x3a:
    if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
      *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
    }
    Etw_UrbComplete(param_2,param_3);
    return 0;
  }
}



===== Etw_UrbComplete @ 140003850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Etw_UrbComplete(longlong param_1,longlong param_2)

{
  short sVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_a8 [32];
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined4 uVar11;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar12;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_38 = 0;
  uStack_30 = 0;
  if (((((_Microsoft_Windows_USB_UCXEnableBits & 8) == 0) &&
       ((_Microsoft_Windows_USB_UCXEnableBits & 0x10) == 0)) &&
      ((_Microsoft_Windows_USB_UCXEnableBits & 0x20) == 0)) &&
     ((_Microsoft_Windows_USB_UCXEnableBits & 0x40) == 0)) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar4 = -0x3ffffddb;
  }
  else {
    iVar4 = (*g_IoGetActivityIdIrp)(0,&local_38);
  }
  uVar2 = *(undefined8 *)(param_2 + 8);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  sVar1 = *(short *)(param_2 + 2);
  uVar3 = *(undefined8 *)(*(longlong *)(lVar5 + 0x18) + 0x28);
  uVar8 = (undefined1)uVar2;
  uVar9 = (undefined1)param_1;
  uVar10 = (undefined1)param_2;
  if (sVar1 == 8) {
    if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar7 = &local_38;
    puVar6 = &UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_CONTROL_TRANSFER_V1;
    if (iVar4 < 0) {
      puVar7 = (undefined8 *)0x0;
    }
    uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x30);
    uVar11 = 0x88;
    goto LAB_140003981;
  }
  if (sVar1 == 0x32) {
    if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar7 = &local_38;
    puVar6 = &UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_CONTROL_TRANSFER_EX_V1;
    if (iVar4 < 0) {
      puVar7 = (undefined8 *)0x0;
    }
    uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x30);
    uVar11 = 0x88;
    goto LAB_140003981;
  }
  if (sVar1 == 9) {
LAB_140003950:
    if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar6 = &UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER_V1;
  }
  else {
    if (sVar1 == 10) {
LAB_1400039ad:
      if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar7 = &local_38;
      if (iVar4 < 0) {
        puVar7 = (undefined8 *)0x0;
      }
      McTemplateK0ppppphnNR5q_EtwWriteTransfer
                (param_2 + 0x8c,&UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_ISOCH_TRANSFER,puVar7,uVar3,
                 uVar8,(char)*(undefined8 *)(param_2 + 0x18),uVar9,uVar10,
                 *(ushort *)(param_2 + 0x84),in_stack_ffffffffffffffa0,param_2,
                 in_stack_ffffffffffffffb0,param_2 + 0x8c,(char)*(undefined4 *)(param_1 + 0x30));
      return;
    }
    if (sVar1 == 0x37) goto LAB_140003950;
    if (sVar1 == 0x38) goto LAB_1400039ad;
    if (sVar1 != 0x39) {
      if (sVar1 != 0x3a) {
        return;
      }
      if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar7 = &local_38;
      if (iVar4 < 0) {
        puVar7 = (undefined8 *)0x0;
      }
      McTemplateK0ppppphnNR5q_EtwWriteTransfer
                (param_2 + 0x8c,&UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_SECURE_ISOCH_TRANSFER,puVar7,
                 uVar3,uVar8,(char)*(undefined8 *)(param_2 + 0x18),uVar9,uVar10,
                 *(ushort *)(param_2 + 0x84),in_stack_ffffffffffffffa0,param_2,
                 in_stack_ffffffffffffffb0,param_2 + 0x8c,(char)*(undefined4 *)(param_1 + 0x30));
      return;
    }
    if ((_Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
      return;
    }
    puVar6 = &UCX_ETW_EVENT_COMPLETE_URB_FUNCTION_SECURE_BULK_OR_INTERRUPT_TRANSFER_V1;
  }
  puVar7 = &local_38;
  if (iVar4 < 0) {
    puVar7 = (undefined8 *)0x0;
  }
  uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x30);
  uVar11 = 0x80;
LAB_140003981:
  McTemplateK0pppppnq_EtwWriteTransfer
            (*(longlong *)(lVar5 + 0x18),puVar6,puVar7,uVar3,uVar8,
             (char)*(undefined8 *)(param_2 + 0x18),uVar9,uVar10,uVar11,param_2,uVar12);
  return;
}



===== McTemplateK0pppppnq_EtwWriteTransfer @ 140003b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppppnq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined4 param_9,undefined8 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  undefined8 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_80 = 8;
  local_88 = &local_res20;
  local_70 = 8;
  local_78 = &param_5;
  local_68 = &param_6;
  local_58 = &param_7;
  local_60 = 8;
  local_48 = &param_8;
  local_38 = param_10;
  local_30 = param_9;
  local_28 = &param_11;
  local_50 = 8;
  local_40 = 8;
  local_2c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(0,param_2,param_3,8,local_98);
  return;
}



===== UrbHandler_USBPORTStyle_Legacy_BulkOrInterruptTransfer @ 140003c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
UrbHandler_USBPORTStyle_Legacy_BulkOrInterruptTransfer
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (*(char *)(*(longlong *)(param_3 + 0x18) + 9) == '\0') {
    *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfffffffe;
  }
  else {
    *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 1;
  }
  local_58 = 0;
  uStack_50 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar3 = -0x3ffffddb;
    }
    else {
      iVar3 = (*g_IoGetActivityIdIrp)(param_2,&local_58);
    }
    uVar5 = *(undefined8 *)(param_3 + 8);
    uVar6 = WdfDriverGlobals;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar5,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar7 = &local_58;
      if (iVar3 < 0) {
        puVar7 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar6,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER,puVar7,
                 *(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x28),(char)uVar5,
                 (char)*(undefined8 *)(param_3 + 0x18),(char)param_2,(char)param_3,0x80,param_3);
    }
  }
  switch(*(undefined2 *)(param_3 + 2)) {
  default:
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
    bVar2 = KeGetCurrentIrql();
    if ((((bVar2 < 2) && (*(longlong *)(param_3 + 0x30) == 0)) &&
        (*(longlong *)(param_3 + 0x28) != 0)) && (*(int *)(param_3 + 0x24) != 0)) {
      UCX_LockBufferPagesInUrbForDMA(param_3);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar7 = *(undefined8 **)(param_2 + 0xb8);
  puVar7[-9] = *puVar7;
  puVar7[-8] = puVar7[1];
  puVar7[-7] = puVar7[2];
  puVar7[-6] = puVar7[3];
  *(undefined4 *)(puVar7 + -5) = *(undefined4 *)(puVar7 + 4);
  *(undefined4 *)((longlong)puVar7 + -0x24) = *(undefined4 *)((longlong)puVar7 + 0x24);
  *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(puVar7 + 5);
  *(undefined4 *)((longlong)puVar7 + -0x1c) = *(undefined4 *)((longlong)puVar7 + 0x2c);
  puVar7[-3] = puVar7[6];
  *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar3 = IoSetCompletionRoutineEx(uVar5,param_2,Urb_LegacyTransferUrbCompletion,param_3);
  if (iVar3 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4);
  return 0x103;
}



===== McTemplateK0pppppn_EtwWriteTransfer @ 140003e70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppppn_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined4 param_9,undefined8 param_10)

{
  undefined8 local_res20;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 8;
  local_78 = &local_res20;
  local_60 = 8;
  local_68 = &param_5;
  local_58 = &param_6;
  local_48 = &param_7;
  local_50 = 8;
  local_38 = &param_8;
  local_28 = param_10;
  local_20 = param_9;
  local_40 = 8;
  local_30 = 8;
  local_1c = 0;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(0,param_2,param_3,7,local_88);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003f30 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14002da08;
  if (DAT_14002da08 == (ushort *)0x0) {
    uVar2 = 0;
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14002da08;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(MS_UCX_ETW_PROVIDER_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== UCX_LOCK_BUFFER_PAGES_IN_URB_FOR_DMA @ 140003fa0 =====

void UCX_LOCK_BUFFER_PAGES_IN_URB_FOR_DMA(longlong param_1)

{
  byte bVar1;
  
  switch(*(undefined2 *)(param_1 + 2)) {
  default:
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xdfffffff;
    bVar1 = KeGetCurrentIrql();
    if ((((bVar1 < 2) && (*(longlong *)(param_1 + 0x30) == 0)) &&
        (*(longlong *)(param_1 + 0x28) != 0)) && (*(int *)(param_1 + 0x24) != 0)) {
      UCX_LockBufferPagesInUrbForDMA(param_1);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  return;
}



===== UCX_LockBufferPagesInUrbForDMA @ 140004020 =====

void UCX_LockBufferPagesInUrbForDMA(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x24),0,0,0);
  *(longlong *)(param_1 + 0x30) = lVar1;
  if (lVar1 != 0) {
    MmProbeAndLockPages(lVar1,0,(*(uint *)(param_1 + 0x20) & 1) != 0);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20000000;
  }
  return;
}



===== Xrb_ProcessSubmitUrbIoctl @ 1400040c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint Xrb_ProcessSubmitUrbIoctl(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  short sVar2;
  short *psVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  byte bVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 uVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined8 *puVar17;
  undefined1 auStackY_d8 [32];
  undefined1 uVar18;
  undefined1 uVar19;
  undefined8 in_stack_ffffffffffffff70;
  undefined8 in_stack_ffffffffffffff80;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  psVar3 = *(short **)(param_3 + 8);
  if (psVar3 != *(short **)(param_3 + 0x30)) {
LAB_140004144:
    uVar10 = Urb_USBPORTStyle_ProcessURB(param_1,param_2,psVar3);
    return (uint)uVar10;
  }
  lVar11 = *(longlong *)(psVar3 + -0x1c);
  if (*(int *)(psVar3 + -2) != 0x2e425258) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x144,3,param_2,psVar3);
  }
  if (*(int *)(psVar3 + -0x22) != -0x54330000) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x144,1,param_2,psVar3);
  }
  psVar3[-0x22] = 1;
  psVar3[-0x21] = -0x5433;
  if (*(uint *)(lVar11 + 4) < 0x602) goto LAB_140004144;
  sVar2 = psVar3[1];
  if (sVar2 == 0x35) {
    uVar8 = Endpoint_StaticStreamsEnableUrb
                      (*(longlong *)(psVar3 + 0xc) + -0x10,param_1,(longlong)(psVar3 + -0x28),
                       param_2);
    return uVar8;
  }
  uVar14 = (undefined1)param_2;
  if (sVar2 != 10) {
    switch(sVar2) {
    case 9:
      break;
    default:
      goto LAB_140004144;
    case 0x36:
      if (*(char *)(*(longlong *)(*(longlong *)(psVar3 + 0xc) + 0x30) + 0x474) != '\0') {
        uVar8 = Endpoint_StaticStreamsDisableUrb
                          (*(longlong *)(psVar3 + 0xc) + -0x10,param_1,(longlong)(psVar3 + -0x28),
                           param_2);
        return uVar8;
      }
      uVar8 = 0;
      LogWppMsgForCloseStaticStreamOnDx(uVar14);
      if (psVar3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        psVar3[-0x22] = 0;
        psVar3[-0x21] = -0x5433;
      }
      psVar3[2] = 0;
      psVar3[3] = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
LAB_14000471c:
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      return uVar8;
    case 0x37:
    case 0x38:
      if (*(char *)(lVar11 + 0x89) == '\0') {
        if (*(char *)(lVar11 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x144,0x806,param_2,psVar3);
        }
        uVar8 = 0xc000000d;
        if (psVar3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
          psVar3[-0x22] = 0;
          psVar3[-0x21] = -0x5433;
        }
        psVar3[2] = 0x300;
        psVar3[3] = -0x8000;
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        goto LAB_14000471c;
      }
      break;
    case 0x39:
    case 0x3a:
      if (*(char *)(lVar11 + 0x8c) == '\0') {
        if (*(char *)(lVar11 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x144,0x806,param_2,psVar3);
        }
        if (psVar3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
          psVar3[-0x22] = 0;
          psVar3[-0x21] = -0x5433;
        }
        psVar3[2] = 0x300;
        psVar3[3] = -0x8000;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        IofCompleteRequest(param_2,0);
        return 0xc000000d;
      }
      break;
    case 0x3c:
      uVar8 = Endpoint_ProcessResetNotificationRequest
                        (*(longlong *)(psVar3 + 0xc) + -0x10,(longlong)(psVar3 + -0x28),param_2);
      return uVar8;
    case 0x3d:
      uVar8 = Endpoint_GetIsochPipeTransferPathDelaysUrb
                        (*(longlong *)(psVar3 + 0xc) + -0x10,(longlong)(psVar3 + -0x28),param_2);
      return uVar8;
    }
  }
  puVar4 = *(undefined8 **)(psVar3 + 0xc);
  if (*(char *)((longlong)puVar4 + 9) == '\0') {
    *(uint *)(psVar3 + 0x10) = *(uint *)(psVar3 + 0x10) & 0xfffffffe;
  }
  else {
    *(uint *)(psVar3 + 0x10) = *(uint *)(psVar3 + 0x10) | 1;
  }
  uVar7 = KeGetCurrentProcessorNumberEx(0);
  *(undefined4 *)(psVar3 + 0x20) = uVar7;
  switch(psVar3[1]) {
  default:
    *(uint *)(psVar3 + 8) = *(uint *)(psVar3 + 8) & 0xdfffffff;
    bVar6 = KeGetCurrentIrql();
    if ((((bVar6 < 2) && (*(longlong *)(psVar3 + 0x18) == 0)) && (*(longlong *)(psVar3 + 0x14) != 0)
        ) && (*(int *)(psVar3 + 0x12) != 0)) {
      UCX_LockBufferPagesInUrbForDMA((longlong)psVar3);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  psVar3[2] = 0;
  psVar3[3] = 0x4000;
  local_50 = 0;
  uStack_48 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) goto LAB_140004273;
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar9 = -0x3ffffddb;
  }
  else {
    iVar9 = (*g_IoGetActivityIdIrp)(param_2,&local_50);
  }
  uVar5 = *(undefined8 *)(psVar3 + 4);
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar5,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar8 = (ushort)psVar3[1] - 9;
  uVar13 = *(undefined8 *)(*(longlong *)(lVar11 + 0x18) + 0x28);
  if (uVar8 < 0x32) {
    pcVar15 = IMAGE_DOS_HEADER_140000000.e_magic +
              (&switchD_14000451e::switchdataD_14002882b)
              [(&switchD_14000451e::switchdataD_14002883f)[(int)uVar8]];
    uVar18 = (undefined1)uVar5;
    uVar19 = SUB81(psVar3,0);
    switch(psVar3[1]) {
    case 9:
    case 0x37:
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
        puVar17 = &local_50;
        if (iVar9 < 0) {
          puVar17 = (undefined8 *)0x0;
        }
        McTemplateK0pppppn_EtwWriteTransfer
                  (pcVar15,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER,puVar17,
                   uVar13,uVar18,(char)*(undefined8 *)(psVar3 + 0xc),uVar14,uVar19,0x80,psVar3);
      }
      break;
    case 10:
    case 0x38:
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
        puVar16 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_ISOCH_TRANSFER;
LAB_140004624:
        puVar17 = &local_50;
        if (iVar9 < 0) {
          puVar17 = (undefined8 *)0x0;
        }
        McTemplateK0ppppphnNR5_EtwWriteTransfer
                  (pcVar15,puVar16,puVar17,uVar13,uVar18,(char)*(undefined8 *)(psVar3 + 0xc),uVar14,
                   uVar19,psVar3[0x42],in_stack_ffffffffffffff70,psVar3,in_stack_ffffffffffffff80,
                   psVar3 + 0x46);
      }
      break;
    case 0x39:
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
        puVar17 = &local_50;
        if (iVar9 < 0) {
          puVar17 = (undefined8 *)0x0;
        }
        McTemplateK0pppppn_EtwWriteTransfer
                  (pcVar15,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_BULK_OR_INTERRUPT_TRANSFER,
                   puVar17,uVar13,uVar18,(char)*(undefined8 *)(psVar3 + 0xc),uVar14,uVar19,0x80,
                   psVar3);
      }
      break;
    case 0x3a:
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
        puVar16 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_ISOCH_TRANSFER;
        goto LAB_140004624;
      }
    }
  }
LAB_140004273:
  if (*(longlong *)(psVar3 + -0x14) == 0) {
    uVar5 = *puVar4;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
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
    uVar13 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
    iVar9 = IoSetCompletionRoutineEx(uVar13,param_2,Xrb_BulkInterruptIsochCompletion,psVar3);
    if (iVar9 < 0) {
      lVar11 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar11 + -0x10) = Xrb_BulkInterruptIsochCompletion;
      *(short **)(lVar11 + -8) = psVar3;
      *(undefined1 *)(lVar11 + -0x45) = 0xe0;
    }
    (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,uVar5);
  }
  else {
    local_60 = 0;
    local_68 = 0x18;
    local_64 = 3;
    local_58 = param_2;
    (**(code **)(WdfFunctions_01015 + 0x7c8))
              (WdfDriverGlobals,*(longlong *)(psVar3 + -0x14),&local_68);
    uVar5 = *puVar4;
    uVar13 = *(undefined8 *)(psVar3 + -0x14);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
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
    uVar12 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
    iVar9 = IoSetCompletionRoutineEx(uVar12,param_2,Xrb_BulkInterruptIsochCompletion,psVar3);
    if (iVar9 < 0) {
      lVar11 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar11 + -0x10) = Xrb_BulkInterruptIsochCompletion;
      *(short **)(lVar11 + -8) = psVar3;
      *(undefined1 *)(lVar11 + -0x45) = 0xe0;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
    local_50 = 0x100000008;
    iVar9 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,uVar13,uVar5,&local_50);
    if (iVar9 < 0) {
      if (iVar9 == -0x3fdffdfc) {
        iVar9 = -0x3ffffff2;
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar13,iVar9);
      return 0x103;
    }
  }
  return 0x103;
}



===== RootHub_Pdo_EvtInternalDeviceControlIrpPreprocessCallback @ 140004860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint RootHub_Pdo_EvtInternalDeviceControlIrpPreprocessCallback
               (undefined8 param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  short sVar2;
  short *psVar3;
  undefined8 *puVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 uVar15;
  char *pcVar16;
  undefined *puVar17;
  code *pcVar18;
  undefined8 *puVar19;
  undefined2 uVar20;
  undefined1 auStackY_e8 [32];
  undefined1 uVar21;
  undefined8 in_stack_ffffffffffffff38;
  undefined1 uVar22;
  undefined8 in_stack_ffffffffffffff60;
  undefined8 in_stack_ffffffffffffff70;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar10 = *(longlong *)(param_2 + 0xb8);
  uVar15 = (undefined1)param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x3d,
                       in_stack_ffffffffffffff38,(char)*(undefined4 *)(lVar10 + 0x18),uVar15);
  }
  if (*(int *)(lVar10 + 0x18) == 0x220003) {
    psVar3 = *(short **)(lVar10 + 8);
    if (psVar3 != *(short **)(lVar10 + 0x30)) {
switchD_140004d8c_caseD_a:
      uVar9 = Urb_USBPORTStyle_ProcessURB(param_1,param_2,psVar3);
      return (uint)uVar9;
    }
    lVar10 = *(longlong *)(psVar3 + -0x1c);
    if (*(int *)(psVar3 + -2) != 0x2e425258) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x144,3,param_2,psVar3);
    }
    if (*(int *)(psVar3 + -0x22) != -0x54330000) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x144,1,param_2,psVar3);
    }
    psVar3[-0x22] = 1;
    psVar3[-0x21] = -0x5433;
    if (*(uint *)(lVar10 + 4) < 0x602) goto switchD_140004d8c_caseD_a;
    sVar2 = psVar3[1];
    if (sVar2 == 0x35) {
      uVar7 = Endpoint_StaticStreamsEnableUrb
                        (*(longlong *)(psVar3 + 0xc) + -0x10,param_1,(longlong)(psVar3 + -0x28),
                         param_2);
      return uVar7;
    }
    if (sVar2 == 10) goto switchD_140004d8c_caseD_9;
    switch(sVar2) {
    case 9:
      goto switchD_140004d8c_caseD_9;
    default:
      goto switchD_140004d8c_caseD_a;
    case 0x36:
      if (*(char *)(*(longlong *)(*(longlong *)(psVar3 + 0xc) + 0x30) + 0x474) != '\0') {
        uVar7 = Endpoint_StaticStreamsDisableUrb
                          (*(longlong *)(psVar3 + 0xc) + -0x10,param_1,(longlong)(psVar3 + -0x28),
                           param_2);
        return uVar7;
      }
      uVar7 = 0;
      LogWppMsgForCloseStaticStreamOnDx(uVar15);
      if (psVar3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        psVar3[-0x22] = 0;
        psVar3[-0x21] = -0x5433;
      }
      psVar3[2] = 0;
      psVar3[3] = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
      goto LAB_140004e98;
    case 0x37:
    case 0x38:
      if (*(char *)(lVar10 + 0x89) != '\0') goto switchD_140004d8c_caseD_9;
      if (*(char *)(lVar10 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x806,param_2,psVar3);
      }
LAB_1400050e8:
      uVar7 = 0xc000000d;
      if (psVar3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        psVar3[-0x22] = 0;
        psVar3[-0x21] = -0x5433;
      }
      psVar3[2] = 0x300;
      psVar3[3] = -0x8000;
      goto LAB_140004e92;
    case 0x39:
    case 0x3a:
      goto switchD_140004d8c_caseD_39;
    case 0x3c:
      uVar7 = Endpoint_ProcessResetNotificationRequest
                        (*(longlong *)(psVar3 + 0xc) + -0x10,(longlong)(psVar3 + -0x28),param_2);
      return uVar7;
    case 0x3d:
      uVar7 = Endpoint_GetIsochPipeTransferPathDelaysUrb
                        (*(longlong *)(psVar3 + 0xc) + -0x10,(longlong)(psVar3 + -0x28),param_2);
      return uVar7;
    }
  }
  uVar13 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  lVar14 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  uVar7 = *(uint *)(lVar10 + 0x18);
  lVar10 = *(longlong *)(lVar14 + 0x10);
  lVar14 = *(longlong *)(lVar14 + 8);
  if (uVar7 == 0x220fb3) {
    if (*(longlong *)(lVar10 + 0x58) == 0) {
      uVar7 = 0xc00000bb;
      *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc00000bb;
      }
      uVar20 = 0x3e;
    }
    else {
      if (*(int *)(lVar10 + 0x3f4) == 0) {
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        *(longlong *)(lVar14 + 0x168) = param_2;
        StateMachineEngine_EventAdd((undefined8 *)(lVar10 + 0x1f8),0xebe40020);
        return 0x103;
      }
      uVar7 = 0xc0000001;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000001;
      }
      uVar20 = 0x3f;
    }
    WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,uVar20,
                       &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar7,(char)lVar10);
    return uVar7;
  }
  if (uVar7 == 0x491057) {
switchD_1400052fa_caseD_491017:
    lVar10 = *(longlong *)(lVar10 + 0x130);
LAB_140004e77:
    if (lVar10 != 0) {
      if (uVar7 == 0x49103f) {
LAB_140004f39:
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        pcVar18 = RootHub_Pdo_DeviceMgmtIrpCompletion;
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
        iVar8 = IoSetCompletionRoutineEx(uVar13,param_2,RootHub_Pdo_DeviceMgmtIrpCompletion,param_1)
        ;
      }
      else {
        if (uVar7 != 0x49100b) {
          if (((uVar7 != 0x491017) && (uVar7 != 0x49101b)) && (uVar7 != 0x491037)) {
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            goto LAB_140004faa;
          }
          goto LAB_140004f39;
        }
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        pcVar18 = RootHub_Pdo_IrpCompletion;
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
        iVar8 = IoSetCompletionRoutineEx(uVar13,param_2,RootHub_Pdo_IrpCompletion,param_1);
      }
      if (iVar8 < 0) {
        lVar14 = *(longlong *)(param_2 + 0xb8);
        *(undefined1 *)(lVar14 + -0x45) = 0xe0;
        *(undefined8 *)(lVar14 + -8) = param_1;
        *(code **)(lVar14 + -0x10) = pcVar18;
      }
LAB_140004faa:
      uVar7 = (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,lVar10);
      return uVar7;
    }
  }
  else {
    if (uVar7 == 0x491007) {
      lVar10 = *(longlong *)(lVar10 + 0x128);
      goto LAB_140004e77;
    }
    if (0x49100b < uVar7) {
      if (uVar7 < 0x491405) {
        if (uVar7 != 0x491404) {
          switch(uVar7) {
          case 0x49100f:
          case 0x491013:
          case 0x49104b:
          case 0x49104f:
            break;
          default:
            goto switchD_1400052fa_caseD_491010;
          case 0x491017:
          case 0x49101b:
          case 0x49101f:
          case 0x491023:
          case 0x491027:
          case 0x49102b:
          case 0x49102f:
          case 0x491033:
          case 0x491037:
          case 0x49103b:
          case 0x49103f:
            goto switchD_1400052fa_caseD_491017;
          case 0x491053:
            lVar10 = *(longlong *)(lVar10 + 0x140);
            goto LAB_140004e77;
          }
        }
      }
      else if ((uVar7 != 0x491408) && (uVar7 != 0x49140f)) goto switchD_1400052fa_caseD_491010;
switchD_1400052fa_caseD_49100f:
      lVar10 = *(longlong *)(lVar10 + 0x148);
      goto LAB_140004e77;
    }
    if ((((uVar7 == 0x49100b) || (uVar7 == 0x490003)) || (uVar7 == 0x490007)) || (uVar7 == 0x49000b)
       ) goto switchD_1400052fa_caseD_49100f;
  }
switchD_1400052fa_caseD_491010:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar7 = 0xc00000bb;
LAB_140004e92:
  *(uint *)(param_2 + 0x30) = uVar7;
LAB_140004e98:
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar7;
switchD_140004d8c_caseD_39:
  if (*(char *)(lVar10 + 0x8c) == '\0') {
    if (*(char *)(lVar10 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x144,0x806,param_2,psVar3);
    }
    goto LAB_1400050e8;
  }
switchD_140004d8c_caseD_9:
  puVar4 = *(undefined8 **)(psVar3 + 0xc);
  if (*(char *)((longlong)puVar4 + 9) == '\0') {
    *(uint *)(psVar3 + 0x10) = *(uint *)(psVar3 + 0x10) & 0xfffffffe;
  }
  else {
    *(uint *)(psVar3 + 0x10) = *(uint *)(psVar3 + 0x10) | 1;
  }
  uVar6 = KeGetCurrentProcessorNumberEx(0);
  *(undefined4 *)(psVar3 + 0x20) = uVar6;
  switch(psVar3[1]) {
  default:
    *(uint *)(psVar3 + 8) = *(uint *)(psVar3 + 8) & 0xdfffffff;
    bVar5 = KeGetCurrentIrql();
    if (((bVar5 < 2) && (*(longlong *)(psVar3 + 0x18) == 0)) &&
       ((*(longlong *)(psVar3 + 0x14) != 0 && (*(int *)(psVar3 + 0x12) != 0)))) {
      UCX_LockBufferPagesInUrbForDMA((longlong)psVar3);
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  psVar3[2] = 0;
  psVar3[3] = 0x4000;
  local_58 = 0;
  uStack_50 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) goto switchD_140004d10_caseD_b;
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    local_78 = CONCAT44(local_78._4_4_,0xc0000225);
  }
  else {
    uVar6 = (*g_IoGetActivityIdIrp)(param_2,&local_58);
    local_78 = CONCAT44(local_78._4_4_,uVar6);
  }
  uVar13 = *(undefined8 *)(psVar3 + 4);
  lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar13,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar7 = (ushort)psVar3[1] - 9;
  uVar12 = *(undefined8 *)(*(longlong *)(lVar10 + 0x18) + 0x28);
  if (0x31 < uVar7) goto switchD_140004d10_caseD_b;
  pcVar16 = IMAGE_DOS_HEADER_140000000.e_magic +
            (&switchD_140004d10::switchdataD_140028700)
            [(&switchD_140004d10::switchdataD_140028714)[(int)uVar7]];
  uVar21 = (undefined1)uVar13;
  uVar22 = SUB81(psVar3,0);
  switch(psVar3[1]) {
  case 9:
  case 0x37:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar19 = &local_58;
      if ((int)local_78 < 0) {
        puVar19 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (pcVar16,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER,puVar19,
                 uVar12,uVar21,(char)*(undefined8 *)(psVar3 + 0xc),uVar15,uVar22,0x80,psVar3);
    }
    break;
  case 10:
  case 0x38:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) break;
    puVar17 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_ISOCH_TRANSFER;
    goto LAB_140004ec6;
  case 0x39:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar19 = &local_58;
      if ((int)local_78 < 0) {
        puVar19 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (pcVar16,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_BULK_OR_INTERRUPT_TRANSFER,
                 puVar19,uVar12,uVar21,(char)*(undefined8 *)(psVar3 + 0xc),uVar15,uVar22,0x80,psVar3
                );
    }
    break;
  case 0x3a:
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) break;
    puVar17 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_ISOCH_TRANSFER;
LAB_140004ec6:
    puVar19 = &local_58;
    if ((int)local_78 < 0) {
      puVar19 = (undefined8 *)0x0;
    }
    McTemplateK0ppppphnNR5_EtwWriteTransfer
              (pcVar16,puVar17,puVar19,uVar12,uVar21,(char)*(undefined8 *)(psVar3 + 0xc),uVar15,
               uVar22,psVar3[0x42],in_stack_ffffffffffffff60,psVar3,in_stack_ffffffffffffff70,
               psVar3 + 0x46);
  }
switchD_140004d10_caseD_b:
  if (*(longlong *)(psVar3 + -0x14) == 0) {
    uVar13 = *puVar4;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
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
    uVar12 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
    iVar8 = IoSetCompletionRoutineEx(uVar12,param_2,Xrb_BulkInterruptIsochCompletion,psVar3);
    if (iVar8 < 0) {
      lVar10 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar10 + -0x10) = Xrb_BulkInterruptIsochCompletion;
      *(short **)(lVar10 + -8) = psVar3;
      *(undefined1 *)(lVar10 + -0x45) = 0xe0;
    }
    (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,uVar13);
  }
  else {
    local_68 = 0;
    local_70 = 0x18;
    local_6c = 3;
    local_60 = param_2;
    (**(code **)(WdfFunctions_01015 + 0x7c8))
              (WdfDriverGlobals,*(longlong *)(psVar3 + -0x14),&local_70);
    uVar13 = *puVar4;
    uVar12 = *(undefined8 *)(psVar3 + -0x14);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
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
    uVar11 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
    iVar8 = IoSetCompletionRoutineEx(uVar11,param_2,Xrb_BulkInterruptIsochCompletion,psVar3);
    if (iVar8 < 0) {
      lVar10 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar10 + -0x10) = Xrb_BulkInterruptIsochCompletion;
      *(short **)(lVar10 + -8) = psVar3;
      *(undefined1 *)(lVar10 + -0x45) = 0xe0;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
    local_78 = 0x100000008;
    iVar8 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,uVar12,uVar13,&local_78);
    if (iVar8 < 0) {
      if (iVar8 == -0x3fdffdfc) {
        iVar8 = -0x3ffffff2;
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar12,iVar8);
      return 0x103;
    }
  }
  return 0x103;
}



===== Urb_USBPORTStyle_ProcessURB @ 1400053a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Urb_USBPORTStyle_ProcessURB(undefined8 param_1,longlong param_2,short *param_3)

{
  char *pcVar1;
  longlong lVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  char cVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong *plVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  bool bVar18;
  bool bVar19;
  
  uVar3 = param_3[1];
  uVar13 = (ulonglong)uVar3;
  uVar17 = 0;
  *(uint *)(param_3 + 8) = *(uint *)(param_3 + 8) & 0xff000000;
  uVar14 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  if (uVar3 < 0x35) {
    lVar2 = uVar13 * 0x18;
    if ((*(short *)(&DAT_14002c108 + lVar2) == 0) ||
       (*(short *)(&DAT_14002c108 + lVar2) == *param_3)) {
      if (*(longlong *)(param_3 + 4) == 0) {
        uVar17 = 0x80000300;
        uVar14 = 0xc000000d;
      }
      else {
        puVar11 = (undefined8 *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(longlong *)(param_3 + 4),
                             PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        if (*(char *)((longlong)puVar11 + 0x19c) == '\0') {
          uVar16 = 0;
          if ((*(uint *)(&DAT_14002c110 + lVar2) & 1) == 0) {
            if ((*(uint *)(&DAT_14002c110 + lVar2) & 0x40) != 0) {
              puVar5 = *(undefined8 **)(param_3 + 0xc);
              cVar9 = Urb_ValidatePipeHandle((longlong)puVar11,puVar5);
              if (cVar9 == '\0') {
                uVar17 = 0x80000600;
LAB_140005841:
                uVar14 = 0xc000000d;
                goto LAB_140005593;
              }
              uVar16 = *puVar5;
              if (*(int *)(puVar5 + 2) == 1) goto LAB_140005593;
            }
LAB_1400055d7:
            param_3[2] = 0;
            param_3[3] = 0x4000;
            uVar14 = (**(code **)(&UrbDispatchTable + uVar13 * 0x18))
                               (param_1,param_2,param_3,uVar16);
            goto LAB_140005605;
          }
          uVar10 = KeGetCurrentProcessorNumberEx(0);
          *(undefined4 *)(param_3 + 0x20) = uVar10;
          if ((*(uint *)(&DAT_14002c110 + lVar2) & 4) != 0) {
            uVar16 = puVar11[0x20];
            *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | 8;
            *(undefined8 *)(param_3 + 0xc) = uVar16;
          }
          if (((*(uint *)(param_3 + 0x10) & 8) != 0) && ((uVar3 == 8 || (uVar3 == 0x32)))) {
            *(undefined8 *)(param_3 + 0xc) = puVar11[0x20];
          }
          if ((*(longlong *)(param_3 + 0x1c) == 0) || (uVar3 == 0x32)) {
            if ((*(uint *)(&DAT_14002c110 + uVar13 * 0x18) & 8) != 0) {
              param_3[0x14] = 0;
              param_3[0x15] = 0;
              param_3[0x16] = 0;
              param_3[0x17] = 0;
              param_3[0x18] = 0;
              param_3[0x19] = 0;
              param_3[0x1a] = 0;
              param_3[0x1b] = 0;
              param_3[0x12] = 0;
              param_3[0x13] = 0;
            }
            puVar5 = *(undefined8 **)(param_3 + 0xc);
            if ((puVar5 == (undefined8 *)0x0) || (*(char *)(puVar5 + 1) != '\0')) {
LAB_140005630:
              puVar11 = puVar11 + 0x3a;
              bVar18 = false;
              puVar12 = (undefined8 *)*puVar11;
              if (puVar11 != puVar12) {
                do {
                  pcVar1 = (char *)((longlong)puVar12 + 0x52);
                  puVar12 = (undefined8 *)*puVar12;
                  if (*pcVar1 != '\0') {
                    bVar18 = true;
                  }
                } while (puVar11 != puVar12);
                if (bVar18) {
                  DbgPrint("Client attempted I/O on stale or invalid pipe handle 0x%p",puVar5);
                  cVar9 = KdRefreshDebuggerNotPresent();
                  if (cVar9 == '\0') {
                    pcVar7 = (code *)swi(3);
                    uVar13 = (*pcVar7)();
                    return uVar13;
                  }
                }
              }
              uVar17 = 0x80000600;
              uVar14 = 0xc000000d;
            }
            else {
              if (*(char *)((longlong)puVar11 + 0x1a1) == '\0') {
                if ((undefined8 *)puVar5[4] != puVar5) goto LAB_140005630;
              }
              else {
                bVar18 = false;
                uVar8 = KeAcquireSpinLockRaiseToDpc(puVar11 + 0x10);
                for (puVar12 = (undefined8 *)puVar11[0xe]; puVar11 != puVar12 + -0xe;
                    puVar12 = (undefined8 *)*puVar12) {
                  if (puVar5 == puVar12 + -0x20) {
                    bVar18 = true;
                    break;
                  }
                }
                KeReleaseSpinLock(puVar11 + 0x10,uVar8);
                if (!bVar18) goto LAB_140005630;
              }
              uVar16 = *puVar5;
              if (*(int *)(puVar5 + 2) == 1) {
                uVar17 = 0x80000300;
                uVar14 = 0xc000000d;
              }
              else {
                if (uVar3 != 9) {
                  if (uVar3 == 10) {
                    if (*(int *)((longlong)puVar5 + 0xc) != 3) {
                      uVar17 = 0x80000600;
                      uVar14 = 0xc000000d;
                      goto LAB_140005593;
                    }
                  }
                  else if ((uVar3 == 0x32) || (uVar3 == 8)) {
                    if (*(int *)((longlong)puVar5 + 0xc) != 1) {
                      uVar17 = 0x80000600;
                      uVar14 = 0xc000000d;
                    }
                    uVar4 = *(uint *)(param_3 + 0x12);
                    if ((uVar4 <= *(uint *)((longlong)puVar5 + 0x14)) ||
                       ((*(uint *)(param_3 + 8) & 0x40000000) != 0)) {
                      bVar18 = uVar4 < 0xffff;
                      bVar19 = uVar4 == 0xffff;
                      goto LAB_140005584;
                    }
                    goto LAB_14000583b;
                  }
LAB_14000566d:
                  uVar14 = *(uint *)(param_3 + 0x12);
                  if (uVar14 == 0) {
                    if (*(longlong *)(param_3 + 0x18) == 0) goto LAB_140005683;
                  }
                  else if ((*(longlong *)(param_3 + 0x14) != 0) ||
                          (*(longlong *)(param_3 + 0x18) != 0)) {
LAB_140005683:
                    if ((*(int *)((longlong)puVar5 + 0xc) != 1) ||
                       (((uVar14 <= *(uint *)((longlong)puVar5 + 0x14) ||
                         ((*(uint *)(param_3 + 8) & 0x40000000) != 0)) && (uVar14 < 0x10000)))) {
                      plVar6 = *(longlong **)(param_3 + 0x18);
                      if (((plVar6 != (longlong *)0x0) &&
                          (plVar15 = (longlong *)*plVar6, plVar15 != (longlong *)0x0)) &&
                         (uVar4 = *(uint *)(plVar6 + 5), uVar4 < uVar14)) {
                        if ((*(int *)((longlong)plVar6 + 0x2c) + uVar4 & 0xfff) == 0) {
                          uVar14 = uVar14 - uVar4;
                          while( true ) {
                            uVar4 = *(uint *)(plVar15 + 5);
                            if (uVar14 <= uVar4) break;
                            if ((*(int *)((longlong)plVar15 + 0x2c) != 0) || ((uVar4 & 0xfff) != 0))
                            goto LAB_1400056e8;
                            plVar15 = (longlong *)*plVar15;
                            uVar14 = uVar14 - uVar4;
                            if (plVar15 == (longlong *)0x0) goto LAB_1400056e8;
                          }
                          if (*(int *)((longlong)plVar15 + 0x2c) == 0) goto LAB_1400055d7;
                        }
LAB_1400056e8:
                        if (*(char *)(puVar11[3] + 0x3f9) != '\0') {
                    /* WARNING: Subroutine does not return */
                          KeBugCheckEx(0x144,0x807,*(undefined8 *)(param_3 + 0x18),param_3,0);
                        }
                      }
                      goto LAB_1400055d7;
                    }
                  }
LAB_14000583b:
                  uVar17 = 0x80000300;
                  goto LAB_140005841;
                }
                if ((*(int *)((longlong)puVar5 + 0xc) - 2U & 0xfffffffd) != 0) {
                  uVar17 = 0x80000600;
                  uVar14 = 0xc000000d;
                }
                bVar18 = *(uint *)(param_3 + 0x12) < *(uint *)((longlong)puVar5 + 0x14);
                bVar19 = *(uint *)(param_3 + 0x12) == *(uint *)((longlong)puVar5 + 0x14);
LAB_140005584:
                if (!bVar18 && !bVar19) goto LAB_14000583b;
                if (-1 < (int)uVar14) goto LAB_14000566d;
              }
            }
          }
          else {
            uVar17 = 0x80000300;
            uVar14 = 0xc000000d;
          }
        }
        else {
          uVar17 = 0xc0007000;
          uVar14 = 0xc000000e;
        }
      }
    }
    else {
      uVar17 = 0x80000300;
      uVar14 = 0xc000000d;
    }
  }
  else {
    uVar17 = 0x80000200;
    uVar14 = 0xc000000d;
  }
LAB_140005593:
  if (param_2 != 0) {
    if (param_3 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
      param_3[-0x22] = 0;
      param_3[-0x21] = -0x5433;
    }
    *(undefined4 *)(param_3 + 2) = uVar17;
    *(uint *)(param_2 + 0x30) = uVar14;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
  }
LAB_140005605:
  return (ulonglong)uVar14;
}



===== Xrb_ProcessURB @ 140005940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint Xrb_ProcessURB(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4,
                   short *param_5)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined1 uVar13;
  char *pcVar14;
  undefined *puVar15;
  undefined8 *puVar16;
  undefined1 auStackY_d8 [32];
  undefined1 uVar17;
  undefined1 uVar18;
  undefined8 in_stack_ffffffffffffff70;
  undefined8 in_stack_ffffffffffffff80;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  sVar2 = param_5[1];
  if (sVar2 == 0x35) {
    uVar7 = Endpoint_StaticStreamsEnableUrb
                      (*(longlong *)(param_5 + 0xc) + -0x10,param_1,param_4,param_2);
    return uVar7;
  }
  uVar13 = (undefined1)param_2;
  if (sVar2 == 10) goto switchD_140005d8f_caseD_9;
  switch(sVar2) {
  case 9:
    goto switchD_140005d8f_caseD_9;
  default:
    uVar12 = Urb_USBPORTStyle_ProcessURB(param_1,param_2,param_5);
    uVar7 = (uint)uVar12;
    break;
  case 0x36:
    if (*(char *)(*(longlong *)(*(longlong *)(param_5 + 0xc) + 0x30) + 0x474) == '\0') {
      uVar7 = 0;
      LogWppMsgForCloseStaticStreamOnDx(uVar13);
      if (param_5 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        param_5[-0x22] = 0;
        param_5[-0x21] = -0x5433;
      }
      param_5[2] = 0;
      param_5[3] = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
LAB_140005f25:
      IofCompleteRequest(param_2,0);
      return uVar7;
    }
    uVar7 = Endpoint_StaticStreamsDisableUrb
                      (*(longlong *)(param_5 + 0xc) + -0x10,param_1,param_4,param_2);
    break;
  case 0x37:
  case 0x38:
    if (*(char *)(*(longlong *)(param_4 + 0x18) + 0x89) == '\0') {
      if (*(char *)(*(longlong *)(param_4 + 0x18) + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x806,param_2,param_4 + 0x50);
      }
      uVar7 = 0xc000000d;
      if (param_5 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        param_5[-0x22] = 0;
        param_5[-0x21] = -0x5433;
      }
      param_5[2] = 0x300;
      param_5[3] = -0x8000;
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      goto LAB_140005f25;
    }
    goto switchD_140005d8f_caseD_9;
  case 0x39:
  case 0x3a:
    if (*(char *)(*(longlong *)(param_4 + 0x18) + 0x8c) == '\0') {
      if (*(char *)(*(longlong *)(param_4 + 0x18) + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x806,param_2,param_4 + 0x50);
      }
      if (param_5 == *(short **)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
        param_5[-0x22] = 0;
        param_5[-0x21] = -0x5433;
      }
      param_5[2] = 0x300;
      param_5[3] = -0x8000;
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
      IofCompleteRequest(param_2,0);
      return 0xc000000d;
    }
switchD_140005d8f_caseD_9:
    puVar3 = *(undefined8 **)(param_5 + 0xc);
    if (*(char *)((longlong)puVar3 + 9) == '\0') {
      *(uint *)(param_5 + 0x10) = *(uint *)(param_5 + 0x10) & 0xfffffffe;
    }
    else {
      *(uint *)(param_5 + 0x10) = *(uint *)(param_5 + 0x10) | 1;
    }
    uVar6 = KeGetCurrentProcessorNumberEx(0);
    *(undefined4 *)(param_5 + 0x20) = uVar6;
    switch(param_5[1]) {
    default:
      *(uint *)(param_5 + 8) = *(uint *)(param_5 + 8) & 0xdfffffff;
      bVar5 = KeGetCurrentIrql();
      if ((((bVar5 < 2) && (*(longlong *)(param_5 + 0x18) == 0)) &&
          (*(longlong *)(param_5 + 0x14) != 0)) && (*(int *)(param_5 + 0x12) != 0)) {
        UCX_LockBufferPagesInUrbForDMA((longlong)param_5);
      }
      break;
    case 0x39:
    case 0x3a:
      break;
    }
    param_5[2] = 0;
    param_5[3] = 0x4000;
    local_50 = 0;
    uStack_48 = 0;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) goto LAB_140005a72;
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar8 = -0x3ffffddb;
    }
    else {
      iVar8 = (*g_IoGetActivityIdIrp)(param_2,&local_50);
    }
    uVar4 = *(undefined8 *)(param_5 + 4);
    lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    uVar7 = (ushort)param_5[1] - 9;
    uVar11 = *(undefined8 *)(*(longlong *)(lVar9 + 0x18) + 0x28);
    if (uVar7 < 0x32) {
      pcVar14 = IMAGE_DOS_HEADER_140000000.e_magic +
                (&switchD_140005d15::switchdataD_140028901)
                [(&switchD_140005d15::switchdataD_140028915)[(int)uVar7]];
      uVar17 = (undefined1)uVar4;
      uVar18 = SUB81(param_5,0);
      switch(param_5[1]) {
      case 9:
      case 0x37:
        if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
          puVar16 = &local_50;
          if (iVar8 < 0) {
            puVar16 = (undefined8 *)0x0;
          }
          McTemplateK0pppppn_EtwWriteTransfer
                    (pcVar14,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER,puVar16
                     ,uVar11,uVar17,(char)*(undefined8 *)(param_5 + 0xc),uVar13,uVar18,0x80,param_5)
          ;
        }
        break;
      case 10:
      case 0x38:
        if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
          puVar15 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_ISOCH_TRANSFER;
LAB_140005e20:
          puVar16 = &local_50;
          if (iVar8 < 0) {
            puVar16 = (undefined8 *)0x0;
          }
          McTemplateK0ppppphnNR5_EtwWriteTransfer
                    (pcVar14,puVar15,puVar16,uVar11,uVar17,(char)*(undefined8 *)(param_5 + 0xc),
                     uVar13,uVar18,param_5[0x42],in_stack_ffffffffffffff70,param_5,
                     in_stack_ffffffffffffff80,param_5 + 0x46);
        }
        break;
      case 0x39:
        if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
          puVar16 = &local_50;
          if (iVar8 < 0) {
            puVar16 = (undefined8 *)0x0;
          }
          McTemplateK0pppppn_EtwWriteTransfer
                    (pcVar14,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_BULK_OR_INTERRUPT_TRANSFER,
                     puVar16,uVar11,uVar17,(char)*(undefined8 *)(param_5 + 0xc),uVar13,uVar18,0x80,
                     param_5);
        }
        break;
      case 0x3a:
        if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
          puVar15 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SECURE_ISOCH_TRANSFER;
          goto LAB_140005e20;
        }
      }
    }
LAB_140005a72:
    if (*(longlong *)(param_4 + 0x28) == 0) {
      uVar4 = *puVar3;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
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
      uVar11 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
      iVar8 = IoSetCompletionRoutineEx(uVar11,param_2,Xrb_BulkInterruptIsochCompletion,param_5);
      if (iVar8 < 0) {
        lVar9 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar9 + -0x10) = Xrb_BulkInterruptIsochCompletion;
        *(short **)(lVar9 + -8) = param_5;
        *(undefined1 *)(lVar9 + -0x45) = 0xe0;
      }
      (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,uVar4);
    }
    else {
      local_60 = 0;
      local_68 = 0x18;
      local_64 = 3;
      local_58 = param_2;
      (**(code **)(WdfFunctions_01015 + 0x7c8))
                (WdfDriverGlobals,*(longlong *)(param_4 + 0x28),&local_68);
      uVar4 = *puVar3;
      uVar11 = *(undefined8 *)(param_4 + 0x28);
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
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
      uVar10 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
      iVar8 = IoSetCompletionRoutineEx(uVar10,param_2,Xrb_BulkInterruptIsochCompletion,param_5);
      if (iVar8 < 0) {
        lVar9 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar9 + -0x10) = Xrb_BulkInterruptIsochCompletion;
        *(short **)(lVar9 + -8) = param_5;
        *(undefined1 *)(lVar9 + -0x45) = 0xe0;
      }
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
      local_50 = 0x100000008;
      iVar8 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,uVar11,uVar4,&local_50);
      if (iVar8 < 0) {
        if (iVar8 == -0x3fdffdfc) {
          iVar8 = -0x3ffffff2;
        }
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar11,iVar8);
        return 0x103;
      }
    }
    return 0x103;
  case 0x3c:
    uVar7 = Endpoint_ProcessResetNotificationRequest
                      (*(longlong *)(param_5 + 0xc) + -0x10,param_4,param_2);
    break;
  case 0x3d:
    uVar7 = Endpoint_GetIsochPipeTransferPathDelaysUrb
                      (*(longlong *)(param_5 + 0xc) + -0x10,param_4,param_2);
  }
  return uVar7;
}



===== Usbd_BusQueryBusTime @ 140006070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 Usbd_BusQueryBusTime(undefined8 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  
  if (param_2 == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x10,
                       &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids);
    }
    uVar6 = 0xc000000d;
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    lVar7 = *(longlong *)(lVar7 + 0x18);
    if (*(longlong *)(lVar7 + 0x48) == 0) {
      uVar6 = 0xc00000bb;
    }
    else {
      LOCK();
      *(int *)(lVar7 + 0x3ec) = *(int *)(lVar7 + 0x3ec) + 1;
      UNLOCK();
      if (*(char *)(lVar7 + 0x3f0) == '\0') {
        uVar6 = (**(code **)(lVar7 + 0x48))(*(undefined8 *)(lVar7 + 0x28),param_2);
        *(undefined4 *)(lVar7 + 0x3d8) = *param_2;
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x5e,
                             &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)*param_2,
                             (char)uVar6);
        }
        iVar3 = *(int *)(lVar7 + 1000);
        LOCK();
        piVar1 = (int *)(lVar7 + 0x3ec);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          uVar5 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x3e0);
          if ((*(char *)(lVar7 + 0x3f1) == '\0') && (iVar3 == *(int *)(lVar7 + 1000))) {
            *(undefined1 *)(lVar7 + 0x3f1) = 1;
            KeReleaseSpinLock(lVar7 + 0x3e0,uVar5);
            StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
          }
          else {
            KeReleaseSpinLock(lVar7 + 0x3e0,uVar5);
          }
        }
      }
      else {
        iVar3 = *(int *)(lVar7 + 1000);
        LOCK();
        piVar1 = (int *)(lVar7 + 0x3ec);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          uVar5 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x3e0);
          if (*(char *)(lVar7 + 0x3f1) == '\0') {
            if (iVar3 == *(int *)(lVar7 + 1000)) {
              *(undefined1 *)(lVar7 + 0x3f1) = 1;
              KeReleaseSpinLock(lVar7 + 0x3e0,uVar5);
              StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
            }
            else {
              KeReleaseSpinLock();
            }
          }
          else {
            KeReleaseSpinLock();
          }
        }
        uVar6 = 0;
        uVar4 = *(undefined4 *)(lVar7 + 0x3d8);
        *param_2 = uVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5f,
                            &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar4);
        }
      }
    }
  }
  return uVar6;
}



===== UrbHandler_GetCurrentFrame @ 140006320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UrbHandler_GetCurrentFrame(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                     PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  iVar1 = Controller_GetCurrentFrameNumber(*(longlong *)(lVar2 + 0x18),local_res10);
  if (iVar1 < 0) {
    local_res10[0] = 0;
  }
  *(undefined4 *)(param_3 + 0x18) = local_res10[0];
  if (iVar1 == -0x3ffffff2) {
    uVar3 = 0xc0007000;
  }
  else if (iVar1 == -0x3fffff66) {
    uVar3 = 0xc0001000;
  }
  else if (iVar1 == -0x3fffff45) {
    uVar3 = 0xc0000e00;
  }
  else if (iVar1 == -0x3ffffee0) {
    uVar3 = 0xc0010000;
  }
  else {
    uVar3 = -(uint)(iVar1 != 0) & 0x80000300;
  }
  if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
  }
  *(uint *)(param_3 + 4) = uVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== Controller_GetCurrentFrameNumber @ 140006420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 Controller_GetCurrentFrameNumber(longlong param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  
  if (*(longlong *)(param_1 + 0x48) == 0) {
    return 0xc00000bb;
  }
  LOCK();
  *(int *)(param_1 + 0x3ec) = *(int *)(param_1 + 0x3ec) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0x3f0) == '\0') {
    uVar5 = (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x3d8) = *param_2;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x5e,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)*param_2,(char)uVar5
                        );
    }
    iVar3 = *(int *)(param_1 + 1000);
    LOCK();
    piVar1 = (int *)(param_1 + 0x3ec);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x3e0);
      if ((*(char *)(param_1 + 0x3f1) == '\0') && (iVar3 == *(int *)(param_1 + 1000))) {
        *(undefined1 *)(param_1 + 0x3f1) = 1;
        KeReleaseSpinLock(param_1 + 0x3e0,uVar4);
        StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(param_1 + 0x3e0,uVar4);
      }
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 1000);
    LOCK();
    piVar1 = (int *)(param_1 + 0x3ec);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x3e0);
      if (*(char *)(param_1 + 0x3f1) == '\0') {
        if (iVar3 == *(int *)(param_1 + 1000)) {
          *(undefined1 *)(param_1 + 0x3f1) = 1;
          KeReleaseSpinLock(param_1 + 0x3e0,uVar4);
          StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock();
        }
      }
      else {
        KeReleaseSpinLock();
      }
    }
    uVar5 = *(undefined4 *)(param_1 + 0x3d8);
    *param_2 = uVar5;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5f,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar5);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== Urb_ValidatePipeHandle @ 140006660 =====

char Urb_ValidatePipeHandle(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  char *pcVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  char cVar7;
  undefined8 *puVar8;
  
  if ((param_2 != (undefined8 *)0x0) && (*(char *)(param_2 + 1) == '\0')) {
    if (*(char *)(param_1 + 0x1a1) == '\0') {
      if ((undefined8 *)param_2[4] == param_2) {
        return '\x01';
      }
    }
    else {
      cVar7 = '\0';
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x80);
      for (puVar8 = *(undefined8 **)(param_1 + 0x70); (undefined8 *)(param_1 + 0x70) != puVar8;
          puVar8 = (undefined8 *)*puVar8) {
        if (param_2 == puVar8 + -0x20) {
          cVar7 = '\x01';
          break;
        }
      }
      KeReleaseSpinLock(param_1 + 0x80,uVar6);
      if (cVar7 != '\0') {
        return cVar7;
      }
    }
  }
  plVar1 = (longlong *)(param_1 + 0x1d0);
  bVar5 = false;
  plVar3 = (longlong *)*plVar1;
  if (plVar1 != plVar3) {
    do {
      pcVar2 = (char *)((longlong)plVar3 + 0x52);
      plVar3 = (longlong *)*plVar3;
      if (*pcVar2 != '\0') {
        bVar5 = true;
      }
    } while (plVar1 != plVar3);
    if (bVar5) {
      DbgPrint("Client attempted I/O on stale or invalid pipe handle 0x%p",param_2);
      cVar7 = KdRefreshDebuggerNotPresent();
      if (cVar7 == '\0') {
        pcVar4 = (code *)swi(3);
        cVar7 = (*pcVar4)();
        return cVar7;
      }
    }
  }
  return '\0';
}



===== UCX_UNLOCK_BUFFER_PAGES_IN_URB_AFTER_DMA @ 1400067a0 =====

void UCX_UNLOCK_BUFFER_PAGES_IN_URB_AFTER_DMA(longlong param_1)

{
  switch(*(undefined2 *)(param_1 + 2)) {
  default:
    if ((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) {
      MmUnlockPages(*(undefined8 *)(param_1 + 0x30));
      IoFreeMdl(*(undefined8 *)(param_1 + 0x30));
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xdfffffff;
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    break;
  case 0x39:
  case 0x3a:
    break;
  }
  return;
}



===== IS_TRANSFER_URB_SECURE @ 140006820 =====

uint IS_TRANSFER_URB_SECURE(longlong param_1)

{
  switch(*(ushort *)(param_1 + 2) - 8) {
  default:
    return 0;
  case 0x31:
  case 0x32:
    return 1;
  }
}



===== Xrb_UrbCompletion @ 140006860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Xrb_UrbCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  iVar2 = *(int *)(param_3 + 4);
  if (iVar2 == 0x40000000) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if (*(char *)(lVar4 + 0x19c) == '\0') {
      *(undefined4 *)(param_3 + 4) = 0xc0010000;
    }
    else {
      *(undefined4 *)(param_3 + 4) = 0xc0007000;
      *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    }
    goto LAB_140006939;
  }
  if (iVar2 < -0x3fffefff) {
    if (iVar2 == -0x3ffff000) {
      uVar3 = 0xc000009a;
    }
    else if ((((iVar2 == -0x7ffffe00) || (iVar2 == -0x7ffffd00)) || (iVar2 == -0x7ffffa00)) ||
            (iVar2 == -0x3ffff600)) {
      uVar3 = 0xc000000d;
    }
    else if (iVar2 == -0x3ffff200) {
      uVar3 = 0xc00000bb;
    }
    else {
LAB_14000691f:
      uVar3 = 0xc0000001;
    }
  }
  else if (iVar2 == -0x3fff9000) {
    uVar3 = 0xc000000e;
  }
  else if (iVar2 == -0x3fff0000) {
    uVar3 = 0xc0000120;
  }
  else {
    if ((iVar2 != 0) && (iVar2 != 1)) goto LAB_14000691f;
    uVar3 = 0;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
LAB_140006939:
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (*(short *)(param_3 + 2) == 0x35) {
    Endpoint_StaticStreamsEnableUrbCompleteFromHcd
              (*(longlong *)(param_3 + 0x18) - 0x10,param_3,param_2);
  }
  else {
    if (*(short *)(param_3 + 2) != 0x36) {
      *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
      return 0;
    }
    lVar4 = *(longlong *)(param_3 + 0x18);
    *(longlong *)(lVar4 + 0x2b8) = param_2;
    StateMachineEngine_EventAdd((undefined8 *)(lVar4 + 0x110),0xebe30131);
  }
  return 0xc0000016;
}



===== Endpoint_StaticStreamsEnableUrbCompleteFromHcd @ 1400069ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_StaticStreamsEnableUrbCompleteFromHcd
               (ulonglong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x50);
  if (*(int *)(param_3 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x29,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,
                        (char)*(int *)(param_3 + 0x30));
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + 0x1e8);
    *(undefined8 *)(param_1 + 0x50) = 0;
    KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + 0x1e8,uVar4);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8));
  }
  else {
    uVar5 = param_1;
    uVar7 = 0;
    if (*(int *)(lVar2 + 4) != 0) {
      do {
        lVar3 = *(longlong *)(param_2 + 0x28);
        uVar6 = (int)uVar7 + 1;
        *(ulonglong *)(lVar3 + uVar7 * 0x18) = *(longlong *)(lVar2 + 0x20) + 0x10 + uVar7 * 0x48;
        *(undefined4 *)(lVar3 + 8 + uVar7 * 0x18) =
             *(undefined4 *)(*(longlong *)(lVar2 + 0x20) + 0x40 + uVar7 * 0x48);
        uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x20) + 0x24 + uVar7 * 0x48);
        uVar5 = (ulonglong)uVar1;
        *(undefined4 *)(lVar3 + 0x10 + uVar7 * 0x18) = 0;
        *(uint *)(lVar3 + 0xc + uVar7 * 0x18) = uVar1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < *(uint *)(lVar2 + 4));
    }
    Etw_UcxStaticStreamsCreate(uVar5,lVar2);
  }
  if ((*(uint *)(param_1 + 0x2d0) & 1) == 0) {
    *(longlong *)(param_1 + 0x2c8) = param_3;
    StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x120),0xebe30151);
  }
  else {
    *(uint *)(param_1 + 0x2d0) = *(uint *)(param_1 + 0x2d0) & 0xfffffffe;
    LOCK();
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
    UNLOCK();
    lVar2 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 8);
    if (lVar2 == *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x30)) {
      *(undefined4 *)(lVar2 + -0x44) = 0xabcd0000;
    }
    IofCompleteRequest(param_3,0);
  }
  return;
}



===== UsbDevice_Disconnect @ 140006b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_Disconnect(undefined8 param_1,int param_2)

{
  longlong lVar1;
  longlong ***ppplVar2;
  longlong ***ppplVar3;
  longlong ****pppplVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong ****pppplVar9;
  longlong ****local_18;
  longlong ****local_10;
  
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar1 = *(longlong *)(lVar7 + 0x18);
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x1e8);
  if (param_2 == 0) {
    UsbDevice_WalkTree(lVar7,'\0',UsbDevice_DisconnectCallback,&local_18);
  }
  else {
    for (puVar8 = *(undefined8 **)(lVar7 + 0x30); (undefined8 *)(lVar7 + 0x30) != puVar8;
        puVar8 = (undefined8 *)*puVar8) {
      if (*(int *)((longlong)puVar8 + (ulonglong)(*(int *)((longlong)puVar8 + 0xdc) - 1) * 4 + 0xe4)
          == param_2) {
        UsbDevice_WalkTree((longlong)(puVar8 + -8),'\0',UsbDevice_DisconnectCallback,&local_18);
      }
    }
  }
  KeReleaseSpinLock(lVar1 + 0x1e8,uVar6);
  pppplVar9 = local_18;
  while( true ) {
    pppplVar4 = (longlong ****)*pppplVar9;
    if (&local_18 == (longlong *****)pppplVar9) {
      return;
    }
    ppplVar2 = *pppplVar9;
    if (((longlong ****)ppplVar2[1] != pppplVar9) ||
       (ppplVar3 = pppplVar9[1], (longlong ****)*ppplVar3 != pppplVar9)) break;
    *ppplVar3 = (longlong **)ppplVar2;
    ppplVar2[1] = (longlong **)ppplVar3;
    pppplVar9[1] = (longlong ***)0x0;
    *pppplVar9 = (longlong ***)0x0;
    if (*(char *)((longlong)pppplVar9 + 0x22b) != '\0') {
      StateMachineEngine_EventAdd(pppplVar9 + 10,0xebe30070);
    }
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,pppplVar9[-0x19],UsbDevice_DisconnectCallback,0x26d,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
    pppplVar9 = pppplVar4;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== Controller_NotifyUsbDevicesAndEndpointsOfControllerResetComplete @ 140006cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_NotifyUsbDevicesAndEndpointsOfControllerResetComplete
               (longlong param_1,undefined8 param_2)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  longlong ****pppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong ****pppplVar6;
  undefined7 uVar7;
  longlong ****local_28;
  longlong ****local_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_20 = (longlong ****)&local_28;
  local_28 = (longlong ****)&local_28;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1e8);
  uVar7 = (undefined7)((ulonglong)param_2 >> 8);
  UsbDevice_WalkTree(*(longlong *)(*(longlong *)(param_1 + 0x158) + 0xb8),'\x01',
                     UsbDevice_NotifyControllerResetCompleteCallback,&local_28);
  KeReleaseSpinLock(param_1 + 0x1e8,CONCAT71(uVar7,uVar5));
  pppplVar6 = local_28;
  while( true ) {
    pppplVar3 = (longlong ****)*pppplVar6;
    if (&local_28 == (longlong *****)pppplVar6) {
      return;
    }
    ppplVar1 = *pppplVar6;
    if (((longlong ****)ppplVar1[1] != pppplVar6) ||
       (ppplVar2 = pppplVar6[1], (longlong ****)*ppplVar2 != pppplVar6)) break;
    *ppplVar2 = (longlong **)ppplVar1;
    ppplVar1[1] = (longlong **)ppplVar2;
    pppplVar6[1] = (longlong ***)0x0;
    *pppplVar6 = (longlong ***)0x0;
    StateMachineEngine_EventAdd(pppplVar6 + 8,0xebe3004f);
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,pppplVar6[-0x1b],UsbDevice_NotifyControllerResetCompleteCallback,
               0xb56,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\controller.c");
    pppplVar6 = pppplVar3;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== UrbHandler_AbortPipe @ 140006e30 =====

undefined8 UrbHandler_AbortPipe(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_3 + 0x18);
  lVar2 = *(longlong *)(lVar1 + 0x30);
  uVar3 = StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x110),0xebe30020);
  if ((char)uVar3 == '\0') {
    uVar3 = 0xc000000e;
    if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
      *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
    }
    *(undefined4 *)(param_3 + 4) = 0xc0007000;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
  }
  else {
    IoCsqInsertIrp(lVar2 + 0x1a0,param_2,lVar1 + 0x2c8);
    uVar3 = 0x103;
    StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x110),0xebe30031);
  }
  return uVar3;
}



===== UsbDevice_ResetFromHub @ 140006f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_ResetFromHub(longlong param_1,undefined8 param_2,char param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),
                     PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  local_28 = 0;
  lStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  uVar1 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x18) + 0x1e8);
  if ((*(char *)(param_1 + 0x1a0) == '\0') && (*(char *)(lVar2 + 0x19f) != '\0')) {
    *(undefined1 *)(param_1 + 0x1a0) = 1;
  }
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x18) + 0x1e8,uVar1);
  pcVar3 = UsbDevice_PendResetRequestDueToControllerReset;
  if (param_3 == '\0') {
    pcVar3 = UsbDevice_ForwardResetToHcd;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x25,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_2);
  }
  lVar2 = lStack_40;
  *(code **)(param_1 + 0x180) = pcVar3;
  *(undefined8 *)(param_1 + 400) = param_2;
  *(int *)(param_1 + 0x188) = *(int *)(lStack_40 + 0x20) + 1;
  UsbDevice_AddEventForEndpoints
            (*(undefined8 **)(lStack_40 + 0x28),*(uint *)(lStack_40 + 0x20),0xebe30190);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),
                     PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  StateMachineEngine_EventAdd((undefined8 *)(lVar2 + 0x120),0xebe30190);
  return;
}



===== UsbDevice_TreePurgeFromHub @ 1400070b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_TreePurgeFromHub(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong ***ppplVar2;
  longlong ***ppplVar3;
  longlong ****pppplVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong ****pppplVar7;
  undefined8 uVar8;
  undefined7 uVar9;
  longlong ****local_28;
  longlong ****local_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_20 = (longlong ****)&local_28;
  local_18 = 0;
  local_28 = (longlong ****)&local_28;
  uVar8 = param_2;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x1e8);
  uVar9 = (undefined7)((ulonglong)uVar8 >> 8);
  UsbDevice_WalkTree(param_1,'\x01',UsbDevice_TreePurgeCallback,&local_28);
  KeReleaseSpinLock(lVar1 + 0x1e8,CONCAT71(uVar9,uVar6));
  *(undefined8 *)(lVar1 + 0x488) = param_2;
  *(undefined4 *)(lVar1 + 0x490) = (undefined4)local_18;
  pppplVar7 = local_28;
  while( true ) {
    pppplVar4 = (longlong ****)*pppplVar7;
    if (&local_28 == (longlong *****)pppplVar7) {
      return;
    }
    ppplVar2 = *pppplVar7;
    if (((longlong ****)ppplVar2[1] != pppplVar7) ||
       (ppplVar3 = pppplVar7[1], (longlong ****)*ppplVar3 != pppplVar7)) break;
    *ppplVar3 = (longlong **)ppplVar2;
    ppplVar2[1] = (longlong **)ppplVar3;
    pppplVar7[1] = (longlong ***)0x0;
    *pppplVar7 = (longlong ***)0x0;
    StateMachineEngine_EventAdd(pppplVar7 + 6,0xebe301b0);
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,pppplVar7[-0x1d],UsbDevice_TreePurgeCallback,0xba7,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
    pppplVar7 = pppplVar4;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== UsbDevice_EndpointsConfigureFromHub @ 140007214 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_EndpointsConfigureFromHub(longlong param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 auStackY_88 [32];
  undefined1 uVar3;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  lStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_58 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  lVar1 = lStack_50;
  uVar3 = (undefined1)param_2;
  if (*(int *)(lStack_50 + 0x28) == 0) {
    if (param_3 == '\0') {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x27,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar3);
      }
      (**(code **)(param_1 + 0x90))(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x28),param_2);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x26,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar3);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000000e);
    }
  }
  else {
    pcVar2 = UsbDevice_PendEndpointsConfigureDueToControllerReset;
    if (param_3 == '\0') {
      pcVar2 = UsbDevice_ForwardEndpointsConfigureToHcd;
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar3);
    }
    *(undefined8 *)(param_1 + 400) = param_2;
    *(code **)(param_1 + 0x180) = pcVar2;
    *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(lVar1 + 0x28);
    UsbDevice_AddEventForEndpoints
              (*(undefined8 **)(lVar1 + 0x30),*(uint *)(lVar1 + 0x28),0xebe300d0);
  }
  return;
}



===== UsbDevice_AddEventForEndpoints @ 1400073fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_AddEventForEndpoints(undefined8 *param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (param_2 != 0) {
    uVar2 = (ulonglong)param_2;
    do {
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*param_1,
                         PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
      StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),param_3);
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== UsbDevice_ResetCompleteFromHcd @ 14000746c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_ResetCompleteFromHcd(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((*(int *)(param_1 + 0x30) < 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2e,
                       &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_1,
                       (char)*(int *)(param_1 + 0x30));
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x10),
                     PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2f,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_1);
  }
  *(undefined4 *)(lVar1 + 0x188) = 1;
  *(code **)(lVar1 + 0x180) = UsbDevice_CompleteResetIrp;
  *(longlong *)(lVar1 + 400) = param_1;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x18),
                     PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe30180);
  return;
}



===== Endpoint_Delete @ 1400075b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_Delete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe30050);
  return;
}



===== UsbDevice_AbortFromHub @ 1400075f8 =====

void UsbDevice_AbortFromHub(longlong *param_1,longlong param_2)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x33,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_2);
  }
  param_1[0x32] = param_2;
  param_1[0x30] = (longlong)UsbDevice_CompleteUsbDeviceAbortToHub;
  UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet(param_1,0xebe301c0);
  return;
}



===== RootHub_Pdo_EvtD0Entry @ 140007690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RootHub_Pdo_EvtD0Entry(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined1 uVar4;
  longlong lVar5;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar1 = *(longlong *)(lVar5 + 8);
  lVar5 = *(longlong *)(lVar5 + 0x10);
  lVar2 = *(longlong *)(lVar1 + 200);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x18);
  *(undefined1 *)(lVar2 + 0x41) = 0;
  KeReleaseSpinLock(lVar2 + 0x18,uVar4);
  KeWaitForSingleObject(lVar2 + 0x28,0,0,0,0);
  StateMachineEngine_EventAdd((undefined8 *)(lVar5 + 0x1f8),0xebe40060);
  *(undefined1 *)(lVar5 + 0x474) = 1;
  puVar3 = *(undefined **)(lVar1 + 400);
  if (puVar3 != (undefined *)0x0) {
    SleepstudyHelper_ComponentActive(puVar3);
  }
  return 0;
}



===== RootHub_Pdo_DeviceMgmtIrpCompletion @ 140007770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RootHub_Pdo_DeviceMgmtIrpCompletion(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x3b,
                       in_stack_ffffffffffffffd8,(char)*(undefined4 *)(lVar3 + 0x18),(char)param_2);
  }
  iVar2 = *(int *)(lVar3 + 0x18);
  if (iVar2 == 0x491017) {
    UsbDevice_DefaultEndpointEnableCompleteFromHcd(param_2,*(longlong *)(lVar3 + 8));
  }
  else if (iVar2 == 0x49101b) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar3 + 8) + 0x10),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if ((*(uint *)(lVar4 + 0x198) & 2) != 0) {
      uVar5 = *(uint *)(lVar4 + 0x198) & 0xfffffffd;
LAB_14000788a:
      *(uint *)(lVar4 + 0x198) = uVar5;
      return 0;
    }
    UsbDevice_ResetCompleteFromHcd(param_2,*(longlong *)(lVar3 + 8));
  }
  else if (iVar2 == 0x491037) {
    UsbDevice_EndpointsConfigureCompleteFromHcd(param_2,*(longlong *)(lVar3 + 8));
  }
  else {
    if (iVar2 != 0x49103f) {
      return 0;
    }
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar3 + 8) + 0x10),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if ((*(uint *)(lVar4 + 0x198) & 4) != 0) {
      uVar5 = *(uint *)(lVar4 + 0x198) & 0xfffffffb;
      goto LAB_14000788a;
    }
    Endpoint_ResetCompleteFromHcd(param_2,*(longlong *)(lVar3 + 8));
  }
  return 0xc0000016;
}



===== UsbDevice_StartFromHub @ 1400078d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_StartFromHub(longlong *param_1,longlong param_2)

{
  if ((code *)param_1[0x1c] != (code *)0x0) {
    (*(code *)param_1[0x1c])(*(undefined8 *)(param_1[3] + 0x28),param_1[2]);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x31,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_2);
  }
  param_1[0x32] = param_2;
  param_1[0x30] = (longlong)UsbDevice_CompleteUsbDeviceStartToHub;
  UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet(param_1,0xebe30120);
  return;
}



===== Endpoint_ResetCompleteFromHcd @ 140007984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_ResetCompleteFromHcd(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x18),
                     PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  *(undefined8 *)(lVar1 + 0x2c8) = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                      &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)param_1);
  }
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe30091);
  return;
}



===== UsbDevice_EvtMgmtIoInternalDeviceControl @ 140007a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_EvtMgmtIoInternalDeviceControl
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  longlong *plVar10;
  longlong lVar11;
  code *pcVar12;
  undefined8 *puVar13;
  byte bVar14;
  uint uVar15;
  char cVar16;
  undefined *puVar17;
  undefined8 uVar18;
  undefined2 uVar19;
  undefined1 auStackY_188 [32];
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  longlong local_128;
  undefined8 local_120;
  longlong lStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 local_f8;
  longlong lStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  longlong lStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_188;
  local_128 = 0;
  local_100 = 0;
  lVar11 = 0;
  lStack_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if (param_5 == 0x220003) {
    local_120 = 0x28;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_120);
    local_128 = lStack_118;
    uVar9 = (undefined1)*(undefined8 *)(lStack_118 + 8);
  }
  else {
    local_120 = 0x28;
    (**(code **)(WdfFunctions_01015 + 0x850))();
    uVar9 = (undefined1)*(undefined8 *)(lStack_118 + 0x10);
    lVar11 = lStack_118;
  }
  puVar17 = PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
  plVar10 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar7 = plVar10[3];
  uVar18 = *(undefined8 *)(lVar7 + 0x28);
  LOCK();
  *(int *)(lVar7 + 0x3ec) = *(int *)(lVar7 + 0x3ec) + 1;
  UNLOCK();
  uVar21 = (undefined1)param_2;
  uVar20 = (undefined1)param_5;
  uVar22 = (undefined1)uVar18;
  if (*(char *)(lVar7 + 0x3f0) != '\0') {
    iVar6 = *(int *)(lVar7 + 1000);
    LOCK();
    piVar1 = (int *)(lVar7 + 0x3ec);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      uVar8 = KeAcquireSpinLockRaiseToDpc();
      if ((*(char *)(lVar7 + 0x3f1) == '\0') && (iVar6 == *(int *)(lVar7 + 1000))) {
        *(undefined1 *)(lVar7 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar7 + 0x3e0,uVar8);
        StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar7 + 0x3e0,uVar8);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lqqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar17,0x45,
                 &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar20,uVar21,uVar22,uVar9);
    }
    if (param_5 != 0x220003) {
      if (param_5 == 0x49101b) {
        *(uint *)(plVar10 + 0x33) = *(uint *)(plVar10 + 0x33) | 2;
        UsbDevice_ResetFromHub((longlong)plVar10,param_2,'\x01');
        return;
      }
      if (param_5 == 0x49102b) {
        UsbDevice_DisableFromHub((longlong)plVar10,param_2,'\x01');
        return;
      }
      if (param_5 == 0x49102f) {
        UsbDevice_PurgeFromHub(plVar10,param_2,'\0');
        return;
      }
      if (param_5 == 0x491037) {
        UsbDevice_EndpointsConfigureFromHub((longlong)plVar10,param_2,'\x01');
        return;
      }
      if (param_5 == 0x49103f) {
        *(uint *)(plVar10 + 0x33) = *(uint *)(plVar10 + 0x33) | 4;
      }
      else {
        if (param_5 == 0x491053) {
          UsbDevice_TreePurgeFromHub((longlong)plVar10,param_2);
          return;
        }
        if (param_5 == 0x491057) {
          UsbDevice_AbortFromHub(plVar10,param_2);
          return;
        }
      }
      uVar18 = 0xc000000e;
LAB_140008133:
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar18);
      return;
    }
    local_100 = 0;
    lStack_118 = 0;
    local_120 = 0x28;
    local_110 = 0;
    uStack_108 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_120);
    sVar4 = *(short *)(lStack_118 + 2);
    if (sVar4 == 0x35) {
      puVar2 = (uint *)(*(longlong *)(lStack_118 + 0x18) + 0x2c0);
      *puVar2 = *puVar2 | 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x40,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)lStack_118);
      }
      uVar18 = 0xc000000e;
      goto LAB_140008133;
    }
    if (sVar4 != 0x36) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x41,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)sVar4);
      }
      uVar18 = 0xc0000010;
      goto LAB_140008133;
    }
    lVar11 = *(longlong *)(lStack_118 + 0x18);
    uVar15 = 0xebe30140;
    *(longlong *)(lVar11 + 0x2b8) = param_2;
    puVar13 = (undefined8 *)(lVar11 + 0x110);
    goto LAB_140008233;
  }
  if (*(char *)((longlong)plVar10 + 0x19e) == '\0') {
LAB_140007b2d:
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_Lqqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,WPP_GLOBAL_Control,0x48,
                 &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar20,uVar21,uVar22,uVar9);
    }
    if (param_5 < 0x491030) {
      if (param_5 == 0x49102f) {
        local_b0 = 0;
        lStack_c8 = 0;
        local_d0 = 0x28;
        local_c0 = 0;
        uStack_b8 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_d0);
        lVar11 = lStack_c8;
        plVar10 = (longlong *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(undefined8 *)(lStack_c8 + 0x10),
                             PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        cVar16 = *(char *)(lVar11 + 0x18);
LAB_140007c29:
        UsbDevice_PurgeFromHub(plVar10,param_2,cVar16);
      }
      else if (param_5 == 0x220003) {
        param_5 = (uint)*(ushort *)(local_128 + 2);
        if (param_5 != 0x35) {
          if (param_5 == 0x36) {
            lVar11 = *(longlong *)(local_128 + 0x18);
            goto LAB_1400083a9;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar19 = 0x49;
            goto LAB_1400083e0;
          }
          goto LAB_14000840b;
        }
        lVar11 = *(longlong *)(local_128 + 0x18);
        uVar15 = 0xebe30160;
        *(longlong *)(lVar11 + 0x2b8) = param_2;
        puVar13 = (undefined8 *)(lVar11 + 0x110);
LAB_140007bb1:
        StateMachineEngine_EventAdd(puVar13,uVar15);
      }
      else {
        if (param_5 == 0x491017) {
          pcVar12 = (code *)plVar10[0x13];
        }
        else {
          if (param_5 == 0x49101b) {
            cVar16 = '\0';
            goto LAB_140007df1;
          }
          if (param_5 == 0x49101f) {
            pcVar12 = (code *)plVar10[0x16];
          }
          else if (param_5 == 0x491023) {
            if (((*(uint *)(lVar11 + 0x18) & 8) != 0) && (*(char *)(lVar11 + 0x34) != '\0')) {
              *(undefined4 *)((longlong)plVar10 + 4) = 1;
            }
            if ((*(uint *)(lVar11 + 0x18) & 0x10) != 0) {
              UsbDevice_EnableInvalidHandleTracking((longlong)plVar10);
            }
            if ((*(uint *)(lVar11 + 0x18) & 1) != 0) {
              *(uint *)(plVar10 + 1) = (uint)*(ushort *)(*(longlong *)(lVar11 + 0x20) + 2);
            }
            pcVar12 = (code *)plVar10[0x17];
          }
          else {
            if (param_5 != 0x491027) {
              if (param_5 != 0x49102b) goto LAB_1400084ec;
              cVar16 = '\0';
              goto LAB_140007f21;
            }
            pcVar12 = (code *)plVar10[0x18];
          }
        }
LAB_140007dcf:
        (*pcVar12)(uVar18,param_2);
      }
    }
    else if (param_5 == 0x491033) {
      local_38 = 0;
      lStack_50 = 0;
      local_58 = 0x28;
      local_48 = 0;
      uStack_40 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
      plVar10 = (longlong *)
                (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(undefined8 *)(lStack_50 + 0x10),
                           PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      UsbDevice_StartFromHub(plVar10,param_2);
    }
    else if (param_5 == 0x491037) {
      cVar16 = '\0';
LAB_140007e8b:
      UsbDevice_EndpointsConfigureFromHub((longlong)plVar10,param_2,cVar16);
    }
    else {
      if (param_5 == 0x49103b) {
        pcVar12 = *(code **)(plVar10[0x1f] + 0x60);
        goto LAB_140007dcf;
      }
      if (param_5 == 0x49103f) {
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(lVar11 + 0x18),
                            PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
        uVar15 = 0xebe300a0;
        *(longlong *)(lVar11 + 0x2c8) = param_2;
        puVar13 = (undefined8 *)(lVar11 + 0x120);
        goto LAB_140007bb1;
      }
      if (param_5 == 0x491053) {
        local_60 = 0;
        lStack_78 = 0;
        local_80 = 0x28;
        local_70 = 0;
        uStack_68 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_80);
        plVar10 = (longlong *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(undefined8 *)(lStack_78 + 0x10),
                             PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        goto LAB_140007ed0;
      }
      if (param_5 != 0x491057) {
LAB_1400084ec:
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000840b;
        uVar19 = 0x4a;
        bVar14 = 3;
        goto LAB_1400083f0;
      }
      local_88 = 0;
      lStack_a0 = 0;
      local_a8 = 0x28;
      local_98 = 0;
      uStack_90 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_a8);
      plVar10 = (longlong *)
                (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(undefined8 *)(lStack_a0 + 0x10),
                           PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
LAB_140007d6b:
      UsbDevice_AbortFromHub(plVar10,param_2);
    }
  }
  else {
    if (param_5 == 0x491017) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x46,
                           &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar9,(char)plVar10);
      }
      *(undefined1 *)((longlong)plVar10 + 0x19e) = 0;
      goto LAB_140007b2d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Lqqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar17,0x47,
                 &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar20,uVar21,uVar22,uVar9);
    }
    if (param_5 == 0x220003) {
      local_d8 = 0;
      lStack_f0 = 0;
      local_f8 = 0x28;
      local_e8 = 0;
      uStack_e0 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_f8);
      uVar5 = *(ushort *)(lStack_f0 + 2);
      if (uVar5 == 0x35) {
        puVar2 = (uint *)(*(longlong *)(lStack_f0 + 0x18) + 0x2c0);
        *puVar2 = *puVar2 | 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x40,
                            &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)lStack_f0);
        }
LAB_140008308:
        uVar18 = 0xc000000e;
      }
      else {
        if (uVar5 == 0x36) {
          lVar11 = *(longlong *)(lStack_f0 + 0x18);
LAB_1400083a9:
          *(longlong *)(lVar11 + 0x2b8) = param_2;
          uVar15 = 0xebe30140;
          puVar13 = (undefined8 *)(lVar11 + 0x110);
          goto LAB_140007bb1;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x41;
          param_5 = (uint)uVar5;
LAB_1400083e0:
          bVar14 = 2;
LAB_1400083f0:
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar14,1,uVar19,
                            &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_5);
        }
LAB_14000840b:
        uVar18 = 0xc0000010;
      }
LAB_140008414:
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar18);
    }
    else if (param_5 == 0x49101b) {
      *(uint *)(plVar10 + 0x33) = *(uint *)(plVar10 + 0x33) | 2;
      cVar16 = '\x01';
LAB_140007df1:
      UsbDevice_ResetFromHub((longlong)plVar10,param_2,cVar16);
    }
    else if (param_5 == 0x49102b) {
      cVar16 = '\x01';
LAB_140007f21:
      UsbDevice_DisableFromHub((longlong)plVar10,param_2,cVar16);
    }
    else {
      if (param_5 == 0x49102f) {
        cVar16 = '\0';
        goto LAB_140007c29;
      }
      if (param_5 == 0x491037) {
        cVar16 = '\x01';
        goto LAB_140007e8b;
      }
      if (param_5 == 0x49103f) {
        *(uint *)(plVar10 + 0x33) = *(uint *)(plVar10 + 0x33) | 4;
        goto LAB_140008308;
      }
      if (param_5 != 0x491053) {
        if (param_5 != 0x491057) {
          uVar18 = 0xc000000e;
          goto LAB_140008414;
        }
        goto LAB_140007d6b;
      }
LAB_140007ed0:
      UsbDevice_TreePurgeFromHub((longlong)plVar10,param_2);
    }
  }
  iVar6 = *(int *)(lVar7 + 1000);
  LOCK();
  piVar1 = (int *)(lVar7 + 0x3ec);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 != 1) {
    return;
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc();
  if ((*(char *)(lVar7 + 0x3f1) != '\0') || (iVar6 != *(int *)(lVar7 + 1000))) {
    KeReleaseSpinLock(lVar7 + 0x3e0,uVar9);
    return;
  }
  *(undefined1 *)(lVar7 + 0x3f1) = 1;
  KeReleaseSpinLock(lVar7 + 0x3e0,uVar9);
  puVar13 = (undefined8 *)(lVar7 + 0x1f8);
  uVar15 = 0xebe40031;
LAB_140008233:
  StateMachineEngine_EventAdd(puVar13,uVar15);
  return;
}



===== _UcxEndpointPurgeComplete @ 140008550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxEndpointPurgeComplete(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe300f1);
  return;
}



===== _UcxEndpointAbortComplete @ 1400085a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxEndpointAbortComplete(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe30011);
  return;
}



===== UsbDevice_PurgeFromHub @ 1400085e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PurgeFromHub(longlong *param_1,longlong param_2,char param_3)

{
  if ((param_3 != '\0') && ((code *)param_1[0x1b] != (code *)0x0)) {
    (*(code *)param_1[0x1b])(*(undefined8 *)(param_1[3] + 0x28),param_1[2]);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x32,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_2);
  }
  param_1[0x32] = param_2;
  param_1[0x30] = (longlong)UsbDevice_CompleteUsbDevicePurgeToHub;
  UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet(param_1,0xebe30100);
  return;
}



===== UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet @ 1400086b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet(longlong *param_1,uint param_2)

{
  longlong ****pppplVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  int iVar11;
  longlong *plVar12;
  bool bVar13;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  char *local_48;
  longlong local_40;
  int local_38 [4];
  longlong ****local_28 [2];
  
  local_28[1] = (longlong ****)local_28;
  local_28[0] = (longlong ****)local_28;
  plVar12 = (longlong *)0x0;
  uVar8 = KeAcquireSpinLockRaiseToDpc(param_1[3] + 0x1e8);
  puVar10 = auStack_68;
  plVar9 = (longlong *)param_1[10];
  while( true ) {
    iVar11 = (int)plVar12;
    puVar7 = auStack_68;
    if (param_1 + 10 == plVar9) goto LAB_140008740;
    plVar12 = (longlong *)(ulonglong)(iVar11 + 1);
    pppplVar1 = (longlong ****)(plVar9 + 8);
    if ((longlong *****)*local_28[1] != local_28) break;
    plVar9[9] = (longlong)local_28[1];
    *pppplVar1 = (longlong ***)local_28;
    *local_28[1] = (longlong ***)pppplVar1;
    local_48 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c";
    local_28[1] = pppplVar1;
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,plVar9[-0x17],
               UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet,0x618);
    plVar9 = (longlong *)*plVar9;
  }
  while( true ) {
    iVar11 = (int)plVar12;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar7 = puVar10 + 8;
LAB_140008740:
    puVar10 = puVar7;
    lVar2 = param_1[3];
    *(undefined8 *)(puVar10 + -8) = 0x140008755;
    KeReleaseSpinLock(lVar2 + 0x1e8,uVar8);
    *(int *)(param_1 + 0x31) = iVar11;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      lVar2 = param_1[2];
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(int *)(puVar10 + 0x30) = iVar11;
      *(longlong *)(puVar10 + 0x28) = lVar2;
      *(undefined **)(puVar10 + 0x20) = &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids;
      *(undefined8 *)(puVar10 + -8) = 0x140008881;
      WPP_RECORDER_SF_qd(uVar5,5,5,0x18,*(undefined8 *)(puVar10 + 0x20),puVar10[0x28],puVar10[0x30])
      ;
    }
    plVar9 = *(longlong **)(puVar10 + 0x40);
    if ((longlong *)(puVar10 + 0x40) == plVar9) break;
    uVar8 = 0x90;
    plVar12 = plVar9 + -0x20;
    plVar3 = (longlong *)*plVar9;
    while( true ) {
      param_1 = plVar3 + -0x20;
      lVar2 = *plVar9;
      if ((*(longlong **)(lVar2 + 8) != plVar9) ||
         (plVar4 = (longlong *)plVar9[1], (longlong *)*plVar4 != plVar9)) break;
      *plVar4 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      plVar9[1] = 0;
      *plVar9 = 0;
      *(undefined8 *)(puVar10 + -8) = 0x1400087d6;
      StateMachineEngine_EventAdd(plVar12 + 0x24,param_2);
      lVar2 = plVar12[1];
      *(char **)(puVar10 + 0x20) = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c";
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x670);
      *(undefined8 *)(puVar10 + -8) = 0x140008806;
      (*pcVar6)(WdfDriverGlobals,lVar2,UsbDevice_CallAddEventForAllEndpointsWithPendingOperationSet,
                0x632);
      bVar13 = (longlong *)(puVar10 + 0x40) == plVar3;
      plVar9 = plVar3;
      plVar12 = param_1;
      plVar3 = (longlong *)*plVar3;
      if (bVar13) {
        return;
      }
    }
  }
  return;
}



===== StateMachineEngine_EventAdd @ 1400088f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 StateMachineEngine_EventAdd(undefined8 *param_1,uint param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined4 uVar14;
  
  cVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 3);
  *(uint *)((longlong)param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0x181) * 4 + 0x140) =
       param_2;
  *(byte *)((longlong)param_1 + 0x181) = *(char *)((longlong)param_1 + 0x181) + 1U & 0xf;
  (*(code *)param_1[0x32])(0,*param_1,param_1,param_2);
  bVar1 = *(byte *)((longlong)param_1 + 0x185);
  puVar12 = (undefined4 *)param_1[4];
  if ((((bVar1 & 1) != 0) && (param_2 == 0xebe30020)) && ((puVar12[4] & 1) == 0)) {
    uVar10 = KeReleaseSpinLock(param_1 + 3,cVar6);
    return uVar10 & 0xffffffffffffff00;
  }
  if ((bVar1 & 2) == 0) {
LAB_140008982:
    if (param_2 == 0xebe3004f) {
      if ((*(char *)((longlong)param_1 + 0x183) != '\0') &&
         (*(char *)((longlong)param_1 + 0x182) != '\0')) goto LAB_1400089d9;
      *(int *)(param_1 + 0x31) = *(int *)(param_1 + 0x31) + 1;
      Ucx_DbgBreak(
                  "On recieving UcxEndpointEventControllerResetComplete State machine should be in a Paused State"
                  );
      goto LAB_140008d32;
    }
    if (param_2 == 0xebe0000f) {
      if ((*(char *)((longlong)param_1 + 0x184) == '\0') ||
         (*(char *)((longlong)param_1 + 0x182) == '\0')) {
        *(int *)(param_1 + 0x31) = *(int *)(param_1 + 0x31) + 1;
        Ucx_DbgBreak(
                    "On recieving UcxEndpointEventControllerResetComplete, State machine should be in a Paused For Passive State"
                    );
        uVar11 = KeReleaseSpinLock(param_1 + 3,cVar6);
        return CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
      }
      goto LAB_1400089d9;
    }
    if ((param_2 & 0xf) == 0) {
      *(uint *)((longlong)param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0xb1) * 4 + 0x70) =
           param_2;
      *(byte *)((longlong)param_1 + 0xb1) = *(char *)((longlong)param_1 + 0xb1) + 1U & 0xf;
    }
    else if ((param_2 & 0xf) == 1) goto LAB_140008c72;
  }
  else {
    if (param_2 == 0xebe40011) {
      if ((bVar1 & 4) != 0) {
LAB_140008e75:
        uVar10 = KeReleaseSpinLock(param_1 + 3,cVar6);
        return uVar10 & 0xffffffffffffff00;
      }
      *(byte *)((longlong)param_1 + 0x185) = bVar1 | 4;
    }
    else {
      if (param_2 != 0xebe40051) goto LAB_140008982;
      if ((bVar1 & 8) != 0) goto LAB_140008e75;
      *(byte *)((longlong)param_1 + 0x185) = bVar1 | 8;
    }
LAB_140008c72:
    *(uint *)((longlong)param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0x6d) * 4 + 0x2c) =
         param_2;
    *(byte *)((longlong)param_1 + 0x6d) = *(char *)((longlong)param_1 + 0x6d) + 1U & 0xf;
  }
  if (*(char *)((longlong)param_1 + 0x182) != '\x01') {
    *(undefined1 *)((longlong)param_1 + 0x182) = 1;
LAB_1400089d9:
    iVar7 = -0x141cffb1;
    pcVar13 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\statemachineengine.c";
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*param_1,StateMachineEngine_EventAdd,0x1e9,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\statemachineengine.c");
    if (param_2 != 0xebe3004f) {
      if (param_2 == 0xebe0000f) {
        pcVar13 = (char *)CONCAT44((int)((ulonglong)pcVar13 >> 0x20),*puVar12);
        *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(param_1 + 0x30) * 8 + 0xc4) =
             *puVar12;
        *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0x30) + 0x18) = 0xebe0000f;
        *(byte *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + 1U & 0xf;
        (*(code *)param_1[0x33])(0,*param_1,param_1,0xebe0000f,pcVar13);
        *(undefined1 *)((longlong)param_1 + 0x184) = 0;
        KeReleaseSpinLock(param_1 + 3,cVar6);
        iVar7 = (**(code **)(puVar12 + 2))(param_1[1]);
        goto LAB_140008b61;
      }
      iVar7 = 0;
    }
LAB_140008b75:
    do {
      if (iVar7 == 0) {
        bVar1 = *(byte *)((longlong)param_1 + 0x6c);
        if (*(byte *)((longlong)param_1 + 0x6d) == bVar1) {
          if ((puVar12[4] & 2) != 0) {
            bVar1 = *(byte *)(param_1 + 0x16);
            if (*(byte *)((longlong)param_1 + 0xb1) != bVar1) {
              iVar7 = *(int *)((longlong)param_1 + (ulonglong)bVar1 * 4 + 0x70);
              *(byte *)(param_1 + 0x16) = bVar1 + 1 & 0xf;
              goto LAB_140008bb0;
            }
          }
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)((longlong)param_1 + (ulonglong)bVar1 * 4 + 0x2c);
          *(byte *)((longlong)param_1 + 0x6c) = bVar1 + 1 & 0xf;
        }
      }
LAB_140008bb0:
      bVar1 = *(byte *)((longlong)param_1 + 0x185);
      if ((bVar1 & 2) == 0) {
LAB_140008bbf:
        if (iVar7 != 0) goto LAB_140008bc3;
        *(undefined1 *)((longlong)param_1 + 0x182) = 0;
        goto LAB_140008bf4;
      }
      if (iVar7 == -0x141bffef) {
        *(byte *)((longlong)param_1 + 0x185) = bVar1 & 0xfb;
      }
      else {
        if (iVar7 != -0x141bffaf) goto LAB_140008bbf;
        *(byte *)((longlong)param_1 + 0x185) = bVar1 & 0xf7;
      }
LAB_140008bc3:
      pcVar9 = (code *)0x0;
      uVar8 = 0;
      while( true ) {
        iVar3 = *(int *)(*(longlong *)(puVar12 + 6) + (ulonglong)uVar8 * 0x10);
        if (iVar3 == 0) break;
        if (iVar3 == iVar7) {
          pcVar9 = *(code **)(*(longlong *)(puVar12 + 6) + 8 + (ulonglong)uVar8 * 0x10);
          pcVar13 = (char *)CONCAT44((int)((ulonglong)pcVar13 >> 0x20),*puVar12);
          *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(param_1 + 0x30) * 8 + 0xc4) =
               *puVar12;
          *(int *)(param_1 + (ulonglong)*(byte *)(param_1 + 0x30) + 0x18) = iVar7;
          *(byte *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + 1U & 0xf;
          (*(code *)param_1[0x33])(0,*param_1,param_1,iVar7,pcVar13);
          break;
        }
        uVar8 = uVar8 + 1;
      }
      uVar14 = (undefined4)((ulonglong)pcVar13 >> 0x20);
      if (pcVar9 != (code *)0x0) {
        KeReleaseSpinLock(param_1 + 3,cVar6);
        goto LAB_140008b4b;
      }
      piVar4 = *(int **)(puVar12 + 8);
      uVar10 = 0;
      iVar3 = *piVar4;
      while ((iVar3 != 0 && (iVar3 != iVar7))) {
        uVar10 = (ulonglong)((int)uVar10 + 1);
        iVar3 = piVar4[uVar10 * 2];
      }
      if (piVar4[uVar10 * 2] == 0) {
        Ucx_DbgBreak("Unexpected Event");
        pcVar13 = (char *)CONCAT44(uVar14,0x57a73036);
        *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(param_1 + 0x30) * 8 + 0xc4) =
             0x57a73036;
        *(int *)(param_1 + (ulonglong)*(byte *)(param_1 + 0x30) + 0x18) = iVar7;
        *(byte *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + 1U & 0xf;
        (*(code *)param_1[0x33])(0,*param_1,param_1,iVar7,pcVar13);
LAB_140008e4f:
        iVar7 = 0;
        *(int *)(param_1 + 0x31) = *(int *)(param_1 + 0x31) + 1;
        goto LAB_140008b75;
      }
      puVar5 = *(undefined4 **)(param_1[2] + (ulonglong)(uint)piVar4[uVar10 * 2 + 1] * 8);
      uVar2 = *puVar5;
      *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(param_1 + 0x30) * 8 + 0xc4) = uVar2;
      pcVar13 = (char *)CONCAT44(uVar14,uVar2);
      *(int *)(param_1 + (ulonglong)*(byte *)(param_1 + 0x30) + 0x18) = iVar7;
      *(byte *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + 1U & 0xf;
      (*(code *)param_1[0x33])(0,*param_1,param_1,iVar7,pcVar13);
      iVar7 = 0;
      if (puVar5 == (undefined4 *)0x0) goto LAB_140008e4f;
      param_1[4] = puVar5;
      puVar12 = puVar5;
      if (*(longlong *)(puVar5 + 2) != 0) {
        if ((((puVar5[4] & 8) != 0) || (*(char *)(param_1 + 0x34) != '\0')) && (cVar6 != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x184) = 1;
          *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(param_1 + 0x30) * 8 + 0xc4) =
               0x57a70000;
          *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0x30) + 0x18) = 0xebe00010;
          *(byte *)(param_1 + 0x30) = *(char *)(param_1 + 0x30) + 1U & 0xf;
          (*(code *)param_1[0x33])(0,*param_1,param_1,0xebe00010,0x57a70000);
          Controller_ForwardProgressWorkItemEnqueue
                    (param_1[0x17],StateMachineEngine_OnPassive,param_1,0);
LAB_140008bf4:
          KeReleaseSpinLock(param_1 + 3,cVar6);
LAB_140008c08:
          (**(code **)(WdfFunctions_01015 + 0x670))
                    (WdfDriverGlobals,*param_1,StateMachineEngine_EventAdd,0x290,
                     "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\statemachineengine.c");
          return 1;
        }
        KeReleaseSpinLock(param_1 + 3,cVar6);
        pcVar9 = *(code **)(puVar5 + 2);
LAB_140008b4b:
        iVar7 = (*pcVar9)(param_1[1]);
        if (iVar7 == -0x141fffe0) goto LAB_140008c08;
LAB_140008b61:
        cVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 3);
      }
    } while( true );
  }
LAB_140008d32:
  KeReleaseSpinLock(param_1 + 3,cVar6);
  return 1;
}



===== SleepstudyHelper_ComponentActive @ 140008f6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentActive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14002f2c0 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14002f2c0)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14002f2c0 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14002f2c0)(param_1);
  }
  return iVar1;
}



===== UsbDevice_WalkTree @ 140008ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_WalkTree(longlong param_1,char param_2,undefined *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  if ((param_2 != '\0') || (*(char *)(param_1 + 0x19c) == '\0')) {
    (*(code *)param_3)(param_1,param_4);
    for (puVar1 = *(undefined8 **)(param_1 + 0x30); (undefined8 *)(param_1 + 0x30) != puVar1;
        puVar1 = (undefined8 *)*puVar1) {
      UsbDevice_WalkTree((longlong)(puVar1 + -8),param_2,param_3,param_4);
    }
  }
  return;
}



===== UsbDevice_DefaultEndpointEnableCompleteFromHcd @ 14000907c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_DefaultEndpointEnableCompleteFromHcd(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(int *)(param_1 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2c,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_1,
                         (char)*(int *)(param_1 + 0x30));
    }
    IofCompleteRequest(param_1,0);
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x10),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2d,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_1);
    }
    *(undefined4 *)(lVar1 + 0x188) = 1;
    *(code **)(lVar1 + 0x180) = UsbDevice_CompleteEnable;
    *(longlong *)(lVar1 + 400) = param_1;
    *(undefined1 *)(lVar1 + 0x19d) = 1;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x18),
                       PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
    StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe30080);
  }
  return;
}



===== UsbDevice_EndpointsConfigureCompleteFromHcd @ 1400091d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_EndpointsConfigureCompleteFromHcd(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  uint *puVar14;
  undefined1 uVar15;
  
  uVar15 = (undefined1)param_1;
  if (*(int *)(param_1 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x29,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar15,
                         (char)*(int *)(param_1 + 0x30));
    }
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x10),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if (*(int *)(param_2 + 0x28) != 0) {
      lVar4 = *(longlong *)(param_2 + 0x30);
      uVar10 = 0;
      do {
        lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(undefined8 *)(lVar4 + (ulonglong)uVar10 * 8),
                           PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
        lVar9 = lVar8 + 0x300;
        uVar6 = KeAcquireSpinLockRaiseToDpc(lVar9);
        *(undefined1 *)(lVar8 + 0x308) = uVar6;
        *(undefined1 *)(lVar8 + 0x309) = 0;
        if (*(longlong *)(lVar8 + 0x318) != 0) {
          LOCK();
          plVar1 = (longlong *)(*(longlong *)(lVar8 + 0x318) + 0x68);
          lVar3 = *plVar1;
          *plVar1 = 0;
          UNLOCK();
          if (lVar3 != 0) {
            lVar3 = *(longlong *)(lVar8 + 0x318);
            lVar5 = *(longlong *)(lVar8 + 800);
            *(undefined8 *)(lVar8 + 0x318) = 0;
            *(undefined8 *)(lVar8 + 800) = 0;
            *(undefined8 *)(lVar3 + 0x78) = 0;
            KeReleaseSpinLock(lVar9,*(undefined1 *)(lVar8 + 0x308));
            if (lVar5 + 0x50 == *(longlong *)(*(longlong *)(lVar3 + 0xb8) + 0x30)) {
              *(undefined4 *)(lVar5 + 0xc) = 0xabcd0000;
            }
            *(undefined4 *)(lVar5 + 0x54) = 0;
            *(undefined4 *)(lVar3 + 0x30) = 0;
            *(undefined8 *)(lVar3 + 0x38) = 0;
            IofCompleteRequest(lVar3,0);
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar9);
            *(undefined1 *)(lVar8 + 0x308) = uVar6;
          }
        }
        KeReleaseSpinLock(lVar9);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(param_2 + 0x28));
    }
    puVar2 = (uint *)(param_2 + 0x18);
    uVar10 = *puVar2;
    if (uVar10 != 0) {
      lVar4 = *(longlong *)(param_2 + 0x20);
      uVar13 = 0;
      puVar14 = *(uint **)(param_2 + 0x58);
      if (*(int *)(param_2 + 0x54) != 0) {
        do {
          uVar12 = 0;
          if (uVar10 != 0) {
            do {
              lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,*(undefined8 *)(lVar4 + uVar12 * 8),
                                 PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
              if ((ushort)*(byte *)(lVar9 + 0x2f6) == (ushort)puVar14[1]) {
                *(undefined1 *)(lVar9 + 0x309) = 1;
              }
              uVar10 = *puVar2;
              uVar11 = (int)uVar12 + 1;
              uVar12 = (ulonglong)uVar11;
            } while (uVar11 < uVar10);
          }
          uVar13 = uVar13 + 1;
          puVar14 = (uint *)((longlong)puVar14 + (ulonglong)*puVar14);
        } while (uVar13 < *(uint *)(param_2 + 0x54));
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2b,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar15);
      }
      *(longlong *)(lVar7 + 400) = param_1;
      *(code **)(lVar7 + 0x180) = UsbDevice_CompleteEndpointsConfigure;
      *(uint *)(lVar7 + 0x188) = *puVar2;
      UsbDevice_AddEventForEndpoints
                (*(undefined8 **)(param_2 + 0x20),*(uint *)(param_2 + 0x18),0xebe30080);
      return;
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2a,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar15);
    }
  }
  IofCompleteRequest(param_1,0);
  return;
}



===== UsbDevice_DisableFromHub @ 14000952c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_DisableFromHub(longlong param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  Controller_PurgeTransportChangeNotifications(*(undefined8 ***)(param_1 + 0x10));
  local_28 = 0;
  lStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lStack_40 + 0x18),
                     PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  pcVar2 = UsbDevice_PendDisableRequestDueToControllerReset;
  if (param_3 == '\0') {
    pcVar2 = UsbDevice_ForwardDisableToHcd;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x30,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_2);
  }
  *(undefined1 *)(param_1 + 0x19d) = 0;
  *(undefined8 *)(param_1 + 400) = param_2;
  *(code **)(param_1 + 0x180) = pcVar2;
  *(undefined4 *)(param_1 + 0x188) = 1;
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x120),0xebe300d0);
  return;
}



===== Controller_PurgeTransportChangeNotifications @ 140009680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_PurgeTransportChangeNotifications(undefined8 **param_1)

{
  undefined8 **ppuVar1;
  bool bVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  uint *puVar6;
  undefined8 ***pppuVar7;
  uint uVar8;
  undefined8 ***pppuVar9;
  int iVar10;
  bool bVar11;
  undefined1 auStackY_b8 [32];
  undefined8 ***local_78;
  undefined8 ***pppuStack_70;
  undefined8 local_68;
  undefined8 **local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_60 = (undefined8 **)0x0;
  local_68 = 0;
  local_78 = (undefined8 ***)0x0;
  pppuStack_70 = (undefined8 ***)0x0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  bVar2 = false;
  uVar8 = 0;
  iVar10 = 0;
  lVar3 = *(longlong *)(lVar3 + 0x18);
  lVar5 = *(longlong *)(lVar3 + 0x4d8);
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e0);
  do {
    (*pcVar4)(WdfDriverGlobals,lVar5);
    while( true ) {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x4d0),iVar10);
      iVar10 = iVar10 + 1;
      if (lVar5 == 0) {
        local_78 = &local_78;
        pppuStack_70 = &local_78;
        goto LAB_1400097c1;
      }
      puVar6 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar5,0);
      if (*(undefined8 ***)(puVar6 + 10) == param_1) break;
      uVar8 = uVar8 | *puVar6;
    }
    bVar2 = true;
    (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x4d0),lVar5);
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x680);
  } while( true );
LAB_1400097c1:
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar10 = (**(code **)(WdfFunctions_01015 + 0x500))
                     (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x4e0),local_68,0);
  if (iVar10 < 0) {
LAB_14000989b:
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x4d8));
    if (&local_78 != (undefined8 ****)local_78) {
      pppuVar7 = local_78;
      pppuVar9 = (undefined8 ***)*local_78;
      do {
        if (((undefined8 ***)pppuVar9[1] != pppuVar7) ||
           (ppuVar1 = pppuVar7[1], (undefined8 ***)*ppuVar1 != pppuVar7)) {
LAB_1400099be:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        *ppuVar1 = pppuVar9;
        pppuVar9[1] = ppuVar1;
        local_60 = pppuVar7[2];
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_60,0xc0000120);
        bVar11 = &local_78 != (undefined8 ****)pppuVar9;
        pppuVar7 = pppuVar9;
        pppuVar9 = (undefined8 ***)*pppuVar9;
      } while (bVar11);
    }
    if ((bVar2) && (uVar8 != *(uint *)(lVar3 + 0x4cc))) {
      *(uint *)(lVar3 + 0x4cc) = uVar8;
      (**(code **)(lVar3 + 0x108))(*(undefined8 *)(lVar3 + 0x28),uVar8);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x6a,
                          &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar8);
      }
    }
    return;
  }
  pppuVar7 = (undefined8 ***)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_68,
                        PTR__WDF_TRANSPORT_NOTIFY_CHANGE_REQUEST_CONTEXT_TYPE_INFO_14002da60);
  if (pppuVar7[3] == param_1) {
    iVar10 = (**(code **)(WdfFunctions_01015 + 0x508))
                       (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x4e0),local_68);
    if (iVar10 < 0) goto LAB_14000989b;
    if ((undefined8 ****)*pppuStack_70 != &local_78) goto LAB_1400099be;
    pppuVar7[1] = pppuStack_70;
    *pppuVar7 = &local_78;
    *pppuStack_70 = pppuVar7;
    pppuStack_70 = pppuVar7;
  }
  goto LAB_1400097c1;
}



===== WPP_RECORDER_SF_Lqqq @ 1400099cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lqqq
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,8
               ,&param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,&param_7,8,&param_8,8,&param_9,8,0);
  return;
}



===== Xrb_Allocate @ 140009af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140009d66) */

int Xrb_Allocate(longlong param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong local_res18;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  
  uVar2 = ExDefaultNonPagedPoolType;
  *param_2 = 0;
  local_res18 = 0;
  uStack_54 = 0;
  local_48 = *(undefined8 *)(param_1 + 0x28);
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  local_68 = 0x38;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_50 = 0x100000001;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_68,uVar2,*(undefined4 *)(param_1 + 0x10));
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,10,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_1,(char)iVar4)
      ;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x98);
    memset((void *)0x0,0,0xe8);
    uRam000000000000004c = 0x2e425258;
    uRam0000000000000000 = 0xe8;
    uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
    uRam000000000000000c = 0xabcd0000;
    uRam0000000000000008 = 0xaabb0000;
    uRam0000000000000020 = 0;
    lRam0000000000000018 = param_1;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30),
                       PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
    lVar5 = *(longlong *)(lVar5 + 8);
    local_48 = *(undefined8 *)(param_1 + 0x30);
    local_68 = (undefined4)*(undefined8 *)(lVar5 + 0x78);
    uStack_64 = (undefined4)((ulonglong)*(undefined8 *)(lVar5 + 0x78) >> 0x20);
    uStack_60 = (undefined4)*(undefined8 *)(lVar5 + 0x80);
    uStack_5c = (undefined4)((ulonglong)*(undefined8 *)(lVar5 + 0x80) >> 0x20);
    uStack_58 = (undefined4)*(undefined8 *)(lVar5 + 0x88);
    uStack_54 = (undefined4)((ulonglong)*(undefined8 *)(lVar5 + 0x88) >> 0x20);
    uStack_40 = *(undefined8 *)(lVar5 + 0xa0);
    uStack_38 = *(undefined8 *)(lVar5 + 0xa8);
    uStack_50 = 0x100000001;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_68,0,&local_res18);
    if (-1 < iVar4) {
      lRam0000000000000028 = local_res18;
      if (*(char *)(param_1 + 0x8b) != '\0') {
        uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
        puVar7 = auStackY_a8;
        plVar6 = *(longlong **)(param_1 + 0x80);
        if (*plVar6 != param_1 + 0x78) {
          plVar6 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          uVar3 = (*pcVar1)();
          puVar7 = auStackY_a0;
        }
        lRam0000000000000030 = param_1 + 0x78;
        plRam0000000000000038 = plVar6;
        *plVar6 = 0x30;
        *(undefined8 *)(param_1 + 0x80) = 0x30;
        *(undefined8 *)(puVar7 + -8) = 0x140009e58;
        KeReleaseSpinLock(param_1 + 0x70,uVar3);
      }
      *param_2 = 0x50;
      return iVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xb,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_1,(char)iVar4)
      ;
    }
  }
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar4;
}



===== RootHub_EvtControlTxHandler @ 140009e70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RootHub_EvtControlTxHandler(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined1 uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 auStackY_98 [32];
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar6 = false;
  uVar10 = 0xc00000bb;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_ROOTHUB_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14002d910);
  uVar5 = *(undefined8 *)(lVar8 + 8);
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  lVar8 = *(longlong *)(lVar9 + 0xb0);
  LOCK();
  *(int *)(lVar8 + 0x3ec) = *(int *)(lVar8 + 0x3ec) + 1;
  UNLOCK();
  if (*(char *)(lVar8 + 0x3f0) != '\0') {
    iVar4 = *(int *)(lVar8 + 1000);
    LOCK();
    piVar1 = (int *)(lVar8 + 0x3ec);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar8 + 0x3e0);
      if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar4 == *(int *)(lVar8 + 1000))) {
        *(undefined1 *)(lVar8 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar8 + 0x3e0,uVar7);
        StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar8 + 0x3e0,uVar7);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x30,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0xbb);
    }
    uVar10 = 0xc000000e;
    goto LAB_14000a51e;
  }
  local_48 = 0;
  lStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  bVar3 = *(byte *)(lStack_60 + 0x80);
  uVar7 = (undefined1)lStack_60;
  if ((bVar3 & 3) == 0) {
    if ((bVar3 & 0x60) == 0x20) {
      if ((char)bVar3 < '\0') {
LAB_14000a241:
        if (*(char *)(lStack_60 + 0x81) == '\0') {
          if (*(longlong *)(lVar9 + 0x28) != 0) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x33,
                                &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
            }
            (**(code **)(lVar9 + 0x28))(uVar5,param_2);
            bVar6 = true;
          }
          goto LAB_140009fd1;
        }
        if ((char)bVar3 < '\0') goto LAB_14000a01e;
      }
      else {
        if (*(char *)(lStack_60 + 0x81) == '\x01') {
          if (*(longlong *)(lVar9 + 0x18) != 0) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x31,
                                &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
            }
            (**(code **)(lVar9 + 0x18))(uVar5,param_2);
            bVar6 = true;
          }
          goto LAB_140009fd1;
        }
        if ((char)bVar3 < '\0') goto LAB_14000a241;
      }
      if (*(char *)(lStack_60 + 0x81) != '\x03') goto LAB_14000a01e;
      if (*(longlong *)(lVar9 + 0x38) != 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x35,
                            &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
        }
        (**(code **)(lVar9 + 0x38))(uVar5,param_2);
        bVar6 = true;
      }
    }
    else {
      if ((((bVar3 & 0x60) != 0) || (-1 < (char)bVar3)) || (*(char *)(lStack_60 + 0x81) != '\r'))
      goto LAB_14000a01e;
      if (*(longlong *)(lVar9 + 0x48) != 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x37,
                            &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
        }
        (**(code **)(lVar9 + 0x48))(uVar5,param_2);
        bVar6 = true;
      }
    }
  }
  else {
    if (((bVar3 & 3) == 3) && ((bVar3 & 0x60) == 0x20)) {
      if ((char)bVar3 < '\0') {
LAB_140009f7e:
        if (*(char *)(lStack_60 + 0x81) == '\0') {
          if (*(longlong *)(lVar9 + 0x30) != 0) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x34,
                                &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
            }
            (**(code **)(lVar9 + 0x30))(uVar5,param_2);
            bVar6 = true;
          }
          goto LAB_140009fd1;
        }
        if ((char)bVar3 < '\0') goto LAB_14000a01e;
      }
      else {
        if (*(char *)(lStack_60 + 0x81) == '\x01') {
          if (*(longlong *)(lVar9 + 0x20) != 0) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x32,
                                &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
            }
            (**(code **)(lVar9 + 0x20))(uVar5,param_2);
            bVar6 = true;
          }
          goto LAB_140009fd1;
        }
        if ((char)bVar3 < '\0') goto LAB_140009f7e;
      }
      if (*(char *)(lStack_60 + 0x81) == '\x03') {
        if (*(longlong *)(lVar9 + 0x40) != 0) {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x36,
                              &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
          }
          (**(code **)(lVar9 + 0x40))(uVar5,param_2);
          bVar6 = true;
        }
        goto LAB_140009fd1;
      }
    }
LAB_14000a01e:
    if (*(longlong *)(lVar9 + 0x50) != 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x38,
                          &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar7);
      }
      (**(code **)(lVar9 + 0x50))(uVar5,param_2);
      bVar6 = true;
    }
  }
LAB_140009fd1:
  iVar4 = *(int *)(lVar8 + 1000);
  LOCK();
  piVar1 = (int *)(lVar8 + 0x3ec);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar8 + 0x3e0);
    if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar4 == *(int *)(lVar8 + 1000))) {
      *(undefined1 *)(lVar8 + 0x3f1) = 1;
      KeReleaseSpinLock(lVar8 + 0x3e0,uVar7);
      StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
    }
    else {
      KeReleaseSpinLock(lVar8 + 0x3e0,uVar7);
    }
  }
  if (bVar6) {
    return;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x39,
                      &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_2);
  }
LAB_14000a51e:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar10);
  return;
}



===== Xrb_Free @ 14000a550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Xrb_Free(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + -0x38);
  if (*(int *)(param_1 + -4) != 0x2e425258) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x144,3,0,param_1,*(undefined8 *)(lVar2 + 8));
  }
  if (*(int *)(param_1 + -0x44) != -0x54330000) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x144,1,0,param_1,*(undefined8 *)(lVar2 + 8));
  }
  if (*(char *)(lVar2 + 0x8b) != '\0') {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x70);
    lVar3 = *(longlong *)(param_1 + -0x20);
    puVar1 = (undefined8 *)(param_1 + -0x20);
    if ((*(undefined8 **)(lVar3 + 8) != puVar1) ||
       (plVar4 = *(longlong **)(param_1 + -0x18), (undefined8 *)*plVar4 != puVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(undefined8 *)(param_1 + -0x18) = 0;
    *puVar1 = 0;
    KeReleaseSpinLock(lVar2 + 0x70,uVar6);
  }
  if (*(longlong *)(param_1 + -0x28) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(param_1 + -0x28) = 0;
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + -0x30));
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + -0x30),Xrb_Free,0x2be,
             "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\xrb.c");
  return;
}



===== USBPORTStyle_LegacyGetUnicodeName @ 14000a6c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
USBPORTStyle_LegacyGetUnicodeName
          (undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,int param_5,
          uint *param_6)

{
  undefined *puVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint *local_res20;
  
  lVar3 = WdfFunctions_01015;
  puVar1 = PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848;
  uVar5 = 0;
  local_res20 = (uint *)0x0;
  *param_6 = 0;
  lVar3 = (**(code **)(lVar3 + 0x650))(WdfDriverGlobals,param_1,puVar1);
  uVar8 = 6;
  lVar3 = *(longlong *)(lVar3 + 8);
  if (5 < param_3) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,param_3,&local_res20,0);
    if (-1 < iVar2) {
      iVar2 = 0x16;
      iVar6 = 5;
      while (puVar7 = (undefined4 *)0x0, 0 < iVar6) {
        iVar6 = iVar6 + -1;
        puVar7 = (undefined4 *)ExAllocatePool2(0x100,iVar2,0x44434855);
        if (puVar7 == (undefined4 *)0x0) {
          return 0xc000009a;
        }
        puVar7[2] = iVar2;
        if (param_5 == 0x220424) {
          *puVar7 = 2;
          USBPORTStyle_UserGetControllerKey(param_1,(longlong)puVar7,puVar7 + 4,iVar2 - 0x10U);
        }
        else {
          *puVar7 = 7;
          USBPORTStyle_UserGetRootHubName
                    (*(longlong *)(lVar3 + 0x158),(longlong)puVar7,puVar7 + 4,iVar2 - 0x10U);
        }
        if (puVar7[1] != 7) break;
        iVar2 = puVar7[3];
        ExFreePoolWithTag(puVar7,0x44434855);
      }
      if (puVar7[1] == 0) {
        uVar4 = puVar7[4] + 4;
        if (uVar4 < (uint)puVar7[4]) {
          uVar4 = 0xffffffff;
          iVar2 = -0x3fffff6b;
        }
        else {
          iVar2 = 0;
        }
        *local_res20 = uVar4;
        if ((param_3 < uVar4) || (iVar2 < 0)) {
          *(undefined2 *)(local_res20 + 1) = 0;
        }
        else {
          memmove(local_res20 + 1,puVar7 + 5,(ulonglong)(uint)puVar7[4]);
          uVar8 = *local_res20;
        }
        *param_6 = uVar8;
      }
      else {
        uVar5 = 0xc0000001;
      }
      ExFreePoolWithTag(puVar7,0x44434855);
      return uVar5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                        &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,(char)iVar2);
    }
  }
  return 0xc0000023;
}



===== USBPORTStyle_UserGetRootHubName @ 14000a914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBPORTStyle_UserGetRootHubName(longlong param_1,longlong param_2,int *param_3,uint param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong local_38;
  undefined8 local_30;
  void *pvStack_28;
  
  local_38 = 0;
  local_30 = 0;
  pvStack_28 = (void *)0x0;
  if (param_4 < 6) {
    *(undefined4 *)(param_2 + 4) = 7;
    return;
  }
  uVar7 = param_4 - 6;
  memset(param_3,0,(ulonglong)uVar7);
  uVar3 = USBPORTStyle_GetSymbolicName(param_1,&local_38);
  iVar4 = (int)uVar3;
  if ((local_38 == 0) && (-1 < iVar4)) {
    return;
  }
  if (iVar4 < 0) {
    uVar5 = 0;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_38,&local_30);
    uVar1 = (ushort)local_30;
    uVar5 = (uint)(ushort)local_30;
    uVar6 = (uint)(ushort)local_30;
    if (uVar7 < (ushort)local_30) {
      iVar4 = -0x3fffffdd;
      uVar6 = uVar7;
    }
    if (uVar6 != 0) {
      memmove(param_3 + 1,pvStack_28,(ulonglong)uVar6);
    }
    if (-1 < iVar4) {
      *(undefined4 *)(param_2 + 4) = 0;
      *param_3 = uVar1 + 2;
      goto LAB_14000a9de;
    }
  }
  uVar2 = 5;
  if (iVar4 == -0x3fffffdd) {
    uVar2 = 7;
  }
  *(undefined4 *)(param_2 + 4) = uVar2;
LAB_14000a9de:
  *(uint *)(param_2 + 0xc) = uVar5 + 0x16;
  if (local_38 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_38);
  }
  return;
}



===== USBPORTStyle_GetSymbolicName @ 14000aa60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 USBPORTStyle_GetSymbolicName(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  short sVar6;
  undefined8 local_res8;
  undefined8 local_88;
  short *psStack_80;
  undefined8 local_78;
  short *psStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  uVar4 = 0;
  local_res8 = 0;
  *param_2 = 0;
  local_38 = local_38 & 0xffffffff00000000;
  sVar6 = 0;
  local_78 = 0;
  psStack_70 = (short *)0x0;
  local_88 = 0;
  psStack_80 = (short *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
  lVar5 = 0;
  if ((*(char *)(param_1 + 0x178) != '\0') && (lVar1 = *(longlong *)(param_1 + 0x180), lVar1 != 0))
  {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,lVar1,USBPORTStyle_GetSymbolicName,0x3a3,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\userioctls.c");
    lVar5 = lVar1;
  }
  KeReleaseSpinLock(param_1 + 0x158,uVar2);
  if (lVar5 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,lVar5,&local_78);
    if ((psStack_70 == (short *)0x0) || ((ushort)local_78 >> 1 == 0)) {
      uVar4 = 0xc0000001;
    }
    else {
      psStack_80 = psStack_70;
      if (*psStack_70 == 0x5c) {
        psStack_80 = psStack_70 + 1;
        iVar3 = ((ushort)local_78 >> 1) - 1;
        if (iVar3 != 0) {
          do {
            if (*psStack_80 == 0x5c) goto LAB_14000ac4c;
            if (*psStack_80 == 0) break;
            psStack_80 = psStack_80 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          if (iVar3 != 0) {
LAB_14000ac4c:
            if (*psStack_80 == 0x5c) {
              psStack_80 = psStack_80 + 1;
            }
          }
        }
        sVar6 = (short)psStack_80 - (short)psStack_70;
      }
      local_38 = 0;
      local_58 = 0;
      uStack_50 = 0x100000001;
      local_48 = *(undefined8 *)(param_1 + 8);
      uStack_40 = 0;
      uStack_60 = 0;
      local_88 = CONCAT62(CONCAT42(local_88._4_4_,local_78._2_2_ - sVar6),(ushort)local_78 - sVar6);
      local_68 = 0x38;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x9a0))
                        (WdfDriverGlobals,&local_88,&local_68,&local_res8);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ddqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        uVar4 = 0xc000009a;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,lVar5,USBPORTStyle_GetSymbolicName,0x3f4,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\userioctls.c");
  }
  *param_2 = local_res8;
  return uVar4;
}



===== USBPORTStyle_UserGetControllerKey @ 14000ad00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBPORTStyle_UserGetControllerKey
               (undefined8 param_1,longlong param_2,int *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_res20 [2];
  
  if (param_4 < 6) {
    *(undefined4 *)(param_2 + 4) = 7;
  }
  else {
    memset(param_3,0,(ulonglong)(param_4 - 6));
    local_res20[0] = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x288))
                      (WdfDriverGlobals,param_1,7,param_4 - 6,param_3 + 1,local_res20);
    if (iVar1 < 0) {
      uVar2 = 5;
      if (iVar1 == -0x3fffffdd) {
        uVar2 = 7;
      }
      *(undefined4 *)(param_2 + 4) = uVar2;
    }
    else {
      *(undefined4 *)(param_2 + 4) = 0;
      *param_3 = local_res20[0] + 2;
    }
    *(int *)(param_2 + 0xc) = local_res20[0] + 0x16;
  }
  return;
}



===== RootHub_EvtInterruptTxHandler @ 14000add0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RootHub_EvtInterruptTxHandler(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStackY_a8 [32];
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar3 = true;
  bVar4 = false;
  iVar6 = 0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_ROOTHUB_INTERRUPT_QUEUE_CONTEXT_TYPE_INFO_14002d9b8);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x10),
                     PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  local_48 = 0;
  lStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x18);
  *(undefined1 *)(lVar7 + 0x40) = 0;
  if ((*(int *)(lStack_60 + 0x10) < 0) && (*(short *)(lVar7 + 0x20) == *(short *)(lVar7 + 0x22))) {
    bVar3 = false;
    iVar6 = (**(code **)(WdfFunctions_01015 + 0xc48))
                      (WdfDriverGlobals,param_2,RootHub_EvtInterruptTxCancel);
    if (iVar6 < 0) {
      bVar4 = true;
    }
    else {
      *(undefined8 *)(lVar7 + 0x48) = param_2;
    }
  }
  else {
    *(undefined2 *)(lVar7 + 0x22) = *(undefined2 *)(lVar7 + 0x20);
  }
  KeReleaseSpinLock(lVar7 + 0x18,uVar5);
  if (!bVar4) {
    if (!bVar3) {
      return;
    }
    lVar7 = *(longlong *)(lVar8 + 0xb0);
    LOCK();
    *(int *)(lVar7 + 0x3ec) = *(int *)(lVar7 + 0x3ec) + 1;
    UNLOCK();
    if (*(char *)(lVar7 + 0x3f0) == '\0') {
      (**(code **)(lVar8 + 0x58))(*(undefined8 *)(lVar8 + 8),param_2);
      lVar7 = *(longlong *)(lVar8 + 0xb0);
      iVar2 = *(int *)(lVar7 + 1000);
      LOCK();
      piVar1 = (int *)(lVar7 + 0x3ec);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 != 1) {
        return;
      }
      lVar8 = lVar7 + 0x3e0;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
      if ((*(char *)(lVar7 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar7 + 1000))) {
        *(undefined1 *)(lVar7 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar8,uVar5);
        StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
        return;
      }
      KeReleaseSpinLock(lVar8,uVar5);
      return;
    }
    iVar2 = *(int *)(lVar7 + 1000);
    LOCK();
    piVar1 = (int *)(lVar7 + 0x3ec);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      lVar8 = lVar7 + 0x3e0;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
      if ((*(char *)(lVar7 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar7 + 1000))) {
        *(undefined1 *)(lVar7 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar8,uVar5);
        StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar8,uVar5);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2e,
                       &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids);
    }
    iVar6 = -0x3ffffff2;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x2f,
                       &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_2,(char)iVar6);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar6);
  return;
}



===== Etw_UcxDeviceRundown @ 14000b130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxDeviceRundown(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  wchar_t *_Dst;
  longlong lVar4;
  longlong lVar5;
  ulonglong local_38;
  void *pvStack_30;
  
  if ((*(uint *)(param_2 + 4) & 2) == 0) {
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0pppqqQ6_EtwWriteTransfer
                (param_1,&UCX_ETW_EVENT_RUNDOWN_UCX_DEVICE_INFORMATION,param_1,
                 *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x28),
                 (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10),
                 (char)*(undefined4 *)(param_2 + 0x10c),(char)*(undefined4 *)(param_2 + 0x11c),
                 param_2 + 0x124);
    }
  }
  else {
    _Dst = (wchar_t *)0x0;
    local_38 = 0;
    pvStack_30 = (void *)0x0;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x10),
                       PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
    lVar4 = lVar3 + 0x158;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar4);
    lVar5 = 0;
    if ((*(char *)(lVar3 + 0x178) != '\0') && (lVar1 = *(longlong *)(lVar3 + 0x180), lVar1 != 0)) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,lVar1,Etw_UcxDeviceRundown,0x4e4,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
      lVar5 = lVar1;
    }
    KeReleaseSpinLock(lVar4,uVar2);
    if (lVar5 != 0) {
      RtlInitUnicodeString(&local_38,0);
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,lVar5,&local_38);
      _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_38 & 0xffff) + 2,0x44434855);
      if (_Dst != (wchar_t *)0x0) {
        memmove(_Dst,pvStack_30,local_38 & 0xffff);
        _Dst[local_38 >> 1 & 0x7fff] = L'\0';
      }
      lVar4 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar5,Etw_UcxDeviceRundown,0x4ff,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0ppz_EtwWriteTransfer
                (lVar4,&UCX_ETW_EVENT_RUNDOWN_UCX_ROOTHUB_INFORMATION,param_1,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0xb0) + 0x28),
                 (char)*(undefined8 *)(lVar3 + 8),_Dst);
    }
    if (_Dst != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Dst,0x44434855);
    }
  }
  return;
}



===== McTemplateK0pppqqQ6_EtwWriteTransfer @ 14000b388 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppqqQ6_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined8 param_9)

{
  undefined8 local_res20;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = &local_res20;
  local_70 = 8;
  local_68 = &param_5;
  local_60 = 8;
  local_58 = &param_6;
  local_48 = &param_7;
  local_38 = &param_8;
  local_28 = param_9;
  local_50 = 8;
  local_40 = 4;
  local_30 = 4;
  local_20 = 0x18;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,7,local_88);
  return;
}



===== _UcxRootHubPortChanged @ 14000b440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxRootHubPortChanged(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  RootHub_PortChanged(lVar1);
  return;
}



===== RootHub_PortChanged @ 14000b47c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_PortChanged(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2c,
                      &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_1);
  }
  lVar3 = *(longlong *)(param_1 + 200);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
  *(short *)(lVar3 + 0x20) = *(short *)(lVar3 + 0x20) + 1;
  lVar9 = 0;
  if ((*(longlong *)(lVar3 + 0x48) != 0) &&
     (iVar6 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals), -1 < iVar6)) {
    lVar9 = *(longlong *)(lVar3 + 0x48);
    *(undefined2 *)(lVar3 + 0x22) = *(undefined2 *)(lVar3 + 0x20);
    *(undefined8 *)(lVar3 + 0x48) = 0;
  }
  cVar5 = *(char *)(lVar3 + 0x41);
  if (cVar5 != '\0') {
    KeClearEvent(lVar3 + 0x28);
  }
  lVar8 = lVar3 + 0x18;
  KeReleaseSpinLock(lVar8,uVar4);
  if (cVar5 != '\0') {
    Etw_UcxRootHubInitiatingWake(lVar8,param_1);
    uVar4 = KfRaiseIrql(2);
    (**(code **)(WdfFunctions_01015 + 0x2b0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x160),0);
    KeLowerIrql(uVar4);
    KeSetEvent(lVar3 + 0x28,0,0);
  }
  if (lVar9 != 0) {
    lVar3 = *(longlong *)(param_1 + 0xb0);
    LOCK();
    *(int *)(lVar3 + 0x3ec) = *(int *)(lVar3 + 0x3ec) + 1;
    UNLOCK();
    if (*(char *)(lVar3 + 0x3f0) == '\0') {
      if ((*(int *)(*(longlong *)(param_1 + 0xb0) + 0x4c8) == 2) &&
         (cVar5 = KeGetCurrentIrql(), cVar5 != '\0')) {
        plVar7 = (longlong *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x198),
                            PTR__WDF_PORT_CHANGED_WORKITEM_CONTEXT_TYPE_INFO_14002d898);
        *plVar7 = lVar9;
        (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x198))
        ;
        return;
      }
      (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 8),lVar9);
      lVar3 = *(longlong *)(param_1 + 0xb0);
      iVar2 = *(int *)(lVar3 + 1000);
      LOCK();
      piVar1 = (int *)(lVar3 + 0x3ec);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        lVar9 = lVar3 + 0x3e0;
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar9);
        if ((*(char *)(lVar3 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar3 + 1000))) {
          *(undefined1 *)(lVar3 + 0x3f1) = 1;
          KeReleaseSpinLock(lVar9,uVar4);
          StateMachineEngine_EventAdd((undefined8 *)(lVar3 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock(lVar9,uVar4);
        }
      }
    }
    else {
      iVar2 = *(int *)(lVar3 + 1000);
      LOCK();
      piVar1 = (int *)(lVar3 + 0x3ec);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        lVar8 = lVar3 + 0x3e0;
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar8);
        if ((*(char *)(lVar3 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar3 + 1000))) {
          *(undefined1 *)(lVar3 + 0x3f1) = 1;
          KeReleaseSpinLock(lVar8,uVar4);
          StateMachineEngine_EventAdd((undefined8 *)(lVar3 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock(lVar8,uVar4);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2d,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar9,0xc000000e);
    }
  }
  return;
}



===== Etw_UcxRootHubInitiatingWake @ 14000b82c =====

void Etw_UcxRootHubInitiatingWake(undefined8 param_1,longlong param_2)

{
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    McTemplateK0ppz_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_ROOTHUB_INITIATING_WAKE,0,
               *(undefined8 *)(*(longlong *)(param_2 + 0xb0) + 0x28),
               (char)*(undefined8 *)(param_2 + 8),(wchar_t *)0x0);
  }
  return;
}



===== McTemplateK0ppz_EtwWriteTransfer @ 14000b870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppz_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  longlong lVar1;
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  if (param_6 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  local_28 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    local_28 = L"NULL";
  }
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(local_28,param_2,param_3,4,local_58);
  return;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_GetSetDescriptor @ 14000b920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_GetSetDescriptor
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte bVar8;
  uint uVar9;
  
  *(undefined2 *)(param_3 + 0x86) = *(undefined2 *)(param_3 + 0x24);
  *(undefined *)(param_3 + 0x81) = (&DAT_14002c10f)[(ulonglong)*(ushort *)(param_3 + 2) * 0x18];
  uVar6 = (ulonglong)*(ushort *)(param_3 + 2);
  bVar8 = ((&DAT_14002c10d)[uVar6 * 0x18] << 5 ^ *(byte *)(param_3 + 0x80)) & 0x60 ^
          *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (&DAT_14002c10c)[uVar6 * 0x18] << 7 | bVar8 & 0x7f;
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (bVar8 ^ (&DAT_14002c10e)[uVar6 * 0x18]) & 3 ^ bVar8;
  *(byte *)(param_3 + 0x80) = bVar8 & 0xe3;
  uVar9 = *(uint *)(param_3 + 0x20) | 3;
  if ((bVar8 & 0x80) == 0) {
    uVar9 = *(uint *)(param_3 + 0x20) & 0xfffffffe | 2;
  }
  *(uint *)(param_3 + 0x20) = uVar9;
  Etw_GetSetDescriptorUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 != 8) && (sVar2 != 9)) && (sVar2 != 10)) &&
     (((sVar2 != 0x32 && (sVar2 != 0x37)) && (sVar2 != 0x38)))) {
    if ((sVar2 == 0x39) || (sVar2 == 0x3a)) goto LAB_14000ba30;
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
  bVar8 = KeGetCurrentIrql();
  if ((bVar8 < 2) &&
     (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
      (*(int *)(param_3 + 0x24) != 0)))) {
    UCX_LockBufferPagesInUrbForDMA(param_3);
  }
LAB_14000ba30:
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar5 = IoSetCompletionRoutineEx(uVar7,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar5 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== Etw_GetSetDescriptorUrbDispatch @ 14000bb48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_GetSetDescriptorUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined7 in_register_00000009;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar4 = (uint)*(ushort *)(param_2 + 2);
  uVar5 = (ulonglong)(uVar4 - 0xb);
  if (uVar4 - 0xb != 0) {
    if (uVar4 == 0xc) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE;
      uVar5 = 0;
      goto LAB_14000bc6a;
    }
    if (uVar4 == 0x24) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_DESCRIPTOR_FROM_ENDPOINT;
      uVar5 = 0;
      goto LAB_14000bc6a;
    }
    if (uVar4 == 0x25) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_DESCRIPTOR_TO_ENDPOINT;
      uVar5 = 0;
      goto LAB_14000bc6a;
    }
    uVar4 = uVar4 - 0x28;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_DESCRIPTOR_FROM_INTERFACE;
      goto LAB_14000bc6a;
    }
    if (uVar4 == 1) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_DESCRIPTOR_TO_INTERFACE;
      goto LAB_14000bc6a;
    }
  }
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE;
LAB_14000bc6a:
  puVar7 = &local_38;
  if (iVar2 < 0) {
    puVar7 = (undefined8 *)0x0;
  }
  McTemplateK0pppppn_EtwWriteTransfer
            (uVar5,puVar6,puVar7,*(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
             (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
  return;
}



===== Controller_ForwardProgressWorkItemWdmCallback @ 14000bcd0 =====

void Controller_ForwardProgressWorkItemWdmCallback(undefined8 param_1,longlong param_2)

{
  Controller_ForwardProgressWorkItemCallback(param_1,param_2);
  return;
}



===== Controller_ForwardProgressWorkItemCallback @ 14000bce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_ForwardProgressWorkItemCallback(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  
  uVar2 = *(uint *)(param_2 + 0x68);
  uVar3 = *(undefined8 *)(param_2 + 0x20);
  pcVar4 = *(code **)(param_2 + 0x30);
  uVar5 = *(undefined8 *)(param_2 + 0x38);
  *(undefined8 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x68) = uVar2 & 0xfffffffd;
  ObfReferenceObject(uVar3);
  (*pcVar4)(uVar3,uVar5,param_2);
  ObfDereferenceObject(uVar3);
  if ((uVar2 & 1) != 0) {
    uVar6 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x40);
    piVar1 = (int *)(param_2 + 0x48);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      KeSetEvent(param_2 + 0x50,0,0);
    }
    KeReleaseSpinLock(param_2 + 0x40,uVar6);
  }
  return;
}



===== _UcxEndpointCreate @ 14000bdc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong _UcxEndpointCreate(undefined8 param_1,undefined8 param_2,longlong *param_3,
                            undefined8 *param_4,longlong *param_5)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong *plVar15;
  undefined8 *puVar16;
  undefined4 *puVar17;
  undefined1 *puVar18;
  longlong lVar19;
  ulonglong uVar20;
  longlong lVar21;
  longlong local_res18;
  longlong local_res20;
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulonglong local_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined *local_48;
  
  local_78 = 0x38;
  local_80 = local_80 & 0xffffffff00000000;
  local_74 = 0;
  local_6c = 0;
  local_50 = 0;
  *param_5 = 0;
  local_48 = PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88;
  local_60 = 1;
  local_5c = 1;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_58 = *(undefined8 *)(*param_3 + 8);
  local_68 = Endpoint_EvtDestroyCallback;
  puVar16 = param_4;
  if ((param_4 != (undefined8 *)0x0) && (*(int *)(param_4 + 3) == 2)) {
    local_b0 = *param_4;
    uStack_a8 = param_4[1];
    puVar16 = &local_b0;
    local_60 = 2;
    local_a0 = param_4[2];
    local_90 = param_4[4];
    uStack_88 = param_4[5];
    uStack_98 = CONCAT44((int)((ulonglong)param_4[3] >> 0x20),1);
    local_80 = param_4[6];
  }
  local_res18 = 0;
  uVar10 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_78,&local_res18);
  uVar20 = (ulonglong)uVar10;
  if ((int)uVar10 < 0) {
LAB_14000c0da:
    if (local_res18 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    lVar19 = 0;
    if ((int)uVar20 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar20;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x13,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar20);
      puVar18 = auStackY_108;
      goto LAB_14000c426;
    }
  }
  else {
    if (puVar16 != (undefined8 *)0x0) {
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res18,puVar16,0);
      uVar20 = (ulonglong)uVar10;
    }
    if ((int)uVar20 < 0) goto LAB_14000c0da;
    lVar19 = local_res18;
  }
  puVar18 = auStackY_108;
  (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,param_2,_UcxEndpointCreate,0x469);
  puVar12 = (undefined4 *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar19,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88)
  ;
  lVar21 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  lVar14 = *(longlong *)(lVar21 + 0x18);
  local_res20 = lVar14;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *puVar12 = 0x70646e45;
  *(longlong *)(puVar12 + 2) = lVar19;
  *(undefined8 *)(puVar12 + 0x10) = *(undefined8 *)(lVar21 + 0x18);
  *(longlong *)(puVar12 + 0x12) = lVar21;
  puVar12[8] = *(undefined4 *)(*param_3 + 4);
  *(undefined4 **)(puVar12 + 0xc) = puVar12 + 4;
  iVar11 = Endpoint_CalculateMaximumTransferSize(lVar21,*param_3);
  puVar12[9] = iVar11;
  lVar3 = *param_3;
  uVar4 = *(undefined8 *)(lVar3 + 0x38);
  *(undefined8 *)(puVar12 + 0x18) = *(undefined8 *)(lVar3 + 0x30);
  *(undefined8 *)(puVar12 + 0x1a) = uVar4;
  uVar4 = *(undefined8 *)(lVar3 + 0x48);
  *(undefined8 *)(puVar12 + 0x1c) = *(undefined8 *)(lVar3 + 0x40);
  *(undefined8 *)(puVar12 + 0x1e) = uVar4;
  uVar4 = *(undefined8 *)(lVar3 + 0x58);
  *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(lVar3 + 0x50);
  *(undefined8 *)(puVar12 + 0x22) = uVar4;
  uVar4 = *(undefined8 *)(lVar3 + 0x68);
  *(undefined8 *)(puVar12 + 0x24) = *(undefined8 *)(lVar3 + 0x60);
  *(undefined8 *)(puVar12 + 0x26) = uVar4;
  uVar6 = *(undefined4 *)(lVar3 + 0x74);
  uVar7 = *(undefined4 *)(lVar3 + 0x78);
  uVar8 = *(undefined4 *)(lVar3 + 0x7c);
  puVar12[0x28] = *(undefined4 *)(lVar3 + 0x70);
  puVar12[0x29] = uVar6;
  puVar12[0x2a] = uVar7;
  puVar12[0x2b] = uVar8;
  uVar4 = *(undefined8 *)(lVar3 + 0x88);
  *(undefined8 *)(puVar12 + 0x2c) = *(undefined8 *)(lVar3 + 0x80);
  *(undefined8 *)(puVar12 + 0x2e) = uVar4;
  if (*(char *)(*param_3 + 0x90) == '\x01') {
    uVar13 = StateMachineEngine_Init
                       (*(longlong *)(puVar12 + 0x10),(undefined8 *)(puVar12 + 0x48),lVar19,puVar12,
                        0x13,0x14002dcb0,Etw_UcxEndpointStateMachineEvent,
                        Etw_UcxEndpointStateMachineTransition,*(int *)(lVar14 + 0x4c8) == 2);
    uVar20 = uVar13 & 0xffffffff;
    if (-1 < (int)uVar13) {
      *(byte *)((longlong)puVar12 + 0x2a5) = *(byte *)((longlong)puVar12 + 0x2a5) | 1;
      *(undefined1 *)((longlong)puVar12 + 0x2fb) = 1;
      (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,lVar19,_UcxEndpointCreate,0x4a6);
      goto LAB_14000c1a1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x15,
                         &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)puVar12,(char)uVar13
                        );
    }
LAB_14000c3c2:
    puVar18 = auStackY_108;
    if (lVar19 != 0) {
      if (*(char *)((longlong)puVar12 + 0x2fb) == '\x01') {
        (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,lVar19,_UcxEndpointCreate,0x540);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar19);
      puVar18 = auStackY_108;
    }
  }
  else {
    *(undefined1 *)((longlong)puVar12 + 0x2fb) = 0;
LAB_14000c1a1:
    if (*(int *)(*param_3 + 4) == 2) {
      *(undefined4 **)(lVar21 + 0xf8) = puVar12;
      *(undefined4 **)(lVar21 + 0x100) = puVar12 + 4;
    }
    iVar11 = *(int *)(*param_3 + 0x10);
    puVar12[7] = iVar11;
    lVar3 = *param_3;
    puVar12[0xbd] = *(undefined4 *)(lVar3 + 0x14);
    *(undefined2 *)(puVar12 + 0xbe) = *(undefined2 *)(lVar3 + 0x18);
    *(undefined1 *)((longlong)puVar12 + 0x2fa) = *(undefined1 *)(lVar3 + 0x1a);
    if ((iVar11 != 1) &&
       (*(bool *)((longlong)puVar12 + 0x19) = *(char *)((longlong)puVar12 + 0x2f6) < '\0',
       iVar11 == 3)) {
      if (*(uint *)(*(longlong *)(puVar12 + 0x12) + 0x10c) < 2) {
        puVar12[10] = 0xff;
        puVar12[0xb] = 8;
      }
      else {
        puVar12[10] = 0x400;
        puVar12[0xb] = 1 << (*(char *)((longlong)puVar12 + 0x2fa) - 1U & 0x1f);
      }
    }
    *(undefined1 *)((longlong)puVar12 + 0x2fd) = *(undefined1 *)(lVar14 + 0x471);
    if (iVar11 - 3U < 2) {
      *(undefined1 *)((longlong)puVar12 + 0x2fd) = 0;
    }
    if (1 < *(uint *)(lVar21 + 0x10c)) {
      *(undefined1 *)((longlong)puVar12 + 0x2fd) = 0;
    }
    if (*(longlong *)(lVar21 + 0x110) == 0) {
      *(undefined1 *)((longlong)puVar12 + 0x2fd) = 0;
    }
    puVar16 = (undefined8 *)(puVar12 + 0x30);
    *(undefined8 *)(puVar12 + 0x36) = 0;
    plVar2 = (longlong *)(puVar12 + 0x44);
    *(undefined8 *)(puVar12 + 0x34) = 0;
    lVar14 = local_res20 + 0x1e8;
    *(undefined8 *)(puVar12 + 0x3a) = 0;
    *(undefined8 *)(puVar12 + 0x38) = 0;
    *(undefined8 *)(puVar12 + 0x32) = 0;
    *puVar16 = 0;
    *(undefined8 *)(puVar12 + 0x42) = 0;
    *(undefined8 *)(puVar12 + 0x40) = 0;
    *(undefined8 *)(puVar12 + 0x46) = 0;
    *plVar2 = 0;
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar14);
    if (*(char *)(lVar21 + 0x19c) == '\0') {
      puVar1 = (undefined8 *)(lVar21 + 0x50);
      plVar15 = (longlong *)*puVar1;
      puVar17 = puVar12;
      if ((undefined8 *)plVar15[1] == puVar1) {
        *puVar16 = plVar15;
        *(undefined8 **)(puVar12 + 0x32) = puVar1;
        plVar15[1] = (longlong)puVar16;
        *puVar1 = puVar16;
        *(int *)(local_res20 + 500) = *(int *)(local_res20 + 500) + 1;
        goto LAB_14000c313;
      }
LAB_14000c368:
      pcVar5 = (code *)swi(0x29);
      uVar9 = (*pcVar5)(3);
      puVar18 = auStackY_100;
LAB_14000c36f:
      *plVar2 = lVar21;
      *(longlong **)(puVar12 + 0x46) = plVar15;
      *plVar15 = (longlong)plVar2;
      *(longlong **)(lVar21 + 8) = plVar2;
LAB_14000c37d:
      *(undefined8 *)(puVar18 + -8) = 0x14000c389;
      KeReleaseSpinLock(puVar17,uVar9);
    }
    else {
      uVar20 = 0xc000009d;
LAB_14000c313:
      KeReleaseSpinLock(lVar14,uVar9);
      if ((int)uVar20 < 0) goto LAB_14000c3c2;
      if (*(char *)(lVar21 + 0x1a1) != '\0') {
        puVar17 = (undefined4 *)(lVar21 + 0x80);
        uVar9 = KeAcquireSpinLockRaiseToDpc(puVar17);
        puVar18 = auStackY_108;
        if ((*plVar2 == 0) && (puVar18 = auStackY_108, *(longlong *)(puVar12 + 0x46) == 0)) {
          plVar15 = *(longlong **)(lVar21 + 0x78);
          lVar21 = lVar21 + 0x70;
          puVar18 = auStackY_108;
          if (*plVar15 != lVar21) goto LAB_14000c368;
          goto LAB_14000c36f;
        }
        goto LAB_14000c37d;
      }
    }
    *param_5 = lVar19;
    *(longlong *)(*param_3 + 0x28) = lVar19;
    *param_3 = 0;
  }
LAB_14000c426:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(int *)(puVar18 + 0x28) = (int)uVar20;
    *(undefined **)(puVar18 + 0x20) = &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids;
    *(undefined8 *)(puVar18 + -8) = 0x14000c45b;
    WPP_RECORDER_SF_D(uVar4,5,2,0x16,*(undefined8 *)(puVar18 + 0x20),puVar18[0x28]);
  }
  return uVar20;
}



===== Endpoint_CalculateMaximumTransferSize @ 14000c480 =====

int Endpoint_CalculateMaximumTransferSize(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x10);
  if (iVar4 != 3) {
    iVar1 = *(int *)((&g_EndpointMaximumTransferSizeTable)[(int)*(uint *)(param_1 + 0x10c)] +
                    (longlong)iVar4 * 4);
    if (iVar4 != 1) {
      return iVar1;
    }
    if (1 < *(uint *)(param_1 + 0x10c)) {
      return iVar1;
    }
    if (g_Allow64KLowOrFullSpeedControlTransfersFlag == '\0') {
      return iVar1;
    }
    return 0x10000;
  }
  uVar3 = (uint)*(ushort *)(param_2 + 0x18);
  if (*(uint *)(param_1 + 8) < 0x250) {
    uVar3 = ((*(ushort *)(param_2 + 0x18) >> 0xb & 3) + 1) * (uVar3 & 0x7ff);
  }
  iVar4 = *(int *)(param_1 + 0x10c);
  if (iVar4 == 1) {
LAB_14000c503:
    iVar4 = uVar3 << 8;
  }
  else {
    if (iVar4 == 2) {
      uVar2 = Feature_EUSB2__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar2 != 0) && (*(short *)(param_2 + 0x18) == 0)) &&
         (*(char *)(param_2 + 0x9a) == '\x12')) {
        return *(int *)(param_2 + 0x9d);
      }
    }
    else {
      if (iVar4 != 3) goto LAB_14000c503;
      if (*(char *)(param_2 + 0x1e) < '\0') {
        uVar3 = *(uint *)(param_2 + 0x95);
      }
      else {
        uVar3 = (uint)*(ushort *)(param_2 + 0x1f);
      }
    }
    iVar4 = uVar3 << 10;
  }
  return iVar4;
}



===== WPP_RECORDER_SF_qqqq @ 14000c54c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,0x14,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,0x14,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,0);
  return;
}



===== Controller_ForwardProgressWorkItemAllocateFromHub @ 14000c660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_ForwardProgressWorkItemAllocateFromHub
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  Controller_ForwardProgressWorkItemAllocate(*(undefined8 *)(lVar1 + 0x18),param_2,param_3);
  return;
}



===== StateMachineEngine_Init @ 14000c6b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
StateMachineEngine_Init
          (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,uint param_5,
          longlong param_6,undefined8 param_7,undefined8 param_8,undefined1 param_9)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  memset(param_2 + 2,0,0x198);
  *param_2 = param_3;
  param_2[1] = param_4;
  param_2[4] = *(undefined8 *)(param_6 + (ulonglong)param_5 * 8);
  param_2[2] = param_6;
  KeInitializeSpinLock(param_2 + 3);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10))
  ;
  puVar2 = Controller_ForwardProgressWorkItemAllocate(param_1,uVar3,0);
  uVar3 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    param_2[0x17] = puVar2;
    param_2[0x32] = param_7;
    param_2[0x33] = param_8;
    *(undefined1 *)(param_2 + 0x34) = param_9;
    *(undefined4 *)((longlong)param_2 + (ulonglong)*(byte *)((longlong)param_2 + 0x181) * 4 + 0x140)
         = 0xebe00030;
    *(byte *)((longlong)param_2 + 0x181) = *(char *)((longlong)param_2 + 0x181) + 1U & 0xf;
    (*(code *)param_2[0x32])(0,*param_2,param_2,0xebe00030);
    uVar1 = *(undefined4 *)param_2[4];
    *(undefined4 *)((longlong)param_2 + (ulonglong)*(byte *)(param_2 + 0x30) * 8 + 0xc4) = uVar1;
    *(undefined4 *)(param_2 + (ulonglong)*(byte *)(param_2 + 0x30) + 0x18) = 0xebe00030;
    *(byte *)(param_2 + 0x30) = *(char *)(param_2 + 0x30) + 1U & 0xf;
    (*(code *)param_2[0x33])(0,*param_2,param_2,0xebe00030,uVar1);
  }
  return uVar3;
}



===== Controller_ForwardProgressWorkItemAllocate @ 14000c834 =====

undefined4 *
Controller_ForwardProgressWorkItemAllocate(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x70,0x44434855);
  if (puVar1 == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x5c,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  else {
    lVar2 = IoAllocateWorkItem(param_2);
    if (lVar2 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x5d,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
      }
      ExFreePoolWithTag(puVar1,0x44434855);
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0x69577046;
      *(undefined8 *)(puVar1 + 4) = 0;
      *(undefined8 *)(puVar1 + 2) = 0;
      KeInitializeEvent(puVar1 + 0x14,0,1);
      KeInitializeSpinLock(puVar1 + 0x10);
      *(undefined8 *)(puVar1 + 8) = param_2;
      *(longlong *)(puVar1 + 10) = lVar2;
      *(undefined8 *)(puVar1 + 6) = param_1;
      if ((param_3 & 1) != 0) {
        puVar1[0x1a] = puVar1[0x1a] | 1;
      }
    }
  }
  return puVar1;
}



===== UcxEndpointEventHandler_ClearEnabledFlagAndCompletePendingOperation @ 14000c990 =====

undefined8 UcxEndpointEventHandler_ClearEnabledFlagAndCompletePendingOperation(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x2fe) = 0;
  UsbDevice_PendingOperationCompleteByEndpoint(*(longlong *)(param_1 + 0x48));
  return 0;
}



===== UcxEndpointStateEntryFunc_CompletingPendingOperation2 @ 14000c9c0 =====

undefined8 UcxEndpointStateEntryFunc_CompletingPendingOperation2(longlong param_1)

{
  UsbDevice_PendingOperationCompleteByEndpoint(*(longlong *)(param_1 + 0x48));
  return 0xebe300c2;
}



===== UcxEndpointEventHandler_CompletePendingOperation @ 14000c9e0 =====

undefined8 UcxEndpointEventHandler_CompletePendingOperation(longlong param_1)

{
  UsbDevice_PendingOperationCompleteByEndpoint(*(longlong *)(param_1 + 0x48));
  return 0;
}



===== UsbDevice_PendingOperationCompleteByEndpoint @ 14000c9fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PendingOperationCompleteByEndpoint(longlong param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x188);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    pcVar3 = *(code **)(param_1 + 0x180);
    *(undefined8 *)(param_1 + 0x180) = 0;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x17,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x10));
    }
    (*pcVar3)(param_1);
  }
  return;
}



===== Controller_ForwardProgressWorkItemEnqueue @ 14000caa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_ForwardProgressWorkItemEnqueue
               (longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 2;
  lVar1 = *(longlong *)(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x30) = param_2;
  *(undefined8 *)(param_1 + 0x38) = param_3;
  if ((*(uint *)(param_1 + 0x68) & 1) != 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    KeClearEvent(param_1 + 0x50);
    KeReleaseSpinLock(param_1 + 0x40,uVar3);
  }
  if ((g_IoTryQueueWorkItem != (code *)0x0) &&
     (cVar4 = (*g_IoTryQueueWorkItem)
                        (*(undefined8 *)(param_1 + 0x28),
                         Controller_ForwardProgressWorkItemWdmCallback,1,param_1), cVar4 != '\0')) {
    return;
  }
  if ((param_4 == -0x352fffff) || (*(longlong *)(lVar1 + 0x418) == 0)) {
    IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x28),Controller_ForwardProgressWorkItemWdmCallback,
                      1,param_1);
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x400);
    puVar7 = auStack_38;
    lVar5 = lVar1 + 0x408;
    plVar8 = (longlong *)(param_1 + 8);
    plVar6 = *(longlong **)(lVar1 + 0x410);
    if (*plVar6 != lVar5) {
      lVar5 = 3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puVar7 = auStack_30;
    }
    *plVar8 = lVar5;
    *(longlong **)(param_1 + 0x10) = plVar6;
    *plVar6 = (longlong)plVar8;
    *(longlong **)(lVar5 + 8) = plVar8;
    *(undefined8 *)(puVar7 + -8) = 0x14000cbba;
    KeSetEvent(lVar1 + 0x420,0,0);
    *(undefined8 *)(puVar7 + -8) = 0x14000cbcc;
    KeReleaseSpinLock(lVar1 + 0x400,uVar3);
  }
  return;
}



===== McTemplateK0pqqqqqqqsssz_EtwWriteTransfer @ 14000cc04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pqqqqqqqsssz_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,char *param_12,
               char *param_13,char *param_14,wchar_t *param_15)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_res20;
  undefined1 auStackY_128 [32];
  undefined8 local_f8 [2];
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e8 = &local_res20;
  lVar2 = -1;
  local_e0 = 8;
  local_d8 = &param_5;
  local_c8 = &param_6;
  local_b8 = &param_7;
  local_a8 = &param_8;
  local_98 = &param_9;
  local_88 = &param_10;
  local_78 = &param_11;
  local_d0 = 4;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  if (param_12 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_12[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_68 = param_12;
  if (param_12 == (char *)0x0) {
    local_68 = "NULL";
  }
  if (param_13 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_13[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_58 = param_13;
  if (param_13 == (char *)0x0) {
    local_58 = "NULL";
  }
  if (param_14 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_14[lVar1] != '\0');
    local_40 = (int)lVar1 + 1;
  }
  local_3c = 0;
  local_48 = param_14;
  if (param_14 == (char *)0x0) {
    local_48 = "NULL";
  }
  if (param_15 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    do {
      lVar2 = lVar2 + 1;
    } while (param_15[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_30 = (undefined4)uVar3;
  local_2c = 0;
  local_38 = param_15;
  if (param_15 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(uVar3,param_2,param_3,0xd,local_f8);
  return;
}



===== UsbDevice_PrepareForControllerResetCallback @ 14000ce00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PrepareForControllerResetCallback(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x15,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x10),(char)param_1);
    }
    *(undefined1 *)(param_1 + 0x19e) = 1;
    for (puVar4 = *(undefined8 **)(param_1 + 0x50); (undefined8 *)(param_1 + 0x50) != puVar4;
        puVar4 = (undefined8 *)*puVar4) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,puVar4[-0x17],UsbDevice_PrepareForControllerResetCallback,0x4e7,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
      plVar2 = *(longlong **)(param_2 + 8);
      plVar1 = puVar4 + 4;
      if (*plVar2 != param_2) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *plVar1 = param_2;
      puVar4[5] = plVar2;
      *plVar2 = (longlong)plVar1;
      *(longlong **)(param_2 + 8) = plVar1;
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
  }
  return;
}



===== _UcxUsbDeviceCreate @ 14000cf00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int _UcxUsbDeviceCreate(undefined8 param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4,
                       longlong *param_5)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 *puVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined4 *puVar16;
  longlong lVar17;
  longlong local_res20;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined4 local_78;
  ulonglong local_74;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined *local_48;
  
  local_74 = local_74 & 0xffffffff00000000;
  *param_5 = 0;
  lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(*param_3 + 8),
                      PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,
                      PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870);
  local_48 = PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
  local_60 = 1;
  local_5c = 1;
  local_74 = 0;
  local_6c = 0;
  local_78 = 0x38;
  local_68 = UsbDevice_EvtDestroyCallback;
  local_58 = 0;
  uStack_50 = 0;
  if (param_4 == (undefined4 *)0x0) {
    param_4 = &local_78;
    puVar16 = (undefined4 *)0x0;
    local_58 = *(undefined8 *)(*param_3 + 8);
  }
  else {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(*param_3 + 8);
    puVar16 = &local_78;
  }
  local_res20 = 0;
  iVar9 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,param_4,&local_res20);
  if (iVar9 < 0) {
LAB_14000d280:
    if (local_res20 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    lVar17 = 0;
    if (iVar9 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar9;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)iVar9);
      puVar15 = auStackY_c8;
      goto LAB_14000d3c7;
    }
  }
  else {
    if (puVar16 != (undefined4 *)0x0) {
      iVar9 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res20,puVar16,0);
    }
    if (iVar9 < 0) goto LAB_14000d280;
    lVar17 = local_res20;
  }
  puVar15 = auStackY_c8;
  puVar12 = (undefined4 *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar17,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0
                      );
  *puVar12 = 0x69766544;
  *(longlong *)(puVar12 + 4) = lVar17;
  *(longlong *)(puVar12 + 6) = lVar11;
  uVar2 = *(undefined8 *)(*param_3 + 8);
  *(undefined8 *)(puVar12 + 8) = uVar2;
  *(undefined8 *)(puVar12 + 10) = *(undefined8 *)(*param_3 + 0x58);
  (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,uVar2,_UcxUsbDeviceCreate,0x36e);
  *(undefined2 *)((longlong)puVar12 + 0x19e) = 0x100;
  plVar1 = (longlong *)(puVar12 + 0x10);
  *(undefined1 *)(puVar12 + 0x68) = 1;
  *(undefined1 *)(puVar12 + 0x67) = 0;
  lVar13 = *param_3;
  uVar2 = *(undefined8 *)(lVar13 + 0x20);
  *(undefined8 *)(puVar12 + 0x42) = *(undefined8 *)(lVar13 + 0x18);
  *(undefined8 *)(puVar12 + 0x44) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x30);
  *(undefined8 *)(puVar12 + 0x46) = *(undefined8 *)(lVar13 + 0x28);
  *(undefined8 *)(puVar12 + 0x48) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x40);
  *(undefined8 *)(puVar12 + 0x4a) = *(undefined8 *)(lVar13 + 0x38);
  *(undefined8 *)(puVar12 + 0x4c) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x50);
  *(undefined8 *)(puVar12 + 0x4e) = *(undefined8 *)(lVar13 + 0x48);
  *(undefined8 *)(puVar12 + 0x50) = uVar2;
  lVar13 = *param_3;
  uVar2 = *(undefined8 *)(lVar13 + 0x68);
  *(undefined8 *)(puVar12 + 0x22) = *(undefined8 *)(lVar13 + 0x60);
  *(undefined8 *)(puVar12 + 0x24) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x78);
  *(undefined8 *)(puVar12 + 0x26) = *(undefined8 *)(lVar13 + 0x70);
  *(undefined8 *)(puVar12 + 0x28) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x88);
  *(undefined8 *)(puVar12 + 0x2a) = *(undefined8 *)(lVar13 + 0x80);
  *(undefined8 *)(puVar12 + 0x2c) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0x98);
  *(undefined8 *)(puVar12 + 0x2e) = *(undefined8 *)(lVar13 + 0x90);
  *(undefined8 *)(puVar12 + 0x30) = uVar2;
  uVar2 = *(undefined8 *)(lVar13 + 0xa8);
  *(undefined8 *)(puVar12 + 0x32) = *(undefined8 *)(lVar13 + 0xa0);
  *(undefined8 *)(puVar12 + 0x34) = uVar2;
  uVar4 = *(undefined4 *)(lVar13 + 0xb4);
  uVar5 = *(undefined4 *)(lVar13 + 0xb8);
  uVar6 = *(undefined4 *)(lVar13 + 0xbc);
  puVar12[0x36] = *(undefined4 *)(lVar13 + 0xb0);
  puVar12[0x37] = uVar4;
  puVar12[0x38] = uVar5;
  puVar12[0x39] = uVar6;
  uVar4 = *(undefined4 *)(lVar13 + 0xc4);
  uVar5 = *(undefined4 *)(lVar13 + 200);
  uVar6 = *(undefined4 *)(lVar13 + 0xcc);
  puVar16 = puVar12 + 0x14;
  puVar12[0x3a] = *(undefined4 *)(lVar13 + 0xc0);
  puVar12[0x3b] = uVar4;
  puVar12[0x3c] = uVar5;
  puVar12[0x3d] = uVar6;
  *(undefined4 **)(puVar12 + 0x16) = puVar16;
  *(undefined4 **)puVar16 = puVar16;
  puVar16 = puVar12 + 0x18;
  *(undefined4 **)(puVar12 + 0x1a) = puVar16;
  *(undefined4 **)puVar16 = puVar16;
  puVar16 = puVar12 + 0xc;
  *(undefined4 **)(puVar12 + 0xe) = puVar16;
  *(undefined4 **)puVar16 = puVar16;
  *(undefined8 *)(puVar12 + 0x12) = 0;
  *plVar1 = 0;
  KeInitializeSpinLock(puVar12 + 0x5a);
  KeInitializeSpinLock(puVar12 + 0x72);
  puVar16 = puVar12 + 0x74;
  *(undefined4 **)(puVar12 + 0x76) = puVar16;
  *(undefined4 **)puVar16 = puVar16;
  KeInitializeSpinLock(puVar12 + 0x20);
  puVar16 = puVar12 + 0x1c;
  *(undefined4 **)(puVar12 + 0x1e) = puVar16;
  *(undefined4 **)puVar16 = puVar16;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar11 + 0x1e8);
  if (*(char *)(lVar10 + 0x19c) == '\0') {
    lVar13 = lVar10 + 0x30;
    plVar14 = *(longlong **)(lVar10 + 0x38);
    if (*plVar14 != lVar13) {
      plVar14 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      lVar13 = (*pcVar3)(3,uVar8);
      puVar15 = auStackY_c0;
    }
    *plVar1 = lVar13;
    *(longlong **)(puVar12 + 0x12) = plVar14;
    *plVar14 = (longlong)plVar1;
    *(longlong **)(lVar13 + 8) = plVar1;
    *(int *)(lVar11 + 0x1f0) = *(int *)(lVar11 + 0x1f0) + 1;
    *(undefined1 *)((longlong)puVar12 + 0x19f) = *(undefined1 *)(lVar10 + 0x19f);
    *(undefined1 *)(puVar12 + 0x68) = *(undefined1 *)(lVar10 + 0x19f);
    iVar7 = iVar9;
LAB_14000d33d:
    iVar9 = iVar7;
  }
  else {
    iVar9 = -0x3ffffff2;
    puVar15 = auStackY_c8;
    iVar7 = -0x3ffffff2;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000d33d;
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xe,
                       &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,
                       (char)*(undefined8 *)(lVar10 + 0x10),0xe);
    puVar15 = auStackY_c8;
  }
  *(undefined8 *)(puVar15 + -8) = 0x14000d34f;
  KeReleaseSpinLock(lVar11 + 0x1e8);
  if (iVar9 < 0) {
    if (lVar17 != 0) {
      pcVar3 = *(code **)(WdfFunctions_01015 + 0x680);
      *(undefined8 *)(puVar15 + -8) = 0x14000d3c7;
      (*pcVar3)(WdfDriverGlobals,lVar17);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      *(undefined4 **)(puVar15 + 0x30) = puVar12;
      *(longlong *)(puVar15 + 0x28) = lVar17;
      *(undefined **)(puVar15 + 0x20) = &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids;
      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined8 *)(puVar15 + -8) = 0x14000d38c;
      WPP_RECORDER_SF_qq(uVar2,4,5,0xf,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28],puVar15[0x30]);
    }
    *param_5 = lVar17;
    *(longlong *)(*param_3 + 0x10) = lVar17;
    *param_3 = 0;
  }
LAB_14000d3c7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(int *)(puVar15 + 0x28) = iVar9;
    *(undefined **)(puVar15 + 0x20) = &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids;
    *(undefined8 *)(puVar15 + -8) = 0x14000d3fd;
    WPP_RECORDER_SF_D(uVar2,5,5,0x10,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28]);
  }
  return iVar9;
}



===== WPP_RECORDER_SF_qq @ 14000d424 =====

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



===== RootHub_EvtUSBDInterfaceRequest @ 14000d550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000db4a) */

uint RootHub_EvtUSBDInterfaceRequest
               (undefined8 param_1,undefined8 param_2,ushort *param_3,longlong param_4)

{
  int *piVar1;
  code *pcVar2;
  ushort uVar3;
  undefined1 uVar4;
  ushort uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  uint uVar11;
  ushort *puVar12;
  undefined2 uVar13;
  ushort uVar14;
  ushort uVar15;
  longlong local_res18;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  longlong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_res18 = 0;
  local_48 = local_48 & 0xffffffff00000000;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar12 = param_3;
  if (param_4 == 0) {
    puVar12 = (ushort *)PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8;
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    param_4 = *(longlong *)(*(longlong *)(lVar6 + 8) + 8);
  }
  uVar14 = 0x98;
  if (*param_3 < 0x98) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar12 = (ushort *)0x9;
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x53,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x98,(char)*param_3);
    }
    uVar11 = 0xc0000023;
LAB_14000d615:
    puVar10 = auStackY_b8;
  }
  else {
    uVar15 = 0x602;
    if (param_3[1] < 0x602) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar12 = (ushort *)0x9;
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x54,
                          &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_3[1]);
      }
      uVar11 = 0xc00000bb;
      goto LAB_14000d615;
    }
    puVar12 = (ushort *)PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_4);
    if (*(longlong *)(param_3 + 0x18) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x55;
LAB_14000d6ab:
        puVar12 = (ushort *)0x9;
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar13,
                           &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_3,
                           (char)param_4);
      }
LAB_14000d6d9:
      uVar11 = 0xc000000d;
LAB_14000d6de:
      puVar10 = auStackY_b8;
    }
    else {
      if (*(int *)(param_3 + 0x1c) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x56;
          goto LAB_14000d6ab;
        }
        goto LAB_14000d6d9;
      }
      local_48 = 0;
      local_68 = 0;
      uStack_60 = 0x100000001;
      uStack_70 = 0;
      local_78 = 0x38;
      uStack_50 = 0;
      local_58 = param_4;
      uVar11 = (**(code **)(WdfFunctions_01015 + 0x600))
                         (WdfDriverGlobals,&local_78,ExDefaultNonPagedPoolType);
      if ((int)uVar11 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar11;
        }
        puVar12 = (ushort *)0x9;
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x57,
                            &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_3,
                            (char)param_4,(char)uVar11);
        goto LAB_14000d6de;
      }
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,0,RootHub_USBDInterfaceV1Unregister,0xe41);
      memset((void *)0x0,0,0x90);
      uRam0000000000000000 = 0x68644455;
      uRam0000000000000008 = *(undefined8 *)(param_3 + 0x18);
      uRam0000000000000010 = *(undefined4 *)(param_3 + 0x1c);
      uRam0000000000000004 = *(undefined4 *)(param_3 + 0x10);
      uRam0000000000000018 = *(undefined8 *)(param_3 + 0x20);
      uRam0000000000000028 = 0;
      lRam0000000000000020 = lVar6;
      uRam0000000000000030 = param_1;
      KeInitializeSpinLock(0x70);
      uRam0000000000000080 = 0x78;
      uRam0000000000000078 = 0x78;
      if (*(int *)(param_3 + 0x24) != 0) {
        cRam000000000000008a = '\x01';
        uRam0000000000000048 = *(uint *)(param_3 + 0x26);
        uRam000000000000004c = *(undefined4 *)(param_3 + 0x28);
        uRam0000000000000058 = *(undefined4 *)(param_3 + 0x2a);
        uRam000000000000005c = *(undefined4 *)(param_3 + 0x2c);
        uRam0000000000000060 = *(undefined4 *)(param_3 + 0x2e);
      }
      if ((cRam000000000000008a != '\0') || (*(char *)(*(longlong *)(lVar6 + 0x18) + 0x3f9) != '\0')
         ) {
        uRam000000000000008b = 1;
      }
      if (cRam000000000000008a != '\0') {
        UsbDevice_EnableInvalidHandleTracking(lVar6);
      }
      uVar7 = Ucx_FailDueToVerifierSetting(uRam0000000000000048);
      if ((char)uVar7 == '\0') {
        param_3[4] = 0;
        param_3[5] = 0;
        param_3[6] = 0;
        param_3[7] = 0;
        *(code **)(param_3 + 8) = _guard_check_icall;
        *(longlong *)(param_3 + 0x14) = local_res18;
        *(code **)(param_3 + 0xc) = _guard_check_icall;
        *(code **)(param_3 + 0x38) = Xrb_Allocate;
        *(code **)(param_3 + 0x3c) = Xrb_SecureIsochAllocate;
        *(code **)(param_3 + 0x40) = Xrb_SelectConfigAllocateAndBuild;
        *(code **)(param_3 + 0x44) = Xrb_SelectInterfaceAllocateAndBuild;
        *(code **)(param_3 + 0x48) = Xrb_Free;
        *(code **)(param_3 + 0x34) = RootHub_USBDInterfaceV1Unregister;
        ObfReferenceObjectWithTag
                  (*(undefined8 *)(local_res18 + 8),RootHub_USBDInterfaceV1Unregister);
        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x1c8);
        puVar10 = auStackY_b8;
        lVar9 = lVar6 + 0x1d0;
        puVar12 = *(ushort **)(lVar6 + 0x1d8);
        plVar8 = (longlong *)0x38;
        if (*(longlong *)puVar12 != lVar9) {
          plVar8 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          uVar4 = (*pcVar2)();
          puVar10 = auStackY_b0;
        }
        *plVar8 = lVar9;
        plVar8[1] = (longlong)puVar12;
        *(longlong **)puVar12 = plVar8;
        *(longlong **)(lVar9 + 8) = plVar8;
        *(undefined8 *)(puVar10 + -8) = 0x14000da40;
        KeReleaseSpinLock(lVar6 + 0x1c8,uVar4);
        LOCK();
        piVar1 = (int *)(*(longlong *)(lVar6 + 0x18) + 0x480);
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        uVar5 = param_3[1];
        if (0x602 < uVar5) {
          puVar12 = (ushort *)0xa8;
          uVar3 = 0x98;
          if (0xa7 < *param_3) {
            *(code **)(param_3 + 0x4c) = Xrb_SecureIsochAllocate;
            if (*(int *)(param_3 + 0x24) != 0) {
              uRam0000000000000050 = *(undefined4 *)(param_3 + 0x50);
              uVar5 = param_3[1];
            }
            uVar15 = 0x603;
            uVar14 = 0xa8;
            uVar3 = 0xa8;
            if (uVar5 < 0x603) goto LAB_14000daf3;
          }
          uVar14 = uVar3;
          puVar12 = (ushort *)0xc8;
          if (199 < *param_3) {
            *(code **)(param_3 + 0x54) = Xrb_SelectInterfaceWithEndpointOffloadAllocate;
            *(code **)(param_3 + 0x5c) = Xrb_AsyncNotificationRequestDuringEndpointOffloadAllocate;
            if ((*(int *)(param_3 + 0x24) != 0) &&
               (uRam0000000000000054 = *(undefined4 *)(param_3 + 0x58),
               *(int *)(param_3 + 0x24) != 0)) {
              uRam0000000000000054 = *(undefined4 *)(param_3 + 0x58);
            }
            uVar15 = 0x603;
            uVar14 = 200;
          }
        }
LAB_14000daf3:
        param_3[1] = uVar15;
        uVar11 = 0;
        *param_3 = uVar14;
      }
      else {
        g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
        uVar11 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000db3d;
        puVar12 = (ushort *)0x9;
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,9,0x58,
                          &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,
                          (char)(g_RandomNumberSeed >> 0x10));
        puVar10 = auStackY_b8;
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar14 = param_3[1];
    uVar15 = *param_3;
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(uint *)(puVar10 + 0x38) = uVar11;
    *(uint *)(puVar10 + 0x30) = (uint)uVar14;
    *(uint *)(puVar10 + 0x28) = (uint)uVar15;
    *(undefined8 *)(puVar10 + -8) = 0x14000db3d;
    WPP_RECORDER_SF_ddd(uVar7,(ulonglong)uVar15,puVar12,0x59,*(undefined8 *)(puVar10 + 0x20),
                        puVar10[0x28],puVar10[0x30],puVar10[0x38]);
  }
LAB_14000db3d:
  if ((int)uVar11 < 0) {
    return uVar11;
  }
  return uVar11;
}



===== _UcxEndpointNeedToCancelTransfers @ 14000dbc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxEndpointNeedToCancelTransfers(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  undefined4 uVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if (*(char *)(lVar2 + 0x2fd) == '\0') {
    (**(code **)(lVar2 + 0x88))(param_2);
  }
  else {
    LOCK();
    bVar4 = *(int *)(lVar2 + 0x2f0) == 0;
    if (bVar4) {
      *(int *)(lVar2 + 0x2f0) = 2;
    }
    UNLOCK();
    if (bVar4) {
      uVar5 = 1;
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,param_2,_UcxEndpointNeedToCancelTransfers,0x656,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
      lVar1 = *(longlong *)(lVar2 + 0x48);
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x110),
                         PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      (**(code **)(lVar3 + 0x1b8))
                (*(undefined8 *)(lVar3 + 0x1b0),*(undefined8 *)(lVar1 + 0x28),param_2,
                 *(undefined1 *)(lVar2 + 0x2f6),
                 CONCAT44(uVar5,*(undefined4 *)
                                 (lVar1 + 0x124 + (ulonglong)*(uint *)(lVar1 + 0x120) * 4)));
      Endpoint_TryToCallEvtEndpointOkToCancelTransfers(lVar2);
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x17,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)param_2);
    }
  }
  return;
}



===== _UcxStaticStreamsSetStreamInfo @ 14000dd20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxStaticStreamsSetStreamInfo(undefined8 param_1,undefined8 param_2,int *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8);
  lVar3 = *(longlong *)(lVar7 + 0x18);
  lVar4 = *(longlong *)(lVar7 + 0x10);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000dda3;
    uVar9 = 0xd;
  }
  else {
    if (*param_3 != 0x18) {
      *(undefined1 *)(lVar3 + 0x20) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xe,
                           &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,0x18,(char)*param_3);
      }
      goto LAB_14000dda3;
    }
    uVar2 = *(uint *)(lVar3 + 0x1c);
    uVar8 = (ulonglong)uVar2;
    uVar6 = uVar2 + 1;
    *(uint *)(lVar3 + 0x1c) = uVar6;
    if (*(uint *)(lVar7 + 4) < uVar6) {
      *(undefined1 *)(lVar3 + 0x20) = 1;
      goto LAB_14000dda3;
    }
    if (uVar6 == param_3[4]) {
      if (*(longlong *)(param_3 + 2) != 0) {
        lVar3 = *(longlong *)(lVar7 + 0x20);
        *(uint *)(lVar3 + 4 + uVar8 * 0x48) = uVar2;
        *(undefined4 *)(lVar3 + uVar8 * 0x48) = 0x6d727453;
        *(longlong *)(lVar3 + 8 + uVar8 * 0x48) = lVar7;
        *(undefined4 *)(lVar3 + 0x1c + uVar8 * 0x48) = 2;
        *(undefined1 *)(lVar3 + 0x19 + uVar8 * 0x48) = *(undefined1 *)(lVar4 + 0x19);
        *(undefined1 *)(lVar3 + 0x18 + uVar8 * 0x48) = 1;
        *(undefined4 *)(lVar3 + 0x24 + uVar8 * 0x48) = *(undefined4 *)(lVar4 + 0x24);
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,*(undefined8 *)(param_3 + 2),_UcxStaticStreamsSetStreamInfo,0xd9
                   ,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\streams.c");
        puVar1 = (undefined8 *)(lVar3 + 0x10 + uVar8 * 0x48);
        *puVar1 = *(undefined8 *)(param_3 + 2);
        *(undefined8 **)(lVar3 + 0x30 + uVar8 * 0x48) = puVar1;
        *(int *)(lVar3 + 0x40 + uVar8 * 0x48) = param_3[4];
        return;
      }
      *(undefined1 *)(lVar3 + 0x20) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000dda3;
      uVar9 = 0x10;
    }
    else {
      *(undefined1 *)(lVar3 + 0x20) = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000dda3;
      uVar9 = 0xf;
    }
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar9,
                   &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids);
LAB_14000dda3:
  if (*(char *)(*(longlong *)(lVar4 + 0x40) + 0x3f9) == '\0') {
    return;
  }
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== Endpoint_EvtDestroyCallback @ 14000df20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_EvtDestroyCallback(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if (*(char *)(lVar1 + 0x2fb) != '\0') {
    Controller_ForwardProgressWorkItemDelete(*(longlong *)(lVar1 + 0x1d8));
    *(undefined1 *)(lVar1 + 0x2fb) = 0;
  }
  if (*(longlong *)(lVar1 + 0x10) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)(lVar1 + 0x10),_UcxEndpointSetWdfIoQueue,0x3e0,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  *(undefined8 *)(lVar1 + 0x30) = 0;
  if (*(longlong *)(lVar1 + 0x48) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 0x48) + 0x10),
               _UcxEndpointCreate,0x3f0,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
  }
  return;
}



===== Controller_ForwardProgressWorkItemDelete @ 14000e000 =====

void Controller_ForwardProgressWorkItemDelete(longlong param_1)

{
  IoFreeWorkItem(*(undefined8 *)(param_1 + 0x28));
  ExFreePoolWithTag(param_1,0x44434855);
  return;
}



===== McGenControlCallbackV2 @ 14000e040 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar3 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + (ulonglong)uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) <
                *(byte *)((ulonglong)uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar3 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar3) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar3) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          uVar5 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (ulonglong)(uVar6 >> 5) * 4);
          uVar2 = *puVar1;
          if (bVar4) {
            uVar5 = uVar5 | uVar2;
          }
          else {
            uVar5 = ~uVar5 & uVar2;
          }
          *puVar1 = uVar5;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
    Etw_EnableCallback(param_1,param_2);
  }
  return;
}



===== Etw_EnableCallback @ 14000e1ac =====

void Etw_EnableCallback(undefined8 param_1,int param_2)

{
  ulonglong uVar1;
  
  uVar1 = Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    Etw_EnableCallbackLegacy(param_1,param_2);
  }
  else {
    Etw_EnableCallbackNew(param_1,param_2);
  }
  return;
}



===== Controller_EvtDefaultIoInternalDeviceControl @ 14000e230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_EvtDefaultIoInternalDeviceControl
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  code *pcVar10;
  longlong lVar11;
  undefined *puVar12;
  undefined1 auStackY_198 [32];
  undefined8 local_148;
  longlong lStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 local_120;
  short *psStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined4 *puStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  ushort *puStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_198;
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar12 = PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar7);
  lVar8 = *(longlong *)(lVar8 + 8);
  lVar11 = *(longlong *)(lVar8 + 0x158);
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,lVar11);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Lqqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar12,0x32,
               &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_5,(char)param_2,
               (char)lVar8,(char)lVar11);
  }
  bVar3 = false;
  if (((param_5 == 0x49100b) || (param_5 == 0x49100f)) || (param_5 == 0x491013)) {
    LOCK();
    *(int *)(lVar8 + 0x3ec) = *(int *)(lVar8 + 0x3ec) + 1;
    UNLOCK();
    if (*(char *)(lVar8 + 0x3f0) != '\0') {
      iVar2 = *(int *)(lVar8 + 1000);
      LOCK();
      piVar1 = (int *)(lVar8 + 0x3ec);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        lVar11 = lVar8 + 0x3e0;
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar11);
        if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar8 + 1000))) {
          *(undefined1 *)(lVar8 + 0x3f1) = 1;
          KeReleaseSpinLock(lVar11,uVar5);
          StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock(lVar11,uVar5);
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x33,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc000000e);
      return;
    }
    bVar3 = true;
  }
  if (param_5 < 0x491014) {
    if (param_5 == 0x491013) {
      pcVar10 = *(code **)(lVar11 + 0x70);
    }
    else {
      if (param_5 == 0x490003) {
        local_100 = 0;
        psStack_118 = (short *)0x0;
        local_120 = 0x28;
        local_110 = 0;
        uStack_108 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_120);
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_110,
                            PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        lVar9 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
        UsbDevice_RegisterCompositeDevice(lVar11,psStack_118,*(longlong **)(lVar9 + 0x18),param_2);
        goto LAB_14000e8e3;
      }
      if (param_5 == 0x490007) {
        local_b0 = 0;
        uStack_c8 = 0;
        local_d0 = 0x28;
        local_c0 = 0;
        uStack_b8 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_d0);
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_c0,
                            PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        UsbDevice_UnregisterCompositeDevice(lVar11,param_2);
        goto LAB_14000e8e3;
      }
      if (param_5 == 0x49000b) {
        local_128 = 0;
        lStack_140 = 0;
        local_148 = 0x28;
        local_138 = 0;
        uStack_130 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_148);
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_138,
                            PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
        UsbDevice_RemoteWakeNotificationRequest(lVar11,lStack_140,param_2);
        goto LAB_14000e8e3;
      }
      if (param_5 == 0x49100b) {
        local_d8 = 0;
        puStack_f0 = (undefined4 *)0x0;
        local_f8 = 0x28;
        local_e8 = 0;
        uStack_e0 = 0;
        (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_f8);
        puVar4 = puStack_f0;
        lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(undefined8 *)(lVar11 + 0xc0),
                           PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
        *puVar4 = 0x10;
        *(longlong *)(puVar4 + 4) = lVar9 + 0x10;
        pcVar10 = *(code **)(lVar11 + 0x60);
      }
      else {
        if (param_5 != 0x49100f) goto LAB_14000e6c8;
        pcVar10 = *(code **)(lVar11 + 0x68);
      }
    }
    (*pcVar10)(uVar7,param_2);
  }
  else {
    if (param_5 == 0x49104b) {
      local_38 = 0;
      puStack_50 = (ushort *)0x0;
      local_58 = 0x28;
      local_48 = 0;
      uStack_40 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
      lVar11 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
      Controller_QueryUsbCapability(lVar8,puStack_50,*(ushort **)(lVar11 + 0x18),param_2);
      goto LAB_14000e8e3;
    }
    if (param_5 == 0x49104f) {
      local_60 = 0;
      uStack_78 = 0;
      local_80 = 0x28;
      local_70 = 0;
      uStack_68 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_80);
      lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_70,
                          PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      lVar9 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
      UsbDevice_SetFunctionData(lVar11,*(longlong *)(lVar9 + 0x18),param_2);
      goto LAB_14000e8e3;
    }
    if (param_5 == 0x491404) {
      (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
      Controller_GetDumpData(lVar8);
      goto LAB_14000e8e3;
    }
    if (param_5 == 0x491408) {
      lVar11 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
      Controller_FreeDumpData(lVar8,*(undefined8 *)(lVar11 + 0x18),param_2);
      goto LAB_14000e8e3;
    }
    if (param_5 == 0x49140f) {
      local_88 = 0;
      lStack_a0 = 0;
      local_a8 = 0x28;
      local_98 = 0;
      uStack_90 = 0;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_a8);
      iVar6 = Controller_EnableForwardProgress(lVar8,lStack_a0);
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x838);
    }
    else {
LAB_14000e6c8:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x34,
                          &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_5);
      }
      iVar6 = -0x3ffffff0;
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x838);
    }
    (*pcVar10)(WdfDriverGlobals,param_2,iVar6);
  }
LAB_14000e8e3:
  if (bVar3) {
    iVar2 = *(int *)(lVar8 + 1000);
    LOCK();
    piVar1 = (int *)(lVar8 + 0x3ec);
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      lVar11 = lVar8 + 0x3e0;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar11);
      if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar8 + 1000))) {
        *(undefined1 *)(lVar8 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar11,uVar5);
        StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar11,uVar5);
      }
    }
  }
  return;
}



===== Controller_QueryUsbCapability @ 14000e990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_QueryUsbCapability
               (longlong param_1,ushort *param_2,ushort *param_3,undefined8 param_4)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined1 uVar13;
  
  uVar13 = SUB81(param_2,0);
  if (param_2[1] == 0x28) {
    uVar2 = *param_2;
    if (uVar2 != 1) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
      uVar12 = 0x40;
      goto LAB_14000e9ea;
    }
    lVar4 = *(longlong *)(param_2 + 4);
    if (lVar4 == 0) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
      uVar12 = 0x41;
LAB_14000ea6d:
      uVar10 = 0xc000000d;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar12,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar13);
      goto LAB_14000f19e;
    }
    param_2[0x12] = 0;
    param_2[0x13] = 0;
    if (*(int *)(param_2 + 0x10) == 0) {
      if (param_3 == (ushort *)0x0) goto LAB_14000eaed;
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
      uVar12 = 0x43;
      goto LAB_14000ea6d;
    }
    if (param_3 == (ushort *)0x0) {
      uVar10 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
      uVar12 = 0x42;
      goto LAB_14000ea6d;
    }
LAB_14000eaed:
    puVar1 = param_2 + 8;
    lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_CHAINED_MDLS,0x10);
    if (lVar5 == 0x10) {
      if (param_3 != (ushort *)0x0) {
        uVar10 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
        uVar12 = 0x44;
        goto LAB_14000ea6d;
      }
      if (*(char *)(lVar4 + 0x89) == '\0') {
        uVar6 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar4 + 0x4c));
        if ((char)uVar6 != '\0') {
          g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
          uVar10 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000f19e;
          uVar12 = 0x45;
LAB_14000eba3:
          uVar11 = 1;
LAB_14000eba6:
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar11,uVar12,
                            &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar10);
          goto LAB_14000f19e;
        }
      }
    }
    else {
      lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_SECURE_TRANSFERS,0x10);
      if (lVar5 == 0x10) {
        if (param_3 != (ushort *)0x0) {
          uVar10 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000f19e;
          uVar12 = 0x46;
          goto LAB_14000ea6d;
        }
        if (*(char *)(lVar4 + 0x8c) == '\0') {
          uVar6 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar4 + 0x50));
          if ((char)uVar6 != '\0') {
            g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
            uVar10 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000f19e;
            uVar12 = 0x47;
            goto LAB_14000eba3;
          }
        }
      }
      else {
        lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,0x10);
        if (lVar5 == 0x10) {
          if (param_3 != (ushort *)0x0) {
            uVar10 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000f19e;
            uVar12 = 0x48;
            goto LAB_14000ea6d;
          }
        }
        else {
          lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_HIGH_BANDWIDTH_ISOCH,0x10);
          if (lVar5 == 0x10) {
            if (*(int *)(param_2 + 0x10) != 4) {
              uVar10 = 0xc000000d;
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14000f19e;
              uVar12 = 0x49;
              goto LAB_14000ea6d;
            }
          }
          else {
            lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_STATIC_STREAMS,0x10);
            if (lVar5 == 0x10) {
              if (*(int *)(param_2 + 0x10) != 2) {
                uVar10 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14000f19e;
                uVar12 = 0x4a;
                goto LAB_14000ea6d;
              }
              uVar6 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar4 + 0x58));
              if ((char)uVar6 != '\0') {
                g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
                uVar10 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14000f19e;
                uVar12 = 0x4b;
LAB_14000edb8:
                uVar11 = 9;
                goto LAB_14000eba6;
              }
            }
            else {
              lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_ENDPOINT_OFFLOAD,0x10);
              if (lVar5 == 0x10) {
                if (*(int *)(param_2 + 0x10) != 4) {
                  uVar10 = 0xc000000d;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14000f19e;
                  uVar12 = 0x4c;
                  goto LAB_14000ea6d;
                }
                uVar6 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar4 + 0x54));
                if ((char)uVar6 != '\0') {
                  g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
                  uVar10 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14000f19e;
                  uVar12 = 0x4d;
                  goto LAB_14000edb8;
                }
              }
              else {
                lVar5 = RtlCompareMemory(puVar1,&GUID_USB_CAPABILITY_TIME_SYNC,0x10);
                if (lVar5 == 0x10) {
                  if (param_3 == (ushort *)0x0) {
                    if (*(int *)(param_2 + 0x10) == 0) {
                      uVar6 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar4 + 100));
                      if ((char)uVar6 != '\0') {
                        g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
                        uVar10 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
                        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                        goto LAB_14000f19e;
                        uVar12 = 0x50;
                        goto LAB_14000edb8;
                      }
                      goto LAB_14000eff2;
                    }
                    uVar10 = 0xc000000d;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14000f19e;
                    uVar12 = 0x4f;
                  }
                  else {
                    uVar10 = 0xc000000d;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14000f19e;
                    uVar12 = 0x4e;
                  }
                  goto LAB_14000ea6d;
                }
                lVar5 = RtlCompareMemory(param_2 + 8,&GUID_USB_CAPABILITY_MICROSOFT_MAUSBHOST,0x10);
                if ((lVar5 != 0x10) &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_SF_qDDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                }
              }
            }
          }
        }
      }
    }
LAB_14000eff2:
    if (*(code **)(param_1 + 0x38) == (code *)0x0) {
      uVar10 = 0xc00000bb;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x52,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
      }
      goto LAB_14000f19e;
    }
    uVar10 = (**(code **)(param_1 + 0x38))
                       (*(undefined8 *)(param_1 + 0x28),param_2 + 8,*(undefined4 *)(param_2 + 0x10),
                        param_3,param_2 + 0x12);
    if ((int)uVar10 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x53,
                            &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar13,(char)param_1,
                            (char)uVar10);
      }
      goto LAB_14000f19e;
    }
    lVar5 = RtlCompareMemory(param_2 + 8,&GUID_USB_CAPABILITY_STATIC_STREAMS,0x10);
    if (lVar5 != 0x10) {
      lVar5 = RtlCompareMemory(param_2 + 8,&GUID_USB_CAPABILITY_CHAINED_MDLS,0x10);
      if (lVar5 == 0x10) {
        *(undefined1 *)(lVar4 + 0x89) = 1;
      }
      else {
        lVar5 = RtlCompareMemory(param_2 + 8,&GUID_USB_CAPABILITY_SECURE_TRANSFERS,0x10);
        if (lVar5 == 0x10) {
          *(undefined1 *)(lVar4 + 0x8c) = 1;
        }
      }
      goto LAB_14000f19e;
    }
    uVar11 = *(uint *)(lVar4 + 0x5c);
    uVar9 = (uint)*param_3;
    if (uVar11 != 0) {
      uVar3 = *(uint *)(lVar4 + 0x68);
      uVar8 = (uint)*param_3;
      if (uVar3 == 0) {
        if (uVar11 == 0xffffffff) {
          g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
          uVar9 = (uint)(ushort)((short)((g_RandomNumberSeed >> 0x10 & 0x7fff) % uVar8) + 1);
        }
        else if (uVar11 < uVar8) {
          uVar9 = (uint)*(ushort *)(lVar4 + 0x5c);
        }
      }
      else if (uVar3 < uVar8) {
        uVar9 = uVar3 & 0xffff;
      }
      *param_3 = (ushort)uVar9;
    }
    *(uint *)(lVar4 + 0x68) = uVar9;
    *(undefined1 *)(lVar4 + 0x88) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
    uVar12 = 0x54;
    bVar7 = 4;
  }
  else {
    uVar10 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f19e;
    uVar2 = *param_2;
    uVar12 = 0x3f;
LAB_14000e9ea:
    uVar9 = (uint)uVar2;
    uVar10 = 0xc000000d;
    bVar7 = 2;
  }
  WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar7,1,uVar12,
                     &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar9,uVar13);
LAB_14000f19e:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_4,uVar10);
  return;
}



===== WPP_RECORDER_SF_qqd @ 14000f1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== Controller_Address0OwnershipRelease @ 14000f330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_Address0OwnershipRelease(undefined8 param_1,undefined1 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x37,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_1,param_2);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar1 = *(undefined8 *)(*(longlong *)(lVar2 + 0x18) + 0x128);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,
                     PTR__WDF_ADDRESS0_OWNERSHIP_QUEUE_CONTEXT_TYPE_INFO_14002d990);
  *(undefined8 *)(lVar2 + 0x10) = 0;
  *(undefined8 *)(lVar2 + 0x18) = 0;
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar1);
  return;
}



===== RootHub_EvtInterruptTxCancel @ 14000f410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_EvtInterruptTxCancel(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,
                     PTR__WDF_ROOTHUB_INTERRUPT_QUEUE_CONTEXT_TYPE_INFO_14002d9b8);
  uVar1 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
  *(undefined8 *)(lVar3 + 0x48) = 0;
  *(undefined1 *)(lVar3 + 0x40) = 1;
  KeReleaseSpinLock(lVar3 + 0x18,uVar1);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== UsbDevice_CompleteUsbDeviceStartToHub @ 14000f4d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_CompleteUsbDeviceStartToHub(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1f,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,0);
  return;
}



===== RootHub_Pdo_EvtQueryInterfaceIrpPreprocessCallback @ 14000f560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_Pdo_EvtQueryInterfaceIrpPreprocessCallback(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined2 *puVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar3 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&USB_BUS_INTERFACE_USBDI_GUID,0x10);
  if (lVar3 == 0x10) {
    puVar2 = *(undefined2 **)(lVar1 + 0x18);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    *puVar2 = *(undefined2 *)(lVar1 + 0x10);
    puVar2[1] = *(undefined2 *)(lVar1 + 0x12);
  }
  else {
    lVar3 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&GUID_HUB_PARENT_INTERFACE,0x10);
    if (lVar3 != 0x10) {
      lVar3 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&GUID_HUB_CONTROLLERSTACK_INTERFACE,0x10);
      if (lVar3 != 0x10) goto LAB_14000f653;
    }
    puVar2 = *(undefined2 **)(lVar1 + 0x18);
    *puVar2 = *(undefined2 *)(lVar1 + 0x10);
    puVar2[1] = *(undefined2 *)(lVar1 + 0x12);
  }
LAB_14000f653:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== _UcxEndpointGetStaticStreamsReferenced @ 14000f6a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
_UcxEndpointGetStaticStreamsReferenced(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if (*(longlong *)(lVar2 + 0x50) != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(lVar2 + 0x40) + 0x1e8);
    if (*(longlong *)(lVar2 + 0x50) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 0x50) + 8),param_3,0x586,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
      uVar3 = *(undefined8 *)(*(longlong *)(lVar2 + 0x50) + 8);
    }
    KeReleaseSpinLock(*(longlong *)(lVar2 + 0x40) + 0x1e8,uVar1);
  }
  return uVar3;
}



===== Controller_EvtAddress0OwnershipIoInternalDeviceControl @ 14000f780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_EvtAddress0OwnershipIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_5 == 0x491007) {
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,param_1,0,0);
    local_18 = 0;
    lStack_30 = 0;
    local_38 = 0x28;
    local_28 = 0;
    uStack_20 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_ADDRESS0_OWNERSHIP_QUEUE_CONTEXT_TYPE_INFO_14002d990);
    lVar1 = lStack_30;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x35,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,
                         (char)*(undefined8 *)(lStack_30 + 8),
                         (char)*(undefined8 *)(lStack_30 + 0x10));
    }
    uVar3 = 0;
    *(undefined8 *)(lVar2 + 0x10) = *(undefined8 *)(lVar1 + 8);
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x10);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x36,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_5);
    }
    uVar3 = 0xc0000010;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  return;
}



===== UcxEndpointStateEntryFunc_IsAbleToStart2 @ 14000f930 =====

int UcxEndpointStateEntryFunc_IsAbleToStart2(longlong param_1)

{
  longlong lVar1;
  
  if ((((*(char *)(param_1 + 0x2fe) == '\0') ||
       (lVar1 = *(longlong *)(param_1 + 0x48), *(char *)(lVar1 + 0x19c) != '\0')) ||
      (*(char *)(lVar1 + 0x19e) != '\0')) || (*(char *)(lVar1 + 0x19d) == '\0')) {
    return -0x141cff4e;
  }
  return (-(uint)(*(char *)(lVar1 + 0x1a0) != '\0') & 0xf0) + 0xebe300b2;
}



===== UcxEndpointStateEntryFunc_Starting2 @ 14000f980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_Starting2(longlong param_1)

{
  (**(code **)(param_1 + 0x70))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28),*(undefined8 *)(param_1 + 8));
  return 0xebe300c2;
}



===== UsbDevice_CompleteUsbDeviceAbortToHub @ 14000f9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_CompleteUsbDeviceAbortToHub(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x21,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,0);
  return;
}



===== UcxEndpointStateEntryFunc_Aborting2 @ 14000fa40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_Aborting2(longlong param_1)

{
  (**(code **)(param_1 + 0x78))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28),*(undefined8 *)(param_1 + 8));
  return 0;
}



===== _UcxIoDeviceControl @ 14000fa70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
_UcxIoDeviceControl(undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4,
                   ulonglong param_5,int param_6)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint local_18 [4];
  
  local_18[0] = 0;
  if ((param_6 == 0x220400) || (param_6 == 0x220404)) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,0);
  }
  else {
    if ((param_6 == 0x220408) || (param_6 == 0x220424)) {
      uVar3 = USBPORTStyle_LegacyGetUnicodeName(param_2,param_3,param_4,param_4,param_6,local_18);
      iVar1 = (int)uVar3;
    }
    else {
      if (param_6 != 0x220438) {
        if (param_6 == 0x220474) {
          lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_2,
                             PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
          Controller_HandleStartTrackingForTimeSync(*(longlong *)(lVar2 + 8),param_3);
          return 1;
        }
        if (param_6 == 0x220478) {
          lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_2,
                             PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
          Controller_HandleGetFrameNumberAndQpcForTimeSync(*(longlong *)(lVar2 + 8),param_3);
          return 1;
        }
        if (param_6 == 0x22047c) {
          lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_2,
                             PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
          Controller_HandleStopTrackingForTimeSync(*(longlong *)(lVar2 + 8),param_3);
          return 1;
        }
        return 0;
      }
      iVar1 = USBPORTStyle_UsbFdoUserIoctl(param_2,param_3,param_4,param_5,local_18);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_3,iVar1,local_18[0]);
  }
  return 1;
}



===== UsbDevice_CompleteUsbDevicePurgeToHub @ 14000fc30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_CompleteUsbDevicePurgeToHub(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x20,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,0);
  return;
}



===== StaticStreams_EvtDestroyCallback @ 14000fcc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StaticStreams_EvtDestroyCallback(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8);
  uVar4 = 0;
  if (*(int *)(lVar2 + 4) != 0) {
    do {
      *(undefined8 *)(*(longlong *)(lVar2 + 0x20) + 0x30 + uVar4 * 0x48) = 0;
      lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x10 + uVar4 * 0x48);
      if (lVar1 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,lVar1,_UcxStaticStreamsSetStreamInfo,0x105,
                   "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\streams.c");
        *(undefined8 *)(*(longlong *)(lVar2 + 0x20) + 0x10 + uVar4 * 0x48) = 0;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar2 + 4));
  }
  return;
}



===== UsbDevice_EvtDestroyCallback @ 14000fd80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_EvtDestroyCallback(undefined8 param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  if (*(longlong *)(lVar7 + 0x10) != 0) {
    lVar2 = *(longlong *)(lVar7 + 0x18);
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x1e8);
    plVar1 = (longlong *)(lVar7 + 0x40);
    lVar3 = *plVar1;
    if ((lVar3 != 0) || (*(longlong *)(lVar7 + 0x48) != 0)) {
      if ((*(longlong **)(lVar3 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(lVar7 + 0x48), (longlong *)*plVar4 != plVar1)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      *(undefined8 *)(lVar7 + 0x48) = 0;
      *plVar1 = 0;
      *(int *)(lVar2 + 0x1f0) = *(int *)(lVar2 + 0x1f0) + -1;
    }
    KeReleaseSpinLock(lVar2 + 0x1e8,CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar6));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20),_UcxUsbDeviceCreate,0x191,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
  }
  return;
}



===== UcxEndpointStateEntryFunc_SetStaleAndDeletePreviousStale @ 14000fe80 =====

undefined8 UcxEndpointStateEntryFunc_SetStaleAndDeletePreviousStale(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  undefined1 uVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  
  bVar7 = false;
  if (*(char *)(*(longlong *)(param_1 + 0x48) + 0x1a1) != '\0') {
    lVar1 = *(longlong *)(param_1 + 0x48) + 0x80;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
    plVar2 = (longlong *)(param_1 + 0x110);
    lVar4 = *plVar2;
    if ((*(longlong **)(lVar4 + 8) != plVar2) ||
       (plVar5 = *(longlong **)(param_1 + 0x118), (longlong *)*plVar5 != plVar2))
    goto LAB_14001003d;
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    *(undefined8 *)(param_1 + 0x118) = 0;
    *plVar2 = 0;
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar8));
  }
  uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + 0x1e8);
  plVar11 = (longlong *)(*(longlong *)(param_1 + 0x48) + 0x60);
  plVar2 = (longlong *)*plVar11;
  plVar5 = (longlong *)*plVar2;
  while( true ) {
    plVar9 = plVar5;
    if (plVar11 == plVar2) break;
    if (*(char *)((longlong)plVar2 + 0x236) == *(char *)(param_1 + 0x2f6)) {
      lVar1 = *plVar2;
      bVar7 = true;
      if ((*(longlong **)(lVar1 + 8) != plVar2) ||
         (plVar5 = (longlong *)plVar2[1], (longlong *)*plVar5 != plVar2)) goto LAB_14001003d;
      *plVar5 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar5;
      plVar2[1] = 0;
      *plVar2 = 0;
      break;
    }
    plVar5 = (longlong *)*plVar9;
    plVar2 = plVar9;
  }
  piVar3 = (int *)(*(longlong *)(param_1 + 0x40) + 500);
  *piVar3 = *piVar3 + -1;
  plVar5 = (longlong *)(param_1 + 0xc0);
  plVar11 = (longlong *)*plVar5;
  if (((longlong *)plVar11[1] != plVar5) ||
     (plVar9 = *(longlong **)(param_1 + 200), (longlong *)*plVar9 != plVar5)) {
LAB_14001003d:
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    uVar10 = (*pcVar6)();
    return uVar10;
  }
  *plVar9 = (longlong)plVar11;
  plVar11[1] = (longlong)plVar9;
  lVar1 = *(longlong *)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (*(char *)(lVar1 + 0x1a2) == '\0') {
    plVar11 = *(longlong **)(lVar1 + 0x68);
    if (*plVar11 != lVar1 + 0x60) goto LAB_14001003d;
    *plVar5 = lVar1 + 0x60;
    uVar10 = 0xebe300c2;
    *(longlong **)(param_1 + 200) = plVar11;
    *plVar11 = (longlong)plVar5;
    *(longlong **)(lVar1 + 0x68) = plVar5;
  }
  else {
    uVar10 = 0xebe30172;
  }
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + 0x1e8,
                    CONCAT71((int7)((ulonglong)plVar11 >> 8),uVar8));
  if (bVar7) {
    StateMachineEngine_EventAdd(plVar2 + 0xc,0xebe30061);
  }
  return uVar10;
}



===== Controller_StopIdleSynchronous @ 140010050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Controller_StopIdleSynchronous(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar2 = *(longlong *)(lVar2 + 0x18);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x10),1,0,CONCAT44(uVar3,0xdc8),
                     "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\controller.c");
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x60,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)lVar2);
    }
  }
  else {
    *param_2 = 1;
  }
  return iVar1;
}



===== _UcxStaticStreamsCreate @ 140010130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int _UcxStaticStreamsCreate
              (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4,
              longlong *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong local_res18 [2];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_64;
  code *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong local_48;
  undefined *local_40;
  
  local_78 = local_78 & 0xffffffff00000000;
  local_6c = 0;
  local_64 = 0;
  *param_5 = 0;
  local_40 = PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8;
  local_70 = 0x38;
  local_58 = 1;
  local_54 = 1;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_48 = (ulonglong)*(uint *)(*param_3 + 0x18) * 0x48 + 0x28;
  local_50 = *(undefined8 *)(*param_3 + 0x10);
  local_60 = StaticStreams_EvtDestroyCallback;
  puVar6 = param_4;
  if ((param_4 != (undefined8 *)0x0) && (*(int *)(param_4 + 3) == 2)) {
    local_a8 = *param_4;
    uStack_a0 = param_4[1];
    puVar6 = &local_a8;
    local_58 = 2;
    local_98 = param_4[2];
    local_88 = param_4[4];
    uStack_80 = param_4[5];
    uStack_90 = CONCAT44((int)((ulonglong)param_4[3] >> 0x20),1);
    local_78 = param_4[6];
  }
  local_res18[0] = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_70,local_res18);
  if ((iVar2 < 0) ||
     ((puVar6 != (undefined8 *)0x0 &&
      (iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res18[0],puVar6,0),
      iVar2 < 0)))) {
    if (local_res18[0] != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    lVar5 = 0;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x11,
                          &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)iVar2);
      }
      goto LAB_140010348;
    }
  }
  else {
    lVar5 = local_res18[0];
  }
  puVar3 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,lVar5,PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x12,
                        &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)param_2,(char)lVar5,
                        (char)puVar3);
  }
  *puVar3 = 0x6d747353;
  uVar1 = *(undefined4 *)(*param_3 + 0x18);
  *(undefined4 **)(puVar3 + 8) = puVar3 + 10;
  *(undefined8 *)(puVar3 + 4) = uVar4;
  puVar3[1] = uVar1;
  *(longlong *)(puVar3 + 2) = lVar5;
  *(longlong *)(puVar3 + 6) = *param_3;
  *param_5 = lVar5;
  *(longlong *)(*param_3 + 8) = lVar5;
  *param_3 = 0;
LAB_140010348:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x13,
                      &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== Controller_ForwardProgressWorkItemFlush @ 140010420 =====

void Controller_ForwardProgressWorkItemFlush(longlong param_1)

{
  undefined1 uVar1;
  
  if ((*(uint *)(param_1 + 0x68) & 1) != 0) {
    KeWaitForSingleObject(param_1 + 0x50,0,0,0,0);
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
    KeReleaseSpinLock(param_1 + 0x40,uVar1);
  }
  return;
}



===== UcxEndpointStateEntryFunc_ResettingEndpoint2 @ 140010480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_ResettingEndpoint2(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(param_1 + 0x80))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28),*(undefined8 *)(param_1 + 8),
             uVar1);
  return 0;
}



===== _UcxEndpointSetWdfIoQueue @ 1400104c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxEndpointSetWdfIoQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if (*(longlong *)(lVar1 + 0x10) == 0) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,param_3,_UcxEndpointSetWdfIoQueue,0x3b9,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
    *(undefined8 *)(lVar1 + 0x10) = param_3;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x12,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar1,
                        (char)*(longlong *)(lVar1 + 0x10),(char)param_3);
  }
  return;
}



===== UsbDevice_RemoteWakeNotificationRequest @ 140010590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_RemoteWakeNotificationRequest(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  
  uVar7 = (undefined1)param_3;
  if (param_2 == 0) {
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3b,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7);
    }
    goto LAB_140010791;
  }
  lVar1 = param_1 + 0x168;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  lVar2 = *(longlong *)(param_2 + 8);
  uVar8 = (undefined1)param_1;
  if (*(longlong *)(param_1 + 0x160) == 0) {
    if (lVar2 == 0) {
      plVar5 = (longlong *)(param_1 + 0x170);
LAB_1400106b1:
      if (*plVar5 == 0) {
        iVar4 = (**(code **)(WdfFunctions_01015 + 0xc48))
                          (WdfDriverGlobals,param_3,UsbDevice_EvtRemoteWakeRequestCancel);
        if (-1 < iVar4) {
          *plVar5 = param_3;
          plVar5[1] = param_2;
          KeReleaseSpinLock(lVar1,uVar3);
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3f,
                              &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar8,uVar7,
                              (char)iVar4);
        }
      }
      else {
        iVar4 = -0x3ffffe7c;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3e,
                              &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)*plVar5,uVar7,
                              uVar8);
        }
      }
    }
    else {
      iVar4 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x3c;
LAB_14001064d:
        iVar4 = -0x3ffffff3;
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                           &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7,uVar8);
      }
    }
  }
  else {
    if (lVar2 != 0) {
      plVar5 = (longlong *)(lVar2 + 0x18);
      goto LAB_1400106b1;
    }
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x3d;
      goto LAB_14001064d;
    }
  }
  KeReleaseSpinLock(lVar1,uVar3);
  if (-1 < iVar4) {
    return;
  }
LAB_140010791:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,iVar4);
  return;
}



===== RootHub_USBDInterfaceV1Unregister @ 140010800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_USBDInterfaceV1Unregister(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int *piVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  
  lVar4 = *(longlong *)(param_1 + 0x20);
  lVar2 = lVar4 + 0x1c8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
  plVar1 = (longlong *)(param_1 + 0x38);
  lVar5 = *plVar1;
  if ((*(longlong **)(lVar5 + 8) == plVar1) &&
     (plVar6 = *(longlong **)(param_1 + 0x40), (longlong *)*plVar6 == plVar1)) {
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    *(undefined8 *)(param_1 + 0x40) = 0;
    *plVar1 = 0;
    KeReleaseSpinLock(lVar2,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar8));
    LOCK();
    piVar3 = (int *)(*(longlong *)(lVar4 + 0x18) + 0x480);
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    ObfDereferenceObjectWithTag(*(undefined8 *)(param_1 + 8),RootHub_USBDInterfaceV1Unregister);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28),RootHub_USBDInterfaceV1Unregister,
               0xf09,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\roothub.c");
    return;
  }
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== UcxEndpointStateEntryFunc_Purging3 @ 140010900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_Purging3(longlong param_1)

{
  (**(code **)(param_1 + 0x68))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28),*(undefined8 *)(param_1 + 8));
  return 0;
}



===== Xrb_SelectInterfaceWithEndpointOffloadAllocate @ 140010930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140010b60) */

int Xrb_SelectInterfaceWithEndpointOffloadAllocate
              (longlong param_1,undefined8 param_2,longlong *param_3,uint param_4,
              undefined8 *param_5)

{
  byte bVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined2 uVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  ushort local_res8;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  uVar7 = (ulonglong)param_4;
  local_40 = local_40 & 0xffffffff00000000;
  local_70 = 0;
  uStack_68 = 0;
  *param_5 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uVar4 = (undefined1)param_1;
  if (*param_3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar12 = 0xd;
  }
  else {
    if (param_3[1] == 0) {
      bVar1 = *(byte *)(*param_3 + 4);
      uVar8 = (ulonglong)bVar1;
      uVar15 = (uint)bVar1;
      if (0x20 < bVar1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0xf,
                            in_stack_ffffffffffffff68,bVar1,(char)param_3,uVar4);
        return -0x3ffffff3;
      }
      if (bVar1 < param_4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_ddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return -0x3ffffff3;
      }
      local_60 = 0;
      uStack_68 = 0;
      local_70 = 0x38;
      uStack_48 = 0;
      uStack_58 = 0x100000001;
      uVar13 = ((ushort)bVar1 + (ushort)bVar1 + (ushort)bVar1) * 8;
      iVar5 = uVar13 + 0x38;
      local_40 = 0;
      local_50 = *(undefined8 *)(param_1 + 0x28);
      uVar14 = param_4 * 0x82 + 0xb0 + iVar5;
      iVar6 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,&local_70,ExDefaultNonPagedPoolType,
                         *(undefined4 *)(param_1 + 0x10));
      if (-1 < iVar6) {
        (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x1f0);
        memset((void *)0x0,0,(ulonglong)uVar14);
        puVar11 = auStackY_b8;
        uRam000000000000004c = 0x2e425258;
        uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
        uRam000000000000000c = 0xabcd0000;
        uRam0000000000000008 = 0xaabb0006;
        uRam0000000000000020 = 0;
        uRam0000000000000082 = *(undefined1 *)(*param_3 + 2);
        uRam0000000000000083 = *(undefined1 *)(*param_3 + 3);
        uRam0000000000000000 = uVar14;
        lRam0000000000000018 = param_1;
        uRam0000000000000090 = uVar15;
        if (uVar15 != 0) {
          puVar10 = (undefined4 *)0xac;
          do {
            puVar10[-1] = 0xffffffff;
            *puVar10 = 0;
            puVar10 = puVar10 + 6;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        sRam0000000000000080 = uVar13 + 0x18;
        sRam0000000000000050 = (short)uVar14 + -0x50;
        param_3[1] = 0x80;
        uRam0000000000000052 = 0x3b;
        local_res8 = (ushort)iVar5;
        puVar10 = (undefined4 *)((ulonglong)local_res8 + 0x80);
        uRam0000000000000068 = param_2;
        uRam0000000000000070 = param_4;
        puRam0000000000000078 = puVar10;
        if (param_4 != 0) {
          do {
            *puVar10 = 0x82;
            puVar10 = (undefined4 *)((longlong)puVar10 + 0x82);
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if (*(char *)(param_1 + 0x8b) != '\0') {
          uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
          puVar11 = auStackY_b8;
          plVar9 = *(longlong **)(param_1 + 0x80);
          if (*plVar9 != param_1 + 0x78) {
            plVar9 = (longlong *)0x3;
            pcVar3 = (code *)swi(0x29);
            uVar4 = (*pcVar3)();
            puVar11 = auStackY_b0;
          }
          lRam0000000000000030 = param_1 + 0x78;
          plRam0000000000000038 = plVar9;
          *plVar9 = 0x30;
          *(undefined8 *)(param_1 + 0x80) = 0x30;
          *(undefined8 *)(puVar11 + -8) = 0x140010d39;
          KeReleaseSpinLock(param_1 + 0x70,uVar4);
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(undefined8 *)(puVar11 + 0x28) = 0;
          *(undefined **)(puVar11 + 0x20) = &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids;
          *(undefined8 *)(puVar11 + -8) = 0x140010d89;
          WPP_RECORDER_SF_q(uVar2,5,9,0x14,*(undefined8 *)(puVar11 + 0x20),puVar11[0x28]);
        }
        *param_5 = 0x50;
        return iVar6;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar6;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x11,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,uVar4,(char)iVar6);
      return iVar6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar12 = 0xe;
  }
  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar12,
                     &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_3,uVar4);
  return -0x3ffffff3;
}



===== UsbDevice_TreePurgeCallback @ 140010dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_TreePurgeCallback(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  *(undefined2 *)(param_1 + 0x19f) = 0;
  puVar4 = *(undefined8 **)(param_1 + 0x50);
  while( true ) {
    if ((undefined8 *)(param_1 + 0x50) == puVar4) {
      return;
    }
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,puVar4[-0x17],UsbDevice_TreePurgeCallback,0xbe8,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
    plVar2 = *(longlong **)(param_2 + 8);
    plVar1 = puVar4 + 6;
    if (*plVar2 != param_2) break;
    *plVar1 = param_2;
    puVar4[7] = plVar2;
    *plVar2 = (longlong)plVar1;
    *(longlong **)(param_2 + 8) = plVar1;
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    puVar4 = (undefined8 *)*puVar4;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== UcxEndpointStateEntryFunc_CompletingEndpointResetIrp1 @ 140010e70 =====

undefined8 UcxEndpointStateEntryFunc_CompletingEndpointResetIrp1(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  IofCompleteRequest(uVar1,0);
  return 0xebe300c2;
}



===== UsbDevice_ForwardEndpointsConfigureToHcd @ 140010eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_ForwardEndpointsConfigureToHcd(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x19,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(param_1 + 0x90))(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x28),uVar1);
  return;
}



===== Usbd_IsDeviceAtleastHighSpeed @ 140010f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool Usbd_IsDeviceAtleastHighSpeed(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  
  bVar1 = false;
  if (param_1 != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    bVar1 = 1 < *(uint *)(lVar2 + 0x10c);
  }
  return bVar1;
}



===== UcxEndpointStateEntryFunc_NeedToSetStale @ 140010f90 =====

int UcxEndpointStateEntryFunc_NeedToSetStale(longlong param_1)

{
  return (-(uint)(*(char *)(param_1 + 0x2fc) != '\0') & 0xf0) + 0xebe300b2;
}



===== Endpoint_FindAndCompleteAbortUrbIfNotAlreadyCancelled @ 140010fac =====

void Endpoint_FindAndCompleteAbortUrbIfNotAlreadyCancelled(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  bool bVar5;
  
  lVar4 = IoCsqRemoveIrp(*(longlong *)(param_1 + 0x40) + 0x1a0);
  if (lVar4 != 0) {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    lVar2 = *(longlong *)(lVar1 + 8);
    bVar5 = lVar2 != *(longlong *)(lVar1 + 0x30);
    if (!bVar5) {
      *(undefined4 *)(lVar2 + -0x44) = 0xabcd0000;
    }
    *(undefined4 *)(lVar2 + 4) = 0;
    *(undefined4 *)(lVar4 + 0x30) = 0;
    *(undefined8 *)(lVar4 + 0x38) = 0;
    if (bVar5) {
      uVar3 = KfRaiseIrql(CONCAT71((int7)((ulonglong)lVar1 >> 8),2));
      IofCompleteRequest(lVar4,0);
      KeLowerIrql(uVar3);
    }
    else {
      IofCompleteRequest(lVar4);
    }
  }
  return;
}



===== UsbDevice_ForwardResetToHcd @ 140011060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_ForwardResetToHcd(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1b,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(param_1 + 0xa8))(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x28),uVar1);
  return;
}



===== UsbDevice_CompleteEndpointsConfigure @ 1400110f0 =====

void UsbDevice_CompleteEndpointsConfigure(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  *(undefined4 *)(lVar1 + 0x30) = 0;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x23,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)lVar1);
  }
  IofCompleteRequest(lVar1,0);
  return;
}



===== Endpoint_OkToResetController @ 140011170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_OkToResetController(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  lVar2 = param_1 + 0x300;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
  *(undefined1 *)(param_1 + 0x308) = uVar5;
  if (*(longlong *)(param_1 + 0x318) != 0) {
    LOCK();
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x318) + 0x68);
    lVar3 = *plVar1;
    *plVar1 = 0;
    UNLOCK();
    if (lVar3 != 0) {
      lVar3 = *(longlong *)(param_1 + 0x318);
      lVar4 = *(longlong *)(param_1 + 800);
      *(undefined8 *)(param_1 + 0x318) = 0;
      *(undefined8 *)(param_1 + 800) = 0;
      *(undefined1 *)(param_1 + 0x328) = 1;
      *(undefined8 *)(lVar3 + 0x78) = 0;
      *(undefined4 *)(lVar4 + 0x70) = 1;
      KeReleaseSpinLock(lVar2,*(undefined1 *)(param_1 + 0x308));
      if (lVar4 + 0x50 == *(longlong *)(*(longlong *)(lVar3 + 0xb8) + 0x30)) {
        *(undefined4 *)(lVar4 + 0xc) = 0xabcd0000;
      }
      *(undefined4 *)(lVar4 + 0x54) = 0;
      *(undefined4 *)(lVar3 + 0x30) = 0;
      *(undefined8 *)(lVar3 + 0x38) = 0;
      IofCompleteRequest(lVar3,0);
      (**(code **)(WdfFunctions_01015 + 0x9f8))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x310),0xffffffffee1e5d00);
      return;
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x310));
    *(undefined8 *)(param_1 + 0x310) = 0;
    uVar5 = *(undefined1 *)(param_1 + 0x308);
  }
  KeReleaseSpinLock(lVar2,uVar5);
  Controller_PendingPrepareForResetOperationComplete(*(longlong *)(param_1 + 0x40));
  return;
}



===== UcxEndpointEventHandler_CompletePendingTreePurge @ 1400112d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointEventHandler_CompletePendingTreePurge(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x490);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x488),0);
    *(undefined8 *)(lVar3 + 0x488) = 0;
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x140));
  }
  return 0;
}



===== UsbDevice_UnregisterCompositeDevice @ 140011348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_UnregisterCompositeDevice(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  lVar1 = *(longlong *)(param_1 + 0x160);
  uVar3 = 0;
  if (lVar1 == 0) {
    KeReleaseSpinLock();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x3a,
                       &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids);
    }
    uVar3 = 0xc0000184;
  }
  else {
    *(undefined8 *)(param_1 + 0x160) = 0;
    *(undefined8 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x150) = 0;
    KeReleaseSpinLock(param_1 + 0x168,uVar2);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  return;
}



===== UsbDevice_EvtRemoteWakeRequestCancel @ 140011460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_EvtRemoteWakeRequestCancel(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  lStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,local_28,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0
                    );
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x168);
  lVar1 = *(longlong *)(lStack_30 + 8);
  if (lVar1 == 0) {
    *(undefined8 *)(lVar3 + 0x170) = 0;
    *(undefined8 *)(lVar3 + 0x178) = 0;
  }
  else if (*(longlong *)(lVar3 + 0x160) != 0) {
    *(undefined8 *)(lVar1 + 0x18) = 0;
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  KeReleaseSpinLock(lVar3 + 0x168,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== UsbDevice_CompleteResetIrp @ 140011590 =====

void UsbDevice_CompleteResetIrp(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x18) + 0x1e8);
  if ((*(char *)(param_1 + 0x1a0) == '\x01') && (*(char *)(param_1 + 0x19f) == '\0')) {
    *(undefined1 *)(param_1 + 0x19f) = 1;
  }
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x18) + 0x1e8,uVar2);
  lVar1 = *(longlong *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  *(undefined4 *)(lVar1 + 0x30) = 0;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x24,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)lVar1);
  }
  IofCompleteRequest(lVar1,0);
  return;
}



===== UsbDevice_DisconnectCallback @ 140011670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_DisconnectCallback(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  *(undefined1 *)(param_1 + 0x19c) = 1;
  puVar4 = *(undefined8 **)(param_1 + 0x50);
  while( true ) {
    if ((undefined8 *)(param_1 + 0x50) == puVar4) {
      return;
    }
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,puVar4[-0x17],UsbDevice_DisconnectCallback,0x496,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
    lVar2 = *param_2;
    plVar1 = puVar4 + 2;
    if (*(longlong **)(lVar2 + 8) != param_2) break;
    *plVar1 = lVar2;
    puVar4[3] = param_2;
    *(longlong **)(lVar2 + 8) = plVar1;
    *param_2 = (longlong)plVar1;
    puVar4 = (undefined8 *)*puVar4;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== UsbDevice_CompleteEnable @ 140011720 =====

void UsbDevice_CompleteEnable(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  *(uint *)(lVar1 + 0x30) = -(uint)(*(char *)(param_1 + 0x19e) != '\0') & 0xc000000e;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x22,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)lVar1);
  }
  IofCompleteRequest(lVar1,0);
  return;
}



===== Controller_ResumeIdle @ 1400117b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_ResumeIdle(undefined8 param_1,char *param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  if (*param_2 != '\0') {
    (**(code **)(WdfFunctions_01015 + 0xdb8))
              (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 0x18) + 0x10),0,0xdf7,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\controller.c");
    *param_2 = '\0';
  }
  return;
}



===== RootHub_Pdo_GetLocationString @ 140011830 =====

undefined8 RootHub_Pdo_GetLocationString(undefined8 param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  *param_2 = 0;
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,0x18,0x44434855);
  if (pwVar1 == (wchar_t *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x4d,
                       &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    builtin_wcsncpy(pwVar1,L"USBROOT(0)",0xb);
    *param_2 = pwVar1;
  }
  return uVar2;
}



===== McTemplateK0_EtwWriteTransfer @ 1400118d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== Controller_AreSuperspeedStreamsSupported @ 140011920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool Controller_AreSuperspeedStreamsSupported(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  short local_res10 [4];
  undefined4 local_res18 [2];
  
  bVar3 = false;
  local_res18[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x38,
                      &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_1);
  }
  local_res10[0] = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar2 = *(longlong *)(lVar2 + 0x18);
  if (*(code **)(lVar2 + 0x38) == (code *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x39,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  else {
    iVar1 = (**(code **)(lVar2 + 0x38))
                      (*(undefined8 *)(lVar2 + 0x28),&GUID_USB_CAPABILITY_STATIC_STREAMS,2,
                       local_res10,local_res18);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3a,
                           &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)lVar2,(char)iVar1)
        ;
      }
    }
    else {
      bVar3 = local_res10[0] != 0;
    }
  }
  return bVar3;
}



===== UsbDevice_EvtTreePurgeIoInternalDeviceControl @ 140011a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_EvtTreePurgeIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined1 auStackY_b8 [32];
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_48 = 0;
  lStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  uVar1 = *(undefined8 *)(lStack_60 + 0x10);
  puVar4 = PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
  lVar3 = *(longlong *)(lVar3 + 0x18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Lqqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x42,
               &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_5,(char)param_2,
               (char)*(undefined8 *)(lVar3 + 0x28),(char)uVar1);
  }
  if (param_5 == 0x491053) {
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,param_1,0,0);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(lVar3 + 0x130));
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Lqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
      (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,param_1);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x44,
                        &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  return;
}



===== UcxEndpointStateEntryFunc_SettingEnabledFlag1 @ 140011ca0 =====

undefined8 UcxEndpointStateEntryFunc_SettingEnabledFlag1(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x2fe) = 1;
  return 0xebe300c2;
}



===== _UcxEndpointInitSetEventCallbacks @ 140011cc0 =====

void _UcxEndpointInitSetEventCallbacks(undefined8 param_1,longlong param_2,int *param_3)

{
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_3 + 8);
  *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)(param_3 + 2);
  *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_3 + 4);
  *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)(param_3 + 6);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_3 + 10);
  *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_3 + 0xc);
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_3 + 0xe);
  *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(param_3 + 0x10);
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_3 + 0x12);
  if (*param_3 == 0x60) {
    *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_3 + 0x14);
    *(undefined8 *)(param_2 + 0x88) = *(undefined8 *)(param_3 + 0x16);
  }
  return;
}



===== Controller_EvtDefaultIoDeviceControl @ 140011d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_EvtDefaultIoDeviceControl
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,int param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
  lVar2 = *(longlong *)(lVar2 + 8);
  if (param_5 == 0x220464) {
    Controller_GetTransportCharacteristics(lVar2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x22046c) {
    Controller_NotifyOnTransportCharacteristicsChange(lVar2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x220474) {
    Controller_HandleStartTrackingForTimeSync(lVar2,param_2);
  }
  else if (param_5 == 0x220478) {
    Controller_HandleGetFrameNumberAndQpcForTimeSync(lVar2,param_2);
  }
  else if (param_5 == 0x22047c) {
    Controller_HandleStopTrackingForTimeSync(lVar2,param_2);
  }
  else if (param_5 == 0x220480) {
    UsbDevice_GetUsbDeviceCharacteristics(lVar2,param_2,param_3,param_4);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x61,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  return;
}



===== UcxEndpointStateEntryFunc_ClearingEnabledFlag @ 140011ea0 =====

undefined8 UcxEndpointStateEntryFunc_ClearingEnabledFlag(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x2fe) = 0;
  return 0xebe300c2;
}



===== UsbDevice_SetPdoInformation @ 140011ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_SetPdoInformation(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  *(undefined8 *)(lVar1 + 0x148) = param_3;
  return;
}



===== ControllerResetStateEntryFunc_StopBlockingResetComplete1 @ 140011f00 =====

undefined8 ControllerResetStateEntryFunc_StopBlockingResetComplete1(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x475) = 0;
  return 0xebe40042;
}



===== UsbDevice_ForwardDisableToHcd @ 140011f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_ForwardDisableToHcd(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1d,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(param_1 + 0xa0))(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x28),uVar1);
  return;
}



===== _UcxDefaultEndpointInitSetEventCallbacks @ 140011fb0 =====

void _UcxDefaultEndpointInitSetEventCallbacks(undefined8 param_1,longlong param_2,longlong param_3)

{
  *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_3 + 0x28);
  *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)(param_3 + 8);
  *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_3 + 0x10);
  *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)(param_3 + 0x18);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_3 + 0x20);
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_3 + 0x30);
  return;
}



===== Etw_GetMsFeatureUrbDispatch @ 140011fe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_GetMsFeatureUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined7 in_register_00000009;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar2 = -0x3ffffddb;
    }
    else {
      iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
    }
    uVar1 = *(undefined8 *)(param_2 + 8);
    uVar4 = WdfDriverGlobals;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar5 = &local_38;
      if (iVar2 < 0) {
        puVar5 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar4,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR,puVar5,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
                 (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
    }
  }
  return;
}



===== WPP_RECORDER_SF_dq @ 1400120e4 =====

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



===== _guard_check_icall @ 140012210 =====

void _guard_check_icall(void)

{
  return;
}



===== WPP_RECORDER_SF_qqq @ 14001221c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== Controller_CsqReleaseAbortPipeIrpLock @ 140012370 =====

void Controller_CsqReleaseAbortPipeIrpLock(longlong param_1)

{
  KeReleaseSpinLock(param_1 + 0x40);
  return;
}



===== Controller_CsqAcquireAbortPipeIrpLock @ 140012390 =====

void Controller_CsqAcquireAbortPipeIrpLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
  *param_2 = uVar1;
  return;
}



===== UsbDevice_RegisterCompositeDevice @ 1400123b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_RegisterCompositeDevice
               (longlong param_1,short *param_2,longlong *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  void *local_res10;
  undefined8 in_stack_ffffffffffffff78;
  longlong local_68 [8];
  
  local_res10 = (void *)0x0;
  local_68[0] = 0;
  local_68[7] = local_68[7] & 0xffffffff00000000;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  if ((param_2 == (short *)0x0) || (param_3 == (longlong *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x34,
                       &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids);
    }
LAB_1400126de:
    iVar2 = -0x3ffffff3;
  }
  else {
    if (param_2[1] != 0x18) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x18,0x35,
                            in_stack_ffffffffffffff78,(char)param_2,0x18,(char)param_2[1]);
      }
      goto LAB_1400126de;
    }
    if (*param_2 != 0x100) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_1400126de;
    }
    uVar1 = *(uint *)(param_2 + 10);
    if (0xfe < uVar1 - 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x37,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
      }
      goto LAB_1400126de;
    }
    local_68[7] = 0;
    local_68[3] = 0;
    local_68[4] = 0x100000001;
    local_68[5] = *(undefined8 *)(param_1 + 0x10);
    local_68[6] = 0;
    local_68[2] = 0;
    local_68[1] = 0x38;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,local_68 + 1,ExDefaultNonPagedPoolType,0x44434855,
                       (ulonglong)uVar1 * 0x28,local_68,&local_res10);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x38,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids);
      }
    }
    else {
      memset(local_res10,0,(ulonglong)uVar1 * 0x28);
      KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
      lVar5 = local_68[0];
      if (*(longlong *)(param_1 + 0x160) == 0) {
        *(void **)(param_1 + 0x158) = local_res10;
        local_68[0] = 0;
        *(longlong *)(param_1 + 0x160) = lVar5;
        *(uint *)(param_1 + 0x150) = uVar1;
        KeReleaseSpinLock();
        uVar4 = 0;
        if (uVar1 != 0) {
          lVar5 = 0;
          lVar3 = 0;
          do {
            *(uint *)(lVar3 + (longlong)local_res10) = uVar4;
            uVar4 = uVar4 + 1;
            *(undefined4 *)(lVar3 + 4 + (longlong)local_res10) = 0x636e7546;
            *(longlong *)(lVar3 + 8 + (longlong)local_res10) = param_1;
            *param_3 = lVar5 + (longlong)local_res10;
            param_3 = param_3 + 1;
            lVar5 = lVar5 + 0x28;
            lVar3 = lVar3 + 0x28;
          } while (uVar4 < uVar1);
        }
        iVar2 = 0;
        goto LAB_140012706;
      }
      KeReleaseSpinLock();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x39,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x160));
      }
      iVar2 = -0x3ffffe7c;
    }
  }
  if (local_68[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140012706:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_4,iVar2);
  return;
}



===== RootHub_Pdo_EvtDeviceControlIrpPreprocessCallback @ 140012750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RootHub_Pdo_EvtDeviceControlIrpPreprocessCallback(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar3 = -0x3fffff45;
  (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar4 = *(longlong *)(lVar4 + 0x10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  iVar1 = *(int *)(lVar2 + 0x18);
  if (iVar1 == 0x220464) {
LAB_140012829:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar5 = *(undefined8 *)(lVar4 + 0x148);
  }
  else {
    if (iVar1 != 0x220468) {
      if (iVar1 != 0x22046c) {
        if (iVar1 == 0x220470) goto LAB_14001289d;
        if ((((iVar1 != 0x220474) && (iVar1 != 0x220478)) && (iVar1 != 0x22047c)) &&
           (iVar1 != 0x220480)) goto LAB_140012869;
      }
      goto LAB_140012829;
    }
LAB_14001289d:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar5 = *(undefined8 *)(lVar4 + 0x4e8);
  }
  iVar3 = (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,uVar5,2);
  if (-1 < iVar3) {
    return iVar3;
  }
LAB_140012869:
  *(int *)(param_2 + 0x30) = iVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== UcxEndpointStateEntryFunc_EnablingStaticStreams @ 1400128c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_EnablingStaticStreams(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(param_1 + 0x98))
            (*(undefined8 *)(param_1 + 8),*(undefined8 *)(*(longlong *)(param_1 + 0x50) + 8),uVar1);
  return 0;
}



===== Etw_UcxDeviceCreate @ 1400128fc =====

void Etw_UcxDeviceCreate(undefined8 param_1,longlong param_2)

{
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    McTemplateK0pppqqQ6_EtwWriteTransfer
              (param_1,&UCX_ETW_EVENT_UCX_DEVICE_CREATE,0,
               *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x28),
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10),
               (char)*(undefined4 *)(param_2 + 0x10c),(char)*(undefined4 *)(param_2 + 0x11c),
               param_2 + 0x124);
  }
  return;
}



===== RootHub_Pdo_EvtD0Exit @ 140012960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RootHub_Pdo_EvtD0Exit(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  
  RootHub_LogDiagnosticsDuringD0Exit(param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar2 = *(longlong *)(lVar5 + 0x10);
  lVar6 = *(longlong *)(*(longlong *)(lVar5 + 8) + 200);
  StateMachineEngine_EventAdd((undefined8 *)(lVar2 + 0x1f8),0xebe40070);
  KeWaitForSingleObject(lVar2 + 0x3a0,0,0,0,0);
  iVar1 = *(int *)(*(longlong *)(lVar5 + 8) + 0x18c);
  *(undefined1 *)(lVar2 + 0x474) = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x18);
  if (*(char *)(lVar6 + 0x40) == '\0') {
    *(short *)(lVar6 + 0x20) = *(short *)(lVar6 + 0x20) + 1;
  }
  bVar7 = false;
  if (iVar1 == 0) {
    bVar7 = *(short *)(lVar6 + 0x20) != *(short *)(lVar6 + 0x22);
    *(undefined1 *)(lVar6 + 0x41) = 1;
  }
  lVar6 = lVar6 + 0x18;
  KeReleaseSpinLock(lVar6,uVar4);
  if (bVar7) {
    Etw_UcxRootHubInitiatingWake(lVar6,*(longlong *)(lVar5 + 8));
    (**(code **)(WdfFunctions_01015 + 0x2b0))(WdfDriverGlobals,param_1,0);
  }
  puVar3 = *(undefined **)(*(longlong *)(lVar2 + 0x158) + 400);
  if (puVar3 != (undefined *)0x0) {
    SleepstudyHelper_ComponentInactive(puVar3);
  }
  return 0;
}



===== RootHub_Pdo_EvtSetPowerIrpPreprocessCallback @ 140012ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_Pdo_EvtSetPowerIrpPreprocessCallback(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar3 + 8);
  if (((*(int *)(lVar1 + 0x10) == 0) && (*(char *)(lVar1 + 1) == '\x02')) &&
     ((*(int *)(lVar1 + 0x18) != 1 || ((*(uint *)(lVar1 + 8) & 0xf0000) != 0x10000)))) {
    uVar2 = *(uint *)(lVar1 + 8) >> 8 & 0xf;
    if (uVar2 == 1) {
      *(undefined4 *)(lVar3 + 0x18c) = 0;
    }
    else {
      *(uint *)(lVar3 + 0x188) = uVar2;
      *(undefined4 *)(lVar3 + 0x18c) = *(undefined4 *)(lVar1 + 0x20);
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== UsbDevice_Create @ 140012b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UsbDevice_Create(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStackY_158 [32];
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  longlong local_108;
  undefined4 local_100;
  uint local_fc;
  undefined8 local_f8;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_114 = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar8 = *(longlong *)(lVar6 + 0x18);
  uVar9 = *(undefined8 *)(lVar8 + 0x28);
  memset(&local_118,0,0xd0);
  local_c0 = *(undefined8 *)(param_2 + 0x10);
  local_118 = 0x74696544;
  local_110 = param_1;
  memset(&local_100,0,0x40);
  local_fc = *(uint *)(param_2 + 4);
  local_100 = 0x40;
  uVar7 = Feature_UISCSF__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    local_c8 = *(undefined4 *)(param_2 + 0x18);
  }
  if ((*(uint *)(lVar6 + 4) & 2) == 0) {
    local_f0 = *(undefined4 *)(lVar6 + 0x118);
    uStack_e8 = *(undefined4 *)(lVar6 + 0x120);
    uStack_e4 = *(undefined4 *)(lVar6 + 0x124);
    local_e0 = *(undefined8 *)(lVar6 + 0x128);
    uStack_d8 = *(undefined8 *)(lVar6 + 0x130);
    local_d0 = *(undefined4 *)(lVar6 + 0x138);
    uStack_ec = *(uint *)(lVar6 + 0x11c) + 1;
    if (6 < uStack_ec) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,10,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uStack_ec);
      }
      iVar5 = -0x3ffffff3;
      goto LAB_140012ed2;
    }
    (&uStack_e4)[*(uint *)(lVar6 + 0x11c)] = *(undefined4 *)(param_2 + 8);
    if (local_fc < 2) {
      if (*(int *)(lVar6 + 0x10c) == 2) {
        uStack_e8 = *(undefined4 *)(lVar6 + 0x11c);
        local_f8 = param_1;
      }
      else {
        uStack_e8 = *(undefined4 *)(lVar6 + 0x120);
        local_f8 = *(undefined8 *)(lVar6 + 0x110);
      }
    }
  }
  else {
    uStack_e4 = *(undefined4 *)(param_2 + 8);
    local_f0 = 0x24;
    uStack_ec = 1;
  }
  LOCK();
  *(int *)(lVar8 + 0x3ec) = *(int *)(lVar8 + 0x3ec) + 1;
  UNLOCK();
  if (*(char *)(lVar8 + 0x3f0) == '\0') {
    iVar5 = (**(code **)(lVar8 + 0x50))(uVar9,&local_100,&local_118);
    iVar3 = *(int *)(lVar8 + 1000);
    LOCK();
    piVar1 = (int *)(lVar8 + 0x3ec);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      lVar6 = lVar8 + 0x3e0;
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6);
      if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar3 == *(int *)(lVar8 + 1000))) {
        *(undefined1 *)(lVar8 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar6,uVar4);
        StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar6,uVar4);
      }
    }
    if (-1 < iVar5) {
      *param_3 = local_108;
      uVar9 = WdfDriverGlobals;
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_108,
                         PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
      Etw_UcxDeviceCreate(uVar9,lVar8);
      return iVar5;
    }
  }
  else {
    iVar2 = *(int *)(lVar8 + 1000);
    LOCK();
    piVar1 = (int *)(lVar8 + 0x3ec);
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      lVar6 = lVar8 + 0x3e0;
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6);
      if ((*(char *)(lVar8 + 0x3f1) == '\0') && (iVar2 == *(int *)(lVar8 + 1000))) {
        *(undefined1 *)(lVar8 + 0x3f1) = 1;
        KeReleaseSpinLock(lVar6,uVar4);
        StateMachineEngine_EventAdd((undefined8 *)(lVar8 + 0x1f8),0xebe40031);
      }
      else {
        KeReleaseSpinLock(lVar6,uVar4);
      }
    }
    iVar5 = -0x3ffffff2;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140012ed2;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xb,
                     &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids);
    iVar5 = -0x3ffffff2;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xc,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)iVar5);
  }
LAB_140012ed2:
  *param_3 = 0;
  if (local_108 != 0) {
    UsbDevice_Delete(param_1,local_108);
  }
  return iVar5;
}



===== UsbDevice_Delete @ 140012f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_Delete(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong ****pppplVar3;
  longlong ****pppplVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  longlong *****ppppplVar8;
  ulonglong uVar9;
  longlong *****ppppplVar10;
  longlong *****local_38;
  longlong *****ppppplStack_30;
  
  local_38 = (longlong *****)0x0;
  ppppplStack_30 = (longlong *****)0x0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar1 = *(longlong *)(lVar7 + 0x18);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x1c8);
  puVar2 = *(undefined8 **)(lVar7 + 0x1d0);
  while( true ) {
    if (puVar2 == (undefined8 *)(lVar7 + 0x1d0)) {
      KeReleaseSpinLock(lVar7 + 0x1c8,uVar6);
      lVar1 = lVar1 + 0x1e8;
      *(undefined1 *)(lVar7 + 0x1a2) = 1;
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      ppppplVar8 = (longlong *****)(lVar7 + 0x60);
      local_38 = (longlong *****)*ppppplVar8;
      if (local_38 == ppppplVar8) {
        ppppplStack_30 = (longlong *****)&local_38;
        ppppplVar10 = local_38;
        local_38 = (longlong *****)&local_38;
      }
      else {
        ppppplStack_30 = *(longlong ******)(lVar7 + 0x68);
        local_38[1] = (longlong ****)&local_38;
        ppppplVar10 = (longlong *****)&local_38;
        *ppppplStack_30 = (longlong ****)ppppplVar10;
        *(longlong ******)(lVar7 + 0x68) = ppppplVar8;
        *ppppplVar8 = (longlong ****)ppppplVar8;
      }
      KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)ppppplVar10 >> 8),uVar6));
      ppppplVar8 = local_38;
      while( true ) {
        ppppplVar10 = (longlong *****)*ppppplVar8;
        if (&local_38 == (longlong ******)ppppplVar8) {
          if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
            McTemplateK0pppqqQ6_EtwWriteTransfer
                      (&local_38,&UCX_ETW_EVENT_UCX_DEVICE_DELETE,0,
                       *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x28),
                       (char)*(undefined8 *)(lVar7 + 0x20),(char)*(undefined8 *)(lVar7 + 0x10),
                       (char)*(undefined4 *)(lVar7 + 0x10c),(char)*(undefined4 *)(lVar7 + 0x11c),
                       lVar7 + 0x124);
          }
          uVar9 = Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar9 != 0) {
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
            *(undefined1 *)(lVar7 + 0x1a3) = 1;
            KeReleaseSpinLock(lVar1,uVar6);
          }
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_2);
          return;
        }
        pppplVar3 = *ppppplVar8;
        if (((longlong *****)pppplVar3[1] != ppppplVar8) ||
           (pppplVar4 = ppppplVar8[1], (longlong *****)*pppplVar4 != ppppplVar8)) break;
        *pppplVar4 = (longlong ***)pppplVar3;
        pppplVar3[1] = (longlong ***)pppplVar4;
        ppppplVar8[1] = (longlong ****)0x0;
        *ppppplVar8 = (longlong ****)0x0;
        StateMachineEngine_EventAdd(ppppplVar8 + 0xc,0xebe30061);
        ppppplVar8 = ppppplVar10;
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    if ((*(char *)(lVar1 + 0x3f9) != '\0') || (*(char *)((longlong)puVar2 + 0x52) != '\0')) break;
    ObfDereferenceObjectWithTag(puVar2[-6],RootHub_USBDInterfaceV1Unregister);
    puVar2 = (undefined8 *)*puVar2;
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x144,0x804,puVar2 + -7,puVar2[-6],0);
}



===== _UcxUsbDeviceInitSetEventCallbacks @ 140013200 =====

void _UcxUsbDeviceInitSetEventCallbacks(undefined8 param_1,longlong param_2,uint *param_3)

{
  if (*param_3 < 0x70) {
    memset((void *)(param_2 + 0x60),0,0x70);
  }
  memmove((void *)(param_2 + 0x60),param_3,(ulonglong)*param_3);
  return;
}



===== Etw_UcxControllerRundown @ 140013248 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxControllerRundown(undefined8 param_1,ulonglong param_2)

{
  uint uVar1;
  wchar_t *_Dst;
  ulonglong uVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  ulonglong local_28;
  void *pvStack_20;
  
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  RtlInitUnicodeString(&local_28,0);
  (**(code **)(WdfFunctions_01015 + 0x9a8))
            (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x150),&local_28);
  pwVar3 = (wchar_t *)0x40;
  _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_28 & 0xffff) + 2,0x44434855);
  if (_Dst != (wchar_t *)0x0) {
    memmove(_Dst,pvStack_20,local_28 & 0xffff);
    pwVar3 = (wchar_t *)(local_28 >> 1 & 0x7fff);
    _Dst[(longlong)pwVar3] = L'\0';
  }
  if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
    pwVar3 = (wchar_t *)(param_2 + 0x99);
    McTemplateK0pqqqqqqqsssz_EtwWriteTransfer
              (pwVar3,&UCX_ETW_EVENT_RUNDOWN_UCX_CONTROLLER_INFORMATION,param_1,
               *(undefined8 *)(param_2 + 0x28),(char)*(undefined4 *)(param_2 + 0x78),
               (char)*(undefined4 *)(param_2 + 0x88),(char)*(undefined4 *)(param_2 + 0x8c),
               (char)*(undefined4 *)(param_2 + 0x90),(char)*(undefined4 *)(param_2 + 0x7c),
               (char)*(undefined4 *)(param_2 + 0x80),(char)*(undefined2 *)(param_2 + 0x84),
               (char *)(param_2 + 0x94),(char *)pwVar3,(char *)(param_2 + 0x9e),_Dst);
  }
  if (_Dst != (wchar_t *)0x0) {
    ExFreePoolWithTag(_Dst,0x44434855);
    pwVar3 = _Dst;
  }
  cVar6 = (char)param_2 + -8;
  lVar4 = 0x10;
  uVar2 = (ulonglong)*(byte *)(param_2 + 0x378);
  lVar5 = 0x10;
  do {
    uVar2 = (ulonglong)((int)uVar2 - 1U & 0xf);
    if ((DAT_14002f391 & 1) != 0) {
      McTemplateK0ppqq_EtwWriteTransfer
                (pwVar3,&UCX_ETW_EVENT_RUNDOWN_UCX_CONTROLLER_STATE_MACHINE_TRANSITION,param_1,
                 *(undefined8 *)(param_2 + 0x28),cVar6,
                 (char)*(undefined4 *)(param_2 + 0x2b8 + uVar2 * 8),
                 (char)*(undefined4 *)(param_2 + 700 + uVar2 * 8));
    }
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar2 = (ulonglong)*(byte *)(param_2 + 0x379);
  do {
    uVar2 = (ulonglong)((int)uVar2 - 1U & 0xf);
    if ((DAT_14002f391 & 1) != 0) {
      uVar1 = *(uint *)(param_2 + 0x338 + uVar2 * 4);
      McTemplateK0ppq_EtwWriteTransfer
                ((ulonglong)uVar1,&UCX_ETW_EVENT_RUNDOWN_UCX_CONTROLLER_STATE_MACHINE_EVENT,param_1,
                 *(undefined8 *)(param_2 + 0x28),cVar6,(char)uVar1);
    }
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  uVar2 = Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    Etw_UcxDeviceTreeRundownLegacy(param_1,param_2);
  }
  else {
    Etw_UcxDeviceTreeRundownNew(param_1,param_2);
  }
  return;
}



===== Etw_UcxDeviceTreeRundownWalkCallback @ 140013490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxDeviceTreeRundownWalkCallback(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  uVar1 = Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar1 == 0) || (*(char *)(param_1 + 0x1a3) == '\0')) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),Etw_UcxDeviceTreeRundownWalkCallback
               ,0x475,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
    *(longlong *)(*param_2 + (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 8) = param_1;
    *(int *)((longlong)param_2 + 0xc) = *(int *)((longlong)param_2 + 0xc) + 1;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    if ((*(uint *)(param_1 + 4) & 2) != 0) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,uVar4,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938)
      ;
      uVar4 = *(undefined8 *)(lVar2 + 8);
    }
    for (puVar3 = *(undefined8 **)(param_1 + 0x50); (undefined8 *)(param_1 + 0x50) != puVar3;
        puVar3 = (undefined8 *)*puVar3) {
      uVar1 = (ulonglong)*(uint *)((longlong)param_2 + 0x1c);
      lVar2 = param_2[2];
      *(uint *)((longlong)param_2 + 0x1c) = *(uint *)((longlong)param_2 + 0x1c) + 1;
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,puVar3[-0x17],Etw_UcxDeviceTreeRundownWalkCallback,0x49c,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
      *(undefined8 *)(lVar2 + uVar1 * 0x18) = uVar4;
      *(undefined8 **)(lVar2 + 8 + uVar1 * 0x18) = puVar3 + -0x18;
      if (puVar3[-0xe] != 0) {
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,*(undefined8 *)(puVar3[-0xe] + 8),
                   Etw_UcxDeviceTreeRundownWalkCallback,0x4a9,
                   "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
        *(undefined8 *)(lVar2 + 0x10 + uVar1 * 0x18) = puVar3[-0xe];
      }
    }
  }
  return;
}



===== SleepstudyHelper_ComponentInactive @ 140013614 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentInactive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14002f2c8 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14002f2c8)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14002f2c8 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14002f2c8)(param_1);
  }
  return iVar1;
}



===== Endpoint_ExposedToClient @ 1400136a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_ExposedToClient(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  *(undefined1 *)(lVar1 + 0x2fc) = 1;
  return;
}



===== ControllerResetStateEntryFunc_SignalOKForRHPdoToExitD0_3 @ 1400136e0 =====

undefined8 ControllerResetStateEntryFunc_SignalOKForRHPdoToExitD0_3(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x475) = 1;
  KeSetEvent(param_1 + 0x3a0,0,0);
  return 0xebe40042;
}



===== Endpoint_GetUsbdPipeHandle @ 140013720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong Endpoint_GetUsbdPipeHandle(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  return lVar1 + 0x10;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_GetStatus @ 140013760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_GetStatus
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte bVar8;
  uint uVar9;
  
  *(short *)(param_3 + 0x86) = *(short *)(param_3 + 0x24);
  *(undefined2 *)(param_3 + 0x82) = 0;
  uVar6 = (ulonglong)*(ushort *)(param_3 + 2);
  bVar8 = ((&DAT_14002c10d)[uVar6 * 0x18] << 5 ^ *(byte *)(param_3 + 0x80)) & 0x60 ^
          *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (&DAT_14002c10c)[uVar6 * 0x18] << 7 | bVar8 & 0x7f;
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (bVar8 ^ (&DAT_14002c10e)[uVar6 * 0x18]) & 3 ^ bVar8;
  *(byte *)(param_3 + 0x80) = bVar8 & 0xe3;
  *(undefined *)(param_3 + 0x81) = (&DAT_14002c10f)[uVar6 * 0x18];
  if (*(short *)(param_3 + 0x24) != 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb,
                       &WPP_37381017bc4f37187367ad98553ba188_Traceguids);
    }
    if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
      *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
    }
    *(undefined4 *)(param_3 + 4) = 0x80000300;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return 0xc000000d;
  }
  uVar9 = *(uint *)(param_3 + 0x20) | 3;
  if ((bVar8 & 0x80) == 0) {
    uVar9 = *(uint *)(param_3 + 0x20) & 0xfffffffe | 2;
  }
  *(uint *)(param_3 + 0x20) = uVar9;
  Etw_GetStatusUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 == 8) || (sVar2 == 9)) || (sVar2 == 10)) ||
     (((sVar2 == 0x32 || (sVar2 == 0x37)) ||
      ((sVar2 == 0x38 || ((sVar2 != 0x39 && (sVar2 != 0x3a)))))))) {
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
    bVar8 = KeGetCurrentIrql();
    if ((bVar8 < 2) &&
       (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
        (*(int *)(param_3 + 0x24) != 0)))) {
      UCX_LockBufferPagesInUrbForDMA(param_3);
    }
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar5 = IoSetCompletionRoutineEx(uVar7,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar5 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== Etw_GetStatusUrbDispatch @ 140013a04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_GetStatusUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined7 in_register_00000009;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar4 = (uint)*(ushort *)(param_2 + 2);
  uVar5 = (ulonglong)(uVar4 - 0x13);
  if (uVar4 - 0x13 != 0) {
    if (uVar4 == 0x14) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_STATUS_FROM_INTERFACE;
      uVar5 = 0;
      goto LAB_140013af0;
    }
    uVar4 = uVar4 - 0x15;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_STATUS_FROM_ENDPOINT;
      goto LAB_140013af0;
    }
    if (uVar4 == 0xc) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_STATUS_FROM_OTHER;
      goto LAB_140013af0;
    }
  }
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_STATUS_FROM_DEVICE;
LAB_140013af0:
  puVar7 = &local_38;
  if (iVar2 < 0) {
    puVar7 = (undefined8 *)0x0;
  }
  McTemplateK0pppppn_EtwWriteTransfer
            (uVar5,puVar6,puVar7,*(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
             (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
  return;
}



===== RootHub_WasResetOnResume @ 140013b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 RootHub_WasResetOnResume(undefined8 param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  LOCK();
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xb0) + 0x3bc);
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 != 0);
}



===== Controller_PrepareUsbDevicesAndEndpointsForControllerReset @ 140013b98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_PrepareUsbDevicesAndEndpointsForControllerReset(longlong param_1,undefined8 param_2)

{
  longlong ****pppplVar2;
  longlong ***ppplVar1;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong ****pppplVar6;
  int iVar7;
  undefined7 uVar8;
  bool bVar9;
  longlong ****local_28;
  longlong ****local_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_20 = (longlong ****)&local_28;
  local_28 = (longlong ****)&local_28;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1e8);
  uVar8 = (undefined7)((ulonglong)param_2 >> 8);
  UsbDevice_WalkTree(*(longlong *)(*(longlong *)(param_1 + 0x158) + 0xb8),'\x01',
                     UsbDevice_PrepareForControllerResetCallback,&local_28);
  KeReleaseSpinLock(param_1 + 0x1e8,CONCAT71(uVar8,uVar5));
  iVar7 = (int)local_18;
  *(int *)(param_1 + 0x3fc) = iVar7;
  pppplVar6 = local_28;
  pppplVar2 = (longlong ****)*local_28;
  if (&local_28 != (longlong *****)local_28) {
    do {
      ppplVar1 = *pppplVar6;
      if (((longlong ****)ppplVar1[1] != pppplVar6) ||
         (ppplVar3 = pppplVar6[1], (longlong ****)*ppplVar3 != pppplVar6)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *ppplVar3 = (longlong **)ppplVar1;
      ppplVar1[1] = (longlong **)ppplVar3;
      pppplVar6[1] = (longlong ***)0x0;
      *pppplVar6 = (longlong ***)0x0;
      StateMachineEngine_EventAdd(pppplVar6 + 8,0xebe300e1);
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,pppplVar6[-0x1b],UsbDevice_PrepareForControllerResetCallback,0xb0b
                 ,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\controller.c");
      bVar9 = &local_28 != (longlong *****)pppplVar2;
      pppplVar6 = pppplVar2;
      pppplVar2 = (longlong ****)*pppplVar2;
    } while (bVar9);
    iVar7 = (int)local_18;
  }
  if (iVar7 == 0) {
    StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40081);
  }
  return;
}



===== UsbDevice_IsDeviceDisconnected @ 140013d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 UsbDevice_IsDeviceDisconnected(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  return *(undefined1 *)(lVar1 + 0x19c);
}



===== UsbDevice_GetLastTransferTimestamp @ 140013d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UsbDevice_GetLastTransferTimestamp(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  return *(undefined8 *)(lVar1 + 0x1a8);
}



===== Ucx_FailDueToVerifierSetting @ 140013d88 =====

undefined8 Ucx_FailDueToVerifierSetting(uint param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_1 != 1) {
      g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
      return CONCAT71((int7)(0x8000 / (ulonglong)param_1 >> 8),
                      (g_RandomNumberSeed >> 0x10 & 0x7fff) < (uint)(0x8000 / (ulonglong)param_1));
    }
    uVar1 = 1;
  }
  return uVar1;
}



===== Controller_HandleGetFrameNumberAndQpcForTimeSync @ 140013dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_HandleGetFrameNumberAndQpcForTimeSync(longlong param_1,undefined8 param_2)

{
  if (*(code **)(param_1 + 0x120) == (code *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  else {
    (**(code **)(param_1 + 0x120))(*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== RootHub_WasDeviceProgrammingLostOnResume @ 140013e20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 RootHub_WasDeviceProgrammingLostOnResume(undefined8 param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  LOCK();
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xb0) + 0x3b8);
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 != 0);
}



===== Controller_PendingPrepareForResetOperationComplete @ 140013e68 =====

void Controller_PendingPrepareForResetOperationComplete(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x3fc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40081);
  }
  return;
}



===== UrbHandler_USBPORTStyle_Legacy_GetMSFeatureDescriptor @ 140013ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_GetMSFeatureDescriptor
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  char cVar2;
  short sVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  byte bVar9;
  
  *(undefined2 *)(param_3 + 0x86) = *(undefined2 *)(param_3 + 0x24);
  bVar9 = ((&DAT_14002c10d)[(ulonglong)*(ushort *)(param_3 + 2) * 0x18] << 5 ^
          *(byte *)(param_3 + 0x80)) & 0x60 ^ *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar9;
  cVar2 = (&DAT_14002c10c)[(ulonglong)*(ushort *)(param_3 + 2) * 0x18];
  *(byte *)(param_3 + 0x80) = cVar2 << 7 | bVar9 & 0x7f;
  uVar8 = *(uint *)(param_3 + 0x20) | 3;
  if ((byte)(cVar2 << 7) == 0) {
    uVar8 = *(uint *)(param_3 + 0x20) & 0xfffffffe | 2;
  }
  *(uint *)(param_3 + 0x20) = uVar8;
  Etw_GetMsFeatureUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar3 = *(short *)(param_3 + 2);
  if ((((sVar3 != 8) && (sVar3 != 9)) && (sVar3 != 10)) &&
     (((sVar3 != 0x32 && (sVar3 != 0x37)) && (sVar3 != 0x38)))) {
    if ((sVar3 == 0x39) || (sVar3 == 0x3a)) goto LAB_140013fa3;
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
  bVar9 = KeGetCurrentIrql();
  if ((bVar9 < 2) &&
     (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
      (*(int *)(param_3 + 0x24) != 0)))) {
    UCX_LockBufferPagesInUrbForDMA(param_3);
  }
LAB_140013fa3:
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar6 = IoSetCompletionRoutineEx(uVar7,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar6 < 0) {
    lVar5 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar5 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar5 + -8) = param_3;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== UsbDevice_PendEndpointsConfigureDueToControllerReset @ 140014090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PendEndpointsConfigureDueToControllerReset(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1a,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x8c8))
            (WdfDriverGlobals,uVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x138));
  return;
}



===== UcxEndpointStateEntryFunc_CompletingAbortUrbIfNotAlreadyCancelled2 @ 140014130 =====

undefined8 UcxEndpointStateEntryFunc_CompletingAbortUrbIfNotAlreadyCancelled2(longlong param_1)

{
  Endpoint_FindAndCompleteAbortUrbIfNotAlreadyCancelled(param_1);
  return 0xebe300c2;
}



===== _UcxControllerSetFailed @ 140014150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxControllerSetFailed(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  LOCK();
  bVar2 = *(int *)(lVar1 + 0x3f4) == 0;
  if (bVar2) {
    *(int *)(lVar1 + 0x3f4) = 1;
  }
  UNLOCK();
  if (bVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x28,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_2);
    }
    UsbDevice_Disconnect(*(undefined8 *)(*(longlong *)(lVar1 + 0x158) + 8),0);
    StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x1f8),0xebe40090);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x27,
                      &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_2);
  }
  return;
}



===== Endpoint_GetMaximumTransferSize @ 140014240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 Endpoint_GetMaximumTransferSize(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  return *(undefined4 *)(lVar1 + 0x24);
}



===== Endpoint_StaticStreamsEnableUrb @ 140014278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint Endpoint_StaticStreamsEnableUrb
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  undefined8 *puVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  byte bVar14;
  uint uVar15;
  undefined2 uVar16;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  lVar1 = param_3 + 0x50;
  lVar11 = *(longlong *)(param_3 + 0x18);
  cVar6 = KeGetCurrentIrql();
  if (cVar6 == '\0') {
    if (*(char *)(lVar11 + 0x88) == '\0') {
      if (*(char *)(lVar11 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x801,param_4,lVar1,*(undefined8 *)(lVar11 + 8));
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x19,
                         &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids);
      }
      goto LAB_140014731;
    }
    uVar15 = *(uint *)(param_3 + 0x70);
    uVar4 = *(uint *)(lVar11 + 0x68);
    if ((uVar4 < uVar15) || (uVar15 == 0)) {
      if (*(char *)(lVar11 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x802,uVar4,uVar15,lVar1);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1a,
                           &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar15,(char)uVar4
                          );
      }
      goto LAB_140014731;
    }
    uVar9 = Ucx_FailDueToVerifierSetting(*(uint *)(lVar11 + 0x60));
    if ((char)uVar9 == '\0') {
      LOCK();
      piVar2 = (int *)(param_1 + 0x58);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      if (iVar8 == 0) {
        uVar10 = StaticStreams_Create(param_1,(ulonglong)*(uint *)(param_3 + 0x70),local_res18);
        uVar15 = (uint)uVar10;
        if (-1 < (int)uVar15) {
          uVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,local_res18[0],
                             PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8);
          uVar7 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + 0x1e8);
          *(undefined8 *)(param_1 + 0x50) = uVar9;
          KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + 0x1e8,uVar7);
          *(undefined4 *)(param_3 + 0x54) = 0x40000000;
          lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_2,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
          uVar9 = *(undefined8 *)(*(longlong *)(lVar11 + 0x10) + 0x130);
          pbVar3 = (byte *)(*(longlong *)(param_4 + 0xb8) + 3);
          *pbVar3 = *pbVar3 | 1;
          puVar5 = *(undefined8 **)(param_4 + 0xb8);
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
          uVar12 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_2);
          iVar8 = IoSetCompletionRoutineEx(uVar12,param_4,Xrb_UrbCompletion,lVar1,1,1,1);
          if (iVar8 < 0) {
            lVar11 = *(longlong *)(param_4 + 0xb8);
            *(code **)(lVar11 + -0x10) = Xrb_UrbCompletion;
            *(longlong *)(lVar11 + -8) = lVar1;
            *(undefined1 *)(lVar11 + -0x45) = 0xe0;
          }
          (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_2,param_4,uVar9,2);
          return 0x103;
        }
        LOCK();
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
        UNLOCK();
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar16 = 0x1d;
          bVar14 = 2;
          goto LAB_1400144ee;
        }
        goto LAB_14001450e;
      }
      if (*(char *)(lVar11 + 0x8a) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x144,0x803,param_4,lVar1,*(undefined8 *)(lVar11 + 8));
      }
      LOCK();
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
      UNLOCK();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1c,
                         &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids);
      }
      uVar15 = 0xc0000184;
    }
    else {
      g_RandomNumberSeed = g_RandomNumberSeed * 0x41c64e6d + 0x3039;
      uVar15 = g_RandomNumberSeed >> 0x10 & 0x7fff | 0xc0000000;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar16 = 0x1b;
        bVar14 = 4;
LAB_1400144ee:
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar14,2,uVar16,
                          &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar15);
      }
LAB_14001450e:
      if (uVar15 == 0xc000000e) {
        uVar13 = 0xc0007000;
        goto LAB_14001473b;
      }
      if (uVar15 == 0xc000009a) {
        uVar13 = 0xc0001000;
        goto LAB_14001473b;
      }
      if (uVar15 == 0xc00000bb) {
        uVar13 = 0xc0000e00;
        goto LAB_14001473b;
      }
      if (uVar15 == 0xc0000120) {
        uVar13 = 0xc0010000;
        goto LAB_14001473b;
      }
      if (uVar15 == 0) {
        uVar13 = 0;
        goto LAB_14001473b;
      }
    }
  }
  else {
    if (*(char *)(lVar11 + 0x8a) != '\0') {
      uVar7 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x144,0x800,uVar7,param_4,*(undefined8 *)(lVar11 + 8));
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = KeGetCurrentIrql();
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x18,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,uVar7);
    }
LAB_140014731:
    uVar15 = 0xc000000d;
  }
  uVar13 = 0x80000300;
LAB_14001473b:
  if (lVar1 == *(longlong *)(*(longlong *)(param_4 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_3 + 0xc) = 0xabcd0000;
  }
  *(undefined4 *)(param_3 + 0x54) = uVar13;
  *(undefined8 *)(param_4 + 0x38) = 0;
  *(uint *)(param_4 + 0x30) = uVar15;
  IofCompleteRequest(param_4,0);
  return uVar15;
}



===== UcxEndpointStateEntryFunc_ResumeSMAndWaitForPendingOperation1 @ 140014790 =====

undefined8 UcxEndpointStateEntryFunc_ResumeSMAndWaitForPendingOperation1(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x2a3) = 0;
  return 0;
}



===== UcxEndpointEventHandler_OkToResetControllerAndPauseSM @ 1400147b0 =====

undefined8 UcxEndpointEventHandler_OkToResetControllerAndPauseSM(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x2a3) = 1;
  Endpoint_OkToResetController(param_1);
  return 0xebe00020;
}



===== Controller_GetInfo @ 1400147e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_GetInfo(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar3 = *(longlong *)(lVar3 + 0x18);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined4 *)param_2 = *(undefined4 *)(lVar3 + 0x78);
  iVar1 = *(int *)(lVar3 + 0x78);
  if (iVar1 == 1) {
    uVar2 = *(undefined8 *)(lVar3 + 0x84);
    param_2[1] = *(undefined8 *)(lVar3 + 0x7c);
    param_2[2] = uVar2;
    param_2[3] = *(undefined8 *)(lVar3 + 0x8c);
  }
  else if (iVar1 == 2) {
    param_2[1] = *(undefined8 *)(lVar3 + 0x94);
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar3 + 0x9c);
    *(undefined2 *)((longlong)param_2 + 0x14) = *(undefined2 *)(lVar3 + 0xa0);
    *(undefined1 *)((longlong)param_2 + 0x16) = *(undefined1 *)(lVar3 + 0xa2);
  }
  else if (iVar1 == 3) {
    param_2[1] = lVar3 + 0x498;
    param_2[2] = lVar3 + 0x4a8;
    param_2[3] = lVar3 + 0x4b8;
  }
  return;
}



===== WPP_RECORDER_SF_Lq @ 1400148a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,param_4,&param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,param_4,&param_6,4,
                  &param_7,8,0);
  return;
}



===== UsbDevice_SetFunctionData @ 140014978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_SetFunctionData(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  uVar1 = *(undefined8 *)(param_2 + 0x10);
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10) = uVar1;
  KeReleaseSpinLock(param_1 + 0x168,CONCAT71((int7)((ulonglong)uVar1 >> 8),uVar2));
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,0);
  return;
}



===== Ucx_DbgBreak @ 1400149f8 =====

void Ucx_DbgBreak(undefined8 param_1)

{
  code *pcVar1;
  char cVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  cVar2 = KdRefreshDebuggerNotPresent();
  if (cVar2 == '\0') {
    DbgPrint("Breaking due to: %s\n",param_1);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  return;
}



===== Usbd_BusEnumLogEntry @ 140014a60 =====

undefined8 Usbd_BusEnumLogEntry(void)

{
  return 0;
}



===== __report_gsfailure @ 140014a80 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140014a8d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140014a8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DriverEntry @ 140014aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStackY_2f8 [32];
  longlong local_2b8 [3];
  ushort local_2a0 [4];
  undefined1 *local_298;
  undefined8 local_290;
  ulonglong local_288;
  undefined8 local_280;
  code *local_278;
  undefined8 local_270;
  ulonglong local_268 [6];
  undefined *local_238;
  undefined4 local_228;
  uint local_224;
  uint local_220;
  undefined1 local_108 [208];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_2a0[0] = 0;
  local_2a0[1] = 200;
  local_2a0[2] = 0;
  local_2a0[3] = 0;
  local_268[0] = (ulonglong)(uint)local_268[0];
  uVar9 = 0;
  local_298 = local_108;
  local_288 = (ulonglong)(uint)local_288;
  local_2b8[1] = 0;
  local_2b8[2] = 0;
  local_290 = 0;
  local_2b8[0] = 0;
  g_RandomNumberSeed = (undefined4)_DAT_fffff78000000320;
  memset(&local_224,0,0x110);
  local_228 = 0x114;
  iVar1 = RtlGetVersion(&local_228);
  if ((-1 < iVar1) && ((6 < local_224 || ((local_224 == 6 && (1 < local_220)))))) {
    ExDefaultNonPagedPoolType = 0x200;
  }
  InitializeTelemetryAssertsKMByDriverObject(param_1);
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_14002f348 = &WPP_ThisDir_CTLGUID_UCX;
  DAT_14002f350 = 0;
  _DAT_14002f360 = 0;
  _DAT_14002f368 = 1;
  _DAT_14002f380 = 0;
  _DAT_14002f388 = 0;
  WppLoadTracingSupport();
  _DAT_14002f360 = 0;
  WppInitKm(param_1,param_2);
  local_288 = 0x20;
  local_268[2] = 0;
  local_270 = 1;
  local_278 = Ucx_EvtDriverUnload;
  local_238 = PTR__WDF_WDFDRIVER_UCX_CONTEXT_TYPE_INFO_14002d960;
  local_268[1] = 0;
  local_280 = 0;
  local_268[4] = 0;
  local_268[5] = 0;
  local_268[0] = 0x38;
  local_268[3] = 0x100000001;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,local_268);
  uVar6 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 10;
LAB_140014c6c:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar7,
                        &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,(char)uVar2);
    }
  }
  else {
    g_WdfDriverUcxContext =
         (undefined4 *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,local_290,PTR__WDF_WDFDRIVER_UCX_CONTEXT_TYPE_INFO_14002d960);
    *g_WdfDriverUcxContext = 0x78557244;
    puVar3 = g_WdfDriverUcxContext + 4;
    *(undefined4 **)(g_WdfDriverUcxContext + 6) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    KeInitializeSpinLock(g_WdfDriverUcxContext + 8);
    g_WdfDriverUcxContext[10] = 0;
    local_2b8[0] = (**(code **)(WdfFunctions_01015 + 200))
                             (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
    if (local_2b8[0] == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xb,
                         &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
      }
      uVar6 = 0xc000009a;
    }
    else {
      do {
        uVar6 = RtlUnicodeStringPrintf(local_2a0,L"%s%d",L"\\Device\\UCX",uVar9);
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
        uVar2 = (uint)uVar6;
        uVar6 = uVar6 & 0xffffffff;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0xc;
LAB_140015094:
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,uVar7,
                              &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,(char)uVar2);
          }
          break;
        }
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_2b8[0],local_2a0);
        uVar6 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0xd;
            goto LAB_140015094;
          }
          break;
        }
        uVar2 = (**(code **)(WdfFunctions_01015 + 600))
                          (WdfDriverGlobals,local_2b8,0,g_WdfDriverUcxContext + 2);
        uVar6 = (ulonglong)uVar2;
        if (uVar2 != 0xc0000035) {
          if (-1 < (int)uVar2) {
            (**(code **)(WdfFunctions_01015 + 0xd8))
                      (WdfDriverGlobals,*(undefined8 *)(g_WdfDriverUcxContext + 2));
            uVar2 = WdfRegisterClassLibrary(&WdfClassLibraryInfo,param_2,local_2a0);
            uVar6 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1400150ec;
              uVar7 = 0xf;
              goto LAB_140014c6c;
            }
            RtlInitUnicodeString(local_2b8 + 1,L"IoTryQueueWorkItem");
            g_IoTryQueueWorkItem = MmGetSystemRoutineAddress(local_2b8 + 1);
            RtlInitUnicodeString(local_2b8 + 1,L"IoGetActivityIdIrp");
            g_IoGetActivityIdIrp = MmGetSystemRoutineAddress(local_2b8 + 1);
            RtlInitUnicodeString(local_2b8 + 1,L"IoSetActivityIdIrp");
            MmGetSystemRoutineAddress(local_2b8 + 1);
            RtlInitUnicodeString(local_2b8 + 1,L"IoFreeActivityIdIrp");
            plVar4 = local_2b8 + 1;
            MmGetSystemRoutineAddress();
            uVar2 = Registry_InitializeAllow64KLowOrFullSpeedControlTransfersFlag();
            uVar6 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((uVar2 != 0xc0000034) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                plVar4 = *(longlong **)(WPP_GLOBAL_Control + 0x40);
                WPP_RECORDER_SF_D(plVar4,2,8,0x12,&WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,
                                  (char)uVar2);
              }
              uVar6 = 0;
            }
            else if (g_Allow64KLowOrFullSpeedControlTransfersFlag == '\0') {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar7 = 0x11;
                goto LAB_140014f80;
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0x10;
LAB_140014f80:
              plVar4 = *(longlong **)(WPP_GLOBAL_Control + 0x40);
              WPP_RECORDER_SF_(plVar4,4,8,uVar7,&WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
            }
            McGenEventRegister_EtwRegister();
            iVar1 = SleepstudyHelper_Initialize(plVar4,param_1);
            if (iVar1 < 0) {
              *(undefined1 *)(g_WdfDriverUcxContext + 0xb) = 0;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x13,
                                  &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,(char)iVar1);
              }
            }
            else {
              *(undefined1 *)(g_WdfDriverUcxContext + 0xb) = 1;
            }
            EtwSetInformation(MS_UCX_ETW_PROVIDER_Context,2,
                              &`EnableManifestedProviderForMicrosoftTelemetry'::__l2::Traits,0x16);
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1400150e8;
            uVar7 = 0x14;
            bVar5 = 4;
            goto LAB_1400150c9;
          }
          break;
        }
      } while (uVar8 < 100);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0xe;
        bVar5 = 2;
LAB_1400150c9:
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,8,uVar7,
                          &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,(char)uVar6);
      }
LAB_1400150e8:
      if (-1 < (int)uVar6) {
        return uVar6;
      }
    }
  }
LAB_1400150ec:
  if (local_2b8[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
    local_2b8[0] = 0;
  }
  if ((g_WdfDriverUcxContext != (undefined4 *)0x0) &&
     (*(longlong *)(g_WdfDriverUcxContext + 2) != 0)) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(g_WdfDriverUcxContext + 2) = 0;
  }
  WppCleanupKm(param_1);
  wil_UninitializeFeatureStaging();
  return uVar6;
}



===== McGenEventRegister_EtwRegister @ 140015194 =====

void McGenEventRegister_EtwRegister(void)

{
  longlong *in_R9;
  
  if (*in_R9 == 0) {
    EtwRegister(&MS_UCX_ETW_PROVIDER,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1400151c8 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (MS_UCX_ETW_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    MS_UCX_ETW_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== RtlUnicodeStringPrintf @ 1400151fc =====

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



===== Ucx_ClassBindClient @ 1400152a0 =====

undefined8 Ucx_ClassBindClient(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1b,
                     &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
  }
  if (*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x1c,
                       &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
    }
    uVar1 = 0xc000000d;
  }
  else {
    **(undefined8 **)(param_1 + 0x30) = 0;
    uVar1 = Ucx_VerifyClientVersionAndFunctionCount(param_1);
    if (-1 < (int)uVar1) {
      memmove(*(void **)(param_1 + 0x20),&PTR__UcxIoDeviceControl_14002c038,
              (ulonglong)*(uint *)(param_1 + 0x28) << 3);
      puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x10,0x44434855);
      if (puVar2 == (undefined4 *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x1d,
                           &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
        }
        uVar1 = 0xc000009a;
      }
      else {
        *puVar2 = 0x10;
        *(undefined8 *)(puVar2 + 2) = param_2;
        **(undefined8 **)(param_1 + 0x30) = puVar2;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



===== Ucx_ClassDeinitialize @ 1400153f0 =====

void Ucx_ClassDeinitialize(void)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x17,
                     &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
  }
  return;
}



===== Ucx_ClassInitialize @ 140015440 =====

undefined8 Ucx_ClassInitialize(void)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x16,
                     &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
  }
  return 0;
}



===== Ucx_ClassUnbindClient @ 1400154a0 =====

void Ucx_ClassUnbindClient(longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong **)(param_1 + 0x30) != (longlong *)0x0) &&
     (lVar1 = **(longlong **)(param_1 + 0x30), lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,0x44434855);
    **(undefined8 **)(param_1 + 0x30) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1e,
                     &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids);
  }
  return;
}



===== Ucx_EvtDriverUnload @ 140015530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Ucx_EvtDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x15,
                      &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,(char)param_1);
  }
  if (*(longlong *)(g_WdfDriverUcxContext + 8) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(g_WdfDriverUcxContext + 8) = 0;
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  if (*(char *)(g_WdfDriverUcxContext + 0x2c) != '\0') {
    SleepstudyHelper_Uninitialize();
  }
  UninitializeTelemetryAssertsKM();
  McGenEventUnregister_EtwUnregister();
  wil_UninitializeFeatureStaging();
  return;
}



===== Ucx_VerifyClientVersionAndFunctionCount @ 140015610 =====

undefined8 Ucx_VerifyClientVersionAndFunctionCount(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 in_stack_ffffffffffffffd8;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x10);
  if (uVar4 == DAT_14002c004) {
    uVar4 = *(uint *)(param_1 + 0x14);
    if ((uVar4 == 1) || (uVar4 == 2)) {
      iVar1 = 0x16;
    }
    else if (uVar4 == 3) {
      iVar1 = 0x17;
    }
    else {
      if ((((uVar4 != 4) && (uVar4 != 5)) && (uVar4 != 6)) && (uVar4 != 7)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        uVar2 = 0x19;
        uVar3 = DAT_14002c008;
        goto LAB_140015642;
      }
      iVar1 = 0x18;
    }
    if (*(int *)(param_1 + 0x28) == iVar1) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar2 = 0x18;
    uVar3 = DAT_14002c004;
LAB_140015642:
    WPP_RECORDER_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar4,
                       (ulonglong)DAT_14002c004,uVar2,in_stack_ffffffffffffffd8,(char)uVar3,
                       (char)uVar4);
  }
  return 0xc000000d;
}



===== WPP_RECORDER_SF_ @ 14001570c =====

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



===== WPP_RECORDER_SF_LL @ 1400157e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_LLL @ 1400158b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,0x1a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,0x1a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1400159a0 =====

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



===== WPP_RECORDER_SF_s @ 140015a9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,0x1f,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,2,8,&WPP_5462ae9ba75837019a984c679ee8eb0e_Traceguids,0x1f,
                  in_stack_00000030,lVar2,0);
  return;
}



===== WppClassicProviderCallback @ 140015bc0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140015c1c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14002b0d7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140015c44 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140015da0 =====

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



===== Feature_EUSB2__private_IsEnabledDeviceUsageNoInline @ 140015e24 =====

ulonglong Feature_EUSB2__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_EUSB2__private_featureState;
  if ((Feature_EUSB2__private_featureState & 0x10) == 0) {
    uVar1 = Feature_EUSB2__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_EUSB2__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_EUSB2__private_IsEnabledFallback @ 140015e5c =====

void Feature_EUSB2__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_EUSB2__private_descriptor);
  return;
}



===== Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline @ 140015e78 =====

ulonglong Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SPR_HardenInClient__private_featureState;
  if ((Feature_SPR_HardenInClient__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SPR_HardenInClient__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SPR_HardenInClient__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SPR_HardenInClient__private_IsEnabledFallback @ 140015eb0 =====

void Feature_SPR_HardenInClient__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SPR_HardenInClient__private_descriptor);
  return;
}



===== RootHub_AddEndpoint @ 140015ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RootHub_AddEndpoint(undefined8 param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 local_res10;
  int local_res18;
  longlong local_res20;
  undefined1 uVar9;
  undefined4 local_1b0;
  ulonglong local_1ac;
  undefined8 uStack_1a4;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined8 local_190;
  undefined8 local_188;
  undefined *local_180;
  undefined4 *local_178;
  undefined8 local_170;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  code *local_118;
  undefined4 local_f8;
  undefined4 local_e8;
  int local_e4;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined1 local_58;
  
  local_1ac = local_1ac & 0xffffffff00000000;
  uStack_150 = 0;
  uStack_14c = 0;
  local_res10 = 0;
  local_170 = 0;
  uStack_168 = 0;
  uStack_164 = 0;
  local_160 = 0;
  uStack_15c = 0;
  uStack_158 = 0;
  uStack_154 = 0;
  local_res18 = param_3;
  memset(&local_e8,0,0xa8);
  lVar7 = 0;
  local_res20 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  memset(&local_148,0,0x60);
  local_148 = 0x60;
  local_140 = 2;
  if (param_3 == 2) {
    local_144 = 2;
    local_f8 = *(undefined4 *)(lVar2 + 0x14);
    local_118 = RootHub_EvtControlTxHandler;
    local_180 = PTR__WDF_ROOTHUB_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14002d910;
  }
  else {
    local_118 = RootHub_EvtInterruptTxHandler;
    local_144 = 1;
    local_180 = PTR__WDF_ROOTHUB_INTERRUPT_QUEUE_CONTEXT_TYPE_INFO_14002d9b8;
  }
  local_194 = 1;
  local_1b0 = 0x38;
  local_188 = 0;
  local_19c = 0;
  local_1ac = 0;
  uStack_1a4 = 0;
  local_198 = *(undefined4 *)(lVar3 + 0x4c8);
  local_190 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),&local_148,&local_1b0,
                     &local_res10);
  uVar8 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400162b1;
    uVar6 = 0x1e;
  }
  else {
    uStack_164 = 0;
    local_160 = 0;
    uStack_15c = 0;
    uStack_158 = 0;
    uStack_154 = 0;
    uStack_150 = 0;
    uStack_14c = 0;
    local_170 = 0x100000028;
    uStack_168 = 1;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0xc30))(WdfDriverGlobals,local_res10,&local_170);
    uVar8 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      if (param_3 == 2) {
        puVar4 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res10,
                            PTR__WDF_ROOTHUB_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14002d910);
        *puVar4 = 0x75514352;
        *(undefined8 *)(puVar4 + 2) = param_2;
      }
      else {
        puVar4 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res10,
                            PTR__WDF_ROOTHUB_INTERRUPT_QUEUE_CONTEXT_TYPE_INFO_14002d9b8);
        *puVar4 = 0x75514952;
        *(undefined8 *)(puVar4 + 2) = local_res10;
        *(undefined8 *)(puVar4 + 4) = param_2;
        KeInitializeSpinLock(puVar4 + 6);
        puVar4[8] = 1;
        *(undefined2 *)(puVar4 + 0x10) = 0;
        KeInitializeEvent(puVar4 + 10,0,1);
        *(undefined4 **)(lVar2 + 200) = puVar4;
      }
      local_e8 = 0x74697045;
      local_58 = 0;
      uVar9 = (undefined1)param_2;
      local_e4 = param_3;
      local_e0 = param_2;
      if (param_3 == 2) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x20,
                            &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar9);
        }
        local_d8 = 1;
      }
      else {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x21,
                            &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar9);
        }
        local_d8 = 4;
      }
      local_178 = &local_e8;
      uVar5 = _UcxEndpointCreate(0,param_2,(longlong *)&local_178,(undefined8 *)0x0,&local_res20);
      lVar7 = local_res20;
      uVar8 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        _UcxEndpointSetWdfIoQueue(0,local_res20,local_res10);
        if (local_res18 == 2) {
          *(undefined8 *)(lVar2 + 0x170) = local_res10;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar8;
          }
          uVar6 = 0x23;
        }
        else {
          *(longlong *)(lVar2 + 0xc0) = lVar7;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar8;
          }
          uVar6 = 0x24;
        }
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,uVar6,
                           &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar9,(char)lVar7);
        return uVar8;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x22,
                          &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar5);
      }
      lVar7 = local_res20;
      goto LAB_1400162b1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400162b1;
    uVar6 = 0x1f;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar6,
                    &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar1);
LAB_1400162b1:
  if (lVar7 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar7);
  }
  return uVar8;
}



===== RootHub_AddUsbDeviceContext @ 140016380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RootHub_AddUsbDeviceContext(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 *local_res18;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  local_res18 = (undefined4 *)0x0;
  local_18 = PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
  local_38 = 0;
  uStack_40 = 0;
  local_48 = 0x38;
  local_28 = 0;
  uStack_20 = 0;
  uStack_30 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,&local_48,&local_res18)
  ;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x1c,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)iVar1);
    }
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870);
    *local_res18 = 0x69766544;
    *(undefined8 *)(local_res18 + 4) = param_2;
    *(undefined8 *)(local_res18 + 6) = uVar2;
    local_res18[1] = 3;
    local_res18[0x43] = 3;
    puVar3 = local_res18 + 0x14;
    *(undefined4 **)(local_res18 + 0x16) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    puVar3 = local_res18 + 0x18;
    *(undefined4 **)(local_res18 + 0x1a) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    puVar3 = local_res18 + 0xc;
    *(undefined4 **)(local_res18 + 0xe) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    *(undefined8 *)(local_res18 + 0x12) = 0;
    *(undefined8 *)(local_res18 + 0x10) = 0;
    puVar3 = local_res18 + 0x74;
    *(undefined4 **)(local_res18 + 0x76) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    puVar3 = local_res18 + 0x1c;
    *(undefined4 **)(local_res18 + 0x1e) = puVar3;
    *(undefined4 **)puVar3 = puVar3;
    KeInitializeSpinLock(local_res18 + 0x72);
    KeInitializeSpinLock(local_res18 + 0x20);
    *(undefined1 *)(local_res18 + 0x67) = 0;
    *(undefined1 *)((longlong)local_res18 + 0x19e) = 0;
    *(undefined1 *)((longlong)local_res18 + 0x19f) = 1;
    *(undefined1 *)(local_res18 + 0x68) = 1;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938)
    ;
    *(undefined4 **)(lVar4 + 0xb8) = local_res18;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x1d,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_2,
                         (char)local_res18);
    }
  }
  return iVar1;
}



===== RootHub_CompleteAsyncReset @ 1400165dc =====

void RootHub_CompleteAsyncReset(longlong param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint *puVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x168);
  lVar4 = *(longlong *)(param_1 + 0xb0);
  *(undefined8 *)(param_1 + 0x168) = 0;
  puVar5 = *(uint **)(*(longlong *)(lVar3 + 0xb8) + 8);
  *puVar5 = 0;
  LOCK();
  piVar1 = (int *)(lVar4 + 0x3b8);
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  if (iVar2 != 0) {
    *puVar5 = *puVar5 | 1;
  }
  *(undefined4 *)(lVar4 + 0x3bc) = 0;
  *(undefined4 *)(lVar3 + 0x30) = param_2;
  *(undefined8 *)(lVar3 + 0x38) = 0;
  IofCompleteRequest(lVar3,0);
  return;
}



===== RootHub_Evt20USBDIQueryInterfaceRequest @ 140016650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
RootHub_Evt20USBDIQueryInterfaceRequest
          (undefined8 param_1,undefined8 param_2,ushort *param_3,longlong param_4)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined *in_stack_ffffffffffffffc8;
  undefined1 uVar8;
  
  uVar5 = 0;
  uVar6 = 0;
  if (param_4 == 0) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
    param_4 = *(longlong *)(*(longlong *)(lVar3 + 8) + 8);
  }
  uVar1 = *param_3;
  uVar2 = param_3[1];
  if (uVar1 < 0x40) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffffc8 = &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids;
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x5b,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x40,(char)uVar1);
    }
    uVar4 = 0xc0000023;
    goto LAB_14001684d;
  }
  *(longlong *)(param_3 + 4) = param_4;
  *(code **)(param_3 + 8) = _guard_check_icall;
  uVar5 = 0x40;
  *(code **)(param_3 + 0xc) = _guard_check_icall;
  *(code **)(param_3 + 0x10) = Usbd_BusGetUSBDIVersion;
  *(code **)(param_3 + 0x14) = Usbd_BusQueryBusTime;
  *(code **)(param_3 + 0x18) = Usbd_BusSubmitIsoOutUrb;
  *(code **)(param_3 + 0x1c) = Usbd_BusQueryBusInformation;
  uVar6 = 0;
  if (uVar2 == 0) {
LAB_1400167c0:
    if (1 < uVar2) {
      if (uVar1 < 0x50) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0x5d;
          uVar8 = 0x50;
          goto LAB_140016781;
        }
        goto LAB_1400167a3;
      }
      uVar5 = 0x50;
      *(code **)(param_3 + 0x24) = Usbd_BusEnumLogEntry;
      uVar6 = 2;
    }
    if (2 < uVar2) {
      if (uVar1 < 0x60) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0x5e;
          uVar8 = 0x60;
          goto LAB_140016781;
        }
        goto LAB_1400167a3;
      }
      uVar5 = 0x60;
      *(code **)(param_3 + 0x28) = Usbd_BusQueryBusTimeEx;
      uVar6 = 3;
      *(code **)(param_3 + 0x2c) = Usbd_QueryControllerType;
    }
    uVar4 = 0;
  }
  else {
    if (0x47 < uVar1) {
      uVar5 = 0x48;
      *(code **)(param_3 + 0x20) = Usbd_IsDeviceAtleastHighSpeed;
      uVar6 = 1;
      goto LAB_1400167c0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0x5c;
      uVar8 = 0x48;
LAB_140016781:
      in_stack_ffffffffffffffc8 = &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids;
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar7,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar8,(char)uVar1);
    }
LAB_1400167a3:
    uVar4 = 0x80000005;
  }
LAB_14001684d:
  *param_3 = uVar5;
  param_3[1] = uVar6;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar6,(ulonglong)uVar5
                        ,0x5f,in_stack_ffffffffffffffc8,(char)uVar5,(char)uVar6,(char)uVar4);
  }
  return uVar4;
}



===== RootHub_EvtCleanupCallback @ 1400168b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_EvtCleanupCallback(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = WdfDriverGlobals;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar1 = *(longlong *)(lVar3 + 0xb0);
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    McTemplateK0ppz_EtwWriteTransfer
              (uVar4,&UCX_ETW_EVENT_UCX_ROOTHUB_DELETE,0,*(undefined8 *)(lVar1 + 0x28),
               (char)*(undefined8 *)(lVar3 + 8),(wchar_t *)0x0);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x1e8);
  *(undefined8 *)(lVar1 + 0x158) = 0;
  *(int *)(lVar1 + 0x1f0) = *(int *)(lVar1 + 0x1f0) + -1;
  KeReleaseSpinLock(lVar1 + 0x1e8,uVar2);
  return;
}



===== RootHub_EvtHubControllerStackQueryInterfaceRequest @ 140016960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RootHub_EvtHubControllerStackQueryInterfaceRequest
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar1 = *(ushort *)((longlong)param_3 + 2);
  if (999 < uVar1) {
    *(code **)(param_3 + 4) = _guard_check_icall;
    *(code **)(param_3 + 6) = _guard_check_icall;
    *(code **)(param_3 + 0xe) = UsbDevice_Create;
    *(code **)(param_3 + 0x10) = UsbDevice_Delete;
    *(code **)(param_3 + 0x12) = UsbDevice_Disconnect;
    *(code **)(param_3 + 0x14) = UsbDevice_SetPdoInformation;
    *(code **)(param_3 + 0x32) = UsbDevice_IsDeviceDisconnected;
    *(code **)(param_3 + 0x3c) = UsbDevice_GetLastTransferTimestamp;
    *(code **)(param_3 + 0x16) = DefaultEndpoint_Create;
    *(code **)(param_3 + 0x1a) = Endpoint_Create;
    *(code **)(param_3 + 0x1c) = Endpoint_Delete;
    *(code **)(param_3 + 0x1e) = Endpoint_ExposedToClient;
    *(code **)(param_3 + 0x20) = Endpoint_GetUsbdPipeHandle;
    *(code **)(param_3 + 0x22) = Endpoint_GetMaximumTransferSize;
    *(code **)(param_3 + 0x18) = Controller_Address0OwnershipRelease;
    *(code **)(param_3 + 0x26) = Controller_ForwardProgressWorkItemAllocateFromHub;
    *(code **)(param_3 + 0x28) = Controller_ForwardProgressWorkItemDelete;
    *(code **)(param_3 + 0x2a) = Controller_ForwardProgressWorkItemEnqueue;
    *(code **)(param_3 + 0x2c) = Controller_ForwardProgressWorkItemFlush;
    *(code **)(param_3 + 0x2e) = Endpoint_ClearTTBufferComplete;
    *(code **)(param_3 + 0x34) = Controller_AreSuperspeedStreamsSupported;
    *(code **)(param_3 + 0x36) = Controller_StopIdleSynchronous;
    *(code **)(param_3 + 0x38) = Controller_ResumeIdle;
    *(code **)(param_3 + 0x3a) = Controller_GetInfo;
    *param_3 = 0x3e800f8;
    *(undefined8 *)(param_3 + 2) = param_1;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_3 + 8),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    *(undefined8 *)(lVar2 + 0x1b0) = *(undefined8 *)(param_3 + 10);
    *(undefined8 *)(lVar2 + 0x1b8) = *(undefined8 *)(param_3 + 0xc);
    *(undefined8 *)(lVar2 + 0x1c0) = *(undefined8 *)(param_3 + 0x30);
  }
  if (1999 < uVar1) {
    *param_3 = 0x7d00100;
    *(code **)(param_3 + 0x3e) = Endpoint_SetPriority;
  }
  uVar3 = Feature_EUSB2__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) && (2999 < uVar1)) {
    *param_3 = 0xbb80108;
    *(code **)(param_3 + 0x40) = Endpoint_Create_V2;
  }
  return 0;
}



===== RootHub_EvtHubParentQueryInterfaceRequest @ 140016b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RootHub_EvtHubParentQueryInterfaceRequest(undefined8 param_1,undefined8 param_2,short *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar1 = *(longlong *)(lVar3 + 0x10);
  uVar2 = *(undefined8 *)(*(longlong *)(lVar3 + 8) + 8);
  if (*param_3 == 0x90) {
    if (param_3[1] == 0x3f5) {
      memset(param_3,0,0x90);
      param_3[0] = 0x90;
      param_3[1] = 0x3f5;
      *(code **)(param_3 + 8) = _guard_check_icall;
      *(code **)(param_3 + 0xc) = _guard_check_icall;
      *(undefined8 *)(param_3 + 4) = uVar2;
      *(undefined1 *)(param_3 + 0x1a) = 1;
      *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(lVar1 + 0x88);
      *(undefined4 *)(param_3 + 0x36) = *(undefined4 *)(lVar1 + 0x8c);
      *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(lVar1 + 0x90);
      *(code **)(param_3 + 0x1c) = RootHub_WasResetOnResume;
      *(code **)(param_3 + 0x20) = RootHub_WasDeviceProgrammingLostOnResume;
      *(code **)(param_3 + 0x30) = RootHub_GetHubSymbolicLinkName;
      uVar4 = 0;
      param_3[0x24] = 0;
      param_3[0x25] = 0;
      *(undefined8 *)(param_3 + 0x14) = uVar2;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x4c,
                           &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0xf5,(char)param_3[1]);
      }
      uVar4 = 0xc00000bb;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x4b,
                         &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x90,(char)*param_3);
    }
    uVar4 = 0xc0000023;
  }
  return uVar4;
}



===== RootHub_EvtIoDeviceControl @ 140016d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_EvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,10,
                      &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,param_5);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  return;
}



===== RootHub_GetHubSymbolicLinkName @ 140016d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_GetHubSymbolicLinkName(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  RtlInitUnicodeString(param_2,0);
  if (*(longlong *)(lVar1 + 0x180) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,*(longlong *)(lVar1 + 0x180),param_2)
    ;
  }
  return;
}



===== RootHub_LogDiagnosticsDuringD0Exit @ 140016e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_LogDiagnosticsDuringD0Exit(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar2 = *(longlong *)(lVar4 + 0x10);
  uVar1 = *(uint *)(*(longlong *)(lVar4 + 8) + 0x18c);
  uVar5 = WdfDriverGlobals;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xc20))();
  if (uVar1 != uVar3) {
    if (*(int *)(lVar2 + 0x78) == 1) {
      uVar6 = *(int *)(lVar2 + 0x7c) << 0x10 | *(uint *)(lVar2 + 0x80);
    }
    else {
      uVar6 = 0;
    }
    MicrosoftTelemetryAssertTriggeredArgsMsgKM(uVar5,uVar6,uVar3 << 0x10 | uVar1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== RootHub_Pdo_EvtPrepareHardware @ 140016ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RootHub_Pdo_EvtPrepareHardware(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined2 uVar12;
  longlong local_res20;
  ulonglong local_58 [5];
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res20 = 0;
  local_58[0] = (ulonglong)(uint)local_58[0];
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar5 = *(longlong *)(lVar5 + 8);
  lVar2 = *(longlong *)(lVar5 + 0xb0);
  local_58[2] = 0;
  local_28 = 0;
  local_58[1] = 0;
  local_58[0] = 0x38;
  uStack_30 = 0;
  local_58[3] = 0x100000001;
  local_58[4] = param_1;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,local_58,&local_res20);
  uVar11 = (ulonglong)uVar4;
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001714d;
    uVar12 = 0x44;
  }
  else {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x278))
                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_USB_HUB,0,local_res20);
    uVar11 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      uVar3 = Controller_QueryClearTtBufferOnAsyncTransferCancel(lVar2);
      *(undefined1 *)(lVar2 + 0x471) = uVar3;
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x158);
      *(undefined1 *)(lVar5 + 0x178) = 1;
      *(longlong *)(lVar5 + 0x180) = local_res20;
      local_res20 = 0;
      KeReleaseSpinLock(lVar5 + 0x158,uVar3);
      Etw_UcxRootHubPrepare(0,lVar5);
      RootHub_PropagateDeviceProperties
                (*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar5 + 0x160));
      if (*(char *)(g_WdfDriverUcxContext + 0x2c) != '\0') {
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x108))
                          (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x160));
        uVar10 = WdfDriverGlobals;
        uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))
                          (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x10));
        puVar1 = (undefined8 *)(lVar5 + 400);
        uVar8 = SleepstudyHelper_RegisterPdoWithParentPdo(uVar10,uVar7,uVar6,puVar1);
        uVar11 = uVar8 & 0xffffffff;
        uVar9 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar9 == 0) {
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x47,
                                &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar8);
            }
            *puVar1 = 0;
            goto LAB_14001714d;
          }
        }
        else if ((int)uVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x46,
                              &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar8);
          }
          *puVar1 = 0;
          uVar11 = 0;
        }
      }
      *(undefined4 *)(lVar5 + 0x188) = 0;
      if (-1 < (int)uVar11) {
        return uVar11;
      }
      goto LAB_14001714d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001714d;
    uVar12 = 0x45;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar12,
                     &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_1,(char)uVar11);
LAB_14001714d:
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar11;
}



===== RootHub_Pdo_EvtReleaseHardware @ 1400171e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RootHub_Pdo_EvtReleaseHardware(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
  lVar3 = *(longlong *)(lVar3 + 8);
  Etw_UcxRootHubRelease(0,lVar3);
  if (*(undefined **)(lVar3 + 400) != (undefined *)0x0) {
    SleepstudyHelper_UnregisterComponent(*(undefined **)(lVar3 + 400));
    *(undefined8 *)(lVar3 + 400) = 0;
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x158);
  lVar1 = *(longlong *)(lVar3 + 0x180);
  *(undefined8 *)(lVar3 + 0x180) = 0;
  *(undefined1 *)(lVar3 + 0x178) = 0;
  KeReleaseSpinLock(lVar3 + 0x158,uVar2);
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar1);
  }
  return 0;
}



===== RootHub_Pdo_IrpCompletion @ 1400172c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RootHub_Pdo_IrpCompletion(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x3a,
                       in_stack_ffffffffffffffd8,(char)*(undefined4 *)(lVar2 + 0x18),(char)param_2);
  }
  if ((*(int *)(lVar2 + 0x18) == 0x49100b) && (-1 < *(int *)(param_2 + 0x30))) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_3,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
    puVar3 = *(undefined4 **)(lVar2 + 8);
    *puVar3 = 0x18;
    *(uint *)(*(longlong *)(lVar4 + 8) + 0xd0) = (uint)*(ushort *)(puVar3 + 2);
    *(uint *)(*(longlong *)(lVar4 + 8) + 0xd4) = (uint)*(ushort *)((longlong)puVar3 + 10);
  }
  return 0;
}



===== RootHub_Pdo_QueryInterfaceAdd @ 1400173a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RootHub_Pdo_QueryInterfaceAdd(undefined8 param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_258 [32];
  undefined8 local_228;
  undefined4 *puStack_220;
  undefined *local_218;
  undefined8 uStack_210;
  code *local_208;
  undefined8 uStack_200;
  undefined4 local_1f8;
  undefined8 local_1f4;
  undefined4 local_1ec;
  code *local_1e8;
  code *local_1e0;
  code *local_1d8;
  undefined2 local_1c8;
  undefined2 local_1c6;
  undefined1 local_1c4 [268];
  undefined4 local_b8;
  undefined1 local_b4 [140];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_258;
  local_1f4 = 0;
  local_1ec = 0;
  memset(local_b4,0,0x8c);
  puStack_220 = &local_b8;
  local_b8 = 0x3f50090;
  uStack_210 = 0;
  local_218 = &GUID_HUB_PARENT_INTERFACE;
  local_228 = 0x30;
  local_208 = RootHub_EvtHubParentQueryInterfaceRequest;
  uStack_200 = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_228);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x4e;
  }
  else {
    memset(local_1c4,0,0x104);
    local_1c8 = 0x108;
    uVar2 = Feature_EUSB2__private_IsEnabledDeviceUsageNoInline();
    local_1c6 = 3000;
    if ((int)uVar2 == 0) {
      local_1c6 = 2000;
    }
    puStack_220 = (undefined4 *)&local_1c8;
    local_228 = 0x30;
    uStack_200 = 1;
    uStack_210 = 0;
    local_218 = &GUID_HUB_CONTROLLERSTACK_INTERFACE;
    local_208 = RootHub_EvtHubControllerStackQueryInterfaceRequest;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_228);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x4f;
    }
    else {
      uStack_200 = 1;
      puStack_220 = (undefined4 *)0x0;
      uStack_210 = 0;
      local_218 = &USB_BUS_INTERFACE_USBDI_GUID;
      local_208 = RootHub_Evt20USBDIQueryInterfaceRequest;
      local_228 = 0x30;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_228);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x50;
      }
      else {
        uStack_200 = 1;
        puStack_220 = (undefined4 *)0x0;
        uStack_210 = 0;
        local_218 = &GUID_USBD_INTERFACE;
        local_208 = RootHub_EvtUSBDInterfaceRequest;
        local_228 = 0x30;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_228);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar3 = 0x51;
        }
        else {
          local_1f4 = 0;
          local_1ec = 0;
          uStack_210 = 0;
          uStack_200 = 0;
          local_208 = (code *)0x0;
          local_1e8 = _guard_check_icall;
          local_1e0 = _guard_check_icall;
          local_1d8 = RootHub_Pdo_GetLocationString;
          puStack_220 = &local_1f8;
          local_218 = &GUID_PNP_LOCATION_INTERFACE;
          local_1f8 = 0x10028;
          local_228 = 0x30;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_228);
          if (-1 < iVar1) {
            return iVar1;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar3 = 0x52;
        }
      }
    }
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar3,
                    &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)iVar1);
  return iVar1;
}



===== RootHub_PortChangedWorkItem @ 140017750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_PortChangedWorkItem(undefined8 param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  
  uVar6 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar6,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  puVar8 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x198),
                      PTR__WDF_PORT_CHANGED_WORKITEM_CONTEXT_TYPE_INFO_14002d898);
  (**(code **)(lVar7 + 0x58))(*(undefined8 *)(lVar7 + 8),*puVar8);
  lVar7 = *(longlong *)(lVar7 + 0xb0);
  iVar4 = *(int *)(lVar7 + 1000);
  LOCK();
  piVar1 = (int *)(lVar7 + 0x3ec);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    lVar2 = lVar7 + 0x3e0;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
    if ((*(char *)(lVar7 + 0x3f1) == '\0') && (iVar4 == *(int *)(lVar7 + 1000))) {
      *(undefined1 *)(lVar7 + 0x3f1) = 1;
      KeReleaseSpinLock(lVar2,uVar5);
      StateMachineEngine_EventAdd((undefined8 *)(lVar7 + 0x1f8),0xebe40031);
    }
    else {
      KeReleaseSpinLock(lVar2,uVar5);
    }
  }
  return;
}



===== RootHub_PropagateDeviceProperties @ 140017874 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_PropagateDeviceProperties(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 uVar6;
  undefined4 local_68 [2];
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined *local_40;
  undefined8 local_38;
  
  local_68[0] = 7;
  local_60 = 0;
  local_res20[0] = 0;
  local_40 = &DEVPKEY_PciDevice_SerialNumber;
  local_res18[0] = 0;
  local_50 = 0;
  bVar4 = 1;
  local_58 = 0;
  local_48 = 0x18;
  local_38 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd88))
                    (WdfDriverGlobals,param_1,&local_48,8,&local_60,local_res20,local_res18);
  if (iVar1 < 0) {
    local_48 = 0x18;
    local_40 = &DEVPKEY_PciDevice_ParentSerialNumber;
    puVar3 = &local_60;
    local_38 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xd88))
                      (WdfDriverGlobals,param_1,&local_48,8,puVar3,local_res20,local_res18);
    uVar6 = (undefined4)((ulonglong)puVar3 >> 0x20);
    if (-1 < iVar1) goto LAB_140017984;
LAB_140017a10:
    bVar4 = 0;
  }
  else {
LAB_140017984:
    local_40 = &DEVPKEY_PciDevice_UsbDvsecPortSpecificAttributes;
    local_48 = 0x18;
    local_38 = 0;
    uVar6 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                      (WdfDriverGlobals,param_1,&local_48,1,0,&local_58,local_68);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 1;
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x41,
                           &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_1,
                           (char)iVar1);
      }
      goto LAB_140017a10;
    }
  }
  local_48 = 0x18;
  local_40 = &DEVPKEY_PciDevice_UsbDvsecPortSpecificAttributes;
  local_38 = 0;
  if (bVar4 == 1) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_58,&local_50);
  }
  else {
    uVar2 = 0;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd98))
                    (WdfDriverGlobals,param_2,&local_48,local_68[0],
                     CONCAT44(uVar6,(undefined4)local_50),uVar2);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017b42;
    uVar5 = 0x42;
  }
  else {
    local_40 = &DEVPKEY_PciDevice_SerialNumber;
    puVar3 = &local_60;
    local_48 = 0x18;
    if (bVar4 != 1) {
      puVar3 = (undefined8 *)0x0;
    }
    local_38 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xd98))
                      (WdfDriverGlobals,param_2,&local_48,local_res18[0],(ulonglong)bVar4 << 3,
                       puVar3);
    if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_140017b42;
    uVar5 = 0x43;
    param_1 = param_2;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar5,
                     &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)param_1,(char)iVar1);
LAB_140017b42:
  if (local_58 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== RootHub_ResumeRootHubIO @ 140017b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_ResumeRootHubIO(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 200);
  uVar2 = *(undefined8 *)(lVar1 + 8);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x18);
  *(short *)(lVar1 + 0x20) = *(short *)(lVar1 + 0x20) + 1;
  KeReleaseSpinLock(lVar1 + 0x18,uVar3);
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x170));
  return;
}



===== RootHub_StartFailingRootHubIO @ 140017c2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RootHub_StartFailingRootHubIO(longlong param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x528))
            (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(param_1 + 200) + 8),0,0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x170),0,0);
  return;
}



===== RootHub_StaticPdoSetup @ 140017c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RootHub_StaticPdoSetup
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  int *piVar1;
  undefined4 *_Dst;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  uint uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  ushort *puVar13;
  undefined2 uVar14;
  longlong *plVar15;
  undefined1 auStackY_638 [32];
  longlong local_5e0;
  longlong local_5d8;
  ushort local_5d0 [4];
  undefined1 *local_5c8;
  ushort local_5c0 [4];
  undefined1 *local_5b8;
  ushort local_5b0 [4];
  wchar_t *local_5a8;
  ushort local_5a0 [4];
  undefined1 *local_598;
  undefined8 local_590;
  undefined8 uStack_588;
  undefined8 local_580;
  undefined8 uStack_578;
  undefined8 local_570;
  undefined8 uStack_568;
  undefined *local_560;
  undefined8 local_558;
  undefined4 *local_550;
  undefined8 local_548;
  undefined8 local_538;
  undefined8 uStack_530;
  undefined8 local_528;
  undefined8 uStack_520;
  undefined8 local_518;
  code *pcStack_510;
  code *local_508;
  undefined4 local_500;
  undefined4 local_4f8;
  undefined4 local_4f4;
  undefined4 local_4f0;
  undefined1 local_4eb;
  code *local_4d0;
  undefined4 local_4a8;
  undefined4 local_498;
  undefined4 local_494;
  code *local_490;
  code *local_480;
  code *local_470;
  code *local_468;
  undefined8 local_408;
  undefined8 uStack_400;
  undefined8 local_3f8;
  undefined4 local_3f0;
  undefined2 local_3ec;
  wchar_t local_3e8 [16];
  undefined1 local_3c8 [192];
  undefined1 local_308 [352];
  undefined1 local_1a8 [352];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_638;
  local_560 = (undefined *)((ulonglong)local_560 & 0xffffffff00000000);
  local_508 = (code *)0x0;
  local_500 = 0;
  local_494 = 0;
  local_5e0 = 0;
  bVar3 = true;
  local_590 = 0;
  uStack_588 = 0;
  local_580 = 0;
  uStack_578 = 0;
  local_570 = 0;
  uStack_568 = 0;
  local_538 = 0;
  uStack_530 = 0;
  local_528 = 0;
  uStack_520 = 0;
  local_518 = 0;
  pcStack_510 = (code *)0x0;
  memset(&local_498,0,0x8c);
  memset(&local_4f8,0,0x60);
  local_3f0 = 0x30;
  local_3ec = 0;
  local_550 = &local_3f0;
  local_5a8 = local_3e8;
  local_5c8 = local_308;
  local_5b8 = local_1a8;
  local_598 = local_3c8;
  local_548 = 0;
  local_558 = 0x60004;
  builtin_wcsncpy(local_3e8,L"USB\\ROOT_HUB30",0xf);
  local_5b0[0] = 0x1e;
  local_5b0[1] = 0x20;
  local_5b0[2] = 0;
  local_5b0[3] = 0;
  local_3e8[0xf] = L'\0';
  local_5d0[0] = 0;
  local_5d0[1] = 0x158;
  local_5d0[2] = 0;
  local_5d0[3] = 0;
  local_5c0[0] = 0;
  local_5c0[1] = 0x158;
  local_5c0[2] = 0;
  local_5c0[3] = 0;
  local_5a0[0] = 0;
  local_5a0[1] = 0xc0;
  local_5a0[2] = 0;
  local_5a0[3] = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  lVar2 = *(longlong *)(lVar6 + 0xb0);
  local_408 = 0x11d1c85d9d7debbc;
  uStack_400 = 0x9aa1c3086000b49e;
  local_3f8 = 0xf;
  (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,param_2,&local_408);
  local_5d8 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_2);
  if (local_5d8 == 0) {
    uVar10 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xb,
                       &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids);
    }
  }
  else {
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_5d8,&local_558);
    uVar10 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar14 = 0xc;
LAB_140017f4b:
        uVar4 = (undefined1)uVar5;
LAB_140017f4d:
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar14,
                          &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,uVar4);
      }
    }
    else {
      if (*(int *)(lVar2 + 0x78) == 1) {
        param_4 = (ulonglong)*(uint *)(lVar2 + 0x80);
        RtlUnicodeStringPrintf
                  (local_5d0,
                   L"USB\\ROOT_HUB30&VID%04X&PID%04X&REV%04X#USB\\ROOT_HUB30&VID%04X&PID%04X#USB\\ROOT_HUB30#"
                   ,(ulonglong)*(uint *)(lVar2 + 0x7c),param_4);
        puVar13 = local_5d0;
        *(undefined2 *)(local_5c8 + 0x4c) = 0;
        *(undefined2 *)(local_5c8 + 0x8a) = 0;
        *(undefined2 *)(local_5c8 + 0xa8) = 0;
      }
      else if (*(int *)(lVar2 + 0x78) == 2) {
        param_4 = lVar2 + 0x99;
        RtlUnicodeStringPrintf
                  (local_5c0,
                   L"USB\\ROOT_HUB30&VID%S&PID%S&REV%S%cUSB\\ROOT_HUB30&VID%S&PID%S%cUSB\\ROOT_HUB30%c"
                   ,lVar2 + 0x94,param_4);
        puVar13 = local_5c0;
      }
      else {
        puVar13 = local_5b0;
      }
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_5d8,puVar13);
      uVar10 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0xd;
          goto LAB_140017f4b;
        }
      }
      else {
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_5d8,local_5b0);
        uVar10 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar14 = 0xe;
            goto LAB_140017f4b;
          }
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0xc40))(WdfDriverGlobals,local_5d8);
          uVar8 = CONCAT71((int7)(param_4 >> 8),0xf);
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                            (WdfDriverGlobals,local_5d8,
                             RootHub_Pdo_EvtInternalDeviceControlIrpPreprocessCallback,uVar8);
          uVar10 = (ulonglong)uVar5;
          if ((int)uVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar14 = 0xf;
              goto LAB_140017f4b;
            }
          }
          else {
            uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),0xe);
            uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                              (WdfDriverGlobals,local_5d8,
                               RootHub_Pdo_EvtDeviceControlIrpPreprocessCallback,uVar8);
            uVar10 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar14 = 0x10;
                goto LAB_140017f4b;
              }
            }
            else {
              uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),0x1b);
              uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                                (WdfDriverGlobals,local_5d8,
                                 RootHub_Pdo_EvtQueryInterfaceIrpPreprocessCallback,uVar8);
              uVar10 = (ulonglong)uVar5;
              if ((int)uVar5 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar14 = 0x11;
                  goto LAB_140017f4b;
                }
              }
              else {
                plVar15 = (longlong *)CONCAT71((int7)((ulonglong)uVar8 >> 8),0x16);
                uVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                                  (WdfDriverGlobals,local_5d8,
                                   RootHub_Pdo_EvtSetPowerIrpPreprocessCallback);
                uVar10 = (ulonglong)uVar5;
                if ((int)uVar5 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar14 = 0x12;
                    goto LAB_140017f4b;
                  }
                }
                else {
                  local_590 = *(undefined8 *)(lVar6 + 0x78);
                  uStack_588 = *(undefined8 *)(lVar6 + 0x80);
                  local_580 = *(undefined8 *)(lVar6 + 0x88);
                  local_570 = *(undefined8 *)(lVar6 + 0x98);
                  uStack_568 = *(undefined8 *)(lVar6 + 0xa0);
                  local_560 = *(undefined **)(lVar6 + 0xa8);
                  uStack_578 = 0x100000001;
                  (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_5d8,&local_590);
                  local_560 = PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8;
                  local_580 = 0;
                  uStack_588 = 0;
                  local_590 = 0x38;
                  uStack_578 = 0x100000001;
                  local_570 = 0;
                  uStack_568 = 0;
                  memset(&local_498,0,0x90);
                  local_470 = RootHub_Pdo_EvtPrepareHardware;
                  local_468 = RootHub_Pdo_EvtReleaseHardware;
                  local_490 = RootHub_Pdo_EvtD0Entry;
                  local_480 = RootHub_Pdo_EvtD0Exit;
                  local_498 = 0x90;
                  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_5d8,&local_498);
                  memset(&local_538,0,0x40);
                  pcStack_510 = RootHub_Pdo_EvtDeviceEnableWakeAtBus;
                  local_508 = _guard_check_icall;
                  local_538 = CONCAT44(local_538._4_4_,0x40);
                  (**(code **)(WdfFunctions_01015 + 0x698))(WdfDriverGlobals,local_5d8,&local_538);
                  uVar11 = 0;
                  do {
                    uVar10 = RtlUnicodeStringPrintf
                                       (local_5a0,L"\\Device\\USBPDO-%d",(ulonglong)uVar11,plVar15);
                    uVar5 = (uint)uVar10;
                    uVar10 = uVar10 & 0xffffffff;
                    if ((int)uVar5 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar14 = 0x13;
LAB_1400188ed:
                        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar14,
                                           &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,
                                           (char)uVar11,(char)uVar5);
                      }
                      goto LAB_140017eac;
                    }
                    uVar5 = (**(code **)(WdfFunctions_01015 + 0x218))
                                      (WdfDriverGlobals,local_5d8,local_5a0);
                    uVar10 = (ulonglong)uVar5;
                    if ((int)uVar5 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar14 = 0x14;
                        goto LAB_1400188ed;
                      }
                      goto LAB_140017eac;
                    }
                    uVar5 = (**(code **)(WdfFunctions_01015 + 0x220))
                                      (WdfDriverGlobals,local_5d8,
                                       &SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_RW_RES_R);
                    uVar10 = (ulonglong)uVar5;
                    if ((int)uVar5 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar14 = 0x15;
                        goto LAB_1400188ed;
                      }
                      goto LAB_140017eac;
                    }
                    plVar15 = &local_5e0;
                    uVar5 = (**(code **)(WdfFunctions_01015 + 600))
                                      (WdfDriverGlobals,&local_5d8,&local_590);
                    uVar11 = uVar11 + 1;
                    uVar10 = (ulonglong)uVar5;
                  } while (uVar5 == 0xc0000035);
                  if ((int)uVar5 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar14 = 0x16;
                      goto LAB_140017f4b;
                    }
                  }
                  else {
                    local_4a8 = 0xffffffff;
                    local_4d0 = RootHub_EvtIoDeviceControl;
                    local_4f8 = 0x60;
                    local_4f0 = 2;
                    local_4eb = 1;
                    local_4f4 = 2;
                    uVar5 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                      (WdfDriverGlobals,local_5e0,&local_4f8,0);
                    uVar10 = (ulonglong)uVar5;
                    if ((int)uVar5 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar14 = 0x17;
                        goto LAB_14001850e;
                      }
                    }
                    else {
                      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_5e0,1,1);
                      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_5e0,2,1);
                      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_5e0,3,1);
                      (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_5e0,4,1);
                      *(undefined8 *)(lVar6 + 0xd8) = 0;
                      *(undefined8 *)(lVar6 + 0xe0) = 0;
                      *(undefined8 *)(lVar6 + 0xe8) = 0;
                      *(undefined8 *)(lVar6 + 0xf0) = 0;
                      *(undefined8 *)(lVar6 + 0xf8) = 0;
                      *(undefined8 *)(lVar6 + 0x100) = 0;
                      *(undefined4 *)(lVar6 + 0x104) = 0xffffffff;
                      *(undefined4 *)(lVar6 + 0xd8) = 0x30;
                      *(undefined4 *)(lVar6 + 0xdc) = 2;
                      *(undefined8 *)(lVar6 + 0xe0) = 2;
                      *(undefined8 *)(lVar6 + 0xe8) = 2;
                      *(undefined4 *)(lVar6 + 0xf0) = 2;
                      *(undefined4 *)(lVar6 + 0xf4) = 2;
                      *(undefined4 *)(lVar6 + 0xf8) = 2;
                      *(undefined8 *)(lVar6 + 0xfc) = 2;
                      (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals);
                      _Dst = (undefined4 *)(lVar6 + 0x108);
                      memset(_Dst,0,0x50);
                      *_Dst = 0x50;
                      *(undefined8 *)(lVar6 + 0x124) = 0x500000005;
                      *(undefined8 *)(lVar6 + 300) = 0x500000005;
                      iVar9 = 2;
                      *(undefined8 *)(lVar6 + 0x134) = 0x500000005;
                      *(undefined4 *)(lVar6 + 0x13c) = 5;
                      *(undefined4 *)(lVar6 + 0x144) = 7;
                      *(undefined4 *)(lVar6 + 0x148) = 0xffffffff;
                      *(undefined4 *)(lVar6 + 0x14c) = 0xffffffff;
                      *(undefined4 *)(lVar6 + 0x150) = 0xffffffff;
                      puVar7 = (undefined4 *)(lVar6 + 300);
                      *(undefined4 *)(lVar6 + 0x154) = 5;
                      *(undefined4 *)(lVar6 + 0x140) = 3;
                      *(undefined8 *)(lVar6 + 0x114) = 1;
                      *(undefined8 *)(lVar6 + 0x11c) = 1;
                      *(undefined4 *)(lVar6 + 0x110) = 1;
                      *(undefined4 *)(lVar6 + 0x10c) = 0;
                      lVar2 = *(longlong *)(lVar6 + 0xb0);
                      piVar1 = (int *)(lVar2 + 0x18c);
                      iVar12 = *piVar1;
                      if (iVar12 == 0) {
                        iVar12 = 1;
                      }
                      *(int *)(lVar6 + 0x144) = iVar12;
                      do {
                        if ((*piVar1 < iVar9) ||
                           (*(int *)((lVar2 - (longlong)_Dst) + 0x154 + (longlong)puVar7) == 0)) {
                          *puVar7 = 4;
                        }
                        else {
                          *puVar7 = 3;
                          if (iVar12 == 6) {
                            *(int *)(lVar6 + 0x144) = iVar9;
                          }
                        }
                        iVar9 = iVar9 + 1;
                        puVar7 = puVar7 + 1;
                      } while (iVar9 < 6);
                      if ((*(int *)(lVar6 + 0x134) == 3) && (*(int *)(lVar6 + 0x138) != 3)) {
                        *(undefined4 *)(lVar6 + 0x138) = 3;
                        *(undefined4 *)(lVar6 + 0x144) = 5;
                      }
                      (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_5e0,_Dst);
                      puVar7 = (undefined4 *)
                               (**(code **)(WdfFunctions_01015 + 0x650))
                                         (WdfDriverGlobals,local_5e0,
                                          PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
                      *puVar7 = 0x6f645052;
                      *(longlong *)(puVar7 + 2) = lVar6;
                      uVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                                        (WdfDriverGlobals,param_1,
                                         PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870);
                      *(undefined8 *)(puVar7 + 4) = uVar8;
                      *(undefined4 *)(*(longlong *)(puVar7 + 2) + 0x18c) = 0;
                      uVar5 = (**(code **)(WdfFunctions_01015 + 0x268))
                                        (WdfDriverGlobals,local_5e0,&GUID_DEVINTERFACE_USB_HUB,0);
                      uVar10 = (ulonglong)uVar5;
                      if ((int)uVar5 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x18,
                                             &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,
                                             (char)local_5e0,(char)uVar5);
                        }
                      }
                      else {
                        uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x158);
                        *(longlong *)(lVar6 + 0x160) = local_5e0;
                        KeReleaseSpinLock(lVar6 + 0x158,uVar4);
                        uVar5 = (**(code **)(WdfFunctions_01015 + 0x428))
                                          (WdfDriverGlobals,param_2,local_5e0);
                        uVar10 = (ulonglong)uVar5;
                        if ((int)uVar5 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar14 = 0x19;
LAB_14001850e:
                            uVar4 = (undefined1)uVar5;
                            goto LAB_140017f4d;
                          }
                        }
                        else {
                          bVar3 = false;
                          uVar5 = RootHub_Pdo_QueryInterfaceAdd(local_5e0);
                          uVar10 = (ulonglong)uVar5;
                          if (-1 < (int)uVar5) goto LAB_140018948;
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar14 = 0x1a;
                            goto LAB_14001850e;
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
LAB_140017eac:
  if (local_5d8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if ((local_5e0 != 0) && (bVar3)) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140018948:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1b,
                      &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar10);
  }
  return uVar10;
}



===== WPP_RECORDER_SF_Dq @ 1400189b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x3c,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x3c,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 140018a84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_ddd @ 140018bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,5,9,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_dddd @ 140018c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x5a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,3,9,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x5a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 140018dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x40,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x40,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140018e84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x48,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,0x48,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 140018f78 =====

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



===== _UcxRootHubCreate @ 1400190b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong _UcxRootHubCreate(undefined8 param_1,ulonglong param_2,uint *param_3,ulonglong *param_4,
                           longlong *param_5)

{
  longlong *plVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong *puVar8;
  longlong *plVar9;
  undefined2 uVar10;
  ulonglong *puVar11;
  undefined8 local_b8;
  code *pcStack_b0;
  ulonglong local_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  longlong *local_80;
  undefined8 uStack_78;
  undefined *local_70;
  ulonglong local_68;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_68 = (ulonglong)(uint)local_68;
  local_70 = (undefined *)((ulonglong)local_70 & 0xffffffff00000000);
  local_a8 = local_a8 & 0xffffffff00000000;
  local_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  local_90 = 0;
  uStack_8c = 0;
  uStack_88 = 0;
  local_80 = (longlong *)0x0;
  uStack_78 = 0;
  local_b8 = 0;
  pcStack_b0 = (code *)0x0;
  puVar11 = param_4;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  plVar1 = param_5;
  local_68 = 0x38;
  local_58 = 0;
  local_48 = 0;
  uStack_40 = 0;
  *param_5 = 0;
  local_50 = 1;
  local_4c = 1;
  local_60 = RootHub_EvtCleanupCallback;
  local_38 = PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938;
  if (param_4 == (ulonglong *)0x0) {
    param_4 = &local_68;
    puVar8 = (ulonglong *)0x0;
    local_48 = param_2;
  }
  else {
    param_4[4] = param_2;
    puVar8 = &local_68;
  }
  param_5 = (longlong *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,param_4,&param_5);
  if ((int)uVar3 < 0) {
LAB_140019275:
    uVar6 = (ulonglong)uVar3;
    if (param_5 != (longlong *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    plVar9 = (longlong *)0x0;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x25,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar3);
      goto LAB_140019509;
    }
  }
  else {
    if (puVar8 != (ulonglong *)0x0) {
      puVar11 = (ulonglong *)0x0;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_5,puVar8);
      if ((int)uVar3 < 0) goto LAB_140019275;
    }
    plVar9 = param_5;
  }
  puVar5 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,plVar9,PTR__WDF_UCXROOTHUB_PRIVCONTEXT_TYPE_INFO_14002d938);
  *puVar5 = 0x63627548;
  *(longlong **)(puVar5 + 2) = plVar9;
  *(longlong *)(puVar5 + 0x2c) = lVar4;
  KeInitializeSpinLock(puVar5 + 0x56);
  memmove(puVar5 + 4,param_3,(ulonglong)*param_3);
  uVar3 = RootHub_AddUsbDeviceContext(param_2,plVar9);
  uVar6 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0x26;
LAB_140019444:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar10,
                        &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar3);
    }
  }
  else {
    uVar6 = RootHub_AddEndpoint(param_2,plVar9,2);
    uVar3 = (uint)uVar6;
    uVar6 = uVar6 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x27;
        goto LAB_140019444;
      }
    }
    else {
      uVar6 = RootHub_AddEndpoint(param_2,plVar9,0);
      uVar3 = (uint)uVar6;
      uVar6 = uVar6 & 0xffffffff;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x28;
          goto LAB_140019444;
        }
      }
      else {
        uVar6 = RootHub_StaticPdoSetup
                          (param_2,*(undefined8 *)(lVar4 + 0x10),plVar9,(ulonglong)puVar11);
        uVar3 = (uint)uVar6;
        uVar6 = uVar6 & 0xffffffff;
        if (-1 < (int)uVar3) {
          if (*(int *)(lVar4 + 0x4c8) == 2) {
            local_70 = PTR__WDF_PORT_CHANGED_WORKITEM_CONTEXT_TYPE_INFO_14002d898;
            uStack_8c = 0;
            uStack_78 = 0;
            uStack_88 = 0x100000001;
            pcStack_b0 = RootHub_PortChangedWorkItem;
            local_a8 = 1;
            uStack_9c = 0;
            uStack_98 = 0;
            uStack_94 = 0;
            local_90 = 0;
            local_a0 = 0x38;
            local_b8 = 0x18;
            local_80 = plVar9;
            uVar3 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                              (WdfDriverGlobals,&local_b8,&local_a0,puVar5 + 0x66);
            uVar6 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x2a;
                goto LAB_140019444;
              }
              goto LAB_140019465;
            }
          }
          lVar7 = lVar4 + 0x1e8;
          uVar2 = KeAcquireSpinLockRaiseToDpc(lVar7);
          *(undefined4 **)(lVar4 + 0x158) = puVar5;
          *(undefined4 *)(lVar4 + 0x1f0) = 1;
          KeReleaseSpinLock(lVar7,uVar2);
          *plVar1 = (longlong)plVar9;
          if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
            McTemplateK0ppz_EtwWriteTransfer
                      (lVar7,&UCX_ETW_EVENT_UCX_ROOTHUB_CREATE,0,
                       *(undefined8 *)(*(longlong *)(puVar5 + 0x2c) + 0x28),
                       (char)*(undefined8 *)(puVar5 + 2),(wchar_t *)0x0);
          }
          goto LAB_140019509;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x29;
          goto LAB_140019444;
        }
      }
    }
  }
LAB_140019465:
  if (plVar9 != (longlong *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,plVar9);
  }
LAB_140019509:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2b,
                      &WPP_21a17a2372db343ee8b9edca7dd5f5f6_Traceguids,(char)uVar6);
  }
  return uVar6;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140019564 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14001963c =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140019720 =====

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
LAB_140019878:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14001986b:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140019878;
      if (uVar5 == 5) goto LAB_14001986b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400198a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140019924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140019a14 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140019b24 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140019b88 =====

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



===== wil_details_IsEnabledFallback @ 140019ce8 =====

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



===== wil_details_MapReportingKind @ 140019d7c =====

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



===== Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline @ 140019e1c =====

ulonglong Feature_UCX_Etw__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_UCX_Etw__private_featureState;
  if ((Feature_UCX_Etw__private_featureState & 0x10) == 0) {
    uVar1 = Feature_UCX_Etw__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_UCX_Etw__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_UCX_Etw__private_IsEnabledFallback @ 140019e54 =====

void Feature_UCX_Etw__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_UCX_Etw__private_descriptor);
  return;
}



===== Feature_UISCSF__private_IsEnabledDeviceUsageNoInline @ 140019e70 =====

ulonglong Feature_UISCSF__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_UISCSF__private_featureState;
  if ((Feature_UISCSF__private_featureState & 0x10) == 0) {
    uVar1 = Feature_UISCSF__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_UISCSF__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_UISCSF__private_IsEnabledFallback @ 140019ea8 =====

void Feature_UISCSF__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_UISCSF__private_descriptor);
  return;
}



===== UsbDevice_EnableForwardProgress @ 140019ec4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UsbDevice_EnableForwardProgress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined8 in_stack_ffffffffffffffc8;
  undefined1 uVar7;
  longlong lVar8;
  
  lVar1 = *(longlong *)(param_1 + 0xf8);
  uVar3 = *(uint *)(param_2 + 0x10);
  lVar5 = lVar1 + 0x10;
  uVar7 = (undefined1)param_2;
  if (0x80000 < uVar3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x51,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7,(char)uVar3);
    }
    return -0x3ffffff3;
  }
  if ((uVar3 != 0) && (*(char *)(lVar1 + 0x38) != '\0')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar6 = 0x52;
    lVar8 = lVar5;
LAB_140019f63:
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                       &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7,(char)lVar8);
    return -0x3ffffff3;
  }
  for (uVar4 = 0; (uint)uVar4 < *(uint *)(param_2 + 0x14); uVar4 = (ulonglong)((uint)uVar4 + 1)) {
    iVar2 = *(int *)(param_2 + (uVar4 + 2) * 0x10);
    if (0x7ffff < iVar2 - 1U) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar3,uVar4,0x53,
                          in_stack_ffffffffffffffc8,uVar7,(char)uVar4,(char)iVar2);
      return -0x3ffffff3;
    }
    lVar8 = *(longlong *)(param_2 + 0x18 + uVar4 * 0x10);
    if (*(char *)(lVar8 + 0x28) != '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar6 = 0x54;
      goto LAB_140019f63;
    }
  }
  if ((uVar3 != 0) && ((*(char *)(lVar1 + 0x39) != '\x01' || (uVar3 < *(uint *)(lVar1 + 0x3c))))) {
    if (*(code **)(lVar1 + 0xa8) == (code *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff45;
      }
      uVar6 = 0x55;
      goto LAB_14001a068;
    }
    iVar2 = (**(code **)(lVar1 + 0xa8))();
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar6 = 0x56;
LAB_14001a0cd:
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7,(char)lVar5,
                          (char)iVar2);
      return iVar2;
    }
    *(undefined1 *)(lVar1 + 0x39) = 1;
    *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)(param_2 + 0x10);
  }
  uVar4 = 0;
  while( true ) {
    if (*(uint *)(param_2 + 0x14) <= (uint)uVar4) {
      if (*(int *)(param_2 + 0x10) != 0) {
        *(undefined1 *)(lVar1 + 0x38) = 1;
      }
      uVar4 = 0;
      if (*(int *)(param_2 + 0x14) != 0) {
        do {
          uVar3 = (int)uVar4 + 1;
          *(undefined1 *)(*(longlong *)(param_2 + 0x18 + uVar4 * 0x10) + 0x28) = 1;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)(param_2 + 0x14));
      }
      return 0;
    }
    lVar5 = *(longlong *)(param_2 + 0x18 + uVar4 * 0x10);
    if (*(code **)(lVar5 + 0x98) == (code *)0x0) break;
    lVar8 = uVar4 + 2;
    iVar2 = (**(code **)(lVar5 + 0x98))
                      (*(undefined8 *)(lVar5 + -8),*(undefined4 *)(param_2 + lVar8 * 0x10));
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar6 = 0x58;
      goto LAB_14001a0cd;
    }
    *(undefined1 *)(lVar5 + 0x29) = 1;
    uVar4 = (ulonglong)((uint)uVar4 + 1);
    *(undefined4 *)(lVar5 + 0x2c) = *(undefined4 *)(param_2 + lVar8 * 0x10);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return -0x3fffff45;
  }
  uVar6 = 0x57;
LAB_14001a068:
  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                     &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar7,(char)lVar5);
  return -0x3fffff45;
}



===== UsbDevice_EnableInvalidHandleTracking @ 14001a1e8 =====

void UsbDevice_EnableInvalidHandleTracking(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  uVar6 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x18) + 0x1e8);
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x80);
  if (*(char *)(param_1 + 0x1a1) == '\0') {
    plVar1 = (longlong *)(param_1 + 0x50);
    plVar3 = (longlong *)*plVar1;
    if (plVar1 != plVar3) {
      do {
        plVar4 = *(longlong **)(param_1 + 0x78);
        plVar2 = plVar3 + 10;
        if (*plVar4 != param_1 + 0x70) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        *plVar2 = param_1 + 0x70;
        plVar3[0xb] = (longlong)plVar4;
        *plVar4 = (longlong)plVar2;
        *(longlong **)(param_1 + 0x78) = plVar2;
        plVar3 = (longlong *)*plVar3;
      } while (plVar1 != plVar3);
    }
    *(undefined1 *)(param_1 + 0x1a1) = 1;
  }
  KeReleaseSpinLock(param_1 + 0x80,uVar7);
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x18) + 0x1e8,uVar6);
  return;
}



===== UsbDevice_GetUsbDeviceCharacteristics @ 14001a2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UsbDevice_GetUsbDeviceCharacteristics
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  int *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = (int *)0x0;
  local_30 = 0;
  uStack_28 = 0;
  if ((param_3 == 0x18) && (param_4 == 0x18)) {
    local_48 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x18,&local_38);
    if (iVar2 < 0) goto LAB_14001a418;
    lVar1 = *(longlong *)(local_38 + 1);
    if (lVar1 != 0) {
      if ((*local_38 == 0) ||
         (lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,lVar1,
                             PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0),
         *(longlong *)(lVar3 + 0xe8) == 0)) {
        iVar2 = -0x3fffff45;
      }
      else {
        uStack_28 = 0;
        local_30 = 0x100000010;
        iVar2 = (**(code **)(lVar3 + 0xe8))(*(undefined8 *)(param_1 + 0x28),lVar1,&local_30);
        if (-1 < iVar2) {
          *local_38 = 1;
          local_38[3] = 1;
          local_38[4] = (int)uStack_28;
          local_38[5] = uStack_28._4_4_;
          (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x18);
          return;
        }
      }
      goto LAB_14001a418;
    }
  }
  iVar2 = -0x3ffffff3;
LAB_14001a418:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== UsbDevice_NotifyControllerResetCompleteCallback @ 14001a460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_NotifyControllerResetCompleteCallback(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    for (puVar4 = *(undefined8 **)(param_1 + 0x50); (undefined8 *)(param_1 + 0x50) != puVar4;
        puVar4 = (undefined8 *)*puVar4) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,puVar4[-0x17],UsbDevice_NotifyControllerResetCompleteCallback,
                 0x527,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\usbdevice.c");
      plVar2 = *(longlong **)(param_2 + 8);
      plVar1 = puVar4 + 4;
      if (*plVar2 != param_2) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *plVar1 = param_2;
      puVar4[5] = plVar2;
      *plVar2 = (longlong)plVar1;
      *(longlong **)(param_2 + 8) = plVar1;
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
  }
  return;
}



===== UsbDevice_PendDisableRequestDueToControllerReset @ 14001a510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PendDisableRequestDueToControllerReset(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1e,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x8c8))
            (WdfDriverGlobals,uVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x138));
  return;
}



===== UsbDevice_PendResetRequestDueToControllerReset @ 14001a5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbDevice_PendResetRequestDueToControllerReset(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1c,
                      &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x8c8))
            (WdfDriverGlobals,uVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x138));
  return;
}



===== WPP_RECORDER_SF_Lqq @ 14001a64c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lqq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0x491053;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,0x43,local_18,4,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,0x43,local_18,4,
                  &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 14001a748 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,0x36,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,0x36,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 14001a81c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== _UcxUsbDeviceRemoteWakeNotification @ 14001a920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxUsbDeviceRemoteWakeNotification(undefined8 param_1,ulonglong param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined *puVar9;
  undefined8 in_stack_ffffffffffffffd8;
  undefined1 uVar10;
  
  puVar9 = PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar1 = lVar5 + 0x168;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar10 = (undefined1)lVar5;
  if (*(longlong *)(lVar5 + 0x160) == 0) {
    plVar8 = (longlong *)(lVar5 + 0x170);
    lVar6 = *plVar8;
    if (lVar6 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x11,
                          &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar10);
      }
    }
    else {
      uVar2 = *(uint *)(*(longlong *)(lVar5 + 0x178) + 0x10);
      if (uVar2 == param_3) {
LAB_14001aa60:
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,lVar6);
        if (-1 < iVar4) {
          lVar5 = *plVar8;
          *plVar8 = 0;
          plVar8[1] = 0;
          KeReleaseSpinLock(lVar1,uVar3);
          (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar5,0);
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x14,
                              &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,uVar10,(char)*plVar8,
                              (char)iVar4);
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar2,puVar9,0x12,
                            in_stack_ffffffffffffffd8,uVar10,(char)uVar2,(char)param_3);
      }
    }
  }
  else {
    for (uVar7 = 0; (uint)uVar7 < *(uint *)(lVar5 + 0x150); uVar7 = (ulonglong)((uint)uVar7 + 1)) {
      plVar8 = (longlong *)(*(longlong *)(lVar5 + 0x158) + (uVar7 * 5 + 3) * 8);
      lVar6 = *plVar8;
      if ((lVar6 != 0) && (*(uint *)(plVar8[1] + 0x10) == param_3)) goto LAB_14001aa60;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x13,
                         &WPP_fd458ded74e03da6cb6b1f77379b7239_Traceguids,(char)param_3,uVar10);
    }
  }
  KeReleaseSpinLock(lVar1,uVar3);
  return;
}



===== Endpoint_ClearTTBufferComplete @ 14001ab90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_ClearTTBufferComplete(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  Endpoint_TryToCallEvtEndpointOkToCancelTransfers(lVar1);
  return;
}



===== Endpoint_Create_V2 @ 14001abd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Endpoint_Create_V2(undefined8 param_1,undefined8 param_2,undefined4 *param_3,
                            undefined4 param_4,byte *param_5,undefined8 *param_6,longlong *param_7)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined2 uVar7;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined2 local_c0;
  undefined1 local_be;
  undefined4 local_bd;
  undefined2 local_b9;
  longlong local_b0;
  undefined1 local_48;
  undefined8 local_47;
  undefined8 local_3f;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar4 = *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28);
  memset(&local_d8,0,0xa8);
  local_c8 = 3;
  bVar6 = *(byte *)((longlong)param_3 + 3) & 3;
  local_d8 = 0x74697045;
  if (bVar6 != 1) {
    if (bVar6 == 2) {
      local_c8 = 2;
    }
    else {
      local_c8 = 1;
      if (bVar6 == 3) {
        local_c8 = 4;
      }
    }
  }
  if (param_6 == (undefined8 *)0x0) {
    if (*(short *)(param_3 + 1) == 0) {
      local_d4 = 1;
    }
  }
  else {
    local_3f = *param_6;
  }
  local_c4 = *param_3;
  local_c0 = *(undefined2 *)(param_3 + 1);
  local_be = *(undefined1 *)((longlong)param_3 + 6);
  local_48 = 1;
  if (param_5 != (byte *)0x0) {
    local_bd = *(undefined4 *)param_5;
    local_b9 = *(undefined2 *)(param_5 + 4);
    if ((bVar6 == 1) && ((char)param_5[3] < '\0')) {
      local_47 = *(undefined8 *)(param_5 + *param_5);
    }
  }
  local_d0 = param_2;
  if ((param_6 != (undefined8 *)0x0) && (*(longlong *)(lVar3 + 0xf0) == 0)) {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xe,
                       &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids);
    }
    goto LAB_14001ae80;
  }
  if (*(code **)(lVar3 + 0xf0) == (code *)0x0) {
    uVar2 = (**(code **)(lVar3 + 0xd0))(uVar4,param_2,param_3,param_4,param_5,&local_d8);
    uVar5 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) goto LAB_14001ae01;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ae80;
    uVar7 = 0x10;
  }
  else {
    uVar2 = (**(code **)(lVar3 + 0xf0))(uVar4,param_2,param_3,param_4,param_5,param_6,&local_d8);
    uVar5 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
LAB_14001ae01:
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_b0,
                         PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
      if (*(longlong *)(lVar3 + 0x10) != 0) {
        KeInitializeSpinLock(lVar3 + 0x300);
        *param_7 = local_b0;
        uVar4 = WdfDriverGlobals;
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,local_b0,
                           PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
        Etw_UcxEndpointCreate(uVar4,lVar3);
        return uVar5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x11,
                          &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar3);
      }
      uVar5 = 0xc00000e5;
      if (*(char *)(*(longlong *)(lVar3 + 0x40) + 0x3f9) != '\0') {
        pcVar1 = (code *)swi(3);
        uVar5 = (*pcVar1)();
        return uVar5;
      }
      goto LAB_14001ae80;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ae80;
    uVar7 = 0xf;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar7,
                    &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)uVar5);
LAB_14001ae80:
  *param_7 = 0;
  if (local_b0 != 0) {
    Endpoint_Delete(param_1,param_2,local_b0);
  }
  return uVar5;
}



===== Endpoint_GetIsochPipeTransferPathDelaysUrb @ 14001af10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Endpoint_GetIsochPipeTransferPathDelaysUrb(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x1c) == 3) {
    if (*(code **)(param_1 + 0xb0) == (code *)0x0) {
      iVar1 = -0x3fffff45;
LAB_14001afed:
      uVar2 = 0xc0000e00;
      goto LAB_14001aff2;
    }
    iVar1 = (**(code **)(param_1 + 0xb0))(*(undefined8 *)(param_1 + 8));
    if (iVar1 < 0) {
      if (iVar1 == -0x3ffffff2) {
        uVar2 = 0xc0007000;
        goto LAB_14001aff2;
      }
      if (iVar1 == -0x3fffff66) {
        uVar2 = 0xc0001000;
        goto LAB_14001aff2;
      }
      if (iVar1 == -0x3fffff45) goto LAB_14001afed;
      if (iVar1 == -0x3ffffee0) {
        uVar2 = 0xc0010000;
        goto LAB_14001aff2;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x70) = 0;
      *(undefined4 *)(param_2 + 0x74) = 0;
    }
    if (iVar1 == 0) {
      uVar2 = 0;
      goto LAB_14001aff2;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x20,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)param_1 + '\x10');
    }
    iVar1 = -0x3ffffff3;
  }
  uVar2 = 0x80000300;
LAB_14001aff2:
  if (param_2 + 0x50 == *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_2 + 0xc) = 0xabcd0000;
  }
  *(undefined4 *)(param_2 + 0x54) = uVar2;
  *(undefined8 *)(param_3 + 0x38) = 0;
  *(int *)(param_3 + 0x30) = iVar1;
  IofCompleteRequest(param_3,0);
  return iVar1;
}



===== Endpoint_ProcessResetNotificationRequest @ 14001b040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Endpoint_ProcessResetNotificationRequest(longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  longlong lVar9;
  undefined8 local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  lVar2 = param_1 + 0x300;
  local_68 = local_68 & 0xffffffff00000000;
  local_30 = local_30 & 0xffffffff00000000;
  local_88 = 0;
  pcStack_80 = (code *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2);
  *(undefined1 *)(param_1 + 0x308) = uVar4;
  uVar4 = (undefined1)param_1;
  if (*(char *)(param_1 + 0x309) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x22,
                         &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,uVar4,(char)param_3);
    }
    iVar6 = -0x3ffffe7c;
    goto LAB_14001b3b6;
  }
  if (*(longlong *)(param_1 + 0x318) == 0) {
    if (*(longlong *)(param_1 + 800) == 0) {
      if (*(char *)(param_1 + 0x328) == '\0') {
        if (*(int *)(param_2 + 0x70) == 0) {
          if (*(int *)(param_2 + 0x74) == 0) {
            *(longlong *)(param_3 + 0x78) = param_1;
            *(longlong *)(param_1 + 0x318) = param_3;
            *(longlong *)(param_1 + 800) = param_2;
            local_30 = 0;
            uStack_58 = 0;
            local_60 = 0x38;
            local_50 = 0;
            uStack_48 = 0x100000000;
            local_40 = 0;
            uStack_38 = 0;
            local_40 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
            uStack_48 = CONCAT44(uStack_48._4_4_,2);
            local_68 = 0;
            pcStack_80 = Endpoint_ResetNotificationTimer;
            local_88 = 0x28;
            local_78 = 0x100000000;
            uStack_70 = 0;
            iVar6 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                              (WdfDriverGlobals,&local_88,&local_60,param_1 + 0x310);
            if (-1 < iVar6) {
              LOCK();
              *(code **)(param_3 + 0x68) = Endpoint_ResetNotificationRequestCancelRoutine;
              UNLOCK();
              if (*(char *)(param_3 + 0x44) != '\0') {
                LOCK();
                lVar9 = *(longlong *)(param_3 + 0x68);
                *(longlong *)(param_3 + 0x68) = 0;
                UNLOCK();
                if (lVar9 != 0) {
                  iVar6 = -0x3ffffee0;
                  goto LAB_14001b3b6;
                }
              }
              pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
              *pbVar1 = *pbVar1 | 1;
              KeReleaseSpinLock(lVar2,*(undefined1 *)(param_1 + 0x308));
              return 0x103;
            }
            goto LAB_14001b3b6;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar8 = 0x27;
            goto LAB_14001b2a8;
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x26;
LAB_14001b2a8:
          lVar9 = param_2;
          goto LAB_14001b25d;
        }
      }
      else {
        if (*(int *)(param_2 + 0x74) == 1) {
          if ((*(longlong *)(param_1 + 0x310) != 0) &&
             (cVar5 = (**(code **)(WdfFunctions_01015 + 0xa00))
                                (WdfDriverGlobals,*(longlong *)(param_1 + 0x310),0), cVar5 != '\0'))
          {
            Controller_PendingPrepareForResetOperationComplete(*(longlong *)(param_1 + 0x40));
            uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2);
            uVar3 = *(undefined8 *)(param_1 + 0x310);
            *(undefined1 *)(param_1 + 0x308) = uVar4;
            *(undefined8 *)(param_1 + 0x310) = 0;
            *(undefined1 *)(param_1 + 0x328) = 0;
            KeReleaseSpinLock(lVar2,uVar4);
            (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,uVar3);
          }
          iVar6 = 0;
          goto LAB_14001b3b6;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b282;
        uVar8 = 0x25;
        lVar9 = param_3;
LAB_14001b25d:
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar8,
                           &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar9,uVar4);
      }
LAB_14001b282:
      iVar6 = -0x3ffffff3;
      goto LAB_14001b3b6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x24;
      lVar9 = param_2;
      goto LAB_14001b131;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar8 = 0x23;
    lVar9 = param_3;
LAB_14001b131:
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar8,
                       &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar9,uVar4);
  }
  iVar6 = -0x3ffffe7c;
LAB_14001b3b6:
  *(undefined8 *)(param_1 + 0x318) = 0;
  *(undefined8 *)(param_1 + 800) = 0;
  *(undefined8 *)(param_3 + 0x78) = 0;
  KeReleaseSpinLock(lVar2);
  if (iVar6 == -0x3ffffff2) {
    uVar7 = 0xc0007000;
  }
  else if (iVar6 == -0x3fffff66) {
    uVar7 = 0xc0001000;
  }
  else if (iVar6 == -0x3fffff45) {
    uVar7 = 0xc0000e00;
  }
  else if (iVar6 == -0x3ffffee0) {
    uVar7 = 0xc0010000;
  }
  else {
    uVar7 = -(uint)(iVar6 != 0) & 0x80000300;
  }
  if (param_2 + 0x50 == *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_2 + 0xc) = 0xabcd0000;
  }
  *(uint *)(param_2 + 0x54) = uVar7;
  *(int *)(param_3 + 0x30) = iVar6;
  *(undefined8 *)(param_3 + 0x38) = 0;
  IofCompleteRequest(param_3,0);
  return iVar6;
}



===== Endpoint_ResetNotificationRequestCancelRoutine @ 14001b4b0 =====

void Endpoint_ResetNotificationRequestCancelRoutine(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x78);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x300);
  lVar2 = *(longlong *)(lVar1 + 800);
  *(undefined8 *)(lVar1 + 0x318) = 0;
  *(undefined8 *)(lVar1 + 800) = 0;
  *(undefined1 *)(lVar1 + 0x308) = uVar3;
  *(undefined8 *)(param_2 + 0x78) = 0;
  KeReleaseSpinLock(lVar1 + 0x300,*(undefined1 *)(lVar1 + 0x308));
  if (lVar2 + 0x50 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
    *(undefined4 *)(lVar2 + 0xc) = 0xabcd0000;
  }
  *(undefined4 *)(lVar2 + 0x54) = 0xc0010000;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== Endpoint_ResetNotificationTimer @ 14001b580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_ResetNotificationTimer(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x21,
                      &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,(char)lVar3);
  }
  Controller_PendingPrepareForResetOperationComplete(*(longlong *)(lVar3 + 0x40));
  uVar1 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x300);
  *(undefined8 *)(lVar3 + 0x310) = 0;
  *(undefined1 *)(lVar3 + 0x308) = uVar1;
  KeReleaseSpinLock(lVar3 + 0x300,uVar1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== Endpoint_SetPriority @ 14001b690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Endpoint_SetPriority
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  if (*(longlong *)(lVar1 + 0xb8) != 0) {
    local_28 = 0xc;
    local_24 = 1;
    local_20 = param_4;
    (**(code **)(lVar1 + 0xb8))(param_3,&local_28);
  }
  return;
}



===== Endpoint_StaticStreamsDisableUrb @ 14001b724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
Endpoint_StaticStreamsDisableUrb
          (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  cVar4 = KeGetCurrentIrql();
  if (cVar4 == '\0') {
    if (*(longlong *)(param_1 + 0x50) != 0) {
      *(undefined4 *)(param_3 + 0x54) = 0x40000000;
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_2,PTR__WDF_RHPDO_CONTEXT_TYPE_INFO_14002d8e8);
      uVar2 = *(undefined8 *)(*(longlong *)(lVar7 + 0x10) + 0x130);
      pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      puVar3 = *(undefined8 **)(param_4 + 0xb8);
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
      uVar8 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_2);
      iVar6 = IoSetCompletionRoutineEx(uVar8,param_4,Xrb_UrbCompletion,param_3 + 0x50,1,1,1);
      if (iVar6 < 0) {
        lVar7 = *(longlong *)(param_4 + 0xb8);
        *(code **)(lVar7 + -0x10) = Xrb_UrbCompletion;
        *(longlong *)(lVar7 + -8) = param_3 + 0x50;
        *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      }
      (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_2,param_4,uVar2,2);
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1f,
                       &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids);
    }
    uVar9 = 0xc0000184;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = KeGetCurrentIrql();
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1e,
                        &WPP_51bd4b7b99263a583c30ac5da0fc6017_Traceguids,uVar5);
    }
    uVar9 = 0xc000000d;
  }
  if (param_3 + 0x50 == *(longlong *)(*(longlong *)(param_4 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_3 + 0xc) = 0xabcd0000;
  }
  *(undefined4 *)(param_3 + 0x54) = 0x80000300;
  *(undefined8 *)(param_4 + 0x38) = 0;
  *(undefined4 *)(param_4 + 0x30) = uVar9;
  IofCompleteRequest(param_4,0);
  return uVar9;
}



===== Endpoint_TryToCallEvtEndpointOkToCancelTransfers @ 14001b958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Endpoint_TryToCallEvtEndpointOkToCancelTransfers(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x2f0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 8));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),_UcxEndpointNeedToCancelTransfers,0xa5e
               ,"onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\endpoint.c");
  }
  return;
}



===== _UcxEndpointNoPingResponseError @ 14001b9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxEndpointNoPingResponseError(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXENDPOINT_PRIVCONTEXT_TYPE_INFO_14002da88);
  *(undefined4 *)(*(longlong *)(lVar1 + 0x48) + 0x18c) = 1;
  return;
}



===== Controller_CleanupUnicodeString @ 14001ba10 =====

void Controller_CleanupUnicodeString(undefined8 *param_1)

{
  if (param_1[1] != 0) {
    ExFreePoolWithTag(param_1[1],0x44434855);
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



===== Controller_CsqCompleteCancelledAbortPipeIrp @ 14001ba50 =====

void Controller_CsqCompleteCancelledAbortPipeIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  bool bVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar3 = lVar1 != *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (!bVar3) {
    *(undefined4 *)(lVar1 + -0x44) = 0xabcd0000;
  }
  *(undefined4 *)(lVar1 + 4) = 0xc0007000;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  if (bVar3) {
    uVar2 = KfRaiseIrql(CONCAT71((int7)((ulonglong)lVar1 >> 8),2));
    IofCompleteRequest(param_2,0);
    KeLowerIrql(uVar2);
  }
  else {
    IofCompleteRequest(param_2,0);
  }
  return;
}



===== Controller_DuplicateUnicodeString @ 14001bae8 =====

ulonglong Controller_DuplicateUnicodeString(ushort *param_1,ushort *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  lVar1 = ExAllocatePool2(0x40,param_1[1],0x44434855);
  *(longlong *)(param_2 + 4) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    param_2[1] = param_1[1];
    uVar2 = RtlUnicodeStringCopy(param_2,param_1);
  }
  return uVar2;
}



===== Controller_EnableForwardProgress @ 14001bb50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Controller_EnableForwardProgress(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeWaitForSingleObject(param_1 + 0x438,0,0,0,0);
  plVar1 = (longlong *)(param_1 + 0x418);
  if (*plVar1 == 0) {
    uStack_40 = 0;
    local_38 = 0;
    local_48 = CONCAT44(local_48._4_4_,0x30);
    uStack_30 = CONCAT44(uStack_30._4_4_,0x200);
    local_28 = 0;
    uStack_20 = 0;
    iVar2 = PsCreateSystemThread(&local_res8,0,&local_48,0,0,Controller_SystemThread,param_1);
    if (-1 < iVar2) {
      iVar2 = ObReferenceObjectByHandle(local_res8,0,0,0,plVar1,0);
      ZwClose(local_res8);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x59,
                            &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)iVar2);
        }
        *plVar1 = 0;
        goto LAB_14001bda2;
      }
      goto LAB_14001bcb0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001bda2;
    uVar4 = 0x58;
  }
  else {
LAB_14001bcb0:
    if ((*(char *)(param_1 + 0x470) == '\0') && (*(code **)(param_1 + 0x60) != (code *)0x0)) {
      iVar2 = (**(code **)(param_1 + 0x60))(*(undefined8 *)(param_1 + 0x28));
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x5a,
                             &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_1,
                             (char)iVar2);
        }
        goto LAB_14001bda2;
      }
      *(undefined1 *)(param_1 + 0x470) = 1;
    }
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 8),
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if ((*(uint *)(lVar3 + 4) & 2) != 0) {
      iVar2 = 0;
      goto LAB_14001bda2;
    }
    iVar2 = UsbDevice_EnableForwardProgress(lVar3,param_2);
    if ((-1 < iVar2) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14001bda2;
    uVar4 = 0x5b;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                    &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)iVar2);
LAB_14001bda2:
  KeReleaseMutex(param_1 + 0x438,0);
  return iVar2;
}



===== Controller_EvtDefaultIoWdfIrpForForwardProgress @ 14001bde0 =====

char Controller_EvtDefaultIoWdfIrpForForwardProgress(undefined8 param_1,longlong param_2)

{
  return (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0x49000b) + '\x01';
}



===== Controller_EvtDestroyCallback @ 14001be00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_EvtDestroyCallback(undefined8 param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  Controller_CleanupUnicodeString((undefined8 *)(lVar5 + 0x498));
  Controller_CleanupUnicodeString((undefined8 *)(lVar5 + 0x4a8));
  Controller_CleanupUnicodeString((undefined8 *)(lVar5 + 0x4b8));
  if (*(longlong *)(lVar5 + 0x418) != 0) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x400);
    *(undefined1 *)(lVar5 + 0x473) = 1;
    KeSetEvent(lVar5 + 0x420,0,0);
    KeReleaseSpinLock(lVar5 + 0x400,uVar4);
    KeWaitForSingleObject(*(undefined8 *)(lVar5 + 0x418),0,0,0,0);
  }
  if (*(char *)(lVar5 + 0x3f8) != '\0') {
    Controller_ForwardProgressWorkItemDelete(*(longlong *)(lVar5 + 0x2b0));
    *(undefined1 *)(lVar5 + 0x3f8) = 0;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(g_WdfDriverUcxContext + 0x20);
  plVar1 = (longlong *)(lVar5 + 0x18);
  lVar6 = *plVar1;
  if ((lVar6 != 0) || (*(longlong *)(lVar5 + 0x20) != 0)) {
    if ((*(longlong **)(lVar6 + 8) != plVar1) ||
       (plVar2 = *(longlong **)(lVar5 + 0x20), (longlong *)*plVar2 != plVar1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3,uVar4);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar2;
    *(int *)(g_WdfDriverUcxContext + 0x28) = *(int *)(g_WdfDriverUcxContext + 0x28) + -1;
  }
  lVar6 = g_WdfDriverUcxContext + 0x20;
  KeReleaseSpinLock();
  *(undefined8 *)(lVar5 + 0x20) = 0;
  *(undefined8 *)(lVar5 + 0x18) = 0;
  Etw_UcxControllerDelete(lVar6,lVar5);
  lVar6 = *(longlong *)(lVar5 + 0x150);
  if (lVar6 != 0) {
    *(undefined8 *)(lVar5 + 0x150) = 0;
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,lVar6,_UcxControllerCreate,0x651,
               "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\controller.c");
  }
  return;
}



===== Controller_EvtNotifyOnTransportCharacteristicsChangeCanceledOnQueue @ 14001bfd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_EvtNotifyOnTransportCharacteristicsChangeCanceledOnQueue
               (undefined8 param_1,undefined8 param_2)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000120);
  return;
}



===== Controller_EvtTransportCharacteristicsChangeRegistrationIoDeviceControl @ 14001c000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_EvtTransportCharacteristicsChangeRegistrationIoDeviceControl
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,int param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
  if (param_5 == 0x220468) {
    Controller_RegisterTransportCharacteristicsChangeNotification
              (*(longlong *)(lVar2 + 8),param_2,param_3,param_4);
  }
  else if (param_5 == 0x220470) {
    Controller_UnregisterTransportCharacteristicsChangeNotification
              (*(longlong *)(lVar2 + 8),param_2,param_3,param_4);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,100,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  return;
}



===== Controller_FreeDumpData @ 14001c108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_FreeDumpData(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(code **)(param_1 + 0x70) == (code *)0x0) {
    uVar1 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x57,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  else {
    (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x28));
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,uVar1);
  return;
}



===== Controller_GetDumpData @ 14001c19c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_GetDumpData(longlong param_1)

{
  int iVar1;
  undefined8 in_stack_00000028;
  
  if (*(code **)(param_1 + 0x68) == (code *)0x0) {
    iVar1 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x55,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x68))(*(undefined8 *)(param_1 + 0x28));
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x56,
                         &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_1,(char)iVar1)
      ;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,in_stack_00000028,iVar1);
  return;
}



===== Controller_GetTransportCharacteristics @ 14001c278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_GetTransportCharacteristics
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 auStackY_88 [32];
  undefined *puVar5;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = (undefined4 *)0x0;
  if (*(longlong *)(param_1 + 0x100) == 0) {
    uVar4 = 0xc00000bb;
  }
  else {
    if ((param_3 == 0x18) && (param_4 == 0x18)) {
      puVar5 = (undefined *)0x0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x18,&local_48);
      if (-1 < iVar2) {
        puVar3 = &local_40;
        uVar1 = (**(code **)(param_1 + 0x100))(*(undefined8 *)(param_1 + 0x28));
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
            puVar3 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar3 >> 8),5);
            puVar5 = &WPP_930299d70c09358e97b1031e752bd63d_Traceguids;
            param_3 = 1;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x62,
                              &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar1);
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_Dii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,param_3,99,puVar5,
                                (char)local_40,(char)uStack_38,(char)local_30);
          }
        }
        *local_48 = 1;
        local_48[1] = (undefined4)local_40;
        *(undefined8 *)(local_48 + 2) = uStack_38;
        *(ulonglong *)(local_48 + 4) = CONCAT44(uStack_2c,local_30);
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x18);
        return;
      }
    }
    uVar4 = 0xc000000d;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar4);
  return;
}



===== Controller_HandleStartTrackingForTimeSync @ 14001c424 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_HandleStartTrackingForTimeSync(longlong param_1,undefined8 param_2)

{
  if (*(code **)(param_1 + 0x110) == (code *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  else {
    (**(code **)(param_1 + 0x110))(*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== Controller_HandleStopTrackingForTimeSync @ 14001c46c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_HandleStopTrackingForTimeSync(longlong param_1,undefined8 param_2)

{
  if (*(code **)(param_1 + 0x118) == (code *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  else {
    (**(code **)(param_1 + 0x118))(*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== Controller_NotifyOnTransportCharacteristicsChange @ 14001c4b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Controller_NotifyOnTransportCharacteristicsChange
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong local_res8;
  longlong *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  local_58 = (longlong *)0x0;
  local_res8 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_20 = (undefined *)((ulonglong)local_20 & 0xffffffff00000000);
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if (*(longlong *)(param_1 + 0x108) == 0) {
    iVar3 = -0x3fffff45;
  }
  else if ((param_3 == 0x20) && (param_4 == 0x20)) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,&local_58,0);
    if (-1 < iVar3) {
      iVar3 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8));
      do {
        lVar1 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d0),iVar3);
        iVar3 = iVar3 + 1;
        if (lVar1 == 0) {
          iVar3 = -0x3ffffff3;
          (**(code **)(WdfFunctions_01015 + 0x9e8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8));
          goto LAB_14001c6b3;
        }
      } while (*local_58 != lVar1);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8));
      local_20 = PTR__WDF_TRANSPORT_NOTIFY_CHANGE_REQUEST_CONTEXT_TYPE_INFO_14002da60;
      local_40 = 0;
      uStack_48 = 0;
      local_50 = 0x38;
      local_30 = 0;
      uStack_28 = 0;
      uStack_38 = 0x100000001;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_2,&local_50,&local_res8);
      if (-1 < iVar3) {
        lVar2 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar1,0);
        *(undefined8 *)(local_res8 + 0x10) = param_2;
        *(undefined8 *)(local_res8 + 0x18) = *(undefined8 *)(lVar2 + 0x28);
        *(longlong *)(local_res8 + 0x20) = lVar1;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                          (WdfDriverGlobals,param_2,*(undefined8 *)(param_1 + 0x4e0));
        if (-1 < iVar3) {
          return;
        }
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
LAB_14001c6b3:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  return;
}



===== Controller_QueryClearTtBufferOnAsyncTransferCancel @ 14001c6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 Controller_QueryClearTtBufferOnAsyncTransferCancel(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 local_res8 [2];
  undefined1 uVar3;
  
  uVar2 = 0;
  local_res8[0] = 0;
  uVar3 = (undefined1)param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x3b,
                      &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar3);
  }
  if (*(code **)(param_1 + 0x38) == (code *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3c,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x38))
                      (*(undefined8 *)(param_1 + 0x28),
                       &GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL,0,0,local_res8)
    ;
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3e,
                          &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar3);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3d,
                          &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar3);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== Controller_RegisterTransportCharacteristicsChangeNotification @ 14001c82c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_RegisterTransportCharacteristicsChangeNotification
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStackY_e8 [32];
  undefined *puVar7;
  uint *local_a8;
  undefined8 local_a0;
  uint *local_98;
  ulonglong local_90 [5];
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = (uint *)0x0;
  local_90[0] = (ulonglong)(uint)local_90[0];
  local_98 = (uint *)0x0;
  local_a0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (*(longlong *)(param_1 + 0x108) == 0) {
    uVar6 = 0xc00000bb;
  }
  else {
    if (((param_3 == 0x24) && (param_4 == 0x24)) &&
       (iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x24,&local_a8),
       -1 < iVar3)) {
      local_60 = 0;
      local_90[2] = 0;
      local_90[4] = *(undefined8 *)(param_1 + 0x28);
      uStack_68 = 0;
      local_90[1] = 0;
      local_90[0] = 0x38;
      local_90[3] = 0x100000001;
      puVar7 = (undefined *)0x30;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,local_90,ExDefaultNonPagedPoolType,0);
      if (-1 < iVar3) {
        uVar5 = local_a8[1];
        uVar1 = local_a8[2];
        uVar2 = local_a8[3];
        *local_98 = *local_a8;
        local_98[1] = uVar5;
        local_98[2] = uVar1;
        local_98[3] = uVar2;
        uVar5 = local_a8[5];
        uVar1 = local_a8[6];
        uVar2 = local_a8[7];
        local_98[4] = local_a8[4];
        local_98[5] = uVar5;
        local_98[6] = uVar1;
        local_98[7] = uVar2;
        local_98[8] = local_a8[8];
        *(undefined8 *)(local_98 + 10) = *(undefined8 *)(local_a8 + 1);
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8))
        ;
        uVar6 = local_a0;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d0));
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8))
        ;
        if (iVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x66,
                              &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)iVar3);
          }
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_a0);
          return;
        }
        uVar5 = *(uint *)(param_1 + 0x4cc) | *local_a8;
        if (uVar5 != *(uint *)(param_1 + 0x4cc)) {
          *(uint *)(param_1 + 0x4cc) = uVar5;
          (**(code **)(param_1 + 0x108))(*(undefined8 *)(param_1 + 0x28),uVar5);
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            uVar6 = 1;
            puVar7 = &WPP_930299d70c09358e97b1031e752bd63d_Traceguids;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x67,
                              &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar5);
          }
        }
        *(undefined8 *)(local_a8 + 1) = local_a0;
        local_a8[3] = 0;
        local_a8[4] = 0;
        local_a8[5] = 0;
        local_a8[6] = 0;
        local_a8[7] = 0;
        local_a8[8] = 0;
        if (*(code **)(param_1 + 0x100) != (code *)0x0) {
          puVar4 = &local_58;
          (**(code **)(param_1 + 0x100))(*(undefined8 *)(param_1 + 0x28));
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_Dii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,uVar6,0x68,puVar7,
                                (char)local_58,(char)uStack_50,(char)local_48);
          }
          local_a8[3] = 1;
          local_a8[4] = (uint)local_58;
          *(undefined8 *)(local_a8 + 5) = uStack_50;
          *(ulonglong *)(local_a8 + 7) = CONCAT44(uStack_44,local_48);
        }
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x24);
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x65,
                        &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)iVar3);
      return;
    }
    uVar6 = 0xc000000d;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  return;
}



===== Controller_SetIdStrings @ 14001cbe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Controller_SetIdStrings
                    (undefined8 param_1,ushort *param_2,ushort *param_3,ushort *param_4)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  if ((*(int *)(lVar3 + 0x78) != 3) && (*(int *)(lVar3 + 0x78) != 0)) {
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2a,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
    goto LAB_14001ce02;
  }
  uVar4 = RtlUnicodeStringValidateWorker(param_2);
  iVar2 = (int)uVar4;
  uVar4 = uVar4 & 0xffffffff;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce02;
    uVar5 = 0x2b;
LAB_14001cca7:
    uVar1 = (undefined1)iVar2;
  }
  else {
    uVar4 = RtlUnicodeStringValidateWorker(param_3);
    iVar2 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce02;
      uVar5 = 0x2c;
      goto LAB_14001cca7;
    }
    uVar4 = RtlUnicodeStringValidateWorker(param_4);
    iVar2 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce02;
      uVar5 = 0x2d;
      goto LAB_14001cca7;
    }
    if (((*param_2 != 0) && (*param_3 != 0)) && (*param_4 != 0)) {
      uVar4 = Controller_DuplicateUnicodeString(param_2,(ushort *)(lVar3 + 0x498));
      iVar2 = (int)uVar4;
      uVar4 = uVar4 & 0xffffffff;
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce02;
        uVar5 = 0x2f;
      }
      else {
        uVar4 = Controller_DuplicateUnicodeString(param_3,(ushort *)(lVar3 + 0x4a8));
        iVar2 = (int)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ce02;
          uVar5 = 0x30;
        }
        else {
          uVar4 = Controller_DuplicateUnicodeString(param_4,(ushort *)(lVar3 + 0x4b8));
          iVar2 = (int)uVar4;
          uVar4 = uVar4 & 0xffffffff;
          if (-1 < iVar2) {
            return uVar4;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ce02;
          uVar5 = 0x31;
        }
      }
      goto LAB_14001cca7;
    }
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ce02;
    uVar5 = 0x2e;
    uVar1 = 0xd;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
                    &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,uVar1);
LAB_14001ce02:
  Controller_CleanupUnicodeString((undefined8 *)(lVar3 + 0x498));
  Controller_CleanupUnicodeString((undefined8 *)(lVar3 + 0x4a8));
  Controller_CleanupUnicodeString((undefined8 *)(lVar3 + 0x4b8));
  return uVar4;
}



===== Controller_SystemThread @ 14001ce50 =====

void Controller_SystemThread(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  int iVar7;
  longlong lVar8;
  undefined1 *puVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  puVar9 = auStack_38;
  lVar1 = param_1 + 0x420;
  lVar2 = param_1 + 0x400;
  while( true ) {
    iVar7 = KeReadStateEvent(lVar1);
    if (iVar7 == 0) {
      *(undefined1 *)(param_1 + 0x472) = 1;
    }
    local_18 = 0;
    KeWaitForSingleObject(lVar1,0,0,0);
    *(undefined1 *)(param_1 + 0x472) = 0;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
    if (*(char *)(param_1 + 0x473) != '\0') goto LAB_14001cf2e;
    plVar3 = (longlong *)(param_1 + 0x408);
    plVar4 = (longlong *)*plVar3;
    if (((longlong *)plVar4[1] != plVar3) || (lVar8 = *plVar4, *(longlong **)(lVar8 + 8) != plVar4))
    break;
    *plVar3 = lVar8;
    *(longlong **)(lVar8 + 8) = plVar3;
    if ((longlong *)*plVar3 == plVar3) {
      KeClearEvent(lVar1);
    }
    lVar8 = lVar2;
    KeReleaseSpinLock(lVar2,uVar6);
    Controller_ForwardProgressWorkItemCallback(lVar8,(longlong)(plVar4 + -1));
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar9 = auStack_30;
LAB_14001cf2e:
  *(undefined8 *)(puVar9 + -8) = 0x14001cf3b;
  KeReleaseSpinLock(lVar2,uVar6);
  *(undefined8 *)(puVar9 + -8) = 0x14001cf49;
  PsTerminateSystemThread(0);
  return;
}



===== Controller_UnregisterTransportCharacteristicsChangeNotification @ 14001cf70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Controller_UnregisterTransportCharacteristicsChangeNotification
               (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 **ppuVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 ***pppuVar6;
  undefined8 ***pppuVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  undefined8 ***local_98;
  undefined8 ***pppuStack_90;
  undefined8 local_88;
  longlong *local_80;
  undefined8 **local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_80 = (longlong *)0x0;
  local_78 = (undefined8 **)0x0;
  local_88 = 0;
  local_98 = (undefined8 ***)0x0;
  pppuStack_90 = (undefined8 ***)0x0;
  if (*(longlong *)(param_1 + 0x108) == 0) {
    iVar3 = -0x3fffff45;
    puVar8 = auStackY_d8;
    goto LAB_14001d326;
  }
  puVar8 = auStackY_d8;
  if ((param_3 == 8) && (puVar8 = auStackY_d8, param_4 == 8)) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,8,&local_80);
    puVar8 = auStackY_d8;
    if (-1 < iVar3) {
      iVar10 = 0;
      uVar9 = 0;
      bVar11 = false;
      iVar3 = -0x3ffffff3;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8));
      puVar8 = auStackY_d8;
      while( true ) {
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d0),iVar10);
        iVar10 = iVar10 + 1;
        if (lVar4 == 0) break;
        puVar5 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar4,0);
        if (*local_80 == lVar4) {
          (**(code **)(WdfFunctions_01015 + 0x80))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d0),lVar4);
          (**(code **)(WdfFunctions_01015 + 0x9e8))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8));
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar4);
          iVar3 = 0;
          bVar11 = true;
        }
        else {
          uVar9 = uVar9 | *puVar5;
        }
      }
      if (bVar11) {
        local_98 = &local_98;
        pppuStack_90 = &local_98;
        while( true ) {
          local_50 = 0;
          local_70 = 0;
          uStack_68 = 0;
          local_60 = 0;
          uStack_58 = 0;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x500))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4e0),local_88,0);
          if (iVar3 < 0) break;
          pppuVar6 = (undefined8 ***)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_88,
                                PTR__WDF_TRANSPORT_NOTIFY_CHANGE_REQUEST_CONTEXT_TYPE_INFO_14002da60
                               );
          if (pppuVar6[4] == (undefined8 **)*local_80) {
            iVar3 = (**(code **)(WdfFunctions_01015 + 0x508))
                              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4e0),local_88);
            if (iVar3 < 0) break;
            if ((undefined8 ****)*pppuStack_90 != &local_98) goto LAB_14001d31a;
            pppuVar6[1] = pppuStack_90;
            *pppuVar6 = &local_98;
            *pppuStack_90 = pppuVar6;
            pppuStack_90 = pppuVar6;
          }
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8))
        ;
        if (&local_98 != (undefined8 ****)local_98) {
          pppuVar6 = local_98;
          pppuVar7 = (undefined8 ***)*local_98;
          do {
            if (((undefined8 ***)pppuVar7[1] != pppuVar6) ||
               (ppuVar1 = pppuVar6[1], (undefined8 ***)*ppuVar1 != pppuVar6)) goto LAB_14001d31a;
            *ppuVar1 = pppuVar7;
            pppuVar7[1] = ppuVar1;
            local_78 = pppuVar6[2];
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_78,0xc0000120);
            bVar11 = &local_98 != (undefined8 ****)pppuVar7;
            pppuVar6 = pppuVar7;
            pppuVar7 = (undefined8 ***)*pppuVar7;
          } while (bVar11);
        }
        if (uVar9 != *(uint *)(param_1 + 0x4cc)) {
          *(uint *)(param_1 + 0x4cc) = uVar9;
          (**(code **)(param_1 + 0x108))(*(undefined8 *)(param_1 + 0x28),uVar9);
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x69,
                              &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar9);
          }
        }
        iVar3 = 0;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x4d8))
        ;
        puVar8 = auStackY_d8;
      }
    }
    goto LAB_14001d326;
  }
  goto LAB_14001d321;
LAB_14001d31a:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar8 = auStackY_d0;
LAB_14001d321:
  iVar3 = -0x3ffffff3;
LAB_14001d326:
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  *(undefined8 *)(puVar8 + -8) = 0x14001d346;
  (*pcVar2)(WdfDriverGlobals,param_2,iVar3);
  *(undefined8 *)(puVar8 + -8) = 0x14001d352;
  return;
}



===== RtlStringCbCopyA @ 14001d374 =====

uint RtlStringCbCopyA(char *param_1,longlong param_2,longlong param_3)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (0x7ffffffe < param_2 - 1U) {
    if (param_2 != 0) {
      *param_1 = '\0';
    }
    return 0xc000000d;
  }
  lVar3 = 0x7ffffffe - param_2;
  lVar2 = param_3 - (longlong)param_1;
  do {
    if ((lVar3 + param_2 == 0) || (param_1[lVar2] == '\0')) break;
    *param_1 = param_1[lVar2];
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  pcVar1 = param_1 + -1;
  if (param_2 != 0) {
    pcVar1 = param_1;
  }
  *pcVar1 = '\0';
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlUnicodeStringCopy @ 14001d3d8 =====

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
    if ((int)uVar1 < 0) goto LAB_14001d483;
  }
  else {
    puVar3 = (undefined2 *)(ulonglong)(*param_2 >> 1);
    puVar6 = *(undefined2 **)(param_2 + 4);
  }
  uVar7 = (ulonglong)puVar4 & 0xffffffff;
  if (uVar5 != 0) {
    lVar8 = lVar8 - (longlong)puVar6;
    do {
      if (puVar3 == (undefined2 *)0x0) goto LAB_14001d483;
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
LAB_14001d483:
  *param_1 = (short)puVar4 * 2;
  return uVar7;
}



===== RtlUnicodeStringValidateWorker @ 14001d4ac =====

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



===== UcxControllerGetDeviceCapabilities @ 14001d4f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UcxControllerGetDeviceCapabilities(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_c8 [48];
  longlong local_98 [2];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined2 local_78 [4];
  undefined4 *local_70;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  uStack_80 = 0;
  uStack_7c = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_98[1] = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  memset(local_78,0,0x48);
  local_98[0] = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,0,uVar2,local_98);
  if (-1 < iVar1) {
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_7c = 0;
    local_98[1] = 0x18;
    uStack_88 = 0xc00000bb;
    (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_98[0],local_98 + 1);
    memset(param_2,0,0x40);
    *param_2 = 0x10040;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    local_78[0] = 0x91b;
    local_70 = param_2;
    (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,local_98[0],local_78);
    uStack_28 = 0;
    local_30 = 0x200000010;
    (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_98[0],uVar2,&local_30);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_98[0]);
  }
  if (local_98[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== WPP_RECORDER_SF_Dii @ 14001d6bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,5,1,&WPP_930299d70c09358e97b1031e752bd63d_Traceguids,param_4,&param_6,4,
                  &param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_PPPP @ 14001d7b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PPPP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18 [2];
  
  local_28 = 0xd0;
  local_20 = 0xa0;
  local_18[0] = 0xf8;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,0xc,&uStack0000000000000030,8,
               local_18,8,&local_20,8,&local_28,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_930299d70c09358e97b1031e752bd63d_Traceguids,0xc,
                  &uStack0000000000000030,8,local_18,8,&local_20,8,&local_28,8,0);
  return;
}



===== WPP_RECORDER_SF_qDDDDDDDDDDD @ 14001d8d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDDDDDDDDD(undefined8 param_1)

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
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,0x51,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_930299d70c09358e97b1031e752bd63d_Traceguids,0x51,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,0);
  return;
}



===== _UcxControllerCreate @ 14001db10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _UcxControllerCreate
                    (longlong param_1,undefined4 *param_2,uint *param_3,undefined8 *param_4,
                    longlong *param_5)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  undefined2 uVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined1 auStackY_308 [8];
  undefined1 auStackY_300 [24];
  undefined4 local_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  undefined8 uStack_2a0;
  longlong local_298;
  undefined8 uStack_290;
  undefined *local_288;
  int local_280;
  undefined8 local_278;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 local_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined8 local_250;
  longlong local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined4 *local_220;
  undefined8 local_218;
  undefined4 local_208;
  undefined8 local_204;
  code *local_1e0;
  code *local_1d8;
  code *local_1c0;
  uint local_1b8;
  undefined8 local_1a8;
  undefined8 local_1a0;
  longlong local_198;
  longlong *local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  ulonglong local_158;
  uint local_148 [18];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined1 local_e4;
  undefined1 local_df;
  undefined1 local_da;
  char local_d5 [141];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_308;
  local_190 = param_5;
  local_288 = (undefined *)((ulonglong)local_288 & 0xffffffff00000000);
  local_158 = local_158 & 0xffffffff00000000;
  local_2b8 = 0;
  uStack_2b4 = 0;
  uStack_2b0 = 0;
  uStack_2ac = 0;
  local_2a8 = 0;
  uStack_2a4 = 0;
  uStack_2a0 = 0;
  local_298 = 0;
  uStack_290 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_198 = param_1;
  memset(&local_208,0,0x60);
  lVar17 = 0;
  local_250 = 0;
  local_240 = 0;
  uStack_258 = 0;
  uStack_254 = 0;
  local_238 = 0;
  local_218 = 0;
  local_278 = 0;
  uStack_270 = 0;
  uStack_26c = 0;
  local_230 = 0;
  local_268 = 0;
  uStack_264 = 0;
  uStack_260 = 0;
  uStack_25c = 0;
  local_1a0 = 0;
  local_1a8 = 0;
  local_220 = (undefined4 *)0x0;
  local_228 = 0;
  memset(local_148,0,0xf8);
  if (param_5 == (longlong *)0x0) {
    uVar12 = 0xc000000d;
    puVar13 = auStackY_308;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee83;
    uVar15 = 10;
LAB_14001dc22:
    puVar13 = auStackY_308;
    uVar12 = 0xc000000d;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar15,
                     &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
  }
  else {
    if (param_3 == (uint *)0x0) {
      uVar12 = 0xc000000d;
      puVar13 = auStackY_308;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee83;
      uVar15 = 0xb;
      goto LAB_14001dc22;
    }
    uVar6 = *param_3;
    if (uVar6 == 0xf8) {
LAB_14001dd48:
      puVar13 = auStackY_308;
      if (*(longlong *)(param_3 + 0xe) == 0) {
        if (*(longlong *)(param_3 + 0x10) != 0) goto LAB_14001dd9e;
      }
      else if (*(longlong *)(param_3 + 0x10) == 0) {
LAB_14001dd9e:
        uVar12 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee83;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xd,
                          &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_3);
        puVar13 = auStackY_308;
        goto LAB_14001ee4e;
      }
      local_280 = 1;
      if (param_4 != (undefined8 *)0x0) {
        if (param_4[4] != 0) {
          uVar12 = 0xc000000d;
          puVar13 = auStackY_308;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ee83;
          uVar15 = 0xe;
          goto LAB_14001dc22;
        }
        if (*(int *)(param_4 + 3) == 2) {
          local_188 = *param_4;
          uStack_180 = param_4[1];
          local_280 = 2;
          local_178 = param_4[2];
          local_168 = param_4[4];
          uStack_160 = param_4[5];
          uStack_170 = CONCAT44((int)((ulonglong)param_4[3] >> 0x20),1);
          local_158 = param_4[6];
          param_4 = &local_188;
        }
      }
      local_288 = PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848;
      local_2a8 = 0;
      uStack_2a4 = 0;
      uStack_2b4 = 0;
      uStack_2b0 = 0;
      uStack_2ac = 0;
      uStack_2a0 = 0x100000001;
      local_298 = 0;
      uStack_290 = 0;
      local_2b8 = 0x38;
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_2,&local_2b8,&local_220);
      puVar13 = auStackY_308;
      uVar12 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0xf;
LAB_14001e06c:
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar15,
                            &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar6);
          puVar13 = auStackY_308;
        }
      }
      else {
        local_248 = 0;
        puVar10 = (undefined8 *)&local_2b8;
        if (param_4 != (undefined8 *)0x0) {
          puVar10 = param_4;
        }
        *local_220 = 0x78554457;
        uStack_2a0 = 0x100000001;
        *param_5 = 0;
        local_288 = PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870;
        local_2a8 = 0x4001be00;
        uStack_2a4 = 1;
        uStack_2b4 = 0;
        uStack_2b0 = 0;
        uVar12 = -(ulonglong)(param_4 != (undefined8 *)0x0) & (ulonglong)&local_2b8;
        uStack_2ac = 0;
        local_298 = 0;
        uStack_290 = 0;
        local_2b8 = 0x38;
        puVar10[4] = param_2;
        *(undefined4 *)(puVar10 + 3) = 2;
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,puVar10,&local_248);
        if (((int)uVar6 < 0) ||
           ((uVar12 != 0 &&
            (uVar6 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_248,uVar12,0),
            (int)uVar6 < 0)))) {
          uVar12 = (ulonglong)uVar6;
          if (local_248 != 0) {
            (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
          }
          puVar13 = auStackY_308;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001ee83;
            uVar15 = 0x10;
            goto LAB_14001e06c;
          }
        }
        else {
          lVar17 = local_248;
        }
        puVar13 = auStackY_308;
        puVar7 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,lVar17,
                            PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870);
        if ((ushort)param_3[0x28] == 0) {
LAB_14001e08f:
          iVar4 = local_280;
          *(undefined **)(puVar7 + 2) = &g_UcxTriageInfo;
          *puVar7 = 0x6c727443;
          *(undefined4 **)(puVar7 + 4) = param_2;
          puVar7[0x132] = local_280;
          if (DAT_14002daa8 == (undefined8 *)0x0) {
            DAT_14002daa8 = &g_WdfDriverUcxContext;
          }
          _DAT_14002db80 = (**(code **)(WdfFunctions_01015 + 0xd78))(WdfDriverGlobals);
          *(undefined8 *)(puVar7 + 8) = 0;
          *(undefined8 *)(puVar7 + 6) = 0;
          *(longlong *)(puVar7 + 10) = lVar17;
          memmove(puVar7 + 0xc,param_3,(ulonglong)*param_3);
          *(undefined8 *)(puVar7 + 0x34) = 0;
          *(undefined8 *)(puVar7 + 0x36) = 0;
          *(undefined8 *)(puVar7 + 0x38) = 0;
          *(undefined8 *)(puVar7 + 0x3a) = 0;
          *(undefined8 *)(puVar7 + 0x3c) = 0;
          *(undefined8 *)(puVar7 + 0x3e) = 0;
          *(undefined4 **)(local_220 + 2) = puVar7;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x12,
                               &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)lVar17,
                               (char)puVar7);
          }
          KeInitializeSpinLock(puVar7 + 0x7a);
          puVar7[0x7c] = 0;
          puVar7[0x7d] = 0;
          uVar8 = StateMachineEngine_Init
                            ((longlong)puVar7,(undefined8 *)(puVar7 + 0x7e),lVar17,puVar7,0x12,
                             0x14002dff0,Etw_UcxControllerStateMachineEvent,
                             Etw_UcxControllerStateMachineTransition,iVar4 == 2);
          uVar12 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar3 = (undefined1)uVar8;
              uVar15 = 0x13;
              param_2 = puVar7;
LAB_14001e200:
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar15,
                                 &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)param_2,
                                 uVar3);
            }
          }
          else {
            *(byte *)((longlong)puVar7 + 0x37d) = *(byte *)((longlong)puVar7 + 0x37d) | 2;
            *(undefined1 *)(puVar7 + 0xfe) = 1;
            KeInitializeEvent(puVar7 + 0xe8,1,0);
            KeInitializeEvent(puVar7 + 0xf0,1,0);
            KeInitializeSpinLock(puVar7 + 0xf8);
            puVar7[0xfb] = 1;
            puVar7[0xfd] = 0;
            *(undefined8 *)(puVar7 + 0x122) = 0;
            puVar7[0x124] = 0;
            lVar11 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals);
            iVar4 = MmIsDriverVerifying(*(undefined8 *)(lVar11 + 8));
            if (iVar4 != 0) {
              *(undefined1 *)((longlong)puVar7 + 0x3f9) = 1;
            }
            if ((*(uint *)(*(longlong *)(local_198 + 8) + 8) & 4) != 0) {
              *(undefined1 *)((longlong)puVar7 + 0x3f9) = 1;
            }
            memset(&local_208,0,0x60);
            local_208 = 0x60;
            local_204 = 1;
            local_1d8 = Controller_EvtAddress0OwnershipIoInternalDeviceControl;
            uStack_2a0 = 0x100000001;
            local_288 = PTR__WDF_ADDRESS0_OWNERSHIP_QUEUE_CONTEXT_TYPE_INFO_14002d990;
            uStack_2b4 = 0;
            uStack_2b0 = 0;
            uStack_2ac = 0;
            local_2a8 = 0;
            uStack_2a4 = 0;
            uStack_290 = 0;
            local_2b8 = 0x38;
            local_298 = lVar17;
            uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                              (WdfDriverGlobals,param_2,&local_208,&local_2b8);
            uVar12 = (ulonglong)uVar6;
            if ((int)uVar6 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = 0x14;
LAB_14001dff3:
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar15,
                                  &WPP_930299d70c09358e97b1031e752bd63d_Traceguids,(char)uVar6);
              }
            }
            else {
              uStack_25c = 0;
              uStack_258 = 0;
              uStack_254 = 0;
              uStack_270 = 1;
              uStack_26c = 0;
              local_268 = 0;
              uStack_264 = 0;
              uStack_260 = 0;
              local_278 = 0x100000028;
              uVar6 = (**(code **)(WdfFunctions_01015 + 0xc30))
                                (WdfDriverGlobals,local_250,&local_278);
              uVar12 = (ulonglong)uVar6;
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar15 = 0x15;
                  goto LAB_14001dff3;
                }
              }
              else {
                puVar9 = (undefined4 *)
                         (**(code **)(WdfFunctions_01015 + 0x650))
                                   (WdfDriverGlobals,local_250,
                                    PTR__WDF_ADDRESS0_OWNERSHIP_QUEUE_CONTEXT_TYPE_INFO_14002d990);
                *puVar9 = 0x434f3041;
                *(longlong *)(puVar9 + 2) = lVar17;
                *(undefined8 *)(puVar7 + 0x4a) = local_250;
                local_250 = 0;
                memset(&local_208,0,0x60);
                iVar4 = local_280;
                local_1b8 = param_3[1];
                local_2a8 = 0;
                uStack_2a4 = 0;
                local_208 = 0x60;
                local_1d8 = UsbDevice_EvtMgmtIoInternalDeviceControl;
                local_204 = 2;
                local_288 = (undefined *)0x0;
                uVar5 = 1;
                if (local_280 == 2) {
                  uVar5 = 2;
                }
                uStack_2a0 = CONCAT44(1,uVar5);
                uStack_2b4 = 0;
                uStack_2b0 = 0;
                uStack_2ac = 0;
                local_2b8 = 0x38;
                uStack_290 = 0;
                local_298 = lVar17;
                uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,param_2,&local_208,&local_2b8);
                uVar12 = (ulonglong)uVar6;
                if ((int)uVar6 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar15 = 0x16;
                    goto LAB_14001dff3;
                  }
                }
                else {
                  uStack_25c = 0;
                  uStack_258 = 0;
                  uStack_254 = 0;
                  uStack_270 = 1;
                  uStack_26c = 0;
                  local_268 = 0;
                  uStack_264 = 0;
                  uStack_260 = 0;
                  local_278 = 0x100000028;
                  uVar6 = (**(code **)(WdfFunctions_01015 + 0xc30))
                                    (WdfDriverGlobals,local_240,&local_278);
                  uVar12 = (ulonglong)uVar6;
                  if ((int)uVar6 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar15 = 0x17;
                      goto LAB_14001dff3;
                    }
                  }
                  else {
                    *(undefined8 *)(puVar7 + 0x4c) = local_240;
                    local_240 = 0;
                    memset(&local_208,0,0x60);
                    local_204 = 1;
                    local_2a8 = 0;
                    uStack_2a4 = 0;
                    local_1d8 = UsbDevice_EvtTreePurgeIoInternalDeviceControl;
                    uStack_2a0 = 0x100000001;
                    local_288 = (undefined *)0x0;
                    uStack_2b4 = 0;
                    uStack_2b0 = 0;
                    uStack_2ac = 0;
                    local_208 = 0x60;
                    uStack_290 = 0;
                    local_2b8 = 0x38;
                    local_298 = lVar17;
                    uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                      (WdfDriverGlobals,param_2,&local_208,&local_2b8);
                    uVar12 = (ulonglong)uVar6;
                    if ((int)uVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar15 = 0x18;
                        goto LAB_14001dff3;
                      }
                    }
                    else {
                      uStack_25c = 0;
                      uStack_258 = 0;
                      uStack_254 = 0;
                      uStack_270 = 1;
                      uStack_26c = 0;
                      local_268 = 0;
                      uStack_264 = 0;
                      uStack_260 = 0;
                      local_278 = 0x100000028;
                      uVar6 = (**(code **)(WdfFunctions_01015 + 0xc30))
                                        (WdfDriverGlobals,local_238,&local_278);
                      uVar12 = (ulonglong)uVar6;
                      if ((int)uVar6 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          uVar15 = 0x19;
                          goto LAB_14001dff3;
                        }
                      }
                      else {
                        *(undefined8 *)(puVar7 + 0x50) = local_238;
                        local_238 = 0;
                        memset(&local_208,0,0x60);
                        local_1b8 = 0xffffffff;
                        local_1d8 = UsbDevice_EvtFailMgmtIoInternalDeviceControl;
                        local_208 = 0x60;
                        local_288 = (undefined *)0x0;
                        local_204 = 2;
                        local_2a8 = 0;
                        uStack_2a4 = 0;
                        uStack_2a0 = 0x100000001;
                        uStack_2b4 = 0;
                        uStack_2b0 = 0;
                        uStack_2ac = 0;
                        local_2b8 = 0x38;
                        uStack_290 = 0;
                        local_298 = lVar17;
                        uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                          (WdfDriverGlobals,param_2,&local_208,&local_2b8);
                        uVar12 = (ulonglong)uVar6;
                        if ((int)uVar6 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar15 = 0x1a;
                            goto LAB_14001dff3;
                          }
                        }
                        else {
                          *(undefined8 *)(puVar7 + 0x4e) = local_218;
                          local_218 = 0;
                          memset(&local_208,0,0x60);
                          local_204 = 1;
                          local_2a8 = 0;
                          uStack_2a4 = 0;
                          local_1e0 = 
                          Controller_EvtTransportCharacteristicsChangeRegistrationIoDeviceControl;
                          uStack_2a0 = 0x100000001;
                          local_288 = (undefined *)0x0;
                          uStack_2b4 = 0;
                          uStack_2b0 = 0;
                          uStack_2ac = 0;
                          local_208 = 0x60;
                          uStack_290 = 0;
                          local_2b8 = 0x38;
                          local_298 = lVar17;
                          uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                            (WdfDriverGlobals,param_2,&local_208,&local_2b8);
                          uVar12 = (ulonglong)uVar6;
                          if ((int)uVar6 < 0) {
                            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
                            {
                              uVar15 = 0x1b;
                              goto LAB_14001dff3;
                            }
                          }
                          else {
                            *(undefined8 *)(puVar7 + 0x13a) = local_1a8;
                            memset(&local_208,0,0x60);
                            local_1c0 = 
                            Controller_EvtNotifyOnTransportCharacteristicsChangeCanceledOnQueue;
                            local_208 = 0x60;
                            local_288 = (undefined *)0x0;
                            local_204 = 3;
                            local_2a8 = 0;
                            uStack_2a4 = 0;
                            uStack_2a0 = 0x100000001;
                            uStack_2b4 = 0;
                            uStack_2b0 = 0;
                            uStack_2ac = 0;
                            local_2b8 = 0x38;
                            uStack_290 = 0;
                            local_298 = lVar17;
                            uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                              (WdfDriverGlobals,param_2,&local_208,&local_2b8);
                            uVar12 = (ulonglong)uVar6;
                            if ((int)uVar6 < 0) {
                              if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                  &WPP_RECORDER_INITIALIZED) {
                                uVar15 = 0x1c;
                                goto LAB_14001dff3;
                              }
                            }
                            else {
                              *(undefined8 *)(puVar7 + 0x138) = local_1a0;
                              local_288 = (undefined *)0x0;
                              local_2a8 = 0;
                              uStack_2a4 = 0;
                              uStack_2a0 = 0x100000001;
                              uStack_2b4 = 0;
                              uStack_2b0 = 0;
                              uStack_2ac = 0;
                              local_2b8 = 0x38;
                              uStack_290 = 0;
                              local_298 = lVar17;
                              uVar6 = (**(code **)(WdfFunctions_01015 + 0x68))
                                                (WdfDriverGlobals,&local_2b8,puVar7 + 0x134);
                              uVar12 = (ulonglong)uVar6;
                              if ((int)uVar6 < 0) {
                                if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                    &WPP_RECORDER_INITIALIZED) {
                                  uVar15 = 0x1d;
                                  goto LAB_14001dff3;
                                }
                              }
                              else {
                                local_288 = (undefined *)0x0;
                                local_2a8 = 0;
                                uStack_2a4 = 0;
                                uStack_2a0 = 0x100000001;
                                uStack_2b4 = 0;
                                uStack_2b0 = 0;
                                uStack_2ac = 0;
                                local_2b8 = 0x38;
                                uStack_290 = 0;
                                local_298 = lVar17;
                                uVar6 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                                                  (WdfDriverGlobals,&local_2b8,puVar7 + 0x136);
                                uVar12 = (ulonglong)uVar6;
                                if ((int)uVar6 < 0) {
                                  if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                      &WPP_RECORDER_INITIALIZED) {
                                    uVar15 = 0x1e;
                                    goto LAB_14001dff3;
                                  }
                                }
                                else {
                                  memset(&local_208,0,0x60);
                                  local_1b8 = 0xffffffff;
                                  local_1d8 = Controller_EvtDefaultIoInternalDeviceControl;
                                  local_208 = 0x60;
                                  local_2a8 = 0;
                                  uStack_2a4 = 0;
                                  local_204 = 2;
                                  local_1e0 = Controller_EvtDefaultIoDeviceControl;
                                  local_288 = (undefined *)0x0;
                                  uVar5 = 1;
                                  if (iVar4 == 2) {
                                    uVar5 = 2;
                                  }
                                  uStack_2a0 = CONCAT44(1,uVar5);
                                  uStack_2b4 = 0;
                                  uStack_2b0 = 0;
                                  uStack_2ac = 0;
                                  local_2b8 = 0x38;
                                  uStack_290 = 0;
                                  local_298 = lVar17;
                                  uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                                    (WdfDriverGlobals,param_2,&local_208,&local_2b8)
                                  ;
                                  uVar12 = (ulonglong)uVar6;
                                  if ((int)uVar6 < 0) {
                                    if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                        &WPP_RECORDER_INITIALIZED) {
                                      uVar15 = 0x1f;
                                      goto LAB_14001dff3;
                                    }
                                  }
                                  else {
                                    uStack_26c = 0;
                                    local_268 = 0x4001bde0;
                                    uStack_264 = 1;
                                    uStack_260 = 0;
                                    uStack_25c = 0;
                                    uStack_258 = 0;
                                    uStack_254 = 0;
                                    local_278 = 0x100000028;
                                    uStack_270 = 2;
                                    uVar6 = (**(code **)(WdfFunctions_01015 + 0xc30))
                                                      (WdfDriverGlobals,local_230,&local_278);
                                    uVar12 = (ulonglong)uVar6;
                                    if ((int)uVar6 < 0) {
                                      if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                          &WPP_RECORDER_INITIALIZED) {
                                        uVar15 = 0x20;
                                        goto LAB_14001dff3;
                                      }
                                    }
                                    else {
                                      *(undefined8 *)(puVar7 + 0x52) = local_230;
                                      local_230 = 0;
                                      KeInitializeSpinLock(puVar7 + 0x78);
                                      IoCsqInitialize(puVar7 + 0x68,_guard_check_icall,
                                                      _guard_check_icall,Usbd_BusEnumLogEntry);
                                      uVar6 = (**(code **)(WdfFunctions_01015 + 0x268))
                                                        (WdfDriverGlobals,param_2,
                                                         &GUID_DEVINTERFACE_USB_HOST_CONTROLLER,0);
                                      uVar12 = (ulonglong)uVar6;
                                      if ((int)uVar6 < 0) {
                                        if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                            &WPP_RECORDER_INITIALIZED) {
                                          uVar15 = 0x21;
                                          goto LAB_14001dff3;
                                        }
                                      }
                                      else {
                                        local_288 = (undefined *)0x0;
                                        local_2a8 = 0;
                                        uStack_2a4 = 0;
                                        uStack_2b4 = 0;
                                        uStack_2b0 = 0;
                                        uStack_2ac = 0;
                                        local_2b8 = 0x38;
                                        uStack_290 = 0;
                                        uStack_2a0 = 0x100000001;
                                        local_298 = lVar17;
                                        uVar6 = (**(code **)(WdfFunctions_01015 + 0x9a0))
                                                          (WdfDriverGlobals,0,&local_2b8,&local_228)
                                        ;
                                        uVar12 = (ulonglong)uVar6;
                                        if ((int)uVar6 < 0) {
                                          if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                              &WPP_RECORDER_INITIALIZED) {
                                            uVar15 = 0x22;
LAB_14001ec30:
                                            uVar3 = (undefined1)uVar6;
                                            goto LAB_14001e200;
                                          }
                                        }
                                        else {
                                          uVar6 = (**(code **)(WdfFunctions_01015 + 0x278))
                                                            (WdfDriverGlobals,param_2,
                                                             &GUID_DEVINTERFACE_USB_HOST_CONTROLLER,
                                                             0);
                                          uVar12 = (ulonglong)uVar6;
                                          if ((int)uVar6 < 0) {
                                            if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                &WPP_RECORDER_INITIALIZED) {
                                              uVar15 = 0x23;
                                              goto LAB_14001ec30;
                                            }
                                          }
                                          else {
                                            (**(code **)(WdfFunctions_01015 + 0x668))
                                                      (WdfDriverGlobals,local_228,
                                                       _UcxControllerCreate,0x451);
                                            *(undefined8 *)(puVar7 + 0x54) = local_228;
                                            uVar6 = UcxControllerGetDeviceCapabilities
                                                              (param_2,puVar7 + 0x58);
                                            uVar12 = (ulonglong)uVar6;
                                            if ((int)uVar6 < 0) {
                                              if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                  &WPP_RECORDER_INITIALIZED) {
                                                uVar15 = 0x24;
                                                goto LAB_14001dff3;
                                              }
                                            }
                                            else {
                                              puVar7[0x11e] = 0;
                                              uVar6 = Wmi_Create(param_2);
                                              uVar12 = (ulonglong)uVar6;
                                              if (-1 < (int)uVar6) {
                                                KeInitializeSpinLock(puVar7 + 0x100);
                                                puVar9 = puVar7 + 0x102;
                                                *(undefined4 **)(puVar7 + 0x104) = puVar9;
                                                *(undefined4 **)puVar9 = puVar9;
                                                KeInitializeEvent(puVar7 + 0x108,0,0);
                                                *(undefined1 *)((longlong)puVar7 + 0x472) = 1;
                                                *(undefined1 *)((longlong)puVar7 + 0x475) = 1;
                                                *(undefined1 *)(puVar7 + 0x11c) = 0;
                                                KeInitializeMutex(puVar7 + 0x10e,0);
                                                uVar3 = KeAcquireSpinLockRaiseToDpc
                                                                  (g_WdfDriverUcxContext + 0x20);
                                                plVar14 = (longlong *)(puVar7 + 6);
                                                lVar11 = g_WdfDriverUcxContext + 0x10;
                                                plVar16 = *(longlong **)
                                                           (g_WdfDriverUcxContext + 0x18);
                                                if (*plVar16 != lVar11) {
                                                  pcVar2 = (code *)swi(0x29);
                                                  (*pcVar2)(3);
                                                  puVar13 = auStackY_300;
                                                }
                                                *plVar14 = lVar11;
                                                plVar14[1] = (longlong)plVar16;
                                                *plVar16 = (longlong)plVar14;
                                                *(longlong **)(lVar11 + 8) = plVar14;
                                                *(int *)(g_WdfDriverUcxContext + 0x28) =
                                                     *(int *)(g_WdfDriverUcxContext + 0x28) + 1;
                                                lVar11 = g_WdfDriverUcxContext + 0x20;
                                                *(undefined8 *)(puVar13 + -8) = 0x14001ee30;
                                                KeReleaseSpinLock(lVar11,uVar3);
                                                *local_190 = lVar17;
                                                *(undefined8 *)(puVar13 + -8) = 0x14001ee44;
                                                Etw_UcxControllerCreate(lVar11,(longlong)puVar7);
                                                goto LAB_14001ee4e;
                                              }
                                              if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                  &WPP_RECORDER_INITIALIZED) {
                                                uVar15 = 0x25;
                                                goto LAB_14001dff3;
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
        else {
          uVar12 = Controller_SetIdStrings
                             (lVar17,(ushort *)(param_3 + 0x28),(ushort *)(param_3 + 0x2c),
                              (ushort *)(param_3 + 0x30));
          uVar6 = (uint)uVar12;
          uVar12 = uVar12 & 0xffffffff;
          if (-1 < (int)uVar6) goto LAB_14001e08f;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x11;
            goto LAB_14001dff3;
          }
        }
        puVar13 = auStackY_308;
        if (lVar17 != 0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar17);
          puVar13 = auStackY_308;
        }
      }
    }
    else {
      if ((uVar6 == 0xa0) || (uVar6 == 0xd0)) {
        memset(local_148,0,0xf8);
        local_148[1] = 0xffffffff;
        local_148[0] = 0xf8;
        local_fc = 0x7fffffff;
        local_f8 = 0x7fffffff;
        local_100 = 0;
        local_e4 = 0;
        local_df = 0;
        local_da = 0;
        local_f4 = 0;
        local_f0 = 0;
        local_e8 = 0;
        RtlStringCbCopyA(local_d5,0x28,(longlong)param_3 + 0x73);
        memmove(local_148,param_3,(ulonglong)*param_3);
        local_148[0] = 0xf8;
        param_3 = local_148;
        goto LAB_14001dd48;
      }
      uVar12 = 0xc000000d;
      puVar13 = auStackY_308;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee83;
      WPP_RECORDER_SF_PPPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      puVar13 = auStackY_308;
    }
  }
LAB_14001ee4e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(int *)(puVar13 + 0x28) = (int)uVar12;
    *(undefined **)(puVar13 + 0x20) = &WPP_930299d70c09358e97b1031e752bd63d_Traceguids;
    *(undefined8 *)(puVar13 + -8) = 0x14001ee83;
    WPP_RECORDER_SF_D(uVar1,5,1,0x26,*(undefined8 *)(puVar13 + 0x20),puVar13[0x28]);
  }
LAB_14001ee83:
  *(undefined8 *)(puVar13 + -8) = 0x14001ee94;
  return uVar12;
}



===== _UcxControllerNeedsReset @ 14001eec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxControllerNeedsReset(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x1f8),0xebe40011);
  return;
}



===== _UcxControllerNotifyTransportCharacteristicsChange @ 14001ef10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxControllerNotifyTransportCharacteristicsChange
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 **ppuVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined8 ***pppuVar5;
  undefined8 ***pppuVar6;
  bool bVar7;
  undefined8 **local_res20;
  longlong local_28;
  undefined8 ***local_20;
  undefined8 ***local_18;
  
  local_res20 = (undefined8 **)0x0;
  local_28 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  local_20 = &local_20;
  local_18 = &local_20;
  while( true ) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x4e0),&local_res20);
    if (iVar3 < 0) break;
    pppuVar5 = (undefined8 ***)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res20,
                          PTR__WDF_TRANSPORT_NOTIFY_CHANGE_REQUEST_CONTEXT_TYPE_INFO_14002da60);
    if ((undefined8 ****)*local_18 != &local_20) goto LAB_14001f0d0;
    pppuVar5[1] = local_18;
    *pppuVar5 = &local_20;
    *local_18 = pppuVar5;
    local_18 = pppuVar5;
  }
  if (&local_20 != (undefined8 ****)local_20) {
    pppuVar5 = local_20;
    pppuVar6 = (undefined8 ***)*local_20;
    do {
      if (((undefined8 ***)pppuVar6[1] != pppuVar5) ||
         (ppuVar1 = pppuVar5[1], (undefined8 ***)*ppuVar1 != pppuVar5)) {
LAB_14001f0d0:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      *ppuVar1 = pppuVar6;
      pppuVar6[1] = ppuVar1;
      local_res20 = pppuVar5[2];
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,local_res20,0x20,&local_28,0);
      if (iVar3 < 0) {
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res20);
      }
      *(undefined4 *)(local_28 + 8) = 1;
      *(undefined4 *)(local_28 + 0xc) = *param_3;
      *(undefined8 *)(local_28 + 0x10) = *(undefined8 *)(param_3 + 2);
      *(undefined8 *)(local_28 + 0x18) = *(undefined8 *)(param_3 + 4);
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res20,0,0x20);
      bVar7 = &local_20 != (undefined8 ****)pppuVar6;
      pppuVar5 = pppuVar6;
      pppuVar6 = (undefined8 ***)*pppuVar6;
    } while (bVar7);
  }
  return;
}



===== _UcxControllerResetComplete @ 14001f0e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UcxControllerResetComplete(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  if (*(int *)(param_3 + 4) == 0) {
    *(undefined4 *)(lVar1 + 0x3b8) = 1;
  }
  *(undefined4 *)(lVar1 + 0x3bc) = 1;
  StateMachineEngine_EventAdd((undefined8 *)(lVar1 + 0x1f8),0xebe40051);
  if (*(char *)(lVar1 + 0x475) != '\0') {
    KeWaitForSingleObject(lVar1 + 0x3c0,0,0,0,0);
  }
  return;
}



===== _UcxControllerSetIdStrings @ 14001f180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong _UcxControllerSetIdStrings
                    (undefined8 param_1,undefined8 param_2,ushort *param_3,ushort *param_4,
                    ushort *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCXCONTROLLER_PRIVCONTEXT_TYPE_INFO_14002d870
                    );
  if (*(short *)(lVar1 + 0x498) == 0) {
    uVar2 = Controller_SetIdStrings(param_2,param_3,param_4,param_5);
    uVar2 = uVar2 & 0xffffffff;
  }
  else {
    uVar2 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x29,
                       &WPP_930299d70c09358e97b1031e752bd63d_Traceguids);
    }
  }
  return uVar2;
}



===== UrbHandler_InvalidFunction @ 14001f230 =====

undefined8 UrbHandler_InvalidFunction(undefined8 param_1,longlong param_2,longlong param_3)

{
  if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
  }
  *(undefined4 *)(param_3 + 4) = 0x80000200;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  IofCompleteRequest(param_2,0);
  return 0xc000000d;
}



===== UrbHandler_NotSupported @ 14001f290 =====

undefined8 UrbHandler_NotSupported(undefined8 param_1,longlong param_2,longlong param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,10,
                       &WPP_37381017bc4f37187367ad98553ba188_Traceguids,
                       (char)*(undefined2 *)(param_3 + 2),(char)param_3);
  }
  if (param_3 == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30)) {
    *(undefined4 *)(param_3 + -0x44) = 0xabcd0000;
  }
  *(undefined4 *)(param_3 + 4) = 0xc0000e00;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_GetConfiguration @ 14001f340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_GetConfiguration
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  byte bVar10;
  
  *(undefined *)(param_3 + 0x81) = (&DAT_14002c10f)[(ulonglong)*(ushort *)(param_3 + 2) * 0x18];
  uVar8 = (ulonglong)*(ushort *)(param_3 + 2);
  bVar10 = ((&DAT_14002c10d)[uVar8 * 0x18] << 5 ^ *(byte *)(param_3 + 0x80)) & 0x60 ^
           *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar10;
  bVar5 = (&DAT_14002c10c)[uVar8 * 0x18] << 7 | bVar10 & 0x7f;
  *(byte *)(param_3 + 0x80) = bVar5;
  bVar10 = (&DAT_14002c10e)[uVar8 * 0x18];
  *(undefined4 *)(param_3 + 0x82) = 0;
  bVar10 = ((bVar5 ^ bVar10) & 3 ^ bVar5) & 0xe3;
  *(undefined2 *)(param_3 + 0x86) = *(undefined2 *)(param_3 + 0x24);
  *(byte *)(param_3 + 0x80) = bVar10;
  if ((char)bVar10 < '\0') {
    uVar6 = *(uint *)(param_3 + 0x20) | 1;
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x20) & 0xfffffffe;
  }
  *(uint *)(param_3 + 0x20) = uVar6 | 2;
  Etw_GetConfigurationUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 != 8) && (sVar2 != 9)) && (sVar2 != 10)) &&
     (((sVar2 != 0x32 && (sVar2 != 0x37)) && (sVar2 != 0x38)))) {
    if ((sVar2 == 0x39) || (sVar2 == 0x3a)) goto LAB_14001f46a;
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
  bVar10 = KeGetCurrentIrql();
  if ((bVar10 < 2) &&
     (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
      (*(int *)(param_3 + 0x24) != 0)))) {
    UCX_LockBufferPagesInUrbForDMA(param_3);
  }
LAB_14001f46a:
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar9 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar7 = IoSetCompletionRoutineEx(uVar9,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar7 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_GetInterface @ 14001f560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_GetInterface
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  byte bVar10;
  
  *(undefined *)(param_3 + 0x81) = (&DAT_14002c10f)[(ulonglong)*(ushort *)(param_3 + 2) * 0x18];
  uVar8 = (ulonglong)*(ushort *)(param_3 + 2);
  bVar10 = ((&DAT_14002c10d)[uVar8 * 0x18] << 5 ^ *(byte *)(param_3 + 0x80)) & 0x60 ^
           *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar10;
  bVar5 = (&DAT_14002c10c)[uVar8 * 0x18] << 7 | bVar10 & 0x7f;
  *(byte *)(param_3 + 0x80) = bVar5;
  bVar10 = (&DAT_14002c10e)[uVar8 * 0x18];
  *(undefined2 *)(param_3 + 0x82) = 0;
  *(undefined2 *)(param_3 + 0x84) = *(undefined2 *)(param_3 + 0x84);
  bVar10 = ((bVar5 ^ bVar10) & 3 ^ bVar5) & 0xe3;
  *(undefined2 *)(param_3 + 0x86) = *(undefined2 *)(param_3 + 0x24);
  *(byte *)(param_3 + 0x80) = bVar10;
  if ((char)bVar10 < '\0') {
    uVar6 = *(uint *)(param_3 + 0x20) | 1;
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x20) & 0xfffffffe;
  }
  *(uint *)(param_3 + 0x20) = uVar6 | 2;
  Etw_GetInterfaceUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 != 8) && (sVar2 != 9)) && (sVar2 != 10)) &&
     (((sVar2 != 0x32 && (sVar2 != 0x37)) && (sVar2 != 0x38)))) {
    if ((sVar2 == 0x39) || (sVar2 == 0x3a)) goto LAB_14001f699;
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
  bVar10 = KeGetCurrentIrql();
  if ((bVar10 < 2) &&
     (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
      (*(int *)(param_3 + 0x24) != 0)))) {
    UCX_LockBufferPagesInUrbForDMA(param_3);
  }
LAB_14001f699:
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar9 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar7 = IoSetCompletionRoutineEx(uVar9,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar7 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== UrbHandler_USBPORTStyle_Legacy_SCT_SetClearFeature @ 14001f790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UrbHandler_USBPORTStyle_Legacy_SCT_SetClearFeature
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  byte *pbVar1;
  short sVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte bVar8;
  uint uVar9;
  
  *(undefined2 *)(param_3 + 0x86) = 0;
  uVar6 = (ulonglong)*(ushort *)(param_3 + 2);
  bVar8 = ((&DAT_14002c10d)[uVar6 * 0x18] << 5 ^ *(byte *)(param_3 + 0x80)) & 0x60 ^
          *(byte *)(param_3 + 0x80);
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (&DAT_14002c10c)[uVar6 * 0x18] << 7 | bVar8 & 0x7f;
  *(byte *)(param_3 + 0x80) = bVar8;
  bVar8 = (bVar8 ^ (&DAT_14002c10e)[uVar6 * 0x18]) & 3 ^ bVar8;
  *(byte *)(param_3 + 0x80) = bVar8 & 0xe3;
  *(undefined *)(param_3 + 0x81) = (&DAT_14002c10f)[uVar6 * 0x18];
  *(undefined4 *)(param_3 + 0x24) = 0;
  uVar9 = *(uint *)(param_3 + 0x20) | 3;
  if ((bVar8 & 0x80) == 0) {
    uVar9 = *(uint *)(param_3 + 0x20) & 0xfffffffe | 2;
  }
  *(uint *)(param_3 + 0x20) = uVar9;
  Etw_SetClearFeatureUrbDispatch((char)param_2,param_3);
  if ((*(uint *)(param_3 + 0x20) & 8) != 0) {
    *(undefined2 *)(param_3 + 2) = 8;
  }
  sVar2 = *(short *)(param_3 + 2);
  if ((((sVar2 != 8) && (sVar2 != 9)) && (sVar2 != 10)) &&
     (((sVar2 != 0x32 && (sVar2 != 0x37)) && (sVar2 != 0x38)))) {
    if ((sVar2 == 0x39) || (sVar2 == 0x3a)) goto LAB_14001f8ad;
  }
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) & 0xdfffffff;
  bVar8 = KeGetCurrentIrql();
  if ((bVar8 < 2) &&
     (((*(longlong *)(param_3 + 0x30) == 0 && (*(longlong *)(param_3 + 0x28) != 0)) &&
      (*(int *)(param_3 + 0x24) != 0)))) {
    UCX_LockBufferPagesInUrbForDMA(param_3);
  }
LAB_14001f8ad:
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
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
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar5 = IoSetCompletionRoutineEx(uVar7,param_2,Urb_LegacyTransferUrbCompletion,param_3,1,1,1);
  if (iVar5 < 0) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Urb_LegacyTransferUrbCompletion;
    *(longlong *)(lVar4 + -8) = param_3;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  (**(code **)(WdfFunctions_01015 + 0xc90))(WdfDriverGlobals,param_1,param_2,param_4,2);
  return 0x103;
}



===== StateMachineEngine_OnPassive @ 14001f9a0 =====

void StateMachineEngine_OnPassive(undefined8 param_1,undefined8 *param_2)

{
  StateMachineEngine_EventAdd(param_2,0xebe0000f);
  return;
}



===== ControllerResetEventHandler_FailResetFromHub @ 14001f9c0 =====

undefined8 ControllerResetEventHandler_FailResetFromHub(longlong param_1)

{
  RootHub_CompleteAsyncReset(*(longlong *)(param_1 + 0x158),0xc000000e);
  return 0;
}



===== ControllerResetEventHandler_UnblockControllerResetComplete @ 14001f9f0 =====

undefined8 ControllerResetEventHandler_UnblockControllerResetComplete(longlong param_1)

{
  KeSetEvent(param_1 + 0x3c0,0,0);
  return 0;
}



===== ControllerResetStateEntryFunc_CallHCDToReset2 @ 14001fa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerResetStateEntryFunc_CallHCDToReset2(longlong param_1)

{
  (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x28));
  return 0;
}



===== ControllerResetStateEntryFunc_CompletePendedDeviceMgmtRequests @ 14001fa40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerResetStateEntryFunc_CompletePendedDeviceMgmtRequests(longlong param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x138));
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_CompleteResetFromHub @ 14001fa80 =====

undefined8 ControllerResetStateEntryFunc_CompleteResetFromHub(longlong param_1)

{
  RootHub_CompleteAsyncReset(*(longlong *)(param_1 + 0x158),0);
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_NotifyUsbDevicesAndEndpointsOfResetComplete2 @ 14001fab0 =====

undefined8
ControllerResetStateEntryFunc_NotifyUsbDevicesAndEndpointsOfResetComplete2
          (longlong param_1,undefined8 param_2)

{
  Controller_NotifyUsbDevicesAndEndpointsOfControllerResetComplete(param_1,param_2);
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_PrepareForReset @ 14001facc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerResetStateEntryFunc_PrepareForReset(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  
  (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x138),0,0);
  lVar1 = param_1 + 0x3e0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x3f0) = 1;
  KeReleaseSpinLock(lVar1,uVar5);
  RootHub_StartFailingRootHubIO(*(longlong *)(param_1 + 0x158));
  iVar4 = *(int *)(param_1 + 1000);
  LOCK();
  piVar2 = (int *)(param_1 + 0x3ec);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if ((*(char *)(param_1 + 0x3f1) == '\0') && (iVar4 == *(int *)(param_1 + 1000))) {
      *(undefined1 *)(param_1 + 0x3f1) = 1;
      KeReleaseSpinLock(lVar1,uVar5);
      StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40031);
    }
    else {
      KeReleaseSpinLock(lVar1,uVar5);
    }
  }
  return 0;
}



===== ControllerResetStateEntryFunc_PrepareForReset1 @ 14001fbd0 =====

void ControllerResetStateEntryFunc_PrepareForReset1(longlong param_1)

{
  ControllerResetStateEntryFunc_PrepareForReset(param_1);
  return;
}



===== ControllerResetStateEntryFunc_RhPdoInDx_PrepareUsbDevicesAndEndpointsForReset @ 14001fbf0 =====

undefined8
ControllerResetStateEntryFunc_RhPdoInDx_PrepareUsbDevicesAndEndpointsForReset
          (longlong param_1,undefined8 param_2)

{
  Controller_PrepareUsbDevicesAndEndpointsForControllerReset(param_1,param_2);
  return 0;
}



===== ControllerResetStateEntryFunc_ResetComplete3 @ 14001fc10 =====

undefined8 ControllerResetStateEntryFunc_ResetComplete3(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x3e0);
  *(int *)(param_1 + 1000) = *(int *)(param_1 + 1000) + 1;
  *(undefined2 *)(param_1 + 0x3f0) = 0;
  LOCK();
  *(int *)(param_1 + 0x3ec) = *(int *)(param_1 + 0x3ec) + 1;
  UNLOCK();
  KeReleaseSpinLock(param_1 + 0x3e0,uVar1);
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_ResumeRootHubIO1 @ 14001fc70 =====

undefined8 ControllerResetStateEntryFunc_ResumeRootHubIO1(longlong param_1)

{
  RootHub_ResumeRootHubIO(*(longlong *)(param_1 + 0x158));
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_RhPdoInDx_SimulatePortChanged2 @ 14001fca0 =====

undefined8 ControllerResetStateEntryFunc_RhPdoInDx_SimulatePortChanged2(longlong param_1)

{
  RootHub_PortChanged(*(longlong *)(param_1 + 0x158));
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_RhPdoInDx_UnblockControllerResetComplete @ 14001fcd0 =====

undefined8 ControllerResetStateEntryFunc_RhPdoInDx_UnblockControllerResetComplete(longlong param_1)

{
  KeSetEvent(param_1 + 0x3c0,0,0);
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_StartFailingRootHubRequests1 @ 14001fd00 =====

undefined8 ControllerResetStateEntryFunc_StartFailingRootHubRequests1(longlong param_1)

{
  RootHub_StartFailingRootHubIO(*(longlong *)(param_1 + 0x158));
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_StartPendingDeviceMgmtRequests @ 14001fd30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerResetStateEntryFunc_StartPendingDeviceMgmtRequests(longlong param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x138),0,0);
  return 0xebe40042;
}



===== ControllerResetStateEntryFunc_WaitingForResetFromHub @ 14001fd70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ControllerResetStateEntryFunc_WaitingForResetFromHub(longlong param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x138));
  return 0;
}



===== UcxEndpointEventHandler_OkToResetController @ 14001fdb0 =====

undefined8 UcxEndpointEventHandler_OkToResetController(longlong param_1)

{
  Endpoint_OkToResetController(param_1);
  return 0;
}



===== UcxEndpointStateEntryFunc_CompletingDisableStaticStreamsIrp1 @ 14001fdd0 =====

undefined8 UcxEndpointStateEntryFunc_CompletingDisableStaticStreamsIrp1(longlong param_1)

{
  UcxEndpoint_CompleteDisableStaticStreamsIrp(param_1);
  return 0xebe300c2;
}



===== UcxEndpointStateEntryFunc_CompletingDisableStaticStreamsWdfRequest2 @ 14001fdf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_CompletingDisableStaticStreamsWdfRequest2(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(WdfFunctions_01015 + 0x8c8))
            (WdfDriverGlobals,uVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x138));
  return 0;
}



===== UcxEndpointStateEntryFunc_CompletingEnableStaticStreamsIrp1 @ 14001fe40 =====

undefined8 UcxEndpointStateEntryFunc_CompletingEnableStaticStreamsIrp1(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  if (*(int *)(lVar1 + 0x30) < 0) {
    LOCK();
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
    UNLOCK();
  }
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0xb8) + 8);
  if (lVar2 == *(longlong *)(*(longlong *)(lVar1 + 0xb8) + 0x30)) {
    *(undefined4 *)(lVar2 + -0x44) = 0xabcd0000;
  }
  IofCompleteRequest(lVar1,0);
  return 0xebe300c2;
}



===== UcxEndpointStateEntryFunc_CompletingPendingTreePurge @ 14001fea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_CompletingPendingTreePurge(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x490);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x488),0);
    *(undefined8 *)(lVar3 + 0x488) = 0;
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x140));
  }
  return 0xebe300c2;
}



===== UcxEndpointStateEntryFunc_DisablingStaticStreams @ 14001ff20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_DisablingStaticStreams(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(param_1 + 0xa0))
            (*(undefined8 *)(param_1 + 8),*(undefined8 *)(*(longlong *)(param_1 + 0x50) + 8),uVar1);
  return 0;
}



===== UcxEndpointStateEntryFunc_FailingEnableStaticStreamsIrp @ 14001ff60 =====

undefined8 UcxEndpointStateEntryFunc_FailingEnableStaticStreamsIrp(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  LOCK();
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
  UNLOCK();
  *(undefined8 *)(lVar1 + 0x38) = 0;
  *(undefined4 *)(lVar1 + 0x30) = 0xc0000184;
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0xb8) + 8);
  if (lVar2 == *(longlong *)(*(longlong *)(lVar1 + 0xb8) + 0x30)) {
    *(undefined4 *)(lVar2 + -0x44) = 0xabcd0000;
  }
  IofCompleteRequest(lVar1,0);
  return 0xebe300c2;
}



===== UcxEndpointStateEntryFunc_FailingEndpointResetWdfRequest @ 14001ffc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_FailingEndpointResetWdfRequest(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,0xc000000e);
  return 0;
}



===== UcxEndpointStateEntryFunc_IsDeprogrammedDueToControllerReset4 @ 140020010 =====

int UcxEndpointStateEntryFunc_IsDeprogrammedDueToControllerReset4(longlong param_1)

{
  return (-(uint)(*(char *)(*(longlong *)(param_1 + 0x48) + 0x19e) != '\0') & 0xf0) + 0xebe300b2;
}



===== UcxEndpointStateEntryFunc_IsDeprogrammedDueToControllerResetOrDisconnected @ 140020030 =====

undefined8
UcxEndpointStateEntryFunc_IsDeprogrammedDueToControllerResetOrDisconnected(longlong param_1)

{
  undefined8 uVar1;
  
  if ((*(char *)(*(longlong *)(param_1 + 0x48) + 0x19e) != '\0') ||
     (uVar1 = 0xebe300b2, *(char *)(*(longlong *)(param_1 + 0x48) + 0x19c) != '\0')) {
    uVar1 = 0xebe301a2;
  }
  return uVar1;
}



===== UcxEndpointStateEntryFunc_Purging2 @ 140020060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_Purging2(longlong param_1)

{
  (**(code **)(param_1 + 0x68))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28),*(undefined8 *)(param_1 + 8));
  return 0xebe300c2;
}



===== UcxEndpointStateEntryFunc_RejectingEnableStaticStreamsWdfRequest2 @ 140020090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UcxEndpointStateEntryFunc_RejectingEnableStaticStreamsWdfRequest2(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,0xc0000184);
  return 0;
}



===== UcxEndpoint_CompleteDisableStaticStreamsIrp @ 1400200d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UcxEndpoint_CompleteDisableStaticStreamsIrp(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x2c8);
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  lVar2 = *(longlong *)(param_1 + 0x50);
  uVar4 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + 0x1e8);
  *(undefined8 *)(param_1 + 0x50) = 0;
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + 0x1e8,uVar4);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8));
  LOCK();
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
  UNLOCK();
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  lVar3 = *(longlong *)(lVar2 + 8);
  if (lVar3 == *(longlong *)(lVar2 + 0x30)) {
    *(undefined4 *)(lVar3 + -0x44) = 0xabcd0000;
  }
  IofCompleteRequest(lVar1,0);
  return;
}



===== Usbd_BusGetUSBDIVersion @ 140020190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Usbd_BusGetUSBDIVersion(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  uVar1 = *(uint *)(lVar3 + 0x10c);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x600;
    uVar2 = 0x110;
    if (1 < uVar1) {
      uVar2 = 0x200;
    }
    param_2[1] = uVar2;
  }
  return;
}



===== Usbd_BusQueryBusInformation @ 140020210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
Usbd_BusQueryBusInformation
          (undefined8 param_1,int param_2,undefined8 *param_3,uint *param_4,uint *param_5)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  ulonglong local_38;
  void *pvStack_30;
  
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
  ;
  lVar1 = *(longlong *)(lVar3 + 0x18);
  if ((2 < *(uint *)(lVar3 + 0x10c)) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,10,
                     &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids);
  }
  if (*(longlong *)(lVar1 + 0x40) == 0) {
    if (param_2 == 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xc,
                          &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids,(char)param_1);
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = 8;
      }
      uVar6 = *param_4;
      if (7 < uVar6) {
        *param_4 = 8;
        *param_3 = 4000000;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000023;
      }
      uVar2 = 8;
      uVar5 = 0xd;
    }
    else {
      if (param_2 != 1) goto LAB_14002044d;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xe,
                          &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids,(char)param_1);
      }
      (**(code **)(WdfFunctions_01015 + 0x9a8))
                (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x150),&local_38);
      uVar2 = (ushort)local_38 + 0x10;
      if (param_5 != (uint *)0x0) {
        *param_5 = uVar2;
      }
      uVar6 = *param_4;
      if (uVar2 <= uVar6) {
        *param_4 = uVar2;
        *(uint *)(param_3 + 1) = (uint)(ushort)local_38;
        *param_3 = 4000000;
        memmove((void *)((longlong)param_3 + 0xc),pvStack_30,local_38 & 0xffff);
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000023;
      }
      uVar5 = 0xf;
    }
    uVar4 = 0xc0000023;
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,uVar5,
                       &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids,(char)uVar6,(char)uVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xb,
                       &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids);
    }
LAB_14002044d:
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



===== Usbd_BusQueryBusTimeEx @ 140020480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Usbd_BusQueryBusTimeEx(undefined8 param_1,undefined4 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar3 = 0x11;
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,
                       PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
    if (1 < *(uint *)(lVar1 + 0x10c)) {
      *param_2 = 0;
      return 0;
    }
    uVar2 = 0xc00000bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc00000bb;
    }
    uVar3 = 0x12;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,uVar3,
                   &WPP_33fdbe15f4823482ead494a8715a2682_Traceguids);
  return uVar2;
}



===== Usbd_BusSubmitIsoOutUrb @ 140020540 =====

undefined8 Usbd_BusSubmitIsoOutUrb(void)

{
  return 0xc00000bb;
}



===== Usbd_QueryControllerType @ 140020550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
Usbd_QueryControllerType
          (undefined8 param_1,undefined4 *param_2,undefined2 *param_3,undefined2 *param_4,
          undefined1 *param_5,undefined1 *param_6,undefined1 *param_7,undefined1 *param_8)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(uint *)(lVar2 + 0x10c) < 2) {
    uVar3 = 0;
    uVar1 = 0x2c3;
  }
  else {
    uVar3 = 0x20;
    uVar1 = 0x80a95;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(*(longlong *)(lVar2 + 0x18) + 0x7c);
  }
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = *(undefined2 *)(*(longlong *)(lVar2 + 0x18) + 0x80);
  }
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = 0xc;
  }
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = 3;
  }
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = *(undefined1 *)(*(longlong *)(lVar2 + 0x18) + 0x84);
  }
  if (param_8 != (undefined1 *)0x0) {
    *param_8 = uVar3;
  }
  return 0;
}



===== StaticStreams_Create @ 14002062c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong StaticStreams_Create(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_34 = 0;
  uStack_30 = 0;
  local_28 = *(undefined8 *)(param_1 + 8);
  local_2c = 0;
  local_1c = 0;
  local_14 = 0;
  local_38 = 0x696d7353;
  local_20 = (undefined4)param_2;
  uVar2 = (**(code **)(param_1 + 0x90))(local_28,param_2,&local_38);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,10,
                        &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)uVar2);
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,CONCAT44(local_2c,uStack_30),
                       PTR__WDF_UCXSSTREAMS_PRIVCONTEXT_TYPE_INFO_14002d9e8);
    *(undefined8 *)(lVar3 + 0x18) = 0;
    if (local_1c._4_1_ == '\0') {
      uVar5 = 0;
      while( true ) {
        if (*(uint *)(lVar3 + 4) <= (uint)uVar5) {
          *param_3 = CONCAT44(local_2c,uStack_30);
          return uVar4;
        }
        if (*(int *)(*(longlong *)(lVar3 + 0x20) + uVar5 * 0x48) != 0x6d727453) break;
        uVar5 = (ulonglong)((uint)uVar5 + 1);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xc,
                          &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)lVar3);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xb,
                        &WPP_25b85e0e005e3e7e5e9e6c5048ae668f_Traceguids,(char)lVar3);
    }
    uVar4 = 0xc00000e5;
    if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x3f9) != '\0') {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  *param_3 = 0;
  if (CONCAT44(local_2c,uStack_30) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar4;
}



===== SystemPowerState_To_WdmUsbPowerState @ 140020808 =====

undefined8 SystemPowerState_To_WdmUsbPowerState(int param_1)

{
  if (param_1 == 1) {
    return 0x65;
  }
  if (param_1 == 2) {
    return 0x66;
  }
  if (param_1 == 3) {
    return 0x67;
  }
  if (param_1 == 4) {
    return 0x68;
  }
  if (param_1 == 5) {
    return 0x69;
  }
  if (param_1 == 6) {
    return 0x6a;
  }
  return 0;
}



===== USBPORTStyle_MapCanWakeAndIsPowered @ 14002085c =====

void USBPORTStyle_MapCanWakeAndIsPowered(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(param_2 + 0x10 + (longlong)param_3 * 4);
  if (*(int *)(param_2 + 0x2c) < param_3) {
    bVar2 = false;
    bVar3 = true;
    if ((uVar1 & 0xfffffffb) == 0) {
      bVar3 = false;
    }
  }
  else {
    bVar3 = uVar1 != 0;
    bVar2 = bVar3;
  }
  *(bool *)(param_1 + 0x20) = bVar2;
  *(bool *)(param_1 + 0x21) = bVar3;
  return;
}



===== USBPORTStyle_MapPowerStateInformation @ 140020894 =====

void USBPORTStyle_MapPowerStateInformation
               (int *param_1,longlong param_2,longlong param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_3 + 0x38);
  iVar3 = 0;
  iVar5 = 0xcc;
  iVar4 = 200;
  if (iVar1 == 0) {
    iVar1 = 200;
  }
  else if (iVar1 == 1) {
    iVar1 = 0xc9;
  }
  else if (iVar1 == 2) {
    iVar1 = 0xca;
  }
  else if (iVar1 == 3) {
    iVar1 = 0xcb;
  }
  else if (iVar1 == 4) {
    iVar1 = 0xcc;
  }
  else {
    iVar1 = 0;
  }
  param_1[5] = iVar1;
  uVar2 = SystemPowerState_To_WdmUsbPowerState(*(int *)(param_3 + 0x3c));
  param_1[6] = (int)uVar2;
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 == 0) {
    iVar1 = iVar4;
  }
  else if (iVar1 == 1) {
    iVar1 = 0xc9;
  }
  else if (iVar1 == 2) {
    iVar1 = 0xca;
  }
  else if (iVar1 == 3) {
    iVar1 = 0xcb;
  }
  else if (iVar1 == 4) {
    iVar1 = iVar5;
  }
  else {
    iVar1 = iVar3;
  }
  param_1[2] = iVar1;
  uVar2 = SystemPowerState_To_WdmUsbPowerState(*(int *)(param_2 + 0x2c));
  iVar1 = *param_1;
  param_1[3] = (int)uVar2;
  if (iVar1 == 0x65) {
    iVar1 = *(int *)(param_3 + 0x20);
    if (iVar1 == 0) {
      iVar1 = iVar4;
    }
    else if (iVar1 == 1) {
      iVar1 = 0xc9;
    }
    else if (iVar1 == 2) {
      iVar1 = 0xca;
    }
    else if (iVar1 == 3) {
      iVar1 = 0xcb;
    }
    else if (iVar1 == 4) {
      iVar1 = iVar5;
    }
    else {
      iVar1 = iVar3;
    }
    param_1[4] = iVar1;
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar4 = 0xc9;
      }
      else if (iVar1 == 2) {
        iVar4 = 0xca;
      }
      else if (iVar1 == 3) {
        iVar4 = 0xcb;
      }
      else {
        iVar4 = iVar5;
        if (iVar1 != 4) {
          iVar4 = iVar3;
        }
      }
    }
    param_1[1] = iVar4;
    *(short *)(param_1 + 8) = (short)iVar3;
  }
  else {
    if (iVar1 == 0x66) {
      iVar1 = *(int *)(param_3 + 0x24);
      if (iVar1 == 0) {
        iVar1 = iVar4;
      }
      else if (iVar1 == 1) {
        iVar1 = 0xc9;
      }
      else if (iVar1 == 2) {
        iVar1 = 0xca;
      }
      else if (iVar1 == 3) {
        iVar1 = 0xcb;
      }
      else if (iVar1 == 4) {
        iVar1 = iVar5;
      }
      else {
        iVar1 = iVar3;
      }
      param_1[4] = iVar1;
      iVar1 = *(int *)(param_2 + 0x18);
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          iVar4 = 0xc9;
        }
        else if (iVar1 == 2) {
          iVar4 = 0xca;
        }
        else if (iVar1 == 3) {
          iVar4 = 0xcb;
        }
        else {
          iVar4 = iVar3;
          if (iVar1 == 4) {
            iVar4 = iVar5;
          }
        }
      }
      iVar1 = 2;
    }
    else if (iVar1 == 0x67) {
      iVar1 = *(int *)(param_3 + 0x28);
      if (iVar1 == 0) {
        iVar1 = iVar4;
      }
      else if (iVar1 == 1) {
        iVar1 = 0xc9;
      }
      else if (iVar1 == 2) {
        iVar1 = 0xca;
      }
      else if (iVar1 == 3) {
        iVar1 = 0xcb;
      }
      else if (iVar1 == 4) {
        iVar1 = iVar5;
      }
      else {
        iVar1 = iVar3;
      }
      param_1[4] = iVar1;
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          iVar4 = 0xc9;
        }
        else if (iVar1 == 2) {
          iVar4 = 0xca;
        }
        else if (iVar1 == 3) {
          iVar4 = 0xcb;
        }
        else {
          iVar4 = iVar3;
          if (iVar1 == 4) {
            iVar4 = iVar5;
          }
        }
      }
      iVar1 = 3;
    }
    else if (iVar1 == 0x68) {
      iVar1 = *(int *)(param_3 + 0x2c);
      if (iVar1 == 0) {
        iVar1 = iVar4;
      }
      else if (iVar1 == 1) {
        iVar1 = 0xc9;
      }
      else if (iVar1 == 2) {
        iVar1 = 0xca;
      }
      else if (iVar1 == 3) {
        iVar1 = 0xcb;
      }
      else if (iVar1 == 4) {
        iVar1 = iVar5;
      }
      else {
        iVar1 = iVar3;
      }
      param_1[4] = iVar1;
      iVar1 = *(int *)(param_2 + 0x20);
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          iVar4 = 0xc9;
        }
        else if (iVar1 == 2) {
          iVar4 = 0xca;
        }
        else if (iVar1 == 3) {
          iVar4 = 0xcb;
        }
        else {
          iVar4 = iVar3;
          if (iVar1 == 4) {
            iVar4 = iVar5;
          }
        }
      }
      iVar1 = 4;
    }
    else {
      if (iVar1 != 0x69) goto LAB_140020bcf;
      iVar1 = *(int *)(param_3 + 0x30);
      if (iVar1 == 0) {
        iVar1 = iVar4;
      }
      else if (iVar1 == 1) {
        iVar1 = 0xc9;
      }
      else if (iVar1 == 2) {
        iVar1 = 0xca;
      }
      else if (iVar1 == 3) {
        iVar1 = 0xcb;
      }
      else if (iVar1 == 4) {
        iVar1 = iVar5;
      }
      else {
        iVar1 = iVar3;
      }
      param_1[4] = iVar1;
      iVar1 = *(int *)(param_2 + 0x24);
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          iVar4 = 0xc9;
        }
        else if (iVar1 == 2) {
          iVar4 = 0xca;
        }
        else if (iVar1 == 3) {
          iVar4 = 0xcb;
        }
        else {
          iVar4 = iVar3;
          if (iVar1 == 4) {
            iVar4 = iVar5;
          }
        }
      }
      iVar1 = 5;
    }
    param_1[1] = iVar4;
    USBPORTStyle_MapCanWakeAndIsPowered((longlong)param_1,param_2,iVar1);
  }
LAB_140020bcf:
  uVar2 = SystemPowerState_To_WdmUsbPowerState(param_4);
  param_1[7] = (int)uVar2;
  return;
}



===== USBPORTStyle_UsbFdoUserIoctl @ 140020bfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBPORTStyle_UsbFdoUserIoctl
              (undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4,
              uint *param_5)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *local_res18;
  
  local_res18 = (uint *)0x0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
  lVar4 = *(longlong *)(lVar4 + 8);
  if (param_4 != param_3) {
    return -0x3ffffff3;
  }
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x10,&local_res18,0);
  puVar2 = local_res18;
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xe,
                        &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,(char)iVar3);
    }
    return -0x3fffffdd;
  }
  uVar6 = local_res18[2];
  local_res18[3] = 0x10;
  local_res18[1] = 0;
  *param_5 = 0x10;
  if (uVar6 != param_3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xf,
                         &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,(char)uVar6,(char)param_3)
      ;
    }
    puVar2[1] = 4;
    return iVar3;
  }
  uVar6 = *local_res18;
  uVar8 = 8;
  if (uVar6 < 9) {
    if (uVar6 == 8) {
      uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x10);
      if ((char)uVar5 == '\0') {
        return iVar3;
      }
      local_res18[4] = 4;
      local_res18[5] = 0x600;
      local_res18[6] = 4;
      *(undefined2 *)(local_res18 + 7) = 0;
      puVar2[3] = 0x20;
      goto LAB_14002108f;
    }
    if (uVar6 != 1) {
      if (uVar6 == 2) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,6);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        USBPORTStyle_UserGetControllerKey
                  (param_1,(longlong)puVar2,(int *)(local_res18 + 4),(int)param_3 - 0x10);
        goto LAB_14002108f;
      }
      if (uVar6 == 3) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x18);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        uVar6 = local_res18[8];
        if (uVar6 < 0x10001) {
          if (puVar2[2] < uVar6 + 0x24) {
            puVar2[1] = 7;
          }
          else {
            puVar2[1] = 6;
            puVar2[3] = uVar6 + 0x28;
          }
        }
        else {
          puVar2[1] = 5;
        }
        goto LAB_14002108f;
      }
      if (uVar6 == 4) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x22);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        lVar1 = *(longlong *)(lVar4 + 0x158);
        if (*(char *)(lVar1 + 0x178) == '\0') {
          puVar2[1] = 9;
        }
        else {
          USBPORTStyle_MapPowerStateInformation
                    ((int *)(local_res18 + 4),lVar4 + 0x160,lVar1 + 0x108,*(int *)(lVar1 + 0x188));
        }
        puVar2[3] = 0x32;
        goto LAB_14002108f;
      }
      if (uVar6 == 5) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x2c);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        local_res18[4] = 0;
        local_res18[5] = 0;
        local_res18[6] = 0;
        local_res18[7] = 0;
        local_res18[8] = 0;
        local_res18[9] = 0;
        local_res18[10] = 0;
        local_res18[0xb] = 0;
        local_res18[0xc] = 0;
        local_res18[0xd] = 0;
        local_res18[0xd] = 0;
        local_res18[0xe] = 0;
        local_res18[0xe] = 0;
        local_res18[4] = 0;
        local_res18[5] = 0x6d600;
        local_res18[6] = 0xdac000;
        local_res18[7] = 0x2bc000;
        local_res18[8] = 0;
        local_res18[9] = 0;
        local_res18[10] = 0;
        local_res18[0xb] = 0;
        local_res18[0xc] = 0;
        puVar2[3] = 0x3c;
        goto LAB_14002108f;
      }
      if (uVar6 == 6) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x38);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        USBPORTStyle_UserGetBusStatistics0(lVar4,(longlong)puVar2,local_res18 + 4);
        goto LAB_14002108f;
      }
      if (uVar6 == 7) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,6);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        USBPORTStyle_UserGetRootHubName
                  (*(longlong *)(lVar4 + 0x158),(longlong)puVar2,(int *)(local_res18 + 4),
                   (int)param_3 - 0x10);
        goto LAB_14002108f;
      }
LAB_140021036:
      local_res18[1] = 2;
      goto LAB_14002108f;
    }
    uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x18);
    if ((char)uVar5 == '\0') {
      return iVar3;
    }
    if (((*(longlong *)(lVar4 + 0x110) == 0) || (*(longlong *)(lVar4 + 0x118) == 0)) ||
       (*(longlong *)(lVar4 + 0x120) == 0)) {
      uVar8 = 0;
    }
    local_res18[9] = uVar8;
    local_res18[7] = *(uint *)(*(longlong *)(lVar4 + 0x158) + 0xd0);
    local_res18[4] = *(uint *)(lVar4 + 0x7c);
    local_res18[5] = *(uint *)(lVar4 + 0x80);
    local_res18[6] = (uint)*(ushort *)(lVar4 + 0x84);
    local_res18[8] = *(uint *)(lVar4 + 0x478);
  }
  else {
    if (uVar6 != 10) {
      if (uVar6 == 0x10000001) {
        uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,0x20);
        if ((char)uVar5 == '\0') {
          return iVar3;
        }
        puVar2[1] = 4;
        goto LAB_14002108f;
      }
      if (uVar6 == 0x20000001) {
        iVar7 = 4;
      }
      else {
        if (((uVar6 != 0x20000005) && (uVar6 != 0x20000006)) && (uVar6 != 0x20000007))
        goto LAB_140021036;
        iVar7 = 6;
      }
      uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,iVar7);
      if ((char)uVar5 == '\0') {
        return iVar3;
      }
      puVar2[1] = 3;
      goto LAB_14002108f;
    }
    uVar5 = UsbUserIoctl_CheckAndSetParamLength((longlong)local_res18,4);
    if ((char)uVar5 == '\0') {
      return iVar3;
    }
  }
  puVar2[1] = 0;
LAB_14002108f:
  uVar6 = puVar2[2];
  if (puVar2[3] < puVar2[2]) {
    uVar6 = puVar2[3];
  }
  *param_5 = uVar6;
  return iVar3;
}



===== USBPORTStyle_UserGetBusStatistics0 @ 1400210c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong USBPORTStyle_UserGetBusStatistics0(longlong param_1,longlong param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  
  *param_3 = *(undefined4 *)(param_1 + 0x1f0);
  *(undefined8 *)(param_3 + 1) = _DAT_fffff78000000014;
  if (*(longlong *)(param_1 + 0x48) != 0) {
    LOCK();
    *(int *)(param_1 + 0x3ec) = *(int *)(param_1 + 0x3ec) + 1;
    UNLOCK();
    piVar1 = (int *)(param_1 + 1000);
    if (*(char *)(param_1 + 0x3f0) == '\0') {
      bVar6 = true;
    }
    else {
      iVar3 = *piVar1;
      bVar6 = false;
      LOCK();
      piVar2 = (int *)(param_1 + 0x3ec);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        lVar10 = param_1 + 0x3e0;
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar10);
        if ((*(char *)(param_1 + 0x3f1) == '\0') && (iVar3 == *piVar1)) {
          *(undefined1 *)(param_1 + 0x3f1) = 1;
          KeReleaseSpinLock(lVar10,uVar7);
          StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock(lVar10);
        }
      }
    }
    if (bVar6) {
      iVar8 = (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x28));
      iVar4 = *piVar1;
      *(undefined4 *)(param_1 + 0x3d8) = param_3[3];
      LOCK();
      piVar2 = (int *)(param_1 + 0x3ec);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x3e0);
        if ((*(char *)(param_1 + 0x3f1) == '\0') && (iVar4 == *piVar1)) {
          *(undefined1 *)(param_1 + 0x3f1) = 1;
          KeReleaseSpinLock(param_1 + 0x3e0,uVar7);
          StateMachineEngine_EventAdd((undefined8 *)(param_1 + 0x1f8),0xebe40031);
        }
        else {
          KeReleaseSpinLock();
        }
      }
    }
    else {
      uVar5 = *(undefined4 *)(param_1 + 0x3d8);
      iVar8 = 0;
      param_3[3] = uVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400212b0;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xb,
                        &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,(char)uVar5);
    }
    if (-1 < iVar8) goto LAB_1400212b0;
  }
  uVar9 = *(int *)(param_1 + 0x47c) + 1U & 0x7ff;
  *(uint *)(param_1 + 0x47c) = uVar9;
  param_3[3] = uVar9;
LAB_1400212b0:
  *(undefined8 *)(param_3 + 9) = 0;
  param_3[0xc] = 0;
  *(undefined2 *)(param_3 + 0xd) = 0x400;
  lVar10 = *(longlong *)(param_1 + 0x158);
  if (*(char *)(lVar10 + 0x178) != '\0') {
    *(undefined1 *)(param_3 + 0xd) = 1;
    lVar10 = CONCAT71((int7)((ulonglong)lVar10 >> 8),-*(char *)(param_1 + 0x474));
    *(byte *)((longlong)param_3 + 0x35) = ~-(*(char *)(param_1 + 0x474) != '\0') & 2;
  }
  *(undefined8 *)(param_3 + 4) = 0;
  *(undefined8 *)(param_3 + 6) = 0;
  param_3[0xb] = 0;
  param_3[8] = 1;
  *(undefined4 *)(param_2 + 0xc) = 0x48;
  return lVar10;
}



===== UsbUserIoctl_CheckAndSetParamLength @ 140021324 =====

ulonglong UsbUserIoctl_CheckAndSetParamLength(longlong param_1,int param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = (ulonglong)uVar1;
  uVar3 = param_2 + 0x10;
  *(uint *)(param_1 + 0xc) = uVar3;
  if (uVar1 < uVar3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,10,
                                 &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,(char)uVar3,
                                 (char)uVar1);
    }
    *(undefined4 *)(param_1 + 4) = 7;
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
  return uVar2;
}



===== WPP_RECORDER_SF_ddqd @ 140021394 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,0xc,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_f4e80384c62a328ce6d2fbb541f7a1fb_Traceguids,0xc,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== LogWppMsgForCloseStaticStreamOnDx @ 1400214a8 =====

void LogWppMsgForCloseStaticStreamOnDx(undefined1 param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x26,
                       &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,param_1,0);
  }
  return;
}



===== WPP_RECORDER_SF_ddq @ 1400214fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,0x10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,0x10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_dqq @ 1400215f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,param_4,&param_6,4,
                  &param_7,8,&param_8,8,0);
  return;
}



===== Xrb_AsyncNotificationRequestDuringEndpointOffloadAllocate @ 1400216f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400217eb) */

int Xrb_AsyncNotificationRequestDuringEndpointOffloadAllocate
              (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  *param_4 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0x100000001;
  local_48 = *(undefined8 *)(param_1 + 0x28);
  uStack_40 = 0;
  uStack_60 = 0;
  local_68 = 0x38;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_68,ExDefaultNonPagedPoolType,
                     *(undefined4 *)(param_1 + 0x10));
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x15,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_1,(char)iVar3)
      ;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x267);
    memset((void *)0x0,0,0xe8);
    uRam000000000000004c = 0x2e425258;
    uRam0000000000000000 = 0xe8;
    uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
    uRam000000000000000c = 0xabcd0000;
    uRam0000000000000008 = 0xaabb0000;
    uRam0000000000000020 = 0;
    uRam0000000000000050 = 0x98;
    uRam0000000000000052 = 0x3c;
    uRam0000000000000070 = 0;
    lRam0000000000000018 = param_1;
    uRam0000000000000068 = param_2;
    uRam0000000000000074 = param_3;
    if (*(char *)(param_1 + 0x8b) != '\0') {
      uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      puVar6 = auStackY_a8;
      lVar5 = param_1 + 0x78;
      plVar7 = *(longlong **)(param_1 + 0x80);
      plVar4 = (longlong *)0x30;
      if (*plVar7 != lVar5) {
        plVar4 = (longlong *)0x3;
        pcVar1 = (code *)swi(0x29);
        uVar2 = (*pcVar1)();
        puVar6 = auStackY_a0;
      }
      *plVar4 = lVar5;
      plVar4[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar4;
      *(longlong **)(lVar5 + 8) = plVar4;
      *(undefined8 *)(puVar6 + -8) = 0x14002194d;
      KeReleaseSpinLock(param_1 + 0x70,uVar2);
    }
    *param_4 = 0x50;
  }
  return iVar3;
}



===== Xrb_SecureIsochAllocate @ 140021980 =====

void Xrb_SecureIsochAllocate(longlong param_1,int param_2,undefined8 param_3)

{
  Xrb_IsochAllocateInternal(param_1,param_2,param_3,(undefined8 *)param_3);
  return;
}



===== Xrb_IsochAllocateInternal @ 140021998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140021a97) */

int Xrb_IsochAllocateInternal(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  *param_4 = 0;
  uVar1 = param_2 * 0xc + 0xe8;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0x100000001;
  local_48 = *(undefined8 *)(param_1 + 0x28);
  uStack_40 = 0;
  uStack_60 = 0;
  local_68 = 0x38;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_68,ExDefaultNonPagedPoolType,
                     *(undefined4 *)(param_1 + 0x10));
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xc,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_1,(char)iVar4)
      ;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x11e);
    memset((void *)0x0,0,(ulonglong)uVar1);
    uRam000000000000004c = 0x2e425258;
    uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
    uRam000000000000000c = 0xabcd0000;
    uRam0000000000000008 = 0xaabb0003;
    uRam0000000000000020 = 0;
    uRam0000000000000000 = uVar1;
    lRam0000000000000018 = param_1;
    if (*(char *)(param_1 + 0x8b) != '\0') {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
      puVar7 = auStackY_a8;
      lVar6 = param_1 + 0x78;
      plVar8 = *(longlong **)(param_1 + 0x80);
      plVar5 = (longlong *)0x30;
      if (*plVar8 != lVar6) {
        plVar5 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        uVar3 = (*pcVar2)();
        puVar7 = auStackY_a0;
      }
      *plVar5 = lVar6;
      plVar5[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar5;
      *(longlong **)(lVar6 + 8) = plVar5;
      *(undefined8 *)(puVar7 + -8) = 0x140021bcb;
      KeReleaseSpinLock(param_1 + 0x70,uVar3);
    }
    *param_4 = 0x50;
  }
  return iVar4;
}



===== Xrb_SelectConfigAllocateAndBuild @ 140021c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140021f85) */

int Xrb_SelectConfigAllocateAndBuild
              (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  ushort *puVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  undefined2 uVar14;
  ushort uVar15;
  uint uVar16;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  *param_4 = 0;
  local_48 = local_48 & 0xffffffff00000000;
  uVar11 = 0x78;
  local_78 = 0;
  uStack_70 = 0;
  uVar12 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  plVar9 = param_3;
  uVar16 = 0;
  do {
    if (*plVar9 == 0) {
      if ((0x601 < *(uint *)(param_1 + 4)) && (plVar9[1] != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar14 = 0x19;
LAB_140021ce7:
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar14,
                           &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)plVar9,
                           (char)param_1);
        return -0x3ffffff3;
      }
      local_48 = 0;
      local_58 = *(undefined8 *)(param_1 + 0x28);
      local_68 = 0;
      uStack_50 = 0;
      uStack_70 = 0;
      local_78 = 0x38;
      uStack_60 = 0x100000001;
      iVar6 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,&local_78,ExDefaultNonPagedPoolType,
                         *(undefined4 *)(param_1 + 0x10));
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar6;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x1a,
                           &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_1,
                           (char)iVar6);
        return iVar6;
      }
      (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x359);
      memset((void *)0x0,0,(ulonglong)uVar11);
      puVar10 = auStackY_b8;
      uRam000000000000004c = 0x2e425258;
      uRam0000000000000000 = (uint)uVar11;
      uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
      uRam000000000000000c = 0xabcd0000;
      uRam0000000000000008 = 0xaabb0001;
      uRam0000000000000020 = 0;
      puVar13 = (ushort *)0x78;
      lRam0000000000000018 = param_1;
      while( true ) {
        lVar2 = *param_3;
        if (lVar2 == 0) {
          sRam0000000000000050 = uVar11 - 0x50;
          uRam0000000000000052 = 0;
          uRam0000000000000068 = param_2;
          if (*(char *)(param_1 + 0x8b) != '\0') {
            KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
            puVar10 = auStackY_b8;
            plVar9 = *(longlong **)(param_1 + 0x80);
            if (*plVar9 != param_1 + 0x78) {
              plVar9 = (longlong *)0x3;
              pcVar5 = (code *)swi(0x29);
              (*pcVar5)();
              puVar10 = auStackY_b0;
            }
            lRam0000000000000030 = param_1 + 0x78;
            plRam0000000000000038 = plVar9;
            *plVar9 = 0x30;
            *(undefined8 *)(param_1 + 0x80) = 0x30;
            *(undefined8 *)(puVar10 + -8) = 0x140022044;
            KeReleaseSpinLock(param_1 + 0x70);
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            *(undefined8 *)(puVar10 + 0x28) = 0;
            *(undefined **)(puVar10 + 0x20) = &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids;
            *(undefined8 *)(puVar10 + -8) = 0x140022092;
            WPP_RECORDER_SF_q(uVar3,5,9,0x1e,*(undefined8 *)(puVar10 + 0x20),puVar10[0x28]);
          }
          *param_4 = 0x50;
          return iVar6;
        }
        *(undefined1 *)(puVar13 + 1) = *(undefined1 *)(lVar2 + 2);
        *(undefined1 *)((longlong)puVar13 + 3) = *(undefined1 *)(lVar2 + 3);
        uVar15 = (*(byte *)(lVar2 + 4) + 1) * 0x18;
        if ((ulonglong)uVar11 < (ulonglong)uVar15 + (longlong)puVar13) break;
        uVar16 = (uint)*(byte *)(lVar2 + 4);
        *(uint *)(puVar13 + 8) = uVar16;
        *puVar13 = uVar15;
        if (uVar16 != 0) {
          puVar7 = puVar13 + 0x16;
          uVar8 = (ulonglong)uVar16;
          do {
            puVar7[-2] = 0xffff;
            puVar7[-1] = 0xffff;
            puVar7[0] = 0;
            puVar7[1] = 0;
            puVar7 = puVar7 + 0xc;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        param_3[1] = (longlong)puVar13;
        param_3 = param_3 + 2;
        puVar13 = (ushort *)((longlong)puVar13 + (ulonglong)uVar15);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar14 = 0x1b;
      goto LAB_140021f4f;
    }
    bVar1 = *(byte *)(*plVar9 + 4);
    uVar12 = uVar12 + bVar1;
    if (0x20 < uVar12) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar14 = 0x16;
      goto LAB_140021f4f;
    }
    if ((0x601 < *(uint *)(param_1 + 4)) && (plVar9[1] != 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar14 = 0x17;
      goto LAB_140021ce7;
    }
    plVar9 = plVar9 + 2;
    uVar11 = uVar11 + (ushort)bVar1 * 0x18 + 0x18;
    bVar4 = 0xff < uVar16;
    uVar16 = uVar16 + 1;
    if (bVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar14 = 0x18;
LAB_140021f4f:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar14,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids);
      }
      return -0x3ffffff3;
    }
  } while( true );
}



===== Xrb_SelectInterfaceAllocateAndBuild @ 1400220d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400222ae) */

int Xrb_SelectInterfaceAllocateAndBuild
              (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4)

{
  byte bVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  uint uVar11;
  short sVar12;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = local_48 & 0xffffffff00000000;
  *param_4 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar4 = (undefined1)param_1;
  if (*param_3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar10 = 0x1f;
  }
  else {
    if (param_3[1] == 0) {
      bVar1 = *(byte *)(*param_3 + 4);
      uVar7 = (ulonglong)bVar1;
      uVar11 = (uint)bVar1;
      if (0x20 < uVar11) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x21,
                            in_stack_ffffffffffffff68,bVar1,(char)param_3,uVar4);
        return -0x3ffffff3;
      }
      local_68 = 0;
      uStack_50 = 0;
      sVar12 = ((ushort)bVar1 + (ushort)bVar1 + (ushort)bVar1) * 8;
      local_48 = 0;
      uStack_60 = 0x100000001;
      local_58 = *(undefined8 *)(param_1 + 0x28);
      uStack_70 = 0;
      local_78 = 0x38;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,&local_78,ExDefaultNonPagedPoolType,
                         *(undefined4 *)(param_1 + 0x10));
      if (-1 < iVar5) {
        (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,0,Xrb_Free,0x432);
        memset((void *)0x0,0,(ulonglong)(ushort)(sVar12 + 0x88U));
        puVar9 = auStackY_b8;
        uRam000000000000004c = 0x2e425258;
        uRam0000000000000000 = (uint)(ushort)(sVar12 + 0x88U);
        uRam0000000000000004 = *(undefined4 *)(param_1 + 4);
        uRam000000000000000c = 0xabcd0000;
        uRam0000000000000008 = 0xaabb0002;
        uRam0000000000000020 = 0;
        uRam0000000000000072 = *(undefined1 *)(*param_3 + 2);
        uRam0000000000000073 = *(undefined1 *)(*param_3 + 3);
        lRam0000000000000018 = param_1;
        uRam0000000000000080 = uVar11;
        if (bVar1 != 0) {
          puVar6 = (undefined4 *)0x9c;
          do {
            puVar6[-1] = 0xffffffff;
            *puVar6 = 0;
            puVar6 = puVar6 + 6;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        sRam0000000000000070 = sVar12 + 0x18;
        sRam0000000000000050 = sVar12 + 0x38;
        param_3[1] = 0x70;
        uRam0000000000000052 = 1;
        uRam0000000000000068 = param_2;
        if (*(char *)(param_1 + 0x8b) != '\0') {
          uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x70);
          puVar9 = auStackY_b8;
          plVar8 = *(longlong **)(param_1 + 0x80);
          if (*plVar8 != param_1 + 0x78) {
            plVar8 = (longlong *)0x3;
            pcVar3 = (code *)swi(0x29);
            uVar4 = (*pcVar3)();
            puVar9 = auStackY_b0;
          }
          lRam0000000000000030 = param_1 + 0x78;
          plRam0000000000000038 = plVar8;
          *plVar8 = 0x30;
          *(undefined8 *)(param_1 + 0x80) = 0x30;
          *(undefined8 *)(puVar9 + -8) = 0x140022457;
          KeReleaseSpinLock(param_1 + 0x70,uVar4);
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(undefined8 *)(puVar9 + 0x28) = 0;
          *(undefined **)(puVar9 + 0x20) = &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids;
          *(undefined8 *)(puVar9 + -8) = 0x1400224a7;
          WPP_RECORDER_SF_q(uVar2,5,9,0x25,*(undefined8 *)(puVar9 + 0x20),puVar9[0x28]);
        }
        *param_4 = 0x50;
        return iVar5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar5;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x22,
                         &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,uVar4,(char)iVar5);
      return iVar5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar10 = 0x20;
  }
  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar10,
                     &WPP_202ec87859e138177a7b9cd63d6c3dde_Traceguids,(char)param_3,uVar4);
  return -0x3ffffff3;
}



===== Etw_EnableCallbackLegacy @ 1400224e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_EnableCallbackLegacy(undefined8 param_1,int param_2)

{
  uint uVar1;
  longlong *plVar2;
  undefined1 uVar3;
  ulonglong *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  undefined1 auStack_68 [32];
  char *local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  if (param_2 != 0) {
    local_28 = __security_cookie ^ (ulonglong)auStack_68;
    puVar4 = (ulonglong *)0x0;
    local_38 = 0;
    uStack_30 = 0;
    uVar5 = 3;
    EtwActivityIdControl(3,&local_38);
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(uVar5,&UCX_ETW_EVENT_RUNDOWN_START,&local_38);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(g_WdfDriverUcxContext + 0x20);
    uVar1 = *(uint *)(g_WdfDriverUcxContext + 0x28);
    lVar6 = g_WdfDriverUcxContext + 0x20;
    KeReleaseSpinLock(lVar6,uVar3);
    if (uVar1 != 0) {
      while( true ) {
        puVar4 = (ulonglong *)ExAllocatePool2(0x40,(ulonglong)uVar1 << 3,0x44434855);
        if (puVar4 == (ulonglong *)0x0) {
          return;
        }
        uVar3 = KeAcquireSpinLockRaiseToDpc(g_WdfDriverUcxContext + 0x20);
        if (*(uint *)(g_WdfDriverUcxContext + 0x28) <= uVar1) break;
        KeReleaseSpinLock(g_WdfDriverUcxContext + 0x20,uVar3);
        ExFreePoolWithTag(puVar4,0x44434855);
      }
      uVar8 = 0;
      plVar2 = *(longlong **)(g_WdfDriverUcxContext + 0x10);
      if ((longlong *)(g_WdfDriverUcxContext + 0x10) != plVar2) {
        do {
          local_48 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c";
          (**(code **)(WdfFunctions_01015 + 0x668))
                    (WdfDriverGlobals,plVar2[2],Etw_EnableCallbackLegacy,0xd9);
          puVar4[uVar8] = (ulonglong)(plVar2 + -3);
          uVar8 = (ulonglong)((int)uVar8 + 1);
          plVar2 = (longlong *)*plVar2;
        } while ((longlong *)(g_WdfDriverUcxContext + 0x10) != plVar2);
      }
      lVar6 = g_WdfDriverUcxContext + 0x20;
      KeReleaseSpinLock(lVar6,uVar3);
      uVar7 = 0;
      if (uVar1 != 0) {
        puVar9 = puVar4;
        do {
          uVar8 = *puVar9;
          if (uVar8 == 0) break;
          Etw_UcxControllerRundown(&local_38,uVar8);
          local_48 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c";
          lVar6 = WdfDriverGlobals;
          (**(code **)(WdfFunctions_01015 + 0x670))
                    (WdfDriverGlobals,*(undefined8 *)(uVar8 + 0x28),Etw_EnableCallbackLegacy,0xfc);
          uVar7 = uVar7 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar7 < uVar1);
      }
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(lVar6,&UCX_ETW_EVENT_RUNDOWN_COMPLETE,&local_38);
    }
    if (puVar4 != (ulonglong *)0x0) {
      ExFreePoolWithTag(puVar4,0x44434855);
    }
  }
  return;
}



===== Etw_EnableCallbackNew @ 140022740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_EnableCallbackNew(undefined8 param_1,int param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  uint uVar9;
  undefined1 auStack_68 [32];
  char *local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  if (param_2 != 0) {
    local_28 = __security_cookie ^ (ulonglong)auStack_68;
    puVar3 = (ulonglong *)0x0;
    local_38 = 0;
    uStack_30 = 0;
    uVar4 = 3;
    EtwActivityIdControl(3,&local_38);
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(uVar4,&UCX_ETW_EVENT_RUNDOWN_START,&local_38);
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(g_WdfDriverUcxContext + 0x20);
    uVar6 = *(uint *)(g_WdfDriverUcxContext + 0x28);
    lVar5 = g_WdfDriverUcxContext + 0x20;
    KeReleaseSpinLock(lVar5,uVar2);
    if (uVar6 != 0) {
      while( true ) {
        puVar3 = (ulonglong *)ExAllocatePool2(0x40,(ulonglong)uVar6 << 3,0x44434855);
        if (puVar3 == (ulonglong *)0x0) {
          return;
        }
        uVar2 = KeAcquireSpinLockRaiseToDpc(g_WdfDriverUcxContext + 0x20);
        uVar9 = *(uint *)(g_WdfDriverUcxContext + 0x28);
        if (uVar9 <= uVar6) break;
        KeReleaseSpinLock(g_WdfDriverUcxContext + 0x20,uVar2);
        ExFreePoolWithTag(puVar3,0x44434855);
        uVar6 = uVar9;
      }
      uVar7 = 0;
      uVar6 = 0;
      plVar1 = *(longlong **)(g_WdfDriverUcxContext + 0x10);
      if ((longlong *)(g_WdfDriverUcxContext + 0x10) != plVar1) {
        do {
          local_48 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c";
          (**(code **)(WdfFunctions_01015 + 0x668))
                    (WdfDriverGlobals,plVar1[2],Etw_EnableCallbackNew,0x199);
          puVar3[uVar7] = (ulonglong)(plVar1 + -3);
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          plVar1 = (longlong *)*plVar1;
        } while ((longlong *)(g_WdfDriverUcxContext + 0x10) != plVar1);
      }
      lVar5 = g_WdfDriverUcxContext + 0x20;
      KeReleaseSpinLock(lVar5,uVar2);
      uVar9 = 0;
      if (uVar6 != 0) {
        puVar8 = puVar3;
        do {
          uVar7 = *puVar8;
          if (uVar7 == 0) break;
          Etw_UcxControllerRundown(&local_38,uVar7);
          local_48 = "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c";
          lVar5 = WdfDriverGlobals;
          (**(code **)(WdfFunctions_01015 + 0x670))
                    (WdfDriverGlobals,*(undefined8 *)(uVar7 + 0x28),Etw_EnableCallbackNew,0x1c4);
          uVar9 = uVar9 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar9 < uVar6);
      }
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(lVar5,&UCX_ETW_EVENT_RUNDOWN_COMPLETE,&local_38);
    }
    if (puVar3 != (ulonglong *)0x0) {
      ExFreePoolWithTag(puVar3,0x44434855);
    }
  }
  return;
}



===== Etw_GetConfigurationUrbDispatch @ 140022998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_GetConfigurationUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined7 in_register_00000009;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar2 = -0x3ffffddb;
    }
    else {
      iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
    }
    uVar1 = *(undefined8 *)(param_2 + 8);
    uVar4 = WdfDriverGlobals;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar5 = &local_38;
      if (iVar2 < 0) {
        puVar5 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar4,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_CONFIGURATION,puVar5,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
                 (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
    }
  }
  return;
}



===== Etw_GetInterfaceUrbDispatch @ 140022a94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_GetInterfaceUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined7 in_register_00000009;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
    if (g_IoGetActivityIdIrp == (code *)0x0) {
      iVar2 = -0x3ffffddb;
    }
    else {
      iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
    }
    uVar1 = *(undefined8 *)(param_2 + 8);
    uVar4 = WdfDriverGlobals;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0)
    ;
    if ((Microsoft_Windows_USB_UCXEnableBits & 4) != 0) {
      puVar5 = &local_38;
      if (iVar2 < 0) {
        puVar5 = (undefined8 *)0x0;
      }
      McTemplateK0pppppn_EtwWriteTransfer
                (uVar4,&UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_GET_INTERFACE,puVar5,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
                 (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
    }
  }
  return;
}



===== Etw_SetClearFeatureUrbDispatch @ 140022b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Etw_SetClearFeatureUrbDispatch(undefined1 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined7 in_register_00000009;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  if (g_IoGetActivityIdIrp == (code *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    iVar2 = (*g_IoGetActivityIdIrp)(CONCAT71(in_register_00000009,param_1),&local_38);
  }
  uVar1 = *(undefined8 *)(param_2 + 8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_UCXUSBDEVICE_PRIVCONTEXT_TYPE_INFO_14002d8c0);
  uVar4 = (uint)*(ushort *)(param_2 + 2);
  uVar5 = (ulonglong)(uVar4 - 0xd);
  if (uVar4 - 0xd != 0) {
    if (uVar4 == 0xe) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_FEATURE_TO_INTERFACE;
      uVar5 = 0;
      goto LAB_140022cfb;
    }
    if (uVar4 == 0xf) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_FEATURE_TO_ENDPOINT;
      uVar5 = 0;
      goto LAB_140022cfb;
    }
    if (uVar4 == 0x10) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLEAR_FEATURE_TO_DEVICE;
      uVar5 = 0;
      goto LAB_140022cfb;
    }
    if (uVar4 == 0x11) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLEAR_FEATURE_TO_INTERFACE;
      uVar5 = 0;
      goto LAB_140022cfb;
    }
    if (uVar4 == 0x12) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLEAR_FEATURE_TO_ENDPOINT;
      uVar5 = 0;
      goto LAB_140022cfb;
    }
    uVar4 = uVar4 - 0x22;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_CLEAR_FEATURE_TO_OTHER;
      goto LAB_140022cfb;
    }
    if (uVar4 == 1) {
      if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
        return;
      }
      puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_FEATURE_TO_OTHER;
      goto LAB_140022cfb;
    }
  }
  if ((Microsoft_Windows_USB_UCXEnableBits & 4) == 0) {
    return;
  }
  puVar6 = &UCX_ETW_EVENT_DISPATCH_URB_FUNCTION_SET_FEATURE_TO_DEVICE;
LAB_140022cfb:
  puVar7 = &local_38;
  if (iVar2 < 0) {
    puVar7 = (undefined8 *)0x0;
  }
  McTemplateK0pppppn_EtwWriteTransfer
            (uVar5,puVar6,puVar7,*(undefined8 *)(*(longlong *)(lVar3 + 0x18) + 0x28),(char)uVar1,
             (char)*(undefined8 *)(param_2 + 0x18),param_1,(char)param_2,0x88,param_2);
  return;
}



===== Etw_UcxControllerCreate @ 140022d5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxControllerCreate(undefined8 param_1,longlong param_2)

{
  wchar_t *_Dst;
  ulonglong local_18;
  void *pvStack_10;
  
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    RtlInitUnicodeString(&local_18,0);
    (**(code **)(WdfFunctions_01015 + 0x9a8))
              (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x150),&local_18);
    _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_18 & 0xffff) + 2,0x44434855);
    if (_Dst != (wchar_t *)0x0) {
      memmove(_Dst,pvStack_10,local_18 & 0xffff);
      _Dst[local_18 >> 1 & 0x7fff] = L'\0';
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
      McTemplateK0pqqqqqqqsssz_EtwWriteTransfer
                (param_2 + 0x99,&UCX_ETW_EVENT_UCX_CONTROLLER_CREATE,0,
                 *(undefined8 *)(param_2 + 0x28),(char)*(undefined4 *)(param_2 + 0x78),
                 (char)*(undefined4 *)(param_2 + 0x88),(char)*(undefined4 *)(param_2 + 0x8c),
                 (char)*(undefined4 *)(param_2 + 0x90),(char)*(undefined4 *)(param_2 + 0x7c),
                 (char)*(undefined4 *)(param_2 + 0x80),(char)*(undefined2 *)(param_2 + 0x84),
                 (char *)(param_2 + 0x94),(char *)(param_2 + 0x99),(char *)(param_2 + 0x9e),_Dst);
    }
    if (_Dst != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Dst,0x44434855);
    }
  }
  return;
}



===== Etw_UcxControllerDelete @ 140022ed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxControllerDelete(undefined8 param_1,longlong param_2)

{
  wchar_t *_Dst;
  ulonglong local_18;
  void *pvStack_10;
  
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  _Dst = (wchar_t *)0x0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    if (*(longlong *)(param_2 + 0x150) != 0) {
      RtlInitUnicodeString(&local_18,0);
      (**(code **)(WdfFunctions_01015 + 0x9a8))
                (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x150),&local_18);
      _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_18 & 0xffff) + 2,0x44434855);
      if (_Dst != (wchar_t *)0x0) {
        memmove(_Dst,pvStack_10,local_18 & 0xffff);
        _Dst[local_18 >> 1 & 0x7fff] = L'\0';
      }
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
      McTemplateK0pqqqqqqqsssz_EtwWriteTransfer
                (param_2 + 0x99,&UCX_ETW_EVENT_UCX_CONTROLLER_DELETE,0,
                 *(undefined8 *)(param_2 + 0x28),(char)*(undefined4 *)(param_2 + 0x78),
                 (char)*(undefined4 *)(param_2 + 0x88),(char)*(undefined4 *)(param_2 + 0x8c),
                 (char)*(undefined4 *)(param_2 + 0x90),(char)*(undefined4 *)(param_2 + 0x7c),
                 (char)*(undefined4 *)(param_2 + 0x80),(char)*(undefined2 *)(param_2 + 0x84),
                 (char *)(param_2 + 0x94),(char *)(param_2 + 0x99),(char *)(param_2 + 0x9e),_Dst);
    }
    if (_Dst != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Dst,0x44434855);
    }
  }
  return;
}



===== Etw_UcxDeviceTreeRundownLegacy @ 140023058 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxDeviceTreeRundownLegacy(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  longlong *_Dst;
  void *_Dst_00;
  ulonglong uVar4;
  undefined7 uVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint local_res10;
  longlong *local_48;
  ulonglong uStack_40;
  void *local_38;
  ulonglong uStack_30;
  
  lVar1 = param_2 + 0x1e8;
  _Dst = (longlong *)0x0;
  _Dst_00 = (void *)0x0;
  local_48 = (longlong *)0x0;
  uStack_40 = 0;
  local_38 = (void *)0x0;
  uStack_30 = 0;
  uVar4 = param_2;
  KeAcquireSpinLockRaiseToDpc(lVar1);
  local_res10 = *(uint *)(param_2 + 500);
  uVar8 = (ulonglong)local_res10;
  uVar6 = *(uint *)(param_2 + 0x1f0);
  uVar4 = uVar4 & 0xffffffffffffff00;
  KeReleaseSpinLock(lVar1);
  while( true ) {
    if ((uVar6 != 0) && (_Dst == (longlong *)0x0)) {
      uVar4 = (ulonglong)uVar6 << 3;
      _Dst = (longlong *)ExAllocatePool2(0x40,uVar4,0x44434855);
      if (_Dst == (longlong *)0x0) goto LAB_140023384;
    }
    if (((uint)uVar8 != 0) && (_Dst_00 == (void *)0x0)) {
      uVar4 = uVar8 * 0x18;
      _Dst_00 = (void *)ExAllocatePool2(0x40,uVar4,0x44434855);
      if (_Dst_00 == (void *)0x0) goto LAB_14002336b;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar5 = (undefined7)(uVar4 >> 8);
    if (*(longlong *)(param_2 + 0x158) == 0) break;
    uVar2 = *(uint *)(param_2 + 0x1f0);
    if (uVar6 < uVar2) {
      uVar4 = CONCAT71(uVar5,uVar3);
      KeReleaseSpinLock(lVar1);
      uVar6 = uVar2;
      if (_Dst != (longlong *)0x0) {
        uVar4 = 0x44434855;
        ExFreePoolWithTag(_Dst);
        _Dst = (longlong *)0x0;
      }
    }
    else {
      uVar2 = *(uint *)(param_2 + 500);
      if (uVar2 <= (uint)uVar8) {
        if (_Dst != (longlong *)0x0) {
          uVar4 = 0;
          memset(_Dst,0,(ulonglong)uVar6 << 3);
        }
        if (_Dst_00 != (void *)0x0) {
          uVar4 = 0;
          memset(_Dst_00,0,uVar8 * 0x18);
        }
        uVar5 = (undefined7)(uVar4 >> 8);
        uStack_40 = (ulonglong)uVar6;
        local_48 = _Dst;
        local_38 = _Dst_00;
        uStack_30 = uVar8;
        UsbDevice_WalkTree(*(longlong *)(*(longlong *)(param_2 + 0x158) + 0xb8),'\x01',
                           Etw_UcxDeviceTreeRundownWalkCallback,&local_48);
        KeReleaseSpinLock(lVar1,CONCAT71(uVar5,uVar3));
        if (uVar6 != 0) {
          uVar4 = (ulonglong)uVar6;
          plVar7 = _Dst;
          do {
            lVar1 = *plVar7;
            Etw_UcxDeviceRundown(param_1,lVar1);
            (**(code **)(WdfFunctions_01015 + 0x670))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10),
                       Etw_UcxDeviceTreeRundownWalkCallback,0x32d,
                       "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            plVar7 = plVar7 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
          uVar8 = (ulonglong)local_res10;
        }
        if ((int)uVar8 != 0) {
          plVar7 = (longlong *)((longlong)_Dst_00 + 0x10);
          do {
            Etw_UcxEndpointRundown(param_1,plVar7[-2],plVar7[-1],*plVar7);
            (**(code **)(WdfFunctions_01015 + 0x670))
                      (WdfDriverGlobals,*(undefined8 *)(plVar7[-1] + 8),
                       Etw_UcxDeviceTreeRundownWalkCallback,0x344,
                       "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            if (*plVar7 != 0) {
              (**(code **)(WdfFunctions_01015 + 0x670))
                        (WdfDriverGlobals,*(undefined8 *)(*plVar7 + 8),
                         Etw_UcxDeviceTreeRundownWalkCallback,0x349,
                         "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            }
            plVar7 = plVar7 + 3;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
LAB_14002336b:
        if (_Dst != (longlong *)0x0) {
          ExFreePoolWithTag(_Dst,0x44434855);
        }
LAB_140023384:
        if (_Dst_00 != (void *)0x0) {
          ExFreePoolWithTag(_Dst_00,0x44434855);
        }
        return;
      }
      uVar4 = CONCAT71(uVar5,uVar3);
      uVar8 = (ulonglong)uVar2;
      KeReleaseSpinLock(lVar1);
      local_res10 = uVar2;
      if (_Dst_00 != (void *)0x0) {
        uVar4 = 0x44434855;
        ExFreePoolWithTag(_Dst_00);
        _Dst_00 = (void *)0x0;
      }
    }
  }
  KeReleaseSpinLock(lVar1,CONCAT71(uVar5,uVar3));
  goto LAB_14002336b;
}



===== Etw_UcxDeviceTreeRundownNew @ 1400233c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxDeviceTreeRundownNew(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  void *_Dst;
  void *_Dst_00;
  ulonglong uVar4;
  undefined7 uVar5;
  uint uVar6;
  uint uVar7;
  void *local_48;
  undefined8 uStack_40;
  void *local_38;
  undefined8 uStack_30;
  
  lVar1 = param_2 + 0x1e8;
  _Dst = (void *)0x0;
  _Dst_00 = (void *)0x0;
  local_48 = (void *)0x0;
  uStack_40 = 0;
  local_38 = (void *)0x0;
  uStack_30 = 0;
  uVar4 = param_2;
  KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar6 = *(uint *)(param_2 + 0x1f0);
  uVar7 = *(uint *)(param_2 + 500);
  uVar4 = uVar4 & 0xffffffffffffff00;
  KeReleaseSpinLock(lVar1);
  while( true ) {
    if ((uVar6 != 0) && (_Dst == (void *)0x0)) {
      uVar4 = (ulonglong)uVar6 << 3;
      _Dst = (void *)ExAllocatePool2(0x40,uVar4,0x44434855);
      if (_Dst == (void *)0x0) goto LAB_1400236dd;
    }
    if ((uVar7 != 0) && (_Dst_00 == (void *)0x0)) {
      uVar4 = (ulonglong)uVar7 * 0x18;
      _Dst_00 = (void *)ExAllocatePool2(0x40,uVar4,0x44434855);
      if (_Dst_00 == (void *)0x0) goto LAB_1400236c4;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar5 = (undefined7)(uVar4 >> 8);
    if (*(longlong *)(param_2 + 0x158) == 0) break;
    uVar2 = *(uint *)(param_2 + 0x1f0);
    if (uVar6 < uVar2) {
      uVar4 = CONCAT71(uVar5,uVar3);
      KeReleaseSpinLock(lVar1);
      uVar6 = uVar2;
      if (_Dst != (void *)0x0) {
        uVar4 = 0x44434855;
        ExFreePoolWithTag(_Dst);
        _Dst = (void *)0x0;
      }
    }
    else {
      uVar2 = *(uint *)(param_2 + 500);
      if (uVar2 <= uVar7) {
        if (_Dst != (void *)0x0) {
          uVar4 = 0;
          memset(_Dst,0,(ulonglong)uVar6 << 3);
        }
        if (_Dst_00 != (void *)0x0) {
          uVar4 = 0;
          memset(_Dst_00,0,(ulonglong)uVar7 * 0x18);
        }
        uVar5 = (undefined7)(uVar4 >> 8);
        uStack_40 = (ulonglong)uVar6;
        uStack_30 = (ulonglong)uVar7;
        local_48 = _Dst;
        local_38 = _Dst_00;
        UsbDevice_WalkTree(*(longlong *)(*(longlong *)(param_2 + 0x158) + 0xb8),'\x01',
                           Etw_UcxDeviceTreeRundownWalkCallback,&local_48);
        KeReleaseSpinLock(lVar1,CONCAT71(uVar5,uVar3));
        uVar4 = 0;
        if (uStack_40._4_4_ != 0) {
          do {
            lVar1 = *(longlong *)((longlong)_Dst + uVar4 * 8);
            Etw_UcxDeviceRundown(param_1,lVar1);
            (**(code **)(WdfFunctions_01015 + 0x670))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10),
                       Etw_UcxDeviceTreeRundownWalkCallback,0x41a,
                       "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            uVar6 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar6;
          } while (uVar6 < uStack_40._4_4_);
        }
        uVar4 = 0;
        if (uStack_30._4_4_ != 0) {
          do {
            Etw_UcxEndpointRundown
                      (param_1,*(undefined8 *)((longlong)_Dst_00 + uVar4 * 0x18),
                       *(longlong *)((longlong)_Dst_00 + uVar4 * 0x18 + 8),
                       *(longlong *)((longlong)_Dst_00 + uVar4 * 0x18 + 0x10));
            (**(code **)(WdfFunctions_01015 + 0x670))
                      (WdfDriverGlobals,
                       *(undefined8 *)(*(longlong *)((longlong)_Dst_00 + uVar4 * 0x18 + 8) + 8),
                       Etw_UcxDeviceTreeRundownWalkCallback,0x431,
                       "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            lVar1 = *(longlong *)((longlong)_Dst_00 + uVar4 * 0x18 + 0x10);
            if (lVar1 != 0) {
              (**(code **)(WdfFunctions_01015 + 0x670))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),
                         Etw_UcxDeviceTreeRundownWalkCallback,0x436,
                         "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
            }
            uVar6 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar6;
          } while (uVar6 < uStack_30._4_4_);
        }
LAB_1400236c4:
        if (_Dst != (void *)0x0) {
          ExFreePoolWithTag(_Dst,0x44434855);
        }
LAB_1400236dd:
        if (_Dst_00 != (void *)0x0) {
          ExFreePoolWithTag(_Dst_00,0x44434855);
        }
        return;
      }
      uVar4 = CONCAT71(uVar5,uVar3);
      KeReleaseSpinLock(lVar1);
      uVar7 = uVar2;
      if (_Dst_00 != (void *)0x0) {
        uVar4 = 0x44434855;
        ExFreePoolWithTag(_Dst_00);
        _Dst_00 = (void *)0x0;
      }
    }
  }
  KeReleaseSpinLock(lVar1,CONCAT71(uVar5,uVar3));
  goto LAB_1400236c4;
}



===== Etw_UcxRootHubPrepare @ 140023720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxRootHubPrepare(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  wchar_t *_Dst;
  longlong lVar3;
  longlong lVar4;
  ulonglong local_38;
  void *pvStack_30;
  
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  _Dst = (wchar_t *)0x0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    lVar3 = param_2 + 0x158;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3);
    lVar4 = 0;
    if ((*(char *)(param_2 + 0x178) != '\0') && (lVar1 = *(longlong *)(param_2 + 0x180), lVar1 != 0)
       ) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,lVar1,Etw_UcxRootHubPrepare,0x6e2,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
      lVar4 = lVar1;
    }
    KeReleaseSpinLock(lVar3,uVar2);
    if (lVar4 != 0) {
      RtlInitUnicodeString(&local_38,0);
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,lVar4,&local_38);
      _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_38 & 0xffff) + 2,0x44434855);
      if (_Dst != (wchar_t *)0x0) {
        memmove(_Dst,pvStack_30,local_38 & 0xffff);
        _Dst[local_38 >> 1 & 0x7fff] = L'\0';
      }
      lVar3 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar4,Etw_UcxRootHubPrepare,0x6fd,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
      McTemplateK0ppz_EtwWriteTransfer
                (lVar3,&UCX_ETW_EVENT_UCX_ROOTHUB_PREPARE,param_1,
                 *(undefined8 *)(*(longlong *)(param_2 + 0xb0) + 0x28),
                 (char)*(undefined8 *)(param_2 + 8),_Dst);
    }
    if (_Dst != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Dst,0x44434855);
    }
  }
  return;
}



===== Etw_UcxRootHubRelease @ 140023900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Etw_UcxRootHubRelease(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  wchar_t *_Dst;
  longlong lVar3;
  longlong lVar4;
  ulonglong local_38;
  void *pvStack_30;
  
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  _Dst = (wchar_t *)0x0;
  if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
    lVar3 = param_2 + 0x158;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3);
    lVar4 = 0;
    if ((*(char *)(param_2 + 0x178) != '\0') && (lVar1 = *(longlong *)(param_2 + 0x180), lVar1 != 0)
       ) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,lVar1,Etw_UcxRootHubRelease,0x73c,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
      lVar4 = lVar1;
    }
    KeReleaseSpinLock(lVar3,uVar2);
    if (lVar4 != 0) {
      RtlInitUnicodeString(&local_38,0);
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,lVar4,&local_38);
      _Dst = (wchar_t *)ExAllocatePool2(0x40,(local_38 & 0xffff) + 2,0x44434855);
      if (_Dst != (wchar_t *)0x0) {
        memmove(_Dst,pvStack_30,local_38 & 0xffff);
        _Dst[local_38 >> 1 & 0x7fff] = L'\0';
      }
      lVar3 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar4,Etw_UcxRootHubRelease,0x757,
                 "onecore\\drivers\\wdm\\usb\\usb3\\ucx\\sys\\etw.c");
    }
    if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
      McTemplateK0ppz_EtwWriteTransfer
                (lVar3,&UCX_ETW_EVENT_UCX_ROOTHUB_RELEASE,param_1,
                 *(undefined8 *)(*(longlong *)(param_2 + 0xb0) + 0x28),
                 (char)*(undefined8 *)(param_2 + 8),_Dst);
    }
    if (_Dst != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Dst,0x44434855);
    }
  }
  return;
}



===== Etw_UcxStaticStreamsCreate @ 140023adc =====

void Etw_UcxStaticStreamsCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0x10);
  uVar5 = 0;
  uVar3 = *(undefined8 *)(*(longlong *)(lVar2 + 0x48) + 0x10);
  if (*(int *)(param_2 + 4) != 0) {
    do {
      if ((Microsoft_Windows_USB_UCXEnableBits & 2) != 0) {
        lVar1 = lVar2 + 0x10;
        McTemplateK0ppqp_EtwWriteTransfer
                  (lVar1,&UCX_ETW_EVENT_UCX_STATIC_STREAM_CREATE,0,uVar3,(char)lVar1,
                   (char)*(undefined4 *)(*(longlong *)(param_2 + 0x20) + 0x40 + uVar5 * 0x48),
                   (char)*(longlong *)(param_2 + 0x20) + '\x10' + (char)uVar5 * 'H');
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_2 + 4));
  }
  return;
}



===== Wmi_Create @ 140023b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Wmi_Create(undefined8 param_1)

{
  int iVar1;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined4 *local_68;
  undefined1 local_5f;
  code *local_58;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  undefined8 local_24;
  undefined8 uStack_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_14 = 0;
  local_24 = 0;
  uStack_1c = 0;
  local_38 = 0x28;
  local_34 = 0x4f41dc7a9c179357;
  uStack_2c = 0xb1b5dc9d3b326bb6;
  memset(local_78,0,0x40);
  local_68 = &local_38;
  local_78[0] = 0x40;
  local_58 = Wmi_WdfEvtWmiInstanceQueryInstance;
  local_5f = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xba8))(WdfDriverGlobals,param_1,local_78,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,10,
                        &WPP_f7a38b5502ba3959cd95ad6a7ad87043_Traceguids,(char)iVar1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== Wmi_WdfEvtWmiInstanceQueryInstance @ 140023c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
Wmi_WdfEvtWmiInstanceQueryInstance
          (undefined8 param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xbc0))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_WDFDEVICE_UCX_CONTEXT_TYPE_INFO_14002d848);
  lVar3 = *(longlong *)(lVar3 + 8);
  if (param_2 < 0x4b2) {
    uVar4 = 0xc0000023;
  }
  else {
    memset(param_3,0,(ulonglong)param_2);
    *param_3 = 0x5553424e;
    param_3[1] = 0x4b2;
    RtlStringCbCopyA((char *)(param_3 + 2),0x50,lVar3 + 0xa3);
    param_3[0x16] = 3;
    param_3[0x17] = *(undefined4 *)(lVar3 + 0x88);
    param_3[0x18] = *(undefined4 *)(lVar3 + 0x8c);
    param_3[0x19] = *(undefined4 *)(lVar3 + 0x90);
    param_3[0x1f] = *(undefined4 *)(lVar3 + 0x7c);
    param_3[0x20] = *(undefined4 *)(lVar3 + 0x80);
    param_3[0x21] = (uint)*(ushort *)(lVar3 + 0x84);
    iVar1 = *(int *)(*(longlong *)(lVar3 + 0x158) + 0xd4);
    iVar2 = *(int *)(*(longlong *)(lVar3 + 0x158) + 0xd0);
    param_3[0x23] = param_3[0x23] | 2;
    uVar4 = 0;
    param_3[0x22] = iVar1 + iVar2;
  }
  *param_4 = 0x4b2;
  return uVar4;
}



===== FxStubDriverUnloadCommon @ 140023da8 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14002f308,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140023de0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140023e14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14002f308 = 0x2080000;
    _DAT_14002f310 = &DAT_14002efd0;
    RtlCopyUnicodeString(&DAT_14002f308);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_14002f308,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar3 = DriverEntry(param_1,param_2);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14002f1d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar3 & 0xffffffff,
                   &DAT_14002f308);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14002ea18 != &__KMDF_CLASS_BIND_START) {
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
      uVar3 = (ulonglong)uVar1;
    }
  }
  return uVar3;
}



===== FxStubDriverUnload @ 140023fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14002f1d8 != (code *)0x0) && (DAT_14002f1d8 != FxStubDriverUnload)) {
    (*DAT_14002f1d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140023fd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140023ff9) */
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
    if ((uint *)0x14002ea0f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14002ea18 = (undefined *)puVar2;
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



===== FxStubUnbindClasses @ 140024134 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14002ea18 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_14002ea18 + 0x50);
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



===== FxGetNextClassBindInfo @ 1400241f0 =====

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



===== FxStubInitTypes @ 140024238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140024255) */
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
    if ((void **)0x14002ea2f < ppvVar2) break;
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



===== SleepstudyHelper_UnregisterComponent @ 140024300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_UnregisterComponent(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14002f2b8 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14002f2b8)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14002f2b8 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14002f2b8)(param_1);
  }
  return iVar1;
}



===== GetImageTuple @ 140024388 =====

/* WARNING: Removing unreachable block (ram,0x0001400243be) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0x24c9fd58;
  *param_3 = 0x4a000;
  return 1;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 1400243d8 =====

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
          if (uVar2 == 0) goto LAB_1400244b9;
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
LAB_1400244b9:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 1400244e0 =====

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
    _DAT_14002f328 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140033078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140024594 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM(undefined8 param_1,uint param_2,undefined4 param_3)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,"UCX01000.SYS",(ulonglong)param_2,param_3)
  ;
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 1400245d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  longlong lVar18;
  char *pcVar19;
  undefined1 auStack_198 [8];
  undefined1 auStack_190 [80];
  undefined4 local_140;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  longlong local_b8 [2];
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar16 = auStack_198;
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  local_140 = (undefined4)param_4;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_140024b68;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar16 = auStack_198;
  for (plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar11 = (longlong *)*plVar11) {
    plVar10 = plVar11 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar10 == param_1) goto LAB_14002470d;
  }
  plVar10 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar18 = _DAT_fffff78000000320;
  puVar16 = auStack_198;
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar16 = auStack_198;
    plVar10[2] = 0;
    *(undefined4 *)(plVar10 + 3) = 0;
    plVar10[1] = (longlong)((ulonglong)uVar7 * lVar18) / 10000 + -0xea61;
    plVar11 = plVar10 + 4;
    plVar13 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar13 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar11 = (longlong *)(*pcVar2)();
      puVar16 = auStack_190;
    }
    *plVar11 = (longlong)plVar13;
    plVar11[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar13[1] = (longlong)plVar11;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar11;
LAB_14002470d:
    *(int *)(plVar10 + 2) = (int)plVar10[2] + 1;
    *(int *)((longlong)plVar10 + 0x14) = *(int *)((longlong)plVar10 + 0x14) + 1;
    lVar3 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar16 + -8) = 0x14002471d;
    uVar7 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar16 + 0x54) = 0;
    *(undefined4 *)(puVar16 + 0x50) = 0;
    lVar18 = (longlong)((ulonglong)uVar7 * lVar3) / 10000;
    if (60000 < (ulonglong)(lVar18 - plVar10[1])) {
      *(undefined8 *)(puVar16 + -8) = 0x14002476b;
      uVar12 = GetImageTuple((ulonglong)uVar7 * lVar3,(dword *)(puVar16 + 0x54),
                             (dword *)(puVar16 + 0x50));
      uVar7 = *(uint *)(puVar16 + 0x50);
      iVar8 = (int)uVar12;
      if ((((iVar8 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) < param_1)) {
        uVar15 = 0;
      }
      else {
        uVar15 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar16 + 0x50) = (int)plVar10[2];
      plVar10[1] = lVar18;
      lVar18 = plVar10[3];
      *(undefined4 *)(puVar16 + 0x7c) = *(undefined4 *)((longlong)plVar10 + 0x14);
      *(undefined8 *)(puVar16 + -8) = 0x1400247c0;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
      uVar1 = *(uint *)(puVar16 + 0x54);
      if (5 < DAT_140033040) {
        *(undefined8 *)(puVar16 + -8) = 0x1400247f4;
        cVar5 = _tlgKeywordOn(0x140033040,0x400000000000);
        uVar12 = 0;
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x54;
          *(undefined4 *)(puVar16 + 0x54) = 10;
          local_e8 = puVar16 + 0x5c;
          local_f0 = 4;
          *(uint *)(puVar16 + 0x5c) = uVar15;
          local_d8 = puVar16 + 0x60;
          local_e0 = 4;
          local_d0 = 4;
          *(uint *)(puVar16 + 0x60) = -(uint)(iVar8 != 0) & uVar1;
          local_c0 = 4;
          local_c8 = puVar16 + 100;
          *(uint *)(puVar16 + 100) = -(uint)(iVar8 != 0) & uVar7;
          pcVar14 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar14 = g_ModuleName;
          }
          *(undefined8 *)(puVar16 + -8) = 0x140024885;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          local_a8 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 0x6c) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 0x6c;
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x1400248be;
          bVar6 = KeGetCurrentIrql();
          local_80 = 4;
          *(uint *)(puVar16 + 0x70) = (uint)bVar6;
          local_88 = puVar16 + 0x70;
          *(undefined8 *)(puVar16 + -8) = 0x1400248eb;
          _tlgCreate1Sz_char(local_78,"UCX01000.SYS");
          local_68 = puVar16 + 0x74;
          *(undefined4 *)(puVar16 + 0x78) = param_5;
          local_58 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x74) = *(undefined4 *)(puVar16 + 0x58);
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x14002492f;
          _tlgCreate1Sz_char(local_48,
                             "D0 Exit - WDF and Pre Processed System Power Action are different");
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xe;
          *(undefined8 *)(puVar16 + -8) = 0x14002494c;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_118,&DAT_140028d11,uVar12,param_4,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if ((DAT_140033078 == 0) || ((int)lVar18 != 0)) goto LAB_140024b68;
      *(undefined8 *)(puVar16 + -8) = 0x14002496b;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_140024b68;
      *(undefined4 *)(puVar16 + 0x40) = 0;
      *(undefined8 *)(puVar16 + 0x38) = 0;
      *(undefined8 *)(puVar16 + 0x30) = 0;
      *(ulonglong *)(puVar16 + 0x28) = (ulonglong)uVar7;
      uVar17 = (ulonglong)uVar15;
      *(ulonglong *)(puVar16 + 0x20) = (ulonglong)uVar1;
      *(undefined8 *)(puVar16 + -8) = 0x1400249b1;
      pcVar14 = g_ModuleName;
      iVar9 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_140033040) {
        *(undefined8 *)(puVar16 + -8) = 0x1400249db;
        cVar5 = _tlgKeywordOn(0x140033040,0x400000000000);
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x78) = 10;
          local_e8 = puVar16 + 0x74;
          local_f0 = 4;
          local_d8 = puVar16 + 0x70;
          *(uint *)(puVar16 + 0x74) = uVar15;
          local_e0 = 4;
          *(uint *)(puVar16 + 0x70) = -(uint)(iVar8 != 0) & uVar1;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar16 + 0x6c) = -(uint)(iVar8 != 0) & uVar7;
          local_c8 = puVar16 + 0x6c;
          pcVar19 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar19 = g_ModuleName;
          }
          *(undefined8 *)(puVar16 + -8) = 0x140024a67;
          _tlgCreate1Sz_char(local_b8,pcVar19);
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          plVar11 = local_78;
          local_a8 = puVar16 + 0x68;
          local_a0 = 4;
          *(undefined4 *)(puVar16 + 100) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 100;
          local_88 = puVar16 + 0x60;
          local_90 = 4;
          *(int *)(puVar16 + 0x60) = iVar9;
          local_80 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140024abe;
          _tlgCreate1Sz_char(plVar11,"UCX01000.SYS");
          *(undefined4 *)(puVar16 + 0x5c) = *(undefined4 *)(puVar16 + 0x58);
          local_68 = puVar16 + 0x5c;
          *(undefined4 *)(puVar16 + 0x58) = param_5;
          local_58 = puVar16 + 0x58;
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xd;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140024b0f;
          _tlgWriteTransfer_EtwWriteTransfer
                    (plVar11,&DAT_140028e28,uVar17,pcVar14,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if (iVar9 != 0) goto LAB_140024b68;
      *(undefined8 *)(puVar16 + -8) = 0x140024b21;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar11[-4] == param_1) {
            *(int *)(plVar11 + -1) = (int)plVar11[-1] + 1;
            break;
          }
          plVar11 = (longlong *)*plVar11;
        } while ((longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x140024b63;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_140024b68:
  *(undefined8 *)(puVar16 + -8) = 0x140024b74;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140024b9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140024c2f;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140024c4c;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140033098;
    DAT_140033098 = 0;
    DAT_140033078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140024c76;
    EtwUnregister(uVar3);
    uVar3 = DAT_140033028;
    DAT_140033028 = 0;
    _DAT_140033008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140024c98;
    EtwUnregister(uVar3);
    uVar3 = DAT_140033060;
    DAT_140033060 = 0;
    DAT_140033040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140024cba;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140024cd4 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== __GSHandlerCheck @ 140024ce8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140024d0c =====

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



===== __cpu_features_init @ 140024d80 =====

/* WARNING: Removing unreachable block (ram,0x000140024dea) */
/* WARNING: Removing unreachable block (ram,0x000140024d99) */
/* WARNING: Removing unreachable block (ram,0x000140024d8a) */

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



===== __security_check_cookie @ 140024e50 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140024e90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140024ec0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140024ec0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140024ef0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140024f40 =====

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



===== memset @ 140025240 =====

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



===== __memset_repmovs @ 140025380 =====

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



===== __memset_query @ 140025400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140025480 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400255c0 =====

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



===== __memset_spec_plain @ 140025640 =====

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



===== WppCleanupKm @ 140034008 =====

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



===== WppInitKm @ 1400340b8 =====

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



===== WppLoadTracingSupport @ 140034194 =====

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



===== WppTraceCallback @ 1400342e0 =====

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



===== wil_UninitializeFeatureStaging @ 140034568 =====

void wil_UninitializeFeatureStaging(void)

{
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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400345c0 =====

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
      goto LAB_14003461d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14003461d;
    }
  }
  uVar1 = 0x206;
LAB_14003461d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140034628 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400346e0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140034718 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14003479a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14003479a;
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
LAB_14003479a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400347f0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140034850 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14003486c =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 140034920 =====

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



===== Registry_InitializeAllow64KLowOrFullSpeedControlTransfersFlag @ 1400349ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Registry_InitializeAllow64KLowOrFullSpeedControlTransfersFlag(void)

{
  int iVar1;
  int local_res8 [2];
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,&g_usbflagsKeyName,0x20019,0,local_res10);
  if (iVar1 < 0) {
    local_res10[0] = 0;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))
                      (WdfDriverGlobals,local_res10[0],
                       &g_Allow64KLowOrFullSpeedControlTransfersValueName,4,local_res8,0,0);
    if (-1 < iVar1) {
      g_Allow64KLowOrFullSpeedControlTransfersFlag = local_res8[0] == 1;
    }
  }
  if (local_res10[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== SleepstudyHelperInitializeOnce @ 140034ad0 =====

undefined8 SleepstudyHelperInitializeOnce(void)

{
  int iVar1;
  size_t _Size;
  undefined8 local_res20;
  int *local_18 [2];
  
  _Size = 0x110;
  local_18[0] = (int *)0x0;
  memset(&SleepstudyHelperRoutineBlock,0,0x110);
  local_res20 = 0x3f;
  iVar1 = ZwPowerInformation(0x57,&local_res20,8,local_18,8);
  if (iVar1 != -0x3fffff45) {
    if (iVar1 < 0) {
      return 0;
    }
    if (*local_18[0] == 1) {
      _Size = 0x108;
    }
    memmove(&SleepstudyHelperRoutineBlock,local_18[0],_Size);
  }
  return 1;
}



===== SleepstudyHelper_Initialize @ 140034b68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_Initialize(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = RtlRunOnceExecuteOnce
                    (&SleepstudyHelperInitializeRunOnce,SleepstudyHelperInitializeOnce,0,0);
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if ((iVar1 < 0) || (DAT_14002f280 == (code *)0x0)) {
      g_SleepstudyLibraryHandle = &SleepstudyHelperUnsupportedHandle;
      return 0;
    }
  }
  else {
    if (iVar1 < 0) {
      return iVar1;
    }
    if (DAT_14002f280 == (code *)0x0) {
      return -0x3fffff45;
    }
  }
  iVar1 = (*DAT_14002f280)(&g_SleepstudyLibraryHandle,param_2);
  return iVar1;
}



===== SleepstudyHelper_RegisterPdoWithParentPdo @ 140034c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SleepstudyHelper_RegisterPdoWithParentPdo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  puVar1 = g_SleepstudyLibraryHandle;
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (puVar1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14002f298 == (code *)0x0) {
        uVar3 = 0xc00000bb;
      }
      else {
        uVar3 = (*DAT_14002f298)(puVar1,param_2,param_3,param_4);
      }
      if ((int)uVar3 != -0x3fffff45) {
        return uVar3;
      }
    }
    *param_4 = &SleepstudyHelperUnsupportedHandle;
    uVar3 = 0;
  }
  else if (DAT_14002f298 == (code *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar3 = (*DAT_14002f298)(puVar1,param_2,param_3,param_4);
  }
  return uVar3;
}



===== SleepstudyHelper_Uninitialize @ 140034cb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SleepstudyHelper_Uninitialize(void)

{
  undefined *puVar1;
  ulonglong uVar2;
  
  puVar1 = g_SleepstudyLibraryHandle;
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) ||
     ((puVar1 != &SleepstudyHelperUnsupportedHandle && (DAT_14002f288 != (code *)0x0)))) {
    (*DAT_14002f288)(puVar1);
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140034d00 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x140034d63;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140034d83;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140034d97;
  return iVar6;
}



===== _tlgEnableCallback @ 140034db0 =====

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



===== __security_init_cookie @ 140035008 =====

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



===== wil_InitializeFeatureStaging @ 14003503c =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14003512c =====

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


