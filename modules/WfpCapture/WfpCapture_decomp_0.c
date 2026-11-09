
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



===== DriverCleanup @ 1c0001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverCleanup(undefined *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  
  uVar2 = 0;
  puVar3 = &DAT_1c00062f0;
  do {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0q_EtwWriteTransfer(param_1,&CalloutUnregister,param_3,uVar2);
    }
    param_1 = puVar3;
    iVar1 = FwpsCalloutUnregisterByKey0();
    if ((iVar1 < 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
      McTemplateK0qzq_EtwWriteTransfer
                (param_1,&CalloutUnregisterError,param_3,uVar2,L"",(char)iVar1);
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 0x10;
  } while (uVar2 < 0x22);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,gWdfDeviceObjectHandle);
  McGenEventUnregister_EtwUnregister();
  return;
}



===== DriverEntry @ 1c00010cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(undefined8 *****param_1,undefined8 *****param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *********pppppppppuVar3;
  undefined8 *****pppppuVar4;
  undefined8 *****pppppuVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined8 *****pppppuVar8;
  undefined1 auStackY_c8 [32];
  undefined8 *********local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  code *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 ****local_58;
  wchar_t *local_50;
  wchar_t local_48 [20];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_58 = (undefined8 ****)0x260024;
  local_80 = 0;
  local_88 = (undefined8 *********)0x0;
  local_68 = (code *)0x0;
  local_60 = 0;
  pppppuVar8 = (undefined8 *****)&WFP_CAPTURE_PROVIDER_Context;
  builtin_wcsncpy(local_48 + 8,L"WFPCapture",0xb);
  local_78 = 0;
  uStack_70 = 0;
  local_50 = local_48;
  builtin_wcsncpy(local_48,L"\\Device\\",8);
  pppppuVar5 = param_1;
  pppppppppuVar3 = (undefined8 *********)param_2;
  iVar1 = McGenEventRegister_EtwRegister();
  if (-1 < iVar1) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0zhh_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,&DriverLoad);
    }
    local_5c = 0;
    uStack_70 = 0;
    local_68 = EvtDriverUnload;
    local_78 = 0x20;
    local_60 = 1;
    pppppuVar5 = WdfDriverGlobals;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
    pppppppppuVar3 = (undefined8 *********)param_1;
    pppppuVar8 = param_2;
    if (-1 < iVar1) {
      pppppuVar8 = (undefined8 *****)&SDDL_DEVOBJ_KERNEL_ONLY;
      pppppuVar5 = WdfDriverGlobals;
      pppppppppuVar3 =
           (undefined8 *********)(**(code **)(WdfFunctions_01015 + 200))(WdfDriverGlobals,local_80);
      local_88 = pppppppppuVar3;
      if (pppppppppuVar3 == (undefined8 *********)0x0) {
        iVar1 = -0x3fddffe4;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,pppppppppuVar3,0x100,0);
        pppppuVar8 = &local_58;
        pppppuVar5 = WdfDriverGlobals;
        pppppppppuVar3 = local_88;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))();
        if (-1 < iVar1) {
          pppppppppuVar3 = &local_88;
          pppppuVar8 = (undefined8 *****)0x0;
          pppppuVar5 = WdfDriverGlobals;
          iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                            (WdfDriverGlobals,pppppppppuVar3,0,&gWdfDeviceObjectHandle);
          if (-1 < iVar1) {
            (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,gWdfDeviceObjectHandle);
            pppppuVar5 = WdfDriverGlobals;
            pppppuVar4 = (undefined8 *****)
                         (**(code **)(WdfFunctions_01015 + 0xf8))
                                   (WdfDriverGlobals,gWdfDeviceObjectHandle);
            ppuVar6 = &PTR_CoReg_inbound_transport_v4_1c0009000;
            uVar7 = 0;
            do {
              if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
                McTemplateK0q_EtwWriteTransfer(pppppuVar5,&CalloutRegister,pppppuVar8,uVar7);
              }
              pppppuVar5 = pppppuVar4;
              iVar2 = (*(code *)*ppuVar6)();
              if ((iVar2 < 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
                McTemplateK0qzq_EtwWriteTransfer
                          (pppppuVar5,&CalloutRegisterError,pppppuVar8,uVar7,L"",(char)iVar2);
              }
              uVar7 = uVar7 + 1;
              ppuVar6 = ppuVar6 + 1;
            } while (uVar7 < 0x22);
            return iVar1;
          }
        }
      }
    }
  }
  if ((WFP_CAPTURE_PROVIDER_Context != 0) &&
     ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
    pppppuVar5 = (undefined8 *****)&WFP_CAPTURE_PROVIDER_Context;
    McTemplateK0zq_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context);
  }
  DriverCleanup((undefined *)pppppuVar5,pppppppppuVar3,pppppuVar8);
  return iVar1;
}



===== EvtDriverUnload @ 1c00013a0 =====

void EvtDriverUnload(undefined8 *param_1,undefined *param_2,undefined8 param_3)

{
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
    param_2 = &DriverUnload;
    param_1 = &WFP_CAPTURE_PROVIDER_Context;
    McTemplateK0zhh_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,&DriverUnload);
  }
  DriverCleanup((undefined *)param_1,param_2,param_3);
  return;
}



===== McGenControlCallbackV2 @ 1c00013e0 =====

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



===== McGenEventRegister_EtwRegister @ 1c00014f0 =====

void McGenEventRegister_EtwRegister(void)

{
  longlong *in_R9;
  
  if (*in_R9 == 0) {
    EtwRegister(&WFP_CAPTURE_PROVIDER,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c0001524 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (WFP_CAPTURE_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    WFP_CAPTURE_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0001558 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0zhh_EtwWriteTransfer @ 1c00015b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zhh_EtwWriteTransfer(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  undefined2 local_68 [4];
  undefined2 local_60 [4];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined2 *local_38;
  undefined8 local_30;
  undefined2 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_60[0] = 0;
  local_68[0] = 1;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (L"WFPCapture"[lVar1] != L'\0');
  local_40 = (int)lVar1 * 2 + 2;
  local_48 = L"WFPCapture";
  local_38 = local_68;
  local_3c = 0;
  local_28 = local_60;
  local_30 = 2;
  local_20 = 2;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,4,local_58);
  return;
}



===== McTemplateK0zq_EtwWriteTransfer @ 1c0001660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zq_EtwWriteTransfer(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 uStack0000000000000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (L""[lVar1] != L'\0');
  local_30 = (int)lVar1 * 2 + 2;
  local_38 = L"";
  local_28 = &uStack0000000000000028;
  local_2c = 0;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DriverLoadError,0,3,local_48);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 1c00016ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
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
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,param_2,0,2,local_38);
  return;
}



===== McTemplateK0qzq_EtwWriteTransfer @ 1c0001754 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qzq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_40 = 4;
  if (param_5 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_20 = 4;
  local_28 = &param_6;
  local_res20[0] = param_4;
  local_38 = param_5;
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,param_2,0,4,local_58);
  return;
}



===== CoReg_ale_auth_connect_v4 @ 1c0001810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_ale_auth_connect_v4(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0xcddbddb4;
  uStack_44 = 0x479e662a;
  uStack_40 = 0xedf85284;
  uStack_3c = 0xfcfd742a;
  local_30 = ale_auth_connect_v4_classifyFn;
  local_20 = 0;
  local_28 = ale_auth_connect_v4_notifyFn;
  FwpsCalloutRegister3(0xcddbddb4,&local_48,&g_IdAleAuthConnectV4);
  return;
}



===== McTemplateK0qqhhxuuxxhbr9_EtwWriteTransfer @ 1c0001884 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqhhxuuxxhbr9_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined2 uStack0000000000000068;
  undefined1 auStackY_108 [32];
  undefined8 local_d8 [2];
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
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined8 local_30;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c8 = local_res20;
  local_c0 = 4;
  local_b0 = 4;
  local_b8 = &uStack0000000000000028;
  local_1c = 0;
  local_a8 = &uStack0000000000000030;
  local_a0 = 2;
  local_98 = &uStack0000000000000038;
  local_90 = 2;
  local_88 = &uStack0000000000000040;
  local_80 = 8;
  local_78 = &uStack0000000000000048;
  local_68 = &uStack0000000000000050;
  local_58 = &uStack0000000000000058;
  local_48 = &uStack0000000000000060;
  local_38 = &uStack0000000000000068;
  local_20 = (uint)uStack0000000000000068;
  local_70 = 1;
  local_60 = 1;
  local_50 = 8;
  local_40 = 8;
  local_30 = 2;
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,&AleAuthMessageV4,0,0xc,local_d8);
  return;
}



===== McTemplateK0xqx_EtwWriteTransfer @ 1c00019a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xqx_EtwWriteTransfer
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
  local_20 = 8;
  local_28 = &param_6;
  local_30 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,param_2,0,4,local_58);
  return;
}



===== ale_auth_connect_v4_classifyFn @ 1c0001a30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ale_auth_connect_v4_classifyFn(longlong param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined2 local_70;
  undefined2 local_68;
  undefined8 local_60;
  undefined1 local_58;
  undefined1 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 local_38;
  undefined1 *local_30;
  undefined1 local_28 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  uVar4 = 0;
  local_28[0] = 0;
  uVar5 = 0;
  if ((*param_2 & 2) != 0) {
    uVar5 = *(undefined8 *)(param_2 + 8);
    iVar3 = FwpsFlowAssociateContext0(uVar5,0x30,g_IdAleAuthConnectV4,uVar5);
    if (iVar3 == 0x40000000) {
      iVar3 = FwpsFlowRemoveContext0(uVar5,0x30,g_IdAleAuthConnectV4);
      if (iVar3 == 0) {
        FwpsFlowAssociateContext0(uVar5,0x30,g_IdAleAuthConnectV4,uVar5);
      }
    }
  }
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 4) != 0) {
    uVar1 = *param_2;
    if ((uVar1 & 8) == 0) {
      local_30 = local_28;
      local_38 = 0;
    }
    else {
      local_30 = *(undefined1 **)(*(undefined4 **)(param_2 + 0xc) + 2);
      local_38 = (undefined2)**(undefined4 **)(param_2 + 0xc);
    }
    if ((uVar1 & 0x20) != 0) {
      uVar4 = *(undefined8 *)(param_2 + 0x10);
    }
    local_58 = 2;
    if ((uVar1 >> 0x12 & 1) != 0) {
      local_58 = (undefined1)param_2[0x23];
    }
    lVar2 = *(longlong *)(param_1 + 8);
    local_50 = *(undefined1 *)(lVar2 + 0x58);
    local_60 = *(undefined8 *)(lVar2 + 0xb8);
    local_68 = *(undefined2 *)(lVar2 + 0x78);
    local_70 = *(undefined2 *)(lVar2 + 0x48);
    local_78 = *(undefined4 *)(lVar2 + 0x68);
    local_48 = uVar5;
    local_40 = uVar4;
    McTemplateK0qqhhxuuxxhbr9_EtwWriteTransfer();
  }
  return;
}



===== ale_auth_connect_v4_notifyFn @ 1c0001b90 =====

undefined8 ale_auth_connect_v4_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,4,uVar2);
  return 0;
}



===== CoReg_ale_auth_connect_v6 @ 1c0001c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_ale_auth_connect_v6(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0x229e3c19;
  uStack_44 = 0x4cb0d940;
  uStack_40 = 0x77bdc58b;
  uStack_3c = 0xb48d5966;
  local_30 = ale_auth_connect_v6_classifyFn;
  local_20 = 0;
  local_28 = ale_auth_connect_v6_notifyFn;
  FwpsCalloutRegister3(0x229e3c19,&local_48,&g_IdAleAuthConnectV6);
  return;
}



===== McTemplateK0b16b16hhxuuxxhbr9_EtwWriteTransfer @ 1c0001c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0b16b16hhxuuxxhbr9_EtwWriteTransfer(void)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined2 uStack0000000000000068;
  undefined1 auStackY_108 [32];
  undefined8 local_d8 [3];
  undefined8 local_c0;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
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
  undefined2 *local_38;
  undefined8 local_30;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_a8 = &uStack0000000000000030;
  local_98 = &uStack0000000000000038;
  local_1c = 0;
  local_88 = &uStack0000000000000040;
  local_c0 = 0x10;
  local_78 = &uStack0000000000000048;
  local_b0 = 0x10;
  local_68 = &uStack0000000000000050;
  local_58 = &uStack0000000000000058;
  local_48 = &uStack0000000000000060;
  local_38 = &uStack0000000000000068;
  local_20 = (uint)uStack0000000000000068;
  local_a0 = 2;
  local_90 = 2;
  local_80 = 8;
  local_70 = 1;
  local_60 = 1;
  local_50 = 8;
  local_40 = 8;
  local_30 = 2;
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,&AleAuthMessageV6,0,0xc,local_d8);
  return;
}



===== ale_auth_connect_v6_classifyFn @ 1c0001da0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ale_auth_connect_v6_classifyFn(longlong param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined2 local_70;
  undefined2 local_68;
  undefined8 local_60;
  undefined1 local_58;
  undefined1 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 local_38;
  undefined1 *local_30;
  undefined1 local_28 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  uVar4 = 0;
  local_28[0] = 0;
  uVar5 = 0;
  if ((*param_2 & 2) != 0) {
    uVar5 = *(undefined8 *)(param_2 + 8);
    iVar3 = FwpsFlowAssociateContext0(uVar5,0x32,g_IdAleAuthConnectV6,uVar5);
    if (iVar3 == 0x40000000) {
      iVar3 = FwpsFlowRemoveContext0(uVar5,0x32,g_IdAleAuthConnectV6);
      if (iVar3 == 0) {
        FwpsFlowAssociateContext0(uVar5,0x32,g_IdAleAuthConnectV6,uVar5);
      }
    }
  }
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 4) != 0) {
    uVar1 = *param_2;
    if ((uVar1 & 8) == 0) {
      local_30 = local_28;
      local_38 = 0;
    }
    else {
      local_30 = *(undefined1 **)(*(undefined4 **)(param_2 + 0xc) + 2);
      local_38 = (undefined2)**(undefined4 **)(param_2 + 0xc);
    }
    if ((uVar1 & 0x20) != 0) {
      uVar4 = *(undefined8 *)(param_2 + 0x10);
    }
    local_58 = 2;
    if ((uVar1 >> 0x12 & 1) != 0) {
      local_58 = (undefined1)param_2[0x23];
    }
    lVar2 = *(longlong *)(param_1 + 8);
    local_50 = *(undefined1 *)(lVar2 + 0x58);
    local_60 = *(undefined8 *)(lVar2 + 0xb8);
    local_68 = *(undefined2 *)(lVar2 + 0x78);
    local_70 = *(undefined2 *)(lVar2 + 0x48);
    local_78 = *(undefined8 *)(lVar2 + 0x68);
    local_48 = uVar5;
    local_40 = uVar4;
    McTemplateK0b16b16hhxuuxxhbr9_EtwWriteTransfer();
  }
  return;
}



===== ale_auth_connect_v6_notifyFn @ 1c0001f00 =====

undefined8 ale_auth_connect_v6_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,5,uVar2);
  return 0;
}



===== CoReg_ale_auth_recv_accept_v4 @ 1c0001f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_ale_auth_recv_accept_v4(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0x710df8ac;
  uStack_44 = 0x4bbadc3d;
  uStack_40 = 0xd62a848c;
  uStack_3c = 0xada08c43;
  local_30 = ale_auth_recv_accept_v4_classifyFn;
  local_20 = 0;
  local_28 = ale_auth_recv_accept_v4_notifyFn;
  FwpsCalloutRegister3(0x710df8ac,&local_48,&g_IdAleAuthRecvAcceptV4);
  return;
}



===== ale_auth_recv_accept_v4_classifyFn @ 1c0002000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ale_auth_recv_accept_v4_classifyFn(longlong param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined2 local_80;
  undefined2 local_78;
  undefined8 local_70;
  undefined1 local_68;
  undefined1 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 local_48;
  undefined1 *local_40;
  undefined1 local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar8 = local_38;
  uVar6 = 0;
  uVar5 = 2;
  local_38[0] = 0;
  uVar4 = 0;
  uVar7 = 0;
  if ((*param_2 & 2) != 0) {
    uVar4 = *(undefined8 *)(param_2 + 8);
    iVar3 = FwpsFlowAssociateContext0(uVar4,0x2c,g_IdAleAuthRecvAcceptV4,uVar4);
    if (iVar3 == 0x40000000) {
      iVar3 = FwpsFlowRemoveContext0(uVar4,0x2c,g_IdAleAuthRecvAcceptV4);
      if (iVar3 == 0) {
        FwpsFlowAssociateContext0(uVar4,0x2c,g_IdAleAuthRecvAcceptV4,uVar4);
      }
    }
  }
  lVar2 = *(longlong *)(param_1 + 8);
  local_88 = *(undefined4 *)(lVar2 + 0x68);
  local_60 = *(undefined1 *)(lVar2 + 0x58);
  local_80 = *(undefined2 *)(lVar2 + 0x48);
  local_78 = *(undefined2 *)(lVar2 + 0x78);
  local_70 = **(undefined8 **)(lVar2 + 0xa8);
  uVar1 = *param_2;
  if ((uVar1 >> 0x12 & 1) != 0) {
    uVar5 = (undefined1)param_2[0x23];
  }
  if ((uVar1 & 0x20) != 0) {
    uVar6 = *(undefined8 *)(param_2 + 0x10);
  }
  if ((uVar1 & 8) != 0) {
    uVar7 = **(undefined2 **)(param_2 + 0xc);
    puVar8 = *(undefined1 **)(*(undefined2 **)(param_2 + 0xc) + 4);
  }
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 4) != 0) {
    local_68 = uVar5;
    local_58 = uVar4;
    local_50 = uVar6;
    local_48 = uVar7;
    local_40 = puVar8;
    McTemplateK0qqhhxuuxxhbr9_EtwWriteTransfer();
  }
  return;
}



===== ale_auth_recv_accept_v4_notifyFn @ 1c0002170 =====

undefined8
ale_auth_recv_accept_v4_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,6,uVar2);
  return 0;
}



===== CoReg_ale_auth_recv_accept_v6 @ 1c00021f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_ale_auth_recv_accept_v6(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0xc3703e0b;
  uStack_44 = 0x40f3e8c3;
  uStack_40 = 0xe9eb9bb3;
  uStack_3c = 0xb37dc94d;
  local_30 = ale_auth_recv_accept_v6_classifyFn;
  local_20 = 0;
  local_28 = ale_auth_recv_accept_v6_notifyFn;
  FwpsCalloutRegister3(0xc3703e0b,&local_48,&g_IdAleAuthRecvAcceptV6);
  return;
}



===== ale_auth_recv_accept_v6_classifyFn @ 1c0002270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ale_auth_recv_accept_v6_classifyFn(longlong param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined2 local_70;
  undefined2 local_68;
  undefined8 local_60;
  undefined1 local_58;
  undefined1 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 local_38;
  undefined1 *local_30;
  undefined1 local_28 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  uVar4 = 0;
  local_28[0] = 0;
  uVar5 = 0;
  if ((*param_2 & 2) != 0) {
    uVar5 = *(undefined8 *)(param_2 + 8);
    iVar3 = FwpsFlowAssociateContext0(uVar5,0x2e,g_IdAleAuthRecvAcceptV6,uVar5);
    if (iVar3 == 0x40000000) {
      iVar3 = FwpsFlowRemoveContext0(uVar5,0x2e,g_IdAleAuthRecvAcceptV6);
      if (iVar3 == 0) {
        FwpsFlowAssociateContext0(uVar5,0x2e,g_IdAleAuthRecvAcceptV6,uVar5);
      }
    }
  }
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 4) != 0) {
    uVar1 = *param_2;
    if ((uVar1 & 8) == 0) {
      local_30 = local_28;
      local_38 = 0;
    }
    else {
      local_30 = *(undefined1 **)(*(undefined4 **)(param_2 + 0xc) + 2);
      local_38 = (undefined2)**(undefined4 **)(param_2 + 0xc);
    }
    if ((uVar1 & 0x20) != 0) {
      uVar4 = *(undefined8 *)(param_2 + 0x10);
    }
    local_58 = 2;
    if ((uVar1 >> 0x12 & 1) != 0) {
      local_58 = (undefined1)param_2[0x23];
    }
    lVar2 = *(longlong *)(param_1 + 8);
    local_50 = *(undefined1 *)(lVar2 + 0x58);
    local_60 = *(undefined8 *)(lVar2 + 0xa8);
    local_68 = *(undefined2 *)(lVar2 + 0x78);
    local_70 = *(undefined2 *)(lVar2 + 0x48);
    local_78 = *(undefined8 *)(lVar2 + 0x68);
    local_48 = uVar5;
    local_40 = uVar4;
    McTemplateK0b16b16hhxuuxxhbr9_EtwWriteTransfer();
  }
  return;
}



===== ale_auth_recv_accept_v6_notifyFn @ 1c00023d0 =====

undefined8
ale_auth_recv_accept_v6_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,7,uVar2);
  return 0;
}



===== CoReg_ale_auth_connect_v4_discard @ 1c0002450 =====

void CoReg_ale_auth_connect_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1e);
  return;
}



===== CoReg_ale_auth_connect_v6_discard @ 1c0002470 =====

void CoReg_ale_auth_connect_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1f);
  return;
}



===== CoReg_ale_auth_listen_v4_discard @ 1c0002490 =====

void CoReg_ale_auth_listen_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1a);
  return;
}



===== CoReg_ale_auth_listen_v6_discard @ 1c00024b0 =====

void CoReg_ale_auth_listen_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1b);
  return;
}



===== CoReg_ale_auth_recv_accept_v4_discard @ 1c00024d0 =====

void CoReg_ale_auth_recv_accept_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1c);
  return;
}



===== CoReg_ale_auth_recv_accept_v6_discard @ 1c00024f0 =====

void CoReg_ale_auth_recv_accept_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x1d);
  return;
}



===== CoReg_ale_flow_established_v4_discard @ 1c0002510 =====

void CoReg_ale_flow_established_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x20);
  return;
}



===== CoReg_ale_flow_established_v6_discard @ 1c0002530 =====

void CoReg_ale_flow_established_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x21);
  return;
}



===== CoReg_ale_resource_assignment_v4_discard @ 1c0002550 =====

void CoReg_ale_resource_assignment_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x18);
  return;
}



===== CoReg_ale_resource_assignment_v6_discard @ 1c0002570 =====

void CoReg_ale_resource_assignment_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x19);
  return;
}



===== CoReg_datagram_data_v4_discard @ 1c0002590 =====

void CoReg_datagram_data_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x12);
  return;
}



===== CoReg_datagram_data_v6_discard @ 1c00025b0 =====

void CoReg_datagram_data_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x13);
  return;
}



===== CoReg_discard @ 1c00025cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_discard(undefined8 param_1,int param_2)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  lVar1 = (longlong)param_2 * 0x10;
  local_48 = *(undefined4 *)(&DAT_1c0006d90 + lVar1);
  uStack_44 = *(undefined4 *)(&UNK_1c0006d94 + lVar1);
  uStack_40 = *(undefined4 *)(&UNK_1c0006d98 + lVar1);
  uStack_3c = *(undefined4 *)(&UNK_1c0006d9c + lVar1);
  local_30 = discard_classifyFn;
  local_28 = discard_notifyFn;
  local_20 = 0;
  FwpsCalloutRegister3(local_48,&local_48);
  return;
}



===== CoReg_inbound_icmp_error_v4_discard @ 1c0002650 =====

void CoReg_inbound_icmp_error_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x14);
  return;
}



===== CoReg_inbound_icmp_error_v6_discard @ 1c0002670 =====

void CoReg_inbound_icmp_error_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x15);
  return;
}



===== CoReg_inbound_ippacket_v4_discard @ 1c0002690 =====

void CoReg_inbound_ippacket_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,8);
  return;
}



===== CoReg_inbound_ippacket_v6_discard @ 1c00026b0 =====

void CoReg_inbound_ippacket_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,9);
  return;
}



===== CoReg_inbound_transport_v4_discard @ 1c00026d0 =====

void CoReg_inbound_transport_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0xe);
  return;
}



===== CoReg_inbound_transport_v6_discard @ 1c00026f0 =====

void CoReg_inbound_transport_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0xf);
  return;
}



===== CoReg_ipforward_v4_discard @ 1c0002710 =====

void CoReg_ipforward_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0xc);
  return;
}



===== CoReg_ipforward_v6_discard @ 1c0002730 =====

void CoReg_ipforward_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0xd);
  return;
}



===== CoReg_outbound_icmp_error_v4_discard @ 1c0002750 =====

void CoReg_outbound_icmp_error_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x16);
  return;
}



===== CoReg_outbound_icmp_error_v6_discard @ 1c0002770 =====

void CoReg_outbound_icmp_error_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x17);
  return;
}



===== CoReg_outbound_ippacket_v4_discard @ 1c0002790 =====

void CoReg_outbound_ippacket_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,10);
  return;
}



===== CoReg_outbound_ippacket_v6_discard @ 1c00027b0 =====

void CoReg_outbound_ippacket_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0xb);
  return;
}



===== CoReg_outbound_transport_v4_discard @ 1c00027d0 =====

void CoReg_outbound_transport_v4_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x10);
  return;
}



===== CoReg_outbound_transport_v6_discard @ 1c00027f0 =====

void CoReg_outbound_transport_v6_discard(undefined8 param_1)

{
  CoReg_discard(param_1,0x11);
  return;
}



===== McTemplateK0uqx_EtwWriteTransfer @ 1c000280c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uqx_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_40 = 1;
  local_38 = &uStack0000000000000028;
  local_20 = 8;
  local_28 = &uStack0000000000000030;
  local_30 = 4;
  McGenEventWrite_EtwWriteTransfer(&WFP_CAPTURE_PROVIDER_Context,&Discard,0,4,local_58);
  return;
}



===== discard_classifyFn @ 1c00028a0 =====

void discard_classifyFn(void)

{
  if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 0x10) != 0) {
    McTemplateK0uqx_EtwWriteTransfer();
  }
  return;
}



===== discard_notifyFn @ 1c00028e0 =====

undefined8 discard_notifyFn(void)

{
  return 0;
}



===== CoReg_inbound_transport_v4 @ 1c00028f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_inbound_transport_v4(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0xeab858e9;
  uStack_44 = 0x4648449a;
  uStack_40 = 0x13d7a391;
  uStack_3c = 0xf6836ec2;
  local_30 = inbound_transport_v4_classifyFn;
  local_20 = 0;
  local_28 = inbound_transport_v4_notifyFn;
  FwpsCalloutRegister3(0xeab858e9,&local_48,0);
  return;
}



===== inbound_transport_v4_classifyFn @ 1c0002960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void inbound_transport_v4_classifyFn
               (longlong param_1,longlong param_2,longlong *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong *plVar10;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if (param_3 == (longlong *)0x0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0qzq_EtwWriteTransfer(param_1,&CalloutClassifyError,0,0,L"Layer data is NULL.",0);
    }
  }
  else {
    iVar4 = NdisRetreatNetBufferListDataStart(param_3,*(undefined4 *)(param_2 + 0x2c),0,0);
    if (iVar4 == 0) {
      local_48 = 0;
      uStack_40 = 0;
      plVar8 = param_3;
      do {
        plVar10 = plVar8 + 1;
        plVar8 = (longlong *)*plVar8;
        puVar3 = (undefined8 *)*plVar10;
        while (puVar3 != (undefined8 *)0x0) {
          plVar10 = (longlong *)puVar3[4];
          puVar1 = (undefined8 *)*puVar3;
          uVar7 = *(uint *)(puVar3 + 5);
          if (plVar10 != (longlong *)0x0) {
            for (; *(uint *)(plVar10 + 5) <= uVar7; plVar10 = (longlong *)*plVar10) {
              uVar7 = uVar7 - *(uint *)(plVar10 + 5);
            }
          }
          puVar3[1] = plVar10;
          *(uint *)(puVar3 + 2) = uVar7;
          lVar2 = *(longlong *)(param_1 + 8);
          uVar9 = (ulonglong)CONCAT31((int3)(*(uint *)(puVar3 + 3) >> 8),*(undefined1 *)(lVar2 + 8))
          ;
          uVar6 = (ulonglong)*(uint *)(lVar2 + 0x18);
          uVar5 = TraceMdlTransV4(*(uint *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x28),
                                  *(undefined1 *)(lVar2 + 8),plVar10,uVar7,*(uint *)(puVar3 + 3),
                                  &local_48,param_6,1);
          puVar3 = puVar1;
          if (((int)uVar5 != 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
            McTemplateK0qzq_EtwWriteTransfer
                      (uVar6,&CalloutClassifyError,uVar9,0,L"Transport layer V4 trace failed.",
                       (char)uVar5);
          }
        }
      } while (plVar8 != (longlong *)0x0);
      NdisAdvanceNetBufferListDataStart(param_3,*(undefined4 *)(param_2 + 0x2c),0,0);
    }
  }
  return;
}



===== inbound_transport_v4_notifyFn @ 1c0002af0 =====

undefined8 inbound_transport_v4_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,0,uVar2);
  return 0;
}



===== CoReg_inbound_transport_v6 @ 1c0002b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_inbound_transport_v6(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0xe8aaa728;
  uStack_44 = 0x4c653c2a;
  uStack_40 = 0x8f890e97;
  uStack_3c = 0x5ea0c46b;
  local_30 = inbound_transport_v6_classifyFn;
  local_20 = 0;
  local_28 = inbound_transport_v6_notifyFn;
  FwpsCalloutRegister3(0xe8aaa728,&local_48,0);
  return;
}



===== inbound_transport_v6_classifyFn @ 1c0002be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void inbound_transport_v6_classifyFn
               (longlong param_1,longlong param_2,longlong *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = 0;
  uStack_40 = 0;
  if (param_3 == (longlong *)0x0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0qzq_EtwWriteTransfer(param_1,&CalloutClassifyError,0,2,L"Layer data is NULL.",0);
    }
  }
  else {
    iVar5 = NdisRetreatNetBufferListDataStart(param_3,*(undefined4 *)(param_2 + 0x2c),0,0);
    plVar9 = param_3;
    if (iVar5 == 0) {
      do {
        plVar1 = (longlong *)*plVar9;
        puVar4 = (undefined8 *)plVar9[1];
        while (puVar4 != (undefined8 *)0x0) {
          plVar9 = (longlong *)puVar4[4];
          puVar2 = (undefined8 *)*puVar4;
          uVar8 = *(uint *)(puVar4 + 5);
          if (plVar9 != (longlong *)0x0) {
            for (; *(uint *)(plVar9 + 5) <= uVar8; plVar9 = (longlong *)*plVar9) {
              uVar8 = uVar8 - *(uint *)(plVar9 + 5);
            }
          }
          puVar4[1] = plVar9;
          *(uint *)(puVar4 + 2) = uVar8;
          lVar3 = *(longlong *)(param_1 + 8);
          uVar10 = (ulonglong)
                   CONCAT31((int3)(*(uint *)(puVar4 + 3) >> 8),*(undefined1 *)(lVar3 + 8));
          puVar7 = *(undefined8 **)(lVar3 + 0x18);
          uVar6 = TraceMdlTransV6(puVar7,*(undefined8 **)(lVar3 + 0x28),*(undefined1 *)(lVar3 + 8),
                                  plVar9,uVar8,*(uint *)(puVar4 + 3),&local_48,param_6,1);
          puVar4 = puVar2;
          if (((int)uVar6 != 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
            McTemplateK0qzq_EtwWriteTransfer
                      (puVar7,&CalloutClassifyError,uVar10,2,L"Transport layer V6 trace failed.",
                       (char)uVar6);
          }
        }
        plVar9 = plVar1;
      } while (plVar1 != (longlong *)0x0);
      NdisAdvanceNetBufferListDataStart(param_3,*(undefined4 *)(param_2 + 0x2c),0,0);
    }
  }
  return;
}



===== inbound_transport_v6_notifyFn @ 1c0002d70 =====

undefined8 inbound_transport_v6_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,2,uVar2);
  return 0;
}



===== CoReg_outbound_transport_v4 @ 1c0002df0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_outbound_transport_v4(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0xcc15f5c6;
  uStack_44 = 0x4d3d93ec;
  uStack_40 = 0xe8980abb;
  uStack_3c = 0x67e7feab;
  local_30 = outbound_transport_v4_classifyFn;
  local_20 = 0;
  local_28 = outbound_transport_v4_notifyFn;
  FwpsCalloutRegister3(0xcc15f5c6,&local_48,0);
  return;
}



===== outbound_transport_v4_classifyFn @ 1c0002e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void outbound_transport_v4_classifyFn
               (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 == (longlong *)0x0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0qzq_EtwWriteTransfer(param_1,&CalloutClassifyError,0,1,L"Layer data is NULL.",0);
    }
  }
  else {
    do {
      plVar8 = param_3 + 1;
      param_3 = (longlong *)*param_3;
      puVar3 = (undefined8 *)*plVar8;
      while (puVar3 != (undefined8 *)0x0) {
        plVar8 = (longlong *)puVar3[4];
        puVar1 = (undefined8 *)*puVar3;
        uVar6 = *(uint *)(puVar3 + 5);
        if (plVar8 != (longlong *)0x0) {
          for (; *(uint *)(plVar8 + 5) <= uVar6; plVar8 = (longlong *)*plVar8) {
            uVar6 = uVar6 - *(uint *)(plVar8 + 5);
          }
        }
        puVar3[1] = plVar8;
        *(uint *)(puVar3 + 2) = uVar6;
        lVar2 = *(longlong *)(param_1 + 8);
        uVar7 = (ulonglong)CONCAT31((int3)(*(uint *)(puVar3 + 3) >> 8),*(undefined1 *)(lVar2 + 8));
        uVar5 = (ulonglong)*(uint *)(lVar2 + 0x18);
        uVar4 = TraceMdlTransV4(*(uint *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x38),
                                *(undefined1 *)(lVar2 + 8),plVar8,uVar6,*(uint *)(puVar3 + 3),
                                &local_38,param_6,0);
        puVar3 = puVar1;
        if (((int)uVar4 != 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
          McTemplateK0qzq_EtwWriteTransfer
                    (uVar5,&CalloutClassifyError,uVar7,1,L"Transport layer V4 trace failed.",
                     (char)uVar4);
        }
      }
    } while (param_3 != (longlong *)0x0);
  }
  return;
}



===== outbound_transport_v4_notifyFn @ 1c0002fa0 =====

undefined8 outbound_transport_v4_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,1,uVar2);
  return 0;
}



===== CoReg_outbound_transport_v6 @ 1c0003020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CoReg_outbound_transport_v6(void)

{
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38 = 0;
  local_48 = 0x83c7edae;
  uStack_44 = 0x4bcb53e7;
  uStack_40 = 0x1ccf2c8f;
  uStack_3c = 0x9355aecc;
  local_30 = outbound_transport_v6_classifyFn;
  local_20 = 0;
  local_28 = outbound_transport_v6_notifyFn;
  FwpsCalloutRegister3(0x83c7edae,&local_48,0);
  return;
}



===== outbound_transport_v6_classifyFn @ 1c0003090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void outbound_transport_v6_classifyFn
               (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 auStackY_88 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 == (longlong *)0x0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0) {
      McTemplateK0qzq_EtwWriteTransfer(param_1,&CalloutClassifyError,0,3,L"Layer data is NULL.",0);
    }
  }
  else {
    do {
      plVar8 = param_3 + 1;
      param_3 = (longlong *)*param_3;
      puVar3 = (undefined8 *)*plVar8;
      while (puVar3 != (undefined8 *)0x0) {
        plVar8 = (longlong *)puVar3[4];
        puVar1 = (undefined8 *)*puVar3;
        uVar6 = *(uint *)(puVar3 + 5);
        if (plVar8 != (longlong *)0x0) {
          for (; *(uint *)(plVar8 + 5) <= uVar6; plVar8 = (longlong *)*plVar8) {
            uVar6 = uVar6 - *(uint *)(plVar8 + 5);
          }
        }
        puVar3[1] = plVar8;
        *(uint *)(puVar3 + 2) = uVar6;
        lVar2 = *(longlong *)(param_1 + 8);
        uVar7 = (ulonglong)CONCAT31((int3)(*(uint *)(puVar3 + 3) >> 8),*(undefined1 *)(lVar2 + 8));
        puVar5 = *(undefined8 **)(lVar2 + 0x18);
        uVar4 = TraceMdlTransV6(puVar5,*(undefined8 **)(lVar2 + 0x38),*(undefined1 *)(lVar2 + 8),
                                plVar8,uVar6,*(uint *)(puVar3 + 3),&local_38,param_6,0);
        puVar3 = puVar1;
        if (((int)uVar4 != 0) && ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) != 0)) {
          McTemplateK0qzq_EtwWriteTransfer
                    (puVar5,&CalloutClassifyError,uVar7,3,L"Transport layer V6 trace failed.",
                     (char)uVar4);
        }
      }
    } while (param_3 != (longlong *)0x0);
  }
  return;
}



===== outbound_transport_v6_notifyFn @ 1c00031d0 =====

undefined8 outbound_transport_v6_notifyFn(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((int)param_1 == 0) {
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & 1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterAdd;
  }
  else {
    if ((int)param_1 != 1) {
      return 0;
    }
    if ((Microsoft_Pef_WFP_MessageProviderEnableBits & (byte)param_1) == 0) {
      return 0;
    }
    if (*(int *)(param_3 + 1) != 0) {
      uVar2 = (undefined1)*(undefined8 *)param_3[2];
    }
    puVar1 = &CalloutNotifyFilterDelete;
  }
  McTemplateK0xqx_EtwWriteTransfer(param_1,puVar1,param_3,*param_3,3,uVar2);
  return 0;
}



===== EventWriteExTransportMessage2V4 @ 1c0003244 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EventWriteExTransportMessage2V4
               (ulonglong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,ushort param_7,undefined8 param_8)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStack_b8 [32];
  undefined4 **local_98;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_70 = 4;
  local_1c = 0;
  local_88 = 0x41000ea6c;
  local_60 = 4;
  local_50 = 1;
  uStack_80 = param_1 | 0x8000060000000000;
  local_40 = 8;
  local_78 = local_res18;
  local_30 = 2;
  local_68 = local_res20;
  local_58 = &param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = param_8;
  local_20 = (uint)param_7;
  local_98 = &local_78;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  EtwWrite(WFP_CAPTURE_PROVIDER_Context,&local_88,param_2,6);
  return;
}



===== EventWriteExTransportMessage2V6 @ 1c0003330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EventWriteExTransportMessage2V6
               (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,ushort param_7,undefined8 param_8)

{
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = 0x41000ea76;
  local_70 = 0x10;
  local_60 = 0x10;
  uStack_80 = param_1 | 0x8000060000000000;
  local_50 = 1;
  local_58 = &param_5;
  local_1c = 0;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = param_8;
  local_20 = (uint)param_7;
  local_98 = &local_78;
  local_40 = 8;
  local_30 = 2;
  local_78 = param_3;
  local_68 = param_4;
  EtwWrite(WFP_CAPTURE_PROVIDER_Context,&local_88,param_2,6);
  return;
}



===== McTemplateK0hqqbr2_EtwWriteTransfer @ 1c0003408 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqbr2_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined1 param_5,undefined4 param_6,undefined8 param_7)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined2 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 2;
  local_58 = local_res20;
  local_40 = 4;
  local_48 = &param_5;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = param_6;
  local_30 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== TraceMdlTransV4 @ 1c000349c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
TraceMdlTransV4(undefined4 param_1,undefined4 param_2,undefined1 param_3,longlong *param_4,
               uint param_5,uint param_6,undefined8 param_7,undefined8 param_8,byte param_9)

{
  uint uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  char cVar10;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  uint local_74;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_57;
  undefined1 uStack_56;
  undefined1 uStack_55;
  
  uVar5 = 0;
  cVar10 = '\0';
  uVar8 = 0x40000000;
  bVar2 = false;
  for (; (param_4 != (longlong *)0x0 && (*(uint *)(param_4 + 5) <= param_5));
      param_4 = (longlong *)*param_4) {
    param_5 = param_5 - *(uint *)(param_4 + 5);
  }
  if ((param_6 != 0) && (param_4 != (longlong *)0x0)) {
    uVar6 = (int)param_4[5] - param_5;
    local_74 = param_6;
    if (param_6 < uVar6) {
      uVar6 = param_6;
    }
    if ((*param_4 != 0) && (uVar6 < param_6)) {
      bVar2 = true;
      LOCK();
      UNLOCK();
      cVar10 = (char)DAT_1c0009288 + '\x01';
      DAT_1c0009288 = DAT_1c0009288 + 1;
    }
    if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
      lVar9 = MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000000);
    }
    else {
      lVar9 = param_4[3];
    }
    if (lVar9 == 0) {
      return 0xc000009a;
    }
    lVar9 = lVar9 + (ulonglong)param_5;
    do {
      uVar7 = uVar8 | 0x80000000;
      if (local_74 != uVar6) {
        uVar7 = uVar8;
      }
      uVar3 = (-(ulonglong)(param_9 != 0) & 0x100000000) + 0x100000000;
      uVar8 = uVar3 & 0x200000000;
      if (bVar2) {
        if (uVar8 == 0) {
          if ((uVar7 & 0x40000000) == 0) {
            if (uVar7 >> 0x1f == 0) {
              if ((((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                  ((_DAT_1c0009120 & 0x8000060100000000) != 0)) &&
                 ((DAT_1c0009128 & 0x8000060100000000) == DAT_1c0009128)) goto LAB_1c0003872;
            }
            else if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                    (((_DAT_1c0009120 & 0x8000060180000000) != 0 &&
                     ((DAT_1c0009128 & 0x8000060180000000) == DAT_1c0009128)))) {
              puVar4 = &OutboundEndFragment;
              goto LAB_1c0003879;
            }
          }
          else {
            WriteStartFragmentV4
                      (param_7,param_1,param_2,param_3,(short)param_6,param_8,cVar10,(uint)param_9);
            if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
               (((_DAT_1c0009120 & 0x8000060100000000) != 0 &&
                ((DAT_1c0009128 & 0x8000060100000000) == DAT_1c0009128)))) {
LAB_1c0003872:
              puVar4 = &OutboundMiddleFragment;
              goto LAB_1c0003879;
            }
          }
        }
        else if ((uVar7 & 0x40000000) == 0) {
          if (uVar7 >> 0x1f == 0) {
            if ((((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                ((_DAT_1c0009120 & 0x8000060200000000) != 0)) &&
               ((DAT_1c0009128 & 0x8000060200000000) == DAT_1c0009128)) goto LAB_1c0003694;
          }
          else if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                  (((_DAT_1c0009120 & 0x8000060280000000) != 0 &&
                   ((DAT_1c0009128 & 0x8000060280000000) == DAT_1c0009128)))) {
            puVar4 = &InboundEndFragment;
            goto LAB_1c0003879;
          }
        }
        else {
          WriteStartFragmentV4
                    (param_7,param_2,param_1,param_3,(short)param_6,param_8,cVar10,(uint)param_9);
          if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
             (((_DAT_1c0009120 & 0x8000060200000000) != 0 &&
              ((DAT_1c0009128 & 0x8000060200000000) == DAT_1c0009128)))) {
LAB_1c0003694:
            puVar4 = &InboundMiddleFragment;
LAB_1c0003879:
            McTemplateK0hqqbr2_EtwWriteTransfer
                      (&WFP_CAPTURE_PROVIDER_Context,puVar4,param_7,0xea6c,cVar10,uVar6,lVar9);
          }
        }
      }
      else {
        uStack_57 = (undefined1)((uint)param_1 >> 8);
        uStack_56 = (undefined1)((uint)param_1 >> 0x10);
        uStack_55 = (undefined1)((uint)param_1 >> 0x18);
        uStack_5f = (undefined1)((uint)param_2 >> 8);
        uStack_5e = (undefined1)((uint)param_2 >> 0x10);
        uStack_5d = (undefined1)((uint)param_2 >> 0x18);
        if (uVar8 == 0) {
          local_7c = CONCAT13((char)param_2,CONCAT12(uStack_5f,CONCAT11(uStack_5e,uStack_5d)));
          local_78 = CONCAT13((char)param_1,CONCAT12(uStack_57,CONCAT11(uStack_56,uStack_55)));
          local_80 = local_78;
          local_84 = local_7c;
        }
        else {
          local_84 = CONCAT13((char)param_1,CONCAT12(uStack_57,CONCAT11(uStack_56,uStack_55)));
          local_80 = CONCAT13((char)param_2,CONCAT12(uStack_5f,CONCAT11(uStack_5e,uStack_5d)));
        }
        EventWriteExTransportMessage2V4
                  (uVar7 | uVar3,param_7,local_80,local_84,param_3,(char)param_8,(ushort)uVar6,lVar9
                  );
      }
      uVar8 = 0;
      if (local_74 == uVar6) {
        return 0;
      }
      local_74 = local_74 - uVar6;
      do {
        param_4 = (longlong *)*param_4;
        if (param_4 == (longlong *)0x0) {
          return 0xc000003e;
        }
        uVar1 = *(uint *)(param_4 + 5);
      } while (uVar1 == 0);
      uVar6 = local_74;
      if (uVar1 <= local_74) {
        uVar6 = uVar1;
      }
      if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
        lVar9 = MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000000);
      }
      else {
        lVar9 = param_4[3];
      }
    } while (lVar9 != 0);
    uVar5 = 0xc000009a;
  }
  return uVar5;
}



===== TraceMdlTransV6 @ 1c00039f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
TraceMdlTransV6(undefined8 *param_1,undefined8 *param_2,undefined1 param_3,longlong *param_4,
               uint param_5,uint param_6,undefined8 param_7,undefined8 param_8,byte param_9)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  char cVar13;
  
  uVar3 = param_6;
  uVar6 = 0;
  bVar2 = false;
  uVar11 = 0x40000000;
  cVar13 = '\0';
  for (; (param_4 != (longlong *)0x0 && (*(uint *)(param_4 + 5) <= param_5));
      param_4 = (longlong *)*param_4) {
    param_5 = param_5 - *(uint *)(param_4 + 5);
  }
  if ((param_6 != 0) && (param_4 != (longlong *)0x0)) {
    uVar7 = (int)param_4[5] - param_5;
    if (param_6 < uVar7) {
      uVar7 = param_6;
    }
    if ((*param_4 != 0) && (uVar7 < param_6)) {
      bVar2 = true;
      LOCK();
      UNLOCK();
      cVar13 = (char)DAT_1c0009288 + '\x01';
      DAT_1c0009288 = DAT_1c0009288 + 1;
    }
    if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
      lVar12 = MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000000);
    }
    else {
      lVar12 = param_4[3];
    }
    if (lVar12 == 0) {
      return 0xc000009a;
    }
    lVar12 = lVar12 + (ulonglong)param_5;
    do {
      uVar10 = uVar11 | 0x80000000;
      if (param_6 != uVar7) {
        uVar10 = uVar11;
      }
      uVar4 = (-(ulonglong)(param_9 != 0) & 0x100000000) + 0x100000000;
      uVar11 = uVar4 & 0x200000000;
      if (bVar2) {
        if (uVar11 == 0) {
          if ((uVar10 & 0x40000000) == 0) {
            if (uVar10 >> 0x1f == 0) {
              if ((((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                  ((_DAT_1c0009120 & 0x8000060100000000) != 0)) &&
                 ((DAT_1c0009128 & 0x8000060100000000) == DAT_1c0009128)) goto LAB_1c0003dd5;
            }
            else if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                    (((_DAT_1c0009120 & 0x8000060180000000) != 0 &&
                     ((DAT_1c0009128 & 0x8000060180000000) == DAT_1c0009128)))) {
              puVar5 = &OutboundEndFragment;
              goto LAB_1c0003ddc;
            }
          }
          else {
            WriteStartFragmentV6
                      (param_7,param_1,param_2,param_3,(short)uVar3,param_8,cVar13,(uint)param_9);
            if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
               (((_DAT_1c0009120 & 0x8000060100000000) != 0 &&
                ((DAT_1c0009128 & 0x8000060100000000) == DAT_1c0009128)))) {
LAB_1c0003dd5:
              puVar5 = &OutboundMiddleFragment;
              goto LAB_1c0003ddc;
            }
          }
        }
        else if ((uVar10 & 0x40000000) == 0) {
          if (uVar10 >> 0x1f == 0) {
            if ((((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                ((_DAT_1c0009120 & 0x8000060200000000) != 0)) &&
               ((DAT_1c0009128 & 0x8000060200000000) == DAT_1c0009128)) goto LAB_1c0003bee;
          }
          else if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
                  (((_DAT_1c0009120 & 0x8000060280000000) != 0 &&
                   ((DAT_1c0009128 & 0x8000060280000000) == DAT_1c0009128)))) {
            puVar5 = &InboundEndFragment;
            goto LAB_1c0003ddc;
          }
        }
        else {
          WriteStartFragmentV6
                    (param_7,param_2,param_1,param_3,(short)uVar3,param_8,cVar13,(uint)param_9);
          if (((DAT_1c0009134 != 0) && (2 < (byte)(DAT_1c0009138 - 1U))) &&
             (((_DAT_1c0009120 & 0x8000060200000000) != 0 &&
              ((DAT_1c0009128 & 0x8000060200000000) == DAT_1c0009128)))) {
LAB_1c0003bee:
            puVar5 = &InboundMiddleFragment;
LAB_1c0003ddc:
            McTemplateK0hqqbr2_EtwWriteTransfer
                      (&WFP_CAPTURE_PROVIDER_Context,puVar5,param_7,0xea76,cVar13,uVar7,lVar12);
          }
        }
      }
      else {
        if (uVar11 == 0) {
          puVar8 = param_1;
          puVar9 = param_2;
        }
        else {
          puVar8 = param_2;
          puVar9 = param_1;
        }
        EventWriteExTransportMessage2V6
                  (uVar10 | uVar4,param_7,puVar8,puVar9,param_3,(char)param_8,(ushort)uVar7,lVar12);
      }
      uVar11 = 0;
      if (param_6 == uVar7) {
        return 0;
      }
      param_6 = param_6 - uVar7;
      do {
        param_4 = (longlong *)*param_4;
        if (param_4 == (longlong *)0x0) {
          return 0xc000003e;
        }
        uVar1 = *(uint *)(param_4 + 5);
      } while (uVar1 == 0);
      uVar7 = param_6;
      if (uVar1 <= param_6) {
        uVar7 = uVar1;
      }
      if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
        lVar12 = MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000000);
      }
      else {
        lVar12 = param_4[3];
      }
    } while (lVar12 != 0);
    uVar6 = 0xc000009a;
  }
  return uVar6;
}



===== WriteStartFragmentV4 @ 1c0003ee8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WriteStartFragmentV4
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined2 param_5,undefined8 param_6,undefined1 param_7,int param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined4 local_res10;
  undefined4 local_res18;
  undefined1 auStackY_78 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined8 local_27;
  undefined2 local_1f;
  ulonglong local_18;
  
  local_res18 = param_3;
  local_res10 = param_2;
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar3 = 0;
  lVar2 = 0;
  do {
    *(undefined1 *)((longlong)&local_38 + lVar3) = auStackY_78[lVar2 + 0x8b];
    lVar1 = lVar2 + 0x93;
    lVar2 = lVar2 + -1;
    *(undefined1 *)((longlong)&local_34 + lVar3) = auStackY_78[lVar1];
    lVar3 = lVar3 + 1;
  } while (-4 < lVar2);
  local_30 = local_38;
  local_2c = local_34;
  local_27 = param_6;
  local_1f = param_5;
  if (param_8 == 1) {
    if (DAT_1c0009134 == 0) {
      return;
    }
    if ((byte)(DAT_1c0009138 - 1U) < 3) {
      return;
    }
    if ((_DAT_1c0009120 & 0x8000060240000000) == 0) {
      return;
    }
    if ((DAT_1c0009128 & 0x8000060240000000) != DAT_1c0009128) {
      return;
    }
    puVar4 = &InboundStartFragment;
  }
  else {
    if (DAT_1c0009134 == 0) {
      return;
    }
    if ((byte)(DAT_1c0009138 - 1U) < 3) {
      return;
    }
    if ((_DAT_1c0009120 & 0x8000060140000000) == 0) {
      return;
    }
    if ((DAT_1c0009128 & 0x8000060140000000) != DAT_1c0009128) {
      return;
    }
    puVar4 = &OutboundStartFragment;
  }
  local_28 = param_4;
  McTemplateK0hqqbr2_EtwWriteTransfer
            (&WFP_CAPTURE_PROVIDER_Context,puVar4,param_1,0xea6c,param_7,0x13,&local_30);
  return;
}



===== WriteStartFragmentV6 @ 1c0004028 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WriteStartFragmentV6
               (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined1 param_4,
               undefined2 param_5,undefined8 param_6,undefined1 param_7,int param_8)

{
  undefined *puVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28;
  undefined8 local_27;
  undefined2 local_1f;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = *param_2;
  uStack_40 = param_2[1];
  local_27 = param_6;
  local_38 = *param_3;
  uStack_30 = param_3[1];
  local_1f = param_5;
  if (param_8 == 1) {
    if (DAT_1c0009134 == 0) {
      return;
    }
    if ((byte)(DAT_1c0009138 - 1U) < 3) {
      return;
    }
    if ((_DAT_1c0009120 & 0x8000060240000000) == 0) {
      return;
    }
    if ((DAT_1c0009128 & 0x8000060240000000) != DAT_1c0009128) {
      return;
    }
    puVar1 = &InboundStartFragment;
  }
  else {
    if (DAT_1c0009134 == 0) {
      return;
    }
    if ((byte)(DAT_1c0009138 - 1U) < 3) {
      return;
    }
    if ((_DAT_1c0009120 & 0x8000060140000000) == 0) {
      return;
    }
    if ((DAT_1c0009128 & 0x8000060140000000) != DAT_1c0009128) {
      return;
    }
    puVar1 = &OutboundStartFragment;
  }
  local_28 = param_4;
  McTemplateK0hqqbr2_EtwWriteTransfer
            (&WFP_CAPTURE_PROVIDER_Context,puVar1,param_1,0xea76,param_7,0x2b,&local_48);
  return;
}



===== FxStubDriverUnloadCommon @ 1c000415c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009258 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0009258 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c00041b5:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000420b;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0004223;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c00041b5;
LAB_1c000420b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0004223:
  WdfVersionUnbind(&DAT_1c00094b0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0004260 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 *****param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0004294 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 *****param_2)

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
    iVar1 = DriverEntry((undefined8 *****)0x0,param_2);
  }
  else {
    _DAT_1c00094b0 = 0x2080000;
    _DAT_1c00094b8 = &DAT_1c00092a0;
    RtlCopyUnicodeString(&DAT_1c00094b0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00094b0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((undefined8 *****)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00094a8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00094b0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009258 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0004420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00094a8 != (code *)0x0) && (DAT_1c00094a8 != FxStubDriverUnload)) {
    (*DAT_1c00094a8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0004454 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0004479) */
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
    if ((void **)0x1c000924f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0009258 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c00045dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00045f9) */
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
    if ((void **)0x1c000926f < ppvVar2) break;
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



===== _guard_check_icall @ 1c00046b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00046c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00046ec =====

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



===== __cpu_features_init @ 1c0004760 =====

/* WARNING: Removing unreachable block (ram,0x0001c00047ca) */
/* WARNING: Removing unreachable block (ram,0x0001c0004779) */
/* WARNING: Removing unreachable block (ram,0x0001c000476a) */

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



===== __security_check_cookie @ 1c0004830 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004870 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00048a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00048a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00048d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0004940 =====

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



===== __memset_repmovs @ 1c0004a80 =====

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



===== __memset_query @ 1c0004b00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004b80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004cc0 =====

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



===== __memset_spec_plain @ 1c0004d40 =====

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



===== __security_init_cookie @ 1c000c008 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  char *pcVar1;
  byte bVar2;
  code *pcVar3;
  byte bVar4;
  char cVar5;
  byte *pbVar6;
  undefined7 uVar8;
  byte *pbVar7;
  byte in_DL;
  byte in_DH;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar3 = (code *)swi(0x29);
    pbVar6 = (byte *)(*pcVar3)(6);
    bVar4 = (byte)pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + in_DL + CARRY1(bVar2,bVar4);
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    cVar5 = cRam10000013e0000013;
    uVar8 = (undefined7)((ulonglong)pbVar6 >> 8);
    pbVar7 = (byte *)CONCAT71(uVar8,cRam10000013e0000013);
    *pbVar7 = (*pbVar7 - cRam10000013e0000013) - CARRY1(bVar2,bVar4);
    bVar2 = *pbVar7;
    *pbVar7 = *pbVar7 + in_DH;
    cVar5 = (cVar5 - *pbVar7) - CARRY1(bVar2,in_DH);
    pbVar7 = (byte *)(CONCAT71(uVar8,cVar5) + 0x1000001b);
    bVar2 = *pbVar7;
    *pbVar7 = *pbVar7 + in_DL;
    pcVar1 = (char *)(CONCAT71(uVar8,cVar5 - CARRY1(bVar2,in_DL)) + 0x1d);
    *pcVar1 = *pcVar1 + (char)((ulonglong)pbVar6 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


