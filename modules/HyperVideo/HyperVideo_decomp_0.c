
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __GSHandlerCheck @ 1c0001030 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001054 =====

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



===== __cpu_features_init @ 1c00010d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000113a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010da) */

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



===== HvdDdiCommitVidPn @ 1c00011a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong HvdDdiCommitVidPn(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined8 *puVar13;
  int iVar14;
  int iVar15;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50 [2];
  
  local_68 = 0;
  local_50[0] = 0;
  local_60 = 0;
  local_58 = 0;
  lVar6 = *(longlong *)(param_1 + 0x290);
  lVar12 = 0x2b8;
  if (*(int *)(param_2 + 1) == 2) {
    lVar12 = 0x2ca;
  }
  puVar13 = (undefined8 *)(lVar12 + param_1);
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(lVar6 + 0x2268);
  if ((*(uint *)(param_2 + 3) & 1) == 0) {
    uVar8 = (**(code **)(param_1 + 0xc0))(*param_2,1,local_50);
    uVar11 = (ulonglong)uVar8;
    if (-1 < (int)uVar8) {
      uVar8 = (**(code **)(local_50[0] + 0x10))
                        (*param_2,*(undefined4 *)(param_2 + 1),&local_60,&local_58);
      uVar11 = (ulonglong)uVar8;
      if (-1 < (int)uVar8) {
        uVar8 = (**(code **)(local_58 + 0x18))(local_60,&local_68);
        uVar11 = (ulonglong)uVar8;
        if (-1 < (int)uVar8) {
          if (local_68 == 0) {
            uVar11 = 0;
            goto LAB_1c000142d;
          }
          plVar1 = (longlong *)(param_1 + 0x2a8);
          lVar6 = *plVar1;
          if (lVar6 != 0) {
            *plVar1 = 0;
            uVar8 = (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x38),lVar6);
            uVar11 = (ulonglong)uVar8;
            if ((int)uVar8 < 0) {
              *plVar1 = lVar6;
              goto LAB_1c0001413;
            }
          }
          *(undefined4 *)((longlong)puVar13 + 1) = 0;
          *(undefined1 *)puVar13 = 1;
          iVar2 = *(int *)(local_68 + 8);
          *(int *)((longlong)puVar13 + 6) = iVar2;
          *(undefined4 *)((longlong)puVar13 + 10) = *(undefined4 *)(local_68 + 0xc);
          *(undefined1 *)((longlong)puVar13 + 5) = 0x20;
          *(int *)((longlong)puVar13 + 0xe) = iVar2 * 4;
          iVar14 = *(int *)(param_1 + 0x2ec);
          if (iVar14 == 3) {
            iVar14 = 2;
          }
          uVar8 = *(uint *)(param_1 + 0x2c2);
          if (*(uint *)(param_1 + 0x2c2) < *(uint *)(param_1 + 0x2d4)) {
            uVar8 = *(uint *)(param_1 + 0x2d4);
          }
          if (*(int *)(param_2 + 1) == 2) {
            iVar10 = *(int *)(param_1 + 0x2be);
            iVar15 = iVar2;
          }
          else {
            iVar15 = *(int *)(param_1 + 0x2d0);
            iVar10 = iVar2;
          }
          *(ulonglong *)(param_1 + 0x2b0) =
               (ulonglong)
               (((iVar14 + -1) * *(int *)(param_1 + 0x308) + iVar10 * iVar14 + iVar15) * uVar8 * 4)
               + 0xfff & 0xfffffffffffff000;
          uVar7 = (**(code **)(param_1 + 0x58))
                            (*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x298),
                             *(undefined4 *)(param_1 + 0x2b0),0,0,1,plVar1);
          uVar11 = (ulonglong)uVar7;
          if (-1 < (int)uVar7) {
            memset(*(void **)(param_1 + 0x2a8),0,*(size_t *)(param_1 + 0x2b0));
            uVar3 = *(undefined4 *)((longlong)puVar13 + 0xe);
            uVar4 = *(undefined4 *)((longlong)puVar13 + 6);
            uVar5 = *(undefined4 *)((longlong)puVar13 + 10);
            iVar15 = (iVar14 + -1) * *(int *)(param_1 + 0x308) + iVar10 * iVar14 + iVar15;
            *(int *)((longlong)puVar13 + 6) = iVar15;
            *(int *)((longlong)puVar13 + 0xe) = iVar15 * 4;
            *(uint *)((longlong)puVar13 + 10) = uVar8;
            uVar9 = SynthVidReportSituationUpdate(*(undefined8 **)(param_1 + 0x290),puVar13);
            uVar11 = uVar9 & 0xffffffff;
            if (-1 < (int)uVar9) {
              *(undefined4 *)((longlong)puVar13 + 0xe) = uVar3;
              *(undefined4 *)((longlong)puVar13 + 10) = uVar5;
              *(undefined4 *)((longlong)puVar13 + 6) = uVar4;
              uVar8 = HvdSendInvisibleCursor(param_1);
              uVar11 = (ulonglong)uVar8;
            }
          }
        }
      }
    }
  }
  else {
    uVar11 = 0;
  }
LAB_1c0001413:
  if (local_68 != 0) {
    (**(code **)(local_58 + 0x20))(local_60);
  }
LAB_1c000142d:
  if (local_60 != 0) {
    (**(code **)(local_50[0] + 0x18))(*param_2);
  }
  ExReleaseFastMutexUnsafe(*(longlong *)(param_1 + 0x290) + 0x2268);
  KeLeaveCriticalRegion();
  return uVar11;
}



===== _guard_check_icall @ 1c0001490 =====

void _guard_check_icall(void)

{
  return;
}



===== HvdDdiStopDeviceAndReleasePostDisplayOwnership @ 1c00014a0 =====

ulonglong HvdDdiStopDeviceAndReleasePostDisplayOwnership(longlong param_1,int param_2,int *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x2e8) == '\0') {
    uVar1 = 0xc00000bb;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    iVar3 = *(int *)(param_1 + 0x2ec);
    if (iVar3 == 3) {
      iVar3 = 2;
    }
    *param_3 = iVar3 * *(int *)(param_1 + 0x2be) + (iVar3 + -1) * *(int *)(param_1 + 0x308) +
               *(int *)(param_1 + 0x2d0);
    uVar2 = *(uint *)(param_1 + 0x2c2);
    if (*(uint *)(param_1 + 0x2c2) < *(uint *)(param_1 + 0x2d4)) {
      uVar2 = *(uint *)(param_1 + 0x2d4);
    }
    param_3[1] = uVar2;
    param_3[2] = iVar3 * *(int *)(param_1 + 0x2c6) + (iVar3 + -1) * *(int *)(param_1 + 0x308) * 4 +
                 *(int *)(param_1 + 0x2d8);
    param_3[3] = 0x15;
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_1 + 0x298);
    param_3[6] = param_2;
    uVar1 = HvdDdiStopDevice(param_1);
  }
  return uVar1;
}



===== HvdDdiSystemDisplayEnable @ 1c0001570 =====

ulonglong HvdDdiSystemDisplayEnable
                    (longlong param_1,undefined8 param_2,undefined8 param_3,int *param_4,
                    uint *param_5,undefined4 *param_6)

{
  byte bVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  if ((*(char *)(param_1 + 0x2dc) == '\0') || (*(longlong *)(param_1 + 0x2a8) == 0)) {
    uVar5 = 0xc0000001;
  }
  else {
    if (*(longlong *)(param_1 + 0x2e0) == 0) {
      bVar1 = in(0x3cc);
      out((ushort)(bVar1 & 1) * 0x20 + 0x3b4,0xbd73);
      *param_4 = 0x280;
      uVar3 = 0x1e0;
    }
    else {
      uVar2 = CrashHvdInitialize(param_1);
      uVar5 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        return uVar5;
      }
      iVar4 = *(int *)(param_1 + 0x2ec);
      if (iVar4 == 3) {
        iVar4 = 2;
      }
      *param_4 = (iVar4 + -1) * *(int *)(param_1 + 0x308) + iVar4 * *(int *)(param_1 + 0x2be) +
                 *(int *)(param_1 + 0x2d0);
      uVar3 = *(uint *)(param_1 + 0x2c2);
      if (*(uint *)(param_1 + 0x2c2) < *(uint *)(param_1 + 0x2d4)) {
        uVar3 = *(uint *)(param_1 + 0x2d4);
      }
    }
    *param_5 = uVar3;
    *param_6 = 0x15;
  }
  return uVar5;
}



===== HvdDdiSystemDisplayWrite @ 1c0001660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HvdDdiSystemDisplayWrite
               (longlong param_1,void *param_2,int param_3,uint param_4,uint param_5,uint param_6,
               uint param_7)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  void *_Dst;
  undefined1 auStack_a8 [32];
  uint local_88;
  int local_84;
  longlong local_80;
  void *local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  uint local_56;
  uint local_52;
  uint local_4e;
  uint local_4a;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  if (*(longlong *)(param_1 + 0x2e0) == 0) {
    uVar5 = 0x280;
    uVar7 = 0x1e0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x2ec);
    if (iVar3 == 3) {
      iVar3 = 2;
    }
    uVar5 = (iVar3 + -1) * *(int *)(param_1 + 0x308) + iVar3 * *(int *)(param_1 + 0x2be) +
            *(int *)(param_1 + 0x2d0);
    uVar7 = *(uint *)(param_1 + 0x2c2);
    if (*(uint *)(param_1 + 0x2c2) < *(uint *)(param_1 + 0x2d4)) {
      uVar7 = *(uint *)(param_1 + 0x2d4);
    }
  }
  iVar1 = (param_3 - uVar5) + param_6;
  iVar3 = param_3;
  local_88 = param_4;
  local_84 = param_3;
  local_70 = param_2;
  local_68 = param_1;
  if ((iVar1 < 1) || (iVar3 = param_3 - iVar1, -1 < iVar3)) {
    iVar1 = (param_4 - uVar7) + param_7;
    uVar4 = param_4;
    if ((iVar1 < 1) || (uVar4 = param_4 - iVar1, -1 < (int)uVar4)) {
      _Dst = (void *)(*(longlong *)(param_1 + 0x2a8) +
                     ((ulonglong)(uVar5 * param_7) + (ulonglong)param_6) * 4);
      if (0 < (int)uVar4) {
        lVar2 = (ulonglong)(param_5 >> 2) * 4;
        uVar6 = (ulonglong)uVar4;
        local_80 = lVar2;
        do {
          memcpy(_Dst,param_2,(ulonglong)(uint)(iVar3 * 4));
          param_2 = (void *)((longlong)param_2 + lVar2);
          _Dst = (void *)((longlong)_Dst + (ulonglong)uVar5 * 4);
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
  }
  if (*(longlong *)(local_68 + 0x2e0) != 0) {
    local_60 = 10;
    local_58 = 0x100;
    local_56 = param_6;
    local_52 = param_7;
    local_4e = uVar5;
    if (param_6 < uVar5 - local_84) {
      local_4e = param_6 + local_84;
    }
    local_5c = 0x1a;
    local_4a = uVar7;
    if (param_7 < uVar7 - local_88) {
      local_4a = local_88 + param_7;
    }
    CrashHvdSendMessage(local_68,&local_60,0x1a);
  }
  return;
}



===== HvdSkipRestoringMonitorData @ 1c0001838 =====

undefined1 HvdSkipRestoringMonitorData(uint param_1,int param_2,int param_3)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_1;
  if ((&g_MonitorData)[uVar1 * 2] != 0) {
    if ((*(int *)(&DAT_1c0005168 + uVar1 * 0x10) == param_2) &&
       (*(int *)(&DAT_1c000516c + uVar1 * 0x10) == param_3)) {
      return 0;
    }
    ExFreePoolWithTag((&g_MonitorData)[uVar1 * 2],0);
    (&g_MonitorData)[uVar1 * 2] = 0;
  }
  return 1;
}



===== UpdateEdidCrc @ 1c0001890 =====

void UpdateEdidCrc(char *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  
  cVar2 = '\0';
  lVar4 = 0x7f;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    cVar2 = cVar2 + cVar1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  param_1[0x7f] = -cVar2;
  return;
}



===== HvdBlit32BppTo32Bpp @ 1c00018b8 =====

undefined8
HvdBlit32BppTo32Bpp(longlong param_1,longlong param_2,uint param_3,int *param_4,int param_5,
                   undefined8 param_6,uint param_7,undefined8 param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *_Src;
  int iVar4;
  int iVar5;
  void *_Dst;
  
  iVar5 = 0;
  iVar1 = param_4[2];
  iVar2 = param_4[3];
  iVar3 = *param_4;
  iVar4 = param_4[1];
  if (param_9 == 1) {
    iVar5 = param_5 + param_10;
  }
  else if (param_9 == 2) {
    iVar5 = param_10 + param_5 * 2;
  }
  _Dst = (void *)(param_1 + (ulonglong)(iVar4 * param_7 + iVar5 + iVar3) * 4);
  _Src = (void *)((ulonglong)(iVar4 * param_3 + iVar3 * 4) + param_2);
  for (; iVar4 < iVar2; iVar4 = iVar4 + 1) {
    memcpy(_Dst,_Src,(longlong)((iVar1 - iVar3) * 4));
    _Src = (void *)((longlong)_Src + (ulonglong)param_3);
    _Dst = (void *)((longlong)_Dst + (ulonglong)param_7 * 4);
  }
  return 0;
}



===== CrashHvdInitialize @ 1c00019e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CrashHvdInitialize(longlong param_1)

{
  undefined8 *puVar1;
  char cVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_78 [32];
  int *local_58;
  int local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_30 = 0;
  local_2c = 0;
  cVar2 = (*(code *)(*(undefined8 **)(param_1 + 0x2e0))[1])(**(undefined8 **)(param_1 + 0x2e0));
  if (cVar2 == '\0') {
LAB_1c0001a2e:
    uVar3 = 0xc0000001;
  }
  else {
    local_28 = 1;
    local_24 = 0xc;
    local_20 = 0x50003;
    uVar3 = CrashHvdSendMessage(param_1,&local_28,0xc);
    if (-1 < (int)uVar3) {
      puVar1 = *(undefined8 **)(param_1 + 0x2e0);
      iVar5 = 20000;
      local_48[0] = 0;
      local_40 = 0;
      while( true ) {
        local_48[1] = 0xe;
        local_58 = local_48 + 1;
        cVar2 = (*(code *)puVar1[3])(*puVar1,local_48,&local_40,&local_38);
        if (cVar2 != '\0') break;
        if ((local_48[0] != 0) || (iVar5 < 1)) goto LAB_1c0001a2e;
        iVar5 = iVar5 + -1;
        KeStallExecutionProcessor(0x32);
      }
      uVar3 = 0xc0000001;
      if ((int)local_38 == 2) {
        uVar4 = 0;
        if ((char)local_2c != '\x02') {
          uVar4 = 0xc0000001;
        }
        uVar3 = (ulonglong)uVar4;
      }
    }
  }
  return uVar3;
}



===== CrashHvdSendMessage @ 1c0001afc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashHvdSendMessage(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  
  puVar1 = *(undefined8 **)(param_1 + 0x2e0);
  iVar3 = 20000;
  while( true ) {
    cVar2 = (*(code *)puVar1[2])(*puVar1,1,0,param_2,param_3,0,0);
    if (cVar2 != '\0') {
      return 0;
    }
    if (iVar3 < 1) break;
    iVar3 = iVar3 + -1;
    KeStallExecutionProcessor(0x32);
  }
  return 0xc0000001;
}



===== SynthVidLockDirt @ 1c0001b94 =====

void SynthVidLockDirt(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x2268);
  return;
}



===== SynthVidUnlockDirt @ 1c0001bcc =====

void SynthVidUnlockDirt(longlong param_1)

{
  ExReleaseFastMutexUnsafe(param_1 + 0x2268);
  KeLeaveCriticalRegion();
  return;
}



===== SynthVidpAcquireWriteLock @ 1c0001bfc =====

void SynthVidpAcquireWriteLock(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x2228);
  return;
}



===== SynthVidpGetWriteBufferLocked @ 1c0001c34 =====

longlong SynthVidpGetWriteBufferLocked(longlong param_1)

{
  return param_1 + 0x208;
}



===== SynthVidpOnFeatureRequest @ 1c0001c44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynthVidpOnFeatureRequest(longlong param_1,longlong param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  cVar1 = *(char *)(param_2 + 8);
  *(char *)(param_1 + 0x22b8) = cVar1;
  *(undefined1 *)(param_1 + 0x22b9) = *(undefined1 *)(param_2 + 9);
  *(undefined1 *)(param_1 + 0x22ba) = *(undefined1 *)(param_2 + 10);
  *(undefined1 *)(param_1 + 0x22bb) = *(undefined1 *)(param_2 + 0xb);
  local_28 = 0x54564800000001;
  if ((param_3 != '\0') && (*(char *)(param_1 + 0x2580) != '\0')) {
    if (cVar1 == '\x01') {
      if (*(char *)(param_1 + 0x2581) == '\0') {
        uVar5 = *(undefined8 *)(param_2 + 0x14);
        uStack_20 = 1;
        *(undefined8 *)(param_1 + 0x2500) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_1 + 0x2508) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x24);
        *(undefined8 *)(param_1 + 0x2510) = *(undefined8 *)(param_2 + 0x1c);
        *(undefined8 *)(param_1 + 0x2518) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x34);
        *(undefined8 *)(param_1 + 0x2520) = *(undefined8 *)(param_2 + 0x2c);
        *(undefined8 *)(param_1 + 0x2528) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x44);
        *(undefined8 *)(param_1 + 0x2530) = *(undefined8 *)(param_2 + 0x3c);
        *(undefined8 *)(param_1 + 0x2538) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x54);
        *(undefined8 *)(param_1 + 0x2540) = *(undefined8 *)(param_2 + 0x4c);
        *(undefined8 *)(param_1 + 0x2548) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 100);
        *(undefined8 *)(param_1 + 0x2550) = *(undefined8 *)(param_2 + 0x5c);
        *(undefined8 *)(param_1 + 0x2558) = uVar5;
        uVar2 = *(undefined4 *)(param_2 + 0x70);
        uVar3 = *(undefined4 *)(param_2 + 0x74);
        uVar4 = *(undefined4 *)(param_2 + 0x78);
        *(undefined4 *)(param_1 + 0x2560) = *(undefined4 *)(param_2 + 0x6c);
        *(undefined4 *)(param_1 + 0x2564) = uVar2;
        *(undefined4 *)(param_1 + 0x2568) = uVar3;
        *(undefined4 *)(param_1 + 0x256c) = uVar4;
        uVar2 = *(undefined4 *)(param_2 + 0x80);
        uVar3 = *(undefined4 *)(param_2 + 0x84);
        uVar4 = *(undefined4 *)(param_2 + 0x88);
        *(undefined4 *)(param_1 + 0x2570) = *(undefined4 *)(param_2 + 0x7c);
        *(undefined4 *)(param_1 + 0x2574) = uVar2;
        *(undefined4 *)(param_1 + 0x2578) = uVar3;
        *(undefined4 *)(param_1 + 0x257c) = uVar4;
        (**(code **)(param_1 + 0x22e0))(*(undefined8 *)(param_1 + 0x22c8),&local_28);
        *(undefined1 *)(param_1 + 0x2581) = 1;
      }
      else {
        uStack_20 = 0;
        (**(code **)(param_1 + 0x22e0))(*(undefined8 *)(param_1 + 0x22c8),&local_28);
        uVar5 = *(undefined8 *)(param_2 + 0x14);
        *(undefined8 *)(param_1 + 0x2500) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_1 + 0x2508) = uVar5;
        uStack_20 = CONCAT71(uStack_20._1_7_,1);
        uVar5 = *(undefined8 *)(param_2 + 0x24);
        *(undefined8 *)(param_1 + 0x2510) = *(undefined8 *)(param_2 + 0x1c);
        *(undefined8 *)(param_1 + 0x2518) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x34);
        *(undefined8 *)(param_1 + 0x2520) = *(undefined8 *)(param_2 + 0x2c);
        *(undefined8 *)(param_1 + 0x2528) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x44);
        *(undefined8 *)(param_1 + 0x2530) = *(undefined8 *)(param_2 + 0x3c);
        *(undefined8 *)(param_1 + 0x2538) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x54);
        *(undefined8 *)(param_1 + 0x2540) = *(undefined8 *)(param_2 + 0x4c);
        *(undefined8 *)(param_1 + 0x2548) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 100);
        *(undefined8 *)(param_1 + 0x2550) = *(undefined8 *)(param_2 + 0x5c);
        *(undefined8 *)(param_1 + 0x2558) = uVar5;
        uVar2 = *(undefined4 *)(param_2 + 0x70);
        uVar3 = *(undefined4 *)(param_2 + 0x74);
        uVar4 = *(undefined4 *)(param_2 + 0x78);
        *(undefined4 *)(param_1 + 0x2560) = *(undefined4 *)(param_2 + 0x6c);
        *(undefined4 *)(param_1 + 0x2564) = uVar2;
        *(undefined4 *)(param_1 + 0x2568) = uVar3;
        *(undefined4 *)(param_1 + 0x256c) = uVar4;
        uVar2 = *(undefined4 *)(param_2 + 0x80);
        uVar3 = *(undefined4 *)(param_2 + 0x84);
        uVar4 = *(undefined4 *)(param_2 + 0x88);
        *(undefined4 *)(param_1 + 0x2570) = *(undefined4 *)(param_2 + 0x7c);
        *(undefined4 *)(param_1 + 0x2574) = uVar2;
        *(undefined4 *)(param_1 + 0x2578) = uVar3;
        *(undefined4 *)(param_1 + 0x257c) = uVar4;
        (**(code **)(param_1 + 0x22e0))(*(undefined8 *)(param_1 + 0x22c8),&local_28);
      }
    }
    else if (*(char *)(param_1 + 0x2581) == '\x01') {
      uStack_20 = 0;
      (**(code **)(param_1 + 0x22e0))(*(undefined8 *)(param_1 + 0x22c8),&local_28);
      *(undefined1 *)(param_1 + 0x2581) = 0;
    }
  }
  return;
}



===== SynthVidpReadCompleted @ 1c0001e20 =====

undefined8 SynthVidpReadCompleted(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *_Src;
  undefined8 *puVar1;
  
  if (-1 < *(int *)(param_2 + 0x30)) {
    _Src = (int *)(param_3 + 0x18);
    if (*_Src == 9) {
      SynthVidpOnFeatureRequest(param_3,(longlong)_Src,*(longlong *)(param_2 + 0x38) != 0xc);
    }
    else {
      puVar1 = *(undefined8 **)(param_3 + 0x2260);
      *(undefined8 *)(param_3 + 0x2260) = 0;
      memcpy((void *)*puVar1,_Src,(ulonglong)*(uint *)(puVar1 + 1));
      *(undefined4 *)(puVar1 + 3) = *(undefined4 *)(param_2 + 0x38);
      KeSetEvent(puVar1[2],0,0);
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    IoQueueWorkItem(*(undefined8 *)(param_3 + 0x1a8),SynthVidpIssueRead,1,param_3);
  }
  return 0xc0000016;
}



===== SynthVidpReleaseWriteLock @ 1c0001ed4 =====

void SynthVidpReleaseWriteLock(longlong param_1)

{
  ExReleaseFastMutexUnsafe(param_1 + 0x2228);
  KeLeaveCriticalRegion();
  return;
}



===== SynthVidpWriteCompleted @ 1c0001f10 =====

undefined8 SynthVidpWriteCompleted(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== DlpGetServiceNameInSystemSpace @ 1c0001f3c =====

undefined8 * DlpGetServiceNameInSystemSpace(void)

{
  wchar_t *_Dst;
  
  _Dst = (wchar_t *)ExAllocatePoolWithTag(0x401,0x78,0x706d6c44);
  if (ExPoolZeroingNativelySupported == '\0') {
    if (_Dst == (wchar_t *)0x0) {
      return (undefined8 *)0x0;
    }
    memset(_Dst,0,0x78);
  }
  else if (_Dst == (wchar_t *)0x0) {
    return (undefined8 *)0x0;
  }
  builtin_wcsncpy(_Dst,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\DXGKrnl",0x3c);
  return (undefined8 *)_Dst;
}



===== DlpLoadDxgkrnl @ 1c0001ff0 =====

int DlpLoadDxgkrnl(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar4 = 10;
  puVar3 = DlpGetServiceNameInSystemSpace();
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    RtlInitUnicodeString(&local_48,puVar3);
    iVar1 = ZwLoadDriver(&local_48);
    ExFreePoolWithTag(puVar3,0);
    if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar2 = iVar1, iVar1 == -0x3ffffef2)) {
      RtlInitUnicodeString(&local_38,L"\\Device\\DxgKrnl");
      do {
        iVar2 = IoGetDeviceObjectPointer(&local_38,0xc0000000,param_1,param_2);
        if ((-1 < iVar2) || (iVar1 != -0x3ffffef2)) break;
        local_res18[0] = 0xffffffffffff3cb0;
        KeDelayExecutionThread(0,0,local_res18);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (iVar2 < 0) {
        if (iVar1 != -0x3ffffef2) {
          DlpUnloadDxgkrnl();
        }
      }
      else if (iVar1 == -0x3ffffef2) {
        iVar2 = -0x3ffffef2;
      }
    }
  }
  return iVar2;
}



===== DlpUnloadDxgkrnl @ 1c0002130 =====

void DlpUnloadDxgkrnl(void)

{
  undefined8 *puVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  puVar1 = DlpGetServiceNameInSystemSpace();
  if (puVar1 != (undefined8 *)0x0) {
    RtlInitUnicodeString(&local_18,puVar1);
    ZwUnloadDriver(&local_18);
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== DxgkInitializeDisplayOnlyDriver @ 1c0002190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DxgkInitializeDisplayOnlyDriver(longlong param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined8 local_res8;
  longlong local_res20;
  
  local_res20 = 0;
  bVar4 = false;
  local_res8 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (uint *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    uVar1 = *param_3;
    if (((((uVar1 - 0x1052 < 2) || (uVar1 == 0x2005)) ||
         ((uVar1 == 0x300e || ((uVar1 - 0x4002 < 2 || (uVar1 == 0x5023)))))) ||
        ((uVar1 == 0x6003 ||
         ((((((uVar1 - 0x6010 < 2 || (uVar1 == 0x700a)) || (uVar1 == 0x8001)) ||
            ((uVar1 == 0x9006 || (uVar1 == 0xa00b)))) ||
           ((uVar1 == 0xb004 || ((uVar1 == 0xc004 || (uVar1 == 0xd001)))))) || (uVar1 == 0xe003)))))
        ) || (((uVar1 == 0xf003 || (uVar1 == 0x10004)) || (0x11006 < uVar1)))) {
      iVar2 = DlpLoadDxgkrnl(&local_res20,&local_res8);
      if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3ffffef2)) {
        bVar4 = iVar2 != -0x3ffffef2;
        uVar3 = DlpCallSyncDeviceIoControl(local_res8);
        iVar2 = (int)uVar3;
      }
      if (local_res20 != 0) {
        ObfDereferenceObject();
      }
      if (iVar2 < 0) {
        if (bVar4) {
          DlpUnloadDxgkrnl();
        }
      }
      else {
        MiniportStartDevice = *(undefined8 *)(param_3 + 4);
        *(code **)(param_3 + 4) = DlpStartDevice;
        iVar2 = (*(code *)0x0)(param_1,param_2,param_3);
      }
    }
    else {
      iVar2 = -0x3fffffa7;
    }
  }
  return iVar2;
}



===== __security_check_cookie @ 1c0002370 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00023b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00023e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00023e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002410 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0002480 =====

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



===== __memset_repmovs @ 1c00025c0 =====

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



===== __memset_query @ 1c0002640 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00026c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002800 =====

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



===== __memset_spec_plain @ 1c0002880 =====

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



===== memcpy @ 1c00029c0 =====

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



===== HvdDdiAddDevice @ 1c0008010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 HvdDdiAddDevice(undefined8 param_1,undefined8 *param_2)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 *puVar6;
  code *pcVar7;
  char *pcVar8;
  undefined4 local_res18 [2];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [8];
  undefined4 local_90;
  wchar_t *local_88;
  uint *local_80;
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 local_68;
  
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x318,0x445648);
  if (puVar6 == (undefined4 *)0x0) {
    return 0xc0000017;
  }
  *puVar6 = 0x445648;
  piVar1 = puVar6 + 0xbd;
  *(undefined8 *)(puVar6 + 2) = param_1;
  puVar2 = puVar6 + 0xbf;
  *puVar2 = 0;
  puVar3 = puVar6 + 0xbb;
  *(undefined1 *)(puVar6 + 0xb7) = 0;
  piVar4 = puVar6 + 0xc0;
  *(undefined8 *)(puVar6 + 0xb8) = 0;
  puVar5 = puVar6 + 0xbc;
  *piVar1 = 0;
  *piVar4 = 0;
  puVar6[0xbe] = 0;
  puVar6[0xc1] = 0;
  *puVar3 = 1;
  *puVar5 = 0x400;
  *(undefined8 *)(puVar6 + 0xc2) = 10;
  local_res18[0] = 0;
  memset(local_98,0,0x70);
  local_88 = L"MonitorCount";
  local_70 = local_res18;
  local_90 = 0x120;
  local_78 = 0x4000000;
  local_68 = 4;
  local_a8 = 0;
  uStack_a0 = 0;
  local_80 = puVar3;
  RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
  pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
  if (pcVar7 == (code *)0x0) {
    pcVar7 = RtlQueryRegistryValues_exref;
  }
  (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
  if (2 < *puVar3 - 1) goto LAB_1c0008626;
  local_88 = L"HorizontalSizeInCm";
  local_a8 = 0;
  uStack_a0 = 0;
  local_80 = (uint *)piVar1;
  RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
  pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
  if (pcVar7 == (code *)0x0) {
    pcVar7 = RtlQueryRegistryValues_exref;
  }
  (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
  local_88 = L"VerticalSizeInCm";
  local_a8 = 0;
  uStack_a0 = 0;
  local_80 = (uint *)piVar4;
  RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
  pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
  if (pcVar7 == (code *)0x0) {
    pcVar7 = RtlQueryRegistryValues_exref;
  }
  (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
  local_88 = L"InternalDisplay";
  local_80 = puVar6 + 0xc3;
  local_a8 = 0;
  uStack_a0 = 0;
  RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
  pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
  if (pcVar7 == (code *)0x0) {
    pcVar7 = RtlQueryRegistryValues_exref;
  }
  (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
  if (*puVar3 == 1) {
    local_88 = L"VirtualModeSupport";
    local_80 = puVar6 + 0xc4;
    local_a8 = 0;
    uStack_a0 = 0;
    RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
    pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
    if (pcVar7 == (code *)0x0) {
      pcVar7 = RtlQueryRegistryValues_exref;
    }
    (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
  }
  if ((*puVar3 < 2) && ((*piVar1 == 0 || (*piVar4 == 0)))) {
LAB_1c0008449:
    if (1 < *puVar3) {
      *(undefined1 *)(puVar6 + 0xc4) = 1;
      local_88 = L"MaskWidth";
      local_80 = puVar6 + 0xc2;
      local_a8 = 0;
      uStack_a0 = 0;
      RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
      pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
      if (pcVar7 == (code *)0x0) {
        pcVar7 = RtlQueryRegistryValues_exref;
      }
      (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
    }
    if (puVar6[0xbb] != 3) {
LAB_1c00085fc:
      *param_2 = puVar6;
      return 0;
    }
    puVar6[0xbe] = 0x400;
    local_88 = L"HorizontalResolutionAuxiliary";
    local_80 = puVar6 + 0xbe;
    local_a8 = 0;
    uStack_a0 = 0;
    RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
    pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
    if (pcVar7 == (code *)0x0) {
      pcVar7 = RtlQueryRegistryValues_exref;
    }
    (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
    local_88 = L"VerticalResolutionAuxiliary";
    local_80 = puVar6 + 0xc1;
    local_a8 = 0;
    uStack_a0 = 0;
    RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
    pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
    if (pcVar7 == (code *)0x0) {
      pcVar7 = RtlQueryRegistryValues_exref;
    }
    (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
    if (((uint)puVar6[0xbe] < 100) || (puVar6[0xc1] - 1 < 99)) {
      if (g_TracingEnabled == '\0') goto LAB_1c0008626;
      pcVar8 = "HyperVideo: Auxiliary monitor resolution cannot be smaller than 100\n";
    }
    else {
      if (((puVar6[0xbe] & 1) == 0) && ((puVar6[0xc1] & 1) == 0)) goto LAB_1c00085fc;
      if (g_TracingEnabled == '\0') goto LAB_1c0008626;
      pcVar8 = "HyperVideo: Auxiliary monitor resolution has to be even number\n";
    }
  }
  else {
    local_88 = L"HorizontalResolution";
    local_a8 = 0;
    uStack_a0 = 0;
    local_80 = puVar5;
    RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
    pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
    if (pcVar7 == (code *)0x0) {
      pcVar7 = RtlQueryRegistryValues_exref;
    }
    (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
    local_88 = L"VerticalResolution";
    local_a8 = 0;
    uStack_a0 = 0;
    local_80 = puVar2;
    RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
    pcVar7 = (code *)MmGetSystemRoutineAddress(&local_a8);
    if (pcVar7 == (code *)0x0) {
      pcVar7 = RtlQueryRegistryValues_exref;
    }
    (*pcVar7)(2,L"Video\\Virtualization",local_98,0,0);
    if ((*puVar5 < 100) || (*puVar2 - 1 < 99)) {
      if (g_TracingEnabled == '\0') goto LAB_1c0008626;
      pcVar8 = "HyperVideo: Monitor resolution cannot be smaller than 100\n";
    }
    else {
      if (((*puVar2 | *puVar5) & 1) == 0) goto LAB_1c0008449;
      if (g_TracingEnabled == '\0') goto LAB_1c0008626;
      pcVar8 = "HyperVideo: Monitor resolution has to be even number\n";
    }
  }
  DbgPrint(pcVar8);
LAB_1c0008626:
  ExFreePoolWithTag(puVar6,0);
  return 0xc000000d;
}



===== HvdDdiDispatchIoRequest @ 1c0008670 =====

undefined8 HvdDdiDispatchIoRequest(void)

{
  return 0xc0000002;
}



===== HvdDdiEnumVidPnCofuncModality @ 1c0008680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HvdDdiEnumVidPnCofuncModality(longlong param_1,undefined8 *param_2)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  int *piVar4;
  uint uVar5;
  int *local_res8;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50 [2];
  
  local_res10 = 0;
  local_70 = 0;
  piVar4 = (int *)0x0;
  local_78 = 0;
  bVar1 = false;
  local_res8 = (int *)0x0;
  local_58 = 0;
  local_res18 = 0;
  local_68 = 0;
  local_50[0] = 0;
  local_res20 = 0;
  local_60 = 0;
  iVar2 = (**(code **)(param_1 + 0xc0))(*param_2,1,&local_res10);
  if (((-1 < iVar2) &&
      (iVar2 = (**(code **)(local_res10 + 8))(*param_2,&local_70,&local_78), -1 < iVar2)) &&
     (uVar5 = 0, *(int *)(param_1 + 0x2ec) != 0)) {
    do {
      if (uVar5 == 0) {
        iVar2 = (**(code **)(local_78 + 0x28))(local_70,&local_res8);
        if (iVar2 < 0) break;
      }
      else {
        if (piVar4 != (int *)0x0) {
          (**(code **)(local_78 + 0x40))(local_70,piVar4);
        }
        piVar4 = local_res8;
        local_res8 = (int *)0x0;
        iVar2 = (**(code **)(local_78 + 0x30))(local_70,piVar4,&local_res8);
        if ((iVar2 < 0) || (local_res8 == (int *)0x0)) break;
      }
      iVar2 = (**(code **)(local_res10 + 0x10))(*param_2,*local_res8,&local_res18,&local_68);
      if (((iVar2 < 0) || (iVar2 = (**(code **)(local_68 + 0x18))(local_res18,&local_58), iVar2 < 0)
          ) || ((iVar2 = (**(code **)(local_res10 + 0x38))
                                   (*param_2,local_res8[1],&local_res20,&local_60), iVar2 < 0 ||
                (iVar2 = (**(code **)(local_60 + 0x18))(local_res20,local_50), iVar2 < 0)))) break;
      if (((*(int *)(param_2 + 1) != 1) && (*(int *)((longlong)param_2 + 0xc) != *local_res8)) &&
         (local_58 == 0)) {
        iVar2 = (**(code **)(local_res10 + 0x18))(*param_2,local_res18);
        if (iVar2 < 0) break;
        local_res18 = 0;
        iVar2 = (**(code **)(local_res10 + 0x20))(*param_2,*local_res8,&local_res18,&local_68);
        if (iVar2 < 0) break;
        if (*(int *)(param_1 + 0x2ec) == 3) {
          plVar3 = &MonitorResolutions;
          if (*local_res8 == 2) {
            plVar3 = &DAT_1c00051b1;
          }
        }
        else {
          plVar3 = &SupportedResolutions;
        }
        iVar2 = HvdAddSourceModesToVidPn
                          (local_68,local_res18,local_50[0],
                           0x30001 < ((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) <<
                                      0x10 | (uint)(byte)*(undefined2 *)
                                                          (*(longlong *)(param_1 + 0x290) + 0x22a2))
                           ,plVar3);
        if ((iVar2 < 0) ||
           (iVar2 = (**(code **)(local_res10 + 0x28))(*param_2,*local_res8,local_res18), iVar2 < 0))
        break;
        local_res18 = 0;
      }
      if (((*(int *)(param_2 + 1) != 2) && (*(int *)(param_2 + 2) != local_res8[1])) &&
         (local_50[0] == 0)) {
        iVar2 = (**(code **)(local_res10 + 0x40))(*param_2,local_res20);
        if (iVar2 < 0) break;
        local_res20 = 0;
        iVar2 = (**(code **)(local_res10 + 0x48))(*param_2,local_res8[1],&local_res20,&local_60);
        if (iVar2 < 0) break;
        if (*(int *)(param_1 + 0x2ec) == 3) {
          plVar3 = &MonitorResolutions;
          if (local_res8[1] == 0x35648) {
            plVar3 = &DAT_1c00051b1;
          }
        }
        else {
          plVar3 = &SupportedResolutions;
        }
        iVar2 = HvdAddTargetModesToVidPn
                          (local_60,local_res20,local_58,
                           0x30001 < ((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) <<
                                      0x10 | (uint)(byte)*(undefined2 *)
                                                          (*(longlong *)(param_1 + 0x290) + 0x22a2))
                           ,plVar3);
        if ((iVar2 < 0) ||
           (iVar2 = (**(code **)(local_res10 + 0x50))(*param_2,local_res8[1],local_res20), iVar2 < 0
           )) break;
        local_res20 = 0;
      }
      if ((((*(int *)(param_2 + 1) != 3) || (*(int *)((longlong)param_2 + 0xc) != *local_res8)) ||
          (*(int *)(param_2 + 2) != local_res8[1])) && (local_res8[3] == 0xfe)) {
        bVar1 = true;
        local_res8[4] = 0;
        local_res8[4] = local_res8[4] | 1;
      }
      if ((((*(int *)(param_2 + 1) == 4) && (*(int *)((longlong)param_2 + 0xc) == *local_res8)) &&
          (*(int *)(param_2 + 2) == local_res8[1])) || (local_res8[5] != 0xfe)) {
        if (bVar1) goto LAB_1c0008ab0;
      }
      else {
        bVar1 = true;
        local_res8[6] = 0;
        local_res8[6] = local_res8[6] | 1;
        local_res8[6] = local_res8[6] | 0x10;
LAB_1c0008ab0:
        iVar2 = (**(code **)(local_78 + 0x38))(local_70,local_res8);
        if (iVar2 < 0) break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x2ec));
  }
  if (local_58 != 0) {
    (**(code **)(local_68 + 0x20))(local_res18);
  }
  if (local_res18 != 0) {
    (**(code **)(local_res10 + 0x18))(*param_2);
  }
  if (local_50[0] != 0) {
    (**(code **)(local_60 + 0x20))(local_res20);
  }
  if (local_res20 != 0) {
    (**(code **)(local_res10 + 0x40))(*param_2);
  }
  if (local_res8 != (int *)0x0) {
    (**(code **)(local_78 + 0x40))(local_70);
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(local_78 + 0x40))(local_70,piVar4);
  }
  return iVar2;
}



===== HvdDdiIsSupportedVidPn @ 1c0008b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HvdDdiIsSupportedVidPn(longlong param_1,longlong *param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 *local_res8;
  undefined8 local_res10;
  longlong local_res18;
  ulonglong local_res20;
  longlong local_38 [2];
  
  local_38[0] = 0;
  lVar3 = 0;
  local_res10 = 0;
  local_res8 = (undefined8 *)0x0;
  local_res20 = 0;
  local_res18 = 0;
  if (*param_2 == 0) {
    *(undefined1 *)(param_2 + 1) = 1;
    return 0;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  iVar1 = (**(code **)(param_1 + 0xc0))(*param_2,1,local_38);
  if (((-1 < iVar1) &&
      (iVar1 = (**(code **)(local_38[0] + 8))(*param_2,&local_res10,&local_res8), -1 < iVar1)) &&
     (iVar1 = (*(code *)*local_res8)(local_res10,&local_res20), -1 < iVar1)) {
    if (local_res20 == 0) {
      iVar1 = 0;
    }
    else {
      if ((*(uint *)(param_1 + 0x2ec) < local_res20) ||
         (iVar1 = (*(code *)local_res8[5])(local_res10,&local_res18), iVar1 < 0))
      goto LAB_1c0008cc4;
      for (uVar2 = 1; uVar2 < local_res20; uVar2 = uVar2 + 1) {
        if (lVar3 != 0) {
          (*(code *)local_res8[8])(local_res10,lVar3);
        }
        lVar3 = local_res18;
        local_res18 = 0;
        iVar1 = (*(code *)local_res8[6])(local_res10,lVar3,&local_res18);
        if (iVar1 < 0) goto LAB_1c0008cc4;
        if (local_res18 == 0) goto LAB_1c0008cde;
      }
    }
    *(undefined1 *)(param_2 + 1) = 1;
  }
LAB_1c0008cc4:
  if (local_res18 != 0) {
    (*(code *)local_res8[8])(local_res10);
  }
LAB_1c0008cde:
  if (lVar3 != 0) {
    (*(code *)local_res8[8])(local_res10,lVar3);
  }
  return iVar1;
}



===== HvdDdiPresentDisplayOnly @ 1c0008d10 =====

int HvdDdiPresentDisplayOnly(longlong param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if ((*(longlong *)(param_1 + 0x2a8) == 0) || (g_MonitorsTurnedOn == '\0')) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x2ec);
    uVar6 = 0;
    if (iVar7 == 3) {
      iVar7 = 2;
    }
    uVar8 = (iVar7 + -1) * *(int *)(param_1 + 0x308) + iVar7 * *(int *)(param_1 + 0x2be) +
            *(int *)(param_1 + 0x2d0);
    if (param_2[7] != 0) {
      do {
        uVar2 = HvdBlit32BppTo32Bpp(*(longlong *)(param_1 + 0x2a8),*(longlong *)(param_2 + 2),
                                    param_2[5],
                                    (int *)(*(longlong *)(param_2 + 8) +
                                           ((ulonglong)uVar6 * 3 + 1) * 8),*(int *)(param_1 + 0x2be)
                                    ,in_stack_ffffffffffffffb0,uVar8,in_stack_ffffffffffffffc0,
                                    *param_2,*(int *)(param_1 + 0x308));
        iVar5 = (int)uVar2;
        bVar9 = true;
        if (iVar5 < 0) goto LAB_1c0008f30;
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)param_2[7]);
    }
    uVar6 = 0;
    if (param_2[10] != 0) {
      do {
        uVar2 = HvdBlit32BppTo32Bpp(*(longlong *)(param_1 + 0x2a8),*(longlong *)(param_2 + 2),
                                    param_2[5],
                                    (int *)((ulonglong)uVar6 * 0x10 + *(longlong *)(param_2 + 0xc)),
                                    *(int *)(param_1 + 0x2be),in_stack_ffffffffffffffb0,uVar8,
                                    in_stack_ffffffffffffffc0,*param_2,*(int *)(param_1 + 0x308));
        iVar5 = (int)uVar2;
        bVar9 = true;
        if (iVar5 < 0) goto LAB_1c0008f30;
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)param_2[10]);
    }
    lVar3 = *(longlong *)(param_1 + 0x290);
    SynthVidLockDirt(lVar3);
    SynthVidpAcquireWriteLock(lVar3);
    lVar3 = SynthVidpGetWriteBufferLocked(lVar3);
    uVar4 = 0;
    *(undefined1 *)(lVar3 + 9) = 0;
    if (param_2[7] != 0) {
      do {
        iVar7 = (int)uVar4;
        puVar1 = (undefined8 *)(*(longlong *)(param_2 + 8) + 8 + uVar4 * 0x18);
        local_28 = *puVar1;
        uStack_20 = puVar1[1];
        if (*param_2 == 1) {
          iVar5 = *(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be);
LAB_1c0008e9e:
          local_28._4_4_ = (undefined4)((ulonglong)local_28 >> 0x20);
          local_28 = CONCAT44(local_28._4_4_,(int)local_28 + iVar5);
          uStack_20._4_4_ = (undefined4)((ulonglong)uStack_20 >> 0x20);
          uStack_20 = CONCAT44(uStack_20._4_4_,(int)uStack_20 + iVar5);
        }
        else if (*param_2 == 2) {
          iVar5 = *(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be) * 2;
          goto LAB_1c0008e9e;
        }
        SynthVidAddDirtRectangle(*(longlong *)(param_1 + 0x290),(int *)&local_28);
        uVar4 = (ulonglong)(iVar7 + 1U);
      } while (iVar7 + 1U < (uint)param_2[7]);
    }
    uVar4 = 0;
    if (param_2[10] != 0) {
      do {
        iVar7 = (int)uVar4;
        puVar1 = (undefined8 *)(*(longlong *)(param_2 + 0xc) + uVar4 * 0x10);
        local_28 = *puVar1;
        uStack_20 = puVar1[1];
        if (*param_2 == 1) {
          iVar5 = *(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be);
LAB_1c0008f03:
          local_28._4_4_ = (undefined4)((ulonglong)local_28 >> 0x20);
          local_28 = CONCAT44(local_28._4_4_,(int)local_28 + iVar5);
          uStack_20._4_4_ = (undefined4)((ulonglong)uStack_20 >> 0x20);
          uStack_20 = CONCAT44(uStack_20._4_4_,(int)uStack_20 + iVar5);
        }
        else if (*param_2 == 2) {
          iVar5 = *(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be) * 2;
          goto LAB_1c0008f03;
        }
        SynthVidAddDirtRectangle(*(longlong *)(param_1 + 0x290),(int *)&local_28);
        uVar4 = (ulonglong)(iVar7 + 1U);
      } while (iVar7 + 1U < (uint)param_2[10]);
    }
    uVar4 = SynthVidSendDirt(*(undefined8 **)(param_1 + 0x290));
    iVar5 = (int)uVar4;
    bVar9 = iVar5 < 0;
LAB_1c0008f30:
    iVar7 = 0;
    if (bVar9) {
      iVar7 = iVar5;
    }
  }
  return iVar7;
}



===== HvdDdiQueryAdapterInfo @ 1c0008f60 =====

undefined8 HvdDdiQueryAdapterInfo(longlong param_1,int *param_2)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  if (*param_2 == 1) {
    puVar2 = *(undefined8 **)(param_2 + 6);
    *puVar2 = 0xffffffffffffffff;
    *(undefined4 *)(puVar2 + 0x2a) = 0x1200;
    *(undefined1 *)(puVar2 + 0x43) = 1;
    *(undefined4 *)(puVar2 + 1) = 0;
    puVar2[2] = 0;
    *(undefined8 *)((longlong)puVar2 + 0x24) = 0;
    *(undefined4 *)(puVar2 + 3) = 0x60;
    *(undefined4 *)((longlong)puVar2 + 0x1c) = 0x60;
    puVar2[8] = 0;
    puVar2[9] = 0;
    *(undefined4 *)(puVar2 + 4) = 3;
    *(undefined8 *)((longlong)puVar2 + 0x2c) = 0;
    puVar2[7] = 0;
    *(undefined4 *)((longlong)puVar2 + 0x34) = 0;
  }
  else {
    if (*param_2 != 0x10) {
      return 0xc00000bb;
    }
    if ((uint)param_2[8] < 4) {
      return 0xc0000023;
    }
    puVar1 = *(uint **)(param_2 + 6);
    *puVar1 = 0;
    uVar3 = *(byte *)(*(longlong *)(param_1 + 0x290) + 0x2582) & 1;
    *puVar1 = uVar3;
    if (*(char *)(param_1 + 0x310) != '\0') {
      *puVar1 = uVar3 | 2;
    }
  }
  return 0;
}



===== HvdDdiQueryChildRelations @ 1c0009010 =====

undefined8 HvdDdiQueryChildRelations(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x2ec) != 0) {
    do {
      if (uVar4 == 0) {
        uVar2 = 0x545648;
      }
      else {
        uVar2 = 0x35648;
        if (uVar4 == 1) {
          uVar2 = 0x25648;
        }
      }
      lVar3 = (ulonglong)uVar4 * 0x1c;
      *(undefined4 *)(lVar3 + 0x18 + param_2) = uVar2;
      *(uint *)(lVar3 + 0x14 + param_2) = uVar4;
      *(undefined4 *)(lVar3 + param_2) = 1;
      *(undefined4 *)(lVar3 + 0x10 + param_2) = 1;
      *(undefined1 *)(lVar3 + 0xc + param_2) = 0;
      iVar1 = *(int *)(param_1 + 0x30c);
      *(undefined4 *)(lVar3 + 8 + param_2) = 1;
      uVar4 = uVar4 + 1;
      *(uint *)(lVar3 + 4 + param_2) = (-(uint)(iVar1 != 0) & 0x80000001) - 1;
    } while (uVar4 < *(uint *)(param_1 + 0x2ec));
  }
  return 0;
}



===== HvdDdiQueryChildStatus @ 1c00090a0 =====

undefined8 HvdDdiQueryChildStatus(undefined8 param_1,int *param_2)

{
  if (*param_2 == 1) {
    *(undefined1 *)(param_2 + 2) = 1;
    return 0;
  }
  return 0xc00000bb;
}



===== HvdDdiQueryDeviceDescriptor @ 1c00090c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 HvdDdiQueryDeviceDescriptor(longlong param_1,int param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  bool bVar6;
  byte bVar7;
  size_t _Size;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  _Size = (size_t)param_3[1];
  uVar1 = *param_3;
  if (0x80 < uVar1 + param_3[1]) {
    return 0xc01d0008;
  }
  lVar2 = *(longlong *)(param_1 + 0x290);
  bVar6 = false;
  local_98 = *(undefined8 *)(lVar2 + 0x2500);
  uVar3 = *(undefined8 *)(lVar2 + 0x2508);
  uVar4 = *(undefined8 *)(lVar2 + 0x2510);
  uStack_80 = *(undefined8 *)(lVar2 + 0x2518);
  local_78 = *(undefined8 *)(lVar2 + 0x2520);
  uStack_70 = *(undefined8 *)(lVar2 + 0x2528);
  local_68 = *(undefined8 *)(lVar2 + 0x2530);
  uVar5 = *(undefined8 *)(lVar2 + 0x2538);
  local_58 = *(undefined8 *)(lVar2 + 0x2540);
  uStack_50 = *(undefined8 *)(lVar2 + 0x2548);
  local_48 = *(undefined8 *)(lVar2 + 0x2550);
  uStack_40 = *(undefined8 *)(lVar2 + 0x2558);
  local_38 = *(undefined8 *)(lVar2 + 0x2560);
  uStack_30 = *(undefined8 *)(lVar2 + 0x2568);
  local_28 = *(undefined8 *)(lVar2 + 0x2570);
  uStack_20 = *(undefined8 *)(lVar2 + 0x2578);
  local_88 = uVar4;
  uStack_60 = uVar5;
  if ((*(int *)(param_1 + 0x2f4) != 0) && (*(int *)(param_1 + 0x300) != 0)) {
    local_88._7_1_ = (undefined1)((ulonglong)uVar4 >> 0x38);
    local_88._0_7_ =
         CONCAT16(*(undefined1 *)(param_1 + 0x300),
                  CONCAT15(*(undefined1 *)(param_1 + 0x2f4),(int5)uVar4));
    uStack_60 = CONCAT71((int7)((ulonglong)uVar5 >> 8),*(undefined1 *)(param_1 + 0x2f0));
    uVar4 = uStack_60;
    uStack_60._2_1_ = (byte)((ulonglong)uVar5 >> 0x10);
    bVar7 = uStack_60._2_1_ & 0xf;
    uStack_60._4_4_ = (undefined4)((ulonglong)uVar5 >> 0x20);
    uStack_60._0_4_ =
         CONCAT13(*(undefined1 *)(param_1 + 0x2fc),
                  CONCAT12((byte)(*(uint *)(param_1 + 0x2f0) >> 4) & 0xf0 | bVar7,(short)uVar4));
    uVar4 = uStack_60;
    uStack_60._5_1_ = (byte)((ulonglong)uVar5 >> 0x28);
    bVar7 = uStack_60._5_1_ & 0xf;
    uStack_60._6_2_ = (undefined2)((ulonglong)uVar5 >> 0x30);
    uStack_60._0_6_ = CONCAT15((byte)(*(uint *)(param_1 + 0x2fc) >> 4) & 0xf0 | bVar7,(int5)uVar4);
    bVar6 = true;
  }
  uStack_90._5_3_ = (undefined3)((ulonglong)uVar3 >> 0x28);
  uStack_90._0_4_ = (undefined4)uVar3;
  if (param_2 == 0x25648) {
    uStack_90._0_5_ = CONCAT14(1,(undefined4)uStack_90);
  }
  else if (param_2 == 0x35648) {
    uStack_90._0_5_ = CONCAT14(2,(undefined4)uStack_90);
  }
  else {
    uStack_90 = uVar3;
    if (!bVar6) goto LAB_1c00091fd;
  }
  UpdateEdidCrc((char *)&local_98);
LAB_1c00091fd:
  memcpy(*(void **)(param_3 + 2),auStack_b8 + (ulonglong)uVar1 + 0x20,_Size);
  return 0;
}



===== HvdDdiQueryVidPnHWCapability @ 1c0009240 =====

undefined8 HvdDdiQueryVidPnHWCapability(longlong param_1,longlong param_2)

{
  if (param_1 == 0) {
    return 0xc000000d;
  }
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffffc0;
  return 0;
}



===== HvdDdiRecommendFunctionalVidPn @ 1c0009260 =====

undefined8 HvdDdiRecommendFunctionalVidPn(void)

{
  return 0xc01e0323;
}



===== HvdDdiRecommendMonitorModes @ 1c0009270 =====

int HvdDdiRecommendMonitorModes(int *param_1,int *param_2)

{
  int iVar1;
  longlong *plVar2;
  
  if (((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (*param_1 != 0x445648)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    if (param_1[0xbb] == 3) {
      plVar2 = &MonitorResolutions;
      if (*param_2 == 0x35648) {
        plVar2 = &DAT_1c00051b1;
      }
    }
    else {
      plVar2 = &SupportedResolutions;
    }
    iVar1 = HvdAddRecommendMonitorModes
                      ((longlong)param_2,
                       0x30001 < ((uint)*(ushort *)(*(longlong *)(param_1 + 0xa4) + 0x22a0) << 0x10
                                 | (uint)(byte)*(undefined2 *)
                                                (*(longlong *)(param_1 + 0xa4) + 0x22a2)),plVar2);
  }
  return iVar1;
}



===== HvdDdiRemoveDevice @ 1c0009300 =====

undefined8 HvdDdiRemoveDevice(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return 0;
}



===== HvdDdiSetPointerPosition @ 1c0009320 =====

ulonglong HvdDdiSetPointerPosition(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  
  puVar4 = *(undefined8 **)(param_1 + 0x290);
  uVar6 = 0;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 4);
  if (*(char *)((longlong)puVar4 + 0x22b9) != '\0') {
    SynthVidpAcquireWriteLock((longlong)puVar4);
    puVar7 = puVar4;
    puVar5 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)puVar4);
    *puVar5 = 7;
    puVar5[1] = 0x12;
    *(undefined4 *)((longlong)puVar5 + 10) = uVar3;
    *(undefined4 *)((longlong)puVar5 + 0xe) = uVar2;
    *(byte *)(puVar5 + 2) = (byte)uVar1 & 1;
    *(undefined1 *)((longlong)puVar5 + 9) = 0;
    uVar6 = SynthVidpIssueWriteLocked(puVar7,0x12);
    uVar6 = uVar6 & 0xffffffff;
    SynthVidpReleaseWriteLock((longlong)puVar4);
  }
  return uVar6;
}



===== HvdDdiSetPointerShape @ 1c00093c0 =====

ulonglong HvdDdiSetPointerShape(longlong param_1,uint *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  size_t _Size;
  uint uVar3;
  ulonglong uVar4;
  void *_Src;
  void *_Dst;
  
  SynthVidLockDirt(*(longlong *)(param_1 + 0x290));
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x901a,0x445648);
  uVar3 = 0;
  if (puVar2 == (undefined8 *)0x0) {
    uVar4 = 0xc0000017;
    goto LAB_1c00094ba;
  }
  *(byte *)((longlong)puVar2 + 9) = (byte)(*param_2 >> 1) & 1;
  *(uint *)((longlong)puVar2 + 10) = param_2[1];
  uVar1 = param_2[2];
  *(uint *)((longlong)puVar2 + 0xe) = uVar1;
  *(uint *)((longlong)puVar2 + 0x12) = param_2[8];
  *(uint *)((longlong)puVar2 + 0x16) = param_2[9];
  if ((*param_2 & 2) == 0) {
    if ((*param_2 & 1) != 0) {
      memcpy((void *)((longlong)puVar2 + 0x1a),*(void **)(param_2 + 6),
             (ulonglong)(uVar1 * param_2[3] * 2));
      goto LAB_1c0009491;
    }
    uVar4 = 0xc000000d;
  }
  else {
    _Size = (size_t)param_2[3];
    _Dst = (void *)((longlong)puVar2 + 0x1a);
    _Src = (void *)((ulonglong)((uVar1 - 1) * param_2[3]) + *(longlong *)(param_2 + 6));
    if (uVar1 != 0) {
      do {
        memcpy(_Dst,_Src,_Size);
        _Size = (size_t)param_2[3];
        uVar3 = uVar3 + 1;
        _Dst = (void *)((longlong)_Dst + _Size);
        _Src = (void *)((longlong)_Src - _Size);
      } while (uVar3 < *(uint *)((longlong)puVar2 + 0xe));
    }
LAB_1c0009491:
    uVar4 = SynthVidUpdatePointerShape(*(undefined8 **)(param_1 + 0x290),puVar2);
    uVar4 = uVar4 & 0xffffffff;
  }
  ExFreePoolWithTag(puVar2,0);
LAB_1c00094ba:
  SynthVidUnlockDirt(*(longlong *)(param_1 + 0x290));
  return uVar4;
}



===== HvdDdiSetPowerState @ 1c00094f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong HvdDdiSetPowerState(longlong param_1,int param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  ulonglong uVar11;
  void *pvVar12;
  uint uVar13;
  longlong *plVar14;
  longlong lVar15;
  void *pvVar16;
  uint uVar17;
  void *_Src;
  int local_288 [3];
  uint local_27c;
  longlong local_278 [72];
  
  lVar15 = 4;
  if (param_2 == -1) {
    if (param_3 == 4) {
      SynthVidDestroy(*(longlong *)(param_1 + 0x290));
      return 0;
    }
    plVar10 = (longlong *)(param_1 + 0x30);
    plVar6 = local_278;
    do {
      plVar14 = plVar6;
      plVar9 = plVar10;
      lVar2 = plVar9[1];
      lVar3 = plVar9[2];
      lVar4 = plVar9[3];
      *plVar14 = *plVar9;
      plVar14[1] = lVar2;
      lVar2 = plVar9[4];
      lVar5 = plVar9[5];
      plVar14[2] = lVar3;
      plVar14[3] = lVar4;
      lVar3 = plVar9[6];
      lVar4 = plVar9[7];
      plVar14[4] = lVar2;
      plVar14[5] = lVar5;
      lVar2 = plVar9[8];
      lVar5 = plVar9[9];
      plVar14[6] = lVar3;
      plVar14[7] = lVar4;
      lVar3 = plVar9[10];
      lVar4 = plVar9[0xb];
      plVar14[8] = lVar2;
      plVar14[9] = lVar5;
      lVar2 = plVar9[0xc];
      lVar5 = plVar9[0xd];
      plVar14[10] = lVar3;
      plVar14[0xb] = lVar4;
      lVar3 = plVar9[0xe];
      lVar4 = plVar9[0xf];
      plVar14[0xc] = lVar2;
      plVar14[0xd] = lVar5;
      plVar14[0xe] = lVar3;
      plVar14[0xf] = lVar4;
      lVar15 = lVar15 + -1;
      plVar10 = plVar9 + 0x10;
      plVar6 = plVar14 + 0x10;
    } while (lVar15 != 0);
    lVar15 = plVar9[0x11];
    lVar2 = plVar9[0x12];
    lVar3 = plVar9[0x13];
    plVar14[0x10] = plVar9[0x10];
    plVar14[0x11] = lVar15;
    lVar15 = plVar9[0x14];
    lVar4 = plVar9[0x15];
    plVar14[0x12] = lVar2;
    plVar14[0x13] = lVar3;
    lVar2 = plVar9[0x16];
    lVar3 = plVar9[0x17];
    plVar14[0x14] = lVar15;
    plVar14[0x15] = lVar4;
    plVar14[0x16] = lVar2;
    plVar14[0x17] = lVar3;
    plVar10 = SynthVidCreate(*(longlong *)(param_1 + 8),local_278);
    *(longlong **)(param_1 + 0x290) = plVar10;
    uVar11 = SynthVidInitialize(plVar10);
    if ((int)uVar11 < 0) {
      return uVar11;
    }
    uVar11 = SynthVidReportVramLocation
                       (*(undefined8 **)(param_1 + 0x290),*(longlong *)(param_1 + 0x298));
    if ((int)uVar11 < 0) {
      return uVar11;
    }
    uVar11 = (**(code **)(param_1 + 0x108))(*(undefined8 *)(param_1 + 0x38),param_1 + 0x270);
    goto LAB_1c000961b;
  }
  if (param_3 == 4) {
    pvVar16 = *(void **)(param_1 + 0x2a8);
    g_MonitorsTurnedOn = 0;
    if (pvVar16 == (void *)0x0) {
      g_MonitorsTurnedOn = 0;
      return 0;
    }
    uVar13 = *(uint *)(param_1 + 0x2be);
    uVar1 = *(uint *)(param_1 + 0x2c2);
    uVar17 = *(uint *)(param_1 + 0x2c6);
    if (param_2 == 0x545648) {
      if (g_MonitorData != (void *)0x0) {
        g_MonitorsTurnedOn = 0;
        return 0;
      }
      pvVar12 = (void *)ExAllocatePool2(0x40,uVar17 * uVar1,0x445648);
      if (pvVar12 == (void *)0x0) {
        g_MonitorData = pvVar12;
        return 0xc0000017;
      }
      _DAT_1c0005168 = *(undefined4 *)(param_1 + 0x2be);
      _DAT_1c000516c = *(undefined4 *)(param_1 + 0x2c2);
      g_MonitorData = pvVar12;
LAB_1c0009731:
    }
    else {
      if (param_2 == 0x25648) {
        if (DAT_1c0005170 != (void *)0x0) {
          g_MonitorsTurnedOn = 0;
          return 0;
        }
        pvVar12 = (void *)ExAllocatePool2(0x40,uVar17 * uVar1,0x445648);
        if (pvVar12 == (void *)0x0) {
          DAT_1c0005170 = pvVar12;
          return 0xc0000017;
        }
        _DAT_1c0005178 = *(undefined4 *)(param_1 + 0x2be);
        _DAT_1c000517c = *(undefined4 *)(param_1 + 0x2c2);
        pvVar16 = (void *)((longlong)pvVar16 +
                          (ulonglong)(uint)(*(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be)) *
                          4);
        DAT_1c0005170 = pvVar12;
        goto LAB_1c0009731;
      }
      if (param_2 != 0x35648) {
        g_MonitorsTurnedOn = 0;
        return 0xc000000d;
      }
      if (DAT_1c0005180 != (void *)0x0) {
        g_MonitorsTurnedOn = 0;
        return 0;
      }
      pvVar12 = (void *)ExAllocatePool2(0x40,*(int *)(param_1 + 0x2d4) * *(int *)(param_1 + 0x2d8),
                                        0x445648);
      if (pvVar12 == (void *)0x0) {
        DAT_1c0005180 = pvVar12;
        return 0xc0000017;
      }
      _DAT_1c0005188 = *(undefined4 *)(param_1 + 0x2d0);
      _DAT_1c000518c = *(undefined4 *)(param_1 + 0x2d4);
      uVar1 = *(uint *)(param_1 + 0x2d4);
      uVar17 = *(uint *)(param_1 + 0x2d8);
      pvVar16 = (void *)((longlong)pvVar16 +
                        (ulonglong)(uint)(*(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be) * 2)
                        * 4);
      uVar13 = *(uint *)(param_1 + 0x2d0);
      DAT_1c0005180 = pvVar12;
    }
    uVar11 = (ulonglong)uVar1;
    iVar8 = *(int *)(param_1 + 0x2ec);
    if (iVar8 == 3) {
      iVar8 = 2;
    }
    if (uVar1 != 0) {
      do {
        memcpy(pvVar12,pvVar16,(ulonglong)uVar17);
        memset(pvVar16,0,(ulonglong)uVar17);
        pvVar12 = (void *)((longlong)pvVar12 + (ulonglong)uVar13 * 4);
        pvVar16 = (void *)((longlong)pvVar16 +
                          (ulonglong)
                          (uint)((iVar8 + -1) * *(int *)(param_1 + 0x308) +
                                 iVar8 * *(int *)(param_1 + 0x2be) + *(int *)(param_1 + 0x2d0)) * 4)
        ;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
  }
  else {
    if (param_3 != 1) {
      return 0;
    }
    pvVar16 = *(void **)(param_1 + 0x2a8);
    g_MonitorsTurnedOn = 1;
    if (pvVar16 == (void *)0x0) {
      g_MonitorsTurnedOn = 1;
      return 0;
    }
    uVar13 = *(uint *)(param_1 + 0x2c6);
    uVar17 = *(uint *)(param_1 + 0x2c2);
    uVar1 = *(uint *)(param_1 + 0x2be);
    if (param_2 == 0x545648) {
      cVar7 = HvdSkipRestoringMonitorData(0,uVar1,uVar17);
      pvVar12 = g_MonitorData;
      if (cVar7 != '\0') {
        return 0;
      }
      g_MonitorData = (void *)0x0;
    }
    else if (param_2 == 0x25648) {
      cVar7 = HvdSkipRestoringMonitorData(1,uVar1,uVar17);
      pvVar12 = DAT_1c0005170;
      if (cVar7 != '\0') {
        return 0;
      }
      DAT_1c0005170 = (void *)0x0;
      pvVar16 = (void *)((longlong)pvVar16 +
                        (ulonglong)(uint)(*(int *)(param_1 + 0x2be) + *(int *)(param_1 + 0x308)) * 4
                        );
    }
    else {
      if (param_2 != 0x35648) {
        g_MonitorsTurnedOn = 1;
        return 0xc000000d;
      }
      cVar7 = HvdSkipRestoringMonitorData(2,*(int *)(param_1 + 0x2d0),*(int *)(param_1 + 0x2d4));
      pvVar12 = DAT_1c0005180;
      if (cVar7 != '\0') {
        return 0;
      }
      DAT_1c0005180 = (void *)0x0;
      uVar17 = *(uint *)(param_1 + 0x2d4);
      uVar1 = *(uint *)(param_1 + 0x2d0);
      pvVar16 = (void *)((longlong)pvVar16 +
                        (ulonglong)(uint)(*(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2be) * 2)
                        * 4);
      uVar13 = *(uint *)(param_1 + 0x2d8);
    }
    uVar11 = (ulonglong)uVar17;
    iVar8 = *(int *)(param_1 + 0x2ec);
    if (iVar8 == 3) {
      iVar8 = 2;
    }
    if (uVar17 != 0) {
      _Src = pvVar12;
      do {
        memcpy(pvVar16,_Src,(ulonglong)uVar13);
        _Src = (void *)((longlong)_Src + (ulonglong)uVar1 * 4);
        pvVar16 = (void *)((longlong)pvVar16 +
                          (ulonglong)
                          (uint)(iVar8 * *(int *)(param_1 + 0x2be) +
                                 (iVar8 + -1) * *(int *)(param_1 + 0x308) +
                                *(int *)(param_1 + 0x2d0)) * 4);
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    ExFreePoolWithTag(pvVar12,0);
  }
  lVar15 = *(longlong *)(param_1 + 0x290);
  SynthVidLockDirt(lVar15);
  SynthVidpAcquireWriteLock(lVar15);
  lVar15 = SynthVidpGetWriteBufferLocked(lVar15);
  local_288[1] = 0;
  *(undefined1 *)(lVar15 + 9) = 0;
  local_27c = *(uint *)(param_1 + 0x2d4);
  if (*(uint *)(param_1 + 0x2d4) <= *(uint *)(param_1 + 0x2c2)) {
    local_27c = *(uint *)(param_1 + 0x2c2);
  }
  local_288[2] = *(int *)(param_1 + 0x2be);
  if (param_2 == 0x545648) {
    local_288[0] = 0;
  }
  else {
    local_288[0] = *(int *)(param_1 + 0x308) + local_288[2] * 2;
    if (param_2 == 0x25648) {
      iVar8 = local_288[2] + *(int *)(param_1 + 0x308);
      local_288[2] = local_288[0];
      local_288[0] = iVar8;
    }
    else {
      local_288[2] = local_288[0] + *(int *)(param_1 + 0x2d0);
    }
  }
  SynthVidAddDirtRectangle(*(longlong *)(param_1 + 0x290),local_288);
  uVar11 = SynthVidSendDirt(*(undefined8 **)(param_1 + 0x290));
LAB_1c000961b:
  if ((int)uVar11 < 0) {
    return uVar11;
  }
  return 0;
}



===== HvdDdiSetVidPnSourceVisibility @ 1c0009a90 =====

undefined8 HvdDdiSetVidPnSourceVisibility(void)

{
  return 0;
}



===== HvdDdiStartDevice @ 1c0009aa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong HvdDdiStartDevice(longlong param_1,undefined8 *param_2,longlong *param_3,
                           undefined4 *param_4,undefined4 *param_5)

{
  undefined8 *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined2 *puVar12;
  ulonglong uVar13;
  short sVar14;
  longlong *plVar15;
  longlong lVar16;
  short *psVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined1 uVar20;
  uint uVar21;
  longlong lVar22;
  char cVar23;
  char cVar24;
  char cVar25;
  undefined1 auStack_378 [32];
  undefined8 local_358;
  undefined4 local_350;
  undefined1 local_348;
  undefined8 *local_340;
  undefined8 *local_338;
  longlong *local_328;
  undefined4 *local_320;
  undefined4 *local_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined1 local_2e8 [32];
  uint *local_2c8;
  longlong local_298 [72];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_378;
  local_318 = param_5;
  local_328 = param_3;
  local_320 = param_4;
  memset(local_2e8,0,0x50);
  local_300 = 0;
  local_310 = 0;
  uStack_308 = 0;
  lVar22 = 4;
  local_2f8 = 0;
  uStack_2f0 = 0;
  uVar3 = param_2[1];
  local_58 = 0;
  uStack_50 = 0;
  *(undefined8 *)(param_1 + 0x10) = *param_2;
  *(undefined8 *)(param_1 + 0x18) = uVar3;
  *(undefined8 *)(param_1 + 0x20) = param_2[2];
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 3);
  plVar9 = (longlong *)(param_1 + 0x30);
  plVar7 = param_3;
  do {
    plVar15 = plVar7;
    plVar8 = plVar9;
    lVar16 = plVar15[1];
    *plVar8 = *plVar15;
    plVar8[1] = lVar16;
    lVar16 = plVar15[3];
    plVar8[2] = plVar15[2];
    plVar8[3] = lVar16;
    lVar16 = plVar15[5];
    plVar8[4] = plVar15[4];
    plVar8[5] = lVar16;
    lVar16 = plVar15[7];
    plVar8[6] = plVar15[6];
    plVar8[7] = lVar16;
    lVar16 = plVar15[9];
    plVar8[8] = plVar15[8];
    plVar8[9] = lVar16;
    lVar16 = plVar15[0xb];
    plVar8[10] = plVar15[10];
    plVar8[0xb] = lVar16;
    lVar16 = plVar15[0xd];
    plVar8[0xc] = plVar15[0xc];
    plVar8[0xd] = lVar16;
    lVar16 = plVar15[0xf];
    plVar8[0xe] = plVar15[0xe];
    plVar8[0xf] = lVar16;
    lVar22 = lVar22 + -1;
    plVar9 = plVar8 + 0x10;
    plVar7 = plVar15 + 0x10;
  } while (lVar22 != 0);
  lVar22 = plVar15[0x11];
  plVar8[0x10] = plVar15[0x10];
  plVar8[0x11] = lVar22;
  lVar22 = plVar15[0x13];
  plVar8[0x12] = plVar15[0x12];
  plVar8[0x13] = lVar22;
  lVar22 = plVar15[0x15];
  plVar8[0x14] = plVar15[0x14];
  plVar8[0x15] = lVar22;
  lVar22 = plVar15[0x17];
  lVar16 = 4;
  plVar8[0x16] = plVar15[0x16];
  plVar8[0x17] = lVar22;
  plVar9 = local_298;
  plVar7 = (longlong *)(param_1 + 0x30);
  do {
    plVar15 = plVar7;
    plVar8 = plVar9;
    lVar22 = plVar15[1];
    lVar4 = plVar15[2];
    lVar5 = plVar15[3];
    *plVar8 = *plVar15;
    plVar8[1] = lVar22;
    lVar22 = plVar15[4];
    lVar6 = plVar15[5];
    plVar8[2] = lVar4;
    plVar8[3] = lVar5;
    lVar4 = plVar15[6];
    lVar5 = plVar15[7];
    plVar8[4] = lVar22;
    plVar8[5] = lVar6;
    lVar22 = plVar15[8];
    lVar6 = plVar15[9];
    plVar8[6] = lVar4;
    plVar8[7] = lVar5;
    lVar4 = plVar15[10];
    lVar5 = plVar15[0xb];
    plVar8[8] = lVar22;
    plVar8[9] = lVar6;
    lVar22 = plVar15[0xc];
    lVar6 = plVar15[0xd];
    plVar8[10] = lVar4;
    plVar8[0xb] = lVar5;
    lVar4 = plVar15[0xe];
    lVar5 = plVar15[0xf];
    plVar8[0xc] = lVar22;
    plVar8[0xd] = lVar6;
    plVar8[0xe] = lVar4;
    plVar8[0xf] = lVar5;
    lVar16 = lVar16 + -1;
    plVar9 = plVar8 + 0x10;
    plVar7 = plVar15 + 0x10;
  } while (lVar16 != 0);
  lVar16 = plVar15[0x11];
  lVar22 = *(longlong *)(param_1 + 8);
  lVar4 = plVar15[0x12];
  lVar5 = plVar15[0x13];
  plVar8[0x10] = plVar15[0x10];
  plVar8[0x11] = lVar16;
  lVar16 = plVar15[0x14];
  lVar6 = plVar15[0x15];
  plVar8[0x12] = lVar4;
  plVar8[0x13] = lVar5;
  lVar4 = plVar15[0x16];
  lVar5 = plVar15[0x17];
  plVar8[0x14] = lVar16;
  plVar8[0x15] = lVar6;
  plVar8[0x16] = lVar4;
  plVar8[0x17] = lVar5;
  plVar9 = SynthVidCreate(lVar22,local_298);
  cVar23 = '\0';
  *(longlong **)(param_1 + 0x290) = plVar9;
  if (plVar9 == (longlong *)0x0) goto LAB_1c0009c3f;
  uVar10 = SynthVidInitialize(plVar9);
  uVar13 = uVar10 & 0xffffffff;
  if (-1 < (int)uVar10) {
    puVar1 = *(undefined8 **)(param_1 + 0x290);
    uVar20 = 1;
    if (0x30003 < ((uint)*(ushort *)(puVar1 + 0x454) << 0x10 |
                  (uint)(byte)*(undefined2 *)((longlong)puVar1 + 0x22a2))) {
      uVar10 = SynthVidRequestResolutions
                         (puVar1,(*(int *)(param_1 + 0x2ec) == 3) + 1,
                          (longlong *)&SupportedResolutions);
      uVar13 = uVar10 & 0xffffffff;
      if ((int)uVar10 < 0) goto LAB_1c000a01a;
      if (1 < *(uint *)(param_1 + 0x2ec)) {
        if ((uint)(ushort)SupportedResolutions[(ulonglong)(DAT_1c0005148 - 1) * 2] <
            (uint)(*(int *)(param_1 + 0x308) + *(int *)(param_1 + 0x2f0) * 2 +
                  *(int *)(param_1 + 0x2f8))) {
          uVar13 = 0xc000000d;
          if (g_TracingEnabled != '\0') {
            DbgPrint(
                    "HyperVideo: Maximum horizontal resolution setting on host is smaller than registry settings in guest\n"
                    );
          }
          goto LAB_1c000a01a;
        }
        sVar14 = SupportedResolutions[(ulonglong)DAT_1c000514c * 2 + 1];
        *SupportedResolutions = *(short *)(param_1 + 0x2f0);
        if (*(int *)(param_1 + 0x2fc) != 0) {
          sVar14 = *(short *)(param_1 + 0x2fc);
        }
        SupportedResolutions[1] = sVar14;
        uVar18 = *(int *)(param_1 + 0x2ec) - 1;
        if (uVar18 < DAT_1c0005148) {
          uVar21 = uVar18;
          do {
            uVar13 = (ulonglong)uVar21;
            uVar21 = uVar21 + 1;
            SupportedResolutions[uVar13 * 2] = 0;
            SupportedResolutions[uVar13 * 2 + 1] = 0;
          } while (uVar21 < DAT_1c0005148);
        }
        psVar17 = &DAT_1c000c052;
        DAT_1c000514c = 0;
        DAT_1c0005150 = '\0';
        DAT_1c0005148 = uVar18;
        if (*(int *)(param_1 + 0x2ec) == 2) {
          uVar18 = 0;
          do {
            if ((psVar17[-1] == *SupportedResolutions) && (*psVar17 == SupportedResolutions[1])) {
              DAT_1c0005150 = '\x01';
              break;
            }
            uVar18 = uVar18 + 1;
            psVar17 = psVar17 + 2;
          } while (uVar18 < 0xd);
        }
        else {
          cVar24 = '\0';
          cVar25 = '\0';
          uVar18 = 0;
          do {
            if ((psVar17[-1] == *SupportedResolutions) && (*psVar17 == SupportedResolutions[1])) {
              cVar23 = '\x01';
            }
            if (psVar17[-1] == SupportedResolutions[2]) {
              cVar25 = cVar24;
              if (*psVar17 == SupportedResolutions[3]) {
                cVar25 = '\x01';
                cVar24 = '\x01';
              }
            }
            if ((cVar23 != '\0') && (cVar25 != '\0')) {
              DAT_1c0005150 = '\x01';
              break;
            }
            uVar18 = uVar18 + 1;
            psVar17 = psVar17 + 2;
          } while (uVar18 < 0xd);
          uVar13 = 0;
          puVar19 = &DAT_1c00051ac;
          lVar22 = 0;
          do {
            lVar16 = uVar13 * 0x11;
            *(undefined8 *)((longlong)&MonitorResolutions + lVar16) = 0;
            *(undefined8 *)((longlong)&DAT_1c00051a8 + lVar16) = 0;
            (&DAT_1c00051b0)[lVar16] = 0;
            puVar12 = (undefined2 *)ExAllocatePool2(0x40,4,0x4c565356);
            *(undefined2 **)(puVar19 + -3) = puVar12;
            if (puVar12 == (undefined2 *)0x0) {
              uVar13 = 0xc0000017;
              goto LAB_1c000a01a;
            }
            *puVar19 = 0;
            psVar17 = SupportedResolutions;
            puVar19[-1] = 1;
            cVar24 = cVar25;
            if ((int)uVar13 == 0) {
              cVar24 = cVar23;
            }
            uVar18 = (int)uVar13 + 1;
            uVar13 = (ulonglong)uVar18;
            *(char *)(puVar19 + 1) = cVar24;
            *puVar12 = *(undefined2 *)(lVar22 + (longlong)psVar17);
            plVar9 = (longlong *)(puVar19 + -3);
            puVar19 = (undefined4 *)((longlong)puVar19 + 0x11);
            lVar16 = lVar22 + 2;
            lVar22 = lVar22 + 4;
            *(undefined2 *)(*plVar9 + 2) = *(undefined2 *)(lVar16 + (longlong)SupportedResolutions);
          } while (uVar18 < 2);
          param_5 = local_318;
          param_3 = local_328;
          param_4 = local_320;
        }
      }
    }
    uVar10 = 0;
    puVar1 = *(undefined8 **)(param_1 + 0x290);
    if (0x30004 < ((uint)*(ushort *)(puVar1 + 0x454) << 0x10 |
                  (uint)(byte)*(undefined2 *)((longlong)puVar1 + 0x22a2))) {
      uVar11 = SynthVidRequestCapability(puVar1);
      uVar13 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_1c000a01a;
    }
    if (((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) << 0x10 |
        (uint)(byte)*(undefined2 *)(*(longlong *)(param_1 + 0x290) + 0x22a2)) < 0x30002) {
      ObfReferenceObject(VideoDriverObject);
    }
    if (((DAT_1c0005150 == '\0') && (0x4b0 < (ushort)SupportedResolutions[1])) &&
       (((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) << 0x10 |
        (uint)(byte)*(undefined2 *)(*(longlong *)(param_1 + 0x290) + 0x22a2)) < 0x30002)) {
      uVar13 = 0xc0000001;
    }
    else {
      uVar18 = (*(code *)param_3[3])(param_3[1],local_2e8);
      uVar13 = (ulonglong)uVar18;
      if (-1 < (int)uVar18) {
        if (*local_2c8 != 0) {
          uVar13 = uVar10;
          do {
            if (local_2c8[4] != 0) {
              uVar11 = uVar10;
              puVar2 = local_2c8;
              do {
                if ((char)puVar2[5] == '\x03') {
                  lVar22 = *(longlong *)(puVar2 + 6);
                  *(longlong *)(param_1 + 0x298) = lVar22;
                  *(uint *)(param_1 + 0x2a0) = puVar2[8];
                  uVar11 = SynthVidReportVramLocation(*(undefined8 **)(param_1 + 0x290),lVar22);
                  uVar13 = uVar11 & 0xffffffff;
                  if ((int)uVar11 < 0) goto LAB_1c000a01a;
                  puVar1 = *(undefined8 **)(param_1 + 0x290);
                  if (((uint)*(ushort *)(puVar1 + 0x454) << 0x10 |
                      (uint)(byte)*(undefined2 *)((longlong)puVar1 + 0x22a2)) < 0x30003) {
                    *(undefined1 *)(param_1 + 0x2e8) = 0;
                  }
                  else {
                    local_328 = (longlong *)((ulonglong)local_328 & 0xffffffff00000000);
                    uVar11 = SynthVidRequestBiosInfo(puVar1,(uint *)&local_328);
                    uVar13 = uVar11 & 0xffffffff;
                    if ((int)uVar11 < 0) goto LAB_1c000a01a;
                    if (((ulonglong)local_328 & 1) != 0) {
                      *(undefined1 *)(param_1 + 0x2e8) = 1;
                      goto LAB_1c000a15d;
                    }
                  }
                  if (((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) << 0x10 |
                      (uint)(byte)*(undefined2 *)(*(longlong *)(param_1 + 0x290) + 0x22a2)) <
                      0x30002) goto LAB_1c000a15a;
                  uVar13 = uVar10;
                  if (DAT_1c0005148 != 0) goto LAB_1c000a12e;
                  goto LAB_1c000a15d;
                }
                uVar18 = (int)uVar11 + 1;
                uVar11 = (ulonglong)uVar18;
                puVar2 = puVar2 + 5;
              } while (uVar18 < local_2c8[4]);
            }
            uVar18 = (int)uVar13 + 1;
            uVar13 = (ulonglong)uVar18;
          } while (uVar18 < *local_2c8);
        }
        uVar13 = 0xc000000d;
      }
    }
  }
  goto LAB_1c000a01a;
LAB_1c000a15a:
  uVar20 = 0;
  goto LAB_1c000a15d;
  while (uVar18 = (int)uVar13 + 1, uVar13 = (ulonglong)uVar18, uVar18 < DAT_1c0005148) {
LAB_1c000a12e:
    if (((ushort)SupportedResolutions[uVar13 * 2] < 0x280) ||
       ((ushort)SupportedResolutions[uVar13 * 2 + 1] < 0x1e0)) goto LAB_1c000a15a;
  }
LAB_1c000a15d:
  *(undefined1 *)(param_1 + 0x2dc) = uVar20;
  uVar18 = (*(code *)param_3[0x1b])(param_3[1],param_1 + 0x270);
  uVar13 = (ulonglong)uVar18;
  if (-1 < (int)uVar18) {
    *param_4 = *(undefined4 *)(param_1 + 0x2ec);
    *param_5 = *(undefined4 *)(param_1 + 0x2ec);
    lVar22 = ExAllocatePool2(0x40,0x30,0x445648);
    *(longlong *)(param_1 + 0x2e0) = lVar22;
    if (lVar22 == 0) {
      uVar13 = 0xc0000017;
    }
    else {
      local_58 = 0x600000006;
      KeInitializeEvent(&local_310,0,0);
      local_338 = &local_2f8;
      local_340 = &local_310;
      local_358 = *(undefined8 *)(param_1 + 0x2e0);
      local_348 = 0;
      local_350 = 0x30;
      lVar22 = IoBuildDeviceIoControlRequest(0x3ec080,*(undefined8 *)(param_1 + 8),&local_58,0x10);
      if (lVar22 == 0) {
LAB_1c0009c3f:
        uVar13 = 0xc000009a;
      }
      else {
        uVar18 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar22);
        if (uVar18 == 0x103) {
          local_358 = 0;
          KeWaitForSingleObject(&local_310,0,0,0);
          uVar18 = (uint)local_2f8;
        }
        if (uVar18 == 0xc00000bb) {
          ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x2e0),0);
          goto LAB_1c000a045;
        }
        uVar13 = (ulonglong)uVar18;
        if (-1 < (int)uVar18) {
          return (ulonglong)uVar18;
        }
      }
    }
  }
LAB_1c000a01a:
  uVar10 = uVar13;
  if (*(longlong *)(param_1 + 0x290) != 0) {
    SynthVidDestroy(*(longlong *)(param_1 + 0x290));
  }
  if (*(longlong *)(param_1 + 0x2e0) == 0) {
    return uVar10;
  }
  ExFreePoolWithTag(*(longlong *)(param_1 + 0x2e0),0);
LAB_1c000a045:
  *(undefined8 *)(param_1 + 0x2e0) = 0;
  return uVar10;
}



===== HvdDdiStopDevice @ 1c000a2c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong HvdDdiStopDevice(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 local_28;
  undefined4 local_27;
  undefined1 local_23;
  undefined4 local_22;
  undefined4 local_1e;
  undefined4 local_1a;
  
  lVar3 = 3;
  if (0x30003 < ((uint)*(ushort *)(*(longlong *)(param_1 + 0x290) + 0x22a0) << 0x10 |
                (uint)(byte)*(undefined2 *)(*(longlong *)(param_1 + 0x290) + 0x22a2))) {
    if (SupportedResolutions != 0) {
      ExFreePoolWithTag(SupportedResolutions,0);
      SupportedResolutions = 0;
    }
    if (*(int *)(param_1 + 0x2ec) == 3) {
      plVar4 = &MonitorResolutions;
      lVar2 = 2;
      do {
        if (*plVar4 != 0) {
          ExFreePoolWithTag(*plVar4,0);
          *plVar4 = 0;
        }
        plVar4 = (longlong *)((longlong)plVar4 + 0x11);
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
  }
  plVar4 = &g_MonitorData;
  do {
    if (*plVar4 != 0) {
      ExFreePoolWithTag(*plVar4,0);
      *plVar4 = 0;
    }
    plVar4 = plVar4 + 2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  local_1e = 0;
  local_1a = 0;
  local_27 = 0;
  local_22 = 0;
  local_28 = 0;
  local_23 = 0;
  uVar1 = SynthVidReportSituationUpdate(*(undefined8 **)(param_1 + 0x290),(undefined8 *)&local_28);
  if (-1 < (int)uVar1) {
    SynthVidDestroy(*(longlong *)(param_1 + 0x290));
    if (*(longlong *)(param_1 + 0x2a8) != 0) {
      (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x38));
      *(undefined8 *)(param_1 + 0x2a8) = 0;
    }
    if (*(longlong *)(param_1 + 0x2e0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x2e0),0);
      *(undefined8 *)(param_1 + 0x2e0) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== HvdDdiUnload @ 1c000a430 =====

void HvdDdiUnload(void)

{
  return;
}



===== HvdDdiUpdateActiveVidPnPresentPath @ 1c000a440 =====

uint HvdDdiUpdateActiveVidPnPresentPath(longlong param_1,longlong param_2)

{
  if (param_1 == 0) {
    return 0xc000000d;
  }
  return ~-(uint)(param_2 != 0) & 0xc000000d;
}



===== HvdAddRecommendMonitorModes @ 1c000a460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HvdAddRecommendMonitorModes(longlong param_1,char param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res18;
  
  uVar3 = 0;
  if ((int)param_3[1] != 0) {
    do {
      local_res18 = 0;
      if ((param_2 != '\0') ||
         ((*(ushort *)(*param_3 + uVar3 * 4) < 0x641 &&
          (*(ushort *)(*param_3 + 2 + uVar3 * 4) < 0x4b1)))) {
        iVar1 = (**(code **)(*(longlong *)(param_1 + 0x10) + 0x20))
                          (*(undefined8 *)(param_1 + 8),&local_res18);
        if (iVar1 < 0) {
          return iVar1;
        }
        *(undefined4 *)(local_res18 + 0x54) = 5;
        *(undefined4 *)(local_res18 + 0x40) = 2;
        *(undefined4 *)(local_res18 + 0x44) = 8;
        *(undefined4 *)(local_res18 + 0x48) = 8;
        *(undefined4 *)(local_res18 + 0x4c) = 8;
        *(undefined4 *)(local_res18 + 0x50) = 8;
        *(undefined4 *)(local_res18 + 8) = 0xff;
        uVar2 = (uint)*(ushort *)(*param_3 + uVar3 * 4);
        *(uint *)(local_res18 + 0x14) = uVar2;
        *(uint *)(local_res18 + 0xc) = uVar2;
        uVar2 = (uint)*(ushort *)(*param_3 + 2 + uVar3 * 4);
        *(uint *)(local_res18 + 0x18) = uVar2;
        *(uint *)(local_res18 + 0x10) = uVar2;
        *(undefined4 *)(local_res18 + 0x1c) = 0xfffffffe;
        *(undefined4 *)(local_res18 + 0x20) = 0xfffffffe;
        *(undefined4 *)(local_res18 + 0x24) = 0xfffffffe;
        *(undefined4 *)(local_res18 + 0x28) = 0xfffffffe;
        *(undefined8 *)(local_res18 + 0x30) = 0xfffffffe;
        *(undefined4 *)(local_res18 + 0x38) = 1;
        *(uint *)(local_res18 + 0x58) = ((int)uVar3 != *(int *)((longlong)param_3 + 0xc)) + 1;
        iVar1 = (**(code **)(*(longlong *)(param_1 + 0x10) + 0x28))
                          (*(undefined8 *)(param_1 + 8),local_res18);
        if (iVar1 < 0) {
          (**(code **)(*(longlong *)(param_1 + 0x10) + 0x30))
                    (*(undefined8 *)(param_1 + 8),local_res18);
          return iVar1;
        }
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_3 + 1));
  }
  return 0;
}



===== HvdAddSourceModesToVidPn @ 1c000a604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HvdAddSourceModesToVidPn
              (longlong param_1,undefined8 param_2,longlong param_3,char param_4,longlong *param_5)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  plVar1 = param_5;
  uVar4 = 0;
  if ((int)param_5[1] != 0) {
    do {
      param_5 = (longlong *)0x0;
      if (((param_3 == 0) ||
          ((*(uint *)(param_3 + 0xc) == (uint)*(ushort *)(*plVar1 + uVar4 * 4) &&
           (*(uint *)(param_3 + 0x10) == (uint)*(ushort *)(*plVar1 + 2 + uVar4 * 4))))) &&
         ((param_4 != '\0' ||
          ((*(ushort *)(*plVar1 + uVar4 * 4) < 0x641 &&
           (*(ushort *)(*plVar1 + 2 + uVar4 * 4) < 0x4b1)))))) {
        iVar2 = (**(code **)(param_1 + 0x28))(param_2,&param_5);
        if (iVar2 < 0) {
          return iVar2;
        }
        *(int *)param_5 = (int)uVar4;
        *(undefined4 *)((longlong)param_5 + 4) = 1;
        *(uint *)(param_5 + 1) = (uint)*(ushort *)(*plVar1 + uVar4 * 4);
        *(uint *)((longlong)param_5 + 0xc) = (uint)*(ushort *)(*plVar1 + 2 + uVar4 * 4);
        param_5[2] = param_5[1];
        *(uint *)(param_5 + 3) = (uint)*(ushort *)(*plVar1 + uVar4 * 4) << 2;
        *(undefined4 *)((longlong)param_5 + 0x1c) = 0x15;
        *(undefined4 *)(param_5 + 4) = 2;
        *(undefined4 *)((longlong)param_5 + 0x24) = 1;
        iVar2 = (**(code **)(param_1 + 0x30))(param_2,param_5);
        if ((iVar2 < 0) && ((**(code **)(param_1 + 0x20))(param_2,param_5), iVar2 != -0x3fe1fcec)) {
          return iVar2;
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(plVar1 + 1));
  }
  return 0;
}



===== HvdAddTargetModesToVidPn @ 1c000a778 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HvdAddTargetModesToVidPn
              (longlong param_1,undefined8 param_2,longlong param_3,char param_4,longlong *param_5)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  
  plVar1 = param_5;
  uVar5 = 0;
  if ((int)param_5[1] != 0) {
    do {
      param_5 = (longlong *)0x0;
      iVar4 = (int)uVar5;
      if (((param_3 == 0) ||
          ((*(uint *)(param_3 + 8) == (uint)*(ushort *)(*plVar1 + uVar5 * 4) &&
           (*(uint *)(param_3 + 0xc) == (uint)*(ushort *)(*plVar1 + 2 + uVar5 * 4))))) &&
         ((param_4 != '\0' ||
          ((*(ushort *)(*plVar1 + uVar5 * 4) < 0x641 &&
           (*(ushort *)(*plVar1 + 2 + uVar5 * 4) < 0x4b1)))))) {
        iVar2 = (**(code **)(param_1 + 0x28))(param_2,&param_5);
        if (iVar2 < 0) {
          return iVar2;
        }
        *(int *)param_5 = iVar4;
        *(undefined4 *)(param_5 + 1) = 0xff;
        uVar3 = (uint)*(ushort *)(*plVar1 + uVar5 * 4);
        *(uint *)((longlong)param_5 + 0x14) = uVar3;
        *(uint *)((longlong)param_5 + 0xc) = uVar3;
        uVar3 = (uint)*(ushort *)(*plVar1 + 2 + uVar5 * 4);
        *(uint *)(param_5 + 3) = uVar3;
        *(uint *)(param_5 + 2) = uVar3;
        *(undefined4 *)((longlong)param_5 + 0x1c) = 0xfffffffe;
        *(undefined4 *)(param_5 + 4) = 0xfffffffe;
        *(undefined4 *)((longlong)param_5 + 0x24) = 0xfffffffe;
        *(undefined4 *)(param_5 + 5) = 0xfffffffe;
        param_5[6] = 0xfffffffe;
        *(undefined4 *)(param_5 + 7) = 1;
        if (iVar4 == *(int *)((longlong)plVar1 + 0xc)) {
          uVar3 = *(uint *)(param_5 + 8) & 0xfffffffd | 1;
        }
        else {
          uVar3 = *(uint *)(param_5 + 8) & 0xfffffffe | 2;
        }
        *(uint *)(param_5 + 8) = uVar3;
        iVar2 = (**(code **)(param_1 + 0x30))(param_2,param_5);
        if ((iVar2 < 0) && ((**(code **)(param_1 + 0x20))(param_2,param_5), iVar2 != -0x3fe1fcec)) {
          return iVar2;
        }
      }
      uVar5 = (ulonglong)(iVar4 + 1U);
    } while (iVar4 + 1U < *(uint *)(plVar1 + 1));
  }
  return 0;
}



===== HvdReadHyperVideoConfigurationSettings @ 1c000a90c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int HvdReadHyperVideoConfigurationSettings(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 *local_80;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_3c = 0;
  local_78[0] = 0;
  local_50 = 0;
  local_58 = 0x30;
  local_68 = 0;
  uStack_60 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  DAT_1c0005150 = 0;
  SupportedResolutions = (undefined2 *)0x0;
  _DAT_1c0005148 = 0;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_1;
  iVar1 = ZwOpenKey(&local_70,0x20019,&local_58);
  uVar2 = 0;
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_68,L"HyperVNonStandardVideoResolution");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70,&local_68,2,&local_28);
    ZwClose(local_70);
    if (-1 < iVar1) {
      if ((local_28._4_4_ != 4) || ((int)uStack_20 != 4)) {
        iVar1 = -0x3fffffff;
        goto LAB_1c000ab4c;
      }
      uVar2 = uStack_20._4_4_;
    }
  }
  if (uVar2 < 0xb) {
    if (uVar2 == 10) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions10;
    }
    else if (uVar2 < 6) {
      if (uVar2 == 5) {
        SupportedResolutions = (undefined2 *)&NonStandardResolutions5;
      }
      else {
        if (uVar2 == 0) {
LAB_1c000ab4c:
          SupportedResolutions = &StandardResolutions;
          _DAT_1c0005148 = 0x20000000d;
          DAT_1c0005150 = 1;
          return iVar1;
        }
        if (uVar2 == 1) {
          SupportedResolutions = (undefined2 *)&NonStandardResolutions1;
        }
        else if (uVar2 == 2) {
          SupportedResolutions = (undefined2 *)&NonStandardResolutions2;
        }
        else if (uVar2 == 3) {
          SupportedResolutions = (undefined2 *)&NonStandardResolutions3;
        }
        else {
          if (uVar2 != 4) goto LAB_1c000ab4c;
          SupportedResolutions = (undefined2 *)&NonStandardResolutions4;
        }
      }
    }
    else if (uVar2 == 6) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions6;
    }
    else if (uVar2 == 7) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions7;
    }
    else if (uVar2 == 8) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions8;
    }
    else {
      if (uVar2 != 9) goto LAB_1c000ab4c;
      SupportedResolutions = (undefined2 *)&NonStandardResolutions9;
    }
  }
  else if (uVar2 < 0x11) {
    if (uVar2 == 0x10) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions16;
    }
    else if (uVar2 == 0xb) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions11;
    }
    else if (uVar2 == 0xc) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions12;
    }
    else if (uVar2 == 0xd) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions13;
    }
    else if (uVar2 == 0xe) {
      SupportedResolutions = (undefined2 *)&NonStandardResolutions14;
    }
    else {
      if (uVar2 != 0xf) goto LAB_1c000ab4c;
      SupportedResolutions = (undefined2 *)&NonStandardResolutions15;
    }
  }
  else if (uVar2 == 0x11) {
    SupportedResolutions = (undefined2 *)&NonStandardResolutions17;
  }
  else if (uVar2 == 0x12) {
    SupportedResolutions = (undefined2 *)&NonStandardResolutions18;
  }
  else if (uVar2 == 0x13) {
    SupportedResolutions = (undefined2 *)&NonStandardResolutions19;
  }
  else {
    if (uVar2 != 0x14) goto LAB_1c000ab4c;
    SupportedResolutions = (undefined2 *)&NonStandardResolutions20;
  }
  _DAT_1c0005148 = CONCAT44(DAT_1c000514c,1);
  DAT_1c0005150 = 0;
  return iVar1;
}



===== HvdSendInvisibleCursor @ 1c000abd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HvdSendInvisibleCursor(longlong param_1)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined2 local_30;
  undefined4 local_2e;
  undefined8 local_2a;
  undefined4 local_22;
  undefined8 local_1e;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  local_30 = 0;
  local_2e = 0x10;
  local_2a = 2;
  local_22 = 0;
  local_1e = 0xffffffff;
  SynthVidUpdatePointerShape(*(undefined8 **)(param_1 + 0x290),&local_38);
  return;
}



===== SynthVidAddDirtRectangle @ 1c000ac40 =====

void SynthVidAddDirtRectangle(longlong param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (*(char *)(param_1 + 0x22b8) != '\0') {
    lVar3 = SynthVidpGetWriteBufferLocked(param_1);
    if (*(byte *)(lVar3 + 9) == 0xff) {
      if (param_2[1] < *(int *)(lVar3 + 0xe)) {
        *(int *)(lVar3 + 0xe) = param_2[1];
      }
      if (*param_2 < *(int *)(lVar3 + 10)) {
        *(int *)(lVar3 + 10) = *param_2;
      }
      if (*(int *)(lVar3 + 0x16) < param_2[3]) {
        *(int *)(lVar3 + 0x16) = param_2[3];
      }
      if (*(int *)(lVar3 + 0x12) < param_2[2]) {
        *(int *)(lVar3 + 0x12) = param_2[2];
      }
    }
    else {
      uVar2 = *(undefined8 *)(param_2 + 2);
      puVar1 = (undefined8 *)(lVar3 + 10 + (ulonglong)*(byte *)(lVar3 + 9) * 0x10);
      *puVar1 = *(undefined8 *)param_2;
      puVar1[1] = uVar2;
      *(char *)(lVar3 + 9) = *(char *)(lVar3 + 9) + '\x01';
    }
  }
  return;
}



===== SynthVidCreate @ 1c000aca8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * SynthVidCreate(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong *plVar8;
  char cVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  plVar10 = (longlong *)ExAllocatePool2(0x40,0x2588,0x4c565356);
  if (plVar10 != (longlong *)0x0) {
    lVar11 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
    plVar10[1] = lVar11;
    if (lVar11 != 0) {
      lVar11 = IoAllocateMdl(plVar10 + 3,0x18b,0,0,0);
      plVar10[2] = lVar11;
      if (lVar11 != 0) {
        MmBuildMdlForNonPagedPool(lVar11);
        lVar11 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
        plVar10[0x3f] = lVar11;
        if (lVar11 != 0) {
          lVar11 = IoAllocateMdl(plVar10 + 0x41,0x201a,0,0,0);
          plVar10[0x40] = lVar11;
          if (lVar11 != 0) {
            MmBuildMdlForNonPagedPool(lVar11);
            lVar11 = IoAllocateWorkItem(param_1);
            plVar10[0x35] = lVar11;
            if (lVar11 != 0) {
              plVar10[0x446] = 0;
              *(undefined4 *)(plVar10 + 0x445) = 1;
              *(undefined4 *)(plVar10 + 0x447) = 0;
              KeInitializeEvent(plVar10 + 0x448,1,0);
              *(undefined4 *)(plVar10 + 0x38) = 1;
              plVar10[0x39] = 0;
              *(undefined4 *)(plVar10 + 0x3a) = 0;
              KeInitializeEvent(plVar10 + 0x3b,1,0);
              *(undefined4 *)(plVar10 + 0x44d) = 1;
              plVar10[0x44e] = 0;
              *(undefined4 *)(plVar10 + 0x44f) = 0;
              KeInitializeEvent(plVar10 + 0x450,1,0);
              ExInitializeRundownProtection(plVar10 + 0x36);
              *plVar10 = param_1;
              *(undefined4 *)(plVar10 + 0x457) = 0x1010101;
              plVar8 = plVar10 + 0x458;
              lVar11 = 4;
              do {
                plVar14 = param_2;
                lVar13 = lVar11;
                plVar12 = plVar8;
                lVar11 = plVar14[1];
                lVar2 = plVar14[2];
                lVar3 = plVar14[3];
                *plVar12 = *plVar14;
                plVar12[1] = lVar11;
                lVar11 = plVar14[4];
                lVar4 = plVar14[5];
                plVar12[2] = lVar2;
                plVar12[3] = lVar3;
                lVar2 = plVar14[6];
                lVar3 = plVar14[7];
                plVar12[4] = lVar11;
                plVar12[5] = lVar4;
                lVar11 = plVar14[8];
                lVar4 = plVar14[9];
                plVar12[6] = lVar2;
                plVar12[7] = lVar3;
                lVar2 = plVar14[10];
                lVar3 = plVar14[0xb];
                plVar12[8] = lVar11;
                plVar12[9] = lVar4;
                lVar11 = plVar14[0xc];
                lVar4 = plVar14[0xd];
                plVar12[10] = lVar2;
                plVar12[0xb] = lVar3;
                lVar2 = plVar14[0xe];
                lVar3 = plVar14[0xf];
                plVar12[0xc] = lVar11;
                plVar12[0xd] = lVar4;
                plVar12[0xe] = lVar2;
                plVar12[0xf] = lVar3;
                lVar11 = lVar13 + -1;
                plVar8 = plVar12 + 0x10;
                param_2 = plVar14 + 0x10;
              } while (lVar11 != 0);
              lVar11 = plVar14[0x11];
              iVar1 = (int)lVar13;
              lVar2 = plVar14[0x12];
              lVar3 = plVar14[0x13];
              plVar12[0x10] = plVar14[0x10];
              plVar12[0x11] = lVar11;
              lVar11 = plVar14[0x14];
              lVar4 = plVar14[0x15];
              plVar12[0x12] = lVar2;
              plVar12[0x13] = lVar3;
              lVar2 = plVar14[0x16];
              lVar3 = plVar14[0x17];
              plVar12[0x14] = lVar11;
              plVar12[0x15] = lVar4;
              plVar12[0x16] = lVar2;
              plVar12[0x17] = lVar3;
              lVar11 = lRam00000001c0005098;
              plVar10[0x4a0] = _DAT_1c0005090;
              plVar10[0x4a1] = lVar11;
              lVar11 = lRam00000001c00050a8;
              plVar10[0x4a2] = _DAT_1c00050a0;
              plVar10[0x4a3] = lVar11;
              lVar11 = lRam00000001c00050b8;
              plVar10[0x4a4] = _DAT_1c00050b0;
              plVar10[0x4a5] = lVar11;
              lVar11 = lRam00000001c00050c8;
              plVar10[0x4a6] = _DAT_1c00050c0;
              plVar10[0x4a7] = lVar11;
              lVar11 = lRam00000001c00050d8;
              plVar10[0x4a8] = _DAT_1c00050d0;
              plVar10[0x4a9] = lVar11;
              lVar11 = ram0x0001c00050e8;
              plVar10[0x4aa] = s_HyperVMonitor_1c00050dd._3_8_;
              plVar10[0x4ab] = lVar11;
              uVar7 = uRam00000001c00050fc;
              uVar6 = uRam00000001c00050f8;
              uVar5 = uRam00000001c00050f4;
              *(undefined4 *)(plVar10 + 0x4ac) = _DAT_1c00050f0;
              *(undefined4 *)((longlong)plVar10 + 0x2564) = uVar5;
              *(undefined4 *)(plVar10 + 0x4ad) = uVar6;
              *(undefined4 *)((longlong)plVar10 + 0x256c) = uVar7;
              uVar7 = uRam00000001c000510c;
              uVar6 = uRam00000001c0005108;
              uVar5 = uRam00000001c0005104;
              *(undefined4 *)(plVar10 + 0x4ae) = _DAT_1c0005100;
              *(undefined4 *)((longlong)plVar10 + 0x2574) = uVar5;
              *(undefined4 *)(plVar10 + 0x4af) = uVar6;
              *(undefined4 *)((longlong)plVar10 + 0x257c) = uVar7;
              *(undefined1 *)(plVar10 + 0x4b0) = 0;
              cVar9 = RtlGetProductInfo(iVar1 + 5,iVar1 + 2,0,0,local_res18);
              if (cVar9 == '\x01') {
                *(undefined1 *)(plVar10 + 0x4b0) = 1;
              }
              *(undefined2 *)((longlong)plVar10 + 0x2581) = 0;
              return plVar10;
            }
          }
        }
      }
    }
    SynthVidpDestroyContext((longlong)plVar10);
  }
  return (longlong *)0x0;
}



===== SynthVidDestroy @ 1c000afc0 =====

void SynthVidDestroy(longlong param_1)

{
  ExAcquireFastMutex(param_1 + 0x1c0);
  *(undefined1 *)(param_1 + 0x1b8) = 1;
  ExReleaseFastMutex(param_1 + 0x1c0);
  IoCancelIrp(*(undefined8 *)(param_1 + 8));
  ExWaitForRundownProtectionRelease(param_1 + 0x1b0);
  SynthVidpDestroyContext(param_1);
  return;
}



===== SynthVidInitialize @ 1c000b038 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynthVidInitialize(undefined8 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_58 [32];
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_20 = 0;
  local_28[0] = 0;
  local_18 = 0;
  local_14 = 0;
  ExAcquireRundownProtection();
  SynthVidpIssueRead(0,param_1);
  SynthVidpAcquireWriteLock((longlong)param_1);
  puVar3 = param_1;
  puVar1 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
  *puVar1 = 1;
  puVar1[1] = 0xc;
  puVar1[2] = 0x50003;
  uVar2 = SynthVidpSendMessageSynchronousLocked(puVar3,0xc,&local_20,0xe,local_28);
  uVar4 = uVar2 & 0xffffffff;
  SynthVidpReleaseWriteLock((longlong)param_1);
  if (-1 < (int)uVar2) {
    if ((char)local_14 == '\0') {
      uVar4 = 0xc0000001;
    }
    else {
      *(undefined2 *)(param_1 + 0x454) = (undefined2)local_18;
      if ((char)local_14 == '\x01') {
        *(undefined2 *)((longlong)param_1 + 0x22a2) = 0;
      }
      else {
        *(undefined2 *)((longlong)param_1 + 0x22a2) = local_18._2_2_;
      }
    }
  }
  return uVar4;
}



===== SynthVidReportSituationUpdate @ 1c000b130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynthVidReportSituationUpdate(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 auStackY_58 [32];
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  uVar3 = 0;
  local_28[0] = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (*(char *)((longlong)param_1 + 0x22bb) != '\0') {
    SynthVidpAcquireWriteLock((longlong)param_1);
    puVar4 = param_1;
    puVar2 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
    *puVar2 = 5;
    puVar2[1] = 0x23;
    *(undefined8 *)(puVar2 + 2) = 0;
    *(undefined1 *)(puVar2 + 4) = 1;
    uVar1 = param_2[1];
    *(undefined8 *)((longlong)puVar2 + 0x11) = *param_2;
    *(undefined8 *)((longlong)puVar2 + 0x19) = uVar1;
    *(undefined2 *)((longlong)puVar2 + 0x21) = *(undefined2 *)(param_2 + 2);
    uVar3 = SynthVidpSendMessageSynchronousLocked(puVar4,0x23,&local_20,0x10,local_28);
    uVar3 = uVar3 & 0xffffffff;
    SynthVidpReleaseWriteLock((longlong)param_1);
  }
  return uVar3;
}



===== SynthVidReportVramLocation @ 1c000b1e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynthVidReportVramLocation(undefined8 *param_1,longlong param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_58 [32];
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28[0] = 0;
  local_20 = 0;
  uStack_18 = 0;
  SynthVidpAcquireWriteLock((longlong)param_1);
  puVar3 = param_1;
  puVar1 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
  *(bool *)(puVar1 + 4) = param_2 != 0;
  *puVar1 = 3;
  puVar1[1] = 0x19;
  *(longlong *)((longlong)puVar1 + 0x11) = param_2;
  *(longlong *)(puVar1 + 2) = param_2;
  uVar2 = SynthVidpSendMessageSynchronousLocked(puVar3,0x19,&local_20,0x10,local_28);
  SynthVidpReleaseWriteLock((longlong)param_1);
  return uVar2 & 0xffffffff;
}



===== SynthVidRequestBiosInfo @ 1c000b288 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynthVidRequestBiosInfo(undefined8 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_68 [32];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  SynthVidpAcquireWriteLock((longlong)param_1);
  puVar3 = param_1;
  puVar1 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
  *puVar1 = 0xb;
  puVar1[1] = 8;
  uVar2 = SynthVidpSendMessageSynchronousLocked(puVar3,8,&local_30,0x18,local_38);
  SynthVidpReleaseWriteLock((longlong)param_1);
  if (-1 < (int)uVar2) {
    *(undefined4 *)(param_1 + 0x455) = uStack_28._4_4_;
    *(uint *)((longlong)param_1 + 0x22a4) = (uint)uStack_28 & 1;
    param_1[0x456] = local_20;
    *param_2 = (uint)uStack_28 & 1;
  }
  return uVar2 & 0xffffffff;
}



===== SynthVidRequestCapability @ 1c000b350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynthVidRequestCapability(undefined8 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined1 local_68 [8];
  byte local_60;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78[0] = 0;
  memset(local_68,0,0x48);
  SynthVidpAcquireWriteLock((longlong)param_1);
  puVar3 = param_1;
  puVar1 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
  *puVar1 = 0xf;
  puVar1[1] = 8;
  uVar2 = SynthVidpSendMessageSynchronousLocked(puVar3,8,local_68,0x48,local_78);
  SynthVidpReleaseWriteLock((longlong)param_1);
  if (-1 < (int)uVar2) {
    *(byte *)((longlong)param_1 + 0x2582) = local_60 & 1;
  }
  return uVar2 & 0xffffffff;
}



===== SynthVidRequestResolutions @ 1c000b404 =====

ulonglong SynthVidRequestResolutions(undefined8 *param_1,byte param_2,longlong *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  void *_Dst;
  undefined8 *puVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  lVar6 = ExAllocatePool2(0x40,0x18b,0x4c565356);
  if (lVar6 == 0) {
    uVar11 = 0xc0000017;
  }
  else {
    SynthVidpAcquireWriteLock((longlong)param_1);
    puVar9 = param_1;
    puVar7 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
    *puVar7 = 0xd;
    puVar7[1] = 9;
    *(undefined1 *)(puVar7 + 2) = 0x40;
    uVar8 = SynthVidpSendMessageSynchronousLocked(puVar9,9,lVar6,0x18b,local_res20);
    uVar11 = uVar8 & 0xffffffff;
    SynthVidpReleaseWriteLock((longlong)param_1);
    if (-1 < (int)uVar8) {
      if (*(char *)(lVar6 + 0x88) == '\0') {
        uVar11 = 0xc000000d;
      }
      else {
        uVar5 = *(undefined8 *)(lVar6 + 0x10);
        param_1[0x4a0] = *(undefined8 *)(lVar6 + 8);
        param_1[0x4a1] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x20);
        param_1[0x4a2] = *(undefined8 *)(lVar6 + 0x18);
        param_1[0x4a3] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x30);
        param_1[0x4a4] = *(undefined8 *)(lVar6 + 0x28);
        param_1[0x4a5] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x40);
        param_1[0x4a6] = *(undefined8 *)(lVar6 + 0x38);
        param_1[0x4a7] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x50);
        param_1[0x4a8] = *(undefined8 *)(lVar6 + 0x48);
        param_1[0x4a9] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x60);
        param_1[0x4aa] = *(undefined8 *)(lVar6 + 0x58);
        param_1[0x4ab] = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0x70);
        param_1[0x4ac] = *(undefined8 *)(lVar6 + 0x68);
        param_1[0x4ad] = uVar5;
        uVar2 = *(undefined4 *)(lVar6 + 0x7c);
        uVar3 = *(undefined4 *)(lVar6 + 0x80);
        uVar4 = *(undefined4 *)(lVar6 + 0x84);
        *(undefined4 *)(param_1 + 0x4ae) = *(undefined4 *)(lVar6 + 0x78);
        *(undefined4 *)((longlong)param_1 + 0x2574) = uVar2;
        *(undefined4 *)(param_1 + 0x4af) = uVar3;
        *(undefined4 *)((longlong)param_1 + 0x257c) = uVar4;
        *param_3 = 0;
        param_3[1] = 0;
        *(undefined1 *)(param_3 + 2) = 0;
        bVar1 = *(byte *)(lVar6 + 0x88);
        bVar10 = bVar1;
        if (bVar1 < param_2) {
          bVar10 = param_2;
        }
        _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)bVar10 << 2,0x4c565356);
        *param_3 = (longlong)_Dst;
        if (_Dst == (void *)0x0) {
          uVar11 = 0xc0000017;
        }
        else {
          uVar8 = (ulonglong)bVar10;
          *(uint *)(param_3 + 1) = (uint)bVar10;
          *(uint *)((longlong)param_3 + 0xc) = (uint)*(byte *)(lVar6 + 0x89);
          *(undefined1 *)(param_3 + 2) = *(undefined1 *)(lVar6 + 0x8a);
          memcpy(_Dst,(void *)(lVar6 + 0x8b),(ulonglong)*(byte *)(lVar6 + 0x88) << 2);
          if (bVar1 < param_2) {
            *(undefined2 *)(*param_3 + -4 + uVar8 * 4) = *(undefined2 *)(*param_3 + -8 + uVar8 * 4);
            *(undefined2 *)(*param_3 + -2 + uVar8 * 4) = *(undefined2 *)(*param_3 + -6 + uVar8 * 4);
          }
        }
      }
    }
    ExFreePoolWithTag(lVar6,0);
  }
  return uVar11;
}



===== SynthVidSendDirt @ 1c000b5e0 =====

ulonglong SynthVidSendDirt(undefined8 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  int iVar4;
  ulonglong uVar5;
  
  puVar3 = param_1;
  puVar1 = (undefined4 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
  if ((*(char *)(puVar3 + 0x457) != '\0') && (*(byte *)((longlong)puVar1 + 9) != 0)) {
    *puVar1 = 10;
    iVar4 = (uint)*(byte *)((longlong)puVar1 + 9) * 0x10 + 10;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[1] = iVar4;
    uVar2 = SynthVidpIssueWriteLocked(param_1,iVar4);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_1c000b628;
  }
  uVar5 = 0;
LAB_1c000b628:
  SynthVidpReleaseWriteLock((longlong)param_1);
  SynthVidUnlockDirt((longlong)param_1);
  return uVar5;
}



===== SynthVidUpdatePointerShape @ 1c000b64c =====

ulonglong SynthVidUpdatePointerShape(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  void *_Src;
  ulonglong _Size;
  char cVar7;
  
  cVar7 = '\0';
  if (*(char *)((longlong)param_1 + 0x22ba) != '\0') {
    if (*(char *)((longlong)param_2 + 9) == '\0') {
      uVar4 = *(int *)((longlong)param_2 + 10) + 7U >> 3;
    }
    else {
      uVar4 = *(int *)((longlong)param_2 + 10) << 2;
    }
    _Src = (void *)((longlong)param_2 + 0x1a);
    uVar6 = (ulonglong)
            ((2 - (uint)(*(char *)((longlong)param_2 + 9) != '\0')) *
             *(int *)((longlong)param_2 + 0xe) * uVar4);
    SynthVidpAcquireWriteLock((longlong)param_1);
    puVar2 = (undefined8 *)SynthVidpGetWriteBufferLocked((longlong)param_1);
    if (uVar6 != 0) {
      do {
        if (uVar6 < 0x2000) {
          _Size = uVar6;
LAB_1c000b6d9:
          cVar7 = -1;
        }
        else {
          _Size = 0x2000;
          if (uVar6 == 0x2000) goto LAB_1c000b6d9;
        }
        uVar1 = param_2[1];
        iVar5 = (int)_Size + 0x1a;
        *puVar2 = *param_2;
        puVar2[1] = uVar1;
        puVar2[2] = param_2[2];
        *(undefined2 *)(puVar2 + 3) = *(undefined2 *)(param_2 + 3);
        *(undefined1 *)((longlong)puVar2 + 0x1a) = *(undefined1 *)((longlong)param_2 + 0x1a);
        *(char *)(puVar2 + 1) = cVar7;
        *(undefined4 *)puVar2 = 8;
        *(int *)((longlong)puVar2 + 4) = iVar5;
        memcpy((void *)((longlong)puVar2 + 0x1a),_Src,_Size);
        uVar3 = SynthVidpIssueWriteLocked(param_1,iVar5);
        if ((int)uVar3 < 0) {
          SynthVidpReleaseWriteLock((longlong)param_1);
          return uVar3 & 0xffffffff;
        }
        _Src = (void *)((longlong)_Src + _Size);
        cVar7 = cVar7 + '\x01';
        uVar6 = uVar6 - _Size;
      } while (uVar6 != 0);
    }
    SynthVidpReleaseWriteLock((longlong)param_1);
  }
  return 0;
}



===== SynthVidpDestroyContext @ 1c000b784 =====

void SynthVidpDestroyContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x1a8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x1a8) = 0;
  }
  if (*(longlong *)(param_1 + 0x200) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x200) = 0;
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(longlong *)(param_1 + 0x1f8) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_1 + 0x1f8) = 0;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_1 + 8) = 0;
  }
  ExFreePoolWithTag(param_1,0x4c565356);
  return;
}



===== SynthVidpIssueRead @ 1c000b850 =====

void SynthVidpIssueRead(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  
  puVar1 = param_2 + 0x38;
  do {
    ExAcquireFastMutex(puVar1);
    if (*(char *)(param_2 + 0x37) != '\0') {
      ExReleaseFastMutex(puVar1);
      ExReleaseRundownProtection(param_2 + 0x36);
      return;
    }
    IoReuseIrp(param_2[1],0);
    ExReleaseFastMutex(puVar1);
    lVar2 = *(longlong *)(param_2[1] + 0xb8);
    *(undefined1 *)(lVar2 + -0x48) = 3;
    *(undefined4 *)(lVar2 + -0x40) = 0x18b;
    *(undefined8 *)(param_2[1] + 8) = param_2[2];
    lVar2 = *(longlong *)(param_2[1] + 0xb8);
    *(code **)(lVar2 + -0x10) = SynthVidpReadCompleted;
    *(undefined8 **)(lVar2 + -8) = param_2;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    iVar3 = IofCallDriver(*param_2);
  } while (iVar3 != 0x103);
  return;
}



===== SynthVidpIssueWriteLocked @ 1c000b938 =====

ulonglong SynthVidpIssueWriteLocked(undefined8 *param_1,undefined4 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  IoReuseIrp(param_1[0x3f],0);
  lVar1 = *(longlong *)(param_1[0x3f] + 0xb8);
  *(undefined1 *)(lVar1 + -0x48) = 4;
  *(undefined4 *)(lVar1 + -0x40) = param_2;
  *(undefined8 *)(param_1[0x3f] + 8) = param_1[0x40];
  *(undefined8 *)(param_1[0x3f] + 0x38) = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_1[0x3f] + 0xb8);
  *(code **)(lVar1 + -0x10) = SynthVidpWriteCompleted;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar2 = IofCallDriver(*param_1,param_1[0x3f]);
  if ((int)uVar2 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar2 = (ulonglong)*(uint *)(param_1[0x3f] + 0x30);
  }
  return uVar2;
}



===== SynthVidpSendMessageSynchronousLocked @ 1c000ba34 =====

ulonglong SynthVidpSendMessageSynchronousLocked
                    (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined4 *param_5)

{
  ulonglong uVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 *local_20;
  undefined8 local_18;
  
  local_24 = 0;
  local_18 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&local_48,1,0);
  local_20 = &local_48;
  param_1[0x44c] = &local_30;
  local_30 = param_3;
  local_28 = param_4;
  uVar1 = SynthVidpIssueWriteLocked(param_1,param_2);
  if ((int)uVar1 < 0) {
    param_1[0x44c] = 0;
  }
  else {
    KeWaitForSingleObject(&local_48,0,0,0,0);
    *param_5 = (undefined4)local_18;
    uVar1 = 0;
  }
  return uVar1;
}



===== DlpCallSyncDeviceIoControl @ 1c000bb04 =====

ulonglong DlpCallSyncDeviceIoControl(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 in_stack_00000030;
  undefined8 *in_stack_00000040;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (0x230043,param_1,0,0,in_stack_00000030,8,1,&local_28,&local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar1 = IofCallDriver(param_1,lVar2);
    if (uVar1 == 0x103) {
      uVar3 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar1 = (uint)local_38;
    }
    if (-1 < (int)uVar1) {
      *in_stack_00000040 = uStack_30;
    }
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== DlpStartDevice @ 1c000bc00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DlpStartDevice(void)

{
  (*MiniportStartDevice)();
  return;
}



===== entry @ 1c000d010 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

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



===== DriverEntry @ 1c000d078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DriverEntry(longlong param_1,longlong param_2)

{
  undefined1 auStack_2a8 [32];
  uint local_288 [2];
  code *local_280;
  code *local_278;
  code *local_270;
  code *local_268;
  code *local_260;
  code *local_248;
  code *local_240;
  code *local_238;
  code *local_230;
  code *local_220;
  code *local_218;
  code *local_200;
  code *local_1f0;
  code *local_1e8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  code *local_1a8;
  code *local_1a0;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  code *local_170;
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2a8;
  memset(local_288,0,0x150);
  memset(local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  local_288[0] = 0x11007;
  local_280 = HvdDdiAddDevice;
  local_278 = HvdDdiStartDevice;
  local_270 = HvdDdiStopDevice;
  local_268 = HvdDdiRemoveDevice;
  local_260 = HvdDdiDispatchIoRequest;
  local_248 = HvdDdiQueryChildRelations;
  local_240 = HvdDdiQueryChildStatus;
  local_238 = HvdDdiQueryDeviceDescriptor;
  local_230 = HvdDdiSetPowerState;
  local_220 = _guard_check_icall;
  local_218 = HvdDdiUnload;
  local_178 = HvdDdiSystemDisplayEnable;
  local_170 = HvdDdiSystemDisplayWrite;
  local_180 = HvdDdiStopDeviceAndReleasePostDisplayOwnership;
  local_200 = HvdDdiQueryAdapterInfo;
  local_1e8 = HvdDdiSetPointerShape;
  local_1f0 = HvdDdiSetPointerPosition;
  local_188 = HvdDdiPresentDisplayOnly;
  local_1d0 = HvdDdiIsSupportedVidPn;
  local_1c8 = HvdDdiRecommendFunctionalVidPn;
  local_1c0 = HvdDdiEnumVidPnCofuncModality;
  local_1b8 = HvdDdiSetVidPnSourceVisibility;
  local_1b0 = HvdDdiCommitVidPn;
  local_1a8 = HvdDdiUpdateActiveVidPnPresentPath;
  local_1a0 = HvdDdiRecommendMonitorModes;
  local_190 = HvdDdiQueryVidPnHWCapability;
  HvdReadHyperVideoConfigurationSettings(param_2);
  VideoDriverObject = param_1;
  DxgkInitializeDisplayOnlyDriver(param_1,param_2,local_288);
  return;
}


