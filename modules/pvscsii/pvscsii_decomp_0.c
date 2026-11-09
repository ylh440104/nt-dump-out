
===== DoLog @ 140001000 =====

void DoLog(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  LogInt(param_1,(va_list)&local_res10);
  return;
}



===== DriverEntry @ 140001028 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_118 [32];
  longlong local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_90;
  undefined4 local_8f;
  code *local_70;
  code *local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  uVar2 = 0xd0;
  memset(&local_e8,0,0xd0);
  RpcVMX_LogSetPrefix(&s_);
  if ((param_1 == 0) && (param_2 == 0)) {
    DoLog("driver v%s starts during crash dump.\n",&s_1_3_15_0,uVar2,param_4);
    DAT_140008841 = 1;
  }
  else {
    local_f8 = param_2;
    DoLog("driver %sPort v%s starts. obj=%p reg=%p\n","Stor",&s_1_3_15_0,param_1);
    DAT_140008841 = 0;
  }
  local_a4 = 0;
  local_e8 = 0xd0;
  local_e0 = PVSCSIInitialize;
  local_a8 = 0xe0;
  local_d8 = PVSCSIStartIo;
  local_a0 = 0x824;
  local_d0 = PVSCSIInterrupt;
  local_c8 = PVSCSIFindAdapter;
  local_c0 = PVSCSIResetBus;
  local_70 = PVSCSIAdapterControl;
  local_68 = PVSCSIBuildIo;
  local_9c = 2;
  local_8f = 0x1010101;
  local_e4 = 5;
  local_90 = 0;
  iVar1 = StorPortInitialize(param_1,param_2,&local_e8,0);
  if (iVar1 == 0) {
    RpcVMX_ReportDriverVersion(&s_pvscsii,&s_1_3_15_0);
  }
  return iVar1;
}



===== Fun2Str @ 140001198 =====

char * Fun2Str(byte param_1)

{
  if (param_1 < 0x14) {
    if (param_1 == 0x13) {
      return "RESET_DEVICE";
    }
    if (param_1 < 7) {
      if (param_1 == 6) {
        return "RELEASE_DEVICE";
      }
      if (param_1 == 0) {
        return "EXECUTE_SCSI";
      }
      if (param_1 == 1) {
        return "CLAIM_DEVICE";
      }
      if (param_1 == 2) {
        return "IO_CONTROL";
      }
      if (param_1 == 3) {
        return "RECEIVE_EVENT";
      }
      if (param_1 == 4) {
        return "RELEASE_QUEUE";
      }
      if (param_1 == 5) {
        return "ATTACH_DEVICE";
      }
    }
    else {
      if (param_1 == 7) {
        return "SHUTDOWN";
      }
      if (param_1 == 8) {
        return "FLUSH";
      }
      if (param_1 == 0x10) {
        return "ABORT_COMMAND";
      }
      if (param_1 == 0x11) {
        return "RELEASE_RECOVERY";
      }
      if (param_1 == 0x12) {
        return "RESET_BUS";
      }
    }
  }
  else if (param_1 < 0x21) {
    if (param_1 == 0x20) {
      return "RESET_LOGICAL_UNIT";
    }
    if (param_1 == 0x14) {
      return "TERMINATE_IO";
    }
    if (param_1 == 0x15) {
      return "FLUSH_QUEUE";
    }
    if (param_1 == 0x16) {
      return "REMOVE_DEVICE";
    }
    if (param_1 == 0x17) {
      return "WMI";
    }
    if (param_1 == 0x18) {
      return "LOCK_QUEUE";
    }
    if (param_1 == 0x19) {
      return "UNLOCK_QUEUE";
    }
  }
  else {
    if (param_1 == 0x21) {
      return "SET_LINK_TIMEOUT";
    }
    if (param_1 == 0x22) {
      return "LINK_TIMEOUT_OCCURRED";
    }
    if (param_1 == 0x23) {
      return "LINK_TIMEOUT_COMPLETE";
    }
    if (param_1 == 0x24) {
      return "POWER";
    }
    if (param_1 == 0x25) {
      return "PNP";
    }
  }
  return "Unknown function";
}



===== Log @ 140001300 =====

void Log(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if (DAT_140008840 != '\0') {
    local_res10 = param_2;
    local_res18 = param_3;
    local_res20 = param_4;
    LogInt(param_1,(va_list)&local_res10);
  }
  return;
}



===== LogInt @ 140001330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogInt(char *param_1,va_list param_2)

{
  undefined8 uVar1;
  char in_CR8;
  undefined1 auStack_418 [32];
  char local_3f8 [992];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_418;
  builtin_strncpy(local_3f8,"PVSCSI: ",9);
  memset(local_3f8 + 9,0,0x3d3);
  uVar1 = 0x3d3;
  Str_Vsnprintf(local_3f8 + 8,0x3d3,param_1,param_2);
  if (in_CR8 == '\0') {
    RpcVMX_Log(local_3f8,uVar1,param_1,param_2);
  }
  return;
}



===== LogRingState @ 1400013c8 =====

void LogRingState(longlong param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x50);
  DoLog("RINGS:  REQ: %u/%u (%u) CMP: %u/%u (%u) MSG: %u/%u (%u)\n",(ulonglong)*puVar1,
        (ulonglong)puVar1[1],(ulonglong)puVar1[2]);
  return;
}



===== PVSCSIAbortCmd @ 140001420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIAbortCmd(ulonglong param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 local_58 [32];
  uint local_38;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_58;
  uVar5 = (ulonglong)*(byte *)(param_2 + 6);
  uVar3 = (ulonglong)*(byte *)(param_2 + 5);
  uVar1 = *(ulonglong *)(param_2 + 0x28);
  local_38 = (uint)*(byte *)(param_2 + 7);
  DoLog("ABORT CMD: srb=%p path=0x%x tgt=%u lun=0x%x\n",uVar1,uVar3,uVar5);
  LogRingState(param_1);
  PVSCSIProcessCompletionRing(param_1,uVar1,uVar3,uVar5);
  local_1c = 0;
  local_20 = (uint)*(byte *)(param_2 + 6);
  local_28 = *(undefined8 *)(param_2 + 0x28);
  **(undefined4 **)(param_1 + 0x78) = 6;
  LOCK();
  UNLOCK();
  puVar2 = &local_28;
  lVar4 = 4;
  do {
    *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 4) = *(undefined4 *)puVar2;
    LOCK();
    UNLOCK();
    puVar2 = (undefined8 *)((longlong)puVar2 + 4);
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  PVSCSIProcessCompletionRing(param_1,(ulonglong)puVar2,0,uVar5);
  *(undefined1 *)(param_2 + 3) = 1;
  LogRingState(param_1);
  DoLog("ABORT CMD DONE.\n",puVar2,lVar4,uVar5);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x82;
  LOCK();
  UNLOCK();
  return;
}



===== PVSCSIAdapterControl @ 140001510 =====

undefined8 PVSCSIAdapterControl(longlong param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  char *pcVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  uVar3 = 0;
  if (param_2 == 0) {
    pcVar2 = "QuerySupportedControlTypes";
  }
  else if (param_2 == 1) {
    pcVar2 = "StopAdapter";
  }
  else if (param_2 == 2) {
    pcVar2 = "RestartAdapter";
  }
  else if (param_2 == 3) {
    pcVar2 = "SetBootConfig";
  }
  else if (param_2 == 4) {
    pcVar2 = "SetRunningConfig";
  }
  else {
    pcVar2 = "Unknown";
  }
  uVar4 = (ulonglong)param_2;
  lVar5 = param_1;
  Log("AdapterControl: %s (0x%x) for 0x%p\n",pcVar2,uVar4,param_1);
  if (param_2 == 0) {
    uVar1 = *param_3;
    if (uVar1 != 0) {
      *(undefined1 *)(param_3 + 1) = 1;
    }
    if (1 < uVar1) {
      *(undefined1 *)((longlong)param_3 + 5) = 1;
      uVar1 = *param_3;
    }
    if (2 < uVar1) {
      *(undefined1 *)((longlong)param_3 + 6) = 1;
      uVar1 = *param_3;
    }
    if (3 < uVar1) {
      *(undefined1 *)((longlong)param_3 + 7) = 0;
      uVar1 = *param_3;
    }
    if (4 < uVar1) {
      *(undefined1 *)(param_3 + 2) = 0;
    }
  }
  else if (param_2 == 1) {
    PVSCSIAdapterReset(param_1,pcVar2,uVar4,lVar5);
  }
  else if (param_2 == 2) {
    PVSCSIAdapterReset(param_1,pcVar2,uVar4,lVar5);
    PVSCSIInitHw(param_1);
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



===== PVSCSIAdapterReset @ 140001610 =====

void PVSCSIAdapterReset(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  Log("Adapter Reset..\n",param_2,param_3,param_4);
  **(undefined4 **)(param_1 + 0x78) = 1;
  LOCK();
  UNLOCK();
  Log("Adapter Reset done: %u\n",(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x78) + 0x100c),
      param_3,param_4);
  return;
}



===== PVSCSIAllocateRings @ 140001650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PVSCSIAllocateRings(longlong param_1,undefined8 param_2,undefined8 param_3,
                             undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint uVar8;
  bool bVar9;
  undefined1 auStack_48 [32];
  uint local_28 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  *(undefined4 *)(param_1 + 0x90) = 0;
  bVar9 = *(char *)(param_1 + 0x49) != '\0';
  if (bVar9) {
    *(undefined4 *)(param_1 + 0x90) = 1;
  }
  iVar5 = *(int *)(param_1 + 0x8c) + *(int *)(param_1 + 0x88) + (uint)bVar9;
  uVar8 = (iVar5 + 3) * 0x1000;
  uVar6 = (ulonglong)uVar8;
  uVar1 = StorPortGetUncachedExtension(param_1);
  if (uVar1 == 0) {
    uVar1 = Log("Failed to allocate extension, numPages: %u.\n",(ulonglong)(iVar5 + 3),uVar6,param_4
               );
  }
  else {
    local_28[0] = 0;
    puVar7 = local_28;
    uVar6 = uVar1;
    uVar2 = StorPortGetPhysicalAddress(param_1,0);
    if (uVar8 <= local_28[0]) {
      if ((uVar2 & 0xfff) != 0) {
        puVar7 = (uint *)(ulonglong)local_28[0];
        uVar6 = uVar2;
        Log("Unaligned va=%p, pa=0x%I64x len=%u\n",uVar1,uVar2,puVar7);
      }
      *(undefined8 *)(param_1 + 0x68) = 0;
      uVar1 = uVar1 + 0xfff & 0xfffffffffffff000;
      *(ulonglong *)(param_1 + 0x80) = uVar2 + 0xfff >> 0xc;
      *(ulonglong *)(param_1 + 0x50) = uVar1;
      *(ulonglong *)(param_1 + 0x58) = uVar1 + 0x1000;
      *(ulonglong *)(param_1 + 0x60) = (uint)((*(int *)(param_1 + 0x88) + 1) * 0x1000) + uVar1;
      lVar3 = (uint)((*(int *)(param_1 + 0x8c) + 1 + *(int *)(param_1 + 0x88)) * 0x1000) + uVar1;
      *(longlong *)(param_1 + 0x98) = lVar3;
      if (*(char *)(param_1 + 0x49) != '\0') {
        *(longlong *)(param_1 + 0x68) = lVar3 + 0x1000;
      }
      Log("RingsState: VA: %p\n",uVar1,uVar6,puVar7);
      Log("ReqRing: VA: 0x%p - %u pages\n",*(undefined8 *)(param_1 + 0x58),
          (ulonglong)*(uint *)(param_1 + 0x88),puVar7);
      Log("CmpRing: VA: 0x%p - %u pages\n",*(undefined8 *)(param_1 + 0x60),
          (ulonglong)*(uint *)(param_1 + 0x8c),puVar7);
      uVar1 = (ulonglong)*(uint *)(param_1 + 0x90);
      Log("MsgRing: VA: 0x%p - %u pages\n",*(undefined8 *)(param_1 + 0x68),uVar1,puVar7);
      uVar4 = Log("configCmp: VA: %p\n",*(undefined8 *)(param_1 + 0x98),uVar1,puVar7);
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
    StorPortDebugPrint(0,"Failed to get PA of extension\n");
    uVar1 = Log("va=%p, pa=0x%I64x len=%u\n",uVar1,uVar2,(ulonglong)local_28[0]);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== PVSCSIBuildIo @ 140001830 =====

undefined8 PVSCSIBuildIo(undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  undefined8 uVar1;
  
  uVar1 = CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  if (((char)param_2[1] == '\0') && (*(int *)(param_2 + 8) != 0)) {
    uVar1 = PVSCSIBuildSGListStorport(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



===== PVSCSIBuildSGListStorport @ 14000184c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PVSCSIBuildSGListStorport
                    (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  uint *puVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  uint *puVar12;
  undefined1 auStack_78 [32];
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  puVar12 = *(uint **)(param_2 + 0x1c);
  uVar3 = 0;
  uVar11 = 0;
  puVar6 = param_2;
  local_58 = puVar12;
  local_50 = param_1;
  puVar2 = (uint *)StorPortGetScatterGatherList();
  uVar1 = local_50;
  if (puVar2 == (uint *)0x0) {
    Log("StorPortGetScatterGatherList failed.\n",puVar6,param_3,param_4);
    uVar3 = PrintSRB(param_2,puVar6,param_3,param_4);
  }
  else {
    if (*puVar2 < 0x81) {
      *puVar12 = 0;
      uVar5 = *puVar2;
      uVar9 = (longlong)puVar12 + 0x13U & 0xfffffffffffffff0;
      uVar8 = 0;
      puVar4 = puVar2;
      if (uVar5 != 0) {
        do {
          puVar4 = (uint *)(ulonglong)(uVar5 - 1);
          if ((uint)uVar8 < uVar5 - 1) {
            uVar11 = (int)uVar3 + 1;
            lVar10 = (ulonglong)uVar11 * 0x10 + uVar9;
            puVar4 = (uint *)(ulonglong)((uint)lVar10 & 0xfff);
            if (puVar4 < (uint *)0x10) {
              puVar4 = (uint *)StorPortGetPhysicalAddress(uVar1,param_2,lVar10,&local_50);
              *(undefined4 *)(uVar9 + 8 + uVar3 * 0x10) = 0;
              *(uint **)(uVar9 + uVar3 * 0x10) = puVar4;
              *(undefined4 *)(uVar9 + 0xc + uVar3 * 0x10) = 1;
              uVar3 = (ulonglong)uVar11;
            }
          }
          uVar7 = (uint)uVar8 + 1;
          uVar11 = (int)uVar3 + 1;
          *(undefined8 *)(uVar9 + uVar3 * 0x10) = *(undefined8 *)(puVar2 + uVar8 * 6 + 4);
          uVar5 = puVar2[uVar8 * 6 + 6];
          *(undefined4 *)(uVar9 + 0xc + uVar3 * 0x10) = 0;
          *(uint *)(uVar9 + 8 + uVar3 * 0x10) = uVar5;
          uVar5 = *puVar2;
          uVar3 = (ulonglong)uVar11;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < uVar5);
        puVar12 = local_58;
      }
      *puVar12 = uVar11;
      return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
    }
    uVar3 = Log("NumberOfElements=%u\n",(ulonglong)*puVar2,param_3,param_4);
  }
  return uVar3 & 0xffffffffffffff00;
}



===== PVSCSIDoResetBus @ 140001988 =====

void PVSCSIDoResetBus(ulonglong param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  DoLog("Resetting bus: path=%u\n",param_2,param_3,param_4);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x70;
  LOCK();
  UNLOCK();
  LogRingState(param_1);
  **(undefined4 **)(param_1 + 0x78) = 4;
  LOCK();
  UNLOCK();
  PVSCSIProcessCompletionRing(param_1,param_2,param_3,param_4);
  LogRingState(param_1);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x71;
  LOCK();
  UNLOCK();
  return;
}



===== PVSCSIDoResetDevice @ 1400019f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIDoResetDevice(ulonglong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 local_78 [32];
  undefined4 local_58;
  uint local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_78;
  bVar1 = *(byte *)(param_2 + 6);
  uVar5 = (ulonglong)bVar1;
  bVar2 = *(byte *)(param_2 + 7);
  bVar3 = *(byte *)(param_2 + 5);
  DoLog("Resetting device: scsi%u:%u:%u\n",(ulonglong)bVar3,uVar5,(ulonglong)bVar2);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x50;
  LOCK();
  UNLOCK();
  LogRingState(param_1);
  local_58 = 0x1e;
  uVar6 = CONCAT71((int7)(uVar5 >> 8),bVar1);
  StorPortPauseDevice(param_1,bVar3,uVar6,bVar2);
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[0] = (uint)bVar1;
  **(undefined4 **)(param_1 + 0x78) = 5;
  LOCK();
  UNLOCK();
  puVar4 = local_48;
  lVar7 = 3;
  do {
    *(uint *)(*(longlong *)(param_1 + 0x78) + 4) = *puVar4;
    LOCK();
    UNLOCK();
    puVar4 = puVar4 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  PVSCSIProcessCompletionRing(param_1,(ulonglong)puVar4,uVar6,0);
  *(undefined1 *)(param_2 + 3) = 1;
  Log("RequestComplete %p: SrbStatus=0x%x ScsiStatus=0x%x\n",param_2,1,
      (ulonglong)*(byte *)(param_2 + 4));
  StorPortNotification(0,param_1,param_2);
  StorPortResumeDevice(param_1,bVar3,bVar1,bVar2);
  LogRingState(param_1);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x51;
  LOCK();
  UNLOCK();
  return;
}



===== PVSCSIDpcRoutine @ 140001b30 =====

void PVSCSIDpcRoutine(undefined8 param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  ulonglong uVar1;
  
  uVar1 = param_2;
  PVSCSIProcessCompletionRing(param_2,param_2,param_3,param_4);
  if ((*(longlong *)(param_2 + 0x68) != 0) &&
     (*(int *)(*(longlong *)(param_2 + 0x50) + 0x80) !=
      *(int *)(*(longlong *)(param_2 + 0x50) + 0x84))) {
    PVSCSIProcessMsgRing(param_2,uVar1,param_3,param_4);
  }
  return;
}



===== PVSCSIFindAdapter @ 140001b70 =====

undefined8
PVSCSIFindAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4,uint *param_5
                 )

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint *puVar11;
  int *piVar12;
  char *pcVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  bool bVar16;
  bool bVar17;
  uint local_res8 [2];
  uint local_res20 [2];
  undefined4 uVar18;
  uint local_48 [4];
  
  puVar15 = (undefined8 *)0x0;
  pcVar13 = param_4;
  DoLog("FindAdapter starts (arg=\'%s\')\n",param_4,param_3,param_4);
  puVar6 = param_5;
  uVar10 = 0xe0;
  uVar4 = (ulonglong)*param_5;
  Log("info->length=%u vs sizeof(*info)=%I64u\n",uVar4,0xe0,pcVar13);
  *(undefined4 *)(param_1 + 0x70) = 0;
  if (*(longlong *)(puVar6 + 0xe) == 0) {
    Log("No range found.\n",uVar4,uVar10,pcVar13);
    return 2;
  }
  uVar8 = 0;
  if (puVar6[0xd] == 0) {
LAB_140001fb8:
    DoLog("No range found.\n",uVar4,uVar10,pcVar13);
    return 2;
  }
  do {
    uVar4 = (ulonglong)uVar8;
    puVar7 = (undefined8 *)((ulonglong)uVar8 * 0x10 + *(longlong *)(puVar6 + 0xe));
    uVar18 = (undefined4)((ulonglong)*puVar7 >> 0x20);
    uVar10 = (ulonglong)*(byte *)((longlong)puVar7 + 0xc);
    pcVar13 = (char *)(ulonglong)*(uint *)(puVar7 + 1);
    DoLog("range[%u]: mmio=%u len=%lu s=0x%I64x\n",uVar4,uVar10,pcVar13);
    if (*(char *)((longlong)puVar7 + 0xc) == '\0') {
      puVar7 = puVar15;
    }
    uVar8 = uVar8 + 1;
    puVar15 = puVar7;
  } while (uVar8 < puVar6[0xd]);
  if (puVar7 == (undefined8 *)0x0) goto LAB_140001fb8;
  uVar14 = *puVar7;
  uVar10 = (ulonglong)puVar6[1];
  uVar4 = StorPortGetDeviceBase
                    (param_1,puVar6[2],uVar10,uVar14,CONCAT44(uVar18,*(undefined4 *)(puVar7 + 1)),0)
  ;
  *(ulonglong *)(param_1 + 0x78) = uVar4;
  DoLog("PVSCSIGetDeviceBase returns 0x%I64x\n",uVar4,uVar10,uVar14);
  if (*(longlong *)(param_1 + 0x78) == 0) {
    DoLog("FindAdapter: Couldn\'t map %I64x for %lu bytes\n",*puVar7,
          (ulonglong)*(uint *)(puVar7 + 1),uVar14);
    return 2;
  }
  PVSCSIAdapterReset(param_1,uVar4,uVar10,uVar14);
  uVar8 = *puVar6;
  *(undefined1 *)(puVar6 + 0x12) = 1;
  puVar6[6] = 0x80000;
  puVar6[7] = 0x80;
  *(undefined2 *)((longlong)puVar6 + 0x51) = 0x101;
  *(undefined1 *)((longlong)puVar6 + 0x53) = 0;
  puVar6[0xc] = 3;
  *(undefined1 *)((longlong)puVar6 + 0x57) = 1;
  *(undefined1 *)((longlong)puVar6 + 0x59) = 0;
  if (0x92 < uVar8) {
    uVar4 = (ulonglong)*(byte *)((longlong)puVar6 + 0x92);
    Log("MaximumNumberOfLogicalUnits = 0x%I64x\n",uVar4,uVar10,uVar14);
    uVar8 = *puVar6;
    *(undefined1 *)((longlong)puVar6 + 0x92) = 1;
  }
  if (0x91 < uVar8) {
    uVar4 = (ulonglong)*(byte *)((longlong)puVar6 + 0x91);
    Log("ResetTargetSupported = 0x%I64x\n",uVar4,uVar10,uVar14);
    uVar8 = *puVar6;
    *(undefined1 *)((longlong)puVar6 + 0x91) = 1;
  }
  if (0x90 < uVar8) {
    uVar4 = (ulonglong)(byte)puVar6[0x24];
    Log("Dma64BitAddresses = 0x%I64x\n",uVar4,uVar10,uVar14);
    if ((char)puVar6[0x24] == -0x80) {
      *(undefined1 *)(puVar6 + 0x24) = 1;
    }
  }
  uVar8 = *puVar6;
  if (0x93 < uVar8) {
    uVar4 = (ulonglong)*(byte *)((longlong)puVar6 + 0x93);
    Log("WmiDataProvider = 0x%I64x\n",uVar4,uVar10,uVar14);
    *(undefined1 *)((longlong)puVar6 + 0x93) = 1;
    PVSCSIWmiInitialize(param_1);
    uVar8 = *puVar6;
  }
  if (0x94 < uVar8) {
    uVar4 = (ulonglong)(int)puVar6[0x25];
    Log("SynchronizationModel = 0x%I64x\n",uVar4,uVar10,uVar14);
    uVar8 = *puVar6;
    puVar6[0x25] = 1;
  }
  if (0xa0 < uVar8) {
    uVar4 = (ulonglong)(int)puVar6[0x28];
    Log("InterruptSynchronizationMode = 0x%I64x\n",uVar4,uVar10,uVar14);
    puVar6[0x28] = 1;
    *(code **)(puVar6 + 0x26) = PVSCSIMSInterrupt;
  }
  **(undefined4 **)(param_1 + 0x78) = 0xb;
  LOCK();
  UNLOCK();
  uVar9 = 8;
  uVar8 = *(uint *)(*(longlong *)(param_1 + 0x78) + 8);
  if (uVar8 == 0xffffffff) {
    DoLog("Adapter doesn\'t support GET MAX TARGET command.\n",uVar4,uVar10,uVar14);
    uVar8 = 0x10;
  }
  puVar11 = (uint *)0xff;
  DoLog("FindAdapter: Device returned, max targets: %u, Driver max: %u\n",(ulonglong)uVar8,0xff,
        uVar14);
  uVar3 = 0xff;
  if (uVar8 < 0xff) {
    uVar3 = (char)uVar8;
  }
  bVar16 = DAT_140008841 == '\0';
  *(undefined1 *)((longlong)puVar6 + 0x61) = uVar3;
  if (bVar16) {
    **(undefined4 **)(param_1 + 0x78) = 8;
    LOCK();
    UNLOCK();
    if (*(int *)(*(longlong *)(param_1 + 0x78) + 8) == -1) {
LAB_140001e64:
      uVar3 = 0;
    }
    else {
      piVar12 = (int *)&param_5;
      uVar4 = PVSCSIFindValueForKeyInString("UseMsg=",param_4,piVar12,uVar14);
      iVar2 = (int)param_5;
      bVar16 = (char)uVar4 != '\0';
      if (bVar16) {
        DoLog("Found entry for UseMsg=%u\n",(ulonglong)param_5 & 0xffffffff,piVar12,uVar14);
      }
      uVar3 = 1;
      if (bVar16 && iVar2 == 0) goto LAB_140001e64;
    }
    *(undefined1 *)(param_1 + 0x49) = uVar3;
    puVar11 = local_res8;
    bVar1 = *(byte *)((longlong)puVar6 + 0x61);
    uVar4 = PVSCSIFindValueForKeyInString("RequestRingPages=",param_4,(int *)puVar11,uVar14);
    if ((char)uVar4 == '\0') {
      bVar16 = bVar1 < 0x10;
      bVar17 = bVar1 == 0x10;
    }
    else {
      DoLog("Found entry for RequestRingPages=%u\n",(ulonglong)local_res8[0],puVar11,uVar14);
      if (local_res8[0] == 0) goto LAB_140001e04;
      bVar16 = local_res8[0] < 0x20;
      bVar17 = local_res8[0] == 0x20;
      uVar9 = local_res8[0];
    }
    if (!bVar16 && !bVar17) {
      uVar9 = 0x20;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x49) = 0;
LAB_140001e04:
    uVar9 = 1;
  }
  *(uint *)(param_1 + 0x88) = uVar9;
  *(uint *)(param_1 + 0x8c) = uVar9;
  uVar5 = PVSCSIAllocateRings(param_1,puVar6,puVar11,uVar14);
  if ((char)uVar5 == '\0') {
    DoLog("FindAdapter failed to allocate rings.\n",puVar6,puVar11,uVar14);
    StorPortFreeDeviceBase(param_1,*(undefined8 *)(param_1 + 0x78));
    return 2;
  }
  puVar6 = local_res20;
  uVar4 = PVSCSIFindValueForKeyInString("UseReqCallThreshold=",param_4,(int *)puVar6,uVar14);
  bVar16 = (char)uVar4 == '\0';
  if (!bVar16) {
    DoLog("Found entry for UseReqCallThreshold=%u\n",(ulonglong)local_res20[0],puVar6,uVar14);
  }
  puVar6 = local_48;
  *(bool *)(param_1 + 0x4a) = bVar16 || local_res20[0] != 0;
  uVar4 = PVSCSIFindValueForKeyInString("MaxQueueDepth=",param_4,(int *)puVar6,uVar14);
  if ((char)uVar4 == '\0') {
    local_48[0] = 0x40;
  }
  else {
    DoLog("Found entry for MaxQueueDepth=%u\n",(ulonglong)local_48[0],puVar6,uVar14);
  }
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x8c) << 7;
  uVar8 = (uint)uVar4;
  if (local_48[0] <= uVar4) {
    uVar8 = local_48[0];
  }
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x88) << 5;
  uVar9 = (uint)uVar4;
  if (uVar8 <= uVar4) {
    uVar9 = uVar8;
  }
  if (0xfe < uVar9) {
    uVar9 = 0xfe;
  }
  *(uint *)(param_1 + 0x74) = uVar9;
  DoLog("CONFIG: useMsg=%d MaxQueueDepth=%u ringPages=%u useReqCallThreshold=%d\n",
        (ulonglong)(uint)(int)*(char *)(param_1 + 0x49),(ulonglong)uVar9,
        (ulonglong)*(uint *)(param_1 + 0x88));
  return 1;
}



===== PVSCSIFindValueForKeyInString @ 140001fe4 =====

ulonglong PVSCSIFindValueForKeyInString(char *param_1,char *param_2,int *param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  char *pcVar5;
  size_t _MaxCount;
  undefined7 uVar6;
  
  uVar6 = (undefined7)((ulonglong)param_4 >> 8);
  _MaxCount = 0xffffffffffffffff;
  do {
    _MaxCount = _MaxCount + 1;
  } while (param_1[_MaxCount] != '\0');
  uVar4 = Log("Looking for \'%s\' in string \'%s\'\n",param_1,param_2,param_4);
  *param_3 = 0;
  do {
    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
      return uVar4 & 0xffffffffffffff00;
    }
    iVar2 = _strnicmp(param_2,param_1,_MaxCount);
    uVar4 = CONCAT44(extraout_var,iVar2);
    if (iVar2 == 0) {
      iVar2 = 0;
      for (pcVar5 = param_2 + _MaxCount; pcVar5 != (char *)0x0; pcVar5 = pcVar5 + 1) {
        cVar1 = *pcVar5;
        uVar3 = (int)CONCAT71(uVar6,cVar1) - 0x30;
        uVar4 = (ulonglong)uVar3;
        if (9 < (byte)uVar3) break;
        uVar4 = (ulonglong)(uint)(int)cVar1;
        iVar2 = (int)cVar1 + (iVar2 * 5 + -0x18) * 2;
      }
      if (pcVar5 != param_2 + _MaxCount) {
        *param_3 = iVar2;
        return CONCAT71((int7)(uVar4 >> 8),1);
      }
    }
    param_2 = param_2 + 1;
  } while( true );
}



===== PVSCSIGetConfigInfo @ 140002098 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
PVSCSIGetConfigInfo(longlong param_1,int param_2,ulonglong param_3,byte param_4,byte param_5,
                   char param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 local_48 [32];
  longlong local_28;
  ulonglong local_20;
  int local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  if (param_2 == 0x1958) {
    local_20 = 0x212000000000;
  }
  else {
    if (param_2 != 0x1959) {
      if (param_2 != 0x195a) goto LAB_14000210f;
      if (param_6 == '\0') {
        local_20 = (ulonglong)param_4 << 0x10 | (ulonglong)param_5 | 0x212100000000;
        goto LAB_14000210f;
      }
    }
    local_20 = param_3 & 0xffffffff | 0x212200000000;
  }
LAB_14000210f:
  local_18 = param_2;
  puVar1 = *(undefined8 **)(param_1 + 0x98);
  local_14 = 0;
  local_28 = ((ulonglong)*(uint *)(param_1 + 0x8c) + (ulonglong)*(uint *)(param_1 + 0x88) +
             *(longlong *)(param_1 + 0x80) + 1) * 0x1000;
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined4 *)((longlong)puVar1 + 6) = 0x2001a;
  **(undefined4 **)(param_1 + 0x78) = 7;
  LOCK();
  UNLOCK();
  plVar3 = &local_28;
  lVar4 = 6;
  do {
    *(int *)(*(longlong *)(param_1 + 0x78) + 4) = (int)*plVar3;
    LOCK();
    UNLOCK();
    plVar3 = (longlong *)((longlong)plVar3 + 4);
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((*(ushort *)((longlong)puVar1 + 6) == 0) && (*(short *)(puVar1 + 1) == 0)) {
    uVar2 = *(undefined8 *)(param_1 + 0x98);
  }
  else {
    DoLog("GetConfigInfo failed: hostStatus = 0x%x, scsiStatus = 0x%x\n",
          (ulonglong)*(ushort *)((longlong)puVar1 + 6),(ulonglong)*(ushort *)(puVar1 + 1),0);
    uVar2 = 0;
  }
  return uVar2;
}



===== PVSCSIInitHw @ 1400021cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIInitHw(longlong param_1)

{
  char cVar1;
  longlong *plVar2;
  ulonglong uVar3;
  uint *puVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 local_258 [48];
  uint local_228 [2];
  longlong local_220;
  longlong local_218 [32];
  longlong local_118 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_258;
  lVar5 = *(longlong *)(param_1 + 0x80);
  memset(local_228,0,0x210);
  local_228[0] = *(uint *)(param_1 + 0x88);
  uVar3 = (ulonglong)local_228[0];
  local_220 = lVar5;
  lVar5 = lVar5 + 1;
  if (local_228[0] != 0) {
    plVar2 = local_218;
    do {
      *plVar2 = lVar5;
      lVar5 = lVar5 + 1;
      plVar2 = plVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  local_228[1] = *(uint *)(param_1 + 0x8c);
  if (local_228[1] != 0) {
    plVar2 = local_118;
    uVar3 = (ulonglong)local_228[1];
    do {
      *plVar2 = lVar5;
      lVar5 = lVar5 + 1;
      plVar2 = plVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  **(undefined4 **)(param_1 + 0x78) = 3;
  LOCK();
  UNLOCK();
  puVar4 = local_228;
  lVar5 = 0x84;
  do {
    *(uint *)(*(longlong *)(param_1 + 0x78) + 4) = *puVar4;
    LOCK();
    UNLOCK();
    puVar4 = puVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  cVar1 = '\0';
  if (*(char *)(param_1 + 0x49) != '\0') {
    PVSCSISetupMsgRing(param_1);
    cVar1 = *(char *)(param_1 + 0x49);
  }
  **(undefined4 **)(param_1 + 0x78) = 10;
  LOCK();
  UNLOCK();
  if (*(int *)(*(longlong *)(param_1 + 0x78) + 8) == -1) {
    bVar6 = false;
  }
  else {
    **(undefined4 **)(param_1 + 0x78) = 10;
    LOCK();
    UNLOCK();
    *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 4) = 1;
    LOCK();
    UNLOCK();
    bVar6 = *(int *)(*(longlong *)(param_1 + 0x78) + 8) != 0;
  }
  *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) & bVar6;
  *(uint *)(*(longlong *)(param_1 + 0x78) + 0x2010) = (-(uint)(cVar1 != '\0') & 0xc) + 3;
  LOCK();
  UNLOCK();
  return;
}



===== PVSCSIInitialize @ 140002330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PVSCSIInitialize(longlong param_1)

{
  undefined8 uVar1;
  bool bVar2;
  undefined1 auStack_38 [32];
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  bVar2 = DAT_140008841 == '\0';
  *(undefined1 *)(param_1 + 0x48) = 0;
  if (bVar2) {
    local_18[0] = 0;
    StorPortNotification(0x1000,param_1,PVSCSIPassiveInitialize,local_18);
    *(undefined1 *)(param_1 + 0x48) = (undefined1)local_18[0];
  }
  uVar1 = PVSCSIInitHw(param_1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== PVSCSIInterrupt @ 1400023a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 PVSCSIInterrupt(ulonglong param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 local_48 [32];
  undefined8 local_28;
  undefined4 *local_20;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x78) + 0x100c);
  if ((uVar1 == 0xffffffff) || ((uVar1 & 0xf) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *(uint *)(*(longlong *)(param_1 + 0x78) + 0x100c) = uVar1;
    LOCK();
    UNLOCK();
    if (*(char *)(param_1 + 0x48) == '\0') {
      PVSCSIProcessCompletionRing(param_1,param_2,param_3,param_4);
      if ((*(longlong *)(param_1 + 0x68) != 0) &&
         (*(int *)(*(longlong *)(param_1 + 0x50) + 0x80) !=
          *(int *)(*(longlong *)(param_1 + 0x50) + 0x84))) {
        PVSCSIProcessMsgRing(param_1,param_2,param_3,param_4);
      }
    }
    else {
      local_18[0] = 0;
      local_20 = local_18;
      local_28 = 0;
      StorPortNotification(0x1002,param_1,param_1,0);
    }
  }
  return uVar2;
}



===== PVSCSIMSInterrupt @ 140002460 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
PVSCSIMSInterrupt(ulonglong param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 *local_20;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (*(char *)(param_1 + 0x48) == '\0') {
    uVar2 = PVSCSIProcessCompletionRing(param_1,param_2,param_3,param_4);
    if ((*(longlong *)(param_1 + 0x68) != 0) &&
       (uVar1 = *(uint *)(*(longlong *)(param_1 + 0x50) + 0x84), uVar2 = (ulonglong)uVar1,
       *(uint *)(*(longlong *)(param_1 + 0x50) + 0x80) != uVar1)) {
      uVar2 = PVSCSIProcessMsgRing(param_1,param_2,param_3,param_4);
    }
  }
  else {
    local_18[0] = 0;
    local_20 = local_18;
    local_28 = 0;
    uVar2 = StorPortNotification(0x1002,param_1,param_1,0);
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== PVSCSIMoveMemory @ 1400024e4 =====

void PVSCSIMoveMemory(void *param_1,void *param_2,uint param_3)

{
  memmove(param_1,param_2,(ulonglong)param_3);
  return;
}



===== PVSCSIPassiveInitialize @ 1400024f0 =====

undefined1 PVSCSIPassiveInitialize(undefined8 param_1)

{
  StorPortNotification(0x1001,param_1,param_1,PVSCSIDpcRoutine);
  return 1;
}



===== PVSCSIProcessCompletionRing @ 140002514 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIProcessCompletionRing
               (ulonglong param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  byte bVar9;
  undefined7 uVar11;
  ulonglong uVar10;
  ulonglong uVar12;
  char cVar13;
  undefined1 auStack_88 [32];
  undefined1 *local_68;
  char local_58;
  undefined1 local_50 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  cVar13 = *(char *)(param_1 + 0x48);
  local_58 = cVar13;
  if (cVar13 != '\0') {
    memset(local_50,0,0x20);
    local_68 = local_50;
    param_2 = param_1;
    param_4 = param_1;
    StorPortNotification(0x1003,param_1,1);
  }
  lVar4 = *(longlong *)(param_1 + 0x50);
  lVar5 = *(longlong *)(param_1 + 0x60);
  uVar3 = *(undefined4 *)(lVar4 + 0x14);
  uVar7 = *(uint *)(lVar4 + 0x10);
  if (uVar7 != *(uint *)(lVar4 + 0xc)) {
    do {
      lVar8 = (ulonglong)(uVar7 & (1 << ((byte)uVar3 & 0x1f)) - 1U) * 0x20;
      uVar1 = *(ushort *)(lVar8 + 0x14 + lVar5);
      lVar6 = *(longlong *)(lVar8 + lVar5);
      uVar2 = *(ushort *)(lVar8 + 0x16 + lVar5);
      uVar12 = (ulonglong)uVar2;
      uVar11 = (undefined7)(param_2 >> 8);
      if (uVar1 == 0) {
        if (uVar2 != 0) {
LAB_14000260b:
          if (uVar2 == 2) {
            uVar10 = CONCAT71(uVar11,-(*(longlong *)(lVar6 + 0x20) != 0)) & 0xffffffffffffff80;
            uVar11 = (undefined7)(uVar10 >> 8);
            bVar9 = (char)uVar10 + 4;
          }
          else {
            if ((uVar2 - 8 & 0xffffffdf) == 0) goto LAB_1400026bc;
            lVar8 = lVar6;
            Log("srb: %p sdstat=0x%x\n",lVar6,uVar12,param_4);
            uVar11 = (undefined7)((ulonglong)lVar8 >> 8);
            bVar9 = 4;
          }
          goto LAB_1400026be;
        }
        bVar9 = 1;
      }
      else {
        if (uVar1 < 0x1c) {
          if (uVar1 == 0x1b) {
            bVar9 = 0x10;
          }
          else if (uVar1 < 0x13) {
            if (uVar1 == 0x12) {
LAB_14000264c:
              bVar9 = 0x12;
            }
            else {
              if (uVar1 != 0) {
                if (9 < uVar1) {
                  if (uVar1 < 0xc) goto LAB_140002607;
                  if (uVar1 == 0xc) goto LAB_14000264c;
                  if (uVar1 == 0x11) {
                    bVar9 = 10;
                    goto LAB_1400026be;
                  }
                }
                goto LAB_1400026b0;
              }
LAB_140002607:
              if (uVar2 != 0) goto LAB_14000260b;
              bVar9 = 1;
            }
          }
          else if (uVar1 == 0x13) {
            bVar9 = 0x13;
          }
          else {
            if (uVar1 != 0x14) {
              if ((uVar1 == 0x17) || (uVar1 == 0x1a)) goto LAB_140002694;
              goto LAB_1400026b0;
            }
            bVar9 = 0x14;
          }
        }
        else if (uVar1 < 0x26) {
          if (uVar1 == 0x25) {
LAB_140002698:
            bVar9 = 0xe;
          }
          else {
            if (0x1b < uVar1) {
              if (uVar1 < 0x1e) {
LAB_140002694:
                bVar9 = 6;
                goto LAB_1400026be;
              }
              if (uVar1 == 0x20) goto LAB_1400026b8;
              if (0x20 < uVar1) {
                if (uVar1 < 0x24) goto LAB_140002698;
                if (uVar1 == 0x24) goto LAB_140002694;
              }
            }
LAB_1400026b0:
            bVar9 = 0x11;
          }
        }
        else if (uVar1 == 0x26) {
LAB_1400026bc:
          bVar9 = 5;
        }
        else if (uVar1 == 0x27) {
LAB_1400026b8:
          bVar9 = 8;
        }
        else {
          if (uVar1 == 0x30) goto LAB_1400026bc;
          if (uVar1 != 0x34) goto LAB_1400026b0;
          bVar9 = 0xf;
        }
LAB_1400026be:
        if ((bVar9 & 0x3f) != 4) {
          uVar12 = 0;
        }
      }
      *(byte *)(lVar6 + 3) = bVar9;
      param_4 = uVar12 & 0xff;
      *(char *)(lVar6 + 4) = (char)uVar12;
      if (((bVar9 == 1) && (*(char *)(lVar6 + 0x48) == '\x12')) &&
         ((*(uint *)(param_1 + 0x70) >> (*(byte *)(lVar6 + 6) & 0x1f) & 1) == 0)) {
        local_68 = (undefined1 *)CONCAT44(local_68._4_4_,*(undefined4 *)(param_1 + 0x74));
        StorPortSetDeviceQueueDepth
                  (param_1,CONCAT71(uVar11,*(undefined1 *)(lVar6 + 5)),*(byte *)(lVar6 + 6),
                   *(undefined1 *)(lVar6 + 7));
        *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 1 << (*(byte *)(lVar6 + 6) & 0x1f);
        param_4 = (ulonglong)*(byte *)(lVar6 + 4);
        bVar9 = *(byte *)(lVar6 + 3);
      }
      Log("RequestComplete %p: SrbStatus=0x%x ScsiStatus=0x%x\n",lVar6,(ulonglong)bVar9,param_4);
      param_2 = param_1;
      StorPortNotification(0,param_1,lVar6);
      uVar7 = *(int *)(lVar4 + 0x10) + 1;
      *(uint *)(lVar4 + 0x10) = uVar7;
    } while (uVar7 != *(uint *)(lVar4 + 0xc));
    cVar13 = local_58;
  }
  if (cVar13 != '\0') {
    StorPortNotification(0x1004,param_1,local_50);
  }
  return;
}



===== PVSCSIProcessMsgRing @ 140002794 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIProcessMsgRing(ulonglong param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  char *pcVar6;
  uint *puVar7;
  undefined1 auStack_78 [32];
  undefined1 *local_58;
  undefined1 local_48 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  cVar1 = *(char *)(param_1 + 0x48);
  if (cVar1 != '\0') {
    memset(local_48,0,0x20);
    local_58 = local_48;
    param_3 = 1;
    param_4 = param_1;
    StorPortNotification(0x1003,param_1);
  }
  lVar3 = *(longlong *)(param_1 + 0x50);
  lVar4 = *(longlong *)(param_1 + 0x68);
  uVar2 = *(undefined4 *)(lVar3 + 0x88);
  uVar5 = *(uint *)(lVar3 + 0x84);
  while (*(uint *)(lVar3 + 0x80) != uVar5) {
    puVar7 = (uint *)((ulonglong)((1 << ((byte)uVar2 & 0x1f)) - 1U & uVar5) * 0x80 + lVar4);
    uVar5 = *puVar7;
    if (uVar5 < 2) {
      if (uVar5 < 2) {
        param_4 = (ulonglong)puVar7[2];
        pcVar6 = "removal";
        local_58 = (undefined1 *)CONCAT44(local_58._4_4_,(uint)*(byte *)((longlong)puVar7 + 0xd));
        if (uVar5 == 0) {
          pcVar6 = "addition";
        }
        param_3 = (ulonglong)puVar7[1];
        DoLog("MSG: device %s at scsi%u:%u:%u\n",pcVar6,param_3,param_4);
        *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & ~(1 << ((byte)puVar7[2] & 0x1f));
        if (puVar7[1] == 0) {
          param_3 = 0;
          StorPortNotification(7,param_1);
        }
      }
      else {
        DoLog("Unknown msg type: 0x%x\n",(ulonglong)uVar5,param_3,param_4);
      }
    }
    else {
      Log("Unknown msg type: 0x%x\n",(ulonglong)uVar5,param_3,param_4);
    }
    uVar5 = *(int *)(lVar3 + 0x84) + 1;
    *(uint *)(lVar3 + 0x84) = uVar5;
  }
  if (cVar1 != '\0') {
    StorPortNotification(0x1004,param_1,local_48);
  }
  return;
}



===== PVSCSIResetBus @ 140002900 =====

undefined8 PVSCSIResetBus(ulonglong param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = param_2 & 0xffffffff;
  Log("ResetBus start path=%u\n",param_2,param_3,param_4);
  *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x90;
  LOCK();
  UNLOCK();
  if (DAT_140008841 == '\0') {
    PVSCSIDoResetBus(param_1,uVar2,param_3,param_4);
  }
  else {
    Log("ResetBus during crash dump is ignored.\n",param_2,param_3,param_4);
  }
  lVar1 = *(longlong *)(param_1 + 0x78);
  *(undefined4 *)(lVar1 + 0x3018) = 0x91;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
}



===== PVSCSISendSCSICmd @ 140002970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PVSCSISendSCSICmd(longlong param_1,longlong param_2)

{
  char cVar1;
  uint *puVar2;
  int *piVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  longlong *plVar9;
  undefined8 uVar10;
  uint *puVar11;
  undefined1 local_58 [32];
  uint local_38 [2];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_58;
  puVar2 = *(uint **)(param_1 + 0x50);
  uVar8 = 1 << ((byte)puVar2[2] & 0x1f);
  if (uVar8 <= *puVar2 - puVar2[4]) {
    StorPortDebugPrint(0,"Not enough room on completion ring.\n");
    *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3018) = 0x859;
    LOCK();
    UNLOCK();
    *(uint *)(*(longlong *)(param_1 + 0x78) + 0x3018) = *puVar2 - puVar2[1];
    LOCK();
    UNLOCK();
    uVar5 = *(ulonglong *)(param_1 + 0x78);
    *(uint *)(uVar5 + 0x3018) = puVar2[3] - puVar2[4];
LAB_1400029ff:
    LOCK();
    UNLOCK();
    return uVar5 & 0xffffffffffffff00;
  }
  plVar9 = (longlong *)((ulonglong)(uVar8 - 1 & *puVar2) * 0x80 + *(longlong *)(param_1 + 0x58));
  *(undefined1 *)((longlong)plVar9 + 0x42) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)((longlong)plVar9 + 0x43) = *(undefined1 *)(param_2 + 6);
  *(undefined8 *)((longlong)plVar9 + 0x39) = 0;
  *(undefined1 *)((longlong)plVar9 + 0x3a) = *(undefined1 *)(param_2 + 7);
  plVar9[2] = (ulonglong)*(uint *)(param_2 + 0x10);
  *(uint *)(plVar9 + 4) = (uint)*(byte *)(param_2 + 0xb);
  plVar9[1] = 0;
  plVar9[3] = 0;
  bVar4 = *(byte *)(param_2 + 10);
  *(byte *)(plVar9 + 7) = bVar4;
  *(undefined1 *)((longlong)plVar9 + 0x44) = SystemReserved1[0xe]._4_1_;
  memmove(plVar9 + 5,(void *)(param_2 + 0x48),(ulonglong)bVar4);
  *(undefined1 *)((longlong)plVar9 + 0x41) = 0x20;
  if ((*(uint *)(param_2 + 0xc) & 2) != 0) {
    *(undefined1 *)((longlong)plVar9 + 0x41) = *(undefined1 *)(param_2 + 9);
  }
  *(undefined4 *)((longlong)plVar9 + 0x24) = 0;
  uVar8 = *(uint *)(param_2 + 0xc) & 0xc0;
  if (uVar8 == 0) {
    *(undefined4 *)((longlong)plVar9 + 0x24) = 4;
    uVar5 = 0;
  }
  else if (uVar8 == 0x40) {
    *(undefined4 *)((longlong)plVar9 + 0x24) = 8;
    uVar5 = 0;
  }
  else {
    uVar5 = (ulonglong)(uVar8 - 0x80);
    if (uVar8 - 0x80 == 0) {
      *(undefined4 *)((longlong)plVar9 + 0x24) = 0x10;
    }
  }
  if (plVar9[2] != 0) {
    plVar7 = (longlong *)((longlong)*(uint **)(param_2 + 0x38) + 0x13U & 0xfffffffffffffff0);
    if (**(uint **)(param_2 + 0x38) < 2) {
      plVar9[1] = *plVar7;
      uVar5 = (ulonglong)*(uint *)(plVar7 + 1);
      plVar9[2] = uVar5;
    }
    else {
      local_38[0] = 0;
      *(uint *)((longlong)plVar9 + 0x24) = *(uint *)((longlong)plVar9 + 0x24) | 1;
      uVar5 = StorPortGetPhysicalAddress(param_1,0,plVar7,local_38);
      plVar9[1] = uVar5;
      if ((uVar5 == 0) || (local_38[0] < 0x824)) {
        StorPortDebugPrint(0,"Failed to get PA of s/g table\n");
        uVar5 = *(ulonglong *)(param_1 + 0x78);
        *(undefined4 *)(uVar5 + 0x3018) = 0x89b;
        goto LAB_1400029ff;
      }
    }
  }
  if ((int)plVar9[4] != 0) {
    uVar10 = *(undefined8 *)(param_2 + 0x20);
    puVar11 = local_38;
    local_38[0] = 0;
    lVar6 = StorPortGetPhysicalAddress(param_1,param_2);
    plVar9[3] = lVar6;
    if ((lVar6 == 0) ||
       (uVar5 = (ulonglong)*(uint *)(plVar9 + 4), local_38[0] < *(uint *)(plVar9 + 4))) {
      StorPortDebugPrint(0,"Failed to get PA of sense buffer\n");
      Log("GetPhysicalAddress for sense buf failed: %u\n",(ulonglong)local_38[0],uVar10,puVar11);
      uVar5 = *(ulonglong *)(param_1 + 0x78);
      *(undefined4 *)(uVar5 + 0x3018) = 0x8af;
      goto LAB_1400029ff;
    }
  }
  *plVar9 = param_2;
  cVar1 = *(char *)(param_2 + 0x48);
  *puVar2 = *puVar2 + 1;
  bVar4 = cVar1 - 8;
  uVar5 = CONCAT71((int7)(uVar5 >> 8),bVar4);
  if ((bVar4 & 0x5d) == 0) {
    if (*(char *)(param_1 + 0x4a) != '\0') {
      piVar3 = *(int **)(param_1 + 0x50);
      uVar5 = (ulonglong)(uint)piVar3[1];
      if ((uint)(*piVar3 - piVar3[1]) < (uint)piVar3[6]) goto LAB_140002bbb;
    }
    uVar5 = *(ulonglong *)(param_1 + 0x78);
    *(undefined4 *)(uVar5 + 0x4018) = 0;
  }
  else {
    *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x3014) = 0;
  }
  LOCK();
  UNLOCK();
LAB_140002bbb:
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== PVSCSISetupMsgRing @ 140002bdc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSISetupMsgRing(longlong param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  uint *puVar3;
  longlong lVar4;
  undefined1 local_c8 [32];
  uint local_a8;
  undefined1 local_a4 [4];
  longlong local_a0 [17];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_c8;
  lVar4 = *(longlong *)(param_1 + 0x80) + 2 +
          (ulonglong)*(uint *)(param_1 + 0x8c) + (ulonglong)*(uint *)(param_1 + 0x88);
  memset(local_a4,0,0x84);
  local_a8 = *(uint *)(param_1 + 0x90);
  uVar2 = (ulonglong)local_a8;
  if (local_a8 != 0) {
    plVar1 = local_a0;
    do {
      *plVar1 = lVar4;
      lVar4 = lVar4 + 1;
      plVar1 = plVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  **(undefined4 **)(param_1 + 0x78) = 8;
  LOCK();
  UNLOCK();
  puVar3 = &local_a8;
  lVar4 = 0x22;
  do {
    *(uint *)(*(longlong *)(param_1 + 0x78) + 4) = *puVar3;
    LOCK();
    UNLOCK();
    puVar3 = puVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== PVSCSIStartIo @ 140002cb0 =====

undefined8 PVSCSIStartIo(ulonglong param_1,ulonglong param_2)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  bVar2 = *(byte *)(param_2 + 2);
  if (bVar2 == 0) {
    Log("StartIo: EXECUTE_SCSI %p scsi%u:%u:%u -- cdb0=0x%x len=%u\n",param_2,
        (ulonglong)*(byte *)(param_2 + 5),(ulonglong)*(byte *)(param_2 + 6));
    *(undefined1 *)(param_2 + 3) = 0;
    uVar3 = PVSCSISendSCSICmd(param_1,param_2);
    if ((char)uVar3 != '\0') goto LAB_140002e21;
    bVar2 = 5;
    *(undefined2 *)(param_2 + 3) = 5;
  }
  else {
    uVar5 = (ulonglong)bVar2;
    pcVar4 = Fun2Str(bVar2);
    uVar3 = param_2;
    Log("StartIo:%s (0x%x) %p scsi%u:%u:%u\n",pcVar4,uVar5,param_2);
    bVar2 = *(byte *)(param_2 + 2);
    if (bVar2 == 2) {
      lVar1 = *(longlong *)(param_2 + 0x18);
      if (lVar1 == 0) {
        Log("IO_CONTROL: ctl is NULL\n",2,uVar5,uVar3);
      }
      else {
        Log("IO_CONTROL: \'%8s\' - code=0x%x len=%u\n",lVar1 + 4,(ulonglong)*(uint *)(lVar1 + 0x10),
            (ulonglong)*(uint *)(lVar1 + 0x18));
      }
LAB_140002df7:
      bVar2 = 6;
      *(undefined1 *)(param_2 + 3) = 6;
    }
    else if (bVar2 == 0x10) {
      PVSCSIAbortCmd(param_1,param_2);
      bVar2 = *(byte *)(param_2 + 3);
    }
    else {
      if (bVar2 != 0x12) {
        if (bVar2 != 0x13) {
          if (bVar2 == 0x17) {
            uVar3 = PVSCSIWmiSrb(param_1,param_2,uVar5,uVar3);
            goto LAB_140002e21;
          }
          if (bVar2 != 0x20) {
            Log("StartIo: failing function 0x%x\n",(ulonglong)bVar2,uVar5,uVar3);
            goto LAB_140002df7;
          }
        }
        uVar3 = PVSCSIDoResetDevice(param_1,param_2);
        goto LAB_140002e21;
      }
      PVSCSIDoResetBus(param_1,(ulonglong)*(byte *)(param_2 + 5),uVar5,uVar3);
      bVar2 = 1;
      *(undefined1 *)(param_2 + 3) = 1;
    }
  }
  Log("RequestComplete %p: SrbStatus=0x%x ScsiStatus=0x%x\n",param_2,(ulonglong)bVar2,
      (ulonglong)*(byte *)(param_2 + 4));
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_140002e21:
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== PrintSRB @ 140002e30 =====

void PrintSRB(ushort *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  Log("SRB: CDB[0]=0x%x\n",(ulonglong)(byte)param_1[0x24],param_3,param_4);
  Log("SRB: Length=%u Function=%u SrbStatus=%u\n",(ulonglong)*param_1,(ulonglong)(byte)param_1[1],
      (ulonglong)*(byte *)((longlong)param_1 + 3));
  Log("SRB: ScsiStatus=%u PathId=%u TargetId=%u\n",(ulonglong)(byte)param_1[2],
      (ulonglong)*(byte *)((longlong)param_1 + 5),(ulonglong)(byte)param_1[3]);
  Log("SRB: Lun=%u QueueTag=%u QueueAction=%u CdbLength=%u\n",
      (ulonglong)*(byte *)((longlong)param_1 + 7),(ulonglong)(byte)param_1[4],
      (ulonglong)*(byte *)((longlong)param_1 + 9));
  Log("SRB: SenseInfoBufferLength=%u SrbFlags=0x%x DataTransferLength=%u\n",
      (ulonglong)*(byte *)((longlong)param_1 + 0xb),(ulonglong)*(uint *)(param_1 + 6),
      (ulonglong)*(uint *)(param_1 + 8));
  Log("SRB: TimeOutValue=%u DataBuffer=0x%p SenseInfoBuffer=0x%p\n",
      (ulonglong)*(uint *)(param_1 + 10),*(undefined8 *)(param_1 + 0xc),
      *(undefined8 *)(param_1 + 0x10));
  Log("SRB: NextSrb=0x%p OriginalRequest=0x%p SrbExtension=0x%p\n",*(undefined8 *)(param_1 + 0x14),
      *(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x1c));
  return;
}



===== PVSCSIGetHBAAttributes @ 140002eec =====

bool PVSCSIGetHBAAttributes(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar2 = 0x1958;
  uVar4 = 0;
  uVar3 = 0;
  lVar1 = PVSCSIGetConfigInfo(param_1,0x1958,0,0,0,'\0');
  if (lVar1 != 0) {
    memset((void *)((longlong)param_2 + 0xc),0,0x1724);
    *(undefined4 *)(param_2 + 1) = 0;
    *param_2 = param_1;
    *(undefined4 *)((longlong)param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x1d8);
    *(undefined4 *)(param_2 + 2) = 0x15ad;
    *(undefined2 *)((longlong)param_2 + 0x14) = 0x80;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x16),(void *)(lVar1 + 0x18),0x80);
    *(undefined2 *)((longlong)param_2 + 0x96) = 0x80;
    PVSCSIMoveMemory(param_2 + 0x13,(void *)(lVar1 + 0x98),0x80);
    *(undefined2 *)(param_2 + 0x23) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x11a),&u_PVSCSI_Controll,0x24);
    *(undefined2 *)((longlong)param_2 + 0x31a) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x31c),&u_PVSCSI_Controll,0x24);
    *(undefined2 *)((longlong)param_2 + 0x51c) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x51e),(void *)(lVar1 + 0x158),0x40);
    *(undefined2 *)((longlong)param_2 + 0x71e) = 0x200;
    PVSCSIMoveMemory(param_2 + 0xe4,&u_1_3_15_0,0x12);
    *(undefined2 *)(param_2 + 0x124) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x922),(void *)(lVar1 + 0x118),0x40);
    *(undefined2 *)((longlong)param_2 + 0xb22) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0xb24),(void *)(lVar1 + 0x198),0x40);
    *(undefined2 *)((longlong)param_2 + 0xd24) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0xd26),L"pvscsii.sys",0x18);
    *(undefined2 *)((longlong)param_2 + 0xf26) = 0x200;
    PVSCSIMoveMemory(param_2 + 0x1e5,&u_PVSCSI_Controll,0x24);
    *(undefined2 *)(param_2 + 0x225) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x112a),&u_,2);
    *(undefined2 *)((longlong)param_2 + 0x132a) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x132c),&u_,2);
    *(undefined2 *)((longlong)param_2 + 0x152c) = 0x200;
    PVSCSIMoveMemory((void *)((longlong)param_2 + 0x152e),(void *)(lVar1 + 0x18),0x80);
  }
  else {
    Log("GetHBAAttributes: GetConfigInfo failed.\n",uVar2,uVar3,uVar4);
  }
  return lVar1 != 0;
}



===== PVSCSIQueryWmiDataBlock @ 140003120 =====

char PVSCSIQueryWmiDataBlock
               (longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4,int param_5,
               undefined4 *param_6,uint param_7,longlong *param_8)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  
  if (((int)param_4 == 0) && (cVar2 = '\x01', param_5 == 1)) {
    if ((int)param_3 == 0) {
      uVar3 = 0x1730;
      if (param_7 < 0x1730) {
        Log("QueryWmiDataBlock: Not enough space to return data for idx 0. bufferAvail = %d bytes, buffer reqd. = %d bytes\n"
            ,(ulonglong)param_7,0x1730,param_4);
        cVar2 = '\x12';
        goto LAB_1400031a3;
      }
      bVar1 = PVSCSIGetHBAAttributes(param_1,param_8);
      if (bVar1) {
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = 0x1730;
        }
        goto LAB_1400031a3;
      }
      Log("QueryWmiDataBlock: GetHBAAttributes failed.\n",param_8,param_3,param_4);
    }
    else {
      Log("QueryWmiDataBlock: unsupported query with idx = %d.\n",param_3 & 0xffffffff,param_3,
          param_4);
    }
  }
  cVar2 = '\x04';
  uVar3 = 0;
LAB_1400031a3:
  ScsiPortWmiPostProcess(param_2,cVar2,uVar3);
  return cVar2;
}



===== PVSCSIQueryWmiRegInfo @ 1400031d0 =====

char * PVSCSIQueryWmiRegInfo
                 (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  Log("PVSCSIQueryWmiRegInfo called.\n",param_2,param_3,param_4);
  *param_3 = L"MofResource";
  return "VSCSIQueryWmiRegInfo called.\n";
}



===== PVSCSIWmiInitialize @ 1400031f8 =====

void PVSCSIWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0xa0) = 1;
  *(undefined ***)(param_1 + 0xa8) = &pvscsiGuidList;
  *(code **)(param_1 + 0xb0) = PVSCSIQueryWmiRegInfo;
  *(code **)(param_1 + 0xb8) = PVSCSIQueryWmiDataBlock;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  return;
}



===== PVSCSIWmiSrb @ 14000324c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PVSCSIWmiSrb(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStackY_78 [32];
  undefined1 local_38 [25];
  byte local_1f;
  uint local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar1 = 0;
  uVar2 = 0x20;
  memset(local_38,0,0x20);
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    Log("PVSCSIWmiSrb: unsupported disk wmi srb.\n",uVar1,uVar2,param_4);
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    uVar2 = CONCAT71((int7)((ulonglong)uVar1 >> 8),*(byte *)(param_2 + 4));
    puVar4 = local_38;
    lVar3 = param_1;
    uVar1 = ScsiPortWmiDispatchFunction
                      ((uint *)(param_1 + 0xa0),*(byte *)(param_2 + 4),param_1,(longlong)puVar4,
                       *(ulonglong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                       *(uint **)(param_2 + 0x18));
    if ((char)uVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
      Panic("PVSCSIWmiSrb: pending adapter wmi srb. Not expected.\n",uVar2,lVar3,puVar4);
    }
    *(uint *)(param_2 + 0x10) = local_1c;
    *(byte *)(param_2 + 3) = local_1f;
    Log("PVSCSIWmiSrb: DataTransferLength = %u bytes, SrbStatus = 0x%x\n",(ulonglong)local_1c,
        (ulonglong)local_1f,puVar4);
  }
  StorPortNotification(0,param_1,param_2);
  return;
}



===== __security_check_cookie @ 140003330 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 140003350 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== StorPortInitialize @ 14000337d =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000337d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortFreeDeviceBase @ 140003383 =====

void StorPortFreeDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140003383. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortFreeDeviceBase();
  return;
}



===== StorPortGetDeviceBase @ 140003389 =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140003389. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortGetScatterGatherList @ 14000338f =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000338f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortGetPhysicalAddress @ 140003395 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140003395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 14000339b =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000339b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortPauseDevice @ 1400033a1 =====

void StorPortPauseDevice(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400033a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortPauseDevice();
  return;
}



===== StorPortResumeDevice @ 1400033a7 =====

void StorPortResumeDevice(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400033a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResumeDevice();
  return;
}



===== StorPortSetDeviceQueueDepth @ 1400033ad =====

void StorPortSetDeviceQueueDepth(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400033ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetDeviceQueueDepth();
  return;
}



===== StorPortNotification @ 1400033b3 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400033b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortDebugPrint @ 1400033b9 =====

void StorPortDebugPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400033b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortDebugPrint();
  return;
}



===== __GSHandlerCheck @ 1400033c0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400033e0 =====

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



===== _strnicmp @ 140003440 =====

int __cdecl _strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140003440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _strnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== ScsiPortWmiDispatchFunction @ 140003448 =====

undefined8
ScsiPortWmiDispatchFunction
          (uint *param_1,byte param_2,undefined8 param_3,longlong param_4,ulonglong *param_5,
          uint param_6,uint *param_7)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined7 extraout_var;
  uint local_res10 [6];
  int local_18 [4];
  
  local_res10[0] = 0;
  *(undefined4 *)(param_4 + 0x1c) = 0;
  if (param_2 < 10) {
    *(uint **)(param_4 + 0x10) = param_7;
    *(uint *)(param_4 + 8) = param_6;
    *(byte *)(param_4 + 0x18) = param_2;
    cVar1 = ScsiWmipProcessRequest
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_res10,
                       (short *)local_18);
    uVar2 = extraout_var;
    if (local_18[0] == 1) {
      *(char *)(param_4 + 0x19) = cVar1;
      if (cVar1 != '\x01') {
        local_res10[0] = 0;
      }
      *(uint *)(param_4 + 0x1c) = local_res10[0];
    }
  }
  else {
    uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
    cVar1 = '\x04';
    *(undefined1 *)(param_4 + 0x19) = 4;
  }
  return CONCAT71(uVar2,cVar1 == '\0');
}



===== ScsiPortWmiPostProcess @ 1400034e8 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 140003520 =====

ulonglong ScsiWmipFindGuid(longlong *param_1,uint param_2,ulonglong *param_3,uint *param_4,
                          undefined4 *param_5)

{
  ulonglong in_RAX;
  uint uVar1;
  longlong *plVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    plVar2 = param_1;
    do {
      in_RAX = *param_3;
      if ((in_RAX == *(ulonglong *)*plVar2) &&
         (in_RAX = param_3[1], in_RAX == ((ulonglong *)*plVar2)[1])) {
        *param_4 = uVar1;
        *param_5 = (int)param_1[(ulonglong)uVar1 * 2 + 1];
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
      uVar1 = uVar1 + 1;
      plVar2 = plVar2 + 2;
    } while (uVar1 < param_2);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ScsiWmipPostProcess @ 140003580 =====

char ScsiWmipPostProcess(char param_1,uint *param_2,uint param_3,uint param_4,char param_5,
                        uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (param_1 == '\0') {
    uVar5 = param_2[0xc];
    uVar1 = param_2[0xd];
    uVar6 = (ulonglong)uVar1;
    uVar2 = uVar5 + param_4;
    if (param_5 == '\x01') {
      if (uVar2 <= param_3) {
        if (((0x2f < param_3) && (*param_2 = uVar2, uVar7 = uVar2, (char)param_2[0xb] < '\0')) &&
           (puVar4 = param_2 + 0xf, uVar3 = uVar6, uVar1 != 0)) {
          do {
            uVar2 = (int)uVar3 - 1;
            uVar3 = (ulonglong)uVar2;
            if (uVar3 * 8 + 0x48 <= (ulonglong)param_3) {
              param_2[uVar3 * 2 + 0x10] = puVar4[uVar3];
            }
          } while (uVar2 != 0);
          if (uVar1 != 0) {
            uVar3 = 0x48;
            do {
              if (uVar3 <= param_3) {
                *puVar4 = uVar5;
                uVar5 = uVar5 + 7 + puVar4[1] & 0xfffffff8;
              }
              uVar3 = uVar3 + 8;
              puVar4 = puVar4 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
        }
        goto LAB_140003648;
      }
      param_5 = '\x12';
    }
LAB_140003626:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140003648;
    param_2[0xc] = uVar2;
  }
  else {
    if (param_1 == '\x01') {
      uVar2 = param_2[0xe] + param_4;
      if (param_5 == '\x01') {
        if (0x2f < param_3) {
          *param_2 = uVar2;
          uVar7 = uVar2;
        }
        goto LAB_140003648;
      }
      goto LAB_140003626;
    }
    if (param_1 != '\t') goto LAB_140003648;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar7 = uVar5;
      }
      goto LAB_140003648;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140003648;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar7 = 0x38;
LAB_140003648:
  *param_6 = uVar7;
  return param_5;
}



===== ScsiWmipProcessRequest @ 1400036d0 =====

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,ulonglong *param_5,
               uint param_6,uint *param_7,uint *param_8,short *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  short *psVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  code *pcVar8;
  uint uVar9;
  ulonglong *puVar10;
  undefined2 *puVar11;
  longlong lVar12;
  int *piVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  ushort uVar18;
  uint local_res10 [2];
  uint uVar19;
  undefined8 uVar20;
  uint local_38 [4];
  
  puVar14 = (uint *)0x0;
  local_res10[0] = 0;
  local_38[0] = 0;
  psVar4 = param_9;
  psVar4[0] = 0;
  psVar4[1] = 0;
  uVar6 = 0;
  if (param_2 != 8) {
    uVar7 = ScsiWmipFindGuid(*(longlong **)(param_1 + 2),*param_1,param_5,local_res10,local_38);
    if ((char)uVar7 == '\0') {
LAB_1400037c7:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_140003ae1;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_1400037c7;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_14000380c;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar6 = local_38[0] * 8 + 0x40;
        param_7[0xd] = local_38[0];
        param_7[0xc] = uVar6;
        if (param_6 < uVar6) {
          lVar12 = 0;
          iVar16 = 0;
        }
        else {
          puVar14 = param_7 + 0xf;
          lVar12 = (ulonglong)uVar6 + (longlong)param_7;
          iVar16 = param_6 - uVar6;
        }
        uVar6 = 0;
        uVar19 = local_38[0];
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            if (*(code **)(param_1 + 8) != (code *)0x0) {
              cVar5 = (**(code **)(param_1 + 8))
                                (param_3,param_4,local_res10[0],uVar6,param_7[0xf],
                                 (ulonglong)param_7[0xe] + (longlong)param_7);
              return cVar5;
            }
          }
          else if (param_2 == 3) {
            if (*(code **)(param_1 + 10) != (code *)0x0) {
              cVar5 = (**(code **)(param_1 + 10))
                                (param_3,param_4,local_res10[0],uVar6,param_7[0xe],param_7[0x10],
                                 (ulonglong)param_7[0xf] + (longlong)param_7);
              return cVar5;
            }
          }
          else if (param_2 == 4) {
            pcVar8 = *(code **)(param_1 + 0xe);
            if (pcVar8 != (code *)0x0) {
              uVar17 = 0;
              goto LAB_140003b08;
            }
            goto LAB_140003b1b;
          }
LAB_14000380c:
          cVar5 = '\x04';
          goto LAB_140003b1d;
        }
        if (param_6 < 0x40) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
            return '\x12';
          }
          *param_7 = 0x40;
          return '\x12';
        }
        puVar14 = param_7 + 0xf;
        iVar16 = param_6 - param_7[0xe];
        lVar12 = (longlong)param_7 + (ulonglong)param_7[0xe];
        uVar19 = 1;
      }
      pcVar8 = *(code **)(param_1 + 6);
LAB_1400038ec:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar6,uVar19,puVar14,iVar16,lVar12);
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 0;
      goto LAB_140003b0c;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar17 = 1;
LAB_140003b08:
      uVar20 = 1;
LAB_140003b0c:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar17,uVar20);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (param_2 == 9) {
          pcVar8 = *(code **)(param_1 + 0xc);
          if ((pcVar8 != (code *)0x0) && (0x47 < param_6)) {
            uVar19 = param_7[0xf];
            if (uVar19 <= param_6) {
              lVar12 = (longlong)param_7 + (ulonglong)uVar19;
              iVar16 = param_6 - uVar19;
              puVar14 = (uint *)(ulonglong)param_7[0x10];
              uVar19 = param_7[0xe];
              goto LAB_1400038ec;
            }
          }
          cVar5 = '\x04';
          goto LAB_140003b1d;
        }
        goto LAB_14000380c;
      }
      cVar5 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar5 == '\x01') {
        uVar19 = *param_1;
        uVar7 = (ulonglong)uVar19;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar15 = uVar19 * 0x20 + 0x18;
        uVar6 = uVar19 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar18 = 0;
        }
        else {
          uVar18 = 0;
          sVar2 = *param_9;
          while (sVar2 != 0) {
            uVar18 = uVar18 + 1;
            sVar2 = param_9[uVar18];
          }
          uVar18 = uVar18 * 2;
        }
        uVar9 = uVar18 + uVar6;
        if ((uVar9 < uVar6) || (uVar1 = uVar9 + 2, uVar1 < uVar9)) {
          cVar5 = '\x04';
          goto LAB_140003ad4;
        }
        if (param_6 < uVar1) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
          }
          else {
            *param_7 = uVar1;
            param_6 = 4;
          }
        }
        else {
          *param_7 = uVar1;
          param_7[1] = 0;
          param_7[2] = 0;
          param_7[3] = uVar6;
          param_7[4] = uVar19;
          if (uVar19 != 0) {
            piVar13 = (int *)(lVar12 + 8);
            puVar10 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(piVar13 + -2))[1];
              puVar10[-3] = **(ulonglong **)(piVar13 + -2);
              puVar10[-2] = uVar3;
              if (*piVar13 == -1) {
                *(int *)(puVar10 + -1) = piVar13[1];
                iVar16 = 0;
                *puVar10 = 0;
              }
              else {
                *(uint *)(puVar10 + -1) = piVar13[1] | 8;
                *puVar10 = (ulonglong)uVar15;
                iVar16 = *piVar13;
              }
              *(int *)((longlong)puVar10 + -4) = iVar16;
              piVar13 = piVar13 + 4;
              puVar10 = puVar10 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          puVar11 = (undefined2 *)((ulonglong)uVar15 + (longlong)param_7);
          *puVar11 = 0x1a;
          memmove(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar6 + (longlong)param_7) = uVar18;
          memmove((ushort *)((ulonglong)uVar6 + (longlong)param_7) + 1,param_9,(ulonglong)uVar18);
          param_6 = uVar1;
        }
      }
      else {
LAB_140003ad4:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_140003ae1:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 1;
      goto LAB_140003b0c;
    }
  }
LAB_140003b1b:
  cVar5 = '\x01';
LAB_140003b1d:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== RpcVMX_Log @ 140003b40 =====

void RpcVMX_Log(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  RpcVMX_LogV(param_1,(va_list)&local_res10);
  return;
}



===== RpcVMX_LogSetPrefix @ 140003b68 =====

void RpcVMX_LogSetPrefix(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while (*(char *)((longlong)param_1 + lVar2 + 1) != '\0');
  if (lVar2 + 5U < 0x803) {
    Str_Strcpy(&DAT_140008034,param_1,0x800);
    DAT_140008834 = (int)lVar2 + 5;
  }
  else {
    DAT_140008834 = 4;
  }
  return;
}



===== RpcVMX_LogV @ 140003bb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RpcVMX_LogV(char *param_1,va_list param_2)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  iVar1 = Str_Vsnprintf(&DAT_140008030 + DAT_140008834,0x804 - (ulonglong)DAT_140008834,param_1,
                        param_2);
  if (iVar1 < 1) {
    iVar1 = 0x804 - DAT_140008834;
  }
  RpcOut_SendOneRawPreallocated
            ((uint *)&DAT_140008030,(ulonglong)(DAT_140008834 + iVar1),local_28,0x10);
  return;
}



===== RpcVMX_ReportDriverVersion @ 140003c2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RpcVMX_ReportDriverVersion(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  char local_98 [128];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar1 = param_1;
  local_a8 = param_2;
  Str_Sprintf(local_98,0x80,"info-set guestinfo.driver.%s.version %s",param_1);
  RpcOut_sendOne((longlong *)0x0,(size_t *)0x0,local_98,uVar1);
  RpcVMX_Log("Driver=%s, Version=%s",param_1,param_2,uVar1);
  return;
}



===== RpcOutSendOneRawWork @ 140003cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RpcOutSendOneRawWork
                    (uint *param_1,longlong param_2,void *param_3,longlong param_4,longlong *param_5
                    ,size_t *param_6)

{
  longlong lVar1;
  char cVar2;
  bool bVar3;
  void *pvVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined1 auStackY_b8 [32];
  char local_88 [8];
  size_t local_80;
  void *local_78;
  short local_70 [24];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  Debug();
  memset(local_70,0,0x30);
  pvVar4 = (void *)RpcOut_startWithReceiveBuffer(local_70,(longlong)param_3,param_4);
  uVar9 = 0;
  if ((char)pvVar4 == '\0') {
    uVar5 = 0xffffffffffffffff;
    do {
      uVar8 = uVar5 + 1;
      lVar1 = uVar5 + 1;
      uVar5 = uVar8;
    } while ("RpcOut: Unable to open the communication channel"[lVar1] != '\0');
    if (param_3 != (void *)0x0) {
      uVar7 = (uint)uVar8;
      if (param_4 - 1U < uVar8) {
        uVar7 = (int)param_4 - 1;
      }
      pvVar4 = memmove(param_3,"RpcOut: Unable to open the communication channel",(ulonglong)uVar7);
      *(undefined1 *)((ulonglong)uVar7 + (longlong)param_3) = 0;
    }
    if (param_5 != (longlong *)0x0) {
      *param_5 = 0;
    }
    uVar5 = (ulonglong)pvVar4 & 0xffffffffffffff00;
  }
  else {
    uVar5 = RpcOut_send(local_70,param_1,param_2,local_88,(longlong *)&local_78,&local_80);
    cVar2 = (char)uVar5;
    Debug();
    if (param_5 != (longlong *)0x0) {
      if (local_78 == (void *)0x0) {
        *param_5 = 0;
      }
      else {
        pvVar4 = malloc(local_80 + 1);
        *param_5 = (longlong)pvVar4;
        if (pvVar4 != (void *)0x0) {
          memmove(pvVar4,local_78,local_80);
          *(undefined1 *)(local_80 + *param_5) = 0;
        }
      }
      if ((param_6 != (size_t *)0x0) && (*param_5 != 0)) {
        *param_6 = local_80;
      }
    }
    bVar3 = RpcOut_stop(local_70);
    uVar6 = extraout_var;
    if (!bVar3) {
      if (param_5 != (longlong *)0x0) {
        free((void *)*param_5);
        *param_5 = 0;
      }
      Debug();
      cVar2 = '\0';
      uVar6 = extraout_var_00;
    }
    if ((cVar2 != '\0') && (local_88[0] != '\0')) {
      uVar9 = 1;
    }
    uVar5 = CONCAT71(uVar6,uVar9);
  }
  return uVar5;
}



===== RpcOut_SendOneRawPreallocated @ 140003e64 =====

void RpcOut_SendOneRawPreallocated(uint *param_1,longlong param_2,void *param_3,longlong param_4)

{
  RpcOutSendOneRawWork(param_1,param_2,param_3,param_4,(longlong *)0x0,(size_t *)0x0);
  return;
}



===== RpcOut_send @ 140003e80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RpcOut_send(short *param_1,uint *param_2,longlong param_3,undefined8 param_4,
                     longlong *param_5,ulonglong *param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_68 [32];
  char *local_48;
  ulonglong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  uVar4 = Message_Send(param_1,param_2,param_3);
  if ((char)uVar4 == '\0') {
    *param_5 = (longlong)"RpcOut: Unable to send the RPCI command";
    uVar4 = 0xffffffffffffffff;
    do {
      uVar5 = uVar4 + 1;
      lVar1 = uVar4 + 1;
      uVar4 = uVar5;
    } while ("RpcOut: Unable to send the RPCI command"[lVar1] != '\0');
  }
  else {
    uVar4 = Message_Receive(param_1,(longlong *)&local_48,&local_40);
    if ((char)uVar4 == '\0') {
      *param_5 = (longlong)"RpcOut: Unable to receive the result of the RPCI command";
      uVar4 = 0xffffffffffffffff;
      do {
        uVar5 = uVar4 + 1;
        lVar1 = uVar4 + 1;
        uVar4 = uVar5;
      } while ("RpcOut: Unable to receive the result of the RPCI command"[lVar1] != '\0');
    }
    else {
      if (1 < local_40) {
        iVar2 = strncmp(local_48,"1 ",2);
        if ((iVar2 == 0) || (iVar3 = strncmp(local_48,"0 ",2), iVar3 == 0)) {
          *(bool *)param_4 = iVar2 == 0;
          *param_5 = (longlong)(local_48 + 2);
          *param_6 = local_40 - 2;
          return CONCAT71((int7)(local_40 - 2 >> 8),1);
        }
      }
      *param_5 = (longlong)"RpcOut: Invalid format for the result of the RPCI command";
      uVar4 = 0xffffffffffffffff;
      do {
        uVar5 = uVar4 + 1;
        lVar1 = uVar4 + 1;
        uVar4 = uVar5;
      } while ("RpcOut: Invalid format for the result of the RPCI command"[lVar1] != '\0');
    }
  }
  *param_6 = uVar5;
  return uVar5 & 0xffffffffffffff00;
}



===== RpcOut_sendOne @ 140003f9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RpcOut_sendOne(longlong *param_1,size_t *param_2,char *param_3,undefined8 param_4)

{
  uint *_Str;
  char *pcVar1;
  uint *_Memory;
  ulonglong extraout_RAX;
  ulonglong uVar2;
  undefined8 extraout_RAX_00;
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38 = 0;
  local_res20 = param_4;
  _Str = (uint *)Str_Vasprintf(&local_38,param_3,(va_list)&local_res20);
  uVar2 = 0;
  if (_Str == (uint *)0x0) {
LAB_14000401a:
    if (param_1 != (longlong *)0x0) {
      *param_1 = 0;
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    pcVar1 = strchr((char *)_Str,0x20);
    _Memory = _Str;
    if (pcVar1 == (char *)0x0) {
      _Memory = (uint *)Str_Asprintf((longlong *)0x0,"%s ",_Str,param_4);
      free(_Str);
      uVar2 = extraout_RAX;
      if (_Memory == (uint *)0x0) goto LAB_14000401a;
    }
    uVar2 = RpcOutSendOneRawWork(_Memory,local_38,(void *)0x0,0,param_1,param_2);
    free(_Memory);
    uVar2 = CONCAT71((int7)((ulonglong)extraout_RAX_00 >> 8),(char)uVar2);
  }
  return uVar2;
}



===== RpcOut_startWithReceiveBuffer @ 140004068 =====

ulonglong RpcOut_startWithReceiveBuffer(undefined2 *param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = Message_OpenAllocated(0x49435052,param_1,param_2,param_3);
  *(char *)(param_1 + 0x14) = (char)uVar1;
  if ((char)uVar1 == '\0') {
    uVar2 = Debug();
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),*(undefined1 *)(param_1 + 0x14));
  }
  return uVar1;
}



===== RpcOut_stop @ 1400040a0 =====

bool RpcOut_stop(undefined2 *param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*(char *)(param_1 + 0x14) != '\0') {
    bVar1 = Message_CloseAllocated(param_1);
    bVar2 = bVar1 != 0;
    if (!bVar2) {
      Debug();
    }
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  return bVar2;
}



===== Debug @ 1400040e0 =====

void Debug(void)

{
  return;
}



===== Panic @ 1400040f0 =====

void Panic(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  char local_3f8 [1016];
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  Str_Vsnprintf(local_3f8,1000,param_1,(va_list)&local_res10);
  uVar1 = IoGetCurrentProcess();
  DbgPrintEx(0x4d,0xffffffff,"\n\n\n\nPANIC! %s pid=%p\n\n\n\n",local_3f8,uVar1);
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x1a,param_1,local_3f8,0,0);
}



===== Str_Asprintf @ 140004168 =====

void Str_Asprintf(longlong *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  Str_Vasprintf(param_1,param_2,(va_list)&local_res18);
  return;
}



===== Str_Sprintf @ 14000418c =====

void Str_Sprintf(char *param_1,size_t param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 unaff_retaddr;
  undefined8 local_res20;
  
  local_res20 = param_4;
  iVar1 = _vsnprintf_s(param_1,param_2,0xffffffffffffffff,param_3,(va_list)&local_res20);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    Panic("%s:%d Buffer too small 0x%p\n",
          "d:\\build\\ob\\bora-18052479\\bora-vmsoft\\build\\release-x64\\pvscsi\\windows\\kernelstubs\\kernelstubswin32.c"
          ,0x244,unaff_retaddr);
  }
  return;
}



===== Str_Strcpy @ 1400041d8 =====

void * Str_Strcpy(void *param_1,void *param_2,ulonglong param_3)

{
  ulonglong uVar2;
  ulonglong uVar1;
  undefined8 unaff_retaddr;
  
  uVar1 = 0xffffffffffffffff;
  do {
    uVar2 = uVar1;
    uVar1 = uVar2 + 1;
  } while (*(char *)((longlong)param_2 + uVar1) != '\0');
  if (param_3 <= uVar1) {
                    /* WARNING: Subroutine does not return */
    Panic("%s:%d Buffer too small 0x%p\n",
          "d:\\build\\ob\\bora-18052479\\bora-vmsoft\\build\\release-x64\\pvscsi\\windows\\kernelstubs\\kernelstubswin32.c"
          ,0x1f6,unaff_retaddr);
  }
  memmove(param_1,param_2,uVar2 + 2);
  return param_1;
}



===== Str_Vasprintf @ 140004228 =====

char * Str_Vasprintf(longlong *param_1,char *param_2,va_list param_3)

{
  int iVar1;
  char *_DstBuf;
  size_t _NewSize;
  char *_Memory;
  
  _NewSize = 0xffffffffffffffff;
  do {
    _NewSize = _NewSize + 1;
  } while (param_2[_NewSize] != '\0');
  _Memory = (char *)0x0;
  do {
    _NewSize = _NewSize * 2;
    _DstBuf = realloc(_Memory,_NewSize);
    if (_DstBuf == (char *)0x0) {
      if (_Memory != (char *)0x0) {
        ExFreePoolWithTag(_Memory + -8,0x50565343);
      }
      return (char *)0x0;
    }
    iVar1 = _vsnprintf_s(_DstBuf,_NewSize,0xffffffffffffffff,param_2,param_3);
    _Memory = _DstBuf;
  } while (iVar1 == -1);
  if (param_1 != (longlong *)0x0) {
    *param_1 = (longlong)iVar1;
  }
  return _DstBuf;
}



===== Str_Vsnprintf @ 1400042cc =====

void Str_Vsnprintf(char *param_1,size_t param_2,char *param_3,va_list param_4)

{
  _vsnprintf_s(param_1,param_2,0xffffffffffffffff,param_3,param_4);
  return;
}



===== free @ 1400042e8 =====

void __cdecl free(void *_Memory)

{
  if (_Memory != (void *)0x0) {
    ExFreePoolWithTag((longlong)_Memory + -8,0x50565343);
  }
  return;
}



===== malloc @ 140004308 =====

void * __cdecl malloc(size_t _Size)

{
  size_t *psVar1;
  
  psVar1 = (size_t *)ExAllocatePoolWithTag(0x200,_Size + 8,0x50565343);
  if (psVar1 != (size_t *)0x0) {
    *psVar1 = _Size;
    psVar1 = psVar1 + 1;
  }
  return psVar1;
}



===== realloc @ 140004338 =====

void * __cdecl realloc(void *_Memory,size_t _NewSize)

{
  void *_Dst;
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = (longlong)_Memory + -8;
  if (_Memory == (void *)0x0) {
    uVar1 = 0;
    lVar2 = -8;
  }
  else {
    uVar1 = *(ulonglong *)((longlong)_Memory + -8);
  }
  if (_NewSize == 0) {
    if (_Memory == (void *)0x0) {
      _Dst = malloc(0);
    }
    else {
      ExFreePoolWithTag(lVar2,0x50565343);
      _Dst = (void *)0x0;
    }
  }
  else if (_NewSize == uVar1) {
    _Dst = _Memory;
  }
  else {
    _Dst = malloc(_NewSize);
    if (_Dst != (void *)0x0) {
      if (uVar1 < _NewSize) {
        _NewSize = uVar1;
      }
      memmove(_Dst,_Memory,_NewSize);
      if (_Memory != (void *)0x0) {
        ExFreePoolWithTag(lVar2,0x50565343);
      }
    }
  }
  return _Dst;
}



===== strchr @ 1400043fe =====

char * __cdecl strchr(char *_Str,int _Val)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400043fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strchr(_Str,_Val);
  return pcVar1;
}



===== strncmp @ 140004404 =====

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140004404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== _vsnprintf_s @ 14000440a =====

int __cdecl
_vsnprintf_s(char *_DstBuf,size_t _SizeInBytes,size_t _MaxCount,char *_Format,va_list _ArgList)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000440a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnprintf_s(_DstBuf,_SizeInBytes,_MaxCount,_Format,_ArgList);
  return iVar1;
}



===== Message_CloseAllocated @ 140004410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte Message_CloseAllocated(undefined2 *param_1)

{
  byte bVar1;
  undefined1 auStack_68 [32];
  ulonglong local_48 [2];
  undefined4 local_38;
  undefined2 local_2e;
  undefined4 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_2e = *param_1;
  local_28 = *(undefined4 *)(param_1 + 0xe);
  local_20 = *(undefined4 *)(param_1 + 0x10);
  local_38 = 0x6001e;
  Backdoor(local_48);
  bVar1 = local_38._2_1_ & 1;
  if (*(char *)(param_1 + 0xc) == '\0') {
    free(*(void **)(param_1 + 4));
  }
  *(undefined8 *)(param_1 + 4) = 0;
  return bVar1;
}



===== Message_OpenAllocated @ 14000448c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
Message_OpenAllocated(ulonglong param_1,undefined2 *param_2,longlong param_3,undefined8 param_4)

{
  bool bVar1;
  undefined8 uVar2;
  uint7 uVar3;
  undefined1 auStack_98 [32];
  ulonglong local_78;
  ulonglong local_70;
  uint local_68;
  undefined2 local_5e;
  undefined4 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  bVar1 = true;
  local_70 = param_1 & 0xffffffff | 0x80000000;
  while( true ) {
    local_68 = 0x1e;
    uVar2 = Backdoor(&local_78);
    uVar3 = (uint7)((ulonglong)uVar2 >> 8);
    if ((local_68 & 0x10000) != 0) {
      *param_2 = local_5e;
      *(undefined4 *)(param_2 + 0xe) = local_58;
      *(undefined4 *)(param_2 + 0x10) = local_50;
      *(bool *)(param_2 + 0xc) = param_3 != 0;
      *(longlong *)(param_2 + 4) = param_3;
      *(undefined8 *)(param_2 + 8) = param_4;
      return CONCAT71(uVar3,1);
    }
    if (!bVar1) break;
    bVar1 = false;
    local_70 = param_1 & 0xffffffff;
  }
  return (ulonglong)uVar3 << 8;
}



===== Message_Receive @ 140004540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Message_Receive(short *param_1,longlong *param_2,ulonglong *param_3)

{
  ulonglong _NewSize;
  undefined1 uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  undefined1 auStack_c8 [32];
  ulonglong local_a8;
  ulonglong local_a0;
  undefined4 local_98;
  short local_8e;
  undefined4 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined4 local_70;
  ulonglong local_68;
  short local_5e;
  ulonglong local_58;
  undefined4 *local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_8e = *param_1;
  local_88 = *(undefined4 *)(param_1 + 0xe);
  local_80 = *(undefined4 *)(param_1 + 0x10);
  local_98 = 0x3001e;
  uVar3 = Backdoor(&local_a8);
  uVar5 = CONCAT71((int7)((ulonglong)uVar3 >> 8),local_98._2_1_);
  do {
    if ((local_98 & 0x10000) == 0) {
LAB_140004691:
      return uVar5 & 0xffffffffffffff00;
    }
    if ((uVar5 & 2) == 0) {
      *param_3 = 0;
      goto LAB_140004804;
    }
    if (local_8e != 1) goto LAB_140004691;
    uVar7 = local_a0 & 0xffffffff;
    _NewSize = uVar7 + 1;
    if (*(ulonglong *)(param_1 + 8) < _NewSize) {
      if (((char)param_1[0xc] == '\0') &&
         (pvVar4 = realloc(*(void **)(param_1 + 4),_NewSize), pvVar4 != (void *)0x0)) {
        *(void **)(param_1 + 4) = pvVar4;
        uVar5 = (ulonglong)local_98._2_1_;
        *(ulonglong *)(param_1 + 8) = _NewSize;
        goto LAB_1400045f6;
      }
LAB_14000465b:
      local_98._2_2_ = 5;
      if (uVar7 != 0) {
        local_98._2_2_ = 4;
      }
      local_8e = *param_1;
      local_88 = *(undefined4 *)(param_1 + 0xe);
      local_80 = *(undefined4 *)(param_1 + 0x10);
      local_98 = CONCAT22(local_98._2_2_,0x1e);
      local_a0 = 0;
      uVar5 = Backdoor(&local_a8);
      goto LAB_140004691;
    }
LAB_1400045f6:
    *param_3 = uVar7;
    puVar8 = *(undefined4 **)(param_1 + 4);
    *param_2 = (longlong)puVar8;
    if ((char)uVar5 < '\0') {
      if (uVar7 == 0) goto LAB_140004773;
      local_5e = *param_1;
      local_58 = (ulonglong)*(uint *)(param_1 + 0xe);
      local_48 = *(undefined4 *)(param_1 + 0x10);
      local_70 = 0x10000;
      local_68 = uVar7;
      local_50 = puVar8;
      Backdoor_HbIn(&local_78);
      local_98._2_1_ = local_70._2_1_;
      if ((local_70 & 0x10000) != 0) goto LAB_140004773;
LAB_140004649:
      if ((local_98._2_1_ & 0x10) == 0) goto LAB_14000465b;
    }
    else {
      for (; uVar7 != 0; uVar7 = uVar7 + lVar6) {
        local_8e = *param_1;
        local_88 = *(undefined4 *)(param_1 + 0xe);
        local_80 = *(undefined4 *)(param_1 + 0x10);
        local_98 = 0x4001e;
        local_a0 = 1;
        Backdoor(&local_a8);
        if ((local_98 & 0x10000) == 0) goto LAB_140004649;
        if (local_8e != 2) goto LAB_14000465b;
        uVar1 = (undefined1)local_a0;
        if (uVar7 == 1) {
          *(undefined1 *)puVar8 = (undefined1)local_a0;
          lVar6 = -1;
        }
        else {
          uVar2 = (undefined1)(local_a0 >> 8);
          if (uVar7 == 2) {
            *(undefined1 *)puVar8 = uVar1;
            *(undefined1 *)((longlong)puVar8 + 1) = uVar2;
            lVar6 = -2;
          }
          else if (uVar7 == 3) {
            *(undefined1 *)puVar8 = uVar1;
            *(undefined1 *)((longlong)puVar8 + 1) = uVar2;
            *(char *)((longlong)puVar8 + 2) = (char)(local_a0 >> 0x10);
            lVar6 = -3;
          }
          else {
            *puVar8 = (undefined4)local_a0;
            lVar6 = -4;
          }
        }
        puVar8 = puVar8 + 1;
      }
LAB_140004773:
      *(undefined1 *)(*(longlong *)(param_1 + 4) + *param_3) = 0;
      local_8e = *param_1;
      local_88 = *(undefined4 *)(param_1 + 0xe);
      local_80 = *(undefined4 *)(param_1 + 0x10);
      local_98 = 0x5001e;
      local_a0 = 1;
      uVar5 = Backdoor(&local_a8);
      uVar5 = uVar5 & 0xffffffffffffff00;
      if ((local_98 & 0x10000) != 0) {
LAB_140004804:
        return CONCAT71((int7)(uVar5 >> 8),1);
      }
      if ((local_98 & 0x100000) == 0) goto LAB_14000465b;
    }
    local_8e = *param_1;
    local_88 = *(undefined4 *)(param_1 + 0xe);
    local_80 = *(undefined4 *)(param_1 + 0x10);
    local_98 = 0x3001e;
    uVar3 = Backdoor(&local_a8);
    uVar5 = CONCAT71((int7)((ulonglong)uVar3 >> 8),local_98._2_1_);
  } while( true );
}



===== Message_Send @ 14000480c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Message_Send(undefined2 *param_1,uint *param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  uint *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_c8 [32];
  ulonglong local_a8;
  ulonglong local_a0;
  undefined4 local_98;
  undefined2 local_8e;
  undefined4 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined4 local_70;
  longlong local_68;
  undefined2 local_5e;
  uint *local_58;
  ulonglong local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_8e = *param_1;
  local_88 = *(undefined4 *)(param_1 + 0xe);
  local_80 = *(undefined4 *)(param_1 + 0x10);
  while( true ) {
    local_98 = 0x1001e;
    local_a0 = param_3;
    uVar2 = Backdoor(&local_a8);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),local_98._2_1_);
    if ((local_98 & 0x10000) == 0) break;
    if (local_98._2_1_ < '\0') {
      if (param_3 == 0) {
LAB_1400049c3:
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
      local_5e = *param_1;
      local_48 = *(undefined4 *)(param_1 + 0xe);
      local_50 = (ulonglong)*(uint *)(param_1 + 0x10);
      local_70 = 0x10000;
      local_68 = param_3;
      local_58 = param_2;
      uVar2 = Backdoor_HbOut(&local_78);
      uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),local_70._2_1_);
      if ((local_70 & 0x10000) != 0) goto LAB_1400049c3;
    }
    else {
      puVar3 = param_2;
      lVar5 = param_3;
      while( true ) {
        if (lVar5 == 0) goto LAB_1400049c3;
        local_8e = *param_1;
        local_88 = *(undefined4 *)(param_1 + 0xe);
        local_80 = *(undefined4 *)(param_1 + 0x10);
        if (lVar5 == 1) {
          local_a0 = (ulonglong)(byte)*puVar3;
          lVar4 = -1;
        }
        else if (lVar5 == 2) {
          lVar4 = -2;
          local_a0 = (ulonglong)(ushort)*puVar3;
        }
        else if (lVar5 == 3) {
          lVar4 = -3;
          local_a0 = (ulonglong)(uint3)*puVar3;
        }
        else {
          local_a0 = (ulonglong)*puVar3;
          lVar4 = -4;
        }
        local_98 = 0x2001e;
        uVar2 = Backdoor(&local_a8);
        uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),local_98._2_1_);
        if ((local_98 & 0x10000) == 0) break;
        puVar3 = puVar3 + 1;
        lVar5 = lVar5 + lVar4;
      }
    }
    if ((uVar1 & 0x10) == 0) break;
    local_8e = *param_1;
    local_88 = *(undefined4 *)(param_1 + 0xe);
    local_80 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== Backdoor @ 1400049cc =====

void Backdoor(ulonglong *param_1)

{
  *(undefined4 *)param_1 = 0x564d5868;
  *(undefined2 *)(param_1 + 3) = 0x5658;
  Backdoor_InOut(param_1);
  return;
}



===== Backdoor_HbIn @ 1400049e0 =====

void Backdoor_HbIn(undefined8 *param_1)

{
  *(undefined4 *)param_1 = 0x564d5868;
  *(undefined2 *)(param_1 + 3) = 0x5659;
  BackdoorHbIn(param_1);
  return;
}



===== Backdoor_HbOut @ 1400049f4 =====

void Backdoor_HbOut(undefined8 *param_1)

{
  *(undefined4 *)param_1 = 0x564d5868;
  *(undefined2 *)(param_1 + 3) = 0x5659;
  BackdoorHbOut(param_1);
  return;
}



===== Backdoor_InOut @ 140004a10 =====

void Backdoor_InOut(ulonglong *param_1)

{
  uint uVar1;
  
  uVar1 = in((short)param_1[3]);
  LOCK();
  UNLOCK();
  param_1[5] = param_1[5];
  param_1[4] = param_1[4];
  param_1[3] = param_1[3];
  param_1[2] = param_1[2];
  param_1[1] = param_1[1];
  *param_1 = (ulonglong)uVar1;
  return;
}



===== BackdoorHbIn @ 140004a4e =====

void BackdoorHbIn(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  
  uVar2 = param_1[6];
  uVar3 = param_1[4];
  uVar4 = param_1[3];
  lVar7 = param_1[2];
  uVar5 = param_1[1];
  uVar6 = *param_1;
  puVar8 = (undefined1 *)param_1[5];
  while (lVar7 != 0) {
    lVar7 = lVar7 + -1;
    uVar1 = in((short)uVar4);
    *puVar8 = uVar1;
    puVar8 = puVar8 + 1;
  }
  LOCK();
  UNLOCK();
  param_1[6] = uVar2;
  param_1[5] = puVar8;
  param_1[4] = uVar3;
  param_1[3] = uVar4;
  param_1[2] = 0;
  param_1[1] = uVar5;
  *param_1 = uVar6;
  return;
}



===== BackdoorHbOut @ 140004a98 =====

void BackdoorHbOut(undefined8 *param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  
  lVar1 = param_1[2];
  puVar2 = (undefined1 *)param_1[4];
  while (lVar1 != 0) {
    lVar1 = lVar1 + -1;
    out(*puVar2,(short)param_1[3]);
    puVar2 = puVar2 + 1;
  }
  LOCK();
  UNLOCK();
  param_1[6] = param_1[6];
  param_1[5] = param_1[5];
  param_1[4] = puVar2;
  param_1[3] = param_1[3];
  param_1[2] = 0;
  param_1[1] = param_1[1];
  *param_1 = *param_1;
  return;
}



===== _guard_check_icall @ 140004af0 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 140004b10 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140004b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 140004b40 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_140004cf7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_140004cf7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_140004b52;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_140004b52:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 140004e80 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (_Size < 0x4f) {
    uVar4 = _Size & 0xfffffffffffffff8;
    do {
      *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
      uVar4 = uVar4 - 8;
    } while (uVar4 != 0);
    if ((_Size & 7) != 0) {
      *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
    }
    return _Dst;
  }
  *(longlong *)_Dst = lVar3;
  *(longlong *)((longlong)_Dst + 8) = lVar3;
  plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
  uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
  uVar5 = uVar4 >> 7;
  plVar2 = plVar1;
  if (uVar5 != 0) {
    do {
      *plVar2 = lVar3;
      plVar2[1] = lVar3;
      plVar2[2] = lVar3;
      plVar2[3] = lVar3;
      plVar1 = plVar2 + 0x10;
      plVar2[4] = lVar3;
      plVar2[5] = lVar3;
      plVar2[6] = lVar3;
      plVar2[7] = lVar3;
      uVar5 = uVar5 - 1;
      plVar2[8] = lVar3;
      plVar2[9] = lVar3;
      plVar2[10] = lVar3;
      plVar2[0xb] = lVar3;
      plVar2[0xc] = lVar3;
      plVar2[0xd] = lVar3;
      plVar2[0xe] = lVar3;
      plVar2[0xf] = lVar3;
      plVar2 = plVar1;
    } while (uVar5 != 0);
    uVar4 = uVar4 & 0x7f;
  }
  for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
    plVar1 = plVar1 + 2;
  }
  if ((uVar4 & 0xf) != 0) {
    plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
  }
  return _Dst;
}



===== entry @ 14000a000 =====

void entry(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 14000a02c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140008020) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


