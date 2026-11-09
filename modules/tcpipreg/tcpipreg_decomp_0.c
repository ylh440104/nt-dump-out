
===== TcpipRegStartRegistryKeyNotification @ 140001010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TcpipRegStartRegistryKeyNotification(void)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar3 = 0;
  do {
    if (uVar3 == 0) {
      uVar2 = TcpipRegInitializeGlobalNotification();
      iVar1 = (int)uVar2;
LAB_14000103d:
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    else {
      if (uVar3 == 1) {
        uVar2 = TcpipRegInitializeInterfaceNotificationTable();
        iVar1 = (int)uVar2;
        goto LAB_14000103d;
      }
      if (uVar3 == 2) {
        iVar1 = TcpipRegInitializePersistentRoutesNotification();
        goto LAB_14000103d;
      }
    }
    uVar3 = uVar3 + 1;
    if (2 < uVar3) {
      _TcpipRegInitializedFlags = _TcpipRegInitializedFlags | 4;
      return iVar1;
    }
  } while( true );
}



===== InterfaceAddressRegKeyChangeHandler @ 140001070 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InterfaceAddressRegKeyChangeHandler
                    (longlong param_1,longlong param_2,undefined8 *param_3,longlong param_4,
                    longlong param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *_Dst;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  short *psVar10;
  uint uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 auStack_158 [32];
  short *local_138;
  undefined8 *local_130;
  longlong local_128;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined8 local_fc;
  undefined4 local_f4;
  undefined8 *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 uStack_e0;
  undefined4 uStack_d8;
  undefined4 local_d4;
  longlong local_c8;
  undefined1 local_b8 [12];
  undefined4 local_ac;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined8 local_9c;
  undefined8 *local_90;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_7c;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  uint auStack_60 [2];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_158;
  uVar8 = 0;
  local_c8 = param_5;
  local_130 = param_3;
  memset(local_b8,0,0x50);
  puVar7 = (undefined8 *)0x0;
  local_e8 = 0x10;
  local_f0 = &local_68;
  local_138 = (short *)0x0;
  local_108 = *(undefined8 *)(param_1 + 8);
  _Dst = (undefined8 *)0x0;
  local_100 = *(undefined4 *)(param_1 + 0x10);
  local_68 = 0;
  auStack_60[0] = 0;
  auStack_60[1] = 0;
  local_128 = 0;
  uVar12 = 0;
  local_110 = 0;
  local_fc = 0;
  local_f4 = 0;
  local_e4 = 0;
  uStack_e0._0_4_ = 0;
  uStack_e0._4_4_ = 0;
  uStack_d8 = 0;
  local_d4 = 0;
  local_118 = 0;
  uVar4 = RoReferenceEx();
  if ((char)uVar4 == '\0') {
    return 0xc0000056;
  }
  if (param_5 == 0) {
    puVar6 = local_130;
  }
  else {
    psVar10 = (short *)(param_5 + 0x1c);
    uVar4 = (ulonglong)puVar7 & 0xffffffff;
    if (*psVar10 != 0) {
      do {
        uVar11 = (uint)uVar4;
        uVar2 = RtlIpv4StringToAddressW(psVar10,1,&local_138,auStack_60);
        uVar8 = (ulonglong)uVar2;
        if (((int)uVar2 < 0) || (*local_138 != 0)) break;
        psVar10 = local_138 + 1;
        uVar11 = uVar11 + 1;
        uVar4 = (ulonglong)uVar11;
      } while (*psVar10 != 0);
      if (uVar11 != 0) {
        _Dst = (undefined8 *)MALLOC((ulonglong)uVar11 * 0x30);
        if (_Dst == (undefined8 *)0x0) {
          uVar8 = 0xc000009a;
          goto LAB_140001438;
        }
        memset(_Dst,0,(ulonglong)uVar11 * 0x30);
      }
      puVar7 = (undefined8 *)0x0;
    }
    psVar10 = (short *)(param_5 + 0x1c);
    local_a8 = *(undefined8 *)(param_1 + 8);
    local_a0 = *(undefined4 *)(param_1 + 0x10);
    local_ac = SUB84(puVar7,0);
    local_9c = 0;
    local_84 = 0;
    uStack_78._0_4_ = (undefined4)((ulonglong)puVar7 >> 0x20);
    local_88 = 0x10;
    local_70 = 0x1c;
    local_90 = puVar7;
    local_7c = local_ac;
    uStack_78._4_4_ = local_ac;
    puVar5 = QueryCurrentState(0x14000d048,param_2);
    puVar6 = local_130;
    uVar12 = (ulonglong)puVar7 & 0xffffffff;
    uStack_78 = (undefined8 *)CONCAT44(uStack_78._4_4_,(undefined4)uStack_78);
    if (*psVar10 != 0) {
      puVar9 = (undefined8 *)((longlong)puVar5 + 0x1c);
      uStack_78 = (undefined8 *)CONCAT44(uStack_78._4_4_,(undefined4)uStack_78);
      if (puVar5 == (undefined8 *)0x0) {
        puVar9 = puVar7;
        uStack_78 = (undefined8 *)CONCAT44(uStack_78._4_4_,(undefined4)uStack_78);
      }
      do {
        uVar2 = RtlIpv4StringToAddressW(psVar10,1,&local_138,auStack_60);
        uVar8 = (ulonglong)uVar2;
        if (((int)uVar2 < 0) || (*local_138 != 0)) break;
        psVar10 = local_138;
        iVar3 = Ipv4AddressType(auStack_60);
        if (iVar3 == 1) {
          puVar5 = _Dst + uVar12 * 6;
          puVar7 = puVar5 + 2;
          *puVar5 = *puVar6;
          *(uint *)(puVar5 + 1) = auStack_60[0];
          lVar1 = TcpipRegNaProviderContext;
          *puVar7 = 0xffffffffffffffff;
          *(undefined4 *)(puVar5 + 3) = 0x10;
          *(undefined4 *)((longlong)puVar5 + 0x1c) = 0x10;
          *(undefined2 *)(puVar5 + 4) = 0xffff;
          *(undefined4 *)((longlong)puVar5 + 0x24) = 0xffffffff;
          *(undefined2 *)(puVar5 + 5) = 0xffff;
          local_130 = puVar5;
          local_90 = puVar5;
          uStack_78 = puVar7;
          iVar3 = (**(code **)(*(longlong *)(lVar1 + 8) + 0x10))(local_b8);
          if (iVar3 < 0) {
            *puVar7 = 0xffffffffffffffff;
            *(undefined4 *)(puVar5 + 3) = 0x10;
            *(undefined4 *)((longlong)puVar5 + 0x1c) = 0x10;
            *(undefined2 *)(puVar5 + 4) = 0xffff;
            *(undefined4 *)((longlong)puVar5 + 0x24) = 0xffffffff;
            *(undefined2 *)(puVar5 + 5) = 0xffff;
          }
          uVar4 = GetCurrentPrefixLength((longlong)puVar9,(byte *)(local_130 + 4));
          uVar8 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            puVar9 = (undefined8 *)(local_128 + 2);
          }
          uVar12 = (ulonglong)((int)uVar12 + 1);
          psVar10 = local_138;
        }
        psVar10 = psVar10 + 1;
      } while (*psVar10 != 0);
    }
  }
  if (param_4 != 0) {
    psVar10 = (short *)(param_4 + 0x1c);
    local_f4 = 3;
    if (*psVar10 != 0) {
      do {
        local_68 = *puVar6;
        auStack_60[0] = 0;
        auStack_60[1] = 0;
        uVar2 = RtlIpv4StringToAddressW(psVar10,1,&local_138,auStack_60);
        uVar8 = (ulonglong)uVar2;
        if (((int)uVar2 < 0) || (*local_138 != 0)) break;
        uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x28))(&local_118);
        uVar8 = (ulonglong)uVar2;
        psVar10 = local_138 + 1;
      } while (*psVar10 != 0);
      param_5 = local_c8;
    }
  }
  uStack_e0 = (undefined8 *)CONCAT44(uStack_e0._4_4_,(undefined4)uStack_e0);
  if (param_5 != 0) {
    local_f4 = 2;
    local_e8 = 0x10;
    uStack_d8 = 0x1c;
    uStack_e0 = (undefined8 *)CONCAT44(uStack_e0._4_4_,(undefined4)uStack_e0);
    if ((int)uVar12 != 0) {
      puVar7 = _Dst;
      do {
        uStack_e0 = puVar7 + 2;
        local_f0 = puVar7;
        uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x28))(&local_118);
        puVar7 = puVar7 + 6;
        uVar8 = (ulonglong)uVar2;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
  }
  if (_Dst != (undefined8 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140001438:
  LOCK();
  iVar3 = TcpipRegNaProviderReference + -2;
  UNLOCK();
  bVar13 = TcpipRegNaProviderReference == 3;
  TcpipRegNaProviderReference = iVar3;
  if (bVar13) {
    NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
  }
  return uVar8;
}



===== TcpipRegStartInterfaceNotification @ 140001490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TcpipRegStartInterfaceNotification(void)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined *local_50;
  ulonglong local_48;
  code *local_40;
  undefined1 local_38;
  undefined4 local_37;
  undefined2 local_33;
  undefined1 local_31;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 *local_18;
  
  local_60 = 0;
  local_31 = 0;
  local_54 = 0;
  DAT_14000df18 = &InterfaceListHead;
  InterfaceListHead = &InterfaceListHead;
  local_48 = (ulonglong)(uint)local_48;
  local_37 = 0;
  local_33 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeSpinLock(&InterfaceListLock);
  DAT_14000df28 = 0;
  _DAT_14000d040 = &DAT_14000d038;
  DAT_14000d038 = &DAT_14000d038;
  _DAT_14000d088 = &DAT_14000d080;
  _DAT_14000d080 = &DAT_14000d080;
  _DAT_14000d0d0 = &DAT_14000d0c8;
  _DAT_14000d0c8 = &DAT_14000d0c8;
  _DAT_14000d118 = &DAT_14000d110;
  _DAT_14000d110 = &DAT_14000d110;
  _DAT_14000d160 = &DAT_14000d158;
  _DAT_14000d158 = &DAT_14000d158;
  _DAT_14000d1a8 = &DAT_14000d1a0;
  _DAT_14000d1a0 = &DAT_14000d1a0;
  _DAT_14000d1f0 = &DAT_14000d1e8;
  _DAT_14000d1e8 = &DAT_14000d1e8;
  _DAT_14000d238 = &DAT_14000d230;
  _DAT_14000d230 = &DAT_14000d230;
  _DAT_14000d280 = &DAT_14000d278;
  _DAT_14000d278 = &DAT_14000d278;
  _DAT_14000d2c8 = &DAT_14000d2c0;
  _DAT_14000d2c0 = &DAT_14000d2c0;
  _DAT_14000d310 = &DAT_14000d308;
  _DAT_14000d308 = &DAT_14000d308;
  _DAT_14000d358 = &DAT_14000d350;
  _DAT_14000d350 = &DAT_14000d350;
  _DAT_14000d3a0 = &DAT_14000d398;
  _DAT_14000d398 = &DAT_14000d398;
  _DAT_14000d3e8 = &DAT_14000d3e0;
  _DAT_14000d3e0 = &DAT_14000d3e0;
  _DAT_14000d430 = &DAT_14000d428;
  _DAT_14000d428 = &DAT_14000d428;
  _DAT_14000d478 = &DAT_14000d470;
  _DAT_14000d470 = &DAT_14000d470;
  _DAT_14000d4c0 = &DAT_14000d4b8;
  _DAT_14000d4b8 = &DAT_14000d4b8;
  _DAT_14000d508 = &DAT_14000d500;
  _DAT_14000d500 = &DAT_14000d500;
  _DAT_14000d550 = &DAT_14000d548;
  _DAT_14000d548 = &DAT_14000d548;
  _DAT_14000d598 = &DAT_14000d590;
  _DAT_14000d590 = &DAT_14000d590;
  _DAT_14000d5e0 = &DAT_14000d5d8;
  _DAT_14000d5d8 = &DAT_14000d5d8;
  _DAT_14000d628 = &DAT_14000d620;
  _DAT_14000d620 = &DAT_14000d620;
  local_68 = &NPI_MS_IPV4_MODULEID;
  _DAT_14000d670 = &DAT_14000d668;
  _DAT_14000d668 = &DAT_14000d668;
  _DAT_14000d6b8 = &DAT_14000d6b0;
  _DAT_14000d6b0 = &DAT_14000d6b0;
  _DAT_14000d700 = &DAT_14000d6f8;
  _DAT_14000d6f8 = &DAT_14000d6f8;
  _DAT_14000d748 = &DAT_14000d740;
  _DAT_14000d740 = &DAT_14000d740;
  _DAT_14000d790 = &DAT_14000d788;
  _DAT_14000d788 = &DAT_14000d788;
  _DAT_14000d7d8 = &DAT_14000d7d0;
  _DAT_14000d7d0 = &DAT_14000d7d0;
  _DAT_14000d820 = &DAT_14000d818;
  _DAT_14000d818 = &DAT_14000d818;
  _DAT_14000d868 = &DAT_14000d860;
  _DAT_14000d860 = &DAT_14000d860;
  _DAT_14000d8b0 = &DAT_14000d8a8;
  _DAT_14000d8a8 = &DAT_14000d8a8;
  _DAT_14000d8f8 = &DAT_14000d8f0;
  _DAT_14000d8f0 = &DAT_14000d8f0;
  _DAT_14000d940 = &DAT_14000d938;
  _DAT_14000d938 = &DAT_14000d938;
  _DAT_14000d988 = &DAT_14000d980;
  _DAT_14000d980 = &DAT_14000d980;
  _DAT_14000d9d0 = &DAT_14000d9c8;
  _DAT_14000d9c8 = &DAT_14000d9c8;
  _DAT_14000da18 = &DAT_14000da10;
  _DAT_14000da10 = &DAT_14000da10;
  _DAT_14000da60 = &DAT_14000da58;
  _DAT_14000da58 = &DAT_14000da58;
  _DAT_14000daa8 = &DAT_14000daa0;
  _DAT_14000daa0 = &DAT_14000daa0;
  _DAT_14000daf0 = &DAT_14000dae8;
  _DAT_14000dae8 = &DAT_14000dae8;
  _DAT_14000db38 = &DAT_14000db30;
  _DAT_14000db30 = &DAT_14000db30;
  _DAT_14000db80 = &DAT_14000db78;
  _DAT_14000db78 = &DAT_14000db78;
  _DAT_14000dbc8 = &DAT_14000dbc0;
  _DAT_14000dbc0 = &DAT_14000dbc0;
  _DAT_14000dc10 = &DAT_14000dc08;
  _DAT_14000dc08 = &DAT_14000dc08;
  _DAT_14000dc58 = &DAT_14000dc50;
  _DAT_14000dc50 = &DAT_14000dc50;
  _DAT_14000dca0 = &DAT_14000dc98;
  _DAT_14000dc98 = &DAT_14000dc98;
  _DAT_14000dce8 = &DAT_14000dce0;
  _DAT_14000dce0 = &DAT_14000dce0;
  uVar3 = RoReferenceEx();
  if ((char)uVar3 == '\0') {
    iVar2 = -0x3fffffaa;
  }
  else {
    iVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 8))(&local_68);
    if (-1 < iVar2) {
      TcpipRegIpv4ProviderModuleHandle = (undefined4)local_60;
    }
    local_54 = 0;
    local_40 = TcpipRegInterfaceChangeCallback;
    local_58 = TcpipRegIpv4ProviderModuleHandle;
    local_18 = &TcpipRegIpv4NotificationHandle;
    local_48 = 7;
    local_37 = 0;
    local_33 = 0;
    local_31 = 0;
    local_28 = 0;
    uStack_20 = 0;
    local_30 = 0;
    local_38 = 1;
    local_50 = &NPI_MS_IPV4_MODULEID;
    iVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x40))(&local_58);
    if ((iVar2 < 0) && (iVar2 = TcpipRegGetNdisInterfaceLuidGuid(), -1 < iVar2)) {
      TcpipRegEnumerateRegInterfaceKeys();
    }
    LOCK();
    iVar1 = TcpipRegNaProviderReference + -2;
    UNLOCK();
    bVar4 = TcpipRegNaProviderReference == 3;
    TcpipRegNaProviderReference = iVar1;
    if (bVar4) {
      NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
    }
    if (-1 < iVar2) {
      _TcpipRegInitializedFlags = _TcpipRegInitializedFlags | 2;
    }
  }
  return iVar2;
}



===== IpAutoConfigurationLimitsRegKeyChangeHandler @ 1400019d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong IpAutoConfigurationLimitsRegKeyChangeHandler(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong in_stack_00000028;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined4 local_130;
  undefined1 *local_128;
  undefined4 local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  void *local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [116];
  undefined1 local_54;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_158;
  local_10c = 0;
  local_fc = 0;
  local_e4 = 0;
  local_dc = 0;
  memset(local_c8,0xff,0x9c);
  if (in_stack_00000028 == 0) {
    local_130 = 0;
    local_138 = 0;
    NsiClearPersistentSetting
              (*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    if (*(int *)(param_1 + 0x14) == 0x74) {
      local_54 = 1;
    }
    local_120 = 0x9c;
    local_128 = local_c8;
    local_130 = 0;
    local_138 = 0;
    uVar3 = NsiSetAllParameters(1,2,*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10));
  }
  else {
    local_108 = *(undefined8 *)(param_1 + 8);
    local_100 = *(undefined4 *)(param_1 + 0x10);
    local_d0 = *(undefined4 *)(param_1 + 0x18);
    local_cc = *(undefined4 *)(param_1 + 0x14);
    local_f0 = 0;
    local_e8 = 0;
    local_118 = 0;
    local_f8 = 0;
    local_f4 = 2;
    local_110 = 0;
    local_e0 = 0;
    local_d8 = (void *)(in_stack_00000028 + 0x1c);
    uVar3 = RoReferenceEx();
    if ((char)uVar3 == '\0') {
      uVar3 = 0xc0000056;
    }
    else {
      (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_118);
      uVar1 = *(uint *)(param_1 + 0x18);
      if ((uVar1 <= *(uint *)(in_stack_00000028 + 0x18)) &&
         (uVar2 = *(uint *)(param_1 + 0x14), uVar2 < 0x9c)) {
        if ((ulonglong)uVar1 <= 0x9c - (ulonglong)uVar2) {
          memmove(local_c8 + uVar2,(void *)(in_stack_00000028 + 0x1c),(ulonglong)uVar1);
          local_128 = local_c8;
          local_120 = 0x9c;
          local_130 = 0;
          local_138 = 0;
          uVar3 = NsiSetAllParameters(1,2,*(undefined8 *)(param_1 + 8),
                                      *(undefined4 *)(param_1 + 0x10));
          LOCK();
          UNLOCK();
          if (TcpipRegNaProviderReference == 3) {
            TcpipRegNaProviderReference = TcpipRegNaProviderReference + -2;
            NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
            return uVar3 & 0xffffffff;
          }
          TcpipRegNaProviderReference = TcpipRegNaProviderReference + -2;
          return uVar3;
        }
      }
      uVar3 = 0xc000000d;
    }
  }
  return uVar3;
}



===== InterfaceMetricRegKeyChangeHandler @ 140001c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InterfaceMetricRegKeyChangeHandler
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
              longlong param_5)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined1 local_68 [16];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_34;
  longlong local_30;
  uint local_28;
  undefined8 local_24;
  undefined4 local_1c;
  undefined1 *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = DefaultRegKeyChangeHandler(param_1,param_2,param_3,param_4,param_5);
  if (-1 < iVar2) {
    local_68[0] = param_5 == 0;
    uVar3 = RoReferenceEx();
    if ((char)uVar3 == '\0') {
      iVar2 = -0x3fffffaa;
    }
    else {
      local_58 = 0;
      local_50 = 0;
      local_3c = 0;
      local_28 = -(uint)(param_3 != 0) & 8;
      local_24 = 0;
      local_48 = *(undefined8 *)(param_1 + 8);
      local_40 = *(undefined4 *)(param_1 + 0x10);
      local_18 = local_68;
      local_1c = 0;
      local_34 = 0;
      local_10 = 1;
      local_c = 6;
      local_30 = param_3;
      iVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_58);
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar4 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar4) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
    }
  }
  return iVar2;
}



===== TcpipRegDeleteIpInterface @ 140001d10 =====

void TcpipRegDeleteIpInterface(longlong *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  uint uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  longlong lVar22;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar18 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
  UpdateInProgress = 1;
  KeAcquireInStackQueuedSpinLock(&InterfaceListLock,&local_28);
  do {
  } while (DAT_14000df28 != 0);
  lVar22 = *param_1;
  if ((*(longlong **)(lVar22 + 8) == param_1) &&
     (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 == param_1)) {
    uVar19 = 0;
    *plVar1 = lVar22;
    *(longlong **)(lVar22 + 8) = plVar1;
    TcpipRegNdisInterfaceCount = TcpipRegNdisInterfaceCount - 1;
    if (TcpipRegNdisInterfaceCount != 0) {
      do {
        uVar17 = (uint)uVar19;
        puVar15 = (undefined8 *)(TcpipRegNdisInterfaceLuidArray + uVar19 * 8);
        if (*(longlong *)(TcpipRegNdisInterfaceLuidArray + uVar19 * 8) == param_1[4]) {
          if (uVar17 < TcpipRegNdisInterfaceCount) {
            puVar20 = (undefined8 *)(uVar19 * 0x238 + TcpipRegNdisInterfaceRosArray);
            puVar16 = (undefined8 *)(TcpipRegNdisInterfaceLuidArray + (ulonglong)(uVar17 + 1) * 8);
            puVar21 = (undefined8 *)
                      ((ulonglong)(uVar17 + 1) * 0x238 + TcpipRegNdisInterfaceRosArray);
            uVar19 = (ulonglong)(TcpipRegNdisInterfaceCount - uVar17);
            do {
              *puVar15 = *puVar16;
              lVar22 = 4;
              puVar11 = puVar21;
              puVar12 = puVar20;
              do {
                puVar14 = puVar12;
                puVar13 = puVar11;
                uVar2 = puVar13[1];
                uVar8 = puVar13[2];
                uVar9 = puVar13[3];
                *puVar14 = *puVar13;
                puVar14[1] = uVar2;
                uVar2 = puVar13[4];
                uVar10 = puVar13[5];
                puVar14[2] = uVar8;
                puVar14[3] = uVar9;
                uVar8 = puVar13[6];
                uVar9 = puVar13[7];
                puVar14[4] = uVar2;
                puVar14[5] = uVar10;
                uVar2 = puVar13[8];
                uVar10 = puVar13[9];
                puVar14[6] = uVar8;
                puVar14[7] = uVar9;
                uVar8 = puVar13[10];
                uVar9 = puVar13[0xb];
                puVar14[8] = uVar2;
                puVar14[9] = uVar10;
                uVar2 = puVar13[0xc];
                uVar10 = puVar13[0xd];
                puVar14[10] = uVar8;
                puVar14[0xb] = uVar9;
                uVar8 = puVar13[0xe];
                uVar9 = puVar13[0xf];
                puVar14[0xc] = uVar2;
                puVar14[0xd] = uVar10;
                puVar14[0xe] = uVar8;
                puVar14[0xf] = uVar9;
                lVar22 = lVar22 + -1;
                puVar11 = puVar13 + 0x10;
                puVar12 = puVar14 + 0x10;
              } while (lVar22 != 0);
              uVar2 = puVar13[0x11];
              puVar16 = puVar16 + 1;
              puVar21 = puVar21 + 0x47;
              uVar8 = puVar13[0x12];
              uVar9 = puVar13[0x13];
              puVar15 = puVar15 + 1;
              puVar20 = puVar20 + 0x47;
              puVar14[0x10] = puVar13[0x10];
              puVar14[0x11] = uVar2;
              uVar4 = *(undefined4 *)(puVar13 + 0x14);
              uVar5 = *(undefined4 *)((longlong)puVar13 + 0xa4);
              uVar6 = *(undefined4 *)(puVar13 + 0x15);
              uVar7 = *(undefined4 *)((longlong)puVar13 + 0xac);
              uVar2 = puVar13[0x16];
              puVar14[0x12] = uVar8;
              puVar14[0x13] = uVar9;
              *(undefined4 *)(puVar14 + 0x14) = uVar4;
              *(undefined4 *)((longlong)puVar14 + 0xa4) = uVar5;
              *(undefined4 *)(puVar14 + 0x15) = uVar6;
              *(undefined4 *)((longlong)puVar14 + 0xac) = uVar7;
              puVar14[0x16] = uVar2;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          break;
        }
        uVar19 = (ulonglong)(uVar17 + 1);
      } while (uVar17 + 1 < TcpipRegNdisInterfaceCount);
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
    if (param_1[6] != 0) {
      ZwClose();
      TcpipRegDereferenceNotificationObject((int *)(param_1 + 5));
    }
    do {
      puVar15 = (undefined8 *)(&DAT_14000d038)[uVar18 * 9];
      while (puVar15 != &DAT_14000d038 + uVar18 * 9) {
        puVar16 = (undefined8 *)*puVar15;
        if ((longlong *)puVar15[2] == param_1 + 5) {
          if (((undefined8 *)puVar16[1] != puVar15) ||
             (puVar20 = (undefined8 *)puVar15[1], (undefined8 *)*puVar20 != puVar15))
          goto LAB_140001fa3;
          *puVar20 = puVar16;
          puVar16[1] = puVar20;
          ExFreePoolWithTag(puVar15,0);
          break;
        }
        puVar15 = puVar16;
      }
      uVar17 = (int)uVar18 + 1;
      uVar18 = (ulonglong)uVar17;
    } while (uVar17 < 0xe);
    if ((undefined8 *)*DAT_14000de98 == &DeletedInterface) {
      *param_1 = (longlong)&DeletedInterface;
      param_1[1] = (longlong)DAT_14000de98;
      *DAT_14000de98 = (longlong)param_1;
      UpdateInProgress = 0;
      DAT_14000de98 = param_1;
      KeReleaseMutex(&TcpipRegUpdateInProgess,0);
      return;
    }
  }
LAB_140001fa3:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== RtlAcquireReadLock @ 140001fb0 =====

void RtlAcquireReadLock(undefined8 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = KfRaiseIrql(2);
  *param_2 = uVar1;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  DAT_14000df28 = DAT_14000df28 + 1;
  UNLOCK();
  cVar2 = KeTestSpinLock(&InterfaceListLock);
  if (cVar2 == '\0') {
    LOCK();
    DAT_14000df28 = DAT_14000df28 + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&InterfaceListLock,&local_28);
    LOCK();
    DAT_14000df28 = DAT_14000df28 + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  return;
}



===== TcpipRegClearCachedLuidMapping @ 140002040 =====

undefined8 TcpipRegClearCachedLuidMapping(longlong *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  
  uVar14 = 0xc0000225;
  KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
  uVar19 = 0;
  if (TcpipRegNdisInterfaceCount != 0) {
    do {
      puVar17 = (undefined8 *)(TcpipRegNdisInterfaceLuidArray + uVar19 * 8);
      uVar10 = (uint)uVar19;
      if (*(longlong *)(TcpipRegNdisInterfaceLuidArray + uVar19 * 8) == *param_1) {
        if (uVar10 < TcpipRegNdisInterfaceCount) {
          TcpipRegNdisInterfaceCount = TcpipRegNdisInterfaceCount - 1;
          if (uVar10 < TcpipRegNdisInterfaceCount) {
            puVar16 = (undefined8 *)(TcpipRegNdisInterfaceLuidArray + (ulonglong)(uVar10 + 1) * 8);
            puVar18 = (undefined8 *)(uVar19 * 0x238 + TcpipRegNdisInterfaceRosArray);
            puVar15 = (undefined8 *)
                      ((ulonglong)(uVar10 + 1) * 0x238 + TcpipRegNdisInterfaceRosArray);
            uVar19 = (ulonglong)(TcpipRegNdisInterfaceCount - uVar10);
            do {
              *puVar17 = *puVar16;
              lVar12 = 4;
              puVar8 = puVar15;
              puVar9 = puVar18;
              do {
                puVar13 = puVar9;
                puVar11 = puVar8;
                uVar14 = puVar11[1];
                uVar5 = puVar11[2];
                uVar6 = puVar11[3];
                *puVar13 = *puVar11;
                puVar13[1] = uVar14;
                uVar14 = puVar11[4];
                uVar7 = puVar11[5];
                puVar13[2] = uVar5;
                puVar13[3] = uVar6;
                uVar5 = puVar11[6];
                uVar6 = puVar11[7];
                puVar13[4] = uVar14;
                puVar13[5] = uVar7;
                uVar14 = puVar11[8];
                uVar7 = puVar11[9];
                puVar13[6] = uVar5;
                puVar13[7] = uVar6;
                uVar5 = puVar11[10];
                uVar6 = puVar11[0xb];
                puVar13[8] = uVar14;
                puVar13[9] = uVar7;
                uVar14 = puVar11[0xc];
                uVar7 = puVar11[0xd];
                puVar13[10] = uVar5;
                puVar13[0xb] = uVar6;
                uVar5 = puVar11[0xe];
                uVar6 = puVar11[0xf];
                puVar13[0xc] = uVar14;
                puVar13[0xd] = uVar7;
                puVar13[0xe] = uVar5;
                puVar13[0xf] = uVar6;
                lVar12 = lVar12 + -1;
                puVar8 = puVar11 + 0x10;
                puVar9 = puVar13 + 0x10;
              } while (lVar12 != 0);
              uVar14 = puVar11[0x11];
              puVar16 = puVar16 + 1;
              puVar15 = puVar15 + 0x47;
              uVar5 = puVar11[0x12];
              uVar6 = puVar11[0x13];
              puVar17 = puVar17 + 1;
              puVar18 = puVar18 + 0x47;
              puVar13[0x10] = puVar11[0x10];
              puVar13[0x11] = uVar14;
              uVar1 = *(undefined4 *)(puVar11 + 0x14);
              uVar2 = *(undefined4 *)((longlong)puVar11 + 0xa4);
              uVar3 = *(undefined4 *)(puVar11 + 0x15);
              uVar4 = *(undefined4 *)((longlong)puVar11 + 0xac);
              uVar14 = puVar11[0x16];
              puVar13[0x12] = uVar5;
              puVar13[0x13] = uVar6;
              *(undefined4 *)(puVar13 + 0x14) = uVar1;
              *(undefined4 *)((longlong)puVar13 + 0xa4) = uVar2;
              *(undefined4 *)(puVar13 + 0x15) = uVar3;
              *(undefined4 *)((longlong)puVar13 + 0xac) = uVar4;
              puVar13[0x16] = uVar14;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          uVar14 = 0;
        }
        break;
      }
      uVar19 = (ulonglong)(uVar10 + 1);
    } while (uVar10 + 1 < TcpipRegNdisInterfaceCount);
  }
  KeReleaseMutex(&TcpipRegUpdateInProgess,0);
  return uVar14;
}



===== DefaultRegKeyChangeHandler @ 1400021d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
DefaultRegKeyChangeHandler
          (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,longlong param_5)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  longlong local_30;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_4c = 0;
  local_3c = 0;
  local_24 = 0;
  local_1c = 0;
  if (param_5 == 0) {
    uVar2 = NsiClearPersistentSetting
                      (*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),param_3,
                       -(param_3 != 0) & 8);
  }
  else {
    local_28 = -(uint)(param_3 != 0) & 8;
    local_48 = *(undefined8 *)(param_1 + 8);
    local_58 = 0;
    local_38 = 0;
    local_34 = 2;
    local_40 = *(undefined4 *)(param_1 + 0x10);
    local_50 = 0;
    local_18 = param_5 + 0x1c;
    local_10 = *(undefined4 *)(param_1 + 0x18);
    local_20 = 0;
    local_c = *(undefined4 *)(param_1 + 0x14);
    local_30 = param_3;
    uVar3 = RoReferenceEx();
    if ((char)uVar3 == '\0') {
      return 0xc0000056;
    }
    uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_58);
    LOCK();
    iVar1 = TcpipRegNaProviderReference + -2;
    UNLOCK();
    bVar4 = TcpipRegNaProviderReference == 3;
    TcpipRegNaProviderReference = iVar1;
    if (bVar4) {
      NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
    }
  }
  return uVar2;
}



===== TcpipRegAddDeletePersistentRoute @ 1400022f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
TcpipRegAddDeletePersistentRoute
          (undefined8 param_1,uint *param_2,byte param_3,uint *param_4,undefined4 param_5,
          char param_6)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined *local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined4 local_b4;
  longlong *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 *puStack_a0;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined8 local_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_88._0_4_ = (uint)(byte)local_88;
  if ((param_6 == '\0') ||
     (cVar2 = TcpipRegIsRouteAlreadyInNsiPersistentStore((int *)param_2,param_3,(int *)param_4),
     cVar2 == '\0')) {
    local_d0 = 0;
    local_bc = 0;
    local_a4 = 0;
    puStack_a0 = (undefined8 *)0x0;
    uStack_98 = 0;
    local_94 = 0;
    local_a8 = 0x30;
    local_d8 = 0;
    local_c0 = 0x10;
    local_68 = (ulonglong)*param_2 << 0x20;
    uStack_60 = (ulonglong)param_3;
    local_48 = 0;
    uStack_40 = (ulonglong)*param_4;
    local_58 = 0;
    uStack_50 = 0;
    local_88 = 0xffffffffffffffff;
    _uStack_80 = CONCAT44(param_5,0xffffffff);
    local_b0 = &local_68;
    local_c8 = &NPI_MS_IPV4_MODULEID;
    local_78 = 0xffffffffffffffff;
    uStack_70 = 0xffffffffffffffff;
    if (param_6 == '\0') {
      local_b4 = 3;
    }
    else {
      puStack_a0 = &local_88;
      local_b4 = 2;
      uStack_98 = 0x20;
    }
    uVar4 = RoReferenceEx();
    if ((char)uVar4 == '\0') {
      uVar3 = 0xc0000056;
    }
    else {
      uVar3 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x28))(&local_d8);
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar5 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar5) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== TcpipRegInitializeInterfaceNotificationTable @ 140002450 =====

ulonglong TcpipRegInitializeInterfaceNotificationTable(void)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  
  uVar3 = 0;
  uVar4 = 0;
  puVar5 = InterfaceListHead;
  while( true ) {
    if ((undefined8 **)puVar5 == &InterfaceListHead) {
      KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
      UpdateInProgress = 1;
      do {
        if ((undefined8 **)InterfaceListHead != &InterfaceListHead) {
          puVar5 = InterfaceListHead;
          do {
            TcpipRegQueryAndUpdateKeyValue
                      (1,(longlong)(puVar5 + 5),
                       (longlong)(&InterfaceRegKeyMappingTable + uVar3 * 0x48));
            puVar5 = (undefined8 *)*puVar5;
          } while ((undefined8 **)puVar5 != &InterfaceListHead);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 0xe);
      UpdateInProgress = 0;
      KeReleaseMutex(&TcpipRegUpdateInProgess,0);
      return uVar4;
    }
    uVar1 = TcpipRegInitializeInterfaceNotificationEntry((longlong)puVar5);
    uVar4 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) break;
    puVar5 = (undefined8 *)*puVar5;
  }
  return uVar1;
}



===== InterfaceDefaultGatewayRegKeyChangeHandler @ 140002540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InterfaceDefaultGatewayRegKeyChangeHandler
                    (longlong param_1,longlong param_2,undefined8 *param_3,longlong param_4,
                    longlong param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *_Dst;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  ushort *puVar10;
  short *psVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 auStack_188 [32];
  uint local_168;
  short *local_160;
  int local_158 [2];
  size_t local_150;
  longlong local_148;
  longlong local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_114;
  undefined8 *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 uStack_100;
  undefined4 uStack_f8;
  undefined4 local_f4;
  longlong local_e8;
  undefined1 local_d8 [12];
  undefined4 local_cc;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_bc;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 uStack_98;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_188;
  local_140 = param_5;
  uVar8 = 0;
  local_e8 = param_4;
  memset(local_d8,0,0x50);
  local_70 = *param_3;
  uVar12 = 0;
  local_160 = (short *)0x0;
  _Dst = (undefined8 *)0x0;
  local_128 = *(undefined8 *)(param_1 + 8);
  local_120 = *(undefined4 *)(param_1 + 0x10);
  local_148 = 0;
  local_158[0] = 0;
  local_168 = 0;
  local_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_60 = 0;
  local_130 = 0;
  local_11c = 0;
  local_114 = 0;
  local_104 = 0;
  uStack_100._0_4_ = 0;
  uStack_100._4_4_ = 0;
  uStack_f8 = 0;
  local_f4 = 0;
  local_108 = 0x30;
  local_138 = 0;
  local_110 = &local_88;
  local_68 = local_70;
  uVar6 = RoReferenceEx();
  if ((char)uVar6 == '\0') {
    return 0xc0000056;
  }
  uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
  if (param_5 != 0) {
    psVar11 = (short *)(param_5 + 0x1c);
    local_168 = (uint)uVar12;
    uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
    if (*psVar11 != (short)uVar12) {
      uVar12 = uVar12 & 0xffffffff;
      do {
        uVar9 = (uint)uVar12;
        uVar3 = RtlIpv4StringToAddressW(psVar11,1,&local_160,&local_60);
        param_5 = local_140;
        uVar8 = (ulonglong)uVar3;
        if (((int)uVar3 < 0) || (*local_160 != 0)) break;
        psVar11 = local_160 + 1;
        uVar9 = uVar9 + 1;
        uVar12 = (ulonglong)uVar9;
      } while (*psVar11 != 0);
      local_168 = uVar9;
      uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
      if (uVar9 != 0) {
        local_150 = (ulonglong)uVar9 * 0x50;
        _Dst = (undefined8 *)MALLOC(local_150);
        if (_Dst == (undefined8 *)0x0) {
          uVar8 = 0xc000009a;
          goto LAB_1400028f8;
        }
        local_c8 = *(undefined8 *)(param_1 + 8);
        local_cc = 0;
        local_bc = 0;
        local_b0 = (undefined8 *)0x0;
        local_a8 = 0;
        local_9c = 0;
        uStack_98._0_4_ = 0;
        uStack_98._4_4_ = 0;
        uStack_90 = 0;
        local_8c = 0;
        local_c0 = *(undefined4 *)(param_1 + 0x10);
        local_a0 = 0;
        puVar7 = QueryCurrentState(0x14000d1b0,param_2);
        memset(_Dst,0,local_150);
        uVar3 = local_168;
        psVar11 = (short *)(param_5 + 0x1c);
        uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
        if (*psVar11 != 0) {
          puVar10 = (ushort *)((longlong)puVar7 + 0x1c);
          uVar9 = 0;
          uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
          if (puVar7 == (undefined8 *)0x0) {
            puVar10 = (ushort *)0x0;
            uStack_98 = (undefined8 *)CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
          }
          while (uVar9 < uVar3) {
            puVar7 = _Dst + (ulonglong)uVar9 * 10;
            puVar7[3] = *param_3;
            puVar7[4] = *param_3;
            uVar4 = RtlIpv4StringToAddressW(psVar11,1,&local_160,puVar7 + 5);
            lVar2 = TcpipRegNaProviderContext;
            uVar8 = (ulonglong)uVar4;
            if ((*local_160 != 0) || ((int)uVar4 < 0)) break;
            puVar1 = puVar7 + 6;
            *puVar1 = 0xffffffffffffffff;
            puVar7[7] = 0xffffffffffffffff;
            puVar7[8] = 0xffffffffffffffff;
            puVar7[9] = 0xffffffffffffffff;
            local_a8 = CONCAT44(local_a8._4_4_,0x30);
            uStack_90 = 0x20;
            local_8c = 0;
            local_b0 = puVar7;
            uStack_98 = puVar1;
            iVar5 = (**(code **)(*(longlong *)(lVar2 + 8) + 0x10))(local_d8);
            if (iVar5 < 0) {
              *puVar1 = 0xffffffffffffffff;
              puVar7[7] = 0xffffffffffffffff;
              puVar7[8] = 0xffffffffffffffff;
              puVar7[9] = 0xffffffffffffffff;
            }
            uVar6 = GetCurrentMetric(puVar10,local_158,&local_148);
            uVar8 = uVar6 & 0xffffffff;
            if ((-1 < (int)uVar6) && (puVar10 = (ushort *)(local_148 + 2), local_158[0] != 0)) {
              *(int *)((longlong)puVar7 + 0x3c) = local_158[0];
            }
            uVar9 = uVar9 + 1;
            psVar11 = local_160 + 1;
            if (*psVar11 == 0) break;
          }
          param_5 = local_140;
          param_4 = local_e8;
        }
      }
      uVar12 = (ulonglong)local_168;
    }
  }
  if (param_4 != 0) {
    psVar11 = (short *)(param_4 + 0x1c);
    local_114 = 3;
    if (*psVar11 != 0) {
      do {
        uVar3 = RtlIpv4StringToAddressW(psVar11,1,&local_160,&local_60);
        uVar8 = (ulonglong)uVar3;
        if (((int)uVar3 < 0) || (*local_160 != 0)) break;
        uVar3 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x28))(&local_138);
        uVar8 = (ulonglong)uVar3;
        psVar11 = local_160 + 1;
      } while (*psVar11 != 0);
      uVar12 = (ulonglong)local_168;
    }
  }
  uStack_100 = (undefined8 *)CONCAT44(uStack_100._4_4_,(undefined4)uStack_100);
  if (param_5 != 0) {
    local_114 = 2;
    local_108 = 0x30;
    uStack_f8 = 0x20;
    uStack_100 = (undefined8 *)CONCAT44(uStack_100._4_4_,(undefined4)uStack_100);
    if ((int)uVar12 != 0) {
      uVar12 = uVar12 & 0xffffffff;
      puVar7 = _Dst;
      do {
        uStack_100 = puVar7 + 6;
        local_110 = puVar7;
        uVar3 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x28))(&local_138);
        puVar7 = puVar7 + 10;
        uVar8 = (ulonglong)uVar3;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
  }
  if (_Dst != (undefined8 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1400028f8:
  LOCK();
  iVar5 = TcpipRegNaProviderReference + -2;
  UNLOCK();
  bVar13 = TcpipRegNaProviderReference == 3;
  TcpipRegNaProviderReference = iVar5;
  if (bVar13) {
    NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
  }
  return uVar8;
}



===== TcpipRegInterfaceChangeCallback @ 140002950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TcpipRegInterfaceChangeCallback
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,int param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  ulonglong uVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  longlong lVar13;
  uint uVar14;
  undefined *puVar15;
  longlong *plVar16;
  longlong *plVar17;
  ulonglong uVar18;
  bool bVar19;
  undefined1 auStack_188 [32];
  undefined4 *local_168;
  undefined1 local_158 [8];
  longlong *local_150;
  undefined4 local_148 [4];
  undefined8 local_138;
  ulonglong uStack_130;
  undefined *local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 *puStack_110;
  ulonglong local_108;
  undefined8 uStack_100;
  longlong *local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  longlong *plStack_a0;
  ulonglong local_98;
  undefined8 uStack_90;
  ulonglong local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong local_40;
  longlong lStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_188;
  uVar18 = 0;
  local_d8 = 0;
  local_148[0] = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_158[0] = 0;
  local_b8 = (undefined *)0x0;
  uStack_b0 = 0;
  local_a8 = 0;
  plStack_a0 = (longlong *)0x0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = (undefined *)0x0;
  uStack_120 = 0;
  local_118 = 0;
  puStack_110 = (undefined8 *)0x0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = (longlong *)0x0;
  uStack_f0 = 0;
  local_40 = 0;
  lStack_38 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  puVar11 = param_2;
  iVar8 = param_4;
  uVar9 = RoReferenceEx();
  if ((char)uVar9 == '\0') {
    return;
  }
  if ((iVar8 == 1) || (param_4 == 0)) {
    plVar17 = (longlong *)*puVar11;
    uVar6 = KfRaiseIrql(2);
    local_48 = 0;
    local_58 = 0;
    uStack_50 = 0;
    LOCK();
    DAT_14000df28 = DAT_14000df28 + 1;
    UNLOCK();
    cVar7 = KeTestSpinLock(&InterfaceListLock);
    if (cVar7 == '\0') {
      LOCK();
      DAT_14000df28 = DAT_14000df28 + -1;
      UNLOCK();
      KeAcquireInStackQueuedSpinLockAtDpcLevel(&InterfaceListLock,&local_58);
      LOCK();
      DAT_14000df28 = DAT_14000df28 + 1;
      UNLOCK();
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
    }
    for (plVar10 = InterfaceListHead; plVar16 = (longlong *)0x0,
        (longlong **)plVar10 != &InterfaceListHead; plVar10 = (longlong *)*plVar10) {
      if (plVar10[4] == *plVar17) {
        plVar16 = plVar10;
        break;
      }
    }
    LOCK();
    DAT_14000df28 = DAT_14000df28 + -1;
    UNLOCK();
    KeLowerIrql(uVar6);
    if (plVar16 != (longlong *)0x0) {
      if (param_4 != 1) goto LAB_140002a91;
      puStack_110 = (undefined8 *)*param_2;
      local_f8 = &local_40;
      uStack_130 = (ulonglong)TcpipRegNdisProviderModuleHandle;
      uStack_120 = 1;
      local_108 = (ulonglong)*(uint *)(param_2 + 1);
      uStack_100 = 2;
      local_128 = &NPI_MS_NDIS_MODULEID;
      local_118 = CONCAT44(local_118._4_4_,1);
      local_138 = 0;
      uStack_f0 = 0x21800000010;
      iVar8 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x10))(&local_138);
      if (iVar8 < 0) goto LAB_140002a91;
      lVar13 = local_40 - plVar16[2];
      if (lVar13 == 0) {
        lVar13 = lStack_38 - plVar16[3];
      }
      if (lVar13 == 0) {
        local_168 = local_148;
        iVar8 = ZwQueryKey(plVar16[6],2,0,0);
        if (iVar8 != -0x3ffffe84) goto LAB_140002a91;
      }
      TcpipRegDeleteIpInterface(plVar16);
    }
    plVar17 = (longlong *)*param_2;
    TcpipRegClearCachedLuidMapping(plVar17);
    RtlAcquireReadLock(plVar17,local_158);
    plVar17 = (longlong *)0x0;
    for (uVar14 = 0; uVar14 < TcpipRegNdisInterfaceCount; uVar14 = uVar14 + 1) {
      uVar9 = (ulonglong)uVar14;
      if (*(longlong *)*param_2 == *(longlong *)(TcpipRegNdisInterfaceLuidArray + uVar9 * 8)) {
        plVar17 = (longlong *)MALLOC(0x90);
        if (plVar17 != (longlong *)0x0) {
          memset(plVar17,0,0x90);
          lVar13 = TcpipRegNdisInterfaceLuidArray;
          puVar1 = (undefined4 *)(uVar9 * 0x238 + 0x218 + TcpipRegNdisInterfaceRosArray);
          uVar3 = puVar1[1];
          uVar4 = puVar1[2];
          uVar5 = puVar1[3];
          *(undefined4 *)(plVar17 + 2) = *puVar1;
          *(undefined4 *)((longlong)plVar17 + 0x14) = uVar3;
          *(undefined4 *)(plVar17 + 3) = uVar4;
          *(undefined4 *)((longlong)plVar17 + 0x1c) = uVar5;
          plVar17[4] = *(longlong *)(lVar13 + uVar9 * 8);
        }
        break;
      }
    }
    local_150 = plVar17;
    if (uVar14 == TcpipRegNdisInterfaceCount) {
      LOCK();
      DAT_14000df28 = DAT_14000df28 + -1;
      UNLOCK();
      KeLowerIrql(local_158[0]);
      puStack_110 = (undefined8 *)*param_2;
      local_f8 = &local_40;
      uStack_130 = (ulonglong)TcpipRegNdisProviderModuleHandle;
      uStack_120 = 1;
      local_108 = (ulonglong)*(uint *)(param_2 + 1);
      uStack_100 = 2;
      local_118 = 1;
      local_128 = &NPI_MS_NDIS_MODULEID;
      local_138 = 0;
      uStack_f0 = 0x21800000010;
      iVar8 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x10))(&local_138);
      if (-1 < iVar8) {
        RtlAcquireWriteLock();
        uVar12 = TcpipRegReallocateGuidLuidMapping(puStack_110,(undefined4 *)local_f8);
        puVar11 = &local_e8;
        KeReleaseInStackQueuedSpinLock();
        if (-1 < (int)uVar12) {
          RtlAcquireReadLock(puVar11,local_158);
          iVar8 = TcpipRegCreateIpInterface((longlong *)*param_2,'\0','\0',&local_150);
          LOCK();
          DAT_14000df28 = DAT_14000df28 + -1;
          UNLOCK();
          KeLowerIrql(local_158[0]);
          if (-1 < iVar8) goto LAB_140002e13;
        }
      }
      plVar17 = local_150;
    }
    else {
      LOCK();
      DAT_14000df28 = DAT_14000df28 + -1;
      UNLOCK();
      KeLowerIrql(local_158[0]);
LAB_140002e13:
      plVar17 = local_150;
      uVar9 = TcpipRegInitializeInterfaceNotificationEntry((longlong)local_150);
      if (-1 < (int)uVar9) {
        local_168 = (undefined4 *)0x0;
        KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0);
        UpdateInProgress = 1;
        puVar15 = &InterfaceRegKeyMappingTable;
        lVar13 = 0xe;
        do {
          TcpipRegQueryAndUpdateKeyValue(1,(longlong)(plVar17 + 5),(longlong)puVar15);
          puVar15 = puVar15 + 0x48;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        UpdateInProgress = 0;
        KeReleaseMutex(&TcpipRegUpdateInProgess,0);
        KeAcquireInStackQueuedSpinLock(&InterfaceListLock,&local_e8);
        do {
        } while (DAT_14000df28 != 0);
        if ((longlong **)*DAT_14000df18 != &InterfaceListHead) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        local_150[1] = (longlong)DAT_14000df18;
        *local_150 = (longlong)&InterfaceListHead;
        *DAT_14000df18 = (longlong)local_150;
        DAT_14000df18 = local_150;
        KeReleaseInStackQueuedSpinLock(&local_e8);
        goto LAB_140002a91;
      }
    }
    if (plVar17 == (longlong *)0x0) goto LAB_140002a91;
  }
  else {
    if ((param_4 != 3) || (iVar8 = TcpipRegGetNdisInterfaceLuidGuid(), iVar8 < 0))
    goto LAB_140002a91;
    TcpipRegEnumerateRegInterfaceKeys();
    uStack_c0 = CONCAT44(uStack_c0._4_4_,TcpipRegIpv4ProviderModuleHandle);
    local_b8 = &NPI_MS_IPV4_MODULEID;
    local_a8 = 0x100000001;
    local_c8 = 0;
    uStack_60 = uStack_60 & 0xffffffff00000000;
    plStack_a0 = (longlong *)0x0;
    local_98 = local_98 & 0xffffffff00000000;
    uStack_b0 = CONCAT44(uStack_b0._4_4_,7);
    uStack_80 = 0;
    local_78 = local_78 & 0xffffffff00000000;
    uStack_70 = 0;
    local_68 = local_68 & 0xffffffff00000000;
    uStack_90 = 0;
    local_88 = local_88 & 0xffffffff00000000;
    (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x38))(&local_c8);
    uVar14 = (uint)uStack_60 + 5;
    plVar17 = (longlong *)MALLOC((ulonglong)uVar14 << 3);
    local_98 = CONCAT44(local_98._4_4_,8);
    uStack_60 = CONCAT44(uStack_60._4_4_,uVar14);
    plStack_a0 = plVar17;
    iVar8 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x38))(&local_c8);
    if ((-1 < iVar8) && ((uint)uStack_60 != 0)) {
      do {
        puVar11 = TcpipRegFindIpInterfaceByLuid(plVar17 + uVar18);
        if (puVar11 == (undefined8 *)0x0) {
          RtlAcquireWriteLock();
          TcpipRegCreateIpInterface(plVar17 + uVar18,'\0','\x01',(undefined8 *)0x0);
          KeReleaseInStackQueuedSpinLock(&local_e8);
        }
        uVar14 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar14;
      } while (uVar14 < (uint)uStack_60);
    }
    if (plVar17 == (longlong *)0x0) goto LAB_140002a91;
  }
  ExFreePoolWithTag(plVar17,0);
LAB_140002a91:
  LOCK();
  iVar8 = TcpipRegNaProviderReference + -2;
  UNLOCK();
  bVar19 = TcpipRegNaProviderReference == 3;
  TcpipRegNaProviderReference = iVar8;
  if (bVar19) {
    NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
  }
  return;
}



===== RoReferenceEx @ 140003010 =====

/* WARNING: Removing unreachable block (ram,0x00014000301f) */

ulonglong RoReferenceEx(void)

{
  uint uVar1;
  
  uVar1 = TcpipRegNaProviderReference;
  if ((uVar1 & 1) == 0) {
    LOCK();
    TcpipRegNaProviderReference = uVar1 + 2;
    UNLOCK();
    return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
  return (ulonglong)(uVar1 & 0xffffff00);
}



===== TcpipRegInitializeGlobalNotification @ 140003040 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TcpipRegInitializeGlobalNotification(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  longlong lVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  _TcpipGlobalKeyNotification = 1;
  local_34 = 0;
  local_1c = 0;
  _DAT_14000df80 = TcpipRegGlobalRegistryKeyChangeCallback;
  DAT_14000df88 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&DAT_14000df90,0,0);
  _DAT_14000df50 = 0;
  _DAT_14000df60 = TcpipRegRegistryKeyChangeCallback;
  _DAT_14000df68 = &TcpipGlobalKeyNotification;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters");
  local_28 = &local_48;
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = ZwOpenKey(&DAT_14000df48,0x2001f,&local_38);
  if (-1 < (int)uVar2) {
    LOCK();
    _TcpipGlobalKeyNotification = _TcpipGlobalKeyNotification + 1;
    UNLOCK();
    uVar1 = ZwNotifyChangeKey(DAT_14000df48,0,&DAT_14000df50,1,&DAT_14000df70,4,DAT_14000df88,0,0,1)
    ;
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      TcpipRegDereferenceNotificationObject((int *)&TcpipGlobalKeyNotification);
    }
    KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
    UpdateInProgress = 1;
    puVar3 = &GlobalRegKeyMappingTable;
    lVar4 = 0x20;
    do {
      TcpipRegQueryAndUpdateKeyValue(0,0x14000df40,(longlong)puVar3);
      puVar3 = puVar3 + 0x48;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    UpdateInProgress = 0;
    KeReleaseMutex(&TcpipRegUpdateInProgess,0);
  }
  return uVar2;
}



===== TcpipRegInterfaceRegistryKeyChangeCallback @ 140003230 =====

void TcpipRegInterfaceRegistryKeyChangeCallback(longlong param_1)

{
  undefined *puVar1;
  longlong lVar2;
  
  puVar1 = &InterfaceRegKeyMappingTable;
  lVar2 = 0xe;
  do {
    TcpipRegQueryAndUpdateKeyValue(1,param_1,(longlong)puVar1);
    puVar1 = puVar1 + 0x48;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== TcpipRegQueryAndUpdateKeyValue @ 140003290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TcpipRegQueryAndUpdateKeyValue(uint param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint local_res10 [2];
  longlong *local_res18;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar7 = (uint)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  plVar11 = *(longlong **)(param_3 + 0x38);
  plVar1 = (longlong *)(param_3 + 0x38);
  uVar2 = *(undefined8 *)(param_2 + 8);
  lVar9 = 0;
  local_res10[0] = 0;
  for (; plVar11 != plVar1; plVar11 = (longlong *)*plVar11) {
    if (plVar11[2] == param_2) goto LAB_1400032d1;
  }
  plVar11 = (longlong *)0x0;
LAB_1400032d1:
  local_res18 = (longlong *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  bVar6 = false;
  RtlInitUnicodeString(&local_48,*(undefined8 *)(param_3 + 0x20));
  uVar7 = ZwQueryValueKey(uVar2,&local_48,2,0,(ulonglong)uVar7 << 0x20,local_res10);
  if ((uVar7 == 0xc0000023) || (uVar7 == 0x80000005)) {
    local_58 = 1;
    local_50 = 0;
    lVar9 = ExAllocatePool3(0x40,local_res10[0],0x6547654c,&local_58,1);
    if (lVar9 == 0) {
      return 0xc000009a;
    }
    uVar7 = ZwQueryValueKey(uVar2,&local_48,2,lVar9,local_res10[0],local_res10);
  }
  uVar12 = (ulonglong)uVar7;
  if ((int)uVar7 < 0) {
    if ((uVar7 != 0xc0000034) || (plVar11 == (longlong *)0x0)) goto LAB_1400033a8;
    lVar13 = *plVar11;
    if ((*(longlong **)(lVar13 + 8) != plVar11) ||
       (plVar1 = (longlong *)plVar11[1], (longlong *)*plVar1 != plVar11)) {
LAB_1400035b7:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar12 = (*pcVar5)();
      return uVar12;
    }
    bVar6 = true;
    *plVar1 = lVar13;
    *(longlong **)(lVar13 + 8) = plVar1;
    plVar10 = local_res18;
LAB_1400034c1:
    if (param_1 < 2) {
      lVar13 = param_2 + -8;
      if (param_1 != 1) {
        lVar13 = 0;
      }
      if ((plVar10 != (longlong *)0x0) && (*(int *)(param_3 + 0x1c) == 4)) {
        uVar7 = *(uint *)(param_3 + 0x18);
        if (uVar7 < *(uint *)(plVar10 + 3)) {
          memset((void *)((ulonglong)uVar7 + 0x1c + (longlong)plVar10),0,
                 (ulonglong)(*(uint *)(plVar10 + 3) - uVar7));
        }
      }
      (**(code **)(param_3 + 0x28))(param_3,param_2,lVar13,plVar11,plVar10);
      goto LAB_1400033a8;
    }
  }
  else if (*(int *)(lVar9 + 4) == *(int *)(param_3 + 0x1c)) {
    if (((plVar11 != (longlong *)0x0) && (*(uint *)(lVar9 + 8) == *(uint *)(plVar11 + 3))) &&
       (iVar8 = memcmp((void *)(lVar9 + 0xc),(void *)((longlong)plVar11 + 0x1c),
                       (ulonglong)*(uint *)(lVar9 + 8)), iVar8 == 0)) goto LAB_1400033a8;
    local_res10[0] = *(uint *)(lVar9 + 8) + 0x20;
    if (local_res10[0] < *(uint *)(lVar9 + 8)) {
      local_res10[0] = 0xffffffff;
      uVar12 = 0xc0000095;
      goto LAB_1400033a8;
    }
    plVar10 = (longlong *)MALLOC((ulonglong)local_res10[0]);
    if (plVar10 == (longlong *)0x0) {
      uVar12 = 0xc000009a;
      goto LAB_1400033a8;
    }
    if (plVar11 != (longlong *)0x0) {
      lVar13 = *plVar11;
      if ((*(longlong **)(lVar13 + 8) != plVar11) ||
         (plVar4 = (longlong *)plVar11[1], (longlong *)*plVar4 != plVar11)) goto LAB_1400035b7;
      *plVar4 = lVar13;
      bVar6 = true;
      *(longlong **)(lVar13 + 8) = plVar4;
    }
    memmove((void *)((longlong)plVar10 + 0x1c),(void *)(lVar9 + 0xc),(ulonglong)*(uint *)(lVar9 + 8)
           );
    *(undefined4 *)(plVar10 + 3) = *(undefined4 *)(lVar9 + 8);
    plVar10[2] = param_2;
    puVar3 = *(undefined8 **)(param_3 + 0x40);
    if ((longlong *)*puVar3 != plVar1) goto LAB_1400035b7;
    *plVar10 = (longlong)plVar1;
    plVar10[1] = (longlong)puVar3;
    *puVar3 = plVar10;
    *(longlong **)(param_3 + 0x40) = plVar10;
    goto LAB_1400034c1;
  }
  uVar12 = 0xc000000d;
LAB_1400033a8:
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  if (bVar6) {
    ExFreePoolWithTag(plVar11,0);
  }
  return uVar12;
}



===== TcpipRegGetNdisInterfaceLuidGuid @ 1400035d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TcpipRegGetNdisInterfaceLuidGuid(void)

{
  int iVar1;
  longlong lVar2;
  undefined *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  longlong local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  longlong local_30;
  undefined4 local_28;
  longlong local_20;
  undefined4 local_18;
  uint local_10;
  
  memset(&local_78,0,0x70);
  local_88 = &NPI_MS_NDIS_MODULEID;
  local_80 = 0;
  iVar1 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 8))(&local_88);
  if (-1 < iVar1) {
    TcpipRegNdisProviderModuleHandle = (undefined4)local_80;
    local_54 = 1;
    local_58 = 1;
    local_78 = 0;
    local_10 = 0;
    local_50 = 0;
    local_48 = 0;
    local_68 = &NPI_MS_NDIS_MODULEID;
    local_60 = 1;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    local_40 = 0;
    local_38 = 0;
    local_70 = TcpipRegNdisProviderModuleHandle;
    iVar1 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x38))(&local_78);
    local_10 = local_10 + 5;
    TcpipRegNdisInterfaceLuidArray = MALLOC((ulonglong)local_10 << 3);
    if (TcpipRegNdisInterfaceLuidArray == 0) {
      iVar1 = -0x3fffff66;
    }
    else if (-1 < iVar1) {
      TcpipRegNdisInterfaceRosArray = MALLOC((ulonglong)local_10 * 0x238);
      if (TcpipRegNdisInterfaceRosArray == 0) {
        iVar1 = -0x3fffff66;
      }
      else {
        lVar2 = MALLOC((ulonglong)local_10 * 0x290);
        if (lVar2 == 0) {
          iVar1 = -0x3fffff66;
        }
        else {
          local_20 = TcpipRegNdisInterfaceRosArray;
          local_50 = TcpipRegNdisInterfaceLuidArray;
          local_18 = 0x238;
          local_48 = 8;
          local_28 = 0x290;
          local_30 = lVar2;
          iVar1 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x38))(&local_78);
          if (-1 < iVar1) {
            TcpipRegNdisInterfaceCount = local_10;
          }
          ExFreePoolWithTag(lVar2,0);
          if (-1 < iVar1) {
            return iVar1;
          }
        }
      }
    }
  }
  if (TcpipRegNdisInterfaceLuidArray != 0) {
    ExFreePoolWithTag(TcpipRegNdisInterfaceLuidArray,0);
    TcpipRegNdisInterfaceLuidArray = 0;
  }
  if (TcpipRegNdisInterfaceRosArray != 0) {
    ExFreePoolWithTag(TcpipRegNdisInterfaceRosArray,0);
    TcpipRegNdisInterfaceRosArray = 0;
  }
  return iVar1;
}



===== GetAddressStringFromAddress @ 1400037e0 =====

void GetAddressStringFromAddress(undefined4 param_1,undefined8 *param_2,longlong *param_3)

{
  short *psVar1;
  short *psVar2;
  longlong lVar3;
  undefined4 local_res8 [2];
  
  local_res8[0] = param_1;
  psVar1 = (short *)MALLOC(0x30);
  if (psVar1 == (short *)0x0) {
    *param_2 = 0;
    *param_3 = 0;
    return;
  }
  RtlIpv4AddressToStringW(local_res8,psVar1);
  *param_2 = psVar1;
  lVar3 = 0x16;
  psVar2 = psVar1;
  do {
    if (*psVar2 == 0) break;
    psVar2 = psVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if (param_3 != (longlong *)0x0) {
    if (lVar3 == 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = 0x16 - lVar3;
    }
  }
  lVar3 = *param_3;
  psVar1[lVar3 + 1] = 0;
  *param_3 = lVar3 * 2 + 4;
  return;
}



===== TcpipRegUpdateRegistryValue @ 1400038a0 =====

void TcpipRegUpdateRegistryValue
               (longlong param_1,uint param_2,ulonglong *param_3,STRSAFE_PCNZWCH param_4,
               longlong param_5,uint param_6,int param_7,char param_8)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  ushort *_Buf1;
  ulonglong uVar7;
  uint uVar8;
  ulonglong local_res20;
  STRSAFE_PCNZWCH local_58;
  ulonglong local_50;
  longlong local_48;
  longlong *local_40;
  char *local_38;
  undefined8 uStack_30;
  
  uVar1 = param_6;
  uVar7 = (ulonglong)param_6;
  uVar8 = 0;
  local_40 = (longlong *)0x0;
  local_48 = 0;
  local_res20 = local_res20 & 0xffffffff00000000;
  local_58 = param_4;
  local_50 = uVar7;
  KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
  if (UpdateInProgress != '\x01') {
    UpdateInProgress = 1;
    local_38 = &GlobalRegKeyMappingTable;
    do {
      uVar3 = TcpipRegIsMatchingNsiObject
                        (0,uVar8,param_1,param_3,(longlong)local_38,param_7,param_8,
                         (longlong *)&local_40,&local_48,(uint *)param_4,param_5,uVar1,param_2,
                         &local_58,(longlong *)&local_50);
      param_6 = CONCAT31(param_6._1_3_,(char)uVar3);
      cVar6 = '\0';
      if ((char)uVar3 != '\0') {
        lVar5 = 0;
        if (local_48 != 0) {
          lVar5 = *(longlong *)(local_48 + 8);
        }
        TcpipRegCheckUpdateRegistryValue
                  (local_48,lVar5,local_38,local_40,param_2,param_4,param_8,uVar7,(int *)0x0);
        cVar6 = (char)param_6;
      }
      uVar8 = uVar8 + 1;
      local_38 = local_38 + 0x48;
    } while (uVar8 < 0x20);
    if (cVar6 != '\x01') {
      uVar3 = 0;
      do {
        local_38 = &InterfaceRegKeyMappingTable + uVar3 * 0x48;
        uVar4 = TcpipRegIsMatchingNsiObject
                          (1,(int)uVar3,param_1,param_3,(longlong)local_38,param_7,param_8,
                           (longlong *)&local_40,&local_48,(uint *)param_4,param_5,uVar1,param_2,
                           &local_58,(longlong *)&local_50);
        if ((char)uVar4 != '\0') {
          if ((local_58 == (STRSAFE_PCNZWCH)0x0) && (param_2 != 4)) break;
          if (local_48 == 0) {
            lVar5 = 0;
          }
          else {
            lVar5 = *(longlong *)(local_48 + 8);
          }
          TcpipRegCheckUpdateRegistryValue
                    (local_48,lVar5,local_38,local_40,param_2,local_58,param_8,local_50,
                     (int *)&local_res20);
        }
        if (local_58 != param_4) {
          if (local_58 != (STRSAFE_PCNZWCH)0x0) {
            ExFreePoolWithTag(local_58,0);
          }
          local_58 = param_4;
          local_50 = uVar7;
        }
        uVar8 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar8;
      } while (uVar8 < 0xe);
      iVar2 = *(int *)(param_1 + 0x10);
      _Buf1 = *(ushort **)(param_1 + 8);
      local_res20 = DAT_14000dfc8;
      param_6 = 0;
      local_38 = (char *)0x0;
      uStack_30 = 0;
      lVar5 = MALLOC(0x200);
      uVar7 = local_res20;
      if (lVar5 != 0) {
        if (param_2 == 4) {
          do {
            iVar2 = ZwEnumerateValueKey(uVar7,0,0,lVar5,0x1fe,&param_6);
            if ((iVar2 < 0) ||
               (*(undefined2 *)(lVar5 + 0xc + (ulonglong)(*(uint *)(lVar5 + 8) >> 1) * 2) = 0,
               *(int *)(lVar5 + 8) == 0)) break;
            RtlInitUnicodeString(&local_38,lVar5 + 0xc);
            iVar2 = ZwDeleteValueKey(uVar7);
          } while (-1 < iVar2);
        }
        else if (((iVar2 == 0x10) &&
                 (iVar2 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)*_Buf1), iVar2 == 0)) &&
                (param_3 != (ulonglong *)0x0)) {
          TcpipRegUpdateSingleRoute
                    ((ulonglong)_Buf1,param_2,(longlong *)param_3,(undefined4 *)param_4,uVar1);
        }
        ExFreePoolWithTag(lVar5,0);
      }
    }
    UpdateInProgress = '\0';
  }
  KeReleaseMutex(&TcpipRegUpdateInProgess,0);
  return;
}



===== TcpipRegIsMatchingNsiObject @ 140003c70 =====

ulonglong TcpipRegIsMatchingNsiObject
                    (int param_1,int param_2,longlong param_3,ulonglong *param_4,longlong param_5,
                    int param_6,char param_7,longlong *param_8,undefined8 *param_9,uint *param_10,
                    longlong param_11,uint param_12,uint param_13,undefined8 *param_14,
                    longlong *param_15)

{
  ushort uVar1;
  ushort *_Buf1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 extraout_var;
  ulonglong uVar7;
  short *psVar8;
  short *psVar9;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  byte bVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  longlong *plVar15;
  byte bVar16;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  iVar5 = *(int *)(param_3 + 0x10);
  uVar14 = 0;
  _Buf1 = *(ushort **)(param_3 + 8);
  *param_8 = 0;
  *param_9 = 0;
  if (param_13 == 4) {
    if (iVar5 != *(int *)(param_5 + 0x10)) {
      return 0;
    }
    if (*_Buf1 == **(ushort **)(param_5 + 8)) {
      iVar4 = memcmp(_Buf1,*(ushort **)(param_5 + 8),(ulonglong)*_Buf1);
      if (iVar4 == 0) {
        return CONCAT71((int7)(CONCAT44(extraout_var_02,iVar4) >> 8),1);
      }
    }
  }
  else if (iVar5 != *(int *)(param_5 + 0x10)) {
    return 0;
  }
  if (param_7 == '\x01') {
    if (param_11 != 0) {
      if (param_12 < *(int *)(param_5 + 0x14) + *(uint *)(param_5 + 0x18)) {
        return 0;
      }
      for (uVar6 = 0; uVar6 < *(uint *)(param_5 + 0x18); uVar6 = uVar6 + 1) {
        if (*(char *)((ulonglong)(uVar6 + *(int *)(param_5 + 0x14)) + param_11) != -1) {
          return 0;
        }
      }
    }
  }
  else {
    if (param_7 != '\0') {
      return 0;
    }
    if (param_6 != *(int *)(param_5 + 0x14)) {
      return 0;
    }
  }
  uVar1 = *_Buf1;
  if (uVar1 != **(ushort **)(param_5 + 8)) {
    return 0;
  }
  iVar4 = memcmp(_Buf1,*(ushort **)(param_5 + 8),(ulonglong)uVar1);
  if (iVar4 != 0) {
    return 0;
  }
  if (param_1 == 0) {
    lVar12 = *(longlong *)(param_5 + 0x38);
    *param_9 = &TcpipGlobalKeyNotification;
    if (lVar12 == param_5 + 0x38) {
      return 1;
    }
    *param_8 = lVar12;
    return 1;
  }
  param_13 = (uint)param_4[1];
  if (param_13 < 8) {
    return 0;
  }
  plVar15 = (longlong *)*param_4;
  if (iVar5 == 10) {
    iVar4 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)uVar1);
    uVar7 = CONCAT44(extraout_var_03,iVar4);
    if ((iVar4 != 0) || (param_2 != 0)) goto LAB_140003d72;
    if (param_13 < 0x10) goto LAB_140003f41;
    GetAddressStringFromAddress((int)plVar15[1],param_14,param_15);
LAB_140003f48:
    iVar5 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)*_Buf1);
    uVar7 = CONCAT44(extraout_var_00,iVar5);
    if ((iVar5 == 0) && (param_2 == 1)) {
      if ((uint)param_4[1] < 0x10) {
LAB_140003f41:
        return uVar7 & 0xffffffffffffff00;
      }
      plVar15 = (longlong *)*param_4;
      if (param_7 == '\x01') {
        if (param_12 < 0x11) goto LAB_140003f41;
        param_10 = param_10 + 4;
      }
      else if (param_12 == 0) goto LAB_140003f41;
      bVar16 = 0;
      uVar6 = 0;
      if ((byte)*param_10 != 0) {
        do {
          bVar10 = 0x1f - bVar16;
          bVar16 = bVar16 + 1;
          uVar6 = uVar6 | 1 << (bVar10 & 0x1f);
        } while (bVar16 < (byte)*param_10);
      }
      GetAddressStringFromAddress
                (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18,
                 param_14,param_15);
    }
  }
  else {
LAB_140003d72:
    if (iVar5 == 10) goto LAB_140003f48;
    if (iVar5 == 0x10) {
      iVar5 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)*_Buf1);
      uVar7 = CONCAT44(extraout_var_04,iVar5);
      if ((iVar5 == 0) && (param_2 == 5)) {
        if ((uint)param_4[1] < 0x30) goto LAB_140003f41;
        uVar7 = *param_4;
        plVar15 = (longlong *)(uVar7 + 0x18);
        if (*(char *)(uVar7 + 8) != '\0') goto LAB_140003f41;
        GetAddressStringFromAddress(*(undefined4 *)(uVar7 + 0x28),param_14,param_15);
      }
      iVar5 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)*_Buf1);
      uVar7 = CONCAT44(extraout_var_01,iVar5);
      if ((iVar5 == 0) && (param_2 == 6)) {
        if ((uint)param_4[1] < 0x30) goto LAB_140003f41;
        uVar7 = *param_4;
        plVar15 = (longlong *)(uVar7 + 0x18);
        if (*(char *)(uVar7 + 8) != '\0') goto LAB_140003f41;
        if (param_7 == '\x01') {
          if (param_12 < 0x10) goto LAB_140003f41;
          param_10 = param_10 + 3;
        }
        else if (param_12 < 4) goto LAB_140003f41;
        GetMetricString(*param_10,param_14,param_15);
      }
    }
    else if (iVar5 == 7) {
      iVar5 = memcmp(_Buf1,&NPI_MS_IPV4_MODULEID,(ulonglong)*_Buf1);
      uVar7 = CONCAT44(extraout_var,iVar5);
      if ((iVar5 == 0) && (param_2 == 2)) {
        if ((param_7 != '\0') || (param_12 < 4)) goto LAB_140003f41;
        plVar15 = (longlong *)*param_4;
        param_13 = *param_10;
        psVar8 = (short *)MALLOC(0x30);
        if (psVar8 == (short *)0x0) {
          *param_14 = 0;
          *param_15 = 0;
        }
        else {
          RtlIpv4AddressToStringW(&param_13,psVar8);
          lVar12 = 0x16;
          *param_14 = psVar8;
          psVar9 = psVar8;
          do {
            if (*psVar9 == 0) break;
            psVar9 = psVar9 + 1;
            lVar12 = lVar12 + -1;
          } while (lVar12 != 0);
          if (param_15 != (longlong *)0x0) {
            if (lVar12 == 0) {
              *param_15 = 0;
            }
            else {
              *param_15 = 0x16 - lVar12;
            }
          }
          lVar12 = *param_15;
          psVar8[lVar12 + 1] = 0;
          *param_15 = lVar12 * 2 + 4;
        }
      }
    }
  }
  uVar2 = KfRaiseIrql(2);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  DAT_14000df28 = DAT_14000df28 + 1;
  UNLOCK();
  cVar3 = KeTestSpinLock(&InterfaceListLock);
  if (cVar3 == '\0') {
    LOCK();
    DAT_14000df28 = DAT_14000df28 + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&InterfaceListLock,&local_48);
    LOCK();
    DAT_14000df28 = DAT_14000df28 + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_48);
  }
  for (puVar13 = InterfaceListHead; (undefined8 **)puVar13 != &InterfaceListHead;
      puVar13 = (undefined8 *)*puVar13) {
    if (puVar13[4] == *plVar15) {
      puVar11 = *(undefined8 **)(param_5 + 0x38);
      goto LAB_140003e0e;
    }
  }
LAB_140003e23:
  LOCK();
  DAT_14000df28 = DAT_14000df28 + -1;
  UNLOCK();
  KeLowerIrql(uVar2);
  return uVar14;
LAB_140003e0e:
  if (puVar11 == (undefined8 *)(param_5 + 0x38)) goto code_r0x000140003e1b;
  if ((undefined8 *)puVar11[2] == puVar13 + 5) {
    *param_9 = (undefined8 *)puVar11[2];
    *param_8 = (longlong)puVar11;
    goto LAB_140003e21;
  }
  puVar11 = (undefined8 *)*puVar11;
  goto LAB_140003e0e;
code_r0x000140003e1b:
  *param_9 = puVar13 + 5;
  *param_8 = 0;
LAB_140003e21:
  uVar14 = 1;
  goto LAB_140003e23;
}



===== MALLOC @ 1400042b0 =====

void MALLOC(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = 1;
  local_10 = 0;
  ExAllocatePool3(0x40,param_1,0x6547654c,&local_18,1);
  return;
}



===== TcpipRegCheckUpdateRegistryValue @ 140004300 =====

ulonglong TcpipRegCheckUpdateRegistryValue
                    (longlong param_1,longlong param_2,char *param_3,longlong *param_4,int param_5,
                    STRSAFE_PCNZWCH param_6,char param_7,ulonglong param_8,int *param_9)

{
  wchar_t wVar1;
  wchar_t wVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  HRESULT HVar10;
  longlong lVar11;
  STRSAFE_PCNZWCH pwVar12;
  longlong *plVar13;
  longlong *plVar14;
  ulonglong uVar15;
  int iVar16;
  STRSAFE_PCNZWCH pwVar17;
  STRSAFE_PCNZWCH pwVar18;
  size_t sVar19;
  ULONG UVar20;
  char *pcVar21;
  STRSAFE_PCNZWCH *pcbLength;
  uint uVar22;
  size_t local_res18;
  longlong *local_res20;
  uint local_78 [2];
  STRSAFE_PCNZWCH local_70;
  ulonglong local_68 [6];
  
  local_78[0] = 0;
  local_res18 = local_res18 & 0xffffffff00000000;
  local_68[1] = 0;
  local_68[2] = 0;
  uVar15 = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  pcVar21 = param_3;
  local_res20 = param_4;
  RtlInitUnicodeString(local_68 + 1,*(undefined8 *)(param_3 + 0x20));
  RtlInitUnicodeString(local_68 + 3,L"MaxUserPort");
  UVar20 = (ULONG)CONCAT71((int7)((ulonglong)pcVar21 >> 8),1);
  cVar6 = RtlEqualUnicodeString(local_68 + 1,local_68 + 3);
  if (cVar6 != '\0') {
    return 0;
  }
  if (param_5 == 4) {
    plVar14 = (longlong *)(param_3 + 0x38);
    while( true ) {
      plVar13 = (longlong *)*plVar14;
      if (plVar13 == plVar14) {
        return uVar15;
      }
      if (((longlong *)plVar13[1] != plVar14) ||
         (lVar11 = *plVar13, (longlong *)*(longlong *)(lVar11 + 8) != plVar13)) break;
      *plVar14 = lVar11;
      *(longlong **)(lVar11 + 8) = plVar14;
      uVar7 = ZwDeleteValueKey(*(undefined8 *)(plVar13[2] + 8),local_68 + 1);
      uVar15 = (ulonglong)uVar7;
      ExFreePoolWithTag(plVar13,0);
    }
    goto LAB_140004a23;
  }
  if ((*param_3 == '\x01') && (param_6 != (STRSAFE_PCNZWCH)0x0)) {
    if (param_7 == '\x01') {
      pwVar17 = (STRSAFE_PCNZWCH)((ulonglong)*(uint *)(param_3 + 0x14) + (longlong)param_6);
    }
    else {
      pwVar17 = param_6;
    }
    lVar11 = IsValueUnChanged((longlong)pwVar17,*(uint *)(param_3 + 0x18));
    if ((char)lVar11 == '\x01') {
      plVar14 = *(longlong **)(param_3 + 0x38);
      do {
        if (plVar14 == (longlong *)(param_3 + 0x38)) {
LAB_140004471:
          uVar7 = ZwDeleteValueKey(param_2,local_68 + 1);
          return (ulonglong)uVar7;
        }
        plVar13 = (longlong *)*plVar14;
        if (*(longlong *)(plVar14[2] + 8) == param_2) {
          if (((longlong *)plVar13[1] != plVar14) ||
             (plVar3 = (longlong *)plVar14[1], (longlong *)*plVar3 != plVar14)) goto LAB_140004a23;
          *plVar3 = (longlong)plVar13;
          plVar13[1] = (longlong)plVar3;
          ExFreePoolWithTag(plVar14,0);
          goto LAB_140004471;
        }
        plVar14 = plVar13;
      } while( true );
    }
  }
  iVar8 = *(int *)(param_3 + 0x1c);
  if (iVar8 != 7) {
    if (param_7 != '\0') {
      param_6 = (STRSAFE_PCNZWCH)((longlong)param_6 + (ulonglong)*(uint *)(param_3 + 0x14));
    }
    if (iVar8 == 1) {
      local_70 = (STRSAFE_PCNZWCH)0x0;
      if (param_8 < *(uint *)(param_3 + 0x14)) {
        return 0xc0000095;
      }
      pcbLength = &local_70;
      sVar19 = param_8 - *(uint *)(param_3 + 0x14);
      if (param_7 == '\0') {
        sVar19 = param_8;
      }
      uVar7 = StringCbLengthW(param_6,sVar19,(size_t *)pcbLength);
      UVar20 = (ULONG)pcbLength;
      if ((int)uVar7 < 0) {
        return (ulonglong)uVar7;
      }
      iVar8 = *(int *)(param_3 + 0x1c);
      uVar7 = (int)local_70 + 2;
    }
    else {
      uVar7 = *(uint *)(param_3 + 0x18);
    }
    param_8 = (ulonglong)uVar7;
  }
  uVar7 = 0;
  if (param_4 != (longlong *)0x0) {
    uVar7 = *(uint *)(param_4 + 3);
  }
  if ((iVar8 == 4) && ((uint)param_8 < 4)) {
    if ((uint)param_8 == 1) {
      local_78[0] = (uint)(byte)*param_6;
    }
    else {
      local_78[0] = (uint)(ushort)*param_6;
    }
    param_8 = 4;
    param_6 = (STRSAFE_PCNZWCH)local_78;
  }
  TcpipRegTranslateValueInPlace((longlong)param_3,(int *)param_6);
  local_68[0] = param_8 & 0xffffffff;
  local_70 = param_6;
  TcpipRegTranslateValueToIPAddress
            ((longlong)param_3,(ULONG *)param_6,UVar20,&local_70,(longlong *)local_68);
  if (param_6 == local_70) {
    local_70 = (STRSAFE_PCNZWCH)0x0;
  }
  else {
    param_8 = local_68[0] & 0xffffffff;
    param_6 = local_70;
  }
  uVar22 = (uint)param_8;
  if (param_5 == 3) {
LAB_1400045b1:
    if ((local_res20 != (longlong *)0x0) || (param_5 != 3)) {
LAB_1400045ca:
      if ((param_9 != (int *)0x0) && (iVar8 = *param_9, iVar8 != 0)) {
        iVar9 = wcscmp(*(wchar_t **)(param_3 + 0x20),L"SubnetMask");
        iVar16 = (int)local_res18;
        if (iVar9 == 0) {
          iVar16 = iVar8;
        }
        local_res18 = CONCAT44(local_res18._4_4_,iVar16);
      }
      plVar14 = local_res20;
      if (*(int *)(param_3 + 0x1c) != 7) {
        if (param_5 == 3) {
          lVar11 = *local_res20;
          if ((*(longlong **)(lVar11 + 8) != local_res20) ||
             (plVar14 = (longlong *)local_res20[1], (longlong *)*plVar14 != local_res20))
          goto LAB_140004a23;
          *plVar14 = lVar11;
          *(longlong **)(lVar11 + 8) = plVar14;
          ExFreePoolWithTag(local_res20,0);
          uVar7 = ZwDeleteValueKey(param_2,local_68 + 1);
        }
        else {
          if (uVar7 < uVar22) {
            if (local_res20 != (longlong *)0x0) {
              lVar11 = *local_res20;
              if ((*(longlong **)(lVar11 + 8) != local_res20) ||
                 (plVar14 = (longlong *)local_res20[1], (longlong *)*plVar14 != local_res20))
              goto LAB_140004a23;
              *plVar14 = lVar11;
              *(longlong **)(lVar11 + 8) = plVar14;
              ExFreePoolWithTag(local_res20,0);
            }
            plVar14 = (longlong *)MALLOC((param_8 & 0xffffffff) + 0x20);
            if (plVar14 == (longlong *)0x0) {
              uVar15 = 0xc000009a;
              goto LAB_14000490f;
            }
            *(uint *)(plVar14 + 3) = uVar22;
            plVar14[2] = param_1;
            memmove((void *)((longlong)plVar14 + 0x1c),param_6,param_8 & 0xffffffff);
            plVar13 = *(longlong **)(param_3 + 0x40);
            if ((char *)*plVar13 != param_3 + 0x38) goto LAB_140004a23;
LAB_1400048da:
            *plVar14 = (longlong)(param_3 + 0x38);
            plVar14[1] = (longlong)plVar13;
            *plVar13 = (longlong)plVar14;
            *(longlong **)(param_3 + 0x40) = plVar14;
          }
          else {
            *(uint *)(local_res20 + 3) = uVar22;
            memmove((void *)((longlong)local_res20 + 0x1c),param_6,param_8 & 0xffffffff);
          }
LAB_1400048e8:
          uVar7 = ZwSetValueKey(param_2,local_68 + 1,0,*(undefined4 *)(param_3 + 0x1c),param_6,
                                uVar22);
        }
        uVar15 = (ulonglong)uVar7;
        goto LAB_14000490f;
      }
      if (param_5 != 3) {
        if (local_res20 == (longlong *)0x0) {
LAB_1400047f8:
          plVar14 = (longlong *)MALLOC((param_8 & 0xffffffff) + 0x20);
          if (plVar14 == (longlong *)0x0) {
            uVar15 = 0xc000009a;
            goto LAB_14000490f;
          }
          *(uint *)(plVar14 + 3) = uVar22;
          plVar14[2] = param_1;
          memmove((void *)((longlong)plVar14 + 0x1c),param_6,param_8 & 0xffffffff);
          plVar13 = *(longlong **)(param_3 + 0x40);
          if ((char *)*plVar13 != param_3 + 0x38) goto LAB_140004a23;
          goto LAB_1400048da;
        }
        uVar7 = *(uint *)(local_res20 + 3);
        pwVar17 = (STRSAFE_PCNZWCH)((longlong)local_res20 + 0x1c);
        local_res18 = 0;
        sVar19 = (size_t)(uVar7 >> 1);
        pwVar18 = pwVar17;
        do {
          HVar10 = StringCchLengthW(pwVar18,sVar19,&local_res18);
          if (HVar10 != 0) break;
          iVar8 = wcscmp(pwVar18,L"0.0.0.0");
          if (iVar8 == 0) {
            if (pwVar18 != (STRSAFE_PCNZWCH)0x0) {
              lVar11 = *local_res20;
              if ((*(longlong **)(lVar11 + 8) != local_res20) ||
                 (plVar14 = (longlong *)local_res20[1], (longlong *)*plVar14 != local_res20))
              goto LAB_140004a23;
              *plVar14 = lVar11;
              *(longlong **)(lVar11 + 8) = plVar14;
              ExFreePoolWithTag(local_res20,0);
              goto LAB_1400047f8;
            }
            break;
          }
          pwVar18 = pwVar18 + local_res18 + 1;
          sVar19 = sVar19 + (-1 - local_res18);
        } while (sVar19 != 0);
        plVar13 = (longlong *)MALLOC((ulonglong)(uVar22 + 0x1e + uVar7));
        plVar14 = local_res20;
        if (plVar13 == (longlong *)0x0) {
          uVar15 = 0xc000009a;
          goto LAB_14000490f;
        }
        lVar11 = local_res20[3];
        plVar13[2] = param_1;
        *(uint *)(plVar13 + 3) = (int)lVar11 + -2 + uVar22;
        memmove((void *)((longlong)plVar13 + 0x1c),pwVar17,(ulonglong)*(uint *)(local_res20 + 3) - 2
               );
        memmove((void *)((ulonglong)*(uint *)(plVar14 + 3) + 0x1a + (longlong)plVar13),param_6,
                param_8 & 0xffffffff);
        lVar11 = *plVar14;
        param_6 = (STRSAFE_PCNZWCH)((longlong)plVar13 + 0x1c);
        uVar22 = *(uint *)(plVar13 + 3);
        if ((*(longlong **)(lVar11 + 8) != plVar14) ||
           (plVar3 = (longlong *)plVar14[1], (longlong *)*plVar3 != plVar14)) {
LAB_140004a23:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          uVar15 = (*pcVar4)();
          return uVar15;
        }
        *plVar3 = lVar11;
        *(longlong **)(lVar11 + 8) = plVar3;
        ExFreePoolWithTag(plVar14,0);
        plVar14 = *(longlong **)(param_3 + 0x40);
        if ((char *)*plVar14 != param_3 + 0x38) goto LAB_140004a23;
        *plVar13 = (longlong)(param_3 + 0x38);
        plVar13[1] = (longlong)plVar14;
        *plVar14 = (longlong)plVar13;
        *(longlong **)(param_3 + 0x40) = plVar13;
        goto LAB_1400048e8;
      }
      iVar8 = 1;
      pwVar17 = (STRSAFE_PCNZWCH)((longlong)local_res20 + 0x1c);
      uVar15 = (ulonglong)(*(uint *)(local_res20 + 3) >> 1);
      pwVar18 = pwVar17;
      do {
        if (pwVar18 == (STRSAFE_PCNZWCH)0x0) break;
        uVar5 = uVar15;
        pwVar12 = pwVar18;
        if (0x7fffffff < uVar15) break;
        for (; (uVar5 != 0 && (*pwVar12 != L'\0')); pwVar12 = pwVar12 + 1) {
          uVar5 = uVar5 - 1;
        }
        if (uVar5 == 0) break;
        pwVar12 = pwVar18;
        do {
          wVar1 = *pwVar12;
          wVar2 = *(wchar_t *)((longlong)pwVar12 + ((longlong)param_6 - (longlong)pwVar18));
          if (wVar1 != wVar2) break;
          pwVar12 = pwVar12 + 1;
        } while (wVar2 != L'\0');
        if (wVar1 == wVar2) {
          if ((int)local_res18 == 0) {
            local_res18 = CONCAT44(local_res18._4_4_,iVar8);
          }
          else if ((int)local_res18 != iVar8) goto LAB_140004695;
          memmove(pwVar18,(void *)(((param_8 & 0xffffffff) - 2) + (longlong)pwVar18),
                  (longlong)local_res20 +
                  (((ulonglong)*(uint *)(local_res20 + 3) - (param_8 & 0xffffffff)) -
                  (longlong)pwVar18) + 0x1e);
          plVar13 = plVar14 + 3;
          *(uint *)plVar13 = (int)*plVar13 + (2 - uVar22);
          uVar22 = *(uint *)(plVar14 + 3);
          param_6 = pwVar17;
          if (param_9 != (int *)0x0) {
            iVar8 = wcscmp(*(wchar_t **)(param_3 + 0x20),L"IPAddress");
            if (iVar8 == 0) {
              *param_9 = (int)local_res18;
            }
            iVar8 = wcscmp(*(wchar_t **)(param_3 + 0x20),L"SubnetMask");
            if (iVar8 == 0) {
              *param_9 = 0;
            }
          }
          goto LAB_1400048e8;
        }
LAB_140004695:
        pwVar18 = pwVar18 + (uVar15 - uVar5) + 1;
        iVar8 = iVar8 + 1;
        uVar15 = uVar15 + (-1 - (uVar15 - uVar5));
      } while (uVar15 != 0);
    }
  }
  else {
    if (((local_res20 == (longlong *)0x0) || (uVar22 != uVar7)) ||
       (iVar8 = memcmp(param_6,(void *)((longlong)local_res20 + 0x1c),param_8 & 0xffffffff),
       iVar8 != 0)) goto LAB_1400045ca;
    if (*(int *)(param_3 + 0x1c) == 7) goto LAB_1400045b1;
  }
  uVar15 = 0;
LAB_14000490f:
  if (local_70 != (STRSAFE_PCNZWCH)0x0) {
    ExFreePoolWithTag(local_70,0);
  }
  return uVar15;
}



===== TcpipRegTranslateValueToIPAddress @ 140004a30 =====

void TcpipRegTranslateValueToIPAddress
               (longlong param_1,ULONG *param_2,ULONG param_3,undefined8 *param_4,longlong *param_5)

{
  char cVar1;
  NTSTATUS NVar2;
  ULONG local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res18[0] = param_3;
  RtlInitUnicodeString(&local_18,*(undefined8 *)(param_1 + 0x20));
  RtlInitUnicodeString(&local_28,L"IPAutoconfigurationMask");
  cVar1 = RtlEqualUnicodeString(&local_18,&local_28,1);
  if (cVar1 != '\0') {
    local_res18[0] = 0;
    NVar2 = ConvertLengthToIpv4Mask(*param_2,local_res18);
    if (NVar2 < 0) {
      return;
    }
    if (local_res18[0] == 0xffffffff) {
      *param_4 = param_2;
      *(undefined2 *)param_2 = 0;
      *param_5 = 2;
    }
    else {
      GetAddressStringFromAddress(local_res18[0],param_4,param_5);
    }
  }
  RtlInitUnicodeString(&local_28,L"IPAutoconfigurationSubnet");
  cVar1 = RtlEqualUnicodeString(&local_18,&local_28,1);
  if (cVar1 != '\0') {
    if (*param_2 == 0xffffffff) {
      *param_4 = param_2;
      *(undefined2 *)param_2 = 0;
      *param_5 = 2;
    }
    else {
      GetAddressStringFromAddress(*param_2,param_4,param_5);
    }
  }
  return;
}



===== TcpipRegTranslateValueInPlace @ 140004b60 =====

void TcpipRegTranslateValueInPlace(longlong param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_18,*(undefined8 *)(param_1 + 0x20));
  RtlInitUnicodeString(&local_28,L"Tcp1323Opts");
  cVar1 = RtlEqualUnicodeString(&local_18,&local_28,1);
  if (cVar1 != '\0') {
    iVar2 = 2;
    if (*param_2 != 1) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
  }
  return;
}



===== TcpipRegValidatePersistentRoute @ 140004be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TcpipRegValidatePersistentRoute
              (void *param_1,uint param_2,undefined8 param_3,PUINT8 param_4,undefined8 param_5,
              undefined8 param_6)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short *_Dst;
  short *psVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_c8 [32];
  uint local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  short *local_78 [3];
  longlong local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar5 = 0;
  local_90 = param_5;
  local_98 = param_6;
  local_78[1] = (short *)0x0;
  local_78[2] = (short *)0x0;
  local_60 = 0;
  uVar7 = 0;
  local_a0 = 0;
  local_a8[0] = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (param_2 + 2 < param_2) {
    return -0x3fffff6b;
  }
  _Dst = (short *)MALLOC((ulonglong)(param_2 + 2));
  if (_Dst == (short *)0x0) {
    return -0x3fffff66;
  }
  _Dst[param_2 >> 1] = 0;
  memmove(_Dst,param_1,(ulonglong)param_2);
  psVar4 = _Dst;
  while( true ) {
    uVar6 = (uint)uVar7;
    local_78[0] = _Dst;
    if (*psVar4 == 0) break;
    if (*psVar4 == 0x2c) {
      if (2 < uVar6) goto LAB_140004cea;
      *psVar4 = 0;
      uVar7 = (ulonglong)(uVar6 + 1);
      local_78[uVar7] = psVar4 + 1;
      psVar4 = psVar4 + 1;
    }
    else {
      psVar4 = psVar4 + 1;
    }
  }
  if (uVar6 == 3) {
    while( true ) {
      sVar1 = *(short *)(local_60 + uVar5 * 2);
      if (sVar1 == 0) break;
      if (9 < (ushort)(sVar1 - 0x30U)) goto LAB_140004cea;
      uVar5 = (ulonglong)((uint)uVar5 + 1);
    }
    if ((uint)uVar5 < 0xb) {
      RtlInitUnicodeString(&local_88);
      iVar2 = RtlUnicodeStringToInteger(&local_88,10,local_98);
      if (((iVar2 < 0) ||
          (iVar2 = RtlIpv4StringToAddressW(local_78[0],1,&local_a0,param_3), iVar2 < 0)) ||
         (iVar2 = RtlIpv4StringToAddressW(local_78[1],1,&local_a0,local_a8), iVar2 < 0))
      goto LAB_140004ded;
      if (local_a8[0] != 0xffffffff) {
        uVar3 = ~(local_a8[0] >> 0x18 | (local_a8[0] & 0xff0000) >> 8 | (local_a8[0] & 0xff00) << 8
                 | local_a8[0] << 0x18);
        uVar6 = uVar3 + 1;
        if ((uVar6 == 0) || ((uVar3 & uVar6) != 0)) goto LAB_140004cea;
      }
      iVar2 = ConvertIpv4MaskToLength(local_a8[0],param_4);
      if (-1 < iVar2) {
        iVar2 = RtlIpv4StringToAddressW(local_78[2],1,&local_a0,local_90);
      }
      goto LAB_140004ded;
    }
  }
LAB_140004cea:
  iVar2 = -0x3ffffff3;
LAB_140004ded:
  ExFreePoolWithTag(_Dst,0);
  return iVar2;
}



===== TcpipRegUpdateSingleRoute @ 140004e20 =====

NTSTATUS TcpipRegUpdateSingleRoute
                   (ulonglong param_1,int param_2,longlong *param_3,undefined4 *param_4,uint param_5
                   )

{
  undefined8 *puVar1;
  int iVar2;
  STRSAFE_LPWSTR pszDest;
  short *psVar3;
  longlong lVar4;
  short *psVar5;
  short *psVar6;
  STRSAFE_LPWSTR pwVar7;
  STRSAFE_LPWSTR pwVar8;
  longlong lVar9;
  ulonglong local_res8;
  undefined4 local_a8 [2];
  ULONG local_a0 [2];
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  local_res8 = param_1 & 0xffffffff00000000;
  iVar2 = 0;
  psVar3 = (short *)0x0;
  psVar5 = (short *)0x0;
  pwVar7 = (STRSAFE_LPWSTR)0x0;
  local_90 = 0;
  uStack_88 = 0;
  pszDest = (STRSAFE_LPWSTR)MALLOC(0x202);
  if (pszDest == (STRSAFE_LPWSTR)0x0) {
    return -0x3fffff66;
  }
  puVar1 = (undefined8 *)*param_3;
  if (((puVar1 == (undefined8 *)0x0) || (*(uint *)(param_3 + 1) < 0x30)) || (param_5 < 0x10)) {
LAB_140004e87:
    iVar2 = -0x3ffffff3;
    goto LAB_14000510a;
  }
  local_80 = *puVar1;
  uStack_78 = puVar1[1];
  local_60 = puVar1[4];
  uStack_58 = puVar1[5];
  if (puVar1[3] == 0) {
    local_50 = *param_4;
    uStack_4c = param_4[1];
    uStack_48 = param_4[2];
    uStack_44 = param_4[3];
    iVar2 = ConvertLengthToIpv4Mask((uint)(byte)uStack_78,(PULONG)&local_res8);
    if (iVar2 < 0) goto LAB_1400050c5;
    memset(pszDest,0,0x202);
    local_a8[0] = local_80._4_4_;
    psVar3 = (short *)MALLOC(0x30);
    if (psVar3 == (short *)0x0) goto LAB_140004e87;
    RtlIpv4AddressToStringW(local_a8,psVar3);
    lVar9 = 0x16;
    psVar5 = psVar3;
    do {
      if (*psVar5 == 0) break;
      psVar5 = psVar5 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    lVar4 = 0x16 - lVar9;
    if (lVar9 == 0) {
      lVar4 = 0;
    }
    psVar3[lVar4 + 1] = 0;
    local_a0[0] = (ULONG)local_res8;
    psVar5 = (short *)MALLOC(0x30);
    if (psVar5 == (short *)0x0) {
      psVar5 = (short *)0x0;
LAB_140004f8b:
      pwVar7 = (STRSAFE_LPWSTR)0x0;
      iVar2 = -0x3ffffff3;
    }
    else {
      RtlIpv4AddressToStringW(local_a0,psVar5);
      lVar9 = 0x16;
      psVar6 = psVar5;
      do {
        if (*psVar6 == 0) break;
        psVar6 = psVar6 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      lVar4 = 0x16 - lVar9;
      if (lVar9 == 0) {
        lVar4 = 0;
      }
      psVar5[lVar4 + 1] = 0;
      local_98[0] = (undefined4)uStack_58;
      pwVar7 = (STRSAFE_LPWSTR)MALLOC(0x30);
      if (pwVar7 == (STRSAFE_LPWSTR)0x0) goto LAB_140004f8b;
      RtlIpv4AddressToStringW(local_98,pwVar7);
      lVar9 = 0x16;
      pwVar8 = pwVar7;
      do {
        if (*pwVar8 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      lVar4 = 0x16 - lVar9;
      if (lVar9 == 0) {
        lVar4 = 0;
      }
      pwVar7[lVar4 + 1] = L'\0';
      pwVar8 = pwVar7;
      iVar2 = StringCchPrintfW(pszDest,0x101,L"%s,%s,%s,%u",psVar3,psVar5,pwVar7,uStack_44);
      if (iVar2 < 0) goto LAB_1400050c5;
      RtlInitUnicodeString(&local_90,pszDest);
      if ((param_2 == 1) || (param_2 == 2)) {
        iVar2 = ZwSetValueKey(DAT_14000dfc8,&local_90,0,1,0,(ulonglong)pwVar8 & 0xffffffff00000000);
      }
      else if ((param_2 != 3) || (iVar2 = ZwDeleteValueKey(DAT_14000dfc8,&local_90), iVar2 < 0))
      goto LAB_1400050c5;
    }
    ExFreePoolWithTag(pszDest,0);
LAB_1400050db:
    ExFreePoolWithTag(psVar3,0);
    pszDest = pwVar7;
  }
  else {
LAB_1400050c5:
    ExFreePoolWithTag(pszDest,0);
    pszDest = pwVar7;
    if (psVar3 != (short *)0x0) goto LAB_1400050db;
  }
  if (psVar5 != (short *)0x0) {
    ExFreePoolWithTag(psVar5,0);
  }
  if (pszDest == (STRSAFE_LPWSTR)0x0) {
    return iVar2;
  }
LAB_14000510a:
  ExFreePoolWithTag(pszDest,0);
  return iVar2;
}



===== TcpipRegInitializeInterfaceNotificationEntry @ 140005180 =====

ulonglong TcpipRegInitializeInterfaceNotificationEntry(longlong param_1)

{
  int *piVar1;
  HRESULT HVar2;
  uint uVar3;
  ulonglong uVar4;
  STRSAFE_LPWSTR pszDest;
  undefined8 local_res8;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_54 = 0;
  local_3c = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_res8 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar4 = RtlStringFromGUID(param_1 + 0x10,&local_88);
  if (-1 < (int)uVar4) {
    pszDest = (STRSAFE_LPWSTR)MALLOC(0x200);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      HVar2 = StringCbPrintfW(pszDest,0x200,L"%ls\\%ls",
                              L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces"
                              ,uStack_80);
      if (HVar2 < 0) {
        ExFreePoolWithTag(pszDest,0);
        uVar4 = 0xc0000023;
      }
      else {
        RtlFreeUnicodeString(&local_88);
        *(undefined1 *)(param_1 + 0x70) = 0;
        piVar1 = (int *)(param_1 + 0x28);
        *(code **)(param_1 + 0x68) = TcpipRegInterfaceRegistryKeyChangeCallback;
        *piVar1 = 1;
        KeInitializeEvent(param_1 + 0x78,0,0);
        *(int **)(param_1 + 0x50) = piVar1;
        *(code **)(param_1 + 0x48) = TcpipRegRegistryKeyChangeCallback;
        *(undefined8 *)(param_1 + 0x38) = 0;
        RtlInitUnicodeString(&local_78,pszDest);
        local_48 = &local_78;
        local_58 = 0x30;
        local_50 = 0;
        local_40 = 0x240;
        local_38 = 0;
        uStack_30 = 0;
        uVar3 = ZwCreateKey(param_1 + 0x30,0x2001f,&local_58,0,0,0,0);
        while (uVar3 == 0xc000003a) {
          RtlInitUnicodeString
                    (&local_68,
                     L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces"
                    );
          local_48 = &local_68;
          local_58 = 0x30;
          local_50 = 0;
          local_40 = 0x240;
          local_38 = 0;
          uStack_30 = 0;
          ZwCreateKey(&local_res8,0x2001f,&local_58,0,0,0,0);
          ZwClose(local_res8);
          local_48 = &local_78;
          local_58 = 0x30;
          local_50 = 0;
          local_40 = 0x240;
          local_38 = 0;
          uStack_30 = 0;
          uVar3 = ZwCreateKey(param_1 + 0x30,0x2001f,&local_58,0,0,0,0);
        }
        if ((int)uVar3 < 0) {
          ExFreePoolWithTag(pszDest,0);
        }
        else {
          LOCK();
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          uVar3 = ZwNotifyChangeKey(*(undefined8 *)(param_1 + 0x30),0,param_1 + 0x38,1,
                                    param_1 + 0x58,4,*(undefined1 *)(param_1 + 0x70),0,0,1);
          if ((int)uVar3 < 0) {
            TcpipRegDereferenceNotificationObject(piVar1);
          }
          ExFreePoolWithTag(pszDest,0);
        }
        uVar4 = (ulonglong)uVar3;
      }
    }
  }
  return uVar4;
}



===== TcpipRegPersistentRoutesKeyChangeCallback @ 1400054b0 =====

void TcpipRegPersistentRoutesKeyChangeCallback(longlong param_1)

{
  undefined8 uVar1;
  longlong ***ppplVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong ***ppplVar6;
  longlong ****pppplVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  HRESULT HVar11;
  longlong lVar12;
  longlong ****pppplVar13;
  undefined8 *puVar14;
  longlong ****pppplVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined8 *puVar18;
  byte local_res10 [8];
  undefined4 local_res18 [2];
  uint local_res20 [2];
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  uint local_78 [2];
  size_t local_70;
  longlong ****local_68;
  longlong ****local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  iVar16 = 0;
  local_60 = (longlong ****)&local_68;
  local_68 = (longlong ****)&local_68;
  local_78[1] = 0;
  local_78[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_70 = 0;
  lVar12 = MALLOC(0x200);
  puVar17 = auStackY_a8;
  if (lVar12 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 8);
    while( true ) {
      iVar10 = ZwEnumerateValueKey(uVar1,iVar16,0,lVar12);
      iVar16 = iVar16 + 1;
      if (iVar10 == -0x7fffffe6) break;
      if (((iVar10 < 0) || (*(int *)(lVar12 + 4) != 1)) || (0x1fe < *(uint *)(lVar12 + 8) - 1))
      goto LAB_14000583a;
      iVar10 = TcpipRegValidatePersistentRoute
                         ((void *)(lVar12 + 0xc),*(uint *)(lVar12 + 8),local_78,local_res10,
                          local_res20,local_res18);
      if (iVar10 < 0) {
        if (iVar10 != -0x7fffffe6) goto LAB_14000583a;
        break;
      }
      pppplVar13 = (longlong ****)MALLOC(0x218);
      if (pppplVar13 == (longlong ****)0x0) goto LAB_14000583a;
      memset(pppplVar13,0,0x218);
      memmove(pppplVar13 + 2,(void *)(lVar12 + 0xc),(ulonglong)*(uint *)(lVar12 + 8));
      pppplVar15 = local_68;
      if ((longlong *****)*local_60 != &local_68) goto LAB_140005875;
      pppplVar13[1] = (longlong ***)local_60;
      *pppplVar13 = (longlong ***)&local_68;
      *local_60 = (longlong ***)pppplVar13;
      local_60 = pppplVar13;
    }
    puVar18 = PersistentRoutesListHead;
LAB_1400055fb:
    if ((undefined8 **)puVar18 != &PersistentRoutesListHead) {
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      uStack_40 = 0;
      RtlInitUnicodeString(&local_58,puVar18 + 2);
      pppplVar13 = local_68;
      while ((longlong *****)pppplVar13 != &local_68) {
        RtlInitUnicodeString(&local_48,pppplVar13 + 2);
        cVar9 = RtlEqualUnicodeString(&local_48,&local_58,1);
        pppplVar7 = (longlong ****)*pppplVar13;
        if (cVar9 != '\0') {
          pppplVar15 = local_68;
          if (((longlong ****)pppplVar7[1] != pppplVar13) ||
             (ppplVar2 = pppplVar13[1], (longlong ****)*ppplVar2 != pppplVar13)) goto LAB_140005875;
          *ppplVar2 = (longlong **)pppplVar7;
          pppplVar7[1] = ppplVar2;
          ExFreePoolWithTag(pppplVar13,0);
          puVar18 = (undefined8 *)*puVar18;
          goto LAB_1400055fb;
        }
        pppplVar13 = pppplVar7;
      }
      HVar11 = StringCbLengthW((STRSAFE_PCNZWCH)(puVar18 + 2),0x202,&local_70);
      if (HVar11 < 0) goto LAB_14000583a;
      puVar14 = puVar18 + 2;
      iVar16 = TcpipRegValidatePersistentRoute
                         (puVar14,(uint)local_70,local_78,local_res10,local_res20,local_res18);
      if (iVar16 < 0) goto LAB_14000583a;
      TcpipRegAddDeletePersistentRoute
                (puVar14,local_78,local_res10[0],local_res20,local_res18[0],'\0');
      puVar14 = (undefined8 *)*puVar18;
      plVar3 = (longlong *)puVar14[1];
      lVar4 = *plVar3;
      pppplVar15 = local_68;
      if ((*(longlong **)(lVar4 + 8) != plVar3) ||
         (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) goto LAB_140005875;
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      ExFreePoolWithTag(puVar18,0);
      puVar18 = puVar14;
      goto LAB_1400055fb;
    }
    while (pppplVar13 = local_68, (longlong *****)local_68 != &local_68) {
      pppplVar15 = local_68;
      if ((((longlong *****)local_68[1] != &local_68) ||
          (pppplVar7 = (longlong ****)*local_68, (longlong ****)pppplVar7[1] != local_68)) ||
         (pppplVar7[1] = (longlong ***)&local_68, pppplVar15 = pppplVar7,
         *DAT_14000df38 != (longlong ***)&PersistentRoutesListHead)) goto LAB_140005875;
      *local_68 = (longlong ***)&PersistentRoutesListHead;
      local_68 = pppplVar7;
      pppplVar13[1] = (longlong ***)DAT_14000df38;
      *DAT_14000df38 = (longlong ***)pppplVar13;
      DAT_14000df38 = pppplVar13;
      HVar11 = StringCbLengthW((STRSAFE_PCNZWCH)(pppplVar13 + 2),0x202,&local_70);
      if (HVar11 < 0) break;
      pppplVar15 = pppplVar13 + 2;
      iVar16 = TcpipRegValidatePersistentRoute
                         (pppplVar15,(uint)local_70,local_78,local_res10,local_res20,local_res18);
      if (iVar16 < 0) break;
      iVar16 = TcpipRegAddDeletePersistentRoute
                         (pppplVar15,local_78,local_res10[0],local_res20,local_res18[0],'\x01');
      if (iVar16 < 0) {
        ppplVar2 = *pppplVar13;
        pppplVar15 = local_68;
        if (((longlong ****)ppplVar2[1] != pppplVar13) ||
           (ppplVar6 = pppplVar13[1], (longlong ****)*ppplVar6 != pppplVar13)) goto LAB_140005875;
        *ppplVar6 = (longlong **)ppplVar2;
        ppplVar2[1] = (longlong **)ppplVar6;
        ExFreePoolWithTag(pppplVar13,0);
      }
    }
  }
LAB_14000583a:
  do {
    pppplVar13 = local_68;
    if ((longlong *****)local_68 == &local_68) goto LAB_14000587c;
    pppplVar15 = local_68;
    if (((longlong *****)local_68[1] != &local_68) ||
       (pppplVar7 = (longlong ****)*local_68, (longlong ****)pppplVar7[1] != local_68)) break;
    pppplVar7[1] = (longlong ***)&local_68;
    local_68 = pppplVar7;
    ExFreePoolWithTag(pppplVar13,0);
  } while( true );
LAB_140005875:
  local_68 = pppplVar15;
  pcVar8 = (code *)swi(0x29);
  (*pcVar8)(3);
  puVar17 = auStackY_a0;
LAB_14000587c:
  if (lVar12 != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x14000588d;
    ExFreePoolWithTag(lVar12,0);
  }
  return;
}



===== TcpipRegEnumerateRegInterfaceKeys @ 1400058b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TcpipRegEnumerateRegInterfaceKeys(void)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 *local_b0;
  undefined4 local_a8 [2];
  longlong local_a0;
  longlong local_98;
  undefined8 uStack_90;
  longlong local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  longlong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a0 = 0;
  local_74 = 0;
  local_5c = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8[0] = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_38 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar3 = MALLOC(0x200);
  if (lVar3 != 0) {
    RtlInitUnicodeString
              (&local_98,
               L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces"
              );
    local_68 = &local_98;
    local_78 = 0x30;
    local_70 = 0;
    local_60 = 0x240;
    local_58 = 0;
    uStack_50 = 0;
    iVar1 = ZwOpenKey(&local_a0,0x20019,&local_78);
    if (-1 < iVar1) {
      local_b0 = local_a8;
      local_b8 = 0x200;
      iVar1 = 0;
      iVar2 = ZwEnumerateKey(local_a0,0,0,lVar3);
      while (iVar2 != -0x7fffffe6) {
        if (-1 < iVar2) {
          *(undefined2 *)(lVar3 + 0x10 + (ulonglong)(*(uint *)(lVar3 + 0xc) >> 1) * 2) = 0;
          RtlInitUnicodeString(&local_88,lVar3 + 0x10);
          iVar2 = RtlGUIDFromString(&local_88,&local_28);
          if (iVar2 < 0) break;
          RtlAcquireWriteLock();
          iVar2 = TcpipRegCreateIpInterface(&local_28,'\x01','\x01',&local_30);
          KeReleaseInStackQueuedSpinLock(&local_48);
          if (iVar2 < 0) break;
        }
        local_b0 = local_a8;
        iVar1 = iVar1 + 1;
        local_b8 = 0x200;
        iVar2 = ZwEnumerateKey(local_a0,iVar1,0,lVar3);
      }
    }
    if (local_a0 != 0) {
      ZwClose();
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return;
}



===== TcpipRegFindIpInterfaceByLuid @ 140005ad0 =====

undefined8 * TcpipRegFindIpInterfaceByLuid(longlong *param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = KfRaiseIrql(2);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  DAT_14000df28 = DAT_14000df28 + 1;
  UNLOCK();
  cVar2 = KeTestSpinLock(&InterfaceListLock);
  if (cVar2 == '\0') {
    LOCK();
    DAT_14000df28 = DAT_14000df28 + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&InterfaceListLock,&local_28);
    LOCK();
    DAT_14000df28 = DAT_14000df28 + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  puVar3 = InterfaceListHead;
  do {
    puVar4 = (undefined8 *)0x0;
    if ((undefined8 **)puVar3 == &InterfaceListHead) {
LAB_140005b46:
      LOCK();
      DAT_14000df28 = DAT_14000df28 + -1;
      UNLOCK();
      KeLowerIrql(uVar1);
      return puVar4;
    }
    if (puVar3[4] == *param_1) {
      puVar4 = puVar3;
      goto LAB_140005b46;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== QueryCurrentState @ 140005bc0 =====

undefined8 * QueryCurrentState(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x38);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 0x38)) {
      return (undefined8 *)0x0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== TcpipRegRegistryKeyChangeCallback @ 140005bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TcpipRegRegistryKeyChangeCallback(uint *param_1)

{
  int iVar1;
  
  KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
  UpdateInProgress = 1;
  if (*param_1 < 2) {
    UpdateInProgress = 0;
    KeReleaseMutex(&TcpipRegUpdateInProgess,0);
    TcpipRegDereferenceNotificationObject((int *)param_1);
  }
  else {
    (**(code **)(param_1 + 0x10))(param_1);
    iVar1 = ZwNotifyChangeKey(*(undefined8 *)(param_1 + 2),0,param_1 + 4,1,param_1 + 0xc,4,
                              (char)param_1[0x12],0,0,1);
    UpdateInProgress = 0;
    KeReleaseMutex(&TcpipRegUpdateInProgess,0);
    if ((iVar1 != 0) && (iVar1 != 0x103)) {
      TcpipRegDereferenceNotificationObject((int *)param_1);
    }
  }
  return;
}



===== TcpipRegDereferenceNotificationObject @ 140005cf0 =====

void TcpipRegDereferenceNotificationObject(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    KeSetEvent(param_1 + 0x14,0,0);
  }
  return;
}



===== StringCchLengthW @ 140005d30 =====

HRESULT __stdcall StringCchLengthW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  size_t sVar1;
  HRESULT HVar2;
  
  if ((psz == (STRSAFE_PCNZWCH)0x0) || (sVar1 = cchMax, 0x7fffffff < cchMax)) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    for (; (sVar1 != 0 && (*psz != L'\0')); psz = psz + 1) {
      sVar1 = sVar1 - 1;
    }
    HVar2 = -0x7ff8ffa9;
    if (sVar1 != 0) {
      HVar2 = 0;
    }
    if (pcchLength != (size_t *)0x0) {
      if (sVar1 == 0) {
        *pcchLength = 0;
      }
      else {
        *pcchLength = cchMax - sVar1;
      }
    }
    if (sVar1 != 0) {
      return HVar2;
    }
  }
  if (pcchLength != (size_t *)0x0) {
    *pcchLength = 0;
  }
  return HVar2;
}



===== TcpipRegCreateIpInterface @ 140005db0 =====

undefined4
TcpipRegCreateIpInterface(longlong *param_1,char param_2,char param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 *_Dst;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  
  _Dst = (undefined8 *)0x0;
  uVar9 = 0;
  uVar8 = 0;
  do {
    if (TcpipRegNdisInterfaceCount <= uVar8) {
LAB_140005ecd:
      if (uVar8 == TcpipRegNdisInterfaceCount) {
        uVar9 = 0xc0000225;
      }
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = _Dst;
      }
      return uVar9;
    }
    uVar11 = (ulonglong)uVar8;
    lVar10 = uVar11 * 0x238;
    if (param_2 == '\0') {
      if (*param_1 == *(longlong *)(uVar11 * 8 + TcpipRegNdisInterfaceLuidArray))
      goto LAB_140005e38;
    }
    else {
      lVar6 = *param_1 - *(longlong *)(TcpipRegNdisInterfaceRosArray + 0x218 + lVar10);
      if (lVar6 == 0) {
        lVar6 = param_1[1] - *(longlong *)(TcpipRegNdisInterfaceRosArray + 0x220 + lVar10);
      }
      if (lVar6 == 0) {
LAB_140005e38:
        _Dst = (undefined8 *)MALLOC(0x90);
        if (_Dst == (undefined8 *)0x0) {
          uVar9 = 0xc000009a;
        }
        else {
          memset(_Dst,0,0x90);
          lVar6 = TcpipRegNdisInterfaceLuidArray;
          puVar1 = (undefined4 *)(lVar10 + 0x218 + TcpipRegNdisInterfaceRosArray);
          uVar3 = puVar1[1];
          uVar4 = puVar1[2];
          uVar5 = puVar1[3];
          *(undefined4 *)(_Dst + 2) = *puVar1;
          *(undefined4 *)((longlong)_Dst + 0x14) = uVar3;
          *(undefined4 *)(_Dst + 3) = uVar4;
          *(undefined4 *)((longlong)_Dst + 0x1c) = uVar5;
          _Dst[4] = *(undefined8 *)(uVar11 * 8 + lVar6);
          if (param_3 != '\0') {
            puVar7 = &InterfaceListHead;
            if ((undefined8 *)*DAT_14000df18 != &InterfaceListHead) {
              puVar7 = (undefined8 *)0x3;
              pcVar2 = (code *)swi(0x29);
              DAT_14000df18 = (undefined8 *)(*pcVar2)();
            }
            *_Dst = puVar7;
            _Dst[1] = DAT_14000df18;
            *DAT_14000df18 = _Dst;
            DAT_14000df18 = _Dst;
          }
        }
        goto LAB_140005ecd;
      }
    }
    uVar8 = uVar8 + 1;
  } while( true );
}



===== IsValueUnChanged @ 140005f10 =====

longlong IsValueUnChanged(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  uint7 uVar2;
  
  uVar1 = 0;
  while( true ) {
    uVar2 = (uint7)(uVar1 >> 8);
    if (param_2 <= (uint)uVar1) {
      return CONCAT71(uVar2,1);
    }
    if (*(char *)(uVar1 + param_1) != -1) break;
    uVar1 = (ulonglong)((uint)uVar1 + 1);
  }
  return (ulonglong)uVar2 << 8;
}



===== InterfaceLinkLocalAddressPrefixChangeHandler @ 140005f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InterfaceLinkLocalAddressPrefixChangeHandler
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
              longlong param_5)

{
  int iVar1;
  void *_Src;
  size_t _Size;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  uint local_50 [4];
  undefined1 local_40 [44];
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  if (param_5 != 0) {
    _Size = 0x2c;
    local_14 = 0x30;
    if (*(uint *)(param_5 + 0x18) < 0x2d) {
      _Size = (size_t)*(uint *)(param_5 + 0x18);
    }
    _Src = (void *)(param_5 + 0x1c);
    memmove(local_40,_Src,_Size);
    param_2 = CONCAT71((int7)((ulonglong)_Src >> 8),1);
    iVar1 = RtlIpv4StringToAddressW(local_40,param_2,&local_58,local_50);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = Ipv4AddressType(local_50);
    if (iVar1 != 1) {
      return -0x3ffffff3;
    }
  }
  iVar1 = InterfaceLinkLocalConfigurationChangeHandler(param_1,param_2,param_3,param_5,local_50);
  return iVar1;
}



===== TcpipRegStartNac @ 140006020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStartNac(void)

{
  int iVar1;
  
  TcpipRegNaProviderReference = 1;
  iVar1 = NmrRegisterClient(&TcpipRegNaClientNotify,0,&TcpipRegNaClientHandle);
  if (-1 < iVar1) {
    LOCK();
    TcpipRegReferenceCount = TcpipRegReferenceCount + 1;
    UNLOCK();
    _TcpipRegInitializedFlags = _TcpipRegInitializedFlags | 1;
  }
  return;
}



===== GetCurrentPrefixLength @ 140006070 =====

undefined8 GetCurrentPrefixLength(longlong param_1,byte *param_2)

{
  undefined8 uVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    return 0xc000000d;
  }
  uVar1 = RtlIpv4StringToAddressW();
  if (-1 < (int)uVar1) {
    bVar2 = 0;
    do {
      if ((0U >> (0x1f - bVar2 & 0x1f) & 1) == 0) break;
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x20);
    *param_2 = bVar2;
    uVar1 = 0;
  }
  return uVar1;
}



===== StringCbLengthW @ 1400060e0 =====

HRESULT __stdcall StringCbLengthW(STRSAFE_PCNZWCH psz,size_t cbMax,size_t *pcbLength)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  uVar3 = cbMax >> 1;
  lVar4 = 0;
  if ((psz == (STRSAFE_PCNZWCH)0x0) || (uVar1 = uVar3, 0x7fffffff < uVar3)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    for (; (uVar1 != 0 && (*psz != L'\0')); psz = psz + 1) {
      uVar1 = uVar1 - 1;
    }
    iVar2 = -0x7ff8ffa9;
    if (uVar1 != 0) {
      iVar2 = 0;
    }
    lVar4 = uVar3 - uVar1;
    if (uVar1 == 0) {
      lVar4 = 0;
    }
  }
  if (pcbLength != (size_t *)0x0) {
    if (-1 < iVar2) {
      *pcbLength = lVar4 * 2;
      return iVar2;
    }
    *pcbLength = 0;
  }
  return iVar2;
}



===== TcpipRegReallocateGuidLuidMapping @ 140006150 =====

undefined8 TcpipRegReallocateGuidLuidMapping(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *_Src;
  void *_Src_00;
  uint uVar5;
  ulonglong uVar6;
  void *_Dst;
  void *_Dst_00;
  undefined8 uVar7;
  uint uVar8;
  
  uVar5 = TcpipRegNdisInterfaceCount;
  _Src_00 = TcpipRegNdisInterfaceRosArray;
  _Src = TcpipRegNdisInterfaceLuidArray;
  uVar8 = TcpipRegNdisInterfaceCount + 1;
  uVar6 = (ulonglong)uVar8 * 0x238;
  if (uVar6 < 0x100000000) {
    _Dst = (void *)MALLOC(uVar6 & 0xffffffff);
    if (_Dst != (void *)0x0) {
      uVar6 = (ulonglong)uVar8 * 8;
      if (0xffffffff < uVar6) goto LAB_14000627d;
      _Dst_00 = (void *)MALLOC(uVar6 & 0xffffffff);
      uVar8 = TcpipRegNdisInterfaceCount;
      if (_Dst_00 != (void *)0x0) {
        uVar6 = (ulonglong)TcpipRegNdisInterfaceCount;
        memmove(_Dst,_Src_00,uVar6 * 0x238);
        memmove(_Dst_00,_Src,uVar6 * 8);
        uVar2 = param_2[1];
        uVar3 = param_2[2];
        uVar4 = param_2[3];
        TcpipRegNdisInterfaceCount = uVar8 + 1;
        puVar1 = (undefined4 *)((ulonglong)uVar5 * 0x238 + 0x218 + (longlong)_Dst);
        TcpipRegNdisInterfaceLuidArray = _Dst_00;
        TcpipRegNdisInterfaceRosArray = _Dst;
        *puVar1 = *param_2;
        puVar1[1] = uVar2;
        puVar1[2] = uVar3;
        puVar1[3] = uVar4;
        *(undefined8 *)((longlong)_Dst_00 + (ulonglong)uVar5 * 8) = *param_1;
        if (_Src != (void *)0x0) {
          ExFreePoolWithTag(_Src,0);
        }
        if (_Src_00 != (void *)0x0) {
          ExFreePoolWithTag(_Src_00,0);
        }
        return 0;
      }
      ExFreePoolWithTag(_Dst,0);
    }
    uVar7 = 0xc000009a;
  }
  else {
LAB_14000627d:
    uVar7 = 0xc000000d;
  }
  return uVar7;
}



===== StringCbPrintfW @ 1400062b0 =====

HRESULT __stdcall
StringCbPrintfW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszFormat,...)

{
  int iVar1;
  HRESULT HVar2;
  ulonglong uVar3;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar3 = cbDest >> 1;
  if (uVar3 - 1 < 0x7fffffff) {
    uVar3 = uVar3 - 1;
    HVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf(pszDest,uVar3,pszFormat,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar3 < (ulonglong)(longlong)iVar1)) {
      pszDest[uVar3] = L'\0';
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 == uVar3) {
      pszDest[uVar3] = L'\0';
    }
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (uVar3 != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== StringCchPrintfW @ 140006340 =====

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
      pszDest[_Count] = L'\0';
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 == _Count) {
      pszDest[_Count] = L'\0';
    }
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== RtlAcquireWriteLock @ 1400063d0 =====

void RtlAcquireWriteLock(void)

{
  KeAcquireInStackQueuedSpinLock(&InterfaceListLock);
  do {
  } while (DAT_14000df28 != 0);
  return;
}



===== __report_gsfailure @ 140006410 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DriverEntry @ 140006420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  iVar1 = wil_InitializeFeatureStaging();
  if (-1 < iVar1) {
    _WPP_MAIN_CB = 0;
    DAT_14000de08 = &WPP_ThisDir_CTLGUID_NETIO;
    DAT_14000de10 = 0;
    _DAT_14000de20 = 0;
    _DAT_14000de28 = 1;
    WppLoadTracingSupport();
    _DAT_14000de20 = 0;
    WppInitKm();
    *(code **)(param_1 + 0x68) = TcpipRegUnload;
    KeInitializeEvent(&TcpipRegAllowUnloadEvent,0,0);
    KeInitializeMutex(&TcpipRegUpdateInProgess,0);
    DAT_14000de98 = &DeletedInterface;
    DeletedInterface = &DeletedInterface;
    LOCK();
    TcpipRegReferenceCount = TcpipRegReferenceCount + 1;
    UNLOCK();
    puVar2 = &TcpipRegInitializedFlags;
    iVar1 = RtlInvokeStartRoutines(&TcpipRegStartStopRoutines,4);
    if (iVar1 < 0) {
      TcpipRegDereferenceDriver();
      uVar3 = 0;
      KeWaitForSingleObject(&TcpipRegAllowUnloadEvent,0,0,0,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (WPP_GLOBAL_Control[0x29] != '\0')) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,uVar3,iVar1);
      }
      WppCleanupKm();
      wil_UninitializeFeatureStaging();
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,puVar2,iVar1);
    }
  }
  return iVar1;
}



===== TcpipRegCleanupResources @ 14000659c =====

void TcpipRegCleanupResources(void)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  puVar8 = auStack_38;
  uVar7 = 0;
LAB_1400065c7:
  do {
    if (uVar7 == 0) {
      if (DAT_14000df48 != 0) {
        local_18 = 0;
        KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0);
        UpdateInProgress = 1;
        ZwClose(DAT_14000df48);
        TcpipRegDereferenceNotificationObject((int *)&TcpipGlobalKeyNotification);
        UpdateInProgress = 0;
        KeReleaseMutex(&TcpipRegUpdateInProgess);
        local_18 = 0;
        KeWaitForSingleObject(&DAT_14000df90);
        goto LAB_140006783;
      }
    }
    else {
      if (uVar7 == 1) {
        while (puVar6 = InterfaceListHead, (undefined8 **)InterfaceListHead != &InterfaceListHead) {
          if (((undefined8 **)InterfaceListHead[1] != &InterfaceListHead) ||
             (puVar4 = (undefined8 *)*InterfaceListHead,
             (undefined8 *)puVar4[1] != InterfaceListHead)) goto LAB_14000691d;
          InterfaceListHead = puVar4;
          puVar4[1] = &InterfaceListHead;
          if (puVar6[6] != 0) {
            local_18 = 0;
            KeWaitForSingleObject(&TcpipRegUpdateInProgess);
            UpdateInProgress = 1;
            ZwClose(puVar6[6]);
            TcpipRegDereferenceNotificationObject((int *)(puVar6 + 5));
            UpdateInProgress = 0;
            KeReleaseMutex(&TcpipRegUpdateInProgess);
            local_18 = 0;
            KeWaitForSingleObject(puVar6 + 0xf);
          }
          ExFreePoolWithTag(puVar6);
        }
LAB_140006783:
        uVar7 = uVar7 + 1;
        goto LAB_1400065c7;
      }
      if (uVar7 == 2) {
        if (DAT_14000dfc8 != 0) {
          local_18 = 0;
          KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0);
          UpdateInProgress = 1;
          ZwClose(DAT_14000dfc8);
          TcpipRegDereferenceNotificationObject((int *)&TcpipPersistentRoutesKeyNotification);
          UpdateInProgress = 0;
          KeReleaseMutex(&TcpipRegUpdateInProgess,0);
          local_18 = 0;
          KeWaitForSingleObject(&DAT_14000e010,0,0,0);
          goto LAB_140006818;
        }
        break;
      }
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 3);
LAB_1400065e6:
  uVar7 = 0;
  do {
    while (plVar1 = *(longlong **)(&DAT_14000d428 + (ulonglong)uVar7 * 0x48),
          plVar1 != (longlong *)(&DAT_14000d428 + (ulonglong)uVar7 * 0x48)) {
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) goto LAB_14000691d;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag();
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x20);
  uVar7 = 0;
  do {
    while (plVar1 = (longlong *)(&DAT_14000d038)[(ulonglong)uVar7 * 9],
          plVar1 != &DAT_14000d038 + (ulonglong)uVar7 * 9) {
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) goto LAB_14000691d;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag();
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0xe);
  while (puVar6 = DeletedInterface, (undefined8 **)DeletedInterface != &DeletedInterface) {
    if (((undefined8 **)DeletedInterface[1] != &DeletedInterface) ||
       (puVar4 = (undefined8 *)*DeletedInterface, (undefined8 *)puVar4[1] != DeletedInterface))
    goto LAB_14000691d;
    DeletedInterface = puVar4;
    puVar4[1] = &DeletedInterface;
    if (puVar6[6] != 0) {
      local_18 = 0;
      KeWaitForSingleObject(puVar6 + 0xf,0,0,0);
    }
    ExFreePoolWithTag(puVar6);
  }
LAB_140006924:
  if (TcpipRegNdisInterfaceLuidArray != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x140006939;
    ExFreePoolWithTag(TcpipRegNdisInterfaceLuidArray,0);
  }
  if (TcpipRegNdisInterfaceRosArray != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x140006953;
    ExFreePoolWithTag(TcpipRegNdisInterfaceRosArray,0);
  }
  return;
LAB_140006818:
  puVar6 = DAT_14000df38;
  if ((undefined8 **)PersistentRoutesListHead == &PersistentRoutesListHead) goto LAB_1400065e6;
  if (((undefined8 **)*DAT_14000df38 != &PersistentRoutesListHead) ||
     (puVar4 = (undefined8 *)DAT_14000df38[1], (undefined8 *)*puVar4 != DAT_14000df38))
  goto LAB_14000691d;
  DAT_14000df38 = puVar4;
  *puVar4 = &PersistentRoutesListHead;
  ExFreePoolWithTag(puVar6,0);
  goto LAB_140006818;
LAB_14000691d:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar8 = auStack_30;
  goto LAB_140006924;
}



===== TcpipRegDereferenceDriver @ 14000697c =====

void TcpipRegDereferenceDriver(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = TcpipRegReferenceCount + -1;
  UNLOCK();
  bVar2 = TcpipRegReferenceCount == 1;
  TcpipRegReferenceCount = iVar1;
  if (bVar2) {
    KeSetEvent(&TcpipRegAllowUnloadEvent,0,0);
  }
  return;
}



===== TcpipRegInitializePersistentRoutesNotification @ 1400069b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TcpipRegInitializePersistentRoutesNotification(void)

{
  int iVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  DAT_14000e008 = 0;
  local_1c = 0;
  local_34 = 0;
  _TcpipPersistentRoutesKeyNotification = 1;
  DAT_14000df38 = &PersistentRoutesListHead;
  PersistentRoutesListHead = &PersistentRoutesListHead;
  _DAT_14000e000 = TcpipRegPersistentRoutesKeyChangeCallback;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&DAT_14000e010,0,0);
  _DAT_14000dfd0 = 0;
  _DAT_14000dfe0 = TcpipRegRegistryKeyChangeCallback;
  _DAT_14000dfe8 = &TcpipPersistentRoutesKeyNotification;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Persistentroutes"
            );
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&DAT_14000dfc8,0x2001f,&local_38);
  if (-1 < iVar1) {
    LOCK();
    _TcpipPersistentRoutesKeyNotification = _TcpipPersistentRoutesKeyNotification + 1;
    UNLOCK();
    iVar1 = ZwNotifyChangeKey(DAT_14000dfc8,0,&DAT_14000dfd0,1,&DAT_14000dff0,4,DAT_14000e008,0,0,1)
    ;
    if (iVar1 < 0) {
      TcpipRegDereferenceNotificationObject((int *)&TcpipPersistentRoutesKeyNotification);
    }
    KeWaitForSingleObject(&TcpipRegUpdateInProgess,0,0,0,0);
    UpdateInProgress = 1;
    TcpipRegPersistentRoutesKeyChangeCallback(0x14000dfc0);
    UpdateInProgress = 0;
    KeReleaseMutex(&TcpipRegUpdateInProgess,0);
  }
  return iVar1;
}



===== TcpipRegNacAttachNaProvider @ 140006b80 =====

undefined8 TcpipRegNacAttachNaProvider(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x18,0x6547654c);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = param_1;
    uVar2 = NmrClientAttachProvider(param_1,puVar1,&TcpipRegNaClientDispatch,puVar1,puVar1 + 1);
    if (-1 < (int)uVar2) {
      TcpipRegNaProviderReference = 2;
      TcpipRegNaProviderContext = puVar1;
    }
  }
  return uVar2;
}



===== TcpipRegNacCleanupNaProviderContext @ 140006c10 =====

void TcpipRegNacCleanupNaProviderContext(undefined8 param_1)

{
  TcpipRegNaProviderContext = 0;
  TcpipRegNaProviderBindingHandle = 0;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== TcpipRegNacDetachNaProvider @ 140006c40 =====

uint TcpipRegNacDetachNaProvider(longlong param_1)

{
  int iVar1;
  
  iVar1 = TcpipRegNaProviderReference;
  TcpipRegNaProviderBindingHandle = *(undefined8 *)(param_1 + 0x10);
  LOCK();
  TcpipRegNaProviderReference = TcpipRegNaProviderReference + -1;
  UNLOCK();
  return -(uint)(iVar1 != 2) & 0x103;
}



===== TcpipRegStartNsiCallback @ 140006c70 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStartNsiCallback(void)

{
  int iVar1;
  
  iVar1 = NsiRegisterLegacyHandler(TcpipRegUpdateRegistryValue);
  if (-1 < iVar1) {
    _TcpipRegInitializedFlags = _TcpipRegInitializedFlags | 8;
  }
  return;
}



===== TcpipRegStopInterfaceNotification @ 140006ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStopInterfaceNotification(void)

{
  int iVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined4 local_28;
  undefined4 local_24;
  longlong local_20;
  undefined4 local_18;
  
  _TcpipRegInitializedFlags = _TcpipRegInitializedFlags & 0xfffffffffffffffd;
  local_34 = 0;
  local_24 = 0;
  local_18 = 0;
  if (TcpipRegIpv4NotificationHandle != 0) {
    uVar2 = RoReferenceEx();
    if ((char)uVar2 != '\0') {
      local_28 = 7;
      local_30 = &NPI_MS_IPV4_MODULEID;
      local_38 = TcpipRegIpv4ProviderModuleHandle;
      local_20 = TcpipRegIpv4NotificationHandle;
      (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x48))(&local_38);
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar3 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar3) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
    }
  }
  return;
}



===== TcpipRegStopNac @ 140006d40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStopNac(void)

{
  NmrDeregisterClient(TcpipRegNaClientHandle);
  NmrWaitForClientDeregisterComplete(TcpipRegNaClientHandle);
  _TcpipRegInitializedFlags = _TcpipRegInitializedFlags & 0xfffffffffffffffe;
  TcpipRegCleanupResources();
  TcpipRegDereferenceDriver();
  return;
}



===== TcpipRegStopNsiCallback @ 140006d90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStopNsiCallback(void)

{
  NsiDeregisterLegacyHandler(TcpipRegUpdateRegistryValue);
  _TcpipRegInitializedFlags = _TcpipRegInitializedFlags & 0xfffffffffffffff7;
  return;
}



===== TcpipRegStopRegistryKeyNotification @ 140006dc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TcpipRegStopRegistryKeyNotification(void)

{
  _TcpipRegInitializedFlags = _TcpipRegInitializedFlags & 0xfffffffffffffffb;
  return;
}



===== TcpipRegUnload @ 140006dd0 =====

void TcpipRegUnload(void)

{
  RtlInvokeStopRoutines(&TcpipRegStartStopRoutines,4,&TcpipRegInitializedFlags);
  TcpipRegDereferenceDriver();
  KeWaitForSingleObject(&TcpipRegAllowUnloadEvent,0,0,0,0);
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return;
}



===== WPP_SF_D @ 140006e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1342e911822e31456cb1a6707b82e583_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140006e80 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140006eb4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000c977 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140006edc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  bool bVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  short local_44 [2];
  undefined4 local_40 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = *param_2;
  do {
    LOCK();
    uVar4 = *param_2;
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    uVar4 = uVar3 & ~uVar4;
  }
  puVar5 = &local_48;
  if ((uVar4 & 1) != 0) {
    puVar5 = local_40;
    local_44[0] = 2;
    local_44[1] = 1;
    local_48 = param_1;
  }
  if ((uVar4 & 2) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10006;
    puVar5 = puVar5 + 2;
  }
  if ((uVar4 & 4) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10003;
    puVar5 = puVar5 + 2;
  }
  if (7 < uVar4) {
    *puVar5 = param_1;
    puVar5[1] = 0x10007;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 5 & 0x1ff) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 5) & 0x1ff;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0xe) & 1) << 2;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 0xf & 0x7f) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 0xf) & 0x7f;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0x16) & 1) * 4 + 1;
    puVar5 = puVar5 + 2;
  }
  lVar6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < lVar6) {
    RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140007030 =====

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack0000000000000028;
  undefined2 in_stack_0000002c;
  undefined2 in_stack_0000002e;
  
  iVar2 = g_wil_details_featureUsageCached;
  piVar1 = (int *)CONCAT26(in_stack_0000002e,CONCAT24(in_stack_0000002c,uStack0000000000000028));
  if (*piVar1 != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar2 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (piVar1[1] != 0) {
    in_stack_0000002c = (undefined2)piVar1[2];
    in_stack_0000002e = (undefined2)piVar1[1];
    uStack0000000000000028 = param_1;
    RtlRecordFeatureUsage(&uStack0000000000000028,1);
  }
  return;
}



===== Feature_5371_3825__private_IsEnabledDeviceUsageNoInline @ 1400070b4 =====

ulonglong Feature_5371_3825__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_5371_3825__private_featureState;
  if ((Feature_5371_3825__private_featureState & 0x10) == 0) {
    uVar1 = Feature_5371_3825__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_5371_3825__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_5371_3825__private_IsEnabledFallback @ 1400070ec =====

void Feature_5371_3825__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== GetCurrentMetric @ 140007104 =====

undefined8 GetCurrentMetric(ushort *param_1,undefined4 *param_2,undefined8 *param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  if (param_1 == (ushort *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    do {
      uVar1 = *param_1;
      if (9 < (ushort)(uVar1 - 0x30)) goto LAB_140007156;
      param_1 = param_1 + 1;
      uVar3 = (ulonglong)uVar1 + (uVar3 * 5 + -0x18) * 2;
    } while (uVar3 < 0xffffffff);
    uVar3 = 0xffffffff;
    uVar2 = 0xc0000095;
LAB_140007156:
    *param_3 = param_1;
    *param_2 = (int)uVar3;
  }
  return uVar2;
}



===== InterfaceDefaultGatewayMetricRegKeyChangeHandler @ 140007180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InterfaceDefaultGatewayMetricRegKeyChangeHandler
              (longlong param_1,longlong param_2,undefined8 *param_3,undefined8 param_4,
              longlong param_5)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort *puVar6;
  short *psVar7;
  bool bVar8;
  undefined1 auStack_f8 [32];
  int local_d8 [2];
  short *local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined4 local_a4;
  undefined8 *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  int *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  iVar2 = 0;
  memset(&local_c8,0,0x50);
  local_d8[0] = 0;
  local_d0 = (short *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_5 == 0) ||
     (puVar3 = QueryCurrentState(0x14000d168,param_2), puVar3 == (undefined8 *)0x0)) {
    return 0;
  }
  psVar7 = (short *)((longlong)puVar3 + 0x1c);
  puVar6 = (ushort *)(param_5 + 0x1c);
  uVar4 = RoReferenceEx();
  if ((char)uVar4 == '\0') {
    return -0x3fffffaa;
  }
  do {
    if (*psVar7 == 0) {
LAB_140007313:
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar8 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar8) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
      return iVar2;
    }
    uStack_60 = *param_3;
    local_78 = 0;
    uStack_50 = 0;
    uStack_70 = 0;
    local_68 = 0;
    local_58 = uStack_60;
    iVar2 = RtlIpv4StringToAddressW(psVar7,1,&local_d0,&uStack_50);
    if (iVar2 < 0) goto LAB_140007313;
    if (*local_d0 != 0) {
      iVar2 = -0x3ffffff3;
      goto LAB_140007313;
    }
    psVar7 = local_d0 + 1;
    uVar5 = GetCurrentMetric(puVar6,local_d8,&local_d0);
    iVar2 = (int)uVar5;
    if (iVar2 < 0) goto LAB_140007313;
    puVar6 = (ushort *)(local_d0 + 1);
    if (local_d8[0] == 0) {
      local_d8[0] = -1;
    }
    local_c0 = 0;
    local_a0 = &local_78;
    local_b8 = *(undefined8 *)(param_1 + 8);
    local_b0 = *(undefined4 *)(param_1 + 0x10);
    local_88 = local_d8;
    local_ac = 0;
    local_98 = 0x30;
    local_90 = 0;
    local_c8 = 0;
    local_a4 = 0;
    local_80 = 4;
    local_7c = 0xc;
    iVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_c8);
  } while( true );
}



===== InterfaceLinkLocalAddressChangeHandler @ 140007370 =====

undefined8 InterfaceLinkLocalAddressChangeHandler(void)

{
  return 0xc000000d;
}



===== InterfaceLinkLocalAddressPrefixLengthChangeHandler @ 140007380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

NTSTATUS InterfaceLinkLocalAddressPrefixLengthChangeHandler
                   (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                   longlong param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  NTSTATUS NVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  size_t _Size;
  bool bVar7;
  undefined1 auStack_f8 [32];
  byte local_d8 [4];
  uint local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_a4;
  longlong local_a0;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 ***local_78;
  undefined8 ***local_70;
  undefined8 local_68;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_58 [44];
  undefined2 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d4 = 0;
  local_d8[0] = 0;
  local_d0 = 0;
  local_bc = 0;
  local_ac = 0;
  local_94 = 0;
  local_8c = 0;
  if (param_5 == 0) {
    puVar6 = (undefined4 *)0x18;
    local_88 = (uint *)0x1c;
  }
  else {
    local_70 = &local_78;
    _Size = 0x2c;
    local_78 = &local_78;
    local_60 = 4;
    local_2c = 0x30;
    if (*(uint *)(param_5 + 0x18) < 0x2d) {
      _Size = (size_t)*(uint *)(param_5 + 0x18);
    }
    local_68 = param_2;
    memmove(local_58,(void *)(param_5 + 0x1c),_Size);
    iVar2 = RtlIpv4StringToAddressW(local_58,1,&local_d0,&local_d4);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_d4 != 0xffffffff) {
      uVar3 = ~(local_d4 >> 0x18 | (local_d4 & 0xff0000) >> 8 | (local_d4 & 0xff00) << 8 |
               local_d4 << 0x18);
      uVar1 = uVar3 + 1;
      if ((uVar1 == 0) || ((uVar3 & uVar1) != 0)) {
        return -0x3ffffff3;
      }
    }
    NVar4 = ConvertIpv4MaskToLength(local_d4,local_d8);
    if (NVar4 < 0) {
      return NVar4;
    }
    puVar6 = &local_60;
    local_5c = (uint)local_d8[0];
    local_88 = &local_5c;
  }
  local_c8 = 0;
  local_a8 = 0;
  local_98 = -(uint)(param_3 != 0) & 8;
  local_c0 = 0;
  local_90 = 0;
  local_b8 = *(undefined8 *)(param_1 + 8);
  local_b0 = *(undefined4 *)(param_1 + 0x10);
  local_a4 = 3 - (uint)(param_5 != 0);
  if (param_5 == 0) {
    local_88 = (uint *)0x0;
    local_80 = 0;
  }
  else {
    local_80 = *puVar6;
  }
  local_7c = *(undefined4 *)(param_1 + 0x14);
  local_a0 = param_3;
  uVar5 = RoReferenceEx();
  if ((char)uVar5 == '\0') {
    NVar4 = -0x3fffffaa;
  }
  else {
    NVar4 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_c8);
    LOCK();
    iVar2 = TcpipRegNaProviderReference + -2;
    UNLOCK();
    bVar7 = TcpipRegNaProviderReference == 3;
    TcpipRegNaProviderReference = iVar2;
    if (bVar7) {
      NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
    }
  }
  return NVar4;
}



===== InterfaceLinkLocalConfigurationChangeHandler @ 140007568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
InterfaceLinkLocalConfigurationChangeHandler
          (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4,undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  int local_34;
  longlong local_30;
  uint local_28;
  undefined8 local_24;
  undefined4 local_1c;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_50 = 0;
  local_3c = 0;
  local_24 = 0;
  local_1c = 0;
  local_28 = -(uint)(param_3 != 0) & 8;
  local_58 = 0;
  local_48 = *(undefined8 *)(param_1 + 8);
  local_40 = *(undefined4 *)(param_1 + 0x10);
  local_34 = 3 - (uint)(param_4 != 0);
  local_c = *(undefined4 *)(param_1 + 0x14);
  if (param_4 == 0) {
    local_18 = 0;
    local_10 = 0;
  }
  else {
    local_18 = param_5;
    local_10 = 8;
  }
  local_30 = param_3;
  uVar3 = RoReferenceEx();
  if ((char)uVar3 == '\0') {
    uVar2 = 0xc0000056;
  }
  else {
    uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_58);
    LOCK();
    iVar1 = TcpipRegNaProviderReference + -2;
    UNLOCK();
    bVar4 = TcpipRegNaProviderReference == 3;
    TcpipRegNaProviderReference = iVar1;
    if (bVar4) {
      NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
    }
  }
  return uVar2;
}



===== InterfaceSubnetMaskRegKeyChangeHandler @ 140007650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InterfaceSubnetMaskRegKeyChangeHandler
              (longlong param_1,longlong param_2,undefined8 *param_3,undefined8 param_4,
              longlong param_5)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  short *psVar7;
  bool bVar8;
  undefined1 auStack_e8 [32];
  byte local_c8 [8];
  short *local_c0;
  longlong local_b8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_8c;
  undefined4 local_84;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 local_70;
  byte *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  iVar2 = 0;
  memset(&local_a8,0,0x50);
  local_c8[0] = 0;
  local_c0 = (short *)0x0;
  local_b8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_5 == 0) ||
     (puVar3 = QueryCurrentState(0x14000d000,param_2), puVar3 == (undefined8 *)0x0)) {
    return 0;
  }
  psVar7 = (short *)((longlong)puVar3 + 0x1c);
  lVar6 = param_5 + 0x1c;
  uVar4 = RoReferenceEx();
  if ((char)uVar4 == '\0') {
    return -0x3fffffaa;
  }
  do {
    if (*psVar7 == 0) {
LAB_1400077bc:
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar8 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar8) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
      return iVar2;
    }
    local_58 = *param_3;
    uStack_50 = 0;
    iVar2 = RtlIpv4StringToAddressW(psVar7,1,&local_c0,&uStack_50);
    if (iVar2 < 0) goto LAB_1400077bc;
    if (*local_c0 != 0) {
      iVar2 = -0x3ffffff3;
      goto LAB_1400077bc;
    }
    psVar7 = local_c0 + 1;
    uVar5 = GetCurrentPrefixLength(lVar6,local_c8);
    iVar2 = (int)uVar5;
    if (iVar2 < 0) goto LAB_1400077bc;
    local_80 = &local_58;
    lVar6 = local_b8 + 2;
    local_98 = *(undefined8 *)(param_1 + 8);
    local_90 = *(undefined4 *)(param_1 + 0x10);
    local_68 = local_c8;
    local_a0 = 0;
    local_8c = 0;
    local_78 = 0x10;
    local_70 = 0;
    local_a8 = 0;
    local_84 = 0;
    local_60 = 1;
    local_5c = 0x10;
    iVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_a8);
  } while( true );
}



===== Ipv4AddressType @ 14000780c =====

int Ipv4AddressType(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0xf0) == 0xe0) {
    return 3;
  }
  if (uVar1 == 0xffffffff) {
    return 4;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return (-(uint)((char)uVar1 != '\0' && (uVar1 & 0xf0) != 0xf0) & 0xfffffffc) + 5;
}



===== TcpDynamicPortRangeChangeHandler @ 140007860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TcpDynamicPortRangeChangeHandler(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined4 local_res8;
  longlong in_stack_00000028;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_48 = *(undefined8 *)(param_1 + 8);
  uVar2 = 0;
  local_40 = *(undefined4 *)(param_1 + 0x10);
  local_18 = &local_res8;
  local_10 = *(undefined4 *)(param_1 + 0x18);
  local_c = *(undefined4 *)(param_1 + 0x14);
  local_res8 = 0;
  local_9c = 0;
  local_8c = 0;
  local_74 = 0;
  local_6c = 0;
  local_50 = 0;
  local_3c = 0;
  local_28 = 0;
  local_20 = 0;
  local_30 = 0;
  local_58 = 0;
  local_34 = 0;
  iVar1 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x10))(&local_58);
  if (iVar1 < 0) {
    if (in_stack_00000028 == 0) {
      local_84 = 4;
    }
    else {
      if (0xfbfe < *(int *)(in_stack_00000028 + 0x1c) - 0x401U) {
        return 0xc000000d;
      }
      local_84 = 2;
      local_res8 = CONCAT22((short)*(int *)(in_stack_00000028 + 0x1c) + -0x3ff,4);
    }
    local_98 = *(undefined8 *)(param_1 + 8);
    local_90 = *(undefined4 *)(param_1 + 0x10);
    local_68 = &local_res8;
    local_60 = *(undefined4 *)(param_1 + 0x18);
    local_5c = *(undefined4 *)(param_1 + 0x14);
    local_88 = 1;
    local_80 = 0;
    local_78 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_70 = 0;
    uVar3 = RoReferenceEx();
    if ((char)uVar3 == '\0') {
      uVar2 = 0xc0000056;
    }
    else {
      uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_a8);
      LOCK();
      iVar1 = TcpipRegNaProviderReference + -2;
      UNLOCK();
      bVar4 = TcpipRegNaProviderReference == 3;
      TcpipRegNaProviderReference = iVar1;
      if (bVar4) {
        NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
      }
    }
  }
  return uVar2;
}



===== TcpGlobalRegKeyChangeHandler @ 1400079d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TcpGlobalRegKeyChangeHandler(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  bool bVar4;
  longlong in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_30 = &uStack0000000000000030;
  local_4c = 0;
  local_3c = 0;
  local_24 = 0;
  local_1c = 0;
  if (in_stack_00000028 == 0) {
    uVar2 = NsiClearPersistentSetting
                      (*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),local_30,2);
  }
  else {
    local_48 = *(undefined8 *)(param_1 + 8);
    local_40 = *(undefined4 *)(param_1 + 0x10);
    local_18 = in_stack_00000028 + 0x1c;
    local_10 = *(undefined4 *)(param_1 + 0x18);
    local_c = *(undefined4 *)(param_1 + 0x14);
    local_28 = 2;
    local_58 = 0;
    local_38 = 0;
    local_34 = 2;
    local_50 = 0;
    local_20 = 0;
    uVar3 = RoReferenceEx();
    if ((char)uVar3 == '\0') {
      return 0xc0000056;
    }
    uVar2 = (**(code **)(*(longlong *)(TcpipRegNaProviderContext + 8) + 0x18))(&local_58);
    LOCK();
    iVar1 = TcpipRegNaProviderReference + -2;
    UNLOCK();
    bVar4 = TcpipRegNaProviderReference == 3;
    TcpipRegNaProviderReference = iVar1;
    if (bVar4) {
      NmrClientDetachProviderComplete(TcpipRegNaProviderBindingHandle);
    }
  }
  return uVar2;
}



===== TcpGlobalTcpip4RegKeyChangeHandler @ 140007af0 =====

void TcpGlobalTcpip4RegKeyChangeHandler(longlong param_1)

{
  TcpGlobalRegKeyChangeHandler(param_1);
  return;
}



===== TcpGlobalTcpip6RegKeyChangeHandler @ 140007b20 =====

void TcpGlobalTcpip6RegKeyChangeHandler(longlong param_1)

{
  TcpGlobalRegKeyChangeHandler(param_1);
  return;
}



===== TcpTimestampsRegKeyChangeHandler @ 140007b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TcpTimestampsRegKeyChangeHandler(longlong param_1)

{
  longlong in_stack_00000028;
  undefined1 auStack_68 [32];
  undefined8 ***local_48;
  undefined2 local_40;
  undefined8 ***local_38;
  undefined8 ***local_30;
  undefined8 local_28;
  undefined4 local_20;
  uint local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (in_stack_00000028 == 0) {
    local_48 = (undefined8 ***)0x0;
  }
  else {
    local_28 = 0;
    local_30 = &local_38;
    local_48 = &local_38;
    local_38 = &local_38;
    local_1c = *(uint *)(in_stack_00000028 + 0x1c) >> 1 & 1;
    local_20 = 4;
  }
  local_40 = 2;
  TcpGlobalRegKeyChangeHandler(param_1);
  return;
}



===== TcpipRegGlobalRegistryKeyChangeCallback @ 140007be0 =====

void TcpipRegGlobalRegistryKeyChangeCallback(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  longlong lVar4;
  
  puVar3 = &GlobalRegKeyMappingTable;
  lVar4 = 0x20;
  do {
    TcpipRegQueryAndUpdateKeyValue(0,param_1,(longlong)puVar3);
    puVar3 = puVar3 + 0x48;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((Feature_5371_3825__private_featureState & 0x10) == 0) {
    uVar2 = Feature_5371_3825__private_IsEnabledDeviceUsageNoInline();
    uVar1 = (uint)uVar2;
  }
  else {
    uVar1 = Feature_5371_3825__private_featureState & 1;
  }
  if (uVar1 != 0) {
    NsiSetParameter(1,0,&NPI_MS_IPV4_MODULEID,0x22,0,0,0,0,0,0);
  }
  NsiSetParameter(1,0,&NPI_MS_IPV6_MODULEID,0x22,0,0,0,0,0,0);
  NsiSetParameter(1,0,&NPI_MS_TCP_MODULEID,0x24,0,0,0,0,0,0);
  return;
}



===== TcpipRegIsRouteAlreadyInNsiPersistentStore @ 140007cf0 =====

undefined1 TcpipRegIsRouteAlreadyInNsiPersistentStore(int *param_1,char param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 local_88 [16];
  undefined *local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60;
  undefined4 local_58;
  uint local_20;
  
  memset(local_88,0,0x70);
  lVar2 = 0;
  local_70 = 0x10;
  uVar5 = 0;
  uVar6 = 0;
  local_58 = 0x30;
  local_68 = 0;
  local_78 = &NPI_MS_IPV4_MODULEID;
  local_20 = 8;
  local_64 = 1;
  do {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    local_20 = local_20 * 2;
    lVar2 = MALLOC((ulonglong)local_20 * 0x30);
    local_60 = lVar2;
    iVar1 = NsiEnumerateObjectsAllParametersEx(local_88);
  } while (iVar1 == 0x105);
  if ((-1 < iVar1) && (local_20 != 0)) {
    piVar3 = (int *)(lVar2 + 4);
    uVar4 = (ulonglong)local_20;
    do {
      if (((char)piVar3[1] == param_2) && (*piVar3 == *param_1)) {
        uVar6 = uVar5;
        if (piVar3[9] == *param_3) {
          uVar6 = 1;
          uVar5 = 1;
        }
      }
      piVar3 = piVar3 + 0xc;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return uVar6;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140007e1c =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140007ef4 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140007fd8 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140008130:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140008123:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140008130;
      if (uVar5 == 5) goto LAB_140008123;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140008158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3339ba1,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400081d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_5371_3825__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3339ba1,param_3 & 0xffffffff,1,&Feature_5371_3825__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3339ba1);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400082c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400083d0 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_5371_3825__private_featureState & 2) != 0) {
    uVar1 = Feature_5371_3825__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_5371_3825__private_featureState;
      if (bVar3) {
        Feature_5371_3825__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_5371_3825__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 140008424 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 140008584 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_5371_3825__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_5371_3825__private_featureState,(ulonglong)param_1,0x14000c8d0
                            );
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 140008614 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== GetMetricString @ 1400086b4 =====

void GetMetricString(uint param_1,undefined8 *param_2,longlong *param_3)

{
  HRESULT HVar1;
  STRSAFE_PCNZWCH pszDest;
  ulonglong uVar2;
  size_t local_res10;
  
  local_res10 = 0;
  *param_2 = 0;
  *param_3 = 0;
  pszDest = (STRSAFE_PCNZWCH)MALLOC(0x18);
  if (pszDest != (STRSAFE_PCNZWCH)0x0) {
    uVar2 = 0;
    if (param_1 != 0xffffffff) {
      uVar2 = (ulonglong)param_1;
    }
    HVar1 = StringCchPrintfW(pszDest,0xb,L"%d",uVar2);
    if (HVar1 == 0) {
      HVar1 = StringCchLengthW(pszDest,0x16,&local_res10);
      if (HVar1 == 0) {
        *param_2 = pszDest;
        pszDest[local_res10 + 1] = L'\0';
        *param_3 = local_res10 * 2 + 4;
      }
    }
  }
  return;
}



===== _guard_check_icall @ 140008760 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140008778 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000879c =====

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



===== wcscmp @ 140008806 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140008806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 140008820 =====

/* WARNING: Removing unreachable block (ram,0x00014000888a) */
/* WARNING: Removing unreachable block (ram,0x000140008839) */
/* WARNING: Removing unreachable block (ram,0x00014000882a) */

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



===== __security_check_cookie @ 1400088f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140008930 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140008960 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140008960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140008990 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1400089e0 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140008a23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140008a94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140008a90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008a94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140008a8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008a90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008a8c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_140008a94:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_140008a23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140008b00 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 140008e00 =====

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



===== __memset_repmovs @ 140008f40 =====

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



===== __memset_query @ 140008fc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140009040 =====

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



===== __memset_spec_ermsb_repmovsb @ 140009180 =====

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



===== __memset_spec_plain @ 140009200 =====

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



===== WppCleanupKm @ 140011008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppTraceCallback @ 140011090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar1 = *(uint **)(param_5 + 8);
          if (((*puVar1 == param_4[6]) && (puVar1[1] == param_4[7])) &&
             ((puVar1[2] == param_4[8] && (puVar1[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != 2;
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
  }
  else {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar3 + 2 + uVar11;
      }
      if (param_3 < uVar12) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
                (ulonglong)*puVar3);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar1 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== wil_UninitializeFeatureStaging @ 140011318 =====

void wil_UninitializeFeatureStaging(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140011370 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_1400113cd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400113cd;
    }
  }
  uVar1 = 0x206;
LAB_1400113cd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400113d8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140011490 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400114c8 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001154a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001154a;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14001154a:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400115a0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140011600 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001161c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1400116d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== WppInitKm @ 1400117a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppLoadTracingSupport @ 140011840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== entry @ 140012010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140012044 =====

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
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== wil_InitializeFeatureStaging @ 140012078 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
    iVar2 = RtlRegisterFeatureUsageProvider
                      (wil_details_OnFeatureUsageProviderFlushNotification,0,
                       &g_wil_details_featureUsageProvider);
    if (iVar2 != 0) {
      if (bVar1) {
        iVar2 = 0;
      }
      g_wil_details_featureUsageProvider = 0;
      return iVar2;
    }
  }
  return 0;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140012168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


