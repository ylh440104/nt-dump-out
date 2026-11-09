
===== NullTraceFunc @ 1c0001000 =====

undefined8 NullTraceFunc(void)

{
  return 0;
}



===== StorWmiTraceMessage @ 1c0001010 =====

undefined4
StorWmiTraceMessage(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined2 param_4,
                   undefined1 param_5)

{
  undefined8 local_58;
  undefined4 local_50 [2];
  undefined8 local_48;
  undefined2 local_40;
  undefined1 *local_38;
  undefined4 local_30;
  
  memset(local_50,0,0x28);
  local_38 = &param_5;
  local_58 = param_1;
  local_50[0] = param_2;
  local_48 = param_3;
  local_40 = param_4;
  StorPortNotification(0xe,0,2000,&local_58);
  return local_30;
}



===== WppTraceCallback @ 1c0001080 =====

int WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                    uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 local_res8 [8];
  undefined8 local_58;
  undefined8 *local_50;
  longlong local_48;
  longlong *local_40;
  uint *local_38;
  int local_30;
  
  puVar5 = param_6;
  lVar4 = param_5;
  iVar6 = 0;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 == 0) {
        return -0x3ffffd6b;
      }
      if (param_3 < 0x30) {
        return -0x3ffffff3;
      }
      if (param_1 == 5) {
        *(undefined1 *)(param_5 + 0x19) = 0;
        *(undefined4 *)(param_5 + 0x1c) = 0;
        *(undefined8 *)(param_5 + 0x10) = 0;
        return 0;
      }
      *(undefined8 *)(param_5 + 0x10) = *(undefined8 *)(param_4 + 2);
      memset(&local_50,0,0x28);
      local_58._0_4_ = 3;
      local_50 = (undefined8 *)local_res8;
      local_48._0_4_ = 4;
      local_40 = &param_5;
      local_38 = param_4;
      StorPortNotification(0xe,0,0x7d3,&local_58);
      if (local_30 == 0) {
        *(undefined1 *)(lVar4 + 0x19) = local_res8[0];
      }
      memset(&local_50,0,0x28);
      local_58 = CONCAT44(local_58._4_4_,2);
      local_50 = (undefined8 *)(lVar4 + 0x1c);
      local_48 = CONCAT44(local_48._4_4_,4);
      local_40 = &param_5;
      local_38 = param_4;
      StorPortNotification(0xe,0,0x7d3,&local_58);
      return local_30;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      puVar1 = *(ushort **)(param_5 + 0x28);
      if (puVar1 == (ushort *)0x0) {
        uVar8 = 0;
        uVar7 = 0x38;
      }
      else {
        uVar8 = 0x38;
        uVar7 = *puVar1 + 0x3a;
      }
      if (param_3 < uVar7) {
        iVar6 = -0x3fffffdd;
        if (3 < param_3) {
          *param_4 = uVar7;
          *param_6 = 4;
        }
      }
      else {
        memset(param_4,0,(ulonglong)param_3);
        *param_4 = uVar7;
        param_4[2] = uVar8;
        param_4[4] = 1;
        uVar2 = **(undefined8 **)(lVar4 + 0x10);
        uVar3 = (*(undefined8 **)(lVar4 + 0x10))[1];
        param_4[10] = 0x81000;
        *(undefined8 *)(param_4 + 6) = uVar2;
        *(undefined8 *)(param_4 + 8) = uVar3;
        if (puVar1 != (ushort *)0x0) {
          *(ushort *)((ulonglong)uVar8 + (longlong)param_4) = *puVar1;
          memcpy((ushort *)((ulonglong)uVar8 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
                 (ulonglong)*puVar1);
        }
        *puVar5 = uVar7;
      }
      local_50 = (undefined8 *)(lVar4 + 0x10);
      local_58 = *local_50;
      local_48 = lVar4 + 0x1c;
      local_40 = (longlong *)(lVar4 + 0x19);
      StorPortNotification(0xe,0,0x7d1,&local_58);
      return iVar6;
    }
  }
  return -0x3ffffff0;
}



===== trace_cleanup @ 1c00012b0 =====

void trace_cleanup(void)

{
  undefined8 *puVar1;
  undefined8 local_res10 [3];
  undefined8 *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_res10[0] = tw_trace_context;
  puVar1 = &WPP_GLOBAL_Control;
  StorPortNotification(0xe,0,0x3e9,local_res10);
  do {
    local_c = 0;
    local_10 = 0x80000002;
    local_18 = puVar1;
    StorPortNotification(0xe,0,0x7d2,&local_18);
    puVar1 = (undefined8 *)puVar1[1];
  } while (puVar1 != (undefined8 *)0x0);
  return;
}



===== DriverEntry @ 1c0001318 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_148 [32];
  undefined8 *local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_114;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c0;
  undefined2 local_bc;
  byte local_b0;
  code *local_a0;
  code *local_98;
  undefined4 local_60;
  undefined4 local_48 [3];
  undefined4 local_3c;
  code *local_28;
  longlong local_20;
  longlong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_148;
  if (param_1 == 0) {
    tw_queue_length = 0x26;
    tw_crash_dump = 1;
    tw_sgls_count = 0x11;
    tw_msg_control = 0x1f;
  }
  memset(&local_118,0,0xd0);
  local_118 = 0xd0;
  local_f8 = FindAdapter;
  local_114 = 5;
  local_110 = Initialize;
  local_d8 = 0x16c0;
  local_f0 = ResetBus;
  local_d0 = 0x503;
  local_98 = BuildIO;
  local_cc = 2;
  local_108 = StartIO;
  local_100 = Interrupt;
  local_a0 = AdapterControl;
  local_c0 = 0x1010100;
  local_bc = 1;
  local_60 = 0x20;
  iVar1 = StorPortInitialize(param_1,param_2,&local_118,0);
  if ((iVar1 == 0) && ((local_b0 & 0x10) != 0)) {
    memset(local_48,0,0x38);
    local_48[0] = 0x38;
    local_28 = trace_cleanup;
    local_3c = 100;
    local_120 = 0xc00000bb;
    puVar2 = &WPP_GLOBAL_Control;
    local_128 = (undefined8 *)local_48;
    local_20 = param_1;
    StorPortNotification(0xe,0,1000,&local_128);
    if ((int)local_120 == 0) {
      pfnWppTraceMessage = StorWmiTraceMessage;
      do {
        puVar2[5] = 0;
        *puVar2 = WppTraceCallback;
        *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(puVar2 + 6);
        *(undefined1 *)((longlong)puVar2 + 0x19) = 0;
        *(undefined4 *)((longlong)puVar2 + 0x1c) = 0;
        local_120 = 0x80000001;
        local_128 = puVar2;
        StorPortNotification(0xe,0,0x7d2,&local_128);
        puVar2 = (undefined8 *)puVar2[1];
      } while (puVar2 != (undefined8 *)0x0);
    }
    if (local_18 != 0) {
      tw_trace_context = local_18;
    }
  }
  return iVar1;
}



===== FindAdapter @ 1c0001530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FindAdapter(byte *param_1,undefined8 param_2,undefined8 param_3,char *param_4,longlong param_5,
           undefined1 *param_6)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte bVar8;
  char *pcVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined8 uVar12;
  bool bVar13;
  undefined1 local_228 [32];
  ushort *local_208;
  undefined1 *local_200;
  undefined *local_1f8;
  ushort local_1e8;
  ushort local_1e6;
  ushort local_1ba;
  undefined1 local_1a8;
  char local_e8 [64];
  char local_a8 [112];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_228;
  uVar10 = 0;
  *param_6 = 0;
  param_1[0x23a] = 1;
  pcVar11 = param_4;
  lVar5 = tw_time_msecs();
  *(int *)(param_1 + 0x2b9) = (int)lVar5;
  bVar8 = 0;
  *(uint *)(param_1 + 0x292) = tw_dbg_control;
  *(undefined4 *)(param_1 + 0x296) = tw_msg_control;
  do {
    if ((&tw_driver_slot)[bVar8] == '\0') {
      *param_1 = bVar8;
      (&tw_driver_slot)[bVar8] = 1;
      break;
    }
    bVar8 = bVar8 + 1;
  } while (bVar8 < 0x10);
  if (param_4 != (char *)0x0) {
    pcVar9 = "dump=1;";
    do {
      if ((*param_4 == '\0') || (cVar1 = *pcVar9, cVar1 == '\0')) {
        if ((*param_4 == '\0') && (*pcVar9 == '\0')) {
          tw_msg_dev(param_1,8,"FindAdapter> Memory Dump Driver",pcVar11);
          tw_crash_dump = '\x01';
        }
        break;
      }
      cVar2 = *param_4;
      pcVar9 = pcVar9 + 1;
      param_4 = param_4 + 1;
    } while (cVar2 == cVar1);
  }
  if (*param_1 == 0) {
    tw_init_options(param_1);
    tw_dma64bit = *(char *)(param_5 + 0x90) == -0x80;
  }
  *(uint *)(param_1 + 0x292) = tw_dbg_control;
  *(undefined4 *)(param_1 + 0x296) = tw_msg_control;
  local_208 = &local_1e8;
  uVar6 = (ulonglong)*(uint *)(param_5 + 100);
  local_200._0_4_ = 0x100;
  local_1a8 = 0;
  iVar4 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4));
  if (iVar4 != 0x100) {
    tw_msg_dev(param_1,1,"Failed StorPortGetBusData() call",uVar6);
    local_1f8 = (undefined *)CONCAT44(local_1f8._4_4_,0x10000001);
    local_200 = (undefined1 *)CONCAT44(local_200._4_4_,6);
    local_208 = (ushort *)((ulonglong)local_208 & 0xffffffffffffff00);
    StorPortLogError(param_1,0,0,0);
    return 2;
  }
  *(uint *)(param_1 + 2) = (uint)local_1e8;
  *(uint *)(param_1 + 6) = (uint)local_1e6;
  *(uint *)(param_1 + 10) = (uint)local_1ba;
  param_1[0x148] = 0xfe;
  param_1[0x149] = 0x20;
  param_1[0x14a] = 0x10;
  if (local_1e6 != 0x1010) {
    local_208 = (ushort *)CONCAT44(local_208._4_4_,(uint)local_1e6);
    tw_msg_dev(param_1,1,"Not LSI 3ware 9750 adapter: VenID=%04X DevID=%04X",(ulonglong)local_1e8);
    local_1f8._0_4_ = 0x10000002;
    uVar12 = 0;
    local_200._0_4_ = 6;
    local_208 = (ushort *)((ulonglong)local_208 & 0xffffffffffffff00);
    StorPortLogError(param_1,0,0);
    goto LAB_1c0001d21;
  }
  pcVar11 = "";
  if (tw_crash_dump != '\0') {
    pcVar11 = " MemDump";
  }
  tw_string(&tw_win_version,0x32,"Windows x64%s",pcVar11);
  if (tw_crash_dump == '\0') {
    pcVar9 = tw_time_date(local_e8);
    tw_msg_dev((byte *)0x0,8,pcVar9,pcVar11);
  }
  local_200 = &tw_win_version;
  local_208 = (ushort *)0x1c00106e0;
  tw_msg_dev((byte *)0x0,8,"%s%s - %s",&s_3ware);
  local_1f8 = &s_11_Apr_13;
  local_200 = (undefined1 *)CONCAT44(local_200._4_4_,0x28);
  local_208 = (ushort *)CONCAT44(local_208._4_4_,0x28);
  tw_msg_dev((byte *)0x0,8,"%s (%u-%u) %s",&s_5_01_00_051);
  tw_msg_dev((byte *)0x0,8,"Sizeof(OrgCmd)    = %u bytes",0x18);
  tw_msg_dev((byte *)0x0,8,"Sizeof(NewCmd)    = %u bytes",0x18);
  tw_msg_dev((byte *)0x0,8,"Sizeof(CmonCmd)   = %u bytes",0x1c);
  tw_msg_dev((byte *)0x0,8,"Sizeof(CmonLcmd)  = %u bytes",0x2c);
  tw_msg_dev((byte *)0x0,8,"Sizeof(SenseBuff) = %u bytes",0x80);
  tw_msg_dev((byte *)0x0,8,"Sizeof(ReqInfo)   = %u bytes",0x1a8);
  tw_msg_dev((byte *)0x0,8,"Sizeof(CmonInfo)  = %u bytes",0x5d8);
  tw_msg_dev((byte *)0x0,8,"Sizeof(SRB Ext)   = %u bytes",0x503);
  uVar12 = 0x16c0;
  tw_msg_dev((byte *)0x0,8,"Sizeof(DeviceX)   = %u bytes",0x16c0);
  if (tw_trace_context != 0) {
    if (tw_crash_dump == '\0') {
      pcVar11 = tw_time_date(local_e8);
      tw_msg_dev((byte *)0x0,8,pcVar11,uVar12);
    }
    local_200 = &tw_win_version;
    local_208 = (ushort *)0x1c00106e0;
    tw_msg_dev((byte *)0x0,8,"%s%s - %s",&s_3ware);
    local_1f8 = &s_11_Apr_13;
    local_200 = (undefined1 *)CONCAT44(local_200._4_4_,0x28);
    local_208 = (ushort *)CONCAT44(local_208._4_4_,0x28);
    tw_msg_dev((byte *)0x0,8,"%s (%u-%u) %s",&s_5_01_00_051);
  }
  local_1f8 = (undefined *)CONCAT44(local_1f8._4_4_,*(uint *)(param_1 + 2));
  local_200._0_4_ = *(undefined4 *)(param_1 + 10);
  local_208._0_4_ = *(undefined4 *)(param_1 + 6);
  tw_string((char *)(param_1 + 0xe),0x32,"PCI\\VEN_%04X&DEV_%04X&SUBSYS_%04X%04X",
            (ulonglong)*(uint *)(param_1 + 2));
  local_200 = (undefined1 *)CONCAT44(local_200._4_4_,*(undefined4 *)(param_1 + 10));
  local_208._0_4_ = *(undefined4 *)(param_1 + 6);
  tw_msg_dev(param_1,8,"VenID=%04X DevID=%04X SubSysId=%04X",(ulonglong)*(uint *)(param_1 + 2));
  if (*(int *)(param_1 + 10) == 1) {
    tw_queue_length = 0x100;
  }
  bVar13 = tw_dma64bit != '\0';
  *(undefined2 *)(param_1 + 0x14b) = tw_queue_length;
  tw_msg_dev(param_1,8,"DMA address: %u bit",(ulonglong)((-(uint)bVar13 & 0x20) + 0x20));
  tw_msg_dev(param_1,8,"Allocated packet size: %u bytes",(ulonglong)tw_sgls_count * 0x10 + 0x14b);
  tw_msg_dev(param_1,8,"Max fware packet size: %u bytes",0x300);
  if (tw_user_max_units != 0) {
    param_1[0x149] = tw_user_max_units;
  }
  if ((tw_user_max_luns != 0) && (tw_user_max_luns < param_1[0x148])) {
    param_1[0x148] = tw_user_max_luns;
  }
  local_208._0_4_ = 0x1fc0;
  tw_msg_dev(param_1,8,"Request count setable: %d-%d",0x26);
  local_208 = (ushort *)CONCAT44(local_208._4_4_,6);
  tw_msg_dev(param_1,8,"Request count current: %d-%d(RSV)",(ulonglong)*(ushort *)(param_1 + 0x14b));
  tw_msg_dev(param_1,8,"MaxUnits: %u",(ulonglong)param_1[0x149]);
  tw_msg_dev(param_1,8,"MaxLuns:  %u",(ulonglong)param_1[0x148]);
  tw_msg_dev(param_1,8,"MaxSGLs:  %u",(ulonglong)tw_sgls_count);
  uVar6 = (ulonglong)((tw_sgls_count - 1 & 0xfffff) << 2);
  tw_msg_dev(param_1,8,"MaxXfer:  %u KB",uVar6);
  cVar1 = tw_dma64bit;
  uVar3 = tw_sgls_count;
  *(uint *)(param_5 + 0x1c) = tw_sgls_count;
  bVar13 = tw_crash_dump == '\0';
  *(uint *)(param_5 + 0x18) = (uVar3 - 1) * 0x1000;
  *(undefined4 *)(param_5 + 0x14) = 0;
  *(undefined4 *)(param_5 + 0x28) = 2;
  *(undefined4 *)(param_5 + 0x30) = 0;
  *(undefined1 *)(param_5 + 0x48) = 1;
  *(undefined2 *)(param_5 + 0x51) = 0x101;
  *(undefined1 *)(param_5 + 0x53) = 1;
  *(undefined2 *)(param_5 + 0x58) = 0;
  *(undefined1 *)(param_5 + 0x5a) = 1;
  *(undefined1 *)(param_5 + 0x60) = 1;
  *(byte *)(param_5 + 0x61) = param_1[0x149];
  *(byte *)(param_5 + 0x92) = param_1[0x148];
  *(bool *)(param_5 + 0x93) = bVar13;
  *(undefined1 *)(param_5 + 0x91) = 0;
  *(bool *)(param_5 + 0x57) = cVar1 == '\0';
  *(bool *)(param_5 + 0x90) = cVar1 != '\0';
  if ((param_1[0x292] & 0x10) == 0) {
    *(undefined4 *)(param_5 + 0x94) = 1;
  }
  else {
    tw_msg_dev(param_1,8,"ConfigInfo> Duplex disabled",uVar6);
    *(undefined4 *)(param_5 + 0x94) = 0;
  }
  lVar5 = *(longlong *)(param_5 + 0x38);
  *(code **)(param_5 + 0x98) = Int_Msi;
  *(undefined4 *)(param_5 + 0xa0) = 1;
  local_208 = (ushort *)0x1c0011330;
  uVar12 = 1;
  if (*(char *)(lVar5 + 0x1c) != '\0') {
    local_208 = (ushort *)0x1c0011320;
  }
  local_1f8._0_4_ = *(undefined4 *)(lVar5 + 0x18);
  local_200._0_4_ = *(uint *)(lVar5 + 0x10);
  tw_string(local_a8,100,"BAR%d (%s): Adr=%X Len=%X",1);
  if (*(char *)(lVar5 + 0x1c) == '\0') {
    uVar12 = 1;
    tw_msg_dev(param_1,1,"AccessRange> BAR%d: MEM space expected",1);
    tw_msg_dev(param_1,1,local_a8,uVar12);
    local_1f8._0_4_ = 0x10000010;
    uVar12 = 0;
    local_200._0_4_ = 6;
    local_208 = (ushort *)((ulonglong)local_208 & 0xffffffffffffff00);
    StorPortLogError(param_1,0,0);
LAB_1c0001ccd:
    uVar6 = 0;
  }
  else {
    tw_msg_dev(param_1,8,local_a8,uVar12);
    uVar12 = *(undefined8 *)(lVar5 + 0x10);
    local_200._0_4_ = (uint)local_200 & 0xffffff00;
    local_208 = (ushort *)CONCAT44(local_208._4_4_,*(undefined4 *)(lVar5 + 0x18));
    uVar6 = StorPortGetDeviceBase(param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4))
    ;
    if (uVar6 == 0) {
      tw_msg_dev(param_1,1,"AccessRange> BAR%d: Base address is 0",1);
      local_1f8._0_4_ = 0x10000030;
      uVar12 = 0;
      local_200._0_4_ = 6;
      local_208 = (ushort *)((ulonglong)local_208 & 0xffffffffffffff00);
      StorPortLogError(param_1,0,0);
      goto LAB_1c0001ccd;
    }
  }
  *(ulonglong *)(param_1 + 0x40) = uVar6;
  if (uVar6 == 0) {
    uVar10 = 3;
  }
  else {
    uVar12 = 1;
    pcVar11 = "BAR%d: Mapped Adr(REG)=%X";
    local_208 = (ushort *)uVar6;
    tw_msg_dev(param_1,8,"BAR%d: Mapped Adr(REG)=%X",1);
    if ((tw_dbg_control & 0x200) != 0) {
      tw_cmon_cmdsize = 0x2c;
    }
    uVar7 = tw_init_memory(param_1,param_5,pcVar11,uVar12);
    if ((char)uVar7 != '\0') {
      if (tw_crash_dump == '\0') {
        tw_msg_dev(param_1,0x8000,"WMI> Initialize",uVar12);
        param_1[0x1670] = 1;
        param_1[0x1671] = 0;
        param_1[0x1672] = 0;
        param_1[0x1673] = 0;
        *(undefined ***)(param_1 + 0x1678) = &TW_WmiGuidList;
        *(code **)(param_1 + 0x1680) = FUN_1c0004610;
        *(code **)(param_1 + 0x1688) = FUN_1c0004640;
        *(code **)(param_1 + 0x16a8) = FUN_1c0004670;
        param_1[0x1698] = 0;
        param_1[0x1699] = 0;
        param_1[0x169a] = 0;
        param_1[0x169b] = 0;
        param_1[0x169c] = 0;
        param_1[0x169d] = 0;
        param_1[0x169e] = 0;
        param_1[0x169f] = 0;
        param_1[0x1690] = 0;
        param_1[0x1691] = 0;
        param_1[0x1692] = 0;
        param_1[0x1693] = 0;
        param_1[0x1694] = 0;
        param_1[0x1695] = 0;
        param_1[0x1696] = 0;
        param_1[0x1697] = 0;
        param_1[0x16a0] = 0;
        param_1[0x16a1] = 0;
        param_1[0x16a2] = 0;
        param_1[0x16a3] = 0;
        param_1[0x16a4] = 0;
        param_1[0x16a5] = 0;
        param_1[0x16a6] = 0;
        param_1[0x16a7] = 0;
      }
      param_1[0x2bf] = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x34) = 0xffffffff;
      LOCK();
      UNLOCK();
      tw_msg_dev(param_1,8,"Disabling interrupts <<<==========================",uVar12);
      tw_msg_dev(param_1,8,"FindAdapter> Successful",uVar12);
      *param_6 = 1;
      return 1;
    }
    uVar10 = 2;
  }
LAB_1c0001d21:
  tw_msg_dev(param_1,2,"Failed FindAdapter: Unload Driver",uVar12);
  return uVar10;
}



===== Initialize @ 1c0001e20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char Initialize(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  longlong lVar5;
  undefined1 auStack_c8 [32];
  uint local_a8;
  char *local_a0;
  char *local_98;
  char *local_90;
  char *local_88;
  char *local_80;
  undefined4 local_78 [2];
  uint local_70 [2];
  uint local_68;
  char local_48 [56];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar3 = tw_time_msecs();
  if (tw_crash_dump == '\0') {
    pcVar4 = tw_time_date(local_48);
    tw_msg_dev(param_1,8,"Initialize> %s",pcVar4);
    if (param_1[1] == 0) {
      memset(local_70,0,0x28);
      uVar2 = StorPortExtendedFunction(0xe,param_1,1,local_70);
      if (uVar2 == 0) {
        local_a0 = "";
        local_80 = "";
        if ((local_68 & 8) != 0) {
          local_80 = "Adv-Locality";
        }
        local_88 = "";
        if ((local_68 & 4) != 0) {
          local_88 = "MSI-Ranges";
        }
        local_90 = "";
        if ((local_68 & 2) != 0) {
          local_90 = "Multi-Channels ";
        }
        local_98 = "";
        if ((local_68 & 0x10) != 0) {
          local_98 = "Start-Complete";
        }
        if ((local_68 & 1) != 0) {
          local_a0 = "DPC-Redirect ";
        }
        local_a8 = local_68;
        tw_msg_dev(param_1,4,"PerfOpts: Ver=%d Flags=%X (%s%s%s)",(ulonglong)local_70[0]);
      }
      else {
        tw_msg_dev(param_1,8,"StorPortInitializePerfOpts() failed: %X (Assume Server 2003)",
                   (ulonglong)uVar2);
        param_1[1] = 1;
      }
    }
    local_78[0] = 0;
    StorPortNotification(0x1000,param_1,tw_dpc_init,local_78);
  }
  else {
    tw_msg_dev(param_1,8,"Initialize> Memory Dump Driver",param_4);
  }
  if (param_1[0xf87] != 0) {
    cm_ctrl_reset((undefined8 *)(param_1 + 0xf7e));
  }
  param_1[0x218] = 1;
  cVar1 = tw_fwstate_exec(param_1,1);
  param_1[0x218] = 0;
  lVar5 = tw_time_msecs();
  local_a8 = (int)lVar5 - (int)lVar3;
  pcVar4 = "failed";
  if (cVar1 != '\0') {
    pcVar4 = "complete";
  }
  tw_msg_dev(param_1,8,"Initialize %s (msecs=%u)",pcVar4);
  return cVar1;
}



===== ResetBus @ 1c0002040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char ResetBus(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  char local_48 [56];
  ulonglong local_10;
  
  cVar1 = tw_crash_dump;
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  if ((tw_crash_dump == '\0') || (param_1[0x23a] == 0)) {
    param_1[0x23a] = 0;
    pcVar4 = "";
    if (cVar1 == '\0') {
      pcVar2 = tw_time_date(local_48);
    }
    else {
      pcVar2 = "";
    }
    tw_msg_dev(param_1,1,"ResetBus> %s",pcVar2);
    local_78 = 0x80000000;
    local_80 = 6;
    local_88 = (undefined4 *)((ulonglong)local_88 & 0xffffffffffffff00);
    StorPortLogError(param_1,0,0,0);
    local_68[0] = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_88 = local_68;
    StorPortNotification(0x1003,param_1,3);
    param_1[0x23b] = 1;
    cVar1 = tw_fwstate_exec(param_1,2);
    if (cVar1 == '\0') {
      if (tw_crash_dump == '\0') {
        pcVar4 = tw_time_date(local_48);
      }
      pcVar2 = "ResetBus> Failed: %s";
      uVar3 = 1;
    }
    else {
      if (tw_crash_dump == '\0') {
        pcVar4 = tw_time_date(local_48);
      }
      pcVar2 = "ResetBus> Successful: %s";
      uVar3 = 4;
    }
    tw_msg_dev(param_1,uVar3,pcVar2,pcVar4);
    StorPortNotification(0x1004,param_1,local_68);
  }
  else {
    tw_msg_dev(param_1,8,"ResetBus> MemDump: Ignoring call",param_4);
    cVar1 = '\x01';
    param_1[0x23a] = 0;
  }
  return cVar1;
}



===== BuildIO @ 1c00021e0 =====

bool BuildIO(byte *param_1,byte *param_2,char *param_3,char *param_4)

{
  ushort uVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined8 *puVar17;
  bool bVar18;
  byte *local_res8;
  int local_res10 [2];
  byte *local_res18;
  longlong *plVar19;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar21;
  uint *puVar20;
  undefined8 local_78;
  uint local_70;
  uint *local_68;
  byte local_60;
  byte local_5f;
  undefined4 local_5c;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  pbVar13 = *(byte **)(param_2 + 0x38);
  bVar18 = true;
  *(byte **)pbVar13 = param_1;
  tw_request_init((undefined8 *)pbVar13,(longlong)param_2);
  local_res8 = param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7e2;
  LOCK();
  *(int *)local_res8 = *(int *)local_res8 + 1;
  UNLOCK();
  uVar16 = 0;
  if (param_1[0x2b8] != 0) {
    *(int *)(param_1 + 0x2ac) = *(int *)(param_1 + 0x2ac) + 1;
  }
  if (((*(int *)(param_1 + 0x232) == 0) && (param_2[2] != 2)) && (1 < (byte)(param_2[2] - 0x24))) {
    local_58[0] = 0;
    local_48 = 0;
    uVar8 = 0;
    local_40 = 0;
    local_50 = 0;
    StorPortNotification(0x1003,param_1,2,0,local_58);
    if ((*(uint *)(param_1 + 0x296) >> 0x1c & 1) != 0) {
      uVar10 = *(uint *)(param_1 + 0x7da);
      if (uVar10 == (int)((ulonglong)uVar10 / 100) * 100) {
        tw_xlate_opcode((ulonglong)CONCAT31((int3)(uVar10 >> 8),pbVar13[0x12]),
                        CONCAT71((int7)((ulonglong)uVar10 / 100 >> 8),pbVar13[0x13]),
                        *(uint *)(pbVar13 + 0x14),pbVar13[0x18],(undefined4 *)(pbVar13 + 0x104));
        uVar5 = (ulonglong)(*(int *)(param_1 + 0x7da) + 1);
        tw_msg_dev(param_1,8,"FW STOPPED(%d): %s",uVar5);
        lVar9 = *(longlong *)(pbVar13 + 8);
        if (lVar9 == 0) {
          uVar14 = 0;
          uVar15 = 0;
        }
        else {
          uVar14 = *(undefined1 *)(lVar9 + 7);
          uVar15 = *(undefined1 *)(lVar9 + 6);
          uVar16 = *(undefined1 *)(lVar9 + 5);
        }
        uVar8 = CONCAT71((int7)(uVar5 >> 8),uVar15);
        StorPortLogError(*(undefined8 *)pbVar13,lVar9,uVar16,uVar8,uVar14,6,
                         CONCAT44(uVar21,0xdead0002));
      }
    }
    *(int *)(param_1 + 0x7da) = *(int *)(param_1 + 0x7da) + 1;
    puVar6 = local_58;
    StorPortNotification(0x1004,param_1);
    tw_srb_status((longlong)param_2,'\x11');
    tw_request_done((longlong *)pbVar13,0,puVar6,uVar8);
    return false;
  }
  local_res18 = param_1 + 0x2a0;
  LOCK();
  *(int *)local_res18 = *(int *)local_res18 + 1;
  UNLOCK();
  lVar9 = 0;
  tw_srb_status((longlong)param_2,'\0');
  pbVar12 = pbVar13;
  tw_request_match((longlong *)pbVar13,lVar9,param_3,param_4);
  if ((tw_crash_dump != '\0') && (param_2[2] != 0)) {
    param_4 = (char *)tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar12 >> 8),pbVar13[0x12]),
                                      CONCAT71((int7)((ulonglong)lVar9 >> 8),pbVar13[0x13]),
                                      *(uint *)(pbVar13 + 0x14),pbVar13[0x18],
                                      (undefined4 *)(pbVar13 + 0x104));
    param_3 = "BuildIO> MemDump: %s";
    lVar9 = 8;
    tw_msg_req((longlong *)pbVar13,8,"BuildIO> MemDump: %s",param_4);
  }
  uVar10 = (uint)param_2[2];
  pbVar12 = pbVar13;
  if (uVar10 < 0x14) {
    if (uVar10 == 0x13) {
      param_4 = (char *)(ulonglong)param_2[6];
      param_3 = "BuildIO> Reset_Device: Target=%d";
      uVar8 = 0;
      tw_msg_req((longlong *)pbVar13,8,"BuildIO> Reset_Device: Target=%d",param_4);
LAB_1c0002535:
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),9);
LAB_1c0002537:
      tw_srb_status((longlong)param_2,(char)uVar8);
LAB_1c000243d:
      tw_request_store((longlong *)pbVar13,uVar8,param_3,param_4);
      pcVar7 = param_4;
      goto LAB_1c0002927;
    }
    uVar10 = (uint)param_2[2];
    if (uVar10 == 0) {
      pbVar13[0x13] = 0x10;
      bVar4 = param_2[0x48];
      *(uint *)(pbVar13 + 0x14) = (uint)bVar4;
      if (bVar4 == 0x1b) {
        bVar4 = param_2[0x4c];
      }
      else {
        bVar4 = 0;
      }
      pbVar13[0x18] = bVar4;
      tw_request_store((longlong *)pbVar13,lVar9,param_3,param_4);
      pbVar12 = param_2;
      uVar5 = tw_scsi_execute((longlong)param_2);
      cVar3 = (char)uVar5;
      pcVar7 = param_4;
LAB_1c00024bd:
      if (cVar3 == '\0') goto LAB_1c0002927;
    }
    else {
      if (uVar10 == 2) {
        uVar5 = tw_ioctl_claimed((longlong)param_2,lVar9,param_3);
        if ((char)uVar5 == '\0') {
          pbVar12 = param_2;
          tw_srb_status((longlong)param_2,'\x06');
          pcVar7 = param_4;
        }
        else {
          pbVar12 = param_2;
          tw_ioctl_execute((longlong)param_2,lVar9,param_3,param_4);
          pcVar7 = param_4;
        }
        goto LAB_1c0002927;
      }
      if (uVar10 == 7) {
        param_3 = "BuildIO> Shutdown: Target=%d Lun=%d";
        pcVar7 = (char *)(ulonglong)param_2[6];
        uVar8 = 8;
        tw_msg_req((longlong *)pbVar13,8,"BuildIO> Shutdown: Target=%d Lun=%d",pcVar7);
        tw_request_store((longlong *)pbVar13,uVar8,param_3,pcVar7);
        cVar3 = tw_crash_dump;
        goto LAB_1c00024bd;
      }
      iVar11 = uVar10 - 8;
      if (iVar11 != 0) {
        if (iVar11 != 8) goto LAB_1c000256e;
        param_3 = "BuildIO> Abort";
        uVar8 = 8;
        tw_msg_req((longlong *)pbVar13,8,"BuildIO> Abort",param_4);
        goto LAB_1c000243d;
      }
      bVar18 = (tw_cache_control & 0x10) == 0;
      if (bVar18) {
        pbVar2 = *(byte **)(pbVar13 + 0x1a0);
        pbVar2[1] = 0;
        pbVar2[5] = 0x10;
        *pbVar2 = *pbVar2 & 0xf0 | 0x10;
        *(ushort *)(pbVar2 + 2) = *(ushort *)(pbVar2 + 2) & 0xfff;
        pbVar2[6] = 0;
        pbVar2[7] = 0;
        pbVar2[8] = 0x35;
      }
      tw_request_store((longlong *)pbVar13,lVar9,param_3,param_4);
      pcVar7 = param_4;
    }
  }
  else {
    if (uVar10 == 0x17) {
      bVar4 = param_2[9];
      pbVar13[0x13] = 2;
      *(uint *)(pbVar13 + 0x14) = (uint)param_2[4] << 0x10 | (uint)param_2[2];
      pbVar13[0x18] = param_2[9];
      tw_request_store((longlong *)pbVar13,lVar9,param_3,param_4);
      pcVar7 = "Device";
      param_3 = "BuildIO> WMI: %s.SubFun=%d Len=%d";
      if ((bVar4 & 1) != 0) {
        pcVar7 = "Adapter";
      }
      tw_msg_req((longlong *)pbVar13,0x8000,"BuildIO> WMI: %s.SubFun=%d Len=%d",pcVar7);
      if ((bVar4 & 1) == 0) {
        param_2[0x10] = 0;
        param_2[0x11] = 0;
        param_2[0x12] = 0;
        param_2[0x13] = 0;
        param_2[3] = 1;
      }
      else {
        bVar4 = param_2[4];
        puVar20 = *(uint **)(param_2 + 0x18);
        plVar19 = *(longlong **)(param_2 + 0x20);
        local_78 = 0;
        local_res8 = (byte *)((ulonglong)local_res8 & 0xffffffff00000000);
        if (bVar4 < 10) {
          puVar17 = &local_78;
          local_5c = 0;
          local_70 = *(uint *)(param_2 + 0x10);
          local_68 = puVar20;
          local_60 = bVar4;
          bVar4 = ScsiWmipProcessRequest
                            ((uint *)(param_1 + 0x1670),bVar4,param_1,puVar17,plVar19,
                             *(uint *)(param_2 + 0x10),puVar20,(uint *)&local_res8,local_res10);
          uVar21 = (undefined4)((ulonglong)puVar20 >> 0x20);
          if (local_res10[0] == 1) {
            local_5c = local_res8._0_4_;
            if (bVar4 != 1) {
              local_5c = 0;
            }
            local_res8 = (byte *)CONCAT44(local_res8._4_4_,local_5c);
            local_5f = bVar4;
          }
          if (bVar4 == 0) {
            tw_msg_req((longlong *)pbVar13,1,"BuildIO> WMI: DispatchFunction pended",puVar17);
            StorPortLogError(param_1,0,0,0,(ulonglong)plVar19 & 0xffffffffffffff00,6,
                             CONCAT44(uVar21,0x30000001));
          }
        }
        else {
          local_5c = 0;
          local_5f = 4;
        }
        param_2[3] = local_5f;
        param_3 = "BuildIO> WMI: Status=%d Len=%d";
        pcVar7 = (char *)(ulonglong)local_5f;
        *(undefined4 *)(param_2 + 0x10) = local_5c;
        pbVar12 = pbVar13;
        tw_msg_req((longlong *)pbVar13,0x8000,"BuildIO> WMI: Status=%d Len=%d",pcVar7);
      }
    }
    else {
      if (uVar10 == 0x20) {
        param_3 = "BuildIO> Reset_LUN: Target=%d Lun=%d";
        param_4 = (char *)(ulonglong)param_2[6];
        uVar8 = 0;
        tw_msg_req((longlong *)pbVar13,8,"BuildIO> Reset_LUN: Target=%d Lun=%d",param_4);
        goto LAB_1c0002535;
      }
      iVar11 = uVar10 - 0x24;
      if (iVar11 == 0) {
        pbVar13[0x13] = 8;
        *(uint *)(pbVar13 + 0x14) =
             (*(int *)(param_2 + 0x40) << 8 | *(uint *)(param_2 + 8)) << 0x10 | (uint)param_2[2];
        pbVar13[0x18] = param_2[4];
        tw_request_store((longlong *)pbVar13,lVar9,param_3,param_4);
        iVar11 = *(int *)(param_2 + 0x40);
        if (iVar11 == 2) {
          pcVar7 = "Sleep";
        }
        else if (iVar11 == 3) {
          pcVar7 = "Hibernate";
        }
        else if (iVar11 == 4) {
          pcVar7 = "Shutdown";
        }
        else if (iVar11 == 5) {
          pcVar7 = "ShutdownReset";
        }
        else if (iVar11 == 6) {
          pcVar7 = "ShutdownOff";
        }
        else if (iVar11 == 7) {
          pcVar7 = "WarmEject";
        }
        else {
          pcVar7 = "Unknown";
        }
        param_3 = "BuildIO> Power: %s.D%d";
        tw_msg_req((longlong *)pbVar13,4,"BuildIO> Power: %s.D%d",pcVar7);
      }
      else {
        if (iVar11 != 1) {
LAB_1c000256e:
          puVar6 = tw_xlate_opcode((ulonglong)CONCAT31((int3)((uint)iVar11 >> 8),pbVar13[0x12]),
                                   CONCAT71((int7)((ulonglong)lVar9 >> 8),pbVar13[0x13]),
                                   *(uint *)(pbVar13 + 0x14),pbVar13[0x18],
                                   (undefined4 *)(pbVar13 + 0x104));
          tw_msg_req((longlong *)pbVar13,1,"Unsupported: %s",puVar6);
          lVar9 = *(longlong *)(pbVar13 + 8);
          if (lVar9 == 0) {
            uVar16 = 0;
            bVar4 = 0;
          }
          else {
            uVar16 = *(undefined1 *)(lVar9 + 6);
            bVar4 = *(byte *)(lVar9 + 5);
          }
          param_4 = (char *)CONCAT71((int7)((ulonglong)puVar6 >> 8),uVar16);
          param_3 = (char *)(ulonglong)bVar4;
          StorPortLogError(*(undefined8 *)pbVar13);
          uVar8 = CONCAT71((int7)((ulonglong)lVar9 >> 8),6);
          goto LAB_1c0002537;
        }
        pbVar13[0x13] = 4;
        pcVar7 = "";
        *(uint *)(pbVar13 + 0x14) =
             (*(int *)(param_2 + 8) << 8 | (uint)param_2[4]) << 0x10 | (uint)param_2[2];
        pbVar13[0x18] = param_2[0x40];
        tw_request_store((longlong *)pbVar13,lVar9,param_3,param_4);
        iVar11 = *(int *)(param_2 + 8);
        if (iVar11 == 0) {
          pcVar7 = "Start";
        }
        else if (iVar11 == 2) {
          pcVar7 = "Remove";
        }
        else if (iVar11 == 4) {
          pcVar7 = "Stop";
        }
        else if (iVar11 == 9) {
          pcVar7 = "Query";
        }
        else if (iVar11 == 0xd) {
          pcVar7 = "Filter";
        }
        param_3 = "BuildIO> PnP: %s.%d";
        tw_msg_req((longlong *)pbVar13,4,"BuildIO> PnP: %s.%d",pcVar7);
        if ((*(int *)(param_2 + 8) == 2) && (param_1[0xf86] != 0)) {
          param_1[0xf87] = 0;
          tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x119e),param_3,pcVar7);
          tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x11a6),param_3,pcVar7);
          pbVar12 = param_1;
          tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x11ae),param_3,pcVar7);
        }
      }
    }
LAB_1c0002927:
    bVar18 = false;
  }
  uVar1 = *(ushort *)(pbVar13 + 0x24);
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 0x4000) != 0) {
      pbVar12 = pbVar13;
      uVar8 = tw_pendio_insert(param_1,pbVar13,'\x01');
      if ((char)uVar8 != '\0') goto LAB_1c0002a16;
      pcVar7 = (char *)tw_xlate_opcode(CONCAT71((int7)((ulonglong)param_1 >> 8),pbVar13[0x12]),
                                       CONCAT71((int7)((ulonglong)pbVar12 >> 8),pbVar13[0x13]),
                                       *(uint *)(pbVar13 + 0x14),pbVar13[0x18],
                                       (undefined4 *)(pbVar13 + 0x104));
      param_3 = "BuildIO> Pending queue full: ";
      tw_msg_req((longlong *)pbVar13,8,"BuildIO> Pending queue full: ",pcVar7);
      if (*(int *)(pbVar13 + 0x20) == 1) {
        puVar20 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x14);
        *puVar20 = *puVar20 | 3;
      }
      else {
        puVar20 = (uint *)(*(longlong *)(param_2 + 0x18) + 0x14);
        *puVar20 = *puVar20 | 0x20;
      }
LAB_1c0002a0c:
      tw_request_done((longlong *)pbVar13,0,param_3,pcVar7);
      goto LAB_1c0002a16;
    }
    if (bVar18 == false) goto LAB_1c0002a0c;
  }
  else {
    if (*(int *)(param_1 + 0x232) == 0) {
      pcVar7 = (char *)tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar12 >> 8),pbVar13[0x12]),
                                       (ulonglong)CONCAT11((char)(uVar1 >> 8),pbVar13[0x13]),
                                       *(uint *)(pbVar13 + 0x14),pbVar13[0x18],
                                       (undefined4 *)(pbVar13 + 0x104));
      param_3 = "BuildIO> Firmware stopped: %s";
      tw_msg_req((longlong *)pbVar13,8,"BuildIO> Firmware stopped: %s",pcVar7);
      *(undefined2 *)(*(longlong *)(param_2 + 0x18) + 0x16) = 0x8003;
      goto LAB_1c0002a0c;
    }
    bVar18 = true;
    iVar11 = *(int *)(*(longlong *)(param_2 + 0x18) + 0xc);
    *(ushort *)(pbVar13 + 0x24) = uVar1 | 0x8000;
    *(int *)(pbVar13 + 0x38) = iVar11 * 1000;
LAB_1c0002a16:
    if (bVar18 == false) goto LAB_1c0002a47;
  }
  if ((*(char *)(*(longlong *)pbVar13 + 0xf87) != '\0') && (pbVar13[0x68] != 0)) {
    pbVar13 = (byte *)((ulonglong)*(ushort *)(pbVar13 + 0x6a) * 0x1c +
                      *(longlong *)(*(longlong *)pbVar13 + 0x119e));
    *pbVar13 = *pbVar13 | 0x80;
    lVar9 = tw_time_msecs();
    *(int *)(pbVar13 + 0x18) = (int)lVar9;
  }
LAB_1c0002a47:
  LOCK();
  *(int *)local_res18 = *(int *)local_res18 + -1;
  UNLOCK();
  return bVar18;
}



===== StartIO @ 1c0002a80 =====

undefined8 StartIO(byte *param_1,byte *param_2,char *param_3,undefined4 *param_4)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined7 uVar7;
  char cVar8;
  byte *pbVar9;
  undefined7 uVar10;
  byte *pbVar11;
  uint uVar12;
  char local_38 [8];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  pbVar1 = *(byte **)(param_2 + 0x38);
  LOCK();
  *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + -1;
  UNLOCK();
  pbVar9 = param_2;
  if ((*(char *)(*(longlong *)pbVar1 + 0xf87) != '\0') && (pbVar1[0x68] != 0)) {
    pbVar11 = (byte *)((ulonglong)*(ushort *)(pbVar1 + 0x6a) * 0x1c +
                      *(longlong *)(*(longlong *)pbVar1 + 0x119e));
    if ((char)*pbVar11 < '\0') {
      *pbVar11 = *pbVar11 & 0x7f;
      lVar3 = tw_time_msecs();
      *(int *)(pbVar11 + 0x18) = (int)lVar3;
    }
  }
  lVar3 = tw_time_msecs();
  iVar2 = (int)lVar3;
  uVar6 = (ulonglong)(uint)(iVar2 - *(int *)(param_1 + 0x2b9));
  if (60000 < (uint)(iVar2 - *(int *)(param_1 + 0x2b9))) {
    local_38[0] = '\0';
    local_38[1] = '\0';
    local_38[2] = '\0';
    local_38[3] = '\0';
    local_28 = 0;
    local_20 = 0;
    param_4 = (undefined4 *)0x0;
    local_30 = 0;
    StorPortNotification(0x1003,param_1,3,0,local_38);
    *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7de) = iVar2;
    *(short *)(param_1 + 0x2bd) = *(short *)(param_1 + 0x2bd) + 1;
    if (0x3b < *(ushort *)(param_1 + 0x2bd)) {
      param_1[0x2bd] = 0;
      param_1[0x2be] = 0;
    }
    param_3 = local_38;
    lVar3 = (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20;
    *(int *)(param_1 + 0x2b9) = iVar2;
    uVar6 = 0x1004;
    pbVar9 = param_1 + lVar3 + 0x7de;
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    pbVar9[3] = 0;
    pbVar9[4] = 0;
    pbVar9[5] = 0;
    pbVar9[6] = 0;
    pbVar9[7] = 0;
    pbVar9 = param_1 + lVar3 + 0x7e6;
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    pbVar9[3] = 0;
    pbVar9[4] = 0;
    pbVar9[5] = 0;
    pbVar9[6] = 0;
    pbVar9[7] = 0;
    pbVar9 = param_1 + lVar3 + 0x7ee;
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    pbVar9[3] = 0;
    pbVar9[4] = 0;
    pbVar9[5] = 0;
    pbVar9[6] = 0;
    pbVar9[7] = 0;
    pbVar9 = param_1 + lVar3 + 0x7f6;
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    pbVar9[3] = 0;
    pbVar9[4] = 0;
    pbVar9[5] = 0;
    pbVar9[6] = 0;
    pbVar9[7] = 0;
    pbVar9 = param_1;
    StorPortNotification(0x1004);
  }
  if (param_1[0x2b8] != 0) {
    *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + 1;
  }
  uVar10 = (undefined7)((ulonglong)pbVar9 >> 8);
  uVar7 = (undefined7)(uVar6 >> 8);
  if (*(int *)(param_1 + 0x232) == 0) {
    param_4 = tw_xlate_opcode(CONCAT71(uVar7,pbVar1[0x12]),CONCAT71(uVar10,pbVar1[0x13]),
                              *(uint *)(pbVar1 + 0x14),pbVar1[0x18],(undefined4 *)(pbVar1 + 0x104));
    param_3 = "StartIO> Is Stopped: %s";
    tw_msg_req((longlong *)pbVar1,1,"StartIO> Is Stopped: %s",param_4);
    cVar8 = '\x11';
  }
  else {
    if (param_1[0x216] == 0) {
      if (param_2[2] == 7) {
        tw_fwstate_exec(param_1,0);
        cVar8 = '\x01';
        goto LAB_1c0002d96;
      }
      if ((*(ushort *)(pbVar1 + 0x24) & 0x8000) != 0) {
        param_3 = (char *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        uVar4 = tw_pendio_insert(param_1,pbVar1,'\x01');
        if ((char)uVar4 == '\0') {
          if ((*(uint *)(param_1 + 0x296) >> 0x18 & 1) != 0) {
            param_3 = "StartIO> Pending queue full: returning BUSY";
            tw_msg_req((longlong *)pbVar1,2,"StartIO> Pending queue full: returning BUSY",param_4);
          }
          goto LAB_1c0002d94;
        }
      }
      uVar6 = tw_request_start((longlong *)pbVar1);
      if ((char)uVar6 != '\0') {
        if (param_1[0x2b8] != 0) {
          lVar3 = tw_time_msecs();
          uVar12 = (int)lVar3 - *(int *)(param_1 + 0x2b4);
          bVar5 = 8;
          param_1[0x2b8] = 0;
          if (*(uint *)(param_1 + 0x2d4) < *(uint *)(param_1 + 0x2ac)) {
            *(uint *)(param_1 + 0x2d4) = *(uint *)(param_1 + 0x2ac);
            bVar5 = 4;
          }
          if (*(uint *)(param_1 + 0x2d8) < *(uint *)(param_1 + 0x2b0)) {
            *(uint *)(param_1 + 0x2d8) = *(uint *)(param_1 + 0x2b0);
            bVar5 = 4;
          }
          if (*(uint *)(param_1 + 0x2dc) < uVar12) {
            *(uint *)(param_1 + 0x2dc) = uVar12;
            bVar5 = 4;
          }
          uVar6 = (ulonglong)*(uint *)(param_1 + 0x296);
          if ((*(uint *)(param_1 + 0x296) >> 0x1b & 1) != 0) {
            uVar6 = tw_msg_req((longlong *)pbVar1,(uint)bVar5,
                               "StartIO> Not Busy: Posted=%-3d Builds=%-3d Starts=%-3d Msecs=%u",
                               (ulonglong)*(uint *)(param_1 + 0x2a4));
          }
        }
        goto LAB_1c0002e4d;
      }
      if ((*(ushort *)(pbVar1 + 0x24) & 0x8000) != 0) {
        param_3 = (char *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        tw_pendio_delete((longlong *)param_1,(longlong *)pbVar1,'\x01');
      }
      *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7f6) =
           *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7f6) + 1;
      if (param_1[0x2b8] == 0) {
        param_1[0x2b8] = 1;
        param_1[0x2ac] = 0;
        param_1[0x2ad] = 0;
        param_1[0x2ae] = 0;
        param_1[0x2af] = 0;
        param_1[0x2b0] = 0;
        param_1[0x2b1] = 0;
        param_1[0x2b2] = 0;
        param_1[0x2b3] = 0;
        lVar3 = tw_time_msecs();
        *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) + 1;
        *(int *)(param_1 + 0x2b4) = (int)lVar3;
        if ((*(uint *)(param_1 + 0x296) >> 0x19 & 1) != 0) {
          param_4 = (undefined4 *)(ulonglong)*(uint *)(param_1 + 0x2a4);
          param_3 = "StartIO> Set Busy: Posted=%d";
          tw_msg_req((longlong *)pbVar1,8,"StartIO> Set Busy: Posted=%d",param_4);
        }
        StorPortBusy(param_1,tw_busy_waitcount);
      }
      else {
        lVar3 = tw_time_msecs();
        if (((*(uint *)(param_1 + 0x296) & 0x4000000) != 0) &&
           ((int)lVar3 != *(int *)(param_1 + 0x2b4))) {
          param_4 = (undefined4 *)(ulonglong)*(uint *)(param_1 + 0x2a4);
          param_3 = "StartIO> Busy Now: Posted=%-3d Builds=%-3d Starts=%-3d Msecs=%u";
          tw_msg_req((longlong *)pbVar1,8,
                     "StartIO> Busy Now: Posted=%-3d Builds=%-3d Starts=%-3d Msecs=%u",param_4);
        }
      }
    }
    else {
      param_4 = tw_xlate_opcode(CONCAT71(uVar7,pbVar1[0x12]),CONCAT71(uVar10,pbVar1[0x13]),
                                *(uint *)(pbVar1 + 0x14),pbVar1[0x18],(undefined4 *)(pbVar1 + 0x104)
                               );
      param_3 = "StartIO> Is Paused: %s";
      tw_msg_req((longlong *)pbVar1,2,"StartIO> Is Paused: %s",param_4);
    }
LAB_1c0002d94:
    cVar8 = '\x05';
  }
LAB_1c0002d96:
  tw_srb_status((longlong)param_2,cVar8);
  uVar6 = tw_request_done((longlong *)pbVar1,0,param_3,param_4);
LAB_1c0002e4d:
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== Interrupt @ 1c0002e70 =====

ulonglong Interrupt(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x40) + 0x30) & 0xc) == 0) {
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x296);
    if ((*(uint *)(param_1 + 0x296) >> 0x1d & 1) != 0) {
      uVar1 = tw_hware_status_display(param_1);
    }
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = tw_isr(param_1,*(uint *)(*(longlong *)(param_1 + 0x40) + 0x30),param_3,param_4);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar1;
}



===== Int_Msi @ 1c0002eb0 =====

void Int_Msi(byte *param_1,ulonglong param_2,char *param_3,ulonglong param_4)

{
  if ((int)param_2 != 0) {
    param_4 = param_2 & 0xffffffff;
    param_3 = "MSI> Message=%d";
    param_2 = 8;
    tw_msg_dev(param_1,8,"MSI> Message=%d",param_4);
  }
  Interrupt(param_1,param_2,param_3,param_4);
  return;
}



===== AdapterControl @ 1c0002ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AdapterControl(byte *param_1,uint param_2,uint *param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 uVar4;
  byte bVar5;
  ulonglong uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined *puVar9;
  undefined1 local_e8 [32];
  char *local_c8;
  undefined1 *local_c0;
  undefined *local_b8;
  char local_a8 [56];
  char local_70 [56];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_e8;
  if (param_2 == 0) {
    if (*param_3 != 0) {
      uVar6 = 0;
      if (*param_3 != 0) {
        do {
          *(undefined1 *)(uVar6 + 4 + (longlong)param_3) = 0;
          uVar3 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar3;
        } while (uVar3 < *param_3);
      }
      *(undefined1 *)(param_3 + 1) = 1;
      if ((*param_3 != 0) && (*(undefined1 *)((longlong)param_3 + 5) = 1, 1 < *param_3)) {
        *(undefined1 *)((longlong)param_3 + 6) = 1;
        goto LAB_1c0003194;
      }
    }
LAB_1c0002fc7:
    uVar4 = 1;
  }
  else {
    if (param_2 == 1) {
      pcVar7 = "";
      if (tw_crash_dump == '\0') {
        local_c8 = tw_time_date(local_a8);
      }
      else {
        local_c8 = "";
      }
      pcVar8 = "StopAdapter";
      tw_msg_dev(param_1,8,"%s> %s","StopAdapter");
      *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x34) = 0xffffffff;
      LOCK();
      UNLOCK();
      tw_msg_dev(param_1,8,"Disabling interrupts <<<==========================",pcVar8);
      tw_fwstate_exec(param_1,0);
      uVar3 = FUN_1c000a9fc((longlong)param_1,0,(undefined1 *)0x0,-1);
      uVar2 = tw_request_check(param_1,'\x01','\0');
      if ((uVar3 != 0) || (uVar2 != 0)) {
        local_c8 = (char *)CONCAT44(local_c8._4_4_,(uint)uVar2);
        tw_msg_dev(param_1,2,"DeviceStop>  Outstanding: Pending=%u Posted=%d",(ulonglong)uVar3);
        local_b8 = (undefined *)CONCAT44(local_b8._4_4_,uVar2 + 0xc0000000);
        local_c0 = (undefined1 *)CONCAT44(local_c0._4_4_,6);
        local_c8 = (char *)((ulonglong)local_c8 & 0xffffffffffffff00);
        StorPortLogError(param_1,0,0,0);
      }
      local_b8 = &s_11_Apr_13;
      local_c0 = (undefined1 *)CONCAT44(local_c0._4_4_,0x28);
      local_c8 = (char *)CONCAT44(local_c8._4_4_,0x28);
      tw_msg_dev(param_1,8,"%s (%u-%u) %s",&s_5_01_00_051);
      local_c0 = &tw_win_version;
      puVar9 = &s_3ware;
      local_c8 = "";
      tw_msg_dev(param_1,8,"%s%s - %s",&s_3ware);
      if (tw_crash_dump == '\0') {
        pcVar7 = tw_time_date(local_a8);
      }
      tw_msg_dev(param_1,8,pcVar7,puVar9);
      (&tw_driver_slot)[*param_1] = 0;
    }
    else if (param_2 == 2) {
      uVar6 = 0;
      do {
        if ((&tw_driver_slot)[uVar6] == '\0') {
          *param_1 = (byte)uVar6;
          (&tw_driver_slot)[uVar6] = 1;
          break;
        }
        bVar5 = (byte)uVar6 + 1;
        uVar6 = (ulonglong)bVar5;
      } while (bVar5 < 0x10);
      if (tw_crash_dump == '\0') {
        pcVar7 = tw_time_date(local_70);
      }
      else {
        pcVar7 = "";
      }
      tw_msg_dev(param_1,8,"RestartAdapter> %s",pcVar7);
      *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x34) = 0xffffffff;
      LOCK();
      UNLOCK();
      tw_msg_dev(param_1,8,"Disabling interrupts <<<==========================",pcVar7);
      cVar1 = tw_fwstate_exec(param_1,1);
      if (cVar1 == '\0') goto LAB_1c0002fc7;
    }
    else {
      tw_msg_dev(param_1,2,"AdapterControl> Unknown ControlType %d",(ulonglong)param_2);
    }
LAB_1c0003194:
    uVar4 = 0;
  }
  return uVar4;
}



===== tw_flow_pause @ 1c000319c =====

void tw_flow_pause(byte *param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (tw_crash_dump == '\0') {
    if (param_1[0x216] == 0) {
      cVar1 = StorPortPause(param_1,param_3);
      if (cVar1 == '\0') {
        tw_msg_dev(param_1,1,"%s> Pause() failed",param_2);
        StorPortLogError(param_1,0,0,0,0,6,0x80000001);
        return;
      }
      param_1[0x216] = 1;
      pcVar3 = "%s> << Input now paused >>";
      uVar2 = 4;
      goto LAB_1c0003237;
    }
    pcVar3 = "%s> (Already paused)";
  }
  else {
    pcVar3 = "%s> Ignore pause in crashdump";
  }
  uVar2 = 8;
LAB_1c0003237:
  tw_msg_dev(param_1,uVar2,pcVar3,param_2);
  return;
}



===== tw_flow_resume @ 1c0003248 =====

void tw_flow_resume(byte *param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1[0x216] == 0) {
    pcVar3 = "%s> (Already resumed)";
    uVar2 = 8;
  }
  else {
    cVar1 = StorPortResume();
    if (cVar1 == '\0') {
      tw_msg_dev(param_1,1,"%s> Resume() failed",param_2);
      StorPortLogError(param_1,0,0,0,0,6,0x80000002);
      return;
    }
    param_1[0x216] = 0;
    pcVar3 = "%s> << Input now resumed >>";
    uVar2 = 4;
  }
  tw_msg_dev(param_1,uVar2,pcVar3,param_2);
  return;
}



===== FUN_1c00032e0 @ 1c00032e0 =====

int FUN_1c00032e0(byte *param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 local_res18 [2];
  
  local_res18[0] = DAT_1c0017040;
  cVar1 = StorPortRegistryRead(param_1,param_2,1,4,DAT_1c00178f0,local_res18);
  if ((cVar1 == '\0') || (iVar2 = *DAT_1c00178f0, *DAT_1c00178f0 == -1)) {
    cVar1 = '\0';
    iVar2 = param_3;
  }
  pcVar3 = "DEF";
  if (cVar1 != '\0') {
    pcVar3 = "REG";
  }
  tw_msg_dev(param_1,8,"%s: %s <-- 0x%X (%u)",pcVar3);
  return iVar2;
}



===== tw_init_options @ 1c000338c =====

void tw_init_options(byte *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  if (tw_crash_dump != '\0') {
    return;
  }
  DAT_1c00178f0 = StorPortAllocateRegistryBuffer(param_1,&DAT_1c0017040);
  iVar1 = FUN_1c00032e0(param_1,"MaxLenTransfers",0x80);
  tw_sgls_count = ((iVar1 + 3U & 0x3fffff) >> 2) + 1;
  if (0x21 < tw_sgls_count) {
    tw_sgls_count = 0x21;
    tw_msg_dev(param_1,2,"Decreasing %s to %u","MaxLenTransfers");
  }
  tw_cache_control = FUN_1c00032e0(param_1,"CacheControl",0);
  tw_dbg_control = FUN_1c00032e0(param_1,"DbgControl",tw_dbg_control);
  tw_msg_control = FUN_1c00032e0(param_1,"MsgControl",tw_msg_control);
  tw_cmon_control = FUN_1c00032e0(param_1,&s_CmonControl,tw_cmon_control);
  iVar1 = FUN_1c00032e0(param_1,"MaxDepthQueue",(uint)tw_queue_length);
  tw_queue_length = (ushort)iVar1;
  if (tw_queue_length < 0x1fc1) {
    if (0x25 < tw_queue_length) goto LAB_1c00034e2;
    pcVar3 = "Increasing %s to %u";
    tw_queue_length = 0x26;
  }
  else {
    pcVar3 = "Decreasing %s to %u";
    tw_queue_length = 0x1fc0;
  }
  tw_msg_dev(param_1,2,pcVar3,"MaxDepthQueue");
LAB_1c00034e2:
  iVar1 = FUN_1c00032e0(param_1,"MaxNumUnits",(uint)tw_user_max_units);
  tw_user_max_units = (byte)iVar1;
  iVar1 = FUN_1c00032e0(param_1,"MaxNumLuns",(uint)tw_user_max_luns);
  tw_user_max_luns = (byte)iVar1;
  tw_busy_waitcount = FUN_1c00032e0(param_1,"BusyCompleteCount",tw_busy_waitcount);
  tw_reset_retrycount = FUN_1c00032e0(param_1,"ResetRetryCount",tw_reset_retrycount);
  tw_reset_twait_init = FUN_1c00032e0(param_1,"ResetWaitReadySecs",tw_reset_twait_init);
  tw_restart_timeout = FUN_1c00032e0(param_1,"RestartWaitSecs",tw_restart_timeout);
  iVar1 = FUN_1c00032e0(param_1,"CmonMaxCmds",(uint)tw_cmon_maxcmds);
  tw_cmon_maxcmds = (ushort)iVar1;
  if ((ushort)(tw_cmon_maxcmds - 1) < 0x3ff) {
    tw_cmon_maxcmds = 0x400;
  }
  iVar1 = FUN_1c00032e0(param_1,"CmonAveFactor",(uint)tw_cmon_avefact);
  tw_cmon_avefact = (byte)iVar1;
  if (0x5a < tw_cmon_avefact) {
    tw_cmon_avefact = 0x5a;
  }
  iVar1 = FUN_1c00032e0(param_1,"CmonMaxAves",(uint)tw_cmon_maxaves);
  tw_cmon_maxaves = (ushort)iVar1;
  iVar1 = FUN_1c00032e0(param_1,"CmonMaxLCTs",(uint)tw_cmon_maxlcts);
  tw_cmon_maxlcts = (ushort)iVar1;
  iVar1 = FUN_1c00032e0(param_1,"CmonMinTimeLCT",(uint)tw_cmon_lct_msecs);
  tw_cmon_lct_msecs = (ushort)iVar1;
  uVar2 = FUN_1c00032e0(param_1,"TimeoutValue",tw_timeout_msecs / 1000);
  tw_timeout_msecs = (uVar2 & 0xff) * 1000;
  StorPortFreeRegistryBuffer(param_1,DAT_1c00178f0);
  DAT_1c00178f0 = 0;
  return;
}



===== tw_init_memory @ 1c0003698 =====

ulonglong tw_init_memory(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  ulonglong uVar6;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  longlong lVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int iVar13;
  size_t _Size;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint local_res8;
  int local_res18;
  undefined1 local_50 [16];
  
  pvVar5 = (void *)0x0;
  local_res8 = 0;
  uVar15 = 0;
  uVar9 = 0;
  local_res18 = 0;
  uVar10 = 0;
  iVar14 = 0;
  if (tw_crash_dump == '\0') {
    local_res8 = 0x8000;
    if ((tw_cmon_maxcmds != 0) && ((param_1[0x292] & 0x40) == 0)) {
      uVar9 = (uint)tw_cmon_maxlcts * 0x2c;
      uVar10 = (uint)tw_cmon_maxaves * 0x9c;
      uVar15 = (uint)tw_cmon_maxcmds * tw_cmon_cmdsize;
      iVar14 = uVar10 + uVar9 + uVar15;
    }
    if (((param_1[0x292] & 0x20) == 0) && (iVar14 != 0)) {
      pvVar4 = (void *)tw_memory_alloc(param_1,uVar15);
      pvVar8 = (void *)0x0;
      if (uVar9 != 0) {
        pvVar8 = (void *)tw_memory_alloc(param_1,uVar9);
      }
      if (uVar10 != 0) {
        pvVar5 = (void *)tw_memory_alloc(param_1,uVar10);
      }
      if (pvVar4 != (void *)0x0) {
        if (((uVar9 == 0) || (pvVar8 != (void *)0x0)) && ((uVar10 == 0 || (pvVar5 != (void *)0x0))))
        {
          *(byte **)(param_1 + 0xf7e) = param_1;
          param_1[0xf86] = 1;
          param_1[0xf87] = 1;
          if (uVar15 != 0) {
            memset(pvVar4,0,(ulonglong)uVar15);
          }
          *(ushort *)(param_1 + 0x1192) = tw_cmon_maxcmds;
          *(void **)(param_1 + 0x119e) = pvVar4;
          if (uVar9 != 0) {
            memset(pvVar8,0,(ulonglong)uVar9);
            *(ushort *)(param_1 + 0x1194) = tw_cmon_maxlcts;
            *(void **)(param_1 + 0x11a6) = pvVar8;
          }
          local_res18 = iVar14;
          if (uVar10 != 0) {
            memset(pvVar5,0,(ulonglong)uVar10);
            *(ushort *)(param_1 + 0x1196) = tw_cmon_maxaves;
            *(void **)(param_1 + 0x11ae) = pvVar5;
          }
          goto LAB_1c00037be;
        }
        tw_memory_free(param_1,pvVar4,param_3,param_4);
      }
      if (pvVar8 != (void *)0x0) {
        tw_memory_free(param_1,pvVar8,param_3,param_4);
      }
      if (pvVar5 != (void *)0x0) {
        tw_memory_free(param_1,pvVar5,param_3,param_4);
      }
    }
  }
LAB_1c00037be:
  uVar1 = *(ushort *)(param_1 + 0x14b);
  iVar2 = (uint)uVar1 * 8;
  _Size = (ulonglong)uVar1 * 0x80;
  iVar13 = (int)_Size;
  uVar16 = iVar2 + 0xec3 + (iVar14 - local_res18) + local_res8 + iVar13;
  uVar6 = (ulonglong)uVar16;
  pvVar5 = (void *)StorPortGetUncachedExtension(param_1,param_2,uVar6);
  pvVar4 = (void *)(uVar6 + (longlong)pvVar5);
  if (pvVar5 == (void *)0x0) {
    tw_msg_dev(param_1,1,"InitMem> Failed: %u bytes",(ulonglong)uVar16);
    uVar12 = 0;
    uVar11 = 0;
    uVar6 = StorPortLogError(param_1,0,0,0,0,6,0x1000ffff);
    if (local_res18 != 0) {
      uVar3 = tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x119e),uVar11,uVar12);
      uVar6 = CONCAT44(extraout_var,uVar3);
      if (uVar9 != 0) {
        uVar3 = tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x11a6),uVar11,uVar12);
        uVar6 = CONCAT44(extraout_var_00,uVar3);
      }
      if (uVar10 != 0) {
        uVar3 = tw_memory_free(param_1,*(undefined8 *)(param_1 + 0x11ae),uVar11,uVar12);
        uVar6 = CONCAT44(extraout_var_01,uVar3);
      }
    }
  }
  else {
    if (uVar16 != 0) {
      memset(pvVar5,0,uVar6);
    }
    if (iVar14 - local_res18 != 0) {
      *(void **)(param_1 + 0x119e) = pvVar5;
      pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)uVar15);
      *(byte **)(param_1 + 0xf7e) = param_1;
      param_1[0xf86] = 0;
      param_1[0xf87] = 1;
      if (uVar9 != 0) {
        *(void **)(param_1 + 0x11a6) = pvVar5;
        pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)uVar9);
      }
      if (uVar10 != 0) {
        *(void **)(param_1 + 0x11ae) = pvVar5;
        pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)uVar10);
      }
      *(ushort *)(param_1 + 0x1192) = tw_cmon_maxcmds;
      *(ushort *)(param_1 + 0x1194) = tw_cmon_maxlcts;
      *(ushort *)(param_1 + 0x1196) = tw_cmon_maxaves;
    }
    if (local_res8 != 0) {
      *(void **)(param_1 + 0xf5e) = pvVar5;
      pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)local_res8);
      param_1[0xf66] = 0;
      param_1[0xf67] = 1;
      param_1[0xf68] = 0;
      param_1[0xf69] = 0;
    }
    tw_msg_dev(param_1,8,"Event Queue:      %3u KB",(ulonglong)(local_res8 + 0x1ff >> 10));
    tw_msg_dev(param_1,8,"CmdMon CMDs:      %3u KB",(ulonglong)(uVar15 + 0x1ff >> 10));
    tw_msg_dev(param_1,8,"CmdMon LCTs:      %3u KB",(ulonglong)(uVar9 + 0x1ff >> 10));
    tw_msg_dev(param_1,8,"CmdMon AVEs:      %3u KB",(ulonglong)(uVar10 + 0x1ff >> 10));
    tw_msg_dev(param_1,8,"Request Packets:  %3u KB",4);
    tw_msg_dev(param_1,8,"Req Ptrs Array:   %3u KB",(ulonglong)(iVar2 + 0x23eU >> 10));
    tw_msg_dev(param_1,8,"Response Array:   %3u KB",(ulonglong)(iVar13 + 0x1ffU >> 10));
    tw_msg_dev(param_1,8,"CmdMon Total:     %3u KB",(ulonglong)(iVar14 + 0x1ffU >> 10));
    tw_msg_dev(param_1,8,"Allocation Total: %3u KB",(ulonglong)(local_res18 + uVar16 + 0x1ff >> 10))
    ;
    lVar7 = StorPortGetPhysicalAddress(param_1,0,pvVar5,local_50);
    *(void **)(param_1 + 0x24f) = pvVar5;
    *(longlong *)(param_1 + 599) = lVar7;
    *(longlong *)(param_1 + 0x267) = (longlong)pvVar5 + 0x200;
    *(longlong *)(param_1 + 0x26f) = lVar7 + 0x200;
    *(void **)(param_1 + 0x247) = (void *)((longlong)pvVar5 + 0x400);
    memset((void *)((longlong)pvVar5 + 0x400),0,0x503);
    pvVar5 = (void *)((longlong)pvVar5 + 0x942U & 0xffffffffffffffc0);
    **(undefined8 **)(param_1 + 0x247) = param_1;
    *(void **)(param_1 + 0x25f) = pvVar5;
    memset(pvVar5,0,0x503);
    **(undefined8 **)(param_1 + 0x25f) = param_1;
    *(longlong *)(param_1 + 0x277) = (longlong)pvVar5 + 0x540;
    pvVar8 = (void *)((longlong)pvVar5 + 0x540 + (ulonglong)(iVar2 + 0x3f) + 0x3f &
                     0xffffffffffffffc0);
    pvVar5 = (void *)(_Size + (longlong)pvVar8);
    if (pvVar5 <= pvVar4) {
      *(void **)(param_1 + 0x27f) = pvVar8;
      if (iVar13 != 0) {
        pvVar5 = memset(pvVar8,0,_Size);
      }
      return CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
    }
    uVar6 = tw_msg_dev(param_1,1,"InitMem> Overflow by %d bytes",
                       (longlong)pvVar4 + ((ulonglong)uVar1 * -0x80 - (longlong)pvVar8));
  }
  return uVar6 & 0xffffffffffffff00;
}



===== tw_srb_status @ 1c0003bf0 =====

void tw_srb_status(longlong param_1,char param_2)

{
  *(char *)(param_1 + 3) = param_2;
  if (((*(char *)(param_1 + 2) != '\x17') && (1 < (byte)(*(char *)(param_1 + 2) - 0x24U))) &&
     (param_2 != '\0')) {
    if (param_2 != '\x01') {
      if (param_2 == '\x05') {
        *(undefined1 *)(param_1 + 4) = 0x28;
        return;
      }
      if (param_2 != '\x12') {
        *(undefined1 *)(param_1 + 4) = 2;
        return;
      }
    }
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return;
}



===== tw_scsi_complete @ 1c0003c28 =====

void tw_scsi_complete(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  longlong *plVar3;
  longlong lVar4;
  char cVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  undefined1 uVar10;
  int *piVar11;
  
  plVar3 = *(longlong **)(param_1 + 0x38);
  lVar4 = *plVar3;
  if ((*(char *)(param_1 + 0x48) == '\x12') && ((*(byte *)(param_1 + 0x49) & 1) == 0)) {
    uVar9 = *(uint *)(lVar4 + 0x14d + (ulonglong)*(byte *)(param_1 + 6) * 4);
    if (((int)uVar9 < 1) && (uVar9 = *(ushort *)(lVar4 + 0x14b) - 6, 0xfe < (int)uVar9)) {
      uVar9 = 0xfe;
    }
    cVar5 = StorPortSetDeviceQueueDepth
                      (lVar4,*(undefined1 *)(param_1 + 5),*(byte *)(param_1 + 6),
                       *(undefined1 *)(param_1 + 7),uVar9);
    if (cVar5 == '\0') {
      tw_msg_req(plVar3,2,"ScsiExec> Set queue depth %d failed",(ulonglong)uVar9);
      lVar4 = plVar3[1];
      if (lVar4 == 0) {
        uVar10 = 0;
        uVar7 = 0;
        uVar6 = 0;
      }
      else {
        uVar10 = *(undefined1 *)(lVar4 + 7);
        uVar7 = *(undefined1 *)(lVar4 + 6);
        uVar6 = *(undefined1 *)(lVar4 + 5);
      }
      StorPortLogError(*plVar3,lVar4,uVar6,uVar7,uVar10,6,0x70000009);
    }
    else {
      tw_msg_req(plVar3,8,"ScsiExec> Set queue depth to %d",(ulonglong)uVar9);
    }
  }
  bVar1 = *(byte *)(param_1 + 0x48);
  if ((((bVar1 < 0x1b) && ((0x4240000U >> (bVar1 & 0x1f) & 1) != 0)) || (bVar1 == 0x55)) ||
     (bVar1 == 0x5a)) {
    iVar8 = 0;
    uVar2 = *(ushort *)(plVar3[0x34] + 6);
    uVar9 = uVar2 & 0xfff;
    if ((uVar2 & 0xfff) != 0) {
      piVar11 = (int *)(plVar3[0x34] + 0x20);
      do {
        uVar9 = uVar9 - 1;
        if (tw_dma64bit != '\0') {
          iVar8 = iVar8 + *piVar11;
          piVar11 = piVar11 + 4;
        }
      } while (uVar9 != 0);
    }
    if (*(int *)(param_1 + 0x10) != iVar8) {
      *(int *)(param_1 + 0x10) = iVar8;
      tw_srb_status(param_1,'\x12');
    }
  }
  return;
}



===== tw_scsi_execute @ 1c0003d80 =====

ulonglong tw_scsi_execute(longlong param_1)

{
  ushort *puVar1;
  byte bVar2;
  ulonglong *puVar3;
  longlong *plVar4;
  ulonglong uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  undefined7 uVar10;
  void *_Src;
  undefined1 uVar11;
  char *pcVar12;
  bool bVar13;
  
  bVar2 = *(byte *)(param_1 + 7);
  puVar3 = *(ulonglong **)(param_1 + 0x38);
  pbVar6 = (byte *)puVar3[0x34];
  pbVar6[1] = *(byte *)(param_1 + 6);
  pbVar6[5] = 0x10;
  *pbVar6 = *pbVar6 & 0xf0 | 0x10;
  _Src = (void *)(param_1 + 0x48);
  pcVar12 = (char *)0x10;
  *(ushort *)(pbVar6 + 2) = (ushort)bVar2 << 0xc | *(ushort *)(pbVar6 + 2) & 0xfff;
  *(ushort *)(pbVar6 + 6) = (ushort)(bVar2 >> 4) << 0xc;
  memcpy(pbVar6 + 8,_Src,0x10);
  bVar2 = *(byte *)(param_1 + 0x48);
  uVar5 = 0;
  uVar8 = (uint)bVar2;
  uVar9 = (uint)bVar2;
  uVar10 = (undefined7)((ulonglong)_Src >> 8);
  if (bVar2 < 0x30) {
    if (bVar2 == 0x2f) goto LAB_1c00040aa;
    if (bVar2 < 0x1b) {
      if (uVar8 != 0x1a) {
        if ((uVar8 == 0) || (uVar9 == 3)) goto LAB_1c00040aa;
        uVar7 = (ulonglong)(bVar2 - 8);
        if ((bVar2 - 8 & 0xfffffffd) == 0) goto LAB_1c0003e97;
        if (uVar9 == 0x12) {
          pcVar12 = "ScsiExec> INQUIRY: Page=0x%02X, Len=%d";
          pbVar6 = (byte *)(ulonglong)*(byte *)(param_1 + 0x4a);
          _Src = (void *)0x10;
          uVar7 = tw_msg_req((longlong *)puVar3,0x10,"ScsiExec> INQUIRY: Page=0x%02X, Len=%d",pbVar6
                            );
          goto LAB_1c00040f1;
        }
        bVar13 = uVar9 == 0x15;
        goto LAB_1c00040a8;
      }
LAB_1c000402d:
      pbVar6 = (byte *)tw_xlate_opcode(CONCAT71((int7)(uVar5 >> 8),
                                                *(undefined1 *)((longlong)puVar3 + 0x12)),
                                       CONCAT71(uVar10,*(undefined1 *)((longlong)puVar3 + 0x13)),
                                       *(uint *)((longlong)puVar3 + 0x14),(byte)puVar3[3],
                                       (undefined4 *)((longlong)puVar3 + 0x104));
      pcVar12 = "ScsiExec> %s: Page=0x%02X Len=%u";
      _Src = (void *)0x10;
      uVar7 = tw_msg_req((longlong *)puVar3,0x10,"ScsiExec> %s: Page=0x%02X Len=%u",pbVar6);
      goto LAB_1c00040f1;
    }
    if (uVar9 != 0x1b) {
      if (uVar9 == 0x1e) {
        uVar7 = tw_msg_req((longlong *)puVar3,8,"ScsiExec> Ignore: SCSIOP_MEDIUM_REMOVAL",pbVar6);
        goto LAB_1c000407f;
      }
      if (uVar8 == 0x25) goto LAB_1c00040aa;
      uVar7 = (ulonglong)(bVar2 - 0x28);
      if ((bVar2 - 0x28 & 0xfffffffd) == 0) goto LAB_1c0003e97;
      goto LAB_1c00040f1;
    }
    uVar11 = 1;
    if ((((*(byte *)(param_1 + 0x4c) & 0xf0) == 0) && ((*(byte *)(param_1 + 0x4c) & 1) == 0)) &&
       ((*(byte *)(*puVar3 + 0x292) & 4) != 0)) {
      bVar13 = true;
    }
    else {
      bVar13 = false;
    }
    pbVar6 = (byte *)tw_xlate_opcode((ulonglong)*(byte *)((longlong)puVar3 + 0x12),
                                     CONCAT71(uVar10,*(undefined1 *)((longlong)puVar3 + 0x13)),
                                     *(uint *)((longlong)puVar3 + 0x14),(byte)puVar3[3],
                                     (undefined4 *)((longlong)puVar3 + 0x104));
    pcVar12 = "ScsiExec> %s%s";
    uVar9 = (-(uint)bVar13 & 0xfffffff8) + 0x10;
    _Src = (void *)(ulonglong)uVar9;
    uVar7 = tw_msg_req((longlong *)puVar3,uVar9,"ScsiExec> %s%s",pbVar6);
    if (bVar13) {
LAB_1c000407f:
      return uVar7 & 0xffffffffffffff00;
    }
    if (*(int *)(param_1 + 0x10) == 0) goto LAB_1c0003fee;
  }
  else {
    uVar7 = 0;
    if (uVar9 < 0x92) {
      if ((uVar9 == 0x91) || (uVar5 = (ulonglong)(uVar8 - 0x35), uVar8 - 0x35 == 0)) {
        uVar7 = (ulonglong)tw_cache_control;
        if ((tw_cache_control & 0x20) != 0) goto LAB_1c000407f;
      }
      else {
        uVar5 = (ulonglong)(uVar8 - 0x55);
        if (uVar8 - 0x55 != 0) {
          uVar5 = (ulonglong)(uVar8 - 0x5a);
          if (uVar8 - 0x5a == 0) goto LAB_1c000402d;
          uVar8 = uVar8 - 0x88;
          goto LAB_1c0004096;
        }
      }
    }
    else {
      uVar5 = (ulonglong)(uVar9 - 0x9e);
      if ((uVar9 - 0x9e != 0) && (uVar5 = (ulonglong)(uVar9 - 0xa0), uVar9 - 0xa0 != 0)) {
        uVar8 = uVar9 - 0xa8;
LAB_1c0004096:
        uVar5 = (ulonglong)uVar8;
        if (uVar8 == 0) {
LAB_1c0003e97:
          if ((*(uint *)(*puVar3 + 0x296) & 0x800000) != 0) {
            pbVar6 = (byte *)tw_xlate_opcode(CONCAT71((int7)(uVar5 >> 8),
                                                      *(undefined1 *)((longlong)puVar3 + 0x12)),
                                             CONCAT71(uVar10,*(undefined1 *)
                                                              ((longlong)puVar3 + 0x13)),
                                             *(uint *)((longlong)puVar3 + 0x14),(byte)puVar3[3],
                                             (undefined4 *)((longlong)puVar3 + 0x104));
            pcVar12 = "ScsiExec> %s Len=%u";
            _Src = (void *)0x10;
            tw_msg_req((longlong *)puVar3,0x10,"ScsiExec> %s Len=%u",pbVar6);
          }
          plVar4 = *(longlong **)(param_1 + 0x38);
          if ((char)*(undefined4 *)(param_1 + 0xc) < '\0') {
            pbVar6 = (byte *)(ulonglong)tw_cache_control;
            uVar5 = (ulonglong)pcVar12 >> 8;
            pcVar12 = (char *)((ulonglong)pcVar12 & 0xffffffffffffff00);
            _Src = (void *)plVar4[0x34];
            bVar13 = (tw_cache_control & 2) != 0;
            if (bVar13) {
              pcVar12 = (char *)CONCAT71((int7)uVar5,1);
            }
            if (bVar13 || (tw_cache_control & 1) != 0) {
              *(byte *)((longlong)_Src + 9) =
                   *(byte *)((longlong)_Src + 9) ^
                   (((char)pcVar12 != '\0') << 3 ^ *(byte *)((longlong)_Src + 9)) & 8;
            }
          }
          *(ushort *)((longlong)plVar4 + 0x24) = *(ushort *)((longlong)plVar4 + 0x24) | 0x30;
          uVar5 = tw_sgl_build(plVar4,_Src,pcVar12,pbVar6);
          return uVar5;
        }
        uVar8 = uVar8 - 2;
        uVar5 = (ulonglong)uVar8;
        if (uVar8 == 0) goto LAB_1c0003e97;
        bVar13 = uVar8 == 5;
LAB_1c00040a8:
        if (!bVar13) goto LAB_1c00040f1;
      }
    }
LAB_1c00040aa:
    uVar7 = *puVar3;
    if ((*(byte *)(uVar7 + 0x296) & 0x10) != 0) {
      pbVar6 = (byte *)tw_xlate_opcode(CONCAT71((int7)(uVar5 >> 8),
                                                *(undefined1 *)((longlong)puVar3 + 0x12)),
                                       CONCAT71(uVar10,*(undefined1 *)((longlong)puVar3 + 0x13)),
                                       *(uint *)((longlong)puVar3 + 0x14),(byte)puVar3[3],
                                       (undefined4 *)((longlong)puVar3 + 0x104));
      pcVar12 = "ScsiExec> %s: Len=%u";
      _Src = (void *)0x10;
      uVar7 = tw_msg_req((longlong *)puVar3,0x10,"ScsiExec> %s: Len=%u",pbVar6);
    }
LAB_1c00040f1:
    if (*(int *)(param_1 + 0x10) == 0) {
      uVar11 = 1;
      goto LAB_1c0003fee;
    }
  }
  plVar4 = *(longlong **)(param_1 + 0x38);
  puVar1 = (ushort *)((longlong)plVar4 + 0x24);
  *puVar1 = *puVar1 | 0x30;
  uVar7 = tw_sgl_build(plVar4,_Src,pcVar12,pbVar6);
  uVar11 = (undefined1)uVar7;
LAB_1c0003fee:
  return CONCAT71((int7)(uVar7 >> 8),uVar11);
}



===== FUN_1c0004104 @ 1c0004104 =====

ulonglong FUN_1c0004104(longlong *param_1,longlong param_2,int param_3,ushort *param_4,
                       short *param_5,longlong *param_6)

{
  ushort uVar1;
  undefined4 *puVar2;
  longlong *plVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined1 *puVar9;
  int iStackX_14;
  undefined4 uVar10;
  
  uVar1 = *param_4;
  if (uVar1 < tw_sgls_count) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    uVar8 = 0;
    if ((param_2 != 0) && (param_3 != 0)) {
      if (tw_dma64bit != '\0') {
        plVar3 = (longlong *)*param_6;
        *plVar3 = param_2;
        *(int *)(plVar3 + 1) = param_3;
        *param_6 = (longlong)(plVar3 + 2);
        *param_5 = *param_5 + 0x10;
LAB_1c00041cb:
        *param_4 = uVar1 + 1;
        return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
      }
      if (iStackX_14 == 0) {
        puVar2 = (undefined4 *)*param_6;
        *puVar2 = (int)param_2;
        puVar2[1] = param_3;
        *param_6 = (longlong)(puVar2 + 2);
        *param_5 = *param_5 + 8;
        goto LAB_1c00041cb;
      }
    }
    puVar9 = &s_32;
    if (tw_dma64bit != '\0') {
      puVar9 = &s_64;
    }
    tw_msg_req(param_1,1,"SglEntry> %s: Adr=%08X:%08X Len=%u",puVar9);
    lVar7 = param_1[1];
    if (lVar7 == 0) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      uVar4 = *(undefined1 *)(lVar7 + 7);
      uVar6 = *(undefined1 *)(lVar7 + 6);
      uVar8 = *(undefined1 *)(lVar7 + 5);
    }
    uVar10 = 0x22000014;
  }
  else {
    tw_msg_req(param_1,1,"SglEntry> Number of entries = %d",(ulonglong)(uVar1 + 1));
    lVar7 = param_1[1];
    uVar8 = 0;
    if (lVar7 == 0) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      uVar4 = *(undefined1 *)(lVar7 + 7);
      uVar6 = *(undefined1 *)(lVar7 + 6);
      uVar8 = *(undefined1 *)(lVar7 + 5);
    }
    uVar10 = 0x22000015;
  }
  uVar5 = StorPortLogError(*param_1,lVar7,uVar8,uVar6,uVar4,6,uVar10);
  return uVar5 & 0xffffffffffffff00;
}



===== FUN_1c000426c @ 1c000426c =====

ulonglong FUN_1c000426c(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  longlong lVar2;
  ushort uVar3;
  uint *puVar4;
  byte *pbVar5;
  ulonglong uVar6;
  ushort uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uVar11;
  uint *puVar12;
  bool bVar13;
  ushort local_res8 [4];
  ushort local_res10 [4];
  byte *local_res18 [2];
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar14;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  puVar4 = (uint *)StorPortGetScatterGatherList(*param_1,param_1[1]);
  uVar10 = 0;
  if (((puVar4 == (uint *)0x0) || (uVar11 = *puVar4, uVar11 == 0)) || (tw_sgls_count < uVar11)) {
    tw_msg_req(param_1,1,"BuildSrb> Bad SG List",param_4);
    lVar2 = param_1[1];
    if (lVar2 == 0) {
      uVar8 = 0;
      uVar9 = 0;
    }
    else {
      uVar8 = *(undefined1 *)(lVar2 + 7);
      uVar9 = *(undefined1 *)(lVar2 + 6);
      uVar10 = *(undefined1 *)(lVar2 + 5);
    }
    pbVar5 = (byte *)StorPortLogError(*param_1,lVar2,uVar10,uVar9,uVar8,CONCAT44(uVar14,6),
                                      0x22000013);
LAB_1c00043f0:
    uVar6 = (ulonglong)pbVar5 & 0xffffffffffffff00;
  }
  else {
    pbVar1 = (byte *)param_1[0x34];
    puVar12 = puVar4 + 4;
    local_res8[0] = 0;
    local_res10[0] = 0;
    bVar13 = (*pbVar1 & 0x1f) != 0x10;
    if (bVar13) {
      pbVar5 = (byte *)(ulonglong)pbVar1[1];
      local_res18[0] = pbVar1 + (longlong)pbVar5 * 4;
    }
    else {
      pbVar5 = pbVar1 + 0x18;
      local_res18[0] = pbVar5;
    }
    uVar6 = 0;
    uVar3 = 0;
    uVar7 = 0;
    if (uVar11 != 0) {
      do {
        lVar2 = *(longlong *)puVar12;
        uVar11 = puVar12[2];
        *(uint *)((longlong)param_1 + uVar6 * 4 + 0x80) = uVar11;
        pbVar5 = (byte *)FUN_1c0004104(param_1,lVar2,uVar11,local_res8,(short *)local_res10,
                                       (longlong *)local_res18);
        if ((char)pbVar5 == '\0') goto LAB_1c00043f0;
        uVar11 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar11;
        puVar12 = puVar12 + 6;
      } while (uVar11 < *puVar4);
      uVar3 = local_res8[0];
      uVar7 = local_res10[0];
    }
    *(short *)((longlong)param_1 + 0x34) = *(short *)((longlong)param_1 + 0x34) + uVar3;
    if (bVar13) {
      pbVar1[1] = pbVar1[1] + (char)(uVar7 >> 2);
    }
    else {
      uVar3 = (*(ushort *)(pbVar1 + 6) ^ uVar3) & 0xfff;
      pbVar5 = (byte *)(ulonglong)uVar3;
      *(ushort *)(pbVar1 + 6) = *(ushort *)(pbVar1 + 6) ^ uVar3;
    }
    uVar6 = CONCAT71((int7)((ulonglong)pbVar5 >> 8),1);
  }
  return uVar6;
}



===== FUN_1c0004404 @ 1c0004404 =====

ulonglong FUN_1c0004404(longlong *param_1)

{
  longlong lVar1;
  byte *pbVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  uint *puVar8;
  uint uVar9;
  longlong lVar10;
  bool bVar11;
  ushort local_res8 [4];
  ushort local_res10 [4];
  uint local_res18 [2];
  byte *local_res20;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar12;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  uVar7 = 0;
  lVar1 = param_1[1];
  uVar9 = *(uint *)(param_1 + 6);
  lVar10 = param_1[5];
  if ((uVar9 == 0) || (lVar10 == 0)) {
    tw_msg_req(param_1,1,"BuildSgl> Ptr=%X, Len=%04X",lVar10);
    lVar1 = param_1[1];
    if (lVar1 == 0) {
      uVar5 = 0;
      uVar6 = 0;
    }
    else {
      uVar5 = *(undefined1 *)(lVar1 + 7);
      uVar6 = *(undefined1 *)(lVar1 + 6);
      uVar7 = *(undefined1 *)(lVar1 + 5);
    }
    uVar4 = StorPortLogError(*param_1,lVar1,uVar7,uVar6,uVar5,CONCAT44(uVar12,6),0x22000011);
LAB_1c0004575:
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    pbVar2 = (byte *)param_1[0x34];
    local_res8[0] = 0;
    local_res10[0] = 0;
    bVar11 = (*pbVar2 & 0x1f) != 0x10;
    if (bVar11) {
      local_res20 = pbVar2 + (ulonglong)pbVar2[1] * 4;
    }
    else {
      local_res20 = pbVar2 + 0x18;
    }
    puVar8 = (uint *)(param_1 + 0x10);
    do {
      lVar3 = StorPortGetPhysicalAddress(*param_1,lVar1,lVar10,local_res18);
      if (uVar9 < local_res18[0]) {
        local_res18[0] = uVar9;
      }
      *puVar8 = local_res18[0];
      puVar8 = puVar8 + 1;
      uVar4 = FUN_1c0004104(param_1,lVar3,local_res18[0],local_res8,(short *)local_res10,
                            (longlong *)&local_res20);
      if ((char)uVar4 == '\0') goto LAB_1c0004575;
      lVar10 = lVar10 + (ulonglong)local_res18[0];
      uVar9 = uVar9 - local_res18[0];
    } while (uVar9 != 0);
    *(short *)((longlong)param_1 + 0x34) = *(short *)((longlong)param_1 + 0x34) + local_res8[0];
    if (bVar11) {
      local_res10[0] = local_res10[0] >> 2;
      pbVar2[1] = pbVar2[1] + (char)local_res10[0];
    }
    else {
      local_res10[0] = (local_res8[0] ^ *(ushort *)(pbVar2 + 6)) & 0xfff;
      *(ushort *)(pbVar2 + 6) = *(ushort *)(pbVar2 + 6) ^ local_res10[0];
    }
    uVar4 = CONCAT71((uint7)(byte)(local_res10[0] >> 8),1);
  }
  return uVar4;
}



===== tw_sgl_build @ 1c0004588 =====

ulonglong tw_sgl_build(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  uVar1 = *(ushort *)((longlong)param_1 + 0x24);
  uVar5 = (ulonglong)uVar1;
  if ((uVar1 & 0x10) != 0) {
    plVar6 = param_1;
    if ((uVar1 & 0x20) == 0) {
      uVar5 = FUN_1c0004404(param_1);
      cVar2 = (char)uVar5;
    }
    else {
      uVar3 = FUN_1c000426c(param_1,param_2,param_3,param_4);
      cVar2 = (char)uVar3;
    }
    if (cVar2 == '\0') {
      puVar4 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)plVar6 >> 8),
                                        *(undefined1 *)((longlong)param_1 + 0x12)),
                               CONCAT71((int7)((ulonglong)param_2 >> 8),
                                        *(undefined1 *)((longlong)param_1 + 0x13)),
                               *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                               (undefined4 *)((longlong)param_1 + 0x104));
      tw_msg_req(param_1,1,"ReqBuild> Error building SGL (%s)",puVar4);
      uVar5 = tw_srb_status(param_1[1],'\x04');
      return uVar5 & 0xffffffffffffff00;
    }
    uVar5 = 0xffef;
    *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) & 0xffef;
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== FUN_1c0004610 @ 1c0004610 =====

char * FUN_1c0004610(byte *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  tw_msg_dev(param_1,0x8000,"WMI> QueryResource",param_4);
  *param_3 = L"MofResource";
  return "uildSgl> Ptr=%X, Len=%04X";
}



===== FUN_1c0004640 @ 1c0004640 =====

undefined1 FUN_1c0004640(byte *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  tw_msg_dev(param_1,0x8000,"WMI> QueryDataBlock",param_4);
  ScsiPortWmiPostProcess(param_2);
  return 0;
}



===== FUN_1c0004670 @ 1c0004670 =====

undefined1
FUN_1c0004670(byte *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,char param_5)

{
  char *pcVar1;
  
  if (param_5 == '\0') {
    param_1[0x166f] = 0;
    pcVar1 = "WMI> FunctionControl: Disabled";
  }
  else {
    param_1[0x166f] = 1;
    pcVar1 = "WMI> FunctionControl: Enabled";
  }
  tw_msg_dev(param_1,0x8000,pcVar1,param_4);
  ScsiPortWmiPostProcess(param_2);
  return 1;
}



===== tw_ioctl_claimed @ 1c00046b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong tw_ioctl_claimed(longlong param_1,undefined8 param_2,char *param_3)

{
  char *_Src;
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStack_58 [32];
  undefined1 *local_38;
  undefined1 local_28;
  ulonglong local_27;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar6 = 8;
  plVar4 = *(longlong **)(param_1 + 0x38);
  _Src = (char *)(lVar3 + 4);
  if (_Src == (char *)0x0) {
LAB_1c0004714:
    *(undefined2 *)((longlong)plVar4 + 0x12) = 0x8001;
    *(undefined4 *)((longlong)plVar4 + 0x14) = *(undefined4 *)(lVar3 + 0x10);
    *(undefined4 *)(plVar4 + 6) = *(undefined4 *)(lVar3 + 0x18);
    plVar4[5] = lVar3 + 0x1c;
    tw_request_store(plVar4,param_2,param_3,uVar6);
    local_28 = 0;
    local_27 = 0;
    memcpy(&local_28,_Src,8);
    local_38 = &local_28;
    local_27 = local_27 & 0xffffffffffffff;
    uVar6 = tw_msg_req(plVar4,4,"Ioctl> %08X (\"%s\")",(ulonglong)*(uint *)(lVar3 + 0x10));
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  else {
    param_3 = _Src;
    do {
      cVar2 = *param_3;
      param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),cVar2);
      uVar5 = (int)uVar6 - 1;
      uVar6 = (ulonglong)uVar5;
      pcVar1 = param_3 + ((longlong)&s_<3ware> - (longlong)_Src);
      param_3 = param_3 + 1;
      if (cVar2 != *pcVar1) goto LAB_1c0004714;
    } while (uVar5 != 0);
    uVar6 = CONCAT71((int7)(local_18 >> 8),1);
  }
  return uVar6;
}



===== tw_ioctl_execute @ 1c000479c =====

char tw_ioctl_execute(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  char cVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint local_res8 [2];
  int *local_res10;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar10 = 0;
  plVar3 = *(longlong **)(param_1 + 0x38);
  local_res8[0] = 0;
  uVar1 = *(uint *)(lVar2 + 0x10);
  *(undefined2 *)((longlong)plVar3 + 0x12) = 0x8002;
  *(undefined4 *)((longlong)plVar3 + 0x14) = *(undefined4 *)(lVar2 + 0x10);
  *(undefined4 *)(plVar3 + 6) = *(undefined4 *)(lVar2 + 0x18);
  plVar3[5] = lVar2 + 0x1c;
  *(undefined2 *)((longlong)plVar3 + 0x19) = 0xffff;
  *(undefined4 *)(lVar2 + 0x14) = 0;
  local_res10 = (int *)((ulonglong)*(ushort *)(*plVar3 + 0x2bd) * 0x20 + 0x7e6 + *plVar3);
  LOCK();
  *local_res10 = *local_res10 + 1;
  UNLOCK();
  uVar11 = uVar1 >> 0x10;
  if (uVar11 == 0xf000) {
    tw_request_match(plVar3,param_2,param_3,param_4);
    uVar11 = *(uint *)(lVar2 + 0x18);
    uVar12 = (ulonglong)uVar11;
    if (uVar11 < 0x98) {
      local_res8[0] = 0x98;
      cVar5 = '\0';
    }
    else {
      param_2 = lVar2;
      uVar7 = ioctl_fwpass(plVar3,lVar2,uVar11);
      cVar5 = (char)uVar7;
    }
    tw_request_store(plVar3,param_2,uVar12,param_4);
  }
  else {
    tw_request_store(plVar3,param_2,param_3,param_4);
    if (uVar11 == 0xb000) {
      uVar6 = ioctl_cmdmon(plVar3,lVar2,local_res8,param_4);
      cVar5 = (char)uVar6;
    }
    else if (uVar11 == 0xcc00) {
      uVar6 = ioctl_debug(plVar3,lVar2,local_res8);
      cVar5 = (char)uVar6;
    }
    else if (uVar11 == 0xcc01) {
      uVar6 = ioctl_driver(plVar3,lVar2,local_res8,param_4);
      cVar5 = (char)uVar6;
    }
    else if (uVar11 == 0xcc03) {
      cVar5 = ioctl_stats(plVar3,lVar2,local_res8);
    }
    else if (uVar11 == 0xcc05) {
      cVar5 = ioctl_pendq(plVar3,lVar2,local_res8);
    }
    else if (uVar11 == 0xcc06) {
      cVar5 = ioctl_postq(plVar3,lVar2,local_res8);
    }
    else if (uVar11 == 0xcc10) {
      cVar5 = ioctl_state(plVar3,lVar2);
    }
    else if (uVar11 == 0xe000) {
      cVar5 = ioctl_event(plVar3,lVar2,local_res8);
    }
    else {
      if (uVar11 == 0xffff) {
        lVar4 = *plVar3;
        if ((short)*(undefined4 *)(lVar2 + 0x10) == 6) {
          tw_msg_req(plVar3,0x10000,"FwCon> RESCAN: Request bus change",param_4);
          StorPortNotification(7,lVar4,*(undefined1 *)(plVar3[1] + 5));
        }
        return '\x01';
      }
      uVar6 = ioctl_main(plVar3,lVar2,local_res8,param_4);
      cVar5 = (char)uVar6;
    }
  }
  if (cVar5 == '\0') {
    if (local_res8[0] == 0) {
      if (*(int *)(lVar2 + 0x14) == 0) {
        tw_msg_req(plVar3,1,"Ioctl> Unknown: 0x%X",(ulonglong)uVar1);
        lVar4 = plVar3[1];
        if (lVar4 == 0) {
          uVar8 = 0;
          uVar9 = 0;
        }
        else {
          uVar8 = *(undefined1 *)(lVar4 + 7);
          uVar9 = *(undefined1 *)(lVar4 + 6);
          uVar10 = *(undefined1 *)(lVar4 + 5);
        }
        StorPortLogError(*plVar3,lVar4,uVar10,uVar9,uVar8,6,0x21000001);
        *(undefined2 *)(lVar2 + 0x16) = 0x8001;
      }
    }
    else {
      tw_msg_req(plVar3,1,"Ioctl> Data Length: %u < %u",(ulonglong)*(uint *)(lVar2 + 0x18));
      lVar4 = plVar3[1];
      if (lVar4 == 0) {
        uVar8 = 0;
        uVar9 = 0;
      }
      else {
        uVar8 = *(undefined1 *)(lVar4 + 7);
        uVar9 = *(undefined1 *)(lVar4 + 6);
        uVar10 = *(undefined1 *)(lVar4 + 5);
      }
      StorPortLogError(*plVar3,lVar4,uVar10,uVar9,uVar8,6,0x21000002);
      *(undefined2 *)(lVar2 + 0x16) = 0x8002;
      *(undefined2 *)(lVar2 + 0x14) = (undefined2)local_res8[0];
    }
  }
  return cVar5;
}



===== ioctl_main @ 1c0004aa4 =====

ulonglong ioctl_main(longlong *param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  ulonglong in_RAX;
  char *pcVar5;
  ulonglong uVar6;
  
  pbVar4 = (byte *)*param_1;
  uVar3 = *(uint *)(param_2 + 0x18);
  if (*(int *)(param_2 + 0x10) == 0) {
    in_RAX = tw_msg_req(param_1,0x20000,"IoMain> DRIVER_NOP",param_4);
    if (3 < uVar3) {
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(pbVar4 + 2);
LAB_1c0004c6f:
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
    *param_3 = 4;
  }
  else if (*(int *)(param_2 + 0x10) == 1) {
    in_RAX = tw_msg_req(param_1,0x20000,"IoMain> GET_DRIVER_VERSION",param_4);
    if (0x6b < uVar3) {
      *(undefined4 *)(param_2 + 0x1c) = 0x72617733;
      pcVar5 = &tw_win_version;
      *(undefined2 *)(param_2 + 0x20) = 0x65;
      do {
        cVar1 = *pcVar5;
        pcVar5[param_2 + -0x1c00178e4] = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      *(undefined8 *)(param_2 + 0x5c) = 0x312d7270412d3131;
      *(undefined2 *)(param_2 + 100) = 0x33;
      *(undefined4 *)(param_2 + 0x7c) = 0x10005;
      *(undefined4 *)(param_2 + 0x80) = 0x330000;
      *(undefined4 *)(param_2 + 0x84) = 0x280028;
      tw_msg_req(param_1,0x20000,"IoMain> %s - %s",(undefined4 *)(param_2 + 0x1c));
      uVar6 = (ulonglong)*(ushort *)(param_2 + 0x7c);
      in_RAX = tw_msg_req(param_1,0x20000,"IoMain> Version:%u.%02u.%02u.%03u (%u-%u) %s",uVar6);
      if (0x7f < uVar3) {
        tw_msg_req(param_1,0x20000,"IoMain> GET_DRIVER_VERSION_EX",uVar6);
        *(undefined2 *)(param_2 + 0x88) = 0x72;
        bVar2 = *pbVar4;
        *(ushort *)(param_2 + 0x8a) = (ushort)bVar2;
        *(ushort *)(param_2 + 0x8c) = (ushort)(*(int *)(pbVar4 + 0x232) == 0);
        tw_msg_req(param_1,0x20000,"IoMain> Card Index = %d",(ulonglong)bVar2);
        in_RAX = tw_msg_req(param_1,0x20000,"IoMain> Status Bits = 0x%X",
                            (ulonglong)*(ushort *)(param_2 + 0x8c));
      }
      goto LAB_1c0004c6f;
    }
    *param_3 = 0x6c;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ioctl_driver @ 1c0004c90 =====

ulonglong ioctl_driver(longlong *param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  char *pcVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar3 = (ulonglong)*(uint *)(param_2 + 0x10);
  lVar9 = *param_1;
  if ((short)*(uint *)(param_2 + 0x10) == 0x15) {
    uVar3 = 0x100;
    if (0xff < *(uint *)(param_2 + 0x18)) {
      lVar8 = 2;
      *(undefined2 *)(param_2 + 0x1c) = 0x84;
      puVar6 = (undefined8 *)(lVar9 + 0x48);
      puVar4 = (undefined8 *)(param_2 + 0x1c);
      do {
        uVar5 = puVar6[1];
        *puVar4 = *puVar6;
        puVar4[1] = uVar5;
        uVar5 = puVar6[3];
        puVar4[2] = puVar6[2];
        puVar4[3] = uVar5;
        uVar5 = puVar6[5];
        puVar4[4] = puVar6[4];
        puVar4[5] = uVar5;
        uVar5 = puVar6[7];
        puVar4[6] = puVar6[6];
        puVar4[7] = uVar5;
        uVar5 = puVar6[9];
        puVar4[8] = puVar6[8];
        puVar4[9] = uVar5;
        uVar5 = puVar6[0xb];
        puVar4[10] = puVar6[10];
        puVar4[0xb] = uVar5;
        uVar5 = puVar6[0xd];
        puVar4[0xc] = puVar6[0xc];
        puVar4[0xd] = uVar5;
        puVar1 = puVar6 + 0xe;
        uVar5 = puVar6[0xf];
        puVar6 = puVar6 + 0x10;
        puVar4[0xe] = *puVar1;
        puVar4[0xf] = uVar5;
        lVar8 = lVar8 + -1;
        puVar4 = puVar4 + 0x10;
      } while (lVar8 != 0);
      pcVar7 = (char *)(lVar9 + 0xe);
      lVar9 = (param_2 + 0x59) - (longlong)pcVar7;
      do {
        cVar2 = *pcVar7;
        pcVar7[lVar9] = cVar2;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      tw_msg_req(param_1,0x20000,"IoDrv> GET_FWARE_INFO:",param_4);
      tw_msg_req(param_1,0x20000,"IoDrv> Ver:  %s",param_2 + 0x28);
      tw_msg_req(param_1,0x20000,"IoDrv> Ser:  %s",param_2 + 0x8b);
      tw_msg_req(param_1,0x20000,"IoDrv> Mod:  %s",param_2 + 0x48);
      tw_msg_req(param_1,0x20000,"IoDrv> HwId: %s",param_2 + 0x59);
      uVar5 = tw_msg_req(param_1,0x20000,"IoDrv> ID=%d SRL=%d-%d Branch=%d Build=%d",
                         (ulonglong)*(ushort *)(param_2 + 0x1e));
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
    *param_3 = 0x100;
  }
  return uVar3 & 0xffffffffffffff00;
}



===== ioctl_debug @ 1c0004e04 =====

undefined8 ioctl_debug(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  lVar3 = *param_1;
  uVar2 = *(uint *)(param_2 + 0x18);
  if ((uVar1 & 0xffff) == 0) {
    if (3 < uVar2) {
      pcVar5 = "IoDebug> GET_MSG_CONTROL: 0x%04X";
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(lVar3 + 0x296);
      uVar7 = (ulonglong)*(uint *)(lVar3 + 0x296);
LAB_1c0004eaa:
      uVar4 = tw_msg_req(param_1,0x10000,pcVar5,uVar7);
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  else {
    uVar6 = uVar1 & 0xffff;
    if (uVar6 == 1) {
      if (3 < uVar2) {
        uVar7 = (ulonglong)*(uint *)(param_2 + 0x1c);
        pcVar5 = "IoDebug> SET_MSG_CONTROL: 0x%04X";
        *(uint *)(lVar3 + 0x296) = *(uint *)(param_2 + 0x1c);
        goto LAB_1c0004eaa;
      }
    }
    else if (uVar6 == 2) {
      if (3 < uVar2) {
        pcVar5 = "IoDebug> GET_DBG_CONTROL: 0x%04X";
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(lVar3 + 0x292);
        uVar7 = (ulonglong)*(uint *)(lVar3 + 0x292);
        goto LAB_1c0004eaa;
      }
    }
    else {
      if (uVar6 != 3) goto LAB_1c0004e8e;
      if (3 < uVar2) {
        uVar7 = (ulonglong)*(uint *)(param_2 + 0x1c);
        pcVar5 = "IoDebug> SET_DBG_CONTROL: 0x%04X";
        *(uint *)(lVar3 + 0x292) = *(uint *)(param_2 + 0x1c);
        goto LAB_1c0004eaa;
      }
    }
  }
  *param_3 = 4;
LAB_1c0004e8e:
  return (ulonglong)(uint3)(uVar1 >> 8) << 8;
}



===== ioctl_stats @ 1c0004ebc =====

undefined1 ioctl_stats(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  byte *pbVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  byte *pbVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  pbVar1 = (byte *)*param_1;
  local_58[0] = 0;
  local_50 = 0;
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar9 = 1;
  StorPortNotification(0x1003,pbVar1,2,0,local_38);
  uVar11 = 0;
  StorPortNotification(0x1003,pbVar1,3,0,local_58);
  uVar5 = *(uint *)(param_2 + 0x10) & 0xffff;
  if (uVar5 == 0) {
    tw_msg_req(param_1,0x20000,"IoStats> CLEAR",uVar11);
    memset(pbVar1 + 0x2bf,0,0xc9f);
  }
  else if (uVar5 == 1) {
    puVar10 = &s_IoStats>_SHOW;
    uVar8 = 0x20000;
    tw_msg_req(param_1,0x20000,"IoStats> SHOW",uVar11);
    tw_stats_display(pbVar1,uVar8,puVar10,uVar11);
  }
  else {
    if (uVar5 == 2) {
      tw_msg_req(param_1,0x20000,"IoStats> READ",uVar11);
      if (0xc9e < *(uint *)(param_2 + 0x18)) {
        lVar4 = 0x19;
        puVar2 = (undefined8 *)(param_2 + 0x1c);
        pbVar3 = pbVar1 + 0x2bf;
        do {
          pbVar7 = pbVar3;
          puVar6 = puVar2;
          uVar11 = *(undefined8 *)(pbVar7 + 8);
          *puVar6 = *(undefined8 *)pbVar7;
          puVar6[1] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x18);
          puVar6[2] = *(undefined8 *)(pbVar7 + 0x10);
          puVar6[3] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x28);
          puVar6[4] = *(undefined8 *)(pbVar7 + 0x20);
          puVar6[5] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x38);
          puVar6[6] = *(undefined8 *)(pbVar7 + 0x30);
          puVar6[7] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x48);
          puVar6[8] = *(undefined8 *)(pbVar7 + 0x40);
          puVar6[9] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x58);
          puVar6[10] = *(undefined8 *)(pbVar7 + 0x50);
          puVar6[0xb] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x68);
          puVar6[0xc] = *(undefined8 *)(pbVar7 + 0x60);
          puVar6[0xd] = uVar11;
          uVar11 = *(undefined8 *)(pbVar7 + 0x78);
          puVar6[0xe] = *(undefined8 *)(pbVar7 + 0x70);
          puVar6[0xf] = uVar11;
          lVar4 = lVar4 + -1;
          puVar2 = puVar6 + 0x10;
          pbVar3 = pbVar7 + 0x80;
        } while (lVar4 != 0);
        uVar11 = *(undefined8 *)(pbVar7 + 0x88);
        puVar6[0x10] = *(undefined8 *)(pbVar7 + 0x80);
        puVar6[0x11] = uVar11;
        puVar6[0x12] = *(undefined8 *)(pbVar7 + 0x90);
        *(undefined4 *)(puVar6 + 0x13) = *(undefined4 *)(pbVar7 + 0x98);
        *(undefined2 *)((longlong)puVar6 + 0x9c) = *(undefined2 *)(pbVar7 + 0x9c);
        *(byte *)((longlong)puVar6 + 0x9e) = pbVar7[0x9e];
        goto LAB_1c0005057;
      }
      *param_3 = 0xc9f;
    }
    uVar9 = 0;
  }
LAB_1c0005057:
  StorPortNotification(0x1004,pbVar1,local_58);
  StorPortNotification(0x1004,pbVar1,local_38);
  return uVar9;
}



===== ioctl_pendq @ 1c0005098 =====

undefined1 ioctl_pendq(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar1 = *param_1;
  local_58[0] = 0;
  local_50 = 0;
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar3 = 1;
  StorPortNotification(0x1003,lVar1,2,0,local_38);
  uVar4 = 0;
  StorPortNotification(0x1003,lVar1,3,0,local_58);
  uVar2 = *(uint *)(param_2 + 0x10) & 0xffff;
  if (uVar2 == 1) {
    tw_msg_req(param_1,0x20000,"IoPendQ> SHOW",uVar4);
    FUN_1c000a9fc(lVar1,0,(undefined1 *)0x0,-1);
  }
  else {
    if (uVar2 == 2) {
      tw_msg_req(param_1,0x20000,"IoPendQ> READ",uVar4);
      if (0x107 < *(uint *)(param_2 + 0x18)) {
        memcpy((void *)(param_2 + 0x1c),(void *)(lVar1 + 0x1556),0x108);
        goto LAB_1c0005190;
      }
      *param_3 = 0x108;
    }
    uVar3 = 0;
  }
LAB_1c0005190:
  StorPortNotification(0x1004,lVar1,local_58);
  StorPortNotification(0x1004,lVar1,local_38);
  return uVar3;
}



===== ioctl_postq @ 1c00051d0 =====

undefined1 ioctl_postq(longlong *param_1,longlong param_2,uint *param_3)

{
  byte *pbVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  pbVar1 = (byte *)*param_1;
  local_58[0] = 0;
  local_50 = 0;
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar3 = 1;
  StorPortNotification(0x1003,pbVar1,2,0,local_38);
  uVar4 = 0;
  StorPortNotification(0x1003,pbVar1,3,0,local_58);
  uVar2 = *(uint *)(param_2 + 0x10) & 0xffff;
  if (uVar2 == 1) {
    tw_msg_req(param_1,0x20000,"IoPostQ> SHOW",uVar4);
    tw_request_check(pbVar1,'\x01','\0');
  }
  else {
    if (uVar2 == 2) {
      tw_msg_req(param_1,0x20000,"IoPostQ> READ",uVar4);
      uVar2 = (uint)tw_queue_length * 0x1a8;
      if (uVar2 <= *(uint *)(param_2 + 0x18)) {
        memcpy((void *)(param_2 + 0x1c),*(void **)(pbVar1 + 0x277),(ulonglong)uVar2);
        goto LAB_1c00052cb;
      }
      *param_3 = uVar2;
    }
    uVar3 = 0;
  }
LAB_1c00052cb:
  StorPortNotification(0x1004,pbVar1,local_58);
  StorPortNotification(0x1004,pbVar1,local_38);
  return uVar3;
}



===== ioctl_state @ 1c000530c =====

undefined1 ioctl_state(longlong *param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  pbVar1 = (byte *)*param_1;
  local_38[0] = 0;
  uVar3 = 1;
  local_30 = 0;
  uVar4 = *(uint *)(param_2 + 0x10) & 0xffff;
  local_58[0] = 0;
  local_50 = 0;
  local_28 = 0;
  local_20 = 0;
  local_48 = 0;
  local_40 = 0;
  StorPortNotification(0x1003,pbVar1,2,0,local_38);
  uVar6 = 0;
  StorPortNotification(0x1003,pbVar1,3,0,local_58);
  if (uVar4 == 0) {
    tw_msg_req(param_1,0x10000,"IoState> STOP",uVar6);
    cVar2 = tw_fwstate_exec(pbVar1,0);
    if (cVar2 != '\0') goto LAB_1c000543e;
    pcVar5 = "IoState> STOP failed";
LAB_1c0005428:
    tw_msg_req(param_1,1,pcVar5,uVar6);
    *(undefined2 *)(param_2 + 0x16) = 0x8003;
  }
  else {
    if (uVar4 == 1) {
      tw_msg_req(param_1,0x10000,"IoState> START",uVar6);
      cVar2 = tw_fwstate_exec(pbVar1,1);
      if (cVar2 != '\0') goto LAB_1c000543e;
      pcVar5 = "IoState> START failed";
      goto LAB_1c0005428;
    }
    if (uVar4 == 2) {
      tw_msg_req(param_1,0x10000,"IoState> RESET",uVar6);
      cVar2 = tw_fwstate_exec(pbVar1,2);
      if (cVar2 != '\0') goto LAB_1c000543e;
      pcVar5 = "IoState> RESET failed";
      goto LAB_1c0005428;
    }
  }
  uVar3 = 0;
LAB_1c000543e:
  StorPortNotification(0x1004,pbVar1,local_58);
  StorPortNotification(0x1004,pbVar1,local_38);
  return uVar3;
}



===== tw_ioctl_complete @ 1c0005480 =====

void tw_ioctl_complete(longlong param_1,void *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  void *_Dst;
  void *_Src;
  ushort uVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x38);
  if ((*(byte *)((longlong)plVar1 + 0x24) & 2) != 0) {
    lVar2 = *(longlong *)(param_1 + 0x18);
    _Src = (void *)plVar1[0x34];
    if (param_2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(ushort *)((longlong)param_2 + 0x16);
      memcpy((void *)(lVar2 + 0x1c),param_2,0x80);
    }
    _Dst = (void *)(lVar2 + 0x9c);
    memcpy(_Dst,_Src,(ulonglong)*(ushort *)((longlong)plVar1 + 0x26));
    if (uVar3 != 0) {
      *(ushort *)(lVar2 + 0x14) = uVar3;
      *(undefined2 *)(lVar2 + 0x16) = 0x8006;
      tw_xlate_opcode(CONCAT71((int7)((ulonglong)_Dst >> 8),*(undefined1 *)((longlong)plVar1 + 0x12)
                              ),
                      CONCAT71((int7)((ulonglong)_Src >> 8),*(undefined1 *)((longlong)plVar1 + 0x13)
                              ),*(uint *)((longlong)plVar1 + 0x14),*(byte *)(plVar1 + 3),
                      (undefined4 *)((longlong)plVar1 + 0x104));
      tw_time_msecs();
      tw_msg_req(plVar1,0x80000,"FrmPT> Status=0x%X Msecs=%u %s",(ulonglong)uVar3);
    }
  }
  return;
}



===== ioctl_fwpass @ 1c0005560 =====

ulonglong ioctl_fwpass(longlong *param_1,longlong param_2,uint param_3)

{
  byte bVar1;
  longlong lVar2;
  byte *_Dst;
  ulonglong uVar3;
  undefined4 *puVar4;
  int *piVar5;
  void *_Dst_00;
  ushort *_Src;
  undefined8 uVar6;
  ushort uVar7;
  size_t _Size;
  char *pcVar8;
  uint uVar9;
  
  lVar2 = param_1[1];
  _Dst = (byte *)param_1[0x34];
  _Src = (ushort *)(param_2 + 0x9c);
  if ((*(byte *)_Src & 0x1f) == 0x10) {
    uVar7 = 0x18;
  }
  else {
    uVar7 = (ushort)*(byte *)(param_2 + 0x9d) << 2;
  }
  if (uVar7 == 0) {
    tw_msg_req(param_1,1,"FrmPT> Invalid packet size: %d",0);
LAB_1c00055ca:
    uVar3 = 0x8005;
  }
  else {
    uVar9 = uVar7 + 0x80;
    if (param_3 < uVar9) {
      tw_msg_req(param_1,1,"FrmPT> Invalid packet size: %d > %d",(ulonglong)(uint)uVar7);
      goto LAB_1c00055ca;
    }
    if (uVar9 < 0x98) {
      uVar9 = 0x98;
    }
    memcpy(_Dst,_Src,(ulonglong)uVar7);
    *(ushort *)((longlong)param_1 + 0x26) = uVar7;
    _Dst_00 = (void *)(ulonglong)(uVar9 + 0x1c);
    param_1[5] = (longlong)_Dst_00 + *(longlong *)(lVar2 + 0x18);
    *(uint *)(param_1 + 6) = *(int *)(lVar2 + 0x10) - (uVar9 + 0x1c);
    if ((*(uint *)(param_2 + 0x10) >> 0xf & 1) != 0) {
      *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) | 0x10;
    }
    if ((*_Dst & 0x1f) == 0x10) {
      lVar2 = param_1[0x34];
      *(undefined1 *)((longlong)param_1 + 0x13) = 0x10;
      _Src = (ushort *)(lVar2 + 8);
      *(uint *)((longlong)param_1 + 0x14) = (uint)*(byte *)_Src;
      *(undefined1 *)((longlong)param_1 + 0x19) = *(undefined1 *)(lVar2 + 1);
      *(byte *)((longlong)param_1 + 0x1a) =
           (byte)((ushort)*(undefined2 *)(lVar2 + 2) >> 0xc) |
           (byte)((ushort)*(undefined2 *)(lVar2 + 6) >> 8) & 0xf0;
LAB_1c000572a:
      _Size = 0x10;
LAB_1c000572d:
      _Dst_00 = (void *)((longlong)param_1 + 0x6e);
      memcpy(_Dst_00,_Src,_Size);
    }
    else if ((*_Dst & 0x1f) == 0x11) {
      if (-1 < (char)_Dst[6]) {
        *(undefined1 *)((longlong)param_1 + 0x13) = 0x20;
        _Src = (ushort *)(_Dst + 8);
        _Size = 0xc;
        *(uint *)((longlong)param_1 + 0x14) = (uint)*_Src << 0x10 | (uint)_Dst[0x13];
        *(byte *)((longlong)param_1 + 0x19) = _Dst[3];
        *(undefined1 *)((longlong)param_1 + 0x1a) = 0xff;
        goto LAB_1c000572d;
      }
      if (0x10b < uVar7) {
        *(undefined1 *)((longlong)param_1 + 0x13) = 0x10;
        _Src = (ushort *)(_Dst + 0xc);
        *(uint *)((longlong)param_1 + 0x14) = (uint)(byte)*_Src;
        *(byte *)((longlong)param_1 + 0x19) = _Dst[3];
        *(byte *)((longlong)param_1 + 0x1a) = _Dst[8];
        goto LAB_1c000572a;
      }
      *(undefined1 *)((longlong)param_1 + 0x13) = 0x40;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0x11;
      *(byte *)((longlong)param_1 + 0x19) = _Dst[3];
      *(undefined1 *)((longlong)param_1 + 0x1a) = 0xff;
    }
    else {
      *(undefined1 *)((longlong)param_1 + 0x13) = 0x40;
      *(byte *)((longlong)param_1 + 0x19) = _Dst[3];
      *(undefined1 *)((longlong)param_1 + 0x1a) = 0xff;
      bVar1 = *_Dst;
      if ((byte)((bVar1 & 0x1f) - 0x12) < 2) {
        _Src = (ushort *)param_1[5];
        uVar9 = (uint)*_Src << 0x10 | bVar1 & 0x1f;
        _Dst_00 = (void *)(ulonglong)uVar9;
        *(uint *)((longlong)param_1 + 0x14) = uVar9;
        *(byte *)(param_1 + 3) = (byte)_Src[1];
      }
      else {
        *(uint *)((longlong)param_1 + 0x14) = bVar1 & 0x1f;
      }
    }
    *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) | 6;
    puVar4 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)_Dst_00 >> 8),
                                      *(undefined1 *)((longlong)param_1 + 0x12)),
                             CONCAT71((int7)((ulonglong)_Src >> 8),
                                      *(undefined1 *)((longlong)param_1 + 0x13)),
                             *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                             (undefined4 *)((longlong)param_1 + 0x104));
    pcVar8 = "FrmPT> %s";
    uVar6 = 0x80000;
    tw_msg_req(param_1,0x80000,"FrmPT> %s",puVar4);
    uVar3 = tw_sgl_build(param_1,uVar6,pcVar8,puVar4);
    if ((char)uVar3 == '\0') goto LAB_1c00055d3;
    if (((*_Dst & 0x1f) == 0x10) || (uVar7 < 0x301)) {
      piVar5 = (int *)((ulonglong)*(ushort *)(*param_1 + 0x2bd) * 0x20 + 0x7ea + *param_1);
      LOCK();
      *piVar5 = *piVar5 + 1;
      UNLOCK();
      return CONCAT71((int7)((ulonglong)piVar5 >> 8),1);
    }
    tw_msg_req(param_1,1,"FrmPT> Excessive packet length: %d > %d",(ulonglong)(uint)uVar7);
    uVar3 = 0x8008;
  }
  *(short *)(param_2 + 0x16) = (short)uVar3;
LAB_1c00055d3:
  return uVar3 & 0xffffffffffffff00;
}



===== ioctl_event @ 1c0005814 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 ioctl_event(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 uVar9;
  undefined1 auStack_128 [32];
  undefined4 *local_108;
  uint local_f8;
  uint local_f4;
  undefined4 local_f0 [2];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_d0 [2];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  char *local_a8 [4];
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  uVar1 = *(uint *)(param_2 + 0x10);
  puVar6 = (uint *)(param_2 + 0x1c);
  pbVar2 = (byte *)*param_1;
  uVar9 = 1;
  uVar7 = uVar1 & 0xffff;
  local_f4 = *(uint *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 4) = 1;
  if (((10 < uVar7) || ((0x581U >> (uVar1 & 0x1f) & 1) == 0)) && (local_f4 < 0x80)) {
    *param_3 = 0x80;
    return 0;
  }
  local_c0 = 0;
  local_b8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0[0] = 0;
  local_108 = local_d0;
  local_c8 = 0;
  local_f0[0] = 0;
  local_e8 = 0;
  StorPortNotification(0x1003,pbVar2,2);
  pcVar8 = (char *)0x0;
  local_108 = local_f0;
  StorPortNotification(0x1003,pbVar2,3);
  if (uVar7 < 0xb) {
    local_a8[0] = "CLEAR";
    local_a8[1] = "GET_FIRST";
    local_a8[2] = "GET_LAST";
    local_a8[3] = "GET_NEXT";
    local_88 = "GET_PREV";
    local_80 = "GET_ALL";
    local_78 = "GET_ALL_CLEAR";
    local_70 = "WAIT";
    local_68 = "WAIT_CANCEL";
    local_60 = "AEN_CREATE";
    local_58 = "AEN_RETRIEVE";
    pcVar8 = local_a8[uVar7];
    tw_msg_req(param_1,0x40000,"Event> %s",pcVar8);
  }
  if (uVar7 < 5) {
    if (uVar7 == 4) {
      uVar5 = tw_evtq_get_prev((ulonglong *)(pbVar2 + 0xf5e),puVar6);
      cVar3 = (char)uVar5;
LAB_1c0005bb4:
      if (cVar3 == '\0') {
        tw_msg_req(param_1,0x40000,"Event> No more in queue",pcVar8);
        *(undefined4 *)(param_2 + 0x14) = 1;
        goto LAB_1c0005c0d;
      }
      *(int *)(pbVar2 + 0x2e4) = *(int *)(pbVar2 + 0x2e4) + 1;
      goto LAB_1c0005bda;
    }
    if (uVar7 != 0) {
      if (uVar7 == 1) {
        uVar5 = tw_evtq_get_first((ulonglong *)(pbVar2 + 0xf5e),puVar6);
        cVar3 = (char)uVar5;
      }
      else if (uVar7 == 2) {
        uVar5 = tw_evtq_get_last((ulonglong *)(pbVar2 + 0xf5e),puVar6);
        cVar3 = (char)uVar5;
      }
      else {
        if (uVar7 != 3) goto LAB_1c0005a9c;
        uVar5 = tw_evtq_get_next((ulonglong *)(pbVar2 + 0xf5e),puVar6);
        cVar3 = (char)uVar5;
      }
      goto LAB_1c0005bb4;
    }
    if (*(int *)(pbVar2 + 0xf66) << 7 != 0) {
      memset(*(void **)(pbVar2 + 0xf5e),0,(ulonglong)(uint)(*(int *)(pbVar2 + 0xf66) << 7));
    }
    pbVar2[0xf76] = 0;
    pbVar2[0xf77] = 0;
    pbVar2[0xf78] = 0;
    pbVar2[0xf79] = 0;
    *(undefined4 *)(pbVar2 + 0xf6a) = *(undefined4 *)(pbVar2 + 0xf6e);
  }
  else {
    if (uVar7 < 7) {
      local_f8 = 0;
      while( true ) {
        if (local_f8 == 0) {
          uVar5 = tw_evtq_get_first((ulonglong *)(pbVar2 + 0xf5e),puVar6);
          cVar3 = (char)uVar5;
        }
        else {
          uVar5 = tw_evtq_get_next((ulonglong *)(pbVar2 + 0xf5e),puVar6);
          cVar3 = (char)uVar5;
        }
        uVar1 = *puVar6;
        if (uVar1 == 0) goto LAB_1c0005b50;
        local_f8 = local_f8 + 1;
        local_f4 = local_f4 - 0x80;
        if (local_f4 < 0x80) break;
        puVar6 = puVar6 + 0x20;
        *puVar6 = uVar1;
      }
      if (cVar3 != '\0') {
        *(undefined4 *)(param_2 + 0x14) = 6;
        tw_msg_req(param_1,0x40000,"Event> More in queue",pcVar8);
      }
LAB_1c0005b50:
      if (uVar7 == 6) {
        if (*(int *)(pbVar2 + 0xf66) << 7 != 0) {
          memset(*(void **)(pbVar2 + 0xf5e),0,(ulonglong)(uint)(*(int *)(pbVar2 + 0xf66) << 7));
        }
        pbVar2[0xf76] = 0;
        pbVar2[0xf77] = 0;
        pbVar2[0xf78] = 0;
        pbVar2[0xf79] = 0;
        *(undefined4 *)(pbVar2 + 0xf6a) = *(undefined4 *)(pbVar2 + 0xf6e);
        pbVar2[0xf7a] = 0;
      }
      pcVar8 = (char *)(ulonglong)local_f8;
      local_108 = (undefined4 *)CONCAT44(local_108._4_4_,*(undefined4 *)(pbVar2 + 0xf76));
      tw_msg_req(param_1,0x40000,"Event> Retrieved %d (%d total)",pcVar8);
      if (uVar7 == 0) goto LAB_1c0005c0d;
      goto LAB_1c0005bb4;
    }
    if (uVar7 != 7) {
      if (uVar7 == 8) {
        iVar4 = tw_pendio_cancel((longlong)pbVar2,1);
        if (iVar4 == 0) {
          *(undefined4 *)(param_2 + 0x14) = 5;
        }
        goto LAB_1c0005c0d;
      }
      if (uVar7 == 10) {
        tw_msg_dev(pbVar2,4,"Event> Triggering AEN retrieval...",pcVar8);
        if (*(int *)(*(longlong *)(pbVar2 + 0x25f) + 0x44) == 0) {
          *(undefined4 *)(*(longlong *)(pbVar2 + 0x25f) + 0x44) = 1;
          tw_dpc_call(pbVar2,"IOC");
        }
        else {
          tw_msg_dev(pbVar2,0x800,"%s> Currently processing AENs","IOC");
        }
        goto LAB_1c0005c0d;
      }
LAB_1c0005a9c:
      uVar9 = 0;
      *(undefined2 *)(param_2 + 0x16) = 0x8007;
      goto LAB_1c0005c0d;
    }
    *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) | 0x4000;
LAB_1c0005bda:
    if (pbVar2[0xf7a] == 0) goto LAB_1c0005c0d;
    *(int *)(pbVar2 + 0x2e8) = *(int *)(pbVar2 + 0x2e8) + 1;
    tw_msg_req(param_1,0x40000,"Event> Queue overflow",pcVar8);
    *(undefined4 *)(param_2 + 0x14) = 2;
  }
  pbVar2[0xf7a] = 0;
LAB_1c0005c0d:
  StorPortNotification(0x1004,pbVar2,local_f0);
  StorPortNotification(0x1004,pbVar2,local_d0);
  return uVar9;
}



===== FUN_1c0005c5c @ 1c0005c5c =====

bool FUN_1c0005c5c(byte *param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_2 + 9) == '\0';
  if (bVar1) {
    tw_msg_dev(param_1,0x10000,"CmdMon> Command monitoring is disabled",param_4);
    *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 1;
  }
  return bVar1;
}



===== ioctl_cmdmon @ 1c0005c8c =====

undefined8 ioctl_cmdmon(longlong *param_1,longlong param_2,uint *param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 auVar5 [16];
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined7 extraout_var;
  void *pvVar10;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  longlong lVar11;
  byte *pbVar12;
  undefined7 extraout_var_04;
  undefined7 extraout_var_05;
  undefined7 extraout_var_06;
  undefined7 extraout_var_07;
  undefined7 extraout_var_08;
  undefined7 extraout_var_09;
  undefined7 extraout_var_10;
  undefined7 extraout_var_11;
  void *_Dst;
  uint uVar13;
  undefined8 *puVar14;
  char *pcVar15;
  char *pcVar16;
  size_t _Size;
  undefined8 uVar17;
  ulonglong uVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  char *local_res8;
  uint local_res10;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pbVar12 = (byte *)*param_1;
  uVar13 = *(uint *)(param_2 + 0x10);
  pvVar10 = (void *)(ulonglong)uVar13;
  uVar4 = *(uint *)(param_2 + 0x18);
  local_res8 = (char *)CONCAT44(local_res8._4_4_,uVar4);
  pbVar2 = pbVar12 + 0xf7e;
  uVar19 = uVar13 & 0xff;
  if (0xb < uVar19) {
    if (uVar19 == 0xc) {
      bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
      pvVar10 = (void *)CONCAT71(extraout_var_11,bVar6);
      if (bVar6) goto LAB_1c0006bc2;
      pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_POST",param_4);
      if ((uint)local_res8 < 0x74) {
LAB_1c0006b5c:
        *param_3 = 0x74;
        goto LAB_1c0006771;
      }
      uVar17 = *(undefined8 *)(pbVar12 + 0x13f2);
      *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x13ea);
      *(undefined8 *)(param_2 + 0x24) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1402);
      *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x13fa);
      *(undefined8 *)(param_2 + 0x34) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1412);
      *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x140a);
      *(undefined8 *)(param_2 + 0x44) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1422);
      *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(pbVar12 + 0x141a);
      *(undefined8 *)(param_2 + 0x54) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1432);
      *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(pbVar12 + 0x142a);
      *(undefined8 *)(param_2 + 100) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1442);
      *(undefined8 *)(param_2 + 0x6c) = *(undefined8 *)(pbVar12 + 0x143a);
      *(undefined8 *)(param_2 + 0x74) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1452);
      *(undefined8 *)(param_2 + 0x7c) = *(undefined8 *)(pbVar12 + 0x144a);
      *(undefined8 *)(param_2 + 0x84) = uVar17;
      uVar13 = *(uint *)(pbVar12 + 0x145a);
    }
    else {
      if (uVar19 == 0xd) {
        bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
        pvVar10 = (void *)CONCAT71(extraout_var_10,bVar6);
        if (!bVar6) {
          pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_SGLS",param_4);
          if ((uint)local_res8 < 0x50) {
            *param_3 = 0x50;
            goto LAB_1c0006771;
          }
          uVar17 = *(undefined8 *)(pbVar12 + 0x1466);
          *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x145e);
          *(undefined8 *)(param_2 + 0x24) = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x1476);
          *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x146e);
          *(undefined8 *)(param_2 + 0x34) = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x1486);
          *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x147e);
          *(undefined8 *)(param_2 + 0x44) = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x1496);
          *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(pbVar12 + 0x148e);
          *(undefined8 *)(param_2 + 0x54) = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x14a6);
          *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(pbVar12 + 0x149e);
          *(undefined8 *)(param_2 + 100) = uVar17;
        }
        goto LAB_1c0006bc2;
      }
      if (uVar19 != 0xe) {
        if (uVar19 == 0xf) {
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_08,bVar6);
          if (!bVar6) {
            pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_ELEN",param_4);
            if ((uint)local_res8 < 0x18) {
              *param_3 = 0x18;
              goto LAB_1c0006771;
            }
            uVar17 = *(undefined8 *)(pbVar12 + 0x152a);
            *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x1522);
            *(undefined8 *)(param_2 + 0x24) = uVar17;
            *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x1532);
          }
        }
        else if (uVar19 == 0x14) {
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_07,bVar6);
          if (!bVar6) {
            pcVar15 = "CmdMon> LOG_CMDS";
            uVar17 = 0x10000;
            tw_msg_dev(pbVar12,0x10000,"CmdMon> LOG_CMDS",param_4);
            pvVar10 = (void *)cm_cmds_log((longlong *)pbVar2,uVar17,pcVar15,param_4);
          }
        }
        else if (uVar19 == 0x15) {
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_06,bVar6);
          uVar13 = 0;
          if ((!bVar6) &&
             (pvVar10 = (void *)tw_msg_dev(pbVar12,0x10000,"CmdMon> LOG_LCTS",param_4),
             *(short *)(pbVar12 + 0x1194) != 0)) {
            lVar11 = 0;
            do {
              if ((*(byte *)(lVar11 + *(longlong *)(pbVar12 + 0x11a6)) & 0x11) == 0x11) {
                cm_log_out((longlong *)pbVar2,
                           (byte *)((longlong)(int)uVar13 * 0x2c + *(longlong *)(pbVar12 + 0x11a6)),
                           uVar13,param_4,' ');
              }
              pvVar10 = (void *)(ulonglong)*(ushort *)(pbVar12 + 0x1194);
              uVar13 = uVar13 + 1;
              lVar11 = lVar11 + 0x2c;
            } while ((int)uVar13 < (int)(uint)*(ushort *)(pbVar12 + 0x1194));
          }
        }
        else {
          if (uVar19 != 0x16) goto LAB_1c0006771;
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_05,bVar6);
          if (!bVar6) {
            tw_msg_dev(pbVar12,0x10000,"CmdMon> LOG_AVES",param_4);
            pvVar10 = (void *)cm_aves_log((undefined8 *)pbVar2);
          }
        }
        goto LAB_1c0006bc2;
      }
      bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
      pvVar10 = (void *)CONCAT71(extraout_var_09,bVar6);
      if (bVar6) goto LAB_1c0006bc2;
      pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_XLEN",param_4);
      if ((uint)local_res8 < 0x74) goto LAB_1c0006b5c;
      uVar17 = *(undefined8 *)(pbVar12 + 0x14b6);
      *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x14ae);
      *(undefined8 *)(param_2 + 0x24) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x14c6);
      *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x14be);
      *(undefined8 *)(param_2 + 0x34) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x14d6);
      *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x14ce);
      *(undefined8 *)(param_2 + 0x44) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x14e6);
      *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(pbVar12 + 0x14de);
      *(undefined8 *)(param_2 + 0x54) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x14f6);
      *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(pbVar12 + 0x14ee);
      *(undefined8 *)(param_2 + 100) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1506);
      *(undefined8 *)(param_2 + 0x6c) = *(undefined8 *)(pbVar12 + 0x14fe);
      *(undefined8 *)(param_2 + 0x74) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x1516);
      *(undefined8 *)(param_2 + 0x7c) = *(undefined8 *)(pbVar12 + 0x150e);
      *(undefined8 *)(param_2 + 0x84) = uVar17;
      uVar13 = *(uint *)(pbVar12 + 0x151e);
    }
    pvVar10 = (void *)(ulonglong)uVar13;
    *(uint *)(param_2 + 0x8c) = uVar13;
    goto LAB_1c0006bc2;
  }
  if (uVar19 == 0xb) {
    bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
    pvVar10 = (void *)CONCAT71(extraout_var_04,bVar6);
    if (bVar6) goto LAB_1c0006bc2;
    tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_RESP",param_4);
    pvVar10 = (void *)0xb8;
    if (0xb7 < (uint)local_res8) {
      uVar17 = *(undefined8 *)(pbVar12 + 0x133a);
      *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x1332);
      *(undefined8 *)(param_2 + 0x24) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x134a);
      *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x1342);
      *(undefined8 *)(param_2 + 0x34) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x135a);
      *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x1352);
      *(undefined8 *)(param_2 + 0x44) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x136a);
      *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(pbVar12 + 0x1362);
      *(undefined8 *)(param_2 + 0x54) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x137a);
      *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(pbVar12 + 0x1372);
      *(undefined8 *)(param_2 + 100) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x138a);
      *(undefined8 *)(param_2 + 0x6c) = *(undefined8 *)(pbVar12 + 0x1382);
      *(undefined8 *)(param_2 + 0x74) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x139a);
      *(undefined8 *)(param_2 + 0x7c) = *(undefined8 *)(pbVar12 + 0x1392);
      *(undefined8 *)(param_2 + 0x84) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x13aa);
      *(undefined8 *)(param_2 + 0x8c) = *(undefined8 *)(pbVar12 + 0x13a2);
      *(undefined8 *)(param_2 + 0x94) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x13ba);
      *(undefined8 *)(param_2 + 0x9c) = *(undefined8 *)(pbVar12 + 0x13b2);
      *(undefined8 *)(param_2 + 0xa4) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x13ca);
      *(undefined8 *)(param_2 + 0xac) = *(undefined8 *)(pbVar12 + 0x13c2);
      *(undefined8 *)(param_2 + 0xb4) = uVar17;
      uVar17 = *(undefined8 *)(pbVar12 + 0x13da);
      *(undefined8 *)(param_2 + 0xbc) = *(undefined8 *)(pbVar12 + 0x13d2);
      *(undefined8 *)(param_2 + 0xc4) = uVar17;
      pvVar10 = *(void **)(pbVar12 + 0x13e2);
      *(void **)(param_2 + 0xcc) = pvVar10;
      goto LAB_1c0006bc2;
    }
  }
  else {
    uVar13 = uVar13 & 0xff;
    if (uVar13 == 1) {
      pvVar10 = (void *)tw_msg_dev(pbVar12,0x10000,"CmdMon> GET_CONFIG",param_4);
      if (uVar4 < 0x1c) {
        *param_3 = 0x1c;
        goto LAB_1c0006771;
      }
      *(undefined1 *)(param_2 + 0x1c) = 9;
      *(undefined2 *)(param_2 + 0x20) = 0x400;
      *(undefined2 *)(param_2 + 0x22) = *(undefined2 *)(pbVar12 + 0x1192);
      *(undefined2 *)(param_2 + 0x24) = *(undefined2 *)(pbVar12 + 0x1194);
      *(undefined2 *)(param_2 + 0x26) = *(undefined2 *)(pbVar12 + 0x1196);
      *(undefined4 *)(param_2 + 0x28) = 0xf1f7ff;
      uVar9 = *(undefined4 *)(param_2 + 0x28);
      if (pbVar12[0xf86] != 0) {
        uVar9 = 0x7f1f7ff;
      }
      bVar6 = tw_cmon_cmdsize == 0x2c;
      *(undefined4 *)(param_2 + 0x28) = uVar9;
      if (bVar6) {
        *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | 0x8000000;
      }
      pvVar10 = (void *)(ulonglong)tw_bootup_time;
      *(uint *)(param_2 + 0x34) = tw_bootup_time;
      *(undefined4 *)(param_2 + 0x2c) = 1000000;
      *(undefined4 *)(param_2 + 0x30) = 0xf;
      goto LAB_1c0006bc2;
    }
    if (uVar13 == 2) {
      tw_msg_dev(pbVar12,0x10000,"CmdMon> GET_CONTROL",param_4);
      pvVar10 = (void *)0x200;
      if (0x1ff < uVar4) {
        if (pbVar12[0xf87] == 0) {
          pbVar12[0xf9a] = 0;
        }
        else {
          pbVar12[0xf9a] = pbVar12[0x11b6];
        }
        lVar11 = 4;
        *(undefined2 *)(pbVar12 + 0xf9e) = *(undefined2 *)(pbVar12 + 0x11c2);
        *(undefined2 *)(pbVar12 + 4000) = *(undefined2 *)(pbVar12 + 0x11c6);
        *(undefined2 *)(pbVar12 + 0xfa2) = *(undefined2 *)(pbVar12 + 0x11c8);
        pbVar12 = pbVar12 + 0xf92;
        puVar14 = (undefined8 *)(param_2 + 0x1c);
        do {
          uVar17 = *(undefined8 *)(pbVar12 + 8);
          *puVar14 = *(undefined8 *)pbVar12;
          puVar14[1] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x18);
          puVar14[2] = *(undefined8 *)(pbVar12 + 0x10);
          puVar14[3] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x28);
          puVar14[4] = *(undefined8 *)(pbVar12 + 0x20);
          puVar14[5] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x38);
          puVar14[6] = *(undefined8 *)(pbVar12 + 0x30);
          puVar14[7] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x48);
          puVar14[8] = *(undefined8 *)(pbVar12 + 0x40);
          puVar14[9] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x58);
          puVar14[10] = *(undefined8 *)(pbVar12 + 0x50);
          puVar14[0xb] = uVar17;
          uVar17 = *(undefined8 *)(pbVar12 + 0x68);
          puVar14[0xc] = *(undefined8 *)(pbVar12 + 0x60);
          puVar14[0xd] = uVar17;
          pbVar1 = pbVar12 + 0x70;
          uVar17 = *(undefined8 *)(pbVar12 + 0x78);
          pbVar12 = pbVar12 + 0x80;
          puVar14[0xe] = *(undefined8 *)pbVar1;
          puVar14[0xf] = uVar17;
          lVar11 = lVar11 + -1;
          puVar14 = puVar14 + 0x10;
        } while (lVar11 != 0);
        pvVar10 = (void *)cm_setup_log((undefined8 *)pbVar2,'\0',"CmControl");
        goto LAB_1c0006bc2;
      }
    }
    else if (uVar13 == 3) {
      tw_msg_dev(pbVar12,0x10000,"CmdMon> SET_CONTROL",param_4);
      pvVar10 = (void *)0x200;
      if (0x1ff < (uint)local_res8) {
        pvVar10 = (void *)(ulonglong)*(ushort *)(pbVar12 + 0x1194);
        if (*(ushort *)(pbVar12 + 0x1194) < *(ushort *)(param_2 + 0x2a)) {
          *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 2;
          goto LAB_1c0006bc2;
        }
LAB_1c0006142:
        local_58[0] = 0;
        local_48 = 0;
        local_40 = 0;
        local_68 = 0;
        local_60 = 0;
        local_50 = 0;
        local_78[0] = 0;
        local_70 = 0;
        StorPortNotification(0x1003,pbVar12,2,0,local_58);
        pcVar15 = (char *)0x0;
        uVar17 = 3;
        StorPortNotification(0x1003,pbVar12,3,0,local_78);
        if (uVar13 == 3) {
          if (*(ushort *)(param_2 + 0x28) == 0) {
            *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(pbVar12 + 0x1192);
          }
          else if (*(ushort *)(param_2 + 0x28) < 0x400) {
            *(undefined2 *)(param_2 + 0x28) = 0x400;
          }
          if (*(short *)(param_2 + 0x2a) == 0) {
            *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(pbVar12 + 0x1194);
          }
          if (*(short *)(param_2 + 0x2c) == 0) {
            *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(pbVar12 + 0x1196);
          }
          if ((*(byte *)(param_2 + 0x22) & 0xfe) != 0) {
            *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 1;
          }
          if (*(char *)(param_2 + 0x24) == '\0') {
            uVar17 = 0x80;
            *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x80;
          }
          else {
            if ((*(ushort *)(param_2 + 0x22) & 0x4000) == 0) {
              if ((*(ushort *)(param_2 + 0x22) & 0x8000) != 0) {
                *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 8;
              }
            }
            else {
              *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 2;
            }
            if ((*(byte *)(param_2 + 0x31) & 0x10) != 0) {
              *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 4;
            }
          }
          if ((*(char *)(param_2 + 0x24) == '\0') || ((*(ushort *)(param_2 + 0x22) & 0x8000) == 0))
          {
LAB_1c0006633:
            if ((pbVar12[0xf87] == 0) && (*(char *)(param_2 + 0x24) != '\0')) {
              pbVar12[0xf87] = 1;
              cm_req_start(pbVar2,param_1,uVar17,pcVar15);
            }
            cm_ctrl_setup((undefined8 *)pbVar2,(uint *)(param_2 + 0x1c),uVar17,pcVar15);
          }
          else {
            bVar6 = *(short *)(param_2 + 0x28) != *(short *)(pbVar12 + 0x1192);
            bVar20 = *(short *)(param_2 + 0x2a) != *(short *)(pbVar12 + 0x1194);
            local_res8 = (char *)CONCAT71(local_res8._1_7_,bVar6);
            bVar21 = *(short *)(param_2 + 0x2c) != *(short *)(pbVar12 + 0x1196);
            local_res10 = CONCAT31(local_res10._1_3_,bVar20);
            uVar17 = CONCAT71((int7)((ulonglong)uVar17 >> 8),bVar21);
            if (pbVar12[0xf86] == 0) {
              if (*(int *)(*(longlong *)pbVar2 + 0x2a0) == 0) {
                if ((bVar21 || bVar20) || bVar6) {
                  pbVar12[0xf87] = 0;
                  StorPortNotification(0x1004,pbVar12,local_78);
                  StorPortNotification(0x1004,pbVar12,local_58);
                  if ((char)local_res8 != '\0') {
                    pcVar15 = "CmdMon> Resize CMD  array: %d => %d entries";
                    uVar18 = (ulonglong)*(ushort *)(pbVar12 + 0x1192);
                    tw_msg_dev(pbVar12,4,"CmdMon> Resize CMD  array: %d => %d entries",uVar18);
                    uVar9 = tw_memory_free(pbVar12,*(undefined8 *)(pbVar12 + 0x119e),pcVar15,uVar18)
                    ;
                    if ((char)uVar9 == '\0') {
                      *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(pbVar12 + 0x1192);
                    }
                    else {
                      pbVar12[0x119e] = 0;
                      pbVar12[0x119f] = 0;
                      pbVar12[0x11a0] = 0;
                      pbVar12[0x11a1] = 0;
                      pbVar12[0x11a2] = 0;
                      pbVar12[0x11a3] = 0;
                      pbVar12[0x11a4] = 0;
                      pbVar12[0x11a5] = 0;
                      local_res8 = (char *)CONCAT44(local_res8._4_4_,
                                                    *(ushort *)(param_2 + 0x28) * tw_cmon_cmdsize);
                      lVar11 = tw_memory_resize(pbVar12,(uint *)&local_res8,0x400);
                      if (lVar11 == 0) {
                        *(undefined2 *)(param_2 + 0x28) = 0;
                        tw_msg_dev(pbVar12,1,"CmdMon> Failed to resize CMD array",uVar18);
                      }
                      else {
                        *(longlong *)(pbVar12 + 0x119e) = lVar11;
                        *(undefined2 *)(pbVar12 + 0x1192) = *(undefined2 *)(param_2 + 0x28);
                        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x40;
                      }
                    }
                    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 2;
                  }
                  if ((char)local_res10 != '\0') {
                    pcVar15 = "CmdMon> Resize LCT array: %d => %d entries";
                    uVar18 = (ulonglong)*(ushort *)(pbVar12 + 0x1194);
                    tw_msg_dev(pbVar12,4,"CmdMon> Resize LCT array: %d => %d entries",uVar18);
                    uVar9 = tw_memory_free(pbVar12,*(undefined8 *)(pbVar12 + 0x11a6),pcVar15,uVar18)
                    ;
                    if ((char)uVar9 == '\0') {
                      *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(pbVar12 + 0x1194);
                    }
                    else {
                      pbVar12[0x11a6] = 0;
                      pbVar12[0x11a7] = 0;
                      pbVar12[0x11a8] = 0;
                      pbVar12[0x11a9] = 0;
                      pbVar12[0x11aa] = 0;
                      pbVar12[0x11ab] = 0;
                      pbVar12[0x11ac] = 0;
                      pbVar12[0x11ad] = 0;
                      local_res8 = (char *)CONCAT44(local_res8._4_4_,
                                                    (uint)*(ushort *)(param_2 + 0x2a) * 0x2c);
                      lVar11 = tw_memory_resize(pbVar12,(uint *)&local_res8,0x32);
                      if (lVar11 == 0) {
                        *(undefined2 *)(param_2 + 0x2a) = 0;
                        tw_msg_dev(pbVar12,1,"CmdMon> Failed to resize LCT array",uVar18);
                      }
                      else {
                        *(longlong *)(pbVar12 + 0x11a6) = lVar11;
                        *(undefined2 *)(pbVar12 + 0x1194) = *(undefined2 *)(param_2 + 0x2a);
                        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x40;
                      }
                    }
                    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 4;
                  }
                  if (bVar21) {
                    pcVar15 = "CmdMon> Resize AVES array: %d => %d entries";
                    uVar18 = (ulonglong)*(ushort *)(pbVar12 + 0x1196);
                    tw_msg_dev(pbVar12,4,"CmdMon> Resize AVES array: %d => %d entries",uVar18);
                    uVar9 = tw_memory_free(pbVar12,*(undefined8 *)(pbVar12 + 0x11ae),pcVar15,uVar18)
                    ;
                    if ((char)uVar9 == '\0') {
                      *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(pbVar12 + 0x1196);
                    }
                    else {
                      pbVar12[0x11ae] = 0;
                      pbVar12[0x11af] = 0;
                      pbVar12[0x11b0] = 0;
                      pbVar12[0x11b1] = 0;
                      pbVar12[0x11b2] = 0;
                      pbVar12[0x11b3] = 0;
                      pbVar12[0x11b4] = 0;
                      pbVar12[0x11b5] = 0;
                      local_res8 = (char *)CONCAT44(local_res8._4_4_,
                                                    (uint)*(ushort *)(param_2 + 0x2c) * 0x2c);
                      lVar11 = tw_memory_resize(pbVar12,(uint *)&local_res8,200);
                      if (lVar11 == 0) {
                        *(undefined2 *)(param_2 + 0x2c) = 0;
                        tw_msg_dev(pbVar12,1,"CmdMon> Failed to resize AVE array",uVar18);
                      }
                      else {
                        *(longlong *)(pbVar12 + 0x11ae) = lVar11;
                        *(undefined2 *)(pbVar12 + 0x1196) = *(undefined2 *)(param_2 + 0x2c);
                        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x40;
                      }
                    }
                    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 4;
                  }
                  StorPortNotification(0x1003,pbVar12,2,0,local_58);
                  pcVar15 = (char *)0x0;
                  uVar17 = 3;
                  StorPortNotification(0x1003,pbVar12,3,0,local_78);
                  pbVar12[0xf87] = 1;
                }
                goto LAB_1c0006633;
              }
              *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 4;
            }
            else {
              *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 8;
            }
          }
        }
        else {
          if (uVar13 == 4) {
            pbVar12[0x153a] = 0;
          }
          iVar8 = tw_pendio_cancel((longlong)pbVar12,(int)param_1[4]);
          if (iVar8 == 0) {
            *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x80;
          }
        }
        StorPortNotification(0x1004,pbVar12,local_78);
        pvVar10 = (void *)StorPortNotification(0x1004,pbVar12,local_58);
LAB_1c0006bc2:
        return CONCAT71((int7)((ulonglong)pvVar10 >> 8),1);
      }
    }
    else {
      if (uVar13 != 4) {
        if (uVar13 == 5) {
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_02,bVar6);
          if (bVar6) goto LAB_1c0006bc2;
          *(undefined4 *)(param_1 + 4) = 4;
          *(undefined1 *)(param_1 + 3) = 0;
          uVar4 = *(uint *)(param_2 + 0x10);
          if ((uVar4 & 0x4000) != 0) {
            pcVar15 = "CmdMon> GET_LCTS: Cancel";
            goto LAB_1c0006138;
          }
          uVar13 = (uint)local_res8;
          local_res10 = CONCAT31((uint3)(uVar4 >> 0x17),(char)(uVar4 >> 0xf)) & 0xffffff01;
          pcVar15 = (char *)(((ulonglong)local_res8 & 0xffffffff) / 0x2c);
          local_res8 = pcVar15;
          pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_LCTS count=%d%s",pcVar15);
          if (uVar13 < 0x2c) {
            *param_3 = 0x2c;
            goto LAB_1c0006771;
          }
          if ((char)local_res10 == '\0') {
            uVar3 = *(ushort *)(pbVar12 + 0x11c6);
            if (uVar3 != 0) {
              pvVar10 = *(void **)(pbVar12 + 0x11a6);
              uVar13 = (uint)local_res8;
              if ((int)(uint)uVar3 < (int)(uint)local_res8) {
                uVar13 = (uint)uVar3;
              }
              _Dst = (void *)(param_2 + 0x1c);
              _Size = (longlong)(int)uVar13 * 0x2c;
LAB_1c0006005:
              pvVar10 = memcpy(_Dst,pvVar10,_Size);
              goto LAB_1c0006bc2;
            }
            pcVar16 = "CmdMon> No LCT data, and not waiting";
            goto LAB_1c0005e40;
          }
        }
        else if (uVar13 == 6) {
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_01,bVar6);
          if (bVar6) goto LAB_1c0006bc2;
          *(undefined4 *)(param_1 + 4) = 5;
          *(undefined1 *)(param_1 + 3) = 0;
          uVar4 = *(uint *)(param_2 + 0x10);
          if ((uVar4 & 0x4000) != 0) {
            pcVar15 = "CmdMon> GET_AVES: Cancel";
            goto LAB_1c0006138;
          }
          uVar13 = (uint)local_res8;
          auVar5._8_8_ = 0;
          auVar5._0_8_ = (ulonglong)local_res8 & 0xffffffff;
          lVar11 = SUB168(ZEXT816(0xa41a41a41a41a41b) * auVar5,8);
          local_res10 = CONCAT31((uint3)(uVar4 >> 0x17),(char)(uVar4 >> 0xf)) & 0xffffff01;
          local_res8 = (char *)((((ulonglong)local_res8 & 0xffffffff) - lVar11 >> 1) + lVar11 >> 7);
          pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_AVES%s",
                                       (ulonglong)local_res8 & 0xffffffff);
          if (uVar13 < 0x9c) {
            *param_3 = 0x9c;
            goto LAB_1c0006771;
          }
          if ((char)local_res10 == '\0') {
            if (*(short *)(pbVar12 + 0x11c8) != 0) {
              uVar17 = *(undefined8 *)(pbVar12 + 0x126e);
              *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x1266);
              *(undefined8 *)(param_2 + 0x24) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x127e);
              *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x1276);
              *(undefined8 *)(param_2 + 0x34) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x128e);
              *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x1286);
              *(undefined8 *)(param_2 + 0x44) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x129e);
              *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(pbVar12 + 0x1296);
              *(undefined8 *)(param_2 + 0x54) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x12ae);
              *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(pbVar12 + 0x12a6);
              *(undefined8 *)(param_2 + 100) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x12be);
              *(undefined8 *)(param_2 + 0x6c) = *(undefined8 *)(pbVar12 + 0x12b6);
              *(undefined8 *)(param_2 + 0x74) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x12ce);
              *(undefined8 *)(param_2 + 0x7c) = *(undefined8 *)(pbVar12 + 0x12c6);
              *(undefined8 *)(param_2 + 0x84) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x12de);
              *(undefined8 *)(param_2 + 0x8c) = *(undefined8 *)(pbVar12 + 0x12d6);
              *(undefined8 *)(param_2 + 0x94) = uVar17;
              uVar17 = *(undefined8 *)(pbVar12 + 0x12ee);
              *(undefined8 *)(param_2 + 0x9c) = *(undefined8 *)(pbVar12 + 0x12e6);
              *(undefined8 *)(param_2 + 0xa4) = uVar17;
              *(undefined8 *)(param_2 + 0xac) = *(undefined8 *)(pbVar12 + 0x12f6);
              pvVar10 = (void *)(ulonglong)*(uint *)(pbVar12 + 0x12fe);
              *(uint *)(param_2 + 0xb4) = *(uint *)(pbVar12 + 0x12fe);
              uVar13 = (int)local_res8 - 1;
              if ((int)uVar13 < 1) goto LAB_1c0006bc2;
              _Dst = (void *)(param_2 + 0xb8);
              if ((int)(uint)*(ushort *)(pbVar12 + 0x11c8) < (int)uVar13) {
                uVar13 = (uint)*(ushort *)(pbVar12 + 0x11c8);
              }
              pvVar10 = *(void **)(pbVar12 + 0x11ae);
              _Size = (longlong)(int)uVar13 * 0x9c;
              goto LAB_1c0006005;
            }
            pvVar10 = (void *)tw_msg_dev(pbVar12,0x10000,"CmdMon> No average data yet: %d cmds",
                                         (ulonglong)*(ushort *)(pbVar12 + 0x1302));
            goto LAB_1c0005e45;
          }
        }
        else {
          if (uVar13 != 7) {
            pvVar10 = (void *)(ulonglong)(uVar13 - 10);
            if (uVar13 - 10 == 0) {
              bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
              pvVar10 = (void *)CONCAT71(extraout_var,bVar6);
              if (!bVar6) {
                pvVar10 = (void *)tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_HIST_OPER",param_4);
                if ((uint)local_res8 < 0x28) {
                  *param_3 = 0x28;
                  goto LAB_1c0006771;
                }
                uVar17 = *(undefined8 *)(pbVar12 + 0x1312);
                *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(pbVar12 + 0x130a);
                *(undefined8 *)(param_2 + 0x24) = uVar17;
                uVar17 = *(undefined8 *)(pbVar12 + 0x1322);
                *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)(pbVar12 + 0x131a);
                *(undefined8 *)(param_2 + 0x34) = uVar17;
                *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)(pbVar12 + 0x132a);
              }
              goto LAB_1c0006bc2;
            }
            goto LAB_1c0006771;
          }
          bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
          pvVar10 = (void *)CONCAT71(extraout_var_00,bVar6);
          if (bVar6) goto LAB_1c0006bc2;
          *(undefined4 *)(param_1 + 4) = 3;
          *(undefined1 *)(param_1 + 3) = 0;
          uVar4 = *(uint *)(param_2 + 0x10);
          if ((uVar4 & 0x4000) != 0) {
            pcVar15 = "CmdMon> GET_TRIG: Cancel";
            goto LAB_1c0006138;
          }
          uVar13 = (uint)local_res8;
          pcVar15 = "";
          local_res10 = CONCAT31((uint3)(uVar4 >> 0x17),(char)(uVar4 >> 0xf)) & 0xffffff01;
          local_res8 = (char *)CONCAT44(local_res8._4_4_,(uint)local_res8 / tw_cmon_cmdsize);
          if ((char)local_res10 != '\0') {
            pcVar15 = "_WAIT";
          }
          tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_TRIG%s count=%d",pcVar15);
          pvVar10 = (void *)(ulonglong)tw_cmon_cmdsize;
          if (uVar13 < tw_cmon_cmdsize) goto LAB_1c000669e;
          if ((char)local_res10 == '\0') {
            if (pbVar12[0x11b6] == 3) goto LAB_1c0005e4e;
            pcVar16 = "CmdMon> Triggered collection in progress, and not waiting";
            if (pbVar12[0x11b6] != 2) {
              pcVar16 = "CmdMon> Nothing trigggered, and not waiting";
            }
            goto LAB_1c0005e40;
          }
        }
LAB_1c0006241:
        pvVar10 = (void *)0x4000;
        *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) | 0x4000;
        goto LAB_1c0006bc2;
      }
      bVar6 = FUN_1c0005c5c(pbVar12,(longlong)pbVar2,param_2,param_4);
      pvVar10 = (void *)CONCAT71(extraout_var_03,bVar6);
      if (bVar6) goto LAB_1c0006bc2;
      *(undefined4 *)(param_1 + 4) = 2;
      *(undefined1 *)(param_1 + 3) = 0;
      uVar4 = *(uint *)(param_2 + 0x10);
      if ((uVar4 & 0x4000) != 0) {
        pcVar15 = "CmdMon> GET_CMDS: Cancel";
LAB_1c0006138:
        tw_msg_dev(pbVar12,0x40000,pcVar15,param_4);
        goto LAB_1c0006142;
      }
      uVar13 = (uint)local_res8;
      pcVar15 = "";
      local_res10 = CONCAT31((uint3)(uVar4 >> 0x17),(char)(uVar4 >> 0xf)) & 0xffffff01;
      local_res8 = (char *)CONCAT44(local_res8._4_4_,(uint)local_res8 / tw_cmon_cmdsize);
      if ((char)local_res10 != '\0') {
        pcVar15 = "_WAIT";
      }
      tw_msg_dev(pbVar12,0x40000,"CmdMon> GET_CMDS%s count=%d",pcVar15);
      pvVar10 = (void *)(ulonglong)tw_cmon_cmdsize;
      if (tw_cmon_cmdsize <= uVar13) {
        if ((char)local_res10 == '\0') {
LAB_1c0005e4e:
          iVar8 = *(int *)(pbVar12 + 0x11c2);
          if (iVar8 != 0) {
            iVar7 = (uint)local_res8;
            if (iVar8 < (int)(uint)local_res8) {
              iVar7 = iVar8;
            }
            pvVar10 = (void *)cm_cmds_get((undefined8 *)pbVar2,iVar7,(undefined8 *)(param_2 + 0x1c))
            ;
            goto LAB_1c0006bc2;
          }
          pcVar16 = "CmdMon> No command data, and not waiting";
LAB_1c0005e40:
          pvVar10 = (void *)tw_msg_dev(pbVar12,0x10000,pcVar16,pcVar15);
LAB_1c0005e45:
          *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x10;
          goto LAB_1c0006bc2;
        }
        pbVar12[0x153a] = 1;
        goto LAB_1c0006241;
      }
    }
  }
LAB_1c000669e:
  *param_3 = (uint)pvVar10;
LAB_1c0006771:
  return (ulonglong)pvVar10 & 0xffffffffffffff00;
}



===== FUN_1c0006bdc @ 1c0006bdc =====

void FUN_1c0006bdc(longlong param_1)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 0x1d) == '\0') {
    *(undefined1 *)(param_1 + 0x1d) = tw_cmon_avefact;
  }
  if (*(short *)(param_1 + 0x1e) == 0) {
    *(undefined2 *)(param_1 + 0x1e) = tw_cmon_lct_msecs;
  }
  *(byte *)(param_1 + 0x239) = *(byte *)(param_1 + 0x18) & 1;
  bVar1 = (byte)*(undefined2 *)(param_1 + 0x18);
  *(byte *)(param_1 + 0x23a) = bVar1 >> 1 & 1;
  *(byte *)(param_1 + 0x23b) = bVar1 >> 2 & 1;
  *(undefined1 *)(param_1 + 0x240) = *(undefined1 *)(param_1 + 0x2a);
  *(byte *)(param_1 + 0x23c) = bVar1 >> 3 & 1;
  *(bool *)(param_1 + 0x238) = *(char *)(param_1 + 0x1c) != '\0';
  return;
}



===== cm_ctrl_reset @ 1c0006c54 =====

void cm_ctrl_reset(undefined8 *param_1)

{
  memset((void *)((longlong)param_1 + 0x14),0,0x200);
  *(undefined4 *)((longlong)param_1 + 0x14) = tw_cmon_control;
  *(undefined1 *)((longlong)param_1 + 0x1d) = tw_cmon_avefact;
  *(undefined2 *)((longlong)param_1 + 0x1e) = tw_cmon_lct_msecs;
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)((longlong)param_1 + 0x214);
  *(undefined2 *)((longlong)param_1 + 0x22) = *(undefined2 *)((longlong)param_1 + 0x216);
  *(undefined2 *)((longlong)param_1 + 0x24) = *(undefined2 *)(param_1 + 0x43);
  *(undefined1 *)((longlong)param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 3) = 0x800000ff;
  *(undefined2 *)((longlong)param_1 + 0x29) = 4;
  *(undefined1 *)(param_1 + 5) = 0;
  FUN_1c0006bdc((longlong)param_1);
  cm_setup_log(param_1,'\x01',"CmReset");
  return;
}



===== cm_ctrl_clear @ 1c0006ce8 =====

void cm_ctrl_clear(undefined8 *param_1,ulonglong param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  int iVar2;
  
  if ((param_2 & 2) != 0) {
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
    iVar2 = 0;
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
    *(undefined4 *)((longlong)param_1 + 0x244) = 0;
    if (*(short *)((longlong)param_1 + 0x214) != 0) {
      lVar1 = 0;
      do {
        if (((param_2 & 1) == 0) && ((*(byte *)(lVar1 + param_1[0x44]) & 2) != 0)) {
          *(int *)((longlong)param_1 + 0x244) = *(int *)((longlong)param_1 + 0x244) + 1;
        }
        else {
          *(undefined1 *)(lVar1 + param_1[0x44]) = 0;
        }
        iVar2 = iVar2 + 1;
        lVar1 = lVar1 + 0x1c;
      } while (iVar2 < (int)(uint)*(ushort *)((longlong)param_1 + 0x214));
    }
    param_4 = "";
    if ((param_2 & 1) != 0) {
      param_4 = "ALL ";
    }
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> %sCMDs info cleared",param_4);
  }
  if ((param_2 & 4) != 0) {
    iVar2 = 0;
    if (*(short *)((longlong)param_1 + 0x216) != 0) {
      lVar1 = 0;
      do {
        iVar2 = iVar2 + 1;
        *(undefined1 *)(lVar1 + param_1[0x45]) = 0;
        lVar1 = lVar1 + 0x2c;
      } while (iVar2 < (int)(uint)*(ushort *)((longlong)param_1 + 0x216));
    }
    *(undefined2 *)(param_1 + 0x49) = 0;
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> LCTs info cleared",param_4);
  }
  if ((param_2 & 8) != 0) {
    iVar2 = 0;
    if (*(short *)(param_1 + 0x43) != 0) {
      lVar1 = 0;
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(lVar1 + param_1[0x46]) = 0;
        *(undefined4 *)(lVar1 + 0x34 + param_1[0x46]) = 0;
        *(undefined4 *)(lVar1 + 0x68 + param_1[0x46]) = 0;
        lVar1 = lVar1 + 0x9c;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 0x43));
    }
    *(undefined2 *)((longlong)param_1 + 0x24a) = 0;
    memset((void *)((longlong)param_1 + 0x24c),0,0x9c);
    memset(param_1 + 0x5d,0,0x9c);
    *(undefined2 *)((longlong)param_1 + 900) = 0;
    lVar1 = tw_time_msecs();
    *(int *)(param_1 + 0x71) = (int)lVar1;
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> AVEs info cleared",param_4);
  }
  if ((param_2 & 0x10) != 0) {
    memset((void *)((longlong)param_1 + 0x38c),0,0x28);
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> OPER histogram cleared",param_4);
  }
  if ((param_2 & 0x100) != 0) {
    memset((void *)((longlong)param_1 + 0x3b4),0,0xb8);
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> RESP histogram cleared",param_4);
  }
  if ((param_2 & 0x20) != 0) {
    memset((void *)((longlong)param_1 + 0x46c),0,0x74);
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> POST histogram cleared",param_4);
  }
  if ((param_2 & 0x40) != 0) {
    memset(param_1 + 0x9c,0,0x50);
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> SGLS histogram cleared",param_4);
  }
  if ((param_2 & 0x200) != 0) {
    *(undefined8 *)((longlong)param_1 + 0x5a4) = 0;
    *(undefined8 *)((longlong)param_1 + 0x5ac) = 0;
    *(undefined8 *)((longlong)param_1 + 0x5b4) = 0;
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> ELEN histogram cleared",param_4);
  }
  if ((char)param_2 < '\0') {
    memset(param_1 + 0xa6,0,0x74);
    tw_msg_dev((byte *)*param_1,0x10000,"CmonClear> XLEN histogram cleared",param_4);
  }
  return;
}



===== cm_ctrl_setup @ 1c0006fa4 =====

void cm_ctrl_setup(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  if ((*(ushort *)((longlong)param_2 + 6) & 0xfe) != 0) {
    cm_ctrl_clear(param_1,(ulonglong)*(ushort *)((longlong)param_2 + 6),param_3,param_4);
  }
  if ((char)param_2[2] == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x1c) = 0;
  }
  else {
    if ((*(ushort *)((longlong)param_2 + 6) & 0x4000) != 0) {
      cm_ctrl_reset(param_1);
      return;
    }
    if ((*(ushort *)((longlong)param_2 + 6) & 0x8000) == 0) {
      return;
    }
    if ((*param_2 & 0x10000000) != 0) {
      *param_2 = *(uint *)((longlong)param_1 + 0x14);
    }
    lVar4 = 4;
    puVar3 = (undefined8 *)((longlong)param_1 + 0x14);
    do {
      uVar2 = *(undefined8 *)(param_2 + 2);
      *puVar3 = *(undefined8 *)param_2;
      puVar3[1] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 6);
      puVar3[2] = *(undefined8 *)(param_2 + 4);
      puVar3[3] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 10);
      puVar3[4] = *(undefined8 *)(param_2 + 8);
      puVar3[5] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 0xe);
      puVar3[6] = *(undefined8 *)(param_2 + 0xc);
      puVar3[7] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 0x12);
      puVar3[8] = *(undefined8 *)(param_2 + 0x10);
      puVar3[9] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 0x16);
      puVar3[10] = *(undefined8 *)(param_2 + 0x14);
      puVar3[0xb] = uVar2;
      uVar2 = *(undefined8 *)(param_2 + 0x1a);
      puVar3[0xc] = *(undefined8 *)(param_2 + 0x18);
      puVar3[0xd] = uVar2;
      puVar1 = param_2 + 0x1c;
      uVar2 = *(undefined8 *)(param_2 + 0x1e);
      param_2 = param_2 + 0x20;
      puVar3[0xe] = *(undefined8 *)puVar1;
      puVar3[0xf] = uVar2;
      lVar4 = lVar4 + -1;
      puVar3 = puVar3 + 0x10;
    } while (lVar4 != 0);
    FUN_1c0006bdc((longlong)param_1);
  }
  cm_setup_log(param_1,'\x01',"CmSetup");
  return;
}



===== cm_setup_log @ 1c0007080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cm_setup_log(undefined8 *param_1,char param_2,undefined8 param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined8 uVar4;
  char *pcVar5;
  char *pcVar6;
  ulonglong uVar7;
  byte *pbVar8;
  int iVar9;
  undefined1 auStackY_138 [32];
  undefined8 local_f0;
  char local_e8 [4];
  char local_e4 [156];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  iVar9 = 0;
  if ((*(char *)((longlong)param_1 + 9) == '\0') || (*(char *)((longlong)param_1 + 0x1c) == '\0')) {
    pbVar8 = (byte *)*param_1;
    pcVar5 = "%s> Command monitoring disabled";
    goto LAB_1c00079fa;
  }
  if (*(char *)((longlong)param_1 + 0x239) == '\0') {
    pbVar8 = (byte *)*param_1;
    pcVar5 = "%s> Disable saving commands";
LAB_1c0007944:
    tw_msg_dev(pbVar8,0x10000,pcVar5,param_3);
  }
  else {
    if ((*(uint *)((longlong)param_1 + 0x14) & 1) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Saving long command times",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Trigger capture started/stopped",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 4) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Commands during trigger capture",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 8) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Commands that are NOT matched",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x10) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Start of each command if saving",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x20) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Update of each command if saving",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x40) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Finish of each command if saving",param_3);
    }
    if ((char)*(undefined4 *)((longlong)param_1 + 0x14) < '\0') {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Finish of each command if saving with locking",
                 param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x100) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Start of each command if NOT saving",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x200) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Update of each command if NOT saving",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x400) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Finish of each command if NOT saving",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x800) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,
                 "%s> MSG: Finish of each command if NOT saving with locking",param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x1000) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Indication when recover lost command entry",
                 param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x2000) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Each pending/triggered command that is skipped",
                 param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x4000) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Total pending/triggered commands skipped",
                 param_3);
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x40000000) != 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Add time/date of completion to cmd log",param_3)
      ;
    }
    if (*(int *)((longlong)param_1 + 0x14) < 0) {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> MSG: Add timestamp of cmd start to cmd log",param_3);
    }
    if (param_2 == '\0') {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Currently captured %d commands",param_3);
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Currently have %d LCT commands",param_3);
      pcVar5 = "%s> Currently have %d averages";
    }
    else {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Set max saved commands: %d",param_3);
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Set max saved LCT cmds: %d",param_3);
      pcVar5 = "%s> Set max saved averages: %d";
    }
    tw_msg_dev((byte *)*param_1,0x10000,pcVar5,param_3);
    if (*(char *)(param_1 + 5) == '\0') {
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Enable capturing ALL commands",param_3);
    }
    else {
      pbVar8 = (byte *)((longlong)param_1 + 0x34);
      do {
        if (*pbVar8 != 0) {
          local_f0 = "";
          if ((*pbVar8 & 0x80) != 0) {
            local_f0 = "Aen ";
          }
          tw_msg_dev((byte *)*param_1,0x10000,"%s> Match Filter #%d: %s%s%s%s%s%s",param_3);
          bVar1 = pbVar8[1];
          local_e8[0] = '\0';
          if ((bVar1 & 1) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," SYS",5);
          }
          if ((bVar1 & 2) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," APP",5);
          }
          if ((bVar1 & 4) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," DRV",5);
          }
          tw_msg_dev((byte *)*param_1,0x10000,"           Sources:%s",local_e8);
          bVar1 = pbVar8[2];
          local_e8[0] = '\0';
          if ((bVar1 & 0x10) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," SCSI",6);
          }
          if ((bVar1 & 0x20) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," ATA",5);
          }
          if ((bVar1 & 1) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," SRB",5);
          }
          if ((bVar1 & 2) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," WMI",5);
          }
          if ((bVar1 & 4) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," PNP",5);
          }
          if ((bVar1 & 8) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," PWR",5);
          }
          if ((char)bVar1 < '\0') {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," IOCTL",7);
          }
          if ((bVar1 & 0x40) != 0) {
            pcVar5 = (char *)((longlong)&local_f0 + 7);
            do {
              pcVar6 = pcVar5;
              pcVar5 = pcVar6 + 1;
            } while (*pcVar5 != '\0');
            builtin_strncpy(pcVar6 + 1," FWARE",7);
          }
          pcVar5 = local_e8;
          uVar4 = 0x10000;
          tw_msg_dev((byte *)*param_1,0x10000,"           Types:  %s",pcVar5);
          bVar1 = pbVar8[3];
          if (bVar1 == 0) {
            pcVar6 = "           All command opcodes";
LAB_1c0007706:
            tw_msg_dev((byte *)*param_1,0x10000,pcVar6,pcVar5);
          }
          else {
            if (bVar1 != 1) {
              if (bVar1 == 2) {
                pcVar6 = "           SCSI READ commands";
              }
              else if (bVar1 == 3) {
                pcVar6 = "           SCSI WRITE commands";
              }
              else if (bVar1 == 4) {
                pcVar6 = "           SCSI RW commands";
              }
              else {
                if (bVar1 != 5) goto LAB_1c0007710;
                pcVar6 = "           SCSI Non-RW commands";
              }
              goto LAB_1c0007706;
            }
            if (*(uint *)(pbVar8 + 8) == 0) {
              puVar2 = tw_xlate_opcode((ulonglong)pbVar8[1],
                                       CONCAT71((int7)((ulonglong)uVar4 >> 8),pbVar8[2]),
                                       *(uint *)(pbVar8 + 4),0,(undefined4 *)local_e8);
              tw_msg_dev((byte *)*param_1,0x10000,"           Opcode: %s",puVar2);
            }
            else {
              tw_msg_dev((byte *)*param_1,0x10000,"           Opmask:  0x%X",
                         (ulonglong)*(uint *)(pbVar8 + 8));
              tw_msg_dev((byte *)*param_1,0x10000,"           Opcodes: (~mask & code) == 0x%X",
                         (ulonglong)*(uint *)(pbVar8 + 4));
              tw_xlate_opmask((byte *)*param_1,pbVar8[1],pbVar8[2],*(uint *)(pbVar8 + 4),
                              ~*(uint *)(pbVar8 + 8));
            }
          }
LAB_1c0007710:
          if (*(uint *)(pbVar8 + 0xc) == 0) {
            if (*(int *)(pbVar8 + 0x10) != 0) {
              pbVar3 = (byte *)*param_1;
              pcVar5 = "           Xlen <= %d bytes";
              uVar7 = 0;
              goto LAB_1c0007759;
            }
          }
          else {
            pbVar3 = (byte *)*param_1;
            if (*(int *)(pbVar8 + 0x10) == 0) {
              uVar7 = (ulonglong)pbVar8[0x14];
              pcVar5 = "           Xlen >= %d bytes";
LAB_1c0007759:
              tw_msg_dev(pbVar3,0x10000,pcVar5,uVar7);
            }
            else {
              tw_msg_dev(pbVar3,0x10000,"           Xlen %d-%d bytes",
                         (ulonglong)*(uint *)(pbVar8 + 0xc));
            }
          }
          bVar1 = pbVar8[0x14];
          if (bVar1 != 0xff) {
            if (pbVar8[0x16] == 0xff) {
              tw_msg_dev((byte *)*param_1,0x10000,"           Target %d",(ulonglong)bVar1);
            }
            else {
              tw_msg_dev((byte *)*param_1,0x10000,"           Targets %d-%d",(ulonglong)bVar1);
            }
          }
          bVar1 = pbVar8[0x15];
          if (bVar1 != 0xff) {
            if (pbVar8[0x17] == 0xff) {
              tw_msg_dev((byte *)*param_1,0x10000,"           LUN %d",(ulonglong)bVar1);
            }
            else {
              tw_msg_dev((byte *)*param_1,0x10000,"           LUNs %d-%d",(ulonglong)bVar1);
            }
          }
        }
        iVar9 = iVar9 + 1;
        pbVar8 = pbVar8 + 0x18;
      } while (iVar9 < 0x14);
    }
    if (*(byte *)((longlong)param_1 + 0x29) != 0) {
      if ((*(byte *)((longlong)param_1 + 0x29) & 1) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Trigger on %d Filters",param_3);
      }
      if ((*(byte *)((longlong)param_1 + 0x29) & 2) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Trigger on Rtime > %d",param_3);
      }
      if ((*(byte *)((longlong)param_1 + 0x29) & 4) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Trigger on Error",param_3);
      }
      if ((*(byte *)((longlong)param_1 + 0x29) & 8) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Trigger on Reset",param_3);
      }
      if ((*(byte *)((longlong)param_1 + 0x29) & 0x10) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Trigger on Request",param_3);
      }
      tw_msg_dev((byte *)*param_1,0x10000,"%s> Complete %d commands after trigger",param_3);
      if ((*(byte *)(param_1 + 3) & 0x10) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Stop CMD collection upon trigger",param_3);
      }
      if ((*(byte *)(param_1 + 3) & 0x20) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Stop LCT collection upon trigger",param_3);
      }
      if ((*(byte *)(param_1 + 3) & 0x40) != 0) {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Stop AVES collection upon trigger",param_3);
      }
      if (*(char *)(param_1 + 3) < '\0') {
        tw_msg_dev((byte *)*param_1,0x10000,"%s> Stop HIST collection upon trigger",param_3);
      }
      if ((*(ushort *)(param_1 + 3) & 0x100) != 0) {
        pbVar8 = (byte *)*param_1;
        pcVar5 = "%s> Send AEN to API upon trigger";
        goto LAB_1c0007944;
      }
    }
  }
  if (*(char *)((longlong)param_1 + 0x23a) == '\0') {
    tw_msg_dev((byte *)*param_1,0x10000,"%s> Disable saving long response cmds",param_3);
  }
  else {
    tw_msg_dev((byte *)*param_1,0x10000,"%s> Enable saving LCTs >%d msecs",param_3);
  }
  if (*(char *)((longlong)param_1 + 0x23b) == '\0') {
    tw_msg_dev((byte *)*param_1,0x10000,"%s> Disable calculating averages",param_3);
  }
  else {
    tw_msg_dev((byte *)*param_1,0x10000,"%s> Enable calculating averages",param_3);
    tw_msg_dev((byte *)*param_1,0x10000,"%s> Use Averaging Factor = %d/100",param_3);
  }
  pbVar8 = (byte *)*param_1;
  if (*(char *)((longlong)param_1 + 0x23c) == '\0') {
    pcVar5 = "%s> Disable calculating histograms";
  }
  else {
    pcVar5 = "%s> Enable calculating histograms";
  }
LAB_1c00079fa:
  tw_msg_dev(pbVar8,0x10000,pcVar5,param_3);
  return;
}



===== FUN_1c0007a28 @ 1c0007a28 =====

ulonglong FUN_1c0007a28(longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ushort local_res10 [12];
  
  uVar4 = cm_cmds_addone(param_1,local_res10,param_3,param_4);
  if ((char)uVar4 != '\0') {
    lVar5 = (ulonglong)local_res10[0] * 0x1c;
    *(undefined2 *)(param_2 + 0x58) = *(undefined2 *)(*param_1 + 0x2a4);
    lVar2 = param_1[0x44];
    uVar3 = *(undefined8 *)(param_2 + 0x54);
    *(undefined8 *)(lVar5 + lVar2) = *(undefined8 *)(param_2 + 0x4c);
    ((undefined8 *)(lVar5 + lVar2))[1] = uVar3;
    *(undefined8 *)(lVar5 + 0x10 + lVar2) = *(undefined8 *)(param_2 + 0x5c);
    uVar1 = *(undefined4 *)(param_2 + 100);
    *(undefined4 *)(lVar5 + 0x18 + lVar2) = uVar1;
    uVar4 = CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);
    *(undefined1 *)(param_2 + 0x68) = 1;
    *(ushort *)(param_2 + 0x6a) = local_res10[0];
  }
  return uVar4;
}



===== FUN_1c0007a98 @ 1c0007a98 =====

byte * FUN_1c0007a98(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (*(char *)(param_2 + 0x68) == '\0') {
    pbVar3 = (byte *)(param_2 + 0x4c);
  }
  else {
    pbVar3 = (byte *)((ulonglong)*(ushort *)(param_2 + 0x6a) * 0x1c + *(longlong *)(param_1 + 0x220)
                     );
  }
  pbVar3[2] = *(byte *)(param_2 + 0x13);
  pbVar3[1] = *(byte *)(param_2 + 0x12);
  *(undefined4 *)(pbVar3 + 4) = *(undefined4 *)(param_2 + 0x14);
  pbVar3[3] = *(byte *)(param_2 + 0x18);
  pbVar3[10] = *(byte *)(param_2 + 0x19);
  pbVar3[0xb] = *(byte *)(param_2 + 0x1a);
  *(undefined2 *)(pbVar3 + 8) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(pbVar3 + 0xe) = *(undefined2 *)(param_2 + 0x34);
  *(undefined4 *)(pbVar3 + 0x10) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(pbVar3 + 0x14) = *(undefined4 *)(param_2 + 0x1c);
  lVar1 = tw_time_msecs();
  *pbVar3 = 3;
  *(int *)(pbVar3 + 0x18) = (int)lVar1;
  bVar2 = *pbVar3;
  if ((*(ushort *)(param_2 + 0x24) & 0x1000) != 0) {
    bVar2 = 7;
  }
  *pbVar3 = bVar2;
  if ((*(ushort *)(param_2 + 0x24) & 0xc000) == 0) {
    *pbVar3 = *pbVar3 & 0xf7;
  }
  else {
    *pbVar3 = *pbVar3 | 8;
  }
  return pbVar3;
}



===== cm_req_start @ 1c0007b48 =====

void cm_req_start(byte *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  byte *pbVar2;
  ulonglong uVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (*(char *)((longlong)param_2 + 0x49) != '\0') {
    return;
  }
  pbVar2 = FUN_1c0007a98((longlong)param_1,(longlong)param_2);
  pbVar4 = pbVar2;
  bVar1 = cm_match(param_1,param_2,pbVar2,param_4);
  if (bVar1) {
    if ((param_1[0x239] == 0) ||
       (uVar3 = FUN_1c0007a28((longlong *)param_1,(longlong)param_2,pbVar4,param_4),
       (char)uVar3 == '\0')) {
      if ((*(uint *)(param_1 + 0x14) & 0x100) == 0) {
        return;
      }
      pcVar5 = "Cm!!Start>>";
    }
    else {
      if ((*(uint *)(param_1 + 0x14) & 0x10) == 0) {
        return;
      }
      pcVar5 = "CmonStart>>";
    }
  }
  else {
    *(undefined1 *)((longlong)param_2 + 0x49) = 1;
    if ((*(uint *)(param_1 + 0x14) & 8) == 0) {
      return;
    }
    pcVar5 = "Cm!!Match>>";
  }
  cm_log_req(param_2,pbVar2,pcVar5);
  return;
}



===== FUN_1c0007be8 @ 1c0007be8 =====

void FUN_1c0007be8(longlong *param_1)

{
  longlong *plVar1;
  undefined4 *puVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  plVar1 = tw_pendio_dolock(*param_1,4);
  if (plVar1 != (longlong *)0x0) {
    uVar5 = (ulonglong)*(uint *)(plVar1 + 6) / 0x2c;
    uVar4 = (uint)uVar5;
    if (*(ushort *)(param_1 + 0x49) < uVar4) {
      tw_pendio_unlock(*plVar1,plVar1);
    }
    else {
      puVar2 = tw_xlate_opcode((ulonglong)
                               CONCAT11((char)(*(ushort *)(param_1 + 0x49) >> 8),
                                        *(undefined1 *)((longlong)plVar1 + 0x12)),
                               CONCAT71((uint7)*(uint *)(plVar1 + 6) / 0x580,
                                        *(undefined1 *)((longlong)plVar1 + 0x13)),
                               *(uint *)((longlong)plVar1 + 0x14),*(byte *)(plVar1 + 3),
                               (undefined4 *)((longlong)plVar1 + 0x104));
      tw_msg_dev((byte *)*param_1,0x2000,"CmDoneLCT> %s: count=%d",puVar2);
      memcpy((void *)plVar1[5],
             (void *)((ulonglong)(*(ushort *)(param_1 + 0x49) - uVar4) * 0x2c + param_1[0x45]),
             uVar5 * 0x2c);
      tw_pendio_unlock(*plVar1,plVar1);
      uVar6 = 0;
      plVar3 = plVar1;
      tw_pendio_delete((longlong *)*plVar1,plVar1,'\0');
      tw_request_finish(plVar1,plVar3,uVar6,(ulonglong)puVar2);
    }
  }
  return;
}



===== FUN_1c0007cd4 @ 1c0007cd4 =====

void FUN_1c0007cd4(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  
  lVar4 = *param_1;
  plVar2 = tw_pendio_dolock(lVar4,5);
  if (plVar2 != (longlong *)0x0) {
    plVar5 = (longlong *)plVar2[5];
    lVar1 = param_1[0x5e];
    *plVar5 = param_1[0x5d];
    plVar5[1] = lVar1;
    lVar1 = param_1[0x60];
    plVar5[2] = param_1[0x5f];
    plVar5[3] = lVar1;
    lVar1 = param_1[0x62];
    plVar5[4] = param_1[0x61];
    plVar5[5] = lVar1;
    lVar1 = param_1[100];
    plVar5[6] = param_1[99];
    plVar5[7] = lVar1;
    lVar1 = param_1[0x66];
    plVar5[8] = param_1[0x65];
    plVar5[9] = lVar1;
    lVar1 = param_1[0x68];
    plVar5[10] = param_1[0x67];
    plVar5[0xb] = lVar1;
    lVar1 = param_1[0x6a];
    plVar5[0xc] = param_1[0x69];
    plVar5[0xd] = lVar1;
    lVar1 = param_1[0x6c];
    plVar5[0xe] = param_1[0x6b];
    plVar5[0xf] = lVar1;
    lVar1 = param_1[0x6e];
    plVar5[0x10] = param_1[0x6d];
    plVar5[0x11] = lVar1;
    plVar5[0x12] = param_1[0x6f];
    *(int *)(plVar5 + 0x13) = (int)param_1[0x70];
    puVar3 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar4 >> 8),
                                      *(undefined1 *)((longlong)plVar2 + 0x12)),
                             CONCAT71((int7)((ulonglong)(param_1 + 0x6d) >> 8),
                                      *(undefined1 *)((longlong)plVar2 + 0x13)),
                             *(uint *)((longlong)plVar2 + 0x14),*(byte *)(plVar2 + 3),
                             (undefined4 *)((longlong)plVar2 + 0x104));
    tw_msg_dev((byte *)*param_1,0x2000,"CmDoneAve> %s",puVar3);
    tw_pendio_unlock(*plVar2,plVar2);
    uVar6 = 0;
    plVar5 = plVar2;
    tw_pendio_delete((longlong *)*plVar2,plVar2,'\0');
    tw_request_finish(plVar2,plVar5,uVar6,(ulonglong)puVar3);
  }
  return;
}



===== cm_req_finish @ 1c0007dd0 =====

undefined8 cm_req_finish(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  ushort uVar2;
  char cVar3;
  char cVar4;
  ulonglong uVar5;
  byte *pbVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  undefined1 *puVar12;
  
  cVar3 = (char)param_3;
  pbVar6 = (byte *)0x0;
  if (((*(char *)((longlong)param_2 + 0x49) == '\0') ||
      ((*(char *)(*param_2 + 0x23c) != '\0' && (*(char *)((longlong)param_2 + 0x3e) != '\0')))) &&
     (((char)param_2[0xd] != '\0' ||
      ((*(char *)((longlong)param_1 + 0x239) == '\0' ||
       (uVar5 = FUN_1c0007a28(param_1,(longlong)param_2,param_3,param_4), (char)uVar5 != '\0'))))))
  {
    pbVar6 = FUN_1c0007a98((longlong)param_1,(longlong)param_2);
    if (*(short *)((longlong)param_2 + 0x3c) == 0) {
      if (*(char *)((longlong)param_2 + 0x3e) == '\0') {
        uVar10 = *(int *)(pbVar6 + 0x18) - *(int *)(pbVar6 + 0x14);
        if (*(char *)((longlong)param_1 + 0x23c) != '\0') {
          cm_hist_oper((longlong)param_1,*(int *)(pbVar6 + 4),pbVar6[2]);
          if (uVar10 < 10) {
            uVar8 = uVar10;
          }
          else if (uVar10 < 100) {
            uVar8 = uVar10 / 10 + 9;
          }
          else if (uVar10 < 1000) {
            uVar8 = uVar10 / 100 + 0x11;
          }
          else if (uVar10 < 10000) {
            uVar8 = uVar10 / 1000 + 0x19;
          }
          else if (uVar10 < 100000) {
            uVar8 = uVar10 / 10000 + 0x21;
          }
          else {
            uVar8 = 0x2d;
          }
          piVar1 = (int *)((longlong)param_1 + ((ulonglong)uVar8 + 0xed) * 4);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          uVar2 = *(ushort *)(pbVar6 + 0xc);
          uVar5 = (ulonglong)uVar2;
          if (9 < uVar2) {
            if (uVar2 < 100) {
              uVar5 = (ulonglong)(uVar2 / 10 + 9);
            }
            else if (uVar2 < 1000) {
              uVar5 = (ulonglong)(uVar2 / 100 + 0x11);
            }
            else {
              uVar5 = 0x1c;
            }
          }
          piVar1 = (int *)((longlong)param_1 + (uVar5 + 0x11b) * 4);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          uVar2 = *(ushort *)(pbVar6 + 0xe);
          uVar5 = (ulonglong)uVar2;
          if (9 < uVar2) {
            if (uVar2 < 100) {
              uVar5 = (ulonglong)(uVar2 / 10 + 9);
            }
            else {
              uVar5 = 0x13;
            }
          }
          piVar1 = (int *)((longlong)param_1 + (uVar5 + 0x138) * 4);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          uVar8 = *(uint *)(pbVar6 + 0x10) >> 9;
          if (9 < uVar8) {
            if (uVar8 < 100) {
              uVar8 = uVar8 / 10 + 9;
            }
            else if (uVar8 < 1000) {
              uVar8 = uVar8 / 100 + 0x11;
            }
            else {
              uVar8 = 0x1c;
            }
          }
          piVar1 = (int *)((longlong)param_1 + ((ulonglong)uVar8 + 0x14c) * 4);
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          puVar9 = (uint *)(param_2 + 0x10);
          iVar11 = 0;
          param_4 = 0;
          do {
            if (*puVar9 == 0) break;
            uVar8 = *puVar9 >> 0xc;
            uVar5 = (ulonglong)uVar8;
            if (5 < uVar8) {
              uVar5 = 5;
            }
            piVar1 = (int *)((longlong)param_1 + (uVar5 + 0x169) * 4);
            LOCK();
            *piVar1 = *piVar1 + 1;
            UNLOCK();
            iVar11 = iVar11 + 1;
            puVar9 = puVar9 + 1;
          } while (iVar11 < 0x21);
        }
        uVar5 = (ulonglong)*(ushort *)((longlong)param_2 + 0x24);
        if ((*(ushort *)((longlong)param_2 + 0x24) & 0x4000) == 0) {
          if (*(char *)((longlong)param_1 + 0x23a) != '\0') {
            cVar4 = cm_lcts_insert(param_1,pbVar6,uVar10,
                                   CONCAT71((int7)((ulonglong)param_4 >> 8),cVar3 == '\0'),
                                   (void *)((longlong)param_2 + 0x6e));
            uVar5 = CONCAT71(extraout_var,cVar4);
            if (cVar4 != '\0') {
              if (cVar3 == '\0') {
                *(undefined1 *)((longlong)param_2 + 0x6c) = 1;
              }
              else {
                uVar5 = FUN_1c0007be8(param_1);
              }
            }
          }
          if (((*(char *)((longlong)param_1 + 0x23b) != '\0') && (cVar3 != '\0')) &&
             (uVar5 = cm_aves_addone((longlong)param_1,(longlong)pbVar6,uVar10), (char)uVar5 != '\0'
             )) {
            uVar5 = FUN_1c0007cd4(param_1);
          }
        }
        if (((char)param_2[0xd] != '\0') &&
           (uVar5 = cm_trig_check(param_1,param_2,(longlong)pbVar6,cVar3 == '\0'),
           (char)uVar5 != '\0')) {
          if (cVar3 == '\0') {
            *(undefined1 *)((longlong)param_2 + 0x6d) = 1;
          }
          else {
            uVar5 = cm_trig_send(param_1);
          }
        }
        if ((*(char *)((longlong)param_2 + 0x6c) != '\0') ||
           (*(char *)((longlong)param_2 + 0x6d) != '\0')) {
LAB_1c0008145:
          return uVar5 & 0xffffffffffffff00;
        }
        if (*(char *)((longlong)param_1 + 0x5bc) != '\0') {
          if (cVar3 == '\0') {
            uVar5 = *param_2;
            if ((*(uint *)(uVar5 + 0x292) & 0x100) != 0) goto LAB_1c0008145;
          }
          else {
            uVar7 = cm_cmds_fillone(param_1,(undefined8 *)pbVar6);
            if ((char)uVar7 == '\0') {
              *(undefined1 *)((longlong)param_1 + 0x5bc) = 0;
            }
          }
        }
      }
      else {
        *pbVar6 = *pbVar6 | 0x80;
      }
    }
    else {
      *pbVar6 = *pbVar6 | 0x40;
    }
  }
  uVar10 = *(uint *)((longlong)param_1 + 0x14);
  uVar5 = (ulonglong)uVar10;
  if ((char)param_2[0xd] == '\0') {
    if ((uVar10 >> 10 & 1) == 0) goto LAB_1c0008139;
    puVar12 = &s_Cm__Finish>;
  }
  else {
    if ((uVar10 & 0x40) == 0) goto LAB_1c0008139;
    puVar12 = &s_CmonFinish>;
  }
  uVar5 = cm_log_req(param_2,pbVar6,puVar12);
LAB_1c0008139:
  if (pbVar6 != (byte *)0x0) {
    *pbVar6 = *pbVar6 & 0xfd;
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== cm_req_finish_locked @ 1c0008160 =====

void cm_req_finish_locked(longlong *param_1,longlong *param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  
  if ((char)param_2[0xd] == '\0') {
    pbVar4 = (byte *)((longlong)param_2 + 0x4c);
  }
  else {
    pbVar4 = (byte *)((ulonglong)*(ushort *)((longlong)param_2 + 0x6a) * 0x1c + param_1[0x44]);
  }
  if (*(char *)((longlong)param_2 + 0x6c) != '\0') {
    cVar1 = cm_lcts_insert(param_1,pbVar4,*(int *)(pbVar4 + 0x18) - *(int *)(pbVar4 + 0x14),0,
                           (void *)((longlong)param_2 + 0x6e));
    if (cVar1 != '\0') {
      FUN_1c0007be8(param_1);
    }
  }
  if (*(char *)((longlong)param_2 + 0x6d) != '\0') {
    uVar2 = cm_trig_check(param_1,param_2,(longlong)pbVar4,'\0');
    if ((char)uVar2 != '\0') {
      cm_trig_send(param_1);
    }
  }
  if (*(char *)((longlong)param_1 + 0x5bc) != '\0') {
    uVar3 = cm_cmds_fillone(param_1,(undefined8 *)pbVar4);
    if ((char)uVar3 == '\0') {
      *(undefined1 *)((longlong)param_1 + 0x5bc) = 0;
    }
  }
  if ((char)param_2[0xd] == '\0') {
    if ((*(uint *)((longlong)param_1 + 0x14) & 0x800) == 0) goto LAB_1c0008230;
    puVar5 = &s_Cm__FinisH>;
  }
  else {
    if (-1 < (char)*(undefined4 *)((longlong)param_1 + 0x14)) goto LAB_1c0008230;
    puVar5 = &s_CmonFinisH>;
  }
  cm_log_req(param_2,pbVar4,puVar5);
LAB_1c0008230:
  *pbVar4 = *pbVar4 & 0xfd;
  return;
}



===== FUN_1c0008244 @ 1c0008244 =====

ulonglong FUN_1c0008244(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined8 in_RAX;
  undefined7 uVar8;
  ulonglong uVar7;
  int iVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  bool bVar12;
  
  bVar1 = *(byte *)(param_2 + 2);
  uVar8 = (undefined7)((ulonglong)in_RAX >> 8);
  uVar7 = CONCAT71(uVar8,*(byte *)(param_1 + 2));
  uVar11 = 1;
  if (((bVar1 & *(byte *)(param_1 + 2)) == 0) ||
     (uVar7 = CONCAT71(uVar8,*(byte *)(param_1 + 1)),
     (*(byte *)(param_2 + 1) & *(byte *)(param_1 + 1)) == 0)) {
LAB_1c0008286:
    return uVar7 & 0xffffffffffffff00;
  }
  bVar2 = *(byte *)(param_1 + 0x14);
  if (bVar2 != 0xff) {
    bVar3 = *(byte *)(param_2 + 10);
    uVar7 = CONCAT71(uVar8,bVar3);
    if (bVar3 == 0xff) goto LAB_1c0008286;
    if (*(byte *)(param_1 + 0x16) == 0xff) {
      if (bVar2 != bVar3) goto LAB_1c0008286;
    }
    else if ((bVar3 < bVar2) || (*(byte *)(param_1 + 0x16) < bVar3)) goto LAB_1c0008286;
  }
  bVar2 = *(byte *)(param_1 + 0x15);
  if (bVar2 != 0xff) {
    bVar3 = *(byte *)(param_2 + 0xb);
    uVar7 = CONCAT71((int7)(uVar7 >> 8),bVar3);
    if (bVar3 == 0xff) goto LAB_1c0008286;
    if (*(byte *)(param_1 + 0x17) == 0xff) {
      if (bVar2 != bVar3) goto LAB_1c0008286;
    }
    else if ((bVar3 <= bVar2) || (*(byte *)(param_1 + 0x17) <= bVar3)) goto LAB_1c0008286;
  }
  uVar4 = *(uint *)(param_1 + 0xc);
  uVar7 = (ulonglong)uVar4;
  if ((uVar4 != 0) && (*(uint *)(param_2 + 0x10) <= uVar4)) goto LAB_1c0008286;
  uVar4 = *(uint *)(param_1 + 0x10);
  uVar7 = (ulonglong)uVar4;
  if ((uVar4 != 0) && (uVar4 <= *(uint *)(param_2 + 0x10))) goto LAB_1c0008286;
  bVar2 = *(byte *)(param_1 + 3);
  if ((bVar2 & 1) != 0) {
    if ((*(uint *)(param_1 + 4) & ~*(uint *)(param_1 + 8)) ==
        (*(uint *)(param_2 + 4) & ~*(uint *)(param_1 + 8))) goto LAB_1c00082f3;
    uVar11 = 0;
  }
  if ((bVar1 & 0x10) != 0) {
    if (bVar2 == 2) {
      iVar9 = *(int *)(param_2 + 4) + -8;
LAB_1c00083fe:
      if (((iVar9 == 0) || (iVar9 == 0x20)) || (iVar9 == 0x80)) goto LAB_1c00082f3;
      bVar12 = iVar9 == 0xa0;
LAB_1c0008419:
      if (bVar12) goto LAB_1c00082f3;
    }
    else {
      if (bVar2 == 3) {
        iVar9 = *(int *)(param_2 + 4) + -10;
        goto LAB_1c00083fe;
      }
      if (bVar2 == 4) {
        iVar9 = *(int *)(param_2 + 4);
        if (((iVar9 == 8) ||
            ((((iVar9 == 10 || (iVar9 == 0x28)) || (iVar9 == 0x2a)) ||
             ((iVar9 == 0x88 || (iVar9 == 0x8a)))))) || (iVar9 == 0xa8)) goto LAB_1c00082f3;
        bVar12 = iVar9 == 0xaa;
        goto LAB_1c0008419;
      }
      if (bVar2 != 5) goto LAB_1c0008352;
      iVar9 = *(int *)(param_2 + 4);
      if ((((iVar9 != 8) && (iVar9 != 10)) &&
          ((iVar9 != 0x28 && ((iVar9 != 0x2a && (iVar9 != 0x88)))))) &&
         ((iVar9 != 0x8a && ((iVar9 != 0xa8 && (iVar9 != 0xaa)))))) goto LAB_1c00082f3;
    }
    uVar11 = 0;
  }
LAB_1c0008352:
  if ((bVar1 & 0x20) == 0) goto LAB_1c00084c0;
  uVar4 = *(uint *)(param_2 + 4);
  uVar10 = (ulonglong)uVar4;
  bVar12 = false;
  bVar6 = false;
  if (0x60 < uVar4) {
    if (uVar4 != 0x61) {
      if (uVar4 == 0xc4) goto LAB_1c000839e;
      if (uVar4 != 0xc5) {
        if (0xc6 < uVar4) {
          if (uVar4 < 0xc9) goto LAB_1c000839e;
          uVar7 = (ulonglong)(uVar4 - 0xca);
          if (((uVar4 - 0xca & 0xfffffff9) == 0) && (uVar4 != 0xd0)) goto LAB_1c000843c;
        }
        goto LAB_1c000843e;
      }
    }
    goto LAB_1c000843c;
  }
  if (uVar4 == 0x60) {
LAB_1c000839e:
    bVar12 = true;
  }
  else if (uVar4 < 0x31) {
    if (uVar4 == 0x30) {
LAB_1c000843c:
      bVar6 = true;
    }
    else if ((uVar4 < 0x2c) &&
            (uVar7 = (ulonglong)uVar4, (0xe7100000000U >> (uVar7 & 0x3f) & 1) != 0))
    goto LAB_1c000839e;
  }
  else if ((uVar4 < 0x3f) && (uVar7 = uVar10, (0x4e70000000000000U >> (uVar10 & 0x3f) & 1) != 0))
  goto LAB_1c000843c;
LAB_1c000843e:
  bVar5 = bVar12;
  if ((bVar2 == 2) || (bVar5 = bVar6, bVar2 == 3)) {
LAB_1c00084b7:
    if (bVar5) {
LAB_1c00082f3:
      return CONCAT71((int7)(uVar7 >> 8),1);
    }
  }
  else {
    if (bVar2 == 4) {
      if (bVar12) goto LAB_1c00082f3;
      goto LAB_1c00084b7;
    }
    if (bVar2 != 5) goto LAB_1c00084c0;
    if ((!bVar12) && (!bVar6)) goto LAB_1c00082f3;
  }
  uVar11 = 0;
LAB_1c00084c0:
  return CONCAT71((int7)(uVar7 >> 8),uVar11);
}



===== cm_match @ 1c00084c8 =====

bool cm_match(byte *param_1,undefined8 *param_2,byte *param_3,undefined8 param_4)

{
  char *pcVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined8 uVar9;
  byte *pbVar10;
  uint uVar11;
  bool bVar12;
  
  if (param_1[0x28] == 0) {
    bVar12 = true;
  }
  else {
    bVar12 = false;
    pbVar10 = param_1 + 0x34;
    bVar4 = false;
    bVar3 = false;
    uVar11 = 0;
    do {
      bVar2 = *pbVar10;
      if (bVar2 == 0) break;
      if ((bVar12 == false) || ((bVar2 & 0xfe) != 0)) {
        bVar3 = bVar4;
        if ((bVar2 & 1) != 0) {
          bVar3 = true;
        }
        pbVar7 = pbVar10;
        pbVar8 = param_3;
        uVar5 = FUN_1c0008244((longlong)pbVar10,(longlong)param_3);
        bVar4 = bVar3;
        if ((char)uVar5 == '\0') {
          if ((bVar2 & 0x20) != 0) {
            cm_log_out((longlong *)param_1,param_3,uVar11,param_4,-0x40);
          }
        }
        else {
          if ((bVar2 & 0x10) != 0) {
            pbVar7 = param_1;
            pbVar8 = param_3;
            cm_log_out((longlong *)param_1,param_3,uVar11,param_4,-0x40);
          }
          if (((param_1[0x29] & 1) != 0) && ((*pbVar10 & 8) != 0)) {
            *(undefined1 *)((longlong)param_2 + 0x4a) = 1;
            *(char *)((longlong)param_2 + 0x4b) = (char)uVar11;
            goto LAB_1c000863c;
          }
          if ((char)*pbVar10 < '\0') {
            pcVar1 = (char *)((longlong)param_2 + 0x104);
            puVar6 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar7 >> 8),
                                              *(undefined1 *)((longlong)param_2 + 0x12)),
                                     CONCAT71((int7)((ulonglong)pbVar8 >> 8),
                                              *(undefined1 *)((longlong)param_2 + 0x13)),
                                     *(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                                     (undefined4 *)pcVar1);
            uVar9 = 0x96;
            tw_string(pcVar1,0x96,"CmdMon Match: %s",puVar6);
            param_4 = 0xdd0a;
            tw_aen_make((byte *)*param_2,uVar9,*(undefined2 *)(param_2 + 2),0xdd0a,pcVar1);
          }
          if ((*pbVar10 & 1) != 0) {
            bVar12 = true;
          }
        }
      }
      uVar11 = uVar11 + 1;
      pbVar10 = pbVar10 + 0x18;
    } while ((int)uVar11 < 0x14);
    if (bVar3) {
      if (param_1[0x28] == 2) {
        bVar12 = bVar12 == false;
      }
    }
    else {
LAB_1c000863c:
      bVar12 = true;
    }
  }
  return bVar12;
}



===== cm_cmds_addone @ 1c0008664 =====

ulonglong cm_cmds_addone(longlong *param_1,undefined2 *param_2,undefined8 param_3,undefined8 param_4
                        )

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int *piVar5;
  uint *puVar6;
  undefined8 uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined *puVar10;
  
  uVar8 = 0;
  puVar6 = (uint *)((longlong)param_1 + 0xc);
  LOCK();
  uVar1 = *puVar6;
  *puVar6 = *puVar6 + 1;
  UNLOCK();
  uVar3 = (ulonglong)uVar1 % (ulonglong)*(ushort *)((longlong)param_1 + 0x214);
  pbVar9 = (byte *)(uVar3 * 0x1c + param_1[0x44]);
  uVar4 = CONCAT71((int7)(uVar3 >> 8),*pbVar9);
  if ((*pbVar9 & 1) != 0) {
    while( true ) {
      bVar2 = *pbVar9;
      uVar4 = CONCAT71((int7)(uVar4 >> 8),bVar2) & 0xffffffffffffff82;
      if ((char)uVar4 == -0x7e) break;
      if (((bVar2 & 2) == 0) && (((bVar2 & 0x20) == 0 || ((char)param_1[0x47] != '\x02'))))
      goto LAB_1c00087a2;
      if ((*(uint *)((longlong)param_1 + 0x14) >> 0xd & 1) != 0) {
        cm_log_out(param_1,pbVar9,(uint)uVar3,param_4,'\x10');
      }
      uVar8 = uVar8 + 1;
      if (*(int *)((longlong)param_1 + 0x244) < (int)uVar8) {
        puVar10 = &s_CmAddCmd>_Queue_full_of_PENDING_;
        uVar7 = 1;
        tw_msg_dev((byte *)*param_1,1,"CmAddCmd> Queue full of PENDING cmds!",param_4);
        uVar3 = cm_cmds_log(param_1,uVar7,puVar10,param_4);
        *(undefined1 *)((longlong)param_1 + 9) = 0;
        return uVar3 & 0xffffffffffffff00;
      }
      LOCK();
      uVar1 = *puVar6;
      *puVar6 = *puVar6 + 1;
      UNLOCK();
      uVar3 = (ulonglong)uVar1 % (ulonglong)*(ushort *)((longlong)param_1 + 0x214);
      pbVar9 = (byte *)(uVar3 * 0x1c + param_1[0x44]);
      uVar4 = CONCAT71((int7)(uVar3 >> 8),*pbVar9);
      if ((*pbVar9 & 1) == 0) goto LAB_1c00087a2;
    }
    uVar4 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
    if ((*(uint *)((longlong)param_1 + 0x14) >> 0xc & 1) != 0) {
      uVar4 = tw_msg_dev((byte *)*param_1,8,"CmAddCmd> Recover lost entry",param_4);
    }
LAB_1c00087a2:
    if ((uVar8 != 0) &&
       (uVar4 = (ulonglong)*(uint *)((longlong)param_1 + 0x14),
       (*(uint *)((longlong)param_1 + 0x14) >> 0xe & 1) != 0)) {
      uVar4 = tw_msg_dev((byte *)*param_1,8,"CmAddCmd> Skipped: %",(ulonglong)uVar8);
    }
  }
  piVar5 = (int *)CONCAT71((int7)(uVar4 >> 8),*pbVar9);
  if ((*pbVar9 & 1) == 0) {
    piVar5 = (int *)((longlong)param_1 + 0x244);
    LOCK();
    *piVar5 = *piVar5 + 1;
    UNLOCK();
  }
  *pbVar9 = 0;
  *param_2 = (short)uVar3;
  return CONCAT71((int7)((ulonglong)piVar5 >> 8),1);
}



===== cm_cmds_get @ 1c0008808 =====

void cm_cmds_get(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  char *pcVar11;
  undefined8 *puVar12;
  
  iVar1 = *(int *)(param_1 + 2);
  uVar9 = 0;
  uVar3 = (longlong)*(int *)((longlong)param_1 + 0xc) %
          (longlong)(int)(uint)*(ushort *)((longlong)param_1 + 0x214);
  uVar8 = uVar3 & 0xffffffff;
  lVar5 = (longlong)(int)uVar3;
  lVar6 = lVar5;
  puVar12 = param_3;
  do {
    lVar2 = param_1[0x44];
    lVar10 = lVar6 * 0x1c;
    if ((*(byte *)(lVar10 + lVar2) & 1) != 0) {
      uVar4 = ((undefined8 *)(lVar10 + lVar2))[1];
      uVar9 = uVar9 + 1;
      *puVar12 = *(undefined8 *)(lVar10 + lVar2);
      puVar12[1] = uVar4;
      puVar12[2] = *(undefined8 *)(lVar10 + 0x10 + lVar2);
      *(undefined4 *)(puVar12 + 3) = *(undefined4 *)(lVar10 + 0x18 + lVar2);
      puVar12 = (undefined8 *)((longlong)puVar12 + 0x1c);
      if (param_2 <= (int)uVar9) break;
    }
    uVar7 = (int)uVar8 + 1;
    uVar8 = (ulonglong)uVar7;
    lVar6 = lVar6 + 1;
    if ((int)(uint)*(ushort *)((longlong)param_1 + 0x214) <= (int)uVar7) {
      uVar8 = 0;
      lVar6 = 0;
    }
  } while (lVar6 != lVar5);
  if (iVar1 == *(int *)(param_1 + 2)) {
    pcVar11 = "CmGetCmds> Returned %d commands";
    uVar7 = 0x2000;
  }
  else {
    if (tw_cmon_cmdsize * uVar9 != 0) {
      memset(param_3,0,(ulonglong)(tw_cmon_cmdsize * uVar9));
    }
    pcVar11 = "CmGetCmds> CANCELED: returning %d commands";
    uVar7 = 2;
  }
  tw_msg_dev((byte *)*param_1,uVar7,pcVar11,(ulonglong)uVar9);
  return;
}



===== cm_cmds_log @ 1c00088fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cm_cmds_log(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined1 auStack_b8 [32];
  char local_58 [56];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  pbVar2 = (byte *)*param_1;
  if (pbVar2[0x23c] == 0) {
LAB_1c0008962:
    pcVar8 = "";
    if (tw_crash_dump == '\0') {
      pcVar3 = tw_time_date(local_58);
    }
    else {
      pcVar3 = "";
    }
    tw_msg_dev(pbVar2,0x1000,"CmLogCmds>  %s",pcVar3);
    if (*(char *)((longlong)param_1 + 0x239) != '\0') {
      pcVar8 = "Cmd ";
    }
    tw_msg_dev(pbVar2,0x1000,"CmLogCmds>  DoCapture(%s%s%s%s) TrigState=%s(@%d+%d) Cmds=%d",pcVar8);
    uVar1 = *(ushort *)((longlong)param_1 + 0x214);
    iVar4 = *(int *)((longlong)param_1 + 0xc) % (int)(uint)uVar1;
    uVar6 = (longlong)iVar4;
    if (pbVar2[0x23c] != 0) {
      uVar6 = (longlong)(int)((uVar1 - 0x32) + iVar4) % (longlong)(int)(uint)uVar1 & 0xffffffff;
    }
    uVar7 = (ulonglong)(int)uVar6;
    do {
      uVar5 = (uint)uVar6;
      if ((*(byte *)(uVar7 * 0x1c + param_1[0x44]) & 1) != 0) {
        cm_log_out(param_1,(byte *)((longlong)(int)uVar5 * 0x1c + param_1[0x44]),uVar5,pcVar8,-0x10)
        ;
      }
      uVar6 = (ulonglong)(uVar5 + 1);
      uVar7 = uVar7 + 1;
      if ((longlong)(ulonglong)uVar1 <= (longlong)uVar7) {
        uVar6 = 0;
        uVar7 = 0;
      }
    } while (uVar7 != (longlong)iVar4);
  }
  else {
    if ((char)param_1[0x47] == '\0') {
      pcVar8 = "CmLogCmds> Command capture is disabled";
    }
    else {
      if ((char)param_1[0x47] != '\x03') goto LAB_1c0008962;
      pcVar8 = "CmLogCmds> Command capture already triggered";
    }
    tw_msg_dev(pbVar2,8,pcVar8,param_4);
  }
  return;
}



===== cm_cmds_fillone @ 1c0008b10 =====

undefined8 cm_cmds_fillone(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  longlong *plVar7;
  
  plVar2 = (longlong *)0x0;
  puVar5 = param_2;
  if (param_1[0xb8] == 0) {
    plVar2 = tw_pendio_dolock(*param_1,2);
    if (plVar2 == (longlong *)0x0) {
      return 0;
    }
    param_1[0xb8] = (longlong)plVar2;
    param_1[0xb9] = plVar2[5];
    puVar5 = (undefined8 *)((ulonglong)*(uint *)(plVar2 + 6) % (ulonglong)tw_cmon_cmdsize);
    *(uint *)(param_1 + 0xba) = *(uint *)(plVar2 + 6) / tw_cmon_cmdsize;
  }
  lVar1 = param_1[0xb8];
  puVar3 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x12)),
                           CONCAT71((int7)((ulonglong)puVar5 >> 8),*(undefined1 *)(lVar1 + 0x13)),
                           *(uint *)(lVar1 + 0x14),*(byte *)(lVar1 + 0x18),
                           (undefined4 *)(lVar1 + 0x104));
  uVar6 = 0x2000;
  tw_msg_dev((byte *)*param_1,0x2000,"CmFillCmd> Fill: %s (%d left)",puVar3);
  uVar4 = param_2[1];
  puVar5 = (undefined8 *)param_1[0xb9];
  *puVar5 = *param_2;
  puVar5[1] = uVar4;
  puVar5[2] = param_2[2];
  *(undefined4 *)(puVar5 + 3) = *(undefined4 *)(param_2 + 3);
  *(int *)(param_1 + 0xba) = (int)param_1[0xba] + -1;
  param_1[0xb9] = param_1[0xb9] + 0x1c;
  if ((int)param_1[0xba] < 1) {
    lVar1 = param_1[0xb8];
    puVar3 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x12)),
                             CONCAT71((int7)((ulonglong)uVar6 >> 8),*(undefined1 *)(lVar1 + 0x13)),
                             *(uint *)(lVar1 + 0x14),*(byte *)(lVar1 + 0x18),
                             (undefined4 *)(lVar1 + 0x104));
    tw_msg_dev((byte *)*param_1,0x2000,"CmFillCmd> Done: %s",puVar3);
    plVar2 = (longlong *)param_1[0xb8];
    param_1[0xb8] = 0;
    param_1[0xb9] = 0;
    *(undefined4 *)(param_1 + 0xba) = 0;
    tw_pendio_unlock(*param_1,plVar2);
    uVar4 = 0;
    plVar7 = plVar2;
    tw_pendio_delete((longlong *)*param_1,plVar2,'\0');
    uVar4 = tw_request_finish(plVar2,plVar7,uVar4,(ulonglong)puVar3);
  }
  else {
    uVar4 = tw_pendio_unlock(*param_1,plVar2);
  }
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== FUN_1c0008c84 @ 1c0008c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1c0008c84(undefined8 *param_1,ushort param_2,undefined8 param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined1 auStackY_f8 [32];
  char local_c8 [160];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  *(undefined1 *)(param_1 + 0x47) = 2;
  *(ushort *)((longlong)param_1 + 0x23e) = param_2;
  pbVar1 = (byte *)((ulonglong)param_2 * 0x1c + param_1[0x44]);
  *pbVar1 = *pbVar1 | 0x20;
  *(undefined4 *)((longlong)param_1 + 0x2c) = *(undefined4 *)(pbVar1 + 0x18);
  if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
    cm_log_trig(param_1,0,"Started");
  }
  if ((*(ushort *)(param_1 + 3) & 0x100) != 0) {
    uVar2 = 0x96;
    tw_string(local_c8,0x96,"CmdMon Trigger: %s",param_3);
    tw_aen_make((byte *)*param_1,uVar2,param_2,0xdd0c,local_c8);
  }
  return;
}



===== FUN_1c0008d40 @ 1c0008d40 =====

ulonglong FUN_1c0008d40(undefined8 *param_1,longlong param_2)

{
  char *pcVar1;
  ushort uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  
  if (*(char *)(param_1 + 0x47) == '\x02') {
    if (*(char *)(param_1 + 0x48) != '\0') {
      in_RAX = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
      if ((*(uint *)((longlong)param_1 + 0x14) & 4) != 0) {
        in_RAX = cm_log_trig(param_1,param_2,"Capture");
      }
      pcVar1 = (char *)(param_1 + 0x48);
      *pcVar1 = *pcVar1 + -1;
      if (*pcVar1 != '\0') goto LAB_1c0008d52;
    }
    uVar2 = *(ushort *)(param_1 + 3);
    uVar3 = (ulonglong)uVar2;
    if ((uVar2 & 0x10) == 0) {
      *(undefined1 *)(param_1 + 0x47) = 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x47) = 3;
    }
    if ((uVar2 & 0x20) != 0) {
      *(undefined1 *)((longlong)param_1 + 0x23a) = 0;
    }
    if ((uVar2 & 0x40) != 0) {
      *(undefined1 *)((longlong)param_1 + 0x23b) = 0;
    }
    if ((char)uVar2 < '\0') {
      *(undefined1 *)((longlong)param_1 + 0x23c) = 0;
    }
    if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
      uVar3 = cm_log_trig(param_1,0,"Stopped");
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  else {
LAB_1c0008d52:
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  return uVar3;
}



===== cm_trig_check @ 1c0008dd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong cm_trig_check(undefined8 *param_1,longlong *param_2,longlong param_3,char param_4)

{
  byte bVar1;
  undefined7 uVar2;
  ulonglong uVar3;
  char cVar4;
  undefined7 uVar5;
  char *pcVar6;
  uint uVar7;
  undefined1 auStackY_98 [32];
  char local_58 [24];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = (undefined7)((ulonglong)param_1 >> 8);
  cVar4 = '\0';
  pcVar6 = (char *)0x0;
  bVar1 = *(byte *)((longlong)param_1 + 0x29);
  uVar5 = (undefined7)((ulonglong)param_2 >> 8);
  if ((bVar1 == 0) || (*(char *)((longlong)param_1 + 0x239) == '\0')) {
    return local_40 & 0xffffffffffffff00;
  }
  uVar3 = local_40;
  if (*(char *)(param_1 + 0x47) == '\x01') {
    uVar3 = (ulonglong)*(uint *)(param_3 + 0x14);
    uVar7 = *(int *)(param_3 + 0x18) - *(uint *)(param_3 + 0x14);
    if ((bVar1 & 0x10) == 0) {
      if (((bVar1 & 1) == 0) || (*(char *)((longlong)param_2 + 0x4a) == '\0')) {
        if (((bVar1 & 2) == 0) ||
           (uVar3 = (ulonglong)*(ushort *)((longlong)param_1 + 0x1e),
           uVar7 <= *(ushort *)((longlong)param_1 + 0x1e))) {
          if (((bVar1 & 4) == 0) || (*(short *)((longlong)param_2 + 0x3c) == 0)) goto LAB_1c0009078;
          if (param_4 == '\0') {
            pcVar6 = "Error";
            if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
              tw_xlate_opcode(CONCAT71(uVar2,*(undefined1 *)(param_3 + 1)),
                              CONCAT71(uVar5,*(undefined1 *)(param_3 + 2)),*(uint *)(param_3 + 4),
                              *(byte *)(param_3 + 3),(undefined4 *)((longlong)param_2 + 0x104));
              cm_str_idval(*(ushort *)(param_2 + 2),'\0',local_58);
              tw_msg_req(param_2,0x1000,"CmTrigger> %s: Id=%s Msecs=%u Err=0x%02X %s","Error");
            }
            *(undefined1 *)((longlong)param_1 + 0x29) = 4;
            uVar3 = (ulonglong)*(ushort *)((longlong)param_2 + 0x3c);
            *(uint *)(param_1 + 6) = (uint)*(ushort *)((longlong)param_2 + 0x3c);
          }
        }
        else if (param_4 == '\0') {
          uVar3 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
          pcVar6 = "LCT";
          if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
            tw_xlate_opcode(CONCAT71(uVar2,*(undefined1 *)(param_3 + 1)),
                            CONCAT71(uVar5,*(undefined1 *)(param_3 + 2)),*(uint *)(param_3 + 4),
                            *(byte *)(param_3 + 3),(undefined4 *)((longlong)param_2 + 0x104));
            cm_str_idval(*(ushort *)(param_2 + 2),'\0',local_58);
            uVar3 = tw_msg_req(param_2,0x1000,"CmTrigger> %s: Id=%s Msecs=%u %s","LCT");
          }
          *(undefined1 *)((longlong)param_1 + 0x29) = 2;
          *(uint *)(param_1 + 6) = uVar7;
        }
      }
      else if (param_4 == '\0') {
        uVar3 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
        pcVar6 = "Opcode";
        if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
          tw_xlate_opcode(CONCAT71(uVar2,*(undefined1 *)(param_3 + 1)),
                          CONCAT71(uVar5,*(undefined1 *)(param_3 + 2)),*(uint *)(param_3 + 4),
                          *(byte *)(param_3 + 3),(undefined4 *)((longlong)param_2 + 0x104));
          cm_str_idval(*(ushort *)(param_2 + 2),'\0',local_58);
          uVar3 = tw_msg_req(param_2,0x1000,"CmTrigger> %s: Id=%s Msecs=%u %s","Opcode");
        }
        *(undefined1 *)((longlong)param_1 + 0x29) = 1;
        uVar3 = CONCAT71((int7)(uVar3 >> 8),*(undefined1 *)((longlong)param_2 + 0x4b));
        *(undefined1 *)((longlong)param_1 + 0x2b) = *(undefined1 *)((longlong)param_2 + 0x4b);
      }
    }
    else if (param_4 == '\0') {
      uVar3 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
      pcVar6 = "Request";
      if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
        tw_xlate_opcode(CONCAT71(uVar2,*(undefined1 *)(param_3 + 1)),
                        CONCAT71(uVar5,*(undefined1 *)(param_3 + 2)),*(uint *)(param_3 + 4),
                        *(byte *)(param_3 + 3),(undefined4 *)((longlong)param_2 + 0x104));
        cm_str_idval(*(ushort *)(param_2 + 2),'\0',local_58);
        uVar3 = tw_msg_req(param_2,0x1000,"CmTrigger> %s: Id=%s Msecs=%u %s","Request");
      }
      *(undefined1 *)((longlong)param_1 + 0x29) = 0x10;
    }
    cVar4 = '\x01';
  }
LAB_1c0009078:
  if (param_4 == '\0') {
    if (cVar4 != '\0') {
      FUN_1c0008c84(param_1,*(ushort *)((longlong)param_2 + 0x6a),pcVar6);
    }
    uVar3 = FUN_1c0008d40(param_1,(longlong)param_2);
  }
  else {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),cVar4);
  }
  return uVar3;
}



===== cm_trig_send @ 1c00090c8 =====

void cm_trig_send(longlong *param_1)

{
  longlong *plVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  undefined8 uVar6;
  
  lVar3 = *param_1;
  plVar1 = tw_pendio_dolock(lVar3,3);
  if (plVar1 != (longlong *)0x0) {
    uVar5 = *(uint *)(plVar1 + 6) / tw_cmon_cmdsize;
    puVar2 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar3 >> 8),
                                      *(undefined1 *)((longlong)plVar1 + 0x12)),
                             CONCAT71((int7)((ulonglong)((longlong)plVar1 + 0x104) >> 8),
                                      *(undefined1 *)((longlong)plVar1 + 0x13)),
                             *(uint *)((longlong)plVar1 + 0x14),*(byte *)(plVar1 + 3),
                             (undefined4 *)((longlong)plVar1 + 0x104));
    tw_msg_dev((byte *)*param_1,0x1000,"CmDoneTrig> %s: count=%d",puVar2);
    cm_cmds_get(param_1,uVar5,(undefined8 *)plVar1[5]);
    tw_pendio_unlock(*plVar1,plVar1);
    uVar6 = 0;
    plVar4 = plVar1;
    tw_pendio_delete((longlong *)*plVar1,plVar1,'\0');
    tw_request_finish(plVar1,plVar4,uVar6,(ulonglong)puVar2);
  }
  return;
}



===== cm_trig_reset @ 1c0009178 =====

ulonglong cm_trig_reset(longlong *param_1,char param_2,char *param_3,char *param_4)

{
  undefined2 uVar1;
  ulonglong in_RAX;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  ushort local_res8 [4];
  
  if (((char)param_1[0x47] == '\x01') &&
     (in_RAX = CONCAT71((int7)(in_RAX >> 8),*(byte *)((longlong)param_1 + 0x29)),
     (*(byte *)((longlong)param_1 + 0x29) & 8) != 0)) {
    if ((*(uint *)((longlong)param_1 + 0x14) & 2) != 0) {
      param_4 = "Internal";
      param_3 = "CmTrigger> %s Reset";
      if (param_2 != '\0') {
        param_4 = "System";
      }
      tw_msg_dev((byte *)*param_1,0x1000,"CmTrigger> %s Reset",param_4);
    }
    in_RAX = cm_cmds_addone(param_1,local_res8,param_3,param_4);
    if ((char)in_RAX != '\0') {
      puVar4 = (undefined1 *)((ulonglong)local_res8[0] * 0x1c + param_1[0x44]);
      *puVar4 = 1;
      *(undefined2 *)(puVar4 + 10) = 0xffff;
      if (param_2 == '\0') {
        *(undefined2 *)(puVar4 + 1) = 0x4004;
        *(undefined4 *)(puVar4 + 4) = 0x1c;
      }
      else {
        *(undefined2 *)(puVar4 + 1) = 0x101;
        *(undefined4 *)(puVar4 + 4) = 0x12;
      }
      *(undefined2 *)(puVar4 + 8) = 0xffff;
      uVar1 = *(undefined2 *)(*param_1 + 0x2a4);
      *(undefined4 *)(puVar4 + 0x10) = 0;
      *(undefined2 *)(puVar4 + 0xc) = uVar1;
      lVar2 = tw_time_msecs();
      *(int *)(puVar4 + 0x14) = (int)lVar2;
      *(int *)(puVar4 + 0x18) = (int)lVar2;
      *(undefined1 *)((longlong)param_1 + 0x29) = 8;
      uVar3 = FUN_1c0008c84(param_1,local_res8[0],"Reset");
      if (((char)param_1[0x48] == '\0') && (uVar3 = FUN_1c0008d40(param_1,0), (char)uVar3 != '\0'))
      {
        uVar3 = cm_trig_send(param_1);
      }
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== FUN_1c0009298 @ 1c0009298 =====

void FUN_1c0009298(int param_1,int param_2,int param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  
  uVar1 = *param_4;
  iVar3 = param_2 - param_3;
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  uVar5 = param_4[0xc] - param_3;
  puVar2 = param_4 + 3;
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  lVar4 = 4;
  param_4[1] = (param_4[1] * 1000) / uVar5;
  param_4[2] = param_4[2] / uVar5;
  do {
    *puVar2 = *puVar2 / uVar1;
    puVar2 = puVar2 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  param_4[0xb] = param_4[0xb] + iVar3;
  if (param_5[1] == 0) {
    param_5[1] = param_4[1];
  }
  else {
    param_5[1] = ((100 - param_1) * param_5[1] + param_4[1] * param_1) / 100;
  }
  if (param_5[2] == 0) {
    param_5[2] = param_4[2];
  }
  else {
    param_5[2] = ((100 - param_1) * param_5[2] + param_4[2] * param_1) / 100;
  }
  if (param_5[3] == 0) {
    param_5[3] = param_4[3];
  }
  else {
    param_5[3] = ((100 - param_1) * param_5[3] + param_4[3] * param_1) / 100;
  }
  if (param_5[4] == 0) {
    param_5[4] = param_4[4];
  }
  else {
    param_5[4] = ((100 - param_1) * param_5[4] + param_4[4] * param_1) / 100;
  }
  if (param_5[5] == 0) {
    param_5[5] = param_4[5];
  }
  else {
    param_5[5] = ((100 - param_1) * param_5[5] + param_4[5] * param_1) / 100;
  }
  if (param_5[6] == 0) {
    param_5[6] = param_4[6];
  }
  else {
    param_5[6] = ((100 - param_1) * param_5[6] + param_4[6] * param_1) / 100;
  }
  if ((uint)param_5[7] < param_4[7]) {
    param_5[7] = param_4[7];
  }
  if ((uint)param_5[8] < param_4[8]) {
    param_5[8] = param_4[8];
  }
  if ((uint)param_5[9] < param_4[9]) {
    param_5[9] = param_4[9];
  }
  if ((uint)param_5[10] < param_4[10]) {
    param_5[10] = param_4[10];
  }
  *param_5 = *param_5 + uVar1;
  param_5[0xb] = param_5[0xb] + iVar3;
  param_5[0xc] = param_2;
  return;
}



===== cm_aves_addone @ 1c0009484 =====

longlong cm_aves_addone(longlong param_1,longlong param_2,uint param_3)

{
  uint *_Dst;
  uint *_Dst_00;
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  void *pvVar5;
  uint uVar6;
  uint *puVar7;
  longlong lVar8;
  
  _Dst = (uint *)(param_1 + 0x2b4);
  puVar7 = _Dst;
  if ((*(byte *)(param_2 + 2) & 0x10) == 0) goto LAB_1c00094f4;
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 == 8) {
LAB_1c00094ed:
    puVar7 = (uint *)(param_1 + 0x24c);
  }
  else {
    if (iVar2 != 10) {
      if (iVar2 == 0x28) goto LAB_1c00094ed;
      if (iVar2 != 0x2a) {
        if (iVar2 == 0x88) goto LAB_1c00094ed;
        if (iVar2 != 0x8a) {
          if (iVar2 == 0xa8) goto LAB_1c00094ed;
          if (iVar2 != 0xaa) goto LAB_1c00094f4;
        }
      }
    }
    puVar7 = (uint *)(param_1 + 0x280);
  }
LAB_1c00094f4:
  lVar4 = tw_time_msecs();
  *puVar7 = *puVar7 + 1;
  puVar7[1] = puVar7[1] + 1;
  puVar7[2] = puVar7[2] + *(int *)(param_2 + 0x10);
  puVar7[3] = puVar7[3] + *(int *)(param_2 + 0x10);
  puVar7[4] = puVar7[4] + (uint)*(ushort *)(param_2 + 0xe);
  puVar7[5] = puVar7[5] + (uint)*(ushort *)(param_2 + 0xc);
  puVar7[6] = puVar7[6] + param_3;
  uVar6 = (uint)lVar4;
  puVar7[0xc] = uVar6;
  if (puVar7[7] < *(uint *)(param_2 + 0x10)) {
    puVar7[7] = *(uint *)(param_2 + 0x10);
  }
  if (puVar7[8] < (uint)*(ushort *)(param_2 + 0xe)) {
    puVar7[8] = (uint)*(ushort *)(param_2 + 0xe);
  }
  if (puVar7[9] < (uint)*(ushort *)(param_2 + 0xc)) {
    puVar7[9] = (uint)*(ushort *)(param_2 + 0xc);
  }
  if (puVar7[10] < param_3) {
    puVar7[10] = param_3;
  }
  *(short *)(param_1 + 900) = *(short *)(param_1 + 900) + 1;
  if (*(ushort *)(param_1 + 900) < *(ushort *)(param_1 + 0x214)) {
    lVar4 = (ulonglong)(byte)(*(ushort *)(param_1 + 900) >> 8) << 8;
  }
  else {
    puVar7 = (uint *)(param_1 + 0x24c);
    if (*puVar7 != 0) {
      FUN_1c0009298((uint)*(byte *)(param_1 + 0x1d),uVar6,*(int *)(param_1 + 0x388),puVar7,
                    (int *)(param_1 + 0x2e8));
    }
    _Dst_00 = (uint *)(param_1 + 0x280);
    if (*_Dst_00 != 0) {
      FUN_1c0009298((uint)*(byte *)(param_1 + 0x1d),uVar6,*(int *)(param_1 + 0x388),_Dst_00,
                    (int *)(param_1 + 0x31c));
    }
    if (*_Dst != 0) {
      FUN_1c0009298((uint)*(byte *)(param_1 + 0x1d),uVar6,*(int *)(param_1 + 0x388),_Dst,
                    (int *)(param_1 + 0x350));
    }
    lVar4 = *(longlong *)(param_1 + 0x230);
    uVar3 = *(undefined8 *)(param_1 + 0x254);
    lVar8 = (ulonglong)*(ushort *)(param_1 + 0x24a) * 0x9c;
    *(undefined8 *)(lVar8 + lVar4) = *(undefined8 *)puVar7;
    ((undefined8 *)(lVar8 + lVar4))[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x264);
    puVar1 = (undefined8 *)(lVar8 + 0x10 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x25c);
    puVar1[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x274);
    puVar1 = (undefined8 *)(lVar8 + 0x20 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x26c);
    puVar1[1] = uVar3;
    *(undefined4 *)(lVar8 + 0x30 + lVar4) = *(undefined4 *)(param_1 + 0x27c);
    lVar4 = *(longlong *)(param_1 + 0x230);
    uVar3 = *(undefined8 *)(param_1 + 0x288);
    puVar1 = (undefined8 *)(lVar8 + 0x34 + lVar4);
    *puVar1 = *(undefined8 *)_Dst_00;
    puVar1[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x298);
    puVar1 = (undefined8 *)(lVar8 + 0x44 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x290);
    puVar1[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x2a8);
    puVar1 = (undefined8 *)(lVar8 + 0x54 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x2a0);
    puVar1[1] = uVar3;
    *(undefined4 *)(lVar8 + 100 + lVar4) = *(undefined4 *)(param_1 + 0x2b0);
    lVar4 = *(longlong *)(param_1 + 0x230);
    uVar3 = *(undefined8 *)(param_1 + 700);
    puVar1 = (undefined8 *)(lVar8 + 0x68 + lVar4);
    *puVar1 = *(undefined8 *)_Dst;
    puVar1[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x2cc);
    puVar1 = (undefined8 *)(lVar8 + 0x78 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x2c4);
    puVar1[1] = uVar3;
    uVar3 = *(undefined8 *)(param_1 + 0x2dc);
    puVar1 = (undefined8 *)(lVar8 + 0x88 + lVar4);
    *puVar1 = *(undefined8 *)(param_1 + 0x2d4);
    puVar1[1] = uVar3;
    *(undefined4 *)(lVar8 + 0x98 + lVar4) = *(undefined4 *)(param_1 + 0x2e4);
    memset(puVar7,0,0x34);
    memset(_Dst_00,0,0x34);
    pvVar5 = memset(_Dst,0,0x34);
    *(short *)(param_1 + 0x24a) = *(short *)(param_1 + 0x24a) + 1;
    if (*(ushort *)(param_1 + 0x218) <= *(ushort *)(param_1 + 0x24a)) {
      *(undefined2 *)(param_1 + 0x24a) = 0;
    }
    *(undefined2 *)(param_1 + 900) = 0;
    lVar4 = CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
    *(uint *)(param_1 + 0x388) = uVar6;
  }
  return lVar4;
}



===== cm_hist_oper @ 1c0009710 =====

void cm_hist_oper(longlong param_1,int param_2,char param_3)

{
  int *piVar1;
  
  if (param_3 == '\x01') {
    piVar1 = (int *)(param_1 + 0x39c);
    goto LAB_1c00097d4;
  }
  if (param_3 == '\x02') {
    piVar1 = (int *)(param_1 + 0x3a0);
    goto LAB_1c00097d4;
  }
  if (param_3 == '\x04') {
    piVar1 = (int *)(param_1 + 0x3a4);
    goto LAB_1c00097d4;
  }
  if (param_3 == '\b') {
    piVar1 = (int *)(param_1 + 0x3a8);
    goto LAB_1c00097d4;
  }
  if (param_3 != '\x10') {
    if (param_3 == ' ') {
      piVar1 = (int *)(param_1 + 0x398);
    }
    else if (param_3 == '@') {
      piVar1 = (int *)(param_1 + 0x3b0);
    }
    else {
      if (param_3 != -0x80) {
        return;
      }
      piVar1 = (int *)(param_1 + 0x3ac);
    }
    goto LAB_1c00097d4;
  }
  if (param_2 == 8) {
LAB_1c00097a9:
    piVar1 = (int *)(param_1 + 0x38c);
  }
  else {
    if (param_2 != 10) {
      if (param_2 == 0x28) goto LAB_1c00097a9;
      if (param_2 != 0x2a) {
        if (param_2 == 0x88) goto LAB_1c00097a9;
        if (param_2 != 0x8a) {
          if (param_2 == 0xa8) goto LAB_1c00097a9;
          if (param_2 != 0xaa) {
            piVar1 = (int *)(param_1 + 0x394);
            goto LAB_1c00097d4;
          }
        }
      }
    }
    piVar1 = (int *)(param_1 + 0x390);
  }
LAB_1c00097d4:
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return;
}



===== cm_aves_log @ 1c00097e4 =====

void cm_aves_log(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  
  tw_msg_dev((byte *)*param_1,0x1000,"%s> Read I/O Only:","CmLogAves");
  iVar1 = 0;
  if (*(short *)(param_1 + 0x43) != 0) {
    lVar2 = 0;
    do {
      if (*(int *)(lVar2 + param_1[0x46]) != 0) {
        cm_log_aves(param_1,(undefined4 *)((longlong)iVar1 * 0x9c + param_1[0x46]));
      }
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 0x9c;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0x43));
  }
  tw_msg_dev((byte *)*param_1,0x1000,"%s> Write I/O Only:","CmLogAves");
  iVar1 = 0;
  if (*(short *)(param_1 + 0x43) != 0) {
    lVar2 = 0;
    do {
      if (*(int *)(lVar2 + 0x34 + param_1[0x46]) != 0) {
        cm_log_aves(param_1,(undefined4 *)(param_1[0x46] + 0x34 + (longlong)iVar1 * 0x9c));
      }
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 0x9c;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0x43));
  }
  tw_msg_dev((byte *)*param_1,0x1000,"%s> NonRW I/O Only:","CmLogAves");
  iVar1 = 0;
  if (*(short *)(param_1 + 0x43) != 0) {
    lVar2 = 0;
    do {
      if (*(int *)(lVar2 + 0x68 + param_1[0x46]) != 0) {
        cm_log_aves(param_1,(undefined4 *)(param_1[0x46] + 0x68 + (longlong)iVar1 * 0x9c));
      }
      iVar1 = iVar1 + 1;
      lVar2 = lVar2 + 0x9c;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0x43));
  }
  return;
}



===== cm_lcts_insert @ 1c000993c =====

char cm_lcts_insert(longlong *param_1,byte *param_2,uint param_3,undefined8 param_4,void *param_5)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  longlong lVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  undefined7 uVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  cVar8 = (char)param_4;
  uVar10 = (undefined7)((ulonglong)param_4 >> 8);
  cVar7 = '\0';
  if (param_3 < *(ushort *)((longlong)param_1 + 0x1e)) {
    return '\0';
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0x216);
  uVar5 = 0;
  cVar9 = cVar8;
  if (uVar1 != 0) {
    piVar4 = (int *)(param_1[0x45] + 0x14);
    do {
      if ((*(byte *)(piVar4 + -5) & 1) == 0) goto LAB_1c0009a01;
      if ((uint)(piVar4[1] - *piVar4) < param_3) {
        if (cVar8 == '\0') {
          iVar3 = uVar1 - 1;
          if ((int)uVar5 < iVar3) {
            lVar6 = (longlong)iVar3 * 0x2c;
            lVar12 = (longlong)(int)(uVar1 - 2) * 0x2c;
            uVar11 = (ulonglong)(iVar3 - uVar5);
            do {
              memcpy((void *)(lVar6 + param_1[0x45]),(void *)(lVar12 + param_1[0x45]),0x2c);
              lVar6 = lVar6 + -0x2c;
              lVar12 = lVar12 + -0x2c;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
        }
        goto LAB_1c0009a01;
      }
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 0xb;
    } while ((int)uVar5 < (int)(uint)uVar1);
  }
LAB_1c0009a04:
  if ((cVar8 == '\0') && (cVar7 != '\0')) {
    *param_2 = *param_2 | 0x10;
    if ((*(uint *)((longlong)param_1 + 0x14) & 1) != 0) {
      cm_log_out(param_1,param_2,uVar5,CONCAT71(uVar10,cVar9),'0');
    }
    lVar12 = param_1[0x45];
    uVar2 = *(undefined8 *)(param_2 + 8);
    lVar6 = (longlong)(int)uVar5 * 0x2c;
    *(undefined8 *)(lVar12 + lVar6) = *(undefined8 *)param_2;
    ((undefined8 *)(lVar12 + lVar6))[1] = uVar2;
    *(undefined8 *)(lVar12 + 0x10 + lVar6) = *(undefined8 *)(param_2 + 0x10);
    *(undefined4 *)(lVar12 + 0x18 + lVar6) = *(undefined4 *)(param_2 + 0x18);
    memcpy((void *)(param_1[0x45] + 0x1c + lVar6),param_5,0x10);
    *(byte *)(param_1[0x45] + lVar6) = *(byte *)(param_1[0x45] + lVar6) & 0xfd;
    if (*(ushort *)(param_1 + 0x49) < *(ushort *)((longlong)param_1 + 0x216)) {
      *(ushort *)(param_1 + 0x49) = *(ushort *)(param_1 + 0x49) + 1;
    }
  }
  return cVar7;
LAB_1c0009a01:
  cVar7 = '\x01';
  goto LAB_1c0009a04;
}



===== cm_str_idval @ 1c0009acc =====

char * cm_str_idval(ushort param_1,char param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  
  if (param_1 == 0xffff) {
    pcVar2 = "";
    if (param_2 != '\0') {
      pcVar2 = "    ";
    }
    lVar3 = (longlong)param_3 - (longlong)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[lVar3] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    pcVar2 = "%d";
    if (param_2 != '\0') {
      pcVar2 = "%-4d";
    }
    tw_string(param_3,0x14,pcVar2,(ulonglong)param_1);
  }
  return param_3;
}



===== cm_log_trig @ 1c0009b38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cm_log_trig(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined1 auStackY_a8 [32];
  char local_68 [16];
  char local_58 [56];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar3 = 0;
  if (param_2 != 0) {
    uVar3 = 0;
    tw_string(local_68,10,"%s #%d",param_3);
  }
  uVar1 = (uint)*(byte *)((longlong)param_1 + 0x29);
  if (uVar1 == 1) {
    uVar2 = 0;
  }
  else if (uVar1 == 2) {
    uVar2 = 0;
  }
  else if (uVar1 == 4) {
    uVar2 = 0;
  }
  else {
    uVar2 = (ulonglong)(uVar1 - 8);
  }
  if (param_2 == 0) {
    if (tw_crash_dump == '\0') {
      tw_time_date(local_58);
    }
  }
  else {
    tw_xlate_opcode(CONCAT71((int7)(uVar2 >> 8),*(undefined1 *)(param_2 + 0x12)),
                    CONCAT71((int7)((ulonglong)uVar3 >> 8),*(undefined1 *)(param_2 + 0x13)),
                    *(uint *)(param_2 + 0x14),*(byte *)(param_2 + 0x18),
                    (undefined4 *)(param_2 + 0x104));
  }
  tw_msg_dev((byte *)*param_1,0x1000,"%s> %s: Cause=%s Index=%d %s","CmTrigger");
  return;
}



===== cm_log_aves @ 1c0009c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cm_log_aves(undefined8 *param_1,undefined4 *param_2)

{
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_60;
  char *local_58;
  char local_48 [56];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  if (tw_crash_dump == '\0') {
    local_58 = tw_time_date_from_1970secs
                         ((ulonglong)((uint)param_2[0xc] / 1000 + tw_bootup_time),local_48);
  }
  else {
    local_58 = "";
  }
  local_60 = param_2[0xb];
  local_68 = param_2[6];
  local_70 = param_2[5];
  local_78 = param_2[4];
  local_80 = param_2[3];
  local_88 = param_2[2];
  local_90 = param_2[1];
  local_98 = *param_2;
  tw_msg_dev((byte *)*param_1,0x1000,
             "%s>   Cmds=%-4d IO/s=%-3d KB/s=%-6d Len=%-6d SGLs=%-3d Pcmds=%-3d Resp=%-5d Etime=%-5d %s"
             ,"CmLogAves");
  return;
}



===== cm_log_out @ 1c0009d4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cm_log_out(longlong *param_1,byte *param_2,uint param_3,undefined8 param_4,char param_5)

{
  code *pcVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined1 auStackY_298 [32];
  uint local_1e0;
  char local_1a8 [24];
  char local_190 [24];
  char local_178 [56];
  char local_140 [56];
  char local_108 [32];
  undefined4 local_e8 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_298;
  pbVar9 = param_2;
  if ((*param_2 & 0x82) == 2) {
    lVar4 = tw_time_msecs();
    uVar6 = (int)lVar4 - *(int *)(param_2 + 0x14);
  }
  else {
    uVar6 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14);
  }
  pcVar8 = (char *)(ulonglong)uVar6;
  if (((*(uint *)((longlong)param_1 + 0x14) & 0x40000000) == 0) &&
     (*(char *)(*param_1 + 0x23c) == '\0')) {
    local_140[0] = '\0';
  }
  else {
    local_178[0] = '\0';
    if (tw_crash_dump == '\0') {
      tw_time_date_from_1970secs
                ((ulonglong)(*(uint *)(param_2 + 0x18) / 1000 + tw_bootup_time),local_178);
    }
    builtin_strncpy(local_1a8,"          ",0xb);
    lVar4 = -1;
    do {
      lVar5 = lVar4 + 1;
      lVar2 = lVar4 + 1;
      lVar4 = lVar5;
    } while (local_178[lVar2] != '\0');
    iVar7 = 0x15 - (int)lVar5;
    iVar3 = 0;
    if (0 < iVar7) {
      iVar3 = iVar7;
    }
    if (0x13 < (ulonglong)(longlong)iVar3) {
      __report_rangecheckfailure();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    local_190[(longlong)iVar3 - 0x18] = '\0';
    pbVar9 = (byte *)0x0;
    pcVar8 = local_140;
    tw_string(pcVar8,0x32,"%s%s %08X ",local_178);
  }
  if ((*(int *)((longlong)param_1 + 0x14) < 0) || (*(char *)(*param_1 + 0x23c) != '\0')) {
    local_1e0 = *(uint *)(param_2 + 0x14);
  }
  else {
    local_1e0 = 0;
  }
  if (param_3 == 0xffff) {
    builtin_strncpy(local_190,"     ",6);
  }
  else {
    pbVar9 = (byte *)0x0;
    pcVar8 = local_190;
    tw_string(pcVar8,0x14,"%4d)",(ulonglong)param_3);
  }
  tw_xlate_opcode(CONCAT71((int7)((ulonglong)pcVar8 >> 8),param_2[1]),
                  CONCAT71((int7)((ulonglong)pbVar9 >> 8),param_2[2]),*(uint *)(param_2 + 4),
                  param_2[3],local_e8);
  cm_str_idval(*(ushort *)(param_2 + 8),'\x01',local_108);
  tw_msg_cmd((byte *)*param_1,(ushort)param_2[10],(ushort)param_2[0xb],(ulonglong)local_1e0,0x1000,
             "%s %s  Id=%s %s%s=%-6d KB=%-3d %s%s%s%s %s%s%s%s",param_5);
  return;
}



===== cm_log_req @ 1c000a0b4 =====

void cm_log_req(longlong *param_1,byte *param_2,undefined8 param_3)

{
  ushort uVar1;
  
  if ((char)param_1[0xd] == '\0') {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = *(ushort *)((longlong)param_1 + 0x6a);
  }
  cm_log_out((longlong *)(*param_1 + 0xf7e),param_2,(uint)uVar1,param_3,(char)param_3);
  return;
}



===== tw_evtq_add @ 1c000a0ec =====

longlong tw_evtq_add(longlong *param_1,void *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 extraout_var;
  longlong lVar2;
  int iVar3;
  undefined4 *_Dst;
  int iVar4;
  
  iVar4 = (int)param_1[2];
  iVar3 = *(int *)((longlong)param_1 + 0xc);
  _Dst = (undefined4 *)((longlong)iVar4 * 0x80 + *param_1);
  iVar1 = tw_time_1970_secs();
  if (((*(char *)((longlong)_Dst + 0xb) == '\x01') &&
      (*(short *)((longlong)param_2 + 8) == *(short *)(_Dst + 2))) && (iVar1 - _Dst[1] < 0x3c)) {
    lVar2 = CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),1);
  }
  else {
    if ((iVar3 == iVar4) && (*(char *)((longlong)_Dst + 0xb) != '\0')) {
      if (iVar3 < (int)param_1[1] + -1) {
        iVar3 = iVar3 + 1;
      }
      else {
        iVar3 = 0;
      }
      *(int *)((longlong)param_1 + 0xc) = iVar3;
      if (*(char *)((longlong)_Dst + 0xb) == '\x01') {
        *(undefined1 *)((longlong)param_1 + 0x1c) = 1;
        *param_3 = 1;
      }
    }
    else {
      *(int *)(param_1 + 3) = (int)param_1[3] + 1;
    }
    memcpy(_Dst,param_2,0x80);
    *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
    *_Dst = *(undefined4 *)((longlong)param_1 + 0x14);
    _Dst[1] = iVar1;
    *(undefined2 *)((longlong)_Dst + 0xb) = 0x101;
    iVar3 = (int)param_1[1] + -1;
    if (iVar4 < iVar3) {
      iVar4 = iVar4 + 1;
    }
    else {
      iVar4 = 0;
    }
    *(int *)(param_1 + 2) = iVar4;
    lVar2 = (ulonglong)(uint3)((uint)iVar3 >> 8) << 8;
  }
  return lVar2;
}



===== tw_evtq_get_first @ 1c000a1d0 =====

ulonglong tw_evtq_get_first(ulonglong *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  
  iVar1 = *(int *)((longlong)param_1 + 0xc);
  iVar5 = 0;
  iVar2 = (int)param_1[2];
  *param_2 = 0;
  if ((iVar1 == iVar2) && (*(char *)((longlong)iVar2 * 0x80 + 0xb + *param_1) == '\0')) {
    uVar4 = *param_1 & 0xffffffffffffff00;
  }
  else {
    memcpy(param_2,(void *)(*param_1 + (longlong)iVar1 * 0x80),0x80);
    *(undefined1 *)(*param_1 + 0xb + (longlong)iVar1 * 0x80) = 2;
    iVar3 = (int)param_1[1] + -1;
    if (iVar1 < iVar3) {
      iVar5 = iVar1 + 1;
    }
    uVar4 = (ulonglong)CONCAT31((int3)((uint)iVar3 >> 8),iVar5 != iVar2);
  }
  return uVar4;
}



===== tw_evtq_get_last @ 1c000a268 =====

ulonglong tw_evtq_get_last(ulonglong *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  iVar1 = *(int *)((longlong)param_1 + 0xc);
  iVar2 = (int)param_1[2];
  *param_2 = 0;
  if ((iVar1 == iVar2) && (*(char *)((longlong)iVar2 * 0x80 + 0xb + *param_1) == '\0')) {
    uVar3 = *param_1 & 0xffffffffffffff00;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (int)param_1[1];
    }
    lVar4 = (longlong)(iVar2 + -1) * 0x80;
    memcpy(param_2,(void *)(*param_1 + lVar4),0x80);
    uVar3 = *param_1;
    *(undefined1 *)(uVar3 + 0xb + lVar4) = 2;
    uVar3 = CONCAT71((int7)(uVar3 >> 8),iVar2 + -1 != iVar1);
  }
  return uVar3;
}



===== tw_evtq_get_prev @ 1c000a2f0 =====

ulonglong tw_evtq_get_prev(ulonglong *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  void *pvVar5;
  int iVar6;
  uint *_Src;
  bool bVar7;
  
  iVar1 = *(int *)((longlong)param_1 + 0xc);
  iVar6 = (int)param_1[2];
  uVar2 = *param_2;
  *param_2 = 0;
  if ((iVar1 == iVar6) &&
     (in_RAX = *param_1, *(char *)((longlong)iVar6 * 0x80 + 0xb + in_RAX) == '\0')) {
    uVar4 = in_RAX & 0xffffffffffffff00;
  }
  else {
    uVar4 = in_RAX & 0xffffffffffffff00;
    bVar3 = false;
    if (iVar6 == 0) {
      iVar6 = (int)param_1[1] + -1;
    }
    else {
      iVar6 = iVar6 + -1;
    }
    do {
      _Src = (uint *)((longlong)iVar6 * 0x80 + *param_1);
      if (*_Src < uVar2) {
        pvVar5 = memcpy(param_2,_Src,0x80);
        uVar4 = CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
        bVar3 = true;
        *(undefined1 *)((longlong)_Src + 0xb) = 2;
      }
      bVar7 = true;
      if (iVar6 == iVar1) goto LAB_1c000a37d;
      if (iVar6 < 1) {
        iVar6 = (int)param_1[1];
      }
      iVar6 = iVar6 + -1;
    } while (!bVar3);
    bVar7 = iVar6 == iVar1;
LAB_1c000a37d:
    uVar4 = CONCAT71((int7)(uVar4 >> 8),!bVar7);
  }
  return uVar4;
}



===== tw_evtq_get_next @ 1c000a39c =====

ulonglong tw_evtq_get_next(ulonglong *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  uint *_Src;
  ulonglong uVar6;
  
  iVar4 = *(int *)((longlong)param_1 + 0xc);
  uVar5 = (ulonglong)iVar4;
  iVar1 = (int)param_1[2];
  uVar2 = *param_2;
  *param_2 = 0;
  if ((iVar4 == iVar1) && (*(char *)((longlong)iVar1 * 0x80 + 0xb + *param_1) == '\0')) {
    uVar5 = *param_1 & 0xffffffffffffff00;
  }
  else {
    bVar3 = false;
    uVar6 = uVar5;
    do {
      _Src = (uint *)(uVar6 * 0x80 + *param_1);
      if (uVar2 < *_Src) {
        memcpy(param_2,_Src,0x80);
        bVar3 = true;
        *(undefined1 *)((longlong)_Src + 0xb) = 2;
      }
      iVar4 = (int)param_1[1] + -1;
      if ((int)uVar5 < iVar4) {
        uVar5 = (ulonglong)((int)uVar5 + 1);
        uVar6 = uVar6 + 1;
      }
      else {
        uVar5 = 0;
        uVar6 = 0;
      }
    } while ((uVar6 != (longlong)iVar1) && (!bVar3));
    uVar5 = (ulonglong)CONCAT31((int3)((uint)iVar4 >> 8),(int)uVar5 != iVar1);
  }
  return uVar5;
}



===== tw_aen_get @ 1c000a454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_aen_get(byte *param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined1 *puVar3;
  longlong *plVar4;
  uint uVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined1 auStack_1a8 [32];
  uint local_188;
  undefined1 *local_180;
  char *local_178;
  char local_168 [16];
  undefined1 local_158 [8];
  undefined2 local_150;
  byte local_14e;
  undefined1 local_14b;
  undefined1 local_14a [98];
  byte local_e8;
  undefined2 local_e7;
  undefined1 local_d8 [160];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(local_158,0,0x80);
  local_14e = *(byte *)(param_2 + 0x19) & 7;
  local_14b = 0x62;
  local_e8 = *(byte *)(param_2 + 0x18) & 0xf;
  local_e7 = *(undefined2 *)(param_2 + 0x12);
  local_150 = *(undefined2 *)(param_2 + 0x16);
  memcpy(local_14a,(void *)(param_2 + 0x1a),0x62);
  local_168[0] = '\0';
  puVar3 = local_158;
  lVar1 = tw_evtq_add((longlong *)(param_1 + 0xf5e),puVar3,local_168);
  tw_str_parse((char *)(param_2 + 0x1a),puVar3,(longlong)local_d8);
  if (local_14e == 2) {
    uVar5 = 2;
  }
  else if (local_14e == 3) {
    uVar5 = 4;
  }
  else if (local_14e == 4) {
    uVar5 = 8;
  }
  else {
    uVar5 = 1;
  }
  pcVar7 = "";
  local_178 = "";
  if (local_168[0] != '\0') {
    local_178 = "<< OFLOW";
  }
  local_180 = local_d8;
  local_188 = *(uint *)(param_1 + 0xf76);
  if ((char)lVar1 != '\0') {
    pcVar7 = " (Lost)";
  }
  tw_msg_dev(param_1,uVar5,"%sAEN(%d): %s%s",pcVar7);
  *(int *)(param_1 + 0x2e0) = *(int *)(param_1 + 0x2e0) + 1;
  if (uVar5 == 1) {
    pcVar7 = (char *)0x0;
    local_178 = (char *)CONCAT44(local_178._4_4_,CONCAT12(local_e8,local_150) + 0xa0000000);
    local_180 = (undefined1 *)CONCAT44(local_180._4_4_,6);
    local_188 = local_188 & 0xffffff00;
    StorPortLogError(param_1,0);
  }
  plVar2 = tw_pendio_dolock((longlong)param_1,1);
  if (plVar2 != (longlong *)0x0) {
    lVar1 = *(longlong *)(plVar2[1] + 0x18);
    tw_evtq_get_last((ulonglong *)(param_1 + 0xf5e),(undefined4 *)(lVar1 + 0x1c));
    if (*(int *)(lVar1 + 0x1c) == 0) {
      tw_pendio_unlock((longlong)param_1,plVar2);
      tw_msg_dev(param_1,4,"AenGet> No AENs in queue",pcVar7);
    }
    else {
      *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
      if (param_1[0xf7a] != 0) {
        *(int *)(param_1 + 0x2e8) = *(int *)(param_1 + 0x2e8) + 1;
        *(undefined4 *)(lVar1 + 0x14) = 2;
        param_1[0xf7a] = 0;
      }
      tw_pendio_unlock((longlong)param_1,plVar2);
      uVar6 = 0;
      plVar4 = plVar2;
      tw_pendio_delete((longlong *)param_1,plVar2,'\0');
      tw_request_finish(plVar2,plVar4,uVar6,(ulonglong)pcVar7);
    }
  }
  return;
}



===== tw_aen_make @ 1c000a678 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool tw_aen_make(byte *param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4,
                char *param_5)

{
  char cVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  char *local_e0;
  char *local_d8;
  char local_c8 [16];
  undefined1 local_b8 [8];
  undefined2 local_b0;
  undefined1 local_ae;
  undefined1 local_ab;
  char local_aa [6];
  undefined2 auStack_a4 [46];
  undefined1 local_48;
  undefined2 local_47;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  memset(local_b8,0,0x80);
  local_ae = 3;
  local_48 = 0;
  param_5[0x5b] = '\0';
  pcVar3 = param_5;
  local_47 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(longlong)(local_aa + -(longlong)param_5)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  lVar2 = -1;
  do {
    lVar4 = lVar2;
    lVar2 = lVar4 + 1;
  } while (param_5[lVar4 + 1] != '\0');
  builtin_strncpy(local_aa + lVar4 + 2,"3war",4);
  *(undefined2 *)((longlong)auStack_a4 + lVar4) = 0x65;
  local_ab = 0x62;
  local_c8[0] = '\0';
  local_b0 = param_4;
  lVar2 = tw_evtq_add((longlong *)(param_1 + 0xf5e),local_b8,local_c8);
  pcVar3 = "";
  local_d8 = "";
  if (local_c8[0] != '\0') {
    local_d8 = "<< OFLOW";
  }
  local_e8 = *(undefined4 *)(param_1 + 0xf76);
  local_e0 = param_5;
  if ((char)lVar2 != '\0') {
    pcVar3 = " (Lost)";
  }
  tw_msg_dev(param_1,4,"%sAEN(%d): %s%s",pcVar3);
  return (char)lVar2 == '\0';
}



===== tw_stats_display @ 1c000a794 =====

void tw_stats_display(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  
  tw_msg_dev(param_1,8,"Driver Statistics:",param_4);
  tw_msg_dev(param_1,8,"Max:  Posted=%u Pended=%u Reqs/Int=%u",(ulonglong)*(uint *)(param_1 + 0x2c0)
            );
  tw_msg_dev(param_1,8,"Busy: Count=%u Builds=%u Starts=%u Time=%u msecs",
             (ulonglong)*(uint *)(param_1 + 0x2d0));
  tw_msg_dev(param_1,8,"Aens: Received=%u Retrieved=%u Overflows=%u",
             (ulonglong)*(uint *)(param_1 + 0x2e0));
  iVar8 = *(uint *)(param_1 + 0x2ec) + *(int *)(param_1 + 0x2f0);
  if (iVar8 != 0) {
    tw_msg_dev(param_1,8,"Reset Information: System=%u Internal=%u",
               (ulonglong)*(uint *)(param_1 + 0x2ec));
    uVar7 = 0;
    lVar5 = 0;
    if (0 < iVar8) {
      pbVar10 = param_1 + 0x2f9;
      do {
        if (*(int *)(pbVar10 + -5) == 0) break;
        tw_msg_dev(param_1,8,
                   "  %d) %08X %s Pended=%-2d Posted=%-3d Recovered=%-3d  Msecs: Complete=%-6d SincePrev=%u"
                   ,uVar7);
        uVar7 = (ulonglong)((int)uVar7 + 1);
        lVar5 = lVar5 + 1;
        pbVar10 = pbVar10 + 0x19;
      } while (lVar5 < iVar8);
    }
  }
  bVar2 = false;
  puVar4 = (uint *)(param_1 + 0x7de);
  uVar9 = 0;
  uVar6 = 0;
  uVar3 = 0;
  do {
    uVar1 = *puVar4;
    if ((uVar1 != 0) && ((uVar6 == 0 || (uVar1 < uVar6)))) {
      bVar2 = true;
      uVar6 = uVar1;
      uVar9 = uVar3;
    }
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 8;
  } while (uVar3 < 0x3c);
  if (bVar2) {
    tw_msg_dev(param_1,8,"Running Request/ISR Information: (starti=%d)",(ulonglong)uVar9);
    uVar7 = 0;
    do {
      if (*(int *)(param_1 + (ulonglong)uVar9 * 0x20 + 0x7de) != 0) {
        tw_msg_dev(param_1,8,
                   "  %2d) %08X ISR=%-8d Reqs=%-8d Posted=%-8d Pended=%-6d IOCTL=%-6d IOpass=%-6d Busy=%u"
                   ,uVar7);
        uVar9 = uVar9 + 1 & -(uint)(uVar9 + 1 < 0x3c);
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while ((int)uVar6 < 0x3c);
  }
  return;
}



===== FUN_1c000a9fc @ 1c000a9fc =====

int FUN_1c000a9fc(longlong param_1,ulonglong param_2,undefined1 *param_3,int param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  
  uVar6 = param_2 & 0xffffffff;
  iVar4 = 0;
  uVar2 = param_2;
  tw_time_msecs();
  puVar7 = &s_PendList;
  if (param_3 != (undefined1 *)0x0) {
    puVar7 = param_3;
  }
  if ((int)param_2 == 0) {
    uVar6 = 8;
  }
  iVar5 = 0;
  lVar3 = 0;
  while( true ) {
    if (-1 < param_4) {
      lVar3 = (longlong)param_4;
      iVar5 = param_4;
    }
    lVar1 = *(longlong *)(param_1 + 0x1556 + lVar3 * 0x18);
    if ((lVar1 != 0) && (iVar4 = iVar4 + 1, (*(uint *)(param_1 + 0x296) & 0x100000) != 0)) {
      tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x12)),
                      CONCAT71((int7)(uVar2 >> 8),*(undefined1 *)(lVar1 + 0x13)),
                      *(uint *)(lVar1 + 0x14),*(byte *)(lVar1 + 0x18),(undefined4 *)(lVar1 + 0x104))
      ;
      uVar2 = uVar6;
      tw_msg_req(*(longlong **)(param_1 + 0x1556 + lVar3 * 0x18),(uint)uVar6,
                 "%s: %d) Id=%-3d Time=%08X Msecs=%-6d Tout=%-6d %s%s",puVar7);
    }
    if (-1 < param_4) break;
    iVar5 = iVar5 + 1;
    lVar3 = lVar3 + 1;
    if (10 < iVar5) {
      return iVar4;
    }
  }
  return iVar4;
}



===== tw_pendio_timer @ 1c000ab50 =====

/* WARNING: Removing unreachable block (ram,0x0001c000ac77) */

void tw_pendio_timer(byte *param_1)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  byte *pbVar7;
  uint uVar8;
  longlong *plVar9;
  
  if (param_1[0x23c] == 0) {
    lVar2 = tw_time_msecs();
    uVar8 = 0xffffffff;
    pbVar7 = param_1 + 0x1556;
    bVar1 = false;
    uVar6 = 0;
    do {
      iVar5 = (int)uVar6;
      if ((*(longlong *)pbVar7 != 0) && (*(int *)(pbVar7 + 0xc) != 0)) {
        uVar3 = *(int *)(pbVar7 + 0xc) + *(int *)(pbVar7 + 8);
        if ((uint)lVar2 < uVar3) {
          if ((!bVar1) && (uVar3 = uVar3 - (uint)lVar2, uVar3 < uVar8)) {
            tw_msg_dev(param_1,0x200,"%s> %d) New Timeout=%d msecs",&s_PendTimer);
            uVar8 = uVar3;
          }
        }
        else {
          uVar4 = 1;
          FUN_1c000a9fc((longlong)param_1,1,&s_PendTimer,iVar5);
          plVar9 = *(longlong **)pbVar7;
          pbVar7[0] = 0;
          pbVar7[1] = 0;
          pbVar7[2] = 0;
          pbVar7[3] = 0;
          pbVar7[4] = 0;
          pbVar7[5] = 0;
          pbVar7[6] = 0;
          pbVar7[7] = 0;
          if (plVar9[1] != 0) {
            uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),0xb);
            tw_srb_status(plVar9[1],'\v');
          }
          tw_request_finish(plVar9,uVar4,plVar9,uVar6);
          bVar1 = true;
        }
      }
      uVar3 = iVar5 + 1;
      uVar6 = (ulonglong)uVar3;
      pbVar7 = pbVar7 + 0x18;
    } while ((int)uVar3 < 0xb);
    if (bVar1) {
      tw_fwstate_exec(param_1,2);
    }
    else if (uVar8 == 0xffffffff) {
      tw_msg_dev(param_1,0x100,"%s> Timeout expired: %d in queue",&s_PendTimer);
    }
    else {
      tw_timer_start(param_1,uVar8,0,tw_pendio_timer);
    }
  }
  else {
    tw_msg_dev(param_1,8,"%s> Ignoring timer call: in reset",&s_PendTimer);
  }
  return;
}



===== tw_pendio_insert @ 1c000acc4 =====

/* WARNING: Removing unreachable block (ram,0x0001c000afd5) */

ulonglong tw_pendio_insert(byte *param_1,byte *param_2,char param_3)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 extraout_var;
  longlong lVar8;
  undefined1 uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined8 uVar13;
  undefined1 uVar14;
  byte *pbVar15;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar16;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  uVar1 = *(uint *)(param_2 + 0x38);
  if ((uVar1 == 0) || ((*(byte *)(*(longlong *)param_2 + 0x292) & 8) == 0)) {
    local_38[0] = 0;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    pbVar10 = param_1;
    pbVar11 = param_2;
    if (param_3 != '\0') {
      pbVar10 = (byte *)0x1003;
      pbVar11 = param_1;
      StorPortNotification(0x1003,param_1,3,0,local_38);
    }
    pbVar12 = param_2;
    if (*(int *)(param_2 + 0x40) == 1) {
      if (*(longlong *)(param_1 + 0x1556) == 0) {
        *(byte **)(param_1 + 0x1556) = param_2;
        lVar6 = tw_time_msecs();
        *(int *)(param_1 + 0x155e) = (int)lVar6;
        *(uint *)(param_1 + 0x1562) = uVar1;
        param_1[0x1566] = 0;
        tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar10 >> 8),param_2[0x12]),
                        CONCAT71((int7)((ulonglong)pbVar11 >> 8),param_2[0x13]),
                        *(uint *)(param_2 + 0x14),param_2[0x18],(undefined4 *)(param_2 + 0x104));
        uVar13 = 0x100;
        tw_msg_req((longlong *)param_2,0x100,"%s(T)> %s",&s_PendInsert);
LAB_1c000af4e:
        uVar4 = *(int *)(param_1 + 0x2a8) + 1;
        *(uint *)(param_1 + 0x2a8) = uVar4;
        if (*(uint *)(param_1 + 0x2c4) < uVar4) {
          *(uint *)(param_1 + 0x2c4) = uVar4;
        }
        lVar6 = (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20;
        *(int *)(param_1 + lVar6 + 0x7ee) = *(int *)(param_1 + lVar6 + 0x7ee) + 1;
        if (uVar1 != 0) {
          tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar12 >> 8),param_2[0x12]),
                          CONCAT71((int7)((ulonglong)uVar13 >> 8),param_2[0x13]),
                          *(uint *)(param_2 + 0x14),param_2[0x18],(undefined4 *)(param_2 + 0x104));
          tw_msg_req((longlong *)param_2,0x100,"%s> Adding: %s",&s_PendInsert);
          lVar6 = tw_timer_start(param_1,uVar1,0,tw_pendio_timer);
        }
        if (param_3 != '\0') {
          lVar6 = StorPortNotification(0x1004,param_1,local_38);
        }
        return CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
      }
      tw_msg_req((longlong *)param_2,1,"%s> Reserved PendQ Slot Taken",&s_PendInsert);
      lVar6 = *(longlong *)(param_2 + 8);
      if (lVar6 == 0) {
        uVar14 = 0;
        uVar9 = 0;
        uVar2 = 0;
      }
      else {
        uVar14 = *(undefined1 *)(lVar6 + 7);
        uVar9 = *(undefined1 *)(lVar6 + 6);
        uVar2 = *(undefined1 *)(lVar6 + 5);
      }
      StorPortLogError(*(undefined8 *)param_2,lVar6,uVar2,uVar9,uVar14,CONCAT44(uVar16,6),0x70000001
                      );
    }
    else {
      pbVar10 = param_1 + 0x156e;
      lVar6 = 1;
      pbVar11 = pbVar10;
      do {
        if ((*(longlong *)pbVar11 != 0) && (lVar7 = 1, 1 < lVar6)) {
          pbVar15 = pbVar10;
          do {
            if (*(longlong *)pbVar15 == 0) {
              lVar8 = *(longlong *)(pbVar11 + 8);
              *(longlong *)(param_1 + lVar7 * 0x18 + 0x1556) = *(longlong *)pbVar11;
              *(longlong *)(param_1 + lVar7 * 0x18 + 0x1556 + 8) = lVar8;
              *(longlong *)(param_1 + lVar7 * 0x18 + 0x1566) = *(longlong *)(pbVar11 + 0x10);
              pbVar11[0] = 0;
              pbVar11[1] = 0;
              pbVar11[2] = 0;
              pbVar11[3] = 0;
              pbVar11[4] = 0;
              pbVar11[5] = 0;
              pbVar11[6] = 0;
              pbVar11[7] = 0;
              break;
            }
            lVar7 = lVar7 + 1;
            pbVar15 = pbVar15 + 0x18;
          } while (lVar7 < lVar6);
        }
        lVar6 = lVar6 + 1;
        pbVar11 = pbVar11 + 0x18;
      } while (lVar6 < 0xb);
      iVar3 = 1;
      lVar7 = 1;
      do {
        if (*(longlong *)pbVar10 == 0) {
          lVar7 = (longlong)iVar3;
          *(byte **)(param_1 + lVar7 * 0x18 + 0x1556) = param_2;
          lVar8 = tw_time_msecs();
          *(int *)(param_1 + lVar7 * 0x18 + 0x155e) = (int)lVar8;
          *(uint *)(param_1 + lVar7 * 0x18 + 0x1562) = uVar1;
          param_1[lVar7 * 0x18 + 0x1566] = 0;
          tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar11 >> 8),param_2[0x12]),
                          CONCAT71((int7)((ulonglong)lVar6 >> 8),param_2[0x13]),
                          *(uint *)(param_2 + 0x14),param_2[0x18],(undefined4 *)(param_2 + 0x104));
          uVar13 = 0x100;
          tw_msg_req((longlong *)param_2,0x100,"%s(%d)> %s",&s_PendInsert);
          goto LAB_1c000af4e;
        }
        iVar3 = iVar3 + 1;
        lVar7 = lVar7 + 1;
        pbVar10 = pbVar10 + 0x18;
      } while (lVar7 < 0xb);
    }
    iVar3 = FUN_1c000a9fc((longlong)param_1,0x100,&s_PendInsert,-1);
    uVar5 = CONCAT44(extraout_var,iVar3);
    if (param_3 != '\0') {
      uVar5 = StorPortNotification(0x1004,param_1,local_38);
    }
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}



===== tw_pendio_delete @ 1c000b01c =====

undefined1 tw_pendio_delete(longlong *param_1,longlong *param_2,char param_3)

{
  uint uVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  int iVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar12;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  uVar11 = 0;
  plVar8 = param_2;
  lVar3 = tw_time_msecs();
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  if (param_3 != '\0') {
    plVar8 = param_1;
    StorPortNotification(0x1003,param_1,3,0,local_38);
  }
  iVar9 = 0;
  plVar4 = (longlong *)((longlong)param_1 + 0x1556);
  plVar7 = (longlong *)0x0;
  while (((char)plVar4[2] != '\0' || ((longlong *)*plVar4 != param_2))) {
    iVar9 = iVar9 + 1;
    plVar7 = (longlong *)((longlong)plVar7 + 1);
    plVar4 = plVar4 + 3;
    if (10 < (longlong)plVar7) {
      if ((*(byte *)(*param_2 + 0x292) & 8) == 0) {
        tw_xlate_opcode(CONCAT71((int7)((ulonglong)plVar7 >> 8),
                                 *(undefined1 *)((longlong)param_2 + 0x12)),
                        CONCAT71((int7)((ulonglong)plVar8 >> 8),
                                 *(undefined1 *)((longlong)param_2 + 0x13)),
                        *(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                        (undefined4 *)((longlong)param_2 + 0x104));
        tw_msg_req(param_2,1,"%s> Not found: %s","PendDelete");
        lVar3 = param_2[1];
        if (lVar3 == 0) {
          uVar10 = 0;
          uVar6 = 0;
          uVar2 = 0;
        }
        else {
          uVar10 = *(undefined1 *)(lVar3 + 7);
          uVar6 = *(undefined1 *)(lVar3 + 6);
          uVar2 = *(undefined1 *)(lVar3 + 5);
        }
        StorPortLogError(*param_2,lVar3,uVar2,uVar6,uVar10,CONCAT44(uVar12,6),0x70000005);
        FUN_1c000a9fc((longlong)param_1,0x100,"PendDelete",-1);
      }
LAB_1c000b1f3:
      if (param_3 != '\0') {
        StorPortNotification(0x1004,param_1,local_38);
      }
      return uVar11;
    }
  }
  lVar5 = (longlong)iVar9;
  uVar1 = *(uint *)((longlong)param_1 + lVar5 * 0x18 + 0x1562);
  if ((uVar1 != 0) &&
     (uVar1 < (uint)((int)lVar3 - *(int *)((longlong)param_1 + lVar5 * 0x18 + 0x155e)))) {
    plVar8 = (longlong *)0x0;
    plVar7 = param_1;
    FUN_1c000a9fc((longlong)param_1,2,"PendDelete",iVar9);
  }
  *(undefined8 *)((longlong)param_1 + lVar5 * 0x18 + 0x1556) = 0;
  *(int *)(param_1 + 0x55) = (int)param_1[0x55] + -1;
  tw_xlate_opcode(CONCAT71((int7)((ulonglong)plVar7 >> 8),*(undefined1 *)((longlong)param_2 + 0x12))
                  ,CONCAT71((int7)((ulonglong)plVar8 >> 8),*(undefined1 *)((longlong)param_2 + 0x13)
                           ),*(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                  (undefined4 *)((longlong)param_2 + 0x104));
  tw_msg_req(param_2,0x100,"%s(%d)> %s","PendDelete");
  uVar11 = 1;
  goto LAB_1c000b1f3;
}



===== tw_pendio_dolock @ 1c000b228 =====

longlong * tw_pendio_dolock(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar4;
  undefined4 *puVar3;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  longlong *plVar9;
  
  uVar7 = 0;
  plVar9 = (longlong *)(param_1 + 0x1556);
  iVar8 = 0;
  lVar1 = 0;
  while ((*plVar9 == 0 || (*(int *)(*plVar9 + 0x20) != (int)param_2))) {
    iVar8 = iVar8 + 1;
    lVar1 = lVar1 + 1;
    plVar9 = plVar9 + 3;
    if (10 < lVar1) {
      return (longlong *)0x0;
    }
  }
  lVar2 = (longlong)iVar8;
  plVar9 = *(longlong **)(param_1 + 0x1556 + lVar2 * 0x18);
  lVar1 = param_1;
  if (*(char *)(param_1 + 0x1566 + lVar2 * 0x18) != '\0') {
    puVar3 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)param_1 >> 8),
                                      *(undefined1 *)((longlong)plVar9 + 0x12)),
                             CONCAT71((int7)((ulonglong)param_2 >> 8),
                                      *(undefined1 *)((longlong)plVar9 + 0x13)),
                             *(uint *)((longlong)plVar9 + 0x14),*(byte *)(plVar9 + 3),
                             (undefined4 *)((longlong)plVar9 + 0x104));
    uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);
    tw_msg_req(plVar9,1,"%s(%d)> Was locked: %s",&s_PendLock);
    param_2 = plVar9[1];
    if (param_2 == 0) {
      uVar5 = 0;
      uVar6 = 0;
    }
    else {
      uVar5 = *(undefined1 *)(param_2 + 7);
      uVar6 = *(undefined1 *)(param_2 + 6);
      uVar7 = *(undefined1 *)(param_2 + 5);
    }
    lVar1 = *plVar9;
    StorPortLogError(lVar1,param_2,uVar7,uVar6,uVar5,CONCAT44(uVar4,6),0x70000006);
  }
  *(undefined1 *)(param_1 + 0x1566 + lVar2 * 0x18) = 1;
  tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)((longlong)plVar9 + 0x12)),
                  CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)((longlong)plVar9 + 0x13))
                  ,*(uint *)((longlong)plVar9 + 0x14),*(byte *)(plVar9 + 3),
                  (undefined4 *)((longlong)plVar9 + 0x104));
  tw_time_msecs();
  tw_msg_req(plVar9,0x100,"%s(%d)> Time=%08X Msecs=%-6d %s",&s_PendLock);
  return plVar9;
}



===== tw_pendio_unlock @ 1c000b3a4 =====

void tw_pendio_unlock(longlong param_1,longlong *param_2)

{
  undefined1 uVar1;
  longlong *plVar2;
  undefined4 uVar4;
  undefined4 *puVar3;
  undefined1 uVar5;
  undefined7 uVar7;
  longlong lVar6;
  longlong lVar8;
  int iVar9;
  undefined1 uVar10;
  
  iVar9 = 0;
  plVar2 = (longlong *)(param_1 + 0x1556);
  lVar8 = 0;
  do {
    uVar7 = (undefined7)((ulonglong)param_1 >> 8);
    if ((longlong *)*plVar2 == param_2) {
      lVar6 = param_1;
      if (*(char *)(param_1 + 0x1566 + (longlong)iVar9 * 0x18) == '\0') {
        puVar3 = tw_xlate_opcode(CONCAT71(uVar7,*(undefined1 *)((longlong)param_2 + 0x12)),
                                 CONCAT71((int7)((ulonglong)lVar8 >> 8),
                                          *(undefined1 *)((longlong)param_2 + 0x13)),
                                 *(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                                 (undefined4 *)((longlong)param_2 + 0x104));
        uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);
        tw_msg_req(param_2,1,"%s(%d)> Not locked: %s",&s_PendUnlock);
        lVar8 = param_2[1];
        if (lVar8 == 0) {
          uVar10 = 0;
          uVar5 = 0;
          uVar1 = 0;
        }
        else {
          uVar10 = *(undefined1 *)(lVar8 + 7);
          uVar5 = *(undefined1 *)(lVar8 + 6);
          uVar1 = *(undefined1 *)(lVar8 + 5);
        }
        lVar6 = *param_2;
        StorPortLogError(lVar6,lVar8,uVar1,uVar5,uVar10,CONCAT44(uVar4,6),0x70000007);
      }
      *(undefined1 *)(param_1 + 0x1566 + (longlong)iVar9 * 0x18) = 0;
      tw_xlate_opcode(CONCAT71((int7)((ulonglong)lVar6 >> 8),
                               *(undefined1 *)((longlong)param_2 + 0x12)),
                      CONCAT71((int7)((ulonglong)lVar8 >> 8),
                               *(undefined1 *)((longlong)param_2 + 0x13)),
                      *(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                      (undefined4 *)((longlong)param_2 + 0x104));
      tw_time_msecs();
      tw_msg_req(param_2,0x100,"%s(%d)> Time=%08X Msecs=%-6d %s",&s_PendUnlock);
      return;
    }
    iVar9 = iVar9 + 1;
    lVar8 = lVar8 + 1;
    plVar2 = plVar2 + 3;
  } while (lVar8 < 0xb);
  tw_xlate_opcode(CONCAT71(uVar7,*(undefined1 *)((longlong)param_2 + 0x12)),
                  CONCAT71((int7)((ulonglong)lVar8 >> 8),*(undefined1 *)((longlong)param_2 + 0x13)),
                  *(uint *)((longlong)param_2 + 0x14),*(byte *)(param_2 + 3),
                  (undefined4 *)((longlong)param_2 + 0x104));
  tw_msg_req(param_2,0x100,"%s> Not found: %s",&s_PendUnlock);
  FUN_1c000a9fc(param_1,0x100,&s_PendUnlock,-1);
  return;
}



===== tw_pendio_cancel @ 1c000b568 =====

int tw_pendio_cancel(longlong param_1,int param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  char *pcVar8;
  
  iVar4 = 0;
  plVar3 = (longlong *)(param_1 + 0x1556);
  uVar7 = 0;
  do {
    iVar5 = (int)uVar7;
    if ((*plVar3 != 0) && ((param_2 == 0 || (*(int *)(*plVar3 + 0x20) == param_2)))) {
      pcVar8 = "PendCancel";
      uVar2 = 8;
      FUN_1c000a9fc(param_1,8,"PendCancel",iVar5);
      plVar1 = (longlong *)*plVar3;
      *plVar3 = 0;
      *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + -1;
      *(undefined1 *)((longlong)plVar1 + 0x3e) = 1;
      tw_request_finish(plVar1,uVar2,pcVar8,uVar7);
      iVar4 = iVar4 + 1;
    }
    uVar6 = iVar5 + 1;
    uVar7 = (ulonglong)uVar6;
    plVar3 = plVar3 + 3;
  } while ((int)uVar6 < 0xb);
  return iVar4;
}



===== timer_signal @ 1c000b600 =====

void timer_signal(byte *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x165e);
  param_1[0x165e] = 0;
  param_1[0x165f] = 0;
  param_1[0x1660] = 0;
  param_1[0x1661] = 0;
  param_1[0x1662] = 0;
  param_1[0x1663] = 0;
  param_1[0x1664] = 0;
  param_1[0x1665] = 0;
  tw_time_msecs();
  tw_msg_dev(param_1,0x200,"TimerCallB> Type=%s Time(current-end)=%d",
             (&tw_strs_timertype)[*(int *)(param_1 + 0x1666)]);
                    /* WARNING: Could not recover jumptable at 0x0001c00101d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}



===== tw_timer_start @ 1c000b668 =====

undefined8 tw_timer_start(byte *param_1,uint param_2,int param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  char *pcVar4;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar6;
  undefined *puVar5;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if ((param_3 == 0) && (param_1[0x219] != 0)) {
    uVar1 = tw_msg_dev(param_1,8,"%s> Ignore PendIO request, restart later","TimerStart");
    param_1[0x166e] = 1;
    goto LAB_1c000b6b4;
  }
  if (*(longlong *)(param_1 + 0x165e) == 0) {
    puVar5 = (&tw_strs_timertype)[param_3];
    pcVar4 = "%s> Type=%s Msecs=%u";
    uVar3 = 0x200;
LAB_1c000b7c6:
    tw_msg_dev(param_1,uVar3,pcVar4,"TimerStart");
  }
  else {
    lVar2 = tw_time_msecs();
    uVar3 = *(int *)(param_1 + 0x166a) - (int)lVar2;
    if (param_3 != 1) {
      if ((param_3 != 0) || (*(int *)(param_1 + 0x1666) != 0)) {
LAB_1c000b76f:
        uVar1 = tw_msg_dev(param_1,1,"%s> Already active: %s","TimerStart");
LAB_1c000b6b4:
        return uVar1 & 0xffffffffffffff00;
      }
      if (uVar3 <= param_2) {
        if ((*(uint *)(param_1 + 0x296) & 0x40000000) != 0) {
          lVar2 = tw_msg_dev(param_1,0x200,"%s> Ignore: Current=%d <= New=%d msecs","TimerStart");
        }
        goto LAB_1c000b80b;
      }
      pcVar4 = "%s> Override: New=%d < Current=%d";
      puVar5 = (undefined *)CONCAT44(uVar6,param_2);
      uVar3 = 2;
      goto LAB_1c000b7c6;
    }
    if (*(int *)(param_1 + 0x1666) != 0) goto LAB_1c000b76f;
    puVar5 = (undefined *)CONCAT44(uVar6,uVar3);
    tw_msg_dev(param_1,2,"%s> Override PendIO request: %d msecs left","TimerStart");
    param_1[0x166e] = 1;
  }
  *(int *)(param_1 + 0x1666) = param_3;
  lVar2 = tw_time_msecs();
  *(uint *)(param_1 + 0x166a) = (int)lVar2 + param_2;
  *(undefined8 *)(param_1 + 0x165e) = param_4;
  lVar2 = StorPortNotification(6,param_1,timer_signal,param_2 * 1000,puVar5);
LAB_1c000b80b:
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
}



===== tw_request_init @ 1c000b824 =====

void tw_request_init(undefined8 *param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = *param_1;
  memset(param_1,0,0x503);
  *param_1 = uVar1;
  *(undefined2 *)(param_1 + 2) = 0xffff;
  param_1[1] = param_2;
  if (param_2 == 0) {
    *(undefined2 *)((longlong)param_1 + 0x19) = 0xffff;
  }
  else {
    *(undefined2 *)((longlong)param_1 + 0x12) = 0x101;
    *(uint *)((longlong)param_1 + 0x14) = (uint)*(byte *)(param_2 + 2);
    *(undefined1 *)((longlong)param_1 + 0x19) = *(undefined1 *)(param_2 + 6);
    *(undefined1 *)((longlong)param_1 + 0x1a) = *(undefined1 *)(param_2 + 7);
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_2 + 0x10);
    param_1[5] = *(undefined8 *)(param_2 + 0x18);
    memcpy((void *)((longlong)param_1 + 0x6e),(void *)(param_2 + 0x48),0x10);
  }
  param_1[0x34] = (longlong)param_1 + 0x1e7U & 0xffffffffffffffc0;
  lVar2 = tw_time_msecs();
  *(int *)((longlong)param_1 + 0x1c) = (int)lVar2;
  return;
}



===== tw_request_driver @ 1c000b8c8 =====

void tw_request_driver(longlong *param_1,ushort *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = (byte *)param_1[0x34];
  *(undefined1 *)((longlong)param_1 + 0x12) = 4;
  bVar1 = *pbVar2;
  if ((bVar1 & 0x1f) == 0x10) {
    *(undefined1 *)((longlong)param_1 + 0x13) = 0x10;
    uVar3 = (uint)pbVar2[8];
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x13) = 0x40;
    if ((byte)((bVar1 & 0x1f) - 0x12) < 2) {
      param_2 = (ushort *)param_1[5];
      *(uint *)((longlong)param_1 + 0x14) = (uint)*param_2 << 0x10 | *pbVar2 & 0x1f;
      *(char *)(param_1 + 3) = (char)param_2[1];
      goto LAB_1c000b919;
    }
    uVar3 = *pbVar2 & 0x1f;
  }
  *(uint *)((longlong)param_1 + 0x14) = uVar3;
LAB_1c000b919:
  tw_request_store(param_1,param_2,param_1,pbVar2);
  return;
}



===== tw_request_match @ 1c000b924 =====

void tw_request_match(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  bool bVar2;
  byte *pbVar3;
  
  lVar1 = *param_1;
  if (*(char *)(lVar1 + 0xf87) != '\0') {
    pbVar3 = FUN_1c0007a98(lVar1 + 0xf7e,(longlong)param_1);
    bVar2 = cm_match((byte *)(lVar1 + 0xf7e),param_1,pbVar3,param_4);
    if ((!bVar2) &&
       (*(undefined1 *)((longlong)param_1 + 0x49) = 1, (*(uint *)(lVar1 + 0xf92) & 8) != 0)) {
      cm_log_req(param_1,pbVar3,"Cm!!Match>>");
    }
  }
  return;
}



===== tw_request_store @ 1c000b998 =====

void tw_request_store(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(char *)(*param_1 + 0xf87) != '\0') {
    cm_req_start((byte *)(*param_1 + 0xf7e),param_1,param_3,param_4);
  }
  return;
}



===== tw_request_start @ 1c000b9bc =====

undefined8 tw_request_start(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  longlong *plVar5;
  byte *pbVar6;
  undefined8 uVar7;
  ushort uVar8;
  longlong *plVar9;
  char *pcVar10;
  bool bVar11;
  uint *local_res8;
  int *local_res10;
  
  pbVar6 = (byte *)param_1[0x34];
  lVar1 = *param_1;
  bVar11 = (*pbVar6 & 0x1f) != 0x10;
  plVar9 = (longlong *)0x2;
  bVar3 = false;
  if ((int)param_1[8] == 2) {
    plVar9 = (longlong *)0x1;
    *(longlong **)(*(longlong *)(lVar1 + 0x277) + 8) = param_1;
  }
  else if ((int)param_1[8] == 1) {
    plVar9 = (longlong *)0x0;
    **(undefined8 **)(lVar1 + 0x277) = param_1;
  }
  else {
    if (bVar11) {
      local_res8._0_2_ = *(ushort *)(lVar1 + 0x14b);
      if (0xff < (ushort)local_res8) {
        local_res8._0_2_ = 0x100;
      }
    }
    else {
      if (*(ushort *)(lVar1 + 0x287) < 6) {
        *(undefined2 *)(lVar1 + 0x287) = 6;
      }
      plVar9 = (longlong *)(ulonglong)*(ushort *)(lVar1 + 0x287);
    }
    do {
      while( true ) {
        plVar5 = plVar9;
        if (*(longlong *)(*(longlong *)(lVar1 + 0x277) + (longlong)plVar5 * 8) == 0) {
          *(longlong **)(*(longlong *)(lVar1 + 0x277) + (longlong)plVar5 * 8) = param_1;
          plVar9 = plVar5;
          goto LAB_1c000babd;
        }
        uVar8 = (short)plVar5 + 1;
        plVar9 = (longlong *)(ulonglong)uVar8;
        if (bVar11) break;
        if (*(ushort *)(lVar1 + 0x14b) <= uVar8) {
          plVar9 = (longlong *)0x6;
        }
        if ((short)plVar9 == *(short *)(lVar1 + 0x287)) goto LAB_1c000bab1;
      }
    } while (uVar8 < (ushort)local_res8);
LAB_1c000bab1:
    bVar3 = true;
LAB_1c000babd:
    if (!bVar11) {
      uVar4 = (int)plVar9 + 1;
      plVar5 = (longlong *)(ulonglong)uVar4;
      uVar8 = (ushort)uVar4;
      *(ushort *)(lVar1 + 0x287) = uVar8;
      if (*(ushort *)(lVar1 + 0x14b) <= uVar8) {
        *(undefined2 *)(lVar1 + 0x287) = 6;
      }
    }
    if (bVar3) {
      return (ulonglong)plVar5 & 0xffffffffffffff00;
    }
  }
  if (bVar11) {
    pbVar6[2] = (byte)plVar9;
  }
  else {
    *(ushort *)(pbVar6 + 2) =
         *(ushort *)(pbVar6 + 2) ^ (*(ushort *)(pbVar6 + 2) ^ (ushort)plVar9) & 0xfff;
  }
  *(ushort *)(param_1 + 2) = (ushort)plVar9;
  *(ushort *)((longlong)param_1 + 0x24) = *(ushort *)((longlong)param_1 + 0x24) | 0x1000;
  local_res8 = (uint *)(lVar1 + 0x2a4);
  LOCK();
  *local_res8 = *local_res8 + 1;
  UNLOCK();
  local_res10 = (int *)((ulonglong)*(ushort *)(lVar1 + 0x2bd) * 0x20 + 0x7f2 + lVar1);
  LOCK();
  *local_res10 = *local_res10 + 1;
  UNLOCK();
  if (*(uint *)(lVar1 + 0x2c0) < *local_res8) {
    *(uint *)(lVar1 + 0x2c0) = *local_res8;
  }
  lVar2 = *param_1;
  if ((*(char *)(lVar2 + 0xf87) != '\0') && (*(char *)((longlong)param_1 + 0x49) == '\0')) {
    pbVar6 = FUN_1c0007a98(lVar2 + 0xf7e,(longlong)param_1);
    uVar8 = *(ushort *)(*(longlong *)(lVar2 + 0xf7e) + 0x2a4);
    plVar9 = (longlong *)(ulonglong)uVar8;
    *(ushort *)(pbVar6 + 0xc) = uVar8;
    if ((char)param_1[0xd] == '\0') {
      if ((*(uint *)(lVar2 + 0xf92) & 0x200) == 0) goto LAB_1c000bbb0;
      pcVar10 = "Cm!!Update>";
    }
    else {
      if ((*(uint *)(lVar2 + 0xf92) & 0x20) == 0) goto LAB_1c000bbb0;
      pcVar10 = "CmonUpdate>";
    }
    plVar9 = param_1;
    cm_log_req(param_1,pbVar6,pcVar10);
  }
LAB_1c000bbb0:
  if ((*(byte *)(*param_1 + 0x296) & 0x40) != 0) {
    tw_xlate_opcode(CONCAT71((int7)((ulonglong)plVar9 >> 8),
                             *(undefined1 *)((longlong)param_1 + 0x12)),
                    CONCAT71((int7)((ulonglong)pbVar6 >> 8),
                             *(undefined1 *)((longlong)param_1 + 0x13)),
                    *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                    (undefined4 *)((longlong)param_1 + 0x104));
    tw_time_msecs();
    tw_msg_req(param_1,0x40,"SND> Id=%-4d Posted=%-3u Msecs=%-6d KB=%-3d %s",
               (ulonglong)*(ushort *)(param_1 + 2));
  }
  uVar7 = StorPortGetPhysicalAddress(lVar1,param_1[1],param_1[0x34],&local_res8);
  *(int *)(*(longlong *)(lVar1 + 0x40) + 0xc4) = (int)((ulonglong)uVar7 >> 0x20);
  LOCK();
  UNLOCK();
  *(uint *)(*(longlong *)(lVar1 + 0x40) + 0xc0) = (uint)uVar7 | 1;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== tw_request_idchk @ 1c000bc74 =====

ulonglong tw_request_idchk(byte *param_1,ushort param_2,undefined8 param_3)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  
  if (param_2 < *(ushort *)(param_1 + 0x14b)) {
    uVar6 = 0;
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x277) + (ulonglong)param_2 * 8);
    if (plVar1 != (longlong *)0x0) {
      if (param_2 == *(ushort *)(plVar1 + 2)) {
        return CONCAT71((uint7)(byte)(*(ushort *)(plVar1 + 2) >> 8),1);
      }
      tw_msg_req(plVar1,1,"%s> RspId=%d != ReqId=%d",param_3);
      lVar3 = plVar1[1];
      if (lVar3 == 0) {
        uVar4 = 0;
        uVar5 = 0;
      }
      else {
        uVar4 = *(undefined1 *)(lVar3 + 7);
        uVar5 = *(undefined1 *)(lVar3 + 6);
        uVar6 = *(undefined1 *)(lVar3 + 5);
      }
      uVar7 = 0x70000004;
      param_1 = (byte *)*plVar1;
      goto LAB_1c000bcda;
    }
    tw_msg_dev(param_1,1,"%s> RspId=%u: Invalid or already completed request",param_3);
    uVar7 = 0x70000003;
  }
  else {
    tw_msg_dev(param_1,1,"%s> RspId=%u > %u maximum",param_3);
    uVar7 = 0x70000002;
  }
  uVar5 = 0;
  uVar6 = 0;
  uVar4 = 0;
  lVar3 = 0;
LAB_1c000bcda:
  uVar2 = StorPortLogError(param_1,lVar3,uVar6,uVar5,uVar4,6,uVar7);
  return uVar2 & 0xffffffffffffff00;
}



===== tw_request_finish @ 1c000bdac =====

void tw_request_finish(longlong *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  ushort uVar1;
  byte *pbVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  byte *pbVar8;
  char *pcVar9;
  undefined1 *puVar10;
  
  uVar1 = *(ushort *)(param_1 + 2);
  pcVar9 = "RequestFinish";
  pbVar2 = (byte *)*param_1;
  uVar7 = (ulonglong)uVar1;
  pbVar8 = pbVar2;
  uVar5 = tw_request_idchk(pbVar2,uVar1,&s_RequestFinish);
  if ((char)uVar5 != '\0') {
    if ((*(byte *)(*param_1 + 0x296) & 0x40) != 0) {
      tw_xlate_opcode(CONCAT71((int7)((ulonglong)pbVar8 >> 8),
                               *(undefined1 *)((longlong)param_1 + 0x12)),
                      CONCAT71((int7)(uVar7 >> 8),*(undefined1 *)((longlong)param_1 + 0x13)),
                      *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                      (undefined4 *)((longlong)param_1 + 0x104));
      tw_time_msecs();
      pcVar9 = "RET> Id=%-4d Posted=%-3u Msecs=%-6d KB=%-3d %s";
      param_4 = (ulonglong)*(ushort *)(param_1 + 2);
      tw_msg_req(param_1,0x40,"RET> Id=%-4d Posted=%-3u Msecs=%-6d KB=%-3d %s",param_4);
    }
    pbVar8 = pbVar2 + 0x2a4;
    *(undefined8 *)(*(longlong *)(pbVar2 + 0x277) + (ulonglong)uVar1 * 8) = 0;
    LOCK();
    *(int *)pbVar8 = *(int *)pbVar8 + -1;
    UNLOCK();
    if (*(int *)pbVar8 < 0) {
      puVar10 = &s_RequestFinish;
      tw_msg_req(param_1,1,"%s>  Posted=%d",&s_RequestFinish);
      lVar3 = param_1[1];
      if (lVar3 == 0) {
        uVar6 = 0;
        bVar4 = 0;
      }
      else {
        uVar6 = *(undefined1 *)(lVar3 + 6);
        bVar4 = *(byte *)(lVar3 + 5);
      }
      param_4 = CONCAT71((int7)((ulonglong)puVar10 >> 8),uVar6);
      pcVar9 = (char *)(ulonglong)bVar4;
      StorPortLogError(*param_1);
      pbVar8[0] = 0;
      pbVar8[1] = 0;
      pbVar8[2] = 0;
      pbVar8[3] = 0;
    }
  }
  tw_request_done(param_1,1,pcVar9,param_4);
  return;
}



===== tw_request_done @ 1c000bf0c =====

void tw_request_done(longlong *param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar3 = *param_1;
  if (((*(char *)((longlong)param_1 + 0x3e) != '\0') && (lVar7 = param_1[1], lVar7 != 0)) &&
     (*(char *)(lVar7 + 2) == '\x02')) {
    if ((int)param_1[4] == 1) {
      puVar1 = (uint *)(*(longlong *)(lVar7 + 0x18) + 0x14);
      *puVar1 = *puVar1 | 4;
    }
    else {
      puVar1 = (uint *)(*(longlong *)(lVar7 + 0x18) + 0x14);
      *puVar1 = *puVar1 | 0x40;
    }
  }
  if (*(char *)(lVar3 + 0xf87) != '\0') {
    plVar2 = (longlong *)(lVar3 + 0xf7e);
    plVar6 = plVar2;
    plVar8 = param_1;
    uVar4 = cm_req_finish(plVar2,param_1,CONCAT71((int7)((ulonglong)param_3 >> 8),param_2),param_4);
    if ((char)uVar4 == '\0') {
      puVar5 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)plVar6 >> 8),
                                        *(undefined1 *)((longlong)param_1 + 0x12)),
                               CONCAT71((int7)((ulonglong)plVar8 >> 8),
                                        *(undefined1 *)((longlong)param_1 + 0x13)),
                               *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                               (undefined4 *)((longlong)param_1 + 0x104));
      tw_msg_req(param_1,8,"RequestDone> Lock for more: %s",puVar5);
      local_28[0] = 0;
      local_20 = 0;
      local_18 = 0;
      local_10 = 0;
      StorPortNotification(0x1003,lVar3,3,0,local_28);
      cm_req_finish_locked(plVar2,param_1);
      StorPortNotification(0x1004,lVar3,local_28);
    }
  }
  if (*(char *)(lVar3 + 0xf9a) == '\0') {
    *(undefined1 *)(lVar3 + 0xf87) = 0;
  }
  lVar7 = param_1[1];
  if (lVar7 == 0) {
    *(undefined1 *)(param_1 + 9) = 1;
  }
  else {
    if (*(char *)(lVar7 + 3) == '\0') {
      tw_srb_status(lVar7,'\x01');
    }
    StorPortNotification(0,lVar3,lVar7);
  }
  return;
}



===== tw_request_show @ 1c000c048 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_request_show(longlong *param_1,undefined8 param_2)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined1 auStackY_88 [32];
  char local_38 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  pbVar2 = (byte *)param_1[0x34];
  bVar1 = *pbVar2;
  pcVar3 = (char *)(ulonglong)*(uint *)(*param_1 + 0x296);
  if ((int)*(uint *)(*param_1 + 0x296) < 0) {
    param_2 = 0;
    pcVar3 = local_38;
    tw_string(pcVar3,10,"(%08X)",(ulonglong)*(uint *)((longlong)param_1 + 0x1c));
  }
  else {
    local_38[0] = '\0';
  }
  tw_xlate_opcode(CONCAT71((int7)((ulonglong)pcVar3 >> 8),*(undefined1 *)((longlong)param_1 + 0x12))
                  ,CONCAT71((int7)((ulonglong)param_2 >> 8),
                            *(undefined1 *)((longlong)param_1 + 0x13)),
                  *(uint *)((longlong)param_1 + 0x14),*(byte *)(param_1 + 3),
                  (undefined4 *)((longlong)param_1 + 0x104));
  tw_msg_req(param_1,8,"PostList: Id=%-4d Status=%-3d %s=%-6d%s KB=%-3d %s",
             (ulonglong)*(ushort *)(param_1 + 2));
  if ((bVar1 & 0x1f) == 0x10) {
    if ((*(uint *)(*param_1 + 0x296) & 0x200000) != 0) {
      tw_msg_req(param_1,8,"SGL: CdbLen=%d Count=%u",(ulonglong)pbVar2[5]);
    }
    if ((*(uint *)(*param_1 + 0x296) & 0x400000) != 0) {
      tw_msg_req(param_1,8,"CDB0: %02X %02X %02X %02X",(ulonglong)pbVar2[8]);
      tw_msg_req(param_1,8,"CDB1: %02X %02X %02X %02X",(ulonglong)pbVar2[0xc]);
      tw_msg_req(param_1,8,"CDB2: %02X %02X %02X %02X",(ulonglong)pbVar2[0x10]);
      tw_msg_req(param_1,8,"CDB3: %02X %02X %02X %02X",(ulonglong)pbVar2[0x14]);
    }
  }
  else if ((pbVar2[1] != 0) && ((*(uint *)(*param_1 + 0x296) & 0x200000) != 0)) {
    tw_msg_req(param_1,8,"SGL: Offset=%d Size=%u",(ulonglong)(*pbVar2 >> 5));
  }
  return;
}



===== tw_request_check @ 1c000c288 =====

ushort tw_request_check(byte *param_1,char param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ushort uVar3;
  char *pcVar4;
  ushort uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  pcVar4 = "ReqCheck";
  if (param_3 != '\0') {
    pcVar4 = "ReqCancel";
  }
  uVar2 = tw_time_msecs();
  uVar1 = *(uint *)(param_1 + 0x2a4);
  uVar3 = 0;
  uVar5 = 0;
  if (*(short *)(param_1 + 0x14b) != 0) {
    do {
      uVar7 = 0;
      plVar6 = *(longlong **)(*(longlong *)(param_1 + 0x277) + (ulonglong)uVar5 * 8);
      if (plVar6 != (longlong *)0x0) {
        uVar3 = uVar3 + 1;
        if (param_3 == '\0') {
          if (param_2 != '\0') {
            tw_request_show(plVar6,uVar2 & 0xffffffff);
          }
        }
        else {
          *(undefined8 *)(*(longlong *)(param_1 + 0x277) + (ulonglong)uVar5 * 8) = 0;
          *(int *)(param_1 + 0x2a4) = *(int *)(param_1 + 0x2a4) + -1;
          if (plVar6[1] != 0) {
            tw_srb_status(plVar6[1],'\v');
          }
          *(undefined1 *)((longlong)plVar6 + 0x3e) = 1;
          tw_request_done(plVar6,1,plVar6,uVar7);
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(param_1 + 0x14b));
    if (uVar3 != 0) {
      tw_msg_dev(param_1,8,"%s> Requests %s=%u",pcVar4);
    }
  }
  if (uVar3 != uVar1) {
    tw_msg_dev(param_1,1,"%s> posted=%d != Found=%d",pcVar4);
  }
  return uVar3;
}



===== FUN_1c000c3f0 @ 1c000c3f0 =====

void FUN_1c000c3f0(byte *param_1)

{
  *(int *)(param_1 + 0x7d6) = *(int *)(param_1 + 0x7d6) + 1;
  tw_msg_dev(param_1,4,"FwRestart> Attempts=%d",(ulonglong)*(uint *)(param_1 + 0x7d6));
  param_1[0x21e] = 1;
  tw_fwstate_exec(param_1,2);
  return;
}



===== FUN_1c000c430 @ 1c000c430 =====

/* WARNING: Removing unreachable block (ram,0x0001c000c48d) */

void FUN_1c000c430(byte *param_1,char param_2,undefined8 param_3,undefined *param_4)

{
  char *pcVar1;
  code *pcVar2;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 0x236) == 0) {
      return;
    }
    param_1[0x232] = 0;
    param_1[0x233] = 0;
    param_1[0x234] = 0;
    param_1[0x235] = 0;
    tw_msg_dev(param_1,2,"%s> Firmware failed: wait for restart...","StateFinish");
    pcVar2 = FUN_1c000c3f0;
    tw_timer_start(param_1,tw_restart_timeout,2,FUN_1c000c3f0);
    pcVar1 = "Disabling interrupts <<<==========================";
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x34) = 0xffffffff;
  }
  else {
    pcVar2 = (code *)param_4;
    if (param_1[0x21e] != 0) {
      pcVar1 = "StateFinish";
      param_1[0x21e] = 0;
      tw_msg_dev(param_1,4,"%s> Successfully restarted: request rescan...","StateFinish");
      StorPortNotification(7,param_1);
      pcVar2 = (code *)pcVar1;
    }
    if (param_1[0x166e] != 0) {
      tw_pendio_timer(param_1);
      param_1[0x166e] = 0;
    }
    if (*(int *)(param_1 + 0x236) != 1) {
      return;
    }
    tw_flow_resume(param_1,"StateFinish");
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xa0) = 0xffffffff;
    LOCK();
    UNLOCK();
    pcVar1 = "Enabling interrupts ===========================>>>";
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x34) = 0xfffffff3;
  }
  LOCK();
  UNLOCK();
  tw_msg_dev(param_1,8,pcVar1,pcVar2);
  return;
}



===== FUN_1c000c560 @ 1c000c560 =====

void FUN_1c000c560(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (param_1[0x21a] == 0) {
    FUN_1c000c580(param_1);
    return;
  }
  tw_msg_dev(param_1,2,"StateTimer> Ignoring: recursive STOP",param_4);
  return;
}



===== FUN_1c000c580 @ 1c000c580 =====

/* WARNING: Removing unreachable block (ram,0x0001c000c826) */

char FUN_1c000c580(byte *param_1)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  char cVar6;
  char *pcVar7;
  undefined1 *puVar8;
  char *pcVar9;
  bool bVar10;
  
  bVar10 = false;
  cVar6 = '\x01';
  do {
    do {
      lVar3 = tw_time_msecs();
      if ((param_1[0x21b] == 0) || (param_1[0x23c] != 0)) {
        pcVar9 = "StateLoop";
        if (*(uint *)(param_1 + 0x223) < (uint)((int)lVar3 - *(int *)(param_1 + 0x22b))) {
          pcVar7 = "%s(%s)> Timeout: %u > %u msecs";
          uVar5 = 1;
          tw_msg_dev(param_1,1,"%s(%s)> Timeout: %u > %u msecs","StateLoop");
          goto LAB_1c000c62b;
        }
        pcVar7 = "%s(%s)> Entering...";
        uVar5 = 0x400;
        tw_msg_dev(param_1,0x400,"%s(%s)> Entering...","StateLoop");
      }
      else {
        pcVar9 = "StateLoop";
        pcVar7 = "%s(%s)> Detected error";
        uVar5 = 1;
        tw_msg_dev(param_1,1,"%s(%s)> Detected error","StateLoop");
LAB_1c000c62b:
        lVar3 = tw_time_msecs();
        *(int *)(param_1 + 0x22b) = (int)lVar3;
        param_1[0x232] = 2;
        param_1[0x233] = 0;
        param_1[0x234] = 0;
        param_1[0x235] = 0;
      }
      iVar1 = *(int *)(param_1 + 0x232);
      param_1[0x21b] = 0;
      if (iVar1 - 2U < 3) {
        param_1[0x21f] = 0x32;
        param_1[0x220] = 0;
        param_1[0x221] = 0;
        param_1[0x222] = 0;
        param_1[0x21c] = 1;
        if (iVar1 == 2) {
          uVar5 = FUN_1c000d080(param_1,uVar5,pcVar7,pcVar9);
          if ((char)uVar5 == '\0') {
            cVar6 = '\0';
            tw_reset_done(param_1,'\0');
            if (param_1[0x23c] == 0) {
              param_1[0x219] = 0;
              bVar10 = true;
            }
            goto LAB_1c000c77a;
          }
          param_1[0x232] = 3;
          param_1[0x233] = 0;
          param_1[0x234] = 0;
          param_1[0x235] = 0;
LAB_1c000c718:
          param_1[0x21c] = 0;
        }
        else if (iVar1 == 3) {
          uVar4 = tw_hware_ready(param_1,uVar5,pcVar7,pcVar9);
          if ((char)uVar4 == '\0') {
            tw_reset_clear(param_1);
            *(undefined4 *)(param_1 + 0x21f) = tw_reset_twait_init;
            param_1[0x232] = 4;
            param_1[0x233] = 0;
            param_1[0x234] = 0;
            param_1[0x235] = 0;
          }
        }
        else if ((iVar1 == 4) &&
                (uVar4 = tw_hware_ready(param_1,uVar5,pcVar7,pcVar9), (char)uVar4 != '\0')) {
          tw_reset_done(param_1,'\x01');
          goto LAB_1c000c718;
        }
        cVar6 = '\x01';
        if (param_1[0x23c] == 0) {
          lVar3 = tw_time_msecs();
          *(int *)(param_1 + 0x22b) = (int)lVar3;
          pcVar9 = "%s> Reconnect to firmware...";
          *(int *)(param_1 + 0x232) = *(int *)(param_1 + 0x236);
          if (*(int *)(param_1 + 0x236) != 1) {
            pcVar9 = "%s> Disconnect from firmware...";
          }
          tw_msg_dev(param_1,0x400,pcVar9,"StateLoop");
        }
      }
      else {
        tw_connect_state(param_1,uVar5,(ulonglong)pcVar7,pcVar9);
        bVar10 = param_1[0x219] == 0;
      }
LAB_1c000c77a:
      if ((bVar10) || (cVar6 == '\0')) {
        tw_time_msecs();
        puVar8 = &s__s__s_>__s___d_msecs;
        pcVar9 = "StateLoop";
        tw_msg_dev(param_1,8,"%s(%s)> %s: %d msecs","StateLoop");
        FUN_1c000c430(param_1,cVar6,puVar8,pcVar9);
        return cVar6;
      }
    } while (param_1[0x21c] == 0);
    if ((param_1[0x21d] != 0) || (bVar2 = false, tw_crash_dump != '\0')) {
      bVar2 = true;
    }
    tw_msg_dev(param_1,0x400,"%s(%s)> Start %s: %d msecs...","StateLoop");
    if (!bVar2) {
      tw_timer_start(param_1,*(uint *)(param_1 + 0x21f),1,FUN_1c000c560);
      goto LAB_1c000c84d;
    }
    StorPortStallExecution(*(int *)(param_1 + 0x21f) * 1000);
    if (!bVar2) {
LAB_1c000c84d:
      tw_msg_dev(param_1,0x400,"%s(%s)> ...Exiting","StateLoop");
      return '\x01';
    }
  } while( true );
}



===== tw_fwstate_exec @ 1c000c8e0 =====

char tw_fwstate_exec(byte *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  byte bVar4;
  undefined *puVar5;
  
  bVar4 = 0;
  if (param_1[0x219] == 0) {
    iVar1 = *(int *)(param_1 + 0x232);
    if (((iVar1 != 0) || (param_2 != 0)) && ((iVar1 != 1 || (param_2 != 1)))) {
      param_1[0x219] = 1;
      param_1[0x21a] = 0;
      lVar3 = tw_time_msecs();
      *(int *)(param_1 + 0x227) = (int)lVar3;
      *(int *)(param_1 + 0x22b) = (int)lVar3;
      *(undefined4 *)(param_1 + 0x223) = tw_timeout_msecs;
      if ((param_2 == 0) || ((param_2 == 1 && (param_1[0x218] != 0)))) {
        bVar4 = 1;
      }
      *(int *)(param_1 + 0x232) = param_2;
      param_1[0x21d] = bVar4;
      param_1[0x22f] = param_2 == 1;
      if (param_2 == 2) {
        param_2 = 1;
      }
      *(int *)(param_1 + 0x236) = param_2;
LAB_1c000ca1b:
      cVar2 = FUN_1c000c580(param_1);
      return cVar2;
    }
    tw_msg_dev(param_1,2,"StateExec> Already in state: %s",(&tw_strs_fwstate)[iVar1]);
  }
  else {
    puVar5 = (&tw_strs_fwstate)[*(int *)(param_1 + 0x232)];
    tw_msg_dev(param_1,2,"StateExec> Recursive: Current=%s Request=%s",puVar5);
    if (param_2 == 2) {
      param_1[0x21b] = 1;
    }
    else if (param_2 != 1) {
      param_1[0x21d] = 1;
      param_1[0x21a] = 1;
      if (param_1[0x23c] != 0) {
        tw_msg_dev(param_1,2,"StateExec> Finish reset first, then stop",puVar5);
      }
      param_1[0x236] = 0;
      param_1[0x237] = 0;
      param_1[0x238] = 0;
      param_1[0x239] = 0;
      goto LAB_1c000ca1b;
    }
  }
  return '\x01';
}



===== tw_connect_response @ 1c000ca38 =====

ulonglong tw_connect_response(longlong *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  
  lVar4 = param_1[0x34];
  lVar5 = *param_1;
  uVar1 = *(ushort *)(lVar4 + 6);
  uVar2 = *(ushort *)(lVar5 + 0x14b);
  if (uVar1 < uVar2) {
    if (uVar1 < 0x26) {
      tw_msg_req(param_1,4,"Connect> MaxRequests too low: %d < %d",(ulonglong)uVar1);
      lVar4 = param_1[1];
      uVar7 = 0;
      if (lVar4 == 0) {
        uVar6 = 0;
        uVar9 = 0;
      }
      else {
        uVar6 = *(undefined1 *)(lVar4 + 7);
        uVar9 = *(undefined1 *)(lVar4 + 6);
        uVar7 = *(undefined1 *)(lVar4 + 5);
      }
      uVar8 = StorPortLogError(*param_1,lVar4,uVar7,uVar9,uVar6,6,0x60000001);
      return uVar8 & 0xffffffffffffff00;
    }
    *(ushort *)(lVar5 + 0x14b) = uVar1;
    tw_msg_req(param_1,4,"Connect> Adjusting MaxRequests to %u",(ulonglong)uVar1);
  }
  else if (uVar2 < uVar1) {
    tw_msg_req(param_1,4,"Connect> FW supports larger MaxRequests: %u < %u",(ulonglong)uVar2);
  }
  tw_msg_req(param_1,4,"Connect> ID=%u SRL=%u Branch=%u Build=%u MaxReqs=%u",
             (ulonglong)*(ushort *)(lVar4 + 0xe));
  *(undefined2 *)(lVar5 + 0x4e) = *(undefined2 *)(lVar4 + 0xc);
  *(undefined2 *)(lVar5 + 0x50) = *(undefined2 *)(lVar4 + 0x10);
  *(undefined2 *)(lVar5 + 0x52) = *(undefined2 *)(lVar4 + 0x12);
  uVar3 = *(undefined2 *)(lVar4 + 0xe);
  *(undefined2 *)(lVar5 + 0x4a) = uVar3;
  return CONCAT71((uint7)(byte)((ushort)uVar3 >> 8),1);
}



===== tw_connect_state @ 1c000cb8c =====

void tw_connect_state(byte *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  ushort uVar1;
  longlong *plVar2;
  undefined *puVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  byte *_Dst;
  
  iVar11 = *(int *)(param_1 + 0x232);
  plVar2 = *(longlong **)(param_1 + 0x247);
  param_1[0x21c] = 0;
  param_1[0x21f] = 0x32;
  param_1[0x220] = 0;
  param_1[0x221] = 0;
  param_1[0x222] = 0;
  puVar3 = (&tw_strs_fwstate)[iVar11];
  if (iVar11 == 0) {
    cVar9 = '\0';
  }
  else {
    if (iVar11 != 1) {
      if (iVar11 == 5) {
        uVar4 = tw_resp_drain(param_1,&s_EXE,(int *)0x0);
        if (((char)uVar4 == '\0') || (*(short *)((longlong)plVar2 + 0x3c) != 0)) {
LAB_1c000cea7:
          iVar11 = 2;
          goto LAB_1c000ceea;
        }
        if ((char)plVar2[9] != '\0') {
          if (*(int *)(param_1 + 0x236) == 0) {
            tw_flow_resume(param_1,puVar3);
            iVar11 = 0;
          }
          else {
            uVar6 = tw_connect_response(plVar2);
            if (((char)uVar6 == '\0') ||
               (uVar7 = tw_hware_stuff(param_1,*(longlong *)(param_1 + 0x27f),
                                       (uint)*(ushort *)(param_1 + 0x14b)), (char)uVar7 == '\0'))
            goto LAB_1c000cea7;
            if ((param_1[0x22f] != 0) && (tw_crash_dump == '\0')) {
              param_1[0x230] = 0;
              param_1[0x231] = 0;
              iVar11 = 6;
              goto LAB_1c000ceea;
            }
            iVar11 = 1;
          }
LAB_1c000ce4c:
          param_1[0x219] = 0;
          goto LAB_1c000ceea;
        }
      }
      else {
        if (iVar11 != 6) goto LAB_1c000ceea;
        if (*(short *)(param_1 + 0x230) != 0) {
          uVar4 = tw_resp_drain(param_1,&s_EXE,(int *)0x0);
          if (((char)uVar4 == '\0') || (*(short *)((longlong)plVar2 + 0x3c) != 0))
          goto LAB_1c000cea7;
          if ((char)plVar2[9] == '\0') goto LAB_1c000ce29;
          uVar1 = *(ushort *)(param_1 + 0x230);
          lVar5 = *(longlong *)(param_1 + 0x24f);
          iVar8 = (&tw_timeout_msecs)[(ulonglong)uVar1 * 2];
          if (iVar8 == 0) {
            uVar1 = *(ushort *)(lVar5 + 8);
            pcVar12 = "Minimum firmware SRL: %d";
            *(ushort *)(param_1 + 0x4c) = uVar1;
            uVar10 = 4;
LAB_1c000cd7d:
            tw_msg_dev(param_1,uVar10,pcVar12,(ulonglong)uVar1);
          }
          else {
            if (iVar8 == 1) {
              _Dst = param_1 + 0x54;
              memcpy(_Dst,(void *)(lVar5 + 8),0x10);
              iVar8 = 0xf;
              lVar5 = 0xf;
              do {
                if (_Dst[lVar5] != 0x20) {
                  _Dst[(longlong)iVar8 + 1] = 0;
                  break;
                }
                iVar8 = iVar8 + -1;
                lVar5 = lVar5 + -1;
              } while (-1 < lVar5);
              if (iVar8 < 0) {
                *_Dst = 0;
              }
              pcVar12 = "Firmware version: %s";
            }
            else if (iVar8 == 2) {
              _Dst = param_1 + 0xb7;
              memcpy(_Dst,(void *)(lVar5 + 8),0x14);
              iVar8 = 0x13;
              lVar5 = 0x13;
              do {
                if (_Dst[lVar5] != 0x20) {
                  _Dst[(longlong)iVar8 + 1] = 0;
                  break;
                }
                iVar8 = iVar8 + -1;
                lVar5 = lVar5 + -1;
              } while (-1 < lVar5);
              if (iVar8 < 0) {
                *_Dst = 0;
              }
              pcVar12 = "Serial string: %s";
            }
            else {
              if (iVar8 != 3) {
                pcVar12 = "Connect> Invalid index=%d";
                uVar10 = 1;
                goto LAB_1c000cd7d;
              }
              _Dst = param_1 + 0x74;
              memcpy(_Dst,(void *)(lVar5 + 8),0x10);
              iVar8 = 0xf;
              lVar5 = 0xf;
              do {
                if (_Dst[lVar5] != 0x20) {
                  _Dst[(longlong)iVar8 + 1] = 0;
                  break;
                }
                iVar8 = iVar8 + -1;
                lVar5 = lVar5 + -1;
              } while (-1 < lVar5);
              if (iVar8 < 0) {
                *_Dst = 0;
              }
              pcVar12 = "Hardware model: %s";
            }
            tw_msg_dev(param_1,4,pcVar12,_Dst);
          }
        }
        uVar6 = (ulonglong)*(ushort *)(param_1 + 0x230);
        if (3 < *(int *)(&tw_fwinit_pcmds + uVar6 * 8)) {
          iVar11 = 1;
          goto LAB_1c000ce4c;
        }
        tw_buildcmd_param(plVar2,'\x01',*(undefined2 **)(param_1 + 0x24f),
                          *(undefined8 *)(param_1 + 599),*(undefined2 *)(&DAT_1c00178b4 + uVar6 * 8)
                          ,(&DAT_1c00178b6)[uVar6 * 8],(&DAT_1c00178b7)[uVar6 * 8]);
        *(short *)(param_1 + 0x230) = *(short *)(param_1 + 0x230) + 1;
        tw_request_start(plVar2);
        lVar5 = tw_time_msecs();
        *(int *)(param_1 + 0x22b) = (int)lVar5;
      }
LAB_1c000ce29:
      param_1[0x21c] = 1;
      goto LAB_1c000ceea;
    }
    param_3 = (ulonglong)tw_timeout_msecs;
    tw_flow_pause(param_1,&s_Connect,tw_timeout_msecs);
    cVar9 = '\x01';
  }
  tw_buildcmd_connect(plVar2,cVar9,param_3,param_4);
  *(undefined4 *)(plVar2 + 8) = 2;
  tw_request_start(plVar2);
  iVar11 = 5;
LAB_1c000ceea:
  *(int *)(param_1 + 0x232) = iVar11;
  return;
}



===== tw_reset_init @ 1c000cf10 =====

void tw_reset_init(byte *param_1,undefined8 param_2,char *param_3,char *param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = tw_time_msecs();
  param_1[0x243] = 1;
  param_1[0x244] = 0;
  param_1[0x23c] = 1;
  if (param_1[0x23b] == 0) {
    *(int *)(param_1 + 0x2f0) = *(int *)(param_1 + 0x2f0) + 1;
  }
  else {
    *(int *)(param_1 + 0x2ec) = *(int *)(param_1 + 0x2ec) + 1;
  }
  lVar5 = (ulonglong)*(ushort *)(param_1 + 0x245) * 0x19;
  iVar3 = (int)lVar4;
  *(int *)(param_1 + lVar5 + 0x2f4) = iVar3;
  param_1[lVar5 + 0x2f8] = param_1[0x23b] == 0;
  *(int *)(param_1 + lVar5 + 0x2fd) = iVar3 - *(int *)(param_1 + 0x23d);
  *(int *)(param_1 + 0x23d) = iVar3;
  tw_hware_status_display(param_1);
  if (param_1[0xf87] != 0) {
    if ((*(uint *)(param_1 + 0x296) & 0x100000) != 0) {
      cm_cmds_log((longlong *)(param_1 + 0xf7e),param_2,param_3,param_4);
    }
    cm_trig_reset((longlong *)(param_1 + 0xf7e),param_1[0x23b],param_3,param_4);
  }
  tw_flow_pause(param_1,"ResetInit",(tw_reset_retrycount + 1) * tw_timeout_msecs);
  uVar1 = *(uint *)(param_1 + 0x296);
  iVar3 = FUN_1c000a9fc((longlong)param_1,0,(undefined1 *)0x0,-1);
  uVar2 = tw_request_check(param_1,(byte)(uVar1 >> 0x14) & 1,'\0');
  *(uint *)(param_1 + lVar5 + 0x305) = (uint)uVar2;
  *(int *)(param_1 + lVar5 + 0x301) = iVar3;
  if ((uint)uVar2 != *(uint *)(param_1 + 0x2a4)) {
    tw_msg_dev(param_1,2,"ResetInit> InQueue=%u != Posted=%u",(ulonglong)(uint)uVar2);
  }
  tw_msg_dev(param_1,8,"ResetInit> Posted=%u Pended=%u",(ulonglong)(uint)uVar2);
  return;
}



===== FUN_1c000d080 @ 1c000d080 =====

longlong FUN_1c000d080(byte *param_1,undefined8 param_2,char *param_3,char *param_4)

{
  ushort uVar1;
  longlong lVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x243);
  if (tw_reset_retrycount < uVar1) {
    lVar2 = (ulonglong)(byte)(uVar1 >> 8) << 8;
  }
  else {
    *(int *)(param_1 + 0x223) = *(int *)(param_1 + 0x223) + 20000;
    if (uVar1 == 0) {
      tw_reset_init(param_1,param_2,param_3,param_4);
      tw_msg_dev(param_1,8,"ResetStart> Resetting controller...",param_4);
    }
    else {
      lVar2 = tw_time_msecs();
      *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x245) * 0x19 + 0x2f9) =
           (int)lVar2 - *(int *)(param_1 + 0x23d);
      *(short *)(param_1 + 0x245) = *(short *)(param_1 + 0x245) + 1;
      if (0x31 < *(ushort *)(param_1 + 0x245)) {
        param_1[0x245] = 0;
        param_1[0x246] = 0;
      }
      tw_msg_dev(param_1,1,"ResetStart> Retrying #%d: msecs=%u",
                 (ulonglong)*(ushort *)(param_1 + 0x243));
    }
    *(undefined2 *)(param_1 + 0x241) = *(undefined2 *)(param_1 + 0x2a4);
    lVar2 = tw_time_msecs();
    *(int *)(param_1 + 0x23d) = (int)lVar2;
    *(uint *)(*(longlong *)(param_1 + 0x40) + 0x20) =
         *(uint *)(*(longlong *)(param_1 + 0x40) + 0x20) | 0x100;
    LOCK();
    UNLOCK();
    lVar2 = tw_time_msecs();
    lVar2 = CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
    *(short *)(param_1 + 0x243) = *(short *)(param_1 + 0x243) + 1;
  }
  return lVar2;
}



===== tw_reset_clear @ 1c000d184 =====

void tw_reset_clear(byte *param_1)

{
  ushort uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  tw_resp_drain(param_1,&s_RST,(int *)0x0);
  uVar1 = tw_request_check(param_1,(byte)(*(uint *)(param_1 + 0x296) >> 0x14) & 1,'\x01');
  StorPortLogError(param_1,0,0,0,0,6,CONCAT22(*(undefined2 *)(param_1 + 0x241),uVar1) + -0x50000000)
  ;
  *(uint *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x245) * 0x19 + 0x309) =
       (uint)*(ushort *)(param_1 + 0x241) - (uint)uVar1;
  uVar1 = 0;
  if (*(short *)(param_1 + 0x14b) != 0) {
    do {
      uVar3 = (ulonglong)uVar1;
      uVar1 = uVar1 + 1;
      *(undefined8 *)(*(longlong *)(param_1 + 0x277) + uVar3 * 8) = 0;
    } while (uVar1 < *(ushort *)(param_1 + 0x14b));
  }
  lVar4 = 0xb;
  param_1[0x287] = 0;
  param_1[0x288] = 0;
  param_1[0x2a4] = 0;
  param_1[0x2a5] = 0;
  param_1[0x2a6] = 0;
  param_1[0x2a7] = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x25f) + 0x44) = 0;
  pbVar2 = param_1 + 0x1556;
  do {
    pbVar2[0] = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    pbVar2[4] = 0;
    pbVar2[5] = 0;
    pbVar2[6] = 0;
    pbVar2[7] = 0;
    pbVar2 = pbVar2 + 0x18;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  param_1[0x2a8] = 0;
  param_1[0x2a9] = 0;
  param_1[0x2aa] = 0;
  param_1[0x2ab] = 0;
  return;
}



===== tw_reset_done @ 1c000d28c =====

void tw_reset_done(byte *param_1,char param_2)

{
  longlong lVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_2 == '\0') {
    tw_flow_resume(param_1,"ResetFail");
  }
  *(undefined4 *)(param_1 + 0x223) = tw_timeout_msecs;
  lVar1 = tw_time_msecs();
  uVar4 = (int)lVar1 - *(int *)(param_1 + 0x23d);
  *(uint *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x245) * 0x19 + 0x2f9) = uVar4;
  if (param_2 == '\0') {
    pcVar3 = "ResetDone> Failed: %d msecs";
    uVar2 = 1;
  }
  else {
    pcVar3 = "ResetDone> Successful: %d msecs";
    uVar2 = 4;
  }
  tw_msg_dev(param_1,uVar2,pcVar3,(ulonglong)uVar4);
  *(short *)(param_1 + 0x245) = *(short *)(param_1 + 0x245) + 1;
  if (0x31 < *(ushort *)(param_1 + 0x245)) {
    param_1[0x245] = 0;
    param_1[0x246] = 0;
  }
  param_1[0x243] = 0;
  param_1[0x244] = 0;
  param_1[0x23b] = 0;
  param_1[0x23c] = 0;
  return;
}



===== tw_resp_drain @ 1c000d348 =====

undefined4 tw_resp_drain(byte *param_1,undefined1 *param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  uint uVar12;
  char *pcVar13;
  undefined1 *puVar14;
  
  uVar11 = 1;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  do {
    while( true ) {
      puVar7 = (undefined1 *)0x0;
      if (*(int *)(*(longlong *)(param_1 + 0x40) + 0xcc) == -1) {
        return CONCAT31(0xffffff,uVar11);
      }
      uVar12 = *(uint *)(*(longlong *)(param_1 + 0x40) + 200);
      if ((uVar12 & 1) == 0) {
        puVar7 = (undefined1 *)StorPortGetVirtualAddress(param_1,uVar12);
        uVar12 = (uint)*(ushort *)(puVar7 + 0x7d);
      }
      else {
        uVar12 = uVar12 >> 0x10;
      }
      uVar8 = tw_request_idchk(param_1,(ushort)uVar12,param_2);
      if ((char)uVar8 != '\0') break;
LAB_1c000d557:
      uVar11 = 0;
    }
    plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x277) + (ulonglong)uVar12 * 8);
    if ((*(ushort *)((longlong)plVar3 + 0x24) & 0x8000) != 0) {
      tw_pendio_delete((longlong *)*plVar3,plVar3,'\0');
    }
    if ((int)plVar3[8] == 1) {
      lVar4 = *(longlong *)(param_1 + 0x25f);
      puVar14 = &s_Swait;
      iVar2 = *(int *)(lVar4 + 0x44);
      if (iVar2 == 2) {
        lVar5 = *(longlong *)(param_1 + 0x267);
        puVar10 = (undefined1 *)0x800;
        sVar1 = *(short *)(lVar5 + 0x16);
        if (sVar1 != 0x31) {
          if (sVar1 != 0) {
            pcVar13 = &s__s>_Received_AEN__0x_02X;
            tw_msg_dev(param_1,0x800,"%s> Received AEN: 0x%02X",&s_Swait);
            tw_aen_get(param_1,lVar5);
            goto LAB_1c000d4d9;
          }
          pcVar13 = "%s> Finished reading AENs";
          tw_msg_dev(param_1,0x800,"%s> Finished reading AENs",&s_Swait);
          *(undefined4 *)(lVar4 + 0x44) = 0;
          goto LAB_1c000d515;
        }
        pcVar13 = "%s> Received AEN: TimeSync";
        tw_msg_dev(param_1,0x800,"%s> Received AEN: TimeSync",&s_Swait);
        *(undefined4 *)(lVar4 + 0x44) = 3;
      }
      else if (iVar2 == 4) {
        pcVar13 = "%s> Received relative time...";
        tw_msg_dev(param_1,0x800,"%s> Received relative time...",&s_Swait);
        *(undefined4 *)(lVar4 + 0x44) = 5;
      }
      else {
        if (iVar2 != 6) {
          pcVar13 = "%s> Ignoring: %s";
          puVar10 = (undefined1 *)0x2;
          tw_msg_dev(param_1,2,"%s> Ignoring: %s",&s_Swait);
          goto LAB_1c000d515;
        }
        pcVar13 = "%s> Received absolute time...";
        tw_msg_dev(param_1,0x800,"%s> Received absolute time...",&s_Swait);
LAB_1c000d4d9:
        *(undefined4 *)(lVar4 + 0x44) = 1;
      }
      puVar10 = &s_Swait;
      tw_dpc_call(param_1,&s_Swait);
    }
    else {
      puVar10 = param_2;
      pcVar13 = (char *)plVar3;
      puVar14 = puVar7;
      FUN_1c000d580((longlong *)param_1,param_2,plVar3,puVar7);
    }
LAB_1c000d515:
    tw_request_finish(plVar3,puVar10,pcVar13,(ulonglong)puVar14);
    if (puVar7 != (undefined1 *)0x0) {
      uVar9 = tw_hware_stuff(param_1,(longlong)puVar7,1);
      if ((char)uVar9 == '\0') {
        cVar6 = tw_fwstate_exec(param_1,2);
        if (cVar6 == '\0') goto LAB_1c000d557;
      }
    }
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
  } while( true );
}



===== FUN_1c000d580 @ 1c000d580 =====

void FUN_1c000d580(longlong *param_1,undefined8 param_2,longlong *param_3,void *param_4)

{
  undefined4 *puVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  byte bVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined7 uVar11;
  undefined8 uVar10;
  undefined1 uVar12;
  undefined1 uVar13;
  ushort uVar14;
  uint uVar15;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar16;
  undefined4 uVar17;
  
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  pbVar2 = (byte *)param_3[0x34];
  lVar3 = param_3[1];
  bVar6 = *pbVar2;
  uVar11 = (undefined7)((ulonglong)param_2 >> 8);
  if (param_4 == (void *)0x0) {
    uVar14 = 0;
  }
  else {
    uVar14 = *(ushort *)((longlong)param_4 + 0x16);
  }
  uVar15 = (-(uint)(*(char *)((longlong)param_1 + 0x217) != '\0') & 0xffffffa0) + 0x80;
  if ((*(uint *)(*param_3 + 0x296) & uVar15) != 0) {
    tw_xlate_opcode(CONCAT71((int7)((ulonglong)param_1 >> 8),
                             *(undefined1 *)((longlong)param_3 + 0x12)),
                    CONCAT71(uVar11,*(undefined1 *)((longlong)param_3 + 0x13)),
                    *(uint *)((longlong)param_3 + 0x14),*(byte *)(param_3 + 3),
                    (undefined4 *)((longlong)param_3 + 0x104));
    tw_time_msecs();
    uVar8 = (ulonglong)uVar15;
    param_1 = param_3;
    tw_msg_req(param_3,uVar15,"%s> Id=%-4d Posted=%-3u Msecs=%-6d KB=%-3d %s",param_2);
    uVar11 = (undefined7)(uVar8 >> 8);
  }
  if ((lVar3 != 0) && (*(char *)(lVar3 + 2) == '\x02')) {
    tw_ioctl_complete(lVar3,param_4);
    return;
  }
  if (uVar14 == 0) {
    if (lVar3 == 0) {
      return;
    }
    if (*(char *)(lVar3 + 2) == '\0') {
      tw_scsi_complete(lVar3);
      return;
    }
    return;
  }
  if (((bVar6 & 0x1f) == 0x10) && ((bVar6 = pbVar2[8], bVar6 == 0x12 || (bVar6 == 0xa0)))) {
    param_1 = (longlong *)0x10a;
    if (((ushort)(uVar14 - 0x10a) < 0x1f) &&
       (param_1 = (longlong *)0x40000009,
       (0x40000009U >> ((ushort)(uVar14 - 0x10a) & 0x1f) & 1) != 0)) {
      tw_xlate_opcode(CONCAT71(0x400000,*(undefined1 *)((longlong)param_3 + 0x12)),
                      CONCAT71(uVar11,*(undefined1 *)((longlong)param_3 + 0x13)),
                      *(uint *)((longlong)param_3 + 0x14),*(byte *)(param_3 + 3),
                      (undefined4 *)((longlong)param_3 + 0x104));
      tw_msg_req(param_3,8,"%s> Ignore: err=0x%04X %s",param_2);
      goto LAB_1c000d820;
    }
  }
  puVar1 = (undefined4 *)((longlong)param_3 + 0x104);
  puVar7 = tw_xlate_opcode(CONCAT71((int7)((ulonglong)param_1 >> 8),
                                    *(undefined1 *)((longlong)param_3 + 0x12)),
                           CONCAT71(uVar11,*(undefined1 *)((longlong)param_3 + 0x13)),
                           *(uint *)((longlong)param_3 + 0x14),*(byte *)(param_3 + 3),puVar1);
  uVar17 = (undefined4)((ulonglong)puVar7 >> 0x20);
  tw_time_msecs();
  uVar15 = 8;
  uVar10 = 8;
  tw_msg_req(param_3,8,"%s> Status=0x%X Msecs=%u %s",param_2);
  tw_str_parse((char *)((longlong)param_4 + 0x1a),uVar10,(longlong)puVar1);
  bVar5 = true;
  bVar6 = *(byte *)((longlong)param_4 + 0x19) & 7;
  if (bVar6 == 2) {
    uVar15 = 2;
  }
  else {
    if (bVar6 == 3) {
      uVar15 = 4;
    }
    else if (bVar6 != 4) {
      uVar15 = 1;
      goto LAB_1c000d799;
    }
    bVar5 = false;
  }
LAB_1c000d799:
  tw_msg_req(param_3,uVar15,"FW: %s",puVar1);
  if (bVar5) {
    lVar4 = param_3[1];
    if (lVar4 == 0) {
      uVar13 = 0;
      uVar12 = 0;
      uVar9 = 0;
    }
    else {
      uVar13 = *(undefined1 *)(lVar4 + 7);
      uVar12 = *(undefined1 *)(lVar4 + 6);
      uVar9 = *(undefined1 *)(lVar4 + 5);
    }
    StorPortLogError(*param_3,lVar4,uVar9,uVar12,uVar13,CONCAT44(uVar16,6),
                     CONCAT44(uVar17,uVar14 + 0xe0000000));
  }
  *(ushort *)((longlong)param_3 + 0x3c) = uVar14;
  uVar8 = tw_time_msecs();
  tw_request_show(param_3,uVar8 & 0xffffffff);
LAB_1c000d820:
  if ((lVar3 != 0) && (tw_srb_status(lVar3,'\x04'), (*(uint *)(lVar3 + 0xc) & 0x20) == 0)) {
    bVar6 = *(byte *)((longlong)param_4 + 0x7f);
    if (*(byte *)(lVar3 + 0xb) < *(byte *)((longlong)param_4 + 0x7f)) {
      bVar6 = *(byte *)(lVar3 + 0xb);
    }
    if ((*(void **)(lVar3 + 0x20) != (void *)0x0) && (bVar6 != 0)) {
      *(byte *)(lVar3 + 3) = *(byte *)(lVar3 + 3) | 0x80;
      memcpy(*(void **)(lVar3 + 0x20),param_4,(ulonglong)bVar6);
    }
  }
  return;
}



===== FUN_1c000d894 @ 1c000d894 =====

void FUN_1c000d894(byte *param_1)

{
  param_1[0x40] = 1;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) | 0x8000;
  *(undefined4 *)(param_1 + 0x38) = tw_timeout_msecs;
  tw_pendio_insert(*(byte **)param_1,param_1,'\0');
  tw_request_start((longlong *)param_1);
  return;
}



===== tw_sense_send @ 1c000d8d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_sense_send(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  longlong lVar4;
  undefined1 auStackY_78 [32];
  undefined1 local_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 local_30 [8];
  undefined1 local_28 [2];
  undefined1 local_26;
  undefined1 local_24;
  undefined1 local_22;
  undefined1 local_20;
  undefined1 local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  pbVar2 = *(byte **)(param_1 + 0x25f);
  iVar1 = *(int *)(pbVar2 + 0x44);
  if (iVar1 == 1) {
    tw_msg_dev(param_1,0x800,"%s> Sending Request_Sense...",&s_Ssend);
    tw_buildcmd_sense((longlong *)pbVar2,*(void **)(param_1 + 0x267),
                      *(undefined8 *)(param_1 + 0x26f));
    pbVar2[0x44] = 2;
    pbVar2[0x45] = 0;
    pbVar2[0x46] = 0;
    pbVar2[0x47] = 0;
  }
  else if (iVar1 == 3) {
    tw_msg_dev(param_1,0x800,"%s> Sending relative time...",&s_Ssend);
    puVar3 = tw_buildcmd_param((longlong *)pbVar2,'\0',*(undefined2 **)(param_1 + 0x267),
                               *(undefined8 *)(param_1 + 0x26f),0x840a,3,4);
    StorPortQuerySystemTime(local_30);
    ExSystemTimeToLocalTime(local_30,&local_38);
    lVar4 = SUB168(SEXT816(-0x29406b2a1a85bd43) *
                   SEXT816(CONCAT17(uStack_31,
                                    CONCAT16(uStack_32,
                                             CONCAT15(uStack_33,
                                                      CONCAT14(uStack_34,
                                                               CONCAT13(uStack_35,
                                                                        CONCAT12(uStack_36,
                                                                                 CONCAT11(uStack_37,
                                                                                          local_38))
                                                                       )))))),8) +
            CONCAT17(uStack_31,
                     CONCAT16(uStack_32,
                              CONCAT15(uStack_33,
                                       CONCAT14(uStack_34,
                                                CONCAT13(uStack_35,
                                                         CONCAT12(uStack_36,
                                                                  CONCAT11(uStack_37,local_38)))))))
    ;
    lVar4 = ((lVar4 >> 0x17) + -0x2b6148580) - (lVar4 >> 0x3f);
    *(int *)(puVar3 + 4) = (int)lVar4 + (int)(lVar4 / 0x93a80) * -0x93a80;
    pbVar2[0x44] = 4;
    pbVar2[0x45] = 0;
    pbVar2[0x46] = 0;
    pbVar2[0x47] = 0;
  }
  else {
    if (iVar1 != 5) {
      return;
    }
    tw_msg_dev(param_1,0x800,"%s> Sending absolute time...",&s_Ssend);
    puVar3 = tw_buildcmd_param((longlong *)pbVar2,'\0',*(undefined2 **)(param_1 + 0x267),
                               *(undefined8 *)(param_1 + 0x26f),0x840a,4,8);
    if (tw_crash_dump == '\0') {
      StorPortQuerySystemTime(&local_38);
      ExSystemTimeToLocalTime(&local_38,local_30);
      RtlTimeToTimeFields(local_30,local_28);
      local_38 = 0;
      uStack_31 = local_28[1];
      uStack_33 = local_26;
      uStack_34 = local_24;
      uStack_35 = local_22;
      uStack_36 = local_20;
      uStack_37 = local_1e;
      uStack_32 = local_28[0];
    }
    *(uint *)(puVar3 + 4) = CONCAT13(uStack_35,CONCAT12(uStack_36,CONCAT11(uStack_37,local_38)));
    *(uint *)(puVar3 + 6) = CONCAT13(uStack_31,CONCAT12(uStack_32,CONCAT11(uStack_33,uStack_34)));
    pbVar2[0x44] = 6;
    pbVar2[0x45] = 0;
    pbVar2[0x46] = 0;
    pbVar2[0x47] = 0;
  }
  FUN_1c000d894(pbVar2);
  return;
}



===== tw_isr @ 1c000db04 =====

void tw_isr(byte *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint local_res10 [6];
  
  *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7fa) =
       *(int *)(param_1 + (ulonglong)*(ushort *)(param_1 + 0x2bd) * 0x20 + 0x7fa) + 1;
  if ((param_2 >> 2 & 1) != 0) {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x9c);
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xa0) = 0xffffffff;
    LOCK();
    UNLOCK();
    if ((uVar1 >> 0x15 & 1) != 0) {
      tw_msg_dev(param_1,8,"ISR> Received hardware error interrupt",param_4);
      tw_hware_status_display(param_1);
      tw_fwstate_exec(param_1,2);
      return;
    }
    if ((uVar1 >> 0x12 & 1) != 0) {
      if (*(int *)(*(longlong *)(param_1 + 0x25f) + 0x44) == 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 0x25f) + 0x44) = 1;
        tw_dpc_call(param_1,&s_ISR);
      }
      else {
        tw_msg_dev(param_1,0x800,"%s> Currently processing AENs",&s_ISR);
      }
    }
  }
  tw_resp_drain(param_1,&s_ISR,(int *)local_res10);
  if (*(uint *)(param_1 + 0x2c8) < local_res10[0]) {
    *(uint *)(param_1 + 0x2c8) = local_res10[0];
  }
  return;
}



===== tw_dpc_init @ 1c000dc00 =====

undefined1 tw_dpc_init(byte *param_1)

{
  code *pcVar1;
  
  pcVar1 = tw_dpc_exec;
  StorPortNotification(0x1001,param_1,param_1 + 0x1ce);
  param_1[0x1cd] = 1;
  tw_msg_dev(param_1,8,"DPC is now initialized",pcVar1);
  return 1;
}



===== tw_dpc_call @ 1c000dc48 =====

void tw_dpc_call(byte *param_1,undefined8 param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined4 local_res18 [4];
  
  if (tw_crash_dump == '\0') {
    if (param_1[0x1cd] != 0) {
      tw_msg_dev(param_1,0x800,"%s> Request DPC...",param_2);
      local_res18[0] = 0;
      StorPortNotification(0x1002,param_1,param_1 + 0x1ce,0,0,local_res18);
      return;
    }
    pcVar2 = "%s> Not initialized yet...";
    uVar1 = 2;
  }
  else {
    pcVar2 = "%s> MemDump: Ignoring request for DPC";
    uVar1 = 8;
  }
  tw_msg_dev(param_1,uVar1,pcVar2,param_2);
  return;
}



===== tw_dpc_exec @ 1c000dcd0 =====

void tw_dpc_exec(undefined8 param_1,byte *param_2)

{
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  StorPortNotification(0x1003,param_2,2,0,local_28);
  tw_sense_send(param_2);
  StorPortNotification(0x1004,param_2,local_28);
  return;
}



===== tw_buildcmd_connect @ 1c000dd2c =====

void tw_buildcmd_connect(longlong *param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined2 uVar1;
  byte *pbVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  bool bVar5;
  
  tw_request_init(param_1,0);
  pbVar2 = (byte *)param_1[0x34];
  bVar5 = tw_dma64bit != '\0';
  *pbVar2 = *pbVar2 & 0xe1 | 1;
  if (bVar5) {
    *(uint *)(pbVar2 + 8) = *(uint *)(pbVar2 + 8) | 1;
  }
  if (param_2 == '\0') {
    pbVar2[6] = 1;
    pbVar2[7] = 0;
    puVar3 = (ushort *)0x4;
    pbVar2[1] = 3;
    tw_msg_dev((byte *)*param_1,4,"BuildConn> Disconnection",param_4);
  }
  else {
    pbVar2[1] = 6;
    puVar4 = &s_32;
    uVar1 = *(undefined2 *)(*param_1 + 0x14b);
    *(uint *)(pbVar2 + 8) = *(uint *)(pbVar2 + 8) | 2;
    *(undefined2 *)(pbVar2 + 6) = uVar1;
    pbVar2[0xc] = 0x28;
    pbVar2[0xd] = 0;
    pbVar2[0x10] = 0;
    pbVar2[0x11] = 0;
    pbVar2[0x12] = 0x33;
    pbVar2[0x13] = 0;
    if ((*(uint *)(pbVar2 + 8) & 1) != 0) {
      puVar4 = &s_64;
    }
    puVar3 = (ushort *)0x4;
    tw_msg_dev((byte *)*param_1,4,"BuildConn> %s-bit: SRL=%u MaxReqs=%u",puVar4);
  }
  tw_request_driver(param_1,puVar3);
  return;
}



===== tw_buildcmd_param @ 1c000de00 =====

undefined2 *
tw_buildcmd_param(longlong *param_1,char param_2,undefined2 *param_3,undefined8 param_4,
                 undefined2 param_5,byte param_6,byte param_7)

{
  byte *pbVar1;
  ushort *puVar2;
  bool bVar3;
  
  tw_request_init(param_1,0);
  pbVar1 = (byte *)param_1[0x34];
  pbVar1[1] = 2;
  pbVar1[3] = 0;
  bVar3 = tw_dma64bit != '\0';
  *pbVar1 = 0x13U - (param_2 != '\0') & 0x1f | 0x40;
  pbVar1[6] = 1;
  pbVar1[7] = 0;
  if (bVar3) {
    *(undefined8 *)(pbVar1 + 8) = param_4;
    pbVar1[0x10] = 0;
    pbVar1[0x11] = 2;
    pbVar1[0x12] = 0;
    pbVar1[0x13] = 0;
    pbVar1[1] = pbVar1[1] + 4;
  }
  puVar2 = (ushort *)0x0;
  memset(param_3,0,0x200);
  *param_3 = param_5;
  param_3[1] = (ushort)param_6;
  param_3[2] = (ushort)param_7;
  param_1[5] = (longlong)param_3;
  *(undefined4 *)(param_1 + 6) = 0x200;
  tw_request_driver(param_1,puVar2);
  return param_3;
}



===== tw_buildcmd_sense @ 1c000deb4 =====

void tw_buildcmd_sense(longlong *param_1,void *param_2,undefined8 param_3)

{
  byte *pbVar1;
  ushort *puVar2;
  bool bVar3;
  
  tw_request_init(param_1,0);
  pbVar1 = (byte *)param_1[0x34];
  pbVar1[1] = 0;
  pbVar1[5] = 0x10;
  *pbVar1 = *pbVar1 & 0xf0 | 0x10;
  *(ushort *)(pbVar1 + 2) = *(ushort *)(pbVar1 + 2) & 0xfff;
  bVar3 = tw_dma64bit != '\0';
  pbVar1[6] = 0;
  pbVar1[7] = 0;
  pbVar1[8] = 3;
  pbVar1[0xc] = 0x80;
  if (bVar3) {
    *(undefined8 *)(pbVar1 + 0x18) = param_3;
    pbVar1[0x20] = 0;
    pbVar1[0x21] = 2;
    pbVar1[0x22] = 0;
    pbVar1[0x23] = 0;
  }
  puVar2 = (ushort *)0x0;
  pbVar1[6] = 1;
  pbVar1[7] = 0;
  memset(param_2,0,0x80);
  param_1[5] = (longlong)param_2;
  *(undefined4 *)(param_1 + 6) = 0x80;
  tw_request_driver(param_1,puVar2);
  return;
}



===== tw_hware_status_display @ 1c000df64 =====

void tw_hware_status_display(byte *param_1)

{
  tw_msg_dev(param_1,8,"HwStatus> Status=%08X Hmask=%08X Hint=%08X OutD=%08X",
             (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x40) + 0xbc));
  return;
}



===== tw_hware_ready @ 1c000dfb8 =====

ulonglong tw_hware_ready(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  
  tw_time_msecs();
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0xbc);
  if ((uVar1 >> 0x15 & 1) != 0) {
    if ((param_1[0x292] & 2) == 0) {
      tw_hware_status_display(param_1);
      tw_msg_dev(param_1,1,"HwError> Have controller error!",param_4);
      uVar2 = StorPortLogError(param_1,0,0,0,0,6,uVar1 | 0xf0000000);
      goto LAB_1c000e058;
    }
    tw_msg_dev(param_1,8,"HwError> Ignoring controller error...",param_4);
  }
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0xbc);
  uVar2 = (ulonglong)uVar1;
  if ((uVar1 >> 0xd & 1) != 0) {
    return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
LAB_1c000e058:
  return uVar2 & 0xffffffffffffff00;
}



===== tw_hware_stuff @ 1c000e05c =====

undefined8 tw_hware_stuff(byte *param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined1 local_res18 [8];
  undefined8 local_res20;
  
  if (1 < param_3) {
    in_RAX = tw_msg_dev(param_1,8,"HwStuff> Submitting %d addresses",(ulonglong)param_3);
  }
  do {
    uVar5 = 0;
    if (param_3 == 0) {
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
    puVar7 = local_res18;
    param_3 = param_3 - 1;
    local_res20 = StorPortGetPhysicalAddress(param_1,0,param_2);
    uVar3 = (undefined4)((ulonglong)local_res20 >> 0x20);
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xcc) = uVar3;
    LOCK();
    UNLOCK();
    uVar4 = (undefined4)local_res20;
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 200) = uVar4;
    LOCK();
    UNLOCK();
    uVar1 = **(uint **)(param_1 + 0x40);
    while ((uVar1 >> 0xd & 1) != 0) {
      if (param_3 == 0) {
        pcVar6 = "HwStuff> Inboard free list queue overrun!";
LAB_1c000e157:
        uVar2 = tw_msg_dev(param_1,1,pcVar6,puVar7);
        return uVar2 & 0xffffffffffffff00;
      }
      if (uVar5 == 0) {
        puVar7 = (undefined1 *)(ulonglong)param_3;
        tw_msg_dev(param_1,8,"HwStuff> Wait for inboard free list queue (count=%d)...",puVar7);
      }
      StorPortStallExecution(1000);
      uVar5 = uVar5 + 1;
      if (1000 < uVar5) {
        pcVar6 = "HwStuff> Failed waiting for free list queue!";
        goto LAB_1c000e157;
      }
      *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0xcc) = uVar3;
      LOCK();
      UNLOCK();
      *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 200) = uVar4;
      LOCK();
      UNLOCK();
      uVar1 = **(uint **)(param_1 + 0x40);
    }
    in_RAX = (ulonglong)uVar1;
    param_2 = param_2 + 0x80;
  } while( true );
}



===== FUN_1c000e184 @ 1c000e184 =====

char * FUN_1c000e184(byte param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = &DAT_1c0017370;
  uVar1 = 0;
  do {
    if (*puVar2 == (uint)param_1) {
      if (param_1 == 0x1b) {
        tw_string(param_3,0x96,"SCSI(%s.%s)",(&PTR_s_READ6_1c0017378)[(longlong)(int)uVar1 * 2]);
        return param_3;
      }
      tw_string(param_3,0x96,"SCSI(%s)",(&PTR_s_READ6_1c0017378)[(longlong)(int)uVar1 * 2]);
      return param_3;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (uVar1 < 0x1e);
  tw_string(param_3,0x96,"SCSI(0x%02X)",(ulonglong)param_1);
  return param_3;
}



===== FUN_1c000e240 @ 1c000e240 =====

char * FUN_1c000e240(uint param_1,undefined8 param_2,char *param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if ((param_1 & 0xffff0000) == 0xb0000000) {
    param_1 = param_1 & 0xffff00ff;
  }
  uVar2 = 0;
  puVar1 = &DAT_1c0017550;
  while (*puVar1 != param_1) {
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 4;
    if (0x31 < uVar2) {
      tw_string(param_3,0x96,"IOCTL(0x%08X)",(ulonglong)param_1);
      return param_3;
    }
  }
  if ((param_1 & 0xffff0000) == 0xb0000000) {
    if ((param_1 & 0xffff) == 3) {
      tw_string(param_3,0x96,"IOCTL(%s%s%s%s%s%s%s)",
                (&PTR_s_NOP_1c0017558)[(longlong)(int)uVar2 * 2]);
      return param_3;
    }
    if ((param_1 & 0xffff) - 4 < 4) {
      tw_string(param_3,0x96,"IOCTL(%s%s%s)",(&PTR_s_NOP_1c0017558)[(longlong)(int)uVar2 * 2]);
      return param_3;
    }
  }
  tw_string(param_3,0x96,"IOCTL(%s)",(&PTR_s_NOP_1c0017558)[(longlong)(int)uVar2 * 2]);
  return param_3;
}



===== tw_xlate_opmask @ 1c000e428 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_xlate_opmask(byte *param_1,byte param_2,byte param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 auStack_138 [32];
  char *local_118;
  char *local_110;
  char *local_108;
  char *local_100;
  byte local_f8;
  byte local_f7;
  byte local_f6;
  uint local_f4;
  char local_e8 [160];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  bVar5 = 0;
  local_f8 = param_2 & 1;
  local_f7 = param_3;
  local_f6 = param_2;
  local_f4 = param_4;
  if (local_f8 != 0) {
    if ((param_3 & 1) != 0) {
      for (bVar3 = 0; bVar3 < 0xb; bVar3 = bVar3 + 1) {
        uVar1 = (&DAT_1c0017060)[(ulonglong)bVar3 * 4];
        tw_string(local_e8,0x96,"SRB(%s)",(&PTR_s_EXECUTE_SCSI_1c0017068)[(ulonglong)bVar3 * 2]);
        if ((param_4 & param_5) == (uVar1 & param_5)) {
          local_118 = local_e8;
          tw_msg_dev(param_1,0x10000,"%sSYS:%s","              ");
        }
      }
    }
    uVar1 = local_f4;
    if ((local_f7 & 4) != 0) {
      for (bVar3 = 0; bVar3 < 5; bVar3 = bVar3 + 1) {
        uVar2 = (&DAT_1c0017250)[(ulonglong)bVar3 * 4];
        tw_string(local_e8,0x96,"PNP(%s)",(&PTR_s_START_1c0017258)[(ulonglong)bVar3 * 2]);
        if ((uVar1 & param_5) == (uVar2 & param_5)) {
          local_118 = local_e8;
          tw_msg_dev(param_1,0x10000,"%sSYS:%s","              ");
        }
      }
    }
    uVar1 = local_f4;
    if ((local_f7 & 8) != 0) {
      for (bVar3 = 0; bVar3 < 6; bVar3 = bVar3 + 1) {
        uVar2 = (&DAT_1c0017140)[(ulonglong)bVar3 * 4];
        tw_string(local_e8,0x96,"PWR(%s)",(&PTR_s_SLEEP_1c0017148)[(ulonglong)bVar3 * 2]);
        if ((uVar1 & param_5) == (uVar2 & param_5)) {
          local_118 = local_e8;
          tw_msg_dev(param_1,0x10000,"%sSYS:%s","              ");
        }
      }
    }
  }
  uVar1 = local_f4;
  bVar3 = local_f6;
  if ((local_f7 & 0x10) != 0) {
    for (bVar4 = 0; bVar4 < 0x1e; bVar4 = bVar4 + 1) {
      uVar2 = (&DAT_1c0017370)[(ulonglong)bVar4 * 4];
      tw_string(local_e8,0x96,"SCSI(%s)",(&PTR_s_READ6_1c0017378)[(ulonglong)bVar4 * 2]);
      if ((uVar1 & param_5) == (uVar2 & param_5)) {
        local_108 = "";
        if ((bVar3 & 4) != 0) {
          local_108 = "DRV:";
        }
        local_110 = "";
        if ((bVar3 & 2) != 0) {
          local_110 = "APP:";
        }
        local_118 = "";
        if (local_f8 != 0) {
          local_118 = "SYS:";
        }
        local_100 = local_e8;
        tw_msg_dev(param_1,0x10000,"%s%s%s%s%s","              ");
      }
    }
  }
  uVar1 = local_f4;
  if (((local_f7 & 0x20) != 0) && ((bVar3 & 3) != 0)) {
    for (bVar4 = 0; bVar4 < 3; bVar4 = bVar4 + 1) {
      uVar2 = (&DAT_1c0017110)[(ulonglong)bVar4 * 4];
      tw_string(local_e8,0x96,"ATA(%s)",(&PTR_s_SET_STANDBY_1c0017118)[(ulonglong)bVar4 * 2]);
      if ((uVar1 & param_5) == (uVar2 & param_5)) {
        local_110 = "";
        if ((bVar3 & 2) != 0) {
          local_110 = "APP:";
        }
        local_118 = "";
        if (local_f8 != 0) {
          local_118 = "SYS:";
        }
        local_108 = local_e8;
        tw_msg_dev(param_1,0x10000,"%s%s%s%s","              ");
      }
    }
  }
  uVar1 = local_f4;
  if (((local_f7 & 0x40) != 0) && ((bVar3 & 6) != 0)) {
    for (bVar4 = 0; bVar4 < 0x20; bVar4 = bVar4 + 1) {
      tw_string(local_e8,0x96,"FWARE(%s)",(&tw_fware_opstrs)[bVar4]);
      if ((uVar1 & param_5) == (bVar4 & param_5)) {
        local_110 = "";
        local_118 = "";
        if ((bVar3 & 4) != 0) {
          local_110 = "DRV:";
        }
        if ((bVar3 & 2) != 0) {
          local_118 = "APP:";
        }
        local_108 = local_e8;
        tw_msg_dev(param_1,0x10000,"%s%s%s%s","              ");
      }
    }
  }
  uVar1 = local_f4;
  if ((char)local_f7 < '\0') {
    if (local_f8 != 0) {
      for (bVar3 = 0; bVar3 < 0xd; bVar3 = bVar3 + 1) {
        uVar2 = (&DAT_1c00172a0)[(ulonglong)bVar3 * 4];
        tw_string(local_e8,0x96,"SYSIO(%s)",(&PTR_s_SCSI_IDENTIFY_1c00172a8)[(ulonglong)bVar3 * 2]);
        if ((uVar1 & param_5) == (uVar2 & param_5)) {
          local_118 = local_e8;
          tw_msg_dev(param_1,0x10000,"%sSYS:%s","              ");
        }
      }
      bVar3 = local_f6;
    }
    if ((bVar3 & 2) != 0) {
      for (; bVar5 < 0x32; bVar5 = bVar5 + 1) {
        uVar1 = (&DAT_1c0017550)[(ulonglong)bVar5 * 4];
        tw_string(local_e8,0x96,"IOCTL(%s)",(&PTR_s_NOP_1c0017558)[(ulonglong)bVar5 * 2]);
        if ((local_f4 & param_5) == (uVar1 & param_5)) {
          local_118 = local_e8;
          tw_msg_dev(param_1,0x10000,"%sAPP:%s","              ");
        }
      }
    }
  }
  return;
}



===== tw_xlate_opcode @ 1c000e9fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
tw_xlate_opcode(ulonglong param_1,ulonglong param_2,uint param_3,byte param_4,undefined4 *param_5)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  undefined7 uVar7;
  uint *puVar5;
  char *pcVar6;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  undefined1 auStack_e8 [32];
  uint local_c8;
  uint local_c0;
  char local_b8 [160];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  uVar10 = (ulonglong)param_3;
  local_b8[0] = '\0';
  uVar7 = (undefined7)(param_2 >> 8);
  bVar2 = (byte)param_3;
  if ((param_2 & 0x10) != 0) {
    FUN_1c000e184(bVar2,CONCAT71(uVar7,param_4),local_b8);
    goto LAB_1c000ed01;
  }
  if ((param_2 & 0x40) == 0) {
    if ((char)param_2 < '\0') {
      if ((param_1 & 2) != 0) {
        FUN_1c000e240(param_3,CONCAT71(uVar7,param_4),local_b8);
        goto LAB_1c000ed01;
      }
      uVar3 = 0;
      puVar5 = &DAT_1c00172a0;
      do {
        if (*puVar5 == param_3) {
          puVar11 = (&PTR_s_SCSI_IDENTIFY_1c00172a8)[(longlong)(int)uVar3 * 2];
          pcVar6 = "IOCTL(%s)";
          goto LAB_1c000ea74;
        }
        uVar3 = uVar3 + 1;
        puVar5 = puVar5 + 4;
      } while (uVar3 < 0xd);
      pcVar6 = "IOCTL(0x%08X)";
    }
    else if ((param_2 & 1) == 0) {
      if ((param_2 & 2) == 0) {
        bVar4 = (byte)(param_3 >> 0x18);
        if ((param_2 & 4) == 0) {
          if ((param_2 & 8) == 0) {
            if ((param_2 & 0x20) == 0) {
              pcVar6 = "OPCODE(0x%08X)";
            }
            else if (bVar2 == 0xb0) {
              uVar3 = 0;
              uVar9 = param_3 >> 0x10 & 0xff;
              uVar10 = (ulonglong)uVar9;
              puVar5 = &DAT_1c00171a0;
              do {
                if (*puVar5 == uVar9) {
                  puVar11 = (&PTR_s_ATTRIBUTES_1c00171a8)[(longlong)(int)uVar3 * 2];
                  pcVar6 = "SMART(%s)";
                  goto LAB_1c000ea74;
                }
                uVar3 = uVar3 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar3 < 0xb);
              pcVar6 = "SMART(0x%02X)";
            }
            else {
              uVar3 = 0;
              puVar5 = &DAT_1c0017110;
              do {
                if (*puVar5 == param_3) {
                  puVar11 = (&PTR_s_SET_STANDBY_1c0017118)[(longlong)(int)uVar3 * 2];
                  pcVar6 = "ATA(%s)";
                  goto LAB_1c000ea74;
                }
                uVar3 = uVar3 + 1;
                puVar5 = puVar5 + 4;
              } while (uVar3 < 3);
              pcVar6 = "ATA(0x%02X)";
            }
            goto LAB_1c000ecf3;
          }
          puVar12 = &DAT_1c0017140;
          uVar3 = 0;
          puVar5 = &DAT_1c0017140;
          do {
            if (*puVar5 == (uint)bVar4) {
              pcVar6 = "PWR(%s.D%d)";
              goto LAB_1c000ebc9;
            }
            uVar3 = uVar3 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar3 < 6);
          pcVar6 = "PWR(%d.D%d)";
        }
        else {
          puVar12 = &DAT_1c0017250;
          uVar3 = 0;
          puVar5 = &DAT_1c0017250;
          do {
            if (*puVar5 == (uint)bVar4) {
              pcVar6 = "PNP(%s.%d)";
LAB_1c000ebc9:
              local_c8 = param_3 >> 0x10 & 0xff;
              tw_string(local_b8,0x96,pcVar6,*(undefined8 *)(puVar12 + (longlong)(int)uVar3 * 4 + 2)
                       );
              goto LAB_1c000ed01;
            }
            uVar3 = uVar3 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar3 < 5);
          pcVar6 = "PNP(%d.%d)";
        }
        local_c8 = param_3 >> 0x10 & 0xff;
        tw_string(local_b8,0x96,pcVar6,(ulonglong)bVar4);
        goto LAB_1c000ed01;
      }
      uVar10 = (ulonglong)(param_3 >> 0x10);
      pcVar6 = "WMI(0x%02X)";
    }
    else {
      uVar3 = 0;
      puVar5 = &DAT_1c0017060;
      do {
        if (*puVar5 == param_3) {
          puVar11 = (&PTR_s_EXECUTE_SCSI_1c0017068)[(longlong)(int)uVar3 * 2];
          pcVar6 = "SRB(%s)";
          goto LAB_1c000ea74;
        }
        uVar3 = uVar3 + 1;
        puVar5 = puVar5 + 4;
      } while (uVar3 < 0xb);
      pcVar6 = "SRB(0x%02X)";
    }
  }
  else {
    if (bVar2 < 0x20) {
      if ((byte)(bVar2 - 0x12) < 2) {
        local_c8 = param_3 >> 0x10;
        local_c0 = (uint)param_4;
        tw_string(local_b8,0x96,"FWARE(%s.%04X.%d)",(&tw_fware_opstrs)[param_3 & 0xff]);
      }
      else {
        pcVar6 = "FWARE(%s)";
        puVar11 = (&tw_fware_opstrs)[param_3 & 0xff];
LAB_1c000ea74:
        tw_string(local_b8,0x96,pcVar6,puVar11);
      }
      goto LAB_1c000ed01;
    }
    pcVar6 = "FWARE(0x%02X)";
  }
LAB_1c000ecf3:
  tw_string(local_b8,0x96,pcVar6,uVar10);
LAB_1c000ed01:
  if ((param_1 & 1) == 0) {
    if ((param_1 & 2) == 0) {
      if ((param_1 & 4) == 0) {
        *param_5 = 0x3a3f3f3f;
      }
      else {
        *param_5 = 0x3a565244;
      }
    }
    else {
      *param_5 = 0x3a505041;
    }
  }
  else {
    *param_5 = 0x3a535953;
  }
  *(undefined1 *)(param_5 + 1) = 0;
  pcVar6 = (char *)((longlong)param_5 + -1);
  do {
    pcVar6 = pcVar6 + 1;
  } while (*pcVar6 != '\0');
  lVar8 = 0;
  do {
    cVar1 = local_b8[lVar8];
    pcVar6[lVar8] = cVar1;
    lVar8 = lVar8 + 1;
  } while (cVar1 != '\0');
  return param_5;
}



===== FUN_1c000ed9c @ 1c000ed9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1c000ed9c(byte *param_1,ushort param_2,ushort param_3,ulonglong param_4,uint param_5,
                  undefined8 param_6)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined1 auStack_238 [32];
  char *local_218;
  char *local_210;
  char *local_208;
  undefined8 local_200;
  char local_1f8 [8];
  char local_1f0 [16];
  char local_1e0 [24];
  char local_1c8 [160];
  char local_128 [208];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_238;
  uVar7 = (uint)param_4;
  if (param_1 == (byte *)0x0) {
    uVar3 = 0xff;
    iVar1 = tw_msg_control;
    uVar2 = tw_dbg_control;
  }
  else {
    uVar3 = (ushort)*param_1;
    iVar1 = *(int *)(param_1 + 0x296);
    uVar2 = *(uint *)(param_1 + 0x292);
  }
  if (uVar3 == 0xff) {
    local_1f8[0] = '-';
    local_1f8[1] = '\0';
  }
  else {
    param_4 = (ulonglong)uVar3;
    tw_string(local_1f8,5,"%u",param_4);
  }
  if (param_2 == 0xff) {
    builtin_strncpy(local_1f0,"--.- ",6);
  }
  else {
    param_4 = (ulonglong)param_2;
    if (param_3 == 0xff) {
      tw_string(local_1f0,10,"%2u.- ",param_4);
    }
    else {
      local_218 = (char *)CONCAT44(local_218._4_4_,(uint)param_3);
      tw_string(local_1f0,10,"%2u.%-1u ",param_4);
    }
  }
  if (iVar1 < 0) {
    if (uVar7 == 0) {
      lVar4 = tw_time_msecs();
      uVar7 = (uint)lVar4;
    }
LAB_1c000eec6:
    tw_string(local_1e0,0xb," %08X ",(ulonglong)uVar7);
  }
  else {
    if (uVar7 != 0) goto LAB_1c000eec6;
    tw_string(local_1e0,0xb," ",param_4);
  }
  if (param_5 == 1) {
    local_208 = "**Err*) ";
  }
  else if (param_5 == 2) {
    local_208 = "++Warn) ";
  }
  else if (param_5 == 4) {
    local_208 = "..Info) ";
  }
  else {
    local_208 = "";
  }
  local_200 = param_6;
  local_210 = local_1e0;
  local_218 = local_1f0;
  tw_string(local_1c8,0x96,"%s.%s%s%s%s",local_1f8);
  if ((tw_trace_context == 0) || ((uVar2 & 0x80) != 0)) goto LAB_1c000f416;
  if (param_5 < 0x201) {
    if (param_5 == 0x200) {
      if ((DAT_1c0017024 & 0x200) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x13;
      goto LAB_1c000f3e6;
    }
    if (param_5 != 1) {
      if (param_5 == 2) {
        if ((DAT_1c0017024 & 2) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0xb;
      }
      else if (param_5 == 4) {
        if ((DAT_1c0017024 & 4) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0xc;
      }
      else if (param_5 == 8) {
        if ((DAT_1c0017024 & 8) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0xd;
      }
      else if (param_5 == 0x10) {
        if ((DAT_1c0017024 & 0x10) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0xe;
      }
      else if (param_5 == 0x20) {
        if ((DAT_1c0017024 & 0x20) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0xf;
      }
      else if (param_5 == 0x40) {
        if ((DAT_1c0017024 & 0x40) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0x10;
      }
      else if (param_5 == 0x80) {
        if ((DAT_1c0017024 & 0x80) == 0) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0x11;
      }
      else {
        if ((param_5 != 0x100) || ((DAT_1c0017024 & 0x100) == 0)) goto LAB_1c000f416;
        lVar4 = -1;
        do {
          lVar5 = lVar4 + 1;
          lVar6 = lVar4 + 1;
          lVar4 = lVar5;
        } while (local_1c8[lVar6] != '\0');
        uVar8 = 0x12;
      }
      goto LAB_1c000f3e6;
    }
    if ((DAT_1c0017024 & 1) == 0) goto LAB_1c000f416;
    lVar4 = -1;
    do {
      lVar6 = lVar4;
      lVar4 = lVar6 + 1;
    } while (local_1c8[lVar6 + 1] != '\0');
    local_210 = (char *)(lVar6 + 2);
    uVar8 = 10;
  }
  else {
    if (param_5 == 0x400) {
      if ((DAT_1c0017024 & 0x400) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x14;
    }
    else if (param_5 == 0x800) {
      if ((DAT_1c0017024 & 0x800) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x15;
    }
    else if (param_5 == 0x1000) {
      if ((DAT_1c0017024 & 0x1000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x16;
    }
    else if (param_5 == 0x2000) {
      if ((DAT_1c0017024 & 0x2000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x17;
    }
    else if (param_5 == 0x8000) {
      if ((DAT_1c0017024 & 0x8000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x18;
    }
    else if (param_5 == 0x10000) {
      if ((DAT_1c0017024 & 0x10000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x19;
    }
    else if (param_5 == 0x20000) {
      if ((DAT_1c0017024 & 0x20000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x1a;
    }
    else if (param_5 == 0x40000) {
      if ((DAT_1c0017024 & 0x40000) == 0) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x1b;
    }
    else {
      if ((param_5 != 0x80000) || ((DAT_1c0017024 & 0x80000) == 0)) goto LAB_1c000f416;
      lVar4 = -1;
      do {
        lVar5 = lVar4 + 1;
        lVar6 = lVar4 + 1;
        lVar4 = lVar5;
      } while (local_1c8[lVar6] != '\0');
      uVar8 = 0x1c;
    }
LAB_1c000f3e6:
    local_210 = (char *)(lVar5 + 1);
  }
  local_208 = (char *)0x0;
  local_218 = local_1c8;
  (*(code *)pfnWppTraceMessage)
            (PTR_WPP_ThisDir_CTLGUID_3ware10k_1c0017018,0x2b,
             &WPP_5b3d1a04b1f782cf0c11084d5ffe0f2a_Traceguids,uVar8);
LAB_1c000f416:
  if ((uVar2 & 0x10000) != 0) {
    local_218 = local_1c8;
    tw_string(local_128,200,"%s %s\n",&s_3ware);
    DbgPrintEx(0xd,0,local_128);
  }
  return;
}



===== tw_msg_dev @ 1c000f474 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_msg_dev(byte *param_1,uint param_2,char *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 local_res20;
  undefined1 auStackY_f8 [32];
  char local_c8 [160];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  if (param_1 == (byte *)0x0) {
    uVar1 = tw_msg_control;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x296);
  }
  if ((param_2 & uVar1) != 0) {
    local_res20 = param_4;
    vsprintf(local_c8,param_3,(va_list)&local_res20);
    FUN_1c000ed9c(param_1,0xff,0xff,0,param_2,local_c8);
  }
  return;
}



===== tw_msg_req @ 1c000f50c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_msg_req(longlong *param_1,uint param_2,char *param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_f8 [32];
  char local_c8 [160];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  if ((*(uint *)(*param_1 + 0x296) & param_2) != 0) {
    local_res20 = param_4;
    vsprintf(local_c8,param_3,(va_list)&local_res20);
    FUN_1c000ed9c((byte *)*param_1,(ushort)*(byte *)((longlong)param_1 + 0x19),
                  (ushort)*(byte *)((longlong)param_1 + 0x1a),0,param_2,local_c8);
  }
  return;
}



===== tw_msg_cmd @ 1c000f594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_msg_cmd(byte *param_1,ushort param_2,ushort param_3,ulonglong param_4,uint param_5,
               char *param_6,char param_7)

{
  uint uVar1;
  undefined1 auStackY_108 [32];
  char local_d8 [160];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  if (param_1 == (byte *)0x0) {
    uVar1 = tw_msg_control;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x296);
  }
  if ((param_5 & uVar1) != 0) {
    vsprintf(local_d8,param_6,&param_7);
    FUN_1c000ed9c(param_1,param_2,param_3,param_4 & 0xffffffff,param_5,local_d8);
  }
  return;
}



===== tw_string @ 1c000f638 =====

void tw_string(char *param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  vsprintf(param_1,param_3,(va_list)&local_res20);
  return;
}



===== tw_str_parse @ 1c000f65c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void tw_str_parse(char *param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar5;
  longlong lVar4;
  char *pcVar6;
  undefined1 auStack_1a8 [32];
  char *local_188;
  char local_178 [97];
  undefined1 local_117;
  char local_108 [112];
  char local_98 [112];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_178[0] = '\0';
  param_1[0x61] = '\0';
  pcVar6 = param_1;
  do {
    cVar1 = *pcVar6;
    pcVar6[(longlong)(local_98 + -(longlong)param_1)] = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar2 = lVar5 + 1;
    lVar5 = lVar4;
  } while (local_98[lVar2] != '\0');
  uVar3 = (int)lVar4 + 1;
  pcVar6 = param_1 + uVar3;
  if ((uVar3 < 0x61) && (*pcVar6 != '\0')) {
    lVar5 = -(longlong)pcVar6;
    do {
      cVar1 = *pcVar6;
      pcVar6[(longlong)(local_108 + lVar5)] = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
  }
  else {
    local_108[0] = '\0';
  }
  local_188 = local_98;
  tw_string(local_178,0x6c,"%s (%s)",local_108);
  lVar5 = -1;
  do {
    lVar4 = lVar5 + 1;
    lVar2 = lVar5 + 1;
    lVar5 = lVar4;
  } while (local_178[lVar2] != '\0');
  pcVar6 = local_178;
  if (0x62 < (int)lVar4 + 1U) {
    local_117 = 0;
  }
  do {
    cVar1 = *pcVar6;
    pcVar6[param_3 - (longlong)local_178] = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  return;
}



===== tw_time_msecs @ 1c000f768 =====

longlong tw_time_msecs(void)

{
  longlong lVar1;
  longlong local_res8;
  undefined1 local_res10 [24];
  
  StorPortQuerySystemTime(local_res10);
  ExSystemTimeToLocalTime(local_res10,&local_res8);
  if (DAT_1c00178f8 == 0) {
    DAT_1c00178f8 = local_res8;
    tw_bootup_time = tw_time_1970_secs();
    lVar1 = 0;
  }
  else {
    if (local_res8 < DAT_1c00178f8) {
      DAT_1c00178f8 = local_res8;
    }
    lVar1 = (local_res8 + (4999 - DAT_1c00178f8)) / 10000;
  }
  return lVar1;
}



===== tw_time_1970_secs @ 1c000f7ec =====

int tw_time_1970_secs(void)

{
  longlong local_res8;
  undefined1 local_res10 [24];
  
  StorPortQuerySystemTime(local_res10);
  ExSystemTimeToLocalTime(local_res10,&local_res8);
  local_res8 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(local_res8),8) + local_res8;
  return ((int)(local_res8 >> 0x17) - (int)(local_res8 >> 0x3f)) + 0x49ef6f00;
}



===== tw_time_date @ 1c000f838 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * tw_time_date(char *param_1)

{
  undefined1 auStack_88 [32];
  int local_68;
  int local_60;
  int local_58;
  int local_50;
  int local_48;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  StorPortQuerySystemTime(local_30);
  ExSystemTimeToLocalTime(local_30,local_38);
  RtlTimeToTimeFields(local_38,&local_28);
  local_48 = (int)local_1e;
  local_50 = (int)local_20;
  local_58 = (int)local_22;
  local_60 = (int)local_28;
  local_68 = (int)local_24;
  tw_string(param_1,0x32,"%d/%02d/%d %d:%02d:%02d",(ulonglong)(uint)(int)local_26);
  return param_1;
}



===== tw_time_date_from_1970secs @ 1c000f8e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * tw_time_date_from_1970secs(ulonglong param_1,char *param_2)

{
  undefined1 auStack_78 [32];
  int local_58;
  int local_50;
  int local_48;
  int local_40;
  int local_38;
  longlong local_28;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_28 = ((param_1 & 0xffffffff) + 0x2b6109100) * 10000000;
  RtlTimeToTimeFields(&local_28,&local_20);
  local_38 = (int)local_16;
  local_40 = (int)local_18;
  local_48 = (int)local_1a;
  local_50 = (int)local_20;
  local_58 = (int)local_1c;
  tw_string(param_2,0x32,"%d/%02d/%d %d:%02d:%02d",(ulonglong)(uint)(int)local_1e);
  return param_2;
}



===== tw_memory_resize @ 1c000f98c =====

longlong tw_memory_resize(byte *param_1,uint *param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = 0;
  uVar2 = *param_2;
  while ((param_3 <= uVar2 && (lVar1 = tw_memory_alloc(param_1,*param_2), lVar1 == 0))) {
    uVar2 = *param_2 - (*param_2 >> 2);
    *param_2 = uVar2;
  }
  return lVar1;
}



===== tw_memory_alloc @ 1c000f9dc =====

longlong tw_memory_alloc(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = 0xebab;
  uVar1 = StorPortExtendedFunction(0,param_1,param_2,0xebab,local_res18);
  if (uVar1 == 0) {
    if (local_res18[0] != 0) {
      tw_msg_dev(param_1,4,"MemAlloc> Memptr=%X Memlen=%d",local_res18[0]);
      return local_res18[0];
    }
  }
  else if (uVar1 == 0xc1000002) {
    tw_msg_dev(param_1,2,"AllocPool: Not implemented in this version of Windows",uVar2);
    param_1[1] = 1;
    return 0;
  }
  tw_msg_dev(param_1,2,"AllocPool: Status=%X Memptr=%X Memlen=%d",(ulonglong)uVar1);
  return 0;
}



===== tw_memory_free @ 1c000fa8c =====

uint tw_memory_free(byte *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = StorPortExtendedFunction(1,param_1,param_2);
  if (uVar1 == 0) {
    uVar2 = tw_msg_dev(param_1,4,"FreePool: Success (Memptr=%X)",param_2);
    uVar1 = CONCAT31((int3)((uint)uVar2 >> 8),1);
  }
  else {
    if (uVar1 == 0xc1000002) {
      uVar1 = tw_msg_dev(param_1,2,"FreePool: Not implemented in this version of Windows",param_4);
    }
    else {
      uVar1 = tw_msg_dev(param_1,2,"FreePool: Status=%X Memptr=%X",(ulonglong)uVar1);
    }
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}



===== __report_gsfailure @ 1c000fb10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 1c000fb18 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 1c000fb20 =====

void ScsiPortWmiPostProcess(longlong param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  cVar1 = *(char *)(param_1 + 0x18);
  uVar10 = 0;
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  uVar8 = 1;
  if (cVar1 == '\0') {
    uVar9 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar11 = (ulonglong)uVar3;
    if (uVar2 < uVar9) {
      uVar8 = 0x12;
      if (0x37 < uVar2) {
        *puVar4 = 0x38;
        puVar4[0xb] = 0x20;
        uVar8 = 1;
        uVar10 = 0x38;
      }
    }
    else if (((0x2f < uVar2) && (*puVar4 = uVar9, uVar10 = uVar9, (char)puVar4[0xb] < '\0')) &&
            (puVar7 = puVar4 + 0xf, uVar6 = uVar11, uVar3 != 0)) {
      do {
        uVar5 = (int)uVar6 - 1;
        uVar6 = (ulonglong)uVar5;
        if (uVar6 * 8 + 0x48 <= (ulonglong)uVar2) {
          puVar4[uVar6 * 2 + 0x10] = puVar7[uVar6];
        }
      } while (uVar5 != 0);
      if (uVar3 != 0) {
        uVar6 = 0x48;
        do {
          if (uVar6 <= uVar2) {
            *puVar7 = uVar9;
            uVar9 = uVar9 + 7 + puVar7[1] & 0xfffffff8;
          }
          uVar6 = uVar6 + 8;
          puVar7 = puVar7 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
    }
  }
  else if (cVar1 == '\x01') {
    if (0x2f < uVar2) {
      *puVar4 = puVar4[0xe];
      uVar10 = puVar4[0xe];
    }
  }
  else if ((cVar1 == '\t') && (0x47 < uVar2)) {
    puVar4[0x10] = 0;
    *puVar4 = puVar4[0xf];
    uVar10 = puVar4[0xf];
  }
  *(undefined1 *)(param_1 + 0x19) = uVar8;
  *(uint *)(param_1 + 0x1c) = uVar10;
  return;
}



===== ScsiWmipProcessRequest @ 1c000fc48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,longlong *param_5,
               uint param_6,uint *param_7,uint *param_8,undefined4 *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong *puVar9;
  undefined2 *puVar10;
  int iVar11;
  longlong lVar12;
  uint *puVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  short *local_38 [2];
  
  puVar13 = (uint *)0x0;
  uVar18 = 0;
  uVar15 = 0;
  *param_9 = 0;
  uVar5 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar8 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar8) && (param_5[1] == ((longlong *)*plVar8)[1])) {
          uVar15 = *(uint *)(*(longlong **)(param_1 + 2) + uVar18 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar5 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar5 < uVar15))))
          goto LAB_1c000fd1b;
          break;
        }
        uVar15 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar15;
        plVar8 = plVar8 + 2;
      } while (uVar15 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1c001008d;
  }
LAB_1c000fd1b:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1c000fd9b;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar5 = uVar15 * 8 + 0x40;
        param_7[0xd] = uVar15;
        param_7[0xc] = uVar5;
        if (param_6 < uVar5) {
          lVar12 = 0;
          iVar11 = 0;
        }
        else {
          puVar13 = param_7 + 0xf;
          lVar12 = (ulonglong)uVar5 + (longlong)param_7;
          iVar11 = param_6 - uVar5;
        }
        uVar5 = 0;
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            if (*(code **)(param_1 + 8) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 8))
                                (param_3,param_4,uVar18,uVar5,param_7[0xf],
                                 (ulonglong)param_7[0xe] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 3) {
            if (*(code **)(param_1 + 10) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 10))
                                (param_3,param_4,uVar18,uVar5,param_7[0xe],param_7[0x10],
                                 (ulonglong)param_7[0xf] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 4) {
            pcVar6 = *(code **)(param_1 + 0xe);
            if (pcVar6 != (code *)0x0) {
              uVar17 = 0;
              goto LAB_1c00100b0;
            }
            goto LAB_1c00100c5;
          }
LAB_1c000fd9b:
          cVar4 = '\x04';
          goto LAB_1c00100c8;
        }
        if (param_6 < 0x40) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
            return '\x12';
          }
          *param_7 = 0x40;
          return '\x12';
        }
        iVar11 = param_6 - param_7[0xe];
        lVar12 = (longlong)param_7 + (ulonglong)param_7[0xe];
        puVar13 = param_7 + 0xf;
        uVar15 = 1;
      }
      pcVar6 = *(code **)(param_1 + 6);
LAB_1c000fe7e:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar5,uVar15,puVar13,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 0;
      goto LAB_1c00100b5;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar17 = 1;
LAB_1c00100b0:
      uVar19 = 1;
LAB_1c00100b5:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar17,uVar19);
      return cVar4;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (pcVar6 = *(code **)(param_1 + 0xc), pcVar6 != (code *)0x0)) &&
           (0x47 < param_6)) {
          uVar15 = param_7[0xf];
          if (uVar15 <= param_6) {
            lVar12 = (longlong)param_7 + (ulonglong)uVar15;
            iVar11 = param_6 - uVar15;
            puVar13 = (uint *)(ulonglong)param_7[0x10];
            uVar15 = param_7[0xe];
            goto LAB_1c000fe7e;
          }
        }
        goto LAB_1c000fd9b;
      }
      cVar4 = (**(code **)(param_1 + 4))(param_3,param_4,local_38);
      if (cVar4 == '\x01') {
        uVar15 = *param_1;
        uVar18 = (ulonglong)uVar15;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar16 = uVar15 * 0x20 + 0x18;
        uVar5 = uVar15 * 0x20 + 0x34;
        if (local_38[0] == (short *)0x0) {
          uVar14 = 0;
        }
        else {
          uVar14 = 0;
          sVar2 = *local_38[0];
          while (sVar2 != 0) {
            uVar14 = uVar14 + 1;
            sVar2 = local_38[0][uVar14];
          }
          uVar14 = uVar14 * 2;
        }
        uVar7 = uVar14 + uVar5;
        if ((uVar7 < uVar5) || (uVar1 = uVar7 + 2, uVar1 < uVar7)) {
          cVar4 = '\x04';
          goto LAB_1c001007e;
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
          param_7[3] = uVar5;
          param_7[4] = uVar15;
          if (uVar15 != 0) {
            puVar13 = (uint *)(lVar12 + 0xc);
            puVar9 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(puVar13 + -3))[1];
              puVar9[-3] = **(ulonglong **)(puVar13 + -3);
              puVar9[-2] = uVar3;
              if (puVar13[-1] == 0xffffffff) {
                *(uint *)(puVar9 + -1) = *puVar13;
                *puVar9 = 0;
                *(undefined4 *)((longlong)puVar9 + -4) = 0;
              }
              else {
                *(uint *)(puVar9 + -1) = *puVar13 | 8;
                *puVar9 = (ulonglong)uVar16;
                *(uint *)((longlong)puVar9 + -4) = puVar13[-1];
              }
              puVar9 = puVar9 + 4;
              puVar13 = puVar13 + 4;
              uVar18 = uVar18 - 1;
            } while (uVar18 != 0);
          }
          puVar10 = (undefined2 *)((ulonglong)uVar16 + (longlong)param_7);
          *puVar10 = 0x1a;
          memcpy(puVar10 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar5 + (longlong)param_7) = uVar14;
          memcpy((ushort *)((ulonglong)uVar5 + (longlong)param_7) + 1,local_38[0],(ulonglong)uVar14)
          ;
          param_6 = uVar1;
        }
      }
      else {
LAB_1c001007e:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1c001008d:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 1;
      goto LAB_1c00100b5;
    }
  }
LAB_1c00100c5:
  cVar4 = '\x01';
LAB_1c00100c8:
  *param_9 = 1;
  return cVar4;
}



===== __security_check_cookie @ 1c0010100 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 1c0010120 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0010130 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0010150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== _guard_dispatch_icall @ 1c00101d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00101d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c0010200 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
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
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
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
        if (uVar12 == 0) goto LAB_1c00103b7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
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
LAB_1c00103b7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
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
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
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
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
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
      if (uVar12 == 0) goto LAB_1c0010212;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_1c0010212:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 1c0010540 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_1c0010600;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c00105fd_caseD_2;
      case 3:
        goto switchD_1c00105fd_caseD_3;
      case 4:
        goto switchD_1c00105fd_caseD_4;
      case 5:
        goto switchD_1c00105fd_caseD_5;
      case 6:
        goto switchD_1c00105fd_caseD_6;
      case 7:
        goto switchD_1c00105fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c0010600:
        *puVar3 = uVar4;
switchD_1c00105fd_caseD_7:
        puVar3[1] = uVar4;
switchD_1c00105fd_caseD_6:
        puVar3[2] = uVar4;
switchD_1c00105fd_caseD_5:
        puVar3[3] = uVar4;
switchD_1c00105fd_caseD_4:
        puVar3[4] = uVar4;
switchD_1c00105fd_caseD_3:
        puVar3[5] = uVar4;
switchD_1c00105fd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== entry @ 1c001a000 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c001a018 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  uint3 uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  char cVar12;
  byte *pbVar8;
  byte *pbVar9;
  uint *puVar10;
  int *piVar11;
  longlong lVar13;
  byte in_DL;
  byte in_DH;
  char unaff_BH;
  char *unaff_RSI;
  int *unaff_RDI;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  lVar13 = 6;
  pcVar1 = (code *)swi(0x29);
  pbVar8 = (byte *)(*pcVar1)();
  bVar3 = (byte)pbVar8;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3;
  bVar4 = *pbVar8;
  *pbVar8 = *pbVar8 + bVar3;
  *pbVar8 = *pbVar8 + bVar3 + CARRY1(bVar4,bVar3);
  bVar4 = *pbVar8;
  *pbVar8 = *pbVar8 + in_DL;
  *pbVar8 = *pbVar8 + bVar3 + CARRY1(bVar4,in_DL);
  pbVar9 = pbVar8 + -0x4ffffff0;
  bVar4 = *pbVar9;
  *pbVar9 = *pbVar9 + bVar3;
  pbVar9 = (byte *)CONCAT71((int7)((ulonglong)pbVar8 >> 8),bVar3 + *pbVar8 + CARRY1(bVar4,bVar3));
  bVar4 = *pbVar9;
  *pbVar9 = *pbVar9 + in_DH;
  uVar6 = (int)pbVar9 + 0x1e200000 + (uint)CARRY1(bVar4,in_DH);
  pbVar9 = (byte *)(ulonglong)uVar6;
  bVar4 = (byte)uVar6;
  *pbVar9 = *pbVar9 + bVar4;
  *pbVar9 = *pbVar9 & bVar4;
  cVar12 = (char)(uVar6 >> 8);
  uVar2 = (uint3)(uVar6 >> 8);
  cVar5 = bVar4 + cVar12;
  puVar10 = (uint *)(ulonglong)CONCAT31(uVar2,cVar5);
  *puVar10 = *puVar10 & CONCAT31(uVar2,cVar5);
  *(char *)((longlong)puVar10 + 0x7000002a) = *(char *)((longlong)puVar10 + 0x7000002a) + cVar5;
  *(char *)puVar10 = (char)*puVar10 + cVar5;
  pbVar9 = (byte *)CONCAT71((uint7)uVar2,0x2e);
  *pbVar9 = *pbVar9 + 0x2e;
  pbVar8 = (byte *)(lVar13 + -1);
  iVar7 = (int)pbVar9;
  if (pbVar8 == (byte *)0x0 || *pbVar9 == 0) {
    bVar4 = *pbVar9;
    *pbVar9 = *pbVar9 + 0x2e;
    *unaff_RSI = *unaff_RSI + '.' + (0xd1 < bVar4);
    pbVar9[0x46] = pbVar9[0x46] + 0x2e;
    bVar4 = *pbVar9;
    *pbVar9 = *pbVar9 + 0x2e;
    if (!SCARRY1(bVar4,'.')) {
      *pbVar9 = *pbVar9 + 0x2e;
      *unaff_RDI = iVar7;
      *pbVar9 = *pbVar9 + 0x2e;
      unaff_RSI[-0x3c100000] = unaff_RSI[-0x3c100000] + in_DH;
      *pbVar9 = *pbVar9 + 0x2e;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    *pbVar8 = *pbVar8 ^ 0x2e;
    *(int *)pbVar9 = *(int *)pbVar9 + iVar7;
    pbVar9[1] = pbVar9[1] + cVar12;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
    *pbVar9 = *pbVar9 + 0x2e;
  }
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *pbVar9 = *pbVar9 + 0x2e;
  *(int *)pbVar9 = *(int *)pbVar9 + iVar7;
  *(int *)pbVar9 = *(int *)pbVar9 + iVar7;
  cVar5 = cRam1080000020800000;
  uVar6 = CONCAT31(uVar2,cRam1080000020800000);
  piVar11 = (int *)(ulonglong)uVar6;
  *(char *)piVar11 = (char)*piVar11 + cRam1080000020800000;
  *(char *)piVar11 = (char)*piVar11 + unaff_BH;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  *piVar11 = *piVar11 + uVar6;
  *(char *)piVar11 = (char)*piVar11 + cVar5;
  piVar11 = (int *)((ulonglong)uVar2 * 0x100);
  *(char *)(piVar11 + -0x1fffffec) = (char)piVar11[-0x1fffffec];
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *piVar11 = *piVar11 + (int)piVar11;
  *piVar11 = *piVar11 + (int)piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *pbVar8 = *pbVar8;
  *pbVar8 = *pbVar8 + (char)pbVar8;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *(char *)piVar11 = (char)*piVar11;
  *pbVar8 = *pbVar8;
  *pbVar8 = *pbVar8 + (char)pbVar8;
  *(byte *)(piVar11 + -0xa000000) = (char)piVar11[-0xa000000] + in_DL;
  return;
}


