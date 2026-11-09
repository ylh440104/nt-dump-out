
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



===== RtlStringCchCatExW @ 140001020 =====

uint RtlStringCchCatExW(short *param_1,undefined8 param_2,short *param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 local_res10 [2];
  ulonglong local_res20;
  
  lVar9 = 0x40;
  psVar3 = param_1;
  do {
    if (*psVar3 == 0) break;
    psVar3 = psVar3 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar8 = -(ulonglong)(lVar9 != 0) & 0x40U - lVar9;
  uVar6 = ~-(uint)(lVar9 != 0) & 0xc000000d;
  if (lVar9 != 0) {
    uVar5 = 0x40 - uVar8;
    psVar3 = param_1 + uVar8;
    if (uVar5 < 2) {
      if (*param_3 == 0) {
        return 0;
      }
      uVar6 = (-(uint)(param_1 != (short *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      lVar7 = 0;
      lVar9 = 0x7ffffffe;
      psVar4 = psVar3;
      uVar10 = uVar5;
      do {
        if ((lVar9 == 0) ||
           (sVar1 = *(short *)(((longlong)param_3 - (longlong)psVar3) + (longlong)psVar4),
           sVar1 == 0)) break;
        *psVar4 = sVar1;
        lVar9 = lVar9 + -1;
        psVar4 = psVar4 + 1;
        lVar7 = lVar7 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      lVar9 = lVar7 + -1;
      psVar2 = psVar4 + -1;
      if (uVar10 != 0) {
        lVar9 = lVar7;
        psVar2 = psVar4;
      }
      *psVar2 = 0;
      uVar6 = ~-(uint)(uVar10 != 0) & 0x80000005;
      if (uVar10 != 0) {
        if (uVar5 - lVar9 < 2) {
          return uVar6;
        }
        uVar8 = (uVar5 - lVar9) * 2;
        if (uVar8 < 3) {
          return uVar6;
        }
        memset(psVar3 + lVar9 + 1,0,uVar8 - 2);
        return uVar6;
      }
    }
    RtlStringExHandleOtherFlagsW(param_1,0x80,uVar8,local_res10,&local_res20,0x600);
  }
  return uVar6;
}



===== RtlStringCchPrintfExA @ 140001168 =====

int RtlStringCchPrintfExA
              (char *param_1,ulonglong param_2,undefined8 *param_3,ulonglong *param_4,uint param_5,
              char *param_6,char param_7)

{
  int iVar1;
  ulonglong _Count;
  int iVar2;
  ulonglong uVar3;
  char *pcVar4;
  
  iVar2 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar2 = 0;
    if (0x7ffffffe < param_2 - 1) {
      iVar2 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (char *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (param_2 == 0) {
      return iVar2;
    }
    *param_1 = '\0';
    return iVar2;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (char *)0x0)) {
    param_6 = "";
  }
  iVar2 = 0;
  uVar3 = param_2;
  pcVar4 = param_1;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == '\0') goto LAB_14000131e;
      iVar2 = (-(uint)(param_1 != (char *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      _Count = param_2 - 1;
      iVar1 = _vsnprintf(param_1,_Count,param_6,&param_7);
      if (iVar1 < 0) {
LAB_1400012b4:
        iVar2 = -0x7ffffffb;
LAB_1400012b9:
        param_1[_Count] = '\0';
      }
      else {
        uVar3 = (ulonglong)iVar1;
        if (_Count < uVar3) goto LAB_1400012b4;
        if (uVar3 == _Count) goto LAB_1400012b9;
        _Count = uVar3;
      }
      uVar3 = param_2 - _Count;
      pcVar4 = param_1 + _Count;
      if (-1 < iVar2) {
        if (((param_5 >> 9 & 1) != 0) && (1 < uVar3)) {
          memset(pcVar4 + 1,param_5 & 0xff,uVar3 - 1);
        }
        goto LAB_14000131e;
      }
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    if ((param_5 >> 0xc & 1) != 0) {
      *param_1 = '\0';
      uVar3 = param_2;
      pcVar4 = param_1;
    }
    if ((param_5 >> 10 & 1) != 0) {
      memset(param_1,param_5 & 0xff,param_2);
      if ((char)param_5 == '\0') {
        uVar3 = param_2;
        pcVar4 = param_1;
      }
      else {
        uVar3 = 1;
        pcVar4 = param_1 + (param_2 - 1);
        *pcVar4 = '\0';
      }
    }
    if ((param_5 >> 0xb & 1) != 0) {
      *param_1 = '\0';
      uVar3 = param_2;
      pcVar4 = param_1;
    }
  }
  if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x7ffffffb)) {
    return iVar2;
  }
LAB_14000131e:
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = pcVar4;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar3;
  }
  return iVar2;
}



===== RtlStringCchPrintfExW @ 14000135c =====

int RtlStringCchPrintfExW
              (wchar_t *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,uint param_5,
              wchar_t *param_6,char param_7)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong _Count;
  wchar_t *pwVar4;
  wchar_t *local_58;
  ulonglong local_50 [2];
  
  iVar3 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar3 = 0;
    if (0x7ffffffe < param_2 - 1) {
      iVar3 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (wchar_t *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    iVar3 = -0x3ffffff3;
  }
  if (iVar3 < 0) {
    if (param_2 == 0) {
      return iVar3;
    }
    *param_1 = L'\0';
    return iVar3;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  iVar3 = 0;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      pwVar4 = param_1;
      uVar2 = param_2;
      if (*param_6 == L'\0') goto LAB_140001452;
      iVar3 = (-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d;
      local_58 = param_1;
      local_50[0] = param_2;
    }
    else {
      local_50[0] = 0;
      _Count = param_2 - 1;
      local_58 = param_1;
      iVar1 = _vsnwprintf(param_1,_Count,param_6,&param_7);
      if (iVar1 < 0) {
LAB_1400014c1:
        iVar3 = -0x7ffffffb;
LAB_1400014c6:
        param_1[_Count] = L'\0';
      }
      else {
        uVar2 = (ulonglong)iVar1;
        if (_Count < uVar2) goto LAB_1400014c1;
        if (uVar2 == _Count) goto LAB_1400014c6;
        _Count = uVar2;
      }
      uVar2 = param_2 - _Count;
      pwVar4 = param_1 + _Count;
      local_58 = pwVar4;
      local_50[0] = uVar2;
      if (-1 < iVar3) {
        if ((((param_5 >> 9 & 1) != 0) && (1 < uVar2)) && (2 < uVar2 * 2)) {
          memset(pwVar4 + 1,param_5 & 0xff,uVar2 * 2 - 2);
        }
        goto LAB_140001452;
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
    local_58 = param_1;
    local_50[0] = param_2;
    if (param_2 != 0) {
      *param_1 = L'\0';
      local_58 = param_1;
      local_50[0] = param_2;
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    RtlStringExHandleOtherFlagsW(param_1,param_2 * 2,0,&local_58,local_50,param_5);
  }
  pwVar4 = local_58;
  uVar2 = local_50[0];
  if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) {
    return iVar3;
  }
LAB_140001452:
  if (param_3 != (longlong *)0x0) {
    *param_3 = (longlong)pwVar4;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar2;
  }
  return iVar3;
}



===== RtlStringExHandleOtherFlagsW @ 140001540 =====

undefined8
RtlStringExHandleOtherFlagsW
          (undefined2 *param_1,ulonglong param_2,longlong param_3,undefined8 *param_4,
          ulonglong *param_5,uint param_6)

{
  ulonglong uVar1;
  
  uVar1 = param_2 >> 1;
  if ((uVar1 != 0) && ((param_6 & 0x1000) != 0)) {
    *param_4 = param_1 + param_3;
    *param_5 = uVar1 - param_3;
    param_1[param_3] = 0;
  }
  if ((param_6 & 0x400) != 0) {
    memset(param_1,param_6 & 0xff,param_2);
    if ((char)param_6 != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *param_5 = 1;
      *param_4 = param_1 + (uVar1 - 1);
      param_1[uVar1 - 1] = 0;
      goto LAB_1400015b8;
    }
    *param_4 = param_1;
    *param_5 = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_1400015b8:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  return 0;
}



===== ScsiTapeNtStatusToTapeStatus @ 14000160c =====

ulonglong ScsiTapeNtStatusToTapeStatus(int param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0xc0000013;
  if (param_1 < -0x3fffffec) {
    if (param_1 != -0x3fffffed) {
      uVar1 = 0x8000001f;
      if (param_1 < -0x7fffffe0) {
        if (param_1 == -0x7fffffe1) {
          *param_2 = 0xc;
        }
        else if (param_1 == -0x7ffffffb) {
          *param_2 = 0xe;
        }
        else if (param_1 == -0x7fffffef) {
          *param_2 = 0x1c;
        }
        else {
          if (param_1 != -0x7fffffea) {
            if (param_1 == -0x7fffffe5) {
              *param_2 = 0xb;
              goto LAB_140001823;
            }
            if (param_1 != -0x7fffffe4) {
              if (param_1 == -0x7fffffe3) {
                *param_2 = 9;
              }
              else {
                if (param_1 != -0x7fffffe2) goto LAB_1400017f1;
                *param_2 = 0xd;
              }
              goto LAB_140001823;
            }
          }
          *param_2 = 8;
        }
      }
      else if (param_1 == -0x7fffffdf) {
        *param_2 = 10;
      }
      else if (param_1 == -0x7fffffde) {
        *param_2 = 0xf;
      }
      else if (param_1 == -0x7fffffd9) {
        *param_2 = 0x1e;
      }
      else if (param_1 == -0x3ffffffe) {
        *param_2 = 5;
      }
      else if (param_1 == -0x3ffffff3) {
        *param_2 = 7;
      }
      else if (param_1 == -0x3ffffff2) {
        *param_2 = 0x17;
      }
      else {
        if (param_1 != -0x3ffffff0) goto LAB_1400017f1;
        *param_2 = 6;
      }
      goto LAB_140001823;
    }
LAB_140001805:
    *param_2 = 0x11;
  }
  else {
    uVar1 = 0xc00000a3;
    if (param_1 < -0x3fffff5c) {
      if (param_1 == -0x3fffff5d) {
        *param_2 = 0x14;
        goto LAB_140001823;
      }
      if (param_1 == -0x3fffffec) {
        *param_2 = 0x13;
        goto LAB_140001823;
      }
      if (param_1 != -0x3fffffeb) {
        if (param_1 == -0x3fffffc4) {
          *param_2 = 0x1b;
        }
        else if (param_1 == -0x3fffff66) {
          *param_2 = 4;
        }
        else if (param_1 == -0x3fffff64) {
          *param_2 = 0x16;
        }
        else if (param_1 == -0x3fffff63) {
          *param_2 = 0x1a;
        }
        else {
          if (param_1 != -0x3fffff5e) goto LAB_1400017f1;
          *param_2 = 0x15;
        }
        goto LAB_140001823;
      }
    }
    else {
      if (param_1 == -0x3fffff4b) {
        *param_2 = 0x19;
        goto LAB_140001823;
      }
      if (param_1 == -0x3ffffe8d) {
        *param_2 = 0x18;
        goto LAB_140001823;
      }
      if (param_1 == -0x3ffffe89) {
        *param_2 = 0x10;
        goto LAB_140001823;
      }
      if (param_1 == -0x3ffffe88) goto LAB_140001805;
      if (param_1 != -0x3ffffe7b) {
        if (param_1 != 0) {
LAB_1400017f1:
          return uVar1 & 0xffffffffffffff00;
        }
        *param_2 = 3;
        goto LAB_140001823;
      }
    }
    *param_2 = 0x12;
  }
LAB_140001823:
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== ScsiTapeTapeStatusToNtStatus @ 140001830 =====

undefined1 ScsiTapeTapeStatusToNtStatus(int param_1,undefined4 *param_2)

{
  if (param_1 < 0x12) {
    if (param_1 == 0x11) {
      *param_2 = 0xc0000178;
    }
    else if (param_1 < 0xb) {
      if (param_1 == 10) {
        *param_2 = 0x80000021;
      }
      else if (param_1 == 3) {
        *param_2 = 0;
      }
      else if (param_1 == 4) {
        *param_2 = 0xc000009a;
      }
      else if (param_1 == 5) {
        *param_2 = 0xc0000002;
      }
      else if (param_1 == 6) {
        *param_2 = 0xc0000010;
      }
      else if (param_1 == 7) {
        *param_2 = 0xc000000d;
      }
      else if (param_1 == 8) {
        *param_2 = 0x80000016;
      }
      else {
        if (param_1 != 9) {
          return 0;
        }
        *param_2 = 0x8000001d;
      }
    }
    else if (param_1 == 0xb) {
      *param_2 = 0x8000001b;
    }
    else if (param_1 == 0xc) {
      *param_2 = 0x8000001f;
    }
    else if (param_1 == 0xd) {
      *param_2 = 0x8000001e;
    }
    else if (param_1 == 0xe) {
      *param_2 = 0x80000005;
    }
    else if (param_1 == 0xf) {
      *param_2 = 0x80000022;
    }
    else {
      if (param_1 != 0x10) {
        return 0;
      }
      *param_2 = 0xc0000177;
    }
  }
  else if (param_1 < 0x19) {
    if (param_1 == 0x18) {
      *param_2 = 0xc0000173;
    }
    else if (param_1 == 0x12) {
      *param_2 = 0xc0000185;
    }
    else if (param_1 == 0x13) {
      *param_2 = 0xc0000014;
    }
    else if (param_1 == 0x14) {
      *param_2 = 0xc00000a3;
    }
    else if (param_1 == 0x15) {
      *param_2 = 0xc00000a2;
    }
    else if (param_1 == 0x16) {
      *param_2 = 0xc000009c;
    }
    else {
      if (param_1 != 0x17) {
        return 0;
      }
      *param_2 = 0xc000000e;
    }
  }
  else if (param_1 == 0x19) {
    *param_2 = 0xc00000b5;
  }
  else if (param_1 == 0x1a) {
    *param_2 = 0xc000009d;
  }
  else if (param_1 == 0x1b) {
    *param_2 = 0xc000003c;
  }
  else if (param_1 == 0x1c) {
    *param_2 = 0x80000011;
  }
  else if (param_1 == 0x1d) {
    *param_2 = 0x80000288;
  }
  else {
    if (param_1 != 0x1e) {
      return 0;
    }
    *param_2 = 0x80000027;
  }
  return 1;
}



===== TapeClassQuerySetAutoRunValue @ 1400019ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TapeClassQuerySetAutoRunValue(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_res8;
  undefined4 local_res10 [2];
  undefined4 local_d8 [2];
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  
  local_d8[0] = 0;
  local_ac = 0;
  local_94 = 0;
  local_res8 = 0;
  local_res10[0] = 0;
  local_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0x30;
  local_90 = 0;
  uStack_88 = 0;
  local_98 = 0x240;
  local_a0 = param_1;
  iVar2 = ZwOpenKey(&local_res8,0x2001f,&local_b0);
  if (-1 < iVar2) {
    memset(local_78,0,0x70);
    uVar1 = local_res8;
    local_60 = local_res10;
    local_70 = 0x24;
    local_68 = L"AutoRun";
    local_d0 = 0;
    uStack_c8 = 0;
    RtlInitUnicodeString(&local_d0,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_d0);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(0x40000000,uVar1,local_78,0,0);
    if (iVar2 == -0x3fffffcc) {
      RtlInitUnicodeString(&local_c0,L"AutoRun");
      ZwSetValueKey(local_res8,&local_c0,0,4,local_d8,4);
    }
    ZwClose(local_res8);
  }
  return;
}



===== TapeDebugPrint @ 140001b50 =====

void TapeDebugPrint(void)

{
                    /* 0x1b50  10  TapeDebugPrint */
  return;
}



===== TapeDeviceControl @ 140001b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TapeDeviceControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  longlong lVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  code *pcVar14;
  uint uVar15;
  uint uVar16;
  undefined1 auStack_198 [32];
  int *local_178;
  undefined4 local_170;
  uint *local_168;
  undefined1 local_158;
  int local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  longlong local_140;
  undefined4 local_138;
  uint local_134;
  undefined4 local_130 [2];
  longlong local_128;
  uint local_120;
  undefined8 local_118;
  int *piStack_110;
  undefined1 local_108 [10];
  undefined1 local_fe;
  uint local_fc;
  uint local_f8;
  int local_f4;
  longlong local_f0;
  undefined1 local_c0 [24];
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_198;
  lVar11 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_14c = 0;
  piVar3 = *(int **)(lVar11 + 0x60);
  local_140 = lVar11;
  local_128 = param_1;
  memset(local_108,0,0x58);
  local_150 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  local_154 = 0;
  local_118 = 0;
  piStack_110 = (int *)0x0;
  local_148 = *(uint *)(lVar2 + 0x18);
  if (local_148 < 0x1fc001) {
    if (local_148 == 0x1fc000) {
      if (7 < *(uint *)(lVar2 + 0x10)) {
        pcVar14 = *(code **)(piVar3 + 0x10);
LAB_140001c87:
        local_154 = piVar3[0x36];
        goto LAB_140001e65;
      }
    }
    else if (local_148 == 0x1f4004) {
      if (7 < *(uint *)(lVar2 + 0x10)) {
        pcVar14 = *(code **)(piVar3 + 0x1a);
        goto LAB_140001c87;
      }
    }
    else if (local_148 == 0x1f400c) {
      if (0xf < *(uint *)(lVar2 + 8)) {
        pcVar14 = *(code **)(piVar3 + 0x16);
        *(undefined8 *)(param_2 + 0x38) = 0x10;
        goto LAB_140001e65;
      }
    }
    else if (local_148 == 0x1f4010) {
      if (0x17 < *(uint *)(lVar2 + 0x10)) {
        pcVar14 = *(code **)(piVar3 + 0x20);
        goto LAB_140001c87;
      }
    }
    else if (local_148 == 0x1f4014) {
      if (0x1f < *(uint *)(lVar2 + 8)) {
        pcVar14 = *(code **)(piVar3 + 0x12);
LAB_140001c5c:
        *(undefined8 *)(param_2 + 0x38) = 0x20;
        goto LAB_140001e65;
      }
    }
    else {
      if (local_148 != 0x1f401c) {
        if (local_148 == 0x1f4020) goto LAB_140001dcb;
        if (local_148 != 0x1f4024) goto LAB_140001d08;
        pcVar14 = *(code **)(piVar3 + 0x18);
        goto LAB_140001e65;
      }
      if (0x1f < *(uint *)(lVar2 + 8)) {
        pcVar14 = *(code **)(piVar3 + 0x14);
        goto LAB_140001c5c;
      }
    }
LAB_140001e17:
    uVar13 = 0xc0000004;
    uVar6 = 0xc0000004;
  }
  else {
    if (local_148 == 0x1fc008) {
      if (0xb < *(uint *)(lVar2 + 0x10)) {
        local_154 = piVar3[0x36];
        pcVar14 = *(code **)(piVar3 + 0x22);
LAB_140001e65:
        piVar10 = piStack_110;
        if (piVar3[0xc] == 0) {
          lVar11 = 0;
LAB_140001e97:
          local_a8 = &local_118;
          if (local_148 != 0x2d1100) {
            local_a8 = *(undefined8 **)(param_2 + 0x18);
          }
          uVar12 = 3;
          local_148 = 0;
          do {
            local_f4 = *(int *)(local_140 + 0x248);
            local_fc = 0;
            local_150 = 0;
            local_168 = &local_150;
            local_178 = (int *)CONCAT44(local_178._4_4_,local_148);
            local_170 = uVar12;
            iVar7 = (*pcVar14)(piVar3 + 0x3a,lVar11,local_a8,local_108);
            if (local_f4 == 0) {
              local_f4 = *(int *)(local_140 + 0x248);
            }
            local_f4 = local_f4 + local_154;
            local_138 = 3;
            local_130[0] = 3;
            local_134 = local_150 & 0xffff;
            if (iVar7 == 2) {
              TapeClassZeroMemory(local_c0,0xc);
              local_f8 = 0;
              local_fe = 6;
              local_c0[0] = 0;
LAB_140001f61:
              if (local_f0 == 0) {
LAB_140001f8c:
                local_158 = 0;
              }
              else {
                if (local_f8 == 0) {
                  ScsiTapeFreeSrbBuffer((longlong)local_108);
                }
                if ((local_f0 == 0) || ((local_fc & 0x80) == 0)) goto LAB_140001f8c;
                local_158 = 1;
              }
              local_120 = local_f8;
              while( true ) {
                local_178 = (int *)CONCAT71(local_178._1_7_,local_158);
                uVar6 = ClassSendSrbSynchronous(local_128,local_108,local_f0,local_f8);
                local_14c = uVar6;
                if (((uVar6 + 0x80000000 & 0x80000000) != 0) || (uVar6 == 0xc000003c)) {
                  if (uVar6 != 0xc000003c) goto LAB_1400020eb;
                  if (local_f8 <= local_120) {
                    local_14c = 0;
                    goto LAB_1400020eb;
                  }
                }
                if ((uVar6 == 0x8000001d) || (uVar6 == 0xc00000b5)) {
                  iVar7 = GetTimeoutDeltaFromRegistry(*(undefined8 *)(local_140 + 0x200));
                  piVar3[0x36] = iVar7;
                  if (iVar7 == 0) {
                    local_154 = *(int *)(local_140 + 0x248);
                    piVar3[0x36] = local_154;
                    local_f4 = local_f4 + local_154;
                  }
                }
                if (local_134 == 0) break;
                local_134 = local_134 - 1;
              }
              if ((local_150 & 0x20000) == 0) {
                if ((local_150 & 0x10000) == 0) {
                  if (lVar11 != 0) {
                    ExFreePoolWithTag(lVar11,0);
                  }
                  ScsiTapeFreeSrbBuffer((longlong)local_108);
                  if (piVar10 != (int *)0x0) {
                    ExFreePoolWithTag(piVar10,0);
                  }
                  *(undefined8 *)(param_2 + 0x38) = 0;
                  *(uint *)(param_2 + 0x30) = uVar6;
                  ClassReleaseRemoveLock(local_128,param_2);
                  ClassCompleteRequest(local_128,param_2,0);
                  return (ulonglong)uVar6;
                }
LAB_1400020eb:
                uVar12 = local_138;
              }
              else {
                ScsiTapeNtStatusToTapeStatus(uVar6,local_130);
                uVar12 = local_130[0];
              }
            }
            else {
              uVar12 = 1;
              if (iVar7 != 1) {
                if (iVar7 == 0) goto LAB_140001f61;
                ScsiTapeFreeSrbBuffer((longlong)local_108);
                if (lVar11 != 0) {
                  ExFreePoolWithTag(lVar11,0);
                }
                cVar4 = ScsiTapeTapeStatusToNtStatus(iVar7,&local_14c);
                uVar6 = local_14c;
                if (cVar4 == '\0') {
                  uVar6 = 0xc0000185;
                }
                if ((int)uVar6 < 0) {
                  *(undefined8 *)(param_2 + 0x38) = 0;
                  if (piVar10 != (int *)0x0) {
LAB_140002372:
                    ExFreePoolWithTag(piVar10,0);
                  }
                  goto LAB_140002383;
                }
                iVar7 = *(int *)(lVar2 + 0x18);
                if (iVar7 == 0x1f4014) {
                  lVar11 = *(longlong *)(param_2 + 0x18);
                  uVar5 = *(uint *)(*(longlong *)(local_140 + 0x210) + 8);
                  uVar8 = *(int *)(*(longlong *)(local_140 + 0x210) + 0xc) * 0x1000 - 0x1000;
                  if (uVar8 <= uVar5) {
                    uVar5 = uVar8;
                  }
                  uVar8 = *(uint *)(lVar11 + 8);
                  if (uVar5 < *(uint *)(lVar11 + 8)) {
                    *(uint *)(lVar11 + 8) = uVar5;
                    uVar8 = uVar5;
                  }
                  uVar5 = *(uint *)(lVar11 + 4);
                  if (uVar8 < *(uint *)(lVar11 + 4)) {
                    *(uint *)(lVar11 + 4) = uVar8;
                    uVar5 = uVar8;
                  }
                  uVar1 = *(uint *)(lVar11 + 0xc);
                  if (((uVar5 & uVar5 - 1) != 0) && (iVar7 = 0, uVar15 = uVar5, uVar5 != 0)) {
                    do {
                      iVar9 = iVar7;
                      iVar7 = iVar9 + 1;
                      uVar15 = uVar15 >> 1;
                    } while (uVar15 != 0);
                    if (iVar7 != 0) {
                      *(int *)(lVar11 + 4) = 1 << ((byte)iVar9 & 0x1f);
                    }
                  }
                  if (((uVar8 & uVar8 - 1) != 0) && (iVar7 = 0, uVar15 = uVar8, uVar8 != 0)) {
                    do {
                      iVar9 = iVar7;
                      iVar7 = iVar9 + 1;
                      uVar15 = uVar15 >> 1;
                    } while (uVar15 != 0);
                    if (iVar7 != 0) {
                      *(int *)(lVar11 + 8) = 1 << ((byte)iVar9 & 0x1f);
                    }
                  }
                  uVar15 = uVar1;
                  if ((uVar1 & uVar1 - 1) != 0) {
                    iVar7 = 0;
                    for (uVar16 = uVar1; uVar16 != 0; uVar16 = uVar16 >> 1) {
                      iVar7 = iVar7 + 1;
                    }
                    if (iVar7 != 0) {
                      uVar15 = 1 << ((byte)iVar7 & 0x1f);
                      *(uint *)(lVar11 + 0xc) = uVar15;
                    }
                  }
                  if (*(uint *)(lVar11 + 8) < uVar15) {
                    *(uint *)(lVar11 + 0xc) = uVar1;
                    *(uint *)(lVar11 + 8) = uVar8;
                    *(uint *)(lVar11 + 4) = uVar5;
                  }
LAB_140002383:
                  *(uint *)(param_2 + 0x30) = uVar6;
                  ClassReleaseRemoveLock(local_128,param_2);
                  ClassCompleteRequest(local_128,param_2,2);
                  return (ulonglong)uVar6;
                }
                if (iVar7 == 0x1f401c) {
                  if (*(int *)(local_140 + 0x23c) == -1) {
                    *(undefined4 *)(local_140 + 0x23c) =
                         *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x10);
                  }
                  goto LAB_140002383;
                }
                if (iVar7 != 0x1f4020) {
                  if (iVar7 == 0x1fc000) {
                    local_78 = 0xffffffff;
                    local_98 = 0x2b0001;
                    local_94 = 0x852d11eb;
                    uStack_90 = 0x45074bb8;
                    uStack_8c = 0x7c419b9d;
                    uStack_88 = 0x38b4b1c2;
                    local_80 = 0;
                    local_74 = 0;
                    IoReportTargetDeviceChangeAsynchronous
                              (*(undefined8 *)(local_140 + 0x200),&local_98,0,0);
                    goto LAB_140002383;
                  }
                  if (iVar7 != 0x1fc020) {
                    if (iVar7 == 0x2d0c04) {
                      *(undefined8 *)(param_2 + 0x38) = 0x28;
                      *(ulonglong *)(param_2 + 0x38) =
                           (ulonglong)(*(int *)(*(longlong *)(param_2 + 0x18) + 4) - 1) * 0x20 +
                           0x28;
                    }
                    else if (iVar7 == 0x2d1100) {
                      local_a8 = (undefined8 *)0x4080fa66bc4dd36c;
                      local_a0 = 0x590ca087;
                      local_9c = 0x8778eb22;
                      **(undefined4 **)(param_2 + 0x18) = 0;
                      if (*piVar10 != 0) {
                        local_178 = piVar10;
                        ClassWmiFireEvent(local_128,&local_a8,0,0x204);
                      }
                      *(undefined8 *)(param_2 + 0x38) = 0x204;
                      goto LAB_140002372;
                    }
                    goto LAB_140002383;
                  }
                }
                *(undefined4 *)(local_140 + 0x23c) = **(undefined4 **)(param_2 + 0x18);
                goto LAB_140002383;
              }
            }
            local_148 = local_148 + 1;
          } while( true );
        }
        lVar11 = ExAllocatePool2(0x40,piVar3[0xc],0x65706154);
        if (lVar11 != 0) goto LAB_140001e97;
        uVar13 = 0xc000009a;
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        goto LAB_140001e21;
      }
      goto LAB_140001e17;
    }
    if (local_148 == 0x1fc018) {
      if (7 < *(uint *)(lVar2 + 0x10)) {
        pcVar14 = *(code **)(piVar3 + 0x1c);
        goto LAB_140001e65;
      }
      goto LAB_140001e17;
    }
    if (local_148 == 0x1fc020) {
LAB_140001dcb:
      if (3 < *(uint *)(lVar2 + 0x10)) {
        uVar6 = *(uint *)(*(longlong *)(lVar11 + 0x210) + 8);
        uVar5 = *(int *)(*(longlong *)(lVar11 + 0x210) + 0xc) * 0x1000 - 0x1000;
        if (uVar5 <= uVar6) {
          uVar6 = uVar5;
        }
        if (**(uint **)(param_2 + 0x18) <= uVar6) {
          pcVar14 = *(code **)(piVar3 + 0x1e);
          goto LAB_140001e65;
        }
        uVar6 = 0xc000000d;
        goto LAB_140001d2a;
      }
      goto LAB_140001e17;
    }
    if (local_148 == 0x1fc028) {
      if (0xb < *(uint *)(lVar2 + 0x10)) {
        pcVar14 = *(code **)(piVar3 + 0xe);
        goto LAB_140001c87;
      }
      goto LAB_140001e17;
    }
    if (local_148 == 0x2d0c04) {
      if (*piVar3 == 0xb8) {
        if ((ulonglong)(piVar3[0x28] * 0x20 - 0x20) + 0x28 <= (ulonglong)*(uint *)(lVar2 + 8)) {
          pcVar14 = *(code **)(piVar3 + 0x26);
          goto LAB_140001e65;
        }
        goto LAB_140001e17;
      }
      uVar6 = 0xc0000002;
    }
    else {
      if (local_148 != 0x2d1100) {
LAB_140001d08:
        uVar13 = ClassDeviceControl(param_1,param_2);
        return uVar13;
      }
      if (*(uint *)(lVar2 + 8) < 0x204) {
        uVar6 = 0xc0000023;
      }
      else {
        pcVar14 = *(code **)(piVar3 + 0x2a);
        if (pcVar14 == (code *)0x0) {
          uVar6 = 0xc00002dd;
        }
        else {
          piVar10 = (int *)ExAllocatePool2(0x40,0x204,0x65706154);
          if (piVar10 != (int *)0x0) {
            *piVar10 = 0;
            local_118 = 0x20400000002;
            piStack_110 = piVar10;
            goto LAB_140001e65;
          }
          uVar6 = 0xc0000017;
        }
      }
    }
LAB_140001d2a:
    uVar13 = (ulonglong)uVar6;
  }
  *(uint *)(param_2 + 0x30) = uVar6;
LAB_140001e21:
  *(undefined8 *)(param_2 + 0x38) = 0;
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return uVar13;
}



===== TapeError @ 1400023f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TapeError(longlong param_1,longlong param_2,uint *param_3,undefined1 *param_4)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined1 auStack_d8 [32];
  int local_b8;
  int local_b4 [3];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_b8 = 0;
  pcVar4 = *(char **)(param_2 + 0x20);
  lVar5 = *(longlong *)(lVar3 + 0x60);
  lVar6 = *(longlong *)(param_2 + 0x30);
  *param_4 = 0;
  local_b4[0] = 0;
  if (-1 < *(char *)(param_2 + 3)) goto LAB_1400025dc;
  bVar1 = pcVar4[2];
  bVar8 = bVar1 & 0xf;
  if ((bVar1 & 0xf) == 0) {
    if ((char)bVar1 < '\0') {
LAB_1400024dd:
      if ((pcVar4[0xd] == '\x01') || (uVar9 = 0x80000021, pcVar4[0xd] != '\x03')) {
        uVar9 = 0x8000001b;
      }
    }
    else {
      if ((bVar1 & 0x40) == 0) {
        if ((((bVar1 & 0x20) != 0) && (*(int *)(lVar3 + 0x23c) == 0)) &&
           (*(char *)(param_2 + 0x48) == '\b')) {
          local_b8 = CONCAT31(CONCAT21(CONCAT11(pcVar4[3],pcVar4[4]),pcVar4[5]),pcVar4[6]);
          uVar9 = 0x80000005;
          if (-1 < pcVar4[3]) {
            uVar9 = 0;
          }
          goto LAB_140002553;
        }
        goto LAB_140002555;
      }
LAB_1400024fd:
      uVar9 = 0x8000001f - (pcVar4[0xd] != '\x04');
    }
LAB_140002553:
    *param_3 = uVar9;
  }
  else if (bVar8 == 1) {
    if ((char)bVar1 < '\0') goto LAB_1400024dd;
    if ((bVar1 & 0x40) != 0) goto LAB_1400024fd;
  }
  else if (bVar8 == 2) {
    if (pcVar4[0xc] == '\x04') {
      cVar2 = pcVar4[0xd];
      if (cVar2 != '\x02') {
        if (cVar2 == '\x03') goto LAB_1400024b1;
        if (cVar2 == '\x04') goto LAB_140002555;
      }
      *param_4 = 1;
    }
    else if (pcVar4[0xc] == ':') {
LAB_1400024b1:
      *param_3 = 0xc0000178;
    }
  }
  else {
    if (bVar8 == 6) {
      uVar9 = (pcVar4[0xc] != '(') + 0x8000001c;
      goto LAB_140002553;
    }
    if (bVar8 == 8) {
      *param_3 = 0x80000022;
    }
    else if (bVar8 == 0xd) {
      *param_3 = 0xc0000177;
    }
  }
LAB_140002555:
  if ((((*param_3 & 0xc0000000) == 0x80000000) || (-1 < (int)*param_3)) &&
     ((*(char *)(param_2 + 0x48) - 8U & 0xfd) == 0)) {
    if (*pcVar4 < '\0') {
      local_b8 = CONCAT31(CONCAT21(CONCAT11(pcVar4[3],pcVar4[4]),pcVar4[5]),pcVar4[6]);
      iVar11 = local_b8;
    }
    else {
      iVar11 = 0;
    }
    uVar9 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),*(undefined1 *)(param_2 + 0x4b))
                           ,*(undefined1 *)(param_2 + 0x4c));
    uVar10 = uVar9 - iVar11;
    if ((int)uVar10 < 0) {
      uVar10 = 0;
      *param_3 = 0xc0000185;
    }
    iVar11 = *(int *)(lVar3 + 0x23c);
    if (iVar11 != 0) {
      uVar9 = uVar9 * iVar11;
      uVar10 = uVar10 * iVar11;
    }
    if ((int)uVar10 <= (int)uVar9) {
      uVar9 = uVar10;
    }
    *(longlong *)(lVar6 + 0x38) = (longlong)(int)uVar9;
  }
LAB_1400025dc:
  if (*(longlong *)(lVar5 + 0x28) != 0) {
    uVar7 = ScsiTapeNtStatusToTapeStatus(*param_3,local_b4);
    iVar11 = local_b4[0];
    if ((char)uVar7 != '\0') {
      (**(code **)(lVar5 + 0x28))(lVar5 + 0xe8,param_2,local_b4);
      if (local_b4[0] != iVar11) {
        ScsiTapeTapeStatusToNtStatus(local_b4[0],param_3);
      }
    }
  }
  lVar6 = _DAT_fffff78000000014;
  if ((*param_3 == 0x80000288) &&
     (*(longlong *)(lVar5 + 0xc0) + 36000000000 < _DAT_fffff78000000014)) {
    local_88 = 0xffffffff;
    local_a8 = 0x2b0001;
    local_a4 = 0x7207877c;
    uStack_a0 = 0x44e590ed;
    uStack_9c = 0x428100a0;
    uStack_98 = 0xbb794c8d;
    local_90 = 0;
    local_84 = 0;
    IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(lVar3 + 0x200),&local_a8,0,0);
    *(longlong *)(lVar5 + 0xc0) = lVar6;
  }
  return;
}



===== TapeIoCompleteAssociated @ 1400026c0 =====

undefined8 TapeIoCompleteAssociated(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  uint local_res8 [4];
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  pcVar5 = *(char **)(param_2 + 0xb8);
  lVar6 = *(longlong *)(param_2 + 0x18);
  lVar7 = *(longlong *)(lVar4 + 0x60);
  local_res8[0] = 0;
  if ((*(byte *)(param_3 + 3) & 0x3f) != 1) {
    if ((*(byte *)(param_3 + 3) & 0x40) != 0) {
      ClassReleaseQueue(param_1);
    }
    if (*pcVar5 == '\x0e') {
      uVar8 = *(undefined4 *)(pcVar5 + 0x18);
    }
    else {
      uVar8 = 0;
    }
    ClassInterpretSenseInfo(param_1,param_3,*pcVar5,uVar8,4 - *(int *)(pcVar5 + 0x20),local_res8,0);
    if ((*(uint *)(lVar6 + 0x30) < local_res8[0]) && ((*(byte *)(param_3 + 3) & 0x3f) != 0x16)) {
      *(uint *)(lVar6 + 0x30) = local_res8[0];
    }
  }
  ExInterlockedAddUlong(lVar6 + 0x38,*(undefined4 *)(param_2 + 0x38),lVar7 + 0xb8);
  ExFreeToNPagedLookasideList(lVar4 + 0x100,param_3);
  uVar3 = *(uint *)(lVar6 + 0x30);
  lVar4 = *(longlong *)(lVar6 + 0xb8);
  if (((uVar3 & 0xc0000000) == 0xc0000000) &&
     ((((*(undefined8 *)(lVar6 + 0x38) = 0, uVar3 + 0x3fffff5e < 2 || (uVar3 == 0xc00000b5)) ||
       (uVar3 + 0x3fffffee < 3)) || (uVar3 == 0x80000016)))) {
    IoSetHardErrorOrVerifyDevice(lVar6,param_1);
  }
  LOCK();
  piVar1 = (int *)(lVar4 + -0x40);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ClassReleaseRemoveLock(param_1,lVar6);
    ClassCompleteRequest(param_1,lVar6,1);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== TapeReadWrite @ 140002860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TapeReadWrite(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  byte bVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0x60);
  puVar6 = (undefined4 *)ExAllocateFromNPagedLookasideList(lVar1 + 0x100);
  if (puVar6 == (undefined4 *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    puVar6[3] = 0;
    pcVar3 = *(char **)(param_2 + 0xb8);
    uVar5 = 0x40;
    if (*pcVar3 != '\x03') {
      uVar5 = 0x80;
    }
    puVar6[3] = uVar5;
    *puVar6 = 0x58;
    *(undefined1 *)(puVar6 + 1) = 0;
    *(undefined1 *)((longlong)puVar6 + 9) = 0x20;
    puVar6[3] = uVar5 | *(uint *)(lVar1 + 0x250);
    puVar6[4] = *(undefined4 *)(pcVar3 + 8);
    puVar6[5] = *(undefined4 *)(lVar1 + 0x248);
    *(ulonglong *)(puVar6 + 6) =
         (ulonglong)*(uint *)(*(longlong *)(param_2 + 8) + 0x2c) +
         *(longlong *)(*(longlong *)(param_2 + 8) + 0x20);
    uVar7 = *(undefined8 *)(lVar1 + 0x240);
    *(undefined8 *)(puVar6 + 10) = 0;
    *(undefined8 *)(puVar6 + 0xe) = 0;
    puVar6[0x10] = 0;
    *(undefined8 *)(puVar6 + 8) = uVar7;
    *(undefined2 *)((longlong)puVar6 + 10) = 0x1206;
    *(longlong *)(puVar6 + 0xc) = param_2;
    *(undefined8 *)(puVar6 + 0x12) = 0;
    puVar6[0x14] = 0;
    uVar5 = *(uint *)(pcVar3 + 8);
    if (*(uint *)(lVar1 + 0x23c) == 0) {
      bVar8 = *(byte *)((longlong)puVar6 + 0x49) & 0xe0;
    }
    else {
      uVar5 = uVar5 / *(uint *)(lVar1 + 0x23c);
      bVar8 = *(byte *)((longlong)puVar6 + 0x49) & 0xe1 | 1;
    }
    *(byte *)((longlong)puVar6 + 0x49) = bVar8;
    *(char *)((longlong)puVar6 + 0x4a) = (char)(uVar5 >> 0x10);
    *(char *)(puVar6 + 0x13) = (char)uVar5;
    *(char *)((longlong)puVar6 + 0x4b) = (char)(uVar5 >> 8);
    *(byte *)(puVar6 + 0x12) = ~(byte)((uint)puVar6[3] >> 5) & 2 | 8;
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 **)(lVar1 + -0x40) = puVar6;
    pcVar4 = ClassIoComplete_exref;
    pcVar3[0x20] = '\x04';
    pcVar3[0x21] = '\0';
    pcVar3[0x22] = '\0';
    pcVar3[0x23] = '\0';
    pcVar3[0x24] = '\0';
    pcVar3[0x25] = '\0';
    pcVar3[0x26] = '\0';
    pcVar3[0x27] = '\0';
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar1 + -0x10) = pcVar4;
    *(undefined4 **)(lVar1 + -8) = puVar6;
    *(undefined1 *)(lVar1 + -0x45) = 0xc0;
    pcVar4 = *(code **)(lVar2 + 0x90);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(lVar2 + 0xe8,0,0,puVar6,0,0,0);
    }
    uVar7 = 0;
  }
  return uVar7;
}



===== TapeReadWriteVerification @ 140002a00 =====

undefined8 TapeReadWriteVerification(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x18);
  uVar2 = *(uint *)(lVar4 + 0x23c);
  lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x210);
  uVar7 = *(uint *)(lVar4 + 8);
  uVar5 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar5 == 0) {
    uVar6 = 0;
  }
  else if ((uVar2 == 0xffffffff) || ((uVar2 != 0 && (uVar5 % uVar2 != 0)))) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar6 = 0xc000000d;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  }
  else {
    if ((uVar7 < uVar5) ||
       (*(uint *)(lVar4 + 0xc) <
        (uint)((ulonglong)
               (*(int *)(*(longlong *)(param_2 + 8) + 0x2c) +
                *(int *)(*(longlong *)(param_2 + 8) + 0x20) & 0xfff) + (ulonglong)uVar5 + 0xfff >>
              0xc))) {
      uVar5 = (*(int *)(lVar4 + 0xc) + -1) * 0x1000;
      if (uVar5 < uVar7) {
        uVar7 = uVar5;
      }
      if (uVar7 == 0) {
        uVar7 = 0x1000;
      }
      if ((uVar2 != 0) && (uVar7 % uVar2 != 0)) {
        uVar7 = uVar7 - uVar7 % uVar2;
      }
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      SplitTapeRequest(param_1,param_2,uVar7);
    }
    else {
      uVar6 = TapeReadWrite(param_1,param_2);
      *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
           *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
      if ((int)uVar6 == 0) {
        IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_2);
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        ClassReleaseRemoveLock(param_1);
        ClassCompleteRequest(param_1,param_2,0);
      }
    }
    uVar6 = 0x103;
  }
  return uVar6;
}



===== TapeClassNotification @ 140002b80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TapeClassNotification(int param_1,undefined8 param_2,undefined8 *param_3)

{
                    /* 0x2b80  7  TapeClassNotification */
  if (param_1 == 0xc) {
    *param_3 = _DAT_fffff78000000320;
  }
  else if (param_1 == 0xd) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf7,0,0,0,0);
  }
  return;
}



===== _guard_check_icall @ 140002bf0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002c08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002c2c =====

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



===== wcscmp @ 140002c96 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140002c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 140002cb0 =====

/* WARNING: Removing unreachable block (ram,0x000140002d1a) */
/* WARNING: Removing unreachable block (ram,0x000140002cc9) */
/* WARNING: Removing unreachable block (ram,0x000140002cba) */

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



===== __security_check_cookie @ 140002d80 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002dc0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002df0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002e20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140002e80 =====

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



===== memset @ 140003180 =====

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



===== __memset_repmovs @ 1400032c0 =====

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



===== __memset_query @ 140003340 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400033c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003500 =====

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



===== __memset_spec_plain @ 140003580 =====

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



===== CreateTapeDeviceObject @ 140009008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140009207) */

int CreateTapeDeviceObject(undefined8 param_1,undefined8 param_2,undefined8 *param_3,char param_4)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  char *pcVar9;
  longlong lVar10;
  char *pcVar11;
  longlong lVar12;
  char *pcVar13;
  uint uVar14;
  undefined1 auStackY_e8 [32];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(local_88,0,0x40);
  lVar8 = IoGetAttachedDeviceReference(param_2);
  iVar7 = ClassClaimDevice(lVar8,0);
  if (iVar7 < 0) {
    ObfDereferenceObject(lVar8);
  }
  else {
    pcVar13 = "\\Tape%u";
    uVar6 = 0;
    if (param_4 == '\0') {
      pcVar13 = "\\TapeDrive%u";
    }
    do {
      uVar14 = uVar6;
      lVar12 = 0x40;
      pcVar11 = local_88;
      do {
        if ((lVar12 == 0x39) || (pcVar11[(longlong)"\\Device" - (longlong)local_88] == '\0')) break;
        *pcVar11 = pcVar11[(longlong)"\\Device" - (longlong)local_88];
        pcVar11 = pcVar11 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      pcVar9 = pcVar11 + -1;
      if (lVar12 != 0) {
        pcVar9 = pcVar11;
      }
      *pcVar9 = '\0';
      lVar12 = -1;
      do {
        lVar10 = lVar12;
        lVar12 = lVar10 + 1;
      } while (local_88[lVar10 + 1] != '\0');
      RtlStringCchPrintfExA
                (local_88 + lVar10 + 1,0x40 - (lVar10 + 1),(undefined8 *)0x0,(ulonglong *)0x0,0x600,
                 pcVar13,(char)uVar14);
      iVar7 = ClassCreateDeviceObject(param_1,local_88,param_2);
      lVar12 = lRam0000000000000040;
    } while ((iVar7 == -0x3fffffcb) && (uVar6 = uVar14 + 1, uVar14 + 1 < 0x7fffffff));
    if (-1 < iVar7) {
      uRam0000000000000030 = uRam0000000000000030 | 0x10;
      *(undefined4 *)(lRam0000000000000040 + 600) = 0;
      *(undefined8 *)(lVar12 + 8) = 0;
      *(longlong *)(lVar12 + 0x18) = lVar12;
      *(undefined4 *)(lVar12 + 0x24c) = 0x7fffffff;
      if (uRam0000000000000098 < *(uint *)(lVar8 + 0x98)) {
        uRam0000000000000098 = *(uint *)(lVar8 + 0x98);
      }
      *(undefined8 *)(lVar12 + 0x210) = 0;
      *(undefined8 *)(lVar12 + 0x208) = 0;
      *(undefined8 *)(lVar12 + 0x200) = param_2;
      lVar10 = IoAttachDeviceToDeviceStack(0,param_2);
      *(longlong *)(lVar12 + 0x10) = lVar10;
      if (lVar10 != 0) {
        uVar5 = param_3[1];
        puVar1 = *(undefined8 **)(lVar12 + 0x60);
        *puVar1 = *param_3;
        puVar1[1] = uVar5;
        uVar5 = param_3[3];
        puVar1[2] = param_3[2];
        puVar1[3] = uVar5;
        uVar5 = param_3[5];
        puVar1[4] = param_3[4];
        puVar1[5] = uVar5;
        uVar5 = param_3[7];
        puVar1[6] = param_3[6];
        puVar1[7] = uVar5;
        uVar5 = param_3[9];
        puVar1[8] = param_3[8];
        puVar1[9] = uVar5;
        uVar5 = param_3[0xb];
        puVar1[10] = param_3[10];
        puVar1[0xb] = uVar5;
        uVar5 = param_3[0xd];
        puVar1[0xc] = param_3[0xc];
        puVar1[0xd] = uVar5;
        uVar5 = param_3[0xf];
        puVar1[0xe] = param_3[0xe];
        puVar1[0xf] = uVar5;
        uVar5 = param_3[0x11];
        puVar1[0x10] = param_3[0x10];
        puVar1[0x11] = uVar5;
        uVar2 = *(undefined4 *)((longlong)param_3 + 0x94);
        uVar3 = *(undefined4 *)(param_3 + 0x13);
        uVar4 = *(undefined4 *)((longlong)param_3 + 0x9c);
        *(undefined4 *)(puVar1 + 0x12) = *(undefined4 *)(param_3 + 0x12);
        *(undefined4 *)((longlong)puVar1 + 0x94) = uVar2;
        *(undefined4 *)(puVar1 + 0x13) = uVar3;
        *(undefined4 *)((longlong)puVar1 + 0x9c) = uVar4;
        uVar2 = *(undefined4 *)((longlong)param_3 + 0xa4);
        uVar3 = *(undefined4 *)(param_3 + 0x15);
        uVar4 = *(undefined4 *)((longlong)param_3 + 0xac);
        *(undefined4 *)(puVar1 + 0x14) = *(undefined4 *)(param_3 + 0x14);
        *(undefined4 *)((longlong)puVar1 + 0xa4) = uVar2;
        *(undefined4 *)(puVar1 + 0x15) = uVar3;
        *(undefined4 *)((longlong)puVar1 + 0xac) = uVar4;
        puVar1[0x16] = param_3[0x16];
        lVar12 = *(longlong *)(lVar12 + 0x60);
        *(uint *)(lVar12 + 0xdc) = uVar14;
        KeInitializeSpinLock(lVar12 + 0xb8);
        uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
        ObfDereferenceObject(lVar8);
        return 0;
      }
      iVar7 = -0x3fffffff;
    }
    ObfDereferenceObject(lVar8);
  }
  return iVar7;
}



===== GetTimeoutDeltaFromRegistry @ 1400092f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GetTimeoutDeltaFromRegistry(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_res10 [2];
  undefined8 local_res18 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  iVar2 = IoOpenDeviceRegistryKey(param_1,1,1,local_res18);
  if (iVar2 < 0) {
    local_res10[0] = 0;
  }
  else {
    memset(local_78,0,0x70);
    uVar1 = local_res18[0];
    local_50 = 0;
    local_48 = 0;
    local_68 = L"SrbTimeoutDelta";
    local_60 = local_res10;
    local_70 = 0x20;
    local_58 = 4;
    local_88 = 0;
    uStack_80 = 0;
    RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_88);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(0x40000000,uVar1,local_78,0,0);
    if (iVar2 < 0) {
      local_res10[0] = 0;
    }
    ZwClose(local_res18[0]);
  }
  return local_res10[0];
}



===== ScsiTapeFreeSrbBuffer @ 1400093f4 =====

void ScsiTapeFreeSrbBuffer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



===== SplitTapeRequest @ 14000942c =====

void SplitTapeRequest(longlong param_1,longlong param_2,uint param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  uint local_res8;
  ulonglong local_res10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar3 = *(undefined1 **)(param_2 + 0xb8);
  bVar6 = false;
  local_res8 = *(uint *)(puVar3 + 8);
  lVar10 = *(longlong *)(puVar3 + 0x18);
  uVar12 = *(uint *)(*(longlong *)(param_2 + 8) + 0x2c);
  lVar11 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x20);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  local_res10 = (ulonglong)((param_3 - 1) + local_res8) / (ulonglong)param_3;
  *(ulonglong *)(puVar3 + -0x40) = local_res10;
  if ((int)local_res10 != 0) {
    lVar11 = ((ulonglong)uVar12 + lVar11) - lVar10;
    uVar12 = param_3;
    do {
      lVar8 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar8 == 0) {
LAB_1400094c7:
        LOCK();
        piVar1 = (int *)(puVar3 + -0x40);
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (*piVar1 == 0) {
          bVar6 = true;
        }
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        uVar9 = *(undefined8 *)(param_2 + 8);
        lVar4 = *(longlong *)(lVar8 + 0xb8);
        *(char *)(lVar8 + 0x43) = *(char *)(lVar8 + 0x43) + -1;
        *(undefined1 **)(lVar8 + 0xb8) = (undefined1 *)(lVar4 + -0x48);
        *(undefined8 *)(lVar8 + 8) = uVar9;
        *(undefined1 *)(lVar4 + -0x48) = *puVar3;
        *(uint *)(lVar4 + -0x40) = uVar12;
        *(longlong *)(lVar4 + -0x30) = lVar10;
        *(longlong *)(lVar4 + -0x20) = param_1;
        uVar9 = TapeReadWrite(param_1,lVar8);
        if ((int)uVar9 != 0) goto LAB_1400094c7;
        lVar4 = *(longlong *)(*(longlong *)(lVar8 + 0xb8) + -0x40);
        *(longlong *)(lVar4 + 0x18) = lVar11 + lVar10;
        lVar5 = *(longlong *)(lVar8 + 0xb8);
        *(longlong *)(lVar8 + 0x18) = param_2;
        *(code **)(lVar5 + -0x10) = TapeIoCompleteAssociated;
        *(longlong *)(lVar5 + -8) = lVar4;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        iVar7 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10));
        if (iVar7 < 0) {
          LOCK();
          piVar1 = (int *)(puVar3 + -0x40);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (*piVar1 == 0) {
            bVar6 = true;
          }
          *(int *)(param_2 + 0x30) = iVar7;
          *(undefined8 *)(param_2 + 0x38) = 0;
          IoFreeIrp(lVar8);
        }
      }
      lVar10 = lVar10 + (ulonglong)param_3;
      local_res8 = local_res8 - param_3;
      uVar12 = param_3;
      if (local_res8 <= param_3) {
        uVar12 = local_res8;
      }
      local_res10 = local_res10 - 1;
    } while (local_res10 != 0);
    if (bVar6) {
      ClassReleaseRemoveLock(param_1,param_2);
      ClassCompleteRequest(param_1,param_2,0);
    }
  }
  return;
}



===== TapeAddDevice @ 140009620 =====

void TapeAddDevice(ulonglong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  char local_res18 [8];
  
  local_res18[0] = '\0';
  uVar4 = param_1;
  puVar2 = (undefined8 *)IoGetDriverObjectExtension(param_1,TapeClassInitialize);
  lVar3 = IoGetConfigurationInformation();
  iVar1 = 1;
  if (*(int *)(lVar3 + 0xc) == 0) {
    TapeSymbolicNamePersistencePreference(uVar4,0x1400051c0,1,0x1400051a8,local_res18);
    iVar1 = 2;
  }
  TapeSymbolicNamePersistencePreference(uVar4,0x140005260,iVar1,0x140005230,local_res18);
  iVar1 = CreateTapeDeviceObject(param_1,param_2,puVar2,local_res18[0] == '\0');
  if (-1 < iVar1) {
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
  }
  return;
}



===== TapeAssignSymbolicLink @ 1400096ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TapeAssignSymbolicLink
              (char param_1,longlong param_2,char param_3,uint param_4,wchar_t *param_5,
              longlong param_6)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  short *psVar5;
  short *psVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_1b8 [32];
  undefined8 local_170;
  longlong lStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  wchar_t local_138 [64];
  short local_b8 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  memset(local_138,0,0x80);
  local_150 = 0;
  uStack_148 = 0;
  memset(local_b8,0,0x80);
  lVar8 = 0;
  local_160 = 0;
  uStack_158 = 0;
  iVar2 = 0;
  pwVar4 = local_138;
  lVar9 = 0x40;
  lVar7 = 0x40;
  local_170 = 0;
  lStack_168 = 0;
  do {
    if ((lVar7 == 0x39) ||
       (wVar1 = *(wchar_t *)(((longlong)L"\\Device" - (longlong)local_138) + (longlong)pwVar4),
       wVar1 == L'\0')) break;
    *pwVar4 = wVar1;
    pwVar4 = pwVar4 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  pwVar3 = pwVar4 + -1;
  if (lVar7 != 0) {
    pwVar3 = pwVar4;
  }
  lVar7 = -1;
  *pwVar3 = L'\0';
  do {
    lVar7 = lVar7 + 1;
  } while (local_138[lVar7] != L'\0');
  pwVar4 = L"\\Tape%u";
  if (param_3 == '\0') {
    pwVar4 = L"\\TapeDrive%u";
  }
  RtlStringCchPrintfExW
            (local_138 + lVar7,0x40 - lVar7,(longlong *)0x0,(ulonglong *)0x0,0x600,pwVar4,param_1);
  pwVar4 = local_138;
  RtlInitUnicodeString(&local_150);
  if ((ulonglong)(param_4 >> 1) < 0x7fffffff) {
    pwVar4 = (wchar_t *)((longlong)param_5 - (longlong)local_b8);
    psVar6 = local_b8;
    do {
      if ((((ulonglong)(param_4 >> 1) - 0x40) + lVar9 == 0) ||
         (*(short *)((longlong)pwVar4 + (longlong)psVar6) == 0)) break;
      *psVar6 = *(short *)((longlong)pwVar4 + (longlong)psVar6);
      psVar6 = psVar6 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    psVar5 = psVar6 + -1;
    if (lVar9 != 0) {
      psVar5 = psVar6;
    }
    *psVar5 = 0;
  }
  RtlStringCchCatExW(local_b8,pwVar4,L"\\");
  RtlStringCchCatExW(local_b8,pwVar4,*(short **)(param_2 + 8));
  RtlInitUnicodeString(&local_160,local_b8);
  if (param_6 != 0) {
    iVar2 = RtlUnicodeStringToAnsiString(&local_170,&local_160,1);
    if (-1 < iVar2) {
      iVar2 = wcscmp(param_5,L"\\DosDevices");
      if (iVar2 == 0) {
        lVar8 = 0xb;
      }
      else {
        iVar2 = wcscmp(param_5,L"\\Device");
        if (iVar2 == 0) {
          lVar8 = 7;
        }
      }
      iVar2 = RtlCharToInteger(lStack_168 + 5 + lVar8,10,param_6);
      RtlFreeAnsiString(&local_170);
    }
  }
  IoCreateSymbolicLink(&local_160,&local_150);
  return iVar2;
}



===== TapeClassAllocateSrbBuffer @ 140009980 =====

bool TapeClassAllocateSrbBuffer(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  
                    /* 0x9980  2  TapeClassAllocateSrbBuffer */
  if (*(longlong *)(param_1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
  }
  lVar1 = ExAllocatePool2(0x48,param_2,0x65706154);
  if (lVar1 != 0) {
    *(longlong *)(param_1 + 0x18) = lVar1;
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  else {
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return lVar1 != 0;
}



===== TapeClassCompareMemory @ 1400099f0 =====

void TapeClassCompareMemory(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
                    /* 0x99f0  3  TapeClassCompareMemory */
  RtlCompareMemory(param_1,param_2,param_3);
  return;
}



===== TapeClassInitialize @ 140009a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TapeClassInitialize(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  undefined8 *local_res8;
  undefined4 local_268;
  undefined4 local_264;
  int local_260;
  undefined4 local_25c;
  undefined4 local_254;
  code *local_250;
  code *local_248;
  code *local_240;
  undefined8 local_238;
  undefined8 local_230;
  code *local_228;
  code *local_220;
  code *local_210;
  code *local_208;
  undefined4 local_1f8;
  undefined *local_1f0;
  code *local_1e8;
  code *local_1e0;
  code *local_1d8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_110;
  code *local_f0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  
                    /* 0x9a10  4  TapeClassInitialize */
  local_res8 = (undefined8 *)0x0;
  local_264 = 0;
  memset(&local_d8,0,0xb8);
  if (*param_3 < 0x90) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    iVar1 = -0x3ffffff3;
  }
  else {
    if (*param_3 < 0xb8) {
      local_b0 = *(undefined8 *)(param_3 + 8);
      uStack_a8 = *(undefined8 *)(param_3 + 10);
      local_a0 = *(undefined8 *)(param_3 + 0xc);
      uStack_98 = *(undefined8 *)(param_3 + 0xe);
      local_90 = *(undefined8 *)(param_3 + 0x10);
      uStack_88 = *(undefined8 *)(param_3 + 0x12);
      local_80 = *(undefined8 *)(param_3 + 0x14);
      uStack_78 = *(undefined8 *)(param_3 + 0x16);
      local_70 = *(undefined8 *)(param_3 + 0x18);
      uStack_68 = *(undefined8 *)(param_3 + 0x1a);
      uStack_50 = *(undefined8 *)(param_3 + 0x20);
      local_48 = param_3[0x22];
      uStack_44 = param_3[0x23];
      uStack_60 = *(undefined8 *)(param_3 + 0x1c);
      local_58 = *(undefined8 *)(param_3 + 0x1e);
      local_d8 = CONCAT44(local_d8._4_4_,0x90);
      uStack_d0 = *(undefined8 *)param_3;
      uStack_c8 = *(undefined8 *)(param_3 + 2);
      uStack_c0 = *(undefined8 *)(param_3 + 4);
      uStack_b8 = *(undefined8 *)(param_3 + 6);
    }
    else {
      uStack_b8 = *(undefined8 *)(param_3 + 8);
      local_b0 = *(undefined8 *)(param_3 + 10);
      uStack_a8 = *(undefined8 *)(param_3 + 0xc);
      local_a0 = *(undefined8 *)(param_3 + 0xe);
      uStack_98 = *(undefined8 *)(param_3 + 0x10);
      local_90 = *(undefined8 *)(param_3 + 0x12);
      uStack_88 = *(undefined8 *)(param_3 + 0x14);
      local_80 = *(undefined8 *)(param_3 + 0x16);
      uStack_78 = *(undefined8 *)(param_3 + 0x18);
      local_70 = *(undefined8 *)(param_3 + 0x1a);
      uStack_68 = *(undefined8 *)(param_3 + 0x1c);
      uStack_60 = *(undefined8 *)(param_3 + 0x1e);
      local_58 = *(undefined8 *)(param_3 + 0x20);
      uStack_50 = *(undefined8 *)(param_3 + 0x22);
      local_28 = *(undefined8 *)(param_3 + 0x2c);
      local_48 = param_3[0x24];
      uStack_44 = param_3[0x25];
      uStack_40 = param_3[0x26];
      uStack_3c = param_3[0x27];
      local_38 = param_3[0x28];
      uStack_34 = param_3[0x29];
      uStack_30 = param_3[0x2a];
      uStack_2c = param_3[0x2b];
      local_d8 = *(undefined8 *)param_3;
      uStack_d0 = *(undefined8 *)(param_3 + 2);
      uStack_c8 = *(undefined8 *)(param_3 + 4);
      uStack_c0 = *(undefined8 *)(param_3 + 6);
    }
    iVar1 = IoAllocateDriverObjectExtension(param_1,TapeClassInitialize,0xb8,&local_res8);
    if (-1 < iVar1) {
LAB_140009c68:
      *local_res8 = local_d8;
      local_res8[1] = uStack_d0;
      local_res8[2] = uStack_c8;
      local_res8[3] = uStack_c0;
      local_res8[4] = uStack_b8;
      local_res8[5] = local_b0;
      local_res8[6] = uStack_a8;
      local_res8[7] = local_a0;
      local_res8[8] = uStack_98;
      local_res8[9] = local_90;
      local_res8[10] = uStack_88;
      local_res8[0xb] = local_80;
      local_res8[0xc] = uStack_78;
      local_res8[0xd] = local_70;
      local_res8[0xe] = uStack_68;
      local_res8[0xf] = uStack_60;
      local_res8[0x10] = local_58;
      local_res8[0x11] = uStack_50;
      local_res8[0x12] = CONCAT44(uStack_44,local_48);
      local_res8[0x13] = CONCAT44(uStack_3c,uStack_40);
      local_res8[0x14] = CONCAT44(uStack_34,local_38);
      local_res8[0x15] = CONCAT44(uStack_2c,uStack_30);
      local_res8[0x16] = local_28;
      memset(&local_268,0,0x188);
      local_238 = 0;
      local_260 = uStack_c8._4_4_ + 0x5a8;
      local_230 = 0;
      local_268 = 0x188;
      local_220 = TapeStartDevice;
      local_210 = TapeStopDevice;
      local_228 = TapeInitDevice;
      local_208 = TapeRemoveDevice;
      local_110 = TapeAddDevice;
      local_250 = TapeError;
      local_248 = TapeReadWriteVerification;
      local_240 = TapeDeviceControl;
      local_1f0 = &TapeWmiGuidList;
      local_1e8 = TapeQueryWmiRegInfo;
      local_1e0 = TapeQueryWmiDataBlock;
      local_1d8 = TapeSetWmiDataItem;
      local_1d0 = TapeSetWmiDataItem;
      local_1c8 = TapeExecuteWmiMethod;
      local_1c0 = TapeWmiFunctionControl;
      local_f0 = TapeUnload;
      local_25c = 0x1f;
      local_254 = 0x101;
      local_1f8 = 6;
      iVar1 = ClassInitialize(param_1,param_2,&local_268);
      if (iVar1 < 0) {
        TapeUnload();
      }
      TapeClassQuerySetAutoRunValue(param_2);
      return iVar1;
    }
    if (iVar1 == -0x3fffffcb) {
      local_res8 = (undefined8 *)IoGetDriverObjectExtension(param_1);
      if (local_res8 != (undefined8 *)0x0) goto LAB_140009c68;
      if (g_wil_details_featureChangeNotification != 0) {
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      iVar1 = -0x3fffff66;
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
    }
  }
  _g_wil_details_isFeatureStagingInitialized = 0;
  return iVar1;
}



===== TapeClassLiDiv @ 140009e30 =====

longlong TapeClassLiDiv(longlong param_1,longlong param_2)

{
                    /* 0x9e30  5  TapeClassLiDiv */
  return param_1 / param_2;
}



===== TapeClassZeroMemory @ 140009e50 =====

void TapeClassZeroMemory(void *param_1,uint param_2)

{
                    /* 0x9e50  9  TapeClassZeroMemory */
  memset(param_1,0,(ulonglong)param_2);
  return;
}



===== TapeCreateNewDeviceSubKey @ 140009e6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140009f9b) */

int TapeCreateNewDeviceSubKey
              (undefined8 param_1,uint *param_2,undefined8 *param_3,undefined8 param_4,
              short *param_5)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStackY_158 [32];
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  wchar_t local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  memset(local_c8,0,0x80);
  local_fc = 0;
  iVar2 = 0;
  local_e4 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if (param_5 == (short *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    uVar6 = *param_2;
    if (uVar6 < 0x7fffffff) {
      lVar7 = 0x40;
      while( true ) {
        RtlStringCchPrintfExW
                  (local_c8,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Tape%u",(char)uVar6);
        RtlInitUnicodeString(&local_110,local_c8);
        local_f0 = &local_110;
        local_100 = 0x30;
        local_e8 = 0x240;
        local_e0 = 0;
        uStack_d8 = 0;
        local_f8 = param_1;
        iVar2 = ZwCreateKey(param_3,0x2001f);
        if (-1 < iVar2) break;
        uVar6 = uVar6 - 1;
        if (0x7ffffffe < uVar6) goto LAB_140009fb9;
      }
      uVar4 = 0xffffffffffffffff;
      do {
        uVar4 = uVar4 + 1;
      } while (local_c8[uVar4] != L'\0');
      if (uVar4 < 0x7fffffff) {
        lVar5 = (longlong)local_c8 - (longlong)param_5;
        do {
          if ((lVar7 + -0x40 + uVar4 == 0) ||
             (sVar1 = *(short *)(lVar5 + (longlong)param_5), sVar1 == 0)) break;
          *param_5 = sVar1;
          param_5 = param_5 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        psVar3 = param_5 + -1;
        if (lVar7 != 0) {
          psVar3 = param_5;
        }
        *psVar3 = 0;
      }
      else {
        *param_5 = 0;
      }
      *param_2 = uVar6 - 1;
      goto LAB_140009fc9;
    }
LAB_140009fb9:
    if (uVar6 == 0x7fffffff) {
      iVar2 = -0x3fffffff;
    }
  }
LAB_140009fc9:
  return iVar2;
}



===== TapeCreateNonPersistentSymbolicName @ 14000a058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TapeCreateNonPersistentSymbolicName
              (longlong param_1,uint *param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStackY_158 [32];
  undefined8 local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_100;
  undefined4 local_fc;
  longlong local_f8;
  undefined8 *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  wchar_t local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  memset(local_c8,0,0x80);
  local_fc = 0;
  iVar2 = 0;
  local_e4 = 0;
  local_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if ((param_4 == (wchar_t *)0x0) || (param_2 == (uint *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    uVar6 = *param_2;
    if (param_1 == 0) {
      RtlStringCchPrintfExW
                (param_4,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Tape%u",(char)uVar6);
    }
    else {
      iVar2 = 0;
      if (uVar6 < 0x7fffffff) {
        lVar7 = 0x40;
LAB_14000a116:
        RtlStringCchPrintfExW
                  (local_c8,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Tape%u",(char)uVar6);
        RtlInitUnicodeString(&local_110,local_c8);
        local_f0 = &local_110;
        local_100 = 0x30;
        local_e8 = 0x240;
        local_e0 = 0;
        uStack_d8 = 0;
        local_f8 = param_1;
        iVar2 = ZwOpenKey(&local_118,0x20019);
        if (iVar2 < 0) {
          if ((iVar2 == -0x3ffffff8) || (iVar2 == -0x3fffffcc)) {
            uVar4 = 0xffffffffffffffff;
            do {
              uVar4 = uVar4 + 1;
            } while (local_c8[uVar4] != L'\0');
            if (uVar4 < 0x7fffffff) {
              lVar5 = (longlong)local_c8 - (longlong)param_4;
              do {
                if ((lVar7 + -0x40 + uVar4 == 0) ||
                   (wVar1 = *(wchar_t *)(lVar5 + (longlong)param_4), wVar1 == L'\0')) break;
                *param_4 = wVar1;
                param_4 = param_4 + 1;
                lVar7 = lVar7 + -1;
              } while (lVar7 != 0);
              pwVar3 = param_4 + -1;
              if (lVar7 != 0) {
                pwVar3 = param_4;
              }
              *pwVar3 = L'\0';
            }
            else {
              *param_4 = L'\0';
            }
            iVar2 = 0;
            *param_2 = uVar6 + 1;
            goto LAB_14000a241;
          }
        }
        else {
          ZwClose(local_118);
        }
        uVar6 = uVar6 + 1;
        if (0x7ffffffe < uVar6) goto LAB_14000a1c9;
        goto LAB_14000a116;
      }
LAB_14000a1c9:
      if (uVar6 == 0x7fffffff) {
        iVar2 = -0x3fffffff;
      }
    }
  }
LAB_14000a241:
  return iVar2;
}



===== TapeCreateSymbolicName @ 14000a270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TapeCreateSymbolicName(longlong param_1,char param_2)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  longlong lVar14;
  bool bVar15;
  bool bVar16;
  undefined1 auStackY_228 [32];
  uint local_1e4;
  longlong local_1e0;
  int local_1d8;
  longlong local_1d0;
  uint local_1c8 [2];
  longlong local_1c0;
  longlong local_1b8 [4];
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 *local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  wchar_t local_138 [64];
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_228;
  bVar16 = false;
  local_1b8[0] = 0;
  local_1c8[0] = 0;
  local_164 = 0;
  local_14c = 0;
  local_1c0 = 0;
  local_1e4 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  uStack_180 = 0;
  memset(local_b8,0,0x80);
  local_1e0 = 0;
  uVar11 = 0x80;
  local_1d0 = 0;
  uVar9 = 0;
  local_1d8 = 0;
  uVar8 = 0;
  local_1b8[1] = 0;
  local_1b8[2] = 0;
  lVar14 = 0;
  memset(local_138,0,0x80);
  local_1b8[3] = *(longlong *)(param_1 + 0x40);
  bVar15 = param_2 == '\0';
  bVar2 = false;
  lVar1 = *(longlong *)(local_1b8[3] + 0x60);
  if (param_2 == '\0') {
    puVar13 = (uint *)(lVar1 + 0xdc);
    TapeCreateNonPersistentSymbolicName(0,puVar13,uVar11,local_138);
    RtlInitUnicodeString(local_1b8 + 1,local_138);
    iVar4 = TapeAssignSymbolicLink
                      ((char)*puVar13,(longlong)(local_1b8 + 1),'\x01',0x16,L"\\DosDevices",
                       lVar1 + 0xe0);
    if (iVar4 < 0) {
      return CONCAT44(extraout_var,iVar4);
    }
    *(undefined1 *)(lVar1 + 0xe5) = 1;
    *(undefined4 *)(local_1b8[3] + 0x24c) = *(undefined4 *)(lVar1 + 0xe0);
    RtlStringCchPrintfExW
              (local_138,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"TapeDrive%u",(char)*puVar13);
    RtlInitUnicodeString(local_1b8 + 1,local_138);
    iVar4 = TapeAssignSymbolicLink
                      ((char)*puVar13,(longlong)(local_1b8 + 1),'\x01',0xe,L"\\Device",0);
    if (iVar4 < 0) {
      return CONCAT44(extraout_var_00,iVar4);
    }
    *(undefined1 *)(lVar1 + 0xe4) = 1;
    return CONCAT44(extraout_var_00,iVar4);
  }
  puVar13 = local_1c8;
  uVar7 = TapeCreateUniqueId(param_1,uVar9,local_1b8,(int *)puVar13);
  lVar3 = local_1b8[0];
  if ((int)uVar7 < 0) {
    if (local_1b8[0] != 0) {
      ExFreePoolWithTag(local_1b8[0],0);
    }
    if ((int)uVar7 != -0x3fffffff) {
      return uVar7 & 0xffffffff;
    }
    bVar2 = true;
  }
  RtlInitUnicodeString(&local_178,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Tape");
  local_160 = 0;
  local_158 = &local_178;
  puVar12 = &local_168;
  local_168 = 0x30;
  local_150 = 0x240;
  local_148 = 0;
  uStack_140 = 0;
  uVar5 = ZwOpenKey(&local_1c0,0x2001f);
  uVar7 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  else {
    if (!bVar2) {
      RtlInitUnicodeString(&local_198,L"UIDType");
      RtlInitUnicodeString(&local_188,L"UniqueId");
      uVar7 = uVar8;
      do {
        uVar5 = (uint)uVar8;
        if (lVar14 != 0) {
          ExFreePoolWithTag(lVar14,0);
          lVar14 = 0;
          local_1d0 = 0;
          uVar5 = local_1e4;
        }
        uVar5 = TapeGetSubKeyByIndex(local_1c0,uVar5,&local_1e0,puVar13,local_b8);
        uVar8 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          if (uVar5 == 0xc000009a) {
            if (lVar3 != 0) {
              ExFreePoolWithTag(lVar3,0);
            }
            uVar7 = 0xc000009a;
            goto LAB_14000a8c3;
          }
          if (uVar5 != 0x8000001a) {
            uVar7 = uVar8;
          }
LAB_14000a63a:
          if (uVar5 == 0x8000001a) goto LAB_14000a657;
        }
        else {
          RtlInitUnicodeString(local_1b8 + 1,local_b8);
          puVar13 = (uint *)0x0;
          uVar6 = TapeGetValuePartialInfo(local_1e0,&local_198,&local_1d0,(undefined4 *)0x0);
          if (-1 < (int)uVar6) {
            local_1d8 = *(int *)(local_1d0 + 0xc);
            ExFreePoolWithTag(local_1d0,0);
            puVar13 = (uint *)local_1b8;
            local_1d0 = 0;
            uVar6 = TapeGetValuePartialInfo(local_1e0,&local_188,&local_1d0,puVar13);
            if (-1 < (int)uVar6) {
              bVar16 = false;
              lVar14 = local_1d0;
              if (((local_1c8[0] != 0) && (local_1c8[0] == *(uint *)(local_1d0 + 8))) &&
                 (local_1d8 == 1)) {
                uVar10 = 0;
                if (local_1c8[0] != 0) {
                  do {
                    if (*(char *)(uVar10 + lVar3) != *(char *)(uVar10 + 0xc + local_1d0)) break;
                    uVar6 = (int)uVar10 + 1;
                    uVar10 = (ulonglong)uVar6;
                  } while (uVar6 < local_1c8[0]);
                }
                bVar16 = (uint)uVar10 == local_1c8[0];
              }
              goto LAB_14000a63a;
            }
          }
          uVar7 = (ulonglong)uVar6;
          ZwClose(local_1e0);
          lVar14 = local_1d0;
        }
        if (bVar16) goto LAB_14000a657;
        local_1e4 = local_1e4 + 1;
        uVar8 = (ulonglong)local_1e4;
      } while( true );
    }
    local_1e4 = 0;
LAB_14000a8f2:
    do {
      uVar5 = TapeCreateNonPersistentSymbolicName(local_1c0,&local_1e4,puVar12,local_138);
      if (-1 < (int)uVar5) {
        RtlInitUnicodeString(local_1b8 + 1,local_138);
        puVar12 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar12 >> 8),bVar15);
        puVar13 = (uint *)(lVar1 + 0xe0);
        uVar5 = TapeAssignSymbolicLink
                          ((char)*(undefined4 *)(lVar1 + 0xdc),(longlong)(local_1b8 + 1),bVar15,0x16
                           ,L"\\DosDevices",(longlong)puVar13);
        if (-1 < (int)uVar5) {
          puVar12 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar12 >> 8),bVar15);
          *(undefined1 *)(lVar1 + 0xe5) = 1;
          uVar5 = TapeAssignSymbolicLink
                            ((char)*(undefined4 *)(lVar1 + 0xdc),(longlong)(local_1b8 + 1),bVar15,
                             0xe,L"\\Device",0);
          uVar7 = (ulonglong)uVar5;
          if (-1 < (int)uVar5) {
            *(undefined1 *)(lVar1 + 0xe4) = 1;
            *(uint *)(local_1b8[3] + 0x24c) = *puVar13;
            break;
          }
          if (uVar5 != 0xc0000035) break;
          if (*(char *)(lVar1 + 0xe5) != '\0') {
            puVar12 = (undefined4 *)(ulonglong)*puVar13;
            TapeDeassignSymbolicLink(0x16,0x140005300,(char)*puVar13,'\0');
            *(undefined1 *)(lVar1 + 0xe5) = 0;
          }
          goto LAB_14000a8f2;
        }
      }
      uVar7 = (ulonglong)uVar5;
    } while (uVar5 == 0xc0000035);
    if (local_1c0 != 0) {
      ZwClose();
    }
  }
  return uVar7;
LAB_14000a657:
  if (local_1e0 != 0) {
    ZwClose();
  }
  if ((!bVar16) && ((int)uVar7 < 0)) {
    if (lVar14 != 0) {
      ExFreePoolWithTag(lVar14,0);
    }
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
LAB_14000a8c3:
    ZwClose(local_1c0);
    return uVar7;
  }
  local_1e4 = 0x7ffffffe;
  if (!bVar16) goto LAB_14000a7b4;
  do {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    ZwClose(local_1c0);
    if ((int)uVar8 < 0) {
LAB_14000a79f:
      uVar6 = (uint)uVar7;
      if (((int)uVar8 != -0x3fffffcb) || (bVar16)) goto LAB_14000a896;
    }
    else {
      puVar13 = (uint *)0x16;
      uVar5 = TapeAssignSymbolicLink
                        ((char)*(undefined4 *)(lVar1 + 0xdc),(longlong)(local_1b8 + 1),bVar15,0x16,
                         L"\\DosDevices",lVar1 + 0xe0);
      uVar8 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        puVar13 = (uint *)0xe;
        *(undefined2 *)(lVar1 + 0xe5) = 0x101;
        *(undefined4 *)(local_1b8[3] + 0x24c) = *(undefined4 *)(lVar1 + 0xe0);
        uVar6 = TapeAssignSymbolicLink
                          ((char)*(undefined4 *)(lVar1 + 0xdc),(longlong)(local_1b8 + 1),bVar15,0xe,
                           L"\\Device",0);
        uVar7 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
          *(undefined1 *)(lVar1 + 0xe4) = 1;
        }
      }
      uVar6 = (uint)uVar7;
      if (bVar16) goto LAB_14000a79f;
      if (uVar5 != 0xc0000035) {
        ZwClose(local_1e0);
LAB_14000a896:
        if ((int)uVar8 < 0) {
          return uVar8;
        }
        if ((int)uVar6 < 0) {
          return (ulonglong)uVar6;
        }
        return uVar8;
      }
      ZwDeleteKey();
    }
LAB_14000a7b4:
    uVar5 = TapeCreateNewDeviceSubKey(local_1c0,&local_1e4,&local_1e0,puVar13,local_138);
    uVar8 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      RtlInitUnicodeString(local_1b8 + 1,local_138);
      local_1d8 = 1;
      puVar13 = (uint *)0x4;
      uVar5 = ZwSetValueKey(local_1e0,&local_198,0);
      if (-1 < (int)uVar5) {
        puVar13 = (uint *)0x3;
        uVar5 = ZwSetValueKey(local_1e0,&local_188,0);
      }
      uVar8 = (ulonglong)uVar5;
      if (lVar14 != 0) {
        ExFreePoolWithTag(lVar14);
      }
      if ((int)uVar5 < 0) {
        ZwDeleteKey(local_1e0);
      }
    }
  } while( true );
}



===== TapeCreateUniqueId @ 14000aa40 =====

undefined8 TapeCreateUniqueId(longlong param_1,undefined8 param_2,undefined8 *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  void *_Dst;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x208);
  uVar1 = *(uint *)(lVar4 + 0xc);
  if (uVar1 != 0xffffffff) {
    uVar2 = *(uint *)(lVar4 + 0x10);
    if (uVar2 != 0xffffffff) {
      uVar3 = *(uint *)(lVar4 + 0x18);
      if ((((uVar3 != 0xffffffff) && (uVar1 != 0)) && (uVar2 != 0)) && (uVar3 != 0)) {
        uVar9 = 0xffffffffffffffff;
        uVar7 = 0xffffffffffffffff;
        do {
          uVar7 = uVar7 + 1;
        } while (*(char *)((longlong)(lVar4 + (ulonglong)uVar1) + uVar7) != '\0');
        uVar8 = 0xffffffffffffffff;
        do {
          uVar8 = uVar8 + 1;
        } while (*(char *)((longlong)(lVar4 + (ulonglong)uVar2) + uVar8) != '\0');
        do {
          uVar9 = uVar9 + 1;
        } while (*(char *)((longlong)(lVar4 + (ulonglong)uVar3) + uVar9) != '\0');
        uVar5 = (int)uVar9 + (int)uVar8 + (int)uVar7;
        iVar6 = uVar5 + 1;
        _Dst = (void *)ExAllocatePool2(0x40,iVar6,0x65706154);
        *param_3 = _Dst;
        if (_Dst == (void *)0x0) {
          return 0xc000009a;
        }
        memcpy(_Dst,(void *)(lVar4 + (ulonglong)uVar1),uVar7 & 0xffffffff);
        memcpy((void *)((uVar7 & 0xffffffff) + (longlong)_Dst),(void *)(lVar4 + (ulonglong)uVar2),
               uVar8 & 0xffffffff);
        memcpy((void *)((ulonglong)(uint)((int)uVar8 + (int)uVar7) + (longlong)_Dst),
               (void *)(lVar4 + (ulonglong)uVar3),uVar9 & 0xffffffff);
        *(undefined1 *)((ulonglong)uVar5 + (longlong)_Dst) = 0;
        *param_4 = iVar6;
        return 0;
      }
    }
  }
  *param_3 = 0;
  return 0xc0000001;
}



===== TapeDeassignSymbolicLink @ 14000ab88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TapeDeassignSymbolicLink(uint param_1,longlong param_2,char param_3,char param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  undefined1 auStackY_e8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(local_98,0,0x80);
  local_a8 = 0;
  uStack_a0 = 0;
  if ((ulonglong)(param_1 >> 1) < 0x7fffffff) {
    lVar4 = 0x40;
    pwVar3 = local_98;
    do {
      if ((((ulonglong)(param_1 >> 1) - 0x40) + lVar4 == 0) ||
         (wVar1 = *(wchar_t *)((param_2 - (longlong)local_98) + (longlong)pwVar3), wVar1 == L'\0'))
      break;
      *pwVar3 = wVar1;
      pwVar3 = pwVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    pwVar2 = pwVar3 + -1;
    if (lVar4 != 0) {
      pwVar2 = pwVar3;
    }
    *pwVar2 = L'\0';
  }
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (local_98[lVar4] != L'\0');
  pwVar3 = L"\\TapeDrive%u";
  if (param_4 == '\0') {
    pwVar3 = L"\\Tape%u";
  }
  RtlStringCchPrintfExW
            (local_98 + lVar4,0x40 - lVar4,(longlong *)0x0,(ulonglong *)0x0,0x600,pwVar3,param_3);
  RtlInitUnicodeString(&local_a8,local_98);
  IoDeleteSymbolicLink(&local_a8);
  return;
}



===== TapeGetSubKeyByIndex @ 14000acd4 =====

int TapeGetSubKeyByIndex
              (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              void *param_5)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res20[0] = 0x18;
  lVar2 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_5 == (void *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    do {
      if (lVar2 != 0) {
        ExFreePoolWithTag(lVar2,0);
      }
      lVar2 = ExAllocatePool2(0x48,local_res20[0],0x65706154);
      if (lVar2 == 0) {
        return -0x3fffff66;
      }
      iVar1 = ZwEnumerateKey(param_1,param_2,0,lVar2,local_res20[0],local_res20);
    } while ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb));
    if (-1 < iVar1) {
      if (*(uint *)(lVar2 + 0xc) < 0x80) {
        memcpy(param_5,(void *)(lVar2 + 0x10),(ulonglong)*(uint *)(lVar2 + 0xc));
        *(undefined2 *)((longlong)param_5 + (ulonglong)(*(uint *)(lVar2 + 0xc) >> 1) * 2) = 0;
        RtlInitUnicodeString(&local_68,param_5);
        local_48 = &local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
        local_38 = 0;
        uStack_30 = 0;
        uStack_50 = param_1;
        iVar1 = ZwOpenKey(param_3,0x80000000,&local_58);
      }
      else {
        iVar1 = -0x3fffffdd;
      }
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return iVar1;
}



===== TapeGetValuePartialInfo @ 14000ae68 =====

int TapeGetValuePartialInfo
              (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_28 [4];
  
  local_28[0] = 0x10;
  lVar2 = 0;
  while( true ) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    lVar2 = ExAllocatePool2(0x48,local_28[0],0x65706154);
    if (lVar2 == 0) break;
    iVar1 = ZwQueryValueKey(param_1,param_2,2,lVar2,local_28[0],local_28);
    if ((iVar1 != -0x3fffffdd) && (iVar1 != -0x7ffffffb)) {
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar2,0);
      }
      else {
        *param_3 = lVar2;
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = local_28[0];
        }
      }
      return iVar1;
    }
  }
  return -0x3fffff66;
}



===== TapeInitDevice @ 14000af60 =====

int TapeInitDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined4 local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = ExAllocatePool2(0x48,0x12,0x65706154);
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    ClassInitializeSrbLookasideList(lVar1,4);
    *(undefined4 *)(lVar1 + 0x23c) = 0xffffffff;
    lVar2 = *(longlong *)(lVar1 + 0x60);
    *(longlong *)(lVar1 + 0x240) = lVar4;
    iVar3 = 0xb4;
    if (*(int *)(lVar2 + 0x20) != 0) {
      iVar3 = *(int *)(lVar2 + 0x20);
    }
    *(int *)(lVar1 + 0x248) = iVar3;
    *(undefined8 *)(lVar2 + 0xc0) = 0;
    iVar3 = GetTimeoutDeltaFromRegistry(*(undefined8 *)(lVar1 + 0x200));
    *(int *)(lVar2 + 0xd8) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(lVar2 + 0xd8) = *(undefined4 *)(lVar1 + 0x248);
    }
    local_res8[0] = 1;
    iVar3 = ClassGetDescriptor(*(undefined8 *)(lVar1 + 0x10),local_res8,lVar1 + 0x210);
    if (iVar3 < 0) {
      ExFreePoolWithTag(lVar4,0);
    }
    else {
      ClassInitializeMediaChangeDetection(lVar1,"Tape");
      RtlInitUnicodeString(lVar2 + 200,0);
      IoRegisterDeviceInterface
                (*(undefined8 *)(lVar1 + 0x200),&GUID_DEVINTERFACE_TAPE,0,lVar2 + 200);
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== TapeRemoveDevice @ 14000b0c0 =====

undefined8 TapeRemoveDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = *(longlong *)(lVar2 + 0x60);
  if ((param_2 - 1U & 0xfd) != 0) {
    if (param_2 == '\x02') {
      if (*(longlong *)(lVar2 + 0x208) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x208),0);
        *(undefined8 *)(lVar2 + 0x208) = 0;
      }
      if (*(longlong *)(lVar2 + 0x210) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x210),0);
        *(undefined8 *)(lVar2 + 0x210) = 0;
      }
      if (*(longlong *)(lVar2 + 0x240) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x240),0);
        *(undefined8 *)(lVar2 + 0x240) = 0;
      }
      ClassDeleteSrbLookasideList(lVar2);
    }
    if (*(longlong *)(lVar1 + 0xd0) != 0) {
      lVar2 = lVar1 + 200;
      IoSetDeviceInterfaceState(lVar2,0);
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    if (*(char *)(lVar1 + 0xe5) != '\0') {
      TapeDeassignSymbolicLink(0x16,0x140005300,(char)*(undefined4 *)(lVar1 + 0xe0),'\0');
      *(undefined1 *)(lVar1 + 0xe5) = 0;
    }
    if (*(char *)(lVar1 + 0xe4) != '\0') {
      TapeDeassignSymbolicLink
                (0xe,0x140005318,(char)*(undefined4 *)(lVar1 + 0xe0),*(char *)(lVar1 + 0xe7) == '\0'
                );
      *(undefined1 *)(lVar1 + 0xe4) = 0;
    }
    lVar2 = IoGetConfigurationInformation();
    *(int *)(lVar2 + 0xc) = *(int *)(lVar2 + 0xc) + -1;
  }
  return 0;
}



===== TapeStartDevice @ 14000b220 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TapeStartDevice(ulonglong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStackY_b8 [32];
  undefined1 local_88 [3];
  byte local_85;
  undefined1 local_7e;
  undefined4 local_74;
  undefined1 local_40;
  undefined1 local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar3 = ExAllocatePool2(0x48,0xfc,0x65706154);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    lVar2 = *(longlong *)(lVar1 + 0x60);
    memset(local_88,0,0x58);
    local_74 = 2;
    local_7e = 6;
    local_40 = 0x12;
    local_3c = 0xfc;
    ClassSendSrbSynchronous(param_1,local_88,lVar3,0xfc);
    uVar7 = local_85 & 0xffffff3f;
    uVar6 = (ulonglong)uVar7;
    if ((uVar7 == 1) || (uVar7 == 0x12)) {
      local_85 = 1;
    }
    if (local_85 == 1) {
      uVar8 = 0;
      if (*(char *)(lVar2 + 0x10) != '\0') {
        uVar6 = 0x48;
        uVar5 = ExAllocatePool2(0x48,0x20,0x65706154);
        uVar8 = uVar5;
        if (uVar5 != 0) {
          uVar6 = param_1;
          uVar7 = ClassModeSense(param_1,uVar5,0x20,0x2a);
          if (uVar7 == 0) {
            uVar6 = param_1;
            uVar7 = ClassModeSense(param_1,uVar5,0x20,0x2a);
          }
          if (uVar7 < 0x1f) {
            ExFreePoolWithTag(uVar5,0);
            uVar8 = 0;
            uVar6 = uVar5;
          }
        }
      }
      if (*(code **)(lVar2 + 0x18) != (code *)0x0) {
        uVar6 = lVar2 + 0xe8;
        (**(code **)(lVar2 + 0x18))(uVar6,lVar3,-(ulonglong)(uVar8 != 0) & uVar8 + 0xc);
      }
      if (uVar8 != 0) {
        ExFreePoolWithTag(uVar8,0);
        uVar6 = uVar8;
      }
    }
    TapeSymbolicNamePersistencePreference(uVar6,0x140005260,1,0x140005230,(char *)(lVar2 + 0xe7));
    if ((*(char *)(lVar2 + 0xe5) == '\0') &&
       (uVar6 = TapeCreateSymbolicName(param_1,*(char *)(lVar2 + 0xe7)), (int)uVar6 < 0)) {
      *(undefined4 *)(lVar1 + 0x24c) = *(undefined4 *)(lVar2 + 0xdc);
    }
    ClassUpdateInformationInRegistry(param_1,"Tape",*(undefined4 *)(lVar1 + 0x24c),lVar3);
    ExFreePoolWithTag(lVar3,0);
    IoSetDeviceInterfaceState(lVar2 + 200,1);
    uVar4 = 0;
  }
  return uVar4;
}



===== TapeStopDevice @ 14000b490 =====

undefined8 TapeStopDevice(void)

{
  return 0;
}



===== TapeSymbolicNamePersistencePreference @ 14000b49c =====

int TapeSymbolicNamePersistencePreference
              (ulonglong param_1,longlong param_2,int param_3,longlong param_4,char *param_5)

{
  longlong lVar1;
  int iVar2;
  ulonglong local_res8;
  int local_res10 [2];
  undefined8 local_88;
  longlong local_80 [5];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_54 = 0;
  local_3c = 0;
  local_88 = 0;
  local_res10[0] = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_80[0] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  if (((param_2 == 0) || (param_4 == 0)) || (param_5 == (char *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    RtlInitUnicodeString(local_80 + 3);
    local_48 = local_80 + 3;
    local_58 = 0x30;
    local_50 = 0;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    iVar2 = ZwCreateKey(&local_88,0x2001f,&local_58,0,0,0,local_res10);
    if (-1 < iVar2) {
      RtlInitUnicodeString(local_80 + 1,param_4);
      if (local_res10[0] == 1) {
        ZwSetValueKey(local_88,local_80 + 1,0,4,&local_res8,4);
        iVar2 = 0;
        *param_5 = (int)local_res8 != 0;
      }
      else if (param_3 == 1) {
        iVar2 = TapeGetValuePartialInfo(local_88,local_80 + 1,local_80,(undefined4 *)0x0);
        lVar1 = local_80[0];
        if (iVar2 < 0) {
          if (iVar2 == -0x3fffffcc) {
            ZwSetValueKey(local_88,local_80 + 1,0,4,&local_res8,4);
            iVar2 = 0;
          }
        }
        else {
          *param_5 = *(int *)(local_80[0] + 0xc) != 0;
        }
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
      }
      else if (param_3 == 2) {
        local_res8 = CONCAT44(local_res8._4_4_,(uint)(*param_5 != '\0'));
        iVar2 = ZwSetValueKey(local_88,local_80 + 1,0,4,&local_res8,4);
      }
      else {
        iVar2 = -0x3ffffff3;
      }
      ZwClose(local_88);
    }
  }
  return iVar2;
}



===== TapeUnload @ 14000b6b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TapeUnload(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  _g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== TapeClassLogicalBlockToPhysicalBlock @ 14000b710 =====

undefined8 TapeClassLogicalBlockToPhysicalBlock(char param_1,uint param_2,uint param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0xb710  6  TapeClassLogicalBlockToPhysicalBlock */
  uVar2 = 0;
  if (param_1 == '\0') {
    param_2 = 0xffffffff;
    goto LAB_14000b81a;
  }
  if ((param_1 == '\x05') || (param_1 == '\x0f')) {
    param_2 = param_2 + 1;
    goto LAB_14000b81a;
  }
  if (param_1 == '\x10') {
    param_2 = param_2 + (param_4 != '\0') + 1;
    goto LAB_14000b81a;
  }
  if (param_1 != '\x11') {
    if (param_1 == '\x12') {
LAB_14000b78d:
      if (param_2 != 0) {
        if (0x200 < param_3) {
          uVar1 = param_3 >> 9;
          if ((param_3 & 0x1ff) != 0) {
            uVar1 = uVar1 + 1;
          }
          param_2 = param_2 * uVar1;
        }
        param_2 = param_2 + (param_2 / 0x34) * 0xc;
      }
      if (param_4 != '\0') {
        param_2 = param_2 + 0x40;
      }
      goto LAB_14000b81a;
    }
    if (param_1 != '\x15') {
      if (param_1 == '\x1f') goto LAB_14000b78d;
      if (param_1 != '\"') goto LAB_14000b81a;
    }
  }
  if (param_2 != 0) {
    if (param_3 == 0x200) {
      uVar2 = param_2 & 1;
      param_2 = param_2 >> 1;
    }
    else if (0x400 < param_3) {
      uVar1 = param_3 >> 10;
      if ((param_3 & 0x3ff) != 0) {
        uVar1 = uVar1 + 1;
      }
      param_2 = param_2 * uVar1;
    }
    param_2 = param_2 + (param_2 / 0xe) * 2;
  }
  uVar1 = param_2 + 0x10;
  if (param_4 == '\0') {
    uVar1 = param_2;
  }
  param_2 = uVar1;
LAB_14000b81a:
  return CONCAT44(uVar2,param_2);
}



===== TapeClassPhysicalBlockToLogicalBlock @ 14000b840 =====

ulonglong TapeClassPhysicalBlockToLogicalBlock(char param_1,uint param_2,uint param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
                    /* 0xb840  8  TapeClassPhysicalBlockToLogicalBlock */
  if (param_1 == '\0') {
    uVar3 = 0xffffffff;
    goto LAB_14000b93a;
  }
  if ((param_1 != '\x05') && (param_1 != '\x0f')) {
    if (param_1 != '\x10') {
      uVar3 = param_2;
      if (param_1 == '\x11') {
LAB_14000b888:
        if ((param_4 != '\0') && (0xf < param_2)) {
          uVar3 = param_2 - 0x10;
        }
        if (uVar3 == 0) goto LAB_14000b93a;
        uVar3 = uVar3 + (uVar3 >> 4) * -2;
        if (param_3 == 0x200) {
          uVar3 = uVar3 * 2;
          goto LAB_14000b93a;
        }
        if (param_3 < 0x401) goto LAB_14000b93a;
        uVar2 = param_3 >> 10;
        uVar1 = param_3 & 0x3ff;
      }
      else {
        if (param_1 != '\x12') {
          if (param_1 != '\x15') {
            if (param_1 == '\x1f') goto LAB_14000b8cf;
            if (param_1 != '\"') goto LAB_14000b93a;
          }
          goto LAB_14000b888;
        }
LAB_14000b8cf:
        if ((param_4 != '\0') && (0x3f < param_2)) {
          uVar3 = param_2 - 0x40;
        }
        if ((uVar3 == 0) || (uVar3 = uVar3 + (uVar3 >> 6) * -0xc, param_3 < 0x201))
        goto LAB_14000b93a;
        uVar2 = param_3 >> 9;
        uVar1 = param_3 & 0x1ff;
      }
      if (uVar1 != 0) {
        uVar2 = uVar2 + 1;
      }
      uVar3 = uVar3 / uVar2;
      goto LAB_14000b93a;
    }
    if (param_4 != '\0') {
      uVar3 = param_2 - 2;
      if (param_2 < 3) {
        uVar3 = 0;
      }
      goto LAB_14000b93a;
    }
  }
  uVar3 = param_2 - 1;
LAB_14000b93a:
  return (ulonglong)uVar3;
}



===== TapeExecuteWmiMethod @ 14000b950 =====

void TapeExecuteWmiMethod(undefined8 param_1,undefined8 param_2)

{
  ClassWmiCompleteRequest(param_1,param_2,0,0,0);
  return;
}



===== TapeQueryWmiDataBlock @ 14000b980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TapeQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,uint param_4,short *param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar4;
  longlong lVar3;
  undefined *puVar5;
  undefined4 uVar6;
  undefined1 auStackY_b8 [32];
  undefined8 local_78;
  short *psStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_78 = 0;
  psStack_70 = (short *)0x0;
  lVar2 = ClassGetVpb();
  if ((lVar2 != 0) && ((*(byte *)(lVar2 + 4) & 1) != 0)) {
    uVar6 = 0;
    iVar1 = -0x7fffffef;
    goto LAB_14000bba8;
  }
  lVar2 = *(longlong *)(lVar4 + 0x60);
  if (param_3 == 0) {
    uVar6 = 0x14;
    if (0x13 < param_4) {
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      iVar1 = TapeWMIControl(param_1,*(undefined **)(lVar2 + 0x48),&local_68);
      if (-1 < iVar1) {
        *(undefined4 *)param_5 = (undefined4)uStack_60;
        *(undefined4 *)(param_5 + 2) = uStack_60._4_4_;
        *(undefined4 *)(param_5 + 4) = local_68._4_4_;
        *(undefined4 *)(param_5 + 6) = (undefined4)local_58;
        *(byte *)(param_5 + 8) = (byte)(local_58._4_4_ >> 0x11) & 1;
        *(undefined1 *)((longlong)param_5 + 0x11) = local_68._1_1_;
        *(undefined1 *)((longlong)param_5 + 0x13) = (undefined1)local_68;
        *(undefined1 *)(param_5 + 9) = local_68._3_1_;
      }
      goto LAB_14000bba8;
    }
  }
  else if (param_3 == 1) {
    uVar6 = 0x20;
    if (0x1f < param_4) {
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      iVar1 = TapeWMIControl(param_1,*(undefined **)(lVar2 + 0x50),&local_68);
      if (-1 < iVar1) {
        *(undefined8 *)(param_5 + 4) = uStack_60;
        *(undefined8 *)param_5 = local_68;
        *(undefined4 *)(param_5 + 8) = (undefined4)local_58;
        *(uint *)(param_5 + 10) = local_58._4_4_;
        *(undefined1 *)(param_5 + 0xc) = (undefined1)uStack_50;
      }
      goto LAB_14000bba8;
    }
  }
  else if (param_3 == 3) {
    uVar6 = 0x204;
    if (0x203 < param_4) {
      puVar5 = *(undefined **)(lVar2 + 0xa8);
      local_78._0_4_ = 3;
LAB_14000bad1:
      uVar6 = 0x204;
      local_78 = CONCAT44(param_4,(undefined4)local_78);
      psStack_70 = param_5;
      iVar1 = TapeWMIControl(param_1,puVar5,&local_78);
      goto LAB_14000bba8;
    }
  }
  else if (param_3 == 4) {
    uVar6 = 0x204;
    if (0x203 < param_4) {
      puVar5 = *(undefined **)(lVar2 + 0xa8);
      local_78._0_4_ = 4;
      goto LAB_14000bad1;
    }
  }
  else {
    if (param_3 != 5) {
      uVar6 = 0;
      iVar1 = -0x3ffffd6b;
      goto LAB_14000bba8;
    }
    uVar6 = 0x40;
    if (0x3f < param_4) {
      memset(param_5,0,0x40);
      RtlStringCchPrintfExW
                (param_5 + 1,(ulonglong)(param_4 >> 1) - 2,(longlong *)0x0,(ulonglong *)0x0,0x600,
                 L"Tape%u",(char)*(undefined4 *)(lVar4 + 0x24c));
      lVar4 = -1;
      do {
        lVar3 = lVar4 + 1;
        lVar2 = lVar4 + 2;
        lVar4 = lVar3;
      } while (param_5[lVar2] != 0);
      iVar1 = 0;
      *param_5 = (short)lVar3 * 2;
      goto LAB_14000bba8;
    }
  }
  iVar1 = -0x3fffffdd;
LAB_14000bba8:
  ClassWmiCompleteRequest(param_1,param_2,iVar1,uVar6);
  return;
}



===== TapeQueryWmiRegInfo @ 14000bbf0 =====

undefined8 TapeQueryWmiRegInfo(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x20;
  return 0;
}



===== TapeSetWmiDataItem @ 14000bc00 =====

void TapeSetWmiDataItem(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xc0000295;
  if (param_3 < 6) {
    uVar1 = 0xc00002c6;
  }
  ClassWmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== TapeWMIControl @ 14000bc38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TapeWMIControl(longlong param_1,undefined *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 auStack_118 [32];
  int local_f8;
  undefined4 local_f0;
  uint *local_e8;
  uint local_d8;
  int local_d4;
  undefined4 local_d0 [2];
  longlong local_c8;
  longlong local_c0;
  code *local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [10];
  char local_9e;
  uint local_9c;
  uint local_98;
  undefined4 local_94;
  longlong local_90;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  lVar5 = *(longlong *)(param_1 + 0x40);
  local_d4 = 0;
  local_c0 = *(longlong *)(lVar5 + 0x60) + 0xe8;
  if (param_2 == (undefined *)0x0) {
    return -0x3ffffd23;
  }
  iVar6 = *(int *)(*(longlong *)(lVar5 + 0x60) + 0x30);
  local_c8 = lVar5;
  local_b8 = (code *)param_2;
  local_b0 = param_3;
  if (iVar6 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = ExAllocatePool2(0x40,iVar6,0x65706154);
  }
  memset(local_a8,0,0x58);
  iVar6 = 0;
  uVar8 = 3;
  do {
    local_94 = *(undefined4 *)(lVar5 + 0x248);
    local_9c = 0;
    local_d8 = 0;
    local_e8 = &local_d8;
    local_f8 = iVar6;
    local_f0 = uVar8;
    iVar2 = (*(code *)param_2)(local_c0,lVar3,param_3,local_a8);
    uVar7 = local_d8 & 0xffff;
    uVar8 = 3;
    local_d0[0] = 3;
    if (iVar2 == 2) {
      local_9e = '\x06';
      local_98 = 0;
      local_58 = 0;
      local_60 = 0;
LAB_14000bd5b:
      if (local_90 == 0) {
LAB_14000bd88:
        uVar4 = 0;
      }
      else {
        if (local_98 == 0) {
          ScsiTapeFreeSrbBuffer((longlong)local_a8);
        }
        if ((local_90 == 0) || ((local_9c & 0x80) == 0)) goto LAB_14000bd88;
        uVar4 = 1;
      }
      while( true ) {
        local_f8 = CONCAT31(local_f8._1_3_,uVar4);
        iVar2 = ClassSendSrbSynchronous(param_1,local_a8,local_90,local_98);
        local_d4 = iVar2;
        if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffffc4)) {
          if (iVar2 != -0x3fffffc4) goto LAB_14000be17;
          if (local_9e == '\n') {
            if (local_98 <= CONCAT11(local_60._7_1_,(undefined1)local_58)) {
              local_d4 = 0;
              goto LAB_14000be17;
            }
          }
        }
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
      }
      if ((local_d8 & 0x20000) == 0) {
        if ((local_d8 & 0x10000) == 0) {
          if (lVar3 != 0) {
            ExFreePoolWithTag(lVar3,0);
          }
          ScsiTapeFreeSrbBuffer((longlong)local_a8);
          return iVar2;
        }
      }
      else {
        ScsiTapeNtStatusToTapeStatus(iVar2,local_d0);
        uVar8 = local_d0[0];
      }
LAB_14000be17:
      lVar5 = local_c8;
    }
    else {
      if (iVar2 != 1) {
        if (iVar2 != 0) {
          ScsiTapeFreeSrbBuffer((longlong)local_a8);
          if (lVar3 != 0) {
            ExFreePoolWithTag(lVar3,0);
          }
          cVar1 = ScsiTapeTapeStatusToNtStatus(iVar2,&local_d4);
          if (cVar1 == '\0') {
            local_d4 = -0x3ffffe7b;
          }
          return local_d4;
        }
        goto LAB_14000bd5b;
      }
      uVar8 = 1;
    }
    iVar6 = iVar6 + 1;
    param_2 = local_b8;
    param_3 = local_b0;
  } while( true );
}



===== TapeWmiFunctionControl @ 14000bec0 =====

void TapeWmiFunctionControl
               (longlong param_1,undefined8 param_2,int param_3,int param_4,char param_5)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    if (param_3 == 2) {
      uVar1 = ClassSetFailurePredictionPoll(*(undefined8 *)(param_1 + 0x40),param_5 != '\0',0xe10);
      goto LAB_14000bf0b;
    }
  }
  else if (param_4 == 1) {
    uVar1 = 0;
    goto LAB_14000bf0b;
  }
  uVar1 = 0xc0000010;
LAB_14000bf0b:
  ClassWmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== entry @ 14000d010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
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



===== DriverEntry @ 14000d078 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== ScsiPortNotification @ 140011000 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xc0aa  1  ScsiPortNotification  (forwarder -> TAPE.TapeClassNotification) */

void ScsiPortNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


