
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



===== CreateNetworkAdapter @ 1c0001020 =====

undefined8 CreateNetworkAdapter(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
                    /* 0x1020  1  CreateNetworkAdapter */
  KdNetNicInterface = param_1;
  if ((DAT_1c0006200 & 8) == 0) {
    ExSetTimerResolution(22000,1);
    DAT_1c0006200 = DAT_1c0006200 | 8;
  }
  if ((DAT_1c0006200 & 2) == 0) {
    uVar1 = NdisGetVersion();
    ExInitializeNPagedLookasideList
              (&DAT_1c0006180,HWFrameAllocate,HWFrameFree,~-(uint)(uVar1 < 0x6001e) & 0x200,0x600,
               0x464e444b,0);
    DAT_1c0006200 = DAT_1c0006200 | 2;
  }
  local_a8 = 0x98028a;
  local_a0 = 0;
  local_a4 = 0x2041406;
  local_98 = MPSetOptions;
  local_90 = MPInitializeEx;
  local_88 = MPHaltEx;
  local_80 = DriverUnload;
  local_78 = MPPause;
  local_70 = MPRestart;
  local_68 = MPOidRequest;
  local_60 = MPSendNetBufferLists;
  local_58 = MPReturnNetBufferLists;
  local_50 = _guard_check_icall;
  local_48 = MPCheckForHangEx;
  local_40 = MPResetEx;
  local_38 = MPDevicePnpEventNotify;
  local_30 = _guard_check_icall;
  local_28 = _guard_check_icall;
  local_20 = 0;
  uStack_18 = 0;
  uVar2 = NdisMRegisterMiniportDriver
                    (KdNicDriverObject,KdNicRegistryPath,&GlobalData,&local_a8,&NdisDriverHandle);
  if (((int)uVar2 == 0) &&
     (uVar3 = DAT_1c0006200 | 4, uVar1 = DAT_1c0006200 & 1, DAT_1c0006200 = uVar3, uVar1 == 0)) {
    DAT_1c0006150 = NdisAllocateRWLock(NdisDriverHandle);
    if (DAT_1c0006150 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      DAT_1c0006200 = DAT_1c0006200 | 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== FreeAdapterListLock @ 1c0001238 =====

void FreeAdapterListLock(void)

{
  NdisFreeRWLock(DAT_1c0006150);
  DAT_1c0006150 = 0;
  return;
}



===== GetSystemTimerResolution @ 1c0001264 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetSystemTimerResolution(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  uint local_res8 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  uint *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  
  if (param_1 == (uint *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_78 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_68 = L"TimerResolution";
    local_60 = local_res8;
    local_res8[0] = 0xfffffffc;
    local_70 = 0x134;
    local_58 = 0x4000000;
    local_88 = 0;
    uStack_80 = 0;
    RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
    pcVar2 = (code *)MmGetSystemRoutineAddress(&local_88);
    if (pcVar2 == (code *)0x0) {
      pcVar2 = RtlQueryRegistryValues_exref;
    }
    uVar1 = (*pcVar2)(1,L"kdnic",&local_78,0,0);
    if (-1 < (int)uVar1) {
      if (local_res8[0] < 5000) {
        local_res8[0] = 5000;
      }
      if (40000 < local_res8[0]) {
        local_res8[0] = 40000;
      }
      *param_1 = local_res8[0];
    }
  }
  return uVar1;
}



===== KdNicDispatchForwardIrp @ 1c000135c =====

void KdNicDispatchForwardIrp(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1);
  return;
}



===== KdNicDispatchPower @ 1c0001390 =====

void KdNicDispatchPower(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  PoStartNextPowerIrp(param_2);
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1,param_2);
  return;
}



===== MPAttachAdapter @ 1c00013e4 =====

void MPAttachAdapter(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res8 = 0;
  local_resa = 0;
  if (param_1[6] != 0) {
    piVar1 = (int *)(param_1[6] + 4);
    LOCK();
    if (*piVar1 == 0) {
      *piVar1 = 1;
    }
    UNLOCK();
  }
  NdisAcquireRWLockWrite(DAT_1c0006150,&local_res8,0);
  puVar4 = auStack_28;
  puVar3 = &GlobalData;
  if ((undefined *)*DAT_1c0006148 != &GlobalData) {
    puVar3 = (undefined *)0x3;
    pcVar2 = (code *)swi(0x29);
    DAT_1c0006148 = (undefined8 *)(*pcVar2)();
    puVar4 = auStack_20;
  }
  *param_1 = puVar3;
  param_1[1] = DAT_1c0006148;
  *DAT_1c0006148 = param_1;
  *(undefined8 *)(puVar4 + -8) = 0x1c0001462;
  DAT_1c0006148 = param_1;
  NdisReleaseRWLock(DAT_1c0006150,puVar4 + 0x30);
  return;
}



===== MPDetachAdapter @ 1c0001474 =====

void MPDetachAdapter(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if (param_1[6] != 0) {
    piVar1 = (int *)(param_1[6] + 4);
    LOCK();
    if (*piVar1 == 1) {
      *piVar1 = 0;
    }
    UNLOCK();
  }
  NdisAcquireRWLockWrite(DAT_1c0006150,&local_res8,0);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    NdisReleaseRWLock(DAT_1c0006150,&local_res8);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== MPSetOptions @ 1c0001510 =====

undefined8 MPSetOptions(void)

{
  return 0;
}



===== MPCheckForHangEx @ 1c0001520 =====

undefined1 MPCheckForHangEx(void)

{
  return 0;
}



===== MPResetEx @ 1c0001530 =====

undefined8 MPResetEx(longlong *param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[6] != 0) {
    iVar2 = *(int *)(param_1[6] + 4);
  }
  if ((*(uint *)(param_1 + 8) & 1) == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
    NICStopTheDatapath(param_1,0xc001000d);
    if (iVar2 != 0) {
      NICStartTheDatapath(param_1);
    }
    *param_2 = 0;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc001000d;
  }
  return uVar1;
}



===== _guard_check_icall @ 1c00015a0 =====

void _guard_check_icall(void)

{
  return;
}



===== NICAsyncResetOrPauseDpc @ 1c00015b0 =====

void NICAsyncResetOrPauseDpc(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  
  if ((*(uint *)(param_2 + 0x40) & 0x11) == 0) {
    return;
  }
  bVar1 = *(int *)(param_2 + 200) != 0;
  if (*(int *)(param_2 + 0x120) == 0) {
    if (*(int *)(param_2 + 200) == 0) goto LAB_1c0001616;
  }
  else {
    bVar1 = true;
  }
  *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + 1;
  if (*(int *)(param_2 + 0x140) < 0x33) {
    NdisSetTimerObject(*(undefined8 *)(param_2 + 0x138),0xfffffffffff0bdc0,0,0);
    return;
  }
LAB_1c0001616:
  if ((*(uint *)(param_2 + 0x40) & 0x10) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xffffffef | 0x20;
    NdisMPauseComplete(*(undefined8 *)(param_2 + 0x28));
  }
  if ((*(uint *)(param_2 + 0x40) & 1) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffe;
    NdisMResetComplete(*(undefined8 *)(param_2 + 0x28),-(uint)bVar1 & 0xc0000001,0);
  }
  return;
}



===== NICIsBusy @ 1c0001674 =====

undefined4 NICIsBusy(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = CONCAT31((int3)((uint)*(int *)(param_1 + 200) >> 8),*(int *)(param_1 + 200) != 0);
  if (*(int *)(param_1 + 0x120) != 0) {
    uVar1 = 1;
  }
  return uVar1;
}



===== NICScheduleTheResetOrPauseDpc @ 1c0001698 =====

void NICScheduleTheResetOrPauseDpc(longlong param_1,char param_2)

{
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x140) = 0;
  }
  NdisSetTimerObject(*(undefined8 *)(param_1 + 0x138),0xfffffffffff0bdc0,0,0);
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_hKdnicProviderProv @ 1c00016d4 =====

void _tlgDefineProvider_annotation__Tlgg_hKdnicProviderProv(void)

{
  return;
}



===== MPOidRequest @ 1c00016e0 =====

ulonglong MPOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = MPSetInformation(param_1,param_2);
      return CONCAT44(extraout_var,iVar1);
    }
    if (iVar1 != 2) {
      return 0xc00000bb;
    }
  }
  uVar2 = MPQueryInformation(param_1,param_2);
  return uVar2;
}



===== MPQueryInformation @ 1c0001718 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MPQueryInformation(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  longlong *_Src;
  uint uVar4;
  undefined1 auStack_78 [32];
  int local_58;
  undefined2 local_54 [2];
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  longlong local_40;
  undefined2 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0x74;
  local_44 = 0;
  local_40._0_1_ = 'M';
  local_40._1_1_ = 'i';
  local_40._2_1_ = 'c';
  local_40._3_1_ = 'r';
  local_40._4_1_ = 'o';
  local_40._5_1_ = 's';
  local_40._6_1_ = 'o';
  local_40._7_1_ = 'f';
  _Src = (longlong *)&local_58;
  uVar1 = *(uint *)(param_2 + 0x20);
  uVar4 = 4;
  local_48 = 0;
  local_58 = 0;
  local_54[0] = 0;
  local_50 = 0;
  if (uVar1 < 0x20102) {
    if (uVar1 != 0x20101) {
      if (uVar1 < 0x1010c) {
        if (uVar1 != 0x1010b) {
          if (uVar1 == 0x10102) {
            _Src = (longlong *)&local_44;
            goto LAB_1c0001b63;
          }
          if ((uVar1 == 0x10103) || (uVar1 == 0x10104)) {
            _Src = (longlong *)&local_48;
            goto LAB_1c0001b63;
          }
          if (uVar1 == 0x10108) {
            local_58 = *(int *)(param_1 + 0x160) * 0x5ea;
            goto LAB_1c0001b63;
          }
          if (uVar1 == 0x10109) {
            local_58 = *(int *)(param_1 + 0x164) * 0x5ea;
            goto LAB_1c0001b63;
          }
          if (uVar1 != 0x1010a) {
            return 0xc00000bb;
          }
        }
      }
      else {
        if (uVar1 == 0x1010c) {
          local_58 = 0xffffff;
          goto LAB_1c0001b63;
        }
        if (uVar1 == 0x1010d) {
          _Src = &local_40;
          uVar4 = 10;
          goto LAB_1c0001b63;
        }
        if (uVar1 == 0x10110) {
          _Src = (longlong *)local_54;
          local_54[0] = 0x614;
          uVar4 = 2;
          goto LAB_1c0001b63;
        }
        if (uVar1 != 0x10111) {
          if (uVar1 == 0x10115) {
            local_58 = *(int *)(param_1 + 0x38);
          }
          else {
            if (uVar1 != 0x10116) {
              return 0xc00000bb;
            }
            local_58 = 0x40002;
          }
          goto LAB_1c0001b63;
        }
      }
      local_58 = 0x5ea;
      goto LAB_1c0001b63;
    }
    local_50 = *(longlong *)(param_1 + 600) + *(longlong *)(param_1 + 0x250) +
               *(longlong *)(param_1 + 0x248);
  }
  else {
    if (0x1020102 < uVar1) {
      if (uVar1 == 0x1020103) {
        local_58 = *(int *)(param_1 + 0x2a8);
      }
      else if (uVar1 == 0x1020201) {
        local_58 = *(int *)(param_1 + 0x2a0);
      }
      else if (uVar1 == 0x1020202) {
        local_58 = *(int *)(param_1 + 0x290);
      }
      else if (uVar1 == 0x1020203) {
        local_58 = *(int *)(param_1 + 0x2c0);
      }
      else if (uVar1 == 0x1020204) {
        local_58 = *(int *)(param_1 + 0x298);
      }
      else if ((uVar1 == 0x1020205) || (uVar1 == 0x1020206)) {
        local_58 = *(int *)(param_1 + 0x29c);
      }
      else {
        if (uVar1 != 0x1020207) {
          return 0xc00000bb;
        }
        local_58 = *(int *)(param_1 + 0x294);
      }
      goto LAB_1c0001b63;
    }
    if (uVar1 == 0x1020102) {
      local_58 = *(int *)(param_1 + 0x2a4);
      goto LAB_1c0001b63;
    }
    if (0x2020e < uVar1) {
      if (uVar1 == 0x1010101) {
        _Src = (longlong *)(param_1 + 0x44);
      }
      else {
        if (uVar1 != 0x1010102) {
          if (uVar1 == 0x1010104) {
            local_58 = 0x20;
          }
          else {
            if (uVar1 != 0x1020101) {
              return 0xc00000bb;
            }
            local_58 = *(int *)(param_1 + 0x2b8);
          }
          goto LAB_1c0001b63;
        }
        _Src = (longlong *)(param_1 + 0x4a);
      }
      uVar4 = 6;
      goto LAB_1c0001b63;
    }
    if (uVar1 == 0x2020e) {
      local_58 = *(int *)(param_1 + 200);
      goto LAB_1c0001b63;
    }
    if (uVar1 != 0x20102) {
      if (uVar1 == 0x20103) {
        local_58 = *(int *)(param_1 + 0x2b0) + *(int *)(param_1 + 0x29c) + *(int *)(param_1 + 0x298)
                   + *(int *)(param_1 + 0x294) + *(int *)(param_1 + 0x290);
      }
      else if (uVar1 == 0x20104) {
        local_58 = *(int *)(param_1 + 0x2c8) + *(int *)(param_1 + 0x2c0) + *(int *)(param_1 + 700) +
                   *(int *)(param_1 + 0x2b8) + *(int *)(param_1 + 0x2b4);
      }
      else {
        if (uVar1 != 0x20105) {
          if (uVar1 != 0x20106) {
            return 0xc00000bb;
          }
          if (*(uint *)(param_2 + 0x30) < 0x98) {
            *(undefined4 *)(param_2 + 0x38) = 0x98;
            return 0xc0010016;
          }
          puVar2 = *(undefined4 **)(param_2 + 0x28);
          memset(puVar2 + 2,0,0x90);
          *puVar2 = 0x980180;
          puVar2[1] = 0x839ffec;
          *(longlong *)(puVar2 + 6) =
               *(longlong *)(param_1 + 0x268) + *(longlong *)(param_1 + 0x270) +
               *(longlong *)(param_1 + 0x260);
          *(undefined8 *)(puVar2 + 0x1a) = *(undefined8 *)(param_1 + 0x260);
          *(undefined8 *)(puVar2 + 0x1c) = *(undefined8 *)(param_1 + 0x268);
          *(undefined8 *)(puVar2 + 0x1e) = *(undefined8 *)(param_1 + 0x270);
          *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x230);
          *(undefined8 *)(puVar2 + 10) = *(undefined8 *)(param_1 + 0x238);
          *(undefined8 *)(puVar2 + 0xc) = *(undefined8 *)(param_1 + 0x240);
          uVar3 = (ulonglong)
                  (uint)(*(int *)(param_1 + 0x2c8) + *(int *)(param_1 + 0x2c0) +
                         *(int *)(param_1 + 0x2b8) + *(int *)(param_1 + 0x2b4) +
                        *(int *)(param_1 + 700));
          *(ulonglong *)(puVar2 + 4) = uVar3;
          *(ulonglong *)(puVar2 + 2) = *(uint *)(param_1 + 700) + uVar3;
          *(longlong *)(puVar2 + 0xe) =
               *(longlong *)(param_1 + 0x280) + *(longlong *)(param_1 + 0x288) +
               *(longlong *)(param_1 + 0x278);
          *(undefined8 *)(puVar2 + 0x20) = *(undefined8 *)(param_1 + 0x278);
          *(undefined8 *)(puVar2 + 0x22) = *(undefined8 *)(param_1 + 0x280);
          *(undefined8 *)(puVar2 + 0x24) = *(undefined8 *)(param_1 + 0x288);
          *(undefined8 *)(puVar2 + 0x10) = *(undefined8 *)(param_1 + 0x248);
          *(undefined8 *)(puVar2 + 0x12) = *(undefined8 *)(param_1 + 0x250);
          *(undefined8 *)(puVar2 + 0x14) = *(undefined8 *)(param_1 + 600);
          *(ulonglong *)(puVar2 + 0x16) =
               (ulonglong)
               (uint)(*(int *)(param_1 + 0x2b0) + *(int *)(param_1 + 0x29c) +
                      *(int *)(param_1 + 0x298) + *(int *)(param_1 + 0x294) +
                     *(int *)(param_1 + 0x290));
          *(undefined8 *)(puVar2 + 0x18) = 0;
          *(undefined4 *)(param_2 + 0x34) = 0x98;
          return 0;
        }
        local_58 = *(int *)(param_1 + 700);
      }
      goto LAB_1c0001b63;
    }
    local_50 = *(longlong *)(param_1 + 0x240) + *(longlong *)(param_1 + 0x238) +
               *(longlong *)(param_1 + 0x230);
  }
  _Src = &local_50;
  uVar4 = 8;
LAB_1c0001b63:
  if (*(uint *)(param_2 + 0x30) < uVar4) {
    *(uint *)(param_2 + 0x38) = uVar4;
    return 0xc0010016;
  }
  memcpy(*(void **)(param_2 + 0x28),_Src,(ulonglong)uVar4);
  *(uint *)(param_2 + 0x34) = uVar4;
  return 0;
}



===== MPSetInformation @ 1c0001bb0 =====

int MPSetInformation(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x20);
  if (iVar2 == 0x1010e) {
    if (*(int *)(param_2 + 0x30) != 4) {
LAB_1c0001c7a:
      *(undefined4 *)(param_2 + 0x38) = 4;
      return -0x3ffeffec;
    }
    *(undefined4 *)(param_2 + 0x34) = 4;
    uVar1 = **(uint **)(param_2 + 0x28);
    if ((uVar1 & 0xffffffd0) != 0) {
      return -0x3fffff45;
    }
    if (uVar1 != *(uint *)(param_1 + 0x144)) {
      *(uint *)(param_1 + 0x144) = uVar1;
    }
  }
  else if (iVar2 == 0x1010f) {
    if (*(int *)(param_2 + 0x30) != 4) goto LAB_1c0001c7a;
    *(undefined4 *)(param_1 + 0x148) = **(undefined4 **)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x34) = 4;
  }
  else {
    if (iVar2 != 0x1010103) {
      return -0x3fffff45;
    }
    uVar1 = *(uint *)(param_2 + 0x30);
    iVar2 = 0;
    *(undefined4 *)(param_2 + 0x38) = 6;
    *(uint *)(param_2 + 0x34) = uVar1;
    if (uVar1 == (uVar1 / 6) * 6) {
      if (uVar1 < 0xc1) {
        memset((void *)(param_1 + 0x16c),0,0xc0);
        memcpy((void *)(param_1 + 0x16c),*(void **)(param_2 + 0x28),
               (ulonglong)*(uint *)(param_2 + 0x30));
        *(uint *)(param_1 + 0x168) = *(uint *)(param_2 + 0x30) / 6;
      }
      else {
        iVar2 = -0x3ffefff7;
        *(undefined4 *)(param_2 + 0x38) = 0xc0;
      }
    }
    else {
      iVar2 = -0x3ffeffec;
    }
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x30);
  return 0;
}



===== MPReturnNetBufferLists @ 1c0001cf0 =====

void MPReturnNetBufferLists(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  while (param_2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_2;
    *param_2 = 0;
    *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
    RCBFree(param_1,param_2[0xc]);
    param_2 = puVar1;
  }
  return;
}



===== MPSendNetBufferLists @ 1c0001d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MPSendNetBufferLists(longlong param_1,undefined8 *param_2,undefined8 param_3,byte param_4)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined2 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  LOCK();
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
  UNLOCK();
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0x30) + 0x56) == '\0')) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  }
  else {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffd;
  }
  do {
    while( true ) {
      if (param_2 == (undefined8 *)0x0) {
        TXTransmitQueuedSends(param_1);
        LOCK();
        *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + -1;
        UNLOCK();
        return;
      }
      uVar3 = *(uint *)(param_1 + 0x40);
      puVar1 = (undefined8 *)*param_2;
      if ((uVar3 & 0x37) == 0) break;
      if ((uVar3 & 1) == 0) {
        *(uint *)((longlong)param_2 + 0x8c) = (-(uint)((uVar3 & 0x30) != 0) & 0x230029) + 0xc0000001
        ;
      }
      else {
        *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc001000d;
      }
      *param_2 = 0;
      NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2,param_4 & 1);
      param_2 = puVar1;
    }
    *param_2 = 0;
    *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
    *(undefined4 *)(param_2 + 0xd) = 0;
    LOCK();
    *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
    UNLOCK();
    LOCK();
    *(int *)(param_2 + 0xd) = *(int *)(param_2 + 0xd) + 1;
    UNLOCK();
    for (puVar5 = (undefined8 *)param_2[1]; puVar5 != (undefined8 *)0x0;
        puVar5 = (undefined8 *)*puVar5) {
      puVar5[0x12] = param_2;
      puVar6 = (undefined8 *)puVar5[1];
      uVar4 = 0;
      local_50 = 0;
      local_48 = 0;
      local_44 = 0;
      do {
        if (puVar6 == (undefined8 *)0x0) {
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0010015;
          _KdNicTxBadDestinationAddress = _KdNicTxBadDestinationAddress + 1;
          goto LAB_1c0001ecc;
        }
        uVar3 = 0xe - (int)uVar4;
        if (*(uint *)(puVar6 + 5) < uVar3) {
          uVar3 = *(uint *)(puVar6 + 5);
        }
        memcpy((void *)((longlong)&local_50 + uVar4),
               (void *)((ulonglong)*(uint *)((longlong)puVar6 + 0x2c) + puVar6[4]),(ulonglong)uVar3)
        ;
        puVar6 = (undefined8 *)*puVar6;
        uVar3 = (int)uVar4 + uVar3;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < 0xe);
      local_58 = (undefined4)local_50;
      local_54 = local_50._4_2_;
      cVar2 = NICGetFrameTypeFromDestination((byte *)&local_58);
      *(int *)(puVar5 + 0x13) = (int)CONCAT71(extraout_var,cVar2);
      LOCK();
      *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
      UNLOCK();
      LOCK();
      *(int *)(param_2 + 0xd) = *(int *)(param_2 + 0xd) + 1;
      UNLOCK();
      ExInterlockedInsertTailList(param_1 + 0x80,puVar5 + 0x10,param_1 + 0x90);
LAB_1c0001ecc:
    }
    TXNblRelease(param_1,param_2,param_4 & 1);
    param_2 = puVar1;
  } while( true );
}



===== NICGetFrameTypeFromDestination @ 1c0001f30 =====

char NICGetFrameTypeFromDestination(byte *param_1)

{
  char cVar1;
  
  if (*param_1 != 0xff) {
    return ((*param_1 & 1) != 0) + '\x01';
  }
  if ((((param_1[1] != 0xff) || (param_1[2] != 0xff)) || (param_1[3] != 0xff)) ||
     (param_1[4] != 0xff)) {
    return '\x02';
  }
  cVar1 = '\x02';
  if (param_1[5] == 0xff) {
    cVar1 = '\b';
  }
  return cVar1;
}



===== RXScheduleTheReceiveIndication @ 1c0001f7c =====

void RXScheduleTheReceiveIndication(longlong param_1)

{
  if ((*(uint *)(param_1 + 0x50) & 1) == 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 2;
    NdisSetTimerObject(*(undefined8 *)(param_1 + 0x130),0xffffffffffffe2b4,0,0);
  }
  return;
}



===== RxFlushReceiveQueue @ 1c0001fc8 =====

void RxFlushReceiveQueue(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 != 0) {
    while (lVar2 = ExpInterlockedPopEntrySList(lVar1 + 0x30), lVar2 != 0) {
      RCBFree(param_1,lVar2);
    }
    while (lVar2 = ExpInterlockedPopEntrySList(lVar1 + 0x40), lVar2 != 0) {
      RCBFree(param_1,lVar2);
    }
  }
  return;
}



===== RxReceiveIndicateDpc @ 1c0002040 =====

void RxReceiveIndicateDpc(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 ***pppuVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined7 extraout_var;
  longlong lVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 **ppuVar13;
  undefined8 **ppuVar14;
  undefined8 **ppuVar15;
  int iVar16;
  undefined4 local_res10;
  undefined2 local_res14;
  undefined8 ***local_38;
  undefined8 ***pppuStack_30;
  
  lVar11 = *(longlong *)(param_2 + 0x30);
  local_38 = (undefined8 ***)0x0;
  pppuStack_30 = (undefined8 ***)0x0;
  if (lVar11 != 0) {
    iVar16 = 0;
    ppuVar15 = (undefined8 **)0x0;
    while( true ) {
      lVar10 = 0;
      piVar7 = (int *)ExAllocateFromNPagedLookasideList(&DAT_1c0006180);
      if (piVar7 == (int *)0x0) break;
      *piVar7 = 1;
      piVar7[4] = 0x5ea;
      lVar8 = ExInterlockedRemoveHeadList(param_2 + 0xe0);
      if (lVar8 != 0) {
        LOCK();
        *(int *)(param_2 + 0x120) = *(int *)(param_2 + 0x120) + 1;
        UNLOCK();
        lVar10 = lVar8 + -0x10;
        LOCK();
        *piVar7 = *piVar7 + 1;
        UNLOCK();
        *(int **)(lVar8 + 0x18) = piVar7;
        lVar1 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 8);
        uVar2 = *(undefined8 *)(piVar7 + 2);
        *(undefined8 *)(lVar1 + 0x20) = uVar2;
        *(undefined4 *)(lVar1 + 0x18) = 0;
        *(undefined4 *)(lVar1 + 0x28) = 0;
        *(undefined8 *)(lVar1 + 8) = uVar2;
        *(undefined4 *)(lVar1 + 0x10) = 0;
        *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x60) = lVar10;
      }
      LOCK();
      iVar6 = *piVar7;
      *piVar7 = *piVar7 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        ExFreeToNPagedLookasideList(&DAT_1c0006180,piVar7);
      }
      if (lVar10 == 0) break;
      ExpInterlockedPushEntrySList(lVar11 + 0x30,lVar10);
    }
    cVar5 = KdPollBreakIn();
    if (cVar5 != '\0') {
      DbgBreakPointWithStatus(1);
    }
    puVar9 = (undefined8 *)ExpInterlockedFlushSList(lVar11 + 0x40);
    if (puVar9 != (undefined8 *)0x0) {
      pppuStack_30 = &local_38;
      local_38 = &local_38;
      do {
        lVar11 = puVar9[5];
        puVar12 = (undefined8 *)*puVar9;
        *puVar9 = 0;
        *(undefined4 *)(*(longlong *)(puVar9[4] + 8) + 0x18) = *(undefined4 *)(lVar11 + 0x10);
        local_res10 = *(undefined4 *)(lVar11 + 0x14);
        local_res14 = *(undefined2 *)(lVar11 + 0x18);
        cVar5 = NICGetFrameTypeFromDestination((byte *)&local_res10);
        iVar6 = (int)CONCAT71(extraout_var,cVar5);
        if (iVar6 == 1) {
LAB_1c00021fa:
          *(longlong *)(param_2 + 0x230) = *(longlong *)(param_2 + 0x230) + 1;
          *(longlong *)(param_2 + 0x260) =
               *(longlong *)(param_2 + 0x260) + (ulonglong)*(uint *)(lVar11 + 0x10);
        }
        else if (iVar6 == 2) {
          *(longlong *)(param_2 + 0x238) = *(longlong *)(param_2 + 0x238) + 1;
          *(longlong *)(param_2 + 0x268) =
               *(longlong *)(param_2 + 0x268) + (ulonglong)*(uint *)(lVar11 + 0x10);
        }
        else {
          if (iVar6 != 8) goto LAB_1c00021fa;
          *(longlong *)(param_2 + 0x240) = *(longlong *)(param_2 + 0x240) + 1;
          *(longlong *)(param_2 + 0x270) =
               *(longlong *)(param_2 + 0x270) + (ulonglong)*(uint *)(lVar11 + 0x10);
        }
        pppuVar3 = (undefined8 ***)(puVar9 + 2);
        if ((undefined8 ****)local_38[1] != &local_38) goto LAB_1c00022fb;
        *pppuVar3 = local_38;
        puVar9[3] = &local_38;
        local_38[1] = pppuVar3;
        puVar9 = puVar12;
        ppuVar13 = (undefined8 **)0x0;
        local_38 = pppuVar3;
      } while (puVar12 != (undefined8 *)0x0);
      while ((undefined8 ****)local_38 != &local_38) {
        if (((undefined8 ****)local_38[1] != &local_38) ||
           (pppuVar3 = (undefined8 ***)*local_38, (undefined8 ***)pppuVar3[1] != local_38))
        goto LAB_1c00022fb;
        pppuVar3[1] = &local_38;
        *(undefined4 *)((longlong)local_38[2] + 0x8c) = 0;
        ppuVar14 = local_38[2];
        if (ppuVar15 == (undefined8 **)0x0) {
          ppuVar15 = ppuVar14;
        }
        else {
          *ppuVar13 = ppuVar14;
          ppuVar14 = local_38[2];
        }
        iVar16 = iVar16 + 1;
        ppuVar13 = ppuVar14;
        local_38 = pppuVar3;
      }
      if (iVar16 != 0) {
        *ppuVar13 = (undefined8 *)0x0;
        NdisMIndicateReceiveNetBufferLists(*(undefined8 *)(param_2 + 0x28),ppuVar15,0,iVar16,0x401);
      }
    }
  }
  if ((*(uint *)(param_2 + 0x50) & 1) != 0) {
    *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) | 2;
    NdisSetTimerObject(*(undefined8 *)(param_2 + 0x130),0xffffffffffffe2b4,0,0);
    return;
  }
LAB_1c0002302:
  *(undefined4 *)(param_2 + 0x50) = 0;
  return;
LAB_1c00022fb:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  goto LAB_1c0002302;
}



===== TXFlushSendQueue @ 1c0002330 =====

longlong TXFlushSendQueue(longlong param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  bool bVar6;
  
  do {
    LOCK();
    bVar6 = *(int *)(param_1 + 0xd0) == 0;
    if (bVar6) {
      *(int *)(param_1 + 0xd0) = 0;
    }
    UNLOCK();
  } while (!bVar6);
  while (lVar4 = ExInterlockedRemoveHeadList(param_1 + 0x80,param_1 + 0x90), lVar4 != 0) {
    puVar3 = *(undefined8 **)(lVar4 + 0x10);
    *(undefined4 *)((longlong)puVar3 + 0x8c) = param_2;
    LOCK();
    piVar1 = (int *)(puVar3 + 0xd);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      *puVar3 = 0;
      NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),puVar3,0);
    }
    LOCK();
    *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + -1;
    UNLOCK();
  }
  while( true ) {
    lVar4 = ExInterlockedRemoveHeadList(param_1 + 0xa0);
    uVar5 = -(ulonglong)(lVar4 != 0) & lVar4 - 0x10U;
    if (uVar5 == 0) break;
    *(undefined4 *)(*(longlong *)(*(longlong *)(uVar5 + 0x20) + 0x90) + 0x8c) = param_2;
    TCBFree(param_1,uVar5);
  }
  return -lVar4;
}



===== TXNblRelease @ 1c0002420 =====

void TXNblRelease(longlong param_1,undefined8 *param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0xd);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *param_2 = 0;
    NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2,param_3 != '\0');
  }
  LOCK();
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + -1;
  UNLOCK();
  return;
}



===== TXScheduleTheSendComplete @ 1c000246c =====

void TXScheduleTheSendComplete(longlong param_1)

{
  NdisSetTimerObject(*(undefined8 *)(param_1 + 0xc0),0xffffffffffffe2b4,1);
  return;
}



===== TXSendCompleteDpc @ 1c00024a0 =====

void TXSendCompleteDpc(undefined8 param_1,longlong param_2)

{
  undefined8 ****ppppuVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 ****ppppuVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 ****local_18;
  undefined8 ****ppppuStack_10;
  
  local_18 = (undefined8 ****)0x0;
  ppppuStack_10 = (undefined8 ****)0x0;
  puVar7 = auStack_38;
  if (*(longlong *)(param_2 + 0x30) != 0) {
    puVar6 = (undefined8 *)ExpInterlockedFlushSList(*(longlong *)(param_2 + 0x30) + 0x20);
    puVar7 = auStack_38;
    if (puVar6 != (undefined8 *)0x0) {
      ppppuStack_10 = &local_18;
      local_18 = &local_18;
      do {
        puVar3 = (undefined8 *)*puVar6;
        ppppuVar4 = (undefined8 ****)(puVar6 + 2);
        *puVar6 = 0;
        if ((undefined8 *****)local_18[1] != &local_18) goto LAB_1c00025d7;
        *ppppuVar4 = local_18;
        puVar6[3] = &local_18;
        local_18[1] = ppppuVar4;
        puVar6 = puVar3;
        local_18 = ppppuVar4;
      } while (puVar3 != (undefined8 *)0x0);
      while (puVar7 = auStack_38, (undefined8 *****)local_18 != &local_18) {
        if (((undefined8 *****)local_18[1] != &local_18) ||
           (ppppuVar4 = (undefined8 ****)*local_18, (undefined8 ****)ppppuVar4[1] != local_18))
        goto LAB_1c00025d7;
        ppppuVar4[1] = &local_18;
        ppppuVar1 = local_18 + -2;
        uVar8 = (ulonglong)*(uint *)((longlong)local_18 + 0x1c);
        if (*(uint *)((longlong)local_18 + 0x1c) == 0) {
          *(int *)(param_2 + 0x2b0) = *(int *)(param_2 + 0x2b0) + 1;
          *(undefined4 *)((longlong)local_18[2][0x12] + 0x8c) = 0xc000009a;
        }
        else {
          iVar2 = *(int *)(local_18 + 3);
          if (iVar2 == 1) {
LAB_1c00025b8:
            *(longlong *)(param_2 + 0x248) = *(longlong *)(param_2 + 0x248) + 1;
            *(longlong *)(param_2 + 0x278) = *(longlong *)(param_2 + 0x278) + uVar8;
          }
          else if (iVar2 == 2) {
            *(longlong *)(param_2 + 0x250) = *(longlong *)(param_2 + 0x250) + 1;
            *(longlong *)(param_2 + 0x280) = *(longlong *)(param_2 + 0x280) + uVar8;
          }
          else {
            if (iVar2 != 8) goto LAB_1c00025b8;
            *(longlong *)(param_2 + 600) = *(longlong *)(param_2 + 600) + 1;
            *(longlong *)(param_2 + 0x288) = *(longlong *)(param_2 + 0x288) + uVar8;
          }
        }
        local_18 = ppppuVar4;
        TCBFree(param_2,(longlong)ppppuVar1);
      }
    }
  }
LAB_1c00025de:
  *(undefined8 *)(puVar7 + -8) = 0x1c00025e6;
  TXTransmitQueuedSends(param_2);
  return;
LAB_1c00025d7:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar7 = auStack_30;
  goto LAB_1c00025de;
}



===== TXTransmitQueuedSends @ 1c00025f8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TXTransmitQueuedSends(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xcc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 < 2) {
LAB_1c000268a:
    do {
      lVar5 = ExInterlockedRemoveHeadList(param_1 + 0x60,param_1 + 0x70);
      if (lVar5 == 0) {
        _KdNicTxTransmitQueuedSendsNoTCBs = _KdNicTxTransmitQueuedSendsNoTCBs + 1;
      }
      else {
        lVar4 = ExInterlockedRemoveHeadList(param_1 + 0x80,param_1 + 0x90);
        if (lVar4 != 0) {
          *(undefined4 *)(lVar5 + 0x1c) = 0;
          *(longlong *)(lVar5 + 0x10) = lVar4 + -0x80;
          *(undefined4 *)(lVar5 + 0x18) = *(undefined4 *)(lVar4 + 0x18);
          ExpInterlockedPushEntrySList(*(longlong *)(param_1 + 0x30) + 0x10,lVar5 + -0x10);
          goto LAB_1c000268a;
        }
        ExInterlockedInsertTailList(param_1 + 0x60,lVar5,param_1 + 0x70);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xcc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    } while (1 < iVar2);
    cVar3 = KdPollBreakIn();
    if (cVar3 != '\0') {
      DbgBreakPointWithStatus(1);
    }
  }
  return;
}



===== RCBFree @ 1c0002718 =====

void RCBFree(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 0x28);
  ExInterlockedInsertTailList(param_1 + 0xe0,param_2 + 0x10,param_1 + 0xf0);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    ExFreeToNPagedLookasideList(&DAT_1c0006180,piVar2);
  }
  LOCK();
  *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + -1;
  UNLOCK();
  return;
}



===== TCBFree @ 1c0002784 =====

void TCBFree(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(*(longlong *)(param_2 + 0x20) + 0x90);
  LOCK();
  piVar1 = (int *)(puVar3 + 0xd);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *puVar3 = 0;
    NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),puVar3,1);
  }
  LOCK();
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + -1;
  UNLOCK();
  *(undefined8 *)(param_2 + 0x20) = 0;
  ExInterlockedInsertTailList(param_1 + 0x60,param_2 + 0x10,param_1 + 0x70);
  return;
}



===== HWFrameAllocate @ 1c0002800 =====

longlong HWFrameAllocate(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = NdisAllocateMemoryWithTagPriority(NdisDriverHandle,param_2,param_3,0x10);
  if (lVar1 != 0) {
    lVar2 = NdisAllocateMdl(NdisDriverHandle,lVar1 + 0x14,0x5ea);
    *(longlong *)(lVar1 + 8) = lVar2;
    if (lVar2 != 0) {
      return lVar1;
    }
    NdisFreeMemory(lVar1,param_2 & 0xffffffff,0);
  }
  return 0;
}



===== HWFrameFree @ 1c0002890 =====

void HWFrameFree(longlong param_1)

{
  NdisFreeMdl(*(undefined8 *)(param_1 + 8));
  NdisFreeMemory(param_1,0x600,0);
  return;
}



===== HWGetMediaConnectStatus @ 1c00028d0 =====

char HWGetMediaConnectStatus(longlong param_1)

{
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0x30) + 0x56) == '\0')) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  }
  else {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffd;
  }
  return ((*(uint *)(param_1 + 0x40) & 2) != 0) + '\x01';
}



===== __GSHandlerCheck @ 1c0002908 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000292c =====

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



===== __cpu_features_init @ 1c00029a0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0002a0a) */
/* WARNING: Removing unreachable block (ram,0x0001c00029b9) */
/* WARNING: Removing unreachable block (ram,0x0001c00029aa) */

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



===== __security_check_cookie @ 1c0002a70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002ab0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002ae0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002ae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002b10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002b80 =====

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



===== memset @ 1c0002e80 =====

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



===== __memset_repmovs @ 1c0002fc0 =====

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



===== __memset_query @ 1c0003040 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00030c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003200 =====

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



===== __memset_spec_plain @ 1c0003280 =====

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



===== DriverUnload @ 1c0009010 =====

void DriverUnload(void)

{
  if ((DAT_1c0006200 & 1) != 0) {
    DAT_1c0006200 = DAT_1c0006200 & 0xfffffffe;
    FreeAdapterListLock();
  }
  if ((DAT_1c0006200 & 4) != 0) {
    DAT_1c0006200 = DAT_1c0006200 & 0xfffffffb;
    NdisMDeregisterMiniportDriver(NdisDriverHandle);
  }
  if ((DAT_1c0006200 & 2) != 0) {
    DAT_1c0006200 = DAT_1c0006200 & 0xfffffffd;
    ExDeleteNPagedLookasideList(&DAT_1c0006180);
  }
  if ((DAT_1c0006200 & 8) != 0) {
    DAT_1c0006200 = DAT_1c0006200 & 0xfffffff7;
    ExSetTimerResolution(22000,0);
  }
  return;
}



===== KdNicAddDevice @ 1c00090b0 =====

int KdNicAddDevice(undefined8 param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  iVar2 = IoCreateDevice(param_1,8,0,0x12,0,0,local_res18);
  if (-1 < iVar2) {
    plVar1 = *(longlong **)(local_res18[0] + 0x40);
    lVar3 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    if (lVar3 == 0) {
      iVar2 = -0x3ffffff2;
    }
    else {
      *plVar1 = lVar3;
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      local_res18[0] = 0;
    }
  }
  if (local_res18[0] != 0) {
    IoDeleteDevice();
  }
  return iVar2;
}



===== KdNicDispatchPnp @ 1c0009160 =====

undefined4 KdNicDispatchPnp(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    if (cVar1 == '\x02') {
      uVar3 = KdNicDispatchForwardIrp(param_1,param_2);
      IoDetachDevice(*puVar2);
      IoDeleteDevice(param_1);
      return uVar3;
    }
    if ((((cVar1 != '\x03') && (cVar1 != '\x04')) && (cVar1 != '\x05')) && (cVar1 != '\x06')) {
      if (cVar1 != '\x14') goto LAB_1c00091ba;
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 2;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
LAB_1c00091ba:
  uVar3 = KdNicDispatchForwardIrp(param_1,param_2);
  return uVar3;
}



===== KdNicDispatchWmi @ 1c0009210 =====

void KdNicDispatchWmi(longlong param_1,longlong param_2)

{
  KdNicDispatchForwardIrp(param_1,param_2);
  return;
}



===== MPDevicePnpEventNotify @ 1c0009230 =====

void MPDevicePnpEventNotify(longlong param_1,longlong param_2)

{
  if (*(int *)(param_2 + 8) == 2) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  return;
}



===== MPHaltEx @ 1c0009250 =====

void MPHaltEx(longlong *param_1)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  NICStopTheDatapath(param_1,0xc0000001);
  while( true ) {
    uVar1 = NICIsBusy((longlong)param_1);
    if ((char)uVar1 == '\0') break;
    NdisMSleep(1000);
  }
  NICFreeAdapter((longlong)param_1);
  return;
}



===== MPInitializeEx @ 1c00092a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong MPInitializeEx(undefined8 param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined7 extraout_var;
  longlong lVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  undefined1 auStack_1e8 [8];
  undefined1 auStack_1e0 [24];
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  longlong local_1b0;
  ulonglong local_1a8;
  longlong local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 local_148 [2];
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined2 local_ec;
  undefined4 local_ea;
  undefined2 local_e6;
  undefined4 local_ca;
  undefined2 local_c6;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined2 local_94;
  undefined1 local_92;
  undefined8 local_90;
  undefined8 local_88;
  undefined *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined *local_58;
  undefined8 local_50;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_1b0 = 0;
  local_1a8 = (ulonglong)(uint)local_1a8;
  uVar7 = NICAllocAdapter(&local_1b0);
  lVar9 = local_1b0;
  uVar11 = uVar7 & 0xffffffff;
  if ((int)uVar7 == 0) {
    *(undefined8 *)(local_1b0 + 0x28) = param_1;
    local_1a8 = 0x1c1c9e;
    local_190 = 0;
    local_1a0 = local_1b0;
    local_198 = 0x24;
    local_194 = 4;
    uVar5 = NdisMSetMiniportAttributes(param_1,&local_1a8);
    uVar11 = (ulonglong)uVar5;
    if (uVar5 == 0) {
      local_50 = *(undefined8 *)(lVar9 + 0x28);
      local_1b8 = 0;
      local_58 = (undefined *)0x1401a9;
      local_48 = (undefined *)0x0;
      iVar6 = NdisOpenConfigurationEx(&local_58);
      if (iVar6 == 0) {
        lVar8 = *(longlong *)(lVar9 + 0x30);
        if (lVar8 != 0) {
          *(undefined4 *)(lVar9 + 0x44) = *(undefined4 *)(lVar8 + 0x50);
          *(undefined2 *)(lVar9 + 0x48) = *(undefined2 *)(lVar8 + 0x54);
        }
        *(undefined4 *)(lVar9 + 0x4a) = *(undefined4 *)(lVar9 + 0x44);
        *(undefined2 *)(lVar9 + 0x4e) = *(undefined2 *)(lVar9 + 0x48);
        if (lVar8 == 0) {
          lVar8 = 1000000000;
          *(undefined8 *)(lVar9 + 0x150) = 1000000000;
        }
        else {
          *(ulonglong *)(lVar9 + 0x150) = (ulonglong)*(uint *)(lVar8 + 0xc) * 1000000;
          uVar5 = *(uint *)(lVar8 + 0xc);
          *(ulonglong *)(lVar9 + 0x158) = (ulonglong)uVar5;
          lVar8 = (ulonglong)uVar5 * 1000000;
        }
        *(longlong *)(lVar9 + 0x158) = lVar8;
        NdisCloseConfiguration(local_1b8);
        memset(local_148,0,0xe0);
        local_148[0] = 0xe0029f;
        local_140 = 0;
        local_138 = 0x5dc;
        local_13c = 0x13;
        if (((byte)DAT_1c0006200 & 0x10) != 0) {
          local_13c = 0xe;
        }
        local_130 = *(undefined8 *)(lVar9 + 0x150);
        local_128 = *(undefined8 *)(lVar9 + 0x150);
        local_120 = *(undefined8 *)(lVar9 + 0x158);
        local_118 = *(undefined8 *)(lVar9 + 0x158);
        cVar4 = HWGetMediaConnectStatus(lVar9);
        local_110 = (undefined4)CONCAT71(extraout_var,cVar4);
        local_10c = 2;
        local_108 = *(undefined4 *)(lVar9 + 0x148);
        local_ec = 6;
        local_f8 = 0xd;
        local_f4 = 0x2f;
        local_f0 = 0x20;
        local_ea = *(undefined4 *)(lVar9 + 0x44);
        local_e6 = *(undefined2 *)(lVar9 + 0x48);
        local_ca = *(undefined4 *)(lVar9 + 0x4a);
        local_c6 = *(undefined2 *)(lVar9 + 0x4e);
        local_168 = 0;
        local_80 = &NICSupportedOids;
        local_94 = 6;
        uStack_15c = 0;
        uStack_180 = 0;
        uStack_158 = 0;
        local_a8 = 0;
        local_a0 = 2;
        local_98 = 1;
        local_92 = 1;
        local_90 = 0x839ffec;
        local_88 = 0;
        local_78 = 0xb0;
        local_74 = 4;
        local_178 = 0;
        uStack_170 = 0;
        local_188 = 0x340180;
        uStack_160 = 0;
        local_70 = 0;
        uVar5 = NdisMSetMiniportAttributes(param_1,local_148);
        uVar11 = (ulonglong)uVar5;
        if (uVar5 == 0) {
          local_1c0 = 0;
          local_1c8 = 0;
          NdisMGetDeviceProperty(param_1,lVar9 + 0x10,lVar9 + 0x18,lVar9 + 0x20);
          puVar10 = auStack_1e8;
          uVar11 = 0;
          local_68 = *(undefined4 *)(PTR_DAT_1c0006008 + -0x10);
          uStack_64 = *(undefined4 *)(PTR_DAT_1c0006008 + -0xc);
          uStack_60 = *(undefined8 *)(PTR_DAT_1c0006008 + -8);
          if (DAT_1c0006020 != 0) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(5);
            puVar10 = auStack_1e0;
          }
          _DAT_1c0006028 = 0;
          uRam00000001c0006030 = 0;
          *(undefined8 *)(puVar10 + -8) = 0x1c00095de;
          iVar6 = EtwRegister(&local_68,_tlgEnableCallback,&DAT_1c0006000,&DAT_1c0006020);
          if (iVar6 == 0) {
            uVar1 = *(undefined2 *)PTR_DAT_1c0006008;
            *(undefined8 *)(puVar10 + -8) = 0x1c0009603;
            EtwSetInformation(DAT_1c0006020,2,PTR_DAT_1c0006008,uVar1);
LAB_1c0009610:
            if (5 < DAT_1c0006000) {
              if (((_DAT_1c0006010 & 0x200000000000) == 0) ||
                 (bVar3 = true, (DAT_1c0006018 & 0x200000000000) != DAT_1c0006018)) {
                bVar3 = false;
              }
              if (bVar3) {
                uStack_60 = 0x200000000000;
                local_38 = "Strategy";
                uStack_64 = 5;
                local_58 = PTR_DAT_1c0006008;
                local_30 = 9;
                local_68 = 0xb000000;
                local_48 = &DAT_1c000531c;
                local_50 = CONCAT44(2,(uint)*(ushort *)PTR_DAT_1c0006008);
                local_40 = 0xf;
                local_3c = 1;
                *(undefined4 *)(puVar10 + 0x30) = 100;
                *(undefined ***)(puVar10 + 0x28) = &local_58;
                *(undefined4 *)(puVar10 + 0x20) = 3;
                *(undefined8 *)(puVar10 + -8) = 0x1c0009711;
                EtwWriteTransfer(DAT_1c0006020,&local_68,0,0);
                lVar9 = *(longlong *)(puVar10 + 0x38);
              }
            }
            lVar8 = DAT_1c0006020;
            DAT_1c0006020 = 0;
            DAT_1c0006000 = 0;
            *(undefined8 *)(puVar10 + -8) = 0x1c0009737;
            EtwUnregister(lVar8);
          }
          else if (-1 < iVar6) goto LAB_1c0009610;
          *(undefined8 *)(puVar10 + -8) = 0x1c0009744;
          NICSetVisible(lVar9);
          goto LAB_1c0009388;
        }
      }
      else {
        uVar11 = 0xc0000001;
      }
    }
  }
  puVar10 = auStack_1e8;
  if (lVar9 != 0) {
    NICFreeAdapter(lVar9);
    puVar10 = auStack_1e8;
  }
LAB_1c0009388:
  *(undefined8 *)(puVar10 + -8) = 0x1c0009399;
  return uVar11;
}



===== MPPause @ 1c0009750 =====

undefined8 MPPause(longlong *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x10;
  NICStopTheDatapath(param_1,0xc023002a);
  uVar1 = NICIsBusy((longlong)param_1);
  uVar2 = 0;
  if ((char)uVar1 == '\0') {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffef | 0x20;
  }
  else {
    NICScheduleTheResetOrPauseDpc((longlong)param_1,'\0');
    uVar2 = 0x103;
  }
  return uVar2;
}



===== MPRestart @ 1c00097a0 =====

undefined8 MPRestart(undefined8 *param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffcf;
  MPAttachAdapter(param_1);
  if (param_1[6] != 0) {
    *(uint *)(param_1 + 10) = *(uint *)(param_1 + 10) | 1;
    TXScheduleTheSendComplete((longlong)param_1);
    RXScheduleTheReceiveIndication((longlong)param_1);
  }
  return 0;
}



===== NICAllocAdapter @ 1c00097e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NICAllocAdapter(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  void *_Dst;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  code *pcStack_50;
  void *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  uVar7 = 0;
  *param_1 = 0;
  local_48 = (void *)0x0;
  local_58 = 0;
  pcStack_50 = (code *)0x0;
  _Dst = (void *)NdisAllocateMemoryWithTagPriority(NdisDriverHandle,0x2d0,0x5f4e444b,0x10);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x2d0);
    *(longlong *)((longlong)_Dst + 0x30) = KdNetNicInterface;
    lVar1 = KdNetNicInterface;
    *(undefined4 *)((longlong)_Dst + 0x38) = 0x200;
    *(undefined4 *)((longlong)_Dst + 0x3c) = 0x600;
    if (lVar1 == 0) {
      *(uint *)((longlong)_Dst + 0x40) = *(uint *)((longlong)_Dst + 0x40) | 2;
    }
    else {
      if (*(char *)(lVar1 + 0x56) == '\0') {
        *(uint *)((longlong)_Dst + 0x40) = *(uint *)((longlong)_Dst + 0x40) | 2;
      }
      if (1000 < *(uint *)(lVar1 + 0x58)) {
        uVar6 = *(uint *)(lVar1 + 0x58) / 1000;
        if (0x10 < uVar6) {
          uVar6 = 0x10;
        }
        *(uint *)((longlong)_Dst + 0x38) = uVar6 << 9;
        *(uint *)((longlong)_Dst + 0x3c) = uVar6 * 0x600;
      }
    }
    lVar1 = (longlong)_Dst + 0x60;
    *(void **)((longlong)_Dst + 8) = _Dst;
    *(void **)_Dst = _Dst;
    *(longlong *)((longlong)_Dst + 0x68) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)((longlong)_Dst + 0x50) = 0;
    KeInitializeSpinLock((longlong)_Dst + 0x70);
    lVar2 = (longlong)_Dst + 0x80;
    *(longlong *)((longlong)_Dst + 0x88) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0x90);
    lVar2 = (longlong)_Dst + 0xa0;
    *(longlong *)((longlong)_Dst + 0xa8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0xb0);
    lVar2 = (longlong)_Dst + 0xe0;
    *(longlong *)((longlong)_Dst + 0xe8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0xf0);
    lVar4 = (longlong)_Dst + 0x100;
    *(longlong *)((longlong)_Dst + 0x108) = lVar4;
    *(longlong *)lVar4 = lVar4;
    KeInitializeSpinLock((longlong)_Dst + 0x110);
    *(undefined4 *)((longlong)_Dst + 0x148) = 0x5dc;
    local_40 = 0x100180;
    local_3c = 0x100;
    local_38 = 0x724e444b;
    lVar4 = NdisAllocateNetBufferListPool(NdisDriverHandle,&local_40);
    *(longlong *)((longlong)_Dst + 0x128) = lVar4;
    if (lVar4 != 0) {
      uVar5 = NdisAllocateMemoryWithTagPriority
                        (*(undefined8 *)((longlong)_Dst + 0x28),
                         *(int *)((longlong)_Dst + 0x38) * 0x30,0x544e444b,0x10);
      *(undefined8 *)((longlong)_Dst + 0x58) = uVar5;
      lVar4 = NdisAllocateMemoryWithTagPriority
                        (*(undefined8 *)((longlong)_Dst + 0x28),
                         *(int *)((longlong)_Dst + 0x3c) * 0x30,0x524e444b,0x10);
      *(longlong *)((longlong)_Dst + 0xd8) = lVar4;
      if ((*(longlong *)((longlong)_Dst + 0x58) != 0) && (lVar4 != 0)) {
        if (*(int *)((longlong)_Dst + 0x38) != 0) {
          do {
            ExInterlockedInsertTailList
                      (lVar1,*(longlong *)((longlong)_Dst + 0x58) + 0x10 + uVar7 * 0x30,
                       (longlong)_Dst + 0x70);
            uVar6 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar6;
          } while (uVar6 < *(uint *)((longlong)_Dst + 0x38));
        }
        uVar6 = 0;
        if (*(int *)((longlong)_Dst + 0x3c) != 0) {
          do {
            local_60 = 0;
            local_68 = 0;
            lVar1 = *(longlong *)((longlong)_Dst + 0xd8);
            lVar4 = NdisAllocateNetBufferAndNetBufferList
                              (*(undefined8 *)((longlong)_Dst + 0x128),0,0,0);
            *(longlong *)((ulonglong)uVar6 * 0x30 + lVar1 + 0x20) = lVar4;
            if (lVar4 == 0) goto LAB_1c0009b64;
            ExInterlockedInsertTailList(lVar2);
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)((longlong)_Dst + 0x3c));
        }
        pcStack_50 = TXSendCompleteDpc;
        local_58 = 0x5f4e444b00180197;
        local_48 = _Dst;
        iVar3 = NdisAllocateTimerObject(NdisDriverHandle,&local_58,(longlong)_Dst + 0xc0);
        if (iVar3 == 0) {
          pcStack_50 = RxReceiveIndicateDpc;
          iVar3 = NdisAllocateTimerObject(NdisDriverHandle,&local_58,(longlong)_Dst + 0x130);
          if (iVar3 == 0) {
            pcStack_50 = NICAsyncResetOrPauseDpc;
            uVar5 = NdisAllocateTimerObject(NdisDriverHandle,&local_58,(longlong)_Dst + 0x138);
            if ((int)uVar5 == 0) goto LAB_1c0009b69;
          }
        }
        uVar5 = 0xc0000001;
        goto LAB_1c0009b69;
      }
    }
  }
LAB_1c0009b64:
  uVar5 = 0xc000009a;
LAB_1c0009b69:
  *param_1 = _Dst;
  return uVar5;
}



===== NICFreeAdapter @ 1c0009ba0 =====

void NICFreeAdapter(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x138) != 0) {
    NdisFreeTimerObject();
    *(undefined8 *)(param_1 + 0x138) = 0;
  }
  if (*(longlong *)(param_1 + 0x130) != 0) {
    NdisFreeTimerObject();
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  if (*(longlong *)(param_1 + 0xc0) != 0) {
    NdisFreeTimerObject();
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  while( true ) {
    lVar1 = ExInterlockedRemoveHeadList(param_1 + 0xe0,param_1 + 0xf0);
    if (lVar1 == 0) break;
    NdisFreeNetBufferList(*(undefined8 *)(lVar1 + 0x10));
  }
  if (*(longlong *)(param_1 + 0x128) != 0) {
    NdisFreeNetBufferListPool();
    *(undefined8 *)(param_1 + 0x128) = 0;
  }
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 0xd8),*(int *)(param_1 + 0x3c) * 0x30,0);
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 0x58),*(int *)(param_1 + 0x38) * 0x30,0);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  NdisFreeMemory(param_1,0x2d0,0);
  return;
}



===== NICSetVisible @ 1c0009cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NICSetVisible(longlong param_1)

{
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined1 local_c8 [4];
  int local_c4;
  undefined8 local_c0;
  longlong local_b8 [2];
  wchar_t *local_a8;
  longlong local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_74;
  undefined1 *local_58;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_b8[1] = 0x20001e;
  local_c0 = 0;
  local_a8 = L"Characteristics";
  local_b8[0] = 0;
  local_c8[0] = 0;
  local_84 = 0;
  memset(&local_88,0,0x6c);
  local_98 = *(undefined8 *)(param_1 + 0x28);
  local_a0 = 0x1401a9;
  local_90 = 0;
  local_c4 = NdisOpenConfigurationEx(local_b8 + 3,&local_c0);
  if (local_c4 == 0) {
    local_d8 = 0;
    NdisReadConfiguration(&local_c4,local_b8,local_c0,local_b8 + 1);
    if (-1 < local_c4) {
      *(uint *)(local_b8[0] + 8) = *(uint *)(local_b8[0] + 8) & 0xfffffff7;
      NdisWriteConfiguration(&local_c4,local_c0,local_b8 + 1,local_b8[0]);
      memset(&local_88,0,0x70);
      local_58 = local_c8;
      local_88 = 0x700198;
      local_74 = 0x40020063;
      local_50 = 1;
      NdisMIndicateStatusEx(*(undefined8 *)(param_1 + 0x28),&local_88);
    }
    NdisCloseConfiguration(local_c0);
  }
  else {
    local_c4 = -0x3fffffff;
  }
  return local_c4;
}



===== _tlgEnableCallback @ 1c0009e50 =====

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



===== NICStartTheDatapath @ 1c0009ecc =====

void NICStartTheDatapath(undefined8 *param_1)

{
  MPAttachAdapter(param_1);
  if (param_1[6] != 0) {
    *(uint *)(param_1 + 10) = *(uint *)(param_1 + 10) | 1;
    TXScheduleTheSendComplete((longlong)param_1);
    RXScheduleTheReceiveIndication((longlong)param_1);
  }
  return;
}



===== NICStopTheDatapath @ 1c0009f08 =====

void NICStopTheDatapath(longlong *param_1,undefined4 param_2)

{
  char cVar1;
  undefined8 local_res8;
  
  local_res8 = 0;
  *(uint *)(param_1 + 10) = *(uint *)(param_1 + 10) & 0xfffffffe;
  NdisCancelTimerObject(param_1[0x27]);
  if ((int)param_1[10] != 0) {
    cVar1 = NdisCancelTimerObject(param_1[0x26]);
    if (cVar1 == '\0') {
      local_res8 = 0xffffffffffffb1e0;
      while ((int)param_1[10] != 0) {
        KeDelayExecutionThread(0,0,&local_res8);
      }
    }
    else {
      *(undefined4 *)(param_1 + 10) = 0;
    }
  }
  NdisCancelTimerObject(param_1[0x18]);
  KeFlushQueuedDpcs();
  MPDetachAdapter(param_1);
  TXFlushSendQueue((longlong)param_1,param_2);
  RxFlushReceiveQueue((longlong)param_1);
  cVar1 = KdPollBreakIn();
  if (cVar1 != '\0') {
    DbgBreakPointWithStatus(1);
  }
  TXFlushSendQueue((longlong)param_1,param_2);
  RxFlushReceiveQueue((longlong)param_1);
  return;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
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

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  ulonglong local_res8;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined4 local_120;
  wchar_t *local_118;
  ulonglong *local_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  KdNicDriverObject = param_1;
  KdNicRegistryPath = param_2;
  memset(&DAT_1c0006150,0,0xf0);
  local_res8 = CONCAT44(local_res8._4_4_,0xfffffffc);
  local_128 = 0;
  local_118 = L"PhysicalMedium802_3";
  local_110 = &local_res8;
  DAT_1c0006148 = &GlobalData;
  _GlobalData = &GlobalData;
  local_120 = 0x134;
  local_108 = 0x4000000;
  local_100 = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_138 = 0;
  uStack_130 = 0;
  RtlInitUnicodeString(&local_138,L"RtlQueryRegistryValuesEx");
  pcVar4 = (code *)MmGetSystemRoutineAddress(&local_138);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar4)(1,L"kdnic",&local_128,0,0);
  iVar3 = 0;
  if (-1 < iVar1) {
    iVar3 = (int)local_res8;
  }
  if (iVar3 != 0) {
    DAT_1c0006200 = DAT_1c0006200 | 0x10;
  }
  local_118 = L"KdNic";
  local_110 = &local_res8;
  KdNetNicInterface = (short *)0x0;
  local_res8 = 0xfffffff8;
  local_128 = 0;
  local_120 = 0x134;
  local_108 = 0xb000000;
  local_100 = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_138 = 0;
  uStack_130 = 0;
  RtlInitUnicodeString(&local_138,L"RtlQueryRegistryValuesEx");
  pcVar4 = (code *)MmGetSystemRoutineAddress(&local_138);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = RtlQueryRegistryValues_exref;
  }
  iVar3 = (*pcVar4)(1,L"KDNET\\KDNIC",&local_128,0,0);
  if (-1 < iVar3) {
    KdNetNicInterface = (short *)MmGetVirtualForPhysical(local_res8);
  }
  if (((KdNetNicInterface == (short *)0x0) || (*KdNetNicInterface != 3)) ||
     (KdNetNicInterface[1] != 0x60)) {
    *(code **)(param_1 + 0x68) = DriverUnload;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = KdNicAddDevice;
    *(code **)(param_1 + 0x148) = KdNicDispatchPnp;
    *(code **)(param_1 + 0x120) = KdNicDispatchPower;
    *(code **)(param_1 + 0x128) = KdNicDispatchWmi;
LAB_1c000b47c:
    iVar3 = 0;
  }
  else {
    local_res8 = CONCAT44(local_res8._4_4_,20000);
    GetSystemTimerResolution((uint *)&local_res8);
    ExSetTimerResolution(local_res8 & 0xffffffff,1);
    DAT_1c0006200 = DAT_1c0006200 | 8;
    uVar2 = NdisGetVersion();
    ExInitializeNPagedLookasideList
              (&DAT_1c0006180,HWFrameAllocate,HWFrameFree,~-(uint)(uVar2 < 0x6001e) & 0x200,0x600,
               0x464e444b,0);
    DAT_1c0006200 = DAT_1c0006200 | 2;
    local_b8 = 0x98028a;
    local_b0 = 0;
    local_b4 = 0x2041406;
    local_a8 = MPSetOptions;
    local_a0 = MPInitializeEx;
    local_98 = MPHaltEx;
    local_90 = DriverUnload;
    local_88 = MPPause;
    local_80 = MPRestart;
    local_78 = MPOidRequest;
    local_70 = MPSendNetBufferLists;
    local_68 = MPReturnNetBufferLists;
    local_60 = _guard_check_icall;
    local_58 = MPCheckForHangEx;
    local_50 = MPResetEx;
    local_48 = MPDevicePnpEventNotify;
    local_40 = _guard_check_icall;
    local_38 = _guard_check_icall;
    local_30 = 0;
    uStack_28 = 0;
    iVar3 = NdisMRegisterMiniportDriver(param_1,param_2,&GlobalData,&local_b8,&NdisDriverHandle);
    if (iVar3 == 0) {
      DAT_1c0006200 = DAT_1c0006200 | 4;
      DAT_1c0006150 = NdisAllocateRWLock(NdisDriverHandle);
      if (DAT_1c0006150 != 0) {
        DAT_1c0006200 = DAT_1c0006200 | 1;
        goto LAB_1c000b47c;
      }
      iVar3 = -0x3fffff66;
    }
    else if (-1 < iVar3) {
      return iVar3;
    }
    DriverUnload();
  }
  return iVar3;
}


