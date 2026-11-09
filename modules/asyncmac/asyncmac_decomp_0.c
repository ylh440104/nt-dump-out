
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



===== AsyncDriverCreate @ 1c0001020 =====

undefined8 AsyncDriverCreate(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AsyncDriverDispatch @ 1c0001050 =====

uint AsyncDriverDispatch(longlong param_1,longlong *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  
  cVar2 = IoIs32bitProcess(param_2);
  if ((((cVar2 == '\0') && (pcVar1 = (char *)param_2[0x17], *pcVar1 == '\x0e')) &&
      (*(short *)(pcVar1 + 0x1a) == 0x12)) &&
     ((param_1 == AsyncDeviceObject && ((*(uint *)(pcVar1 + 0x18) & 3) == 0)))) {
    uVar3 = AsyncIOCtlRequest(param_2,(longlong)pcVar1);
    if (uVar3 == 0xc0000004) {
      lVar4 = 4;
      if (*(uint *)(pcVar1 + 8) < 4) {
        lVar4 = 0;
      }
      else {
        *(longlong *)param_2[3] = param_2[7];
      }
      param_2[7] = lVar4;
      uVar3 = 0;
    }
    else if (uVar3 != 0) {
      if (uVar3 == 0x103) {
        return 0x103;
      }
      if (uVar3 < 0xc0000000) {
        uVar3 = 0xc0000001;
      }
      param_2[7] = 0;
    }
  }
  else {
    uVar3 = 0xc00000bb;
  }
  *(uint *)(param_2 + 6) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== AsyncIrpStub @ 1c0001130 =====

undefined8 AsyncIrpStub(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== AsyncUnload @ 1c0001170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AsyncUnload(undefined8 param_1)

{
  ExDeleteNPagedLookasideList(&AsyncIoCtxList);
  ExDeleteNPagedLookasideList(&AsyncInfoList);
  if (AsyncDeviceHandle != 0) {
    NdisDeregisterDeviceEx();
    AsyncDeviceHandle = 0;
  }
  (*NdisUnload)(param_1);
  return;
}



===== DriverEntry @ 1c00011dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  code **ppcVar4;
  undefined1 auStack_2b8 [32];
  undefined8 *local_298;
  uint local_290;
  undefined8 *local_288;
  undefined8 local_278;
  undefined8 local_270;
  ulonglong *puStack_268;
  ulonglong *local_260;
  code **ppcStack_258;
  undefined8 local_250;
  undefined *puStack_248;
  ulonglong local_240;
  ulonglong local_238 [10];
  undefined4 local_1e8;
  undefined4 local_1e4;
  code *local_1d8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  code *local_1a0;
  code *local_198;
  code *local_190;
  code *local_178;
  code *local_170;
  code *local_168;
  code *local_148 [14];
  code *local_d8;
  code *local_b8;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  memset(&local_1e8,0,0x98);
  local_288 = (undefined8 *)((ulonglong)local_288 & 0xffffffffffff0000);
  local_290 = 0x31797341;
  local_298 = (undefined8 *)0x78;
  ExInitializeNPagedLookasideList(&AsyncIoCtxList,0,0,0x200);
  local_288 = (undefined8 *)((ulonglong)local_288 & 0xffffffffffff0000);
  local_290 = 0x32797341;
  local_298 = (undefined8 *)0x198;
  ExInitializeNPagedLookasideList(&AsyncInfoList,0,0,0x200);
  KeInitializeSpinLock(&GlobalLock);
  local_1e8 = 0x98028a;
  local_1d8 = AsyncMpSetOptions;
  local_1e4 = 0x11e06;
  local_1c8 = AsyncMpHaltEx;
  local_1c0 = AsyncUnload;
  local_1d0 = AsyncMpInitializeEx;
  local_298 = &MiniportDriverHandle;
  local_1b8 = AsyncMpPause;
  local_1b0 = AsyncMpRestart;
  local_1a0 = _guard_check_icall;
  local_198 = AsyncMpReturnNetBufferListChain;
  local_190 = _guard_check_icall;
  local_178 = _guard_check_icall;
  local_170 = _guard_check_icall;
  local_168 = _guard_check_icall;
  iVar2 = NdisMRegisterMiniportDriver(param_1,param_2,&MiniportDriverHandle,&local_1e8);
  if (iVar2 != 0) {
    iVar2 = -0x3fffffff;
    goto LAB_1c0001606;
  }
  local_238[5] = 0;
  local_238[6] = 0;
  local_240 = local_240 & 0xffffffff00000000;
  local_238[7] = 0;
  local_238[8] = 0;
  local_270 = 0;
  puStack_268 = (ulonglong *)0x0;
  local_260 = (ulonglong *)0x0;
  ppcStack_258 = (code **)0x0;
  local_250 = 0;
  puStack_248 = (undefined *)0x0;
  RtlInitUnicodeString(local_238 + 5,L"\\Device\\ASYNCMAC");
  RtlInitUnicodeString(local_238 + 7,L"\\DosDevices\\ASYNCMAC");
  local_270 = 0x380185;
  local_250 = 0;
  local_240 = 0;
  ppcVar4 = local_148;
  for (lVar3 = 0x1c; lVar3 != 0; lVar3 = lVar3 + -1) {
    *ppcVar4 = AsyncIrpStub;
    ppcVar4 = ppcVar4 + 1;
  }
  local_148[0] = AsyncDriverCreate;
  local_d8 = AsyncDriverDispatch;
  local_b8 = AsyncDriverCreate;
  puStack_268 = local_238 + 5;
  local_260 = local_238 + 7;
  ppcStack_258 = local_148;
  puStack_248 = &SDDL_LS_ALL;
  iVar2 = NdisRegisterDeviceEx
                    (MiniportDriverHandle,&local_270,&AsyncDeviceObject,&AsyncDeviceHandle);
  if (-1 < iVar2) {
    local_68 = 0x300002;
    local_64 = 1;
    local_60 = 0x280000;
    *(uint *)(AsyncDeviceObject + 0x30) = *(uint *)(AsyncDeviceObject + 0x30) | 4;
    lVar3 = AsyncDeviceObject;
    local_5c = 0x10000000;
    local_58 = 0x601;
    local_54 = 0x5000000;
    local_50 = 0x50;
    local_4c = 0xf8ee4d1a;
    local_48 = 0x1231c877;
    local_44 = 0x8682c501;
    local_40 = 0xa1c73fcb;
    local_3c = 0xd3bf5936;
    local_238[0] = 0;
    local_238[1] = 0;
    local_238[4] = 0;
    local_238[2] = 0;
    local_238[3] = 0;
    local_278 = 0;
    iVar2 = RtlCreateSecurityDescriptor(local_238,1);
    if ((iVar2 == 0) && (iVar2 = RtlSetDaclSecurityDescriptor(local_238,1,&local_68,0), iVar2 == 0))
    {
      cVar1 = RtlValidSecurityDescriptor(local_238);
      if (cVar1 != '\0') {
        local_238[0] = local_238[0] | 0x10000000;
        local_288 = &local_278;
        local_290 = local_290 & 0xffffff00;
        local_298 = (undefined8 *)0x0;
        iVar2 = ObOpenObjectByPointer(lVar3,0x200,0,0x40000);
        if (iVar2 == 0) {
          iVar2 = ZwSetSecurityObject(local_278,4,local_238);
          ZwClose(local_278);
        }
        goto LAB_1c00015c7;
      }
      iVar2 = -0x3fffff87;
    }
    else {
LAB_1c00015c7:
      if (-1 < iVar2) {
        NdisUnload = *(undefined8 *)(param_1 + 0x68);
        *(code **)(param_1 + 0x68) = AsyncUnload;
        return 0;
      }
    }
    *(uint *)(AsyncDeviceObject + 0x30) = *(uint *)(AsyncDeviceObject + 0x30) & 0xfffffffb;
    NdisDeregisterDeviceEx(AsyncDeviceHandle);
  }
  AsyncDeviceObject = 0;
  AsyncDeviceHandle = 0;
LAB_1c0001606:
  ExDeleteNPagedLookasideList(&AsyncIoCtxList);
  ExDeleteNPagedLookasideList(&AsyncInfoList);
  if (MiniportDriverHandle != 0) {
    NdisMDeregisterMiniportDriver();
    MiniportDriverHandle = 0;
  }
  return iVar2;
}



===== AsyncSetLinkInfo @ 1c0001680 =====

undefined4 AsyncSetLinkInfo(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined4 uVar11;
  
  puVar4 = *(undefined4 **)(param_1 + 0x20);
  uVar5 = *(undefined8 *)(param_1 + 0x30);
  lVar6 = *(longlong *)(param_1 + 0x28);
  ExFreePoolWithTag(param_1,0);
  lVar1 = lVar6 + 0x180;
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(uint *)(lVar6 + 0x14) = *(uint *)(lVar6 + 0x14) & 0xfffffffe;
  *(undefined1 *)(lVar6 + 0x188) = uVar9;
  if (*(int *)(lVar6 + 0x28) == 5) {
    uVar11 = puVar4[1];
    uVar7 = puVar4[2];
    uVar8 = puVar4[3];
    uVar2 = *(uint *)(lVar6 + 0xf4);
    *(undefined4 *)(lVar6 + 0xe8) = *puVar4;
    *(undefined4 *)(lVar6 + 0xec) = uVar11;
    *(undefined4 *)(lVar6 + 0xf0) = uVar7;
    *(undefined4 *)(lVar6 + 0xf4) = uVar8;
    uVar11 = puVar4[5];
    uVar7 = puVar4[6];
    uVar8 = puVar4[7];
    *(undefined4 *)(lVar6 + 0xf8) = puVar4[4];
    *(undefined4 *)(lVar6 + 0xfc) = uVar11;
    *(undefined4 *)(lVar6 + 0x100) = uVar7;
    *(undefined4 *)(lVar6 + 0x104) = uVar8;
    *(uint *)(lVar6 + 0x164) = *(uint *)(lVar6 + 0x164) & 0xbfffffff;
    *(uint *)(lVar6 + 0x168) = *(uint *)(lVar6 + 0x168) | 0x60000000;
    uVar3 = *(uint *)(lVar6 + 0x100);
    *(uint *)(lVar6 + 0x15c) = uVar3;
    if (*(int *)(*(longlong *)(lVar6 + 0x18) + 0x9c) != 0) {
      uVar10 = *(uint *)(lVar6 + 0x16c) | 0x20000;
      if ((uVar3 & 0x20000) == 0) {
        uVar10 = *(uint *)(lVar6 + 0x16c) & 0xfffdffff;
      }
      if ((uVar3 & 0x80000) == 0) {
        uVar10 = uVar10 & 0xfff7ffff;
      }
      else {
        uVar10 = uVar10 | 0x80000;
      }
      *(uint *)(lVar6 + 0x16c) = uVar10;
    }
    uVar3 = puVar4[3];
    if ((uVar3 != 0 || uVar2 != 0) && (uVar3 != 0)) {
      if ((uVar3 & uVar2 & 0x1100) == 0) {
        KeInitializeEvent(lVar6 + 0x40,1);
        *(undefined4 *)(lVar6 + 0x28) = 3;
        KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar6 + 0x188));
        CancelSerialRequests(lVar6);
        KeWaitForSingleObject(lVar6 + 0x40,6,0,0,0);
        *(undefined4 *)(lVar6 + 0x28) = 5;
        AsyncStartReads(lVar6);
        uVar11 = 0;
        goto LAB_1c0001807;
      }
      *(undefined4 *)(lVar6 + 0x28) = 5;
    }
    uVar11 = 0;
  }
  else {
    uVar11 = 0xc0000001;
  }
  KeReleaseSpinLock(lVar1,uVar9);
LAB_1c0001807:
  NdisMCoOidRequestComplete
            (*(undefined8 *)(*(longlong *)(lVar6 + 0x18) + 0x70),*(undefined8 *)(lVar6 + 0x98),uVar5
             ,uVar11);
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(lVar6 + 0x188) = uVar9;
  LOCK();
  *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + -1;
  UNLOCK();
  if (*(int *)(lVar6 + 0x10) == 0) {
    KeSetEvent(lVar6 + 0x70,1);
  }
  KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar6 + 0x188));
  return uVar11;
}



===== MpQueryInfo @ 1c000189c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint MpQueryInfo(int *param_1,undefined8 *param_2,longlong param_3)

{
  uint uVar1;
  bool bVar2;
  undefined8 *puVar3;
  char *_Src;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_78 [32];
  int local_58;
  undefined2 local_54 [2];
  int local_50 [3];
  int local_44;
  undefined2 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  uVar1 = *(uint *)(param_3 + 0x20);
  local_50[0] = 3;
  local_58 = 0;
  local_54[0] = 0;
  uVar5 = 4;
  local_44 = 0x59534120;
  uVar4 = 0;
  local_40 = 0xff4e;
  _Src = (char *)&local_58;
  local_50[1] = 0;
  if (uVar1 < 0x20102) {
    if (uVar1 == 0x20101) goto LAB_1c0001b1d;
    if (uVar1 < 0x1010a) {
      if (uVar1 != 0x10109) {
        if (uVar1 == 0x10101) {
          _Src = &AsyncGlobalSupportedOids;
          uVar5 = 0x94;
          goto LAB_1c0001b1d;
        }
        if (uVar1 == 0x10102) {
          _Src = (char *)(local_50 + 1);
          goto LAB_1c0001b1d;
        }
        if ((uVar1 == 0x10103) || (uVar1 == 0x10104)) {
          _Src = (char *)local_50;
          goto LAB_1c0001b1d;
        }
        if ((uVar1 == 0x10105) || (uVar1 == 0x10106)) goto LAB_1c00019e6;
        if (uVar1 == 0x10107) {
          local_58 = 0x120;
          goto LAB_1c0001b1d;
        }
        if (uVar1 != 0x10108) {
          return 0xc00000bb;
        }
      }
      local_58 = param_1[0x21] * 2;
      goto LAB_1c0001b1d;
    }
    if ((uVar1 != 0x1010a) && (uVar1 != 0x1010b)) {
      if (uVar1 == 0x1010c) {
        local_58 = -1;
        uVar5 = 3;
        goto LAB_1c0001b1d;
      }
      if (uVar1 == 0x1010d) {
        _Src = "AsyncMac Adapter";
        goto LAB_1c0001b18;
      }
      if (uVar1 != 0x1010f) {
        if (uVar1 == 0x10110) {
          _Src = (char *)local_54;
          local_54[0] = 0x500;
          uVar5 = 2;
          goto LAB_1c0001b1d;
        }
        if (uVar1 != 0x10111) {
          if (uVar1 != 0x10113) {
            return 0xc00000bb;
          }
          local_58 = 7;
          goto LAB_1c0001b1d;
        }
      }
    }
LAB_1c00019e6:
    local_58 = param_1[0x21];
  }
  else {
    if (uVar1 < 0x4010107) {
      if (uVar1 == 0x4010106) {
        local_58 = 1;
      }
      else if ((((uVar1 != 0x20102) && (uVar1 != 0x20103)) && (uVar1 != 0x20104)) &&
              (uVar1 != 0x20105)) {
        if ((uVar1 == 0x4010101) || (uVar1 == 0x4010102)) {
          _Src = (char *)&local_44;
          uVar5 = 6;
        }
        else if (uVar1 != 0x4010104) {
          if (uVar1 != 0x4010105) {
            return 0xc00000bb;
          }
          local_58 = 3;
        }
      }
      goto LAB_1c0001b1d;
    }
    if (uVar1 != 0x4010180) {
      if (uVar1 == 0x4010182) {
        if (*(uint *)(param_3 + 0x30) < 0x20) {
          return 0xc0010016;
        }
        bVar2 = false;
        for (puVar3 = *(undefined8 **)(param_2[3] + 0x28);
            puVar3 != (undefined8 *)(param_2[3] + 0x28); puVar3 = (undefined8 *)*puVar3) {
          if (param_2 == puVar3) {
            bVar2 = true;
            _Src = (char *)(param_2 + 0x1d);
            break;
          }
        }
        uVar4 = ~-(uint)bVar2 & 0xc0010015;
        uVar5 = (-(uint)bVar2 & 0x1c) + 4;
        if (!bVar2) {
          return uVar4;
        }
      }
      else if (((uVar1 == 0x4010280) || (uVar1 == 0x4010282)) ||
              ((2 < uVar1 + 0x2feff00 && (uVar1 != 0xfd010106)))) {
        return 0xc00000bb;
      }
      goto LAB_1c0001b1d;
    }
    _Src = (char *)param_1;
LAB_1c0001b18:
    uVar5 = 0x10;
  }
LAB_1c0001b1d:
  if (*(uint *)(param_3 + 0x30) < uVar5) {
    *(uint *)(param_3 + 0x38) = uVar5;
    return 0xc0010016;
  }
  memcpy(*(void **)(param_3 + 0x28),_Src,(ulonglong)uVar5);
  *(int *)(param_3 + 0x34) = *(int *)(param_3 + 0x34) + uVar5;
  return uVar4;
}



===== MpSetInfo @ 1c0001b5c =====

undefined8 MpSetInfo(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  
  iVar2 = *(int *)(param_3 + 0x20);
  uVar4 = *(undefined8 *)(param_3 + 0x28);
  uVar3 = *(undefined4 *)(param_3 + 0x30);
  if (iVar2 == 0x4010181) {
    lVar1 = param_2 + 0x180;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_2 + 0x188) = uVar5;
    if (*(int *)(param_2 + 0x28) == 5) {
      puVar6 = (undefined8 *)ExAllocatePool2(0x40,0x38,0x35797341);
      if (puVar6 != (undefined8 *)0x0) {
        *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 1;
        LOCK();
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
        UNLOCK();
        KeReleaseSpinLock(lVar1,*(undefined1 *)(param_2 + 0x188));
        *puVar6 = 0;
        puVar6[2] = AsyncSetLinkInfo;
        puVar6[4] = uVar4;
        puVar6[5] = param_2;
        puVar6[6] = param_3;
        puVar6[3] = puVar6;
        ExQueueWorkItem(puVar6,1);
        return 0x103;
      }
      uVar5 = *(undefined1 *)(param_2 + 0x188);
    }
    KeReleaseSpinLock(lVar1,uVar5);
  }
  else {
    if (iVar2 == 0x4010281) {
      return 0xc0010017;
    }
    if ((2 < iVar2 + 0x2feff00U) && (iVar2 != -0x2fefefa)) {
      *(undefined4 *)(param_3 + 0x34) = 0;
      *(undefined4 *)(param_3 + 0x38) = 0;
      return 0xc0010017;
    }
  }
  *(undefined4 *)(param_3 + 0x34) = uVar3;
  *(undefined4 *)(param_3 + 0x38) = 0;
  return 0;
}



===== AsyncIOCtlRequest @ 1c0001cb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint AsyncIOCtlRequest(longlong *param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  code *pcVar8;
  undefined1 uVar9;
  int iVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  longlong lVar13;
  char *pcVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  longlong *plVar17;
  uint uVar18;
  longlong *plVar19;
  bool bVar20;
  longlong *local_res10;
  undefined8 local_res18;
  char *local_res20;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  char **local_58;
  undefined8 *local_50;
  undefined8 local_48 [2];
  
  uVar2 = *(uint *)(param_2 + 0x18);
  uVar18 = *(uint *)(param_2 + 8);
  local_res18 = 0;
  uVar3 = *(uint *)(param_2 + 0x10);
  plVar12 = (longlong *)0x0;
  plVar19 = (longlong *)0x0;
  if ((uVar2 & 0xffff0000) != 0x120000) {
    return 0xc000000d;
  }
  plVar15 = (longlong *)param_1[3];
  if (uVar2 == 0x120000) {
    param_1[7] = 0x18;
    if ((uVar3 < 0x18) || (uVar18 < 0x18)) {
      return 0xc0000004;
    }
  }
  else {
    if (uVar2 == 0x120004) {
      uVar18 = -(uint)(uVar3 < 0x10) & 0xc0000004;
      plVar12 = plVar15;
      if (uVar3 < 0x10) {
        plVar12 = (longlong *)0x0;
      }
    }
    else {
      if (uVar2 == 0x120008) {
        return 0;
      }
      if (uVar2 != 0x12000c) {
        return 0xc0000010;
      }
      uVar18 = -(uint)(uVar3 < 0x10) & 0xc0000004;
      plVar19 = plVar15;
      if (uVar3 < 0x10) {
        plVar19 = (longlong *)0x0;
      }
    }
    if (uVar18 != 0) {
      return uVar18;
    }
  }
  lVar7 = GlobalAdapter;
  uVar18 = 0;
  if (GlobalAdapter == 0) {
    return 700;
  }
  plVar17 = (longlong *)(GlobalAdapter + 0x38);
  local_res10 = plVar15;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar17);
  lVar13 = CONCAT71((int7)((ulonglong)plVar15 >> 8),uVar9);
  *(undefined1 *)(lVar7 + 0x40) = uVar9;
  if (uVar2 == 0x120000) {
    local_res20 = (char *)0x0;
    local_48[0] = 0;
    param_1 = (longlong *)ExAllocateFromNPagedLookasideList(&AsyncInfoList);
    if (param_1 != (longlong *)0x0) {
      memset(param_1,0,0x198);
      param_1[3] = lVar7;
      lVar13 = ExAllocateFromNPagedLookasideList(lVar7 + 0xc0);
      if (lVar13 == 0) {
        iVar10 = -0x3fffff66;
      }
      else {
        *(ulonglong *)(lVar13 + 8) = lVar13 + 0x58U & 0xfffffffffffffff8;
        *(undefined4 *)(lVar13 + 4) = *(undefined4 *)(lVar7 + 0x84);
        iVar10 = 0;
        *(longlong *)(lVar13 + 0x30) = lVar7;
        *(longlong **)(lVar13 + 0x38) = param_1;
      }
      param_1[0x21] = lVar13;
      if (iVar10 == 0) {
        KeInitializeEvent(param_1 + 0xb,1,1);
        KeInitializeEvent(param_1 + 0xe,1,1);
        NdisInitializeEvent(param_1 + 0x16);
        NdisInitializeEvent(param_1 + 0x19);
        LOCK();
        *(int *)(lVar7 + 0x14) = *(int *)(lVar7 + 0x14) + 1;
        UNLOCK();
        *(int *)(param_1 + 2) = (int)param_1[2] + 1;
        *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 4;
        KeClearEvent(param_1 + 0xe);
        KeReleaseSpinLock(plVar17,*(undefined1 *)(lVar7 + 0x40));
        plVar12 = local_res10;
        local_50 = local_48;
        local_58 = &local_res20;
        iVar10 = ObReferenceObjectByHandle(local_res10[2],3,*(undefined8 *)IoFileObjectType_exref,1)
        ;
        plVar17 = (longlong *)0x0;
        if (-1 < iVar10) {
          plVar19 = param_1 + 0x14;
          param_1[0x15] = (longlong)plVar19;
          *plVar19 = (longlong)plVar19;
          *(undefined4 *)(param_1 + 5) = 4;
          param_1[6] = plVar12[2];
          *(int *)((longlong)param_1 + 0x8c) = (int)plVar12[1];
          param_1[0x12] = (longlong)param_1;
          *plVar12 = (longlong)param_1;
          *(uint *)(param_1 + 0x11) = (uint)*(ushort *)((longlong)plVar12 + 0xc);
          *(undefined4 *)(param_1 + 5) = 5;
          param_1[7] = (longlong)local_res20;
          *(undefined4 *)(param_1 + 0x1d) = 0x5dc;
          *(undefined4 *)((longlong)param_1 + 0xec) = 0x5dc;
          *(undefined4 *)(param_1 + 0x1e) = 0x100;
          *(undefined8 *)((longlong)param_1 + 0xf4) = 0x100;
          *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
          *(undefined4 *)((longlong)param_1 + 0x104) = 0xffffffff;
          *(undefined4 *)((longlong)param_1 + 0x15c) = 0xffffffff;
          *(undefined4 *)((longlong)param_1 + 0xfc) = 0;
          *(undefined4 *)(param_1 + 0x2d) = 0x60000000;
          iVar10 = AsyncSendLineUp((longlong)param_1);
          if (iVar10 == 0) {
            KeInitializeSpinLock(param_1 + 0x30);
            lVar13 = IoGetRelatedDeviceObject(local_res20);
            ObfReferenceObject(lVar13);
            param_1[4] = lVar13;
            param_1[0x27] = 0;
            param_1[0x28] = 0;
            param_1[0x29] = 0;
            uVar9 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x38);
            puVar16 = auStack_78;
            *(undefined1 *)(lVar7 + 0x40) = uVar9;
            plVar12 = (longlong *)(lVar7 + 0x28);
            lVar13 = *plVar12;
            if (*(longlong **)(lVar13 + 8) != plVar12) {
LAB_1c0002564:
              pcVar8 = (code *)swi(0x29);
              plVar12 = (longlong *)(*pcVar8)(3);
              puVar16 = auStack_70;
            }
            *param_1 = lVar13;
            param_1[1] = (longlong)plVar12;
            *(longlong **)(lVar13 + 8) = param_1;
            *plVar12 = (longlong)param_1;
            uVar9 = *(undefined1 *)(lVar7 + 0x40);
            *(undefined8 *)(puVar16 + -8) = 0x1c0002587;
            KeReleaseSpinLock(lVar7 + 0x38,uVar9);
            lVar13 = param_1[4];
            *(undefined4 *)((longlong)param_1 + 0xe4) = 0x4b2;
            uVar9 = *(undefined1 *)(lVar13 + 0x4c);
            *(undefined8 *)(puVar16 + -8) = 0x1c00025a6;
            lVar13 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar13 >> 8),uVar9),0);
            if (lVar13 != 0) {
              *(undefined8 *)(puVar16 + -8) = 0x1c00025c2;
              pcVar14 = AsyncAllocateIoCtx('\x01',param_1);
              if (pcVar14 == (char *)0x0) {
                *(undefined8 *)(puVar16 + -8) = 0x1c00025d4;
                IoFreeIrp(lVar13);
              }
              else {
                lVar5 = param_1[7];
                lVar6 = *(longlong *)(lVar13 + 0xb8);
                *(longlong *)(lVar13 + 0xc0) = lVar5;
                *(short *)(lVar13 + 0x40) = (short)plVar17;
                *(longlong **)(lVar13 + 0x50) = plVar17;
                *(longlong **)(lVar13 + 0x58) = plVar17;
                *(longlong **)(lVar13 + 0x60) = plVar17;
                *(undefined4 *)(lVar13 + 0x10) = 0x10;
                *(longlong *)(lVar6 + -0x18) = lVar5;
                *(undefined4 *)(lVar6 + -0x38) = 4;
                *(undefined4 *)(lVar6 + -0x40) = 4;
                *(undefined1 *)(lVar6 + -0x48) = 0xe;
                *(undefined4 *)(lVar6 + -0x30) = 0x1b3e80;
                *(undefined4 *)(pcVar14 + 0x38) = *(undefined4 *)(lVar7 + 0x98);
                lVar7 = *(longlong *)(lVar13 + 0xb8);
                *(char **)(lVar13 + 0x18) = pcVar14 + 0x38;
                *(code **)(lVar7 + -0x10) = SerialIoSyncCompletionRoutine;
                *(char **)(lVar7 + -8) = pcVar14;
                *(undefined1 *)(lVar7 + -0x45) = 0xe0;
                *(undefined8 *)(puVar16 + -8) = 0x1c0002657;
                KeClearEvent(pcVar14 + 8);
                lVar7 = param_1[4];
                *(undefined8 *)(puVar16 + -8) = 0x1c000266a;
                iVar10 = IofCallDriver(lVar7,lVar13);
                if (iVar10 == 0x103) {
                  *(ulonglong *)(puVar16 + 0x20) =
                       *(ulonglong *)(puVar16 + 0x20) & (ulonglong)plVar17;
                  *(undefined8 *)(puVar16 + -8) = 0x1c0002690;
                  KeWaitForSingleObject(pcVar14 + 8,0,0,0);
                  iVar10 = *(int *)(pcVar14 + 0x20);
                }
                *(undefined8 *)(puVar16 + -8) = 0x1c00026a3;
                IoFreeIrp(lVar13);
                *(undefined8 *)(puVar16 + -8) = 0x1c00026b9;
                ExFreeToNPagedLookasideList(&AsyncIoCtxList,pcVar14);
                if (iVar10 == 0) {
                  *(uint *)((longlong)param_1 + 0xe4) =
                       *(uint *)((longlong)param_1 + 0xe4) & 0xffffff7f;
                }
              }
            }
            param_1[0x26] = 6;
            *(undefined8 *)(puVar16 + -8) = 0x1c00026dd;
            AsyncStartReads((longlong)param_1);
            LOCK();
            UNLOCK();
            if (glConnectionCount == 0) {
              *(undefined8 *)(puVar16 + -8) = 0x1c00026fe;
              glConnectionCount = glConnectionCount + 1;
              ObfReferenceObject(AsyncDeviceObject);
              return 0;
            }
            glConnectionCount = glConnectionCount + 1;
            return 0;
          }
        }
        *(undefined4 *)(param_1 + 5) = 2;
        ExFreeToNPagedLookasideList(lVar7 + 0xc0,param_1[0x21]);
        ExFreeToNPagedLookasideList(&AsyncInfoList,param_1);
        return 0x2be;
      }
      ExFreeToNPagedLookasideList(&AsyncInfoList,param_1);
    }
    KeReleaseSpinLock(plVar17,*(undefined1 *)(lVar7 + 0x40));
    return 0x2be;
  }
  if ((uVar2 != 0x120004) && ((uVar2 == 0x120008 || (uVar2 != 0x12000c)))) {
    KeReleaseSpinLock(plVar17);
    return 0;
  }
  if (uVar2 == 0x120004) {
    param_1 = (longlong *)*plVar12;
    for (plVar12 = *(longlong **)(param_1[3] + 0x28); plVar12 != (longlong *)(param_1[3] + 0x28);
        plVar12 = (longlong *)*plVar12) {
      if (param_1 == plVar12) {
        KeReleaseSpinLock(plVar17);
        plVar17 = param_1 + 0x30;
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar17);
        *(undefined1 *)(param_1 + 0x31) = uVar9;
        if ((int)param_1[5] != 5) {
          KeReleaseSpinLock(plVar17,uVar9);
          return 0x2c1;
        }
        *(undefined4 *)(param_1 + 5) = 3;
        KeInitializeEvent(param_1 + 8,1);
        KeReleaseSpinLock(plVar17,(char)param_1[0x31]);
        local_58 = (char **)0x0;
        KeWaitForSingleObject(param_1 + 0xb,6,0,0);
        CancelSerialRequests((longlong)param_1);
        AsyncCancelAllQueued(param_1 + 0x14);
        local_58 = (char **)&local_res18;
        local_res18 = 0xfffffffffa0a1f00;
        iVar10 = KeWaitForSingleObject(param_1 + 8,6,0,0);
        if ((iVar10 == 0x102) &&
           (lVar13 = IoAllocateIrp(CONCAT71((int7)((ulonglong)param_1[4] >> 8),
                                            *(undefined1 *)(param_1[4] + 0x4c)),0), lVar13 != 0)) {
          local_res20 = AsyncAllocateIoCtx('\x01',param_1);
          if (local_res20 == (char *)0x0) {
            IoFreeIrp(lVar13);
          }
          else {
            lVar5 = param_1[7];
            lVar6 = *(longlong *)(lVar13 + 0xb8);
            *(longlong *)(lVar13 + 0xc0) = lVar5;
            *(undefined2 *)(lVar13 + 0x40) = 0;
            *(undefined8 *)(lVar13 + 0x50) = 0;
            *(undefined8 *)(lVar13 + 0x58) = 0;
            *(undefined8 *)(lVar13 + 0x60) = 0;
            *(undefined4 *)(lVar13 + 0x10) = 0x10;
            *(longlong *)(lVar6 + -0x18) = lVar5;
            *(undefined4 *)(lVar6 + -0x38) = 4;
            *(undefined4 *)(lVar6 + -0x40) = 4;
            *(undefined1 *)(lVar6 + -0x48) = 0xe;
            *(undefined4 *)(lVar6 + -0x30) = 0x1b004c;
            local_res20[0x38] = '\x03';
            *(char **)(lVar13 + 0x18) = local_res20 + 0x38;
            lVar5 = *(longlong *)(lVar13 + 0xb8);
            *(code **)(lVar5 + -0x10) = SerialIoSyncCompletionRoutine;
            *(char **)(lVar5 + -8) = local_res20;
            *(undefined1 *)(lVar5 + -0x45) = 0xe0;
            local_res10 = (longlong *)(local_res20 + 8);
            KeClearEvent(local_res10);
            iVar10 = IofCallDriver(param_1[4],lVar13);
            if (iVar10 == 0x103) {
              local_58 = (char **)0x0;
              KeWaitForSingleObject(local_res10,0,0,0);
            }
            IoFreeIrp(lVar13);
            ExFreeToNPagedLookasideList(&AsyncIoCtxList,local_res20);
            KeDelayExecutionThread(0,0,&local_res18);
          }
        }
        ObfDereferenceObject(param_1[4]);
        ObfDereferenceObject(param_1[7]);
        NdisCmDispatchIncomingCloseCall(0,param_1[0x13],0,0);
        NdisWaitEvent(param_1 + 0x19,0);
        NdisMCmDeleteVc(param_1[0x13]);
        piVar1 = (int *)(lVar7 + 0x48);
        LOCK();
        iVar10 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar10 == 1) {
          (**(code **)(lVar7 + 0x50))();
        }
        ExFreePoolWithTag(param_1[0x32],0);
        *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) & 0xfffffffb;
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar17);
        *(undefined1 *)(param_1 + 0x31) = uVar9;
        LOCK();
        *(int *)(param_1 + 2) = (int)param_1[2] + -1;
        UNLOCK();
        if ((int)param_1[2] == 0) {
          KeSetEvent(param_1 + 0xe,1,0);
        }
        KeReleaseSpinLock(plVar17,(char)param_1[0x31]);
        local_58 = (char **)0x0;
        lVar13 = 6;
        KeWaitForSingleObject(param_1 + 0xe,6,0,0);
        uVar9 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x38);
        *(undefined1 *)(lVar7 + 0x40) = uVar9;
        lVar5 = *param_1;
        if ((*(longlong **)(lVar5 + 8) != param_1) ||
           (plVar12 = (longlong *)param_1[1], (longlong *)*plVar12 != param_1)) goto LAB_1c0002564;
        *plVar12 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar12;
        LOCK();
        *(int *)(lVar7 + 0x14) = *(int *)(lVar7 + 0x14) + -1;
        UNLOCK();
        *(undefined4 *)(param_1 + 5) = 2;
        ExFreeToNPagedLookasideList(lVar7 + 0xc0,param_1[0x21]);
        ExFreeToNPagedLookasideList(&AsyncInfoList,param_1);
        LOCK();
        iVar10 = glConnectionCount + -1;
        UNLOCK();
        bVar20 = glConnectionCount == 1;
        glConnectionCount = iVar10;
        if (bVar20) {
          ObfDereferenceObject(AsyncDeviceObject);
        }
        goto LAB_1c0001e14;
      }
    }
  }
  else {
    if (uVar2 != 0x12000c) goto LAB_1c0001e14;
    puVar4 = (undefined8 *)*plVar19;
    for (puVar11 = *(undefined8 **)(lVar7 + 0x28); puVar11 != (undefined8 *)(lVar7 + 0x28);
        puVar11 = (undefined8 *)*puVar11) {
      if (puVar4 == puVar11) {
        if (*(int *)(puVar4 + 5) != 2) {
          plVar15 = puVar4 + 0x14;
          AsyncCancelAllQueued(plVar15);
          local_res10 = (longlong *)((ulonglong)local_res10 & 0xffffffffffffff00);
          IoAcquireCancelSpinLock(&local_res10);
          *(undefined4 *)(param_1 + 6) = 0x103;
          *(byte *)(param_1[0x17] + 3) = *(byte *)(param_1[0x17] + 3) | 1;
          plVar12 = param_1 + 0x15;
          plVar19 = (longlong *)puVar4[0x15];
          if ((longlong *)*plVar19 != plVar15) goto LAB_1c0002564;
          param_1[0x16] = (longlong)plVar19;
          *plVar12 = (longlong)plVar15;
          *plVar19 = (longlong)plVar12;
          puVar4[0x15] = plVar12;
          LOCK();
          param_1[0xd] = (longlong)AsyncCancelQueued;
          UNLOCK();
          IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)plVar19 >> 8),local_res10._0_1_));
          uVar18 = 0x103;
          goto LAB_1c0001e14;
        }
        break;
      }
    }
  }
  uVar18 = 0x2c0;
LAB_1c0001e14:
  KeReleaseSpinLock(lVar7 + 0x38,*(undefined1 *)(lVar7 + 0x40));
  return uVar18;
}



===== AsyncSendLineUp @ 1c0002730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AsyncSendLineUp(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  
  lVar5 = *(longlong *)(param_1 + 0x18);
  bVar6 = false;
  puVar10 = (undefined4 *)ExAllocatePool2(0x40,0x90,0x37797341);
  if (puVar10 == (undefined4 *)0x0) {
    return -0x3fffffff;
  }
  lVar1 = lVar5 + 0x38;
  *(undefined4 **)(puVar10 + 2) = puVar10 + 6;
  *(undefined4 **)(puVar10 + 4) = puVar10 + 0x1a;
  uVar8 = *(uint *)(param_1 + 0x8c) >> 3;
  puVar10[6] = uVar8;
  puVar10[8] = uVar8;
  puVar10[0xe] = uVar8;
  puVar10[0x10] = uVar8;
  puVar10[0xc] = 0x5dc;
  puVar10[0x14] = 0x5dc;
  *puVar10 = 4;
  *(longlong *)(puVar10 + 0x22) = param_1;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  plVar3 = (longlong *)(param_1 + 0x98);
  *(undefined1 *)(lVar5 + 0x40) = uVar7;
  piVar2 = (int *)(lVar5 + 0x48);
  if (*(int *)(lVar5 + 0x58) == 0) {
    KeReleaseSpinLock(lVar1,uVar7);
    iVar9 = -0x3fffffff;
  }
  else {
    LOCK();
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar5 + 0x40));
    bVar6 = true;
    iVar9 = NdisMCmCreateVc(*(undefined8 *)(lVar5 + 0x70),*(undefined8 *)(lVar5 + 0x68),param_1,
                            plVar3);
    if (iVar9 == 0) {
      *(undefined4 **)(param_1 + 400) = puVar10;
      iVar9 = NdisCmDispatchIncomingCall(*(undefined8 *)(lVar5 + 0x60),*plVar3,puVar10);
      if (iVar9 == 0x103) {
        NdisWaitEvent(param_1 + 0xb0,0);
        iVar9 = *(int *)(param_1 + 0xe0);
      }
      if (iVar9 == 0) {
        return 0;
      }
    }
  }
  if (*plVar3 != 0) {
    NdisMCmDeleteVc();
    *plVar3 = 0;
  }
  if (bVar6) {
    LOCK();
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      (**(code **)(lVar5 + 0x50))(piVar2);
    }
  }
  ExFreePoolWithTag(puVar10,0);
  return iVar9;
}



===== AsyncMpCoSendNetBufferListChain @ 1c00028f0 =====

void AsyncMpCoSendNetBufferListChain(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  puVar5 = param_2;
  if (*(int *)(*(longlong *)(param_1 + 0x18) + 0x10) == 1) {
    if ((*(int *)(param_1 + 0x28) == 5) && ((*(uint *)(param_1 + 0xf0) & 0x1100) != 0)) {
      if (param_2 == (undefined8 *)0x0) {
        return;
      }
      *param_2 = 0;
      *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
      puVar5 = (undefined8 *)param_2[1];
      *(undefined4 *)(param_2 + 0xe) = 1;
      for (; puVar5 != (undefined8 *)0x0; puVar5 = (undefined8 *)*puVar5) {
        puVar5[0x10] = param_2;
        LOCK();
        *(int *)(param_2 + 0xe) = *(int *)(param_2 + 0xe) + 1;
        UNLOCK();
        uVar3 = AsyncSendNB(param_1,(longlong)puVar5);
        if ((int)uVar3 != 0x103) {
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0000001;
          LOCK();
          *(int *)(param_2 + 0xe) = *(int *)(param_2 + 0xe) + -1;
          UNLOCK();
          break;
        }
      }
      LOCK();
      piVar1 = (int *)(param_2 + 0xe);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        return;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x98);
      goto LAB_1c00029d4;
    }
    for (; puVar5 != (undefined8 *)0x0; puVar5 = (undefined8 *)*puVar5) {
      *(undefined4 *)((longlong)puVar5 + 0x8c) = 0xc0000001;
    }
  }
  else {
    for (; puVar5 != (undefined8 *)0x0; puVar5 = (undefined8 *)*puVar5) {
      *(undefined4 *)((longlong)puVar5 + 0x8c) = 0xc023002a;
    }
  }
  uVar4 = *(undefined8 *)(param_1 + 0x98);
LAB_1c00029d4:
  NdisMCoSendNetBufferListsComplete(uVar4,param_2,0);
  return;
}



===== AsyncSendNB @ 1c00029fc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AsyncSendNB(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint local_res8 [2];
  ulonglong in_stack_ffffffffffffffb8;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  lVar3 = *(longlong *)(param_1 + 0x38);
  lVar4 = *(longlong *)(param_1 + 0x18);
  lVar5 = IoAllocateIrp(*(undefined1 *)(lVar2 + 0x4c),0);
  if (lVar5 == 0) {
    return 0xc000009a;
  }
  lVar1 = lVar4 + 0x140;
  puVar6 = (undefined1 *)ExAllocateFromNPagedLookasideList(lVar1);
  if (puVar6 == (undefined1 *)0x0) {
    uVar10 = 0xc000009a;
  }
  else {
    uVar9 = *(uint *)(lVar4 + 0x1c0);
    *(longlong *)(param_2 + 0x88) = param_1;
    *(undefined1 **)(param_2 + 0x90) = puVar6;
    *(undefined2 *)(lVar5 + 0x40) = 0;
    *(undefined8 *)(lVar5 + 0x50) = 0;
    *(undefined8 *)(lVar5 + 0x58) = 0;
    *(undefined8 *)(lVar5 + 0x60) = 0;
    lVar4 = *(longlong *)(lVar5 + 0xb8);
    *(longlong *)(lVar5 + 0xc0) = lVar3;
    *(undefined1 *)(lVar4 + -0x48) = 4;
    *(longlong *)(lVar4 + -0x18) = lVar3;
    if ((*(uint *)(lVar3 + 0x50) & 0x10) != 0) {
      *(undefined1 *)(lVar4 + -0x46) = 4;
    }
    *(uint *)(lVar5 + 0x10) = *(uint *)(lVar5 + 0x10) | (*(uint *)(lVar3 + 0x50) & 8 | 0x1000) >> 3;
    local_res8[0] = uVar9;
    pbVar7 = (byte *)NdisGetDataBuffer(param_2,*(undefined4 *)(param_2 + 0x18),puVar6 + 0x5dc,1,
                                       in_stack_ffffffffffffffb8 & 0xffffffff00000000);
    if (pbVar7 != (byte *)0x0) {
      if ((*(uint *)(param_1 + 0xf0) & 0x100) != 0) {
        uVar8 = AssemblePPPFrame(param_1,pbVar7,*(int *)(param_2 + 0x18),puVar6,local_res8);
        uVar10 = uVar8 & 0xffffffff;
        if ((int)uVar8 != 0) {
          ExFreeToNPagedLookasideList(lVar1,puVar6);
          goto LAB_1c0002b5b;
        }
        uVar9 = local_res8[0];
      }
      _GlobalXmitWentOut = _GlobalXmitWentOut + 1;
      *(undefined1 **)(lVar5 + 0x18) = puVar6;
      *(undefined4 *)(lVar4 + -0x38) = 0;
      *(uint *)(lVar4 + -0x40) = uVar9;
      *(undefined8 *)(lVar4 + -0x30) = *(undefined8 *)(lVar3 + 0x68);
      lVar3 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar3 + -0x10) = AsyncWriteCompletionRoutine;
      *(longlong *)(lVar3 + -8) = param_2;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10;
      LOCK();
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      UNLOCK();
      IofCallDriver(lVar2,lVar5);
      return 0x103;
    }
    ExFreeToNPagedLookasideList(lVar1,puVar6);
    uVar10 = 0xc000021b;
  }
LAB_1c0002b5b:
  IoFreeIrp(lVar5);
  return uVar10;
}



===== AsyncWriteCompletionRoutine @ 1c0002bf0 =====

undefined8 AsyncWriteCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  lVar3 = *(longlong *)(param_3 + 0x88);
  lVar4 = *(longlong *)(param_3 + 0x80);
  uVar5 = *(undefined8 *)(param_3 + 0x90);
  iVar2 = *(int *)(param_2 + 0x30);
  lVar6 = *(longlong *)(lVar3 + 0x18);
  IoFreeIrp(param_2);
  ExFreeToNPagedLookasideList(lVar6 + 0x140,uVar5);
  if (iVar2 != 0) {
    *(undefined4 *)(lVar4 + 0x8c) = 0xc0000001;
  }
  *(int *)(lVar3 + 0x154) = *(int *)(lVar3 + 0x154) + 1;
  LOCK();
  piVar1 = (int *)(lVar4 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(lVar3 + 0x98),lVar4,0);
  }
  *(uint *)(lVar3 + 0x14) = *(uint *)(lVar3 + 0x14) & 0xffffffef;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x180);
  *(undefined1 *)(lVar3 + 0x188) = uVar7;
  LOCK();
  *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + -1;
  UNLOCK();
  if (*(int *)(lVar3 + 0x10) == 0) {
    KeSetEvent(lVar3 + 0x70,1);
  }
  KeReleaseSpinLock(lVar3 + 0x180,*(undefined1 *)(lVar3 + 0x188));
  return 0xc0000016;
}



===== AsyncIndicateFragment @ 1c0002d04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AsyncIndicateFragment(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8 [4];
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined4 local_84;
  undefined4 *local_68;
  undefined4 local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = *(longlong *)(param_1 + 0x18);
  memset(local_98,0,0x70);
  local_98[0] = 0x700198;
  local_90 = *(undefined8 *)(lVar1 + 0x70);
  local_68 = local_a8;
  local_84 = 0x40010015;
  local_60 = 4;
  local_a8[0] = param_2;
  NdisMCoIndicateStatusEx(*(undefined8 *)(lVar1 + 0x70),*(undefined8 *)(param_1 + 0x98),local_98);
  return;
}



===== AsyncStartReads @ 1c0002db4 =====

undefined8 AsyncStartReads(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  
  *(undefined8 *)(*(longlong *)(param_1 + 0x108) + 0x30) = *(undefined8 *)(param_1 + 0x18);
  *(longlong *)(*(longlong *)(param_1 + 0x108) + 0x38) = param_1;
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)));
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x38);
    lVar3 = *(longlong *)(lVar4 + 0xb8);
    *(undefined2 *)(lVar4 + 0x40) = 0;
    *(undefined8 *)(lVar4 + 0x50) = 0;
    *(undefined8 *)(lVar4 + 0x58) = 0;
    *(undefined8 *)(lVar4 + 0x60) = 0;
    *(undefined8 *)(lVar4 + 0xc0) = uVar2;
    *(undefined4 *)(lVar4 + 0x10) = 0x10;
    *(undefined8 *)(lVar3 + -0x18) = uVar2;
    *(undefined1 *)(lVar3 + -0x48) = 0xe;
    *(undefined4 *)(lVar3 + -0x30) = 0x1b0008;
    *(undefined4 *)(lVar3 + -0x38) = 8;
    *(undefined4 *)(lVar3 + -0x40) = 8;
    pcVar5 = AsyncAllocateIoCtx('\0',param_1);
    if (pcVar5 == (char *)0x0) {
      IoFreeIrp(lVar4);
    }
    else {
      pcVar5[0x3c] = '\0';
      pcVar5[0x3d] = '\x10';
      pcVar5[0x3e] = '\0';
      pcVar5[0x3f] = '\0';
      pcVar6 = pcVar5 + 0x38;
      pcVar6[0] = '\0';
      pcVar6[1] = '\x10';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      *(char **)(lVar4 + 0x18) = pcVar6;
      lVar4 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar4 + -0x10) = SerialIoAsyncCompletionRoutine;
      *(char **)(lVar4 + -8) = pcVar5;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(param_1 + 0x20));
      SetSerialTimeouts(param_1);
    }
  }
  SerialSetEventChar(param_1,(-((*(uint *)(param_1 + 0xf4) & 0x1000) != 0) & 0x42U) + 0x7e);
  uVar1 = *(undefined4 *)(param_1 + 0xe4);
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)),0);
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x38);
    lVar3 = *(longlong *)(lVar4 + 0xb8);
    *(undefined2 *)(lVar4 + 0x40) = 0;
    *(undefined8 *)(lVar4 + 0x50) = 0;
    *(undefined8 *)(lVar4 + 0x58) = 0;
    *(undefined8 *)(lVar4 + 0x60) = 0;
    *(undefined8 *)(lVar4 + 0xc0) = uVar2;
    *(undefined4 *)(lVar4 + 0x10) = 0x10;
    *(undefined8 *)(lVar3 + -0x18) = uVar2;
    *(undefined1 *)(lVar3 + -0x48) = 0xe;
    *(undefined4 *)(lVar3 + -0x30) = 0x1b0044;
    *(undefined4 *)(lVar3 + -0x38) = 4;
    *(undefined4 *)(lVar3 + -0x40) = 4;
    pcVar5 = AsyncAllocateIoCtx('\0',param_1);
    if (pcVar5 == (char *)0x0) {
      IoFreeIrp(lVar4);
    }
    else {
      *(undefined4 *)(pcVar5 + 0x38) = uVar1;
      *(char **)(lVar4 + 0x18) = pcVar5 + 0x38;
      lVar3 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar3 + -0x10) = SerialIoAsyncCompletionRoutine;
      *(char **)(lVar3 + -8) = pcVar5;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(param_1 + 0x20),lVar4);
    }
  }
  AsyncPPPRead(param_1);
  return 0;
}



===== CancelSerialRequests @ 1c0002fbc =====

void CancelSerialRequests(longlong param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  char *pcVar7;
  char *pcVar8;
  
  lVar6 = *(longlong *)(param_1 + 0x20);
  lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar6 >> 8),*(undefined1 *)(lVar6 + 0x4c)),0);
  if (lVar6 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x38);
    lVar4 = *(longlong *)(lVar6 + 0xb8);
    *(undefined8 *)(lVar6 + 0xc0) = uVar3;
    *(undefined2 *)(lVar6 + 0x40) = 0;
    *(undefined8 *)(lVar6 + 0x50) = 0;
    *(undefined8 *)(lVar6 + 0x58) = 0;
    *(undefined8 *)(lVar6 + 0x60) = 0;
    *(undefined4 *)(lVar6 + 0x10) = 0x10;
    *(undefined8 *)(lVar4 + -0x18) = uVar3;
    *(undefined1 *)(lVar4 + -0x48) = 0xe;
    *(undefined4 *)(lVar4 + -0x30) = 0x1b0044;
    *(undefined4 *)(lVar4 + -0x38) = 4;
    *(undefined4 *)(lVar4 + -0x40) = 4;
    pcVar7 = AsyncAllocateIoCtx('\x01',param_1);
    if (pcVar7 == (char *)0x0) {
      IoFreeIrp(lVar6);
    }
    else {
      pcVar8 = pcVar7 + 0x38;
      pcVar1 = pcVar7 + 8;
      pcVar8[0] = '\0';
      pcVar8[1] = '\0';
      pcVar8[2] = '\0';
      pcVar8[3] = '\0';
      *(char **)(lVar6 + 0x18) = pcVar8;
      lVar4 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar4 + -0x10) = SerialIoSyncCompletionRoutine;
      *(char **)(lVar4 + -8) = pcVar7;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      KeClearEvent(pcVar1);
      iVar5 = IofCallDriver(*(longlong *)(param_1 + 0x20),lVar6);
      piVar2 = (int *)(pcVar7 + 0x20);
      if (iVar5 == 0x103) {
        KeWaitForSingleObject(pcVar1,0,0,0,0);
        iVar5 = *piVar2;
      }
      if (iVar5 != 0) {
        KeSetEvent(param_1 + 0x40,1);
      }
      uVar3 = *(undefined8 *)(param_1 + 0x38);
      lVar4 = *(longlong *)(lVar6 + 0xb8);
      *(undefined8 *)(lVar6 + 0xc0) = uVar3;
      *(undefined2 *)(lVar6 + 0x40) = 0;
      *(undefined8 *)(lVar6 + 0x50) = 0;
      *(undefined8 *)(lVar6 + 0x58) = 0;
      *(undefined8 *)(lVar6 + 0x60) = 0;
      *(undefined4 *)(lVar6 + 0x10) = 0x10;
      *(undefined8 *)(lVar4 + -0x18) = uVar3;
      *(undefined4 *)(lVar4 + -0x38) = 4;
      *(undefined4 *)(lVar4 + -0x40) = 4;
      *(undefined1 *)(lVar4 + -0x48) = 0xe;
      *(undefined4 *)(lVar4 + -0x30) = 0x1b004c;
      piVar2[0] = 0;
      piVar2[1] = 0;
      pcVar7[0x28] = '\0';
      pcVar7[0x29] = '\0';
      pcVar7[0x2a] = '\0';
      pcVar7[0x2b] = '\0';
      pcVar7[0x2c] = '\0';
      pcVar7[0x2d] = '\0';
      pcVar7[0x2e] = '\0';
      pcVar7[0x2f] = '\0';
      pcVar7[0x38] = '\x03';
      *(char **)(lVar6 + 0x18) = pcVar7 + 0x38;
      lVar4 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar4 + -0x10) = SerialIoSyncCompletionRoutine;
      *(char **)(lVar4 + -8) = pcVar7;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      KeClearEvent(pcVar1);
      iVar5 = IofCallDriver(*(undefined8 *)(param_1 + 0x20),lVar6);
      if (iVar5 == 0x103) {
        KeWaitForSingleObject(pcVar1,0,0,0,0);
        iVar5 = *piVar2;
      }
      if (iVar5 != 0) {
        KeSetEvent(param_1 + 0x40,1);
      }
      IoFreeIrp(lVar6);
      ExFreeToNPagedLookasideList(&AsyncIoCtxList,pcVar7);
    }
  }
  return;
}



===== SerialIoAsyncCompletionRoutine @ 1c0003220 =====

undefined8 SerialIoAsyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  IoFreeIrp(param_2);
  ExFreeToNPagedLookasideList(&AsyncIoCtxList,param_3);
  return 0xc0000016;
}



===== SerialIoSyncCompletionRoutine @ 1c0003260 =====

undefined8 SerialIoSyncCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_2 + 0x34);
  uVar2 = *(undefined4 *)(param_2 + 0x38);
  uVar3 = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_3 + 0x24) = uVar1;
  *(undefined4 *)(param_3 + 0x28) = uVar2;
  *(undefined4 *)(param_3 + 0x2c) = uVar3;
  KeSetEvent(param_3 + 8,1);
  return 0xc0000016;
}



===== SerialSetEventChar @ 1c0003298 =====

void SerialSetEventChar(longlong param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)),0);
  if (lVar4 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x38);
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar4 + 0xc0) = uVar1;
    *(undefined2 *)(lVar4 + 0x40) = 0;
    *(undefined8 *)(lVar4 + 0x50) = 0;
    *(undefined8 *)(lVar4 + 0x58) = 0;
    *(undefined8 *)(lVar4 + 0x60) = 0;
    *(undefined4 *)(lVar4 + 0x10) = 0x10;
    *(undefined8 *)(lVar2 + -0x18) = uVar1;
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x30) = 0x1b0058;
    *(undefined4 *)(lVar2 + -0x38) = 6;
    *(undefined4 *)(lVar2 + -0x40) = 6;
    pcVar5 = AsyncAllocateIoCtx('\x01',param_1);
    if (pcVar5 == (char *)0x0) {
      IoFreeIrp(lVar4);
    }
    else {
      *(char **)(lVar4 + 0x18) = pcVar5 + 0x38;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = SerialIoSyncCompletionRoutine;
      *(char **)(lVar2 + -8) = pcVar5;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      KeClearEvent(pcVar5 + 8);
      iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x20),lVar4);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(pcVar5 + 8,0,0,0,0);
        iVar3 = *(int *)(pcVar5 + 0x20);
      }
      if (iVar3 == 0) {
        pcVar5[0x3b] = param_2;
        *pcVar5 = '\0';
        uVar1 = *(undefined8 *)(param_1 + 0x38);
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(undefined8 *)(lVar4 + 0xc0) = uVar1;
        *(undefined2 *)(lVar4 + 0x40) = 0;
        *(undefined8 *)(lVar4 + 0x50) = 0;
        *(undefined8 *)(lVar4 + 0x58) = 0;
        *(undefined8 *)(lVar4 + 0x60) = 0;
        *(undefined4 *)(lVar4 + 0x10) = 0x10;
        *(undefined1 *)(lVar2 + -0x48) = 0xe;
        *(undefined8 *)(lVar2 + -0x18) = uVar1;
        *(undefined4 *)(lVar2 + -0x30) = 0x1b005c;
        *(undefined4 *)(lVar2 + -0x38) = 6;
        *(undefined4 *)(lVar2 + -0x40) = 6;
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(code **)(lVar2 + -0x10) = SerialIoAsyncCompletionRoutine;
        *(char **)(lVar2 + -8) = pcVar5;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(param_1 + 0x20),lVar4);
      }
      else {
        IoFreeIrp(lVar4);
        ExFreeToNPagedLookasideList(&AsyncIoCtxList,pcVar5);
      }
    }
  }
  return;
}



===== SetSerialTimeouts @ 1c000347c =====

void SetSerialTimeouts(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)),0);
  if (lVar3 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x38);
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0x50) = 0;
    *(undefined8 *)(lVar3 + 0x58) = 0;
    *(undefined8 *)(lVar3 + 0x60) = 0;
    *(undefined8 *)(lVar3 + 0xc0) = uVar1;
    *(undefined4 *)(lVar3 + 0x10) = 0x10;
    *(undefined8 *)(lVar2 + -0x18) = uVar1;
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x30) = 0x1b001c;
    *(undefined4 *)(lVar2 + -0x38) = 0x14;
    *(undefined4 *)(lVar2 + -0x40) = 0x14;
    pcVar4 = AsyncAllocateIoCtx('\0',param_1);
    if (pcVar4 == (char *)0x0) {
      IoFreeIrp(lVar3);
    }
    else {
      pcVar5 = pcVar4 + 0x38;
      pcVar5[0] = -1;
      pcVar5[1] = -1;
      pcVar5[2] = -1;
      pcVar5[3] = -1;
      pcVar4[0x3c] = '\0';
      pcVar4[0x3d] = '\0';
      pcVar4[0x3e] = '\0';
      pcVar4[0x3f] = '\0';
      pcVar4[0x40] = '\0';
      pcVar4[0x41] = '\0';
      pcVar4[0x42] = '\0';
      pcVar4[0x43] = '\0';
      pcVar4[0x44] = '\x04';
      pcVar4[0x45] = '\0';
      pcVar4[0x46] = '\0';
      pcVar4[0x47] = '\0';
      pcVar4[0x48] = -0x60;
      pcVar4[0x49] = '\x0f';
      pcVar4[0x4a] = '\0';
      pcVar4[0x4b] = '\0';
      *(char **)(lVar3 + 0x18) = pcVar5;
      lVar2 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar2 + -0x10) = SerialIoAsyncCompletionRoutine;
      *(char **)(lVar2 + -8) = pcVar4;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(param_1 + 0x20),lVar3);
    }
  }
  return;
}



===== AsyncAllocateIoCtx @ 1c0003574 =====

char * AsyncAllocateIoCtx(char param_1,undefined8 param_2)

{
  char *_Dst;
  
  _Dst = (char *)ExAllocateFromNPagedLookasideList(&AsyncIoCtxList);
  if (_Dst != (char *)0x0) {
    memset(_Dst,0,0x78);
    *(undefined8 *)(_Dst + 0x30) = param_2;
    *_Dst = param_1;
    if (param_1 != '\0') {
      KeInitializeEvent(_Dst + 8,1);
    }
  }
  return _Dst;
}



===== AsyncCancelAllQueued @ 1c00035f0 =====

void AsyncCancelAllQueued(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar4 = auStack_28;
  local_res8[0] = 0;
  do {
    IoAcquireCancelSpinLock(local_res8);
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
LAB_1c0003678:
      *(undefined8 *)(puVar4 + -8) = 0x1c0003683;
      IoReleaseCancelSpinLock(puVar4[0x30]);
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar4 = auStack_20;
      goto LAB_1c0003678;
    }
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    LOCK();
    plVar1[-8] = 0;
    UNLOCK();
    plVar1[-0xe] = 0;
    *(undefined1 *)((longlong)plVar1 + -100) = 1;
    *(undefined4 *)(plVar1 + -0xf) = 0xc0000120;
    IoReleaseCancelSpinLock(local_res8[0]);
    IofCompleteRequest(plVar1 + -0x15,2);
  } while( true );
}



===== AsyncCancelQueued @ 1c00036a0 =====

void AsyncCancelQueued(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  plVar1 = (longlong *)(param_2 + 0xa8);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    IoReleaseCancelSpinLock
              (CONCAT71((int7)((ulonglong)plVar3 >> 8),*(undefined1 *)(param_2 + 0x45)));
    IofCompleteRequest(param_2,2);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== AsyncCheckCommStatus @ 1c000370c =====

void AsyncCheckCommStatus(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  lVar2 = *(longlong *)(param_1 + 0x38);
  lVar4 = IoAllocateIrp(*(undefined1 *)(lVar1 + 0x4c),0);
  if (lVar4 != 0) {
    pcVar5 = AsyncAllocateIoCtx('\0',param_1);
    if (pcVar5 == (char *)0x0) {
      IoFreeIrp(lVar4);
    }
    else {
      *(undefined2 *)(lVar4 + 0x40) = 0;
      *(undefined8 *)(lVar4 + 0x50) = 0;
      *(undefined8 *)(lVar4 + 0x58) = 0;
      *(undefined8 *)(lVar4 + 0x60) = 0;
      lVar3 = *(longlong *)(lVar4 + 0xb8);
      *(longlong *)(lVar4 + 0xc0) = lVar2;
      *(undefined4 *)(lVar4 + 0x10) = 0x10;
      *(char **)(lVar4 + 0x18) = pcVar5 + 0x38;
      *(longlong *)(lVar3 + -0x18) = lVar2;
      if ((*(uint *)(lVar2 + 0x50) & 0x10) != 0) {
        *(undefined1 *)(lVar3 + -0x46) = 4;
      }
      *(undefined4 *)(lVar3 + -0x38) = 0;
      *(undefined1 *)(lVar3 + -0x48) = 0xe;
      *(undefined4 *)(lVar3 + -0x30) = 0x1b006c;
      *(undefined4 *)(lVar3 + -0x40) = 0x14;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = AsyncCheckCommStatusCompletionRoutine;
      *(char **)(lVar2 + -8) = pcVar5;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
      LOCK();
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      UNLOCK();
      IofCallDriver(lVar1,lVar4);
    }
  }
  return;
}



===== AsyncCheckCommStatusCompletionRoutine @ 1c0003820 =====

undefined8
AsyncCheckCommStatusCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  uint *puVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(param_3 + 0x30);
  if (*(int *)(param_2 + 0x30) == 0) {
    puVar2 = *(uint **)(param_2 + 0x18);
    if ((*puVar2 & 2) != 0) {
      *(int *)(lVar1 + 0x148) = *(int *)(lVar1 + 0x148) + 1;
    }
    if ((*puVar2 & 4) != 0) {
      *(int *)(lVar1 + 0x144) = *(int *)(lVar1 + 0x144) + 1;
    }
    if ((*puVar2 & 8) != 0) {
      *(int *)(lVar1 + 0x14c) = *(int *)(lVar1 + 0x14c) + 1;
    }
    AsyncIndicateFragment(lVar1,*puVar2);
  }
  IoFreeIrp(param_2);
  ExFreeToNPagedLookasideList(&AsyncIoCtxList,param_3);
  *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) & 0xfffffffd;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x180);
  *(undefined1 *)(lVar1 + 0x188) = uVar3;
  LOCK();
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + -1;
  UNLOCK();
  if (*(int *)(lVar1 + 0x10) == 0) {
    KeSetEvent(lVar1 + 0x70,1);
  }
  KeReleaseSpinLock(lVar1 + 0x180,*(undefined1 *)(lVar1 + 0x188));
  return 0xc0000016;
}



===== AssemblePPPFrame @ 1c0003908 =====

undefined8
AssemblePPPFrame(longlong param_1,byte *param_2,int param_3,undefined1 *param_4,uint *param_5)

{
  undefined8 uVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  longlong lVar6;
  byte local_18;
  undefined1 local_17;
  
  if (*param_5 < param_3 * 2 + 6U) {
    *param_5 = 0;
    uVar1 = 0xc0000001;
  }
  else {
    uVar2 = 0xffff;
    pbVar5 = param_2;
    for (iVar4 = param_3; iVar4 != 0; iVar4 = iVar4 + -1) {
      bVar3 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      uVar2 = uVar2 >> 8 ^ *(ushort *)(&DAT_1c00071e0 + (ulonglong)(byte)(bVar3 ^ (byte)uVar2) * 2);
    }
    *param_4 = 0x7e;
    local_18 = (byte)~uVar2;
    lVar6 = 2;
    local_17 = (char)((ushort)~uVar2 >> 8);
    pbVar5 = param_4 + 1;
    do {
      if (*(int *)(param_1 + 0x15c) == 0) {
        while (param_3 != 0) {
          bVar3 = *param_2;
          param_3 = param_3 + -1;
          param_2 = param_2 + 1;
          if ((byte)(bVar3 + 0x83) < 2) {
            *pbVar5 = 0x7d;
            pbVar5 = pbVar5 + 1;
            bVar3 = bVar3 ^ 0x20;
          }
          *pbVar5 = bVar3;
          pbVar5 = pbVar5 + 1;
        }
      }
      else {
        while (param_3 != 0) {
          bVar3 = *param_2;
          param_3 = param_3 + -1;
          param_2 = param_2 + 1;
          if ((*(uint *)(param_1 + 0x15c + (ulonglong)(bVar3 >> 5) * 4) >> (bVar3 & 0x1f) & 1) != 0)
          {
            *pbVar5 = 0x7d;
            pbVar5 = pbVar5 + 1;
            bVar3 = bVar3 ^ 0x20;
          }
          *pbVar5 = bVar3;
          pbVar5 = pbVar5 + 1;
        }
      }
      param_3 = 2;
      lVar6 = lVar6 + -1;
      param_2 = &local_18;
    } while (lVar6 != 0);
    *pbVar5 = 0x7e;
    *param_5 = ((int)pbVar5 - (int)param_4) + 1;
    uVar1 = 0;
  }
  return uVar1;
}



===== AsyncPPPCompletionRoutine @ 1c0003a30 =====

undefined8 AsyncPPPCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  byte *_Dst;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *_Src;
  
  iVar5 = *(int *)(param_2 + 0x30);
  iVar2 = *(int *)(param_2 + 0x38);
  IoFreeIrp(param_2);
  if (iVar5 == -0x3ffffee0) {
    *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xffffffbf;
LAB_1c0003c57:
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x180);
    *(undefined1 *)(param_3 + 0x188) = uVar4;
    LOCK();
    *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + -1;
    UNLOCK();
    if (*(int *)(param_3 + 0x10) == 0) {
      KeSetEvent(param_3 + 0x70,1);
    }
    KeReleaseSpinLock(param_3 + 0x180,*(undefined1 *)(param_3 + 0x188));
LAB_1c0003ca9:
    if (*(int *)(param_3 + 0x28) - 2U < 2) {
      KeSetEvent(param_3 + 0x40,1);
    }
  }
  else {
    if (iVar5 == 0) {
      lVar3 = *(longlong *)(param_3 + 0x108);
      if (iVar2 != 0) {
        uVar9 = iVar2 + *(int *)(param_3 + 0x134);
        *(uint *)(param_3 + 0x134) = uVar9;
        _Dst = (byte *)(*(longlong *)(lVar3 + 8) + 0x80);
        do {
          if (*_Dst == 0x7e) {
            do {
              uVar9 = uVar9 - 1;
              if (uVar9 == 0) goto LAB_1c0003bf3;
              _Dst = _Dst + 1;
            } while (*_Dst == 0x7e);
          }
          else if (uVar9 == 0) break;
          bVar1 = *_Dst;
          _Src = _Dst;
          while (bVar1 != 0x7e) {
            uVar9 = uVar9 - 1;
            if (uVar9 == 0) goto LAB_1c0003bf3;
            _Src = _Src + 1;
            bVar1 = *_Src;
          }
          if (*(char *)(*(longlong *)(lVar3 + 8) + 0x80) == '~') {
            iVar5 = (int)_Src - (int)_Dst;
            pbVar11 = _Dst;
            pbVar10 = _Dst;
            while (0 < iVar5) {
              bVar1 = *pbVar11;
              pbVar8 = pbVar11 + 1;
              *pbVar10 = bVar1;
              iVar2 = iVar5 + -1;
              if (bVar1 == 0x7d) {
                *pbVar10 = *pbVar8 ^ 0x20;
                pbVar8 = pbVar11 + 2;
                iVar2 = iVar5 + -2;
              }
              iVar5 = iVar2;
              pbVar10 = pbVar10 + 1;
              pbVar11 = pbVar8;
            }
            iVar5 = (int)(pbVar10 + -2) - (int)_Dst;
            if (iVar5 < 3) goto LAB_1c0003b06;
            uVar6 = 0xffff;
            pbVar11 = _Dst;
            iVar2 = iVar5;
            do {
              iVar7 = iVar2;
              bVar1 = *pbVar11;
              pbVar11 = pbVar11 + 1;
              uVar6 = uVar6 >> 8 ^
                      *(ushort *)(&DAT_1c00071e0 + (ulonglong)(byte)(bVar1 ^ (byte)uVar6) * 2);
              iVar2 = iVar7 + -1;
            } while (iVar7 + -1 != 0);
            if ((ushort)~*(ushort *)(pbVar10 + -2) != uVar6) {
              *(int *)(param_3 + 0x138) = *(int *)(param_3 + 0x138) + 1;
              goto LAB_1c0003b14;
            }
            IndicatePacketToNdis(param_3,_Dst,iVar5);
          }
          else {
LAB_1c0003b06:
            *(int *)(param_3 + 0x140) = *(int *)(param_3 + 0x140) + 1;
            iVar7 = 0x20;
LAB_1c0003b14:
            AsyncIndicateFragment(param_3,iVar7);
          }
          _Dst = (byte *)(*(longlong *)(lVar3 + 8) + 0x80);
          uVar9 = (*(int *)(param_3 + 0x134) - (int)_Src) + (int)_Dst;
          *(uint *)(param_3 + 0x134) = uVar9;
          memcpy(_Dst,_Src,(ulonglong)uVar9);
        } while (3 < uVar9);
      }
LAB_1c0003bf3:
      AsyncPPPWaitMask(param_3);
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xffffffbf;
    }
    else {
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xffffffbf;
      if (iVar5 == 0x103) {
        if (param_3 != 0) goto LAB_1c0003c57;
        goto LAB_1c0003ca9;
      }
      if (param_3 == 0) {
        return 0xc0000016;
      }
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x180);
    *(undefined1 *)(param_3 + 0x188) = uVar4;
    LOCK();
    *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + -1;
    UNLOCK();
    if (*(int *)(param_3 + 0x10) == 0) {
      KeSetEvent(param_3 + 0x70,1);
    }
    KeReleaseSpinLock(param_3 + 0x180,*(undefined1 *)(param_3 + 0x188));
  }
  return 0xc0000016;
}



===== AsyncPPPRead @ 1c0003d00 =====

undefined8 AsyncPPPRead(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  lVar3 = *(longlong *)(param_1 + 0x38);
  lVar4 = *(longlong *)(param_1 + 0x108);
  if (*(int *)(param_1 + 0x28) - 2U < 2) {
    KeSetEvent(param_1 + 0x40,1);
    uVar7 = 0xc0000016;
  }
  else if (*(uint *)(param_1 + 0x158) < 2) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) + 1;
    lVar8 = IoAllocateIrp(*(undefined1 *)(lVar2 + 0x4c),0);
    if (lVar8 == 0) {
      uVar7 = 0xc000009a;
    }
    else {
      lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x38) + 0x20);
      uVar7 = *(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 0x38);
      *(undefined2 *)(lVar8 + 0x40) = 0;
      *(undefined8 *)(lVar8 + 0x50) = 0;
      *(undefined8 *)(lVar8 + 0x58) = 0;
      *(undefined8 *)(lVar8 + 0x60) = 0;
      *(undefined8 *)(lVar8 + 0xc0) = uVar7;
      uVar6 = *(uint *)(lVar5 + 0x30);
      if ((uVar6 & 4) == 0) {
        if ((uVar6 & 0x10) == 0) {
          *(undefined8 *)(lVar8 + 0x70) = *(undefined8 *)(lVar4 + 8);
        }
      }
      else {
        *(undefined8 *)(lVar8 + 0x18) = *(undefined8 *)(lVar4 + 8);
        *(undefined4 *)(lVar8 + 0x10) = 0x10;
      }
      uVar6 = *(uint *)(param_1 + 0x134);
      if (0xc29 < uVar6) {
        *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
        AsyncIndicateFragment(param_1,8);
        *(undefined4 *)(param_1 + 0x134) = 0;
        uVar6 = 0;
      }
      lVar5 = *(longlong *)(lVar8 + 0xb8);
      *(ulonglong *)(lVar8 + 0x18) = (ulonglong)uVar6 + *(longlong *)(lVar4 + 8) + 0x80;
      *(undefined1 *)(lVar5 + -0x48) = 3;
      *(longlong *)(lVar5 + -0x18) = lVar3;
      if ((*(uint *)(lVar3 + 0x50) & 0x10) != 0) {
        *(undefined1 *)(lVar5 + -0x46) = 4;
      }
      uVar6 = *(uint *)(lVar8 + 0x10);
      *(uint *)(lVar8 + 0x10) = uVar6 | 0x100;
      if ((*(uint *)(lVar3 + 0x50) & 8) != 0) {
        *(uint *)(lVar8 + 0x10) = uVar6 | 0x101;
      }
      iVar1 = *(int *)(param_1 + 0x134);
      *(undefined4 *)(lVar5 + -0x38) = 0;
      *(int *)(lVar5 + -0x40) = 0xc2a - iVar1;
      *(undefined8 *)(lVar5 + -0x30) = *(undefined8 *)(lVar3 + 0x68);
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40;
      LOCK();
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      UNLOCK();
      lVar3 = *(longlong *)(lVar8 + 0xb8);
      *(code **)(lVar3 + -0x10) = AsyncPPPCompletionRoutine;
      *(longlong *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar7 = IofCallDriver(lVar2,lVar8);
      if (*(int *)(param_1 + 0x158) != 0) {
        *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + -1;
      }
    }
  }
  else {
    *(undefined8 *)(lVar4 + 0x10) = 0;
    *(code **)(lVar4 + 0x20) = AsyncPPPRead;
    *(longlong *)(lVar4 + 0x28) = param_1;
    *(undefined4 *)(param_1 + 0x158) = 0;
    ExQueueWorkItem((undefined8 *)(lVar4 + 0x10),1);
    uVar7 = 0x103;
  }
  return uVar7;
}



===== AsyncPPPWaitMask @ 1c0003f04 =====

undefined8 AsyncPPPWaitMask(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0x108);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)),0);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x38);
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 0xc0) = uVar1;
    *(undefined2 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0x50) = 0;
    *(undefined8 *)(lVar3 + 0x58) = 0;
    *(undefined8 *)(lVar3 + 0x60) = 0;
    *(undefined4 *)(lVar3 + 0x10) = 0x10;
    *(undefined8 *)(lVar2 + -0x18) = uVar1;
    *(undefined4 *)(lVar2 + -0x38) = 4;
    *(undefined4 *)(lVar2 + -0x40) = 4;
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x30) = 0x1b0048;
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 0x18) = uVar4;
    *(code **)(lVar2 + -0x10) = AsyncWaitMaskCompletionRoutine;
    *(longlong *)(lVar2 + -8) = param_1;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80;
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
    uVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0x20));
  }
  return uVar4;
}



===== AsyncWaitMaskCompletionRoutine @ 1c0003fd0 =====

undefined8 AsyncWaitMaskCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  int iVar2;
  uint *puVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 local_res10 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  iVar2 = *(int *)(param_2 + 0x30);
  puVar3 = *(uint **)(param_3 + 0x108);
  IoFreeIrp(param_2);
  if (*(int *)(param_3 + 0x28) - 2U < 2) {
    KeSetEvent(param_3 + 0x40,1);
    puVar8 = auStack_28;
    goto LAB_1c00040ed;
  }
  if (iVar2 != 0) {
    *(undefined4 *)(param_3 + 0x28) = 5;
    puVar8 = auStack_28;
    goto LAB_1c00040ed;
  }
  if ((char)*puVar3 < '\0') {
    AsyncCheckCommStatus(param_3);
  }
  if ((*puVar3 & 0x30) == 0) {
LAB_1c0004066:
    puVar8 = auStack_28;
    lVar7 = param_3;
    if ((*puVar3 & 0x402) != 0) {
      AsyncPPPRead(param_3);
      puVar8 = auStack_28;
      goto LAB_1c00040ed;
    }
  }
  else {
    local_res10[0] = 0;
    IoAcquireCancelSpinLock(local_res10);
    plVar1 = (longlong *)(param_3 + 0xa0);
    plVar4 = (longlong *)*plVar1;
    if (plVar4 == plVar1) {
      IoReleaseCancelSpinLock(local_res10[0]);
      goto LAB_1c0004066;
    }
    if (((longlong *)plVar4[1] == plVar1) &&
       (lVar7 = *plVar4, (longlong *)*(longlong *)(lVar7 + 8) == plVar4)) {
      *plVar1 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar1;
      LOCK();
      plVar4[-8] = 0;
      UNLOCK();
      *(undefined4 *)(plVar4 + -0xf) = 0;
      plVar4[-0xe] = 0;
      IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)lVar7 >> 8),local_res10[0]));
      IofCompleteRequest(plVar4 + -0x15,2);
      goto LAB_1c0004066;
    }
    lVar7 = 3;
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)();
    puVar8 = auStack_20;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1c00040d4;
  AsyncPPPWaitMask(lVar7);
LAB_1c00040ed:
  *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xffffff7f;
  *(undefined8 *)(puVar8 + -8) = 0x1c0004103;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x180);
  *(undefined1 *)(param_3 + 0x188) = uVar6;
  LOCK();
  *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + -1;
  UNLOCK();
  if (*(int *)(param_3 + 0x10) == 0) {
    *(undefined8 *)(puVar8 + -8) = 0x1c000412a;
    KeSetEvent(param_3 + 0x70,1);
  }
  uVar6 = *(undefined1 *)(param_3 + 0x188);
  *(undefined8 *)(puVar8 + -8) = 0x1c000413f;
  KeReleaseSpinLock(param_3 + 0x180,uVar6);
  return 0xc0000016;
}



===== IndicatePacketToNdis @ 1c0004164 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IndicatePacketToNdis(longlong param_1,void *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  void *_Dst;
  ulonglong uVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  lVar5 = lVar3 + 0x38;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar5);
  *(undefined1 *)(lVar3 + 0x40) = uVar4;
  if (*(int *)(lVar3 + 0x10) == 1) {
    piVar1 = (int *)(lVar3 + 0x18);
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    KeReleaseSpinLock(lVar5,*(undefined1 *)(lVar3 + 0x40));
    lVar5 = NdisAllocateNetBufferList(*(undefined8 *)(lVar3 + 0x78),0,0);
    if (lVar5 == 0) {
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(lVar3 + 0x20))(piVar1);
      }
    }
    else {
      uVar6 = 0;
      NdisRetreatNetBufferListDataStart(lVar5,*(int *)(lVar3 + 0x1c0) + -0x14,0,0,0);
      _Dst = (void *)NdisGetDataBuffer(*(undefined8 *)(lVar5 + 8),param_3,0,1,
                                       uVar6 & 0xffffffff00000000);
      memcpy(_Dst,param_2,(longlong)param_3);
      *(int *)(*(longlong *)(lVar5 + 8) + 0x18) = param_3;
      *(undefined8 *)(lVar5 + 0x78) = *(undefined8 *)(param_1 + 0x98);
      uVar4 = KfRaiseIrql(2);
      NdisMCoIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x98),lVar5,1);
      KeLowerIrql(uVar4);
    }
  }
  else {
    KeReleaseSpinLock(lVar5,uVar4);
  }
  return;
}



===== _guard_check_icall @ 1c00042d0 =====

void _guard_check_icall(void)

{
  return;
}



===== AsyncMpCoRequest @ 1c00042e0 =====

ulonglong AsyncMpCoRequest(int *param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      uVar3 = MpSetInfo(param_1,(longlong)param_2,param_3);
      return uVar3;
    }
    if (iVar1 != 2) {
      return 0xc00000bb;
    }
  }
  uVar2 = MpQueryInfo(param_1,param_2,param_3);
  return CONCAT44(extraout_var,uVar2);
}



===== AsyncMpHaltEx @ 1c0004320 =====

void AsyncMpHaltEx(longlong param_1)

{
  DAT_1c0008238 = KeAcquireSpinLockRaiseToDpc(&GlobalLock);
  GlobalAdapterCount = GlobalAdapterCount + -1;
  GlobalAdapter = 0;
  KeReleaseSpinLock(&GlobalLock,DAT_1c0008238);
  ExDeleteNPagedLookasideList(param_1 + 0xc0);
  ExDeleteNPagedLookasideList(param_1 + 0x140);
  NdisFreeNetBufferListPool(*(undefined8 *)(param_1 + 0x78));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== AsyncMpInitializeEx @ 1c00043c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AsyncMpInitializeEx(undefined8 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  short sVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 auStack_298 [32];
  ulonglong local_278;
  undefined4 local_270;
  undefined2 local_268;
  int local_258 [2];
  longlong local_250;
  undefined8 local_248;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined8 local_230;
  wchar_t *local_228;
  undefined8 local_220;
  wchar_t *local_218;
  undefined8 local_210;
  wchar_t *local_208;
  undefined8 local_200;
  wchar_t *local_1f8;
  undefined8 local_1f0;
  wchar_t *local_1e8;
  undefined8 local_1e0;
  wchar_t *local_1d8;
  undefined8 local_1d0;
  wchar_t *local_1c8;
  undefined8 local_1c0;
  wchar_t *local_1b8;
  undefined8 local_1b0;
  wchar_t *local_1a8;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 *local_198;
  undefined8 local_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined8 local_178;
  undefined8 local_170;
  undefined4 local_168 [2];
  undefined8 local_160;
  undefined4 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 local_118;
  undefined4 local_114;
  undefined2 local_10c;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined1 local_b2;
  undefined4 local_ac;
  undefined *local_a0;
  undefined4 local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_298;
  local_19c = 0;
  local_184 = 0;
  memset(local_168,0,0xe0);
  local_17c = 0;
  local_48 = 0;
  uVar7 = 500;
  local_40 = 0;
  uVar5 = 5;
  local_170 = 0;
  local_228 = L"IrpStackSize";
  iVar9 = 0x5ea;
  local_248 = 0;
  local_218 = L"MaxFrameSize";
  uVar8 = 0x7080;
  local_250 = 0;
  local_208 = L"FramesPerPort";
  local_1f8 = L"XonXoff";
  local_1e8 = L"TimeoutBase";
  local_1d8 = L"TimeoutBaud";
  local_1c8 = L"TimeoutReSync";
  local_1b8 = L"WriteBufferingEnabled";
  local_1a8 = L"ExtendedXonXoffEnabled";
  sVar4 = 1;
  local_23c = 1;
  local_238 = 1;
  local_78 = 0;
  uStack_70 = 0;
  local_230 = 0x1a0018;
  local_68 = 0;
  uStack_60 = 0;
  local_220 = 0x1a0018;
  local_58 = 0;
  uStack_50 = 0;
  local_210 = 0x1c001a;
  local_200 = 0x10000e;
  local_1f0 = 0x180016;
  local_1e0 = 0x180016;
  local_1d0 = 0x1c001a;
  local_1c0 = 0x2c002a;
  local_1b0 = 0x2e002c;
  local_234 = 0;
  local_240 = 500;
  if (GlobalAdapterCount == 0) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x200,0x33797341);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xc000009a;
    }
    *(undefined8 *)(puVar2 + 0x1c) = param_1;
    local_180 = 0x1801a9;
    local_178 = param_1;
    local_258[0] = NdisOpenConfigurationEx(&local_180,&local_248);
    if (local_258[0] == 0) {
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_230);
      if (local_258[0] == 0) {
        uVar5 = *(undefined1 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_220);
      if (local_258[0] == 0) {
        iVar9 = *(int *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_210);
      if (local_258[0] == 0) {
        sVar4 = *(short *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_200);
      if (local_258[0] == 0) {
        local_234 = *(undefined4 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_1f0);
      if (local_258[0] == 0) {
        uVar7 = *(undefined4 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_1e0);
      if (local_258[0] == 0) {
        uVar8 = *(undefined4 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_1d0);
      if (local_258[0] == 0) {
        local_240 = *(undefined4 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_1c0);
      if (local_258[0] == 0) {
        local_23c = *(undefined4 *)(local_250 + 8);
      }
      local_278 = local_278 & 0xffffffff00000000;
      NdisReadConfiguration(local_258,&local_250,local_248,&local_1b0);
      if (local_258[0] == 0) {
        local_238 = *(undefined4 *)(local_250 + 8);
      }
      NdisCloseConfiguration(local_248);
      KeInitializeSpinLock(puVar2 + 0xe);
      *(undefined1 *)(puVar2 + 0x20) = uVar5;
      puVar2[0x21] = iVar9 * 2 + 0xe4;
      if (sVar4 == 0) {
        sVar4 = 1;
      }
      puVar2[0x25] = local_240;
      puVar2[0x26] = local_23c;
      puVar1 = puVar2 + 10;
      *(undefined4 **)(puVar2 + 0xc) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      puVar2[0x23] = uVar7;
      puVar2[0x27] = local_238;
      *(short *)((longlong)puVar2 + 0x8a) = sVar4;
      puVar2[0x24] = uVar8;
      local_1a0 = 0x20019e;
      local_190 = 0x30;
      local_188 = 0;
      local_198 = puVar2;
      local_258[0] = NdisMSetMiniportAttributes(param_1,&local_1a0);
      if (local_258[0] == 0) {
        local_168[0] = 0xe0029f;
        local_160 = 0xc;
        local_158 = puVar2[0x21];
        local_150 = 0xffffffffffffffff;
        local_140 = 0xffffffffffffffff;
        local_148 = 0xffffffffffffffff;
        local_138 = 0xffffffffffffffff;
        local_130 = 0;
        local_128 = puVar2[0x21];
        local_90 = &local_78;
        local_b4 = 0x17;
        local_a0 = &AsyncGlobalSupportedOids;
        local_78 = CONCAT44(local_78._4_4_,0x3c0280);
        uStack_50 = 0;
        local_118 = 5;
        local_114 = 1;
        local_10c = 0;
        local_c8 = 0;
        local_c0 = 3;
        local_b8 = 1;
        local_b2 = 0;
        local_ac = 0;
        local_98 = 0x94;
        local_258[0] = NdisMSetMiniportAttributes(param_1,local_168);
        if (local_258[0] == 0) {
          local_88 = 0x600000800;
          _uStack_80 = CONCAT44(uStack_7c,0x1e);
          local_258[0] = NdisMCmRegisterAddressFamilyEx(param_1,&local_88);
          if (local_258[0] == 0) {
            *(code **)(puVar2 + 0x14) = DoDerefAfSapCBWork;
            local_268 = 0;
            local_270 = 0x34797341;
            puVar2[0x12] = 0;
            uVar6 = (ulonglong)(uint)puVar2[0x21];
            if ((uint)puVar2[0x21] < 0xcaa) {
              uVar6 = 0xcaa;
            }
            local_278 = uVar6 + 0x58;
            ExInitializeNPagedLookasideList(puVar2 + 0x30,0,0,0x200);
            local_268 = 0;
            local_270 = 0x36797341;
            local_278 = uVar6;
            ExInitializeNPagedLookasideList(puVar2 + 0x50,0,0,0x200);
            puVar2[0x70] = (int)uVar6;
            local_88 = 0x10000100180;
            _uStack_80 = CONCAT44((int)uVar6,0x38797341);
            lVar3 = NdisAllocateNetBufferListPool(param_1,&local_88);
            *(longlong *)(puVar2 + 0x1e) = lVar3;
            if (lVar3 != 0) {
              DAT_1c0008238 = KeAcquireSpinLockRaiseToDpc(&GlobalLock);
              GlobalAdapterCount = GlobalAdapterCount + 1;
              GlobalAdapter = puVar2;
              KeReleaseSpinLock(&GlobalLock,DAT_1c0008238);
              puVar2[3] = local_234;
              *puVar2 = 0x5dc;
              puVar2[1] = 2;
              puVar2[2] = 0x7f00;
              puVar2[4] = 0;
              return 0;
            }
          }
        }
      }
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return 0xc0000001;
}



===== AsyncMpPause @ 1c0004ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AsyncMpPause(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x10) = 2;
  *(undefined1 *)(param_1 + 0x40) = uVar3;
  KeReleaseSpinLock(param_1 + 0x38,uVar3);
  piVar1 = (int *)(param_1 + 0x18);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x20))();
  }
  return 0x103;
}



===== AsyncMpRestart @ 1c0004b40 =====

undefined8 AsyncMpRestart(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
  *(undefined1 *)(param_1 + 0x40) = uVar1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(code **)(param_1 + 0x20) = DoDerefAdapterDataBlockWork;
  *(undefined4 *)(param_1 + 0x10) = 1;
  LOCK();
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  UNLOCK();
  KeReleaseSpinLock(param_1 + 0x38,*(undefined1 *)(param_1 + 0x40));
  return 0;
}



===== AsyncMpReturnNetBufferListChain @ 1c0004bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AsyncMpReturnNetBufferListChain(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if (param_2 != (undefined8 *)0x0) {
    piVar1 = (int *)(param_1 + 0x18);
    do {
      puVar3 = (undefined8 *)*param_2;
      *param_2 = 0;
      NdisFreeNetBufferList();
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x20))(piVar1);
      }
      param_2 = puVar3;
    } while (puVar3 != (undefined8 *)0x0);
  }
  return;
}



===== AsyncMpSetOptions @ 1c0004c10 =====

void AsyncMpSetOptions(undefined8 param_1)

{
  int iVar1;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  code *local_b0;
  code *local_a8;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  code *local_10;
  
  local_d4 = 0;
  local_d8 = 0x380191;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_94 = 0;
  local_b0 = AsyncMpCoSendNetBufferListChain;
  local_a8 = AsyncMpCoRequest;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = NdisSetOptionalHandlers(0,&local_d8);
  if (-1 < iVar1) {
    local_98 = 0x9001a5;
    local_90 = AsyncCmCreateVc;
    local_88 = AsyncCmCreateVc;
    local_80 = AsyncCmOpenAf;
    local_78 = AsyncCmCloseAf;
    local_70 = AsyncCmRegisterSap;
    local_68 = AsyncCmDeregisterSap;
    local_60 = AsyncCmModifyCallQoS;
    local_58 = AsyncCmCloseCall;
    local_50 = AsyncCmIncomingCallComplete;
    local_38 = _guard_check_icall;
    local_30 = _guard_check_icall;
    local_28 = AsyncCmModifyCallQoS;
    local_20 = AsyncCmModifyCallQoS;
    local_18 = _guard_check_icall;
    local_10 = _guard_check_icall;
    NdisSetOptionalHandlers(param_1,&local_98);
  }
  return;
}



===== DoDerefAdapterDataBlockWork @ 1c0004d60 =====

void DoDerefAdapterDataBlockWork(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
  *(undefined4 *)(param_1 + -8) = 0;
  *(undefined1 *)(param_1 + 0x28) = uVar1;
  KeReleaseSpinLock(param_1 + 0x20,uVar1);
  NdisMPauseComplete(*(undefined8 *)(param_1 + 0x58));
  return;
}



===== AsyncCmCloseAf @ 1c0004dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AsyncCmCloseAf(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0x103;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
  *(undefined1 *)(param_1 + 0x40) = uVar3;
  if ((*(uint *)(param_1 + 0x58) & 1) == 0) {
    KeReleaseSpinLock();
    uVar4 = 0xc0000001;
  }
  else {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffffffe | 2;
    KeReleaseSpinLock(param_1 + 0x38);
    piVar1 = (int *)(param_1 + 0x48);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_1 + 0x50))();
    }
  }
  return uVar4;
}



===== AsyncCmCloseCall @ 1c0004e60 =====

undefined8 AsyncCmCloseCall(longlong param_1)

{
  NdisSetEvent(param_1 + 200);
  return 0;
}



===== AsyncCmCreateVc @ 1c0004e90 =====

undefined8 AsyncCmCreateVc(void)

{
  return 0xc0000001;
}



===== AsyncCmDeregisterSap @ 1c0004ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AsyncCmDeregisterSap(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  lVar1 = param_1 + 0x38;
  uVar5 = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x40) = uVar4;
  if ((*(uint *)(param_1 + 0x58) & 8) == 0) {
    KeReleaseSpinLock(lVar1);
    uVar5 = 0xc0000001;
  }
  else {
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffffff7;
    KeReleaseSpinLock(lVar1);
    piVar2 = (int *)(param_1 + 0x48);
    LOCK();
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (**(code **)(param_1 + 0x50))();
    }
  }
  return uVar5;
}



===== AsyncCmIncomingCallComplete @ 1c0004f40 =====

void AsyncCmIncomingCallComplete(undefined4 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0xe0) = param_1;
  NdisSetEvent(param_2 + 0xb0);
  return;
}



===== AsyncCmModifyCallQoS @ 1c0004f70 =====

undefined8 AsyncCmModifyCallQoS(void)

{
  return 0;
}



===== AsyncCmOpenAf @ 1c0004f80 =====

undefined8 AsyncCmOpenAf(longlong param_1,int *param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  *param_4 = 0;
  if (*param_2 == 0x800) {
    lVar1 = param_1 + 0x38;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x40) = uVar2;
    if ((*(uint *)(param_1 + 0x58) & 3) == 0) {
      *(undefined8 *)(param_1 + 0x68) = param_3;
      LOCK();
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      UNLOCK();
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 1;
      KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x40));
      *param_4 = param_1;
    }
    else {
      KeReleaseSpinLock(lVar1,uVar2);
      uVar3 = 0xc0000001;
    }
  }
  else {
    uVar3 = 0xc0010004;
  }
  return uVar3;
}



===== AsyncCmRegisterSap @ 1c0005030 =====

undefined8
AsyncCmRegisterSap(longlong param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  lVar1 = param_1 + 0x38;
  uVar3 = 0;
  *param_4 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x40) = uVar2;
  if (((byte)*(undefined4 *)(param_1 + 0x58) & 9) == 1) {
    *(undefined8 *)(param_1 + 0x60) = param_3;
    LOCK();
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    UNLOCK();
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x40));
    *param_4 = param_1;
  }
  else {
    KeReleaseSpinLock(lVar1,uVar2);
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== DoDerefAfSapCBWork @ 1c00050d0 =====

void DoDerefAfSapCBWork(longlong param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + -0x10);
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  uVar3 = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(uint *)(param_1 + 0x10) = uVar3 | 4;
  *(undefined1 *)(param_1 + -8) = uVar2;
  KeReleaseSpinLock(param_1 + -0x10,CONCAT31((int3)(uVar3 >> 8),uVar2));
  NdisCmCloseAddressFamilyComplete(0,uVar1);
  return;
}



===== __GSHandlerCheck @ 1c0005148 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000516c =====

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



===== __cpu_features_init @ 1c00051e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000524a) */
/* WARNING: Removing unreachable block (ram,0x0001c00051f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00051ea) */

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



===== __security_check_cookie @ 1c00052b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00052f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0005320 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0005320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0005350 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00053c0 =====

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



===== memset @ 1c00056c0 =====

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



===== __memset_repmovs @ 1c0005800 =====

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



===== __memset_query @ 1c0005880 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005900 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005a40 =====

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



===== __memset_spec_plain @ 1c0005ac0 =====

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



===== entry @ 1c000b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  uint3 uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  char cVar10;
  byte *pbVar7;
  undefined7 uVar11;
  char *pcVar8;
  int *piVar9;
  char cVar12;
  byte in_DL;
  byte in_DH;
  undefined6 in_register_00000012;
  byte *unaff_RBX;
  char *unaff_RSI;
  char *in_R8;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    cVar12 = '\x06';
    pcVar1 = (code *)swi(0x29);
    pbVar7 = (byte *)(*pcVar1)();
    bVar3 = (byte)pbVar7;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3;
    bVar5 = *pbVar7;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + in_DL + CARRY1(bVar5,bVar3);
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 & in_DL;
    bVar5 = *pbVar7;
    *pbVar7 = *pbVar7 + bVar3;
    *pbVar7 = *pbVar7 + bVar3 + CARRY1(bVar5,bVar3);
    bVar5 = *pbVar7;
    *pbVar7 = *pbVar7 + in_DH;
    *(uint *)pbVar7 = *(int *)pbVar7 + (int)pbVar7 + (uint)CARRY1(bVar5,in_DH);
    pbVar7[0x11] = pbVar7[0x11] + in_DH;
    bVar5 = *pbVar7;
    *pbVar7 = *pbVar7 + bVar3;
    *unaff_RSI = *unaff_RSI + CARRY1(bVar5,bVar3);
    uVar11 = (undefined7)((ulonglong)pbVar7 >> 8);
    cVar4 = bVar3 + in_DH;
    pcVar8 = (char *)CONCAT71(uVar11,cVar4);
    *pcVar8 = *pcVar8 - cVar4;
    piVar9 = (int *)CONCAT71(uVar11,cVar4 + in_DH);
    uVar6 = (int)piVar9 - *piVar9;
    pbVar7 = (byte *)(ulonglong)uVar6;
    cVar10 = (char)(uVar6 >> 8);
    *pbVar7 = *pbVar7 + cVar10;
    uVar2 = (uint3)(uVar6 >> 8);
    bVar5 = (byte)uVar6 ^ *pbVar7;
    pcVar8 = (char *)(ulonglong)CONCAT31(uVar2,bVar5);
    pcVar8[0x32] = pcVar8[0x32] + cVar10;
    *pcVar8 = *pcVar8 + bVar5;
    cVar4 = cRam3000003820000036;
    pcVar8 = (char *)(ulonglong)CONCAT31(uVar2,cRam3000003820000036);
    *pcVar8 = *pcVar8 + cRam3000003820000036;
    *pcVar8 = *pcVar8 + cVar4;
    *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) << 1 |
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) < '\0';
    bVar5 = cVar4 + cVar10;
    *(char *)(ulonglong)CONCAT31(uVar2,bVar5) = *(char *)(ulonglong)CONCAT31(uVar2,bVar5) + bVar5;
    *unaff_RBX = *unaff_RBX & bVar5;
    cVar4 = bVar5 * '\x02';
    pcVar8 = (char *)(ulonglong)CONCAT31(uVar2,cVar4);
    *in_R8 = *in_R8 + cVar4;
    *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
         *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) >> 1 |
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) << 7;
    pcVar8[0x4b] = pcVar8[0x4b] + cVar4;
    *pcVar8 = *pcVar8 + cVar4;
    pbVar7 = (byte *)CONCAT71((uint7)uVar2,0x4b);
    bVar5 = *pbVar7;
    *pbVar7 = *pbVar7 + 0x4b;
    *(char *)((longlong)pbVar7 * 2) = *(char *)((longlong)pbVar7 * 2) + cVar12 + (0xb4 < bVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


