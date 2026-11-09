
===== CrashDumpAdapterControl @ 140001000 =====

undefined8 CrashDumpAdapterControl(void)

{
  return 0;
}



===== CrashDumpBringUpAdapter @ 140001004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CrashDumpBringUpAdapter(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = (*(code *)l2_driver_intf[0xb])(*l2_driver_intf);
  if (iVar1 == 0) {
    uVar2 = 1;
    (*(code *)l2_driver_intf[7])
              (*l2_driver_intf,
               *(longlong *)
                (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) + 0x12);
    (*(code *)l2_driver_intf[8])
              (*l2_driver_intf,
               *(longlong *)
                (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) + 0x12);
    iVar1 = (*(code *)l2_driver_intf[10])(*l2_driver_intf);
    if (iVar1 == 4) {
      return 0;
    }
    kd_print("dev %p link NOT active!!!\n",*l2_driver_intf,uVar2,param_4);
    (*(code *)l2_driver_intf[0xc])(*l2_driver_intf);
  }
  else {
    kd_print("dev %p init failed!!!\n",*l2_driver_intf,param_3,param_4);
  }
  return 0xffffffff;
}



===== CrashDumpBuildIo @ 1400010f0 =====

undefined1 CrashDumpBuildIo(void)

{
  return 1;
}



===== CrashDumpExecuteiSCSICommand @ 1400010f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char CrashDumpExecuteiSCSICommand(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  
  cVar2 = '\x06';
  if_log_scsi_cmd((uint)*(byte *)(param_2 + 0x48));
  bVar1 = *(byte *)(param_2 + 0x48);
  if (bVar1 < 0x26) {
    if (bVar1 == 0x25) {
      uVar3 = CrashDumpFcoeDoReadCapacity(param_1,param_2);
      cVar2 = (char)uVar3;
    }
    else if (bVar1 == 0) {
      uVar3 = CrashDumpFcoeDoTUR(param_1,param_2);
      cVar2 = (char)uVar3;
    }
    else if (bVar1 == 3) {
      uVar3 = CrashDumpFcoeDoReadCapacity(param_1,param_2);
      cVar2 = (char)uVar3;
    }
    else {
      if (bVar1 == 8) goto LAB_1400011c0;
      if (bVar1 != 0x12) {
        if (bVar1 == 0x1b) {
          return '\x01';
        }
        goto LAB_1400011d1;
      }
      uVar3 = CrashDumpFcoeDoReadCapacity(param_1,param_2);
      cVar2 = (char)uVar3;
    }
  }
  else if (bVar1 == 0x28) {
LAB_1400011c0:
    uVar3 = CrashDumpFcoeDoReadCapacity(param_1,param_2);
    cVar2 = (char)uVar3;
  }
  else {
    if (bVar1 == 0x2a) {
      uVar3 = CrashDumpFcoeDoSyncCache(param_1,param_2);
      cVar2 = (char)uVar3;
      if (cVar2 == '\x01') {
        _DAT_1400202b8 = _DAT_1400202b8 + 1;
        _DAT_1400202bc = _DAT_1400202bc + *(int *)(param_2 + 0x10);
        return '\x01';
      }
      goto LAB_1400011d1;
    }
    if (bVar1 == 0x2f) {
      uVar3 = CrashDumpFcoeDoSyncCache(param_1,param_2);
      cVar2 = (char)uVar3;
    }
    else {
      if (bVar1 != 0x35) goto LAB_1400011d1;
      uVar3 = CrashDumpFcoeDoSyncCache(param_1,param_2);
      cVar2 = (char)uVar3;
    }
  }
  if (cVar2 == '\x01') {
    return '\x01';
  }
LAB_1400011d1:
  _DAT_1400202d0 = 0;
  _DAT_1400202cc = 0;
  _DAT_1400202c8 = (uint)*(byte *)(param_2 + 0x48);
  _DAT_1400202c4 = 0xc0000002;
  return cVar2;
}



===== CrashDumpExtractFcoeInfo @ 140001208 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CrashDumpExtractFcoeInfo
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  
  kd_print(&s_CrashDumpExtractFcoeInfo_called,param_2,param_3,param_4);
  DAT_14001ff40 = 1;
  _DAT_14001ff4e = *(undefined2 *)(param_1 + 0x14);
  lVar4 = 2;
  _DAT_14001ff98 = *(undefined8 *)(param_1 + 0x1c);
  _DAT_14001ffa0 = *(undefined8 *)(param_1 + 0x24);
  uVar8 = 0x80;
  puVar2 = (undefined8 *)(param_1 + 0x30);
  puVar3 = (undefined8 *)&DAT_14001ffa8;
  do {
    uVar6 = puVar2[1];
    *puVar3 = *puVar2;
    puVar3[1] = uVar6;
    uVar6 = puVar2[3];
    puVar3[2] = puVar2[2];
    puVar3[3] = uVar6;
    uVar6 = puVar2[5];
    puVar3[4] = puVar2[4];
    puVar3[5] = uVar6;
    uVar6 = puVar2[7];
    puVar3[6] = puVar2[6];
    puVar3[7] = uVar6;
    uVar6 = puVar2[9];
    puVar3[8] = puVar2[8];
    puVar3[9] = uVar6;
    uVar6 = puVar2[0xb];
    puVar3[10] = puVar2[10];
    puVar3[0xb] = uVar6;
    uVar6 = puVar2[0xd];
    puVar3[0xc] = puVar2[0xc];
    puVar3[0xd] = uVar6;
    puVar1 = puVar2 + 0xe;
    uVar6 = puVar2[0xf];
    puVar2 = puVar2 + 0x10;
    puVar3[0xe] = *puVar1;
    puVar3[0xf] = uVar6;
    lVar4 = lVar4 + -1;
    puVar3 = puVar3 + 0x10;
  } while (lVar4 != 0);
  DAT_140020036 = DAT_140020036 | 2;
  DAT_1400200d6 = 1;
  _DAT_140020037 = *(undefined8 *)(param_1 + 0x130);
  _DAT_14002003f = *(undefined8 *)(param_1 + 0x138);
  kd_print(&s__Dump_target_information,0,0x80,param_4);
  kd_print(&s___Initiator,lVar4,uVar8,param_4);
  kd_print(&s_____MAC_Address__,lVar4,uVar8,param_4);
  lVar7 = 0;
  lVar4 = 0;
  do {
    uVar5 = (ulonglong)*(byte *)(param_1 + 0x16 + lVar4);
    kd_print(&s__02x_,uVar5,uVar8,param_4);
    lVar4 = lVar4 + 1;
  } while (lVar4 < 6);
  kd_print("\n\t\t Port WWN: ",uVar5,uVar8,param_4);
  lVar4 = 0;
  do {
    uVar5 = (ulonglong)*(byte *)(param_1 + 0x24 + lVar4);
    kd_print(&s__02x_,uVar5,uVar8,param_4);
    lVar4 = lVar4 + 1;
  } while (lVar4 < 8);
  kd_print("\n\t\t Node WWN: ",uVar5,uVar8,param_4);
  lVar4 = 0;
  do {
    kd_print(&s__02x_,(ulonglong)*(byte *)(param_1 + 0x1c + lVar4),uVar8,param_4);
    lVar4 = lVar4 + 1;
  } while (lVar4 < 8);
  kd_print("\n\t\t Port Symbolic Name: %s",param_1 + 0x30,uVar8,param_4);
  kd_print(&s_____PCIBusDevFunc___x,(ulonglong)*(ushort *)(param_1 + 0x14),uVar8,param_4);
  kd_print(&s_____PCIBusDevFunc___x,(ulonglong)*(ushort *)(param_1 + 0x14),uVar8,param_4);
  kd_print("\n\t\t VLAN: %x",(ulonglong)*(ushort *)(param_1 + 0x2c),uVar8,param_4);
  kd_print("\n\t\t GRCRegisterBase: 0x%p",*(undefined8 *)(param_1 + 4),uVar8,param_4);
  uVar6 = *(undefined8 *)(param_1 + 0xc);
  kd_print("\n\t\t DoorbellRegisterBase: 0x%p",uVar6,uVar8,param_4);
  kd_print("\n\tTarget",uVar6,uVar8,param_4);
  kd_print("\n\t\t Port WWN: ",uVar6,uVar8,param_4);
  lVar4 = 0;
  do {
    uVar5 = (ulonglong)*(byte *)(lVar4 + 0x130 + param_1);
    kd_print(&s__02x_,uVar5,uVar8,param_4);
    lVar4 = lVar4 + 1;
  } while (lVar4 < 8);
  kd_print("\n\t\t Boot LUN: ",uVar5,uVar8,param_4);
  do {
    uVar5 = (ulonglong)*(byte *)(param_1 + 0x138 + lVar7);
    kd_print(&s__02x_,uVar5,uVar8,param_4);
    lVar7 = lVar7 + 1;
  } while (lVar7 < 8);
  kd_print(&s__,uVar5,uVar8,param_4);
  return;
}



===== CrashDumpFcoeDoReadCapacity @ 140001450 =====

undefined8 CrashDumpFcoeDoReadCapacity(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = fcbSessionSendScsiCdb
                    (2,(void *)(param_2 + 0x48),(ushort)*(byte *)(param_2 + 10),
                     *(longlong *)(param_2 + 0x18),*(uint *)(param_2 + 0x10),
                     *(longlong *)(param_2 + 0x20),(ushort)*(byte *)(param_2 + 0xb));
  uVar1 = (ulonglong)CONCAT31((int3)((uint)-(int)uVar1 >> 8),-((int)uVar1 != 0)) &
          0xffffffffffffff03;
  return CONCAT71((int7)(uVar1 >> 8),(char)uVar1 + '\x01');
}



===== CrashDumpFcoeDoSyncCache @ 140001494 =====

undefined8 CrashDumpFcoeDoSyncCache(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = fcbSessionSendScsiCdb
                    (1,(void *)(param_2 + 0x48),(ushort)*(byte *)(param_2 + 10),
                     *(longlong *)(param_2 + 0x18),*(uint *)(param_2 + 0x10),
                     *(longlong *)(param_2 + 0x20),(ushort)*(byte *)(param_2 + 0xb));
  uVar1 = (ulonglong)CONCAT31((int3)((uint)-(int)uVar1 >> 8),-((int)uVar1 != 0)) &
          0xffffffffffffff03;
  return CONCAT71((int7)(uVar1 >> 8),(char)uVar1 + '\x01');
}



===== CrashDumpFcoeDoTUR @ 1400014d8 =====

undefined8 CrashDumpFcoeDoTUR(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = fcbSessionSendScsiCdb
                    (0,(void *)(param_2 + 0x48),(ushort)*(byte *)(param_2 + 10),
                     *(longlong *)(param_2 + 0x18),*(uint *)(param_2 + 0x10),
                     *(longlong *)(param_2 + 0x20),(ushort)*(byte *)(param_2 + 0xb));
  uVar1 = (ulonglong)CONCAT31((int3)((uint)-(int)uVar1 >> 8),-((int)uVar1 != 0)) &
          0xffffffffffffff03;
  return CONCAT71((int7)(uVar1 >> 8),(char)uVar1 + '\x01');
}



===== CrashDumpFindAdapter @ 140001520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CrashDumpFindAdapter
          (void *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,undefined4 *param_5)

{
  ushort uVar1;
  ushort *puVar2;
  uint *puVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  char *pcVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong local_res8;
  
  OurAdapter = param_1;
  kd_print("CrashDumpFindAdapter:Adapter = %p\n",param_1,param_3,param_4);
  if (CrashDumpDriverInitialized == '\x01') {
    return 0;
  }
  uVar9 = 0;
  lVar11 = 0x158;
  memset(param_1,0,0x158);
  puVar2 = *(ushort **)(param_5 + 0x10);
  *(undefined4 *)((longlong)param_1 + 0x150) = 1;
  if (*puVar2 == 2) {
    if (*(longlong *)(puVar2 + 2) == 0) {
      pcVar8 = "CrashDumpFindAdater: Initiator mapping is NULL. Exiting!\n";
    }
    else {
      *(longlong *)((longlong)param_1 + 0x128) = *(longlong *)(puVar2 + 2);
      *(undefined1 *)((longlong)param_1 + 0x130) = 0xff;
      uVar10 = 0xdeadbeef;
      *(ushort **)((longlong)param_1 + 8) = puVar2;
      *(undefined1 *)((longlong)param_1 + 0x148) = 0xff;
      if (**(int **)(puVar2 + 2) == -1) {
        *(undefined1 *)((longlong)param_1 + 0x130) = 1;
      }
      else {
        puVar3 = *(uint **)((longlong)param_1 + 0x128);
        if (puVar3 == (uint *)0x0) {
          uVar7 = 0xffffffff;
        }
        else {
          uVar7 = *puVar3;
          if ((short)uVar7 != 0x14e4) {
            uVar7 = puVar3[0x800];
          }
        }
        uVar9 = (ulonglong)(uVar7 >> 0x10);
        uVar6 = fcbIsSupportedAdapter((short)uVar7,(short)(uVar7 >> 0x10));
        if ((char)uVar6 != '\0') {
          puVar3 = *(uint **)((longlong)param_1 + 0x128);
          *(undefined1 *)((longlong)param_1 + 0x131) = 1;
          if (puVar3 == (uint *)0x0) {
            uVar10 = 0xffffffff;
          }
          else {
            uVar10 = *puVar3;
            if ((short)uVar10 != 0x14e4) {
              uVar10 = puVar3[0x800];
            }
          }
        }
      }
      if (*(char *)((longlong)param_1 + 0x131) == '\0') {
        kd_print("no brcm device found\n",uVar9,lVar11,param_4);
        return 0;
      }
      param_5[0xc] = 0;
      param_5[0x22] = 0;
      param_5[0x23] = 0;
      param_5[0x25] = 0;
      *(undefined8 *)(param_5 + 0x26) = 0;
      param_5[0x28] = 0;
      *param_5 = 0xe0;
      param_5[6] = 0x10000;
      *(undefined1 *)(param_5 + 0x12) = 1;
      *(undefined2 *)((longlong)param_5 + 0x51) = 0x101;
      *(undefined1 *)((longlong)param_5 + 0x53) = 0;
      *(undefined1 *)((longlong)param_5 + 0x59) = 2;
      *(undefined1 *)((longlong)param_5 + 0x61) = 1;
      param_5[0x21] = 0x158;
      *(undefined2 *)((longlong)param_5 + 0x91) = 0xff01;
      uVar9 = (ulonglong)(uVar10 >> 0x10);
      fcbGlobalsPtr = &fcbContext;
      uVar5 = mm_basic_initialize((char *)((longlong)param_1 + 0x20),(short)(uVar10 >> 0x10));
      if ((int)uVar5 != 0) {
        return 0;
      }
      l2_driver_intf = (longlong)OurAdapter + 0x28;
      if (*(longlong *)((longlong)param_1 + 0x100) == 0) {
        if (l2_driver_intf == 0) {
          iVar4 = mm_get_largest_dma_length();
        }
        else {
          iVar4 = (**(code **)((longlong)OurAdapter + 0x50))();
        }
        lVar11 = StorPortGetUncachedExtension(param_1,param_5,iVar4);
        *(longlong *)((longlong)param_1 + 0x100) = lVar11;
        if (lVar11 == 0) {
          return 2;
        }
        param_4 = (longlong)param_1 + 0x110;
        uVar9 = 0;
        local_res8 = StorPortGetPhysicalAddress(param_1);
      }
      if ((local_res8 & 0x3f) != 0) {
        *(uint *)((longlong)param_1 + 0x118) = (-(int)local_res8 - 1U & 0x3f) + 1;
      }
      *(int *)((longlong)param_1 + 0x108) = (int)local_res8;
      *(int *)((longlong)param_1 + 0x10c) = (int)(local_res8 >> 0x20);
      mm_free_all_resources();
      uVar1 = puVar2[10];
      *(uint *)((longlong)param_1 + 0x124) = (uint)(uVar1 >> 8);
      *(uint *)((longlong)param_1 + 0x120) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
      uVar6 = CrashDumpInitializeAdapter((longlong)param_1,uVar9,lVar11,param_4);
      if ((char)uVar6 == '\x01') {
        CrashDumpDriverInitialized = '\x01';
        return 1;
      }
      pcVar8 = "InitializeAdapter() Failed\n";
    }
    kd_print(pcVar8,uVar9,lVar11,param_4);
  }
  else {
    kd_print("CrashDumpFindAdater: Verison mismatch for miniport mappings. Expected %d, got %d. Exiting!\n"
             ,2,(ulonglong)*puVar2,param_4);
  }
  return 2;
}



===== CrashDumpInitialize @ 1400017f0 =====

undefined1 CrashDumpInitialize(undefined8 param_1)

{
  StorPortNotification(3,param_1);
  return 1;
}



===== CrashDumpInitializeAdapter @ 14000180c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashDumpInitializeAdapter
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  
  kd_print("CrashDumpInitializeAdapter():\n",param_2,param_3,param_4);
  *(undefined2 *)(fcbGlobalsPtr + 0xe10) = 5000;
  *(undefined1 *)(fcbGlobalsPtr + 0xe17) = 1;
  uVar7 = fcbGlobalsPtr;
  *(ulonglong *)(fcbGlobalsPtr + 0xe30) = fcbGlobalsPtr + 0xe40;
  *(undefined1 *)(fcbGlobalsPtr + 0xe40) = 1;
  CrashDumpExtractFcoeInfo(*(longlong *)(param_1 + 8),uVar7,param_3,param_4);
  *(undefined1 *)(fcbGlobalsPtr + 0xe2c) = 0;
  uVar8 = (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c);
  pcVar2 = *(char **)(fcbGlobalsPtr + 0xe30 + uVar8 * 8);
  uVar7 = fcbGlobalsPtr;
  if (*pcVar2 == '\0') goto LAB_140001b35;
  uVar1 = *(ushort *)(pcVar2 + 0xe);
  *(uint *)(param_1 + 0x124 + uVar8 * 0x18) = (uint)(uVar1 >> 8);
  *(uint *)(param_1 + 0x120 + uVar8 * 0x18) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
  uVar7 = *(longlong *)(fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) +
          0xe;
  iVar4 = (*(code *)l2_driver_intf[0x15])(*(undefined8 *)(OurAdapter + 0x28));
  if (iVar4 == 0) {
    if (*(char *)(param_1 + 0x130) == '\x01') {
      uVar5 = get_device_to_d0_if_necessary
                        (*(ushort *)
                          (*(longlong *)
                            (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8
                            ) + 0xe),uVar7,uVar8,param_4);
      if ((int)uVar5 == 0) {
        puVar3 = *(uint **)(param_1 + 0x128);
        if (puVar3 == (uint *)0x0) {
          uVar6 = 0xffffffff;
        }
        else {
          uVar6 = *puVar3;
          if ((short)uVar6 != 0x14e4) {
            uVar6 = puVar3[0x800];
          }
        }
        uVar7 = (ulonglong)(uVar6 >> 0x10);
        uVar5 = fcbIsSupportedAdapter((short)uVar6,(short)(uVar6 >> 0x10));
        if ((char)uVar5 != '\0') goto LAB_1400019ba;
      }
      kd_print("skip this device\n",uVar7,uVar8,param_4);
    }
  }
  else {
    uVar8 = (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c);
    uVar1 = *(ushort *)(*(longlong *)(fcbGlobalsPtr + 0xe30 + uVar8 * 8) + 0xe);
    *(uint *)(param_1 + 0x124 + uVar8 * 0x18) = (uint)(uVar1 >> 8);
    *(uint *)(param_1 + 0x120 + uVar8 * 0x18) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
  }
LAB_1400019ba:
  kd_print("Bringing up i/f at pfn %x\n",
           (ulonglong)
           *(ushort *)
            (*(longlong *)(fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8)
            + 0xe),uVar8,param_4);
  uVar5 = 0;
  uVar9 = 0x68;
  uVar1 = *(ushort *)
           (*(longlong *)(fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) +
           0xe);
  memset(&g_if_stats,0,0x68);
  _g_if_stats = *(undefined8 *)(OurAdapter + 0x28);
  _DAT_1400202a8 = 0xffffffff;
  _DAT_1400202b0 = (uint)uVar1;
  uVar5 = CrashDumpBringUpAdapter(param_1,uVar5,uVar9,param_4);
  if ((int)uVar5 == 0) {
    _DAT_1400202a8 = DAT_1400202ac;
    DAT_1400202ac = 1;
    DAT_140020304 = 0xc;
    uVar7 = (ulonglong)
            *(ushort *)
             (*(longlong *)(fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8)
             + 0xe);
    kd_print("Logging in from i/f at pfn %x\n",uVar7,uVar9,param_4);
    uVar5 = CrashDumpLogonTarget(param_1,uVar7,uVar9,param_4);
    if ((char)uVar5 == '\0') {
      if (DAT_14001e918 != '\0') {
        uVar5 = fcbInitTimer();
      }
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
    fcbInitTimer();
    _DAT_1400202cc = 0;
    _DAT_1400202d0 = 0;
    _DAT_1400202c4 = 0xc0000003;
    _DAT_1400202c8 =
         (uint)*(ushort *)
                (*(longlong *)
                  (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) + 0xe);
    (*(code *)l2_driver_intf[0xc])(*l2_driver_intf);
  }
  else {
    _DAT_1400202cc = 0;
    _DAT_1400202d0 = 0;
    _DAT_1400202c4 = 0xc0000001;
    _DAT_1400202c8 =
         (uint)*(ushort *)
                (*(longlong *)
                  (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) + 0xe);
  }
  uVar7 = mm_free_all_resources();
LAB_140001b35:
  return uVar7 & 0xffffffffffffff00;
}



===== CrashDumpIsr @ 140001b50 =====

undefined1 CrashDumpIsr(void)

{
  return 0;
}



===== CrashDumpLogonTarget @ 140001b54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
CrashDumpLogonTarget(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ushort *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 auStack_2d8 [32];
  undefined1 local_2b8 [16];
  byte local_2a8 [3];
  undefined1 local_2a5;
  undefined2 local_29e;
  undefined4 local_298;
  undefined1 *local_290;
  undefined1 *local_288;
  undefined1 local_260;
  undefined4 local_25e;
  undefined2 local_259;
  undefined1 local_248 [32];
  undefined1 local_228 [512];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2d8;
  kd_print("Start: CrashDumpLogonTarget\n",param_2,param_3,param_4);
  memset(fcbGlobalsPtr,0,0x210);
  fcbInit();
  puVar7 = local_2b8;
  _DAT_1400202a8 = DAT_1400202ac;
  uVar4 = 0;
  DAT_1400202ac = 0x10001;
  DAT_140020304 = 0xc;
  iVar1 = (*(code *)l2_driver_intf[0xe])(*l2_driver_intf);
  if (iVar1 == 0) {
    _DAT_1400202a8 = DAT_1400202ac;
    DAT_1400202ac = 0x10002;
    DAT_140020304 = 0xc;
    *(undefined1 *)(fcbGlobalsPtr + 0x30) = local_2b8[0];
    fcbGlobalsPtr[0xd6] = 4;
    *(undefined8 *)((longlong)fcbGlobalsPtr + 0x19) =
         *(undefined8 *)
          (*(longlong *)(fcbGlobalsPtr + (ulonglong)(byte)fcbGlobalsPtr[0x716] * 4 + 0x718) + 0x58);
    *(undefined8 *)((longlong)fcbGlobalsPtr + 0x21) =
         *(undefined8 *)
          (*(longlong *)(fcbGlobalsPtr + (ulonglong)(byte)fcbGlobalsPtr[0x716] * 4 + 0x718) + 0x60);
    puVar2 = fcbGlobalsPtr;
    *(longlong *)(fcbGlobalsPtr + 0xf8) =
         *(longlong *)(fcbGlobalsPtr + (ulonglong)(byte)fcbGlobalsPtr[0x716] * 4 + 0x718) + 0x68;
    (*(code *)l2_driver_intf[0xd])(*l2_driver_intf);
    kd_print("Attempting to login to fabric\n",puVar2,uVar4,param_4);
    uVar9 = 0;
    do {
      kd_print("*** Starting DiscoverFabric: %d ***\n",(ulonglong)uVar9,uVar4,param_4);
      uVar3 = fcbDiscoverFabric();
      if ((int)uVar3 == 0) {
        kd_print("Fabric discovered ok, rty_cnt %d\n",(ulonglong)uVar9,uVar4,param_4);
        _DAT_1400202a8 = DAT_1400202ac;
        DAT_1400202ac = 0x10003;
        _fcb_debug = 0;
        _dbg_trace = 0;
        DAT_140020304 = 0xc;
        break;
      }
      if ((uVar9 == 7) && ((dbg_ctl & 2) != 0)) {
        uVar9 = 0;
        kd_print("FAB discover failed %d times, resetting to 0\n",8,uVar4,param_4);
      }
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < 8);
    if (uVar9 == 8) {
      kd_print("FAB discover failed %d times",8,uVar4,param_4);
      _DAT_1400202cc = (uint)fcbGlobalsPtr[0xd6];
      _DAT_1400202c4 = 0xc0010003;
      _DAT_1400202c8 = 8;
      puVar2 = fcbGlobalsPtr;
    }
    else {
      (*(code *)l2_driver_intf[0xf])(*l2_driver_intf,&s_____);
      puVar2 = fcbGlobalsPtr + 6;
      (*(code *)l2_driver_intf[0x11])(*l2_driver_intf);
      (*(code *)l2_driver_intf[0xd])(*l2_driver_intf);
      uVar3 = fcbDoFabricLogin(fcbGlobalsPtr);
      if ((int)uVar3 == 0) {
        _DAT_1400202a8 = DAT_1400202ac;
        DAT_1400202ac = 0x10004;
        DAT_140020304 = 0xc;
        kd_print("Fabric login success, %d targets\n",
                 (ulonglong)
                 *(byte *)(*(longlong *)
                            (fcbGlobalsPtr + (ulonglong)(byte)fcbGlobalsPtr[0x716] * 4 + 0x718) +
                          0x196),uVar4,param_4);
        uVar9 = 0;
        lVar10 = 0;
        do {
          uVar5 = (ulonglong)
                  *(byte *)(*(longlong *)
                             (fcbGlobalsPtr + (ulonglong)(byte)fcbGlobalsPtr[0x716] * 4 + 0x718) +
                           0x196);
          kd_print("logining into target %d of %d\n",(ulonglong)uVar9,uVar5,param_4);
          puVar2 = (ushort *)(ulonglong)(byte)fcbGlobalsPtr[0x716];
          pbVar8 = (byte *)(*(longlong *)(fcbGlobalsPtr + (longlong)puVar2 * 4 + 0x718) + 0xf6 +
                           lVar10);
          if ((*pbVar8 & 2) != 0) {
            iVar1 = fcbDoLoginToTarget((longlong)fcbGlobalsPtr,(longlong)pbVar8);
            if (iVar1 == 0) {
              iVar1 = scsi_io_send_tur(param_1);
              if (iVar1 == 0) {
                kd_print("TUR successful\n",pbVar8,uVar5,param_4);
                iVar1 = 0;
                do {
                  uVar5 = 0x58;
                  memset(local_2a8,0,0x58);
                  local_29e = 0x120a;
                  local_2a8[0] = 0x58;
                  local_2a8[1] = 0;
                  pbVar8 = local_2a8;
                  local_288 = local_248;
                  local_2a5 = 0;
                  local_290 = local_228;
                  local_260 = 0x28;
                  local_298 = 0x200;
                  local_25e = 0;
                  local_259 = 0x100;
                  uVar4 = CrashDumpFcoeDoReadCapacity(param_1,(longlong)pbVar8);
                  if ((char)uVar4 != '\x01') {
                    pcVar6 = "TARGET NOT READY LBA0\n";
                    goto LAB_140001f73;
                  }
                  iVar1 = iVar1 + 1;
                } while (iVar1 < 5);
                iVar1 = 0;
                pcVar6 = "5 READY LBA0\n";
              }
              else {
                pcVar6 = "TARGET NOT READY TUR\n";
LAB_140001f73:
                iVar1 = -1;
              }
              kd_print(pcVar6,pbVar8,uVar5,param_4);
              if (iVar1 == 0) {
                kd_print(&s_Logged_into_target__d_,(ulonglong)uVar9,uVar5,param_4);
                uVar5 = (ulonglong)DAT_1400202ac;
                _DAT_1400202a8 = DAT_1400202ac;
                DAT_1400202ac = 0x10005;
                DAT_140020304 = 0xc;
                if (DAT_14001e918 != '\0') {
                  uVar5 = (*(code *)l2_driver_intf[0x14])(*l2_driver_intf,0x54464642);
                }
                return uVar5 & 0xffffffffffffff00;
              }
            }
            puVar2 = (ushort *)kd_print(&s_No_login_target__try_next____,pbVar8,uVar5,param_4);
          }
          uVar9 = uVar9 + 1;
          lVar10 = lVar10 + 0x14;
        } while ((int)uVar9 < 2);
        _DAT_1400202c4 = 0xc0010005;
        _DAT_1400202cc = 0;
        _DAT_1400202d0 = 0;
        _DAT_1400202c8 = uVar9;
        goto LAB_140001fb1;
      }
      puVar2 = (ushort *)kd_print("Fracric Login failure\n",puVar2,uVar4,param_4);
      _DAT_1400202c4 = 0xc0010004;
      _DAT_1400202c8 = 0;
      _DAT_1400202cc = 0;
    }
    _DAT_1400202d0 = 0;
  }
  else {
    _DAT_1400202c4 = 0xc0010002;
    _DAT_1400202c8 = 0;
    _DAT_1400202cc = 0;
    _DAT_1400202d0 = 0;
    puVar2 = (ushort *)kd_print(&s_dcb_init_failure_,puVar7,uVar4,param_4);
  }
LAB_140001fb1:
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),0xff);
}



===== CrashDumpResetBus @ 140002040 =====

undefined1 CrashDumpResetBus(undefined8 param_1,undefined8 param_2)

{
  StorPortCompleteRequest(param_1,param_2,0xff,0xff,0xe);
  StorPortNotification(1,param_1);
  return 1;
}



===== CrashDumpStartIo @ 140002070 =====

undefined1 CrashDumpStartIo(undefined8 param_1,longlong param_2)

{
  char cVar1;
  
  cVar1 = '\x06';
  if (*(char *)(param_2 + 2) == '\0') {
    cVar1 = CrashDumpExecuteiSCSICommand(param_1,param_2);
  }
  else if (*(char *)(param_2 + 2) == '\a') {
    if (DAT_14001e918 != '\0') {
      fcbUnInitTimer();
    }
    cVar1 = '\x01';
  }
  *(char *)(param_2 + 3) = cVar1;
  StorPortNotification(0,param_1,param_2);
  StorPortNotification(1,param_1);
  return 1;
}



===== cd_finit_55ms_timer @ 1400020d4 =====

void cd_finit_55ms_timer(void)

{
  if (DAT_14001e918 != '\0') {
    StorPortNotification(6,OurAdapter,timer_55ms);
  }
  return;
}



===== cd_init_55ms_timer @ 140002100 =====

void cd_init_55ms_timer(void)

{
  if (DAT_14001e918 != '\0') {
    StorPortNotification(6,OurAdapter,timer_55ms);
  }
  return;
}



===== fcbGetTicks @ 140002130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbGetTicks(void)

{
  (*(code *)l2_driver_intf[0x13])(*l2_driver_intf);
  return;
}



===== fcbL2CfgVlanMode @ 140002148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbL2CfgVlanMode(undefined2 param_1,undefined1 param_2)

{
  (*(code *)l2_driver_intf[0x12])(*l2_driver_intf,param_1,param_2);
  return;
}



===== fcbL2Send @ 14000216c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbL2Send(undefined8 param_1,undefined2 param_2)

{
  (**(code **)(l2_driver_intf + 0x20))(*(undefined8 *)(OurAdapter + 0x28),param_1,param_2);
  return;
}



===== fcbPollNetwork @ 140002190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 fcbPollNetwork(undefined *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3 * 1000;
  iVar1 = (*(code *)l2_driver_intf[0x13])(*l2_driver_intf);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    iVar2 = (*(code *)l2_driver_intf[0x13])(*l2_driver_intf);
    if (iVar1 != iVar2) {
      iVar1 = (*(code *)l2_driver_intf[0x13])(*l2_driver_intf);
      iVar3 = iVar3 + -1;
    }
    fcbProcessLoop(1);
  } while ((param_1 == (undefined *)0x0) || (iVar2 = (*(code *)param_1)(param_2), iVar2 == 0));
  return 1;
}



===== fcbProcessLoop @ 140002244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbProcessLoop(ushort param_1)

{
  fcbServiceTicks();
  if ((param_1 & 1) != 0) {
    (*(code *)l2_driver_intf[9])(*l2_driver_intf);
  }
  fcbServiceTimer();
  return;
}



===== fcbServiceTicks @ 14000227c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fcbServiceTicks(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(code *)l2_driver_intf[0x13])(*l2_driver_intf);
  if ((DAT_14001e91c == 0) || (uVar1 != DAT_14001e91c)) {
    if (DAT_14001e91c < uVar1) {
      uVar2 = uVar1 - DAT_14001e91c;
    }
    else {
      uVar2 = DAT_14001e91c - uVar1;
    }
    if (1000 < uVar2) {
      uVar2 = 1;
    }
    _system_ticks = _system_ticks + uVar2;
    DAT_14001e91c = uVar1;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      fcbTimerTick();
    }
  }
  return;
}



===== if_log_scsi_cmd @ 1400022e4 =====

void if_log_scsi_cmd(undefined4 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar1 = DAT_140020304;
  bVar3 = DAT_140020304 == 0xc;
  if (bVar3) {
    DAT_140020304 = 0;
  }
  uVar2 = 0;
  if (!bVar3) {
    uVar2 = (ulonglong)uVar1;
  }
  (&DAT_1400202d4)[uVar2] = param_1;
  DAT_140020304 = DAT_140020304 + 1;
  return;
}



===== kd_print @ 14000230c =====

void kd_print(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(DAT_140017000,DAT_140017004,param_1,&local_res10);
  return;
}



===== scsi_io_send_tur @ 140002344 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int scsi_io_send_tur(undefined8 param_1)

{
  char cVar1;
  undefined1 auStack_a8 [32];
  undefined2 local_88;
  undefined1 local_85;
  undefined2 local_7e;
  undefined1 *local_68;
  undefined2 local_40;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(&local_88,0,0x58);
  local_88 = 0x58;
  local_85 = 0;
  local_40 = 0;
  local_68 = local_28;
  local_7e = 0x120a;
  cVar1 = CrashDumpExecuteiSCSICommand(param_1,(longlong)&local_88);
  return -(uint)(cVar1 != '\x01');
}



===== swap_dword @ 1400023d8 =====

uint swap_dword(uint param_1)

{
  return param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



===== timer_55ms @ 1400023e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void timer_55ms(void)

{
  bool bVar1;
  int *piVar2;
  longlong lVar3;
  
  bVar1 = false;
  piVar2 = &DAT_14001e928;
  _system_ticks = _system_ticks + 1;
  lVar3 = 8;
  do {
    if (((short)piVar2[-2] == 1) && (*piVar2 = *piVar2 + 1, piVar2[-1] <= *piVar2)) {
      bVar1 = true;
    }
    piVar2 = piVar2 + 6;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((*(char *)(fcbGlobalsPtr + 0xe17) != '\0') && (bVar1)) {
    fcbServiceTimer();
  }
  return;
}



===== um_block @ 1400023e8 =====

longlong um_block(void)

{
  return OurAdapter + 0x20;
}



===== mm_basic_initialize @ 1400023f4 =====

ulonglong mm_basic_initialize(char *param_1,short param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar2 = 0xffffffff;
  uVar1 = fcbGetDevFamily(param_2);
  param_1[0x134] = '\0';
  param_1[0x135] = '\0';
  param_1[0x136] = '\0';
  param_1[0x137] = '\0';
  *param_1 = (char)uVar1;
  if ((char)uVar1 == '\x02') {
    uVar2 = nx3_get_intf((undefined8 *)(param_1 + 8));
    uVar2 = uVar2 & 0xffffffff;
    param_1[0x134] = '\x01';
    param_1[0x135] = '\0';
    param_1[0x136] = '\0';
    param_1[0x137] = '\0';
  }
  return uVar2;
}



===== mm_current_device_map @ 14000243c =====

undefined8 mm_current_device_map(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  return *(undefined8 *)(lVar1 + ((ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) + 0xb) * 0x18);
}



===== mm_free_all_resources @ 140002468 =====

undefined8 mm_free_all_resources(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  *(undefined4 *)(lVar1 + 0xf4) = *(undefined4 *)(lVar1 + 0xf8);
  return 0;
}



===== mm_get_dma_buffer @ 140002490 =====

undefined8 mm_get_dma_buffer(longlong param_1,longlong *param_2,uint *param_3,int param_4)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_4 + 0x3fU & 0xffffffc0;
  if (*(uint *)(param_1 + 0xf0) < *(uint *)(param_1 + 0xf4) + uVar4) {
    return 1;
  }
  *param_2 = (ulonglong)*(uint *)(param_1 + 0xf4) + *(longlong *)(param_1 + 0xe0);
  uVar1 = *(undefined8 *)(param_1 + 0xe8);
  *(undefined8 *)param_3 = uVar1;
  uVar2 = (uint)uVar1;
  uVar3 = *(int *)(param_1 + 0xf4) + uVar2;
  *param_3 = uVar3;
  if (uVar3 < uVar2) {
    param_3[1] = param_3[1] + 1;
  }
  *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + uVar4;
  return 0;
}



===== mm_get_largest_dma_length @ 1400024ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int mm_get_largest_dma_length(void)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 local_d8 [5];
  code *local_b0;
  
  uVar2 = nx3_get_intf(local_d8);
  iVar3 = 0;
  if ((int)uVar2 == 0) {
    iVar1 = (*local_b0)();
    iVar3 = 0;
    if (iVar1 != 0) {
      iVar3 = iVar1;
    }
  }
  return iVar3;
}



===== mm_get_um_blk @ 140002520 =====

longlong mm_get_um_blk(void)

{
  return OurAdapter + 0x20;
}



===== mm_stall @ 140002528 =====

void mm_stall(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== read_pci_pfn @ 140002530 =====

undefined4 read_pci_pfn(ushort param_1,undefined1 param_2)

{
  undefined4 local_res10 [6];
  
  HalGetBusDataByOffset
            (4,param_1 >> 8,param_1 >> 3 & 0x1f | (param_1 & 7) << 5,local_res10,param_2,4);
  return local_res10[0];
}



===== storport_mem_read_dword @ 14000257c =====

undefined4 storport_mem_read_dword(undefined8 param_1,uint param_2)

{
  longlong lVar1;
  
  um_block();
  lVar1 = mm_current_device_map();
  return *(undefined4 *)(lVar1 + (ulonglong)param_2);
}



===== storport_pci_cfg_read_dword @ 1400025a8 =====

undefined4 storport_pci_cfg_read_dword(undefined8 param_1,byte param_2)

{
  longlong lVar1;
  undefined4 local_res18 [4];
  
  lVar1 = um_block();
  if (*(int *)(lVar1 + 0x134) == 0) {
    lVar1 = mm_current_device_map();
    local_res18[0] = *(undefined4 *)(lVar1 + (ulonglong)param_2);
  }
  else {
    HalGetBusDataByOffset
              (4,*(undefined4 *)(lVar1 + 0x104 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 0x18)
               ,*(undefined4 *)(lVar1 + 0x100 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 0x18),
               local_res18,param_2,4);
  }
  return local_res18[0];
}



===== storport_pci_cfg_write_dword @ 14000261c =====

void storport_pci_cfg_write_dword(undefined8 param_1,byte param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  lVar1 = um_block();
  if (*(int *)(lVar1 + 0x134) == 0) {
    lVar1 = mm_current_device_map();
    *(undefined4 *)(lVar1 + (ulonglong)param_2) = local_res18[0];
  }
  else {
    HalSetBusDataByOffset
              (4,*(undefined4 *)(lVar1 + 0x104 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 0x18)
               ,*(undefined4 *)(lVar1 + 0x100 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 0x18),
               local_res18,param_2,4);
  }
  return;
}



===== write_pci_pfn @ 140002698 =====

void write_pci_pfn(ushort param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  HalSetBusDataByOffset
            (4,param_1 >> 8,param_1 >> 3 & 0x1f | (param_1 & 7) << 5,local_res18,param_2,4);
  return;
}



===== fcbGetDevFamily @ 1400026e4 =====

undefined8 fcbGetDevFamily(short param_1)

{
  short sVar1;
  int7 iVar3;
  undefined8 uVar2;
  longlong lVar4;
  int iVar5;
  
  iVar5 = 0;
  if (supported_device_table != 0) {
    lVar4 = 0;
    sVar1 = supported_device_table;
    do {
      if (sVar1 == param_1) break;
      lVar4 = lVar4 + 1;
      iVar5 = iVar5 + 1;
      sVar1 = (&supported_device_table)[lVar4 * 0xc];
    } while (sVar1 != 0);
  }
  iVar3 = (int7)(int3)((uint)iVar5 >> 8);
  uVar2 = CONCAT71(iVar3,0xfe);
  if ((&supported_device_table)[(longlong)iVar5 * 0xc] != 0) {
    uVar2 = CONCAT71(iVar3,(&DAT_140017020)[(longlong)iVar5 * 0x18]);
  }
  return uVar2;
}



===== fcbIsSupportedAdapter @ 140002730 =====

undefined8 fcbIsSupportedAdapter(short param_1,short param_2)

{
  short sVar1;
  longlong lVar2;
  
  if (((param_1 == 0x14e4) || (param_1 == 0x1077)) && (supported_device_table != 0)) {
    lVar2 = 0;
    sVar1 = supported_device_table;
    do {
      if (sVar1 == param_2) {
        return 1;
      }
      lVar2 = lVar2 + 1;
      sVar1 = (&supported_device_table)[lVar2 * 0xc];
    } while (sVar1 != 0);
  }
  return 0;
}



===== fcbAddTimer @ 14000277c =====

undefined2 * fcbAddTimer(undefined4 param_1,undefined8 param_2)

{
  short *psVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0;
  psVar1 = &DAT_14001e920;
  do {
    if (*psVar1 == 0) {
      lVar2 = (longlong)iVar3;
      (&DAT_14001e930)[lVar2 * 3] = param_2;
      (&DAT_14001e920)[lVar2 * 0xc] = 1;
      (&DAT_14001e924)[lVar2 * 6] = param_1;
      (&DAT_14001e928)[lVar2 * 6] = 0;
      return &DAT_14001e920 + lVar2 * 0xc;
    }
    iVar3 = iVar3 + 1;
    psVar1 = psVar1 + 0xc;
  } while ((longlong)psVar1 < 0x14001e9e0);
  return (undefined2 *)0x0;
}



===== fcbDelTimer @ 1400027d8 =====

undefined8 fcbDelTimer(undefined2 *param_1)

{
  if (param_1 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = 0;
  return 0;
}



===== fcbInitTimer @ 1400027e8 =====

void fcbInitTimer(void)

{
  undefined2 *puVar1;
  
  puVar1 = &DAT_14001e920;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0xc;
  } while ((longlong)puVar1 < 0x14001e9e0);
  cd_init_55ms_timer();
  return;
}



===== fcbServiceTimer @ 14000280c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbServiceTimer(void)

{
  int *piVar1;
  
  piVar1 = &DAT_14001e924;
  do {
    if (((short)piVar1[-1] == 1) && (*piVar1 <= piVar1[1])) {
      (**(code **)(piVar1 + 3))();
      piVar1[1] = 0;
    }
    piVar1 = piVar1 + 6;
  } while ((longlong)piVar1 < 0x14001e9e4);
  return;
}



===== fcbTimerTick @ 14000284c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fcbTimerTick(void)

{
  bool bVar1;
  int *piVar2;
  longlong lVar3;
  
  bVar1 = false;
  piVar2 = &DAT_14001e928;
  _system_ticks = _system_ticks + 1;
  lVar3 = 8;
  do {
    if (((short)piVar2[-2] == 1) && (*piVar2 = *piVar2 + 1, piVar2[-1] <= *piVar2)) {
      bVar1 = true;
    }
    piVar2 = piVar2 + 6;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((*(char *)(fcbGlobalsPtr + 0xe17) != '\0') && (bVar1)) {
    fcbServiceTimer();
  }
  return;
}



===== fcbUnInitTimer @ 1400028a4 =====

void fcbUnInitTimer(void)

{
  if (DAT_14001e918 != '\0') {
    StorPortNotification(6,OurAdapter,timer_55ms);
  }
  return;
}



===== istrcpy @ 1400028ac =====

void istrcpy(longlong param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = param_1 - (longlong)param_2;
  do {
    cVar1 = *param_2;
    param_2[lVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return;
}



===== fcbDiscoverFabric @ 1400028bc =====

undefined8 fcbDiscoverFabric(void)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int iVar9;
  
  puVar2 = fcbGlobalsPtr;
  fcbL2CfgVlanMode((ushort)(byte)fcbGlobalsPtr[0x30] << 0xd,1);
  iVar9 = 0;
  if (puVar2[0xd6] != 0) {
    do {
      *puVar2 = *puVar2 & 0xfffe;
      puVar3 = fcbGlobalsPtr;
      puVar7 = fcbSessionGetTxFipFrame(1);
      fcbInitFipHdr((undefined8 *)((longlong)puVar7 + 0xe),4,1);
      *(undefined2 *)(puVar7 + 6) = 0x202;
      puVar4 = fcbGlobalsPtr;
      *(undefined4 *)((longlong)puVar7 + 0x1a) = *(undefined4 *)((longlong)fcbGlobalsPtr + 0x13);
      *(undefined2 *)((longlong)puVar7 + 0x1e) = *(undefined2 *)((longlong)puVar4 + 0x17);
      *(undefined2 *)(puVar7 + 5) = 0x200;
      fcbL2Send(puVar7,0x20);
      uVar8 = fcbPollNetwork(fcbFipWaitForDiscoveryVlanDone,puVar3,2);
      if ((int)uVar8 != 0) break;
      fcbWaitForTicks(2000);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)puVar2[0xd6]);
  }
  uVar1 = puVar2[0x18];
  if (uVar1 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (ushort)(byte)puVar2[0x30] << 0xd | uVar1;
  }
  fcbL2CfgVlanMode(uVar5,uVar1 != 0);
  iVar9 = 0;
  if (puVar2[0xd6] != 0) {
    do {
      *puVar2 = *puVar2 & 0xfffd;
      puVar3 = fcbGlobalsPtr;
      puVar7 = fcbSessionGetTxFipFrame(1);
      fcbInitFipHdr((undefined8 *)((longlong)puVar7 + 0xe),1,1);
      *(undefined4 *)((longlong)puVar7 + 0x16) = 0x2020080;
      puVar4 = fcbGlobalsPtr;
      *(undefined4 *)((longlong)puVar7 + 0x1a) = *(undefined4 *)((longlong)fcbGlobalsPtr + 0x13);
      *(undefined2 *)((longlong)puVar7 + 0x1e) = *(undefined2 *)((longlong)puVar4 + 0x17);
      *(undefined2 *)(puVar7 + 8) = 0x304;
      *(undefined8 *)(puVar7 + 9) = *(undefined8 *)((longlong)fcbGlobalsPtr + 0x19);
      *(undefined2 *)(puVar7 + 0xb) = 0x106;
      *(ushort *)((longlong)puVar7 + 0x2e) =
           puVar3[5] << 8 | (ushort)*(byte *)((longlong)puVar3 + 0xb);
      *(undefined2 *)(puVar7 + 5) = 0x600;
      fcbL2Send(puVar7,0x30);
      uVar8 = fcbPollNetwork(fcbFipWaitForFabricDiscoveryDone,puVar3,2);
      if (((int)uVar8 != 0) && (iVar6 = fcbFipFabricLogin(), iVar6 == 0)) {
        return 0;
      }
      fcbWaitForTicks(2000);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)puVar2[0xd6]);
  }
  return 0xffffffff;
}



===== fcbFipParseDiscovery @ 140002ac8 =====

void fcbFipParseDiscovery(longlong param_1)

{
  byte *pbVar1;
  char cVar2;
  ushort *puVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  char *pcVar7;
  
  puVar3 = fcbGlobalsPtr;
  pcVar7 = (char *)(param_1 + 10);
  uVar6 = 0;
  uVar5 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  if (((*(byte *)(param_1 + 9) & 7) == 7) && (uVar5 != 0)) {
    do {
      cVar2 = *pcVar7;
      if (cVar2 == '\x01') {
        uVar6 = uVar6 | 1;
        *(char *)(puVar3 + 0x17) = pcVar7[3];
      }
      else if (cVar2 == '\x02') {
        *(undefined4 *)((longlong)puVar3 + 0x37) = *(undefined4 *)(pcVar7 + 2);
        *(undefined2 *)((longlong)puVar3 + 0x3b) = *(undefined2 *)(pcVar7 + 6);
      }
      else if (cVar2 == '\x04') {
        uVar6 = uVar6 | 2;
        *(undefined8 *)((longlong)puVar3 + 0x3d) = *(undefined8 *)(pcVar7 + 4);
      }
      else if (cVar2 == '\x05') {
        uVar6 = uVar6 | 4;
        puVar3[0x19] = *(ushort *)(pcVar7 + 2);
        *(char *)(puVar3 + 0x1a) = pcVar7[5];
        *(char *)((longlong)puVar3 + 0x35) = pcVar7[6];
        *(char *)(puVar3 + 0x1b) = pcVar7[7];
        *(undefined8 *)((longlong)puVar3 + 0x45) = *(undefined8 *)(pcVar7 + 8);
      }
      else if (cVar2 == '\f') {
        uVar4 = swap_dword(*(uint *)(pcVar7 + 4));
        *(uint *)(puVar3 + 0x2e) = uVar4;
        if ((pcVar7[3] & 1U) == 0) {
          puVar3[0x16] = puVar3[0x16] | 1;
        }
      }
      pbVar1 = (byte *)(pcVar7 + 1);
      pcVar7 = pcVar7 + (ulonglong)*pbVar1 * 4;
      uVar5 = uVar5 - *pbVar1;
    } while (uVar5 != 0);
    if (uVar6 == 7) {
      *puVar3 = *puVar3 | 2;
    }
  }
  return;
}



===== fcbFipProcessDiscovery @ 140002bd4 =====

void fcbFipProcessDiscovery(longlong param_1)

{
  if (*(char *)(param_1 + 5) == '\x02') {
    fcbFipParseDiscovery(param_1);
  }
  return;
}



===== fcbFipProcessVlanDiscovery @ 140002be8 =====

void fcbFipProcessVlanDiscovery(longlong param_1)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  ushort uVar4;
  ushort *puVar5;
  ushort uVar6;
  
  puVar5 = fcbGlobalsPtr;
  if (*(char *)(param_1 + 5) == '\x02') {
    pcVar1 = (char *)(param_1 + 10);
    for (uVar6 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7); uVar6 != 0;
        uVar6 = uVar6 - *pbVar2) {
      if (*pcVar1 == '\x02') {
        *(undefined4 *)((longlong)puVar5 + 0x37) = *(undefined4 *)(pcVar1 + 2);
        *(undefined2 *)((longlong)puVar5 + 0x3b) = *(undefined2 *)(pcVar1 + 6);
      }
      else if (*pcVar1 == '\x0e') {
        bVar3 = pcVar1[3];
        uVar4 = *(ushort *)(pcVar1 + 2);
        *puVar5 = *puVar5 | 1;
        puVar5[0x18] = (uVar4 & 0xf) << 8 | (ushort)bVar3;
      }
      pbVar2 = (byte *)(pcVar1 + 1);
      pcVar1 = pcVar1 + (ulonglong)*pbVar2 * 4;
    }
  }
  return;
}



===== fcbFipWaitForDiscoveryVlanDone @ 140002c60 =====

ushort fcbFipWaitForDiscoveryVlanDone(ushort *param_1)

{
  return *param_1 & 1;
}



===== fcbFipWaitForFabricDiscoveryDone @ 140002c70 =====

ushort fcbFipWaitForFabricDiscoveryDone(ushort *param_1)

{
  return *param_1 >> 1 & 1;
}



===== fcbDoDisconnectSession @ 140002c7c =====

void fcbDoDisconnectSession(ushort *param_1)

{
  ushort *puVar1;
  longlong lVar2;
  
  fcbDelTimer(*(undefined2 **)(param_1 + 0xfc));
  fcbDelTimer(*(undefined2 **)(param_1 + 0x100));
  fcbDelTimer(*(undefined2 **)(param_1 + 0x104));
  puVar1 = param_1 + 0x34;
  lVar2 = 8;
  do {
    *(undefined1 *)puVar1 = 0;
    puVar1 = puVar1 + 0x14;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *param_1 = *param_1 & 0xffe3;
  return;
}



===== fcbDoFabricLogin @ 140002cd0 =====

undefined8 fcbDoFabricLogin(ushort *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  if ((param_1[0x16] & 1) != 0) {
    puVar2 = fcbAddTimer((*(uint *)(param_1 + 0x2e) / 1000) * 1000,fcbFipTxKeepAlive);
    *(undefined2 **)(param_1 + 0xfc) = puVar2;
    fcbFipTxKeepAlive();
  }
  iVar1 = fcbDoPlogi((undefined2 *)&s____);
  if (iVar1 == 0) {
    fcbSendDnsRegisterObject(0x17);
    fcbSendDnsRegisterObject(0x1f);
    fcbSendDnsRegisterObject(0x13);
    fcbSendDnsRegisterObject(0x12);
    fcbSendDnsRegisterObject(0x18);
    iVar1 = fcbQueryNxPortsFromDns();
    if (iVar1 == 0) {
      puVar2 = fcbAddTimer(90000,fcbFipTxKeepAliveVnPorts);
      *param_1 = *param_1 | 0x10;
      *(undefined2 **)(param_1 + 0x100) = puVar2;
      return 0;
    }
  }
  return 0xffffffff;
}



===== fcbDoLoginToTarget @ 140002d70 =====

undefined4 fcbDoLoginToTarget(longlong param_1,longlong param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (((*(char *)(param_2 + 0x11) != '\0') || (*(char *)(param_2 + 0x12) != '\0')) ||
     (*(char *)(param_2 + 0x13) != '\0')) {
    puVar1 = (undefined2 *)(param_1 + 0x1b8);
    *puVar1 = *(undefined2 *)(param_2 + 0x11);
    *(undefined1 *)(param_1 + 0x1ba) = *(undefined1 *)(param_2 + 0x13);
    *(undefined8 *)(param_1 + 0x1bb) = *(undefined8 *)(param_2 + 9);
    iVar2 = fcbDoPlogi(puVar1);
    if ((iVar2 == 0) && (iVar2 = fcbDoProcessLogin(puVar1), iVar2 == 0)) {
      return 0;
    }
  }
  return 0xffffffff;
}



===== fcbDoPlogi @ 140002dc8 =====

int fcbDoPlogi(undefined2 *param_1)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int iVar7;
  short local_res10 [4];
  
  iVar7 = 0;
  do {
    pbVar5 = fcbSessionGetTxFcoeFrame();
    lVar1 = fcbGlobalsPtr;
    if (pbVar5 == (byte *)0x0) {
      sVar2 = -1;
    }
    else {
      pbVar5[0x1c] = 0x22;
      *(undefined2 *)(pbVar5 + 0x1d) = *param_1;
      pbVar5[0x1f] = *(byte *)(param_1 + 1);
      uVar3 = swap_dword(0x1290000);
      *(uint *)(pbVar5 + 0x24) = uVar3;
      memset(pbVar5 + 0x35,0,0x73);
      pbVar5[0x34] = 3;
      pbVar5[0x38] = 0x20;
      pbVar5[0x39] = 0x20;
      pbVar5[0x3a] = 1;
      pbVar5[0x3b] = 0;
      pbVar5[0x3c] = 0x80;
      pbVar5[0x3d] = 0x40;
      pbVar5[0x3e] = 4;
      pbVar5[0x3f] = 0;
      uVar3 = swap_dword(2000);
      *(uint *)(pbVar5 + 0x44) = uVar3;
      *(undefined8 *)(pbVar5 + 0x48) = *(undefined8 *)(lVar1 + 0x21);
      *(undefined8 *)(pbVar5 + 0x50) = *(undefined8 *)(lVar1 + 0x19);
      *(ushort *)(pbVar5 + 0x40) = (ushort)*(byte *)(lVar1 + 0x12) << 8;
      pbVar5[0x42] = 0;
      pbVar5[0x43] = 2;
      pbVar5[0x78] = 0x80;
      pbVar5[0x79] = 0;
      pbVar5[0x7e] = 4;
      pbVar5[0x7f] = 0;
      pbVar5[0x81] = *(byte *)(lVar1 + 0x12);
      pbVar5[0x85] = 1;
      iVar4 = fcbSessionTxFcoeFrame((longlong)pbVar5,0x74,(undefined *)0x0,local_res10);
      if (iVar4 == -1) {
        sVar2 = -1;
      }
      else {
        puVar6 = (undefined1 *)fcbSessionGetExchgEntry(*(short *)(pbVar5 + 0x2c));
        fcbPollNetwork(fcbSessionWaitForFcp4Response,local_res10,(uint)*(ushort *)(lVar1 + 0x1a8));
        if (local_res10[0] == -1) {
          fcbSessionFreeExchgEntry(puVar6);
        }
        if (local_res10[0] == 1) {
          local_res10[0] = -3;
          sVar2 = -3;
        }
        else if (local_res10[0] == 2) {
          local_res10[0] = 0;
          sVar2 = 0;
        }
        else {
          local_res10[0] = -1;
          sVar2 = -1;
        }
      }
    }
    if (sVar2 == 0) break;
    if (sVar2 == -3) {
      mm_stall(4000000);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  return (iVar7 != 4) - 1;
}



===== fcbDoProcessLogin @ 140002f80 =====

int fcbDoProcessLogin(undefined2 *param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  short local_res10 [4];
  
  pbVar4 = fcbSessionGetTxFcoeFrame();
  lVar1 = fcbGlobalsPtr;
  if (pbVar4 != (byte *)0x0) {
    pbVar4[0x1c] = 0x22;
    *(undefined2 *)(pbVar4 + 0x1d) = *param_1;
    pbVar4[0x1f] = *(byte *)(param_1 + 1);
    uVar2 = swap_dword(0x1290000);
    *(uint *)(pbVar4 + 0x24) = uVar2;
    pbVar4[0x34] = 0;
    pbVar4[0x35] = 0;
    pbVar4[0x36] = 0;
    pbVar4[0x37] = 0;
    pbVar4[0x38] = 0;
    pbVar4[0x39] = 0;
    pbVar4[0x3a] = 0;
    pbVar4[0x3b] = 0;
    pbVar4[0x3c] = 0;
    pbVar4[0x3d] = 0;
    pbVar4[0x3e] = 0;
    pbVar4[0x3f] = 0;
    pbVar4[0x40] = 0;
    pbVar4[0x41] = 0;
    pbVar4[0x42] = 0;
    pbVar4[0x43] = 0;
    pbVar4[0x44] = 0;
    pbVar4[0x45] = 0;
    pbVar4[0x46] = 0;
    pbVar4[0x47] = 0;
    pbVar4[0x34] = 0x20;
    pbVar4[0x35] = 0x10;
    pbVar4[0x36] = 0;
    pbVar4[0x37] = 0x14;
    pbVar4[0x38] = 8;
    pbVar4[0x3a] = 0x20;
    pbVar4[0x3b] = 0;
    uVar2 = swap_dword(0x22);
    *(uint *)(pbVar4 + 0x44) = uVar2;
    iVar3 = fcbSessionTxFcoeFrame((longlong)pbVar4,0x14,(undefined *)0x0,local_res10);
    if (iVar3 != -1) {
      fcbPollNetwork(fcbSessionWaitForFcp4Response,local_res10,(uint)*(ushort *)(lVar1 + 0x1a8));
      return -(uint)(local_res10[0] != 2);
    }
  }
  return -1;
}



===== fcbFipFabricLogin @ 140003048 =====

undefined4 fcbFipFabricLogin(void)

{
  byte bVar1;
  short sVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  lVar3 = fcbGlobalsPtr;
  puVar5 = fcbSessionGetTxFipFrame(0);
  memset((void *)((longlong)puVar5 + 0xe),0,0xa2);
  fcbInitFipHdr((undefined8 *)((longlong)puVar5 + 0xe),2,1);
  *(undefined4 *)((longlong)puVar5 + 0x16) = 0x24070080;
  *(undefined1 *)(puVar5 + 7) = 0x22;
  *(undefined2 *)((longlong)puVar5 + 0x1d) = 0xffff;
  *(undefined1 *)((longlong)puVar5 + 0x1f) = 0xfe;
  uVar4 = swap_dword(0x1290000);
  puVar5[9] = uVar4;
  *(undefined1 *)(puVar5 + 10) = *(undefined1 *)(lVar3 + 9);
  *(short *)(lVar3 + 4) = *(short *)(lVar3 + 4) + 1;
  sVar2 = *(short *)(lVar3 + 4);
  bVar1 = *(byte *)(lVar3 + 5);
  puVar5[0xe] = 0x12020;
  *(ushort *)(puVar5 + 0xb) = (ushort)bVar1 | sVar2 << 8;
  *(undefined1 *)(puVar5 + 0xd) = 4;
  *(undefined2 *)((longlong)puVar5 + 0x2e) = 0xffff;
  puVar5[0xf] = 0x40080;
  puVar5[0x11] = 0xd007;
  *(undefined8 *)(puVar5 + 0x12) = *(undefined8 *)(lVar3 + 0x21);
  *(undefined8 *)(puVar5 + 0x14) = *(undefined8 *)(lVar3 + 0x19);
  *(undefined2 *)(puVar5 + 0x1e) = 0x88;
  *(undefined2 *)(puVar5 + 5) = 0x2600;
  *(undefined2 *)(puVar5 + 0x2a) = 0x202;
  fcbL2Send(puVar5,0xb0);
  uVar6 = fcbPollNetwork(fcbFipWaitForFlogiDone,lVar3,(uint)*(ushort *)(lVar3 + 0x1a8));
  uVar7 = 0xffffffff;
  if ((int)uVar6 != 0) {
    uVar7 = 0;
  }
  return uVar7;
}



===== fcbFipParseClearVirtualLinkRequest @ 140003178 =====

void fcbFipParseClearVirtualLinkRequest(longlong param_1)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar4 = 0;
  pcVar3 = (char *)(param_1 + 10);
  uVar5 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  if (uVar5 != 0) {
    do {
      cVar2 = *pcVar3;
      if (cVar2 == '\x02') {
        if ((*(int *)((longlong)fcbGlobalsPtr + 0x37) == *(int *)(pcVar3 + 2)) &&
           (*(short *)((longlong)fcbGlobalsPtr + 0x3b) == *(short *)(pcVar3 + 6))) {
          uVar4 = uVar4 | 1;
        }
      }
      else if (cVar2 == '\x04') {
        if (*(longlong *)((longlong)fcbGlobalsPtr + 0x3d) == *(longlong *)(pcVar3 + 4)) {
          uVar4 = uVar4 | 2;
        }
      }
      else if ((((cVar2 == '\v') && (*(int *)(fcbGlobalsPtr + 6) == *(int *)(pcVar3 + 2))) &&
               (fcbGlobalsPtr[8] == *(ushort *)(pcVar3 + 6))) &&
              (((fcbGlobalsPtr[3] == *(ushort *)(pcVar3 + 9) &&
                ((char)fcbGlobalsPtr[4] == pcVar3[0xb])) &&
               (*(longlong *)((longlong)fcbGlobalsPtr + 0x21) == *(longlong *)(pcVar3 + 0xc))))) {
        uVar4 = 3;
      }
      pbVar1 = (byte *)(pcVar3 + 1);
      pcVar3 = pcVar3 + (ulonglong)*pbVar1 * 4;
      uVar5 = uVar5 - *pbVar1;
    } while (uVar5 != 0);
    if (uVar4 == 7) {
      fcbDoDisconnectSession(fcbGlobalsPtr);
    }
  }
  return;
}



===== fcbFipParseFlogiResponse @ 140003230 =====

void fcbFipParseFlogiResponse(longlong param_1)

{
  byte *pbVar1;
  undefined2 uVar2;
  ushort *puVar3;
  char *pcVar4;
  ushort uVar5;
  ushort uVar6;
  
  puVar3 = fcbGlobalsPtr;
  pcVar4 = (char *)(param_1 + 10);
  uVar5 = 0;
  uVar6 = *(short *)(param_1 + 6) << 8 | (ushort)*(byte *)(param_1 + 7);
  if (((short)(*(short *)(param_1 + 8) << 8) < 0) && (uVar6 != 0)) {
    do {
      if (*pcVar4 == '\x02') {
        if ((uVar5 & 2) == 0) {
          *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(pcVar4 + 2);
          puVar3[8] = *(ushort *)(pcVar4 + 6);
        }
        else {
          *(undefined4 *)((longlong)puVar3 + 0x55) = *(undefined4 *)(pcVar4 + 2);
          uVar2 = *(undefined2 *)(pcVar4 + 6);
          *puVar3 = *puVar3 | 0x20;
          *(undefined2 *)((longlong)puVar3 + 0x59) = uVar2;
        }
        uVar5 = uVar5 | 2;
      }
      else if (*pcVar4 == '\a') {
        if (pcVar4[0x1c] == '\x01') {
          return;
        }
        if (pcVar4[4] != '#') {
          return;
        }
        if (-1 < (short)(*(short *)(pcVar4 + 0x60) << 8)) {
          return;
        }
        uVar5 = uVar5 | 1;
        *(char *)(puVar3 + 3) = pcVar4[5];
        *(char *)((longlong)puVar3 + 7) = pcVar4[6];
        *(char *)(puVar3 + 4) = pcVar4[7];
        *(undefined8 *)((longlong)puVar3 + 0x45) = *(undefined8 *)(pcVar4 + 0x38);
        *(undefined8 *)((longlong)puVar3 + 0x4d) = *(undefined8 *)(pcVar4 + 0x30);
      }
      pbVar1 = (byte *)(pcVar4 + 1);
      pcVar4 = pcVar4 + (ulonglong)*pbVar1 * 4;
      uVar6 = uVar6 - *pbVar1;
    } while (uVar6 != 0);
    if (uVar5 == 3) {
      *puVar3 = *puVar3 | 4;
    }
  }
  return;
}



===== fcbFipProcessLinkControl @ 140003314 =====

void fcbFipProcessLinkControl(longlong param_1)

{
  if (*(char *)(param_1 + 5) == '\x02') {
    fcbFipParseClearVirtualLinkRequest(param_1);
  }
  return;
}



===== fcbFipProcessLinkService @ 140003328 =====

void fcbFipProcessLinkService(longlong param_1)

{
  if (*(char *)(param_1 + 5) == '\x02') {
    fcbFipParseFlogiResponse(param_1);
  }
  return;
}



===== fcbFipWaitForFlogiDone @ 140003340 =====

ushort fcbFipWaitForFlogiDone(ushort *param_1)

{
  return *param_1 >> 2 & 1;
}



===== fcbQueryNxPortsCallback @ 140003350 =====

ushort fcbQueryNxPortsCallback(longlong param_1,ushort param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  ushort uVar8;
  undefined2 *puVar9;
  
  uVar2 = swap_dword(*(uint *)(param_1 + 8));
  iVar3 = param_2 - 0x18;
  lVar4 = param_1 + 0x18;
  if (DAT_14001e9e0 == 0) {
    lVar4 = param_1 + 0x28;
    uVar8 = *(short *)(param_1 + 0x20) << 8 | (ushort)*(byte *)(param_1 + 0x21);
    if (uVar8 == 0x8002) {
      iVar3 = param_2 - 0x28;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    uVar8 = 0x8002;
  }
  if (0 < iVar3) {
    puVar9 = (undefined2 *)(lVar4 + 1);
    uVar7 = (ulonglong)((iVar3 - 1U >> 4) + 1);
    do {
      lVar4 = 0;
      lVar5 = 0;
      lVar6 = 2;
      do {
        lVar1 = *(longlong *)
                 (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8);
        if (*(longlong *)((longlong)puVar9 + 7) == *(longlong *)(lVar5 + 0xf7 + lVar1)) {
          *(undefined2 *)(lVar4 + 0x107 + lVar1) = *puVar9;
          *(undefined1 *)(lVar4 + 0x109 + lVar1) = *(undefined1 *)(puVar9 + 1);
        }
        lVar5 = lVar5 + 0x14;
        lVar4 = lVar4 + 0x14;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      puVar9 = puVar9 + 8;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  DAT_14001e9e0 = (uint)((uVar2 & 0x180000) != 0x180000);
  return uVar8;
}



===== fcbQueryNxPortsFromDns @ 14000344c =====

int fcbQueryNxPortsFromDns(void)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  short local_res8 [16];
  
  lVar1 = fcbGlobalsPtr;
  uVar3 = fcbSendDnsGetObject(0x72,fcbQueryNxPortsCallback,local_res8);
  if ((int)uVar3 == 0) {
    fcbPollNetwork(fcbSessionWaitForFcp4Response,local_res8,(uint)*(ushort *)(lVar1 + 0x1a8));
    iVar2 = -(uint)(1 < (ushort)(local_res8[0] + 0x7fffU));
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



===== fcbRestartSession @ 1400034ac =====

undefined4 fcbRestartSession(ushort *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  fcbDoDisconnectSession(param_1);
  uVar2 = fcbDiscoverFabric();
  if (((((int)uVar2 == 0) && (uVar2 = fcbDoFabricLogin(param_1), (int)uVar2 == 0)) &&
      (iVar1 = fcbDoPlogi(param_1 + 0xdc), iVar1 == 0)) &&
     (iVar1 = fcbDoProcessLogin(param_1 + 0xdc), iVar1 == 0)) {
    return 0;
  }
  return 0xffffffff;
}



===== fcbFcoeRx @ 1400034f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void fcbFcoeRx(int *param_1,ushort param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar1 = 0;
  if ((((*(int *)(fcbGlobalsPtr + 0xc) == *param_1) &&
       (*(short *)(fcbGlobalsPtr + 0x10) == (short)param_1[1])) ||
      ((*param_1 == 0x1181001 && ((short)param_1[1] == 0x100)))) &&
     ((((*(char *)((longlong)param_1 + 0xe) == '\0' &&
        ((*(char *)((longlong)param_1 + 0x1b) - 0x2eU & 0xf7) == 0)) &&
       (*(char *)((longlong)param_1 + 0x1d) == *(char *)(fcbGlobalsPtr + 6))) &&
      ((*(char *)((longlong)param_1 + 0x1e) == *(char *)(fcbGlobalsPtr + 7) &&
       (*(char *)((longlong)param_1 + 0x1f) == *(char *)(fcbGlobalsPtr + 8))))))) {
    puVar3 = (undefined1 *)fcbSessionGetExchgEntry((short)param_1[0xb]);
    if (puVar3 == (undefined1 *)0x0) {
      uVar2 = swap_dword(param_1[9]);
      if (uVar2 >> 0x18 == 1) {
        fcbSessionHandleEls((longlong)(param_1 + 7));
      }
    }
    else {
      *(int *)(puVar3 + 0x20) = *(int *)(puVar3 + 0x20) + 1;
      *(undefined2 *)(puVar3 + 6) = *(undefined2 *)((longlong)param_1 + 0x2e);
      if (*(code **)(puVar3 + 8) != (code *)0x0) {
        uVar1 = (**(code **)(puVar3 + 8))(param_1 + 7,param_2 - 0x24);
      }
      uVar2 = swap_dword(param_1[9]);
      if ((uVar2 & 0x180000) == 0x180000) {
        if (*(undefined2 **)(puVar3 + 0x18) != (undefined2 *)0x0) {
          **(undefined2 **)(puVar3 + 0x18) = uVar1;
        }
        if ((puVar3[2] & 1) != 0) {
          *puVar3 = 0;
        }
      }
    }
  }
  return;
}



===== fcbSessionAbortExchange @ 140003620 =====

undefined8 fcbSessionAbortExchange(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  byte *pbVar3;
  undefined8 uVar4;
  short local_res10 [4];
  
  pbVar3 = fcbSessionGetTxFcoeFrame();
  lVar1 = fcbGlobalsPtr;
  if (pbVar3 == (byte *)0x0) {
LAB_1400036db:
    uVar4 = 0xffffffff;
  }
  else {
    *(undefined2 *)(pbVar3 + 0x2c) = *(undefined2 *)(param_1 + 4);
    pbVar3[0x2e] = 0xff;
    pbVar3[0x2f] = 0xff;
    pbVar3[0x28] = 1;
    pbVar3[0x1c] = 0x81;
    *(undefined2 *)(pbVar3 + 0x1d) = *(undefined2 *)(lVar1 + 0x1b8);
    pbVar3[0x1f] = *(byte *)(lVar1 + 0x1ba);
    uVar2 = swap_dword(0x90000);
    *(uint *)(pbVar3 + 0x24) = uVar2;
    local_res10[0] = 0xff;
    uVar4 = fcbSessionTxFcoeFrameWithParms((longlong)pbVar3,0,fcbSessionBlsCallback,local_res10,4);
    if ((int)uVar4 == 0) {
      fcbPollNetwork(fcbSessionWaitForBlsResponse,local_res10,(uint)*(ushort *)(lVar1 + 0x1aa));
      if (local_res10[0] == 0x85) goto LAB_1400036db;
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== fcbSessionAllocExchgEntry @ 1400036f0 =====

undefined1 * fcbSessionAllocExchgEntry(undefined2 param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  int iVar5;
  
  lVar2 = fcbGlobalsPtr;
  iVar5 = 0;
  lVar4 = 0;
  pcVar3 = (char *)(fcbGlobalsPtr + 0x68);
  do {
    if (*pcVar3 == '\0') {
      lVar4 = (longlong)iVar5;
      *(undefined8 *)(fcbGlobalsPtr + 0x70 + lVar4 * 0x28) = 0;
      *(undefined8 *)(lVar2 + 0x80 + lVar4 * 0x28) = 0;
      puVar1 = (undefined1 *)(lVar2 + 0x68 + lVar4 * 0x28);
      *(undefined4 *)(lVar2 + 0x88 + lVar4 * 0x28) = 0;
      *puVar1 = 1;
      *(undefined2 *)(lVar2 + 0x6a + lVar4 * 0x28) = param_2;
      *(undefined2 *)(lVar2 + 0x6c + lVar4 * 0x28) = param_1;
      return puVar1;
    }
    iVar5 = iVar5 + 1;
    lVar4 = lVar4 + 1;
    pcVar3 = pcVar3 + 0x28;
  } while (lVar4 < 8);
  return (undefined1 *)0x0;
}



===== fcbSessionBlsCallback @ 140003760 =====

undefined1 fcbSessionBlsCallback(undefined1 *param_1)

{
  return *param_1;
}



===== fcbSessionCommonTransportCallback @ 140003770 =====

ushort fcbSessionCommonTransportCallback(longlong param_1)

{
  return *(short *)(param_1 + 0x20) << 8 | (ushort)*(byte *)(param_1 + 0x21);
}



===== fcbSessionElsCallback @ 140003790 =====

undefined1 fcbSessionElsCallback(longlong param_1)

{
  return *(undefined1 *)(param_1 + 0x18);
}



===== fcbSessionExecScsiCdb @ 140003798 =====

ulonglong fcbSessionExecScsiCdb
                    (byte param_1,void *param_2,ushort param_3,longlong param_4,uint param_5,
                    undefined8 param_6,ushort param_7)

{
  short sVar1;
  ushort *puVar2;
  uint uVar3;
  undefined8 uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  ushort local_38 [8];
  
  uVar4 = fcbSessionStackEnteredWithTimeout(1);
  if ((int)uVar4 != 0) {
    return 0xffffffff;
  }
  fcbProcessLoop(1);
  puVar2 = fcbGlobalsPtr;
  if ((*fcbGlobalsPtr & 0x10) == 0) {
    fcbRestartSession(fcbGlobalsPtr);
  }
  pbVar5 = fcbSessionGetTxFcoeFrame();
  if (pbVar5 != (byte *)0x0) {
    pbVar5[0x1c] = 6;
    *(ushort *)(pbVar5 + 0x1d) = puVar2[0xdc];
    pbVar5[0x1f] = (byte)puVar2[0xdd];
    uVar3 = swap_dword(0x8290000);
    *(uint *)(pbVar5 + 0x24) = uVar3;
    pbVar5[0x34] = 0;
    pbVar5[0x35] = 0;
    pbVar5[0x36] = 0;
    pbVar5[0x37] = 0;
    pbVar5[0x38] = 0;
    pbVar5[0x39] = 0;
    pbVar5[0x3a] = 0;
    pbVar5[0x3b] = 0;
    pbVar5[0x3c] = 0;
    pbVar5[0x3d] = 0;
    pbVar5[0x3e] = 0;
    pbVar5[0x3f] = 0;
    pbVar5[0x40] = 0;
    pbVar5[0x41] = 0;
    pbVar5[0x42] = 0;
    pbVar5[0x43] = 0;
    pbVar5[0x44] = 0;
    pbVar5[0x45] = 0;
    pbVar5[0x46] = 0;
    pbVar5[0x47] = 0;
    pbVar5[0x48] = 0;
    pbVar5[0x49] = 0;
    pbVar5[0x4a] = 0;
    pbVar5[0x4b] = 0;
    pbVar5[0x4c] = 0;
    pbVar5[0x4d] = 0;
    pbVar5[0x4e] = 0;
    pbVar5[0x4f] = 0;
    pbVar5[0x50] = 0;
    pbVar5[0x51] = 0;
    pbVar5[0x52] = 0;
    pbVar5[0x53] = 0;
    *(undefined8 *)(pbVar5 + 0x34) = *(undefined8 *)((longlong)puVar2 + 0x1bb);
    puVar2[0xea] = 0;
    puVar2[0xeb] = 0;
    puVar2[0xec] = 0;
    puVar2[0xed] = 0;
    puVar2[0xee] = 0;
    puVar2[0xef] = 0;
    *(undefined8 *)(puVar2 + 0xf0) = param_6;
    puVar2[0xf4] = param_7;
    *(longlong *)(puVar2 + 0xe4) = param_4;
    *(uint *)(puVar2 + 0xe8) = param_5;
    if ((param_1 & 2) != 0) {
      pbVar5[0x3f] = pbVar5[0x3f] | 2;
    }
    if ((param_1 & 1) != 0) {
      pbVar5[0x3f] = pbVar5[0x3f] | 1;
    }
    memmove(pbVar5 + 0x40,param_2,(ulonglong)param_3);
    uVar3 = swap_dword(param_5);
    *(uint *)(pbVar5 + 0x50) = uVar3;
    uVar4 = fcbSessionTxFcoeFrameWithParms((longlong)pbVar5,0x20,(undefined *)0x0,local_38,3);
    if ((int)uVar4 != -1) {
      sVar1 = *(short *)(pbVar5 + 0x2c);
      fcbPollNetwork(fcbSessionWaitForFcp4Response,local_38,(uint)puVar2[0xd5]);
      puVar6 = (undefined1 *)fcbSessionGetExchgEntry(sVar1);
      if (local_38[0] == 0) {
        if (((((param_1 & 2) != 0) && (param_4 != 0)) && (0x1ff < param_5)) &&
           (*(uint *)(puVar2 + 0xee) < *(uint *)(puVar2 + 0xe8))) goto LAB_14000394d;
      }
      else if ((local_38[0] == 0xffff) && (0 < *(int *)(puVar6 + 0x20))) {
LAB_14000394d:
        local_38[0] = 0xfffe;
      }
      if ((0xfffd < local_38[0]) &&
         (uVar4 = fcbSessionAbortExchange((longlong)puVar6), (int)uVar4 == -1)) {
        local_38[0] = 0xffff;
      }
      *puVar6 = 0;
      goto LAB_140003978;
    }
  }
  local_38[0] = 0xffff;
LAB_140003978:
  DAT_14001e9e4 = 0;
  return (ulonglong)local_38[0];
}



===== fcbSessionFcp4Callback @ 1400039a0 =====

ulonglong fcbSessionFcp4Callback(char *param_1,int param_2)

{
  char cVar1;
  longlong lVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar2 = fcbGlobalsPtr;
  cVar1 = *param_1;
  uVar5 = param_2 - 0x18;
  uVar6 = 0xffff;
  if (cVar1 == '\x01') {
    uVar4 = swap_dword(*(uint *)(param_1 + 0x14));
    if (*(uint *)(lVar2 + 0x1d0) < (uVar5 & 0xffff) + uVar4) {
      uVar5 = (uint)(ushort)(*(short *)(lVar2 + 0x1d0) - (short)uVar4);
    }
    *(int *)(lVar2 + 0x1dc) = *(int *)(lVar2 + 0x1dc) + (uVar5 & 0xffff);
    memmove((void *)((ulonglong)uVar4 + *(longlong *)(lVar2 + 0x1c8)),param_1 + 0x18,
            (ulonglong)(uVar5 & 0xffff));
  }
  else if (cVar1 == '\x05') {
    fcbSessionProcessXferRdy((longlong)param_1);
  }
  else if (((cVar1 == '\a') && (uVar6 = (ulonglong)(byte)param_1[0x23], param_1[0x23] == 2)) &&
          ((param_1[0x22] & 2U) != 0)) {
    uVar5 = swap_dword(*(uint *)(param_1 + 0x28));
    uVar4 = swap_dword(*(uint *)(param_1 + 0x2c));
    if ((*(void **)(lVar2 + 0x1e0) != (void *)0x0) &&
       (uVar3 = *(ushort *)(lVar2 + 0x1e8), uVar3 != 0)) {
      if ((ushort)uVar5 <= uVar3) {
        uVar3 = (ushort)uVar5;
      }
      memmove(*(void **)(lVar2 + 0x1e0),param_1 + (ulonglong)(uVar4 & 0xffff) + 0x30,
              (ulonglong)uVar3);
      *(ushort *)(lVar2 + 0x1e8) = uVar3;
    }
  }
  return uVar6;
}



===== fcbSessionFreeExchgEntry @ 140003aac =====

void fcbSessionFreeExchgEntry(undefined1 *param_1)

{
  *param_1 = 0;
  return;
}



===== fcbSessionGetExchgEntry @ 140003ab0 =====

longlong fcbSessionGetExchgEntry(short param_1)

{
  short *psVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = 0;
  lVar3 = 0;
  psVar1 = (short *)(fcbGlobalsPtr + 0x6c);
  while (((char)psVar1[-2] == '\0' || (*psVar1 != param_1))) {
    iVar2 = iVar2 + 1;
    lVar3 = lVar3 + 1;
    psVar1 = psVar1 + 0x14;
    if (7 < lVar3) {
      return 0;
    }
  }
  return fcbGlobalsPtr + ((longlong)iVar2 * 5 + 0xd) * 8;
}



===== fcbSessionGetTxFcoeFrame @ 140003af0 =====

byte * fcbSessionGetTxFcoeFrame(void)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 uVar3;
  
  pbVar2 = fcbGlobalsPtr;
  pbVar1 = fcbGlobalsPtr + 0x210;
  *(undefined4 *)(fcbGlobalsPtr + 0x216) = *(undefined4 *)(fcbGlobalsPtr + 0xc);
  *(undefined2 *)(pbVar2 + 0x21a) = *(undefined2 *)(pbVar2 + 0x10);
  if ((*pbVar2 & 0x20) == 0) {
    *(undefined4 *)pbVar1 = *(undefined4 *)(pbVar2 + 0x37);
    uVar3 = *(undefined2 *)(pbVar2 + 0x3b);
  }
  else {
    *(undefined4 *)pbVar1 = *(undefined4 *)(pbVar2 + 0x55);
    uVar3 = *(undefined2 *)(pbVar2 + 0x59);
  }
  *(undefined2 *)(pbVar2 + 0x214) = uVar3;
  pbVar2[0x21c] = 0x89;
  pbVar2[0x21d] = 6;
  pbVar2[0x21e] = 0;
  pbVar2[0x21f] = 0;
  pbVar2[0x220] = 0;
  pbVar2[0x221] = 0;
  pbVar2[0x222] = 0;
  pbVar2[0x223] = 0;
  pbVar2[0x224] = 0;
  pbVar2[0x225] = 0;
  pbVar2[0x226] = 0;
  pbVar2[0x227] = 0;
  pbVar2[0x228] = 0;
  pbVar2[0x229] = 0;
  pbVar2[0x22a] = 0;
  pbVar2[0x22b] = 0;
  pbVar2[0x22b] = 0x2e;
  pbVar2[0x22c] = 0;
  pbVar2[0x22d] = 0;
  pbVar2[0x22e] = 0;
  pbVar2[0x22f] = 0;
  pbVar2[0x230] = 0;
  pbVar2[0x231] = 0;
  pbVar2[0x232] = 0;
  pbVar2[0x233] = 0;
  pbVar2[0x234] = 0;
  pbVar2[0x235] = 0;
  pbVar2[0x236] = 0;
  pbVar2[0x237] = 0;
  pbVar2[0x238] = 0;
  pbVar2[0x239] = 0;
  pbVar2[0x23a] = 0;
  pbVar2[0x23b] = 0;
  pbVar2[0x23c] = 0;
  pbVar2[0x23d] = 0;
  pbVar2[0x23e] = 0;
  pbVar2[0x23f] = 0;
  pbVar2[0x240] = 0;
  pbVar2[0x241] = 0;
  pbVar2[0x242] = 0;
  pbVar2[0x243] = 0;
  *(undefined2 *)(pbVar2 + 0x231) = *(undefined2 *)(pbVar2 + 6);
  pbVar2[0x233] = pbVar2[8];
  return pbVar1;
}



===== fcbSessionGetTxFipFrame @ 140003b6c =====

undefined4 * fcbSessionGetTxFipFrame(int param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = fcbGlobalsPtr;
  puVar1 = (undefined4 *)(fcbGlobalsPtr + 0x810);
  if (param_1 == 0) {
    *puVar1 = *(undefined4 *)(fcbGlobalsPtr + 0x37);
    *(undefined2 *)(lVar3 + 0x814) = *(undefined2 *)(lVar3 + 0x3b);
  }
  else {
    *puVar1 = fcb_all_fcf_mac_addr;
    *(undefined2 *)(lVar3 + 0x814) = DAT_140017194;
  }
  lVar4 = fcbGlobalsPtr;
  *(undefined4 *)(lVar3 + 0x816) = *(undefined4 *)(fcbGlobalsPtr + 0x13);
  uVar2 = *(undefined2 *)(lVar4 + 0x17);
  *(undefined2 *)(lVar3 + 0x81c) = 0x1489;
  *(undefined2 *)(lVar3 + 0x81a) = uVar2;
  return puVar1;
}



===== fcbSessionHandleEls @ 140003bcc =====

void fcbSessionHandleEls(longlong param_1)

{
  char cVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  ushort uVar5;
  
  pbVar2 = fcbGlobalsPtr;
  cVar1 = *(char *)(param_1 + 0x18);
  if ((cVar1 == '\x03') || (cVar1 == '\x05')) {
LAB_140003cf3:
    if ((*fcbGlobalsPtr & 0x10) == 0) {
      return;
    }
    pbVar4 = fcbSessionGetTxFcoeFrame();
    if (pbVar4 == (byte *)0x0) {
      return;
    }
    pbVar4[0x1c] = 0x23;
    *(undefined2 *)(pbVar4 + 0x1d) = *(undefined2 *)(param_1 + 5);
    pbVar4[0x1f] = *(byte *)(param_1 + 7);
    uVar3 = swap_dword(0x1980000);
    *(uint *)(pbVar4 + 0x24) = uVar3;
    *(undefined2 *)(pbVar4 + 0x2c) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(pbVar4 + 0x2e) = *(undefined2 *)(pbVar2 + 4);
    uVar5 = 4;
    pbVar4[0x34] = 2;
  }
  else {
    if (cVar1 != ' ') {
      if (cVar1 == '!') goto LAB_140003cf3;
      if (cVar1 == 'R') {
        if ((*fcbGlobalsPtr & 0x10) == 0) {
          return;
        }
        pbVar4 = fcbSessionGetTxFcoeFrame();
        if (pbVar4 == (byte *)0x0) {
          return;
        }
        pbVar4[0x1c] = 0x23;
        *(undefined2 *)(pbVar4 + 0x1d) = *(undefined2 *)(param_1 + 5);
        pbVar4[0x1f] = *(byte *)(param_1 + 7);
        uVar3 = swap_dword(0x1980000);
        *(uint *)(pbVar4 + 0x24) = uVar3;
        *(undefined2 *)(pbVar4 + 0x2c) = *(undefined2 *)(param_1 + 0x10);
        *(undefined2 *)(pbVar4 + 0x2e) = *(undefined2 *)(pbVar2 + 4);
        pbVar4[0x34] = 2;
        *(undefined8 *)(pbVar4 + 0x3c) = *(undefined8 *)(pbVar2 + 0x21);
        *(undefined8 *)(pbVar4 + 0x44) = *(undefined8 *)(pbVar2 + 0x19);
        *(undefined2 *)(pbVar4 + 0x4d) = *(undefined2 *)(pbVar2 + 6);
        pbVar4[0x4f] = pbVar2[8];
        uVar5 = 0x1c;
        goto LAB_140003d49;
      }
      if (cVar1 != 'a') {
        return;
      }
    }
    pbVar4 = fcbSessionGetTxFcoeFrame();
    pbVar2 = fcbGlobalsPtr;
    if (pbVar4 == (byte *)0x0) {
      return;
    }
    pbVar4[0x1c] = 0x23;
    *(undefined2 *)(pbVar4 + 0x1d) = *(undefined2 *)(param_1 + 5);
    pbVar4[0x1f] = *(byte *)(param_1 + 7);
    uVar3 = swap_dword(0x1980000);
    *(uint *)(pbVar4 + 0x24) = uVar3;
    *(undefined2 *)(pbVar4 + 0x2c) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(pbVar4 + 0x2e) = *(undefined2 *)(pbVar2 + 4);
    pbVar4[0x34] = 0;
    pbVar4[0x35] = 0;
    pbVar4[0x36] = 0;
    pbVar4[0x37] = 0;
    pbVar4[0x38] = 0;
    pbVar4[0x39] = 0;
    pbVar4[0x3a] = 0;
    pbVar4[0x3b] = 0;
    pbVar4[0x34] = 1;
    pbVar4[0x39] = 0xb;
    pbVar4[0x3a] = 0;
    uVar5 = 8;
  }
LAB_140003d49:
  fcbSessionTxFcoeFrameWithParms((longlong)pbVar4,uVar5,(undefined *)0x0,(undefined2 *)0x0,4);
  return;
}



===== fcbSessionProcessXferRdy @ 140003d6c =====

undefined8 fcbSessionProcessXferRdy(longlong param_1)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  byte *pbVar7;
  undefined8 uVar8;
  byte bVar9;
  
  uVar3 = swap_dword(*(uint *)(param_1 + 0x18));
  uVar4 = swap_dword(*(uint *)(param_1 + 0x1c));
  lVar6 = fcbSessionGetExchgEntry(*(short *)(param_1 + 0x10));
  if ((lVar6 != 0) &&
     (pbVar7 = fcbSessionGetTxFcoeFrame(), lVar1 = fcbGlobalsPtr, pbVar7 != (byte *)0x0)) {
    bVar9 = 0;
    pbVar7[0x1c] = 1;
    *(undefined2 *)(pbVar7 + 0x1d) = *(undefined2 *)(lVar1 + 0x1b8);
    pbVar7[0x1f] = *(byte *)(lVar1 + 0x1ba);
    while( true ) {
      if (uVar4 == 0) {
        return 0;
      }
      uVar5 = swap_dword(uVar3);
      *(uint *)(pbVar7 + 0x30) = uVar5;
      uVar2 = *(ushort *)(lVar1 + 0x1ea);
      if (uVar4 <= *(ushort *)(lVar1 + 0x1ea)) {
        uVar2 = (ushort)uVar4;
      }
      *(ushort *)(pbVar7 + 0x2a) = (ushort)bVar9 << 8;
      *(undefined2 *)(pbVar7 + 0x2e) = *(undefined2 *)(lVar6 + 6);
      memmove(pbVar7 + 0x34,(void *)((ulonglong)uVar3 + *(longlong *)(lVar1 + 0x1c8)),
              (ulonglong)uVar2);
      *(int *)(lVar1 + 0x1d8) = *(int *)(lVar1 + 0x1d8) + (uint)uVar2;
      uVar4 = uVar4 - uVar2;
      uVar3 = uVar3 + uVar2;
      uVar5 = (-(uint)(uVar4 != 0) & 0xfff80000) + 0x8080008;
      if ((*(int *)(lVar1 + 0x1d8) == *(int *)(lVar1 + 0x1d0)) || (uVar4 == 0)) {
        uVar5 = uVar5 | 0x10000;
      }
      uVar5 = swap_dword(uVar5);
      *(uint *)(pbVar7 + 0x24) = uVar5;
      if (bVar9 != 0) {
        pbVar7[0x1b] = 0x36;
      }
      uVar8 = fcbSessionTxFcoeFrameWithParms
                        ((longlong)pbVar7,uVar2,(undefined *)0x0,(undefined2 *)0x0,
                         ~-(ushort)(bVar9 != 0) & 2);
      if ((int)uVar8 == -1) break;
      bVar9 = bVar9 + 1;
    }
  }
  return 0xffffffff;
}



===== fcbSessionSendScsiCdb @ 140003ed4 =====

ulonglong fcbSessionSendScsiCdb
                    (byte param_1,void *param_2,ushort param_3,longlong param_4,uint param_5,
                    longlong param_6,ushort param_7)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  int iVar5;
  uint local_48;
  
  bVar1 = false;
  iVar4 = 0;
  iVar5 = fcbGlobalsPtr[0xd7] + 1;
  if (iVar5 == 0) {
    uVar3 = (ulonglong)local_48;
  }
  else {
    do {
      uVar3 = fcbSessionExecScsiCdb(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      iVar2 = (int)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (iVar2 == 2) {
        if ((param_6 != 0) && (param_1 != 0)) {
          return uVar3;
        }
      }
      else {
        if (((iVar2 - 8U & 0xffffffdf) != 0) && (1 < iVar2 - 0xfffeU)) {
          return uVar3;
        }
        if ((iVar2 - 8U & 0xffffffdf) == 0) {
          fcbWaitForTicks(1000);
        }
      }
      if ((iVar2 == 0xffff) && (!bVar1)) {
        bVar1 = true;
        iVar2 = fcbRestartSession(fcbGlobalsPtr);
        if (iVar2 == 0) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  return uVar3;
}



===== fcbSessionStackEnteredWithTimeout @ 140003fec =====

undefined8 fcbSessionStackEnteredWithTimeout(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 1000;
  iVar1 = fcbGetTicks();
  do {
    if (iVar3 == 0) {
      return 1;
    }
    iVar2 = fcbGetTicks();
    if (iVar1 != iVar2) {
      iVar1 = fcbGetTicks();
      iVar3 = iVar3 + -1;
    }
  } while (DAT_14001e9e4 != 0);
  DAT_14001e9e4 = 1;
  return 0;
}



===== fcbSessionTxFcoeFrame @ 140004040 =====

void fcbSessionTxFcoeFrame(longlong param_1,ushort param_2,undefined *param_3,undefined2 *param_4)

{
  fcbSessionTxFcoeFrameWithParms(param_1,param_2,param_3,param_4,0xb);
  return;
}



===== fcbSessionTxFcoeFrameWithParms @ 140004058 =====

undefined8
fcbSessionTxFcoeFrameWithParms
          (longlong param_1,ushort param_2,undefined *param_3,undefined2 *param_4,ushort param_5)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  ushort uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint *puVar11;
  undefined1 local_58 [48];
  
  lVar1 = fcbGlobalsPtr;
  uVar10 = (ulonglong)param_2;
  uVar9 = 0;
  puVar11 = (uint *)(param_1 + 0x1c);
  uVar3 = swap_dword(*(uint *)(param_1 + 0x24));
  if ((param_5 & 1) != 0) {
    *(short *)(lVar1 + 4) = *(short *)(lVar1 + 4) + 1;
  }
  if ((param_5 & 4) == 0) {
    *(ushort *)(param_1 + 0x2c) = *(short *)(lVar1 + 4) << 8 | (ushort)*(byte *)(lVar1 + 5);
  }
  if ((param_5 & 1) == 0) {
    puVar6 = (undefined1 *)fcbSessionGetExchgEntry(*(short *)(param_1 + 0x2c));
    puVar5 = local_58;
    if (puVar6 != (undefined1 *)0x0) {
      puVar5 = puVar6;
    }
  }
  else {
    puVar5 = fcbSessionAllocExchgEntry(*(short *)(param_1 + 0x2c),param_5 >> 3 & 1);
    if (puVar5 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    if (param_4 != (undefined2 *)0x0) {
      *param_4 = 0xffff;
    }
    *(undefined2 *)(param_1 + 0x2e) = 0xffff;
  }
  if (param_4 != (undefined2 *)0x0) {
    *(undefined2 **)(puVar5 + 0x18) = param_4;
  }
  uVar7 = uVar3 >> 0x18;
  puVar5[0x11] = (char)(uVar3 >> 0x18);
  puVar5[0x10] = *(undefined1 *)puVar11;
  if (param_3 == (undefined *)0x0) {
    param_3 = (code *)0x0;
    if (uVar7 == 0) {
      param_3 = fcbSessionBlsCallback;
    }
    else if (uVar7 == 1) {
      param_3 = fcbSessionElsCallback;
    }
    else if (uVar7 == 8) {
      param_3 = fcbSessionFcp4Callback;
    }
    else if (uVar7 == 0x20) {
      param_3 = fcbSessionCommonTransportCallback;
    }
  }
  *(undefined **)(puVar5 + 8) = param_3;
  cVar2 = *(char *)(lVar1 + 9);
  if ((param_5 & 2) != 0) {
    cVar2 = cVar2 + '\x01';
    *(char *)(lVar1 + 9) = cVar2;
  }
  *(char *)(param_1 + 0x28) = cVar2;
  if ((param_2 & 3) != 0) {
    uVar8 = 4 - (param_2 & 3);
    uVar9 = (ulonglong)uVar8;
    if (uVar8 != 0) {
      uVar7 = (uint)uVar8;
      uVar3 = uVar3 | uVar8;
      uVar4 = swap_dword(uVar3);
      *(uint *)(param_1 + 0x24) = uVar4;
      goto LAB_1400041be;
    }
  }
  uVar7 = 0;
LAB_1400041be:
  uVar7 = fcbGenCrc32(puVar11,param_2 + 0x18 + uVar7,0xffffffff);
  *(uint *)((longlong)puVar11 + uVar10 + 0x18 + uVar9) = ~uVar7;
  *(char *)((longlong)puVar11 + uVar10 + 0x1c + uVar9) = ((uVar3 >> 0x13 & 1) != 0) + 'A';
  *(undefined2 *)((longlong)puVar11 + uVar10 + 0x1d + uVar9) = 0;
  *(undefined1 *)((longlong)puVar11 + uVar10 + 0x1f + uVar9) = 0;
  fcbL2Send(param_1,param_2 + (short)uVar9 + 0x3c);
  return 0;
}



===== fcbSessionWaitForBlsResponse @ 140004230 =====

bool fcbSessionWaitForBlsResponse(short *param_1)

{
  return *param_1 != 0xff;
}



===== fcbSessionWaitForFcp4Response @ 140004240 =====

bool fcbSessionWaitForFcp4Response(short *param_1)

{
  return *param_1 != -1;
}



===== fcbInit @ 140004250 =====

undefined8 fcbInit(void)

{
  byte bVar1;
  longlong lVar2;
  short sVar3;
  undefined1 *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  lVar2 = fcbGlobalsPtr;
  lVar6 = *(longlong *)(fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8);
  *(undefined4 *)(fcbGlobalsPtr + 0x13) = *(undefined4 *)(lVar6 + 0x12);
  *(undefined2 *)(lVar2 + 0x17) = *(undefined2 *)(lVar6 + 0x16);
  sVar3 = fcbGetTicks();
  *(undefined1 *)(lVar2 + 0x60) = 3;
  *(undefined1 *)(lVar2 + 0x12) = 1;
  *(short *)(lVar2 + 4) = sVar3 + 1;
  *(undefined2 *)(lVar2 + 10) = 0x42e;
  puVar4 = (undefined1 *)(lVar2 + 0x68);
  lVar6 = 8;
  do {
    lVar5 = lVar6;
    *puVar4 = 0;
    puVar4 = puVar4 + 0x28;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  *(undefined4 *)(lVar2 + 0x1a8) = 0x20004;
  uVar7 = (short)lVar5 + 3;
  *(undefined2 *)(lVar2 + 0x1ea) = 0x400;
  *(ushort *)(lVar2 + 0x1ac) =
       *(byte *)(*(longlong *)
                  (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) + 0xf5)
       + 1;
  bVar1 = *(byte *)(*(longlong *)
                     (fcbGlobalsPtr + 0xe30 + (ulonglong)*(byte *)(fcbGlobalsPtr + 0xe2c) * 8) +
                   0xf4);
  if (bVar1 != 0) {
    uVar7 = (ushort)bVar1;
  }
  *(ushort *)(lVar2 + 0x1ae) = uVar7;
  return 0;
}



===== fcbFipRx @ 140004328 =====

void fcbFipRx(int *param_1)

{
  char *pcVar1;
  ushort uVar2;
  
  if ((((*(int *)(fcbGlobalsPtr + 0x13) == *param_1) &&
       (*(short *)(fcbGlobalsPtr + 0x17) == (short)param_1[1])) ||
      ((*param_1 == 0x1181001 && ((short)param_1[1] == 0x100)))) &&
     (pcVar1 = (char *)((longlong)param_1 + 0xe), *pcVar1 == '\x10')) {
    uVar2 = (short)param_1[4] << 8 | (ushort)*(byte *)((longlong)param_1 + 0x11);
    if (uVar2 == 1) {
      fcbFipProcessDiscovery((longlong)pcVar1);
    }
    else {
      if (uVar2 == 2) {
        fcbFipProcessLinkService((longlong)pcVar1);
        return;
      }
      if (uVar2 == 3) {
        fcbFipProcessLinkControl((longlong)pcVar1);
        return;
      }
      if (uVar2 == 4) {
        fcbFipProcessVlanDiscovery((longlong)pcVar1);
        return;
      }
    }
  }
  return;
}



===== fcbFipTxKeepAlive @ 1400043c0 =====

undefined8 fcbFipTxKeepAlive(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  puVar2 = fcbSessionGetTxFipFrame(0);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    *(undefined8 *)((longlong)puVar2 + 0xe) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x16) = 0x2020000;
    *(undefined2 *)(puVar2 + 4) = 0x300;
    *(undefined1 *)((longlong)puVar2 + 0xe) = 0x10;
    *(undefined1 *)((longlong)puVar2 + 0x13) = 1;
    lVar1 = fcbGlobalsPtr;
    *(undefined4 *)((longlong)puVar2 + 0x1a) = *(undefined4 *)(fcbGlobalsPtr + 0x13);
    *(undefined2 *)((longlong)puVar2 + 0x1e) = *(undefined2 *)(lVar1 + 0x17);
    *(undefined2 *)(puVar2 + 5) = 0x200;
    fcbL2Send(puVar2,0x20);
    uVar3 = 0;
  }
  return uVar3;
}



===== fcbFipTxKeepAliveVnPorts @ 140004430 =====

undefined8 fcbFipTxKeepAliveVnPorts(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  puVar2 = fcbSessionGetTxFipFrame(0);
  lVar1 = fcbGlobalsPtr;
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    *(undefined4 *)((longlong)puVar2 + 6) = *(undefined4 *)(fcbGlobalsPtr + 0xc);
    *(undefined2 *)((longlong)puVar2 + 10) = *(undefined2 *)(lVar1 + 0x10);
    *(undefined8 *)((longlong)puVar2 + 0xe) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x16) = 0x2020000;
    *(undefined2 *)(puVar2 + 4) = 0x300;
    *(undefined1 *)((longlong)puVar2 + 0xe) = 0x10;
    *(undefined1 *)((longlong)puVar2 + 0x13) = 1;
    lVar1 = fcbGlobalsPtr;
    *(undefined4 *)((longlong)puVar2 + 0x1a) = *(undefined4 *)(fcbGlobalsPtr + 0x13);
    *(undefined2 *)((longlong)puVar2 + 0x1e) = *(undefined2 *)(lVar1 + 0x17);
    *(undefined2 *)(puVar2 + 8) = 0x50b;
    lVar1 = fcbGlobalsPtr;
    *(undefined4 *)((longlong)puVar2 + 0x22) = *(undefined4 *)(fcbGlobalsPtr + 0xc);
    *(undefined2 *)((longlong)puVar2 + 0x26) = *(undefined2 *)(lVar1 + 0x10);
    lVar1 = fcbGlobalsPtr;
    *(undefined2 *)((longlong)puVar2 + 0x29) = *(undefined2 *)(fcbGlobalsPtr + 6);
    *(undefined1 *)((longlong)puVar2 + 0x2b) = *(undefined1 *)(lVar1 + 8);
    *(undefined8 *)(puVar2 + 0xb) = *(undefined8 *)(fcbGlobalsPtr + 0x21);
    *(undefined2 *)(puVar2 + 5) = 0x700;
    fcbL2Send(puVar2,0x34);
    uVar3 = 0;
  }
  return uVar3;
}



===== fcbInitFipHdr @ 140004500 =====

void fcbInitFipHdr(undefined8 *param_1,ushort param_2,undefined1 param_3)

{
  *param_1 = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined1 *)param_1 = 0x10;
  *(ushort *)((longlong)param_1 + 2) = param_2 << 8 | param_2 >> 8;
  *(undefined1 *)((longlong)param_1 + 5) = param_3;
  return;
}



===== fcbSendDnsGetObject @ 14000451c =====

undefined8 fcbSendDnsGetObject(byte param_1,undefined *param_2,undefined2 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  undefined8 uVar3;
  
  pbVar2 = fcbSessionGetTxFcoeFrame();
  if (pbVar2 != (byte *)0x0) {
    pbVar2[0x1c] = 2;
    pbVar2[0x1d] = 0xff;
    pbVar2[0x1e] = 0xff;
    pbVar2[0x1f] = 0xfc;
    uVar1 = swap_dword(0x20290000);
    *(uint *)(pbVar2 + 0x24) = uVar1;
    pbVar2[0x34] = 0;
    pbVar2[0x35] = 0;
    pbVar2[0x36] = 0;
    pbVar2[0x37] = 0;
    pbVar2[0x38] = 0;
    pbVar2[0x39] = 0;
    pbVar2[0x3a] = 0;
    pbVar2[0x3b] = 0;
    pbVar2[0x3c] = 0;
    pbVar2[0x3d] = 0;
    pbVar2[0x3e] = 0;
    pbVar2[0x3f] = 0;
    pbVar2[0x40] = 0;
    pbVar2[0x41] = 0;
    pbVar2[0x42] = 0;
    pbVar2[0x43] = 0;
    pbVar2[0x34] = 1;
    pbVar2[0x38] = 0xfc;
    pbVar2[0x39] = 2;
    *(ushort *)(pbVar2 + 0x3c) = (ushort)param_1 << 8 | 1;
    if (param_1 == 0x72) {
      pbVar2[0x45] = 0;
      pbVar2[0x46] = 0;
      pbVar2[0x47] = 8;
      uVar3 = fcbSessionTxFcoeFrame((longlong)pbVar2,0x14,param_2,param_3);
      return uVar3;
    }
  }
  return 0xffffffff;
}



===== fcbSendDnsRegisterObject @ 1400045cc =====

undefined8 fcbSendDnsRegisterObject(byte param_1)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  byte *pbVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  pbVar4 = fcbSessionGetTxFcoeFrame();
  lVar1 = fcbGlobalsPtr;
  if (pbVar4 == (byte *)0x0) {
    return 0xffffffffffffffff;
  }
  pbVar4[0x1c] = 2;
  pbVar4[0x1d] = 0xff;
  pbVar4[0x1e] = 0xff;
  pbVar4[0x1f] = 0xfc;
  uVar3 = swap_dword(0x20290000);
  *(uint *)(pbVar4 + 0x24) = uVar3;
  pbVar4[0x34] = 0;
  pbVar4[0x35] = 0;
  pbVar4[0x36] = 0;
  pbVar4[0x37] = 0;
  pbVar4[0x38] = 0;
  pbVar4[0x39] = 0;
  pbVar4[0x3a] = 0;
  pbVar4[0x3b] = 0;
  pbVar4[0x3c] = 0;
  pbVar4[0x3d] = 0;
  pbVar4[0x3e] = 0;
  pbVar4[0x3f] = 0;
  pbVar4[0x40] = 0;
  pbVar4[0x41] = 0;
  pbVar4[0x42] = 0;
  pbVar4[0x43] = 0;
  pbVar4[0x34] = 1;
  pbVar4[0x38] = 0xfc;
  pbVar4[0x39] = 2;
  *(ushort *)(pbVar4 + 0x3c) = (ushort)param_1 << 8 | 2;
  *(undefined2 *)(pbVar4 + 0x45) = *(undefined2 *)(lVar1 + 6);
  pbVar4[0x47] = *(byte *)(lVar1 + 8);
  if (param_1 == 0x12) {
    uVar6 = *(undefined8 *)(lVar1 + 0x21);
  }
  else {
    if (param_1 != 0x13) {
      if (param_1 == 0x17) {
        pbVar4[0x4a] = 1;
        uVar2 = 0x34;
      }
      else if (param_1 == 0x18) {
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (*(char *)(*(longlong *)(lVar1 + 0x1f0) + lVar5) != '\0');
        pbVar4[0x48] = (byte)lVar5;
        istrcpy((longlong)(pbVar4 + 0x49),*(char **)(lVar1 + 0x1f0));
        uVar2 = pbVar4[0x48] + 0x15;
      }
      else {
        if (param_1 != 0x1f) {
          return 0xffffffffffffffff;
        }
        pbVar4[0x4a] = 2;
        pbVar4[0x4b] = 8;
        uVar2 = 0x18;
      }
      goto LAB_1400046be;
    }
    uVar6 = *(undefined8 *)(lVar1 + 0x19);
  }
  *(undefined8 *)(pbVar4 + 0x48) = uVar6;
  uVar2 = 0x1c;
LAB_1400046be:
  uVar6 = fcbSessionTxFcoeFrame((longlong)pbVar4,uVar2,(undefined *)0x0,(undefined2 *)0x0);
  return uVar6;
}



===== fcbRxIndication @ 1400046e8 =====

void fcbRxIndication(int *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = (short)param_1[3] << 8 | (ushort)*(byte *)((longlong)param_1 + 0xd);
  if (uVar1 == 0x8906) {
    fcbFcoeRx(param_1,param_2);
  }
  else if (uVar1 == 0x8914) {
    fcbFipRx(param_1);
    return;
  }
  return;
}



===== FC_Crc32 @ 140004724 =====

ulonglong FC_Crc32(ulonglong param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = param_3;
  if (((ulonglong)param_2 & 3) != 0) {
    for (; uVar2 = 0, param_3 != 0; param_3 = param_3 - 1) {
      param_1 = (ulonglong)
                (*(uint *)(&DAT_140015170 + ((ulonglong)(byte)*param_2 ^ param_1 & 0xff) * 4) ^
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
                (*(uint *)(&DAT_140015170 + (ulonglong)(uVar1 >> 0x18) * 4) ^
                 *(uint *)(&DAT_140015570 + (ulonglong)(uVar1 >> 0x10 & 0xff) * 4) ^
                 *(uint *)(&DAT_140015970 + (ulonglong)(uVar1 >> 8 & 0xff) * 4) ^
                *(uint *)(&DAT_140015d70 + (ulonglong)(uVar1 & 0xff) * 4));
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = *param_2;
    param_2 = (uint *)((longlong)param_2 + 1);
    param_1 = (ulonglong)
              (*(uint *)(&DAT_140015170 + ((ulonglong)(byte)uVar1 ^ param_1 & 0xff) * 4) ^
              (uint)(param_1 >> 8) & 0xffffff);
  }
  return param_1 & 0xffffffff;
}



===== fcbGenCrc32 @ 1400047ec =====

void fcbGenCrc32(uint *param_1,uint param_2,uint param_3)

{
  FC_Crc32((ulonglong)param_3,param_1,param_2);
  return;
}



===== fcbWaitForTicks @ 1400047fc =====

void fcbWaitForTicks(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = fcbGetTicks();
  while (0 < param_1) {
    iVar2 = fcbGetTicks();
    if (iVar1 != iVar2) {
      iVar1 = fcbGetTicks();
      param_1 = param_1 + -1;
    }
  }
  return;
}



===== stack_rx_packet @ 140004830 =====

void stack_rx_packet(int *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = (short)param_1[3] << 8 | (ushort)*(byte *)((longlong)param_1 + 0xd);
  if (uVar1 == 0x8906) {
    fcbFcoeRx(param_1,param_2);
  }
  else if (uVar1 == 0x8914) {
    fcbFipRx(param_1);
    return;
  }
  return;
}



===== __security_check_cookie @ 140004850 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 140004870 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 140004880 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== StorPortInitialize @ 1400048b0 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetPhysicalAddress @ 1400048b6 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 1400048bc =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortNotification @ 1400048c2 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortCompleteRequest @ 1400048c8 =====

void StorPortCompleteRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortCompleteRequest();
  return;
}



===== StorPortStallExecution @ 1400048ce =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400048ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== __GSHandlerCheck @ 1400048d4 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400048f4 =====

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



===== HalGetBusDataByOffset @ 140004960 =====

void HalGetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HalGetBusDataByOffset();
  return;
}



===== HalSetBusDataByOffset @ 140004966 =====

void HalSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004966. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HalSetBusDataByOffset();
  return;
}



===== ev_lm_reg_read_ind @ 14000496c =====

void ev_lm_reg_read_ind(undefined8 param_1,undefined4 param_2)

{
  storport_pci_cfg_write_dword(param_1,0x78,param_2);
  storport_pci_cfg_read_dword(param_1,0x80);
  return;
}



===== ev_lm_reg_write_ind @ 140004990 =====

void ev_lm_reg_write_ind(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  storport_pci_cfg_write_dword(param_1,0x78,param_2);
  storport_pci_cfg_write_dword(param_1,0x80,param_3);
  return;
}



===== ev_mm_get_rx_desc @ 1400049c4 =====

undefined * ev_mm_get_rx_desc(undefined8 param_1,int param_2)

{
  return &dev_rx_packet_ring + (longlong)param_2 * 0x60;
}



===== ev_mm_get_tx_desc @ 1400049dc =====

undefined * ev_mm_get_tx_desc(undefined8 param_1,int param_2)

{
  return &dev_tx_packet_ring + (longlong)param_2 * 0x60;
}



===== ev_mm_get_user_config @ 1400049f4 =====

undefined8 ev_mm_get_user_config(longlong param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    *(undefined2 *)(param_1 + 0x5e) = 10000;
    if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
       ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000)) {
      *(undefined4 *)(param_1 + 0x5e) = 0xfa003a98;
    }
  }
  else {
    if (sVar1 == 0x300) {
      uVar2 = 15000;
    }
    else if (sVar1 == 0x700) {
      uVar2 = 40000;
    }
    else if (sVar1 == 0x800) {
      uVar2 = 13000;
    }
    else {
      if (sVar1 == 0x900) {
        *(ushort *)(param_1 + 0x5e) =
             (-(ushort)((*(uint *)(param_1 + 0x58) & 0x200) != 0) & 0xd8ef) + 10000;
        goto LAB_140004aa7;
      }
      uVar2 = 2000;
    }
    *(undefined2 *)(param_1 + 0x5e) = uVar2;
  }
LAB_140004aa7:
  *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffeffff;
  *(undefined4 *)(param_1 + 0x17a) = 0x100010;
  *(undefined4 *)(param_1 + 0x180) = 0x80000000;
  *(undefined1 *)(param_1 + 0x184) = 0;
  if (((sVar1 == 0) || (sVar1 == 0x300)) || (sVar1 == 0x700)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 6;
    if ((sVar1 == 0x900) && (uVar3 = 3, (*(uint *)(param_1 + 0x48) & 0x3c000000) != 0x14000000)) {
      uVar3 = 6;
    }
  }
  *(undefined1 *)(param_1 + 0x18d) = uVar3;
  *(undefined1 *)(param_1 + 0x188) = 1;
  return 0;
}



===== ev_mm_initialize_packets @ 140004b18 =====

undefined8 ev_mm_initialize_packets(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  
  lVar1 = mm_get_um_blk();
  iVar5 = 0;
  if (*(short *)(param_1 + 0x17c) != 0) {
    uVar4 = *(uint *)(param_1 + 0x4d4);
    do {
      uVar3 = *(uint *)(param_1 + 0x4d0);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x4d8);
        }
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
        *(uint *)(param_1 + 0x4d0) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x4d4);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x4d8);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x4d0)) {
        *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x17c));
  }
  iVar5 = 0;
  if (*(short *)(param_1 + 0x17a) != 0) {
    uVar4 = *(uint *)(param_1 + 0x2dc);
    do {
      uVar3 = *(uint *)(param_1 + 0x2d8);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x2e0);
        }
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + -1;
        *(uint *)(param_1 + 0x2d8) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x2e8 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x2dc);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x2e0);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x2d8)) {
        *(longlong *)(param_1 + 0x2e8 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
        *(uint *)(param_1 + 0x2dc) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x17a));
  }
  return 0;
}



===== lm_reg_write_block @ 140004cb4 =====

void lm_reg_write_block(undefined8 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  if (param_4 != 0) {
    uVar1 = (ulonglong)param_4;
    do {
      ev_lm_reg_write_ind(param_1,param_2,*param_3);
      param_2 = param_2 + 4;
      param_3 = param_3 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



===== mm_add_mcast_addr @ 140004d10 =====

undefined8 mm_add_mcast_addr(longlong param_1,int *param_2)

{
  short *psVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(byte *)(param_1 + 0x1a4) != 0) {
    do {
      if ((*(int *)(param_1 + 0x1a6 + (longlong)iVar3 * 8) == *param_2) &&
         (*(short *)(param_1 + 0x1aa + (longlong)iVar3 * 8) == (short)param_2[1])) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x1a4));
    if (0x1f < iVar3) {
      return 1;
    }
  }
  lVar2 = (longlong)iVar3;
  *(int *)(param_1 + 0x1a6 + lVar2 * 8) = *param_2;
  iVar3 = param_2[1];
  psVar1 = (short *)(param_1 + 0x1ac + lVar2 * 8);
  *psVar1 = *psVar1 + 1;
  *(short *)(param_1 + 0x1aa + lVar2 * 8) = (short)iVar3;
  *(char *)(param_1 + 0x1a4) = *(char *)(param_1 + 0x1a4) + '\x01';
  return 0;
}



===== mm_alloc_dma_buffer @ 140004d84 =====

void mm_alloc_dma_buffer(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x88),(uint *)(param_1 + 0x90),0x104);
  return;
}



===== mm_alloc_rcq_ring @ 140004db4 =====

void mm_alloc_rcq_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x688),(uint *)(param_1 + 0x690),0x100);
  return;
}



===== mm_alloc_rx_ring @ 140004de4 =====

void mm_alloc_rx_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x4a0),(uint *)(param_1 + 0x4a8),0x100);
  return;
}



===== mm_alloc_sp_ring @ 140004e14 =====

void mm_alloc_sp_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x6e0),(uint *)(param_1 + 0x6f0),0x10);
  return;
}



===== mm_alloc_statusblock @ 140004e44 =====

void mm_alloc_statusblock(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x18),(uint *)(param_1 + 0x28),0x50);
  return;
}



===== mm_alloc_tx_ring @ 140004e70 =====

void mm_alloc_tx_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x2a8),(uint *)(param_1 + 0x2b0),0x100);
  return;
}



===== mm_cfg_vlan_mode @ 140004ea0 =====

undefined8 mm_cfg_vlan_mode(longlong param_1,ushort param_2,char param_3)

{
  uint uVar1;
  
  if (param_3 == '\0') {
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  else {
    if (*(short *)(param_1 + 0xec) == 0x500) {
      uVar1 = (uint)param_2;
    }
    else {
      if ((*(uint *)(param_1 + 0x58) & 0x4000) != 0) {
        *(ushort *)(param_1 + 0x38) = (*(ushort *)(param_1 + 0x38) ^ param_2) & 0x1fff ^ param_2;
        return 0;
      }
      uVar1 = param_2 | 0x10000;
    }
    *(uint *)(param_1 + 0x34) = uVar1;
  }
  return 0;
}



===== mm_dcbx_init @ 140004ef0 =====

undefined8 mm_dcbx_init(longlong param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  
  uVar1 = lm_dcbx_init(param_1);
  uVar2 = 0;
  if ((int)uVar1 == 0) {
    if (*(char *)(param_1 + 0xac) == '\0') {
      param_2[2] = 0;
      *param_2 = 0;
    }
    else {
      param_2[2] = *(undefined1 *)(param_1 + 0xaf);
      *param_2 = *(undefined1 *)(param_1 + 0xad);
      uVar2 = *(undefined1 *)(param_1 + 0xae);
    }
    param_2[1] = uVar2;
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



===== mm_delete_mcast_addr @ 140004f50 =====

undefined8 mm_delete_mcast_addr(longlong param_1,int *param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(byte *)(param_1 + 0x1a4) != 0) {
    do {
      if ((*(int *)(param_1 + 0x1a6 + (longlong)iVar2 * 8) == *param_2) &&
         (*(short *)(param_1 + 0x1aa + (longlong)iVar2 * 8) == (short)param_2[1])) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x1a4));
    if (0x1f < iVar2) {
      return 1;
    }
  }
  psVar1 = (short *)(param_1 + 0x1ac + (longlong)iVar2 * 8);
  *psVar1 = *psVar1 + -1;
  return 0;
}



===== mm_device_bringup @ 140004fb0 =====

undefined8 mm_device_bringup(longlong param_1)

{
  uint uVar1;
  
  uVar1 = 3;
  if (*(char *)(param_1 + 0x1a4) == '\0') {
    uVar1 = 1;
  }
  ev_lm_set_rx_mask(param_1,uVar1);
  ev_lm_enable_intr(param_1);
  return 0;
}



===== mm_device_init @ 140004fe0 =====

undefined8 mm_device_init(byte *param_1)

{
  undefined8 uVar1;
  
  memset(param_1 + 0x2a8,0,0x430);
  memset(param_1,0,0xf8);
  uVar1 = ev_lm_get_dev_info(param_1);
  if (((int)uVar1 == 0) && (uVar1 = ev_lm_init_resc((longlong)param_1), (int)uVar1 == 0)) {
    lm_reset_all_devices((longlong)param_1);
    uVar1 = lm_chip_init(param_1);
    if ((int)uVar1 == 0) {
      ev_lm_init_phy((longlong)param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
      return 0;
    }
  }
  return 1;
}



===== mm_device_poll @ 140005070 =====

undefined8 mm_device_poll(longlong param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  int iVar5;
  uint uVar4;
  int *piVar6;
  undefined8 uVar7;
  
  uVar7 = 0;
  ev_lm_service_intr(param_1);
  iVar2 = *(int *)(param_1 + 0x3f8);
  if (iVar2 != *(int *)(param_1 + 0x3fc)) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x400);
    }
    *(uint *)(param_1 + 0x3f8) = iVar2 - 1U;
    *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + -1;
    iVar5 = *(int *)(param_1 + 0x2dc);
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0x2e0);
    }
    uVar4 = iVar5 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x2d8)) {
      *(undefined8 *)(param_1 + 0x2e8 + (ulonglong)uVar4 * 8) =
           *(undefined8 *)(param_1 + 0x408 + (ulonglong)(iVar2 - 1U) * 8);
      *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
      *(uint *)(param_1 + 0x2dc) = uVar4;
    }
    uVar7 = 1;
  }
  if ((param_2 != 0) && (iVar2 = *(int *)(param_1 + 0x5f0), iVar2 != *(int *)(param_1 + 0x5f4))) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x5f8);
    }
    *(uint *)(param_1 + 0x5f0) = iVar2 - 1U;
    *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
    lVar1 = *(longlong *)(param_1 + 0x600 + (ulonglong)(iVar2 - 1U) * 8);
    piVar6 = *(int **)(lVar1 + 0x38);
    if ((*(int *)(param_1 + 0x34) != 0) || ((*(uint *)(param_1 + 0x58) & 0x200) != 0)) {
      lVar3 = lm_strip_vntag_vlan_hdr(param_1,lVar1);
      piVar6 = (int *)((longlong)piVar6 + (longlong)(int)lVar3);
      *(short *)(lVar1 + 0x24) = *(short *)(lVar1 + 0x24) - (short)lVar3;
    }
    stack_rx_packet(piVar6,*(ushort *)(lVar1 + 0x24));
    iVar2 = *(int *)(param_1 + 0x4d4);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x4d8);
    }
    uVar4 = iVar2 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x4d0)) {
      *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar4 * 8) = lVar1;
      *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
      *(uint *)(param_1 + 0x4d4) = uVar4;
    }
    ev_lm_post_buffers(param_1);
  }
  return uVar7;
}



===== mm_device_shutdown @ 1400051c0 =====

undefined8 mm_device_shutdown(byte *param_1)

{
  ev_lm_disable_intr((longlong)param_1);
  lm_shutdown(param_1);
  return 0;
}



===== mm_flush_rx_buffers_ctrl_on_pf @ 1400051f0 =====

void mm_flush_rx_buffers_ctrl_on_pf(longlong param_1,int param_2)

{
  uint uVar1;
  
  if (1 < *(byte *)(param_1 + 0x13d)) {
    storport_pci_cfg_write_dword(param_1,0x78,0x431520);
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
    if ((uVar1 & 2) == 0) {
      ev_lm_reg_write_ind(param_1,0x43150c,(uint)(param_2 != 0));
    }
  }
  return;
}



===== mm_get_dma_buffer_length @ 140005250 =====

undefined8 mm_get_dma_buffer_length(void)

{
  return 0xdb53;
}



===== mm_get_link_status @ 140005260 =====

undefined4 mm_get_link_status(longlong param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



===== mm_get_mac_addr @ 140005270 =====

undefined8 mm_get_mac_addr(undefined1 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0xf8) == 0) {
    ev_lm_get_dev_info(param_1);
  }
  if ((*(int *)(param_1 + 0x11c) == 0) && (*(short *)(param_1 + 0x120) == 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x116);
    uVar1 = *(undefined2 *)(param_1 + 0x11a);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x11c);
    uVar1 = *(undefined2 *)(param_1 + 0x120);
  }
  *(undefined2 *)(param_2 + 1) = uVar1;
  return 0;
}



===== mm_get_mac_addr_parms @ 1400052e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 mm_get_mac_addr_parms(undefined1 *param_1,undefined4 *param_2)

{
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  ev_lm_get_dev_info(param_1);
  lm_get_mac_addresses((longlong)param_1,&local_38);
  param_2[1] = local_34;
  *param_2 = local_38;
  param_2[3] = local_2c;
  param_2[2] = local_30;
  param_2[5] = local_24;
  param_2[4] = local_28;
  param_2[9] = local_14;
  param_2[8] = local_18;
  param_2[7] = local_1c;
  param_2[6] = local_20;
  return 0;
}



===== mm_get_overwrite_pfn @ 140005370 =====

undefined8 mm_get_overwrite_pfn(longlong param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  *(ushort *)(param_1 + 0x16c) = *param_2;
  lm_get_basic_hw_info(param_1);
  if (*(byte *)(param_1 + 0x138) < 2) {
    uVar3 = 0;
  }
  else {
    *(ushort *)(param_1 + 0x16c) = *param_2;
    *param_2 = *param_2 & 0xfff9;
    uVar1 = read_pci_pfn(*param_2,4);
    uVar2 = uVar1 | 0x400;
    if ((*(uint *)(param_1 + 0x58) & 0x400) == 0) {
      uVar2 = uVar1 & 0xfffffbff;
    }
    write_pci_pfn(*param_2,4,uVar2 | 6);
    uVar2 = read_pci_pfn(*param_2,0x4c);
    if ((uVar2 & 3) != 0) {
      write_pci_pfn(*param_2,0x4c,uVar2 & 0xfffffffc);
    }
    uVar3 = 1;
  }
  return uVar3;
}



===== mm_get_rx_packet @ 140005410 =====

undefined2 mm_get_rx_packet(longlong param_1,void *param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  void *_Src;
  
  mm_device_poll(param_1,0);
  iVar3 = *(int *)(param_1 + 0x5f0);
  if (iVar3 == *(int *)(param_1 + 0x5f4)) {
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x5f8);
    }
    *(uint *)(param_1 + 0x5f0) = iVar3 - 1U;
    *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
    lVar1 = *(longlong *)(param_1 + 0x600 + (ulonglong)(iVar3 - 1U) * 8);
    _Src = *(void **)(lVar1 + 0x38);
    if ((*(int *)(param_1 + 0x34) != 0) || ((*(uint *)(param_1 + 0x58) & 0x200) != 0)) {
      lVar4 = lm_strip_vntag_vlan_hdr(param_1,lVar1);
      _Src = (void *)((longlong)_Src + (longlong)(int)lVar4);
      *(short *)(lVar1 + 0x24) = *(short *)(lVar1 + 0x24) - (short)lVar4;
    }
    memmove(param_2,_Src,(ulonglong)*(ushort *)(lVar1 + 0x24));
    iVar3 = *(int *)(param_1 + 0x4d4);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    uVar5 = iVar3 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x4d0)) {
      *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar5 * 8) = lVar1;
      *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
      *(uint *)(param_1 + 0x4d4) = uVar5;
    }
    ev_lm_post_buffers(param_1);
    uVar2 = *(undefined2 *)(lVar1 + 0x24);
  }
  return uVar2;
}



===== mm_get_timer_in_ms @ 140005500 =====

ulonglong mm_get_timer_in_ms(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_e3(param_1);
  if (*(int *)(param_1 + 0x10c) == 0) {
    uVar1 = storport_mem_read_dword(param_1,0xa5dc);
  }
  else {
    storport_pci_cfg_write_dword(param_1,0x78,0xa5dc);
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
  }
  return (ulonglong)~uVar1 / (ulonglong)((-(uint)((int)uVar2 != 0) & 0x32) + 100);
}



===== mm_init_context @ 14000555c =====

void mm_init_context(longlong param_1)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = mm_get_um_blk();
  puVar2 = (uint *)(param_1 + 0x80);
  plVar1 = (longlong *)(param_1 + 0x78);
  uVar6 = mm_get_dma_buffer(lVar5,plVar1,puVar2,0x12ff);
  if ((int)uVar6 == 0) {
    uVar4 = *puVar2;
    uVar3 = uVar4 + (-uVar4 & 0xfff);
    *puVar2 = uVar3;
    if (uVar3 < uVar4) {
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
    *plVar1 = *plVar1 + (ulonglong)(-uVar4 & 0xfff);
    memset((void *)*plVar1,0,0x300);
  }
  return;
}



===== mm_interrupt_control @ 1400055e0 =====

void mm_interrupt_control(undefined8 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = storport_pci_cfg_read_dword(param_1,4);
  uVar2 = uVar1 & 0xfffffbff;
  if (param_2 == 0) {
    uVar2 = uVar1 | 0x400;
  }
  storport_pci_cfg_write_dword(param_1,4,uVar2);
  return;
}



===== mm_pcicfg_map @ 14000561c =====

void mm_pcicfg_map(longlong param_1,int param_2)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  
  cVar1 = *(char *)(param_1 + 0x138);
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    *(uint *)(&pxp2_pci_registers_map + (ulonglong)*(byte *)(param_1 + 0x138) * 0x10) =
         (uint)*(byte *)(param_1 + 0x138) * 0x2000 + 0x441000;
  }
  else {
    *(uint *)(&pxp2_pci_registers_map + (ulonglong)*(byte *)(param_1 + 0x138) * 0x10) =
         (uint)*(ushort *)(param_1 + 0xb0) * 8 + 0x442000;
  }
  lVar5 = 0;
  iVar3 = 0;
  do {
    if (param_2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)
               (&pxp2_pci_registers_map + (lVar5 + (ulonglong)*(byte *)(param_1 + 0x138) * 4) * 4);
    }
    ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 0x10) + 0x120534 + iVar3,uVar4);
    iVar3 = iVar3 + 4;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 4);
  return;
}



===== mm_set_boot_signature @ 1400056e0 =====

void mm_set_boot_signature(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x13c);
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 != 0) {
    bVar2 = 1 < bVar2;
  }
  ev_lm_reg_write_ind(param_1,(uint)bVar2 * 0x2c + *(int *)(param_1 + 0x4c) + 0x69c,param_2);
  return;
}



===== mm_set_fcoe_mac_addr @ 140005740 =====

undefined8 mm_set_fcoe_mac_addr(longlong param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x192) = *param_2;
  *(undefined2 *)(param_1 + 0x196) = *(undefined2 *)(param_2 + 1);
  return 0;
}



===== mm_set_ibft_address @ 140005760 =====

void mm_set_ibft_address(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 != 0) {
    storport_pci_cfg_write_dword(param_1,0x78,*(undefined4 *)(param_1 + 0x50));
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
    if (0x10c < uVar1) {
      ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x50) + 0x10c,param_2);
    }
  }
  return;
}



===== mm_set_mac_addr @ 1400057c0 =====

void mm_set_mac_addr(longlong param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x172) = *param_2;
  *(undefined2 *)(param_1 + 0x176) = *(undefined2 *)(param_2 + 1);
  ev_lm_set_rx_mask(param_1,*(uint *)(param_1 + 0x6c4));
  return;
}



===== mm_transmit_packet_raw @ 1400057e0 =====

undefined8 mm_transmit_packet_raw(longlong param_1,void *param_2,ushort param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  void *_Dst;
  
  iVar6 = *(int *)(param_1 + 0x2d8);
  if (iVar6 != *(int *)(param_1 + 0x2dc)) {
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x2e0);
    }
    *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + -1;
    *(uint *)(param_1 + 0x2d8) = iVar6 - 1U;
    lVar5 = *(longlong *)(param_1 + 0x2e8 + (ulonglong)(iVar6 - 1U) * 8);
    if (lVar5 != 0) goto LAB_1400058a0;
  }
  iVar6 = 0;
  do {
    ev_lm_service_intr(param_1);
    iVar2 = *(int *)(param_1 + 0x3f8);
    if (iVar2 == *(int *)(param_1 + 0x3fc)) {
      lVar5 = 0;
    }
    else {
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x400);
      }
      *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + -1;
      *(uint *)(param_1 + 0x3f8) = iVar2 - 1U;
      lVar5 = *(longlong *)(param_1 + 0x408 + (ulonglong)(iVar2 - 1U) * 8);
      if (lVar5 != 0) goto LAB_1400058a0;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 10000);
  if (lVar5 == 0) {
    return 1;
  }
LAB_1400058a0:
  _Dst = *(void **)(lVar5 + 0x38);
  *(ushort *)(lVar5 + 0x24) = param_3;
  lm_insert_vntag_vlan_hdr(param_1,lVar5);
  bVar1 = *(byte *)(lVar5 + 0x28);
  if (bVar1 != 0) {
    _Dst = (void *)((longlong)_Dst + (ulonglong)bVar1);
  }
  memmove(_Dst,param_2,(ulonglong)param_3);
  if (bVar1 != 0) {
    puVar3 = *(undefined1 **)(lVar5 + 0x38);
    lVar4 = 0xc;
    do {
      *puVar3 = puVar3[bVar1];
      puVar3 = puVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    lm_insert_vntag_vlan_hdr(param_1,lVar5);
    *(short *)(lVar5 + 0x24) = *(short *)(lVar5 + 0x24) + (ushort)bVar1;
  }
  *(byte *)(lVar5 + 0x48) = 1;
  *(undefined2 *)(lVar5 + 0x2a) = 0;
  *(undefined8 *)(lVar5 + 0x50) = *(undefined8 *)(lVar5 + 0x40);
  *(undefined2 *)(lVar5 + 0x4a) = *(undefined2 *)(lVar5 + 0x24);
  *(undefined2 *)(lVar5 + 0x58) = *(undefined2 *)(lVar5 + 0x24);
  if (*(int *)(param_1 + 0x34) != 0) {
    *(ushort *)(lVar5 + 0x2a) = *(ushort *)(lVar5 + 0x2a) | 1;
    *(undefined2 *)(lVar5 + 0x2c) = *(undefined2 *)(param_1 + 0x34);
  }
  ev_lm_send_packet(param_1,lVar5,(byte *)(lVar5 + 0x48));
  return 0;
}



===== nx3_get_intf @ 14000595c =====

undefined8 nx3_get_intf(undefined8 *param_1)

{
  *param_1 = &DAT_14001e9f0;
  param_1[0xb] = mm_device_init;
  param_1[0xc] = mm_device_shutdown;
  param_1[10] = mm_get_link_status;
  param_1[1] = mm_get_dma_buffer;
  param_1[2] = CrashDumpAdapterControl;
  param_1[3] = mm_get_rx_packet;
  param_1[4] = mm_transmit_packet_raw;
  param_1[5] = mm_get_dma_buffer_length;
  param_1[6] = ev_dir_get_fcoe_block;
  param_1[7] = mm_get_mac_addr;
  param_1[8] = mm_set_mac_addr;
  param_1[9] = mm_device_poll;
  param_1[0xd] = mm_device_bringup;
  param_1[0xe] = mm_dcbx_init;
  param_1[0xf] = mm_add_mcast_addr;
  param_1[0x10] = mm_delete_mcast_addr;
  param_1[0x11] = mm_set_fcoe_mac_addr;
  param_1[0x12] = mm_cfg_vlan_mode;
  param_1[0x13] = mm_get_timer_in_ms;
  param_1[0x14] = mm_set_boot_signature;
  param_1[0x15] = mm_get_overwrite_pfn;
  param_1[0x16] = mm_get_mac_addr_parms;
  param_1[0x17] = mm_interrupt_control;
  param_1[0x18] = mm_flush_rx_buffers_ctrl_on_pf;
  param_1[0x19] = mm_set_ibft_address;
  return 0;
}



===== ev_lm_disable_intr @ 140005a9c =====

void ev_lm_disable_intr(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    iVar3 = (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x108000;
    uVar1 = ev_lm_reg_read_ind(param_1,iVar3);
    uVar1 = uVar1 & 0xffffffe7;
  }
  else {
    iVar3 = 0x130154;
    uVar1 = ev_lm_reg_read_ind(param_1,0x130154);
    uVar1 = uVar1 & 0xfffffffb;
  }
  ev_lm_reg_write_ind(param_1,iVar3,uVar1);
  return;
}



===== ev_lm_enable_intr @ 140005b00 =====

void ev_lm_enable_intr(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    iVar3 = (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x108000;
    uVar1 = ev_lm_reg_read_ind(param_1,iVar3);
    uVar1 = uVar1 | 8;
  }
  else {
    iVar3 = 0x130154;
    uVar1 = ev_lm_reg_read_ind(param_1,0x130154);
    uVar1 = uVar1 | 4;
  }
  ev_lm_reg_write_ind(param_1,iVar3,uVar1);
  return;
}



===== ev_lm_get_dev_info @ 140005b64 =====

undefined8 ev_lm_get_dev_info(undefined1 *param_1)

{
  byte bVar1;
  bool bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined7 extraout_var;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined7 extraout_var_00;
  ushort uVar9;
  uint uVar10;
  longlong lVar11;
  undefined2 *puVar12;
  undefined4 local_58;
  undefined1 local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [28];
  
  bVar2 = lm_get_basic_hw_info((longlong)param_1);
  if ((((int)CONCAT71(extraout_var,bVar2) == 1) ||
      (uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + (uint)(byte)param_1[0x138] * 4)
      , (uVar4 & 0x600000) != 0x600000)) || ((uVar4 & 0xff000000) != 0x41000000)) {
    uVar8 = 1;
  }
  else {
    uVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 +
                                       (uint)(byte)param_1[0x13b] * 0x2c);
    *(undefined2 *)(param_1 + 0x32) = uVar3;
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1c);
    *(undefined4 *)(param_1 + 0x44) = uVar5;
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x360 +
                                       ((byte)param_1[0x13d] >> 1 & 1) * 0x74);
    bVar1 = param_1[0x13c];
    *(undefined4 *)(param_1 + 0x48) = uVar5;
    local_54._0_2_ = local_54._1_2_;
    local_4c._0_2_ = local_4c._1_2_;
    local_44._0_2_ = local_44._1_2_;
    lm_get_mac_addresses((longlong)param_1,&local_58);
    param_1[0x110] = local_54[1];
    param_1[0x111] = local_54[0];
    param_1[0x112] = (char)((uint)local_58 >> 0x18);
    param_1[0x113] = (char)((uint)local_58 >> 0x10);
    param_1[0x114] = (char)((uint)local_58 >> 8);
    param_1[0x115] = (char)local_58;
    param_1[0x116] = local_4c[1];
    param_1[0x117] = local_4c[0];
    param_1[0x118] = local_54[7];
    param_1[0x119] = local_54[6];
    param_1[0x11a] = local_54[5];
    param_1[0x11b] = local_54[4];
    param_1[0x11c] = local_44[1];
    param_1[0x11d] = local_44[0];
    param_1[0x11e] = local_4c[7];
    param_1[0x11f] = local_4c[6];
    param_1[0x120] = local_4c[5];
    param_1[0x121] = local_4c[4];
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x368 +
                                       ((byte)param_1[0x13d] >> 1 & 1) * 0x74);
    if ((uVar4 >> 0x10 & 1) != 0) {
      *(uint *)(param_1 + 0x34) = uVar4;
    }
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b0 +
                                       (uint)(byte)param_1[0x138] * 400);
    *(undefined4 *)(param_1 + 0x134) = uVar5;
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x378 +
                                       (uint)(byte)param_1[0x138] * 0x74);
    *(undefined4 *)(param_1 + 0x144) = uVar5;
    uVar5 = ev_lm_reg_read_ind(param_1,((byte)param_1[0x138] + 1) * 400 + *(int *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x148) = uVar5;
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x30);
    *(undefined4 *)(param_1 + 0x168) = uVar5;
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x70 +
                                       (uint)(byte)param_1[0x138] * 400);
    uVar9 = (ushort)uVar5 & 0xff;
    *(ushort *)(param_1 + 0x15e) = uVar9;
    *(ushort *)(param_1 + 0x162) = uVar9;
    *(ushort *)(param_1 + 0x164) = (ushort)((uint)uVar5 >> 0x10) & 0xff;
    *(ushort *)(param_1 + 0x160) = (ushort)(byte)((uint)uVar5 >> 0x18);
    uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x74 +
                                       (uint)(byte)param_1[0x138] * 400);
    *(ushort *)(param_1 + 0x15a) = (ushort)((uint)uVar5 >> 8) & 0xff;
    *(ushort *)(param_1 + 0x15c) = (ushort)((uint)uVar5 >> 0x10) & 0xff;
    iVar6 = ev_lm_reg_read_ind(param_1,0x10394);
    if (iVar6 != 0) {
      *(ushort *)(param_1 + 0x14e) = *(ushort *)(param_1 + 0x14e) | 1;
    }
    iVar6 = 0;
    lVar11 = 2;
    puVar12 = (undefined2 *)(param_1 + 0x9e);
    do {
      uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xa0 +
                                         ((uint)(byte)param_1[0x138] * 100 + iVar6) * 4);
      puVar12[-1] = (short)uVar5;
      *puVar12 = (short)((uint)uVar5 >> 0x10);
      uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xa8 +
                                         ((uint)(byte)param_1[0x138] * 100 + iVar6) * 4);
      puVar12[3] = (short)uVar5;
      iVar6 = iVar6 + 1;
      puVar12[4] = (short)((uint)uVar5 >> 0x10);
      lVar11 = lVar11 + -1;
      puVar12 = puVar12 + 2;
    } while (lVar11 != 0);
    uVar7 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar7 & 2) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 2;
    }
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x358 +
                                       (uint)(byte)param_1[0x138] * 0x74);
    if ((uVar4 >> 0x1a & 1) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
    }
    if ((uVar4 >> 0x18 & 1) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20;
    }
    if ((uVar4 & 0x100) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
    }
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar4 & 0x700) == 0x400) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x204;
    }
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar4 & 0x700) == 0x600) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
    }
    uVar8 = lm_is_mf_device((longlong)param_1);
    if (((int)uVar8 != 0) &&
       (bVar2 = lm_is_mf_cfg((longlong)param_1), (int)CONCAT71(extraout_var_00,bVar2) != 0)) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x40;
      uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
      if ((uVar4 & 0x700) == 0) {
        uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + (uint)bVar1 * 0x18);
        if ((uVar4 & 6) == 0) {
          uVar7 = 8;
        }
        else {
          uVar7 = 4;
          if ((uVar4 & 6) != 6) {
            uVar7 = 0;
          }
        }
      }
      else {
        uVar7 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xe4 + (uint)bVar1 * 0x28);
      }
      if ((uVar7 & 4) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x80;
      }
      if ((uVar7 & 8) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100;
      }
    }
    uVar7 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x358 +
                                       (uint)(byte)param_1[0x138] * 0x74);
    if ((uVar7 & 0xc00) != 0) {
      uVar4 = *(uint *)(param_1 + 0x58);
      uVar10 = uVar4 | 0x800;
      *(uint *)(param_1 + 0x58) = uVar10;
      if ((uVar7 & 0x800) != 0) {
        uVar10 = uVar4 | 0x1800;
        *(uint *)(param_1 + 0x58) = uVar10;
      }
      if ((uVar7 & 0x400) != 0) {
        *(uint *)(param_1 + 0x58) = uVar10 | 0x2000;
      }
    }
    param_1[0x172] = param_1[0x110];
    param_1[0x173] = param_1[0x111];
    param_1[0x174] = param_1[0x112];
    param_1[0x175] = param_1[0x113];
    param_1[0x176] = param_1[0x114];
    param_1[0x177] = param_1[0x115];
    *(undefined4 *)(param_1 + 0x17a) = 0x100010;
    *(undefined4 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined2 *)(param_1 + 0x185) = 0x202;
    *param_1 = 0;
    *(undefined8 *)(param_1 + 0xb4) = 0;
    lm_get_phy_info((longlong)param_1,0);
    ev_mm_get_user_config((longlong)param_1);
    *(undefined2 *)(param_1 + 0x170) = 0x5ea;
    uVar8 = 0;
  }
  return uVar8;
}



===== ev_lm_get_interrupt_status @ 1400060c4 =====

undefined2 ev_lm_get_interrupt_status(longlong param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (*(short *)(lVar2 + 0x28) != *(short *)(param_1 + 100)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x28);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 4;
    *(undefined2 *)(param_1 + 100) = uVar1;
  }
  if (*(short *)(lVar2 + 0x18) != *(short *)(param_1 + 0x66)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x18);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 2;
    *(undefined2 *)(param_1 + 0x66) = uVar1;
  }
  if (*(short *)(lVar2 + 0x38) != *(short *)(param_1 + 0x68)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x38);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 8;
    *(undefined2 *)(param_1 + 0x68) = uVar1;
  }
  if (*(short *)(lVar2 + 0x48) != *(short *)(param_1 + 0x6a)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x48);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 0x10;
    *(undefined2 *)(param_1 + 0x6a) = uVar1;
  }
  return *(undefined2 *)(param_1 + 0x6c);
}



===== ev_lm_init_phy @ 14000612c =====

undefined8 ev_lm_init_phy(longlong param_1,byte param_2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  *(undefined1 *)(param_1 + 0x18c) = 6;
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar5 = lm_is_e3(param_1);
    if ((int)uVar5 != 0) goto LAB_140006181;
    iVar7 = (uint)bVar1 * 0x18 + 0x10340;
  }
  else {
    iVar7 = 0xa9cc;
  }
  uVar2 = ev_lm_reg_read_ind(param_1,iVar7);
  *(undefined2 *)(param_1 + 0x122) = uVar2;
LAB_140006181:
  if ((*(uint *)(param_1 + 0x58) & 0x10000) == 0) {
    uVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 + (uint)bVar1 * 0x10);
    *(uint *)(param_1 + 4) = (~uVar3 & 1) + 4;
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
    uVar4 = lm_get_link_speed(param_1);
    *(undefined4 *)(param_1 + 0xc) = uVar4;
  }
  else {
    *(byte *)(param_1 + 0x14c) = (byte)(*(uint *)(param_1 + 0x134) >> 0xe) & 3;
    *(char *)(param_1 + 0x13f) = (char)(*(uint *)(param_1 + 0x134) >> 8);
    *(undefined1 *)(param_1 + 0x140) = *(undefined1 *)(param_1 + 0x134);
    everest_init_nig_mdio(param_1);
    ev_lm_reg_write_ind(param_1,0xa5a4,0x1f0 << ((*(byte *)(param_1 + 0x138) & 1) << 4));
    mm_stall(500);
    if (((param_2 - 0xf7 & 0xfffffff9) == 0) && (param_2 != 0xf9)) {
      uVar3 = *(uint *)(param_1 + 0x18c) & 0xffffff00 | (uint)param_2;
      *(uint *)(param_1 + 0x18c) = uVar3;
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x18c);
    }
    lm_phy_initialize_link(param_1,uVar3);
    if (*(int *)(param_1 + 4) == 4) {
      iVar7 = 0;
      do {
        uVar6 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 +
                                           (uint)*(byte *)(param_1 + 0x13c) * 0x18);
        if ((uVar6 & 8) == 0) break;
        mm_stall(1000000);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x1e);
      if ((uVar6 & 8) != 0) {
        *(undefined4 *)(param_1 + 4) = 5;
      }
    }
  }
  return 0;
}



===== ev_lm_init_resc @ 1400062ac =====

undefined8 ev_lm_init_resc(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar5;
  uint uVar4;
  int iVar6;
  
  mm_alloc_dma_buffer(param_1);
  mm_alloc_statusblock(param_1);
  *(undefined4 *)(param_1 + 0x488) = 1;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined8 *)(param_1 + 0x368) = 0;
  *(undefined8 *)(param_1 + 0x3f8) = 0;
  *(undefined8 *)(param_1 + 0x2e0) = 0x10;
  *(undefined8 *)(param_1 + 0x370) = 0x10;
  *(undefined8 *)(param_1 + 0x400) = 0x10;
  mm_alloc_tx_ring(param_1);
  *(undefined4 *)(param_1 + 700) = 0;
  lVar2 = *(longlong *)(param_1 + 0x2a8);
  *(longlong *)(param_1 + 0x2c0) = lVar2;
  *(undefined4 *)(param_1 + 0x2d0) = 0xf;
  *(longlong *)(param_1 + 0x2c8) = *(longlong *)(param_1 + 0x18) + 0x20;
  lm_setup_bd_chain_ring(lVar2,(uint *)(param_1 + 0x2b0),1);
  *(undefined4 *)(param_1 + 0x6c0) = 1;
  *(undefined8 *)(param_1 + 0x4d0) = 0;
  *(undefined8 *)(param_1 + 0x4d8) = 0x10;
  *(undefined8 *)(param_1 + 0x560) = 0;
  *(undefined8 *)(param_1 + 0x568) = 0x10;
  *(undefined8 *)(param_1 + 0x5f0) = 0;
  *(undefined8 *)(param_1 + 0x5f8) = 0x10;
  mm_alloc_rx_ring(param_1);
  plVar1 = (longlong *)(param_1 + 0x4a0);
  lm_setup_bd_chain_ring(*plVar1,(uint *)(param_1 + 0x4a8),1);
  *(longlong *)(param_1 + 0x4b8) = *plVar1;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0xf;
  mm_alloc_rcq_ring(param_1);
  lm_setup_bd_chain_ring(*(longlong *)(param_1 + 0x688),(uint *)(param_1 + 0x690),1);
  *(undefined2 *)(param_1 + 0x6b8) = 0xf;
  *(longlong *)(param_1 + 0x6b0) = *(longlong *)(param_1 + 0x18) + 0x10;
  *(undefined8 *)(param_1 + 0x6a0) = *(undefined8 *)(param_1 + 0x688);
  iVar6 = 0;
  *(undefined8 *)(param_1 + 0x6a8) = *(undefined8 *)(param_1 + 0x688);
  *(undefined4 *)(param_1 + 0x698) = 1;
  if (*(short *)(param_1 + 0x17a) != 0) {
    do {
      puVar3 = (undefined8 *)ev_mm_get_tx_desc(param_1,iVar6);
      *(undefined4 *)(puVar3 + 1) = 0x7450324c;
      *puVar3 = 0;
      *(undefined1 *)((longlong)puVar3 + 0xc) = 0;
      puVar3[2] = param_1;
      puVar3[3] = (longlong *)(param_1 + 0x2a8);
      *(undefined1 *)(puVar3 + 5) = 0;
      iVar5 = *(int *)(param_1 + 0x2dc);
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x2e0);
      }
      uVar4 = iVar5 - 1;
      if (uVar4 != *(uint *)(param_1 + 0x2d8)) {
        *(undefined8 **)(param_1 + 0x2e8 + (ulonglong)uVar4 * 8) = puVar3;
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
        *(uint *)(param_1 + 0x2dc) = uVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x17a));
  }
  iVar6 = 0;
  if (*(short *)(param_1 + 0x17c) != 0) {
    do {
      puVar3 = (undefined8 *)ev_mm_get_rx_desc(param_1,iVar6);
      *(undefined4 *)(puVar3 + 1) = 0x7250324c;
      *puVar3 = 0;
      *(undefined1 *)((longlong)puVar3 + 0xc) = 1;
      puVar3[2] = param_1;
      puVar3[3] = plVar1;
      *(undefined1 *)(puVar3 + 5) = 0;
      *(undefined2 *)(puVar3 + 9) = 0x600;
      iVar5 = *(int *)(param_1 + 0x4d4);
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x4d8);
      }
      uVar4 = iVar5 - 1;
      if (uVar4 != *(uint *)(param_1 + 0x4d0)) {
        *(undefined8 **)(param_1 + 0x4e0 + (ulonglong)uVar4 * 8) = puVar3;
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x17c));
  }
  ev_mm_initialize_packets(param_1);
  return 0;
}



===== ev_lm_post_buffers @ 14000652c =====

int ev_lm_post_buffers(longlong param_1)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  longlong lVar7;
  short sVar8;
  undefined4 *puVar9;
  
  iVar3 = *(int *)(param_1 + 0x4d0);
  iVar5 = 0;
  if (iVar3 == *(int *)(param_1 + 0x4d4)) {
    lVar7 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
    *(uint *)(param_1 + 0x4d0) = iVar3 - 1U;
    lVar7 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(iVar3 - 1U) * 8);
  }
  sVar6 = *(short *)(param_1 + 0x4b4);
  sVar8 = *(short *)(param_1 + 0x698);
  puVar1 = *(undefined4 **)(param_1 + 0x4b8);
  while (puVar9 = puVar1, lVar7 != 0) {
    puVar9 = puVar1 + 4;
    sVar2 = sVar6 + 1;
    if (((byte)(sVar6 + 1) & 0xf) == 0xf) {
      puVar9 = *(undefined4 **)(puVar1 + 6);
      sVar2 = sVar6 + 2;
    }
    sVar6 = sVar2;
    *(short *)(lVar7 + 0x36) = sVar6;
    puVar1[1] = *(undefined4 *)(lVar7 + 0x44);
    *puVar1 = *(undefined4 *)(lVar7 + 0x40);
    *(int *)(param_1 + 0x4c8) = *(int *)(param_1 + 0x4c8) + -1;
    *(short *)(param_1 + 0x6b8) = *(short *)(param_1 + 0x6b8) + -1;
    iVar3 = *(int *)(param_1 + 0x564);
    sVar8 = (((char)sVar8 + 1U & 0xf) == 0xf) + 1 + sVar8;
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x568);
    }
    uVar4 = iVar3 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x560)) {
      *(longlong *)(param_1 + 0x570 + (ulonglong)uVar4 * 8) = lVar7;
      *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + 1;
      *(uint *)(param_1 + 0x564) = uVar4;
    }
    iVar5 = iVar5 + 1;
    if ((*(int *)(param_1 + 0x4c8) == 0) ||
       (iVar3 = *(int *)(param_1 + 0x4d0), iVar3 == *(int *)(param_1 + 0x4d4))) break;
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
    *(uint *)(param_1 + 0x4d0) = iVar3 - 1U;
    puVar1 = puVar9;
    lVar7 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(iVar3 - 1U) * 8);
  }
  *(short *)(param_1 + 0x4b4) = sVar6;
  *(undefined4 **)(param_1 + 0x4b8) = puVar9;
  *(short *)(param_1 + 0x698) = sVar8;
  if (iVar5 != 0) {
    lm_update_tstorm_rx_indices(param_1,sVar8,sVar6);
  }
  return iVar5;
}



===== ev_lm_send_packet @ 1400066b4 =====

undefined8 ev_lm_send_packet(longlong param_1,longlong param_2,byte *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  short sVar14;
  undefined4 local_res8;
  
  *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*param_3;
  puVar1 = *(undefined4 **)(param_1 + 0x2c0);
  sVar14 = *(short *)(param_1 + 700);
  bVar6 = 0;
  iVar4 = 0;
  puVar10 = puVar1;
  pbVar12 = param_3 + 8;
  puVar13 = puVar1;
  bVar7 = 0;
  if (*param_3 != 0) {
    do {
      puVar10 = puVar13;
      *puVar10 = *(undefined4 *)pbVar12;
      puVar10[1] = *(undefined4 *)(pbVar12 + 4);
      bVar6 = bVar7 + 1;
      *(undefined2 *)((longlong)puVar10 + 10) = *(undefined2 *)(pbVar12 + 8);
      *(undefined1 *)((longlong)puVar10 + 0xe) = 0;
      puVar13 = puVar10 + 4;
      sVar2 = sVar14 + 1;
      if (((byte)(sVar14 + 1) & 0xf) == 0xf) {
        puVar13 = *(undefined4 **)(puVar10 + 6);
        bVar6 = bVar7 + 2;
        sVar2 = sVar14 + 2;
      }
      sVar14 = sVar2;
      iVar4 = iVar4 + 1;
      pbVar12 = pbVar12 + 0x10;
      bVar7 = bVar6;
    } while (iVar4 < (int)(uint)*param_3);
  }
  bVar7 = *(byte *)((longlong)puVar1 + 0xe);
  *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 2;
  *(ushort *)(puVar1 + 2) = (ushort)*param_3;
  if (*(short *)(param_1 + 0x38) != 0) {
    *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 3;
    *(undefined2 *)(puVar1 + 3) = *(undefined2 *)(param_1 + 0x38);
    if (*(short *)(param_1 + 0xec) == 0x500) {
      *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 0xb;
    }
  }
  *(byte *)((longlong)puVar10 + 0xe) = *(byte *)((longlong)puVar10 + 0xe) | 4;
  *(ushort *)(param_2 + 0x30) = (ushort)*param_3;
  *(short *)(param_2 + 0x2e) = sVar14;
  *(undefined4 **)(param_1 + 0x2c0) = puVar13;
  *(short *)(param_1 + 700) = sVar14;
  iVar4 = *(int *)(param_1 + 0x36c);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x370);
  }
  uVar5 = iVar4 - 1;
  if (uVar5 != *(uint *)(param_1 + 0x368)) {
    *(longlong *)(param_1 + 0x378 + (ulonglong)uVar5 * 8) = param_2;
    *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + 1;
    *(uint *)(param_1 + 0x36c) = uVar5;
  }
  local_res8 = CONCAT22(1,(ushort)bVar6 << 8);
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) == 0x164e0000) {
    uVar5 = -(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x80000000;
  }
  else {
    uVar5 = (*(byte *)(param_1 + 0x13e) & 1 | (uint)*(byte *)(param_1 + 0x13b) * 2) << 0x1d;
  }
  uVar11 = *(uint *)(param_1 + 0x58) & 0x20000;
  if (uVar11 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (uint)*(byte *)(param_1 + 0x13e);
  }
  uVar3 = lm_is_e3(param_1);
  if (((int)uVar3 == 0) || (*(char *)(param_1 + 0x138) == '\0')) {
    if ((uVar11 == 0) && (*(byte *)(param_1 + 0x13d) < 2)) {
      storport_pci_cfg_write_dword(param_1,0x90,uVar5);
      storport_pci_cfg_write_dword(param_1,0x94,local_res8);
      return 0;
    }
    if (*(char *)(param_1 + 0x138) == '\0') {
      ev_lm_reg_write_ind(param_1,0x17008c,uVar5);
      uVar3 = lm_is_dual_core(param_1);
      if ((int)uVar3 != 0) {
        ev_lm_reg_write_ind(param_1,0x1701b0,uVar9);
      }
      uVar8 = 0x170208;
      goto LAB_1400068ef;
    }
  }
  ev_lm_reg_write_ind(param_1,0x170090,uVar5);
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 != 0) {
    ev_lm_reg_write_ind(param_1,0x1701b4,uVar9);
  }
  uVar8 = 0x17020c;
LAB_1400068ef:
  ev_lm_reg_write_ind(param_1,uVar8,local_res8);
  return 0;
}



===== ev_lm_service_intr @ 140006918 =====

void ev_lm_service_intr(longlong param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined6 extraout_var;
  undefined8 uVar4;
  
  uVar1 = ev_lm_get_interrupt_status(param_1);
  if ((int)CONCAT62(extraout_var,uVar1) != 0) {
    *(undefined2 *)(param_1 + 0x5c) = 1;
    if ((uVar1 & 2) != 0) {
      if ((*(short **)(param_1 + 0x6b0) != (short *)0x0) &&
         (**(short **)(param_1 + 0x6b0) != *(short *)(param_1 + 0x69a))) {
        ev_lm_service_rx_intr(param_1);
      }
      if (*(int *)(param_1 + 0x4d0) != *(int *)(param_1 + 0x4d4)) {
        ev_lm_post_buffers(param_1);
      }
    }
    if (((((*(uint *)(param_1 + 0x58) & 0x10000) != 0) && (*(int *)(param_1 + 4) == 4)) &&
        ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) && (*(int *)(param_1 + 0x6c8) == 0)) {
      uVar4 = lm_acquire_mdio_hw_lock(param_1,0);
      if ((int)uVar4 == 0) {
        lm_phy_set_aer_mmd(param_1);
        sVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83ea);
        if (sVar2 != 0) {
          uVar3 = lm_get_link_speed(param_1);
          if ((uVar3 & 0xff00) == 0x600) {
            *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
            if (20000 < *(int *)(param_1 + 0xf0)) {
              *(undefined4 *)(param_1 + 0xf0) = 0;
              lm_enable_xmac(param_1,0);
            }
            mm_stall(1);
          }
        }
        lm_release_mdio_hw_lock(param_1);
      }
    }
    if ((((uVar1 & 4) != 0) && (*(short **)(param_1 + 0x2c8) != (short *)0x0)) &&
       (**(short **)(param_1 + 0x2c8) != *(short *)(param_1 + 0x2be))) {
      ev_lm_service_tx_intr(param_1);
    }
  }
  return;
}



===== ev_lm_service_rx_intr @ 140006a74 =====

void ev_lm_service_rx_intr(longlong param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  short sVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  short sVar10;
  short sVar11;
  longlong lVar12;
  undefined2 uVar13;
  
  if (*(int *)(param_1 + 0xb4) == 0) {
    *(undefined4 *)(param_1 + 0xb4) = 1;
    sVar11 = **(short **)(param_1 + 0x6b0);
    if (((byte)sVar11 & 0xf) == 0xf) {
      sVar11 = sVar11 + 1;
    }
    uVar13 = *(undefined2 *)(param_1 + 0x4b6);
    sVar10 = *(short *)(param_1 + 0x69a);
    while (sVar10 != sVar11) {
      pcVar3 = *(char **)(param_1 + 0x6a8);
      *(char **)(param_1 + 0x6a8) = pcVar3 + 0x10;
      sVar5 = sVar10 + 1;
      if (((byte)(sVar10 + 1) & 0xf) == 0xf) {
        *(undefined8 *)(param_1 + 0x6a8) = *(undefined8 *)(pcVar3 + 0x18);
        sVar5 = sVar10 + 2;
      }
      sVar10 = sVar5;
      if (*pcVar3 == '\x01') {
        cVar1 = pcVar3[7];
        *(undefined1 *)(param_1 + 0x6d8) = 0;
        if ((pcVar3[8] & 1U) == 0) {
          *(char *)(param_1 + 0x6e) = cVar1;
        }
        *(short *)(param_1 + 0x698) = *(short *)(param_1 + 0x698) + 1;
        if (((byte)*(short *)(param_1 + 0x698) & 0xf) == 0xf) {
          *(short *)(param_1 + 0x698) = *(short *)(param_1 + 0x698) + 1;
        }
      }
      else {
        iVar7 = *(int *)(param_1 + 0x560);
        if (iVar7 == *(int *)(param_1 + 0x564)) break;
        if (iVar7 == 0) {
          iVar7 = *(int *)(param_1 + 0x568);
        }
        *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + -1;
        *(uint *)(param_1 + 0x560) = iVar7 - 1U;
        lVar12 = *(longlong *)(param_1 + 0x570 + (ulonglong)(iVar7 - 1U) * 8);
        if (lVar12 == 0) break;
        *(int *)(param_1 + 0x4c8) = *(int *)(param_1 + 0x4c8) + 1;
        uVar13 = *(undefined2 *)(lVar12 + 0x36);
        *(undefined4 *)(lVar12 + 0x20) = 0;
        *(undefined2 *)(lVar12 + 0x24) = *(undefined2 *)(pcVar3 + 6);
        *(undefined4 *)(lVar12 + 0x2c) = 0;
        *(int *)(param_1 + 0x6c8) = *(int *)(param_1 + 0x6c8) + 1;
        if ((*(uint *)(param_1 + 0x58) & 0x200000) == 0) {
          pbVar4 = *(byte **)(lVar12 + 0x38);
          iVar7 = 1;
          bVar6 = *pbVar4;
          if (bVar6 == 0xff) {
            iVar7 = 3;
LAB_140006c41:
            bVar6 = lm_validate_vntag_vlan_hdr(param_1,lVar12,iVar7);
          }
          else {
            if (((bVar6 & 1) == 0) && ((bVar6 != 0x33 || (pbVar4[1] != 0x33)))) goto LAB_140006c41;
            bVar2 = *(byte *)(param_1 + 0x1a4);
            iVar7 = 2;
            uVar8 = 0;
            if (bVar2 != 0) {
              pbVar9 = (byte *)(param_1 + 0x1a7);
              do {
                if (((((pbVar9[-1] == bVar6) && (*pbVar9 == pbVar4[1])) && (pbVar9[1] == pbVar4[2]))
                    && ((pbVar9[2] == pbVar4[3] && (pbVar9[3] == pbVar4[4])))) &&
                   (pbVar9[4] == pbVar4[5])) break;
                uVar8 = uVar8 + 1;
                pbVar9 = pbVar9 + 8;
              } while ((int)uVar8 < (int)(uint)bVar2);
            }
            if (bVar2 != uVar8) goto LAB_140006c41;
            bVar6 = 1;
          }
          if ((*(ushort *)(param_1 + 0x38) != 0) &&
             (((*(ushort *)(param_1 + 0x38) ^ *(ushort *)(pcVar3 + 4)) & 0xfff) != 0)) {
            bVar6 = 1;
          }
        }
        else {
          bVar6 = 1;
        }
        if (pcVar3[1] != '\0') {
          *(int *)(param_1 + 0x6cc) = *(int *)(param_1 + 0x6cc) + 1;
          bVar6 = 1;
        }
        sVar11 = **(short **)(param_1 + 0x6b0);
        if (((byte)sVar11 & 0xf) == 0xf) {
          sVar11 = sVar11 + 1;
        }
        if (bVar6 == 0) {
          iVar7 = *(int *)(param_1 + 0x5f4);
          if (iVar7 == 0) {
            iVar7 = *(int *)(param_1 + 0x5f8);
          }
          uVar8 = iVar7 - 1;
          if (uVar8 != *(uint *)(param_1 + 0x5f0)) {
            *(longlong *)(param_1 + 0x600 + (ulonglong)uVar8 * 8) = lVar12;
            *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + 1;
            *(uint *)(param_1 + 0x5f4) = uVar8;
          }
        }
        else {
          iVar7 = *(int *)(param_1 + 0x4d4);
          if (iVar7 == 0) {
            iVar7 = *(int *)(param_1 + 0x4d8);
          }
          uVar8 = iVar7 - 1;
          if (uVar8 != *(uint *)(param_1 + 0x4d0)) {
            *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar8 * 8) = lVar12;
            *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
            *(uint *)(param_1 + 0x4d4) = uVar8;
          }
        }
      }
      *(short *)(param_1 + 0x6b8) = *(short *)(param_1 + 0x6b8) + 1;
      *(undefined2 *)(param_1 + 0x4b6) = uVar13;
      *(short *)(param_1 + 0x69a) = sVar10;
      lm_update_tstorm_rx_indices
                (param_1,*(undefined2 *)(param_1 + 0x698),*(undefined2 *)(param_1 + 0x4b4));
    }
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return;
}



===== ev_lm_service_tx_intr @ 140006d58 =====

void ev_lm_service_tx_intr(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  
  if (*(int *)(param_1 + 0xb8) == 0) {
    *(undefined4 *)(param_1 + 0xb8) = 1;
    sVar5 = *(short *)(param_1 + 0x2be);
    if (sVar5 != **(short **)(param_1 + 0x2c8)) {
      do {
        iVar3 = *(int *)(param_1 + 0x368);
        if (iVar3 == *(int *)(param_1 + 0x36c)) break;
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x370);
        }
        *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + -1;
        *(uint *)(param_1 + 0x368) = iVar3 - 1U;
        lVar2 = *(longlong *)(param_1 + 0x378 + (ulonglong)(iVar3 - 1U) * 8);
        if (lVar2 == 0) break;
        *(undefined4 *)(lVar2 + 0x20) = 0;
        *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) + (uint)*(ushort *)(lVar2 + 0x30);
        sVar1 = **(short **)(param_1 + 0x2c8);
        iVar3 = *(int *)(param_1 + 0x3fc);
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x400);
        }
        uVar4 = iVar3 - 1;
        if (uVar4 != *(uint *)(param_1 + 0x3f8)) {
          *(longlong *)(param_1 + 0x408 + (ulonglong)uVar4 * 8) = lVar2;
          *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + 1;
          *(uint *)(param_1 + 0x3fc) = uVar4;
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 != sVar1);
    }
    *(short *)(param_1 + 0x2be) = sVar5;
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  return;
}



===== ev_lm_set_rx_mask @ 140006e34 =====

undefined8 ev_lm_set_rx_mask(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 local_res8;
  
  *(uint *)(param_1 + 0x6c4) = param_2;
  uVar3 = 0x1b8;
  if (param_2 != 0) {
    uVar3 = 0x138;
    if ((*(char *)(param_1 + 0x1a4) != '\0') || ((param_2 & 4) != 0)) {
      uVar3 = 0x118;
    }
    if ((param_2 >> 0x10 & 1) != 0) {
      uVar3 = uVar3 & 0xffcf;
    }
  }
  uVar1 = lm_is_e3(param_1);
  uVar2 = uVar3 & 0xffcf;
  if ((int)uVar1 == 0) {
    uVar2 = uVar3;
  }
  local_res8._0_4_ = (uint)uVar2 << 0x10;
  local_res8 = CONCAT44(0x5fc,(int)local_res8);
  lm_set_mac_addrs(param_1);
  if (*(short *)(param_1 + 0x38) == 0) {
    local_res8 = (ulonglong)local_res8._1_7_ << 8;
  }
  else {
    local_res8 = (ulonglong)local_res8._1_7_ << 8 | 1;
  }
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 200),(int)local_res8);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 200) + 4,local_res8._4_4_);
  return 0;
}



===== everest_init_ccm_common @ 140006f00 =====

void everest_init_ccm_common(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  ev_lm_reg_write_ind(param_1,0xd0044,0x32);
  ev_lm_reg_write_ind(param_1,0xd008c,0x2150020);
  ev_lm_reg_write_ind(param_1,0xd0090,0x2150020);
  ev_lm_reg_write_ind(param_1,0xd0094,0x8100000);
  ev_lm_reg_write_ind(param_1,0xd0098,0x33);
  ev_lm_reg_write_ind(param_1,0xd00c0,1);
  ev_lm_reg_write_ind(param_1,0xd00c8,2);
  ev_lm_reg_write_ind(param_1,0xd00cc,2);
  ev_lm_reg_write_ind(param_1,0xd0108,1);
  ev_lm_reg_write_ind(param_1,0xd015c,1);
  ev_lm_reg_write_ind(param_1,0xd0164,1);
  ev_lm_reg_write_ind(param_1,0xd0168,2);
  ev_lm_reg_write_ind(param_1,0xd0204,1);
  ev_lm_reg_write_ind(param_1,0xd020c,0x20);
  ev_lm_reg_write_ind(param_1,0xd0210,0x40);
  ev_lm_reg_write_ind(param_1,0xd0214,0x40);
  uVar2 = 0xd0280;
  do {
    ev_lm_reg_write_ind(param_1,uVar2,0);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xd02c8);
  uVar3 = 0;
  uVar2 = 0xd0300;
  iVar1 = 0;
  do {
    if (uVar3 < 0x18) {
      iVar4 = ((uVar3 + 1) % 0x18) * 0x2000 + iVar1;
    }
    else {
      iVar4 = 0;
    }
    ev_lm_reg_write_ind(param_1,uVar2,iVar4);
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0xc0;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xd0390);
  ev_lm_reg_write_ind(param_1,0xd0220,3);
  ev_lm_reg_write_ind(param_1,0xd0224,0x18);
  ev_lm_reg_write_ind(param_1,0xd004c,1);
  ev_lm_reg_write_ind(param_1,0xd00c4,4);
  ev_lm_reg_write_ind(param_1,0xd0118,0x28);
  ev_lm_reg_write_ind(param_1,0xd0004,1);
  ev_lm_reg_write_ind(param_1,0xd0008,1);
  ev_lm_reg_write_ind(param_1,0xd000c,1);
  ev_lm_reg_write_ind(param_1,0xd0010,1);
  ev_lm_reg_write_ind(param_1,0xd0014,1);
  ev_lm_reg_write_ind(param_1,0xd0018,1);
  ev_lm_reg_write_ind(param_1,0xd001c,1);
  ev_lm_reg_write_ind(param_1,0xd0020,1);
  ev_lm_reg_write_ind(param_1,0xd0024,1);
  ev_lm_reg_write_ind(param_1,0xd0028,1);
  ev_lm_reg_write_ind(param_1,0xd002c,1);
  ev_lm_reg_write_ind(param_1,0xd0030,1);
  ev_lm_reg_write_ind(param_1,0xd0034,1);
  ev_lm_reg_write_ind(param_1,0xd0038,1);
  ev_lm_reg_write_ind(param_1,0xd003c,1);
  return;
}



===== everest_init_csem_common @ 14000720c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_csem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_58 [32];
  ushort local_38 [12];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = 0;
  local_38[0] = 0;
  local_38[1] = 6;
  local_38[2] = 3;
  local_38[3] = 7;
  local_38[4] = 0x32;
  local_38[5] = 8;
  iVar2 = 0x200400;
  local_38[6] = 0x33;
  local_38[7] = 9;
  local_38[8] = 0x34;
  local_38[9] = 10;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x200800);
  puVar3 = local_38;
  do {
    ev_lm_reg_write_ind(param_1,(uint)*puVar3 * 4 + 0x200400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 5);
  iVar2 = 0x202000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x204000);
  ev_lm_reg_write_ind(param_1,0x200020,1);
  ev_lm_reg_write_ind(param_1,0x200024,2);
  ev_lm_reg_write_ind(param_1,0x200028,3);
  ev_lm_reg_write_ind(param_1,0x20002c,0);
  ev_lm_reg_write_ind(param_1,0x200030,4);
  ev_lm_reg_write_ind(param_1,0x200034,0x12);
  ev_lm_reg_write_ind(param_1,0x200038,0);
  ev_lm_reg_write_ind(param_1,0x20003c,1);
  ev_lm_reg_write_ind(param_1,0x200040,4);
  ev_lm_reg_write_ind(param_1,0x200044,0);
  ev_lm_reg_write_ind(param_1,0x200048,1);
  ev_lm_reg_write_ind(param_1,0x20004c,3);
  ev_lm_reg_write_ind(param_1,0x200050,0);
  ev_lm_reg_write_ind(param_1,0x200054,1);
  ev_lm_reg_write_ind(param_1,0x200058,4);
  ev_lm_reg_write_ind(param_1,0x20005c,0);
  ev_lm_reg_write_ind(param_1,0x200060,1);
  ev_lm_reg_write_ind(param_1,0x200064,3);
  ev_lm_reg_write_ind(param_1,0x200068,0);
  ev_lm_reg_write_ind(param_1,0x20006c,1);
  ev_lm_reg_write_ind(param_1,0x200070,4);
  ev_lm_reg_write_ind(param_1,0x200074,0);
  ev_lm_reg_write_ind(param_1,0x200078,4);
  ev_lm_reg_write_ind(param_1,0x20007c,3);
  ev_lm_reg_write_ind(param_1,0x200080,0);
  ev_lm_reg_write_ind(param_1,0x200084,0);
  ev_lm_reg_write_ind(param_1,0x2000a4,0x3fff);
  ev_lm_reg_write_ind(param_1,0x2000a8,0x3ff);
  ev_lm_reg_write_ind(param_1,0x200224,0);
  ev_lm_reg_write_ind(param_1,0x200234,0);
  ev_lm_reg_write_ind(param_1,0x20024c,0);
  ev_lm_reg_write_ind(param_1,0x2002e4,0xffff);
  lm_reg_write_block(param_1,0x238bc0,(undefined4 *)&DAT_1400162a4,1);
  lm_reg_write_block(param_1,0x238000,(undefined4 *)&DAT_1400162b0,1);
  lm_reg_write_block(param_1,0x238040,(undefined4 *)&DAT_1400162b4,1);
  lm_reg_write_block(param_1,0x238080,(undefined4 *)&DAT_1400162b8,1);
  lm_reg_write_block(param_1,0x2380c0,(undefined4 *)&DAT_1400162bc,1);
  iVar2 = 0x225000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x225108);
  iVar2 = 0x221020;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x221340);
  lm_reg_write_block(param_1,0x221000,(undefined4 *)&DAT_1400162c0,2);
  return;
}



===== everest_init_nig_mac_addr @ 1400075c8 =====

void everest_init_nig_mac_addr(longlong param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  cVar2 = *(char *)(param_1 + 0x138);
  uVar4 = 0;
  iVar1 = (-(uint)(cVar2 != '\0') & 0x40) + 0x16180 + param_2 * 8;
  if (param_4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = CONCAT31(CONCAT21(CONCAT11(param_3[2],param_3[3]),param_3[4]),param_3[5]);
    uVar3 = (uint)CONCAT11(*param_3,param_3[1]);
  }
  ev_lm_reg_write_ind(param_1,iVar1,uVar4);
  ev_lm_reg_write_ind(param_1,iVar1 + 4,uVar3);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar2 != '\0') & 0x20) + 0x16140 + param_2 * 4,param_4);
  return;
}



===== everest_init_nig_mdio @ 140007694 =====

void everest_init_nig_mdio(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar1 = lm_is_e3(param_1);
  if ((int)uVar1 == 0) {
    if (*(char *)(param_1 + 0x138) == '\0') {
      ev_lm_reg_write_ind(param_1,0x10338,0);
      uVar2 = 0x1033c;
    }
    else {
      ev_lm_reg_write_ind(param_1,0x10350,0);
      uVar2 = 0x10354;
    }
    ev_lm_reg_write_ind(param_1,uVar2,3);
  }
  return;
}



===== everest_init_nig_port @ 1400076ec =====

void everest_init_nig_port(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_res8;
  undefined4 local_res10;
  
  everest_init_nig_mdio(param_1);
  uVar1 = lm_is_e3(param_1);
  if (*(char *)(param_1 + 0x138) == '\0') {
    if ((int)uVar1 == 0) {
      ev_lm_reg_write_ind(param_1,0x100e8,1);
    }
    uVar4 = 0x100f8;
    local_res10 = 0x10084;
    uVar8 = 0x10330;
    local_res8 = 0x1007c;
    uVar3 = 0x100cc;
    uVar2 = 0x10060;
    uVar7 = 0x100c4;
    uVar5 = 0x10328;
    uVar6 = 0x1008c;
  }
  else {
    if ((int)uVar1 == 0) {
      ev_lm_reg_write_ind(param_1,0x100ec,1);
    }
    uVar4 = 0x100fc;
    local_res10 = 0x10088;
    uVar8 = 0x10334;
    local_res8 = 0x10080;
    uVar3 = 0x100d0;
    uVar2 = 0x10064;
    uVar7 = 0x100c8;
    uVar5 = 0x1032c;
    uVar6 = 0x10090;
  }
  ev_lm_reg_write_ind(param_1,uVar2,0);
  ev_lm_reg_write_ind(param_1,local_res8,0);
  ev_lm_reg_write_ind(param_1,local_res10,0);
  ev_lm_reg_write_ind(param_1,uVar6,0);
  ev_lm_reg_write_ind(param_1,uVar5,0);
  ev_lm_reg_write_ind(param_1,uVar8,0x3c0001);
  ev_lm_reg_write_ind(param_1,uVar7,1);
  ev_lm_reg_write_ind(param_1,uVar3,1);
  ev_lm_reg_write_ind(param_1,uVar4,1);
  if (*(char *)(param_1 + 0x138) == '\0') {
    ev_lm_reg_write_ind(param_1,0x185b0,1);
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      return;
    }
    ev_lm_reg_write_ind(param_1,0x16024,1);
    ev_lm_reg_write_ind(param_1,0x160fc,1);
    if ((*(uint *)(param_1 + 0x58) & 0x4000) != 0) {
      ev_lm_reg_write_ind(param_1,0x16080,1);
      ev_lm_reg_write_ind(param_1,0x18038,7);
      uVar2 = 0x16100;
LAB_14000789b:
      ev_lm_reg_write_ind(param_1,uVar2,(uint)*(ushort *)(param_1 + 0x38));
      if (*(short *)(param_1 + 0xec) != 0x500) {
        return;
      }
      ev_lm_reg_write_ind(param_1,0x401a8,0x88a8);
      ev_lm_reg_write_ind(param_1,0x15c06c,0x88a8);
      uVar3 = 0x88a8;
      uVar2 = 0x16028;
      goto LAB_14000797d;
    }
    ev_lm_reg_write_ind(param_1,0x16080,2);
    uVar2 = 0x18038;
  }
  else {
    ev_lm_reg_write_ind(param_1,0x185c4,1);
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      return;
    }
    ev_lm_reg_write_ind(param_1,0x18614,1);
    ev_lm_reg_write_ind(param_1,0x16104,1);
    if ((*(uint *)(param_1 + 0x58) & 0x4000) != 0) {
      ev_lm_reg_write_ind(param_1,0x16084,1);
      ev_lm_reg_write_ind(param_1,0x1818c,7);
      uVar2 = 0x16108;
      goto LAB_14000789b;
    }
    ev_lm_reg_write_ind(param_1,0x16084,2);
    uVar2 = 0x1818c;
  }
  uVar3 = 6;
LAB_14000797d:
  ev_lm_reg_write_ind(param_1,uVar2,uVar3);
  return;
}



===== everest_init_pbf_common @ 14000799c =====

void everest_init_pbf_common(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  ev_lm_reg_write_ind(param_1,0x140000,1);
  uVar1 = lm_is_e3(param_1);
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    iVar3 = 0x140004;
    lVar4 = 3;
  }
  else {
    iVar3 = 0x15c160;
    ev_lm_reg_write_ind(param_1,0x15c1f8,3);
    ev_lm_reg_write_ind(param_1,0x140030,1);
    ev_lm_reg_write_ind(param_1,0x14003c,1);
    lVar4 = 7;
  }
  lVar6 = lVar4;
  iVar2 = iVar3;
  do {
    lVar5 = lVar6;
    ev_lm_reg_write_ind(param_1,iVar2,1);
    iVar2 = iVar2 + 4;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  ev_lm_reg_write_ind(param_1,0x140040,(int)lVar5);
  ev_lm_reg_write_ind(param_1,0x140044,0xfffff);
  ev_lm_reg_write_ind(param_1,0x14006c,0);
  ev_lm_reg_write_ind(param_1,0x140000,0);
  do {
    ev_lm_reg_write_ind(param_1,iVar3,0);
    iVar3 = iVar3 + 4;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== everest_init_pxp2_common @ 140007ac4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_pxp2_common(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  ushort local_48 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0x5130;
  local_48[1] = 0x5148;
  local_48[2] = 0x5190;
  local_48[3] = 0x51a8;
  local_48[4] = 0x51c0;
  local_48[5] = 0x51d8;
  local_48[6] = 0x51f0;
  local_48[7] = 21000;
  local_48[8] = 0x1508;
  local_48[9] = 0x1518;
  local_48[10] = 0x1848;
  local_48[0xb] = 0x1858;
  local_48[0xc] = 0x1868;
  local_48[0xd] = 0x1878;
  local_48[0xe] = 0x1888;
  local_48[0xf] = 0x1898;
  ev_lm_reg_write_ind(param_1,0x120514,0x1410);
  iVar1 = 0x12049c;
  iVar3 = 0x1204b4;
  do {
    ev_lm_reg_write_ind(param_1,iVar1,0xffffffff);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x1204b4);
  iVar1 = 0x1204d4;
  do {
    ev_lm_reg_write_ind(param_1,iVar3,0xffffffff);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1204d4);
  iVar3 = 0x1204dc;
  iVar4 = 0x1204f4;
  do {
    ev_lm_reg_write_ind(param_1,iVar3,0xffffffff);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1204f4);
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xffffffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x120514);
  lVar5 = 0;
  lVar2 = lVar5;
  do {
    ev_lm_reg_write_ind(param_1,iVar1,local_48[lVar2] | 0xffff0000);
    iVar1 = iVar1 + 4;
    lVar2 = lVar2 + 1;
  } while (lVar2 < 8);
  iVar1 = 0x120494;
  do {
    ev_lm_reg_write_ind(param_1,iVar1,local_48[lVar5 + 8] | 0xfff80000);
    iVar1 = iVar1 + 4;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 8);
  ev_lm_reg_write_ind(param_1,0x120390,8);
  ev_lm_reg_write_ind(param_1,0x12039c,8);
  ev_lm_reg_write_ind(param_1,0x1203a0,8);
  ev_lm_reg_write_ind(param_1,0x1203a4,2);
  ev_lm_reg_write_ind(param_1,0x1203bc,4);
  ev_lm_reg_write_ind(param_1,0x1203c0,5);
  ev_lm_reg_write_ind(param_1,0x1203c4,4);
  ev_lm_reg_write_ind(param_1,0x1203d0,0);
  ev_lm_reg_write_ind(param_1,0x12036c,1);
  ev_lm_reg_write_ind(param_1,0x1201b0,1);
  iVar1 = 0x122000;
  do {
    ev_lm_reg_write_ind(param_1,iVar1,0);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x124000);
  ev_lm_reg_write_ind(param_1,0x942c,1);
  return;
}



===== everest_init_qm_common @ 140007d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_qm_common(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStack_58 [32];
  undefined4 local_38 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  ev_lm_reg_write_ind(param_1,0x168040,6);
  ev_lm_reg_write_ind(param_1,0x168044,5);
  ev_lm_reg_write_ind(param_1,0x168048,6);
  ev_lm_reg_write_ind(param_1,0x16804c,5);
  iVar3 = 0x1680cc;
  do {
    ev_lm_reg_write_ind(param_1,iVar3,4);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1680ec);
  ev_lm_reg_write_ind(param_1,0x168804,4);
  ev_lm_reg_write_ind(param_1,0x168030,0x7c);
  ev_lm_reg_write_ind(param_1,0x168034,0x3d);
  ev_lm_reg_write_ind(param_1,0x168038,0x3f);
  ev_lm_reg_write_ind(param_1,0x16803c,0x9c);
  ev_lm_reg_write_ind(param_1,0x168240,0xfefffeff);
  ev_lm_reg_write_ind(param_1,0x168244,0xfefffefe);
  uVar1 = lm_is_e3(param_1);
  iVar3 = 0;
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 0x16824c;
    uVar7 = 1;
  }
  else {
    uVar2 = 0x16825c;
    uVar7 = 0x10001;
  }
  ev_lm_reg_write_ind(param_1,uVar2,uVar7);
  ev_lm_reg_write_ind(param_1,0x168268,0x1000100);
  ev_lm_reg_write_ind(param_1,0x16826c,0x1000100);
  ev_lm_reg_write_ind(param_1,0x1680f4,0);
  ev_lm_reg_write_ind(param_1,0x168134,0);
  ev_lm_reg_write_ind(param_1,0x168114,5);
  ev_lm_reg_write_ind(param_1,0x168154,5);
  ev_lm_reg_write_ind(param_1,0x168194,5);
  ev_lm_reg_write_ind(param_1,0x1681d4,5);
  uVar1 = lm_is_e3(param_1);
  uVar2 = 3;
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 1;
  }
  else {
    ev_lm_reg_write_ind(param_1,0x16e7c0,3);
  }
  ev_lm_reg_write_ind(param_1,0x168174,uVar2);
  ev_lm_reg_write_ind(param_1,0x1681b4,uVar2);
  ev_lm_reg_write_ind(param_1,0x1682a0,0);
  ev_lm_reg_write_ind(param_1,0x1682a4,1);
  ev_lm_reg_write_ind(param_1,0x1682b4,0);
  uVar1 = lm_is_e3(param_1);
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 0x17;
    uVar7 = 0xc08;
  }
  else {
    uVar2 = 0x1f;
    uVar7 = 0xc00;
  }
  ev_lm_reg_write_ind(param_1,0x1681f4,uVar7);
  ev_lm_reg_write_ind(param_1,0x168204,uVar2);
  ev_lm_reg_write_ind(param_1,0x168200,0x20);
  ev_lm_reg_write_ind(param_1,0x168060,0x140);
  ev_lm_reg_write_ind(param_1,0x168064,0x140);
  ev_lm_reg_write_ind(param_1,0x16806c,0x140);
  ev_lm_reg_write_ind(param_1,0x168074,0);
  ev_lm_reg_write_ind(param_1,0x16809c,0x40);
  ev_lm_reg_write_ind(param_1,0x1680a0,0x40);
  ev_lm_reg_write_ind(param_1,0x1680a8,0x40);
  ev_lm_reg_write_ind(param_1,0x1680b0,0);
  ev_lm_reg_write_ind(param_1,0x168238,0x8000);
  ev_lm_reg_write_ind(param_1,0x168234,0x2400);
  ev_lm_reg_write_ind(param_1,0x168220,1);
  ev_lm_reg_write_ind(param_1,0x16821c,1);
  ev_lm_reg_write_ind(param_1,0x168228,0);
  ev_lm_reg_write_ind(param_1,0x168224,0xffffffff);
  ev_lm_reg_write_ind(param_1,0x168230,0);
  ev_lm_reg_write_ind(param_1,0x16822c,0xffffffff);
  local_38[0] = 0;
  iVar5 = 2;
  local_38[1] = 2;
  local_38[2] = 1;
  local_38[3] = 3;
  ev_lm_reg_write_ind(param_1,0x16e794,0);
  ev_lm_reg_write_ind(param_1,0x16e6f0,1);
  ev_lm_reg_write_ind(param_1,0x16e6f4,1);
  ev_lm_reg_write_ind(param_1,0x16e6f8,4);
  ev_lm_reg_write_ind(param_1,0x168220,0x10001);
  ev_lm_reg_write_ind(param_1,0x16821c,0x10001);
  if ((1 < (ushort)(*(short *)(param_1 + 0xfa) + 0xe9c3U)) &&
     ((*(short *)(param_1 + 0xfc) + 0x1c0fU & 0xfffd) != 0)) {
    iVar5 = 1;
  }
  uVar6 = 0;
  do {
    iVar4 = (uint)*(byte *)(param_1 + 0x13d) * 4 + 0x120674;
    ev_lm_reg_write_ind(param_1,iVar4,uVar6 & 0xff);
    ev_lm_reg_read_ind(param_1,iVar4);
    ev_lm_reg_write_ind(param_1,0x16e70c,1);
    uVar6 = uVar6 + iVar5;
  } while ((int)uVar6 < 8);
  iVar5 = (uint)*(byte *)(param_1 + 0x13d) * 4 + 0x120674;
  ev_lm_reg_write_ind(param_1,iVar5,(uint)*(byte *)(param_1 + 0x13d));
  ev_lm_reg_read_ind(param_1,iVar5);
  iVar5 = 0x16e6bc;
  do {
    ev_lm_reg_write_ind(param_1,iVar5,local_38[iVar3]);
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0x16e6cc);
  ev_lm_reg_write_ind(param_1,0x1680ec,0xff);
  return;
}



===== everest_init_qm_port @ 140008230 =====

void everest_init_qm_port(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0x168a80;
  if (*(char *)(param_1 + 0x138) == '\0') {
    iVar3 = 0;
    iVar4 = 0x168a00;
    do {
      ev_lm_reg_write_ind(param_1,iVar4 + -0x100,iVar3);
      ev_lm_reg_write_ind(param_1,iVar4,0);
      iVar3 = iVar3 + 0x1000;
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x168a80);
    uVar2 = 0x168020;
  }
  else {
    do {
      ev_lm_reg_write_ind(param_1,iVar3 + -0x100,0x1000);
      ev_lm_reg_write_ind(param_1,iVar3,0);
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x168b00);
    uVar2 = 0x168024;
  }
  ev_lm_reg_write_ind(param_1,uVar2,0x3f);
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 != 0) {
    ev_lm_reg_write_ind(param_1,0x16e70c,1);
  }
  return;
}



===== everest_init_tcm_common @ 140008300 =====

void everest_init_tcm_common(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  
  ev_lm_reg_write_ind(param_1,0x50048,0x32);
  ev_lm_reg_write_ind(param_1,0x50090,0x2150020);
  ev_lm_reg_write_ind(param_1,0x50094,0x2150020);
  ev_lm_reg_write_ind(param_1,0x50098,0x30);
  ev_lm_reg_write_ind(param_1,0x5009c,0x8100000);
  ev_lm_reg_write_ind(param_1,0x500a0,0x33);
  ev_lm_reg_write_ind(param_1,0x500a4,0x30);
  ev_lm_reg_write_ind(param_1,0x500a8,0x31);
  ev_lm_reg_write_ind(param_1,0x500d4,1);
  ev_lm_reg_write_ind(param_1,0x50204,1);
  ev_lm_reg_write_ind(param_1,0x5020c,0x40);
  ev_lm_reg_write_ind(param_1,0x50210,0x40);
  uVar6 = 0x20;
  ev_lm_reg_write_ind(param_1,0x5021c,0x20);
  ev_lm_reg_write_ind(param_1,0x50224,0x10);
  ev_lm_reg_write_ind(param_1,0x50044,0x20);
  uVar3 = 0x50240;
  do {
    ev_lm_reg_write_ind(param_1,uVar3,0);
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x50268);
  uVar1 = lm_is_e3(param_1);
  uVar3 = 0;
  if ((int)uVar1 == 0) {
    iVar4 = (-(uint)(((*(uint *)(param_1 + 0x124) & 0xffff0000) + 0xe99e0000 & 0xfffeffff) != 0) &
            0xfffffff7) + 0x1c;
  }
  else {
    iVar4 = 0x1e;
    uVar6 = 0x1d;
  }
  iVar2 = 0;
  iVar5 = 0x50280;
  do {
    uVar3 = uVar3 + 1;
    ev_lm_reg_write_ind(param_1,iVar5,((int)((ulonglong)uVar3 % uVar6) * 0x400 + iVar2) * 0x40);
    iVar2 = iVar2 + iVar4;
    iVar5 = iVar5 + 4;
  } while (uVar3 < (uint)uVar6);
  ev_lm_reg_write_ind(param_1,0x50050,5);
  ev_lm_reg_write_ind(param_1,0x50220,iVar4);
  ev_lm_reg_write_ind(param_1,0x50004,1);
  ev_lm_reg_write_ind(param_1,0x50008,1);
  ev_lm_reg_write_ind(param_1,0x5000c,1);
  ev_lm_reg_write_ind(param_1,0x50010,1);
  ev_lm_reg_write_ind(param_1,0x50014,1);
  ev_lm_reg_write_ind(param_1,0x50018,1);
  ev_lm_reg_write_ind(param_1,0x5001c,1);
  ev_lm_reg_write_ind(param_1,0x50020,1);
  ev_lm_reg_write_ind(param_1,0x50024,1);
  ev_lm_reg_write_ind(param_1,0x50028,1);
  ev_lm_reg_write_ind(param_1,0x5002c,1);
  ev_lm_reg_write_ind(param_1,0x50030,1);
  ev_lm_reg_write_ind(param_1,0x50034,1);
  ev_lm_reg_write_ind(param_1,0x50038,1);
  ev_lm_reg_write_ind(param_1,0x5003c,1);
  ev_lm_reg_write_ind(param_1,0x50040,1);
  return;
}



===== everest_init_tsem_common @ 1400085f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_tsem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_98 [32];
  ushort local_78 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  local_78[0] = 3;
  local_78[1] = 9;
  local_78[2] = 4;
  local_78[3] = 6;
  local_78[4] = 5;
  local_78[5] = 7;
  iVar2 = 0x180400;
  local_78[6] = 6;
  local_78[7] = 8;
  local_78[8] = 7;
  local_78[9] = 0xf;
  local_78[10] = 8;
  local_78[0xb] = 0x10;
  local_78[0xc] = 9;
  local_78[0xd] = 0x11;
  local_78[0xe] = 10;
  local_78[0xf] = 0x12;
  local_78[0x10] = 0xb;
  local_78[0x11] = 0x13;
  local_78[0x12] = 0xc;
  local_78[0x13] = 0x14;
  local_78[0x14] = 0x30;
  local_78[0x15] = 10;
  local_78[0x16] = 0x31;
  local_78[0x17] = 0xb;
  local_78[0x18] = 0x32;
  local_78[0x19] = 0xc;
  local_78[0x1a] = 0x33;
  local_78[0x1b] = 0xd;
  local_78[0x1c] = 0x34;
  local_78[0x1d] = 0xe;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x180800);
  uVar1 = 0;
  puVar3 = local_78;
  do {
    ev_lm_reg_write_ind(param_1,(uint)*puVar3 * 4 + 0x180400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 0xf);
  iVar2 = 0x181000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x183000);
  ev_lm_reg_write_ind(param_1,0x180020,1);
  ev_lm_reg_write_ind(param_1,0x180024,2);
  ev_lm_reg_write_ind(param_1,0x180028,3);
  ev_lm_reg_write_ind(param_1,0x18002c,0);
  ev_lm_reg_write_ind(param_1,0x180030,4);
  ev_lm_reg_write_ind(param_1,0x180034,0x12);
  ev_lm_reg_write_ind(param_1,0x180038,0);
  ev_lm_reg_write_ind(param_1,0x18003c,1);
  ev_lm_reg_write_ind(param_1,0x180040,4);
  ev_lm_reg_write_ind(param_1,0x180044,0);
  ev_lm_reg_write_ind(param_1,0x180048,1);
  ev_lm_reg_write_ind(param_1,0x18004c,3);
  ev_lm_reg_write_ind(param_1,0x180050,0);
  ev_lm_reg_write_ind(param_1,0x180054,1);
  ev_lm_reg_write_ind(param_1,0x180058,4);
  ev_lm_reg_write_ind(param_1,0x18005c,0);
  ev_lm_reg_write_ind(param_1,0x180060,1);
  ev_lm_reg_write_ind(param_1,0x180064,3);
  ev_lm_reg_write_ind(param_1,0x180068,0);
  ev_lm_reg_write_ind(param_1,0x18006c,1);
  ev_lm_reg_write_ind(param_1,0x180070,4);
  ev_lm_reg_write_ind(param_1,0x180074,0);
  ev_lm_reg_write_ind(param_1,0x180078,4);
  ev_lm_reg_write_ind(param_1,0x18007c,3);
  ev_lm_reg_write_ind(param_1,0x180080,0);
  ev_lm_reg_write_ind(param_1,0x180084,0);
  ev_lm_reg_write_ind(param_1,0x1800a4,0x3fff);
  ev_lm_reg_write_ind(param_1,0x1800a8,0x3ff);
  ev_lm_reg_write_ind(param_1,0x180224,0);
  ev_lm_reg_write_ind(param_1,0x180234,0);
  ev_lm_reg_write_ind(param_1,0x18024c,0);
  ev_lm_reg_write_ind(param_1,0x1802e4,0xff);
  ev_lm_reg_write_ind(param_1,0x1b8bc0,1);
  ev_lm_reg_write_ind(param_1,0x1b8000,0x34);
  ev_lm_reg_write_ind(param_1,0x1b8040,0x18);
  ev_lm_reg_write_ind(param_1,0x1b8080,0xc);
  ev_lm_reg_write_ind(param_1,0x1b80c0,0x20);
  iVar2 = 0x1a2000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a22c8);
  iVar2 = 0x1a1530;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a1830);
  iVar2 = 0x1a1020;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a1340);
  ev_lm_reg_write_ind(param_1,0x1a1000,0);
  ev_lm_reg_write_ind(param_1,0x1a1004,0);
  return;
}



===== everest_init_ucm_common @ 140008a10 =====

void everest_init_ucm_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  ev_lm_reg_write_ind(param_1,0xe004c,0x32);
  ev_lm_reg_write_ind(param_1,0xe0094,0x2150020);
  ev_lm_reg_write_ind(param_1,0xe0098,0x2150020);
  ev_lm_reg_write_ind(param_1,0xe009c,0x30);
  ev_lm_reg_write_ind(param_1,0xe00a0,0x8100000);
  ev_lm_reg_write_ind(param_1,0xe00a4,0x33);
  ev_lm_reg_write_ind(param_1,0xe00a8,0x30);
  ev_lm_reg_write_ind(param_1,0xe00ac,0x31);
  ev_lm_reg_write_ind(param_1,0xe00d8,1);
  ev_lm_reg_write_ind(param_1,0xe00e4,1);
  ev_lm_reg_write_ind(param_1,0xe0144,1);
  ev_lm_reg_write_ind(param_1,0xe014c,1);
  ev_lm_reg_write_ind(param_1,0xe0150,2);
  ev_lm_reg_write_ind(param_1,0xe0204,1);
  ev_lm_reg_write_ind(param_1,0xe020c,0x40);
  ev_lm_reg_write_ind(param_1,0xe0210,0x40);
  ev_lm_reg_write_ind(param_1,0xe021c,4);
  ev_lm_reg_write_ind(param_1,0xe0220,0x20);
  uVar1 = 0xe0300;
  do {
    ev_lm_reg_write_ind(param_1,uVar1,0);
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xe0348);
  uVar3 = 0;
  uVar1 = 0xe0280;
  iVar2 = 0;
  do {
    if (uVar3 < 0x1b) {
      iVar4 = ((uVar3 + 1) % 0x1b) * 0x8000 + iVar2;
    }
    else {
      iVar4 = 0;
    }
    ev_lm_reg_write_ind(param_1,uVar1,iVar4);
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 0x380;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xe0300);
  ev_lm_reg_write_ind(param_1,0xe0224,0xc);
  ev_lm_reg_write_ind(param_1,0xe0228,0x1b);
  ev_lm_reg_write_ind(param_1,0xe0054,10);
  ev_lm_reg_write_ind(param_1,0xe0004,1);
  ev_lm_reg_write_ind(param_1,0xe0008,1);
  ev_lm_reg_write_ind(param_1,0xe000c,1);
  ev_lm_reg_write_ind(param_1,0xe0010,1);
  ev_lm_reg_write_ind(param_1,0xe0014,1);
  ev_lm_reg_write_ind(param_1,0xe0018,1);
  ev_lm_reg_write_ind(param_1,0xe001c,1);
  ev_lm_reg_write_ind(param_1,0xe0020,1);
  ev_lm_reg_write_ind(param_1,0xe0024,1);
  ev_lm_reg_write_ind(param_1,0xe0028,1);
  ev_lm_reg_write_ind(param_1,0xe002c,1);
  ev_lm_reg_write_ind(param_1,0xe0030,1);
  ev_lm_reg_write_ind(param_1,0xe0034,1);
  ev_lm_reg_write_ind(param_1,0xe0038,1);
  ev_lm_reg_write_ind(param_1,0xe003c,1);
  ev_lm_reg_write_ind(param_1,0xe0040,1);
  ev_lm_reg_write_ind(param_1,0xe0044,1);
  return;
}



===== everest_init_usem_common @ 140008d3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_usem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_78 [32];
  ushort local_58 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 3;
  local_58[1] = 6;
  local_58[2] = 4;
  local_58[3] = 7;
  local_58[4] = 5;
  local_58[5] = 8;
  iVar2 = 0x300400;
  local_58[6] = 0x10;
  local_58[7] = 0xe;
  local_58[8] = 0x30;
  local_58[9] = 9;
  local_58[10] = 0x31;
  local_58[0xb] = 10;
  local_58[0xc] = 0x32;
  local_58[0xd] = 0xb;
  local_58[0xe] = 0x33;
  local_58[0xf] = 0xc;
  local_58[0x10] = 0x34;
  local_58[0x11] = 0xd;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x300800);
  uVar1 = 0;
  puVar3 = local_58;
  do {
    ev_lm_reg_write_ind(param_1,(uint)*puVar3 * 4 + 0x300400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 9);
  iVar2 = 0x302000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x304000);
  ev_lm_reg_write_ind(param_1,0x300020,1);
  ev_lm_reg_write_ind(param_1,0x300024,2);
  ev_lm_reg_write_ind(param_1,0x300028,3);
  ev_lm_reg_write_ind(param_1,0x30002c,0);
  ev_lm_reg_write_ind(param_1,0x300030,4);
  ev_lm_reg_write_ind(param_1,0x300034,0x12);
  ev_lm_reg_write_ind(param_1,0x300038,0);
  ev_lm_reg_write_ind(param_1,0x30003c,1);
  ev_lm_reg_write_ind(param_1,0x300040,4);
  ev_lm_reg_write_ind(param_1,0x300044,0);
  ev_lm_reg_write_ind(param_1,0x300048,1);
  ev_lm_reg_write_ind(param_1,0x30004c,3);
  ev_lm_reg_write_ind(param_1,0x300050,0);
  ev_lm_reg_write_ind(param_1,0x300054,1);
  ev_lm_reg_write_ind(param_1,0x300058,4);
  ev_lm_reg_write_ind(param_1,0x30005c,0);
  ev_lm_reg_write_ind(param_1,0x300060,1);
  ev_lm_reg_write_ind(param_1,0x300064,3);
  ev_lm_reg_write_ind(param_1,0x300068,0);
  ev_lm_reg_write_ind(param_1,0x30006c,1);
  ev_lm_reg_write_ind(param_1,0x300070,4);
  ev_lm_reg_write_ind(param_1,0x300074,0);
  ev_lm_reg_write_ind(param_1,0x300078,4);
  ev_lm_reg_write_ind(param_1,0x30007c,3);
  ev_lm_reg_write_ind(param_1,0x300080,0);
  ev_lm_reg_write_ind(param_1,0x300084,0);
  ev_lm_reg_write_ind(param_1,0x3000a4,0x3fff);
  ev_lm_reg_write_ind(param_1,0x3000a8,0x3ff);
  ev_lm_reg_write_ind(param_1,0x300224,0);
  ev_lm_reg_write_ind(param_1,0x300234,0);
  ev_lm_reg_write_ind(param_1,0x30024c,0);
  ev_lm_reg_write_ind(param_1,0x3002e4,0xffff);
  lm_reg_write_block(param_1,0x338bc0,(undefined4 *)&DAT_140016290,1);
  lm_reg_write_block(param_1,0x338000,(undefined4 *)&DAT_140016294,1);
  lm_reg_write_block(param_1,0x338040,(undefined4 *)&DAT_140016298,1);
  lm_reg_write_block(param_1,0x338080,(undefined4 *)&DAT_14001629c,1);
  lm_reg_write_block(param_1,0x3380c0,(undefined4 *)&DAT_1400162a0,1);
  iVar2 = 0x325000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x325308);
  iVar2 = 0x321020;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x321340);
  lm_reg_write_block(param_1,0x321000,(undefined4 *)&DAT_1400162a8,2);
  return;
}



===== everest_init_xcm_common @ 140009120 =====

void everest_init_xcm_common(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  ev_lm_reg_write_ind(param_1,0x20058,0x32);
  ev_lm_reg_write_ind(param_1,0x200a0,0x3150020);
  ev_lm_reg_write_ind(param_1,0x200a4,0x3150020);
  ev_lm_reg_write_ind(param_1,0x200a8,0x1000030);
  ev_lm_reg_write_ind(param_1,0x200ac,0x8100000);
  ev_lm_reg_write_ind(param_1,0x200b0,0x33);
  ev_lm_reg_write_ind(param_1,0x200b4,0x30);
  ev_lm_reg_write_ind(param_1,0x200b8,0x31);
  ev_lm_reg_write_ind(param_1,0x200f0,1);
  ev_lm_reg_write_ind(param_1,0x200fc,6);
  ev_lm_reg_write_ind(param_1,0x20120,0);
  ev_lm_reg_write_ind(param_1,0x20134,2);
  ev_lm_reg_write_ind(param_1,0x201b0,1);
  ev_lm_reg_write_ind(param_1,0x2020c,1);
  ev_lm_reg_write_ind(param_1,0x20214,1);
  ev_lm_reg_write_ind(param_1,0x20218,2);
  ev_lm_reg_write_ind(param_1,0x20404,1);
  ev_lm_reg_write_ind(param_1,0x2040c,0x40);
  ev_lm_reg_write_ind(param_1,0x20410,0x40);
  ev_lm_reg_write_ind(param_1,0x2041c,4);
  ev_lm_reg_write_ind(param_1,0x20428,0x1f);
  uVar2 = 0x20500;
  do {
    ev_lm_reg_write_ind(param_1,uVar2,0);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20548);
  uVar3 = 0;
  uVar1 = 0x20480;
  uVar2 = uVar3;
  do {
    uVar3 = uVar3 + 1;
    ev_lm_reg_write_ind(param_1,uVar1,(uVar3 & 0x1f) * 0x1000 + uVar2);
    uVar2 = uVar2 + 0x80;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x20500);
  ev_lm_reg_write_ind(param_1,0x20420,2);
  ev_lm_reg_write_ind(param_1,0x20424,2);
  ev_lm_reg_write_ind(param_1,0x20060,0xf);
  ev_lm_reg_write_ind(param_1,0x200f4,4);
  ev_lm_reg_write_ind(param_1,0x20004,1);
  ev_lm_reg_write_ind(param_1,0x20008,1);
  ev_lm_reg_write_ind(param_1,0x2000c,1);
  ev_lm_reg_write_ind(param_1,0x20010,1);
  ev_lm_reg_write_ind(param_1,0x20014,1);
  ev_lm_reg_write_ind(param_1,0x20018,1);
  ev_lm_reg_write_ind(param_1,0x2001c,1);
  ev_lm_reg_write_ind(param_1,0x20020,1);
  ev_lm_reg_write_ind(param_1,0x20024,1);
  ev_lm_reg_write_ind(param_1,0x20028,1);
  ev_lm_reg_write_ind(param_1,0x2002c,1);
  ev_lm_reg_write_ind(param_1,0x20030,1);
  ev_lm_reg_write_ind(param_1,0x20034,1);
  ev_lm_reg_write_ind(param_1,0x20038,1);
  ev_lm_reg_write_ind(param_1,0x2003c,1);
  ev_lm_reg_write_ind(param_1,0x20040,1);
  ev_lm_reg_write_ind(param_1,0x20044,1);
  ev_lm_reg_write_ind(param_1,0x20048,1);
  ev_lm_reg_write_ind(param_1,0x2004c,1);
  ev_lm_reg_write_ind(param_1,0x20050,1);
  return;
}



===== everest_init_xcm_port @ 1400094a4 =====

void everest_init_xcm_port(longlong param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x138);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x20108,200);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x20118,2);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201c4,0);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201cc,1);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201d4,2);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201dc,2);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201ec,1);
  return;
}



===== everest_init_xsem_common @ 140009584 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_xsem_common(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_88 [32];
  ushort local_68 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  uVar1 = 0;
  local_68[0] = 0;
  local_68[1] = 9;
  local_68[2] = 4;
  local_68[3] = 10;
  local_68[4] = 5;
  local_68[5] = 0xb;
  iVar2 = 0x280400;
  local_68[6] = 0x10;
  local_68[7] = 6;
  local_68[8] = 0x11;
  local_68[9] = 7;
  local_68[10] = 0x12;
  local_68[0xb] = 8;
  local_68[0xc] = 0x30;
  local_68[0xd] = 0xc;
  local_68[0xe] = 0x31;
  local_68[0xf] = 0xd;
  local_68[0x10] = 0x32;
  local_68[0x11] = 0xe;
  local_68[0x12] = 0x33;
  local_68[0x13] = 0xf;
  local_68[0x14] = 0x34;
  local_68[0x15] = 0x10;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x280800);
  puVar3 = local_68;
  do {
    ev_lm_reg_write_ind(param_1,(uint)*puVar3 * 4 + 0x280400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 0xb);
  iVar2 = 0x282000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x284000);
  ev_lm_reg_write_ind(param_1,0x280020,1);
  ev_lm_reg_write_ind(param_1,0x280024,2);
  ev_lm_reg_write_ind(param_1,0x280028,3);
  ev_lm_reg_write_ind(param_1,0x28002c,0);
  ev_lm_reg_write_ind(param_1,0x280030,4);
  ev_lm_reg_write_ind(param_1,0x280034,0x12);
  ev_lm_reg_write_ind(param_1,0x280038,0);
  ev_lm_reg_write_ind(param_1,0x28003c,1);
  ev_lm_reg_write_ind(param_1,0x280040,4);
  ev_lm_reg_write_ind(param_1,0x280044,0);
  ev_lm_reg_write_ind(param_1,0x280048,1);
  ev_lm_reg_write_ind(param_1,0x28004c,3);
  ev_lm_reg_write_ind(param_1,0x280050,0);
  ev_lm_reg_write_ind(param_1,0x280054,1);
  ev_lm_reg_write_ind(param_1,0x280058,4);
  ev_lm_reg_write_ind(param_1,0x28005c,0);
  ev_lm_reg_write_ind(param_1,0x280060,1);
  ev_lm_reg_write_ind(param_1,0x280064,3);
  ev_lm_reg_write_ind(param_1,0x280068,0);
  ev_lm_reg_write_ind(param_1,0x28006c,1);
  ev_lm_reg_write_ind(param_1,0x280070,4);
  ev_lm_reg_write_ind(param_1,0x280074,0);
  ev_lm_reg_write_ind(param_1,0x280078,4);
  ev_lm_reg_write_ind(param_1,0x28007c,3);
  ev_lm_reg_write_ind(param_1,0x280080,0);
  ev_lm_reg_write_ind(param_1,0x280084,0);
  ev_lm_reg_write_ind(param_1,0x2800a4,0x3fff);
  ev_lm_reg_write_ind(param_1,0x2800a8,0x3ff);
  ev_lm_reg_write_ind(param_1,0x280224,0);
  ev_lm_reg_write_ind(param_1,0x280234,0);
  ev_lm_reg_write_ind(param_1,0x28024c,0);
  ev_lm_reg_write_ind(param_1,0x2802e4,0xffff);
  ev_lm_reg_write_ind(param_1,0x2b8bc0,1);
  ev_lm_reg_write_ind(param_1,0x2b8000,0);
  ev_lm_reg_write_ind(param_1,0x2b8040,0x18);
  ev_lm_reg_write_ind(param_1,0x2b8080,0xc);
  ev_lm_reg_write_ind(param_1,0x2b80c0,0x66);
  iVar2 = 0x2a5000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a5120);
  ev_lm_reg_write_ind(param_1,0x2a5120,0x402400);
  ev_lm_reg_write_ind(param_1,0x2a5124,0x1402400);
  iVar2 = 0x2a1020;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a1340);
  iVar2 = 0x2a1000;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a1008);
  iVar2 = 0x2a5178;
  do {
    ev_lm_reg_write_ind(param_1,iVar2,0xffffffff);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a5180);
  if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
    ev_lm_reg_write_ind(param_1,0x2a516c,1);
  }
  return;
}



===== lm_ack_enable_intr @ 1400099b8 =====

void lm_ack_enable_intr(longlong param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    uVar1 = *(ushort *)(param_1 + 0x6c);
    if ((uVar1 & 0x10) != 0) {
      lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),3,*(ushort *)(param_1 + 0x6a),0,1);
      uVar1 = *(ushort *)(param_1 + 0x6c);
    }
    if ((uVar1 & 8) != 0) {
      lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),2,*(ushort *)(param_1 + 0x68),0,1);
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x6c);
  if ((uVar1 & 2) != 0) {
    lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),0,*(ushort *)(param_1 + 0x66),0,1);
    uVar1 = *(ushort *)(param_1 + 0x6c);
  }
  if ((uVar1 & 4) != 0) {
    lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),1,*(ushort *)(param_1 + 100),0,1);
  }
  *(undefined2 *)(param_1 + 0x6c) = 0;
  return;
}



===== lm_acquire_mdio_hw_lock @ 140009a80 =====

undefined8 lm_acquire_mdio_hw_lock(longlong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x74);
  if (iVar1 == 0) {
    uVar4 = -(uint)(param_2 != 0) & 10000;
    iVar1 = (uint)*(byte *)(param_1 + 0x13a) * 8;
    do {
      ev_lm_reg_write_ind(param_1,iVar1 + 0xa514,1);
      uVar2 = ev_lm_reg_read_ind(param_1,iVar1 + 0xa510);
      if ((uVar2 & 1) != 0) {
        iVar1 = *(int *)(param_1 + 0x74);
        goto LAB_140009af0;
      }
      if (0 < (int)uVar4) {
        mm_stall(1000);
      }
      uVar4 = uVar4 - 1;
    } while (-1 < (int)uVar4);
    uVar3 = 0xffffffff;
  }
  else {
LAB_140009af0:
    *(int *)(param_1 + 0x74) = iVar1 + 1;
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_bcm8073_external_rom_boot @ 140009b0c =====

void lm_bcm8073_external_rom_boot(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  
  mm_stall(100000);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,1);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x8c);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,1);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x18a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
  mm_stall(100000);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,0);
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,uVar1 | 0x400)
  ;
  lVar2 = 1000;
  do {
    mm_stall(1000);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,uVar1 & 0xfbff
             );
  mm_stall(200000);
  return;
}



===== lm_bcm8073_load_spi_rom @ 140009cf4 =====

void lm_bcm8073_load_spi_rom(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  longlong lVar4;
  int iVar5;
  byte local_res8 [8];
  ushort local_res10 [4];
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar2 = *(ushort *)(param_1 + 300);
  local_res10[1] = *(ushort *)(param_1 + 0x12e);
  iVar5 = 0;
  if (local_res10[1] < uVar2) {
    local_res8[0] = bVar1;
    local_res10[0] = uVar2;
    local_res8[1] = bVar1 ^ 1;
  }
  else {
    local_res8[0] = bVar1 ^ 1;
    local_res10[0] = local_res10[1];
    local_res8[1] = bVar1;
    local_res10[1] = uVar2;
  }
  lVar4 = 0;
  do {
    *(byte *)(param_1 + 0x138) = local_res8[lVar4];
    *(ushort *)(param_1 + 300) = local_res10[lVar4];
    lm_reset_ext_phy(param_1);
    sVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca19);
    if (sVar3 == 0x4321) {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
      mm_stall(100);
      lm_bcm8073_external_rom_boot(param_1);
      iVar5 = iVar5 + 1;
    }
    lVar4 = lVar4 + 1;
  } while (lVar4 < 2);
  *(byte *)(param_1 + 0x138) = bVar1;
  *(ushort *)(param_1 + 300) = uVar2;
  if ((iVar5 != 0) && (*(short *)(param_1 + 0x130) == 0x900)) {
    mm_stall(1000000);
  }
  return;
}



===== lm_bcm8726_set_limiting_mode @ 140009e34 =====

void lm_bcm8726_set_limiting_mode(longlong param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar2 = lm_phy_872x_read_sfp_module_eeprom(param_1,0x40);
  uVar4 = *(ushort *)(param_1 + 300);
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xca1a;
    uVar1 = 0x44;
  }
  else {
    uVar3 = 0xca3f;
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),uVar4,1,0xca3f,0);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a,0x123);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca23,0x4008);
    uVar4 = *(ushort *)(param_1 + 300);
    uVar1 = 0xaaaa;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),uVar4,1,uVar3,uVar1);
  return;
}



===== lm_bcm8727_set_edc_mode @ 140009f20 =====

void lm_bcm8727_set_edc_mode(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ushort uVar5;
  
  uVar5 = 0x44;
  uVar3 = lm_phy_872x_read_sfp_module_eeprom(param_1,2);
  if ((char)uVar3 != '\a') {
    if ((char)uVar3 != '!') goto LAB_140009f80;
    uVar4 = lm_phy_872x_read_sfp_module_eeprom(param_1,8);
    if ((uVar4 & 4) != 0) {
      uVar5 = 0x55;
      goto LAB_140009f80;
    }
  }
  uVar4 = lm_phy_872x_read_sfp_module_eeprom(param_1,0x40);
  if ((uVar4 & 1) != 0) {
    uVar5 = 0x22;
  }
LAB_140009f80:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,uVar1 & 0xfdff
             );
  uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a,
              uVar2 & 0xff00 | uVar5);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,
              uVar1 & 0xfdff | 0x200);
  mm_stall(2000000);
  return;
}



===== lm_chip_init @ 14000a078 =====

undefined8 lm_chip_init(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined8 local_res8;
  
  bVar1 = param_1[0x13b];
  lm_retrieve_phy_info((longlong)param_1);
  uVar3 = lm_issue_fw_command((longlong)param_1,0x10000000);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x4c) + (uint)bVar1 * 0x2c + 0x694,0x8000);
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x50) + 0x74,0x9001);
  }
  lm_init_fw_offsets((longlong)param_1);
  uVar4 = *(uint *)(param_1 + 0x58);
  if (((uVar4 >> 0x11 & 1) == 0) || (uVar3 != 0x10120000)) {
    uVar4 = uVar4 | 0x10000;
  }
  else {
    uVar4 = uVar4 & 0xfffeffff;
  }
  *(uint *)(param_1 + 0x58) = uVar4 | 0x10;
  uVar5 = lm_init_common_part((longlong)param_1);
  if ((int)uVar5 == 1) {
    lm_shutdown(param_1);
  }
  else {
    lm_init_function_part((longlong)param_1);
    lm_init_status_blocks((longlong)param_1);
    param_1[0x6d8] = 0;
    param_1[0x6e8] = 0;
    param_1[0x6e9] = 0;
    mm_alloc_sp_ring((longlong)param_1);
    ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_1 + 0x6f0));
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xbc) + 4,*(undefined4 *)(param_1 + 0x6f4));
    if (*(short *)(param_1 + 0x38) == 0) {
      local_res8 = 0x5fc01b80000;
    }
    else {
      local_res8 = 0x5fc01b80001;
    }
    ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 200),(undefined4)local_res8);
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 200) + 4,local_res8._4_4_);
    ev_lm_reg_write_ind(param_1,0x325308,*(undefined4 *)(param_1 + 0x90));
    ev_lm_reg_write_ind(param_1,0x32530c,*(undefined4 *)(param_1 + 0x94));
    ev_lm_post_buffers((longlong)param_1);
    bVar2 = lm_sp_post_and_wait((longlong)param_1,0x50,0,0,0);
    if (((int)CONCAT71(extraout_var,bVar2) != 1) &&
       (uVar3 = lm_issue_fw_command((longlong)param_1,0x11000000), uVar3 == 0x11100000)) {
      lm_set_mac_addrs((longlong)param_1);
      bVar1 = param_1[0x138];
      uVar4 = -(uint)(bVar1 != 0) & 4;
      uVar3 = ev_lm_reg_read_ind(param_1,uVar4 + 0x16050);
      ev_lm_reg_write_ind(param_1,uVar4 + 0x16050,uVar3 | 4);
      ev_lm_reg_write_ind(param_1,(-(uint)(bVar1 != 0) & 4) + 0x10244,0x1f);
      ev_lm_reg_write_ind(param_1,(-(uint)(bVar1 != 0) & 0x80) + 0x1025c,1);
      ev_lm_reg_write_ind(param_1,0xa45c,0xffffffff);
      return 0;
    }
  }
  return 1;
}



===== lm_chip_reset_all_blocks @ 14000a2cc =====

void lm_chip_reset_all_blocks(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = ev_lm_reg_read_ind(param_1,0x10394);
  uVar2 = ev_lm_reg_read_ind(param_1,0x10398);
  uVar4 = *(uint *)(param_1 + 0x58) & 0xc;
  if (uVar4 == 0) {
    lm_shutdown_mgmt_to_mcp(param_1);
  }
  ev_lm_reg_write_ind(param_1,0xa588,(-(uint)(uVar4 != 0) & 0xffffff80) + 0xd3ffffff);
  ev_lm_reg_write_ind(param_1,0xa598,0x1403);
  mm_stall(100);
  ev_lm_reg_write_ind(param_1,0xa584,0xffffffff);
  ev_lm_reg_write_ind(param_1,0xa594,0xfffc);
  iVar3 = 0x1025c;
  iVar5 = 0x10244;
  do {
    ev_lm_reg_write_ind(param_1,iVar5,0);
    ev_lm_reg_write_ind(param_1,iVar3,0);
    iVar5 = iVar5 + 4;
    iVar3 = iVar3 + 0x80;
  } while (iVar5 < 0x1024c);
  if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
    ev_lm_reg_write_ind(param_1,0xa584,0x80);
  }
  ev_lm_reg_write_ind(param_1,0x10394,uVar1);
  ev_lm_reg_write_ind(param_1,0x10398,uVar2);
  return;
}



===== lm_ctrl_epio @ 14000a3f8 =====

void lm_ctrl_epio(undefined8 param_1,byte param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_2 & 0x1f);
  uVar1 = ev_lm_reg_read_ind(param_1,0x800c4);
  if (param_3 == 0) {
    uVar1 = uVar1 & ~uVar2;
  }
  else {
    uVar1 = uVar1 | uVar2;
  }
  ev_lm_reg_write_ind(param_1,0x800c4,uVar1);
  uVar1 = ev_lm_reg_read_ind(param_1,0x800c8);
  ev_lm_reg_write_ind(param_1,0x800c8,uVar1 | uVar2);
  return;
}



===== lm_ctrl_pin_cfg @ 14000a470 =====

void lm_ctrl_pin_cfg(undefined8 param_1,ushort param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  
  if (param_2 != 0) {
    cVar2 = (char)param_2;
    if (8 < param_2) {
      lm_ctrl_epio(param_1,cVar2 - 9,param_3);
      return;
    }
    bVar1 = 3 < (ushort)(param_2 - 1);
    if (bVar1) {
      cVar2 = cVar2 + -5;
    }
    else {
      cVar2 = cVar2 + -1;
    }
    lm_gpio_write(param_1,bVar1,cVar2,(char)param_3);
  }
  return;
}



===== lm_dcbx_init @ 14000a4bc =====

undefined8 lm_dcbx_init(longlong param_1)

{
  uint uVar1;
  ushort uVar2;
  
  if (((*(uint *)(param_1 + 0x58) & 8) != 0) && (uVar2 = 0, *(int *)(param_1 + 0x50) != 0)) {
    lm_phy_toggle_link(param_1);
    uVar1 = lm_issue_fw_command(param_1,0xb0000000);
    if (uVar1 == 0x40100000) {
      do {
        lm_get_dcbx_info(param_1);
        if ((*(byte *)(param_1 + 0xac) & 1) != 0) break;
        mm_stall(1000);
        uVar2 = uVar2 + 1;
      } while (uVar2 < 40000);
      uVar1 = lm_issue_fw_command(param_1,0xb2000000);
      if (uVar1 == 0x40100000) {
        if ((*(byte *)(param_1 + 0xac) & 1) == 0) {
          *(undefined1 *)(param_1 + 0xad) = 3;
        }
        return 0;
      }
    }
  }
  return 1;
}



===== lm_disable_mac @ 14000a56c =====

void lm_disable_mac(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x138);
    ev_lm_reg_write_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 4 + 0x100ac,0);
    ev_lm_reg_write_ind(param_1,uVar1 * 4 + 0x100e0,0);
    ev_lm_reg_write_ind(param_1,uVar1 * 4 + 0x1003c,0);
    ev_lm_reg_write_ind(param_1,uVar1 * 4 + 0x100a4,0);
    ev_lm_reg_write_ind(param_1,uVar1 * 4 + 0x10120,0);
  }
  lm_set_xumac_nig(param_1,0,0);
  return;
}



===== lm_e3_imc_done @ 14000a5fc =====

bool lm_e3_imc_done(undefined8 param_1,ulonglong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = (uint)((param_2 & 0xffffffff) / 10);
  if (uVar3 != 0) {
    do {
      uVar1 = ev_lm_reg_read_ind(param_1,0x85900);
      if ((uVar1 & 0x30000) == 0x10000) break;
      mm_stall(10);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return uVar2 < uVar3;
}



===== lm_enable_bmac @ 14000a660 =====

void lm_enable_bmac(longlong param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  bVar2 = *(byte *)(param_1 + 0x138);
  uVar3 = lm_is_dual_core(param_1);
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar6 = (uint)bVar2;
    ev_lm_reg_write_ind(param_1,0xa594,1 << (bVar2 & 0x1f));
    uVar4 = lm_is_e3(param_1);
    if ((int)uVar4 == 0) {
      ev_lm_reg_write_ind(param_1,(uint)bVar2 * 4 + 0x100e8,1);
      uVar7 = -(uint)(bVar2 != 0) & 0x400;
      iVar5 = uVar7 + 0x10c00;
      ev_lm_reg_write_ind(param_1,iVar5,0);
      iVar1 = uVar7 + 0x10c04;
      ev_lm_reg_write_ind(param_1,iVar1,0);
      ev_lm_reg_write_ind(param_1,uVar7 + 0x10c08,0x3c);
      ev_lm_reg_write_ind(param_1,uVar7 + 0x10c0c,0);
      if ((int)uVar3 == 0) {
        uVar8 = 0x8000c0;
        if (*(int *)(param_1 + 0x10) != 2) {
          uVar8 = 0xc0;
        }
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10c38,uVar8);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10c3c,0);
        ev_lm_reg_write_ind(param_1,iVar5,(-(uint)(param_2 != 0) & 4) + 3);
        ev_lm_reg_write_ind(param_1,iVar1,0);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10d18,0x600);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10d1c,0);
        uVar8 = 0x34;
        if (*(int *)(param_1 + 0x10) != 1) {
          uVar8 = 0x14;
        }
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10d08,uVar8);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10d0c,0);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10c48,0x600);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10c4c,0);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10c28,0x600);
        iVar5 = uVar7 + 0x10c2c;
      }
      else {
        uVar8 = 0x8000c0;
        if (*(int *)(param_1 + 0x10) != 2) {
          uVar8 = 0xc0;
        }
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10ce0,uVar8);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10ce4,0);
        ev_lm_reg_write_ind(param_1,iVar5,(-(uint)(param_2 != 0) & 4) + 3);
        ev_lm_reg_write_ind(param_1,iVar1,0);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10de0,0x600);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10de4,0);
        ev_lm_reg_write_ind(param_1,uVar7 + 0x10cf0,0x600);
        iVar5 = uVar7 + 0x10cf4;
      }
      ev_lm_reg_write_ind(param_1,iVar5,0);
    }
    ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x10058,0);
    uVar3 = lm_is_e3(param_1);
    if ((int)uVar3 == 0) {
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x102e8,0);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x102e0,1);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x10120,0);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x10110,1);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x100a4,0);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x100ac,1);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x100e0,1);
      ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x10118,0);
    }
    ev_lm_reg_write_ind(param_1,uVar6 * 4 + 0x100f0,0);
  }
  else {
    lm_enable_xmac(param_1,param_2);
  }
  return;
}



===== lm_enable_emac @ 14000a9b4 =====

void lm_enable_emac(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 != 0) {
    iVar3 = 0x100000 << (bVar1 & 0x1f);
    ev_lm_reg_write_ind(param_1,0xa598,iVar3);
    mm_stall(1000);
    ev_lm_reg_write_ind(param_1,0xa594,iVar3);
    lm_reg_bits_en(param_1,0xa000,0x590,0x1000000 << (bVar1 & 0x1f));
  }
  lm_reg_bits_en(param_1,0xa000,0x590,0x4000 << (bVar1 & 0x1f));
  mm_stall(1000);
  ev_lm_reg_write_ind(param_1,(-(uint)(bVar1 != 0) & 0x400) + 0x80c8,0x500);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x102e8,0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x102e0,1);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x1003c,1);
  }
  ev_lm_reg_write_ind(param_1,(-(uint)(bVar1 != 0) & 0x400) + 0x809c,0x600);
  ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10058,1);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10044,1);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x100ac,0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x100e0,0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10110,0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x100a4,1);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10118,1);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10120,1);
  }
  lm_set_xumac_nig(param_1,1,1);
  return;
}



===== lm_enable_xmac @ 14000ab90 =====

void lm_enable_xmac(longlong param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar5 = -(uint)(bVar1 != 0) & 0x800;
  uVar6 = -(uint)(bVar1 != 0) & 0xfffff800;
  uVar2 = ev_lm_reg_read_ind(param_1,uVar6 + 0x163800);
  if ((uVar2 & 0x40) == 0) {
    iVar3 = ev_lm_reg_read_ind(param_1,uVar6 + 0x163840);
    iVar4 = ev_lm_reg_read_ind(param_1,uVar6 + 0x163820);
  }
  else {
    iVar3 = param_2;
    iVar4 = param_2;
  }
  ev_lm_reg_write_ind(param_1,0xa594,0x1000000 << (*(byte *)(param_1 + 0x138) & 0x1f));
  ev_lm_reg_write_ind(param_1,0xa598,0x400000);
  mm_stall(1000);
  ev_lm_reg_write_ind(param_1,0xa594,0x400000);
  if (*(char *)(param_1 + 0x158) == '\0') {
    ev_lm_reg_write_ind(param_1,0xa964,1);
    uVar7 = 3;
  }
  else {
    ev_lm_reg_write_ind(param_1,0xa964,0);
    uVar7 = 3;
    if ((*(uint *)(param_1 + 0xc) & 0xff00) == 0x700) {
      uVar7 = 1;
    }
  }
  ev_lm_reg_write_ind(param_1,0xa960,uVar7);
  ev_lm_reg_write_ind(param_1,0xa598,0x800000);
  mm_stall(1000);
  ev_lm_reg_write_ind(param_1,0xa594,0x800000);
  if ((uVar2 & 0x40) == 0) {
    ev_lm_reg_write_ind(param_1,uVar6 + 0x163840,iVar3);
    ev_lm_reg_write_ind(param_1,uVar6 + 0x163820,iVar4);
    ev_lm_reg_write_ind(param_1,uVar6 + 0x163800,uVar2);
  }
  ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10058,0);
  ev_lm_reg_write_ind(param_1,uVar5 + 0x163040,0x600);
  ev_lm_reg_write_ind(param_1,uVar5 + 0x163020,0xc800);
  uVar6 = (-(uint)(param_2 != 0) & 4) + 3;
  uVar2 = uVar6 | 0x80;
  if ((*(uint *)(param_1 + 0xc) & 0xff00) != 0x700) {
    uVar2 = uVar6;
  }
  ev_lm_reg_write_ind(param_1,uVar5 + 0x163000,uVar2);
  lm_set_xumac_nig(param_1,1,1);
  return;
}



===== lm_extract_vntag_info @ 14000ada8 =====

void lm_extract_vntag_info(longlong param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    bVar1 = *(byte *)(param_1 + 0x13c);
    *(undefined2 *)(param_1 + 0x38) = 0;
    bVar2 = false;
    iVar5 = 0;
    do {
      uVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + (bVar1 + 2) * 0x18);
      *(short *)(param_1 + 0x3c) = (short)uVar3;
      uVar4 = ev_lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 0x2c +
                                         *(int *)(param_1 + 0x4c) + 0x6a4);
      if ((uVar4 >> 0x17 & 1) != 0) {
        lm_issue_fw_command(param_1,0xd4000000);
        bVar2 = true;
      }
      if ((uVar4 >> 0x15 & 1) != 0) {
        lm_issue_fw_command(param_1,0xd2000000);
      }
      if (((10000 < iVar5) && (*(short *)(param_1 + 0x3c) != -1)) && (bVar2)) break;
      mm_stall(1000);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 20000);
    *(short *)(param_1 + 0x3e) = (short)(uVar3 >> 0x10);
    if (*(int *)(param_1 + 0x34) == 0) {
      *(uint *)(param_1 + 0x34) = uVar3 >> 0x10;
    }
  }
  return;
}



===== lm_flush_rx_buffers @ 14000aeb8 =====

uint lm_flush_rx_buffers(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar4;
  uint uVar3;
  uint uVar5;
  
  uVar5 = 0;
  uVar1 = ev_lm_get_interrupt_status(param_1);
  if ((((uVar1 & 2) != 0) && (*(short **)(param_1 + 0x6b0) != (short *)0x0)) &&
     (**(short **)(param_1 + 0x6b0) != *(short *)(param_1 + 0x69a))) {
    do {
      ev_lm_service_rx_intr(param_1);
      iVar2 = *(int *)(param_1 + 0x5f0);
      if (iVar2 == *(int *)(param_1 + 0x5f4)) break;
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x5f8);
      }
      *(uint *)(param_1 + 0x5f0) = iVar2 - 1U;
      *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
      iVar4 = *(int *)(param_1 + 0x4d4);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x4d8);
      }
      uVar3 = iVar4 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x4d0)) {
        *(undefined8 *)(param_1 + 0x4e0 + (ulonglong)uVar3 * 8) =
             *(undefined8 *)(param_1 + 0x600 + (ulonglong)(iVar2 - 1U) * 8);
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar3;
      }
      ev_lm_post_buffers(param_1);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x1e);
  }
  return uVar5 & 0xffff;
}



===== lm_get_basic_hw_info @ 14000af70 =====

bool lm_get_basic_hw_info(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  int iVar12;
  char cVar13;
  
  uVar3 = storport_pci_cfg_read_dword(param_1,0);
  *(short *)(param_1 + 0xf8) = (short)uVar3;
  *(short *)(param_1 + 0xfa) = (short)((uint)uVar3 >> 0x10);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x2c);
  *(short *)(param_1 + 0xfe) = (short)uVar3;
  *(short *)(param_1 + 0xfc) = (short)((uint)uVar3 >> 0x10);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x3c);
  *(char *)(param_1 + 0x100) = (char)uVar3;
  *(char *)(param_1 + 0x101) = (char)((uint)uVar3 >> 8);
  uVar3 = storport_pci_cfg_read_dword(param_1,0xc);
  *(char *)(param_1 + 0x102) = (char)uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,8);
  *(char *)(param_1 + 0x103) = (char)uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,0x10);
  *(undefined4 *)(param_1 + 0x108) = uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,0x14);
  *(undefined4 *)(param_1 + 0x10c) = uVar3;
  iVar4 = ev_lm_reg_read_ind(param_1,0xa408);
  uVar5 = ev_lm_reg_read_ind(param_1,0xa40c);
  uVar6 = ev_lm_reg_read_ind(param_1,0xa404);
  ev_lm_reg_read_ind(param_1,0xa400);
  *(uint *)(param_1 + 0x124) =
       (uVar6 & 0xff) << 4 | uVar6 & 0xf | iVar4 << 0x10 | (uVar5 & 0xf) << 0xc;
  uVar5 = storport_pci_cfg_read_dword(param_1,4);
  storport_pci_cfg_write_dword(param_1,4,uVar5 | 4);
  iVar4 = storport_pci_cfg_read_dword(param_1,0x98);
  if (iVar4 == -1) {
    iVar4 = 1;
  }
  uVar7 = lm_is_dual_core(param_1);
  iVar8 = 0;
  bVar9 = (byte)((uint)iVar4 >> 0x10);
  if ((int)uVar7 == 0) {
    bVar10 = (byte)iVar4;
  }
  else {
    bVar10 = bVar9;
  }
  *(byte *)(param_1 + 0x13d) = bVar10 & 7;
  bVar9 = bVar9 & 1;
  bVar10 = (byte)iVar4 & 1;
  *(byte *)(param_1 + 0x139) = bVar9;
  *(byte *)(param_1 + 0x138) = bVar10;
  *(undefined1 *)(param_1 + 0x158) = 2;
  cVar13 = '\x02';
  uVar7 = lm_is_dual_core(param_1);
  if ((int)uVar7 != 0) {
    uVar5 = ev_lm_reg_read_ind(param_1,0xa720);
    if ((uVar5 & 1) == 0) {
      uVar5 = ev_lm_reg_read_ind(param_1,0xa750);
    }
    else {
      uVar5 = uVar5 >> 1 & 1;
    }
    bVar9 = *(byte *)(param_1 + 0x139);
    cVar13 = uVar5 == 0;
    bVar10 = *(byte *)(param_1 + 0x138);
    *(char *)(param_1 + 0x158) = cVar13;
  }
  if (cVar13 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x13d) >> 1;
    *(byte *)(param_1 + 0x13e) = bVar1;
    bVar10 = bVar10 * '\x02';
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x13d) & 6;
    *(byte *)(param_1 + 0x13e) = bVar1;
    bVar1 = bVar1 >> 1;
  }
  *(byte *)(param_1 + 0x13a) = bVar9 | bVar10;
  *(byte *)(param_1 + 0x13b) = bVar1;
  uVar3 = ev_lm_reg_read_ind(param_1,0xa2b4);
  *(undefined4 *)(param_1 + 0x4c) = uVar3;
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) != 0x164e0000) {
    uVar3 = 0xa460;
    if (*(char *)(param_1 + 0x139) != '\0') {
      uVar3 = 0xa464;
    }
    uVar3 = ev_lm_reg_read_ind(param_1,uVar3);
    *(undefined4 *)(param_1 + 0x50) = uVar3;
  }
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x4c) + 0x7e4;
  if (((*(int *)(param_1 + 0x50) != 0) &&
      (uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50)), 0xb < uVar5)) &&
     (iVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) + 0x10), iVar4 != 0)) {
    *(int *)(param_1 + 0x54) = iVar4;
  }
  bVar9 = *(byte *)(param_1 + 0x13d);
  *(byte *)(param_1 + 0x13c) = bVar9;
  uVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
  *(ushort *)(param_1 + 0xec) = uVar2 & 0x700;
  if (((uVar2 & 0x700) - 0x500 & 0xfdff) == 0) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20000;
  }
  uVar7 = lm_is_mf_device(param_1);
  if (((int)uVar7 != 0) &&
     ((uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x368 +
                                          (*(byte *)(param_1 + 0x13d) >> 1 & 1) * 0x74),
      *(short *)(param_1 + 0xec) != 0x600 || ((uVar5 & 0x700000) != 0x100000)))) {
    iVar12 = (bVar9 + 2) * 0x18;
    iVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + iVar12);
    sVar11 = (short)iVar4;
    if ((*(short *)(param_1 + 0xec) == 0x500) && ((sVar11 == -1 || (iVar4 == 0)))) {
      do {
        iVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + iVar12);
        sVar11 = (short)iVar4;
        if ((sVar11 != -1) && (iVar4 != 0)) break;
        mm_stall(1000000);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x3c);
    }
    if (sVar11 != -1) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x24000;
      *(short *)(param_1 + 0x38) = sVar11;
    }
  }
  uVar5 = *(uint *)(param_1 + 0x58);
  if ((uVar5 >> 0x11 & 1) != 0) {
    if (1 < (*(byte *)(param_1 + 0x16c) & 7)) {
      uVar5 = uVar5 | 0x400;
      *(uint *)(param_1 + 0x58) = uVar5;
      *(byte *)(param_1 + 0x13c) = *(byte *)(param_1 + 0x16c) & 7;
    }
    if (1 < *(byte *)(param_1 + 0x13d)) {
      *(uint *)(param_1 + 0x58) = uVar5 | 0x8000;
    }
  }
  return *(int *)(param_1 + 0x4c) == 0;
}



===== lm_get_dcbx_info @ 14000b334 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 lm_get_dcbx_info(longlong param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  byte bVar5;
  byte *pbVar6;
  ushort uVar7;
  longlong lVar8;
  undefined4 *puVar9;
  undefined1 auStack_b8 [32];
  undefined4 local_98 [8];
  byte local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  iVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) + 0x2c);
  if (iVar2 == 0) {
    uVar4 = 1;
  }
  else {
    bVar5 = *(byte *)(param_1 + 0x138);
    puVar9 = local_98;
    uVar7 = 0;
    do {
      uVar3 = ev_lm_reg_read_ind(param_1,(uint)uVar7 + iVar2 + (uint)bVar5 * 100);
      *puVar9 = uVar3;
      uVar7 = uVar7 + 4;
      puVar9 = puVar9 + 1;
    } while (uVar7 < 100);
    pbVar6 = local_78 + 2;
    lVar8 = 0x10;
    do {
      if ((pbVar6[-2] & 1) != 0) {
        sVar1 = CONCAT11(*pbVar6,pbVar6[1]);
        if (sVar1 == 0x689) {
LAB_14000b41d:
          bVar5 = 0;
          do {
            if ((pbVar6[-1] >> (bVar5 & 0x1f) & 1) != 0) goto LAB_14000b438;
            bVar5 = bVar5 + 1;
          } while (bVar5 < 8);
          bVar5 = 0;
LAB_14000b438:
          *(byte *)(param_1 + 0xac) = *(byte *)(param_1 + 0xac) | 1;
          *(byte *)(param_1 + 0xad) = bVar5;
        }
        else {
          if (sVar1 != 0xcbc) {
            if (sVar1 == -0x76fa) goto LAB_14000b41d;
            if (sVar1 != -0x43f4) goto LAB_14000b445;
          }
          bVar5 = 0;
          do {
            if ((pbVar6[-1] >> (bVar5 & 0x1f) & 1) != 0) goto LAB_14000b40e;
            bVar5 = bVar5 + 1;
          } while (bVar5 < 8);
          bVar5 = 0;
LAB_14000b40e:
          *(byte *)(param_1 + 0xac) = *(byte *)(param_1 + 0xac) | 2;
          *(byte *)(param_1 + 0xae) = bVar5;
        }
      }
LAB_14000b445:
      pbVar6 = pbVar6 + 4;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    uVar4 = 0;
  }
  return uVar4;
}



===== lm_get_emac_base @ 14000b484 =====

int lm_get_emac_base(longlong param_1,short param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0x300) {
    uVar1 = lm_is_dual_core(param_1);
    if ((int)uVar1 == 0) {
      return (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 0xfffffc00) + 0x8400;
    }
  }
  else {
    if ((param_2 != 0x600) && (param_2 != 0x900)) {
      return (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x400) + 0x8000;
    }
    uVar1 = lm_is_dual_core(param_1);
    if ((int)uVar1 == 0) {
      return ((byte)~*(byte *)(param_1 + 0x14e) & 1 | 0x20) << 10;
    }
  }
  return 0x8000;
}



===== lm_get_link_speed @ 14000b50c =====

undefined4 lm_get_link_speed(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    uVar4 = lm_phy_get_gp_status(param_1);
    uVar4 = uVar4 & 0x3f00;
    if ((uVar4 == 0x200) || (uVar4 == 0xd00)) {
      return 0x300;
    }
    uVar3 = 0x700;
    if (uVar4 != 0x3900) {
      uVar3 = 0x600;
    }
    return uVar3;
  }
  if (sVar1 == 0x300) {
LAB_14000b679:
    uVar2 = lm_mread45(param_1,sVar1,*(ushort *)(param_1 + 300),1,0xc820);
    if ((uVar2 & 0x8004) == 4) {
      return 0x600;
    }
    if ((uVar2 & 0x4002) == 2) {
      return 0x400;
    }
    if ((uVar2 & 0x2001) == 1) {
      return 0x300;
    }
    return 0;
  }
  if (sVar1 == 0x700) {
    uVar2 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),1,0xa811);
    if ((uVar2 & 0x800) != 0) {
      return 0x600;
    }
    lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfff9);
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfff9);
    uVar4 = uVar2 & 0x700;
    if ((uVar4 - 0x100 & 0xfffffeff) != 0) {
      if ((uVar4 - 0x300 & 0xfffffdff) != 0) {
        if ((uVar4 - 0x600 & 0xfffffeff) == 0) {
          return 0x300;
        }
        return 0;
      }
LAB_14000b5a9:
      uVar5 = 0x200;
      uVar3 = 0x10200;
      bVar6 = uVar4 == 0x300;
      goto LAB_14000b671;
    }
  }
  else {
    if (sVar1 == 0x900) goto LAB_14000b679;
    if (sVar1 != 0xe00) {
      return 0x600;
    }
    uVar2 = lm_mread22_ext(param_1,0x19);
    uVar4 = uVar2 & 0x700;
    if ((uVar4 - 0x100 & 0xfffffeff) != 0) {
      if ((uVar4 - 0x300 & 0xfffffdff) != 0) {
        return 0x300;
      }
      goto LAB_14000b5a9;
    }
  }
  uVar5 = 0x100;
  uVar3 = 0x10100;
  bVar6 = uVar4 == 0x100;
LAB_14000b671:
  if (bVar6) {
    return uVar3;
  }
  return uVar5;
}



===== lm_get_mac_addresses @ 14000b728 =====

void lm_get_mac_addresses(longlong param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  int iVar9;
  int iVar10;
  
  bVar1 = *(byte *)(param_1 + 0x13c);
  uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x44 +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x48 +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    iVar9 = (uint)bVar1 * 0x18;
    uVar6 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + iVar9);
    if (((uVar6 & 6) - 2 & 0xfffffffd) == 0) {
      uVar7 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + iVar9);
      if ((short)uVar7 != -1) {
        uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x2c + iVar9);
        uVar4 = uVar7;
      }
    }
  }
  param_2[1] = uVar4;
  *param_2 = uVar5;
  iVar9 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x4c +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar4 = ev_lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 +
                                     *(int *)(param_1 + 0x4c) + 0x50);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var_00,bVar2) == 0) goto LAB_14000b8cc;
  if ((*(short *)(param_1 + 0xec) - 0x300U & 0xfbff) == 0) {
    iVar10 = (uint)bVar1 * 0x28;
    iVar8 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xe8 + iVar10);
    if ((iVar8 == 0) || (iVar8 == 0xffff)) goto LAB_14000b8cc;
    iVar9 = *(int *)(param_1 + 0x54) + 0xec;
  }
  else {
    iVar10 = (uint)bVar1 * 0x18;
    bVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + iVar10);
    if ((bVar3 & 6) != 6) goto LAB_14000b8cc;
    iVar8 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + iVar10);
    if ((short)iVar8 == -1) goto LAB_14000b8cc;
    iVar9 = *(int *)(param_1 + 0x54) + 0x2c;
  }
  uVar4 = ev_lm_reg_read_ind(param_1,iVar9 + iVar10);
  iVar9 = iVar8;
LAB_14000b8cc:
  param_2[3] = iVar9;
  param_2[2] = uVar4;
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var_01,bVar2) == 0) {
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb0 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[5] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb4 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[4] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb8 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[7] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xbc +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[6] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xc0 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[9] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xc4 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[8] = uVar4;
  }
  else {
    iVar9 = (uint)bVar1 * 0x28;
    if (*(short *)(param_1 + 0xec) == 0x500) {
      uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + (uint)bVar1 * 0x18);
      param_2[5] = uVar4;
      iVar8 = *(int *)(param_1 + 0x54) + 0x2c + (uint)bVar1 * 0x18;
    }
    else {
      uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xf0 + iVar9);
      param_2[5] = uVar4;
      iVar8 = *(int *)(param_1 + 0x54) + 0xf4 + iVar9;
    }
    uVar4 = ev_lm_reg_read_ind(param_1,iVar8);
    param_2[4] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x100 + iVar9);
    param_2[9] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x104 + iVar9);
    param_2[8] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xf8 + iVar9);
    param_2[7] = uVar4;
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xfc + iVar9);
    param_2[6] = uVar4;
  }
  return;
}



===== lm_get_phy_info @ 14000ba8c =====

void lm_get_phy_info(longlong param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined8 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  iVar7 = (-(uint)(param_2 != 0) & 0xffffffe8) + 0x1b4;
  uVar2 = ev_lm_reg_read_ind(param_1,(uint)bVar1 * 400 + *(int *)(param_1 + 0x4c) + iVar7);
  uVar6 = *(ushort *)(param_1 + 0x14e);
  uVar4 = uVar2 & 0xff00;
  *(ushort *)(param_1 + 300) = uVar2 & 0xff;
  *(ushort *)(param_1 + 0x130) = uVar4;
  uVar5 = uVar6 | 0x100;
  *(ushort *)(param_1 + 0x14e) = uVar5;
  if (uVar4 == 0xa00) {
    uVar5 = uVar6 | 0x102;
    *(undefined2 *)(param_1 + 0x130) = 0x900;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x900;
  }
  if (uVar4 == 0xb00) {
    uVar5 = uVar5 | 8;
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x700;
  }
  if (uVar4 == 0xd00) {
    uVar5 = uVar5 | 0x10;
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x700;
  }
  if (uVar4 == 0x1100) {
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    uVar5 = uVar5 | 0x400;
    uVar4 = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0xf00) {
    *(undefined2 *)(param_1 + 0x130) = 0x900;
    uVar5 = uVar5 | 0x80;
    uVar4 = 0x900;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0x1000) {
    uVar4 = 0xe00;
    uVar5 = uVar5 | 0x200;
    *(undefined2 *)(param_1 + 0x130) = 0xe00;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0x1200) {
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    uVar5 = uVar5 | 0x800;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  uVar3 = lm_is_e3(param_1);
  if (((int)uVar3 != 0) &&
     (*(ushort *)(param_1 + 0x14e) = uVar5 | 0x20,
     ((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfc000000 & 0xfeffffff) == 0)) {
    *(ushort *)(param_1 + 0x14e) = uVar5 | 0x60;
  }
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 == 0) {
    uVar6 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + (bVar1 ^ 1) * 400 + iVar7);
    uVar6 = uVar6 & 0xff;
  }
  else {
    uVar6 = uVar2 & 0xff ^ 1;
  }
  *(ushort *)(param_1 + 0x12e) = uVar6;
  return;
}



===== lm_gpio_write @ 14000bc94 =====

void lm_gpio_write(undefined8 param_1,char param_2,char param_3,char param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  
  iVar2 = ev_lm_reg_read_ind(param_1,0x10394);
  cVar5 = '\0';
  if (iVar2 != 0) {
    iVar2 = ev_lm_reg_read_ind(param_1,0x10398);
    if (iVar2 != 0) {
      cVar5 = '\x01';
    }
  }
  bVar1 = (-(cVar5 != param_2) & 4U) + param_3;
  uVar3 = ev_lm_reg_read_ind(param_1,0xa490);
  uVar6 = 0x10000 << (bVar1 & 0x1f);
  uVar3 = uVar3 & ~(0x1000000 << (bVar1 & 0x1f));
  uVar4 = 0x100 << (bVar1 & 0x1f);
  if (param_4 == '\x01') {
    uVar6 = ~uVar6 & uVar3;
  }
  else {
    uVar4 = ~uVar4 & uVar3;
  }
  ev_lm_reg_write_ind(param_1,0xa490,uVar6 | uVar4);
  return;
}



===== lm_init_common_part @ 14000bd50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 lm_init_common_part(longlong param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined1 auStack_68 [32];
  int local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  lm_chip_reset_all_blocks(param_1);
  ev_lm_reg_write_ind(param_1,0xa280,1);
  ev_lm_reg_write_ind(param_1,0xa294,0x71d2911);
  ev_lm_reg_write_ind(param_1,0xa298,0);
  ev_lm_reg_write_ind(param_1,0xa29c,0x9c0424);
  ev_lm_reg_write_ind(param_1,0xa2a0,0);
  ev_lm_reg_write_ind(param_1,0xa2a8,0x100);
  mm_stall(0x1e);
  ev_lm_reg_write_ind(param_1,0xa2a8,0);
  iVar4 = 0x103800;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xcccccccc);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x104000);
  iVar4 = 0x103c10;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0x1002000);
    iVar4 = iVar4 + 0x20;
  } while (iVar4 < 0x103d10);
  iVar8 = 0;
  iVar4 = 0x103e10;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,iVar8 * 0x1000000 + 0x1000000U | 0x2000);
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x20;
  } while (iVar4 < 0x103f10);
  ev_lm_reg_write_ind(param_1,0x103e10,0x1002000);
  ev_lm_reg_write_ind(param_1,0x103e30,0x2002000);
  everest_init_pxp2_common(param_1);
  everest_init_tcm_common(param_1);
  everest_init_ucm_common(param_1);
  everest_init_ccm_common(param_1);
  everest_init_xcm_common(param_1);
  everest_init_qm_common(param_1);
  ev_lm_reg_write_ind(param_1,0x168428,1);
  ev_lm_reg_write_ind(param_1,0x168428,0);
  ev_lm_reg_write_ind(param_1,0x16401c,250000);
  ev_lm_reg_write_ind(param_1,0x170008,1);
  ev_lm_reg_write_ind(param_1,0x17002c,7);
  ev_lm_reg_write_ind(param_1,0x17003c,4);
  ev_lm_reg_write_ind(param_1,0x170048,2);
  ev_lm_reg_write_ind(param_1,0x17004c,0x90);
  ev_lm_reg_write_ind(param_1,0x170050,0x90);
  ev_lm_reg_write_ind(param_1,0x170054,0x800090);
  ev_lm_reg_write_ind(param_1,0x170058,0x8140000);
  uVar2 = lm_is_dual_core(param_1);
  uVar5 = -(uint)((int)uVar2 != 0) & 0x3a0;
  ev_lm_reg_write_ind(param_1,uVar5 + 0x170060,10);
  ev_lm_reg_write_ind(param_1,uVar5 + 0x170064,10);
  ev_lm_reg_write_ind(param_1,uVar5 + 0x170068,0x10);
  ev_lm_reg_write_ind(param_1,uVar5 + 0x17006c,0x10);
  ev_lm_reg_write_ind(param_1,0x170070,6);
  ev_lm_reg_write_ind(param_1,0x170038,0x7c1004);
  ev_lm_reg_write_ind(param_1,0x170004,0xf);
  ev_lm_reg_write_ind(param_1,0x170030,7);
  uVar5 = 0;
  iVar4 = 0x61000;
  do {
    uVar5 = uVar5 + 0x2000;
    ev_lm_reg_write_ind(param_1,iVar4,uVar5);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x617fc);
  ev_lm_reg_write_ind(param_1,0x617fc,uVar5 | 1);
  ev_lm_reg_write_ind(param_1,0x600dc,1);
  ev_lm_reg_write_ind(param_1,0x60200,0);
  ev_lm_reg_write_ind(param_1,0x60204,0x1ff);
  ev_lm_reg_write_ind(param_1,0x60208,0x200);
  ev_lm_reg_write_ind(param_1,0x600dc,0);
  ev_lm_reg_write_ind(param_1,0x40048,10);
  ev_lm_reg_write_ind(param_1,0x40070,4);
  ev_lm_reg_write_ind(param_1,0x400b8,0x160000);
  ev_lm_reg_write_ind(param_1,0x400bc,0x100000);
  ev_lm_reg_write_ind(param_1,0x400dc,0x160000);
  ev_lm_reg_write_ind(param_1,0x40004,0xff);
  ev_lm_reg_write_ind(param_1,0x40138,1);
  if ((*(uint *)(param_1 + 0x58) >> 0x11 & 1) != 0) {
    uVar5 = *(uint *)(param_1 + 0x58) & 0x4000;
    uVar6 = (uVar5 | 0x18000) >> 0xe;
    if (uVar5 != 0) {
      ev_lm_reg_write_ind(param_1,0x401c8,1);
      ev_lm_reg_write_ind(param_1,0x40254,1);
      ev_lm_reg_write_ind(param_1,0x4028c,1);
      ev_lm_reg_write_ind(param_1,0x402ac,1);
    }
    ev_lm_reg_write_ind(param_1,0x40238,uVar6);
    ev_lm_reg_write_ind(param_1,0x40270,uVar6);
    ev_lm_reg_write_ind(param_1,0x40290,uVar6);
  }
  ev_lm_reg_write_ind(param_1,0x42008,0x411);
  ev_lm_reg_write_ind(param_1,0x4200c,0x400);
  ev_lm_reg_write_ind(param_1,0x42010,0x404);
  ev_lm_reg_write_ind(param_1,0x42014,0x419);
  iVar4 = 0x4201c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x4202c);
  ev_lm_reg_write_ind(param_1,0x42038,0x34);
  iVar8 = 0;
  iVar4 = 0x4203c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,iVar8 + 5);
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x4205c);
  ev_lm_reg_write_ind(param_1,0x421b8,0);
  iVar8 = 0x421bc;
  iVar4 = 0x421dc;
  do {
    ev_lm_reg_write_ind(param_1,iVar8,1);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x421dc);
  do {
    ev_lm_reg_write_ind(param_1,iVar4 + -0x180,0);
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x42238);
  iVar4 = 0x42138;
  do {
    ev_lm_reg_write_ind(param_1,iVar4 + -0x80,0);
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x421b8);
  ev_lm_reg_write_ind(param_1,0x42238,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0x4223c,0x3f);
  ev_lm_reg_write_ind(param_1,0x42240,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0x42244,0xf);
  ev_lm_reg_write_ind(param_1,0x42000,1000);
  ev_lm_reg_write_ind(param_1,0xc2008,0xa11);
  ev_lm_reg_write_ind(param_1,0xc200c,0xa00);
  ev_lm_reg_write_ind(param_1,0xc2010,0xa04);
  iVar4 = 0xc201c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc202c);
  ev_lm_reg_write_ind(param_1,0xc2038,0x34);
  iVar4 = 0xc203c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc20b8);
  iVar4 = 0xc2138;
  do {
    ev_lm_reg_write_ind(param_1,iVar4 + -0x80,0);
    ev_lm_reg_write_ind(param_1,iVar4,0);
    ev_lm_reg_write_ind(param_1,iVar4 + 0x80,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc21b8);
  ev_lm_reg_write_ind(param_1,0xc2238,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0xc223c,0x3f);
  ev_lm_reg_write_ind(param_1,0xc2240,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0xc2244,0xf);
  ev_lm_reg_write_ind(param_1,0xc2000,1000);
  ev_lm_reg_write_ind(param_1,0xc4008,0xa11);
  ev_lm_reg_write_ind(param_1,0xc400c,0xa00);
  ev_lm_reg_write_ind(param_1,0xc4010,0xa04);
  ev_lm_reg_write_ind(param_1,0xc4014,0xa21);
  iVar4 = 0xc401c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc402c);
  ev_lm_reg_write_ind(param_1,0xc4038,0x34);
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      iVar8 = 0xc4038;
      uVar10 = 0x34;
    }
    else {
      iVar8 = iVar4 * 4 + 0xc4038;
      uVar10 = 0;
    }
    ev_lm_reg_write_ind(param_1,iVar8,uVar10);
    ev_lm_reg_write_ind(param_1,iVar4 * 4 + 0xc40b8,0);
    ev_lm_reg_write_ind(param_1,iVar4 * 4 + 0xc4138,0);
    ev_lm_reg_write_ind(param_1,iVar4 * 4 + 0xc41b8,0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  ev_lm_reg_write_ind(param_1,0xc4238,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0xc423c,0x3f);
  ev_lm_reg_write_ind(param_1,0xc4240,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0xc4244,0xf);
  ev_lm_reg_write_ind(param_1,0xc4000,1000);
  ev_lm_reg_write_ind(param_1,0x166008,0xa14);
  ev_lm_reg_write_ind(param_1,0x16600c,0xa00);
  ev_lm_reg_write_ind(param_1,0x166010,0xa04);
  iVar4 = 0x16601c;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x16602c);
  ev_lm_reg_write_ind(param_1,0x166038,0x34);
  ev_lm_reg_write_ind(param_1,0x16603c,0x10);
  ev_lm_reg_write_ind(param_1,0x166040,0x10);
  iVar4 = 0x166044;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x1660b8);
  iVar4 = 0x166138;
  iVar8 = 0x1661b8;
  do {
    ev_lm_reg_write_ind(param_1,iVar4 + -0x80,0);
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x1661b8);
  iVar4 = 0;
  do {
    ev_lm_reg_write_ind(param_1,iVar8,(uint)(iVar4 == 1));
    iVar4 = iVar4 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x166238);
  ev_lm_reg_write_ind(param_1,0x166238,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0x16623c,0x3f);
  ev_lm_reg_write_ind(param_1,0x166240,0x7ffffff);
  ev_lm_reg_write_ind(param_1,0x166244,0xf);
  ev_lm_reg_write_ind(param_1,0x166000,1000);
  local_48[0] = 0x1a0000;
  piVar9 = local_48;
  local_48[1] = 0x220000;
  lVar7 = 4;
  local_48[2] = 0x2a0000;
  local_48[3] = 0x320000;
  do {
    iVar4 = *piVar9;
    uVar5 = 0;
    do {
      ev_lm_reg_write_ind(param_1,iVar4 + uVar5,0);
      uVar5 = uVar5 + 4;
    } while (uVar5 < 0x5800);
    piVar9 = piVar9 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar5 = 0;
  if (l2fw_tstorm_len != 0) {
    do {
      ev_lm_reg_write_ind(param_1,uVar5 + 0x1c0000,(&l2fw_tstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_tstorm_len);
  }
  uVar5 = 0;
  if (l2fw_cstorm_len != 0) {
    do {
      ev_lm_reg_write_ind(param_1,uVar5 + 0x240000,(&l2fw_cstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_cstorm_len);
  }
  uVar5 = 0;
  if (l2fw_xstorm_len != 0) {
    do {
      ev_lm_reg_write_ind(param_1,uVar5 + 0x2c0000,(&l2fw_xstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_xstorm_len);
  }
  uVar5 = 0;
  if (l2fw_ustorm_len != 0) {
    do {
      ev_lm_reg_write_ind(param_1,uVar5 + 0x340000,(&l2fw_ustorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_ustorm_len);
  }
  everest_init_tsem_common(param_1);
  everest_init_usem_common(param_1);
  everest_init_csem_common(param_1);
  everest_init_xsem_common(param_1);
  ev_lm_reg_write_ind(param_1,0xa588,0x80000000);
  ev_lm_reg_write_ind(param_1,0xa584,0x80000000);
  ev_lm_reg_write_ind(param_1,0xc1000,0x20);
  ev_lm_reg_write_ind(param_1,0x161000,0x20);
  everest_init_pbf_common(param_1);
  ev_lm_reg_write_ind(param_1,0x101020,0x4000400);
  ev_lm_reg_write_ind(param_1,0x101000,0);
  ev_lm_reg_write_ind(param_1,0x101008,9);
  lm_reg_write_block(param_1,0x101800,(undefined4 *)&DAT_140016170,0x40);
  lm_reg_write_block(param_1,0x101100,(undefined4 *)&DAT_140016270,8);
  if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
    ev_lm_reg_write_ind(param_1,0x101050,1);
  }
  ev_lm_reg_write_ind(param_1,0x10404c,0x7ff);
  ev_lm_reg_write_ind(param_1,0x104028,0x10);
  ev_lm_reg_write_ind(param_1,0x104044,0x3fff);
  ev_lm_reg_write_ind(param_1,0x104084,0x84924a);
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    ev_lm_reg_write_ind(param_1,0x108068,0x288);
    ev_lm_reg_write_ind(param_1,0x10806c,0x288);
    ev_lm_reg_write_ind(param_1,0x108070,0x288);
    ev_lm_reg_write_ind(param_1,0x108074,0x288);
  }
  iVar4 = 0xa000;
  do {
    ev_lm_reg_write_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xa058);
  ev_lm_reg_write_ind(param_1,0x10104,1);
  ev_lm_reg_write_ind(param_1,0x100b4,1);
  ev_lm_reg_write_ind(param_1,0x100b8,1);
  ev_lm_reg_write_ind(param_1,0x10100,1);
  ev_lm_reg_write_ind(param_1,0x120330,0);
  ev_lm_reg_write_ind(param_1,0x120374,0);
  ev_lm_reg_write_ind(param_1,0x104050,0);
  if (((*(short *)(param_1 + 0x130) == 0x600) || (*(short *)(param_1 + 0x130) == 0x900)) &&
     ((*(byte *)(param_1 + 1) & 1) == 0)) {
    uVar1 = *(undefined1 *)(param_1 + 0x13a);
    bVar3 = ~*(byte *)(param_1 + 0x14e) & 1;
    *(byte *)(param_1 + 0x13a) = bVar3;
    lm_gpio_write(param_1,bVar3,'\x01','\x01');
    mm_stall(100000);
    *(undefined1 *)(param_1 + 0x13a) = uVar1;
  }
  ev_lm_reg_write_ind(param_1,0xa30c,0xffffffff);
  ev_lm_reg_write_ind(param_1,0xa5dc,0);
  ev_lm_reg_write_ind(param_1,0xa2ec,3);
  return 0;
}



===== lm_init_connection_context @ 14000cadc =====

void lm_init_connection_context(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  mm_init_context(param_1);
  lVar1 = *(longlong *)(param_1 + 0x78);
  lVar2 = (ulonglong)param_2 * 0x1e0;
  *(undefined4 *)(lVar1 + 0x204) = *(undefined4 *)(lVar2 + 0x2b4 + param_1);
  *(undefined4 *)(lVar1 + 0x200) = *(undefined4 *)(lVar2 + 0x2b0 + param_1);
  *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(lVar2 + 0x4ac + param_1);
  *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(lVar2 + 0x4a8 + param_1);
  *(undefined1 *)(lVar1 + 2) = 0;
  *(undefined4 *)(lVar1 + 0x14) = *(undefined4 *)((ulonglong)param_2 * 0x40 + 0x694 + param_1);
  *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)((ulonglong)param_2 * 0x40 + 0x690 + param_1);
  *(undefined1 *)(lVar1 + 0x2f0) = 0;
  return;
}



===== lm_init_ext_phy @ 14000cb64 =====

void lm_init_ext_phy(longlong param_1)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  
  uVar3 = 0;
  do {
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar1 & 0x8000) == 0) break;
    mm_stall(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 1000);
  sVar2 = *(short *)(param_1 + 0x130);
  if (sVar2 == 0x300) {
    lm_mwrite45(param_1,0x300,*(ushort *)(param_1 + 300),1,0x9000,4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x9002,4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x11,0xa0);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329,uVar3 | 1);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x12);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x12,uVar3 | 0x8000
               );
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0,0x1200);
    mm_stall(500000);
  }
  else if (sVar2 == 0x600) {
    sVar2 = lm_mread45(param_1,0x600,*(ushort *)(param_1 + 300),1,0xca1c);
    if (sVar2 != -1) {
      mm_stall(100000);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,1);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1e,0x73a0);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x18a);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
      mm_stall(100000);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,0);
      mm_stall(200000);
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4;
    }
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,
                uVar3 & 0x7fff);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x9002,1);
  }
  else if (sVar2 == 0x700) {
    sVar2 = 0x700;
    if ((*(uint *)(param_1 + 0x148) & 0x200000) == 0) {
      uVar3 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),0x1e,0x4005);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,
                  uVar3 & 0xff7f);
      sVar2 = *(short *)(param_1 + 0x130);
    }
    uVar3 = lm_mread45(param_1,sVar2,*(ushort *)(param_1 + 300),7,0xffe9);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe9,
                uVar3 | 0x300);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4,
                uVar3 | 0xde0);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0,0x1200);
    mm_stall(500000);
    if ((*(ushort *)(param_1 + 0x14e) & 0x418) != 0) {
      lm_phy_848xx_prg_leds(param_1);
    }
  }
  else if (sVar2 == 0x900) {
    uVar3 = 0xd;
    bVar4 = (*(uint *)(param_1 + 0x18c) & 0xff00) != 0x300;
    if (bVar4) {
      uVar3 = 8;
    }
    uVar1 = 0x40;
    if (bVar4) {
      uVar1 = 0x2040;
    }
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0,uVar1);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,7,uVar3);
    lm_bcm8727_set_edc_mode(param_1);
    lm_phy_8727_ctrl_optical_output(param_1,1);
  }
  else if (sVar2 == 0xe00) {
    uVar3 = lm_mread22_ext(param_1,4);
    lm_mwrite22_ext(param_1,4,uVar3 | 0xde0);
    uVar3 = lm_mread22_ext(param_1,9);
    lm_mwrite22_ext(param_1,9,uVar3 | 0x300);
    lm_mwrite22_ext(param_1,0,0x1200);
  }
  return;
}



===== lm_init_function_part @ 14000d178 =====

undefined8 lm_init_function_part(longlong param_1)

{
  char cVar1;
  bool bVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  cVar1 = *(char *)(param_1 + 0x138);
  lm_init_connection_context(param_1,0);
  ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x10330,0);
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) == 0x164e0000) {
    cVar1 = *(char *)(param_1 + 0x138);
    ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x120000,
                        -(uint)(cVar1 != '\0') & 0x60180);
    uVar6 = -(uint)(cVar1 != '\0') & 0xc00;
  }
  else {
    ev_lm_reg_write_ind(param_1,0x12061c,(uint)*(byte *)(param_1 + 0x13d));
    ev_lm_reg_write_ind(param_1,0x120620,(uint)*(byte *)(param_1 + 0x13d));
    ev_lm_reg_write_ind(param_1,(-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x120000,
                        (uint)*(byte *)(param_1 + 0x13d) << 10 | (uint)*(byte *)(param_1 + 0x13d));
    uVar6 = (uint)*(byte *)(param_1 + 0x13d) << 3;
  }
  ev_lm_reg_write_ind(param_1,uVar6 + 0x122000,
                      *(int *)(param_1 + 0x84) << 0x14 | *(uint *)(param_1 + 0x80) >> 0xc);
  ev_lm_reg_write_ind(param_1,uVar6 + 0x122004,*(uint *)(param_1 + 0x84) >> 0xc | 0x100000);
  if (*(byte *)(param_1 + 0x13d) < 2) {
    mm_pcicfg_map(param_1,1);
  }
  iVar7 = 0;
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x80) >> 0xc;
  if ((*(uint *)(param_1 + 0x58) & 0x10000) != 0) {
    everest_init_xcm_port(param_1);
    everest_init_qm_port(param_1);
    ev_lm_reg_write_ind(param_1,(-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x400fc,
                        -(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x800000);
    uVar6 = ev_lm_reg_read_ind(param_1,0x40134);
    ev_lm_reg_write_ind(param_1,0x40134,uVar6 | 5);
    if (*(char *)(param_1 + 0x138) == '\0') {
      ev_lm_reg_write_ind(param_1,0x140030,1);
      uVar4 = 0x14005c;
    }
    else {
      ev_lm_reg_write_ind(param_1,0x140034,1);
      uVar4 = 0x140060;
    }
    ev_lm_reg_write_ind(param_1,uVar4,0);
  }
  iVar8 = iVar7;
  do {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xe4) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xbc) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xcc) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar9 = 0;
  iVar8 = iVar7;
  do {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xd4) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xc4) + -8 + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x10);
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 200),0);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 200) + 4,0);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    iVar9 = (*(short *)(param_1 + 0xec) == 0x700) + 1;
  }
  ev_lm_reg_write_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 8 + 0x431944,iVar9);
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 == 0) {
    if (*(char *)(param_1 + 0x138) == '\0') {
      uVar4 = 0x108000;
      ev_lm_reg_write_ind(param_1,0x108000,0x1080);
      ev_lm_reg_write_ind(param_1,0x108028,0x2860286);
      ev_lm_reg_write_ind(param_1,0x10802c,0x2860286);
      ev_lm_reg_write_ind(param_1,0x108050,0);
      ev_lm_reg_write_ind(param_1,0x108008,0x2b5);
      ev_lm_reg_write_ind(param_1,0x108010,0);
      iVar7 = 0x108200;
      do {
        ev_lm_reg_write_ind(param_1,iVar7,0);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x108328);
      uVar5 = 0x108108;
    }
    else {
      uVar4 = 0x108004;
      ev_lm_reg_write_ind(param_1,0x108004,0x1080);
      ev_lm_reg_write_ind(param_1,0x108030,0x2870287);
      ev_lm_reg_write_ind(param_1,0x108034,0x2870287);
      ev_lm_reg_write_ind(param_1,0x108054,0);
      ev_lm_reg_write_ind(param_1,0x10800c,0x2b5);
      ev_lm_reg_write_ind(param_1,0x108014,0);
      iVar7 = 0x108400;
      do {
        ev_lm_reg_write_ind(param_1,iVar7,0);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x108528);
      uVar5 = 0x10810c;
    }
    iVar7 = 0x1ffff;
  }
  else {
    uVar6 = ev_lm_reg_read_ind(param_1,0x130154);
    ev_lm_reg_write_ind(param_1,0x130154,uVar6 & 0xfffffff5 | 0x31);
    ev_lm_reg_write_ind(param_1,0x13015c,0);
    ev_lm_reg_write_ind(param_1,0x130160,0);
    uVar4 = 0x130168;
    uVar5 = 0x130164;
  }
  ev_lm_reg_write_ind(param_1,uVar5,iVar7);
  ev_lm_reg_write_ind(param_1,uVar4,0);
  ev_lm_reg_write_ind(param_1,0xd0114,8);
  everest_init_nig_port(param_1);
  ev_lm_reg_read_ind(param_1,0x282000);
  ev_lm_reg_read_ind(param_1,0x282004);
  ev_lm_reg_read_ind(param_1,0x282008);
  ev_lm_reg_read_ind(param_1,0x202000);
  ev_lm_reg_read_ind(param_1,0x202004);
  ev_lm_reg_read_ind(param_1,0x202008);
  ev_lm_reg_read_ind(param_1,0x181000);
  ev_lm_reg_read_ind(param_1,0x181004);
  ev_lm_reg_read_ind(param_1,0x181008);
  ev_lm_reg_read_ind(param_1,0x302000);
  ev_lm_reg_read_ind(param_1,0x302004);
  ev_lm_reg_read_ind(param_1,0x302008);
  return 0;
}



===== lm_init_fw_offsets @ 14000d6b4 =====

void lm_init_fw_offsets(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  if ((*(uint *)(param_1 + 0x58) & 0x8000) == 0) {
    bVar1 = *(byte *)(param_1 + 0x138);
    iVar10 = (uint)bVar1 * 0x10 + 0x431508;
    uVar2 = (uint)bVar1;
    iVar7 = uVar2 * 0x18 + 0x401408;
    iVar12 = (bVar1 + 0x2ab80) * 0x18;
    iVar5 = (bVar1 + 0x2b62b) * 0x18;
    iVar8 = (bVar1 + 0x2cb80) * 0x18;
    iVar13 = (uint)bVar1 * 8 + 0x431520;
    iVar4 = (bVar1 + 0x2c362) * 0x18;
    iVar6 = uVar2 * 0x18 + 0x411400;
    iVar14 = uVar2 * 0x18 + 0x431408;
    iVar11 = uVar2 * 0x18 + 0x421408;
    iVar9 = uVar2 * 0x18 + 0x421400;
    iVar3 = uVar2 * 0x18 + 0x425128;
  }
  else {
    iVar9 = *(byte *)(param_1 + 0x13e) - 2;
    iVar3 = iVar9 * 0x18;
    iVar13 = iVar9 * 8 + 0x4318a0;
    iVar10 = iVar9 * 0x10 + 0x431848;
    iVar9 = iVar3 + 0x421448;
    iVar7 = iVar3 + 0x401450;
    iVar12 = iVar3 + 0x401448;
    iVar5 = iVar3 + 0x411450;
    iVar6 = iVar3 + 0x411448;
    iVar14 = iVar3 + 0x431450;
    iVar8 = iVar3 + 0x431448;
    iVar4 = iVar3 + 0x425190;
    iVar3 = iVar3 + 0x425188;
    iVar11 = iVar9;
  }
  *(int *)(param_1 + 0xbc) = iVar3;
  *(int *)(param_1 + 0xc0) = iVar4;
  *(int *)(param_1 + 0xc4) = iVar10;
  *(int *)(param_1 + 200) = iVar13;
  *(int *)(param_1 + 0xcc) = iVar9;
  *(int *)(param_1 + 0xd0) = iVar11;
  *(int *)(param_1 + 0xd4) = iVar8;
  *(int *)(param_1 + 0xd8) = iVar14;
  *(int *)(param_1 + 0xdc) = iVar6;
  *(int *)(param_1 + 0xe0) = iVar5;
  *(int *)(param_1 + 0xe4) = iVar12;
  *(int *)(param_1 + 0xe8) = iVar7;
  return;
}



===== lm_init_status_blocks @ 14000d830 =====

void lm_init_status_blocks(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 *puVar7;
  int iVar8;
  
  uVar4 = lm_is_dual_core(param_1);
  uVar5 = 0;
  if ((int)uVar4 != 0) {
    uVar6 = 0;
    do {
      uVar3 = ev_lm_reg_read_ind(param_1,(uint)uVar6 * 4 + 0x131000);
      if ((((uVar3 & 0x2001) == 0x2001) && (((byte)(uVar3 >> 7) & 7) == *(byte *)(param_1 + 0x13e)))
         && ((uVar3 & 0x7e) == 0)) goto LAB_14000d8ab;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x88);
  }
  uVar6 = 0x10;
LAB_14000d8ab:
  *(ushort *)(param_1 + 0xb0) = uVar6;
  *(undefined8 *)(param_1 + 100) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x28) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x38) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x18) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x48) = 0;
  cVar1 = *(char *)(param_1 + 0x138);
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar4 = lm_is_dual_core(param_1);
  if ((int)uVar4 != 0) {
    *(undefined1 *)(lVar2 + 0x1a) = 1;
    puVar7 = (undefined4 *)(lVar2 + 0x10);
    *(undefined1 *)(lVar2 + 0x2a) = 3;
    uVar3 = 0;
    iVar8 = 0;
    *(undefined1 *)(lVar2 + 0x2b) = *(undefined1 *)(param_1 + 0xb0);
    *(undefined1 *)(lVar2 + 0x1b) = *(undefined1 *)(param_1 + 0xb0);
    do {
      ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xe8) + iVar8,*puVar7);
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar3 < 4);
    iVar8 = 0;
    puVar7 = (undefined4 *)(lVar2 + 0x20);
    do {
      ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xe0) + iVar8,*puVar7);
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar5 < 4);
  }
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xe4),*(int *)(param_1 + 0x28) + 0x10);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xe4) + 4,*(undefined4 *)(param_1 + 0x2c));
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xdc),*(int *)(param_1 + 0x28) + 0x20);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xdc) + 4,*(undefined4 *)(param_1 + 0x2c));
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xcc),*(int *)(param_1 + 0x28) + 0x30);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xcc) + 4,*(undefined4 *)(param_1 + 0x2c));
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xd4),*(int *)(param_1 + 0x28) + 0x40);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0xd4) + 4,*(undefined4 *)(param_1 + 0x2c));
  uVar5 = -(uint)(cVar1 != '\0') & 8;
  ev_lm_reg_write_ind(param_1,uVar5 + 0x108018,*(undefined4 *)(param_1 + 0x28));
  ev_lm_reg_write_ind(param_1,uVar5 + 0x10801c,*(undefined4 *)(param_1 + 0x2c));
  return;
}



===== lm_insert_vntag_vlan_hdr @ 14000da54 =====

void lm_insert_vntag_vlan_hdr(longlong param_1,longlong param_2)

{
  byte bVar1;
  short sVar2;
  longlong lVar3;
  uint uVar4;
  
  *(undefined4 *)(param_2 + 0x28) = 0;
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    lVar3 = *(longlong *)(param_2 + 0x38);
    *(undefined4 *)(lVar3 + 0xc) = 0x2689;
    sVar2 = *(short *)(param_1 + 0x3c);
    bVar1 = *(byte *)(param_1 + 0x3d);
    *(undefined2 *)(lVar3 + 0x12) = 0x81;
    *(ushort *)(lVar3 + 0x10) = sVar2 << 8 | (ushort)bVar1;
    uVar4 = *(uint *)(param_1 + 0x34);
    if ((uVar4 & 0xfff) == 0) {
      uVar4 = *(ushort *)(param_1 + 0x3e) & 0xfff | uVar4;
      *(uint *)(param_1 + 0x34) = uVar4;
    }
    *(ushort *)(lVar3 + 0x14) = (ushort)(uVar4 >> 8) & 0xff | *(short *)(param_1 + 0x34) << 8;
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 10;
    return;
  }
  uVar4 = *(uint *)(param_1 + 0x34);
  if (*(short *)(param_1 + 0xec) == 0x500) {
    uVar4 = uVar4 & 0xfff;
  }
  if (uVar4 != 0) {
    *(undefined2 *)(*(longlong *)(param_2 + 0x38) + 0xc) = 0x81;
    *(ushort *)(*(longlong *)(param_2 + 0x38) + 0xe) =
         (ushort)((uint)*(undefined4 *)(param_1 + 0x34) >> 8) & 0xff |
         *(short *)(param_1 + 0x34) << 8;
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 4;
  }
  return;
}



===== lm_intr_ack_sb @ 14000db28 =====

void lm_intr_ack_sb(longlong param_1,byte param_2,byte param_3,ushort param_4,byte param_5,
                   byte param_6)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 == 0) {
    uVar3 = ((uint)(ushort)((((ushort)param_5 * 2 | (ushort)param_6) << 3 | (ushort)param_3) << 5) |
            (uint)param_2) << 0x10 | (uint)param_4;
    uVar1 = lm_is_e3(param_1);
    if (((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
        ((*(uint *)(param_1 + 0x58) & 0x20000) == 0)) && (*(byte *)(param_1 + 0x13d) < 2))
    goto LAB_14000dbf0;
    iVar2 = (uint)*(byte *)(param_1 + 0x138) * 0x2000 + 0x441000;
  }
  else {
    uVar3 = (((uint)param_5 * 2 | (uint)param_6) << 3 | (uint)param_3) << 0x15 | (uint)param_4;
    uVar1 = lm_is_e3(param_1);
    if ((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
       (((*(uint *)(param_1 + 0x58) & 0x20000) == 0 && (*(byte *)(param_1 + 0x13d) < 2)))) {
LAB_14000dbf0:
      storport_pci_cfg_write_dword(param_1,0x88,uVar3);
      return;
    }
    iVar2 = (uint)*(ushort *)(param_1 + 0xb0) * 8 + 0x442000;
  }
  ev_lm_reg_write_ind(param_1,iVar2,uVar3);
  return;
}



===== lm_is_dual_core @ 14000dc38 =====

undefined8 lm_is_dual_core(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if (((uVar1 + 0xe9b20000 & 0xfffcffff) == 0) && (uVar1 != 0x16510000)) {
    return 0;
  }
  return 1;
}



===== lm_is_e3 @ 14000dc64 =====

undefined8 lm_is_e3(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if (((uVar1 == 0x168a0000) || (uVar1 == 0x168e0000)) || (uVar1 == 0x168d0000)) {
    return 1;
  }
  return 0;
}



===== lm_is_mf_cfg @ 14000dc90 =====

bool lm_is_mf_cfg(longlong param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  undefined8 uVar6;
  byte bVar7;
  byte bVar8;
  
  bVar8 = *(byte *)(param_1 + 0x13a);
  bVar7 = 0;
  uVar6 = lm_is_mf_device(param_1);
  if (((int)uVar6 == 0) ||
     (uVar5 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354), (uVar5 & 0x700) == 0x100
     )) {
    return false;
  }
  sVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x30);
  if (sVar4 != -1) {
    return true;
  }
  cVar1 = *(char *)(param_1 + 0x158);
  for (; bVar8 < 8; bVar8 = bVar8 + (-(cVar1 != '\0') & 0xfeU) + 4) {
    bVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + (uint)bVar8 * 0x18);
    bVar2 = bVar7 + 1;
    if ((bVar3 & 1) != 0) {
      bVar2 = bVar7;
    }
    bVar7 = bVar2;
  }
  return 1 < bVar7;
}



===== lm_is_mf_device @ 14000dd6c =====

undefined8 lm_is_mf_device(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if ((((uVar1 == 0x16500000) || (uVar1 == 0x16620000)) || (uVar1 == 0x16630000)) ||
     (((uVar1 == 0x168a0000 || (uVar1 == 0x168e0000)) || (uVar1 == 0x168d0000)))) {
    return 1;
  }
  return 0;
}



===== lm_is_phy_link_up @ 14000ddac =====

undefined4 lm_is_phy_link_up(longlong param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined7 extraout_var;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined7 extraout_var_00;
  ushort uVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  int iVar11;
  
  uVar9 = 0;
  uVar10 = 0;
  if (param_2 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = lm_phy_get_sigdet(param_1);
  }
  if (((*(byte *)(param_1 + 0x14e) & 0x20) == 0) || (param_2 == 0)) {
LAB_14000de1c:
    if (uVar4 == 0) goto LAB_14000e22a;
  }
  else if (uVar4 == 0) {
    uVar10 = 0;
    do {
      bVar2 = lm_phy_wc_get_sigdet(param_1);
      if ((int)CONCAT71(extraout_var,bVar2) != 0) goto LAB_14000de24;
      uVar10 = uVar10 + 1;
      uVar4 = 0;
    } while (uVar10 < 0x28);
    goto LAB_14000de1c;
  }
LAB_14000de24:
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    iVar11 = 0;
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        iVar8 = 0;
        uVar3 = lm_phy_get_gp_status(param_1);
        uVar7 = *(ushort *)(param_1 + 0x14e) & 0x20;
        if ((uVar3 & 4) == 0) {
          if ((((uVar7 != 0) && ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000)) &&
              (uVar10 != 0)) && ((uint)uVar10 == (uVar10 / 10000) * 10000)) {
            lm_mwrite45_int2(param_1,0x8345,0xc000);
            lm_mwrite45_int2(param_1,0x8345,0);
          }
          iVar11 = iVar8;
LAB_14000e20d:
          mm_stall(1000);
        }
        else {
          iVar11 = iVar11 + 1;
          if (uVar7 == 0) {
            do {
              uVar6 = lm_phy_get_gp_status(param_1);
              if ((uVar6 & 4) == 0) break;
              mm_stall(1000);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 100);
            if (iVar8 < 100) {
              if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
                bVar2 = lm_phy_cx4_get_sigdet(param_1);
                if ((((int)CONCAT71(extraout_var_00,bVar2) != 0) &&
                    (uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8371),
                    (uVar3 & 0x500) == 0x500)) &&
                   (uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8330),
                   (uVar3 & 0x610) == 0x610)) {
                  lm_mwrite45_int2(param_1,0,0);
                  lm_mwrite45_int2(param_1,0xffe0,0x800);
                  mm_stall(300000);
                  lm_mwrite45_int2(param_1,0xffe0,0x1200);
                }
              }
              else {
              }
              goto LAB_14000e20d;
            }
            uVar9 = 1;
            break;
          }
          uVar9 = 1;
          if (((*(uint *)(param_1 + 0x148) & 0xf000000) != 0x3000000) || (999 < iVar11)) break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
    goto LAB_14000e22a;
  }
  if (sVar1 == 0x300) {
LAB_14000dff1:
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        uVar5 = lm_phy_get_pma_link_status(param_1,1);
        if (((int)uVar5 != 0) &&
           (uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,
                               0xc820), (uVar3 & 0xa000) != 0xa000)) goto LAB_14000dfe9;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
  }
  else {
    if (((sVar1 - 0x400U & 0xfcff) != 0) || (sVar1 == 0x700)) {
      if (sVar1 == 0x700) {
        uVar10 = 0;
        if (*(short *)(param_1 + 0x5e) != 0) {
          do {
            uVar5 = lm_phy_get_mii_link_status(param_1,1);
            if ((int)uVar5 != 0) goto LAB_14000dfe9;
            if ((((*(ushort *)(param_1 + 0x14e) & 0x410) != 0) &&
                ((uint)uVar10 == (uVar10 / 2000) * 2000)) &&
               (uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,
                                   0x20), (uVar3 & 0x1000) == 0)) {
              lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20,
                          uVar3 | 0x1000);
              lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0,
                          0x1200);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(ushort *)(param_1 + 0x5e));
        }
        goto LAB_14000e22a;
      }
      if (sVar1 != 0x800) {
        if (sVar1 != 0x900) {
          if ((sVar1 == 0xe00) && (uVar10 = 0, *(short *)(param_1 + 0x5e) != 0)) {
            do {
              uVar5 = lm_phy_get_ieee_link_status(param_1,1);
              if ((int)uVar5 != 0) goto LAB_14000dfe9;
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(ushort *)(param_1 + 0x5e));
          }
          goto LAB_14000e22a;
        }
        goto LAB_14000dff1;
      }
    }
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        uVar5 = lm_phy_get_pma_link_status(param_1,1);
        if ((int)uVar5 != 0) goto LAB_14000dfe9;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
  }
LAB_14000e22a:
  if (*(ushort *)(param_1 + 0x70) < uVar10) {
    *(ushort *)(param_1 + 0x70) = uVar10;
  }
  return uVar9;
LAB_14000dfe9:
  uVar9 = 1;
  goto LAB_14000e22a;
}



===== lm_issue_fw_command @ 14000e254 =====

uint lm_issue_fw_command(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  *(short *)(param_1 + 0x32) = *(short *)(param_1 + 0x32) + 1;
  uVar1 = *(ushort *)(param_1 + 0x32);
  if (param_2 == 0x21000000) {
    if ((*(byte *)(param_1 + 1) & 0x40) != 0) {
      uVar5 = 2;
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xbf;
      if ((*(short *)(param_1 + 0xfc) == 0x2231) || (*(short *)(param_1 + 0xfc) == -0x7ef9)) {
        uVar5 = 1;
      }
      goto LAB_14000e2da;
    }
    uVar5 = 1;
  }
  if (param_2 == 0x10000000) {
    uVar5 = 0x100a;
  }
LAB_14000e2da:
  iVar6 = (uint)*(byte *)(param_1 + 0x13b) * 0x2c;
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x4c) + 0x688 + iVar6,uVar5);
  ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar6,uVar1 | param_2);
  iVar3 = 0;
  do {
    uVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x68c + iVar6);
    if ((uint)uVar1 == (uVar2 & 0xffff)) {
      uVar2 = uVar2 & 0xffff0000;
      break;
    }
    mm_stall(1000);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5000);
  uVar4 = 0;
  if (iVar3 != 5000) {
    uVar4 = uVar2;
  }
  return uVar4;
}



===== lm_link_update @ 14000e374 =====

undefined8 lm_link_update(longlong param_1)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  iVar6 = 0;
  do {
    mm_stall(1000);
    uVar3 = lm_phy_get_gp_status(param_1);
    if ((uVar3 & 4) != 0) break;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 500);
  bVar2 = false;
  if (0x300 < (uVar3 & 0x3f00)) {
    bVar2 = false;
    if ((uVar3 & 0x3f00) != 0xd00) {
      bVar2 = true;
    }
  }
  if ((uVar3 & 4) != 0) {
    iVar6 = lm_is_phy_link_up(param_1,1);
    if (iVar6 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      bVar9 = (char)uVar3 < '\0';
      if (bVar9) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
      if ((uVar3 & 0x40) != 0) {
        *(uint *)(param_1 + 0x10) = bVar9 | 2;
      }
      lm_phy_up_init_ext_phy(param_1);
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10060,0);
      if (bVar2) {
        lm_enable_bmac(param_1,0);
      }
      else {
        lm_enable_emac(param_1);
        iVar6 = (*(byte *)(param_1 + 0x138) + 0x20) * 0x400;
        uVar7 = *(uint *)(param_1 + 0xc) & 0xff00;
        uVar4 = ev_lm_reg_read_ind(param_1,iVar6);
        uVar8 = uVar4 & 0xffffffd1 | 2;
        if ((*(uint *)(param_1 + 0xc) & 0x10000) == 0) {
          uVar8 = uVar4 & 0xffffffd1;
        }
        if (uVar7 == 0x100) {
          uVar8 = uVar8 | 0xc;
        }
        else if (uVar7 == 0x200) {
          uVar8 = uVar8 | 4;
        }
        else if (uVar7 == 0x300) {
          uVar8 = uVar8 | 8;
        }
        else if (uVar7 == 0x400) {
          uVar8 = uVar8 | 0x28;
        }
        ev_lm_reg_write_ind(param_1,iVar6,uVar8);
        uVar5 = lm_is_e3(param_1);
        if ((int)uVar5 != 0) {
          lm_program_umac(param_1,uVar7);
        }
      }
      lm_set_link_up(param_1);
      goto LAB_14000e4fe;
    }
  }
  lm_set_link_down(param_1);
LAB_14000e4fe:
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100000;
  lm_update_link_mng(param_1);
  if ((uVar3 & 4) != 0) {
    lm_extract_vntag_info(param_1);
  }
  return 0;
}



===== lm_mread22_ext @ 14000e53c =====

void lm_mread22_ext(longlong param_1,ushort param_2)

{
  lm_write_mdio_cmd(param_1,((uint)param_2 | (*(ushort *)(param_1 + 300) | 0x140) << 5) << 0x10,
                    *(short *)(param_1 + 0x130),0);
  return;
}



===== lm_mread45 @ 14000e568 =====

void lm_mread45(longlong param_1,short param_2,ushort param_3,ushort param_4,ushort param_5)

{
  lm_write_mdio_cmd(param_1,((param_3 | 0x100) << 5 | (uint)param_4) << 0x10 | (uint)param_5,param_2
                    ,1);
  lm_write_mdio_cmd(param_1,((param_3 | 0x160) << 5 | (uint)param_4) << 0x10,param_2,1);
  return;
}



===== lm_mwrite22_ext @ 14000e5e4 =====

void lm_mwrite22_ext(longlong param_1,ushort param_2,ushort param_3)

{
  lm_write_mdio_cmd(param_1,((uint)param_2 | (*(ushort *)(param_1 + 300) | 0x120) << 5) << 0x10 |
                            (uint)param_3,*(short *)(param_1 + 0x130),0);
  return;
}



===== lm_mwrite45 @ 14000e618 =====

void lm_mwrite45(longlong param_1,short param_2,ushort param_3,ushort param_4,ushort param_5,
                ushort param_6)

{
  lm_write_mdio_cmd(param_1,((param_3 | 0x100) << 5 | (uint)param_4) << 0x10 | (uint)param_5,param_2
                    ,1);
  lm_write_mdio_cmd(param_1,(uint)param_6 | ((param_3 | 0x120) << 5 | (uint)param_4) << 0x10,param_2
                    ,1);
  return;
}



===== lm_mwrite45_int2 @ 14000e69c =====

void lm_mwrite45_int2(longlong param_1,ushort param_2,ushort param_3)

{
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,param_2,param_3);
  return;
}



===== lm_phy_8481_get_sigdet @ 14000e6c8 =====

bool lm_phy_8481_get_sigdet(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfffc,0x7c00);
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfffc);
    if ((uVar1 & 0x20) != 0) break;
    mm_stall(10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return iVar2 != 5;
}



===== lm_phy_84833_cmd_hdlr @ 14000e770 =====

void lm_phy_84833_cmd_hdlr(longlong param_1,ushort param_2,ushort *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037,0xa5a5);
  iVar2 = 0;
  iVar3 = 0;
  do {
    sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037);
    if (sVar1 == 0x10) break;
    mm_stall(1000);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 300);
  if (iVar3 < 300) {
    iVar3 = 0;
    do {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,
                  (short)iVar3 + 0x4038,*param_3);
      iVar3 = iVar3 + 1;
      param_3 = param_3 + 1;
    } while (iVar3 < 5);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,param_2);
    do {
      sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037)
      ;
      if ((sVar1 - 4U & 0xfffb) == 0) break;
      mm_stall(1000);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 300);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037,0x80);
  }
  return;
}



===== lm_phy_84858_cmd_hdlr @ 14000e904 =====

void lm_phy_84858_cmd_hdlr(longlong param_1,ushort param_2,ushort *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037);
    if ((sVar1 != 2) && (sVar1 != -0x4445)) break;
    mm_stall(1000);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 300);
  if (iVar2 < 300) {
    iVar2 = 0;
    do {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,
                  (short)iVar2 + 0x4038,*param_3);
      iVar2 = iVar2 + 1;
      param_3 = param_3 + 1;
    } while (iVar2 < 5);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,param_2);
    do {
      sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037)
      ;
      if ((sVar1 - 4U & 0xfffb) == 0) {
        return;
      }
      mm_stall(1000);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 300);
  }
  return;
}



===== lm_phy_848xx_pre_init @ 14000ea5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_phy_848xx_pre_init(longlong param_1,int param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined1 auStackY_58 [32];
  ushort local_28;
  ushort local_26;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  if (param_2 != 0) {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
    iVar3 = 0;
    do {
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
      if ((uVar1 & 0x8000) == 0) break;
      mm_stall(1000);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 500);
    mm_stall(3000000);
  }
  if ((*(ushort *)(param_1 + 0x14e) & 0xc10) == 0) goto LAB_14000ebdf;
  uVar1 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x18c +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar1 = uVar1 & 0xff;
  if (uVar1 != 0) {
    local_26 = uVar1;
    if (*(short *)(param_1 + 0x130) != 0x1200) {
      uVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) +
                                         (*(byte *)(param_1 + 0x13a) + 0x55) * 4);
      if ((uVar2 & 2) == 0) {
        lm_phy_84833_cmd_hdlr(param_1,0x8001,&local_28);
        goto LAB_14000eb8a;
      }
    }
    lm_phy_84858_cmd_hdlr(param_1,0x8001,&local_28);
  }
LAB_14000eb8a:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x401a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x401a,
              uVar1 & 0x7fff);
LAB_14000ebdf:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20,uVar1 | 0x1000);
  return;
}



===== lm_phy_848xx_prg_leds @ 14000ec58 =====

void lm_phy_848xx_prg_leds(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa83b);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa83b,
              uVar1 & 0xfe52 | 0x52);
  if ((*(uint *)(param_1 + 0x44) & 0xf0000) == 0xe0000) {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82c,0x10);
    uVar2 = 0xa82f;
    uVar1 = 0x80;
  }
  else {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82c,0x80);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82f,0x18);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa832,6);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa834,0);
    uVar2 = 0xa8ec;
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa8ec);
    uVar1 = uVar1 | 0x80;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,uVar2,uVar1);
  return;
}



===== lm_phy_8727_ctrl_optical_output @ 14000ee04 =====

void lm_phy_8727_ctrl_optical_output(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
  uVar2 = uVar1 & 0x7fff;
  if (param_2 == 0) {
    uVar2 = uVar1 | 0x8000;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,uVar2);
  return;
}



===== lm_phy_872x_read_sfp_module_eeprom @ 14000ee8c =====

undefined8 lm_phy_872x_read_sfp_module_eeprom(longlong param_1,ushort param_2)

{
  byte bVar1;
  undefined8 uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  sVar3 = *(short *)(param_1 + 0x130);
  if (sVar3 == 0x900) {
    uVar4 = 0x8007;
    uVar5 = 2;
    uVar6 = 0x8002;
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0x8004,0x8007);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8005,0xa101);
    sVar3 = *(short *)(param_1 + 0x130);
  }
  else {
    uVar5 = 0xa001;
    uVar6 = 0x2c0f;
    uVar4 = 0xc820;
  }
  lm_mwrite45(param_1,sVar3,*(ushort *)(param_1 + 300),1,0x8002,uVar5);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8003,param_2);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8000,uVar6);
  uVar6 = 0;
  do {
    bVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8000);
    if ((bVar1 & 0xc) == 4) break;
    mm_stall(100);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 100);
  if (uVar6 < 100) {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,uVar4);
  }
  else {
    uVar2 = 0xffff;
  }
  return uVar2;
}



===== lm_phy_check_sigdet @ 14000f038 =====

bool lm_phy_check_sigdet(longlong param_1)

{
  short sVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  int iVar4;
  bool bVar5;
  
  bVar5 = false;
  uVar2 = lm_acquire_mdio_hw_lock(param_1,1);
  if ((int)uVar2 == 0) {
    sVar1 = *(short *)(param_1 + 0x130);
    if (sVar1 == 0x700) {
      iVar4 = 0;
      do {
        bVar5 = lm_phy_8481_get_sigdet(param_1);
        if ((int)CONCAT71(extraout_var,bVar5) != 0) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 100);
      bVar5 = false;
      if (iVar4 != 100) {
        bVar5 = true;
      }
    }
    else if (sVar1 == 0x900) {
      iVar4 = 0;
      do {
        uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca40);
        if ((uVar3 & 4) == 0) break;
        mm_stall(1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
      bVar5 = iVar4 != 5;
    }
    else if ((sVar1 != 0xe00) || (uVar2 = lm_phy_ieee_get_sigdet(param_1), (int)uVar2 != 0)) {
      bVar5 = true;
    }
    lm_release_mdio_hw_lock(param_1);
  }
  else {
    bVar5 = false;
  }
  return bVar5;
}



===== lm_phy_cx4_get_sigdet @ 14000f118 =====

bool lm_phy_cx4_get_sigdet(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x80b0);
    if ((uVar1 & 0x8000) != 0) break;
    mm_stall(100);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1000);
  return iVar2 != 1000;
}



===== lm_phy_force_unicore_speed @ 14000f188 =====

void lm_phy_force_unicore_speed(longlong param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
     ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x1000000)) {
    lm_mwrite45_int2(param_1,0x8345,0xc000);
    lm_warpcore_clear_configs(param_1);
    if ((param_2 & 0xff00) == 0x600) {
      lm_phy_warpcore_set_10G_XFI(param_1,1);
    }
    else {
      lm_phy_warpcore_set_sgmii(param_1,1);
    }
    lm_mwrite45_int2(param_1,0x8345,0);
    if ((param_2 & 0xff00) == 0x600) {
      return;
    }
    uVar3 = 0xffe0;
    uVar1 = 0x1200;
    goto LAB_14000f2f9;
  }
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
  uVar1 = uVar1 & 0xffe0;
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  uVar4 = param_2 & 0xff00;
  uVar3 = uVar2 | 1;
  if (uVar4 == 0x100) {
    uVar3 = 0;
LAB_14000f2d0:
    lm_mwrite45_int2(param_1,0xffe0,uVar3);
    uVar3 = uVar2 & 0xfffe;
  }
  else {
    if (uVar4 == 0x200) {
      uVar3 = 0x2000;
      goto LAB_14000f2d0;
    }
    if (uVar4 == 0x300) {
      uVar3 = 0x40;
      goto LAB_14000f2d0;
    }
    if (uVar4 == 0x400) {
      uVar1 = uVar1 | 0x10;
    }
    else if (uVar4 == 0x600) {
      uVar1 = uVar1 | 0x14;
    }
  }
  lm_mwrite45_int2(param_1,0x8300,uVar3);
  uVar3 = 0x8308;
LAB_14000f2f9:
  lm_mwrite45_int2(param_1,uVar3,uVar1);
  return;
}



===== lm_phy_get_gp_status @ 14000f320 =====

void lm_phy_get_gp_status(longlong param_1)

{
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x812b);
    return;
  }
  lm_phy_warpcore_get_gp_status(param_1);
  return;
}



===== lm_phy_get_ieee_link_status @ 14000f358 =====

undefined8 lm_phy_get_ieee_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  lm_mread22_ext(param_1,1);
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar2) {
      return 0;
    }
    mm_stall(1000);
    uVar1 = lm_mread22_ext(param_1,1);
    if ((uVar1 & 4) != 0) break;
    uVar2 = uVar2 + 1;
  }
  return 1;
}



===== lm_phy_get_mii_link_status @ 14000f3c0 =====

undefined8 lm_phy_get_mii_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      mm_stall(1000);
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe1);
      if ((uVar1 & 4) != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== lm_phy_get_pma_link_status @ 14000f43c =====

undefined8 lm_phy_get_pma_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      mm_stall(1000);
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,1);
      if ((uVar1 & 4) != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== lm_phy_get_shmem_link_status @ 14000f4b0 =====

uint lm_phy_get_shmem_link_status(longlong param_1)

{
  uint uVar1;
  
  uVar1 = ev_lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 0x10 +
                                     *(int *)(param_1 + 0x4c) + 0x664);
  return uVar1 & 1;
}



===== lm_phy_get_sigdet @ 14000f4d8 =====

uint lm_phy_get_sigdet(longlong param_1)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  int iVar6;
  
  uVar4 = 0;
  uVar5 = lm_acquire_mdio_hw_lock(param_1,1);
  if ((int)uVar5 != 0) {
    return 0;
  }
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    if ((*(byte *)(param_1 + 0x14e) & 0x20) != 0) {
      if ((((*(byte *)(param_1 + 1) & 1) == 0) &&
          (uVar4 = *(uint *)(param_1 + 0x148) & 0xf000000, (uVar4 - 0x1000000 & 0xfcffffff) == 0))
         && (uVar4 != 0x4000000)) {
        if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
           (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
          uVar3 = lm_phy_warpcore_get_gp_status(param_1);
          uVar4 = (uint)uVar3;
        }
      }
      else {
        bVar2 = lm_phy_wc_get_sigdet(param_1);
        uVar4 = (uint)CONCAT71(extraout_var_00,bVar2);
      }
    }
    goto LAB_14000f6de;
  }
  if (((sVar1 != 0x300) && (sVar1 != 0x400)) && (sVar1 != 0x500)) {
    if (sVar1 == 0x600) {
      iVar6 = 0;
      do {
        uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc804);
        if ((uVar3 & 0x6060) == 0x60) break;
        mm_stall(10);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 10);
      uVar4 = (uint)(iVar6 != 10);
      goto LAB_14000f6de;
    }
    if (sVar1 == 0x700) {
      if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
         (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
        }
        bVar2 = lm_phy_8481_get_sigdet(param_1);
        uVar4 = (uint)CONCAT71(extraout_var,bVar2);
      }
      goto LAB_14000f6de;
    }
    if (((sVar1 != 0x800) && (sVar1 != 0x900)) && (sVar1 == 0xe00)) {
      if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
         (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
        }
        uVar5 = lm_phy_ieee_get_sigdet(param_1);
        uVar4 = (uint)uVar5;
      }
      goto LAB_14000f6de;
    }
  }
  uVar4 = 1;
LAB_14000f6de:
  lm_release_mdio_hw_lock(param_1);
  return uVar4;
}



===== lm_phy_get_warpcore_lane @ 14000f704 =====

char lm_phy_get_warpcore_lane(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  
  bVar3 = *(byte *)(param_1 + 0x139);
  bVar5 = *(byte *)(param_1 + 0x138);
  if (*(char *)(param_1 + 0x158) == '\0') {
    uVar2 = ev_lm_reg_read_ind(param_1,0xa738);
    if ((uVar2 & 1) == 0) {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa75c);
    }
    else {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa738);
      uVar1 = uVar1 & 2;
    }
    bVar6 = bVar3 ^ 1;
    if (uVar1 == 0) {
      bVar6 = bVar3;
    }
    uVar2 = ev_lm_reg_read_ind(param_1,0xa734);
    if ((uVar2 & 1) == 0) {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa754);
    }
    else {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa734);
      uVar1 = uVar1 & 2;
    }
    bVar3 = bVar5 ^ 1;
    if (uVar1 == 0) {
      bVar3 = bVar5;
    }
    cVar4 = bVar3 * '\x02' + bVar6;
  }
  else {
    uVar2 = ev_lm_reg_read_ind(param_1,0xa72c);
    if ((uVar2 & 1) == 0) {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa758);
    }
    else {
      uVar1 = ev_lm_reg_read_ind(param_1,0xa72c);
      uVar1 = uVar1 & 2;
    }
    bVar5 = bVar3 ^ 1;
    if (uVar1 == 0) {
      bVar5 = bVar3;
    }
    cVar4 = bVar5 * '\x02';
  }
  return cVar4;
}



===== lm_phy_ieee_get_sigdet @ 14000f804 =====

undefined8 lm_phy_ieee_get_sigdet(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  
  lm_mwrite22_ext(param_1,0x1c,0x7c00);
  iVar2 = 0;
  do {
    uVar1 = lm_mread22_ext(param_1,0x1c);
    if ((uVar1 & 0x20) != 0) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return 0;
}



===== lm_phy_init_link_part2 @ 14000f850 =====

void lm_phy_init_link_part2(longlong param_1)

{
  uint uVar1;
  
  uVar1 = lm_get_link_speed(param_1);
  *(uint *)(param_1 + 0xc) = uVar1;
  if (*(short *)(param_1 + 0x130) != 0) {
    lm_phy_force_unicore_speed(param_1,uVar1);
  }
  lm_link_update(param_1);
  return;
}



===== lm_phy_initialize_link @ 14000f884 =====

void lm_phy_initialize_link(longlong param_1,uint param_2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  bVar8 = *(byte *)(param_1 + 0x138);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffefffff;
  bVar2 = false;
  *(undefined4 *)(param_1 + 4) = 5;
  lm_update_link_mng(param_1);
  if (((*(ushort *)(param_1 + 0x14e) & 0x100) != 0) &&
     (uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b4 + (uint)bVar8 * 400),
     (uVar4 & 0xff00) == 0xfd00)) {
    return;
  }
  if ((param_2 & 0xff) == 0xfb) {
    lm_enable_bmac(param_1,1);
    ev_lm_reg_write_ind(param_1,(uint)bVar8 * 4 + 0x10060,0);
  }
  else {
    uVar6 = lm_acquire_mdio_hw_lock(param_1,1);
    if ((int)uVar6 == 0) {
      if ((((*(short *)(param_1 + 0x130) == 0x300) || (*(short *)(param_1 + 0x130) == 0x900)) &&
          (lm_bcm8073_load_spi_rom(param_1), *(short *)(param_1 + 0x130) == 0x300)) &&
         ((*(uint *)(param_1 + 0x134) & 0x10000) != 0)) {
        uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),1,0xcd08);
        lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xcd08,
                    uVar3 | 0x600);
      }
      if (((*(uint *)(param_1 + 0x148) & 0x100000) != 0) && (*(short *)(param_1 + 0x130) == 0x300))
      {
        uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),7,0x8350);
        lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8350,
                    uVar3 | 3);
      }
      iVar5 = lm_phy_reinit_required(param_1);
      *(uint *)(param_1 + 8) = (iVar5 != 0) + 4;
      if (iVar5 != 0) {
        lm_reset_ext_phy(param_1);
      }
      if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
         ((iVar5 != 0 || (*(short *)(param_1 + 0x130) != 0)))) {
        lm_phy_warpcore_config_init(param_1);
      }
      lm_phy_unicore_config_init(param_1,param_2);
      if (iVar5 == 0) {
        bVar8 = *(byte *)(param_1 + 1);
        if ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x5000000) {
          bVar8 = bVar8 | 0x40;
          *(byte *)(param_1 + 1) = bVar8;
        }
        sVar1 = *(short *)(param_1 + 0x130);
        if (sVar1 == 0x600) {
          *(byte *)(param_1 + 1) = bVar8 | 4;
        }
        else if ((sVar1 == 0x700) || (sVar1 == 0xe00)) {
          *(byte *)(param_1 + 1) = bVar8 | 1;
        }
      }
      if (((((*(byte *)(param_1 + 1) & 1) == 0) || (iVar5 != 0)) || ((param_2 & 0xff) == 0xf7)) &&
         (*(short *)(param_1 + 0x130) != 0)) {
        lm_init_ext_phy(param_1);
      }
      if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) && (iVar5 != 0)) {
        lm_phy_warpcore_config_runtime(param_1);
        uVar7 = lm_phy_get_gp_status(param_1);
        if (((uVar7 & 4) == 0) && ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x5000000)) {
          uVar6 = lm_phy_warpcore_check_KR2_wa(param_1);
          if ((short)uVar6 != 0) {
            lm_phy_warpcore_reset_KR2_cfg(param_1);
          }
          lm_phy_warpcore_config_runtime(param_1);
        }
      }
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
      if ((*(byte *)(param_1 + 1) & 2) == 0) {
        iVar5 = 1;
        while (((iVar5 = lm_is_phy_link_up(param_1,iVar5), iVar5 != 0 &&
                (lm_phy_init_link_part2(param_1), !bVar2)) && (*(int *)(param_1 + 4) != 4))) {
          bVar2 = true;
          iVar5 = 0;
        }
      }
      lm_release_mdio_hw_lock(param_1);
    }
  }
  return;
}



===== lm_phy_program_serdes @ 14000fba0 =====

void lm_phy_program_serdes(longlong param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
  uVar2 = uVar1 & 0xeeff | 0x100;
  if ((param_2 & 0x10000) != 0) {
    uVar2 = uVar1 & 0xeeff;
  }
  lm_mwrite45_int2(param_1,0xffe0,uVar2);
  if (0x300 < (param_2 & 0xff00)) {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
    uVar2 = uVar1 & 0xfff0 | 0x6014;
    if ((param_2 & 0xff00) != 0x600) {
      uVar2 = uVar1 & 0xfff0 | 0x6010;
    }
    lm_mwrite45_int2(param_1,0x8308,uVar2);
  }
  return;
}



===== lm_phy_reinit_required @ 14000fc70 =====

undefined4 lm_phy_reinit_required(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,2);
  uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,3);
  sVar4 = *(short *)(param_1 + 0x130);
  uVar7 = uVar3 & 0xfff0 | (uint)uVar2 << 0x10;
  if (sVar4 == 0) {
    if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
      return 1;
    }
    if ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000) {
      uVar3 = 0xa0;
      uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x11);
      if (*(short *)(param_1 + 0xfc) == -0x7ef9) {
        uVar7 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                           (uint)*(byte *)(param_1 + 0x138) * 400);
        uVar3 = (ushort)(uVar7 >> 0xf) & 0xfffe;
      }
      if ((uVar2 & 0xa0) != uVar3) {
        return 1;
      }
    }
    uVar6 = lm_phy_get_gp_status(param_1);
    if ((uVar6 & 4) == 0) {
      return 1;
    }
    if (((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) != 0) {
      return 0;
    }
    uVar7 = lm_get_link_speed(param_1);
    if ((uVar7 & 0xff00) == 0x300) {
      return 1;
    }
    return 0;
  }
  if (sVar4 == 0x300) {
    bVar1 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),7,0x11);
    if ((bVar1 & 0x80 | 0x20) != 0xa0) {
      return 1;
    }
    bVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329);
    if ((bVar1 & 1) == 0) {
      return 1;
    }
  }
  else {
    if (((sVar4 - 0x400U & 0xfcff) == 0) && (sVar4 != 0x700)) {
      return 1;
    }
    if (sVar4 == 0x700) {
      if (((uVar7 != 0x205c60) && (uVar7 != 0x3625cb0)) && (uVar7 != 0x3625c30)) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),1,0);
      if ((uVar2 & 0x8000) != 0) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe9);
      if ((uVar2 & 0x200) == 0) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4);
      if ((uVar2 & 0x140) != 0x140) {
        return 1;
      }
      sVar4 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0);
      if (sVar4 == 0) {
        return 1;
      }
      iVar8 = 0;
      do {
        uVar5 = lm_phy_get_mii_link_status(param_1,10);
        if ((int)uVar5 == 0) break;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 5);
      goto LAB_14000ffe4;
    }
    if (sVar4 != 0x900) {
      if (sVar4 != 0xe00) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,2);
      uVar7 = lm_mread22_ext(param_1,3);
      if ((uVar7 & 0xfff0 | (uint)uVar2 << 0x10) != 0x3625d10) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,0);
      if ((uVar2 & 0x1000) == 0) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,4);
      if ((uVar2 & 0x1e0) != 0x1e0) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,9);
      if ((uVar2 & 0x300) != 0x300) {
        return 1;
      }
      uVar5 = lm_phy_get_ieee_link_status(param_1,5);
      if ((int)uVar5 == 0) {
        return 1;
      }
      return 0;
    }
    uVar2 = 0xd;
    bVar9 = (*(uint *)(param_1 + 0x18c) & 0xff00) != 0x300;
    if (bVar9) {
      uVar2 = 8;
    }
    uVar3 = 0x40;
    if (bVar9) {
      uVar3 = 0x2040;
    }
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0,uVar3);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,7,uVar2);
  }
  iVar8 = 0;
  do {
    uVar5 = lm_phy_get_pma_link_status(param_1,400);
    if ((int)uVar5 == 0) break;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
LAB_14000ffe4:
  if (iVar8 == 5) {
    return 0;
  }
  return 1;
}



===== lm_phy_set_aer_mmd @ 1400100e0 =====

void lm_phy_set_aer_mmd(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  
  sVar3 = (ushort)*(byte *)(param_1 + 0x14c) + *(short *)(param_1 + 0x122);
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar2 = lm_is_dual_core(param_1);
    sVar5 = sVar3 + -1;
    if ((int)uVar2 == 0) {
      sVar5 = sVar3;
    }
    uVar4 = sVar5 + 0x3800;
  }
  else {
    bVar1 = lm_phy_get_warpcore_lane(param_1);
    uVar4 = (ushort)bVar1;
    if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
      uVar4 = (ushort)(bVar1 | 0x400) >> 1;
    }
  }
  lm_mwrite45_int2(param_1,0xffde,uVar4);
  return;
}



===== lm_phy_set_autoneg @ 140010158 =====

void lm_phy_set_autoneg(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x18c) & 0xff00;
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
  uVar4 = 0x1000;
  if (*(short *)(param_1 + 0x130) != 0) {
    uVar3 = 0x600;
  }
  uVar2 = uVar1 | 0x1000;
  if (uVar3 != 0) {
    uVar2 = uVar1 & 0xedff;
  }
  lm_mwrite45_int2(param_1,0xffe0,uVar2);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  uVar1 = uVar2 & 0xfffb | 0x10;
  if (uVar3 != 0) {
    uVar1 = uVar2 & 0xffeb;
  }
  lm_mwrite45_int2(param_1,0x8300,uVar1);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8350);
  uVar1 = uVar2 | 3;
  if (uVar3 != 0) {
    uVar1 = uVar2 & 0xfffc;
  }
  lm_mwrite45_int2(param_1,0x8350,uVar1);
  if (*(short *)(param_1 + 0x130) == 0) {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370);
    lm_mwrite45_int2(param_1,0x8370,uVar1 | 2);
    lm_mwrite45_int2(param_1,0x8372,0xe000);
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x11);
    lm_mwrite45_int2(param_1,0x11,uVar1 | 0x60);
  }
  else {
    uVar4 = 0;
  }
  lm_mwrite45_int2(param_1,0,uVar4);
  return;
}



===== lm_phy_set_master_ln @ 140010314 =====

void lm_phy_set_master_ln(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8105);
  lm_mwrite45_int2(param_1,0x8105,*(byte *)(param_1 + 0x14c) | uVar1);
  return;
}



===== lm_phy_toggle_link @ 140010360 =====

void lm_phy_toggle_link(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = lm_acquire_mdio_hw_lock(param_1,1);
  if ((int)uVar4 == 0) {
    sVar1 = *(short *)(param_1 + 0x130);
    if (sVar1 == 0) {
      if ((*(byte *)(param_1 + 0x14e) & 0x20) != 0) {
        uVar3 = *(uint *)(param_1 + 0x148) & 0xf000000;
        if (uVar3 == 0x2000000) {
          lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15e),1);
          mm_stall(1000000);
          lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15e),0);
        }
        else if (uVar3 == 0x3000000) {
          lm_phy_warpcore_transmitter_ctrl(param_1,0);
          mm_stall(1000000);
          lm_phy_warpcore_transmitter_ctrl(param_1,1);
        }
      }
    }
    else if (sVar1 == 0x300) {
      uVar2 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),1,0xca02);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,
                  uVar2 | 0x400);
      mm_stall(1000000);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,
                  uVar2 & 0xfbff);
    }
    else if (sVar1 == 0x900) {
      lm_phy_8727_ctrl_optical_output(param_1,0);
      mm_stall(1000000);
      lm_phy_8727_ctrl_optical_output(param_1,1);
    }
    lm_release_mdio_hw_lock(param_1);
  }
  return;
}



===== lm_phy_unicore_config_init @ 1400104ec =====

void lm_phy_unicore_config_init(longlong param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  ushort *puVar4;
  
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    lm_phy_set_aer_mmd(param_1);
    lm_phy_set_master_ln(param_1);
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
    lm_mwrite45_int2(param_1,0xffe0,uVar1 | 0x8000);
    iVar3 = 0;
    do {
      mm_stall(500);
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
      if ((uVar1 & 0x8000) == 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 1000);
    lm_phy_set_aer_mmd(param_1);
    lm_phy_set_master_ln(param_1);
    if (*(byte *)(param_1 + 0x13f) == 0x1b) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(byte *)(param_1 + 0x13f) | 0xc000;
    }
    lm_mwrite45_int2(param_1,0x8100,uVar1);
    if (*(byte *)(param_1 + 0x140) == 0x1b) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(byte *)(param_1 + 0x140) | 0x8000;
    }
    lm_mwrite45_int2(param_1,0x8101,uVar1);
    if (((*(uint *)(param_1 + 0x58) & 2) != 0) && (*(short *)(param_1 + 0x130) == 0)) {
      iVar3 = 0;
      puVar4 = (ushort *)(param_1 + 0xa4);
      do {
        sVar2 = (short)iVar3 * 0x10;
        lm_mwrite45_int2(param_1,sVar2 + 0x80bc,puVar4[-4]);
        lm_mwrite45_int2(param_1,sVar2 + 0x8067,*puVar4);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
    }
    if (*(short *)(param_1 + 0x130) == 0) {
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
      lm_mwrite45_int2(param_1,0x8301,uVar1 | 1);
      lm_mwrite45_int2(param_1,0x8133,0x16e2);
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8131);
      lm_mwrite45_int2(param_1,0x8131,uVar1 | 1);
      lm_mwrite45_int2(param_1,0x8104,0x11);
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(uint *)(param_1 + 0x18c) & 0xff00) == 0)) {
        lm_mwrite45_int2(param_1,0x8329,0x11);
        lm_mwrite45_int2(param_1,0xffe4,0x1a0);
        lm_phy_set_autoneg(param_1);
        uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0);
        lm_mwrite45_int2(param_1,0,uVar1 | 0x1200);
        return;
      }
    }
    lm_phy_set_autoneg(param_1);
    lm_phy_program_serdes(param_1,param_2);
  }
  return;
}



===== lm_phy_up_init_ext_phy @ 14001079c =====

void lm_phy_up_init_ext_phy(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0x300) {
    if ((*(uint *)(param_1 + 0x134) & 0x10000) == 0) {
      return;
    }
    uVar2 = 4;
    uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),4,0x80fa);
    uVar4 = uVar3 | 8;
    if ((*(uint *)(param_1 + 0xc) & 0xff00) != 0x300) {
      uVar4 = uVar3 & 0xfff7;
    }
    uVar3 = 0x80fa;
  }
  else if ((sVar1 - 0x400U & 0xfeff) == 0) {
    lm_mwrite45(param_1,sVar1,*(ushort *)(param_1 + 300),1,0xca0a,0x8288);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,0x7fbf);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca09,0x100);
    uVar4 = 1;
    uVar3 = 0x9002;
    uVar2 = 2;
  }
  else {
    if (sVar1 == 0x600) {
      lm_bcm8726_set_limiting_mode(param_1);
      return;
    }
    if (sVar1 != 0x800) {
      if (sVar1 == 0x900) {
        lm_phy_8727_ctrl_optical_output(param_1,1);
        return;
      }
      return;
    }
    uVar2 = 1;
    lm_mwrite45(param_1,0x800,*(ushort *)(param_1 + 300),1,0x9002,1);
    uVar4 = 8;
    uVar3 = 0xc007;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),uVar2,uVar3,uVar4);
  return;
}



===== lm_phy_warpcore_KR2_supp @ 140010984 =====

void lm_phy_warpcore_KR2_supp(longlong param_1)

{
  ushort uVar1;
  
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8077,0x2690);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8368);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8368,uVar1 & 0xff3f);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8436,0xa157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8438,0xcbe2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8437,0x7537);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8439,0xa157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843b,0xcbe2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843a,0x7537);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370,10);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8372,0x6400);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8374,0x620);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x837b,0x157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8453,0x6464);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8454,0x3150);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8455,0x3150);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8456,0x157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8457,0x620);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 0x20;
  return;
}



===== lm_phy_warpcore_check_KR2_wa @ 140010c8c =====

undefined8 lm_phy_warpcore_check_KR2_wa(longlong param_1)

{
  short sVar1;
  short sVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    sVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x13);
    sVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x14);
    if ((sVar1 != 0) || (sVar2 != 0)) break;
    mm_stall(200000);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  if ((-1 < sVar1) || (((byte)sVar2 & 0xe0) == 0x20)) {
    uVar3 = 1;
  }
  return uVar3;
}



===== lm_phy_warpcore_config_init @ 140010d44 =====

void lm_phy_warpcore_config_init(longlong param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  
  cVar1 = lm_phy_get_warpcore_lane(param_1);
  *(char *)(param_1 + 0x159) = cVar1;
  ev_lm_reg_write_ind(param_1,0xa9a0,1);
  uVar8 = *(uint *)(param_1 + 0x148);
  lm_phy_set_aer_mmd(param_1);
  lm_mwrite45_int2(param_1,0x8345,0xc000);
  uVar8 = uVar8 & 0xf000000;
  if (uVar8 == 0) {
    lm_phy_warpcore_set_sgmii(param_1,0);
  }
  else if (uVar8 == 0x1000000) {
    lm_phy_warpcore_set_10G_XFI(param_1,1);
  }
  else if (uVar8 == 0x2000000) {
    uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,6);
    if ((uVar5 & 8) != 0) {
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
        lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),1);
      }
      mm_stall(100000);
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
        lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),0);
      }
      mm_stall(40000);
      *(undefined1 *)(param_1 + 0x18d) = 3;
    }
    if ((*(uint *)(param_1 + 0x18c) & 0xff00) == 0x300) {
      lm_warpcore_clear_configs(param_1);
      lm_phy_warpcore_set_sgmii(param_1,1);
    }
    else {
      lm_phy_warpcore_set_10G_XFI(param_1,0);
    }
    iVar9 = 2;
    uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,2);
    if ((uVar5 & 0x21) != 0) {
      uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,8);
      iVar9 = 2;
      if ((uVar5 & 4) != 0) {
        iVar9 = 3;
      }
    }
    bVar6 = *(char *)(param_1 + 0x159) << 2;
    uVar4 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81f2);
    sVar10 = 0;
    if (iVar9 == 3) {
      sVar10 = 2;
    }
    lm_mwrite45_int2(param_1,0x81f2,sVar10 << (bVar6 & 0x1f) | uVar4 & ~(0xf << (bVar6 & 0x1f)));
    lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81f2);
    if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),0);
    }
    lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15e),0);
  }
  else {
    if (uVar8 == 0x3000000) {
      cVar1 = '\0';
    }
    else {
      if (uVar8 != 0x5000000) goto LAB_140010f87;
      cVar1 = '\x01';
    }
    lm_phy_warpcore_set_KR(param_1,cVar1);
  }
LAB_140010f87:
  if ((*(byte *)(param_1 + 0x14e) & 0x20) != 0) {
    iVar9 = 0;
    do {
      uVar7 = (short)iVar9 * 0x10 + 0x80ba;
      uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar7);
      uVar4 = uVar3 | 0xc;
      if ((0x100000 << ((byte)iVar9 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
        uVar4 = uVar3 & 0xfff3;
      }
      lm_mwrite45_int2(param_1,uVar7,uVar4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    iVar9 = 0;
    do {
      uVar7 = (short)iVar9 * 0x10 + 0x8061;
      uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar7);
      uVar4 = uVar3 | 0x20;
      if ((0x10000 << ((byte)iVar9 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
        uVar4 = uVar3 & 0xffdf;
      }
      lm_mwrite45_int2(param_1,uVar7,uVar4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
  }
  uVar4 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833e);
  lm_mwrite45_int2(param_1,0x833e,uVar4 | 8);
  lm_mwrite45_int2(param_1,0x8345,0);
  bVar2 = lm_phy_wc_get_sigdet(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    if (*(short *)(param_1 + 0x60) != 0) {
      *(short *)(param_1 + 0x5e) = *(short *)(param_1 + 0x60);
    }
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 8;
  }
  return;
}



===== lm_phy_warpcore_config_runtime @ 1400110d4 =====

void lm_phy_warpcore_config_runtime(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  
  if (((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) == 0) {
    iVar3 = 0;
    do {
      if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
        lm_mwrite45_int2(param_1,0xffde,(ushort)*(byte *)(param_1 + 0x159));
      }
      lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0,0x1200);
      mm_stall(500000);
      uVar2 = lm_phy_get_gp_status(param_1);
      if ((uVar2 & 4) == 0) {
        lm_mwrite45_int2(param_1,0x8345,0xc000);
        lm_mwrite45_int2(param_1,0x8345,0);
      }
      else {
        uVar1 = lm_get_link_speed(param_1);
        if (((uVar1 & 0xff00) != 0x300) || ((*(byte *)(param_1 + 1) & 0x20) == 0)) break;
        lm_phy_warpcore_reset_KR2_cfg(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
      lm_phy_set_aer_mmd(param_1);
    }
  }
  return;
}



===== lm_phy_warpcore_get_gp_status @ 1400111d0 =====

ushort lm_phy_warpcore_get_gp_status(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  cVar1 = lm_phy_get_warpcore_lane(param_1);
  *(char *)(param_1 + 0x159) = cVar1;
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d1);
  if (*(short *)(param_1 + 0x130) == 0) {
    uVar2 = uVar2 | (uVar2 & 0xff00) << 4;
  }
  mm_stall(5000);
  uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,
                     (*(byte *)(param_1 + 0x159) >> 1) + 0x81d2);
  if ((*(byte *)(param_1 + 0x159) & 1) == 0) {
    uVar3 = uVar3 << 8;
  }
  if ((uVar3 & 0x3f00) == 0x3900) {
    uVar2 = uVar2 | uVar2 << 0xc;
  }
  if ((((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) == 0) &&
     ((uVar2 >> (*(byte *)(param_1 + 0x159) & 0x1f) & 1) == 0)) {
    uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d4);
    uVar2 = uVar2 & 0xf00f;
  }
  if ((*(short *)(param_1 + 0x130) != 0) ||
     ((uVar2 >> ((byte)(*(char *)(param_1 + 0x159) + 0xc) & 0x1f) & 1) != 0)) {
    uVar4 = uVar3 & 0x3f00 | 4;
  }
  return uVar4;
}



===== lm_phy_warpcore_read_sfp_module_eeprom @ 140011320 =====

longlong lm_phy_warpcore_read_sfp_module_eeprom(longlong param_1,byte param_2)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  uint7 extraout_var;
  uint7 extraout_var_00;
  longlong lVar4;
  uint7 uVar5;
  
  uVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x2c);
  uVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x74 +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  lm_ctrl_pin_cfg(param_1,(ushort)uVar2 & 0x3f,(uint)((uVar3 & 0x1000000) != 0));
  lm_ctrl_pin_cfg(param_1,(ushort)(uVar2 >> 6) & 0x3f,(uint)((uVar3 & 0x2000000) != 0));
  ev_lm_reg_write_ind(param_1,0x85900,0x80000000);
  ev_lm_reg_write_ind(param_1,0x85904,param_2 | 0xa00000);
  ev_lm_reg_write_ind(param_1,0x85900,0xa0000000);
  bVar1 = lm_e3_imc_done(param_1,10000);
  uVar5 = extraout_var;
  if (bVar1) {
    ev_lm_reg_write_ind(param_1,0x85900,0x90000001);
    bVar1 = lm_e3_imc_done(param_1,10000);
    uVar5 = extraout_var_00;
    if (bVar1) {
      lVar4 = ev_lm_reg_read_ind(param_1,0x85920);
      return lVar4;
    }
  }
  return (ulonglong)uVar5 << 8;
}



===== lm_phy_warpcore_reset_KR2_cfg @ 140011448 =====

void lm_phy_warpcore_reset_KR2_cfg(longlong param_1)

{
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8436,0x7690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8438,0xe647);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8437,0xc4f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8439,0x7690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843b,0xe647);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843a,0xc4f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370,0xc);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8372,0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8374,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x837b,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8453,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8454,0xaf7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8455,0xaf7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8456,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8457,0);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xdf;
  return;
}



===== lm_phy_warpcore_set_10G_XFI @ 1400116c4 =====

void lm_phy_warpcore_set_10G_XFI(longlong param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x821e);
  lm_mwrite45_int2(param_1,0x821e,uVar1 | 0x8000);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302);
  lm_mwrite45_int2(param_1,0x8302,uVar1 | 1);
  lm_mwrite45_int2(param_1,0,0);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8400);
  lm_mwrite45_int2(param_1,0x8400,uVar1 & 0xfffa);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8402);
  lm_mwrite45_int2(param_1,0x8402,uVar1 | 0x80);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c);
  lm_mwrite45_int2(param_1,0x833c,uVar1 & 0xff7f);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  lm_mwrite45_int2(param_1,0x8300,uVar1 & 0xffee);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
  lm_mwrite45_int2(param_1,0x8301,uVar1 & 0xfffe | 6);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
  lm_mwrite45_int2(param_1,0x8308,uVar1 & 0xffe0 | (-(ushort)(param_2 != 0) & 0xfffc) + 9);
  lm_mwrite45_int2(param_1,0x82e2,(-(ushort)(param_2 != 0) & 0xe4be) + 0x3eb2 | 0x8000);
  lm_mwrite45_int2(param_1,(ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,
                   (-(ushort)(param_2 != 0) & 0xcfd0) + 0x3260);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  lm_mwrite45_int2(param_1,0x8300,uVar1 | 1);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c);
  lm_mwrite45_int2(param_1,0x833c,uVar1 | 0x8080);
  lm_mwrite45_int2(param_1,0,0x100);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302);
  lm_mwrite45_int2(param_1,0x8302,uVar1 & 0xfffe);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x821e);
  lm_mwrite45_int2(param_1,0x821e,uVar1 & 0x7fff);
  return;
}



===== lm_phy_warpcore_set_KR @ 1400119e8 =====

void lm_phy_warpcore_set_KR(longlong param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0,0x7415);
  if (*(short *)(param_1 + 0xfc) == -0x7ef9) {
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    uVar2 = (ushort)(uVar4 >> 0xf) & 0xfffe;
  }
  else {
    uVar2 = 0xa0;
  }
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x11,uVar2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x12,0xc000);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349,uVar2 | 0x100);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8329,0x1f);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,0x2690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e6,0x3f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e8,0x3f0);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349,uVar2 | 0x100);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8329,0x1f);
  if (param_2 == '\0') {
    lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300,0x10);
    lm_mwrite45_int2(param_1,0xffde,0);
    bVar1 = lm_phy_get_warpcore_lane(param_1);
    uVar5 = (ushort)bVar1 * 0x10 + 0x80ba;
    uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar5);
    uVar2 = uVar3 | 0x80c;
    if ((0x100000 << (bVar1 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
      uVar2 = uVar3 & 0xfff3 | 0x800;
    }
    lm_mwrite45_int2(param_1,uVar5,uVar2);
    lm_phy_set_aer_mmd(param_1);
    lm_phy_warpcore_reset_KR2_cfg(param_1);
  }
  else {
    lm_phy_warpcore_KR2_supp(param_1);
  }
  return;
}



===== lm_phy_warpcore_set_sgmii @ 140011d0c =====

void lm_phy_warpcore_set_sgmii(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0);
  lm_mwrite45_int2(param_1,0x83c0,uVar1 & 0x9fff);
  lm_mwrite45_int2(param_1,0xffe0,0x140);
  uVar2 = (-(ushort)(param_2 != 0) & 0xfef1) + 0x110;
  lm_mwrite45_int2(param_1,0x8300,uVar2);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
  lm_mwrite45_int2(param_1,0x8301,uVar1 & 0xfffb);
  lm_mwrite45_int2(param_1,0x8301,uVar1 | 4);
  lm_mwrite45_int2(param_1,0x8300,uVar2 | 0x10);
  return;
}



===== lm_phy_warpcore_transmitter_ctrl @ 140011dfc =====

void lm_phy_warpcore_transmitter_ctrl(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x800e);
  uVar2 = 1 << (*(char *)(param_1 + 0x159) + 0xcU & 0x1f);
  if (param_2 == 0) {
    uVar1 = uVar1 | uVar2;
  }
  else {
    uVar1 = uVar1 & ~uVar2;
  }
  lm_mwrite45_int2(param_1,0x800e,uVar1);
  return;
}



===== lm_phy_wc_get_sigdet @ 140011e6c =====

bool lm_phy_wc_get_sigdet(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d0);
    if ((uVar1 >> ((byte)(*(char *)(param_1 + 0x159) + 8) & 0x1f) & 1) != 0) break;
    mm_stall(100);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1000);
  return iVar2 != 1000;
}



===== lm_program_umac @ 140011ee8 =====

void lm_program_umac(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (uint)*(byte *)(param_1 + 0x138) * 0x400;
  uVar3 = (*(uint *)(param_1 + 0xc) & 0x10000 | 0x40080c00) >> 6;
  if (param_2 == 0x200) {
    uVar3 = uVar3 | 4;
  }
  else if (param_2 == 0x300) {
    uVar3 = uVar3 | 8;
  }
  else if (param_2 == 0x400) {
    uVar3 = uVar3 | 0xc;
  }
  iVar2 = iVar1 + 0x160008;
  ev_lm_reg_write_ind(param_1,iVar2,uVar3);
  mm_stall(0x32);
  ev_lm_reg_write_ind(param_1,iVar2,uVar3 & 0xffffffdf | 3);
  mm_stall(0x32);
  ev_lm_reg_write_ind(param_1,iVar2,uVar3 & 0xffffdfdf | 3);
  ev_lm_reg_write_ind(param_1,iVar1 + 0x160014,0x600);
  return;
}



===== lm_reg_bits_dis @ 140011fb0 =====

void lm_reg_bits_dis(undefined8 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = ev_lm_reg_read_ind(param_1,param_2 + param_3);
  ev_lm_reg_write_ind(param_1,param_2 + param_3,uVar1 & ~param_4);
  return;
}



===== lm_reg_bits_en @ 140011ff0 =====

void lm_reg_bits_en(undefined8 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = ev_lm_reg_read_ind(param_1,param_2 + param_3);
  ev_lm_reg_write_ind(param_1,param_2 + param_3,uVar1 | param_4);
  return;
}



===== lm_release_mdio_hw_lock @ 140012030 =====

void lm_release_mdio_hw_lock(longlong param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x74);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    ev_lm_reg_write_ind(param_1,(uint)*(byte *)(param_1 + 0x13a) * 8 + 0xa510,1);
  }
  return;
}



===== lm_reset_all_devices @ 140012058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_reset_all_devices(longlong param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  uint local_54;
  int local_50;
  longlong local_48;
  uint local_40 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = *(undefined1 *)(param_1 + 0x13b);
  local_40[0] = 0x10000000;
  local_40[1] = 0x11000000;
  local_40[2] = 0x20010000;
  local_40[3] = 0x21000000;
  uVar8 = lm_is_dual_core(param_1);
  if ((int)uVar8 == 0) {
    uVar12 = (-(uint)(((*(uint *)(param_1 + 0x124) & 0xffff0000) + 0xe9b10000 & 0xfffeffff) != 0) &
             0xfffffffa) + 8;
  }
  else {
    uVar12 = 4;
  }
  local_48 = 0;
  local_54 = uVar12;
  do {
    uVar11 = 0;
    local_50 = 0;
    iVar10 = 0;
    lVar13 = local_48;
    do {
      iVar9 = local_50;
      iVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar10);
      if (uVar12 == 2) {
        iVar3 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x44 + iVar9);
        iVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x48 + iVar9);
        if ((iVar3 == -1) && (iVar4 == -1)) {
          iVar2 = 0;
        }
      }
      uVar1 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar10);
      *(undefined2 *)(param_1 + 0x32) = uVar1;
      *(char *)(param_1 + 0x13b) = (char)uVar11;
      if (iVar2 != 0) {
        lm_issue_fw_command(param_1,local_40[lVar13 * 2]);
      }
      uVar11 = uVar11 + 1;
      if ((uVar12 == uVar11) && (local_40[lVar13 * 2] == 0x10000000)) {
        iVar9 = 0x10244;
        uVar12 = 0x1025c;
        do {
          ev_lm_reg_write_ind(param_1,iVar9 + 0xf7dbc,0x1000);
          ev_lm_reg_write_ind(param_1,iVar9,0);
          ev_lm_reg_write_ind(param_1,uVar12,0);
          ev_lm_reg_write_ind(param_1,iVar9 + -0x61e4,0);
          uVar5 = ev_lm_reg_read_ind(param_1,0x108000);
          ev_lm_reg_write_ind(param_1,0x108000,uVar5 & 0xffffffe7);
          uVar5 = ev_lm_reg_read_ind(param_1,0x108004);
          ev_lm_reg_write_ind(param_1,0x108004,uVar5 & 0xffffffe7);
          lm_shutdown_mgmt_to_mcp(param_1);
          ev_lm_reg_write_ind(param_1,0xa588,0xd3ffffff);
          ev_lm_reg_write_ind(param_1,0xa598,0x1403);
          uVar6 = ev_lm_reg_read_ind(param_1,0x10394);
          uVar7 = ev_lm_reg_read_ind(param_1,0x10398);
          ev_lm_reg_write_ind(param_1,0xa584,0x80);
          ev_lm_reg_write_ind(param_1,0x10394,uVar6);
          ev_lm_reg_write_ind(param_1,0x10398,uVar7);
          uVar12 = uVar12 + 0x80;
          iVar9 = iVar9 + 4;
        } while (uVar12 < 0x1035c);
        lVar13 = local_48;
        uVar12 = local_54;
        iVar9 = local_50;
      }
      if (iVar2 != 0) {
        lm_issue_fw_command(param_1,local_40[lVar13 * 2 + 1]);
      }
      local_50 = iVar9 + 400;
      iVar10 = iVar10 + 0x2c;
    } while (uVar11 < uVar12);
    local_48 = lVar13 + 1;
  } while (local_48 < 2);
  *(undefined1 *)(param_1 + 0x13b) = local_58;
  return;
}



===== lm_reset_ext_phy @ 140012330 =====

undefined8 lm_reset_ext_phy(longlong param_1)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = *(short *)(param_1 + 0x130);
  bVar1 = false;
  if (sVar3 == 0x300) goto LAB_14001246c;
  if ((sVar3 - 0x400U & 0xfeff) == 0) {
LAB_1400124a6:
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x02','\x01');
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x01','\0');
    mm_stall(1000);
LAB_14001251e:
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x01','\x01');
  }
  else if (sVar3 == 0x600) {
    sVar3 = lm_mread45(param_1,0x600,*(ushort *)(param_1 + 300),1,0xca1c);
    if (sVar3 != -1) {
      bVar1 = true;
    }
LAB_14001246c:
    if ((*(ushort *)(param_1 + 0x14e) & 0xc1c) == 0) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x02','\x01');
      goto LAB_14001251e;
    }
    if (*(ushort *)(param_1 + 0x15a) == 0) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x03','\x01');
    }
    else if ((*(ushort *)(param_1 + 0x14e) & 0x410) == 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15a),1);
    }
    else {
      ev_lm_reg_read_ind(param_1,0xa490);
    }
    lm_phy_848xx_pre_init(param_1,1);
  }
  else {
    if (sVar3 == 0x700) goto LAB_14001246c;
    if (sVar3 == 0x800) goto LAB_1400124a6;
    if (sVar3 != 0xe00) goto LAB_1400125cb;
    if (*(ushort *)(param_1 + 0x15a) != 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15a),1);
      mm_stall(50000);
    }
    lm_mwrite22_ext(param_1,0,0x8000);
    iVar4 = 0;
    do {
      uVar2 = lm_mread22_ext(param_1,0);
      if ((uVar2 & 0x8000) == 0) break;
      mm_stall(100);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 1000);
    if (*(ushort *)(param_1 + 0x15c) != 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15c),0);
      mm_stall(50000);
    }
  }
  if (!bVar1) {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar2 & 0x8000) == 0) goto LAB_1400125cb;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
  iVar4 = 0;
  do {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar2 & 0x8000) == 0) break;
    mm_stall(100);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10000);
  mm_stall(100000);
LAB_1400125cb:
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100000;
  lm_update_link_mng(param_1);
  return 0;
}



===== lm_retrieve_phy_info @ 1400125f4 =====

void lm_retrieve_phy_info(longlong param_1)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  ev_lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 +
                             *(int *)(param_1 + 0x4c) + 0x1b4);
  uVar2 = ev_lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 +
                                     *(int *)(param_1 + 0x4c) + 0x19c);
  uVar3 = uVar2 & 0xff00;
  if (((uVar3 == 0) || (uVar3 == 0xfd00)) || (uVar3 == 0xff00)) goto LAB_140012774;
  *(ushort *)(param_1 + 0x14e) = *(ushort *)(param_1 + 0x14e) | 4;
  uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x198 +
                                     (uint)*(byte *)(param_1 + 0x138) * 400);
  do {
    lm_get_phy_info(param_1,uVar6);
    if (*(short *)(param_1 + 0x130) == 0x700) {
      lm_reset_ext_phy(param_1);
      uVar5 = uVar6;
      break;
    }
    uVar6 = uVar6 + 1;
    uVar5 = uVar6;
  } while ((int)uVar6 < 2);
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    uVar2 = lm_mread45(param_1,0x700,uVar2 & 0xff,0x1e,0x401a);
    uVar4 = 4 - ((uVar2 & 0x100) != 0);
  }
  if (uVar4 == 1) {
LAB_140012751:
    uVar5 = 0;
  }
  else if (uVar4 == 2) {
LAB_1400127cd:
    uVar5 = 1;
  }
  else if (uVar4 == 3) {
    uVar5 = 0;
    lm_get_phy_info(param_1,0);
    if (*(short *)(param_1 + 0x130) != 0x700) {
      lm_reset_ext_phy(param_1);
    }
    lm_init_ext_phy(param_1);
    bVar1 = lm_phy_check_sigdet(param_1);
    if ((int)CONCAT71(extraout_var_00,bVar1) == 0) goto LAB_1400127cd;
  }
  else if (uVar4 == 4) {
    lm_get_phy_info(param_1,1);
    if (*(short *)(param_1 + 0x130) != 0x700) {
      lm_reset_ext_phy(param_1);
    }
    lm_init_ext_phy(param_1);
    bVar1 = lm_phy_check_sigdet(param_1);
    uVar5 = 1;
    if ((int)CONCAT71(extraout_var,bVar1) == 0) goto LAB_140012751;
  }
  if (*(short *)(param_1 + 0x130) == 0x700) {
    lm_get_phy_info(param_1,uVar5 ^ 1);
    lm_phy_8727_ctrl_optical_output(param_1,0);
  }
LAB_140012774:
  lm_get_phy_info(param_1,uVar5);
  ev_mm_get_user_config(param_1);
  return;
}



===== lm_set_link_down @ 1400127d8 =====

void lm_set_link_down(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  if ((*(uint *)(param_1 + 0x58) & 0x10000) != 0) {
    lm_reg_bits_dis(param_1,0xa000,0x590,1 << (bVar1 & 0x1f));
    uVar3 = -(uint)(bVar1 != 0) & 0x400;
    uVar2 = ev_lm_reg_read_ind(param_1,uVar3 + 0x800c);
    ev_lm_reg_write_ind(param_1,uVar3 + 0x800c,uVar2 | 1);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x102f0,0);
    if (*(short *)(param_1 + 0x130) == 0) {
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10320,0);
    }
  }
  *(undefined4 *)(param_1 + 4) = 5;
  *(undefined1 *)(param_1 + 0xd) = 0;
  return;
}



===== lm_set_link_up @ 140012890 =====

void lm_set_link_up(longlong param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  *(undefined4 *)(param_1 + 4) = 4;
  if ((*(uint *)(param_1 + 0x58) & 0x10000) == 0) {
    uVar4 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 + (uint)bVar1 * 0x10);
    uVar4 = uVar4 & 0x1e;
    if (uVar4 == 0xe) {
      *(undefined1 *)(param_1 + 0xd) = 3;
    }
    else if (uVar4 == 0x14) {
      *(undefined1 *)(param_1 + 0xd) = 6;
    }
    else if (uVar4 == 0x16) {
      *(undefined1 *)(param_1 + 0xd) = 7;
    }
  }
  else {
    iVar6 = (uint)bVar1 * 4 + 0x102f0;
    ev_lm_reg_write_ind(param_1,iVar6,*(ushort *)(param_1 + 0x46) & 0xf);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x102f8,0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10310,0x1e0);
    ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10318,1);
    uVar5 = -(uint)(bVar1 != 0) & 0x400;
    uVar4 = ev_lm_reg_read_ind(param_1,uVar5 + 0x800c);
    ev_lm_reg_write_ind(param_1,uVar5 + 0x800c,uVar4 & 0xfffffffe);
    sVar2 = *(short *)(param_1 + 0x130);
    if (sVar2 == 0) {
      uVar3 = lm_phy_get_gp_status(param_1);
      if ((uVar3 & 0x3f00) == 0xe00) {
        ev_lm_reg_write_ind(param_1,iVar6,0);
        ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10320,1);
      }
    }
    else if (sVar2 == 0x600) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\0','\0');
    }
    else if (sVar2 == 0x700) {
      lm_phy_848xx_prg_leds(param_1);
    }
    else if (sVar2 == 0x900) {
      uVar3 = lm_mread45(param_1,0x900,*(ushort *)(param_1 + 300),1,0xc808);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc808,
                  uVar3 | 0x60);
    }
    uVar4 = lm_get_link_speed(param_1);
    *(uint *)(param_1 + 0xc) = uVar4 | *(uint *)(param_1 + 0xc) & 0xffff00ff;
  }
  return;
}



===== lm_set_mac_addrs @ 140012a80 =====

undefined8 lm_set_mac_addrs(longlong param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  int iVar8;
  undefined4 local_res8;
  
  pcVar4 = *(char **)(param_1 + 0x88);
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  pcVar1 = (char *)(param_1 + 0x192);
  pcVar4[1] = *(char *)(param_1 + 0x13d) << 3;
  pcVar2 = (char *)(param_1 + 0x193);
  uVar5 = *(uint *)(param_1 + 0x172);
  *(uint *)(pcVar4 + 4) =
       (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8 | (uVar5 & 0xff00 | uVar5 << 0x10) << 8;
  bVar7 = 1;
  *(ushort *)(pcVar4 + 8) = *(ushort *)(param_1 + 0x176) << 8 | *(ushort *)(param_1 + 0x176) >> 8;
  *(ushort *)(pcVar4 + 10) = (ushort)*(byte *)(param_1 + 0x13d);
  pcVar4[0xc] = '\0';
  pcVar4[0xd] = '\0';
  pcVar4[0xe] = '\0';
  pcVar4[0xf] = '\0';
  pcVar4[0x10] = '\0';
  pcVar4[0x11] = '\0';
  pcVar4[0x12] = '\0';
  pcVar4[0x13] = '\0';
  if ((*pcVar1 != '\0') || (*pcVar2 != '\0')) {
    local_res8._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 0x194),CONCAT11(*pcVar2,*pcVar1));
    local_res8 = CONCAT13(*(undefined1 *)(param_1 + 0x195),(uint3)local_res8);
    *(uint *)(pcVar4 + 0x14) =
         ((uint3)local_res8 & 0xff0000 | local_res8 >> 0x10) >> 8 |
         ((uint3)local_res8 & 0xff00 | local_res8 << 0x10) << 8;
    bVar7 = 2;
    *(ushort *)(pcVar4 + 0x18) =
         *(ushort *)(param_1 + 0x196) << 8 | *(ushort *)(param_1 + 0x196) >> 8;
    *(ushort *)(pcVar4 + 0x1a) = (ushort)*(byte *)(param_1 + 0x13d);
    pcVar4[0x1c] = '\0';
    pcVar4[0x1d] = '\0';
    pcVar4[0x1e] = '\0';
    pcVar4[0x1f] = '\0';
    pcVar4[0x20] = '\0';
    pcVar4[0x21] = '\0';
    pcVar4[0x22] = '\0';
    pcVar4[0x23] = '\0';
  }
  uVar6 = (ulonglong)bVar7;
  pcVar3 = pcVar4 + uVar6 * 0x10 + 4;
  pcVar3[0] = -1;
  pcVar3[1] = -1;
  pcVar3[2] = -1;
  pcVar3[3] = -1;
  (pcVar4 + uVar6 * 0x10 + 8)[0] = -1;
  (pcVar4 + uVar6 * 0x10 + 8)[1] = -1;
  *(ushort *)(pcVar4 + uVar6 * 0x10 + 10) = (ushort)*(byte *)(param_1 + 0x13d);
  pcVar3 = pcVar4 + uVar6 * 0x10 + 0xc;
  pcVar3[0] = '\x01';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  pcVar3[4] = '\0';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  *pcVar4 = bVar7 + 1;
  lm_sp_post_and_wait(param_1,0x5f,0,*(uint *)(param_1 + 0x94),*(uint *)(param_1 + 0x90));
  if (((*(uint *)(param_1 + 0x58) & 0x20000) != 0) &&
     ((*(short *)(param_1 + 0xec) - 0x500U & 0xfdff) == 0)) {
    iVar8 = 0;
    do {
      everest_init_nig_mac_addr(param_1,iVar8,(undefined1 *)0x0,0);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    everest_init_nig_mac_addr(param_1,0,(undefined1 *)(param_1 + 0x172),1);
    if ((*(char *)(param_1 + 0x116) != '\0') || (iVar8 = 1, *(char *)(param_1 + 0x117) != '\0')) {
      everest_init_nig_mac_addr(param_1,1,(char *)(param_1 + 0x116),1);
      iVar8 = 2;
    }
    if ((*pcVar1 != '\0') || (*pcVar2 != '\0')) {
      everest_init_nig_mac_addr(param_1,iVar8,pcVar1,1);
    }
  }
  return 0;
}



===== lm_set_xumac_nig @ 140012cdc =====

void lm_set_xumac_nig(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x138);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 != 0) {
    ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185ac,param_3);
    ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185b0,param_3);
    ev_lm_reg_write_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185b4,param_2);
  }
  return;
}



===== lm_setup_bd_chain_ring @ 140012d6c =====

void lm_setup_bd_chain_ring(longlong param_1,uint *param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_2[1];
  uVar3 = 0;
  uVar7 = *param_2;
  lVar5 = param_1;
  if (0 < (int)(param_3 - 1)) {
    lVar4 = param_1;
    uVar1 = uVar7;
    do {
      uVar1 = uVar1 + 0x100;
      uVar2 = uVar6 + 1;
      if (uVar7 <= uVar1) {
        uVar2 = uVar6;
      }
      uVar6 = uVar2;
      uVar7 = uVar7 + 0x100;
      *(uint *)(lVar4 + 0xf4) = uVar6;
      lVar5 = lVar4 + 0x100;
      *(uint *)(lVar4 + 0xf0) = uVar7;
      *(longlong *)(lVar4 + 0xf8) = lVar5;
      uVar3 = uVar3 + 1;
      lVar4 = lVar5;
    } while ((int)(uint)uVar3 < (int)(param_3 - 1));
    uVar6 = param_2[1];
  }
  *(uint *)(lVar5 + 0xf4) = uVar6;
  *(uint *)(lVar5 + 0xf0) = *param_2;
  *(longlong *)(lVar5 + 0xf8) = param_1;
  return;
}



===== lm_shutdown @ 140012e00 =====

undefined8 lm_shutdown(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  
  bVar1 = param_1[0x138];
  if ((*param_1 & 2) == 0) {
    *param_1 = *param_1 | 2;
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10244,0);
      if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
        ev_lm_reg_write_ind(param_1,(uint)bVar1 * 0x80 + 0x1025c,0);
      }
      lm_disable_mac((longlong)param_1);
    }
    else {
      ev_lm_reg_write_ind(param_1,0x160fc,0);
      ev_lm_reg_write_ind(param_1,0x16100,0);
      iVar5 = 0;
      do {
        everest_init_nig_mac_addr((longlong)param_1,iVar5,(undefined1 *)0x0,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      lVar6 = 10;
      do {
        lm_flush_rx_buffers((longlong)param_1);
        mm_stall(1000);
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    ev_lm_disable_intr((longlong)param_1);
    lm_sp_post_and_wait((longlong)param_1,0x5a,0,0,0);
    lm_sp_post_and_wait((longlong)param_1,100,0,0,0);
    uVar2 = lm_issue_fw_command((longlong)param_1,
                                (-(uint)((*(uint *)(param_1 + 0x58) & 0x20) != 0) & 0x10000) +
                                0x20010000);
    if (uVar2 != 0x20120000) {
      bVar1 = param_1[0x138];
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x10330,0);
      lm_disable_mac((longlong)param_1);
      ev_lm_reg_write_ind(param_1,0xa5a8,0x1f0 << ((bVar1 & 1) << 4));
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0x108000,0x1000);
      ev_lm_reg_write_ind(param_1,(uint)bVar1 * 4 + 0xa060,0);
      if ((uVar2 == 0x20100000) || ((*(uint *)(param_1 + 0x58) & 1) != 0)) {
        uVar3 = ev_lm_reg_read_ind(param_1,0x10394);
        uVar4 = ev_lm_reg_read_ind(param_1,0x10398);
        uVar2 = *(uint *)(param_1 + 0x58);
        if ((uVar2 & 0xc) == 0) {
          lm_shutdown_mgmt_to_mcp((longlong)param_1);
        }
        ev_lm_reg_write_ind(param_1,0xa588,(-(uint)((uVar2 & 0xc) != 0) & 0xffffff80) + 0xd3ffffff);
        ev_lm_reg_write_ind(param_1,0xa598,0x1403);
        if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
          ev_lm_reg_write_ind(param_1,0xa584,0x80);
        }
        ev_lm_reg_write_ind(param_1,0x10394,uVar3);
        ev_lm_reg_write_ind(param_1,0x10398,uVar4);
      }
    }
    lm_issue_fw_command((longlong)param_1,0x21000000);
    mm_stall(1000);
    ev_lm_reg_write_ind(param_1,0xa45c,0xffffffff);
    iVar5 = ev_lm_reg_read_ind(param_1,0x907c);
    if (iVar5 != 0) {
      ev_lm_reg_write_ind(param_1,38000,iVar5);
    }
    if (param_1[0x13d] < 2) {
      mm_pcicfg_map((longlong)param_1,0);
    }
    storport_pci_cfg_write_dword(param_1,0x78,0);
  }
  return 0;
}



===== lm_shutdown_mgmt_to_mcp @ 1400130b4 =====

void lm_shutdown_mgmt_to_mcp(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = lm_is_e3(param_1);
  if ((int)uVar1 == 0) {
    ev_lm_reg_write_ind(param_1,0x100a4,0);
    ev_lm_reg_write_ind(param_1,0x100a8,0);
    uVar3 = 0x100b0;
    uVar2 = 0x100ac;
  }
  else {
    uVar3 = 0x185c0;
    uVar2 = 0x185ac;
  }
  ev_lm_reg_write_ind(param_1,uVar2,0);
  ev_lm_reg_write_ind(param_1,uVar3,0);
  mm_stall(200000);
  return;
}



===== lm_sp_post_and_wait @ 140013128 =====

bool lm_sp_post_and_wait(longlong param_1,uint param_2,byte param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x6e) = 0;
  if (*(char *)(param_1 + 0x6d8) == '\0') {
    puVar1 = *(uint **)(param_1 + 0x6e0);
    *(undefined1 *)(param_1 + 0x6d8) = 1;
    uVar2 = (uint)*(byte *)(param_1 + 0x138) << 0x17 | (uint)param_3;
    if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
      uVar2 = uVar2 | (uint)*(byte *)(param_1 + 0x13b) << 0x11;
    }
    *puVar1 = param_2 << 0x18 | uVar2;
    puVar1[1] = (uint)(param_2 == 100);
    puVar1[2] = param_5;
    puVar1[3] = param_4;
    *(short *)(param_1 + 0x6e8) = *(short *)(param_1 + 0x6e8) + 1;
    ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xc0),(uint)*(ushort *)(param_1 + 0x6e8));
  }
  iVar3 = 0;
  do {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x200000;
    ev_lm_service_intr(param_1);
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffdfffff;
    if (*(char *)(param_1 + 0x6d8) == '\0') break;
    mm_stall(100);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 1000);
  lm_ack_enable_intr(param_1);
  return param_2 != *(byte *)(param_1 + 0x6e);
}



===== lm_strip_vntag_vlan_hdr @ 14001322c =====

longlong lm_strip_vntag_vlan_hdr(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ushort uVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  uVar4 = *(ushort *)(lVar1 + 0xc) << 8 | *(ushort *)(lVar1 + 0xc) >> 8;
  if (uVar4 == 0x8100) {
    lVar5 = 4;
  }
  else {
    if (uVar4 != 0x8926) {
      return 0;
    }
    lVar5 = 10;
  }
  lVar3 = 0xc;
  lVar2 = lVar5;
  do {
    *(undefined1 *)(lVar2 + 0xb + lVar1) = *(undefined1 *)((lVar1 - lVar5) + 0xc + lVar2 + -1);
    lVar3 = lVar3 + -1;
    lVar2 = lVar2 + -1;
  } while (lVar3 != 0);
  return lVar5;
}



===== lm_update_link_mng @ 140013288 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_update_link_mng(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  ushort local_54;
  ushort local_52;
  undefined2 local_50;
  undefined2 local_4e;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  uVar4 = 0;
  uVar1 = ev_lm_reg_read_ind(param_1,*(undefined4 *)(param_1 + 0x50));
  if ((0x13c < uVar1) &&
     (iVar2 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) +
                                         (*(byte *)(param_1 + 0x138) + 0x4f) * 4), iVar2 != 0)) {
    local_58 = 0x10001;
    if ((*(uint *)(param_1 + 0x18c) >> 0x10 & 1) != 0) {
      local_58 = 0x20002;
    }
    uVar1 = *(uint *)(param_1 + 0x18c) & 0xff00;
    local_54 = *(ushort *)(param_1 + 0x144) & 0x700;
    local_44 = 0x300;
    if (uVar1 == 0x300) {
      local_50 = 1000;
    }
    else if (uVar1 == 0x600) {
      local_50 = 10000;
    }
    else {
      local_50 = 0;
    }
    local_52 = local_54;
    local_4e = local_50;
    uVar1 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                       (uint)*(byte *)(param_1 + 0x138) * 400);
    local_48 = uVar1 & 0xffff0000;
    local_4c = uVar1 & 0xffff0000;
    if ((*(byte *)(param_1 + 0x14e) & 4) == 0) {
      local_52 = 0;
      local_4e = 0;
      local_48 = 0;
    }
    puVar3 = &local_58;
    lVar5 = 6;
    do {
      ev_lm_reg_write_ind(param_1,iVar2,*puVar3);
      iVar2 = iVar2 + 4;
      puVar3 = puVar3 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  if ((*(uint *)(param_1 + 0x58) & 0x100000) != 0) {
    if (*(int *)(param_1 + 4) == 4) {
      uVar1 = *(uint *)(param_1 + 0xc) & 0xff00;
      if (uVar1 == 0x300) {
        uVar4 = 0xf;
      }
      else {
        uVar4 = 0x17;
        if (uVar1 != 0x700) {
          uVar4 = 0x15;
        }
      }
    }
    uVar1 = ev_lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 +
                                       (uint)*(byte *)(param_1 + 0x138) * 0x10);
    if (((uVar1 ^ uVar4) & 1) != 0) {
      ev_lm_reg_write_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 +
                                  (uint)*(byte *)(param_1 + 0x138) * 0x10,uVar4);
      lm_issue_fw_command(param_1,0x1000000);
    }
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffefffff;
  }
  return;
}



===== lm_update_tstorm_rx_indices @ 140013478 =====

void lm_update_tstorm_rx_indices(longlong param_1,undefined2 param_2,undefined2 param_3)

{
  undefined8 uVar1;
  undefined4 local_res10;
  
  local_res10 = CONCAT22(param_3,param_2);
  uVar1 = lm_is_e3(param_1);
  if (((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
      ((*(uint *)(param_1 + 0x58) & 0x20000) == 0)) && (*(byte *)(param_1 + 0x13d) < 2)) {
    storport_pci_cfg_write_dword(param_1,0x8c,local_res10);
    return;
  }
  ev_lm_reg_write_ind(param_1,*(undefined4 *)(param_1 + 0xc4),local_res10);
  return;
}



===== lm_validate_vntag_vlan_hdr @ 1400134dc =====

byte lm_validate_vntag_vlan_hdr(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  byte bVar2;
  
  if ((*(uint *)(param_1 + 0x58) & 0x200) == 0) {
    bVar2 = 0;
    if ((*(uint *)(param_1 + 0x34) & 0xfff) != 0) {
      lVar1 = *(longlong *)(param_2 + 0x38);
      bVar2 = 1;
      if (*(short *)(lVar1 + 0xc) == 0x81) {
        bVar2 = -((((*(short *)(lVar1 + 0xe) << 8 | (ushort)*(byte *)(lVar1 + 0xf)) ^
                   *(ushort *)(param_1 + 0x34)) & 0xfff) != 0) & 1;
      }
    }
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x38);
    bVar2 = 1;
    if (((*(short *)(lVar1 + 0xc) == 0x2689) &&
        (((((*(char *)(param_1 + 0x172) != *(char *)(lVar1 + 6) ||
            (*(char *)(param_1 + 0x173) != *(char *)(lVar1 + 7))) ||
           (*(char *)(param_1 + 0x174) != *(char *)(lVar1 + 8))) ||
          ((*(char *)(param_1 + 0x175) != *(char *)(lVar1 + 9) ||
           (*(char *)(param_1 + 0x176) != *(char *)(lVar1 + 10))))) ||
         (*(char *)(param_1 + 0x177) != *(char *)(lVar1 + 0xb))))) &&
       ((param_3 - 2U < 2 ||
        ((*(ushort *)(param_1 + 0x3c) ==
          (ushort)((*(ushort *)(lVar1 + 0xe) & 0x3f) << 8 | (ushort)*(byte *)(lVar1 + 0xf)) &&
         (*(short *)(lVar1 + 0x12) == 0x81)))))) {
      bVar2 = 0;
    }
  }
  return bVar2;
}



===== lm_warpcore_clear_configs @ 1400135c4 =====

void lm_warpcore_clear_configs(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0,uVar1 | 0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8400,0x14a);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8402,0x800);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c,0x8008);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300,0x195);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301,7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308,0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e2,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,0x990);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0,0x2040);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0,0x140);
  return;
}



===== lm_write_mdio_cmd @ 140013824 =====

uint lm_write_mdio_cmd(longlong param_1,undefined4 param_2,short param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  
  bVar2 = false;
  iVar4 = lm_get_emac_base(param_1,param_3);
  uVar6 = lm_is_e3(param_1);
  if (((int)uVar6 != 0) && ((*(uint *)(param_1 + 0x124) & 0xf000) != 0)) {
    bVar2 = true;
    lm_reg_bits_en(param_1,iVar4,0xb0,2);
  }
  ev_lm_reg_write_ind(param_1,iVar4 + 0xb4,(-(uint)(param_4 != 0) & 0x80000000) + 0x310000);
  iVar1 = iVar4 + 0xac;
  ev_lm_reg_write_ind(param_1,iVar1,param_2);
  iVar7 = 0;
  do {
    mm_stall(10);
    uVar5 = ev_lm_reg_read_ind(param_1,iVar1);
    if ((uVar5 >> 0x1d & 1) == 0) {
      mm_stall(5);
      uVar3 = ev_lm_reg_read_ind(param_1,iVar1);
      uVar5 = (uint)uVar3;
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 50000);
  if (bVar2) {
    lm_reg_bits_dis(param_1,iVar4,0xb0,2);
  }
  return uVar5 & 0xffff;
}



===== dir_get_dir_entry @ 140013934 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 dir_get_dir_entry(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_448 [32];
  undefined8 local_428;
  undefined4 auStack_420 [58];
  uint local_338 [4];
  undefined4 auStack_328 [192];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_448;
  if ((param_2 & 3) == 0) {
    ev_lm_nvram_read_block(param_1,0x14,(longlong)&local_428,0xec);
    iVar5 = 0;
    puVar3 = (uint *)((longlong)&local_428 + 4);
    do {
      if (((*puVar3 & 0x7ffffc) != 0) && ((*puVar3 & 0xf0800003) == param_2)) {
        uVar2 = *(undefined8 *)(auStack_448 + (longlong)iVar5 * 0xc + 0x20);
        uVar1 = auStack_420[(longlong)iVar5 * 3];
        goto LAB_1400139f9;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar5 < 0x10);
  }
  else {
    uVar2 = dir_get_dir_entry(param_1,0xe0000000,param_3);
    uVar4 = 0;
    if (((int)uVar2 == 0) &&
       (ev_lm_nvram_read_block(param_1,*(int *)(param_3 + 1),(longlong)local_338,0x308),
       local_338[0] != 0)) {
      puVar3 = local_338;
      do {
        puVar3 = puVar3 + 3;
        if ((*puVar3 & 0xf0800003) == param_2) {
          uVar2 = *(undefined8 *)(local_338 + (longlong)(int)uVar4 * 3 + 2);
          uVar1 = auStack_328[(longlong)(int)uVar4 * 3];
LAB_1400139f9:
          *param_3 = uVar2;
          *(undefined4 *)(param_3 + 1) = uVar1;
          return 0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_338[0]);
    }
  }
  return 1;
}



===== ev_dir_get_fcoe_block @ 140013a60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ev_dir_get_fcoe_block(undefined1 *param_1,longlong param_2,uint param_3)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  int local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  ev_lm_get_dev_info(param_1);
  uVar1 = dir_get_dir_entry(param_1,*(uint *)(&fcoe_block_dir + (ulonglong)(byte)param_1[0x13c] * 4)
                            ,&local_38);
  if ((int)uVar1 != 1) {
    ev_lm_nvram_read_block(param_1,local_30,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}



===== ev_lm_nvram_read_block @ 140013ad4 =====

undefined8 ev_lm_nvram_read_block(undefined8 param_1,int param_2,longlong param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      uVar1 = ev_lm_nvram_read_dword(param_1,uVar2 + param_2);
      uVar3 = uVar2 + 4;
      *(undefined4 *)(param_3 + (ulonglong)(uVar2 >> 2) * 4) = uVar1;
      uVar2 = uVar3;
    } while (uVar3 < param_4);
  }
  return 0;
}



===== ev_lm_nvram_read_dword @ 140013b3c =====

undefined4 ev_lm_nvram_read_dword(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  ev_lm_reg_write_ind(param_1,0x86420,2);
  uVar6 = 0;
  uVar4 = 0;
  do {
    uVar1 = ev_lm_reg_read_ind(param_1,0x86420);
    if ((uVar1 >> 9 & 1) != 0) break;
    mm_stall(500);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 10000);
  ev_lm_reg_write_ind(param_1,0x86424,3);
  ev_lm_reg_write_ind(param_1,0x8640c,param_2);
  ev_lm_reg_write_ind(param_1,0x86400,0x198);
  iVar5 = 0;
  do {
    uVar3 = ev_lm_reg_read_ind(param_1,0x86400);
    if ((uVar3 & 8) != 0) break;
    mm_stall(5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 10000);
  uVar2 = ev_lm_reg_read_ind(param_1,0x86410);
  ev_lm_reg_write_ind(param_1,0x86424,0);
  ev_lm_reg_write_ind(param_1,0x86420,0x20);
  do {
    uVar4 = ev_lm_reg_read_ind(param_1,0x86420);
    if ((uVar4 >> 9 & 1) == 0) {
      return uVar2;
    }
    mm_stall(5);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 1000);
  return uVar2;
}



===== _guard_dispatch_icall @ 140013c70 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140013c70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 140013c80 =====

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



===== memmove @ 140013d80 =====

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
        if (uVar12 == 0) goto LAB_140013f37;
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
LAB_140013f37:
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
      if (uVar12 == 0) goto LAB_140013d92;
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
LAB_140013d92:
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



===== DriverEntry @ 140022000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(longlong param_1,longlong param_2)

{
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined2 local_6e;
  undefined8 local_68;
  code *local_60;
  code *local_58;
  
  memset(&local_d8,0,0xd0);
  _fcCrashDumpDebugFlags = 0;
  if ((param_1 == 0) && (param_2 == 0xdeadbeef)) {
    DAT_14001e918 = 1;
  }
  _fcb_debug = 0;
  local_d0 = CrashDumpInitialize;
  local_a8 = 0;
  local_c8 = CrashDumpStartIo;
  local_a0 = 0;
  local_c0 = CrashDumpIsr;
  local_90 = 0;
  local_b8 = CrashDumpFindAdapter;
  local_b0 = CrashDumpResetBus;
  local_60 = CrashDumpAdapterControl;
  local_78 = 0;
  local_6e = 0;
  local_68 = 0;
  local_58 = CrashDumpBuildIo;
  local_d8 = 0x88;
  local_98 = 0x158;
  local_80 = 0x1010101;
  local_7c = 0x101;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== get_device_to_d0_if_necessary @ 14002210c =====

undefined8
get_device_to_d0_if_necessary
          (ushort param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 uVar6;
  
  uVar2 = 0;
  uVar1 = read_pci_pfn(param_1,4);
  if ((uVar1 >> 0x14 & 1) != 0) {
    uVar1 = read_pci_pfn(param_1,0x34);
    while( true ) {
      uVar5 = uVar1 & 0xff;
      if (uVar5 < 0x40) break;
      uVar1 = read_pci_pfn(param_1,(char)uVar1);
      if ((char)uVar1 == '\x01') {
        param_3 = (ulonglong)uVar5;
        kd_print("PCI CAP %02x found at %04x\n",1,param_3,param_4);
        uVar2 = uVar5;
        break;
      }
      uVar1 = uVar1 >> 8;
    }
    if (uVar2 != 0) {
      uVar3 = (ulonglong)(uVar2 + 4);
      kd_print("pm_csr at offset %x\n",uVar3,param_3,param_4);
      uVar6 = (undefined1)(uVar2 + 4);
      uVar4 = CONCAT71((int7)(uVar3 >> 8),uVar6);
      uVar2 = read_pci_pfn(param_1,uVar6);
      if ((uVar2 & 3) != 0) {
        kd_print("Base function appeared to be powered down, power it up\n",uVar4,param_3,param_4);
        write_pci_pfn(param_1,uVar6,uVar2 & 0xfffffffc);
        StorPortStallExecution(10000);
        uVar2 = read_pci_pfn(param_1,4);
        write_pci_pfn(param_1,4,uVar2 | 0x406);
      }
      return 0;
    }
  }
  return 0xffffffff;
}



===== entry @ 1400221f0 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002221c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140017198) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


