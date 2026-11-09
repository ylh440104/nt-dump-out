
===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 180001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ULONG UVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_18002e008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_18002e008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_18002e008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_18002e008 + -4);
  if (DAT_18002e020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_18002e028 = 0;
  uRam000000018002e030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x18000106b;
  UVar3 = EventRegister((LPCGUID)(puVar4 + 0x20),_tlgEnableCallback,&DAT_18002e000,
                        (PREGHANDLE)&DAT_18002e020);
  if (UVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_18002e008;
    *(undefined8 *)(puVar4 + -8) = 0x1800010a1;
    EventSetInformation(DAT_18002e020,2,PTR_DAT_18002e008,uVar1);
  }
  else if (0 < (int)UVar3) {
    UVar3 = UVar3 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1800010b5;
  return UVar3;
}



===== _tlgCreate1Sz_wchar_t @ 1800010c4 =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
    iVar1 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar1 = (int)lVar2 * 2 + 2;
  }
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== VidMessageSlotHandleAndGetNext @ 180001110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
VidMessageSlotHandleAndGetNext
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,HANDLE param_4)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hObject;
  HANDLE pvVar4;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4 [3];
  undefined4 local_d8;
  undefined4 local_d4;
  EVENT_DESCRIPTOR local_d0;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8;
  undefined *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x1110  122  VidMessageSlotHandleAndGetNext */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d8 = param_2;
  local_d4 = param_3;
  if (param_4 == (HANDLE)0x0) {
    pvVar4 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,pvVar4);
      goto LAB_180001232;
    }
  }
  else {
    hObject = param_4;
  }
  iVar2 = NtDeviceIoControlFile(param_1,hObject,0,0);
  if (iVar2 == 0x103) {
    NtWaitForSingleObject(hObject,0,0);
    iVar2 = (int)local_c0;
  }
  if (iVar2 < 0) {
    DVar3 = RtlNtStatusToDosError(iVar2);
    SetLastError(DVar3);
  }
  if ((param_4 == (HANDLE)0x0) && (hObject != (HANDLE)0x0)) {
    CloseHandle(hObject);
  }
  if (iVar2 >= 0) {
    return 1;
  }
LAB_180001232:
  DVar3 = GetLastError();
  if (DVar3 != 0x3e3) {
    DVar3 = GetLastError();
    if (2 < DAT_18002e000) {
      if (((_DAT_18002e010 & 0x100) == 0) || (((uint)DAT_18002e018 & 0x100) != DAT_18002e018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_80 = 0x1f;
        local_88 = "VidMessageSlotHandleAndGetNext";
        local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
        local_68 = &local_e8;
        local_70 = 0x20;
        local_58 = local_e4;
        local_e8 = 0xaae;
        local_48 = "(DWORD) VID_IOCTL_MESSAGE_SLOT_HANDLE_AND_GET_NEXT";
        local_d0.Level = '\x02';
        local_d0.Opcode = '\0';
        local_d0.Task = 0;
        local_a8.Ptr = (ULONGLONG)PTR_DAT_18002e008;
        local_60 = 4;
        local_50 = 4;
        local_40 = 0x33;
        local_d0.Id = 0;
        local_d0.Version = '\0';
        local_d0.Channel = '\v';
        local_d0.Keyword = 0x100;
        local_a8.Size = (ULONG)*(ushort *)PTR_DAT_18002e008;
        local_98 = &DAT_180029ecf;
        local_a8.Reserved = 2;
        local_90 = 0x44;
        local_8c = 1;
        local_e4[1] = 0x524;
        local_e4[0] = DVar3;
        EventWriteTransfer(DAT_18002e020,&local_d0,(LPCGUID)0x0,(LPCGUID)0x0,7,&local_a8);
      }
    }
    SetLastError(DVar3);
  }
  return 0;
}



===== VidGetHvPartitionId @ 180001400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGetHvPartitionId(undefined8 param_1)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [8];
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  char *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x1400  78  VidGetHvPartitionId */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_70 = 0x14;
    local_78 = "VidGetHvPartitionId";
    local_58 = local_b8 + 1;
    local_68 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_48 = local_b8;
    local_38 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGetHvPartitionId) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_60 = 0x20;
    local_b8[1] = 0xbfc;
    local_50 = 4;
    local_40 = 4;
    local_30 = 0x6a;
    local_b8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidCreateMmioGpaRange @ 180001640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateMmioGpaRange
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 *param_5)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  _EVENT_DATA_DESCRIPTOR local_b8 [2];
  char *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x1640  19  VidCreateMmioGpaRange */
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_f0 = 0;
  if (param_5 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateMmioGpaRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x14ad,param_4);
  }
  else {
    uVar5 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_d8 = param_2;
    local_d0 = param_3;
    local_c8 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e8;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_5 = local_f0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_78 = &local_f8;
      local_90 = 0x16;
      local_68 = &local_f4;
      local_98 = "VidCreateMmioGpaRange";
      local_88 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_58 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateMmioGpaRange) | (0x1 << 10)) << 2) | (0) )"
      ;
      local_80 = 0x20;
      local_f8 = 0x14b9;
      local_70 = 4;
      local_60 = 4;
      local_50 = 0x6c;
      local_f4 = DVar2;
      _tlgWriteTransfer_EventWriteTransfer
                ("VidCreateMmioGpaRange",&DAT_180029ec4,uVar4,uVar5,7,local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidAssertVirtualProcessorInterrupt @ 1800018c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidAssertVirtualProcessorInterrupt
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined1 param_5)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined1 local_ac;
  undefined2 local_ab;
  undefined1 local_a9;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x18c0  3  VidAssertVirtualProcessorInterrupt */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_ab = 0;
  local_a9 = 0;
  local_ac = param_5;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  DVar1 = GetLastError();
  if (DVar1 != 0xc0350016) {
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
      local_80 = 0x23;
      local_88 = "VidAssertVirtualProcessorInterrupt";
      local_68 = local_d8 + 1;
      local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_58 = local_d8;
      local_48 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionAssertInterrupt) | (0x1 << 10)) << 2) | (3) )"
      ;
      local_70 = 0x20;
      local_d8[1] = 0x6dc;
      local_60 = 4;
      local_50 = 4;
      local_40 = 0x69;
      local_d8[0] = DVar1;
      _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
    }
    SetLastError(DVar1);
  }
  return 0;
}



===== VidHandleMessageAndGetNextMessage @ 180001af0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint VidHandleMessageAndGetNextMessage
               (char *param_1,uint param_2,longlong *param_3,longlong *param_4,undefined8 param_5,
               char *param_6)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  char *hObject;
  ulonglong uVar4;
  char *pcVar5;
  char **ppcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined1 auStackY_148 [32];
  longlong *local_f8;
  char *local_f0;
  undefined4 local_e8 [2];
  undefined8 local_e0;
  longlong lStack_d8;
  _EVENT_DATA_DESCRIPTOR local_c8 [2];
  char *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  char **local_88;
  undefined8 local_80;
  longlong **local_78;
  undefined8 local_70;
  char **local_68;
  undefined8 local_60;
  ulonglong local_58;
  
                    /* 0x1af0  95  VidHandleMessageAndGetNextMessage */
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  lVar9 = 0;
  local_f8 = param_4;
  local_f0 = param_1;
  if ((param_2 & 3) == 0) {
    SetLastError(0x57);
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char((longlong *)&local_a8,"VidHandleMessageAndGetNextMessage");
      ppcVar6 = &local_98;
      _tlgCreate1Sz_char((longlong *)ppcVar6,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_88 = (char **)local_e8;
      local_e8[0] = 0xa14;
      local_78 = &local_f8;
      local_80 = 4;
      local_68 = &local_f0;
      local_f8 = (longlong *)CONCAT44(local_f8._4_4_,DVar2);
      local_70 = 4;
      local_f0 = (char *)CONCAT44(local_f0._4_4_,param_2);
      local_60 = 4;
      _tlgWriteTransfer_EventWriteTransfer(ppcVar6,&DAT_180029b7a,param_3,param_4,7,local_c8);
    }
    SetLastError(DVar2);
    return 0;
  }
  if (param_3 == (longlong *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidHandleMessageAndGetNextMessage","onecore\\vm\\vid\\dll\\src\\viddll.c",
                     0xa1f,param_4);
    return 0;
  }
  if (((param_2 & 1) != 0) && (param_4 == (longlong *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidHandleMessageAndGetNextMessage","onecore\\vm\\vid\\dll\\src\\viddll.c",
                     0xa2c,param_4);
    return 0;
  }
  local_e0 = 0;
  lStack_d8 = 0;
  if (param_6 == (char *)0x0) {
    uVar8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (char *)0x0) {
      uVar7 = 0x129;
      pcVar5 = "VidIoControl";
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar8);
      goto LAB_180001ca5;
    }
  }
  else {
    hObject = param_6;
  }
  uVar8 = 0;
  uVar7 = 0;
  pcVar5 = local_f0;
  iVar1 = NtDeviceIoControlFile(local_f0,hObject);
  if (iVar1 == 0x103) {
    uVar7 = 0;
    pcVar5 = hObject;
    NtWaitForSingleObject(hObject,0);
    iVar1 = (int)local_e0;
  }
  if (iVar1 < 0) {
    uVar3 = RtlNtStatusToDosError(iVar1);
    pcVar5 = (char *)(ulonglong)uVar3;
    SetLastError(uVar3);
  }
  else {
    lVar9 = lStack_d8;
  }
  uVar3 = (uint)(iVar1 >= 0);
  if ((param_6 == (char *)0x0) && (hObject != (char *)0x0)) {
    CloseHandle(hObject);
    pcVar5 = hObject;
  }
  if (uVar3 != 0) {
    if ((int)lVar9 == 0x102) {
      SetLastError(0x102);
      return 0;
    }
    if ((param_2 & 1) == 0) {
      return uVar3;
    }
    *local_f8 = lVar9;
    *param_3 = lVar9 + 0x140;
    return uVar3;
  }
LAB_180001ca5:
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
    local_a0 = 0x22;
    local_a8 = "VidHandleMessageAndGetNextMessage";
    local_88 = &local_f0;
    local_98 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_78 = &local_f8;
    local_68 = (char **)0x180022d60;
    local_90 = 0x20;
    local_f0 = (char *)CONCAT44(local_f0._4_4_,0xa45);
    local_80 = 4;
    local_f8 = (longlong *)CONCAT44(local_f8._4_4_,DVar2);
    local_70 = 4;
    local_60 = 0x26;
    _tlgWriteTransfer_EventWriteTransfer(pcVar5,&DAT_180029ec4,uVar7,uVar8,7,local_c8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidGetPartitionProperty @ 180001ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetPartitionProperty(HANDLE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x1ef0  83  VidGetPartitionProperty */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c0 = param_2;
  if (param_1 == (HANDLE)0xffffffffffffffff) {
    param_1 = VidpGetGlobalVidObject(0,param_2,param_3,param_4);
  }
  uVar5 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b8;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x18;
    local_88 = "VidGetPartitionProperty";
    local_68 = local_c8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_c8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | ((VidIoctlDualGetPartitionProperty) << 2) | (3) )";
    local_70 = 0x20;
    local_c8[1] = 0xc38;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x59;
    local_c8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidOpenStatisticsHandle @ 180002110 =====

HANDLE VidOpenStatisticsHandle
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HANDLE hSourceHandle;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  HANDLE local_res8;
  
                    /* 0x2110  124  VidOpenStatisticsHandle */
  local_res8 = (HANDLE)0xffffffffffffffff;
  hSourceHandle = VidpGetGlobalVidObject(0,param_2,param_3,param_4);
  if (hSourceHandle == (HANDLE)0xffffffffffffffff) {
    VidlpTraceError0("VidOpenStatisticsHandle","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",
                     0x30e,param_4);
  }
  else {
    hTargetProcessHandle = GetCurrentProcess();
    hSourceProcessHandle = GetCurrentProcess();
    DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,&local_res8,0,0,2);
  }
  return local_res8;
}



===== VidpGetGlobalVidObject @ 1800021b0 =====

HANDLE VidpGetGlobalVidObject(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HANDLE pvVar1;
  
  if (param_1 == 0) {
    pvVar1 = DAT_180032e50;
    if (DAT_180032e50 == (HANDLE)0xffffffffffffffff) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
      if (DAT_180032e50 == (HANDLE)0xffffffffffffffff) {
        DAT_180032e50 = VidpCreateVidObject(L"",param_2,'\0',param_4);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
      pvVar1 = DAT_180032e50;
    }
  }
  else {
    pvVar1 = DAT_180032e58;
    if (DAT_180032e58 == (HANDLE)0xffffffffffffffff) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
      if (DAT_180032e58 == (HANDLE)0xffffffffffffffff) {
        DAT_180032e58 = VidpCreateVidObject(L"",param_2,'\x01',param_4);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
      pvVar1 = DAT_180032e58;
    }
  }
  return pvVar1;
}



===== VidExoControlGpaAccessTracking @ 180002280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoControlGpaAccessTracking
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [6];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x2280  57  VidExoControlGpaAccessTracking */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_b4 = 0;
  local_b8 = param_5;
  uVar4 = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_d0 = param_2;
  local_c8 = param_3;
  local_c0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_e8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_80 = 0x1f;
    local_88 = "VidExoControlGpaAccessTracking";
    local_68 = local_e8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_e8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoControlGpaAccessTracking) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_e8[1] = 0x3f5;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x75;
    local_e8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGetVirtualProcessorRunningStatus @ 1800024b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGetVirtualProcessorRunningStatus(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  undefined4 local_d0;
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x24b0  90  VidGetVirtualProcessorRunningStatus */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x24;
    local_88 = "VidGetVirtualProcessorRunningStatus";
    local_68 = local_c8;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGetVirtualProcessorStatus) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_c8[0] = 0x5b3;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x7b;
    local_d8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidTranslateGvaToGpa @ 1800026c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidTranslateGvaToGpa
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 *param_5,undefined8 *param_6,undefined8 *param_7,undefined8 *param_8,
          undefined8 *param_9,undefined8 *param_10)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_1c8 [32];
  undefined8 *local_178;
  undefined8 *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  _EVENT_DATA_DESCRIPTOR local_c8 [2];
  char *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  undefined8 **local_88;
  undefined8 local_80;
  undefined8 **local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
                    /* 0x26c0  195  VidTranslateGvaToGpa */
  local_58 = __security_cookie ^ (ulonglong)auStackY_1c8;
  local_170 = param_9;
  local_178 = param_10;
  local_e4 = 0;
  uVar5 = param_4;
  local_168 = param_1;
  memset(&local_148,0,0x60);
  local_e8 = param_2;
  local_e0 = param_3;
  local_d8 = param_4;
  if (((((param_5 == (undefined8 *)0x0) || (param_6 == (undefined8 *)0x0)) ||
       (param_7 == (undefined8 *)0x0)) ||
      ((param_8 == (undefined8 *)0x0 || (local_170 == (undefined8 *)0x0)))) ||
     (local_178 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidTranslateGvaToGpa","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1b25,uVar5);
  }
  else {
    uVar5 = 0;
    local_160 = 0;
    uStack_158 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(local_168,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_160;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_5 = local_148;
        param_5[1] = uStack_140;
        param_5[2] = local_138;
        param_5[3] = uStack_130;
        param_5[4] = local_128;
        param_5[5] = uStack_120;
        *param_6 = local_118;
        *param_7 = local_110;
        *param_8 = local_108;
        *local_170 = local_100;
        *local_178 = local_f8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_88 = &local_178;
      local_a0 = 0x15;
      local_78 = &local_170;
      local_a8 = "VidTranslateGvaToGpa";
      local_98 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_68 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTranslateGva) | (0x1 << 10)) << 2) | (3) )"
      ;
      local_90 = 0x20;
      local_178 = (undefined8 *)CONCAT44(local_178._4_4_,0x1b33);
      local_80 = 4;
      local_170 = (undefined8 *)CONCAT44(local_170._4_4_,DVar2);
      local_70 = 4;
      local_60 = 0x66;
      _tlgWriteTransfer_EventWriteTransfer
                ("VidTranslateGvaToGpa",&DAT_180029ec4,uVar4,uVar5,7,local_c8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidVsmCheckGpaPageVtlAccess @ 1800029f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidVsmCheckGpaPageVtlAccess
          (undefined8 param_1,undefined1 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 *param_5)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8;
  undefined2 local_b7;
  undefined1 local_b5;
  undefined4 local_b4;
  undefined8 local_b0;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x29f0  207  VidVsmCheckGpaPageVtlAccess */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b5 = 0;
  local_b7 = 0;
  local_d0 = 0;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = param_2;
  local_b4 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      *param_5 = local_d0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x1c;
    local_88 = "VidVsmCheckGpaPageVtlAccess";
    local_68 = &local_d8;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = &local_d4;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmCheckGpaPageVtlAccess) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_70 = 0x20;
    local_d8 = 0x2989;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x72;
    local_d4 = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidTranslateGpa @ 180002c20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidTranslateGpa(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4,
               undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  char **ppcVar4;
  undefined8 uVar5;
  undefined1 auStackY_178 [32];
  DWORD local_128 [4];
  undefined8 local_118;
  EVENT_DESCRIPTOR local_110;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  _EVENT_DATA_DESCRIPTOR local_c8;
  undefined *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  char *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  DWORD *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
                    /* 0x2c20  194  VidTranslateGpa */
  local_58 = __security_cookie ^ (ulonglong)auStackY_178;
  local_100 = 0;
  uStack_f8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_118 = param_2;
  if ((((param_3 == (undefined8 *)0x0) || (param_4 == (undefined8 *)0x0)) ||
      (param_5 == (undefined8 *)0x0)) || (param_6 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char((longlong *)&local_a8,"VidTranslateGpa");
      ppcVar4 = &local_98;
      _tlgCreate1Sz_char((longlong *)ppcVar4,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_88 = local_128 + 1;
      local_128[1] = 0x1b87;
      local_78 = local_128;
      local_80 = 4;
      local_70 = 4;
      local_128[0] = DVar2;
      _tlgWriteTransfer_EventWriteTransfer(ppcVar4,&DAT_180029bc3,param_3,param_4,6,&local_c8);
    }
    SetLastError(DVar2);
  }
  else {
    uVar5 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      iVar1 = NtDeviceIoControlFile(param_1,hObject,0,0);
      if (iVar1 == 0x103) {
        NtWaitForSingleObject(hObject,0,0);
        iVar1 = (int)local_e0;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_3 = local_100;
        *param_4 = uStack_f8;
        *param_5 = local_f0;
        *param_6 = uStack_e8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_a0 = 0x10;
      local_88 = local_128 + 2;
      local_a8 = "VidTranslateGpa";
      local_78 = local_128;
      local_98 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_68 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTranslateGpa) | (0x1 << 10)) << 2) | (3) )"
      ;
      local_110.Level = '\x02';
      local_110.Opcode = '\0';
      local_110.Task = 0;
      local_c8.Ptr = (ULONGLONG)PTR_DAT_18002e008;
      local_90 = 0x20;
      local_128[2] = 0x1b95;
      local_80 = 4;
      local_70 = 4;
      local_60 = 0x66;
      local_110.Id = 0;
      local_110.Version = '\0';
      local_110.Channel = '\v';
      local_110.Keyword = 0x100;
      local_c8.Size = (ULONG)*(ushort *)PTR_DAT_18002e008;
      local_b8 = &DAT_180029ecf;
      local_c8.Reserved = 2;
      local_b0 = 0x44;
      local_ac = 1;
      local_128[1] = 0x524;
      local_128[0] = DVar2;
      EventWriteTransfer(DAT_18002e020,&local_110,(LPCGUID)0x0,(LPCGUID)0x0,7,&local_c8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMapMemoryBlockPageRangeEx @ 180002ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMapMemoryBlockPageRangeEx
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_168 [32];
  DWORD local_118 [4];
  EVENT_DESCRIPTOR local_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  _EVENT_DATA_DESCRIPTOR local_b8;
  undefined *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  char *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x2ff0  104  VidMapMemoryBlockPageRangeEx */
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_bc = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  if (((param_6 == (undefined8 *)0x0) || (param_7 == (undefined8 *)0x0)) ||
     (param_5 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char((longlong *)&local_98,"VidMapMemoryBlockPageRangeEx");
      _tlgCreate1Sz_char((longlong *)&local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_118;
      local_118[1] = 0x16dc;
      local_78 = local_118 + 1;
      local_70 = 4;
      local_60 = 4;
      local_118[0] = DVar2;
      _tlgWriteTransfer_EventWriteTransfer(&local_b8,&DAT_180029bc3,param_3,param_4,6,&local_b8);
    }
    SetLastError(DVar2);
  }
  else {
    local_c0 = *param_5;
    uVar4 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_d8 = param_2;
    local_d0 = param_3;
    local_c8 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
    }
    else {
      iVar1 = NtDeviceIoControlFile(param_1,hObject,0,0);
      if (iVar1 == 0x103) {
        NtWaitForSingleObject(hObject,0,0);
        iVar1 = (int)local_e8;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_6 = local_f8;
        *param_7 = uStack_f0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_90 = 0x1d;
      local_78 = local_118 + 2;
      local_98 = "VidMapMemoryBlockPageRangeEx";
      local_68 = local_118;
      local_88 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_58 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMapMemoryBlockPageRange) | (0x1 << 10)) << 2) | (3) )"
      ;
      local_108.Level = '\x02';
      local_108.Opcode = '\0';
      local_108.Task = 0;
      local_b8.Ptr = (ULONGLONG)PTR_DAT_18002e008;
      local_80 = 0x20;
      local_118[2] = 0x16f1;
      local_70 = 4;
      local_60 = 4;
      local_50 = 0x71;
      local_108.Id = 0;
      local_108.Version = '\0';
      local_108.Channel = '\v';
      local_108.Keyword = 0x100;
      local_b8.Size = (ULONG)*(ushort *)PTR_DAT_18002e008;
      local_a8 = &DAT_180029ecf;
      local_b8.Reserved = 2;
      local_a0 = 0x44;
      local_9c = 1;
      local_118[1] = 0x524;
      local_118[0] = DVar2;
      EventWriteTransfer(DAT_18002e020,&local_108,(LPCGUID)0x0,(LPCGUID)0x0,7,&local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== _tlgKeywordOn @ 1800033a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  uint uVar1;
  ulonglong in_RAX;
  
  if ((_DAT_18002e010 & 0x100) != 0) {
    uVar1 = (uint)DAT_18002e018 & 0x100;
    in_RAX = (ulonglong)uVar1;
    if (in_RAX == DAT_18002e018) {
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== _tlgWriteTransfer_EventWriteTransfer @ 1800033d0 =====

void _tlgWriteTransfer_EventWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,ULONG param_5
               ,PEVENT_DATA_DESCRIPTOR param_6)

{
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_6->Ptr = (ULONGLONG)PTR_DAT_18002e008;
  param_6->Size = (uint)*(ushort *)PTR_DAT_18002e008;
  param_6[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_6->Reserved = 2;
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  EventWriteTransfer(DAT_18002e020,&local_18,(LPCGUID)0x0,(LPCGUID)0x0,param_5,param_6);
  return;
}



===== VidCreateMemoryBlock @ 180003480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateMemoryBlock(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  _EVENT_DATA_DESCRIPTOR local_b8 [2];
  char *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x3480  17  VidCreateMemoryBlock */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateMemoryBlock","onecore\\vm\\vid\\dll\\src\\viddll.c",0x103b,param_4);
  }
  else {
    uVar5 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c8;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_3 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_78 = &local_d8;
      local_90 = 0x15;
      local_68 = &local_d4;
      local_98 = "VidCreateMemoryBlock";
      local_88 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_58 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateMemoryBlock) | (0x1 << 10)) << 2) | (0) )"
      ;
      local_80 = 0x20;
      local_d8 = 0x1043;
      local_70 = 4;
      local_60 = 4;
      local_50 = 0x6b;
      local_d4 = DVar2;
      _tlgWriteTransfer_EventWriteTransfer
                ("VidCreateMemoryBlock",&DAT_180029ec4,uVar4,uVar5,7,local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidSetMemoryBlockNotificationQueue @ 1800036f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetMemoryBlockNotificationQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x36f0  168  VidSetMemoryBlockNotificationQueue */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_2;
  local_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x23;
    local_88 = "VidSetMemoryBlockNotificationQueue";
    local_68 = local_d8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetMemoryBlockNotificationQueue) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_d8[1] = 0x1610;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x79;
    local_d8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDestroyGpaRange @ 180003900 =====

ulonglong VidDestroyGpaRange(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                            undefined8 param_4)

{
  undefined1 uVar1;
  undefined7 extraout_var;
  ulonglong uVar2;
  
                    /* 0x3900  26  VidDestroyGpaRange */
  uVar1 = VidDestroyGpaRangeInternal(param_1,param_2,0);
  uVar2 = CONCAT71(extraout_var,uVar1);
  if ((int)uVar2 == 0) {
    VidlpTraceError0("VidDestroyGpaRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x159c,param_4);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== VidDestroyGpaRangeInternal @ 180003940 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDestroyGpaRangeInternal(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c4 = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_2;
  local_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x1b;
    local_88 = "VidDestroyGpaRangeInternal";
    local_68 = local_d8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDestroyGpaRange) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_70 = 0x20;
    local_d8[1] = 0x1569;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x69;
    local_d8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidReadWriteMemoryBlockPageRange @ 180003b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidReadWriteMemoryBlockPageRange
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined8 *param_10,int param_11)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  char *hObject;
  ulonglong uVar4;
  wchar_t *pwVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  undefined1 auStackY_178 [32];
  DWORD local_128;
  DWORD local_124;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  _EVENT_DATA_DESCRIPTOR local_c8 [2];
  char *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  DWORD *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
                    /* 0x3b50  142  VidReadWriteMemoryBlockPageRange */
  local_58 = __security_cookie ^ (ulonglong)auStackY_178;
  local_f0 = param_5;
  local_d8 = param_8;
  local_d0 = param_9;
  local_cc = 0;
  local_120 = 0;
  local_e8 = param_6;
  local_e0 = param_7;
  local_108 = param_2;
  local_100 = param_3;
  local_f8 = param_4;
  if (param_11 == 0) {
    iVar9 = 0x22113f;
    iVar8 = 0x22113f;
    uVar7 = 0;
    local_118 = 0;
    uStack_110 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (char *)0x0) {
      bVar1 = false;
      uVar6 = 0x129;
      hObject = "VidIoControl";
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
    }
    else {
      uVar7 = 0;
      uVar6 = 0;
      iVar2 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar2 == 0x103) {
        uVar6 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar2 = (int)local_118;
      }
      if (iVar2 < 0) {
        DVar3 = RtlNtStatusToDosError(iVar2);
        SetLastError(DVar3);
      }
      bVar1 = iVar2 >= 0;
      CloseHandle(hObject);
      if (bVar1) goto LAB_180003cce;
    }
    GetLastError();
    DVar3 = GetLastError();
    iVar8 = iVar9;
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      local_88 = &local_128;
      local_128 = 0x18f6;
      local_78 = &local_124;
      local_124 = DVar3;
LAB_180003e97:
      local_68 = "ioControlCode";
      local_a8 = "VidReadWriteMemoryBlockPageRange";
      local_a0 = 0x21;
      local_98 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_90 = 0x20;
      local_80 = 4;
      local_70 = 4;
      local_60 = 0xe;
      _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar6,uVar7,7,local_c8);
      iVar8 = iVar9;
    }
  }
  else {
    iVar9 = 0x2211ef;
    iVar8 = 0x2211ef;
    uVar7 = 0;
    local_118 = 0;
    uStack_110 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (char *)0x0) {
      bVar1 = false;
      uVar6 = 0x129;
      hObject = "VidIoControl";
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
    }
    else {
      uVar7 = 0;
      uVar6 = 0;
      iVar2 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar2 == 0x103) {
        uVar6 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar2 = (int)local_118;
      }
      if (iVar2 < 0) {
        DVar3 = RtlNtStatusToDosError(iVar2);
        SetLastError(DVar3);
      }
      bVar1 = iVar2 >= 0;
      CloseHandle(hObject);
      if (bVar1) goto LAB_180003cce;
    }
    GetLastError();
    DVar3 = GetLastError();
    iVar8 = iVar9;
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      local_88 = &local_124;
      local_124 = 0x18ec;
      local_78 = &local_128;
      local_128 = DVar3;
      goto LAB_180003e97;
    }
  }
  SetLastError(DVar3);
LAB_180003cce:
  if (bVar1) {
    if (param_10 != (undefined8 *)0x0) {
      if (iVar8 == 0x22113f) {
        param_6 = local_120;
      }
      *param_10 = param_6;
    }
  }
  else {
    DVar3 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char((longlong *)&local_a8,"VidReadWriteMemoryBlockPageRange");
      _tlgCreate1Sz_char((longlong *)&local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_88 = &local_128;
      local_128 = 0x18ff;
      pwVar5 = L"VID_IOCTL_READ_MEMORY_BLOCK_PAGE_RANGE";
      local_78 = &local_124;
      local_80 = 4;
      local_70 = 4;
      if (iVar8 != 0x22113f) {
        pwVar5 = L"VID_IOCTL_WRITE_MEMORY_BLOCK_PAGE_RANGE";
      }
      local_124 = DVar3;
      _tlgCreate1Sz_wchar_t((longlong *)&local_68,pwVar5);
      _tlgWriteTransfer_EventWriteTransfer(local_c8,&DAT_180029b29,uVar6,uVar7,7,local_c8);
    }
    SetLastError(DVar3);
    if (param_10 != (undefined8 *)0x0) {
      *param_10 = 0;
    }
  }
  return bVar1;
}



===== VidDestroyMemoryBlock @ 180004050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDestroyMemoryBlock(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  char *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x4050  28  VidDestroyMemoryBlock */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_70 = 0x16;
    local_78 = "VidDestroyMemoryBlock";
    local_58 = local_b8 + 1;
    local_68 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_48 = local_b8;
    local_38 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDestroyMemoryBlock) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_60 = 0x20;
    local_b8[1] = 0x1079;
    local_50 = 4;
    local_40 = 4;
    local_30 = 0x6c;
    local_b8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidExoMapGpaRange @ 180004270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoMapGpaRange(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [6];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x4270  60  VidExoMapGpaRange */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_b8 = param_5;
  local_b0 = param_6;
  local_ac = param_7;
  uVar4 = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_d0 = param_2;
  local_c8 = param_3;
  local_c0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_e8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_80 = 0x12;
    local_88 = "VidExoMapGpaRange";
    local_68 = local_e8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_e8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoMapGpaRange) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_e8[1] = 0x386;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x68;
    local_e8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidCreateVaGpaRange @ 1800044a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateVaGpaRange(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  _EVENT_DATA_DESCRIPTOR local_b8 [2];
  char *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x44a0  22  VidCreateVaGpaRange */
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_f0 = 0;
  if (param_6 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateVaGpaRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x27e6,param_4);
  }
  else {
    local_c0 = param_5;
    *param_6 = 0xffffffffffffffff;
    uVar5 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_d8 = param_2;
    local_d0 = param_3;
    local_c8 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e8;
      }
      if (iVar1 < 0) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (iVar1 >= 0) {
        *param_6 = local_f0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_78 = &local_f8;
      local_90 = 0x14;
      local_68 = &local_f4;
      local_98 = "VidCreateVaGpaRange";
      local_88 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_58 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateVaGpaRange) | (0x1 << 10)) << 2) | (0) )"
      ;
      local_80 = 0x20;
      local_f8 = 0x27f5;
      local_70 = 4;
      local_60 = 4;
      local_50 = 0x6a;
      local_f4 = DVar2;
      _tlgWriteTransfer_EventWriteTransfer
                ("VidCreateVaGpaRange",&DAT_180029ec4,uVar4,uVar5,7,local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetVirtualProcessorState @ 180004730 =====

void VidGetVirtualProcessorState
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4,
               undefined8 param_5)

{
                    /* 0x4730  91  VidGetVirtualProcessorState */
  VidGetVirtualProcessorStateEx(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



===== VidGetVirtualProcessorStateEx @ 180004760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetVirtualProcessorStateEx
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined1 param_5,undefined8 param_6)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [3];
  undefined4 local_dc;
  undefined8 local_d8;
  undefined1 local_d0;
  undefined4 local_cf;
  undefined2 local_cb;
  undefined1 local_c9;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x4760  92  VidGetVirtualProcessorStateEx */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_cf = 0;
  local_c8 = param_6;
  local_cb = 0;
  local_c9 = 0;
  local_d0 = param_5;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_e8[2] = param_2;
  local_dc = param_3;
  local_d8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (iVar1 < 0) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (iVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x1e;
    local_88 = "VidGetVirtualProcessorStateEx";
    local_68 = local_e8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_e8;
    local_48 = 
    "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGetVirtualProcessorState) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_70 = 0x20;
    local_e8[1] = 0x62a;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x7a;
    local_e8[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetPartitionProperty @ 1800049a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetPartitionProperty(HANDLE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x49a0  172  VidSetPartitionProperty */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  if (param_1 == (HANDLE)0xffffffffffffffff) {
    param_1 = VidpGetGlobalVidObject(0,param_2,param_3,param_4);
  }
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_80 = 0x18;
    local_88 = "VidSetPartitionProperty";
    local_68 = local_d8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetPartitionProperty) | (0x1 << 10)) << 2) | (3) )"
    ;
    local_70 = 0x20;
    local_d8[1] = 0xc74;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x6e;
    local_d8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoInstallIntercept @ 180004bc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoInstallIntercept(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  DWORD DVar1;
  DWORD dwErrCode;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [7];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x4bc0  59  VidExoInstallIntercept */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = *param_4;
  local_bc = 0;
  local_b4 = 0;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_d8[6] = param_3;
  local_b8 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if ((int)DVar1 < 0) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if ((int)DVar1 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_80 = 0x17;
    local_88 = "VidExoInstallIntercept";
    local_68 = local_d8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoInstallIntercept) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_d8[1] = 0x35d9;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x6d;
    local_d8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidQueryVaGpaRangeWorkingSetInfo @ 180004de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidQueryVaGpaRangeWorkingSetInfo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  char *hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x4de0  139  VidQueryVaGpaRangeWorkingSetInfo */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar3 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    local_80 = 0x21;
    local_88 = "VidQueryVaGpaRangeWorkingSetInfo";
    local_68 = local_d8 + 1;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d8;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionQueryVaGpaRangeWorkingSetInfo) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_d8[1] = 0x2fd1;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x77;
    local_d8[0] = DVar1;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar3,uVar4,7,local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidStopVirtualProcessor @ 180004fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidStopVirtualProcessor(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b8;
  undefined4 local_b4;
  undefined4 local_b0 [2];
  undefined8 local_a8;
  undefined8 uStack_a0;
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  char *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x4fe0  190  VidStopVirtualProcessor */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  DVar2 = GetLastError();
  if (DVar2 != 0xc037001c) {
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_70 = 0x18;
      local_78 = "VidStopVirtualProcessor";
      local_58 = local_b0;
      local_68 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_48 = &local_b8;
      local_38 = 
      "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionStopVirtualProcessor) | (0x1 << 10)) << 2) | (0) )"
      ;
      local_60 = 0x20;
      local_b0[0] = 0x582;
      local_50 = 4;
      local_40 = 4;
      local_30 = 0x76;
      local_b8 = DVar2;
      _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_98);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMessageSlotMap @ 1800051f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMessageSlotMap(undefined8 param_1,undefined8 *param_2,undefined4 param_3)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x51f0  123  VidMessageSlotMap */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c8 = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_2 = local_c8;
      *(undefined4 *)(param_2 + 1) = param_3;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x12;
    local_88 = "VidMessageSlotMap";
    local_68 = &local_d4;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = local_d0;
    local_48 = 
    "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMessageSlotMap) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_d4 = 0xae4;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x70;
    local_d0[0] = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidExoAccessVaFault @ 180005420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
VidExoAccessVaFault(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
                   uint param_5)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hObject;
  undefined8 uVar4;
  undefined1 auStackY_148 [32];
  undefined4 local_f4;
  DWORD local_f0 [2];
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  EVENT_DESCRIPTOR local_d0;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8;
  undefined *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x5420  54  VidExoAccessVaFault */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d8 = (ulonglong)param_5;
  uStack_e0 = (ulonglong)CONCAT14(param_4,param_3);
  uVar4 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_e8 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    iVar2 = NtDeviceIoControlFile(param_1,hObject,0,0);
    if (iVar2 == 0x103) {
      NtWaitForSingleObject(hObject,0,0);
      iVar2 = (int)local_c0;
    }
    if (iVar2 < 0) {
      DVar3 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar3);
    }
    CloseHandle(hObject);
    if (iVar2 >= 0) {
      return 1;
    }
  }
  GetLastError();
  DVar3 = GetLastError();
  if (2 < DAT_18002e000) {
    if (((_DAT_18002e010 & 0x100) == 0) || (((uint)DAT_18002e018 & 0x100) != DAT_18002e018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_80 = 0x14;
      local_88 = "VidExoAccessVaFault";
      local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_68 = &local_f4;
      local_70 = 0x20;
      local_58 = local_f0;
      local_f4 = 0x3145;
      local_48 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoAccessFault) | (0x1 << 10)) << 2) | (3) )"
      ;
      local_d0.Level = '\x02';
      local_d0.Opcode = '\0';
      local_d0.Task = 0;
      local_a8.Ptr = (ULONGLONG)PTR_DAT_18002e008;
      local_60 = 4;
      local_50 = 4;
      local_40 = 0x68;
      local_d0.Id = 0;
      local_d0.Version = '\0';
      local_d0.Channel = '\v';
      local_d0.Keyword = 0x100;
      local_a8.Size = (ULONG)*(ushort *)PTR_DAT_18002e008;
      local_98 = &DAT_180029ecf;
      local_a8.Reserved = 2;
      local_90 = 0x44;
      local_8c = 1;
      local_f0[0] = DVar3;
      EventWriteTransfer(DAT_18002e020,&local_d0,(LPCGUID)0x0,(LPCGUID)0x0,7,&local_a8);
    }
  }
  SetLastError(DVar3);
  return 0;
}



===== VidUnmapMemoryBlockPageRange @ 1800056f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
VidUnmapMemoryBlockPageRange
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hObject;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  longlong local_c8;
  EVENT_DESCRIPTOR local_c0;
  undefined8 local_b0;
  undefined8 uStack_a8;
  _EVENT_DATA_DESCRIPTOR local_98;
  undefined *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x56f0  203  VidUnmapMemoryBlockPageRange */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  if (param_2 == -1) {
    SetLastError(0x57);
    VidlpTraceError0("VidUnmapMemoryBlockPageRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x177c,
                     param_4);
  }
  else {
    uVar4 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    local_c8 = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
    }
    else {
      iVar2 = NtDeviceIoControlFile(param_1,hObject,0,0);
      if (iVar2 == 0x103) {
        NtWaitForSingleObject(hObject,0,0);
        iVar2 = (int)local_b0;
      }
      if (iVar2 < 0) {
        DVar3 = RtlNtStatusToDosError(iVar2);
        SetLastError(DVar3);
      }
      CloseHandle(hObject);
      if (iVar2 >= 0) {
        return 1;
      }
    }
    GetLastError();
    DVar3 = GetLastError();
    if (2 < DAT_18002e000) {
      if (((_DAT_18002e010 & 0x100) == 0) || (((uint)DAT_18002e018 & 0x100) != DAT_18002e018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_70 = 0x1d;
        local_78 = "VidUnmapMemoryBlockPageRange";
        local_68 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
        local_58 = &local_d4;
        local_60 = 0x20;
        local_48 = local_d0;
        local_d4 = 0x178a;
        local_38 = 
        "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionUnmapMemoryBlockPageRange) | (0x1 << 10)) << 2) | (3) )"
        ;
        local_c0.Level = '\x02';
        local_c0.Opcode = '\0';
        local_c0.Task = 0;
        local_98.Ptr = (ULONGLONG)PTR_DAT_18002e008;
        local_50 = 4;
        local_40 = 4;
        local_30 = 0x73;
        local_c0.Id = 0;
        local_c0.Version = '\0';
        local_c0.Channel = '\v';
        local_c0.Keyword = 0x100;
        local_98.Size = (ULONG)*(ushort *)PTR_DAT_18002e008;
        local_88 = &DAT_180029ecf;
        local_98.Reserved = 2;
        local_80 = 0x44;
        local_7c = 1;
        local_d0[0] = DVar3;
        EventWriteTransfer(DAT_18002e020,&local_c0,(LPCGUID)0x0,(LPCGUID)0x0,7,&local_98);
      }
    }
    SetLastError(DVar3);
  }
  return 0;
}



===== VidDmBalloon @ 1800059f0 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmBalloon(undefined8 param_1,void *param_2,uint param_3,undefined8 *param_4,undefined4 *param_5,
            undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined1 auStackY_1148 [32];
  undefined4 local_10f8;
  DWORD local_10f4;
  undefined8 local_10f0;
  undefined8 uStack_10e8;
  undefined8 local_10e0;
  undefined8 uStack_10d8;
  undefined8 local_10d0;
  undefined1 local_10c8 [4096];
  uint local_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  undefined8 uStack_40;
  
                    /* 0x59f0  37  VidDmBalloon */
  uStack_40 = 0x180005a0d;
  local_48 = __security_cookie ^ (ulonglong)auStackY_1148;
  puVar5 = param_4;
  memset(local_10c8,0,0x1008);
  local_10d0 = 0;
  local_10e0 = 0;
  uStack_10d8 = 0;
  if ((((param_2 == (void *)0x0) || (0x200 < param_3)) || (param_4 == (undefined8 *)0x0)) ||
     ((param_5 == (undefined4 *)0x0 || (param_6 == (undefined8 *)0x0)))) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmBalloon","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1c63,puVar5);
  }
  else {
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    memcpy(local_10c8,param_2,(ulonglong)param_3 << 3);
    uVar6 = 0;
    local_10f0 = 0;
    uStack_10e8 = 0;
    local_c8 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_10f0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = local_10e0;
        *param_5 = (undefined4)uStack_10d8;
        *param_6 = local_10d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidDmBalloon");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_78 = &local_10f8;
      local_10f8 = 0x1c74;
      local_68 = &local_10f4;
      local_70 = 4;
      local_60 = 4;
      local_10f4 = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmBalloon) | (0x1 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDllStatsPartitionSetup @ 180005cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidDllStatsPartitionSetup
               (undefined8 *param_1,wchar_t *param_2,ulonglong param_3,undefined8 param_4)

{
  undefined1 uVar1;
  int iVar2;
  DWORD dwErrCode;
  longlong lVar3;
  longlong *plVar4;
  undefined7 extraout_var;
  char *pcVar5;
  ulonglong *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 auStack_d8 [48];
  undefined8 local_a8;
  undefined2 *puStack_a0;
  ulonglong local_98 [2];
  undefined2 local_88;
  undefined8 local_86;
  undefined8 uStack_7e;
  undefined8 local_76;
  undefined8 uStack_6e;
  undefined8 local_66;
  undefined8 uStack_5e;
  undefined4 local_56;
  undefined4 uStack_52;
  undefined4 uStack_4e;
  undefined4 uStack_4a;
  undefined8 local_46;
  undefined2 local_3e;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a8 = 0;
  puStack_a0 = (undefined2 *)0x0;
  local_98[0] = 0;
  local_98[1] = 0;
  uVar8 = param_3;
  AcquireSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (*(short *)((longlong)param_1 + lVar3 * 2) != 0);
  if (lVar3 == 0x24) {
    local_86 = *param_1;
    uStack_7e = param_1[1];
    puVar6 = local_98;
    local_76 = param_1[2];
    uStack_6e = param_1[3];
    local_88 = 0x7b;
    local_3e = 0x7d;
    puStack_a0 = &local_88;
    local_66 = param_1[4];
    uStack_5e = param_1[5];
    local_a8 = CONCAT44(local_a8._4_4_,0x4c004c);
    local_56 = *(undefined4 *)(param_1 + 6);
    uStack_52 = *(undefined4 *)((longlong)param_1 + 0x34);
    uStack_4e = *(undefined4 *)(param_1 + 7);
    uStack_4a = *(undefined4 *)((longlong)param_1 + 0x3c);
    local_46 = param_1[8];
    iVar2 = RtlGUIDFromString(&local_a8);
    if (iVar2 < 0) {
      uVar9 = 0x12d;
      pcVar5 = "onecore\\vm\\vid\\dll\\src\\viddllstats.c";
      VidlpTraceError0("VidDllStatsPartitionSetup","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x12d
                       ,param_4);
    }
    else {
      plVar4 = VidDllPartitionContextGet(param_3,puVar6,uVar8,param_4);
      if (plVar4 != (longlong *)0x0) {
        uVar8 = local_98[0] & 0xffffffff;
        lVar3 = VmPerfCreateInstance(DAT_180032df8,puVar6,param_2,(undefined4)local_98[0]);
        plVar4[4] = lVar3;
        if (lVar3 == 0) {
          dwErrCode = GetLastError();
          uVar9 = 0x151;
        }
        else {
          DAT_180032e00 = lVar3;
          uVar1 = VidDllStatspMapPartition(param_3,plVar4 + 5,(undefined4 *)(plVar4 + 6),uVar8);
          if ((int)CONCAT71(extraout_var,uVar1) != 0) {
            uVar7 = 1;
            if (1 < *(uint *)(plVar4 + 6)) {
              do {
                if ((undefined8 *)plVar4[4] != (undefined8 *)0x0) {
                  PerfSetCounterRefValue
                            (DAT_180032df8,*(undefined8 *)plVar4[4],uVar7,
                             plVar4[5] + (ulonglong)uVar7 * 8);
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 < *(uint *)(plVar4 + 6));
            }
            dwErrCode = 0;
            ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
            goto LAB_180005f4f;
          }
          dwErrCode = GetLastError();
          uVar9 = 0x15d;
        }
        pcVar5 = "onecore\\vm\\vid\\dll\\src\\viddllstats.c";
        VidlpTraceError0("VidDllStatsPartitionSetup","onecore\\vm\\vid\\dll\\src\\viddllstats.c",
                         uVar9,uVar8);
        ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
        if (dwErrCode != 0) {
          VidDllStatsPartitionTeardown(param_3,pcVar5,uVar9,uVar8);
        }
        goto LAB_180005f4f;
      }
      uVar9 = 0x135;
      pcVar5 = "onecore\\vm\\vid\\dll\\src\\viddllstats.c";
      VidlpTraceError0("VidDllStatsPartitionSetup","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x135
                       ,param_4);
    }
  }
  else {
    uVar9 = 0x11f;
    pcVar5 = "onecore\\vm\\vid\\dll\\src\\viddllstats.c";
    VidlpTraceError0("VidDllStatsPartitionSetup","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x11f,
                     param_4);
  }
  dwErrCode = 0x57;
  ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  VidDllStatsPartitionTeardown(param_3,pcVar5,uVar9,param_4);
LAB_180005f4f:
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



===== VidDllStatsGetPartitionCounters @ 180005fa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
VidDllStatsGetPartitionCounters
          (ulonglong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  uint uVar1;
  DWORD dwErrCode;
  longlong *plVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  byte *pbVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_c8 [32];
  DWORD local_98;
  DWORD local_94 [3];
  _EVENT_DATA_DESCRIPTOR local_88 [2];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined8 local_40;
  DWORD *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x5fa0  34  VidDllStatsGetPartitionCounters */
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar6 = 0x80004005;
  uVar4 = param_2;
  lVar8 = param_3;
  lVar9 = param_4;
  AcquireSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  if (DAT_180032de0 == '\0') {
    dwErrCode = GetLastError();
    if (2 < DAT_18002e000) {
      uVar3 = _tlgKeywordOn();
      if ((char)uVar3 != '\0') {
        _tlgCreate1Sz_char(local_68,"VidDllStatsGetPartitionCounters");
        plVar2 = local_58;
        _tlgCreate1Sz_char(plVar2,"onecore\\vm\\vid\\dll\\src\\viddllstats.c");
        local_48 = &local_98;
        local_98 = 0x1df;
        pbVar5 = &DAT_180029e83;
        local_38 = local_94;
        local_94[0] = dwErrCode;
LAB_180006178:
        local_40 = 4;
        local_30 = 4;
        _tlgWriteTransfer_EventWriteTransfer(plVar2,pbVar5,lVar8,lVar9,6,local_88);
      }
    }
  }
  else {
    plVar2 = VidDllPartitionContextGet(param_1,uVar4,lVar8,lVar9);
    if ((plVar2 != (longlong *)0x0) && (plVar2[5] != 0)) {
      for (uVar7 = 0; uVar7 < (uint)param_2; uVar7 = uVar7 + 1) {
        uVar1 = *(uint *)(param_3 + (ulonglong)uVar7 * 4);
        if (*(uint *)(plVar2 + 6) <= uVar1) {
          VidlpTraceError0("VidDllStatsGetPartitionCounters",
                           "onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x1f1,0);
          goto LAB_180006034;
        }
        *(undefined8 *)(param_4 + (ulonglong)uVar7 * 8) =
             *(undefined8 *)(plVar2[5] + (ulonglong)uVar1 * 8);
      }
      uVar6 = 0;
      goto LAB_180006034;
    }
    dwErrCode = GetLastError();
    if (2 < DAT_18002e000) {
      uVar3 = _tlgKeywordOn();
      if ((char)uVar3 != '\0') {
        _tlgCreate1Sz_char(local_68,"VidDllStatsGetPartitionCounters");
        plVar2 = local_58;
        _tlgCreate1Sz_char(plVar2,"onecore\\vm\\vid\\dll\\src\\viddllstats.c");
        local_48 = local_94;
        local_94[0] = 0x1e6;
        pbVar5 = &DAT_180029e42;
        local_38 = &local_98;
        local_98 = dwErrCode;
        goto LAB_180006178;
      }
    }
  }
  SetLastError(dwErrCode);
LAB_180006034:
  ReleaseSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  return uVar6;
}



===== VidDllPartitionContextGet @ 1800061b0 =====

longlong *
VidDllPartitionContextGet
          (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = DAT_180032de8;
  if ((DAT_180032df0 & 1) != 0) {
    if (DAT_180032de8 == (longlong *)0x0) goto LAB_180006225;
    plVar1 = (longlong *)((ulonglong)DAT_180032de8 ^ 0x180032de8);
  }
  if (plVar1 != (longlong *)0x0) {
    do {
      if ((ulonglong)plVar1[3] < param_1) {
        plVar2 = (longlong *)plVar1[1];
        if (((DAT_180032df0 & 1) != 0) && (plVar2 != (longlong *)0x0)) goto LAB_180006220;
LAB_1800061e7:
        plVar1 = plVar2;
      }
      else {
        if ((ulonglong)plVar1[3] <= param_1) break;
        plVar2 = (longlong *)*plVar1;
        if (((DAT_180032df0 & 1) == 0) || (plVar2 == (longlong *)0x0)) goto LAB_1800061e7;
LAB_180006220:
        plVar1 = (longlong *)((ulonglong)plVar1 ^ (ulonglong)plVar2);
      }
    } while (plVar1 != (longlong *)0x0);
    if (plVar1 != (longlong *)0x0) {
      return plVar1;
    }
  }
LAB_180006225:
  VidlpTraceError0("VidDllPartitionContextGet","onecore\\vm\\vid\\dll\\src\\viddllpartition.c",0x158
                   ,param_4);
  return (longlong *)0x0;
}



===== VidDllStatspMapPartition @ 180006250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDllStatspMapPartition
          (undefined8 param_1,undefined8 *param_2,undefined4 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  uStack_c8 = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidDllStatspMapPartition","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0xac,
                     param_4);
  }
  else {
    *param_2 = 0;
    *param_3 = 0;
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_d0;
        *param_3 = (undefined4)uStack_c8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidDllStatspMapPartition");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddllstats.c");
      local_68 = &local_d8;
      local_d8 = 0xb7;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionStatisticsMap) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== _tlgCreate1Sz_char @ 1800064d0 =====

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
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== VidDllStatspComparePartitionHandles @ 180006510 =====

int VidDllStatspComparePartitionHandles(ulonglong *param_1,longlong param_2)

{
  if (*(ulonglong *)(param_2 + 0x18) < *param_1) {
    return 1;
  }
  return -(uint)(*param_1 < *(ulonglong *)(param_2 + 0x18));
}



===== VidGetSystemInformation @ 180006530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetSystemInformation
          (undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4,undefined8 param_5,
          undefined8 param_6,undefined4 *param_7)

{
  DWORD DVar1;
  int iVar2;
  HANDLE pvVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined1 auStackY_128 [32];
  undefined4 local_d8 [2];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x6530  88  VidGetSystemInformation */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar8 = 0;
  uVar5 = param_4 & 0xffffffff;
  local_d0 = param_5;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  iVar2 = (int)param_4;
  pvVar3 = GetProcessHeap();
  puVar4 = HeapAlloc(pvVar3,8,(ulonglong)(iVar2 + 8));
  if (puVar4 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidGetSystemInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x24e5,param_4
                    );
    return 0;
  }
  *puVar4 = param_2;
  puVar4[1] = iVar2;
  if (iVar2 != 0) {
    memcpy(puVar4 + 2,param_3,uVar5);
  }
  uVar7 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar3 == (HANDLE)0x0) {
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    iVar2 = NtDeviceIoControlFile(param_1,pvVar3);
    if (iVar2 == 0x103) {
      uVar6 = 0;
      NtWaitForSingleObject(pvVar3,0);
      iVar2 = (int)local_c8;
    }
    if (-1 < iVar2) {
      uVar8 = (undefined4)uStack_c0;
    }
    else {
      DVar1 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar1);
    }
    CloseHandle(pvVar3);
    if (-1 < iVar2) {
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = uVar8;
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidGetSystemInformation");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_78 = local_d8;
    local_d8[0] = 0x24fa;
    local_68 = &local_d0;
    local_70 = 4;
    local_d0 = CONCAT44(local_d0._4_4_,DVar1);
    local_60 = 4;
    _tlgCreate1Sz_char(local_58,"VID_IOCTL_GET_SYSTEM_INFORMATION");
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMapVpStatePage @ 180006830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMapVpStatePage(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  char *hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x6830  105  VidMapVpStatePage */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c8 = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_2;
  local_cc = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (char *)0x0) {
    uVar4 = 0x129;
    hObject = "VidIoControl";
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = local_c8;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    local_80 = 0x12;
    local_88 = "VidMapVpStatePage";
    local_68 = &local_d8;
    local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
    local_58 = &local_d4;
    local_48 = 
    "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMapVpStatePage) | (0x1 << 10)) << 2) | (0) )"
    ;
    local_70 = 0x20;
    local_d8 = 0x303d;
    local_60 = 4;
    local_50 = 4;
    local_40 = 0x68;
    local_d4 = DVar2;
    _tlgWriteTransfer_EventWriteTransfer(hObject,&DAT_180029ec4,uVar4,uVar5,7,local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== _tlgEnableCallback @ 180006a50 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

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



===== VmPerfCreateInstance2 @ 180006ad0 =====

DWORD VmPerfCreateInstance2
                (undefined8 param_1,undefined8 param_2,wchar_t *param_3,longlong param_4,
                undefined4 param_5,undefined8 *param_6)

{
  longlong lVar1;
  HRESULT HVar2;
  HANDLE pvVar3;
  longlong *plVar4;
  wchar_t *_Dst;
  DWORD DVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong _SizeInWords;
  
  lVar6 = 0;
  pvVar3 = GetProcessHeap();
  plVar4 = HeapAlloc(pvVar3,8,0x18);
  if (plVar4 == (longlong *)0x0) {
    *param_6 = 0;
    return 0xe;
  }
  lVar1 = -1;
  do {
    lVar7 = lVar1;
    lVar1 = lVar7 + 1;
  } while (param_3[lVar7 + 1] != L'\0');
  _SizeInWords = lVar7 + 2;
  if (param_4 != 0) {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (*(short *)(param_4 + lVar6 * 2) != 0);
    _SizeInWords = lVar7 + 3 + lVar6;
  }
  pvVar3 = GetProcessHeap();
  _Dst = HeapAlloc(pvVar3,8,_SizeInWords * 2);
  plVar4[1] = (longlong)_Dst;
  if (_Dst == (wchar_t *)0x0) {
    DVar5 = 0xe;
  }
  else {
    if (lVar6 == 0) {
      wcscpy_s(_Dst,_SizeInWords,param_3);
    }
    else {
      HVar2 = StringCchPrintfW(_Dst,_SizeInWords,L"%s:%s",param_4,param_3);
      if (HVar2 < 0) {
        DVar5 = 0x6f;
        goto LAB_180006c17;
      }
    }
    VmPerfpCleanNameString(plVar4[1],_SizeInWords);
    lVar6 = PerfCreateInstance(param_1,&VidPartitionObjectGuid,plVar4[1],param_5);
    *plVar4 = lVar6;
    if (lVar6 != 0) {
      *param_6 = plVar4;
      return 0;
    }
    DVar5 = GetLastError();
    if (DVar5 == 0) {
      *param_6 = plVar4;
      return 0;
    }
  }
LAB_180006c17:
  VmPerfDeleteInstance(param_1,plVar4);
  *param_6 = 0;
  return DVar5;
}



===== VidQueryMemoryBlockInformation @ 180006c70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
VidQueryMemoryBlockInformation
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,void *param_4,uint param_5,
          void *param_6,uint param_7,uint *param_8)

{
  DWORD DVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  uint *puVar5;
  HANDLE hObject;
  char **ppcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  void *pvVar9;
  undefined8 uVar10;
  undefined1 auStackY_128 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  uint *local_c8;
  void *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  char *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
                    /* 0x6c70  137  VidQueryMemoryBlockInformation */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c0 = param_6;
  local_c8 = param_8;
  local_d8 = param_1;
  local_d0 = param_2;
  if ((param_4 != (void *)0x0) != (param_5 != 0)) {
    SetLastError(0x57);
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char((longlong *)&local_88,"VidQueryMemoryBlockInformation");
      ppcVar6 = &local_78;
      _tlgCreate1Sz_char((longlong *)ppcVar6,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_d8;
      local_4c = 0;
      local_58 = &local_d0;
      local_d8 = CONCAT44(local_d8._4_4_,0x33cc);
      local_60 = 4;
      local_d0 = CONCAT44(local_d0._4_4_,DVar1);
      local_50 = 4;
      _tlgWriteTransfer_EventWriteTransfer(ppcVar6,&DAT_180029bc3,param_3,param_4,6,local_a8);
    }
    SetLastError(DVar1);
    return 0;
  }
  if (param_5 + 0xc < 0xc) {
    RtlSetLastWin32ErrorAndNtStatusFromNtStatus(0xc0000095);
    VidlpTraceError0("VidQueryMemoryBlockInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x33e0,
                     param_4);
    return 0;
  }
  if (param_7 + 4 < 4) {
    RtlSetLastWin32ErrorAndNtStatusFromNtStatus(0xc0000095);
    VidlpTraceError0("VidQueryMemoryBlockInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x33f1,
                     param_4);
    return 0;
  }
  pvVar9 = param_4;
  puVar4 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,param_5 + 0xc
                          );
  if (puVar4 == (undefined8 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidQueryMemoryBlockInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x3401,
                     pvVar9);
    return 0;
  }
  puVar5 = (uint *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8);
  if (puVar5 == (uint *)0x0) {
    uVar7 = 0;
    SetLastError(0xe);
    VidlpTraceError0("VidQueryMemoryBlockInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x340e,
                     pvVar9);
    goto LAB_18000706c;
  }
  *puVar4 = local_d0;
  *(int *)(puVar4 + 1) = (int)param_3;
  if (param_4 != (void *)0x0) {
    memcpy((void *)((longlong)puVar4 + 0xc),param_4,(ulonglong)param_5);
  }
  uVar10 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar8 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar10);
LAB_180006f69:
    GetLastError();
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      local_7c = 0;
      local_68 = &local_d0;
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_58 = &local_d8;
      local_48 = 
      "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionQueryMemoryBlockInformation) | (0x1 << 10)) << 2) | (0) )"
      ;
      local_88 = "VidQueryMemoryBlockInformation";
      local_80 = 0x1f;
      local_78 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
      local_70 = 0x20;
      local_d0 = CONCAT44(local_d0._4_4_,0x3426);
      local_60 = 4;
      local_d8 = CONCAT44(local_d8._4_4_,DVar1);
      local_50 = 4;
      local_40 = 0x75;
      _tlgWriteTransfer_EventWriteTransfer
                ("VidQueryMemoryBlockInformation",&DAT_180029ec4,uVar8,uVar10,7,local_a8);
    }
  }
  else {
    uVar10 = 0;
    uVar8 = 0;
    iVar2 = NtDeviceIoControlFile(local_d8,hObject);
    if (iVar2 == 0x103) {
      uVar8 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar2 = (int)local_b8;
    }
    if (iVar2 < 0) {
      DVar1 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar1);
    }
    CloseHandle(hObject);
    if (iVar2 < 0) goto LAB_180006f69;
    if (local_c8 != (uint *)0x0) {
      *local_c8 = *puVar5;
    }
    if (*puVar5 <= param_7) {
      memcpy(local_c0,puVar5 + 1,(ulonglong)*puVar5);
      uVar7 = 1;
      goto LAB_18000706c;
    }
    DVar1 = 0x7a;
  }
  uVar7 = 0;
  SetLastError(DVar1);
LAB_18000706c:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
  if (puVar5 != (uint *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar5);
  }
  return uVar7;
}



===== VidlpTraceError0 @ 180007140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VidlpTraceError0(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  ulonglong uVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  DWORD local_94 [3];
  _EVENT_DATA_DESCRIPTOR local_88 [2];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  DWORD *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  uVar3 = (undefined4)param_3;
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  dwErrCode = GetLastError();
  if (2 < DAT_18002e000) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      _tlgCreate1Sz_char(local_68,param_1);
      plVar2 = local_58;
      _tlgCreate1Sz_char(plVar2,param_2);
      local_48 = &local_98;
      local_38 = local_94;
      local_40 = 4;
      local_30 = 4;
      local_98 = uVar3;
      local_94[0] = dwErrCode;
      _tlgWriteTransfer_EventWriteTransfer(plVar2,&DAT_180029bc3,param_3,param_4,6,local_88);
    }
  }
  SetLastError(dwErrCode);
  return;
}



===== VidMapHvLocalStatsPage @ 180007240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMapHvLocalStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  uint local_c0;
  undefined4 uStack_bc;
  undefined1 local_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x7240  100  VidMapHvLocalStatsPage */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  _local_c0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_b8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidMapHvLocalStatsPage");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = local_d8 + 1;
    local_d8[1] = 0xe0d;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMapHvStatsPageLocal) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidRegisterIoPortHandler @ 180007450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRegisterIoPortHandler
          (undefined8 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
          undefined8 param_5)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined2 local_c0;
  undefined2 local_be;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x7450  148  VidRegisterIoPortHandler */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8 = param_5;
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = param_2;
  local_be = param_3;
  local_bc = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidRegisterIoPortHandler");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_58 = local_c8 + 1;
    local_c8[1] = 0x7c0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterIoPortHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VmPerfCreateInstance @ 180007690 =====

undefined8
VmPerfCreateInstance(undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  longlong lVar1;
  undefined8 local_res10 [3];
  
  lVar1 = 0;
  local_res10[0] = 0;
  if (DAT_180032e00 != (longlong *)0x0) {
    lVar1 = DAT_180032e00[1];
    param_4 = *(undefined4 *)(*DAT_180032e00 + 0x14);
  }
  dwErrCode = VmPerfCreateInstance2(param_1,param_2,param_3,lVar1,param_4,local_res10);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return local_res10[0];
}



===== VidCloseStatisticsHandle @ 180007700 =====

BOOL __stdcall VidCloseStatisticsHandle(HANDLE hObject)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180007700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x7700  12  VidCloseStatisticsHandle */
  BVar1 = CloseHandle(hObject);
  return BVar1;
}



===== __security_init_cookie @ 180007718 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  ulonglong uVar2;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_res18;
  
  local_res18.dwLowDateTime = 0;
  local_res18.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    GetSystemTimeAsFileTime(&local_res18);
    local_res8 = local_res18;
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1 << 0x18);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)DVar1 ^ (ulonglong)local_res8 ^ (ulonglong)&local_res8);
    QueryPerformanceCounter(&local_res10);
    uVar2 = (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)local_res8) &
            0xffffffffffff;
    __security_cookie = 0x2b992ddfa232;
    if (uVar2 != 0) {
      __security_cookie = uVar2;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __report_gsfailure @ 1800077f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  HANDLE hProcess;
  DWORD64 unaff_retaddr;
  uintptr_t local_res8 [4];
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  local_res8[0] = _StackCookie;
  RtlCaptureContext(&DAT_180032900);
  ControlPc = DAT_1800329f8;
  FunctionEntry = RtlLookupFunctionEntry(DAT_1800329f8,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_180032998 = local_res8;
    DAT_1800329f8 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_180032900,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_180032870 = DAT_1800329f8;
  _DAT_180032980 = local_res8[0];
  _DAT_180032860 = 0xc0000409;
  _DAT_180032864 = 1;
  _DAT_180032878 = 1;
  DAT_180032880 = 2;
  local_20 = __security_cookie;
  local_18 = __security_cookie_complement;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_180022000);
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,0xc0000409);
  return;
}



===== __tailMerge_devobj_dll @ 180007962 =====

void __tailMerge_devobj_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *in_RAX;
  FARPROC UNRECOVERED_JUMPTABLE;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper2(&ImgDelayDescr_18002aeb0.grAttrs,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001800079d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,in_XMM2_Qa,in_XMM3_Qa);
  return;
}



===== DelayLoad_DevObjCreateDeviceInfoList @ 1800079e1 =====

void DelayLoad_DevObjCreateDeviceInfoList
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_devobj_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DevObjGetClassDevs @ 1800079f3 =====

void DelayLoad_DevObjGetClassDevs
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_devobj_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DevObjEnumDeviceInterfaces @ 180007a05 =====

void DelayLoad_DevObjEnumDeviceInterfaces
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_devobj_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DevObjGetDeviceInterfaceDetail @ 180007a17 =====

void DelayLoad_DevObjGetDeviceInterfaceDetail
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_devobj_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DevObjDestroyDeviceInfoList @ 180007a29 =====

void DelayLoad_DevObjDestroyDeviceInfoList
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_devobj_dll(param_1,param_2,param_3,param_4);
  return;
}



===== _guard_check_icall @ 180007a50 =====

void _guard_check_icall(void)

{
  return;
}



===== entry @ 180007a70 =====

undefined8 entry(HMODULE param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  REGHANDLE RegHandle;
  BOOL BVar1;
  HANDLE hHeap;
  
  if (param_2 == 0) {
    if (DAT_180032e18 != (LPVOID)0x0) {
      hHeap = GetProcessHeap();
      BVar1 = HeapFree(hHeap,0,DAT_180032e18);
      if (BVar1 == 0) {
        VidlpTraceError0("VidpUninitializeSymbolicLink",
                         "onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",0x188,param_4);
      }
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_180032e28);
    if (DAT_180032e50 != (HANDLE)0xffffffffffffffff) {
      CloseHandle(DAT_180032e50);
      DAT_180032e50 = (HANDLE)0xffffffffffffffff;
    }
    if (DAT_180032e58 != (HANDLE)0xffffffffffffffff) {
      CloseHandle(DAT_180032e58);
      DAT_180032e58 = (HANDLE)0xffffffffffffffff;
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
    VidDllPartitionsTeardown();
    RegHandle = DAT_18002e020;
    DAT_18002e020 = 0;
    DAT_18002e000 = 0;
    EventUnregister(RegHandle);
  }
  else if (param_2 == 1) {
    TraceLoggingRegisterEx_EventRegister_EventSetInformation();
    __security_init_cookie();
    DisableThreadLibraryCalls(param_1);
    DAT_180032e18 = (LPVOID)0x0;
    DAT_180032e20 = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_180032e28);
    DAT_180032e50 = (HANDLE)0xffffffffffffffff;
    DAT_180032e58 = (HANDLE)0xffffffffffffffff;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_180032e60);
    DAT_180032de4 = 0;
    DAT_180032de0 = 0;
    InitializeSRWLock((PSRWLOCK)&g_VidStatsContext);
    DAT_180032de8 = 0;
    DAT_180032df0 = 0;
  }
  return 1;
}



===== StringCchCopyW @ 180007c08 =====

HRESULT __stdcall StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  HRESULT HVar1;
  
  if (cchDest - 1 < 0x7fffffff) {
    HVar1 = StringCopyWorkerW(pszDest,cchDest,(size_t *)pszSrc,pszSrc,0x7ffffffe);
  }
  else {
    HVar1 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar1;
}



===== StringCopyWorkerW @ 180007c48 =====

HRESULT __stdcall
StringCopyWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,
                 STRSAFE_PCNZWCH pszSrc,size_t cchToCopy)

{
  wchar_t wVar1;
  STRSAFE_LPWSTR pwVar2;
  longlong lVar3;
  
  if (cchDest != 0) {
    lVar3 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((cchToCopy == 0) || (wVar1 = *(wchar_t *)(lVar3 + (longlong)pszDest), wVar1 == L'\0'))
      break;
      *pszDest = wVar1;
      cchToCopy = cchToCopy - 1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
  }
  pwVar2 = pszDest + -1;
  if (cchDest != 0) {
    pwVar2 = pszDest;
  }
  *pwVar2 = L'\0';
  return ~-(uint)(cchDest != 0) & 0x8007007a;
}



===== VidAdjustNestedTlbSize @ 180007cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidAdjustNestedTlbSize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x7cb0  1  VidAdjustNestedTlbSize */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_b0 = param_2;
  local_a8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidAdjustNestedTlbSize");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x2f6c;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionAdjustNestedTlbSize) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidAllocateMemoryBlockReadWriteBuffers @ 180007ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidAllocateMemoryBlockReadWriteBuffers
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [7];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x7ea0  2  VidAllocateMemoryBlockReadWriteBuffers */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = param_2;
  local_ac = param_3;
  local_a8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidAllocateMemoryBlockReadWriteBuffers");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x22d5;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryBlockReadWriteAllocateBuffers) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidAttachPartition @ 180008090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidAttachPartition(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x8090  4  VidAttachPartition */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidAttachPartition");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x3778;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionAttach) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidChangePartitionLifeState @ 180008280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidChangePartitionLifeState
          (undefined8 param_1,undefined4 param_2,longlong param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [3];
  undefined4 local_cc;
  longlong local_c8;
  int local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x8280  5  VidChangePartitionLifeState */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cc = 0;
  local_c0 = (int)param_4;
  if ((param_3 == 0) && (local_c0 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidChangePartitionLifeState","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2654,
                     param_4);
  }
  else {
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_d8[2] = param_2;
    local_c8 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidChangePartitionLifeState");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_d8 + 1;
      local_d8[1] = 0x265f;
      local_58 = local_d8;
      local_60 = 4;
      local_50 = 4;
      local_d8[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionChangeLifeState) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidCheckForIoIntercept @ 1800084c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidCheckForIoIntercept(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 *in_stack_00000030;
  undefined1 auStackY_128 [32];
  undefined4 local_c8;
  DWORD local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x84c0  6  VidCheckForIoIntercept */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *in_stack_00000030 = 0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidCheckForIoIntercept");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_c8;
    local_4c = 0;
    local_58 = &local_c4;
    local_60 = 4;
    local_50 = 4;
    local_c8 = 0x2a3a;
    local_c4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCheckForIoIntercept) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidClearVirtualProcessorInterrupt @ 1800086d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidClearVirtualProcessorInterrupt(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x86d0  7  VidClearVirtualProcessorInterrupt */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  DVar1 = GetLastError();
  if (DVar1 != 0xc0350014) {
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
      _tlgCreate1Sz_char(local_68,"VidClearVirtualProcessorInterrupt");
      _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_3c = 0;
      local_48 = local_a8 + 1;
      local_2c = 0;
      local_38 = local_a8;
      local_40 = 4;
      local_30 = 4;
      local_a8[1] = 0x705;
      local_a8[0] = DVar1;
      _tlgCreate1Sz_char(local_28,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionClearInterrupt) | (0x1 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
    }
    SetLastError(DVar1);
  }
  return 0;
}



===== VidCloneTemplateCreate @ 1800088d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCloneTemplateCreate(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x88d0  8  VidCloneTemplateCreate */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    VidlpTraceError0("VidCloneTemplateCreate","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2a70,param_4)
    ;
  }
  else {
    uVar5 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_b8;
        param_3[1] = uStack_b0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidCloneTemplateCreate");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d4;
      local_d4 = 0x2a7a;
      local_58 = local_d0;
      local_60 = 4;
      local_50 = 4;
      local_d0[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCloneTemplateCreate) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidCloneTemplateDestroy @ 180008b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidCloneTemplateDestroy(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x8b00  9  VidCloneTemplateDestroy */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidCloneTemplateDestroy");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2aa5;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCloneTemplateDestroy) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidCloneTemplateDestroyDetached @ 180008cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidCloneTemplateDestroyDetached(undefined8 param_1,undefined4 *param_2)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [7];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x8cf0  10  VidCloneTemplateDestroyDetached */
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8[6] = *param_2;
  uStack_9c = param_2[1];
  uStack_98 = param_2[2];
  uStack_94 = param_2[3];
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidCloneTemplateDestroyDetached");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_b8 + 1;
    local_2c = 0;
    local_38 = local_b8;
    local_40 = 4;
    local_30 = 4;
    local_b8[1] = 0x2b12;
    local_b8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCloneTemplateDestroyDetached) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidCloneTemplateDetach @ 180008ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCloneTemplateDetach
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x8ef0  11  VidCloneTemplateDetach */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  if (param_3 == (undefined8 *)0x0) {
    VidlpTraceError0("VidCloneTemplateDetach","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2ad6,param_4)
    ;
  }
  else {
    local_d0 = *param_2;
    uStack_c8 = param_2[1];
    uVar5 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_c0;
        param_3[1] = uStack_b8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidCloneTemplateDetach");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_e8;
      local_e8 = 0x2ae0;
      local_58 = &local_e4;
      local_60 = 4;
      local_50 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCloneTemplateDetach) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidControlGpaAccessTracking @ 180009130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidControlGpaAccessTracking
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 *param_6,undefined8 *param_7,undefined4 param_8)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x9130  13  VidControlGpaAccessTracking */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_e4 = 0;
  local_cc = 0;
  local_d8 = param_5;
  local_d0 = param_8;
  local_b8 = 0;
  uStack_b0 = 0;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_f0 = param_2;
  local_e8 = param_3;
  local_e0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      if (param_6 != (undefined8 *)0x0) {
        *param_6 = local_b8;
      }
      if (param_7 == (undefined8 *)0x0) {
        return 1;
      }
      *param_7 = uStack_b0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidControlGpaAccessTracking");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_f8;
    local_4c = 0;
    local_58 = &local_f4;
    local_60 = 4;
    local_50 = 4;
    local_f8 = 0x31bb;
    local_f4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionControlGpaAccessTracking) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidCreateCpuGroup @ 180009380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateCpuGroup(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x9380  14  VidCreateCpuGroup */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_bc = 0;
  local_d0 = 0;
  uVar5 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = param_2;
  local_c0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = local_d0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidCreateCpuGroup");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_d8;
    local_4c = 0;
    local_58 = &local_d4;
    local_60 = 4;
    local_50 = 4;
    local_d8 = 0x2e61;
    local_d4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCpuGroupCreate) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidCreateDaxFileMemoryBlock @ 1800095a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidCreateDaxFileMemoryBlock
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined1 auVar1 [16];
  undefined1 uVar2;
  int iVar3;
  DWORD DVar4;
  HANDLE pvVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  ulonglong dwBytes;
  undefined8 uVar8;
  undefined8 uVar9;
  size_t _Size;
  bool bVar10;
  undefined1 auStackY_128 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x95a0  15  VidCreateDaxFileMemoryBlock */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar2 = (undefined1)param_4;
  local_c8 = 0;
  local_d8 = param_3;
  local_d0 = param_2;
  local_c0 = param_1;
  if (param_7 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateDaxFileMemoryBlock","onecore\\vm\\vid\\dll\\src\\viddll.c",0x10c8,
                     param_4);
    return false;
  }
  if (param_6 == (undefined8 *)0x0) {
    _Size = 0;
    uVar7 = 0x30;
LAB_18000965d:
    dwBytes = uVar7;
    if (uVar7 < 0x100000000) {
    }
  }
  else {
    dwBytes = 0xffffffffffffffff;
    local_b8 = 0;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_6[1];
    _Size = 0xffffffffffffffff;
    if (SUB168(ZEXT816(0x18) * auVar1,8) == 0) {
      _Size = SUB168(ZEXT816(0x18) * auVar1,0);
    }
    uVar7 = _Size + 0x30;
    if (0x2f < uVar7) goto LAB_18000965d;
  }
  pvVar5 = GetProcessHeap();
  puVar6 = HeapAlloc(pvVar5,8,dwBytes);
  if (puVar6 == (undefined8 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidCreateDaxFileMemoryBlock","onecore\\vm\\vid\\dll\\src\\viddll.c",0x10e8,
                     param_4);
    return false;
  }
  *puVar6 = local_d0;
  puVar6[1] = local_d8;
  puVar6[3] = param_5;
  *(undefined1 *)(puVar6 + 2) = uVar2;
  if (param_6 != (undefined8 *)0x0) {
    puVar6[4] = *param_6;
    puVar6[5] = param_6[1];
    memcpy(puVar6 + 6,param_6 + 2,_Size);
  }
  uVar9 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  pvVar5 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar5 == (HANDLE)0x0) {
    uVar8 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar9);
    bVar10 = false;
  }
  else {
    uVar9 = 0;
    uVar8 = 0;
    iVar3 = NtDeviceIoControlFile(local_c0,pvVar5);
    if (iVar3 == 0x103) {
      uVar8 = 0;
      NtWaitForSingleObject(pvVar5,0);
      iVar3 = (int)local_b8;
    }
    bVar10 = -1 < iVar3;
    if (!bVar10) {
      DVar4 = RtlNtStatusToDosError(iVar3);
      SetLastError(DVar4);
    }
    CloseHandle(pvVar5);
    if (bVar10) {
      *param_7 = local_c8;
      goto LAB_1800098b1;
    }
  }
  GetLastError();
  DVar4 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar7 = _tlgKeywordOn(), (char)uVar7 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidCreateDaxFileMemoryBlock");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = &local_d8;
    local_d8 = CONCAT44(local_d8._4_4_,0x1102);
    local_58 = &local_d0;
    local_60 = 4;
    local_d0 = CONCAT44(local_d0._4_4_,DVar4);
    local_50 = 4;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateDaxFileMemoryBlock) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar8,uVar9,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar4);
LAB_1800098b1:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar6);
  return bVar10;
}



===== VidCreateExoPartition @ 180009910 =====

HANDLE VidCreateExoPartition
                 (STRSAFE_PCNZWCH param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined1 uVar2;
  wchar_t *pwVar3;
  undefined7 extraout_var;
  undefined8 uVar4;
  DWORD dwErrCode;
  HANDLE pvVar5;
  
                    /* 0x9910  16  VidCreateExoPartition */
  bVar1 = false;
  if (param_1 == (STRSAFE_PCNZWCH)0x0) {
    dwErrCode = 0x57;
    VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2c3,param_4);
  }
  else if (*(uint *)(param_2 + 0x28) < 0x801) {
    if (((byte)*(undefined4 *)(param_2 + 0x30) & 0x7f) < 0x41) {
      uVar4 = 0x5c;
      pwVar3 = wcschr(param_1,L'\\');
      if (pwVar3 == (wchar_t *)0x0) {
        pvVar5 = VidpCreateVidObject(param_1,uVar4,'\x01',param_4);
        if (pvVar5 == (HANDLE)0xffffffffffffffff) {
          dwErrCode = GetLastError();
          uVar4 = 0x2e6;
          pvVar5 = (HANDLE)0xffffffffffffffff;
        }
        else {
          pvVar5 = (HANDLE)((ulonglong)pvVar5 | 1);
          bVar1 = true;
          uVar2 = VidpSetupPartition(pvVar5);
          if ((int)CONCAT71(extraout_var,uVar2) != 0) {
            dwErrCode = 0;
            goto LAB_180009a7c;
          }
          dwErrCode = GetLastError();
          uVar4 = 0x2ff;
        }
        VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",uVar4,
                         param_4);
        if (dwErrCode == 0) goto LAB_180009a7c;
        if (bVar1) {
          CloseHandle(pvVar5);
        }
      }
      else {
        dwErrCode = 0x57;
        VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2db,
                         param_4);
      }
    }
    else {
      dwErrCode = 0x57;
      VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2d1,param_4)
      ;
    }
  }
  else {
    dwErrCode = 0x57;
    VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2ca,param_4);
  }
  pvVar5 = (HANDLE)0xffffffffffffffff;
  VidlpTraceError0("VidCreateExoPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x310,param_4);
LAB_180009a7c:
  SetLastError(dwErrCode);
  return pvVar5;
}



===== VidCreateMemoryBlockGpaRange @ 180009ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateMemoryBlockGpaRange
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x9ab0  18  VidCreateMemoryBlockGpaRange */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_f0 = 0;
  if (param_8 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateMemoryBlockGpaRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1370,
                     param_4);
  }
  else {
    local_c0 = param_5;
    local_b8 = param_6;
    local_b0 = param_7;
    uVar5 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_d8 = param_2;
    local_d0 = param_3;
    local_c8 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_8 = local_f0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidCreateMemoryBlockGpaRange");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_f8;
      local_f8 = 0x137f;
      local_58 = &local_f4;
      local_60 = 4;
      local_50 = 4;
      local_f4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateMemoryBlockGpaRange) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidCreatePartition @ 180009d20 =====

HANDLE VidCreatePartition(STRSAFE_PCNZWCH param_1,wchar_t *param_2,longlong param_3,
                         undefined8 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  wchar_t *pwVar5;
  undefined7 extraout_var;
  undefined8 uVar6;
  char *pcVar7;
  DWORD dwErrCode;
  HANDLE hObject;
  undefined8 uVar8;
  
                    /* 0x9d20  20  VidCreatePartition */
  bVar2 = false;
  bVar1 = false;
  if (param_1 == (STRSAFE_PCNZWCH)0x0) {
    dwErrCode = 0x57;
    VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x23c,param_4);
  }
  else if (*(uint *)(param_3 + 0x28) < 0x801) {
    if (((byte)*(undefined4 *)(param_3 + 0x30) & 0x7f) < 0x41) {
      uVar6 = 0x5c;
      pwVar5 = wcschr(param_1,L'\\');
      if (pwVar5 == (wchar_t *)0x0) {
        uVar8 = 0;
        hObject = VidpCreateVidObject(param_1,uVar6,'\0',param_4);
        if (hObject == (HANDLE)0xffffffffffffffff) {
          dwErrCode = GetLastError();
          uVar6 = 0x262;
        }
        else {
          bVar2 = true;
          bVar3 = VidDllPartitionTrack(hObject,uVar6,uVar8,param_4);
          if (bVar3) {
            bVar1 = true;
            uVar4 = VidpSetupPartition(hObject);
            if ((int)CONCAT71(extraout_var,uVar4) != 0) {
              dwErrCode = 0;
              VidDllStatsPartitionSetup((undefined8 *)param_1,param_2,(ulonglong)hObject,param_4);
              goto LAB_180009edc;
            }
            dwErrCode = GetLastError();
            uVar6 = 0x279;
          }
          else {
            dwErrCode = GetLastError();
            uVar6 = 0x26d;
          }
        }
        pcVar7 = "onecore\\vm\\vid\\dll\\src\\viddll.c";
        VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",uVar6,param_4);
        if (dwErrCode == 0) goto LAB_180009edc;
        if (bVar1) {
          VidDllPartitionUntrack((ulonglong)hObject,pcVar7,uVar6,param_4);
        }
        if (bVar2) {
          CloseHandle(hObject);
        }
      }
      else {
        dwErrCode = 0x57;
        VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x254,param_4);
      }
    }
    else {
      dwErrCode = 0x57;
      VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x24a,param_4);
    }
  }
  else {
    dwErrCode = 0x57;
    VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x243,param_4);
  }
  hObject = (HANDLE)0xffffffffffffffff;
  VidlpTraceError0("VidCreatePartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x294,param_4);
LAB_180009edc:
  SetLastError(dwErrCode);
  return hObject;
}



===== VidCreateSynicPort @ 180009f10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidCreateSynicPort(undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                  undefined8 *param_5,undefined8 param_6,undefined8 *param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x9f10  21  VidCreateSynicPort */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  if (param_7 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidCreateSynicPort","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1457,param_4);
  }
  else {
    uStack_e0 = *param_5;
    local_d8 = param_5[1];
    uStack_d0 = param_5[2];
    local_c8 = param_5[3];
    local_e8._0_4_ = (uint)CONCAT11(param_3,param_2);
    local_e8 = CONCAT44((int)param_4,(uint)local_e8);
    uStack_c0 = param_6;
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_7 = local_f0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidCreateSynicPort");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_f8;
      local_f8 = 0x1465;
      local_58 = &local_f4;
      local_60 = 4;
      local_50 = 4;
      local_f4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCreateSynicPort) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDeleteCpuGroup @ 18000a190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDeleteCpuGroup(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xa190  23  VidDeleteCpuGroup */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDeleteCpuGroup");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2ec7;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCpuGroupDelete) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDeletePartition @ 18000a390 =====

void VidDeletePartition(HANDLE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0xa390  24  VidDeletePartition */
  if (((ulonglong)param_1 & 1) == 0) {
    VidDllStatsPartitionTeardown((ulonglong)param_1,param_2,param_3,param_4);
    VidDllPartitionUntrack((ulonglong)param_1,param_2,param_3,param_4);
  }
                    /* WARNING: Could not recover jumptable at 0x00018000a3b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CloseHandle(param_1);
  return;
}



===== VidDepositPartitionMemory @ 18000a3d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDepositPartitionMemory(undefined8 param_1,undefined8 param_2,byte param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xa3d0  25  VidDepositPartitionMemory */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  uStack_b0 = (ulonglong)param_3;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = local_d0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidDepositPartitionMemory");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_d8;
    local_4c = 0;
    local_58 = &local_d4;
    local_60 = 4;
    local_50 = 4;
    local_d8 = 0x37aa;
    local_d4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDepositPartitionMemory) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDestroyGpaRangeCheckSecure @ 18000a5f0 =====

ulonglong VidDestroyGpaRangeCheckSecure
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined7 extraout_var;
  
                    /* 0xa5f0  27  VidDestroyGpaRangeCheckSecure */
  uVar1 = VidDestroyGpaRangeInternal(param_1,param_2,1);
  if ((int)CONCAT71(extraout_var,uVar1) == 0) {
    VidlpTraceError0("VidDestroyGpaRangeCheckSecure","onecore\\vm\\vid\\dll\\src\\viddll.c",0x15cd,
                     param_4);
  }
  return CONCAT71(extraout_var,uVar1) & 0xffffffff;
}



===== VidDestroyMemoryBlockReadWriteBuffers @ 18000a630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDestroyMemoryBlockReadWriteBuffers(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xa630  29  VidDestroyMemoryBlockReadWriteBuffers */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDestroyMemoryBlockReadWriteBuffers");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x234d;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryBlockReadWriteDestroyBuffers) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDestroySynicPort @ 18000a820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDestroySynicPort(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xa820  30  VidDestroySynicPort */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDestroySynicPort");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x14f0;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDestroySynicPort) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDetachPartition @ 18000aa20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDetachPartition(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xaa20  31  VidDetachPartition */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDetachPartition");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x375a;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDetach) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDisablePartitionVtl @ 18000ac10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDisablePartitionVtl(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b4 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xac10  32  VidDisablePartitionVtl */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidDisablePartitionVtl");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b4 + 1;
    local_3c = 0;
    local_48 = local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b4[1] = 0x3868;
    local_b4[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDisableVtl) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDisableVpVtl @ 18000ae00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDisableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xae00  33  VidDisableVpVtl */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c0 = (ulonglong)CONCAT15(param_4,CONCAT14(param_3,param_2));
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidDisableVpVtl");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_b8[0] = 0x3895;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDisableVpVtl) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidDmConsolidationDisable @ 18000b000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDmConsolidationDisable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xb000  38  VidDmConsolidationDisable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDmConsolidationDisable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1f0f;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmConsolidationDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDmConsolidationEnable @ 18000b1f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDmConsolidationEnable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xb1f0  39  VidDmConsolidationEnable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_a8[2] = 0;
  local_a8[3] = 0;
  uVar4 = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[4];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDmConsolidationEnable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1ee9;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmConsolidationEnable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDmHotAdd @ 18000b3f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmHotAdd(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xb3f0  40  VidDmHotAdd */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmHotAdd","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1cab,param_4);
  }
  else {
    *param_3 = 0;
    local_c8 = *param_2;
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidDmHotAdd");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x1cb6;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmHotAdd) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDmHotAddUndo @ 18000b640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmHotAddUndo(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xb640  41  VidDmHotAddUndo */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_2 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmHotAddUndo","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1ce6,param_4);
  }
  else {
    local_b0 = *param_2;
    uVar5 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_a8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_78,"VidDmHotAddUndo");
      _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_58 = local_b8 + 1;
      local_b8[1] = 0x1cef;
      local_48 = local_b8;
      local_50 = 4;
      local_40 = 4;
      local_b8[0] = DVar2;
      _tlgCreate1Sz_char(local_38,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmHotAddUndo) | (0x1 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDmMemoryBlockQueryTopology @ 18000b870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmMemoryBlockQueryTopology
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_158 [32];
  undefined4 local_108;
  DWORD local_104;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0xb870  42  VidDmMemoryBlockQueryTopology */
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_c8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  if (((param_5 == (undefined8 *)0x0) || (param_6 == (undefined8 *)0x0)) ||
     (param_7 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmMemoryBlockQueryTopology","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1d2d,
                     param_4);
  }
  else {
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
    uVar5 = 0;
    local_100 = 0;
    uStack_f8 = 0;
    local_f0 = param_2;
    local_e8 = param_3;
    local_e0 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_100;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_5 = local_d8;
        *param_6 = uStack_d0;
        *param_7 = local_c8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidDmMemoryBlockQueryTopology");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_78 = &local_108;
      local_108 = 0x1d3c;
      local_68 = &local_104;
      local_70 = 4;
      local_60 = 4;
      local_104 = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmQueryBackingState) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDmSlpDisable @ 18000bb10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDmSlpDisable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xbb10  43  VidDmSlpDisable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDmSlpDisable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1dcd;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmSlpDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDmSlpQuery @ 18000bd00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmSlpQuery(undefined8 param_1,undefined1 *param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_c0;
  undefined7 local_bf;
  undefined1 uStack_b8;
  undefined7 uStack_b7;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xbd00  44  VidDmSlpQuery */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  uStack_b8 = 0;
  local_c0 = 0;
  local_bf = 0;
  if ((param_2 == (undefined1 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmSlpQuery","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1e79,param_4);
  }
  else {
    uVar5 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_c0;
        *param_3 = CONCAT71(uStack_b7,uStack_b8);
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidDmSlpQuery");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_d8;
      local_4c = 0;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d8 = 0x1e80;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmSlpQuery) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidDmSlpSetup @ 18000bf50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidDmSlpSetup(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  HRESULT HVar2;
  int iVar3;
  DWORD DVar4;
  HANDLE hObject;
  ulonglong uVar5;
  size_t *pcchNewDestLength;
  undefined8 uVar6;
  STRSAFE_PCNZWCH pwVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined1 auStackY_318 [32];
  DWORD local_2c8 [2];
  ulonglong local_2c0;
  STRSAFE_PCNZWCH pwStack_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  wchar_t local_298 [256];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xbf50  45  VidDmSlpSetup */
  local_28 = __security_cookie ^ (ulonglong)auStackY_318;
  memset(local_298,0,0x200);
  bVar9 = false;
  local_2c0 = 0;
  pwStack_2b8 = (STRSAFE_PCNZWCH)0x0;
  if (param_2 == 0) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmSlpSetup","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1e25,param_4);
  }
  else {
    pcchNewDestLength = (size_t *)0x0;
    cVar1 = RtlDosPathNameToNtPathName_U(param_2,&local_2c0,0,0);
    if (cVar1 == '\0') {
      local_2c0 = 0;
      pwStack_2b8 = (STRSAFE_PCNZWCH)0x0;
    }
    if (pwStack_2b8 == (STRSAFE_PCNZWCH)0x0) {
      pwVar7 = pwStack_2b8;
      SetLastError(0x57);
      VidlpTraceError0("VidDmSlpSetup","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1e2f,pwVar7);
    }
    else {
      pwVar7 = pwStack_2b8;
      HVar2 = StringCopyWorkerW(local_298,0x100,pcchNewDestLength,pwStack_2b8,
                                local_2c0 >> 0x11 & 0x7fff);
      if (HVar2 < 0) {
        SetLastError(0x57);
        VidlpTraceError0("VidDmSlpSetup","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1e3b,pwVar7);
      }
      else {
        uVar8 = 0;
        local_2b0 = 0;
        uStack_2a8 = 0;
        hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        if (hObject == (HANDLE)0x0) {
          uVar6 = 0x129;
          VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar8);
        }
        else {
          uVar8 = 0;
          uVar6 = 0;
          iVar3 = NtDeviceIoControlFile(param_1,hObject);
          if (iVar3 == 0x103) {
            uVar6 = 0;
            NtWaitForSingleObject(hObject,0);
            iVar3 = (int)local_2b0;
          }
          bVar9 = -1 < iVar3;
          if (!bVar9) {
            DVar4 = RtlNtStatusToDosError(iVar3);
            SetLastError(DVar4);
          }
          CloseHandle(hObject);
          if (bVar9) goto LAB_18000c23a;
        }
        GetLastError();
        DVar4 = GetLastError();
        if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
          _tlgCreate1Sz_char(local_78,"VidDmSlpSetup");
          _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
          local_4c = 0;
          local_58 = local_2c8 + 1;
          local_3c = 0;
          local_48 = local_2c8;
          local_50 = 4;
          local_40 = 4;
          local_2c8[1] = 0x1e42;
          local_2c8[0] = DVar4;
          _tlgCreate1Sz_char(local_38,
                             "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmSlpSetup) | (0x1 << 10)) << 2) | (0) )"
                            );
          _tlgWriteTransfer_EventWriteTransfer
                    (local_98,&DAT_180029ec4,uVar6,uVar8,7,(PEVENT_DATA_DESCRIPTOR)local_98);
        }
        SetLastError(DVar4);
      }
    }
  }
LAB_18000c23a:
  if (pwStack_2b8 != (STRSAFE_PCNZWCH)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pwStack_2b8);
  }
  return bVar9;
}



===== VidDmSlpWaitForDisable @ 18000c290 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDmSlpWaitForDisable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xc290  46  VidDmSlpWaitForDisable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDmSlpWaitForDisable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1df3;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmSlpWaitForDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidDmUnBalloon @ 18000c480 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmUnBalloon(undefined8 param_1,undefined1 param_2,undefined8 param_3,void *param_4,uint param_5,
              undefined8 *param_6,uint *param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined1 auStackY_1158 [32];
  undefined4 local_1108;
  DWORD local_1104;
  undefined8 local_1100;
  undefined8 uStack_10f8;
  undefined8 local_10f0;
  undefined8 uStack_10e8;
  uint local_10e0;
  undefined1 local_10d8 [4096];
  undefined8 local_d8;
  uint local_d0;
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  DWORD *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  ulonglong local_58;
  undefined8 uStack_48;
  
                    /* 0xc480  47  VidDmUnBalloon */
  uStack_48 = 0x18000c49f;
  local_58 = __security_cookie ^ (ulonglong)auStackY_1158;
  local_10e0 = local_10e0 & 0xffffff00;
  local_10f0 = 0;
  uStack_10e8 = 0;
  pvVar5 = param_4;
  memset(local_10d8,0,0x1010);
  if ((param_4 == (void *)0x0) || (param_7 == (uint *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmUnBalloon","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1d82,pvVar5);
  }
  else {
    *param_7 = 0;
    if ((param_5 < 0x201) && (param_6 != (undefined8 *)0x0)) {
      *param_6 = 0;
      local_10f0 = CONCAT71(local_10f0._1_7_,param_2);
      local_10e0 = param_5;
      uVar6 = 0;
      local_1100 = 0;
      uStack_10f8 = 0;
      uStack_10e8 = param_3;
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (hObject == (HANDLE)0x0) {
        uVar4 = 0x129;
        VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
      }
      else {
        uVar6 = 0;
        uVar4 = 0;
        iVar1 = NtDeviceIoControlFile(param_1,hObject);
        if (iVar1 == 0x103) {
          uVar4 = 0;
          NtWaitForSingleObject(hObject,0);
          iVar1 = (int)local_1100;
        }
        if (-1 >= iVar1) {
          DVar2 = RtlNtStatusToDosError(iVar1);
          SetLastError(DVar2);
        }
        CloseHandle(hObject);
        if (-1 < iVar1) {
          *param_6 = local_d8;
          *param_7 = local_d0;
          if (local_d0 == 0) {
            return 1;
          }
          memcpy(param_4,local_10d8,(ulonglong)local_d0 << 3);
          return 1;
        }
      }
      GetLastError();
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
        _tlgCreate1Sz_char(local_a8,"VidDmUnBalloon");
        _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_7c = 0;
        local_88 = &local_1108;
        local_6c = 0;
        local_78 = &local_1104;
        local_80 = 4;
        local_70 = 4;
        local_1108 = 0x1d99;
        local_1104 = DVar2;
        _tlgCreate1Sz_char(local_68,
                           "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmUnballoon) | (0x1 << 10)) << 2) | (0) )"
                          );
        _tlgWriteTransfer_EventWriteTransfer
                  (local_c8,&DAT_180029ec4,uVar4,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
      }
      SetLastError(DVar2);
    }
    else {
      SetLastError(0x57);
      VidlpTraceError0("VidDmUnBalloon","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1d8c,pvVar5);
    }
  }
  return 0;
}



===== VidDmWorkingSetModify @ 18000c7b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidDmWorkingSetModify(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xc7b0  48  VidDmWorkingSetModify */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidDmWorkingSetModify","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1eb3,param_4);
  }
  else {
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    local_c8 = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidDmWorkingSetModify");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x1ebd;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDmWorkingSetModify) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidEncryptDecryptData @ 18000c9f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018000cc3b) */

undefined1
VidEncryptDecryptData
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined8 param_4,
          undefined4 param_5,undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e4;
  DWORD local_e0 [2];
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined2 local_ba;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xc9f0  49  VidEncryptDecryptData */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_cc = 0;
  local_ba = 0;
  if (param_3 == (undefined4 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidEncryptDecryptData","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1a9b,param_4);
  }
  else {
    local_d0 = param_5;
    local_c0 = *param_3;
    local_bc = param_6;
    local_bb = param_7;
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_d8 = param_4;
    local_c8 = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = 0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidEncryptDecryptData");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_e4;
      local_e4 = 0x1aab;
      local_58 = local_e0;
      local_60 = 4;
      local_50 = 4;
      local_e0[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCryptEncryptDecryptData) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidEpfRestore @ 18000cca0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidEpfRestore(undefined8 param_1,void *param_2,uint param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  uint local_c0;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined8 local_ac;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xcca0  50  VidEpfRestore */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_ac = 0;
  local_bc = 0;
  uStack_b4 = 0;
  if (param_2 == (void *)0x0) {
    if (param_3 != 0) {
      SetLastError(0x57);
      VidlpTraceError0("VidEpfRestore","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1ff2,param_4);
      return 0;
    }
  }
  else if (0x18 < param_3) {
    SetLastError(0x57);
    VidlpTraceError0("VidEpfRestore","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1ff9,param_4);
    return 0;
  }
  local_c0 = param_3;
  memcpy(&local_bc,param_2,(ulonglong)param_3);
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidEpfRestore");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_58 = local_d8 + 1;
    local_d8[1] = 0x2003;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionEpfRestore) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidEpfSave @ 18000cf20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidEpfSave(undefined8 param_1,void *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hObject;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0xcf20  51  VidEpfSave */
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d0 = 0;
  local_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  if ((param_2 == (void *)0x0) && (param_3 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidEpfSave","onecore\\vm\\vid\\dll\\src\\viddll.c",0x203b,param_4);
    return 0;
  }
  *param_4 = 0;
  uVar7 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
LAB_18000d082:
    GetLastError();
    DVar3 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidEpfSave");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_f8;
      local_5c = 0;
      local_68 = &local_f4;
      local_70 = 4;
      local_60 = 4;
      local_f8 = 0x2044;
      local_f4 = DVar3;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionEpfSave) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar3);
    return 0;
  }
  uVar7 = 0;
  uVar6 = 0;
  iVar2 = NtDeviceIoControlFile(param_1,hObject);
  if (iVar2 == 0x103) {
    uVar6 = 0;
    NtWaitForSingleObject(hObject,0);
    iVar2 = (int)local_f0;
  }
  if (iVar2 < 0) {
    DVar3 = RtlNtStatusToDosError(iVar2);
    SetLastError(DVar3);
  }
  CloseHandle(hObject);
  if (iVar2 < 0) goto LAB_18000d082;
  uVar5 = 1;
  if (param_2 != (void *)0x0) {
    uVar1 = (uint)local_e0;
    if ((uint)local_e0 <= param_3) {
      memcpy(param_2,(void *)((longlong)&local_e0 + 4),local_e0 & 0xffffffff);
      local_e0._0_4_ = uVar1;
      goto LAB_18000d190;
    }
    SetLastError(0x7a);
    VidlpTraceError0("VidEpfSave","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2054,uVar7);
    uVar5 = 0;
  }
LAB_18000d190:
  *param_4 = (uint)local_e0;
  return uVar5;
}



===== VidEpfSuspendBegin @ 18000d1c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidEpfSuspendBegin(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xd1c0  52  VidEpfSuspendBegin */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidEpfSuspendBegin");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x207a;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionEpfSuspendBegin) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidEpfSuspendEnd @ 18000d3b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidEpfSuspendEnd(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xd3b0  53  VidEpfSuspendEnd */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidEpfSuspendEnd");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x20a0;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionEpfSuspendEnd) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoBrokerReceive @ 18000d5a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
VidExoBrokerReceive(undefined8 param_1,void *param_2,uint param_3,uint *param_4,void *param_5,
                   uint param_6,uint *param_7)

{
  uint uVar1;
  int iVar2;
  HANDLE pvVar3;
  uint *lpMem;
  ulonglong uVar4;
  DWORD DVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  uint local_f0;
  void *local_e8;
  void *local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  DWORD *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0xd5a0  55  VidExoBrokerReceive */
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  local_e0 = param_5;
  local_f0 = param_3;
  local_e8 = param_2;
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,0,(ulonglong)(param_3 * 8 + 0x10 + param_6));
  if (lpMem == (uint *)0x0) {
    DVar5 = 0xe;
    goto LAB_18000d873;
  }
  uVar7 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar3 == (HANDLE)0x0) {
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
LAB_18000d707:
    GetLastError();
    DVar5 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidExoBrokerReceive");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_7c = 0;
      local_88 = &local_f8;
      local_6c = 0;
      local_78 = &local_f4;
      local_80 = 4;
      local_70 = 4;
      local_f8 = 0x3716;
      local_f4 = DVar5;
      _tlgCreate1Sz_char(local_68,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoBrokerReceive) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_c8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
    }
    SetLastError(DVar5);
    DVar5 = GetLastError();
    if (DVar5 == 0xea) goto LAB_18000d7fe;
    *param_4 = 0;
    *param_7 = 0;
    VidlpTraceError0("VidExoBrokerReceive","onecore\\vm\\vid\\dll\\src\\viddll.c",0x371d,uVar7);
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    iVar2 = NtDeviceIoControlFile(param_1,pvVar3);
    if (iVar2 == 0x103) {
      uVar6 = 0;
      NtWaitForSingleObject(pvVar3,0);
      iVar2 = (int)local_d8;
    }
    if (iVar2 < 0) {
      DVar5 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar5);
    }
    CloseHandle(pvVar3);
    if (iVar2 < 0) goto LAB_18000d707;
    DVar5 = 0;
LAB_18000d7fe:
    *param_4 = lpMem[1];
    uVar1 = lpMem[3];
    *param_7 = uVar1;
    if (DVar5 == 0) {
      if ((local_f0 < *param_4) || (param_6 < uVar1)) {
        DVar5 = 0xea;
      }
      else {
        memcpy(local_e8,(void *)((ulonglong)*lpMem + (longlong)lpMem),(ulonglong)lpMem[1] << 3);
        memcpy(local_e0,(void *)((ulonglong)lpMem[2] + (longlong)lpMem),(ulonglong)lpMem[3]);
      }
    }
  }
  pvVar3 = GetProcessHeap();
  HeapFree(pvVar3,0,lpMem);
  if (DVar5 == 0) {
    return 1;
  }
LAB_18000d873:
  SetLastError(DVar5);
  return 0;
}



===== VidExoBrokerSend @ 18000d8c0 =====

undefined4
VidExoBrokerSend(HANDLE param_1,void *param_2,uint param_3,void *param_4,uint param_5,
                LPOVERLAPPED param_6)

{
  uint uVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  undefined4 *lpInBuffer;
  DWORD dwErrCode;
  uint nInBufferSize;
  ulonglong uVar4;
  DWORD local_res18 [4];
  
                    /* 0xd8c0  56  VidExoBrokerSend */
  local_res18[0] = 0;
  uVar4 = (ulonglong)param_3 * 8;
  if ((uVar4 < 0x100000000) && (uVar1 = (uint)uVar4 + 0x10, (uint)uVar4 <= uVar1)) {
    nInBufferSize = uVar1 + param_5;
    if (uVar1 <= nInBufferSize) {
      pvVar3 = GetProcessHeap();
      lpInBuffer = HeapAlloc(pvVar3,0,(ulonglong)nInBufferSize);
      if (lpInBuffer == (undefined4 *)0x0) {
        dwErrCode = 0xe;
      }
      else {
        *lpInBuffer = 0x10;
        lpInBuffer[1] = param_3;
        lpInBuffer[3] = param_5;
        lpInBuffer[2] = param_3 * 8 + 0x10;
        memcpy(lpInBuffer + 4,param_2,uVar4);
        memcpy((void *)((ulonglong)(uint)lpInBuffer[2] + (longlong)lpInBuffer),param_4,
               (ulonglong)param_5);
        uVar4 = (ulonglong)nInBufferSize;
        BVar2 = DeviceIoControl(param_1,0x22128c,lpInBuffer,nInBufferSize,(LPVOID)0x0,0,local_res18,
                                param_6);
        if (BVar2 == 0) {
          dwErrCode = GetLastError();
          if (dwErrCode != 0x3e5) {
            VidlpTraceError0("VidExoBrokerSend","onecore\\vm\\vid\\dll\\src\\viddll.c",0x36bb,uVar4)
            ;
          }
        }
        else {
          dwErrCode = 0;
        }
        pvVar3 = GetProcessHeap();
        HeapFree(pvVar3,0,lpInBuffer);
        if (dwErrCode == 0) {
          return 1;
        }
      }
      goto LAB_18000da2c;
    }
  }
  dwErrCode = 0x57;
LAB_18000da2c:
  SetLastError(dwErrCode);
  return 0;
}



===== VidExoGetVpState @ 18000da60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoGetVpState(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [2];
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xda60  58  VidExoGetVpState */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  uStack_c8 = param_4[2];
  local_e0 = (ulonglong)CONCAT14(param_3,param_2);
  uStack_d8 = *param_4;
  local_d0 = param_4[1];
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidExoGetVpState");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_e8 + 1;
    local_4c = 0;
    local_58 = local_e8;
    local_60 = 4;
    local_50 = 4;
    local_e8[1] = 0x30ad;
    local_e8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoGetVirtualProcessorState) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidExoPinGpaRanges @ 18000dc80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidExoPinGpaRanges(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xdc80  61  VidExoPinGpaRanges */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidExoPinGpaRanges");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_c8 + 1;
    local_4c = 0;
    local_58 = local_c8;
    local_60 = 4;
    local_50 = 4;
    local_c8[1] = 0x3641;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoPinGpaRanges) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoRegisterInterceptResult @ 18000de70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoRegisterInterceptResult
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [7];
  undefined4 uStack_cc;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xde70  62  VidExoRegisterInterceptResult */
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  uStack_b8 = param_4[2];
  local_b0 = param_4[3];
  stack0xffffffffffffff30 = CONCAT44(param_3,param_2);
  uStack_c8 = *param_4;
  local_c0 = param_4[1];
  uStack_a8 = param_4[4];
  uStack_a0 = *(undefined4 *)(param_4 + 5);
  uStack_9c = *(undefined4 *)((longlong)param_4 + 0x2c);
  uVar4 = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_e8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidExoRegisterInterceptResult");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_e8 + 1;
    local_3c = 0;
    local_48 = local_e8;
    local_50 = 4;
    local_40 = 4;
    local_e8[1] = 0x3611;
    local_e8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoRegisterInterceptResult) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoSetVpState @ 18000e090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidExoSetVpState(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4,
                     void *param_5,uint param_6)

{
  DWORD DVar1;
  int iVar2;
  HANDLE pvVar3;
  undefined4 *lpMem;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined1 auStackY_128 [32];
  undefined4 local_d8 [2];
  void *local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  void **local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0xe090  63  VidExoSetVpState */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = param_5;
  puVar6 = param_4;
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,8,(ulonglong)param_6 + 0x20);
  if (lpMem == (undefined4 *)0x0) {
    DVar1 = GetLastError();
    VidlpTraceError0("VidExoSetVpState","onecore\\vm\\vid\\dll\\src\\viddll.c",0x30f0,puVar6);
    goto LAB_18000e326;
  }
  *lpMem = param_2;
  *(undefined1 *)(lpMem + 1) = param_3;
  uVar7 = param_4[1];
  *(undefined8 *)(lpMem + 2) = *param_4;
  *(undefined8 *)(lpMem + 4) = uVar7;
  *(undefined8 *)(lpMem + 6) = param_4[2];
  memcpy(lpMem + 8,local_d0,(ulonglong)param_6);
  uVar7 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar3 == (HANDLE)0x0) {
    uVar5 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
LAB_18000e238:
    GetLastError();
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidExoSetVpState");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = local_d8;
      local_5c = 0;
      local_68 = &local_d0;
      local_70 = 4;
      local_60 = 4;
      local_d8[0] = 0x30ff;
      local_d0 = (void *)CONCAT44(local_d0._4_4_,DVar1);
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoSetVirtualProcessorState) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar5,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar1);
    DVar1 = GetLastError();
  }
  else {
    uVar7 = 0;
    uVar5 = 0;
    iVar2 = NtDeviceIoControlFile(param_1,pvVar3);
    if (iVar2 == 0x103) {
      uVar5 = 0;
      NtWaitForSingleObject(pvVar3,0);
      iVar2 = (int)local_c8;
    }
    if (iVar2 < 0) {
      DVar1 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar1);
    }
    CloseHandle(pvVar3);
    if (iVar2 < 0) goto LAB_18000e238;
    DVar1 = 0;
  }
  pvVar3 = GetProcessHeap();
  HeapFree(pvVar3,0,lpMem);
LAB_18000e326:
  if (DVar1 != 0) {
    SetLastError(DVar1);
  }
  return DVar1 == 0;
}



===== VidExoUnmapGpaRange @ 18000e370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidExoUnmapGpaRange(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xe370  64  VidExoUnmapGpaRange */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_b0 = param_2;
  local_a8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidExoUnmapGpaRange");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x3b9;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoUnmapGpaRange) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoUnpinGpaRanges @ 18000e560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidExoUnpinGpaRanges(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xe560  65  VidExoUnpinGpaRanges */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidExoUnpinGpaRanges");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_c8 + 1;
    local_4c = 0;
    local_58 = local_c8;
    local_60 = 4;
    local_50 = 4;
    local_c8[1] = 0x3668;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoUnpinGpaRanges) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoVpCreate @ 18000e750 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidExoVpCreate(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4,
              undefined8 param_5)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xe750  66  VidExoVpCreate */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  uStack_b8 = 0;
  local_c0 = (ulonglong)CONCAT14(param_3,param_2);
  local_b0 = 0;
  uStack_a8 = param_5;
  if (param_4 != (undefined8 *)0x0) {
    uStack_b8 = *param_4;
    local_b0 = param_4[1];
  }
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidExoVpCreate");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x3539;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoVpCreate) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidExoVpDestroy @ 18000e970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidExoVpDestroy(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0xe970  67  VidExoVpDestroy */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidExoVpDestroy");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x35a1;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoVpDestroy) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidExoVpMap @ 18000eb70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidExoVpMap(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xeb70  68  VidExoVpMap */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_3 = local_b8;
      param_3[1] = uStack_b0;
      param_3[2] = local_a8;
      param_3[3] = uStack_a0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidExoVpMap");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = &local_d4;
    local_3c = 0;
    local_48 = local_d0;
    local_d4 = 0x356e;
    local_50 = 4;
    local_40 = 4;
    local_d0[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionExoVpMap) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidFlushMemoryBlockMapping @ 18000eda0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidFlushMemoryBlockMapping
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xeda0  69  VidFlushMemoryBlockMapping */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_b0 = param_2;
  local_a8 = param_3;
  local_a0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidFlushMemoryBlockMapping");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x180e;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionFlushMemoryBlockMapping) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidFlushMemoryBlockPageRange @ 18000ef90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidFlushMemoryBlockPageRange
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xef90  70  VidFlushMemoryBlockPageRange */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_a4 = 0;
  local_a8 = param_5;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidFlushMemoryBlockPageRange");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x17c7;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionFlushMemoryBlockPageRange) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGetCpuGroupProperty @ 18000f1a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetCpuGroupProperty(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xf1a0  71  VidGetCpuGroupProperty */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_ac = 0;
  local_d0 = 0;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = param_2;
  local_b0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = local_d0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidGetCpuGroupProperty");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_d8;
    local_4c = 0;
    local_58 = &local_d4;
    local_60 = 4;
    local_50 = 4;
    local_d8 = 0x2f00;
    local_d4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCpuGroupGetProperty) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidGetExoPartitionProperty @ 18000f3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetExoPartitionProperty(HANDLE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xf3c0  72  VidGetExoPartitionProperty */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c0 = param_2;
  if ((param_1 != (HANDLE)0xffffffffffffffff) ||
     (param_1 = VidpGetGlobalVidObject(1,param_2,param_3,param_4),
     param_1 != (HANDLE)0xffffffffffffffff)) {
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidGetExoPartitionProperty");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_c8 + 1;
      local_c8[1] = 0x435;
      local_58 = local_c8;
      local_60 = 4;
      local_50 = 4;
      local_c8[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | ((VidIoctlDualGetPartitionProperty) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetExoSystemInformation @ 18000f5e0 =====

undefined1
VidGetExoSystemInformation
          (undefined4 param_1,void *param_2,ulonglong param_3,undefined8 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  undefined1 uVar1;
  HANDLE pvVar2;
  undefined4 in_stack_ffffffffffffffe4;
  
                    /* 0xf5e0  73  VidGetExoSystemInformation */
  pvVar2 = VidpGetGlobalVidObject(1,param_2,param_3,param_4);
  if (pvVar2 == (HANDLE)0xffffffffffffffff) {
    uVar1 = 0;
  }
  else {
    uVar1 = VidGetSystemInformation
                      (pvVar2,param_1,param_2,param_3 & 0xffffffff,param_4,
                       CONCAT44(in_stack_ffffffffffffffe4,param_5),param_6);
  }
  return uVar1;
}



===== VidGetExoSystemTopology @ 18000f660 =====

ulonglong VidGetExoSystemTopology
                    (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined1 *param_4
                    ,void *param_5,byte *param_6)

{
  undefined1 uVar1;
  HANDLE pvVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  undefined1 *puVar4;
  
  puVar4 = param_4;
                    /* 0xf660  74  VidGetExoSystemTopology */
  pvVar2 = VidpGetGlobalVidObject(1,param_2,param_3,param_4);
  if (pvVar2 == (HANDLE)0xffffffffffffffff) {
    uVar3 = 0;
    VidlpTraceError0("VidGetExoSystemTopology","onecore\\vm\\vid\\dll\\src\\viddll.c",0x21d7,puVar4)
    ;
  }
  else {
    uVar1 = VidGetSystemTopology(pvVar2,param_1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = CONCAT71(extraout_var,uVar1) & 0xffffffff;
    if ((int)CONCAT71(extraout_var,uVar1) == 0) {
      VidlpTraceError0("VidGetExoSystemTopology","onecore\\vm\\vid\\dll\\src\\viddll.c",0x21e6,
                       param_3);
    }
  }
  return uVar3;
}



===== VidGetHvLogicalProcessorCount @ 18000f720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetHvLogicalProcessorCount
          (undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  undefined4 local_b4;
  DWORD local_b0 [2];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0xf720  75  VidGetHvLogicalProcessorCount */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_2 == (undefined4 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidGetHvLogicalProcessorCount","onecore\\vm\\vid\\dll\\src\\viddll.c",0xf6b,
                     param_4);
  }
  else {
    uVar5 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_a8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = 0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_78,"VidGetHvLogicalProcessorCount");
      _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_58 = &local_b4;
      local_b4 = 0xf73;
      local_48 = local_b0;
      local_50 = 4;
      local_40 = 4;
      local_b0[0] = DVar2;
      _tlgCreate1Sz_char(local_38,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatsGetLogicalProcCount) | (0x0 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetHvLogicalProcessorRuntime @ 18000f960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetHvLogicalProcessorRuntime
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4,
          undefined8 *param_5)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f4;
  DWORD local_f0 [2];
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0xf960  76  VidGetHvLogicalProcessorRuntime */
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_c8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  if (((param_3 == (undefined8 *)0x0) || (param_4 == (undefined8 *)0x0)) ||
     (param_5 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidGetHvLogicalProcessorRuntime","onecore\\vm\\vid\\dll\\src\\viddll.c",0xfb3,
                     param_4);
  }
  else {
    uVar5 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d8;
        *param_4 = uStack_d0;
        *param_5 = local_c8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidGetHvLogicalProcessorRuntime");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_f4;
      local_5c = 0;
      local_68 = local_f0;
      local_f4 = 0xfbd;
      local_70 = 4;
      local_60 = 4;
      local_f0[0] = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatsGetLogicalProcRuntime) | (0x0 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetHvMemoryBalance @ 18000fbe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetHvMemoryBalance(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xfbe0  77  VidGetHvMemoryBalance */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidGetHvMemoryBalance","onecore\\vm\\vid\\dll\\src\\viddll.c",0xff3,param_4);
  }
  else {
    uVar5 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_c0;
        *param_3 = uStack_b8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidGetHvMemoryBalance");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_d8;
      local_4c = 0;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d8 = 0xffb;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGetHvMemoryBalance) | (0x1 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetHvVpRuntime @ 18000fe30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetHvVpRuntime(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b4;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0xfe30  79  VidGetHvVpRuntime */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_bc = 0;
  local_b4 = 0;
  local_e0 = 0;
  if (param_4 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidGetHvVpRuntime","onecore\\vm\\vid\\dll\\src\\viddll.c",0xf41,param_4);
  }
  else {
    uVar5 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_c8 = param_2;
    local_c0 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = local_e0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidGetHvVpRuntime");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_e8;
      local_e8 = 0xf4f;
      local_58 = &local_e4;
      local_60 = 4;
      local_50 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatsGetVpRuntime) | (0x0 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetIsolationLuid @ 180010080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGetIsolationLuid(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x10080  80  VidGetIsolationLuid */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidGetIsolationLuid");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_c8 + 1;
    local_4c = 0;
    local_58 = local_c8;
    local_60 = 4;
    local_50 = 4;
    local_c8[1] = 0x268f;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGetIsolationLuid) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGetMemoryBlockProtectionBitmap @ 180010270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetMemoryBlockProtectionBitmap
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x10270  81  VidGetMemoryBlockProtectionBitmap */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_b0 = param_2;
  local_a8 = param_3;
  local_a0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidGetMemoryBlockProtectionBitmap");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x1319;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDbgProtectMemoryBlockGetBitmap) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGetPartitionIds @ 180010460 =====

undefined8 VidGetPartitionIds(void)

{
                    /* 0x10460  82  VidGetPartitionIds */
  SetLastError(0x32);
  return 0;
}



===== VidGetProcessorTopology @ 180010490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetProcessorTopology
          (undefined8 param_1,undefined8 param_2,undefined1 *param_3,undefined4 *param_4,
          undefined4 *param_5,uint *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e4;
  DWORD local_e0 [2];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  uint local_bc;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x10490  84  VidGetProcessorTopology */
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_c8 = 0;
  local_c0 = 0;
  local_bc = local_bc & 0xffffff00;
  uVar5 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_d8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = (undefined1)local_c8;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_c8._4_4_;
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = local_c0;
      }
      if (param_6 == (uint *)0x0) {
        return 1;
      }
      *param_6 = local_bc;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidGetProcessorTopology");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_6c = 0;
    local_78 = &local_e4;
    local_5c = 0;
    local_68 = local_e0;
    local_e4 = 0x228b;
    local_70 = 4;
    local_60 = 4;
    local_e0[0] = DVar2;
    _tlgCreate1Sz_char(local_58,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverNumaGetProcessorTopology) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidGetRootReferenceTime @ 1800106e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGetRootReferenceTime(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [8];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x106e0  85  VidGetRootReferenceTime */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidGetRootReferenceTime");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8 + 1;
    local_3c = 0;
    local_48 = local_b8;
    local_50 = 4;
    local_40 = 4;
    local_b8[1] = 0xce9;
    local_b8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverGetRootReferenceTime) | (0x0 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGetRpcSession @ 1800108d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetRpcSession(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x108d0  86  VidGetRpcSession */
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_c0 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  if (((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) ||
     (param_4 == (undefined8 *)0x0)) {
    VidlpTraceError0("VidGetRpcSession","onecore\\vm\\vid\\dll\\src\\viddll.c",0x19c8,param_4);
  }
  else {
    uVar5 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_d0;
        *param_3 = uStack_c8;
        *param_4 = local_c0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidGetRpcSession");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_e8;
      local_5c = 0;
      local_68 = &local_e4;
      local_70 = 4;
      local_60 = 4;
      local_e8 = 0x19cf;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCryptGetSession) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetSecurityCookie @ 180010b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetSecurityCookie(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  undefined4 local_b8;
  DWORD local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x10b30  87  VidGetSecurityCookie */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b0 = 0;
  if (param_2 == (undefined8 *)0x0) {
    VidlpTraceError0("VidGetSecurityCookie","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1a02,param_4);
  }
  else {
    uVar5 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_a8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_b0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_78,"VidGetSecurityCookie");
      _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_58 = &local_b8;
      local_b8 = 0x1a09;
      local_48 = &local_b4;
      local_50 = 4;
      local_40 = 4;
      local_b4 = DVar2;
      _tlgCreate1Sz_char(local_38,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCryptGetSecurityCookie) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidGetSystemTopology @ 180010d60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidGetSystemTopology
          (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined1 *param_5,void *param_6,byte *param_7)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined1 auStackY_558 [32];
  undefined4 *local_508;
  undefined8 local_500;
  undefined8 local_4f8;
  undefined8 uStack_4f0;
  byte local_4e8 [4];
  undefined4 local_4e4;
  undefined4 local_4e0;
  undefined4 local_4dc;
  undefined1 local_4d8;
  undefined1 local_4d0 [1032];
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  undefined4 **local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0x10d60  89  VidGetSystemTopology */
  local_58 = __security_cookie ^ (ulonglong)auStackY_558;
  puVar5 = param_4;
  local_508 = param_2;
  local_500 = param_1;
  memset(local_4e8,0,0x418);
  if ((param_6 == (void *)0x0) || ((param_7 != (byte *)0x0 && (0x3f < *param_7)))) {
    uVar6 = 0;
    local_4f8 = 0;
    uStack_4f0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(local_500,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_4f8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        if (local_508 != (undefined4 *)0x0) {
          *local_508 = local_4e4;
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = local_4e0;
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = local_4dc;
        }
        if (param_5 != (undefined1 *)0x0) {
          *param_5 = local_4d8;
        }
        if (param_6 == (void *)0x0) {
          return 1;
        }
        memcpy(param_6,local_4d0,(ulonglong)local_4e8[0] << 4);
        *param_7 = local_4e8[0];
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidGetSystemTopology");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_7c = 0;
      local_88 = &local_508;
      local_6c = 0;
      local_78 = &local_500;
      local_80 = 4;
      local_70 = 4;
      local_508 = (undefined4 *)CONCAT44(local_508._4_4_,0x2228);
      local_500 = CONCAT44(local_500._4_4_,DVar2);
      _tlgCreate1Sz_char(local_68,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverNumaGetTopology) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_c8,&DAT_180029ec4,uVar4,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
    }
    SetLastError(DVar2);
  }
  else {
    SetLastError(0x57);
    VidlpTraceError0("VidGetSystemTopology","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2221,puVar5);
  }
  return 0;
}



===== VidGpaAccessTrackingDisable @ 180011050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGpaAccessTrackingDisable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x11050  93  VidGpaAccessTrackingDisable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidGpaAccessTrackingDisable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x22fb;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGpaAccessTrackingDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidGpaAccessTrackingEnable @ 180011240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidGpaAccessTrackingEnable(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b4 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x11240  94  VidGpaAccessTrackingEnable */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidGpaAccessTrackingEnable");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b4 + 1;
    local_3c = 0;
    local_48 = local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b4[1] = 8999;
    local_b4[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionGpaAccessTrackingEnable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidInitEncryptionKeys @ 180011430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidInitEncryptionKeys(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x11430  96  VidInitEncryptionKeys */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidInitEncryptionKeys");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1a34;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCryptKeysInitialize) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidInjectSyntheticMachineCheckEvent @ 180011620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidInjectSyntheticMachineCheckEvent(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_188 [32];
  DWORD local_138 [8];
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x11620  97  VidInjectSyntheticMachineCheckEvent */
  local_28 = __security_cookie ^ (ulonglong)auStackY_188;
  local_114 = 0;
  memset(&local_114,0,0x70);
  local_110 = *param_3;
  uStack_108 = param_3[1];
  local_100 = param_3[2];
  uStack_f8 = param_3[3];
  local_f0 = param_3[4];
  uStack_e8 = param_3[5];
  local_e0 = param_3[6];
  uStack_d8 = param_3[7];
  local_d0 = param_3[8];
  uStack_c8 = param_3[9];
  local_c0 = param_3[10];
  uStack_b8 = param_3[0xb];
  local_b0 = *(undefined4 *)(param_3 + 0xc);
  uStack_ac = *(undefined4 *)((longlong)param_3 + 100);
  uStack_a8 = *(undefined4 *)(param_3 + 0xd);
  uStack_a4 = *(undefined4 *)((longlong)param_3 + 0x6c);
  uVar4 = 0;
  local_138[2] = 0;
  local_138[3] = 0;
  local_138[4] = 0;
  local_138[5] = 0;
  local_118 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_138[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidInjectSyntheticMachineCheckEvent");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_138 + 1;
    local_3c = 0;
    local_48 = local_138;
    local_50 = 4;
    local_40 = 4;
    local_138[1] = 0x258f;
    local_138[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionInjectSyntheticMachineCheckEvent) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidIsolatedInsertPages @ 180011870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidIsolatedInsertPages
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,ulonglong param_4,
               void *param_5)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined1 auStackY_128 [32];
  undefined4 local_d8 [2];
  void *local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  void **local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x11870  98  VidIsolatedInsertPages */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = param_5;
  local_d8[0] = param_2;
  if (0x1ffffffe < param_4) {
    SetLastError(0x57);
    VidlpTraceError0("VidIsolatedInsertPages","onecore\\vm\\vid\\dll\\src\\viddll.c",0x325c,param_4)
    ;
    return false;
  }
  uVar5 = param_4;
  pvVar3 = GetProcessHeap();
  puVar4 = HeapAlloc(pvVar3,0,(ulonglong)((int)param_4 * 8 + 8));
  if (puVar4 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidIsolatedInsertPages","onecore\\vm\\vid\\dll\\src\\viddll.c",0x3268,uVar5);
    return false;
  }
  *puVar4 = local_d8[0];
  puVar4[1] = param_3;
  memcpy(puVar4 + 2,local_d0,param_4 * 8);
  uVar7 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar3 == (HANDLE)0x0) {
    bVar8 = false;
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,pvVar3);
    if (iVar1 == 0x103) {
      uVar6 = 0;
      NtWaitForSingleObject(pvVar3,0);
      iVar1 = (int)local_c8;
    }
    bVar8 = -1 < iVar1;
    if (!bVar8) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(pvVar3);
    if (bVar8) goto LAB_180011afa;
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidIsolatedInsertPages");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_78 = local_d8;
    local_d8[0] = 0x3279;
    local_68 = &local_d0;
    local_70 = 4;
    local_d0 = (void *)CONCAT44(local_d0._4_4_,DVar2);
    local_60 = 4;
    _tlgCreate1Sz_char(local_58,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionIsolationInsertPages) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar2);
LAB_180011afa:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
  return bVar8;
}



===== VidMapHvGlobalStatsPage @ 180011b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMapHvGlobalStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  uint local_c0;
  undefined4 uStack_bc;
  undefined1 local_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x11b50  99  VidMapHvGlobalStatsPage */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  _local_c0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_b8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidMapHvGlobalStatsPage");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0xd25;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMapHvStatsPageGlobal) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMapHvRootStatsPage @ 180011d60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMapHvRootStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  uint local_c0;
  undefined4 uStack_bc;
  undefined1 local_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x11d60  101  VidMapHvRootStatsPage */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  _local_c0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_b8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidMapHvRootStatsPage");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0xd99;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMapHvStatsPageRoot) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMapHypercallDoorbellPage @ 180011f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMapHypercallDoorbellPage(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  undefined4 local_b8;
  DWORD local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x11f70  102  VidMapHypercallDoorbellPage */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b0 = 0;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_2 = local_b0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidMapHypercallDoorbellPage");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = &local_b8;
    local_3c = 0;
    local_48 = &local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b8 = 0x3171;
    local_b4 = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMapHypercallDoorbellPage) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidMapMemoryBlockPageRange @ 180012170 =====

ulonglong VidMapMemoryBlockPageRange
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    int param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined1 uVar1;
  undefined7 extraout_var;
  undefined4 local_18 [4];
  
                    /* 0x12170  103  VidMapMemoryBlockPageRange */
  local_18[0] = 0;
  if (param_5 != 1) {
    if (param_5 != 2) {
      SetLastError(0x57);
      VidlpTraceError0("VidMapMemoryBlockPageRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x173b,
                       param_4);
      return 0;
    }
    local_18[0] = 1;
  }
  uVar1 = VidMapMemoryBlockPageRangeEx(param_1,param_2,param_3,param_4,local_18,param_6,param_7);
  if ((int)CONCAT71(extraout_var,uVar1) == 0) {
    VidlpTraceError0("VidMapMemoryBlockPageRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x174f,
                     param_4);
  }
  return CONCAT71(extraout_var,uVar1) & 0xffffffff;
}



===== VidMarkPagePoisoned @ 180012220 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMarkPagePoisoned(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x12220  106  VidMarkPagePoisoned */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidMarkPagePoisoned");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x25c2;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMarkPagePoisoned) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidMemPartEnumerate @ 180012410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemPartEnumerate(undefined8 param_1,undefined4 param_2,longlong param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [3];
  undefined4 local_cc;
  longlong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x12410  107  VidMemPartEnumerate */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cc = 0;
  if (param_3 == 0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemPartEnumerate","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2e22,param_4);
  }
  else {
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_d8[2] = param_2;
    local_c8 = param_3;
    local_c0 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        return 1;
      }
    }
    DVar2 = GetLastError();
    if ((DVar2 != 0x7a) && (DVar2 != 0xc0000023)) {
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
        _tlgCreate1Sz_char(local_88,"VidMemPartEnumerate");
        _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_68 = local_d8 + 1;
        local_d8[1] = 0x2e2d;
        local_58 = local_d8;
        local_60 = 4;
        local_50 = 4;
        local_d8[0] = DVar2;
        _tlgCreate1Sz_char(local_48,
                           "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemPartEnumerate) | (0x0 << 10)) << 2) | (0) )"
                          );
        _tlgWriteTransfer_EventWriteTransfer
                  (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
      }
      SetLastError(DVar2);
    }
  }
  return 0;
}



===== VidMemPartGetIndexFromName @ 180012660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
VidMemPartGetIndexFromName(undefined8 param_1,wchar_t *param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD dwErrCode;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_e8 [32];
  undefined4 local_b8;
  DWORD local_b4 [3];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x12660  108  VidMemPartGetIndexFromName */
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar4 = 0;
  if (param_3 == (wchar_t *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemPartGetIndexFromName","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2d74,
                     param_4);
  }
  else {
    uVar2 = 0;
    uVar4 = 1;
    pwVar5 = param_3;
    while( true ) {
      uVar3 = (uint)uVar2;
      if (2 < uVar3) break;
      param_4 = 0xffffffff;
      pwVar5 = param_2;
      iVar1 = CompareStringW(0x7f,0,param_2,-1,(PCNZWCH)(&g_VidMemPartIndexToString)[uVar2],-1);
      if (iVar1 == 2) {
        *(undefined4 *)param_3 = (&g_VidMemPartId)[uVar2];
        return 1;
      }
      uVar2 = (ulonglong)(uVar3 + 1);
    }
    if (uVar3 == 3) {
      SetLastError(0x57);
      uVar4 = 0;
      dwErrCode = GetLastError();
      if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
        _tlgCreate1Sz_char(local_88,"VidMemPartGetIndexFromName");
        _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_5c = 0;
        local_4c = 0;
        local_68 = &local_b8;
        local_58 = local_b4;
        local_60 = 4;
        local_50 = 4;
        local_b8 = 0x2d8e;
        local_b4[0] = dwErrCode;
        _tlgCreate1Sz_wchar_t(local_48,param_2);
        _tlgWriteTransfer_EventWriteTransfer
                  (local_a8,&DAT_180029ad3,pwVar5,param_4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
      }
      SetLastError(dwErrCode);
    }
  }
  return uVar4;
}



===== VidMemPartGetNameFromIndex @ 180012810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
VidMemPartGetNameFromIndex(undefined8 param_1,int param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  uint uVar1;
  HRESULT HVar2;
  DWORD dwErrCode;
  ulonglong uVar3;
  byte *pbVar4;
  STRSAFE_LPCWSTR pszSrc;
  undefined1 auStackY_d8 [32];
  HRESULT local_a8;
  DWORD local_a4;
  int local_a0 [2];
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  longlong local_78 [2];
  longlong local_68 [2];
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  HRESULT *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
                    /* 0x12810  109  VidMemPartGetNameFromIndex */
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_3 == (STRSAFE_LPWSTR)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemPartGetNameFromIndex","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2dc7,
                     param_3);
    return 0;
  }
  uVar3 = 0;
  while (uVar1 = (uint)uVar3, uVar1 < 3) {
    if ((&g_VidMemPartId)[uVar3] == param_2) {
      pszSrc = (STRSAFE_LPCWSTR)(&g_VidMemPartIndexToString)[uVar3];
      goto LAB_180012899;
    }
    uVar3 = (ulonglong)(uVar1 + 1);
  }
  pszSrc = (STRSAFE_LPCWSTR)0x0;
  if (uVar1 == 3) {
    SetLastError(0x57);
    dwErrCode = GetLastError();
    if ((DAT_18002e000 < 3) || (uVar3 = _tlgKeywordOn(), (char)uVar3 == '\0')) goto LAB_18001295e;
    _tlgCreate1Sz_char(local_78,"VidMemPartGetNameFromIndex");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_a8 = 0x2ddb;
    local_58 = &local_a8;
    local_38 = local_a0;
    pbVar4 = &DAT_180029a7c;
    local_a0[0] = param_2;
  }
  else {
LAB_180012899:
    HVar2 = StringCchCopyW(param_3,param_4,pszSrc);
    if (-1 < HVar2) {
      return 1;
    }
    SetLastError(0x57);
    dwErrCode = GetLastError();
    if ((DAT_18002e000 < 3) || (uVar3 = _tlgKeywordOn(), (char)uVar3 == '\0')) goto LAB_18001295e;
    _tlgCreate1Sz_char(local_78,"VidMemPartGetNameFromIndex");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_a0[0] = 0x2de7;
    local_58 = local_a0;
    local_38 = &local_a8;
    pbVar4 = &DAT_180029a31;
    local_a8 = HVar2;
  }
  local_48 = &local_a4;
  local_4c = 0;
  local_3c = 0;
  local_2c = 0;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_a4 = dwErrCode;
  _tlgWriteTransfer_EventWriteTransfer(local_38,pbVar4,pszSrc,param_3,7,local_98);
LAB_18001295e:
  SetLastError(dwErrCode);
  return 0;
}



===== VidMemReserveGetTarget @ 180012a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMemReserveGetTarget(undefined8 param_1,undefined8 param_2,byte *param_3,void *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined1 auStackY_338 [32];
  undefined4 local_2e4;
  DWORD local_2e0 [2];
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  byte local_2c8 [8];
  undefined1 local_2c0 [520];
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x12a20  110  VidMemReserveGetTarget */
  local_48 = __security_cookie ^ (ulonglong)auStackY_338;
  pvVar5 = param_4;
  memset(local_2c8,0,0x208);
  if ((param_4 == (void *)0x0) || (param_3 == (byte *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemReserveGetTarget","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2ca1,pvVar5);
  }
  else {
    *param_3 = 0;
    uVar6 = 0;
    local_2d8 = 0;
    uStack_2d0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_2d8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_2c8[0];
        memcpy(param_4,local_2c0,(ulonglong)local_2c8[0] << 3);
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidMemReserveGetTarget");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_2e4;
      local_5c = 0;
      local_68 = local_2e0;
      local_2e4 = 0x2cad;
      local_70 = 4;
      local_60 = 4;
      local_2e0[0] = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveTargetGet) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMemReserveIoSpaceConvert @ 180012cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemReserveIoSpaceConvert(undefined8 param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  uint local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x12cd0  111  VidMemReserveIoSpaceConvert */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  _local_b0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_a8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidMemReserveIoSpaceConvert");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x2d3d;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveIoSpaceConvert) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMemReserveIoSpacePagesAdd @ 180012ed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemReserveIoSpacePagesAdd
          (undefined8 param_1,byte param_2,undefined8 param_3,longlong param_4,uint param_5,
          undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulonglong uStack_c0;
  longlong local_b8;
  ulonglong uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x12ed0  112  VidMemReserveIoSpacePagesAdd */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_6 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemReserveIoSpacePagesAdd","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2c1f,
                     param_4);
  }
  else {
    uStack_b0 = (ulonglong)param_5;
    *param_6 = 0;
    uStack_c0 = (ulonglong)param_2;
    local_b8 = param_4 << 0x20;
    uVar5 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_c8 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_6 = local_e0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidMemReserveIoSpacePagesAdd");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_e8;
      local_e8 = 0x2c2e;
      local_58 = &local_e4;
      local_60 = 4;
      local_50 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveIoSpaceAdd) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMemReserveIoSpacePagesRelease @ 180013130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemReserveIoSpacePagesRelease
          (undefined8 param_1,byte param_2,undefined8 param_3,uint param_4,uint param_5)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  ulonglong uStack_b8;
  longlong local_b0;
  ulonglong uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x13130  113  VidMemReserveIoSpacePagesRelease */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  uStack_b8 = (ulonglong)param_2;
  local_b0 = (ulonglong)param_4 << 0x20;
  uStack_a8 = (ulonglong)param_5;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidMemReserveIoSpacePagesRelease");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x2c69;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveIoSpaceRelease) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMemReservePagesAdd @ 180013340 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemReservePagesAdd
          (undefined8 param_1,byte param_2,undefined8 param_3,longlong param_4,uint param_5,
          undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulonglong uStack_c0;
  longlong local_b8;
  ulonglong uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x13340  114  VidMemReservePagesAdd */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_6 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemReservePagesAdd","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2b9e,param_4);
  }
  else {
    uStack_b0 = (ulonglong)param_5;
    *param_6 = 0;
    uStack_c0 = (ulonglong)param_2;
    local_b8 = param_4 << 0x20;
    uVar5 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_c8 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_6 = local_e0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidMemReservePagesAdd");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_e8;
      local_e8 = 0x2bad;
      local_58 = &local_e4;
      local_60 = 4;
      local_50 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveAdd) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMemReservePagesRelease @ 1800135a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemReservePagesRelease
          (undefined8 param_1,byte param_2,undefined8 param_3,uint param_4,uint param_5)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  ulonglong uStack_b8;
  longlong local_b0;
  ulonglong uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x135a0  115  VidMemReservePagesRelease */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  uStack_b8 = (ulonglong)param_2;
  local_b0 = (ulonglong)param_4 << 0x20;
  uStack_a8 = (ulonglong)param_5;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidMemReservePagesRelease");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x2be6;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveRelease) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMemReserveSetTarget @ 1800137b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMemReserveSetTarget(undefined8 param_1,undefined4 param_2,byte param_3,void *param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined1 auStackY_338 [32];
  DWORD local_2e8 [8];
  undefined4 local_2c8;
  byte local_2c4;
  undefined1 local_2c3 [3];
  undefined1 local_2c0 [520];
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  DWORD *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x137b0  116  VidMemReserveSetTarget */
  local_48 = __security_cookie ^ (ulonglong)auStackY_338;
  pvVar4 = param_4;
  memset(local_2c3,0,0x203);
  if (param_3 < 0x41) {
    if (param_4 == (void *)0x0) {
      SetLastError(0x57);
      VidlpTraceError0("VidMemReserveSetTarget","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2cf5,pvVar4
                      );
    }
    else {
      local_2c8 = param_2;
      local_2c4 = param_3;
      memcpy(local_2c0,param_4,(ulonglong)param_3 << 3);
      uVar5 = 0;
      local_2e8[2] = 0;
      local_2e8[3] = 0;
      local_2e8[4] = 0;
      local_2e8[5] = 0;
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (hObject == (HANDLE)0x0) {
        uVar3 = 0x129;
        VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
      }
      else {
        uVar5 = 0;
        uVar3 = 0;
        DVar1 = NtDeviceIoControlFile(param_1,hObject);
        if (DVar1 == 0x103) {
          uVar3 = 0;
          NtWaitForSingleObject(hObject,0);
          DVar1 = local_2e8[2];
        }
        if (-1 >= (int)DVar1) {
          dwErrCode = RtlNtStatusToDosError(DVar1);
          SetLastError(dwErrCode);
        }
        CloseHandle(hObject);
        if (-1 < (int)DVar1) {
          return 1;
        }
      }
      GetLastError();
      DVar1 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
        _tlgCreate1Sz_char(local_98,"VidMemReserveSetTarget");
        _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_78 = local_2e8 + 1;
        local_2e8[1] = 0x2d06;
        local_68 = local_2e8;
        local_70 = 4;
        local_60 = 4;
        local_2e8[0] = DVar1;
        _tlgCreate1Sz_char(local_58,
                           "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverMemReserveTargetSet) | (0x0 << 10)) << 2) | (0) )"
                          );
        _tlgWriteTransfer_EventWriteTransfer
                  (local_b8,&DAT_180029ec4,uVar3,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
      }
      SetLastError(DVar1);
    }
  }
  else {
    SetLastError(0x57);
    VidlpTraceError0("VidMemReserveSetTarget","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2ced,pvVar4);
  }
  return 0;
}



===== VidMemXferConnectClose @ 180013a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMemXferConnectClose(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x13a70  117  VidMemXferConnectClose */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidMemXferConnectClose");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2781;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryXferConnectClose) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMemXferConnectDisable @ 180013c60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMemXferConnectDisable(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x13c60  118  VidMemXferConnectDisable */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidMemXferConnectDisable");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x27aa;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryXferConnectDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidMemXferConnectEnable @ 180013e50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidMemXferConnectEnable(undefined8 param_1,STRSAFE_LPWSTR param_2,size_t param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HRESULT HVar3;
  HANDLE hObject;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStackY_328 [32];
  undefined4 local_2d8;
  DWORD local_2d4;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  wchar_t local_2b8 [264];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x13e50  119  VidMemXferConnectEnable */
  local_38 = __security_cookie ^ (ulonglong)auStackY_328;
  memset(local_2b8,0,0x208);
  if (param_2 == (STRSAFE_LPWSTR)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemXferConnectEnable","onecore\\vm\\vid\\dll\\src\\viddll.c",0x26c4,param_4
                    );
  }
  else {
    uVar6 = 0;
    local_2d0 = 0;
    uStack_2c8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar5 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
    }
    else {
      uVar6 = 0;
      uVar5 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar5 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_2d0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        HVar3 = StringCchCopyW(param_2,param_3,local_2b8);
        if (HVar3 < 0) {
          SetLastError(0x57);
          VidlpTraceError0("VidMemXferConnectEnable","onecore\\vm\\vid\\dll\\src\\viddll.c",0x26db,
                           uVar6);
          return 0;
        }
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidMemXferConnectEnable");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_2d8;
      local_4c = 0;
      local_58 = &local_2d4;
      local_60 = 4;
      local_50 = 4;
      local_2d8 = 0x26cb;
      local_2d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryXferConnectEnable) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar5,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidMemXferConnectOpen @ 180014100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidMemXferConnectOpen(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x14100  120  VidMemXferConnectOpen */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidMemXferConnectOpen");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2708;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryXferConnectOpen) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidMemXferSendAsync @ 180014300 =====

undefined8
VidMemXferSendAsync(HANDLE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   LPOVERLAPPED param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  DWORD local_res10 [6];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
                    /* 0x14300  121  VidMemXferSendAsync */
  uVar3 = 0;
  local_res10[0] = 0;
  local_28 = param_2;
  local_20 = param_3;
  local_18 = param_4;
  if (param_5 == (LPOVERLAPPED)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidMemXferSendAsync","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2745,param_4);
  }
  else {
    uVar4 = 0x18;
    BVar1 = DeviceIoControl(param_1,0x2211f8,&local_28,0x18,(LPVOID)0x0,0,local_res10,param_5);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 != 0x3e5) {
        VidlpTraceError0("VidMemXferSendAsync","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2755,uVar4);
      }
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



===== VidPhuBegin @ 1800143d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidPhuBegin(undefined8 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [3];
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x143d0  125  VidPhuBegin */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_ac = *param_3;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8[2] = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidPhuBegin");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8 + 1;
    local_3c = 0;
    local_48 = local_b8;
    local_50 = 4;
    local_40 = 4;
    local_b8[1] = 0x113c;
    local_b8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuBegin) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidPhuCommit @ 1800145c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidPhuCommit(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x145c0  126  VidPhuCommit */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidPhuCommit");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1162;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuCommit) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidPhuEnd @ 1800147b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidPhuEnd(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x147b0  127  VidPhuEnd */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidPhuEnd");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1181;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuEnd) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidPhuFreePersistedData @ 1800149a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidPhuFreePersistedData(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [8];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x149a0  128  VidPhuFreePersistedData */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidPhuFreePersistedData");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8 + 1;
    local_3c = 0;
    local_48 = local_b8;
    local_50 = 4;
    local_40 = 4;
    local_b8[1] = 0x1275;
    local_b8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverPhuFreePersistedData) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidPhuOpenMemoryBlockFile @ 180014b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidPhuOpenMemoryBlockFile
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x14b90  129  VidPhuOpenMemoryBlockFile */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_ac = 0;
  local_d0 = 0;
  if (param_4 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidPhuOpenMemoryBlockFile","onecore\\vm\\vid\\dll\\src\\viddll.c",0x11b6,
                     param_4);
  }
  else {
    uVar5 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_b8 = param_2;
    local_b0 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidPhuOpenMemoryBlockFile");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x11c1;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuOpenMemoryBlockFile) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidPhuPersistGpaRange @ 180014dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidPhuPersistGpaRange(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x14dd0  130  VidPhuPersistGpaRange */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidPhuPersistGpaRange","onecore\\vm\\vid\\dll\\src\\viddll.c",0x11f9,param_4);
  }
  else {
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    local_c8 = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidPhuPersistGpaRange");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x1203;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuPersistGpaRange) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidPhuPersistMemoryBlock @ 180015010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidPhuPersistMemoryBlock
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x15010  131  VidPhuPersistMemoryBlock */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidPhuPersistMemoryBlock","onecore\\vm\\vid\\dll\\src\\viddll.c",0x123c,
                     param_4);
  }
  else {
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    local_c8 = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidPhuPersistMemoryBlock");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x1246;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPhuPersistMemoryBlock) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidPopulateCpuidInformation @ 180015250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidPopulateCpuidInformation
               (undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  undefined1 auStackY_128 [32];
  undefined8 local_d8;
  undefined4 local_d0 [2];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x15250  132  VidPopulateCpuidInformation */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = param_4 & 0xffffffff;
  local_d8 = param_1;
  if ((int)param_4 == 0) {
    SetLastError(0x57);
    VidlpTraceError0("VidPopulateCpuidInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x32b8,
                     param_4);
    return false;
  }
  uVar8 = (int)param_4 + 4;
  if (uVar8 < 4) {
    VidlpTraceError0("VidPopulateCpuidInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x32c1,
                     param_4);
    return false;
  }
  pvVar3 = GetProcessHeap();
  puVar4 = HeapAlloc(pvVar3,8,(ulonglong)uVar8);
  if (puVar4 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidPopulateCpuidInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x32cd,
                     param_4);
    return false;
  }
  *puVar4 = param_2;
  memcpy(puVar4 + 1,param_3,uVar5);
  uVar7 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar3 == (HANDLE)0x0) {
    bVar9 = false;
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    iVar1 = NtDeviceIoControlFile(local_d8,pvVar3);
    if (iVar1 == 0x103) {
      uVar6 = 0;
      NtWaitForSingleObject(pvVar3,0);
      iVar1 = (int)local_c8;
    }
    bVar9 = -1 < iVar1;
    if (!bVar9) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(pvVar3);
    if (bVar9) goto LAB_1800154c8;
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidPopulateCpuidInformation");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_78 = local_d0;
    local_d0[0] = 0x32df;
    local_68 = &local_d8;
    local_70 = 4;
    local_d8 = CONCAT44(local_d8._4_4_,DVar2);
    local_60 = 4;
    _tlgCreate1Sz_char(local_58,"VID_IOCTL_POPULATE_CPUID_INFORMATION");
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar2);
LAB_1800154c8:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
  return bVar9;
}



===== VidPrefetchDirectMapRanges @ 180015540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidPrefetchDirectMapRanges(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [3];
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x15540  133  VidPrefetchDirectMapRanges */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_bc = 0;
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c8[2] = param_2;
  local_b8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidPrefetchDirectMapRanges");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x3004;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPrefetchDirectMapRanges) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidPreparePartitionOperation @ 180015730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidPreparePartitionOperation(undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE pvVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [8];
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  DWORD *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x15730  134  VidPreparePartitionOperation */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar4 = param_4 & 0xffffffff;
  if ((param_3 == (void *)0x0) && ((int)param_4 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidPreparePartitionOperation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x37e2,
                     param_4);
    return 0;
  }
  uVar7 = 4;
  if ((param_3 != (void *)0x0) && (uVar7 = (int)param_4 + 4, uVar7 < 4)) {
    VidlpTraceError0("VidPreparePartitionOperation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x37f2,
                     param_4);
    return 0;
  }
  pvVar2 = GetProcessHeap();
  puVar3 = HeapAlloc(pvVar2,8,(ulonglong)uVar7);
  if (puVar3 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidPreparePartitionOperation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x37fe,
                     param_4);
    return 0;
  }
  *puVar3 = param_2;
  if (param_3 != (void *)0x0) {
    memcpy(puVar3 + 1,param_3,uVar4);
  }
  uVar6 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar2 == (HANDLE)0x0) {
    uVar5 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar6);
  }
  else {
    uVar6 = 0;
    uVar5 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,pvVar2);
    if (DVar1 == 0x103) {
      uVar5 = 0;
      NtWaitForSingleObject(pvVar2,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(pvVar2);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidPreparePartitionOperation");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_78 = local_d8 + 1;
    local_d8[1] = 0x3812;
    local_68 = local_d8;
    local_70 = 4;
    local_60 = 4;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_58,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionOperationPrepare) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar5,uVar6,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidProtectMemoryBlockPages @ 180015a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidProtectMemoryBlockPages(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x15a10  135  VidProtectMemoryBlockPages */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidProtectMemoryBlockPages");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x12a9;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDbgProtectMemoryBlockEnable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidQueryMemoryBlockFaultClusterInfo @ 180015c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidQueryMemoryBlockFaultClusterInfo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong *param_4,
          undefined1 *param_5)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8;
  undefined7 local_b7;
  undefined1 uStack_b0;
  undefined7 uStack_af;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x15c10  136  VidQueryMemoryBlockFaultClusterInfo */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  uStack_b0 = 0;
  local_b8 = 0;
  local_b7 = 0;
  local_d0 = *param_4;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_e0 = param_2;
  local_d8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = CONCAT71(uStack_af,uStack_b0);
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = local_b8;
      }
      if (local_d0 < CONCAT71(uStack_af,uStack_b0)) {
        SetLastError(0x7a);
        return 0;
      }
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidQueryMemoryBlockFaultClusterInfo");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_e8;
    local_4c = 0;
    local_58 = &local_e4;
    local_60 = 4;
    local_50 = 4;
    local_e8 = 0x13c2;
    local_e4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionMemoryBlockQueryFaultClusterInfo) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidQueryPartitionInformation @ 180015e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidQueryPartitionInformation
               (undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4,void *param_5,
               uint *param_6)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE pvVar4;
  undefined4 *puVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  bool bVar11;
  undefined1 auStackY_138 [32];
  uint local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  void *local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x15e60  138  VidQueryPartitionInformation */
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  bVar11 = false;
  local_d8 = param_5;
  uVar7 = param_4 & 0xffffffff;
  local_e4 = param_2;
  local_e0 = param_1;
  if (((param_6 == (uint *)0x0) || ((param_3 != (void *)0x0) != ((int)param_4 != 0))) ||
     ((param_5 != (void *)0x0) != (*param_6 != 0))) {
    SetLastError(0x57);
    VidlpTraceError0("VidQueryPartitionInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x332c,
                     param_4);
    return false;
  }
  uVar10 = (int)param_4 + 4;
  if (uVar10 < 4) {
    VidlpTraceError0("VidQueryPartitionInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x3334,
                     param_4);
    return false;
  }
  local_e8 = *param_6 + 4;
  if (local_e8 < 4) {
    VidlpTraceError0("VidQueryPartitionInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x333c,
                     param_4);
    return false;
  }
  pvVar4 = GetProcessHeap();
  puVar5 = HeapAlloc(pvVar4,8,(ulonglong)uVar10);
  uVar10 = local_e8;
  if (puVar5 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidQueryPartitionInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x3347,
                     param_4);
    return false;
  }
  pvVar4 = GetProcessHeap();
  puVar6 = HeapAlloc(pvVar4,8,(ulonglong)uVar10);
  if (puVar6 == (uint *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidQueryPartitionInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x3352,
                     param_4);
    goto LAB_1800161ab;
  }
  *puVar5 = local_e4;
  if (param_3 != (void *)0x0) {
    memcpy(puVar5 + 1,param_3,uVar7);
  }
  uVar9 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar4 == (HANDLE)0x0) {
    uVar8 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar9);
LAB_1800160b1:
    GetLastError();
    DVar3 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar7 = _tlgKeywordOn(), (char)uVar7 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidQueryPartitionInformation");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_e4;
      local_5c = 0;
      local_68 = &local_e8;
      local_70 = 4;
      local_60 = 4;
      local_e4 = 0x3363;
      local_e8 = DVar3;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionQueryInformation) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar8,uVar9,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar3);
  }
  else {
    uVar9 = 0;
    uVar8 = 0;
    iVar2 = NtDeviceIoControlFile(local_e0,pvVar4);
    if (iVar2 == 0x103) {
      uVar8 = 0;
      NtWaitForSingleObject(pvVar4,0);
      iVar2 = (int)local_d0;
    }
    bVar11 = -1 < iVar2;
    if (!bVar11) {
      DVar3 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar3);
    }
    CloseHandle(pvVar4);
    if (!bVar11) goto LAB_1800160b1;
    uVar10 = *param_6;
    uVar1 = *puVar6;
    if (uVar10 < uVar1) {
      SetLastError(0x7a);
    }
    bVar11 = uVar10 >= uVar1 && bVar11;
    *param_6 = *puVar6;
  }
  if ((bVar11) && (local_d8 != (void *)0x0)) {
    memcpy(local_d8,puVar6 + 1,(ulonglong)*puVar6);
  }
LAB_1800161ab:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar5);
  if (puVar6 != (uint *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar6);
  }
  return bVar11;
}



===== VidReadMemoryBlockPageRange @ 180016290 =====

void VidReadMemoryBlockPageRange
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
                    /* 0x16290  140  VidReadMemoryBlockPageRange */
  VidReadWriteMemoryBlockPageRange
            (param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,(undefined8 *)0x0,0);
  return;
}



===== VidReadWriteMappedMemoryBlockPageRange @ 1800162e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidReadWriteMappedMemoryBlockPageRange
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,int param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [2];
  longlong local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined1 local_c0;
  undefined4 local_bf;
  undefined2 local_bb;
  undefined1 local_b9;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x162e0  141  VidReadWriteMappedMemoryBlockPageRange */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_bf = 0;
  local_bb = 0;
  local_b9 = 0;
  if (param_2 == -1) {
    SetLastError(0x57);
    VidlpTraceError0("VidReadWriteMappedMemoryBlockPageRange","onecore\\vm\\vid\\dll\\src\\viddll.c"
                     ,0x1950,param_4);
  }
  else {
    local_c0 = param_6 != 0;
    local_c8 = param_5;
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_e0 = param_2;
    local_d8 = param_3;
    local_d0 = param_4;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidReadWriteMappedMemoryBlockPageRange");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_e8 + 1;
      local_e8[1] = 0x195e;
      local_58 = local_e8;
      local_60 = 4;
      local_50 = 4;
      local_e8[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionReadWriteMappedMemoryBlockPageRange) | (0x1 << 10)) << 2) | (3) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidRegisterApicEoiHandler @ 180016530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidRegisterApicEoiHandler(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [3];
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x16530  143  VidRegisterApicEoiHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cc = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d8[2] = param_2;
  local_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRegisterApicEoiHandler");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0x994;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterApicEoiHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRegisterCpuidHandler @ 180016740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRegisterCpuidHandler
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x16740  144  VidRegisterCpuidHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  local_c4 = 0;
  local_c8 = param_2;
  local_c0 = param_3;
  if (param_4 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidRegisterCpuidHandler","onecore\\vm\\vid\\dll\\src\\viddll.c",0x776,param_4)
    ;
  }
  else {
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = local_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidRegisterCpuidHandler");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = &local_d8;
      local_d8 = 0x77e;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterCpuidHandler) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidRegisterCpuidResult @ 180016980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRegisterCpuidResult
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4,
          undefined8 *param_5,uint param_6)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [7];
  undefined4 uStack_cc;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  ulonglong uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x16980  145  VidRegisterCpuidResult */
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  stack0xffffffffffffff30 = CONCAT44(param_3,param_2);
  uStack_b8 = *param_5;
  local_b0 = param_5[1];
  uStack_a8 = (ulonglong)param_6;
  uStack_c8 = *param_4;
  local_c0 = param_4[1];
  uVar4 = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_e8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidRegisterCpuidResult");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_e8 + 1;
    local_3c = 0;
    local_48 = local_e8;
    local_50 = 4;
    local_40 = 4;
    local_e8[1] = 0x922;
    local_e8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterCpuidResult) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidRegisterExceptionHandler @ 180016ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRegisterExceptionHandler
          (undefined8 param_1,undefined1 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  undefined1 local_d0;
  undefined2 local_cf;
  undefined1 local_cd;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x16ba0  146  VidRegisterExceptionHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cf = 0;
  local_cd = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_2;
  local_cc = param_3;
  local_c8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRegisterExceptionHandler");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = local_d8 + 1;
    local_d8[1] = 0x86f;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterExceptionHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRegisterHypervisorRestartHandler @ 180016db0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRegisterHypervisorRestartHandler(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [3];
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x16db0  147  VidRegisterHypervisorRestartHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cc = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d8[2] = param_2;
  local_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRegisterHypervisorRestartHandler");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0x8e1;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterHypervisorRestartHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRegisterMsrAddressHandler @ 180016fc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidRegisterMsrAddressHandler(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  ulonglong local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x16fc0  149  VidRegisterMsrAddressHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = (ulonglong)param_2;
  local_c0 = 1;
  uVar5 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  uStack_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRegisterMsrAddressHandler");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0x7fa;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterMsrHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRegisterMsrHandler @ 1800171c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidRegisterMsrHandler(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [4];
  undefined8 uStack_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x171c0  150  VidRegisterMsrHandler */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_b0 = 0;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  uStack_b8 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidRegisterMsrHandler");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x830;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterMsrHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRegisterTripleFaultHandler @ 1800173d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidRegisterTripleFaultHandler(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [3];
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x173d0  151  VidRegisterTripleFaultHandler */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_cc = 0;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d8[2] = param_2;
  local_c8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRegisterTripleFaultHandler");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_d8 + 1;
    local_4c = 0;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[1] = 0x8a8;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRegisterTripleFaultHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidReleaseEncryptionKeys @ 1800175e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidReleaseEncryptionKeys(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x175e0  152  VidReleaseEncryptionKeys */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidReleaseEncryptionKeys");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x1a5c;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionCryptKeysRelease) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidReleasePages @ 1800177d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidReleasePages(undefined8 param_1,byte param_2,undefined8 param_3)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  ulonglong local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x177d0  153  VidReleasePages */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b0 = (ulonglong)param_2;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  uStack_a8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidReleasePages");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x1c22;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionRelease) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidReopenExoPartition @ 1800179c0 =====

HANDLE VidReopenExoPartition(HANDLE param_1)

{
  DWORD dwErrCode;
  HANDLE pvVar1;
  undefined8 uVar2;
  
                    /* 0x179c0  154  VidReopenExoPartition */
  uVar2 = 0x40000000;
  pvVar1 = ReOpenFile(param_1,0x80000000,0,0x40000000);
  if (pvVar1 == (HANDLE)0xffffffffffffffff) {
    dwErrCode = GetLastError();
    VidlpTraceError0("VidpReopenVidObject","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",0x273,
                     uVar2);
    SetLastError(dwErrCode);
    pvVar1 = (HANDLE)0xffffffffffffffff;
  }
  return pvVar1;
}



===== VidReservePages @ 180017a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidReservePages(undefined8 param_1,byte param_2,undefined8 param_3,undefined8 param_4,
                    uint param_5,undefined8 *param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [2];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x17a40  155  VidReservePages */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e0 = 0;
  bVar6 = false;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if (param_6 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidReservePages","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1bd6,param_4);
  }
  else {
    *param_6 = 0;
    local_b8 = (ulonglong)param_5;
    uStack_c0 = CONCAT44((int)param_4,(uint)param_2);
    uVar5 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_c8 = param_3;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_d8;
      }
      bVar6 = -1 < iVar1;
      if (!bVar6) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (bVar6) goto LAB_180017c84;
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidReservePages");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = local_e8 + 1;
      local_4c = 0;
      local_58 = local_e8;
      local_60 = 4;
      local_50 = 4;
      local_e8[1] = 0x1be4;
      local_e8[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionReserve) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
    if (bVar6) goto LAB_180017c84;
  }
  DVar2 = GetLastError();
  if (DVar2 != 0x80370001) {
    return bVar6;
  }
LAB_180017c84:
  *param_6 = local_e0;
  return bVar6;
}



===== VidResetPartition @ 180017cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidResetPartition(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b4 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x17cb0  156  VidResetPartition */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidResetPartition");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b4 + 1;
    local_3c = 0;
    local_48 = local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b4[1] = 0x2623;
    local_b4[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionReset) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidResetPoisonedPage @ 180017ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidResetPoisonedPage(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x17ea0  157  VidResetPoisonedPage */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidResetPoisonedPage");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x25f5;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionResetPoisonedPage) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidRestorePartitionState @ 180018090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidRestorePartitionState(HANDLE param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [2];
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x18090  158  VidRestorePartitionState */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  if ((param_2 & 4) != 0) {
    param_1 = VidpGetGlobalVidObject(0,param_2,param_3,param_4);
  }
  local_c4 = (undefined4)param_2;
  local_c8 = (undefined4)param_4;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidRestorePartitionState");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = local_d8 + 1;
    local_d8[1] = 0xbd1;
    local_58 = local_d8;
    local_60 = 4;
    local_50 = 4;
    local_d8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | ((VidIoctlDualRestorePartitionState) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSavePartitionState @ 1800182a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001800184e8) */

undefined1
VidSavePartitionState(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x182a0  159  VidSavePartitionState */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  if (param_4 == (undefined4 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidSavePartitionState","onecore\\vm\\vid\\dll\\src\\viddll.c",0xb4d,param_4);
  }
  else {
    local_c0 = *param_4;
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = param_3;
    local_bc = param_2;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = 0;
        return 1;
      }
    }
    DVar2 = GetLastError();
    if ((DVar2 != 0x7a) && (DVar2 != 0xc0000023)) {
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
        _tlgCreate1Sz_char(local_88,"VidSavePartitionState");
        _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_5c = 0;
        local_68 = &local_d4;
        local_4c = 0;
        local_58 = local_d0;
        local_d4 = 0xb59;
        local_60 = 4;
        local_50 = 4;
        local_d0[0] = DVar2;
        _tlgCreate1Sz_char(local_48,
                           "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSavePartitionState) | (0x1 << 10)) << 2) | (0) )"
                          );
        _tlgWriteTransfer_EventWriteTransfer
                  (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
      }
      SetLastError(DVar2);
    }
  }
  return 0;
}



===== VidSchedulerAssistRestore @ 180018530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSchedulerAssistRestore(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x18530  160  VidSchedulerAssistRestore */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  if ((param_2 == 0) && (param_3 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidSchedulerAssistRestore","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1f41,
                     param_4);
  }
  else {
    uVar4 = 0;
    local_c8[2] = 0;
    local_c8[3] = 0;
    local_c8[4] = 0;
    local_c8[5] = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar3 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
    }
    else {
      uVar4 = 0;
      uVar3 = 0;
      DVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (DVar1 == 0x103) {
        uVar3 = 0;
        NtWaitForSingleObject(hObject,0);
        DVar1 = local_c8[2];
      }
      if (-1 >= (int)DVar1) {
        dwErrCode = RtlNtStatusToDosError(DVar1);
        SetLastError(dwErrCode);
      }
      CloseHandle(hObject);
      if (-1 < (int)DVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidSchedulerAssistRestore");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_c8 + 1;
      local_c8[1] = 0x1f4b;
      local_58 = local_c8;
      local_60 = 4;
      local_50 = 4;
      local_c8[0] = DVar1;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSchedulerAssistRestore) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar1);
  }
  return 0;
}



===== VidSchedulerAssistSave @ 180018760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSchedulerAssistSave(undefined8 param_1,longlong param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  undefined4 *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0x18760  161  VidSchedulerAssistSave */
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar6 = 0;
  if ((param_2 == 0) && (param_3 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidSchedulerAssistSave","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1f82,param_4)
    ;
  }
  else {
    *param_4 = 0;
    uVar5 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e0;
      }
      if (-1 < iVar1) {
        uVar6 = (undefined4)uStack_d8;
      }
      else {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = uVar6;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidSchedulerAssistSave");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_88 = &local_e8;
      local_e8 = 0x1f90;
      local_78 = &local_e4;
      local_80 = 4;
      local_70 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_68,"VID_IOCTL_SCHEDULER_ASSIST_SAVE");
      _tlgWriteTransfer_EventWriteTransfer
                (local_c8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidSchedulerAssistSuspend @ 1800189a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSchedulerAssistSuspend(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b4 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x189a0  162  VidSchedulerAssistSuspend */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidSchedulerAssistSuspend");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b4 + 1;
    local_3c = 0;
    local_48 = local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b4[1] = 0x1fbf;
    local_b4[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSchedulerAssistSuspend) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetCpuGroupAffinity @ 180018b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetCpuGroupAffinity(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x18b90  163  VidSetCpuGroupAffinity */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_ac = 0;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidSetCpuGroupAffinity");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x2e99;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCpuGroupUpdate) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetCpuGroupProperty @ 180018d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetCpuGroupProperty(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x18d90  164  VidSetCpuGroupProperty */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_a4 = 0;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_b0 = param_2;
  local_a8 = param_3;
  local_a0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidSetCpuGroupProperty");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x2f3a;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverCpuGroupSetProperty) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidSetMailboxKey @ 180018f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetMailboxKey(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x18f90  165  VidSetMailboxKey */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b0 = 0;
  uStack_a8 = 0;
  if (param_2 == (undefined8 *)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidSetMailboxKey","onecore\\vm\\vid\\dll\\src\\viddll.c",0x1989,param_4);
  }
  else {
    local_b0 = *param_2;
    uStack_a8 = param_2[1];
    uVar4 = 0;
    local_c8[2] = 0;
    local_c8[3] = 0;
    local_c8[4] = 0;
    local_c8[5] = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar3 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
    }
    else {
      uVar4 = 0;
      uVar3 = 0;
      DVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (DVar1 == 0x103) {
        uVar3 = 0;
        NtWaitForSingleObject(hObject,0);
        DVar1 = local_c8[2];
      }
      if (-1 >= (int)DVar1) {
        dwErrCode = RtlNtStatusToDosError(DVar1);
        SetLastError(dwErrCode);
      }
      CloseHandle(hObject);
      if (-1 < (int)DVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
      _tlgCreate1Sz_char(local_78,"VidSetMailboxKey");
      _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_58 = local_c8 + 1;
      local_c8[1] = 0x1992;
      local_48 = local_c8;
      local_50 = 4;
      local_40 = 4;
      local_c8[0] = DVar1;
      _tlgCreate1Sz_char(local_38,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetMailboxKey) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
    }
    SetLastError(DVar1);
  }
  return 0;
}



===== VidSetMemoryBlockClientNotifications @ 1800191c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidSetMemoryBlockClientNotifications
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8,
               undefined8 *param_9)

{
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined1 auStackY_158 [32];
  DWORD local_108 [6];
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x191c0  166  VidSetMemoryBlockClientNotifications */
  local_38 = __security_cookie ^ (ulonglong)auStackY_158;
  local_d4 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  if (param_9 != (undefined8 *)0x0) {
    *param_9 = 0;
  }
  if (param_8 != (undefined8 *)0x0) {
    *param_8 = 0;
  }
  local_d8 = param_5;
  local_c8 = param_7;
  local_d0 = param_6;
  uVar4 = 0;
  local_108[2] = 0;
  local_108[3] = 0;
  local_108[4] = 0;
  local_108[5] = 0;
  local_f0 = param_2;
  local_e8 = param_3;
  local_e0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    bVar5 = false;
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_108[2];
    }
    bVar5 = -1 < (int)DVar1;
    if (!bVar5) {
      DVar1 = RtlNtStatusToDosError(DVar1);
      SetLastError(DVar1);
    }
    CloseHandle(hObject);
    if (bVar5) {
      if (param_8 != (undefined8 *)0x0) {
        *param_8 = uStack_b8;
      }
      goto LAB_180019409;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidSetMemoryBlockClientNotifications");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_108 + 1;
    local_4c = 0;
    local_58 = local_108;
    local_60 = 4;
    local_50 = 4;
    local_108[1] = 0x168f;
    local_108[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetMemoryBlockClientNotifications) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  DVar1 = GetLastError();
  if (DVar1 != 0xc0370019) {
    return bVar5;
  }
LAB_180019409:
  if (param_9 != (undefined8 *)0x0) {
    *param_9 = local_c0;
  }
  return bVar5;
}



===== VidSetMemoryBlockFlushAfterWrite @ 180019440 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSetMemoryBlockFlushAfterWrite(undefined8 param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  undefined4 local_c8;
  DWORD local_c4;
  undefined8 local_c0;
  ulonglong uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x19440  167  VidSetMemoryBlockFlushAfterWrite */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  uStack_b8 = (ulonglong)param_3;
  uVar5 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_b0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidSetMemoryBlockFlushAfterWrite");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = &local_c8;
    local_3c = 0;
    local_48 = &local_c4;
    local_50 = 4;
    local_40 = 4;
    local_c8 = 0x140a;
    local_c4 = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetMemoryBlockFlushAfterWrite) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetPartitionCpuFrequencyCap @ 180019640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSetPartitionCpuFrequencyCap(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x19640  169  VidSetPartitionCpuFrequencyCap */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSetPartitionCpuFrequencyCap");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x31f3;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetPartitionFrequencyCap) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetPartitionCpuResourcePriorities @ 180019840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSetPartitionCpuResourcePriorities(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x19840  170  VidSetPartitionCpuResourcePriorities */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSetPartitionCpuResourcePriorities");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x3222;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetPartitionResourcePriorities) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetPartitionFriendlyName @ 180019a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetPartitionFriendlyName
          (undefined8 param_1,STRSAFE_LPCWSTR param_2,undefined8 param_3,undefined8 param_4)

{
  HRESULT HVar1;
  DWORD dwErrCode;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_308 [32];
  DWORD local_2b8 [8];
  wchar_t local_298 [256];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined8 local_50;
  DWORD *local_48;
  undefined8 local_40;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x19a40  171  VidSetPartitionFriendlyName */
  local_28 = __security_cookie ^ (ulonglong)auStackY_308;
  memset(local_298,0,0x200);
  if (param_2 == (STRSAFE_LPCWSTR)0x0) {
    SetLastError(0x57);
    VidlpTraceError0("VidSetPartitionFriendlyName","onecore\\vm\\vid\\dll\\src\\viddll.c",0xca7,
                     param_4);
  }
  else {
    HVar1 = StringCchCopyW(local_298,0x100,param_2);
    if (HVar1 < 0) {
      SetLastError(0x57);
      VidlpTraceError0("VidSetPartitionFriendlyName","onecore\\vm\\vid\\dll\\src\\viddll.c",0xcb3,
                       param_4);
    }
    else {
      uVar5 = 0;
      local_2b8[2] = 0;
      local_2b8[3] = 0;
      local_2b8[4] = 0;
      local_2b8[5] = 0;
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (hObject == (HANDLE)0x0) {
        uVar4 = 0x129;
        VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
      }
      else {
        uVar5 = 0;
        uVar4 = 0;
        DVar2 = NtDeviceIoControlFile(param_1,hObject);
        if (DVar2 == 0x103) {
          uVar4 = 0;
          NtWaitForSingleObject(hObject,0);
          DVar2 = local_2b8[2];
        }
        if (-1 >= (int)DVar2) {
          dwErrCode = RtlNtStatusToDosError(DVar2);
          SetLastError(dwErrCode);
        }
        CloseHandle(hObject);
        if (-1 < (int)DVar2) {
          return 1;
        }
      }
      GetLastError();
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
        _tlgCreate1Sz_char(local_78,"VidSetPartitionFriendlyName");
        _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
        local_58 = local_2b8 + 1;
        local_2b8[1] = 0xcba;
        local_48 = local_2b8;
        local_50 = 4;
        local_40 = 4;
        local_2b8[0] = DVar2;
        _tlgCreate1Sz_char(local_38,
                           "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionPartitionFriendlyNameSet) | (0x1 << 10)) << 2) | (0) )"
                          );
        _tlgWriteTransfer_EventWriteTransfer
                  (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
      }
      SetLastError(DVar2);
    }
  }
  return 0;
}



===== VidSetPeerProcess @ 180019cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSetPeerProcess(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x19cf0  173  VidSetPeerProcess */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSetPeerProcess");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x306f;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetPeerProcess) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetPropertySynicPort @ 180019ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetPropertySynicPort(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [2];
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x19ef0  174  VidSetPropertySynicPort */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b4 = 0;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidSetPropertySynicPort");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x152d;
    local_c8[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetPropertySynicPort) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetSystemInformation @ 18001a0f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetSystemInformation(undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x1a0f0  175  VidSetSystemInformation */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = param_4 & 0xffffffff;
  iVar1 = (int)param_4;
  pvVar3 = GetProcessHeap();
  puVar4 = HeapAlloc(pvVar3,8,(ulonglong)(iVar1 + 8));
  if (puVar4 == (undefined4 *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidSetSystemInformation","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2543,param_4
                    );
  }
  else {
    *puVar4 = param_2;
    puVar4[1] = iVar1;
    if (iVar1 != 0) {
      memcpy(puVar4 + 2,param_3,uVar5);
    }
    uVar7 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (pvVar3 == (HANDLE)0x0) {
      uVar6 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar7);
    }
    else {
      uVar7 = 0;
      uVar6 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,pvVar3);
      if (iVar1 == 0x103) {
        uVar6 = 0;
        NtWaitForSingleObject(pvVar3,0);
        iVar1 = (int)local_d0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(pvVar3);
      if (-1 < iVar1) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidSetSystemInformation");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_78 = &local_d8;
      local_d8 = 0x2558;
      local_68 = &local_d4;
      local_70 = 4;
      local_60 = 4;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_58,"VID_IOCTL_SET_SYSTEM_INFORMATION");
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar6,uVar7,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidSetVirtualProcessorState @ 18001a390 =====

void VidSetVirtualProcessorState
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4,
               undefined8 param_5)

{
                    /* 0x1a390  176  VidSetVirtualProcessorState */
  VidSetVirtualProcessorStateEx(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



===== VidSetVirtualProcessorStateEx @ 18001a3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSetVirtualProcessorStateEx
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined1 param_5,undefined8 param_6)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  DWORD local_e8 [3];
  undefined4 local_dc;
  undefined8 local_d8;
  undefined1 local_d0;
  undefined4 local_cf;
  undefined2 local_cb;
  undefined1 local_c9;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1a3c0  177  VidSetVirtualProcessorStateEx */
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_cf = 0;
  local_c8 = param_6;
  local_cb = 0;
  local_c9 = 0;
  local_d0 = param_5;
  uVar5 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_e8[2] = param_2;
  local_dc = param_3;
  local_d8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidSetVirtualProcessorStateEx");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = local_e8 + 1;
    local_e8[1] = 0x69f;
    local_58 = local_e8;
    local_60 = 4;
    local_50 = 4;
    local_e8[0] = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetVirtualProcessorState) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSetupMessageQueue @ 18001a5e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSetupMessageQueue(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1a5e0  178  VidSetupMessageQueue */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSetupMessageQueue");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x736;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetupMessageQueue) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSevSnpControlStateRestore @ 18001a7e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSevSnpControlStateRestore(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1a7e0  179  VidSevSnpControlStateRestore */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  if ((param_2 == 0) && (param_3 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidSevSnpControlStateRestore","onecore\\vm\\vid\\dll\\src\\viddll.c",0x20d3,
                     param_4);
  }
  else {
    uVar4 = 0;
    local_c8[2] = 0;
    local_c8[3] = 0;
    local_c8[4] = 0;
    local_c8[5] = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar3 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
    }
    else {
      uVar4 = 0;
      uVar3 = 0;
      DVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (DVar1 == 0x103) {
        uVar3 = 0;
        NtWaitForSingleObject(hObject,0);
        DVar1 = local_c8[2];
      }
      if (-1 >= (int)DVar1) {
        dwErrCode = RtlNtStatusToDosError(DVar1);
        SetLastError(dwErrCode);
      }
      CloseHandle(hObject);
      if (-1 < (int)DVar1) {
        return 1;
      }
    }
    GetLastError();
    DVar1 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidSevSnpControlStateRestore");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_68 = local_c8 + 1;
      local_c8[1] = 0x20dd;
      local_58 = local_c8;
      local_60 = 4;
      local_50 = 4;
      local_c8[0] = DVar1;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSevSnpControlRestore) | (0x1 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar1);
  }
  return 0;
}



===== VidSevSnpControlStateSave @ 18001aa10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidSevSnpControlStateSave(undefined8 param_1,longlong param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  DWORD local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  undefined4 *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0x1aa10  180  VidSevSnpControlStateSave */
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar6 = 0;
  if ((param_2 == 0) && (param_3 != 0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidSevSnpControlStateSave","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2111,
                     param_4);
  }
  else {
    *param_4 = 0;
    uVar5 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_e0;
      }
      if (-1 < iVar1) {
        uVar6 = (undefined4)uStack_d8;
      }
      else {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_4 = uVar6;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidSevSnpControlStateSave");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_88 = &local_e8;
      local_e8 = 0x211f;
      local_78 = &local_e4;
      local_80 = 4;
      local_70 = 4;
      local_e4 = DVar2;
      _tlgCreate1Sz_char(local_68,"VID_IOCTL_SEVSNP_CONTROL_SAVE");
      _tlgWriteTransfer_EventWriteTransfer
                (local_c8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidSevSnpIssueNestedPspRequests @ 18001ac50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool VidSevSnpIssueNestedPspRequests
               (undefined8 param_1,void *param_2,uint param_3,void *param_4,uint param_5,
               undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE pvVar4;
  uint *lpMem;
  ulonglong uVar5;
  undefined8 uVar6;
  void *pvVar7;
  undefined8 uVar8;
  uint uVar9;
  bool bVar10;
  undefined1 auStackY_158 [32];
  uint local_108 [2];
  void *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 *local_e8;
  undefined4 *local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined1 local_c8 [32];
  longlong local_a8 [2];
  longlong local_98 [2];
  uint *local_88;
  undefined8 local_80;
  void **local_78;
  undefined8 local_70;
  longlong local_68 [2];
  ulonglong local_58;
  
                    /* 0x1ac50  181  VidSevSnpIssueNestedPspRequests */
  local_58 = __security_cookie ^ (ulonglong)auStackY_158;
  local_e0 = param_7;
  local_e8 = param_6;
  local_f8 = 0;
  local_100 = param_2;
  local_f0 = param_1;
  if (((((param_2 == (void *)0x0) || (param_3 == 0)) || (param_6 == (undefined4 *)0x0)) ||
      (param_7 == (undefined4 *)0x0)) ||
     (((param_5 != 0 && (param_4 == (void *)0x0)) || ((1 < param_3 && (param_5 != 0)))))) {
    SetLastError(0x57);
    VidlpTraceError0("VidSevSnpIssueNestedPspRequests","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2164
                     ,param_4);
    return false;
  }
  uVar9 = param_3 * 0x44;
  local_108[0] = uVar9 + 8;
  if (param_4 != (void *)0x0) {
    local_108[0] = param_5 + 8 + uVar9;
  }
  uVar1 = local_108[0];
  pvVar7 = param_4;
  pvVar4 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar4,8,(ulonglong)uVar1);
  if (lpMem == (uint *)0x0) {
    SetLastError(0xe);
    VidlpTraceError0("VidSevSnpIssueNestedPspRequests","onecore\\vm\\vid\\dll\\src\\viddll.c",0x217b
                     ,pvVar7);
    return false;
  }
  *lpMem = param_3;
  lpMem[1] = param_5;
  memcpy(lpMem + 2,local_100,(ulonglong)uVar9);
  if (param_4 != (void *)0x0) {
    memcpy((void *)((ulonglong)uVar9 + 8 + (longlong)lpMem),param_4,(ulonglong)param_5);
  }
  uVar8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar4 == (HANDLE)0x0) {
    uVar6 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar8);
    bVar10 = false;
  }
  else {
    uVar8 = 0;
    uVar6 = 0;
    iVar2 = NtDeviceIoControlFile(local_f0,pvVar4);
    if (iVar2 == 0x103) {
      uVar6 = 0;
      NtWaitForSingleObject(pvVar4,0);
      iVar2 = (int)local_d8;
    }
    bVar10 = -1 < iVar2;
    if (!bVar10) {
      DVar3 = RtlNtStatusToDosError(iVar2);
      SetLastError(DVar3);
    }
    CloseHandle(pvVar4);
    if (bVar10) {
      *local_e8 = (undefined4)local_f8;
      *local_e0 = local_f8._4_4_;
      goto LAB_18001af51;
    }
  }
  GetLastError();
  DVar3 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    _tlgCreate1Sz_char(local_a8,"VidSevSnpIssueNestedPspRequests");
    _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_88 = local_108;
    local_108[0] = 0x2195;
    local_78 = &local_100;
    local_80 = 4;
    local_100 = (void *)CONCAT44(local_100._4_4_,DVar3);
    local_70 = 4;
    _tlgCreate1Sz_char(local_68,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSevSnpIssueNestedPspRequests) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_c8,&DAT_180029ec4,uVar6,uVar8,7,(PEVENT_DATA_DESCRIPTOR)local_c8);
  }
  SetLastError(DVar3);
LAB_18001af51:
  pvVar4 = GetProcessHeap();
  HeapFree(pvVar4,0,lpMem);
  return bVar10;
}



===== VidSgxResetMemoryBlocks @ 18001afd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSgxResetMemoryBlocks(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1afd0  182  VidSgxResetMemoryBlocks */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSgxResetMemoryBlocks");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2f96;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSgxResetMemoryBlocks) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidStartVirtualProcessor @ 18001b1c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidStartVirtualProcessor
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 *param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_208 [32];
  DWORD local_1b8 [8];
  undefined4 local_198 [2];
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined4 local_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1b1c0  183  VidStartVirtualProcessor */
  local_38 = __security_cookie ^ (ulonglong)auStackY_208;
  memset(local_198,0,0xf0);
  if (param_4 != (undefined8 *)0x0) {
    local_190 = *param_4;
    uStack_188 = param_4[1];
    local_180 = param_4[2];
    uStack_178 = param_4[3];
    local_170 = param_4[4];
    uStack_168 = param_4[5];
    local_160 = param_4[6];
    uStack_158 = param_4[7];
    local_150 = param_4[8];
    uStack_148 = param_4[9];
    local_140 = param_4[10];
    uStack_138 = param_4[0xb];
    local_130 = param_4[0xc];
    uStack_128 = param_4[0xd];
    local_120 = param_4[0xe];
    uStack_118 = param_4[0xf];
    local_110 = param_4[0x10];
    uStack_108 = param_4[0x11];
    local_100 = param_4[0x12];
    uStack_f8 = param_4[0x13];
    local_f0 = param_4[0x14];
    uStack_e8 = param_4[0x15];
    local_e0 = param_4[0x16];
    uStack_d8 = param_4[0x17];
    local_d0 = param_4[0x18];
    uStack_c8 = param_4[0x19];
    local_c0 = param_4[0x1a];
    uStack_b8 = param_4[0x1b];
  }
  uVar4 = 0;
  local_1b8[2] = 0;
  local_1b8[3] = 0;
  local_1b8[4] = 0;
  local_1b8[5] = 0;
  local_198[0] = param_2;
  local_b0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_1b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidStartVirtualProcessor");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_1b8 + 1;
    local_4c = 0;
    local_58 = local_1b8;
    local_60 = 4;
    local_50 = 4;
    local_1b8[1] = 0x55c;
    local_1b8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionStartVirtualProcessor) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidStatsMap @ 18001b480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidStatsMap(undefined8 param_1,undefined8 *param_2,undefined4 *param_3,undefined8 param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1b480  184  VidStatsMap */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  uStack_c8 = 0;
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidStatsMap","onecore\\vm\\vid\\dll\\src\\viddll.c",0x237f,param_4);
  }
  else {
    *param_2 = 0;
    *param_3 = 0;
    uVar5 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c0;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_2 = local_d0;
        *param_3 = (undefined4)uStack_c8;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidStatsMap");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_d8;
      local_4c = 0;
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_d8 = 0x2389;
      local_d4 = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsMap) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidStatsMapMemoryPartition @ 18001b6d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidStatsMapMemoryPartition
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d4;
  DWORD local_d0 [2];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1b6d0  185  VidStatsMapMemoryPartition */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c8 = 0;
  uStack_c0 = 0;
  if ((param_3 == (undefined8 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidStatsMapMemoryPartition","onecore\\vm\\vid\\dll\\src\\viddll.c",0x2407,
                     param_4);
  }
  else {
    *param_3 = 0;
    *param_4 = 0;
    uVar5 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_b8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_c8;
        *param_4 = (undefined4)uStack_c0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_88,"VidStatsMapMemoryPartition");
      _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_5c = 0;
      local_68 = &local_d4;
      local_4c = 0;
      local_58 = local_d0;
      local_d4 = 0x2414;
      local_60 = 4;
      local_50 = 4;
      local_d0[0] = DVar2;
      _tlgCreate1Sz_char(local_48,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsMapMemoryPartition) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidStatsMapNuma @ 18001b930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidStatsMapNuma(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_138 [32];
  undefined4 local_e4;
  DWORD local_e0 [2];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x1b930  186  VidStatsMapNuma */
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  local_d8 = 0;
  uStack_d0 = 0;
  if ((param_3 == (undefined8 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    SetLastError(0x57);
    VidlpTraceError0("VidStatsMapNuma","onecore\\vm\\vid\\dll\\src\\viddll.c",0x23c1,param_4);
  }
  else {
    *param_3 = 0;
    *param_4 = 0;
    uVar5 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (hObject == (HANDLE)0x0) {
      uVar4 = 0x129;
      VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      iVar1 = NtDeviceIoControlFile(param_1,hObject);
      if (iVar1 == 0x103) {
        uVar4 = 0;
        NtWaitForSingleObject(hObject,0);
        iVar1 = (int)local_c8;
      }
      if (-1 >= iVar1) {
        DVar2 = RtlNtStatusToDosError(iVar1);
        SetLastError(DVar2);
      }
      CloseHandle(hObject);
      if (-1 < iVar1) {
        *param_3 = local_d8;
        *param_4 = (undefined4)uStack_d0;
        return 1;
      }
    }
    GetLastError();
    DVar2 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
      _tlgCreate1Sz_char(local_98,"VidStatsMapNuma");
      _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
      local_6c = 0;
      local_78 = &local_e4;
      local_5c = 0;
      local_68 = local_e0;
      local_70 = 4;
      local_60 = 4;
      local_e4 = 0x23ce;
      local_e0[0] = DVar2;
      _tlgCreate1Sz_char(local_58,
                         "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsMapNuma) | (0x0 << 10)) << 2) | (0) )"
                        );
      _tlgWriteTransfer_EventWriteTransfer
                (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
    }
    SetLastError(DVar2);
  }
  return 0;
}



===== VidStatsUnMap @ 18001bb90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidStatsUnMap(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1bb90  187  VidStatsUnMap */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidStatsUnMap");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x243c;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsUnMap) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidStatsUnMapMemoryPartition @ 18001bd80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidStatsUnMapMemoryPartition(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1bd80  188  VidStatsUnMapMemoryPartition */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidStatsUnMapMemoryPartition");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x2496;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsUnMapMemoryPartition) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidStatsUnMapNuma @ 18001bf80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidStatsUnMapNuma(undefined8 param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_108 [32];
  DWORD local_b4 [3];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1bf80  189  VidStatsUnMapNuma */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar5 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_a8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidStatsUnMapNuma");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b4 + 1;
    local_3c = 0;
    local_48 = local_b4;
    local_50 = 4;
    local_40 = 4;
    local_b4[1] = 0x2469;
    local_b4[0] = DVar2;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverStatisticsUnMapNuma) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSuspendApply @ 18001c170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSuspendApply(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1c170  191  VidSuspendApply */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSuspendApply");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x2b41;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSuspendApply) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidSuspendClear @ 18001c370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidSuspendClear(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1c370  192  VidSuspendClear */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidSuspendClear");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x2b69;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSuspendClear) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidTeardownPartitionOperation @ 18001c560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidTeardownPartitionOperation(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1c560  193  VidTeardownPartitionOperation */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a4 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidTeardownPartitionOperation");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a0;
    local_2c = 0;
    local_38 = &local_a8;
    local_a0[0] = 0x383f;
    local_40 = 4;
    local_30 = 4;
    local_a8 = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionOperationTeardown) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidTriggerCreate @ 18001c760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidTriggerCreate(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1c760  196  VidTriggerCreate */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d0 = *param_2;
  uStack_c8 = param_2[1];
  local_f0 = 0;
  uStack_e8 = 0;
  local_c0 = *(undefined4 *)(param_2 + 2);
  uStack_bc = *(undefined4 *)((longlong)param_2 + 0x14);
  uStack_b8 = *(undefined4 *)(param_2 + 3);
  uStack_b4 = *(undefined4 *)((longlong)param_2 + 0x1c);
  uVar5 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_e0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_3 = local_f0;
      *param_4 = uStack_e8;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidTriggerCreate");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_f8;
    local_4c = 0;
    local_58 = &local_f4;
    local_60 = 4;
    local_50 = 4;
    local_f8 = 0x3489;
    local_f4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTriggerCreate) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidTriggerDestroy @ 18001c990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidTriggerDestroy(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1c990  197  VidTriggerDestroy */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidTriggerDestroy");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x34f4;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTriggerDestroy) | (0x1 << 10)) << 2) | (3) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidTriggerUpdateParameters @ 18001cb90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidTriggerUpdateParameters(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1cb90  198  VidTriggerUpdateParameters */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b8 = *param_3;
  uStack_b0 = param_3[1];
  local_a8 = *(undefined4 *)(param_3 + 2);
  uStack_a4 = *(undefined4 *)((longlong)param_3 + 0x14);
  uStack_a0 = *(undefined4 *)(param_3 + 3);
  uStack_9c = *(undefined4 *)((longlong)param_3 + 0x1c);
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidTriggerUpdateParameters");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x34bf;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTriggerUpdateParameters) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidTrimPartitionMemory @ 18001cd90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidTrimPartitionMemory(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1cd90  199  VidTrimPartitionMemory */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidTrimPartitionMemory");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x4c3;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionTrimPartitionMemory) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidUnmapHvGlobalStatsPage @ 18001cf80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidUnmapHvGlobalStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  uint local_b0;
  undefined4 uStack_ac;
  undefined1 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1cf80  200  VidUnmapHvGlobalStatsPage */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  _local_b0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_a8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidUnmapHvGlobalStatsPage");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0xd5d;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverUnmapHvStatsPageGlobal) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidUnmapHvLocalStatsPage @ 18001d180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidUnmapHvLocalStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  uint local_b0;
  undefined4 uStack_ac;
  undefined1 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1d180  201  VidUnmapHvLocalStatsPage */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  _local_b0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_a8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidUnmapHvLocalStatsPage");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0xe45;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionUnmapHvStatsPageLocal) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidUnmapHvRootStatsPage @ 18001d380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidUnmapHvRootStatsPage(undefined8 param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [6];
  uint local_b0;
  undefined4 uStack_ac;
  undefined1 local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1d380  202  VidUnmapHvRootStatsPage */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  _local_b0 = CONCAT44(param_3,(uint)param_2);
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_a8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidUnmapHvRootStatsPage");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0xdd1;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlDriverUnmapHvStatsPageRoot) | (0x0 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidUnprotectMemoryBlockPages @ 18001d580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidUnprotectMemoryBlockPages(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1d580  204  VidUnprotectMemoryBlockPages */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidUnprotectMemoryBlockPages");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x12dd;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionDbgProtectMemoryBlockDisable) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidUnregisterCpuidResult @ 18001d780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidUnregisterCpuidResult(undefined8 param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [7];
  undefined4 uStack_ac;
  uint local_a8;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1d780  205  VidUnregisterCpuidResult */
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  stack0xffffffffffffff50 = CONCAT44(param_3,param_2);
  local_a8 = (uint)param_4;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidUnregisterCpuidResult");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_c8 + 1;
    local_3c = 0;
    local_48 = local_c8;
    local_50 = 4;
    local_40 = 4;
    local_c8[1] = 0x95a;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionUnregisterCpuidResult) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidUnregisterHandler @ 18001d980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidUnregisterHandler(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
                    /* 0x1d980  206  VidUnregisterHandler */
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar5 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = param_2;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_98;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidUnregisterHandler");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0x9c3;
    local_a8[0] = DVar2;
    _tlgCreate1Sz_char(local_28,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionUnregisterHandler) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidVsmEnableVpVtl @ 18001db80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidVsmEnableVpVtl(undefined8 param_1,undefined4 param_2,undefined1 param_3,undefined8 *param_4)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_208 [32];
  DWORD local_1b8 [8];
  undefined4 local_198;
  undefined1 local_194;
  undefined1 local_193 [3];
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1db80  208  VidVsmEnableVpVtl */
  local_38 = __security_cookie ^ (ulonglong)auStackY_208;
  memset(local_193,0,0xe3);
  local_190 = *param_4;
  uStack_188 = param_4[1];
  local_180 = param_4[2];
  uStack_178 = param_4[3];
  local_170 = param_4[4];
  uStack_168 = param_4[5];
  local_160 = param_4[6];
  uStack_158 = param_4[7];
  local_150 = param_4[8];
  uStack_148 = param_4[9];
  local_140 = param_4[10];
  uStack_138 = param_4[0xb];
  local_130 = param_4[0xc];
  uStack_128 = param_4[0xd];
  local_120 = param_4[0xe];
  uStack_118 = param_4[0xf];
  local_110 = param_4[0x10];
  uStack_108 = param_4[0x11];
  local_100 = param_4[0x12];
  uStack_f8 = param_4[0x13];
  local_f0 = param_4[0x14];
  uStack_e8 = param_4[0x15];
  local_e0 = param_4[0x16];
  uStack_d8 = param_4[0x17];
  local_d0 = param_4[0x18];
  uStack_c8 = param_4[0x19];
  local_c0 = *(undefined4 *)(param_4 + 0x1a);
  uStack_bc = *(undefined4 *)((longlong)param_4 + 0xd4);
  uStack_b8 = *(undefined4 *)(param_4 + 0x1b);
  uStack_b4 = *(undefined4 *)((longlong)param_4 + 0xdc);
  uVar4 = 0;
  local_1b8[2] = 0;
  local_1b8[3] = 0;
  local_1b8[4] = 0;
  local_1b8[5] = 0;
  local_198 = param_2;
  local_194 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_1b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidVsmEnableVpVtl");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_68 = local_1b8 + 1;
    local_1b8[1] = 0x294b;
    local_58 = local_1b8;
    local_60 = 4;
    local_50 = 4;
    local_1b8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmEnableVpVtl) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidVsmGetMemoryBlockProtections @ 18001de30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018001e053) */

undefined1
VidVsmGetMemoryBlockProtections
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined1 param_5,undefined8 param_6,undefined4 param_7,undefined4 *param_8)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_158 [32];
  undefined4 local_104;
  DWORD local_100 [2];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined1 local_d4;
  undefined2 local_d3;
  undefined1 local_d1;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_b8 [32];
  longlong local_98 [2];
  longlong local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  DWORD *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
                    /* 0x1de30  209  VidVsmGetMemoryBlockProtections */
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_e0 = param_6;
  local_d4 = param_5;
  local_d3 = 0;
  local_d1 = 0;
  local_d8 = param_7;
  uVar5 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_f8 = param_2;
  local_f0 = param_3;
  local_e8 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_d0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_8 = 0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_98,"VidVsmGetMemoryBlockProtections");
    _tlgCreate1Sz_char(local_88,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_78 = &local_104;
    local_104 = 0x2842;
    local_68 = local_100;
    local_70 = 4;
    local_60 = 4;
    local_100[0] = DVar2;
    _tlgCreate1Sz_char(local_58,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmGetMemoryBlockProtections) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_b8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_b8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidVsmGetPartitionConfig @ 18001e0b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidVsmGetPartitionConfig(undefined8 param_1,uint param_2,void *param_3,uint *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_148 [32];
  undefined4 local_f8;
  DWORD local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined1 local_d8 [32];
  longlong local_b8 [2];
  longlong local_a8 [2];
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  DWORD *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong local_78 [2];
  uint local_68;
  undefined1 local_60 [40];
  ulonglong local_38;
  
                    /* 0x1e0b0  210  VidVsmGetPartitionConfig */
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  uVar5 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_f0;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      if (param_2 < local_68) {
        SetLastError(0x7a);
        VidlpTraceError0("VidVsmGetPartitionConfig","onecore\\vm\\vid\\dll\\src\\viddll.c",0x28dd,
                         uVar5);
        return 0;
      }
      memcpy(param_3,local_60,(ulonglong)local_68);
      *param_4 = local_68;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_b8,"VidVsmGetPartitionConfig");
    _tlgCreate1Sz_char(local_a8,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_8c = 0;
    local_98 = &local_f8;
    local_7c = 0;
    local_88 = &local_f4;
    local_90 = 4;
    local_80 = 4;
    local_f8 = 0x28cd;
    local_f4 = DVar2;
    _tlgCreate1Sz_char(local_78,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmGetPartitionConfig) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_d8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_d8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidVsmPrecommitMgmtVtlPageRange @ 18001e310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidVsmPrecommitMgmtVtlPageRange
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_d8;
  DWORD local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1e310  211  VidVsmPrecommitMgmtVtlPageRange */
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = 0;
  uVar5 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = param_2;
  local_b0 = param_3;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar4 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar5);
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    iVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (iVar1 == 0x103) {
      uVar4 = 0;
      NtWaitForSingleObject(hObject,0);
      iVar1 = (int)local_c8;
    }
    if (-1 >= iVar1) {
      DVar2 = RtlNtStatusToDosError(iVar1);
      SetLastError(DVar2);
    }
    CloseHandle(hObject);
    if (-1 < iVar1) {
      *param_4 = local_d0;
      return 1;
    }
  }
  GetLastError();
  DVar2 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar3 = _tlgKeywordOn(), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidVsmPrecommitMgmtVtlPageRange");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = &local_d8;
    local_4c = 0;
    local_58 = &local_d4;
    local_60 = 4;
    local_50 = 4;
    local_d8 = 0x29f4;
    local_d4 = DVar2;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmPrecommitMgmtVtlPageRange) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar4,uVar5,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar2);
  return 0;
}



===== VidVsmQueryProtectionsDirty @ 18001e520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidVsmQueryProtectionsDirty(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [8];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1e520  212  VidVsmQueryProtectionsDirty */
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidVsmQueryProtectionsDirty");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8 + 1;
    local_3c = 0;
    local_48 = local_b8;
    local_50 = 4;
    local_40 = 4;
    local_b8[1] = 0x29b7;
    local_b8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmQueryProtectionsDirty) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidVsmSetMemoryBlockProtections @ 18001e720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
VidVsmSetMemoryBlockProtections
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_128 [32];
  DWORD local_d8 [6];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
                    /* 0x1e720  213  VidVsmSetMemoryBlockProtections */
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_a0 = param_6;
  local_a8 = param_5;
  local_9c = param_7;
  uVar4 = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_c0 = param_2;
  local_b8 = param_3;
  local_b0 = param_4;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_d8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidVsmSetMemoryBlockProtections");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_d8 + 1;
    local_3c = 0;
    local_48 = local_d8;
    local_50 = 4;
    local_40 = 4;
    local_d8[1] = 0x2892;
    local_d8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmSetMemoryBlockProtections) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidVsmSetPartitionConfig @ 18001e930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidVsmSetPartitionConfig(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_118 [32];
  DWORD local_c8 [8];
  undefined1 local_a8 [32];
  longlong local_88 [2];
  longlong local_78 [2];
  DWORD *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
                    /* 0x1e930  214  VidVsmSetPartitionConfig */
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar4 = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_c8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_88,"VidVsmSetPartitionConfig");
    _tlgCreate1Sz_char(local_78,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_5c = 0;
    local_68 = local_c8 + 1;
    local_4c = 0;
    local_58 = local_c8;
    local_60 = 4;
    local_50 = 4;
    local_c8[1] = 0x2912;
    local_c8[0] = DVar1;
    _tlgCreate1Sz_char(local_48,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionVsmSetPartitionConfig) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_a8,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_a8);
  }
  SetLastError(DVar1);
  return 0;
}



===== VidWriteMemoryBlockPageRange @ 18001eb20 =====

void VidWriteMemoryBlockPageRange
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
                    /* 0x1eb20  215  VidWriteMemoryBlockPageRange */
  VidReadWriteMemoryBlockPageRange
            (param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,(undefined8 *)0x0,1);
  return;
}



===== VidpSetupPartition @ 18001eb6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidpSetupPartition(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_108 [32];
  DWORD local_b8 [8];
  undefined1 local_98 [32];
  longlong local_78 [2];
  longlong local_68 [2];
  DWORD *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar4 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_b8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_78,"VidpSetupPartition");
    _tlgCreate1Sz_char(local_68,"onecore\\vm\\vid\\dll\\src\\viddll.c");
    local_4c = 0;
    local_58 = local_b8 + 1;
    local_3c = 0;
    local_48 = local_b8;
    local_50 = 4;
    local_40 = 4;
    local_b8[1] = 0x206;
    local_b8[0] = DVar1;
    _tlgCreate1Sz_char(local_38,
                       "(DWORD) ( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionSetupPartition) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_98,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_98);
  }
  SetLastError(DVar1);
  return 0;
}



===== StringCchLengthW @ 18001ed88 =====

HRESULT __stdcall StringCchLengthW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  size_t sVar1;
  uint uVar2;
  
  if ((psz == (STRSAFE_PCNZWCH)0x0) || (sVar1 = cchMax, 0x7fffffff < cchMax)) {
    uVar2 = 0x80070057;
  }
  else {
    for (; (sVar1 != 0 && (*psz != L'\0')); psz = psz + 1) {
      sVar1 = sVar1 - 1;
    }
    uVar2 = ~-(uint)(sVar1 != 0) & 0x80070057;
    if (pcchLength != (size_t *)0x0) {
      if (sVar1 == 0) {
        *pcchLength = 0;
      }
      else {
        *pcchLength = cchMax - sVar1;
      }
    }
    if (sVar1 != 0) {
      return uVar2;
    }
  }
  if (pcchLength != (size_t *)0x0) {
    *pcchLength = 0;
  }
  return uVar2;
}



===== StringCchPrintfW @ 18001edf4 =====

HRESULT __stdcall
StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...)

{
  ulonglong _Count;
  int iVar1;
  HRESULT HVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (cchDest - 1 < 0x7fffffff) {
    _Count = cchDest - 1;
    HVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    pszDest[_Count] = L'\0';
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== VidpCreateVidObject @ 18001ee70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HANDLE VidpCreateVidObject(STRSAFE_PCNZWCH param_1,undefined8 param_2,char param_3,
                          undefined8 param_4)

{
  bool bVar1;
  HRESULT HVar2;
  DWORD DVar3;
  int iVar4;
  BOOL BVar5;
  ulonglong uVar6;
  HANDLE pvVar7;
  LPCWSTR pszDest;
  DWORD *pDVar8;
  byte *pbVar9;
  longlong lVar10;
  DWORD **pcchLength;
  DWORD *pDVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  undefined1 auStackY_128 [32];
  ULONG UVar14;
  DWORD local_e8;
  DWORD local_e4;
  DWORD *local_e0;
  DWORD *local_d8;
  HANDLE local_d0;
  _EVENT_DATA_DESCRIPTOR local_c8 [2];
  longlong local_a8 [2];
  longlong local_98 [2];
  DWORD *local_88;
  undefined8 local_80;
  DWORD *local_78;
  undefined8 local_70;
  DWORD **local_68;
  undefined8 local_60;
  DWORD **local_58;
  undefined8 local_50;
  wchar_t local_48 [12];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d0 = (HANDLE)0xffffffffffffffff;
  builtin_wcsncpy(local_48,L"\\\\?\\VidExo",0xb);
  DVar3 = 0;
  local_e0 = (DWORD *)0x0;
  local_d8 = (DWORD *)0x0;
  if (param_3 == '\0') {
LAB_18001efb6:
    pcchLength = &local_d8;
    pDVar8 = local_e0;
    HVar2 = StringCchLengthW(param_1,0x100,(size_t *)pcchLength);
    if (-1 < HVar2) {
      if (param_3 == '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180032e28);
        iVar4 = VidpInitializeSymbolicLink();
        if (iVar4 != 0) {
          bVar1 = true;
          lVar10 = DAT_180032e20 + (longlong)local_d8;
          goto LAB_18001f107;
        }
        DVar3 = GetLastError();
        VidlpTraceError0("VidpCreateVidObject","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",500,
                         param_4);
LAB_18001f3ae:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180032e28);
      }
      else {
        bVar1 = false;
        lVar10 = (longlong)local_d8 + (longlong)pDVar8;
LAB_18001f107:
        pDVar8 = (DWORD *)((lVar10 + 2U) * 2);
        pvVar7 = GetProcessHeap();
        pDVar11 = pDVar8;
        pszDest = HeapAlloc(pvVar7,8,(SIZE_T)pDVar8);
        if (pszDest == (LPCWSTR)0x0) {
          DVar3 = GetLastError();
          if ((2 < DAT_18002e000) && (uVar6 = _tlgKeywordOn(), (char)uVar6 != '\0')) {
            _tlgCreate1Sz_char(local_a8,"VidpCreateVidObject");
            _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
            local_88 = &local_e4;
            local_78 = &local_e8;
            local_e4 = 0x20a;
            local_80 = 4;
            local_70 = 4;
            local_68 = &local_e0;
            local_60 = 8;
            local_e8 = DVar3;
            local_e0 = pDVar8;
            _tlgWriteTransfer_EventWriteTransfer(local_78,&DAT_180029c4f,pDVar11,param_4,7,local_c8)
            ;
          }
          SetLastError(DVar3);
          DVar3 = 0xe;
        }
        else {
          if (bVar1) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180032e28);
            bVar1 = false;
          }
          if (param_3 == '\0') {
            pwVar13 = (wchar_t *)(DAT_180032e18 + 4);
          }
          else {
            pwVar13 = local_48;
          }
          pwVar12 = L"%s\\%s";
          HVar2 = StringCchPrintfW(pszDest,lVar10 + 2U,L"%s\\%s");
          if (HVar2 < 0) {
            DVar3 = GetLastError();
            if ((2 < DAT_18002e000) && (uVar6 = _tlgKeywordOn(), (char)uVar6 != '\0')) {
              _tlgCreate1Sz_char(local_a8,"VidpCreateVidObject");
              _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
              local_88 = &local_e4;
              local_e4 = 0x21e;
              local_78 = &local_e8;
              local_68 = &local_d8;
              local_80 = 4;
              local_70 = 4;
              local_d8 = (DWORD *)CONCAT44(local_d8._4_4_,HVar2);
              local_60 = 4;
              local_e8 = DVar3;
              _tlgWriteTransfer_EventWriteTransfer
                        (local_68,&DAT_180029c04,pwVar12,pwVar13,7,local_c8);
            }
            SetLastError(DVar3);
            DVar3 = 0x57;
          }
          else {
            pwVar13 = (wchar_t *)0x0;
            local_d0 = CreateFileW(pszDest,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x40100080,
                                   (HANDLE)0x0);
            if (local_d0 == (HANDLE)0xffffffffffffffff) {
              DVar3 = GetLastError();
              VidlpTraceError0("VidpCreateVidObject",
                               "onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",0x234,pwVar13);
            }
          }
          pvVar7 = GetProcessHeap();
          BVar5 = HeapFree(pvVar7,0,pszDest);
          if (BVar5 == 0) {
            VidlpTraceError0("VidpCreateVidObject","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",
                             0x23f,pwVar13);
          }
        }
        if (bVar1) goto LAB_18001f3ae;
      }
      if (DVar3 == 0) {
        return local_d0;
      }
      goto LAB_18001f3c5;
    }
    DVar3 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar6 = _tlgKeywordOn(), (char)uVar6 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidpCreateVidObject");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
      local_78 = &local_e8;
      local_e4 = 0x1e1;
      local_88 = &local_e4;
      local_80 = 4;
      local_70 = 4;
      local_e8 = DVar3;
      _tlgCreate1Sz_wchar_t((longlong *)&local_68,param_1);
      local_58 = &local_e0;
      pbVar9 = &DAT_180029c9c;
      local_e0 = local_d8;
      UVar14 = 8;
      local_50 = 8;
      pDVar8 = local_d8;
      goto LAB_18001f081;
    }
  }
  else {
    pcchLength = &local_e0;
    HVar2 = StringCchLengthW(local_48,0x100,(size_t *)pcchLength);
    if (-1 < HVar2) goto LAB_18001efb6;
    DVar3 = GetLastError();
    if ((2 < DAT_18002e000) && (uVar6 = _tlgKeywordOn(), (char)uVar6 != '\0')) {
      _tlgCreate1Sz_char(local_a8,"VidpCreateVidObject");
      _tlgCreate1Sz_char(local_98,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
      local_88 = &local_e8;
      local_e8 = 0x1cd;
      local_78 = &local_e4;
      pbVar9 = &DAT_180029d00;
      local_68 = &local_e0;
      UVar14 = 7;
      local_80 = 4;
      local_70 = 4;
      local_60 = 8;
      pDVar8 = local_78;
      local_e4 = DVar3;
LAB_18001f081:
      _tlgWriteTransfer_EventWriteTransfer(pDVar8,pbVar9,pcchLength,param_4,UVar14,local_c8);
    }
  }
  SetLastError(DVar3);
  DVar3 = 0x57;
LAB_18001f3c5:
  SetLastError(DVar3);
  return local_d0;
}



===== VidpInitializeSymbolicLink @ 18001f40c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VidpInitializeSymbolicLink(void)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;
  DWORD DVar4;
  BOOL BVar5;
  longlong lVar6;
  undefined4 *lpMem;
  ulonglong uVar7;
  ulonglong uVar8;
  HANDLE pvVar9;
  longlong *plVar10;
  int iVar11;
  undefined8 uVar12;
  size_t *pcchLength;
  ulonglong uVar13;
  undefined1 auStackY_118 [32];
  uint local_e8;
  uint local_e4;
  DWORD local_e0 [2];
  size_t local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  longlong local_88 [2];
  longlong local_78 [2];
  size_t *local_68;
  undefined8 local_60;
  DWORD *local_58;
  undefined8 local_50;
  size_t *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  iVar11 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e4 = 0;
  lpMem = (undefined4 *)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d8 = 0;
  DVar2 = 0;
  if (DAT_180032e18 != (undefined4 *)0x0) {
    return 1;
  }
  uVar12 = 0;
  lVar6 = DevObjCreateDeviceInfoList(0,0,0);
  if (lVar6 == -1) {
    VidlpTraceError0("VidpInitializeSymbolicLink","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",
                     0xd2,uVar12);
    DVar2 = GetLastError();
    goto LAB_18001f8cc;
  }
  uVar13 = 0x12;
  iVar3 = DevObjGetClassDevs(lVar6,&GUID_DEVICEINTERFACE_VID,0);
  if (iVar3 == 0) {
    VidlpTraceError0("VidpInitializeSymbolicLink","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",
                     0xe1,uVar13);
LAB_18001f86f:
    DVar2 = GetLastError();
  }
  else {
    local_d0 = CONCAT44(local_d0._4_4_,0x20);
    uVar13 = 0;
    iVar3 = DevObjEnumDeviceInterfaces(lVar6,0);
    if (iVar3 == 0) {
      VidlpTraceError0("VidpInitializeSymbolicLink","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c"
                       ,0xf2,uVar13);
      goto LAB_18001f86f;
    }
    uVar13 = 0;
    uVar12 = 0;
    DevObjGetDeviceInterfaceDetail(lVar6,&local_d0);
    DVar4 = GetLastError();
    uVar1 = local_e4;
    if (DVar4 != 0x7a) {
      VidlpTraceError0("VidpInitializeSymbolicLink","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c"
                       ,0x10b,uVar13);
      goto LAB_18001f86f;
    }
    if (0x7ffffffd < local_e4 - 1) {
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar8 = _tlgKeywordOn(), (char)uVar8 != '\0')) {
        _tlgCreate1Sz_char(local_88,"VidpInitializeSymbolicLink");
        plVar10 = local_78;
        _tlgCreate1Sz_char(plVar10,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
        local_68 = &local_d8;
        local_d8 = CONCAT44(local_d8._4_4_,0x112);
        local_58 = local_e0;
        local_60 = 4;
        local_e8 = local_e4;
        local_48 = (size_t *)&local_e8;
        local_50 = 4;
        local_40 = 4;
        local_e0[0] = DVar2;
        _tlgWriteTransfer_EventWriteTransfer(plVar10,&DAT_180029df2,uVar12,uVar13,7,local_a8);
      }
      SetLastError(DVar2);
      goto LAB_18001f86f;
    }
    pvVar9 = GetProcessHeap();
    uVar8 = (ulonglong)uVar1;
    lpMem = HeapAlloc(pvVar9,8,uVar8);
    if (lpMem == (undefined4 *)0x0) {
      DVar2 = GetLastError();
      if ((2 < DAT_18002e000) && (uVar7 = _tlgKeywordOn(), (char)uVar7 != '\0')) {
        _tlgCreate1Sz_char(local_88,"VidpInitializeSymbolicLink");
        plVar10 = local_78;
        _tlgCreate1Sz_char(plVar10,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
        local_68 = (size_t *)&local_e8;
        local_e8 = 0x11d;
        local_58 = local_e0;
        local_60 = 4;
        local_d8 = CONCAT44(local_d8._4_4_,local_e4);
        local_48 = &local_d8;
        local_50 = 4;
        local_40 = 4;
        local_e0[0] = DVar2;
        _tlgWriteTransfer_EventWriteTransfer(plVar10,&DAT_180029da2,uVar8,uVar13,7,local_a8);
      }
      SetLastError(DVar2);
      DVar2 = 0xe;
    }
    else {
      *lpMem = 8;
      uVar13 = (ulonglong)local_e4;
      iVar3 = DevObjGetDeviceInterfaceDetail(lVar6,&local_d0,lpMem);
      if (iVar3 == 0) {
        VidlpTraceError0("VidpInitializeSymbolicLink",
                         "onecore\\vm\\vid\\dll\\src\\viddriverconnect.c",299,uVar13);
        goto LAB_18001f86f;
      }
      pcchLength = &local_d8;
      local_e8 = StringCchLengthW((STRSAFE_PCNZWCH)(lpMem + 1),(ulonglong)local_e4 - 4,pcchLength);
      if ((int)local_e8 < 0) {
        DVar2 = GetLastError();
        if ((2 < DAT_18002e000) && (uVar8 = _tlgKeywordOn(), (char)uVar8 != '\0')) {
          _tlgCreate1Sz_char(local_88,"VidpInitializeSymbolicLink");
          plVar10 = local_78;
          _tlgCreate1Sz_char(plVar10,"onecore\\vm\\vid\\dll\\src\\viddriverconnect.c");
          local_68 = &local_d8;
          local_d8 = CONCAT44(local_d8._4_4_,0x13c);
          local_58 = local_e0;
          local_60 = 4;
          local_48 = (size_t *)&local_e8;
          local_50 = 4;
          local_40 = 4;
          local_e0[0] = DVar2;
          _tlgWriteTransfer_EventWriteTransfer(plVar10,&DAT_180029d57,pcchLength,uVar13,7,local_a8);
        }
        SetLastError(DVar2);
        DVar2 = 0x57;
      }
      else {
        iVar11 = 1;
        DAT_180032e20 = local_d8;
        DAT_180032e18 = lpMem;
      }
    }
  }
  DevObjDestroyDeviceInfoList(lVar6);
  if (iVar11 != 0) {
    return iVar11;
  }
  if (lpMem != (undefined4 *)0x0) {
    pvVar9 = GetProcessHeap();
    BVar5 = HeapFree(pvVar9,0,lpMem);
    if (BVar5 == 0) {
      VidlpTraceError0("VidpInitializeSymbolicLink","onecore\\vm\\vid\\dll\\src\\viddriverconnect.c"
                       ,0x158,uVar13);
    }
  }
LAB_18001f8cc:
  SetLastError(DVar2);
  return 0;
}



===== VidDllPartitionTrack @ 18001f910 =====

bool VidDllPartitionTrack
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  HANDLE hHeap;
  LPVOID pvVar4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  undefined8 uVar7;
  
  AcquireSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  hHeap = GetProcessHeap();
  pvVar4 = HeapAlloc(hHeap,8,0x38);
  if (pvVar4 == (LPVOID)0x0) {
    VidlpTraceError0("VidDllPartitionTrack","onecore\\vm\\vid\\dll\\src\\viddllpartition.c",0xa9,
                     param_4);
    goto LAB_18001fa3d;
  }
  *(undefined8 *)((longlong)pvVar4 + 0x18) = param_1;
  puVar6 = DAT_180032de8;
  if ((((byte)DAT_180032df0 & 1) != 0) && (DAT_180032de8 != (ulonglong *)0x0)) {
    puVar6 = (ulonglong *)((ulonglong)DAT_180032de8 ^ 0x180032de8);
  }
  uVar7 = 0;
  bVar1 = (byte)DAT_180032df0 & 1;
  bVar2 = (byte)DAT_180032df0 & 1;
  if (puVar6 != (ulonglong *)0x0) {
    do {
      iVar3 = VidDllStatspComparePartitionHandles
                        ((ulonglong *)((longlong)pvVar4 + 0x18),(longlong)puVar6);
      if (iVar3 < 0) {
        puVar5 = (ulonglong *)*puVar6;
        if (bVar2 == 0) {
LAB_18001f9f4:
          if (puVar5 != (ulonglong *)0x0) goto LAB_18001f9f9;
        }
        else if (puVar5 != (ulonglong *)0x0) {
          puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar6);
          goto LAB_18001f9f4;
        }
        uVar7 = 0;
        break;
      }
      puVar5 = (ulonglong *)puVar6[1];
      if (bVar1 != 0) {
        if (puVar5 == (ulonglong *)0x0) goto LAB_18001f9e0;
        puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)puVar6);
      }
      if (puVar5 == (ulonglong *)0x0) goto LAB_18001f9e0;
LAB_18001f9f9:
      puVar6 = puVar5;
    } while( true );
  }
  goto LAB_18001fa01;
LAB_18001f9e0:
  uVar7 = 1;
LAB_18001fa01:
  RtlRbInsertNodeEx(&DAT_180032de8,puVar6,uVar7,pvVar4);
  DAT_180032de4 = DAT_180032de4 + 1;
  if (DAT_180032de0 == '\0') {
    VidDllStatsPerfLibInitialize();
  }
  ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
LAB_18001fa3d:
  SetLastError(~-(uint)(pvVar4 != (LPVOID)0x0) & 0xe);
  return pvVar4 != (LPVOID)0x0;
}



===== VidDllPartitionUntrack @ 18001fa80 =====

void VidDllPartitionUntrack
               (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong local_res8;
  
  local_res8 = param_1;
  AcquireSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  puVar4 = DAT_180032de8;
  if ((((byte)DAT_180032df0 & 1) != 0) && (DAT_180032de8 != (undefined8 *)0x0)) {
    puVar4 = (undefined8 *)((ulonglong)DAT_180032de8 ^ 0x180032de8);
  }
  bVar1 = (byte)DAT_180032df0 & 1;
  while (puVar4 != (undefined8 *)0x0) {
    iVar2 = VidDllStatspComparePartitionHandles(&local_res8,(longlong)puVar4);
    if (iVar2 < 0) {
      puVar3 = (undefined8 *)*puVar4;
    }
    else {
      if (iVar2 < 1) break;
      puVar3 = (undefined8 *)puVar4[1];
    }
    if ((bVar1 == 0) || (puVar3 == (undefined8 *)0x0)) {
      puVar4 = puVar3;
    }
    else {
      puVar4 = (undefined8 *)((ulonglong)puVar4 ^ (ulonglong)puVar3);
    }
  }
  if (puVar4 == (undefined8 *)0x0) {
    VidlpTraceError0("VidDllPartitionUntrack","onecore\\vm\\vid\\dll\\src\\viddllpartition.c",0xe8,
                     param_4);
  }
  else {
    RtlRbRemoveNode(&DAT_180032de8,puVar4);
    VidDllPartitionpContextTeardown(puVar4);
    DAT_180032de4 = DAT_180032de4 + -1;
  }
  if ((DAT_180032de0 != '\0') && (DAT_180032de4 == 0)) {
    if (DAT_180032df8 != -1) {
      PerfStopProvider();
      DAT_180032df8 = -1;
    }
    DAT_180032de0 = '\0';
  }
                    /* WARNING: Could not recover jumptable at 0x00018001fb9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  return;
}



===== VidDllPartitionpContextTeardown @ 18001fbac =====

void VidDllPartitionpContextTeardown(LPVOID param_1)

{
  HANDLE hHeap;
  
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x00018001fbce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree(hHeap,0,param_1);
  return;
}



===== VidDllPartitionsTeardown @ 18001fbe0 =====

void VidDllPartitionsTeardown(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  AcquireSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  if (((ulonglong)DAT_180032df0 & 1) == 0) {
    puVar3 = DAT_180032df0;
  }
  else {
    if (DAT_180032df0 == (undefined8 *)0x1) goto LAB_18001fc68;
    puVar3 = (undefined8 *)((ulonglong)DAT_180032df0 ^ 0x180032de9);
  }
  while (puVar3 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)puVar3[1];
    puVar1 = puVar3;
    if (puVar2 == (undefined8 *)0x0) {
      do {
        puVar2 = (undefined8 *)(puVar1[2] & 0xfffffffffffffffc);
        if (puVar2 == (undefined8 *)0x0) break;
        bVar4 = (undefined8 *)*puVar2 != puVar1;
        puVar1 = puVar2;
      } while (bVar4);
    }
    else {
      for (puVar1 = (undefined8 *)*puVar2; puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)*puVar1) {
        puVar2 = puVar1;
      }
    }
    VidDllPartitionpContextTeardown(puVar3);
    puVar3 = puVar2;
  }
LAB_18001fc68:
                    /* WARNING: Could not recover jumptable at 0x00018001fc74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  return;
}



===== VidDllStatsGetSharedBuffer @ 18001fc90 =====

undefined8
VidDllStatsGetSharedBuffer
          (ulonglong param_1,longlong *param_2,undefined4 *param_3,undefined8 param_4)

{
  longlong *plVar1;
  undefined8 extraout_RAX;
  undefined1 uVar2;
  undefined4 *puVar3;
  
                    /* 0x1fc90  35  VidDllStatsGetSharedBuffer */
  uVar2 = 0;
  *param_2 = 0;
  *param_3 = 0;
  plVar1 = param_2;
  puVar3 = param_3;
  AcquireSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  if (DAT_180032de0 == '\0') {
    VidlpTraceError0("VidDllStatsGetSharedBuffer","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x22a,
                     param_4);
  }
  else {
    plVar1 = VidDllPartitionContextGet(param_1,plVar1,puVar3,param_4);
    if (((plVar1 == (longlong *)0x0) || (plVar1[5] == 0)) || ((int)plVar1[6] == 0)) {
      VidlpTraceError0("VidDllStatsGetSharedBuffer","onecore\\vm\\vid\\dll\\src\\viddllstats.c",
                       0x235,param_4);
    }
    else {
      *param_2 = plVar1[5];
      uVar2 = 1;
      *param_3 = (int)plVar1[6];
    }
  }
  ReleaseSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  return CONCAT71((int7)((ulonglong)extraout_RAX >> 8),uVar2);
}



===== VidDllStatsGetVmPerfRootInstance @ 18001fd60 =====

longlong VidDllStatsGetVmPerfRootInstance
                   (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  
                    /* 0x1fd60  36  VidDllStatsGetVmPerfRootInstance */
  lVar2 = 0;
  AcquireSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  if (DAT_180032de0 == '\0') {
    VidlpTraceError0("VidDllStatsGetVmPerfRootInstance","onecore\\vm\\vid\\dll\\src\\viddllstats.c",
                     0x264,param_4);
  }
  else {
    plVar1 = VidDllPartitionContextGet(param_1,param_2,param_3,param_4);
    if ((plVar1 == (longlong *)0x0) || (plVar1[4] == 0)) {
      VidlpTraceError0("VidDllStatsGetVmPerfRootInstance",
                       "onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x26e,param_4);
    }
    else {
      lVar2 = plVar1[4];
    }
  }
  ReleaseSRWLockShared((PSRWLOCK)&g_VidStatsContext);
  return lVar2;
}



===== VidDllStatsPartitionTeardown @ 18001fe00 =====

void VidDllStatsPartitionTeardown
               (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  
  AcquireSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  plVar1 = VidDllPartitionContextGet(param_1,param_2,param_3,param_4);
  if (plVar1 == (longlong *)0x0) {
    VidlpTraceError0("VidDllStatsPartitionTeardown","onecore\\vm\\vid\\dll\\src\\viddllstats.c",
                     0x19f,param_4);
  }
  else {
    if ((longlong *)plVar1[4] != (longlong *)0x0) {
      VmPerfDeleteInstance(DAT_180032df8,(longlong *)plVar1[4]);
      plVar1[4] = 0;
    }
    if (plVar1[5] != 0) {
      VidDllStatspUnMapPartition(plVar1[3]);
      plVar1[5] = 0;
      *(undefined4 *)(plVar1 + 6) = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00018001fe86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive((PSRWLOCK)&g_VidStatsContext);
  return;
}



===== VidDllStatsPerfLibInitialize @ 18001fe98 =====

void VidDllStatsPerfLibInitialize(void)

{
  int iVar1;
  undefined8 in_R9;
  
  iVar1 = PerfStartProvider(&VidPerfProviderGuid,0,&DAT_180032df8);
  if (iVar1 != 0) {
    VidlpTraceError0("VidDllStatsPerfLibInitialize","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x4a
                     ,in_R9);
    return;
  }
  iVar1 = PerfSetCounterSetInfo(DAT_180032df8,&VidPartitionObjectInfo,0x47e8);
  if (iVar1 == 0) {
    DAT_180032de0 = 1;
    return;
  }
  VidlpTraceError0("VidDllStatsPerfLibInitialize","onecore\\vm\\vid\\dll\\src\\viddllstats.c",0x57,
                   in_R9);
  return;
}



===== VidDllStatspUnMapPartition @ 18001ff30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 VidDllStatspUnMapPartition(undefined8 param_1)

{
  DWORD dwErrCode;
  DWORD DVar1;
  HANDLE hObject;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auStackY_f8 [32];
  DWORD local_a8 [8];
  undefined1 local_88 [32];
  longlong local_68 [2];
  longlong local_58 [2];
  DWORD *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  DWORD *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar4 = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hObject == (HANDLE)0x0) {
    uVar3 = 0x129;
    VidlpTraceError0("VidIoControl","onecore\\vm\\vid\\dll\\src\\viddll.c",0x129,uVar4);
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    DVar1 = NtDeviceIoControlFile(param_1,hObject);
    if (DVar1 == 0x103) {
      uVar3 = 0;
      NtWaitForSingleObject(hObject,0);
      DVar1 = local_a8[2];
    }
    if (-1 >= (int)DVar1) {
      dwErrCode = RtlNtStatusToDosError(DVar1);
      SetLastError(dwErrCode);
    }
    CloseHandle(hObject);
    if (-1 < (int)DVar1) {
      return 1;
    }
  }
  GetLastError();
  DVar1 = GetLastError();
  if ((2 < DAT_18002e000) && (uVar2 = _tlgKeywordOn(), (char)uVar2 != '\0')) {
    _tlgCreate1Sz_char(local_68,"VidDllStatspUnMapPartition");
    _tlgCreate1Sz_char(local_58,"onecore\\vm\\vid\\dll\\src\\viddllstats.c");
    local_3c = 0;
    local_48 = local_a8 + 1;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 4;
    local_30 = 4;
    local_a8[1] = 0xe0;
    local_a8[0] = DVar1;
    _tlgCreate1Sz_char(local_28,
                       "( ((0x00000022) << 16) | ((0) << 14) | (((VidIoctlPartitionStatisticsUnMap) | (0x1 << 10)) << 2) | (0) )"
                      );
    _tlgWriteTransfer_EventWriteTransfer
              (local_88,&DAT_180029ec4,uVar3,uVar4,7,(PEVENT_DATA_DESCRIPTOR)local_88);
  }
  SetLastError(DVar1);
  return 0;
}



===== VmPerfDeleteInstance @ 18002011c =====

undefined4 VmPerfDeleteInstance(undefined8 param_1,longlong *param_2)

{
  LPVOID lpMem;
  undefined4 uVar1;
  HANDLE pvVar2;
  bool bVar3;
  
  uVar1 = 0;
  if (param_2 == (longlong *)0x0) {
    uVar1 = 0x57;
  }
  else {
    if (*param_2 != 0) {
      uVar1 = PerfDeleteInstance();
    }
    lpMem = (LPVOID)param_2[1];
    bVar3 = param_2 == DAT_180032e00;
    if (lpMem != (LPVOID)0x0) {
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,0,lpMem);
    }
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,param_2);
    if (bVar3) {
      DAT_180032e00 = (longlong *)0x0;
    }
  }
  return uVar1;
}



===== VmPerfpCleanNameString @ 1800201d8 =====

void VmPerfpCleanNameString(longlong param_1,ulonglong param_2)

{
  short sVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      sVar1 = *(short *)(param_1 + uVar2 * 2);
      if (sVar1 == 0x23) {
LAB_180020223:
        *(undefined2 *)(param_1 + uVar2 * 2) = 0x5f;
      }
      else if (sVar1 == 0x28) {
        *(undefined2 *)(param_1 + uVar2 * 2) = 0x5b;
      }
      else if (sVar1 == 0x29) {
        *(undefined2 *)(param_1 + uVar2 * 2) = 0x5d;
      }
      else {
        if (sVar1 == 0x2a) goto LAB_180020223;
        if ((sVar1 == 0x2f) || (sVar1 == 0x5c)) {
          *(undefined2 *)(param_1 + uVar2 * 2) = 0x2d;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}



===== DloadAcquireSectionWriteAccess @ 18002023c =====

void DloadAcquireSectionWriteAccess(void)

{
  DWORD DVar1;
  int iVar2;
  
  AcquireSRWLockExclusive((PSRWLOCK)&DloadSrwLock);
  iVar2 = DloadSectionLockCount + 1;
  if (iVar2 == 1) {
    DVar1 = DloadSectionLockCount + 4;
    DloadSectionLockCount = iVar2;
    DloadProtectSection(DVar1,&DloadSectionOldProtection);
    iVar2 = DloadSectionLockCount;
  }
  DloadSectionLockCount = iVar2;
  ReleaseSRWLockExclusive((PSRWLOCK)&DloadSrwLock);
  return;
}



===== DloadMakePermanentImageCommit @ 1800202a0 =====

void DloadMakePermanentImageCommit(LPCVOID param_1,ulonglong param_2)

{
  code *pcVar1;
  SIZE_T SVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  _MEMORY_BASIC_INFORMATION local_68;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_68.BaseAddress = (PVOID)0x0;
  local_68.AllocationBase = (PVOID)0x0;
  local_68.AllocationProtect = 0;
  local_68._20_4_ = 0;
  local_68.RegionSize = 0;
  local_68.State = 0;
  local_68.Protect = 0;
  local_68.Type = 0;
  local_68._44_4_ = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  SVar2 = VirtualQuery(param_1,&local_68,0x30);
  puVar6 = auStack_88;
  if (SVar2 == 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x19);
    puVar6 = auStack_80;
  }
  if ((puVar6[0x44] & 0x44) != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x180020306;
    GetSystemInfo((LPSYSTEM_INFO)(puVar6 + 0x50));
    uVar8 = (ulonglong)*(uint *)(puVar6 + 0x54);
    puVar7 = (undefined4 *)(-uVar8 & (ulonglong)param_1);
    uVar4 = *(uint *)(puVar6 + 0x54) - 1;
    uVar5 = (((ulonglong)((uVar4 & (uint)param_2) + (uVar4 & (uint)param_1)) - 1) + uVar8) / uVar8 +
            param_2 / uVar8;
    uVar3 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) {
      do {
        LOCK();
        *puVar7 = *puVar7;
        UNLOCK();
        puVar7 = (undefined4 *)((longlong)puVar7 + uVar8);
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  return;
}



===== DloadObtainSection @ 18002036c =====

/* WARNING: Enum "SectionFlags": Some values do not have unique names */

longlong DloadObtainSection(dword *param_1,SectionFlags *param_2)

{
  uint uVar1;
  dword dVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  uint uVar4;
  
  uVar4 = 0;
  pIVar3 = &IMAGE_SECTION_HEADER_1800001f8;
  while( true ) {
    if (7 < uVar4) {
      return 0;
    }
    uVar1 = pIVar3->VirtualAddress;
    if ((uVar1 < 0x34001) && (dVar2 = (pIVar3->Misc).PhysicalAddress, 0x34000 < uVar1 + dVar2))
    break;
    uVar4 = uVar4 + 1;
    pIVar3 = pIVar3 + 1;
  }
  *param_2 = pIVar3->Characteristics;
  *param_1 = dVar2;
  return (ulonglong)uVar1 + 0x180000000;
}



===== DloadProtectSection @ 18002040c =====

/* WARNING: Enum "SectionFlags": Some values do not have unique names */

void DloadProtectSection(DWORD param_1,PDWORD param_2)

{
  code *pcVar1;
  BOOL BVar2;
  LPCVOID lpAddress;
  undefined1 *puVar3;
  dword local_res18 [2];
  SectionFlags local_res20 [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  lpAddress = (LPCVOID)DloadObtainSection(local_res18,local_res20);
  puVar3 = auStack_28;
  if (lpAddress == (LPCVOID)0x0) {
    *param_2 = 4;
  }
  else {
    if (DloadSectionCommitPermanent == 0) {
      DloadSectionCommitPermanent = 1;
      puVar3 = auStack_28;
      if ((local_res20[0] & IMAGE_SCN_MEM_WRITE) == 0) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(0x19);
        puVar3 = auStack_20;
      }
      *(undefined8 *)(puVar3 + -8) = 0x180020476;
      DloadMakePermanentImageCommit(lpAddress,(ulonglong)*(uint *)(puVar3 + 0x40));
    }
    *(undefined8 *)(puVar3 + -8) = 0x18002048a;
    BVar2 = VirtualProtect(lpAddress,(ulonglong)*(uint *)(puVar3 + 0x40),param_1,param_2);
    if (BVar2 == 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(0x19);
    }
  }
  return;
}



===== DloadReleaseSectionWriteAccess @ 1800204b0 =====

void DloadReleaseSectionWriteAccess(void)

{
  DWORD local_res8 [8];
  
  local_res8[0] = 0;
  AcquireSRWLockExclusive((PSRWLOCK)&DloadSrwLock);
  DloadSectionLockCount = DloadSectionLockCount + -1;
  if (DloadSectionLockCount == 0) {
    DloadProtectSection(DloadSectionOldProtection,local_res8);
  }
  ReleaseSRWLockExclusive((PSRWLOCK)&DloadSrwLock);
  return;
}



===== __delayLoadHelper2 @ 180020510 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001800207f4) */
/* WARNING: Removing unreachable block (ram,0x000180020699) */
/* WARNING: Removing unreachable block (ram,0x00018002061b) */
/* WARNING: Removing unreachable block (ram,0x00018002064a) */
/* WARNING: Removing unreachable block (ram,0x000180020762) */
/* WARNING: Removing unreachable block (ram,0x000180020849) */

FARPROC __delayLoadHelper2(uint *param_1,longlong *param_2)

{
  HMODULE pHVar1;
  uint uVar2;
  HMODULE hLibModule;
  HMODULE pHVar3;
  HANDLE hHeap;
  undefined8 *puVar4;
  FARPROC pFVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined4 *local_res8;
  undefined4 local_78;
  undefined4 local_74;
  uint *local_70;
  longlong *local_68;
  LPCSTR local_60;
  uint local_58;
  undefined4 local_54;
  char *local_50;
  HMODULE local_48;
  FARPROC local_40;
  DWORD local_38;
  
  local_54 = 0;
  local_74 = 0;
  DloadAcquireSectionWriteAccess();
  local_60 = (LPCSTR)((ulonglong)param_1[1] + 0x180000000);
  plVar9 = (longlong *)((ulonglong)param_1[2] + 0x180000000);
  uVar2 = param_1[5];
  lVar7 = (ulonglong)param_1[4] + 0x180000000;
  local_58 = 0;
  local_50 = (char *)0x0;
  local_48 = (HMODULE)0x0;
  local_40 = (FARPROC)0x0;
  local_38 = 0;
  local_res8 = (undefined4 *)CONCAT44(local_res8._4_4_,param_1[7]);
  local_78 = 0x48;
  local_70 = param_1;
  local_68 = param_2;
  if ((*param_1 & 1) == 0) {
    local_res8 = &local_78;
    DloadReleaseSectionWriteAccess();
    RaiseException(0xc06d0057,0,1,(ULONG_PTR *)&local_res8);
    pFVar5 = (FARPROC)0x0;
  }
  else {
    uVar8 = (longlong)((longlong)param_2 - ((ulonglong)param_1[3] + 0x180000000)) >> 3;
    uVar6 = uVar8 & 0xffffffff;
    local_58 = (uint)(-1 < *(longlong *)(lVar7 + uVar6 * 8));
    if (local_58 == 0) {
      local_50 = (char *)(ulonglong)*(ushort *)(lVar7 + uVar6 * 8);
    }
    else {
      local_50 = IMAGE_DOS_HEADER_180000000.e_magic + (ulonglong)*(uint *)(lVar7 + uVar6 * 8) + 2;
    }
    hLibModule = (HMODULE)*plVar9;
    if ((HMODULE)*plVar9 == (HMODULE)0x0) {
      hLibModule = LoadLibraryExA(local_60,(HANDLE)0x0,0);
      if (hLibModule == (HMODULE)0x0) {
        local_38 = GetLastError();
        local_res8 = &local_78;
        DloadReleaseSectionWriteAccess();
        RaiseException(0xc06d007e,0,1,(ULONG_PTR *)&local_res8);
        return local_40;
      }
      pHVar3 = (HMODULE)0x0;
      LOCK();
      pHVar1 = (HMODULE)*plVar9;
      if (pHVar1 == (HMODULE)0x0) {
        *plVar9 = (longlong)hLibModule;
      }
      else {
        pHVar3 = pHVar1;
      }
      UNLOCK();
      if (pHVar1 == (HMODULE)0x0) {
        if ((hLibModule != (HMODULE)0xffffffffffffffff) && (param_1[6] != 0)) {
          hHeap = GetProcessHeap();
          puVar4 = HeapAlloc(hHeap,8,0x10);
          if (puVar4 != (undefined8 *)0x0) {
            puVar4[1] = param_1;
            *puVar4 = __puiHead;
            __puiHead = puVar4;
          }
        }
      }
      else {
        if (hLibModule != (HMODULE)0xffffffffffffffff) {
          FreeLibrary(hLibModule);
        }
        if (hLibModule != pHVar3) {
          hLibModule = pHVar3;
        }
      }
    }
    local_48 = hLibModule;
    if (((((param_1[5] == 0) || (param_1[7] == 0)) ||
         (lVar7 = (longlong)hLibModule[0xf].unused,
         *(int *)((longlong)&hLibModule->unused + lVar7) != 0x4550)) ||
        (((*(int *)((longlong)&hLibModule[2].unused + lVar7) != (int)local_res8 ||
          (hLibModule != *(HMODULE *)((longlong)&hLibModule[0xc].unused + lVar7))) ||
         (pFVar5 = *(FARPROC *)((ulonglong)uVar2 + 0x180000000 + (uVar8 & 0xffffffff) * 8),
         pFVar5 == (FARPROC)0x0)))) &&
       (pFVar5 = GetProcAddress(hLibModule,local_50), pFVar5 == (FARPROC)0x0)) {
      local_38 = GetLastError();
      local_res8 = &local_78;
      DloadReleaseSectionWriteAccess();
      RaiseException(0xc06d007f,0,1,(ULONG_PTR *)&local_res8);
      DloadAcquireSectionWriteAccess();
      pFVar5 = local_40;
    }
    *param_2 = (longlong)pFVar5;
    DloadReleaseSectionWriteAccess();
  }
  return pFVar5;
}



===== __GSHandlerCheck @ 180020898 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1800208bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== __chkstk @ 18002091d =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018002091d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== memcpy @ 180020929 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180020929. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 180020935 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180020935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __security_check_cookie @ 180020950 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180020990 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180020990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1800209c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1800209f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 180021010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


