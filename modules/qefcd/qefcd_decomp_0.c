
===== evcd_adapter_control @ 140001000 =====

undefined8
evcd_adapter_control(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk(&s_ControlType____x_,param_2,param_3,param_4);
  }
  return 0;
}



===== evcd_bringup_adapter @ 140001028 =====

ulonglong evcd_bringup_adapter
                    (uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined7 extraout_var;
  
  uVar3 = mm_device_init(param_1,param_2,param_3,param_4);
  if ((int)uVar3 == 0) {
    uVar2 = mm_get_elapsed_ms((longlong)param_1);
    *(ulonglong *)(param_1 + 0x302) = *(longlong *)(param_1 + 0x302) + (ulonglong)uVar2;
    mm_get_mac_addr((longlong)param_1,(void *)((longlong)param_1 + 0x15b2));
    bVar1 = mm_get_link_status((longlong)param_1);
    uVar3 = CONCAT71(extraout_var,bVar1);
    if ((int)uVar3 != 1) {
      if ((~FCoEDebugFlags & 1) == 0) {
        mm_printk(&s__s____Dev__p__polling_for_link_,"evcd_bringup_adapter",param_1,param_4);
      }
      uVar3 = mm_poll_link_status((longlong)param_1,0x1e);
      if ((int)uVar3 != 1) {
        if ((~FCoEDebugFlags & 1) == 0) {
          mm_printk("%s(): Dev %p link is NOT active. Shutting down adapter.\n",
                    "evcd_bringup_adapter",param_1,param_4);
        }
        uVar4 = mm_device_shutdown((longlong)param_1);
        goto LAB_140001055;
      }
    }
    if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
      uVar3 = mm_printk("%s(): Dev %p link is up.\n","evcd_bringup_adapter",param_1,param_4);
    }
    uVar4 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  else {
    uVar4 = (ulonglong)~FCoEDebugFlags;
    if ((~FCoEDebugFlags & 1) == 0) {
      uVar4 = mm_printk("Dev %p init failed\n",param_1,param_3,param_4);
    }
LAB_140001055:
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== evcd_build_io @ 140001120 =====

undefined1 evcd_build_io(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk(&s_SRB_function____x_,(ulonglong)*(byte *)(param_2 + 2),param_3,param_4);
  }
  return 1;
}



===== evcd_extract_boot_info @ 14000114c =====

void evcd_extract_boot_info(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined8 *)(param_1 + 0xaf4) = *(undefined8 *)(param_2 + 4);
  *(undefined8 *)(param_1 + 0xafc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined1 *)(param_1 + 0x15af) = 1;
  *(undefined2 *)(param_1 + 0x15b0) = *(undefined2 *)(param_2 + 0x14);
  mm_memcpy((void *)(param_1 + 0x15b2),(void *)(param_2 + 0x16),6);
  mm_memcpy((void *)(param_1 + 0x15b8),(void *)(param_2 + 0x1c),8);
  mm_memcpy((void *)(param_1 + 0x15c0),(void *)(param_2 + 0x24),8);
  mm_memcpy((void *)(param_1 + 0x15c8),(void *)(param_2 + 0x30),0x100);
  *(byte *)(param_1 + 0x16c8) = *(byte *)(param_1 + 0x16c8) | 3;
  mm_memcpy((void *)(param_1 + 0x16d4),(void *)(param_2 + 0x130),8);
  mm_memcpy((void *)(param_1 + 0x16cc),(void *)(param_2 + 0x138),8);
  *(undefined1 *)(param_1 + 0x15ae) = 1;
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("BAR0=%p, BAR1=%p \n",*(undefined8 *)(param_1 + 0xaf4),
              *(undefined8 *)(param_1 + 0xafc),param_4);
  }
  return;
}



===== evcd_find_adapter @ 140001260 =====

undefined8
evcd_find_adapter(undefined4 *param_1,undefined4 *param_2,ulonglong param_3,undefined8 param_4,
                 undefined4 *param_5)

{
  short *psVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 **ppuVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 **ppuVar10;
  
  puVar8 = param_5;
  iVar9 = 0;
  param_5._0_4_ = 0;
  psVar1 = *(short **)(puVar8 + 0x10);
  if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
    param_2 = param_1;
    mm_printk("Find Adapter Invoked. Adapter = %p\n",param_1,param_3,param_4);
  }
  if (psVar1 == (short *)0x0) {
    if ((~FCoEDebugFlags & 1) != 0) {
      return 2;
    }
    pcVar7 = "Invalid miniport mappings pointer. Exiting\n.";
    puVar8 = param_2;
  }
  else if (*psVar1 == 2) {
    *puVar8 = 0xe0;
    *(undefined8 *)(puVar8 + 0x21) = 0x16f0;
    puVar8[6] = 0x10000;
    puVar8[7] = 0x11;
    puVar8[0xc] = 0;
    *(undefined1 *)(puVar8 + 0x12) = 1;
    *(undefined2 *)((longlong)puVar8 + 0x51) = 0x101;
    *(undefined1 *)((longlong)puVar8 + 0x53) = 0;
    *(undefined1 *)((longlong)puVar8 + 0x59) = 3;
    *(undefined2 *)((longlong)puVar8 + 0x61) = 1;
    puVar8[0x23] = 0;
    *(undefined1 *)(puVar8 + 0x24) = 1;
    *(undefined1 *)((longlong)puVar8 + 0x92) = 0xff;
    puVar8[0x25] = 1;
    *(undefined8 *)(puVar8 + 0x26) = 0;
    puVar8[0x28] = 0;
    mm_memset(param_1,0x16f0,0);
    uVar2 = mm_get_dma_buf_len();
    param_3 = uVar2 & 0xffffffff;
    lVar3 = StorPortGetUncachedExtension(param_1);
    *(longlong *)(param_1 + 0x2b6) = lVar3;
    if (lVar3 != 0) {
      ppuVar10 = &param_5;
      ppuVar4 = (undefined4 **)StorPortGetPhysicalAddress(param_1);
      uVar5 = mm_get_dma_buf_len();
      if ((uint)uVar5 <= (uint)param_5) {
        uVar6 = mm_get_dma_buf_len();
        uVar6 = uVar6 & 0xffffffff;
        memset(*(void **)(param_1 + 0x2b6),0,uVar6);
        uVar5 = mm_get_dma_buf_len();
        param_1[0x2ba] = (int)uVar5;
        uVar2 = *(ulonglong *)(param_1 + 0x2b6);
        if ((uVar2 & 3) != 0) {
          iVar9 = (~(uint)uVar2 & 3) + 1;
        }
        param_1[699] = iVar9;
        if ((uVar2 & 0xfff) == 0) {
          uVar5 = mm_get_dma_buf_len();
          iVar9 = (int)uVar5;
        }
        else {
          uVar5 = mm_get_dma_buf_len();
          iVar9 = (int)uVar5 + -0xfff + (~(uint)uVar2 & 0xfff);
        }
        param_1[700] = iVar9;
        *(undefined4 ***)(param_1 + 0x2b8) = ppuVar4;
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          uVar6 = *(ulonglong *)(param_1 + 0x2b6);
          mm_printk("Non-Cache Extension: total mem_len %d virt_addr 0x%p phy_addr %p mem_align_offset %d MAX_RX_DESC_CNT %d MAX_TX_DESC_CNT %d\n"
                    ,(ulonglong)(uint)param_1[0x2ba],uVar6,ppuVar4);
          ppuVar10 = ppuVar4;
        }
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("Non-Cache Extension: mem_page_align_bottom_up_offset %d\n",
                    (ulonglong)(uint)param_1[700],uVar6,ppuVar10);
        }
        evcd_extract_boot_info((longlong)param_1,(longlong)psVar1,uVar6,ppuVar10);
        return 1;
      }
      if ((~FCoEDebugFlags & 1) == 0) {
        mm_printk("Contiguous mem_len %d too small\n",(ulonglong)(uint)param_1[0x2ba],lVar3,ppuVar10
                 );
        return 2;
      }
      return 2;
    }
    if ((~FCoEDebugFlags & 1) != 0) {
      return 2;
    }
    pcVar7 = "StorPortGetUncachedExtension() API failed\n";
  }
  else {
    if ((~FCoEDebugFlags & 1) != 0) {
      return 2;
    }
    pcVar7 = "Incorrect version of miniport mappings. Exiting\n";
    puVar8 = param_2;
  }
  mm_printk(pcVar7,puVar8,param_3,param_4);
  return 2;
}



===== evcd_initialize_adapter @ 1400014e0 =====

ulonglong evcd_initialize_adapter(uint *param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  uint *puVar2;
  code *pcVar3;
  
  uVar1 = (ulonglong)~(FCoEDebugFlags >> 2);
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    param_2 = param_1;
    uVar1 = mm_printk("Initialize Adapter = %p\n",param_1,param_3,param_4);
  }
  if (*(char *)((longlong)param_1 + 0x15af) == '\x01') {
    if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
      param_2 = (uint *)(ulonglong)(ushort)param_1[0x56c];
      mm_printk(&s_Bringing_up_i_f_at_pfn__x_,param_2,param_3,param_4);
    }
    uVar1 = evcd_bringup_adapter(param_1,param_2,param_3,param_4);
    if ((char)uVar1 == '\x01') {
      uVar1 = 1000000;
      pcVar3 = evcd_timer;
      puVar2 = param_1;
      StorPortNotification(6);
      uVar1 = evcd_login_dump_disk((longlong)param_1,puVar2,pcVar3,uVar1);
      if ((char)uVar1 == '\x01') {
        return uVar1;
      }
      uVar1 = mm_device_shutdown((longlong)param_1);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



===== evcd_isr @ 140001580 =====

ulonglong evcd_isr(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)~(FCoEDebugFlags >> 2);
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    uVar1 = mm_printk(&s__s____,"evcd_isr",param_3,param_4);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== evcd_login_dump_disk @ 1400015b0 =====

ulonglong evcd_login_dump_disk
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  char *pcVar3;
  byte *pbVar4;
  ulonglong uVar5;
  byte local_res8 [8];
  
  local_res8[0] = 0;
  local_res8[1] = 0;
  local_res8[2] = 0;
  evcd_init_session_params(param_1);
  uVar5 = 0;
  pbVar4 = local_res8;
  uVar1 = mm_get_bus_num();
  if ((int)uVar1 == 0) {
    *(longlong *)(param_1 + 0xd75) = param_1 + 0x15c8;
    mm_memcpy((void *)(param_1 + 0xc27),(void *)(param_1 + 0x15b8),8);
    uVar5 = 8;
    mm_memcpy((void *)(param_1 + 0xc2f),(void *)(param_1 + 0x15c0),8);
    *(undefined2 *)(param_1 + 0xdac) = 0x412;
    mm_device_bringup(param_1);
    pbVar4 = (byte *)(param_1 + 0xc21);
    mm_add_unicast_addr(param_1,pbVar4);
    if (((*(uint *)(param_1 + 0x278) & 4) == 0) || (*(int *)(param_1 + 0x27c) != 1)) {
      if (((*(uint *)(param_1 + 0x278) & 8) != 0) &&
         ((*(int *)(param_1 + 0x27c) == 1 && ((~(FCoEDebugFlags >> 5) & 1) == 0)))) {
        mm_printk("****BD mode****\n",pbVar4,uVar5,param_4);
      }
    }
    else {
      *(ushort *)(param_1 + 0xc39) = *(ushort *)(param_1 + 0x14a);
      if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
        pbVar4 = (byte *)(ulonglong)*(ushort *)(param_1 + 0x14a);
        mm_printk("****UFP mode, VLAN ID: %d****\n",pbVar4,uVar5,param_4);
      }
    }
    if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
      mm_printk("Discovering fabric...",pbVar4,uVar5,param_4);
    }
    uVar1 = evcd_process_fip_disc_login(param_1,pbVar4,uVar5,param_4);
    if ((char)uVar1 == '\x01') {
      if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
        mm_printk("successful\n",pbVar4,uVar5,param_4);
      }
      mm_add_mcast_addr(param_1,&s_____,uVar5,param_4);
      pbVar4 = (byte *)(param_1 + 0xc1b);
      mm_add_unicast_addr(param_1,pbVar4);
      _guard_check_icall();
      if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
        mm_printk("Logging into Name Server...\n",pbVar4,uVar5,param_4);
      }
      uVar1 = evcd_login_name_server(param_1,pbVar4,uVar5,param_4);
      if ((char)uVar1 == '\x01') {
        if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
          mm_printk("Name Server login successful, num targets = %d\n",
                    (ulonglong)*(byte *)(param_1 + 0x15ae),uVar5,param_4);
        }
        if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
          uVar5 = (ulonglong)*(byte *)(param_1 + 0x15ae);
          mm_printk("Logging into target, %d of %d...\n",0,uVar5,param_4);
        }
        pbVar4 = (byte *)(param_1 + 0x16c8);
        uVar1 = evcd_login_target(param_1,(longlong)pbVar4,uVar5,param_4);
        if ((char)uVar1 == '\x01') {
          *pbVar4 = *pbVar4 | 4;
          if ((~(byte)(FCoEDebugFlags >> 5) & 1) == 0) {
            uVar1 = mm_printk("Target-%d %02x:%02x:%02x login successful\n",0,
                              (ulonglong)*(byte *)(param_1 + 0x16c9),
                              (ulonglong)*(byte *)(param_1 + 0x16ca));
          }
          return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
        }
        uVar2 = (ulonglong)~FCoEDebugFlags;
        if ((~FCoEDebugFlags & 1) == 0) {
          uVar2 = mm_printk("Target-%d %02x:%02x:%02x login failed\n",0,
                            (ulonglong)*(byte *)(param_1 + 0x16c9),
                            (ulonglong)*(byte *)(param_1 + 0x16ca));
        }
        goto LAB_140001846;
      }
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_140001846;
      pcVar3 = "Name Server login failed\n";
    }
    else {
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_140001846;
      pcVar3 = "failed\n";
    }
  }
  else {
    uVar2 = (ulonglong)~FCoEDebugFlags;
    if ((~FCoEDebugFlags & 1) != 0) goto LAB_140001846;
    pcVar3 = "DCBX initialization failed\n";
  }
  uVar2 = mm_printk(pcVar3,pbVar4,uVar5,param_4);
LAB_140001846:
  return uVar2 & 0xffffffffffffff00;
}



===== evcd_reset_bus @ 140001860 =====

undefined1
evcd_reset_bus(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk(&s__s____,"evcd_reset_bus",param_3,param_4);
  }
  return 1;
}



===== evcd_start_io @ 140001890 =====

undefined8 evcd_start_io(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  uint uVar5;
  
  uVar4 = 6;
  if (*(byte *)(param_2 + 2) == 0) {
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk(&s_CDB_opcode____x_,(ulonglong)*(byte *)(param_2 + 0x48),param_3,param_4);
    }
    uVar1 = evcd_send_scsi_cdb(param_1,param_2,param_3,param_4);
    uVar5 = 4;
    if ((char)uVar1 == '\x01') {
      uVar5 = 1;
    }
    uVar4 = (undefined1)uVar5;
    if ((~(FCoEDebugFlags >> 2) & 1) != 0) goto LAB_140001927;
    uVar3 = (ulonglong)uVar5;
    pcVar2 = "SRB status = %x\n";
  }
  else {
    if ((~(FCoEDebugFlags >> 2) & 1) != 0) goto LAB_140001927;
    uVar3 = (ulonglong)*(byte *)(param_2 + 2);
    pcVar2 = "SRB function = %x\n";
    uVar4 = 6;
  }
  mm_printk(pcVar2,uVar3,param_3,param_4);
LAB_140001927:
  *(undefined1 *)(param_2 + 3) = uVar4;
  uVar1 = StorPortNotification(0,param_1,param_2);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== evcd_timer @ 140001950 =====

void evcd_timer(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  
  uVar1 = mm_get_elapsed_ms(param_1);
  *(longlong *)(param_1 + 0xc08) = *(longlong *)(param_1 + 0xc08) + (ulonglong)uVar1;
  if ((*(byte *)(param_1 + 0xc10) & 0x20) == 0) {
    evcd_send_fka(param_1);
    StorPortNotification(6,param_1,evcd_timer,1000000);
    return;
  }
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("Restart session flagged. Triggering restart.\n",param_2,param_3,param_4);
  }
  evcd_restart_session(param_1,param_2,param_3,param_4);
  return;
}



===== mm_add_mcast_addr @ 1400019c0 =====

uint mm_add_mcast_addr(longlong param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = lm_add_multicast_addr(param_1,param_2);
  if ((uVar1 != 0) && ((~(FCoEDebugFlags >> 1) & 1) == 0)) {
    mm_printk("Failed to add multicast address. Status: %d\n",(ulonglong)uVar1,param_3,param_4);
  }
  return uVar1;
}



===== mm_add_unicast_addr @ 1400019f8 =====

int mm_add_unicast_addr(longlong param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = lm_add_unicast_addr(param_1,param_2);
  if (iVar1 == 0) {
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("Unicast address addition %0x:%0x:%0x:%0x:%0x:%0x successful.\n",(ulonglong)*param_2
                ,(ulonglong)param_2[1],(ulonglong)param_2[2]);
    }
  }
  else if ((~(FCoEDebugFlags >> 1) & 1) == 0) {
    mm_printk("Unicast address addition %0x:%0x:%0x:%0x:%0x:%0x failed. Status: %d\n",
              (ulonglong)*param_2,(ulonglong)param_2[1],(ulonglong)param_2[2]);
  }
  return iVar1;
}



===== mm_alloc_pool @ 140001aa8 =====

longlong mm_alloc_pool(longlong param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong local_res8;
  
  local_res8 = 0;
  uVar4 = (ulonglong)param_2;
  uVar5 = 0x44434651;
  iVar2 = StorPortExtendedFunction(0,param_1,uVar4,0x44434651,&local_res8);
  if (iVar2 != 0) {
    uVar1 = *(uint *)(param_1 + 0xc04);
    uVar3 = (param_2 + 3 & 0xfffffffc) + uVar1;
    if (uVar3 < 0x101) {
      *(uint *)(param_1 + 0xc04) = uVar3;
      local_res8 = param_1 + 0xb04 + (ulonglong)uVar1;
    }
    else {
      if ((~FCoEDebugFlags & 1) == 0) {
        mm_printk("%s():Unable to allocated pool memory for %x bytes.\n",(ulonglong)param_2,uVar4,
                  uVar5);
      }
      local_res8 = 0;
    }
  }
  return local_res8;
}



===== mm_cfg_vlan_mode @ 140001b38 =====

void mm_cfg_vlan_mode(longlong param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x12e) = (ushort)*(byte *)(param_1 + 0xd51) << 0xd | param_2;
  return;
}



===== mm_get_bus_num @ 140001b50 =====

undefined8 mm_get_bus_num(void)

{
  return 0;
}



===== mm_delay @ 140001b54 =====

ulonglong mm_delay(uint param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (param_1 < 1000) {
    uVar1 = StorPortStallExecution();
    return uVar1;
  }
  uVar2 = (ulonglong)param_1 * 0x10624dd3 & 0xffffffff;
  uVar1 = (ulonglong)param_1 / 1000;
  if ((int)uVar1 != 0) {
    do {
      uVar2 = StorPortStallExecution(0x3de);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return uVar2;
}



===== mm_device_bringup @ 140001b98 =====

undefined8 mm_device_bringup(longlong param_1)

{
  lm_enable_intr(param_1);
  return 0;
}



===== mm_device_init @ 140001ba8 =====

undefined8 mm_device_init(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  uVar5 = 0xad8;
  memset(param_1,0,0xad8);
  uVar2 = lm_get_dev_id((longlong)param_1);
  uVar1 = (uint)uVar2;
  if (uVar1 == 0) {
    uVar3 = lm_get_dev_info(param_1);
    uVar1 = (uint)uVar3;
    if (uVar1 == 0) {
      uVar1 = lm_init_resc((longlong)param_1);
      if (uVar1 == 0) {
        uVar3 = lm_chip_init((longlong)param_1);
        uVar1 = (uint)uVar3;
        if (uVar1 == 0) {
          uVar1 = lm_mcp_cfg_link((longlong)param_1,1);
          if (uVar1 == 0) {
            uVar1 = lm_mcp_ov_update_drv_state((longlong)param_1,2);
            if ((uVar1 != 0) && ((~FCoEDebugFlags & 1) == 0)) {
              mm_printk("Failed to set driver state to Active. Status=%x\n",(ulonglong)uVar1,uVar5,
                        param_4);
            }
            mm_init_hw_timer8((longlong)param_1);
            lm_set_rx_mask((longlong)param_1,8);
            return 0;
          }
          if ((~FCoEDebugFlags & 1) != 0) {
            return 1;
          }
          pcVar4 = "lm_mcp_cfg_link() failed. Status=%x\n";
        }
        else {
          if ((~FCoEDebugFlags & 1) != 0) {
            return 1;
          }
          pcVar4 = "lm_chip_init() failed. Status=%x\n";
        }
      }
      else {
        if ((~FCoEDebugFlags & 1) != 0) {
          return 1;
        }
        pcVar4 = "lm_init_resc() failed. Status=%x\n";
      }
    }
    else {
      if ((~FCoEDebugFlags & 1) != 0) {
        return 1;
      }
      pcVar4 = "lm_get_dev_info() failed. Status=%x\n";
    }
  }
  else {
    if ((~FCoEDebugFlags & 1) != 0) {
      return 1;
    }
    pcVar4 = "lm_get_dev_id() failed. Status=%x\n";
  }
  mm_printk(pcVar4,(ulonglong)uVar1,uVar5,param_4);
  return 1;
}



===== mm_device_poll @ 140001cc8 =====

int mm_device_poll(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  ulonglong uVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  uVar8 = 0;
  iVar9 = 0;
  lm_ack_enable_intr(param_1,1,0);
  iVar3 = lm_service_intr(param_1);
  do {
    iVar5 = *(int *)(param_1 + 0xa70);
    if (iVar5 == *(int *)(param_1 + 0xa74)) {
      iVar4 = iVar5;
      if (iVar5 == 0) {
        iVar4 = *(int *)(param_1 + 0xa78);
      }
      if (*(longlong *)(param_1 + 0xa80 + (ulonglong)(iVar4 - 1) * 8) == 0) {
        do {
          iVar5 = *(int *)(param_1 + 0x908);
          if (iVar5 == *(int *)(param_1 + 0x90c)) {
            iVar4 = iVar5;
            if (iVar5 == 0) {
              iVar4 = *(int *)(param_1 + 0x910);
            }
            if (*(longlong *)(param_1 + 0x918 + (ulonglong)(iVar4 - 1) * 8) == 0) {
              if (iVar9 != 0) {
                lm_post_buffers(param_1);
              }
              lm_ack_enable_intr(param_1,0,iVar3 != 0);
              return iVar10;
            }
          }
          if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
            mm_printk(&s__s____Rx_chain_processed__frame,"mm_device_poll",uVar8,param_4);
            iVar5 = *(int *)(param_1 + 0x908);
          }
          if (iVar5 == 0) {
            iVar5 = *(int *)(param_1 + 0x910);
          }
          *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + -1;
          uVar6 = iVar5 - 1;
          *(uint *)(param_1 + 0x908) = uVar6;
          lVar2 = *(longlong *)(param_1 + 0x918 + (ulonglong)uVar6 * 8);
          *(undefined8 *)(param_1 + 0x918 + (ulonglong)uVar6 * 8) = 0;
          pbVar7 = (byte *)((ulonglong)*(byte *)(lVar2 + 0x10) + *(longlong *)(lVar2 + 0x18));
          mm_strip_vlan((longlong)pbVar7,(short *)(lVar2 + 0xe),uVar8,param_4);
          uVar8 = (ulonglong)*(ushort *)(lVar2 + 0xe);
          evcd_rx_pkt(param_1,pbVar7,uVar8,param_4);
          iVar5 = *(int *)(param_1 + 0x8ac);
          if (iVar5 == 0) {
            iVar5 = *(int *)(param_1 + 0x8b0);
          }
          *(longlong *)(param_1 + 0x8b8 + (ulonglong)(iVar5 - 1U) * 8) = lVar2;
          *(int *)(param_1 + 0x8b4) = *(int *)(param_1 + 0x8b4) + 1;
          iVar9 = iVar9 + 1;
          *(uint *)(param_1 + 0x8ac) = iVar5 - 1U;
        } while( true );
      }
    }
    if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
      mm_printk("%s(): Tx_chain processed\n","mm_device_poll",uVar8,param_4);
      iVar5 = *(int *)(param_1 + 0xa70);
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0xa78);
    }
    *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + -1;
    uVar6 = iVar5 - 1;
    *(uint *)(param_1 + 0xa70) = uVar6;
    uVar1 = *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar6 * 8);
    *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar6 * 8) = 0;
    iVar5 = *(int *)(param_1 + 0xa14);
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0xa18);
    }
    *(undefined8 *)(param_1 + 0xa20 + (ulonglong)(iVar5 - 1U) * 8) = uVar1;
    *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + 1;
    iVar10 = iVar10 + 1;
    *(uint *)(param_1 + 0xa14) = iVar5 - 1U;
  } while( true );
}



===== mm_device_shutdown @ 140001ec0 =====

void mm_device_shutdown(longlong param_1)

{
  lm_disable_intr(param_1);
  lm_shutdown(param_1);
  return;
}



===== mm_dma_alloc @ 140001edc =====

undefined8 mm_dma_alloc(longlong param_1,longlong *param_2,longlong *param_3,ulonglong param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  
  iVar4 = (int)param_4;
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("\n%s(): **** size requested %d\n","mm_dma_alloc",param_4 & 0xffffffff,param_4);
  }
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("%s(): current mem_align_offset %d\n","mm_dma_alloc",
              (ulonglong)*(uint *)(param_1 + 0xaec),param_4);
  }
  uVar1 = *(uint *)(param_1 + 0xaec);
  uVar5 = (ulonglong)uVar1;
  uVar3 = iVar4 + 3U & 0xfffffffc;
  if (*(uint *)(param_1 + 0xaf0) < uVar1 + uVar3) {
    if ((~FCoEDebugFlags & 1) == 0) {
      mm_printk("%s(): failed to allocate, remaining mem %d\n","mm_dma_alloc",
                (ulonglong)(*(uint *)(param_1 + 0xaf0) - uVar1),uVar5);
    }
    uVar2 = 1;
  }
  else {
    *param_2 = uVar5 + *(longlong *)(param_1 + 0xad8);
    *param_3 = (ulonglong)*(uint *)(param_1 + 0xaec) + *(longlong *)(param_1 + 0xae0);
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("%s(): virtual addr returned 0x%x\n","mm_dma_alloc",*param_2,uVar5);
    }
    uVar3 = *(int *)(param_1 + 0xaec) + uVar3;
    *(uint *)(param_1 + 0xaec) = uVar3;
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("%s(): next mem_align_offset %d remaining mem %d\n","mm_dma_alloc",(ulonglong)uVar3,
                (ulonglong)(*(int *)(param_1 + 0xaf0) - uVar3));
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== mm_gen_crc32 @ 140002028 =====

uint mm_gen_crc32(uint *param_1,uint param_2)

{
  ulonglong uVar1;
  
  uVar1 = FC_Crc32(0xffffffff,param_1,param_2);
  return ~(uint)uVar1;
}



===== mm_get_dma_buf_len @ 140002044 =====

undefined8 mm_get_dma_buf_len(void)

{
  return 0x8000;
}



===== mm_get_drv_type @ 14000204c =====

undefined8 mm_get_drv_type(void)

{
  return 3;
}



===== mm_get_drv_version_dword @ 140002054 =====

undefined8 mm_get_drv_version_dword(void)

{
  return 0x82a0264;
}



===== mm_get_elapsed_ms @ 14000205c =====

int mm_get_elapsed_ms(longlong param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_14002000c;
  DAT_14002000c = mm_get_ticks(param_1);
  if (uVar1 < DAT_14002000c) {
    iVar2 = (uVar1 - DAT_14002000c) + -1;
  }
  else {
    iVar2 = uVar1 - DAT_14002000c;
  }
  return iVar2;
}



===== mm_get_free_pkt_desc @ 140002088 =====

longlong mm_get_free_pkt_desc
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  iVar4 = *(int *)(param_1 + 0xa10);
  lVar5 = 0;
  if (iVar4 == *(int *)(param_1 + 0xa14)) {
    iVar1 = iVar4;
    if (iVar4 == 0) {
      iVar1 = *(int *)(param_1 + 0xa18);
    }
    if (*(longlong *)(param_1 + 0xa20 + (ulonglong)(iVar1 - 1) * 8) == 0) {
      if ((~(FCoEDebugFlags >> 6) & 1) == 0) {
        mm_printk("%s(): Could not get free packet, trying to dequeue completion list\n",
                  "mm_get_free_pkt_desc",param_3,param_4);
      }
      iVar4 = 0;
      do {
        lm_ack_enable_intr(param_1,1,0);
        iVar1 = lm_service_intr(param_1);
        lm_ack_enable_intr(param_1,0,iVar1 != 0);
        iVar1 = *(int *)(param_1 + 0xa70);
        if (iVar1 == *(int *)(param_1 + 0xa74)) {
          iVar2 = iVar1;
          if (iVar1 == 0) {
            iVar2 = *(int *)(param_1 + 0xa78);
          }
          if (*(longlong *)(param_1 + 0xa80 + (ulonglong)(iVar2 - 1) * 8) != 0) goto LAB_14000213c;
        }
        else {
LAB_14000213c:
          if (iVar1 == 0) {
            iVar1 = *(int *)(param_1 + 0xa78);
          }
          uVar3 = iVar1 - 1;
          *(uint *)(param_1 + 0xa70) = uVar3;
          *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + -1;
          lVar5 = *(longlong *)(param_1 + 0xa80 + (ulonglong)uVar3 * 8);
          *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar3 * 8) = 0;
          if ((~(FCoEDebugFlags >> 6) & 1) == 0) {
            mm_printk("%s(): Pkt popped from completion list %p.\n","mm_get_free_pkt_desc",lVar5,
                      param_4);
          }
          if (lVar5 != 0) {
            return lVar5;
          }
        }
        iVar4 = iVar4 + 1;
        if (9999 < iVar4) {
          return lVar5;
        }
      } while( true );
    }
  }
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0xa18);
  }
  uVar3 = iVar4 - 1;
  *(uint *)(param_1 + 0xa10) = uVar3;
  *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + -1;
  lVar5 = *(longlong *)(param_1 + 0xa20 + (ulonglong)uVar3 * 8);
  *(undefined8 *)(param_1 + 0xa20 + (ulonglong)uVar3 * 8) = 0;
  if ((~(FCoEDebugFlags >> 6) & 1) == 0) {
    mm_printk("%s(): Pkt=%p, Free list Head=%d, Tail=%d\n","mm_get_free_pkt_desc",lVar5,
              (ulonglong)*(uint *)(param_1 + 0xa10));
  }
  return lVar5;
}



===== mm_get_link_status @ 140002214 =====

bool mm_get_link_status(longlong param_1)

{
  return *(char *)(param_1 + 0x280) != '\0';
}



===== mm_get_mac_addr @ 140002220 =====

void mm_get_mac_addr(longlong param_1,void *param_2)

{
  memmove(param_2,(void *)(param_1 + 0xb4),6);
  return;
}



===== mm_get_ticks @ 140002238 =====

undefined4 mm_get_ticks(longlong param_1)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = 0;
  lm_reg_read(param_1,0x8d1c,local_res10);
  return local_res10[0];
}



===== mm_init_hw_timer8 @ 14000225c =====

void mm_init_hw_timer8(longlong param_1)

{
  lm_reg_write(param_1,0x8c60,0xffffffff);
  lm_reg_write(param_1,0x8d1c,0);
  lm_reg_write(param_1,0x8c40,0x23);
  return;
}



===== mm_memcmp @ 14000229c =====

int mm_memcmp(char *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  if (param_3 != 0) {
    lVar1 = param_2 - (longlong)param_1;
    do {
      param_3 = param_3 + -1;
      if (*param_1 != param_1[lVar1]) {
        return (int)*param_1 - (int)param_1[lVar1];
      }
      param_1 = param_1 + 1;
    } while (param_3 != 0);
  }
  return 0;
}



===== mm_memcpy @ 1400022c4 =====

void * __cdecl mm_memcpy(void *_Dst,void *_Src,size_t _Size)

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
        if (uVar12 == 0) goto LAB_14000a537;
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
LAB_14000a537:
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
      if (uVar12 == 0) goto LAB_14000a392;
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
LAB_14000a392:
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



===== mm_memset @ 1400022cc =====

void mm_memset(void *param_1,uint param_2,undefined1 param_3)

{
  if ((short)param_2 != 0) {
    memset(param_1,CONCAT31((int3)(param_2 >> 8),param_3),(ulonglong)(param_2 & 0xffff));
  }
  return;
}



===== mm_page_alloc @ 1400022e8 =====

undefined8
mm_page_alloc(longlong param_1,longlong *param_2,longlong *param_3,ulonglong param_4,
             undefined8 *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (int)param_4;
  *param_5 = 0;
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("\n%s(): numOfPages requested %d\n","mm_page_alloc",param_4 & 0xffffffff,param_4);
  }
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("%s(): current mem_page_align_bottom_up_offset %d\n","mm_page_alloc",
              (ulonglong)*(uint *)(param_1 + 0xaf0),param_4);
  }
  uVar3 = *(uint *)(param_1 + 0xaf0);
  uVar1 = *(uint *)(param_1 + 0xaec);
  if (uVar3 + iVar4 * -0x1000 < uVar1) {
    if ((~FCoEDebugFlags & 1) == 0) {
      mm_printk("%s(): failed to allocate, remaining mem %d\n","mm_page_alloc",
                (ulonglong)(uVar3 - uVar1),(ulonglong)uVar1);
    }
    uVar2 = 1;
  }
  else {
    *param_2 = (*(longlong *)(param_1 + 0xad8) + (ulonglong)uVar3) -
               (ulonglong)(uint)(iVar4 * 0x1000);
    *param_3 = (*(longlong *)(param_1 + 0xae0) + (ulonglong)*(uint *)(param_1 + 0xaf0)) -
               (ulonglong)(uint)(iVar4 * 0x1000);
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("%s(): virtual addr returned 0x%x\n","mm_page_alloc",*param_2,(ulonglong)uVar1);
    }
    uVar3 = *(int *)(param_1 + 0xaf0) + iVar4 * -0x1000;
    *(uint *)(param_1 + 0xaf0) = uVar3;
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("%s(): next mem_page_align_bottom_up_offset %d remaining mem %d\n","mm_page_alloc",
                (ulonglong)uVar3,(ulonglong)(uVar3 - *(int *)(param_1 + 0xaec)));
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== mm_pci_cfg_read @ 140002448 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 mm_pci_cfg_read(longlong param_1,uint param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  undefined1 auStack_148 [32];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_118 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  memset(local_118,0,0x100);
  uVar1 = *(ushort *)(param_1 + 0x15b0);
  if (param_2 < 0x100) {
    local_120 = 0x100;
    local_128 = local_118;
    uVar2 = StorPortGetBusData(param_1,4,uVar1 >> 8,uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5);
    if ((uVar2 & 0xfffffffd) != 0) {
      return *(undefined4 *)((longlong)local_118 + (ulonglong)param_2);
    }
  }
  return 0xffffffff;
}



===== mm_pci_mem_read @ 1400024fc =====

undefined4 mm_pci_mem_read(longlong param_1,uint param_2)

{
  return *(undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0xaf4));
}



===== mm_pci_mem_write @ 140002508 =====

void mm_pci_mem_write(longlong param_1,byte param_2,uint param_3,undefined4 *param_4)

{
  *(undefined4 *)((ulonglong)param_3 + *(longlong *)(param_1 + 0xaf4 + (ulonglong)param_2 * 8)) =
       *param_4;
  LOCK();
  UNLOCK();
  return;
}



===== mm_poll_link_status @ 140002524 =====

undefined8 mm_poll_link_status(longlong param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 * 1000 != 0) {
    do {
      lm_mcp_handle_link_change(param_1);
      if (*(char *)(param_1 + 0x280) != '\0') {
        return 1;
      }
      StorPortStallExecution(0x3de);
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(param_2 * 1000));
  }
  return 0;
}



===== mm_printk @ 14000257c =====

void mm_printk(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(DAT_140020004,DAT_140020008,param_1,&local_res10);
  return;
}



===== _guard_check_icall @ 1400025c0 =====

void _guard_check_icall(void)

{
  return;
}



===== mm_strip_vlan @ 1400025c4 =====

void mm_strip_vlan(longlong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  short sVar1;
  ulonglong uVar2;
  short *psVar3;
  
  if (param_1 != 0) {
    sVar1 = *param_2;
    uVar2 = 0;
    if (sVar1 != 0) {
      psVar3 = (short *)(param_1 + 0xc);
      if (*psVar3 == 0x81) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("Stripping VLAN tag in Rx packet.\n",param_2,param_3,param_4);
        }
        for (; (ushort)uVar2 < (ushort)(sVar1 - 0x10U);
            uVar2 = (ulonglong)(ushort)((ushort)uVar2 + 1)) {
          *(undefined1 *)psVar3 = *(undefined1 *)(uVar2 + 0x10 + param_1);
          psVar3 = (short *)((longlong)psVar3 + 1);
        }
        *param_2 = *param_2 + -4;
      }
      else if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        mm_printk("No VLAN tag in Rx packet.\n",param_2,param_3,param_4);
      }
    }
  }
  return;
}



===== mm_transmit_packet_raw @ 140002678 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
mm_transmit_packet_raw(longlong param_1,undefined8 *param_2,ushort param_3,undefined8 param_4)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  size_t _Size;
  bool bVar4;
  undefined1 auStack_658 [32];
  undefined8 local_638;
  undefined4 local_630;
  undefined2 local_62c;
  ushort local_62a;
  undefined1 local_628 [1520];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_658;
  _Size = (size_t)param_3;
  memset(&local_638,0,0x5f2);
  uVar1 = *(ushort *)(param_1 + 0x12e);
  if (((*(uint *)(param_1 + 0x278) & 4) == 0) || (*(int *)(param_1 + 0x27c) != 1)) {
    if (((*(uint *)(param_1 + 0x278) & 8) == 0) || (*(int *)(param_1 + 0x27c) != 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = (uVar1 & 0x1fff) != 0;
    }
    if (bVar4) {
      local_638 = *param_2;
      _Size = _Size - 0xc;
      local_630 = *(undefined4 *)(param_2 + 1);
      param_2 = (undefined8 *)((longlong)param_2 + 0xc);
      memmove(local_628,param_2,_Size);
      local_62c = 0x81;
      local_62a = (ushort)*(byte *)(param_1 + 0x12f) | uVar1 << 8;
      param_3 = param_3 + 4;
      goto LAB_14000274f;
    }
  }
  memmove(&local_638,param_2,_Size);
LAB_14000274f:
  lVar2 = mm_get_free_pkt_desc(param_1,param_2,_Size,param_4);
  if (lVar2 == 0) {
    if ((~FCoEDebugFlags & 1) == 0) {
      mm_printk("%s(): *** failed to get free pkt desc\n","mm_transmit_packet_raw",_Size,param_4);
    }
    uVar3 = 1;
  }
  else {
    *(ushort *)(lVar2 + 0x22) = param_3;
    *(undefined4 *)(lVar2 + 4) = 0;
    *(undefined2 *)(lVar2 + 8) = 0;
    memmove(*(void **)(lVar2 + 0x10),&local_638,0x5f2);
    uVar3 = lm_send_packet(param_1,lVar2);
  }
  return uVar3;
}



===== FC_Crc32 @ 1400027d0 =====

ulonglong FC_Crc32(ulonglong param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = param_3;
  if (((ulonglong)param_2 & 3) != 0) {
    for (; uVar2 = 0, param_3 != 0; param_3 = param_3 - 1) {
      param_1 = (ulonglong)
                (*(uint *)(&DAT_14000c0e0 + ((ulonglong)(byte)*param_2 ^ param_1 & 0xff) * 4) ^
                (uint)(param_1 >> 8) & 0xffffff);
      param_2 = (uint *)((longlong)param_2 + 1);
    }
  }
  if (3 < uVar2) {
    uVar3 = (ulonglong)(uVar2 >> 2);
    do {
      uVar2 = uVar2 - 4;
      uVar1 = *param_2 ^ (uint)param_1;
      param_2 = param_2 + 1;
      param_1 = (ulonglong)
                (*(uint *)(&DAT_14000c0e0 + (ulonglong)(uVar1 >> 0x18) * 4) ^
                 *(uint *)(&DAT_14000c4e0 + (ulonglong)(uVar1 >> 0x10 & 0xff) * 4) ^
                 *(uint *)(&DAT_14000c8e0 + (ulonglong)(uVar1 >> 8 & 0xff) * 4) ^
                *(uint *)(&DAT_14000cce0 + (ulonglong)(uVar1 & 0xff) * 4));
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = *param_2;
    param_2 = (uint *)((longlong)param_2 + 1);
    param_1 = (ulonglong)
              (*(uint *)(&DAT_14000c0e0 + ((ulonglong)(byte)uVar1 ^ param_1 & 0xff) * 4) ^
              (uint)(param_1 >> 8) & 0xffffff);
  }
  return param_1 & 0xffffffff;
}



===== __security_check_cookie @ 1400028b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 1400028d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== StorPortInitialize @ 1400028fd =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400028fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetPhysicalAddress @ 140002903 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002903. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 140002909 =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002909. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortNotification @ 14000290f =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000290f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortGetBusData @ 140002920 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortStallExecution @ 140002926 =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortExtendedFunction @ 14000292c =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000292c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== __GSHandlerCheck @ 140002934 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002954 =====

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



===== lm_mcp_ov_bw_update_ack @ 1400029c0 =====

bool lm_mcp_ov_bw_update_ack(longlong param_1)

{
  int iVar1;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  iVar1 = elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x32000000,0,local_res10,local_res8)
  ;
  return iVar1 != 0;
}



===== lm_mcp_ov_get_oem_update @ 1400029fc =====

int lm_mcp_ov_get_oem_update(longlong param_1)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined7 extraout_var;
  uint local_res8 [2];
  int local_res10 [2];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  
  pbVar1 = (byte *)(param_1 + 0x284);
  iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x41000000,0,local_res8,local_res10);
  if (iVar3 == 0) {
    if (local_res8[0] == 0x41000000) {
      if (local_res10[0] == 1) {
        elite_mcp_update_bw(param_1,pbVar1);
        bVar2 = lm_mcp_ov_bw_update_ack(param_1);
        iVar3 = (int)CONCAT71(extraout_var,bVar2);
      }
      else {
        if (local_res10[0] != 2) {
          return 0;
        }
        elite_mcp_update_stag(param_1,pbVar1);
        iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x3b000000,0,local_res18,local_res20);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0;
        if (local_res18[0] != 0x3b000000) {
          iVar3 = 3;
        }
      }
    }
    else {
      iVar3 = 3;
    }
  }
  return iVar3;
}



===== lm_mcp_ov_update_bus_num @ 140002abc =====

void lm_mcp_ov_update_bus_num(longlong param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  uVar1 = mm_get_bus_num();
  elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x27000000,(uint)uVar1 & 0xff,local_res10,
                      local_res8);
  return;
}



===== lm_mcp_ov_update_drv_state @ 140002b00 =====

int lm_mcp_ov_update_drv_state(longlong param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  if (param_2 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == 1) {
    uVar2 = 4;
  }
  else {
    if (param_2 != 2) {
      return 3;
    }
    uVar2 = 5;
  }
  iVar1 = elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x31000000,uVar2,local_res10,
                              local_res8);
  if ((iVar1 == 0) && (local_res10[0] != 0x31000000)) {
    iVar1 = 3;
  }
  return iVar1;
}



===== elite_cdu_init_common @ 140002b78 =====

void elite_cdu_init_common(longlong param_1)

{
  uint uVar1;
  
  uVar1 = 1 << ((char)*(undefined4 *)(param_1 + 0x238) + 0xcU & 0x1f);
  elite_init_store_rt_reg(param_1,0x9a,uVar1 % 0x270 << 0xc | uVar1 / 0x270 << 0x18 | 0x270);
  return;
}



===== elite_chip_init_common @ 140002bd8 =====

void elite_chip_init_common(longlong param_1,byte *param_2,uint param_3)

{
  elite_gtt_init(param_1);
  elite_cdu_init_common(param_1);
  elite_init_run(param_1,param_2,0,0xffff,param_3);
  return;
}



===== elite_cxt_hw_init_pf @ 140002c28 =====

void elite_cxt_hw_init_pf(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  undefined4 local_res8;
  uint local_resc;
  
  elite_doorbell_init_pf(param_1);
  puVar3 = (ulonglong *)(param_1 + 0x1f0);
  elite_init_store_rt_reg(param_1,0xd,*(undefined4 *)(param_1 + 0x234));
  elite_init_store_rt_reg(param_1,0xe,*(undefined4 *)(param_1 + 0x230));
  elite_init_store_rt_reg(param_1,0xc,*(undefined4 *)(param_1 + 0x238));
  uVar2 = 0;
  lVar1 = 2;
  do {
    mm_memset(&local_res8,8,0);
    local_res8 = (undefined4)(*puVar3 >> 0xc);
    local_resc = (uint)(*puVar3 >> 0x2c) | local_resc & 0xfff00000 | 0x100000;
    elite_init_store_rt_agg(param_1,(ulonglong)((int)(uVar2 >> 2) + 0xf),(longlong)&local_res8,8);
    uVar2 = uVar2 + 8;
    puVar3 = puVar3 + 3;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  return;
}



===== elite_dmae_cmd @ 140002d04 =====

undefined8 elite_dmae_cmd(longlong param_1,byte *param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint local_res18 [2];
  
  local_res18[0] = (uint)param_3;
  uVar1 = elite_set_ptt(param_1,param_2,0x2aa16c);
  mm_pci_mem_write(param_1,0,uVar1,local_res18);
  uVar1 = 0;
  do {
    uVar2 = elite_set_ptt(param_1,param_2,0x2aa16c);
    uVar2 = mm_pci_mem_read(param_1,uVar2);
    if (uVar2 == param_3) {
      return 0;
    }
    mm_delay(0x32);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 20000);
  return 1;
}



===== elite_doorbell_init_pf @ 140002d98 =====

void elite_doorbell_init_pf(longlong param_1)

{
  elite_init_store_rt_reg(param_1,0,1);
  elite_init_store_rt_reg(param_1,1,1);
  elite_init_store_rt_reg(param_1,2,1);
  elite_init_store_rt_reg(param_1,3,1);
  elite_init_store_rt_reg(param_1,4,1);
  elite_init_store_rt_reg(param_1,5,1);
  return;
}



===== elite_function_start @ 140002e04 =====

ulonglong elite_function_start(longlong param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  undefined4 extraout_var_00;
  undefined4 local_res18 [4];
  
  bVar1 = elite_rx_start(param_1);
  uVar4 = CONCAT71(extraout_var,bVar1);
  if ((int)uVar4 == 0) {
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 8;
    iVar2 = elite_tx_start(param_1);
    uVar4 = CONCAT44(extraout_var_00,iVar2);
    if (iVar2 == 0) {
      local_res18[0] = 0;
      uVar3 = elite_set_ptt(param_1,param_2,0x5011f4);
      mm_pci_mem_write(param_1,0,uVar3,local_res18);
      *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 0x10;
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== elite_get_chip_info @ 140002e6c =====

undefined8 elite_get_chip_info(longlong param_1,byte *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = mm_pci_cfg_read(param_1,0);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar2 = elite_set_ptt(param_1,param_2,0x976c);
  uVar1 = mm_pci_mem_read(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar2 = elite_set_ptt(param_1,param_2,0x9770);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x20) = uVar2 & 0xf;
  *(uint *)(param_1 + 0x10) = (uint)((*(ushort *)(param_1 + 0x16) & 0xff00) == 0x8000);
  uVar2 = elite_set_ptt(param_1,param_2,0x971c);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(char *)(param_1 + 0x91) = ((uVar2 >> (*(uint *)(param_1 + 0x30) & 0x1f) & 1) != 0) + '\x01';
  uVar2 = elite_set_ptt(param_1,param_2,0x9778);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x3c) = uVar2 >> 4 & 0xf;
  uVar2 = elite_set_ptt(param_1,param_2,0x9774);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x40) = uVar2 & 0xff;
  if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x20) == 0)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== elite_get_dev_port_id @ 140002f74 =====

undefined4 elite_get_dev_port_id(longlong param_1,byte *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = uVar5;
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = elite_set_ptt(param_1,param_2,0x218200);
    uVar2 = mm_pci_mem_read(param_1,uVar2);
    uVar3 = 2;
    if ((2 < uVar2) && (uVar3 = 2, uVar2 < 6)) {
      uVar3 = 4;
    }
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x2c) % uVar3;
    if (uVar2 < 3) {
      *(undefined1 *)(param_1 + 0x44) = 1;
    }
    else if (uVar2 < 6) {
      *(undefined1 *)(param_1 + 0x44) = 2;
    }
    else {
      uVar4 = 0xe;
    }
  }
  else {
    uVar4 = 1;
    if (*(int *)(param_1 + 0x10) == 1) {
      *(undefined1 *)(param_1 + 0x44) = 0;
      uVar2 = 0x218200;
      do {
        uVar3 = elite_set_ptt(param_1,param_2,uVar2);
        uVar3 = mm_pci_mem_read(param_1,uVar3);
        cVar1 = *(char *)(param_1 + 0x44);
        if ((uVar3 & 1) != 0) {
          cVar1 = cVar1 + '\x01';
          *(char *)(param_1 + 0x44) = cVar1;
        }
        uVar2 = uVar2 + 4;
      } while ((int)uVar2 < 0x218210);
      if (cVar1 == '\0') {
        uVar4 = 0xe;
      }
      else {
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x34);
        uVar4 = uVar5;
      }
    }
  }
  return uVar4;
}



===== elite_get_fid @ 140003064 =====

void elite_get_fid(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = mm_pci_mem_read(param_1,0x1fc);
  *(uint *)(param_1 + 0x28) = uVar1;
  uVar2 = uVar1 & 0xf;
  *(uint *)(param_1 + 0x2c) = uVar1 >> 0x10 & 0xf;
  *(uint *)(param_1 + 0x30) = uVar2;
  *(uint *)(param_1 + 0x34) = uVar1 >> 4 & 3;
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = (uVar1 >> 0x10 & 1) << 3 | uVar2;
  }
  *(char *)(param_1 + 0x90) = (char)uVar2;
  return;
}



===== elite_get_init_hw_mode @ 1400030b4 =====

undefined8 elite_get_init_hw_mode(longlong param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  *param_2 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 3;
    if (*(int *)(param_1 + 0x10) == 1) {
      iVar4 = 1;
    }
  }
  if (iVar4 == 0) {
    uVar2 = 0x2002;
    uVar3 = 0x802;
    uVar5 = 0x1002;
  }
  else {
    if (iVar4 != 1) {
      return 0xe;
    }
    uVar2 = 0x2004;
    uVar3 = 0x804;
    uVar5 = 0x1004;
  }
  cVar1 = *(char *)(param_1 + 0x44);
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      uVar3 = uVar5;
    }
    else {
      uVar3 = uVar2;
      if (cVar1 != '\x04') {
        return 0xe;
      }
    }
  }
  if (*(int *)(param_1 + 0x27c) == 1) {
    uVar3 = uVar3 | 0x208;
  }
  else {
    uVar3 = uVar3 | 0x408;
  }
  *param_2 = uVar3;
  return 0;
}



===== elite_init_function @ 14000314c =====

void elite_init_function(longlong param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  elite_cxt_hw_init_pf(param_1);
  elite_intr_enable_rt(param_1);
  elite_init_mf_mode_rt(param_1);
  iVar1 = elite_init_run(param_1,param_2,2,*(uint *)(param_1 + 0x30),param_3);
  if (iVar1 == 0) {
    iVar1 = elite_init_run(param_1,param_2,4,*(uint *)(param_1 + 0x30),param_3);
    if (iVar1 == 0) {
      uVar2 = elite_config_sb(param_1);
      if ((int)uVar2 == 0) {
        elite_function_start(param_1,param_2);
      }
    }
  }
  return;
}



===== elite_init_mf_mode_rt @ 1400031d8 =====

void elite_init_mf_mode_rt(longlong param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x27c) == 1) {
    elite_init_store_rt_reg(param_1,0x92,1);
    elite_init_store_rt_reg(param_1,0x96,(uint)*(ushort *)(param_1 + 0x14a));
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x27c) != 2) {
      return;
    }
    uVar1 = 1;
  }
  elite_init_store_rt_reg(param_1,0x91,uVar1);
  return;
}



===== elite_l2_filter_cmd @ 140003234 =====

void elite_l2_filter_cmd(longlong param_1,undefined8 param_2)

{
  undefined4 local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  undefined4 local_18;
  
  local_24 = 5;
  local_res8 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  local_18 = local_res8;
  local_28 = 0x20;
  local_20 = param_2;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_l2b_context_host_alloc @ 140003274 =====

undefined8 elite_l2b_context_host_alloc(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  
  puVar3 = (undefined8 *)(param_1 + 0x200);
  iVar4 = 0;
  do {
    plVar1 = (longlong *)(param_1 + (longlong)iVar4 * 0x18 + 0x1f0);
    uVar2 = mm_page_alloc(param_1,plVar1 + 1,plVar1,1,
                          (undefined8 *)(param_1 + ((longlong)iVar4 + 0x44) * 8));
    if ((int)uVar2 != 0) {
      return 1;
    }
    *puVar3 = 0x1000;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 3;
  } while (iVar4 < 2);
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x230) = 1;
  *(undefined4 *)(param_1 + 0x238) = 3;
  return uVar2;
}



===== elite_ptt_set_win @ 140003304 =====

void elite_ptt_set_win(longlong param_1,byte *param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 4);
  if (param_3 != *puVar1 * 4) {
    *puVar1 = param_3 >> 2;
    mm_pci_mem_write(param_1,0,(uint)*param_2 << 3,puVar1);
  }
  return;
}



===== elite_rd @ 140003334 =====

void elite_rd(longlong param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = elite_set_ptt(param_1,param_2,param_3);
  mm_pci_mem_read(param_1,uVar1);
  return;
}



===== elite_read_igu_cam @ 140003354 =====

undefined8 elite_read_igu_cam(longlong param_1,byte *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  *(undefined4 *)(param_1 + 0x4c) = 0xffff;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0xff;
  do {
    uVar1 = elite_set_ptt(param_1,param_2,uVar4 * 4 + 0x184000);
    uVar1 = mm_pci_mem_read(param_1,uVar1);
    if (((uVar1 & 1) == 0) && ((uVar1 >> 0x11 & 1) != 0)) break;
    if (((uVar1 >> 0x11 & 1) != 0) && ((uVar1 >> 9 & 0xff) == *(uint *)(param_1 + 0x30))) {
      if (*(short *)(param_1 + 0x4c) == -1) {
        *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + 1;
        *(ushort *)(param_1 + 0x4c) = uVar5;
        break;
      }
      if ((uint)uVar3 != uVar4 - 1) break;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + 1;
      uVar3 = uVar5;
    }
    uVar5 = uVar5 + 1;
    uVar4 = (uint)uVar5;
  } while (uVar4 < (-(uint)(*(int *)(param_1 + 0x10) != 0) & 0x50) + 0x120);
  if ((*(short *)(param_1 + 0x4c) == -1) || (*(short *)(param_1 + 0x4e) == 0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_set_ptt @ 140003440 =====

int elite_set_ptt(longlong param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3 + *(int *)(param_2 + 4) * -4;
  if ((param_3 < (uint)(*(int *)(param_2 + 4) * 4)) || (0xfff < uVar1)) {
    elite_ptt_set_win(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return (*param_2 + 1) * 0x1000 + uVar1;
}



===== elite_sp_post @ 14000347c =====

undefined4 elite_sp_post(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x798);
  puVar2 = (uint *)(param_1 + 0x7b8);
  if (*param_2 < 0x41) {
    mm_memset(*(void **)(param_1 + 0x7a8),(uint)(ushort)*param_2,0);
    mm_memset(*(void **)(param_1 + 0x798),8,0);
    mm_memset(puVar2,0x20,0);
    *(undefined4 *)(param_1 + 0x7c8) = *(undefined4 *)(param_1 + 0x7b0);
    *(int *)(param_1 + 0x7cc) = (int)((ulonglong)*(undefined8 *)(param_1 + 0x7b0) >> 0x20);
    *(undefined4 *)(param_1 + 0x7c0) = *(undefined4 *)(param_1 + 0x7a0);
    *(int *)(param_1 + 0x7c4) = (int)((ulonglong)*(undefined8 *)(param_1 + 0x7a0) >> 0x20);
    *puVar2 = param_2[4];
    *(char *)(param_1 + 0x7bc) = (char)param_2[1];
    *(undefined2 *)(param_1 + 0x7be) = 0x55;
    if (*(void **)(param_2 + 2) != (void *)0x0) {
      mm_memcpy(*(void **)(param_1 + 0x7a8),*(void **)(param_2 + 2),(ulonglong)*param_2);
    }
    local_res8[0] = 0;
    uVar4 = **(int **)(param_1 + 0x788) + 0x16000 +
            (uint)*(ushort *)(*(int **)(param_1 + 0x788) + 1) * *(int *)(param_1 + 0x30);
    do {
      mm_pci_mem_write(param_1,0,uVar4,puVar2);
      puVar2 = puVar2 + 1;
      local_res8[0] = local_res8[0] + 1;
      uVar4 = uVar4 + 4;
    } while (local_res8[0] < 8);
    local_res8[0] = 1;
    mm_pci_mem_write(param_1,0,
                     *(int *)(*(longlong *)(param_1 + 0x788) + 0xc) + 0x16000 +
                     (uint)*(ushort *)(*(longlong *)(param_1 + 0x788) + 0x10) *
                     *(int *)(param_1 + 0x30),local_res8);
    mm_delay(10000);
    local_res8[0] = 0;
    do {
      if (((*(char *)(lVar1 + 7) == '\0') && (*(short *)(lVar1 + 4) == 0x55)) &&
         (*(char *)(lVar1 + 6) == (char)param_2[1])) break;
      local_res8[0] = local_res8[0] + 1;
      mm_delay(1000);
    } while (local_res8[0] < 15000);
    uVar3 = 0;
    if (14999 < local_res8[0]) {
      uVar3 = 3;
    }
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}



===== elite_spe_alloc @ 14000362c =====

ulonglong elite_spe_alloc(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  plVar1 = (longlong *)(param_1 + 0x7a0);
  mm_dma_alloc(param_1,(longlong *)(param_1 + 0x798),plVar1,8);
  *(undefined4 *)(param_1 + 0x7c0) = *(undefined4 *)plVar1;
  plVar2 = (longlong *)(param_1 + 0x7b0);
  *(int *)(param_1 + 0x7c4) = (int)((ulonglong)*plVar1 >> 0x20);
  uVar3 = mm_dma_alloc(param_1,(longlong *)(param_1 + 0x7a8),plVar2,0x40);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 != 0) {
    uVar4 = 1;
  }
  *(undefined4 *)(param_1 + 0x7c8) = *(undefined4 *)plVar2;
  *(int *)(param_1 + 0x7cc) = (int)((ulonglong)*plVar2 >> 0x20);
  return uVar4;
}



===== elite_wr @ 1400036b4 =====

undefined8 elite_wr(longlong param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  uVar1 = elite_set_ptt(param_1,param_2,param_3);
  mm_pci_mem_write(param_1,0,uVar1,local_res20);
  return 0;
}



===== lm_ack_enable_intr @ 1400036e4 =====

void lm_ack_enable_intr(longlong param_1,int param_2,byte param_3)

{
  ulonglong local_res8 [4];
  
  local_res8[0] = (ulonglong)((param_2 * 2 | (uint)param_3) << 0x18 | *(uint *)(param_1 + 0xab8));
  mm_pci_mem_write(param_1,0,(uint)*(ushort *)(param_1 + 0xabc) * 8 + 0xf000,
                   (undefined4 *)local_res8);
  return;
}



===== lm_add_multicast_addr @ 140003724 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lm_add_multicast_addr(longlong param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_68 [32];
  undefined1 local_48 [4];
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(byte *)(param_1 + 0xac8) & 8) == 0) {
    return 1;
  }
  if (*(char *)(param_1 + 0xf5) != '\0') {
    iVar2 = lm_lookup_multicast_table(param_1,(longlong)param_2);
    if (iVar2 != -1) {
      return 3;
    }
    bVar1 = *(byte *)(param_1 + 0xf4);
    iVar2 = 0;
    if (bVar1 != 0) {
      pcVar4 = (char *)(param_1 + 0xf6);
      do {
        if (*pcVar4 == '\0') break;
        iVar2 = iVar2 + 1;
        pcVar4 = pcVar4 + 7;
      } while (iVar2 < (int)(uint)bVar1);
    }
    if (iVar2 < (int)(uint)bVar1) {
      mm_memset(local_48,0x20,0);
      local_40 = CONCAT11(param_2[4],param_2[5]);
      local_48[0] = 1;
      local_42 = CONCAT11(param_2[2],param_2[3]);
      local_44 = CONCAT11(*param_2,param_2[1]);
      iVar3 = elite_l2_filter_cmd(param_1,local_48);
      if (iVar3 == 0) {
        mm_memcpy((void *)(param_1 + 0xf7 + (longlong)iVar2 * 7),param_2,6);
        pcVar4 = (char *)((longlong)iVar2 * 7 + 0xf6 + param_1);
        *pcVar4 = *pcVar4 + '\x01';
        *(char *)(param_1 + 0xf5) = *(char *)(param_1 + 0xf5) + -1;
        return 0;
      }
      return iVar3;
    }
  }
  return 2;
}



===== lm_add_unicast_addr @ 140003858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lm_add_unicast_addr(longlong param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_68 [32];
  undefined1 local_48 [4];
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(byte *)(param_1 + 0xac8) & 8) == 0) {
    return 1;
  }
  if (*(char *)(param_1 + 0xbb) != '\0') {
    iVar2 = lm_lookup_unicast_table(param_1,(longlong)param_2);
    if (iVar2 != -1) {
      return 3;
    }
    bVar1 = *(byte *)(param_1 + 0xba);
    iVar2 = 0;
    if (bVar1 != 0) {
      pcVar4 = (char *)(param_1 + 0xbc);
      do {
        if (*pcVar4 == '\0') break;
        iVar2 = iVar2 + 1;
        pcVar4 = pcVar4 + 7;
      } while (iVar2 < (int)(uint)bVar1);
    }
    if (iVar2 < (int)(uint)bVar1) {
      mm_memset(local_48,0x20,0);
      local_40 = CONCAT11(param_2[4],param_2[5]);
      local_48[0] = 1;
      local_42 = CONCAT11(param_2[2],param_2[3]);
      local_44 = CONCAT11(*param_2,param_2[1]);
      iVar3 = elite_l2_filter_cmd(param_1,local_48);
      if (iVar3 == 0) {
        mm_memcpy((void *)(param_1 + 0xbd + (longlong)iVar2 * 7),param_2,6);
        pcVar4 = (char *)((longlong)iVar2 * 7 + 0xbc + param_1);
        *pcVar4 = *pcVar4 + '\x01';
        *(char *)(param_1 + 0xbb) = *(char *)(param_1 + 0xbb) + -1;
        return 0;
      }
      return iVar3;
    }
  }
  return 2;
}



===== lm_chip_init @ 14000398c =====

ulonglong lm_chip_init(longlong param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  ulonglong uVar5;
  undefined4 uVar6;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  uint local_res18 [2];
  
  local_res8[0] = 0;
  pbVar1 = (byte *)(param_1 + 0x284);
  local_res10[0] = 0;
  uVar4 = elite_dmae_cmd(param_1,pbVar1,1);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 1;
  uVar4 = elite_get_init_hw_mode(param_1,local_res18);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  if (*(int *)(param_1 + 0x27c) == 1) {
    if ((*(uint *)(param_1 + 0x278) & 4) == 0) {
      if ((*(uint *)(param_1 + 0x278) & 8) == 0) goto LAB_140003a2e;
      uVar6 = 0x88a8;
    }
    else {
      uVar6 = 0x8100;
    }
    elite_init_store_rt_reg(param_1,0xb,uVar6);
    elite_init_store_rt_reg(param_1,0x8f,uVar6);
    elite_init_store_rt_reg(param_1,0x9b,uVar6);
  }
LAB_140003a2e:
  uVar4 = elite_mcp_load_req(param_1,pbVar1,local_res8);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  elite_mcp_set_capab(param_1,pbVar1);
  if (local_res8[0] == 0x10100000) {
    uVar2 = elite_chip_init_common(param_1,pbVar1,local_res18[0]);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_140003abe;
LAB_140003a8f:
    uVar2 = elite_init_run(param_1,pbVar1,1,*(uint *)(param_1 + 0x34),local_res18[0]);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_140003abe;
  }
  else {
    if (local_res8[0] == 0x10110000) goto LAB_140003a8f;
    if (local_res8[0] != 0x10120000) {
      return 1;
    }
  }
  uVar2 = elite_init_function(param_1,pbVar1,local_res18[0]);
  uVar4 = (ulonglong)uVar2;
LAB_140003abe:
  iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x11000000,0,local_res8,local_res10);
  uVar5 = CONCAT44(extraout_var,iVar3);
  if (iVar3 == 0) {
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 4;
    *(byte *)(param_1 + 0xaca) = *(byte *)(param_1 + 0xaca) | 1;
    elite_issue_mcp_cmd(param_1,pbVar1,0x29000000,0x8210100,local_res8,local_res10);
    lm_mcp_ov_update_drv_state(param_1,1);
    if (*(int *)(param_1 + 0x2c) == 0) {
      lm_mcp_ov_update_bus_num(param_1);
    }
    lm_mcp_ov_get_oem_update(param_1);
    uVar5 = uVar4;
  }
  return uVar5;
}



===== lm_disable_intr @ 140003b58 =====

void lm_disable_intr(longlong param_1)

{
  if (*(char *)(param_1 + 0xac9) != '\0') {
    elite_intr_disable_igu(param_1);
  }
  return;
}



===== lm_enable_intr @ 140003b70 =====

void lm_enable_intr(longlong param_1)

{
  if (*(char *)(param_1 + 0xac9) == '\0') {
    elite_intr_enable_igu(param_1);
  }
  return;
}



===== lm_get_dev_id @ 140003b88 =====

undefined8 lm_get_dev_id(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = mm_pci_mem_read(param_1,0x1f8);
  *(int *)(param_1 + 0x24) = iVar1;
  if (iVar1 == -1) {
    uVar3 = 0xd;
  }
  else {
    uVar2 = mm_pci_mem_read(param_1,0x1fc);
    *(uint *)(param_1 + 0x28) = uVar2;
    *(uint *)(param_1 + 0x2c) = uVar2 >> 0x10 & 0xf;
    *(uint *)(param_1 + 0x30) = uVar2 & 0xf;
    *(uint *)(param_1 + 0x34) = uVar2 >> 4 & 3;
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_get_dev_info @ 140003be0 =====

ulonglong lm_get_dev_info(uint *param_1)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  int local_res8 [2];
  
  puVar1 = param_1 + 0xa1;
  uVar3 = mm_pci_cfg_read((longlong)param_1,8);
  *(char *)(param_1 + 6) = (char)uVar3;
  if ((char)uVar3 == -1) {
    uVar7 = 1;
  }
  else {
    param_1[0x9e] = 0;
    uVar4 = mm_pci_mem_read((longlong)param_1,0x1f8);
    param_1[9] = uVar4;
    if (uVar4 == 0xffffffff) {
      uVar7 = 0xd;
    }
    else {
      param_1[0xa2] = 0xffffffff;
      param_1[0xa5] = 0xffffffff;
      param_1[0xa8] = 0xffffffff;
      *(byte *)puVar1 = 0;
      *(undefined1 *)(param_1 + 0xa4) = 1;
      *(undefined1 *)(param_1 + 0xa7) = 2;
      uVar7 = elite_get_chip_info((longlong)param_1,(byte *)puVar1);
      if ((int)uVar7 == 0) {
        elite_get_fid((longlong)param_1);
        local_res8[0] = 1 << ((byte)param_1[0xb] & 0x1f);
        uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x2aa138);
        mm_pci_mem_write((longlong)param_1,0,uVar4,local_res8);
        local_res8[0] = 1;
        uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x2aa174);
        mm_pci_mem_write((longlong)param_1,0,uVar4,local_res8);
        iVar5 = elite_get_dev_port_id((longlong)param_1,(byte *)puVar1);
        uVar7 = CONCAT44(extraout_var_00,iVar5);
        if (iVar5 == 0) {
          uVar7 = elite_cfg_mcp_cmd_interface((longlong)param_1);
          if ((int)uVar7 == 0) {
            elite_get_mfw_version((longlong)param_1);
            bVar2 = elite_get_scratch_nvm_cfg_addr((longlong)param_1);
            uVar7 = CONCAT71(extraout_var,bVar2);
            if ((int)uVar7 == 0) {
              uVar7 = elite_get_dev_info_nvm(param_1);
              if ((int)uVar7 == 0) {
                uVar7 = elite_mcp_get_capab((longlong)param_1,(byte *)puVar1);
                if ((int)uVar7 == 0) {
                  uVar7 = elite_read_igu_cam((longlong)param_1,(byte *)puVar1);
                  if ((int)uVar7 == 0) {
                    *(undefined **)(param_1 + 0x1e2) = &DAT_14000d0e0;
                    uVar4 = 0xe4;
                    if (param_1[4] != 1) {
                      uVar4 = 0x80;
                    }
                    uVar6 = 0xe0;
                    if (param_1[4] != 1) {
                      uVar6 = 0x78;
                    }
                    param_1[0x25] = uVar6;
                    param_1[0x26] = uVar4;
                    param_1[0x28] = 0;
                    param_1[0x27] = 0x20;
                    uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x9760);
                    mm_pci_mem_read((longlong)param_1,uVar4);
                    uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x9760);
                    uVar3 = mm_pci_mem_read((longlong)param_1,uVar4);
                    *(byte *)(param_1 + 0x29) = (byte)uVar3 & 1;
                    uVar7 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar7;
}



===== lm_init_resc @ 140003dd8 =====

void lm_init_resc(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = elite_alloc_status_block(param_1);
  if ((int)uVar1 == 0) {
    uVar1 = elite_setup_rx_chain(param_1);
    if ((int)uVar1 == 0) {
      uVar1 = elite_setup_tx_chain(param_1);
      if ((int)uVar1 == 0) {
        uVar1 = elite_l2b_context_host_alloc(param_1);
        if ((int)uVar1 == 0) {
          uVar1 = elite_dma_info_alloc(param_1);
          if ((int)uVar1 == 0) {
            elite_spe_alloc(param_1);
          }
        }
      }
    }
  }
  return;
}



===== lm_lookup_multicast_table @ 140003e28 =====

int lm_lookup_multicast_table(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  if (*(char *)(param_1 + 0xf4) != '\0') {
    pcVar3 = (char *)(param_1 + 0xf6);
    do {
      if ((*pcVar3 == '\x01') &&
         (iVar1 = mm_memcmp((char *)((longlong)iVar2 * 7 + 0xf7 + param_1),param_2,6), iVar1 == 0))
      {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      pcVar3 = pcVar3 + 7;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0xf4));
  }
  return -1;
}



===== lm_lookup_unicast_table @ 140003ea8 =====

int lm_lookup_unicast_table(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  if (*(char *)(param_1 + 0xba) != '\0') {
    pcVar3 = (char *)(param_1 + 0xbc);
    do {
      if ((*pcVar3 == '\x01') &&
         (iVar1 = mm_memcmp((char *)(((longlong)iVar2 + 0x1b) * 7 + param_1),param_2,6), iVar1 == 0)
         ) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      pcVar3 = pcVar3 + 7;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0xba));
  }
  return -1;
}



===== lm_mcp_cfg_link @ 140003f28 =====

int lm_mcp_cfg_link(longlong param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((*(byte *)(param_1 + 0xaca) & 1) != 0) {
    iVar2 = elite_set_link_mcp(param_1,(byte *)(param_1 + 0x284),(char)param_2);
    if (iVar2 == 0) {
      if (param_2 == 0) {
        *(undefined1 *)(param_1 + 0x280) = 0;
        bVar1 = *(byte *)(param_1 + 0xaca) & 0xfd;
      }
      else {
        bVar1 = *(byte *)(param_1 + 0xaca) | 2;
      }
      *(byte *)(param_1 + 0xaca) = bVar1;
      if ((param_2 != 0) && (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x38))) {
        elite_wait_for_stable_link(param_1,(byte *)(param_1 + 0x284));
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== lm_mcp_handle_link_change @ 140003fa8 =====

ulonglong lm_mcp_handle_link_change(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = elite_mcp_link_handler(param_1,(byte *)(param_1 + 0x290),'\0');
  return uVar1 & 0xff;
}



===== lm_post_buffers @ 140003fc4 =====

ulonglong lm_post_buffers(longlong param_1)

{
  short sVar1;
  undefined6 extraout_var;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  sVar1 = elite_replenish_bd_chain((longlong *)(param_1 + 0x7d8));
  if ((int)CONCAT62(extraout_var,sVar1) != 0) {
    local_res8[0] =
         CONCAT22(*(undefined2 *)(param_1 + 0x7ec),(short)local_res8[0]) & 0xffffff30 | 0x46;
    mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0x9c),local_res8);
  }
  return CONCAT62(extraout_var,sVar1) & 0xffffffff;
}



===== lm_reg_read @ 140004030 =====

undefined8 lm_reg_read(longlong param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    uVar3 = 1;
  }
  else {
    uVar1 = elite_set_ptt(param_1,(byte *)(param_1 + 0x284),param_2);
    uVar2 = mm_pci_mem_read(param_1,uVar1);
    *param_3 = uVar2;
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_reg_write @ 14000407c =====

bool lm_reg_write(longlong param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 local_res8 [8];
  
  if (param_1 != 0) {
    local_res8[0] = param_3;
    uVar1 = elite_set_ptt(param_1,(byte *)(param_1 + 0x284),param_2);
    mm_pci_mem_write(param_1,0,uVar1,local_res8);
  }
  return param_1 == 0;
}



===== lm_send_packet @ 1400040c0 =====

void lm_send_packet(longlong param_1,longlong param_2)

{
  if ((*(uint *)(param_1 + 0x278) & 1) == 0) {
    elite_send_packet(param_1,param_2);
  }
  return;
}



===== lm_service_intr @ 1400040e0 =====

undefined4 lm_service_intr(longlong param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  sVar1 = 0;
  sVar2 = 0;
  if ((*(uint *)(param_1 + 0x278) & 1) == 0) {
    uVar4 = elite_has_tx_work(param_1);
    if ((char)uVar4 != '\0') {
      sVar1 = elite_process_tx_completions(param_1);
    }
    uVar4 = elite_has_rx_work(param_1);
    if ((char)uVar4 != '\0') {
      sVar2 = elite_process_rx_pkt(param_1);
    }
    uVar4 = elite_has_tx_work(param_1);
    if ((char)uVar4 == '\0') {
      elite_has_rx_work(param_1);
    }
    if (((sVar1 != 0) || (sVar2 != 0)) &&
       (uVar5 = *(uint *)(*(longlong *)(param_1 + 0xaa8) + 0x1c) & 0xffffff,
       *(uint *)(param_1 + 0xab8) != uVar5)) {
      *(uint *)(param_1 + 0xab8) = uVar5;
    }
    uVar3 = CONCAT22(sVar1,sVar2);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_set_rx_mask @ 140004194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 lm_set_rx_mask(longlong param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined1 local_38 [2];
  undefined1 local_36;
  undefined1 local_2c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if ((*(byte *)(param_1 + 0xac8) & 8) == 0) {
    uVar1 = 1;
  }
  else {
    mm_memset(local_38,0x20,0);
    *(undefined1 *)(param_1 + 0x131) = param_2;
    local_36 = 1;
    local_2c = param_2;
    uVar1 = elite_l2_filter_cmd(param_1,local_38);
  }
  return uVar1;
}



===== lm_shutdown @ 14000420c =====

ulonglong lm_shutdown(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  
  uVar6 = 0;
  pbVar1 = (byte *)(param_1 + 0x284);
  if (*(char *)(param_1 + 0xac9) != '\0') {
    elite_intr_disable_igu(param_1);
    local_res10[0] = 0;
    uVar3 = elite_set_ptt(param_1,pbVar1,0x18082c);
    mm_pci_mem_write(param_1,0,uVar3,local_res10);
    local_res10[0] = 0;
    uVar3 = elite_set_ptt(param_1,pbVar1,0x180830);
    mm_pci_mem_write(param_1,0,uVar3,local_res10);
  }
  local_res10[0] = 1;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x5011f4);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  bVar2 = *(byte *)(param_1 + 0xac8);
  if ((bVar2 & 8) != 0) {
    elite_rx_stop(param_1);
    elite_cfc_delete(param_1,1);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xf7;
    bVar2 = *(byte *)(param_1 + 0xac8);
  }
  if ((bVar2 & 0x10) != 0) {
    elite_tx_stop(param_1);
    elite_cfc_delete(param_1,0);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xef;
  }
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2c043c);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2c0444);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  uVar3 = 0;
  do {
    uVar4 = elite_set_ptt(param_1,pbVar1,0x2c04fc);
    iVar5 = mm_pci_mem_read(param_1,uVar4);
    if (iVar5 == 0) {
      uVar4 = elite_set_ptt(param_1,pbVar1,0x2c0500);
      iVar5 = mm_pci_mem_read(param_1,uVar4);
      if (iVar5 == 0) break;
    }
    mm_delay(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10);
  if ((*(byte *)(param_1 + 0xac8) & 1) != 0) {
    uVar6 = elite_dmae_cmd(param_1,pbVar1,0);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xfe;
    uVar6 = uVar6 & 0xffffffff;
  }
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x100508);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2f2ea4);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2d0708);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2e0708);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  if ((*(byte *)(param_1 + 0xac8) & 4) != 0) {
    iVar5 = elite_issue_mcp_cmd(param_1,pbVar1,0x20000000,1,local_res8,local_res18);
    if (iVar5 != 0) {
      local_res8[0] = 0x20110000;
    }
    uVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x21000000,0,local_res8,local_res18);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xf9;
    uVar6 = (ulonglong)uVar3;
  }
  *(byte *)(param_1 + 0xaca) = *(byte *)(param_1 + 0xaca) & 0xfe;
  lm_mcp_ov_update_drv_state(param_1,0);
  return uVar6;
}



===== elite_cfg_mcp_cmd_interface @ 1400044dc =====

undefined8 elite_cfg_mcp_cmd_interface(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  elite_get_mcp_public_offsets(param_1,(byte *)(param_1 + 0x284));
  lVar1 = mm_alloc_pool(param_1,((int)(*(ushort *)(param_1 + 0x178) - 1) >> 2) * 4 + 4);
  *(longlong *)(param_1 + 0x168) = lVar1;
  lVar1 = mm_alloc_pool(param_1,((int)(*(ushort *)(param_1 + 0x178) - 1) >> 2) * 4 + 4);
  *(longlong *)(param_1 + 0x170) = lVar1;
  if ((*(longlong *)(param_1 + 0x168) == 0) || (lVar1 == 0)) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_get_dev_info_nvm @ 140004554 =====

undefined8 elite_get_dev_info_nvm(uint *param_1)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  
  puVar1 = param_1 + 0xa1;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,param_1[0x6b] + 0xe20000);
  uVar6 = uVar4 >> 4 & 0xff;
  if ((char)(uVar4 >> 4) == '\0') {
LAB_1400045b0:
    param_1[0x9f] = 1;
  }
  else {
    if ((uVar6 != 1) && (uVar6 != 3)) {
      if (uVar6 == 6) {
        param_1[0x9e] = param_1[0x9e] | 8;
      }
      else {
        if (uVar6 != 7) goto LAB_1400045f1;
        param_1[0x9e] = param_1[0x9e] | 4;
      }
      goto LAB_1400045b0;
    }
LAB_1400045f1:
    param_1[0x9f] = 2;
  }
  uVar4 = param_1[0x6b];
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20050);
  *param_1 = (uint)uVar3;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar6 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20b94 + uVar6 * 0x50);
  param_1[0x2a] = uVar6;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar6 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20b90 + uVar6 * 0x50);
  param_1[0x2b] = uVar6;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20ba0 + uVar6 * 0x50);
  param_1[1] = (uint)uVar3;
  iVar7 = (param_1[0xb] %
          (((((uint)uVar3 - (uint)uVar3) - (uint)(param_1[4] != 0)) + 2) * (uint)(byte)param_1[0x11]
          )) * 600 + param_1[0x6b];
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe20244);
  param_1[0x70] = (uint)uVar3;
  param_1[0x7a] = (uint)uVar3;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe20248);
  uVar6 = uVar4 & 0xf;
  if (uVar6 == 0) {
    *(undefined1 *)(param_1 + 0x6f) = 1;
  }
  else if (uVar6 == 1) {
    param_1[0x71] = 1000;
  }
  else if (uVar6 == 2) {
    param_1[0x71] = 10000;
  }
  else if (uVar6 == 3) {
    param_1[0x71] = 20000;
  }
  else if (uVar6 == 4) {
    param_1[0x71] = 25000;
  }
  else if (uVar6 == 5) {
    param_1[0x71] = 40000;
  }
  else if (uVar6 == 6) {
    param_1[0x71] = 50000;
  }
  else {
    if (uVar6 != 7) {
      return 1;
    }
    param_1[0x71] = 100000;
  }
  param_1[0x73] = 0;
  uVar4 = uVar4 >> 4 & 7;
  *(byte *)(param_1 + 0x72) = (byte)uVar4 & 1;
  *(char *)((longlong)param_1 + 0x1ca) = (char)(uVar4 >> 2);
  *(byte *)((longlong)param_1 + 0x1c9) = (byte)(uVar4 >> 1) & 1;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe2025c);
  param_1[0x6d] = uVar4 >> 0x11 & 0xff;
  uVar5 = elite_mcp_read_core_config((longlong)param_1,(byte *)puVar1);
  if ((int)uVar5 != 0) {
    return 1;
  }
  iVar7 = elite_mcp_read_func_info((longlong)param_1,(byte *)puVar1);
  if (iVar7 != 0) {
    return 1;
  }
  bVar2 = elite_rd((longlong)param_1,(byte *)puVar1,param_1[0x6b] + 0xe2002c);
  if (bVar2 < 0xd) {
    if ((bVar2 == 0xc) || (bVar2 < 2)) goto LAB_140004843;
    if (bVar2 != 2) {
      if (2 < bVar2) {
        if (bVar2 < 6) goto LAB_14000484c;
        if (bVar2 == 0xb) goto LAB_14000480d;
      }
LAB_140004825:
      *(undefined1 *)((longlong)param_1 + 0x93) = 0;
      return 1;
    }
  }
  else if (bVar2 != 0xd) {
    if (bVar2 == 0xe) {
LAB_14000484c:
      *(undefined1 *)((longlong)param_1 + 0x93) = 4;
      return 0;
    }
    if (bVar2 != 0xf) goto LAB_140004825;
LAB_140004843:
    *(undefined1 *)((longlong)param_1 + 0x93) = 2;
    return 0;
  }
LAB_14000480d:
  *(undefined1 *)((longlong)param_1 + 0x93) = 1;
  return 0;
}



===== elite_get_mcp_public_offsets @ 140004858 =====

bool elite_get_mcp_public_offsets(longlong param_1,byte *param_2)

{
  int iVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar6 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | uVar6;
  }
  uVar4 = elite_rd(param_1,param_2,0x8c20);
  *(uint *)(param_1 + 0x150) = uVar4;
  if (uVar4 != 0) {
    uVar7 = uVar4 | 0xe00000;
    *(uint *)(param_1 + 0x150) = uVar7;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 4);
    *(uint *)(param_1 + 0x154) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 8);
    uVar5 = (uVar5 >> 0xe & 0x3fffc) * uVar6 + ((uVar5 & 0xffff) + 0x388000) * 4;
    *(uint *)(param_1 + 0x158) = uVar5;
    uVar2 = elite_rd(param_1,param_2,uVar5);
    *(undefined2 *)(param_1 + 0x178) = uVar2;
    uVar2 = elite_rd(param_1,param_2,*(uint *)(param_1 + 0x154));
    *(undefined2 *)(param_1 + 0x160) = uVar2;
    uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 0x10);
    *(ushort *)(param_1 + 0x162) = uVar3 & 0x7fff;
    uVar2 = elite_rd(param_1,param_2,0x96d4);
    *(undefined2 *)(param_1 + 0x198) = uVar2;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0xc);
    *(uint *)(param_1 + 0x184) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x10);
    *(uint *)(param_1 + 0x188) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x14);
    uVar8 = uVar5 >> 0xe & 0x3fffc;
    iVar1 = (uVar5 & 0xffff) * 4 + 0xe20000;
    *(uint *)(param_1 + 0x18c) = uVar8 * uVar6 + iVar1;
    *(uint *)(param_1 + 0x15c) =
         (*(uint *)(param_1 + 0x2c) %
         ((2 - (uint)(*(int *)(param_1 + 0x10) != 0)) * (uint)*(byte *)(param_1 + 0x44))) * uVar8 +
         iVar1;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x18);
    *(uint *)(param_1 + 400) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
  }
  return uVar4 == 0;
}



===== elite_get_mfw_version @ 140004a84 =====

void elite_get_mfw_version(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = elite_rd(param_1,(byte *)(param_1 + 0x284),*(int *)(param_1 + 0x150) + 0xc);
  uVar2 = elite_rd(param_1,(byte *)(param_1 + 0x284),(uVar1 & 0xffff) * 4 + 0xe20018);
  *(undefined4 *)(param_1 + 0x194) = uVar2;
  return;
}



===== elite_get_scratch_nvm_cfg_addr @ 140004ad4 =====

bool elite_get_scratch_nvm_cfg_addr(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = elite_rd(param_1,(byte *)(param_1 + 0x284),0x8c80);
  *(int *)(param_1 + 0x1a8) = iVar1;
  if (iVar1 != 0) {
    uVar2 = elite_rd(param_1,(byte *)(param_1 + 0x284),iVar1 + 4);
    *(undefined4 *)(param_1 + 0x1ac) = uVar2;
  }
  return iVar1 == 0;
}



===== elite_issue_mcp_cmd @ 140004b2c =====

undefined4
elite_issue_mcp_cmd(longlong param_1,byte *param_2,uint param_3,undefined4 param_4,uint *param_5,
                   undefined4 *param_6)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    *(undefined1 *)(param_1 + 0x1a0) = 1;
    if (*(int *)(param_1 + 0x150) == 0) {
      uVar5 = 1;
    }
    else {
      uVar2 = elite_rd(param_1,param_2,0x96d4);
      if (*(ushort *)(param_1 + 0x198) != uVar2) {
        elite_get_mcp_public_offsets(param_1,param_2);
      }
      *(short *)(param_1 + 0x160) = *(short *)(param_1 + 0x160) + 1;
      uVar1 = *(ushort *)(param_1 + 0x160);
      elite_wr(param_1,param_2,*(int *)(param_1 + 0x154) + 4,param_4);
      elite_wr(param_1,param_2,*(uint *)(param_1 + 0x154),uVar1 | param_3);
      uVar2 = 1;
      do {
        mm_delay(10);
        uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 8);
        *param_5 = uVar3;
        if ((uint)uVar1 == (uVar3 & 0xffff)) {
          *(undefined2 *)param_5 = 0;
          uVar4 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 0xc);
          *param_6 = uVar4;
          goto LAB_140004c56;
        }
        bVar6 = uVar2 < 5000000;
        uVar2 = uVar2 + 1;
      } while (bVar6);
      *param_5 = 0;
      uVar5 = 1;
LAB_140004c56:
      *(undefined1 *)(param_1 + 0x1a0) = 0;
    }
  }
  else {
    uVar5 = 0x19;
  }
  return uVar5;
}



===== elite_mcp_do_load_req @ 140004c7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void elite_mcp_do_load_req(longlong param_1,byte *param_2,uint *param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  uint local_50 [4];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  if (0x10000 < (param_5 & 0xff0000)) {
    mm_memset(local_50,0x10,0);
    uVar2 = mm_get_drv_version_dword();
    local_50[0] = (uint)uVar2;
    uVar2 = mm_get_drv_type();
    iVar1 = *(int *)(param_1 + 0x154);
    local_50[1] = (int)uVar2;
    local_50[3] = param_4 << 0x10 | 1;
    uVar3 = 0;
    lVar4 = 0;
    local_50[2] = 0x8210100;
    do {
      elite_wr(param_1,param_2,uVar3 + iVar1 + 0x18,*(undefined4 *)((longlong)local_50 + lVar4));
      uVar3 = uVar3 + 4;
      lVar4 = lVar4 + 4;
    } while (uVar3 < 0x10);
  }
  elite_issue_mcp_cmd(param_1,param_2,0x10000000,param_5 | 0x4002108,param_3,local_58);
  return;
}



===== elite_mcp_get_capab @ 140004d6c =====

void elite_mcp_get_capab(longlong param_1,byte *param_2)

{
  uint local_res8 [8];
  
  elite_issue_mcp_cmd(param_1,param_2,0x310000,0,local_res8,(undefined4 *)(param_1 + 0x19c));
  return;
}



===== elite_mcp_link_handler @ 140004d9c =====

ulonglong elite_mcp_link_handler(longlong param_1,byte *param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  
  if ((*(byte *)(param_1 + 0xaca) & 2) == 0) goto LAB_140004f23;
  register0x00000020 = (BADSPACEBASE *)mm_memset((byte *)(param_1 + 0x1d0),0x18,0);
  if (param_3 != '\0') goto LAB_140004f23;
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x15c) + 4);
  bVar5 = (byte)uVar2 & 1;
  *(undefined1 *)(param_1 + 0x1d8) = 1;
  *(byte *)(param_1 + 0x1d0) = bVar5;
  uVar4 = uVar2 & 0x1e;
  if (uVar4 == 2) {
    *(undefined1 *)(param_1 + 0x1d8) = 0;
LAB_140004e82:
    *(undefined4 *)(param_1 + 0x1d4) = 1000;
  }
  else {
    if (uVar4 == 4) goto LAB_140004e82;
    if (uVar4 == 6) {
      *(undefined4 *)(param_1 + 0x1d4) = 10000;
    }
    else if (uVar4 == 8) {
      *(undefined4 *)(param_1 + 0x1d4) = 20000;
    }
    else if (uVar4 == 10) {
      *(undefined4 *)(param_1 + 0x1d4) = 40000;
    }
    else if (uVar4 == 0xc) {
      *(undefined4 *)(param_1 + 0x1d4) = 50000;
    }
    else if (uVar4 == 0xe) {
      *(undefined4 *)(param_1 + 0x1d4) = 100000;
    }
    else {
      uVar3 = 25000;
      if (uVar4 != 0x10) {
        uVar3 = 0;
      }
      *(undefined4 *)(param_1 + 0x1d4) = uVar3;
    }
  }
  *(byte *)(param_1 + 0x1d9) = (byte)(uVar2 >> 5) & 1;
  *(byte *)(param_1 + 0x1da) = (byte)(uVar2 >> 6) & 1;
  *(byte *)(param_1 + 0x1db) = (byte)(uVar2 >> 7) & 1;
  *(byte *)(param_1 + 0x1dc) = (byte)(uVar2 >> 8) & 1;
  *(uint *)(param_1 + 0x1e0) =
       *(uint *)(param_1 + 0x1e0) | uVar2 >> 10 & 1 | uVar2 >> 9 & 0x7c | uVar2 >> 8 & 2;
  *(byte *)(param_1 + 0x1e4) = (byte)(uVar2 >> 0x15) & 1;
  *(byte *)(param_1 + 0x1e5) = (byte)(uVar2 >> 0x16) & 1;
  uVar4 = uVar2 & 0xc0000;
  if (uVar4 == 0x40000) {
    *(undefined1 *)(param_1 + 0x1e6) = 1;
    uVar4 = 0x40000;
  }
  else {
    cVar1 = (uVar4 != 0x80000) + '\x02';
    uVar4 = CONCAT31((int3)(uVar4 >> 8),cVar1);
    *(char *)(param_1 + 0x1e6) = cVar1;
  }
  register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar4;
  *(byte *)(param_1 + 0x1e7) = (byte)(uVar2 >> 0x14) & 1;
  *(byte *)(param_1 + 0x280) = bVar5;
LAB_140004f23:
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== elite_mcp_load_req @ 140004f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 elite_mcp_load_req(longlong param_1,byte *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar3 = 0x20000;
  uVar2 = elite_mcp_do_load_req(param_1,param_2,param_3,0,0x20000);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  if (*param_3 == 0x10210000) {
    iVar5 = 0;
    uVar3 = 0x10000;
  }
  else {
    if (*param_3 != 0x10300000) goto LAB_140004ffd;
    mm_memset(local_58,0x10,0);
    iVar5 = *(int *)(param_1 + 0x154);
    uVar4 = 0;
    lVar6 = 0;
    do {
      uVar1 = elite_rd(param_1,param_2,uVar4 + iVar5 + 0x18);
      uVar4 = uVar4 + 4;
      *(undefined4 *)((longlong)local_58 + lVar6) = uVar1;
      lVar6 = lVar6 + 4;
    } while (uVar4 < 0x10);
    iVar5 = 2;
  }
  uVar2 = elite_mcp_do_load_req(param_1,param_2,param_3,iVar5,uVar3);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
LAB_140004ffd:
  uVar3 = *param_3;
  if ((((uVar3 == 0x11100000) || (uVar3 == 0x10100000)) || (uVar3 == 0x10110000)) ||
     (uVar3 == 0x10120000)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_mcp_read_boot_protocol @ 140005040 =====

uint elite_mcp_read_boot_protocol(longlong param_1,byte *param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe20ba4 + uVar1 * 0x50);
  return uVar1 & 7;
}



===== elite_mcp_read_core_config @ 140005080 =====

undefined8 elite_mcp_read_core_config(longlong param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe2002c);
  if (bVar1 < 6) {
    if (bVar1 != 5) {
      if (bVar1 == 0) {
        *(undefined4 *)(param_1 + 0x48) = 0;
        return 0;
      }
      if (bVar1 == 1) {
        *(undefined4 *)(param_1 + 0x48) = 1;
        return 0;
      }
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 0x48) = 2;
        return 0;
      }
      if (bVar1 == 3) {
        *(undefined4 *)(param_1 + 0x48) = 3;
        return 0;
      }
      if (bVar1 == 4) {
        *(undefined4 *)(param_1 + 0x48) = 4;
        return 0;
      }
      return 1;
    }
  }
  else {
    if (bVar1 == 0xb) {
      *(undefined4 *)(param_1 + 0x48) = 6;
      return 0;
    }
    if ((bVar1 != 0xc) && (bVar1 != 0xd)) {
      if (bVar1 == 0xe) {
        *(undefined4 *)(param_1 + 0x48) = 9;
        return 0;
      }
      if (bVar1 == 0xf) {
        *(undefined4 *)(param_1 + 0x48) = 10;
        return 0;
      }
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 0x48) = 5;
  return 0;
}



===== elite_mcp_read_func_info @ 140005134 =====

int elite_mcp_read_func_info(longlong param_1,byte *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar8 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x30);
  }
  iVar7 = (uVar2 >> 0xe & 0x3fffc) * uVar8 + (uVar2 & 0xffff) * 4;
  uVar2 = elite_rd(param_1,param_2,iVar7 + 0xe20028);
  *(byte *)(param_1 + 0xb0) = (byte)(uVar2 >> 1) & 1;
  uVar8 = uVar2 & 0xf0;
  if (uVar8 == 0) {
    *(undefined1 *)(param_1 + 0xb1) = 1;
  }
  else if (uVar8 == 0x10) {
    *(undefined1 *)(param_1 + 0xb1) = 4;
  }
  else if (uVar8 == 0x20) {
    *(undefined1 *)(param_1 + 0xb1) = 8;
  }
  else {
    if (uVar8 != 0x30) {
      return 3;
    }
    *(undefined1 *)(param_1 + 0xb1) = 2;
  }
  *(char *)(param_1 + 0xb3) = (char)(uVar2 >> 0x10);
  *(char *)(param_1 + 0xb2) = (char)(uVar2 >> 8);
  iVar3 = elite_rd(param_1,param_2,iVar7 + 0xe20030);
  iVar4 = elite_rd(param_1,param_2,iVar7 + 0xe20034);
  if ((iVar3 == 0) && (iVar4 == 0)) {
    return 3;
  }
  *(char *)(param_1 + 0xb9) = (char)iVar4;
  *(char *)(param_1 + 0xb4) = (char)((uint)iVar3 >> 8);
  *(char *)(param_1 + 0xb5) = (char)iVar3;
  *(char *)(param_1 + 0xb6) = (char)((uint)iVar4 >> 0x18);
  *(char *)(param_1 + 0xb7) = (char)((uint)iVar4 >> 0x10);
  *(char *)(param_1 + 0xb8) = (char)((uint)iVar4 >> 8);
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20038);
  uVar6 = elite_rd(param_1,param_2,iVar7 + 0xe2003c);
  *(undefined4 *)(param_1 + 0x138) = uVar5;
  *(undefined4 *)(param_1 + 0x134) = uVar6;
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20040);
  uVar6 = elite_rd(param_1,param_2,iVar7 + 0xe20044);
  *(undefined4 *)(param_1 + 0x140) = uVar5;
  *(undefined4 *)(param_1 + 0x13c) = uVar6;
  uVar1 = elite_rd(param_1,param_2,iVar7 + 0xe20048);
  *(undefined2 *)(param_1 + 0x14a) = uVar1;
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20008);
  *(undefined4 *)(param_1 + 0x144) = uVar5;
  *(undefined1 *)(param_1 + 0x148) = 0;
  if (*(int *)(param_1 + 0x150) != 0) {
    iVar7 = elite_issue_mcp_cmd(param_1,param_2,0x2e0000,0,local_res8,local_res18);
    if (iVar7 != 0) {
      return iVar7;
    }
    if (local_res8[0] == 0x800000) {
      *(undefined1 *)(param_1 + 0x148) = 1;
    }
  }
  *(undefined1 *)(param_1 + 0x149) = 0;
  return 0;
}



===== elite_mcp_read_vlan_setting @ 14000535c =====

undefined8 elite_mcp_read_vlan_setting(longlong param_1,byte *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe20bbc + uVar1 * 0x50);
  if (((uVar1 >> 0x10 & 1) == 0) || (0xffd < (uVar1 & 0xffff) - 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_mcp_set_capab @ 1400053bc =====

void elite_mcp_set_capab(longlong param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_res8 [4];
  uint local_res18 [4];
  
  uVar1 = *(uint *)(param_1 + 0x19c) & 1;
  uVar2 = uVar1 | 2;
  if ((*(uint *)(param_1 + 0x19c) & 2) == 0) {
    uVar2 = uVar1;
  }
  elite_issue_mcp_cmd(param_1,param_2,0x300000,uVar2,local_res18,local_res8);
  return;
}



===== elite_mcp_update_bw @ 140005400 =====

void elite_mcp_update_bw(longlong param_1,byte *param_2)

{
  undefined2 extraout_var;
  uint uVar1;
  uint uVar2;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  local_res8[0] = 0;
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x30);
  }
  elite_rd(param_1,param_2,(uVar1 >> 0xe & 0x3fffc) * uVar2 + ((uVar1 & 0xffff) + 0x38800a) * 4);
  *(char *)(param_1 + 0xb3) = (char)((ushort)extraout_var >> 8);
  *(char *)(param_1 + 0xb2) = (char)extraout_var;
  elite_issue_mcp_cmd(param_1,param_2,0x32000000,0,local_res8,local_res18);
  return;
}



===== elite_mcp_update_stag @ 1400054a8 =====

void elite_mcp_update_stag(longlong param_1,byte *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  local_res8[0] = 0;
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar3 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,
                   (uVar2 >> 0xe & 0x3fffc) * uVar3 + ((uVar2 & 0xffff) + 0x388012) * 4);
  *(undefined2 *)(param_1 + 0x14a) = uVar1;
  elite_issue_mcp_cmd(param_1,param_2,0x3b000000,0,local_res8,local_res18);
  return;
}



===== elite_set_link_mcp @ 140005544 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 elite_set_link_mcp(longlong param_1,byte *param_2,char param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStackY_78 [32];
  uint local_48;
  undefined4 local_44;
  uint local_40 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = 0;
  local_48 = 0;
  if (*(int *)(param_1 + 0x150) == 0) {
    uVar1 = 1;
  }
  else {
    mm_memset(local_40,0x20,0);
    if (*(char *)(param_1 + 0x1bc) == '\0') {
      local_40[0] = *(uint *)(param_1 + 0x1c4);
    }
    local_40[1] = local_40[1] |
                  -(uint)(*(char *)(param_1 + 0x1ca) != '\0') & 4 |
                  -(uint)(*(char *)(param_1 + 0x1c9) != '\0') & 2 |
                  (uint)(*(char *)(param_1 + 0x1c8) != '\0');
    local_40[2] = *(undefined4 *)(param_1 + 0x1c0);
    local_40[3] = *(undefined4 *)(param_1 + 0x1cc);
    do {
      elite_wr(param_1,param_2,*(int *)(param_1 + 0x154) + 0x18 + uVar2,
               local_40[(longlong)(int)uVar2 >> 2]);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x20);
    uVar1 = elite_issue_mcp_cmd(param_1,param_2,(-(uint)(param_3 != '\0') & 0xff000000) + 0x23000000
                                ,0,&local_48,&local_44);
  }
  return uVar1;
}



===== elite_wait_for_stable_link @ 140005664 =====

void elite_wait_for_stable_link(longlong param_1,byte *param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = *(int *)(param_1 + 0x1b4) * 1000;
  uVar6 = 0;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x280) != '\x01') {
    uVar8 = 0;
    if ((*(uint *)(param_1 + 0x19c) & 8) != 0) {
      do {
        uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x15c) + 8);
        uVar3 = uVar3 & 3;
        if (1 < uVar3) break;
        uVar5 = uVar6;
        if ((uVar8 != 1) && (uVar3 == 1)) {
          uVar5 = 0;
        }
        mm_delay(1000);
        uVar6 = uVar5 + 1;
        uVar8 = uVar3;
      } while (uVar5 < 3000);
      if (uVar3 == 3) {
        return;
      }
    }
    bVar1 = false;
    uVar6 = 0;
    if (uVar7 == 0) {
      uVar7 = 12000;
    }
    do {
      elite_mcp_link_handler(param_1,param_2,'\0');
      uVar8 = uVar6;
      bVar2 = bVar1;
      if (*(char *)(param_1 + 0x280) == '\x01') {
        if (bVar1) {
          if (4999 < iVar4 + 1U) {
            return;
          }
        }
        else {
          uVar8 = 0;
          bVar2 = true;
        }
        if (bVar1) {
          iVar4 = iVar4 + 1;
        }
      }
      else {
        iVar4 = 0;
      }
      bVar1 = bVar2;
      mm_delay(1000);
      uVar6 = uVar8 + 1;
    } while (uVar8 < uVar7);
  }
  return;
}



===== comp_and @ 140005780 =====

bool comp_and(uint param_1,uint param_2)

{
  return (param_1 & param_2) == param_2;
}



===== comp_eq @ 140005790 =====

bool comp_eq(int param_1,int param_2)

{
  return param_1 == param_2;
}



===== comp_or @ 1400057a0 =====

bool comp_or(int param_1,int param_2)

{
  return param_1 != 0 || param_2 != 0;
}



===== elite_gtt_init @ 1400057a8 =====

void elite_gtt_init(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  
  piVar3 = &DAT_140020020;
  uVar2 = 0;
  uVar1 = 0x200;
  do {
    if (*piVar3 != 0) {
      mm_pci_mem_write(param_1,0,uVar1,&DAT_140020020 + uVar2);
    }
    uVar2 = (ulonglong)((int)uVar2 + 1);
    uVar1 = uVar1 + 4;
    piVar3 = piVar3 + 1;
  } while (uVar1 < 0x24c);
  return;
}



===== elite_init_array_dmae @ 140005818 =====

undefined4
elite_init_array_dmae
          (longlong param_1,byte *param_2,uint param_3,ulonglong param_4,uint param_5,
          longlong param_6,char param_7,char param_8)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  uVar2 = (ulonglong)param_5;
  uVar1 = 0;
  if ((param_8 == '\0') || ((param_7 == '\0' && (param_5 < 0x10)))) {
    puVar3 = (undefined4 *)(param_6 + (param_4 & 0xffffffff) * 4);
    if (param_5 != 0) {
      do {
        elite_wr(param_1,param_2,param_3,*puVar3);
        param_3 = param_3 + 4;
        puVar3 = puVar3 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  }
  else {
    uVar1 = elite_dmae_host2grc(param_1,param_2,(void *)(param_6 + (param_4 & 0xffffffff) * 4),
                                param_3,param_5,0);
  }
  return uVar1;
}



===== elite_init_cmd_array @ 1400058cc =====

int elite_init_cmd_array(longlong param_1,byte *param_2,uint *param_3,char param_4,char param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_3[1];
  iVar3 = 0;
  uVar6 = *param_3 >> 7 & 0x1fffffc;
  uVar2 = *(uint *)(&DAT_1400109b0 + (ulonglong)uVar1 * 4);
  if ((uVar2 & 0xf) == 0) {
    iVar3 = elite_init_array_dmae
                      (param_1,param_2,uVar6,(ulonglong)(uVar1 + 1),uVar2 >> 4,0x1400109b0,param_4,
                       param_5);
  }
  else if ((uVar2 & 0xf) == 2) {
    uVar5 = 0;
    uVar4 = uVar2 >> 4 & 0xf;
    if (uVar2 >> 8 != 0) {
      do {
        iVar3 = elite_init_array_dmae
                          (param_1,param_2,uVar6,(ulonglong)(uVar1 + 1),uVar4,0x1400109b0,param_4,
                           param_5);
        if (iVar3 != 0) {
          return iVar3;
        }
        uVar6 = uVar6 + uVar4 * 4;
        uVar5 = uVar5 + 1;
        iVar3 = 0;
      } while (uVar5 < uVar2 >> 8);
    }
  }
  return iVar3;
}



===== elite_init_cmd_mode_match @ 1400059d0 =====

byte elite_init_cmd_mode_match(undefined8 param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (&DAT_14001ec10)[*param_2];
  *param_2 = *param_2 + 1;
  if (bVar2 == 0) {
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 ^ 1;
  }
  else if (bVar2 == 1) {
    bVar1 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 | bVar1;
  }
  else if (bVar2 == 2) {
    bVar1 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 & bVar1;
  }
  else {
    bVar2 = (param_3 >> (bVar2 - 3 & 0x1f) & 1) != 0;
  }
  return bVar2;
}



===== elite_init_cmd_rd @ 140005a7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void elite_init_cmd_rd(longlong param_1,byte *param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = *param_3;
  uVar5 = uVar3 >> 7 & 0x1fffffc;
  uVar2 = elite_rd(param_1,param_2,uVar5);
  uVar3 = uVar3 >> 4 & 0xf;
  if (uVar3 != 0) {
    if (uVar3 == 1) {
      pcVar4 = comp_eq;
    }
    else if (uVar3 == 2) {
      pcVar4 = comp_or;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      pcVar4 = comp_and;
    }
    uVar3 = param_3[1];
    iVar6 = 0;
    do {
      cVar1 = (*pcVar4)(uVar2,uVar3);
      if (cVar1 != '\0') {
        return;
      }
      mm_delay(500);
      uVar2 = elite_rd(param_1,param_2,uVar5);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 100);
  }
  return;
}



===== elite_init_cmd_wr @ 140005b34 =====

int elite_init_cmd_wr(longlong param_1,byte *param_2,uint *param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  byte bVar6;
  
  uVar1 = *param_3;
  iVar3 = 0;
  uVar5 = uVar1 >> 7 & 0x1fffffc;
  bVar6 = (byte)(uVar1 >> 8);
  if (((uVar1 & 0x100) != 0) && (param_4 == '\0')) {
    return 0;
  }
  uVar2 = uVar1 >> 4 & 7;
  if (uVar2 == 0) {
    elite_wr(param_1,param_2,uVar5,param_3[1]);
  }
  else if (uVar2 == 1) {
    uVar2 = param_3[1];
    uVar4 = (ulonglong)uVar2;
    if (((uVar1 & 0x100) == 0) && ((param_4 == '\0' || (uVar2 < 0x40)))) {
      if (uVar2 == 0) {
        return 0;
      }
      do {
        elite_wr(param_1,param_2,uVar5,0);
        uVar5 = uVar5 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      return 0;
    }
    mm_memset(&DAT_140020670,0x1000,0);
    iVar3 = elite_dmae_host2grc(param_1,param_2,&DAT_140020670,uVar5,uVar2,1);
  }
  else {
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        elite_init_rt(param_1,param_2,uVar5,*(ushort *)((longlong)param_3 + 6),(ushort)param_3[1],
                      bVar6 & 1);
        return 0;
      }
      return 0;
    }
    iVar3 = elite_init_cmd_array(param_1,param_2,param_3,bVar6 & 1,param_4);
  }
  return iVar3;
}



===== elite_init_rt @ 140005c60 =====

undefined8
elite_init_rt(longlong param_1,byte *param_2,int param_3,ushort param_4,ushort param_5,char param_6)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  longlong lVar8;
  
  uVar6 = 0;
  lVar8 = (ulonglong)param_4 * 4 + param_1;
  lVar1 = param_1 + 0x2a8 + (ulonglong)param_4 * 4;
  if (param_5 != 0) {
    do {
      uVar5 = (ulonglong)uVar6;
      if (*(int *)(lVar8 + 0x518 + uVar5 * 4) != 0) {
        uVar4 = (uint)uVar6;
        if (param_6 == '\0') {
          elite_wr(param_1,param_2,param_3 + uVar4 * 4,*(undefined4 *)(lVar1 + uVar5 * 4));
        }
        else {
          uVar2 = uVar4 + 1;
          uVar7 = 1;
          while ((uVar2 < param_5 && (*(int *)(lVar8 + 0x518 + (ulonglong)uVar2 * 4) != 0))) {
            uVar7 = uVar7 + 1;
            uVar2 = uVar7 + uVar4;
          }
          uVar3 = elite_dmae_host2grc(param_1,param_2,(void *)(uVar5 * 4 + lVar1),
                                      param_3 + uVar4 * 4,(uint)uVar7,0);
          if ((int)uVar3 != 0) {
            return uVar3;
          }
          uVar6 = uVar6 + uVar7;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_5);
  }
  return 0;
}



===== elite_init_run @ 140005d7c =====

int elite_init_run(longlong param_1,byte *param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  byte bVar5;
  uint *puVar6;
  ushort local_28 [8];
  
  iVar3 = 0;
  bVar5 = 0;
  uVar4 = 0;
  do {
    puVar6 = &DAT_14000d130 + uVar4 * 2;
    uVar2 = *puVar6 & 0xf;
    if (uVar2 == 0) {
      elite_init_cmd_rd(param_1,param_2,puVar6);
LAB_140005e71:
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    else {
      if (uVar2 == 1) {
        iVar3 = elite_init_cmd_wr(param_1,param_2,puVar6,bVar5);
        goto LAB_140005e71;
      }
      if (uVar2 == 2) {
        local_28[0] = *(ushort *)((longlong)&DAT_14000d134 + uVar4 * 8 + 2);
        bVar1 = elite_init_cmd_mode_match(param_1,local_28,param_5);
        if (bVar1 == 0) {
          uVar2 = (uint)*(ushort *)((longlong)puVar6 + 2);
        }
        else {
          uVar2 = 0;
        }
        uVar4 = (ulonglong)((int)uVar4 + uVar2);
      }
      else if (uVar2 == 3) {
        if ((((&DAT_14000d134)[uVar4 * 2] & 0xff) == param_3) &&
           ((uVar2 = (uint)(&DAT_14000d134)[uVar4 * 2] >> 0x10, uVar2 == 0xffff ||
            (uVar2 == param_4)))) {
          uVar2 = 0;
        }
        else {
          uVar2 = (uint)*(ushort *)((longlong)&DAT_14000d130 + uVar4 * 8 + 2);
        }
        uVar4 = (ulonglong)((int)uVar4 + uVar2);
        bVar5 = (byte)(*puVar6 >> 4) & 1;
      }
      else if (uVar2 == 4) {
        mm_delay((&DAT_14000d134)[uVar4 * 2]);
      }
    }
    uVar2 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar2;
    if (0x70e < uVar2) {
      return iVar3;
    }
  } while( true );
}



===== elite_init_store_rt_agg @ 140005ea4 =====

void elite_init_store_rt_agg(longlong param_1,ulonglong param_2,longlong param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  
  uVar3 = param_4 >> 2;
  if (uVar3 != 0) {
    lVar1 = (param_2 & 0xffffffff) * 4 + 0x518;
    puVar2 = (undefined4 *)(lVar1 + param_1);
    do {
      puVar2[-0x9c] = *(undefined4 *)(((param_3 - lVar1) - param_1) + (longlong)puVar2);
      *puVar2 = 1;
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== elite_init_store_rt_reg @ 140005edc =====

void elite_init_store_rt_reg(longlong param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x2a8 + (ulonglong)param_2 * 4) = param_3;
  *(undefined4 *)(param_1 + 0x518 + (ulonglong)param_2 * 4) = 1;
  return;
}



===== elite_dma_info_alloc @ 140005ef4 =====

undefined8 elite_dma_info_alloc(longlong param_1)

{
  mm_dma_alloc(param_1,(longlong *)(param_1 + 0x250),(longlong *)(param_1 + 0x248),8);
  if (((*(longlong *)(param_1 + 0x250) == 0) ||
      (mm_dma_alloc(param_1,(longlong *)(param_1 + 0x270),(longlong *)(param_1 + 0x268),0x38),
      *(longlong *)(param_1 + 0x270) == 0)) ||
     (mm_dma_alloc(param_1,(longlong *)(param_1 + 0x260),(longlong *)(param_1 + 600),0x1000),
     *(longlong *)(param_1 + 0x260) == 0)) {
    return 1;
  }
  *(undefined1 *)(param_1 + 0x240) = *(undefined1 *)(param_1 + 0x30);
  return 0;
}



===== elite_dmae_execute_command @ 140005fa0 =====

ulonglong elite_dmae_execute_command
                    (longlong param_1,byte *param_2,void *param_3,int param_4,char param_5,
                    char param_6,uint param_7,uint *param_8)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  void *pvVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  puVar1 = *(uint **)(param_1 + 0x270);
  uVar8 = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x248);
  *puVar1 = 0;
  *(undefined2 *)((longlong)puVar1 + 0x16) = 0;
  uVar10 = 0;
  *puVar1 = *puVar1 | (uint)(param_5 == '\x02');
  uVar6 = 2;
  if (param_6 == '\x02') {
    uVar6 = 4;
  }
  uVar6 = (*(uint *)(param_1 + 0x30) & 0xf) << 0x14 | uVar6 | *puVar1;
  *puVar1 = uVar6;
  uVar6 = (*(uint *)(param_1 + 0x30) & 0xf) << 0x18 | uVar6;
  uVar9 = uVar6 | 0x120;
  *puVar1 = uVar9;
  if ((*param_8 & 8) != 0) {
    uVar9 = uVar6 | 0x1a0;
  }
  *puVar1 = uVar9 | 0x8000;
  uVar6 = *(int *)(param_1 + 0x34) << 0x12 | uVar9 | 0x8000;
  *puVar1 = uVar6 | 0x40;
  if ((*param_8 & 2) == 0) {
    uVar3 = 0xff;
  }
  else {
    *puVar1 = uVar6 | 0x10000040;
    uVar3 = (ushort)(byte)param_8[1];
  }
  *(ushort *)((longlong)puVar1 + 0x16) = *(ushort *)((longlong)puVar1 + 0x16) | uVar3;
  if ((*param_8 & 4) == 0) {
    *(ushort *)((longlong)puVar1 + 0x16) = *(ushort *)((longlong)puVar1 + 0x16) | 0xff00;
  }
  else {
    *puVar1 = *puVar1 | 0x20000000;
    *(ushort *)((longlong)puVar1 + 0x16) =
         *(ushort *)((longlong)puVar1 + 0x16) | (ushort)*(byte *)((longlong)param_8 + 5) << 8;
  }
  puVar1[6] = (uint)uVar2;
  puVar1[7] = (uint)((ulonglong)uVar2 >> 0x20);
  puVar1[8] = 0xd1ae;
  uVar6 = 0;
  pvVar7 = param_3;
  do {
    uVar9 = uVar6 << 10;
    if ((*param_8 & 1) == 0) {
      if (param_5 != '\x02') {
        uVar9 = uVar6 << 0xc;
      }
      pvVar7 = (void *)((ulonglong)uVar9 + (longlong)param_3);
    }
    iVar4 = 0x1000;
    if (param_6 == '\x02') {
      iVar4 = 0x400;
    }
    uVar3 = 0x400;
    if (param_7 >> 10 == uVar6) {
      uVar3 = (ushort)param_7 & 0x3ff;
    }
    if (uVar3 != 0) {
      uVar5 = elite_dmae_execute_sub_operation
                        (param_1,param_2,pvVar7,(void *)(ulonglong)(param_4 + iVar4 * uVar6),param_5
                         ,param_6,(uint)uVar3);
      uVar10 = uVar5 & 0xffffffff;
      if ((int)uVar5 != 0) {
        return uVar10;
      }
    }
    uVar8 = uVar8 + 1;
    uVar6 = (uint)uVar8;
  } while (uVar6 <= param_7 >> 10);
  return uVar10;
}



===== elite_dmae_execute_sub_operation @ 140006198 =====

undefined8
elite_dmae_execute_sub_operation
          (longlong param_1,byte *param_2,void *param_3,void *param_4,char param_5,char param_6,
          uint param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  pvVar4 = *(void **)(param_1 + 600);
  lVar1 = *(longlong *)(param_1 + 0x270);
  uVar3 = SUB84(pvVar4,0);
  if (param_5 == '\0') {
    *(undefined4 *)(lVar1 + 4) = uVar3;
    *(int *)(lVar1 + 8) = (int)((ulonglong)pvVar4 >> 0x20);
    mm_memcpy(*(void **)(param_1 + 0x260),param_3,(ulonglong)param_7 << 2);
LAB_140006221:
    if (param_6 != '\0') {
      if (1 < (byte)(param_6 - 1U)) goto LAB_140006299;
      uVar3 = SUB84(param_4,0);
      pvVar4 = param_4;
    }
    *(int *)(lVar1 + 0x10) = (int)((ulonglong)pvVar4 >> 0x20);
    *(undefined4 *)(lVar1 + 0xc) = uVar3;
    *(short *)(lVar1 + 0x14) = (short)param_7;
    elite_dmae_post_command(param_1,param_2);
    uVar2 = elite_dmae_operation_wait(param_1);
    if ((int)uVar2 == 0) {
      if (param_6 == '\0') {
        mm_memcpy(param_4,*(void **)(param_1 + 0x260),(ulonglong)param_7 << 2);
      }
      uVar2 = 0;
    }
  }
  else {
    if ((byte)(param_5 - 1U) < 2) {
      *(void **)(lVar1 + 4) = param_3;
      goto LAB_140006221;
    }
LAB_140006299:
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_dmae_host2grc @ 1400062a0 =====

void elite_dmae_host2grc(longlong param_1,byte *param_2,void *param_3,uint param_4,uint param_5,
                        uint param_6)

{
  uint local_18 [4];
  
  mm_memset(local_18,8,0);
  local_18[0] = param_6;
  elite_dmae_execute_command(param_1,param_2,param_3,param_4 >> 2,'\0','\x02',param_5,local_18);
  return;
}



===== elite_dmae_operation_wait @ 140006324 =====

undefined8 elite_dmae_operation_wait(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x250);
  uVar2 = 0;
  while( true ) {
    if (*piVar1 == 0xd1ae) {
      *piVar1 = 0;
      return 0;
    }
    mm_delay(2);
    uVar2 = uVar2 + 1;
    if (10000 < uVar2) break;
    piVar1 = *(int **)(param_1 + 0x250);
  }
  return 1;
}



===== elite_dmae_post_command @ 140006384 =====

undefined8 elite_dmae_post_command(longlong param_1,byte *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0x270);
  bVar1 = *(byte *)(param_1 + 0x240);
  if (((puVar3[3] == 0) && (puVar3[4] == 0)) || ((puVar3[1] == 0 && (puVar3[2] == 0)))) {
    uVar2 = 1;
  }
  else {
    bVar4 = 0;
    do {
      if (bVar4 < 9) {
        uVar5 = *puVar3;
      }
      else {
        uVar5 = 0;
      }
      elite_wr(param_1,param_2,((uint)bVar4 + (uint)bVar1 * 0xe) * 4 + 0xc800,uVar5);
      bVar4 = bVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (bVar4 < 0xe);
    elite_wr(param_1,param_2,(uint)bVar1 * 4 + 0xc048,1);
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_alloc_status_block @ 140006444 =====

undefined8 elite_alloc_status_block(longlong param_1)

{
  undefined8 uVar1;
  longlong local_res8;
  longlong local_res10 [3];
  
  local_res8 = 0;
  uVar1 = mm_dma_alloc(param_1,&local_res8,local_res10,0x20);
  if ((int)uVar1 == 0) {
    *(longlong *)(param_1 + 0xaa8) = local_res8;
    *(longlong *)(param_1 + 0xab0) = local_res10[0];
    uVar1 = 0;
  }
  return uVar1;
}



===== elite_cfc_delete @ 14000648c =====

void elite_cfc_delete(longlong param_1,undefined2 param_2)

{
  undefined4 local_res8 [2];
  undefined4 local_res10;
  uint local_28;
  undefined1 local_24;
  undefined4 *local_20;
  undefined4 local_18;
  
  mm_memset(local_res8,8,0);
  local_20 = local_res8;
  local_res10 = CONCAT22(*(undefined2 *)(param_1 + 0x24),param_2);
  local_18 = local_res10;
  local_res8[0] = local_res10;
  local_24 = 6;
  local_28 = 8;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_config_cau_sb @ 1400064f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 elite_config_cau_sb(longlong param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  uint local_44;
  undefined4 local_40 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  pbVar1 = (byte *)(param_1 + 0x284);
  mm_memset(&local_48,8,0);
  local_44 = *(int *)(param_1 + 0x30) << 0x1b | local_44 & 0x8003ffff;
  iVar2 = (uint)*(ushort *)(param_1 + 0xabc) * 8;
  elite_wr(param_1,pbVar1,iVar2 + 0x1c8000,*(undefined4 *)(param_1 + 0xab0));
  elite_wr(param_1,pbVar1,iVar2 + 0x1c8004,
           (int)((ulonglong)*(undefined8 *)(param_1 + 0xab0) >> 0x20));
  iVar2 = (uint)*(ushort *)(param_1 + 0xabc) * 8;
  elite_wr(param_1,pbVar1,iVar2 + 0x1c6000,local_48);
  elite_wr(param_1,pbVar1,iVar2 + 0x1c6004,local_44);
  mm_memset(local_40,0x30,0);
  bVar3 = 0;
  puVar4 = local_40;
  do {
    elite_wr(param_1,pbVar1,((uint)bVar3 + (uint)*(ushort *)(param_1 + 0xabc) * 0xc) * 4 + 0x1d0000,
             *puVar4);
    bVar3 = bVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (bVar3 < 0xc);
  return 0;
}



===== elite_config_sb @ 140006634 =====

undefined8 elite_config_sb(longlong param_1)

{
  *(ushort *)(param_1 + 0xabc) = *(ushort *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0xac0) = (uint)*(ushort *)(param_1 + 0x4c) * 8 + 0xf000;
  mm_memset(*(void **)(param_1 + 0xaa8),0x20,0);
  elite_config_cau_sb(param_1);
  return 0;
}



===== elite_has_rx_work @ 14000667c =====

undefined8 elite_has_rx_work(longlong param_1)

{
  return CONCAT71((int7)((ulonglong)*(short **)(param_1 + 0x7f8) >> 8),
                  **(short **)(param_1 + 0x7f8) != *(short *)(param_1 + 0x7ee));
}



===== elite_has_tx_work @ 140006694 =====

undefined8 elite_has_tx_work(longlong param_1)

{
  return CONCAT71((int7)((ulonglong)*(short **)(param_1 + 0x960) >> 8),
                  **(short **)(param_1 + 0x960) != *(short *)(param_1 + 0x956));
}



===== elite_process_rx_pkt @ 1400066ac =====

short elite_process_rx_pkt(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  
  sVar7 = 0;
  sVar1 = **(short **)(param_1 + 0x7f8);
  sVar6 = *(short *)(param_1 + 0x7ee);
  while ((sVar1 != sVar6 && (*(int *)(param_1 + 0x800) != 0))) {
    iVar4 = *(int *)(param_1 + 0x8d8);
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0x8e0);
    }
    *(int *)(param_1 + 0x8e4) = *(int *)(param_1 + 0x8e4) + -1;
    uVar5 = iVar4 - 1;
    *(uint *)(param_1 + 0x8d8) = uVar5;
    lVar2 = *(longlong *)(param_1 + 0x8e8 + (ulonglong)uVar5 * 8);
    *(undefined8 *)(param_1 + 0x8e8 + (ulonglong)uVar5 * 8) = 0;
    if (lVar2 == 0) break;
    *(int *)(param_1 + 0x800) = *(int *)(param_1 + 0x800) + -1;
    pcVar3 = *(char **)(lVar2 + 0x18);
    if (*pcVar3 == '\x01') {
      *(char *)(lVar2 + 0x10) = pcVar3[1];
      *(undefined2 *)(lVar2 + 0xe) = *(undefined2 *)(pcVar3 + 2);
      iVar4 = *(int *)(param_1 + 0x90c);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x910);
      }
      *(longlong *)(param_1 + 0x918 + (ulonglong)(iVar4 - 1U) * 8) = lVar2;
      *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + 1;
      *(uint *)(param_1 + 0x90c) = iVar4 - 1U;
    }
    sVar6 = sVar6 + 1;
    sVar7 = sVar7 + 1;
  }
  *(short *)(param_1 + 0x7ee) = sVar6;
  return sVar7;
}



===== elite_process_tx_completions @ 140006790 =====

short elite_process_tx_completions(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  short sVar6;
  
  sVar6 = 0;
  sVar1 = **(short **)(param_1 + 0x960);
  sVar5 = *(short *)(param_1 + 0x956);
  while (sVar5 != sVar1) {
    iVar3 = *(int *)(param_1 + 0xa40);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xa48);
    }
    *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + -1;
    uVar4 = iVar3 - 1;
    *(uint *)(param_1 + 0xa40) = uVar4;
    lVar2 = *(longlong *)(param_1 + 0xa50 + (ulonglong)uVar4 * 8);
    *(undefined8 *)(param_1 + 0xa50 + (ulonglong)uVar4 * 8) = 0;
    if (lVar2 == 0) break;
    *(int *)(param_1 + 0x968) = *(int *)(param_1 + 0x968) + 1;
    sVar5 = sVar5 + 1;
    iVar3 = *(int *)(param_1 + 0xa74);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xa78);
    }
    sVar6 = sVar6 + 1;
    *(longlong *)(param_1 + 0xa80 + (ulonglong)(iVar3 - 1U) * 8) = lVar2;
    *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + 1;
    *(uint *)(param_1 + 0xa74) = iVar3 - 1U;
  }
  *(short *)(param_1 + 0x956) = sVar5;
  return sVar6;
}



===== elite_replenish_bd_chain @ 140006840 =====

short elite_replenish_bd_chain(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  short sVar7;
  
  uVar6 = *(ushort *)((longlong)param_1 + 0x14);
  sVar7 = 0;
  do {
    iVar4 = (int)param_1[0x1a];
    if (iVar4 == *(int *)((longlong)param_1 + 0xd4)) {
      iVar3 = iVar4;
      if (iVar4 == 0) {
        iVar3 = (int)param_1[0x1b];
      }
      if (param_1[(ulonglong)(iVar3 - 1) + 0x1c] == 0) {
LAB_140006911:
        *(ushort *)((longlong)param_1 + 0x14) = uVar6;
        return sVar7;
      }
    }
    lVar1 = *param_1;
    if (iVar4 == 0) {
      iVar4 = (int)param_1[0x1b];
    }
    *(int *)((longlong)param_1 + 0xdc) = *(int *)((longlong)param_1 + 0xdc) + -1;
    uVar5 = iVar4 - 1;
    *(uint *)(param_1 + 0x1a) = uVar5;
    lVar2 = param_1[(ulonglong)uVar5 + 0x1c];
    param_1[(ulonglong)uVar5 + 0x1c] = 0;
    if (lVar2 == 0) goto LAB_140006911;
    *(undefined4 *)(lVar1 + (ulonglong)(uVar6 & 3) * 8) = *(undefined4 *)(lVar2 + 0x20);
    *(int *)(lVar1 + 4 + (ulonglong)(uVar6 & 3) * 8) =
         (int)((ulonglong)*(undefined8 *)(lVar2 + 0x20) >> 0x20);
    iVar4 = *(int *)((longlong)param_1 + 0x104);
    if (iVar4 == 0) {
      iVar4 = (int)param_1[0x21];
    }
    uVar6 = uVar6 + 1;
    param_1[(ulonglong)(iVar4 - 1U) + 0x22] = lVar2;
    *(int *)((longlong)param_1 + 0x10c) = *(int *)((longlong)param_1 + 0x10c) + 1;
    *(uint *)((longlong)param_1 + 0x104) = iVar4 - 1U;
    *(int *)(param_1 + 5) = (int)param_1[5] + 1;
    sVar7 = sVar7 + 1;
  } while( true );
}



===== elite_rx_start @ 140006928 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool elite_rx_start(longlong param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_a8 [32];
  byte local_88 [2];
  undefined2 local_86;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_40;
  undefined1 local_3e;
  undefined2 local_3d;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_36;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  pvVar1 = *(void **)(param_1 + 0x210);
  mm_memset(pvVar1,0x270,0);
  *(undefined2 *)((longlong)pvVar1 + 0x1e2) = 4;
  mm_memset(local_88,4,0);
  mm_memset(&local_68,0x40,0);
  local_60 = *(undefined4 *)(param_1 + 0x7e0);
  local_5c = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x7e0) >> 0x20);
  local_64 = 0x5ea;
  local_62 = *(undefined2 *)(param_1 + 0xabc);
  local_68 = 0x40004;
  local_3d = 0x101;
  local_40 = 4;
  local_3b = 0;
  uVar2 = elite_mcp_read_boot_protocol(param_1,(byte *)(param_1 + 0x284));
  if (uVar2 == 0) {
    uVar4 = elite_mcp_read_vlan_setting(param_1,(byte *)(param_1 + 0x284));
    if ((int)uVar4 != 0) goto LAB_140006aed;
  }
  else if (uVar2 == 3) {
LAB_140006aed:
    local_3a = 1;
    goto LAB_140006a03;
  }
  local_3a = 0;
LAB_140006a03:
  local_39 = *(undefined1 *)(param_1 + 0x27c);
  *(undefined1 *)(param_1 + 0x131) = local_3e;
  local_78 = &local_68;
  local_84 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  *(undefined4 *)(param_1 + 0x7e8) = local_84;
  local_70 = local_84;
  local_36 = 1;
  local_7c = 1;
  local_80 = 0x40;
  iVar3 = elite_sp_post(param_1,&local_80);
  local_86 = 4;
  local_88[0] = local_88[0] & 0x30 | 0x46;
  mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0x9c),(undefined4 *)local_88);
  *(undefined2 *)(param_1 + 0x12e) = 0xffff;
  *(longlong *)(param_1 + 0x7f8) = *(longlong *)(param_1 + 0xaa8) + 2;
  *(undefined2 *)(param_1 + 0x7ec) = 4;
  *(undefined2 *)(param_1 + 0xba) = 0x808;
  *(undefined2 *)(param_1 + 0xf4) = 0x808;
  return iVar3 != 0;
}



===== elite_rx_stop @ 140006af8 =====

void elite_rx_stop(longlong param_1)

{
  undefined4 local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  undefined4 local_18;
  
  local_20 = 0;
  local_28 = 0;
  local_res8 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  local_18 = local_res8;
  local_24 = 3;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_send_packet @ 140006b38 =====

undefined4 elite_send_packet(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 uVar7;
  short sVar8;
  undefined2 local_res8;
  short sStackX_a;
  
  uVar7 = 0;
  if (*(int *)(param_1 + 0x968) == 0) {
    uVar7 = 2;
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x954);
    puVar5 = (undefined4 *)((ulonglong)(uVar2 & 3) * 0x10 + *(longlong *)(param_1 + 0x940));
    if (puVar5 == (undefined4 *)0x0) {
      uVar7 = 2;
    }
    else {
      bVar1 = *(byte *)((longlong)puVar5 + 0xd);
      bVar6 = bVar1 | 4;
      *(undefined1 *)(puVar5 + 3) = 1;
      *(byte *)((longlong)puVar5 + 0xd) = bVar6;
      if ((*(byte *)(param_1 + 0x131) & 0x20) != 0) {
        bVar6 = bVar1 | 5;
        *(byte *)((longlong)puVar5 + 0xd) = bVar6;
      }
      if (*(int *)(param_2 + 4) == 1) {
        *(byte *)((longlong)puVar5 + 0xd) = bVar6 & 0xfd | 2;
        uVar3 = *(undefined2 *)(param_2 + 8);
      }
      else {
        *(byte *)((longlong)puVar5 + 0xd) = bVar6 & 0xfd;
        uVar3 = 0;
      }
      *(undefined2 *)((longlong)puVar5 + 10) = uVar3;
      sVar8 = uVar2 + 1;
      *(byte *)((longlong)puVar5 + 0xd) = *(byte *)((longlong)puVar5 + 0xd) & 0x47;
      *(undefined2 *)((longlong)puVar5 + 0xe) = 0;
      *puVar5 = *(undefined4 *)(param_2 + 0x18);
      puVar5[1] = (int)((ulonglong)*(undefined8 *)(param_2 + 0x18) >> 0x20);
      *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(param_2 + 0x22);
      *(int *)(param_1 + 0x968) = *(int *)(param_1 + 0x968) + -1;
      iVar4 = *(int *)(param_1 + 0xa44);
      _local_res8 = CONCAT22(sVar8,0x1084);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0xa48);
      }
      *(longlong *)(param_1 + 0xa50 + (ulonglong)(iVar4 - 1U) * 8) = param_2;
      *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + 1;
      *(uint *)(param_1 + 0xa44) = iVar4 - 1U;
      *(short *)(param_1 + 0x954) = sVar8;
      mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0xa0),(undefined4 *)&local_res8);
    }
  }
  return uVar7;
}



===== elite_setup_rx_chain @ 140006c58 =====

undefined8 elite_setup_rx_chain(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong local_res8;
  longlong local_res10;
  
  plVar1 = (longlong *)(param_1 + 0x7d8);
  *(undefined8 *)(param_1 + 0x8b0) = 4;
  lVar6 = param_1 + 0x808;
  *(undefined8 *)(param_1 + 0x8a8) = 0;
  mm_memset((void *)(param_1 + 0x8b8),0x20,0);
  *(undefined8 *)(param_1 + 0x8d8) = 0;
  *(undefined8 *)(param_1 + 0x8e0) = 4;
  mm_memset((void *)(param_1 + 0x8e8),0x20,0);
  *(undefined8 *)(param_1 + 0x908) = 0;
  *(undefined8 *)(param_1 + 0x910) = 4;
  mm_memset((void *)(param_1 + 0x918),0x20,0);
  uVar3 = mm_dma_alloc(param_1,plVar1,(longlong *)(param_1 + 0x7e0),0x20);
  if ((int)uVar3 == 0) {
    uVar5 = 0;
    *(longlong *)(param_1 + 0x7f0) = *plVar1;
    lVar7 = 0;
    *(undefined4 *)(param_1 + 0x7ec) = 0;
    *(undefined4 *)(param_1 + 0x800) = 4;
    do {
      uVar3 = mm_dma_alloc(param_1,&local_res10,&local_res8,0x620);
      if ((int)uVar3 != 0) goto LAB_140006d94;
      *(longlong *)(lVar6 + 0x18) = local_res10;
      *(longlong *)(lVar6 + 0x20) = local_res8;
      iVar4 = *(int *)(param_1 + 0x8dc);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x8e0);
      }
      uVar5 = uVar5 + 1;
      *(longlong *)(param_1 + 0x8e8 + (ulonglong)(iVar4 - 1U) * 8) = lVar6;
      lVar6 = lVar6 + 0x28;
      *(int *)(param_1 + 0x8e4) = *(int *)(param_1 + 0x8e4) + 1;
      *(uint *)(param_1 + 0x8dc) = iVar4 - 1U;
      lVar2 = *plVar1;
      *(int *)(lVar7 + lVar2) = (int)local_res8;
      *(int *)(lVar7 + 4 + lVar2) = (int)((ulonglong)local_res8 >> 0x20);
      lVar7 = lVar7 + 8;
    } while (uVar5 < 4);
    uVar3 = 0;
  }
  else {
LAB_140006d94:
    uVar3 = 2;
  }
  return uVar3;
}



===== elite_setup_tx_chain @ 140006dac =====

undefined8 elite_setup_tx_chain(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong local_res8;
  longlong local_res10;
  
  *(undefined8 *)(param_1 + 0xa18) = 4;
  lVar4 = param_1 + 0x970;
  *(undefined8 *)(param_1 + 0xa10) = 0;
  mm_memset((void *)(param_1 + 0xa20),0x20,0);
  *(undefined8 *)(param_1 + 0xa40) = 0;
  *(undefined8 *)(param_1 + 0xa48) = 4;
  mm_memset((void *)(param_1 + 0xa50),0x20,0);
  *(undefined8 *)(param_1 + 0xa70) = 0;
  *(undefined8 *)(param_1 + 0xa78) = 4;
  mm_memset((void *)(param_1 + 0xa80),0x20,0);
  uVar1 = mm_dma_alloc(param_1,(longlong *)(param_1 + 0x940),(longlong *)(param_1 + 0x948),0x40);
  if ((int)uVar1 == 0) {
    uVar3 = 0;
    *(longlong *)(param_1 + 0x958) = *(longlong *)(param_1 + 0x940);
    *(undefined4 *)(param_1 + 0x954) = 0;
    *(undefined4 *)(param_1 + 0x968) = 4;
    do {
      uVar1 = mm_dma_alloc(param_1,&local_res8,&local_res10,0x600);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      *(longlong *)(lVar4 + 0x10) = local_res8;
      *(longlong *)(lVar4 + 0x18) = local_res10;
      *(undefined2 *)(lVar4 + 0x20) = 0x600;
      iVar2 = *(int *)(param_1 + 0xa14);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0xa18);
      }
      uVar3 = uVar3 + 1;
      *(longlong *)(param_1 + 0xa20 + (ulonglong)(iVar2 - 1U) * 8) = lVar4;
      lVar4 = lVar4 + 0x28;
      *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + 1;
      *(uint *)(param_1 + 0xa14) = iVar2 - 1U;
    } while (uVar3 < 4);
    uVar1 = 0;
  }
  return uVar1;
}



===== elite_tx_start @ 140006ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int elite_tx_start(longlong param_1)

{
  int iVar1;
  undefined1 auStack_88 [32];
  int local_68;
  uint local_60;
  undefined1 local_5c;
  undefined4 *local_58;
  int local_50;
  undefined4 local_48;
  undefined2 local_44;
  short local_42;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_20;
  undefined2 local_1e;
  char local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  mm_memset(*(void **)(param_1 + 0x1f8),0x270,0);
  mm_memset(&local_48,0x38,0);
  local_40 = *(undefined4 *)(param_1 + 0x948);
  local_3c = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x948) >> 0x20);
  local_44 = 0x5ea;
  local_20 = *(undefined2 *)(param_1 + 0xabc);
  local_1c = *(char *)(param_1 + 0x27c);
  local_48 = 0x40004;
  local_1e = 0x100;
  if ((local_1c != '\x01') || (local_42 = *(short *)(param_1 + 0x14a), local_42 == -1)) {
    local_42 = 0;
  }
  local_58 = &local_48;
  local_68 = (uint)*(ushort *)(param_1 + 0x24) << 0x10;
  local_50 = local_68;
  *(int *)(param_1 + 0x950) = local_68;
  local_5c = 2;
  local_60 = 0x38;
  iVar1 = elite_sp_post(param_1,&local_60);
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x960) = *(undefined8 *)(param_1 + 0xaa8);
    iVar1 = 0;
  }
  return iVar1;
}



===== elite_tx_stop @ 140006ff8 =====

void elite_tx_stop(longlong param_1)

{
  int local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  int local_18;
  
  local_24 = 4;
  local_20 = 0;
  local_28 = 0;
  local_res8 = (uint)*(ushort *)(param_1 + 0x24) << 0x10;
  local_18 = local_res8;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_intr_disable_igu @ 140007034 =====

void elite_intr_disable_igu(longlong param_1)

{
  *(undefined1 *)(param_1 + 0xac9) = 0;
  elite_wr(param_1,(byte *)(param_1 + 0x284),0x180800,0);
  return;
}



===== elite_intr_enable_igu @ 140007050 =====

void elite_intr_enable_igu(longlong param_1)

{
  *(undefined1 *)(param_1 + 0xac9) = 1;
  elite_wr(param_1,(byte *)(param_1 + 0x284),0x180800,0x1d);
  return;
}



===== elite_intr_enable_rt @ 140007070 =====

void elite_intr_enable_rt(longlong param_1)

{
  elite_init_store_rt_reg(param_1,8,1);
  return;
}



===== evcd_alloc_sess_exchg_entry @ 140007080 =====

undefined1 * evcd_alloc_sess_exchg_entry(longlong param_1,undefined2 param_2,undefined2 param_3)

{
  char *pcVar1;
  undefined1 *puVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = 0;
  lVar3 = 0;
  pcVar1 = (char *)(param_1 + 0x59);
  do {
    if (*pcVar1 == '\0') {
      lVar3 = (longlong)iVar4 * 0x1d;
      puVar2 = (undefined1 *)(param_1 + 0x59 + lVar3);
      *(undefined2 *)(lVar3 + 0x5a + param_1) = param_3;
      *puVar2 = 1;
      *(undefined2 *)(lVar3 + 0x5c + param_1) = param_2;
      *(undefined8 *)(lVar3 + 0x60 + param_1) = 0;
      *(undefined8 *)(lVar3 + 0x6a + param_1) = 0;
      *(undefined4 *)(lVar3 + 0x72 + param_1) = 0;
      return puVar2;
    }
    iVar4 = iVar4 + 1;
    lVar3 = lVar3 + 1;
    pcVar1 = pcVar1 + 0x1d;
  } while (lVar3 < 8);
  return (undefined1 *)0x0;
}



===== evcd_disconnect_session @ 1400070d8 =====

void evcd_disconnect_session(undefined2 *param_1)

{
  undefined1 *puVar1;
  longlong lVar2;
  
  puVar1 = (undefined1 *)((longlong)param_1 + 0x59);
  *(undefined1 *)((longlong)param_1 + 0x179) = 0;
  *(undefined1 *)(param_1 + 0xc5) = 0;
  *(undefined2 *)((longlong)param_1 + 0x29) = 0;
  lVar2 = 8;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x1d;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *param_1 = 0;
  *(undefined2 *)((longlong)param_1 + 0x27) = 0;
  return;
}



===== evcd_free_sess_xchg_entry @ 140007110 =====

void evcd_free_sess_xchg_entry(undefined1 *param_1)

{
  *param_1 = 0;
  return;
}



===== evcd_get_sess_xchg_entry @ 140007114 =====

longlong evcd_get_sess_xchg_entry(longlong param_1,short param_2)

{
  short *psVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = 0;
  psVar1 = (short *)(param_1 + 0x5c);
  lVar3 = 0;
  while ((*(char *)((longlong)psVar1 + -3) == '\0' || (param_2 != *psVar1))) {
    iVar2 = iVar2 + 1;
    lVar3 = lVar3 + 1;
    psVar1 = (short *)((longlong)psVar1 + 0x1d);
    if (7 < lVar3) {
      return 0;
    }
  }
  return param_1 + 0x59 + (longlong)iVar2 * 0x1d;
}



===== evcd_init_session_params @ 140007150 =====

void evcd_init_session_params(longlong param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  
  mm_memset((void *)(param_1 + 0xc10),0x19e,0);
  mm_memcpy((void *)(param_1 + 0xc21),(void *)(param_1 + 0x15b2),6);
  *(undefined1 *)(param_1 + 0xc18) = 1;
  *(undefined2 *)(param_1 + 0xc12) = 0;
  *(undefined2 *)(param_1 + 0xc19) = 0x42e;
  *(undefined2 *)(param_1 + 0xd87) = 0x400;
  *(undefined1 *)(param_1 + 0xd51) = 3;
  lVar1 = 8;
  puVar2 = (undefined1 *)(param_1 + 0xc69);
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 0x1d;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  return;
}



===== evcd_process_adisc @ 1400071d0 =====

void evcd_process_adisc(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  if ((*(byte *)(param_1 + 0xc10) & 0x10) != 0) {
    *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x23;
    *(undefined4 *)((longlong)puVar1 + 0x24) = 0x9801;
    *(undefined2 *)((longlong)puVar1 + 0x2c) = *(undefined2 *)(param_2 + 0x10);
    *(undefined2 *)((longlong)puVar1 + 0x2e) = *(undefined2 *)(param_1 + 0xc12);
    mm_memcpy((void *)((longlong)puVar1 + 0x1d),(void *)(param_2 + 5),3);
    *(undefined1 *)((longlong)puVar1 + 0x34) = 2;
    mm_memcpy((void *)((longlong)puVar1 + 0x3c),(void *)(param_1 + 0xc2f),8);
    mm_memcpy((void *)((longlong)puVar1 + 0x44),(void *)(param_1 + 0xc27),8);
    mm_memcpy((void *)((longlong)puVar1 + 0x4d),(void *)(param_1 + 0xc14),3);
    evcd_tx_fcoe_frame(param_1,puVar1,0x1c,0,(undefined2 *)0x0,4);
  }
  return;
}



===== evcd_process_fc_pkt @ 1400072a0 =====

void evcd_process_fc_pkt(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  if (*(char *)(param_2 + 8) != '\x01') {
    return;
  }
  bVar1 = *(byte *)(param_2 + 0x18);
  uVar3 = (uint)bVar1;
  if ((uVar3 == 3) || (uVar3 == 5)) {
    if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
      pcVar5 = "PLOGI";
      if (bVar1 == 5) {
        pcVar5 = "LOGO";
      }
      mm_printk("Received FC frame for %s \n",pcVar5,0,param_4);
    }
    uVar3 = *(uint *)(param_2 + 5);
    uVar7 = 0xff00;
    if (0xfff00000 < ((uVar3 << 0x10 | uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00))
    goto LAB_14000744f;
    if (*(char *)(param_2 + 0x18) != '\x05') goto LAB_140007319;
    uVar2 = 0xff3f;
LAB_140007448:
    *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) & uVar2;
LAB_14000744f:
    evcd_send_acc_rsp(param_1,param_2,uVar7,param_4);
    return;
  }
  if (uVar3 == 0xf) {
    if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
      mm_printk(&s_Received_RLS_,uVar4,0,param_4);
    }
    evcd_process_rls(param_1,param_2);
    return;
  }
  uVar7 = (ulonglong)(uVar3 - 0x20);
  if (uVar3 - 0x20 != 0) {
    uVar7 = (ulonglong)(uVar3 - 0x21);
    if (uVar3 - 0x21 == 0) {
      if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
        mm_printk("Received FC frame for PRLO \n",uVar4,0,param_4);
      }
      uVar2 = 0xff7f;
      goto LAB_140007448;
    }
    uVar6 = uVar3 - 0x52;
    uVar7 = (ulonglong)uVar6;
    if (uVar6 == 0) {
      if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
        mm_printk("Received FC frame for ADISC \n",uVar4,0,param_4);
      }
      evcd_process_adisc(param_1,param_2);
      return;
    }
    if (uVar6 != 0xf) {
      if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
        mm_printk("Received unknown FC frame. Commmand: 0x%x\n",(ulonglong)uVar3,uVar7,param_4);
      }
      goto LAB_140007319;
    }
  }
  if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
    pcVar5 = "RSCN";
    if (bVar1 == 0x20) {
      pcVar5 = "PRLI";
    }
    mm_printk("Received FC frame for %s\n",pcVar5,uVar7,param_4);
  }
LAB_140007319:
  evcd_send_rjt_rsp(param_1,param_2,0xb,0);
  return;
}



===== evcd_process_rls @ 140007460 =====

void evcd_process_rls(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = evcd_get_tx_fcoe_frame(param_1);
  if ((((*(byte *)(param_1 + 0xc10) & 0x10) == 0) ||
      (iVar1 = mm_memcmp((char *)(param_1 + 0xd52),param_2 + 5,3), iVar1 == 0)) ||
     ((*(byte *)(param_1 + 0xc10) & 0x40) == 0)) {
    evcd_send_rjt_rsp(param_1,param_2,3,0x1f);
    return;
  }
  *(undefined1 *)((longlong)puVar2 + 0x1c) = 0x23;
  *(undefined4 *)((longlong)puVar2 + 0x24) = 0x9801;
  *(undefined2 *)((longlong)puVar2 + 0x2c) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)((longlong)puVar2 + 0x2e) = *(undefined2 *)(param_1 + 0xc12);
  mm_memcpy((void *)((longlong)puVar2 + 0x1d),(void *)(param_2 + 5),3);
  mm_memset((void *)((longlong)puVar2 + 0x34),0x1c,0);
  *(undefined1 *)((longlong)puVar2 + 0x34) = 2;
  evcd_tx_fcoe_frame(param_1,puVar2,0x1c,0,(undefined2 *)0x0,4);
  return;
}



===== evcd_process_sess_bls_cb @ 140007550 =====

undefined1 evcd_process_sess_bls_cb(undefined8 param_1,undefined1 *param_2)

{
  return *param_2;
}



===== evcd_process_sess_ct_cb @ 140007560 =====

ushort evcd_process_sess_ct_cb(undefined8 param_1,longlong param_2)

{
  return *(short *)(param_2 + 0x20) << 8 | (ushort)*(byte *)(param_2 + 0x21);
}



===== evcd_process_sess_els_cb @ 140007570 =====

undefined1 evcd_process_sess_els_cb(undefined8 param_1,longlong param_2)

{
  return *(undefined1 *)(param_2 + 0x18);
}



===== evcd_process_sess_fcp_cb @ 140007580 =====

ushort evcd_process_sess_fcp_cb(longlong param_1,char *param_2,undefined8 param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar7 = *(uint *)(param_2 + 0x14);
  uVar3 = (uint)param_3 & 0xffff;
  uVar8 = uVar7 >> 8 & 0xff00;
  uVar9 = (ulonglong)uVar8;
  cVar1 = *param_2;
  uVar4 = 0xffff;
  uVar7 = (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar8 | (uint)(byte)param_2[0x17];
  if (cVar1 == '\x01') {
    if ((~(FCoEDebugFlags >> 3) & 1) == 0) {
      mm_printk("OX_ID: %04x - Received SOLICITED_DATA\n",
                (ulonglong)
                ((uint)(ushort)(*(short *)(param_2 + 0x10) << 8) | (uint)(byte)param_2[0x11]),
                param_3,uVar9);
    }
    uVar8 = *(uint *)(param_1 + 0xd65) - uVar7;
    if ((uVar3 - 0x18) + uVar7 <= *(uint *)(param_1 + 0xd65)) {
      uVar8 = uVar3 - 0x18;
    }
    *(int *)(param_1 + 0xd71) = *(int *)(param_1 + 0xd71) + uVar8;
    mm_memcpy((void *)((ulonglong)uVar7 + *(longlong *)(param_1 + 0xd5d)),param_2 + 0x18,
              (ulonglong)uVar8);
  }
  else if (cVar1 == '\x05') {
    if ((~(FCoEDebugFlags >> 3) & 1) == 0) {
      mm_printk("OX_ID: %04x - Received XFER_RDY.\n",
                (ulonglong)
                ((uint)(ushort)(*(short *)(param_2 + 0x10) << 8) | (uint)(byte)param_2[0x11]),
                param_3,uVar9);
    }
    evcd_process_xfer_rdy(param_1,(longlong)param_2);
  }
  else if (cVar1 == '\a') {
    if ((~(FCoEDebugFlags >> 3) & 1) == 0) {
      mm_printk(&s_OX_ID___04x___Received_COMMAND_,
                (ulonglong)
                ((uint)(ushort)(*(short *)(param_2 + 0x10) << 8) | (uint)(byte)param_2[0x11]),
                (ulonglong)(byte)param_2[0x23],uVar9);
    }
    bVar2 = param_2[0x23];
    *(byte *)(param_1 + 0xdab) = bVar2;
    uVar4 = (ushort)bVar2;
    if ((uVar4 == 2) && ((param_2[0x22] & 2U) != 0)) {
      uVar6 = (ushort)((uint)*(undefined4 *)(param_2 + 0x28) >> 8) & 0xff00 |
              (ushort)(byte)((uint)*(undefined4 *)(param_2 + 0x28) >> 0x18);
      if ((*(void **)(param_1 + 0xd7d) != (void *)0x0) &&
         (uVar5 = *(ushort *)(param_1 + 0xd85), uVar5 != 0)) {
        if (uVar6 <= uVar5) {
          uVar5 = uVar6;
        }
        mm_memcpy(*(void **)(param_1 + 0xd7d),
                  param_2 + ((ulonglong)(*(uint *)(param_2 + 0x2c) >> 8) & 0xff00 |
                            (ulonglong)(*(uint *)(param_2 + 0x2c) >> 0x18)) + 0x30,(ulonglong)uVar5)
        ;
        *(ushort *)(param_1 + 0xd85) = uVar5;
      }
    }
  }
  else if ((~(FCoEDebugFlags >> 3) & 1) == 0) {
    mm_printk("OX_ID: %04x - Received uknonwn R_CTL\n",
              (ulonglong)
              ((uint)(ushort)(*(short *)(param_2 + 0x10) << 8) | (uint)(byte)param_2[0x11]),param_3,
              uVar9);
  }
  return uVar4;
}



===== evcd_process_xfer_rdy @ 140007794 =====

ulonglong evcd_process_xfer_rdy(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  void *pvVar5;
  ulonglong uVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  puVar3 = evcd_get_tx_fcoe_frame(param_1);
  uVar9 = *(uint *)(param_2 + 0x18);
  uVar7 = *(uint *)(param_2 + 0x1c);
  uVar10 = (uVar9 << 0x10 | uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
           (uint)*(byte *)(param_2 + 0x1b);
  uVar8 = 0;
  uVar9 = (uVar7 << 0x10 | uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
          (uint)*(byte *)(param_2 + 0x1f);
  lVar4 = evcd_get_sess_xchg_entry(param_1 + 0xc10,*(short *)(param_2 + 0x10));
  pvVar5 = (void *)0x0;
  if (lVar4 == 0) {
LAB_140007915:
    uVar6 = (ulonglong)pvVar5 & 0xffffffffffffff00;
  }
  else {
    *(undefined1 *)((longlong)puVar3 + 0x1c) = 1;
    pvVar5 = mm_memcpy((void *)((longlong)puVar3 + 0x1d),(void *)(param_1 + 0xd52),3);
    while (uVar9 != 0) {
      uVar1 = *(ushort *)(param_1 + 0xd87);
      if (uVar9 <= *(ushort *)(param_1 + 0xd87)) {
        uVar1 = (ushort)uVar9;
      }
      *(uint *)(puVar3 + 6) =
           uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
      *(ushort *)((longlong)puVar3 + 0x2a) = uVar8 << 8 | uVar8 >> 8;
      *(undefined2 *)((longlong)puVar3 + 0x2e) = *(undefined2 *)(lVar4 + 5);
      mm_memcpy((void *)((longlong)puVar3 + 0x34),
                (void *)((ulonglong)uVar10 + *(longlong *)(param_1 + 0xd5d)),(ulonglong)(uint)uVar1)
      ;
      *(int *)(param_1 + 0xd6d) = *(int *)(param_1 + 0xd6d) + (uint)uVar1;
      uVar10 = uVar10 + uVar1;
      uVar9 = uVar9 - uVar1;
      uVar7 = 0x8080008;
      if (uVar9 != 0) {
        uVar7 = 0x8000008;
      }
      if ((*(int *)(param_1 + 0xd6d) == *(int *)(param_1 + 0xd65)) || (uVar9 == 0)) {
        uVar7 = uVar7 | 0x10000;
      }
      if (uVar8 != 0) {
        *(undefined1 *)((longlong)puVar3 + 0x1b) = 0x36;
      }
      *(uint *)((longlong)puVar3 + 0x24) = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | uVar7 << 0x18;
      uVar2 = 0;
      if (uVar8 == 0) {
        uVar2 = 2;
      }
      pvVar5 = (void *)evcd_tx_fcoe_frame(param_1,puVar3,uVar1,0,(undefined2 *)0x0,uVar2);
      if ((char)pvVar5 != '\x01') goto LAB_140007915;
      uVar8 = uVar8 + 1;
    }
    uVar6 = CONCAT71((int7)((ulonglong)pvVar5 >> 8),1);
  }
  return uVar6;
}



===== evcd_restart_session @ 140007934 =====

ulonglong evcd_restart_session
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  ushort *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  
  puVar1 = (ushort *)(param_1 + 0xc10);
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("Restarting session\n",param_2,param_3,param_4);
  }
  evcd_disconnect_session(puVar1);
  uVar3 = evcd_process_fip_disc_login(param_1,param_2,param_3,param_4);
  if (((char)uVar3 == '\x01') &&
     (uVar3 = evcd_login_name_server(param_1,param_2,param_3,param_4), (char)uVar3 == '\x01')) {
    uVar2 = evcd_send_plogi(param_1,(void *)(param_1 + 0xd52));
    uVar3 = CONCAT44(extraout_var,uVar2);
    if (((char)uVar2 == '\x01') &&
       (uVar3 = evcd_send_prli(param_1,(void *)(param_1 + 0xd52)), (char)uVar3 == '\x01')) {
      return uVar3;
    }
  }
  *puVar1 = *puVar1 | 0x20;
  return uVar3 & 0xffffffffffffff00;
}



===== evcd_rx_fcoe_frame @ 1400079c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void evcd_rx_fcoe_frame(longlong param_1,byte *param_2,short param_3,undefined8 param_4)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  char *pcVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ushort uVar12;
  
  puVar1 = (uint *)(param_2 + 0x1c);
  uVar3 = *(uint *)(param_2 + 0x24);
  uVar12 = param_3 - 0x24;
  uVar11 = 6;
  uVar5 = 0xffff;
  iVar6 = mm_memcmp((char *)(param_1 + 0xc1b),(longlong)param_2,6);
  if (iVar6 != 0) {
    uVar11 = 6;
    iVar6 = mm_memcmp("\x01\x10\x18\x01",(longlong)param_2,6);
    if (iVar6 != 0) {
      if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
        mm_printk(&s_Not_our_FCoE_packet__dest_MAC_a,(ulonglong)*param_2,(ulonglong)param_2[1],
                  (ulonglong)param_2[2]);
        return;
      }
      return;
    }
  }
  if (param_2[0xe] == 0) {
    if ((param_2[0x1b] - 0x2e & 0xf7) == 0) {
      bVar2 = *(byte *)((ulonglong)uVar12 + 4 + (longlong)puVar1);
      if ((byte)(bVar2 + 0xbf) < 2) {
        uVar7 = mm_gen_crc32(puVar1,(uint)uVar12);
        uVar4 = *(uint *)((ulonglong)uVar12 + (longlong)puVar1);
        uVar10 = (ulonglong)uVar4;
        if (uVar4 == uVar7) {
          if (((param_2[0x1d] != *(byte *)(param_1 + 0xc14)) ||
              (param_2[0x1e] != *(byte *)(param_1 + 0xc15))) ||
             (param_2[0x1f] != *(byte *)(param_1 + 0xc16))) {
            if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
              mm_printk("Not our FCoE packet, dest PID = %02x:%02x:%02x\n",(ulonglong)param_2[0x1d],
                        (ulonglong)param_2[0x1e],(ulonglong)param_2[0x1f]);
              return;
            }
            return;
          }
          puVar8 = (undefined1 *)
                   evcd_get_sess_xchg_entry(param_1 + 0xc10,*(short *)(param_2 + 0x2c));
          if (puVar8 == (undefined1 *)0x0) {
            evcd_process_fc_pkt(param_1,(longlong)puVar1,uVar11,param_4);
            return;
          }
          if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
            mm_printk("Frame received for exchange \'%04x\'\n",
                      (ulonglong)
                      ((uint)(ushort)(*(short *)(puVar8 + 3) << 8) | (uint)(byte)puVar8[4]),uVar11,
                      param_4);
          }
          *(int *)(puVar8 + 0x19) = *(int *)(puVar8 + 0x19) + 1;
          *(undefined2 *)(puVar8 + 5) = *(undefined2 *)(param_2 + 0x2e);
          if (*(code **)(puVar8 + 7) != (code *)0x0) {
            uVar5 = (**(code **)(puVar8 + 7))(param_1,puVar1,param_3 + -0x24);
          }
          if ((uVar3 & 0x1800) != 0x1800) {
            return;
          }
          if (*(undefined2 **)(puVar8 + 0x11) != (undefined2 *)0x0) {
            **(undefined2 **)(puVar8 + 0x11) = uVar5;
          }
          if ((puVar8[1] & 1) == 0) {
            return;
          }
          *puVar8 = 0;
          return;
        }
        if ((~(FCoEDebugFlags >> 7) & 1) != 0) {
          return;
        }
        pcVar9 = "FCoE trailer CRC 0x%x invalid. Dropping packet\n";
      }
      else {
        if ((~(FCoEDebugFlags >> 7) & 1) != 0) {
          return;
        }
        uVar10 = (ulonglong)bVar2;
        pcVar9 = "FCoE trailer EOF 0x%x invalid. Dropping packet\n";
      }
    }
    else {
      if ((~(FCoEDebugFlags >> 7) & 1) != 0) {
        return;
      }
      uVar10 = (ulonglong)param_2[0x1b];
      pcVar9 = "FCoE header SOF 0x%x invalid\n";
    }
  }
  else {
    if ((~(FCoEDebugFlags >> 7) & 1) != 0) {
      return;
    }
    uVar10 = (ulonglong)param_2[0xe];
    pcVar9 = "FCoE header version 0x%x invalid\n";
  }
  mm_printk(pcVar9,uVar10,uVar11,param_4);
  return;
}



===== evcd_rx_pkt @ 140007c3c =====

void evcd_rx_pkt(longlong param_1,byte *param_2,ulonglong param_3,ulonglong param_4)

{
  ushort uVar1;
  byte *pbVar2;
  short sVar3;
  
  sVar3 = (short)param_3;
  pbVar2 = param_2;
  if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
    param_4 = (ulonglong)param_2[8];
    param_3 = (ulonglong)param_2[7];
    pbVar2 = (byte *)(ulonglong)param_2[6];
    mm_printk("Received packet. SRC MAC: %x:%x:%x:%x:%x:%x, DEST MAC: %x:%x:%x:%x:%x:%x\n",pbVar2,
              param_3,param_4);
  }
  uVar1 = *(short *)(param_2 + 0xc) << 8 | (ushort)param_2[0xd];
  if (uVar1 == 0x8100) {
    if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
      mm_printk("ETHERTYPE_ETH frame received\n",pbVar2,param_3,param_4);
    }
  }
  else if (uVar1 == 0x8906) {
    if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
      mm_printk("ETHERTYPE_FCOE frame received\n",pbVar2,param_3,param_4);
    }
    evcd_rx_fcoe_frame(param_1,param_2,sVar3,param_4);
  }
  else if (uVar1 == 0x8914) {
    if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
      mm_printk("ETHERTYPE_FIP frame received\n",pbVar2,param_3,param_4);
    }
    evcd_rx_fip_frame(param_1,param_2,param_3,param_4);
  }
  return;
}



===== evcd_schedule_session_restart @ 140007d90 =====

void evcd_schedule_session_restart(longlong param_1)

{
  if ((*(ushort *)(param_1 + 0xc10) & 0x20) == 0) {
    *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) | 0x20;
  }
  return;
}



===== evcd_send_abts @ 140007da8 =====

ulonglong evcd_send_abts(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  short local_res8 [4];
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  local_res8[0] = 0xff;
  *(undefined2 *)((longlong)puVar1 + 0x2c) = *(undefined2 *)(param_2 + 3);
  *(undefined2 *)((longlong)puVar1 + 0x2e) = 0xffff;
  *(undefined1 *)(puVar1 + 5) = 1;
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x81;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x900;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),(void *)(param_1 + 0xd52),3);
  uVar2 = evcd_tx_fcoe_frame(param_1,puVar1,0,0,local_res8,4);
  if ((((char)uVar2 != '\x01') ||
      (uVar2 = evcd_poll_rsp(param_1,evcd_wait_for_bls_rsp,local_res8,10), (char)uVar2 != '\x01'))
     || (local_res8[0] != 0x84)) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== evcd_send_acc_rsp @ 140007e6c =====

void evcd_send_acc_rsp(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  void *_Src;
  undefined8 uVar2;
  ulonglong uVar3;
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  if ((*(byte *)(param_1 + 0xc10) & 0x10) != 0) {
    *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x23;
    _Src = (void *)(param_2 + 5);
    *(undefined4 *)((longlong)puVar1 + 0x24) = 0x9801;
    *(undefined2 *)((longlong)puVar1 + 0x2c) = *(undefined2 *)(param_2 + 0x10);
    uVar2 = 3;
    *(undefined2 *)((longlong)puVar1 + 0x2e) = *(undefined2 *)(param_1 + 0xc12);
    mm_memcpy((void *)((longlong)puVar1 + 0x1d),_Src,3);
    *(undefined1 *)((longlong)puVar1 + 0x34) = 2;
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("Send LS_ACC\n",_Src,uVar2,param_4);
    }
    uVar3 = 0;
    uVar2 = 4;
    evcd_tx_fcoe_frame(param_1,puVar1,4,0,(undefined2 *)0x0,4);
    mm_device_poll(param_1,puVar1,uVar2,uVar3);
  }
  return;
}



===== evcd_send_fka @ 140007f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void evcd_send_fka(longlong param_1)

{
  if (*(char *)(param_1 + 0xd89) != '\0') {
    if ((ulonglong)*(uint *)(param_1 + 0xc65) <=
        (ulonglong)(*(longlong *)(param_1 + 0xc08) - *(longlong *)(param_1 + 0xd8a))) {
      *(longlong *)(param_1 + 0xd8a) = *(longlong *)(param_1 + 0xc08);
      (**(code **)(param_1 + 0xd92))(param_1);
    }
  }
  if ((*(char *)(param_1 + 0xd9a) != '\0') &&
     (89999 < (ulonglong)(*(longlong *)(param_1 + 0xc08) - *(longlong *)(param_1 + 0xd9b)))) {
    *(longlong *)(param_1 + 0xd9b) = *(longlong *)(param_1 + 0xc08);
    (**(code **)(param_1 + 0xda3))(param_1);
  }
  return;
}



===== evcd_send_rjt_rsp @ 140007fa4 =====

void evcd_send_rjt_rsp(longlong param_1,longlong param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x23;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x9801;
  *(undefined2 *)((longlong)puVar1 + 0x2c) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)((longlong)puVar1 + 0x2e) = *(undefined2 *)(param_1 + 0xc12);
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),(void *)(param_2 + 5),3);
  mm_memset((void *)((longlong)puVar1 + 0x34),8,0);
  *(undefined1 *)((longlong)puVar1 + 0x34) = 1;
  *(undefined1 *)((longlong)puVar1 + 0x39) = param_3;
  *(undefined1 *)((longlong)puVar1 + 0x3a) = param_4;
  evcd_tx_fcoe_frame(param_1,puVar1,8,0,(undefined2 *)0x0,4);
  return;
}



===== evcd_send_scsi_cdb @ 14000805c =====

ulonglong evcd_send_scsi_cdb(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  ushort *puVar1;
  void *_Src;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined4 extraout_var;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 extraout_var_00;
  byte bVar8;
  longlong lVar9;
  int iVar10;
  ushort local_res8 [4];
  
  lVar9 = param_2;
  puVar5 = evcd_get_tx_fcoe_frame(param_1);
  puVar1 = (ushort *)(param_1 + 0xc10);
  local_res8[0] = 0xffff;
  if ((*(byte *)puVar1 & 0x20) != 0) {
    if ((~(FCoEDebugFlags >> 1) & 1) == 0) {
      mm_printk("Fabric inactive. Attempting to restart session.\n",lVar9,param_3,param_4);
    }
    evcd_restart_session(param_1,lVar9,param_3,param_4);
  }
  uVar2 = *puVar1;
  puVar6 = (undefined1 *)(ulonglong)uVar2;
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x20) == 0) {
      puVar6 = (undefined1 *)(ulonglong)(uVar2 | 0x20);
      *puVar1 = uVar2 | 0x20;
    }
    goto LAB_1400080d3;
  }
  _Src = (void *)(param_1 + 0xd52);
  if ((uVar2 & 0x40) == 0) {
    uVar4 = evcd_send_plogi(param_1,_Src);
    puVar6 = (undefined1 *)CONCAT44(extraout_var,uVar4);
    if ((char)uVar4 != '\x01') goto LAB_1400080d3;
    *puVar1 = *puVar1 | 0x40;
    puVar6 = (undefined1 *)(ulonglong)*puVar1;
  }
  if (((ulonglong)puVar6 & 0x80) == 0) {
    puVar6 = (undefined1 *)evcd_send_prli(param_1,_Src);
    if ((char)puVar6 != '\x01') goto LAB_1400080d3;
    *puVar1 = *puVar1 | 0x80;
  }
  *(undefined8 *)(param_1 + 0xd5d) = *(undefined8 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0xd65) = *(undefined4 *)(param_2 + 0x10);
  *(undefined8 *)(param_1 + 0xd7d) = *(undefined8 *)(param_2 + 0x20);
  *(ushort *)(param_1 + 0xd85) = (ushort)*(byte *)(param_2 + 0xb);
  *(undefined8 *)(param_1 + 0xd6d) = 0;
  *(undefined1 *)(param_1 + 0xdab) = 0;
  *(undefined1 *)((longlong)puVar5 + 0x1c) = 6;
  *(undefined4 *)((longlong)puVar5 + 0x24) = 0x2908;
  mm_memcpy((void *)((longlong)puVar5 + 0x1d),_Src,3);
  mm_memset((void *)((longlong)puVar5 + 0x34),0x20,0);
  mm_memcpy((void *)((longlong)puVar5 + 0x34),(void *)(param_1 + 0xd55),8);
  mm_memcpy(puVar5 + 8,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  uVar4 = *(uint *)(param_2 + 0x10);
  *(uint *)(puVar5 + 10) =
       (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | (uint)*(byte *)(param_2 + 0x13)
  ;
  bVar8 = (byte)*(uint *)(param_2 + 0xc);
  if ((*(uint *)(param_2 + 0xc) & 0x40) != 0) {
    *(byte *)((longlong)puVar5 + 0x3f) = *(byte *)((longlong)puVar5 + 0x3f) | 2;
    bVar8 = (byte)*(undefined4 *)(param_2 + 0xc);
  }
  if ((bVar8 & 0x80) != 0) {
    *(byte *)((longlong)puVar5 + 0x3f) = *(byte *)((longlong)puVar5 + 0x3f) | 1;
  }
  puVar6 = (undefined1 *)evcd_tx_fcoe_frame(param_1,puVar5,0x20,0,local_res8,3);
  if ((char)puVar6 != '\x01') goto LAB_1400080d3;
  sVar3 = *(short *)((longlong)puVar5 + 0x2c);
  evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res8,(ulonglong)*(uint *)(param_2 + 0x14));
  puVar7 = (undefined1 *)evcd_get_sess_xchg_entry((longlong)puVar1,sVar3);
  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_1 + 0xdab);
  puVar6 = puVar7;
  if (local_res8[0] == 0) {
    if (((((*(uint *)(param_2 + 0xc) & 0x40) != 0) && (*(longlong *)(param_2 + 0x18) != 0)) &&
        (0x1ff < *(uint *)(param_2 + 0x10))) &&
       (puVar6 = (undefined1 *)(ulonglong)*(uint *)(param_1 + 0xd65),
       *(uint *)(param_1 + 0xd71) < *(uint *)(param_1 + 0xd65))) {
      local_res8[0] = 0xfffe;
      goto LAB_1400082ad;
    }
  }
  else {
LAB_1400082ad:
    if (0xfffd < local_res8[0]) {
      iVar10 = 0;
      do {
        if ((*(byte *)puVar1 & 0x20) != 0) {
          *puVar7 = 0;
          goto LAB_1400080d3;
        }
        puVar6 = (undefined1 *)evcd_send_abts(param_1,(longlong)puVar7);
      } while (((char)puVar6 != '\x01') && (iVar10 = iVar10 + 1, iVar10 < 2));
      if (iVar10 == 2) {
        *puVar1 = *puVar1 & 0xff3f;
        uVar4 = evcd_send_plogi(param_1,_Src);
        puVar6 = (undefined1 *)CONCAT44(extraout_var_00,uVar4);
        if ((char)uVar4 == '\x01') {
          *puVar1 = *puVar1 | 0x40;
          puVar6 = (undefined1 *)evcd_send_prli(param_1,_Src);
          if ((char)puVar6 == '\x01') {
            puVar6 = (undefined1 *)0x0;
            *puVar1 = *puVar1 | 0x80;
          }
        }
      }
    }
  }
  *puVar7 = 0;
  if (local_res8[0] == 0) {
    return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
  }
LAB_1400080d3:
  return (ulonglong)puVar6 & 0xffffffffffffff00;
}



===== evcd_tx_fcoe_frame @ 140008328 =====

undefined8
evcd_tx_fcoe_frame(longlong param_1,undefined8 *param_2,ushort param_3,longlong param_4,
                  undefined2 *param_5,ushort param_6)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  ushort uVar11;
  undefined8 uVar12;
  uint uVar13;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined1 local_3c;
  
  puVar1 = (uint *)((longlong)param_2 + 0x1c);
  uVar3 = *(uint *)((longlong)param_2 + 0x24);
  uVar8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uVar5 = 0;
  local_40 = 0;
  local_3c = 0;
  uVar13 = (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | (uint)*(byte *)((longlong)param_2 + 0x27);
  if (((param_6 & 1) != 0) &&
     (*(short *)(param_1 + 0xc12) = *(short *)(param_1 + 0xc12) + 1,
     *(short *)(param_1 + 0xc12) == -1)) {
    *(undefined2 *)(param_1 + 0xc12) = 0;
  }
  if ((param_6 & 4) == 0) {
    *(ushort *)((longlong)param_2 + 0x2c) =
         *(short *)(param_1 + 0xc12) << 8 | (ushort)*(byte *)(param_1 + 0xc13);
  }
  uVar11 = *(ushort *)((longlong)param_2 + 0x2c);
  uVar10 = (ulonglong)uVar11;
  if ((param_6 & 1) == 0) {
    puVar6 = (undefined8 *)evcd_get_sess_xchg_entry(param_1 + 0xc10,uVar11);
    puVar4 = &local_58;
    if (puVar6 != (undefined8 *)0x0) {
      puVar4 = puVar6;
    }
  }
  else {
    puVar4 = (undefined8 *)evcd_alloc_sess_exchg_entry(param_1 + 0xc10,uVar11,param_6 >> 3 & 1);
    if (puVar4 == (undefined8 *)0x0) {
      uVar5 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) == 0) {
        uVar5 = mm_printk("Failed to get a free exchange\n",uVar10,0,uVar8);
      }
      return uVar5 & 0xffffffffffffff00;
    }
    *(undefined2 *)((longlong)param_2 + 0x2e) = 0xffff;
    if (param_5 != (undefined2 *)0x0) {
      *param_5 = 0xffff;
    }
  }
  uVar8 = 0;
  uVar9 = (uVar3 << 0x10 & 0xffffff) >> 0x10;
  *(char *)(puVar4 + 2) = (char)uVar3;
  *(undefined1 *)((longlong)puVar4 + 0xf) = *(undefined1 *)puVar1;
  if (param_5 != (undefined2 *)0x0) {
    *(undefined2 **)((longlong)puVar4 + 0x11) = param_5;
  }
  if (param_4 == 0) {
    if (uVar9 == 0) {
      pcVar7 = evcd_process_sess_bls_cb;
    }
    else if (uVar9 == 1) {
      pcVar7 = evcd_process_sess_els_cb;
    }
    else if (uVar9 == 8) {
      pcVar7 = evcd_process_sess_fcp_cb;
    }
    else {
      if (uVar9 != 0x20) goto LAB_1400084c2;
      pcVar7 = evcd_process_sess_ct_cb;
    }
    *(code **)((longlong)puVar4 + 7) = pcVar7;
  }
  else {
    *(longlong *)((longlong)puVar4 + 7) = param_4;
  }
LAB_1400084c2:
  cVar2 = *(char *)(param_1 + 0xc17);
  if ((param_6 & 2) != 0) {
    cVar2 = cVar2 + '\x01';
    *(char *)(param_1 + 0xc17) = cVar2;
  }
  uVar10 = (ulonglong)param_3;
  *(char *)(param_2 + 5) = cVar2;
  if ((param_3 & 3) != 0) {
    uVar11 = 4 - (param_3 & 3);
    uVar5 = (ulonglong)uVar11;
    if (uVar11 != 0) {
      uVar9 = (uint)uVar11;
      uVar13 = uVar13 | uVar11;
      *(uint *)((longlong)param_2 + 0x24) =
           (uVar3 << 0x10 & 0xffffff) >> 0x10 | uVar3 & 0xff00 | (uVar13 & 0xff00) << 8 |
           uVar13 << 0x18;
      goto LAB_140008506;
    }
  }
  uVar9 = 0;
LAB_140008506:
  uVar3 = mm_gen_crc32(puVar1,param_3 + 0x18 + uVar9);
  *(uint *)((longlong)puVar1 + uVar10 + 0x18 + uVar5) = uVar3;
  uVar12 = 0;
  *(undefined2 *)((longlong)puVar1 + uVar10 + 0x1d + uVar5) = 0;
  *(char *)((longlong)puVar1 + uVar10 + 0x1c + uVar5) = ((uVar13 >> 0x13 & 1) != 0) + 'A';
  *(undefined1 *)((longlong)puVar1 + uVar10 + 0x1f + uVar5) = 0;
  if ((~(FCoEDebugFlags >> 7) & 1) == 0) {
    mm_printk("Frame transmitted for exchange \'%04x\'\n",
              (ulonglong)
              ((uint)(ushort)(*(short *)((longlong)puVar4 + 3) << 8) |
              (uint)*(byte *)((longlong)puVar4 + 4)),uVar8,0);
  }
  uVar8 = mm_transmit_packet_raw(param_1,param_2,param_3 + (short)uVar5 + 0x3c,uVar12);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== evcd_wait_for_bls_rsp @ 1400085a0 =====

bool evcd_wait_for_bls_rsp(short *param_1)

{
  return *param_1 != 0xff;
}



===== evcd_wait_for_els_rsp @ 1400085b0 =====

undefined8 evcd_wait_for_els_rsp(short *param_1)

{
  return CONCAT71(0xff,*param_1 != -1);
}



===== evcd_get_tx_fip_frame @ 1400085bc =====

void * evcd_get_tx_fip_frame(longlong param_1,int param_2)

{
  undefined1 *_Src;
  
  *(undefined2 *)(param_1 + 0x11ba) = 0x1489;
  mm_memcpy((void *)(param_1 + 0x11b4),(void *)(param_1 + 0xc21),6);
  _Src = &s_____;
  if (param_2 == 0) {
    _Src = (undefined1 *)(param_1 + 0xc41);
  }
  mm_memcpy((void *)(param_1 + 0x11ae),_Src,6);
  return (void *)(param_1 + 0x11ae);
}



===== evcd_init_fip_hdr @ 14000862c =====

void evcd_init_fip_hdr(undefined1 *param_1,ushort param_2,undefined1 param_3)

{
  mm_memset(param_1,10,0);
  *(ushort *)(param_1 + 2) = param_2 << 8 | param_2 >> 8;
  param_1[5] = param_3;
  *param_1 = 0x10;
  return;
}



===== evcd_poll_rsp @ 140008674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong evcd_poll_rsp(longlong param_1,undefined *param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar5 = (int)param_4 * 1000;
  uVar4 = 0;
  puVar3 = param_2;
  uVar6 = param_3;
  if (uVar5 != 0) {
    do {
      if ((*(byte *)(param_1 + 0xc10) & 0x20) != 0) {
        register0x00000020 = (BADSPACEBASE *)(ulonglong)~(FCoEDebugFlags >> 2);
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          register0x00000020 =
               (BADSPACEBASE *)
               mm_printk("Pending CVL. Bailing out of command processing.\n",puVar3,uVar6,param_4);
        }
        break;
      }
      uVar1 = mm_get_elapsed_ms(param_1);
      *(longlong *)(param_1 + 0xc08) = *(longlong *)(param_1 + 0xc08) + (ulonglong)uVar1;
      evcd_send_fka(param_1);
      mm_device_poll(param_1,puVar3,uVar6,param_4);
      uVar2 = (*(code *)param_2)(param_3);
      if ((char)uVar2 != '\0') {
        return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
      }
      register0x00000020 = (BADSPACEBASE *)mm_delay(0x3de);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== evcd_process_fip_disc_adv @ 14000872c =====

void evcd_process_fip_disc_adv(longlong param_1,ushort *param_2,byte *param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  ushort uVar5;
  byte *pbVar6;
  ushort local_res8;
  
  pbVar6 = (byte *)(param_1 + 10);
  uVar5 = 0;
  bVar1 = *(byte *)(param_1 + 9);
  local_res8 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  uVar3 = 0;
  if ((*param_2 & 2) == 0) {
    if ((bVar1 & 7) != 7) {
      return;
    }
  }
  else {
    iVar4 = mm_memcmp((char *)((longlong)param_2 + 0x31),(longlong)param_3,6);
    if (iVar4 != 0) {
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        mm_printk("Ignoring Discovery Advt from a FCF not logged into. MAC= %02x:%02x:%02x:%02x:%02x:%02x\n"
                  ,(ulonglong)*param_3,(ulonglong)param_3[1],(ulonglong)param_3[2]);
        return;
      }
      return;
    }
    if ((bVar1 & 5) != 5) {
      return;
    }
  }
  if (local_res8 != 0) {
    do {
      bVar1 = *pbVar6;
      if (bVar1 == 1) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("Fabric priority = 0x%x\n",(ulonglong)pbVar6[3],1,param_4);
        }
        uVar5 = uVar5 | 1;
        *(byte *)((longlong)param_2 + 0x2b) = pbVar6[3];
        uVar3 = uVar5;
      }
      else if (bVar1 == 2) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          param_4 = (ulonglong)pbVar6[4];
          mm_printk("FCF MAC addr = %02x:%02x:%02x:%02x:%02x:%02x\n",(ulonglong)pbVar6[2],
                    (ulonglong)pbVar6[3],param_4);
        }
        mm_memcpy((void *)((longlong)param_2 + 0x31),pbVar6 + 2,6);
      }
      else if (bVar1 == 4) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          param_4 = (ulonglong)pbVar6[6];
          mm_printk("FCF node name = %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n",(ulonglong)pbVar6[4]
                    ,(ulonglong)pbVar6[5],param_4);
        }
        mm_memcpy((void *)((longlong)param_2 + 0x37),pbVar6 + 4,8);
        uVar5 = uVar5 | 2;
        uVar3 = uVar5;
      }
      else if (bVar1 == 5) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          param_4 = (ulonglong)pbVar6[6];
          mm_printk("VF_ID = 0x%x, FC-MAP = %02x:%02x:%02x, Fabric name = %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n"
                    ,(ulonglong)*(ushort *)(pbVar6 + 2),(ulonglong)pbVar6[5],param_4);
          uVar5 = uVar3;
        }
        *(undefined2 *)((longlong)param_2 + 0x2f) = *(undefined2 *)(pbVar6 + 2);
        *(byte *)(param_2 + 0x16) = pbVar6[5];
        *(byte *)((longlong)param_2 + 0x2d) = pbVar6[6];
        *(byte *)(param_2 + 0x17) = pbVar6[7];
        mm_memcpy((void *)((longlong)param_2 + 0x3f),pbVar6 + 8,8);
        uVar5 = uVar5 | 4;
        uVar3 = uVar5;
      }
      else if (bVar1 == 0xc) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          uVar2 = *(uint *)(pbVar6 + 4);
          mm_printk("FKA ADV Period = %d ms\n",
                    (ulonglong)
                    ((uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | (uint)pbVar6[7]),
                    0xc,param_4);
        }
        uVar2 = *(uint *)(pbVar6 + 4);
        *(uint *)((longlong)param_2 + 0x55) =
             (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | (uint)pbVar6[7];
        if ((pbVar6[3] & 1) == 0) {
          *(ushort *)((longlong)param_2 + 0x27) = *(ushort *)((longlong)param_2 + 0x27) | 1;
        }
      }
      else if ((~FCoEDebugFlags & 1) == 0) {
        mm_printk("%s(): Unknown fip_desc->hdr.type 0x%x\n","evcd_process_fip_disc_adv",
                  (ulonglong)bVar1,param_4);
      }
      local_res8 = local_res8 - pbVar6[1];
      pbVar6 = pbVar6 + (ulonglong)pbVar6[1] * 4;
    } while (local_res8 != 0);
    if (uVar5 == 7) {
      *param_2 = *param_2 | 2;
    }
  }
  return;
}



===== evcd_process_fip_disc_login @ 140008ae4 =====

longlong evcd_process_fip_disc_login
                   (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  ushort uVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  
  pcVar4 = (char *)(ulonglong)*(ushort *)(param_1 + 0xc39);
  uVar9 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  mm_cfg_vlan_mode(param_1,*(ushort *)(param_1 + 0xc39));
  uVar8 = 0;
  if ((*(short *)(param_1 + 0xc39) == 0) && (uVar5 = 0, *(byte *)(param_1 + 0xdac) != 0xffffffff)) {
    do {
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        uVar9 = (ulonglong)uVar5;
        pcVar4 = "evcd_process_fip_disc_login";
        mm_printk("%s(): FIP VLAN Request, attempt %d\n","evcd_process_fip_disc_login",uVar9,param_4
                 );
      }
      *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) & 0xfffe;
      cVar1 = evcd_send_fip_vlan_req(param_1,pcVar4,uVar9,param_4);
      if (cVar1 == '\x01') {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          uVar9 = (ulonglong)*(ushort *)(param_1 + 0xc39);
          mm_printk("%s(): FIP VLAN Request successful. VLAN id %d\n","evcd_process_fip_disc_login",
                    uVar9,param_4);
        }
        break;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < (int)(*(byte *)(param_1 + 0xdac) + 1));
  }
  uVar2 = *(ushort *)(param_1 + 0xc39);
  if (uVar2 == 0) {
    if ((~(FCoEDebugFlags >> 1) & 1) == 0) {
      uVar9 = 0x3ea;
      mm_printk("%s(): FIP VLAN Request failed. Attempting with default VLAN id %d\n",
                "evcd_process_fip_disc_login",0x3ea,param_4);
    }
    uVar2 = 0x3ea;
  }
  uVar10 = CONCAT71((int7)(uVar9 >> 8),1);
  pcVar4 = (char *)(ulonglong)uVar2;
  mm_cfg_vlan_mode(param_1,uVar2);
  uVar5 = 0;
  if (*(byte *)(param_1 + 0xdac) != 0xffffffff) {
    do {
      iVar6 = (int)uVar8;
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        pcVar4 = "evcd_process_fip_disc_login";
        uVar10 = 0x3ea;
        mm_printk("%s(): FIP Discovery Solicitation with VLAN id %d, attempt %d\n",
                  "evcd_process_fip_disc_login",0x3ea,uVar8);
        param_4 = uVar8;
      }
      *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) & 0xfffd;
      cVar1 = evcd_send_fip_disc_solicit(param_1,pcVar4,uVar10,param_4);
      if ((cVar1 == '\x01') &&
         (uVar3 = evcd_send_fip_flogi(param_1,pcVar4,uVar10,param_4), (char)uVar3 == '\x01')) {
        return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      }
      uVar7 = iVar6 + 1;
      uVar8 = (ulonglong)uVar7;
      uVar5 = *(byte *)(param_1 + 0xdac) + 1;
    } while ((int)uVar7 < (int)uVar5);
  }
  return (ulonglong)(uVar5 >> 8) << 8;
}



===== evcd_process_fip_vlan_notif @ 140008c5c =====

void evcd_process_fip_vlan_notif(longlong param_1,ushort *param_2,byte *param_3,ulonglong param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  ushort uVar7;
  ushort uVar8;
  byte *pbVar9;
  
  pbVar6 = (byte *)(param_1 + 10);
  uVar7 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  uVar8 = 0;
  bVar2 = false;
  pbVar9 = param_3;
  if ((*param_2 & 1) != 0) {
    pbVar9 = (byte *)0x6;
    pbVar5 = param_3;
    iVar3 = mm_memcmp((char *)((longlong)param_2 + 0x31),(longlong)param_3,6);
    if (iVar3 != 0) {
      if ((~(FCoEDebugFlags >> 2) & 1) != 0) {
        return;
      }
      pcVar4 = "Ignoring VLAN notification from unknown FCF MAC.\n";
LAB_140008df0:
      mm_printk(pcVar4,pbVar5,pbVar9,param_4);
      return;
    }
  }
  if (uVar7 != 0) {
    do {
      bVar1 = *pbVar6;
      if (bVar1 == 2) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          param_4 = (ulonglong)param_3[2];
          mm_printk("FCF MAC addr = %02x:%02x:%02x:%02x:%02x:%02x\n",(ulonglong)*param_3,
                    (ulonglong)param_3[1],param_4);
        }
        pbVar5 = pbVar6 + 2;
        pbVar9 = (byte *)0x6;
        if ((*param_2 & 1) == 0) {
          mm_memcpy((char *)((longlong)param_2 + 0x31),pbVar5,6);
        }
        else {
          iVar3 = mm_memcmp((char *)((longlong)param_2 + 0x31),(longlong)pbVar5,6);
          if (iVar3 != 0) {
            if ((~(FCoEDebugFlags >> 2) & 1) != 0) {
              return;
            }
            pcVar4 = "Invalid MAC descriptor on an unsolicited VLAN notification.\n";
            goto LAB_140008df0;
          }
        }
      }
      else if (bVar1 == 0xe) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("FIP VLAN ID = %d\n",
                    (ulonglong)((uint)(ushort)(*(short *)(pbVar6 + 2) << 8) | (uint)pbVar6[3]),
                    pbVar9,param_4);
        }
        bVar2 = true;
        uVar8 = (*(ushort *)(pbVar6 + 2) & 0xf) << 8 | (ushort)pbVar6[3];
      }
      else if ((~FCoEDebugFlags & 1) == 0) {
        pbVar9 = (byte *)(ulonglong)bVar1;
        mm_printk("%s(): Unknown fip_desc->hdr.type 0x%x\n","evcd_process_fip_vlan_notif",pbVar9,
                  param_4);
      }
      pbVar5 = pbVar6 + 1;
      pbVar6 = pbVar6 + (ulonglong)*pbVar5 * 4;
      uVar7 = uVar7 - *pbVar5;
    } while (uVar7 != 0);
    if (bVar2) {
      *param_2 = *param_2 | 1;
      *(ushort *)((longlong)param_2 + 0x29) = uVar8;
    }
  }
  return;
}



===== evcd_send_fip_disc_solicit @ 140008e14 =====

void evcd_send_fip_disc_solicit
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = evcd_get_tx_fip_frame(param_1,1);
  evcd_init_fip_hdr((undefined1 *)((longlong)puVar1 + 0xe),1,1);
  *(undefined4 *)((longlong)puVar1 + 0x14) = 0x800600;
  *(undefined2 *)(puVar1 + 3) = 0x202;
  mm_memcpy((void *)((longlong)puVar1 + 0x1a),(void *)(param_1 + 0xc21),6);
  *(undefined2 *)(puVar1 + 4) = 0x304;
  mm_memcpy((void *)((longlong)puVar1 + 0x24),(void *)(param_1 + 0xc27),8);
  *(undefined2 *)((longlong)puVar1 + 0x2c) = 0x106;
  *(ushort *)((longlong)puVar1 + 0x2e) =
       *(short *)(param_1 + 0xc19) << 8 | (ushort)*(byte *)(param_1 + 0xc1a);
  mm_transmit_packet_raw(param_1,puVar1,0x30,param_4);
  evcd_poll_rsp(param_1,evcd_wait_for_fip_disc_adv,param_1 + 0xc10,2);
  return;
}



===== evcd_send_fip_vlan_req @ 140008ee0 =====

void evcd_send_fip_vlan_req
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = evcd_get_tx_fip_frame(param_1,1);
  evcd_init_fip_hdr((undefined1 *)((longlong)puVar1 + 0xe),4,1);
  *(undefined2 *)(puVar1 + 3) = 0x202;
  *(undefined2 *)((longlong)puVar1 + 0x14) = 0x200;
  mm_memcpy((void *)((longlong)puVar1 + 0x1a),(void *)(param_1 + 0xc21),6);
  mm_transmit_packet_raw(param_1,puVar1,0x20,param_4);
  evcd_poll_rsp(param_1,evcd_wait_for_fip_vlan_notif,param_1 + 0xc10,2);
  return;
}



===== evcd_wait_for_fip_disc_adv @ 140008f80 =====

byte evcd_wait_for_fip_disc_adv(byte *param_1)

{
  return *param_1 >> 1 & 1;
}



===== evcd_wait_for_fip_vlan_notif @ 140008f90 =====

byte evcd_wait_for_fip_vlan_notif(byte *param_1)

{
  return *param_1 & 1;
}



===== evcd_get_dns_object @ 140008f98 =====

longlong evcd_get_dns_object(longlong param_1,byte param_2,longlong param_3,undefined2 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 2;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x2920;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),s____,3);
  mm_memset((void *)((longlong)puVar1 + 0x34),0x10,0);
  *(undefined1 *)((longlong)puVar1 + 0x34) = 1;
  *(undefined2 *)(puVar1 + 7) = 0x2fc;
  *(ushort *)((longlong)puVar1 + 0x3c) = (ushort)param_2 << 8 | 1;
  if (param_2 == 0x72) {
    *(undefined2 *)((longlong)puVar1 + 0x45) = 0;
    *(undefined1 *)((longlong)puVar1 + 0x47) = 8;
    lVar2 = evcd_tx_fcoe_frame(param_1,puVar1,0x14,param_3,param_4,0xb);
  }
  else {
    lVar2 = (ulonglong)(ushort)param_2 << 8;
  }
  return lVar2;
}



===== evcd_get_tx_fcoe_frame @ 14000905c =====

void * evcd_get_tx_fcoe_frame(longlong param_1)

{
  void *_Dst;
  
  _Dst = (void *)(param_1 + 0xdae);
  mm_memset(_Dst,0x5f0,0);
  *(undefined2 *)(param_1 + 0xdba) = 0x689;
  mm_memcpy((void *)(param_1 + 0xdb4),(void *)(param_1 + 0xc1b),6);
  mm_memcpy(_Dst,(void *)((ulonglong)(-(uint)((*(ushort *)(param_1 + 0xc10) & 0x100) != 0) & 0x1e) +
                          0x31 + param_1 + 0xc10),6);
  mm_memset((void *)(param_1 + 0xdbc),0xe,0);
  *(undefined1 *)(param_1 + 0xdbc) = 0;
  *(undefined1 *)(param_1 + 0xdc9) = 0x2e;
  mm_memset((void *)(param_1 + 0xdca),0x18,0);
  mm_memcpy((void *)(param_1 + 0xdcf),(void *)(param_1 + 0xc14),3);
  return _Dst;
}



===== evcd_issue_plogi @ 140009128 =====

short evcd_issue_plogi(longlong param_1,void *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  short local_res8 [4];
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  local_res8[0] = -1;
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x22;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x2901;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),param_2,3);
  mm_memset((void *)((longlong)puVar1 + 0x34),0x74,0);
  *(undefined1 *)((longlong)puVar1 + 0x34) = 3;
  *(undefined4 *)(puVar1 + 7) = 0x12020;
  *(undefined4 *)((longlong)puVar1 + 0x3c) = 0x44080;
  *(undefined4 *)((longlong)puVar1 + 0x44) = 0xd0070000;
  *(ushort *)(puVar1 + 8) = (ushort)*(byte *)(param_1 + 0xc18) << 8;
  *(undefined2 *)((longlong)puVar1 + 0x42) = 0x200;
  mm_memcpy(puVar1 + 9,(void *)(param_1 + 0xc2f),8);
  mm_memcpy(puVar1 + 10,(void *)(param_1 + 0xc27),8);
  *(undefined2 *)((longlong)puVar1 + 0x7e) = 4;
  *(undefined2 *)(puVar1 + 0xf) = 0x80;
  *(undefined1 *)((longlong)puVar1 + 0x81) = *(undefined1 *)(param_1 + 0xc18);
  *(undefined1 *)((longlong)puVar1 + 0x85) = 1;
  uVar2 = evcd_tx_fcoe_frame(param_1,puVar1,0x74,0,local_res8,0xb);
  if ((char)uVar2 == '\x01') {
    puVar3 = (undefined1 *)
             evcd_get_sess_xchg_entry(param_1 + 0xc10,*(short *)((longlong)puVar1 + 0x2c));
    evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res8,0x14);
    if (local_res8[0] == -1) {
      evcd_free_sess_xchg_entry(puVar3);
    }
    if ((ushort)(local_res8[0] - 1U) < 2) {
      return local_res8[0];
    }
  }
  return 0;
}



===== evcd_login_name_server @ 140009298 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong evcd_login_name_server
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if ((*(byte *)(param_1 + 0xc37) & 1) != 0) {
    uVar1 = mm_get_elapsed_ms(param_1);
    *(longlong *)(param_1 + 0xc08) = *(longlong *)(param_1 + 0xc08) + (ulonglong)uVar1;
    *(undefined1 *)(param_1 + 0xd89) = 1;
    *(undefined8 *)(param_1 + 0xd8a) = *(undefined8 *)(param_1 + 0xc08);
    *(code **)(param_1 + 0xd92) = evcd_tx_fka;
    *(undefined1 *)(param_1 + 0xd9a) = 1;
    *(undefined8 *)(param_1 + 0xd9b) = *(undefined8 *)(param_1 + 0xc08);
    *(code **)(param_1 + 0xda3) = evcd_tx_vn_fka;
    evcd_tx_fka(param_1,param_2,param_3,param_4);
    (**(code **)(param_1 + 0xda3))(param_1);
  }
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk(&s_Send_SCR_,param_2,param_3,param_4);
  }
  uVar2 = evcd_send_scr(param_1);
  if ((char)uVar2 == '\x01') {
    if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
      mm_printk("Issue DNS registration\n",param_2,param_3,param_4);
    }
    uVar3 = evcd_register_dns(param_1,param_2,param_3,param_4);
    if ((char)uVar3 == '\x01') {
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        mm_printk("Query NxPorts\n",param_2,param_3,param_4);
      }
      uVar2 = evcd_query_nx_ports(param_1);
      if ((char)uVar2 == '\x01') {
        *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) | 0x10;
        return CONCAT71((int7)(uVar2 >> 8),1);
      }
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_1400093c1;
      pcVar4 = "Query NxPorts failed\n";
    }
    else {
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_1400093c1;
      pcVar4 = "DNS registration failed\n";
    }
  }
  else {
    uVar2 = (ulonglong)~FCoEDebugFlags;
    if ((~FCoEDebugFlags & 1) != 0) goto LAB_1400093c1;
    pcVar4 = "SCR failed\n";
  }
  uVar2 = mm_printk(pcVar4,param_2,param_3,param_4);
LAB_1400093c1:
  return uVar2 & 0xffffffffffffff00;
}



===== evcd_login_target @ 1400093d8 =====

ulonglong evcd_login_target(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  void *_Dst;
  uint uVar1;
  ulonglong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar2 = 0;
  if (((*(char *)(param_2 + 1) != '\0') || (*(char *)(param_2 + 2) != '\0')) ||
     (*(char *)(param_2 + 3) != '\0')) {
    _Dst = (void *)(param_1 + 0xd52);
    mm_memcpy(_Dst,(char *)(param_2 + 1),3);
    uVar4 = 8;
    mm_memcpy((void *)(param_1 + 0xd55),(void *)(param_2 + 4),8);
    uVar1 = evcd_send_plogi(param_1,_Dst);
    if ((char)uVar1 == '\x01') {
      *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) | 0x40;
      uVar2 = evcd_send_prli(param_1,_Dst);
      if ((char)uVar2 == '\x01') {
        *(ushort *)(param_1 + 0xc10) = *(ushort *)(param_1 + 0xc10) | 0x80;
        return CONCAT71((int7)(uVar2 >> 8),1);
      }
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_140009490;
      pcVar3 = "%s(): PRLI failed\n";
    }
    else {
      uVar2 = (ulonglong)~FCoEDebugFlags;
      if ((~FCoEDebugFlags & 1) != 0) goto LAB_140009490;
      pcVar3 = "%s(): PLOGI failed\n";
    }
    uVar2 = mm_printk(pcVar3,"evcd_login_target",uVar4,param_4);
  }
LAB_140009490:
  return uVar2 & 0xffffffffffffff00;
}



===== evcd_process_fip_cvl @ 1400094b4 =====

void evcd_process_fip_cvl(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  char *pcVar6;
  
  pcVar6 = (char *)(param_1 + 10);
  uVar4 = 0;
  uVar5 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  if (uVar5 != 0) {
    do {
      cVar2 = *pcVar6;
      if (cVar2 == '\x02') {
        iVar3 = mm_memcmp((char *)(param_2 + 0xc41),(longlong)(pcVar6 + 2),6);
        if (iVar3 == 0) {
          uVar4 = uVar4 | 1;
        }
      }
      else if (cVar2 == '\x04') {
        iVar3 = mm_memcmp((char *)(param_2 + 0xc47),(longlong)(pcVar6 + 4),8);
        if (iVar3 == 0) {
          uVar4 = uVar4 | 2;
        }
      }
      else if (cVar2 == '\v') {
        iVar3 = mm_memcmp((char *)(param_2 + 0xc1b),(longlong)(pcVar6 + 2),6);
        if (iVar3 == 0) {
          iVar3 = mm_memcmp((char *)(param_2 + 0xc14),(longlong)(pcVar6 + 9),3);
          if (iVar3 == 0) {
            iVar3 = mm_memcmp((char *)(param_2 + 0xc2f),(longlong)(pcVar6 + 0xc),8);
            if (iVar3 == 0) {
              uVar4 = uVar4 | 4;
            }
          }
        }
      }
      pbVar1 = (byte *)(pcVar6 + 1);
      pcVar6 = pcVar6 + (ulonglong)*pbVar1 * 4;
      uVar5 = uVar5 - *pbVar1;
    } while (uVar5 != 0);
    if (uVar4 == 7) {
      evcd_schedule_session_restart(param_2);
    }
  }
  return;
}



===== evcd_process_fip_flogi_rsp @ 1400095cc =====

void evcd_process_fip_flogi_rsp
               (longlong param_1,ushort *param_2,undefined8 param_3,ulonglong param_4)

{
  byte *pbVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  pcVar2 = (char *)(param_1 + 10);
  uVar5 = 0;
  uVar4 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  uVar3 = *(short *)(param_1 + 8) << 8;
  if ((short)(*(short *)(param_1 + 0x6a) << 8) < 0) {
    if ((short)uVar3 < 0) {
      if (uVar4 == 0) {
        return;
      }
      do {
        if (*pcVar2 == '\x02') {
          pbVar1 = (byte *)(pcVar2 + 2);
          if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
            param_4 = (ulonglong)(byte)pcVar2[4];
            mm_printk("FPMA = %02x:%02x:%02x:%02x:%02x:%02x\n",(ulonglong)*pbVar1,
                      (ulonglong)(byte)pcVar2[3],param_4);
          }
          if ((uVar5 & 2) == 0) {
            mm_memcpy((void *)((longlong)param_2 + 0xb),pbVar1,6);
          }
          else {
            mm_memcpy((void *)((longlong)param_2 + 0x4f),pbVar1,6);
            *param_2 = *param_2 | 0x100;
          }
          uVar5 = uVar5 | 2;
        }
        else if (*pcVar2 == '\a') {
          if ((pcVar2[0x1c] == 1) || (pcVar2[4] != '#')) {
            if ((~FCoEDebugFlags & 1) == 0) {
              mm_printk("FLOGI status = 0x%x, FC R_CTL = 0x%x\n",(ulonglong)(byte)pcVar2[0x1c],
                        (ulonglong)(byte)pcVar2[4],param_4);
              return;
            }
            return;
          }
          *(char *)(param_2 + 2) = pcVar2[5];
          *(char *)((longlong)param_2 + 5) = pcVar2[6];
          *(char *)(param_2 + 3) = pcVar2[7];
          mm_memcpy((void *)((longlong)param_2 + 0x3f),pcVar2 + 0x38,8);
          mm_memcpy((void *)((longlong)param_2 + 0x47),pcVar2 + 0x30,8);
          uVar5 = uVar5 | 1;
        }
        pbVar1 = (byte *)(pcVar2 + 1);
        pcVar2 = pcVar2 + (ulonglong)*pbVar1 * 4;
        uVar4 = uVar4 - *pbVar1;
        if (uVar4 == 0) {
          if (uVar5 == 3) {
            *param_2 = *param_2 | 4;
            return;
          }
          return;
        }
      } while( true );
    }
    if ((~FCoEDebugFlags & 1) != 0) {
      return;
    }
    pcVar2 = "Fabric did not provide FPMA\n";
  }
  else {
    if ((~FCoEDebugFlags & 1) != 0) {
      return;
    }
    pcVar2 = "Fabric doesn\'t support Class-3\n";
  }
  mm_printk(pcVar2,(ulonglong)uVar3,param_3,param_4);
  return;
}



===== evcd_query_nx_ports @ 140009790 =====

ulonglong evcd_query_nx_ports(longlong param_1)

{
  ulonglong uVar1;
  short local_res10 [12];
  
  local_res10[0] = -1;
  uVar1 = evcd_get_dns_object(param_1,0x72,0x140009800,local_res10);
  if ((char)uVar1 == '\x01') {
    evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res10,0x1e);
    uVar1 = (ulonglong)
            CONCAT11((char)((ushort)(local_res10[0] + 0x7fffU) >> 8),
                     (ushort)(local_res10[0] + 0x7fffU) < 2);
  }
  else {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== evcd_query_nx_ports_cb @ 140009800 =====

ushort evcd_query_nx_ports_cb(longlong param_1,longlong param_2,ushort param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ushort uVar4;
  int iVar5;
  ulonglong uVar6;
  void *_Src;
  
  uVar1 = *(uint *)(param_2 + 8);
  iVar5 = param_3 - 0x18;
  if (DAT_140021670 == 0) {
    uVar4 = *(short *)(param_2 + 0x20) << 8 | (ushort)*(byte *)(param_2 + 0x21);
    lVar3 = 0x29;
    if (uVar4 == 0x8002) {
      iVar5 = param_3 - 0x28;
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    uVar4 = 0x8002;
    lVar3 = 0x19;
  }
  if (0 < iVar5) {
    _Src = (void *)(lVar3 + param_2);
    uVar6 = (ulonglong)((iVar5 - 1U >> 4) + 1);
    do {
      iVar5 = 0;
      if (*(char *)(param_1 + 0x15ae) != '\0') {
        do {
          iVar2 = mm_memcmp((char *)((longlong)_Src + 7),param_1 + 0x16d4 + (longlong)iVar5 * 0x14,8
                           );
          if (iVar2 == 0) {
            mm_memcpy((void *)(param_1 + 0x16c9 + (longlong)iVar5 * 0x14),_Src,3);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x15ae));
      }
      _Src = (void *)((longlong)_Src + 0x10);
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  DAT_140021670 = (uint)((uVar1 & 0x1800) != 0x1800);
  return uVar4;
}



===== evcd_register_dns @ 140009910 =====

ulonglong evcd_register_dns(longlong param_1,undefined8 param_2,undefined8 param_3,
                           undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  void *pvVar3;
  
  uVar1 = evcd_send_plogi(param_1,s____);
  if ((char)uVar1 == '\x01') {
    evcd_register_dns_object(param_1,0x17);
    evcd_register_dns_object(param_1,0x1f);
    evcd_register_dns_object(param_1,0x13);
    evcd_register_dns_object(param_1,0x12);
    pvVar3 = evcd_register_dns_object(param_1,0x18);
    uVar2 = CONCAT71((int7)((ulonglong)pvVar3 >> 8),1);
  }
  else {
    uVar2 = (ulonglong)~FCoEDebugFlags;
    if ((~FCoEDebugFlags & 1) == 0) {
      uVar2 = mm_printk("%s(): PLOGI failed\n","evcd_register_dns",param_3,param_4);
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== evcd_register_dns_object @ 140009988 =====

void * evcd_register_dns_object(longlong param_1,byte param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  void *pvVar3;
  ulonglong uVar4;
  undefined2 local_res10 [4];
  
  puVar2 = evcd_get_tx_fcoe_frame(param_1);
  local_res10[0] = 0xffff;
  *(undefined1 *)((longlong)puVar2 + 0x1c) = 2;
  *(undefined4 *)((longlong)puVar2 + 0x24) = 0x2920;
  mm_memcpy((void *)((longlong)puVar2 + 0x1d),s____,3);
  mm_memset((void *)((longlong)puVar2 + 0x34),0x10,0);
  *(undefined1 *)((longlong)puVar2 + 0x34) = 1;
  *(undefined2 *)(puVar2 + 7) = 0x2fc;
  *(ushort *)((longlong)puVar2 + 0x3c) = (ushort)param_2 << 8 | 2;
  pvVar3 = mm_memcpy((void *)((longlong)puVar2 + 0x45),(void *)(param_1 + 0xc14),3);
  if (param_2 == 0x12) {
    pvVar3 = (void *)(param_1 + 0xc2f);
LAB_140009a92:
    mm_memcpy(puVar2 + 9,pvVar3,8);
    uVar1 = 0x1c;
  }
  else {
    if (param_2 == 0x13) {
      pvVar3 = (void *)(param_1 + 0xc27);
      goto LAB_140009a92;
    }
    if (param_2 == 0x17) {
      *(undefined1 *)((longlong)puVar2 + 0x4a) = 1;
      uVar1 = 0x34;
    }
    else if (param_2 == 0x18) {
      uVar4 = 0xffffffffffffffff;
      do {
        uVar4 = uVar4 + 1;
      } while (*(char *)(*(longlong *)(param_1 + 0xd75) + uVar4) != '\0');
      *(char *)(puVar2 + 9) = (char)uVar4;
      mm_memcpy((void *)((longlong)puVar2 + 0x49),*(void **)(param_1 + 0xd75),(uVar4 & 0xff) + 1);
      uVar1 = *(byte *)(puVar2 + 9) + 0x15;
    }
    else {
      if (param_2 != 0x1f) goto LAB_140009af0;
      *(undefined2 *)((longlong)puVar2 + 0x4a) = 0x802;
      uVar1 = 0x18;
    }
  }
  pvVar3 = (void *)evcd_tx_fcoe_frame(param_1,puVar2,uVar1,0,local_res10,0xb);
  if (((char)pvVar3 == '\x01') &&
     (pvVar3 = (void *)evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res10,0x1e),
     (char)pvVar3 == '\x01')) {
    return pvVar3;
  }
LAB_140009af0:
  return (void *)((ulonglong)pvVar3 & 0xffffffffffffff00);
}



===== evcd_send_fip_flogi @ 140009b08 =====

void evcd_send_fip_flogi(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  puVar1 = evcd_get_tx_fip_frame(param_1,0);
  mm_memset((void *)((longlong)puVar1 + 0xe),0xa2,0);
  evcd_init_fip_hdr((undefined1 *)((longlong)puVar1 + 0xe),2,1);
  *(undefined4 *)((longlong)puVar1 + 0x14) = 0x802600;
  *(undefined2 *)(puVar1 + 3) = 0x2407;
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x22;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x2901;
  *(undefined1 *)(puVar1 + 5) = *(undefined1 *)(param_1 + 0xc17);
  *(short *)(param_1 + 0xc12) = *(short *)(param_1 + 0xc12) + 1;
  *(ushort *)((longlong)puVar1 + 0x2c) =
       (ushort)*(byte *)(param_1 + 0xc13) | *(short *)(param_1 + 0xc12) << 8;
  *(undefined2 *)((longlong)puVar1 + 0x2e) = 0xffff;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),s____,3);
  *(undefined4 *)(puVar1 + 7) = 0x12020;
  *(undefined1 *)((longlong)puVar1 + 0x34) = 4;
  *(undefined4 *)((longlong)puVar1 + 0x3c) = 0x40080;
  *(undefined4 *)((longlong)puVar1 + 0x44) = 0xd007;
  mm_memcpy(puVar1 + 9,(void *)(param_1 + 0xc2f),8);
  mm_memcpy(puVar1 + 10,(void *)(param_1 + 0xc27),8);
  *(undefined2 *)(puVar1 + 0x15) = 0x202;
  *(undefined2 *)(puVar1 + 0xf) = 0x88;
  mm_transmit_packet_raw(param_1,puVar1,0xb0,param_4);
  evcd_poll_rsp(param_1,evcd_wait_for_fip_flogi_rsp,param_1 + 0xc10,0x14);
  return;
}



===== evcd_send_plogi @ 140009c40 =====

uint evcd_send_plogi(longlong param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = *(byte *)(param_1 + 0xdad) + 1;
  if (uVar2 != 0) {
    do {
      if ((*(byte *)(param_1 + 0xc10) & 0x20) != 0) {
        return uVar2 & 0xffffff00;
      }
      sVar1 = evcd_issue_plogi(param_1,param_2);
      if (sVar1 == 2) break;
      if (sVar1 == 1) {
        mm_delay(2000000);
      }
      iVar4 = iVar4 + 1;
      uVar2 = *(byte *)(param_1 + 0xdad) + 1;
    } while (iVar4 < (int)uVar2);
  }
  iVar3 = *(byte *)(param_1 + 0xdad) + 1;
  return CONCAT31((int3)((uint)iVar3 >> 8),iVar3 != iVar4);
}



===== evcd_send_prli @ 140009cd0 =====

ulonglong evcd_send_prli(longlong param_1,void *param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  short local_res18 [4];
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  local_res18[0] = -1;
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x22;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x2901;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),param_2,3);
  mm_memset((void *)((longlong)puVar1 + 0x34),0x14,0);
  *(undefined4 *)((longlong)puVar1 + 0x34) = 0x14001020;
  *(undefined2 *)((longlong)puVar1 + 0x3a) = 0x20;
  *(undefined1 *)(puVar1 + 7) = 8;
  *(undefined4 *)((longlong)puVar1 + 0x44) = 0x22000000;
  uVar2 = evcd_tx_fcoe_frame(param_1,puVar1,0x14,0,local_res18,0xb);
  if (((char)uVar2 == '\x01') &&
     (uVar2 = evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res18,0x14), (char)uVar2 == '\x01'))
  {
    return (ulonglong)(local_res18[0] == 2);
  }
  return uVar2 & 0xffffffffffffff00;
}



===== evcd_send_scr @ 140009dac =====

ulonglong evcd_send_scr(longlong param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  short local_res10 [4];
  
  puVar1 = evcd_get_tx_fcoe_frame(param_1);
  local_res10[0] = -1;
  *(undefined1 *)((longlong)puVar1 + 0x1c) = 0x22;
  *(undefined4 *)((longlong)puVar1 + 0x24) = 0x2901;
  mm_memcpy((void *)((longlong)puVar1 + 0x1d),s____,3);
  mm_memset((void *)((longlong)puVar1 + 0x34),8,0);
  *(undefined1 *)((longlong)puVar1 + 0x34) = 0x62;
  *(undefined1 *)((longlong)puVar1 + 0x3b) = 3;
  uVar2 = evcd_tx_fcoe_frame(param_1,puVar1,8,0,local_res10,0xb);
  if (((char)uVar2 == '\x01') &&
     (uVar2 = evcd_poll_rsp(param_1,evcd_wait_for_els_rsp,local_res10,0x14), (char)uVar2 == '\x01'))
  {
    return (ulonglong)(local_res10[0] == 2);
  }
  return uVar2 & 0xffffffffffffff00;
}



===== evcd_wait_for_fip_flogi_rsp @ 140009e80 =====

byte evcd_wait_for_fip_flogi_rsp(byte *param_1)

{
  return *param_1 >> 2 & 1;
}



===== evcd_rx_fip_frame @ 140009e88 =====

void evcd_rx_fip_frame(longlong param_1,byte *param_2,undefined8 param_3,ulonglong param_4)

{
  byte *pbVar1;
  ushort *puVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  puVar2 = (ushort *)(param_1 + 0xc10);
  uVar6 = 6;
  pbVar1 = param_2 + 0xe;
  pbVar4 = param_2;
  iVar3 = mm_memcmp((char *)(param_1 + 0xc21),(longlong)param_2,6);
  if (iVar3 != 0) {
    uVar6 = 6;
    pbVar4 = param_2;
    iVar3 = mm_memcmp("\x01\x10\x18\x01",(longlong)param_2,6);
    if (iVar3 != 0) {
      if ((~(FCoEDebugFlags >> 4) & 1) == 0) {
        mm_printk("Not our FIP packet, dest MAC addr = %02x:%02x:%02x:%02x:%02x:%02x\n",
                  (ulonglong)*param_2,(ulonglong)param_2[1],(ulonglong)param_2[2]);
        return;
      }
      return;
    }
  }
  if (*pbVar1 == 0x10) {
    uVar5 = (uint)(ushort)(*(short *)(param_2 + 0x10) << 8) | (uint)param_2[0x11];
    uVar7 = (ulonglong)uVar5;
    if (uVar5 == 1) {
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        mm_printk("Recevied frame with FCOE_FIP_OPERATION_CODE_DISCOVERY\n",pbVar4,1,param_4);
      }
      if (param_2[0x13] == 2) {
        evcd_process_fip_disc_adv((longlong)pbVar1,puVar2,param_2 + 6,param_4);
      }
    }
    else if (uVar5 == 2) {
      if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
        mm_printk("Recevied frame with FCOE_FIP_OPERATION_CODE_LINK_SERVICE\n",pbVar4,2,param_4);
      }
      if (param_2[0x13] == 2) {
        evcd_process_fip_flogi_rsp((longlong)pbVar1,puVar2,uVar7,param_4);
      }
    }
    else if (uVar5 == 3) {
      if (param_2[0x13] == 2) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("Recevied frame with FCOE_FIP_SUBOCDE_CLEAR_VIRTUAL_LINKS\n",pbVar4,3,param_4);
        }
        evcd_process_fip_cvl((longlong)pbVar1,param_1);
      }
    }
    else if (uVar5 == 4) {
      if (param_2[0x13] == 2) {
        if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
          mm_printk("Recevied frame with FCOE_FIP_SUBCODE_VLAN_DISCOVERY_RESPONSE\n",pbVar4,4,
                    param_4);
        }
        evcd_process_fip_vlan_notif((longlong)pbVar1,puVar2,param_2 + 6,param_4);
      }
    }
    else if ((~(FCoEDebugFlags >> 1) & 1) == 0) {
      mm_printk("%s(): Unknown protocol code 0x%x in received FIP frame\n","evcd_rx_fip_frame",uVar7
                ,param_4);
    }
  }
  else if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("FIP header version 0x%x invalid\n",(ulonglong)*pbVar1,uVar6,param_4);
  }
  return;
}



===== evcd_tx_fka @ 14000a090 =====

void evcd_tx_fka(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 *puVar1;
  void *_Src;
  undefined8 uVar2;
  
  puVar1 = evcd_get_tx_fip_frame(param_1,0);
  evcd_init_fip_hdr((undefined1 *)((longlong)puVar1 + 0xe),3,1);
  *(undefined2 *)(puVar1 + 3) = 0x202;
  _Src = (void *)(param_1 + 0xc21);
  *(undefined2 *)((longlong)puVar1 + 0x14) = 0x200;
  uVar2 = 6;
  mm_memcpy((void *)((longlong)puVar1 + 0x1a),_Src,6);
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("Sending ENODE FKA.\n",_Src,uVar2,param_4);
  }
  uVar2 = 0x20;
  mm_transmit_packet_raw(param_1,puVar1,0x20,param_4);
  mm_device_poll(param_1,puVar1,uVar2,param_4);
  return;
}



===== evcd_tx_vn_fka @ 14000a130 =====

void evcd_tx_vn_fka(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 *puVar1;
  void *_Src;
  undefined8 uVar2;
  
  puVar1 = evcd_get_tx_fip_frame(param_1,0);
  mm_memcpy((void *)((longlong)puVar1 + 6),(void *)(param_1 + 0xc1b),6);
  evcd_init_fip_hdr((undefined1 *)((longlong)puVar1 + 0xe),3,1);
  *(undefined2 *)(puVar1 + 3) = 0x202;
  *(undefined2 *)((longlong)puVar1 + 0x14) = 0x700;
  mm_memcpy((void *)((longlong)puVar1 + 0x1a),(void *)(param_1 + 0xc21),6);
  *(undefined2 *)(puVar1 + 4) = 0x50b;
  mm_memcpy((void *)((longlong)puVar1 + 0x22),(void *)(param_1 + 0xc1b),6);
  mm_memcpy((void *)((longlong)puVar1 + 0x29),(void *)(param_1 + 0xc14),3);
  _Src = (void *)(param_1 + 0xc2f);
  uVar2 = 8;
  mm_memcpy((void *)((longlong)puVar1 + 0x2c),_Src,8);
  if ((~(FCoEDebugFlags >> 2) & 1) == 0) {
    mm_printk("Sending VN_Port FKA.\n",_Src,uVar2,param_4);
  }
  uVar2 = 0x34;
  mm_transmit_packet_raw(param_1,puVar1,0x34,param_4);
  mm_device_poll(param_1,puVar1,uVar2,param_4);
  return;
}



===== _guard_dispatch_icall @ 14000a240 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 14000a280 =====

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



===== memmove @ 14000a380 =====

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
        if (uVar12 == 0) goto LAB_14000a537;
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
LAB_14000a537:
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
      if (uVar12 == 0) goto LAB_14000a392;
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
LAB_14000a392:
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



===== DriverEntry @ 140023000 =====

void DriverEntry(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  char *pcVar1;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_80;
  undefined1 local_7c;
  code *local_60;
  code *local_58;
  undefined4 local_1c;
  undefined4 local_18;
  
  pcVar1 = (char *)0xd0;
  memset(&local_d8,0,0xd0);
  if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
    mm_printk("%s() : ************************************************************************************\n"
              ,"DriverEntry",pcVar1,param_4);
  }
  if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
    param_4 = &s_8_42_2_100;
    pcVar1 = "qefcd.sys";
    mm_printk("%s() : binary %s version %s timestamp %s %s\n","DriverEntry","qefcd.sys",
              &s_8_42_2_100);
  }
  if ((~(FCoEDebugFlags >> 5) & 1) == 0) {
    mm_printk("%s() : ************************************************************************************\n"
              ,"DriverEntry",pcVar1,param_4);
  }
  local_d4 = 0;
  local_d0 = evcd_initialize_adapter;
  local_d8 = 0xd0;
  local_c8 = evcd_start_io;
  local_98 = 0x16f0;
  local_c0 = evcd_isr;
  local_80 = 0x1010103;
  local_b8 = evcd_find_adapter;
  local_7c = 1;
  local_b0 = evcd_reset_bus;
  local_60 = evcd_adapter_control;
  local_58 = evcd_build_io;
  local_1c = 1;
  local_18 = 1;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== entry @ 140023160 =====

void entry(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 14002318c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140020010) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


