
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



===== McGenControlCallbackV2 @ 140001020 =====

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



===== McGenEventRegister_EtwRegister @ 140001130 =====

void McGenEventRegister_EtwRegister(void)

{
  if (IMCEXT_PROVIDER_ID_Context == 0) {
    EtwRegister(&IMCEXT_PROVIDER_ID,McGenControlCallbackV2,&IMCEXT_PROVIDER_ID_Context,
                &IMCEXT_PROVIDER_ID_Context);
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001170 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140004008;
  uVar2 = 0;
  if (DAT_140004008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140004008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(IMCEXT_PROVIDER_ID_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0d_EtwWriteTransfer @ 1400011d4 =====

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
  McGenEventWrite_EtwWriteTransfer
            (param_1,&IMC_ETW_EVENT_IMC_HIVE_UNLOAD_FAILURE,param_3,2,local_38);
  return;
}



===== McTemplateK0hzr0_EtwWriteTransfer @ 140001238 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5)

{
  ushort local_res20 [4];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  ushort *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_30 = 2;
  local_28 = param_5;
  local_1c = 0;
  local_20 = (uint)param_4 * 2;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&IMC_ETW_EVENT_IMC_COMPLETED_FOR_HIVE,param_3,3,local_48)
  ;
  return;
}



===== McTemplateK0hzr0hzr2_EtwWriteTransfer @ 1400012b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0hzr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,ushort param_6,undefined8 param_7)

{
  ushort local_res20 [4];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 2;
  local_58 = local_res20;
  local_3c = 0;
  local_48 = param_5;
  local_40 = (uint)param_4 * 2;
  local_30 = 2;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = (uint)param_6 * 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,5,local_68);
  return;
}



===== McTemplateK0xhzr1di_EtwWriteTransfer @ 140001354 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xhzr1di_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               ushort param_5,undefined8 param_6,undefined1 param_7)

{
  undefined1 auStackY_b8 [32];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = ImpBugcheckParam;
  local_88 = ImpBugcheckCodepoint;
  local_68 = &local_88;
  local_58 = &param_5;
  local_48 = param_6;
  local_40 = (uint)param_5 * 2;
  local_60 = 8;
  local_38 = &param_7;
  local_28 = &local_80;
  local_50 = 2;
  local_3c = 0;
  local_30 = 4;
  local_20 = 8;
  McGenEventWrite_EtwWriteTransfer(0,&IMC_ETW_EVENT_GENERAL_ERROR,param_3,6,local_78);
  return;
}



===== HviIsAnyHypervisorPresent @ 140001414 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140001448) */
/* WARNING: Removing unreachable block (ram,0x000140001437) */

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



===== HviIsHypervisorMicrosoftCompatible @ 140001470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000149d) */

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



===== __GSHandlerCheck @ 1400014c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400014ec =====

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



===== __cpu_features_init @ 140001560 =====

/* WARNING: Removing unreachable block (ram,0x0001400015ca) */
/* WARNING: Removing unreachable block (ram,0x000140001579) */
/* WARNING: Removing unreachable block (ram,0x00014000156a) */

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



===== _guard_check_icall @ 140001630 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001650 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001690 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400016c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140001740 =====

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



===== memset @ 140001a40 =====

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



===== __memset_repmovs @ 140001b80 =====

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



===== __memset_query @ 140001c00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140001c80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140001dc0 =====

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



===== __memset_spec_plain @ 140001e40 =====

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



===== CmCompleteInitMachineConfig @ 140008010 =====

void CmCompleteInitMachineConfig
               (undefined4 *param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  undefined *puVar2;
  undefined *puVar3;
  code *pcVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint uVar8;
  longlong lVar9;
  undefined **ppuVar10;
  
                    /* 0x8010  1  CmCompleteInitMachineConfig */
  McGenEventRegister_EtwRegister();
  if (ImpBugcheckCode == 0) {
    for (ppuVar10 = (undefined **)CmpImcAllowEventQueueHead; ppuVar10 != &CmpImcAllowEventQueueHead;
        ppuVar10 = (undefined **)*ppuVar10) {
      if (*(char *)(ppuVar10 + 2) == '\0') {
        if ((Microsoft_Windows_CoreSystem_InitMachineConfigEnableBits & 1) != 0) {
          param_2 = &IMC_ETW_EVENT_IMC_VALUE_BLOCKED;
          goto LAB_14000806d;
        }
      }
      else if ((Microsoft_Windows_CoreSystem_InitMachineConfigEnableBits & 2) != 0) {
        param_2 = &IMC_ETW_EVENT_IMC_VALUE_SET;
LAB_14000806d:
        McTemplateK0hzr0hzr2_EtwWriteTransfer
                  ((ulonglong)(*(ushort *)(ppuVar10 + 5) >> 1),param_2,param_3,
                   *(ushort *)(ppuVar10 + 3) >> 1,ppuVar10[4],*(ushort *)(ppuVar10 + 5) >> 1,
                   ppuVar10[6]);
      }
    }
    if ((ImpPerformConfig != '\0') &&
       ((Microsoft_Windows_CoreSystem_InitMachineConfigEnableBits & 2) != 0)) {
      lVar9 = -1;
      do {
        lVar9 = lVar9 + 1;
      } while (*(short *)(PTR_u_SYSTEM_140004078 + lVar9 * 2) != 0);
      McTemplateK0hzr0_EtwWriteTransfer(lVar9,param_2,param_3,(ushort)lVar9,PTR_u_SYSTEM_140004078);
    }
  }
  else {
    if (ImpBugcheckPhase == 5) {
      puVar7 = &DAT_140004062;
      ppuVar10 = &PTR_u__GLOBAL_140004058;
    }
    else {
      puVar7 = &DAT_140004082;
      ppuVar10 = &PTR_u_SYSTEM_140004078;
    }
    bVar5 = Microsoft_Windows_CoreSystem_InitMachineConfigEnableBits & 1;
    *puVar7 = 1;
    if (bVar5 != 0) {
      puVar3 = *ppuVar10;
      lVar9 = -1;
      do {
        lVar9 = lVar9 + 1;
      } while (*(short *)(puVar3 + lVar9 * 2) != 0);
      McTemplateK0xhzr1di_EtwWriteTransfer
                (lVar9,puVar3,param_3,param_4,(ushort)lVar9,puVar3,
                 (char)(undefined4)ImpBugcheckStatusCode);
    }
    lVar9 = ImpBugcheckPhase;
    if (((ImpBugcheckPhase == 5) && (ImpTreatImcLoaderFatalErrorAsFatal != '\0')) ||
       ((ImpBugcheckPhase == 6 && (ImpTreatImcInitFatalErrorAsFatal != '\0')))) {
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = 0;
      }
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(ImpBugcheckCode,lVar9,ImpBugcheckCodepoint,
                   CONCAT44(ImpBugcheckStatusCode._4_4_,(undefined4)ImpBugcheckStatusCode),
                   ImpBugcheckParam);
    }
  }
  uVar8 = 0;
  if (ImcpHiveList != (undefined *)0x0) {
    pcVar6 = &DAT_140004061;
    do {
      if (((1 < uVar8) && (pcVar6[-1] != '\0')) && (*pcVar6 == '\0')) goto LAB_140008113;
      uVar8 = uVar8 + 1;
      plVar1 = (longlong *)(pcVar6 + 0xf);
      pcVar6 = pcVar6 + 0x20;
    } while (*plVar1 != 0);
  }
  ImpUnloadImcHive();
LAB_140008113:
  while( true ) {
    puVar3 = CmpImcAllowEventQueueHead;
    if ((undefined **)CmpImcAllowEventQueueHead == &CmpImcAllowEventQueueHead) {
      return;
    }
    if ((*(undefined ***)(CmpImcAllowEventQueueHead + 8) != &CmpImcAllowEventQueueHead) ||
       (puVar2 = *(undefined **)CmpImcAllowEventQueueHead,
       *(undefined **)(puVar2 + 8) != CmpImcAllowEventQueueHead)) break;
    CmpImcAllowEventQueueHead = puVar2;
    *(undefined ***)(puVar2 + 8) = &CmpImcAllowEventQueueHead;
    ExFreePoolWithTag(*(undefined8 *)(puVar3 + 0x20),0x50434d49);
    ExFreePoolWithTag(*(undefined8 *)(puVar3 + 0x30),0x50434d49);
    ExFreePoolWithTag(puVar3,0x50434d49);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== DllUnload @ 140008260 =====

undefined8 DllUnload(void)

{
                    /* 0x8260  3  DllUnload */
  return 0;
}



===== DriverEntry @ 14000826c =====

undefined8 DriverEntry(void)

{
  return 0xc0000001;
}



===== ImpApplyMachineConfiguration @ 14000827c =====

ulonglong ImpApplyMachineConfiguration
                    (longlong param_1,longlong param_2,short *param_3,ulonglong param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  char cVar10;
  longlong local_res8;
  longlong local_res20;
  undefined8 local_58;
  longlong lStack_50;
  short *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  cVar10 = '\0';
  local_res20 = 0;
  pcVar3 = (char *)0x0;
  pcVar5 = (char *)0x0;
  pcVar6 = (char *)0x0;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = (short *)0x0;
  uStack_40 = 0;
  local_res8 = param_1;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (short *)0x0)) ||
     ((*(longlong *)(param_3 + 4) == 0 || (*param_3 == 0)))) {
    uVar9 = 0xc000000d;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000000d;
    }
    ImpBugcheckCodepoint = 5;
  }
  else {
    puVar8 = &local_58;
    local_58 = 0x30;
    uStack_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    lStack_50 = param_2;
    local_48 = param_3;
    uVar1 = ZwOpenKey(&local_res20,0x20019);
    uVar9 = (ulonglong)uVar1;
    if (((int)uVar1 < 0) || (pcVar7 = pcVar6, local_res20 == 0)) {
LAB_1400084df:
      uVar9 = 0;
      goto LAB_140008525;
    }
    do {
      while( true ) {
        pcVar6 = pcVar5;
        if (-1 < (int)uVar9) {
          if (pcVar7 == (char *)0x0) {
            puVar8 = (undefined8 *)0x50434d49;
            pcVar3 = (char *)ExAllocatePool2(0x40,0x28);
          }
          else {
            pcVar3 = pcVar7 + -0x18;
            pcVar7 = *(char **)pcVar7;
          }
          if (pcVar3 == (char *)0x0) {
            uVar9 = 0xffffffffc0000017;
            if (ImpBugcheckCode == 0) {
              ImpBugcheckStatusCode = 0xffffffffc0000017;
            }
            ImpBugcheckCodepoint = 6;
            ImpBugcheckParam = 0x28;
            goto LAB_140008510;
          }
          pcVar3[0] = '\0';
          pcVar3[1] = '\0';
          pcVar3[2] = '\0';
          pcVar3[3] = '\0';
          pcVar3[4] = '\0';
          pcVar3[5] = '\0';
          pcVar3[6] = '\0';
          pcVar3[7] = '\0';
          pcVar3[8] = '\0';
          pcVar3[9] = '\0';
          pcVar3[10] = '\0';
          pcVar3[0xb] = '\0';
          pcVar3[0xc] = '\0';
          pcVar3[0xd] = '\0';
          pcVar3[0xe] = '\0';
          pcVar3[0xf] = '\0';
          pcVar3[0x10] = '\0';
          pcVar3[0x11] = '\0';
          pcVar3[0x12] = '\0';
          pcVar3[0x13] = '\0';
          pcVar3[0x14] = '\0';
          pcVar3[0x15] = '\0';
          pcVar3[0x16] = '\0';
          pcVar3[0x17] = '\0';
          pcVar3[0x20] = '\0';
          pcVar3[0x21] = '\0';
          pcVar3[0x22] = '\0';
          pcVar3[0x23] = '\0';
          pcVar3[0x24] = '\0';
          pcVar3[0x25] = '\0';
          pcVar3[0x26] = '\0';
          pcVar3[0x27] = '\0';
          *(char **)(pcVar3 + 0x18) = pcVar5;
          pcVar5 = pcVar3 + 0x18;
          uVar4 = ImpCopyKeyValues(local_res20,local_res8);
          uVar9 = (ulonglong)(int)uVar4;
          if ((int)uVar4 < 0) {
            if (ImpBugcheckCode == 0) {
              ImpBugcheckStatusCode = uVar9;
            }
            ImpBugcheckCodepoint = 7;
            pcVar6 = pcVar7;
            goto LAB_140008509;
          }
          *(longlong *)(pcVar3 + 8) = local_res20;
          *(longlong *)(pcVar3 + 0x10) = local_res8;
          *pcVar3 = cVar10;
          local_res20 = 0;
          local_res8 = 0;
          pcVar6 = pcVar5;
        }
        cVar10 = '\x01';
        iVar2 = ImpGetSubkeyByIndex(*(longlong *)(pcVar3 + 8),*(undefined4 *)(pcVar3 + 0x20),puVar8,
                                    param_4);
        uVar9 = (ulonglong)iVar2;
        pcVar5 = pcVar6;
        if (-1 < iVar2) break;
        if (iVar2 != -0x7fffffe6) {
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = uVar9;
          }
          ImpBugcheckCodepoint = 9;
          pcVar6 = pcVar7;
          goto LAB_140008509;
        }
        ZwClose(*(undefined8 *)(pcVar3 + 8));
        if (*pcVar3 != '\0') {
          ZwClose(*(undefined8 *)(pcVar3 + 0x10));
        }
        pcVar3[0x10] = '\0';
        pcVar3[0x11] = '\0';
        pcVar3[0x12] = '\0';
        pcVar3[0x13] = '\0';
        pcVar3[0x14] = '\0';
        pcVar3[0x15] = '\0';
        pcVar3[0x16] = '\0';
        pcVar3[0x17] = '\0';
        pcVar3[8] = '\0';
        pcVar3[9] = '\0';
        pcVar3[10] = '\0';
        pcVar3[0xb] = '\0';
        pcVar3[0xc] = '\0';
        pcVar3[0xd] = '\0';
        pcVar3[0xe] = '\0';
        pcVar3[0xf] = '\0';
        if (pcVar6 != (char *)0x0) {
          pcVar5 = *(char **)pcVar6;
        }
        *(char **)pcVar6 = pcVar7;
        if (pcVar5 == (char *)0x0) goto LAB_1400084df;
        pcVar3 = pcVar5 + -0x18;
        *(int *)(pcVar5 + 8) = *(int *)(pcVar5 + 8) + 1;
        uVar9 = 0xffffffff8000001a;
        pcVar7 = pcVar6;
      }
      uVar4 = ImpEstablishNamedSubkey
                        (*(longlong *)(pcVar3 + 8),*(longlong *)(pcVar3 + 0x10),puVar8,param_4,
                         &local_res20,(longlong)&local_res8);
      uVar9 = (ulonglong)(int)uVar4;
    } while (-1 < (int)uVar4);
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = uVar9;
    }
    ImpBugcheckCodepoint = 8;
    pcVar6 = pcVar7;
  }
LAB_140008509:
  ImpBugcheckParam = 0;
  pcVar7 = pcVar6;
LAB_140008510:
  ImpBugcheckCode = 0x67;
  ImpBugcheckPhase = 6;
  pcVar6 = pcVar7;
LAB_140008525:
  if (local_res20 != 0) {
    ZwClose();
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  while (pcVar5 != (char *)0x0) {
    pcVar3 = *(char **)pcVar5;
    if (*(longlong *)(pcVar5 + -0x10) != 0) {
      ZwClose();
    }
    if ((*(longlong *)(pcVar5 + -8) != 0) && (pcVar5[-0x18] != '\0')) {
      ZwClose();
    }
    ExFreePoolWithTag(pcVar5 + -0x18,0x50434d49);
    pcVar5 = pcVar3;
  }
  while (pcVar6 != (char *)0x0) {
    pcVar5 = *(char **)pcVar6;
    if (*(longlong *)(pcVar6 + -0x10) != 0) {
      ZwClose();
    }
    if ((*(longlong *)(pcVar6 + -8) != 0) && (pcVar6[-0x18] != '\0')) {
      ZwClose();
    }
    ExFreePoolWithTag(pcVar6 + -0x18,0x50434d49);
    pcVar6 = pcVar5;
  }
  return uVar9 & 0xffffffff;
}



===== ImpCopyKeyValues @ 140008618 =====

ulonglong ImpCopyKeyValues(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  undefined8 local_18;
  longlong lStack_10;
  
  uVar2 = 0;
  uVar3 = 0;
  local_res8[0] = 0;
  local_18 = 0;
  lStack_10 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xc000000d;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000000d;
    }
    ImpBugcheckParam = 0;
    ImpBugcheckCodepoint = 10;
  }
  else {
    while( true ) {
      while( true ) {
        iVar1 = (int)uVar2;
        if (((iVar1 < 0) && (iVar1 != -0x3fffffdd)) && (iVar1 != -0x7ffffffb)) goto LAB_140008850;
        iVar1 = ZwEnumerateValueKey(param_1,uVar3,1,ImpEnumBuffer,ImpEnumBufferSize,local_res8);
        uVar2 = (ulonglong)iVar1;
        if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) break;
        if (iVar1 < 0) {
          if (iVar1 == -0x7fffffe6) {
            uVar2 = 0;
            goto LAB_140008850;
          }
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = uVar2;
          }
          ImpBugcheckCodepoint = 0xc;
          ImpBugcheckParam = uVar3;
          goto LAB_14000883b;
        }
        lStack_10 = ImpEnumBuffer + 0x14;
        local_18 = CONCAT62(CONCAT42(local_18._4_4_,*(undefined2 *)(ImpEnumBuffer + 0x10)),
                            *(undefined2 *)(ImpEnumBuffer + 0x10));
        iVar1 = ZwSetValueKey(param_2,&local_18,0,*(undefined4 *)(ImpEnumBuffer + 4),
                              (ulonglong)*(uint *)(ImpEnumBuffer + 8) + ImpEnumBuffer,
                              *(undefined4 *)(ImpEnumBuffer + 0xc));
        uVar2 = (ulonglong)iVar1;
        if (iVar1 < 0) {
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = uVar2;
          }
          ImpBugcheckParam = 0;
          ImpBugcheckCodepoint = 0xd;
          goto LAB_14000883b;
        }
        uVar3 = (ulonglong)((int)uVar3 + 1);
      }
      if (ImpEnumBuffer != 0) {
        ExFreePoolWithTag(ImpEnumBuffer,0x50434d49);
        ImpEnumBuffer = 0;
      }
      local_res8[0] = local_res8[0] + 0x1000 & 0xfffff000;
      ImpEnumBuffer = ExAllocatePool2(0x40,local_res8[0],0x50434d49);
      if (ImpEnumBuffer == 0) break;
      ImpEnumBufferSize = local_res8[0];
    }
    uVar2 = 0xffffffffc0000017;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc0000017;
    }
    ImpBugcheckParam = (ulonglong)local_res8[0];
    ImpEnumBufferSize = 0;
    ImpBugcheckCodepoint = 0xb;
  }
LAB_14000883b:
  ImpBugcheckPhase = 6;
  ImpBugcheckCode = 0x67;
LAB_140008850:
  return uVar2 & 0xffffffff;
}



===== ImpEstablishNamedSubkey @ 140008870 =====

ulonglong ImpEstablishNamedSubkey
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    longlong *param_5,longlong param_6)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  ulonglong *puVar4;
  ulonglong local_58;
  longlong lStack_50;
  ulonglong local_48;
  longlong lStack_40;
  undefined4 local_38;
  undefined4 local_34;
  longlong local_30;
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  local_48 = 0;
  lStack_40 = 0;
  if ((((param_1 == 0) || (param_2 == 0)) || (ImpEnumBuffer == 0)) ||
     ((param_5 == (longlong *)0x0 || (param_6 == 0)))) {
    uVar3 = 0xc000000d;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000000d;
    }
    ImpBugcheckCodepoint = 0xe;
  }
  else if (*(int *)(ImpEnumBuffer + 0x14) == 0) {
    uVar3 = 0xffffffffc000014c;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000014c;
    }
    ImpBugcheckCodepoint = 0xf;
  }
  else {
    lStack_50 = ImpEnumBuffer + 0x18;
    local_58 = (ulonglong)
               CONCAT22(*(undefined2 *)(ImpEnumBuffer + 0x14),*(undefined2 *)(ImpEnumBuffer + 0x14))
    ;
    uVar1 = *(uint *)(ImpEnumBuffer + 0xc);
    if (uVar1 - 1 < 0xfffffffe) {
      if (ImpEnumBufferSize <= *(int *)(ImpEnumBuffer + 0x10) + uVar1) {
        if (ImpBugcheckCode == 0) {
          ImpBugcheckStatusCode = 0xffffffffc000000d;
        }
        ImpBugcheckPhase = 6;
        ImpBugcheckCode = 0x67;
        ImpBugcheckCodepoint = 0x10;
        ImpBugcheckParam = 0;
        return 0xc000000d;
      }
      lStack_40 = ImpEnumBuffer + (ulonglong)uVar1;
      puVar4 = &local_48;
      local_48 = (ulonglong)
                 CONCAT22(*(undefined2 *)(ImpEnumBuffer + 0x10),
                          *(undefined2 *)(ImpEnumBuffer + 0x10));
    }
    else {
      puVar4 = (ulonglong *)0x0;
    }
    local_28 = &local_58;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    local_30 = param_1;
    uVar1 = ZwOpenKey(param_5,0x1020019,&local_38);
    if ((int)uVar1 < 0) {
      if (ImpBugcheckCode == 0) {
        ImpBugcheckStatusCode = (longlong)(int)uVar1;
      }
      ImpBugcheckCodepoint = 0x11;
      uVar3 = (ulonglong)uVar1;
    }
    else {
      local_28 = &local_58;
      local_38 = 0x30;
      local_18 = 0;
      uStack_10 = 0;
      local_20 = 0x240;
      local_30 = param_2;
      uVar3 = ZwOpenKey(param_6,0xf003f,&local_38);
      if (-1 < (int)uVar3) {
        return uVar3;
      }
      iVar2 = ImpGetObjectSecurityDescriptorByHandle(*param_5);
      uVar3 = CONCAT44(extraout_var,iVar2);
      if (iVar2 < 0) {
        if (ImpBugcheckCode == 0) {
          ImpBugcheckStatusCode = (ulonglong)iVar2;
        }
        ImpBugcheckCodepoint = 0x12;
      }
      else {
        local_28 = &local_58;
        local_18 = ImpSecDescBuffer;
        local_38 = 0x30;
        local_20 = 0x240;
        uStack_10 = 0;
        local_30 = param_2;
        iVar2 = ZwCreateKey(param_6,0xf003f,&local_38,0,puVar4,0,0);
        uVar3 = (ulonglong)iVar2;
        if (-1 < iVar2) {
          return uVar3;
        }
        if (ImpBugcheckCode == 0) {
          ImpBugcheckStatusCode = uVar3;
        }
        ImpBugcheckCodepoint = 0x13;
      }
    }
  }
  ImpBugcheckParam = 0;
  ImpBugcheckCode = 0x67;
  ImpBugcheckPhase = 6;
  return uVar3;
}



===== ImpGetObjectSecurityDescriptorByHandle @ 140008b3c =====

int ImpGetObjectSecurityDescriptorByHandle(longlong param_1)

{
  int iVar1;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000000d;
    }
    ImpBugcheckParam = 0;
    ImpBugcheckCodepoint = 0x14;
LAB_140008c54:
    ImpBugcheckPhase = 6;
    ImpBugcheckCode = 0x67;
  }
  else {
    while( true ) {
      iVar1 = ZwQuerySecurityObject(param_1,0xf,ImpSecDescBuffer,ImpSecDescBufferSize,local_res10);
      if (iVar1 != -0x3fffffdd) break;
      if (ImpSecDescBuffer != 0) {
        ExFreePoolWithTag(ImpSecDescBuffer,0x50434d49);
      }
      local_res10[0] = local_res10[0] + 0x1000 & 0xfffff000;
      ImpSecDescBuffer = ExAllocatePool2(0x40,local_res10[0],0x50434d49);
      if (ImpSecDescBuffer == 0) {
        iVar1 = -0x3fffffe9;
        if (ImpBugcheckCode == 0) {
          ImpBugcheckStatusCode = 0xffffffffc0000017;
        }
        ImpBugcheckParam = (ulonglong)local_res10[0];
        ImpSecDescBufferSize = 0;
        ImpBugcheckCodepoint = 0x15;
        goto LAB_140008c54;
      }
      ImpSecDescBufferSize = local_res10[0];
    }
  }
  return iVar1;
}



===== ImpGetSubkeyByIndex @ 140008c78 =====

int ImpGetSubkeyByIndex(longlong param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 local_res20;
  
  local_res20 = param_4 & 0xffffffff00000000;
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
    if (ImpBugcheckCode == 0) {
      ImpBugcheckStatusCode = 0xffffffffc000000d;
    }
    ImpBugcheckParam = 0;
    ImpBugcheckCodepoint = 0x16;
LAB_140008dc6:
    ImpBugcheckPhase = 6;
    ImpBugcheckCode = 0x67;
  }
  else {
    do {
      iVar1 = ZwEnumerateKey(param_1,param_2,1,ImpEnumBuffer,ImpEnumBufferSize,&local_res20);
      if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
        return iVar1;
      }
      if (ImpEnumBuffer != 0) {
        ExFreePoolWithTag(ImpEnumBuffer,0x50434d49);
        ImpEnumBuffer = 0;
      }
      uVar2 = (int)local_res20 + 0x1000;
      local_res20 = CONCAT44(local_res20._4_4_,uVar2) & 0xfffffffffffff000;
      ImpEnumBuffer = ExAllocatePool2(0x40,uVar2 & 0xfffff000,0x50434d49);
      if (ImpEnumBuffer == 0) {
        ImpEnumBufferSize = 0;
        iVar1 = -0x3fffffe9;
        if (ImpBugcheckCode == 0) {
          ImpBugcheckStatusCode = 0xffffffffc0000017;
        }
        ImpBugcheckParam = local_res20 & 0xffffffff;
        ImpBugcheckCodepoint = 0x17;
        goto LAB_140008dc6;
      }
      ImpEnumBufferSize = (int)local_res20;
    } while ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd));
  }
  return iVar1;
}



===== ImpUnloadImcHive @ 140008df4 =====

void ImpUnloadImcHive(void)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 *local_res18 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar2 = 0;
  local_2c = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_res18[0] = (undefined4 *)0x0;
  local_44 = 0;
  if (ImpImcHiveUnloaded != '\0') {
    return;
  }
  local_40 = 0;
  puVar5 = &local_48;
  local_48 = 0x30;
  local_38 = &ImpSystemImcFullKeyName;
  puVar4 = (undefined *)0x20019;
  local_30 = 0x240;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = ZwOpenKey(local_res18);
  if (iVar1 < 0) {
LAB_140008f65:
    local_40 = 0;
    local_38 = &ImpMachineConfigKeyName;
    puVar3 = &local_48;
    local_48 = 0x30;
    local_28 = 0;
    uStack_20 = 0;
    local_30 = 0x240;
    iVar1 = ZwUnloadKey();
    if (-1 < iVar1) {
      ImpImcHiveUnloaded = '\x01';
      goto LAB_140008f2f;
    }
  }
  else {
    puVar5 = (undefined4 *)0x2;
    puVar4 = &ImpSystemImcPreserveValueName;
    iVar1 = ZwQueryValueKey(local_res18[0],&ImpSystemImcPreserveValueName,2,0,0,local_res8);
    if (((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) || (local_res8[0] == 0))
    goto LAB_140008f65;
    puVar4 = (undefined *)(ulonglong)local_res8[0];
    puVar5 = (undefined4 *)0x50434d49;
    lVar2 = ExAllocatePool2(0x40);
    if (lVar2 == 0) goto LAB_140008f65;
    puVar4 = &ImpSystemImcPreserveValueName;
    puVar5 = (undefined4 *)0x2;
    puVar3 = local_res18[0];
    iVar1 = ZwQueryValueKey(local_res18[0],&ImpSystemImcPreserveValueName,2,lVar2,local_res8[0],
                            local_res10);
    if ((((iVar1 < 0) || (*(int *)(lVar2 + 4) != 4)) && (*(int *)(lVar2 + 8) != 4)) ||
       (*(int *)(lVar2 + 0xc) == 0)) goto LAB_140008f65;
    if (-1 < iVar1) goto LAB_140008f2f;
  }
  if ((Microsoft_Windows_CoreSystem_InitMachineConfigEnableBits & 4) != 0) {
    McTemplateK0d_EtwWriteTransfer(puVar3,puVar4,puVar5,iVar1);
  }
LAB_140008f2f:
  if (local_res18[0] != (undefined4 *)0x0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x50434d49);
  }
  return;
}



===== entry @ 14000a010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 14000a044 =====

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



===== CmSetInitMachineConfig @ 14000a080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000a105) */
/* WARNING: Removing unreachable block (ram,0x00014000a0e6) */

ulonglong CmSetInitMachineConfig
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  ulonglong *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined1 auStack_d8 [32];
  int *local_b8;
  undefined4 local_b0;
  int local_a8;
  int local_a4;
  int local_a0 [2];
  longlong local_98;
  longlong local_90;
  int local_88 [2];
  longlong local_80;
  undefined4 local_78;
  undefined4 local_74;
  longlong local_70;
  short *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  short local_48 [8];
  ulonglong local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
                    /* 0xa080  2  CmSetInitMachineConfig */
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  local_88[0] = 0;
  local_74 = 0;
  local_5c = 0;
  local_a8 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_90 = 0;
  local_a4 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar3 == '\0') {
LAB_14000a10e:
    uVar9 = 0;
  }
  else {
    puVar1 = (ulonglong *)cpuid(0x40000003);
    local_38 = *puVar1;
    if ((local_38 & 0x40000000000000) == 0) goto LAB_14000a10e;
    lVar2 = cpuid(0x4000000c);
    uVar9 = *(uint *)(lVar2 + 4) & 0xf;
  }
  local_80 = 0;
  local_98 = 0;
  local_a0[0] = 0;
  ImpPerformConfig = '\x01';
  RtlInitUnicodeString(local_48,PTR_u__REGISTRY_MACHI_140004070);
  local_68 = local_48;
  local_78 = 0x30;
  local_70 = 0;
  local_60 = 0x240;
  local_58 = 0;
  uStack_50 = 0;
  iVar4 = ZwOpenKey(&local_80,0x2001f,&local_78);
  if (iVar4 < 0) {
    uVar8 = 0xffffffffc000014c;
    if (*(int *)(*(longlong *)(param_1 + 0xf0) + 0xa78) == 0) {
      if (ImpBugcheckCode == 0) {
        ImpBugcheckStatusCode = 0xffffffffc000014c;
      }
      ImpBugcheckPhase = 6;
      ImpBugcheckCode = 0x67;
      ImpBugcheckCodepoint = 1;
      ImpBugcheckParam = 0;
    }
    ImpPerformConfig = '\0';
  }
  else {
    local_70 = local_80;
    local_78 = 0x30;
    local_68 = (short *)&ImpSystemSubkeyName;
    local_60 = 0x240;
    local_58 = 0;
    uStack_50 = 0;
    uVar5 = ZwOpenKey(&local_98,0x2001f,&local_78);
    uVar8 = (ulonglong)uVar5;
    if (((int)uVar5 < 0) || (local_98 == 0)) {
      uVar8 = 0;
      ImpPerformConfig = '\0';
    }
    else {
      ImpEstablishIMCPolicies(local_98);
      ImpTreatImcInitFatalErrorAsFatal = DAT_14000408c;
    }
    lVar2 = *(longlong *)(param_1 + 0xf0);
    if (*(int *)(lVar2 + 0xa78) != 0) {
      uVar8 = (ulonglong)*(int *)(lVar2 + 0xa90);
      if (ImpBugcheckCode == 0) {
        ImpBugcheckStatusCode = uVar8;
      }
      ImpBugcheckCodepoint = *(undefined8 *)(lVar2 + 0xa88);
      ImpBugcheckParam = *(undefined8 *)(lVar2 + 0xa98);
      ImpBugcheckCode = 0x67;
      ImpBugcheckPhase = 5;
      ImpPerformConfig = '\0';
    }
    if (ImpPerformConfig == '\0') {
LAB_14000a2ef:
      if (-1 < (int)uVar8) goto LAB_14000a2fa;
    }
    else {
      ImpPerformConfig = '\0';
      if (uVar9 == 0) {
LAB_14000a411:
        local_78 = 0x30;
        local_68 = (short *)&ImpMachineConfigKeyName;
        local_70 = 0;
        local_60 = 0x240;
        local_58 = 0;
        uStack_50 = 0;
        iVar4 = ZwOpenKey(&local_90,0x20019,&local_78);
        if ((iVar4 < 0) || (local_90 == 0)) {
          ImpImcHiveUnloaded = 1;
          uVar8 = 0;
          goto LAB_14000a2fa;
        }
        uVar7 = ImpReadImcHiveDword(local_98,&ImpSequenceValueName,local_a0);
        if ((int)uVar7 < 0) {
          uVar8 = 0;
          ImpBugcheckCode = 0;
          goto LAB_14000a2fa;
        }
        uVar8 = ImpReadImcHiveDword(local_90,&ImpSequenceValueName,&local_a4);
        if ((int)uVar8 < 0) {
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = (ulonglong)(int)uVar8;
          }
          ImpBugcheckCode = 0x67;
          uVar8 = uVar8 & 0xffffffff;
          ImpBugcheckPhase = 6;
          ImpBugcheckCodepoint = 2;
          ImpBugcheckParam = 0;
          goto LAB_14000a2f3;
        }
        if (local_a4 == local_a0[0]) {
          uVar6 = ImpReadImcHiveDword(local_90,&ImpForceImcUpdateValueName,local_88);
          if ((int)uVar6 == -0x3fffffcc) {
            uVar8 = 0;
            iVar4 = 0;
          }
          else {
            uVar8 = uVar6 & 0xffffffff;
            if ((int)uVar6 < 0) goto LAB_14000a2f3;
            iVar4 = local_88[0];
          }
          if (iVar4 == 0) goto LAB_14000a2fa;
        }
        ImpPerformConfig = '\x01';
        if (DAT_140004080 == '\0') {
LAB_14000a5b1:
          if (local_98 == 0) {
            iVar4 = -0x3ffffff3;
            uVar8 = 0xc000000d;
          }
          else {
            local_b8 = &local_a4;
            local_b0 = 4;
            uVar8 = ZwSetValueKey(local_98,&ImpSequenceValueName,0,4);
            iVar4 = (int)uVar8;
            uVar8 = uVar8 & 0xffffffff;
            if (-1 < iVar4) goto LAB_14000a2fa;
          }
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = (ulonglong)iVar4;
          }
          ImpBugcheckCodepoint = 4;
        }
        else {
          RtlInitUnicodeString(local_48,PTR_u_SYSTEM_140004078);
          if (uVar9 == 0) {
            uVar8 = ImpApplyMachineConfiguration(local_80,local_90,local_48,param_4);
            uVar9 = (uint)uVar8;
          }
          else {
            uVar8 = ImpProcessImc();
            uVar9 = (uint)uVar8;
          }
          DAT_140004081 = 1;
          uVar8 = (ulonglong)uVar9;
          if (-1 < (int)uVar9) goto LAB_14000a5b1;
          if (ImpBugcheckCode == 0) {
            ImpBugcheckStatusCode = (ulonglong)(int)uVar9;
          }
          ImpBugcheckCodepoint = 3;
        }
        ImpBugcheckPhase = 6;
        ImpBugcheckCode = 0x67;
        ImpBugcheckParam = 0;
      }
      else {
        uVar6 = ImpReadImcHiveDword(local_98,&ImpProcessImcValueName,&local_a8);
        uVar8 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
          if ((int)uVar6 == -0x3fffffcc) {
            uVar8 = 0;
            ImpImcHiveUnloaded = 1;
            goto LAB_14000a2ef;
          }
        }
        else {
          if (local_a8 == 0) {
            uVar8 = 0;
            ImpImcHiveUnloaded = 1;
            goto LAB_14000a2fa;
          }
          local_a8 = 0;
          if (local_98 == 0) {
            uVar8 = 0xc000000d;
          }
          else {
            local_b8 = &local_a8;
            local_b0 = 4;
            param_4 = 4;
            uVar5 = ZwSetValueKey(local_98,&ImpProcessImcValueName,0);
            uVar8 = (ulonglong)uVar5;
            if (-1 < (int)uVar5) goto LAB_14000a411;
          }
        }
      }
    }
  }
LAB_14000a2f3:
  DAT_140004082 = 1;
LAB_14000a2fa:
  if (ImpEnumBuffer != 0) {
    ExFreePoolWithTag(ImpEnumBuffer,0x50434d49);
    ImpEnumBuffer = 0;
  }
  ImpEnumBufferSize = 0;
  if (ImpSecDescBuffer != 0) {
    ExFreePoolWithTag(ImpSecDescBuffer,0x50434d49);
    ImpSecDescBuffer = 0;
  }
  ImpSecDescBufferSize = 0;
  if (local_80 != 0) {
    ZwClose();
  }
  if (local_98 != 0) {
    ZwClose();
  }
  if (local_90 != 0) {
    ZwClose();
  }
  return uVar8 & 0xffffffff;
}



===== ImpEstablishIMCPolicies @ 14000a624 =====

void ImpEstablishIMCPolicies(undefined8 param_1)

{
  longlong *plVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_res10 [2];
  longlong local_res18;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_res10[0] = 0;
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  iVar6 = 0;
  local_res18 = 0;
  lVar5 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  if (ImcpHiveList != (undefined *)0x0) {
    puVar7 = &DAT_140004064;
    do {
      RtlInitUnicodeString(&local_68,*(undefined8 *)(puVar7 + -3));
      local_48 = &local_68;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
      local_38 = 0;
      uStack_30 = 0;
      uStack_50 = param_1;
      iVar4 = ZwOpenKey(&local_res18,0x20019,&local_58);
      if ((-1 < iVar4) && (local_res18 != 0)) {
        iVar4 = ZwQueryValueKey(local_res18,&ImpErrorControlPolicyValueName,2,lVar5,iVar6,
                                local_res10);
        if (((iVar4 == -0x7ffffffb) || (iVar4 == -0x3fffffdd)) && (local_res10[0] != 0)) {
          if (lVar5 != 0) {
            ExFreePoolWithTag(lVar5,0x50434d49);
          }
          iVar6 = local_res10[0];
          lVar5 = ExAllocatePool2(0x40,local_res10[0],0x50434d49);
          if (lVar5 == 0) goto LAB_14000a8d0;
          iVar4 = ZwQueryValueKey(local_res18,&ImpErrorControlPolicyValueName,2,lVar5,iVar6,
                                  local_res10);
        }
        if (((-1 < iVar4) && (*(int *)(lVar5 + 4) == 4)) && (*(int *)(lVar5 + 8) == 4)) {
          *puVar7 = *(undefined4 *)(lVar5 + 0xc);
        }
        iVar4 = ZwQueryValueKey(local_res18,&ImpApplicationPolicyValueName,2,lVar5,iVar6,local_res10
                               );
        if (((iVar4 == -0x7ffffffb) || (iVar4 == -0x3fffffdd)) && (local_res10[0] != 0)) {
          if (lVar5 != 0) {
            ExFreePoolWithTag(lVar5,0x50434d49);
          }
          iVar6 = local_res10[0];
          lVar5 = ExAllocatePool2(0x40,local_res10[0],0x50434d49);
          if (lVar5 == 0) goto LAB_14000a8d0;
          iVar4 = ZwQueryValueKey(local_res18,&ImpApplicationPolicyValueName,2,lVar5,iVar6,
                                  local_res10);
        }
        if (((-1 < iVar4) && (*(int *)(lVar5 + 4) == 4)) && (*(int *)(lVar5 + 8) == 4)) {
          puVar7[1] = *(undefined4 *)(lVar5 + 0xc);
        }
        ZwClose();
        local_res18 = 0;
      }
      plVar1 = (longlong *)(puVar7 + 3);
      puVar7 = puVar7 + 8;
    } while (*plVar1 != 0);
  }
  iVar6 = 0;
  puVar3 = &DAT_140004064;
  puVar2 = ImcpHiveList;
  while (puVar2 != (undefined *)0x0) {
    if (iVar6 == 0) {
      ImpTreatImcLoaderFatalErrorAsFatal = (byte)*puVar3 & 1;
    }
    else {
      *(byte *)(puVar3 + 2) = (byte)(*puVar3 >> 2) & 1;
      if (((byte)puVar3[1] & 3) == 1) {
        *(undefined1 *)(puVar3 + -1) = 1;
      }
    }
    iVar6 = iVar6 + 1;
    puVar2 = *(undefined **)(puVar3 + 3);
    puVar3 = puVar3 + 8;
  }
LAB_14000a8d0:
  if (local_res18 != 0) {
    ZwClose();
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x50434d49);
  }
  return;
}



===== ImpReadImcHiveDword @ 14000a918 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ImpReadImcHiveDword(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38[0] = 0;
  local_20 = 0;
  local_40 = local_38;
  local_48 = 0x14;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = ZwQueryValueKey(0,param_2,2,&local_30);
  if (-1 < (int)uVar1) {
    if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
      *param_3 = uStack_28._4_4_;
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  return uVar1;
}



===== ImpAddAllowListEvent @ 14000a9a8 =====

undefined8 ImpAddAllowListEvent(undefined1 param_1,undefined2 *param_2,undefined2 *param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined **ppuVar4;
  
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x38,0x50434d49);
  if (puVar2 != (undefined8 *)0x0) {
    *(undefined1 *)(puVar2 + 2) = param_1;
    *(undefined2 *)(puVar2 + 3) = *param_2;
    *(undefined2 *)((longlong)puVar2 + 0x1a) = param_2[1];
    lVar3 = ExAllocatePool2(0x100,param_2[1],0x50434d49);
    puVar2[4] = lVar3;
    if (lVar3 != 0) {
      RtlCopyUnicodeString(puVar2 + 3,param_2);
      *(undefined2 *)(puVar2 + 5) = *param_3;
      *(undefined2 *)((longlong)puVar2 + 0x2a) = param_3[1];
      lVar3 = ExAllocatePool2(0x100,param_3[1],0x50434d49);
      puVar2[6] = lVar3;
      if (lVar3 != 0) {
        RtlCopyUnicodeString(puVar2 + 5,param_3);
        ppuVar4 = &CmpImcAllowEventQueueHead;
        if (*(undefined ***)PTR_CmpImcAllowEventQueueHead_1400040b8 != &CmpImcAllowEventQueueHead) {
          ppuVar4 = (undefined **)0x3;
          pcVar1 = (code *)swi(0x29);
          PTR_CmpImcAllowEventQueueHead_1400040b8 = (undefined *)(*pcVar1)();
        }
        *puVar2 = ppuVar4;
        puVar2[1] = PTR_CmpImcAllowEventQueueHead_1400040b8;
        *(undefined8 **)PTR_CmpImcAllowEventQueueHead_1400040b8 = puVar2;
        PTR_CmpImcAllowEventQueueHead_1400040b8 = (undefined *)puVar2;
        return 0;
      }
    }
    if (puVar2[4] != 0) {
      ExFreePoolWithTag(puVar2[4],0x50434d49);
    }
    if (puVar2[6] != 0) {
      ExFreePoolWithTag(puVar2[6],0x50434d49);
    }
    ExFreePoolWithTag(puVar2,0x50434d49);
  }
  return 0xc0000017;
}



===== ImpGetRegValueSz @ 14000ab28 =====

int ImpGetRegValueSz(undefined8 param_1,undefined8 param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  longlong lVar2;
  void *_Dst;
  int local_res8 [2];
  longlong local_50 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_50[0] = 0;
  local_2c = 0;
  local_res8[0] = 0;
  local_50[1] = 0x30;
  lVar2 = 0;
  local_50[2] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0x1240;
  local_50[3] = param_1;
  iVar1 = ZwOpenKey(local_50,0x20019,local_50 + 1);
  if (iVar1 < 0) {
LAB_14000ac8e:
    if (*(longlong *)(param_4 + 4) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_4 + 4),0x50434d49);
    }
    if (lVar2 == 0) goto LAB_14000acc1;
  }
  else {
    iVar1 = ZwQueryValueKey(local_50[0],param_2,2,0,0,local_res8);
    if (iVar1 != -0x3fffffdd) {
      if (-1 < iVar1) goto LAB_14000acc1;
      goto LAB_14000ac8e;
    }
    if (local_res8[0] == 0) {
      iVar1 = -0x3fffffcc;
      goto LAB_14000ac8e;
    }
    lVar2 = ExAllocatePool2(0x100,local_res8[0],0x50434d49);
    if (lVar2 == 0) {
LAB_14000ac08:
      iVar1 = -0x3fffff66;
      goto LAB_14000ac8e;
    }
    iVar1 = ZwQueryValueKey(local_50[0],param_2,2,lVar2,local_res8[0],local_res8);
    if (iVar1 < 0) goto LAB_14000ac8e;
    if (*(int *)(lVar2 + 4) != param_3) {
      iVar1 = -0x3fffffdc;
      goto LAB_14000ac8e;
    }
    _Dst = (void *)ExAllocatePool2(0x100,*(undefined4 *)(lVar2 + 8),0x50434d49);
    *(void **)(param_4 + 4) = _Dst;
    if (_Dst == (void *)0x0) goto LAB_14000ac08;
    *param_4 = *(undefined2 *)(lVar2 + 8);
    memmove(_Dst,(void *)(lVar2 + 0xc),(ulonglong)*(uint *)(lVar2 + 8));
  }
  ExFreePoolWithTag(lVar2,0x50434d49);
LAB_14000acc1:
  if (local_50[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== ImpProcessImc @ 14000acfc =====

ulonglong ImpProcessImc(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined4 local_res8 [2];
  ushort local_28 [4];
  longlong lStack_20;
  ushort local_18 [4];
  longlong lStack_10;
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  lStack_20 = 0;
  RtlInitUnicodeString(local_18,0);
  RtlInitUnicodeString(local_28,0);
  local_res8[0] = 1;
  bVar1 = false;
  bVar2 = false;
  iVar3 = ImpGetRegValueSz(&ImpImcComputerNameKey,&ImpComputerNameValueName,1,local_18);
  if (iVar3 < 0) {
    if (iVar3 != -0x3fffffcc) goto LAB_14000ad74;
LAB_14000ade0:
    iVar3 = ImpGetRegValueSz(&ImpImcPagingKey,&ImpPagingValueName,7,local_28);
    if (-1 < iVar3) {
      bVar2 = true;
      uVar4 = ImpValidatePagingFiles(local_28);
      if (-1 < (int)uVar4) goto LAB_14000ae2b;
LAB_14000ae08:
      puVar9 = (undefined2 *)&ImpPagingValueName;
      puVar8 = (undefined2 *)&ImpImcPagingKey;
      goto LAB_14000ad82;
    }
    if (iVar3 != -0x3fffffcc) goto LAB_14000ae08;
LAB_14000ae2b:
    if (bVar1) {
      uVar4 = ImpSetComputerNameValues(local_18);
      uVar7 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) goto LAB_14000ad8b;
    }
    if (bVar2) {
      uVar6 = ImpSetRegValue((undefined2 *)&ImpMachinePagingKey,(undefined2 *)&ImpPagingValueName,7,
                             lStack_20,(uint)local_28[0]);
      uVar7 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) goto LAB_14000ad8b;
    }
    uVar7 = ImpSetRegValue((undefined2 *)&ImpMachineSanPolicyKey,
                           (undefined2 *)&ImpSanPolicyValueName,4,local_res8,4);
    uVar4 = (uint)uVar7;
  }
  else {
    bVar1 = true;
    uVar5 = ImpValidateComputerName(local_18);
    if (-1 < (int)uVar5) goto LAB_14000ade0;
LAB_14000ad74:
    puVar9 = (undefined2 *)&ImpComputerNameValueName;
    puVar8 = (undefined2 *)&ImpImcComputerNameKey;
LAB_14000ad82:
    uVar5 = ImpAddAllowListEvent(0,puVar8,puVar9);
    uVar4 = (uint)uVar5;
  }
  uVar7 = (ulonglong)uVar4;
LAB_14000ad8b:
  if (lStack_10 != 0) {
    ExFreePoolWithTag(lStack_10,0x50434d49);
  }
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0x50434d49);
  }
  return uVar7;
}



===== ImpSetComputerNameValues @ 14000aea4 =====

void ImpSetComputerNameValues(ushort *param_1)

{
  ulonglong uVar1;
  undefined4 local_res8 [8];
  
  local_res8[0] = 1;
  uVar1 = ImpSetRegValue((undefined2 *)&ImpMachineComputerNameKey,
                         (undefined2 *)&ImpComputerNameValueName,1,*(undefined8 *)(param_1 + 4),
                         (uint)*param_1);
  if (-1 < (int)uVar1) {
    uVar1 = ImpSetRegValue((undefined2 *)&ImpMachineTcpIpParametersKey,
                           (undefined2 *)&ImpHostNameValueName,1,*(undefined8 *)(param_1 + 4),
                           (uint)*param_1);
    if (-1 < (int)uVar1) {
      uVar1 = ImpSetRegValue((undefined2 *)&ImpMachineTcpIpParametersKey,
                             (undefined2 *)&ImpNvHostNameValueName,1,*(undefined8 *)(param_1 + 4),
                             (uint)*param_1);
      if (-1 < (int)uVar1) {
        uVar1 = ImpSetRegValue((undefined2 *)&ImpMachineDjoinKey,(undefined2 *)&ImpNameSetValueName,
                               4,local_res8,4);
        if (-1 < (int)uVar1) {
          ImpSetRegValue((undefined2 *)&ImpMachineDjoinKey,(undefined2 *)&ImpMarkNameSetValueName,4,
                         local_res8,4);
        }
      }
    }
  }
  return;
}



===== ImpSetRegValue @ 14000af88 =====

ulonglong ImpSetRegValue(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,
                        undefined8 param_4,undefined4 param_5)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_res8;
  undefined8 local_48;
  undefined8 local_40;
  undefined2 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_2c = 0;
  local_res8 = 0;
  local_40 = 0;
  local_48 = 0x30;
  local_30 = 0x240;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = param_1;
  uVar1 = ZwOpenKey(&local_res8,0x20006,&local_48);
  uVar2 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar1 = ZwSetValueKey(local_res8,param_2,0,param_3,param_4,param_5);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = ImpAddAllowListEvent(1,param_1,param_2);
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return uVar2;
}



===== ImpValidateComputerName @ 14000b070 =====

undefined8 ImpValidateComputerName(ushort *param_1)

{
  ushort uVar1;
  wchar_t *_Str;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *param_1;
  uVar3 = (uVar1 >> 1) - 1;
  if (((1 < uVar1) && ((uVar1 & 1) == 0)) && (uVar3 != 0)) {
    _Str = *(wchar_t **)(param_1 + 4);
    if ((_Str[uVar3] == L'\0') && (uVar3 < 0x10)) {
      uVar5 = 0;
      if (uVar3 != 0) {
        do {
          if (0x5d < (ushort)(_Str[uVar5] + L'￟')) {
            return 0xc000000d;
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < uVar3);
      }
      sVar2 = wcscspn(_Str,
                      L"\"/\\[]:|<>+=;,?\x01\x02\x03\x04\x05\x06\a\b\t\n\v\f\r\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f"
                     );
      if (((uVar3 <= sVar2) && (**(short **)(param_1 + 4) != 0x20)) &&
         ((*(short **)(param_1 + 4))[uVar3] != 0x20)) {
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== ImpValidatePagingFiles @ 14000b118 =====

uint ImpValidatePagingFiles(ushort *param_1)

{
  ushort uVar1;
  short sVar2;
  short *psVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = *param_1;
  uVar7 = (uint)(uVar1 >> 1);
  bVar4 = false;
  uVar8 = uVar7 - 2;
  uVar6 = 0;
  if (uVar1 < 4) {
    return 0xc000000d;
  }
  if ((uVar1 & 1) != 0) {
    return 0xc000000d;
  }
  if (0x16 < uVar7 - 0x11) {
    return 0xc000000d;
  }
  psVar3 = *(short **)(param_1 + 4);
  if (psVar3[uVar8] != 0) {
    return 0xc000000d;
  }
  if (psVar3[uVar7 - 1] != 0) {
    return 0xc000000d;
  }
  if (0x3b < (ushort)(*psVar3 - 0x3fU)) {
    return 0xc000000d;
  }
  if ((0xffffffc0ffffffdU >> ((ulonglong)(ushort)(*psVar3 - 0x3fU) & 0x3f) & 1) == 0) {
    return 0xc000000d;
  }
  iVar5 = _wcsnicmp(psVar3 + 1,L":\\pagefile.sys",0xe);
  if (iVar5 != 0) {
    return 0xc000000d;
  }
  sVar2 = *(short *)(*(longlong *)(param_1 + 4) + 0x1e);
  if (sVar2 == 0x20) {
    uVar7 = 0x10;
    if (uVar8 < 0x11) {
      return 0xc000000d;
    }
    do {
      sVar2 = *(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar7 * 2);
      if (sVar2 == 0x20) {
        if (bVar4) {
          return 0xc000000d;
        }
        bVar4 = true;
        if (uVar7 + 1 == uVar8) {
          return 0xc000000d;
        }
      }
      else if (9 < (ushort)(sVar2 - 0x30U)) {
        return 0xc000000d;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar8);
    if (!bVar4) {
      return 0xc000000d;
    }
  }
  else {
    uVar6 = -(uint)(sVar2 != 0) & 0xc000000d;
    uVar7 = 0xf;
    if (sVar2 != 0) {
      return uVar6;
    }
  }
  if (uVar7 == uVar8) {
    return uVar6;
  }
  return 0xc000000d;
}


