
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



===== ChangerClassAllocatePool @ 1c0001020 =====

void ChangerClassAllocatePool(uint param_1,undefined4 param_2)

{
                    /* 0x1020  1  ChangerClassAllocatePool */
  ExAllocatePoolWithTag(param_1 | 0x400,param_2,0x434d6353);
  return;
}



===== ChangerClassDebugPrint @ 1c0001050 =====

void ChangerClassDebugPrint(void)

{
                    /* 0x1050  2  ChangerClassDebugPrint */
  return;
}



===== ChangerClassDeviceControl @ 1c0001070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ChangerClassDeviceControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong lVar6;
  code *pcVar7;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar3 = *(undefined8 *)(param_1 + 0x40);
  lVar6 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
  if (lVar6 == 0) {
    iVar5 = -0x3ffffff2;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    goto LAB_1c00012dd;
  }
  ClassDisableMediaChangeDetection(uVar3);
  uVar1 = *(uint *)(lVar2 + 0x18);
  if (uVar1 < 0x304021) {
    if (uVar1 == 0x304020) {
      if (*(uint *)(lVar2 + 0x10) < 0x24) goto LAB_1c000127b;
      pcVar7 = *(code **)(lVar6 + 0x60);
    }
    else if (uVar1 == 0x304000) {
      if (*(uint *)(lVar2 + 8) < 0x3c) goto LAB_1c000127b;
      puVar4 = *(undefined8 **)(param_2 + 0x18);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      *(undefined4 *)(puVar4 + 7) = 0;
      pcVar7 = *(code **)(lVar6 + 0x28);
    }
    else if (uVar1 == 0x304004) {
      pcVar7 = *(code **)(lVar6 + 0x30);
    }
    else if (uVar1 == 0x304008) {
      if (*(uint *)(lVar2 + 8) < 0x3d) goto LAB_1c000127b;
      puVar4 = *(undefined8 **)(param_2 + 0x18);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      *(undefined4 *)(puVar4 + 7) = 0;
      *(undefined1 *)((longlong)puVar4 + 0x3c) = 0;
      pcVar7 = *(code **)(lVar6 + 0x38);
    }
    else if (uVar1 == 0x304018) {
      if (*(uint *)(lVar2 + 0x10) < 0x10) goto LAB_1c000127b;
      pcVar7 = *(code **)(lVar6 + 0x50);
    }
    else {
      if (uVar1 != 0x30401c) goto LAB_1c00011d4;
      if (*(uint *)(lVar2 + 0x10) < 0x14) goto LAB_1c000127b;
      pcVar7 = *(code **)(lVar6 + 0x58);
    }
LAB_1c0001286:
    iVar5 = (*pcVar7)(param_1,param_2);
  }
  else {
    if (uVar1 == 0x304024) {
      if (*(uint *)(lVar2 + 0x10) < 0x1c) goto LAB_1c000127b;
      pcVar7 = *(code **)(lVar6 + 0x68);
      goto LAB_1c0001286;
    }
    if (uVar1 == 0x304028) {
      if (7 < *(uint *)(lVar2 + 0x10)) {
        pcVar7 = *(code **)(lVar6 + 0x70);
        goto LAB_1c0001286;
      }
LAB_1c000127b:
      iVar5 = -0x3ffffffc;
    }
    else {
      if (uVar1 == 0x30c010) {
        if (0xb < *(uint *)(lVar2 + 0x10)) {
          pcVar7 = *(code **)(lVar6 + 0x40);
          goto LAB_1c0001286;
        }
        goto LAB_1c000127b;
      }
      if (uVar1 != 0x30c014) {
        if (uVar1 != 0x30c02c) {
LAB_1c00011d4:
          iVar5 = ClassDeviceControl(param_1,param_2);
          ClassEnableMediaChangeDetection(uVar3);
          return iVar5;
        }
        if ((0x33 < *(uint *)(lVar2 + 0x10)) && (0x67 < *(uint *)(lVar2 + 8))) {
          pcVar7 = *(code **)(lVar6 + 0x78);
          goto LAB_1c0001286;
        }
        goto LAB_1c000127b;
      }
      if (*(uint *)(lVar2 + 0x10) < 0x10) goto LAB_1c000127b;
      uVar1 = *(uint *)(*(longlong *)(param_2 + 0x18) + 8);
      if (uVar1 < 0x1a41a42) {
        if ((*(uint *)(lVar2 + 8) < uVar1 * 0x9c) && (*(uint *)(lVar2 + 8) < uVar1 * 100)) {
          iVar5 = -0x3fffffdd;
        }
        else {
          if ((uVar1 * 100 != 0) && (uVar1 * 0x9c != 0)) {
            pcVar7 = *(code **)(lVar6 + 0x48);
            goto LAB_1c0001286;
          }
          iVar5 = -0x3ffffff3;
        }
      }
      else {
        iVar5 = -0x7ffffffb;
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar5;
  ClassEnableMediaChangeDetection(uVar3);
  if ((((iVar5 + 0x3fffff5eU < 2) || (iVar5 == -0x3fffff4b)) || (iVar5 + 0x3fffffeeU < 3)) ||
     (iVar5 == -0x7fffffea)) {
    IoSetHardErrorOrVerifyDevice(param_2,param_1);
  }
LAB_1c00012dd:
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return iVar5;
}



===== ChangerClassError @ 1c0001330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChangerClassError(longlong param_1,longlong param_2,undefined4 *param_3,undefined1 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  lVar4 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
  if (lVar4 != 0) {
    if (*(char *)(param_2 + 3) < '\0') {
      bVar3 = *(byte *)(lVar1 + 2) & 0xf;
      if (bVar3 == 3) {
        *param_4 = 0;
        if ((*(char *)(lVar1 + 0xc) == '0') && (*(char *)(lVar1 + 0xd) == '\x03')) {
          *param_3 = 0x80000027;
        }
      }
      else if (bVar3 == 5) {
        if (*(char *)(lVar1 + 0xc) == '!') {
          if (*(char *)(lVar1 + 0xd) == '\x01') {
            *param_4 = 0;
            *param_3 = 0xc0000285;
          }
        }
        else if (*(char *)(lVar1 + 0xc) == ';') {
          if (*(char *)(lVar1 + 0xd) == '\x0e') {
            *param_4 = 0;
            *param_3 = 0xc0000283;
          }
          else if (*(char *)(lVar1 + 0xd) == '\r') {
            *param_4 = 0;
            *param_3 = 0xc0000284;
          }
        }
      }
      else if ((bVar3 == 6) &&
              ((*(char *)(lVar1 + 0xc) == '(' ||
               ((*(char *)(lVar1 + 0xc) == '?' && (*(char *)(lVar1 + 0xd) == -0x7f)))))) {
        ClassSetMediaChangeState(uVar2,2);
        ClassSetMediaChangeState(uVar2,1);
      }
    }
    bVar3 = KeGetCurrentIrql();
    if ((bVar3 < 2) && (*(code **)(lVar4 + 0x18) != (code *)0x0)) {
      (**(code **)(lVar4 + 0x18))(param_1,param_2,param_3,param_4);
    }
  }
  return;
}



===== ChangerClassFreePool @ 1c00014a0 =====

void ChangerClassFreePool(undefined8 param_1)

{
                    /* 0x14a0  3  ChangerClassFreePool */
  ExFreePoolWithTag(param_1,0);
  return;
}



===== ChangerClassInitialize @ 1c00014c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ChangerClassInitialize(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_res20;
  undefined4 local_198;
  undefined4 local_194;
  int local_190;
  undefined4 local_18c;
  undefined4 local_184;
  code *local_180;
  code *local_178;
  code *local_170;
  undefined8 local_168;
  code *local_160;
  code *local_158;
  code *local_150;
  code *local_140;
  code *local_138;
  undefined4 local_128;
  undefined *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_40;
  code *local_20;
  
                    /* 0x14c0  4  ChangerClassInitialize */
  local_res20 = (undefined8 *)0x0;
  local_194 = 0;
  uVar1 = IoAllocateDriverObjectExtension(param_1,ChangerClassInitialize,0x80,&local_res20);
  if ((int)uVar1 < 0) {
    if ((int)uVar1 != -0x3fffffcb) {
      return uVar1;
    }
    local_res20 = (undefined8 *)IoGetDriverObjectExtension(param_1);
    if (local_res20 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
  }
  uVar1 = param_3[1];
  *local_res20 = *param_3;
  local_res20[1] = uVar1;
  uVar1 = param_3[3];
  local_res20[2] = param_3[2];
  local_res20[3] = uVar1;
  uVar1 = param_3[5];
  local_res20[4] = param_3[4];
  local_res20[5] = uVar1;
  uVar1 = param_3[7];
  local_res20[6] = param_3[6];
  local_res20[7] = uVar1;
  uVar1 = param_3[9];
  local_res20[8] = param_3[8];
  local_res20[9] = uVar1;
  uVar1 = param_3[0xb];
  local_res20[10] = param_3[10];
  local_res20[0xb] = uVar1;
  uVar1 = param_3[0xd];
  local_res20[0xc] = param_3[0xc];
  local_res20[0xd] = uVar1;
  uVar1 = param_3[0xf];
  local_res20[0xe] = param_3[0xe];
  local_res20[0xf] = uVar1;
  memset(&local_198,0,0x188);
  local_198 = 0x188;
  local_190 = (*(code *)param_3[1])();
  local_168 = 0;
  local_190 = local_190 + 0x4f0;
  local_18c = 0x30;
  local_184 = 0x100;
  local_150 = ChangerStartDevice;
  local_128 = 3;
  local_158 = ChangerInitDevice;
  local_140 = ChangerStopDevice;
  local_138 = ChangerRemoveDevice;
  local_40 = ChangerAddDevice;
  local_170 = ChangerClassDeviceControl;
  local_180 = ChangerClassError;
  local_160 = ChangerClassCreateClose;
  local_178 = ChangerReadWriteVerification;
  local_20 = ChangerUnload;
  local_120 = &ChangerWmiFdoGuidList;
  local_118 = ChangerFdoQueryWmiRegInfo;
  local_110 = ChangerFdoQueryWmiDataBlock;
  local_108 = ChangerFdoSetWmiDataBlock;
  local_100 = ChangerFdoSetWmiDataBlock;
  local_f8 = ChangerFdoExecuteWmiMethod;
  local_f0 = ChangerWmiFunctionControl;
  uVar1 = ClassInitialize(param_1,param_2,&local_198);
  return uVar1;
}



===== ChangerClassSendSrbSynchronous @ 1c00016e0 =====

void ChangerClassSendSrbSynchronous(void)

{
                    /* 0x16e0  5  ChangerClassSendSrbSynchronous */
  ClassSendSrbSynchronous();
  return;
}



===== ChangerReadWriteVerification @ 1c0001710 =====

void ChangerReadWriteVerification(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  return;
}



===== RtlStringCchCatExW @ 1c0001728 =====

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



===== RtlStringCchPrintfExA @ 1c0001870 =====

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
      if (*param_6 == '\0') goto LAB_1c0001a26;
      iVar2 = (-(uint)(param_1 != (char *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      _Count = param_2 - 1;
      iVar1 = _vsnprintf(param_1,_Count,param_6,&param_7);
      if (iVar1 < 0) {
LAB_1c00019bc:
        iVar2 = -0x7ffffffb;
LAB_1c00019c1:
        param_1[_Count] = '\0';
      }
      else {
        uVar3 = (ulonglong)iVar1;
        if (_Count < uVar3) goto LAB_1c00019bc;
        if (uVar3 == _Count) goto LAB_1c00019c1;
        _Count = uVar3;
      }
      uVar3 = param_2 - _Count;
      pcVar4 = param_1 + _Count;
      if (-1 < iVar2) {
        if (((param_5 >> 9 & 1) != 0) && (1 < uVar3)) {
          memset(pcVar4 + 1,param_5 & 0xff,uVar3 - 1);
        }
        goto LAB_1c0001a26;
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
LAB_1c0001a26:
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = pcVar4;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar3;
  }
  return iVar2;
}



===== RtlStringCchPrintfExW @ 1c0001a64 =====

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
      if (*param_6 == L'\0') goto LAB_1c0001b5a;
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
LAB_1c0001bc9:
        iVar3 = -0x7ffffffb;
LAB_1c0001bce:
        param_1[_Count] = L'\0';
      }
      else {
        uVar2 = (ulonglong)iVar1;
        if (_Count < uVar2) goto LAB_1c0001bc9;
        if (uVar2 == _Count) goto LAB_1c0001bce;
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
        goto LAB_1c0001b5a;
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
LAB_1c0001b5a:
  if (param_3 != (longlong *)0x0) {
    *param_3 = (longlong)pwVar4;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar2;
  }
  return iVar3;
}



===== RtlStringExHandleOtherFlagsW @ 1c0001c48 =====

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
      goto LAB_1c0001cc0;
    }
    *param_4 = param_1;
    *param_5 = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_1c0001cc0:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  return 0;
}



===== ChangerFdoExecuteWmiMethod @ 1c0001d20 =====

void ChangerFdoExecuteWmiMethod(undefined8 param_1,undefined8 param_2,uint param_3)

{
  ClassWmiCompleteRequest(param_1,param_2,-(uint)(2 < param_3) & 0xc0000295,0,0);
  return;
}



===== ChangerFdoQueryWmiDataBlock @ 1c0001d60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChangerFdoQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,uint param_4,uint *param_5)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined1 auStack_a8 [32];
  undefined1 local_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar4 = 0;
  if (param_3 == 0) {
    local_78 = 0;
    uStack_70 = 0;
    local_48 = 0;
    local_68 = 0;
    uStack_60 = 0;
    uVar4 = 0x1c;
    local_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    uVar1 = 0x1c;
    if (0x1b < param_4) {
      iVar2 = ChangerWMIGetParameters(param_1,&local_78);
      if (-1 < iVar2) {
        *param_5 = (uint)local_78._6_2_;
        param_5[1] = (uint)uStack_70._4_2_;
        param_5[2] = (uint)uStack_70._2_2_;
        param_5[3] = (uint)local_78._4_2_;
        param_5[4] = (uint)uStack_70._6_2_;
        param_5[6] = (uint)uStack_60._2_2_;
        param_5[5] = (uint)(ushort)uStack_70;
      }
      goto LAB_1c0001e6b;
    }
  }
  else {
    if (param_3 != 2) {
      iVar2 = -0x3ffffd6b;
      goto LAB_1c0001e6b;
    }
    lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
    if (lVar3 == 0) {
      iVar2 = -0x3ffffff2;
      goto LAB_1c0001e6b;
    }
    if (*(longlong *)(lVar3 + 0x20) == 0) {
      iVar2 = -0x3ffffffe;
      goto LAB_1c0001e6b;
    }
    uVar4 = 4;
    uVar1 = 4;
    if (3 < param_4) {
      *param_5 = 0;
      iVar2 = (**(code **)(lVar3 + 0x20))(param_1,param_5);
      goto LAB_1c0001e6b;
    }
  }
  uVar4 = uVar1;
  iVar2 = -0x3fffffdd;
LAB_1c0001e6b:
  local_88 = 0;
  ClassWmiCompleteRequest(param_1,param_2,iVar2,uVar4);
  return;
}



===== ChangerFdoQueryWmiRegInfo @ 1c0001eb0 =====

undefined8 ChangerFdoQueryWmiRegInfo(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0x20;
  return 0;
}



===== ChangerFdoSetWmiDataBlock @ 1c0001ec0 =====

void ChangerFdoSetWmiDataBlock(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xc0000295;
  if (param_3 < 3) {
    uVar1 = 0xc00002c6;
  }
  ClassWmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== ChangerWMIGetParameters @ 1c0001ef8 =====

int ChangerWMIGetParameters(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,1,0);
  uVar2 = IoGetAttachedDeviceReference(param_1);
  lVar3 = IoBuildDeviceIoControlRequest(0x304000,uVar2,0,0,param_2,0x3c,0,&local_28,&local_38);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(uVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
  }
  ObfDereferenceObject(uVar2);
  return iVar1;
}



===== ChangerWmiFunctionControl @ 1c0002010 =====

void ChangerWmiFunctionControl(undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ClassWmiCompleteRequest(param_1,param_2,-(uint)(param_4 != 1) & 0xc0000010,0,0);
  return;
}



===== _guard_check_icall @ 1c0002050 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002068 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000208c =====

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



===== wcscmp @ 1c00020f6 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00020f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 1c0002110 =====

/* WARNING: Removing unreachable block (ram,0x0001c000217a) */
/* WARNING: Removing unreachable block (ram,0x0001c0002129) */
/* WARNING: Removing unreachable block (ram,0x0001c000211a) */

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



===== __security_check_cookie @ 1c00021e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002220 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002250 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002280 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002300 =====

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



===== memset @ 1c0002600 =====

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



===== __memset_repmovs @ 1c0002740 =====

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



===== __memset_query @ 1c00027c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002840 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002980 =====

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



===== __memset_spec_plain @ 1c0002a00 =====

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



===== ChangerAddDevice @ 1c0008010 =====

void ChangerAddDevice(ulonglong param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  char local_res18 [16];
  
  local_res18[0] = '\0';
  uVar3 = param_1;
  lVar2 = IoGetConfigurationInformation();
  iVar1 = 1;
  if (*(int *)(lVar2 + 0x24) == 0) {
    ChangerSymbolicNamePersistencePreference(uVar3,0x1c0004160,1,0x1c0004148,local_res18);
    iVar1 = 2;
  }
  ChangerSymbolicNamePersistencePreference(uVar3,0x1c0004210,iVar1,0x1c00041d8,local_res18);
  iVar1 = CreateChangerDeviceObject(param_1,param_2,local_res18[0] == '\0');
  if (-1 < iVar1) {
    *(int *)(lVar2 + 0x24) = *(int *)(lVar2 + 0x24) + 1;
  }
  return;
}



===== ChangerAssignSymbolicLink @ 1c00080b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChangerAssignSymbolicLink
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
  pwVar4 = L"\\Changer%u";
  if (param_3 == '\0') {
    pwVar4 = L"\\MediumChangerDevice%u";
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
      iVar2 = RtlCharToInteger(lStack_168 + 8 + lVar8,10,param_6);
      RtlFreeAnsiString(&local_170);
    }
  }
  IoCreateSymbolicLink(&local_160,&local_150);
  return iVar2;
}



===== ChangerClassCreateClose @ 1c0008350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ChangerClassCreateClose(longlong param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  int *piVar6;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  uVar5 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar4 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
  if (lVar4 == 0) {
    uVar5 = 0xc000000e;
  }
  else {
    uVar3 = (**(code **)(lVar4 + 8))();
    piVar6 = (int *)(lVar2 + (ulonglong)uVar3);
    if (*pcVar1 == '\x02') {
      *piVar6 = 0;
    }
    else if (*pcVar1 == '\0') {
      if (*piVar6 == 0) {
        LOCK();
        *piVar6 = *piVar6 + 1;
        UNLOCK();
      }
      else {
        uVar5 = 0x80000011;
      }
    }
  }
  *(undefined4 *)(param_2 + 0x30) = uVar5;
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return uVar5;
}



===== ChangerCreateNewDeviceSubKey @ 1c000841c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000854b) */

int ChangerCreateNewDeviceSubKey
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
                  (local_c8,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Changer%u",(char)uVar6);
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
        if (0x7ffffffe < uVar6) goto LAB_1c0008569;
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
      goto LAB_1c0008579;
    }
LAB_1c0008569:
    if (uVar6 == 0x7fffffff) {
      iVar2 = -0x3fffffff;
    }
  }
LAB_1c0008579:
  return iVar2;
}



===== ChangerCreateNonPersistentSymbolicName @ 1c0008608 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChangerCreateNonPersistentSymbolicName
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
                (param_4,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Changer%u",(char)uVar6);
    }
    else {
      iVar2 = 0;
      if (uVar6 < 0x7fffffff) {
        lVar7 = 0x40;
LAB_1c00086c6:
        RtlStringCchPrintfExW
                  (local_c8,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"Changer%u",(char)uVar6);
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
            goto LAB_1c00087f1;
          }
        }
        else {
          ZwClose(local_118);
        }
        uVar6 = uVar6 + 1;
        if (0x7ffffffe < uVar6) goto LAB_1c0008779;
        goto LAB_1c00086c6;
      }
LAB_1c0008779:
      if (uVar6 == 0x7fffffff) {
        iVar2 = -0x3fffffff;
      }
    }
  }
LAB_1c00087f1:
  return iVar2;
}



===== ChangerCreateSymbolicName @ 1c0008820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ChangerCreateSymbolicName(longlong param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar6;
  ulonglong uVar7;
  code *pcVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  uint *puVar12;
  longlong lVar13;
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
  uVar10 = 0x80;
  local_1d0 = 0;
  local_1d8 = 0;
  uVar7 = 0;
  local_1b8[1] = 0;
  local_1b8[2] = 0;
  lVar13 = 0;
  bVar16 = false;
  memset(local_138,0,0x80);
  local_1b8[3] = *(longlong *)(param_1 + 0x40);
  pcVar8 = ChangerClassInitialize;
  bVar15 = param_2 == '\0';
  bVar1 = false;
  lVar14 = *(longlong *)(local_1b8[3] + 0x60);
  lVar5 = IoGetDriverObjectExtension();
  if (lVar5 == 0) {
    return 0xc000000e;
  }
  uVar3 = (**(code **)(lVar5 + 8))();
  lVar14 = lVar14 + (ulonglong)uVar3;
  if (param_2 == '\0') {
    puVar12 = (uint *)(lVar14 + 0x20);
    ChangerCreateNonPersistentSymbolicName(0,puVar12,uVar10,local_138);
    RtlInitUnicodeString(local_1b8 + 1,local_138);
    iVar2 = ChangerAssignSymbolicLink
                      ((char)*puVar12,(longlong)(local_1b8 + 1),'\x01',0x16,L"\\DosDevices",
                       lVar14 + 0x24);
    if (iVar2 < 0) {
      return CONCAT44(extraout_var,iVar2);
    }
    *(undefined1 *)(lVar14 + 0x29) = 1;
    *(undefined4 *)(local_1b8[3] + 0x24c) = *(undefined4 *)(lVar14 + 0x24);
    RtlStringCchPrintfExW
              (local_138,0x40,(longlong *)0x0,(ulonglong *)0x0,0x600,L"MediumChangerDevice%u",
               (char)*puVar12);
    RtlInitUnicodeString(local_1b8 + 1,local_138);
    iVar2 = ChangerAssignSymbolicLink
                      ((char)*puVar12,(longlong)(local_1b8 + 1),'\x01',0xe,L"\\Device",0);
    if (iVar2 < 0) {
      return CONCAT44(extraout_var_00,iVar2);
    }
    *(undefined1 *)(lVar14 + 0x28) = 1;
    return CONCAT44(extraout_var_00,iVar2);
  }
  puVar12 = local_1c8;
  uVar6 = ChangerCreateUniqueId(param_1,pcVar8,local_1b8,(int *)puVar12);
  lVar5 = local_1b8[0];
  if ((int)uVar6 < 0) {
    if (local_1b8[0] != 0) {
      ExFreePoolWithTag(local_1b8[0],0);
      lVar5 = 0;
    }
    if ((int)uVar6 != -0x3fffffff) {
      return uVar6 & 0xffffffff;
    }
    bVar1 = true;
  }
  RtlInitUnicodeString(&local_178,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MChgr")
  ;
  local_160 = 0;
  local_158 = &local_178;
  puVar11 = &local_168;
  local_168 = 0x30;
  local_150 = 0x240;
  local_148 = 0;
  uStack_140 = 0;
  uVar3 = ZwOpenKey(&local_1c0,0x2001f);
  uVar6 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0);
    }
  }
  else {
    if (!bVar1) {
      RtlInitUnicodeString(&local_198,L"UIDType");
      RtlInitUnicodeString(&local_188,L"UniqueId");
      uVar6 = uVar7;
      do {
        uVar3 = (uint)uVar7;
        if (lVar13 != 0) {
          ExFreePoolWithTag(lVar13,0);
          lVar13 = 0;
          local_1d0 = 0;
          uVar3 = local_1e4;
        }
        uVar3 = ChangerGetSubKeyByIndex(local_1c0,uVar3,&local_1e0,puVar12,local_b8);
        uVar7 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          if (uVar3 == 0xc000009a) {
            if (lVar5 != 0) {
              ExFreePoolWithTag(lVar5,0);
            }
            uVar6 = 0xc000009a;
            goto LAB_1c0008e9a;
          }
          if (uVar3 != 0x8000001a) {
            uVar6 = uVar7;
          }
LAB_1c0008c1e:
          if (uVar3 == 0x8000001a) goto LAB_1c0008c3b;
        }
        else {
          RtlInitUnicodeString(local_1b8 + 1,local_b8);
          puVar12 = (uint *)0x0;
          uVar4 = ChangerGetValuePartialInfo(local_1e0,&local_198,&local_1d0,(undefined4 *)0x0);
          if (-1 < (int)uVar4) {
            local_1d8 = *(int *)(local_1d0 + 0xc);
            ExFreePoolWithTag(local_1d0,0);
            puVar12 = (uint *)local_1b8;
            local_1d0 = 0;
            uVar4 = ChangerGetValuePartialInfo(local_1e0,&local_188,&local_1d0,puVar12);
            if (-1 < (int)uVar4) {
              bVar16 = false;
              lVar13 = local_1d0;
              if (((local_1c8[0] != 0) && (local_1c8[0] == *(uint *)(local_1d0 + 8))) &&
                 (local_1d8 == 1)) {
                uVar9 = 0;
                if (local_1c8[0] != 0) {
                  do {
                    if (*(char *)(uVar9 + lVar5) != *(char *)(uVar9 + 0xc + local_1d0)) break;
                    uVar4 = (int)uVar9 + 1;
                    uVar9 = (ulonglong)uVar4;
                  } while (uVar4 < local_1c8[0]);
                }
                bVar16 = (uint)uVar9 == local_1c8[0];
              }
              goto LAB_1c0008c1e;
            }
          }
          uVar6 = (ulonglong)uVar4;
          ZwClose(local_1e0);
          lVar13 = local_1d0;
        }
        if (bVar16) goto LAB_1c0008c3b;
        local_1e4 = local_1e4 + 1;
        uVar7 = (ulonglong)local_1e4;
      } while( true );
    }
    local_1e4 = 0;
LAB_1c0008ec9:
    do {
      uVar3 = ChangerCreateNonPersistentSymbolicName(local_1c0,&local_1e4,puVar11,local_138);
      if (-1 < (int)uVar3) {
        RtlInitUnicodeString(local_1b8 + 1,local_138);
        puVar11 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar11 >> 8),bVar15);
        puVar12 = (uint *)(lVar14 + 0x24);
        uVar3 = ChangerAssignSymbolicLink
                          ((char)*(undefined4 *)(lVar14 + 0x20),(longlong)(local_1b8 + 1),bVar15,
                           0x16,L"\\DosDevices",(longlong)puVar12);
        if (-1 < (int)uVar3) {
          puVar11 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar11 >> 8),bVar15);
          *(undefined1 *)(lVar14 + 0x29) = 1;
          uVar3 = ChangerAssignSymbolicLink
                            ((char)*(undefined4 *)(lVar14 + 0x20),(longlong)(local_1b8 + 1),bVar15,
                             0xe,L"\\Device",0);
          uVar6 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            *(undefined1 *)(lVar14 + 0x28) = 1;
            *(uint *)(local_1b8[3] + 0x24c) = *puVar12;
            break;
          }
          if (uVar3 != 0xc0000035) break;
          if (*(char *)(lVar14 + 0x29) != '\0') {
            puVar11 = (undefined4 *)(ulonglong)*puVar12;
            ChangerDeassignSymbolicLink(0x16,0x1c0004290,(char)*puVar12,'\0');
            *(undefined1 *)(lVar14 + 0x29) = 0;
          }
          goto LAB_1c0008ec9;
        }
      }
      uVar6 = (ulonglong)uVar3;
    } while (uVar3 == 0xc0000035);
    if (local_1c0 != 0) {
      ZwClose();
    }
  }
  return uVar6;
LAB_1c0008c3b:
  if (local_1e0 != 0) {
    ZwClose();
  }
  if ((!bVar16) && ((int)uVar6 < 0)) {
    if (lVar13 != 0) {
      ExFreePoolWithTag(lVar13,0);
    }
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0);
    }
LAB_1c0008e9a:
    ZwClose(local_1c0);
    return uVar6;
  }
  local_1e4 = 0x7ffffffe;
  if (!bVar16) goto LAB_1c0008d88;
  do {
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0);
      lVar5 = 0;
    }
    ZwClose(local_1c0);
    if ((int)uVar7 < 0) {
LAB_1c0008d73:
      uVar4 = (uint)uVar6;
      if (((int)uVar7 != -0x3fffffcb) || (bVar16)) goto LAB_1c0008e6d;
    }
    else {
      puVar12 = (uint *)0x16;
      uVar3 = ChangerAssignSymbolicLink
                        ((char)*(undefined4 *)(lVar14 + 0x20),(longlong)(local_1b8 + 1),bVar15,0x16,
                         L"\\DosDevices",lVar14 + 0x24);
      uVar7 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        puVar12 = (uint *)0xe;
        *(undefined2 *)(lVar14 + 0x29) = 0x101;
        *(undefined4 *)(local_1b8[3] + 0x24c) = *(undefined4 *)(lVar14 + 0x24);
        uVar4 = ChangerAssignSymbolicLink
                          ((char)*(undefined4 *)(lVar14 + 0x20),(longlong)(local_1b8 + 1),bVar15,0xe
                           ,L"\\Device",0);
        uVar6 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          *(undefined1 *)(lVar14 + 0x28) = 1;
        }
      }
      uVar4 = (uint)uVar6;
      if (bVar16) goto LAB_1c0008d73;
      if (uVar3 != 0xc0000035) {
        ZwClose(local_1e0);
LAB_1c0008e6d:
        if ((int)uVar7 < 0) {
          return uVar7;
        }
        if ((int)uVar4 < 0) {
          return (ulonglong)uVar4;
        }
        return uVar7;
      }
      ZwDeleteKey();
    }
LAB_1c0008d88:
    uVar3 = ChangerCreateNewDeviceSubKey(local_1c0,&local_1e4,&local_1e0,puVar12,local_138);
    uVar7 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      RtlInitUnicodeString(local_1b8 + 1,local_138);
      local_1d8 = 1;
      puVar12 = (uint *)0x4;
      uVar3 = ZwSetValueKey(local_1e0,&local_198,0);
      if (-1 < (int)uVar3) {
        puVar12 = (uint *)0x3;
        uVar3 = ZwSetValueKey(local_1e0,&local_188,0);
      }
      uVar7 = (ulonglong)uVar3;
      if (lVar13 != 0) {
        ExFreePoolWithTag(lVar13);
        lVar13 = 0;
      }
      if ((int)uVar3 < 0) {
        ZwDeleteKey(local_1e0);
      }
    }
  } while( true );
}



===== ChangerCreateUniqueId @ 1c0009004 =====

undefined8
ChangerCreateUniqueId(longlong param_1,undefined8 param_2,undefined8 *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x208);
  uVar7 = *(uint *)(lVar3 + 0xc);
  if (uVar7 != 0xffffffff) {
    uVar1 = *(uint *)(lVar3 + 0x10);
    if (uVar1 != 0xffffffff) {
      uVar2 = *(uint *)(lVar3 + 0x18);
      if ((((uVar2 != 0xffffffff) && (uVar7 != 0)) && (uVar1 != 0)) && (uVar2 != 0)) {
        uVar5 = 0xffffffffffffffff;
        uVar8 = 0xffffffffffffffff;
        do {
          uVar8 = uVar8 + 1;
        } while (*(char *)(lVar3 + (ulonglong)uVar7 + uVar8) != '\0');
        uVar4 = 0xffffffffffffffff;
        do {
          uVar4 = uVar4 + 1;
        } while (*(char *)(lVar3 + (ulonglong)uVar1 + uVar4) != '\0');
        do {
          uVar5 = uVar5 + 1;
        } while (*(char *)(lVar3 + (ulonglong)uVar2 + uVar5) != '\0');
        uVar7 = (int)uVar5 + (int)uVar4 + (int)uVar8;
        iVar6 = uVar7 + 1;
        _Dst = (void *)ExAllocatePool2(0x40,iVar6,0x434d6353);
        *param_3 = _Dst;
        if (_Dst == (void *)0x0) {
          return 0xc000009a;
        }
        memcpy(_Dst,(void *)((ulonglong)*(uint *)(lVar3 + 0xc) + lVar3),uVar8 & 0xffffffff);
        memcpy((void *)((uVar8 & 0xffffffff) + (longlong)_Dst),
               (void *)((ulonglong)*(uint *)(lVar3 + 0x10) + lVar3),uVar4 & 0xffffffff);
        memcpy((void *)((ulonglong)(uint)((int)uVar8 + (int)uVar4) + (longlong)_Dst),
               (void *)((ulonglong)*(uint *)(lVar3 + 0x18) + lVar3),uVar5 & 0xffffffff);
        *(undefined1 *)((ulonglong)uVar7 + (longlong)_Dst) = 0;
        *param_4 = iVar6;
        return 0;
      }
    }
  }
  *param_3 = 0;
  return 0xc0000001;
}



===== ChangerDeassignSymbolicLink @ 1c0009158 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ChangerDeassignSymbolicLink(uint param_1,longlong param_2,char param_3,char param_4)

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
  pwVar3 = L"\\MediumChangerDevice%u";
  if (param_4 == '\0') {
    pwVar3 = L"\\Changer%u";
  }
  RtlStringCchPrintfExW
            (local_98 + lVar4,0x40 - lVar4,(longlong *)0x0,(ulonglong *)0x0,0x600,pwVar3,param_3);
  RtlInitUnicodeString(&local_a8,local_98);
  IoDeleteSymbolicLink(&local_a8);
  return;
}



===== ChangerGetSubKeyByIndex @ 1c00092a4 =====

int ChangerGetSubKeyByIndex
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
      lVar2 = ExAllocatePool2(0x48,local_res20[0],0x434d6353);
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



===== ChangerGetValuePartialInfo @ 1c0009438 =====

int ChangerGetValuePartialInfo
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
    lVar2 = ExAllocatePool2(0x48,local_28[0],0x434d6353);
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



===== ChangerInitDevice @ 1c0009530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ChangerInitDevice(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
  if (lVar3 == 0) {
    uVar4 = 0xc000000e;
  }
  else {
    lVar5 = ExAllocatePool2(0x48,0x12,0x434d6353);
    if (lVar5 == 0) {
      uVar4 = 0xc000009a;
    }
    else {
      ClassInitializeSrbLookasideList(lVar1,2);
      *(longlong *)(lVar1 + 0x240) = lVar5;
      *(undefined4 *)(lVar1 + 0x248) = 600;
      local_res8[0] = 1;
      uVar2 = ClassGetDescriptor(*(undefined8 *)(lVar1 + 0x10),local_res8,lVar1 + 0x210);
      if ((-1 < (int)uVar2) && (uVar2 = (**(code **)(lVar3 + 0x10))(param_1), -1 < (int)uVar2)) {
        ClassInitializeMediaChangeDetection(lVar1,"Changer");
        lVar5 = *(longlong *)(lVar1 + 0x60);
        uVar2 = (**(code **)(lVar3 + 8))();
        lVar5 = lVar5 + (ulonglong)uVar2;
        RtlInitUnicodeString(lVar5 + 0x10,0);
        uVar4 = IoRegisterDeviceInterface
                          (*(undefined8 *)(lVar1 + 0x200),&GUID_DEVINTERFACE_MEDIUMCHANGER,0,
                           lVar5 + 0x10);
        return uVar4;
      }
      uVar4 = (ulonglong)uVar2;
      ExFreePoolWithTag(lVar5,0);
      *(undefined8 *)(lVar1 + 0x240) = 0;
    }
  }
  return uVar4;
}



===== ChangerRemoveDevice @ 1c00096a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ChangerRemoveDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x60);
  if ((param_2 - 1U & 0xfd) != 0) {
    lVar1 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
    if (lVar1 == 0) {
      return 0xc000000e;
    }
    uVar2 = (**(code **)(lVar1 + 8))();
    if (param_2 == '\x02') {
      if (*(longlong *)(lVar3 + 0x208) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x208),0);
        *(undefined8 *)(lVar3 + 0x208) = 0;
      }
      if (*(longlong *)(lVar3 + 0x210) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x210),0);
        *(undefined8 *)(lVar3 + 0x210) = 0;
      }
      if (*(longlong *)(lVar3 + 0x240) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x240),0);
        *(undefined8 *)(lVar3 + 0x240) = 0;
      }
      ClassDeleteSrbLookasideList(lVar3);
    }
    lVar4 = lVar4 + (uVar2 & 0xffffffff);
    if (*(longlong *)(lVar4 + 0x18) != 0) {
      lVar3 = lVar4 + 0x10;
      IoSetDeviceInterfaceState(lVar3,0);
      RtlFreeUnicodeString(lVar3);
      RtlInitUnicodeString(lVar3,0);
    }
    if (*(char *)(lVar4 + 0x29) != '\0') {
      ChangerDeassignSymbolicLink(0x16,0x1c0004290,(char)*(undefined4 *)(lVar4 + 0x24),'\0');
      *(undefined1 *)(lVar4 + 0x29) = 0;
    }
    if (*(char *)(lVar4 + 0x28) != '\0') {
      ChangerDeassignSymbolicLink
                (0xe,0x1c00042a8,(char)*(undefined4 *)(lVar4 + 0x24),*(char *)(lVar4 + 0x2b) == '\0'
                );
      *(undefined1 *)(lVar4 + 0x28) = 0;
    }
    if (param_2 == '\x02') {
      lVar3 = IoGetConfigurationInformation();
      *(int *)(lVar3 + 0x24) = *(int *)(lVar3 + 0x24) + -1;
    }
  }
  return 0;
}



===== ChangerStartDevice @ 1c0009830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ChangerStartDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
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
  lVar6 = *(longlong *)(lVar1 + 0x60);
  lVar2 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ChangerClassInitialize);
  if (lVar2 == 0) {
    uVar3 = 0xc000000e;
  }
  else {
    uVar5 = (**(code **)(lVar2 + 8))();
    lVar6 = lVar6 + (ulonglong)uVar5;
    lVar2 = ExAllocatePool2(0x48,0xfc,0x434d6353);
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(local_88,0,0x58);
      local_74 = 2;
      local_7e = 6;
      local_40 = 0x12;
      local_3c = 0xfc;
      ClassSendSrbSynchronous(param_1,local_88,lVar2,0xfc);
      uVar5 = local_85 & 0xffffff3f;
      if ((uVar5 == 1) || (uVar5 == 0x12)) {
        local_85 = 1;
      }
      ChangerSymbolicNamePersistencePreference
                ((ulonglong)uVar5,0x1c0004210,1,0x1c00041d8,(char *)(lVar6 + 0x2b));
      if ((*(char *)(lVar6 + 0x29) == '\0') &&
         (uVar4 = ChangerCreateSymbolicName(param_1,*(char *)(lVar6 + 0x2b)), (int)uVar4 < 0)) {
        *(undefined4 *)(lVar1 + 0x24c) = *(undefined4 *)(lVar6 + 0x20);
      }
      ClassUpdateInformationInRegistry(param_1,"Changer",*(undefined4 *)(lVar1 + 0x24c),lVar2);
      ExFreePoolWithTag(lVar2,0);
      if (*(longlong *)(lVar6 + 0x18) != 0) {
        IoSetDeviceInterfaceState(lVar6 + 0x10,1);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== ChangerStopDevice @ 1c0009a10 =====

undefined8 ChangerStopDevice(void)

{
  return 0;
}



===== ChangerSymbolicNamePersistencePreference @ 1c0009a1c =====

int ChangerSymbolicNamePersistencePreference
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
        iVar2 = ChangerGetValuePartialInfo(local_88,local_80 + 1,local_80,(undefined4 *)0x0);
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



===== ChangerUnload @ 1c0009c30 =====

void ChangerUnload(void)

{
  return;
}



===== CreateChangerDeviceObject @ 1c0009c3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0009dec) */

int CreateChangerDeviceObject(undefined8 param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  char *pcVar7;
  longlong lVar8;
  uint uVar9;
  char *pcVar10;
  undefined1 auStackY_e8 [32];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  memset(local_88,0,0x40);
  lVar4 = IoGetAttachedDeviceReference(param_2);
  iVar2 = ClassClaimDevice(lVar4,0);
  if (iVar2 < 0) {
    ObfDereferenceObject(lVar4);
  }
  else {
    pcVar10 = "\\Changer%u";
    uVar3 = 0;
    if (param_3 == '\0') {
      pcVar10 = "\\MediumChangerDevice%u";
    }
    do {
      uVar9 = uVar3;
      pcVar7 = local_88;
      lVar8 = 0x40;
      do {
        if ((lVar8 == 0x39) || (pcVar7[(longlong)"\\Device" - (longlong)local_88] == '\0')) break;
        *pcVar7 = pcVar7[(longlong)"\\Device" - (longlong)local_88];
        pcVar7 = pcVar7 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      pcVar5 = pcVar7 + -1;
      if (lVar8 != 0) {
        pcVar5 = pcVar7;
      }
      *pcVar5 = '\0';
      lVar8 = -1;
      do {
        lVar6 = lVar8;
        lVar8 = lVar6 + 1;
      } while (local_88[lVar6 + 1] != '\0');
      RtlStringCchPrintfExA
                (local_88 + lVar6 + 1,0x40 - (lVar6 + 1),(undefined8 *)0x0,(ulonglong *)0x0,0x600,
                 pcVar10,(char)uVar9);
      iVar2 = ClassCreateDeviceObject(param_1,local_88,param_2);
      lVar8 = lRam0000000000000040;
    } while ((iVar2 == -0x3fffffcb) && (uVar3 = uVar9 + 1, uVar9 + 1 < 0x7fffffff));
    if (-1 < iVar2) {
      uRam0000000000000030 = uRam0000000000000030 | 0x10;
      lVar6 = IoGetDriverObjectExtension(param_1,ChangerClassInitialize);
      if (lVar6 == 0) {
        iVar2 = -0x3ffffff2;
      }
      else {
        lVar1 = *(longlong *)(lVar8 + 0x60);
        uVar3 = (**(code **)(lVar6 + 8))();
        *(undefined4 *)(lVar8 + 600) = 0;
        *(undefined8 *)(lVar8 + 8) = 0;
        *(longlong *)(lVar8 + 0x18) = lVar8;
        *(undefined4 *)(lVar8 + 0x24c) = 0x7fffffff;
        if (uRam0000000000000098 < *(uint *)(lVar4 + 0x98)) {
          uRam0000000000000098 = *(uint *)(lVar4 + 0x98);
        }
        *(undefined8 *)(lVar8 + 0x210) = 0;
        *(undefined8 *)(lVar8 + 0x208) = 0;
        *(undefined4 *)(lVar8 + 0x250) = 8;
        *(undefined8 *)(lVar8 + 0x200) = param_2;
        lVar6 = IoAttachDeviceToDeviceStack(0,param_2);
        *(longlong *)(lVar8 + 0x10) = lVar6;
        if (lVar6 != 0) {
          *(uint *)(lVar1 + (ulonglong)uVar3 + 0x20) = uVar9;
          uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
          ObfDereferenceObject(lVar4);
          return 0;
        }
        iVar2 = -0x3fffffff;
      }
    }
    ObfDereferenceObject(lVar4);
  }
  return iVar2;
}



===== entry @ 1c000b010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== DriverEntry @ 1c000b078 =====

undefined8 DriverEntry(void)

{
  return 0;
}


