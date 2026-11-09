
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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
  *param_6 = PTR_DAT_140006050;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140006050;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140006068,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== PdcpResizeDiagnosticContext @ 1400010d0 =====

void PdcpResizeDiagnosticContext(ulonglong *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  
  uVar3 = 0;
  puVar1 = param_2;
  do {
    puVar4 = puVar1 + 4;
    uVar2 = (uint)uVar3;
    if (*param_1 <= uVar3) break;
    uVar2 = uVar2 + 1;
    uVar3 = (ulonglong)uVar2;
    *(undefined8 *)puVar4 =
         *(undefined8 *)(((longlong)param_1 - (longlong)param_2) + (longlong)puVar4);
    *(undefined8 *)(puVar1 + 2) =
         *(undefined8 *)(((longlong)param_1 - (longlong)param_2) + -8 + (longlong)puVar4);
    puVar1 = puVar4;
  } while (uVar2 < 10);
  *param_2 = uVar2;
  return;
}



===== Pdcv2pValidateExtraActivationParameters @ 140001110 =====

undefined8 Pdcv2pValidateExtraActivationParameters(int *param_1,int param_2)

{
  uint uVar1;
  ulonglong *puVar2;
  ulonglong in_RAX;
  undefined1 uVar3;
  
  uVar3 = 1;
  if (param_1 != (int *)0x0) {
    uVar1 = *param_1;
    in_RAX = (ulonglong)uVar1;
    if ((uVar1 == 1) ||
       (((uVar1 == 2 &&
         ((puVar2 = *(ulonglong **)(param_1 + 8), puVar2 == (ulonglong *)0x0 || (*puVar2 < 8)))) &&
        ((param_2 != 4 ||
         ((((puVar2 != (ulonglong *)0x0 && ((*puVar2 & 1) != 0)) && (puVar2[1] != 0)) &&
          (puVar2[2] == 0)))))))) goto LAB_140001156;
  }
  uVar3 = 0;
LAB_140001156:
  return CONCAT71((int7)(in_RAX >> 8),uVar3);
}



===== PdcPortSendMessageSynchronously @ 140001164 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcPortSendMessageSynchronously(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ExAcquireRundownProtection(param_1 + 8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0000189;
  }
  else {
    *(undefined4 *)(param_2 + 0x2c) = 6;
    uVar2 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x18),param_2,800);
    ExReleaseRundownProtection(param_1 + 8);
  }
  return uVar2;
}



===== PdcResetEvent @ 1400011e0 =====

void PdcResetEvent(void)

{
  KeResetEvent();
  return;
}



===== McGenControlCallbackV2 @ 140001200 =====

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



===== McGenEventRegister_EtwRegister @ 140001310 =====

void McGenEventRegister_EtwRegister(void)

{
  if (PDC_EVENT_PROVIDER_Context == 0) {
    EtwRegister(&PDC_EVENT_PROVIDER,McGenControlCallbackV2,&PDC_EVENT_PROVIDER_Context,
                &PDC_EVENT_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001350 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (PDC_EVENT_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    PDC_EVENT_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001384 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140006008;
  uVar2 = 0;
  if (DAT_140006008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140006008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(PDC_EVENT_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateU0qqqqzr3_EtwWriteTransfer @ 1400013e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqqzr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined1 param_5,int param_6,undefined8 param_7)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 4;
  local_68 = local_res18;
  local_50 = 4;
  local_58 = local_res20;
  local_48 = &param_5;
  local_38 = &param_6;
  local_40 = 4;
  local_28 = param_7;
  local_20 = param_6 * 2;
  local_30 = 4;
  local_1c = 0;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,6,local_78);
  return;
}



===== McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer @ 140001494 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,int param_14,undefined8 param_15)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_128 [32];
  undefined8 local_f8 [2];
  undefined4 *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  int local_c0;
  undefined4 local_bc;
  int *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  int local_a0;
  undefined4 local_9c;
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
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e0 = 4;
  local_e8 = local_res18;
  local_bc = 0;
  local_d8 = local_res20;
  local_c8 = param_5;
  local_c0 = param_4 * 2;
  local_b8 = &param_6;
  local_9c = 0;
  local_a8 = param_7;
  local_a0 = param_6 * 2;
  local_1c = 0;
  local_98 = &param_8;
  local_d0 = 4;
  local_88 = &param_9;
  local_78 = &param_10;
  local_68 = &param_11;
  local_58 = &param_12;
  local_48 = &param_13;
  local_38 = &param_14;
  local_28 = param_15;
  local_20 = param_14 * 2;
  local_b0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 8;
  local_40 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_ACTIVATE,param_3,0xe,local_f8);
  return;
}



===== McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer @ 1400015e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,int param_16,
               undefined8 param_17,undefined1 param_18)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_158 [32];
  undefined8 local_128 [2];
  undefined4 *local_118;
  undefined8 local_110;
  int *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  int local_f0;
  undefined4 local_ec;
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  int local_d0;
  undefined4 local_cc;
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
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_110 = 4;
  local_118 = local_res18;
  local_ec = 0;
  local_108 = local_res20;
  local_f8 = param_5;
  local_f0 = param_4 * 2;
  local_e8 = &param_6;
  local_cc = 0;
  local_d8 = param_7;
  local_d0 = param_6 * 2;
  local_2c = 0;
  local_c8 = &param_8;
  local_100 = 4;
  local_b8 = &param_9;
  local_a8 = &param_10;
  local_98 = &param_11;
  local_88 = &param_12;
  local_78 = &param_13;
  local_68 = &param_14;
  local_58 = &param_15;
  local_48 = &param_16;
  local_38 = param_17;
  local_30 = param_16 * 2;
  local_e0 = 4;
  local_28 = &param_18;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 8;
  local_80 = 4;
  local_70 = 8;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_CALLBACK,param_3,0x11,local_128);
  return;
}



===== McTemplateU0qqzr1qzr3qqqxqqqpqzr13_EtwWriteTransfer @ 140001784 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqxqqqpqzr13_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,int param_16,
               undefined8 param_17)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_148 [32];
  undefined8 local_118 [2];
  undefined4 *local_108;
  undefined8 local_100;
  int *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  int local_e0;
  undefined4 local_dc;
  int *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  int local_c0;
  undefined4 local_bc;
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
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  local_100 = 4;
  local_108 = local_res18;
  local_f0 = 4;
  local_f8 = local_res20;
  local_dc = 0;
  local_e8 = param_5;
  local_e0 = param_4 * 2;
  local_d8 = &param_6;
  local_d0 = 4;
  local_c8 = param_7;
  local_c0 = param_6 * 2;
  local_bc = 0;
  local_b8 = &param_8;
  local_a8 = &param_9;
  local_98 = &param_10;
  local_88 = &param_11;
  local_78 = &param_12;
  local_68 = &param_13;
  local_58 = &param_14;
  local_48 = &param_15;
  local_38 = &param_16;
  local_28 = param_17;
  local_20 = param_16 * 2;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 8;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 8;
  local_30 = 4;
  local_1c = 0;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_SET_BROKERED_PID,0,0x10,local_118);
  return;
}



===== McTemplateU0qqzr1qzr3qqqxqqqpqzr13q_EtwWriteTransfer @ 14000190c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqxqqqpqzr13q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,int param_16,
               undefined8 param_17,undefined1 param_18)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_158 [32];
  undefined8 local_128 [2];
  undefined4 *local_118;
  undefined8 local_110;
  int *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  int local_f0;
  undefined4 local_ec;
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  int local_d0;
  undefined4 local_cc;
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
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_110 = 4;
  local_118 = local_res18;
  local_ec = 0;
  local_108 = local_res20;
  local_f8 = param_5;
  local_f0 = param_4 * 2;
  local_e8 = &param_6;
  local_cc = 0;
  local_d8 = param_7;
  local_d0 = param_6 * 2;
  local_2c = 0;
  local_c8 = &param_8;
  local_100 = 4;
  local_b8 = &param_9;
  local_a8 = &param_10;
  local_98 = &param_11;
  local_88 = &param_12;
  local_78 = &param_13;
  local_68 = &param_14;
  local_58 = &param_15;
  local_48 = &param_16;
  local_38 = param_17;
  local_30 = param_16 * 2;
  local_e0 = 4;
  local_28 = &param_18;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 8;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 8;
  local_40 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&PDCV2_ACTIVATION_RENEW_ACTIVATION,param_3,0x11,local_128);
  return;
}



===== McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer @ 140001aac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,int param_14,undefined8 param_15,undefined1 param_16)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_138 [32];
  undefined8 local_108 [2];
  undefined4 *local_f8;
  undefined8 local_f0;
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  int local_d0;
  undefined4 local_cc;
  int *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  int local_b0;
  undefined4 local_ac;
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
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  local_f0 = 4;
  local_f8 = local_res18;
  local_cc = 0;
  local_e8 = local_res20;
  local_d8 = param_5;
  local_d0 = param_4 * 2;
  local_c8 = &param_6;
  local_ac = 0;
  local_b8 = param_7;
  local_b0 = param_6 * 2;
  local_2c = 0;
  local_a8 = &param_8;
  local_e0 = 4;
  local_98 = &param_9;
  local_88 = &param_10;
  local_78 = &param_11;
  local_68 = &param_12;
  local_58 = &param_13;
  local_48 = &param_14;
  local_38 = param_15;
  local_30 = param_14 * 2;
  local_c0 = 4;
  local_28 = &param_16;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 8;
  local_70 = 4;
  local_60 = 8;
  local_50 = 4;
  local_40 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_DEACTIVATE,param_3,0xf,local_108);
  return;
}



===== PdcInitializeETW @ 140001c18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcInitializeETW(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  bool bVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  LOCK();
  iVar3 = g_RegistrationCount + 1;
  UNLOCK();
  bVar5 = g_RegistrationCount == 0;
  g_RegistrationCount = iVar3;
  if (bVar5) {
    McGenEventRegister_EtwRegister();
    local_28 = *(undefined4 *)(PTR_DAT_140006050 + -0x10);
    uStack_24 = *(undefined4 *)(PTR_DAT_140006050 + -0xc);
    uStack_20 = *(undefined4 *)(PTR_DAT_140006050 + -8);
    uStack_1c = *(undefined4 *)(PTR_DAT_140006050 + -4);
    puVar4 = auStack_48;
    if (DAT_140006068 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar4 = auStack_40;
    }
    _DAT_140006070 = 0;
    uRam0000000140006078 = 0;
    *(undefined8 *)(puVar4 + -8) = 0x140001c92;
    iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140006048,&DAT_140006068);
    if (iVar3 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_140006050;
      *(undefined8 *)(puVar4 + -8) = 0x140001cb7;
      EtwSetInformation(DAT_140006068,2,PTR_DAT_140006050,uVar1);
    }
  }
  *(undefined8 *)(puVar4 + -8) = 0x140001cc9;
  return;
}



===== PdcUninitializeETW @ 140001cd8 =====

void PdcUninitializeETW(void)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  
  uVar2 = DAT_140006068;
  LOCK();
  iVar1 = g_RegistrationCount + -1;
  UNLOCK();
  bVar3 = g_RegistrationCount == 1;
  g_RegistrationCount = iVar1;
  if (bVar3) {
    DAT_140006068 = 0;
    DAT_140006048 = 0;
    EtwUnregister(uVar2);
    McGenEventUnregister_EtwUnregister();
  }
  return;
}



===== PdcpFormatTaskName @ 140001d20 =====

void PdcpFormatTaskName(uint param_1,undefined4 *param_2)

{
  short sVar1;
  uint uVar2;
  short sVar3;
  
  *param_2 = 0x310056;
  *(undefined2 *)(param_2 + 3) = 0;
  *(undefined2 *)(param_2 + 1) = 0x5f;
  sVar3 = (short)(param_1 / 10);
  uVar2 = (param_1 / 10) / 10;
  sVar1 = (short)uVar2;
  *(short *)((longlong)param_2 + 10) = (short)param_1 + sVar3 * -10 + 0x30;
  *(short *)((longlong)param_2 + 6) = sVar1 + (short)((ulonglong)uVar2 / 10) * -10 + 0x30;
  *(short *)(param_2 + 2) = sVar3 + sVar1 * -10 + 0x30;
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE @ 140001dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStackY_b8 [32];
  short local_38 [8];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar3 = 0xff;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  uVar4 = 0xffffffff;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar4 = *(uint *)(param_1 + 0x20);
    uVar3 = (undefined1)*(undefined4 *)(param_1 + 200);
    PdcpFormatTaskName(uVar4,(undefined4 *)local_38);
    pwVar2 = (wchar_t *)(param_1 + 0x46);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar5 = -1;
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    do {
      lVar5 = lVar5 + 1;
    } while (local_38[lVar5] != 0);
    McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer
              (pwVar2,local_38,(ulonglong)uVar4,(int)lVar5,local_38,10,L"V1_Unknown",uVar3,0xff,0xff
               ,param_2,(char)param_1,1,(int)lVar1,pwVar2);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK @ 140001ed4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK(longlong param_1,int param_2,ulonglong param_3)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStackY_1e8 [32];
  uint local_158;
  uint local_154;
  uint local_150;
  int local_14c [5];
  longlong local_138;
  longlong local_130;
  undefined8 local_128 [4];
  uint *local_108;
  undefined8 local_100;
  short *local_f8;
  int local_f0;
  undefined4 local_ec;
  wchar_t *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  int *local_b8;
  undefined8 local_b0;
  int *local_a8;
  undefined8 local_a0;
  longlong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  short local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_154 = (uint)param_3;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  lVar4 = -1;
  local_48[6] = 0;
  local_58 = L"";
  uVar3 = 0xffffffff;
  local_158 = 0xffffffff;
  lVar8 = -1;
  uVar9 = 0xffffffff;
  if (param_1 != 0) {
    local_158 = *(uint *)(param_1 + 200);
    uVar9 = *(uint *)(param_1 + 0x20);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    lVar8 = SUB168(auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8) -
            *(longlong *)(param_1 + 0xd0);
    PdcpFormatTaskName(uVar9,(undefined4 *)local_48);
    uVar3 = (ulonglong)local_158;
    local_58 = (wchar_t *)(param_1 + 0x46);
    param_3 = (ulonglong)local_154;
  }
  iVar7 = 0x65;
  if (param_2 != 0) {
    iVar7 = param_2;
  }
  uVar5 = param_3;
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (local_48[lVar6] != 0);
    uVar5 = (ulonglong)uVar9;
    McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer
              (uVar3,0,uVar5,(int)lVar6,local_48,10,L"V1_Unknown",(char)iVar7,(char)uVar3,0xff,
               (char)lVar8,(char)param_3,(char)param_1,0xff,1,(int)lVar2,local_58,0);
  }
  if (5 < DAT_140006048) {
    local_108 = &local_150;
    lVar2 = -1;
    local_100 = 4;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != 0);
    local_f0 = (int)lVar2 * 2 + 2;
    local_ec = 0;
    local_f8 = local_48;
    local_d8 = local_14c;
    local_c8 = &local_158;
    local_b8 = local_14c + 1;
    local_a8 = local_14c + 2;
    local_98 = &local_138;
    local_88 = &local_130;
    local_78 = &local_154;
    local_68 = local_14c + 3;
    local_e8 = L"V1_Unknown";
    local_e0 = 0x16;
    local_d0 = 4;
    local_c0 = 4;
    local_14c[1] = 0xffffffff;
    local_b0 = 4;
    local_14c[2] = 0xffffffff;
    local_a0 = 4;
    local_90 = 8;
    local_80 = 8;
    local_70 = 4;
    local_14c[3] = 1;
    local_60 = 4;
    if (local_58 == (wchar_t *)0x0) {
      local_58 = L"";
      local_50 = 2;
    }
    else {
      do {
        lVar4 = lVar4 + 1;
      } while (local_58[lVar4] != L'\0');
      local_50 = (int)lVar4 * 2 + 2;
    }
    local_4c = 0;
    local_150 = uVar9;
    local_14c[0] = iVar7;
    local_138 = lVar8;
    local_130 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0xffffffff,&DAT_140005438,uVar5,L"V1_Unknown",0xe,local_128);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE @ 1400021e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE
               (longlong param_1,undefined4 param_2,ulonglong param_3,longlong param_4)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_1b8 [32];
  uint local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128 [2];
  ulonglong local_120;
  longlong local_118 [2];
  undefined8 local_108 [4];
  uint *local_e8;
  undefined8 local_e0;
  short *local_d8;
  int local_d0;
  undefined4 local_cc;
  wchar_t *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  ulonglong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  short local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_58 = L"";
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  uVar4 = 0xffffffff;
  uVar6 = 0xffffffff;
  uVar5 = 0xffffffff;
  if (param_1 != 0) {
    uVar6 = *(uint *)(param_1 + 0x20);
    uVar4 = *(undefined4 *)(param_1 + 200);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    uVar5 = SUB168(auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8) -
            *(longlong *)(param_1 + 0xd0);
    PdcpFormatTaskName(uVar6,(undefined4 *)local_48);
    local_58 = (wchar_t *)(param_1 + 0x46);
  }
  lVar3 = -1;
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    param_4 = -1;
    do {
      param_4 = param_4 + 1;
    } while (local_48[param_4] != 0);
    param_3 = (ulonglong)uVar6;
    McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer
              (0,0xffffffff,param_3,(int)param_4,local_48,10,L"V1_Unknown",(char)uVar4,0xff,
               (char)uVar5,(char)param_2,(char)param_1,1,(int)lVar2,local_58,0);
  }
  if ((999 < uVar5) && (5 < DAT_140006048)) {
    local_e8 = &local_138;
    lVar2 = -1;
    local_e0 = 4;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != 0);
    local_cc = 0;
    local_d0 = (int)lVar2 * 2 + 2;
    local_b8 = &local_134;
    local_130 = 0xffffffff;
    local_a8 = &local_130;
    local_98 = &local_120;
    local_88 = local_118;
    local_78 = &local_12c;
    local_68 = local_128;
    local_d8 = local_48;
    local_c8 = L"V1_Unknown";
    local_c0 = 0x16;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 8;
    local_80 = 8;
    local_70 = 4;
    local_128[0] = 1;
    local_60 = 4;
    if (local_58 == (wchar_t *)0x0) {
      local_58 = L"";
      local_50 = 2;
    }
    else {
      do {
        lVar3 = lVar3 + 1;
      } while (local_58[lVar3] != L'\0');
      local_50 = (int)lVar3 * 2 + 2;
    }
    local_4c = 0;
    local_138 = uVar6;
    local_134 = uVar4;
    local_12c = param_2;
    local_120 = uVar5;
    local_118[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(local_d8,&DAT_140005391,param_3,param_4,0xc,local_108);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER @ 140002480 =====

void Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    pwVar2 = (wchar_t *)(param_1 + 0x46);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    McTemplateU0qqqqzr3_EtwWriteTransfer
              (param_1,&PDCV2_ACTIVATION_REGISTER,uVar3,param_2,1,(int)lVar1,pwVar2);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_UNREGISTER @ 1400024e8 =====

void Pdcv1EventWrite_ACTIVATION_CLIENT_UNREGISTER(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    pwVar2 = (wchar_t *)(param_1 + 0x46);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    McTemplateU0qqqqzr3_EtwWriteTransfer
              (param_1,&PDCV2_ACTIVATION_UNREGISTER,uVar3,param_2,1,(int)lVar1,pwVar2);
  }
  return;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_ACTIVATE @ 140002550 =====

void Pdcv2EventWrite_ACTIVATION_CLIENT_ACTIVATE
               (longlong param_1,longlong param_2,undefined1 param_3)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  undefined1 uVar10;
  
  uVar10 = 0xff;
  pwVar9 = L"";
  uVar4 = 0xff;
  uVar7 = 0xffffffff;
  uVar5 = 0xff;
  pwVar3 = L"";
  pwVar6 = L"";
  if (param_2 != 0) {
    uVar7 = (ulonglong)*(uint *)(param_2 + 0x20);
    pwVar9 = (wchar_t *)(param_2 + 0x78);
    uVar4 = (undefined1)*(undefined4 *)(param_2 + 0xf8);
    uVar10 = (undefined1)*(undefined4 *)(param_2 + 0xfc);
  }
  if (param_1 != 0) {
    uVar5 = (undefined1)*(undefined4 *)(param_1 + 0x34);
    pwVar6 = (wchar_t *)(param_1 + 0x48);
    pwVar3 = (wchar_t *)(param_1 + 0x148);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar8 = -1;
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (pwVar9[lVar2] != L'\0');
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar3[lVar1] != L'\0');
    do {
      lVar8 = lVar8 + 1;
    } while (pwVar6[lVar8] != L'\0');
    McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer
              (param_1,lVar2,uVar7,(int)lVar8,pwVar6,(int)lVar1,pwVar3,uVar10,uVar4,uVar5,param_3,
               (char)param_1,2,(int)lVar2,pwVar9);
  }
  return;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_CALLBACK @ 140002648 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t * Pdcv2EventWrite_ACTIVATION_CLIENT_CALLBACK
                    (longlong param_1,longlong param_2,uint param_3,ulonglong param_4)

{
  undefined1 auVar1 [16];
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 uVar12;
  uint uVar13;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  undefined1 auStackY_1f8 [32];
  uint local_168;
  undefined4 local_164;
  uint local_160;
  uint local_15c;
  uint local_158 [2];
  longlong local_150;
  undefined4 local_148 [2];
  longlong local_140;
  longlong local_138 [2];
  undefined8 local_128 [4];
  uint *local_108;
  undefined8 local_100;
  wchar_t *local_f8;
  int local_f0;
  undefined4 local_ec;
  wchar_t *local_e8;
  int local_e0;
  undefined4 local_dc;
  uint *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  longlong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  lVar6 = -1;
  uVar9 = 0xffffffff;
  local_160 = (uint)param_4;
  pwVar2 = L"";
  local_158[0] = 0xffffffff;
  local_150 = -1;
  uVar4 = 0;
  local_168 = 0xffffffff;
  local_164 = 0xffffffff;
  uVar12 = 0;
  uVar13 = 0xffffffff;
  pwVar8 = L"";
  pwVar15 = L"";
  pwVar14 = L"";
  if (param_2 != 0) {
    local_168 = *(uint *)(param_2 + 0xf8);
    pwVar2 = (wchar_t *)(ulonglong)local_168;
    pwVar8 = (wchar_t *)(param_2 + 0x78);
    local_158[0] = *(uint *)(param_2 + 0xfc);
    uVar9 = (ulonglong)local_158[0];
    uVar13 = *(uint *)(param_2 + 0x20);
  }
  if (param_1 != 0) {
    local_164 = *(undefined4 *)(param_1 + 0x40);
    pwVar14 = (wchar_t *)(param_1 + 0x48);
    pwVar15 = (wchar_t *)(param_1 + 0x148);
    uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x248);
    uVar4 = (ulonglong)_DAT_fffff78000000004 << 0x20;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    auVar1 = auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20);
    pwVar2 = auVar1._0_8_;
    local_150 = auVar1._8_8_ - *(longlong *)(param_1 + 0x28);
  }
  iVar7 = 2;
  uVar10 = uVar9;
  local_15c = param_3;
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar8[lVar5] != L'\0');
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (pwVar15[lVar3] != L'\0');
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (pwVar14[lVar11] != L'\0');
    uVar4 = (ulonglong)param_3;
    uVar10 = (ulonglong)uVar13;
    pwVar2 = (wchar_t *)
             McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer
                       (uVar4,0,uVar10,(int)lVar11,pwVar14,(int)lVar3,pwVar15,(char)param_3,
                        (char)uVar9,(char)local_168,(char)local_150,(char)param_4,(char)param_1,
                        (char)local_164,2,(int)lVar5,pwVar8,uVar12);
    param_4 = (ulonglong)local_160;
  }
  if (5 < DAT_140006048) {
    local_100 = 4;
    local_108 = &local_160;
    if (pwVar14 == (wchar_t *)0x0) {
      pwVar14 = L"";
      local_f0 = 2;
    }
    else {
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (pwVar14[lVar5] != L'\0');
      local_f0 = (int)lVar5 * 2 + 2;
    }
    local_ec = 0;
    if (pwVar15 == (wchar_t *)0x0) {
      pwVar15 = L"";
      local_e0 = 2;
    }
    else {
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (pwVar15[lVar5] != L'\0');
      local_e0 = (int)lVar5 * 2 + 2;
    }
    local_d8 = &local_15c;
    local_c8 = local_158;
    local_b8 = &local_168;
    local_a8 = &local_164;
    local_140 = local_150;
    local_98 = &local_140;
    local_88 = local_138;
    local_78 = local_148;
    local_68 = &local_150;
    local_dc = 0;
    local_d0 = 4;
    local_c0 = 4;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 8;
    local_80 = 8;
    local_148[0] = (undefined4)param_4;
    local_70 = 4;
    local_150 = CONCAT44(local_150._4_4_,2);
    local_60 = 4;
    if (pwVar8 == (wchar_t *)0x0) {
      pwVar8 = L"";
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pwVar8[lVar6] != L'\0');
      iVar7 = (int)lVar6 * 2 + 2;
    }
    local_4c = 0;
    local_160 = uVar13;
    local_138[0] = param_1;
    local_f8 = pwVar14;
    local_e8 = pwVar15;
    local_58 = pwVar8;
    local_50 = iVar7;
    pwVar2 = (wchar_t *)
             _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1400055ac,uVar10,param_4,0xe,local_128);
  }
  return pwVar2;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_DEACTIVATE @ 14000296c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

wchar_t * Pdcv2EventWrite_ACTIVATION_CLIENT_DEACTIVATE
                    (longlong param_1,longlong param_2,uint param_3)

{
  undefined1 auVar1 [16];
  ulonglong uVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 uVar11;
  uint uVar12;
  wchar_t *pwVar13;
  wchar_t *pwVar14;
  undefined1 auStackY_1b8 [32];
  uint local_138;
  uint local_134;
  undefined4 local_130 [2];
  ulonglong local_128;
  uint local_120 [2];
  ulonglong local_118;
  longlong local_110;
  undefined8 local_108 [4];
  uint *local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  int local_d0;
  undefined4 local_cc;
  wchar_t *local_c8;
  int local_c0;
  undefined4 local_bc;
  undefined4 *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  ulonglong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  ulonglong *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  lVar6 = -1;
  local_130[0] = 0xffffffff;
  pwVar3 = L"";
  local_128 = 0xffffffffffffffff;
  local_138 = 0xffffffff;
  uVar11 = 0;
  uVar12 = 0xffffffff;
  pwVar8 = L"";
  pwVar14 = L"";
  pwVar13 = L"";
  if (param_2 != 0) {
    local_138 = *(uint *)(param_2 + 0xf8);
    pwVar3 = (wchar_t *)(ulonglong)local_138;
    pwVar8 = (wchar_t *)(param_2 + 0x78);
    local_130[0] = *(undefined4 *)(param_2 + 0xfc);
    uVar12 = *(uint *)(param_2 + 0x20);
  }
  if (param_1 != 0) {
    pwVar13 = (wchar_t *)(param_1 + 0x48);
    pwVar14 = (wchar_t *)(param_1 + 0x148);
    uVar11 = (undefined1)*(undefined4 *)(param_1 + 0x248);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    auVar1 = auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20);
    pwVar3 = auVar1._0_8_;
    local_128 = auVar1._8_8_ - *(longlong *)(param_1 + 0x28);
  }
  iVar7 = 2;
  uVar9 = local_128;
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar8[lVar5] != L'\0');
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (pwVar14[lVar4] != L'\0');
    lVar10 = -1;
    do {
      lVar10 = lVar10 + 1;
    } while (pwVar13[lVar10] != L'\0');
    uVar9 = (ulonglong)uVar12;
    local_134 = param_3;
    pwVar3 = (wchar_t *)
             McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer
                       ((ulonglong)local_138,0,uVar9,(int)lVar10,pwVar13,(int)lVar4,pwVar14,
                        (char)local_130[0],(char)local_138,(char)local_128,(char)param_3,
                        (char)param_1,2,(int)lVar5,pwVar8,uVar11);
    param_3 = local_134;
  }
  uVar2 = local_128;
  if ((999 < local_128) && (5 < DAT_140006048)) {
    local_e0 = 4;
    local_e8 = &local_134;
    if (pwVar13 == (wchar_t *)0x0) {
      pwVar13 = L"";
      local_d0 = 2;
    }
    else {
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (pwVar13[lVar5] != L'\0');
      local_d0 = (int)lVar5 * 2 + 2;
    }
    local_cc = 0;
    if (pwVar14 == (wchar_t *)0x0) {
      pwVar14 = L"";
      local_c0 = 2;
    }
    else {
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (pwVar14[lVar5] != L'\0');
      local_c0 = (int)lVar5 * 2 + 2;
    }
    local_b8 = local_130;
    local_a8 = &local_138;
    local_98 = &local_118;
    local_88 = &local_110;
    local_78 = local_120;
    local_68 = &local_128;
    local_bc = 0;
    local_b0 = 4;
    local_a0 = 4;
    local_118 = local_128;
    local_90 = 8;
    local_80 = 8;
    local_70 = 4;
    local_128 = CONCAT44(local_128._4_4_,2);
    local_60 = 4;
    if (pwVar8 == (wchar_t *)0x0) {
      pwVar8 = L"";
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pwVar8[lVar6] != L'\0');
      iVar7 = (int)lVar6 * 2 + 2;
    }
    local_4c = 0;
    local_134 = uVar12;
    local_120[0] = param_3;
    local_110 = param_1;
    local_d8 = pwVar13;
    local_c8 = pwVar14;
    local_58 = pwVar8;
    local_50 = iVar7;
    pwVar3 = (wchar_t *)
             _tlgWriteTransfer_EtwWriteTransfer
                       (uVar2,&DAT_140005505,uVar9,(ulonglong)param_3,0xc,local_108);
  }
  return pwVar3;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_REGISTER @ 140002c34 =====

void Pdcv2EventWrite_ACTIVATION_CLIENT_REGISTER(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    pwVar2 = (wchar_t *)(param_1 + 0x78);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    McTemplateU0qqqqzr3_EtwWriteTransfer
              (param_1,&PDCV2_ACTIVATION_REGISTER,uVar3,param_2,2,(int)lVar1,pwVar2);
  }
  return;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_RENEW_ACTIVATION @ 140002c9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
Pdcv2EventWrite_ACTIVATION_CLIENT_RENEW_ACTIVATION
          (longlong param_1,longlong param_2,uint param_3,undefined1 param_4)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  undefined1 uVar6;
  char cVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  longlong lVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  uint uVar14;
  undefined1 uVar15;
  
  uVar11 = 0xff;
  pwVar5 = L"";
  lVar10 = -1;
  uVar2 = 0;
  uVar6 = 0xff;
  cVar7 = -1;
  uVar15 = 0;
  uVar14 = 0xffffffff;
  uVar12 = 0xff;
  uVar13 = 0xff;
  pwVar9 = L"";
  pwVar8 = L"";
  if (param_2 != 0) {
    uVar14 = *(uint *)(param_2 + 0x20);
    pwVar5 = (wchar_t *)(param_2 + 0x78);
    uVar6 = (undefined1)*(undefined4 *)(param_2 + 0xf8);
    uVar11 = (undefined1)*(undefined4 *)(param_2 + 0xfc);
  }
  if (param_1 != 0) {
    uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x34);
    pwVar8 = (wchar_t *)(param_1 + 0x48);
    pwVar9 = (wchar_t *)(param_1 + 0x148);
    uVar13 = (undefined1)*(undefined4 *)(param_1 + 0x40);
    uVar15 = (undefined1)*(undefined4 *)(param_1 + 0x248);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    auVar1 = auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20);
    uVar2 = auVar1._0_8_;
    cVar7 = auVar1[8] - (char)*(undefined8 *)(param_1 + 0x28);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (pwVar5[lVar4] != L'\0');
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (pwVar9[lVar3] != L'\0');
    do {
      lVar10 = lVar10 + 1;
    } while (pwVar8[lVar10] != L'\0');
    uVar2 = McTemplateU0qqzr1qzr3qqqxqqqpqzr13q_EtwWriteTransfer
                      ((ulonglong)param_3,0,(ulonglong)uVar14,(int)lVar10,pwVar8,(int)lVar3,pwVar9,
                       uVar12,uVar11,uVar6,cVar7,uVar13,(char)param_3,param_4,(char)param_1,
                       (int)lVar4,pwVar5,uVar15);
  }
  return uVar2;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_SET_BROKERED_PROCESSID @ 140002e00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
Pdcv2EventWrite_ACTIVATION_CLIENT_SET_BROKERED_PROCESSID
          (longlong param_1,longlong param_2,uint param_3)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  char cVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  longlong lVar9;
  undefined1 uVar10;
  wchar_t *pwVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined4 uVar14;
  undefined1 uVar15;
  
  uVar10 = 0xff;
  pwVar11 = L"";
  lVar9 = -1;
  uVar2 = 0;
  uVar5 = 0xff;
  cVar6 = -1;
  uVar15 = 0;
  uVar14 = 0xffffffff;
  uVar12 = 0xff;
  uVar13 = 0xff;
  pwVar8 = L"";
  pwVar7 = L"";
  if (param_2 != 0) {
    uVar14 = *(undefined4 *)(param_2 + 0x20);
    pwVar11 = (wchar_t *)(param_2 + 0x78);
    uVar5 = (undefined1)*(undefined4 *)(param_2 + 0xf8);
    uVar10 = (undefined1)*(undefined4 *)(param_2 + 0xfc);
  }
  if (param_1 != 0) {
    uVar12 = (undefined1)*(undefined4 *)(param_1 + 0x34);
    pwVar7 = (wchar_t *)(param_1 + 0x48);
    pwVar8 = (wchar_t *)(param_1 + 0x148);
    uVar13 = (undefined1)*(undefined4 *)(param_1 + 0x40);
    uVar15 = (undefined1)*(undefined4 *)(param_1 + 0x248);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    auVar1 = auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20);
    uVar2 = auVar1._0_8_;
    cVar6 = auVar1[8] - (char)*(undefined8 *)(param_1 + 0x28);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (pwVar11[lVar4] != L'\0');
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (pwVar8[lVar3] != L'\0');
    do {
      lVar9 = lVar9 + 1;
    } while (pwVar7[lVar9] != L'\0');
    uVar2 = McTemplateU0qqzr1qzr3qqqxqqqpqzr13_EtwWriteTransfer
                      ((ulonglong)param_3,0,uVar14,(int)lVar9,pwVar7,(int)lVar3,pwVar8,uVar12,uVar10
                       ,uVar5,cVar6,uVar13,uVar15,(char)param_3,(char)param_1,(int)lVar4,pwVar11);
  }
  return uVar2;
}



===== Pdcv2EventWrite_ACTIVATION_CLIENT_UNREGISTER @ 140002f5c =====

void Pdcv2EventWrite_ACTIVATION_CLIENT_UNREGISTER(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    pwVar2 = (wchar_t *)(param_1 + 0x78);
  }
  if ((Microsoft_Windows_PDCEnableBits._2_1_ & 0x40) != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    McTemplateU0qqqqzr3_EtwWriteTransfer
              (param_1,&PDCV2_ACTIVATION_UNREGISTER,uVar3,param_2,2,(int)lVar1,pwVar2);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgumpdo_hKernelPdcProv @ 140002fc4 =====

void _tlgDefineProvider_annotation__Tlgumpdo_hKernelPdcProv(void)

{
  return;
}



===== PdcCreateWatchdogAroundClientCall @ 140002fd0 =====

undefined8 PdcCreateWatchdogAroundClientCall(void)

{
  return 0;
}



===== _guard_check_icall @ 140002ff0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003008 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000302c =====

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



===== __cpu_features_init @ 1400030a0 =====

/* WARNING: Removing unreachable block (ram,0x00014000310a) */
/* WARNING: Removing unreachable block (ram,0x0001400030b9) */
/* WARNING: Removing unreachable block (ram,0x0001400030aa) */

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



===== __security_check_cookie @ 140003170 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400031b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400031e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400031e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003210 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003280 =====

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



===== memset @ 140003580 =====

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



===== __memset_repmovs @ 1400036c0 =====

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



===== __memset_query @ 140003740 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400037c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003900 =====

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



===== __memset_spec_plain @ 140003980 =====

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



===== DllUnload @ 140009010 =====

undefined8 DllUnload(void)

{
                    /* 0x9010  2  DllUnload */
  return 0;
}



===== PdcActivationClientActivityRequest @ 140009020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PdcActivationClientActivityRequest(int *param_1,uint param_2,char param_3,longlong param_4)

{
  int iVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  ulonglong uVar4;
  undefined1 local_328 [40];
  undefined4 local_300;
  uint local_2f0;
  uint local_2ec;
  
  uVar4 = 800;
  memset(local_328,0,800);
  if ((param_1 == (int *)0x0) || (*param_1 != 0x41636450)) {
    return 0xc00000ef;
  }
  if ((4 < param_2) || (param_2 == 4)) {
    return 0xc00000f0;
  }
  PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
  iVar1 = param_1[(longlong)(int)param_2 + 0xc];
  if (param_3 == '\0') {
    if (iVar1 == 0) {
      uVar3 = 0xc0000001;
      goto LAB_14000916b;
    }
    if (iVar1 != 1) goto LAB_1400090ae;
LAB_1400090c4:
    local_2f0 = local_2f0 & 0xffffff00;
LAB_1400090c9:
    local_300 = 4;
    local_2ec = param_2;
    uVar3 = PdcPortSendMessageSynchronously(*(longlong *)(param_1 + 10),(longlong)local_328);
    if (((int)uVar3 < 0) || (uVar3 = local_2f0, (int)local_2f0 < 0)) goto LAB_14000916b;
  }
  else {
    if (iVar1 == 0) {
      local_2f0 = CONCAT31(local_2f0._1_3_,1);
      if (param_3 == '\0') goto LAB_1400090c4;
      goto LAB_1400090c9;
    }
LAB_1400090ae:
    uVar3 = 0;
  }
  if (param_3 == '\0') {
    param_1[(longlong)(int)param_2 + 0xc] = param_1[(longlong)(int)param_2 + 0xc] + -1;
    param_1[0x32] = param_1[0x32] + -1;
    Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE((longlong)param_1,uVar3,uVar4,param_4);
    if (param_1[0x32] != 0) goto LAB_14000916b;
    param_1[0x34] = 0;
    param_1[0x35] = 0;
  }
  else {
    param_1[(longlong)(int)param_2 + 0xc] = param_1[(longlong)(int)param_2 + 0xc] + 1;
    param_1[0x32] = param_1[0x32] + 1;
    Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE((longlong)param_1,(char)uVar3);
    if (param_1[0x32] != 1) goto LAB_14000916b;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = _DAT_fffff78000000320 << 8;
    *(longlong *)(param_1 + 0x34) = SUB168(auVar2 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8);
  }
  param_1[0x33] = 0;
LAB_14000916b:
  PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
  return uVar3;
}



===== PdcActivationClientRegister @ 1400091a0 =====

ulonglong PdcActivationClientRegister(int param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *local_res10;
  undefined8 in_stack_ffffffffffffffe0;
  
                    /* 0x91a0  4  PdcActivationClientRegister */
  *param_2 = 0;
  if (param_1 == 0) {
    uVar3 = 0xc00000ef;
  }
  else {
    puVar1 = (undefined4 *)ExAllocatePool2(0x100,0xd8,0x41636450);
    if (puVar1 == (undefined4 *)0x0) {
      uVar3 = 0xc0000017;
    }
    else {
      *(undefined8 *)(puVar1 + 0x34) = 0;
      puVar1[0x32] = 0;
      puVar1[0x33] = 0;
      *puVar1 = 0x41636450;
      puVar1[8] = param_1;
      local_res10 = PdcpActivationClientCallback;
      *(undefined8 *)(puVar1 + 4) = 0;
      *(undefined8 *)(puVar1 + 6) = 0;
      *(undefined8 *)(puVar1 + 2) = 0;
      uVar2 = PdcPortOpenCommon(param_1,2,puVar1,(longlong *)&local_res10,(void *)0x0,0,0,
                                in_stack_ffffffffffffffe0,(undefined8 *)(puVar1 + 10));
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 == 0) {
        *(undefined1 *)(puVar1 + 0x11) = 1;
        PdcInitializeETW();
        Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER((longlong)puVar1,0);
        *param_2 = puVar1;
      }
      else {
        ExFreePoolWithTag(puVar1,0);
      }
    }
  }
  return uVar3;
}



===== PdcActivationClientUnregister @ 1400092b0 =====

undefined8 PdcActivationClientUnregister(int *param_1)

{
  undefined8 uVar1;
  
                    /* 0x92b0  5  PdcActivationClientUnregister */
  uVar1 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x41636450)) {
    uVar1 = 0xc00000ef;
    Pdcv1EventWrite_ACTIVATION_CLIENT_UNREGISTER(0,0xc00000ef);
  }
  else {
    PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
    Pdcv1EventWrite_ACTIVATION_CLIENT_UNREGISTER((longlong)param_1,0);
    *(undefined1 *)(param_1 + 0x11) = 0;
    PdcPortClose(*(undefined4 **)(param_1 + 10));
    param_1[10] = 0;
    param_1[0xb] = 0;
    *param_1 = 0;
    PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
    ExFreePoolWithTag(param_1,0);
    PdcUninitializeETW();
  }
  return uVar1;
}



===== PdcpActivationClientCallback @ 140009340 =====

uint PdcpActivationClientCallback(int *param_1,longlong param_2)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = false;
  uVar2 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x41636450)) {
    uVar2 = 0xc00000ef;
LAB_140009369:
    param_1 = (int *)0x0;
  }
  else {
    if (*(int *)(param_2 + 0x28) != 0xe) {
      uVar2 = 0xc0000702;
      goto LAB_140009369;
    }
    PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
    bVar1 = true;
    if ((char)param_1[0x11] != '\0') {
      Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK((longlong)param_1,*(int *)(param_2 + 0x38),0);
      goto LAB_1400093bc;
    }
    uVar2 = 0xc0000189;
  }
  Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK((longlong)param_1,-1,(ulonglong)uVar2);
  if (!bVar1) {
    return uVar2;
  }
LAB_1400093bc:
  PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
  return uVar2;
}



===== Pdcv2ActivationClientActivate @ 1400093f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Pdcv2ActivationClientActivate
              (int *param_1,int *param_2,longlong param_3,uint param_4,longlong param_5,
              undefined4 param_6,undefined8 *param_7,int *param_8)

{
  short sVar1;
  code *pcVar2;
  undefined1 auVar3 [16];
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  short *psVar8;
  int *piVar9;
  longlong *plVar10;
  short *psVar11;
  longlong lVar12;
  undefined1 *puVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStack_378 [8];
  undefined1 auStack_370 [24];
  undefined1 local_358 [16];
  undefined1 local_348 [40];
  undefined4 local_320;
  int local_310;
  int local_30c;
  longlong local_308;
  uint local_300;
  undefined8 local_2f8;
  undefined4 local_2f0;
  int local_2ec;
  short local_2e8 [128];
  short local_1e8 [140];
  uint local_d0 [42];
  
                    /* 0x93f0  19  Pdcv2ActivationClientActivate */
  memset(local_348,0,800);
  local_358[0] = 0;
  if (param_8 == (int *)0x0) {
    param_1 = (int *)0x0;
    local_310 = -0x3fffff0a;
LAB_14000978c:
    puVar13 = auStack_378;
    plVar6 = (longlong *)0x0;
    iVar4 = local_310;
  }
  else {
    *param_8 = 1;
    if (param_7 == (undefined8 *)0x0) {
      param_1 = (int *)0x0;
      local_310 = -0x3fffff0b;
      goto LAB_14000978c;
    }
    *param_7 = 0;
    if ((param_1 == (int *)0x0) || (*param_1 != 0x32414450)) {
      param_1 = (int *)0x0;
      local_310 = -0x3fffff11;
      goto LAB_14000978c;
    }
    if ((4 < param_4) || (param_4 == 4)) {
      local_310 = -0x3fffff0e;
      goto LAB_14000978c;
    }
    uVar5 = Pdcv2pValidateActivationParameters(param_2);
    if (((char)uVar5 == '\0') ||
       (uVar5 = Pdcv2pValidateExtraActivationParameters(param_2,param_4), (char)uVar5 == '\0')) {
      local_310 = -0x3fffff10;
      goto LAB_14000978c;
    }
    if (param_5 == 0) {
      local_310 = -0x3fffff0d;
      goto LAB_14000978c;
    }
    PdcAcquireRwLockExclusive2((undefined8 *)(param_1 + 2),local_358);
    if (*(longlong *)(param_1 + 10) == 0) {
      local_310 = -0x3ffff900;
      goto LAB_14000978c;
    }
    plVar6 = (longlong *)ExAllocatePool2(0x100,600,0x41434450);
    if (plVar6 == (longlong *)0x0) {
      local_310 = -0x3fffffe9;
      goto LAB_14000978c;
    }
    *(undefined4 *)(plVar6 + 2) = 0x41434450;
    lVar14 = 0x80;
    *(undefined4 *)((longlong)plVar6 + 0x14) = 1;
    plVar6[3] = (longlong)param_1;
    auVar3._8_8_ = 0;
    auVar3._0_8_ = _DAT_fffff78000000320 << 8;
    plVar10 = plVar6 + 9;
    plVar6[5] = SUB168(auVar3 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8);
    lVar15 = param_5 - (longlong)plVar10;
    *(uint *)(plVar6 + 6) = param_4;
    lVar12 = 0x80;
    plVar6[4] = param_3;
    *(int *)((longlong)plVar6 + 0x34) = param_2[1];
    do {
      if ((lVar12 == -0x7fffff7e) || (sVar1 = *(short *)(lVar15 + (longlong)plVar10), sVar1 == 0))
      break;
      *(short *)plVar10 = sVar1;
      plVar10 = (longlong *)((longlong)plVar10 + 2);
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    plVar7 = (longlong *)((longlong)plVar10 + -2);
    if (lVar12 != 0) {
      plVar7 = plVar10;
    }
    *(short *)plVar7 = 0;
    psVar11 = *(short **)(param_2 + 4);
    if (psVar11 != (short *)0x0) {
      plVar10 = plVar6 + 0x29;
      lVar12 = 0x80;
      do {
        if ((lVar12 == -0x7fffff7e) || (*psVar11 == 0)) break;
        *(short *)plVar10 = *psVar11;
        psVar11 = psVar11 + 1;
        plVar10 = (longlong *)((longlong)plVar10 + 2);
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      plVar7 = (longlong *)((longlong)plVar10 + -2);
      if (lVar12 != 0) {
        plVar7 = plVar10;
      }
      *(short *)plVar7 = 0;
    }
    local_2f8 = *(undefined8 *)(param_2 + 2);
    psVar11 = local_2e8;
    lVar12 = 0x80;
    local_2f0 = param_6;
    local_2ec = param_2[1];
    local_320 = 10;
    do {
      if ((lVar12 == -0x7fffff7e) ||
         (sVar1 = *(short *)((param_5 - (longlong)local_2e8) + (longlong)psVar11), sVar1 == 0))
      break;
      *psVar11 = sVar1;
      psVar11 = psVar11 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    lVar15 = *(longlong *)(param_2 + 4);
    psVar8 = psVar11 + -1;
    if (lVar12 != 0) {
      psVar8 = psVar11;
    }
    *psVar8 = 0;
    if (lVar15 != 0) {
      psVar11 = local_1e8;
      do {
        if ((lVar14 == -0x7fffff7e) ||
           (sVar1 = *(short *)((longlong)psVar11 + (lVar15 - (longlong)local_1e8)), sVar1 == 0))
        break;
        *psVar11 = sVar1;
        psVar11 = psVar11 + 1;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
      psVar8 = psVar11 + -1;
      if (lVar14 != 0) {
        psVar8 = psVar11;
      }
      *psVar8 = 0;
    }
    local_300 = param_4;
    if (*(ulonglong **)(param_2 + 6) != (ulonglong *)0x0) {
      PdcpResizeDiagnosticContext(*(ulonglong **)(param_2 + 6),local_d0);
    }
    iVar4 = PdcPortSendMessageSynchronously(*(longlong *)(param_1 + 10),(longlong)local_348);
    puVar13 = auStack_378;
    if (iVar4 < 0) {
      ExFreePoolWithTag(plVar6,0);
      local_310 = iVar4;
      goto LAB_14000978c;
    }
    *param_8 = local_30c;
    if ((local_310 < 0) || (local_30c == 300)) {
      ExFreePoolWithTag(plVar6,0);
      puVar13 = auStack_378;
      if (-1 < local_310) goto LAB_140009799;
      goto LAB_14000978c;
    }
    plVar6[0x4a] = local_308;
    *(undefined1 *)((longlong)plVar6 + 0x3c) = 0;
    *(int *)(plVar6 + 7) = local_30c;
    piVar9 = param_1 + 0x14;
    param_1[0x3e] = param_1[0x3e] + 1;
    param_1[0x3f] = param_1[0x3f] + 1;
    param_1[(longlong)(int)param_4 + 0x40] = param_1[(longlong)(int)param_4 + 0x40] + 1;
    plVar10 = *(longlong **)(param_1 + 0x16);
    if ((int *)*plVar10 != piVar9) {
      plVar10 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      piVar9 = (int *)(*pcVar2)();
      puVar13 = auStack_370;
    }
    plVar6[1] = (longlong)plVar10;
    *plVar6 = (longlong)piVar9;
    *plVar10 = (longlong)plVar6;
    *(longlong **)(piVar9 + 2) = plVar6;
    *param_7 = plVar6;
    iVar4 = local_310;
  }
  *(undefined8 *)(puVar13 + -8) = 0x140009799;
  Pdcv2EventWrite_ACTIVATION_CLIENT_ACTIVATE((longlong)plVar6,(longlong)param_1,(char)iVar4);
  local_310 = iVar4;
LAB_140009799:
  if (puVar13[0x20] != '\0') {
    *(undefined8 *)(puVar13 + -8) = 0x1400097ae;
    PdcReleaseRwLockExclusive2((longlong *)(param_1 + 2),puVar13 + 0x20);
  }
  return local_310;
}



===== Pdcv2ActivationClientDeactivate @ 1400097e0 =====

ulonglong Pdcv2ActivationClientDeactivate(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  int *piVar7;
  char local_res8 [8];
  undefined1 local_328 [40];
  undefined4 local_300;
  uint local_2f0;
  longlong local_2e8;
  
                    /* 0x97e0  20  Pdcv2ActivationClientDeactivate */
  memset(local_328,0,800);
  local_res8[0] = '\0';
  piVar7 = (int *)0x0;
  if (param_1 == (longlong *)0x0) {
    param_1 = (longlong *)0x0;
    uVar5 = 0xc00000ef;
  }
  else if ((int)param_1[2] == 0x41434450) {
    piVar7 = (int *)param_1[3];
    if (*piVar7 == 0x32414450) {
      plVar3 = (longlong *)(piVar7 + 2);
      PdcAcquireRwLockExclusive2(plVar3,local_res8);
      if (SystemReserved1[0xf] != *(void **)(piVar7 + 0x18)) {
        while (*(longlong **)(piVar7 + 0x1c) == param_1) {
          PdcReleaseRwLockExclusive2(plVar3,local_res8);
          KeWaitForSingleObject(*(undefined8 *)(piVar7 + 0x1a),0,0,0,0);
          PdcAcquireRwLockExclusive2(plVar3,local_res8);
        }
      }
      if (*(longlong *)(piVar7 + 10) == 0) {
        uVar5 = 0xc0000700;
      }
      else if (piVar7[(longlong)(int)param_1[6] + 0x40] == 0) {
        uVar5 = 0xc0000001;
      }
      else {
        local_2e8 = param_1[0x4a];
        local_300 = 0xd;
        uVar5 = PdcPortSendMessageSynchronously(*(longlong *)(piVar7 + 10),(longlong)local_328);
        if ((-1 < (int)uVar5) && (uVar5 = local_2f0, -1 < (int)local_2f0)) {
          lVar2 = param_1[3];
          piVar1 = (int *)(lVar2 + 0x100 + (longlong)(int)param_1[6] * 4);
          *piVar1 = *piVar1 + -1;
          piVar1 = (int *)(lVar2 + 0xfc);
          *piVar1 = *piVar1 + -1;
          *(undefined4 *)(param_1 + 2) = 0;
          Pdcv2EventWrite_ACTIVATION_CLIENT_DEACTIVATE((longlong)param_1,(longlong)piVar7,0);
          lVar2 = *param_1;
          if ((*(longlong **)(lVar2 + 8) != param_1) ||
             (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 != param_1)) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar6 = (*pcVar4)();
            return uVar6;
          }
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          *(undefined4 *)(param_1 + 2) = 0;
          ExFreePoolWithTag(param_1,0);
          goto LAB_140009830;
        }
      }
    }
    else {
      param_1 = (longlong *)0x0;
      piVar7 = (int *)0x0;
      uVar5 = 0xc00000ef;
    }
  }
  else {
    param_1 = (longlong *)0x0;
    uVar5 = 0xc00000ef;
  }
  Pdcv2EventWrite_ACTIVATION_CLIENT_DEACTIVATE((longlong)param_1,(longlong)piVar7,uVar5);
LAB_140009830:
  if (local_res8[0] != '\0') {
    PdcReleaseRwLockExclusive2((longlong *)(piVar7 + 2),local_res8);
  }
  return (ulonglong)uVar5;
}



===== Pdcv2ActivationClientRegister @ 1400099d0 =====

ulonglong Pdcv2ActivationClientRegister(int param_1,int *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  code *local_res18 [2];
  undefined8 in_stack_ffffffffffffffc0;
  
                    /* 0x99d0  21  Pdcv2ActivationClientRegister */
  *param_3 = 0;
  if (param_1 == 0) {
    uVar7 = 0xc00000ef;
  }
  else if ((*param_2 == 1) && (*(longlong *)(param_2 + 2) != 0)) {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x118,0x32414450);
    if (puVar4 == (undefined4 *)0x0) {
      uVar7 = 0xc0000017;
    }
    else {
      plVar1 = (longlong *)(puVar4 + 2);
      lVar5 = ExAllocatePool2(0x40,0x38,0x4c636450);
      if (lVar5 == 0) {
        uVar7 = 0xc0000017;
      }
      else {
        *plVar1 = 0;
        *(undefined8 *)(puVar4 + 4) = 0;
        *(undefined8 *)(puVar4 + 6) = 0;
        KeInitializeMutex(lVar5);
        *plVar1 = lVar5;
        PdcAcquireRwLockExclusive2(plVar1,(undefined1 *)0x0);
        lVar5 = ExAllocatePool2(0x40,0x18,0x45636450);
        if (lVar5 != 0) {
          KeInitializeEvent(lVar5,0,1);
        }
        *(longlong *)(puVar4 + 0x1a) = lVar5;
        if (lVar5 == 0) {
          uVar7 = 0xc000009a;
        }
        else {
          puVar2 = puVar4 + 0x14;
          *puVar4 = 0x32414450;
          *(undefined4 **)(puVar4 + 0x16) = puVar2;
          *(undefined4 **)puVar2 = puVar2;
          puVar4[8] = param_1;
          *(undefined1 *)(puVar4 + 0x12) = 1;
          uVar3 = *(undefined8 *)(param_2 + 2);
          local_res18[0] = Pdcv2pActivationClientCallback;
          *(undefined8 *)(puVar4 + 0xc) = *(undefined8 *)param_2;
          *(undefined8 *)(puVar4 + 0xe) = uVar3;
          *(undefined8 *)(puVar4 + 0x10) = *(undefined8 *)(param_2 + 4);
          uVar6 = PdcPortOpenCommon(param_1,7,puVar4,(longlong *)local_res18,(void *)0x0,0,0,
                                    in_stack_ffffffffffffffc0,(undefined8 *)(puVar4 + 10));
          uVar7 = uVar6 & 0xffffffff;
          if ((int)uVar6 == 0) {
            *param_3 = puVar4;
            PdcInitializeETW();
            Pdcv2EventWrite_ACTIVATION_CLIENT_REGISTER((longlong)puVar4,0);
            PdcReleaseRwLockExclusive2(plVar1,(undefined1 *)0x0);
            return uVar7;
          }
          if (*(longlong *)(puVar4 + 0x1a) != 0) {
            ExFreePoolWithTag();
          }
        }
        plVar1 = (longlong *)(puVar4 + 2);
        PdcReleaseRwLockExclusive2(plVar1,(undefined1 *)0x0);
        ExFreePoolWithTag(*plVar1,0);
        *plVar1 = 0;
      }
      ExFreePoolWithTag(puVar4,0);
    }
  }
  else {
    uVar7 = 0xc00000f0;
  }
  return uVar7;
}



===== Pdcv2ActivationClientRenewActivation @ 140009bf0 =====

int Pdcv2ActivationClientRenewActivation(longlong param_1,int *param_2,uint *param_3)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  short *psVar5;
  longlong lVar6;
  int *piVar7;
  short *psVar8;
  uint uVar9;
  longlong lVar10;
  char local_res18 [8];
  undefined1 local_348 [40];
  undefined4 local_320;
  int local_310;
  uint local_30c;
  undefined8 local_308;
  undefined8 local_300;
  int local_2f8;
  short local_2f4 [130];
  uint local_1f0 [114];
  
                    /* 0x9bf0  22  Pdcv2ActivationClientRenewActivation */
  memset(local_348,0,800);
  local_res18[0] = '\0';
  piVar7 = (int *)0x0;
  if (param_3 == (uint *)0x0) {
    iVar3 = -0x3fffff0f;
    uVar9 = 0xffffffff;
    param_1 = 0;
  }
  else {
    *param_3 = 1;
    if (param_1 == 0) {
      param_1 = 0;
      iVar3 = -0x3fffff11;
    }
    else if (*(int *)(param_1 + 0x10) == 0x41434450) {
      piVar7 = *(int **)(param_1 + 0x18);
      if (*piVar7 == 0x32414450) {
        uVar4 = Pdcv2pValidateActivationParameters(param_2);
        if ((char)uVar4 == '\0') {
          iVar3 = -0x3fffff10;
        }
        else {
          PdcAcquireRwLockExclusive2((undefined8 *)(piVar7 + 2),local_res18);
          if (*(longlong *)(piVar7 + 10) == 0) {
            iVar3 = -0x3ffff900;
          }
          else {
            local_308 = *(undefined8 *)(param_2 + 2);
            lVar10 = 0x80;
            lVar2 = *(longlong *)(param_2 + 4);
            local_300 = *(undefined8 *)(param_1 + 0x250);
            local_2f8 = param_2[1];
            local_320 = 0xb;
            if (lVar2 != 0) {
              lVar6 = 0x80;
              psVar5 = local_2f4;
              do {
                if ((lVar6 == -0x7fffff7e) ||
                   (sVar1 = *(short *)((lVar2 - (longlong)local_2f4) + (longlong)psVar5), sVar1 == 0
                   )) break;
                *psVar5 = sVar1;
                psVar5 = psVar5 + 1;
                lVar6 = lVar6 + -1;
              } while (lVar6 != 0);
              psVar8 = psVar5 + -1;
              if (lVar6 != 0) {
                psVar8 = psVar5;
              }
              *psVar8 = 0;
            }
            if (*(ulonglong **)(param_2 + 6) != (ulonglong *)0x0) {
              PdcpResizeDiagnosticContext(*(ulonglong **)(param_2 + 6),local_1f0);
            }
            iVar3 = PdcPortSendMessageSynchronously(*(longlong *)(piVar7 + 10),(longlong)local_348);
            if (-1 < iVar3) {
              *param_3 = local_30c;
              *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
              *(uint *)(param_1 + 0x38) = local_30c;
              *(undefined1 *)(param_1 + 0x3c) = 0;
              psVar5 = *(short **)(param_2 + 4);
              iVar3 = local_310;
              if ((psVar5 != (short *)0x0) && (*psVar5 != 0)) {
                psVar8 = (short *)(param_1 + 0x148);
                do {
                  if ((lVar10 == -0x7fffff7e) || (*psVar5 == 0)) break;
                  *psVar8 = *psVar5;
                  psVar5 = psVar5 + 1;
                  psVar8 = psVar8 + 1;
                  lVar10 = lVar10 + -1;
                } while (lVar10 != 0);
                psVar5 = psVar8 + -1;
                if (lVar10 != 0) {
                  psVar5 = psVar8;
                }
                *psVar5 = 0;
              }
            }
          }
        }
      }
      else {
        piVar7 = (int *)0x0;
        iVar3 = -0x3fffff11;
      }
    }
    else {
      param_1 = 0;
      iVar3 = -0x3fffff11;
    }
    uVar9 = *param_3;
  }
  Pdcv2EventWrite_ACTIVATION_CLIENT_RENEW_ACTIVATION(param_1,(longlong)piVar7,uVar9,(char)iVar3);
  if (local_res18[0] != '\0') {
    PdcReleaseRwLockExclusive2((longlong *)(piVar7 + 2),local_res18);
  }
  return iVar3;
}



===== Pdcv2ActivationClientSetBrokeredProcessId @ 140009e30 =====

uint Pdcv2ActivationClientSetBrokeredProcessId(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  char local_res8 [8];
  
                    /* 0x9e30  23  Pdcv2ActivationClientSetBrokeredProcessId */
  local_res8[0] = '\0';
  piVar2 = (int *)0x0;
  if (param_1 == 0) {
    uVar1 = 0xc00000ef;
    param_1 = 0;
  }
  else if (*(int *)(param_1 + 0x10) == 0x41434450) {
    piVar2 = *(int **)(param_1 + 0x18);
    if (*piVar2 == 0x32414450) {
      PdcAcquireRwLockExclusive2((undefined8 *)(piVar2 + 2),local_res8);
      if (*(longlong *)(piVar2 + 10) == 0) {
        uVar1 = 0xc0000700;
      }
      else {
        *(undefined4 *)(param_1 + 0x248) = param_2;
        uVar1 = 0;
      }
    }
    else {
      param_1 = 0;
      uVar1 = 0xc00000ef;
      piVar2 = (int *)0x0;
    }
  }
  else {
    uVar1 = 0xc00000ef;
    param_1 = 0;
  }
  Pdcv2EventWrite_ACTIVATION_CLIENT_SET_BROKERED_PROCESSID(param_1,(longlong)piVar2,uVar1);
  if (local_res8[0] != '\0') {
    PdcReleaseRwLockExclusive2((longlong *)(piVar2 + 2),local_res8);
  }
  return uVar1;
}



===== Pdcv2ActivationClientUnregister @ 140009ef0 =====

undefined4 Pdcv2ActivationClientUnregister(int *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  int *piVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x9ef0  24  Pdcv2ActivationClientUnregister */
  if (param_1 == (int *)0x0) {
    uVar8 = 0xc00000ef;
    param_1 = (int *)0x0;
  }
  else if (*param_1 == 0x32414450) {
    plVar1 = (longlong *)(param_1 + 2);
    PdcAcquireRwLockExclusive2(plVar1,local_res8);
    if (*(void **)(param_1 + 0x18) != SystemReserved1[0xf]) {
      puVar4 = *(undefined4 **)(param_1 + 10);
      param_1[10] = 0;
      param_1[0xb] = 0;
      *(undefined1 *)(param_1 + 0x12) = 0;
      PdcReleaseRwLockExclusive2(plVar1,local_res8);
      PdcPortClose(puVar4);
      PdcAcquireRwLockExclusive2(plVar1,local_res8);
      puVar9 = auStack_28;
      plVar2 = (longlong *)(param_1 + 0x14);
      do {
        plVar5 = (longlong *)*plVar2;
        if (plVar5 == plVar2) {
LAB_140009fe6:
          *param_1 = 0;
          *(undefined8 *)(puVar9 + -8) = 0x140009ff5;
          Pdcv2EventWrite_ACTIVATION_CLIENT_UNREGISTER((longlong)param_1,0);
          *(undefined8 *)(puVar9 + -8) = 0x14000a002;
          PdcReleaseRwLockExclusive2(plVar1,puVar9 + 0x30);
          lVar6 = *plVar1;
          *(undefined8 *)(puVar9 + -8) = 0x14000a00e;
          ExFreePoolWithTag(lVar6,0);
          *plVar1 = 0;
          lVar6 = *(longlong *)(param_1 + 0x1a);
          if (lVar6 != 0) {
            *(undefined8 *)(puVar9 + -8) = 0x14000a028;
            ExFreePoolWithTag(lVar6,0);
          }
          *(undefined8 *)(puVar9 + -8) = 0x14000a039;
          ExFreePoolWithTag(param_1,0);
          *(undefined8 *)(puVar9 + -8) = 0x14000a043;
          PdcUninitializeETW();
          return 0;
        }
        if (((longlong *)plVar5[1] != plVar2) ||
           (lVar6 = *plVar5, (longlong *)*(longlong *)(lVar6 + 8) != plVar5)) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          puVar9 = auStack_20;
          goto LAB_140009fe6;
        }
        *plVar2 = lVar6;
        *(longlong **)(lVar6 + 8) = plVar2;
        lVar6 = plVar5[3];
        piVar3 = (int *)(lVar6 + 0x100 + (longlong)*(int *)(plVar5 + 6) * 4);
        *piVar3 = *piVar3 + -1;
        piVar3 = (int *)(lVar6 + 0xfc);
        *piVar3 = *piVar3 + -1;
        *(undefined4 *)(plVar5 + 2) = 0;
        ExFreePoolWithTag();
      } while( true );
    }
    uVar8 = 0xc00000bb;
    PdcReleaseRwLockExclusive2(plVar1,local_res8);
  }
  else {
    uVar8 = 0xc00000ef;
    param_1 = (int *)0x0;
  }
  Pdcv2EventWrite_ACTIVATION_CLIENT_UNREGISTER((longlong)param_1,uVar8);
  return uVar8;
}



===== Pdcv2pActivationClientCallback @ 14000a070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Pdcv2pActivationClientCallback(int *param_1,longlong param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  char local_res8 [8];
  
  uVar4 = 0;
  local_res8[0] = '\0';
  if (param_1 == (int *)0x0) {
    uVar5 = 0xc00000ef;
  }
  else if (*param_1 == 0x32414450) {
    if (*(int *)(param_2 + 0x28) == 0xc) {
      piVar3 = param_1;
      uVar2 = PdcCreateWatchdogAroundClientCall();
      uVar5 = uVar2 & 0xffffffff;
      plVar1 = (longlong *)(piVar3 + 2);
      while( true ) {
        PdcAcquireRwLockExclusive2(plVar1,local_res8);
        if (*(longlong *)(param_1 + 0x18) == 0) break;
        PdcReleaseRwLockExclusive2(plVar1,local_res8);
        KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x1a),0,0,0,0);
      }
      if (*(longlong *)(param_1 + 10) == 0) {
        uVar5 = 0xc0000700;
      }
      else {
        uVar4 = *(uint *)(param_2 + 0x40);
        for (piVar3 = *(int **)(param_1 + 0x14); piVar3 != param_1 + 0x14; piVar3 = *(int **)piVar3)
        {
          if (*(longlong *)(piVar3 + 0x94) == *(longlong *)(param_2 + 0x38)) {
            if (100 < (int)uVar4) {
              piVar3[0x11] = piVar3[0x11] + 1;
              *(undefined1 *)(piVar3 + 0xf) = 1;
            }
            Pdcv2EventWrite_ACTIVATION_CLIENT_CALLBACK
                      ((longlong)piVar3,(longlong)param_1,uVar4,uVar2 & 0xffffffff);
            *(void **)(param_1 + 0x18) = SystemReserved1[0xf];
            *(int **)(param_1 + 0x1c) = piVar3;
            PdcResetEvent();
            *(void **)(*(longlong *)(param_1 + 10) + 0x6e0) = SystemReserved1[0xf];
            PdcReleaseRwLockExclusive2(plVar1,local_res8);
            (**(code **)(param_1 + 0xe))
                      (piVar3,uVar4,*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(piVar3 + 8));
            PdcAcquireRwLockExclusive2(plVar1,local_res8);
            if (*(longlong *)(param_1 + 10) != 0) {
              *(undefined8 *)(*(longlong *)(param_1 + 10) + 0x6e0) = 0;
            }
            param_1[0x18] = 0;
            param_1[0x19] = 0;
            param_1[0x1c] = 0;
            param_1[0x1d] = 0;
            KeSetEvent(*(undefined8 *)(param_1 + 0x1a),0,0);
            goto LAB_14000a14c;
          }
        }
        uVar5 = 0xc0000189;
      }
    }
    else {
      uVar5 = 0xc0000702;
    }
  }
  else {
    uVar5 = 0xc00000ef;
    param_1 = (int *)0x0;
  }
  Pdcv2EventWrite_ACTIVATION_CLIENT_CALLBACK(0,(longlong)param_1,uVar4,uVar5);
LAB_14000a14c:
  if (local_res8[0] != '\0') {
    PdcReleaseRwLockExclusive2((longlong *)(param_1 + 2),local_res8);
  }
  return uVar5;
}



===== Pdcv2pValidateActivationParameters @ 14000a230 =====

undefined8 Pdcv2pValidateActivationParameters(int *param_1)

{
  ulonglong *in_RAX;
  ulonglong uVar1;
  undefined1 uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  
  uVar2 = 0;
  if ((((param_1 != (int *)0x0) &&
       (in_RAX = (ulonglong *)(ulonglong)(*param_1 - 1U), *param_1 - 1U < 2)) &&
      ((*(ulonglong *)(param_1 + 2) & 0xfffffffffffffffc) == 0)) &&
     (in_RAX = (ulonglong *)(ulonglong)(param_1[1] - 10U), param_1[1] - 10U < 0x123)) {
    puVar3 = *(ulonglong **)(param_1 + 6);
    if (puVar3 != (ulonglong *)0x0) {
      uVar1 = *puVar3;
      if (10 < uVar1) goto LAB_14000a2be;
      uVar4 = 0;
      if (uVar1 != 0) {
        in_RAX = puVar3 + 1;
        do {
          if ((*in_RAX == 0) || (in_RAX[1] == 0)) goto LAB_14000a2be;
          uVar4 = uVar4 + 1;
          in_RAX = in_RAX + 2;
        } while (uVar4 < uVar1);
      }
      if (uVar1 < 10) {
        in_RAX = (ulonglong *)(uVar1 * 0x10);
        puVar3 = puVar3 + 1 + uVar1 * 2;
        do {
          if ((*puVar3 != 0) || (puVar3[1] != 0)) goto LAB_14000a2be;
          uVar1 = uVar1 + 1;
          puVar3 = puVar3 + 2;
        } while (uVar1 < 10);
      }
    }
    uVar2 = 1;
  }
LAB_14000a2be:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar2);
}



===== PdcNotificationClientAcknowledge @ 14000a2d0 =====

undefined4 PdcNotificationClientAcknowledge(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 local_328 [40];
  undefined4 local_300;
  int local_2f0;
  int local_2e8;
  
                    /* 0xa2d0  6  PdcNotificationClientAcknowledge */
  uVar2 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x4e636450)) {
    uVar2 = 0xc00000ef;
  }
  else {
    piVar1 = param_1 + 2;
    PdcAcquireRwLockExclusive((longlong)piVar1);
    local_2f0 = 0;
    if (param_2 != 0x103) {
      local_2f0 = param_2;
    }
    if ((param_1[0x18] == 1) && ((char)param_1[0x1a] == '\0')) {
      if (*(void **)(param_1 + 0x1c) != SystemReserved1[0xf]) {
        memset(local_328,0,800);
        local_2e8 = param_1[0x17];
        param_1[0x18] = 0;
        local_300 = 2;
        PdcReleaseRwLockExclusive((longlong)piVar1);
        uVar2 = PdcPortSendMessage(*(longlong *)(param_1 + 10),(longlong)local_328);
        return uVar2;
      }
      param_1[0x1e] = local_2f0;
      *(undefined1 *)(param_1 + 0x1a) = 1;
    }
    else {
      uVar2 = 0xc000000d;
    }
    PdcReleaseRwLockExclusive((longlong)piVar1);
  }
  return uVar2;
}



===== PdcNotificationClientRegister @ 14000a3d0 =====

int PdcNotificationClientRegister(int param_1,int *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined8 local_348;
  undefined8 local_340;
  undefined8 local_338;
  undefined4 local_31c;
  int local_310;
  undefined4 local_30c;
  
                    /* 0xa3d0  7  PdcNotificationClientRegister */
  *param_4 = 0;
  if (param_1 == 0) {
    return -0x3fffff11;
  }
  if (*param_2 == 1) {
    lVar2 = *(longlong *)(param_2 + 2);
  }
  else {
    if (*param_2 != 2) {
      return -0x3fffff10;
    }
    lVar2 = *(longlong *)(param_2 + 4);
  }
  if (lVar2 == 0) {
    return -0x3fffff10;
  }
  puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x80,0x4e636450);
  if (puVar6 == (undefined4 *)0x0) {
    return -0x3fffffe9;
  }
  *puVar6 = 0x4e636450;
  puVar1 = (undefined8 *)(puVar6 + 2);
  puVar6[8] = param_1;
  *(undefined1 *)(puVar6 + 0x16) = 1;
  uVar3 = *(undefined8 *)(param_2 + 2);
  *(undefined8 *)(puVar6 + 0xe) = *(undefined8 *)param_2;
  *(undefined8 *)(puVar6 + 0x10) = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 4);
  uVar4 = *(undefined8 *)(param_2 + 6);
  *(undefined8 *)(puVar6 + 0xc) = param_3;
  *(undefined8 *)(puVar6 + 0x12) = uVar3;
  *(undefined8 *)(puVar6 + 0x14) = uVar4;
  *(undefined8 *)(puVar6 + 4) = 0;
  *(undefined8 *)(puVar6 + 6) = 0;
  *puVar1 = 0;
  PdcAcquireRwLockExclusive((longlong)puVar1);
  memset(&local_348,0,800);
  *(undefined8 *)(puVar6 + 10) = 0;
  puVar8 = (undefined4 *)0x0;
  puVar7 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar7 == (undefined4 *)0x0) {
LAB_14000a4f0:
    iVar5 = -0x3fffffe9;
LAB_14000a4f5:
    if (puVar7 != (undefined4 *)0x0) {
      PdcpPortReleaseResources(puVar7);
    }
    if (puVar8 == (undefined4 *)0x0) goto LAB_14000a518;
  }
  else {
    *puVar7 = 0x50636450;
    *(undefined4 **)(puVar7 + 0x1b4) = puVar6;
    puVar7[4] = param_1;
    puVar7[5] = 0;
    ExInitializeRundownProtection(puVar7 + 2);
    *(code **)(puVar7 + 0x1b6) = PdcpNotificationClientCallback;
    local_31c = 6;
    local_30c = 0;
    local_348 = 0x32002f8;
    local_340 = 0;
    local_338 = 0;
    local_310 = param_1;
    puVar8 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
    if (puVar8 == (undefined4 *)0x0) goto LAB_14000a4f0;
    *puVar8 = 1;
    *(undefined4 **)(puVar8 + 4) = puVar7;
    *(undefined8 **)(puVar8 + 2) = &local_348;
    iVar5 = ZwPowerInformation(0x43,puVar8,0xe0,0,0);
    if (iVar5 < 0) goto LAB_14000a4f5;
    *(undefined4 **)(puVar6 + 10) = puVar7;
    iVar5 = 0;
  }
  ExFreePoolWithTag(puVar8,0);
LAB_14000a518:
  if (iVar5 == 0) {
    *param_4 = puVar6;
    puVar6 = (undefined4 *)0x0;
  }
  PdcReleaseRwLockExclusive((longlong)puVar1);
  if (puVar6 == (undefined4 *)0x0) {
    return iVar5;
  }
  ExFreePoolWithTag(puVar6,0);
  return iVar5;
}



===== PdcNotificationClientUnregister @ 14000a610 =====

undefined8 PdcNotificationClientUnregister(int *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 local_res8;
  
                    /* 0xa610  8  PdcNotificationClientUnregister */
  if ((param_1 == (int *)0x0) || (*param_1 != 0x4e636450)) {
    uVar2 = 0xc00000ef;
  }
  else {
    piVar1 = param_1 + 2;
    PdcAcquireRwLockExclusive((longlong)piVar1);
    if (*(void **)(param_1 + 0x1c) == SystemReserved1[0xf]) {
      uVar2 = 0xc0000001;
    }
    else {
      if ((char)param_1[0x16] != '\0') {
        *(undefined1 *)(param_1 + 0x16) = 0;
        PdcReleaseRwLockExclusive((longlong)piVar1);
        while (param_1[0x18] != 0) {
          local_res8 = 0xfffffffffffb6c20;
          KeDelayExecutionThread(0,0,&local_res8);
        }
        PdcPortClose(*(undefined4 **)(param_1 + 10));
        param_1[10] = 0;
        param_1[0xb] = 0;
        *param_1 = 0;
        ExFreePoolWithTag(param_1,0);
        return 0;
      }
      uVar2 = 0xc0000189;
    }
    PdcReleaseRwLockExclusive((longlong)piVar1);
  }
  return uVar2;
}



===== PdcpNotificationClientCallback @ 14000a6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcpNotificationClientCallback(int *param_1,longlong param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_328 [40];
  undefined4 local_300;
  int local_2f0;
  int local_2e8;
  
  memset(local_328,0,800);
  uVar5 = 0;
  if (param_1 != (int *)0x0) {
    if (1 < *(int *)(param_2 + 0x28) - 2U) {
      return 0xc0000702;
    }
    if (*param_1 == 0x4e636450) {
      piVar1 = param_1 + 2;
      PdcAcquireRwLockExclusive((longlong)piVar1);
      if ((char)param_1[0x16] == '\0') {
        uVar5 = 0xc0000189;
      }
      else {
        if (*(int *)(param_2 + 0x28) == 3) {
          if (param_1[0x19] == 0) {
            if (*(longlong *)(param_1 + 0x14) != 0) {
              uVar3 = *(undefined8 *)(param_1 + 0xc);
              param_1[0x19] = 1;
              uVar2 = *(undefined4 *)(param_2 + 0x38);
              PdcReleaseRwLockExclusive((longlong)piVar1);
              (**(code **)(param_1 + 0x14))(uVar3,uVar2);
              PdcAcquireRwLockExclusive((longlong)piVar1);
              param_1[0x19] = param_1[0x19] + -1;
            }
            goto LAB_14000a866;
          }
        }
        else if (param_1[0x18] == 0) {
          iVar4 = *(int *)(param_2 + 0x40);
          param_1[0x18] = 1;
          param_1[0x17] = iVar4;
          *(undefined1 *)(param_1 + 0x1a) = 0;
          *(void **)(param_1 + 0x1c) = SystemReserved1[0xf];
          *(void **)(*(longlong *)(param_1 + 10) + 0x6e0) = SystemReserved1[0xf];
          PdcReleaseRwLockExclusive((longlong)piVar1);
          if (param_1[0xe] == 1) {
            iVar4 = (**(code **)(param_1 + 0x10))();
          }
          else {
            iVar4 = (**(code **)(param_1 + 0x12))
                              (*(undefined8 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38),
                               *(undefined1 *)(param_2 + 0x3c));
          }
          PdcAcquireRwLockExclusive((longlong)piVar1);
          *(undefined8 *)(*(longlong *)(param_1 + 10) + 0x6e0) = 0;
          param_1[0x1c] = 0;
          param_1[0x1d] = 0;
          if ((char)param_1[0x1a] != '\0') {
            iVar4 = param_1[0x1e];
          }
          if (iVar4 != 0x103) {
            local_2e8 = param_1[0x17];
            local_300 = 2;
            local_2f0 = iVar4;
            uVar5 = PdcPortSendMessage(*(longlong *)(param_1 + 10),(longlong)local_328);
            param_1[0x18] = param_1[0x18] + -1;
          }
          goto LAB_14000a866;
        }
        uVar5 = 0xc0000702;
      }
LAB_14000a866:
      PdcReleaseRwLockExclusive((longlong)piVar1);
      return uVar5;
    }
  }
  return 0xc00000ef;
}



===== PdcResiliencyClientAcknowledge @ 14000a8a0 =====

undefined8 PdcResiliencyClientAcknowledge(void)

{
                    /* 0xa8a0  9  PdcResiliencyClientAcknowledge */
  return 0xc0000002;
}



===== PdcResiliencyClientRegister @ 14000a8b0 =====

int PdcResiliencyClientRegister(int param_1,int *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_338;
  undefined4 local_334;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 local_30c;
  int local_300;
  undefined4 local_2fc;
  
                    /* 0xa8b0  10  PdcResiliencyClientRegister */
  *param_4 = 0;
  if (param_1 == 0) {
    return -0x3fffff11;
  }
  if ((*param_2 != 1) || (*(longlong *)(param_2 + 2) == 0)) {
    return -0x3fffff10;
  }
  puVar5 = (undefined4 *)ExAllocatePool2(0x100,0x68,0x52636450);
  if (puVar5 == (undefined4 *)0x0) {
    return -0x3fffffe9;
  }
  *puVar5 = 0x52636450;
  puVar1 = (undefined8 *)(puVar5 + 2);
  puVar5[8] = param_1;
  *(undefined1 *)(puVar5 + 0x12) = 1;
  uVar2 = *(undefined8 *)param_2;
  uVar3 = *(undefined8 *)(param_2 + 2);
  *(undefined8 *)(puVar5 + 0xc) = param_3;
  *(undefined8 *)(puVar5 + 0xe) = uVar2;
  *(undefined8 *)(puVar5 + 0x10) = uVar3;
  *(undefined8 *)(puVar5 + 4) = 0;
  *(undefined8 *)(puVar5 + 6) = 0;
  *puVar1 = 0;
  PdcAcquireRwLockExclusive((longlong)puVar1);
  memset(&local_338,0,800);
  puVar7 = (undefined4 *)0x0;
  *(undefined8 *)(puVar5 + 10) = 0;
  puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar6 == (undefined4 *)0x0) {
LAB_14000a9a5:
    iVar4 = -0x3fffffe9;
LAB_14000a9aa:
    if (puVar6 != (undefined4 *)0x0) {
      PdcpPortReleaseResources(puVar6);
    }
    if (puVar7 == (undefined4 *)0x0) goto LAB_14000a9cd;
  }
  else {
    *puVar6 = 0x50636450;
    *(undefined4 **)(puVar6 + 0x1b4) = puVar5;
    puVar6[5] = 1;
    puVar6[4] = param_1;
    ExInitializeRundownProtection(puVar6 + 2);
    *(code **)(puVar6 + 0x1b6) = PdcpResiliencyClientCallback;
    local_334 = 0;
    local_330 = 0;
    local_328 = 0;
    local_30c = 6;
    local_2fc = 1;
    local_338 = 0x32002f8;
    local_300 = param_1;
    puVar7 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
    if (puVar7 == (undefined4 *)0x0) goto LAB_14000a9a5;
    *puVar7 = 1;
    *(undefined4 **)(puVar7 + 4) = puVar6;
    *(undefined4 **)(puVar7 + 2) = &local_338;
    iVar4 = ZwPowerInformation(0x43,puVar7,0xe0,0,0);
    if (iVar4 < 0) goto LAB_14000a9aa;
    *(undefined4 **)(puVar5 + 10) = puVar6;
    iVar4 = 0;
  }
  ExFreePoolWithTag(puVar7,0);
LAB_14000a9cd:
  if (iVar4 == 0) {
    *param_4 = puVar5;
    puVar5 = (undefined4 *)0x0;
  }
  PdcReleaseRwLockExclusive((longlong)puVar1);
  if (puVar5 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
  return iVar4;
}



===== PdcResiliencyClientUnregister @ 14000aae0 =====

undefined8 PdcResiliencyClientUnregister(int *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 local_res8;
  
                    /* 0xaae0  11  PdcResiliencyClientUnregister */
  if ((param_1 == (int *)0x0) || (*param_1 != 0x52636450)) {
    uVar2 = 0xc00000ef;
  }
  else {
    piVar1 = param_1 + 2;
    PdcAcquireRwLockExclusive((longlong)piVar1);
    if (*(void **)(param_1 + 0x16) == SystemReserved1[0xf]) {
      uVar2 = 0xc0000001;
    }
    else {
      if ((char)param_1[0x12] != '\0') {
        *(undefined1 *)(param_1 + 0x12) = 0;
        PdcReleaseRwLockExclusive((longlong)piVar1);
        while (param_1[0x14] != 0) {
          local_res8 = 0xfffffffffffb6c20;
          KeDelayExecutionThread(0,0,&local_res8);
        }
        PdcPortClose(*(undefined4 **)(param_1 + 10));
        param_1[10] = 0;
        param_1[0xb] = 0;
        *param_1 = 0;
        ExFreePoolWithTag(param_1,0);
        return 0;
      }
      uVar2 = 0xc0000189;
    }
    PdcReleaseRwLockExclusive((longlong)piVar1);
  }
  return uVar2;
}



===== PdcpGetActualResiliencyClient @ 14000aba4 =====

undefined8 PdcpGetActualResiliencyClient(undefined8 *param_1,undefined8 *param_2,longlong param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  lVar1 = *(longlong *)(param_3 + 8);
  uVar7 = 0;
  *param_1 = 0;
  LOCK();
  UNLOCK();
  if (PerNetworkResiliencyClientsRegistered == 0) {
    DAT_140006118 = &PerNetworkResiliencyClients;
    PerNetworkResiliencyClients = &PerNetworkResiliencyClients;
  }
  puVar5 = PerNetworkResiliencyClients;
  while( true ) {
    if ((undefined8 **)puVar5 == &PerNetworkResiliencyClients) {
      PerNetworkResiliencyClientsRegistered = PerNetworkResiliencyClientsRegistered + 1;
      puVar5 = (undefined8 *)ExAllocatePool2(0x100,0x80,0x52636450);
      if (puVar5 == (undefined8 *)0x0) {
        uVar7 = 0xc0000017;
      }
      else {
        puVar5[4] = 0;
        puVar5[5] = 0;
        puVar5[6] = 0;
        puVar5[2] = lVar1;
        puVar6 = DAT_140006118;
        if ((undefined8 **)*DAT_140006118 != &PerNetworkResiliencyClients) {
          puVar6 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          puVar5 = (undefined8 *)(*pcVar2)();
        }
        puVar5[1] = puVar6;
        *puVar5 = &PerNetworkResiliencyClients;
        *puVar6 = puVar5;
        uVar3 = *param_2;
        uVar4 = param_2[1];
        DAT_140006118 = puVar5;
        *param_1 = puVar5 + 3;
        puVar5[3] = uVar3;
        puVar5[4] = uVar4;
        uVar3 = param_2[3];
        puVar5[5] = param_2[2];
        puVar5[6] = uVar3;
        uVar3 = param_2[5];
        puVar5[7] = param_2[4];
        puVar5[8] = uVar3;
        uVar3 = param_2[7];
        puVar5[9] = param_2[6];
        puVar5[10] = uVar3;
        uVar3 = param_2[9];
        puVar5[0xb] = param_2[8];
        puVar5[0xc] = uVar3;
        uVar3 = param_2[0xb];
        puVar5[0xd] = param_2[10];
        puVar5[0xe] = uVar3;
        puVar5[0xf] = param_2[0xc];
        *(undefined4 *)(puVar5 + 0xf) = 0xffffffff;
        *(undefined4 *)(puVar5 + 0xd) = 0;
      }
      return uVar7;
    }
    if (puVar5[2] == lVar1) break;
    puVar5 = (undefined8 *)*puVar5;
  }
  PerNetworkResiliencyClientsRegistered = PerNetworkResiliencyClientsRegistered + 1;
  *param_1 = puVar5 + 3;
  return 0;
}



===== PdcpResiliencyClientCallback @ 14000ace0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcpResiliencyClientCallback(int *param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_398 [32];
  int *local_378 [2];
  undefined1 local_368 [40];
  undefined4 local_340;
  int local_330;
  int local_32c;
  undefined4 local_328;
  undefined8 local_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_398;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  memset(local_368,0,800);
  local_378[0] = (int *)0x0;
  if (param_1 == (int *)0x0) {
    return 0xc00000ef;
  }
  if (*(int *)(param_2 + 0x28) != 5) {
    return 0xc0000702;
  }
  if (*param_1 != 0x52636450) {
    return 0xc00000ef;
  }
  PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
  piVar5 = param_1;
  if ((char)param_1[0x12] == '\0') {
    uVar4 = 0xc0000189;
  }
  else if (param_1[0x14] == 0) {
    local_48 = *(undefined8 *)(param_2 + 0x48);
    uStack_40 = *(undefined8 *)(param_2 + 0x50);
    iVar1 = *(int *)(param_2 + 0x38);
    local_38 = *(undefined8 *)(param_2 + 0x58);
    iVar2 = *(int *)(param_2 + 0x3c);
    piVar6 = (int *)0x0;
    if ((*(uint *)(param_2 + 0x48) & 1) != 0) {
      PdcpGetActualResiliencyClient(local_378,(undefined8 *)param_1,(longlong)&local_48);
      piVar5 = local_378[0];
      piVar6 = param_1;
    }
    iVar3 = piVar5[0x18];
    piVar5[0x14] = piVar5[0x14] + 1;
    piVar5[0x18] = iVar2;
    piVar5[0x13] = iVar1;
    *(undefined1 *)(piVar5 + 0x15) = 0;
    *(void **)(piVar5 + 0x16) = SystemReserved1[0xf];
    if (iVar2 == iVar3) {
      local_328 = 0;
    }
    else {
      *(void **)(*(longlong *)(piVar5 + 10) + 0x6e0) = SystemReserved1[0xf];
      local_328 = (**(code **)(piVar5 + 0x10))(*(undefined8 *)(piVar5 + 0xc),iVar2,&local_48);
      *(undefined8 *)(*(longlong *)(piVar5 + 10) + 0x6e0) = 0;
    }
    piVar5[0x16] = 0;
    piVar5[0x17] = 0;
    local_340 = 5;
    local_330 = piVar5[0x13];
    local_320 = local_48;
    uStack_318 = uStack_40;
    local_310 = local_38;
    local_32c = iVar2;
    uVar4 = PdcPortSendMessage(*(longlong *)(piVar5 + 10),(longlong)local_368);
    piVar5[0x14] = piVar5[0x14] + -1;
    if (piVar6 != (int *)0x0) goto LAB_14000ae89;
  }
  else {
    uVar4 = 0xc0000702;
  }
  piVar6 = piVar5;
LAB_14000ae89:
  PdcReleaseRwLockExclusive((longlong)(piVar6 + 2));
  return uVar4;
}



===== PdcSignalClientPulse @ 14000aec0 =====

void PdcSignalClientPulse(int *param_1,wchar_t *param_2)

{
  undefined1 local_328 [56];
  undefined4 local_2f0;
  
                    /* 0xaec0  12  PdcSignalClientPulse */
  memset(local_328,0,800);
  PdcpInitializeSignalChangeMessage(local_328,param_2);
  local_2f0 = 0;
  PdcpSignalClientSendChangeMessage(param_1,(longlong)local_328);
  return;
}



===== PdcSignalClientRegister @ 14000af20 =====

ulonglong PdcSignalClientRegister(int *param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffe0;
  
                    /* 0xaf20  13  PdcSignalClientRegister */
  *param_2 = 0;
  if (*param_1 == 1) {
    if (param_1[1] - 1U < 2) {
      puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x30,0x53636450);
      if (puVar1 == (undefined4 *)0x0) {
        uVar3 = 0xc0000017;
      }
      else {
        *puVar1 = 0x53636450;
        *(undefined8 *)(puVar1 + 4) = 0;
        *(undefined8 *)(puVar1 + 6) = 0;
        *(undefined8 *)(puVar1 + 2) = 0;
        local_res8 = 0;
        uVar2 = PdcPortOpenCommon(0x47,5,puVar1,&local_res8,param_1,0xac,0,in_stack_ffffffffffffffe0
                                  ,(undefined8 *)(puVar1 + 8));
        uVar3 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          ExFreePoolWithTag(puVar1,0);
        }
        else {
          *param_2 = puVar1;
        }
      }
    }
    else {
      uVar3 = 0xc00000f0;
    }
  }
  else {
    uVar3 = 0xc00000ef;
  }
  return uVar3;
}



===== PdcSignalClientSetActive @ 14000b010 =====

void PdcSignalClientSetActive(int *param_1,undefined1 param_2,wchar_t *param_3)

{
  undefined1 local_328 [56];
  undefined4 local_2f0;
  undefined1 local_268;
  
                    /* 0xb010  14  PdcSignalClientSetActive */
  memset(local_328,0,800);
  PdcpInitializeSignalChangeMessage(local_328,param_3);
  local_2f0 = 1;
  local_268 = param_2;
  PdcpSignalClientSendChangeMessage(param_1,(longlong)local_328);
  return;
}



===== PdcSignalClientUnregister @ 14000b090 =====

undefined8 PdcSignalClientUnregister(int *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0xb090  15  PdcSignalClientUnregister */
  puVar4 = auStack_28;
  piVar3 = param_1;
  if (*param_1 != 0x53636450) {
    piVar3 = (int *)0x5;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
    puVar4 = auStack_20;
  }
  *(undefined8 *)(puVar4 + -8) = 0x14000b0b5;
  PdcAcquireRwLockExclusive((longlong)(piVar3 + 2));
  puVar1 = *(undefined4 **)(param_1 + 8);
  *(undefined8 *)(puVar4 + -8) = 0x14000b0be;
  PdcPortClose(puVar1);
  param_1[8] = 0;
  param_1[9] = 0;
  *param_1 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14000b0cf;
  PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
  *(undefined8 *)(puVar4 + -8) = 0x14000b0db;
  ExFreePoolWithTag(param_1,0);
  return 0;
}



===== PdcpInitializeSignalChangeMessage @ 14000b0f4 =====

void PdcpInitializeSignalChangeMessage(void *param_1,wchar_t *param_2)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  wchar_t *pwVar5;
  longlong lVar4;
  short *psVar6;
  
  memset(param_1,0,800);
  *(undefined4 *)((longlong)param_1 + 0x28) = 8;
  psVar6 = (short *)((longlong)param_1 + 0x3c);
  if (psVar6 != (short *)0x0) {
    lVar3 = 0x40;
    pwVar5 = L"";
    if (param_2 != (wchar_t *)0x0) {
      pwVar5 = param_2;
    }
    lVar4 = (longlong)pwVar5 - (longlong)psVar6;
    do {
      if ((lVar3 == -0x7fffffbe) || (sVar1 = *(short *)(lVar4 + (longlong)psVar6), sVar1 == 0))
      break;
      *psVar6 = sVar1;
      psVar6 = psVar6 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    psVar2 = psVar6 + -1;
    if (lVar3 != 0) {
      psVar2 = psVar6;
    }
    *psVar2 = 0;
  }
  return;
}



===== PdcpSignalClientSendChangeMessage @ 14000b17c =====

undefined4 PdcpSignalClientSendChangeMessage(int *param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  piVar4 = param_1;
  if (*param_1 != 0x53636450) {
    piVar4 = (int *)0x5;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
    puVar5 = auStack_20;
  }
  *(undefined8 *)(puVar5 + -8) = 0x14000b1ac;
  PdcAcquireRwLockExclusive((longlong)(piVar4 + 2));
  lVar1 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(puVar5 + -8) = 0x14000b1b8;
  uVar3 = PdcPortSendMessage(lVar1,param_2);
  *(undefined8 *)(puVar5 + -8) = 0x14000b1c2;
  PdcReleaseRwLockExclusive((longlong)(piVar4 + 2));
  return uVar3;
}



===== PdcTaskClientRegister @ 14000b1e0 =====

int PdcTaskClientRegister(undefined4 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined8 local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 local_30c;
  undefined4 local_300;
  undefined4 local_2fc;
  
                    /* 0xb1e0  16  PdcTaskClientRegister */
  *param_2 = 0;
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x40,0x63636450);
  if (puVar2 == (undefined8 *)0x0) {
    return -0x3fffffe9;
  }
  *puVar2 = 0x63636450;
  *(undefined4 *)((longlong)puVar2 + 0x24) = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  *(undefined4 *)(puVar2 + 4) = param_1;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[1] = 0;
  memset(&local_338,0,800);
  puVar2[5] = 0;
  puVar4 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar3 == (undefined4 *)0x0) {
LAB_14000b294:
    iVar1 = -0x3fffffe9;
LAB_14000b299:
    if (puVar3 != (undefined4 *)0x0) {
      PdcpPortReleaseResources(puVar3);
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_14000b2bc;
  }
  else {
    *puVar3 = 0x50636450;
    puVar3[5] = 4;
    *(undefined8 **)(puVar3 + 0x1b4) = puVar2;
    puVar3[4] = param_1;
    ExInitializeRundownProtection(puVar3 + 2);
    *(undefined8 *)(puVar3 + 0x1b6) = 0;
    local_30c = 6;
    local_2fc = 4;
    local_338 = 0x32002f8;
    local_330 = 0;
    local_328 = 0;
    local_300 = param_1;
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
    if (puVar4 == (undefined4 *)0x0) goto LAB_14000b294;
    *puVar4 = 1;
    *(undefined4 **)(puVar4 + 4) = puVar3;
    *(undefined8 **)(puVar4 + 2) = &local_338;
    iVar1 = ZwPowerInformation(0x43,puVar4,0xe0,0,0);
    if (iVar1 < 0) goto LAB_14000b299;
    puVar2[5] = puVar3;
    iVar1 = 0;
  }
  ExFreePoolWithTag(puVar4,0);
LAB_14000b2bc:
  if (iVar1 == 0) {
    *param_2 = puVar2;
  }
  else {
    ExFreePoolWithTag(puVar2,0);
  }
  return iVar1;
}



===== PdcTaskClientRequest @ 14000b3d0 =====

int PdcTaskClientRequest(int *param_1,char param_2)

{
  int iVar1;
  undefined1 local_328 [40];
  undefined4 local_300;
  undefined1 local_2f0;
  
                    /* 0xb3d0  17  PdcTaskClientRequest */
  memset(local_328,0,800);
  if ((param_1 == (int *)0x0) || (*param_1 != 0x63636450)) {
    return -0x3fffff11;
  }
  PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
  if ((param_2 == '\0') && (param_1[0xc] == 0)) {
    iVar1 = -0x3fffffff;
    goto LAB_14000b478;
  }
  iVar1 = 0;
  if (param_2 == '\0') {
    if (param_1[0xc] == 1) {
LAB_14000b43e:
      local_2f0 = param_2 != '\0';
      local_300 = 7;
      PdcPortSendMessageSynchronously(*(longlong *)(param_1 + 10),(longlong)local_328);
      iVar1 = param_1[0xd];
      if (iVar1 < 0) goto LAB_14000b478;
    }
  }
  else if (param_1[0xc] == 0) goto LAB_14000b43e;
  if (param_2 == '\0') {
    param_1[0xc] = param_1[0xc] + -1;
  }
  else {
    param_1[0xc] = param_1[0xc] + 1;
  }
LAB_14000b478:
  PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
  return iVar1;
}



===== PdcTaskClientUnregister @ 14000b4a0 =====

undefined8 PdcTaskClientUnregister(int *param_1)

{
  undefined8 uVar1;
  
                    /* 0xb4a0  18  PdcTaskClientUnregister */
  uVar1 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x63636450)) {
    uVar1 = 0xc00000ef;
  }
  else {
    PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
    PdcPortClose(*(undefined4 **)(param_1 + 10));
    param_1[10] = 0;
    param_1[0xb] = 0;
    *param_1 = 0;
    PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
    ExFreePoolWithTag(param_1,0);
  }
  return uVar1;
}



===== PdcPortClose @ 14000b514 =====

void PdcPortClose(undefined4 *param_1)

{
  ExWaitForRundownProtectionRelease(param_1 + 2);
  ExRundownCompleted(param_1 + 2);
  PdcpPortReleaseResources(param_1);
  return;
}



===== PdcPortOpenCommon @ 14000b55c =====

ulonglong PdcPortOpenCommon(undefined4 param_1,int param_2,undefined8 param_3,longlong *param_4,
                           void *param_5,uint param_6,longlong param_7,undefined8 param_8,
                           undefined8 *param_9)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  short *psVar5;
  undefined4 *puVar6;
  short *psVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 local_30c;
  undefined4 local_300;
  int local_2fc;
  short local_2f0 [64];
  undefined1 local_270 [600];
  
  memset(&local_338,0,800);
  puVar6 = (undefined4 *)0x0;
  *param_9 = 0;
  if (((param_6 == 0) != (param_5 == (void *)0x0)) || (0xac < param_6)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    pcVar2 = (code *)swi(3);
    uVar8 = (*pcVar2)();
    return uVar8;
  }
  puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar4 == (undefined4 *)0x0) {
LAB_14000b5fe:
    uVar8 = 0xc0000017;
  }
  else {
    *puVar4 = 0x50636450;
    *(undefined8 *)(puVar4 + 0x1b4) = param_3;
    puVar4[4] = param_1;
    puVar4[5] = param_2;
    ExInitializeRundownProtection(puVar4 + 2);
    lVar9 = *param_4;
    *(longlong *)(puVar4 + 0x1b6) = lVar9;
    if ((lVar9 == 0) && (((param_2 - 4U & 0xfffffffa) != 0 || (param_2 == 9)))) {
      uVar8 = 0xc00000f1;
    }
    else {
      local_30c = 6;
      local_300 = param_1;
      local_2fc = param_2;
      if (param_5 != (void *)0x0) {
        memmove(local_270,param_5,(ulonglong)param_6);
      }
      if (param_7 != 0) {
        lVar9 = 0x40;
        psVar7 = local_2f0;
        do {
          if ((lVar9 == -0x7fffffbe) ||
             (sVar1 = *(short *)((param_7 - (longlong)local_2f0) + (longlong)psVar7), sVar1 == 0))
          break;
          *psVar7 = sVar1;
          psVar7 = psVar7 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        psVar5 = psVar7 + -1;
        if (lVar9 != 0) {
          psVar5 = psVar7;
        }
        *psVar5 = 0;
      }
      local_338 = 0x32002f8;
      local_330 = 0;
      local_328 = 0;
      puVar6 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
      if (puVar6 == (undefined4 *)0x0) goto LAB_14000b5fe;
      *puVar6 = 1;
      *(undefined4 **)(puVar6 + 4) = puVar4;
      *(undefined8 **)(puVar6 + 2) = &local_338;
      uVar3 = ZwPowerInformation(0x43,puVar6,0xe0,0,0);
      uVar8 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar8 = 0;
        *param_9 = puVar4;
        goto LAB_14000b615;
      }
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    PdcpPortReleaseResources(puVar4);
  }
  if (puVar6 == (undefined4 *)0x0) {
    return uVar8;
  }
LAB_14000b615:
  ExFreePoolWithTag(puVar6,0);
  return uVar8;
}



===== PdcPortSendMessage @ 14000b7b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcPortSendMessage(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ExAcquireRundownProtection(param_1 + 8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0000189;
  }
  else {
    *(undefined4 *)(param_2 + 0x2c) = 6;
    uVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x18),param_2,800);
    ExReleaseRundownProtection(param_1 + 8);
  }
  return uVar2;
}



===== PdcpPortReleaseResources @ 14000b830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpPortReleaseResources(undefined4 *param_1)

{
  undefined1 local_328 [40];
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f0;
  undefined4 local_2ec;
  
  memset(local_328,0,800);
  *param_1 = 0;
  if (*(longlong *)(param_1 + 6) != 0) {
    local_2f0 = param_1[4];
    local_2ec = param_1[5];
    local_300 = 1;
    local_2fc = 6;
    (**(code **)(param_1 + 8))(*(longlong *)(param_1 + 6),local_328,800);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PdcAcquireRwLockExclusive @ 14000b8b0 =====

void PdcAcquireRwLockExclusive(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  *(void **)(param_1 + 8) = SystemReserved1[0xf];
  return;
}



===== PdcAcquireRwLockExclusive2 @ 14000b8f0 =====

void PdcAcquireRwLockExclusive2(undefined8 *param_1,undefined1 *param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  do {
    iVar3 = KeWaitForSingleObject(*param_1,0,0,0);
    if (iVar3 == 0) goto LAB_14000b94e;
  } while (((iVar3 != 0xc0) && (iVar3 != 0x101)) && (iVar3 == 0x102));
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(5);
LAB_14000b94e:
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 1;
  }
  LOCK();
  piVar1 = (int *)(param_1 + 2);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar3 == 0) {
    param_1[1] = SystemReserved1[0xf];
  }
  if ((void *)param_1[1] != SystemReserved1[0xf]) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(0x28);
  }
  return;
}



===== PdcReleaseRwLockExclusive @ 14000b99c =====

void PdcReleaseRwLockExclusive(longlong param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  ExReleasePushLockEx(param_1,0);
  KeLeaveCriticalRegion();
  return;
}



===== PdcReleaseRwLockExclusive2 @ 14000b9cc =====

void PdcReleaseRwLockExclusive2(longlong *param_1,undefined1 *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 1;
  }
  if (((*param_1 == 0) || ((void *)param_1[1] != SystemReserved1[0xf])) || ((int)param_1[2] < 1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  LOCK();
  plVar1 = param_1 + 2;
  lVar3 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar3 == 1) {
    param_1[1] = 0;
  }
  KeReleaseMutex(*param_1,0);
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  return;
}



===== _tlgEnableCallback @ 14000ba40 =====

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



===== entry @ 14000d010 =====

void entry(void)

{
  __security_init_cookie();
  DllInitialize();
  return;
}



===== __security_init_cookie @ 14000d044 =====

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



===== DllInitialize @ 14000d080 =====

undefined8 DllInitialize(void)

{
                    /* 0xd080  1  DllInitialize */
  return 0;
}


